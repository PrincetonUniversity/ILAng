/// \file CHC Invariant Input Parsing
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/smt-inout/chc_inv_in.h>
#include <ilang/smt-inout/chc_inv_callback_fn.h>

#include <fstream>
#include <cstdio>

namespace ilang {
namespace smt {


// -------------- SmtlibInvariantParser ---------------- //

// we need to make sure this variable is shared
// and it is globally unique... so when invoking
// we can won't have multiple var with the same name
unsigned SmtlibInvariantParser::local_var_idx = 0;

SmtlibInvariantParser::SmtlibInvariantParser(YosysSmtParser * yosys_smt_info,
  bool _flatten_datatype, bool _flatten_hierarchy,
  const std::set<std::string> & _inv_pred_name,
  const std::string & dut_instance_name,
  bool discourageOutOfScopeVariable) :

  parser_wrapper(new smtlib2_abstract_parser_wrapper()),
  inv_pred_name(_inv_pred_name),
  dut_verilog_instance_name(dut_instance_name),
  design_smt_info_ptr(yosys_smt_info),
  datatype_flattened(_flatten_datatype), hierarchy_flattened(_flatten_hierarchy),
  no_outside_var_refer(discourageOutOfScopeVariable),
  _bad_state(false) {
  
  ILA_NOT_NULL(yosys_smt_info);
  // the first element's address should be the outer structure's address
  ILA_ASSERT(((void *) parser_wrapper) ==  ((void *) &(parser_wrapper->parser) )  );

  if (not parser_wrapper) {
    _bad_state = true;
    ILA_ERROR << "SMT-LIB2 parser construct allocation failed!";
    return;
  }
  // the be
  smtlib2_abstract_parser_init((smtlib2_abstract_parser *)parser_wrapper,
                                 (smtlib2_context)parser_wrapper);

  smtlib2_parser_interface *pi;
  smtlib2_term_parser *tp;

  parser_wrapper->inv_parser = this;
  /* initialize the term parser and override virtual methods */
  pi = &(parser_wrapper->parser.parent_);
  // pi->set_logic = smtlib2_yices_parser_set_logic;
  // pi->declare_sort = smtlib2_yices_parser_declare_sort;
  // pi->declare_function = smtlib2_yices_parser_declare_function;
  // pi->define_function = smtlib2_yices_parser_define_function;
  // pi->push = smtlib2_yices_parser_push;
  // pi->pop = smtlib2_yices_parser_pop;
  // pi->assert_formula = smtlib2_yices_parser_assert_formula;
  // pi->check_sat = smtlib2_yices_parser_check_sat;
  // pi->annotate_term = smtlib2_yices_parser_annotate_term;
  // pi->set_int_option = smtlib2_yices_parser_set_int_option;
  // pi->get_unsat_core = smtlib2_yices_parser_get_unsat_core;
  // pi->get_assignment = smtlib2_yices_parser_get_assignment;
  // pi->get_value = smtlib2_yices_parser_get_value;
  // pi->make_sort = smtlib2_yices_parser_make_sort;
  // pi->make_function_sort = smtlib2_yices_parser_make_function_sort;
  // pi->make_parametric_sort = smtlib2_yices_parser_make_parametric_sort;
  // pi->define_sort = smtlib2_yices_parser_define_sort;
  // ---------------------------------------------------------
  // pi->push_let_scope = ; pop_let_scope; push_quantifier_scope; pop_quantifier_scope
  // smtlib2_term_parser_push_let_scope // handles automatically
  // smtlib2_term_parser_pop_let_scope // handles automatically
  // smtlib2_abstract_parser_push_quantifier_scope : do nothing
  // smtlib2_abstract_parser_pop_quantifier_scope : do nothing
  // 
  // forall (A ())  make_sort -- declare_variable  -- push_quantifier_scope
  //
  //
  pi->assert_formula = proxy_assert_formula;
  pi->define_function = proxy_define_func;
  pi->make_forall_term = proxy_make_forall_term;
  pi->make_exists_term = proxy_make_exists_term;
  pi->push_quantifier_scope = proxy_push_quantifier_scope;
  pi->pop_quantifier_scope  = proxy_pop_quantifier_scope;
  pi->make_sort = proxy_make_sort;
  pi->declare_variable = proxy_declare_variable;
  pi->declare_function = proxy_declare_function;
  pi->check_sat = proxy_check_sat;

  tp = parser_wrapper->parser.termparser_; // internal allocated already

  // call back function to apply an uninterpreted function
  // fall through case for handler (operator) 
  smtlib2_term_parser_set_function_handler(tp,
                                             proxy_mk_function);
  smtlib2_term_parser_set_number_handler(tp,
                                           proxy_mk_number);

  smtlib2_term_parser_set_handler(tp, "and", smt_to_vlg_mk_and); // you need to carry something ...
  smtlib2_term_parser_set_handler(tp, "or",  smt_to_vlg_mk_or);
  smtlib2_term_parser_set_handler(tp, "not", smt_to_vlg_mk_not);
  smtlib2_term_parser_set_handler(tp, "=>",  smt_to_vlg_mk_implies);
  smtlib2_term_parser_set_handler(tp, "=",   smt_to_vlg_mk_eq);
  smtlib2_term_parser_set_handler(tp, "ite", smt_to_vlg_mk_ite);
  smtlib2_term_parser_set_handler(tp, "xor", smt_to_vlg_mk_xor);
  smtlib2_term_parser_set_handler(tp, "nand",smt_to_vlg_mk_nand);
  // should we do this?
  smtlib2_term_parser_set_handler(tp, "true", smt_to_vlg_mk_true);
  smtlib2_term_parser_set_handler(tp, "false",smt_to_vlg_mk_false);

  smtlib2_term_parser_set_handler(tp, "concat",smt_to_vlg_mk_concat);
  smtlib2_term_parser_set_handler(tp, "bvnot", smt_to_vlg_mk_bvnot);
  smtlib2_term_parser_set_handler(tp, "bvand", smt_to_vlg_mk_bvand);
  smtlib2_term_parser_set_handler(tp, "bvnand",smt_to_vlg_mk_bvnand);
  smtlib2_term_parser_set_handler(tp, "bvor",  smt_to_vlg_mk_bvor);
  smtlib2_term_parser_set_handler(tp, "bvnor", smt_to_vlg_mk_bvnor);
  smtlib2_term_parser_set_handler(tp, "bvxor", smt_to_vlg_mk_bvxor);
  smtlib2_term_parser_set_handler(tp, "bvxnor",smt_to_vlg_mk_bvxnor);
  smtlib2_term_parser_set_handler(tp, "bvult", smt_to_vlg_mk_bvult);
  smtlib2_term_parser_set_handler(tp, "bvslt", smt_to_vlg_mk_bvslt);
  smtlib2_term_parser_set_handler(tp, "bvule", smt_to_vlg_mk_bvule);
  smtlib2_term_parser_set_handler(tp, "bvsle", smt_to_vlg_mk_bvsle);
  smtlib2_term_parser_set_handler(tp, "bvugt", smt_to_vlg_mk_bvugt);
  smtlib2_term_parser_set_handler(tp, "bvsgt", smt_to_vlg_mk_bvsgt);
  smtlib2_term_parser_set_handler(tp, "bvuge", smt_to_vlg_mk_bvuge);
  smtlib2_term_parser_set_handler(tp, "bvsge", smt_to_vlg_mk_bvsge);
  smtlib2_term_parser_set_handler(tp, "bvcomp",smt_to_vlg_mk_bvcomp);
  smtlib2_term_parser_set_handler(tp, "bvneg", smt_to_vlg_mk_bvneg);
  smtlib2_term_parser_set_handler(tp, "bvadd", smt_to_vlg_mk_bvadd);
  smtlib2_term_parser_set_handler(tp, "bvsub", smt_to_vlg_mk_bvsub);
  smtlib2_term_parser_set_handler(tp, "bvmul", smt_to_vlg_mk_bvmul);
  smtlib2_term_parser_set_handler(tp, "bvudiv",smt_to_vlg_mk_bvudiv);
  smtlib2_term_parser_set_handler(tp, "bvsdiv",smt_to_vlg_mk_bvsdiv);
  smtlib2_term_parser_set_handler(tp, "bvsmod",smt_to_vlg_mk_bvsmod);
  smtlib2_term_parser_set_handler(tp, "bvurem",smt_to_vlg_mk_bvurem);
  smtlib2_term_parser_set_handler(tp, "bvsrem",smt_to_vlg_mk_bvsrem);
  smtlib2_term_parser_set_handler(tp, "bvshl", smt_to_vlg_mk_bvshl);
  smtlib2_term_parser_set_handler(tp, "bvlshr",smt_to_vlg_mk_bvlshr);
  smtlib2_term_parser_set_handler(tp, "bvashr",smt_to_vlg_mk_bvashr);
  smtlib2_term_parser_set_handler(tp, "extract",     smt_to_vlg_mk_extract);
  smtlib2_term_parser_set_handler(tp, "bit2bool",    smt_to_vlg_mk_bit2bool);
  smtlib2_term_parser_set_handler(tp, "repeat",      smt_to_vlg_mk_repeat);
  smtlib2_term_parser_set_handler(tp, "zero_extend", smt_to_vlg_mk_zero_extend);
  smtlib2_term_parser_set_handler(tp, "sign_extend", smt_to_vlg_mk_sign_extend);
  smtlib2_term_parser_set_handler(tp, "rotate_left", smt_to_vlg_mk_rotate_left);
  smtlib2_term_parser_set_handler(tp, "rotate_right",smt_to_vlg_mk_rotate_right);
  
  mask = 0xdeadbeaf;
}


SmtlibInvariantParser::~SmtlibInvariantParser() {
  if(parser_wrapper) {
    smtlib2_abstract_parser_deinit(&(parser_wrapper->parser));
    delete parser_wrapper;
  }
}

bool SmtlibInvariantParser::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state) << "SmtlibInvariantParser is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return


std::string SmtlibInvariantParser::get_a_new_local_var_name() {
  return "__INV_EXT_new_local_var_"+std::to_string(local_var_idx++)+"__";
}


/// this function receives the final assert result
void SmtlibInvariantParser::assert_formula(SmtTermInfoVlgPtr result) {
  final_translate_result = result->_translate;
}

/// declare function (useful for FreqHorn)
void SmtlibInvariantParser::declare_function(const std::string &name, var_type * sort) {
  ILA_ASSERT(false)<<"Bug: CHC solver should not generate output containing declare-fun!";
}

void SmtlibInvariantParser::define_function(const std::string &func_name, 
    const std::vector<SmtTermInfoVlgPtr> & args, var_type * ret_type,
    SmtTermInfoVlgPtr func_body) {
  
  ILA_ASSERT(false)<<"Bug: CHC solver should not generate output containing define-fun!";
  // we expect the forall style // for SyGuS, it is the opposite
} // define_function

/// call back function to handle (forall
SmtTermInfoVlgPtr SmtlibInvariantParser::push_quantifier_scope() {
  quantifier_def_stack.push_back(quantifier_temp_def_t());
  quantifier_var_def_idx_stack.push_back(0);
  return nullptr; // no body cares this
}
/// call back function to handle ) of forall
SmtTermInfoVlgPtr SmtlibInvariantParser::pop_quantifier_scope() {
  quantifier_def_stack.pop_back();
  quantifier_var_def_idx_stack.pop_back();
  return nullptr; // if we return null, it will not overwrite the make_forall_term result
}

/// call back function to create a sort
var_type * SmtlibInvariantParser::make_sort(const std::string &name, const std::vector<int> & idx) {
  //ILA_ASSERT(not quantifier_def_stack.empty());
  //ILA_ASSERT(not quantifier_var_def_idx_stack.empty());
  ILA_ASSERT(mask == 0xdeadbeaf);
  if (datatype_flattened) {
    // should should only be BitVec or Bool
    if (name == "Bool") {
      if (not IN("Bool", sort_container))
        sort_container.insert(std::make_pair(std::string("Bool"),
          var_type(var_type::tp::Bool, 1, "")));
      return & (sort_container["Bool"]);
    }
    else if (name == "BitVec") {
      ILA_ASSERT(idx.size() == 1);
      ILA_ASSERT(idx[0] > 0);
      std::string sortIdxName = "BV"+std::to_string(idx[0]);
      if (not IN(sortIdxName, sort_container))
        sort_container.insert(std::make_pair(sortIdxName,
          var_type(var_type::tp::BV, idx[0], "")));
      return & (sort_container[sortIdxName]);
    }
    ILA_ASSERT(false) << "Unknown sort:" << name << " in flattened smt.";
    return nullptr; // should not be reachable
  } else {
    // if not flattened, there should only be one sort
    const auto & module_def_order = design_smt_info_ptr->get_module_def_orders();

    std::string top_module = module_def_order.back();
    std::string top_module_sort;
    ILA_DLOG("SmtlibInvariantParser.make_sort") << top_module << std::endl;
    top_module_sort = top_module + std::string("_s");
    ILA_DLOG("SmtlibInvariantParser.make_sort") << top_module_sort << std::endl;

    ILA_ASSERT(name == top_module_sort || name == "|"+top_module_sort+"|") 
      << "Unknown sort:" << name << " in unflattened smt."
      << " Expecting:" << top_module_sort;
    
    if (not IN(top_module_sort, sort_container))
      sort_container.insert(std::make_pair(top_module_sort,
        var_type(var_type::tp::Datatype, 0, top_module)));
    return & (sort_container[top_module_sort]);
  }
} // make_sort

/// call back function to create a temporary (quantified variable)
// for the flattened-datatype, this should be the same as the datatype order
// 
void SmtlibInvariantParser::declare_quantified_variable(const std::string &name, var_type * sort ) {
  // check on the name part
  ILA_ASSERT(mask == 0xdeadbeaf);
  ILA_ASSERT(not quantifier_def_stack.empty());
  ILA_ASSERT(not quantifier_var_def_idx_stack.empty());
  // I assume it has nothing to do with hierarchy flattening
  auto & top = quantifier_def_stack.back();
  if (datatype_flattened) {
    // we need to extract the name from verilog
    auto top_module = design_smt_info_ptr->get_module_def_orders().back();
    auto vlg_name = ( 
      design_smt_info_ptr->get_module_flatten_dt(top_module)
      [quantifier_var_def_idx_stack.back()])
      .verilog_name;

    top.insert(std::make_pair(name,
      SmtTermInfoVerilog(vlg_name,*sort,this)));

    quantifier_var_def_idx_stack.back() ++;
  } else {
    // if not flattened, there should only be one sort
    top.insert(std::make_pair(name,
      SmtTermInfoVerilog("",*sort,this))); // itself could not be translated
    ILA_DLOG("SmtlibInvariantParser.declare_quantified_variable") << "make var :" << name << std::endl;
  }
}

SmtTermInfoVlgPtr SmtlibInvariantParser::search_quantified_var_stack(const std::string & name) {

  ILA_ASSERT(mask == 0xdeadbeaf);
  ILA_DLOG("SmtlibInvariantParser.search_var") << "Begin search var:"<<name<<std::endl;
  for (auto mp_pos = quantifier_def_stack.rbegin(); 
    mp_pos != quantifier_def_stack.rend(); ++ mp_pos) { // search from the closest binding
    if (IN(name,(*mp_pos) ))
      return & ( (*mp_pos) [name] );
  }
  ILA_DLOG("SmtlibInvariantParser.search_var") << "Not found var:"<<name<<std::endl;
  return nullptr;
} // search_quantified_var_stack


/// call back function to apply an uninterpreted function
/// fall-through case if it is not an defined op, if failed, return NULL
/// for unflattened-hierarchy: this should be the place where things are called
/// it could be directly the (pred state)
/// or (pred (pred state)) ... you need to pass the right instance name allow side
SmtTermInfoVlgPtr SmtlibInvariantParser::mk_function(
  const std::string &name, var_type * sort, 
  const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args) {
  // we don't really rely on the sort here: actually it should be NULL
  ILA_DLOG("SmtlibInvariantParser.mk_function") << "make func:" << name << ", #arg" << args.size() << std::endl;
  if (args.empty() and idx.empty()) {
    // first let's check if it is referring to a quantifier-bound variable
    auto term_ptr = search_quantified_var_stack(name);
    if (term_ptr)
      return term_ptr;
    ILA_ASSERT(false) << "unknown symbol:"<<name;
    return nullptr; // no use
  }
  // if it is function call
  if (datatype_flattened) {
    if(IN(name, inv_pred_name))
      return mk_true("true",NULL,{},{});
    ILA_ASSERT(false) << "Fun:" << name <<" called in flattened smt.";
    return nullptr; // should not be reachable
  }
  else {
    ILA_ASSERT(args.size() == 1);
    ILA_ASSERT(args[0]->_type._type == var_type::tp::Datatype);

    if(IN(name, inv_pred_name))
      return mk_true("true",NULL,{},{});

    // get it from the module_name
    const auto & module_name = args[0]->_type.module_name;
    const auto & dts = design_smt_info_ptr->get_module_flatten_dt(module_name);
    for (auto && dt : dts) {
      if (dt.internal_name == name || dt.internal_name == "|"+name+"|" ) {
        // make the new variable here
        std::string search_name;
        if (dt._type._type == var_type::tp::Bool)
          search_name = "##bool_";
        else if (dt._type._type == var_type::tp::BV)
          search_name = "##bv" + std::to_string(dt._type._width) + "_";
        else
          ILA_ASSERT(false) << "unexpected type!";

        search_name += dt.verilog_name;
        auto repl_name = dt.verilog_name;
        // here we need to make sure it is a good name
        if (! dut_verilog_instance_name.empty() && no_outside_var_refer) {
          auto dot_pos = dt.verilog_name.find('.');
          if(dot_pos != std::string::npos and 
             dt.verilog_name.substr(0,dot_pos) != dut_verilog_instance_name) {
            
            repl_name = ReplaceAll(dt.verilog_name, ".", "_dot_");
            ILA_ERROR_IF(IN(repl_name, free_vars))
              << "Bug free var name reappearing: " << repl_name;
            // not possible for datatype here
            int width = dt._type._type == var_type::tp::BV ? dt._type._width : 1;
            free_vars.insert(std::make_pair(repl_name,  width ));

            ILA_ERROR << "Invariant refers to out-of-scope var : " << dt.verilog_name
              << " replaced w. " << repl_name;
          } else if (dot_pos == std::string::npos) {
            ILA_ERROR << "Invariant refers to wrapper var: " << dt.verilog_name;
          }
        } // check out-of-scope name

        if(not IN(search_name, term_container)) {
          term_container.insert(std::make_pair(search_name,
            SmtTermInfoVerilog(repl_name, dt._type ,this)));
        }
        return & ( term_container[search_name] );
      } // if name matched
    } // for all datatypes
    ILA_ASSERT(false) << "unknown symbol:"<<name;
    return nullptr; // should not be reachable
  } // end of else 
} // mk_function


/// call back function to make a number term
SmtTermInfoVlgPtr SmtlibInvariantParser::mk_number(const std::string & rep, int width, int base) {
  ILA_ASSERT(width > 0) << "Unable to translate Integer!";
  char radix;
  switch(base){
    case 2: radix = 'b'; break;
    case 10: radix = 'd'; break;
    case 16: radix = 'h'; break;
    default: ILA_ASSERT(false) << "unable to handle base:" << base;
  }
  std::string vlg_expr = std::to_string(width)+"'"+radix+rep;
  std::string name = "##bv" + vlg_expr;
  if (not IN(name, term_container)) {
    term_container.insert( std::make_pair( name, 
      SmtTermInfoVerilog(
        vlg_expr , 
        var_type ( var_type::tp::BV , width, ""), 
        this ) ) );
  }
  // return the reference from the container
  return & ( term_container[name] );
} // mk_number

#include <ilang/smt-inout/smt_op.h>

#define DEFINE_OPERATOR(name) \
  SmtTermInfoVlgPtr SmtlibInvariantParser::mk_##name( \
    const std::string & symbol, var_type * sort, \
    const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args) 

