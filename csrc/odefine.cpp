/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\odefine.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:46 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_List_Optimize(List *v1140)
{ GC_BIND;
  ;{ ClaireType *Result ;
    if (((v1140->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._list,v1140->of);
    else { OID  v16259 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v9243);
          for (START(v1140->args); NEXT(v9243);)
          if (boolean_I_any(v16259) == CTRUE)
           v16259= _oid_(meet_class(OBJECT(ClaireClass,v16259),class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v9243))))));
          else v16259= _oid_(class_I_type(ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v9243)))));
            } 
        Result = nth_class1(Kernel._list,OBJECT(ClaireType,v16259));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_List_Optimize(List *v1140)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { List * v7248;
      { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
          { Construct * v9479 = v2072; 
            list * v9481;
            { bag *v_list; OID v_val;
              OID v9243,CLcount;
              v_list = GC_OBJECT(list,v1140->args);
               v9481 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v9243 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v9243,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v9243))));
                
                (*((list *) v9481))[CLcount] = v_val;} 
              } 
            (v9479->args = v9481);} 
          add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
          v7248 = v2072;
          } 
        GC_OBJECT(List,v7248);} 
      if (((v1140->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0307I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0307I =CTRUE; 
              else { v_or = ((equal(_oid_(v1140->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0307I =CTRUE; 
                else { { OID  v5420;
                    { OID gc_local;
                      ITERATE(v9243);
                      v5420= Kernel.cfalse;
                      bag *v9243_support;
                      v9243_support = GC_OBJECT(list,v1140->args);
                      for (START(v9243_support); NEXT(v9243);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v9243))),GC_OBJECT(ClaireType,v1140->of)) != CTRUE)
                         { v5420 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v5420);
                    } 
                  if (v_or == CTRUE) g0307I =CTRUE; 
                  else g0307I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0307I == CTRUE) { (v7248->of = v1140->of);
              Result = _oid_(v7248);
              } 
            else { warn_void();
            { list * v6379;
              { { OID v_bag;
                  GC_ANY(v6379= list::empty(Kernel.emptySet));
                  { { list * v11132;{ bag *v_list; OID v_val;
                        OID v9243,CLcount;
                        v_list = GC_OBJECT(list,v1140->args);
                         v11132 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v9243 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v9243);
                          
                          (*((list *) v11132))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v11132);} 
                    GC_OID(v_bag);} 
                  ((list *) v6379)->addFast(v_bag);
                  ((list *) v6379)->addFast(GC_OID(_oid_(v1140->of)));} 
                GC_OBJECT(list,v6379);} 
              tformat_string("unsafe typed list: ~S not in ~S [262]\n",2,v6379);
              } 
            { OID  v12098;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.check_in);
                (v2072->args = list::alloc(3,_oid_(v7248),
                  _oid_(Kernel._list),
                  GC_OID(_oid_(v1140->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v12098 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v12098,
                _oid_(Kernel._list));
              } 
            } 
          } 
        } 
      else Result = _oid_(v7248);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Set_Optimize(Set *v1140)
{ GC_BIND;
  ;{ ClaireType *Result ;
    if (((v1140->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     Result = param_I_class(Kernel._set,v1140->of);
    else { OID  v16259 = _oid_(Kernel.emptySet);
        { OID gc_local;
          ITERATE(v9243);
          for (START(v1140->args); NEXT(v9243);)
          if (boolean_I_any(v16259) == CTRUE)
           v16259= _oid_(meet_class(OBJECT(ClaireClass,v16259),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v9243)))));
          else v16259= _oid_(class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v9243))));
            } 
        Result = nth_class1(Kernel._set,OBJECT(ClaireType,v16259));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Set_Optimize(Set *v1140)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Set * v7248;
      { { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
          { Construct * v9507 = v2072; 
            list * v9508;
            { bag *v_list; OID v_val;
              OID v9243,CLcount;
              v_list = GC_OBJECT(list,v1140->args);
               v9508 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v9243 = (*(v_list))[CLcount];
                v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v9243,
                  _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v9243))));
                
                (*((list *) v9508))[CLcount] = v_val;} 
              } 
            (v9507->args = v9508);} 
          add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
          v7248 = v2072;
          } 
        GC_OBJECT(Set,v7248);} 
      if (((v1140->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { ClaireBoolean * g0314I;
          { ClaireBoolean *v_or;
            { v_or = ((Optimize.compiler->safety > 4) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0314I =CTRUE; 
              else { v_or = ((equal(_oid_(v1140->of),_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) g0314I =CTRUE; 
                else { { OID  v15942;
                    { OID gc_local;
                      ITERATE(v9243);
                      v15942= Kernel.cfalse;
                      bag *v9243_support;
                      v9243_support = GC_OBJECT(list,v1140->args);
                      for (START(v9243_support); NEXT(v9243);)
                      { GC_LOOP;
                        if (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v9243))),GC_OBJECT(ClaireType,v1140->of)) != CTRUE)
                         { v15942 = Kernel.ctrue;
                          break;} 
                        GC_UNLOOP;} 
                      } 
                    v_or = not_any(v15942);
                    } 
                  if (v_or == CTRUE) g0314I =CTRUE; 
                  else g0314I = CFALSE;} 
                } 
              } 
            } 
          
          if (g0314I == CTRUE) { (v7248->of = v1140->of);
              Result = _oid_(v7248);
              } 
            else { warn_void();
            { list * v519;
              { { OID v_bag;
                  GC_ANY(v519= list::empty(Kernel.emptySet));
                  { { list * v11139;{ bag *v_list; OID v_val;
                        OID v9243,CLcount;
                        v_list = GC_OBJECT(list,v1140->args);
                         v11139 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v9243 = (*(v_list))[CLcount];
                          v_val = (*Optimize.c_type)(v9243);
                          
                          (*((list *) v11139))[CLcount] = v_val;} 
                        } 
                      
                      v_bag=_oid_(v11139);} 
                    GC_OID(v_bag);} 
                  ((list *) v519)->addFast(v_bag);
                  ((list *) v519)->addFast(GC_OID(_oid_(v1140->of)));} 
                GC_OBJECT(list,v519);} 
              tformat_string("unsafe typed set: ~S not in ~S [262]\n",2,v519);
              } 
            { OID  v2441;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.check_in);
                (v2072->args = list::alloc(3,_oid_(v7248),
                  _oid_(Kernel._set),
                  GC_OID(_oid_(v1140->of))));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v2441 = _oid_(v2072);
                } 
              Result = (*Optimize.c_code)(v2441,
                _oid_(Kernel._set));
              } 
            } 
          } 
        } 
      else Result = _oid_(v7248);
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Tuple_Optimize(Tuple *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v3402;
      { { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = v1140->args;
           v3402 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_type)(v7248);
            
            (*((list *) v3402))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v3402);} 
      Result = tuple_I_list(v3402);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Tuple_Optimize(Tuple *v1140)
{ GC_BIND;
  (Optimize.OPT->allocation = CTRUE);
  { OID Result = 0;
    { Tuple * v2072 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
      { Construct * v9536 = v2072; 
        list * v9537;
        { bag *v_list; OID v_val;
          OID v9243,CLcount;
          v_list = GC_OBJECT(list,v1140->args);
           v9537 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v9243 = (*(v_list))[CLcount];
            v_val = c_gc_I_any2(GC_OID((*Optimize.c_code)(v9243,
              _oid_(Kernel._any))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v9243))));
            
            (*((list *) v9537))[CLcount] = v_val;} 
          } 
        (v9536->args = v9537);} 
      add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Definition_Optimize(Definition *v1140)
{ { ClaireType *Result ;
    if (_inf_equalt_class(v1140->arg,Kernel._exception) == CTRUE)
     Result = Kernel.emptySet;
    else Result = v1140->arg;
      return (Result);} 
  } 

