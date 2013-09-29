//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| copt.cl,                                                    |
//| Copyright (C) 1994 - 2013 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file core.cl: about()                 |
//+-------------------------------------------------------------+

// *******************************************************************
// * Contents                                                        *
// *     Part 1: the inline coding of function calls                 *
// *     Part 2: Fast dispatch (inlining method selection)           *
// *     Part 3: Specific code for expressions                       *
// *     Part 4: Specific code for control structures                *
// *******************************************************************


// *******************************************************************
// *       Part 1: the inline coding of function calls               *
// *******************************************************************

// these methods are important since they contain the open-coding
// optimisations. Some of the method calls may be replaced
// directly by C expressions.
// functions with one argument
[inline_exp(c:c_producer,self:Call_method1,loop:any) : void
 -> let m := self.arg, p := m.selector, a1 := car(self.args) in
       (if (p = - & (domain!(m) = integer | domain!(m) = float))
           printf("(-~I)", bexpression(a1, loop))
        else if (p = owner & Compile/designated?(a1))
           printf("OWNER(~I)", expression(a1, loop))
        else if (p = sqrt & domain!(m) = float)
           printf("sqrt(~I)", expression(a1, loop))
        else if (p = eval & Compile/designated?(a1))
           printf("OPT_EVAL(~I)", expression(a1, loop))
        else if (p = externC) princ(a1)
        else if (m = *length_bag* & Compile/designated?(a1))
           printf("~I->length", expression(a1, loop))
        else if (p = integer! & domain!(m) = char & Compile/designated?(a1))
           printf("~I->ascii", expression(a1, loop))
        else if (m = *length_array*)
           printf("~I[0]", expression(a1, loop))
        else if (m = *not* & c_type(a1) <= boolean)     // v3.2.24 for Ali :-)
           printf("((~I == Kernel.ctrue) ? CFALSE : CTRUE)", expression(a1, loop))
        // v3.3.12 - change suggested by Sylvain
        else print_external_call(c, self, loop)) ]

// functions with two arguments
//
[inline_exp(c:c_producer,self:Call_method2,loop:any) : void
 -> let m := self.arg, p := m.selector, a1 := self.args[1], a2 := self.args[2] in
      ( if (m = *min_integer* & Compile/designated?(a1) &
                 Compile/designated?(a2))
           printf("((~I <= ~I) ? ~I : ~I)",
                  expression(a1, loop), expression(a2, loop),
                  expression(a1, loop), expression(a2, loop))
        else if (m = *max_integer* & Compile/designated?(a1) &
                 Compile/designated?(a2))
           printf("((~I <= ~I) ? ~I : ~I)",
                  expression(a1, loop), expression(a2, loop),
                  expression(a2, loop), expression(a1, loop))
        else if (p = class! & a1 % symbol)
           printf("(~I._~I = ClaireClass::make(~S,~I,~I.it))", ident(defined(a1)),
                  c_princ(string!(a1)), // protected by _
                  string!(a1),
                  expression(a2, loop),
                  ident(module!(a1)))    // <yc>  7/98  safer (was current_module)
        else if (p % c.open_operators &
                 (p != / | compiler.safety >= 5) &
                 (m.domain[1] = m.domain[2]) &               // v3.1.08
                 (c_type(a1) <= integer | c_type(a1) <= float))
           printf("~I(~I~A~I)",
                  (if (compiler.safety < 2 & c_type(a1) <= integer) princ("_integer_")),
                  bexpression(a1, loop),        // v3.2.06
                  string!(p.name),
                  bexpression(a2, loop))
        else if (m = *contain* & Compile/identifiable?(a2))
           printf("~I->memq(~I)", expression(a1, loop), expression(a2, loop))
        else if ((m = *nth_list* & compiler.safety >= 2) | m = *nth_1_bag*)
           printf("(*(~I))[~I]", expression(a1, loop),
                  expression(a2, loop))
        else if (p = add! & domain!(m) <= bag)
           printf("~I->addFast(~I)", expression(a1, loop), expression(a2, loop))
        else if (m = *nth_string* & compiler.safety >= 2)
           printf("_char_(~I[~I - 1])", expression(a1, loop), expression(a2, loop))
        else if (m.selector = identical?)
           printf("(~I ? CTRUE : CFALSE)",
                  bool_exp(self, true, loop))
        else if (m.selector = externC) princ(a1)
        else if (p = inlineok? & a2 % string)
           printf("~I->inlineDef(~S)",expression(a1,loop),a2)
        else print_external_call(c, self, loop)) ]