DEFINE_OPERATOR(true) {
  CHECK_EMPTY_PARAM(idx,args);
  MAKE_BOOL_RESULT(std::string("1'b1"));
}

DEFINE_OPERATOR(false) {
  CHECK_EMPTY_PARAM(idx,args);
  MAKE_BOOL_RESULT(std::string("1'b0"));
}

DEFINE_OPERATOR(and) {
  CHECK_BOOL_MULTI_ARG(idx,args);
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr,args,var_type::tp::Bool, "&&");
  MAKE_BOOL_RESULT(vlg_expr);
}

DEFINE_OPERATOR(or) {
  CHECK_BOOL_MULTI_ARG(idx,args);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr,args,var_type::tp::Bool, "||");
  MAKE_BOOL_RESULT(vlg_expr);
}

DEFINE_OPERATOR(not) {
  CHECK_BOOL_ONE_ARG(idx,args);
  
  std::string vlg_expr = 
   "!(" + args[0]->_translate + ")";

  MAKE_BOOL_RESULT(vlg_expr);
}

DEFINE_OPERATOR(implies) {
  CHECK_BOOL_TWO_ARG(idx,args);
  std::string vlg_expr = 
   "~(" + args[0]->_translate + ") || (" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
}

DEFINE_OPERATOR(eq) {
  ILA_ASSERT(idx.empty());
  ILA_ASSERT(args.size() == 2); // we don't require they are bv
  ILA_ASSERT(var_type::eqtype(args[0]->_type,args[1]->_type));

  std::string vlg_expr = 
   "(" + args[0]->_translate + ") == (" + args[1]->_translate + ")";
  
  MAKE_BOOL_RESULT(vlg_expr);
}
DEFINE_OPERATOR(ite) {
  ILA_ASSERT(idx.empty());
  ILA_ASSERT(args.size() == 3);
  ILA_ASSERT(args[0]->_type._type == var_type::tp::Bool);
  ILA_ASSERT(var_type::eqtype(args[1]->_type,args[2]->_type));
  
  auto vlg_expr = "(" + args[0]->_translate + ") ? ("
    + args[1]->_translate + ") : (" + args[2]->_translate + ")";

  if (args[1]->_type._type == var_type::tp::Bool) {
    MAKE_BOOL_RESULT(vlg_expr);
  } else if (args[1]->_type._type == var_type::tp::BV) {
    MAKE_BV_RESULT_TYPE_AS_ARGN(vlg_expr,args,1);
  } // diff on type
  // should not be executed...
}

