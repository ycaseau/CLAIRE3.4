//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| gsystem.cl                                                  |
//| Copyright (C) 1994 - 2003 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file object.cl: about()               |
//+-------------------------------------------------------------+

//**********************************************************************
//* Contents                                                           *
//*          Part 1: Global_variables & producer interface             *
//*          Part 2: Module Compiler Interface                         *
//*          Part 3: File Compiler                                     *
//*          Part 4: Function Compiler                                 *
//**********************************************************************


//**********************************************************************
//*          Part 1: Global_variables                                  *
//**********************************************************************

// ----------------------- inline coding --------------------------------
// here we have a list of methods that we want to handle in a special way
// these variables exist already
Compile/*?_interval* :: (set! @ Interval) 
Compile/*--_integer* :: (.. @ integer)
Compile/*+_integer* :: (+ @ integer)
Compile/*nth_integer* :: (nth @ integer)
Compile/*nth_list* :: (nth @ list)
Compile/*nth_1_bag* :: (nth_get @ bag)
Compile/*nth_string* :: (nth @ string)
Compile/*nth_1_string* :: (nth_get @ string)
Compile/*nth=_list* :: (nth= @ list)
Compile/*not* :: (not @ any)
Compile/*known* :: (known? @ any)
Compile/*unknown* :: (unknown? @ any)
Compile/*not_equal* :: (!= @ any)
Compile/*contain* :: (contain? @ list)
Compile/*min_integer* :: (min @ integer)
Compile/*max_integer* :: (max @ integer)
Compile/*length_array* :: (length @ array)
Compile/*length_bag* :: (length @ bag)
Compile/*close_exception* :: (close @ exception)            // v3.2.58  */


// new: the target code production (the part that depends on the target language) is
// encapsulated with a producer object
producer <: thing(
   open_comparators:list[operation],      // list of comparison ops that are inlined (the order matters!!)
   open_operators:list[operation],        // list of arithmetic operators that are inlined
   body:any = 0,                          // used to store the body of the current method
   extension:string,                      // extension for generated files
   comment:string,                        // a string that designates the target language
   interfaces:list,                       // used to translate imported to C/.. entities
   stat:integer = 0)                      // v3.3.32: stats about GC protection

claire/PRODUCER:producer :: unknown

// most standard method: call the producer to print the ident from a symbol
ident(self:symbol) : void -> ident(PRODUCER,self)
ident(self:thing) : void -> ident(PRODUCER,self.name)
ident(self:class) : void -> ident(PRODUCER,self.name)
interface!(c:class) : void -> interface!(PRODUCER,c)
class_princ(c:class) : void -> class_princ(PRODUCER,c)

// we simply use some smart identation. True pretty_printing will be left to bc
indent_c() : any
 -> (let x := OPT.level in while (x > 0) (princ("  "), x :- 1))

breakline() : any -> (princ("\n"), indent_c())

// adds a new C block with the condensed option
new_block() : void
 -> (OPT.level :+ 1, princ("{ "))

// closes the current C block
close_block() : void -> (OPT.level :- 1, princ("} "), breakline())

// TODO: define a status = 3 for the PRODUCER class that tells that is it extensible
(producer.open := 3)

//*********************************************************************
//*          Part 2: Module Compiler Interface                        *
//*********************************************************************

// NOTE/ THIS PART MUST BE COMPLETELY RE-ORGANIZED
// -> the class2file mode is defined in the *gen part
//    the interface stuff as well

// a small test function for the compiler
claire/c_test(x:any) : void
 -> (let t := c_type(x),
         s := osort(t),
         u := c_code(x, s),
         f := Compile/c_func(u) in
       (printf("type -> ~S [sort ~S]\n", t, s),
        printf("opt[~S] -> ~S \n", owner(u), u),
        if f printf("exp  -> ~I\n", expression(u, nil))
        else printf("stat -> ~I\n", statement(u, "result", nil))))


