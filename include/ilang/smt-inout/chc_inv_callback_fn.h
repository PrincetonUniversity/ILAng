/// \file CHC Invariant Input Parsing
/// call back functions for smt-lib2 parser
/// declarations
// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef CHC_INV_CALLBACK_FN_H__
#define CHC_INV_CALLBACK_FN_H__

#include <ilang/smt-inout/chc_inv_in.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {
namespace smt {

//
// -------------- call back function declarations ---------------- //
//
// these are just proxy that forwards calls to the SmtlibInvariantParser
// member functions
// this is just because we can not pass function objects (lambda functions)
// to the legacy C code

// --- for abstract parser
// (forall
void proxy_push_quantifier_scope(smtlib2_parser_interface* p);

// ) ; end of forall
smtlib2_term proxy_pop_quantifier_scope(smtlib2_parser_interface* p);

// the special function dealing with the final term in a forall term
smtlib2_term proxy_make_forall_term(smtlib2_parser_interface* parser,
                                    smtlib2_term term);

// the special function dealing with the final term in an exists term
smtlib2_term proxy_make_exists_term(smtlib2_parser_interface* parser,
                                    smtlib2_term term);

// we will treat everything as an assert, although it does nothing
void proxy_assert_formula(smtlib2_parser_interface* parser, smtlib2_term term);

// in the case of CVC4 output, it will be a define-fun
void proxy_define_func(smtlib2_parser_interface* parser, const char* name,
                       smtlib2_vector* params, smtlib2_sort sort,
                       smtlib2_term term);
//
smtlib2_sort proxy_make_sort(smtlib2_parser_interface* p, const char* sortname,
                             smtlib2_vector* index);
//
void proxy_declare_variable(smtlib2_parser_interface* p, const char* name,
                            smtlib2_sort sort);

void proxy_declare_function(smtlib2_parser_interface* p, const char* name,
                            smtlib2_sort sort);

void proxy_check_sat(smtlib2_parser_interface* p);
// --- for term parser

smtlib2_term proxy_mk_function(smtlib2_context ctx, const char* symbol,
                               smtlib2_sort sort, smtlib2_vector* index,
                               smtlib2_vector* args);

smtlib2_term proxy_mk_number(smtlib2_context ctx, const char* rep,
                             unsigned int width, unsigned int base);
// handle the operators

#define SMTLIB2_VERILOG_DECLHANDLER(name)                                      \
  smtlib2_term smt_to_vlg_mk_##name(smtlib2_context ctx, const char* symbol,   \
                                    smtlib2_sort sort, smtlib2_vector* idx,    \
                                    smtlib2_vector* args)

SMTLIB2_VERILOG_DECLHANDLER(and);
SMTLIB2_VERILOG_DECLHANDLER(or);
SMTLIB2_VERILOG_DECLHANDLER(not);
SMTLIB2_VERILOG_DECLHANDLER(implies);
SMTLIB2_VERILOG_DECLHANDLER(eq);
SMTLIB2_VERILOG_DECLHANDLER(ite);
SMTLIB2_VERILOG_DECLHANDLER (xor);
SMTLIB2_VERILOG_DECLHANDLER(nand);

SMTLIB2_VERILOG_DECLHANDLER(true);
SMTLIB2_VERILOG_DECLHANDLER(false);

SMTLIB2_VERILOG_DECLHANDLER(concat);
SMTLIB2_VERILOG_DECLHANDLER(bvnot);
SMTLIB2_VERILOG_DECLHANDLER(bvand);
SMTLIB2_VERILOG_DECLHANDLER(bvnand);
SMTLIB2_VERILOG_DECLHANDLER(bvor);
SMTLIB2_VERILOG_DECLHANDLER(bvnor);
SMTLIB2_VERILOG_DECLHANDLER(bvxor);
SMTLIB2_VERILOG_DECLHANDLER(bvxnor);
SMTLIB2_VERILOG_DECLHANDLER(bvult);
SMTLIB2_VERILOG_DECLHANDLER(bvslt);
SMTLIB2_VERILOG_DECLHANDLER(bvule);
SMTLIB2_VERILOG_DECLHANDLER(bvsle);
SMTLIB2_VERILOG_DECLHANDLER(bvugt);
SMTLIB2_VERILOG_DECLHANDLER(bvsgt);
SMTLIB2_VERILOG_DECLHANDLER(bvuge);
SMTLIB2_VERILOG_DECLHANDLER(bvsge);
SMTLIB2_VERILOG_DECLHANDLER(bvcomp);
SMTLIB2_VERILOG_DECLHANDLER(bvneg);
SMTLIB2_VERILOG_DECLHANDLER(bvadd);
SMTLIB2_VERILOG_DECLHANDLER(bvsub);
SMTLIB2_VERILOG_DECLHANDLER(bvmul);
SMTLIB2_VERILOG_DECLHANDLER(bvudiv);
SMTLIB2_VERILOG_DECLHANDLER(bvsdiv);
SMTLIB2_VERILOG_DECLHANDLER(bvsmod);
SMTLIB2_VERILOG_DECLHANDLER(bvurem);
SMTLIB2_VERILOG_DECLHANDLER(bvsrem);
SMTLIB2_VERILOG_DECLHANDLER(bvshl);
SMTLIB2_VERILOG_DECLHANDLER(bvlshr);
SMTLIB2_VERILOG_DECLHANDLER(bvashr);
SMTLIB2_VERILOG_DECLHANDLER(extract);
SMTLIB2_VERILOG_DECLHANDLER(bit2bool);
SMTLIB2_VERILOG_DECLHANDLER(repeat);
SMTLIB2_VERILOG_DECLHANDLER(zero_extend);
SMTLIB2_VERILOG_DECLHANDLER(sign_extend);
SMTLIB2_VERILOG_DECLHANDLER(rotate_left);
SMTLIB2_VERILOG_DECLHANDLER(rotate_right);

#undef SMTLIB2_VERILOG_DECLHANDLER

}; // namespace smt
}; // namespace ilang

#endif // CHC_INV_CALLBACK_FN_H__
