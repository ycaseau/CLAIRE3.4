/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\otool.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:46 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
void  self_print_to_protect(Compile_to_protect *v7248)
{ GC_BIND;
  princ_string("[to_protect ");
  print_any(GC_OID(v7248->arg));
  princ_string("]");
  GC_UNBIND;} 

OID  self_eval_to_protect(Compile_to_protect *v7248)
{ GC_BIND;
  { OID Result = 0;
    Result = OPT_EVAL(v7248->arg);
    GC_UNBIND; return (Result);} 
  } 

void  self_print_to_CL(Compile_to_CL *v1140)
{ GC_BIND;
  princ_string("CL{");
  print_any(GC_OID(v1140->arg));
  princ_string("}:");
  print_any(_oid_(v1140->set_arg));
  princ_string("");
  GC_UNBIND;} 

ClaireType * c_type_to_CL_Optimize(Compile_to_CL *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = sort_abstract_I_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v1140->arg))));
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * c_gc_ask_to_CL(Compile_to_CL *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((gcsafe_ask_class(v1140->set_arg) != CTRUE) && 
        ((v1140->set_arg == Kernel._float) || 
            (_inf_equalt_class(v1140->set_arg,Kernel._cl_import) == CTRUE))) ? CTRUE : (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(v1140->arg)))) == CTRUE) ? CTRUE : CFALSE));
    GC_UNBIND; return (Result);} 
  } 

void  self_print_to_C(Compile_to_C *v1140)
{ GC_BIND;
  princ_string("C{");
  print_any(GC_OID(v1140->arg));
  princ_string("}:");
  print_any(_oid_(v1140->set_arg));
  princ_string("");
  GC_UNBIND;} 

ClaireBoolean * c_gc_ask_to_C(Compile_to_C *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((gcsafe_ask_class(v1140->set_arg) != CTRUE) ? (((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(GC_OID(v1140->arg)))) == CTRUE) ? (((_inf_equalt_class(v1140->set_arg,Kernel._object) == CTRUE) || 
        (v1140->set_arg == Kernel._string)) ? CTRUE: CFALSE): CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_to_C_Optimize(Compile_to_C *v1140)
{ GC_BIND;
  { ClaireType *Result ;
    Result = glb_class(v1140->set_arg,GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(v1140->arg))))));
    GC_UNBIND; return (Result);} 
  } 

void  self_print_C_cast(Compile_C_cast *v1140)
{ GC_BIND;
  princ_string("<");
  print_any(GC_OID(v1140->arg));
  princ_string(":");
  print_any(_oid_(v1140->set_arg));
  princ_string(">");
  GC_UNBIND;} 

ClaireBoolean * c_gc_ask_C_cast(Compile_C_cast *v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140->arg));
    GC_UNBIND; return (Result);} 
  } 

ClaireType * c_type_C_cast_Optimize(Compile_C_cast *v1140)
{ return (v1140->set_arg);} 

OID  c_code_C_cast_Optimize(Compile_C_cast *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(v7243,Kernel._object))
     { Compile_C_cast * v2072 = ((Compile_C_cast *) GC_OBJECT(Compile_C_cast,new_object_class(Optimize._C_cast)));
      (v2072->arg = (*Optimize.c_code)(GC_OID(v1140->arg),
        _oid_(v7243)));
      (v2072->set_arg = v1140->set_arg);
      add_I_property(Kernel.instances,Optimize._C_cast,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else Result = (*Optimize.c_code)(GC_OID(v1140->arg),
        _oid_(v7243));
      GC_UNBIND; return (Result);} 
  } 

void  self_print_Pattern(Optimize_ClairePattern *v1140)
{ GC_BIND;
  print_any(_oid_(v1140->selector));
  princ_string("[tuple(");
  princ_bag(GC_OBJECT(list,v1140->arg));
  princ_string(")]");
  GC_UNBIND;} 

ClaireBoolean * _Z_any3(OID v7248,Optimize_ClairePattern *v7249)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v7248),Language._Call))
     { ClaireBoolean *v_and;
      { v_and = ((OBJECT(Call,v7248)->selector == v7249->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { { list * v5438;
            { { bag *v_list; OID v_val;
                OID v7250,CLcount;
                v_list = GC_OBJECT(list,OBJECT(Call,v7248)->args);
                 v5438 = v_list->clone();
                for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                { v7250 = (*(v_list))[CLcount];
                  v_val = (*Optimize.c_type)(v7250);
                  
                  (*((list *) v5438))[CLcount] = v_val;} 
                } 
              GC_OBJECT(list,v5438);} 
            v_and = tmatch_ask_list(v5438,GC_OBJECT(list,v7249->arg));
            } 
          if (v_and == CFALSE) Result =CFALSE; 
          else Result = CTRUE;} 
        } 
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

ClaireType * glb_Pattern(Optimize_ClairePattern *v7248,ClaireType *v7249)
{ return (Kernel.emptySet);} 

ClaireBoolean * less_ask_Pattern(Optimize_ClairePattern *v7248,OID v7249)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v7249),Optimize._Pattern))
     { ClaireBoolean *v_and;
      { v_and = ((v7248->selector == OBJECT(Optimize_ClairePattern,v7249)->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = ((v7248->arg->length == OBJECT(Optimize_ClairePattern,v7249)->arg->length) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v7360;
              { int  v7233 = 1;
                int  v6687 = v7248->arg->length;
                { OID gc_local;
                  v7360= _oid_(CFALSE);
                  while ((v7233 <= v6687))
                  { GC_LOOP;
                    if (_equaltype_ask_any(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(v7248->arg))[v7233])),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(OBJECT(Optimize_ClairePattern,v7249)->arg))[v7233]))) != CTRUE)
                     { v7360 = Kernel.ctrue;
                      break;} 
                    ++v7233;
                    GC_UNLOOP;} 
                  } 
                } 
              v_and = not_any(v7360);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    else Result = OBJECT(ClaireBoolean,(*Core._inf_equalt)(_oid_(Language._Call),
        v7249));
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * less_ask_any(OID v7248,Optimize_ClairePattern *v7249)
{ GC_BIND;
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v7248),Optimize._Pattern))
     { ClaireBoolean *v_and;
      { v_and = ((OBJECT(Optimize_ClairePattern,v7248)->selector == v7249->selector) ? CTRUE : CFALSE);
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = ((OBJECT(Optimize_ClairePattern,v7248)->arg->length == v7249->arg->length) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v9282;
              { int  v7233 = 1;
                int  v6689 = OBJECT(Optimize_ClairePattern,v7248)->arg->length;
                { OID gc_local;
                  v9282= _oid_(CFALSE);
                  while ((v7233 <= v6689))
                  { GC_LOOP;
                    if (_equaltype_ask_any(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(OBJECT(Optimize_ClairePattern,v7248)->arg))[v7233])),GC_OBJECT(ClaireType,OBJECT(ClaireType,(*(v7249->arg))[v7233]))) != CTRUE)
                     { v9282 = Kernel.ctrue;
                      break;} 
                    ++v7233;
                    GC_UNLOOP;} 
                  } 
                } 
              v_and = not_any(v9282);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      } 
    else Result = CFALSE;
      GC_UNBIND; return (Result);} 
  } 

