/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\gexp.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:49 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
ClaireBoolean * c_func_any(OID v9396)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v9396),Kernel._bag))
     { OID  v4712;
      { OID gc_local;
        ITERATE(v9232);
        v4712= Kernel.cfalse;
        for (START(OBJECT(bag,v9396)); NEXT(v9232);)
        if (c_func_any(v9232) != CTRUE)
         { v4712 = Kernel.ctrue;
          break;} 
        else ;} 
      Result = not_any(v4712);
      } 
    else if (INHERIT(OWNER(v9396),Language._Construct))
     { if (((INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Set)) || 
            (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._List))) || 
          (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Tuple)))
       { ClaireBoolean *v_and;
        { v_and = ((OBJECT(Construct,v9396)->args->length < 15) ? CTRUE : CFALSE);
          if (v_and == CFALSE) Result =CFALSE; 
          else { { OID  v9470;
              { ClaireBoolean * v8250;{ OID  v11392;
                  { set * v8252;{ set * v15007 = set::empty(Kernel.emptySet);
                      { OID gc_local;
                        ITERATE(v9232);
                        bag *v9232_support;
                        v9232_support = GC_OBJECT(list,OBJECT(Construct,v9396)->args);
                        for (START(v9232_support); NEXT(v9232);)
                        if (c_func_any(v9232) != CTRUE)
                         v15007->addFast(v9232);
                        } 
                      v8252 = GC_OBJECT(set,v15007);
                      } 
                    
                    v11392=_oid_(v8252);} 
                  v8250 = boolean_I_any(v11392);
                  } 
                
                v9470=_oid_(v8250);} 
              v_and = ((v9470 != Kernel.ctrue) ? CTRUE : CFALSE);
              } 
            if (v_and == CFALSE) Result =CFALSE; 
            else Result = CTRUE;} 
          } 
        } 
      else Result = CFALSE;
        } 
    else if (INHERIT(OWNER(v9396),Language._If))
     { ClaireBoolean *v_and;
      { v_and = c_func_any(GC_OID(OBJECT(If,v9396)->test));
        if (v_and == CFALSE) Result =CFALSE; 
        else { v_and = c_func_any(GC_OID(OBJECT(If,v9396)->arg));
          if (v_and == CFALSE) Result =CFALSE; 
          else { v_and = c_func_any(GC_OID(OBJECT(If,v9396)->other));
            if (v_and == CFALSE) Result =CFALSE; 
            else { v_and = stupid_t_any2(GC_OID(OBJECT(If,v9396)->arg),GC_OID(OBJECT(If,v9396)->other));
              if (v_and == CFALSE) Result =CFALSE; 
              else { { int  v9223 = 4;
                  OID  v9232 = GC_OID(OBJECT(If,v9396)->other);
                  { OID v15730;{ OID gc_local;
                      v15730= _oid_(CFALSE);
                      while ((v9223 > 0))
                      { GC_LOOP;
                        if (INHERIT(OWNER(v9232),Language._If))
                         { GC__OID(v9232 = OBJECT(If,v9232)->other, 1);
                          v9223= (v9223-1);
                          } 
                        else { v15730 = Kernel.ctrue;
                            break;} 
                          GC_UNLOOP;} 
                      } 
                    
                    v_and=OBJECT(ClaireBoolean,v15730);} 
                  } 
                if (v_and == CFALSE) Result =CFALSE; 
                else Result = CTRUE;} 
              } 
            } 
          } 
        } 
      } 
    else if (INHERIT(OWNER(v9396),Language._Assign))
     Result = c_func_any(GC_OID(OBJECT(Assign,v9396)->arg));
    else if (INHERIT(OWNER(v9396),Language._Gassign))
     Result = c_func_any(GC_OID(OBJECT(Gassign,v9396)->arg));
    else if (INHERIT(OWNER(v9396),Optimize._to_protect))
     Result = c_func_any(GC_OID(OBJECT(Compile_to_protect,v9396)->arg));
    else if (INHERIT(OWNER(v9396),Language._And))
     Result = c_func_any(GC_OID(_oid_(OBJECT(And,v9396)->args)));
    else if (INHERIT(OWNER(v9396),Language._Or))
     Result = c_func_any(GC_OID(_oid_(OBJECT(Or,v9396)->args)));
    else if (INHERIT(OWNER(v9396),Language._Call))
     Result = c_func_any(GC_OID(_oid_(OBJECT(Call,v9396)->args)));
    else if (INHERIT(OWNER(v9396),Language._Call_method))
     Result = ((c_func_any(GC_OID(_oid_(OBJECT(Call_method,v9396)->args))) == CTRUE) ? ((_oid_(OBJECT(Call_method,v9396)->arg) != Generate._starclose_exception_star->value) ? CTRUE: CFALSE): CFALSE);
    else if (INHERIT(OWNER(v9396),Language._Call_slot))
     Result = c_func_any(GC_OID(OBJECT(Call_slot,v9396)->arg));
    else if (INHERIT(OWNER(v9396),Language._Call_table))
     Result = c_func_any(GC_OID(OBJECT(Call_table,v9396)->arg));
    else if (INHERIT(OWNER(v9396),Language._Call_array))
     Result = c_func_any(GC_OID(OBJECT(Call_array,v9396)->arg));
    else Result = ((INHERIT(OWNER(v9396),Language._Update)) ?
      ((c_func_any(GC_OID(OBJECT(Update,v9396)->value)) == CTRUE) ? ((c_func_any(GC_OID(OBJECT(Update,v9396)->arg)) == CTRUE) ? CTRUE: CFALSE): CFALSE) :
      ((INHERIT(OWNER(v9396),Language._Cast)) ?
        c_func_any(GC_OID(OBJECT(Cast,v9396)->arg)) :
        ((INHERIT(OWNER(v9396),Optimize._to_C)) ?
          c_func_any(GC_OID(OBJECT(Compile_to_C,v9396)->arg)) :
          ((INHERIT(OWNER(v9396),Optimize._to_CL)) ?
            c_func_any(GC_OID(OBJECT(Compile_to_CL,v9396)->arg)) :
            ((INHERIT(OWNER(v9396),Kernel._thing)) ? CTRUE : 
            ((INHERIT(OWNER(v9396),Kernel._integer)) ? CTRUE : 
            ((Kernel._string == OWNER(v9396)) ? CTRUE : 
            ((INHERIT(OWNER(v9396),Kernel._char)) ? CTRUE : 
            ((Kernel._float == OWNER(v9396)) ? CTRUE : 
            ((INHERIT(OWNER(v9396),Language._Variable)) ? CTRUE : 
            ((INHERIT(OWNER(v9396),Core._global_variable)) ? CTRUE : 
            ((INHERIT(OWNER(v9396),Kernel._function)) ? CTRUE : 
            ((INHERIT(OWNER(v9396),Kernel._symbol)) ? CTRUE : 
            ((v9396 == CNULL) ? CTRUE : 
            ((Kernel._boolean == OWNER(v9396)) ? CTRUE : 
            ((INHERIT(OWNER(v9396),Kernel._class)) ? CTRUE : 
            ((INHERIT(OWNER(v9396),Kernel._environment)) ? CTRUE : 
            CFALSE))))))))))))) ) ) ) );
    GC_UNBIND; return (Result);} 
  } 

