/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\copt.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:50 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
void  inline_exp_c_producer1(Generate_c_producer *v9211,Call_method1 *v9396,OID v7180)
{ GC_BIND;
  { method * v9221 = v9396->arg;
    property * v9226 = v9221->selector;
    OID  v7000 = GC_OID(car_list(v9396->args));
    if ((v9226 == Kernel._dash) && 
        ((domain_I_restriction(v9221) == Kernel._integer) || 
            (domain_I_restriction(v9221) == Kernel._float)))
     { princ_string("(-");
      bexpression_any(v7000,v7180);
      princ_string(")");
      } 
    else if ((v9226 == Core.owner) && 
        (designated_ask_any(v7000) == CTRUE))
     { princ_string("OWNER(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")");
      } 
    else if ((v9226 == Core.sqrt) && 
        (domain_I_restriction(v9221) == Kernel._float))
     { princ_string("sqrt(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")");
      } 
    else if ((v9226 == Core.eval) && 
        (designated_ask_any(v7000) == CTRUE))
     { princ_string("OPT_EVAL(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")");
      } 
    else if (v9226 == Core.externC)
     (*Kernel.princ)(v7000);
    else if ((_oid_(v9221) == Generate._starlength_bag_star->value) && 
        (designated_ask_any(v7000) == CTRUE))
     { (*Generate.expression)(v7000,
        v7180);
      princ_string("->length");
      } 
    else if ((v9226 == Kernel.integer_I) && 
        ((domain_I_restriction(v9221) == Kernel._char) && 
          (designated_ask_any(v7000) == CTRUE)))
     { (*Generate.expression)(v7000,
        v7180);
      princ_string("->ascii");
      } 
    else if (_oid_(v9221) == Generate._starlength_array_star->value)
     { (*Generate.expression)(v7000,
        v7180);
      princ_string("[0]");
      } 
    else if ((_oid_(v9221) == Generate._starnot_star->value) && 
        (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7000))),Kernel._boolean) == CTRUE))
     { princ_string("((");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(" == Kernel.ctrue) ? CFALSE : CTRUE)");
      } 
    else print_external_call_c_producer(v9211,v9396,v7180);
      } 
  GC_UNBIND;} 

void  inline_exp_c_producer2(Generate_c_producer *v9211,Call_method2 *v9396,OID v7180)
{ GC_BIND;
  { method * v9221 = v9396->arg;
    property * v9226 = v9221->selector;
    OID  v7000 = GC_OID((*(v9396->args))[1]);
    OID  v7002 = GC_OID((*(v9396->args))[2]);
    if ((_oid_(v9221) == Generate._starmin_integer_star->value) && 
        ((designated_ask_any(v7000) == CTRUE) && 
          (designated_ask_any(v7002) == CTRUE)))
     { princ_string("((");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(" <= ");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(") ? ");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(" : ");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(")");
      } 
    else if ((_oid_(v9221) == Generate._starmax_integer_star->value) && 
        ((designated_ask_any(v7000) == CTRUE) && 
          (designated_ask_any(v7002) == CTRUE)))
     { princ_string("((");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(" <= ");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(") ? ");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(" : ");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")");
      } 
    else if ((v9226 == Core.class_I) && 
        (INHERIT(OWNER(v7000),Kernel._symbol)))
     { princ_string("(");
      ident_thing(defined_symbol(OBJECT(symbol,v7000)));
      princ_string("._");
      c_princ_string(string_v((*Kernel.string_I)(v7000)));
      princ_string(" = ClaireClass::make(");
      print_any(GC_OID((*Kernel.string_I)(v7000)));
      princ_string(",");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(",");
      ident_thing(OBJECT(thing,(*Kernel.module_I)(v7000)));
      princ_string(".it))");
      } 
    else if ((v9211->open_operators->memq(_oid_(v9226)) == CTRUE) && 
        (((v9226 != Kernel._7) || 
            (5 <= Optimize.compiler->safety)) && 
          ((equal((*(v9221->domain))[1],(*(v9221->domain))[2]) == CTRUE) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7000))),Kernel._integer) == CTRUE) || 
                (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7000))),Kernel._float) == CTRUE)))))
     { if ((Optimize.compiler->safety < 2) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7000))),Kernel._integer) == CTRUE))
       princ_string("_integer_");
      princ_string("(");
      bexpression_any(v7000,v7180);
      princ_string(string_I_symbol(v9226->name));
      bexpression_any(v7002,v7180);
      princ_string(")");
      } 
    else if ((_oid_(v9221) == Generate._starcontain_star->value) && 
        (identifiable_ask_any(v7002) == CTRUE))
     { (*Generate.expression)(v7000,
        v7180);
      princ_string("->memq(");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(")");
      } 
    else if (((_oid_(v9221) == Generate._starnth_list_star->value) && 
          (2 <= Optimize.compiler->safety)) || 
        (_oid_(v9221) == Generate._starnth_1_bag_star->value))
     { princ_string("(*(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string("))[");
      (*Generate.expression)(v7002,
        v7180);
      princ_string("]");
      } 
    else if ((v9226 == Kernel.add_I) && 
        (_inf_equal_type(domain_I_restriction(v9221),Kernel._bag) == CTRUE))
     { (*Generate.expression)(v7000,
        v7180);
      princ_string("->addFast(");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(")");
      } 
    else if ((_oid_(v9221) == Generate._starnth_string_star->value) && 
        (2 <= Optimize.compiler->safety))
     { princ_string("_char_(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string("[");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(" - 1])");
      } 
    else if (v9221->selector == Core.identical_ask)
     { princ_string("(");
      (*Optimize.bool_exp)(_oid_(v9396),
        Kernel.ctrue,
        v7180);
      princ_string(" ? CTRUE : CFALSE)");
      } 
    else if (v9221->selector == Core.externC)
     (*Kernel.princ)(v7000);
    else if ((v9226 == Core.inlineok_ask) && 
        (Kernel._string == OWNER(v7002)))
     { (*Generate.expression)(v7000,
        v7180);
      princ_string("->inlineDef(");
      print_any(v7002);
      princ_string(")");
      } 
    else print_external_call_c_producer(v9211,v9396,v7180);
      } 
  GC_UNBIND;} 