Optimize_ClairePattern * nth_property(property *v7240,tuple *v7248)
{ GC_BIND;
  { Optimize_ClairePattern *Result ;
    { Optimize_ClairePattern * v2072 = ((Optimize_ClairePattern *) GC_OBJECT(Optimize_ClairePattern,new_object_class(Optimize._Pattern)));
      (v2072->selector = v7240);
      (v2072->arg = list_I_tuple(v7248));
      add_I_property(Kernel.instances,Optimize._Pattern,11,_oid_(v2072));
      Result = v2072;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  warn_void()
{ GC_BIND;
  if (Optimize.OPT->in_method != CNULL)
   tformat_string("---- WARNING[in ~S]: ",2,list::alloc(1,GC_OID(Optimize.OPT->in_method)));
  else tformat_string("---- WARNING: ",2,list::empty());
    GC_UNBIND;} 

void  Cerror_string(char *v7243,listargs *v7236)
{ GC_BIND;
  princ_string("---- Compiler Error[in ");
  print_any(GC_OID(Optimize.OPT->in_method));
  princ_string("]:\n");
  princ_string("---- file read up to line ");
  princ_integer(Reader.reader->nb_line);
  princ_string("\n");
  close_exception(((general_error *) (*Core._general_error)(_string_(v7243),
    _oid_(v7236))));
  GC_UNBIND;} 

void  notice_void()
{ if (Optimize.OPT->in_method != CNULL)
   ;} 

OID  c_warn_Call(Call *v1140,OID v9399)
{ GC_BIND;
  { OID Result = 0;
    { property * v7243 = v1140->selector;
      if (v9399 == _oid_(Kernel._void))
       (*Optimize.Cerror)(_string_("[205] message ~S sent to void object"),
        _oid_(v1140));
      else if ((boolean_I_any(_oid_(v7243->restrictions)) != CTRUE) && 
          (contain_ask_set(Optimize.OPT->ignore,_oid_(v7243)) != CTRUE))
       { warn_void();
        tformat_string("the property ~S is undefined [255]\n",2,list::alloc(1,_oid_(v7243)));
        } 
      else if ((contain_ask_set(Optimize.OPT->ignore,_oid_(v7243)) != CTRUE) && 
          (((v7243->open <= 1) || 
              (v7243->open == 4)) && 
            ((INHERIT(OWNER(v9399),Kernel._list)) && (class_I_type(OBJECT(ClaireType,(*(OBJECT(bag,v9399)))[1]))->open != 3))))
       { warn_void();
        tformat_string("wrongly typed message ~S (~S) [256]\n",2,list::alloc(2,_oid_(v1140),v9399));
        } 
      else if (Optimize.compiler->optimize_ask == CTRUE)
       { notice_void();
        ;} 
      Result = _oid_(open_message_property(v1140->selector,GC_OBJECT(list,v1140->args)));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_warn_Super(Super *v1140,OID v9399)
{ GC_BIND;
  { OID Result = 0;
    { property * v7243 = v1140->selector;
      if (v9399 == _oid_(Kernel._void))
       (*Optimize.Cerror)(_string_("[205] message ~S sent to void object"),
        _oid_(v1140));
      else if (boolean_I_any(_oid_(v7243->restrictions)) != CTRUE)
       { warn_void();
        tformat_string("the property ~S is undefined [255]\n",2,list::alloc(1,_oid_(v7243)));
        } 
      else if ((contain_ask_set(Optimize.OPT->ignore,_oid_(v7243)) != CTRUE) && 
          (v7243->open <= 1))
       ;{ Call * v7237 = GC_OBJECT(Call,open_message_property(v1140->selector,GC_OBJECT(list,v1140->args)));
        Super * v2072 = ((Super *) GC_OBJECT(Super,new_object_class(Language._Super)));
        (v2072->selector = v7237->selector);
        (v2072->cast_to = v1140->cast_to);
        (v2072->args = v7237->args);
        add_I_property(Kernel.instances,Language._Super,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_warn_property(property *v1140,list *v7236,list *v9399)
{ if ((v1140->open <= 1) && 
      ((contain_ask_set(Optimize.OPT->ignore,_oid_(v1140)) != CTRUE) && 
        (Optimize.compiler->safety > 1)))
   ;return (_oid_(open_message_property(v1140,v7236)));} 

OID  c_warn_Variable(Variable *v1140,OID v7248,ClaireType *v7249)
{ GC_BIND;
  if (boolean_I_any((*Kernel._exp)(_oid_(v7249),
    GC_OID(_oid_(v1140->range)))) != CTRUE)
   { if (Optimize.compiler->safety > 4)
     { warn_void();
      tformat_string("~S of type ~S is put in the variable ~S:~S [257]\n",2,list::alloc(4,v7248,
        _oid_(v7249),
        _oid_(v1140),
        GC_OID(_oid_(v1140->range))));
      } 
    else (*Optimize.Cerror)(_string_("[212] the value ~S of type ~S cannot be placed in the variable ~S:~S"),
        v7248,
        _oid_(v7249),
        _oid_(v1140),
        GC_OID(_oid_(v1140->range)));
      } 
  else if ((Optimize.compiler->safety <= 1) || 
      (boolean_I_any(sort_equal_class(osort_any(_oid_(v1140->range)),osort_any(_oid_(v7249)))) != CTRUE))
   { warn_void();
    tformat_string("~S of type ~S is put in the variable ~S:~S [257]\n",2,list::alloc(4,v7248,
      _oid_(v7249),
      _oid_(v1140),
      GC_OID(_oid_(v1140->range))));
    } 
  { OID Result = 0;
    if ((Optimize.compiler->safety <= 1) && 
        (_inf_equal_type(v7249,GC_OBJECT(ClaireType,v1140->range)) != CTRUE))
     Result = c_check_any(GC_OID((*Optimize.c_code)(v7248,
      _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v1140->range)),
      _oid_(Kernel._type))));
    else Result = v7248;
      GC_UNBIND; return (Result);} 
  } 

OID  sort_equal_class(ClaireClass *v7227,ClaireClass *v11095)
{ { OID Result = 0;
    if (INHERIT(v7227,Kernel._object))
     Result = _oid_(inherit_ask_class(v11095,Kernel._object));
    else Result = _oid_(((v7227 == v11095) ? CTRUE : ((((Optimize.compiler->overflow_ask != CTRUE) && 
            ((v7227 == Kernel._any) && 
                (v11095 == Kernel._integer))) || 
          ((v7227 == Kernel._integer) && 
              (v11095 == Kernel._any))) ? CTRUE : CFALSE)));
      return (Result);} 
  } 

ClaireClass * psort_any(OID v7248)
{ { ClaireClass *Result ;
    { ClaireClass * v7227 = class_I_type(OBJECT(ClaireType,v7248));
      Result = ((INHERIT(v7227,Kernel._object)) ?
        v7227 :
        ((v7227 == Kernel._float) ?
          v7227 :
          sort_I_class(v7227) ) );
      } 
    return (Result);} 
  } 

ClaireClass * osort_any(OID v7248)
{ { ClaireClass *Result ;
    { ClaireClass * v7227 = class_I_type(OBJECT(ClaireType,v7248));
      Result = ((v7227 == Kernel._float) ?
        v7227 :
        sort_I_class(v7227) );
      } 
    return (Result);} 
  } 

ClaireClass * sort_Variable(Variable *v7248)
{ { ClaireClass *Result ;
    { ClaireType * v7242 = v7248->range;
      Result = (((INHERIT(v7242->isa,Core._Union)) && (equal(_oid_(CLREAD(Union,v7242,t1)),_oid_(Kernel.emptySet)) == CTRUE)) ?
        psort_any(_oid_(CLREAD(Union,CLREAD(Union,v7242,t2),t2))) :
        psort_any(_oid_(v7242)) );
      } 
    return (Result);} 
  } 

ClaireClass * stupid_t_any1(OID v1140)
{ GC_BIND;
  { ClaireClass *Result ;
    if (INHERIT(OWNER(v1140),Language._Variable))
     { ClaireType * v7242 = GC_OBJECT(ClaireType,OBJECT(Variable,v1140)->range);
      Result = ((sort_abstract_ask_type(v7242) == CTRUE) ?
        Kernel._any :
        (((INHERIT(v7242->isa,Core._Union)) && (equal(_oid_(CLREAD(Union,v7242,t1)),_oid_(Kernel.emptySet)) == CTRUE)) ?
          OBJECT(ClaireClass,(*Core.t1)(GC_OID(_oid_(CLREAD(Union,v7242,t2))))) :
          class_I_type(v7242) ) );
      } 
    else if (INHERIT(OWNER(v1140),Core._global_variable))
     { ClaireType * v7242 = OBJECT(global_variable,v1140)->range;
      Result = ((boolean_I_any(_oid_(v7242)) == CTRUE) ?
        class_I_type(v7242) :
        OWNER(OBJECT(global_variable,v1140)->value) );
      } 
    else if (INHERIT(OWNER(v1140),Language._And))
     Result = Kernel._boolean;
    else if (INHERIT(OWNER(v1140),Kernel._bag))
     Result = OWNER(v1140);
    else if (INHERIT(OWNER(v1140),Kernel._environment))
     Result = Kernel._environment;
    else if (INHERIT(OWNER(v1140),Kernel._class))
     Result = Kernel._class;
    else if (INHERIT(OWNER(v1140),Language._Call_slot))
     { slot * v7243 = OBJECT(Call_slot,v1140)->selector;
      property * v7240 = v7243->selector;
      { ITERATE(v11591);
        for (START(v7240->definition); NEXT(v11591);)
        if (Kernel._slot == OBJECT(ClaireObject,v11591)->isa)
         { if (_inf_equal_type(domain_I_restriction(v7243),domain_I_restriction(OBJECT(restriction,v11591))) == CTRUE)
           v7243= OBJECT(slot,v11591);
          } 
        } 
      Result = class_I_type(v7243->range);
      } 
    else if (INHERIT(OWNER(v1140),Language._Call_method))
     Result = class_I_type(OBJECT(Call_method,v1140)->arg->range);
    else if (INHERIT(OWNER(v1140),Language._Call))
     Result = selector_psort_Call(OBJECT(Call,v1140));
    else if (INHERIT(OWNER(v1140),Optimize._to_C))
     Result = OBJECT(Compile_to_C,v1140)->set_arg;
    else if (INHERIT(OWNER(v1140),Optimize._to_protect))
     Result = stupid_t_any1(GC_OID(OBJECT(Compile_to_protect,v1140)->arg));
    else if (INHERIT(OWNER(v1140),Kernel._symbol))
     Result = OWNER(v1140);
    else if (INHERIT(OWNER(v1140),Kernel._char))
     Result = OWNER(v1140);
    else if (Kernel._boolean == OWNER(v1140))
     Result = OWNER(v1140);
    else if (INHERIT(OWNER(v1140),Kernel._primitive))
     Result = OWNER(v1140);
    else if (INHERIT(OWNER(v1140),Language._Assign))
     Result = stupid_t_any1(GC_OID(OBJECT(Assign,v1140)->arg));
    else if (INHERIT(OWNER(v1140),Language._Let))
     Result = stupid_t_any1(GC_OID(OBJECT(Let,v1140)->arg));
    else if (INHERIT(OWNER(v1140),Language._Do))
     Result = stupid_t_any1(GC_OID(last_list(OBJECT(Do,v1140)->args)));
    else if (INHERIT(OWNER(v1140),Language._If))
     Result = meet_class(stupid_t_any1(GC_OID(OBJECT(If,v1140)->arg)),stupid_t_any1(GC_OID(OBJECT(If,v1140)->other)));
    else if (INHERIT(OWNER(v1140),Language._Collect))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v1140),Language._Image))
     Result = Kernel._set;
    else if (INHERIT(OWNER(v1140),Language._Or))
     Result = Kernel._boolean;
    else if (INHERIT(OWNER(v1140),Language._Select))
     Result = Kernel._set;
    else if (INHERIT(OWNER(v1140),Language._Lselect))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v1140),Language._List))
     Result = Kernel._list;
    else if (INHERIT(OWNER(v1140),Language._Set))
     Result = Kernel._set;
    else Result = ((INHERIT(OWNER(v1140),Kernel._thing)) ?
      OWNER(v1140) :
      ((INHERIT(OWNER(v1140),Language._Tuple)) ?
        Kernel._tuple :
        ((INHERIT(OWNER(v1140),Language._Exists)) ?
          ((OBJECT(Exists,v1140)->other == CNULL) ?
            Kernel._any :
            Kernel._boolean ) :
          ((INHERIT(OWNER(v1140),Kernel._integer)) ?
            Kernel._integer :
            Kernel._any ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * stupid_t_any2(OID v1140,OID v7248)
{ { ClaireBoolean *Result ;
    { ClaireClass * v11096 = stupid_t_any1(v1140);
      ClaireClass * v11095 = stupid_t_any1(v7248);
      Result = ((v11096 != Kernel._any) ? ((v11096 == v11095) ? CTRUE: CFALSE): CFALSE);
      } 
    return (Result);} 
  } 

ClaireBoolean * extended_ask_type(ClaireType *v1140)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(v1140->isa,Core._Union)) ?
      ((Kernel._set == CLREAD(Union,v1140,t2)->isa) ? ((boolean_I_any(_oid_(CLREAD(Union,v1140,t2))) == CTRUE) ? (((*(((bag *) CLREAD(Union,v1140,t2))))[1] == CNULL) ? CTRUE: CFALSE): CFALSE): CFALSE) :
      CFALSE );
    return (Result);} 
  } 

ClaireType * extends_type(ClaireType *v7248)
{ GC_BIND;
  { ClaireType *Result ;
    { Optimize_optUnion * v2072 = ((Optimize_optUnion *) GC_OBJECT(Optimize_optUnion,new_object_class(Optimize._optUnion)));
      (v2072->t1 = v7248);
      (v2072->t2 = set::alloc(Kernel.emptySet,1,CNULL));
      Result = v2072;
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireType * sort_abstract_I_type(ClaireType *v7248)
{ GC_BIND;
  { ClaireType *Result ;
    if (((_oid_((INHERIT(v7248->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v7248))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v7248))))) != _oid_(Kernel._any)) && 
          ((_oid_((INHERIT(v7248->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v7248))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v7248))))) != _oid_(Kernel._integer)) || 
              (Optimize.compiler->overflow_ask == CTRUE))) || 
        (v7248 == Kernel._float))
     { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
      (v2072->t1 = Kernel._any);
      (v2072->t2 = v7248);
      Result = v2072;
      } 
    else Result = v7248;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * sort_abstract_ask_type(ClaireType *v7248)
{ { ClaireBoolean *Result ;
    Result = ((INHERIT(v7248->isa,Core._Union)) ?
      equal(_oid_(CLREAD(Union,v7248,t1)),_oid_(Kernel._any)) :
      CFALSE );
    return (Result);} 
  } 

ClaireType * ptype_type(ClaireType *v7248)
{ { ClaireType *Result ;
    Result = ((INHERIT(v7248->isa,Core._Union)) ?
      ((CLREAD(Union,v7248,t1) == Kernel._any) ?
        CLREAD(Union,v7248,t2) :
        v7248 ) :
      v7248 );
    return (Result);} 
  } 

ClaireType * pmember_type(ClaireType *v7248)
{ GC_BIND;
  { ClaireType *Result ;
    Result = member_type(GC_OBJECT(ClaireType,ptype_type(v7248)));
    GC_UNBIND; return (Result);} 
  } 

OID  enumerate_code_any(OID v1140,ClaireType *v9239)
{ GC_BIND;
  { OID Result = 0;
    if (_inf_equal_type(GC_OBJECT(ClaireType,ptype_type(v9239)),Kernel._bag) == CTRUE)
     Result = c_strict_code_any(v1140,Kernel._bag);
    else { if (Optimize.compiler->optimize_ask == CTRUE)
         { notice_void();
          ;} 
        Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property1(Core.enumerate,Kernel._any))),list::alloc(1,v1140),list::alloc(1,_oid_(v9239)));
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  range_infers_for_Variable(Variable *v1140,ClaireType *v7249,ClaireType *v11687)
{ GC_BIND;
  if (v1140->range == (NULL))
   { if (INHERIT(v7249->isa,Core._Interval))
     v7249= Kernel._integer;
    (v1140->range = v7249);
    } 
  else if ((_inf_equal_type(v7249,GC_OBJECT(ClaireType,v1140->range)) != CTRUE) && 
      (Optimize.compiler->safety <= 1))
   { if (((boolean_I_any(_oid_(v7249)) == CTRUE) ? ((boolean_I_any(_oid_(v1140->range)) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)
     { warn_void();
      tformat_string("range of variable in ~S is wrong [258]\n",2,list::alloc(1,_oid_(v1140)));
      } 
    } 
  { OID Result = 0;
    if ((sort_Variable(v1140) != Kernel._any) && 
        (((sort_Variable(v1140) != Kernel._integer) || 
            (Optimize.compiler->overflow_ask == CTRUE)) && 
          (((_inf_equal_type(v11687,Kernel._array) == CTRUE) ? ((_inf_equal_type(v7249,Kernel._float) == CTRUE) ? CTRUE: CFALSE): CFALSE) != CTRUE)))
     { Result = _void_((v1140->range = sort_abstract_I_type(GC_OBJECT(ClaireType,v1140->range))));
      } 
    else Result = Kernel.cfalse;
      GC_UNBIND; return (Result);} 
  } 

OID  range_infers_Variable(Variable *v1140,ClaireType *v7249)
{ gc_register_Variable(v1140);
  { OID Result = 0;
    if ((v1140->range == (NULL)) || 
        ((extended_ask_type(v1140->range) == CTRUE) && 
            (INHERIT(v1140->range->isa,Optimize._optUnion))))
     { if (Kernel._set == v7249->isa)
       Result = _void_((v1140->range = class_I_type(v7249)));
      else Result = _void_((v1140->range = v7249));
        } 
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

void  range_infer_case_any(OID v1140,ClaireType *v7249)
{ GC_BIND;
  if (INHERIT(OWNER(v1140),Language._Variable))
   { if (boolean_I_any(sort_equal_class(osort_any(_oid_(OBJECT(Variable,v1140)->range)),osort_any(_oid_(v7249)))) == CTRUE)
     { ClaireClass * v11096 = psort_any(_oid_(class_I_type(OBJECT(Variable,v1140)->range)));
      if (v11096 != psort_any(_oid_(class_I_type(v7249))))
       { Variable * v6691 = OBJECT(Variable,v1140); 
        ClaireType * v6693;
        { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v2072->t1 = Kernel.emptySet);
          { Union * v6694 = v2072; 
            ClaireType * v6715;
            { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
              (v2072->t1 = v11096);
              (v2072->t2 = v7249);
              v6715 = v2072;
              } 
            (v6694->t2 = v6715);} 
          v6693 = v2072;
          } 
        (v6691->range = v6693);} 
      else (OBJECT(Variable,v1140)->range = v7249);
        } 
    else if (osort_any(_oid_(OBJECT(Variable,v1140)->range)) == Kernel._any)
     (OBJECT(Variable,v1140)->range = sort_abstract_I_type(v7249));
    } 
  GC_UNBIND;} 

OID  c_check_any(OID v7248,OID v7249)
{ GC_BIND;
  { OID Result = 0;
    { method * v7237 = ((method *) _at_property1(Core.check_in,Kernel._any));
      if (Optimize.compiler->safety > 3)
       Result = v7248;
      else { legal_ask_module(v7237->module_I,_oid_(v7237));
          { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
            (v2072->arg = v7237);
            (v2072->args = list::alloc(2,GC_OID(c_gc_I_any1(v7248)),GC_OID(c_gc_I_any1(v7249))));
            add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
            Result = _oid_(v2072);
            } 
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

void  range_sets_any(OID v1140,ClaireType *v7249)
{ GC_BIND;
  if (INHERIT(OWNER(v1140),Language._Variable))
   { if (boolean_I_any(sort_equal_class(osort_any(_oid_(OBJECT(Variable,v1140)->range)),osort_any(_oid_(v7249)))) == CTRUE)
     { ClaireClass * v11096 = psort_any(_oid_(class_I_type(OBJECT(Variable,v1140)->range)));
      if (v11096 != psort_any(_oid_(class_I_type(v7249))))
       { Variable * v6716 = OBJECT(Variable,v1140); 
        ClaireType * v6717;
        { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
          (v2072->t1 = Kernel.emptySet);
          { Union * v6719 = v2072; 
            ClaireType * v6720;
            { Union * v2072 = ((Union *) GC_OBJECT(Union,new_object_class(Core._Union)));
              (v2072->t1 = v11096);
              (v2072->t2 = v7249);
              v6720 = v2072;
              } 
            (v6719->t2 = v6720);} 
          v6717 = v2072;
          } 
        (v6716->range = v6717);} 
      else (OBJECT(Variable,v1140)->range = v7249);
        } 
    else if (osort_any(_oid_(OBJECT(Variable,v1140)->range)) == Kernel._any)
     (OBJECT(Variable,v1140)->range = sort_abstract_I_type(v7249));
    } 
  GC_UNBIND;} 

ClaireClass * c_srange_method(method *v7237)
{ { ClaireClass *Result ;
    Result = ((v7237->range == Kernel._float) ?
      Kernel._float :
      OBJECT(ClaireClass,last_list(v7237->srange)) );
    return (Result);} 
  } 

ClaireBoolean * nativeVar_ask_global_variable(global_variable *v7248)
{ return (((Optimize.compiler->optimize_ask == CTRUE) ? ((v7248->store_ask == CFALSE) ? ((v7248->name->module_I == v7248->name->definition) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(v7248->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v7248->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v7248->range))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE): CFALSE): CFALSE));} 

ClaireType * return_type_any(OID v1140)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireType *Result ;
    if (INHERIT(OWNER(v1140),Optimize._to_C))
     Result = return_type_any(GC_OID(OBJECT(Compile_to_C,v1140)->arg));
    else if (INHERIT(OWNER(v1140),Optimize._to_protect))
     Result = return_type_any(GC_OID(OBJECT(Compile_to_protect,v1140)->arg));
    else if (INHERIT(OWNER(v1140),Language._Let))
     Result = return_type_any(GC_OID(OBJECT(Let,v1140)->arg));
    else if (INHERIT(OWNER(v1140),Language._Do))
     { set * v7248 = Kernel.emptySet;
      { OID gc_local;
        ITERATE(v7249);
        bag *v7249_support;
        v7249_support = GC_OBJECT(list,OBJECT(Do,v1140)->args);
        for (START(v7249_support); NEXT(v7249);)
        { GC_LOOP;
          GC__ANY(v7248 = OBJECT(set,(*Kernel._exp)(_oid_(v7248),
            GC_OID(_oid_(return_type_any(v7249))))), 1);
          GC_UNLOOP;} 
        } 
      Result = v7248;
      } 
    else if (INHERIT(OWNER(v1140),Language._If))
     Result = OBJECT(ClaireType,(*Kernel._exp)(GC_OID(_oid_(return_type_any(GC_OID(OBJECT(If,v1140)->arg)))),
      GC_OID(_oid_(return_type_any(GC_OID(OBJECT(If,v1140)->other))))));
    else if (INHERIT(OWNER(v1140),Language._Return))
     Result = OBJECT(ClaireType,(*Optimize.c_type)(GC_OID(OBJECT(Return,v1140)->arg)));
    else if (INHERIT(OWNER(v1140),Language._Case))
     { set * v7248 = Kernel.emptySet;
      { OID gc_local;
        ITERATE(v7249);
        bag *v7249_support;
        v7249_support = GC_OBJECT(list,OBJECT(Case,v1140)->args);
        for (START(v7249_support); NEXT(v7249);)
        { GC_LOOP;
          GC__ANY(v7248 = OBJECT(set,(*Kernel._exp)(_oid_(v7248),
            GC_OID(_oid_(return_type_any(v7249))))), 1);
          GC_UNLOOP;} 
        } 
      Result = v7248;
      } 
    else if (INHERIT(OWNER(v1140),Language._Handle))
     Result = return_type_any(GC_OID(OBJECT(ClaireHandle,v1140)->arg));
    else Result = Kernel.emptySet;
      GC_UNBIND; return (Result);} 
  } 

OID  c_code_Type_Optimize(Type *v1140,ClaireClass *v7243)
{ GC_BIND;
  { OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID((*Optimize.self_code)(_oid_(v1140))),
      _oid_(v7243));
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_subtype(subtype *v1140)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.nth);
      (v2072->args = list::alloc(2,_oid_(v1140->arg),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v1140->t1)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Param(Param *v1140)
{ GC_BIND;
  { OID Result = 0;
    if ((v1140->params->length == 1) && 
        (((*(v1140->params))[1] == _oid_(Kernel.of)) && 
          (Kernel._set == OWNER((*(v1140->args))[1]))))
     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Core.param_I);
      (v2072->args = list::alloc(2,_oid_(v1140->arg),GC_OID((*Optimize.c_code)(GC_OID((*Kernel.nth)(GC_OID((*(v1140->args))[1]),
          1)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
        (v2072->selector = Kernel.nth);
        { Call * v6721 = v2072; 
          list * v6722;
          { OID v_bag;
            GC_ANY(v6722= list::empty(Kernel.emptySet));
            ((list *) v6722)->addFast(_oid_(v1140->arg));
            ((list *) v6722)->addFast(GC_OID(_oid_(v1140->params)));
            { { list * v8349;{ bag *v_list; OID v_val;
                  OID v7249,CLcount;
                  v_list = GC_OBJECT(list,v1140->args);
                   v8349 = v_list->clone();
                  for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                  { v7249 = (*(v_list))[CLcount];
                    v_val = (*Optimize.c_code)(v7249,
                      _oid_(Kernel._type));
                    
                    (*((list *) v8349))[CLcount] = v_val;} 
                  } 
                
                v_bag=_oid_(v8349);} 
              GC_OID(v_bag);} 
            ((list *) v6722)->addFast(v_bag);} 
          (v6721->args = v6722);} 
        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  self_code_Union(Union *v1140)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Core.U);
      (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)(GC_OID(_oid_(v1140->t1)),
        _oid_(Kernel._type))),GC_OID((*Optimize.c_code)(GC_OID(_oid_(v1140->t2)),
        _oid_(Kernel._type)))));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Interval(Interval *v1140)
{ GC_BIND;
  { OID Result = 0;
    { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel._dot_dot);
      (v2072->args = list::alloc(2,v1140->arg1,v1140->arg2));
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Reference(Reference *v1140)
{ GC_BIND;
  { OID Result = 0;
    { Definition * v2072 = ((Definition *) GC_OBJECT(Definition,new_object_class(Language._Definition)));
      (v2072->arg = Core._Reference);
      { Definition * v6723 = v2072; 
        list * v6724;
        { OID v_bag;
          GC_ANY(v6724= list::empty(Kernel.emptySet));
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._equal);
              (v2072->args = list::alloc(2,_oid_(Core.args),GC_OID(_oid_(v1140->args))));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v_bag = _oid_(v2072);
              } 
            GC_OID(v_bag);} 
          ((list *) v6724)->addFast(v_bag);
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._equal);
              (v2072->args = list::alloc(2,_oid_(Kernel.index),v1140->index));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v_bag = _oid_(v2072);
              } 
            GC_OID(v_bag);} 
          ((list *) v6724)->addFast(v_bag);
          { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Kernel._equal);
              (v2072->args = list::alloc(2,_oid_(Kernel.arg),_oid_(v1140->arg)));
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v_bag = _oid_(v2072);
              } 
            GC_OID(v_bag);} 
          ((list *) v6724)->addFast(v_bag);} 
        (v6723->args = v6724);} 
      add_I_property(Kernel.instances,Language._Definition,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  self_code_Pattern(Optimize_ClairePattern *v1140)
{ GC_BIND;
  { OID Result = 0;
    if (Optimize.compiler->inline_ask == CTRUE)
     { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
      (v2072->selector = Kernel.nth);
      { Call * v6746 = v2072; 
        list * v6747;
        { OID v_bag;
          GC_ANY(v6747= list::empty(Kernel.emptySet));
          ((list *) v6747)->addFast(_oid_(v1140->selector));
          { { Tuple * v2072 = ((Tuple *) GC_OBJECT(Tuple,new_object_class(Language._Tuple)));
              (v2072->args = v1140->arg);
              add_I_property(Kernel.instances,Language._Tuple,11,_oid_(v2072));
              v_bag = _oid_(v2072);
              } 
            GC_OID(v_bag);} 
          ((list *) v6747)->addFast(v_bag);} 
        (v6746->args = v6747);} 
      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    else Result = _oid_(Language._Call);
      GC_UNBIND; return (Result);} 
  } 

OID  member_code_class2(ClaireClass *v1140,OID v7248)
{ GC_BIND;
  { OID Result = 0;
    { Call * v8121;
      { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7248))),Kernel._object) == CTRUE) ?
            Kernel.isa :
            Core.owner ));
          (v2072->args = list::alloc(1,v7248));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v8121 = v2072;
          } 
        GC_OBJECT(Call,v8121);} 
      if (((v1140->open <= -1) || 
            (v1140->open == 1)) && 
          (boolean_I_any(_oid_(v1140->subclass)) != CTRUE))
       { OID  v15868;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Kernel._equal);
          (v2072->args = list::alloc(2,_oid_(v1140),_oid_(v8121)));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v15868 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v15868);
        } 
      else { OID  v445;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Core.inherit_ask);
            (v2072->args = list::alloc(2,_oid_(v8121),_oid_(v1140)));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v445 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v445);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Type(Type *v1140,OID v7248)
{ GC_BIND;
  { OID Result = 0;
    { Call_method2 * v2072 = ((Call_method2 *) GC_OBJECT(Call_method2,new_object_class(Language._Call_method2)));
      update_property(Kernel.arg,
        v2072,
        2,
        Kernel._object,
        GC_OID(_oid_(_at_property2(Kernel._Z,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any))))));
      (v2072->args = list::alloc(2,GC_OID((*Optimize.c_code)(v7248,
        _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v1140),
        _oid_(Kernel._any)))));
      add_I_property(Kernel.instances,Language._Call_method2,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Union(Union *v1140,OID v7248)
{ GC_BIND;
  { OID Result = 0;
    { Or * v2072 = ((Or *) GC_OBJECT(Or,new_object_class(Language._Or)));
      (v2072->args = list::alloc(2,GC_OID((*Optimize.member_code)(GC_OID(_oid_(v1140->t1)),
        v7248)),GC_OID((*Optimize.member_code)(GC_OID(_oid_(v1140->t2)),
        v7248))));
      add_I_property(Kernel.instances,Language._Or,11,_oid_(v2072));
      Result = _oid_(v2072);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Interval(Interval *v1140,OID v7248)
{ GC_BIND;
  { OID Result = 0;
    { OID  v1406;
      { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
        { And * v6751 = v2072; 
          list * v6752;
          { OID v_bag;
            GC_ANY(v6752= list::empty(Kernel.emptySet));
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel._sup_equal);
                (v2072->args = list::alloc(2,v7248,v1140->arg1));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              GC_OID(v_bag);} 
            ((list *) v6752)->addFast(v_bag);
            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                (v2072->selector = Kernel._inf_equal);
                (v2072->args = list::alloc(2,v7248,v1140->arg2));
                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                v_bag = _oid_(v2072);
                } 
              GC_OID(v_bag);} 
            ((list *) v6752)->addFast(v_bag);} 
          (v6751->args = v6752);} 
        add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
        v1406 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v1406,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_Param(Param *v1140,OID v7248)
{ GC_BIND;
  { OID Result = 0;
    { OID  v5250;
      { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
        { And * v6755 = v2072; 
          list * v6777;
          { list * v11930;
            { { OID v_bag;
                GC_ANY(v11930= list::empty(Kernel.emptySet));
                { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                    (v2072->selector = Kernel._Z);
                    (v2072->args = list::alloc(2,v7248,_oid_(v1140->arg)));
                    add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                    v_bag = _oid_(v2072);
                    } 
                  GC_OID(v_bag);} 
                ((list *) v11930)->addFast(v_bag);} 
              GC_OBJECT(list,v11930);} 
            list * v12891;
            { list * v16138 = list::empty(Kernel.emptySet);
              { int  v7233 = 1;
                int  v6753 = v1140->params->length;
                { OID gc_local;
                  while ((v7233 <= v6753))
                  { GC_LOOP;
                    { OID  v13852;
                      { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                        (v2072->selector = Kernel._Z);
                        { Call * v6781 = v2072; 
                          list * v6782;
                          { OID v_bag;
                            GC_ANY(v6782= list::empty(Kernel.emptySet));
                            { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                                update_property(Kernel.selector,
                                  v2072,
                                  2,
                                  Kernel._object,
                                  GC_OID((*(v1140->params))[v7233]));
                                (v2072->args = list::alloc(1,v7248));
                                add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                                v_bag = _oid_(v2072);
                                } 
                              GC_OID(v_bag);} 
                            ((list *) v6782)->addFast(v_bag);
                            ((list *) v6782)->addFast(GC_OID((*(v1140->args))[v7233]));} 
                          (v6781->args = v6782);} 
                        add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                        v13852 = _oid_(v2072);
                        } 
                      v16138->addFast(v13852);
                      } 
                    ++v7233;
                    GC_UNLOOP;} 
                  } 
                } 
              v12891 = GC_OBJECT(list,v16138);
              } 
            v6777 = append_list(v11930,v12891);
            } 
          (v6755->args = v6777);} 
        add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
        v5250 = _oid_(v2072);
        } 
      Result = (*Optimize.c_code)(v5250,
        _oid_(Kernel._any));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  member_code_tuple(tuple *v1140,OID v7248)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v7248),Language._Tuple))
     { if (length_bag(OBJECT(bag,(*Core.args)(v7248))) != v1140->length)
       Result = Kernel.cfalse;
      else { OID  v1312;
          { And * v2072 = ((And *) GC_OBJECT(And,new_object_class(Language._And)));
            { And * v6785 = v2072; 
              list * v6786;
              { list * v16138 = list::empty(Kernel.emptySet);
                { int  v7233 = 1;
                  int  v6783 = v1140->length;
                  { OID gc_local;
                    while ((v7233 <= v6783))
                    { GC_LOOP;
                      { OID  v7992;
                        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                          (v2072->selector = Kernel._Z);
                          (v2072->args = list::alloc(2,GC_OID((*(OBJECT(bag,(*Core.args)(v7248))))[v7233]),(*(v1140))[v7233]));
                          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                          v7992 = _oid_(v2072);
                          } 
                        v16138->addFast(v7992);
                        } 
                      ++v7233;
                      GC_UNLOOP;} 
                    } 
                  } 
                v6786 = GC_OBJECT(list,v16138);
                } 
              (v6785->args = v6786);} 
            add_I_property(Kernel.instances,Language._And,11,_oid_(v2072));
            v1312 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v1312,
            _oid_(Kernel._any));
          } 
        } 
    else Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any)))))),GC_OBJECT(list,list::alloc(2,v7248,_oid_(v1140))),GC_OBJECT(list,list::alloc(2,_oid_(Kernel._any),_oid_(Kernel._any))));
      GC_UNBIND; return (Result);} 
  } 

