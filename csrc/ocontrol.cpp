/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\ocontrol.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:46 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
ClaireType * c_type_Assign_Optimize(Assign *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v1140->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assign_Optimize(Assign *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7246 = GC_OID(v1140->var);
      OID  v7248 = GC_OID(v1140->arg);
      ClaireType * v9399 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v7248))));
      if (inherit_ask_class(OWNER(v7246),Language._Variable) != CTRUE)
       (*Optimize.Cerror)(_string_("[213] ~S is not a variable"),
        v7246);
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((int) v9399),((int) OBJECT(ClaireObject,GC_OID((*Kernel.range)(v7246)))))) != Kernel.ctrue)
       v7248= GC_OID((*Optimize.c_warn)(GC_OID(v1140->var),
        v7248,
        _oid_(v9399)));
      { OID  v313 = GC_OID(c_gc_I_any2(GC_OID(c_strict_code_any(v7248,psort_any((*Kernel.range)(v7246)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(GC_OID((*Kernel.range)(v7246)),
          _oid_(v9399))))));
        gc_register_Variable2(OBJECT(Variable,v7246),v313);
        { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
          (v2072->var = v7246);
          (v2072->arg = v313);
          add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
          Result = _oid_(v2072);
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Assign(Assign *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Gassign_Optimize(Gassign *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v1140->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Gassign_Optimize(Gassign *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v9241 = GC_OID(v1140->arg);
      ClaireType * v9399 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v9241))));
      if (boolean_I_any(_oid_(v1140->var->range)) != CTRUE)
       (*Optimize.Cerror)(_string_("[214] cannot assign ~S"),
        _oid_(v1140));
      if (_oid_((ClaireObject *) Core._inf_equalt->fcall(((int) v9399),((int) v1140->var->range))) != Kernel.ctrue)
       v9241= GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v9241,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v1140->var->range),
        _oid_(Kernel._type)))));
      { Gassign * v2072 = ((Gassign *) GC_OBJECT(Gassign,new_object_class(Language._Gassign)));
        store_object(v2072,
          2,
          Kernel._object,
          (*Optimize.c_code)(_oid_(v1140->var)),
          CFALSE);
        { Gassign * v7711 = v2072; 
          OID  v7712;
          if (nativeVar_ask_global_variable(v1140->var) == CTRUE)
           v7712 = c_strict_code_any(v9241,psort_any(_oid_(v1140->var->range)));
          else v7712 = (*Optimize.c_code)(v9241,
              _oid_(Kernel._any));
            (v7711->arg = v7712);} 
        add_I_property(Kernel.instances,Language._Gassign,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Gassign(Gassign *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_And_Optimize(And *v1140)
{ return (Kernel._boolean);} 

OID  c_code_And_Optimize(And *v1140)
{ GC_BIND;
  { OID Result = 0;
    { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
      { And * v7713 = v2072; 
        list * v7715;
        { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = GC_OBJECT(list,v1140->args);
           v7715 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v7248) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_("[206] void ~S in ~S"),
                v7248,
                _oid_(v1140));
              v_val = c_boolean_any(v7248);
              } 
            
            (*((list *) v7715))[CLcount] = v_val;} 
          } 
        (v7713->args = v7715);} 
      add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Or_Optimize(Or *v1140)
{ return (Kernel._boolean);} 

OID  c_code_Or_Optimize(Or *v1140)
{ GC_BIND;
  { OID Result = 0;
    { Or * v2072 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      { Or * v7716 = v2072; 
        list * v7718;
        { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = GC_OBJECT(list,v1140->args);
           v7718 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            { if ((*Optimize.c_type)(v7248) == _oid_(Kernel._void))
               (*Optimize.Cerror)(_string_("[206] void ~S in ~S"),
                v7248,
                _oid_(v1140));
              v_val = c_boolean_any(v7248);
              } 
            
            (*((list *) v7718))[CLcount] = v_val;} 
          } 
        (v7716->args = v7718);} 
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Quote_Optimize(Quote *v1140)
{ return (OWNER(v1140->arg));} 

void  c_code_Quote_Optimize(Quote *v1140)
{ (*Optimize.Cerror)(_string_("[internal] optimization of quote not implemented yet! ~S"),
    _oid_(v1140));
  } 

ClaireType * c_type_to_protect_Optimize(Compile_to_protect *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(v1140->arg));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_to_protect_Optimize(Compile_to_protect *v1140)
{ return (_oid_(v1140));} 

ClaireBoolean * c_gc_ask_to_protect(Compile_to_protect *v1140)
{ return (CFALSE);} 

ClaireType * c_type_Return_Optimize(Return *v1140)
{ return (Kernel._any);} 

OID  c_code_Return_Optimize(Return *v1140)
{ GC_BIND;
  (Optimize.OPT->loop_gc = CFALSE);
  { OID Result = 0;
    { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
      (v2072->arg = (*Optimize.c_code)(GC_OID(v1140->arg),
        _oid_(Kernel._any)));
      add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Handle_Optimize(ClaireHandle *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->other)))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Handle_Optimize(ClaireHandle *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { ClaireHandle * v7248;
      { { ClaireHandle * v2072 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
          (v2072->test = _oid_(Kernel._any));
          (v2072->arg = (*Optimize.c_code)(GC_OID(v1140->arg),
            _oid_(v7243)));
          (v2072->other = (*Optimize.c_code)(GC_OID(v1140->other),
            _oid_(v7243)));
          add_I_property(Kernel.instances,Language._Handle,11,_oid_(v2072));
          v7248 = v2072;
          } 
        GC_OBJECT(ClaireHandle,v7248);} 
      if (v1140->test != _oid_(Core._contradiction))
       (Optimize.OPT->allocation = CTRUE);
      (v7248->test = v1140->test);
      Result = _oid_(v7248);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Handle(ClaireHandle *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Cast_Optimize(Cast *v1140)
{ return (v1140->set_arg);} 

OID  c_code_Cast_Optimize(Cast *v1140)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v7249 = GC_OBJECT(ClaireType,v1140->set_arg);
      ClaireClass * v7288 = psort_any(_oid_(v7249));
      if ((INHERIT(v7249->isa,Core._Param)) && (((CLREAD(Param,v7249,arg) == Kernel._list) || 
            (CLREAD(Param,v7249,arg) == Kernel._set)) && 
          (Kernel._set == OWNER((*(CLREAD(Param,v7249,args)))[1]))))
       { OID  v15624 = GC_OID((*(OBJECT(set,(*(CLREAD(Param,v7249,args)))[1])))[1]);
        if ((equal(_oid_(_at_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg)))),Kernel.of)),v15624) == CTRUE) || 
            (Optimize.compiler->safety > 4))
         Result = (*Optimize.c_code)(GC_OID(v1140->arg),
          _oid_(v7288));
        else { OID  v602;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.check_in);
              (v2072->args = list::alloc(3,GC_OID(v1140->arg),
                _oid_(CLREAD(Param,v7249,arg)),
                v15624));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v602 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v602,
              _oid_(v7288));
            } 
          } 
      else if ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg)))),v7249) == CTRUE) || 
          (Optimize.compiler->safety > 1))
       Result = (*Optimize.c_code)(GC_OID(v1140->arg),
        _oid_(v7288));
      else { OID  v1563;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Core.check_in);
            (v2072->args = list::alloc(2,GC_OID(v1140->arg),_oid_(v7249)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v1563 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v1563,
            _oid_(v7288));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Super_Optimize(Super *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { list * v9399;
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
      property * v7243 = v1140->selector;
      ((*(v9399))[1]=_oid_(v1140->cast_to));
      { OID  v6284;
        { if (v7243->open == 3)
           v6284 = Core.nil->value;
          else v6284 = restriction_I_class(class_I_type(v1140->cast_to),v7243->definition,v9399);
            GC_OID(v6284);} 
        Result = ((Kernel._slot == OWNER(v6284)) ?
          OBJECT(restriction,v6284)->range :
          ((Kernel._method == OWNER(v6284)) ?
            use_range_method(OBJECT(method,v6284),v9399) :
            v7243->range ) );
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Super_Optimize(Super *v1140)
{ GC_BIND;
  { OID Result = 0;
    { property * v7243 = v1140->selector;
      list * v7236 = GC_OBJECT(list,v1140->args);
      list * v9399;
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
      OID  v6284;
      { if (v7243->open == 3)
         v6284 = Core.nil->value;
        else v6284 = restriction_I_class(class_I_type(v1140->cast_to),v7243->definition,v9399);
          GC_OID(v6284);} 
      if (Kernel._slot == OWNER(v6284))
       { Call_slot * v2072 = ((Call_slot *) GC_OBJECT(Call_slot,new_object_class(Language._Call_slot)));
        (v2072->selector = OBJECT(slot,v6284));
        (v2072->arg = (*Optimize.c_code)((*(v7236))[1],
          _oid_(psort_any(_oid_(domain_I_restriction(OBJECT(restriction,v6284)))))));
        (v2072->test = ((belong_to(OBJECT(slot,v6284)->DEFAULT,_oid_(OBJECT(restriction,v6284)->range)) != CTRUE) ? ((Optimize.compiler->safety < 5) ? CTRUE: CFALSE): CFALSE));
        add_I_property(Kernel.instances,Language._Call_slot,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (Kernel._method == OWNER(v6284))
       Result = c_code_method_method1(OBJECT(method,v6284),v7236,v9399);
      else Result = c_warn_Super(v1140,_oid_(v9399));
        } 
    GC_UNBIND; return (Result);} 
  } 

void  self_print_Call_function2(Optimize_Call_function2 *v1140)
{ print_any(_oid_(v1140->arg));
  princ_string("(");
  princ_bag(v1140->args);
  princ_string(")");
  } 

ClaireType * c_type_Call_function2_Optimize(Optimize_Call_function2 *v1140)
{ return (Kernel._any);} 

OID  c_code_Call_function2_Optimize(Optimize_Call_function2 *v1140)
{ GC_BIND;
  { OID Result = 0;
    { Optimize_Call_function2 * v2072 = ((Optimize_Call_function2 *) GC_OBJECT(Optimize_Call_function2,new_object_class(Optimize._Call_function2)));
      (v2072->arg = v1140->arg);
      { Optimize_Call_function2 * v7740 = v2072; 
        list * v7741;
        { bag *v_list; OID v_val;
          OID v7248,CLcount;
          v_list = v1140->args;
           v7741 = v_list->clone();
          for (CLcount= 1; CLcount <= v_list->length; CLcount++)
          { v7248 = (*(v_list))[CLcount];
            v_val = (*Optimize.c_code)(v7248,
              _oid_(Kernel._any));
            
            (*((list *) v7741))[CLcount] = v_val;} 
          } 
        (v7740->args = v7741);} 
      add_I_property(Kernel.instances,Optimize._Call_function2,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Assert_Optimize(Assert *v1140)
{ if (Optimize.OPT->online_ask == CTRUE) 
  { { OID Result = 0;
      Result = _oid_(v1140);
      return (Result);} 
     } 
  else{ GC_BIND;
    { OID Result = 0;
      if ((Optimize.compiler->safety == 0) || 
          (Optimize.compiler->debug_ask->length != 0))
       { OID  v4446;
        { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
          { If * v7743 = v2072; 
            OID  v7744;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.NOT);
              (v2072->args = list::alloc(1,GC_OID((*(v1140->args))[1])));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v7744 = _oid_(v2072);
              } 
            (v7743->test = v7744);} 
          { If * v7745 = v2072; 
            OID  v7746;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core.tformat);
              { Call * v7747 = v2072; 
                list * v7769;
                { OID v_bag;
                  GC_ANY(v7769= list::empty(Kernel.emptySet));
                  ((list *) v7769)->addFast(_string_("Assertion violation in ~A line ~A\n"));
                  ((list *) v7769)->addFast(0);
                  { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                      (v2072->args = list::alloc(2,GC_OID(_string_(v1140->external)),v1140->index));
                      add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v7769)->addFast(v_bag);} 
                (v7747->args = v7769);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v7746 = _oid_(v2072);
              } 
            (v7745->arg = v7746);} 
          (v2072->other = Kernel.cfalse);
          add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
          v4446 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v4446,
          _oid_(Kernel._any));
        } 
      else Result = Kernel.cfalse;
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  c_code_Trace_Optimize(Trace *v1140)
{ GC_BIND;
  { OID Result = 0;
    { list * v7225 = GC_OBJECT(list,v1140->args);
      if (Optimize.OPT->online_ask == CTRUE)
       Result = _oid_(v1140);
      else if ((v7225->length == 1) && 
          (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v7225))[1]))),Kernel._integer) == CTRUE))
       { OID  v14970;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.write);
          (v2072->args = list::alloc(3,_oid_(Kernel.verbose),
            _oid_(ClEnv),
            (*(v7225))[1]));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v14970 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v14970);
        } 
      else { ClaireBoolean * g0172I;
        { ClaireBoolean *v_and;
          { v_and = ((v7225->length > 1) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0172I =CFALSE; 
            else { v_and = ((Kernel._string == OWNER((*(v7225))[2])) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0172I =CFALSE; 
              else { { ClaireBoolean *v_or;
                  { v_or = ((Optimize.compiler->debug_ask->length != 0) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) v_and =CTRUE; 
                    else { { ClaireObject *V_CC ;
                        { ClaireHandler c_handle = ClaireHandler();
                          if ERROR_IN 
                          { V_CC = ((OPT_EVAL((*(v7225))[1]) <= ClEnv->verbose) ? CTRUE : CFALSE);
                            ClEnv->cHandle--;} 
                          else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
                          { c_handle.catchIt();V_CC = CTRUE;
                            } 
                          else PREVIOUS_HANDLER;} 
                        v_or= (ClaireBoolean *) V_CC;} 
                      if (v_or == CTRUE) v_and =CTRUE; 
                      else v_and = CFALSE;} 
                    } 
                  } 
                if (v_and == CFALSE) g0172I =CFALSE; 
                else g0172I = CTRUE;} 
              } 
            } 
          } 
        
        if (g0172I == CTRUE) { Call * v9222;
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Core.tformat);
                { Call * v7772 = v2072; 
                  list * v7773;
                  { OID v_bag;
                    GC_ANY(v7773= list::empty(Kernel.emptySet));
                    ((list *) v7773)->addFast((*(v7225))[2]);
                    ((list *) v7773)->addFast((*(v7225))[1]);
                    { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                        (v2072->args = skip_list(((list *) copy_bag(v7225)),2));
                        add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v7773)->addFast(v_bag);} 
                  (v7772->args = v7773);} 
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v9222 = v2072;
                } 
              GC_OBJECT(Call,v9222);} 
            { OID  v2430;
              if (inherit_ask_class(OWNER((*(v7225))[1]),Kernel._integer) != CTRUE)
               { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v7775 = v2072; 
                  OID  v7777;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel._inf_equal);
                    { Call * v7778 = v2072; 
                      list * v7779;
                      { OID v_bag;
                        GC_ANY(v7779= list::empty(Kernel.emptySet));
                        ((list *) v7779)->addFast((*(v7225))[1]);
                        { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v2072->selector = Kernel.verbose);
                            (v2072->args = list::alloc(1,_oid_(ClEnv)));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                            v_bag = _oid_(v2072);
                            } 
                          GC_OID(v_bag);} 
                        ((list *) v7779)->addFast(v_bag);} 
                      (v7778->args = v7779);} 
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v7777 = _oid_(v2072);
                    } 
                  (v7775->test = v7777);} 
                (v2072->arg = _oid_(v9222));
                (v2072->other = Kernel.cfalse);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v2430 = _oid_(v2072);
                } 
              else v2430 = _oid_(v9222);
                Result = (*Optimize.c_code)(v2430,
                _oid_(Kernel._any));
              } 
            } 
          else Result = Kernel.cfalse;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Assert_Optimize(Assert *v1140)
{ return (Kernel._any);} 

