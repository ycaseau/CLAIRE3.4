/***** CLAIRE Compilation of file c:\claire\v3.4\src\compile\gsystem.cl 
         [version 3.4.0 / safety 5] Sun Sep 29 07:16:49 2013 *****/

#include <claire.h>
#include <Kernel.h>
#include <Core.h>
#include <Language.h>
#include <Reader.h>
#include <Optimize.h>
#include <Generate.h>
void  ident_symbol(symbol *v9396)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v9396));
  } 

void  ident_thing(thing *v9396)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v9396->name));
  } 

void  ident_class(ClaireClass *v9396)
{ (*Language.ident)(Generate.PRODUCER->value,
    _oid_(v9396->name));
  } 

void  interface_I_class(ClaireClass *v9211)
{ (*Generate.interface_I)(Generate.PRODUCER->value,
    _oid_(v9211));
  } 

void  class_princ_class(ClaireClass *v9211)
{ (*Generate.class_princ)(Generate.PRODUCER->value,
    _oid_(v9211));
  } 

OID  indent_c_void()
{ { OID Result = 0;
    { int  v9232 = Optimize.OPT->level;
      { Result= _oid_(CFALSE);
        while ((v9232 > 0))
        { princ_string("  ");
          v9232= (v9232-1);
          } 
        } 
      } 
    return (Result);} 
  } 

OID  breakline_void()
{ princ_string("\n");
  return (indent_c_void());} 

void  new_block_void()
{ (Optimize.OPT->level = (Optimize.OPT->level+1));
  princ_string("{ ");
  } 

void  close_block_void()
{ (Optimize.OPT->level = (Optimize.OPT->level-1));
  princ_string("} ");
  breakline_void();
  } 

void  c_test_any(OID v9232)
{ GC_BIND;
  { OID  v9231 = GC_OID((*Optimize.c_type)(v9232));
    ClaireClass * v9233 = osort_any(v9231);
    OID  v9234 = GC_OID((*Optimize.c_code)(v9232,
      _oid_(v9233)));
    ClaireBoolean * v9216 = c_func_any(v9234);
    princ_string("type -> ");
    print_any(v9231);
    princ_string(" [sort ");
    print_any(_oid_(v9233));
    princ_string("]\n");
    princ_string("opt[");
    print_any(_oid_(OWNER(v9234)));
    princ_string("] -> ");
    print_any(v9234);
    princ_string(" \n");
    if (v9216 == CTRUE)
     { princ_string("exp  -> ");
      (*Generate.expression)(v9234,
        Core.nil->value);
      princ_string("\n");
      } 
    else { princ_string("stat -> ");
        statement_any(v9234,_string_("result"),Core.nil->value);
        princ_string("\n");
        } 
      } 
  GC_UNBIND;} 

void  c_test_method(method *v9221)
{ GC_BIND;
  { lambda * v9222 = GC_OBJECT(lambda,v9221->formula);
    if (v9222 == (NULL))
     ;else { tformat_string("---- Compiling ~S ---- \n",0,list::alloc(1,_oid_(v9221)));
        (Optimize.OPT->in_method = _oid_(v9221));
        (Optimize.OPT->protection = CFALSE);
        (Optimize.OPT->allocation = CFALSE);
        if (Optimize.OPT->loop_index > 0)
         (Optimize.OPT->loop_index = 0);
        (Optimize.OPT->loop_gc = CFALSE);
        (Optimize.OPT->use_update = CFALSE);
        (Optimize.OPT->use_nth_equal = CFALSE);
        (Optimize.OPT->use_string_update = CFALSE);
        (Optimize.OPT->max_vars = 0);
        (Optimize.OPT->online_ask = CFALSE);
        (Optimize.OPT->legal_modules = ((set *) Kernel._module->instances));
        (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = v9222->body);
        { ClaireClass * v9233 = Kernel._void;
          OID  v14047;
          { { v9233= check_sort_method(v9221);
              v14047 = OBJECT(Generate_producer,Generate.PRODUCER->value)->body;
              } 
            GC_OID(v14047);} 
          char * v12286 = GC_STRING(string_v((*Generate.protect_result)(Generate.PRODUCER->value,
            _oid_(v9233),
            _oid_(Optimize.OPT->protection),
            _oid_(v9221))));
          princ_string("Opt => ");
          print_any(v14047);
          princ_string(" \n\n");
          new_block_void();
          (*Generate.print_body)(v14047,
            _string_(v12286),
            _oid_(v9233),
            GC_OID(v9222->body),
            Kernel.ctrue);
          } 
        (Optimize.OPT->in_method = CNULL);
        } 
      } 
  GC_UNBIND;} 

