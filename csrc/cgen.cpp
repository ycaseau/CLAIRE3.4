/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\cgen.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:50 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
char * c_string_c_producer1(Generate_c_producer *v9211,Variable *v9396)
{ GC_BIND;
  { char *Result ;
    if (Optimize.compiler->naming == 2)
     Result = append_string("v",GC_STRING(string_I_integer (integer_I_symbol(v9396->pname))));
    else { print_in_string_void();
        ident_c_producer(v9211,v9396->pname);
        Result = end_of_print_void();
        } 
      GC_UNBIND; return (Result);} 
  } 

char * c_string_c_producer2(Generate_c_producer *v9211,symbol *v9396)
{ print_in_string_void();
  ident_c_producer(v9211,v9396);
  return (end_of_print_void());} 

char * string_I_c_producer1(Generate_c_producer *v9211,Variable *v9396)
{ GC_BIND;
  { char *Result ;
    if (Optimize.compiler->naming == 2)
     Result = append_string("v",GC_STRING(string_I_integer (integer_I_symbol(v9396->pname))));
    else { print_in_string_void();
        ident_c_producer(v9211,v9396->pname);
        Result = end_of_print_void();
        } 
      GC_UNBIND; return (Result);} 
  } 

char * string_I_c_producer2(Generate_c_producer *v9211,symbol *v9396)
{ print_in_string_void();
  ident_c_producer(v9211,v9396);
  return (end_of_print_void());} 

void  ident_c_producer3(Generate_c_producer *v9211,Variable *v9236)
{ GC_BIND;
  if (Optimize.compiler->naming == 2)
   princ_string(append_string("v",GC_STRING(string_I_integer (integer_I_symbol(v9236->pname)))));
  else { symbol * v9233 = v9236->pname;
      int  v9223 = index_list(v9211->bad_names,_oid_(v9233));
      if (v9223 == 0)
       c_princ_string(string_I_symbol(v9233));
      else c_princ_symbol(OBJECT(symbol,(*(v9211->good_names))[v9223]));
        } 
    GC_UNBIND;} 

void  ident_c_producer(Generate_c_producer *v9211,symbol *v9233)
{ { int  v9223 = index_list(v9211->bad_names,_oid_(v9233));
    if (v9223 == 0)
     c_princ_string(string_I_symbol(v9233));
    else c_princ_symbol(OBJECT(symbol,(*(v9211->good_names))[v9223]));
      } 
  } 

void  class_princ_c_producer(Generate_c_producer *v9211,ClaireClass *v9396)
{ if (v9396->name->module_I != claire.it)
   { ident_c_producer(v9211,v9396->name->module_I->name);
    princ_string("_");
    } 
  ident_c_producer(v9211,v9396->name);
  } 

void  produce_c_producer2(Generate_c_producer *v9211,OID v9232)
{ GC_BIND;
  if (INHERIT(OWNER(v9232),Kernel._function))
   { princ_string("_function_(");
    c_princ_function(OBJECT(ClaireFunction,v9232));
    princ_string(",");
    print_any(GC_OID(_string_(string_I_function(OBJECT(ClaireFunction,v9232)))));
    princ_string(")");
    } 
  else if (INHERIT(OWNER(v9232),Kernel._char))
   { princ_string("_char_('");
    if ((v9232 == _oid_(_char_('\"'))) || 
        ((v9232 == _oid_(_char_('\''))) || 
          ((v9232 == _oid_(_char_('\?'))) || 
            (v9232 == _oid_(_char_('\\'))))))
     princ_string("\\");
    princ_char(OBJECT(ClaireChar,v9232));
    princ_string("')");
    } 
  else if (INHERIT(OWNER(v9232),Kernel._environment))
   princ_string("ClEnv");
  else if (Kernel._string == OWNER(v9232))
   { if (Optimize.OPT->use_string_update == CTRUE)
     { princ_string("copy_string(");
      print_any(v9232);
      princ_string(")");
      } 
    else print_any(v9232);
      } 
  else if (INHERIT(OWNER(v9232),Core._global_variable))
   globalVar_c_producer(v9211,OBJECT(global_variable,v9232));
  else if (Kernel._boolean == OWNER(v9232))
   { if ((OBJECT(ClaireBoolean,v9232)) == CTRUE)
     princ_string("CTRUE");
    else princ_string("CFALSE");
      } 
  else if (INHERIT(OWNER(v9232),Kernel._symbol))
   { princ_string("symbol::make(");
    print_any(GC_OID(_string_(string_I_symbol(OBJECT(symbol,v9232)))));
    princ_string(",");
    ident_symbol(OBJECT(symbol,v9232)->module_I->name);
    princ_string(",");
    ident_symbol(defined_symbol(OBJECT(symbol,v9232))->name);
    princ_string(")");
    } 
  else if (INHERIT(OWNER(v9232),Kernel._class))
   { if (v9232 == _oid_(Kernel._cl_import))
     princ_string("Kernel._cl_import");
    else { ident_c_producer(v9211,defined_symbol(OBJECT(ClaireClass,v9232)->name)->name);
        princ_string("._");
        c_princ_string(string_I_symbol(OBJECT(ClaireClass,v9232)->name));
        princ_string("");
        } 
      } 
  else if (INHERIT(OWNER(v9232),Reader._reserved_keyword))
   { ident_c_producer(v9211,defined_symbol(OBJECT(thing,v9232)->name)->name);
    princ_string("._cl_");
    c_princ_string(string_I_symbol(OBJECT(thing,v9232)->name));
    princ_string("");
    } 
  else if (INHERIT(OWNER(v9232),Kernel._thing))
   { if (INHERIT(OBJECT(ClaireObject,v9232)->isa,Kernel._module))
     { ident_c_producer(v9211,OBJECT(thing,v9232)->name);
      princ_string(".it");
      } 
    else { ident_c_producer(v9211,defined_symbol(OBJECT(thing,v9232)->name)->name);
        princ_string(".");
        ident_symbol(OBJECT(thing,v9232)->name);
        princ_string("");
        } 
      } 
  else princ_string("CNULL");
    GC_UNBIND;} 

void  globalVar_c_producer(Generate_c_producer *v9211,global_variable *v9232)
{ if ((equal(_oid_(v9232->range),_oid_(Kernel.emptySet)) == CTRUE) && 
      (INHERIT(OWNER(v9232->value),Kernel._integer))) 
  { (*Kernel.princ)(v9232->value);
     } 
  else{ GC_BIND;
    ident_c_producer(v9211,defined_symbol(v9232->name)->name);
    princ_string(".");
    ident_symbol(v9232->name);
    if (nativeVar_ask_global_variable(v9232) != CTRUE)
     princ_string("->value");
    princ_string("");
    GC_UNBIND;} 
  } 

void  stat_exp_c_producer(Generate_c_producer *v9211,OID v9396,OID v7180)
{ if (INHERIT(OWNER(v9396),Optimize._to_C)) 
  { stat_exp_c_producer(v9211,GC_OID(OBJECT(Compile_to_C,v9396)->arg),v7180);
     } 
  else{ if (INHERIT(OWNER(v9396),Optimize._to_CL)) 
    { stat_exp_c_producer(v9211,GC_OID(OBJECT(Compile_to_CL,v9396)->arg),v7180);
       } 
    else{ GC_BIND;
      if (designated_ask_any(v9396) == CTRUE)
       princ_string(";");
      else { (*Generate.expression)(v9396,
            v7180);
          princ_string(";");
          breakline_void();
          princ_string("");
          } 
        GC_UNBIND;} 
    } 
  } 

void  namespace_I_c_producer(Generate_c_producer *v9211,module *v9221)
{ princ_string("\n\n// namespace class for ");
  print_any(_oid_(v9221));
  princ_string(" \n");
  { princ_string("class ");
    ident_c_producer(v9211,v9221->name);
    princ_string("Class: public NameSpace {\npublic:\n");
    } 
  } 

void  module_I_c_producer(Generate_c_producer *v9211,module *v9221)
{ princ_string("\n\n// module definition \n");
  princ_string(" void metaLoad();};\n\n");
  princ_string("extern ");
  ident_c_producer(v9211,v9221->name);
  princ_string("Class ");
  ident_c_producer(v9211,v9221->name);
  princ_string(";\n");
  { module * v7373 = v9221->part_of;
    { while (((boolean_I_any(_oid_(v7373->made_of)) != CTRUE) && 
          (v7373 != claire.it)))
      { princ_string("extern NameSpace ");
        ident_c_producer(v9211,v7373->name);
        princ_string(";\n");
        v7373= v7373->part_of;
        } 
      } 
    } 
  } 

