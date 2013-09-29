//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| ocontrol.cl                                                 |
//| Copyright (C) 1994 - 2013 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file object.cl: about()               |
//+-------------------------------------------------------------+


// *********************************************************************
// * Contents                                                          *
// *     Part 1: Basic Instructions                                    *
// *     Part 2: other control structures                              *
// *     Part 3: If, Case, Do, Let                                     *
// *     Part 4: Loops                                                 *
// *     Part 5: Iterate                                               *
// *********************************************************************


// *********************************************************************
// *      Part 1: Basic Instructions                                   *
// *********************************************************************

// the type of an assignment is the type of the result
[c_type(self:Assign) : type -> c_type(self.arg)]

// we must include the type checking if needed
[c_code(self:Assign) : any
 ->  let v := self.var,
         x := self.arg,
         %type := ptype(c_type(x)) in
       (if not(v % Variable) Cerror("[213] ~S is not a variable", v),
        if not(%type Core/<=t v.range) x := c_warn(self.var, x, %type),
        let %arg := c_gc!(c_strict_code(x, psort(v.range)), v.range ^ %type) in
          (gc_register(v,%arg),                 // v3.1.06
           Assign(var = v, arg = %arg)))  ]

[c_gc?(self:Assign) : boolean -> c_gc?(self.arg)]

// assignment to a global variable
[c_type(self:Gassign) : type -> c_type(get(arg, self)) ]
[c_code(self:Gassign) : any
 ->  let %v := get(arg, self),
         %type := ptype(c_type(%v)) in
       (if not(self.var.range) Cerror("[214] cannot assign ~S", self),
        if not(%type Core/<=t self.var.range)
           %v := c_check(c_code(%v, any), c_code(self.var.range, type)),
        Gassign(var = c_code(self.var),
                arg = (if nativeVar?(self.var)
                          c_strict_code(%v, psort(self.var.range))
                       else c_code(%v, any)))) ] // v3.3 !

[c_gc?(self:Gassign) : boolean -> c_gc?(self.arg)]

// _______________ l AND/OR     ____________________________________

[c_type(self:And) : type -> boolean]
[c_code(self:And) : any
 -> And(args =
          list{ (if (c_type(x) = void) Cerror("[206] void ~S in ~S", x, self),
                 c_boolean(x)) |
                 x in self.args}) ]

[c_type(self:Or) : type -> boolean]
[c_code(self:Or) : any
 -> Or(args =
         list{ (if (c_type(x) = void) Cerror("[206] void ~S in ~S", x, self),
                c_boolean(x)) |
                x in self.args})]

//---------------- quote and return -------------------------------------
[c_type(self:Quote) : type -> owner(self.arg)]
[c_code(self:Quote) : {}
 -> Cerror("[internal] optimization of quote not implemented yet! ~S",self)]

// a to_protect is a wrapper
c_type(self:to_protect) : type -> c_type(self.arg) // <yc> can be string
c_code(self:to_protect) : any -> self
c_gc?(self:to_protect) : boolean -> false


c_type(self:Return) : type -> any
c_code(self:Return) : any
  ->  (OPT.loop_gc := false,             // v3.3.36: LOOP_GC optimization is unsafe in the presence of a break :-(
       Return(arg = c_code(self.arg , any)))

// optimisation of exception handlers
[c_type(self:Handle) : type -> (c_type(self.arg) U c_type(self.other))]

[c_code(self:Handle,s:class) : any
 ->  let x := Handle(test = any, arg = c_code(self.arg, s),
                     other = c_code(self.other, s)) in
       (if (self.test != contradiction)
           write(allocation, OPT, true),
        put(test, x, self.test),
        x) ]

c_gc?(self:Handle) : boolean
 -> (c_gc?(self.arg) | c_gc?(self.other))

// ****************************************************************
// *      Part 2: Specific structures                             *
// ****************************************************************

// __________________ CAST ________________________________________

// cast is now more subtle since we introduce coercion for list<t> types
[c_type(self:Cast) : type -> self.set_arg]