// functions with three arguments or more
[inline_exp(c:c_producer,self:Call_method,loop:any) : void
 -> let m := self.arg, b := OPT.Compile/alloc_stack,
         a1 := self.args[1], a2 := self.args[2], a3 := self.args[3] in
       (OPT.Compile/alloc_stack := false,
        if (m = *nth=_list* & compiler.safety >= 3)
           printf("((*(~I))[~I]=~I)", expression(a1, loop),
                  expression(a2, loop), expression(a3, loop))
         else if (domain!(m) = string & ((m.selector = nth= & compiler.safety >= 2) |
                                         m.selector = nth_put))
           printf("(~I[~I - 1] = (char) ~I->ascii)", expression(a1, loop),
                  expression(a2, loop),
                  expression(a3, loop))
         else if (m = *nth_1_string*)
           printf("_char_(~I[~I - 1])", expression(a1, loop), expression(a2, loop))
         else if (m.selector = store & c_type(a1) <= list &
                 ((length(self.args) = 4 & self.args[4] = true) | length(self.args) = 3))
           printf("STOREI((*~I)[~I],~I)",
                   expression(a1, loop),
                   expression(a2, loop),
                   expression(a3, loop))
         else if (m.selector = store & c_type(a1) <= array &
                  member(c_type(a1)) ^ float = {} &
                 ((length(self.args) = 4 & self.args[4] = true) | length(self.args) = 3))
           printf("STOREI(~I[~I],~I)",
                        expression(a1, loop),
                        expression(a2, loop),
                        expression(a3, loop))
        else if (m.selector = add_slot & getC(a1) % class)
           printf("CL_ADD_SLOT(~I,~I,~I,~I,~I,~I)",expression(a1, loop),
                        class_princ(getC(a1)), // v3.3.14
                        expression(a2, loop),
                        ident(getC(a2).name),  
                        expression(getC(a3), loop),
                        expression(self.args[4],loop))
        else if (m.selector = add_method)
         (if (a1 % property)
          printf("~I->add~IMethod(~I,~I,~I	~I,~I)",expression(a1, loop),
                        (if (length(self.args) > 5) princ("Float")),
                        signature!(c,a2),
                        expression(a3, loop),
                        breakline(),
                        bitvector!(c,self.args[4]),
                        (expression(self.args[5],loop),
                         if (length(self.args) > 5)
                            (princ(","), expression(self.args[6],loop)))  )
          else printf("add_method_property(~I)",
                        args_list(self.args, loop,true)))
        else (write(Compile/alloc_stack, OPT, b),
              print_external_call(c,self, loop)),
        OPT.Compile/alloc_stack :=  b) ]

// unprotected call
[print_external_call(c:c_producer,self:Call_method,loop:any) : void
 -> let m := self.arg, l := self.args, n := 1, ld := m.domain in
     (printf("~I(", c_princ(Compile/functional!(m))),
      if (length(l) > 4) OPT.level :+ 1,
     // was if (length(l) = 1 & (domain!(m) = void) & m.range != float)  l := nil,
      if (length(l) = 1 & domain!(m) = void)  l := nil,
      for x in l
          (if (n != 1) (princ(","), if (length(l) > 4) breakline()),
           let s1 := Compile/psort(ld[n]),
               s2 := Compile/stupid_t(x) in
             (if (s1 Core/<=t object & not(s2 Core/<=t s1))
                 printf("(~I *) ", class_princ(s1))),  // v3.3.13
           expression(x, loop),
           n :+ 1),
      princ(")"),
      if (m.range % tuple & not(OPT.Compile/alloc_stack)) princ("->copyIfNeeded()"), // v3.2.26
      if (length(l) > 4) OPT.level :- 1) ]