OID  c_code_Definition_Optimize(Definition *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { ClaireClass * v9222 = v1140->arg;
      Variable * v9241;
      { { int  v11043;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v11043 = 0;
            } 
          v9241 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v11043,v9222);
          } 
        GC_OBJECT(Variable,v9241);} 
      OID  v9243 = GC_OID(total_ask_class(v9222,GC_OBJECT(list,v1140->args)));
      if (v9222->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_("[105] cannot instantiate ~S"),
        _oid_(list::alloc(1,_oid_(v9222))))));
      if (boolean_I_any(v9243) == CTRUE)
       Result = (*Optimize.c_code)(v9243,
        _oid_(v7243));
      else { OID  v12004;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v9241);
            { Let * v9541 = v2072; 
              OID  v9543;
              { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                { Cast * v9544 = v2072; 
                  OID  v9545;
                  { OID  v425;
                    { { OID  v5183;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core.new_I);
                          (v2072->args = list::alloc(1,_oid_(v9222)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v5183 = _oid_(v2072);
                          } 
                        v425 = (*Optimize.c_code)(v5183,
                          _oid_(Kernel._object));
                        } 
                      GC_OID(v425);} 
                    v9545 = c_gc_I_any1(v425);
                    } 
                  (v9544->arg = v9545);} 
                (v2072->set_arg = v9222);
                add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                v9543 = _oid_(v2072);
                } 
              (v9541->value = v9543);} 
            { Let * v9568 = v2072; 
              OID  v9569;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                store_object(v2072,
                  2,
                  Kernel._object,
                  analyze_I_class(v9222,_oid_(v9241),GC_OBJECT(list,v1140->args),list::empty()),
                  CFALSE);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v9569 = _oid_(v2072);
                } 
              (v9568->arg = v9569);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v12004 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v12004,
            _oid_(v7243));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  total_ask_class(ClaireClass *v1140,list *v7236)
{ GC_BIND;
  { OID Result = 0;
    { list * v11437 = GC_OBJECT(list,OBJECT(list,(*Optimize.get_indexed)(_oid_(v1140))));
      int  v7239 = v11437->length;
      { ClaireBoolean * g0334I;
        { ClaireBoolean *v_and;
          { v_and = not_any(_oid_(Optimize.compiler->diet_ask));
            if (v_and == CFALSE) g0334I =CFALSE; 
            else { v_and = ((v7236->length == (v7239-1)) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0334I =CFALSE; 
              else { v_and = ((v1140->open == ClEnv->ephemeral) ? CTRUE : ((_inf_equalt_class(v1140,Kernel._exception) == CTRUE) ? CTRUE : CFALSE));
                if (v_and == CFALSE) g0334I =CFALSE; 
                else { v_and = ((v7239 <= 4) ? CTRUE : CFALSE);
                  if (v_and == CFALSE) g0334I =CFALSE; 
                  else { { OID  v9988;
                      { int  v7233 = 2;
                        int  v9570 = v7239;
                        { v9988= _oid_(CFALSE);
                          while ((v7233 <= v9570))
                          { if ((((*Kernel.srange)((*(v11437))[v7233]) == _oid_(Kernel._integer)) ? CTRUE : (((*Kernel.srange)((*(v11437))[v7233]) == _oid_(Kernel._any)) ? CTRUE : CFALSE)) != CTRUE)
                             { v9988 = Kernel.ctrue;
                              break;} 
                            ++v7233;
                            } 
                          } 
                        } 
                      v_and = not_any(v9988);
                      } 
                    if (v_and == CFALSE) g0334I =CFALSE; 
                    else g0334I = CTRUE;} 
                  } 
                } 
              } 
            } 
          } 
        
        if (g0334I == CTRUE) { OID  v9222;
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = ((v7236->length == 0) ?
                  Core.new_I :
                  Optimize.anyObject_I ));
                { Call * v9573 = v2072; 
                  list * v9574;
                  { list * v12871;
                    { { bag *v_list; OID v_val;
                        OID v7248,CLcount;
                        v_list = v7236;
                         v12871 = v_list->clone();
                        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                        { v7248 = (*(v_list))[CLcount];
                          v_val = c_gc_I_any1(GC_OID((*Optimize.c_code)(GC_OID((*(OBJECT(bag,(*Core.args)(v7248))))[2]),
                            _oid_(Kernel._any))));
                          
                          (*((list *) v12871))[CLcount] = v_val;} 
                        } 
                      GC_OBJECT(list,v12871);} 
                    v9574 = cons_any(_oid_(v1140),v12871);
                    } 
                  (v9573->args = v9574);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v9222 = _oid_(v2072);
                } 
              GC_OID(v9222);} 
            OID  v7237 = GC_OID(_oid_(_at_property1(Kernel.close,v1140)));
            if (_inf_equal_type(v1140,Kernel._exception) != CTRUE)
             (Optimize.OPT->allocation = CTRUE);
            if (v7236->length == 0)
             v9222= GC_OID((*Optimize.c_code)(v9222));
            if (boolean_I_any(v7237) == CTRUE)
             { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
              update_property(Kernel.arg,
                v2072,
                2,
                Kernel._object,
                v7237);
              (v2072->args = list::alloc(1,v9222));
              add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
              Result = _oid_(v2072);
              } 
            else Result = v9222;
              } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  analyze_I_class(ClaireClass *v7227,OID v1140,list *v9231,list *v11437)
{ GC_RESERVE(15);  // v3.0.55 optim !
  { OID Result = 0;
    { ClaireBoolean * v6969 = ((v7227->open != 4) ? ((boolean_I_any(_oid_(v11437)) != CTRUE) ? ((Optimize.compiler->class2file_ask != CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE);
      list * v7242;
      { { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = v9231;
           v7242 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            { OID  v7240 = GC_OID((*(OBJECT(Call,v7248)->args))[1]);
              OID  v7249 = GC_OID((*(OBJECT(Call,v7248)->args))[2]);
              ClaireObject * v7243 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v7240),v7227));
              ClaireBoolean * v14286 = (((*Kernel.open)(v7240) == 0) ? ((Kernel._slot == v7243->isa) ? CTRUE: CFALSE): CFALSE);
              GC__ANY(v11437 = v11437->addFast(v7240), 4);
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = ((v14286 == CTRUE) ?
                  Kernel.put :
                  Core.write ));
                { Call * v9577 = v2072; 
                  list * v9598;
                  { OID v_bag;
                    GC_ANY(v9598= list::empty(Kernel.emptySet));
                    ((list *) v9598)->addFast(v7240);
                    ((list *) v9598)->addFast(v1140);
                    { if ((v14286 != CTRUE) || 
                          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7249))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(_oid_(v7243))))) == CTRUE))
                       v_bag = v7249;
                      else v_bag = c_check_any(GC_OID((*Optimize.c_code)(v7249,
                          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.range)(_oid_(v7243))),
                          _oid_(Kernel._type))));
                        GC_OID(v_bag);} 
                    ((list *) v9598)->addFast(v_bag);} 
                  (v9577->args = v9598);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_val = _oid_(v2072);
                } 
              } 
            
            (*((list *) v7242))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v7242);} 
      if (v6969 == CTRUE)
       { { OID  v3167;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.add);
            (v2072->args = list::alloc(3,_oid_(Kernel.instances),
              _oid_(v7227),
              v1140));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v3167 = _oid_(v2072);
            } 
          v7242 = v7242->addFast(v3167);
          } 
        GC_OBJECT(list,v7242);} 
      if (Optimize.compiler->class2file_ask != CTRUE)
       { OID gc_local;
        ITERATE(v7243);
        bag *v7243_support;
        v7243_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(_oid_(v7227))));
        for (START(v7243_support); NEXT(v7243);)
        { GC_LOOP;
          { property * v7240 = OBJECT(restriction,v7243)->selector;
            OID  v7246 = GC_OID(OBJECT(slot,v7243)->DEFAULT);
            { ClaireBoolean * g0342I;
              { ClaireBoolean *v_and;
                { v_and = known_ask_any(v7246);
                  if (v_and == CFALSE) g0342I =CFALSE; 
                  else { { OID  v5089;
                      if (multi_ask_any(_oid_(v7240)) == CTRUE)
                       v5089 = v7246;
                      else v5089 = Kernel.ctrue;
                        v_and = boolean_I_any(v5089);
                      } 
                    if (v_and == CFALSE) g0342I =CFALSE; 
                    else { v_and = not_any(_oid_(v11437->memq(_oid_(v7240))));
                      if (v_and == CFALSE) g0342I =CFALSE; 
                      else { v_and = ((((v7240->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : ((((v7240->if_write == CNULL) ? CTRUE : CFALSE) != CTRUE) ? CTRUE : (((OBJECT(slot,v7243)->srange != Kernel._object) && 
                            ((OBJECT(slot,v7243)->srange != Kernel._float) && 
                              (inherit_ask_class(OWNER(v7246),Kernel._integer) != CTRUE))) ? CTRUE : CFALSE)));
                        if (v_and == CFALSE) g0342I =CFALSE; 
                        else g0342I = CTRUE;} 
                      } 
                    } 
                  } 
                } 
              
              if (g0342I == CTRUE) { OID  v7936;
                  if (designated_ask_any(v7246) == CTRUE)
                   v7936 = v7246;
                  else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.DEFAULT);
                      { Call * v9603 = v2072; 
                        list * v9604;
                        { OID v_bag;
                          GC_ANY(v9604= list::empty(Kernel.emptySet));
                          { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                              { Cast * v9605 = v2072; 
                                OID  v9606;
                                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Core._at);
                                  (v2072->args = list::alloc(2,_oid_(v7240),_oid_(v7227)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v9606 = _oid_(v2072);
                                  } 
                                (v9605->arg = v9606);} 
                              (v2072->set_arg = Kernel._slot);
                              add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                              v_bag = _oid_(v2072);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v9604)->addFast(v_bag);} 
                        (v9603->args = v9604);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v7936 = _oid_(v2072);
                      } 
                    { { OID  v9894;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core.write);
                        (v2072->args = list::alloc(3,_oid_(v7240),
                          v1140,
                          v7936));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v9894 = _oid_(v2072);
                        } 
                      v7242 = v7242->addFast(v9894);
                      } 
                     GC__ANY(v7242, 7);} 
                  } 
                } 
            } 
          GC_UNLOOP;} 
        } 
      { OID  v7237 = GC_OID(_oid_(_at_property1(Kernel.close,v7227)));
        { OID  v10855;
          if (boolean_I_any(v7237) == CTRUE)
           { Call_method1 * v2072 = ((Call_method1 *) GC_OBJECT(Call_method1,new_object_class(Language._Call_method1)));
            update_property(Kernel.arg,
              v2072,
              2,
              Kernel._object,
              v7237);
            (v2072->args = list::alloc(1,v1140));
            add_I_property(Kernel.instances,Language._Call_method1,11,_oid_(v2072));
            v10855 = _oid_(v2072);
            } 
          else v10855 = v1140;
            v7242 = v7242->addFast(v10855);
          } 
        } 
      Result = _oid_(v7242);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defobj_Optimize(Defobj *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v9220 = Optimize.OPT->allocation;
      ClaireClass * v9222 = v1140->arg;
      OID  v7247 = GC_OID(get_symbol(v1140->ident));
      OID  v9241;
      { if ((v7247 != CNULL) && 
            (inherit_ask_class(OWNER(v7247),Core._global_variable) != CTRUE))
         v9241 = v7247;
        else { Variable * v11258;{ int  v2112;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v2112 = 0;
                } 
              v11258 = Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),v2112,v9222);
              } 
            
            v9241=_oid_(v11258);} 
          GC_OID(v9241);} 
      Call * v8085;
      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Optimize.object_I);
          (v2072->args = list::alloc(2,_oid_(v1140->ident),_oid_(v9222)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v8085 = v2072;
          } 
        GC_OBJECT(Call,v8085);} 
      OID  v8086 = GC_OID(analyze_I_class(v9222,v9241,GC_OBJECT(list,v1140->args),list::alloc(1,_oid_(Kernel.name))));
      OID  v9243;
      if (inherit_ask_class(OWNER(v9241),Language._Variable) != CTRUE)
       { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        store_object(v2072,
          2,
          Kernel._object,
          (*Kernel.cons)(_oid_(v8085),
            v8086),
          CFALSE);
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
        v9243 = _oid_(v2072);
        } 
      else { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          store_object(v2072,
            2,
            Kernel._object,
            v9241,
            CFALSE);
          (v2072->value = _oid_(v8085));
          { Let * v9633 = v2072; 
            OID  v9634;
            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              store_object(v2072,
                2,
                Kernel._object,
                v8086,
                CFALSE);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
              v9634 = _oid_(v2072);
              } 
            (v9633->arg = v9634);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v9243 = _oid_(v2072);
          } 
        if (v9222->open <= 0)
       close_exception(((general_error *) (*Core._general_error)(_string_("[105] cannot instantiate ~S"),
        _oid_(list::alloc(1,_oid_(v9222))))));
      if (v7247 != CNULL)
       { if (contain_ask_list(Optimize.OPT->objects,v7247) != CTRUE)
         { GC_OBJECT(list,Optimize.OPT->objects)->addFast(v7247);
          (*Optimize.c_register)(v7247);
          } 
        } 
      else { warn_void();
          tformat_string("~S is unknown [265]\n",2,list::alloc(1,_oid_(v1140->ident)));
          } 
        v9243= GC_OID((*Optimize.c_code)(v9243,
        _oid_(v7243)));
      if (_inf_equal_type(v1140->arg,Kernel._exception) == CTRUE)
       (Optimize.OPT->allocation = v9220);
      Result = v9243;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Defclass_Optimize(Defclass *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { symbol * v4104 = v1140->ident;
      OID  v7247 = GC_OID(get_symbol(v4104));
      Call * v2873;
      { ClaireObject *V_CC ;
        if (v7247 != CNULL)
         { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.class_I);
          (v2072->args = list::alloc(2,_oid_(v4104),_oid_(v1140->arg)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          V_CC = v2072;
          } 
        else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] cannot compile unknown class ~S"),
            _oid_(list::alloc(1,_oid_(v4104))))));
          v2873= (Call *) V_CC;} 
      Do * v9243;
      { { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v9636 = v2072; 
            list * v9637;
            { list * v7878;
              { { list * v12636;
                  { { bag *v_list; OID v_val;
                      OID v7248,CLcount;
                      v_list = GC_OBJECT(list,v1140->args);
                       v12636 = v_list->clone();
                      for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                      { v7248 = (*(v_list))[CLcount];
                        { OID  v7246 = CNULL;
                          if (INHERIT(OWNER(v7248),Language._Call))
                           { v7246= GC_OID((*(OBJECT(Call,v7248)->args))[2]);
                            v7248= GC_OID((*(OBJECT(Call,v7248)->args))[1]);
                            } 
                          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v2072->selector = Kernel.add_slot);
                            (v2072->args = list::alloc(5,v7247,
                              _oid_(make_a_property_any(_oid_(OBJECT(Variable,v7248)->pname))),
                              GC_OID((*Kernel.range)(v7248)),
                              v7246,
                              0));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                            v_val = _oid_(v2072);
                            } 
                          } 
                        
                        (*((list *) v12636))[CLcount] = v_val;} 
                      } 
                    GC_OBJECT(list,v12636);} 
                  list * v13597;
                  if (v1140->params->length != 0)
                   { OID v_bag;
                    GC_ANY(v13597= list::empty(Kernel.emptySet));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel.put);
                        (v2072->args = list::alloc(3,_oid_(Kernel.params),
                          v7247,
                          GC_OID(_oid_(v1140->params))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v13597)->addFast(v_bag);} 
                  else v13597 = list::empty();
                    v7878 = append_list(v12636,v13597);
                  } 
                GC_OBJECT(list,v7878);} 
              v9637 = cons_any(_oid_(v2873),v7878);
              } 
            (v9636->args = v9637);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v9243 = v2072;
          } 
        GC_OBJECT(Do,v9243);} 
      if (contain_ask_list(Optimize.OPT->objects,v7247) != CTRUE)
       { GC_OBJECT(list,Optimize.OPT->objects)->addFast(v7247);
        (*Optimize.c_register)(v7247);
        } 
      Result = (*Optimize.c_code)(_oid_(v9243),
        _oid_(v7243));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Defmethod_Optimize(Defmethod *v1140)
{ return (Kernel._any);} 