[c_code(self:Cast) : any
 -> let y := self.set_arg, ftype := psort(y) in
      (if (case y (Param ((y.arg = list | y.arg = set) & y.args[1] % set)))
        let utype := ((y as Param).args[1] as set)[1] in
            (if (c_type(self.arg) @ of = utype | compiler.safety > 4) c_code(self.arg, ftype)
             else  c_code( Call(Core/check_in,
                                list(self.arg,(y as Param).arg, utype)),
                           ftype))
       else (if (c_type(self.arg) <= y | compiler.safety > 1) 
                c_code(self.arg, ftype)
             else c_code(Call(Core/check_in,               // v3.3.16 - type check for as 
                              list(self.arg,y)),ftype))) ]


// _________________ SUPER _________________________________________
c_type(self:Super) : type
 -> (let %type := list{ c_type(x) | x in self.args},
         s := self.selector in
       (%type[1] := self.cast_to,         // <yc> 7/98
        let prop := (if (s.open = 3) nil
                     else restriction!(class!(self.cast_to), 
                                       s.Kernel/definition, %type)) in
          case prop
           (slot prop.range,
            method use_range(prop, %type),
            any s.range)))

// this is the optimizer for messages
c_code(self:Super) : any
 -> (let s := self.selector, l := self.args,
         %type := list{ c_type(x) | x in self.args},
         prop := (if (s.open = 3) nil
                  else  restriction!(class!(self.cast_to), 
                                     s.Kernel/definition, %type)) in
       case prop
        (slot Call_slot(selector = prop,
                        arg = c_code(l[1], psort(domain!(prop))),
                        test = (not(get(default, prop) % prop.range) & compiler.safety < 5)),
         method c_code_method(prop, l, %type),
         any c_warn(self, %type)))

// we will need this direct call for compiling call to CLAIRE_demons
Call_function2 <: Optimized_instruction(arg:function,args:list)

self_print(self:Call_function2) : void
 -> printf("~S(~I)", self.arg, princ(self.args))

c_type(self:Call_function2) : type -> any

c_code(self:Call_function2) : any
 -> Call_function2(arg = self.arg,  args = list{ c_code(x, any) | x in self.args})

// ASSERT & trace
[c_code(self:Assert) : any
 ->  if OPT.online? self
     else if (compiler.safety = 0 | compiler.debug?)
        c_code(If(test = Call(not, list(self.args[1])),
                  arg = Call( Core/tformat,
                              list("Assertion violation in ~A line ~A\n", 0,
                                    List(args = list(self.external, self.index)))),
                  other = false),
               any) ]

[c_code(self:Trace) : any
 -> let a := self.args in
       (if OPT.online? self
        else if (length(a) = 1 & c_type(a[1]) <= integer)
          c_code(Call(write,list(verbose,system,a[1])))
        else if (length(a) > 1 & a[2] % string &
                 (compiler.debug? | (try eval(a[1]) <= system.verbose catch any true)))
           let %c := Call(Core/tformat,
                          list(a[2], a[1], List(args = (copy(a) << 2)))) in
             c_code((if not(a[1] % integer)
                        If(test = Call(<=, list(a[1], Call(verbose, list(system)))),
                           arg = %c, other = false)
                     else %c),
                    any)) ]

c_type(self:Assert) : type -> any
c_type(self:Trace) : type -> any
c_type(self:Branch) : type -> boolean

[c_code(self:Branch) : any
 -> c_code(Handle(arg = Do(list(Call(choice, list(system)),
                                If(test = self.args[1], arg = true,
                                   other = Do(list(Call(backtrack, list(system)),
                                              false))))),
                  test = contradiction,
                  other = Do(list(Call(backtrack, list(system)), false))),any) ]

[c_code(self:Macro,s:class) : any -> c_code(call(macroexpand,self),s)]

[c_type(self:Macro) : type -> c_type(call(macroexpand,self))]


c_type(self:Printf) : type -> any