ClaireType * c_type_Trace_Optimize(Trace *v1140)
{ return (Kernel._any);} 

ClaireType * c_type_Branch_Optimize(Branch *v1140)
{ return (Kernel._boolean);} 

OID  c_code_Branch_Optimize(Branch *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v11032;
      { ClaireHandle * v2072 = ((ClaireHandle *) GC_OBJECT(ClaireHandle,new_object_class(Language._Handle)));
        { ClaireHandle * v7802 = v2072; 
          OID  v7803;
          { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v7804 = v2072; 
              list * v7805;
              { OID v_bag;
                GC_ANY(v7805= list::empty(Kernel.emptySet));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.choice);
                    (v2072->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7805)->addFast(v_bag);
                { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = (*(v1140->args))[1]);
                    (v2072->arg = Kernel.ctrue);
                    { If * v7806 = v2072; 
                      OID  v7807;
                      { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                        { Do * v7808 = v2072; 
                          list * v7809;
                          { OID v_bag;
                            GC_ANY(v7809= list::empty(Kernel.emptySet));
                            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                (v2072->selector = Kernel.backtrack);
                                (v2072->args = list::alloc(1,_oid_(ClEnv)));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                v_bag = _oid_(v2072);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v7809)->addFast(v_bag);
                            ((list *) v7809)->addFast(Kernel.cfalse);} 
                          (v7808->args = v7809);} 
                        add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                        v7807 = _oid_(v2072);
                        } 
                      (v7806->other = v7807);} 
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7805)->addFast(v_bag);} 
              (v7804->args = v7805);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v7803 = _oid_(v2072);
            } 
          (v7802->arg = v7803);} 
        (v2072->test = _oid_(Core._contradiction));
        { ClaireHandle * v7810 = v2072; 
          OID  v7831;
          { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
            { Do * v7832 = v2072; 
              list * v7833;
              { OID v_bag;
                GC_ANY(v7833= list::empty(Kernel.emptySet));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.backtrack);
                    (v2072->args = list::alloc(1,_oid_(ClEnv)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v7833)->addFast(v_bag);
                ((list *) v7833)->addFast(Kernel.cfalse);} 
              (v7832->args = v7833);} 
            add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
            v7831 = _oid_(v2072);
            } 
          (v7810->other = v7831);} 
        add_I_property(Kernel.instances,Language._Handle,11,_oid_(v2072));
        v11032 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v11032,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Macro_Optimize(Macro *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Language.macroexpand)(_oid_(v1140))),
      _oid_(v7243));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Macro_Optimize(Macro *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*Language.macroexpand)(_oid_(v1140)))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Printf_Optimize(Printf *v1140)
{ return (Kernel._any);} 