OID  c_code_Defmethod_Optimize(Defmethod *v1140)
{ GC_BIND;
  { OID Result = 0;
    { property * v11568 = v1140->arg->selector;
      list * v7236 = GC_OBJECT(list,v1140->arg->args);
      list * v11442 = (((v7236->length == 1) && 
          ((*(v7236))[1] == _oid_(ClEnv))) ?
        list::alloc(1,GC_OID(_oid_(Variable_I_symbol(OBJECT(symbol,Optimize._starname_star->value),0,Kernel._void)))) :
        v7236 );
      list * v11439 = GC_OBJECT(list,extract_signature_I_list(v11442));
      list * v10106 = GC_OBJECT(list,extract_range_any(GC_OID(v1140->set_arg),v11442,GC_OBJECT(list,OBJECT(list,Language.LDEF->value))));
      OID  v16346;
      { if ((boolean_I_any(v1140->inline_ask) == CTRUE) && 
            (Optimize.compiler->inline_ask == CTRUE))
         { print_in_string_void();
          princ_string("lambda[(");
          ppvariable_list(v11442);
          princ_string("),");
          print_any(GC_OID(v1140->body));
          princ_string("]");
          v16346 = _string_(end_of_print_void());
          } 
        else v16346 = Kernel.cfalse;
          GC_OID(v16346);} 
      list * v5094 = GC_OBJECT(list,extract_status_new_any(GC_OID(v1140->body)));
      OID  v4351 = GC_OID((*Core._at)(_oid_(v11568),
        (*(v11439))[2]));
      method * v7237;
      { ClaireObject *V_CC ;
        if (Kernel._method == OBJECT(ClaireObject,v4351)->isa)
         V_CC = OBJECT(method,v4351);
        else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] the method ~S @ ~S is not known"),
            _oid_(list::alloc(2,_oid_(v11568),(*(v11439))[2])))));
          v7237= (method *) V_CC;} 
      OID  v3156 = v7237->status;
      ((*(v5094))[2]=get_property(Kernel.functional,v7237));
      if ((Optimize.compiler->inline_ask != CTRUE) && 
          ((v11568 == Language.Iterate) || 
              (v11568 == Language.iterate)))
       Result = Core.nil->value;
      else if (((*(v10106))[1] == _oid_(Kernel._void)) && 
          (sort_pattern_ask_list(v11442,GC_OID(v1140->body)) == CTRUE))
       Result = sort_code_Defmethod(v1140,v11442);
      else { if ((*(v5094))[3] != _oid_(Kernel.body))
           { char * v11483 = GC_STRING(string_v((*Optimize.function_name)(_oid_(v11568),
              (*(v11439))[2],
              (*(v5094))[2])));
            lambda * v11421 = GC_OBJECT(lambda,lambda_I_list(v11442,(*(v5094))[3]));
            int  v16379 = ((Optimize.OPT->recompute == CTRUE) ?
              c_status_any(GC_OID(v11421->body),GC_OBJECT(list,v11421->vars)) :
              status_I_restriction(v7237) );
            compile_lambda_string(v11483,v11421,_oid_(v7237));
            if (((*(v5094))[1] == CNULL) || 
                (Optimize.OPT->recompute == CTRUE))
             { if ((Optimize.OPT->use_nth_equal != CTRUE) && 
                  (BCONTAIN(v16379,2)))
               v16379= (v16379-exp2_integer(2));
              if ((Optimize.OPT->use_update != CTRUE) && 
                  (BCONTAIN(v16379,3)))
               v16379= (v16379-exp2_integer(3));
              if ((Optimize.OPT->use_string_update != CTRUE) && 
                  (BCONTAIN(v16379,7)))
               v16379= (v16379-exp2_integer(7));
              if ((Optimize.OPT->allocation != CTRUE) && 
                  (BCONTAIN(v16379,1)))
               v16379= (v16379-exp2_integer(1));
              ((*(v5094))[1]=v16379);
              } 
            ((*(v5094))[2]=_oid_(make_function_string(v11483)));
            } 
          if (INHERIT(OWNER(v1140->set_arg),Core._global_variable))
           ((*(v10106))[1]=v1140->set_arg);
          else if ((INHERIT(v7237->range->isa,Kernel._class)) && 
              (inherit_ask_class(OWNER((*(v10106))[1]),Kernel._class) != CTRUE))
           ((*(v10106))[1]=_oid_(v7237->range));
          { OID  v9232 = GC_OID(add_method_I_method(v7237,
              OBJECT(list,(*(v11439))[1]),
              (*(v10106))[1],
              (*(v5094))[1],
              OBJECT(ClaireFunction,(*(v5094))[2])));
            { OID  v14558;
              if ((boolean_I_any(v1140->inline_ask) == CTRUE) && 
                  ((Optimize.compiler->inline_ask == CTRUE) && 
                    (Optimize.compiler->diet_ask != CTRUE)))
               { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.inlineok_ask);
                (v2072->args = list::alloc(2,v9232,v16346));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v14558 = _oid_(v2072);
                } 
              else if ((boolean_I_any((*(v10106))[2]) == CTRUE) && 
                  (Optimize.compiler->diet_ask != CTRUE))
               { char * v11483 = GC_STRING(append_string(GC_STRING(string_v((*Optimize.function_name)(_oid_(v11568),
                  (*(v11439))[2],
                  (*(v5094))[2]))),"_type"));
                compile_lambda_string(v11483,OBJECT(lambda,(*(v10106))[2]),_oid_(Kernel._type));
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core.write);
                  (v2072->args = list::alloc(3,Language.typing->value,
                    v9232,
                    _oid_(make_function_string(v11483))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v14558 = _oid_(v2072);
                  } 
                } 
              else v14558 = v9232;
                Result = (*Optimize.c_code)(v14558);
              } 
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_pattern_ask_list(list *v11442,OID v3871)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_and;
      { v_and = ((v11442->length == 1) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { if (INHERIT(OWNER(v3871),Language._Call))
           { ClaireBoolean *v_and1;
            { v_and1 = ((OBJECT(Call,v3871)->selector == Core.sort) ? CTRUE : CFALSE);
              if (v_and1 == CFALSE) v_and =CFALSE; 
              else { { OID  v11033 = GC_OID((*(OBJECT(Call,v3871)->args))[1]);
                  v_and1 = ((INHERIT(OWNER(v11033),Language._Call)) ?
                    ((OBJECT(Call,v11033)->selector == Core._at) ? ((INHERIT(OWNER((*(OBJECT(Call,v11033)->args))[1]),Kernel._property)) ? CTRUE: CFALSE): CFALSE) :
                    CFALSE );
                  } 
                if (v_and1 == CFALSE) v_and =CFALSE; 
                else { v_and1 = ((equal(lexical_build_any(GC_OID((*(OBJECT(Call,v3871)->args))[2]),v11442,0),(*(v11442))[1]) == CTRUE) ? CTRUE : CFALSE);
                  if (v_and1 == CFALSE) v_and =CFALSE; 
                  else v_and = CTRUE;} 
                } 
              } 
            } 
          else v_and = CFALSE;
            if (v_and == CFALSE) Result =CFALSE; 
          else Result = CTRUE;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  sort_code_Defmethod(Defmethod *v1140,list *v11442)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7236 = (*(v11442))[1];
      OID  v7230 = GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v1140->body)))))[1])))))[1]);
      Variable * v7237 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("m"),0,Kernel._integer));
      Variable * v7239 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("n"),0,Kernel._integer));
      Variable * v7248 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("x"),0,GC_OBJECT(ClaireType,member_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.range)(v7236)))))));
      Variable * v7240 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("p"),0,Kernel._integer));
      Variable * v1353 = GC_OBJECT(Variable,Variable_I_symbol(symbol_I_string2("q"),0,Kernel._integer));
      Defmethod * v12788;
      { { Defmethod * v2072 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          (v2072->arg = v1140->arg);
          (v2072->inline_ask = Kernel.cfalse);
          (v2072->set_arg = v1140->set_arg);
          { Defmethod * v9664 = v2072; 
            OID  v9665;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = v1140->arg->selector);
              { Call * v9666 = v2072; 
                list * v9667;
                { OID v_bag;
                  GC_ANY(v9667= list::empty(Kernel.emptySet));
                  ((list *) v9667)->addFast(1);
                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.length);
                      (v2072->args = list::alloc(1,(*(v11442))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v9667)->addFast(v_bag);
                  ((list *) v9667)->addFast(v7236);} 
                (v9666->args = v9667);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v9665 = _oid_(v2072);
              } 
            (v9664->body = v9665);} 
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v2072));
          v12788 = v2072;
          } 
        GC_OBJECT(Defmethod,v12788);} 
      If * v7423;
      { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v9668 = v2072; 
            OID  v9669;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._sup);
              (v2072->args = list::alloc(2,_oid_(v7237),_oid_(v7239)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v9669 = _oid_(v2072);
              } 
            (v9668->test = v9669);} 
          { If * v9670 = v2072; 
            OID  v9691;
            { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              (v2072->var = v7248);
              { Let * v9692 = v2072; 
                OID  v9693;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.nth);
                  (v2072->args = list::alloc(2,v7236,_oid_(v7239)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v9693 = _oid_(v2072);
                  } 
                (v9692->value = v9693);} 
              { Let * v9694 = v2072; 
                OID  v9695;
                { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v9696 = v2072; 
                    OID  v9697;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel._equal);
                      { Call * v9698 = v2072; 
                        list * v9699;
                        { OID v_bag;
                          GC_ANY(v9699= list::empty(Kernel.emptySet));
                          ((list *) v9699)->addFast(_oid_(v7237));
                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v2072->selector = Core._plus);
                              (v2072->args = list::alloc(2,_oid_(v7239),1));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                              v_bag = _oid_(v2072);
                              } 
                            GC_OID(v_bag);} 
                          ((list *) v9699)->addFast(v_bag);} 
                        (v9698->args = v9699);} 
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v9697 = _oid_(v2072);
                      } 
                    (v9696->test = v9697);} 
                  { If * v9700 = v2072; 
                    OID  v9722;
                    { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v9723 = v2072; 
                        OID  v9724;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          update_property(Kernel.selector,
                            v2072,
                            2,
                            Kernel._object,
                            v7230);
                          { Call * v9725 = v2072; 
                            list * v9726;
                            { OID v_bag;
                              GC_ANY(v9726= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth);
                                  (v2072->args = list::alloc(2,v7236,_oid_(v7237)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9726)->addFast(v_bag);
                              ((list *) v9726)->addFast(_oid_(v7248));} 
                            (v9725->args = v9726);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v9724 = _oid_(v2072);
                          } 
                        (v9723->test = v9724);} 
                      { If * v9727 = v2072; 
                        OID  v9728;
                        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                          { Do * v9729 = v2072; 
                            list * v9730;
                            { OID v_bag;
                              GC_ANY(v9730= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth_equal);
                                  { Call * v9731 = v2072; 
                                    list * v9753;
                                    { OID v_bag;
                                      GC_ANY(v9753= list::empty(Kernel.emptySet));
                                      ((list *) v9753)->addFast(v7236);
                                      ((list *) v9753)->addFast(_oid_(v7239));
                                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel.nth);
                                          (v2072->args = list::alloc(2,v7236,_oid_(v7237)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v_bag = _oid_(v2072);
                                          } 
                                        GC_OID(v_bag);} 
                                      ((list *) v9753)->addFast(v_bag);} 
                                    (v9731->args = v9753);} 
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9730)->addFast(v_bag);
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Kernel.nth_equal);
                                  (v2072->args = list::alloc(3,v7236,
                                    _oid_(v7237),
                                    _oid_(v7248)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9730)->addFast(v_bag);} 
                            (v9729->args = v9730);} 
                          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                          v9728 = _oid_(v2072);
                          } 
                        (v9727->arg = v9728);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                      (v2072->other = Kernel.cfalse);
                      v9722 = _oid_(v2072);
                      } 
                    (v9700->arg = v9722);} 
                  { If * v9754 = v2072; 
                    OID  v9755;
                    { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                      (v2072->var = v7240);
                      { Let * v9756 = v2072; 
                        OID  v9757;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core._sup_sup);
                          { Call * v9758 = v2072; 
                            list * v9759;
                            { OID v_bag;
                              GC_ANY(v9759= list::empty(Kernel.emptySet));
                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                  (v2072->selector = Core._plus);
                                  (v2072->args = list::alloc(2,_oid_(v7239),_oid_(v7237)));
                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v9759)->addFast(v_bag);
                              ((list *) v9759)->addFast(1);} 
                            (v9758->args = v9759);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v9757 = _oid_(v2072);
                          } 
                        (v9756->value = v9757);} 
                      { Let * v9760 = v2072; 
                        OID  v9761;
                        { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                          (v2072->var = v1353);
                          (v2072->value = _oid_(v7239));
                          { Let * v9762 = v2072; 
                            OID  v10435;
                            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                              { Do * v10438 = v2072; 
                                list * v10439;
                                { OID v_bag;
                                  GC_ANY(v10439= list::empty(Kernel.emptySet));
                                  { { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                      (v2072->var = _oid_(v7248));
                                      { Assign * v10440 = v2072; 
                                        OID  v10441;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel.nth);
                                          (v2072->args = list::alloc(2,v7236,_oid_(v7240)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10441 = _oid_(v2072);
                                          } 
                                        (v10440->arg = v10441);} 
                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10439)->addFast(v_bag);
                                  { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                      { If * v10442 = v2072; 
                                        OID  v10443;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Core._I_equal);
                                          (v2072->args = list::alloc(2,_oid_(v7240),_oid_(v7239)));
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10443 = _oid_(v2072);
                                          } 
                                        (v10442->test = v10443);} 
                                      { If * v10444 = v2072; 
                                        OID  v10445;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel.nth_equal);
                                          { Call * v10447 = v2072; 
                                            list * v10466;
                                            { OID v_bag;
                                              GC_ANY(v10466= list::empty(Kernel.emptySet));
                                              ((list *) v10466)->addFast(v7236);
                                              ((list *) v10466)->addFast(_oid_(v7240));
                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v2072->selector = Kernel.nth);
                                                  (v2072->args = list::alloc(2,v7236,_oid_(v7239)));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                  v_bag = _oid_(v2072);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v10466)->addFast(v_bag);} 
                                            (v10447->args = v10466);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10445 = _oid_(v2072);
                                          } 
                                        (v10444->arg = v10445);} 
                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                                      (v2072->other = Kernel.cfalse);
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10439)->addFast(v_bag);
                                  { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                                      (v2072->var = v7240);
                                      { Iteration * v10467 = v2072; 
                                        OID  v10468;
                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                          (v2072->selector = Kernel._dot_dot);
                                          { Call * v10469 = v2072; 
                                            list * v10470;
                                            { OID v_bag;
                                              GC_ANY(v10470= list::empty(Kernel.emptySet));
                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                  (v2072->selector = Core._plus);
                                                  (v2072->args = list::alloc(2,_oid_(v7239),1));
                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                  v_bag = _oid_(v2072);
                                                  } 
                                                GC_OID(v_bag);} 
                                              ((list *) v10470)->addFast(v_bag);
                                              ((list *) v10470)->addFast(_oid_(v7237));} 
                                            (v10469->args = v10470);} 
                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                          v10468 = _oid_(v2072);
                                          } 
                                        (v10467->set_arg = v10468);} 
                                      { Iteration * v10471 = v2072; 
                                        OID  v10472;
                                        { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                          { If * v10473 = v2072; 
                                            OID  v10474;
                                            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              update_property(Kernel.selector,
                                                v2072,
                                                2,
                                                Kernel._object,
                                                v7230);
                                              { Call * v10475 = v2072; 
                                                list * v10497;
                                                { OID v_bag;
                                                  GC_ANY(v10497= list::empty(Kernel.emptySet));
                                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v2072->selector = Kernel.nth);
                                                      (v2072->args = list::alloc(2,v7236,_oid_(v7240)));
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10497)->addFast(v_bag);
                                                  ((list *) v10497)->addFast(_oid_(v7248));} 
                                                (v10475->args = v10497);} 
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v10474 = _oid_(v2072);
                                              } 
                                            (v10473->test = v10474);} 
                                          { If * v10498 = v2072; 
                                            OID  v10500;
                                            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                                              { Do * v10501 = v2072; 
                                                list * v10502;
                                                { OID v_bag;
                                                  GC_ANY(v10502= list::empty(Kernel.emptySet));
                                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                      (v2072->selector = Kernel.nth_equal);
                                                      { Call * v10504 = v2072; 
                                                        list * v10505;
                                                        { OID v_bag;
                                                          GC_ANY(v10505= list::empty(Kernel.emptySet));
                                                          ((list *) v10505)->addFast(v7236);
                                                          ((list *) v10505)->addFast(_oid_(v7239));
                                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                              (v2072->selector = Kernel.nth);
                                                              (v2072->args = list::alloc(2,v7236,_oid_(v7240)));
                                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                              v_bag = _oid_(v2072);
                                                              } 
                                                            GC_OID(v_bag);} 
                                                          ((list *) v10505)->addFast(v_bag);} 
                                                        (v10504->args = v10505);} 
                                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10502)->addFast(v_bag);
                                                  { { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                                      (v2072->var = _oid_(v7239));
                                                      { Assign * v10506 = v2072; 
                                                        OID  v10507;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Core._plus);
                                                          (v2072->args = list::alloc(2,_oid_(v7239),1));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10507 = _oid_(v2072);
                                                          } 
                                                        (v10506->arg = v10507);} 
                                                      add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10502)->addFast(v_bag);
                                                  { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                                                      { If * v10508 = v2072; 
                                                        OID  v10528;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Kernel._sup);
                                                          (v2072->args = list::alloc(2,_oid_(v7240),_oid_(v7239)));
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10528 = _oid_(v2072);
                                                          } 
                                                        (v10508->test = v10528);} 
                                                      { If * v10529 = v2072; 
                                                        OID  v10530;
                                                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                          (v2072->selector = Kernel.nth_equal);
                                                          { Call * v10531 = v2072; 
                                                            list * v10532;
                                                            { OID v_bag;
                                                              GC_ANY(v10532= list::empty(Kernel.emptySet));
                                                              ((list *) v10532)->addFast(v7236);
                                                              ((list *) v10532)->addFast(_oid_(v7240));
                                                              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                                                  (v2072->selector = Kernel.nth);
                                                                  (v2072->args = list::alloc(2,v7236,_oid_(v7239)));
                                                                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                                  v_bag = _oid_(v2072);
                                                                  } 
                                                                GC_OID(v_bag);} 
                                                              ((list *) v10532)->addFast(v_bag);} 
                                                            (v10531->args = v10532);} 
                                                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                                          v10530 = _oid_(v2072);
                                                          } 
                                                        (v10529->arg = v10530);} 
                                                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                                                      (v2072->other = Kernel.cfalse);
                                                      v_bag = _oid_(v2072);
                                                      } 
                                                    GC_OID(v_bag);} 
                                                  ((list *) v10502)->addFast(v_bag);} 
                                                (v10501->args = v10502);} 
                                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                                              v10500 = _oid_(v2072);
                                              } 
                                            (v10498->arg = v10500);} 
                                          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                                          (v2072->other = Kernel.cfalse);
                                          v10472 = _oid_(v2072);
                                          } 
                                        (v10471->arg = v10472);} 
                                      add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10439)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = Kernel.nth_equal);
                                      (v2072->args = list::alloc(3,v7236,
                                        _oid_(v7239),
                                        _oid_(v7248)));
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10439)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = v1140->arg->selector);
                                      { Call * v10533 = v2072; 
                                        list * v10534;
                                        { OID v_bag;
                                          GC_ANY(v10534= list::empty(Kernel.emptySet));
                                          ((list *) v10534)->addFast(_oid_(v1353));
                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v2072->selector = Kernel._dash);
                                              (v2072->args = list::alloc(2,_oid_(v7239),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v_bag = _oid_(v2072);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v10534)->addFast(v_bag);
                                          ((list *) v10534)->addFast(v7236);} 
                                        (v10533->args = v10534);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10439)->addFast(v_bag);
                                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                      (v2072->selector = v1140->arg->selector);
                                      { Call * v10535 = v2072; 
                                        list * v10536;
                                        { OID v_bag;
                                          GC_ANY(v10536= list::empty(Kernel.emptySet));
                                          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                              (v2072->selector = Core._plus);
                                              (v2072->args = list::alloc(2,_oid_(v7239),1));
                                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                              v_bag = _oid_(v2072);
                                              } 
                                            GC_OID(v_bag);} 
                                          ((list *) v10536)->addFast(v_bag);
                                          ((list *) v10536)->addFast(_oid_(v7237));
                                          ((list *) v10536)->addFast(v7236);} 
                                        (v10535->args = v10536);} 
                                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                      v_bag = _oid_(v2072);
                                      } 
                                    GC_OID(v_bag);} 
                                  ((list *) v10439)->addFast(v_bag);} 
                                (v10438->args = v10439);} 
                              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                              v10435 = _oid_(v2072);
                              } 
                            (v9762->arg = v10435);} 
                          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                          v9761 = _oid_(v2072);
                          } 
                        (v9760->arg = v9761);} 
                      add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                      v9755 = _oid_(v2072);
                      } 
                    (v9754->other = v9755);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                  v9695 = _oid_(v2072);
                  } 
                (v9694->arg = v9695);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
              v9691 = _oid_(v2072);
              } 
            (v9670->arg = v9691);} 
          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
          (v2072->other = Kernel.cfalse);
          v7423 = v2072;
          } 
        GC_OBJECT(If,v7423);} 
      Defmethod * v12789;
      { { Defmethod * v2072 = ((Defmethod *) GC_OBJECT(Defmethod,new_object_class(Language._Defmethod)));
          { Defmethod * v10537 = v2072; 
            Call * v10559;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = v1140->arg->selector);
              (v2072->args = list::alloc(3,_oid_(v7239),
                _oid_(v7237),
                v7236));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v10559 = v2072;
              } 
            (v10537->arg = v10559);} 
          (v2072->inline_ask = Kernel.cfalse);
          (v2072->set_arg = v1140->set_arg);
          (v2072->body = _oid_(v7423));
          add_I_property(Kernel.instances,Language._Defmethod,11,_oid_(v2072));
          v12789 = v2072;
          } 
        GC_OBJECT(Defmethod,v12789);} 
      tformat_string("---- note: quick sort optimisation for ~S ---- \n",2,list::alloc(1,_oid_(v1140->arg->selector)));
      OPT_EVAL(_oid_(v12789));
      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
        (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)(_oid_(v12788))),GC_OID((*Optimize.c_code)(_oid_(v12789)))));
        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