[c_code(self:Printf) : any
 ->  let l := self.args in
       (if not(l[1] % string)
           Cerror("[209] the first argument in ~S must be a string", self)
        else let s := (l[1] as string),
                 i := 1,
                 n := get(s, '~'),
                 r := list<any>() in
               (while not(n = 0)
                  let m := s[n + 1] in
                    (if (i < length(l)) i :+ 1
                     else Cerror("[210] not enough arguments in ~S", self),
                     if (n > 1)
                        r :add Call(princ, list(substring(s, 1, n - 1))),
                     r :add
                       (if ('A' = m)  Call(princ, list(l[i]))
                        else if ('S' = m) Call(print, list(l[i]))
                        else if ('F' = m)  // v3.4
                            let p% := false,                                    // print a % float ?
                                j := integer!(nth_get(s,n + 2,n + 2)) - 48 in   // an <int> after ~F
                          (if ('%' = s[n + 2]) (p% := true, j := 1)             // ~F% format
                           else if (j < 0 | j > 9) error("[189] F requires a single digit integer in ~S",self),
                           if (not(p%) & '%' = s[n + 3]) (p% := true, n :+ 1),  // ~Fi% format
                           n :+ 1,
                           Call(mClaire/printFDigit,list((if p% Call(*,list(l[i],100.0)) else l[i]),j)))
                        else if ('I' = m) l[i]),
                     s := substring(s, n + 2, 1000),
                     n := get(s, '~')),
                if s r :add Call(princ, list(s)),
                c_code(Do(r), any))) ]


c_type(self:Error) : type -> {}
[c_code(self:Error) : any
 -> let x := OPT.allocation,
        y := c_code(Call(close,
                list(Cast(arg = Call(anyObject!,
                                     list(general_error,
                                          c_code(car(self.args),any),
                                          c_code((if (length(self.args) != 1)
                                                   List(args = cdr(self.args))
                                                  else nil), any))),
                          set_arg = exception))),
                     void) in
         (OPT.allocation := x,  // v3.2.24 -> error => no GC protection is needed !
          y) ]


// *********************************************************************
// *     Part 3: If, Case, Do, Let                                     *
// *********************************************************************

//_______________ IF __________________________________________

// check if the test is of the form known?(v) so that the type (result) can be reduced
[extendedTest?(self:If) : type
 -> let %t := self.test in
      (case %t
        (Call (if (%t.args[1] % Variable & %t.selector = known?)
                  %t.args[1].range
               else any),
         any any))]

// notice that we analyze the test to detect the know? filter
[c_type(self:If) : type
 ->  let %r := extendedTest?(self) in
       (if extended?(%r) range_sets(self.test.args[1], sort_abstract!(%r.Core/t1)),
        let result := (c_type(get(arg, self)) U c_type(get(other, self))) in
          (if extended?(%r) put(range, self.test.args[1], %r), result)) ]

claire/PENIBLE:boolean :: false

[c_code(self:If,s:class) : any
 -> let %r := extendedTest?(self) in
       (if extended?(%r) range_sets(self.test.args[1], sort_abstract!(%r.Core/t1)),
        if ( not(ptype(c_type(self.test)) <= boolean) & (PENIBLE = true))
          (warn(), trace(2,"CLAIRE 3.3 SYNTAX - Test in ~S should be a boolean [260]\n",self)),               // v3.3
        let result := If(test = c_boolean(self.test),
                         arg = c_code(get(arg, self), s),
                         other = c_code(get(other, self), s)) in
          (if extended?(%r) put(range, self.test.args[1], %r), result)) ]

Compile/c_gc?(self:If) : boolean
 -> (c_gc?(get(arg, self)) | c_gc?(get(other, self)))

// ------------------ CASE -------------------------------------------

// a member-of is a CLAIRE case. [yc 1/29/98]
// note that type inference supposes that the case is "closed" (all types are delt with)
// but only with safety >= 5
[c_type(self:Case) : type
 ->  let %var := self.var,
         %type := (case %var (Variable get(range, %var), any any)),  // input type
         l := copy(self.args),
         rtype:type := {},
         utype:type := {} in    // union of all covered cases
       (while (length(l) > 0)
          (if (l[1] % type) (utype :U l[1],
                             if (osort(%type) = osort(l[1])) range_sets(%var, l[1]) // v3.3.0
                             else if (osort(%type) = any)      // v3.3.0
                               range_sets(%var, sort_abstract!(l[1])))
           else Cerror("[208] wrong type declaration for case: ~S in ~S",
                      car(l), self),
           rtype :U c_type(l[2]),
           //[5] so far rtype -> ~S because of ~S branch // rtype, l[1],
           case %var (Variable put(range, %var, %type)),
           l :<< 2),
        if (%type <= utype) rtype   // used to check safety
        else if (rtype <= boolean) boolean  // new: supports open cases
        else any) ]                 // safety

