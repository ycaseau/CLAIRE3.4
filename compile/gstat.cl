//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| gstat.cl                                                    |
//| Copyright (C) 1994 - 2013 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file object.cl: about()               |
//+-------------------------------------------------------------+

// statement is implemented as a general method that calls a restriction
// self_statement which is defined with many restrictions.
// The argument s is supposed to be the named of the C variable in which the
// result of the evaluation must be placed. s is () when the result is not
// used.
// The argument loop tells how the result is to be used:
//     loop = false means that the code will be evaluated at most once
//     loop = true means that the result may be evaluated more than once.
//     loop = s (sort) means that we are inside an all, while or until.
//         if s = unknown, then the return does only a break.

//**********************************************************************
//*  Table of contents:                                                *
//*          Part 1: Unfolding of complex expressions                  *
//*          Part 2: Basic control structures                          *
//*          Part 3: iteration                                         *
//*          Part 4: CLAIRE-specific structures                        *
 //**********************************************************************


//**********************************************************************
//*          Part 1: Unfolding of complex expressions                  *
//**********************************************************************

// this is a crisp-and-clever piece by <yc> :-), which is a little bit tricky
// this is brand new and much better than the previous strategy !
// HOWEVER, if only works for list of arguments whose evaluation order is not specified !

// this function is used to unfold complex expressions that should be compiled as
// expressions and not statements. It takes a list of arguments l and returns the
// embedded Lets that defines the necessary variable or nil (nothing is needed)
// this list is of the form  (a1 .. am) where
//     m is the number of statement args in l
//     ai is a Let that defines the i-th variable corresponding to the i-th bad guy
unfold_args(l:list) : list
  ->  let lbad := list{i in (1 .. length(l)) | not(c_func(l[i]))} in // list of indices
        (//[5] unfold -> ~S : ~S - ~S // list{l[x] | x in lbad}, list{c_sort(l[x]) | x in lbad}, list{stupid_t(l[x]) | x in lbad},
         list{ Let(var = Variable!(gensym() /+ "UU", 0, c_type_sort(l[i])),
                   value = l[i]) | i in lbad}   )

// we can infer a type but the sort must be preserved
// v3.2.40 : If the stupid type is void, we need to use a precise type.
c_type_sort(x:any) : type
 -> let s := c_sort(x), t := stupid_t(x) in
     (//[5] AHA infer a stupid type ~S [sort ~S] in ~S // t,s,x,
      if (s = void) osort(c_type(x))            // v3.2.40: sort = void => the value is not needed
      else if sort=(osort(t),s) t
      else s)

// uses the previous list to use the variable instead of the Fold.
// l is the list of arguments 
unfold_arg(l:list,ld:list,x:any) : any
 -> let i := 1, j := 0, m := length(l) in
       (if (while (i <= m)
             (if not(c_func(l[i]))
                 (j :+ 1, (if (l[i] = x) break(true)))
              else if (l[i] = x) break(false),
              i :+ 1))
           var(ld[j])
        else l[i])

// creates the Let from the ldef definition and places the statement x in the body
unfold_use(ldef:list,x:any,s:any,loop:any) : void
 -> let  n := length(ldef), v := verbose() in
      (verbose() := 0,                  // v3.1.06
       if not(ldef) error("[internal] design bug c_func(~S) should be true",x),
       if (c_type(x) = {}) s := void,                     //  <yc> error -> no value
       for i in (1 .. (n - 1)) ldef[i].arg := ldef[i + 1],
       arg(ldef[n] as Let) := x,
       verbose() := v,                  // not very elegant !
       self_statement(ldef[1] as Let,s,loop))

//**********************************************************************
//*          Part 2: Basic control structures                          *
//**********************************************************************

