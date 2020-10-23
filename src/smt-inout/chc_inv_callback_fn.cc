/// \file CHC Invariant Input Parsing
/// call back functions for smt-lib2 parser
/// Definitions
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/smt-inout/chc_inv_callback_fn.h>
#include <ilang/smt-inout/chc_inv_in.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

#include <vector>

namespace ilang {
namespace smt {

// make vector
template <class T> std::vector<T> make_vector(smtlib2_vector* iv) {
  std::vector<T> ret;
  if (!iv)
    return ret;

  auto l = SMTLIB2_VECTOR_SIZE(iv);
  intptr_t* ptr = SMTLIB2_VECTOR_ARRAY(iv);
  for (decltype(l) idx = 0; idx < l; ++idx)
    ret.push_back((T)(ptr[idx]));
  return ret;
}

#define PARSER(x) ((SmtlibInvariantParser *)(((smtlib2_abstract_parser*)x)->termparser_->ctx_))
#define TERM_T SmtlibInvariantParser::TermPtrT
#define SORT_T SmtlibInvariantParser::SortPtrT

// ------------------ CALL BACK FUNCTIONS ------------- //

void proxy_push_quantifier_scope(smtlib2_parser_interface* p) {
  (PARSER(p)->push_quantifier_scope());
}

smtlib2_term proxy_pop_quantifier_scope(smtlib2_parser_interface* p) {
  return (smtlib2_term)(PARSER(p)->pop_quantifier_scope());
}

// we will treat everything as an assert, although it does nothing
void proxy_assert_formula(smtlib2_parser_interface* parser, smtlib2_term term) {
  // here it should be where we get our result
  PARSER(parser)->assert_formula((TERM_T)term);
}

void proxy_define_func(smtlib2_parser_interface* parser, const char* name,
                       smtlib2_vector* params, smtlib2_sort sort,
                       smtlib2_term term) {

  auto idxv = make_vector<TERM_T>(params);
  PARSER(parser)->define_function(name, idxv, (SORT_T)(sort),
                                    (TERM_T)(term));
  // check the idxv (params) type
}

// the special function dealing with the final term in a forall term
smtlib2_term proxy_make_forall_term(smtlib2_parser_interface* parser,
                                    smtlib2_term term) {
  return term;
}

// the special function dealing with the final term in an exists term
smtlib2_term proxy_make_exists_term(smtlib2_parser_interface* parser,
                                    smtlib2_term term) {
  ILA_ERROR << "should not contain exists";
  return term;
}

/*

a_sort :
  SYMBOL
  {
      $$ = parser->make_sort(parser, $1, NULL);
      free($1);
  }
| '(' TK_UNDERSCORE SYMBOL int_list ')'
  {
      $$ = parser->make_sort(parser, $3, $4);
      smtlib2_vector_delete($4);
      free($3);
  }
| '(' SYMBOL sort_list ')'
  {
      $$ = parser->make_parametric_sort(parser, $2, $3);
      smtlib2_vector_delete($3);
      free($2);
  }
;

*/

smtlib2_sort proxy_make_sort(smtlib2_parser_interface* p, const char* sortname,
                             smtlib2_vector* index) {
  auto idxv = make_vector<int>(index);
  smtlib2_sort ret = 
      (smtlib2_sort)(PARSER(p)->make_sort(sortname, idxv));
  return ret;
  // free((void *)sortname);
  // if(index)
  //   smtlib2_vector_delete(index);
  // free the content?
}

void proxy_declare_variable(smtlib2_parser_interface* p, const char* name,
                            smtlib2_sort sort) {
  PARSER(p)->declare_quantified_variable(name, (SORT_T)sort);
  // free((void *)name);
}

void proxy_declare_function(smtlib2_parser_interface* p, const char* name,
                            smtlib2_sort sort) {
  PARSER(p)->declare_function(name, (SORT_T)sort);
}

void proxy_check_sat(smtlib2_parser_interface* p) {
  // do nothing
}

smtlib2_term proxy_mk_function(smtlib2_context ctx, const char* symbol,
                               smtlib2_sort sort, smtlib2_vector* index,
                               smtlib2_vector* args) {
  auto idxv = make_vector<int>(index);
  auto argsv = make_vector<TERM_T>(args);

  smtlib2_term ret = (smtlib2_term)(
      ((SmtlibInvariantParser*)ctx)->mk_function(symbol, (SORT_T)sort, idxv, argsv));
  // free(symbol);
  // if(index)
  //   smtlib2_vector_delete(index);
  // if(args)
  //   smtlib2_vector_delete(args);
  return ret;
}

smtlib2_term proxy_mk_number(smtlib2_context ctx, const char* rep,
                             unsigned int width, unsigned int base) {
  smtlib2_term ret =
      (smtlib2_term)(((SmtlibInvariantParser*)ctx)
                         ->mk_number(rep, width, base));
  // free(rep);
  return ret;
}

// ------------------ OPERATORS ------------- //

#define SMTLIB2_VERILOG_DEFHANDLER(name)                                       \
  smtlib2_term smt_to_vlg_mk_##name(smtlib2_context ctx, const char* symbol,   \
                                    smtlib2_sort sort, smtlib2_vector* idx,    \
                                    smtlib2_vector* args) {                    \
    auto idxv = make_vector<int>(idx);                                         \
    auto argsv = make_vector<TERM_T>(args);                                    \
    smtlib2_term ret = (smtlib2_term)(                                         \
        ((SmtlibInvariantParser*)ctx)                                          \
            ->mk_##name(symbol, (SORT_T)sort, idxv, argsv));                   \
    return ret;                                                                \
  }

// handle the operators
SMTLIB2_VERILOG_DEFHANDLER(true);
SMTLIB2_VERILOG_DEFHANDLER(false);

SMTLIB2_VERILOG_DEFHANDLER(and);
SMTLIB2_VERILOG_DEFHANDLER(or);
SMTLIB2_VERILOG_DEFHANDLER(not);
SMTLIB2_VERILOG_DEFHANDLER(implies);
SMTLIB2_VERILOG_DEFHANDLER(eq);
SMTLIB2_VERILOG_DEFHANDLER(ite);
SMTLIB2_VERILOG_DEFHANDLER(xor);
SMTLIB2_VERILOG_DEFHANDLER(nand);
SMTLIB2_VERILOG_DEFHANDLER(concat);
SMTLIB2_VERILOG_DEFHANDLER(bvnot);
SMTLIB2_VERILOG_DEFHANDLER(bvand);
SMTLIB2_VERILOG_DEFHANDLER(bvnand);
SMTLIB2_VERILOG_DEFHANDLER(bvor);
SMTLIB2_VERILOG_DEFHANDLER(bvnor);
SMTLIB2_VERILOG_DEFHANDLER(bvxor);
SMTLIB2_VERILOG_DEFHANDLER(bvxnor);
SMTLIB2_VERILOG_DEFHANDLER(bvult);
SMTLIB2_VERILOG_DEFHANDLER(bvslt);
SMTLIB2_VERILOG_DEFHANDLER(bvule);
SMTLIB2_VERILOG_DEFHANDLER(bvsle);
SMTLIB2_VERILOG_DEFHANDLER(bvugt);
SMTLIB2_VERILOG_DEFHANDLER(bvsgt);
SMTLIB2_VERILOG_DEFHANDLER(bvuge);
SMTLIB2_VERILOG_DEFHANDLER(bvsge);
SMTLIB2_VERILOG_DEFHANDLER(bvcomp);
SMTLIB2_VERILOG_DEFHANDLER(bvneg);
SMTLIB2_VERILOG_DEFHANDLER(bvadd);
SMTLIB2_VERILOG_DEFHANDLER(bvsub);
SMTLIB2_VERILOG_DEFHANDLER(bvmul);
SMTLIB2_VERILOG_DEFHANDLER(bvudiv);
SMTLIB2_VERILOG_DEFHANDLER(bvsdiv);
SMTLIB2_VERILOG_DEFHANDLER(bvsmod);
SMTLIB2_VERILOG_DEFHANDLER(bvurem);
SMTLIB2_VERILOG_DEFHANDLER(bvsrem);
SMTLIB2_VERILOG_DEFHANDLER(bvshl);
SMTLIB2_VERILOG_DEFHANDLER(bvlshr);
SMTLIB2_VERILOG_DEFHANDLER(bvashr);
SMTLIB2_VERILOG_DEFHANDLER(extract);
SMTLIB2_VERILOG_DEFHANDLER(bit2bool);
SMTLIB2_VERILOG_DEFHANDLER(repeat);
SMTLIB2_VERILOG_DEFHANDLER(zero_extend);
SMTLIB2_VERILOG_DEFHANDLER(sign_extend);
SMTLIB2_VERILOG_DEFHANDLER(rotate_left);
SMTLIB2_VERILOG_DEFHANDLER(rotate_right);

#undef SMTLIB2_VERILOG_DEFHANDLER

}; // namespace smt
}; // namespace ilang