// member_of is treated like a macro and vanishes into a large if.
// the last line is a trap for code generated by the logic compiler.
// [yc 1/29/99]
[c_code(self:Case,s:class) : any
 -> let %var := self.var,
         %type := (case %var (Variable get(range, %var), any any)),
         l := copy(self.args), utype:any := {},
         ctest1 := c_boolean(Call( %, list(%var, l[1]))) in  // new in v3.0.54
       (range_sets(%var, l[1]),
        let rep := If(test = ctest1,
                      arg = c_code(l[2], s),
                      other = c_code(false, s)),
            pointer:If := rep in
          (case %var (Variable put(range, %var, %type)),
           l :<< 2,
           while (length(l) > 0)
             (utype :U l[1],
              if (%type <= utype)
                (if (osort(%type) = osort(l[1])) range_sets(%var, l[1])   // v3.3.0
                 else if (osort(%type) = any) range_sets(%var, sort_abstract!(l[1])), // v3.3.0
                 write(other, pointer, c_code(l[2], s)),
                 case %var (Variable put(range, %var, %type)),
                 break())
              else let ctest := c_boolean(Call(%, list(%var, l[1]))) in
                   (range_sets(%var, l[1]),
                    write(other, pointer,
                          If(test = ctest,  // <yc> new in v0.15
                             arg = c_code(l[2], s),
                             other = c_code(false,s))),
                    pointer := pointer.other as If),
              case %var (Variable put(range, %var, %type)),
              l :<< 2),
           if (case %var (Definition %var.arg % exception)) %var
           else rep)) ]

//_____________________ Block structure________________________
c_type(self:Do) : type -> c_type(last(self.args))

[c_code(self:Do,s:class) : any
 -> Do( (let m := length(self.args), n := 0 in
          list{ (n :+ 1, c_code(x, (if (n = m) s else void))) | x in self.args})) ]

Compile/c_gc?(self:Do) : boolean -> c_gc?(last(self.args))

// ----------------------- LET -----------------------------------

// we make a range inference
//
[c_type(self:Let) : type
 -> range_infers(self.var, c_type(get(value, self))),
    c_type(self.arg) ]

// works also for Let+ / Let*
c_code(self:Let,s:class) : any
 -> (let %v := get(value, self),
         %type:type := ptype(c_type(%v)) in
       (range_infers(self.var, %type),
        if not(%type <= self.var.range) %v := c_warn(self.var, %v, %type),
        let x := Let(var = self.var,
                     value = c_gc!(c_strict_code(%v, psort(self.var.range)), %type),
                     arg = c_code(self.arg, s)) in
          (put(isa, x, self.isa),
           if (x % Let* & %type % tuple & c_status(self.value,nil)[NEW_ALLOC])            // v3.3.3 protection of tuple vars
              let i := 1, z := x.arg in
                 (while (z % Let & i <= length(%type)) 
                        (if not(gcsafe?(%type[i]) | z.value % to_protect)     // need to protect the var since the tuple is short-lived !
                           (OPT.protection := true,
                            z.value := to_protect(arg = z.value)),
                         i :+ 1, z := z.arg)),
           x)))

// type inference for When is more subtle
c_type(self:When) : type
 -> (let %v := get(value, self),
         v := self.var,
         d:any := daccess(%v, true),
         %type := (if known?(d) c_type(d) else c_type(%v)) in
       (if extended?(%type) %type := %type.Core/t1,
        range_infers(v, %type),
        c_type(self.arg) U c_type(self.other)))

