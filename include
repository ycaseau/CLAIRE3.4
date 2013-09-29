// interface defination for module Generate, Sun Sep 29 07:16:49 2013
#ifndef CLAIREH_Generate
#define CLAIREH_Generate


class Generate_producer;
class Generate_c_producer;

class Generate_producer: public thing{ 
  public:
     list *open_comparators;
     list *open_operators;
     OID body;
     char *extension;
     char *comment;
     list *interfaces;
     int stat;} 
;

class Generate_c_producer: public Generate_producer{ 
  public:
     list *bad_names;
     list *good_names;} 
;
extern void  ident_symbol(symbol *v9396);
extern void  ident_thing(thing *v9396);
extern void  ident_class(ClaireClass *v9396);
extern void  interface_I_class(ClaireClass *v9211);
extern void  class_princ_class(ClaireClass *v9211);
extern OID  indent_c_void();
extern OID  breakline_void();
extern void  new_block_void();
extern void  close_block_void();
extern void  c_test_any(OID v9232);
extern void  c_test_method(method *v9221);
extern void  compile_module(module *v9396);
extern void  generate_files_module(module *v9396);
extern void  generate_f2f_module(module *v9221);
extern void  generate_file_string1(char *v9233,module *v9221);
extern void  generate_classes_module(module *v9396);
extern void  generate_c2f_module(module *v9396);
extern void  generate_interface_module(module *v9396,bag *v9222);
extern void  generate_objects_module(module *v9396);
extern void  generate_meta_load_module(module *v9396);
extern ClaireBoolean * global_var_def_ask_any(OID v9232);
extern ClaireClass * getRange_global_variable(global_variable *v9232);
extern void  generate_functions_module(module *v9396);
extern list * parents_module(module *v9396,list *v9222);
extern list * parents_list(list *v9396);
extern void  get_module2(module *v9221);
extern void  generate_file_string2(char *v9396,char *v7156);
extern OID  make_c_function_lambda_Generate(lambda *v9396,char *v4591,OID v9221);
extern OID  print_c_function_lambda2(lambda *v9396,char *v4591,OID v9221);
extern void  print_body_If(If *v14047,char *v12286,ClaireClass *v9233,If *v8334,ClaireBoolean *v8511);
extern void  print_body_any(OID v14047,char *v12286,ClaireClass *v9233,OID v8334,ClaireBoolean *v8511);
extern OID  print_body_Do(Do *v14047,char *v12286,ClaireClass *v9233,OID v8334,ClaireBoolean *v8511);
extern void  outer_statement_any(OID v14047,char *v12286,ClaireClass *v9233,ClaireBoolean *v8511);
extern ClaireBoolean * c_safe_any(OID v9232);
extern ClaireClass * check_sort_method(method *v9396);
extern OID  typed_args_list_list(list *v9396);
extern ClaireBoolean * need_debug_ask_any(OID v9221);
extern void  get_dependents_method(method *v9221);
extern void  c_princ_function(ClaireFunction *v9396);
extern void  set_outfile_lambda(lambda *v9396);
extern ClaireBoolean * c_func_any(OID v9396);
extern void  expression_thing(thing *v9396,OID v7180);
extern void  expression_integer(int v9396,OID v7180);
extern void  expression_any(OID v9396,OID v7180);
extern void  expression_string(char *v9396,OID v7180);
extern void  expression_float(double v9396,OID v7180);
extern void  expression_float_(OID v6626,OID v6627);
extern void  expression_boolean(ClaireBoolean *v9396,OID v7180);
extern void  expression_environment(ClaireEnvironment *v9396,OID v7180);
extern void  expression_Variable(Variable *v9396,OID v7180);
extern void  expression_global_variable(global_variable *v9396,OID v7180);
extern void  expression_Set(Set *v9396,OID v7180);
extern void  expression_set2(set *v9396,OID v7180);
extern void  expression_Tuple(Tuple *v9396,OID v7180);
extern void  expression_tuple(tuple *v9396,OID v7180);
extern void  expression_List(List *v9396,OID v7180);
extern void  expression_list(list *v9396,OID v7180);
extern void  expression_Call2(Call *v9396,OID v7180);
extern void  expression_Call_method12(Call_method1 *v9396,OID v7180);
extern void  expression_Call_method22(Call_method2 *v9396,OID v7180);
extern void  expression_Call_method2(Call_method *v9396,OID v7180);
extern void  bexpression_any(OID v9396,OID v7180);
extern void  expression_If(If *v9396,OID v7180);
extern void  expression_Assign(Assign *v9396,OID v7180);
extern void  expression_to_protect(Compile_to_protect *v9396,OID v7180);
extern void  expression_Gassign(Gassign *v9396,OID v7180);
extern void  expression_And(And *v9396,OID v7180);
extern void  expression_Or(Or *v9396,OID v7180);
extern void  expression_to_CL(Compile_to_CL *v9396,OID v7180);
extern void  expression_to_C(Compile_to_C *v9396,OID v7180);
extern void  expression_C_cast(Compile_C_cast *v9396,OID v7180);
extern void  expression_Call_slot(Call_slot *v9396,OID v7180);
extern void  expression_Call_table(Call_table *v9396,OID v7180);
extern void  expression_Call_array(Call_array *v9396,OID v7180);
extern void  expression_Update(Update *v9396,OID v7180);
extern void  sign_equal_boolean(ClaireBoolean *v9396);
extern void  sign_or_boolean(ClaireBoolean *v9396);
extern void  bool_exp_any_Generate(OID v9396,ClaireBoolean *v11731,OID v7180);
extern void  any_bool_exp_any(OID v9396,ClaireBoolean *v11731,OID v7180,ClaireBoolean *v4262);
extern void  bool_exp_to_CL_Generate(Compile_to_CL *v9396,ClaireBoolean *v11731,OID v7180);
extern void  bool_exp_If_Generate(If *v9396,ClaireBoolean *v11731,OID v7180);
extern void  bool_exp_And_Generate(And *v9396,ClaireBoolean *v11731,OID v7180);
extern void  bool_exp_Or_Generate(Or *v9396,ClaireBoolean *v11731,OID v7180);
extern void  bool_exp_Call_method1_Generate(Call_method1 *v9396,ClaireBoolean *v11731,OID v7180);
extern void  bool_exp_Call_method2_Generate(Call_method2 *v9396,ClaireBoolean *v11731,OID v7180);
extern ClaireBoolean * bool_exp_ask_any(OID v9232);
extern void  args_list_bag(bag *v9396,OID v7180,ClaireBoolean *v6830);
extern char * check_var_string(char *v9396,OID v9233,OID v7180);
extern Variable * build_Variable_string(char *v9233,OID v9231);
extern list * unfold_args_list(list *v9222);
extern ClaireType * c_type_sort_any(OID v9232);
extern OID  unfold_arg_list(list *v9222,list *v7392,OID v9232);
extern void  unfold_use_list(list *v12673,OID v9232,OID v9233,OID v7180);
extern void  statement_any(OID v9396,OID v9233,OID v7180);
extern void  self_statement_Construct(Construct *v9396,OID v9233,OID v7180);
extern void  self_statement_If(If *v9396,OID v9233,OID v7180);
extern void  self_statement_Do(Do *v9396,OID v9233,OID v7180);
extern void  inner_statement_any(OID v9396,OID v9233,OID v7180);
extern void  self_statement_Let(Let *v9396,OID v9233,OID v7180);
extern void  self_statement_And(And *v9396,OID v9233,OID v7180);
extern void  self_statement_Or(Or *v9396,OID v9233,OID v7180);
extern void  self_statement_While(While *v9396,OID v9233,OID v7180);
extern void  self_statement_Assign(Assign *v9396,OID v9233,OID v7180);
extern void  self_statement_Gassign(Gassign *v9396,OID v9233,OID v7180);
extern void  self_statement_to_protect(Compile_to_protect *v9396,OID v9233,OID v7180);
extern void  self_statement_For(For *v9396,OID v9233,OID v7180);
extern void  self_statement_Iteration(Iteration *v9396,OID v9233,OID v7180);
extern void  self_statement_Return(Return *v9396,OID v9233,OID v7180);
extern void  self_statement_Call(Call *v9396,OID v9233,OID v7180);
extern void  self_statement_Call_method(Call_method *v9396,OID v9233,OID v7180);
extern void  self_statement_Call_method1(Call_method1 *v9396,OID v9233,OID v7180);
extern void  self_statement_Call_method2(Call_method2 *v9396,OID v9233,OID v7180);
extern void  self_statement_Super(Super *v9396,OID v9233,OID v7180);
extern void  self_statement_Cast(Cast *v9396,OID v9233,OID v7180);
extern void  self_statement_Handle(ClaireHandle *v9396,OID v9233,OID v7180);
extern void  self_statement_to_CL(Compile_to_CL *v9396,OID v9233,OID v7180);
extern void  self_statement_to_C(Compile_to_C *v9396,OID v9233,OID v7180);
extern void  self_statement_C_cast(Compile_C_cast *v9396,OID v9233,OID v7180);
extern void  self_statement_Call_slot(Call_slot *v9396,OID v9233,OID v7180);
extern void  self_statement_Call_table(Call_table *v9396,OID v9233,OID v7180);
extern void  self_statement_Call_array(Call_array *v9396,OID v9233,OID v7180);
extern void  self_statement_Update(Update *v9396,OID v9233,OID v7180);
extern char * c_string_c_producer1(Generate_c_producer *v9211,Variable *v9396);
extern char * c_string_c_producer2(Generate_c_producer *v9211,symbol *v9396);
extern char * string_I_c_producer1(Generate_c_producer *v9211,Variable *v9396);
extern char * string_I_c_producer2(Generate_c_producer *v9211,symbol *v9396);
extern void  ident_c_producer3(Generate_c_producer *v9211,Variable *v9236);
extern void  ident_c_producer(Generate_c_producer *v9211,symbol *v9233);
extern void  class_princ_c_producer(Generate_c_producer *v9211,ClaireClass *v9396);
extern void  produce_c_producer2(Generate_c_producer *v9211,OID v9232);
extern void  globalVar_c_producer(Generate_c_producer *v9211,global_variable *v9232);
extern void  stat_exp_c_producer(Generate_c_producer *v9211,OID v9396,OID v7180);
extern void  namespace_I_c_producer(Generate_c_producer *v9211,module *v9221);
extern void  module_I_c_producer(Generate_c_producer *v9211,module *v9221);
extern void  declare_c_producer(Generate_c_producer *v9211,property *v9226);
extern void  start_module_interface_c_producer(Generate_c_producer *v9211,module *v9396);
extern void  end_module_interface_c_producer(Generate_c_producer *v9211,module *v9396);
extern void  generate_end_file_c_producer(Generate_c_producer *v9218,module *v9221);
extern void  generate_classes_c_producer(Generate_c_producer *v9218,char *v9233,module *v9221);
extern void  generate_start_file_c_producer(Generate_c_producer *v9211,module *v9221);
extern void  generate_meta_load_c_producer(Generate_c_producer *v9211,module *v9221);
extern OID  start_file_string(char *v9233,module *v9221);
extern void  define_variable_c_producer2(Generate_c_producer *v9211,ClaireClass *v9231,char *v9236);
extern void  generate_profile_c_producer(Generate_c_producer *v9211,OID v9221);
extern void  generate_interface_c_producer(Generate_c_producer *v9211,module *v9396);
extern void  global_var_def_I_c_producer(Generate_c_producer *v9211,module *v9396,Let *v9232);
extern void  gc_introduction_c_producer(Generate_c_producer *v9211,OID v5189);
extern OID  gc_usage_any(OID v9396,ClaireBoolean *v7180);
extern OID  gc_or_any(OID v9232,OID v9235);
extern OID  gc_usage_star_list(list *v9222,ClaireBoolean *v7180);
extern void  debug_intro_c_producer(Generate_c_producer *v9211,lambda *v9396,method *v9232);
extern char * protect_result_c_producer(Generate_c_producer *v9211,ClaireClass *v9233,ClaireBoolean *v1532,OID v9232);
extern void  generate_function_start_c_producer(Generate_c_producer *v9211,lambda *v9396,ClaireClass *v9233,OID v9221,char *v4591);
extern void  generate_regular_function_c_producer(Generate_c_producer *v9211,lambda *v9396,ClaireFunction *v5193,ClaireClass *v9233,OID v9221,list *v7411);
extern void  generate_float_function_c_producer(Generate_c_producer *v9211,method *v9221,char *v4591);
extern void  at_c_producer(Generate_c_producer *v9211);
extern void  generate_tuple_function_c_producer(Generate_c_producer *v9211,method *v9221,char *v4591);
extern OID  create_function_entry_c_producer(Generate_c_producer *v9211,lambda *v7390,char *v5193,OID v9221);
extern OID  update_function_entry_c_producer(Generate_c_producer *v9211,ClaireFunction *v5193,list *v7411,ClaireClass *v9233);
extern char * c_interface_class1_Generate(ClaireClass *v9396);
extern void  c_interface_class2_Generate(ClaireClass *v9396,char *v9233);
extern void  c_interface_method_Generate(method *v9396);
extern void  interface_I_c_producer(Generate_c_producer *v9211,ClaireClass *v9396);
extern void  to_cl_c_producer(Generate_c_producer *v9211,OID v9232,ClaireClass *v9233,OID v7180);
extern void  to_c_c_producer1(Generate_c_producer *v9211,OID v9232,ClaireClass *v9233,OID v7180);
extern void  to_c_c_producer2(Generate_c_producer *v9211,ClaireClass *v9233);
extern void  public_static_c_producer(Generate_c_producer *v9211);
extern void  bool_exp_I_c_producer(Generate_c_producer *v9211,OID v9396,OID v7180);
extern void  inherit_exp_c_producer(Generate_c_producer *v9211,OID v7000,OID v7002,OID v7180);
extern void  bitvector_exp_c_producer(Generate_c_producer *v9211,OID v7000,OID v7002,OID v7180);
extern void  equal_exp_c_producer(Generate_c_producer *v9211,OID v7000,ClaireBoolean *v11731,OID v7002,OID v13340);
extern ClaireBoolean * char_exp_ask_c_producer2(Generate_c_producer *v9211,OID v9232);
extern void  char_exp_c_producer2(Generate_c_producer *v9211,OID v9232,OID v7180);
extern void  c_member_c_producer(Generate_c_producer *v9211,OID v9396,ClaireClass *v9233,property *v9232,OID v7180);
extern void  addFast_c_producer(Generate_c_producer *v9211);
extern void  cast_I_c_producer(Generate_c_producer *v9211,Compile_C_cast *v9396,OID v7180);
extern void  gc_protection_exp_c_producer(Generate_c_producer *v9211,Variable *v9236,ClaireBoolean *v3883,OID v9234,OID v7180);
extern void  bag_expression_c_producer(Generate_c_producer *v7133,ClaireClass *v9211,bag *v9222,ClaireType *v9231,OID v7180);
extern void  generate_s_file_string(char *v9396,list *v9222,OID v9221);
extern void  create_load_modules_string(char *v9396,ClairePort *v9226,list *v212,OID v9221);
extern void  methods_interface_c_producer(Generate_c_producer *v9211,ClaireClass *v9232);
extern void  methods_bodies_c_producer(Generate_c_producer *v9211,ClaireClass *v9232);
extern void  inline_exp_c_producer1(Generate_c_producer *v9211,Call_method1 *v9396,OID v7180);
extern void  inline_exp_c_producer2(Generate_c_producer *v9211,Call_method2 *v9396,OID v7180);
extern void  inline_exp_c_producer3(Generate_c_producer *v9211,Call_method *v9396,OID v7180);
extern void  print_external_call_c_producer(Generate_c_producer *v9211,Call_method *v9396,OID v7180);
extern void  inline_exp_c_producer5(Generate_c_producer *v9211,Call *v9396,OID v7180);
extern ClaireBoolean * fcall_ask_Call2_Generate(Call *v9232);
extern list * get_restrictions_Call2(Call *v9232,list *v7408);
extern void  fcall_exp_Call2_Generate(Call *v9232,OID v7180);
extern void  c_sorted_arg_any(OID v9232,ClaireClass *v9233,OID v7180,ClaireBoolean *v14460);
extern void  c_sorted_args_Call(Call *v9232,list *v7407,OID v7180,ClaireBoolean *v14460);
extern void  bitvector_I_c_producer(Generate_c_producer *v9211,OID v9232);
extern void  bitvectorSum_integer(int v9232);
extern void  signature_I_c_producer(Generate_c_producer *v9211,OID v9232);
extern OID  getC_any(OID v9232);
extern void  gassign_c_producer(Generate_c_producer *v9211,Gassign *v9396,OID v7180);
extern void  call_slot_c_producer(Generate_c_producer *v9211,Call_slot *v9396,OID v7180);
extern void  call_table_c_producer(Generate_c_producer *v9211,Call_table *v9396,OID v7180);
extern void  call_array_c_producer(Generate_c_producer *v9211,Call_array *v9396,OID v7180);
extern void  update_c_producer(Generate_c_producer *v9211,Update *v9396,OID v7180);
extern void  object_test_c_producer(Generate_c_producer *v9211,OID v7000,ClaireBoolean *v11731,OID v7180);
extern void  exp_to_protect_c_producer(Generate_c_producer *v9211,Compile_to_protect *v9396,OID v7180);
extern char * gc_protect_class(ClaireClass *v9211);
extern void  macro_c_producer(Generate_c_producer *v9211);
extern void  init_var_c_producer(Generate_c_producer *v9211,ClaireClass *v9233);
extern void  any_interface_c_producer(Generate_c_producer *v9211);
extern void  pointer_cast_c_producer(Generate_c_producer *v9211,ClaireClass *v9233);
extern void  exp_Assign_c_producer(Generate_c_producer *v9211,Assign *v9396,OID v7180);
extern void  stat_handle_c_producer(Generate_c_producer *v9211,ClaireHandle *v9396,OID v9233,OID v7180);
extern void  stat_construct_c_producer(Generate_c_producer *v9211,Construct *v9396,OID v9233,OID v7180);
extern void  stat_while_c_producer(Generate_c_producer *v9211,While *v9396,OID v9233,OID v7180);
extern void  stat_gassign_c_producer(Generate_c_producer *v9211,Gassign *v9396,OID v9233,OID v7180);
extern void  stat_for_c_producer(Generate_c_producer *v9211,For *v9396,OID v9233,OID v7180);
extern void  stat_iteration_c_producer(Generate_c_producer *v9211,Iteration *v9396,OID v9233,OID v7180);
extern void  stat_super_c_producer(Generate_c_producer *v9211,Super *v9396,OID v9233,OID v7180);
extern void  stat_let_c_producer(Generate_c_producer *v9211,Let *v9396,OID v9233,OID v7180);

