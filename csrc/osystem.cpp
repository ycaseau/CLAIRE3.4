/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\osystem.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:46 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
char * home_void()
{ return (getenv_string("CLAIRE3_HOME"));} 

OID  safe_any2(OID v7248)
{ return (v7248);} 

ClaireType * safe_any2_type(ClaireType *v7248)
{ return (v7248);} 

ClaireType * c_type_any_Optimize(OID v1140)
{ GC_BIND;
  { ClaireType *Result ;
    { ClaireObject *V_CC ;
      if (INHERIT(OWNER(v1140),Language._Variable))
       { OID  v7242 = GC_OID(get_property(Kernel.range,OBJECT(ClaireObject,v1140)));
        if (v7242 == CNULL)
         V_CC = Kernel._any;
        else V_CC = (((INHERIT(OWNER(v7242),Core._Union)) && (equal(_oid_(OBJECT(Union,v7242)->t1),_oid_(Kernel.emptySet)) == CTRUE)) ?
          CLREAD(Union,OBJECT(Union,v7242)->t2,t2) :
          ptype_type(OBJECT(ClaireType,v7242)) );
        } 
      else if (INHERIT(OWNER(v1140),Core._global_variable))
       { ClaireType * v7242 = OBJECT(global_variable,v1140)->range;
        if (boolean_I_any(_oid_(v7242)) == CTRUE)
         V_CC = v7242;
        else V_CC = set::alloc(1,OBJECT(global_variable,v1140)->value);
          } 
      else if (INHERIT(OWNER(v1140),Kernel._unbound_symbol))
       V_CC = OBJECT(ClaireType,(*Optimize.Cerror)(_string_("[215] the symbol ~A is unbound_symbol"),
        _oid_(OBJECT(unbound_symbol,v1140)->name)));
      else if (INHERIT(OWNER(v1140),Kernel._error))
       V_CC = Kernel.emptySet;
      else if (INHERIT(OWNER(v1140),Language._Update))
       V_CC = OBJECT(ClaireType,(*Optimize.c_type)(OBJECT(Update,v1140)->value));
      else if (INHERIT(OWNER(v1140),Language._Construct))
       { if (((INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._List)) ? CTRUE : ((INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Set)) ? CTRUE : CFALSE)) != CTRUE)
         V_CC = Kernel._any;
        else { ClaireType * v16259 = Kernel.emptySet;
            { OID gc_local;
              ITERATE(v9243);
              for (START(OBJECT(Construct,v1140)->args); NEXT(v9243);)
              if (boolean_I_any(_oid_(v16259)) == CTRUE)
               v16259= meet_class(((ClaireClass *) v16259),class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v9243))));
              else v16259= class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v9243)));
                } 
            V_CC = nth_class1(((INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Set)) ?
              Kernel._set :
              Kernel._list ),v16259);
            } 
          } 
      else if (INHERIT(OWNER(v1140),Language._Instruction))
       close_exception(((general_error *) (*Core._general_error)(_string_("c_type of ~S is not defined"),
        _oid_(list::alloc(1,_oid_(OWNER(v1140)))))));
      else V_CC = set::alloc(1,v1140);
        Result= (ClaireType *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

OID  c_strict_code_any(OID v7248,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_strict_check)(GC_OID((*Optimize.c_code)(v7248,
        _oid_(v7243))),
      _oid_(v7243));
    GC_UNBIND; return (Result);} 
  } 