// A When is macroexpanded into one/two Let
c_code(self:When,s:class) : any
 -> (let %v := get(value, self),
         v := self.var,
         d:any := daccess(%v, true),
         v2 := Variable!(self.var.pname /+ "test", self.var.index, any),
         %type := (if known?(d) c_type(d) else c_type(%v)) in
       (if extended?(%type) %type := %type.Core/t1,
        range_infers(v, %type),
        if (known?(d) & not(extended?(d.selector.range)))  // <yc> 7/98 : extended(range) =>
           Let(var = v, value = c_gc!(d, %type),           // poss. sort error with direct Let
               arg =
                 If(test =
                      Call_method2(arg = (identical? @ any),
                                   args = list(v, c_code(unknown, c_sort(v)))),
                    arg = c_code(self.other, s),
                    other = c_code(self.arg, s)))
        else if (c_sort(v) = any & %type <= v.range &      // make sure direct let is sort-safe
                 compiler.safety >= 3)                   // v3.0.52
             c_code(Let(var = v, value = %v,
                        arg = If(test =  Call(!=, list(v, unknown)),
                                 arg = self.arg, other = self.other)),
                  s)
        else c_code(Let(var = v2, value = %v,            // double let for safety
                        arg =
                          If(test = Call(!=, list(v2, unknown)),
                             arg = Let(var = v,
                                       value = Cast(arg = v2, set_arg = %type),
                                       arg = self.arg),
                             other = c_code(self.other, s))),
                    s)))

Compile/c_gc?(self:Let) : boolean -> c_gc?(self.arg)

// *********************************************************************
// *     Part 4: Loops                                                 *
// *********************************************************************

// here we could do a return extraction
c_type(self:For) : type -> infers_from(return_type(self.arg),self)

infers_from(t:type,self:any) : type
 -> (if (t = {})     sort_abstract!(boolean)    // will return false
     else if (compiler.safety > 3)
         (//[2] ... c_type(~S) -> ~S - ~S // self,t,sort_abstract!(t),
          sort_abstract!(t))
     else any)        // false or the return value


// notice that for is of sort any and may require a cast ..
[c_code(self:For,s:class) : any
 -> let sx := self.set_arg,
        b := OPT.protection,
        ns := compiler.safety,
        vold := self.var,               // new in v2.5.44 vold => v !
        v := Variable(pname = vold.pname, range = vold.range,
                      mClaire/index = vold.mClaire/index),
        narg := substitution(self.arg,vold,v),
        scs := c_inline_arg?(sx) in
     (OPT.protection := false,
      case sx
         (global_variable
            (if not(sx.range)
                (// the set is a constant ! we replace it by its value to benefit from Iterate optim
                 put(set_arg, self, sx.value), sx := sx.value)),
          Select let %t := c_type(sx) in
                   (if (not(%t <= bag) | %t <= set)
                       (self := copy(self), put(isa, self, Select))),
          class (if (sx.open <= 1 & not(sx.subclass))
                   put(set_arg, self,
                       Call(selector = instances, args = list(sx))))),
        let %t := c_type(self.set_arg),
            %t2 := pmember(%t),
            %t3 := pmember(c_type(Call(selector = set!, args = list(sx)))) in
          (if (%t3 <= %t2) %t2 := %t3,
           range_infers_for(v, %t2,%t),
           write(safety, compiler, 1),
           %t2 := v.range,
           put(range, v, ptype(%t2)),
           let m := Iterate!(self) in
             (if not(m % method)
                 let m2 := restriction!(iterate, list(%t, set(v), any), true) in
                   case m2 (method m := m2),
              write(safety, compiler, ns),
              put(range, v, %t2),
              let r := (if (case m (method m.inline?))
                          (if (compiler.safety < 6 & c_status(narg,nil)[NEW_ALLOC])
                               OPT.loop_gc := true,
                           // this is new in v2.4.06
                           //[5] iteration found -> ~S // m,
                           if sort_abstract?(v.range)
                              put(range,v,Core/t2(v.range)),
                           c_inline(m, list(Language/instruction_copy(self.set_arg), // v3.2.01
                                            v, narg), s))
                        else if scs
                           c_code(For(var = v, set_arg = scs, arg = narg), s)
                        else if (case sx (Call sx.selector = Id))
                            c_code_multiple(self,%t,s)       // new in v3.1.0
                        else let r2 :=
                             For(var = v,
                                 set_arg = c_gc!(enumerate_code(self.set_arg, %t)),
                                 arg = c_code(narg, void)) in
                              (if (s = any) r2 else to_C(arg = r2, set_arg = s))) in
                (if (OPT.protection & OPT.loop_index >= 0 &
                     compiler.safety < 6) OPT.loop_gc := true,
                 OPT.protection := (OPT.protection | b),
                 r)))) ]


