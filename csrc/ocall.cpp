/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\ocall.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:46 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
OID  restriction_I_property(property *v1140,list *v7236,ClaireBoolean *v11979)
{ { int  v7233 = 1;
    int  v6847 = v7236->length;
    { while ((v7233 <= v6847))
      { ((*(v7236))[v7233]=_oid_(ptype_type(OBJECT(ClaireType,(*(v7236))[v7233]))));
        ++v7233;
        } 
      } 
    } 
  return (restriction_I_list(v1140->definition,v7236,v11979));} 

OID  restriction_I_list(list *v11438,list *v7236,ClaireBoolean *v11979)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  ;{ OID Result = 0;
    { ClaireBoolean * v460 = ((class_I_type(OBJECT(ClaireType,(*(v7236))[1]))->open == 3) ? CTRUE : CFALSE);
      OID  v15989 = _oid_(Kernel.emptySet);
      { OID gc_local;
        ITERATE(v7242);
        for (START(v11438); NEXT(v7242);)
        { GC_LOOP;
          if ((boolean_I_any(v15989) != CTRUE) && 
              (tmatch_ask_list(v7236,OBJECT(restriction,v7242)->domain) == CTRUE))
           { if (v11979 == CTRUE)
             GC__OID(v15989 = v7242, 1);
            else v15989= _oid_(OBJECT(restriction,v7242)->range);
              { ;break;} 
            } 
          else if (length_bag(_exp_list(OBJECT(restriction,v7242)->domain,v7236)) != 0)
           { if (v11979 != CTRUE)
             { GC__OID(v15989 = _oid_(U_type(OBJECT(ClaireType,v15989),OBJECT(restriction,v7242)->range)), 1);
              } 
            else if ((Optimize.compiler->safety <= 3) || 
                ((equal(v15989,_oid_(Kernel.emptySet)) != CTRUE) || 
                  (v460 == CTRUE)))
             { v15989= _oid_(Optimize.ambiguous);
              { ;break;} 
              } 
            else GC__OID(v15989 = v7242, 1);
              } 
          GC_UNLOOP;} 
        } 
      Result = v15989;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  restriction_I_class(ClaireClass *v7227,list *v11438,list *v7236)
{ if (Optimize.compiler->safety > 3)
   ((*(v7236))[1]=_oid_(_exp_type(v7227,OBJECT(ClaireType,(*(v7236))[1]))));
  { OID Result = 0;
    { ITERATE(v7242);
      Result= Kernel.cfalse;
      for (START(v11438); NEXT(v7242);)
      if (_inf_equalt_class(v7227,OBJECT(ClaireType,(*(OBJECT(restriction,v7242)->domain))[1])) == CTRUE)
       { if (tmatch_ask_list(v7236,OBJECT(restriction,v7242)->domain) == CTRUE)
         { Result = v7242;
          break;} 
        else if (length_bag(_exp_list(OBJECT(restriction,v7242)->domain,v7236)) != 0)
         { Result = _oid_(Optimize.ambiguous);
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireType * use_range_method(method *v1140,list *v9231)
{ GC_BIND;
  { ClaireType *Result ;
    if ((v1140->inline_ask == CTRUE) && 
        (v1140->typing == CNULL))
     { list * v11442 = GC_OBJECT(list,v1140->formula->vars);
      ClaireType * v9239 = Kernel._any;
      list * v7683;
      { { bag *v_list; OID v_val;
          OID v7246,CLcount;
          v_list = v11442;
           v7683 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7246 = (*(v_list))[CLcount];
            v_val = (*Kernel.range)(v7246);
            
            (*((list *) v7683))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v7683);} 
      { ITERATE(v7246);
        for (START(v11442); NEXT(v7246);)
        put_property2(Kernel.range,OBJECT(ClaireObject,v7246),(*(v9231))[(((*Kernel.index)(v7246))+1)]);
        } 
      v9239= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->formula->body))));
      { ITERATE(v7246);
        for (START(v11442); NEXT(v7246);)
        put_property2(Kernel.range,OBJECT(ClaireObject,v7246),(*(v7683))[(((*Kernel.index)(v7246))+1)]);
        } 
      if (INHERIT(v1140->range->isa,Kernel._type))
       v9239= GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v9239),
        _oid_(v1140->range))));
      if (boolean_I_any(_oid_(v9239)) != CTRUE)
       (*Optimize.Cerror)(_string_("[207] inline ~S: range ~S is incompatible with ~S (inferred)"),
        _oid_(v1140),
        _oid_(v1140->range),
        GC_OID((*Optimize.c_type)(GC_OID(v1140->formula->body))));
      Result = v9239;
      } 
    else { { OID  v7230 = GC_OID(v1140->typing);
          list * v7683;
          { { bag *v_list; OID v_val;
              OID v7245,CLcount;
              v_list = v9231;
               v7683 = v_list->clone(Kernel._type);
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7245 = (*(v_list))[CLcount];
                v_val = _oid_(ptype_type(OBJECT(ClaireType,v7245)));
                
                (*((list *) v7683))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v7683);} 
          ClaireType * v7930 = v1140->range;
          ClaireType * v7931;
          { { ClaireObject *V_CC ;
              { ClaireHandler c_handle = ClaireHandler();
                if ERROR_IN 
                { if (INHERIT(OWNER(v7230),Core._lambda))
                   V_CC = OBJECT(ClaireType,apply_lambda(OBJECT(lambda,v7230),v7683));
                  else if (INHERIT(OWNER(v7230),Kernel._property))
                   V_CC = OBJECT(ClaireType,apply_property(OBJECT(property,v7230),v7683));
                  else if (INHERIT(OWNER(v7230),Kernel._function))
                   { OID v15730;{ list * v13664;
                      { list * v13455 = list::empty(Kernel.emptySet);
                        { int  v7239 = 1;
                          int  v6848 = (v9231->length+1);
                          { while ((v7239 <= v6848))
                            { v13455->addFast(_oid_(Kernel._object));
                              ++v7239;
                              } 
                            } 
                          } 
                        v13664 = GC_OBJECT(list,v13455);
                        } 
                      v15730 = apply_function(OBJECT(ClaireFunction,v7230),v13664,v7683);
                      } 
                    
                    V_CC=OBJECT(ClaireType,v15730);} 
                  else V_CC = v7930;
                    ClEnv->cHandle--;} 
                else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
                { c_handle.catchIt();{ tformat_string("~S's 2nd-order type failed on ~S \n",0,list::alloc(2,_oid_(v1140),_oid_(v9231)));
                    V_CC = v7930;
                    } 
                  } 
                else PREVIOUS_HANDLER;} 
              v7931= (ClaireType *) V_CC;} 
            GC_OBJECT(ClaireType,v7931);} 
          if ((boolean_I_any(sort_equal_class(osort_any(_oid_(v7930)),osort_any(_oid_(v7931)))) == CTRUE) || 
              (v1140->selector == Core.externC))
           Result = v7931;
          else if (boolean_I_any(sort_equal_class(Kernel._any,osort_any(_oid_(v7930)))) == CTRUE)
           { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
            (v2072->t1 = Kernel._any);
            (v2072->t2 = v7931);
            Result = v2072;
            } 
          else Result = v7930;
            } 
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_Optimize(Call *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (v1140->selector == Language.function_I)
       V_CC = Kernel._function;
      else { property * v7243 = v1140->selector;
          list * v7236 = GC_OBJECT(list,v1140->args);
          list * v9399;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = v7236;
               v9399 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7248);
                
                (*((list *) v9399))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v9399);} 
          if (v7243 == Optimize.safe)
           V_CC = OBJECT(ClaireType,(*(v9399))[1]);
          else if ((v7243 == Core.externC) && 
              ((v7236->length == 2) && 
                (INHERIT(OWNER((*(v7236))[2]),Kernel._class))))
           V_CC = OBJECT(ClaireClass,(*(v7236))[2]);
          else if ((v7243 == Core.NEW) && 
              (INHERIT(OWNER((*(v7236))[1]),Kernel._class)))
           V_CC = OBJECT(ClaireClass,(*(v7236))[1]);
          else if ((v7243 == Core.check_in) && 
              (INHERIT(OWNER((*(v7236))[2]),Kernel._type)))
           { V_CC = ((v7236->length == 2) ?
              sort_abstract_I_type(OBJECT(ClaireType,(*(v7236))[2])) :
              OBJECT(ClaireType,(*(v7236))[2]) );
            } 
          else if ((v7243 == Kernel.nth) && 
              (_inf_equal_type(OBJECT(ClaireType,(*(v9399))[1]),Kernel._array) == CTRUE))
           { if (_inf_equal_type(GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,(*(v9399))[1]))),Kernel._float) == CTRUE)
             V_CC = Kernel._float;
            else V_CC = member_type(OBJECT(ClaireType,(*(v9399))[1]));
              } 
          else if ((v7243 == Core._at) && 
              (INHERIT(OWNER((*(v7236))[1]),Kernel._property)))
           { property * v7240 = OBJECT(property,(*(v7236))[1]);
            OID  v7227 = (*(v7236))[2];
            if ((INHERIT(OWNER(v7227),Kernel._class)) && 
                (Kernel._method == owner_any((*Core._at)(_oid_(v7240),
                  v7227))))
             V_CC = set::alloc(1,GC_OID((*Core._at)(_oid_(v7240),
              v7227)));
            else V_CC = Kernel._any;
              } 
          else if ((v7243 == Kernel.get) && 
              (INHERIT(OWNER((*(v7236))[1]),Kernel._relation)))
           { ClaireRelation * v7242 = OBJECT(ClaireRelation,(*(v7236))[1]);
            if (INHERIT(v7242->isa,Kernel._property))
             { ClaireObject * v11811 = GC_OBJECT(ClaireObject,_at_property1(((property *) v7242),class_I_type(OBJECT(ClaireType,(*(v9399))[2]))));
              if (Kernel._slot == v11811->isa)
               { if ((_inf_equal_type(CLREAD(restriction,v11811,range),Kernel._bag) == CTRUE) && 
                    (Optimize.compiler->safety < 3))
                 V_CC = class_I_type(OBJECT(ClaireType,(*Kernel.range)((*(v7236))[2])));
                else V_CC = ((belong_to(CLREAD(slot,v11811,DEFAULT),_oid_(CLREAD(restriction,v11811,range))) == CTRUE) ?
                  CLREAD(restriction,v11811,range) :
                  extends_type(CLREAD(restriction,v11811,range)) );
                } 
              else V_CC = v7242->range;
                } 
            else if (INHERIT(v7242->isa,Kernel._table))
             { V_CC = ((belong_to(CLREAD(table,v7242,DEFAULT),_oid_(v7242->range)) == CTRUE) ?
                v7242->range :
                extends_type(v7242->range) );
              } 
            else V_CC = CFALSE;
              } 
          else { OID  v7242 = GC_OID(restriction_I_property(v7243,v9399,CTRUE));
              if (Kernel._slot == OWNER(v7242))
               { if ((v7243 == Kernel.instances) && 
                    (INHERIT(OWNER((*(v7236))[1]),Kernel._class)))
                 { Param * v2072 = ((Param *) GC_OBJECT(Param,new_object_class(Core._Param)));
                  (v2072->arg = Kernel._list);
                  (v2072->params = list::alloc(1,_oid_(Kernel.of)));
                  (v2072->args = list::alloc(1,_oid_(set::alloc(1,(*(v7236))[1]))));
                  V_CC = v2072;
                  } 
                else V_CC = OBJECT(restriction,v7242)->range;
                  } 
              else if (Kernel._method == OWNER(v7242))
               V_CC = use_range_method(OBJECT(method,v7242),v9399);
              else if (boolean_I_any(_oid_(v7243->restrictions)) != CTRUE)
               V_CC = selector_psort_Call(v1140);
              else V_CC = (((v7243->open == 3) || 
                  (v7242 != _oid_(Optimize.ambiguous))) ?
                sort_abstract_I_type(v7243->range) :
                sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,restriction_I_property(v7243,v9399,CFALSE)))) );
              } 
            } 
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_Optimize(Call *v1140)
{ return (c_code_call_Call(v1140,Kernel._void));} 