OID  c_code_Printf_Optimize(Printf *v1140)
{ GC_RESERVE(13);  // v3.0.55 optim !
  { OID Result = 0;
    { list * v7236 = GC_OBJECT(list,v1140->args);
      if (equal(_oid_(Kernel._string),_oid_(OWNER((*(v7236))[1]))) != CTRUE)
       Result = (*Optimize.Cerror)(_string_("[209] the first argument in ~S must be a string"),
        _oid_(v1140));
      else { char * v7243 = string_v((*(v7236))[1]);
          int  v7233 = 1;
          int  v7239 = get_string(v7243,_char_('~'));
          list * v7242 = list::empty(Kernel._any);
          { OID gc_local;
            while ((equal(v7239,0) != CTRUE))
            { GC_LOOP;
              { ClaireChar * v7237 = _char_(v7243[(v7239+1) - 1]);
                if (v7233 < v7236->length)
                 ++v7233;
                else (*Optimize.Cerror)(_string_("[210] not enough arguments in ~S"),
                    _oid_(v1140));
                  if (v7239 > 1)
                 { { OID  v10938;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.princ);
                      (v2072->args = list::alloc(1,GC_OID(_string_(substring_string(v7243,1,(v7239-1))))));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v10938 = _oid_(v2072);
                      } 
                    v7242 = v7242->addFast(v10938);
                    } 
                   GC__ANY(v7242, 7);} 
                { { OID  v11899;
                    if ('A' == ((char) v7237->ascii))
                     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.princ);
                      (v2072->args = list::alloc(1,(*(v7236))[v7233]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v11899 = _oid_(v2072);
                      } 
                    else if ('S' == ((char) v7237->ascii))
                     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.print);
                      (v2072->args = list::alloc(1,(*(v7236))[v7233]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v11899 = _oid_(v2072);
                      } 
                    else if ('F' == ((char) v7237->ascii))
                     { ClaireBoolean * v11485 = CFALSE;
                      int  v7234 = (integer_I_char(_char_(v7243[(v7239+2) - 1]))-48);
                      if ('%' == v7243[(v7239+2) - 1])
                       { v11485= CTRUE;
                        v7234= 1;
                        } 
                      else if ((v7234 < 0) || 
                          (v7234 > 9))
                       close_exception(((general_error *) (*Core._general_error)(_string_("[189] F requires a single digit integer in ~S"),
                        _oid_(list::alloc(1,_oid_(v1140))))));
                      if ((v11485 != CTRUE) && 
                          ('%' == v7243[(v7239+3) - 1]))
                       { v11485= CTRUE;
                        ++v7239;
                        } 
                      ++v7239;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Core.printFDigit);
                        { Call * v7836 = v2072; 
                          list * v7837;
                          { OID v_bag;
                            GC_ANY(v7837= list::empty(Kernel.emptySet));
                            if (v11485 == CTRUE)
                             { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v2072->selector = Kernel._star);
                              (v2072->args = list::alloc(2,(*(v7236))[v7233],GC_OID(_float_(100.0))));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                              v_bag = _oid_(v2072);
                              } 
                            else v_bag = (*(v7236))[v7233];
                              ((list *) v7837)->addFast(v_bag);
                            ((list *) v7837)->addFast(v7234);} 
                          (v7836->args = v7837);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v11899 = _oid_(v2072);
                        } 
                      } 
                    else if ('I' == ((char) v7237->ascii))
                     v11899 = (*(v7236))[v7233];
                    else v11899 = Kernel.cfalse;
                      v7242 = v7242->addFast(v11899);
                    } 
                   GC__ANY(v7242, 7);} 
                GC__STRING(v7243 = substring_string(v7243,(v7239+2),1000), 4);
                v7239= get_string(v7243,_char_('~'));
                } 
              GC_UNLOOP;} 
            } 
          if (boolean_I_any(_string_(v7243)) == CTRUE)
           { OID  v14782;
            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel.princ);
              (v2072->args = list::alloc(1,_string_(v7243)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v14782 = _oid_(v2072);
              } 
            v7242 = v7242->addFast(v14782);
            } 
          { OID  v15743;
            { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
              (v2072->args = v7242);
              add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
              v15743 = _oid_(v2072);
              } 
            Result = (*Optimize.c_code)(v15743,
              _oid_(Kernel._any));
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Error_Optimize(Error *v1140)
{ return (Kernel.emptySet);} 

OID  c_code_Error_Optimize(Error *v1140)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v7248 = Optimize.OPT->allocation;
      OID  v7249;
      { { OID  v320;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.close);
            { Call * v8513 = v2072; 
              list * v8514;
              { OID v_bag;
                GC_ANY(v8514= list::empty(Kernel.emptySet));
                { { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                    { Cast * v8515 = v2072; 
                      OID  v8516;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Optimize.anyObject_I);
                        { Call * v8517 = v2072; 
                          list * v8518;
                          { OID v_bag;
                            GC_ANY(v8518= list::empty(Kernel.emptySet));
                            ((list *) v8518)->addFast(_oid_(Core._general_error));
                            ((list *) v8518)->addFast(GC_OID((*Optimize.c_code)(GC_OID(car_list(v1140->args)),
                              _oid_(Kernel._any))));
                            { { OID  v13864;
                                if (v1140->args->length != 1)
                                 { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                                  (v2072->args = cdr_list(GC_OBJECT(list,v1140->args)));
                                  add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                                  v13864 = _oid_(v2072);
                                  } 
                                else v13864 = Core.nil->value;
                                  v_bag = (*Optimize.c_code)(v13864,
                                  _oid_(Kernel._any));
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v8518)->addFast(v_bag);} 
                          (v8517->args = v8518);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v8516 = _oid_(v2072);
                        } 
                      (v8515->arg = v8516);} 
                    (v2072->set_arg = Kernel._exception);
                    add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v8514)->addFast(v_bag);} 
              (v8513->args = v8514);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v320 = _oid_(v2072);
            } 
          v7249 = (*Optimize.c_code)(v320,
            _oid_(Kernel._void));
          } 
        GC_OID(v7249);} 
      (Optimize.OPT->allocation = v7248);
      Result = v7249;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * extendedTest_ask_If(If *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v9239 = v1140->test;
      if (INHERIT(OWNER(v9239),Language._Call))
       { if ((INHERIT(OWNER((*(OBJECT(Call,v9239)->args))[1]),Language._Variable)) && 
            (OBJECT(Call,v9239)->selector == Core.known_ask))
         Result = OBJECT(ClaireType,(*Kernel.range)((*(OBJECT(Call,v9239)->args))[1]));
        else Result = Kernel._any;
          } 
      else Result = Kernel._any;
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_If_Optimize(If *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v9237 = GC_OBJECT(ClaireType,extendedTest_ask_If(v1140));
      if (extended_ask_type(v9237) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v1140->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v9237)))))));
      { ClaireType * v4933 = GC_OBJECT(ClaireType,U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->other))))));
        if (extended_ask_type(v9237) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v1140->test)))))[1])),_oid_(v9237));
        Result = v4933;
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_If_Optimize(If *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v9237 = GC_OBJECT(ClaireType,extendedTest_ask_If(v1140));
      if (extended_ask_type(v9237) == CTRUE)
       range_sets_any(GC_OID((*(OBJECT(bag,(*Core.args)(GC_OID(v1140->test)))))[1]),GC_OBJECT(ClaireType,sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Core.t1)(_oid_(v9237)))))));
      if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->test))))),Kernel._boolean) != CTRUE) && 
          (Optimize.PENIBLE->value == Kernel.ctrue))
       { warn_void();
        tformat_string("CLAIRE 3.3 SYNTAX - Test in ~S should be a boolean [260]\n",2,list::alloc(1,_oid_(v1140)));
        } 
      { If * v4933;
        { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v2072->test = c_boolean_any(GC_OID(v1140->test)));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v1140->arg),
              _oid_(v7243)));
            (v2072->other = (*Optimize.c_code)(GC_OID(v1140->other),
              _oid_(v7243)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v4933 = v2072;
            } 
          GC_OBJECT(If,v4933);} 
        if (extended_ask_type(v9237) == CTRUE)
         put_property2(Kernel.range,GC_OBJECT(ClaireObject,OBJECT(ClaireObject,(*(OBJECT(bag,(*Core.args)(GC_OID(v1140->test)))))[1])),_oid_(v9237));
        Result = _oid_(v4933);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_If(If *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140->arg))) == CTRUE) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140->other))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Case_Optimize(Case *v1140)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { ClaireType *Result ;
    { OID  v3594 = GC_OID(v1140->var);
      OID  v9399;
      { if (INHERIT(OWNER(v3594),Language._Variable))
         v9399 = get_property(Kernel.range,OBJECT(ClaireObject,v3594));
        else v9399 = _oid_(Kernel._any);
          GC_OID(v9399);} 
      list * v7236 = GC_OBJECT(list,((list *) copy_bag(v1140->args)));
      ClaireType * v13957 = Kernel.emptySet;
      ClaireType * v15624 = Kernel.emptySet;
      { OID gc_local;
        while ((v7236->length > 0))
        { GC_LOOP;
          if (INHERIT(OWNER((*(v7236))[1]),Kernel._type))
           { GC__ANY(v15624 = U_type(v15624,OBJECT(ClaireType,(*(v7236))[1])), 6);
            if (osort_any(v9399) == osort_any((*(v7236))[1]))
             range_sets_any(v3594,OBJECT(ClaireType,(*(v7236))[1]));
            else if (osort_any(v9399) == Kernel._any)
             range_sets_any(v3594,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v7236))[1]))));
            } 
          else (*Optimize.Cerror)(_string_("[208] wrong type declaration for case: ~S in ~S"),
              GC_OID(car_list(v7236)),
              _oid_(v1140));
            GC__ANY(v13957 = U_type(v13957,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v7236))[2])))), 5);
          if (INHERIT(OWNER(v3594),Language._Variable))
           store_object(OBJECT(ClaireObject,v3594),
            3,
            Kernel._object,
            v9399,
            CFALSE);
          GC__ANY(v7236 = skip_list(v7236,2), 4);
          GC_UNLOOP;} 
        } 
      if (_inf_equal_type(OBJECT(ClaireType,v9399),v15624) == CTRUE)
       Result = v13957;
      else Result = ((_inf_equal_type(v13957,Kernel._boolean) == CTRUE) ?
        Kernel._boolean :
        Kernel._any );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Case_Optimize(Case *v1140,ClaireClass *v7243)
{ GC_RESERVE(13);  // v3.0.55 optim !
  { OID Result = 0;
    { OID  v3594 = GC_OID(v1140->var);
      OID  v9399;
      { if (INHERIT(OWNER(v3594),Language._Variable))
         v9399 = get_property(Kernel.range,OBJECT(ClaireObject,v3594));
        else v9399 = _oid_(Kernel._any);
          GC_OID(v9399);} 
      list * v7236 = GC_OBJECT(list,((list *) copy_bag(v1140->args)));
      OID  v15624 = _oid_(Kernel.emptySet);
      OID  v7812;
      { { OID  v14824;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel._Z);
            (v2072->args = list::alloc(2,v3594,(*(v7236))[1]));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v14824 = _oid_(v2072);
            } 
          v7812 = c_boolean_any(v14824);
          } 
        GC_OID(v7812);} 
      range_sets_any(v3594,OBJECT(ClaireType,(*(v7236))[1]));
      { If * v15989;
        { { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            (v2072->test = v7812);
            (v2072->arg = (*Optimize.c_code)((*(v7236))[2],
              _oid_(v7243)));
            (v2072->other = (*Optimize.c_code)(Kernel.cfalse,
              _oid_(v7243)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v15989 = v2072;
            } 
          GC_OBJECT(If,v15989);} 
        If * v6165 = v15989;
        if (INHERIT(OWNER(v3594),Language._Variable))
         store_object(OBJECT(ClaireObject,v3594),
          3,
          Kernel._object,
          v9399,
          CFALSE);
        v7236= GC_OBJECT(list,skip_list(v7236,2));
        { OID gc_local;
          while ((v7236->length > 0))
          { GC_LOOP;
            GC__OID(v15624 = _oid_(U_type(OBJECT(ClaireType,v15624),OBJECT(ClaireType,(*(v7236))[1]))), 7);
            if (_inf_equal_type(OBJECT(ClaireType,v9399),OBJECT(ClaireType,v15624)) == CTRUE)
             { if (osort_any(v9399) == osort_any((*(v7236))[1]))
               range_sets_any(v3594,OBJECT(ClaireType,(*(v7236))[1]));
              else if (osort_any(v9399) == Kernel._any)
               range_sets_any(v3594,GC_OBJECT(ClaireType,sort_abstract_I_type(OBJECT(ClaireType,(*(v7236))[1]))));
              (v6165->other = (*Optimize.c_code)((*(v7236))[2],
                _oid_(v7243)));
              if (INHERIT(OWNER(v3594),Language._Variable))
               store_object(OBJECT(ClaireObject,v3594),
                3,
                Kernel._object,
                v9399,
                CFALSE);
              { ;break;} 
              } 
            else { OID  v2893;
                { { OID  v15785;
                    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel._Z);
                      (v2072->args = list::alloc(2,v3594,(*(v7236))[1]));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v15785 = _oid_(v2072);
                      } 
                    v2893 = c_boolean_any(v15785);
                    } 
                  GC_OID(v2893);} 
                range_sets_any(v3594,OBJECT(ClaireType,(*(v7236))[1]));
                { If * v8522 = v6165; 
                  OID  v8544;
                  { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                    (v2072->test = v2893);
                    (v2072->arg = (*Optimize.c_code)((*(v7236))[2],
                      _oid_(v7243)));
                    (v2072->other = (*Optimize.c_code)(Kernel.cfalse,
                      _oid_(v7243)));
                    add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                    v8544 = _oid_(v2072);
                    } 
                  (v8522->other = v8544);} 
                GC__ANY(v6165 = OBJECT(If,v6165->other), 10);
                } 
              if (INHERIT(OWNER(v3594),Language._Variable))
             store_object(OBJECT(ClaireObject,v3594),
              3,
              Kernel._object,
              v9399,
              CFALSE);
            GC__ANY(v7236 = skip_list(v7236,2), 6);
            GC_UNLOOP;} 
          } 
        if ((INHERIT(OWNER(v3594),Language._Definition)) && (INHERIT(OBJECT(Definition,v3594)->arg->isa,Kernel._exception)))
         Result = v3594;
        else Result = _oid_(v15989);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Do_Optimize(Do *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(last_list(v1140->args))));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Do_Optimize(Do *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
      { Do * v8545 = v2072; 
        list * v8546;
        { int  v7237 = v1140->args->length;
          int  v7239 = 0;
          { bag *v_list; OID v_val;
            OID v7248,CLcount;
            v_list = GC_OBJECT(list,v1140->args);
             v8546 = v_list->clone();
            for (CLcount= 1; CLcount <= v_list->length; CLcount++)
            { v7248 = (*(v_list))[CLcount];
              { ++v7239;
                { OID  v8003;
                  if (v7239 == v7237)
                   v8003 = _oid_(v7243);
                  else v8003 = _oid_(Kernel._void);
                    v_val = (*Optimize.c_code)(v7248,
                    v8003);
                  } 
                } 
              
              (*((list *) v8546))[CLcount] = v_val;} 
            } 
          } 
        (v8545->args = v8546);} 
      add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Do(Do *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(last_list(v1140->args))));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Let_Optimize(Let *v1140)
{ GC_BIND;
  range_infers_Variable(GC_OBJECT(Variable,v1140->var),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->value)))));
  { ClaireType *Result ;
    Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg)));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Let_Optimize(Let *v1140,ClaireClass *v7243)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v9241 = GC_OID(v1140->value);
      ClaireType * v9399 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v9241))));
      range_infers_Variable(v1140->var,v9399);
      if (_inf_equal_type(v9399,GC_OBJECT(ClaireType,v1140->var->range)) != CTRUE)
       v9241= GC_OID(c_warn_Variable(GC_OBJECT(Variable,v1140->var),v9241,v9399));
      { Let * v7248;
        { { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v1140->var);
            (v2072->value = c_gc_I_any2(GC_OID(c_strict_code_any(v9241,psort_any(_oid_(v1140->var->range)))),v9399));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v1140->arg),
              _oid_(v7243)));
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v7248 = v2072;
            } 
          GC_OBJECT(Let,v7248);} 
        (v7248->isa = v1140->isa);
        if ((INHERIT(v7248->isa,Language._Let_star)) && 
            ((INHERIT(v9399->isa,Kernel._tuple)) && 
              (BCONTAIN(c_status_any(GC_OID(v1140->value),Kernel.nil),1))))
         { int  v7233 = 1;
          OID  v7250 = GC_OID(v7248->arg);
          { OID gc_local;
            while (((INHERIT(OWNER(v7250),Language._Let)) && 
                (v7233 <= ((bag *) v9399)->length)))
            { GC_LOOP;
              if ((((OBJECT(ClaireBoolean,(*Optimize.gcsafe_ask)((*(((bag *) v9399)))[v7233]))) == CTRUE) ? CTRUE : ((INHERIT(owner_any((*Kernel.value)(v7250)),Optimize._to_protect)) ? CTRUE : CFALSE)) != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { OID  v8965;
                  { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                    (v2072->arg = (*Kernel.value)(v7250));
                    add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                    v8965 = _oid_(v2072);
                    } 
                  write_property(Kernel.value,OBJECT(ClaireObject,v7250),v8965);
                  } 
                } 
              ++v7233;
              GC__OID(v7250 = (*Kernel.arg)(v7250), 8);
              GC_UNLOOP;} 
            } 
          } 
        Result = _oid_(v7248);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_When_Optimize(When *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v9241 = GC_OID(v1140->value);
      Variable * v7246 = GC_OBJECT(Variable,v1140->var);
      OID  v7228 = GC_OID(daccess_any(v9241,CTRUE));
      OID  v9399;
      { if (v7228 != CNULL)
         v9399 = (*Optimize.c_type)(v7228);
        else v9399 = (*Optimize.c_type)(v9241);
          GC_OID(v9399);} 
      if (extended_ask_type(OBJECT(ClaireType,v9399)) == CTRUE)
       v9399= GC_OID((*Core.t1)(v9399));
      range_infers_Variable(v7246,OBJECT(ClaireType,v9399));
      Result = U_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg)))),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->other)))));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_When_Optimize(When *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { OID  v9241 = GC_OID(v1140->value);
      Variable * v7246 = GC_OBJECT(Variable,v1140->var);
      OID  v7228 = GC_OID(daccess_any(v9241,CTRUE));
      Variable * v11684 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v1140->var->pname,_string_("test")),v1140->var->index,Kernel._any));
      OID  v9399;
      { if (v7228 != CNULL)
         v9399 = (*Optimize.c_type)(v7228);
        else v9399 = (*Optimize.c_type)(v9241);
          GC_OID(v9399);} 
      if (extended_ask_type(OBJECT(ClaireType,v9399)) == CTRUE)
       v9399= GC_OID((*Core.t1)(v9399));
      range_infers_Variable(v7246,OBJECT(ClaireType,v9399));
      if ((v7228 != CNULL) && 
          (extended_ask_type(OBJECT(ClaireType,(*Kernel.range)(GC_OID((*Kernel.selector)(v7228))))) != CTRUE))
       { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v2072->var = v7246);
        (v2072->value = c_gc_I_any2(v7228,OBJECT(ClaireType,v9399)));
        { Let * v8549 = v2072; 
          OID  v8550;
          { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
            { If * v8551 = v2072; 
              OID  v8552;
              { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
                (v2072->arg = ((method *) _at_property1(Core.identical_ask,Kernel._any)));
                (v2072->args = list::alloc(2,_oid_(v7246),GC_OID((*Optimize.c_code)(CNULL,
                  GC_OID((*Optimize.c_sort)(_oid_(v7246)))))));
                add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
                v8552 = _oid_(v2072);
                } 
              (v8551->test = v8552);} 
            (v2072->arg = (*Optimize.c_code)(GC_OID(v1140->other),
              _oid_(v7243)));
            (v2072->other = (*Optimize.c_code)(GC_OID(v1140->arg),
              _oid_(v7243)));
            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
            v8550 = _oid_(v2072);
            } 
          (v8549->arg = v8550);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else if (((*Optimize.c_sort)(_oid_(v7246)) == _oid_(Kernel._any)) && 
          ((_inf_equal_type(OBJECT(ClaireType,v9399),GC_OBJECT(ClaireType,v7246->range)) == CTRUE) && 
            (3 <= Optimize.compiler->safety)))
       { OID  v13769;
        { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v2072->var = v7246);
          (v2072->value = v9241);
          { Let * v8575 = v2072; 
            OID  v8576;
            { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
              { If * v8577 = v2072; 
                OID  v8578;
                { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Core._I_equal);
                  (v2072->args = list::alloc(2,_oid_(v7246),CNULL));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v8578 = _oid_(v2072);
                  } 
                (v8577->test = v8578);} 
              (v2072->arg = v1140->arg);
              (v2072->other = v1140->other);
              add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
              v8576 = _oid_(v2072);
              } 
            (v8575->arg = v8576);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v13769 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v13769,
          _oid_(v7243));
        } 
      else { OID  v5987;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v11684);
            (v2072->value = v9241);
            { Let * v8580 = v2072; 
              OID  v8581;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v8582 = v2072; 
                  OID  v8583;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core._I_equal);
                    (v2072->args = list::alloc(2,_oid_(v11684),CNULL));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v8583 = _oid_(v2072);
                    } 
                  (v8582->test = v8583);} 
                { If * v8584 = v2072; 
                  OID  v8606;
                  { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
                    (v2072->var = v7246);
                    { Let * v8607 = v2072; 
                      OID  v8608;
                      { Cast * v2072 = ((Cast *) GC_OBJECT(Cast,new_object_class(Language._Cast)));
                        (v2072->arg = _oid_(v11684));
                        (v2072->set_arg = OBJECT(ClaireType,v9399));
                        add_I_property(Kernel.instances,Language._Cast,11,_oid_(v2072));
                        v8608 = _oid_(v2072);
                        } 
                      (v8607->value = v8608);} 
                    (v2072->arg = v1140->arg);
                    add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
                    v8606 = _oid_(v2072);
                    } 
                  (v8584->arg = v8606);} 
                (v2072->other = (*Optimize.c_code)(GC_OID(v1140->other),
                  _oid_(v7243)));
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v8581 = _oid_(v2072);
                } 
              (v8580->arg = v8581);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v5987 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v5987,
            _oid_(v7243));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Let(Let *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_For_Optimize(For *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v1140->arg))),_oid_(v1140));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * infers_from_type2(ClaireType *v7244,OID v1140)
{ if (equal(_oid_(v7244),_oid_(Kernel.emptySet)) == CTRUE) 
  { { ClaireType *Result ;
      Result = sort_abstract_I_type(Kernel._boolean);
      return (Result);} 
     } 
  else{ GC_BIND;
    { ClaireType *Result ;
      if (Optimize.compiler->safety > 3)
       { tformat_string("... c_type(~S) -> ~S - ~S \n",2,list::alloc(3,v1140,
          _oid_(v7244),
          GC_OID(_oid_(sort_abstract_I_type(v7244)))));
        Result = sort_abstract_I_type(v7244);
        } 
      else Result = Kernel._any;
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  c_code_For_Optimize(For *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { OID  v11661 = GC_OID(v1140->set_arg);
      ClaireBoolean * v7226 = Optimize.OPT->protection;
      int  v11501 = Optimize.compiler->safety;
      Variable * v1817 = GC_OBJECT(Variable,v1140->var);
      Variable * v7246;
      { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
          (v2072->pname = v1817->pname);
          (v2072->range = v1817->range);
          (v2072->index = v1817->index);
          add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
          v7246 = v2072;
          } 
        GC_OBJECT(Variable,v7246);} 
      OID  v12368 = GC_OID(substitution_any(v1140->arg,v1817,_oid_(v7246)));
      OID  v507 = GC_OID(c_inline_arg_ask_any(v11661));
      (Optimize.OPT->protection = CFALSE);
      if (INHERIT(OWNER(v11661),Core._global_variable))
       { if (boolean_I_any(_oid_(OBJECT(global_variable,v11661)->range)) != CTRUE)
         { (v1140->set_arg = OBJECT(global_variable,v11661)->value);
          v11661= GC_OID(OBJECT(global_variable,v11661)->value);
          } 
        } 
      else if (INHERIT(OWNER(v11661),Language._Select))
       { ClaireType * v9239 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v11661)));
        if ((_inf_equal_type(v9239,Kernel._bag) != CTRUE) || 
            (_inf_equal_type(v9239,Kernel._set) == CTRUE))
         { v1140= GC_OBJECT(For,((For *) copy_object(v1140)));
          (v1140->isa = Language._Select);
          } 
        } 
      else if (INHERIT(OWNER(v11661),Kernel._class))
       { if ((OBJECT(ClaireClass,v11661)->open <= 1) && 
            (boolean_I_any(_oid_(OBJECT(ClaireClass,v11661)->subclass)) != CTRUE))
         { Iteration * v8609 = v1140; 
          OID  v8610;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.instances);
            (v2072->args = list::alloc(1,v11661));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v8610 = _oid_(v2072);
            } 
          (v8609->set_arg = v8610);} 
        } 
      { OID  v9239 = GC_OID((*Optimize.c_type)(GC_OID(v1140->set_arg)));
        ClaireType * v7931 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239)));
        ClaireType * v7932;
        { { ClaireType * v3971;
            { { OID v15730;{ OID  v4932;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.set_I);
                    (v2072->args = list::alloc(1,v11661));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v4932 = _oid_(v2072);
                    } 
                  v15730 = (*Optimize.c_type)(v4932);
                  } 
                
                v3971=OBJECT(ClaireType,v15730);} 
              GC_OBJECT(ClaireType,v3971);} 
            v7932 = pmember_type(v3971);
            } 
          GC_OBJECT(ClaireType,v7932);} 
        if (_inf_equal_type(v7932,v7931) == CTRUE)
         v7931= v7932;
        range_infers_for_Variable(v7246,v7931,OBJECT(ClaireType,v9239));
        (Optimize.compiler->safety = 1);
        v7931= GC_OBJECT(ClaireType,v7246->range);
        (v7246->range = ptype_type(v7931));
        { OID  v7237 = GC_OID(Iterate_I_Iteration(v1140));
          if (equal(_oid_(Kernel._method),_oid_(OWNER(v7237))) != CTRUE)
           { OID  v11405 = GC_OID(restriction_I_property(Language.iterate,list::alloc(3,v9239,
              _oid_(set::alloc(1,_oid_(v7246))),
              _oid_(Kernel._any)),CTRUE));
            if (Kernel._method == OWNER(v11405))
             v7237= v11405;
            } 
          (Optimize.compiler->safety = v11501);
          (v7246->range = v7931);
          { OID  v7242;
            { if ((Kernel._method == OWNER(v7237)) && (OBJECT(method,v7237)->inline_ask == CTRUE))
               { if ((Optimize.compiler->safety < 6) && 
                    (BCONTAIN(c_status_any(v12368,Kernel.nil),1)))
                 (Optimize.OPT->loop_gc = CTRUE);
                if (sort_abstract_ask_type(v7246->range) == CTRUE)
                 (v7246->range = CLREAD(Union,v7246->range,t2));
                v7242 = c_inline_method1(OBJECT(method,v7237),list::alloc(3,GC_OID(instruction_copy_any(GC_OID(v1140->set_arg))),
                  _oid_(v7246),
                  v12368),v7243);
                } 
              else if (boolean_I_any(v507) == CTRUE)
               { OID  v5893;
                { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v2072->var = v7246);
                  (v2072->set_arg = v507);
                  (v2072->arg = v12368);
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                  v5893 = _oid_(v2072);
                  } 
                v7242 = (*Optimize.c_code)(v5893,
                  _oid_(v7243));
                } 
              else if ((INHERIT(OWNER(v11661),Language._Call)) && (OBJECT(Call,v11661)->selector == Core.Id))
               v7242 = c_code_multiple_For(v1140,OBJECT(ClaireType,v9239),v7243);
              else { For * v11560;
                  { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                      (v2072->var = v7246);
                      (v2072->set_arg = c_gc_I_any1(GC_OID(enumerate_code_any(GC_OID(v1140->set_arg),OBJECT(ClaireType,v9239)))));
                      (v2072->arg = (*Optimize.c_code)(v12368,
                        _oid_(Kernel._void)));
                      add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                      v11560 = v2072;
                      } 
                    GC_OBJECT(For,v11560);} 
                  if (v7243 == Kernel._any)
                   v7242 = _oid_(v11560);
                  else { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
                      (v2072->arg = _oid_(v11560));
                      (v2072->set_arg = v7243);
                      add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
                      v7242 = _oid_(v2072);
                      } 
                    } 
                GC_OID(v7242);} 
            if ((Optimize.OPT->protection == CTRUE) && 
                ((0 <= Optimize.OPT->loop_index) && 
                  (Optimize.compiler->safety < 6)))
             (Optimize.OPT->loop_gc = CTRUE);
            (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v7226 == CTRUE) ? CTRUE : CFALSE)));
            Result = v7242;
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_multiple_For(For *v1140,ClaireType *v9239,ClaireClass *v7243)
{ GC_RESERVE(14);  // v3.0.55 optim !
  { OID Result = 0;
    { Variable * v7246 = GC_OBJECT(Variable,v1140->var);
      OID  v11661 = GC_OID((*(OBJECT(Call,v1140->set_arg)->args))[1]);
      Variable * v11684 = GC_OBJECT(Variable,Variable_I_symbol(append_symbol(v7246->pname,_string_("test")),v1140->var->index,v9239));
      Let * v7239;
      { { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
          (v2072->var = v11684);
          (v2072->value = v11661);
          { Let * v8615 = v2072; 
            OID  v8616;
            { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
              (v2072->var = v1140->var);
              (v2072->set_arg = enumerate_code_any(v11661,v9239));
              (v2072->arg = v1140->arg);
              add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
              v8616 = _oid_(v2072);
              } 
            (v8615->arg = v8616);} 
          add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
          v7239 = v2072;
          } 
        GC_OBJECT(Let,v7239);} 
      tformat_string("---- note: use an expended iteration for {~S} \n",0,list::alloc(1,_oid_(v1140)));
      { OID gc_local;
        ITERATE(v7242);
        for (START(Language.iterate->restrictions); NEXT(v7242);)
        { GC_LOOP;
          if ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v7242)),v9239) == CTRUE) && 
              ((_inf_equalt_class(domain_I_restriction(OBJECT(restriction,v7242)),Kernel._collection) == CTRUE) && 
                ((OBJECT(method,v7242)->inline_ask == CTRUE) && 
                  (belong_to(_oid_(v7246),(*(OBJECT(restriction,v7242)->domain))[2]) == CTRUE))))
           { Variable * v658;
            { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v2072->pname = v7246->pname);
                (v2072->range = v7246->range);
                (v2072->index = v7246->index);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
                v658 = v2072;
                } 
              GC_OBJECT(Variable,v658);} 
            OID  v12368 = GC_OID(substitution_any(v1140->arg,v7246,_oid_(v658)));
            { Let * v8637 = v7239; 
              OID  v8638;
              { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                { If * v8639 = v2072; 
                  OID  v8640;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel._Z);
                    (v2072->args = list::alloc(2,_oid_(v11684),(*(OBJECT(restriction,v7242)->domain))[1]));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v8640 = _oid_(v2072);
                    } 
                  (v8639->test = v8640);} 
                { If * v8641 = v2072; 
                  OID  v8644;
                  { if ((Optimize.compiler->safety < 6) && 
                        (BCONTAIN(c_status_any(GC_OID(v1140->arg),Kernel.nil),1)))
                     (Optimize.OPT->loop_gc = CTRUE);
                    if (sort_abstract_ask_type(v658->range) == CTRUE)
                     (v658->range = CLREAD(Union,v7246->range,t2));
                    v8644 = c_inline_method1(OBJECT(method,v7242),GC_OBJECT(list,list::alloc(3,_oid_(v11684),
                      _oid_(v658),
                      v12368)),v7243);
                    } 
                  (v8641->arg = v8644);} 
                (v2072->other = v7239->arg);
                add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                v8638 = _oid_(v2072);
                } 
              (v8637->arg = v8638);} 
            } 
          GC_UNLOOP;} 
        } 
      Result = (*Optimize.c_code)(_oid_(v7239),
        _oid_(v7243));
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_Iteration(Iteration *v1140)
{ return (CTRUE);} 