void  inline_exp_c_producer3(Generate_c_producer *v9211,Call_method *v9396,OID v7180)
{ GC_BIND;
  { method * v9221 = v9396->arg;
    ClaireBoolean * v9210 = Optimize.OPT->alloc_stack;
    OID  v7000 = GC_OID((*(v9396->args))[1]);
    OID  v7002 = GC_OID((*(v9396->args))[2]);
    OID  v7003 = GC_OID((*(v9396->args))[3]);
    (Optimize.OPT->alloc_stack = CFALSE);
    if ((_oid_(v9221) == Generate._starnth_equal_list_star->value) && 
        (3 <= Optimize.compiler->safety))
     { princ_string("((*(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string("))[");
      (*Generate.expression)(v7002,
        v7180);
      princ_string("]=");
      (*Generate.expression)(v7003,
        v7180);
      princ_string(")");
      } 
    else if ((domain_I_restriction(v9221) == Kernel._string) && 
        (((v9221->selector == Kernel.nth_equal) && 
              (2 <= Optimize.compiler->safety)) || 
            (v9221->selector == Kernel.nth_put)))
     { princ_string("(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string("[");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(" - 1] = (char) ");
      (*Generate.expression)(v7003,
        v7180);
      princ_string("->ascii)");
      } 
    else if (_oid_(v9221) == Generate._starnth_1_string_star->value)
     { princ_string("_char_(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string("[");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(" - 1])");
      } 
    else if ((v9221->selector == Kernel.store) && 
        ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7000))),Kernel._list) == CTRUE) && 
          (((v9396->args->length == 4) && 
                ((*(v9396->args))[4] == Kernel.ctrue)) || 
              (v9396->args->length == 3))))
     { princ_string("STOREI((*");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")[");
      (*Generate.expression)(v7002,
        v7180);
      princ_string("],");
      (*Generate.expression)(v7003,
        v7180);
      princ_string(")");
      } 
    else if ((v9221->selector == Kernel.store) && 
        ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7000))),Kernel._array) == CTRUE) && 
          ((equal(_oid_(_exp_type(GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7000))))),Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE) && 
            (((v9396->args->length == 4) && 
                  ((*(v9396->args))[4] == Kernel.ctrue)) || 
                (v9396->args->length == 3)))))
     { princ_string("STOREI(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string("[");
      (*Generate.expression)(v7002,
        v7180);
      princ_string("],");
      (*Generate.expression)(v7003,
        v7180);
      princ_string(")");
      } 
    else if ((v9221->selector == Kernel.add_slot) && 
        (INHERIT(owner_any(getC_any(v7000)),Kernel._class)))
     { princ_string("CL_ADD_SLOT(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(",");
      class_princ_class(OBJECT(ClaireClass,getC_any(v7000)));
      princ_string(",");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(",");
      ident_symbol(OBJECT(symbol,(*Kernel.name)(GC_OID(getC_any(v7002)))));
      princ_string(",");
      (*Generate.expression)(GC_OID(getC_any(v7003)),
        v7180);
      princ_string(",");
      (*Generate.expression)(GC_OID((*(v9396->args))[4]),
        v7180);
      princ_string(")");
      } 
    else if (v9221->selector == Kernel.add_method)
     { if (INHERIT(OWNER(v7000),Kernel._property))
       { (*Generate.expression)(v7000,
          v7180);
        princ_string("->add");
        if (v9396->args->length > 5)
         princ_string("Float");
        princ_string("Method(");
        signature_I_c_producer(v9211,v7002);
        princ_string(",");
        (*Generate.expression)(v7003,
          v7180);
        princ_string(",");
        breakline_void();
        princ_string("\t");
        bitvector_I_c_producer(v9211,GC_OID((*(v9396->args))[4]));
        princ_string(",");
        (*Generate.expression)(GC_OID((*(v9396->args))[5]),
          v7180);
        if (v9396->args->length > 5)
         { princ_string(",");
          (*Generate.expression)(GC_OID((*(v9396->args))[6]),
            v7180);
          } 
        princ_string(")");
        } 
      else { princ_string("add_method_property(");
          args_list_bag(GC_OBJECT(list,v9396->args),v7180,CTRUE);
          princ_string(")");
          } 
        } 
    else { (Optimize.OPT->alloc_stack = v9210);
        print_external_call_c_producer(v9211,v9396,v7180);
        } 
      (Optimize.OPT->alloc_stack = v9210);
    } 
  GC_UNBIND;} 

void  print_external_call_c_producer(Generate_c_producer *v9211,Call_method *v9396,OID v7180)
{ GC_BIND;
  { method * v9221 = v9396->arg;
    list * v9222 = GC_OBJECT(list,v9396->args);
    int  v9223 = 1;
    list * v7392 = v9221->domain;
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v9221))));
    princ_string("(");
    if (v9222->length > 4)
     (Optimize.OPT->level = (Optimize.OPT->level+1));
    if ((v9222->length == 1) && 
        (domain_I_restriction(v9221) == Kernel._void))
     v9222= Kernel.nil;
    { ITERATE(v9232);
      for (START(v9222); NEXT(v9232);)
      { if (v9223 != 1)
         { princ_string(",");
          if (v9222->length > 4)
           breakline_void();
          } 
        { ClaireClass * v7558 = psort_any((*(v7392))[v9223]);
          ClaireClass * v7559 = stupid_t_any1(v9232);
          if ((_inf_equalt_class(v7558,Kernel._object) == CTRUE) && 
              (_inf_equalt_class(v7559,v7558) != CTRUE))
           { princ_string("(");
            class_princ_class(v7558);
            princ_string(" *) ");
            } 
          } 
        (*Generate.expression)(v9232,
          v7180);
        ++v9223;
        } 
      } 
    princ_string(")");
    if ((INHERIT(v9221->range->isa,Kernel._tuple)) && 
        (Optimize.OPT->alloc_stack != CTRUE))
     princ_string("->copyIfNeeded()");
    if (v9222->length > 4)
     (Optimize.OPT->level = (Optimize.OPT->level-1));
    } 
  GC_UNBIND;} 