OID  c_code_call_Call(Call *v1140,ClaireClass *v11661)
{ GC_BIND;
  ;{ OID Result = 0;
    { property * v7243 = v1140->selector;
      list * v7236 = GC_OBJECT(list,v1140->args);
      if ((INHERIT(OWNER((*(v7236))[1]),Core._global_variable)) && 
          ((equal((*Kernel.range)((*(v7236))[1]),_oid_(Kernel.emptySet)) == CTRUE) && 
            (designated_ask_any(GC_OID((*Kernel.value)((*(v7236))[1]))) == CTRUE)))
       ((*(v7236))[1]=(*Kernel.value)((*(v7236))[1]));
      { OID  v7237 = GC_OID(inline_optimize_ask_Call(v1140));
        ClaireBoolean * v7226 = inherit_ask_class(OWNER((*(v7236))[1]),Kernel._property);
        OID  v7228 = GC_OID(daccess_any(_oid_(v1140),_sup_integer(Optimize.compiler->safety,5)));
        if ((v7226 == CTRUE) && 
            (((v7243 == Kernel.put) || 
                (v7243 == Core.write)) && 
              (v7236->length == 3)))
         Result = c_code_write_Call(v1140);
        else if ((v7226 == CTRUE) && 
            ((v7243 == Core.put_store) && 
              ((v7236->length == 4) && 
                ((*(v7236))[4] == Kernel.ctrue))))
         Result = c_code_write_Call(v1140);
        else if ((v7226 == CTRUE) && 
            (v7243 == Core.unknown_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v7236))[1]),(*(v7236))[2],CNULL,CTRUE);
        else if ((v7226 == CTRUE) && 
            (v7243 == Core.known_ask))
         Result = c_code_hold_property(OBJECT(property,(*(v7236))[1]),(*(v7236))[2],CNULL,CFALSE);
        else if ((v7226 == CTRUE) && 
            ((v7243 == Core.erase) && 
              (INHERIT(OWNER((*(v7236))[2]),Language._Variable))))
         Result = (*Optimize.c_code)(GC_OID(Produce_erase_property2(OBJECT(property,(*(v7236))[1]),OBJECT(Variable,(*(v7236))[2]))),
          _oid_(v11661));
        else if (v7243 == Optimize.safe)
         { int  v7249 = Optimize.compiler->safety;
          ClaireBoolean * v7226 = Optimize.compiler->overflow_ask;
          OID  v7248 = CNULL;
          (Optimize.compiler->safety = 1);
          (Optimize.compiler->overflow_ask = CTRUE);
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Optimize.safe);
              (v2072->args = list::alloc(1,GC_OID((*Optimize.c_code)((*(v7236))[1],
                _oid_(v11661)))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v7248 = _oid_(v2072);
              } 
            GC_OID(v7248);} 
          (Optimize.compiler->safety = v7249);
          (Optimize.compiler->overflow_ask = v7226);
          Result = v7248;
          } 
        else if (((v7243 == Kernel.add) || 
              (v7243 == Kernel.add_I)) && 
            (v7226 == CTRUE))
         Result = c_code_add_Call(v1140);
        else if (((v7243 == Kernel.add) || 
              (v7243 == Kernel.add_I)) && 
            (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v7236))[1]))),Kernel._bag) == CTRUE))
         Result = c_code_add_bag_Call(v1140);
        else if ((v7226 == CTRUE) && 
            (v7243 == Kernel._delete))
         Result = c_code_delete_Call(v1140);
        else if ((contain_ask_set(Optimize.OPT->to_remove,_oid_(v7243)) == CTRUE) || 
            ((v7243 == Optimize.c_interface) && 
                ((v7236->length == 2) && 
                  (contain_ask_set(Optimize.OPT->legal_modules,get_module_object(v7243)) != CTRUE))))
         Result = Core.nil->value;
        else if (v7228 != CNULL)
         Result = v7228;
        else if (Kernel._method == OWNER(v7237))
         Result = c_inline_method1(OBJECT(method,v7237),v7236,c_srange_method(OBJECT(method,v7237)));
        else if (((v7243 == Kernel._equal) || 
              (v7243 == Core._I_equal)) && 
            (daccess_any((*(v7236))[1],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v7236))[1]))))[1]),GC_OID((*(OBJECT(bag,(*Core.args)((*(v7236))[1]))))[2]),(*(v7236))[2],equal(_oid_(v7243),_oid_(Kernel._equal)));
        else if (((v7243 == Kernel._equal) || 
              (v7243 == Core._I_equal)) && 
            (daccess_any((*(v7236))[2],CTRUE) != CNULL))
         Result = c_code_hold_property(OBJECT(property,(*(OBJECT(bag,(*Core.args)((*(v7236))[2]))))[1]),GC_OID((*(OBJECT(bag,(*Core.args)((*(v7236))[2]))))[2]),(*(v7236))[1],equal(_oid_(v7243),_oid_(Kernel._equal)));
        else if (((v7243 == Kernel.nth_equal) || 
              (v7243 == Kernel.put)) && 
            ((INHERIT(OWNER((*(v7236))[1]),Kernel._table)) && 
              (v7236->length == 3)))
         Result = c_code_table_Call(v1140);
        else if (((v7243 == Kernel.nth_put) || 
              (v7243 == Kernel.nth_equal)) && 
            ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v7236))[1]))),Kernel._array) == CTRUE) && 
              (v7236->length == 3)))
         Result = c_code_array_Call(v1140);
        else if ((v7243 == Kernel.nth) || 
            (((v7243 == Kernel.get) && 
                (INHERIT(OWNER((*(v7236))[1]),Kernel._table))) || 
              ((v7243 == Kernel.nth_get) && 
                  (Kernel._array == OWNER((*(v7236))[1])))))
         Result = c_code_nth_Call(v1140);
        else if (v7243 == Kernel._Z)
         Result = c_code_belong_Call(v1140);
        else if (v7243 == Core.Id)
         Result = (*Optimize.c_code)(GC_OID(OPT_EVAL((*(v7236))[1])));
        else if (v7243 == Language.function_I)
         Result = _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(v7236))[1]))));
        else if ((v7243 == Core.NOT) && 
            (INHERIT(OWNER((*(v7236))[1]),Language._Select)))
         Result = c_code_not_Select(OBJECT(Select,(*(v7236))[1]));
        else if ((v7243 == Core.call) && 
            (INHERIT(OWNER((*(v7236))[1]),Kernel._property)))
         { OID  v2038;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            update_property(Kernel.selector,
              v2072,
              2,
              Kernel._object,
              (*(v7236))[1]);
            (v2072->args = cdr_list(v7236));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v2038 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v2038);
          } 
        else if (v7243->open == 3)
         { list * v2999;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = v7236;
               v2999 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7248);
                
                (*((list *) v2999))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v2999);} 
          Result = c_warn_property(v7243,v7236,v2999);
          } 
        else { ClaireBoolean * g0092I;
          { ClaireBoolean *v_and;
            { v_and = ((v7243 == Language.bit_vector) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0092I =CFALSE; 
              else { { OID  v4922;
                  { OID gc_local;
                    ITERATE(v7249);
                    v4922= Kernel.cfalse;
                    bag *v7249_support;
                    v7249_support = GC_OBJECT(list,v1140->args);
                    for (START(v7249_support); NEXT(v7249);)
                    if (inherit_ask_class(OWNER(v7249),Kernel._integer) != CTRUE)
                     { v4922 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = not_any(v4922);
                  } 
                if (v_and == CFALSE) g0092I =CFALSE; 
                else g0092I = CTRUE;} 
              } 
            } 
          
          if (g0092I == CTRUE) Result = OPT_EVAL(_oid_(v1140));
            else if ((v7243 == Optimize.anyObject_I) || 
              ((v7243 == Optimize.object_I) || 
                ((v7243 == Kernel.add_method) && 
                    (v7226 == CTRUE))))
           Result = _oid_(v1140);
          else { list * v9399;
              { { bag *v_list; OID v_val;
                  OID v7248,CLcount;
                  v_list = v7236;
                   v9399 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v7248 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_type)(v7248);
                    
                    (*((list *) v9399))[CLcount] = v_val;} 
                  } 
                GC_OBJECT(list,v9399);} 
              OID  v7250 = GC_OID(restriction_I_property(v7243,v9399,CTRUE));
              if (Kernel._slot == OWNER(v7250))
               { ClaireBoolean * v2477 = ((belong_to(OBJECT(slot,v7250)->DEFAULT,_oid_(OBJECT(restriction,v7250)->range)) != CTRUE) ? ((contain_ask_set(Optimize.OPT->knowns,_oid_(v7243)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE): CFALSE);
                if ((v2477 != CTRUE) || 
                    (designated_ask_any((*(v7236))[1]) == CTRUE))
                 { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                  (v2072->selector = OBJECT(slot,v7250));
                  (v2072->arg = (*Optimize.c_code)((*(v7236))[1],
                    _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v7250)))))));
                  (v2072->test = v2477);
                  add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                  Result = _oid_(v2072);
                  } 
                else { if (Optimize.compiler->optimize_ask == CTRUE)
                     { notice_void();
                      ;} 
                    Result = c_warn_property(v7243,v7236,v9399);
                    } 
                  } 
              else if (Kernel._method == OWNER(v7250))
               { if (v7243 == Kernel.nth_equal)
                 (Optimize.OPT->use_nth_equal = CTRUE);
                if (v9399->memq(_oid_(Kernel._void)) == CTRUE)
                 (*Optimize.Cerror)(_string_("[205] call ~S uses a void argument [~S]"),
                  _oid_(v1140),
                  _oid_(v9399));
                if (((v7243 == Kernel.begin) || 
                      (v7243 == Kernel.end)) && 
                    (INHERIT(OWNER((*(v7236))[1]),Kernel._module)))
                 OPT_EVAL(_oid_(v1140));
                if ((last_list(OBJECT(restriction,v7250)->domain) == _oid_(Kernel._listargs)) || 
                    (((*(OBJECT(restriction,v7250)->domain))[1] == _oid_(Kernel._void)) && 
                        ((*(v7236))[1] != _oid_(ClEnv))))
                 Result = _oid_(open_message_property(v7243,v7236));
                else Result = c_code_method_method2(OBJECT(method,v7250),v7236,v9399,v11661);
                  } 
              else if (INHERIT(OWNER(v7250),Kernel._keyword))
               Result = c_warn_property(v7243,v7236,v9399);
              else Result = c_warn_Call(v1140,_oid_(v9399));
                } 
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