void  declare_c_producer(Generate_c_producer *v9211,property *v9226)
{ GC_BIND;
  breakline_void();
  { expression_thing(v9226,Core.nil->value);
    princ_string(" = ");
    princ_string(((INHERIT(v9226->isa,Kernel._operation)) ?
      "operation" :
      "property" ));
    princ_string("::make(");
    print_any(GC_OID(_string_(string_I_symbol(v9226->name))));
    princ_string(",");
    if ((v9226->open != 1) || 
        (v9226->dispatcher > 0))
     { expression_integer(v9226->open,_oid_(Kernel.emptySet));
      princ_string(",");
      } 
    expression_thing(v9226->name->module_I,Core.nil->value);
    if (INHERIT(v9226->isa,Kernel._operation))
     { princ_string(",");
      princ_integer(CLREAD(operation,v9226,precedence));
      princ_string("");
      } 
    else if (v9226->dispatcher > 0)
     { princ_string(",");
      (*Generate.expression)(_oid_(v9226->domain),
        Core.nil->value);
      princ_string(",");
      princ_integer(v9226->dispatcher);
      princ_string("");
      } 
    princ_string(");");
    } 
  GC_UNBIND;} 

void  start_module_interface_c_producer(Generate_c_producer *v9211,module *v9396)
{ GC_BIND;
  { char * v11804 = GC_STRING(append_string(GC_STRING(Optimize.compiler->headers_dir),GC_STRING(append_string(GC_STRING(append_string(GC_STRING(string_v(Reader._starfs_star->value)),GC_STRING(string_I_symbol(v9396->name)))),".h"))));
    (Optimize.OPT->cinterface = fopen_string(v11804,"w"));
    use_as_output_port(Optimize.OPT->cinterface);
    princ_string("// interface defination for module ");
    print_any(_oid_(v9396));
    princ_string(", ");
    princ_string(date_I_integer(1));
    princ_string("");
    princ_string("#ifndef CLAIREH_");
    ident_thing(v9396);
    princ_string("\n#define CLAIREH_");
    ident_thing(v9396);
    princ_string("\n");
    { OID gc_local;
      ITERATE(v9232);
      bag *v9232_support;
      v9232_support = GC_OBJECT(list,Optimize.compiler->headers);
      for (START(v9232_support); NEXT(v9232);)
      { princ_string("#include \"");
        princ_string(string_v(v9232));
        princ_string(".h\"\n");
        } 
      } 
    use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
    } 
  GC_UNBIND;} 

void  end_module_interface_c_producer(Generate_c_producer *v9211,module *v9396)
{ princ_string("\n#endif\n");
  } 

void  generate_end_file_c_producer(Generate_c_producer *v9218,module *v9221)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  close_block_void();
  fclose_port(Optimize.OPT->outfile);
  { OID gc_local;
    ITERATE(v9211);
    bag *v9211_support;
    v9211_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v9211_support); NEXT(v9211);)
    { GC_LOOP;
      if (INHERIT(OWNER(v9211),Kernel._class))
       { ClairePort * v9226 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(c_string_c_producer2(v9218,OBJECT(symbol,(*Kernel.name)(v9211)))))),GC_STRING(v9218->extension)),"a"));
        use_as_output_port(v9226);
        close_block_void();
        fclose_port(v9226);
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_classes_c_producer(Generate_c_producer *v9218,char *v9233,module *v9221)
{ princ_string("\n\n");
  princ_string(v9233);
  princ_string("Class ");
  princ_string(v9233);
  princ_string(";\n\n");
  { module * v7372 = v9221;
    module * v7373 = v7372->part_of;
    { while (((boolean_I_any(_oid_(v7373->made_of)) != CTRUE) && 
          ((v7373 != claire.it) && 
            ((*(v7373->parts))[1] == _oid_(v7372)))))
      { princ_string("NameSpace ");
        (*Language.ident)(Generate.PRODUCER->value,
          _oid_(v7373->name));
        princ_string(";\n");
        v7373= v7373->part_of;
        v7372= v7373;
        } 
      } 
    } 
  } 

void  generate_start_file_c_producer(Generate_c_producer *v9211,module *v9221)
{ GC_BIND;
  tformat_string("++++ Creating the file ~A.cpp \n",2,list::alloc(1,GC_OID(_string_(c_string_c_producer2(v9211,v9221->name)))));
  start_file_string(GC_STRING(string_I_symbol(v9221->name)),v9221);
  (Optimize.OPT->level = 0);
  princ_string("/* class file for module ");
  print_any(_oid_(v9221));
  princ_string(" */");
  breakline_void();
  breakline_void();
  princ_string("public class ");
  ident_c_producer(v9211,v9221->name);
  princ_string(" extends NameSpace");
  new_block_void();
  GC_UNBIND;} 

void  generate_meta_load_c_producer(Generate_c_producer *v9211,module *v9221)
{ princ_string("void ");
  ident_c_producer(v9211,v9221->name);
  princ_string("Class::metaLoad() ");
  new_block_void();
  breakline_void();
  { princ_string("GC_BIND;");
    breakline_void();
    princ_string("ClEnv->module_I = it;\n");
    } 
  } 

OID  start_file_string(char *v9233,module *v9221)
{ GC_BIND;
  use_as_output_port(Optimize.OPT->outfile);
  princ_string("/***** CLAIRE Compilation of file ");
  princ_string(v9233);
  princ_string(".cl \n         [version ");
  (*Kernel.princ)(GC_OID(release_void()));
  princ_string(" / safety ");
  print_any(Optimize.compiler->safety);
  princ_string("] ");
  princ_string(substring_string(GC_STRING(date_I_integer(1)),1,24));
  princ_string(" *****/\n\n");
  princ_string("#include <claire.h>\n");
  princ_string("#include <Kernel.h>\n");
  { OID gc_local;
    ITERATE(v9232);
    bag *v9232_support;
    v9232_support = GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(v9221))));
    for (START(v9232_support); NEXT(v9232);)
    { GC_LOOP;
      { { OID gc_local;
          ITERATE(v9238);
          bag *v9238_support;
          v9238_support = GC_OBJECT(list,OBJECT(module,v9232)->uses);
          for (START(v9238_support); NEXT(v9238);)
          if (Kernel._string == OWNER(v9238))
           { princ_string("#include <");
            (*Kernel.princ)(v9238);
            princ_string(".h>\n");
            } 
          } 
        if (OBJECT(module,v9232)->made_of->length != 0)
         { princ_string("#include <");
          ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
          princ_string(".h>\n");
          } 
        } 
      GC_UNLOOP;} 
    } 
  if (boolean_I_any(Optimize.OPT->cfile) == CTRUE)
   { princ_string("#include <");
    (*Kernel.princ)(GC_OID(Optimize.OPT->cfile));
    princ_string(".h>\n");
    } 
  { OID Result = 0;
    Result = ClAlloc->import(Kernel._port,(int *) use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
    GC_UNBIND; return (Result);} 
  } 

void  define_variable_c_producer2(Generate_c_producer *v9211,ClaireClass *v9231,char *v9236)
{ interface_I_class(v9231);
  princ_string(v9236);
  princ_string(" ");
  if ((v9231 == Kernel._integer) || 
      (v9231 == Kernel._any))
   princ_string("= 0");
  else if (v9231 == Kernel._float)
   princ_string("=0.0");
  princ_string(";");
  } 

void  generate_profile_c_producer(Generate_c_producer *v9211,OID v9221)
{ if (Kernel._method == OWNER(v9221))
   get_dependents_method(OBJECT(method,v9221));
  { princ_string("   PRcount *PR_x = PRstart(PRget_property(");
    expression_thing(((Kernel._method == OWNER(v9221)) ?
      OBJECT(restriction,v9221)->selector :
      Kernel.fastcall ),Core.nil->value);
    princ_string("));");
    breakline_void();
    princ_string("");
    } 
  } 