method * add_method_property2(property *v7240,list *v11439,ClaireType *v11613,int v11657,ClaireFunction *v11187,ClaireFunction *v11188)
{ return (add_method_property(v7240,
    v11439,
    v11613,
    v11657,
    _oid_(v11187)));} 

OID  add_method_I_method(method *v7237,list *v11439,OID v11613,OID v12924,ClaireFunction *v11255)
{ GC_BIND;
  { OID Result = 0;
    { Call_method * v9222;
      { { Call_method * v2072 = ((Call_method *) GC_OBJECT(Call_method,new_object_class(Language._Call_method)));
          (v2072->arg = ((method *) _at_property1(Kernel.add_method,Kernel._property)));
          (v2072->args = list::alloc(5,GC_OID((*Optimize.c_code)(_oid_(v7237->selector),
              _oid_(Kernel._property))),
            GC_OID((*Optimize.c_code)(_oid_(v11439),
              _oid_(Kernel._list))),
            GC_OID((*Optimize.c_code)(v11613,
              _oid_(Kernel._type))),
            v12924,
            _oid_(v11255)));
          add_I_property(Kernel.instances,Language._Call_method,11,_oid_(v2072));
          v9222 = v2072;
          } 
        GC_OBJECT(Call_method,v9222);} 
      if ((v7237->range == Kernel._float) || 
          ((v7237->domain->memq(_oid_(Kernel._float)) == CTRUE) || 
            (INHERIT(v7237->range->isa,Kernel._tuple))))
       GC_OBJECT(list,v9222->args)->addFast(_oid_(make_function_string(append_string(GC_STRING(string_I_function(v11255)),"_"))));
      Result = _oid_(v9222);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_status_new_any(OID v7248)
{ GC_BIND;
  { list *Result ;
    { OID  v7243 = CNULL;
      OID  v7230;
      if ((INHERIT(OWNER(v7248),Language._Call)) && (OBJECT(Call,v7248)->selector == Language.function_I))
       v7230 = v7248;
      else v7230 = CNULL;
        if (INHERIT(OWNER(v7248),Language._And))
       { OID  v7249 = (*(OBJECT(And,v7248)->args))[1];
        if ((INHERIT(OWNER(v7249),Language._Call)) && (OBJECT(Call,v7249)->selector == Language.function_I))
         { v7230= v7249;
          v7248= (*(OBJECT(And,v7248)->args))[2];
          } 
        } 
      else if (INHERIT(OWNER(v7248),Language._Call))
       { if (OBJECT(Call,v7248)->selector == Language.function_I)
         v7248= _oid_(Kernel.body);
        } 
      if (v7230 != CNULL)
       { v7248= _oid_(Kernel.body);
        if (length_bag(OBJECT(bag,(*Core.args)(v7230))) > 1)
         { ClaireHandler c_handle = ClaireHandler();
          if ERROR_IN 
          { { int  v12188;{ set * v11106;
                { set * v6422 = set::empty(Kernel.emptySet);
                  { OID gc_local;
                    ITERATE(v7245);
                    bag *v7245_support;
                    v7245_support = GC_OBJECT(list,cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v7230)))));
                    for (START(v7245_support); NEXT(v7245);)
                    { GC_LOOP;
                      v6422->addFast(GC_OID(OPT_EVAL(v7245)));
                      GC_UNLOOP;} 
                    } 
                  v11106 = GC_OBJECT(set,v6422);
                  } 
                v12188 = integer_I_set(v11106);
                } 
              
              v7243=v12188;} 
            ClEnv->cHandle--;} 
          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
          { c_handle.catchIt();{ warn_void();
              (Optimize.SHIT->value= _oid_(cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v7230))))));
              tformat_string("wrong status ~S -> ~S [266]\n",2,GC_OBJECT(list,list::alloc(2,v7230,_oid_(set_I_bag(cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(v7230)))))))));
              v7243= 0;
              } 
            } 
          else PREVIOUS_HANDLER;} 
        else v7243= 0;
          v7230= _oid_(make_function_string(string_I_symbol(extract_symbol_any((*(OBJECT(bag,(*Core.args)(v7230))))[1]))));
        } 
      Result = list::alloc(3,v7243,
        v7230,
        v7248);
      } 
    GC_UNBIND; return (Result);} 
  } 