// v3.2.32
[c_test(m:method) : void
  -> when l := get(formula,m) in
        (//[0] ---- Compiling ~S ---- // m,
        OPT.in_method := m,
        OPT.protection := false,
        OPT.allocation := false,
        if (OPT.loop_index > 0) OPT.loop_index := 0,
        OPT.loop_gc := false,
        OPT.Optimize/use_update := false,
        OPT.Optimize/use_nth= := false,
        OPT.Optimize/use_string_update := false,   // v3.3.46
        OPT.Optimize/max_vars := 0,
        OPT.Optimize/online? := false,
        OPT.legal_modules := module.instances,
        // start make_c_function ....
        PRODUCER.body := l.body,
        let s := void,
            %body := (s := check_sort(m), PRODUCER.body),
            %end := protect_result(PRODUCER, s, OPT.protection, m) in
         (printf("Opt => ~S \n\n",%body),
          new_block(),
          print_body(%body,%end,s,l.body, true)),
        OPT.in_method := unknown ) ]

// compile the modules and check that no necessary modules is not
// declared
[claire/compile(self:module) : void
 -> OPT.need_modules := {},
      let l1:bag := parents(Reader/add_modules(list(self))) in
      (OPT.legal_modules := set!(l1),
       if compiler.class2file?
          (//[2] **** Compiling the module ~A [v. 3.~A - verbose:~A opt:~S] // string!(self.name), compiler.version, verbose(), compiler.optimize?,
           // OPT.module! := self, v0.02
           OPT.outmodule := fopen(compiler.source /+ *fs* /+ c_string(PRODUCER,self.name) /+ PRODUCER.extension,"w"),
           generate_files(self),
           begin(self),                    // v3.0.3
           generate_classes(self),
           generate_c2f(self),
           end(self))                      // module -> file in the ClassToFile mode
        else (//[5] call generate_files ~S  // self,
              generate_files(self),                // files to files
              generate_f2f(self),                  // module -> file in the FileToFile mode
              generate_interface(self, OPT.legal_modules)),
       l1 := difference(set!(OPT.need_modules), OPT.legal_modules),
       //[5] ++++ v3.3.32 info: ~A GC protection inserted. // PRODUCER.stat,
       if l1 trace(2, "---- WARNING: ~S should be declared for ~S\n", l1, self)) ]

// the first part is to generate the C files in the FileToFile mode
[generate_files(self:module) : void
 ->  //[0] ==== Generate ~A files for module ~S [verbose = ~A, Opt? = ~S] // PRODUCER.comment, self, verbose(),compiler.optimize?,
     OPT.instructions := list<any>(),
     OPT.properties := set<property>(),
     OPT.objects := list<object>(),
     OPT.functions := list<any>(),
     OPT.need_to_close := set<any>(),
     start_module_interface(PRODUCER,self),
     begin(self),
     for x in self.made_of
       (//[2] ++++ Compiling the file ~A.cl [v. 3.~A - safety:~A] // x, compiler.version, compiler.safety,
        if (x = string!(self.name))
           Cerror("[211]  ~S cannot be used both as a file and module name",x),
        generate_file((self.source /+ *fs*) /+ x,
                      (compiler.source /+ *fs*) /+ x),
        if false gc()),     // TO REMOVE UGENTLY
     end(self) ]

// This makes the initial loading function by compilinf all the claire
// expression placed in the list oself. *new_objects* holds all the new
// objects defined in this file.
// The name of the function is built from the file name (s argument)
//
[generate_f2f(m:module) : void
 -> let p := fopen(((compiler.source /+ *fs*) /+ string!(m.name)) /+ PRODUCER.extension,
                   "w") in
      (//[0] ==== generate file for module ~S [~A GC protections inserted] ==== // m,PRODUCER.stat,
       OPT.outfile := p,
       generate_file(string!(m.name), m)) ]
       
// v3.2.22 : make this part dependent on the producer
[generate_file(s:string, m:module) : void
 -> start_file(s,m),
    use_as_output(OPT.outfile),
    generate_classes(PRODUCER,s,m),                 // v3.2.44
    for c in list{x in OPT.objects | x % class}     // new in v3.1
       methods_bodies(PRODUCER,c),                  // interface methods
    generate_meta_load(m),
    breakline(),
    printf("GC_UNBIND;"),
    close_block(),
    breakline(),                       // v3.0.3
    fclose(OPT.outfile)]

