/***** CLAIRE Compilation of file c:\claire\v3.4\src\meta\inspect.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:36 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>

//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| inspect.cl                                                  |
//| Copyright (C) 1994 - 2013 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file object.cl: about()               |
//+-------------------------------------------------------------+
// --------------------------------------------------------------------
// this file contains the CLAIRE run-time tools: inspect, trace & debug
// --------------------------------------------------------------------
// *********************************************************************
// * Contents                                                          *
// *      Part 1: Inspection                                           *
// *      Part 2: Trace                                                *
// *      Part 3: Debugger                                             *
// *      Part 4: Stepper & Measure                                    *
// *      Part 5: Profiler                                             *
// *********************************************************************
// a useful global variable *last*
// v3.2.14 cleaner :-)
// v0.01 stop the ... !
// this is the interface with the system
//
// *********************************************************************
// *      Part 1: Inspection                                           *
// *********************************************************************
// this is the method that the user calls
//
/* The c++ function for: inspect(self:any) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  inspect_any(OID self)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  _Zread = _oid_(Kernel.emptySet);
      module * m0 = ClEnv->module_I;
      int  ix = 0;
      if (INHERIT(OWNER(self),Kernel._bag))
       { int  i = 1;
        int  g0104 = OBJECT(bag,self)->length;
        { OID gc_local;
          while ((i <= g0104))
          { princ_integer(i);
            princ_string(": ");
            print_any((*(OBJECT(bag,self)))[i]);
            princ_string("\n");
            ++i;
            } 
          } 
        } 
      else if (_Z_any1(self,Kernel._object) == CTRUE)
       { OID gc_local;
        ITERATE(rel);
        bag *rel_support;
        rel_support = OWNER(self)->slots;
        for (START(rel_support); NEXT(rel);)
        { GC_LOOP;
          { module * m = OBJECT(restriction,rel)->selector->name->module_I;
            ++ix;
            if ((m == m0) || 
                ((m == claire.it) || 
                  ((OBJECT(ClaireBoolean,Reader._starshowall_star->value)) == CTRUE)))
             { OID  val = GC_OID(get_slot(OBJECT(slot,rel),OBJECT(ClaireObject,self)));
              princ_integer(ix);
              princ_string(": ");
              print_any(_oid_(OBJECT(restriction,rel)->selector));
              princ_string(" = ");
              if (INHERIT(OWNER(val),Kernel._bag))
               { if (OBJECT(bag,val)->length < 10)
                 pretty_print_any(val);
                else { { OID  g0106UU;
                      { list * V_CL0107;{ list * i_bag = list::empty(Kernel.emptySet);
                          { int  i = 1;
                            int  g0105 = 9;
                            { OID gc_local;
                              while ((i <= g0105))
                              { i_bag->addFast((*(OBJECT(bag,val)))[i]);
                                ++i;
                                } 
                              } 
                            } 
                          V_CL0107 = GC_OBJECT(list,i_bag);
                          } 
                        
                        g0106UU=_oid_(V_CL0107);} 
                      pretty_print_any(g0106UU);
                      } 
                    pretty_print_any(_string_("..."));
                    } 
                  } 
              else pretty_print_any(val);
                princ_string("\n");
              } 
            } 
          GC_UNLOOP;} 
        } 
      else { pretty_print_any(self);
          princ_string("\n");
          } 
        InspectLoop(list::alloc(1,self));
      Result = _oid_(Reader.None);
      } 
    GC_UNBIND; return (Result);} 
  } 


// this is the inspect top_level
//
/* The c++ function for: inspect_loop(%read:any,old:list) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  inspect_loop_any(OID _Zread,list *old)
{ GC_BIND;
  { OID  self = (*(old))[1];
    if ((INHERIT(OWNER(_Zread),Language._Call)) && (OBJECT(Call,_Zread)->selector == Kernel.put))
     { int  n = (*(OBJECT(bag,(*Core.args)(_Zread))))[1];
      symbol * s = extract_symbol_any((*(OBJECT(bag,(*Core.args)(_Zread))))[2]);
      if (inherit_ask_class(OWNER(n),Kernel._integer) != CTRUE)
       close_exception(((general_error *) (*Core._general_error)(_string_("[128] ~S should be an integer"),
        _oid_(list::alloc(1,n)))));
      { OID  val = GC_OID(get_from_integer_any(self,n));
        (CLREAD(global_variable,new_class2(Core._global_variable,s),value) = val);
        inspect_any(val);
        old= GC_OBJECT(list,cons_any(val,old));
        } 
      } 
    else if (_Zread == _oid_(Reader.up))
     { if (old->length > 1)
       { old= GC_OBJECT(list,cdr_list(old));
        inspect_any((*(old))[1]);
        } 
      } 
    else if (INHERIT(OWNER(_Zread),Kernel._integer))
     { OID  val = GC_OID(get_from_integer_any(self,_Zread));
      old= GC_OBJECT(list,cons_any(val,old));
      inspect_any(val);
      } 
    else if (INHERIT(OWNER(_Zread),Kernel._thing))
     { old= GC_OBJECT(list,cons_any(_Zread,old));
      inspect_any(_Zread);
      } 
    else princ_string("=> given to inspector is wrong.\n");
      } 
  { OID Result = 0;
    Result = InspectLoop(old);
    GC_UNBIND; return (Result);} 
  } 


// get the information bound to the index
//
/* The c++ function for: get_from_integer(self:any,n:integer) [NEW_ALLOC+SLOT_UPDATE] */
OID  get_from_integer_any(OID self,int n)
{ { OID Result = 0;
    if (INHERIT(OWNER(self),Kernel._bag))
     { if ((n > 0) && 
          (n <= (*Kernel.length)(self)))
       Result = (*Kernel.nth)(self,
        n);
      else { princ_integer(n);
          princ_string(" in not a good index for ");
          print_any(self);
          princ_string(".\n");
          Result = self;
          } 
        } 
    else { list * l = OWNER(self)->slots;
        if ((n > 0) && 
            (n <= l->length))
         { OID v_rec;
          v_rec = (*(l))[n];
          PUSH(v_rec);
          v_rec = self;
          PUSH(v_rec);
          Result=Kernel.get->super(Kernel._slot,2);} 
        else { princ_integer(n);
            princ_string(" is not a good index for ");
            print_any(self);
            princ_string(".\n");
            Result = self;
            } 
          } 
      return (Result);} 
  } 


