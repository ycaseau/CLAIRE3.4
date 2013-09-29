//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| osystem.cl                                                  |
//| Copyright (C) 1994 - 2003 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file object.cl: about()               |
//+-------------------------------------------------------------+

//-------------------------------------------------------------------
// This file contains the gloabal parameter objects and the key methods
// This are the key methods
//
//  c_type(x)  is the CLAIRE type of x
//  c_code(x)  is an optimized instruction
//  & c_code(x,s) is an optimized expression of sort s
//  c_gc?(x)   [boolean] true if x must be protected from garbage collection
//  c_sort(x)  the sort of the expression x (precise sort)
//  c_status(x,l) [bitvector] abstract interpretation of x according to a set
//             of criterions (allocation, update, etc...)
//
// the sorts are integer, char, x <= imported, object, entity
//-----------------------------------------------------------------


// ******************************************************************
// *   Table of contents                                            *
// *    Part 1: General Global Variables and Properties             *
// *    Part 2: The defaults for c_type, c_code, c_gc and c_sort    *
// *    Part 3: c_new, c_sort, c_fonc                               *
// *    Part 4: Names & identifiers management                      *
// *    Part 5: On-line optimization                                *
// ******************************************************************

// import
// Compile/index :: Kernel/index
Compile/srange :: Kernel/srange
Compile/typing :: Kernel/typing
Compile/status :: Kernel/status
Compile/tmatch? :: Core/tmatch?
// Compile/test :: Language/test
//Compile/set_arg :: Language/set_arg
Compile/pname :: Core/pname
//Compile/other :: Language/other
Compile/if_write :: Kernel/if_write
// Optimize/extract_symbol :: Language/extract_symbol

// where to find the CLAIRE libraries
claire/home() : string -> getenv("CLAIRE3_HOME")     // TO CHANGE -> simply read claire_home


// ******************************************************************
// *    Part 1: General Global Variables and Properties             *
// ******************************************************************

// we use an optimizer object with all the necessary resources
// they are all private.
meta_OPT <: thing(
	Compile/instructions:list,        // list of compiled instructions
        Compile/objects:list,          // new named objects that are defined - v3.3.3: the order is important
        Compile/properties:set<property>, // new properties (implicit)
        Compile/functions:list,           // new functions
        Compile/need_to_close:set,        // properties that need to be closed
        Compile/need_modules:set,         // other modules that are needed
        Compile/legal_modules:set,        // modules that are allowed
        Compile/allocation:boolean = false,    // status: use an allocation
        Compile/protection:boolean = false,    //         use a GC protection
        Compile/alloc_stack:boolean = false,   //         use a stack allocation
        Compile/ignore:set,               // do not print
        Compile/to_remove:set,            // do not compile
        Compile/cinterface:port,          // port for the .h output
        Compile/outfile:port,             // port for the .Cpp output
        Compile/max_vars:integer = 0,          // max number of local variables
        Compile/loop_gc:boolean = false,       // used to signal that we optimize a loop
        Compile/loop_index:integer = 0,        // max index of var in loop
        Compile/level:integer = 0,            // indentation level
        Compile/in_method:any = unknown,      // current method (used to print context info)
        Compile/profile?:boolean = false,     // do we use the profiler
        Compile/cfile:any = false,            // used for file compilation mode
        use_update:boolean = false,    // used to record update for status
        use_nth=:boolean = false,      // update on bags
        online?:boolean = false,       // online optimization
        recompute:boolean = true,      // recompute the status
        unsure:list = nil,             // methods that need to be compiled at safety 1
        knowns:set<relation>,          // properties that are safe (no unknown)
        Compile/simple_operations:set<property>,   //  v3.3
        Compile/non_identifiable_set:set<class>,   // v 3.3
        Compile/use_string_update:boolean = false)     // update on strings   v3.3.46
       