void  inline_exp_c_producer5(Generate_c_producer *v9211,Call *v9396,OID v7180)
{ GC_BIND;
  { property * v9226 = v9396->selector;
    OID  v7000 = GC_OID(car_list(v9396->args));
    int  v9223 = v9396->args->length;
    if (v9226 == Core.get_stack)
     { princ_string("ClEnv->stack[");
      (*Generate.expression)(v7000,
        v7180);
      princ_string("]");
      } 
    else if (v9226 == Optimize.safe)
     { int  v9235 = Optimize.compiler->safety;
      (Optimize.compiler->safety = 1);
      (*Generate.expression)((*(v9396->args))[1],
        v7180);
      (Optimize.compiler->safety = v9235);
      } 
    else if (v9226 == Core.base_I)
     princ_string("ClEnv->base");
    else if ((v9226 == Core.index_I) && 
        (v9223 == 1))
     princ_string("ClEnv->index");
    else if ((v9226 == Core.push_I) && 
        (v9223 == 1))
     { princ_string("PUSH(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")");
      } 
    else if (v9226 == Core.put_stack)
     { princ_string("(ClEnv->stack[");
      (*Generate.expression)(v7000,
        v7180);
      princ_string("]=");
      (*Generate.expression)((*(v9396->args))[2],
        v7180);
      princ_string(")");
      } 
    else if (v9226 == Core.set_base)
     { princ_string("(ClEnv->base= ");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")");
      } 
    else if (v9226 == Core.set_index)
     { princ_string("(ClEnv->index= ");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")");
      } 
    else if (v9226 == Optimize.object_I)
     { OID  v7002 = (*(v9396->args))[2];
      princ_string("(");
      ident_thing(defined_symbol(OBJECT(symbol,v7000)));
      princ_string(".");
      if (_inf_equal_type(OBJECT(ClaireType,v7002),Reader._reserved_keyword) == CTRUE)
       { princ_string("_cl_");
        c_princ_string(string_v((*Kernel.string_I)(v7000)));
        } 
      else (*Language.ident)(v7000);
        princ_string(" = ");
      if ((v7002 == _oid_(Kernel._property)) && 
          (INHERIT(owner_any((*Kernel.value)(v7000)),Kernel._property)))
       { princ_string("property::make(");
        print_any(GC_OID((*Kernel.string_I)(v7000)));
        princ_string(",");
        princ_integer((*Kernel.open)(GC_OID((*Kernel.value)(v7000))));
        princ_string(",");
        expression_thing(OBJECT(thing,(*Kernel.module_I)(v7000)),Core.nil->value);
        princ_string(",");
        (*Generate.expression)(GC_OID((*Kernel.domain)(GC_OID((*Kernel.value)(v7000)))),
          Core.nil->value);
        princ_string(",");
        (*Kernel.princ)(GC_OID((*Kernel.dispatcher)(GC_OID((*Kernel.value)(v7000)))));
        princ_string(")");
        } 
      else { princ_string("(");
          class_princ_class(OBJECT(ClaireClass,v7002));
          princ_string(" *) ");
          (*Generate.expression)(v7002,
            v7180);
          princ_string("->instantiate(");
          print_any(GC_OID((*Kernel.string_I)(v7000)));
          princ_string(",");
          expression_thing(OBJECT(thing,(*Kernel.module_I)(v7000)),Core.nil->value);
          princ_string(")");
          } 
        princ_string(")");
      } 
    else if (v9226 == Optimize.anyObject_I)
     { princ_string("((");
      class_princ_class(OBJECT(ClaireClass,v7000));
      princ_string(" *) (*");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(")(");
      args_list_bag(GC_OBJECT(list,cdr_list(GC_OBJECT(list,v9396->args))),v7180,_sup_integer(v9396->args->length,2));
      princ_string("))");
      } 
    else if ((OBJECT(ClaireBoolean,(*Generate.fcall_ask)(_oid_(v9396)))) == CTRUE)
     (*Generate.fcall_exp)(_oid_(v9396),
      v7180);
    else if (v9396->args->length > 20)
     { if (v9396->selector == Kernel.store)
       { list * v9222 = GC_OBJECT(list,v9396->args);
        int  v9223 = v9222->length;
        int  v9221 = (v9223/10);
        princ_string("(");
        { int  v9217 = 0;
          int  v6816 = v9221;
          { OID gc_local;
            while ((v9217 <= v6816))
            { GC_LOOP;
              princ_string("(*");
              expression_thing(Kernel.store,v7180);
              princ_string(")(");
              { list * v5015;
                { list * v15947 = list::empty(Kernel.emptySet);
                  { int  v9218 = ((v9217*10)+1);
                    int  v6817 = ((v9217 == v9221) ?
                      v9223 :
                      ((v9217*10)+10) );
                    { OID gc_local;
                      while ((v9218 <= v6817))
                      { v15947->addFast((*(v9222))[v9218]);
                        ++v9218;
                        } 
                      } 
                    } 
                  v5015 = GC_OBJECT(list,v15947);
                  } 
                args_list_bag(v5015,v7180,CTRUE);
                } 
              princ_string(")");
              if (v9217 != v9221)
               princ_string(",");
              ++v9217;
              GC_UNLOOP;} 
            } 
          } 
        princ_string(")");
        } 
      else close_exception(((general_error *) (*Core._general_error)(_string_("[216] ~S has more than 10 parameters"),
          _oid_(list::alloc(1,_oid_(v9396))))));
        } 
    else { princ_string("(*");
        expression_thing(v9396->selector,v7180);
        princ_string(")(");
        args_list_bag(GC_OBJECT(list,v9396->args),v7180,_sup_integer(v9396->args->length,1));
        princ_string(")");
        } 
      } 
  GC_UNBIND;} 