// new: we macroexpand the iteration  based on the type
// this is only called if the set is wrapped in an Id
[c_code_multiple(self:For,%t:type,s:class) : any
  -> let v := self.var,
         sx := (self.set_arg as Call).args[1],
         v2 :=  Variable!(v.pname /+ "test", self.var.index, %t),
         n :=  Let(var = v2,
                   value = sx,
                   arg = For(var = self.var, set_arg = enumerate_code(sx, %t), arg = self.arg)) in
       (//[0] ---- note: use an expended iteration for {~S} // self,
        for r in {r in iterate.restrictions |
                   domain!(r) Core/<=t %t & domain!(r) Core/<=t collection & r.inline? &
                   v % r.domain[2] }                 // check var subtyping
         let vnew := Variable(pname = v.pname, range = v.range, mClaire/index = v.mClaire/index),
             narg := substitution(self.arg,v,vnew) in        // a separate var
          n.arg := If(test = Call(%,list(v2,r.domain[1])),   // v3.2.16 domain! => class !
                      arg = (if (compiler.safety < 6 & c_status(self.arg,nil)[NEW_ALLOC])
                                 OPT.loop_gc := true,
                             if sort_abstract?(vnew.range) put(range,vnew,Core/t2(v.range)),
                             c_inline(r, list(v2, vnew, narg), s)),
                      other = n.arg),
        c_code(n,s)) ]


Compile/c_gc?(self:Iteration) : boolean -> true

// ------------------------ Collect/ Image / Select / Lselect ------------------------------

// an Iteration builds a bag
[c_type(self:Iteration) : type
 -> let %t := c_type(self.set_arg) in
     (range_infers_for(self.var, pmember(%t),%t),
      if known?(of,self) Core/param!( (if (self % (Select U Image)) set else list), self.of)
       else nth( (if (self % (Select U Image)) set else list),
                 (if (self % (Select U Lselect))
                     pmember(c_type(self.set_arg))
                  else ptype(c_type(self.arg))))) ]

// They are all expended into a For except for Collect(bag)
c_code(self:Iteration) : any
 -> let sx := self.set_arg,
        %t := c_type(sx) in
      (if (self % For) c_code(self, any)
       else if (case self (Collect %t <= bag))
          (// we generate a Collect ONLY FOR BAGS (thus, not a method)
           write(allocation, OPT, true),
           range_infers_for(self.var, pmember(%t), %t),
           let ty := ptype(c_type(self.arg)),                  // v3.3
               x := Collect(var = self.var,
                            set_arg = c_gc!(c_strict_code(sx, bag)),
                            arg = c_code(self.arg, any)) in
             (if (ty = void) Cerror("[205] use of void expression ~S in ~S",self.arg,self),
              if known?(of,self)
               (if (compiler.safety > 4 | ty <= self.of)     // v3.2.12
                   (x.of := self.of, x)    // type safe !
                else (warn(),
                      trace(2,"unsafe typed collect (~S): ~S not in ~S [261]\n",
                              self, c_type(self.arg), self.of),
                      c_code( Call(Core/check_in,list(x,list,self.of)), list)))
             else x))
       else let  val:any := (if (self % Image) set() else list()),
                 v := Variable!(self.var.pname /+ "_bag",
                                       (OPT.max_vars :+ 1, 0),
                                       (if (self % Image) set else list)) in
              (// If self is a typed construct _<X>{...}, take X into account!
               //[5] (~S:~S) v = ~S range = ~S (arg:~S)// self, self.isa, self.var, self.var.range,self.arg,
               if known?(of,self)
                 let %typeIn := c_type(self.arg) in
                  (if (not(ptype(%typeIn) <= self.of) & compiler.safety <= 4)
                      (warn(),
                       trace(2,"unsafe bag construction (~S) : a ~S is not a ~S [262]\n",
                               self.var, %typeIn, self.of)),
                   cast!(val,of(self)),                       // v3.1.06
                   put(range,v, Core/param!(v.range,self.of)))
               else (val := (if (val % set) Set(of = {}) else List(of = {}))), // v3.2
               Let(var = v,
                   value = val,  // v0.01
                   arg = Do( list(c_code(For(var = self.var, set_arg = sx,
                                          arg = Call(add!,list(v, self.arg))), // v3.1.06
                                         any),
                              (if not(OPT.online?)
                                  (write(protection, OPT, true),
                                   to_protect(arg = v))
                               else v))))))