void  compile_module(module *v9396)
{ GC_BIND;
  (Optimize.OPT->need_modules = Kernel.emptySet);
  { bag * v7341 = GC_OBJECT(list,parents_list(GC_OBJECT(list,add_modules_list(list::alloc(1,_oid_(v9396))))));
    update_property(Optimize.legal_modules,
      Optimize.OPT,
      9,
      Kernel._object,
      GC_OID((*Kernel.set_I)(_oid_(v7341))));
    if (Optimize.compiler->class2file_ask == CTRUE)
     { tformat_string("**** Compiling the module ~A [v. 3.~A - verbose:~A opt:~S] \n",2,list::alloc(4,GC_OID(_string_(string_I_symbol(v9396->name))),
        GC_OID(Optimize.compiler->version),
        ClEnv->verbose,
        _oid_(Optimize.compiler->optimize_ask)));
      write_property(Generate.outmodule,Optimize.OPT,GC_OID(ClAlloc->import(Kernel._port,(int *) fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
        _oid_(v9396->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),"w"))));
      generate_files_module(v9396);
      begin_module(v9396);
      generate_classes_module(v9396);
      generate_c2f_module(v9396);
      end_module(v9396);
      } 
    else { generate_files_module(v9396);
        generate_f2f_module(v9396);
        generate_interface_module(v9396,GC_OBJECT(set,Optimize.OPT->legal_modules));
        } 
      v7341= GC_OBJECT(set,difference_set(GC_OBJECT(set,set_I_set(Optimize.OPT->need_modules)),GC_OBJECT(set,Optimize.OPT->legal_modules)));
    if (v7341->length != 0)
     tformat_string("---- WARNING: ~S should be declared for ~S\n",2,list::alloc(2,_oid_(v7341),_oid_(v9396)));
    } 
  GC_UNBIND;} 

void  generate_files_module(module *v9396)
{ GC_BIND;
  tformat_string("==== Generate ~A files for module ~S [verbose = ~A, Opt? = ~S] \n",0,list::alloc(4,GC_OID(_string_(OBJECT(Generate_producer,Generate.PRODUCER->value)->comment)),
    _oid_(v9396),
    ClEnv->verbose,
    _oid_(Optimize.compiler->optimize_ask)));
  (Optimize.OPT->instructions = list::empty(Kernel._any));
  (Optimize.OPT->properties = set::empty(Kernel._property));
  (Optimize.OPT->objects = list::empty(Kernel._object));
  (Optimize.OPT->functions = list::empty(Kernel._any));
  (Optimize.OPT->need_to_close = set::empty(Kernel._any));
  (*Generate.start_module_interface)(Generate.PRODUCER->value,
    _oid_(v9396));
  begin_module(v9396);
  { OID gc_local;
    ITERATE(v9232);
    bag *v9232_support;
    v9232_support = GC_OBJECT(list,v9396->made_of);
    for (START(v9232_support); NEXT(v9232);)
    { GC_LOOP;
      { tformat_string("++++ Compiling the file ~A.cl [v. 3.~A - safety:~A] \n",2,list::alloc(3,v9232,
          GC_OID(Optimize.compiler->version),
          Optimize.compiler->safety));
        if (equal(v9232,_string_(string_I_symbol(v9396->name))) == CTRUE)
         (*Optimize.Cerror)(_string_("[211]  ~S cannot be used both as a file and module name"),
          v9232);
        generate_file_string2(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(v9396->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_v(v9232))),GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),string_v(v9232))));
        if (CFALSE == CTRUE)
         claire_gc();
        } 
      GC_UNLOOP;} 
    } 
  end_module(v9396);
  GC_UNBIND;} 

void  generate_f2f_module(module *v9221)
{ GC_BIND;
  { ClairePort * v9226 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_I_symbol(v9221->name)))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),"w"));
    tformat_string("==== generate file for module ~S [~A GC protections inserted] ==== \n",0,list::alloc(2,_oid_(v9221),OBJECT(Generate_producer,Generate.PRODUCER->value)->stat));
    (Optimize.OPT->outfile = v9226);
    generate_file_string1(GC_STRING(string_I_symbol(v9221->name)),v9221);
    } 
  GC_UNBIND;} 

void  generate_file_string1(char *v9233,module *v9221)
{ GC_BIND;
  start_file_string(v9233,v9221);
  use_as_output_port(Optimize.OPT->outfile);
  (*Generate.generate_classes)(Generate.PRODUCER->value,
    _string_(v9233),
    _oid_(v9221));
  { OID gc_local;
    ITERATE(v9211);
    bag *v9211_support;
    v9211_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v9211_support); NEXT(v9211);)
    if (INHERIT(OWNER(v9211),Kernel._class))
     (*Generate.methods_bodies)(Generate.PRODUCER->value,
      v9211);
    } 
  generate_meta_load_module(v9221);
  breakline_void();
  princ_string("GC_UNBIND;");
  close_block_void();
  breakline_void();
  fclose_port(Optimize.OPT->outfile);
  GC_UNBIND;} 

