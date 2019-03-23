/// \file CHC Invariant Input Parsing
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/smt-inout/chc_inv_in.h>
#include <ilang/smt-inout/chc_inv_callback_fn.h>

namespace ilang {
namespace smt {


// -------------- SmtlibInvariantParser ---------------- //

SmtlibInvariantParser::SmtlibInvariantParser() : 
  parser_wrapper(new smtlib2_abstract_parser_wrapper()),
  _bad_state(false) {

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
  pi->push_quantifier_scope = proxy_push_quantifier_scope;
  pi->pop_quantifier_scope  = proxy_pop_quantifier_scope;
  pi->make_sort = proxy_make_sort;
  pi->declare_variable = proxy_declare_variable;

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
  smtlib2_term_parser_set_handler(tp, "repeat",      smt_to_vlg_mk_repeat);
  smtlib2_term_parser_set_handler(tp, "zero_extend", smt_to_vlg_mk_zero_extend);
  smtlib2_term_parser_set_handler(tp, "sign_extend", smt_to_vlg_mk_sign_extend);
  smtlib2_term_parser_set_handler(tp, "rotate_left", smt_to_vlg_mk_rotate_left);
  smtlib2_term_parser_set_handler(tp, "rotate_right",smt_to_vlg_mk_rotate_right);
  
}


SmtlibInvariantParser::~SmtlibInvariantParser() {
  smtlib2_abstract_parser_deinit(&(parser_wrapper->parser));
  if(parser_wrapper)
    delete parser_wrapper;
}

bool SmtlibInvariantParser::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state) << "SmtlibInvariantParser is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return




/// call back function to handle (forall
SmtTermInfoVlgPtr SmtlibInvariantParser::push_quantifier_scope() {

}
/// call back function to handle ) of forall
SmtTermInfoVlgPtr SmtlibInvariantParser::pop_quantifier_scope() {

}
/// call back function to create a sort
var_type * SmtlibInvariantParser::make_sort(const std::string &name, const std::vector<int> &) {

}
/// call back function to create a temporary (quantified variable)
void SmtlibInvariantParser::declare_quantified_variable(const std::string &name, var_type * sort ) {

}
/// call back function to apply an uninterpreted function
/// fall-through case if it is not an defined op, if failed, return NULL
SmtTermInfoVlgPtr SmtlibInvariantParser::mk_function(
  const std::string &name, var_type * sort, 
  const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args) {

  }
/// call back function to make a number term
SmtTermInfoVlgPtr SmtlibInvariantParser::mk_number(const std::string & rep, int width, int base) {
  
}

#define DEFINE_OPERATOR(name) \
  SmtTermInfoVlgPtr SmtlibInvariantParser::mk_##name( \
    const std::string & symbol, var_type * sort, \
    const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args) 

DEFINE_OPERATOR(and) {
  
}
DEFINE_OPERATOR(or) {
  
}
DEFINE_OPERATOR(not) {
  
}
DEFINE_OPERATOR(implies) {
  
}
DEFINE_OPERATOR(eq) {
  
}
DEFINE_OPERATOR(ite) {
  
}
DEFINE_OPERATOR(xor) {
  
}
DEFINE_OPERATOR(nand) {
  
}
DEFINE_OPERATOR(concat) {
  
}
DEFINE_OPERATOR(bvnot) {
  
}
DEFINE_OPERATOR(bvand) {
  
}
DEFINE_OPERATOR(bvnand) {
  
}
DEFINE_OPERATOR(bvor) {
  
}
DEFINE_OPERATOR(bvnor) {
  
}
DEFINE_OPERATOR(bvxor) {
  
}
DEFINE_OPERATOR(bvxnor) {
  
}
DEFINE_OPERATOR(bvult) {
  
}
DEFINE_OPERATOR(bvslt) {
  
}
DEFINE_OPERATOR(bvule) {
  
}
DEFINE_OPERATOR(bvsle) {
  
}
DEFINE_OPERATOR(bvugt) {
  
}
DEFINE_OPERATOR(bvsgt) {
  
}
DEFINE_OPERATOR(bvuge) {
  
}
DEFINE_OPERATOR(bvsge) {
  
}
DEFINE_OPERATOR(bvcomp) {
  
}
DEFINE_OPERATOR(bvneg) {
  
}
DEFINE_OPERATOR(bvadd) {
  
}
DEFINE_OPERATOR(bvsub) {
  
}
DEFINE_OPERATOR(bvmul) {
  
}
DEFINE_OPERATOR(bvudiv) {
  
}
DEFINE_OPERATOR(bvsdiv) {
  
}
DEFINE_OPERATOR(bvsmod) {
  
}
DEFINE_OPERATOR(bvurem) {
  
}
DEFINE_OPERATOR(bvsrem) {
  
}
DEFINE_OPERATOR(bvshl) {
  
}
DEFINE_OPERATOR(bvlshr) {
  
}
DEFINE_OPERATOR(bvashr) {
  
}
DEFINE_OPERATOR(extract) {
  
}
DEFINE_OPERATOR(repeat) {
  
}
DEFINE_OPERATOR(zero_extend) {
  
}
DEFINE_OPERATOR(sign_extend) {
  
}
DEFINE_OPERATOR(rotate_left) {
  
}
DEFINE_OPERATOR(rotate_right) {
  
}

#undef DEFINE_OPERATOR
}; // namespace smt
}; // namespace ilang