// new in 3.0 : really low level method are virtual and only rely on inline compiling
[inline_exp(c:c_producer,self:Call,loop:any) : void
 -> let  p := self.selector, a1 := car(self.args), n := length(self.args) in
       (if (p = mClaire/get_stack) printf("ClEnv->stack[~I]", expression(a1, loop))
        else if (p = safe)                    // v3.2.12 : we had forgotten this !!!!
           let y := compiler.safety in
             (compiler.safety := 1,
              expression(self.args[1],loop),
              compiler.safety := y)
        else if (p = mClaire/base!) printf("ClEnv->base")
        else if (p = mClaire/index! & n = 1) printf("ClEnv->index")
        else if (p = mClaire/push! & n = 1)
          printf("PUSH(~I)", expression(a1, loop))
        else if (p = mClaire/put_stack)
          printf("(ClEnv->stack[~I]=~I)", expression(a1, loop),
                                          expression(self.args[2], loop))
        else if (p = mClaire/set_base)
          printf("(ClEnv->base= ~I)", expression(a1, loop))
        else if (p = mClaire/set_index)
          printf("(ClEnv->index= ~I)", expression(a1, loop))
        else if (p = object!)
          let a2 := self.args[2] in     // a class
              printf("(~I.~I = ~I)",
                     ident(defined(a1)),
                     (if (a2 <= reserved_keyword)
                         (princ("_cl_"), c_princ(string!(a1)))
                      else ident(a1)),
                     (if (a2 = property & (a1.value % property))
                         printf("property::make(~S,~A,~I,~I,~A)",
                                string!(a1),
                                a1.value.open,
                                expression(module!(a1),nil),
                                expression(a1.value.domain,nil),
                                a1.value.mClaire/dispatcher)
                      // new in v3.0.50: trap property -> init dispatcher slot
                      else printf("(~I *) ~I->instantiate(~S,~I)",
                                  class_princ(a2),                  // v3.3.14
                                  expression(a2, loop),
                                  string!(a1),
                                  expression(module!(a1),nil))))
        else if (p = anyObject!)
              printf("((~I *) (*~I)(~I))", class_princ(a1 as class),        // v3.3.16
                        expression(a1,loop),
                        args_list(cdr(self.args), loop, length(self.args) > 2))
        else if fcall?(self) fcall_exp(self,loop)
        else if (length(self.args) > 20)            // v3.2.54
           (if (self.selector = store)
             let l := self.args, n := length(l), m := n / 10  in
               printf("(~I)",
                       (for i in (0 .. m)
                         (printf("(*~I)(~I)", expression(store, loop),
                                 args_list(list{l[j] |
                                                j in ((i * 10 + 1) ..
                                                      (if (i = m) n else (i * 10 + 10))) },
                                                loop, true)),
                          if (i != m) princ(","))))             // v3.1.06
            else error("[216] ~S has more than 10 parameters",self))
        else printf("(*~I)(~I)", expression(self.selector, loop),
                                 args_list(self.args, loop, length(self.args) > 1))) ]


// *******************************************************************
// *       Part 2: Fast dispatch                                     *
// *******************************************************************


// new in v3.00.05: fast dispatch -----------------------------------------

// is the call OK for a fast dispatch? - similar to what is provided by Java :-)
// (a) dictionary or <= 3 restrictions
// (b) args a2->an match all restrictions => all sorts are the same
// (c) a1 is designated  & covered by union of restrictions
fcall? :: property(open = 3)
fcall_exp :: property(open = 3)

Compile/FCLimit :: 3
Compile/FCALLSTINKS:boolean :: false          // v3.2.22 : a boolean to understand