OID  member_code_any(OID v1140,OID v7248)
{ GC_BIND;
  (Language.LDEF->value= Core.nil->value);
  { OID Result = 0;
    { list * v9399 = list::alloc(2,GC_OID((*Optimize.c_type)(v7248)),GC_OID((*Optimize.c_type)(v1140)));
      OID  v7242 = GC_OID(extract_pattern_any(v1140,Kernel.nil));
      { ClaireBoolean * g0071I;
        { ClaireBoolean *v_or;
          { v_or = ((v7242 == CNULL) ? CTRUE : CFALSE);
            if (v_or == CTRUE) g0071I =CTRUE; 
            else { v_or = ((v1140 == _oid_(Kernel._object)) ? CTRUE : CFALSE);
              if (v_or == CTRUE) g0071I =CTRUE; 
              else { { OID  v9914;
                  if (INHERIT(OWNER(v1140),Core._global_variable))
                   v9914 = _oid_(OBJECT(global_variable,v1140)->range);
                  else v9914 = Kernel.cfalse;
                    v_or = boolean_I_any(v9914);
                  } 
                if (v_or == CTRUE) g0071I =CTRUE; 
                else g0071I = CFALSE;} 
              } 
            } 
          } 
        
        if (g0071I == CTRUE) Result = c_code_method_method1(GC_OBJECT(method,((method *) _at_property2(Kernel._Z,v9399))),list::alloc(2,v7248,v1140),v9399);
          else Result = (*Optimize.member_code)(v7242,
          v7248);
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _Z_any4(OID v7248,OID v7249)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(v7248,
      GC_OID(OPT_EVAL((*(OBJECT(Call,v7249)->args))[2]))))) == CTRUE) ? (((OBJECT(ClaireBoolean,(*Kernel._inf_equal)(GC_OID(OPT_EVAL((*(OBJECT(Call,v7249)->args))[1])),
      v7248))) == CTRUE) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * _Z_any5(OID v7248,OID v7249)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((belong_to(v7248,OPT_EVAL((*(OBJECT(Call,v7249)->args))[1])) == CTRUE) ? ((equal(v7248,OPT_EVAL((*(OBJECT(Call,v7249)->args))[2])) != CTRUE) ? CTRUE: CFALSE): CFALSE);
    GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * gcsafe_ask_class(ClaireClass *v1140)
{ return (((v1140 == Kernel._void) ? CTRUE : 
  ((INHERIT(v1140,Kernel._thing)) ? CTRUE : 
  ((INHERIT(v1140,Kernel._class)) ? CTRUE : 
  (((v1140 != Kernel._object) && 
      ((INHERIT(v1140,Kernel._object)) && 
        ((v1140->open < 3) && 
          ((inherit_ask_class(v1140,Kernel._collection) != CTRUE) && 
            (v1140 != Core._lambda))))) ? CTRUE : 
  ((v1140 == Kernel._integer) ? CTRUE : 
  ((v1140 == Kernel._char) ? CTRUE : 
  ((INHERIT(v1140,Kernel._boolean)) ? CTRUE : 
  ((v1140 == Kernel._function) ? CTRUE : 
  CFALSE)))))))));} 

ClaireBoolean * gcsafe_ask_type(ClaireType *v1140)
{ { ClaireBoolean *Result ;
    Result = ((equal(_oid_(v1140),_oid_(Kernel.emptySet)) == CTRUE) ?
      CTRUE :
      ((INHERIT(v1140->isa,Core._Union)) ?
        (((OBJECT(ClaireBoolean,_oid_((INHERIT(CLREAD(Union,v1140,t1)->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(CLREAD(Union,v1140,t1)))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(CLREAD(Union,v1140,t1)))))))) == CTRUE) ? (((OBJECT(ClaireBoolean,_oid_((INHERIT(CLREAD(Union,v1140,t2)->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(CLREAD(Union,v1140,t2)))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(CLREAD(Union,v1140,t2)))))))) == CTRUE) ? CTRUE: CFALSE): CFALSE) :
        gcsafe_ask_class(class_I_type(v1140)) ) );
    return (Result);} 
  } 

