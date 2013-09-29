/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\gstat.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:50 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
list * unfold_args_list(list *v9222)
{ GC_BIND;
  { list *Result ;
    { list * v10625;
      { { list * v6672 = list::empty(Kernel.emptySet);
          { int  v9217 = 1;
            int  v6663 = v9222->length;
            { OID gc_local;
              while ((v9217 <= v6663))
              { if (c_func_any((*(v9222))[v9217]) != CTRUE)
                 v6672->addFast(v9217);
                ++v9217;
                } 
              } 
            } 
          v10625 = GC_OBJECT(list,v6672);
          } 
        GC_OBJECT(list,v10625);} 
      { bag *v_list; OID v_val;
        OID v9217,CLcount;
        v_list = v10625;
         Result = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v9217 = (*(v_list))[CLcount];
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = Variable_I_symbol(append_symbol(gensym_void(),_string_("UU")),0,GC_OBJECT(ClaireType,c_type_sort_any((*(v9222))[v9217]))));
            (v2072->value = (*(v9222))[v9217]);
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v_val = _oid_(v2072);
            } 
          
          (*((list *) Result))[CLcount] = v_val;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_sort_any(OID v9232)
{ { ClaireType *Result ;
    { ClaireClass * v9233 = OBJECT(ClaireClass,(*Optimize.c_sort)(v9232));
      ClaireClass * v9231 = stupid_t_any1(v9232);
      Result = ((v9233 == Kernel._void) ?
        osort_any((*Optimize.c_type)(v9232)) :
        ((boolean_I_any(sort_equal_class(osort_any(_oid_(v9231)),v9233)) == CTRUE) ?
          v9231 :
          v9233 ) );
      } 
    return (Result);} 
  } 

OID  unfold_arg_list(list *v9222,list *v7392,OID v9232)
{ { OID Result = 0;
    { int  v9217 = 1;
      int  v9218 = 0;
      int  v9221 = v9222->length;
      { ClaireBoolean * g0030I;
        { OID v15730;{ v15730= _oid_(CFALSE);
            while ((v9217 <= v9221))
            { if (c_func_any((*(v9222))[v9217]) != CTRUE)
               { ++v9218;
                if (equal((*(v9222))[v9217],v9232) == CTRUE)
                 { v15730 = Kernel.ctrue;
                  break;} 
                } 
              else if (equal((*(v9222))[v9217],v9232) == CTRUE)
               { v15730 = Kernel.cfalse;
                break;} 
              ++v9217;
              } 
            } 
          
          g0030I=OBJECT(ClaireBoolean,v15730);} 
        
        if (g0030I == CTRUE) Result = (*Language.var)((*(v7392))[v9218]);
          else Result = (*(v9222))[v9217];
        } 
      } 
    return (Result);} 
  } 

void  unfold_use_list(list *v12673,OID v9232,OID v9233,OID v7180)
{ { int  v9223 = v12673->length;
    int  v9236 = ClEnv->verbose;
    (ClEnv->verbose = 0);
    if (boolean_I_any(_oid_(v12673)) != CTRUE)
     close_exception(((general_error *) (*Core._general_error)(_string_("[internal] design bug c_func(~S) should be true"),
      _oid_(list::alloc(1,v9232)))));
    if (equal((*Optimize.c_type)(v9232),_oid_(Kernel.emptySet)) == CTRUE)
     v9233= _oid_(Kernel._void);
    { int  v9217 = 1;
      int  v6685 = (v9223-1);
      { while ((v9217 <= v6685))
        { write_property(Kernel.arg,OBJECT(ClaireObject,(*(v12673))[v9217]),(*(v12673))[(v9217+1)]);
          ++v9217;
          } 
        } 
      } 
    (OBJECT(Let,(*(v12673))[v9223])->arg = v9232);
    (ClEnv->verbose = v9236);
    self_statement_Let(OBJECT(Let,(*(v12673))[1]),v9233,v7180);
    } 
  } 

void  statement_any(OID v9396,OID v9233,OID v7180)
{ GC_BIND;
  { ClaireBoolean * v9210 = Optimize.OPT->alloc_stack;
    if ((((INHERIT(OWNER(v9396),Language._Tuple)) || 
        (INHERIT(OWNER(v9396),Language._Do))) ? CTRUE : ((INHERIT(OWNER(v9396),Language._Let)) ? CTRUE : CFALSE)) != CTRUE)
     (Optimize.OPT->alloc_stack = CFALSE);
    if (c_func_any(v9396) == CTRUE)
     { { ClaireBoolean * g0032I;
        { ClaireBoolean *v_and;
          { v_and = ((Kernel._string == OWNER(v9233)) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0032I =CFALSE; 
            else { { OID  v6399;
                { OID  v7360;
                  { if (INHERIT(OWNER(v9396),Optimize._to_CL))
                     v7360 = OBJECT(Compile_to_CL,v9396)->arg;
                    else v7360 = v9396;
                      GC_OID(v7360);} 
                  v6399 = (*Optimize.c_sort)(v7360);
                  } 
                v_and = ((v6399 != _oid_(Kernel._void)) ? CTRUE : CFALSE);
                } 
              if (v_and == CFALSE) g0032I =CFALSE; 
              else g0032I = CTRUE;} 
            } 
          } 
        
        if (g0032I == CTRUE) { (*Kernel.c_princ)(v9233);
            princ_string(" = ");
            if (bool_exp_ask_any(v9396) == CTRUE)
             (*Generate.bool_exp_I)(Generate.PRODUCER->value,
              v9396,
              v7180);
            else (*Generate.expression)(v9396,
                v7180);
              princ_string(";");
            breakline_void();
            princ_string("");
            } 
          else if (INHERIT(OWNER(v9396),Language._If))
         (*Generate.self_statement)(v9396,
          v9233,
          v7180);
        else if (INHERIT(OWNER(v9396),Reader._delimiter))
         close_exception(((general_error *) (*Core._general_error)(_string_("[201] Loose delimiter in program: ~S"),
          _oid_(list::alloc(1,v9396)))));
        else (*Generate.stat_exp)(Generate.PRODUCER->value,
            v9396,
            v7180);
          } 
      } 
    else if ((INHERIT(OWNER(v9396),Language._Call_method)) && 
        (((*Kernel.arg)(v9396) == Generate._starclose_exception_star->value) && 
          (c_func_any(GC_OID((*(OBJECT(bag,(*Core.args)(v9396))))[1])) == CTRUE)))
     { (*Generate.expression)(v9396,
        v7180);
      princ_string(";");
      breakline_void();
      princ_string("");
      } 
    else (*Generate.self_statement)(v9396,
        v9233,
        v7180);
      (Optimize.OPT->alloc_stack = v9210);
    } 
  GC_UNBIND;} 

void  self_statement_Construct(Construct *v9396,OID v9233,OID v7180)
{ (*Generate.stat_construct)(Generate.PRODUCER->value,
    _oid_(v9396),
    v9233,
    v7180);
  } 

void  self_statement_If(If *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (c_func_any(GC_OID(v9396->test)) == CTRUE)
   { princ_string("if ");
    (*Optimize.bool_exp)(GC_OID(v9396->test),
      Kernel.ctrue,
      v7180);
    princ_string("");
    breakline_void();
    princ_string(" ");
    if (INHERIT(OWNER(v9396->arg),Language._If))
     new_block_void();
    statement_any(GC_OID(v9396->arg),v9233,v7180);
    if (INHERIT(OWNER(v9396->arg),Language._If))
     close_block_void();
    if ((Kernel._string == OWNER(v9233)) || 
        (boolean_I_any(v9396->other) == CTRUE))
     { OID  v7765 = GC_OID(v9396->other);
      if (inherit_ask_class(OWNER(v7765),Language._If) != CTRUE)
       (Optimize.OPT->level = (Optimize.OPT->level+1));
      princ_string("else ");
      statement_any(v7765,v9233,v7180);
      princ_string("");
      if (inherit_ask_class(OWNER(v7765),Language._If) != CTRUE)
       (Optimize.OPT->level = (Optimize.OPT->level-1));
      } 
    } 
  else { OID  v9236 = GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        _oid_(append_symbol(gensym_void(),_string_("I")))));
      new_block_void();
      interface_I_class(Kernel._boolean);
      princ_string(" ");
      princ_string(string_v(v9236));
      princ_string(";");
      breakline_void();
      statement_any(GC_OID(v9396->test),v9236,v7180);
      princ_string("");
      breakline_void();
      (Optimize.OPT->level = (Optimize.OPT->level+1));
      princ_string("if (");
      princ_string(string_v(v9236));
      princ_string(" == ");
      (*Generate.produce)(Generate.PRODUCER->value,
        Kernel.ctrue);
      princ_string(") ");
      statement_any(GC_OID(v9396->arg),v9233,v7180);
      princ_string("");
      (Optimize.OPT->level = (Optimize.OPT->level-1));
      if ((Kernel._string == OWNER(v9233)) || 
          (boolean_I_any(v9396->other) == CTRUE))
       { princ_string("else ");
        statement_any(GC_OID(v9396->other),v9233,v7180);
        princ_string("");
        } 
      close_block_void();
      } 
    GC_UNBIND;} 

void  self_statement_Do(Do *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (v9396->args->length == 1)
   statement_any(GC_OID((*(v9396->args))[1]),v9233,v7180);
  else { list * v9222 = GC_OBJECT(list,v9396->args);
      int  v9221 = v9222->length;
      ClaireBoolean * v9210 = Optimize.OPT->alloc_stack;
      int  v9223 = 0;
      (Optimize.OPT->alloc_stack = CFALSE);
      new_block_void();
      inner_statement_any(_oid_(v9396),v9233,v7180);
      close_block_void();
      } 
    GC_UNBIND;} 

void  inner_statement_any(OID v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (INHERIT(OWNER(v9396),Language._Do))
   { list * v9222 = GC_OBJECT(list,OBJECT(Do,v9396)->args);
    int  v9221 = v9222->length;
    ClaireBoolean * v9210 = Optimize.OPT->alloc_stack;
    int  v9223 = 0;
    (Optimize.OPT->alloc_stack = CFALSE);
    { ITERATE(v9232);
      for (START(v9222); NEXT(v9232);)
      { ++v9223;
        if (v9223 == v9221)
         { (Optimize.OPT->alloc_stack = v9210);
          inner_statement_any(v9232,v9233,v7180);
          } 
        else if (boolean_I_any(v9232) == CTRUE)
         inner_statement_any(v9232,_oid_(Kernel.emptySet),v7180);
        } 
      } 
    } 
  else statement_any(v9396,v9233,v7180);
    GC_UNBIND;} 

void  self_statement_Let(Let *v9396,OID v9233,OID v7180)
{ (*Generate.stat_let)(Generate.PRODUCER->value,
    _oid_(v9396),
    v9233,
    v7180);
  } 

void  self_statement_And(And *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { char * v9236 = GC_STRING(check_var_string("v_and",v9233,v7180));
    new_block_void();
    interface_I_class(Kernel._boolean);
    princ_string(v9236);
    princ_string(";");
    breakline_void();
    { OID gc_local;
      ITERATE(v9232);
      bag *v9232_support;
      v9232_support = GC_OBJECT(list,v9396->args);
      for (START(v9232_support); NEXT(v9232);)
      { new_block_void();
        statement_any(v9232,_string_(v9236),v7180);
        princ_string("if (");
        princ_string(v9236);
        princ_string(" == ");
        (*Generate.produce)(Generate.PRODUCER->value,
          Kernel.cfalse);
        princ_string(") ");
        if (Kernel._string == OWNER(v9233))
         { c_princ_string(string_v(v9233));
          princ_string(" =");
          } 
        expression_boolean(CFALSE,v7180);
        princ_string("; ");
        breakline_void();
        princ_string("else ");
        } 
      } 
    if (Kernel._string == OWNER(v9233))
     { c_princ_string(string_v(v9233));
      princ_string(" = ");
      expression_boolean(CTRUE,v7180);
      princ_string(";");
      } 
    else { expression_boolean(CTRUE,v7180);
        princ_string(";");
        } 
      { OID gc_local;
      ITERATE(v9232);
      bag *v9232_support;
      v9232_support = GC_OBJECT(list,v9396->args);
      for (START(v9232_support); NEXT(v9232);)
      close_block_void();
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Or(Or *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { char * v9236 = GC_STRING(check_var_string("v_or",v9233,v7180));
    new_block_void();
    interface_I_class(Kernel._boolean);
    princ_string(v9236);
    princ_string(";");
    breakline_void();
    { OID gc_local;
      ITERATE(v9232);
      bag *v9232_support;
      v9232_support = GC_OBJECT(list,v9396->args);
      for (START(v9232_support); NEXT(v9232);)
      { new_block_void();
        statement_any(v9232,_string_(v9236),v7180);
        princ_string("if (");
        princ_string(v9236);
        princ_string(" == ");
        (*Generate.produce)(Generate.PRODUCER->value,
          Kernel.ctrue);
        princ_string(") ");
        if (Kernel._string == OWNER(v9233))
         { c_princ_string(string_v(v9233));
          princ_string(" =");
          } 
        expression_boolean(CTRUE,v7180);
        princ_string("; ");
        breakline_void();
        princ_string("else ");
        } 
      } 
    if (Kernel._string == OWNER(v9233))
     { c_princ_string(string_v(v9233));
      princ_string(" = ");
      expression_boolean(CFALSE,v7180);
      princ_string(";");
      } 
    else { expression_boolean(CFALSE,v7180);
        princ_string(";");
        } 
      { OID gc_local;
      ITERATE(v9232);
      bag *v9232_support;
      v9232_support = GC_OBJECT(list,v9396->args);
      for (START(v9232_support); NEXT(v9232);)
      close_block_void();
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_While(While *v9396,OID v9233,OID v7180)
{ (*Generate.stat_while)(Generate.PRODUCER->value,
    _oid_(v9396),
    v9233,
    v7180);
  } 

void  self_statement_Assign(Assign *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { OID  v9236 = GC_OID(v9396->var);
    OID  v9232 = GC_OID(v9396->arg);
    ClaireBoolean * v5206 = ((boolean_I_any(v7180) == CTRUE) ? ((Optimize.OPT->loop_gc == CTRUE) ? ((inner2outer_ask_any(v9232) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
    OID  v9235;
    { if ((v5206 == CTRUE) && 
          (INHERIT(OWNER(v9232),Optimize._to_protect)))
       v9235 = (*Kernel.arg)(v9232);
      else v9235 = v9232;
        GC_OID(v9235);} 
    if (Kernel._string == OWNER(v9233))
     { new_block_void();
      statement_any(v9235,v9233,v7180);
      princ_string(" ");
      if (v5206 == CTRUE)
       (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v9236,
        Kernel.cfalse,
        v9233,
        v7180);
      else { ident_symbol(OBJECT(Variable,v9236)->pname);
          princ_string(" = ");
          (*Kernel.c_princ)(v9233);
          princ_string("");
          } 
        princ_string(";");
      close_block_void();
      princ_string("");
      } 
    else if (v5206 == CTRUE)
     { new_block_void();
      statement_any(v9235,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        v9236)),v7180);
      princ_string(" ");
      (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v9236,
        Kernel.ctrue,
        v9236,
        v7180);
      princ_string(";");
      close_block_void();
      princ_string("");
      } 
    else statement_any(v9232,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
        v9236)),v7180);
      } 
  GC_UNBIND;} 

void  self_statement_Gassign(Gassign *v9396,OID v9233,OID v7180)
{ (*Generate.stat_gassign)(Generate.PRODUCER->value,
    _oid_(v9396),
    v9233,
    v7180);
  } 

void  self_statement_to_protect(Compile_to_protect *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if ((Optimize.OPT->protection == CTRUE) && 
      (Kernel._string == OWNER(v9233)))
   { ClaireClass * v9211 = OBJECT(ClaireClass,(*Optimize.c_sort)(GC_OID(v9396->arg)));
    new_block_void();
    (OBJECT(Generate_producer,Generate.PRODUCER->value)->stat = (OBJECT(Generate_producer,Generate.PRODUCER->value)->stat+1));
    statement_any(GC_OID(v9396->arg),v9233,v7180);
    princ_string(gc_protect_class(v9211));
    princ_string("(");
    if (INHERIT(v9211,Kernel._object))
     { class_princ_class(psort_any((*Optimize.c_type)(GC_OID(v9396->arg))));
      princ_string(",");
      } 
    (*Kernel.c_princ)(v9233);
    princ_string(");");
    close_block_void();
    } 
  else statement_any(GC_OID(v9396->arg),v9233,v7180);
    GC_UNBIND;} 

void  self_statement_For(For *v9396,OID v9233,OID v7180)
{ (*Generate.stat_for)(Generate.PRODUCER->value,
    _oid_(v9396),
    v9233,
    v7180);
  } 

void  self_statement_Iteration(Iteration *v9396,OID v9233,OID v7180)
{ (*Generate.stat_iteration)(Generate.PRODUCER->value,
    _oid_(v9396),
    v9233,
    v7180);
  } 

void  self_statement_Return(Return *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (v7180 == CNULL)
   { new_block_void();
    statement_any(GC_OID(v9396->arg),_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
    princ_string("break;");
    close_block_void();
    } 
  else if (Kernel._string == OWNER(v7180))
   { new_block_void();
    statement_any(GC_OID(v9396->arg),v7180,_oid_(Kernel.emptySet));
    princ_string("break;");
    close_block_void();
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_("[204] break not inside a For or While:~S"),
      _oid_(list::alloc(1,_oid_(v9396))))));
    GC_UNBIND;} 

void  self_statement_Call(Call *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { list * v9222 = GC_OBJECT(list,v9396->args);
    list * v7392 = GC_OBJECT(list,unfold_args_list(v9222));
    { OID  v539;
      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = v9396->selector);
        { Call * v6716 = v2072; 
          list * v6717;
          { bag *v_list; OID v_val;
            OID v9237,CLcount;
            v_list = v9222;
             v6717 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v9237 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v9222,v7392,v9237);
              
              (*((list *) v6717))[CLcount] = v_val;} 
            } 
          (v6716->args = v6717);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        v539 = _oid_(v2072);
        } 
      unfold_use_list(v7392,v539,v9233,v7180);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method(Call_method *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { list * v9222 = GC_OBJECT(list,v9396->args);
    list * v7392 = GC_OBJECT(list,unfold_args_list(v9222));
    { OID  v3422;
      { Call_method * v2072 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v2072->arg = v9396->arg);
        { Call_method * v6720 = v2072; 
          list * v6721;
          { bag *v_list; OID v_val;
            OID v9237,CLcount;
            v_list = v9222;
             v6721 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v9237 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v9222,v7392,v9237);
              
              (*((list *) v6721))[CLcount] = v_val;} 
            } 
          (v6720->args = v6721);} 
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v2072));
        v3422 = _oid_(v2072);
        } 
      unfold_use_list(v7392,v3422,v9233,v7180);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method1(Call_method1 *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { list * v9222 = GC_OBJECT(list,v9396->args);
    list * v7392 = GC_OBJECT(list,unfold_args_list(v9222));
    { OID  v6305;
      { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
        (v2072->arg = v9396->arg);
        { Call_method * v6723 = v2072; 
          list * v6724;
          { bag *v_list; OID v_val;
            OID v9237,CLcount;
            v_list = v9222;
             v6724 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v9237 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v9222,v7392,v9237);
              
              (*((list *) v6724))[CLcount] = v_val;} 
            } 
          (v6723->args = v6724);} 
        add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
        v6305 = _oid_(v2072);
        } 
      unfold_use_list(v7392,v6305,v9233,v7180);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Call_method2(Call_method2 *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { list * v9222 = GC_OBJECT(list,v9396->args);
    list * v7392 = GC_OBJECT(list,unfold_args_list(v9222));
    { OID  v9188;
      { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
        (v2072->arg = v9396->arg);
        { Call_method * v6746 = v2072; 
          list * v6747;
          { bag *v_list; OID v_val;
            OID v9237,CLcount;
            v_list = v9222;
             v6747 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v9237 = (*(v_list))[CLcount];
              v_val = unfold_arg_list(v9222,v7392,v9237);
              
              (*((list *) v6747))[CLcount] = v_val;} 
            } 
          (v6746->args = v6747);} 
        add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
        v9188 = _oid_(v2072);
        } 
      unfold_use_list(v7392,v9188,v9233,v7180);
      } 
    } 
  GC_UNBIND;} 

void  self_statement_Super(Super *v9396,OID v9233,OID v7180)
{ (*Generate.stat_super)(Generate.PRODUCER->value,
    _oid_(v9396),
    v9233,
    v7180);
  } 

void  self_statement_Cast(Cast *v9396,OID v9233,OID v7180)
{ GC_BIND;
  statement_any(GC_OID(v9396->arg),v9233,v7180);
  GC_UNBIND;} 

void  self_statement_Handle(ClaireHandle *v9396,OID v9233,OID v7180)
{ (*Generate.stat_handle)(Generate.PRODUCER->value,
    _oid_(v9396),
    v9233,
    v7180);
  } 

void  self_statement_to_CL(Compile_to_CL *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (Kernel._string == OWNER(v9233))
   { Variable * v13192 = GC_OBJECT(Variable,build_Variable_string(string_I_symbol(gensym_string("V_CL")),_oid_(v9396->set_arg)));
    ClaireClass * v7559 = ((v9396->set_arg == Kernel._void) ?
      Kernel._any :
      v9396->set_arg );
    new_block_void();
    interface_I_class(v7559);
    princ_string(" ");
    expression_Variable(v13192,v7180);
    princ_string(";");
    statement_any(GC_OID(v9396->arg),GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v13192))),v7180);
    breakline_void();
    princ_string(string_v(v9233));
    princ_string("=");
    (*Generate.to_cl)(Generate.PRODUCER->value,
      _oid_(v13192),
      _oid_(v9396->set_arg),
      v7180);
    princ_string(";");
    close_block_void();
    } 
  else statement_any(GC_OID(v9396->arg),v9233,v7180);
    GC_UNBIND;} 

void  self_statement_to_C(Compile_to_C *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (Kernel._string == OWNER(v9233))
   { Variable * v13192 = GC_OBJECT(Variable,build_Variable_string("V_C",_oid_(Kernel._any)));
    new_block_void();
    (*Generate.any_interface)(Generate.PRODUCER->value);
    princ_string(" ");
    (*Language.ident)(Generate.PRODUCER->value,
      _oid_(v13192));
    princ_string(";");
    statement_any(GC_OID(v9396->arg),GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v13192))),v7180);
    breakline_void();
    princ_string(string_v(v9233));
    princ_string("=");
    (*Generate.to_c)(Generate.PRODUCER->value,
      _oid_(v13192),
      _oid_(v9396->set_arg),
      v7180);
    princ_string(";");
    close_block_void();
    } 
  else statement_any(GC_OID(v9396->arg),v9233,v7180);
    GC_UNBIND;} 