// The meta_compiler contains the definition of the compiler flags and slots
// that are important for the user. Other stuff is hidden in OPT
meta_compiler <: thing(external:string,             // name of the output
                       claire/headers:list<string>, // headers
                       source:string,               // where to put the produced code
                       claire/debug?:list<module>,  // generate instrumented code for modules
                       version:any,
                       claire/active?:boolean = false,     // active = (loading | compiling)
                       claire/safety:integer = 1,   // cf .. later
                       claire/env:string = "ntw",   // OS info
                       claire/naming:integer = 0,          // naming mode (0: normal, 1: self-compile, 2: protected)
                       claire/libraries:list<string>,      // libs to be included
                       claire/inline?:boolean = false,     // do we want to use inlining
                       claire/loading?:boolean = false,    // mode (read the file vs compile)
                       claire/class2file?:boolean = false, //
                       claire/greedy?:boolean = false,     // allow un-necessary allocation -> faster
                       claire/libraries_dir:list,          // regular/debug
                       claire/headers_dir:string,          // include directory
                       claire/options:list,                // list of options
                       claire/overflow?:boolean = false,   // safe arithmetic
                       claire/diet?:boolean = false,       // flag non-diet fragments
                       claire/optimize?:boolean = false)   // v3.2.56: record -O option

// v3.2.38: greedy is no longer used ! -> a plan was to generate a faster STORENTH but it has
// been discontinued. greedy? becomes a deprecated feature

// the three variables that are used in the main files
claire/claire_options:string :: "/w0 /zq"
claire/claire_lib:string :: ""
claire/claire_modules:list :: list{get_value(x) |
                                   x in list("Kernel","Core","Language","Reader")}

// safety:
//       0  -> super-safe (check returns & gc safe)
//       1  -> safe
//       2  -> we trust explicit types & super
//       3  -> no overflow checking (integer & arrays)
//       4  -> no selector errors, no range error
//       5  -> cross-compiling (i.e. no errors)
//       6  -> unsafe (no GC)
claire/compiler :: meta_compiler(
   external = Id(compiler.external),
   env = Id(compiler.env),
   version = Id(version()),
   source = "",
   headers_dir = "",
   libraries = list<string>("Kernel"),
   options = Id(compiler.options))

// re-definable items for bootstrap modifications
claire/c_type :: property(Core/open = 3, range = type)
claire/c_code :: property(Core/open = 3)
claire/c_gc :: property(Core/open = 3)
Compile/get_index :: property(range = integer, Core/open = 3)
Compile/get_indexed :: property(range = bag, Core/open = 3)
Compile/make_c_function :: property(Core/open = 3)
Compile/make_float_function :: property(Core/open = 3)
Compile/c_expression :: property(Core/open = 3)
Compile/bool_exp :: property(Core/open = 3)
Compile/c_statement :: property()
claire/c_interface :: property(Core/open = 3)
Compile/c_sort :: property(Core/open = 3)

// other useful properties
Compile/designated? :: property()
Compile/sort= :: property()
Compile/psort :: property()
Compile/osort :: property()                        // Optimizer version of sorts
Compile/compile_lambda :: property()
Compile/c_check :: property()
Compile/need_protect :: property()
member_code :: property()
Compile/c_strict_code :: property()                // code with strict (stupid) type
Compile/c_strict_check :: property(Core/open = 3)  // new: allow future overload !!
Compile/stupid_t :: property()
Compile/object! :: property()                      // compiler instantiation
Compile/anyObject! :: property(range = object)     // fast instantiation if all any slots are known
Compile/Cerror :: property()
Compile/self_code :: property()                    // how to compile a type expression
Compile/get_module :: property()
claire/main :: property()

// these are the classes defined especially for this module
Compile/to_protect <: Optimized_instruction(arg:any)
Compile/to_CL <: Optimized_instruction(arg:any,set_arg:class)
Compile/to_C <: Optimized_instruction(arg:any,set_arg:class)
Compile/C_cast <: to_C()
Pattern <: Type(selector:property,       //
                arg:list)                // the tuple is made into a list

// OPT contains all the parameters for the optimizer
claire/OPT :: meta_OPT(
    outfile = stdin, cinterface = stdin,
    ignore = set(mClaire/index!, mClaire/set_index, object!, mClaire/base!, mClaire/set_base,
                 mClaire/push!, anyObject!, mClaire/get_stack, mClaire/put_stack),
    to_remove = set(interface),
    knowns = set<relation>(arg1,arg2),                     // v3.1.12
    unsure = list(+ @ integer, * @ integer, - @ integer),
    simple_operations = {+, -, /, *},                      // v3.3
    non_identifiable_set =
                    Id(set<class>{c in class | exists(c2 in c.descendents | c2.ident? = false)}))



claire/safe(x:any) : type[x] -> x

// ******************************************************************
// *    Part 2: The defaults for c_type, c_code, c_gc and c_sort    *
// ******************************************************************