// The general definition.
// if functional, the best compiling is into an expression
[statement(self:any,s:any,loop:any) : void
 -> let b := OPT.alloc_stack in
      (if not(self % ((Tuple U Do) U Let)) OPT.alloc_stack := false,   // v3.2.26
       if c_func(self)
         (if (s % string &
              c_sort( (case self (to_CL self.arg, any self))) != void)
           printf("~I = ~I;~I", c_princ(s),                           // v3.1.12 -> use bol_exp!
                  (if bool_exp?(self) bool_exp!(PRODUCER,self,loop) else expression(self, loop)),
                  breakline())
          else if (self % If) self_statement(self, s, loop)
          else if (self % delimiter)
             error("[201] Loose delimiter in program: ~S", self)
          else stat_exp(PRODUCER,self,loop))    // new: v3.0.60: include a few tricks
        else if (self % Call_method & self.arg = *close_exception* & c_func(self.args[1])) // v3.3.34
          printf("~I;~I", expression(self, loop), breakline())    // v3.2.58
        else self_statement(self, s, loop),
        OPT.alloc_stack := b) ]


// makes a bag of statements.
// The value cannot be ignored: it is considered as an error
// (a do should have been used)
[self_statement(self:Construct,s:any,loop:any) : void
 -> stat_construct(PRODUCER,self,s,loop) ]

// A if is easy to compile. We check if the logical compiler can be used
// we now assume that the test retuns a boolean !
[self_statement(self:If,s:any,loop:any) : void
 -> if c_func(self.test)
      (printf("if ~I", bool_exp(self.test, true, loop)),
       breakline(),
       princ(" "),
       if (get(arg, self) % If) new_block(),
       statement(get(arg, self), s, loop),
       if (get(arg, self) % If) close_block(),
       if (s % string | get(other, self))
          let xe := get(other, self) in
              (if not(xe % If) OPT.level :+ 1,
               printf("else ~I", statement(xe, s, loop)),
               if not(xe % If) OPT.level :- 1))
    else let v := c_string(PRODUCER,gensym() /+ "I") in
            (new_block(),
             // printf("// type ~S: test is ~S\n",ti,self.test),
             printf("~I ~A;~I~I", interface!(boolean),
                    v,breakline(), statement(self.test, v, loop)),
             breakline(),
             OPT.level :+ 1,
             printf("if (~A == ~I) ~I",                       //<FXJ> MACRO
                    v, produce(PRODUCER,true), statement(get(arg, self), s, loop)),
             OPT.level :- 1,
             // breakline(),
             if (s % string | get(other, self))
                printf("else ~I",statement(get(other, self), s, loop)),
             close_block()) ]

// a DO is a simple C block
[self_statement(self:Do,s:any,loop:any) : void
 -> if (length(self.args) = 1) statement(self.args[1], s, loop)
    else let l := self.args, m := length(l), b := OPT.alloc_stack, n := 0 in
           (OPT.alloc_stack := false,
            new_block(),
            inner_statement(self, s, loop),
            close_block()) ]

// this method is used to avoid creating sub-blocks when un-necessary
[inner_statement(self:any,s:any,loop:any) : void
 -> case self
      (Do let l := self.args, m := length(l), b := OPT.alloc_stack, n := 0 in
             (OPT.alloc_stack := false,
              for x in l
                (n :+ 1,
                 if (n = m) (OPT.alloc_stack := b, inner_statement(x, s, loop))
                 else if x inner_statement(x, {}, loop))),
       any statement(self,s,loop)) ]

// a Let is a local variable declaration
[self_statement(self:Let,s:any,loop:any) : void
 -> stat_let(PRODUCER,self,s,loop) ]


// --------------- logical combinations and/or -------------------------------

// note: we cannot use unfolding because the order of evaluation is important !
// AND is compiled with IF: as soon as an argument is false, the result is false.
[self_statement(self:And,s:any,loop:any) : void
  -> let v := check_var("v_and", s, loop) in
       (new_block(),
        printf("~I~A;", interface!(boolean), v),
        breakline(),
        for x in self.args
          (new_block(),
           printf("~Iif (~A == ~I) ~I~I; ~Ielse ",    //<FXJ> MACRO
                  statement(x, v, loop), v, produce(PRODUCER,false),
                  (case s (string printf("~I =", c_princ(s)))),
                  expression(false,loop), breakline())),
        case s
         (string printf("~I = ~I;", c_princ(s),expression(true,loop)),
          any printf("~I;",expression(true,loop))),
        for x in self.args close_block(),
        close_block()) ]