ClaireBoolean * gcsafe_ask_property(property *v1140)
{ { ClaireBoolean *Result ;
    { OID  v10875;
      { ITERATE(v7248);
        v10875= Kernel.cfalse;
        for (START(v1140->restrictions); NEXT(v7248);)
        if (_oid_((INHERIT(v1140->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v1140->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v1140->range))))) != Kernel.ctrue)
         { v10875 = Kernel.ctrue;
          break;} 
        } 
      Result = not_any(v10875);
      } 
    return (Result);} 
  } 

OID  c_gc_I_any1(OID v1140)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140))) == CTRUE))
     { (Optimize.OPT->protection = CTRUE);
      { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
        (v2072->arg = v1140);
        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    else Result = v1140;
      GC_UNBIND; return (Result);} 
  } 

OID  c_gc_I_any2(OID v1140,ClaireType *v7244)
{ GC_BIND;
  { OID Result = 0;
    if ((Optimize.OPT->online_ask != CTRUE) && 
        ((((OBJECT(ClaireBoolean,(*Optimize.c_gc_ask)(v1140))) == CTRUE) || 
            ((INHERIT(OWNER(v1140),Language._Let)) && 
                ((*Optimize.gcsafe_ask)(GC_OID((*Optimize.c_type)(v1140))) != Kernel.ctrue))) && 
          (_oid_((INHERIT(v7244->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v7244))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(v7244))))) != Kernel.ctrue)))
     { (Optimize.OPT->protection = CTRUE);
      { Compile_to_protect * v2072 = ((Compile_to_protect *) GC_OBJECT(Compile_to_protect,new_object_class(Optimize._to_protect)));
        (v2072->arg = v1140);
        add_I_property(Kernel.instances,Optimize._to_protect,11,_oid_(v2072));
        Result = _oid_(v2072);
        } 
      } 
    else Result = v1140;
      GC_UNBIND; return (Result);} 
  } 