ClaireBoolean * fcall_ask_Call2_Generate(Call *v9232)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireBoolean *Result ;
    { property * v9226 = v9232->selector;
      OID  v7000 = GC_OID((*(v9232->args))[1]);
      int  v6121;
      { list * v5976;
        { bag * v2067 = v9232->args;
          list * v4640 = ((list *) empty_bag(v2067));
          { OID gc_local;
            ITERATE(v9235);
            for (START(v2067); NEXT(v9235);)
            if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v9235))) == CTRUE)
             v4640->addFast(v9235);
            } 
          v5976 = GC_OBJECT(list,v4640);
          } 
        v6121 = v5976->length;
        } 
      { ClaireBoolean *v_and;
        { v_and = ((designated_ask_any(v7000) == CTRUE) ? CTRUE : ((v9226->dispatcher > 0) ? CTRUE : CFALSE));
          if (v_and == CFALSE) Result =CFALSE; 
          else { { list * v9222 = GC_OBJECT(list,cdr_list(GC_OBJECT(list,v9232->args)));
              ClaireType * v3191 = Kernel.emptySet;
              list * v7408;
              { { bag *v_list; OID v_val;
                  OID v9235,CLcount;
                  v_list = GC_OBJECT(list,v9232->args);
                   v7408 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v9235 = (*(v_list))[CLcount];
                    v_val = _oid_(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v9235))));
                    
                    (*((list *) v7408))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v7408);} 
              list * v322 = GC_OBJECT(list,cdr_list(v7408));
              list * v7406 = GC_OBJECT(list,get_restrictions_Call2(v9232,v7408));
              ClaireBoolean * v12110;
              { ClaireBoolean *v_and;
                { v_and = ((v7406->length > 0) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) v12110 =CFALSE; 
                  else { { ClaireBoolean *v_or;
                      { v_or = ((v6121 == 0) ? CTRUE : CFALSE);
                        if (v_or == CTRUE) v_and =CTRUE; 
                        else { { OID  v6937;
                            { OID gc_local;
                              ITERATE(v9221);
                              v6937= Kernel.cfalse;
                              for (START(v7406); NEXT(v9221);)
                              if (not_any(_oid_(nth_integer(status_I_restriction(OBJECT(restriction,v9221)),1))) != CTRUE)
                               { v6937 = Kernel.ctrue;
                                break;} 
                              } 
                            v_or = not_any(v6937);
                            } 
                          if (v_or == CTRUE) v_and =CTRUE; 
                          else v_and = CFALSE;} 
                        } 
                      } 
                    if (v_and == CFALSE) v12110 =CFALSE; 
                    else { v_and = (((v9226->dispatcher > 0) && 
                          (v9222->length <= 4)) ? CTRUE : ((v7406->length < 3) ? CTRUE : CFALSE));
                      if (v_and == CFALSE) v12110 =CFALSE; 
                      else v12110 = CTRUE;} 
                    } 
                  } 
                } 
              ClaireClass * v9233 = ((v7406->length > 0) ?
                c_srange_method(OBJECT(method,(*(v7406))[1])) :
                Kernel._void );
              ClaireBoolean * v9034;
              { OID  v7898;
                { OID gc_local;
                  ITERATE(v9239);
                  v7898= Kernel.cfalse;
                  for (START(v7406); NEXT(v9239);)
                  { GC_LOOP;
                    { ClaireBoolean * g0084I;
                      { OID  v9820;
                        { GC__ANY(v3191 = U_type(v3191,domain_I_restriction(OBJECT(restriction,v9239))), 1);
                          v9820 = _oid_(((INHERIT(OWNER((*(OBJECT(restriction,v9239)->domain))[1]),Kernel._class)) ? ((last_list(OBJECT(restriction,v9239)->domain) != _oid_(Kernel._listargs)) ? ((tmatch_ask_list(v322,GC_OBJECT(list,cdr_list(OBJECT(restriction,v9239)->domain))) == CTRUE) ? ((c_srange_method(OBJECT(method,v9239)) == v9233) ? CTRUE: CFALSE): CFALSE): CFALSE): CFALSE));
                          } 
                        g0084I = not_any(v9820);
                        } 
                      
                      if (g0084I == CTRUE) { v7898 = Kernel.ctrue;
                          break;} 
                        } 
                    GC_UNLOOP;} 
                  } 
                v9034 = not_any(v7898);
                } 
              ClaireBoolean * v34 = (((v9233 == Kernel._integer) || 
                  ((v9233 == Kernel._object) || 
                    ((v9233 == Kernel._any) || 
                      (v9233 == Kernel._void)))) ? ((_inf_equal_type(v3191,Kernel._object) == CTRUE) ? ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v7000)))),v3191) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
              if (((OBJECT(ClaireBoolean,Generate.FCALLSTINKS->value)) == CTRUE) && 
                  ((((v12110 == CTRUE) ? ((v9034 == CTRUE) ? ((v34 == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE) != CTRUE) && 
                    (v9226->dispatcher > 0)))
               tformat_string("****> fcall(~S) fails (selectorOK = ~S , lrOK = ~S, callOK = ~S)\n",0,GC_OBJECT(list,list::alloc(4,_oid_(v9232),
                _oid_(v12110),
                _oid_(v9034),
                _oid_(v34))));
              v_and = ((v12110 == CTRUE) ? ((v9034 == CTRUE) ? ((v34 == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

list * get_restrictions_Call2(Call *v9232,list *v7408)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { property * v9226 = v9232->selector;
      ClaireBoolean * v10636 = ((class_I_type(OBJECT(ClaireType,(*(v7408))[1]))->open == ClEnv->open) ? CTRUE : CFALSE);
      list * v7406 = list::empty(Kernel._method);
      if ((v9226->dispatcher == 0) && 
          ((v10636 == CTRUE) || 
              (v9226->open == ClEnv->open)))
       ;else { OID gc_local;
          ITERATE(v9239);
          for (START(v9226->restrictions); NEXT(v9239);)
          { GC_LOOP;
            if (length_bag(_exp_list(OBJECT(restriction,v9239)->domain,v7408)) != 0)
             { if (Kernel._method == OBJECT(ClaireObject,v9239)->isa)
               GC__ANY(v7406 = v7406->addFast(v9239), 1);
              else { shrink_list(v7406,0);
                  break;} 
                } 
            GC_UNLOOP;} 
          } 
        Result = v7406;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  fcall_exp_Call2_Generate(Call *v9232,OID v7180)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { property * v9226 = v9232->selector;
    OID  v7000 = (*(v9232->args))[1];
    list * v7408;
    { { bag *v_list; OID v_val;
        OID v9235,CLcount;
        v_list = v9232->args;
         v7408 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v9235 = (*(v_list))[CLcount];
          v_val = _oid_(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v9235))));
          
          (*((list *) v7408))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v7408);} 
    list * v7406 = GC_OBJECT(list,get_restrictions_Call2(v9232,v7408));
    method * v9221 = OBJECT(method,(*(v7406))[1]);
    ClaireClass * v9233 = c_srange_method(v9221);
    if (v9233 == Kernel._void)
     princ_string("_void_(");
    else if (v9233 == Kernel._object)
     princ_string("_oid_(");
    else if ((v9233 == Kernel._integer) && 
        (Optimize.compiler->safety <= 2))
     princ_string("_integer_(");
    if ((v9226->dispatcher > 0) && 
        (v7408->length <= 4))
     { if (v9233 == Kernel._object)
       princ_string("(ClaireObject *) ");
      expression_thing(v9226,v7180);
      princ_string("->fcall(");
      c_sorted_args_Call(v9232,v9221->srange,v7180,CTRUE);
      princ_string(")");
      } 
    else { list * v260;
        { { bag * v5044 = v9226->definition;
            list * v15007 = ((list *) empty_bag(v5044));
            { OID gc_local;
              ITERATE(v9232);
              for (START(v5044); NEXT(v9232);)
              if (v7406->memq(v9232) == CTRUE)
               v15007->addFast(v9232);
              } 
            v260 = GC_OBJECT(list,v15007);
            } 
          GC_OBJECT(list,v260);} 
        { OID gc_local;
          ITERATE(v9221);
          for (START(v260); NEXT(v9221);)
          { GC_LOOP;
            { list * v13990;
              { { bag *v_list; OID v_val;
                  OID v9232,CLcount;
                  v_list = OBJECT(restriction,v9221)->domain;
                   v13990 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v9232 = (*(v_list))[CLcount];
                    v_val = _oid_(psort_any(v9232));
                    
                    (*((list *) v13990))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v13990);} 
              if (v9221 != last_list(v260))
               { princ_string("(INHERIT(");
                if (INHERIT(OWNER(v7000),Optimize._to_CL))
                 { (*Generate.expression)(GC_OID((*Kernel.arg)(v7000)),
                    v7180);
                  princ_string("->isa");
                  } 
                else { princ_string("OWNER(");
                    (*Generate.expression)(v7000,
                      v7180);
                    princ_string(")");
                    } 
                  princ_string(",");
                expression_any(_oid_(domain_I_restriction(OBJECT(restriction,v9221))),v7180);
                princ_string(") ? ");
                if (v9233 == Kernel._object)
                 princ_string("(ClaireObject *)");
                princ_string(" ");
                c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(v9221)));
                princ_string("((");
                class_princ_class(domain_I_restriction(OBJECT(restriction,v9221)));
                princ_string(" *) ");
                c_sorted_args_Call(v9232,v13990,v7180,CFALSE);
                princ_string(") : ");
                ;princ_string(" ");
                } 
              else { if (v9233 == Kernel._object)
                   princ_string("(ClaireObject *) ");
                  princ_string(" ");
                  c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(v9221)));
                  princ_string("((");
                  (*Generate.interface_I)(Generate.PRODUCER->value,
                    _oid_(domain_I_restriction(OBJECT(restriction,v9221))));
                  princ_string(") ");
                  c_sorted_args_Call(v9232,v13990,v7180,CFALSE);
                  princ_string(")");
                  { int  v9217 = 1;
                    int  v6846 = (v260->length-1);
                    { OID gc_local;
                      while ((v9217 <= v6846))
                      { princ_string(")");
                        ++v9217;
                        } 
                      } 
                    } 
                  } 
                } 
            GC_UNLOOP;} 
          } 
        } 
      if ((v9233 == Kernel._void) || 
        ((v9233 == Kernel._object) || 
          ((v9233 == Kernel._float) || 
            ((v9233 == Kernel._integer) && 
                (Optimize.compiler->safety <= 2)))))
     princ_string(")");
    } 
  GC_UNBIND;} 

void  c_sorted_arg_any(OID v9232,ClaireClass *v9233,OID v7180,ClaireBoolean *v14460)
{ GC_BIND;
  if (v14460 == CTRUE)
   princ_string("((int) ");
  if ((INHERIT(OWNER(v9232),Optimize._to_CL)) && (osort_any(_oid_(OBJECT(Compile_to_CL,v9232)->set_arg)) == v9233))
   (*Generate.expression)(GC_OID((*Kernel.arg)(v9232)),
    v7180);
  else if (v9233 == Kernel._any)
   (*Generate.expression)(v9232,
    v7180);
  else (*Generate.to_c)(Generate.PRODUCER->value,
      v9232,
      _oid_(v9233),
      v7180);
    if (v14460 == CTRUE)
   princ_string(")");
  GC_UNBIND;} 