void  generate_interface_c_producer(Generate_c_producer *v9211,module *v9396)
{ GC_RESERVE(8);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v9232);
    bag *v9232_support;
    v9232_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v9232_support); NEXT(v9232);)
    if (INHERIT(OWNER(v9232),Kernel._class))
     { princ_string("\nclass ");
      class_princ_c_producer(v9211,OBJECT(ClaireClass,v9232));
      princ_string(";");
      } 
    } 
  { OID gc_local;
    ITERATE(v9232);
    bag *v9232_support;
    v9232_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v9232_support); NEXT(v9232);)
    { GC_LOOP;
      if (INHERIT(OWNER(v9232),Kernel._class))
       { princ_string("\n\nclass ");
        class_princ_c_producer(v9211,OBJECT(ClaireClass,v9232));
        princ_string(": public ");
        class_princ_c_producer(v9211,OBJECT(ClaireClass,v9232)->superclass);
        new_block_void();
        breakline_void();
        princ_string("public:");
        { OID gc_local;
          ITERATE(v9235);
          bag *v9235_support;
          v9235_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(v9232)));
          for (START(v9235_support); NEXT(v9235);)
          { ClaireBoolean * g0060I;
            { OID  v11930;
              { OID gc_local;
                ITERATE(v7559);
                v11930= Kernel.cfalse;
                for (START(OBJECT(ClaireClass,v9232)->superclass->slots); NEXT(v7559);)
                if (_I_equal_any(_oid_(OBJECT(restriction,v7559)->selector),_oid_(OBJECT(restriction,v9235)->selector)) != CTRUE)
                 { v11930 = Kernel.ctrue;
                  break;} 
                } 
              g0060I = not_any(v11930);
              } 
            
            if (g0060I == CTRUE) { breakline_void();
                princ_string("   ");
                (*Generate.interface_I)(Generate.PRODUCER->value,
                  _oid_(psort_any(_oid_(OBJECT(restriction,v9235)->range))));
                ident_symbol(OBJECT(restriction,v9235)->selector->name);
                princ_string(";");
                } 
              } 
          } 
        (*Generate.methods_interface)(Generate.PRODUCER->value,
          v9232);
        close_block_void();
        princ_string(";");
        } 
      GC_UNLOOP;} 
    } 
  { OID gc_local;
    ITERATE(v9222);
    bag *v9222_support;
    v9222_support = GC_OBJECT(list,Optimize.OPT->functions);
    for (START(v9222_support); NEXT(v9222);)
    { GC_LOOP;
      { OID  v5193 = GC_OID((*Kernel.nth)(v9222,
          1));
        OID  v7019 = GC_OID((*Kernel.nth)(v9222,
          2));
        OID  v9233 = GC_OID((*Kernel.nth)(v9222,
          3));
        princ_string("\nextern ");
        (*Generate.interface_I)(Generate.PRODUCER->value,
          v9233);
        princ_string(" ");
        (*Kernel.c_princ)(v5193);
        princ_string("(");
        typed_args_list_list(OBJECT(list,v7019));
        princ_string(");");
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  global_var_def_I_c_producer(Generate_c_producer *v9211,module *v9396,Let *v9232)
{ GC_BIND;
  { global_variable * v5789 = OBJECT(global_variable,get_symbol(OBJECT(symbol,(*(OBJECT(bag,(*Core.args)(GC_OID(v9232->value)))))[1])));
    ClaireClass * v9233 = getRange_global_variable(v5789);
    OID  v6854 = GC_OID((*(OBJECT(Do,v9232->arg)->args))[2]);
    OID  v6409;
    { if (INHERIT(OWNER(v6854),Language._Update))
       v6409 = OBJECT(Update,v6854)->value;
      else if ((INHERIT(OWNER(v6854),Language._Call)) || 
          (INHERIT(OWNER(v6854),Language._Call_method)))
       v6409 = (*(OBJECT(bag,(*Core.args)(v6854))))[5];
      else { OID  v8406;close_exception(((general_error *) (*Core._general_error)(_string_("Design bug: make ~S a public global var !"),
            _oid_(list::alloc(1,_oid_(v5789))))));
          
          v6409=_void_(v8406);} 
        GC_OID(v6409);} 
    ClaireBoolean * v9210 = c_func_any(v6409);
    Variable * v13192 = GC_OBJECT(Variable,build_Variable_string("V_C",_oid_(Kernel._any)));
    if (nativeVar_ask_global_variable(v5789) != CTRUE)
     statement_any(_oid_(v9232),Core.nil->value,Core.nil->value);
    else { if (v9210 != CTRUE)
         { new_block_void();
          princ_string("OID ");
          ident_c_producer3(v9211,v13192);
          princ_string(";");
          breakline_void();
          statement_any(v6409,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
            _oid_(v13192))),Core.nil->value);
          princ_string("");
          } 
        ident_c_producer(v9211,v9396->name);
        princ_string(".");
        ident_c_producer(v9211,v5789->name);
        princ_string(" = ");
        if (v9210 == CTRUE)
         to_c_c_producer1(v9211,v6409,v9233,Core.nil->value);
        else to_c_c_producer1(v9211,_oid_(v13192),v9233,Core.nil->value);
          princ_string(";");
        if (v9210 != CTRUE)
         close_block_void();
        breakline_void();
        princ_string("");
        } 
      } 
  GC_UNBIND;} 

void  gc_introduction_c_producer(Generate_c_producer *v9211,OID v5189)
{ GC_BIND;
  if (Optimize.OPT->protection == CTRUE)
   { OID  v9237 = GC_OID(gc_usage_any(v5189,CFALSE));
    if ((Optimize.OPT->loop_gc == CTRUE) && 
        (INHERIT(OWNER(v9237),Kernel._integer)))
     { if ((OBJECT(ClaireBoolean,(*Kernel._inf)(v9237,
        100))) == CTRUE)
       { (Optimize.OPT->loop_index = 0);
        princ_string("GC_RESERVE(1);  // HOHO v3.0.55 optim !");
        } 
      else { princ_string("GC_RESERVE(");
          princ_integer((Optimize.OPT->loop_index+1));
          princ_string(");  // v3.0.55 optim !");
          } 
        } 
    else princ_string("GC_BIND;");
      breakline_void();
    } 
  GC_UNBIND;} 

OID  gc_usage_any(OID v9396,ClaireBoolean *v7180)
{ { OID Result = 0;
    if (INHERIT(OWNER(v9396),Language._Instruction))
     { if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Construct))
       Result = gc_usage_star_list(OBJECT(Construct,v9396)->args,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Definition))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Call_method))
       Result = gc_usage_star_list(OBJECT(Call_method,v9396)->args,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Call_slot))
       Result = gc_usage_any(OBJECT(Call_slot,v9396)->arg,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Call_table))
       Result = gc_usage_any(OBJECT(Call_table,v9396)->arg,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Call_array))
       Result = gc_usage_any(OBJECT(Call_array,v9396)->arg,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Optimize._to_C))
       Result = gc_usage_any(OBJECT(Compile_to_C,v9396)->arg,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Optimize._to_CL))
       Result = gc_usage_any(OBJECT(Compile_to_CL,v9396)->arg,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Optimize._to_protect))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Update))
       Result = gc_usage_any(OBJECT(Update,v9396)->value,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Call))
       Result = gc_usage_star_list(OBJECT(Call,v9396)->args,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._If))
       Result = gc_or_any(gc_usage_any(OBJECT(If,v9396)->test,v7180),gc_or_any(gc_usage_any(OBJECT(If,v9396)->arg,v7180),gc_usage_any(OBJECT(If,v9396)->other,v7180)));
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Do))
       Result = gc_usage_star_list(OBJECT(Do,v9396)->args,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Iteration))
       Result = gc_or_any(gc_usage_any(OBJECT(Iteration,v9396)->set_arg,v7180),gc_usage_any(OBJECT(Iteration,v9396)->arg,CTRUE));
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Let))
       { OID  v9232 = OBJECT(Let,v9396)->value;
        { OID  v13852;
          if ((v7180 == CTRUE) && 
              (INHERIT(OWNER(v9232),Optimize._to_protect)))
           v13852 = OBJECT(Instruction_with_var,v9396)->var->index;
          else v13852 = Kernel.cfalse;
            Result = gc_or_any(v13852,gc_or_any(gc_usage_any(v9232,v7180),gc_usage_any(OBJECT(Let,v9396)->arg,v7180)));
          } 
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Assign))
       { OID  v9232 = OBJECT(Assign,v9396)->arg;
        { OID  v14813;
          if ((v7180 == CTRUE) && 
              (inner2outer_ask_any(v9232) == CTRUE))
           v14813 = (*Kernel.index)(OBJECT(Assign,v9396)->var);
          else v14813 = Kernel.cfalse;
            Result = gc_or_any(v14813,gc_usage_any(v9232,v7180));
          } 
        } 
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Optimize._to_protect))
       Result = Kernel.ctrue;
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Gassign))
       Result = gc_usage_any(OBJECT(Gassign,v9396)->arg,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._And))
       Result = gc_usage_star_list(OBJECT(And,v9396)->args,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Or))
       Result = gc_usage_star_list(OBJECT(Or,v9396)->args,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Cast))
       Result = gc_usage_any(OBJECT(Cast,v9396)->arg,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Super))
       Result = gc_usage_star_list(OBJECT(Super,v9396)->args,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Case))
       Result = gc_usage_star_list(OBJECT(Case,v9396)->args,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._While))
       Result = gc_or_any(gc_usage_any(OBJECT(While,v9396)->arg,CTRUE),gc_usage_any(OBJECT(While,v9396)->test,v7180));
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Return))
       Result = gc_usage_any(OBJECT(Return,v9396)->arg,v7180);
      else if (INHERIT(OBJECT(ClaireObject,v9396)->isa,Language._Handle))
       Result = gc_or_any(gc_usage_any(OBJECT(ClaireHandle,v9396)->arg,v7180),gc_usage_any(OBJECT(ClaireHandle,v9396)->other,v7180));
      else Result = Kernel.cfalse;
        } 
    else Result = Kernel.cfalse;
      return (Result);} 
  } 