// *********************************************************************
// *      Part 2: Trace methods                                        *
// *********************************************************************
// instrument the code generated from the rules
/* The c++ function for: trace_on(self:any) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE+RETURN_ARG] */
OID  trace_on_any(OID self)
{ GC_BIND;
  if (INHERIT(OWNER(self),Kernel._property))
   { if (self == _oid_(Core.spy))
     { OID  m = GC_OID(_oid_(_at_property1(Core.spy,Kernel._void)));
      if (boolean_I_any(m) == CTRUE)
       store_object(ClEnv,
        18,
        Kernel._object,
        m,
        CFALSE);
      } 
    else if (self == _oid_(Reader.where))
     write_property(Reader.call_count,ClEnv,1);
    else (OBJECT(property,self)->trace_I = (5-ClEnv->verbose));
      } 
  else if (INHERIT(OWNER(self),Kernel._environment))
   (ClEnv->trace_I = 1);
  else if (INHERIT(OWNER(self),Kernel._module))
   { if (OBJECT(module,self)->status > 2)
     (OBJECT(module,self)->status = 4);
    { OID gc_local;
      ITERATE(m);
      bag *m_support;
      m_support = GC_OBJECT(list,OBJECT(module,self)->parts);
      for (START(m_support); NEXT(m);)
      trace_on_any(m);
      } 
    } 
  else if (Kernel._port == OWNER(self))
   (ClEnv->ctrace = EXPORT((ClairePort *),self));
  else if (Kernel._string == OWNER(self))
   (ClEnv->ctrace = fopen_string(string_v(self),"w"));
  else if (INHERIT(OWNER(self),Kernel._integer))
   (ClEnv->verbose = self);
  else close_exception(((general_error *) (*Core._general_error)(_string_("[129] trace not implemented on ~S\n"),
      _oid_(list::alloc(1,self)))));
    { OID Result = 0;
    Result = self;
    GC_UNBIND; return (Result);} 
  } 


/* The c++ function for: untrace(self:any) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE+RETURN_ARG] */
OID  untrace_any(OID self)
{ GC_BIND;
  if (INHERIT(OWNER(self),Kernel._property))
   { if (self == _oid_(Core.spy))
     (ClEnv->spy_I = NULL);
    else if (self == _oid_(Reader.where))
     write_property(Reader.call_count,ClEnv,-1);
    else (OBJECT(property,self)->trace_I = 0);
      } 
  else if (INHERIT(OWNER(self),Kernel._environment))
   (ClEnv->trace_I = 0);
  else if (INHERIT(OWNER(self),Kernel._module))
   { if (OBJECT(module,self)->status == 4)
     (OBJECT(module,self)->status = 3);
    { OID gc_local;
      ITERATE(m);
      bag *m_support;
      m_support = GC_OBJECT(list,OBJECT(module,self)->parts);
      for (START(m_support); NEXT(m);)
      untrace_any(m);
      } 
    } 
  else if (Kernel._port == OWNER(self))
   (ClEnv->ctrace = EXPORT((ClairePort *),Reader.STDOUT->value));
  else close_exception(((general_error *) (*Core._general_error)(_string_("[130] untrace not implemented on ~S\n"),
      _oid_(list::alloc(1,self)))));
    { OID Result = 0;
    Result = self;
    GC_UNBIND; return (Result);} 
  } 


// a filter to restrict the impact of spy
// we put the special value nil (emply list of demons => OK) to mark that spying
// should be waken up on properties from l
/* The c++ function for: spy(l:listargs) [SLOT_UPDATE] */
void  spy_listargs2_Reader(listargs *l)
{ { OID  m = _oid_(_at_property1(Core.spy,Kernel._void));
    if (boolean_I_any(m) == CTRUE)
     { store_object(ClEnv,
        18,
        Kernel._object,
        m,
        CFALSE);
      { ITERATE(g0108);
        bag *g0108_support;
        g0108_support = Kernel._property->descendents;
        for (START(g0108_support); NEXT(g0108);)
        { ClaireBoolean * g0109;
          { OID V_C;{ ITERATE(f);
              V_C= Kernel.cfalse;
              for (START(OBJECT(ClaireClass,g0108)->instances); NEXT(f);)
              if (l->memq(f) == CTRUE)
               (OBJECT(ClaireRelation,f)->if_write = Core.nil->value);
              } 
            
            g0109=OBJECT(ClaireBoolean,V_C);} 
          if (g0109 == CTRUE)
           { ;break;} 
          } 
        } 
      } 
    } 
  } 