void  generate_classes_module(module *v9396)
{ GC_BIND;
  erase_table(Generate.classFile);
  { OID gc_local;
    ITERATE(v9211);
    bag *v9211_support;
    v9211_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v9211_support); NEXT(v9211);)
    { GC_LOOP;
      if (INHERIT(OWNER(v9211),Kernel._class))
       { put_table(Generate.classFile,v9211,ClAlloc->import(Kernel._port,(int *) fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
          GC_OID((*Kernel.name)(v9211))))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),"w")));
        use_as_output_port(EXPORT((ClairePort *),nth_table1(Generate.classFile,v9211)));
        tformat_string("++++ Creating the file ~A.java\n",2,GC_OBJECT(list,list::alloc(1,GC_OID((*Generate.c_string)(Generate.PRODUCER->value,
          GC_OID((*Kernel.name)(v9211)))))));
        (Optimize.OPT->level = 0);
        princ_string("// class file for ");
        print_any(v9211);
        princ_string(" in module ");
        print_any(_oid_(v9396));
        princ_string(" ");
        breakline_void();
        breakline_void();
        breakline_void();
        princ_string("public class ");
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v9211)));
        princ_string(" extends ");
        ident_symbol(OBJECT(ClaireClass,v9211)->superclass->name);
        new_block_void();
        breakline_void();
        breakline_void();
        princ_string("/* empty constructor by default */");
        breakline_void();
        princ_string("public ");
        ident_symbol(OBJECT(symbol,(*Kernel.name)(v9211)));
        princ_string("() {}");
        breakline_void();
        breakline_void();
        breakline_void();
        princ_string("/* declaration of fields */");
        { OID gc_local;
          ITERATE(v9235);
          bag *v9235_support;
          v9235_support = GC_OBJECT(list,OBJECT(bag,(*Optimize.get_indexed)(v9211)));
          for (START(v9235_support); NEXT(v9235);)
          if (_oid_(domain_I_restriction(OBJECT(restriction,v9235))) == v9211)
           { breakline_void();
            princ_string("public  ");
            interface_I_class(psort_any(_oid_(OBJECT(restriction,v9235)->range)));
            princ_string(" ");
            ident_symbol(OBJECT(restriction,v9235)->selector->name);
            princ_string(";");
            } 
          } 
        breakline_void();
        princ_string("");
        fclose_port(EXPORT((ClairePort *),nth_table1(Generate.classFile,v9211)));
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_c2f_module(module *v9396)
{ GC_BIND;
  { ClairePort * v1141 = (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v9396->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),"w"));
    (Optimize.OPT->outfile = v1141);
    use_as_output_port(v1141);
    (*Generate.generate_start_file)(Generate.PRODUCER->value,
      _oid_(v9396));
    fclose_port(v1141);
    claire_gc();
    generate_functions_module(v9396);
    claire_gc();
    v1141= (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
      _oid_(v9396->name)))))),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),"a"));
    use_as_output_port(v1141);
    (Optimize.OPT->outfile = v1141);
    (Optimize.OPT->level = 2);
    generate_objects_module(v9396);
    use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
    claire_gc();
    use_as_output_port(v1141);
    generate_meta_load_module(v9396);
    (*Generate.generate_end_file)(Generate.PRODUCER->value,
      _oid_(v9396));
    } 
  GC_UNBIND;} 

void  generate_interface_module(module *v9396,bag *v9222)
{ tformat_string("==== Generate inteface (.h) files for module ~S \n",0,list::alloc(1,_oid_(v9396)));
  use_as_output_port(Optimize.OPT->cinterface);
  breakline_void();
  (*Generate.generate_interface)(Generate.PRODUCER->value,
    _oid_(v9396));
  (*Generate.namespace_I)(Generate.PRODUCER->value,
    _oid_(v9396));
  generate_objects_module(v9396);
  (*Kernel.module_I)(Generate.PRODUCER->value,
    _oid_(v9396));
  (*Generate.end_module_interface)(Generate.PRODUCER->value,
    _oid_(v9396));
  fclose_port(Optimize.OPT->cinterface);
  use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value));
  } 