OID  gc_or_any(OID v9232,OID v9235)
{ { OID Result = 0;
    if (v9232 == Kernel.cfalse)
     Result = v9235;
    else if (v9232 == Kernel.ctrue)
     { if (v9235 == Kernel.cfalse)
       Result = v9232;
      else Result = v9235;
        } 
    else if (INHERIT(OWNER(v9235),Kernel._integer))
     { if (equal(v9232,v9235) == CTRUE)
       Result = v9235;
      else Result = 1000;
        } 
    else Result = v9232;
      return (Result);} 
  } 

OID  gc_usage_star_list(list *v9222,ClaireBoolean *v7180)
{ { OID Result = 0;
    { OID  v9232 = Kernel.cfalse;
      { ITERATE(v9235);
        for (START(v9222); NEXT(v9235);)
        v9232= gc_or_any(v9232,gc_usage_any(v9235,v7180));
        } 
      Result = v9232;
      } 
    return (Result);} 
  } 

void  debug_intro_c_producer(Generate_c_producer *v9211,lambda *v9396,method *v9232)
{ GC_BIND;
  { module * v9221;
    { ClaireObject *V_CC ;
      if (Kernel._method == v9232->isa)
       V_CC = v9232->module_I;
      else V_CC = CFALSE;
        v9221= (module *) V_CC;} 
    int  v9223 = 1;
    princ_string("DB_BIND(");
    ident_thing(v9221);
    princ_string(",");
    expression_thing(v9232->selector,_oid_(Kernel.emptySet));
    princ_string(",");
    princ_integer(v9396->vars->length);
    princ_string(",{");
    if ((v9396->vars->length == 1) && 
        ((*Kernel.range)((*(v9396->vars))[1]) == _oid_(Kernel._void)))
     princ_string("PUSH(_oid_(ClEnv));");
    else { OID gc_local;
        ITERATE(v9236);
        for (START(v9396->vars); NEXT(v9236);)
        { princ_string("PUSH(");
          { OID  v9233 = (*(v9232->srange))[v9223];
            if (((v9233 == _oid_(Kernel._any)) && 
                  ((*Kernel.range)(v9236) != _oid_(Kernel._float))) || 
                (v9233 == _oid_(Kernel._integer)))
             (*Generate.expression)(v9236,
              Kernel.cfalse);
            else to_cl_c_producer(v9211,v9236,(((*Kernel.range)(v9236) == _oid_(Kernel._float)) ?
                Kernel._float :
                OBJECT(ClaireClass,v9233) ),Kernel.cfalse);
              } 
          princ_string(");");
          ++v9223;
          } 
        } 
      princ_string("});");
    breakline_void();
    princ_string("");
    } 
  GC_UNBIND;} 

char * protect_result_c_producer(Generate_c_producer *v9211,ClaireClass *v9233,ClaireBoolean *v1532,OID v9232)
{ GC_BIND;
  if (Optimize.compiler->safety > 5)
   { (Optimize.OPT->protection = CFALSE);
    v1532= CFALSE;
    (Optimize.OPT->loop_gc = CFALSE);
    } 
  { char *Result ;
    { char * v7558 = ((v9233 != Kernel._void) ?
        ((v1532 == CTRUE) ?
          "GC_UNBIND; return " :
          "return " ) :
        ((v1532 == CTRUE) ?
          "GC_UNBIND;" :
          "" ) );
      ClaireObject * v9221;
      if (need_debug_ask_any(v9232) == CTRUE)
       v9221 = OBJECT(method,v9232)->module_I;
      else v9221 = CFALSE;
        if (INHERIT(v9221->isa,Kernel._module))
       { print_in_string_void();
        princ_string("DB_UNBIND(");
        ident_thing(((thing *) v9221));
        princ_string(",");
        (*Generate.expression)(GC_OID((*Kernel.selector)(v9232)),
          _oid_(Kernel.emptySet));
        princ_string(",");
        if (v9233 == Kernel._void)
         princ_string("CNULL");
        else if ((v9233 == Kernel._any) || 
            (v9233 == Kernel._integer))
         princ_string("Result");
        else to_cl_c_producer(v9211,GC_OID(_oid_(build_Variable_string("Result",_oid_(v9233)))),v9233,Core.nil->value);
          princ_string(");");
        breakline_void();
        princ_string("  ");
        princ_string(v7558);
        princ_string("");
        Result = end_of_print_void();
        } 
      else Result = (((Optimize.OPT->profile_ask == CTRUE) && 
          ((Kernel._method == OWNER(v9232)) || 
              (v9232 == CNULL))) ?
        append_string("PRend(PR_x);",v7558) :
        v7558 );
      } 
    GC_UNBIND; return (Result);} 
  } 

void  generate_function_start_c_producer(Generate_c_producer *v9211,lambda *v9396,ClaireClass *v9233,OID v9221,char *v4591)
{ GC_BIND;
  { OID  v11365;
    { if (v9396->vars->length != 0)
       v11365 = (*Kernel.range)(GC_OID((*(v9396->vars))[1]));
      else v11365 = _oid_(Kernel._any);
        GC_OID(v11365);} 
    ClaireFunction * v5193 = make_function_string(v4591);
    list * v7411 = GC_OBJECT(list,(((v9396->vars->length == 1) && 
        ((v11365 == _oid_(Kernel._environment)) || 
            (v11365 == _oid_(Kernel._void)))) ?
      Kernel.nil :
      v9396->vars ));
    update_function_entry_c_producer(v9211,v5193,v7411,v9233);
    use_as_output_port(Optimize.OPT->outfile);
    if (Kernel._method == OWNER(v9221))
     { if ((OBJECT(restriction,v9221)->range == Kernel._float) || 
          (OBJECT(restriction,v9221)->domain->memq(_oid_(Kernel._float)) == CTRUE))
       generate_float_function_c_producer(v9211,OBJECT(method,v9221),GC_STRING(string_I_function(v5193)));
      else if (INHERIT(OBJECT(restriction,v9221)->range->isa,Kernel._tuple))
       generate_tuple_function_c_producer(v9211,OBJECT(method,v9221),GC_STRING(string_I_function(v5193)));
      } 
    generate_regular_function_c_producer(v9211,
      v9396,
      v5193,
      v9233,
      v9221,
      v7411);
    } 
  GC_UNBIND;} 

void  generate_regular_function_c_producer(Generate_c_producer *v9211,lambda *v9396,ClaireFunction *v5193,ClaireClass *v9233,OID v9221,list *v7411)
{ GC_BIND;
  if (Optimize.compiler->naming != 2)
   { princ_string("\n/* The c++ function for: ");
    if (Kernel._method == OWNER(v9221))
     { print_any(_oid_(OBJECT(restriction,v9221)->selector));
      princ_string("(");
      ppvariable_list(GC_OBJECT(list,v9396->vars));
      princ_string(") [");
      if (Optimize.compiler->naming == 1)
       bitvectorSum_integer(status_I_restriction(OBJECT(restriction,v9221)));
      princ_string("]");
      } 
    else princ_string(string_I_function(v5193));
      princ_string(" */\n");
    } 
  { interface_I_c_producer(v9211,v9233);
    princ_string(" ");
    c_princ_function(v5193);
    princ_string("(");
    typed_args_list_list(v7411);
    princ_string(")\n");
    } 
  GC_UNBIND;} 