ClaireBoolean * need_protect_any(OID v7248)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v7248),Language._Call_slot)) ?
      Optimize.OPT->use_update :
      ((INHERIT(OWNER(v7248),Language._Call_method2)) ?
        ((OBJECT(Call_method,v7248)->arg->selector == Kernel.nth) ?
          ((Optimize.OPT->use_nth_equal == CTRUE) ? CTRUE : ((domain_I_restriction(OBJECT(Call_method,v7248)->arg) == Kernel._class) ? CTRUE : ((_inf_equal_type(GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)((*(OBJECT(Call_method,v7248)->args))[1]))),Kernel._tuple) == CTRUE) ? CTRUE : CFALSE))) :
          CTRUE ) :
        CTRUE ) );
    GC_UNBIND; return (Result);} 
  } 

Variable * Variable_I_symbol(symbol *v7243,int v7239,ClaireType *v7244)
{ GC_BIND;
  { Variable *Result ;
    { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
      (v2072->pname = v7243);
      (v2072->index = v7239);
      (v2072->range = v7244);
      add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
      Result = v2072;
      } 
    GC_UNBIND; return (Result);} 
  } 

list * get_indexed_class_Optimize(ClaireClass *v7227)
{ return (v7227->slots);} 

ClaireBoolean * designated_ask_any(OID v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { v_or = inherit_ask_class(OWNER(v1140),Kernel._thing);
        if (v_or == CTRUE) Result =CTRUE; 
        else { v_or = inherit_ask_class(OWNER(v1140),Language._Variable);
          if (v_or == CTRUE) Result =CTRUE; 
          else { v_or = inherit_ask_class(OWNER(v1140),Kernel._integer);
            if (v_or == CTRUE) Result =CTRUE; 
            else { v_or = ((Kernel._boolean == OWNER(v1140)) ? CTRUE : CFALSE);
              if (v_or == CTRUE) Result =CTRUE; 
              else { v_or = ((equal(v1140,Core.nil->value) == CTRUE) ? CTRUE : CFALSE);
                if (v_or == CTRUE) Result =CTRUE; 
                else { v_or = ((equal(v1140,_oid_(Kernel.emptySet)) == CTRUE) ? CTRUE : CFALSE);
                  if (v_or == CTRUE) Result =CTRUE; 
                  else { v_or = ((v1140 == CNULL) ? CTRUE : CFALSE);
                    if (v_or == CTRUE) Result =CTRUE; 
                    else { v_or = ((Kernel._float == OWNER(v1140)) ? CTRUE : CFALSE);
                      if (v_or == CTRUE) Result =CTRUE; 
                      else { if (INHERIT(OWNER(v1140),Language._Call))
                         { OID  v7248 = GC_OID((*Optimize.c_code)(v1140));
                          v_or = (((inherit_ask_class(OWNER(v7248),Language._Call) != CTRUE) && 
                              (designated_ask_any(v7248) == CTRUE)) ? CTRUE : ((OBJECT(Call,v1140)->selector == Core.get_stack) ? CTRUE : CFALSE));
                          } 
                        else if (INHERIT(OWNER(v1140),Language._Call_slot))
                         v_or = designated_ask_any(GC_OID(OBJECT(Call_slot,v1140)->arg));
                        else if (INHERIT(OWNER(v1140),Language._Call_table))
                         v_or = designated_ask_any(GC_OID(OBJECT(Call_table,v1140)->arg));
                        else if (INHERIT(OWNER(v1140),Optimize._to_protect))
                         v_or = ((need_protect_any(GC_OID(OBJECT(Compile_to_protect,v1140)->arg)) != CTRUE) ? ((designated_ask_any(GC_OID(OBJECT(Compile_to_protect,v1140)->arg)) == CTRUE) ? CTRUE: CFALSE): CFALSE);
                        else if (INHERIT(OWNER(v1140),Language._Call_method))
                         { ClaireBoolean *v_and;
                          { v_and = ((contain_ask_set(Optimize.OPT->simple_operations,_oid_(OBJECT(Call_method,v1140)->arg->selector)) == CTRUE) ? CTRUE : ((OBJECT(Call_method,v1140)->arg == _at_property1(Kernel.nth,Kernel._bag)) ? CTRUE : CFALSE));
                            if (v_and == CFALSE) v_or =CFALSE; 
                            else { { OID  v11836;
                                { OID gc_local;
                                  ITERATE(v7249);
                                  v11836= Kernel.cfalse;
                                  bag *v7249_support;
                                  v7249_support = GC_OBJECT(list,OBJECT(Call_method,v1140)->args);
                                  for (START(v7249_support); NEXT(v7249);)
                                  if (designated_ask_any(v7249) != CTRUE)
                                   { v11836 = Kernel.ctrue;
                                    break;} 
                                  } 
                                v_and = not_any(v11836);
                                } 
                              if (v_and == CFALSE) v_or =CFALSE; 
                              else v_or = CTRUE;} 
                            } 
                          } 
                        else v_or = ((INHERIT(OWNER(v1140),Optimize._to_CL)) ?
                          designated_ask_any(GC_OID(OBJECT(Compile_to_CL,v1140)->arg)) :
                          ((INHERIT(OWNER(v1140),Optimize._to_C)) ?
                            designated_ask_any(GC_OID(OBJECT(Compile_to_C,v1140)->arg)) :
                            CFALSE ) );
                        if (v_or == CTRUE) Result =CTRUE; 
                        else Result = CFALSE;} 
                      } 
                    } 
                  } 
                } 
              } 
            } 
          } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  gc_register_Variable(Variable *v1140)
{ if ((0 <= Optimize.OPT->loop_index) && 
      (v1140->index > Optimize.OPT->loop_index))
   (Optimize.OPT->loop_index = v1140->index);
  return (Kernel.ctrue);} 

OID  gc_register_Variable2(Variable *v1140,OID v10542)
{ ;{ OID Result = 0;
    if (inner2outer_ask_any(v10542) == CTRUE)
     Result = gc_register_Variable(v1140);
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

ClaireBoolean * inner2outer_ask_any(OID v7248)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v7248),Optimize._to_protect))
     Result = CTRUE;
    else if (INHERIT(OWNER(v7248),Language._Variable))
     Result = not_any(_oid_((INHERIT(OBJECT(Variable,v7248)->range->isa,Kernel._class) ? (ClaireObject *) gcsafe_ask_class((ClaireClass *) OBJECT(ClaireClass,_oid_(OBJECT(Variable,v7248)->range))) :  (ClaireObject *)  gcsafe_ask_type((ClaireType *) OBJECT(ClaireType,_oid_(OBJECT(Variable,v7248)->range))))));
    else if (INHERIT(OWNER(v7248),Language._Call_method))
     Result = (((OBJECT(Call_method,v7248)->arg->selector == Kernel.copy) && 
        (OBJECT(Call_method,v7248)->arg->range == Kernel._bag)) ? CTRUE : (((BCONTAIN(OBJECT(Call_method,v7248)->arg->status,4)) && 
        (inner2outer_ask_any((*(OBJECT(Call_method,v7248)->args))[1]) == CTRUE)) ? CTRUE : CFALSE));
    else if (INHERIT(OWNER(v7248),Optimize._to_CL))
     Result = inner2outer_ask_any(OBJECT(Compile_to_CL,v7248)->arg);
    else Result = ((INHERIT(OWNER(v7248),Optimize._to_C)) ?
      inner2outer_ask_any(OBJECT(Compile_to_C,v7248)->arg) :
      ((INHERIT(OWNER(v7248),Language._List)) ?
        CTRUE :
        ((INHERIT(OWNER(v7248),Language._Set)) ?
          CTRUE :
          ((INHERIT(OWNER(v7248),Language._Let)) ?
            inner2outer_ask_any(_oid_(OBJECT(Instruction_with_var,v7248)->var)) :
            CFALSE ) ) ) );
    return (Result);} 
  } 