void  c_sorted_args_Call(Call *v9232,list *v7407,OID v7180,ClaireBoolean *v14460)
{ GC_BIND;
  { int  v9217 = 0;
    { OID gc_local;
      ITERATE(v9235);
      for (START(v9232->args); NEXT(v9235);)
      { if (v9217 != 0)
         princ_string(",");
        ++v9217;
        c_sorted_arg_any(v9235,OBJECT(ClaireClass,(*(v7407))[v9217]),v7180,v14460);
        } 
      } 
    } 
  GC_UNBIND;} 

void  bitvector_I_c_producer(Generate_c_producer *v9211,OID v9232)
{ GC_BIND;
  if (INHERIT(OWNER(v9232),Kernel._integer))
   bitvectorSum_integer(v9232);
  else if (INHERIT(OWNER(v9232),Optimize._to_CL))
   bitvector_I_c_producer(v9211,GC_OID(OBJECT(Compile_to_CL,v9232)->arg));
  else if (INHERIT(OWNER(v9232),Optimize._to_protect))
   bitvector_I_c_producer(v9211,GC_OID(OBJECT(Compile_to_protect,v9232)->arg));
  else (*Generate.expression)(v9232,
      Core.nil->value);
    GC_UNBIND;} 

void  bitvectorSum_integer(int v9232)
{ if (v9232 == 0)
   princ_string("0");
  else { ClaireBoolean * v9210 = CFALSE;
      int  v9217 = 1;
      int  v6847 = 7;
      { while ((v9217 <= v6847))
        { if (BCONTAIN(v9232,v9217))
           { if (v9210 == CTRUE)
             princ_string("+");
            else v9210= CTRUE;
              princ_string(string_v((*(OBJECT(bag,Generate.bitvectorList->value)))[v9217]));
            } 
          ++v9217;
          } 
        } 
      } 
    } 

void  signature_I_c_producer(Generate_c_producer *v9211,OID v9232)
{ GC_BIND;
  if (INHERIT(OWNER(v9232),Kernel._list))
   { princ_string("list::domain(");
    princ_integer(OBJECT(bag,v9232)->length);
    princ_string(",");
    { list * v12703;
      { { bag *v_list; OID v_val;
          OID v9235,CLcount;
          v_list = OBJECT(bag,v9232);
           v12703 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v9235 = (*(v_list))[CLcount];
            v_val = getC_any(v9235);
            
            (*((list *) v12703))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v12703);} 
      args_list_bag(v12703,Core.nil->value,_sup_integer(OBJECT(bag,v9232)->length,3));
      } 
    princ_string(")");
    } 
  else if (INHERIT(OWNER(v9232),Optimize._to_C))
   signature_I_c_producer(v9211,GC_OID(OBJECT(Compile_to_C,v9232)->arg));
  else if (INHERIT(OWNER(v9232),Optimize._to_protect))
   signature_I_c_producer(v9211,GC_OID(OBJECT(Compile_to_protect,v9232)->arg));
  else if (INHERIT(OWNER(v9232),Language._List))
   signature_I_c_producer(v9211,GC_OID(_oid_(OBJECT(Construct,v9232)->args)));
  else if (INHERIT(OWNER(v9232),Language._Variable))
   expression_Variable(OBJECT(Variable,v9232),Core.nil->value);
  else { princ_string("<fucking ");
      print_any(_oid_(OWNER(v9232)));
      princ_string(":");
      print_any(v9232);
      princ_string(">");
      } 
    GC_UNBIND;} 

OID  getC_any(OID v9232)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v9232),Optimize._to_CL))
     Result = getC_any(GC_OID(OBJECT(Compile_to_CL,v9232)->arg));
    else if (INHERIT(OWNER(v9232),Optimize._to_protect))
     Result = getC_any(GC_OID(OBJECT(Compile_to_protect,v9232)->arg));
    else if (INHERIT(OWNER(v9232),Core._global_variable))
     { if (nativeVar_ask_global_variable(OBJECT(global_variable,v9232)) == CTRUE)
       Result = v9232;
      else { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
          (v2072->arg = v9232);
          (v2072->set_arg = Kernel._type);
          add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    else Result = v9232;
      GC_UNBIND; return (Result);} 
  } 

void  gassign_c_producer(Generate_c_producer *v9211,Gassign *v9396,OID v7180)
{ GC_BIND;
  if (v9396->var->store_ask == CTRUE)
   { princ_string("(STOREI(");
    expression_global_variable(v9396->var,v7180);
    princ_string(",");
    (*Generate.expression)(v9396->arg,
      v7180);
    princ_string("))");
    } 
  else { princ_string("(");
      expression_global_variable(v9396->var,v7180);
      princ_string("= ");
      (*Generate.expression)(v9396->arg,
        v7180);
      princ_string(")");
      } 
    GC_UNBIND;} 

void  call_slot_c_producer(Generate_c_producer *v9211,Call_slot *v9396,OID v7180)
{ GC_BIND;
  if (v9396->test == CTRUE)
   { princ_string((((INHERIT(v9396->selector->srange,Kernel._cl_import)) || 
        ((INHERIT(v9396->selector->srange,Kernel._string)) || 
          ((INHERIT(v9396->selector->srange,Kernel._array)) || 
            (INHERIT(v9396->selector->srange,Kernel._object))))) ?
      "NOTNULL" :
      "KNOWN" ));
    princ_string("(");
    expression_thing(v9396->selector->selector,v7180);
    princ_string(",");
    } 
  c_member_c_producer(v9211,
    GC_OID(v9396->arg),
    psort_any(_oid_(domain_I_restriction(v9396->selector))),
    v9396->selector->selector,
    v7180);
  if (v9396->test == CTRUE)
   princ_string(")");
  GC_UNBIND;} 

void  call_table_c_producer(Generate_c_producer *v9211,Call_table *v9396,OID v7180)
{ GC_BIND;
  { table * v9209 = v9396->selector;
    OID  v9226 = v9209->params;
    OID  v9222 = v9396->arg;
    if (v9396->test == CTRUE)
     { princ_string("KNOWN(");
      expression_thing(v9209,v7180);
      princ_string(",");
      } 
    princ_string("(*(");
    expression_thing(v9209,v7180);
    princ_string("->graph))[");
    if (INHERIT(OWNER(v9226),Kernel._integer))
     { (*Generate.expression)(v9222,
        v7180);
      princ_string(" - ");
      princ_integer(v9226);
      princ_string("");
      } 
    else if (INHERIT(OWNER(v9226),Kernel._list))
     { (*Generate.expression)((*(OBJECT(bag,(*Core.args)(v9222))))[1],
        v7180);
      princ_string(" * ");
      (*Kernel.princ)((*(OBJECT(bag,v9226)))[1]);
      princ_string(" + ");
      (*Generate.expression)((*(OBJECT(bag,(*Core.args)(v9222))))[2],
        v7180);
      princ_string(" - ");
      (*Kernel.princ)((*(OBJECT(bag,v9226)))[2]);
      princ_string("");
      } 
    princ_string("]");
    if (v9396->test == CTRUE)
     princ_string(")");
    } 
  GC_UNBIND;} 