// note: trace behavior for output statements defined in CLAIRE1 (self_eval)
/* The c++ function for: self_trace(self:Trace) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  self_trace_Trace(Trace *self)
{ GC_BIND;
  { OID Result = 0;
    { list * a = GC_OBJECT(list,self->args);
      if (a->length == 1)
       { OID  a1 = GC_OID(OPT_EVAL((*(a))[1]));
        if (ClEnv->trace_I == 0)
         (ClEnv->trace_I = 1);
        Result = trace_on_any(a1);
        } 
      else Result = self_eval_Trace(self);
        } 
    GC_UNBIND; return (Result);} 
  } 


// used to trace the trigger of a rule
//
/* The c++ function for: trace_rule(R:relation,s:string,x:any,y:any,u:any,v:any) [NEW_ALLOC] */
void  trace_rule_relation(ClaireRelation *R,char *s,OID x,OID y,OID u,OID v)
{ GC_BIND;
  if (5 <= (Kernel.if_write->trace_I+ClEnv->verbose))
   { OID  p = GC_OID(get_property(Kernel.ctrace,ClEnv));
    if (p != CNULL)
     p= GC_OID(ClAlloc->import(Kernel._port,(int *) use_as_output_port(EXPORT((ClairePort *),p))));
    princ_string("--- the rule ");
    princ_string(s);
    princ_string(" is triggered for (");
    print_any(u);
    princ_string(",");
    print_any(v);
    princ_string(") by an update ");
    print_any(_oid_(R));
    princ_string("(");
    print_any(x);
    princ_string(") ");
    princ_string(((multi_ask_any(_oid_(R)) == CTRUE) ?
      ":add" :
      ":=" ));
    princ_string(" ");
    print_any(y);
    princ_string(" \n");
    if (p != CNULL)
     use_as_output_port(EXPORT((ClairePort *),p));
    } 
  GC_UNBIND;} 


// stores a set of stopping values
/* The c++ function for: stop(p:property,l:listargs) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  stop_property(property *p,listargs *l)
{ if (get_table(Core.StopProperty,_oid_(p)) == CNULL)
   put_table(Core.StopProperty,_oid_(p),_oid_(list::alloc(1,_oid_(l))));
  else if (_oid_(l) == Core.nil->value)
   put_table(Core.StopProperty,_oid_(p),CNULL);
  else add_table(Core.StopProperty,_oid_(p),_oid_(list::alloc(1,_oid_(l))));
    return (Kernel.ctrue);} 


// ******************************************************************
// *    Part 3: The debugger interface                              *
// ******************************************************************
// toggle the debug mode
/* The c++ function for: debug(_CL_obj:void) [SLOT_UPDATE] */
void  debug_void()
{ if (ClEnv->debug_I != -1)
   { (ClEnv->debug_I = -1);
    princ_string("debugger removed\n");
    } 
  else { (ClEnv->debug_I = 0);
      (ClEnv->ctrace = EXPORT((ClairePort *),Reader.STDOUT->value));
      princ_string("debugger installed\n");
      } 
    } 


// this method is called when an error has occured. The value of index
// is recalled with last_index, so that the actual content of the stack is
// preserved.
/* The c++ function for: call_debug(_CL_obj:void) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  call_debug_void()
{ GC_BIND;
  { OID Result = 0;
    { int  top = ClEnv->last_debug;
      DebugLoop();
      (ClEnv->spy_I = NULL);
      (ClEnv->step_I = 0);
      (ClEnv->trace_I = 0);
      (ClEnv->base= ClEnv->last_index);
      (ClEnv->index= (ClEnv->last_index+1));
      (ClEnv->debug_I = top);
      print_exception_void();
      (Reader.reader->fromp = EXPORT((ClairePort *),Reader.STDIN->value));
      (Reader.reader->index = 0);
      { OID  c = GC_OID(Language.LastCall->value);
        if (c != CNULL)
         { ClaireHandler c_handle = ClaireHandler();
          if ERROR_IN 
          { if (nth_table1(Reader.DBline,c) > 0)
             { princ_string(" \n---- Last call ");
              print_any(c);
              princ_string(" in line ");
              princ_integer(nth_table1(Reader.DBline,c));
              princ_string("\n");
              } 
            ClEnv->cHandle--;} 
          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
          { c_handle.catchIt();;} 
          else PREVIOUS_HANDLER;} 
        else ;} 
      (Reader._starindex_star->value= 1);
      (Reader._starcurd_star->value= ClEnv->debug_I);
      Result = (Reader._starmaxd_star->value= ClEnv->debug_I);
      } 
    GC_UNBIND; return (Result);} 
  } 


// this method is called when an error has occured. The value of index
// is recalled with last_index, so that the actual content of the stack is
// preserved.
/* The c++ function for: breakpoint(_CL_obj:void) [NEW_ALLOC+SLOT_UPDATE] */
void  breakpoint_void()
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { int  top = ClEnv->debug_I;
    int  s = ClEnv->step_I;
    int  t = ClEnv->trace_I;
    (ClEnv->step_I = 0);
    (ClEnv->trace_I = 0);
    (Reader._starindex_star->value= 0);
    (Reader._starcurd_star->value= top);
    (Reader._starmaxd_star->value= top);
    if (((OBJECT(ClaireBoolean,(*Kernel._sup)(GC_OID(ClEnv->stack[top]),
        0))) == CTRUE) && 
        (ClEnv->debug_I > 0))
     { OID  j = GC_OID(ClEnv->stack[top]);
      OID  num_args = GC_OID((*Kernel._dash)(GC_OID(ClEnv->stack[GC_OID((*Core._plus)(j,
          2))]),
        1));
      int  start = ClEnv->stack[GC_OID((*Core._plus)(j,
        3))];
      OID  m = GC_OID(ClEnv->stack[GC_OID((*Core._plus)(j,
        1))]);
      princ_string("break in ");
      print_any(m);
      princ_string("(");
      print_any(GC_OID(ClEnv->stack[start]));
      { OID gc_local;
        ITERATE(i);
        bag *i_support;
        i_support = GC_OBJECT(bag,enumerate_any(GC_OID(_oid_(_dot_dot_integer((start+1),(*Core._plus)(start,
          num_args))))));
        for (START(i_support); NEXT(i);)
        { GC_LOOP;
          { princ_string(",");
            print_any(GC_OID(ClEnv->stack[i]));
            princ_string("");
            } 
          GC_UNLOOP;} 
        } 
      princ_string(") [q] >");
      { int  n = 1;
        int  m = 1;
        OID  c = GC_OID(read_string(GC_STRING(CommandLoopVoid())));
        { OID gc_local;
          while ((c != _oid_(Reader.q)))
          { GC_LOOP;
            OPT_EVAL(c);
            princ_string("break>");
            GC__OID(c = read_string(GC_STRING(CommandLoopVoid())), 1);
            GC_UNLOOP;} 
          } 
        } 
      } 
    (ClEnv->step_I = s);
    (ClEnv->trace_I = t);
    } 
  GC_UNBIND;} 