list * extract_signature_I_list(list *v7236)
{ GC_BIND;
  (Language.LDEF->value= _oid_(list::empty(Kernel._any)));
  { list *Result ;
    { int  v7239 = 0;
      list * v11373 = list::empty(Kernel._type);
      list * v11374;
      { { bag *v_list; OID v_val;
          OID v7246,CLcount;
          v_list = v7236;
           v11374 = v_list->clone(Kernel._any);
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7246 = (*(v_list))[CLcount];
            { OID  v7240 = GC_OID(extract_pattern_any(GC_OID(_oid_(OBJECT(Variable,v7246)->range)),list::alloc(1,v7239)));
              ++v7239;
              { { OID  v12067;
                  { if (INHERIT(OBJECT(Variable,v7246)->range->isa,Core._global_variable))
                     v12067 = _oid_(OBJECT(Variable,v7246)->range);
                    else v12067 = v7240;
                      GC_OID(v12067);} 
                  v11373 = v11373->addFast(v12067);
                  } 
                GC_OBJECT(list,v11373);} 
              (OBJECT(Variable,v7246)->range = type_I_any(v7240));
              v_val = v7240;
              } 
            
            (*((list *) v11374))[CLcount] = v_val;} 
          } 
        GC_OBJECT(list,v11374);} 
      Result = list::alloc(2,_oid_(v11373),_oid_(v11374));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _equalsig_ask_list(list *v7248,list *v7249)
{ return (((tmatch_ask_list(v7248,v7249) == CTRUE) ? ((tmatch_ask_list(v7249,v7248) == CTRUE) ? CTRUE: CFALSE): CFALSE));} 

char * function_name_property_Optimize(property *v7240,list *v7236,OID v7248)
{ GC_BIND;
  { char *Result ;
    if (INHERIT(OWNER(v7248),Kernel._function))
     Result = string_I_function(OBJECT(ClaireFunction,v7248));
    else { int  v7239 = 0;
        int  v7237 = 0;
        module * v11455 = v7240->name->module_I;
        ClaireClass * v7227 = class_I_type(OBJECT(ClaireType,(*(v7236))[1]));
        char * v7242 = GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_I_symbol(v7240->name)),"_")),GC_STRING(string_I_symbol(v7227->name))));
        if ((Optimize.compiler->naming == 0) && 
            (v7240 != Core.main))
         v7242= GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_I_symbol(v11455->name)),"_")),v7242));
        { ITERATE(v7242);
          for (START(v7240->restrictions); NEXT(v7242);)
          { if (v7227 == domain_I_restriction(OBJECT(restriction,v7242)))
             ++v7239;
            if (_equalsig_ask_list(v7236,OBJECT(restriction,v7242)->domain) == CTRUE)
             v7237= v7239;
            } 
          } 
        v7242= GC_STRING(((v7239 <= 1) ?
          v7242 :
          append_string(v7242,GC_STRING(string_I_integer (v7237))) ));
        Result = (((stable_ask_relation(v7240) == CTRUE) || 
            (v7240 == Core.main)) ?
          v7242 :
          append_string(GC_STRING(append_string(v7242,"_")),GC_STRING(string_I_symbol(ClEnv->module_I->name))) );
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  compile_lambda_string(char *v1140,lambda *v7236,OID v7237)
{ { OID Result = 0;
    { int  v7248 = Optimize.compiler->safety;
      lambda * v7249 = v7236;
      if (Kernel._method == OWNER(v7237))
       (Optimize.OPT->in_method = v7237);
      (Optimize.OPT->protection = CFALSE);
      (Optimize.OPT->allocation = CFALSE);
      if (Optimize.OPT->loop_index > 0)
       (Optimize.OPT->loop_index = 0);
      (Optimize.OPT->loop_gc = CFALSE);
      (Optimize.OPT->use_update = CFALSE);
      (Optimize.OPT->use_nth_equal = CFALSE);
      (Optimize.OPT->use_string_update = CFALSE);
      (Optimize.OPT->max_vars = 0);
      if (contain_ask_list(Optimize.OPT->unsure,v7237) == CTRUE)
       (Optimize.compiler->safety = 1);
      (*Optimize.make_c_function)(_oid_(v7236),
        _string_(v1140),
        v7237);
      (Optimize.OPT->in_method = CNULL);
      (Optimize.compiler->safety = v7248);
      Result = Kernel.ctrue;
      } 
    return (Result);} 
  } 