// ----------------- ClassToFile Mode (FXJ) ----------------------------------------

classFile[c:class] : port := unknown        //  classe ==> port

// prints the definition of classes and their FIELDS (and not slots :-)
[generate_classes(self:module) : void
 -> erase(classFile),
    for c in {c in OPT.objects | c % class}
       (classFile[c] := fopen(compiler.source /+ *fs* /+ c_string(PRODUCER,c.name) /+ PRODUCER.extension,"w"),
        use_as_output(classFile[c]),
        trace(2, "++++ Creating the file ~A.java\n", c_string(PRODUCER,c.name)),
        OPT.level := 0,
        printf("// class file for ~S in module ~S ",c,self), // v0.02
        breakline(), breakline(), breakline(),
        printf("public class ~I extends ~I~I~I~I/* empty constructor by default */~Ipublic ~I() {}~I~I~I/* declaration of fields */~I~I",
               ident(c.name),
               ident(c.superclass.name),
               new_block(),
               breakline(),breakline(),breakline(),
               ident(c.name),
               breakline(),breakline(),breakline(),
               for y:slot in {s in get_indexed(c) | domain!(s) = c}
                  (breakline(),
                   printf("public  ~I ", interface!(psort(y.range))),
                   ident(y.selector.name),
                   princ(";")),
               breakline() ),
        fclose(classFile[c])) ]

// TODO: clean the gc() once CLAIRE is stable
[generate_c2f(self:module) : void
 -> let modulePort := fopen(compiler.source /+ *fs* /+ c_string(PRODUCER,self.name) /+ PRODUCER.extension,"w") in
      (OPT.outfile := modulePort,
       use_as_output(modulePort),
       generate_start_file(PRODUCER,self),
       fclose(modulePort),                                      // <FXJ> : PATCH!
       gc(),
       generate_functions(self),
       gc(),
       modulePort := fopen(compiler.source /+ *fs* /+ c_string(PRODUCER,self.name) /+ PRODUCER.extension,"a"),    // <FXJ> : PATCH!
       use_as_output(modulePort),     // may be changed ....
       OPT.outfile := modulePort,                               // <FXJ> : PATCH!
       OPT.level := 2,
       generate_objects(self),
       use_as_output(stdout),
       gc(),
       use_as_output(modulePort),
       generate_meta_load(self),
       generate_end_file(PRODUCER,self)) ]

// the second part is to generate the interface. l is the list of modules
// that were physically used by the module.
[generate_interface(self:module,l:bag) : void
 -> //[0] ==== Generate inteface (.h) files for module ~S // self,
    use_as_output(OPT.cinterface),
    breakline(),
    generate_interface(PRODUCER,self),      // v3.2.44
    namespace!(PRODUCER,self),
    generate_objects(self),
    module!(PRODUCER,self),
    end_module_interface(PRODUCER,self),
    fclose(OPT.cinterface),
    use_as_output(stdout) ]


// generate the definition of the named objects from the module (used in both modes)
// must move to the producer
[generate_objects(self:module)  : void
 -> for x in OPT.objects      // remove classes
      (breakline(),
       public_static(PRODUCER),
       case x
        (global_variable                                 // v3.3 - new ! native global vars
           printf("~I ~I;",
                  interface!(PRODUCER,(if nativeVar?(x) getRange(x) else global_variable)),
                  ident(x.name)),
         any printf("~I ~I;",
                interface!(PRODUCER,Compile/psort(owner(x))),
                (if (x % class) ( princ("_"),  c_princ(string!(x.name)))
                 else if (x % reserved_keyword)
                   (princ("_cl_"), c_princ(string!(x.name)))
                 else ident(x.name))))),
     for x in {p in OPT.properties | not(p % OPT.objects) }  
       (when p2 := some(p2 in (OPT.properties but x) |            // v0.01
                        string!(p2.name) = string!(x.name)) in
         error("[217] ~S and ~S cannot be defined in the same module",p2,x),
        printf("\n~I~I ~I;// ~S",
               public_static(PRODUCER),
               interface!(PRODUCER,Compile/psort(owner(x))),
               ident(x.name), x.name)) ]



