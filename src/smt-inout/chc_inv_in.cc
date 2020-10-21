/// \file CHC Invariant Input Parsing
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/fs.h>
#include <ilang/util/str_util.h>

#if defined(_WIN32) || defined(_WIN64)
#include <ilang/util/posix_emu.h>
#endif

#include <ilang/smt-inout/chc_inv_callback_fn.h>
#include <ilang/smt-inout/chc_inv_in.h>
#include <ilang/util/container_shortcut.h>

#include <cstdio>
#include <fstream>

namespace ilang {
namespace smt {

// -------------- SmtlibInvariantParser ---------------- //

SmtlibInvariantParser::SmtlibInvariantParser(
    YosysSmtParser* yosys_smt_info, bool _flatten_datatype,
    bool _flatten_hierarchy, const std::set<std::string>& _inv_pred_name,
    const std::string& dut_instance_name, bool discourageOutOfScopeVariable)
    :

      parser_wrapper(new smtlib2_abstract_parser()),
      inv_pred_name(_inv_pred_name),
      dut_verilog_instance_name(dut_instance_name),
      design_smt_info_ptr(yosys_smt_info),
      datatype_flattened(_flatten_datatype),
      hierarchy_flattened(_flatten_hierarchy),
      no_outside_var_refer(discourageOutOfScopeVariable), _bad_state(false) {

  ILA_NOT_NULL(yosys_smt_info);
  // the first element's address should be the outer structure's address

  if (!parser_wrapper) {
    _bad_state = true;
    ILA_ERROR << "SMT-LIB2 parser construct allocation failed!";
    return;
  }
  // the be
  smtlib2_abstract_parser_init(parser_wrapper,
                               (smtlib2_context)this);
                               
  parser_wrapper->print_success_ = false;
  smtlib2_parser_interface* pi;
  smtlib2_term_parser* tp;

  /* initialize the term parser and override virtual methods */
  pi = &(parser_wrapper->parent_);
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
  // pi->push_let_scope = ; pop_let_scope; push_quantifier_scope;
  // pop_quantifier_scope smtlib2_term_parser_push_let_scope // handles
  // automatically smtlib2_term_parser_pop_let_scope // handles automatically
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
  pi->pop_quantifier_scope = proxy_pop_quantifier_scope;
  pi->make_sort = proxy_make_sort;
  pi->declare_variable = proxy_declare_variable;
  pi->declare_function = proxy_declare_function;
  pi->check_sat = proxy_check_sat;

  tp = parser_wrapper->termparser_; // internal allocated already

  // call back function to apply an uninterpreted function
  // fall through case for handler (operator)
  smtlib2_term_parser_set_function_handler(tp, proxy_mk_function);
  smtlib2_term_parser_set_number_handler(tp, proxy_mk_number);

  smtlib2_term_parser_set_handler(
      tp, "and", smt_to_vlg_mk_and); // you need to carry something ...
  smtlib2_term_parser_set_handler(tp, "or", smt_to_vlg_mk_or);
  smtlib2_term_parser_set_handler(tp, "not", smt_to_vlg_mk_not);
  smtlib2_term_parser_set_handler(tp, "=>", smt_to_vlg_mk_implies);
  smtlib2_term_parser_set_handler(tp, "=", smt_to_vlg_mk_eq);
  smtlib2_term_parser_set_handler(tp, "ite", smt_to_vlg_mk_ite);
  smtlib2_term_parser_set_handler(tp, "xor", smt_to_vlg_mk_xor);
  smtlib2_term_parser_set_handler(tp, "nand", smt_to_vlg_mk_nand);
  // should we do this?
  smtlib2_term_parser_set_handler(tp, "true", smt_to_vlg_mk_true);
  smtlib2_term_parser_set_handler(tp, "false", smt_to_vlg_mk_false);

  smtlib2_term_parser_set_handler(tp, "concat", smt_to_vlg_mk_concat);
  smtlib2_term_parser_set_handler(tp, "bvnot", smt_to_vlg_mk_bvnot);
  smtlib2_term_parser_set_handler(tp, "bvand", smt_to_vlg_mk_bvand);
  smtlib2_term_parser_set_handler(tp, "bvnand", smt_to_vlg_mk_bvnand);
  smtlib2_term_parser_set_handler(tp, "bvor", smt_to_vlg_mk_bvor);
  smtlib2_term_parser_set_handler(tp, "bvnor", smt_to_vlg_mk_bvnor);
  smtlib2_term_parser_set_handler(tp, "bvxor", smt_to_vlg_mk_bvxor);
  smtlib2_term_parser_set_handler(tp, "bvxnor", smt_to_vlg_mk_bvxnor);
  smtlib2_term_parser_set_handler(tp, "bvult", smt_to_vlg_mk_bvult);
  smtlib2_term_parser_set_handler(tp, "bvslt", smt_to_vlg_mk_bvslt);
  smtlib2_term_parser_set_handler(tp, "bvule", smt_to_vlg_mk_bvule);
  smtlib2_term_parser_set_handler(tp, "bvsle", smt_to_vlg_mk_bvsle);
  smtlib2_term_parser_set_handler(tp, "bvugt", smt_to_vlg_mk_bvugt);
  smtlib2_term_parser_set_handler(tp, "bvsgt", smt_to_vlg_mk_bvsgt);
  smtlib2_term_parser_set_handler(tp, "bvuge", smt_to_vlg_mk_bvuge);
  smtlib2_term_parser_set_handler(tp, "bvsge", smt_to_vlg_mk_bvsge);
  smtlib2_term_parser_set_handler(tp, "bvcomp", smt_to_vlg_mk_bvcomp);
  smtlib2_term_parser_set_handler(tp, "bvneg", smt_to_vlg_mk_bvneg);
  smtlib2_term_parser_set_handler(tp, "bvadd", smt_to_vlg_mk_bvadd);
  smtlib2_term_parser_set_handler(tp, "bvsub", smt_to_vlg_mk_bvsub);
  smtlib2_term_parser_set_handler(tp, "bvmul", smt_to_vlg_mk_bvmul);
  smtlib2_term_parser_set_handler(tp, "bvudiv", smt_to_vlg_mk_bvudiv);
  smtlib2_term_parser_set_handler(tp, "bvsdiv", smt_to_vlg_mk_bvsdiv);
  smtlib2_term_parser_set_handler(tp, "bvsmod", smt_to_vlg_mk_bvsmod);
  smtlib2_term_parser_set_handler(tp, "bvurem", smt_to_vlg_mk_bvurem);
  smtlib2_term_parser_set_handler(tp, "bvsrem", smt_to_vlg_mk_bvsrem);
  smtlib2_term_parser_set_handler(tp, "bvshl", smt_to_vlg_mk_bvshl);
  smtlib2_term_parser_set_handler(tp, "bvlshr", smt_to_vlg_mk_bvlshr);
  smtlib2_term_parser_set_handler(tp, "bvashr", smt_to_vlg_mk_bvashr);
  smtlib2_term_parser_set_handler(tp, "extract", smt_to_vlg_mk_extract);
  smtlib2_term_parser_set_handler(tp, "bit2bool", smt_to_vlg_mk_bit2bool);
  smtlib2_term_parser_set_handler(tp, "repeat", smt_to_vlg_mk_repeat);
  smtlib2_term_parser_set_handler(tp, "zero_extend", smt_to_vlg_mk_zero_extend);
  smtlib2_term_parser_set_handler(tp, "sign_extend", smt_to_vlg_mk_sign_extend);
  smtlib2_term_parser_set_handler(tp, "rotate_left", smt_to_vlg_mk_rotate_left);
  smtlib2_term_parser_set_handler(tp, "rotate_right",
                                  smt_to_vlg_mk_rotate_right);

  sort_pool.push_back(var_type(var_type::tp::BV,0,"ERROR")); // should never use this
  term_pool.push_back(SmtTermInfoVerilog("__ERROR__", sort_pool.at(0),this)); // should never use this
}

SmtlibInvariantParser::~SmtlibInvariantParser() {
  if (parser_wrapper) {
    smtlib2_abstract_parser_deinit(parser_wrapper);
    delete parser_wrapper;
  }
}

bool SmtlibInvariantParser::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state)
      << "SmtlibInvariantParser is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return


/// New Sort
SmtlibInvariantParser::SortPtrT
SmtlibInvariantParser::new_sort(const std::string & search_name, const var_type & sort) {
  sort_pool.push_back(sort);
  name2sort_map.emplace(search_name, sort_pool.size()-1);
  return sort_pool.size()-1;
}

/// New Term
SmtlibInvariantParser::TermPtrT
SmtlibInvariantParser::new_term(const std::string & search_name, const SmtTermInfoVerilog & term) {
  term_pool.push_back(term);
  name2term_map.emplace(search_name,term_pool.size()-1);
  return term_pool.size()-1;
}

/// From pointer to sort
const var_type & SmtlibInvariantParser::get_sort(SortPtrT ptr) const {
  ILA_CHECK(ptr!=0 && ptr < sort_pool.size()) 
     << "Unexpected Error in SmtlibInvariantParser. Referencing sort " << ptr;
  return sort_pool.at(ptr);
}

/// From pointer to term
const SmtTermInfoVerilog & SmtlibInvariantParser::get_term(TermPtrT ptr) const {
  ILA_CHECK(ptr!=0 && ptr < term_pool.size()) 
     << "Unexpected Error in SmtlibInvariantParser. Referencing term " << ptr;
  return term_pool.at(ptr);
}


/// this function receives the final assert result
void SmtlibInvariantParser::assert_formula(TermPtrT resultidx) {
  const auto result = term_pool.at(resultidx);
  final_translate_result = result._translate;
}

/// declare function (useful for Grain)
void SmtlibInvariantParser::declare_function(const std::string& name,
                                             SortPtrT sort) {
  ILA_ASSERT(false)
      << "Bug: CHC solver should not generate output containing declare-fun!";
}

void SmtlibInvariantParser::define_function(
    const std::string& func_name, const std::vector<TermPtrT>& args,
    SortPtrT ret_type, TermPtrT func_body) {

  ILA_ASSERT(false)
      << "Bug: CHC solver should not generate output containing define-fun!";
  // we expect the forall style // for SyGuS, it is the opposite
} // define_function

/// call back function to handle (forall
SmtlibInvariantParser::TermPtrT SmtlibInvariantParser::push_quantifier_scope() {
  quantifier_def_stack.push_back(quantifier_temp_def_t());
  quantifier_var_def_idx_stack.push_back(0);
  return 0; // no body cares this
}
/// call back function to handle ) of forall
SmtlibInvariantParser::TermPtrT SmtlibInvariantParser::pop_quantifier_scope() {
  // will not to deallocate term pool at this point
  quantifier_def_stack.pop_back();
  quantifier_var_def_idx_stack.pop_back();
  return 0; // if we return null, it will not overwrite the
                  // make_forall_term result
}

/// call back function to create a sort
SmtlibInvariantParser::SortPtrT 
SmtlibInvariantParser::make_sort(const std::string& name,
                                           const std::vector<int>& idx) {
  // ILA_ASSERT(! quantifier_def_stack.empty());
  // ILA_ASSERT(! quantifier_var_def_idx_stack.empty());
  if (datatype_flattened) {
    // should should only be BitVec or Bool
    if (name == "Bool") {
      if (!IN("Bool", name2sort_map)) {
        sort_pool.push_back(var_type(var_type::tp::Bool, 1, ""));
        name2sort_map.emplace(std::string("Bool"), sort_pool.size()-1);
      }
      return name2sort_map.at("Bool");
    } else if (name == "BitVec") {
      ILA_CHECK(idx.size() == 1);
      ILA_CHECK(idx[0] > 0);
      std::string sortIdxName = "BV" + std::to_string(idx[0]);
      if (!IN(sortIdxName, name2sort_map)) 
        return new_sort(sortIdxName, var_type(var_type::tp::BV, idx[0], ""));
      return name2sort_map.at(sortIdxName);
    }
    ILA_CHECK(false) << "Unknown sort:" << name << " in flattened smt.";
    return 0; // should not be reachable
  } else {
    // if not flattened, there should only be one sort
    const auto& module_def_order = design_smt_info_ptr->get_module_def_orders();

    std::string top_module = module_def_order.back();
    std::string top_module_sort;
    ILA_DLOG("SmtlibInvariantParser.make_sort") << top_module << std::endl;
    top_module_sort = top_module + std::string("_s");
    ILA_DLOG("SmtlibInvariantParser.make_sort") << top_module_sort << std::endl;

    ILA_CHECK(name == top_module_sort || name == "|" + top_module_sort + "|")
        << "Unknown sort:" << name << " in unflattened smt."
        << " Expecting:" << top_module_sort;

    if (!IN(top_module_sort, name2sort_map))
      return new_sort(top_module_sort, 
                      var_type(var_type::tp::Datatype, 0, top_module));
    
    return name2sort_map.at(top_module_sort);
  }
} // make_sort


SmtlibInvariantParser::SortPtrT
SmtlibInvariantParser::make_parametric_sort(const std::string& name, const std::vector<SortPtrT>& tpargs) 
{
  ILA_CHECK(name == "Array") << ("Parametric Sort : " + name + " is unknown");
  ILA_CHECK(tpargs.size() == 2) << ("Parametric Array has wrong parameters");
  const var_type & sort1 = get_sort(tpargs[0]);
  const var_type & sort2 = get_sort(tpargs[1]);
  ILA_CHECK(sort1.is_bv()) << "Parametric Array has non-BV parameter type";
  ILA_CHECK(sort2.is_bv()) << "Parametric Array has non-BV parameter type";
  
  auto sort_name("A" + sort1.toString()+" -> " + sort2.toString());
  auto sort_pos = name2sort_map.find(sort_name);
  if (sort_pos == name2sort_map.end()) {
    return new_sort(sort_name, var_type(
      var_type::tp::Array, sort1.GetBoolBvWidth(), sort2.GetBoolBvWidth(), ""));
  } else 
    return (sort_pos->second);
}

/// call back function to create a temporary (quantified variable)
// for the flattened-datatype, this should be the same as the datatype order
//
void SmtlibInvariantParser::declare_quantified_variable(const std::string& name,
                                                        SortPtrT sort) {
  // check on the name part
  ILA_ASSERT(!quantifier_def_stack.empty());
  ILA_ASSERT(!quantifier_var_def_idx_stack.empty());
  // I assume it has nothing to do with hierarchy flattening
  auto& top = quantifier_def_stack.back();
  if (datatype_flattened) {
    // we need to extract the name from verilog
    auto top_module = design_smt_info_ptr->get_module_def_orders().back();
    auto vlg_name = (design_smt_info_ptr->get_module_flatten_dt(
                         top_module)[quantifier_var_def_idx_stack.back()])
                        .verilog_name;
    top.emplace(name, 
      new_term(name, SmtTermInfoVerilog(vlg_name, get_sort(sort), this)));
    quantifier_var_def_idx_stack.back()++;
  } else {
    // if not flattened, there should only be one sort
    top.emplace(name, 
      new_term(name, SmtTermInfoVerilog("", get_sort(sort), this)));
    ILA_DLOG("SmtlibInvariantParser.declare_quantified_variable")
        << "make var :" << name << std::endl;
  }
}

SmtlibInvariantParser::TermPtrT
SmtlibInvariantParser::search_quantified_var_stack(const std::string& name) {

  ILA_DLOG("SmtlibInvariantParser.search_var")
      << "Begin search var:" << name << std::endl;
  for (auto mp_pos = quantifier_def_stack.rbegin();
       mp_pos != quantifier_def_stack.rend();
       ++mp_pos) { // search from the closest binding
    if (IN(name, (*mp_pos)))
      return (*mp_pos)[name];
  }
  ILA_DLOG("SmtlibInvariantParser.search_var")
      << "Not found var:" << name << std::endl;
  return 0;
} // search_quantified_var_stack

/// call back function to apply an uninterpreted function
/// fall-through case if it is not an defined op, if failed, return NULL
/// for unflattened-hierarchy: this should be the place where things are called
/// it could be directly the (pred state)
/// or (pred (pred state)) ... you need to pass the right instance name allow
/// side
SmtlibInvariantParser::TermPtrT
SmtlibInvariantParser::mk_function(const std::string& name, SortPtrT sort,
                                   const std::vector<int>& idx,
                                   const std::vector<TermPtrT>& args) {
  // we don't really rely on the sort here: actually it should be NULL
  ILA_DLOG("SmtlibInvariantParser.mk_function")
      << "make func:" << name << ", #arg" << args.size() << std::endl;
  if (args.empty() && idx.empty()) {
    // first let's check if it is referring to a quantifier-bound variable
    auto term_ptr = search_quantified_var_stack(name);
    if (term_ptr)
      return term_ptr;
    ILA_CHECK(false) << "unknown symbol:" << name;
    return 0; // no use
  }
  // if it is function call
  if (datatype_flattened) {
    if (IN(name, inv_pred_name))
      return mk_true("true", 0, {}, {});
    ILA_CHECK(false) << "Fun:" << name << " called in flattened smt.";
    return 0; // should not be reachable
  } else {
    ILA_CHECK(args.size() == 1);
    const SmtTermInfoVerilog & t = get_term(args[0]);
    ILA_CHECK(t._type.is_datatype());

    if (IN(name, inv_pred_name))
      return mk_true("true", 0, {}, {});

    // get it from the module_name
    const auto& module_name = t._type.module_name;
    const auto& dts = design_smt_info_ptr->get_module_flatten_dt(module_name);
    for (auto&& dt : dts) {
      if (dt.internal_name == name || dt.internal_name == "|" + name + "|") {
        // make the new variable here
        std::string search_name;
        if (dt._type.is_bool())
          search_name = "##bool_";
        else if (dt._type.is_bv())
          search_name = "##bv" + std::to_string(dt._type._width) + "_";
        else
          ILA_CHECK(false) << "unexpected type!";

        search_name += dt.verilog_name;
        auto repl_name = dt.verilog_name;
        // here we need to make sure it is a good name
        if (!dut_verilog_instance_name.empty() && no_outside_var_refer) {
          auto dot_pos = dt.verilog_name.find('.');
          if (dot_pos != std::string::npos &&
              dt.verilog_name.substr(0, dot_pos) != dut_verilog_instance_name) {

            repl_name = ReplaceAll(dt.verilog_name, ".", "_dot_");
            ILA_ERROR_IF(IN(repl_name, free_vars))
                << "Bug free var name reappearing: " << repl_name;
            // not possible for datatype here
            int width =
                dt._type._type == var_type::tp::BV ? dt._type._width : 1;
            free_vars.insert(std::make_pair(repl_name, width));

            ILA_ERROR << "Invariant refers to out-of-scope var : "
                      << dt.verilog_name << " replaced w. " << repl_name;
          } else if (dot_pos == std::string::npos) {
            ILA_ERROR << "Invariant refers to wrapper var: " << dt.verilog_name;
          }
        } // check out-of-scope name

        if (!IN(search_name, name2term_map)) {
          return new_term(search_name, SmtTermInfoVerilog(repl_name, dt._type, this));
        }
        return name2term_map.at(search_name);
      } // if name matched
    }   // for all datatypes
    ILA_CHECK(false) << "unknown symbol:" << name;
    return 0; // should not be reachable
  }                 // end of else
} // mk_function

/// call back function to make a number term
SmtlibInvariantParser::TermPtrT 
SmtlibInvariantParser::mk_number(const std::string& rep,
                                                   int width, int base) {
  ILA_CHECK(width > 0) << "Unable to translate Integer with width <=0!";
  char radix;
  switch (base) {
  case 2:
    radix = 'b';
    break;
  case 10:
    radix = 'd';
    break;
  case 16:
    radix = 'h';
    break;
  default:
    ILA_CHECK(false) << "unable to handle base:" << base;
  }
  std::string vlg_expr = std::to_string(width) + "'" + radix + rep;
  std::string name = "##bv" + vlg_expr;
  if (!IN(name, name2term_map)) {
    return new_term(name, SmtTermInfoVerilog(vlg_expr,
                                 var_type(var_type::tp::BV, width, ""), this));
  }
  // return the reference from the container
  return name2term_map.at(name);
} // mk_number

#include <ilang/smt-inout/smt_op.h>

#define DEFINE_OPERATOR(name)                                                  \
  SmtlibInvariantParser::TermPtrT SmtlibInvariantParser::mk_##name(                          \
      const std::string& symbol, SortPtrT sort, const std::vector<int>& idx,  \
      const std::vector<TermPtrT>& args)