OID  c_code_Defarray_Optimize(Defarray *v1140)
{ GC_BIND;
  { OID Result = 0;
    { list * v7225 = GC_OBJECT(list,v1140->arg->args);
      OID  v9220 = GC_OID(get_symbol(extract_symbol_any((*(v7225))[1])));
      table * v9241;
      { ClaireObject *V_CC ;
        if (INHERIT(OWNER(v9220),Kernel._table))
         V_CC = OBJECT(table,v9220);
        else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] the table ~S is unknown"),
            _oid_(list::alloc(1,(*(v7225))[1])))));
          v9241= (table *) V_CC;} 
      OID  v7243 = GC_OID((*Kernel.domain)(v9220));
      OID  v7229;
      { { list * v7236 = GC_OBJECT(list,cdr_list(v7225));
          OID  v7226 = GC_OID(lexical_build_any(GC_OID(v1140->body),v7236,0));
          { ClaireBoolean * g0446I;
            { OID  v14950;
              { ITERATE(v11731);
                v14950= Kernel.cfalse;
                for (START(v7236); NEXT(v11731);)
                if (occurrence_any(v7226,OBJECT(Variable,v11731)) > 0)
                 { v14950 = Kernel.ctrue;
                  break;} 
                } 
              g0446I = boolean_I_any(v14950);
              } 
            
            if (g0446I == CTRUE) v7229 = _oid_(lambda_I_list(v7236,v7226));
              else v7229 = v1140->body;
            } 
          } 
        GC_OID(v7229);} 
      OID  v7228;
      { if (INHERIT(OWNER(v7229),Core._lambda))
         v7228 = CNULL;
        else v7228 = v1140->body;
          GC_OID(v7228);} 
      list * v7687;
      if (boolean_I_any(_oid_(OBJECT(ClaireRelation,v9220)->multivalued_ask)) == CTRUE)
       { OID v_bag;
        GC_ANY(v7687= list::empty(Kernel._any));
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.multivalued_ask),
              _oid_(v9241),
              GC_OID(_oid_(OBJECT(ClaireRelation,v9220)->multivalued_ask))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v7687)->addFast(v_bag);} 
      else v7687 = list::empty(Kernel._any);
        list * v7683;
      { OID v_bag;
        GC_ANY(v7683= list::empty(Kernel._any));
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.range),
              _oid_(v9241),
              GC_OID((*Kernel.range)(v9220))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v7683)->addFast(v_bag);
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.params),
              _oid_(v9241),
              GC_OID((*Kernel.params)(v9220))));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v7683)->addFast(v_bag);
        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.put);
            (v2072->args = list::alloc(3,_oid_(Kernel.domain),
              _oid_(v9241),
              v7243));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          GC_OID(v_bag);} 
        ((list *) v7683)->addFast(v_bag);} 
      (OBJECT(Variable,(*(v7225))[2])->range = extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v7225))[2])->range))));
      if (v7225->length == 2)
       { { { OID  v15911;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.put);
              { Call * v10569 = v2072; 
                list * v10590;
                { OID v_bag;
                  GC_ANY(v10590= list::empty(Kernel.emptySet));
                  ((list *) v10590)->addFast(_oid_(Kernel.graph));
                  ((list *) v10590)->addFast(_oid_(v9241));
                  if (INHERIT(OBJECT(ClaireObject,v7243)->isa,Core._Interval))
                   { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.make_copy_list);
                    (v2072->args = list::alloc(2,size_Interval(OBJECT(Interval,v7243)),v7228));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.make_list);
                      (v2072->args = list::alloc(2,29,CNULL));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    ((list *) v10590)->addFast(v_bag);} 
                (v10569->args = v10590);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v15911 = _oid_(v2072);
              } 
            v7683 = v7683->addFast(v15911);
            } 
          GC_OBJECT(list,v7683);} 
        { { OID  v6207;
            if (INHERIT(OWNER(v7229),Core._lambda))
             { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              store_object(v2072,
                2,
                Kernel._object,
                (*(v7225))[2],
                CFALSE);
              (v2072->set_arg = v7243);
              { Iteration * v10592 = v2072; 
                OID  v10593;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.nth_equal);
                  (v2072->args = list::alloc(3,_oid_(v9241),
                    (*(v7225))[2],
                    GC_OID(OBJECT(lambda,v7229)->body)));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v10593 = _oid_(v2072);
                  } 
                (v10592->arg = v10593);} 
              add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
              v6207 = _oid_(v2072);
              } 
            else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.put);
                (v2072->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                  _oid_(v9241),
                  v7228));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v6207 = _oid_(v2072);
                } 
              v7683 = v7683->addFast(v6207);
            } 
          GC_OBJECT(list,v7683);} 
        } 
      else { ClaireType * v11591 = GC_OBJECT(ClaireType,extract_type_any(GC_OID(_oid_(OBJECT(Variable,(*(v7225))[3])->range))));
          (OBJECT(Variable,(*(v7225))[3])->range = v11591);
          { { OID  v9090;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.put);
                { Call * v10595 = v2072; 
                  list * v10596;
                  { OID v_bag;
                    GC_ANY(v10596= list::empty(Kernel.emptySet));
                    ((list *) v10596)->addFast(_oid_(Kernel.graph));
                    ((list *) v10596)->addFast(_oid_(v9241));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core.make_copy_list);
                        { Call * v10597 = v2072; 
                          list * v10598;
                          { OID v_bag;
                            GC_ANY(v10598= list::empty(Kernel.emptySet));
                            ((list *) v10598)->addFast(OBJECT(table,v9220)->graph->length);
                            { if ((*Kernel.params)(v9220) == _oid_(Kernel._any))
                               v_bag = CNULL;
                              else v_bag = (*Kernel.DEFAULT)(v9220);
                                GC_OID(v_bag);} 
                            ((list *) v10598)->addFast(v_bag);} 
                          (v10597->args = v10598);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v10596)->addFast(v_bag);} 
                  (v10595->args = v10596);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v9090 = _oid_(v2072);
                } 
              v7683 = v7683->addFast(v9090);
              } 
            GC_OBJECT(list,v7683);} 
          { { OID  v13895;
              if (INHERIT(OWNER(v7229),Core._lambda))
               { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                store_object(v2072,
                  2,
                  Kernel._object,
                  (*(v7225))[2],
                  CFALSE);
                (v2072->set_arg = (*(OBJECT(bag,v7243)))[1]);
                { Iteration * v10621 = v2072; 
                  OID  v10622;
                  { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    store_object(v2072,
                      2,
                      Kernel._object,
                      (*(v7225))[3],
                      CFALSE);
                    (v2072->set_arg = _oid_(v11591));
                    { Iteration * v10623 = v2072; 
                      OID  v10624;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel.nth_equal);
                        (v2072->args = list::alloc(4,_oid_(v9241),
                          (*(v7225))[2],
                          (*(v7225))[3],
                          GC_OID(OBJECT(lambda,v7229)->body)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v10624 = _oid_(v2072);
                        } 
                      (v10623->arg = v10624);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v10622 = _oid_(v2072);
                    } 
                  (v10621->arg = v10622);} 
                add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                v13895 = _oid_(v2072);
                } 
              else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  (v2072->args = list::alloc(3,_oid_(Kernel.DEFAULT),
                    _oid_(v9241),
                    v7228));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v13895 = _oid_(v2072);
                  } 
                v7683 = v7683->addFast(v13895);
              } 
            GC_OBJECT(list,v7683);} 
          } 
        GC_OBJECT(list,Optimize.OPT->objects)->addFast(v9220);
      (*Optimize.c_register)(v9220);
      { OID  v6113;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v10626 = v2072; 
            list * v10627;
            { OID  v8996;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Optimize.object_I);
                (v2072->args = list::alloc(2,GC_OID((*Kernel.name)(v9220)),_oid_(Kernel._table)));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v8996 = _oid_(v2072);
                } 
              v10627 = cons_any(v8996,GC_OBJECT(list,add_star_list(v7687,v7683)));
              } 
            (v10626->args = v10627);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v6113 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v6113,
          _oid_(Kernel._any));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compute_if_write_inverse_relation2(ClaireRelation *v7210)
{ GC_BIND;
  { Variable * v7248;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2("XX"));
        (v2072->range = v7210->domain);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v7248 = v2072;
        } 
      GC_OBJECT(Variable,v7248);} 
    Variable * v7249;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2("YY"));
        (v2072->range = ((multi_ask_any(_oid_(v7210)) == CTRUE) ?
          member_type(v7210->range) :
          v7210->range ));
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v7249 = v2072;
        } 
      GC_OBJECT(Variable,v7249);} 
    Variable * v7250;
    { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
        (v2072->pname = symbol_I_string2("ZZ"));
        (v2072->range = v7210->range);
        add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
        v7250 = v2072;
        } 
      GC_OBJECT(Variable,v7250);} 
    list * v11373 = list::empty(Kernel._any);
    if (multi_ask_any(_oid_(v7210)) == CTRUE)
     { v11373= list::alloc(Kernel._any,1,GC_OID((INHERIT(v7210->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v7210)),OBJECT(Variable,_oid_(v7248)),_oid_(v7249)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v7210)),OBJECT(Variable,_oid_(v7248)),_oid_(v7249)))));
      if (((v7210->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v11373= GC_OBJECT(list,v11373->addFast(GC_OID((INHERIT(v7210->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v7210->inverse)),OBJECT(Variable,_oid_(v7249)),_oid_(v7248)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v7210->inverse)),OBJECT(Variable,_oid_(v7249)),_oid_(v7248))))));
      { ClaireRelation * v10629 = v7210; 
        OID  v10630;
        { lambda * v12279;{ OID  v253;
            { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v10654 = v2072; 
                OID  v10655;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core.NOT);
                  { Call * v10656 = v2072; 
                    list * v10658;
                    { OID v_bag;
                      GC_ANY(v10658= list::empty(Kernel.emptySet));
                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Kernel._Z);
                          (v2072->args = list::alloc(2,_oid_(v7249),GC_OID(Produce_get_relation2(v7210,v7248))));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v10658)->addFast(v_bag);} 
                    (v10656->args = v10658);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v10655 = _oid_(v2072);
                  } 
                (v10654->test = v10655);} 
              { If * v10659 = v2072; 
                OID  v10660;
                { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                  (v2072->args = v11373);
                  add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                  v10660 = _oid_(v2072);
                  } 
                (v10659->arg = v10660);} 
              add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
              (v2072->other = Kernel.cfalse);
              v253 = _oid_(v2072);
              } 
            v12279 = lambda_I_list(list::alloc(2,_oid_(v7248),_oid_(v7249)),v253);
            } 
          
          v10630=_oid_(v12279);} 
        (v10629->if_write = v10630);} 
      } 
    else { v11373= list::alloc(Kernel._any,1,GC_OID((INHERIT(v7210->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v7210)),OBJECT(Variable,_oid_(v7248)),_oid_(v7249)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v7210)),OBJECT(Variable,_oid_(v7248)),_oid_(v7249)))));
        if (((v7210->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
         { { { OID  v6980;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v10662 = v2072; 
                  OID  v10683;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.known_ask);
                    (v2072->args = list::alloc(1,_oid_(v7250)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v10683 = _oid_(v2072);
                    } 
                  (v10662->test = v10683);} 
                (v2072->arg = (INHERIT(v7210->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v7210->inverse)),OBJECT(Variable,_oid_(v7250)),_oid_(v7248)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v7210->inverse)),OBJECT(Variable,_oid_(v7250)),_oid_(v7248))));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                (v2072->other = Kernel.cfalse);
                v6980 = _oid_(v2072);
                } 
              v11373 = v11373->addFast(v6980);
              } 
            GC_OBJECT(list,v11373);} 
          v11373= GC_OBJECT(list,v11373->addFast(GC_OID((INHERIT(v7210->inverse->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v7210->inverse)),OBJECT(Variable,_oid_(v7249)),_oid_(v7248)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v7210->inverse)),OBJECT(Variable,_oid_(v7249)),_oid_(v7248))))));
          } 
        { ClaireRelation * v10684 = v7210; 
          OID  v10685;
          { lambda * v12313;{ OID  v159;
              { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                (v2072->var = v7250);
                (v2072->value = Produce_get_relation2(v7210,v7248));
                { Let * v10688 = v2072; 
                  OID  v10689;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    { If * v10690 = v2072; 
                      OID  v10691;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core._I_equal);
                        (v2072->args = list::alloc(2,_oid_(v7249),_oid_(v7250)));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v10691 = _oid_(v2072);
                        } 
                      (v10690->test = v10691);} 
                    { If * v10692 = v2072; 
                      OID  v10714;
                      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        (v2072->args = v11373);
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                        v10714 = _oid_(v2072);
                        } 
                      (v10692->arg = v10714);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    (v2072->other = Kernel.cfalse);
                    v10689 = _oid_(v2072);
                    } 
                  (v10688->arg = v10689);} 
                add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                v159 = _oid_(v2072);
                } 
              v12313 = lambda_I_list(list::alloc(2,_oid_(v7248),_oid_(v7249)),v159);
              } 
            
            v10685=_oid_(v12313);} 
          (v10684->if_write = v10685);} 
        } 
      { char * v8882 = GC_STRING(append_string(GC_STRING(string_I_symbol(v7210->name)),"_write"));
      compile_lambda_string(v8882,GC_OBJECT(lambda,OBJECT(lambda,v7210->if_write)),_oid_(Kernel._void));
      } 
    } 
  GC_UNBIND;} 