// generate the meta_load function
[generate_meta_load(self:module) : void   // v0.02
  -> printf("// definition of the meta-model for ~S \n~I",self, breakline()),
     generate_meta_load(PRODUCER,self),       // 1st lines are target dependent
     printf("// definition of the properties ",breakline()),
     for x in {p in OPT.properties | not(p % OPT.objects)}
        declare(PRODUCER,x),
     breakline(), breakline(),
     printf("// instructions from module sources",breakline()),
     let j:any := unknown in (
       for i in OPT.instructions (
          breakline(),
          if (i % string)  printf("~I// ~A", (if not(j % string) breakline()), i)
          else if global_var_def?(i) global_var_def!(PRODUCER, self, i as Let) // v3.3
          else  statement(i, {}, {}),
          j := i))]


// v3.3 trap global variable definitions

// pattern matching
[global_var_def?(x:any) : boolean
  -> case x (Let (x.value % Call & x.value.selector = Compile/object! &
                           x.value.args[2] = global_variable),
             any false) ]

[getRange(x:global_variable) : class
  -> (if (x.range = {}) owner(x.value) else class!(x.range)) ]


// generate the body of the methods
[generate_functions(self:module) : void
 -> printf("// definition of class methods "),
    let p := OPT.outfile in
         (for f in OPT.functions
           (OPT.level := 2,
            OPT.outfile := p,
            print_c_function(f[1],f[2],f[3]))) ]      // v0.04 TO CHECK WITH FXJ



// This is a similar method which places all the necessary modules
// in the right order so that self can be defined
parents(self:module,l:list) : list
 -> (if (self % l) l
     else (if known?(part_of, self) l := parents(self.part_of, l),
           l :add self, l))

// this methods takes a list of modules that must be loaded and returns
// a list of modules that are necessary for the definition
//
parents(self:list) : list
 -> (let l := list<module>() in (for x in self l := parents(x, l), l))

// useful (v3.0.06)
[claire/get(m:module) : void ->  load(m), begin(m) ]


// *********************************************************************
// *     Part 3: File compilation                                      *
// *********************************************************************

// this is the basic file cross_compiler, which translates from claire to C
// this file compiler runs only in the good environment (the file
// to be compiled must be already loaded).
// changed ib v0.02 to accomodate F2C mode
[generate_file(self:string,f2:string) : void
 -> let p1 := fopen(self /+ ".cl", "r"), b := reader.Reader/toplevel,
        p0 := reader.Reader/fromp in
       (if not(compiler.class2file?)                 // v0.02
           OPT.outfile := fopen(f2 /+ PRODUCER.extension, "w"),
        reader.Reader/toplevel := false,
        compiler.loading? := true,
        reader.Reader/nb_line := 1,
        reader.external := self,
        reader.Reader/fromp := p1,                     //<yc> ensures automatic fclose !
        if not(compiler.class2file?) start_file(self,module!()),
        let %instruction := Reader/readblock(p1) in
          while not(%instruction = Reader/eof)
            (if (system.verbose > 5)
               printf("[~A] ~S (~S%)\n", reader.Reader/nb_line, owner(%instruction),
                       OPT.need_modules),  
             if (%instruction % string & not(compiler.class2file?))
              (if (compiler.Optimize/naming < 2)
                let pp := use_as_output(OPT.outfile) in
                 (printf("\n//~A", %instruction),
                  use_as_output(pp)))
             else OPT.instructions :add c_code(%instruction, void),
             %instruction := Reader/readblock(p1)),
       fclose(p1),
       compiler.loading? := false,
       reader.Reader/toplevel := b,
       reader.external := "toplevel",
       reader.Reader/fromp := p0,
       if not(compiler.class2file?) fclose(OPT.outfile)) ]



//**********************************************************************
//*     Part 4: the lambda-to-function compiler                        *
//**********************************************************************

// This method creates a C/C++/Java function from a claire lambda.
// The body of the function is obtained by an apporpriate call to the C compiling methods
// m is either unknown/{} for a free lambda, or the method to which the lambda
// is bound.
[make_c_function(self:lambda,%nom:string,m:any) : any
 -> if  compiler.class2file?
        create_function_entry(PRODUCER,self,%nom,m)   // OPT.functions :add list(self,%nom,m)
    else print_c_function(self,%nom,m) ]