OID  c_strict_check_any_Optimize(OID v7248,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((INHERIT(v7243,Kernel._object)) && 
          (inherit_ask_class(stupid_t_any1(v7248),v7243) != CTRUE)))
     { if ((*Optimize.c_type)(v7248) == _oid_(Kernel._any))
       (*Optimize.Cerror)(_string_("Need explict cast: ~S is not a ~S"),
        v7248,
        _oid_(v7243));
      { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
        (v2072->arg = v7248);
        (v2072->set_arg = v7243);
        add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    else Result = v7248;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_any1_Optimize(OID v7248,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7249;
      { if (INHERIT(OWNER(v7248),Language._Call))
         v7249 = c_code_call_Call(OBJECT(Call,v7248),v7243);
        else v7249 = (*Optimize.c_code)(v7248);
          GC_OID(v7249);} 
      ClaireClass * v7250 = OBJECT(ClaireClass,(*Optimize.c_sort)(v7249));
      if ((v7243 == Kernel._void) || 
          ((v7250 == v7243) || 
            (Optimize.OPT->online_ask == CTRUE)))
       { if ((v7243 == Kernel._void) && 
            ((INHERIT(OWNER(v7248),Language._Call)) && (OBJECT(Call,v7248)->selector == Kernel._equal)))
         { warn_void();
          tformat_string("-- Equality meant as an assignment: ~S [264]\n",2,list::alloc(1,v7248));
          } 
        Result = v7249;
        } 
      else if (v7243 == Kernel._any)
       { if ((v7250 == Kernel._integer) && 
            ((INHERIT(OWNER(v7249),Language._Call_slot)) && 
              (((Optimize.compiler->overflow_ask == CTRUE) ? ((Optimize.compiler->class2file_ask == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
         Result = v7249;
        else if (INHERIT(OWNER(v7249),Optimize._to_C))
         Result = OBJECT(Compile_to_C,v7249)->arg;
        else { if (v7250 == Kernel._float)
             { (Optimize.OPT->protection = CTRUE);
              (Optimize.OPT->allocation = CTRUE);
              } 
            { Compile_to_CL * v2072 = ((Compile_to_CL *) GC_OBJECT(Compile_to_CL,new_object_class(Optimize._to_CL)));
              (v2072->arg = v7249);
              (v2072->set_arg = psort_any((*Optimize.c_type)(v7249)));
              add_I_property(Kernel.instances,Optimize._to_CL,11,_oid_(v2072));
              Result = _oid_(v2072);
              } 
            } 
          } 
      else if (v7250 == Kernel._any)
       { Compile_to_C * v2072 = ((Compile_to_C *) GC_OBJECT(Compile_to_C,new_object_class(Optimize._to_C)));
        (v2072->arg = v7249);
        (v2072->set_arg = v7243);
        add_I_property(Kernel.instances,Optimize._to_C,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      else Result = v7249;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_code_any2_Optimize(OID v1140)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v1140),Kernel._unbound_symbol))
     Result = (*Optimize.Cerror)(_string_("[215] the symbol ~A is unbound_symbol"),
      _oid_(OBJECT(unbound_symbol,v1140)->name));
    else if (INHERIT(OWNER(v1140),Language._Variable))
     Result = v1140;
    else if (INHERIT(OWNER(v1140),Core._global_variable))
     { c_register_object(OBJECT(ClaireObject,v1140));
      Result = v1140;
      } 
    else if (INHERIT(OWNER(v1140),Language._Optimized_instruction))
     Result = v1140;
    else if (INHERIT(OWNER(v1140),Language._Instruction))
     Result = (*Optimize.Cerror)(_string_("[internal] c_code(~S) should have a parameter"),
      v1140);
    else if (Kernel._set == OWNER(v1140))
     { if (OBJECT(bag,v1140)->length != 0)
       { Set * v7248;
        { { Set * v2072 = ((Set *) GC_OBJECT(Set,new_object_class(Language._Set)));
            (v2072->args = list_I_set(OBJECT(set,v1140)));
            add_I_property(Kernel.instances,Language._Set,11,_oid_(v2072));
            v7248 = v2072;
            } 
          GC_OBJECT(Set,v7248);} 
        if (of_bag(OBJECT(bag,v1140)) != Kernel._void)
         (v7248->of = of_bag(OBJECT(bag,v1140)));
        Result = (*Optimize.c_code)(_oid_(v7248));
        } 
      else Result = v1140;
        } 
    else if (INHERIT(OWNER(v1140),Kernel._list))
     { if (OBJECT(bag,v1140)->length != 0)
       { List * v7248;
        { { List * v2072 = ((List *) GC_OBJECT(List,new_object_class(Language._List)));
            (v2072->args = OBJECT(list,v1140));
            add_I_property(Kernel.instances,Language._List,11,_oid_(v2072));
            v7248 = v2072;
            } 
          GC_OBJECT(List,v7248);} 
        if (of_bag(OBJECT(bag,v1140)) != Kernel._void)
         (v7248->of = of_bag(OBJECT(bag,v1140)));
        Result = (*Optimize.c_code)(_oid_(v7248));
        } 
      else Result = v1140;
        } 
    else if (INHERIT(OWNER(v1140),Kernel._tuple))
     { OID  v14369;
      { Tuple * v2072 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
        (v2072->args = OBJECT(list,v1140));
        add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v2072));
        v14369 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v14369);
      } 
    else { if (INHERIT(OWNER(v1140),Kernel._thing))
         (*Optimize.c_register)(v1140);
        if ((Kernel._float == OWNER(v1140)) || 
            (INHERIT(OWNER(v1140),Kernel._function)))
         (Optimize.OPT->allocation = CTRUE);
        Result = v1140;
        } 
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_any(OID v1140)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v1140),Language._Variable))
     Result = CFALSE;
    else Result = ((INHERIT(OWNER(v1140),Core._global_variable)) ?
      not_any(_oid_((INHERIT(OBJECT(global_variable,v1140)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(global_variable,v1140)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(global_variable,v1140)->range)))))) :
      ((INHERIT(OWNER(v1140),Language._Construct)) ?
        ((Optimize.OPT->loop_gc == CTRUE) ? (((INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._List)) || 
            (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Set))) ? CTRUE: CFALSE): CFALSE) :
        ((INHERIT(OWNER(v1140),Language._Instruction)) ?
          CFALSE :
          ((Kernel._string == OWNER(v1140)) ?
            Optimize.OPT->use_string_update :
            CFALSE ) ) ) );
    return (Result);} 
  } 