void  generate_objects_module(module *v9396)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { OID gc_local;
    ITERATE(v9232);
    bag *v9232_support;
    v9232_support = GC_OBJECT(list,Optimize.OPT->objects);
    for (START(v9232_support); NEXT(v9232);)
    { breakline_void();
      (*Generate.public_static)(Generate.PRODUCER->value);
      if (INHERIT(OWNER(v9232),Core._global_variable))
       { { OID  v16291;
          if (nativeVar_ask_global_variable(OBJECT(global_variable,v9232)) == CTRUE)
           v16291 = _oid_(getRange_global_variable(OBJECT(global_variable,v9232)));
          else v16291 = _oid_(Core._global_variable);
            (*Generate.interface_I)(Generate.PRODUCER->value,
            v16291);
          } 
        princ_string(" ");
        ident_symbol(OBJECT(thing,v9232)->name);
        princ_string(";");
        } 
      else { (*Generate.interface_I)(Generate.PRODUCER->value,
            _oid_(psort_any(_oid_(OWNER(v9232)))));
          princ_string(" ");
          if (INHERIT(OWNER(v9232),Kernel._class))
           { princ_string("_");
            c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v9232))));
            } 
          else if (INHERIT(OWNER(v9232),Reader._reserved_keyword))
           { princ_string("_cl_");
            c_princ_string(string_I_symbol(OBJECT(symbol,(*Kernel.name)(v9232))));
            } 
          else ident_symbol(OBJECT(symbol,(*Kernel.name)(v9232)));
            princ_string(";");
          } 
        } 
    } 
  { OID gc_local;
    ITERATE(v9232);
    bag *v9232_support;
    v9232_support = GC_OBJECT(set,Optimize.OPT->properties);
    for (START(v9232_support); NEXT(v9232);)
    { GC_LOOP;
      if (Optimize.OPT->objects->memq(v9232) != CTRUE)
       { { OID  v15548;
          { { OID  v15081 = CNULL;
              { OID gc_local;
                ITERATE(v7466);
                bag *v7466_support;
                v7466_support = GC_OBJECT(set,Optimize.OPT->properties);
                for (START(v7466_support); NEXT(v7466);)
                { GC_LOOP;
                  if (v7466 != v9232)
                   { if (equal_string(string_I_symbol(OBJECT(thing,v7466)->name),string_I_symbol(OBJECT(thing,v9232)->name)) == CTRUE)
                     { v15081= v7466;
                      break;} 
                    } 
                  GC_UNLOOP;} 
                } 
              v15548 = v15081;
              } 
            GC_OID(v15548);} 
          if (v15548 != CNULL)
           { property * v7466 = OBJECT(property,v15548);
            close_exception(((general_error *) (*Core._general_error)(_string_("[217] ~S and ~S cannot be defined in the same module"),
              _oid_(list::alloc(2,_oid_(v7466),v9232)))));
            } 
          else ;} 
        princ_string("\n");
        (*Generate.public_static)(Generate.PRODUCER->value);
        (*Generate.interface_I)(Generate.PRODUCER->value,
          _oid_(psort_any(_oid_(OWNER(v9232)))));
        princ_string(" ");
        ident_symbol(OBJECT(thing,v9232)->name);
        princ_string(";// ");
        print_any(_oid_(OBJECT(thing,v9232)->name));
        princ_string("");
        } 
      GC_UNLOOP;} 
    } 
  GC_UNBIND;} 