// basic type inference
[c_type(self:any) : type
 -> case self
      (Variable let r := get(range, self) in
                  (if (r = unknown) any
                   else if (case r (Union r.Core/t1 = {})) r.Core/t2.Core/t2
                   else ptype(r)),
       global_variable let r := self.range in
                         (if r r else set(self.value)),
       unbound_symbol Cerror("[215] the symbol ~A is unbound_symbol", self.name),
       error {},
       Update c_type(self.value),
       Construct (if not(self % (List U Set)) any
                 else let %res:type := {} in
                        (for %x in self.args
                           (if %res %res :meet class!(c_type(%x))
                            else %res := class!(c_type(%x))),
                         nth((case self (Set set, any list)),
                             %res))),
       Instruction error("c_type of ~S is not defined",owner(self)), //<yc:v0.01>
       any set(self)) ]

// compile into a sort and checks strict type matching (naive/stupid)
[c_strict_code(x:any,s:class) : any
 -> c_strict_check(c_code(x, s), s) ]

[c_strict_check(x:any,s:class) : any
 -> if (not(OPT.online?) & s inherit? object & not(stupid_t(x) inherit? s))
       (if (c_type(x) = any)     // v3.2.06 - avoid C++ compiler error !
           Cerror("Need explict cast: ~S is not a ~S",x,s),
        C_cast(arg = x, set_arg = s))
     else x ]

// using conversions. s is a sort or void (we do not need the value).
// note: we need s to be the precise sort for C++
// the is the default version that uses c_code(x)/ c_sort(x)
[c_code(x:any,s:class) : any
 -> let y := (case x (Call c_code_call(x,s), any c_code(x))),   // v2.4.9 safe sort for inline !
        z := c_sort(y) in
      (if (s = void | z = s | OPT.online?)
           (if (s = void & (case x (Call x.selector = =)))
               (warn(),
                trace(2,"-- Equality meant as an assignment: ~S [264]\n",x)),    // v3.3
            y)       // v3.0.44 BIG CHANGE
       else if (s = any)
         (if (z = integer & y % Call_slot &                       // need a proper slot
              not(compiler.overflow? & compiler.class2file?)) y   // UGLY: v3.0.42
          else if (y % to_C) arg(y as to_C)
          else (if (z = float)
                   (OPT.protection := true,             // v3.2.30 - implicit protection !
                    OPT.allocation := true),            // v3.2.30 - _float_ will cause an allocation
                to_CL(arg = y, set_arg = psort(c_type(y)))))
       else if (z = any) to_C(arg = y, set_arg = s)
       else y) ]

// basic code generation
// c_code without a sort parameter means that we do not care about the resulting sort,
// which will be checked later on using c_sort
[c_code(self:any) : any
 -> case self
      (unbound_symbol Cerror("[215] the symbol ~A is unbound_symbol", self.name),
       Variable self,
       global_variable (c_register(self), self),
       Optimized_instruction self,
       Instruction Cerror("[internal] c_code(~S) should have a parameter", self),
       set (if self
              let x :=  Set(args = list!(self)) in
                 (if (of(self) != void) x.of := of(self),
                  c_code(x))
            else self),
       list (if self
               let x := List(args = self) in
                    (if (of(self) != void) x.of := of(self),
                  c_code(x))
             else self),
       tuple c_code(Tuple(args = self)),
       any (if (self % thing) c_register(self),
            if (self % (float U function)) OPT.allocation := true,
            self)) ]

// basic gc protection
// v3.3.3 : do not protect float, which requires that they are stored properly
[Compile/c_gc?(self:any) : boolean
 -> case self
      (Variable false,
       global_variable not(gcsafe?(self.range)),
       Construct (OPT.loop_gc & (self % List | self % Set)), // v3.3.3  List constructors are SAFE_RESULT by construction
                                                             // but this protection is not enough in a loop
       Instruction false,            // defined recursively
       string OPT.use_string_update, // implies copy, which implies a protection (v3.3.48)
       any false) ]                  // TODO : protect functions !!!!