void  generate_float_function_c_producer(Generate_c_producer *v9211,method *v9221,char *v4591)
{ GC_BIND;
  { list * v7392 = (((v9221->domain->length == 1) && 
        (domain_I_restriction(v9221) == Kernel._void)) ?
      Kernel.nil :
      v9221->domain );
    int  v9223 = v7392->length;
    list * v7411;
    { { bag *v_list; OID v_val;
        OID v9232,CLcount;
        v_list = v7392;
         v7411 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v9232 = (*(v_list))[CLcount];
          { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (v2072->pname = gensym_void());
            { Variable * v6784 = v2072; 
              ClaireType * v6785;
              if (v9232 == _oid_(Kernel._float))
               v6785 = Kernel._any;
              else v6785 = OBJECT(ClaireType,v9232);
                (v6784->range = v6785);} 
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
            v_val = _oid_(v2072);
            } 
          
          (*((list *) v7411))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v7411);} 
    char * v11344 = GC_STRING(append_string(v4591,"_"));
    ClaireFunction * v5193 = make_function_string(v11344);
    lambda * v13764 = GC_OBJECT(lambda,lambda_I_list(v7411,Core.nil->value));
    ClaireClass * v9233 = ((v9221->range == Kernel._float) ?
      Kernel._any :
      psort_any(_oid_(v9221->range)) );
    generate_regular_function_c_producer(v9211,
      v13764,
      v5193,
      v9233,
      _oid_(v9221),
      v7411);
    GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v5193),
      _oid_(v7411),
      _oid_(v9233))));
    new_block_void();
    if (v9233 != Kernel._void)
     princ_string("return ");
    if (v9221->range == Kernel._float)
     princ_string("_float_(");
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v9221))));
    princ_string("(");
    { int  v9217 = 1;
      int  v6783 = v9223;
      { OID gc_local;
        while ((v9217 <= v6783))
        { if (v9217 != 1)
           princ_string(",");
          if ((*(v9221->domain))[v9217] == _oid_(Kernel._float))
           { princ_string("float_v(");
            expression_Variable(OBJECT(Variable,(*(v7411))[v9217]),Core.nil->value);
            princ_string(")");
            } 
          else expression_Variable(OBJECT(Variable,(*(v7411))[v9217]),Core.nil->value);
            ++v9217;
          } 
        } 
      } 
    princ_string(")");
    if (v9221->range == Kernel._float)
     princ_string(")");
    princ_string(";");
    close_block_void();
    princ_string("\n");
    } 
  GC_UNBIND;} 

void  at_c_producer(Generate_c_producer *v9211)
{ princ_string("->");
  } 

void  generate_tuple_function_c_producer(Generate_c_producer *v9211,method *v9221,char *v4591)
{ GC_BIND;
  { list * v7392 = (((v9221->domain->length == 1) && 
        (domain_I_restriction(v9221) == Kernel._void)) ?
      Kernel.nil :
      v9221->domain );
    int  v9223 = v7392->length;
    list * v7411;
    { { bag *v_list; OID v_val;
        OID v9232,CLcount;
        v_list = v7392;
         v7411 = v_list->clone();
        for (CLcount= 1; CLcount <= v_list->length; CLcount++)
        { v9232 = (*(v_list))[CLcount];
          { Variable * v2072 = ((Variable *) GC_OBJECT(Variable,new_object_class(Language._Variable)));
            (v2072->pname = gensym_void());
            (v2072->range = OBJECT(ClaireType,v9232));
            add_I_property(Kernel.instances,Language._Variable,11,_oid_(v2072));
            v_val = _oid_(v2072);
            } 
          
          (*((list *) v7411))[CLcount] = v_val;} 
        } 
      GC_OBJECT(list,v7411);} 
    char * v11344 = GC_STRING(append_string(v4591,"_"));
    ClaireFunction * v5193 = make_function_string(v11344);
    lambda * v13764 = GC_OBJECT(lambda,lambda_I_list(v7411,Core.nil->value));
    ClaireClass * v9233 = Kernel._tuple;
    generate_regular_function_c_producer(v9211,
      v13764,
      v5193,
      v9233,
      _oid_(v9221),
      v7411);
    GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v5193),
      _oid_(v7411),
      _oid_(v9233))));
    new_block_void();
    if (v9233 != Kernel._void)
     princ_string("return ");
    c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v9221))));
    princ_string("(");
    { int  v9217 = 1;
      int  v6808 = v9223;
      { OID gc_local;
        while ((v9217 <= v6808))
        { if (v9217 != 1)
           princ_string(",");
          expression_Variable(OBJECT(Variable,(*(v7411))[v9217]),Core.nil->value);
          ++v9217;
          } 
        } 
      } 
    princ_string(")");
    princ_string("->copyIfNeeded()");
    princ_string(";");
    close_block_void();
    princ_string("\n");
    } 
  GC_UNBIND;} 

OID  create_function_entry_c_producer(Generate_c_producer *v9211,lambda *v7390,char *v5193,OID v9221)
{ return (Core.nil->value);} 

OID  update_function_entry_c_producer(Generate_c_producer *v9211,ClaireFunction *v5193,list *v7411,ClaireClass *v9233)
{ GC_BIND;
  GC_OBJECT(list,Optimize.OPT->functions)->addFast(_oid_(list::alloc(3,_oid_(v5193),
    _oid_(v7411),
    _oid_(v9233))));
  { OID Result = 0;
    Result = Kernel.cfalse;
    GC_UNBIND; return (Result);} 
  } 

char * c_interface_class1_Generate(ClaireClass *v9396)
{ { char *Result ;
    { int  v9223 = index_list(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces,_oid_(v9396));
      Result = ((v9223 == 0) ?
        "OID *" :
        string_v((*(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces))[(v9223+1)]) );
      } 
    return (Result);} 
  } 

void  c_interface_class2_Generate(ClaireClass *v9396,char *v9233)
{ GC_BIND;
  { int  v9223 = index_list(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces,_oid_(v9396));
    if (v9223 == 0)
     (OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces = GC_OBJECT(list,GC_OBJECT(list,OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces)->addFast(_oid_(v9396)))->addFast(_string_(v9233)));
    else ((*(OBJECT(Generate_producer,Generate.PRODUCER->value)->interfaces))[(v9223+1)]=_string_(v9233));
      } 
  GC_UNBIND;} 

void  c_interface_method_Generate(method *v9396)
{ c_princ_string(string_v((*Optimize.function_name)(_oid_(v9396->selector),
    _oid_(v9396->domain),
    _oid_(v9396->functional))));
  } 

void  interface_I_c_producer(Generate_c_producer *v9211,ClaireClass *v9396)
{ if (v9396 == Kernel._void)
   princ_string("void ");
  else if (v9396 == Kernel._integer)
   princ_string("int ");
  else if ((v9396 == Kernel._function) || 
      ((v9396 == Kernel._char) || 
        (v9396 == Kernel._boolean)))
   { ident_c_producer(v9211,v9396->name);
    princ_string(" *");
    } 
  else if ((INHERIT(v9396,Kernel._cl_import)) || 
      ((v9396 == Kernel._string) || 
        (v9396 == Kernel._array)))
   princ_string(string_v((*Optimize.c_interface)(_oid_(v9396))));
  else if (INHERIT(v9396,Kernel._object))
   { class_princ_c_producer(v9211,v9396);
    princ_string(" *");
    } 
  else if (INHERIT(v9396,Kernel._bag))
   { ident_c_producer(v9211,v9396->name);
    princ_string(" *");
    } 
  else if (v9396 == Kernel._float)
   princ_string("double ");
  else princ_string("OID ");
    } 