Call * open_message_property(property *v1140,list *v7236)
{ GC_BIND;
  selector_register_property(v1140);
  { Call *Result ;
    { list * v313;
      { { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = v7236;
           v313 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            if ((*Optimize.c_type)(v7248) != _oid_(Kernel._void))
             v_val = (*Optimize.c_code)(v7248,
              _oid_(Kernel._any));
            else v_val = (*Optimize.Cerror)(_string_("[206] use of void ~S in ~S~S"),
                v7248,
                _oid_(v1140),
                _oid_(v7236));
              
            (*((list *) v313))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v313);} 
      if (Optimize.OPT->allocation == CTRUE)
       { { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = v313;
           v313 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v7248);
            
            (*((list *) v313))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v313);} 
      { ClaireBoolean * g0094I;
        { ClaireBoolean *v_and;
          { v_and = Optimize.compiler->diet_ask;
            if (v_and == CFALSE) g0094I =CFALSE; 
            else { { OID  v6850;
                { ITERATE(v7248);
                  v6850= Kernel.cfalse;
                  for (START(v7236); NEXT(v7248);)
                  if ((INHERIT(OWNER(v7248),Kernel._class)) || 
                      (INHERIT(OWNER(v7248),Kernel._property)))
                   { v6850 = Kernel.ctrue;
                    break;} 
                  } 
                v_and = boolean_I_any(v6850);
                } 
              if (v_and == CFALSE) g0094I =CFALSE; 
              else g0094I = CTRUE;} 
            } 
          } 
        
        if (g0094I == CTRUE) { warn_void();
            tformat_string("Non diet call ~S(~A) [254]\n",2,list::alloc(2,_oid_(v1140),_oid_(v7236)));
            } 
          } 
      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = v1140);
        (v2072->args = v313);
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        Result = v2072;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call(Call *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((v1140->selector == Language.function_I) ? CTRUE : (((v1140->selector == Optimize.safe) ? ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)((*(v1140->args))[1]))) == CTRUE) : (((stable_ask_relation(v1140->selector) == CTRUE) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(v1140->selector->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v1140->selector->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v1140->selector->range))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

OID  daccess_any(OID v1140,ClaireBoolean *v7226)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v1140),Language._Call))
     { list * v7236 = GC_OBJECT(list,OBJECT(Call,v1140)->args);
      ClaireObject * v11811;
      { if ((OBJECT(Call,v1140)->selector == Kernel.get) && 
            (INHERIT(OWNER((*(v7236))[1]),Kernel._property)))
         v11811 = _at_property1(OBJECT(property,(*(v7236))[1]),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)((*(v7236))[2]))));
        else v11811 = CFALSE;
          GC_OBJECT(ClaireObject,v11811);} 
      if ((Kernel._slot == v11811->isa) && ((v7226 == CTRUE) || 
          ((belong_to(CLREAD(slot,v11811,DEFAULT),_oid_(CLREAD(restriction,v11811,range))) == CTRUE) || 
            ((CLREAD(slot,v11811,srange) == Kernel._any) || 
              (CLREAD(slot,v11811,srange) == Kernel._integer)))))
       { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v2072->selector = ((slot *) v11811));
        (v2072->arg = (*Optimize.c_code)((*(v7236))[2],
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v11811)))))));
        (v2072->test = CFALSE);
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else Result = CNULL;
        } 
    else Result = CNULL;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Call_slot(Call_slot *v1140)
{ { ClaireBoolean *Result ;
    { slot * v7243 = v1140->selector;
      OID  v7248 = v1140->arg;
      Result = ((_oid_((INHERIT(v7243->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v7243->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v7243->range))))) != Kernel.ctrue) ? ((v7243->range != Kernel._float) ? (((1 <= v7243->selector->open) || 
          (gcsafe_ask_class(domain_I_restriction(v7243)) != CTRUE)) ? CTRUE: CFALSE): CFALSE): CFALSE);
      } 
    return (Result);} 
  } 