// namespace class for Generate 
class GenerateClass: public NameSpace {
public:

global_variable * _star_ask_interval_star;
global_variable * _star_dash_dash_integer_star;
global_variable * _star_plus_integer_star;
global_variable * _starnth_integer_star;
global_variable * _starnth_list_star;
global_variable * _starnth_1_bag_star;
global_variable * _starnth_string_star;
global_variable * _starnth_1_string_star;
global_variable * _starnth_equal_list_star;
global_variable * _starnot_star;
global_variable * _starknown_star;
global_variable * _starunknown_star;
global_variable * _starnot_equal_star;
global_variable * _starcontain_star;
global_variable * _starmin_integer_star;
global_variable * _starmax_integer_star;
global_variable * _starlength_array_star;
global_variable * _starlength_bag_star;
global_variable * _starclose_exception_star;
ClaireClass * _producer;
global_variable * PRODUCER;
table * classFile;
global_variable * WrongMethod;
ClaireClass * _c_producer;
Generate_c_producer * C_plus_plusPRODUCER;
property * fcall_ask;
property * fcall_exp;
global_variable * FCLimit;
global_variable * FCALLSTINKS;
global_variable * bitvectorList;
property * open_comparators;// Generate/"open_comparators"
property * open_operators;// Generate/"open_operators"
property * extension;// Generate/"extension"
property * interfaces;// Generate/"interfaces"
property * interface_I;// Generate/"interface!"
property * indent_c;// Generate/"indent_c"
property * breakline;// Generate/"breakline"
property * new_block;// Generate/"new_block"
property * close_block;// Generate/"close_block"
property * c_test;// claire/"c_test"
property * c_func;// Compile/"c_func"
property * expression;// Generate/"expression"
property * statement;// Generate/"statement"
property * compile;// claire/"compile"
property * parents;// Generate/"parents"
property * outmodule;// Generate/"outmodule"
property * generate_files;// Generate/"generate_files"
property * generate_classes;// Generate/"generate_classes"
property * generate_c2f;// Generate/"generate_c2f"
property * generate_f2f;// Generate/"generate_f2f"
property * generate_interface;// Generate/"generate_interface"
property * start_module_interface;// Generate/"start_module_interface"
property * generate_file;// Generate/"generate_file"
property * start_file;// Generate/"start_file"
property * generate_meta_load;// Generate/"generate_meta_load"
property * generate_start_file;// Generate/"generate_start_file"
property * generate_functions;// Generate/"generate_functions"
property * generate_objects;// Generate/"generate_objects"
property * generate_end_file;// Generate/"generate_end_file"
property * typed_args_list;// Generate/"typed_args_list"
property * namespace_I;// Generate/"namespace!"
property * public_static;// Generate/"public_static"
property * declare;// Generate/"declare"
property * print_c_function;// Generate/"print_c_function"
property * create_function_entry;// Generate/"create_function_entry"
property * check_sort;// Generate/"check_sort"
property * protect_result;// Generate/"protect_result"
property * need_debug_ask;// Generate/"need_debug?"
property * set_outfile;// Generate/"set_outfile"
property * generate_profile;// Generate/"generate_profile"
property * debug_intro;// Generate/"debug_intro"
property * inner_statement;// Generate/"inner_statement"
property * update_function_entry;// Generate/"update_function_entry"
property * get_dependents;// Generate/"get_dependents"
property * produce;// Generate/"produce"
property * at;// Generate/"at"
property * bag_expression;// Generate/"bag_expression"
property * inline_exp;// Generate/"inline_exp"
property * gc_protection_exp;// Generate/"gc_protection_exp"
property * exp_to_protect;// Generate/"exp_to_protect"
property * gc_protect;// Generate/"gc_protect"
property * gassign;// Generate/"gassign"
property * to_cl;// Generate/"to_cl"
property * to_c;// Generate/"to_c"
property * call_slot;// Generate/"call_slot"
property * call_table;// Generate/"call_table"
property * call_array;// Generate/"call_array"
property * update;// Generate/"update"
property * sign_equal;// Generate/"sign_equal"
property * sign_or;// Generate/"sign_or"
property * macro;// Generate/"macro"
property * equal_exp;// Generate/"equal_exp"
property * object_test;// Generate/"object_test"
property * bitvector_exp;// Generate/"bitvector_exp"
property * inherit_exp;// Generate/"inherit_exp"
property * args_list;// Generate/"args_list"
property * check_var;// Generate/"check_var"
property * build_Variable;// Generate/"build_Variable"
property * unfold_args;// Generate/"unfold_args"
property * c_type_sort;// Generate/"c_type_sort"
property * unfold_arg;// Generate/"unfold_arg"
property * unfold_use;// Generate/"unfold_use"
property * self_statement;// Generate/"self_statement"
property * stat_construct;// Generate/"stat_construct"
property * init_var;// Generate/"init_var"
property * stat_while;// Generate/"stat_while"
property * stat_gassign;// Generate/"stat_gassign"
property * stat_for;// Generate/"stat_for"
property * stat_iteration;// Generate/"stat_iteration"
property * stat_super;// Generate/"stat_super"
property * stat_handle;// Generate/"stat_handle"
property * any_interface;// Generate/"any_interface"
property * pointer_cast;// Generate/"pointer_cast"
property * bad_names;// Generate/"bad_names"
property * good_names;// Generate/"good_names"
property * generate_float_function;// Generate/"generate_float_function"
property * generate_regular_function;// Generate/"generate_regular_function"
property * bitvectorSum;// Generate/"bitvectorSum"
property * c_member;// Generate/"c_member"
property * addFast;// Generate/"addFast"
property * print_external_call;// Generate/"print_external_call"
property * getC;// Generate/"getC"
property * signature_I;// Generate/"signature!"
property * bitvector_I;// Generate/"bitvector!"
property * get_restrictions;// Generate/"get_restrictions"
property * c_sorted_args;// Generate/"c_sorted_args"
property * c_sorted_arg;// Generate/"c_sorted_arg"
property * generate_function_start;// Generate/"generate_function_start"
property * print_body;// Generate/"print_body"
property * c_safe;// Generate/"c_safe"
property * outer_statement;// Generate/"outer_statement"
property * methods_interface;// Generate/"methods_interface"
property * methods_bodies;// Generate/"methods_bodies"
property * gc_introduction;// Generate/"gc_introduction"
property * gc_usage;// Generate/"gc_usage"
property * gc_usage_star;// Generate/"gc_usage*"
property * gc_or;// Generate/"gc_or"
property * stat_exp;// Generate/"stat_exp"
property * define_variable;// Generate/"define_variable"
property * char_exp_ask;// Generate/"char_exp?"
property * char_exp;// Generate/"char_exp"
property * bool_exp_ask;// Generate/"bool_exp?"
property * bool_exp_I;// Generate/"bool_exp!"
property * bexpression;// Generate/"bexpression"
property * end_module_interface;// Generate/"end_module_interface"
property * stat_let;// Generate/"stat_let"
property * exp_Assign;// Generate/"exp_Assign"
property * generate_tuple_function;// Generate/"generate_tuple_function"
property * generate_s_file;// Generate/"generate_s_file"
property * create_load_modules;// Generate/"create_load_modules"
property * global_var_def_ask;// Generate/"global_var_def?"
property * global_var_def_I;// Generate/"global_var_def!"
property * getRange;// Generate/"getRange"
property * globalVar;// Generate/"globalVar"
property * c_string;// Generate/"c_string"
property * any_bool_exp;// Generate/"any_bool_exp"
property * class_princ;// Generate/"class_princ"

// module definition 
 void metaLoad();};

extern GenerateClass Generate;
extern NameSpace Compile;
extern NameSpace iClaire;

#endif
