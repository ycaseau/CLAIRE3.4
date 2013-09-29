//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| gexp.cl                                                     |
//| Copyright (C) 1994 - 2001 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file object.cl: about()               |
//+-------------------------------------------------------------+

// ---------------------------------------------------------------------
// Compiling is based upon three methods:
//  - c_func? tests if the CLAIRE form can be represented by a C/ expression.
//    In this case,
//  - expression transforms it into an equivalent C expression.
//    otherwise,
//  - statement takes also a variable as an argument, and transforms a CLAIRE
//    expression into a C statement that assigns the value of the expression
//    into the variable;
//
// A special case occurs when the expression represent a boolean value and is
// functional, we can use bool_exp that returns a C boolean
// ---------------------------------------------------------------------

// *********************************************************************
// *  Contents                                                         *
// *  Part 1: c_func & expression for objects                          *
// *  Part 2: expression for messages                                  *
// *  Part 3: expression for structures                                *
// *  Part 4: boolean optimization                                     *
// *********************************************************************

// the mark //! shows C++ specific code that should be moved

//**********************************************************************
//*          Part 1: c_func & expression for objects                   *
//**********************************************************************

// this methods tells if a CLAIRE instruction can be compiled as an expression,
// as opposed to a statement.
[c_func(self:any) : boolean
 -> case self
      (bag not({ x in self | not(c_func(x))}),
       Construct (if (self % (Set U List U Tuple))
                    (length(self.args) < 15 &
                     not({ x in self.args | not(c_func(x))}))
                  else false),
       If (c_func(self.test) & c_func(get(arg, self)) &
           c_func(get(other, self)) &
           stupid_t(self.arg, self.other) &
           (let n := 4,
                x := self.other in
              while (n > 0)
                case x (If (x := x.other, n :- 1), any break(true)))),
       Assign c_func(get(arg, self)),
       Gassign c_func(get(arg, self)),
       to_protect c_func(get(arg, self)),
       And c_func(self.args),
       Or c_func(self.args),
       Call c_func(self.args),
       Call_method (c_func(self.args) & (self.arg != *close_exception*)),   // test v3.2.58
       Call_slot c_func(get(arg, self)),
       Call_table c_func(get(arg, self)),
       Call_array c_func(get(arg, self)),
       Update (c_func(get(value, self)) &
               c_func(get(arg, self))),
       Cast c_func(self.arg),
       to_C c_func(self.arg),
       to_CL c_func(self.arg),
       any (self % thing | self % integer | self % string | self % char |
            self % float | self % Variable | self % global_variable |
            self % function | self % symbol | self = unknown |
            self % boolean | self % class | self % environment)) ]


// A named object is designed by a C identifier !
expression(self:thing,loop:any) : void -> produce(PRODUCER,self)

// Primitive types rely on the producer to generate code that uses their specific implementation
expression(self:integer,loop:any) : void -> princ(self)
expression(self:any,loop:any) : void -> produce(PRODUCER,self)
expression(self:string,loop:any) : void -> produce(PRODUCER,self)
expression(self:float,loop:any) : void -> princ(self)
expression(self:boolean,loop:any) : void -> produce(PRODUCER,self)
expression(self:environment,loop:any) : void -> produce(PRODUCER,self)
// lexical variables are represented by C variables
expression(self:Variable,loop:any) : void -> ident(PRODUCER,self)

// global_variables are CLAIRE objects
[expression(self:global_variable,loop:any) : void
 -> produce(PRODUCER,self) ]

// builds a set
expression(self:Set,loop:any) : void
 -> bag_expression(PRODUCER,set,self.args,(if known?(of,self) self.of else void),loop)
[expression(self:set,loop:any) : void
 -> if (length(self) = 0 & of(self) = {}) princ("Kernel.emptySet")
    else bag_expression(PRODUCER,set,self,of(self),loop) ]

// builds a tuple
expression(self:Tuple,loop:any) : void
 -> bag_expression(PRODUCER,tuple,self.args,void,loop)