// v3.2.18 : cut the to_CL restriction !
// v3.2.22 : type(a1) <= object is not necessary (implied with the dispatcher case, irrelevant with the enumerated case)
[fcall?(x:Call)  : boolean
  -> let p := x.selector, a1 := x.args[1],
         nProtect := length(list{ y in x.args | c_gc?(y)}) in    // number of args that need a gc
       // (a1 % to_CL & designated?(a1.arg) &           // old: only apply to to_CL
      ( (designated?(a1) | p.mClaire/dispatcher > 0) &  // new v3.2.26: even simpler
           (let l := cdr(x.args), %type:type := {},
              lt := list{Optimize/ptype(c_type(y)) | y in x.args},
              lt2 := cdr(lt),
              lr := get_restrictions(x,lt),
              selOK := ((length(lr) > 0) &
                        (nProtect = 0 |
                         forall(m in lr | not(status!(m)[NEW_ALLOC]))) & // do not remove GC protect !
                        ( (p.mClaire/dispatcher > 0 & length(l) <= 4) |  // use dispatcher <= 4 args
                          length(lr) < FCLimit)),                        // use explicit enumeration
              s := (if (length(lr) > 0) c_srange(lr[1]) else void),
              lrOK := forall( r in lr |
                          (%type :U domain!(r),
                           ( r.domain[1] % class &            // v3.2.16: domain!(m) always a class !
                             (last(r.domain) != listargs) &   // v3.1.06
                             Core/tmatch?(lt2, cdr(r.domain)) &
                             c_srange(r) = s))),
              callOK := (s % {any, void, integer,object} &
                         %type <= object &
                         Optimize/ptype(c_type(a1)) <= %type) in
          (if (FCALLSTINKS & not(selOK & lrOK & callOK) & p.mClaire/dispatcher > 0)
              trace(0,"****> fcall(~S) fails (selectorOK = ~S , lrOK = ~S, callOK = ~S)\n",
                                  x, selOK, lrOK, callOK),
           (selOK & lrOK & callOK)))) ]


// return the list of restrictions that may be involved with the call
[get_restrictions(x:Call, lt:list) : list<method>
 -> let p := x.selector, open_required := (class!(lt[1]).open = system.open),
        lr := list<method>() in
       (if (p.mClaire/dispatcher = 0 & (open_required | p.open = system.open)) nil  // v3.2.24 ! thanks to FLA
        else (for r:restriction in p.restrictions
               (if (r.domain ^ lt)
                  (case r (method lr :add r,
                           any break(shrink(lr,0)))))),
        lr) ]

// generate the fast dispatch code
// if dictionary -> use fcall
[fcall_exp(x:Call,loop:any) : void
  -> let p := x.selector, a1 := x.args[1],             // was (x.args[1] as to_CL).arg,
         lt := list{Optimize/ptype(c_type(y)) | y in x.args},
         lr := get_restrictions(x,lt),
         m := lr[1] as method, s := c_srange(m) in
       (if (s = void) printf("_void_(")
        else if (s = object) printf("_oid_(")
        else if (s = integer & compiler.safety <= 2) printf("_integer_("),
        if (p.mClaire/dispatcher > 0 & length(lt) <= 4)    // use fcall
          (//[4] ---- note: ~S is compiled with fast dispatch // x,
           if (s = object) princ("(ClaireObject *) "),
           printf("~I->fcall(~I)", expression(p,loop),
                                  c_sorted_args(x,m.mClaire/srange,loop,true)))
        else let lr2 :=  list{x in p.mClaire/definition | x % lr} in  // good order
             (//[4] ---- note: ~S is compiled with explicit dispatch (s = ~S) // x, s,
              for m in lr2
               let psort := list{psort(x) | x in m.domain} in    // v3.3.24 --- looks like we reinvent psort ... 
                                 ;(let c := class!(x), sc := sort!(c) in    // sort! = osort :-)
                                 ;   (if (sc = object) c else sc)) |
                                 ; x in m.domain} in
               (if (m != last(lr2))
                   printf("(INHERIT(~I,~I) ? ~I ~I((~I *) ~I) : ~I ",
                       (if (a1 % to_CL) printf("~I->isa",expression(a1.arg,loop))
                        else printf("OWNER(~I)",expression(a1,loop))),
                       expression(domain!(m),loop),
                       (if (s = object) princ("(ClaireObject *)")),   // v3.2.16
                       c_princ(Compile/functional!(m)),
                       class_princ(domain!(m)),                       // v3.3.14
                       c_sorted_args(x,psort,loop,false),
                       breakline)
                 else (printf("~I ~I((~I) ~I)",
                             (if (s = object) princ("(ClaireObject *) ")), // v3.2.16
                             c_princ(Compile/functional!(m)),
                             interface!(PRODUCER,domain!(m)),
                             c_sorted_args(x,psort,loop,false)),
                      for i in (1 .. (length(lr2) - 1)) princ(")")))),
        if (s = void | s = object | s = float | s = integer & compiler.safety <= 2)
           princ(")")) ]