DEFINE_OPERATOR(xor) {
  CHECK_BOOL_TWO_ARG(idx,args);
  
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") ^ (" + args[1]->_translate + ")";
   
  MAKE_BOOL_RESULT(vlg_expr);
} // xor

DEFINE_OPERATOR(nand) {
  ILA_ASSERT(idx.empty());
  ILA_ASSERT(args.size() >= 2);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr,args,var_type::tp::Bool, "&&" );
  vlg_expr = "!(" + vlg_expr +")";

  MAKE_BOOL_RESULT(vlg_expr);
} // nand

DEFINE_OPERATOR(concat) {
  ILA_ASSERT(idx.empty());
  ILA_ASSERT(args.size() >= 2);
  
  std::string vlg_expr = "{";
  unsigned total_width = 0;
  bool first = true; 
  for(auto && arg:(args)) {
    ILA_ASSERT(arg->_type._type == (var_type::tp::BV)); 
    if (first)
      (vlg_expr) += arg->_translate ;
    else
      (vlg_expr) += " , " + arg->_translate ;
    first = false;
    total_width += arg->_type._width;
  } // arg
  vlg_expr += "}";

  std::string search_name = "##bv"+std::to_string(total_width) + "_"  + (vlg_expr);
  if (not IN(search_name, term_container)) {
    term_container.insert( std::make_pair( search_name,
      SmtTermInfoVerilog(
        vlg_expr ,
        var_type(var_type::tp::BV, total_width, ""),
        this ) ) );
  } // not in, then add it
  return & ( term_container[search_name] );
} // concat