void  call_array_c_producer(Generate_c_producer *v9211,Call_array *v9396,OID v7180)
{ GC_BIND;
  if (v9396->test == _oid_(Kernel._float))
   { princ_string("((double *) ");
    (*Generate.expression)(v9396->selector,
      v7180);
    princ_string(")[");
    (*Generate.expression)(v9396->arg,
      v7180);
    princ_string("]");
    } 
  else { princ_string("((OID *) ");
      (*Generate.expression)(v9396->selector,
        v7180);
      princ_string(")[");
      (*Generate.expression)(v9396->arg,
        v7180);
      princ_string("]");
      } 
    GC_UNBIND;} 

void  update_c_producer(Generate_c_producer *v9211,Update *v9396,OID v7180)
{ GC_BIND;
  { OID  v9226 = v9396->selector;
    OID  v9209 = v9396->arg;
    OID  v9236 = v9396->value;
    OID  v9232 = v9396->var;
    ClaireClass * v9233 = OBJECT(ClaireClass,(*Optimize.c_sort)(v9236));
    if ((INHERIT(OWNER(v9226),Kernel._relation)) && ((OBJECT(ClaireRelation,v9226)->if_write != CNULL) && 
        ((v9209 != _oid_(Kernel.put)) && 
          (v9209 != _oid_(Core.put_store)))))
     { c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v9226))));
      princ_string("_write(");
      (*Generate.expression)(GC_OID((*Kernel.arg)(v9232)),
        v7180);
      princ_string(",");
      (*Generate.expression)(v9236,
        v7180);
      princ_string(")");
      } 
    else if ((INHERIT(OWNER(v9226),Kernel._relation)) && ((OBJECT(ClaireRelation,v9226)->store_ask == CTRUE) || 
        (v9209 == _oid_(Core.put_store))))
     { princ_string("STORE");
      princ_string((((v9233 == Kernel._any) || 
          (v9233 == Kernel._integer)) ?
        "I" :
        ((v9233 == Kernel._float) ?
          "F" :
          "O" ) ));
      princ_string("(");
      (*Generate.expression)(v9232,
        v7180);
      princ_string(",");
      (*Generate.expression)(v9236,
        v7180);
      princ_string(")");
      } 
    else { princ_string("(");
        (*Generate.expression)(v9232,
          v7180);
        princ_string(" = ");
        (*Generate.expression)(v9236,
          v7180);
        princ_string(")");
        } 
      } 
  GC_UNBIND;} 

void  object_test_c_producer(Generate_c_producer *v9211,OID v7000,ClaireBoolean *v11731,OID v7180)
{ princ_string("(CTAG(");
  (*Generate.expression)(v7000,
    v7180);
  princ_string(") ");
  sign_equal_boolean(v11731);
  princ_string(" OBJ_CODE)");
  } 