DEFINE_OPERATOR(true) {
  CHECK_EMPTY_PARAM(idx, args);
  MAKE_BOOL_RESULT(std::string("1'b1"));
}

DEFINE_OPERATOR(false) {
  CHECK_EMPTY_PARAM(idx, args);
  MAKE_BOOL_RESULT(std::string("1'b0"));
}

DEFINE_OPERATOR(and) {
  CHECK_BOOL_MULTI_ARG(idx, args);
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::Bool, "&&");
  MAKE_BOOL_RESULT(vlg_expr);
}

DEFINE_OPERATOR(or) {
  CHECK_BOOL_MULTI_ARG(idx, args);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::Bool, "||");
  MAKE_BOOL_RESULT(vlg_expr);
}

DEFINE_OPERATOR(not) {
  CHECK_BOOL_ONE_ARG(idx, args);

  std::string vlg_expr = "!(" + get_term(args[0])._translate + ")";

  MAKE_BOOL_RESULT(vlg_expr);
}

DEFINE_OPERATOR(implies) {
  CHECK_BOOL_TWO_ARG(idx, args);
  std::string vlg_expr =
      "~(" + get_term(args[0])._translate + ") || (" + get_term(args[1])._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
}

DEFINE_OPERATOR(eq) {
  ILA_CHECK(idx.empty());
  ILA_CHECK(args.size() == 2); // we don't require they are bv
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  ILA_CHECK(var_type::eqtype(t0._type, t1._type));


  std::string vlg_expr =
      "(" + t0._translate + ") == (" + t1._translate + ")";

  MAKE_BOOL_RESULT(vlg_expr);
}
DEFINE_OPERATOR(ite) {
  ILA_CHECK(idx.empty());
  ILA_CHECK(args.size() == 3);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  const auto & t2 = get_term(args[2]);
  ILA_CHECK(t0._type.is_bool());
  ILA_CHECK(var_type::eqtype(t1._type, t2._type));

  auto vlg_expr = "(" + t0._translate + ") ? (" + t1._translate +
                  ") : (" + t2._translate + ")";

  if (t1._type.is_bool()) {
    MAKE_BOOL_RESULT(vlg_expr);
  } else if (t1._type.is_bv()) {
    MAKE_BV_RESULT_TYPE_AS_ARGN(vlg_expr, args, 1);
  } // diff on type
  // should not be executed...
  ILA_CHECK(false) << "Unable to handle ite type for Array/Datatype";
  return 0;
}