DEFINE_OPERATOR(bvnot) {
  CHECK_BV_ONE_ARG(idx,args);
  std::string vlg_expr = 
   "~(" + args[0]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvnot

DEFINE_OPERATOR(bvand) {
  CHECK_BV_MULTI_ARG(idx,args);
  
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args,var_type::tp::BV, "&");
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvand

DEFINE_OPERATOR(bvnand) {
  CHECK_BV_MULTI_ARG(idx,args);
  
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args,var_type::tp::BV, "&");
  vlg_expr += "~(" + vlg_expr + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvnand
DEFINE_OPERATOR(bvor) {
  CHECK_BV_MULTI_ARG(idx,args);
  
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args,var_type::tp::BV, "|");
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvor
DEFINE_OPERATOR(bvnor) {
  CHECK_BV_MULTI_ARG(idx,args);
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args,var_type::tp::BV, "|");
  vlg_expr += "~(" + vlg_expr + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvnor

DEFINE_OPERATOR(bvxor) {
  CHECK_BV_TWO_ARG(idx,args);
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") ^ (" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvxor

DEFINE_OPERATOR(bvxnor) {
  CHECK_BV_TWO_ARG(idx,args);  
  std::string vlg_expr = 
   "~((" + args[0]->_translate + ") ^ (" + args[1]->_translate + "))";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvxnor

DEFINE_OPERATOR(bvult) {
  CHECK_BV_COMPARE(idx,args);
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") < (" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvult
DEFINE_OPERATOR(bvslt) {
  CHECK_BV_COMPARE(idx,args);
  std::string vlg_expr = 
   "$signed(" + args[0]->_translate + ") < $signed(" = args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr); 
} // bvslt
DEFINE_OPERATOR(bvule) {
  CHECK_BV_COMPARE(idx,args);  
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") <= (" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvule
DEFINE_OPERATOR(bvsle) {
  CHECK_BV_COMPARE(idx,args);  
  std::string vlg_expr = 
   "$signed(" + args[0]->_translate + ") <= $signed(" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvsle
DEFINE_OPERATOR(bvugt) {
  CHECK_BV_COMPARE(idx,args);  
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") > (" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvugt

DEFINE_OPERATOR(bvsgt) {
  CHECK_BV_COMPARE(idx,args);  
  std::string vlg_expr = 
   "$signed(" + args[0]->_translate + ") > $signed(" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvsgt
DEFINE_OPERATOR(bvuge) {
  CHECK_BV_COMPARE(idx,args);  
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") >= (" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvuge

DEFINE_OPERATOR(bvsge) {
  CHECK_BV_COMPARE(idx,args);  
  std::string vlg_expr = 
   "$signed(" + args[0]->_translate + ") >= $signed(" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvsge

DEFINE_OPERATOR(bvcomp) {
  CHECK_BV_COMPARE(idx,args);  
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") == (" + args[1]->_translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvcomp

DEFINE_OPERATOR(bvneg) {
  CHECK_BV_ONE_ARG(idx,args);
  std::string vlg_expr = 
   "( ~(" + args[0]->_translate + ") + 'b1 )";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvneg
// we support a+b+c+..
DEFINE_OPERATOR(bvadd) {
  CHECK_BV_MULTI_ARG(idx,args);
  
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::BV, "+");
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvadd

DEFINE_OPERATOR(bvsub) {
  CHECK_BV_TWO_ARG(idx,args);
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") - (" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvsub

// we support a*b*c*...
DEFINE_OPERATOR(bvmul) {
  CHECK_BV_MULTI_ARG(idx,args);
  
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::BV, "*");
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvmul

DEFINE_OPERATOR(bvudiv) {
  CHECK_BV_TWO_ARG(idx,args);
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") / (" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvudiv

DEFINE_OPERATOR(bvsdiv) {
  CHECK_BV_TWO_ARG(idx,args);
  std::string vlg_expr = 
   "$signed(" + args[0]->_translate + ") / $signed(" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
  
} // bvsdiv


DEFINE_OPERATOR(bvsmod) {
  CHECK_BV_TWO_ARG(idx,args);
  std::string vlg_expr = 
   "$signed(" + args[0]->_translate + ") % $signed(" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvsmod

DEFINE_OPERATOR(bvurem) {
  CHECK_BV_TWO_ARG(idx,args);
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") % (" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
  // CHECK_BV_TWO_ARG(idx,args);
  // MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvurem

DEFINE_OPERATOR(bvsrem) {
  ILA_ASSERT(false) << "Unimplemented";
  return nullptr;

  // CHECK_BV_TWO_ARG(idx,args);
  // MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvsrem

// allow variable shift
// not requiring same width
// width the same as args[0]
DEFINE_OPERATOR(bvshl) {
  CHECK_BV_TWO_ARG_DIFF_WIDTH(idx,args);
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") << (" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvshl

DEFINE_OPERATOR(bvlshr) {
  CHECK_BV_TWO_ARG_DIFF_WIDTH(idx,args);
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") >> (" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvlshr

DEFINE_OPERATOR(bvashr) {
  CHECK_BV_TWO_ARG_DIFF_WIDTH(idx,args);
  std::string vlg_expr = 
   "(" + args[0]->_translate + ") >>> (" + args[1]->_translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvashr

DEFINE_OPERATOR(extract) {
  ILA_ASSERT(idx.size() == 2);
  ILA_ASSERT(args.size() == 1);
  ILA_ASSERT(args[0]->_type._type == var_type::tp::BV);
  
  auto left = idx[0]; auto right = idx[1];
  auto new_width = std::max(left,right) - std::min(left,right) + 1;
  ILA_ASSERT(new_width <= args[0]->_type._width);
  ILA_ASSERT(left >=0 and left < args[0]->_type._width);
  ILA_ASSERT(right >=0 and right < args[0]->_type._width);

  std::string bitslice = "[" + std::to_string(left) + ":" + std::to_string(right) + "]";
  // this creates extra problem!
  //if (left == right)
  //  bitslice = "[" + std::to_string(left)  + "]";

  if (S_IN("(",args[0]->_translate )) 
  { // when we cannot put in one expression
    std::string vlg_expr = 
    "(" + args[0]->_translate + ")" + bitslice;
    std::string search_name = "##bv"+std::to_string(new_width) + "_"  + vlg_expr;
    if (not IN(search_name, term_container)) {
      auto local_var = get_a_new_local_var_name();
      // here we need to put the variable
      term_container.insert( std::make_pair( search_name, 
        SmtTermInfoVerilog(
          local_var+bitslice , 
          var_type(var_type::tp::BV, new_width, ""), 
          this ) ) );
      // assign the current expression to a local var
      // and apply to it
      local_vars.insert( std::make_pair(
        local_var, SmtTermInfoVerilog(
          args[0]->_translate,
          args[0]->_type,
          args[0]->_context)));
    }
    return & ( term_container[search_name] );
  } // else 
  ILA_ASSERT(not S_IN(')', args[0]->_translate));

  std::string vlg_expr = args[0]->_translate + bitslice;
  std::string search_name = "##bv"+std::to_string(new_width) + "_"  + vlg_expr;
  if (not IN(search_name, term_container)) {
    // here we need to put the variable
    term_container.insert( std::make_pair( search_name, 
      SmtTermInfoVerilog(
        vlg_expr , 
        var_type(var_type::tp::BV, new_width, ""), 
        this ) ) );
  } // end of insert if not found
  return & ( term_container[search_name] );
} // extract

DEFINE_OPERATOR(bit2bool) {
  ILA_ASSERT(idx.size() == 1);
  ILA_ASSERT(args.size() == 1);
  ILA_ASSERT(args[0]->_type._type == var_type::tp::BV);

  auto bitidx = idx[0];
  ILA_ASSERT(bitidx >=0 and bitidx < args[0]->_type._width);
  //auto bitslice = "[" + std::to_string(bitidx)  + "]";
  auto bitslice = "[" + std::to_string(bitidx) + ":" + std::to_string(bitidx) + "]";

  if (S_IN("(",args[0]->_translate )) 
  { // when we cannot put in one expression
    std::string vlg_expr = 
    "(" + args[0]->_translate + ")" + bitslice;
    std::string search_name = "##bool_"  + vlg_expr;
    if (not IN(search_name, term_container)) {
      auto local_var = get_a_new_local_var_name();
      // here we need to put the variable
      term_container.insert( std::make_pair( search_name, 
        SmtTermInfoVerilog(
          local_var+bitslice , 
          var_type(var_type::tp::Bool, 1, ""), 
          this ) ) );
      // assign the current expression to a local var
      // and apply to it
      local_vars.insert( std::make_pair(
        local_var, SmtTermInfoVerilog(
          args[0]->_translate,
          args[0]->_type,
          args[0]->_context)));
    }
    return & ( term_container[search_name] );
  } // else 
  ILA_ASSERT(not S_IN(')', args[0]->_translate));

  std::string vlg_expr = args[0]->_translate + bitslice;
  std::string search_name = "##bool_"  + vlg_expr;
  if (not IN(search_name, term_container)) {
    // here we need to put the variable
    term_container.insert( std::make_pair( search_name, 
      SmtTermInfoVerilog(
        vlg_expr , 
        var_type(var_type::tp::Bool, 1, ""), 
        this ) ) );
  } // end of insert if not found
  return & ( term_container[search_name] );
} // bit2bool


DEFINE_OPERATOR(repeat) {
  ILA_ASSERT(false) << "Unimplemented";
  return nullptr;
}
DEFINE_OPERATOR(zero_extend) {
  ILA_ASSERT(idx.size() == 1);
  ILA_ASSERT(args.size() == 1);
  ILA_ASSERT(args[0]->_type._type == var_type::tp::BV);
  
}
DEFINE_OPERATOR(sign_extend) {
  ILA_ASSERT(idx.size() == 1);
  ILA_ASSERT(args.size() == 1);
  ILA_ASSERT(args[0]->_type._type == var_type::tp::BV);
  
}
DEFINE_OPERATOR(rotate_left) {
  ILA_ASSERT(false) << "Unimplemented";
  return nullptr;
}
DEFINE_OPERATOR(rotate_right) {
  ILA_ASSERT(false) << "Unimplemented";  
  return nullptr;
}

#undef DEFINE_OPERATOR


// ---------------------- METHODS ------------------------- //

// parse from a file, we will add something there to make
// if sat --> failed (return false)
// if unsat --> add the (assert ...)
bool SmtlibInvariantParser::ParseInvResultFromFile(const std::string & fname) {
  std::ifstream fin(fname);
  if (not fin.is_open()) {
    ILA_ERROR << "Unable to read from : " << fname;
    return false;
  }

  std::string result;
  if (not std::getline(fin,result) || result != std::string("unsat") ) {
    ILA_ERROR << "The cex is not unreachable, get result:" << result;
    return false; // unknown result, possibly failed
  }

  std::stringstream sbuf;
  sbuf << fin.rdbuf();
  raw_string = sbuf.str();
  ParseSmtResultFromString("(assert " + raw_string + ")");
  return true;
}
// parse from a string: assume we have the (assert ...) there
void SmtlibInvariantParser::ParseSmtResultFromString(const std::string & text) {
  auto len = text.size()+1;
  char * buffer = new char[len];
  strncpy(buffer,text.c_str(),len);
  ILA_ASSERT(buffer[len-1] == '\0');
  std::FILE * fp = fmemopen((void * )buffer, len * sizeof(char), "r" );
  ILA_NOT_NULL(fp);

  smtlib2_abstract_parser_parse(&(parser_wrapper->parser), fp);

  fclose(fp);
  delete [] buffer;
}


std::string SmtlibInvariantParser::GetFinalTranslateResult() const {
  return final_translate_result;
}
/// get the local variable definitions
const SmtlibInvariantParser::local_vars_t & 
SmtlibInvariantParser::GetLocalVarDefs() const {
  return local_vars;
}

/// get the local variable definitions
const SmtlibInvariantParser::free_vars_t & 
SmtlibInvariantParser::GetFreeVarDefs() const {
  return free_vars;
}

}; // namespace smt
}; // namespace ilang