// gives the sort of a compiled expression (does not apply to instructions that
// have a direct c_code(x,s)
// v2.4.9: special type => special sorts !!!
[c_sort(self:any) : class
 -> case self
      (global_variable (if nativeVar?(self) (if (self.range = {}) osort(owner(self.value))
                                             else osort(self.range))
                        else any),    // v3.3 ! was any,
       Instruction case self
                   (Variable sort(self),
                    Assign sort(self.var),
                    Call osort(selector_psort(self)),
                    Call_method (if (self.arg.selector = externC & length(self.args) = 2)
                                    psort(self.args[2] as class)
                                 else c_srange(self.arg)),
                    Call_slot srange(self.selector),
                    Call_table any,
                    Call_array (if (self.test = float) float else any),
                    Definition object,
                    to_C self.set_arg,
                    to_protect c_sort(self.arg),
                    Update c_sort(self.value),
                    If psort(c_sort(self.arg) meet c_sort(self.other)),
                    Handle  psort(c_sort(self.arg) meet c_sort(self.other)),
                    Let c_sort(self.arg),
                    to_CL any,
                    Return  any,
                    List object,
                    Set object,
                    Tuple object,
                    Construct any,
                    Gassign  any,
                    Super any,
                    For any,
                    Exists (if (self.other = unknown) any else object),
                    Iteration object,
                    And boolean,
                    Or boolean,
                    While any,
                    Do c_sort(last(self.args)),
                    any error("[internal] c_sort is not implemented for ~S",
                              owner(self))),
       float float,
       any psort(c_type(self))) ]

// for the special compiler properties, we need to tell the sort of the optimized
// form
[selector_psort(self:Call) : class
  -> let p := self.selector in
       (if (p = mClaire/base! | p = mClaire/index!) integer
        else if (p = anyObject!) (self.args[1] as class)
        else if (p = object!) (self.args[2] as class)
        else any) ]


// ******************************************************************
// *    Part 3: c_status                                            *
// ******************************************************************


// this is one of the most important method. c_status(x,l) returns the status bitvector
// associated to the method defined by the body x and whose variable list is l.
// It computes (using the code BEFORE optimization) the status of the 6 important flags
// NEW_ALLOC :       a new allocation may be done by running the method
// LIST_UPDATE :     a list is updated whose content is not gcsafe
// SLOT_UPDATE :     an slot is updated whose content is not gcsafe
// RETURN_ARG :      the result is (may be) one of the input argument (or a slot from ...) // v3.3.3
// SAFE_RESULT :     the result from the method (not gcsafe) does not need protection
// SAFE_GC :         the arguments do not need protection (even if an alloc occurs) -the method
//                   takes care of its arguments (pushed on a stack for instance)
// STRING_UPDATE     a string is modified (forbiden by C++ if const char) -> a copy is required  // v3.3.46
// this method is allowed to be pessimistic as far as allocation are concerned
[c_status(self:any,l:list) : integer
 -> case self
      (Instruction case self
            (Variable
               (if (unknown?(range, self) | not(gcsafe?(self.range)))
                  (if (self % l) bit_vector(RETURN_ARG)
                   else if (known?(range,self) & self.range <= float) bit_vector(NEW_ALLOC)
                   else 0)
                else bit_vector(SAFE_RESULT)),
             Error bit_vector(SAFE_RESULT),
             Printf c_return(0, c_or(list{c_status(x,l) | x in self.args})),
             Construct bit_vector(NEW_ALLOC),
             Definition bit_vector(NEW_ALLOC),
             Call let r1 := c_status_call(self.selector,c_type(l[1])),              // v3.3.48
                      r2 := c_or(list{c_status(x,l) | x in self.args}) in
                    c_return(r1,r2),                                 
             If let r1 := c_status(get(arg, self), l),
                    r2 := c_status(get(other, self), l) in
               c_return(c_or(r1,r2),c_status(self.test, l)),
             Do let y := last(self.args), r1 := c_status(y, l),
                    r2 := c_or(list{c_status(x, l) | x in self.args but y}) in
                 c_return(r1,r2),
             For c_return( c_status(self.arg,l), c_status(self.set_arg, l)),
             Iteration c_return(bit_vector(NEW_ALLOC), c_status(self.arg,l)),
             Let c_return(c_status(self.arg, l),
                          c_status(get(value, self), l)),
             Assign c_status(get(arg, self), l),
             Gassign c_status(get(arg, self), l),
             And c_return(0,c_or(list{c_status(x, l) | x in self.args})),
             Or c_return(0,c_or(list{c_status(x, l) | x in self.args})),
             Cast c_status(self.arg, l),
             Super let r1 := c_status_call(self.selector,self.cast_to),
                       r2 := c_or(list{c_status(x,l) | x in self.args}) in
                    c_return(r1,r2),
             Case c_or(list{c_status(x, l) | x in self.args}),
             While c_return(c_status(self.arg, l),c_status(self.test, l)),
             Return c_status(self.arg, l),
             Handle c_return(c_or(c_status(self.arg, l), c_status(self.other, l)),
                             c_status(self.test, l)),
             unbound_symbol 0,
             any Cerror("[internal] oops .. I forgot ~S",owner(self))),
       float bit_vector(NEW_ALLOC),
       string bit_vector(NEW_ALLOC),
       function bit_vector(NEW_ALLOC),
       Type bit_vector(NEW_ALLOC),
       any 0) ]