// ------------ new version with optimized body generation ------------------------

// this method produced the code associated with a lambda. m is either the
// corresponding method or the range for a free lambda, or nil for a demon
[print_c_function(self:lambda, %nom:string, m:any) : any
 ->  PRODUCER.body := self.body,
     let s := void,
         %body := (if not(m) c_code(self.body, void)
                   else if (m % method) (s := check_sort(m), PRODUCER.body)
                   else if (m % class) (s := (m as class), c_code(self.body,m)) // v0.01
                   else (s := any, c_code(self.body, any))),
         %end := protect_result(PRODUCER, s, OPT.protection, m),
         %debug := need_debug?(m),
         %profile := (OPT.profile? & (m % method | m = unknown))  in    // unknown => demon
       (generate_function_start(PRODUCER, self, s, m, %nom),        // remove one parameter (%f)
        if (OPT.max_vars > 0)
           (*variable_index* := 0,
            lexical_num(%body, length(self.vars) + 1),    //<yc> bug with new var indexes 6/5/98
            OPT.loop_index := *variable_index*),          // better since v3.0.60
        new_block(),
        if %profile generate_profile(PRODUCER,m),
        if %debug debug_intro(PRODUCER,self, m),
        //   [debug] method ~A [loop_gc = ~S]... // %nom,OPT.loop_gc,
        print_body(%body,%end,s,self.body,
                   not(OPT.protection | %profile |%debug | OPT.alloc_stack)),
        close_block(),
        breakline(),
        OPT.alloc_stack := false,
        use_as_output(stdout)) ]

// version for Ifs
[print_body(%body:If,%end:string,s:class,%original:If,%easy:boolean) : void
  -> if (c_func(%body.test) & OPT.protection & c_safe(%original.arg) &
         not(module!() % compiler.debug?))
       let %end2 := (if (s != void) "return " else "") in
       (printf("if ~I ~I~I ~Ielse",
               bool_exp(%body.test, true, nil),
               (breakline(),new_block()),
               outer_statement(%body.arg,%end2,s,%easy),
               close_block()),
        new_block(),
        print_body(%body.other,%end,s,%original.other,%easy),
        close_block())
     else print_body@any(%body,%end,s,%original,%easy)]

[print_body(%body:any,%end:string,s:class,%original:any,%easy:boolean) : void
  -> gc_introduction(PRODUCER,%body),               // v3.0.55
     outer_statement(%body,%end,s,%easy) ]

// special case when the body is a Do
[print_body(%body:Do,%end:string,s:class,%original:any,%easy:boolean) : any
 -> let l := %body.args, %length := length(l), m := 0 in
      (gc_introduction(PRODUCER,%body),        // v3.0.55
       for x in l
        (m :+ 1,
         if (m = %length) outer_statement(x,%end,s,%easy)
         else inner_statement(x, {}, {}))) ]

// prints a return statement - changed in v3.2.44 to take care of ANSI C requiprements
[outer_statement(%body:any, %end:string,s:class, %easy:boolean) : void 
   -> if (c_func(%body) & %easy & (s != void) & not(%body % If)) 
             (if (%end != "") printf("~A(~I);", %end, expression(%body, nil)) 
              else  printf("~I;",expression(%body, nil))) 
      else if (s != void)
            (new_block(),                            //<FXJ> ANSI C 
             define_variable(PRODUCER,s,"Result"), 
             breakline(), 
             statement(%body, "Result", {}), 
             if (%end != "") printf("~A(Result);~I", %end, close_block()))        //<FXJ>  ANSI C
      else (statement(%body, {}, {}),
             princ(%end)) ] 
  
// finds out if no allocation occurs (useful for an if branch)
// only useful when OPT.allocation is raised !
[c_safe(x:any) : boolean
   -> not(OPT.allocation & Optimize/c_status(x,nil)[NEW_ALLOC]) ]          // v3.3.3 !!!