void  expression_thing(thing *v9396,OID v7180)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v9396));
  } 

void  expression_integer(int v9396,OID v7180)
{ princ_integer(v9396);
  } 

void  expression_any(OID v9396,OID v7180)
{ (*Generate.produce)(Generate.PRODUCER->value,
    v9396);
  } 

void  expression_string(char *v9396,OID v7180)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _string_(v9396));
  } 

void  expression_float_(OID v6626,OID v6627)
{ expression_float(float_v(v6626),v6627);} 

void  expression_float(double v9396,OID v7180)
{ princ_float(v9396);
  } 

void  expression_boolean(ClaireBoolean *v9396,OID v7180)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v9396));
  } 

void  expression_environment(ClaireEnvironment *v9396,OID v7180)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v9396));
  } 

void  expression_Variable(Variable *v9396,OID v7180)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v9396));
  } 

void  expression_global_variable(global_variable *v9396,OID v7180)
{ (*Generate.produce)(Generate.PRODUCER->value,
    _oid_(v9396));
  } 

void  expression_Set(Set *v9396,OID v7180)
{ GC_BIND;
  { OID  v15236;
    { if (((v9396->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v15236 = _oid_(v9396->of);
      else v15236 = _oid_(Kernel._void);
        GC_OID(v15236);} 
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._set),
      GC_OID(_oid_(v9396->args)),
      v15236,
      v7180);
    } 
  GC_UNBIND;} 

void  expression_set2(set *v9396,OID v7180)
{ GC_BIND;
  if ((v9396->length == 0) && 
      (equal(_oid_(of_bag(v9396)),_oid_(Kernel.emptySet)) == CTRUE))
   princ_string("Kernel.emptySet");
  else (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._set),
      _oid_(v9396),
      GC_OID(_oid_(of_bag(v9396))),
      v7180);
    GC_UNBIND;} 