ClaireClass * c_sort_any_Optimize(OID v1140)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireObject *V_CC ;
      if (INHERIT(OWNER(v1140),Core._global_variable))
       { V_CC = ((nativeVar_ask_global_variable(OBJECT(global_variable,v1140)) == CTRUE) ?
          ((equal(_oid_(OBJECT(global_variable,v1140)->range),_oid_(Kernel.emptySet)) == CTRUE) ?
            osort_any(_oid_(OWNER(OBJECT(global_variable,v1140)->value))) :
            osort_any(_oid_(OBJECT(global_variable,v1140)->range)) ) :
          Kernel._any );
        } 
      else if (INHERIT(OWNER(v1140),Language._Instruction))
       { if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Variable))
         V_CC = sort_Variable(OBJECT(Variable,v1140));
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Assign))
         V_CC = sort_Variable(OBJECT(Variable,OBJECT(Assign,v1140)->var));
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Call))
         V_CC = osort_any(_oid_(selector_psort_Call(OBJECT(Call,v1140))));
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Call_method))
         { V_CC = (((OBJECT(Call_method,v1140)->arg->selector == Core.externC) && 
              (OBJECT(Call_method,v1140)->args->length == 2)) ?
            psort_any((*(OBJECT(Call_method,v1140)->args))[2]) :
            c_srange_method(OBJECT(Call_method,v1140)->arg) );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Call_slot))
         V_CC = OBJECT(Call_slot,v1140)->selector->srange;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Call_table))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Call_array))
         { V_CC = ((OBJECT(Call_array,v1140)->test == _oid_(Kernel._float)) ?
            Kernel._float :
            Kernel._any );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Definition))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Optimize._to_C))
         V_CC = OBJECT(Compile_to_C,v1140)->set_arg;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Optimize._to_protect))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Compile_to_protect,v1140)->arg));
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Update))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Update,v1140)->value));
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._If))
         V_CC = psort_any(_oid_(meet_class(OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(If,v1140)->arg)),OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(If,v1140)->other)))));
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Handle))
         V_CC = psort_any(_oid_(meet_class(OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(ClaireHandle,v1140)->arg)),OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(ClaireHandle,v1140)->other)))));
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Let))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(OBJECT(Let,v1140)->arg));
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Optimize._to_CL))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Return))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._List))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Set))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Tuple))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Construct))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Gassign))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Super))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._For))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Exists))
         { V_CC = ((OBJECT(Exists,v1140)->other == CNULL) ?
            Kernel._any :
            Kernel._object );
          } 
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Iteration))
         V_CC = Kernel._object;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._And))
         V_CC = Kernel._boolean;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Or))
         V_CC = Kernel._boolean;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._While))
         V_CC = Kernel._any;
        else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Do))
         V_CC = OBJECT(ClaireClass,(*Optimize.c_sort)(GC_OID(last_list(OBJECT(Do,v1140)->args))));
        else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] c_sort is not implemented for ~S"),
            _oid_(list::alloc(1,_oid_(OWNER(v1140)))))));
          } 
      else V_CC = ((Kernel._float == OWNER(v1140)) ?
        Kernel._float :
        psort_any((*Optimize.c_type)(v1140)) );
      Result= (ClaireClass *) V_CC;} 
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * selector_psort_Call(Call *v1140)
{ { ClaireClass *Result ;
    { property * v7240 = v1140->selector;
      Result = (((v7240 == Core.base_I) || 
          (v7240 == Core.index_I)) ?
        Kernel._integer :
        ((v7240 == Optimize.anyObject_I) ?
          OBJECT(ClaireClass,(*(v1140->args))[1]) :
          ((v7240 == Optimize.object_I) ?
            OBJECT(ClaireClass,(*(v1140->args))[2]) :
            Kernel._any ) ) );
      } 
    return (Result);} 
  } 