expression(self:tuple,loop:any) : void
 -> bag_expression(PRODUCER,tuple,self,void,loop)

// builds a tuple
expression(self:List,loop:any) : void
 -> bag_expression(PRODUCER,list,self.args,(if known?(of,self) self.of else void),loop)
[expression(self:list,loop:any) : void
 -> if (length(self) = 0 & of(self) = {}) princ("Kernel.nil")
    else bag_expression(PRODUCER,list,self,of(self),loop) ]

//**********************************************************************
//*          Part 2: expression for messages                         *
//**********************************************************************

// General case. Note that the arguments are protected if needed !
//
expression(self:Call,loop:any) : void
 -> inline_exp(PRODUCER,self,loop)

// the other cases will be taken care in the optimization part
[expression(self:Call_method1,loop:any) : void
 -> inline_exp(PRODUCER,self,loop)]

[expression(self:Call_method2,loop:any) : void
 -> inline_exp(PRODUCER,self,loop)]

[expression(self:Call_method,loop:any) : void
 -> inline_exp(PRODUCER,self,loop)]
 

//**********************************************************************
//*          Part 3: expression for structures                       *
//**********************************************************************

// this is an attempt to get rid of useless parenthesis without creating ambuiguous situations
// bexpression(x,loop) adds wrapping ( ) if needed     v3.2.06
[bexpression(self:any,loop:any) : void
  -> case self (Assign printf("(~I)",expression(self,loop)),
                to_C  printf("(~I)",expression(self,loop)),                     // v3.2.44
                integer (if (self < 0)  printf("(~I)",expression(self,loop))    // v3.2.44
                         else expression(self,loop)),                           // avoid (2--2)
                float   (if (self < 0.0)  printf("(~I)",expression(self,loop))
                         else expression(self,loop)),
                any    expression(self,loop)) ]

// if can be represented by an expression
expression(self:If,loop:any) : void
 -> (printf("(~I ?", bool_exp(self.test, true, loop)),
     OPT.level :+ 1,
     breakline(),
     printf("~I :", expression(get(arg, self), loop)),
     breakline(),
     printf("~I )", expression(get(other, self), loop)),
     OPT.level :- 1)

// An assignment is a C expression. It may be an increment (optimization).
// This is a simple variable operation. If loop is on, and the value is
// protected, we use an optimization to save stack space.
// note: GC statements are generic since they don't exist in Java !
[expression(self:Assign,loop:any) : void
 -> let x := self.arg, v := self.var in
      (if (case x (Call_method2
                     (x.arg = *+_integer* & x.args[1] = self.var &  x.args[2] = 1)))
           printf("++~I", expression(v, loop))
       else if (loop & OPT.loop_gc & inner2outer?(x))
            gc_protection_exp(PRODUCER,v,true,(case x (to_protect x.arg, any x)),
                             loop)
       else exp_Assign(PRODUCER,self,loop)) ]  // v3.2.44
       // WAS (~I = ~I)

// this is the case where the value is to be protected
[expression(self:to_protect,loop:any) : void
 -> exp_to_protect(PRODUCER,self,loop) ]                                    // v3.0.3

     
// an assignment is a C expression
// This is a global variable
[expression(self:Gassign,loop:any) : void
 -> gassign(PRODUCER,self,loop) ]

// a conjunction is also a C expression
[expression(self:And,loop:any) : void
 -> let b := (length(self.args) > 5) in
       (for x in self.args
          (printf("(~I ? ", bool_exp(x, true, loop)),
           if b breakline()),
        expression(true,loop),
        for x in self.args printf(": ~I)",expression(false,loop))) ]

// same thing for a disjunction
[expression(self:Or,loop:any) : void
 -> let b := (length(self.args) > 5) in
       (for x in self.args
          (printf("(~I ? ~I : ", bool_exp(x, true, loop), expression(true,loop)),
           if b breakline()),
        expression(false,loop),
        for x in self.args princ(")")) ]