// this methods combines two status vector, assuming that the result could be
// one or the other
// note that the semantic for the SAFE_RESULT flag is an and (both must be safe)
// v3.4 same for RETURN_ARG : the semantic is an and
[c_or(x:integer,y:integer) : integer
 -> let d := (x or y) in
     (if ( d[SAFE_RESULT] & not(x[SAFE_RESULT] & y[SAFE_RESULT])) d :- ^2(SAFE_RESULT),
      if ( d[SAFE_GC] & not(x[SAFE_GC] & y[SAFE_GC])) d :- ^2(SAFE_GC),
      if ( d[RETURN_ARG] & not(x[RETURN_ARG] & y[RETURN_ARG])) d :- ^2(RETURN_ARG),   // v3.4
      d)  ]


[c_or(l:list) : integer
 => let d := 0 in (for x in l d := c_or(d,x), d) ]

// computes the status of a method if unknown. We use the c_status method to
// compute a bitvector
[Compile/status!(self:restriction) : integer
 -> case self
      (method (if known?(status, self) self.status
               else if unknown?(formula, self)
                 (write(status, self, 0), 0)
               else (self.status := 0,
                     self.status := c_status(self.formula.body,
                                             self.formula.vars),
                     //[4] status(~S) = ~S // self,self.status,
                     self.status)),
       any 0) ]


// this is a special version where only x may be returned, thus dominates the
// two result flags
[c_return(x:integer,y:integer) : integer
-> let d := (x or y) in
     (if ( not(x[SAFE_RESULT]) & y[SAFE_RESULT]) d :- ^2(SAFE_RESULT),
      if ( not(x[RETURN_ARG]) & y[RETURN_ARG]) d :- ^2(RETURN_ARG),
      d)  ]

// computes the status vector associated to a property
// v3.3.38: use the type of the first argument to filter out restrictions that are irrelevant
[c_status_call(self:property,t:type) : integer
 -> let r := (if stable?(self) 0 else bit_vector(NEW_ALLOC,BAG_UPDATE,SLOT_UPDATE)) in
      (for x in self.restrictions
        (if (t glb x.domain[1])
             case x (method (if not(last(x.srange) % {integer,any,object,void})
                                r := c_or(r,bit_vector(NEW_ALLOC)),                // return value may require an allocation
                             r := c_or(r,status!(x))),
                     slot r := c_or(r,^2(RETURN_ARG)))),  // v3.3.3 : return x.r is same as return x as far as GC protection is concerned
       r) ]

// here we fix some status by hand
(write(Core/status, Core/vmatch? @ any, bit_vector(SAFE_GC)),
 write(Core/status, Core/pop_debug @ property, 0),
 write(Core/status, Core/matching? @ list, bit_vector(SAFE_GC)),
 write(Core/status, Core/eval_message @ property, bit_vector(NEW_ALLOC,SLOT_UPDATE,SAFE_GC)),
 write(Core/status, nth @ bag, bit_vector(RETURN_ARG)),   // v3.3.3 returning a part of a list is like a slot of an object !
 write(Core/status, eval @ any, bit_vector(NEW_ALLOC)),
 write(Core/status, self_eval @ Call, bit_vector(SAFE_GC)),
 write(Core/status, self_eval @ If, bit_vector(SAFE_GC)),
 write(Core/status, self_eval @ Do, bit_vector(SAFE_GC)),
 write(Core/status, nth= @ string, bit_vector(STRING_UPDATE)),
 write(Core/status, nth_put @ string, bit_vector(STRING_UPDATE)))   // v3.3.46