// same thing for OR
[self_statement(self:Or,s:any,loop:any) : void
 -> let v := check_var("v_or", s, loop) in
       (new_block(),
        printf("~I~A;", interface!(boolean), v),
        breakline(),
        for x in self.args
          (new_block(),
           printf("~Iif (~A == ~I) ~I~I; ~Ielse ",          //<FXJ> MACRO
                  statement(x, v, loop), v, produce(PRODUCER,true),
                  (case s (string printf("~I =", c_princ(s)))),
                  expression(true,loop), breakline())),
        case s
         (string printf("~I = ~I;", c_princ(s),expression(false,loop)),
          any printf("~I;",expression(false,loop))),
        for x in self.args close_block(),
        close_block()) ]

// --------------- WHILE   ------------------------------------------
// if it is possible the logical compiler is used to produce a better code
[self_statement(self:While,s:any,loop:any) : void
  -> stat_while(PRODUCER,self,s,loop) ]

// a assignment can be compiled directly if the value does not matter.
// Here this is the simple assignment, with a true variable
[self_statement(self:Assign,s:any,loop:any) : void
 -> let v := self.var, x := self.arg,
        %s:boolean := (loop &  OPT.loop_gc & inner2outer?(x)),
        y := (if (%s & x % to_protect) x.arg else x) in    // avoid double protection
      (if (s % string)
          printf("~I~I ~I;~I", new_block(), statement(y, s, loop),
                  (if %s gc_protection_exp(PRODUCER,v,false,s,loop)
                   else printf("~I = ~I",ident(v.pname), c_princ(s))),
                  close_block())
       else if %s
          printf("~I~I ~I;~I",
                 new_block(), statement(y, c_string(PRODUCER,v), loop),
                 gc_protection_exp(PRODUCER,v,true,v,loop),              // u = v => purely for protection
                 close_block())
       else statement(x, c_string(PRODUCER,v), loop)) ]

// This is the global variable assignment
[self_statement(self:Gassign,s:any,loop:any) : void
  -> stat_gassign(PRODUCER,self,s,loop) ]

// this is the case where the value is to be protected
// note: this should use the PRODUCER ...
[self_statement(self:to_protect,s:any,loop:any) : void
 -> if (OPT.protection & s % string)
        let c := c_sort(self.arg) in
          (new_block(),
           PRODUCER.stat :+ 1,                         // v3.3.32
           printf("~I~A(~I~I);", statement(self.arg, s, loop),
                  gc_protect(c),
                  (if (c inherit? object)
                     (class_princ(psort(c_type(self.arg))), princ(","))),   // v3.3.34
                  c_princ(s)),
           close_block())
     else statement(self.arg, s, loop) ]

//**********************************************************************
//*          Part 3: iteration                                         *
//**********************************************************************

// generates the iteration code for a "for x in S ..." expression , once
// all optimization based on code substitution have been performed.
[self_statement(self:For,s:any,loop:any) : void
  -> stat_for(PRODUCER,self,s,loop) ]

// here the value is expected to be important, otherwise an error is raised.
// THIS IS ONLY APPLIED TO COLLECT
[self_statement(self:Iteration,s:any,loop:any) : void
  -> stat_iteration(PRODUCER,self,s,loop) ]

//------------- compiling a return -------------------------------------
// a return inside a loop is compiled with a break, the C variable should be
// in the loop argument
[self_statement(self:Return,s:any,loop:any) : void
 -> if (loop = unknown)
        (new_block(),
         statement(self.arg, {}, {}),
        // breakline(),
         princ("break;"),
         close_block())
     else if (loop % string)
        (new_block(),
         printf("~Ibreak;", statement(self.arg, loop, {})),
         close_block())
     else error("[204] break not inside a For or While:~S", self) ]

//**********************************************************************
//*          Part 4: CLAIRE-specific structures                        *
//**********************************************************************

// ------------- Messages and optimized instructions ------------------------