// new in v3.1.16
// selection has its own optimization method that takes care of the polymorphism
[c_code(self:Select) : any -> c_code_select(self,set) ]                               
[c_code(self:Lselect) : any -> c_code_select(self,list) ] 

[c_code_select(self:Iteration,x:class) : any
 -> let sx := self.set_arg,
        %t := c_type(sx),
        st := enumerate_code(sx, %t),
        val := (if (x = set) set() else list()),   // v3.2
        v1 := Variable!(self.var.pname /+ "_in", (OPT.max_vars :+ 1, 0), bag),
        v2 := Variable!(self.var.pname /+ "_out", (OPT.max_vars :+ 1, 0), x) in
    (// If self is a typed construct _<X>{...}, take X into account!
     if known?(of,self)
       let  %typeIn := pmember(%t) in
          (if (not(ptype(%typeIn) <= self.of) & compiler.safety <= 4)
             (warn(),
              trace(2,"unsafe bag construction (~S) : a ~S is not a ~S [262]\n",
                    self.var, %typeIn, self.of)),
           cast!(val,self.of),                       // v3.1.06
           put(range,v2, Core/param!(x,self.of)),
           inner_select(self,v2,sx,val))             // v3.2.01 ??
      else if (%t <= x)                              // we want to conserve the type of
         Let(var = v1,                               // the input
             value = st,
             arg = inner_select(self,v2,v1,
                              C_cast(arg = c_code(Call(empty,list(v1)),bag), set_arg = x)))
      else inner_select(self,v2,sx, (if (x = set) Set(of = {})
                                     else List(of = {})))) ]  // v3.2.01
                                    
 
// sub-procedure 
[inner_select(self:Iteration,v2:any,sx:any,val:any) : any
 -> Let(var = v2,
        value = val,  // v0.01
        arg = Do( list(c_code(For(var = self.var, set_arg = sx,
                                  arg = If(test = self.arg,           // 
                                           arg = Call(add!, list(v2, self.var)))),
                              any),
                  (if not(OPT.online?)
                      (write(protection, OPT, true),
                       to_protect(arg = v2))
                   else v2)))) ]
   
// if (other = unknown : some) the result is either the variable or unknown
c_type(self:Exists) : type
 -> let %t := c_type(self.set_arg) in
     (range_infers_for(self.var, pmember(%t),%t),
      if (self.other = unknown) extends(pmember(%t))       //<yc> there was a stupid bug
      else boolean)       // boolean, or any U boolean ?

c_code(self:Exists,s:class) : any
 -> let %t := c_type(self.set_arg) in
     (range_infers_for(self.var, pmember(%t),%t),
      if (self.other = true)     		// forall
        c_code(Call(not,
                    list(For(var = self.var, set_arg = self.set_arg,
                             arg = If(test = Call(not,list(self.arg)),
                                      arg = Return(arg = true))))),
               s)
     else if (self.other = unknown)     // some
        let v := Variable!(self.var.pname /+ "_some",
                                   (OPT.max_vars :+ 1, 0),
                                   extends(self.var.range)) in  // v0.02
          c_code(Let(var = v, value = unknown,
                     arg = Do(list(For(var = self.var,
                                       set_arg = self.set_arg,
                                       arg =
                                       If(test = self.arg,
                                          arg =
                                            Return(arg = Assign(var = v, arg = self.var)))),
                                 v))),
                 s)
     else c_code(Call(boolean!,
                     list(For(var = self.var, set_arg = self.set_arg,
                              arg = If(test = self.arg, arg = Return(arg = true))))),
                 s))                     // exists