// to_CL(x) produces a CLAIRE id from an external representation
expression(self:to_CL,loop:any) : void
 -> to_cl(PRODUCER,self.arg, self.set_arg, loop)

// to_C(x) produces an external representation from a CLAIRE id
expression(self:to_C,loop:any) : void
 -> to_c(PRODUCER,self.arg, self.set_arg, loop)

// C_cast(x) produces a cast for C++
expression(self:C_cast,loop:any) : void
 -> cast!(PRODUCER,self,loop)

// reads a slot.
// when the test is on, we use two functions NOTNULL/KNOWN(p,x,x->p)
[expression(self:Call_slot,loop:any) : void
 -> call_slot(PRODUCER,self,loop) ]

// reads an (integer) table
[expression(self:Call_table,loop:any) : void
 -> call_table(PRODUCER,self,loop)]

// reads an array
[expression(self:Call_array,loop:any) : void
 -> call_array(PRODUCER,self,loop) ]

// places a value in a slot with similar conventions
// if the selector is external, there is an interface
[expression(self:Update,loop:any) : void
 -> update(PRODUCER,self,loop) ]


//**********************************************************************
//*          Part 4: the logical expression compilation                *
//**********************************************************************

// v3.0.03: bool_exp can be used for a test in an If => always
// v3.0.22: self must be of range boolean but we now support a sort any

// this is the boolean compiler. An automatic computation of negation is
// included. The flag pos? tells if the assertion is positive. When a
// negation occurs, we simply change the flag. At the end of compiling,
// the flag is used to generate == or != according to this method:
// generate a equality/ difference
//
sign_equal(self:boolean) : void -> (if self princ("==") else princ("!="))

// generate a conjunction/disjunction
sign_or(self:boolean) : void -> (if self princ("||") else princ("&&"))

// this is the default compilation of a logical expression
// NEW: we know that self is a boolean,
// the (any -> boolean) conversion is done at the optimizer level
// v3.3.12: the droping of to-C means that the sort cannot be computed
// hence the test for c_sort != bool is only on global variables
[bool_exp(self:any,pos?:boolean,loop:any) : void
 ->  any_bool_exp(self,pos?,loop,
         not(self % global_variable & not(nativeVar?(self)))) ]


// v3.3.12: this method works for both OID and true bools
[any_bool_exp(self:any,pos?:boolean,loop:any,nat?:boolean) : void
 ->  printf("(~I ~I ~I)", bexpression(self, loop),              // v3.00.05
            (if not(pos?) princ("!=") else princ("==")),
            (if not(nat?) to_cl(PRODUCER,true,boolean,loop)
             else expression(true,loop))) ]


// if we have a CL, we know that the self.arg is of type boolean
[bool_exp(self:to_CL,pos?:boolean,loop:any) : void
  -> bool_exp(self.arg,pos?,loop) ]

// an if may be used as a test, especially within a member
// if there is not else clause, it is an and.
[bool_exp(self:If,pos?:boolean,loop:any) : void
 -> if self.other
        printf("(~I ? ~I : ~I)", bool_exp(self.test, true, loop),
                                 bool_exp(self.arg, pos?, loop),
                                 bool_exp(self.other, pos?, loop))
     else printf("(~I ~I ~I)", bool_exp(self.test, pos?, loop),
                 sign_or(not(pos?)), bool_exp(self.arg, pos?, loop)) ]

// for a AND, we can used the && C operation
[bool_exp(self:And,pos?:boolean,loop:any) : void
 -> let l := self.args, m := length(l), n := 0, %l := OPT.level in
       (OPT.level :+ 1,
        for x in l
          (n :+ 1,
           if (n = m) bool_exp(x, pos?, loop)
           else (printf("(~I ~I ", bool_exp(x, pos?, loop), sign_or(not(pos?))),
                 OPT.level :+ 1,
                 breakline())),
        for x in (2 .. m) princ(")"),
        OPT.level := %l)  ]