DEFINE_OPERATOR (xor) {
  CHECK_BOOL_TWO_ARG(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);

  std::string vlg_expr =
      "(" + t0._translate + ") ^ (" + t1._translate + ")";

  MAKE_BOOL_RESULT(vlg_expr);
} // xor

DEFINE_OPERATOR(nand) {
  ILA_CHECK(idx.empty());
  ILA_CHECK(args.size() >= 2);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::Bool, "&&");
  vlg_expr = "!(" + vlg_expr + ")";

  MAKE_BOOL_RESULT(vlg_expr);
} // nand

DEFINE_OPERATOR(concat) {
  ILA_CHECK(idx.empty());
  ILA_CHECK(args.size() >= 2);

  std::string vlg_expr = "{";
  unsigned total_width = 0;
  bool first = true;
  for (auto&& arg : (args)) {
    const auto & t = get_term(arg);
    ILA_CHECK(t._type.is_bv());
    if (first)
      (vlg_expr) += t._translate;
    else
      (vlg_expr) += " , " + t._translate;
    first = false;
    total_width += t._type._width;
  } // arg
  vlg_expr += "}";

  std::string search_name =
      "##bv" + std::to_string(total_width) + "_" + (vlg_expr);
  if (!IN(search_name, name2term_map)) {
    return new_term(search_name, SmtTermInfoVerilog(vlg_expr,
                           var_type(var_type::tp::BV, total_width, ""), this));
  } // not in, then add it
  return name2term_map.at(search_name);
} // concat