// the four keyword
/* The c++ function for: dn(x:integer) [NEW_ALLOC] */
void  dn_integer(int x)
{ GC_BIND;
  { OID gc_local;
    ClaireBoolean *v_while;
    v_while = (((OBJECT(ClaireBoolean,(*Kernel._sup)(GC_OID(ClEnv->stack[Reader._starcurd_star->value]),
      0))) == CTRUE) ? ((x > 0) ? CTRUE: CFALSE): CFALSE);
    
    while (v_while == CTRUE)
    { (Reader._starcurd_star->value= ClEnv->stack[Reader._starcurd_star->value]);
      (Reader._starindex_star->value= ((Reader._starindex_star->value)+1));
      x= (x-1);
      v_while = (((OBJECT(ClaireBoolean,(*Kernel._sup)(GC_OID(ClEnv->stack[Reader._starcurd_star->value]),
        0))) == CTRUE) ? ((x > 0) ? CTRUE: CFALSE): CFALSE);
      } 
    } 
  GC_UNBIND;} 


/* The c++ function for: up(x:integer) [NEW_ALLOC] */
void  up_integer(int x)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  if (x > 0)
   { list * indices = Kernel.nil;
    int  ind = Reader._starmaxd_star->value;
    { OID gc_local;
      while ((ind != Reader._starcurd_star->value))
      { GC_LOOP;
        GC__ANY(indices = cons_any(ind,indices), 1);
        ind= ClEnv->stack[ind];
        GC_UNLOOP;} 
      } 
    if (x > indices->length)
     { (Reader._starcurd_star->value= Reader._starmaxd_star->value);
      (Reader._starindex_star->value= 1);
      } 
    else { (Reader._starcurd_star->value= (*(indices))[x]);
        (Reader._starindex_star->value= ((Reader._starindex_star->value)-x));
        } 
      } 
  GC_UNBIND;} 


// top is the top position in this stack (the last entered message)
/* The c++ function for: where(x:integer) [NEW_ALLOC] */
void  where_integer(int x)
{ { int  j = Reader._starcurd_star->value;
    int  stack_level = 0;
    { while (((j > 0) && 
          ((x > 0) && 
            (ClEnv->debug_I > 0))))
      { print_debug_info_integer(j,stack_level,Reader._starindex_star->value);
        ++stack_level;
        x= (x-1);
        j= ClEnv->stack[j];
        } 
      } 
    } 
  } 


// note for interpretted methods .. they should be pushing their restriction
// on the stack vs. properties
/* The c++ function for: print_debug_info(iClaire/index:integer,stack_level:integer,cur_index:integer) [NEW_ALLOC] */
void  print_debug_info_integer(int index,int stack_level,int cur_index)
{ GC_BIND;
  { int  num_args = ((ClEnv->stack[(index+2)])-1);
    int  start = ClEnv->stack[(index+3)];
    OID  m = GC_OID(ClEnv->stack[(index+1)]);
    princ_string("debug[");
    princ_integer((cur_index+stack_level));
    princ_string("]>");
    { int  x = 1;
      int  g0111 = stack_level;
      { OID gc_local;
        while ((x <= g0111))
        { princ_string(">");
          ++x;
          } 
        } 
      } 
    princ_string(" ");
    print_any(m);
    princ_string("(");
    print_any(GC_OID(ClEnv->stack[start]));
    { int  i = (start+1);
      int  g0112 = (start+num_args);
      { OID gc_local;
        while ((i <= g0112))
        { GC_LOOP;
          princ_string(",");
          print_any(GC_OID(ClEnv->stack[i]));
          princ_string("");
          ++i;
          GC_UNLOOP;} 
        } 
      } 
    princ_string(")\n");
    } 
  GC_UNBIND;} 