// prints an argument with the proper sort, %cast = true => cast to int
// x is assumed to be of sort OID
[c_sorted_arg(x:any,s:class,loop:any, %cast:boolean) : void
  -> if %cast printf("((int) "),
     if (case x (to_CL osort(x.set_arg) = s)) expression(x.arg,loop)  // v3.3.0
     else if (s = any) expression(x,loop)
     else to_c(PRODUCER,x,s,loop),
     if %cast printf(")") ]

// prints the set of args
[c_sorted_args(x:Call,ls:list,loop:any, %cast:boolean) : void
  -> let i := 0 in
       (for y in x.args
          (if (i != 0) princ(","), i :+ 1,
           c_sorted_arg(y,ls[i],loop,%cast))) ]

// *******************************************************************
// *       Part 3: Specific code for expressions                     *
// *******************************************************************

// prints a bitvector status in a nice manner
[bitvector!(c:c_producer,x:any) : void
  -> case x (integer bitvectorSum(x),
             to_CL bitvector!(c,x.arg),
             to_protect bitvector!(c,x.arg),
             any expression(x,nil)) ]

Compile/bitvectorList :: list("NEW_ALLOC","BAG_UPDATE","SLOT_UPDATE","RETURN_ARG","SAFE_RESULT",
                              "SAFE_GC","STRING_UPDATE")    // v3.3.46

[bitvectorSum(x:integer) : void
 -> if (x = 0) princ("0")
    else let b := false in
          for i in (1 .. 7)                         // v3.3.46
            (if x[i] (if b princ("+") else b := true,
                      princ(bitvectorList[i]))) ]

// print a signature
[signature!(c:c_producer,x:any) : void
 -> case x (list printf("list::domain(~A,~I)", length(x),
                        args_list(list{getC(y) | y in x}, nil, length(x) > 3)),
            to_C signature!(c,x.arg),
            to_protect signature!(c,x.arg),
            List signature!(c,x.args),
            Variable expression(x,nil),
            any printf("<fucking ~S:~S>",owner(x),x)) ]


// patch: remove protection and conversion layers
[getC(x:any) : any
  -> case x (to_CL getC(x.arg),
             to_protect getC(x.arg),
             global_variable (if nativeVar?(x) x                        // v3.3
                              else  to_C(arg = x, set_arg = type)),     // AHA new in v3.0.42
             any x) ]

// assignment for a global-variable (value is an OID) that may require trailing
[gassign(c:c_producer,self:Gassign,loop:any) : void
 -> if self.var.Kernel/store?                                     // still ok in v3.3 since storeable vars use the old pattern
        printf("(STOREI(~I,~I))", expression(self.var, loop),     //!
               expression(get(arg, self), loop))
    else printf("(~I= ~I)", expression(self.var, loop),
                expression(get(arg, self), loop)) ]

[call_slot(c:c_producer,self:Call_slot,loop:any) : void
 -> if self.test
       printf("~A(~I,",
               (if (self.selector.srange inherit? import |
                    self.selector.srange inherit? string |
                    self.selector.srange inherit? array |      // v3.0.66 unknown(array) => null
                    self.selector.srange inherit? object) "NOTNULL"
                else "KNOWN"),
               expression(self.selector.selector, loop)),
    c_member(c, self.arg, psort(domain!(self.selector)),
             self.selector.selector, loop),
    if self.test princ(")") ]