void  generate_meta_load_module(module *v9396)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  princ_string("// definition of the meta-model for ");
  print_any(_oid_(v9396));
  princ_string(" \n");
  breakline_void();
  princ_string("");
  (*Generate.generate_meta_load)(Generate.PRODUCER->value,
    _oid_(v9396));
  princ_string("// definition of the properties ");
  { OID gc_local;
    ITERATE(v9232);
    bag *v9232_support;
    v9232_support = GC_OBJECT(set,Optimize.OPT->properties);
    for (START(v9232_support); NEXT(v9232);)
    if (Optimize.OPT->objects->memq(v9232) != CTRUE)
     (*Generate.declare)(Generate.PRODUCER->value,
      v9232);
    } 
  breakline_void();
  breakline_void();
  princ_string("// instructions from module sources");
  { OID  v9218 = CNULL;
    { OID gc_local;
      ITERATE(v9217);
      bag *v9217_support;
      v9217_support = GC_OBJECT(list,Optimize.OPT->instructions);
      for (START(v9217_support); NEXT(v9217);)
      { GC_LOOP;
        { breakline_void();
          if (Kernel._string == OWNER(v9217))
           { if (equal(_oid_(Kernel._string),_oid_(OWNER(v9218))) != CTRUE)
             breakline_void();
            princ_string("// ");
            (*Kernel.princ)(v9217);
            princ_string("");
            } 
          else if (global_var_def_ask_any(v9217) == CTRUE)
           (*Generate.global_var_def_I)(Generate.PRODUCER->value,
            _oid_(v9396),
            v9217);
          else statement_any(v9217,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
            GC__OID(v9218 = v9217, 1);
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 

ClaireBoolean * global_var_def_ask_any(OID v9232)
{ GC_BIND;
  { ClaireBoolean *Result ;
    Result = ((INHERIT(OWNER(v9232),Language._Let)) ?
      ((INHERIT(OWNER(OBJECT(Let,v9232)->value),Language._Call)) ? (((*Kernel.selector)(OBJECT(Let,v9232)->value) == _oid_(Optimize.object_I)) ? (((*(OBJECT(bag,(*Core.args)(OBJECT(Let,v9232)->value))))[2] == _oid_(Core._global_variable)) ? CTRUE: CFALSE): CFALSE): CFALSE) :
      CFALSE );
    GC_UNBIND; return (Result);} 
  } 

ClaireClass * getRange_global_variable(global_variable *v9232)
{ { ClaireClass *Result ;
    Result = ((equal(_oid_(v9232->range),_oid_(Kernel.emptySet)) == CTRUE) ?
      OWNER(v9232->value) :
      class_I_type(v9232->range) );
    return (Result);} 
  } 

void  generate_functions_module(module *v9396)
{ GC_BIND;
  princ_string("// definition of class methods ");
  { ClairePort * v9226 = (Optimize.OPT->outfile);
    { OID gc_local;
      ITERATE(v9216);
      bag *v9216_support;
      v9216_support = GC_OBJECT(list,Optimize.OPT->functions);
      for (START(v9216_support); NEXT(v9216);)
      { GC_LOOP;
        { (Optimize.OPT->level = 2);
          (Optimize.OPT->outfile = v9226);
          print_c_function_lambda2(GC_OBJECT(lambda,OBJECT(lambda,(*Kernel.nth)(v9216,
            1))),GC_STRING(string_v((*Kernel.nth)(v9216,
            2))),GC_OID((*Kernel.nth)(v9216,
            3)));
          } 
        GC_UNLOOP;} 
      } 
    } 
  GC_UNBIND;} 

list * parents_module(module *v9396,list *v9222)
{ if (v9222->memq(_oid_(v9396)) == CTRUE) 
  { { list *Result ;
      Result = v9222;
      return (Result);} 
     } 
  else{ GC_BIND;
    if (((v9396->part_of == (NULL)) ? CTRUE : CFALSE) != CTRUE)
     v9222= GC_OBJECT(list,parents_module(v9396->part_of,v9222));
    v9222= GC_OBJECT(list,v9222->addFast(_oid_(v9396)));
    { list *Result ;
      Result = v9222;
      GC_UNBIND; return (Result);} 
    } 
  } 

list * parents_list(list *v9396)
{ GC_RESERVE(1);  // HOHO v3.0.55 optim !
  { list *Result ;
    { list * v9222 = list::empty(Kernel._module);
      { OID gc_local;
        ITERATE(v9232);
        for (START(v9396); NEXT(v9232);)
        { GC_LOOP;
          GC__ANY(v9222 = parents_module(OBJECT(module,v9232),v9222), 1);
          GC_UNLOOP;} 
        } 
      Result = v9222;
      } 
    GC_UNBIND; return (Result);} 
  } 

void  get_module2(module *v9221)
{ load_module(v9221);
  begin_module(v9221);
  } 

void  generate_file_string2(char *v9396,char *v7156)
{ GC_RESERVE(7);  // v3.0.55 optim !
  { ClairePort * v7465 = (fopen_string(append_string(v9396,".cl"),"r"));
    ClaireBoolean * v9210 = Reader.reader->toplevel;
    ClairePort * v7464 = (Reader.reader->fromp);
    if (Optimize.compiler->class2file_ask != CTRUE)
     (Optimize.OPT->outfile = fopen_string(append_string(v7156,GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),"w"));
    (Reader.reader->toplevel = CFALSE);
    (Optimize.compiler->loading_ask = CTRUE);
    (Reader.reader->nb_line = 1);
    (Reader.reader->external = v9396);
    (Reader.reader->fromp = v7465);
    if (Optimize.compiler->class2file_ask != CTRUE)
     start_file_string(v9396,ClEnv->module_I);
    { OID  v178 = GC_OID(readblock_port(v7465));
      { OID gc_local;
        while ((equal(v178,_oid_(Reader.eof)) != CTRUE))
        { GC_LOOP;
          if (ClEnv->verbose > 5)
           { princ_string("[");
            princ_integer(Reader.reader->nb_line);
            princ_string("] ");
            print_any(_oid_(OWNER(v178)));
            princ_string(" (");
            print_any(GC_OID(_oid_(Optimize.OPT->need_modules)));
            princ_string("%)\n");
            } 
          if ((Kernel._string == OWNER(v178)) && 
              (Optimize.compiler->class2file_ask != CTRUE))
           { if (Optimize.compiler->naming < 2)
             { ClairePort * v7529 = (use_as_output_port(Optimize.OPT->outfile));
              princ_string("\n//");
              (*Kernel.princ)(v178);
              princ_string("");
              use_as_output_port(v7529);
              } 
            } 
          else GC_OBJECT(list,Optimize.OPT->instructions)->addFast(GC_OID((*Optimize.c_code)(v178,
              _oid_(Kernel._void))));
            GC__OID(v178 = readblock_port(v7465), 6);
          GC_UNLOOP;} 
        } 
      } 
    fclose_port(v7465);
    (Optimize.compiler->loading_ask = CFALSE);
    (Reader.reader->toplevel = v9210);
    (Reader.reader->external = "toplevel");
    (Reader.reader->fromp = v7464);
    if (Optimize.compiler->class2file_ask != CTRUE)
     fclose_port(Optimize.OPT->outfile);
    } 
  GC_UNBIND;} 

OID  make_c_function_lambda_Generate(lambda *v9396,char *v4591,OID v9221)
{ { OID Result = 0;
    if (Optimize.compiler->class2file_ask == CTRUE)
     Result = (*Generate.create_function_entry)(Generate.PRODUCER->value,
      _oid_(v9396),
      _string_(v4591),
      v9221);
    else Result = print_c_function_lambda2(v9396,v4591,v9221);
      return (Result);} 
  } 

OID  print_c_function_lambda2(lambda *v9396,char *v4591,OID v9221)
{ GC_BIND;
  (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = v9396->body);
  { OID Result = 0;
    { ClaireClass * v9233 = Kernel._void;
      OID  v14047;
      { if (boolean_I_any(v9221) != CTRUE)
         v14047 = (*Optimize.c_code)(GC_OID(v9396->body),
          _oid_(Kernel._void));
        else if (Kernel._method == OWNER(v9221))
         { v9233= check_sort_method(OBJECT(method,v9221));
          v14047 = OBJECT(Generate_producer,Generate.PRODUCER->value)->body;
          } 
        else if (INHERIT(OWNER(v9221),Kernel._class))
         { v9233= OBJECT(ClaireClass,v9221);
          v14047 = (*Optimize.c_code)(GC_OID(v9396->body),
            v9221);
          } 
        else { v9233= Kernel._any;
            v14047 = (*Optimize.c_code)(GC_OID(v9396->body),
              _oid_(Kernel._any));
            } 
          GC_OID(v14047);} 
      OID  v12286 = GC_OID((*Generate.protect_result)(Generate.PRODUCER->value,
        _oid_(v9233),
        _oid_(Optimize.OPT->protection),
        v9221));
      ClaireBoolean * v182 = need_debug_ask_any(v9221);
      ClaireBoolean * v10060 = ((Optimize.OPT->profile_ask == CTRUE) ? (((Kernel._method == OWNER(v9221)) || 
          (v9221 == CNULL)) ? CTRUE: CFALSE): CFALSE);
      (*Generate.generate_function_start)(Generate.PRODUCER->value,
        _oid_(v9396),
        _oid_(v9233),
        v9221,
        _string_(v4591));
      if (Optimize.OPT->max_vars > 0)
       { (Language._starvariable_index_star->value= 0);
        lexical_num_any2(v14047,(v9396->vars->length+1));
        (Optimize.OPT->loop_index = Language._starvariable_index_star->value);
        } 
      new_block_void();
      if (v10060 == CTRUE)
       (*Generate.generate_profile)(Generate.PRODUCER->value,
        v9221);
      if (v182 == CTRUE)
       (*Generate.debug_intro)(Generate.PRODUCER->value,
        _oid_(v9396),
        v9221);
      (*Generate.print_body)(v14047,
        v12286,
        _oid_(v9233),
        GC_OID(v9396->body),
        _oid_(not_any(_oid_(((Optimize.OPT->protection == CTRUE) ? CTRUE : ((v10060 == CTRUE) ? CTRUE : ((v182 == CTRUE) ? CTRUE : ((Optimize.OPT->alloc_stack == CTRUE) ? CTRUE : CFALSE))))))));
      close_block_void();
      breakline_void();
      (Optimize.OPT->alloc_stack = CFALSE);
      Result = ClAlloc->import(Kernel._port,(int *) use_as_output_port(EXPORT((ClairePort *),Reader.STDOUT->value)));
      } 
    GC_UNBIND; return (Result);} 
  } 

void  print_body_If(If *v14047,char *v12286,ClaireClass *v9233,If *v8334,ClaireBoolean *v8511)
{ GC_BIND;
  if ((c_func_any(GC_OID(v14047->test)) == CTRUE) && 
      ((Optimize.OPT->protection == CTRUE) && 
        ((c_safe_any(GC_OID(v8334->arg)) == CTRUE) && 
          (Optimize.compiler->debug_ask->memq(_oid_(ClEnv->module_I)) != CTRUE))))
   { char * v4084 = ((v9233 != Kernel._void) ?
      "return " :
      "" );
    princ_string("if ");
    (*Optimize.bool_exp)(GC_OID(v14047->test),
      Kernel.ctrue,
      Core.nil->value);
    princ_string(" ");
    breakline_void();
    new_block_void();
    outer_statement_any(GC_OID(v14047->arg),v4084,v9233,v8511);
    princ_string(" ");
    close_block_void();
    princ_string("else");
    new_block_void();
    (*Generate.print_body)(GC_OID(v14047->other),
      _string_(v12286),
      _oid_(v9233),
      GC_OID(v8334->other),
      _oid_(v8511));
    close_block_void();
    } 
  else print_body_any(_oid_(v14047),
      v12286,
      v9233,
      _oid_(v8334),
      v8511);
    GC_UNBIND;} 

void  print_body_any(OID v14047,char *v12286,ClaireClass *v9233,OID v8334,ClaireBoolean *v8511)
{ (*Generate.gc_introduction)(Generate.PRODUCER->value,
    v14047);
  outer_statement_any(v14047,v12286,v9233,v8511);
  } 

OID  print_body_Do(Do *v14047,char *v12286,ClaireClass *v9233,OID v8334,ClaireBoolean *v8511)
{ GC_BIND;
  { OID Result = 0;
    { list * v9222 = GC_OBJECT(list,v14047->args);
      int  v7395 = v9222->length;
      int  v9221 = 0;
      (*Generate.gc_introduction)(Generate.PRODUCER->value,
        _oid_(v14047));
      { ITERATE(v9232);
        Result= Kernel.cfalse;
        for (START(v9222); NEXT(v9232);)
        { ++v9221;
          if (v9221 == v7395)
           outer_statement_any(v9232,v12286,v9233,v8511);
          else inner_statement_any(v9232,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
            } 
        } 
      } 
    GC_UNBIND; return (Result);} 
  } 

void  outer_statement_any(OID v14047,char *v12286,ClaireClass *v9233,ClaireBoolean *v8511)
{ if ((c_func_any(v14047) == CTRUE) && 
      ((v8511 == CTRUE) && 
        ((v9233 != Kernel._void) && 
          (inherit_ask_class(OWNER(v14047),Language._If) != CTRUE))))
   { if (equal_string(v12286,"") != CTRUE)
     { princ_string(v12286);
      princ_string("(");
      (*Generate.expression)(v14047,
        Core.nil->value);
      princ_string(");");
      } 
    else { (*Generate.expression)(v14047,
          Core.nil->value);
        princ_string(";");
        } 
      } 
  else if (v9233 != Kernel._void)
   { new_block_void();
    (*Generate.define_variable)(Generate.PRODUCER->value,
      _oid_(v9233),
      _string_("Result"));
    breakline_void();
    statement_any(v14047,_string_("Result"),_oid_(Kernel.emptySet));
    if (equal_string(v12286,"") != CTRUE)
     { princ_string(v12286);
      princ_string("(Result);");
      close_block_void();
      princ_string("");
      } 
    } 
  else { statement_any(v14047,_oid_(Kernel.emptySet),_oid_(Kernel.emptySet));
      princ_string(v12286);
      } 
    } 

ClaireBoolean * c_safe_any(OID v9232)
{ return (not_any(_oid_(((Optimize.OPT->allocation == CTRUE) ? ((BCONTAIN(c_status_any(v9232,Kernel.nil),1)) ? CTRUE: CFALSE): CFALSE))));} 

ClaireClass * check_sort_method(method *v9396)
{ GC_BIND;
  { ClaireClass *Result ;
    { ClaireType * v7558 = v9396->range;
      OID  v9210 = GC_OID(OBJECT(Generate_producer,Generate.PRODUCER->value)->body);
      ClaireType * v7559 = GC_OBJECT(ClaireType,ptype_type(OBJECT(ClaireType,(*Optimize.c_type)(v9210))));
      ClaireClass * v9233 = psort_any(_oid_(v7558));
      (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = c_strict_code_any(v9210,v9233));
      if (_inf_equal_type(v7559,v7558) != CTRUE)
       { tformat_string("---- note: ~S's range was found to be ~S (vs. ~S) \n",2,list::alloc(3,_oid_(v9396),
          _oid_(v7559),
          _oid_(v7558)));
        if (Generate.WrongMethod->value == 0)
         { (Generate.WrongMethod->value= v9210);
          close_exception(((general_error *) (*Core._general_error)(_string_("You can look at WrongMethod"),
            _oid_(Kernel.nil))));
          } 
        if ((Optimize.compiler->safety < 2) || 
            ((Optimize.compiler->safety < 4) && 
                (boolean_I_any(sort_equal_class(osort_any(_oid_(v7559)),v9233)) != CTRUE)))
         (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = c_strict_code_any(GC_OID(c_check_any(GC_OID((*Optimize.c_code)(v9210,
          _oid_(Kernel._any))),GC_OID((*Optimize.c_code)(_oid_(v7558),
          _oid_(Kernel._type))))),v9233));
        if (boolean_I_any(sort_equal_class(osort_any(_oid_(v7559)),v9233)) != CTRUE)
         { if ((v9233 != Kernel._void) && 
              ((_oid_((INHERIT(v7559->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v7559))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v7559))))) == _oid_(Kernel._void)) || 
                  (inherit_ask_class(v9233,OBJECT(ClaireClass,_oid_((INHERIT(v7559->isa,Kernel._class) ? (ClaireObject *) sort_I_class((ClaireClass *) OBJECT(ClaireClass,_oid_(v7559))) :  (ClaireObject *)  sort_I_type((ClaireType *) OBJECT(ClaireType,_oid_(v7559))))))) != CTRUE)))
           (*Optimize.Cerror)(_string_("[218] Sort error: Cannot compile ~S."),
            _oid_(v9396));
          } 
        } 
      { ClaireType * v7561 = GC_OBJECT(ClaireType,OBJECT(ClaireType,(*Kernel._exp)(_oid_(v7558),
          _oid_(v7559))));
        if ((Optimize.compiler->safety > 1) && 
            (osort_any(_oid_(v7561)) == v9233))
         { (OBJECT(Generate_producer,Generate.PRODUCER->value)->body = (*Optimize.c_strict_check)(GC_OID(OBJECT(Generate_producer,Generate.PRODUCER->value)->body),
            _oid_(class_I_type(v7561))));
          ;} 
        } 
      if (INHERIT(v7558->isa,Kernel._tuple))
       { (Optimize.OPT->alloc_stack = CTRUE);
        } 
      if ((Optimize.OPT->allocation == CTRUE) && 
          (nth_integer(status_I_restriction(v9396),6) != CTRUE))
       { if (nth_integer(status_I_restriction(v9396),1) != CTRUE)
         ;} 
      else { (Optimize.OPT->loop_gc = CFALSE);
          (Optimize.OPT->protection = CFALSE);
          } 
        Result = psort_any(_oid_(v9396->range));
      } 
    GC_UNBIND; return (Result);} 
  } 

OID  typed_args_list_list(list *v9396)
{ { OID Result = 0;
    { ClaireBoolean * v15137 = CTRUE;
      { ITERATE(v9232);
        Result= Kernel.cfalse;
        for (START(v9396); NEXT(v9232);)
        { if (v15137 == CTRUE)
           v15137= CFALSE;
          else princ_string(",");
            (*Generate.interface_I)(Generate.PRODUCER->value,
            _oid_(sort_Variable(OBJECT(Variable,v9232))));
          (*Language.ident)(Generate.PRODUCER->value,
            v9232);
          } 
        } 
      } 
    return (Result);} 
  } 

ClaireBoolean * need_debug_ask_any(OID v9221)
{ { ClaireBoolean *Result ;
    if (Kernel._method == OWNER(v9221))
     { property * v9226 = OBJECT(restriction,v9221)->selector;
      Result = ((Optimize.compiler->debug_ask->memq(_oid_(OBJECT(restriction,v9221)->module_I)) == CTRUE) ? 
      ((domain_I_restriction(OBJECT(restriction,v9221)) != Kernel._environment) ? 
      ((OBJECT(restriction,v9221)->module_I != claire.it) ? 
      ((v9226 != Core.self_eval) ? 
      ((v9226 != Core.execute) ? 
      ((v9226 != Core.eval_message) ? 
      ((v9226 != Core.push_debug) ? 
      ((v9226 != Core.pop_debug) ? 
      ((v9226 != Core.tr_indent) ? 
      ((v9226 != Core.find_which) ? 
      ((v9226 != Core.matching_ask) ? 
      ((v9226 != Core.vmatch_ask) ? 
      CTRUE: CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE): CFALSE);
      } 
    else Result = CFALSE;
      return (Result);} 
  } 

void  get_dependents_method(method *v9221)
{ GC_BIND;
  { OID gc_local;
    ITERATE(v9226);
    bag *v9226_support;
    v9226_support = GC_OBJECT(set,dependents_method(v9221));
    for (START(v9226_support); NEXT(v9226);)
    { property * v6597 = v9221->selector;
      add_table(Reader.PRdependent,_oid_(v6597),v9226);
      } 
    } 
  GC_UNBIND;} 

void  c_princ_function(ClaireFunction *v9396)
{ c_princ_string(string_I_function(v9396));
  } 

void  set_outfile_lambda(lambda *v9396)
{ GC_BIND;
  { module * v9221 = ClEnv->module_I;
    char * v7121 = GC_STRING(string_I_symbol(v9221->name));
    ClairePort * v9226 = (Optimize.OPT->outfile);
    OID  v11365;
    { if (v9396->vars->length != 0)
       v11365 = (*Kernel.range)((*(v9396->vars))[1]);
      else v11365 = CNULL;
        GC_OID(v11365);} 
    if (v11365 != CNULL)
     { { ClaireBoolean * g0007I;
        { OID  v3751;
          { OID gc_local;
            ITERATE(v9211);
            v3751= Kernel.cfalse;
            bag *v9211_support;
            v9211_support = GC_OBJECT(list,Optimize.OPT->objects);
            for (START(v9211_support); NEXT(v9211);)
            if ((INHERIT(OWNER(v9211),Kernel._class)) && 
                (equal(v9211,v11365) == CTRUE))
             { v3751 = Kernel.ctrue;
              break;} 
            } 
          g0007I = boolean_I_any(v3751);
          } 
        
        if (g0007I == CTRUE) v7121= GC_STRING(string_v((*Generate.c_string)(Generate.PRODUCER->value,
            _oid_(OBJECT(ClaireClass,v11365)->name))));
          } 
      if (equal_string(v7121,string_I_symbol(ClEnv->module_I->name)) != CTRUE)
       v9226= (fopen_string(append_string(GC_STRING(append_string(GC_STRING(append_string(GC_STRING(Optimize.compiler->source),GC_STRING(string_v(Reader._starfs_star->value)))),v7121)),GC_STRING(OBJECT(Generate_producer,Generate.PRODUCER->value)->extension)),"a"));
      (Optimize.OPT->outfile = v9226);
      } 
    ;} 
  GC_UNBIND;} 