// am Image builds a set
c_type(self:Image) : type
 -> let %t := ptype(c_type(self.set_arg)) in             // v3.2.01
     (range_infers_for(self.var, pmember(%t),%t),
      if known?(of,self) Core/param!(set,self.of)
      else set[ c_type(self.arg) ])

c_type(self:Select) : type
 -> let %t := c_type(self.set_arg) in
     (range_infers_for(self.var, pmember(%t),%t),
      if known?(of,self) Core/param!(set,self.of)
      else set[ pmember(c_type(self.set_arg))] )

// new in v3.1.06 : proper type inference !
c_type(self:Lselect) : type
 ->  let %t := c_type(self.set_arg) in
       (range_infers_for(self.var, pmember(%t),%t),
        if known?(of,self) Core/param!(list,self.of)
        else list[ pmember(c_type(self.set_arg))] )

//______________________  while/until  __________________________________

// similar to a For
c_type(self:While) : type -> infers_from(return_type(self.arg),self)

c_code(self:While,s:class) : any
 -> (let b := OPT.protection in
       (write(protection, OPT, false),
        let r := While(test = c_boolean(self.test),
                       arg = c_code(self.arg, void),
                       other = self.other) in
          (if (OPT.protection & OPT.loop_index >= 0) OPT.loop_gc := true,
           write(protection, OPT, (OPT.protection | b)),
           if (s != void & s != any)
             (//[5] ... insert a to_C with s = ~S for ~S // s,self,
              to_C(arg = r, set_arg = s)) // v3.3
           else r)))


// *********************************************************************
// *     Part 6: Iterate                                               *
// *********************************************************************

// finds the right restriction of Iterate
// Iterate applies to the non-evaluated types (meta level)
[Iterate!(self:Iteration) : any
 -> restriction!(Iterate,
                 list(set(self.set_arg), set(self.var), any), true) ]

// iteration methods
// note the beauty of this: we only apply the code transformation if
// we actually get a constant Interval
[iterate(x:Interval,v:Variable[range:subtype[integer]],e:any) : any
 => let v := eval(x.arg1,Interval),
        %max:integer := eval(x.arg2,Interval) in     // 2.4.07  => must protect !
       while (v <= %max) (e, v :+ 1) ]

iterate(x:array,v:Variable,e:any) : any
 => (let %i := 1, %a := x,
         %max := length(%a) in
       while (%i <= %max) let v := %a[%i] in (e, %i :+ 1))

Iterate(x:class,v:Variable,e:any) : any
 => (for %v_1 in x.descendents
       let %v_2 := (for v in %v_1.instances e) in (if %v_2 break(%v_2)))

Iterate(x:..[tuple(integer, integer)],v:Variable,e:any) : any
 => (let v := eval(x.args[1]),
         %max := eval(x.args[2]) in
        while (v <= %max) (e, v :+ 1))

Iterate(x:Lselect,v:Variable,e:any) : any
 => (for v in eval(x.set_arg) (if eval(substitution(x.arg, x.var, v)) e))

Iterate(x:Select,v:Variable,e:any) : any
 => (for v in eval(x.set_arg) (if eval(substitution(x.arg, x.var, v)) e))

Iterate(x:Collect,v:Variable,e:any) : any
 => (for C%v in eval(x.set_arg)
       let v := eval(substitution(x.arg, x.var,C%v)) in e)

Iterate(x:but[tuple(any, any)],v:Variable,e:any) : any
 => (for v in eval(x.args[1]) (if (v != eval(x.args[2])) e))

Iterate(x:/+[tuple(any, any)],v:Variable,e:any) : any
 => (for v in eval(x.args[1]) e, for v in eval(x.args[2]) e)