int  c_status_any(OID v1140,list *v7236)
{ GC_BIND;
  { int Result = 0;
    if (INHERIT(OWNER(v1140),Language._Instruction))
     { if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Variable))
       { Result = (((OBJECT(Variable,v1140)->range == (NULL)) || 
            (_oid_((INHERIT(OBJECT(Variable,v1140)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(Variable,v1140)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(Variable,v1140)->range))))) != Kernel.ctrue)) ?
          ((contain_ask_list(v7236,v1140) == CTRUE) ?
            16 :
            (((((OBJECT(Variable,v1140)->range == (NULL)) ? CTRUE : CFALSE) != CTRUE) && 
                (_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(Variable,v1140)->range),Kernel._float) == CTRUE)) ?
              2 :
              0 ) ) :
          32 );
        } 
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Error))
       Result = 32;
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Printf))
       { int  v10337;
        { int  v6594 = 0;
          { OID gc_local;
            ITERATE(v6596);
            bag *v6596_support;
            v6596_support = GC_OBJECT(list,OBJECT(Construct,v1140)->args);
            for (START(v6596_support); NEXT(v6596);)
            { int  v6595 = c_status_any(v6596,v7236);
              v6594= c_or_integer(v6594,v6595);
              } 
            } 
          v10337 = v6594;
          } 
        Result = c_return_integer(0,v10337);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Construct))
       Result = 2;
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Definition))
       Result = 2;
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Call))
       { int  v11559 = c_status_call_property(OBJECT(Call,v1140)->selector,GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(v7236))[1]))));
        int  v11560;
        { int  v6597 = 0;
          { OID gc_local;
            ITERATE(v6600);
            bag *v6600_support;
            v6600_support = GC_OBJECT(list,OBJECT(Call,v1140)->args);
            for (START(v6600_support); NEXT(v6600);)
            { int  v6599 = c_status_any(v6600,v7236);
              v6597= c_or_integer(v6597,v6599);
              } 
            } 
          v11560 = v6597;
          } 
        Result = c_return_integer(v11559,v11560);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._If))
       { int  v11559 = c_status_any(GC_OID(OBJECT(If,v1140)->arg),v7236);
        int  v11560 = c_status_any(GC_OID(OBJECT(If,v1140)->other),v7236);
        Result = c_return_integer(c_or_integer(v11559,v11560),c_status_any(GC_OID(OBJECT(If,v1140)->test),v7236));
        } 
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Do))
       { OID  v7249 = GC_OID(last_list(OBJECT(Do,v1140)->args));
        int  v11559 = c_status_any(v7249,v7236);
        int  v11560;
        { int  v6601 = 0;
          { OID gc_local;
            ITERATE(v6623);
            bag *v6623_support;
            v6623_support = GC_OBJECT(list,OBJECT(Do,v1140)->args);
            for (START(v6623_support); NEXT(v6623);)
            if (equal(v6623,v7249) != CTRUE)
             { int  v6622 = c_status_any(v6623,v7236);
              v6601= c_or_integer(v6601,v6622);
              } 
            } 
          v11560 = v6601;
          } 
        Result = c_return_integer(v11559,v11560);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._For))
       Result = c_return_integer(c_status_any(GC_OID(OBJECT(Iteration,v1140)->arg),v7236),c_status_any(GC_OID(OBJECT(Iteration,v1140)->set_arg),v7236));
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Iteration))
       Result = c_return_integer(2,c_status_any(GC_OID(OBJECT(Iteration,v1140)->arg),v7236));
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Let))
       Result = c_return_integer(c_status_any(GC_OID(OBJECT(Let,v1140)->arg),v7236),c_status_any(GC_OID(OBJECT(Let,v1140)->value),v7236));
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Assign))
       Result = c_status_any(GC_OID(OBJECT(Assign,v1140)->arg),v7236);
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Gassign))
       Result = c_status_any(GC_OID(OBJECT(Gassign,v1140)->arg),v7236);
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._And))
       { int  v11298;
        { int  v6624 = 0;
          { OID gc_local;
            ITERATE(v6626);
            bag *v6626_support;
            v6626_support = GC_OBJECT(list,OBJECT(And,v1140)->args);
            for (START(v6626_support); NEXT(v6626);)
            { int  v6625 = c_status_any(v6626,v7236);
              v6624= c_or_integer(v6624,v6625);
              } 
            } 
          v11298 = v6624;
          } 
        Result = c_return_integer(0,v11298);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Or))
       { int  v12259;
        { int  v6627 = 0;
          { OID gc_local;
            ITERATE(v6629);
            bag *v6629_support;
            v6629_support = GC_OBJECT(list,OBJECT(Or,v1140)->args);
            for (START(v6629_support); NEXT(v6629);)
            { int  v6628 = c_status_any(v6629,v7236);
              v6627= c_or_integer(v6627,v6628);
              } 
            } 
          v12259 = v6627;
          } 
        Result = c_return_integer(0,v12259);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Cast))
       Result = c_status_any(GC_OID(OBJECT(Cast,v1140)->arg),v7236);
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Super))
       { int  v11559 = c_status_call_property(OBJECT(Super,v1140)->selector,GC_OBJECT(ClaireType,OBJECT(Super,v1140)->cast_to));
        int  v11560;
        { int  v6630 = 0;
          { OID gc_local;
            ITERATE(v6654);
            bag *v6654_support;
            v6654_support = GC_OBJECT(list,OBJECT(Super,v1140)->args);
            for (START(v6654_support); NEXT(v6654);)
            { int  v6631 = c_status_any(v6654,v7236);
              v6630= c_or_integer(v6630,v6631);
              } 
            } 
          v11560 = v6630;
          } 
        Result = c_return_integer(v11559,v11560);
        } 
      else if (INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Case))
       { int  v6655 = 0;
        { OID gc_local;
          ITERATE(v6657);
          bag *v6657_support;
          v6657_support = GC_OBJECT(list,OBJECT(Case,v1140)->args);
          for (START(v6657_support); NEXT(v6657);)
          { int  v6656 = c_status_any(v6657,v7236);
            v6655= c_or_integer(v6655,v6656);
            } 
          } 
        Result = v6655;
        } 
      else Result = ((INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._While)) ?
        c_return_integer(c_status_any(GC_OID(OBJECT(While,v1140)->arg),v7236),c_status_any(GC_OID(OBJECT(While,v1140)->test),v7236)) :
        ((INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Return)) ?
          c_status_any(GC_OID(OBJECT(Return,v1140)->arg),v7236) :
          ((INHERIT(OBJECT(ClaireObject,v1140)->isa,Language._Handle)) ?
            c_return_integer(c_or_integer(c_status_any(GC_OID(OBJECT(ClaireHandle,v1140)->arg),v7236),c_status_any(GC_OID(OBJECT(ClaireHandle,v1140)->other),v7236)),c_status_any(GC_OID(OBJECT(ClaireHandle,v1140)->test),v7236)) :
            ((INHERIT(OBJECT(ClaireObject,v1140)->isa,Kernel._unbound_symbol)) ?
              0 :
              (*Optimize.Cerror)(_string_("[internal] oops .. I forgot ~S"),
                _oid_(OWNER(v1140))) ) ) ) );
      } 
    else Result = ((Kernel._float == OWNER(v1140)) ?
      2 :
      ((Kernel._string == OWNER(v1140)) ?
        2 :
        ((INHERIT(OWNER(v1140),Kernel._function)) ?
          2 :
          ((INHERIT(OWNER(v1140),Core._Type)) ?
            2 :
            0 ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

int  c_or_integer(int v7248,int v7249)
{ { int Result = 0;
    { int  v7228 = or_integer(v7248,v7249);
      if ((BCONTAIN(v7228,5)) && 
          (((BCONTAIN(v7248,5)) ? ((BCONTAIN(v7249,5)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v7228= (v7228-exp2_integer(5));
      if ((BCONTAIN(v7228,6)) && 
          (((BCONTAIN(v7248,6)) ? ((BCONTAIN(v7249,6)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v7228= (v7228-exp2_integer(6));
      if ((BCONTAIN(v7228,4)) && 
          (((BCONTAIN(v7248,4)) ? ((BCONTAIN(v7249,4)) ? CTRUE: CFALSE): CFALSE) != CTRUE))
       v7228= (v7228-exp2_integer(4));
      Result = v7228;
      } 
    return (Result);} 
  } 

int  c_or_list(list *v7236)
{ { int Result = 0;
    { int  v7228 = 0;
      { ITERATE(v7248);
        for (START(v7236); NEXT(v7248);)
        v7228= c_or_integer(v7228,v7248);
        } 
      Result = v7228;
      } 
    return (Result);} 
  } 

int  status_I_restriction(restriction *v1140)
{ GC_BIND;
  { int Result = 0;
    if (Kernel._method == v1140->isa)
     { if (((CLREAD(method,v1140,status) == (CNULL)) ? CTRUE : CFALSE) != CTRUE)
       Result = CLREAD(method,v1140,status);
      else if (CLREAD(method,v1140,formula) == (NULL))
       { (CLREAD(method,v1140,status) = 0);
        Result = 0;
        } 
      else { (CLREAD(method,v1140,status) = 0);
          (CLREAD(method,v1140,status) = c_status_any(GC_OID(CLREAD(method,v1140,formula)->body),GC_OBJECT(list,CLREAD(method,v1140,formula)->vars)));
          Result = CLREAD(method,v1140,status);
          } 
        } 
    else Result = 0;
      GC_UNBIND; return (Result);} 
  } 

int  c_return_integer(int v7248,int v7249)
{ { int Result = 0;
    { int  v7228 = or_integer(v7248,v7249);
      if ((nth_integer(v7248,5) != CTRUE) && 
          (BCONTAIN(v7249,5)))
       v7228= (v7228-exp2_integer(5));
      if ((nth_integer(v7248,4) != CTRUE) && 
          (BCONTAIN(v7249,4)))
       v7228= (v7228-exp2_integer(4));
      Result = v7228;
      } 
    return (Result);} 
  } 

int  c_status_call_property(property *v1140,ClaireType *v7244)
{ { int Result = 0;
    { int  v7242 = ((stable_ask_relation(v1140) == CTRUE) ?
        0 :
        (*Language.bit_vector)(1,
          2,
          3) );
      { ITERATE(v7248);
        for (START(v1140->restrictions); NEXT(v7248);)
        if (boolean_I_any((*Core.glb)(_oid_(v7244),
          (*(OBJECT(restriction,v7248)->domain))[1])) == CTRUE)
         { if (Kernel._method == OBJECT(ClaireObject,v7248)->isa)
           { if (((last_list(OBJECT(method,v7248)->srange) == _oid_(Kernel._integer)) ? CTRUE : ((last_list(OBJECT(method,v7248)->srange) == _oid_(Kernel._object)) ? CTRUE : ((last_list(OBJECT(method,v7248)->srange) == _oid_(Kernel._any)) ? CTRUE : ((last_list(OBJECT(method,v7248)->srange) == _oid_(Kernel._void)) ? CTRUE : CFALSE)))) != CTRUE)
             v7242= c_or_integer(v7242,2);
            v7242= c_or_integer(v7242,status_I_restriction(OBJECT(restriction,v7248)));
            } 
          else if (Kernel._slot == OBJECT(ClaireObject,v7248)->isa)
           v7242= c_or_integer(v7242,exp2_integer(4));
          } 
        } 
      Result = v7242;
      } 
    return (Result);} 
  } 

OID  showstatus_method2(method *v7237)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    { list * v11373 = list::alloc(7,_string_("NEW_ALLOC"),
        _string_("BAG_UPDATE"),
        _string_("SLOT_UPDATE"),
        _string_("RETURN_ARG"),
        _string_("SAFE_RESULT"),
        _string_("SAFE_GC"),
        _string_("STRING_UPDATE"));
      list * v7236 = list::empty(Kernel._any);
      int  v7243 = v7237->status;
      { int  v7233 = 1;
        int  v6661 = 7;
        { OID gc_local;
          while ((v7233 <= v6661))
          { GC_LOOP;
            if (BCONTAIN(v7243,v7233))
             GC__ANY(v7236 = v7236->addFast((*(v11373))[v7233]), 1);
            ++v7233;
            GC_UNLOOP;} 
          } 
        } 
      Result = _oid_(v7236);
      } 
    GC_UNBIND; return (Result);} 
  } 

void  s_test_method2(method *v7237)
{ GC_BIND;
  { lambda * v11421 = GC_OBJECT(lambda,v7237->formula);
    int  v16379 = c_status_any(GC_OID(v11421->body),GC_OBJECT(list,v11421->vars));
    tformat_string("status(~S) := ~S \n",0,list::alloc(2,_oid_(v7237),v16379));
    (v7237->status = v16379);
    showstatus_method2(v7237);
    } 
  GC_UNBIND;} 

ClaireBoolean * legal_ask_module(module *v1140,OID v7248)
{ if ((v7248 == _oid_(Optimize.object_I)) || 
      (v7248 == _oid_(Optimize.anyObject_I))) 
  { { ClaireBoolean *Result ;
      Result = CTRUE;
      return (Result);} 
     } 
  else{ GC_BIND;
    { ClaireBoolean *Result ;
      if (Optimize.OPT->legal_modules->length != 0)
       { if ((contain_ask_set(Optimize.OPT->legal_modules,_oid_(v1140)) != CTRUE) && 
            ((Kernel._method == OWNER(v7248)) && ((OBJECT(method,v7248)->inline_ask == CFALSE) || 
                (Optimize.compiler->inline_ask != CTRUE))))
         { tformat_string("legal_modules = ~S\n",0,list::alloc(1,GC_OID(_oid_(Optimize.OPT->legal_modules))));
          tformat_string("---- ERROR: ~S implies using ~S !\n\n",0,list::alloc(2,v7248,_oid_(v1140)));
          Result = CFALSE;
          } 
        else Result = CTRUE;
          } 
      else { GC_OBJECT(set,Optimize.OPT->need_modules)->addFast(_oid_(v1140));
          Result = CTRUE;
          } 
        GC_UNBIND; return (Result);} 
    } 
  } 

OID  legal_ask_environment(ClaireEnvironment *v1140,OID v7248)
{ return (Kernel.ctrue);} 

OID  c_register_object(ClaireObject *v1140)
{ GC_BIND;
  { OID Result = 0;
    { OID  v7248 = GC_OID(get_module_object(v1140));
      if (v7248 != _oid_(ClEnv))
       Result = (*Optimize.legal_ask)(v7248,
        _oid_(v1140));
      else Result = Kernel.ctrue;
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_register_property(property *v1140)
{ GC_BIND;
  { OID Result = 0;
    { module * v7237 = ClEnv->module_I;
      OID  v11405 = GC_OID(get_module_object(v1140));
      if (((v11405 == _oid_(claire.it)) || 
            (v11405 == _oid_(v7237))) && 
          (Optimize.OPT->objects->memq(_oid_(v1140)) != CTRUE))
       GC_OBJECT(set,Optimize.OPT->properties)->addFast(_oid_(v1140));
      Result = c_register_object(v1140);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  selector_register_property(property *v1140)
{ c_register_property(v1140);
  if (allocate_ask_property(v1140) == Kernel.ctrue)
   (Optimize.OPT->allocation = CTRUE);
  return (_oid_(v1140));} 

OID  allocate_ask_property(property *v1140)
{ { OID Result = 0;
    { ITERATE(v7248);
      Result= Kernel.cfalse;
      for (START(v1140->restrictions); NEXT(v7248);)
      if (Kernel._slot == OBJECT(ClaireObject,v7248)->isa)
       { if ((_oid_((INHERIT(OBJECT(restriction,v7248)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v7248)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v7248)->range))))) != Kernel.ctrue) && 
            (OBJECT(slot,v7248)->srange != Kernel._any))
         { Result = Kernel.ctrue;
          break;} 
        else if ((_oid_((INHERIT(OBJECT(restriction,v7248)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v7248)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v7248)->range))))) != Kernel.ctrue) && 
            (gcsafe_ask_class(domain_I_restriction(OBJECT(restriction,v7248))) != CTRUE))
         { Result = 0;
          break;} 
        } 
      else if (Kernel._method == OBJECT(ClaireObject,v7248)->isa)
       { if ((BCONTAIN(status_I_restriction(OBJECT(restriction,v7248)),1)) || 
            ((((c_srange_method(OBJECT(method,v7248)) == Kernel._integer) ? CTRUE : ((c_srange_method(OBJECT(method,v7248)) == Kernel._object) ? CTRUE : ((c_srange_method(OBJECT(method,v7248)) == Kernel._any) ? CTRUE : CFALSE))) != CTRUE) || 
              (_oid_((INHERIT(OBJECT(restriction,v7248)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(restriction,v7248)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(restriction,v7248)->range))))) != Kernel.ctrue)))
         { Result = Kernel.ctrue;
          break;} 
        } 
      } 
    return (Result);} 
  } 

ClaireBoolean * stable_ask_relation(ClaireRelation *v1140)
{ { OID  v7237 = get_module_object(v1140);
    if (v1140->open == 2)
     (v1140->open = 1);
    } 
  return (((v1140->open <= 1) ? CTRUE : ((v1140->open == 4) ? CTRUE : CFALSE)));} 

OID  get_module_object(ClaireObject *v1140)
{ return (_oid_(defined_symbol(OBJECT(symbol,(*Kernel.name)(_oid_(v1140))))));} 

OID  known_I_listargs(listargs *v7236)
{ GC_BIND;
  GC_OBJECT(set,Optimize.OPT->to_remove)->addFast(_oid_(Reader.known_I));
  { OID Result = 0;
    { OID gc_local;
      ITERATE(v7242);
      Result= Kernel.cfalse;
      for (START(v7236); NEXT(v7242);)
      { GC_LOOP;
        if (INHERIT(OWNER(v7242),Kernel._property))
         GC_OBJECT(set,Optimize.OPT->knowns)->addFast(v7242);
        GC_UNLOOP;} 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  oload_module(module *v7237)
{ load_module(v7237);
  return (turbo_module(v7237));} 

OID  oload_string(char *v7230)
{ load_string(v7230);
  return (turbo_module(ClEnv->module_I));} 

OID  turbo_module(module *v7237)
{ GC_RESERVE(5);  // v3.0.55 optim !
  { OID Result = 0;
    { int  v11732 = ClEnv->verbose;
      (Optimize.OPT->online_ask = CTRUE);
      (ClEnv->verbose = 0);
      { OID gc_local;
        ITERATE(v7248);
        bag *v7248_support;
        v7248_support = Kernel._method->instances;
        for (START(v7248_support); NEXT(v7248);)
        { GC_LOOP;
          if ((OBJECT(restriction,v7248)->module_I == v7237) && 
              ((OBJECT(method,v7248)->inline_ask != CTRUE) && 
                (((OBJECT(method,v7248)->formula == (NULL)) ? CTRUE : CFALSE) != CTRUE)))
           { lambda * v7236 = GC_OBJECT(lambda,OBJECT(method,v7248)->formula);
            OID  v7249 = GC_OID(v7236->body);
            { ClaireHandler c_handle = ClaireHandler();
              if ERROR_IN 
              { { if (OBJECT(restriction,v7248)->range == Kernel._any)
                   update_property(Kernel.range,
                    OBJECT(ClaireObject,v7248),
                    5,
                    Kernel._object,
                    GC_OID((*Optimize.c_type)(v7249)));
                  (v7236->body = (*Optimize.c_code)(v7249,
                    _oid_(Kernel._any)));
                  (Language._starvariable_index_star->value= (v7236->vars->length+1));
                  (v7236->body = lexical_build_any(GC_OID(v7236->body),GC_OBJECT(list,v7236->vars),Language._starvariable_index_star->value));
                  (v7236->dimension = Language._starvariable_index_star->value);
                  } 
                ClEnv->cHandle--;} 
              else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
              { c_handle.catchIt();{ (v7236->body = v7249);
                  ;} 
                } 
              else PREVIOUS_HANDLER;} 
            } 
          GC_UNLOOP;} 
        } 
      (Optimize.OPT->online_ask = CFALSE);
      (ClEnv->verbose = v11732);
      Result = Kernel.ctrue;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  stats_meta_OPT(Optimize_meta_OPT *v7248)
{ ;} 