void  exp_to_protect_c_producer(Generate_c_producer *v9211,Compile_to_protect *v9396,OID v7180)
{ GC_BIND;
  { OID  v7626 = GC_OID((*Optimize.c_type)(v9396->arg));
    if ((Optimize.OPT->protection == CTRUE) && 
        ((need_protect_any(v9396->arg) == CTRUE) && 
          (((Optimize.OPT->alloc_stack == CTRUE) ? ((_inf_equal_type(OBJECT(ClaireType,v7626),Kernel._tuple) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
     { OID  v9232 = v9396->arg;
      ClaireClass * v9233 = OBJECT(ClaireClass,(*Optimize.c_sort)(v9232));
      princ_string(gc_protect_class(v9233));
      princ_string("(");
      if (INHERIT(v9233,Kernel._object))
       { class_princ_class(psort_any((*Core.glb)(GC_OID((*Optimize.c_type)(v9232)),
          _oid_(v9233))));
        princ_string(",");
        (*Generate.expression)(v9396->arg,
          v7180);
        princ_string("");
        } 
      else (*Generate.expression)(v9396->arg,
          v7180);
        princ_string(")");
      } 
    else (*Generate.expression)(v9396->arg,
        v7180);
      } 
  GC_UNBIND;} 

char * gc_protect_class(ClaireClass *v9211)
{ { char *Result ;
    Result = ((v9211 == Kernel._any) ?
      "GC_OID" :
      ((v9211 == Kernel._string) ?
        "GC_STRING" :
        ((v9211 == Kernel._array) ?
          "GC_ARRAY" :
          ((INHERIT(v9211,Kernel._object)) ?
            "GC_OBJECT" :
            "" ) ) ) );
    return (Result);} 
  } 

void  macro_c_producer(Generate_c_producer *v9211)
{ ;} 

void  init_var_c_producer(Generate_c_producer *v9211,ClaireClass *v9233)
{ ;} 

void  any_interface_c_producer(Generate_c_producer *v9211)
{ princ_string("OID");
  } 

void  pointer_cast_c_producer(Generate_c_producer *v9211,ClaireClass *v9233)
{ princ_string("(");
  class_princ_c_producer(v9211,v9233);
  princ_string(" *)");
  } 

void  exp_Assign_c_producer(Generate_c_producer *v9211,Assign *v9396,OID v7180)
{ GC_BIND;
  { OID  v9232 = v9396->arg;
    OID  v9236 = v9396->var;
    (*Language.ident)(Generate.PRODUCER->value,
      v9236);
    princ_string("= ");
    (*Generate.expression)(v9232,
      v7180);
    princ_string("");
    } 
  GC_UNBIND;} 

void  stat_handle_c_producer(Generate_c_producer *v9211,ClaireHandle *v9396,OID v9233,OID v7180)
{ GC_BIND;
  new_block_void();
  princ_string("ClaireHandler c_handle = ClaireHandler();");
  breakline_void();
  princ_string("if ERROR_IN ");
  breakline_void();
  new_block_void();
  statement_any(GC_OID(v9396->arg),v9233,v7180);
  princ_string("ClEnv->cHandle--;");
  close_block_void();
  princ_string("else if (belong_to(_oid_(ClEnv->exception_I),");
  (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(v9396->test),
      _oid_(Kernel._any))),
    _oid_(Kernel.emptySet));
  princ_string(") == CTRUE)");
  breakline_void();
  new_block_void();
  princ_string("c_handle.catchIt();");
  statement_any(GC_OID(v9396->other),v9233,v7180);
  close_block_void();
  princ_string("else PREVIOUS_HANDLER;");
  close_block_void();
  GC_UNBIND;} 

void  stat_construct_c_producer(Generate_c_producer *v9211,Construct *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (boolean_I_any(v9233) != CTRUE)
   close_exception(((general_error *) (*Core._general_error)(_string_("[202] A do should have been used for ~S"),
    _oid_(list::alloc(1,_oid_(v9396))))));
  { char * v9236 = GC_STRING(check_var_string("v_bag",v9233,v7180));
    bag * v9177;
    { ClaireObject *V_CC ;
      if (INHERIT(v9396->isa,Language._List))
       V_CC = list::empty();
      else if (INHERIT(v9396->isa,Language._Set))
       V_CC = set::empty();
      else if (INHERIT(v9396->isa,Language._Tuple))
       V_CC = tuple::empty();
      else close_exception(((general_error *) (*Core._general_error)(_string_("BUG: ~S"),
          _oid_(list::alloc(1,_oid_(v9396))))));
        v9177= (bag *) V_CC;} 
    new_block_void();
    if (get_property(Kernel.of,v9396) != CNULL)
     cast_I_bag(v9177,OBJECT(ClaireType,(*Kernel.of)(_oid_(v9396))));
    { ClaireBoolean * g0090I;
      { OID  v2999;
        { OID gc_local;
          ITERATE(v9232);
          v2999= Kernel.cfalse;
          bag *v9232_support;
          v9232_support = GC_OBJECT(list,v9396->args);
          for (START(v9232_support); NEXT(v9232);)
          if (c_func_any(v9232) != CTRUE)
           { v2999 = Kernel.ctrue;
            break;} 
          } 
        g0090I = boolean_I_any(v2999);
        } 
      
      if (g0090I == CTRUE) { princ_string("OID ");
          princ_string(v9236);
          princ_string(";");
          breakline_void();
          princ_string("");
          } 
        } 
    if (Optimize.OPT->protection == CTRUE)
     { (v9211->stat = (v9211->stat+1));
      princ_string("GC_ANY(");
      } 
    (*Kernel.c_princ)(v9233);
    princ_string("= ");
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(v9177->isa),
      _oid_(v9177),
      GC_OID(_oid_(of_bag(v9177))),
      v7180);
    if (Optimize.OPT->protection == CTRUE)
     princ_string(")");
    princ_string(";");
    { OID gc_local;
      ITERATE(v9232);
      bag *v9232_support;
      v9232_support = GC_OBJECT(list,v9396->args);
      for (START(v9232_support); NEXT(v9232);)
      { ClaireBoolean * v9216 = c_func_any(v9232);
        breakline_void();
        if (v9216 != CTRUE)
         statement_any(v9232,_string_(v9236),v7180);
        princ_string("((");
        { OID  v3960;
          if (INHERIT(v9396->isa,Language._List))
           v3960 = _oid_(Kernel._list);
          else if (INHERIT(v9396->isa,Language._Set))
           v3960 = _oid_(Kernel._set);
          else v3960 = _oid_(Kernel._tuple);
            print_any(v3960);
          } 
        princ_string(" *) ");
        (*Kernel.c_princ)(v9233);
        princ_string(")");
        addFast_c_producer(v9211);
        princ_string("(");
        if (v9216 == CTRUE)
         (*Generate.expression)(v9232,
          v7180);
        else c_princ_string(v9236);
          princ_string(");");
        } 
      } 
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_while_c_producer(Generate_c_producer *v9211,While *v9396,OID v9233,OID v7180)
{ GC_BIND;
  new_block_void();
  { ClaireBoolean * v7169 = ((c_func_any(GC_OID(v9396->test)) == CTRUE) ? ((v9396->other != CTRUE) ? ((gc_usage_any(v9396->test,OBJECT(ClaireBoolean,v7180)) == Kernel.cfalse) ? CTRUE: CFALSE): CFALSE): CFALSE);
    char * v9236 = GC_STRING(check_var_string("v_while",v9233,v7180));
    if (Optimize.OPT->loop_gc == CTRUE)
     { princ_string("OID gc_local;");
      breakline_void();
      princ_string("");
      } 
    if (v7169 != CTRUE)
     { interface_I_class(Kernel._boolean);
      princ_string(v9236);
      princ_string(";");
      breakline_void();
      princ_string("");
      } 
    if (Kernel._string == OWNER(v9233))
     { (*Kernel.c_princ)(v9233);
      princ_string("= _oid_(");
      expression_boolean(CFALSE,v7180);
      princ_string(");");
      breakline_void();
      } 
    if (v7169 == CTRUE)
     { princ_string("while (");
      (*Optimize.bool_exp)(GC_OID(v9396->test),
        _oid_(not_any(_oid_(v9396->other))),
        v7180);
      princ_string(")");
      } 
    else { { OID  v4922;
          { if (v9396->other == CTRUE)
             v4922 = Kernel.cfalse;
            else v4922 = v9396->test;
              GC_OID(v4922);} 
          statement_any(v4922,_string_(v9236),Kernel.ctrue);
          } 
        breakline_void();
        princ_string("while (");
        princ_string(v9236);
        princ_string(" ");
        if (v9396->other == CTRUE)
         princ_string("!=");
        else princ_string("==");
          princ_string(" CTRUE)");
        } 
      breakline_void();
    new_block_void();
    { ClaireBoolean * v7582 = ((Optimize.OPT->loop_gc == CTRUE) ? ((gc_usage_any(v9396->arg,CTRUE) != Kernel.cfalse) ? CTRUE: CFALSE): CFALSE);
      if (v7582 == CTRUE)
       { princ_string("GC_LOOP;");
        breakline_void();
        } 
      { OID  v5882;
        if (Kernel._string == OWNER(v9233))
         v5882 = v9233;
        else v5882 = CNULL;
          inner_statement_any(GC_OID(v9396->arg),_oid_(Kernel.emptySet),v5882);
        } 
      if (v7169 != CTRUE)
       statement_any(GC_OID(v9396->test),_string_(v9236),Kernel.ctrue);
      if (v7582 == CTRUE)
       princ_string("GC_UNLOOP;");
      } 
    close_block_void();
    } 
  close_block_void();
  GC_UNBIND;} 

void  stat_gassign_c_producer(Generate_c_producer *v9211,Gassign *v9396,OID v9233,OID v7180)
{ GC_BIND;
  new_block_void();
  interface_I_c_producer(v9211,((nativeVar_ask_global_variable(v9396->var) == CTRUE) ?
    getRange_global_variable(v9396->var) :
    Kernel._any ));
  princ_string(" truc;");
  statement_any(GC_OID(v9396->arg),_string_("truc"),v7180);
  princ_string("");
  breakline_void();
  if (v9396->var->store_ask == CTRUE)
   { princ_string("STOREI(");
    expression_global_variable(v9396->var,v7180);
    princ_string(",truc);");
    } 
  else { princ_string("(");
      expression_global_variable(v9396->var,v7180);
      princ_string(" = truc);");
      } 
    close_block_void();
  GC_UNBIND;} 

void  stat_for_c_producer(Generate_c_producer *v9211,For *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { char * v9236 = GC_STRING(c_string_c_producer1(v9211,GC_OBJECT(Variable,v9396->var)));
    new_block_void();
    if (Optimize.OPT->loop_gc == CTRUE)
     { princ_string("OID gc_local;");
      breakline_void();
      princ_string("");
      } 
    princ_string("ITERATE(");
    c_princ_string(v9236);
    princ_string(");");
    if (Kernel._string == OWNER(v9233))
     { breakline_void();
      (*Kernel.c_princ)(v9233);
      princ_string("= Kernel.cfalse;");
      } 
    breakline_void();
    if ((c_func_any(GC_OID(v9396->set_arg)) == CTRUE) && 
        (designated_ask_any(GC_OID(v9396->set_arg)) == CTRUE))
     { princ_string("for (START(");
      (*Generate.expression)(GC_OID(v9396->set_arg),
        v7180);
      princ_string("); NEXT(");
      c_princ_string(v9236);
      princ_string(");)");
      } 
    else { char * v7652 = GC_STRING(append_string(v9236,"_support"));
        princ_string("bag *");
        c_princ_string(v7652);
        princ_string(";");
        breakline_void();
        princ_string("");
        statement_any(GC_OID(v9396->set_arg),_string_(v7652),v7180);
        princ_string("for (START(");
        c_princ_string(v7652);
        princ_string("); NEXT(");
        c_princ_string(v9236);
        princ_string(");)");
        } 
      breakline_void();
    { ClaireBoolean * v7582 = ((Optimize.OPT->loop_gc == CTRUE) ? ((gc_usage_any(v9396->arg,CTRUE) != Kernel.cfalse) ? CTRUE: CFALSE): CFALSE);
      if (v7582 == CTRUE)
       { new_block_void();
        princ_string("GC_LOOP;");
        breakline_void();
        } 
      if ((Optimize.OPT->profile_ask == CTRUE) && 
          (_Z_any1(Optimize.OPT->in_method,Kernel._object) == CTRUE))
       { if (v7582 != CTRUE)
         new_block_void();
        princ_string("PRloop(PR_x);");
        breakline_void();
        } 
      { OID  v6850;
        if (Kernel._string == OWNER(v9233))
         v6850 = v9233;
        else v6850 = CNULL;
          statement_any(GC_OID(v9396->arg),_oid_(Kernel.emptySet),v6850);
        } 
      if (v7582 == CTRUE)
       { princ_string("GC_UNLOOP;");
        close_block_void();
        } 
      if ((Optimize.OPT->profile_ask == CTRUE) && 
          ((_Z_any1(Optimize.OPT->in_method,Kernel._object) == CTRUE) && 
            (v7582 != CTRUE)))
       close_block_void();
      close_block_void();
      } 
    } 
  GC_UNBIND;} 

void  stat_iteration_c_producer(Generate_c_producer *v9211,Iteration *v9396,OID v9233,OID v7180)
{ GC_BIND;
  if (boolean_I_any(v9233) != CTRUE)
   close_exception(((general_error *) (*Core._general_error)(_string_("[203] you should have used a FOR here:~S"),
    _oid_(list::alloc(1,_oid_(v9396))))));
  { char * v9236 = GC_STRING(c_string_c_producer1(v9211,GC_OBJECT(Variable,v9396->var)));
    char * v14083 = GC_STRING(check_var_string("v_val",v9233,v7180));
    char * v15135 = GC_STRING(check_var_string("v_list",v9233,v7180));
    new_block_void();
    princ_string("bag *");
    princ_string(v15135);
    princ_string("; OID ");
    princ_string(v14083);
    princ_string(";");
    breakline_void();
    princ_string("");
    princ_string("OID ");
    c_princ_string(v9236);
    princ_string(",CLcount;");
    breakline_void();
    princ_string("");
    statement_any(GC_OID(v9396->set_arg),_string_(v15135),v7180);
    princ_string(" ");
    (*Kernel.c_princ)(v9233);
    princ_string(" = ");
    princ_string(v15135);
    princ_string("->clone(");
    if (get_property(Kernel.of,v9396) != CNULL)
     (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID((*Kernel.of)(_oid_(v9396))),
        _oid_(Kernel._type))),
      Core.nil->value);
    princ_string(")");
    princ_string(";");
    breakline_void();
    princ_string("for (CLcount= 1; CLcount <= ");
    princ_string(v15135);
    princ_string("->length; CLcount++)");
    breakline_void();
    new_block_void();
    c_princ_string(v9236);
    princ_string(" = (*(");
    princ_string(v15135);
    princ_string("))[CLcount];");
    breakline_void();
    statement_any(GC_OID(v9396->arg),_string_(v14083),Kernel.ctrue);
    breakline_void();
    princ_string("(*((list *) ");
    (*Kernel.princ)(v9233);
    princ_string("))[CLcount] = ");
    princ_string(v14083);
    princ_string(";");
    close_block_void();
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_super_c_producer(Generate_c_producer *v9211,Super *v9396,OID v9233,OID v7180)
{ GC_BIND;
  { char * v5673 = GC_STRING(check_var_string("v_rec",v9233,v7180));
    new_block_void();
    princ_string("OID ");
    princ_string(v5673);
    princ_string(";");
    breakline_void();
    { OID gc_local;
      ITERATE(v9232);
      bag *v9232_support;
      v9232_support = GC_OBJECT(list,v9396->args);
      for (START(v9232_support); NEXT(v9232);)
      { statement_any(v9232,_string_(v5673),v7180);
        princ_string("PUSH(");
        princ_string(v5673);
        princ_string(");");
        breakline_void();
        } 
      } 
    if (Kernel._string == OWNER(v9233))
     { c_princ_string(string_v(v9233));
      princ_string("=");
      } 
    expression_thing(v9396->selector,v7180);
    princ_string("->super(");
    (*Generate.expression)(GC_OID(_oid_(v9396->cast_to)),
      v7180);
    princ_string(",");
    princ_integer(v9396->args->length);
    princ_string(");");
    close_block_void();
    } 
  GC_UNBIND;} 

void  stat_let_c_producer(Generate_c_producer *v9211,Let *v9396,OID v9233,OID v7180)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { char * v7469 = GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v9396->var->pname))));
    if ((v7469[1 - 1] == 'C') && 
        (v7469[2 - 1] == '%'))
     (v9396->var->pname = gensym_void());
    } 
  { OID  v9236 = GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
      GC_OID(_oid_(v9396->var))));
    ClaireBoolean * v9210 = Optimize.OPT->alloc_stack;
    OID  v9232 = GC_OID(v9396->value);
    ClaireBoolean * v9216 = CTRUE;
    new_block_void();
    (Optimize.OPT->alloc_stack = CFALSE);
    { OID gc_local;
      while ((v9216 == CTRUE))
      { GC_LOOP;
        if (INHERIT(v9396->isa,Language._Let_star))
         (Optimize.OPT->alloc_stack = CTRUE);
        interface_I_class(sort_Variable(v9396->var));
        princ_string(" ");
        c_princ_string(string_v(v9236));
        princ_string("");
        if (c_func_any(v9232) == CTRUE)
         { princ_string(" = ");
          if (bool_exp_ask_any(v9232) == CTRUE)
           (*Generate.bool_exp_I)(Generate.PRODUCER->value,
            v9232,
            v7180);
          else (*Generate.expression)(v9232,
              v7180);
            princ_string(";");
          breakline_void();
          princ_string("");
          } 
        else { (*Generate.init_var)(Generate.PRODUCER->value,
              _oid_(sort_Variable(v9396->var)));
            princ_string(";");
            breakline_void();
            statement_any(v9232,v9236,v7180);
            princ_string("");
            } 
          if (INHERIT(v9396->isa,Language._Let_star))
         (Optimize.OPT->alloc_stack = CFALSE);
        if (INHERIT(OWNER(v9396->arg),Language._Let))
         { GC__ANY(v9396 = OBJECT(Let,v9396->arg), 2);
          GC__OID(v9236 = (*Generate.c_string)(Generate.PRODUCER->value,
            GC_OID(_oid_(v9396->var))), 5);
          GC__OID(v9232 = v9396->value, 7);
          } 
        else v9216= CFALSE;
          GC_UNLOOP;} 
      } 
    (Optimize.OPT->alloc_stack = v9210);
    inner_statement_any(GC_OID(v9396->arg),v9233,v7180);
    princ_string("");
    close_block_void();
    } 
  GC_UNBIND;} 