void  to_cl_c_producer(Generate_c_producer *v9211,OID v9232,ClaireClass *v9233,OID v7180)
{ if (v9233 == Kernel._void)
   { princ_string("_void_(");
    (*Generate.expression)(v9232,
      v7180);
    princ_string(")");
    } 
  else if (INHERIT(v9233,Kernel._object))
   { if (v9232 == Kernel.ctrue)
     princ_string("Kernel.ctrue");
    else if (v9232 == Kernel.cfalse)
     princ_string("Kernel.cfalse");
    else { princ_string("_oid_(");
        (*Generate.expression)(v9232,
          v7180);
        princ_string(")");
        } 
      } 
  else if (v9233 == Kernel._integer)
   { if (Optimize.compiler->safety > 1)
     (*Generate.expression)(v9232,
      v7180);
    else { princ_string("_integer_(");
        (*Generate.expression)(v9232,
          v7180);
        princ_string(")");
        } 
      } 
  else if (v9233 == Kernel._char)
   { princ_string("_oid_(");
    (*Generate.expression)(v9232,
      v7180);
    princ_string(")");
    } 
  else if (v9233 == Kernel._string)
   { princ_string("_string_(");
    (*Generate.expression)(v9232,
      v7180);
    princ_string(")");
    } 
  else if (v9233 == Kernel._array)
   { princ_string("_array_(");
    (*Generate.expression)(v9232,
      v7180);
    princ_string(")");
    } 
  else if (v9233 == Kernel._float)
   { princ_string("_float_(");
    (*Generate.expression)(v9232,
      v7180);
    princ_string(")");
    } 
  else if (INHERIT(v9233,Kernel._cl_import))
   { princ_string("ClAlloc->import(");
    expression_any(_oid_(v9233),_oid_(Kernel.emptySet));
    princ_string(",(int *) ");
    (*Generate.expression)(v9232,
      v7180);
    princ_string(")");
    } 
  else if (v9233 == Kernel._any)
   (*Generate.expression)(v9232,
    v7180);
  else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] to_cl for a ~S is not implemented"),
      _oid_(list::alloc(1,_oid_(v9233))))));
    } 

void  to_c_c_producer1(Generate_c_producer *v9211,OID v9232,ClaireClass *v9233,OID v7180)
{ if (v9233 == Kernel._integer)
   (*Generate.expression)(v9232,
    v7180);
  else if (v9232 == CNULL)
   princ_string("NULL");
  else if ((INHERIT(OWNER(v9232),Core._global_variable)) && 
      ((equal((*Kernel.range)(v9232),_oid_(Kernel.emptySet)) == CTRUE) && 
        (equal((*Kernel.value)(v9232),Core.nil->value) == CTRUE)))
   princ_string("Kernel.nil");
  else { to_c_c_producer2(v9211,v9233);
      (*Generate.expression)(v9232,
        v7180);
      princ_string(")");
      } 
    } 

void  to_c_c_producer2(Generate_c_producer *v9211,ClaireClass *v9233)
{ if (INHERIT(v9233,Kernel._object))
   { princ_string("OBJECT(");
    class_princ_class(v9233);
    princ_string(",");
    } 
  else if (v9233 == Kernel._float)
   princ_string("float_v(");
  else if (v9233 == Kernel._char)
   princ_string("char_v(");
  else if (v9233 == Kernel._string)
   princ_string("string_v(");
  else if (v9233 == Kernel._array)
   princ_string("array_v(");
  else if (INHERIT(v9233,Kernel._cl_import))
   { princ_string("EXPORT((");
    interface_I_class(v9233);
    princ_string("),");
    } 
  else close_exception(((general_error *) (*Core._general_error)(_string_("[internal] to_c for a ~S is not implemented"),
      _oid_(list::alloc(1,_oid_(v9233))))));
    } 

void  public_static_c_producer(Generate_c_producer *v9211)
{ ;} 

void  bool_exp_I_c_producer(Generate_c_producer *v9211,OID v9396,OID v7180)
{ if (INHERIT(OWNER(v9396),Optimize._to_CL))
   { princ_string("(");
    (*Optimize.bool_exp)(v9396,
      Kernel.ctrue,
      v7180);
    princ_string(" ? Kernel.ctrue : Kernel.cfalse)");
    } 
  else { princ_string("(");
      (*Optimize.bool_exp)(v9396,
        Kernel.ctrue,
        v7180);
      princ_string(" ? CTRUE : CFALSE)");
      } 
    } 

void  inherit_exp_c_producer(Generate_c_producer *v9211,OID v7000,OID v7002,OID v7180)
{ princ_string("INHERIT(");
  (*Generate.expression)(v7000,
    v7180);
  princ_string(",");
  (*Generate.expression)(v7002,
    v7180);
  princ_string(")");
  } 

void  bitvector_exp_c_producer(Generate_c_producer *v9211,OID v7000,OID v7002,OID v7180)
{ princ_string("BCONTAIN(");
  (*Generate.expression)(v7000,
    v7180);
  princ_string(",");
  (*Generate.expression)(v7002,
    v7180);
  princ_string(")");
  } 

void  equal_exp_c_producer(Generate_c_producer *v9211,OID v7000,ClaireBoolean *v11731,OID v7002,OID v13340)
{ if ((INHERIT(OWNER(v7000),Optimize._to_CL)) && 
      ((INHERIT(OWNER(v7002),Optimize._to_CL)) && 
        ((osort_any((*Language.set_arg)(v7000)) == osort_any((*Language.set_arg)(v7002))) && 
          ((identifiable_ask_any(GC_OID((*Kernel.arg)(v7000))) == CTRUE) || 
              ((identifiable_ask_any(GC_OID((*Kernel.arg)(v7002))) == CTRUE) || 
                (((*Language.set_arg)(v7000) == _oid_(Kernel._string)) || 
                  ((*Language.set_arg)(v7000) == _oid_(Kernel._float)))))))) 
  { equal_exp_c_producer(v9211,
      GC_OID((*Kernel.arg)(v7000)),
      v11731,
      GC_OID((*Kernel.arg)(v7002)),
      Kernel.ctrue);
     } 
  else{ if ((INHERIT(OWNER(v7000),Optimize._to_protect)) && 
        ((INHERIT(owner_any((*Kernel.arg)(v7000)),Optimize._to_CL)) && 
          (((*Optimize.c_gc_ask)(GC_OID((*Kernel.arg)(GC_OID((*Kernel.arg)(v7000))))) != Kernel.ctrue) && 
            ((INHERIT(OWNER(v7002),Optimize._to_protect)) && 
              ((INHERIT(owner_any((*Kernel.arg)(v7002)),Optimize._to_CL)) && 
                ((*Optimize.c_gc_ask)(GC_OID((*Kernel.arg)(GC_OID((*Kernel.arg)(v7002))))) != Kernel.ctrue)))))) 
    { equal_exp_c_producer(v9211,
        GC_OID((*Kernel.arg)(v7000)),
        v11731,
        GC_OID((*Kernel.arg)(v7002)),
        v13340);
       } 
    else{ GC_BIND;
      { ClaireBoolean * g0072I;
        { ClaireBoolean *v_and;
          { v_and = (((*Optimize.c_sort)(v7000) == _oid_(Kernel._string)) ? CTRUE : CFALSE);
            if (v_and == CFALSE) g0072I =CFALSE; 
            else { v_and = (((*Optimize.c_sort)(v7002) == _oid_(Kernel._string)) ? CTRUE : CFALSE);
              if (v_and == CFALSE) g0072I =CFALSE; 
              else { { OID  v10875;
                  if (INHERIT(OWNER(v7002),Optimize._to_C))
                   v10875 = ((OBJECT(Compile_to_C,v7002)->arg == CNULL) ? Kernel.ctrue : Kernel.cfalse);
                  else v10875 = Kernel.cfalse;
                    v_and = not_any(v10875);
                  } 
                if (v_and == CFALSE) g0072I =CFALSE; 
                else g0072I = CTRUE;} 
              } 
            } 
          } 
        
        if (g0072I == CTRUE) { princ_string("(equal_string(");
            (*Generate.expression)(v7000,
              Core.nil->value);
            princ_string(",");
            (*Generate.expression)(v7002,
              Core.nil->value);
            princ_string(") ");
            sign_equal_boolean(v11731);
            princ_string(" CTRUE)");
            } 
          else if ((INHERIT(OWNER(v7000),Optimize._to_CL)) && 
            (((*Language.set_arg)(v7000) != _oid_(Kernel._integer)) && 
              (v7002 == CNULL)))
         { princ_string("(");
          (*Generate.expression)(GC_OID((*Kernel.arg)(v7000)),
            Core.nil->value);
          princ_string(" ");
          sign_equal_boolean(v11731);
          princ_string(" NULL)");
          } 
        else if ((char_exp_ask_c_producer2(v9211,v7000) == CTRUE) || 
            (char_exp_ask_c_producer2(v9211,v7002) == CTRUE))
         { princ_string("(");
          char_exp_c_producer2(v9211,v7000,Core.nil->value);
          princ_string(" ");
          sign_equal_boolean(v11731);
          princ_string(" ");
          char_exp_c_producer2(v9211,v7002,Core.nil->value);
          princ_string(")");
          } 
        else if ((boolean_I_any(v13340) == CTRUE) || 
            ((identifiable_ask_any(v7000) == CTRUE) || 
              ((identifiable_ask_any(v7002) == CTRUE) || 
                ((*Optimize.c_sort)(v7000) == _oid_(Kernel._float)))))
         { if (equal(_oid_(glb_class(stupid_t_any1(v7000),stupid_t_any1(v7002))),_oid_(Kernel.emptySet)) == CTRUE)
           { warn_void();
            tformat_string("~S = ~S will fail ! [263]",2,list::alloc(2,v7000,v7002));
            } 
          princ_string("(");
          bexpression_any(v7000,Core.nil->value);
          princ_string(" ");
          sign_equal_boolean(v11731);
          princ_string(" ");
          bexpression_any(v7002,Core.nil->value);
          princ_string(")");
          } 
        else { princ_string("(equal(");
            (*Generate.expression)(v7000,
              Core.nil->value);
            princ_string(",");
            (*Generate.expression)(v7002,
              Core.nil->value);
            princ_string(") ");
            sign_equal_boolean(v11731);
            princ_string(" CTRUE)");
            } 
          } 
      GC_UNBIND;} 
    } 
  } 