DEFINE_OPERATOR(bvnot) {
  CHECK_BV_ONE_ARG(idx, args);
  std::string vlg_expr = "~(" + get_term(args[0])._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvnot

DEFINE_OPERATOR(bvand) {
  CHECK_BV_MULTI_ARG(idx, args);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::BV, "&");
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvand

DEFINE_OPERATOR(bvnand) {
  CHECK_BV_MULTI_ARG(idx, args);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::BV, "&");
  vlg_expr = "~(" + vlg_expr + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvnand
DEFINE_OPERATOR(bvor) {
  CHECK_BV_MULTI_ARG(idx, args);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::BV, "|");
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvor
DEFINE_OPERATOR(bvnor) {
  CHECK_BV_MULTI_ARG(idx, args);
  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::BV, "|");
  vlg_expr = "~(" + vlg_expr + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvnor

DEFINE_OPERATOR(bvxor) {
  CHECK_BV_TWO_ARG(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") ^ (" + t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvxor

DEFINE_OPERATOR(bvxnor) {
  CHECK_BV_TWO_ARG(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "~((" + t0._translate + ") ^ (" + t1._translate + "))";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvxnor

DEFINE_OPERATOR(bvult) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") < (" + t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvult
DEFINE_OPERATOR(bvslt) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr = "$signed(" + t0._translate + ") < $signed(" +
                         t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvslt
DEFINE_OPERATOR(bvule) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") <= (" + t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvule
DEFINE_OPERATOR(bvsle) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr = "$signed(" + t0._translate + ") <= $signed(" +
                        t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvsle
DEFINE_OPERATOR(bvugt) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") > (" + t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvugt

DEFINE_OPERATOR(bvsgt) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr = "$signed(" + t0._translate + ") > $signed(" +
                         t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvsgt
DEFINE_OPERATOR(bvuge) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") >= (" + t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvuge

DEFINE_OPERATOR(bvsge) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr = "$signed(" + t0._translate + ") >= $signed(" +
                         t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvsge

DEFINE_OPERATOR(bvcomp) {
  CHECK_BV_COMPARE(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") == (" + t1._translate + ")";
  MAKE_BOOL_RESULT(vlg_expr);
} // bvcomp

DEFINE_OPERATOR(bvneg) {
  CHECK_BV_ONE_ARG(idx, args);
  std::string vlg_expr = "( ~(" + get_term(args[0])._translate + ") + 'b1 )";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvneg
// we support a+b+c+..
DEFINE_OPERATOR(bvadd) {
  CHECK_BV_MULTI_ARG(idx, args);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::BV, "+");
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvadd

DEFINE_OPERATOR(bvsub) {
  CHECK_BV_TWO_ARG(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") - (" + t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvsub

// we support a*b*c*...
DEFINE_OPERATOR(bvmul) {
  CHECK_BV_MULTI_ARG(idx, args);

  std::string vlg_expr;
  MAKE_MULTI_OP(vlg_expr, args, var_type::tp::BV, "*");
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvmul

DEFINE_OPERATOR(bvudiv) {
  CHECK_BV_TWO_ARG(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") / (" + t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvudiv

DEFINE_OPERATOR(bvsdiv) {
  CHECK_BV_TWO_ARG(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr = "$signed(" + t0._translate + ") / $signed(" +
                         t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);

} // bvsdiv

DEFINE_OPERATOR(bvsmod) {
  CHECK_BV_TWO_ARG(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr = "$signed(" + t0._translate + ") % $signed(" +
                         t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvsmod

DEFINE_OPERATOR(bvurem) {
  CHECK_BV_TWO_ARG(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") % (" + t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
  // CHECK_BV_TWO_ARG(idx,args);
  // MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvurem

DEFINE_OPERATOR(bvsrem) {
  ILA_CHECK(false) << "Unimplemented";
  return 0;

  // CHECK_BV_TWO_ARG(idx,args);
  // MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr,args);
} // bvsrem

// allow variable shift
// not requiring same width
// width the same as args[0]
DEFINE_OPERATOR(bvshl) {
  CHECK_BV_TWO_ARG_DIFF_WIDTH(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") << (" + t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvshl

DEFINE_OPERATOR(bvlshr) {
  CHECK_BV_TWO_ARG_DIFF_WIDTH(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") >> (" + t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvlshr

DEFINE_OPERATOR(bvashr) {
  CHECK_BV_TWO_ARG_DIFF_WIDTH(idx, args);
  const auto & t0 = get_term(args[0]);
  const auto & t1 = get_term(args[1]);
  std::string vlg_expr =
      "(" + t0._translate + ") >>> (" + t1._translate + ")";
  MAKE_BV_RESULT_TYPE_AS_ARG0(vlg_expr, args);
} // bvashr

DEFINE_OPERATOR(extract) {
  ILA_CHECK(idx.size() == 2);
  ILA_CHECK(args.size() == 1);
  const auto & arg0 = get_term(args[0]);
  ILA_CHECK(arg0._type.is_bv());
  // || (args[0]->_type.is_bool() && idx[0] == 0 && idx[1] == 0 ) smt should ensure it is bv
  ILA_CHECK(idx[0] >= 0 && idx[1] >= 0);

  unsigned left = idx[0];
  unsigned right = idx[1];
  unsigned new_width = std::max(left, right) - std::min(left, right) + 1;
  ILA_CHECK(new_width <= arg0._type._width);
  ILA_CHECK(idx[0] >= 0 && left < arg0._type._width);  // left >= 0, always true
  ILA_CHECK(idx[1] >= 0 && right < arg0._type._width); // right >= 0

  std::string bitslice =
      "[" + std::to_string(left) + ":" + std::to_string(right) + "]";
  // this creates extra problem!
  // if (left == right)
  //  bitslice = "[" + std::to_string(left)  + "]";

  std::string before_adding_bitslice = arg0._translate;

  if (S_IN("(", before_adding_bitslice) ||
      S_IN("{", before_adding_bitslice) ||
      S_IN("[", before_adding_bitslice)
      ) { // when we cannot put in one expression
    
    // search the local var map
    std::string tp = "##bv" + std::to_string(arg0._type._width) + "_";
    std::string to_replaced_search_name = tp + "(" + arg0._translate + ")";

    if (!IN(to_replaced_search_name, local_vars_lookup)) {
      // insert it 
      auto local_var = get_a_new_local_var_name();
      // assign the current expression to a local var
      // and apply to it
      term_pool.push_back(SmtTermInfoVerilog(arg0._translate, arg0._type,
                                        arg0._context));
      local_vars.emplace(local_var, term_pool.size()-1);
      local_vars_lookup.insert(std::make_pair(
          to_replaced_search_name, local_var ));
    }
    before_adding_bitslice = local_vars_lookup[to_replaced_search_name];
  } // else
  ILA_ASSERT(!S_IN(')', before_adding_bitslice) &&
             !S_IN('}', before_adding_bitslice) &&
             !S_IN(']', before_adding_bitslice)
             );

  std::string vlg_expr = before_adding_bitslice + bitslice;
  std::string search_name = "##bv" + std::to_string(new_width) +
    "_(" +  arg0._translate + ")" + bitslice; // use the original translation
  if (!IN(search_name, name2term_map)) {
    // here we need to put the variable
    return new_term(search_name,
        SmtTermInfoVerilog(vlg_expr, var_type(var_type::tp::BV, new_width, ""),
                           this));
  } // end of insert if not found
  return name2term_map.at(search_name);
} // extract

DEFINE_OPERATOR(bit2bool) {
  ILA_CHECK(idx.size() == 1);
  ILA_CHECK(args.size() == 1);
  const auto & arg0 = get_term(args[0]);
  ILA_CHECK(arg0._type.is_bv());
  ILA_CHECK(idx[0] >= 0);

  unsigned bitidx = idx[0];
  ILA_CHECK(idx[0] >= 0 && bitidx < arg0._type._width);
  // auto bitslice = "[" + std::to_string(bitidx)  + "]";
  auto bitslice =
      "[" + std::to_string(bitidx) + ":" + std::to_string(bitidx) + "]";

  std::string before_adding_bitslice = arg0._translate;
  if (S_IN("(", before_adding_bitslice) || 
      S_IN("[", before_adding_bitslice) ||
      S_IN("{", before_adding_bitslice)) {
    // search the local var map
    std::string tp = // args[0]->_type.is_bool() ? "##bool_" :  // no need
      "##bv" + std::to_string(arg0._type._width) + "_";

    std::string to_replaced_search_name = tp + "(" +arg0._translate + ")";

    if (!IN(to_replaced_search_name, local_vars_lookup)){
      // insert it 
      auto local_var = get_a_new_local_var_name();
      // assign the current expression to a local var
      // and apply to it
      term_pool.push_back(SmtTermInfoVerilog(arg0._translate, arg0._type,
                                        arg0._context));
      local_vars.emplace(local_var, term_pool.size()-1);
      local_vars_lookup.insert(std::make_pair(
          to_replaced_search_name, local_var ));
    }
    before_adding_bitslice = local_vars_lookup[to_replaced_search_name];
  } // if { [ ( in 
  
  ILA_ASSERT(
    !S_IN(')', before_adding_bitslice) && 
    !S_IN(']', before_adding_bitslice) && 
    !S_IN('}', before_adding_bitslice)
    );

  std::string vlg_expr = before_adding_bitslice + bitslice;
  std::string search_name = "##bool_(" + arg0._translate + ")" + bitslice;
  if (!IN(search_name, name2term_map)) {
    return new_term(search_name, SmtTermInfoVerilog(
                         vlg_expr, var_type(var_type::tp::Bool, 1, ""), this));
  } // end of insert if not found
  return name2term_map.at(search_name);
} // bit2bool

DEFINE_OPERATOR(repeat) {
  ILA_CHECK(idx.size() == 1);
  ILA_CHECK(args.size() == 1);
  const auto & arg0 = get_term(args[0]);
  ILA_CHECK(arg0._type.is_bv());
  ILA_CHECK(idx[0] > 0);
  auto n_times = idx[0];
  auto new_width = n_times * arg0._type.GetBoolBvWidth();

  std::string vlg_expr = n_times == 1 ? arg0._translate :
    "{" + IntToStrCustomBase(n_times,10,false) + "{" + arg0._translate + "}}";
  std::string search_name = "##bvrepeat" + std::to_string(new_width) + "{" + arg0._translate + "}";
  if (!IN(search_name, name2term_map)) {
    return new_term(search_name, SmtTermInfoVerilog(vlg_expr, var_type(var_type::tp::BV, new_width, ""), this));
  }
  return name2term_map.at(search_name);
}

DEFINE_OPERATOR(zero_extend) {
  ILA_CHECK(idx.size() == 1);
  ILA_CHECK(args.size() == 1);
  const auto & t = get_term(args[0]);
  ILA_CHECK(t._type.is_bv());
  auto extraw = idx[0];
  auto new_width = extraw + t._type.GetBoolBvWidth();
  ILA_CHECK(extraw > 0);
  std::string vlg_expr = "{" + IntToStrCustomBase(extraw,10,false) + "'d0," + t._translate + "}";
  std::string search_name = "##bvzext" + std::to_string(new_width) + "{" + t._translate + "}";
  if (!IN(search_name, name2term_map)) {
    return new_term(search_name, SmtTermInfoVerilog(vlg_expr, var_type(var_type::tp::BV, new_width, ""), this));
  }
  return name2term_map.at(search_name);
}

DEFINE_OPERATOR(sign_extend) {
  ILA_CHECK(idx.size() == 1);
  ILA_CHECK(args.size() == 1);
  const auto & t = get_term(args[0]);
  ILA_CHECK(t._type.is_bv());
  auto extraw = idx[0];
  auto oldw = t._type.GetBoolBvWidth();
  auto new_width = extraw + oldw;
  ILA_CHECK(extraw > 0);
  TermPtrT inner_term_no = mk_extract("", 0, {(int)(oldw)-1,(int)(oldw)-1},{args[0]});//?;
  const auto & inner_term = get_term(inner_term_no);
  std::string vlg_expr = "{{" + IntToStrCustomBase(extraw,10,false) + "{" + inner_term._translate + "}}," + t._translate + "}";
  std::string search_name = "##bvsext" + std::to_string(new_width) + "{" + t._translate + "}";
  if (!IN(search_name, name2term_map)) {
    return new_term(search_name, SmtTermInfoVerilog(vlg_expr, var_type(var_type::tp::BV, new_width, ""), this));
  }
  return name2term_map.at(search_name);
}
DEFINE_OPERATOR(rotate_left) {
  ILA_CHECK(false) << "Unimplemented";
  return 0;
}
DEFINE_OPERATOR(rotate_right) {
  ILA_CHECK(false) << "Unimplemented";
  return 0;
}

#undef DEFINE_OPERATOR

// ---------------------- METHODS ------------------------- //

// parse from a file, we will add something there to make
// if sat --> failed (return false)
// if unsat --> add the (assert ...)
bool SmtlibInvariantParser::ParseInvResultFromFile(const std::string& fname) {
  std::ifstream fin(fname);
  if (!fin.is_open()) {
    ILA_ERROR << "Unable to read from : " << fname;
    return false;
  }

  std::string result;
  if (!std::getline(fin, result) || result != std::string("unsat")) {
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
void SmtlibInvariantParser::ParseSmtResultFromString(const std::string& text) {
  auto len = text.size() + 1;
  char* buffer = new char[len];
  ILA_ASSERT(buffer) << "Memory allocation failed";
  strncpy(buffer, text.c_str(), len);
  ILA_ASSERT(buffer[len - 1] == '\0');
  buffer[len - 1] = '\0'; // to make static analysis happy

  //std::FILE* fp = fmemopen((void*)buffer, len * sizeof(char), "r");
#if 0
#if defined(__linux__) 
  std::FILE* fp = fmemopen((void*)buffer, len * sizeof(char), "r");
#elif ( defined(__unix__) || defined(unix) || defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__) )
  std::FILE* fp = fmemopen_osx((void*)buffer, len * sizeof(char), "r");
#else
  #error "No available fmemopen implementation on this platform!"
#endif
#endif //  

  //ILA_NOT_NULL(fp);
  smtlib2_abstract_parser_parse_string(parser_wrapper, buffer);
  //smtlib2_abstract_parser_parse(&(parser_wrapper->parser), fp);

  //fclose(fp);
  delete[] buffer;
}

std::string SmtlibInvariantParser::GetFinalTranslateResult() const {
  return final_translate_result;
}
/// get the local variable definitions
const SmtlibInvariantParser::local_vars_t&
SmtlibInvariantParser::GetLocalVarDefs() const {
  return local_vars;
}

/// get the local variable definitions
const SmtlibInvariantParser::free_vars_t&
SmtlibInvariantParser::GetFreeVarDefs() const {
  return free_vars;
}

}; // namespace smt
}; // namespace ilang