void  self_statement_C_cast(Compile_C_cast *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (Kernel._string == OWNER(v9233))
   { char * v13192 = GC_STRING(check_var_string("V_CC",v9233,v7180));
    ClaireClass * v7559 = v9396->set_arg;
    ClaireClass * v7561 = stupid_t_any1(GC_OID(v9396->arg));
    ClaireType * v7594 = GC_OBJECT(ClaireType,join_class(osort_any(_oid_(v7559)),v7561));
    new_block_void();
    (*Generate.define_variable)(Generate.PRODUCER->value,
      _oid_(v7594),
      _string_(v13192));
    breakline_void();
    statement_any(GC_OID(v9396->arg),_string_(v13192),v7180);
    princ_string(string_v(v9233));
    princ_string("= ");
    (*Generate.pointer_cast)(Generate.PRODUCER->value,
      _oid_(v7559));
    princ_string(" ");
    princ_string(v13192);
    princ_string(";");
    close_block_void();
    } 
  else statement_any(GC_OID(v9396->arg),v9233,v7180);
    GC_UNBIND;} 

void  self_statement_Call_slot(Call_slot *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { char * v10268 = GC_STRING(string_I_symbol(gensym_void()));
    Variable * v13192 = GC_OBJECT(Variable,build_Variable_string(v10268,(*Optimize.c_type)(GC_OID(v9396->arg))));
    new_block_void();
    interface_I_class(sort_Variable(v13192));
    princ_string(" ");
    expression_Variable(v13192,_oid_(Kernel.emptySet));
    princ_string(";");
    breakline_void();
    statement_any(GC_OID(v9396->arg),_string_(v10268),v7180);
    breakline_void();
    if (Kernel._string == OWNER(v9233))
     { c_princ_string(string_v(v9233));
      princ_string(" = ");
      } 
    { Call_slot * v15868;
      { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v2072->selector = v9396->selector);
        (v2072->arg = _oid_(v13192));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
        v15868 = v2072;
        } 
      expression_Call_slot(v15868,v7180);
      } 
    princ_string(";");
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Call_table(Call_table *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { char * v10268 = GC_STRING(string_I_symbol(gensym_void()));
    Variable * v13192 = GC_OBJECT(Variable,build_Variable_string(v10268,(*Optimize.c_type)(GC_OID(v9396->arg))));
    new_block_void();
    interface_I_class(sort_Variable(v13192));
    princ_string(" ");
    expression_Variable(v13192,_oid_(Kernel.emptySet));
    princ_string(";");
    breakline_void();
    statement_any(GC_OID(v9396->arg),_string_(v10268),v7180);
    breakline_void();
    if (Kernel._string == OWNER(v9233))
     { c_princ_string(string_v(v9233));
      princ_string(" = ");
      } 
    { Call_table * v445;
      { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        (v2072->selector = v9396->selector);
        (v2072->arg = _oid_(v13192));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
        v445 = v2072;
        } 
      expression_Call_table(v445,v7180);
      } 
    princ_string(";");
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Call_array(Call_array *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { Variable * v15785 = GC_OBJECT(Variable,build_Variable_string("va_arg1",_oid_(Kernel._array)));
    Variable * v15786 = GC_OBJECT(Variable,build_Variable_string("va_arg2",_oid_(Kernel._integer)));
    new_block_void();
    interface_I_class(Kernel._array);
    princ_string(" ");
    expression_Variable(v15785,_oid_(Kernel.emptySet));
    princ_string(";");
    breakline_void();
    interface_I_class(Kernel._integer);
    princ_string(" ");
    expression_Variable(v15786,_oid_(Kernel.emptySet));
    princ_string(";");
    breakline_void();
    statement_any(GC_OID(v9396->selector),_string_("va_arg1"),v7180);
    statement_any(GC_OID(v9396->arg),_string_("va_arg2"),v7180);
    if (Kernel._string == OWNER(v9233))
     { c_princ_string(string_v(v9233));
      princ_string(" = ");
      } 
    { Call_array * v1406;
      { Call_array * v2072 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v2072->selector = _oid_(v15785));
        (v2072->arg = _oid_(v15786));
        (v2072->test = v9396->test);
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v2072));
        v1406 = v2072;
        } 
      expression_Call_array(v1406,v7180);
      } 
    princ_string(";");
    close_block_void();
    } 
  GC_UNBIND;} 