// this is one example on how to unfold: a Call
[self_statement(self:Call,s:any,loop:any) : void
 -> let l := args(self), ld := unfold_args(l) in
      unfold_use(ld, Call(selector(self),
                          list{unfold_arg(l,ld,z) | z in l}), s, loop) ]



// A call method is now simpler with unfolding !
[self_statement(self:Call_method,s:any,loop:any) : void
 -> let l := args(self), ld := unfold_args(l) in
       unfold_use(ld, Call_method(arg = self.arg,
                                  args = list{unfold_arg(l,ld,z) | z in l}), s, loop) ]

[self_statement(self:Call_method1,s:any,loop:any) : void
 -> let l := args(self), ld := unfold_args(l) in
       unfold_use(ld, Call_method1(arg = self.arg,
                                  args = list{unfold_arg(l,ld,z) | z in l}), s, loop)  ]

[self_statement(self:Call_method2,s:any,loop:any) : void
 -> let l := args(self), ld := unfold_args(l) in
       unfold_use(ld, Call_method2(arg = self.arg,
                                  args = list{unfold_arg(l,ld,z) | z in l}), s, loop)]


// The dynamic version of SUPER is not really optimized
//
[self_statement(self:Super,s:any,loop:any) : void
  -> stat_super(PRODUCER,self,s,loop) ]

// trivial
//
[self_statement(self:Cast,s:any,loop:any) : void
 -> statement(self.arg, s, loop)]

//-------------- compiling a handle -------------------------------------
// compiling of exception handling is a little tricky since we must find
// the right handler that matches the error. This is why a stack of
// environment is kept (Exc_env).
// Longjmp gives the basic tool, on top of which we add
// an object layer (belong_to)
//
self_statement(self:Handle,s:any,loop:any) : void
 -> stat_handle(PRODUCER,self,s,loop)


//; to_CL(x) produces a CLAIRE id from an external representation
[self_statement(self:to_CL,s:any,loop:any) : void
 -> case s
      (string let varg := build_Variable(string!(gensym("V_CL")),self.set_arg),
                  s2 := (if (self.set_arg = void) any else self.set_arg) in
                (new_block(),
                 printf("~I ~I;", interface!(s2), expression(varg,loop)),
                 statement(self.arg, c_string(PRODUCER,varg), loop),
                 breakline(),
                 printf("~A=~I;", s,
                        to_cl(PRODUCER, varg, self.set_arg, loop)),
                 close_block()),
       any statement(self.arg, s, loop)) ]

// to_C(x) produces an external representation from a CLAIRE id
//
[self_statement(self:to_C,s:any,loop:any) : void
 -> case s
      (string let varg := build_Variable("V_C", any) in //  YC: was c_type(self.arg)) 28/8
                (new_block(),
                 printf("~I ~I;",
                        any_interface(PRODUCER),               //<FXJ>: PATCH!   in Java: ClaireAny (was OID)
                        ident(PRODUCER,varg)),                 //<FXJ>: PATCH!   ident(PRODUCER...
                 statement(self.arg, c_string(PRODUCER,varg), loop),
                 breakline(),
                 printf("~A=~I;", s, to_c(PRODUCER,varg, self.set_arg, loop)),
                 close_block()),
       any statement(self.arg, s, loop)) ]

// same for a cast
// v3.2.06: the case where self.arg is of type any is painful => it is forbiden in osystem.cl
[self_statement(self:C_cast,s:any,loop:any) : void
 -> case s
      (string let varg := check_var("V_CC", s, loop),     // a string
                  s2 := self.set_arg,
                  s3 := stupid_t(self.arg),
                  t2 := (osort(s2) join s3) in     // v3.2.06 -> v3.3.0 (osort)
                (new_block(),
                 define_variable(PRODUCER,t2,varg),
                 breakline(),
                 statement(self.arg, varg, loop),
                 printf("~A= ~I ~A;", s, pointer_cast(PRODUCER,s2), varg),   //<FXJ> no * in Java ...
                 close_block()),
       any statement(self.arg, s, loop)) ]