ClaireBoolean * char_exp_ask_c_producer2(Generate_c_producer *v9211,OID v9232)
{ { ClaireBoolean *Result ;
    if (INHERIT(OWNER(v9232),Kernel._char))
     Result = CTRUE;
    else if (INHERIT(OWNER(v9232),Language._Call_method))
     { method * v9221 = OBJECT(Call_method,v9232)->arg;
      Result = ((_oid_(v9221) == Generate._starnth_1_string_star->value) ? CTRUE : (((_oid_(v9221) == Generate._starnth_string_star->value) && 
          (2 <= Optimize.compiler->safety)) ? CTRUE : CFALSE));
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  char_exp_c_producer2(Generate_c_producer *v9211,OID v9232,OID v7180)
{ GC_BIND;
  if (INHERIT(OWNER(v9232),Kernel._char))
   { princ_string("'");
    if ((v9232 == _oid_(_char_('\"'))) || 
        ((v9232 == _oid_(_char_('\''))) || 
          ((v9232 == _oid_(_char_('\?'))) || 
            (v9232 == _oid_(_char_('\\'))))))
     princ_string("\\");
    princ_char(OBJECT(ClaireChar,v9232));
    princ_string("'");
    } 
  else if (INHERIT(OWNER(v9232),Language._Call_method))
   { method * v9221 = OBJECT(Call_method,v9232)->arg;
    if ((_oid_(v9221) == Generate._starnth_1_string_star->value) || 
        (_oid_(v9221) == Generate._starnth_string_star->value))
     { OID  v7000 = (*(OBJECT(Call_method,v9232)->args))[1];
      OID  v7002 = (*(OBJECT(Call_method,v9232)->args))[2];
      (*Generate.expression)(v7000,
        v7180);
      princ_string("[");
      (*Generate.expression)(v7002,
        v7180);
      princ_string(" - 1]");
      } 
    else { princ_string("((char) ");
        (*Generate.expression)(v9232,
          v7180);
        princ_string("->ascii)");
        } 
      } 
  else { princ_string("((char) ");
      (*Generate.expression)(v9232,
        v7180);
      princ_string("->ascii)");
      } 
    GC_UNBIND;} 

void  c_member_c_producer(Generate_c_producer *v9211,OID v9396,ClaireClass *v9233,property *v9232,OID v7180)
{ if (INHERIT(stupid_t_any1(v9396),v9233))
   { (*Generate.expression)(v9396,
      v7180);
    princ_string("->");
    ident_symbol(v9232->name);
    princ_string("");
    } 
  else { princ_string("CLREAD(");
      class_princ_class(v9233);
      princ_string(",");
      (*Generate.expression)(v9396,
        v7180);
      princ_string(",");
      ident_symbol(v9232->name);
      princ_string(")");
      } 
    } 

void  addFast_c_producer(Generate_c_producer *v9211)
{ princ_string("->addFast");
  } 

void  cast_I_c_producer(Generate_c_producer *v9211,Compile_C_cast *v9396,OID v7180)
{ GC_BIND;
  princ_string("((");
  class_princ_class(v9396->set_arg);
  princ_string(" *) ");
  (*Generate.expression)(v9396->arg,
    v7180);
  princ_string(")");
  GC_UNBIND;} 

void  gc_protection_exp_c_producer(Generate_c_producer *v9211,Variable *v9236,ClaireBoolean *v3883,OID v9234,OID v7180)
{ (v9211->stat = (v9211->stat+1));
  if ((osort_any(_oid_(v9236->range)) == Kernel._float) || 
      (osort_any(_oid_(v9236->range)) == Kernel._integer))
   { princ_string("(");
    ident_c_producer3(v9211,v9236);
    princ_string("=");
    if (v3883 == CTRUE)
     (*Generate.expression)(v9234,
      v7180);
    else c_princ_string(string_v(v9234));
      princ_string(")");
    } 
  else { princ_string("GC__");
      princ_string(((osort_any(_oid_(v9236->range)) == Kernel._any) ?
        "OID" :
        ((osort_any(_oid_(v9236->range)) == Kernel._string) ?
          "STRING" :
          "ANY" ) ));
      princ_string("(");
      ident_c_producer3(v9211,v9236);
      if (v9234 != _oid_(v9236))
       { princ_string(" = ");
        if (v3883 == CTRUE)
         (*Generate.expression)(v9234,
          v7180);
        else c_princ_string(string_v(v9234));
          } 
      princ_string(", ");
      princ_integer(((Optimize.OPT->loop_index == 0) ?
        1 :
        (v9236->index+1) ));
      princ_string(")");
      } 
    } 

void  bag_expression_c_producer(Generate_c_producer *v7133,ClaireClass *v9211,bag *v9222,ClaireType *v9231,OID v7180)
{ GC_BIND;
  if (v9222->length == 0)
   { print_any(_oid_(v9211));
    princ_string("::empty(");
    if (v9231 != Kernel._void)
     { (*Generate.expression)(GC_OID((*Optimize.c_code)(_oid_(v9231),
          _oid_(Kernel._object))),
        v7180);
      } 
    princ_string(")");
    } 
  else { print_any(_oid_(v9211));
      princ_string("::alloc");
      if ((v9211 == Kernel._tuple) && 
          (Optimize.OPT->alloc_stack == CTRUE))
       princ_string("Stack");
      princ_string("(");
      if (v9231 != Kernel._void)
       { (*Generate.expression)(GC_OID((*Optimize.c_code)(_oid_(v9231),
            _oid_(Kernel._object))),
          v7180);
        princ_string(",");
        } 
      princ_integer(v9222->length);
      princ_string(",");
      args_list_bag(v9222,v7180,_sup_integer(v9222->length,2));
      princ_string(")");
      } 
    GC_UNBIND;} 

void  generate_s_file_string(char *v9396,list *v9222,OID v9221)
{ GC_BIND;
  { ClairePort * v9226 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(_7_string(GC_STRING(Optimize.compiler->source),v9396)),"-s")),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),"w"));
    list * v8984 = GC_OBJECT(list,add_modules_list(v9222));
    list * v212 = GC_OBJECT(list,parents_list(v9222));
    (Optimize.OPT->cinterface = v9226);
    (Optimize.OPT->properties = set::empty(Kernel._property));
    (Optimize.OPT->objects = list::empty(Kernel._any));
    (Optimize.OPT->functions = list::empty(Kernel._any));
    (Optimize.OPT->need_to_close = set::empty(Kernel._any));
    (Optimize.OPT->legal_modules = set_I_bag(v212));
    use_as_output_port(v9226);
    princ_string("// --- System configuration file for ");
    print_any(_string_(v9396));
    princ_string(" , [");
    print_any(GC_OID(_string_(date_I_integer(1))));
    princ_string("] ---\n\n");
    princ_string("#include <claire.h>\n");
    princ_string("#include <Kernel.h>\n");
    { ITERATE(v9232);
      for (START(v8984); NEXT(v9232);)
      if (OBJECT(module,v9232)->made_of->length != 0)
       { princ_string("#include <");
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
        princ_string(".h>\n");
        } 
      } 
    create_load_modules_string(v9396,v9226,v212,v9221);
    if ((boolean_I_any(_oid_(_at_property1(Core.main,Kernel._list))) == CTRUE) && 
        (domain_I_restriction(((restriction *) _at_property1(Core.main,Kernel._list))) == Kernel._list))
     { char * v9233 = "main_list";
      princ_string("\nextern void ");
      princ_string(v9233);
      princ_string("(list *l);\n");
      princ_string("void call_main() {");
      princ_string(v9233);
      princ_string("(ClEnv->params);}\n");
      } 
    else princ_string("\nvoid call_main() {default_main();}\n");
      fclose_port(v9226);
    } 
  GC_UNBIND;} 