[call_table(c:c_producer,self:Call_table,loop:any) : void
 -> let a := self.selector,
         p := a.params,
         l := self.arg in
       (if self.test printf("KNOWN(~I,", expression(a, loop)),
        printf("(*(~I->graph))[~I]", expression(a, loop),           //!
               (case p
                 (integer
                    printf("~I - ~A", expression(l, loop), p),
                  list printf("~I * ~A + ~I - ~A",                    //<yc> l is a List
                              expression(l.args[1], loop), p[1],
                              expression(l.args[2], loop), p[2])))),
        if self.test princ(")")) ]

[call_array(c:c_producer,self:Call_array,loop:any) : void
 -> if (self.test = float)
        printf("((double *) ~I)[~I]",expression(self.selector, loop),  //!
                 expression(self.arg, loop))
    else printf("((OID *) ~I)[~I]",expression(self.selector, loop),
                 expression(self.arg, loop)) ]

// this method is extensible and can be further refined  if necessary
[update(c:c_producer,self:Update,loop:any) : void
 ->  let p:any := self.selector, a := self.arg,
         v := self.value, x := self.var, s := c_sort(v) in
       (if (case p (relation (known?(p.if_write) & a != put & a != put_store)))
           printf("~I_write(~I,~I)",
                  c_princ(string!(p.name)),
                  expression(x.arg, loop),
                  expression(v,loop))
        else if (case p (relation (p.Kernel/store? | a = put_store)))
           printf("STORE~A(~I,~I)",
                  (if (s = any | s = integer) "I"
                   else if (s = float) "F"
                   else "O"),
                  expression(x, loop),
                  expression(v, loop))
        else printf("(~I = ~I)", expression(x, loop), expression(v, loop))) ]
        // AUDACIEUX: remove parenthesis -> failed

[object_test(c:c_producer,a1:any,pos?:boolean,loop:any) : void
  -> printf("(CTAG(~I) ~I OBJ_CODE)",
            expression(a1, loop), sign_equal(pos?)) ]


[exp_to_protect(c:c_producer,self:to_protect,loop:any) : void                  // v3.0.3
 -> let st := c_type(self.arg) in
     (if (OPT.protection & need_protect(self.arg) &
          not(OPT.alloc_stack & st <= tuple))                                 // v3.2.26 : a temporary tuple should not be protected ...
        let x := self.arg, s := c_sort(x) in
          printf("~A(~I)",gc_protect(s),
                  (if (s inherit? object) printf("~I,~I",
                                                  class_princ(psort(c_type(x) glb s)),   // v3.3.14
                                                  expression(self.arg, loop))
                   else expression(self.arg,loop)))
      else expression(self.arg, loop)) ]


[gc_protect(c:class) : string
  -> if (c = any) "GC_OID"
     else if (c = string) "GC_STRING"
     else if (c = array) "GC_ARRAY"
     else if (c inherit? object) "GC_OBJECT"
     else ""]

[macro(c:c_producer) : void -> nil]
[init_var(c:c_producer,s:class) : void -> nil]
[any_interface(c:c_producer) : void -> princ("OID") ]
[pointer_cast(c:c_producer,s:class) : void -> printf("(~I *)",class_princ(c,s)) ]  // v3.3.14


// v3.2.44:  make this part re-definable for C
[exp_Assign(c:c_producer,self:Assign, loop:any) : void
  -> let x := self.arg, v := self.var in
        printf("~I= ~I", ident(PRODUCER, v), expression(x, loop)) ]   // v3.0.3 AUDACIEUX


// *******************************************************************
// *       Part 4: Specific code for control structures              *
// *******************************************************************