// this is a cute trick   
claire/WrongMethod:any :: 1

// check the range & sort of the method through type inference. Produces the
// optimized code (placed in PRODUCER.body)
[check_sort(self:method) : class
 -> let s1 := self.range, b := PRODUCER.body,
        s2 := Optimize/ptype(c_type(b)), s := psort(s1) in
      (PRODUCER.body := c_strict_code(b, s),                            // includes C++ type checks
       //[5] ---- note: ~S's range was found to be ~S (vs. ~S) // self, s2, s1,
       if not(s2 <= s1)
         (//[2] ---- note: ~S's range was found to be ~S (vs. ~S) // self, s2, s1,
          if (WrongMethod = 0) (WrongMethod := b, error("You can look at WrongMethod")),
          if (compiler.safety < 2 |
                (compiler.safety < 4 & not(sort=(osort(s2), s))))
             PRODUCER.body := c_strict_code(c_check(c_code(b, any), c_code(s1, type)), s),  // OID compiling
          if not(sort=(osort(s2), s))
             (// [2] ---- WARNING: wrong sort [~S] inferred for ~S (was ~S) // osort(s2), self, s,
              if (s != void & (sort!(s2) = void | not(s inherit? sort!(s2))))
                  Cerror("[218] Sort error: Cannot compile ~S.",self))),
        let s3 := (s1 ^ s2) in
          (if (compiler.safety > 1 & osort(s3) = s)
              (PRODUCER.body := c_strict_check(PRODUCER.body, class!(s3)),
               // put(range,self,s3))),
               nil)),
        if (s1 % tuple)
           (//[3] --- note: ~S is a method with range <= tuple => use stack allocation // self,
            OPT.alloc_stack := true),                        // v3.2.26
        if (OPT.allocation & not(status!(self)[SAFE_GC]))
           (// OPT.protection := true,  NOT NECESSARILY -> a verifier <yc> 7/98
            if not(status!(self)[NEW_ALLOC])
               trace(4, "---- note: ~S may provoke an allocation \n", self))
        else (OPT.loop_gc := false,
              OPT.protection := false),
        psort(self.range))]


// prints a list of arguments with types
[typed_args_list(self:list) : any
 -> let prems := true in
       for x:Variable in self
         (if prems prems := false else printf(","),
          interface!(PRODUCER,sort(x)),
          ident(PRODUCER,x)) ]

// tells if a method needs debug instrumentation
[need_debug?(m:any) : boolean
 -> case m
      (method let p := m.selector in
                (m.module! % compiler.debug? &
                 domain!(m) != environment &
                 m.module! != claire & p != self_eval & p != execute &
                 p != eval_message & p != Core/push_debug & p != Core/pop_debug &
                 p != Core/tr_indent & p != Core/find_which & p != Core/matching? &
                 p != Core/vmatch?),
       any false) ]


// computes the inter-module dependence
get_dependents(m:method) : void
  -> (for p in Reader/dependents(m) Reader/PRdependent[m.selector] :add p)


[c_princ(self:function) : void -> c_princ(string!(self)) ]

// add the function for making function later
// decide where to generate the code of the compiled function
// the rule is: if 1st arg is of type a class c declared in that module m
//              or the range is such a class c, the code is produced in the
//              file c.java, otherwise it is generated in m.java
// assumes that the module file is in OPT.outfile
[set_outfile(self:lambda) : void
  ->  let m := module!(), cl:string := string!(m.name), p:port := OPT.outfile,
          %dom := (if self.vars self.vars[1].range else unknown) in
        (if known?(%dom)
          (if exists(c in OPT.objects | c % class & c = %dom)
              cl := c_string(PRODUCER,%dom.name),
           if (cl != string!(module!().name))       // v0.02 get rid of OPT.module!
              p := fopen(compiler.source /+ *fs* /+ cl /+ PRODUCER.extension,"a"),
              OPT.outfile := p),
         true) ]
          //    extfunc_stuff :add string!(%f),  v0.02 -> a changer !
          //    extfunc_stuff :add cl)) ]

// v3.2.06 - some properties may be extended
(put(open,set_outfile,4),
 put(open,inline_exp,4))


// end of file