// idem for OR: we use ||
[bool_exp(self:Or,pos?:boolean,loop:any) : void
 -> let l := self.args, m := length(l), n := 0, %l := OPT.level in
       (OPT.level :+ 1,
        for x in l
          (n :+ 1,
           if (n = m) bool_exp(x, pos?, loop)
           else (printf("(~I ~I ", bool_exp(x, pos?, loop), sign_or(pos?)),
                 OPT.level :+ 1,
                 breakline())),
        for x in (2 .. m) princ(")"),
        OPT.level := %l) ]

// some special functions are open coded when used in a logical test
[bool_exp(self:Call_method1,pos?:boolean,loop:any) : void
 -> let m := self.arg, a1 := self.args[1] in
       (if (m = *not*)
           (if (a1 % to_CL) any_bool_exp(a1.arg, not(pos?), loop, true)
            else any_bool_exp(a1, not(pos?), loop,false))     // v3.3.12 - was :  & a1 % to_CL
        else if (m = *known*) equal_exp(PRODUCER,a1, not(pos?), unknown, loop)
        else if (m = *unknown*) equal_exp(PRODUCER,a1, pos?, unknown, loop)
        else if (m.range <= boolean)
           printf("(~I ~I ~I)", expression(self, loop), sign_equal(pos?), expression(true,loop))
        else bool_exp@any(self, pos?, loop)) ]

// same thing for two arguments functions
[bool_exp(self:Call_method2,pos?:boolean,loop:any) : void
 -> let m := self.arg, p := m.selector, lop := PRODUCER.open_comparators,
        a1 := self.args[1], a2 := self.args[2] in
      (if (p = !=) equal_exp(PRODUCER,a1, not(pos?), a2, nil)
       else if (p = identical?) equal_exp(PRODUCER,a1, pos?, a2, true)
       else if (p = =) equal_exp(PRODUCER,a1, pos?, a2, nil)
       else if (p % lop & domain!(m) % {float,integer})
           printf("(~I ~I ~I)", expression(a1, loop),
                  (if pos? print(p)
                   else print(lop[((get(lop, p) + 1) mod 4) + 1])),
                  expression(a2, loop))
      ;  else if (m.selector = % & a2 = object)          // v3.2.24
      ;     object_test(PRODUCER,a1,pos?,loop)
        else if (m = *nth_integer*)
           printf("(~I~I)", (if not(pos?) princ("!")),
                            bitvector_exp(PRODUCER,a1,a2,loop))
        else if (p = inherit? & domain!(m) = class)
         printf("(~I~I)", (if not(pos?) princ("!")),
                          inherit_exp(PRODUCER,a1,a2,loop))
       else if (m.range <= boolean)
          printf("(~I ~I ~I)", expression(self, loop), sign_equal(pos?), expression(true,loop))
       else bool_exp@any(self, pos?, loop)) ]

// v3.1.12 -> recognize pure boolean expression
[bool_exp?(x:any) : boolean
  -> case x (to_CL bool_exp?(x.arg),
             Call_method let p := x.arg.selector in
                            ((x.arg.range = boolean &           // v3.2 : protection !
                              (p = = | p = != | p = > | p = >= | p = < | p = <=)) |
                             (p = not & bool_exp?(x.args[1]))),
             any false)]


// produces a list of C expressions, separated by commas
[args_list(self:bag,loop:any,bk?:boolean) : void
 -> let %first := true in
       (if bk? OPT.level :+ 1,
        for x in self
          (if %first (expression(x, loop), %first := false)
           else printf(",~I~I", (if bk? breakline()),
                       expression(x, loop))),
        if bk? OPT.level :- 1) ]

// this method checks that a proposed variable is different from the
// imported one, else it add a mark.
check_var(self:string,s:any,loop:any) : string
 -> (if (self = s | self = loop) self /+ "1" else self)


build_Variable(s:string,t:any) : Variable
 -> Variable!(symbol!(s), 0, t)