// how to .. handle handler
[stat_handle(c:c_producer,self:Handle,s:any,loop:any) : void
 ->  new_block(),
     printf("ClaireHandler c_handle = ClaireHandler();"),
     breakline(),
     princ("if ERROR_IN "),
     breakline(),
     new_block(),
     statement(self.arg, s, loop),           // v3.3.3: the loop argument is needed for GC protection
     princ("ClEnv->cHandle--;"),
     close_block(),
     printf("else if (belong_to(_oid_(ClEnv->exception_I),~I) == CTRUE)",
            expression(c_code(self.test, any), {})),
     breakline(),
     new_block(),
     princ("c_handle.catchIt();"),
     statement(get(other, self), s, loop),   // same (was put to nil to forbid the use of a return)
     close_block(),
     printf("else PREVIOUS_HANDLER;"),
     close_block() ]

// v3.0.42: the variable s is not necessariuly properly typed
[stat_construct(c:c_producer,self:Construct,s:any,loop:any) : void
  -> if not(s) error("[202] A do should have been used for ~S", self),
     let v := check_var("v_bag", s, loop),
         seed := (case self (List list(), Set set(), Tuple tuple(), any error("BUG: ~S", self))) in
       (new_block(),
        (if known?(of,self) cast!(seed,self.of)),
        if exists(x in self.args | not(c_func(x)))
           printf("OID ~A;~I",v,breakline()),
        printf("~I~I= ~I~I;",
               (if OPT.protection (c.stat :+ 1, printf("GC_ANY("))),   // v3.3.32
               c_princ(s),
               bag_expression(PRODUCER,seed.isa,seed,of(seed),loop), // v3.2
               (if OPT.protection printf(")"))),
        for x in self.args
          let f := c_func(x) in
            printf("~I~I~I~I(~I);", breakline(),
                   (if not(f) statement(x, v, loop)),
                   printf("((~S *) ~I)",
                          (case self (List list, Set set, any tuple)),
                          c_princ(s)),
                   addFast(c),
                   (if f expression(x, loop) else c_princ(v))),
        close_block()) ]

// note: it might be wise to use define_variable to define v ...
// v3.2.42: do not use the simple form if the test needs a GC protection
[stat_while(c:c_producer,self:While,s:any,loop:any) : void
 -> new_block(),
    let f? := (c_func(self.test) & not(self.other) & gc_usage(self.test,loop) = false),
        v := check_var("v_while", s, loop) in
       (if OPT.loop_gc printf("OID gc_local;~I", breakline()),
        if not(f?) printf("~I~A;~I", interface!(boolean),v, breakline()),
        if (s % string) (printf("~I= _oid_(~I);", c_princ(s),expression(false,loop)), breakline()),
        if f?  printf("while (~I)",bool_exp(self.test, not(self.other), loop))
        else (statement((if self.other false else self.test), v, true),
              breakline(),
              printf("while (~A ~I CTRUE)", v,
                      (if self.other princ("!=") else princ("==")))),      // v3.00.05
        breakline(),
        new_block(),
        let bloop := (OPT.loop_gc & gc_usage(self.arg,true) != false) in   // new in v3.0.55
          (if bloop (printf("GC_LOOP;"), breakline()),
           inner_statement(self.arg, {}, (case s (string s, any unknown))),
           if not(f?) statement(self.test, v, true),
           if bloop printf("GC_UNLOOP;")),
        close_block()),
     close_block() ]

[stat_gassign(c:c_producer,self:Gassign,s:any,loop:any) : void
 ->  new_block(),
     printf("~I truc;~I", interface!(c,(if nativeVar?(self.var) getRange(self.var) else any)),
                          statement(get(arg, self), "truc", loop)),     // v3.3
     breakline(),
     if self.var.Kernel/store?  printf("STOREI(~I,truc);", expression(self.var, loop))
     else printf("(~I = truc);", expression(self.var, loop)),
     close_block() ]