ClaireType * c_type_Call_slot_Optimize(Call_slot *v1140)
{ return (v1140->selector->range);} 

ClaireType * c_type_Call_table_Optimize(Call_table *v1140)
{ return (v1140->selector->range);} 

ClaireType * c_type_Call_array_Optimize(Call_array *v1140)
{ return (OBJECT(ClaireType,v1140->test));} 

OID  c_code_write_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7240 = GC_OID((*(v1140->args))[1]);
      OID  v7248 = GC_OID((*(v1140->args))[2]);
      OID  v7249 = GC_OID((*(v1140->args))[3]);
      OID  v11843 = GC_OID((*Optimize.c_type)(v7249));
      property * v11656 = v1140->selector;
      OID  v7243 = GC_OID((*Optimize.restriction_I)(v7240,
        _oid_(list::alloc(1,GC_OID((*Optimize.c_type)(v7248)))),
        Kernel.ctrue));
      (Optimize.OPT->use_update = CTRUE);
      if (contain_ask_set(Optimize.OPT->to_remove,v7240) == CTRUE)
       Result = Core.nil->value;
      else if ((Kernel._slot == OWNER(v7243)) && ((_inf_equal_type(OBJECT(ClaireType,v11843),OBJECT(restriction,v7243)->range) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if ((v7249 != CNULL) && 
            (boolean_I_any((*Kernel._exp)(v11843,
              GC_OID((*Kernel.srange)(v7243)))) != CTRUE))
         { warn_void();
          tformat_string("sort error in ~S: ~S is a ~S [253]\n",2,list::alloc(3,_oid_(v1140),
            v7249,
            v11843));
          } 
        if (((_inf_equal_type(OBJECT(ClaireType,v11843),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v7243)))) == CTRUE) || 
              ((_inf_equal_type(OBJECT(ClaireType,v11843),Kernel._object) == CTRUE) || 
                (((*Kernel.srange)(v7243) != _oid_(Kernel._object)) || 
                  (v7249 == CNULL)))) && 
            ((v11656 != Core.write) || 
                ((Update_ask_relation(OBJECT(ClaireRelation,v7240),v7248,v7249) == CTRUE) && 
                    ((OBJECT(ClaireRelation,v7240)->multivalued_ask == CFALSE) || 
                        (get_property(Kernel.if_write,OBJECT(ClaireObject,v7240)) == CNULL)))))
         { OID  v9243 = GC_OID((*Optimize.c_code)(v7248,
            _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v7243)))))));
          OID  v9244 = GC_OID(c_strict_code_any(v7249,psort_any((*Kernel.range)(v7243))));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = v7240);
          (v2072->value = v9244);
          { Update * v6876 = v2072; 
            OID  v6878;
            if (v11656 != Core.write)
             v6878 = _oid_(v11656);
            else v6878 = (*Optimize.c_code)(v7248,
                _oid_(Kernel._any));
              (v6876->arg = v6878);} 
          { Update * v6879 = v2072; 
            OID  v6880;
            { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              update_property(Kernel.selector,
                v2072,
                2,
                Kernel._object,
                v7243);
              (v2072->arg = v9243);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
              v6880 = _oid_(v2072);
              } 
            (v6879->var = v6880);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if (v11656 == Kernel.put)
         { OID  v2080;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.store);
            (v2072->args = list::alloc(5,v7248,
              (*Kernel.index)(v7243),
              GC_OID((*Kernel.srange)(v7243)),
              v7249,
              GC_OID((*Kernel.store_ask)(v7240))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v2080 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v2080);
          } 
        else { if (Optimize.compiler->diet_ask == CTRUE)
             { warn_void();
              tformat_string("~S is not a diet call [254]",2,list::alloc(1,_oid_(v1140)));
              } 
            if ((Optimize.compiler->optimize_ask == CTRUE) && 
                (v7240 != _oid_(Kernel.instances)))
             { notice_void();
              ;} 
            { OID  v3041;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.update);
                (v2072->args = list::alloc(5,v7240,
                  v7248,
                  (*Kernel.index)(v7243),
                  GC_OID((*Kernel.srange)(v7243)),
                  v7249));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v3041 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v3041);
              } 
            } 
          } 
      else { list * v9399;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = GC_OBJECT(list,v1140->args);
               v9399 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7248);
                
                (*((list *) v9399))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v9399);} 
          OID  v7250 = GC_OID(restriction_I_property(v11656,v9399,CTRUE));
          if (Kernel._method == OWNER(v7250))
           Result = c_code_method_method1(OBJECT(method,v7250),GC_OBJECT(list,v1140->args),v9399);
          else Result = c_warn_Call(v1140,_oid_(v9399));
            } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_hold_property(property *v7240,OID v7248,OID v7249,ClaireBoolean *v7226)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7243 = GC_OID(restriction_I_property(v7240,list::alloc(1,GC_OID((*Optimize.c_type)(v7248))),CTRUE));
      if ((Kernel._slot == OWNER(v7243)) && ((v7249 == CNULL) || 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7249))),OBJECT(slot,v7243)->srange) == CTRUE) && 
              (identifiable_ask_any(v7249) == CTRUE))))
       { Call_slot * v11160;
        { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
            update_property(Kernel.selector,
              v2072,
              2,
              Kernel._object,
              v7243);
            (v2072->arg = (*Optimize.c_code)(v7248,
              _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v7243)))))));
            (v2072->test = CFALSE);
            add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
            v11160 = v2072;
            } 
          GC_OBJECT(Call_slot,v11160);} 
        Call_method2 * v11154;
        { { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v2072->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
            (v2072->args = list::alloc(2,_oid_(v11160),GC_OID((*Optimize.c_code)(v7249,
              GC_OID((*Kernel.srange)(v7243))))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
            v11154 = v2072;
            } 
          GC_OBJECT(Call_method2,v11154);} 
        if (v7226 == CTRUE)
         Result = (*Optimize.c_code)(_oid_(v11154));
        else { OID  v4004;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.NOT);
              (v2072->args = list::alloc(1,_oid_(v11154)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v4004 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v4004);
            } 
          } 
      else { list * v7236 = list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any));
          { list * v4963;
            { OID v_bag;
              GC_ANY(v4963= list::empty(Kernel.emptySet));
              { { OID  v5924;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.get);
                    (v2072->args = list::alloc(2,_oid_(v7240),v7248));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v5924 = _oid_(v2072);
                    } 
                  v_bag = (*Optimize.c_code)(v5924,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v4963)->addFast(v_bag);
              ((list *) v4963)->addFast(GC_OID((*Optimize.c_code)(v7249,
                _oid_(Kernel._any))));} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(((v7226 == CTRUE) ?
              Kernel._equal :
              Core._I_equal ),v7236))),v4963,v7236);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { property * v7240 = OBJECT(property,(*(v1140->args))[1]);
      OID  v7248 = GC_OID((*(v1140->args))[2]);
      OID  v7249 = GC_OID((*(v1140->args))[3]);
      ClaireObject * v7243 = GC_OBJECT(ClaireObject,_at_property1(v7240,class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v7248))))));
      (Optimize.OPT->use_update = CTRUE);
      if ((Kernel._slot == v7243->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7249))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v7243,range)))) == CTRUE) || 
          (4 <= Optimize.compiler->safety)))
       { if (Update_ask_relation2(v7240,v1140->selector) == CTRUE)
         { OID  v11746 = GC_OID((*Optimize.c_code)(v7248,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v7243)))))));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = _oid_(v7240));
          (v2072->arg = _oid_(Kernel.add));
          { Update * v7557 = v2072; 
            OID  v7558;
            { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
              (v2072->selector = ((slot *) v7243));
              (v2072->arg = v11746);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
              v7558 = _oid_(v2072);
              } 
            (v7557->var = v7558);} 
          (v2072->value = (*Optimize.c_code)(v7249,
            _oid_(psort_any(_oid_(member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v7243))))))))));
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if ((designated_ask_any(v7248) == CTRUE) && 
            ((v7240->store_ask != CTRUE) && 
                ((v1140->selector == Kernel.add_I) || 
                    (v7240->inverse == (NULL)))))
         { OID  v11746 = GC_OID((*Optimize.c_code)(v7248,
            _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v7243)))))));
          { OID  v8807;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.add);
              { Call * v7561 = v2072; 
                list * v7562;
                { OID v_bag;
                  GC_ANY(v7562= list::empty(Kernel.emptySet));
                  { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                      (v2072->selector = ((slot *) v7243));
                      (v2072->arg = v11746);
                      (v2072->test = CFALSE);
                      add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v7562)->addFast(v_bag);
                  ((list *) v7562)->addFast(v7249);} 
                (v7561->args = v7562);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v8807 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v8807);
            } 
          } 
        else { if (Optimize.compiler->optimize_ask == CTRUE)
             { notice_void();
              ;} 
            Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add_I,Kernel._property))),list::alloc(4,_oid_(v7240),
              v7248,
              (*Kernel.index)(_oid_(v7243)),
              v7249),list::alloc(4,_oid_(Kernel._property),
              GC_OID((*Optimize.c_type)(v7248)),
              _oid_(Kernel._integer),
              GC_OID((*Optimize.c_type)(v7249))));
            } 
          } 
      else { list * v15487;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = GC_OBJECT(list,v1140->args);
               v15487 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7248);
                
                (*((list *) v15487))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v15487);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.add,Kernel._property))),GC_OBJECT(list,v1140->args),v15487);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_add_bag_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7930 = GC_OID((*Optimize.c_type)(GC_OID((*(v1140->args))[1])));
      ClaireType * v7931 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*(v1140->args))[2])))));
      property * v9235;
      if (((INHERIT(OBJECT(ClaireObject,v7930)->isa,Core._Param)) && 
            (_inf_equal_type(v7931,GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v7930)))) == CTRUE)) || 
          (4 <= Optimize.compiler->safety))
       v9235 = Kernel.add_I;
      else v9235 = v1140->selector;
        list * v5065 = list::alloc(2,v7930,_oid_(v7931));
      OID  v7250 = GC_OID(restriction_I_property(v9235,v5065,CTRUE));
      if ((_inf_equal_type(v7931,GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v7930)))) != CTRUE) && 
          (v1140->selector == Kernel.add))
       { warn_void();
        tformat_string("the bag addition ~S is poorly typed (~S) [251] \n",2,list::alloc(2,_oid_(v1140),GC_OID(_oid_(member_type(OBJECT(ClaireType,v7930))))));
        } 
      if (Kernel._method == OWNER(v7250))
       Result = c_code_method_method1(OBJECT(method,v7250),GC_OBJECT(list,v1140->args),v5065);
      else Result = c_warn_Call(v1140,_oid_(v5065));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_delete_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7240 = GC_OID((*(v1140->args))[1]);
      OID  v7248 = GC_OID((*(v1140->args))[2]);
      OID  v7249 = GC_OID((*(v1140->args))[3]);
      ClaireObject * v7243 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v7240),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v7248)))));
      (Optimize.OPT->use_update = CTRUE);
      if ((OBJECT(ClaireRelation,v7240)->inverse == (NULL)) && 
          ((designated_ask_any(v7248) == CTRUE) && 
            ((Kernel._slot == v7243->isa) && ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7249))),GC_OBJECT(ClaireType,member_type(CLREAD(restriction,v7243,range)))) == CTRUE) || 
                (4 <= Optimize.compiler->safety)))))
       { OID  v11746 = GC_OID((*Optimize.c_code)(v7248,
          _oid_(psort_any(_oid_(domain_I_restriction(((restriction *) v7243)))))));
        { OID  v64;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._delete);
            { Call * v7585 = v2072; 
              list * v7586;
              { OID v_bag;
                GC_ANY(v7586= list::empty(Kernel.emptySet));
                { { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
                    (v2072->selector = ((slot *) v7243));
                    (v2072->arg = v11746);
                    (v2072->test = CFALSE);
                    add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7586)->addFast(v_bag);
                ((list *) v7586)->addFast(v7249);} 
              (v7585->args = v7586);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v64 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v64);
          } 
        } 
      else { list * v2947;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = GC_OBJECT(list,v1140->args);
               v2947 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7248);
                
                (*((list *) v2947))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v2947);} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel._delete,Kernel._property))),GC_OBJECT(list,v1140->args),v2947);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_not_Select(Select *v7248)
{ GC_BIND;
  { OID Result = 0;
    { OID  v3908;
      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = Core.NOT);
        { Call * v7589 = v2072; 
          list * v7594;
          { OID v_bag;
            GC_ANY(v7594= list::empty(Kernel.emptySet));
            { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                (v2072->var = v7248->var);
                (v2072->set_arg = v7248->set_arg);
                { Iteration * v7595 = v2072; 
                  OID  v7596;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = v7248->arg);
                    { If * v7614 = v2072; 
                      OID  v7615;
                      { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                        (v2072->arg = Kernel.ctrue);
                        add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                        v7615 = _oid_(v2072);
                        } 
                      (v7614->arg = v7615);} 
                    (v2072->other = CNULL);
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v7596 = _oid_(v2072);
                    } 
                  (v7595->arg = v7596);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              GC_OID(v_bag);} 
            ((list *) v7594)->addFast(v_bag);} 
          (v7589->args = v7594);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        v3908 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v3908);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_belong_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7248 = GC_OID((*(v1140->args))[1]);
      OID  v7249 = GC_OID((*(v1140->args))[2]);
      list * v9399 = list::alloc(2,GC_OID((*Optimize.c_type)(v7249)),GC_OID((*Optimize.c_type)(v7248)));
      if (Kernel._set == OWNER(v7249))
       { Or * v2072 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
        { Or * v7616 = v2072; 
          list * v7617;
          { list * v3739 = list::empty(Kernel.emptySet);
            { OID gc_local;
              ITERATE(v7250);
              bag *v7250_support;
              v7250_support = GC_OBJECT(bag,enumerate_any(v7249));
              for (START(v7250_support); NEXT(v7250);)
              { GC_LOOP;
                { OID  v16355;
                  { { OID  v932;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel._equal);
                        (v2072->args = list::alloc(2,v7248,v7250));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v932 = _oid_(v2072);
                        } 
                      v16355 = (*Optimize.c_code)(v932,
                        _oid_(Kernel._any));
                      } 
                    GC_OID(v16355);} 
                  v3739->addFast(v16355);
                  } 
                GC_UNLOOP;} 
              } 
            v7617 = GC_OBJECT(list,v3739);
            } 
          (v7616->args = v7617);} 
        add_I_property(Kernel.instances,Language._Or,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v9399))[1]),Kernel._list) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._list),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v7249,v7248)),v9399);
      else if (_inf_equal_type(OBJECT(ClaireType,(*(v9399))[1]),Kernel._set) == CTRUE)
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel.contain_ask,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._set),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v7249,v7248)),v9399);
      else if (v7249 == _oid_(Kernel._object))
       Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class)))))),GC_OBJECT(list,list::alloc(2,v7248,v7249)),GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._class))));
      else Result = (*Optimize.member_code)(v7249,
          v7248);
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_nth_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { list * v7236 = GC_OBJECT(list,v1140->args);
      OID  v7248 = (*(v7236))[1];
      property * v7240 = v1140->selector;
      OID  v7244 = GC_OID((*Optimize.c_type)(v7248));
      ClaireType * v11471 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v7244)));
      OID  v7242;
      { { list * v1893;
          { { bag *v_list; OID v_val;
              OID v7245,CLcount;
              v_list = v7236;
               v1893 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7245 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7245);
                
                (*((list *) v1893))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v1893);} 
          v7242 = restriction_I_property(v7240,v1893,CTRUE);
          } 
        GC_OID(v7242);} 
      if (contain_ask_set(Optimize.OPT->to_remove,v7248) == CTRUE)
       Result = Core.nil->value;
      else if (((INHERIT(OWNER(v7248),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v7248)->params),Kernel._integer))) && 
          ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v7236))[2]))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v7248)))) == CTRUE) || 
              ((v7240 == Kernel.nth) && 
                  (Optimize.compiler->safety > 2))))
       { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v2072,
          2,
          Kernel._object,
          v7248);
        (v2072->arg = (*Optimize.c_code)((*(v7236))[2],
          _oid_(Kernel._integer)));
        (v2072->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v7248)),GC_OID((*Kernel.range)(v7248))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v7248) == 0) ? CTRUE : ((v7240 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (((INHERIT(OWNER(v7248),Kernel._table)) && (INHERIT(OWNER(OBJECT(table,v7248)->params),Kernel._list))) && 
          ((v7236->length == 3) && 
            ((_inf_equal_type(GC_OBJECT(tuple,tuple_I_list(list::alloc(2,GC_OID((*Optimize.c_type)((*(v7236))[2])),GC_OID((*Optimize.c_type)((*(v7236))[3]))))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.domain)(v7248)))) == CTRUE) || 
                (Optimize.compiler->safety > 2))))
       { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
        update_property(Kernel.selector,
          v2072,
          2,
          Kernel._object,
          v7248);
        { Call_table * v7621 = v2072; 
          OID  v7623;
          { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)((*(v7236))[2],
              _oid_(Kernel._integer))),GC_OID((*Optimize.c_code)((*(v7236))[3],
              _oid_(Kernel._integer)))));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
            v7623 = _oid_(v2072);
            } 
          (v7621->arg = v7623);} 
        (v2072->test = not_any(_oid_(((belong_to(GC_OID((*Kernel.DEFAULT)(v7248)),GC_OID((*Kernel.range)(v7248))) == CTRUE) ? CTRUE : (((*Kernel.DEFAULT)(v7248) == 0) ? CTRUE : ((v7240 == Kernel.get) ? CTRUE : CFALSE))))));
        add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if ((_inf_equal_type(OBJECT(ClaireType,v7244),Kernel._array) == CTRUE) && 
          (((v7240 == Kernel.nth_get) || 
              (Optimize.compiler->safety > 2)) && 
            ((_inf_equal_type(v11471,Kernel._float) == CTRUE) || 
                (equal(_oid_(_exp_type(v11471,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE))))
       { Call_array * v2072 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
        (v2072->selector = (*Optimize.c_code)(v7248,
          _oid_(Kernel._array)));
        (v2072->arg = (*Optimize.c_code)((*(v7236))[2],
          _oid_(Kernel._integer)));
        (v2072->test = _oid_(v11471));
        add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (Kernel._method == OWNER(v7242))
       { if ((Optimize.compiler->optimize_ask == CTRUE) && 
            ((_inf_equal_type(OBJECT(ClaireType,v7244),Kernel._array) == CTRUE) || 
                (_inf_equal_type(OBJECT(ClaireType,v7244),Kernel._table) == CTRUE)))
         { notice_void();
          ;} 
        { list * v4775;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = GC_OBJECT(list,v1140->args);
               v4775 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7248);
                
                (*((list *) v4775))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v4775);} 
          Result = c_code_method_method1(OBJECT(method,v7242),GC_OBJECT(list,v1140->args),v4775);
          } 
        } 
      else { list * v9533;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = GC_OBJECT(list,v1140->args);
               v9533 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7248);
                
                (*((list *) v9533))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v9533);} 
          Result = c_warn_property(v7240,GC_OBJECT(list,v1140->args),v9533);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_table_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { property * v11653 = v1140->selector;
      table * v7240 = OBJECT(table,(*(v1140->args))[1]);
      OID  v7248 = GC_OID((*(v1140->args))[2]);
      OID  v7249 = GC_OID((*(v1140->args))[3]);
      if (contain_ask_set(Optimize.OPT->to_remove,_oid_(v7240)) == CTRUE)
       Result = Core.nil->value;
      else if ((v11653 == Kernel.put) || 
          (((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7248))),v7240->domain) == CTRUE) || 
                (5 <= Optimize.compiler->safety)) && 
              ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7249))),v7240->range) == CTRUE) || 
                  (4 <= Optimize.compiler->safety))))
       { if ((Update_ask_relation(v7240,v7248,v7249) == CTRUE) && 
            ((INHERIT(OWNER(v7240->params),Kernel._list)) || 
                (INHERIT(OWNER(v7240->params),Kernel._integer))))
         { OID  v9243 = GC_OID((*Optimize.c_code)(v7248,
            _oid_(Kernel._any)));
          OID  v9244 = GC_OID((*Optimize.c_code)(v7249,
            _oid_(Kernel._any)));
          Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
          (v2072->selector = _oid_(v7240));
          (v2072->value = v9244);
          { Update * v7646 = v2072; 
            OID  v7647;
            if (v11653 == Kernel.put)
             v7647 = _oid_(Kernel.put);
            else v7647 = v9243;
              (v7646->arg = v7647);} 
          { Update * v7648 = v2072; 
            OID  v7649;
            { Call_table * v2072 = ((Call_table *) GC_OBJECT(Call_table,new_object_class(Language._Call_table)));
              (v2072->selector = v7240);
              (v2072->arg = v9243);
              (v2072->test = CFALSE);
              add_I_property(Kernel.instances,Language._Call_table,11,_oid_(v2072));
              v7649 = _oid_(v2072);
              } 
            (v7648->var = v7649);} 
          add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        else if ((v11653 == Kernel.put) || 
            ((v7240->inverse == (NULL)) && 
                (v7240->if_write == CNULL)))
         { if (Optimize.compiler->optimize_ask == CTRUE)
           { notice_void();
            ;} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.put,Kernel._table))),GC_OBJECT(list,v1140->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
        else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_put,Kernel._table))),GC_OBJECT(list,v1140->args),list::alloc(3,_oid_(Kernel._table),
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
      else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Kernel.nth_equal,Kernel._table))),GC_OBJECT(list,v1140->args),list::alloc(3,_oid_(Kernel._table),
          _oid_(Kernel._any),
          _oid_(Kernel._any)));
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_array_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { property * v11653 = v1140->selector;
      OID  v7240 = GC_OID((*(v1140->args))[1]);
      OID  v11685 = GC_OID((*Optimize.c_type)(v7240));
      ClaireType * v11471 = GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v11685)));
      OID  v7248 = GC_OID((*(v1140->args))[2]);
      OID  v7249 = GC_OID((*(v1140->args))[3]);
      ClaireBoolean * v446 = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7249))),GC_OBJECT(ClaireType,member_type(OBJECT(ClaireType,v11685)))) == CTRUE) ? CTRUE : ((4 <= Optimize.compiler->safety) ? CTRUE : CFALSE));
      if (((v11653 == Kernel.nth_put) || 
            (v446 == CTRUE)) && 
          ((_inf_equal_type(v11471,Kernel._float) == CTRUE) || 
              (equal(_oid_(_exp_type(v11471,Kernel._float)),_oid_(Kernel.emptySet)) == CTRUE)))
       { OID  v9243 = GC_OID((*Optimize.c_code)(v7248,
          _oid_(Kernel._integer)));
        OID  v9244;
        { { OID  v14338;
            if (_inf_equal_type(v11471,Kernel._float) == CTRUE)
             v14338 = _oid_(Kernel._float);
            else v14338 = _oid_(Kernel._any);
              v9244 = (*Optimize.c_code)(v7249,
              v14338);
            } 
          GC_OID(v9244);} 
        Update * v2072 = ((Update *) GC_OBJECT(Update,new_object_class(Language._Update)));
        (v2072->selector = v7240);
        (v2072->value = v9244);
        (v2072->arg = _oid_(Kernel.put));
        { Update * v7651 = v2072; 
          OID  v7652;
          { Call_array * v2072 = ((Call_array *) GC_OBJECT(Call_array,new_object_class(Language._Call_array)));
            (v2072->selector = (*Optimize.c_code)(v7240,
              _oid_(Kernel._array)));
            (v2072->arg = v9243);
            (v2072->test = _oid_(v11471));
            add_I_property(Kernel.instances,Language._Call_array,11,_oid_(v2072));
            v7652 = _oid_(v2072);
            } 
          (v7651->var = v7652);} 
        add_I_property(Kernel.instances,Language._Update,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else { if (Optimize.compiler->optimize_ask == CTRUE)
           { notice_void();
            ;} 
          Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(((v446 == CTRUE) ?
            Kernel.nth_put :
            v11653 ),Kernel._array))),GC_OBJECT(list,v1140->args),list::alloc(3,v11685,
            _oid_(Kernel._any),
            _oid_(Kernel._any)));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation(ClaireRelation *v7240,OID v7248,OID v7249)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((v7240 != Kernel.inverse) ? ((((((v7240->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) && 
          (inherit_ask_class(OWNER(v7240->if_write),Kernel._list) != CTRUE)) || 
        ((v7240->inverse == (NULL)) && 
            (((INHERIT(v7240->isa,Kernel._table)) ? (INHERIT(OWNER(CLREAD(table,v7240,params)),Kernel._integer)) : (CTRUE == CTRUE)) && 
              ((v7240->store_ask == CTRUE) ? ((designated_ask_any(v7248) == CTRUE) && 
                  ((designated_ask_any(v7249) == CTRUE) && 
                    ((multi_ask_any(_oid_(v7240)) != CTRUE) && 
                      ((identifiable_ask_any(v7249) == CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7249))),Kernel._float) == CTRUE))))) : (CTRUE == CTRUE))))) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * Update_ask_relation2(ClaireRelation *v7240,ClaireRelation *v7243)
{ return (((((v7240->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? ((inherit_ask_class(OWNER(v7240->if_write),Kernel._list) != CTRUE) ? ((v7243 == Kernel.add) ? CTRUE: CFALSE): CFALSE): CFALSE));} 

ClaireType * c_type_Update_Optimize(Update *v1140)
{ return (Kernel._void);} 

OID  c_code_method_method1(method *v1140,list *v7236,list *v9399)
{ return (c_code_method_method2(v1140,v7236,v9399,c_srange_method(v1140)));} 

OID  c_code_method_method2(method *v1140,list *v7236,list *v9399,ClaireClass *v11661)
{ GC_BIND;
  { OID Result = 0;
    if ((v1140->module_I != claire.it) || 
        ((Optimize.compiler->safety > 4) || 
          (((v1140->functional == (NULL)) ? CTRUE : CFALSE) != CTRUE)))
     { list * v11424 = v1140->domain;
      int  v7239 = v11424->length;
      if (v7239 != v7236->length)
       { { list * v7517;
          { list * v16138 = list::empty(Kernel.emptySet);
            { int  v7233 = 1;
              int  v7653 = (v7239-1);
              { OID gc_local;
                while ((v7233 <= v7653))
                { v16138->addFast((*(v7236))[v7233]);
                  ++v7233;
                  } 
                } 
              } 
            v7517 = GC_OBJECT(list,v16138);
            } 
          OID  v8478;
          { list * v9306;{ list * v16138 = list::empty(Kernel.emptySet);
              { int  v7233 = v7239;
                int  v7657 = v7236->length;
                { OID gc_local;
                  while ((v7233 <= v7657))
                  { v16138->addFast((*(v7236))[v7233]);
                    ++v7233;
                    } 
                  } 
                } 
              v9306 = GC_OBJECT(list,v16138);
              } 
            
            v8478=_oid_(v9306);} 
          v7236 = v7517->addFast(v8478);
          } 
        GC_OBJECT(list,v7236);} 
      if ((v1140->inline_ask == CTRUE) && 
          (c_inline_ask_method(v1140,v7236) == CTRUE))
       Result = c_inline_method1(v1140,v7236,v11661);
      else { ClaireBoolean * v7226 = Optimize.OPT->allocation;
          OID  v7248 = Core.nil->value;
          (Optimize.OPT->allocation = CFALSE);
          { { list * v10400;
              { list * v16138 = list::empty(Kernel.emptySet);
                { int  v7233 = 1;
                  int  v7676 = v7239;
                  { OID gc_local;
                    while ((v7233 <= v7676))
                    { GC_LOOP;
                      v16138->addFast(GC_OID(c_strict_code_any((*(v7236))[v7233],psort_any((*(v11424))[v7233]))));
                      ++v7233;
                      GC_UNLOOP;} 
                    } 
                  } 
                v10400 = GC_OBJECT(list,v16138);
                } 
              v7248 = Call_method_I_method(v1140,v10400);
              } 
            GC_OID(v7248);} 
          if (Optimize.OPT->allocation != CTRUE)
           (Optimize.OPT->allocation = v7226);
          Result = v7248;
          } 
        } 
    else { if (Optimize.compiler->optimize_ask == CTRUE)
         { notice_void();
          ;} 
        Result = _oid_(open_message_property(v1140->selector,v7236));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  Call_method_I_method(method *v1140,list *v874)
{ GC_BIND;
  if (BCONTAIN(status_I_restriction(v1140),1))
   { (Optimize.OPT->allocation = CTRUE);
    if (nth_integer(v1140->status,6) != CTRUE)
     { { bag *v_list; OID v_val;
        OID v7248,CLcount;
        v_list = v874;
         v874 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v7248 = (*(v_list))[CLcount];
          v_val = c_gc_I_any1(v7248);
          
          (*((list *) v874))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v874);} 
    } 
  else { ClaireBoolean * g0145I;
    { ClaireBoolean *v_and;
      { v_and = Optimize.OPT->allocation;
        if (v_and == CFALSE) g0145I =CFALSE; 
        else { { int  v12322;
            { list * v13283;
              { bag * v13172 = v874;
                list * v4832 = ((list *) empty_bag(v13172));
                { ITERATE(v7248);
                  for (START(v13172); NEXT(v7248);)
                  if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v7248))) == CTRUE)
                   v4832->addFast(v7248);
                  } 
                v13283 = GC_OBJECT(list,v4832);
                } 
              v12322 = v13283->length;
              } 
            v_and = ((v12322 > 1) ? CTRUE : CFALSE);
            } 
          if (v_and == CFALSE) g0145I =CFALSE; 
          else g0145I = CTRUE;} 
        } 
      } 
    
    if (g0145I == CTRUE) { { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = v874;
           v874 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            v_val = c_gc_I_any1(v7248);
            
            (*((list *) v874))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v874);} 
      } 
  if (BCONTAIN(v1140->status,2))
   (Optimize.OPT->use_nth_equal = CTRUE);
  if (BCONTAIN(v1140->status,7))
   (Optimize.OPT->use_string_update = CTRUE);
  if (BCONTAIN(v1140->status,3))
   (Optimize.OPT->use_update = CTRUE);
  if (legal_ask_module(v1140->module_I,_oid_(v1140)) != CTRUE)
   tformat_string("in call ~S~S\n",0,list::alloc(2,_oid_(v1140->selector),_oid_(v874)));
  { OID Result = 0;
    if (v874->length == 1)
     { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
      (v2072->arg = v1140);
      (v2072->args = v874);
      add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else if (v874->length == 2)
     { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      (v2072->arg = v1140);
      (v2072->args = v874);
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else { Call_method * v2072 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
        (v2072->arg = v1140);
        (v2072->args = v874);
        add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Call_method_Optimize(Call_method *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v14245;
      { { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = GC_OBJECT(list,v1140->args);
           v14245 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v7248);
            
            (*((list *) v14245))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v14245);} 
      Result = use_range_method(v1140->arg,v14245);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Call_method_Optimize(Call_method *v1140)
{ return (_oid_(v1140));} 

ClaireBoolean * c_gc_ask_Call_method(Call_method *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { method * v7237 = v1140->arg;
      { ClaireBoolean *v_and;
        { v_and = not_any(_oid_((INHERIT(v7237->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v7237->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v7237->range))))));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = ((v7237->range != Kernel._float) ? CTRUE : CFALSE);
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = ((nth_integer(status_I_restriction(v7237),5) != CTRUE) ? CTRUE : ((((_inf_equal_type(v7237->range,Kernel._bag) == CTRUE) ? ((Optimize.OPT->loop_gc == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE) ? CTRUE : CFALSE));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = not_any(_oid_(nth_integer(status_I_restriction(v7237),4)));
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireBoolean *v_or1;
                        { v_or1 = nth_integer(status_I_restriction(v7237),1);
                          if (v_or1 == CTRUE) v_or =CTRUE; 
                          else { { OID  v15205;
                              { OID gc_local;
                                ITERATE(v7248);
                                v15205= Kernel.cfalse;
                                bag *v7248_support;
                                v7248_support = GC_OBJECT(list,v1140->args);
                                for (START(v7248_support); NEXT(v7248);)
                                if ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v7248))) == CTRUE)
                                 { v15205 = Kernel.ctrue;
                                  break;} 
                                } 
                              v_or1 = boolean_I_any(v15205);
                              } 
                            if (v_or1 == CTRUE) v_or =CTRUE; 
                            else v_or = CFALSE;} 
                          } 
                        } 
                      if (v_or == CTRUE) v_and =CTRUE; 
                      else v_and = CFALSE;} 
                    } 
                  } 
                if (v_and == CFALSE) Result =CFALSE; 
                else Result = CTRUE;} 
              } 
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireFunction * functional_I_method_Optimize(method *v1140)
{ GC_BIND;
  { ClaireFunction *Result ;
    { OID  v7230 = GC_OID(get_property(Kernel.functional,v1140));
      property * v7240 = v1140->selector;
      Result = ((INHERIT(OWNER(v7230),Kernel._function)) ?
        OBJECT(ClaireFunction,v7230) :
        make_function_string(string_v((*Optimize.function_name)(_oid_(v7240),
          _oid_(v1140->domain),
          v7230))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  nth_type_check_type(ClaireType *v11680,ClaireType *v11678,ClaireType *v11692)
{ GC_BIND;
  if (_inf_equal_type(v11692,GC_OBJECT(ClaireType,member_type(v11680))) != CTRUE)
   { warn_void();
    tformat_string("unsafe update on bag: type ~S into ~S [252]\n",2,list::alloc(2,_oid_(v11692),_oid_(v11680)));
    } 
  { OID Result = 0;
    Result = _oid_(v11692);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_inline_ask_method(method *v1140,list *v7236)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { lambda * v7230 = GC_OBJECT(lambda,v1140->formula);
      list * v11421 = GC_OBJECT(list,v7230->vars);
      OID  v7248 = GC_OID(v7230->body);
      int  v7239 = 1;
      { OID  v3579;
        { OID gc_local;
          ITERATE(v7246);
          v3579= Kernel.cfalse;
          bag *v7246_support;
          v7246_support = GC_OBJECT(list,v7230->vars);
          for (START(v7246_support); NEXT(v7246);)
          if ((occurrence_any(v7248,OBJECT(Variable,v7246)) > 1) && 
              ((designated_ask_any((*(v7236))[v7239]) != CTRUE) && 
                (inherit_ask_class(owner_any((*Kernel.range)(v7246)),Optimize._Pattern) != CTRUE)))
           { v3579 = Kernel.ctrue;
            break;} 
          else ++v7239;
            } 
        Result = not_any(v3579);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  inline_optimize_ask_Call(Call *v1140)
{ GC_BIND;
  { OID Result = 0;
    { list * v7236 = GC_OBJECT(list,v1140->args);
      OID  v7237;
      { { list * v4540;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = v7236;
               v4540 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = _oid_(set::alloc(1,v7248));
                
                (*((list *) v4540))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v4540);} 
          v7237 = restriction_I_property(v1140->selector,v4540,CTRUE);
          } 
        GC_OID(v7237);} 
      if (Kernel._method == OWNER(v7237))
       { { ClaireBoolean * g0152I;
          { ClaireBoolean *v_and;
            { v_and = OBJECT(method,v7237)->inline_ask;
              if (v_and == CFALSE) g0152I =CFALSE; 
              else { { OID  v6462;
                  { ITERATE(v7243);
                    v6462= Kernel.cfalse;
                    for (START(OBJECT(restriction,v7237)->domain); NEXT(v7243);)
                    if (INHERIT(OBJECT(ClaireObject,v7243)->isa,Optimize._Pattern))
                     { v6462 = Kernel.ctrue;
                      break;} 
                    } 
                  v_and = boolean_I_any(v6462);
                  } 
                if (v_and == CFALSE) g0152I =CFALSE; 
                else { v_and = c_inline_ask_method(OBJECT(method,v7237),v7236);
                  if (v_and == CFALSE) g0152I =CFALSE; 
                  else g0152I = CTRUE;} 
                } 
              } 
            } 
          
          if (g0152I == CTRUE) Result = v7237;
            else Result = Kernel.cfalse;
          } 
        } 
      else Result = Kernel.cfalse;
        } 
    GC_UNBIND; return (Result);} 
  } 