OID  compute_set_write_relation2(ClaireRelation *v7210)
{ GC_BIND;
  { OID Result = 0;
    { Variable * v7248;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2("XX"));
          (v2072->range = v7210->domain);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v7248 = v2072;
          } 
        GC_OBJECT(Variable,v7248);} 
      Variable * v7249;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2("YY"));
          (v2072->range = Kernel._bag);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v7249 = v2072;
          } 
        GC_OBJECT(Variable,v7249);} 
      Variable * v7250;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = symbol_I_string2("ZZ"));
          (v2072->range = member_type(v7210->range));
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v7250 = v2072;
          } 
        GC_OBJECT(Variable,v7250);} 
      list * v11373 = list::empty(Kernel._any);
      tformat_string("compute set_write for ~S \n",0,list::alloc(1,_oid_(v7210)));
      if (((v7210->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       { { OID  v10686;
          { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v2072->var = v7250);
            (v2072->set_arg = Produce_get_relation2(v7210,v7248));
            (v2072->arg = (INHERIT(v7210->inverse->isa,Kernel._property) ?  Produce_remove_property2((property *) OBJECT(property,_oid_(v7210->inverse)),OBJECT(Variable,_oid_(v7250)),_oid_(v7248)) :   Produce_remove_table2((table *) OBJECT(table,_oid_(v7210->inverse)),OBJECT(Variable,_oid_(v7250)),_oid_(v7248))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
            v10686 = _oid_(v2072);
            } 
          v11373 = v11373->addFast(v10686);
          } 
        GC_OBJECT(list,v11373);} 
      v11373= GC_OBJECT(list,v11373->addFast(GC_OID(Produce_erase_property2(((property *) v7210),v7248))));
      { { OID  v11644;
          { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
            (v2072->var = v7250);
            (v2072->set_arg = _oid_(v7249));
            (v2072->arg = (INHERIT(v7210->isa,Kernel._property) ?  Produce_put_property2((property *) OBJECT(property,_oid_(v7210)),OBJECT(Variable,_oid_(v7248)),_oid_(v7250)) :   Produce_put_table2((table *) OBJECT(table,_oid_(v7210)),OBJECT(Variable,_oid_(v7248)),_oid_(v7250))));
            add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
            v11644 = _oid_(v2072);
            } 
          v11373 = v11373->addFast(v11644);
          } 
        GC_OBJECT(list,v11373);} 
      { char * v8882 = GC_STRING(append_string(GC_STRING(string_I_symbol(v7210->name)),"_set_write"));
        { lambda * v12606;
          { { OID  v13566;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v2072->args = v11373);
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v13566 = _oid_(v2072);
                } 
              v12606 = lambda_I_list(list::alloc(2,_oid_(v7248),_oid_(v7249)),v13566);
              } 
            GC_OBJECT(lambda,v12606);} 
          Result = compile_lambda_string(v8882,v12606,_oid_(Kernel._void));
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_property2(property *v7242,Variable *v7248,OID v7249)
{ GC_BIND;
  { OID Result = 0;
    { list * v7236 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v11811);
        for (START(v7242->restrictions); NEXT(v11811);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v11811)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v7248->range)),domain_I_restriction(OBJECT(restriction,v11811))))) == CTRUE))
           { list * v14528;
            { { OID v_bag;
                GC_ANY(v14528= list::empty(Kernel.emptySet));
                ((list *) v14528)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v11811))));
                if (boolean_I_any(_oid_(v7242->multivalued_ask)) == CTRUE)
                 { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.add_I);
                  { Call * v10720 = v2072; 
                    list * v10721;
                    { OID v_bag;
                      GC_ANY(v10721= list::empty(Kernel.emptySet));
                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = v7242);
                          { Call * v10723 = v2072; 
                            list * v10724;
                            { OID v_bag;
                              GC_ANY(v10724= list::empty(Kernel.emptySet));
                              { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                                  (v2072->arg = _oid_(v7248));
                                  (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v11811)));
                                  add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                                  v_bag = _oid_(v2072);
                                  } 
                                GC_OID(v_bag);} 
                              ((list *) v10724)->addFast(v_bag);} 
                            (v10723->args = v10724);} 
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v10721)->addFast(v_bag);
                      ((list *) v10721)->addFast(v7249);} 
                    (v10720->args = v10721);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.put);
                    { Call * v11396 = v2072; 
                      list * v11397;
                      { OID v_bag;
                        GC_ANY(v11397= list::empty(Kernel.emptySet));
                        ((list *) v11397)->addFast(_oid_(v7242));
                        { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v2072->arg = _oid_(v7248));
                            (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v11811)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v11397)->addFast(v_bag);
                        ((list *) v11397)->addFast(v7249);} 
                      (v11396->args = v11397);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  ((list *) v14528)->addFast(v_bag);} 
              GC_OBJECT(list,v14528);} 
            v7236 = add_star_list(v7236,v14528);
            } 
          GC_UNLOOP;} 
        } 
      if (v7236->length == 2)
       Result = (*(v7236))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v7248));
          (v2072->args = v7236);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_erase_property2(property *v7242,Variable *v7248)
{ GC_BIND;
  { OID Result = 0;
    { list * v7236 = list::empty(Kernel._any);
      bag * v3321;
      if (v7242->multivalued_ask == Kernel._list)
       v3321 = list::empty(Kernel._any);
      else v3321 = set::empty(Kernel._any);
        cast_I_bag(v3321,member_type(v7242->range));
      { OID gc_local;
        ITERATE(v11811);
        for (START(v7242->restrictions); NEXT(v11811);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v11811)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v7248->range)),domain_I_restriction(OBJECT(restriction,v11811))))) == CTRUE))
           { list * v11686;
            { { OID v_bag;
                GC_ANY(v11686= list::empty(Kernel.emptySet));
                ((list *) v11686)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v11811))));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.put);
                    { Call * v11399 = v2072; 
                      list * v11400;
                      { OID v_bag;
                        GC_ANY(v11400= list::empty(Kernel.emptySet));
                        ((list *) v11400)->addFast(_oid_(v7242));
                        { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v2072->arg = _oid_(v7248));
                            (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v11811)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v11400)->addFast(v_bag);
                        { if (boolean_I_any(_oid_(v7242->multivalued_ask)) == CTRUE)
                           v_bag = _oid_(v3321);
                          else v_bag = OBJECT(slot,v11811)->DEFAULT;
                            GC_OID(v_bag);} 
                        ((list *) v11400)->addFast(v_bag);} 
                      (v11399->args = v11400);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v11686)->addFast(v_bag);} 
              GC_OBJECT(list,v11686);} 
            v7236 = add_star_list(v7236,v11686);
            } 
          GC_UNLOOP;} 
        } 
      if (v7236->length == 2)
       Result = (*(v7236))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v7248));
          (v2072->args = v7236);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_put_table2(table *v7242,Variable *v7248,OID v7249)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.put);
      { Call * v11401 = v2072; 
        list * v11402;
        { OID v_bag;
          GC_ANY(v11402= list::empty(Kernel.emptySet));
          ((list *) v11402)->addFast(_oid_(v7242));
          ((list *) v11402)->addFast(_oid_(v7248));
          if (boolean_I_any(_oid_(v7242->multivalued_ask)) == CTRUE)
           { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.add);
            (v2072->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v7242),_oid_(v7248))))),v7249));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          else v_bag = v7249;
            ((list *) v11402)->addFast(v_bag);} 
        (v11401->args = v11402);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_get_relation2(ClaireRelation *v7242,Variable *v7248)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v7242->isa,Kernel._table))
     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.nth);
      (v2072->args = list::alloc(2,_oid_(v7242),_oid_(v7248)));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else if (INHERIT(v7242->isa,Kernel._property))
     { list * v7236 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v11811);
        for (START(CLREAD(property,v7242,restrictions)); NEXT(v11811);)
        { GC_LOOP;
          if ((Kernel._slot == OBJECT(ClaireObject,v11811)->isa) && 
              (boolean_I_any(_oid_(_exp_type(GC_OBJECT(ClaireType,ptype_type(v7248->range)),domain_I_restriction(OBJECT(restriction,v11811))))) == CTRUE))
           { list * v107;
            { { OID v_bag;
                GC_ANY(v107= list::empty(Kernel.emptySet));
                ((list *) v107)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v11811))));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = ((property *) v7242));
                    { Call * v11404 = v2072; 
                      list * v11406;
                      { OID v_bag;
                        GC_ANY(v11406= list::empty(Kernel.emptySet));
                        { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                            (v2072->arg = _oid_(v7248));
                            (v2072->set_arg = domain_I_restriction(OBJECT(restriction,v11811)));
                            add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v11406)->addFast(v_bag);} 
                      (v11404->args = v11406);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v107)->addFast(v_bag);} 
              GC_OBJECT(list,v107);} 
            v7236 = add_star_list(v7236,v107);
            } 
          GC_UNLOOP;} 
        } 
      if (v7236->length == 2)
       Result = (*(v7236))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v7248));
          (v2072->args = v7236);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_property2(property *v7242,Variable *v7248,OID v7249)
{ GC_BIND;
  { OID Result = 0;
    { list * v7236 = list::empty(Kernel._any);
      { OID gc_local;
        ITERATE(v11811);
        for (START(v7242->restrictions); NEXT(v11811);)
        { GC_LOOP;
          if (Kernel._slot == OBJECT(ClaireObject,v11811)->isa)
           { list * v6787;
            { { OID v_bag;
                GC_ANY(v6787= list::empty(Kernel.emptySet));
                ((list *) v6787)->addFast(_oid_(domain_I_restriction(OBJECT(restriction,v11811))));
                if (boolean_I_any(_oid_(v7242->multivalued_ask)) == CTRUE)
                 { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel._delete);
                  { Call * v11428 = v2072; 
                    list * v11429;
                    { OID v_bag;
                      GC_ANY(v11429= list::empty(Kernel.emptySet));
                      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = v7242);
                          (v2072->args = list::alloc(1,_oid_(v7248)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v_bag = _oid_(v2072);
                          } 
                        GC_OID(v_bag);} 
                      ((list *) v11429)->addFast(v_bag);
                      ((list *) v11429)->addFast(v7249);} 
                    (v11428->args = v11429);} 
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.put);
                    (v2072->args = list::alloc(3,_oid_(v7242),
                      _oid_(v7248),
                      CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  ((list *) v6787)->addFast(v_bag);} 
              GC_OBJECT(list,v6787);} 
            v7236 = add_star_list(v7236,v6787);
            } 
          GC_UNLOOP;} 
        } 
      if (v7236->length == 2)
       Result = (*(v7236))[2];
      else { Case * v2072 = ((Case *) GC_OBJECT(Case,new_object_class(Language._Case)));
          (v2072->var = _oid_(v7248));
          (v2072->args = v7236);
          add_I_property(Kernel.instances,Language._Case,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  Produce_remove_table2(table *v7242,Variable *v7248,OID v7249)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.put);
      { Call * v11430 = v2072; 
        list * v11431;
        { OID v_bag;
          GC_ANY(v11431= list::empty(Kernel.emptySet));
          ((list *) v11431)->addFast(_oid_(v7242));
          ((list *) v11431)->addFast(_oid_(v7248));
          if (boolean_I_any(_oid_(v7242->multivalued_ask)) == CTRUE)
           { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._delete);
            (v2072->args = list::alloc(2,_oid_(list::alloc(2,_oid_(Kernel.nth),_oid_(list::alloc(2,_oid_(v7242),_oid_(v7248))))),v7249));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v_bag = _oid_(v2072);
            } 
          else v_bag = CNULL;
            ((list *) v11431)->addFast(v_bag);} 
        (v11430->args = v11431);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

void  Tighten_relation2(ClaireRelation *v7242)
{ GC_RESERVE(6);  // v3.0.55 optim !
  if (INHERIT(v7242->isa,Kernel._property))
   { ClaireType * v11084 = set::empty();
    ClaireType * v11097 = set::empty();
    { OID gc_local;
      ITERATE(v7243);
      for (START(CLREAD(property,v7242,restrictions)); NEXT(v7243);)
      { GC_LOOP;
        if (Kernel._slot == OBJECT(ClaireObject,v7243)->isa)
         { GC__ANY(v11084 = U_type(v11084,domain_I_restriction(OBJECT(restriction,v7243))), 3);
          GC__ANY(v11097 = U_type(v11097,GC_OBJECT(ClaireType,((multi_ask_any(_oid_(v7242)) == CTRUE) ?
            member_type(OBJECT(restriction,v7243)->range) :
            OBJECT(restriction,v7243)->range ))), 4);
          } 
        GC_UNLOOP;} 
      } 
    (v7242->open = 1);
    (v7242->domain = class_I_type(v11084));
    (v7242->range = ((v7242->multivalued_ask == Kernel._list) ?
      param_I_class(Kernel._list,class_I_type(v11097)) :
      ((v7242->multivalued_ask == Kernel._set) ?
        param_I_class(Kernel._set,class_I_type(v11097)) :
        v11097 ) ));
    ;} 
  GC_UNBIND;} 

void  lexical_num_any2(OID v1140,int v7239)
{ GC_BIND;
  if (INHERIT(OWNER(v1140),Language._Call))
   lexical_num_any2(GC_OID(_oid_(OBJECT(Call,v1140)->args)),v7239);
  else if (INHERIT(OWNER(v1140),Language._Instruction))
   { ClaireClass * v9399 = OBJECT(ClaireObject,v1140)->isa;
    if (contain_ask_set(Language._Instruction_with_var->descendents,_oid_(v9399)) == CTRUE)
     { put_property2(Kernel.index,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*Language.var)(v1140))),v7239);
      ++v7239;
      if (v7239 > Language._starvariable_index_star->value)
       (Language._starvariable_index_star->value= v7239);
      } 
    { OID gc_local;
      ITERATE(v7243);
      for (START(v9399->slots); NEXT(v7243);)
      { GC_LOOP;
        lexical_num_any2(GC_OID(get_slot(OBJECT(slot,v7243),OBJECT(ClaireObject,v1140))),v7239);
        GC_UNLOOP;} 
      } 
    } 
  else if (INHERIT(OWNER(v1140),Kernel._bag))
   { OID gc_local;
    ITERATE(v7248);
    for (START(OBJECT(bag,v1140)); NEXT(v7248);)
    lexical_num_any2(v7248,v7239);
    } 
  else ;GC_UNBIND;} 

ClaireType * c_type_Defrule2_Optimize(Defrule *v1140)
{ return (Kernel._any);} 

OID  c_code_Defrule_Optimize(Defrule *v1140,ClaireClass *v7243)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v11627 = GC_OID(get_symbol(v1140->ident));
      list * v7236 = list::empty(Kernel._any);
      tformat_string("compile a rule ~S \n",0,list::alloc(1,v11627));
      { OID gc_local;
        ITERATE(v7242);
        bag *v7242_support;
        v7242_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v11627)));
        for (START(v7242_support); NEXT(v7242);)
        if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v7242)) != CTRUE)
         Tighten_relation2(OBJECT(ClaireRelation,v7242));
        } 
      { OID gc_local;
        ITERATE(v7242);
        bag *v7242_support;
        v7242_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v11627)));
        for (START(v7242_support); NEXT(v7242);)
        { GC_LOOP;
          { if ((*Kernel.open)(v7242) < 2)
             { OID  v11592;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel.FINAL);
                (v2072->args = list::alloc(1,v7242));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v11592 = _oid_(v2072);
                } 
              v7236 = v7236->addFast(v11592);
              } 
            compile_if_write_relation(OBJECT(ClaireRelation,v7242));
            { OID  v8882 = GC_OID((*Kernel._7_plus)(GC_OID((*Kernel.name)(v7242)),
                _string_("_write")));
              char * v7243 = GC_STRING(string_I_symbol(OBJECT(symbol,v8882)));
              OID  v11422 = GC_OID((*Kernel.if_write)(v7242));
              compile_lambda_string(v7243,OBJECT(lambda,v11422),_oid_(Kernel._void));
              { OID  v12553;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.put);
                  (v2072->args = list::alloc(3,Optimize.if_write->value,
                    v7242,
                    _oid_(make_function_string(v7243))));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v12553 = _oid_(v2072);
                  } 
                v7236->addFast(v12553);
                } 
              } 
            } 
          GC_UNLOOP;} 
        } 
      { OID gc_local;
        ITERATE(v7242);
        bag *v7242_support;
        v7242_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Language.relations,v11627)));
        for (START(v7242_support); NEXT(v7242);)
        { GC_LOOP;
          if (eventMethod_ask_relation2(OBJECT(ClaireRelation,v7242)) == CTRUE)
           v7236= v7236->addFast(GC_OID(compileEventMethod_property(OBJECT(property,v7242))));
          GC_UNLOOP;} 
        } 
      { OID  v13514;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          (v2072->args = v7236);
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v13514 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v13514,
          _oid_(v7243));
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  compile_if_write_relation(ClaireRelation *v7210)
{ GC_BIND;
  { OID  v7236 = GC_OID(nth_table1(Language.demons,_oid_(v7210)));
    list * v5219 = GC_OBJECT(list,OBJECT(Language_demon,(*(OBJECT(bag,v7236)))[1])->formula->vars);
    list * v11373 = list::alloc(Kernel._any,1,GC_OID((*Optimize.Produce_put)(_oid_(v7210),
      (*(v5219))[1],
      (*(v5219))[2])));
    list * v11374;
    { { bag *v_list; OID v_val;
        OID v7248,CLcount;
        v_list = OBJECT(bag,v7236);
         v11374 = v_list->clone(Kernel._any);
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v7248 = (*(v_list))[CLcount];
          v_val = substitution_any(substitution_any(substitution_any(OBJECT(Language_demon,v7248)->formula->body,OBJECT(Variable,(*(OBJECT(Language_demon,v7248)->formula->vars))[3]),(*(v5219))[3]),OBJECT(Variable,(*(OBJECT(Language_demon,v7248)->formula->vars))[1]),(*(v5219))[1]),OBJECT(Variable,(*(OBJECT(Language_demon,v7248)->formula->vars))[2]),(*(v5219))[2]);
          
          (*((list *) v11374))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v11374);} 
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v5219))[1]),_oid_(v7210->domain));
    put_property2(Kernel.range,OBJECT(ClaireObject,(*(v5219))[2]),_oid_(v7210->range));
    { ITERATE(v7246);
      for (START(v5219); NEXT(v7246);)
      put_property2(Kernel.range,OBJECT(ClaireObject,v7246),_oid_(class_I_type(OBJECT(ClaireType,(*Kernel.range)(v7246)))));
      } 
    if ((INHERIT(OWNER((*(v11374))[1]),Language._If)) && 
        (eventMethod_ask_relation2(v7210) != CTRUE))
     { if (INHERIT(OWNER(OBJECT(If,(*(v11374))[1])->test),Language._And))
       { If * v11435 = OBJECT(If,(*(v11374))[1]); 
        OID  v11440;
        { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
          (v2072->args = cdr_list(GC_OBJECT(list,OBJECT(list,(*Core.args)(GC_OID(OBJECT(If,(*(v11374))[1])->test))))));
          add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
          v11440 = _oid_(v2072);
          } 
        (v11435->test = v11440);} 
      else ((*(v11374))[1]=OBJECT(If,(*(v11374))[1])->arg);
        } 
    if (((v7210->inverse == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     { if (multi_ask_any(_oid_(v7210)) != CTRUE)
       v11373= GC_OBJECT(list,v11373->addFast(GC_OID((*Optimize.Produce_remove)(_oid_(v7210->inverse),
        (*(v5219))[3],
        (*(v5219))[1]))));
      v11373= GC_OBJECT(list,v11373->addFast(GC_OID((*Optimize.Produce_put)(_oid_(v7210->inverse),
        (*(v5219))[2],
        (*(v5219))[1]))));
      } 
    { ClaireRelation * v11458 = v7210; 
      OID  v11459;
      { lambda * v13087;{ OID  v6695;
          if (eventMethod_ask_relation2(v7210) == CTRUE)
           { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            (v2072->args = v11374);
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v6695 = _oid_(v2072);
            } 
          else if (multi_ask_any(_oid_(v7210)) == CTRUE)
           { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v11462 = v2072; 
              OID  v11463;
              { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.NOT);
                { Call * v11464 = v2072; 
                  list * v11465;
                  { OID v_bag;
                    GC_ANY(v11465= list::empty(Kernel.emptySet));
                    { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel._Z);
                        (v2072->args = list::alloc(2,(*(v5219))[2],GC_OID(_oid_(readCall_relation(v7210,(*(v5219))[1])))));
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v11465)->addFast(v_bag);} 
                  (v11464->args = v11465);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v11463 = _oid_(v2072);
                } 
              (v11462->test = v11463);} 
            { If * v11466 = v2072; 
              OID  v11467;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                (v2072->args = append_list(v11373,v11374));
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v11467 = _oid_(v2072);
                } 
              (v11466->arg = v11467);} 
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            (v2072->other = Kernel.cfalse);
            v6695 = _oid_(v2072);
            } 
          else { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
              store_object(v2072,
                2,
                Kernel._object,
                (*(v5219))[3],
                CFALSE);
              (v2072->value = _oid_(readCall_relation(v7210,(*(v5219))[1])));
              { Let * v11489 = v2072; 
                OID  v11490;
                { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                  { If * v11491 = v2072; 
                    OID  v11492;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Core._I_equal);
                      (v2072->args = list::alloc(2,(*(v5219))[2],(*(v5219))[3]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v11492 = _oid_(v2072);
                      } 
                    (v11491->test = v11492);} 
                  { If * v11493 = v2072; 
                    OID  v11494;
                    { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                      (v2072->args = append_list(v11373,v11374));
                      add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                      v11494 = _oid_(v2072);
                      } 
                    (v11493->arg = v11494);} 
                  add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                  (v2072->other = Kernel.cfalse);
                  v11490 = _oid_(v2072);
                  } 
                (v11489->arg = v11490);} 
              add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
              v6695 = _oid_(v2072);
              } 
            v13087 = lambda_I_list(list::alloc(2,(*(v5219))[1],(*(v5219))[2]),v6695);
          } 
        
        v11459=_oid_(v13087);} 
      (v11458->if_write = v11459);} 
    } 
  GC_UNBIND;} 

OID  compileEventMethod_property(property *v7240)
{ GC_BIND;
  { OID Result = 0;
    { method * v7237 = OBJECT(method,(*(v7240->restrictions))[1]);
      char * v11483 = GC_STRING(append_string(GC_STRING(string_I_symbol(v7240->name)),"_write"));
      Result = add_method_I_method(v7237,
        list::alloc(2,_oid_(v7240->domain),_oid_(v7240->range)),
        _oid_(Kernel._void),
        0,
        make_function_string(v11483));
      } 
    GC_UNBIND; return (Result);} 
  } 