// useful #1: show a status
[claire/showstatus(m:method) : any
  -> let l1 := list("NEW_ALLOC","BAG_UPDATE","SLOT_UPDATE","RETURN_ARG","SAFE_RESULT","SAFE_GC","STRING_UPDATE"),
         l := list<any>(), s := Core/status(m) in
       (for i in (1 .. 7) (if s[i] l :add l1[i]), l) ]

// useful #2: provoke a recomputation of status
[claire/s_test(m:method) : void
  -> let  la := m.formula,
          news := c_status(la.body,la.vars) in
       (//[0] status(~S) := ~S // m, news,
        Core/status(m) := news,
        showstatus(m)) ]

// ******************************************************************
// *    Part 4: Names & identifiers management                      *
// ******************************************************************

// check that the module is allowed and otherwise complain because of x;
// this should raise an error, it simply returns false if there is a problem
[legal?(self:module,x:any) : boolean
 -> if (x = object! | x = anyObject!) true
    else if (OPT.legal_modules)
       (if (not(self % OPT.legal_modules)  &
            (case x (method (x.inline? = false | not(compiler.inline?)))))
        (trace(0, "legal_modules = ~S\n", OPT.legal_modules),
         trace(0, "---- ERROR: ~S implies using ~S !\n\n", x, self),
         false)
        else true)
     else (need_modules(OPT) :add self, true) ]

legal?(self:environment,x:any) : any -> true

// A named object is used, thus it must be declared if it belongs to the
// current module - returns true if OK
[c_register(self:(thing U class)) : any
 -> let x := get_module(self) in
       (if (x != system) legal?(x, self) else true) ]

// looks if a property may be implicit and then add it in the right list
[c_register(self:property) : any
 -> let m := module!(), m2 := get_module(self) in
     (// while (m.loaded = 0) m := m.part_of,     // <yc> 7/98: we need the compilation unit
      if ((m2 = claire | m2 = m) & //   v3.2.4  (self % property) &
          not(self % OPT.objects)) //   v3.2.4  & not(self % OPT.properties))
        OPT.properties :add self,
      c_register@thing(self)) ]

// declare the property as used and check if a property may allocate
[selector_register(self:property) : any
 ->  c_register(self),
     if (allocate?(self) = true) OPT.allocation := true,
     self ]

// looks if a property may cause an allocation
[allocate?(self:property) : any
 ->  for x in self.restrictions
       case x
        (slot (if (not(gcsafe?(x.range)) & srange(x) != any) break(true)
              else if (not(gcsafe?(x.range)) & not(gcsafe?(domain!(x))))
                 break(0)),
         method (if (status!(x)[NEW_ALLOC] |
                      not(c_srange(x) % {any,integer,object}) |
                     not(gcsafe?(x.range))) break(true))) ]

// this method looks if the open slot is less than 1 or can be set to 1
// v3.3.48 note - weaken the open semantic to get a better c_status
[stable?(self:relation) : boolean
 -> let m := get_module(self) in
       (if (self.open = 2) // v3.3.48  - was :  & (m % OPT.legal_modules | m = system))
           write(open, self, 1)),
     self.open <= 1 | self.open = 4 ]                       // v3.2.04

// returns the module (i.e. the compilation unit, not the namespace) in which self is
// defined
[get_module(self:(thing U class)) : any
  -> defined(self.name) ]
//      (while (m.loaded = 0) m := m.part_of, m) ]


// allows to optimize the access
[known!(l:listargs) : any
 -> (to_remove(OPT) :add known!,
     for r in l (case r (property OPT.knowns :add r))) ]


// ******************************************************************
// *    Part 5: On-line optimization                                *
// ******************************************************************


// a cute method that optimises all methods
oload(m:module) : any -> (load(m), turbo(m))
oload(f:string) : any -> (load(f), turbo(module!()))

[turbo(m:module) : any
 -> let vb := system.verbose in
       (OPT.online? := true,
        verbose() := 0,
        for x:method in method
          (if (x.module! = m & not(x.inline?) & known?(formula, x))
              let l := x.formula,
                  y := l.body in
                try (if (x.range = any) write(range, x, c_type(y)),
                     write(body, l, c_code(y, any)),
                     *variable_index* := length(l.vars) + 1,
                     write(body, l,
                           Language/lexical_build(l.body, l.vars, *variable_index*)),
                     write(dimension, l, *variable_index*))
                catch any (write(body, l, y), nil)),
        OPT.online? := false,
        verbose() := vb,
        true) ]

// prints the optimisation stats - todo
[stats(x:meta_OPT) : void -> nil]