[stat_for(c:c_producer,self:For,s:any,loop:any) : void
 -> let v := c_string(c,self.var) in
      (new_block(),
       if OPT.loop_gc printf("OID gc_local;~I", breakline()),
       printf("ITERATE(~I);", c_princ(v)),
       if (s % string) (breakline(), printf("~I= Kernel.cfalse;", c_princ(s))),  // v3.3.42 - Sylvain's optim 
       breakline(),
       if (c_func(self.set_arg) & designated?(self.set_arg))
          printf("for (START(~I); NEXT(~I);)",
                 expression(self.set_arg, loop), c_princ(v))
       else let v2 := v /+ "_support" in
            (printf("bag *~I;~I",c_princ(v2),breakline()),
             statement(self.set_arg, v2, loop),
             printf("for (START(~I); NEXT(~I);)", c_princ(v2), c_princ(v))),
       breakline(),
       let bloop := (OPT.loop_gc & gc_usage(self.arg,true) != false) in   // new in v3.3 :-) copied from while ....
         (if bloop (new_block(), printf("GC_LOOP;"), breakline()),
          if (OPT.profile? & OPT.in_method % object)
             (if not(bloop) new_block(), princ("PRloop(PR_x);"), breakline()), // v3.3.44
          statement(self.arg, {}, (if (s % string) s else unknown)),
          if bloop (printf("GC_UNLOOP;"), close_block()),
          if (OPT.profile? & OPT.in_method % object & not(bloop)) close_block(),
          close_block())) ]

[stat_iteration(c:c_producer,self:Iteration,s:any,loop:any) : void
 -> if not(s) error("[203] you should have used a FOR here:~S", self),
    let v := c_string(c,self.var),
        local := check_var("v_val", s, loop),
        liste := check_var("v_list", s, loop) in
      (new_block(),
       printf("bag *~A; OID ~A;~I",liste, local,breakline()),
       printf("OID ~I,CLcount;~I", c_princ(v), breakline()),
       printf("~I ~I = ~I;",
              statement(self.set_arg, liste, loop),
              c_princ(s),
              printf("~A->clone(~I)", liste,
                     (if known?(of,self)
                         expression(c_code(of(self),type),nil)))),    // v3.2.28
       breakline(),
       printf("for (CLcount= 1; CLcount <= ~A->length; CLcount++)", liste),
       breakline(),
       new_block(),
       printf("~I = (*(~A))[CLcount];", c_princ(v), liste),
       breakline(),
       statement(self.arg, local, true),
       breakline(),
       printf("(*((list *) ~I))[CLcount] = ~A;", princ(s), local),
       close_block(),
       close_block()) ]

[stat_super(c:c_producer,self:Super,s:any,loop:any) : void
 -> let rec := check_var("v_rec", s, loop) in
       (new_block(),
        printf("OID ~A;", rec),
        breakline(),
        for x in self.args
          (printf("~IPUSH(~A);", statement(x, rec, loop), rec),
           breakline()),
        printf("~I~I->super(~I,~A);",
               (case s (string printf("~I=", c_princ(s)))),
               expression(self.selector, loop),
               expression(self.cast_to, loop), length(self.args)),
        close_block()) ]


// last addition in v3.2.44
[stat_let(c:c_producer,self:Let,s:any,loop:any) : void
 -> let ns := c_string(PRODUCER,self.var.pname) in
      (if (ns[1] = 'C' & ns[2] = '%') self.var.pname := gensym()),
     let v := c_string(PRODUCER,self.var), b := OPT.alloc_stack,
         x := get(value, self), f := true in   // f is used for recursively embedded lets
       (new_block(),
        OPT.alloc_stack := false,
        while f
          (if (self % Let*) OPT.alloc_stack := true,            // Let* uses a tuple of vars
           printf("~I ~I", interface!(sort(self.var)), c_princ(v)),
           if c_func(x)
            printf(" = ~I;~I",
               (if bool_exp?(x) bool_exp!(PRODUCER,x,loop) else expression(x, loop)),   // v3.1.12
                   breakline())
           else printf("~I;~I~I",init_var(PRODUCER, sort(self.var)),
                                 breakline(), statement(x, v, loop)),
           if (self % Let*)  OPT.alloc_stack := false,
           if (self.arg % Let)
              (self := self.arg as Let,
               v := c_string(PRODUCER,self.var),
               x := get(value, self))
           else f := false),
        OPT.alloc_stack := b,
        printf("~I", inner_statement(self.arg, s, loop)),
        close_block()) ]