ClaireBoolean * identifiable_ask_any(OID v1140)
{ GC_BIND;
  { ClaireBoolean *Result ;
    { ClaireBoolean *v_or;
      { v_or = ((v1140 == CNULL) ? CTRUE : CFALSE);
        if (v_or == CTRUE) Result =CTRUE; 
        else { if (INHERIT(OWNER(v1140),Optimize._to_CL))
           v_or = identifiable_ask_any(GC_OID(OBJECT(Compile_to_CL,v1140)->arg));
          else { ClaireClass * v7244 = class_I_type(OBJECT(ClaireType,(*Optimize.c_type)(v1140)));
              v_or = not_any(_oid_(contain_ask_set(Optimize.OPT->non_identifiable_set,_oid_(v7244))));
              } 
            if (v_or == CTRUE) Result =CTRUE; 
          else Result = CFALSE;} 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_method1(method *v1140,list *v7236,ClaireClass *v7243)
{ GC_BIND;
  ;{ OID Result = 0;
    Result = (*Optimize.c_code)(GC_OID(c_inline_method2(v1140,v7236)),
      _oid_(v7243));
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_method2(method *v1140,list *v7236)
{ GC_RESERVE(11);  // v3.0.55 optim !
  { OID Result = 0;
    { lambda * v7230 = GC_OBJECT(lambda,v1140->formula);
      OID  v7248 = GC_OID(v7230->body);
      list * v10136 = GC_OBJECT(list,bound_variables_any(v7248));
      symbol * v14530 = (((v1140->selector == Language.iterate) || 
          (v1140->selector == Language.Iterate)) ?
        OBJECT(Variable,(*(v7230->vars))[2])->pname :
        Kernel._class->name );
      v7248= GC_OID(instruction_copy_any(v7248));
      { OID gc_local;
        ITERATE(v7246);
        for (START(v10136); NEXT(v7246);)
        { GC_LOOP;
          { Variable * v11684;
            { { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
                (v2072->pname = ((OBJECT(Variable,v7246)->pname == v14530) ?
                  v14530 :
                  gensym_void() ));
                (v2072->index = 1000);
                add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
                v11684 = v2072;
                } 
              GC_OBJECT(Variable,v11684);} 
            store_object(v11684,
              3,
              Kernel._object,
              get_property(Kernel.range,OBJECT(ClaireObject,v7246)),
              CFALSE);
            GC__OID(v7248 = substitution_any(v7248,OBJECT(Variable,v7246),_oid_(v11684)), 5);
            } 
          GC_UNLOOP;} 
        } 
      (Optimize.OPT->max_vars = (Optimize.OPT->max_vars+v10136->length));
      Result = c_substitution_any(v7248,GC_OBJECT(list,v7230->vars),v7236,CFALSE);
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_inline_arg_ask_any(OID v1140)
{ GC_BIND;
  { OID Result = 0;
    if (INHERIT(OWNER(v1140),Language._Call))
     { list * v7236 = GC_OBJECT(list,OBJECT(Call,v1140)->args);
      OID  v7237;
      { { list * v13758;
          { { bag *v_list; OID v_val;
              OID v7248,CLcount;
              v_list = v7236;
               v13758 = v_list->clone();
              for (CLcount= 1; CLcount <= v_list->length; CLcount++)
              { v7248 = (*(v_list))[CLcount];
                v_val = (*Optimize.c_type)(v7248);
                
                (*((list *) v13758))[CLcount] = v_val;} 
              } 
            GC_OBJECT(list,v13758);} 
          v7237 = restriction_I_property(OBJECT(Call,v1140)->selector,v13758,CTRUE);
          } 
        GC_OID(v7237);} 
      if (Kernel._method == OWNER(v7237))
       { if ((OBJECT(method,v7237)->inline_ask == CTRUE) && 
            (c_inline_ask_method(OBJECT(method,v7237),v7236) == CTRUE))
         Result = c_inline_method2(OBJECT(method,v7237),v7236);
        else Result = Kernel.cfalse;
          } 
      else Result = Core.nil->value;
        } 
    else { OID  v14719;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Kernel.set_I);
          (v2072->args = list::alloc(1,v1140));
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v14719 = _oid_(v2072);
          } 
        Result = c_inline_arg_ask_any(v14719);
        } 
      GC_UNBIND; return (Result);} 
  } 

OID  c_substitution_any(OID v1140,list *v11444,list *v3321,ClaireBoolean *v4859)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID Result = 0;
    if (INHERIT(OWNER(v1140),Language._Variable))
     { OID  v7233;
      { { OID  v10961 = CNULL;
          { int  v7234 = 1;
            int  v6816 = v11444->length;
            { OID gc_local;
              while ((v7234 <= v6816))
              { if (OBJECT(Variable,v1140)->pname == OBJECT(Variable,(*(v11444))[v7234])->pname)
                 { v10961= v7234;
                  break;} 
                ++v7234;
                } 
              } 
            } 
          v7233 = v10961;
          } 
        GC_OID(v7233);} 
      if (v7233 != CNULL)
       Result = (*(v3321))[v7233];
      else Result = v1140;
        } 
    else if (INHERIT(OWNER(v1140),Kernel._bag))
     { { int  v7233 = 1;
        int  v6817 = OBJECT(bag,v1140)->length;
        { OID gc_local;
          while ((v7233 <= v6817))
          { ((*(OBJECT(list,v1140)))[v7233]=c_substitution_any((*(OBJECT(bag,v1140)))[v7233],v11444,v3321,v4859));
            ++v7233;
            } 
          } 
        } 
      Result = v1140;
      } 
    else if (INHERIT(OWNER(v1140),Language._Call))
     { if (OBJECT(Call,v1140)->selector == Core.eval)
       Result = c_substitution_any(GC_OID((*(OBJECT(Call,v1140)->args))[1]),v11444,v3321,((OBJECT(Call,v1140)->args->length == 1) ? CTRUE : (((OBJECT(Call,v1140)->args->length == 2) && 
          (belong_to((*(v3321))[1],(*(OBJECT(Call,v1140)->args))[2]) == CTRUE)) ? CTRUE : CFALSE)));
      else if (v4859 == CTRUE)
       { ClaireHandler c_handle = ClaireHandler();
        if ERROR_IN 
        { { list * v5015;
            { { bag *v_list; OID v_val;
                OID v7249,CLcount;
                v_list = GC_OBJECT(list,OBJECT(Call,v1140)->args);
                 v5015 = v_list->clone();
                for (CLcount= 1; CLcount <= v_list->length; CLcount++)
                { v7249 = (*(v_list))[CLcount];
                  v_val = c_substitution_any(v7249,v11444,v3321,CTRUE);
                  
                  (*((list *) v5015))[CLcount] = v_val;} 
                } 
              GC_OBJECT(list,v5015);} 
            Result = apply_property(OBJECT(Call,v1140)->selector,v5015);
            } 
          ClEnv->cHandle--;} 
        else if (belong_to(_oid_(ClEnv->exception_I),_oid_(Kernel._any)) == CTRUE)
        { c_handle.catchIt();{ tformat_string("a strange problem happens ~A \n",0,GC_OBJECT(list,list::alloc(1,ClEnv->verbose)));
            warn_void();
            tformat_string("failed substitution: ~S",2,GC_OBJECT(list,list::alloc(1,GC_OID(_oid_(ClEnv->exception_I)))));
            c_substitution_any(GC_OID(_oid_(OBJECT(Call,v1140)->args)),v11444,v3321,CFALSE);
            Result = v1140;
            } 
          } 
        else PREVIOUS_HANDLER;} 
      else { c_substitution_any(GC_OID(_oid_(OBJECT(Call,v1140)->args)),v11444,v3321,CFALSE);
          Result = v1140;
          } 
        } 
    else if (INHERIT(OWNER(v1140),Language._Instruction))
     { { OID gc_local;
        ITERATE(v7243);
        bag *v7243_support;
        v7243_support = OWNER(v1140)->slots;
        for (START(v7243_support); NEXT(v7243);)
        { GC_LOOP;
          { OID  v7249 = GC_OID(get_slot(OBJECT(slot,v7243),OBJECT(ClaireObject,v1140)));
            put_slot(OBJECT(slot,v7243),OBJECT(ClaireObject,v1140),c_substitution_any(v7249,v11444,v3321,v4859));
            } 
          GC_UNLOOP;} 
        } 
      Result = v1140;
      } 
    else Result = v1140;
      GC_UNBIND; return (Result);} 
  } 

OID  eval_any2(OID v7248,ClaireClass *v7249)
{ return (OPT_EVAL(v7248));} 

list * bound_variables_any(OID v1140)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * v7236 = list::empty(Kernel._any);
      if (INHERIT(OWNER(v1140),Language._Instruction_with_var))
       v7236= list::alloc(Kernel._any,1,GC_OID(_oid_(OBJECT(For,v1140)->var)));
      if (INHERIT(OWNER(v1140),Language._Variable))
       ;else if (INHERIT(OWNER(v1140),Language._Instruction))
       { OID gc_local;
        ITERATE(v7243);
        for (START(OBJECT(ClaireObject,v1140)->isa->slots); NEXT(v7243);)
        { GC_LOOP;
          GC__ANY(v7236 = add_star_list(v7236,GC_OBJECT(list,bound_variables_any(GC_OID(get_slot(OBJECT(slot,v7243),OBJECT(ClaireObject,v1140)))))), 1);
          GC_UNLOOP;} 
        } 
      else if (INHERIT(OWNER(v1140),Kernel._bag))
       { OID gc_local;
        ITERATE(v7248);
        for (START(OBJECT(bag,v1140)); NEXT(v7248);)
        { GC_LOOP;
          v7236= add_star_list(v7236,GC_OBJECT(list,bound_variables_any(v7248)));
          GC_UNLOOP;} 
        } 
      Result = v7236;
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  c_boolean_any(OID v7248)
{ GC_BIND;
  { OID Result = 0;
    { ClaireType * v11692 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Optimize.c_type)(v7248)));
      ClaireType * v14540 = GC_OBJECT(ClaireType,ptype_type(v11692));
      if (_inf_equal_type(v14540,Kernel._boolean) == CTRUE)
       { if (INHERIT(OWNER(v7248),Language._Call))
         { if ((OBJECT(Call,v7248)->selector == Core.NOT) && 
              (ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(GC_OID((*(OBJECT(Call,v7248)->args))[1])))) != Kernel._boolean))
           { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
              (v2072->selector = Core._I_equal);
              { Call * v6840 = v2072; 
                list * v6841;
                { OID v_bag;
                  GC_ANY(v6841= list::empty(Kernel.emptySet));
                  { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                      (v2072->selector = Kernel.boolean_I);
                      (v2072->args = list::alloc(1,GC_OID((*(OBJECT(Call,v7248)->args))[1])));
                      add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                      v_bag = _oid_(v2072);
                      } 
                    GC_OID(v_bag);} 
                  ((list *) v6841)->addFast(v_bag);
                  ((list *) v6841)->addFast(Kernel.ctrue);} 
                (v6840->args = v6841);} 
              add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
              v7248 = _oid_(v2072);
              } 
            GC_OID(v7248);} 
          } 
        if (_inf_equal_type(v11692,Kernel._boolean) == CTRUE)
         Result = c_strict_code_any(v7248,Kernel._boolean);
        else Result = (*Optimize.c_code)(v7248,
            _oid_(Kernel._boolean));
          } 
      else if (_inf_equal_type(v11692,Kernel._bag) == CTRUE)
       { OID  v7898;
        { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
          (v2072->selector = Core._I_equal);
          { Call * v6844 = v2072; 
            list * v6845;
            { OID v_bag;
              GC_ANY(v6845= list::empty(Kernel.emptySet));
              { { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
                  (v2072->selector = Kernel.length);
                  (v2072->args = list::alloc(1,v7248));
                  add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
                  v_bag = _oid_(v2072);
                  } 
                GC_OID(v_bag);} 
              ((list *) v6845)->addFast(v_bag);
              ((list *) v6845)->addFast(0);} 
            (v6844->args = v6845);} 
          add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
          v7898 = _oid_(v2072);
          } 
        Result = (*Optimize.c_code)(v7898);
        } 
      else { OID  v10781;
          { Call * v2072 = ((Call *) GC_OBJECT(Call,new_object_class(Language._Call)));
            (v2072->selector = Kernel.boolean_I);
            (v2072->args = list::alloc(1,v7248));
            add_I_property(Kernel.instances,Language._Call,11,_oid_(v2072));
            v10781 = _oid_(v2072);
            } 
          Result = (*Optimize.c_code)(v10781);
          } 
        } 
    GC_UNBIND; return (Result);} 
  } 