// debug version of the debugger :-)
/* The c++ function for: Show(n:integer) [NEW_ALLOC] */
OID  Show_integer(int n)
{ GC_BIND;
  { OID Result = 0;
    { int  i = Reader._starcurd_star->value;
      { OID gc_local;
        Result= _oid_(CFALSE);
        while (((i > 0) && 
            (n > 0)))
        { GC_LOOP;
          { int  num_args = ((ClEnv->stack[(i+2)])-1);
            int  start = ClEnv->stack[(i+3)];
            princ_string("[");
            princ_integer(start);
            princ_string(" - ");
            princ_integer(i);
            princ_string("]: p = ");
            print_any(GC_OID(ClEnv->stack[(i+1)]));
            princ_string(", narg = ");
            print_any(num_args);
            princ_string(" \n");
            { int  j = 0;
              int  g0113 = num_args;
              { OID gc_local;
                while ((j <= g0113))
                { GC_LOOP;
                  princ_string("  [");
                  princ_integer((j+i));
                  princ_string("]:");
                  print_any(GC_OID(ClEnv->stack[(j+i)]));
                  princ_string(" \n");
                  ++j;
                  GC_UNLOOP;} 
                } 
              } 
            n= (n-1);
            i= ClEnv->stack[i];
            } 
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 


// go to next block
// top is the top position in this stack (the last entered message)
//
/* The c++ function for: block(x:integer) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
void  block_integer(int x)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { int  j = Reader._starcurd_star->value;
    int  stack_level = 0;
    { OID gc_local;
      while (((j > 0) && 
          ((x > 0) && 
            (ClEnv->debug_I > 0))))
      { GC_LOOP;
        { OID  nargs = GC_OID(ClEnv->stack[(j+2)]);
          int  start = ClEnv->stack[(j+3)];
          property * z = OBJECT(property,ClEnv->stack[(j+1)]);
          ClaireObject * m = GC_OBJECT(ClaireObject,find_which_list(z->definition,OWNER(ClEnv->stack[start]),start,(*Core._plus)(start,
            nargs)));
          if (Kernel._method == m->isa)
           { princ_string("debug[");
            princ_integer(((Reader._starindex_star->value)+stack_level));
            princ_string("] > ");
            print_any(_oid_(m));
            princ_string("(");
            if ((((CLREAD(method,m,formula) == (NULL)) ? CTRUE : CFALSE) != CTRUE) && 
                (INHERIT(CLREAD(method,m,formula)->isa,Core._lambda)))
             { int  n = 0;
              { OID gc_local;
                ITERATE(v);
                bag *v_support;
                v_support = GC_OBJECT(list,closure_build_lambda(CLREAD(method,m,formula)));
                for (START(v_support); NEXT(v);)
                { GC_LOOP;
                  { print_any(v);
                    princ_string(" = ");
                    print_any(GC_OID(ClEnv->stack[(start+n)]));
                    princ_string(", ");
                    ++n;
                    } 
                  GC_UNLOOP;} 
                } 
              } 
            else { princ_string("<compiled:");
                print_any(_oid_(CLREAD(restriction,m,module_I)));
                princ_string(">");
                } 
              princ_string(")\n");
            } 
          else { princ_string("debug[");
              princ_integer(((Reader._starindex_star->value)+stack_level));
              princ_string("] > ");
              print_any(_oid_(z));
              princ_string(" -> ");
              print_any(_oid_(m));
              princ_string("\n");
              } 
            } 
        ++stack_level;
        x= (x-1);
        j= ClEnv->stack[j];
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 


// computes the list of variables of a lambda, including everything
//
/* The c++ function for: closure_build(self:lambda) [BAG_UPDATE] */
list * closure_build_lambda(lambda *self)
{ GC_BIND;
  { list *Result ;
    { list * lvar = GC_OBJECT(list,make_list_integer(self->dimension,_oid_(Kernel.emptySet)));
      { OID gc_local;
        ITERATE(x);
        for (START(self->vars); NEXT(x);)
        ((*(lvar))[(((*Kernel.index)(x))+1)]=x);
        } 
      closure_build_any(self->body,lvar);
      Result = lvar;
      } 
    GC_UNBIND; return (Result);} 
  } 


// give to each lexical variable its right position in the stack
// answer with the number of lexical variable
//
/* The c++ function for: closure_build(self:any,lvar:list) [BAG_UPDATE] */
void  closure_build_any(OID self,list *lvar)
{ if (INHERIT(OWNER(self),Language._Variable))
   ((*(lvar))[(OBJECT(Variable,self)->index+1)]=self);
  else if (INHERIT(OWNER(self),Language._Instruction))
   { ITERATE(s);
    for (START(OBJECT(ClaireObject,self)->isa->slots); NEXT(s);)
    closure_build_any(get_slot(OBJECT(slot,s),OBJECT(ClaireObject,self)),lvar);
    } 
  else if (INHERIT(OWNER(self),Kernel._bag))
   { ITERATE(x);
    for (START(OBJECT(bag,self)); NEXT(x);)
    closure_build_any(x,lvar);
    } 
  else ;} 


// ******************************************************************
// *    Part 4: Stepper, Measure & mem                              *
// ******************************************************************
// the stepper interface is quite simple and could be improved
//
/* The c++ function for: Core/call_step(pr:property) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
void  call_step_property_Reader(property *pr)
{ princ_string(") : [(i)n,(o)ut,e(x)it,(t)race,(b)reakpoint]\n");
  { int  m = 1;
    ClaireChar * c = char_I_integer(StepLoop());
    int  n = ClEnv->step_I;
    if (((char) c->ascii) == 'i')
     (ClEnv->step_I = (n+1));
    else if (((char) c->ascii) == 'o')
     { if (n > 1)
       (ClEnv->step_I = (n-1));
      } 
    else if (((char) c->ascii) == 'x')
     close_exception(((general_error *) (*Core._general_error)(_string_("exit stepper"),
      _oid_(Kernel.nil))));
    else if (((char) c->ascii) == 't')
     trace_on_any(_oid_(pr));
    else if (((char) c->ascii) == 'b')
     breakpoint_void();
    } 
  } 


// interface
// step => trace
//
/* The c++ function for: step(x:any) [SLOT_UPDATE] */
void  step_any(OID x)
{ if (ClEnv->trace_I == 0)
   (ClEnv->trace_I = 1);
  if (INHERIT(OWNER(x),Kernel._property))
   (OBJECT(property,x)->trace_I = (OBJECT(property,x)->trace_I+1000));
  else if (INHERIT(OWNER(x),Kernel._integer))
   { (ClEnv->count_trigger = _oid_(Reader.step));
    (ClEnv->count_level = x);
    } 
  else if (INHERIT(OWNER(x),Kernel._environment))
   { if (ClEnv->step_I == 0)
     (ClEnv->step_I = ClEnv->trace_I);
    else (ClEnv->step_I = 0);
      } 
  else ;} 


// New in CLAIRE 3.4 - measure objects can be stored on a file and loaded later on
// a measure is a float value counter that stores the sum & sum of squares, to 
// number of experiments
// simple methods add, mean, stdev
/* The c++ function for: close(x:measure) [SAFE_RESULT] */
measure * close_measure(measure *x)
{ (x->m_index = length_bag(Reader._measure->instances));
  return (x);} 


/* The c++ function for: add(g0117:measure,g0118:any) [NEW_ALLOC+SAFE_RESULT] */
measure * add_measure_(measure *g0117,OID g0118)
{ return add_measure(g0117,float_v(g0118));} 


/* The c++ function for: add(x:measure,f:float) [NEW_ALLOC+SAFE_RESULT] */
measure * add_measure(measure *x,double f)
{ (x->num_value = (x->num_value+1.0));
  (x->sum_value = (x->sum_value+f));
  (x->sum_square = (x->sum_square+(f*f)));
  return (x);} 


/* The c++ function for: mean(g0119:measure) [NEW_ALLOC] */
OID  mean_measure_(measure *g0119)
{ return _float_(mean_measure(g0119));} 


/* The c++ function for: mean(x:measure) [NEW_ALLOC] */
double  mean_measure(measure *x)
{ GC_BIND;
  { double Result =0.0;
    Result = ((x->num_value == 0.0) ?
      0.0 :
      (x->sum_value/x->num_value) );
    GC_UNBIND; return (Result);} 
  } 


/* The c++ function for: stdev(g0120:measure) [NEW_ALLOC] */
OID  stdev_measure_(measure *g0120)
{ return _float_(stdev_measure(g0120));} 


/* The c++ function for: stdev(x:measure) [NEW_ALLOC] */
double  stdev_measure(measure *x)
{ { double Result =0.0;
    { double  y = ((x->sum_square/x->num_value)-_exp_float((x->sum_value/x->num_value),2.0));
      Result = ((y > 0.0) ?
        sqrt(y) :
        0.0 );
      } 
    return (Result);} 
  } 


/* The c++ function for: stdev%(g0121:measure) [NEW_ALLOC] */
OID  stdev_Z_measure_(measure *g0121)
{ return _float_(stdev_Z_measure(g0121));} 


/* The c++ function for: stdev%(x:measure) [NEW_ALLOC] */
double  stdev_Z_measure(measure *x)
{ return ((stdev_measure(x)/mean_measure(x)));} 


/* The c++ function for: reset(x:measure) [NEW_ALLOC] */
void  reset_measure(measure *x)
{ (x->sum_square = 0.0);
  (x->num_value = 0.0);
  (x->sum_value = 0.0);
  } 


/* The c++ function for: self_print(m:measure) [NEW_ALLOC] */
void  self_print_measure_Reader(measure *m)
{ printFDigit_float(mean_measure(m),2);
  princ_string("[");
  printFDigit_float(m->num_value,0);
  princ_string("]");
  } 


// two simple methods to store and retreive measures
//   logMeasure(s:string)  : creates a file
//   load(s:string)        : loads the files, that containts addLog(i,s,ss,n) line
/* The c++ function for: logMeasure(s:string) [0] */
void  logMeasure_string(char *s)
{ { ClairePort * p = fopen_string(s,"w");
    int  n = size_class(Reader._measure);
    use_as_output_port(p);
    princ_string("// log file produced on ");
    princ_string(date_I_integer(1));
    princ_string("");
    { ITERATE(g0122);
      bag *g0122_support;
      g0122_support = Reader._measure->descendents;
      for (START(g0122_support); NEXT(g0122);)
      { ClaireBoolean * g0123;
        { OID V_C;{ ITERATE(m);
            V_C= Kernel.cfalse;
            for (START(OBJECT(ClaireClass,g0122)->instances); NEXT(m);)
            { princ_string("(addLog(");
              princ_integer(OBJECT(measure,m)->m_index);
              princ_string(",");
              princ_float(OBJECT(measure,m)->sum_value);
              princ_string(",");
              princ_float(OBJECT(measure,m)->sum_square);
              princ_string(",");
              princ_float(OBJECT(measure,m)->num_value);
              princ_string(",");
              princ_integer(n);
              princ_string("))\n");
              } 
            } 
          
          g0123=OBJECT(ClaireBoolean,V_C);} 
        if (g0123 == CTRUE)
         { ;break;} 
        } 
      } 
    fclose_port(p);
    } 
  } 


// adds a set of measures to a measure object (represented by its index)
/* The c++ function for: addLog(g0127:integer,g0128:any,g0129:any,g0130:any,g0131:integer) [0] */
void  addLog_integer_(int g0127,OID g0128,OID g0129,OID g0130,int g0131)
{ addLog_integer(g0127,float_v(g0128),float_v(g0129),float_v(g0130),g0131);} 


/* The c++ function for: addLog(i:integer,x:float,y:float,n:float,s:integer) [0] */
void  addLog_integer(int i,double x,double y,double n,int s)
{ if (size_class(Reader._measure) == s)
   { OID  m = (*(Reader._measure->instances))[i];
    (OBJECT(measure,m)->sum_value = (OBJECT(measure,m)->sum_value+x));
    (OBJECT(measure,m)->sum_square = (OBJECT(measure,m)->sum_square+y));
    (OBJECT(measure,m)->num_value = (OBJECT(measure,m)->num_value+n));
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_("logMeasure not compatible with current set (~A vs ~A)"),
      _oid_(list::alloc(2,size_class(Reader._measure),s)))));
    } 


// memory usage statistics for a class (useful for debug)
/* The c++ function for: mem(c:class) [NEW_ALLOC] */
int  mem_class(ClaireClass *c)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { int Result = 0;
    { int  n = 0;
      { OID gc_local;
        ITERATE(x);
        for (START(c->instances); NEXT(x);)
        { GC_LOOP;
          { n= (*Core._plus)(n,
              GC_OID(slot_get_object(OBJECT(ClaireObject,x),0,Kernel._integer)));
            { OID gc_local;
              ITERATE(sl);
              for (START(c->slots); NEXT(sl);)
              { GC_LOOP;
                { ClaireType * rs = OBJECT(restriction,sl)->range;
                  if (rs == Kernel._float)
                   n= (n+5);
                  else if (rs == Kernel._string)
                   { OID  st = GC_OID(get_slot(OBJECT(slot,sl),OBJECT(ClaireObject,x)));
                    if (st != CNULL)
                     n= (n+min_integer(5,(strlen(string_v(st))/2)));
                    else ;} 
                  else if (_inf_equal_type(rs,Kernel._bag) == CTRUE)
                   { OID  l = GC_OID(get_slot(OBJECT(slot,sl),OBJECT(ClaireObject,x)));
                    if (l != CNULL)
                     n= (*Core._plus)(n,
                      GC_OID((*(OBJECT(bag,l)))[0]));
                    else ;} 
                  } 
                GC_UNLOOP;} 
              } 
            } 
          GC_UNLOOP;} 
        } 
      Result = n;
      } 
    GC_UNBIND; return (Result);} 
  } 


// *********************************************************************
// *      Part 5: Profiler                                             *
// *********************************************************************
// we use a counter object for the 5 interesting values  and
// we use the reified slot to store the counter (thus no profiling on reified)
// start time (1st entry)
// get & create if needed a PRcounter
/* The c++ function for: PRget(p:property) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
PRcount * PRget_property(property *p)
{ GC_BIND;
  { PRcount *Result ;
    { ClaireObject *V_CC ;
      { ClaireObject * x = GC_OBJECT(ClaireObject,p->reified);
        if (OWNER(_oid_(x)) == Reader._PRcount)
         V_CC = x;
        else if (x == CTRUE)
         close_exception(((general_error *) (*Core._general_error)(_string_("[131] Cannot profile a reified property ~S"),
          _oid_(list::alloc(1,_oid_(p))))));
        else { { PRcount * _CL_obj = ((PRcount *) GC_OBJECT(PRcount,new_object_class(Reader._PRcount)));
              add_I_property(Kernel.instances,Reader._PRcount,11,_oid_(_CL_obj));
              x = _CL_obj;
              } 
            (p->reified = x);
            V_CC = x;
            } 
          } 
      Result= (PRcount *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 


// get & create if needed a PRcounter
/* The c++ function for: PRlook(p:property) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  PRlook_property2(property *p)
{ return (show_any(_oid_(PRget_property(p))));} 


// show the profiler statistics on one property
/* The c++ function for: PRshow(p:property) [NEW_ALLOC] */
void  PRshow_property(property *p)
{ GC_BIND;
  { ClaireObject * x = GC_OBJECT(ClaireObject,p->reified);
    if (INHERIT(x->isa,Reader._PRcount))
     { print_any(_oid_(p));
      princ_string(": ");
      princ_integer(CLREAD(PRcount,x,rnum));
      princ_string(" calls -> ");
      princ_integer(CLREAD(PRcount,x,rtime));
      princ_string(" clock tics\n");
      } 
    } 
  GC_UNBIND;} 


// elapsed time
/* The c++ function for: PRtime(p:property) [0] */
int  PRtime_property(property *p)
{ { int Result = 0;
    { ClaireObject * x = p->reified;
      Result = ((INHERIT(x->isa,Reader._PRcount)) ?
        CLREAD(PRcount,x,rtime) :
        0 );
      } 
    return (Result);} 
  } 


/* The c++ function for: PRcounter(p:property) [0] */
int  PRcounter_property(property *p)
{ { int Result = 0;
    { ClaireObject * x = p->reified;
      Result = ((INHERIT(x->isa,Reader._PRcount)) ?
        CLREAD(PRcount,x,rnum) :
        0 );
      } 
    return (Result);} 
  } 


// show the profiler statistics on the 10 most important properties
/* The c++ function for: PRshow(_CL_obj:void) [NEW_ALLOC+BAG_UPDATE] */
void  PRshow_void()
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list * l = list::empty(Kernel._property);
    { OID gc_local;
      ITERATE(g0132);
      bag *g0132_support;
      g0132_support = Kernel._property->descendents;
      for (START(g0132_support); NEXT(g0132);)
      { GC_LOOP;
        { ClaireBoolean * g0133;
          { OID V_C;{ OID gc_local;
              ITERATE(p);
              V_C= Kernel.cfalse;
              for (START(OBJECT(ClaireClass,g0132)->instances); NEXT(p);)
              { GC_LOOP;
                { ClaireBoolean * g0135I;
                  { OID  g0136UU;
                    { int  i = 1;
                      int  g0134 = min_integer(10,l->length);
                      { OID gc_local;
                        g0136UU= _oid_(CFALSE);
                        while ((i <= g0134))
                        { { ClaireBoolean * g0137I;
                            if ((PRtime_property(OBJECT(property,p)) > PRtime_property(OBJECT(property,(*(l))[i]))) || 
                                ((PRtime_property(OBJECT(property,p)) == PRtime_property(OBJECT(property,(*(l))[i]))) && 
                                    (PRcounter_property(OBJECT(property,p)) > PRcounter_property(OBJECT(property,(*(l))[i])))))
                             { l= add_at_list(l,i,p);
                              g0137I = CTRUE;
                              } 
                            else g0137I = CFALSE;
                              
                            if (g0137I == CTRUE) { g0136UU = Kernel.ctrue;
                                break;} 
                              } 
                          ++i;
                          } 
                        } 
                      } 
                    g0135I = boolean_I_any(g0136UU);
                    } 
                  
                  if (g0135I == CTRUE) ;else if (l->length < 10)
                   GC__ANY(l = l->addFast(p), 1);
                  } 
                GC_UNLOOP;} 
              } 
            
            g0133=OBJECT(ClaireBoolean,V_C);} 
          if (g0133 == CTRUE)
           { ;break;} 
          } 
        GC_UNLOOP;} 
      } 
    shrink_list(l,10);
    { OID gc_local;
      ITERATE(p);
      for (START(l); NEXT(p);)
      { GC_LOOP;
        if (PRcounter_property(OBJECT(property,p)) > 0)
         { princ_string("-----------------------------------\n");
          PRshow_property(OBJECT(property,p));
          { OID gc_local;
            ITERATE(p2);
            bag *p2_support;
            p2_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Reader.PRdependent,p)));
            for (START(p2_support); NEXT(p2);)
            if (PRtime_property(OBJECT(property,p2)) > 0)
             { princ_string("   * ");
              PRshow_property(OBJECT(property,p2));
              princ_string("");
              } 
            } 
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 


// reuse from lexical_build in pretty.cl
// returns the list of properties that are used by a method
/* The c++ function for: dependents(self:method) [NEW_ALLOC] */
set * dependents_method(method *self)
{ GC_BIND;
  { set *Result ;
    { set * p_out = set::empty(Kernel._property);
      { OID gc_local;
        ITERATE(p);
        bag *p_support;
        p_support = GC_OBJECT(bag,enumerate_any(GC_OID((*Reader.dependents)(self->formula->body))));
        for (START(p_support); NEXT(p);)
        { ClaireBoolean * g0138I;
          { OID  g0139UU;
            { OID gc_local;
              ITERATE(r);
              g0139UU= Kernel.cfalse;
              for (START(OBJECT(property,p)->restrictions); NEXT(r);)
              if (Kernel._method == OBJECT(ClaireObject,r)->isa)
               { g0139UU = Kernel.ctrue;
                break;} 
              } 
            g0138I = boolean_I_any(g0139UU);
            } 
          
          if (g0138I == CTRUE) p_out->addFast(p);
            } 
        } 
      Result = GC_OBJECT(set,p_out);
      } 
    GC_UNBIND; return (Result);} 
  } 


// this is really cute ....   v3.2.58: fix typing
/* The c++ function for: dependents(self:any) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
OID  dependents_any(OID self)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    if (INHERIT(OWNER(self),Language._Call))
     Result = (*Kernel.add)(GC_OID(dependents_any(GC_OID(_oid_(OBJECT(Call,self)->args)))),
      _oid_(OBJECT(Call,self)->selector));
    else if (INHERIT(OWNER(self),Language._Instruction))
     { set * s = set::empty(Kernel._property);
      { OID gc_local;
        ITERATE(sl);
        for (START(OBJECT(ClaireObject,self)->isa->slots); NEXT(sl);)
        { GC_LOOP;
          GC__ANY(s = ((set *) U_type(s,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Reader.dependents)(GC_OID(get_slot(OBJECT(slot,sl),OBJECT(ClaireObject,self)))))))), 1);
          GC_UNLOOP;} 
        } 
      Result = _oid_(s);
      } 
    else if (INHERIT(OWNER(self),Kernel._bag))
     { set * s = GC_OBJECT(set,set::empty(Kernel._property));
      { OID gc_local;
        ITERATE(x);
        for (START(OBJECT(bag,self)); NEXT(x);)
        { GC_LOOP;
          GC__ANY(s = ((set *) U_type(s,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Reader.dependents)(x))))), 1);
          GC_UNLOOP;} 
        } 
      Result = _oid_(s);
      } 
    else if (INHERIT(OWNER(self),Kernel._property))
     Result = _oid_(set::alloc(Kernel._property,1,self));
    else Result = _oid_(set::empty(Kernel._property));
      GC_UNBIND; return (Result);} 
  } 


// used to set up the dependence
/* The c++ function for: PRdepends(p:property,p2:property) [NEW_ALLOC+BAG_UPDATE+SLOT_UPDATE] */
void  PRdepends_property(property *p,property *p2)
{ add_table(Reader.PRdependent,_oid_(p),_oid_(p2));
  ;} 


// end of file