//------------- compiling slot read/write -------------------------------
// reads a slot.
[self_statement(self:Call_slot,s:any,loop:any) : void
 -> let v_name := string!(gensym()),                         // v3.1.04
        varg := build_Variable(v_name, c_type(self.arg)) in
       (new_block(),
        printf("~I ~I;", interface!(sort(varg)),
               expression(varg, {})),
        breakline(),
        statement(self.arg, v_name, loop),
        breakline(),
        case s (string printf("~I = ", c_princ(s))),
        expression(Call_slot(selector = self.selector,  arg = varg), loop),
        princ(";"),
        close_block()) ]

// reads an table.
[self_statement(self:Call_table,s:any,loop:any) : void
 -> let v_name := string!(gensym()),                         // v3.1.04
        varg := build_Variable(v_name, c_type(self.arg)) in
       (new_block(),
        printf("~I ~I;", interface!(sort(varg)),
               expression(varg, {})),
        breakline(),
        statement(self.arg, v_name, loop),
        breakline(),
        case s (string printf("~I = ", c_princ(s))),
        expression(Call_table(selector = self.selector, arg = varg), loop),
        princ(";"),
        close_block()) ]

// reads an array.
[self_statement(self:Call_array,s:any,loop:any) : void
 -> let varg1 :=  build_Variable("va_arg1", array),
        varg2 :=  build_Variable("va_arg2", integer)  in
     (new_block(),
      printf("~I ~I;", interface!(array),expression(varg1, {})),
      breakline(),
      printf("~I ~I;", interface!(integer),expression(varg2, {})),
      breakline(),
      statement(self.selector, "va_arg1", loop),
    //  breakline(),
      statement(self.arg, "va_arg2", loop),
    //  breakline(),
      case s (string printf("~I = ", c_princ(s))),
      expression(Call_array(selector = varg1, arg = varg2, test = self.test), loop),
      princ(";"),
      close_block()) ]

// places a value in a slot with similar conventions
// note that the value returned is self.value, so the type should not be
// weakened
// new in v.3.00.42: handles add case => call the demon
[self_statement(self:Update,s:any,loop:any) : void
 ->  let X := self.var,
         p := self.selector,
         s1 := (case X
                 (Call_slot domain!(X.selector),
                  Call_array integer,
                  any any U p.domain)),   // Call_table
         s2 := (case X
                 (Call_slot (if (self.arg = add) member(X.selector.range)
                             else X.selector.range),
                  Call_array (if (X.test Core/<=t float) float else any),
                  any any U (if (self.arg = add) member(p.range)
                             else p.range))),
         ss1 := stupid_t(self.var.arg),
         ss2 := stupid_t(self.value),
         %arg := (if (not(ss1 Core/<=t psort(s1)) & ss1 Core/<=t object)
                      C_cast(arg = self.var.arg, set_arg = psort(s1))
                  else self.var.arg),
         %value := (if (not(ss2 Core/<=t psort(s2)) & ss2 Core/<=t object)
                       C_cast(arg = self.value, set_arg = psort(s2))
                    else self.value),
         varg1 := Variable!(gensym(), 0, s1),
         varg2 := Variable!(gensym(), 0, s2),
         b1 := c_func(%arg) in
       (new_block(),
        printf("~I ~I ~I; ", interface!(psort(s1)), expression(varg1, {}),
                             (if b1 (printf("= ~I",expression(%arg, {}))))),   // v3.3
        breakline(),
        printf("~I ~I;", interface!(psort(s2)), expression(varg2, {})),
        breakline(),
        if not(b1) statement(%arg, c_string(PRODUCER,varg1), loop),            // v3.3 :
        // breakline(),
        statement(%value, c_string(PRODUCER,varg2), loop),
        // breakline(),
        case s (string printf("~I = ", c_princ(s))),
        expression(Update(selector = p,
                            arg = (if (self.arg = add) add // v3.0.44
                                   else if (sort(varg1) = any) varg1
                                   else to_CL(arg = varg1, set_arg = sort(varg1))),
                            value = varg2,
                            var = (let xx := copy(X) in
                                         (put(arg, xx, varg1), xx))),
                     loop),
        princ(";"),
        close_block()) ]