ClaireType * c_type_Iteration_Optimize(Iteration *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v9239 = GC_OID((*Optimize.c_type)(GC_OID(v1140->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v1140->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239))),OBJECT(ClaireType,v9239));
      Result = ((get_property(Kernel.of,v1140) != CNULL) ?
        param_I_class((((INHERIT(v1140->isa,Language._Select)) || 
            (INHERIT(v1140->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v1140))))) :
        nth_class1((((INHERIT(v1140->isa,Language._Select)) || 
            (INHERIT(v1140->isa,Language._Image))) ?
          Kernel._set :
          Kernel._list ),GC_OBJECT(ClaireType,(((INHERIT(v1140->isa,Language._Select)) || 
            (INHERIT(v1140->isa,Language._Lselect))) ?
          pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->set_arg))))) :
          ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg)))) ))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Iteration_Optimize(Iteration *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v11661 = GC_OID(v1140->set_arg);
      OID  v9239 = GC_OID((*Optimize.c_type)(v11661));
      if (INHERIT(v1140->isa,Language._For))
       Result = (*Optimize.c_code)(_oid_(v1140),
        _oid_(Kernel._any));
      else if ((INHERIT(v1140->isa,Language._Collect)) && (_inf_equal_type(OBJECT(ClaireType,v9239),Kernel._bag) == CTRUE))
       { (Optimize.OPT->allocation = CTRUE);
        range_infers_for_Variable(GC_OBJECT(Variable,v1140->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239))),OBJECT(ClaireType,v9239));
        { ClaireType * v11693 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg)))));
          Collect * v7248;
          { { Collect * v2072 = ((Collect *) GC_OBJECT(Collect,new_object_class(Language._Collect)));
              (v2072->var = v1140->var);
              (v2072->set_arg = c_gc_I_any1(GC_OID(c_strict_code_any(v11661,Kernel._bag))));
              (v2072->arg = (*Optimize.c_code)(GC_OID(v1140->arg),
                _oid_(Kernel._any)));
              add_I_property(Kernel.instances,Language._Collect,11,_oid_(v2072));
              v7248 = v2072;
              } 
            GC_OBJECT(Collect,v7248);} 
          if (v11693 == Kernel._void)
           (*Optimize.Cerror)(_string_("[205] use of void expression ~S in ~S"),
            GC_OID(v1140->arg),
            _oid_(v1140));
          if (get_property(Kernel.of,v1140) != CNULL)
           { if ((Optimize.compiler->safety > 4) || 
                (_inf_equal_type(v11693,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v1140))))) == CTRUE))
             { update_property(Kernel.of,
                v7248,
                5,
                Kernel._object,
                GC_OID((*Kernel.of)(_oid_(v1140))));
              Result = _oid_(v7248);
              } 
            else { warn_void();
                tformat_string("unsafe typed collect (~S): ~S not in ~S [261]\n",2,list::alloc(3,_oid_(v1140),
                  GC_OID((*Optimize.c_type)(GC_OID(v1140->arg))),
                  GC_OID((*Kernel.of)(_oid_(v1140)))));
                { OID  v2916;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Core.check_in);
                    (v2072->args = list::alloc(3,_oid_(v7248),
                      _oid_(Kernel._list),
                      GC_OID((*Kernel.of)(_oid_(v1140)))));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v2916 = _oid_(v2072);
                    } 
                  Result = (*Optimize.c_code)(v2916,
                    _oid_(Kernel._list));
                  } 
                } 
              } 
          else Result = _oid_(v7248);
            } 
        } 
      else { OID  v3321;
          if (INHERIT(v1140->isa,Language._Image))
           v3321 = _oid_(set::empty());
          else v3321 = _oid_(list::empty());
            Variable * v7246;
          { { int  v3878;
              { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
                v3878 = 0;
                } 
              v7246 = Variable_I_symbol(append_symbol(v1140->var->pname,_string_("_bag")),v3878,((INHERIT(v1140->isa,Language._Image)) ?
                Kernel._set :
                Kernel._list ));
              } 
            GC_OBJECT(Variable,v7246);} 
          if (get_property(Kernel.of,v1140) != CNULL)
           { ClaireType * v7231 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg))));
            if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v7231)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v1140))))) != CTRUE) && 
                (Optimize.compiler->safety <= 4))
             { warn_void();
              tformat_string("unsafe bag construction (~S) : a ~S is not a ~S [262]\n",2,list::alloc(3,GC_OID(_oid_(v1140->var)),
                _oid_(v7231),
                GC_OID((*Kernel.of)(_oid_(v1140)))));
              } 
            cast_I_bag(OBJECT(bag,v3321),OBJECT(ClaireType,(*Kernel.of)(_oid_(v1140))));
            (v7246->range = param_I_class(GC_OBJECT(ClaireClass,((ClaireClass *) v7246->range)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v1140))))));
            } 
          else if (Kernel._set == OWNER(v3321))
             { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
              (v2072->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
              v3321 = _oid_(v2072);
              } 
            else { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
                (v2072->of = Kernel.emptySet);
                add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
                v3321 = _oid_(v2072);
                } 
              { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v7246);
            (v2072->value = v3321);
            { Let * v8649 = v2072; 
              OID  v8668;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v8669 = v2072; 
                  list * v8670;
                  { OID v_bag;
                    GC_ANY(v8670= list::empty(Kernel.emptySet));
                    { { OID  v12479;
                        { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                          (v2072->var = v1140->var);
                          (v2072->set_arg = v11661);
                          { Iteration * v8672 = v2072; 
                            OID  v8673;
                            { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                              (v2072->selector = Kernel.add_I);
                              (v2072->args = list::alloc(2,_oid_(v7246),GC_OID(v1140->arg)));
                              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                              v8673 = _oid_(v2072);
                              } 
                            (v8672->arg = v8673);} 
                          add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                          v12479 = _oid_(v2072);
                          } 
                        v_bag = (*Optimize.c_code)(v12479,
                          _oid_(Kernel._any));
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v8670)->addFast(v_bag);
                    if (Optimize.OPT->online_ask != CTRUE)
                     { (Optimize.OPT->protection = CTRUE);
                      { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                        (v2072->arg = _oid_(v7246));
                        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      } 
                    else v_bag = _oid_(v7246);
                      ((list *) v8670)->addFast(v_bag);} 
                  (v8669->args = v8670);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v8668 = _oid_(v2072);
                } 
              (v8649->arg = v8668);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            Result = _oid_(v2072);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Select_Optimize(Select *v1140)
{ return (c_code_select_Iteration(v1140,Kernel._set));} 

OID  c_code_Lselect_Optimize(Lselect *v1140)
{ return (c_code_select_Iteration(v1140,Kernel._list));} 

OID  c_code_select_Iteration(Iteration *v1140,ClaireClass *v7248)
{ GC_BIND;
  { OID Result = 0;
    { OID  v11661 = GC_OID(v1140->set_arg);
      OID  v9239 = GC_OID((*Optimize.c_type)(v11661));
      OID  v11657 = GC_OID(enumerate_code_any(v11661,OBJECT(ClaireType,v9239)));
      bag * v3321;
      if (v7248 == Kernel._set)
       v3321 = set::empty();
      else v3321 = list::empty();
        Variable * v11683;
      { { int  v900;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v900 = 0;
            } 
          v11683 = Variable_I_symbol(append_symbol(v1140->var->pname,_string_("_in")),v900,Kernel._bag);
          } 
        GC_OBJECT(Variable,v11683);} 
      Variable * v11684;
      { { int  v1861;
          { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
            v1861 = 0;
            } 
          v11684 = Variable_I_symbol(append_symbol(v1140->var->pname,_string_("_out")),v1861,v7248);
          } 
        GC_OBJECT(Variable,v11684);} 
      if (get_property(Kernel.of,v1140) != CNULL)
       { ClaireType * v7231 = GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239)));
        if ((_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v7231)),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v1140))))) != CTRUE) && 
            (Optimize.compiler->safety <= 4))
         { warn_void();
          tformat_string("unsafe bag construction (~S) : a ~S is not a ~S [262]\n",2,list::alloc(3,GC_OID(_oid_(v1140->var)),
            _oid_(v7231),
            GC_OID((*Kernel.of)(_oid_(v1140)))));
          } 
        cast_I_bag(v3321,OBJECT(ClaireType,(*Kernel.of)(_oid_(v1140))));
        (v11684->range = param_I_class(v7248,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel.of)(_oid_(v1140))))));
        Result = inner_select_Iteration(v1140,_oid_(v11684),v11661,_oid_(v3321));
        } 
      else if (_inf_equal_type(OBJECT(ClaireType,v9239),v7248) == CTRUE)
       { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
        (v2072->var = v11683);
        (v2072->value = v11657);
        { Let * v8699 = v2072; 
          OID  v8700;
          { OID  v8541;
            { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
              { Compile_to_C * v8703 = v2072; 
                OID  v8704;
                { OID  v11425;
                  { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel.empty);
                    (v2072->args = list::alloc(1,_oid_(v11683)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v11425 = _oid_(v2072);
                    } 
                  v8704 = (*Optimize.c_code)(v11425,
                    _oid_(Kernel._bag));
                  } 
                (v8703->arg = v8704);} 
              (v2072->set_arg = v7248);
              add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
              v8541 = _oid_(v2072);
              } 
            v8700 = inner_select_Iteration(v1140,_oid_(v11684),_oid_(v11683),v8541);
            } 
          (v8699->arg = v8700);} 
        add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else { OID  v12385;
          if (v7248 == Kernel._set)
           { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v2072->of = Kernel.emptySet);
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
            v12385 = _oid_(v2072);
            } 
          else { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
              (v2072->of = Kernel.emptySet);
              add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
              v12385 = _oid_(v2072);
              } 
            Result = inner_select_Iteration(v1140,_oid_(v11684),v11661,v12385);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  inner_select_Iteration(Iteration *v1140,OID v11684,OID v11661,OID v3321)
{ GC_BIND;
  { OID Result = 0;
    { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
      store_object(v2072,
        2,
        Kernel._object,
        v11684,
        CFALSE);
      (v2072->value = v3321);
      { Let * v8707 = v2072; 
        OID  v8708;
        { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
          { Do * v8709 = v2072; 
            list * v8730;
            { OID v_bag;
              GC_ANY(v8730= list::empty(Kernel.emptySet));
              { { OID  v4603;
                  { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v2072->var = v1140->var);
                    (v2072->set_arg = v11661);
                    { Iteration * v8732 = v2072; 
                      OID  v8733;
                      { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v2072->test = v1140->arg);
                        { If * v8734 = v2072; 
                          OID  v8735;
                          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                            (v2072->selector = Kernel.add_I);
                            (v2072->args = list::alloc(2,v11684,GC_OID(_oid_(v1140->var))));
                            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                            v8735 = _oid_(v2072);
                            } 
                          (v8734->arg = v8735);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                        (v2072->other = Kernel.cfalse);
                        v8733 = _oid_(v2072);
                        } 
                      (v8732->arg = v8733);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v4603 = _oid_(v2072);
                    } 
                  v_bag = (*Optimize.c_code)(v4603,
                    _oid_(Kernel._any));
                  } 
                GC_OID(v_bag);} 
              ((list *) v8730)->addFast(v_bag);
              if (Optimize.OPT->online_ask != CTRUE)
               { (Optimize.OPT->protection = CTRUE);
                { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
                  (v2072->arg = v11684);
                  add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                } 
              else v_bag = v11684;
                ((list *) v8730)->addFast(v_bag);} 
            (v8709->args = v8730);} 
          add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
          v8708 = _oid_(v2072);
          } 
        (v8707->arg = v8708);} 
      add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Exists_Optimize(Exists *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v9239 = GC_OID((*Optimize.c_type)(GC_OID(v1140->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v1140->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239))),OBJECT(ClaireType,v9239));
      if (v1140->other == CNULL)
       Result = extends_type(GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239))));
      else Result = Kernel._boolean;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_Exists_Optimize(Exists *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { OID  v9239 = GC_OID((*Optimize.c_type)(GC_OID(v1140->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v1140->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239))),OBJECT(ClaireType,v9239));
      if (v1140->other == Kernel.ctrue)
       { OID  v10369;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core.NOT);
          { Call * v8738 = v2072; 
            list * v8739;
            { OID v_bag;
              GC_ANY(v8739= list::empty(Kernel.emptySet));
              { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                  (v2072->var = v1140->var);
                  (v2072->set_arg = v1140->set_arg);
                  { Iteration * v8762 = v2072; 
                    OID  v8763;
                    { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                      { If * v8764 = v2072; 
                        OID  v8765;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Core.NOT);
                          (v2072->args = list::alloc(1,GC_OID(v1140->arg)));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v8765 = _oid_(v2072);
                          } 
                        (v8764->test = v8765);} 
                      { If * v8766 = v2072; 
                        OID  v8767;
                        { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                          (v2072->arg = Kernel.ctrue);
                          add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                          v8767 = _oid_(v2072);
                          } 
                        (v8766->arg = v8767);} 
                      add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                      (v2072->other = Kernel.cfalse);
                      v8763 = _oid_(v2072);
                      } 
                    (v8762->arg = v8763);} 
                  add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                GC_OID(v_bag);} 
              ((list *) v8739)->addFast(v_bag);} 
            (v8738->args = v8739);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v10369 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v10369,
          _oid_(v7243));
        } 
      else if (v1140->other == CNULL)
       { Variable * v7246;
        { { int  v6431;
            { (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+1));
              v6431 = 0;
              } 
            v7246 = Variable_I_symbol(append_symbol(v1140->var->pname,_string_("_some")),v6431,GC_OBJECT(ClaireType,extends_type(GC_OBJECT(ClaireType,v1140->var->range))));
            } 
          GC_OBJECT(Variable,v7246);} 
        { OID  v7392;
          { Let * v2072 = ((Let *) GC_OBJECT(Let,new_object_class(Language._Let)));
            (v2072->var = v7246);
            (v2072->value = CNULL);
            { Let * v8770 = v2072; 
              OID  v8771;
              { Do * v2072 = ((Do *) GC_OBJECT(Do,new_object_class(Language._Do)));
                { Do * v8792 = v2072; 
                  list * v8793;
                  { OID v_bag;
                    GC_ANY(v8793= list::empty(Kernel.emptySet));
                    { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                        (v2072->var = v1140->var);
                        (v2072->set_arg = v1140->set_arg);
                        { Iteration * v8796 = v2072; 
                          OID  v8797;
                          { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                            (v2072->test = v1140->arg);
                            { If * v8798 = v2072; 
                              OID  v8799;
                              { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                                { Return * v8800 = v2072; 
                                  OID  v8801;
                                  { Assign * v2072 = ((Assign *) GC_OBJECT(Assign,new_object_class(Language._Assign)));
                                    (v2072->var = _oid_(v7246));
                                    (v2072->arg = _oid_(v1140->var));
                                    add_I_property(Kernel.instances,Language._Assign,11,_oid_(v2072));
                                    v8801 = _oid_(v2072);
                                    } 
                                  (v8800->arg = v8801);} 
                                add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                                v8799 = _oid_(v2072);
                                } 
                              (v8798->arg = v8799);} 
                            add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                            (v2072->other = Kernel.cfalse);
                            v8797 = _oid_(v2072);
                            } 
                          (v8796->arg = v8797);} 
                        add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                        v_bag = _oid_(v2072);
                        } 
                      GC_OID(v_bag);} 
                    ((list *) v8793)->addFast(v_bag);
                    ((list *) v8793)->addFast(_oid_(v7246));} 
                  (v8792->args = v8793);} 
                add_I_property(Kernel.instances,Language._Do,11,_oid_(v2072));
                v8771 = _oid_(v2072);
                } 
              (v8770->arg = v8771);} 
            add_I_property(Kernel.instances,Language._Let,11,_oid_(v2072));
            v7392 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v7392,
            _oid_(v7243));
          } 
        } 
      else { OID  v5376;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.boolean_I);
            { Call * v8803 = v2072; 
              list * v9474;
              { OID v_bag;
                GC_ANY(v9474= list::empty(Kernel.emptySet));
                { { For * v2072 = ((For *) GC_OBJECT(For,new_object_class(Language._For)));
                    (v2072->var = v1140->var);
                    (v2072->set_arg = v1140->set_arg);
                    { Iteration * v9475 = v2072; 
                      OID  v9476;
                      { If * v2072 = ((If *) GC_OBJECT(If,new_object_class(Language._If)));
                        (v2072->test = v1140->arg);
                        { If * v9477 = v2072; 
                          OID  v9478;
                          { Return * v2072 = ((Return *) GC_OBJECT(Return,new_object_class(Language._Return)));
                            (v2072->arg = Kernel.ctrue);
                            add_I_property(Kernel.instances,Language._Return,11,_oid_(v2072));
                            v9478 = _oid_(v2072);
                            } 
                          (v9477->arg = v9478);} 
                        add_I_property(Kernel.instances,Language._If,11,_oid_(v2072));
                        (v2072->other = Kernel.cfalse);
                        v9476 = _oid_(v2072);
                        } 
                      (v9475->arg = v9476);} 
                    add_I_property(Kernel.instances,Language._For,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v9474)->addFast(v_bag);} 
              (v8803->args = v9474);} 
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v5376 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v5376,
            _oid_(v7243));
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Image_Optimize(Image *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireType * v9239 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->set_arg)))));
      range_infers_for_Variable(GC_OBJECT(Variable,v1140->var),GC_OBJECT(ClaireType,pmember_type(v9239)),v9239);
      Result = ((((v1140->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v1140->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Select_Optimize(Select *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v9239 = GC_OID((*Optimize.c_type)(GC_OID(v1140->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v1140->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239))),OBJECT(ClaireType,v9239));
      Result = ((((v1140->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._set,GC_OBJECT(ClaireType,v1140->of)) :
        nth_class1(Kernel._set,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_Lselect_Optimize(Lselect *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { OID  v9239 = GC_OID((*Optimize.c_type)(GC_OID(v1140->set_arg)));
      range_infers_for_Variable(GC_OBJECT(Variable,v1140->var),GC_OBJECT(ClaireType,pmember_type(OBJECT(ClaireType,v9239))),OBJECT(ClaireType,v9239));
      Result = ((((v1140->of == (NULL)) ? CTRUE : CFALSE) != CTRUE) ?
        param_I_class(Kernel._list,GC_OBJECT(ClaireType,v1140->of)) :
        nth_class1(Kernel._list,GC_OBJECT(ClaireType,pmember_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->set_arg))))))) );
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_While_Optimize(While *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = infers_from_type2(GC_OBJECT(ClaireType,return_type_any(GC_OID(v1140->arg))),_oid_(v1140));
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_While_Optimize(While *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { ClaireBoolean * v7226 = Optimize.OPT->protection;
      (Optimize.OPT->protection = CFALSE);
      { While * v7242;
        { { While * v2072 = ((While *) GC_OBJECT(While,new_object_class(Language._While)));
            (v2072->test = c_boolean_any(GC_OID(v1140->test)));
            (v2072->arg = (*Optimize.c_code)(GC_OID(v1140->arg),
              _oid_(Kernel._void)));
            (v2072->other = v1140->other);
            add_I_property(Kernel.instances,Language._While,11,_oid_(v2072));
            v7242 = v2072;
            } 
          GC_OBJECT(While,v7242);} 
        if ((Optimize.OPT->protection == CTRUE) && 
            (0 <= Optimize.OPT->loop_index))
         (Optimize.OPT->loop_gc = CTRUE);
        (Optimize.OPT->protection = ((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v7226 == CTRUE) ? CTRUE : CFALSE)));
        if ((v7243 != Kernel._void) && 
            (v7243 != Kernel._any))
         { { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
            (v2072->arg = _oid_(v7242));
            (v2072->set_arg = v7243);
            add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
            Result = _oid_(v2072);
            } 
          } 
        else Result = _oid_(v7242);
          } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_I_Iteration(Iteration *v1140)
{ GC_BIND;
  { OID Result = 0;
    Result = restriction_I_property(Language.Iterate,list::alloc(3,_oid_(set::alloc(1,GC_OID(v1140->set_arg))),
      _oid_(set::alloc(1,GC_OID(_oid_(v1140->var)))),
      _oid_(Kernel._any)),CTRUE);
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_Interval(Interval *v7248,Variable *v7246,OID v7229)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v7246 = GC_OID(eval_any2(v7248->arg1,Core._Interval));
      int  v11335 = eval_any2(v7248->arg2,Core._Interval);
      { OID gc_local;
        Result= _oid_(CFALSE);
        while ((v7246 <= v11335))
        { GC_LOOP;
          ;GC__OID(v7246 = (*Core._plus)(v7246,
            1), 1);
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  iterate_array(OID *v7248,Variable *v7246,OID v7229)
{ { OID Result = 0;
    { int  v9229 = 1;
      OID * v9220 = v7248;
      int  v11335 = v9220[0];
      { Result= _oid_(CFALSE);
        while ((v9229 <= v11335))
        { { OID  v7246 = nth_array(v9220,v9229);
            ;++v9229;
            } 
          } 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_class(ClaireClass *v7248,Variable *v7246,OID v7229)
{ { OID Result = 0;
    { ITERATE(v3467);
      Result= Kernel.cfalse;
      for (START(v7248->descendents); NEXT(v3467);)
      { ClaireBoolean * v3468;
        { OID v15730;{ ITERATE(v7246);
            v15730= Kernel.cfalse;
            for (START(OBJECT(ClaireClass,v3467)->instances); NEXT(v7246);)
            ;} 
          
          v3468=OBJECT(ClaireBoolean,v15730);} 
        if (v3468 == CTRUE)
         { Result = _oid_(v3468);
          break;} 
        } 
      } 
    return (Result);} 
  } 

OID  Iterate_any1(OID v7248,Variable *v7246,OID v7229)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID  v7246 = GC_OID(OPT_EVAL((*(OBJECT(Call,v7248)->args))[1]));
      OID  v11335 = GC_OID(OPT_EVAL((*(OBJECT(Call,v7248)->args))[2]));
      { OID gc_local;
        Result= _oid_(CFALSE);
        while (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v7246,
          v11335))) == CTRUE))
        { GC_LOOP;
          ;GC__OID(v7246 = (*Core._plus)(v7246,
            1), 1);
          GC_UNLOOP;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Lselect(Lselect *v7248,Variable *v7246,OID v7229)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v7246);
      Result= Kernel.cfalse;
      bag *v7246_support;
      v7246_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v7248->set_arg)))));
      for (START(v7246_support); NEXT(v7246);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(v7248->arg,v7248->var,v7246)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Select(Select *v7248,Variable *v7246,OID v7229)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v7246);
      Result= Kernel.cfalse;
      bag *v7246_support;
      v7246_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v7248->set_arg)))));
      for (START(v7246_support); NEXT(v7246);)
      { GC_LOOP;
        if (boolean_I_any(eval_any(GC_OID(substitution_any(v7248->arg,v7248->var,v7246)))) == CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_Collect(Collect *v7248,Variable *v7246,OID v7229)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v1612);
      Result= Kernel.cfalse;
      bag *v1612_support;
      v1612_support = GC_OBJECT(bag,enumerate_any(GC_OID(eval_any(GC_OID(v7248->set_arg)))));
      for (START(v1612_support); NEXT(v1612);)
      { GC_LOOP;
        { OID  v7246 = GC_OID(eval_any(GC_OID(substitution_any(v7248->arg,v7248->var,v1612))));
          ;} 
        GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any2(OID v7248,Variable *v7246,OID v7229)
{ GC_BIND;
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v7246);
      Result= Kernel.cfalse;
      bag *v7246_support;
      v7246_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v7248)->args))[1]))));
      for (START(v7246_support); NEXT(v7246);)
      { GC_LOOP;
        if (equal(v7246,OPT_EVAL((*(OBJECT(Call,v7248)->args))[2])) != CTRUE)
         ;GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  Iterate_any3(OID v7248,Variable *v7246,OID v7229)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v7246);
    bag *v7246_support;
    v7246_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v7248)->args))[1]))));
    for (START(v7246_support); NEXT(v7246);)
    ;} 
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v7246);
      Result= Kernel.cfalse;
      bag *v7246_support;
      v7246_support = GC_OBJECT(bag,enumerate_any(GC_OID(OPT_EVAL((*(OBJECT(Call,v7248)->args))[2]))));
      for (START(v7246_support); NEXT(v7246);)
      ;} 
    GC_UNBIND; return (Result);} 
  } 