void  create_load_modules_string(char *v9396,ClairePort *v9226,list *v212,OID v9221)
{ GC_BIND;
  breakline_void();
  { OID gc_local;
    ITERATE(v9232);
    for (START(v212); NEXT(v9232);)
    if ((*Kernel.status)(v9232) == 5)
     { princ_string("void load_");
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
      princ_string("() {");
      ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
      princ_string(".metaLoad();}\n");
      } 
    } 
  princ_string("\n\nvoid loadModules() \n");
  new_block_void();
  princ_string("//module definitions ");
  breakline_void();
  princ_string("");
  { OID gc_local;
    ITERATE(v9232);
    bag *v9232_support;
    v9232_support = GC_OBJECT(set,_backslash_type(v212,GC_OBJECT(set,set::alloc(Kernel.emptySet,3,_oid_(claire.it),
      _oid_(mClaire.it),
      _oid_(Kernel.it)))));
    for (START(v9232_support); NEXT(v9232);)
    { GC_LOOP;
      { ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
        princ_string(".initModule(");
        print_any(GC_OID(_string_(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v9232))))));
        princ_string(",");
        expression_thing(OBJECT(module,v9232)->part_of,Core.nil->value);
        princ_string(",");
        (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(_oid_(OBJECT(module,v9232)->uses)),
            _oid_(Kernel._list))),
          Core.nil->value);
        princ_string(",");
        breakline_void();
        print_any(GC_OID((*Kernel.source)(v9232)));
        princ_string(",");
        (*Generate.expression)(GC_OID((*Optimize.c_code)(GC_OID(_oid_(OBJECT(module,v9232)->made_of)),
            _oid_(Kernel._list))),
          Core.nil->value);
        princ_string(");");
        breakline_void();
        princ_string("");
        } 
      GC_UNLOOP;} 
    } 
  princ_string("//module load ");
  breakline_void();
  princ_string("");
  { OID gc_local;
    ITERATE(v9232);
    for (START(v212); NEXT(v9232);)
    if ((OBJECT(module,v9232)->made_of->length != 0) && 
        ((*Kernel.status)(v9232) != 5))
     { ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
      princ_string(".metaLoad();");
      breakline_void();
      princ_string("");
      } 
    } 
  { OID gc_local;
    ITERATE(v9232);
    for (START(v212); NEXT(v9232);)
    { GC_LOOP;
      if ((*Kernel.status)(v9232) == 5)
       { ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
        princ_string(".it->evaluate = ");
        expression_any(_oid_(make_function_string(append_string("load_",GC_STRING(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v9232))))))),Kernel.cfalse);
        breakline_void();
        princ_string("");
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
        princ_string(".it->status = 2;");
        breakline_void();
        princ_string("");
        } 
      GC_UNLOOP;} 
    } 
  princ_string("ClEnv->module_I = ");
  { OID  v12799;
    if (INHERIT(OWNER(v9221),Kernel._module))
     v12799 = v9221;
    else v12799 = _oid_(claire.it);
      (*Generate.expression)(v12799,
      Core.nil->value);
    } 
  princ_string("; ");
  breakline_void();
  princ_string("");
  if (Optimize.compiler->safety > 5)
   princ_string("ClAlloc->statusGC = 2;\n");
  if (Optimize.OPT->profile_ask == CTRUE)
   { OID gc_local;
    ITERATE(v9226);
    for (START(Reader.PRdependent->graph); NEXT(v9226);)
    { GC_LOOP;
      if (INHERIT(OWNER(v9226),Kernel._property))
       { OID gc_local;
        ITERATE(v7466);
        bag *v7466_support;
        v7466_support = GC_OBJECT(set,OBJECT(bag,nth_table1(Reader.PRdependent,v9226)));
        for (START(v7466_support); NEXT(v7466);)
        if ((contain_ask_set(Optimize.OPT->to_remove,v7466) != CTRUE) && 
            (OBJECT(thing,v9226)->name->definition == OBJECT(thing,v7466)->name->definition))
         { princ_string("PRdepends_property(");
          expression_thing(OBJECT(thing,v9226),Core.nil->value);
          princ_string(",");
          expression_thing(OBJECT(thing,v7466),Core.nil->value);
          princ_string(");\n");
          } 
        } 
      GC_UNLOOP;} 
    } 
  close_block_void();
  GC_UNBIND;} 

void  methods_interface_c_producer(Generate_c_producer *v9211,ClaireClass *v9232)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v9226);
    bag *v9226_support;
    v9226_support = GC_OBJECT(list,OBJECT(bag,nth_table1(Language.InterfaceList,_oid_(v9232))));
    for (START(v9226_support); NEXT(v9226);)
    { GC_LOOP;
      { ClaireObject * v9221 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v9226),v9232));
        if ((Kernel._method == v9221->isa) && 
            (get_property(Kernel.formula,v9221) != CNULL))
         { ClaireClass * v9233 = class_I_type(OBJECT(ClaireType,(*Kernel.range)(_oid_(v9221))));
          list * v7019 = GC_OBJECT(list,cdr_list(OBJECT(lambda,(*Kernel.formula)(_oid_(v9221)))->vars));
          breakline_void();
          interface_I_c_producer(v9211,v9233);
          princ_string(" ");
          (*Kernel.c_princ)(GC_OID((*Kernel.name)(v9226)));
          princ_string("(");
          typed_args_list_list(v7019);
          princ_string(");  ");
          } 
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  methods_bodies_c_producer(Generate_c_producer *v9211,ClaireClass *v9232)
{ GC_RESERVE(6);  // v3.0.55 optim !
  { OID gc_local;
    ITERATE(v9226);
    bag *v9226_support;
    v9226_support = GC_OBJECT(list,OBJECT(bag,nth_table1(Language.InterfaceList,_oid_(v9232))));
    for (START(v9226_support); NEXT(v9226);)
    { GC_LOOP;
      { ClaireObject * v9221 = GC_OBJECT(ClaireObject,_at_property1(OBJECT(property,v9226),v9232));
        if ((Kernel._method == v9221->isa) && 
            (get_property(Kernel.formula,v9221) != CNULL))
         { ClaireClass * v9233 = class_I_type(OBJECT(ClaireType,(*Kernel.range)(_oid_(v9221))));
          list * v7019 = GC_OBJECT(list,cdr_list(OBJECT(lambda,(*Kernel.formula)(_oid_(v9221)))->vars));
          breakline_void();
          princ_string("// interface method ");
          breakline_void();
          princ_string("");
          breakline_void();
          interface_I_c_producer(v9211,v9233);
          princ_string(" ");
          class_princ_class(v9232);
          princ_string("::");
          (*Kernel.c_princ)(GC_OID((*Kernel.name)(v9226)));
          princ_string("(");
          typed_args_list_list(v7019);
          princ_string(")");
          breakline_void();
          princ_string("  ");
          princ_string("\t{ ");
          if (v9233 != Kernel._void)
           { princ_string("return (");
            interface_I_c_producer(v9211,v9233);
            princ_string(") ");
            } 
          if ((OBJECT(ClaireBoolean,(*Kernel._sup)(GC_OID((*Kernel.dispatcher)(v9226)),
            0))) == CTRUE)
           { (*Generate.expression)(v9226,
              Core.nil->value);
            princ_string("->fcall((int) this");
            { OID gc_local;
              ITERATE(v9236);
              for (START(v7019); NEXT(v9236);)
              { princ_string(",(int) ");
                (*Generate.expression)(v9236,
                  Core.nil->value);
                } 
              } 
            princ_string(")");
            } 
          else { c_princ_function(OBJECT(ClaireFunction,(*Optimize.functional_I)(_oid_(v9221))));
              princ_string("(this");
              { OID gc_local;
                ITERATE(v9236);
                for (START(v7019); NEXT(v9236);)
                { princ_string(",");
                  (*Generate.expression)(v9236,
                    Core.nil->value);
                  } 
                } 
              princ_string(")");
              } 
            princ_string(";}\n");
          breakline_void();
          princ_string("");
          } 
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

