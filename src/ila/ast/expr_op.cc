/// \file
/// Source for the op expression

#include "ila/ast/expr_op.h"

namespace ila {

const std::string ExprOp::k_prefix_op_ = "op";

unsigned ExprOp::counter_ = 0;

// ------------------------- Class ExprOp ----------------------------------- //
ExprOp::ExprOp() { ILA_ERROR << "Undefined ExprOp constructor.\n"; }

ExprOp::ExprOp(const ExprPtr arg0, const ExprPtr arg1) {
  set_arity(2);
  ExprPtrVec args = {arg0, arg1};
  set_args(args);
}

ExprOp::~ExprOp() {}

#if 0
std::ostream& ExprOp::Print(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}
#endif

Sort ExprOp::GetSortBinaryOperation(const Sort& s0, const Sort& s1) {
  ILA_ASSERT(s0 == s1) << "Undefined sorts " << s0 << " & " << s1
                       << " for binary operations.\n";
  // return the smae sort as input arguments.
  return s0;
}

Sort ExprOp::GetSortBinaryComparison(const Sort& s0, const Sort& s1) {
  ILA_ASSERT(s0 == s1) << "Compare between different sorts " << s0 << " & "
                       << s1 << "\n";
  // return boolean sort.
  return Sort();
}

std::ostream& ExprOp::PrintBinaryOp(std::ostream& out,
                                    const std::string& op_name) const {
  ILA_ERROR << "Not implemented.\n";
  return out;
}

// ------------------------- Class ExprOp ----------------------------------- //
ExprOpAnd::ExprOpAnd(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpAnd::GetZ3Expr(z3::context& z3_ctx,
                              const Z3ExprVec& z3expr_vec) const {
  ILA_ASSERT(z3expr_vec.size() == 2);
  return z3expr_vec[0] & z3expr_vec[1]; // XXX check if sort-independent.
}

std::ostream& ExprOpAnd::Print(std::ostream& out) const {
  return PrintBinaryOp(out, op_name());
}

// ------------------------- Class ExprOp ----------------------------------- //
ExprOpOr::ExprOpOr(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpOr::GetZ3Expr(z3::context& z3_ctx,
                             const Z3ExprVec& z3expr_vec) const {
  ILA_ASSERT(z3expr_vec.size() == 2);
  return z3expr_vec[0] | z3expr_vec[1]; // XXX check if sort-independent.
}

std::ostream& ExprOpOr::Print(std::ostream& out) const {
  return PrintBinaryOp(out, op_name());
}

} // namespace ila