void  self_statement_Update(Update *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { OID  v9200 = GC_OID(v9396->var);
    OID  v9226 = GC_OID(v9396->selector);
    ClaireType * v7558;
    { if (INHERIT(OWNER(v9200),Language._Call_slot))
       v7558 = domain_I_restriction(OBJECT(Call_slot,v9200)->selector);
      else if (INHERIT(OWNER(v9200),Language._Call_array))
       v7558 = Kernel._integer;
      else v7558 = U_type(Kernel._any,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v9226))));
        GC_OBJECT(ClaireType,v7558);} 
    ClaireType * v7559;
    { if (INHERIT(OWNER(v9200),Language._Call_slot))
       { v7559 = ((v9396->arg == _oid_(Kernel.add)) ?
          member_type(OBJECT(Call_slot,v9200)->selector->range) :
          OBJECT(Call_slot,v9200)->selector->range );
        } 
      else if (INHERIT(OWNER(v9200),Language._Call_array))
       { v7559 = (((OBJECT(ClaireBoolean,(*Core._inf_equalt)(GC_OID(OBJECT(Call_array,v9200)->test),
          _oid_(Kernel._float)))) == CTRUE) ?
          Kernel._float :
          Kernel._any );
        } 
      else v7559 = U_type(Kernel._any,GC_OBJECT(ClaireType,((v9396->arg == _oid_(Kernel.add)) ?
          member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v9226)))) :
          OBJECT(ClaireType,(*Kernel.range)(v9226)) )));
        GC_OBJECT(ClaireType,v7559);} 
    ClaireClass * v7017 = stupid_t_any1(GC_OID((*Kernel.arg)(v9396->var)));
    ClaireClass * v7018 = stupid_t_any1(GC_OID(v9396->value));
    OID  v8569;
    { if ((_inf_equalt_class(v7017,psort_any(_oid_(v7558))) != CTRUE) && 
          (_inf_equalt_class(v7017,Kernel._object) == CTRUE))
       { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v2072->arg = (*Kernel.arg)(GC_OID(v9396->var)));
        (v2072->set_arg = psort_any(_oid_(v7558)));
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
        v8569 = _oid_(v2072);
        } 
      else v8569 = (*Kernel.arg)(GC_OID(v9396->var));
        GC_OID(v8569);} 
    OID  v15316;
    { if ((_inf_equalt_class(v7018,psort_any(_oid_(v7559))) != CTRUE) && 
          (_inf_equalt_class(v7018,Kernel._object) == CTRUE))
       { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v2072->arg = v9396->value);
        (v2072->set_arg = psort_any(_oid_(v7559)));
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
        v15316 = _oid_(v2072);
        } 
      else v15316 = v9396->value;
        GC_OID(v15316);} 
    Variable * v15785 = GC_OBJECT(Variable,Variable_I_symbol(gensym_void(),0,v7558));
    Variable * v15786 = GC_OBJECT(Variable,Variable_I_symbol(gensym_void(),0,v7559));
    ClaireBoolean * v7031 = c_func_any(v8569);
    new_block_void();
    interface_I_class(psort_any(_oid_(v7558)));
    princ_string(" ");
    expression_Variable(v15785,_oid_(Kernel.emptySet));
    princ_string(" ");
    if (v7031 == CTRUE)
     { princ_string("= ");
      (*Generate.expression)(v8569,
        _oid_(Kernel.emptySet));
      princ_string("");
      } 
    princ_string("; ");
    breakline_void();
    interface_I_class(psort_any(_oid_(v7559)));
    princ_string(" ");
    expression_Variable(v15786,_oid_(Kernel.emptySet));
    princ_string(";");
    breakline_void();
    if (v7031 != CTRUE)
     statement_any(v8569,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v15785))),v7180);
    statement_any(v15316,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v15786))),v7180);
    if (Kernel._string == OWNER(v9233))
     { c_princ_string(string_v(v9233));
      princ_string(" = ");
      } 
    { Update * v2367;
      { Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v2072->selector = v9226);
        { Update * v6752 = v2072; 
          OID  v6753;
          if (v9396->arg == _oid_(Kernel.add))
           v6753 = _oid_(Kernel.add);
          else if (sort_Variable(v15785) == Kernel._any)
           v6753 = _oid_(v15785);
          else { Compile_to_CL * v2072 = ((Compile_to_CL *) GC_OBJECT(Compile_to_CL,new_object_class(Optimize._to_CL)));
              (v2072->arg = _oid_(v15785));
              (v2072->set_arg = sort_Variable(v15785));
              add_I_property(Kernel.instances,Optimize._to_CL,11,_oid_(v2072));
              v6753 = _oid_(v2072);
              } 
            (v6752->arg = v6753);} 
        (v2072->value = _oid_(v15786));
        { Update * v6754 = v2072; 
          OID  v6755;
          { OID  v7784 = GC_OID((*Kernel.copy)(v9200));
            put_property2(Kernel.arg,OBJECT(ClaireObject,v7784),_oid_(v15785));
            v6755 = v7784;
            } 
          (v6754->var = v6755);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
        v2367 = v2072;
        } 
      expression_Update(v2367,v7180);
      } 
    princ_string(";");
    close_block_void();
    } 
  GC_UNBIND;} 