void  expression_Tuple(Tuple *v9396,OID v7180)
{ GC_BIND;
  (*Generate.bag_expression)(Generate.PRODUCER->value,
    _oid_(Kernel._tuple),
    GC_OID(_oid_(v9396->args)),
    _oid_(Kernel._void),
    v7180);
  GC_UNBIND;} 

void  expression_tuple(tuple *v9396,OID v7180)
{ (*Generate.bag_expression)(Generate.PRODUCER->value,
    _oid_(Kernel._tuple),
    _oid_(v9396),
    _oid_(Kernel._void),
    v7180);
  } 

void  expression_List(List *v9396,OID v7180)
{ GC_BIND;
  { OID  v16197;
    { if (((v9396->of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
       v16197 = _oid_(v9396->of);
      else v16197 = _oid_(Kernel._void);
        GC_OID(v16197);} 
    (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._list),
      GC_OID(_oid_(v9396->args)),
      v16197,
      v7180);
    } 
  GC_UNBIND;} 

void  expression_list(list *v9396,OID v7180)
{ GC_BIND;
  if ((v9396->length == 0) && 
      (equal(_oid_(of_bag(v9396)),_oid_(Kernel.emptySet)) == CTRUE))
   princ_string("Kernel.nil");
  else (*Generate.bag_expression)(Generate.PRODUCER->value,
      _oid_(Kernel._list),
      _oid_(v9396),
      GC_OID(_oid_(of_bag(v9396))),
      v7180);
    GC_UNBIND;} 

void  expression_Call2(Call *v9396,OID v7180)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_Call_method12(Call_method1 *v9396,OID v7180)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_Call_method22(Call_method2 *v9396,OID v7180)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_Call_method2(Call_method *v9396,OID v7180)
{ (*Generate.inline_exp)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  bexpression_any(OID v9396,OID v7180)
{ if (INHERIT(OWNER(v9396),Language._Assign))
   { princ_string("(");
    expression_Assign(OBJECT(Assign,v9396),v7180);
    princ_string(")");
    } 
  else if (INHERIT(OWNER(v9396),Optimize._to_C))
   { princ_string("(");
    (*Generate.expression)(v9396,
      v7180);
    princ_string(")");
    } 
  else if (INHERIT(OWNER(v9396),Kernel._integer))
   { if (v9396 < 0)
     { princ_string("(");
      expression_integer(v9396,v7180);
      princ_string(")");
      } 
    else expression_integer(v9396,v7180);
      } 
  else if (Kernel._float == OWNER(v9396))
   { if (float_v(v9396) < 0.0)
     { princ_string("(");
      expression_float(float_v(v9396),v7180);
      princ_string(")");
      } 
    else expression_float(float_v(v9396),v7180);
      } 
  else (*Generate.expression)(v9396,
      v7180);
    } 

void  expression_If(If *v9396,OID v7180)
{ GC_BIND;
  princ_string("(");
  (*Optimize.bool_exp)(GC_OID(v9396->test),
    Kernel.ctrue,
    v7180);
  princ_string(" ?");
  (Optimize.OPT->level = (Optimize.OPT->level+1));
  breakline_void();
  (*Generate.expression)(GC_OID(v9396->arg),
    v7180);
  princ_string(" :");
  breakline_void();
  (*Generate.expression)(GC_OID(v9396->other),
    v7180);
  princ_string(" )");
  (Optimize.OPT->level = (Optimize.OPT->level-1));
  GC_UNBIND;} 

void  expression_Assign(Assign *v9396,OID v7180)
{ GC_BIND;
  { OID  v9232 = v9396->arg;
    OID  v9236 = v9396->var;
    if ((INHERIT(OWNER(v9232),Language._Call_method2)) && ((_oid_(OBJECT(Call_method,v9232)->arg) == Generate._star_plus_integer_star->value) && 
        ((equal((*(OBJECT(Call_method,v9232)->args))[1],v9396->var) == CTRUE) && 
          ((*(OBJECT(Call_method,v9232)->args))[2] == 1))))
     { princ_string("++");
      (*Generate.expression)(v9236,
        v7180);
      princ_string("");
      } 
    else if ((boolean_I_any(v7180) == CTRUE) && 
        ((Optimize.OPT->loop_gc == CTRUE) && 
          (inner2outer_ask_any(v9232) == CTRUE)))
     { OID  v6493;
      { if (INHERIT(OWNER(v9232),Optimize._to_protect))
         v6493 = OBJECT(Compile_to_protect,v9232)->arg;
        else v6493 = v9232;
          GC_OID(v6493);} 
      (*Generate.gc_protection_exp)(Generate.PRODUCER->value,
        v9236,
        Kernel.ctrue,
        v6493,
        v7180);
      } 
    else (*Generate.exp_Assign)(Generate.PRODUCER->value,
        _oid_(v9396),
        v7180);
      } 
  GC_UNBIND;} 

void  expression_to_protect(Compile_to_protect *v9396,OID v7180)
{ (*Generate.exp_to_protect)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_Gassign(Gassign *v9396,OID v7180)
{ (*Generate.gassign)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_And(And *v9396,OID v7180)
{ GC_BIND;
  { ClaireBoolean * v9210 = ((v9396->args->length > 5) ? CTRUE : CFALSE);
    { OID gc_local;
      ITERATE(v9232);
      for (START(v9396->args); NEXT(v9232);)
      { princ_string("(");
        (*Optimize.bool_exp)(v9232,
          Kernel.ctrue,
          v7180);
        princ_string(" ? ");
        if (v9210 == CTRUE)
         breakline_void();
        } 
      } 
    expression_boolean(CTRUE,v7180);
    { OID gc_local;
      ITERATE(v9232);
      for (START(v9396->args); NEXT(v9232);)
      { princ_string(": ");
        expression_boolean(CFALSE,v7180);
        princ_string(")");
        } 
      } 
    } 
  GC_UNBIND;} 

void  expression_Or(Or *v9396,OID v7180)
{ GC_BIND;
  { ClaireBoolean * v9210 = ((v9396->args->length > 5) ? CTRUE : CFALSE);
    { OID gc_local;
      ITERATE(v9232);
      for (START(v9396->args); NEXT(v9232);)
      { princ_string("(");
        (*Optimize.bool_exp)(v9232,
          Kernel.ctrue,
          v7180);
        princ_string(" ? ");
        expression_boolean(CTRUE,v7180);
        princ_string(" : ");
        if (v9210 == CTRUE)
         breakline_void();
        } 
      } 
    expression_boolean(CFALSE,v7180);
    { OID gc_local;
      ITERATE(v9232);
      for (START(v9396->args); NEXT(v9232);)
      princ_string(")");
      } 
    } 
  GC_UNBIND;} 

void  expression_to_CL(Compile_to_CL *v9396,OID v7180)
{ GC_BIND;
  (*Generate.to_cl)(Generate.PRODUCER->value,
    v9396->arg,
    _oid_(v9396->set_arg),
    v7180);
  GC_UNBIND;} 

void  expression_to_C(Compile_to_C *v9396,OID v7180)
{ GC_BIND;
  (*Generate.to_c)(Generate.PRODUCER->value,
    v9396->arg,
    _oid_(v9396->set_arg),
    v7180);
  GC_UNBIND;} 

void  expression_C_cast(Compile_C_cast *v9396,OID v7180)
{ (*Kernel.cast_I)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_Call_slot(Call_slot *v9396,OID v7180)
{ (*Generate.call_slot)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_Call_table(Call_table *v9396,OID v7180)
{ (*Generate.call_table)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_Call_array(Call_array *v9396,OID v7180)
{ (*Generate.call_array)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  expression_Update(Update *v9396,OID v7180)
{ (*Generate.update)(Generate.PRODUCER->value,
    _oid_(v9396),
    v7180);
  } 

void  sign_equal_boolean(ClaireBoolean *v9396)
{ if (v9396 == CTRUE)
   princ_string("==");
  else princ_string("!=");
    } 

void  sign_or_boolean(ClaireBoolean *v9396)
{ if (v9396 == CTRUE)
   princ_string("||");
  else princ_string("&&");
    } 

void  bool_exp_any_Generate(OID v9396,ClaireBoolean *v11731,OID v7180)
{ any_bool_exp_any(v9396,v11731,v7180,not_any(_oid_(((INHERIT(OWNER(v9396),Core._global_variable)) ? ((nativeVar_ask_global_variable(OBJECT(global_variable,v9396)) != CTRUE) ? CTRUE: CFALSE): CFALSE))));
  } 

void  any_bool_exp_any(OID v9396,ClaireBoolean *v11731,OID v7180,ClaireBoolean *v4262)
{ princ_string("(");
  bexpression_any(v9396,v7180);
  princ_string(" ");
  if (v11731 != CTRUE)
   princ_string("!=");
  else princ_string("==");
    princ_string(" ");
  if (v4262 != CTRUE)
   (*Generate.to_cl)(Generate.PRODUCER->value,
    Kernel.ctrue,
    _oid_(Kernel._boolean),
    v7180);
  else expression_boolean(CTRUE,v7180);
    princ_string(")");
  } 

void  bool_exp_to_CL_Generate(Compile_to_CL *v9396,ClaireBoolean *v11731,OID v7180)
{ GC_BIND;
  (*Optimize.bool_exp)(v9396->arg,
    _oid_(v11731),
    v7180);
  GC_UNBIND;} 

void  bool_exp_If_Generate(If *v9396,ClaireBoolean *v11731,OID v7180)
{ GC_BIND;
  if (boolean_I_any(v9396->other) == CTRUE)
   { princ_string("(");
    (*Optimize.bool_exp)(v9396->test,
      Kernel.ctrue,
      v7180);
    princ_string(" ? ");
    (*Optimize.bool_exp)(v9396->arg,
      _oid_(v11731),
      v7180);
    princ_string(" : ");
    (*Optimize.bool_exp)(v9396->other,
      _oid_(v11731),
      v7180);
    princ_string(")");
    } 
  else { princ_string("(");
      (*Optimize.bool_exp)(v9396->test,
        _oid_(v11731),
        v7180);
      princ_string(" ");
      sign_or_boolean(not_any(_oid_(v11731)));
      princ_string(" ");
      (*Optimize.bool_exp)(v9396->arg,
        _oid_(v11731),
        v7180);
      princ_string(")");
      } 
    GC_UNBIND;} 

void  bool_exp_And_Generate(And *v9396,ClaireBoolean *v11731,OID v7180)
{ GC_BIND;
  { list * v9222 = GC_OBJECT(list,v9396->args);
    int  v9221 = v9222->length;
    int  v9223 = 0;
    int  v5199 = Optimize.OPT->level;
    (Optimize.OPT->level = (Optimize.OPT->level+1));
    { OID gc_local;
      ITERATE(v9232);
      for (START(v9222); NEXT(v9232);)
      { ++v9223;
        if (v9223 == v9221)
         (*Optimize.bool_exp)(v9232,
          _oid_(v11731),
          v7180);
        else { princ_string("(");
            (*Optimize.bool_exp)(v9232,
              _oid_(v11731),
              v7180);
            princ_string(" ");
            sign_or_boolean(not_any(_oid_(v11731)));
            princ_string(" ");
            (Optimize.OPT->level = (Optimize.OPT->level+1));
            breakline_void();
            } 
          } 
      } 
    { int  v9232 = 2;
      int  v6657 = v9221;
      { OID gc_local;
        while ((v9232 <= v6657))
        { princ_string(")");
          ++v9232;
          } 
        } 
      } 
    (Optimize.OPT->level = v5199);
    } 
  GC_UNBIND;} 

void  bool_exp_Or_Generate(Or *v9396,ClaireBoolean *v11731,OID v7180)
{ GC_BIND;
  { list * v9222 = GC_OBJECT(list,v9396->args);
    int  v9221 = v9222->length;
    int  v9223 = 0;
    int  v5199 = Optimize.OPT->level;
    (Optimize.OPT->level = (Optimize.OPT->level+1));
    { OID gc_local;
      ITERATE(v9232);
      for (START(v9222); NEXT(v9232);)
      { ++v9223;
        if (v9223 == v9221)
         (*Optimize.bool_exp)(v9232,
          _oid_(v11731),
          v7180);
        else { princ_string("(");
            (*Optimize.bool_exp)(v9232,
              _oid_(v11731),
              v7180);
            princ_string(" ");
            sign_or_boolean(v11731);
            princ_string(" ");
            (Optimize.OPT->level = (Optimize.OPT->level+1));
            breakline_void();
            } 
          } 
      } 
    { int  v9232 = 2;
      int  v6660 = v9221;
      { OID gc_local;
        while ((v9232 <= v6660))
        { princ_string(")");
          ++v9232;
          } 
        } 
      } 
    (Optimize.OPT->level = v5199);
    } 
  GC_UNBIND;} 

void  bool_exp_Call_method1_Generate(Call_method1 *v9396,ClaireBoolean *v11731,OID v7180)
{ GC_BIND;
  { method * v9221 = v9396->arg;
    OID  v7000 = (*(v9396->args))[1];
    if (_oid_(v9221) == Generate._starnot_star->value)
     { if (INHERIT(OWNER(v7000),Optimize._to_CL))
       any_bool_exp_any(GC_OID((*Kernel.arg)(v7000)),not_any(_oid_(v11731)),v7180,CTRUE);
      else any_bool_exp_any(v7000,not_any(_oid_(v11731)),v7180,CFALSE);
        } 
    else if (_oid_(v9221) == Generate._starknown_star->value)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v7000,
      _oid_(not_any(_oid_(v11731))),
      CNULL,
      v7180);
    else if (_oid_(v9221) == Generate._starunknown_star->value)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v7000,
      _oid_(v11731),
      CNULL,
      v7180);
    else if (_inf_equal_type(v9221->range,Kernel._boolean) == CTRUE)
     { princ_string("(");
      expression_Call_method12(v9396,v7180);
      princ_string(" ");
      sign_equal_boolean(v11731);
      princ_string(" ");
      expression_boolean(CTRUE,v7180);
      princ_string(")");
      } 
    else { OID v_rec;
        v_rec = _oid_(v9396);
        PUSH(v_rec);
        v_rec = _oid_(v11731);
        PUSH(v_rec);
        v_rec = v7180;
        PUSH(v_rec);
        Optimize.bool_exp->super(Kernel._any,3);} 
      } 
  GC_UNBIND;} 

void  bool_exp_Call_method2_Generate(Call_method2 *v9396,ClaireBoolean *v11731,OID v7180)
{ GC_BIND;
  { method * v9221 = v9396->arg;
    property * v9226 = v9221->selector;
    list * v229 = GC_OBJECT(list,OBJECT(Generate_producer,Generate.PRODUCER->value)->open_comparators);
    OID  v7000 = (*(v9396->args))[1];
    OID  v7002 = (*(v9396->args))[2];
    if (v9226 == Core._I_equal)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v7000,
      _oid_(not_any(_oid_(v11731))),
      v7002,
      Core.nil->value);
    else if (v9226 == Core.identical_ask)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v7000,
      _oid_(v11731),
      v7002,
      Kernel.ctrue);
    else if (v9226 == Kernel._equal)
     (*Generate.equal_exp)(Generate.PRODUCER->value,
      v7000,
      _oid_(v11731),
      v7002,
      Core.nil->value);
    else if ((v229->memq(_oid_(v9226)) == CTRUE) && 
        ((domain_I_restriction(v9221) == Kernel._integer) || 
            (domain_I_restriction(v9221) == Kernel._float)))
     { princ_string("(");
      (*Generate.expression)(v7000,
        v7180);
      princ_string(" ");
      if (v11731 == CTRUE)
       print_any(_oid_(v9226));
      else print_any((*(v229))[(mod_integer((index_list(v229,_oid_(v9226))+1),4)+1)]);
        princ_string(" ");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(")");
      } 
    else if (_oid_(v9221) == Generate._starnth_integer_star->value)
     { princ_string("(");
      if (v11731 != CTRUE)
       princ_string("!");
      (*Generate.bitvector_exp)(Generate.PRODUCER->value,
        v7000,
        v7002,
        v7180);
      princ_string(")");
      } 
    else if ((v9226 == Core.inherit_ask) && 
        (domain_I_restriction(v9221) == Kernel._class))
     { princ_string("(");
      if (v11731 != CTRUE)
       princ_string("!");
      (*Generate.inherit_exp)(Generate.PRODUCER->value,
        v7000,
        v7002,
        v7180);
      princ_string(")");
      } 
    else if (_inf_equal_type(v9221->range,Kernel._boolean) == CTRUE)
     { princ_string("(");
      expression_Call_method22(v9396,v7180);
      princ_string(" ");
      sign_equal_boolean(v11731);
      princ_string(" ");
      expression_boolean(CTRUE,v7180);
      princ_string(")");
      } 
    else { OID v_rec;
        v_rec = _oid_(v9396);
        PUSH(v_rec);
        v_rec = _oid_(v11731);
        PUSH(v_rec);
        v_rec = v7180;
        PUSH(v_rec);
        Optimize.bool_exp->super(Kernel._any,3);} 
      } 
  GC_UNBIND;} 

ClaireBoolean * bool_exp_ask_any(OID v9232)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v9232),Optimize._to_CL))
     Result = bool_exp_ask_any(OBJECT(Compile_to_CL,v9232)->arg);
    else if (INHERIT(OWNER(v9232),Language._Call_method))
     { property * v9226 = OBJECT(Call_method,v9232)->arg->selector;
      Result = (((OBJECT(Call_method,v9232)->arg->range == Kernel._boolean) && 
          ((v9226 == Kernel._equal) || 
              ((v9226 == Core._I_equal) || 
                ((v9226 == Kernel._sup) || 
                  ((v9226 == Kernel._sup_equal) || 
                    ((v9226 == Kernel._inf) || 
                      (v9226 == Kernel._inf_equal))))))) ? CTRUE : (((v9226 == Core.NOT) && 
          (bool_exp_ask_any((*(OBJECT(Call_method,v9232)->args))[1]) == CTRUE)) ? CTRUE : CFALSE));
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  args_list_bag(bag *v9396,OID v7180,ClaireBoolean *v6830)
{ { ClaireBoolean * v15635 = CTRUE;
    if (v6830 == CTRUE)
     (Optimize.OPT->level = (Optimize.OPT->level+1));
    { ITERATE(v9232);
      for (START(v9396); NEXT(v9232);)
      if (v15635 == CTRUE)
       { (*Generate.expression)(v9232,
          v7180);
        v15635= CFALSE;
        } 
      else { princ_string(",");
          if (v6830 == CTRUE)
           breakline_void();
          (*Generate.expression)(v9232,
            v7180);
          princ_string("");
          } 
        } 
    if (v6830 == CTRUE)
     (Optimize.OPT->level = (Optimize.OPT->level-1));
    } 
  } 

char * check_var_string(char *v9396,OID v9233,OID v7180)
{ { char *Result ;
    Result = (((equal(_string_(v9396),v9233) == CTRUE) || 
        (equal(_string_(v9396),v7180) == CTRUE)) ?
      append_string(v9396,"1") :
      v9396 );
    return (Result);} 
  } 

Variable * build_Variable_string(char *v9233,OID v9231)
{ return (Variable_I_symbol(symbol_I_string2(v9233),0,OBJECT(ClaireType,v9231)));} 

