/// \file
/// Source for the op expression

#include "ila/ast/expr_op.h"

namespace ila {

const std::string ExprOp::k_prefix_op_ = "op";

unsigned ExprOp::counter_ = 0;

// ------------------------- Class ExprOp ----------------------------------- //
ExprOp::ExprOp() { ILA_ERROR << "Undefined ExprOp constructor.\n"; }

ExprOp::ExprOp(const ExprPtr arg) {
  set_arity(1);
  ExprPtrVec args = {arg};
  set_args(args);
}

ExprOp::ExprOp(const ExprPtr arg0, const ExprPtr arg1) {
  set_arity(2);
  ExprPtrVec args = {arg0, arg1};
  set_args(args);
}

ExprOp::~ExprOp() {}

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
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

std::ostream& ExprOp::PrintUnaryOp(std::ostream& out,
                                   const std::string& op_name) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

// ------------------------- Class ExprOpNeg -------------------------------- //
ExprOpNeg::ExprOpNeg(const ExprPtr arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bv()) << "Negate can only be applied to bitvectors.\n";
  set_sort(arg->sort());
}

z3::expr ExprOpNeg::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Negate is a unary function.\n";
  return -expr_vec[0];
}

std::ostream& ExprOpNeg::Print(std::ostream& out) const {
  return PrintUnaryOp(out, op_name());
}

// ------------------------- Class ExprOpCompl ------------------------------ //
ExprOpCompl::ExprOpCompl(const ExprPtr arg) : ExprOp(arg) {
  // bit-wise complement "~", can be applied to both bool and bv.
  // see also "not" "!", which pre-required to be bool.
  set_sort(arg->sort());
}

z3::expr ExprOpCompl::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1);
  return ~expr_vec[0];
}

std::ostream& ExprOpCompl::Print(std::ostream& out) const {
  return PrintUnaryOp(out, op_name());
}

// ------------------------- Class ExprOpAnd -------------------------------- //
ExprOpAnd::ExprOpAnd(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpAnd::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  return expr_vec[0] & expr_vec[1];
}

std::ostream& ExprOpAnd::Print(std::ostream& out) const {
  return PrintBinaryOp(out, op_name());
}

// ------------------------- Class ExprOpOr --------------------------------- //
ExprOpOr::ExprOpOr(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpOr::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                             const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  return expr_vec[0] | expr_vec[1];
}

std::ostream& ExprOpOr::Print(std::ostream& out) const {
  return PrintBinaryOp(out, op_name());
}

// ------------------------- Class ExprOpEq --------------------------------- //
ExprOpEq::ExprOpEq(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryComparison(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpEq::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                             const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  return expr_vec[0] == expr_vec[1];
}

std::ostream& ExprOpEq::Print(std::ostream& out) const {
  return PrintBinaryOp(out, op_name());
}

} // namespace ila

