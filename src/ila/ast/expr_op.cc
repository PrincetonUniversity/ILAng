/// \file
/// Source for the op expression

#include "ila/ast/expr_op.h"

namespace ila {

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

ExprOp::ExprOp(const ExprPtr arg0, const ExprPtr arg1, const ExprPtr arg2) {
  set_arity(3);
  ExprPtrVec args = {arg0, arg1, arg2};
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
  return Sort::MakeBoolSort();
}

std::ostream& ExprOp::PrintBinaryOp(std::ostream& out,
                                    const std::string& op_name) const {
  return out << op_name;
}

std::ostream& ExprOp::PrintUnaryOp(std::ostream& out,
                                   const std::string& op_name) const {
  return out << op_name;
}

std::ostream& ExprOp::PrintNnaryOp(std::ostream& out,
                                   const std::string& op_name) const {
  return out << op_name;
}

// ------------------------- Class ExprOpNeg -------------------------------- //
ExprOpNeg::ExprOpNeg(const ExprPtr arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bv()) << "Negate can only be applied to bitvector.\n";
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

// ------------------------- Class ExprOpNot -------------------------------- //
ExprOpNot::ExprOpNot(const ExprPtr arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bool()) << "Not can only be applied to bool.\n";
  set_sort(arg->sort());
}

z3::expr ExprOpNot::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Not is a unary function.\n";
  return !expr_vec[0];
}

std::ostream& ExprOpNot::Print(std::ostream& out) const {
  return PrintUnaryOp(out, op_name());
}

// ------------------------- Class ExprOpCompl ------------------------------ //
ExprOpCompl::ExprOpCompl(const ExprPtr arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bv()) << "Complement can only be applied to bitvector.\n";
  set_sort(arg->sort());
}

z3::expr ExprOpCompl::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Negate is a unary function.\n";
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

// ------------------------- Class ExprOpXor -------------------------------- //
ExprOpXor::ExprOpXor(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpXor::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  return expr_vec[0] ^ expr_vec[1];
#if 0
  ILA_ASSERT(expr_vec.size() == 2);
  if (is_bv() {
    auto ast_xor = Z3_mk_bvxor(ctx, expr_vec[0], expr_vec[1]);
    return z3::to_expr(ctx, ast_xor);
  } else {
    ILA_ASSERT(is_bool()) << "XOR must be either bool or bv.\n";
    auto ast_xor = Z3_mk_xor(ctx, expr_vec[0], expr_vec[1]);
    return z3::to_expr(ctx, ast_xor);
  }
#endif
}

std::ostream& ExprOpXor::Print(std::ostream& out) const {
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

// ------------------------- Class ExprOpLoad ------------------------------- //
ExprOpLoad::ExprOpLoad(const ExprPtr mem, const ExprPtr addr)
    : ExprOp(mem, addr) {
  ILA_ASSERT(mem->sort().addr_width() == addr->sort().bit_width())
      << "Address width does not match with memory.\n";
  // sort should be the data sort of the mem
  auto data_sort = Sort::MakeBvSort(mem->sort().data_width());
  set_sort(data_sort);
}

z3::expr ExprOpLoad::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  return z3::select(expr_vec[0], expr_vec[1]);
}

std::ostream& ExprOpLoad::Print(std::ostream& out) const {
  return PrintBinaryOp(out, op_name());
}

// ------------------------- Class ExprOpLoad ------------------------------- //
ExprOpStore::ExprOpStore(const ExprPtr mem, const ExprPtr addr,
                         const ExprPtr data)
    : ExprOp(mem, addr, data) {
  ILA_ASSERT(mem->sort().addr_width() == addr->sort().bit_width())
      << "Address width does not match with memory.\n";
  ILA_ASSERT(mem->sort().data_width() == data->sort().bit_width())
      << "Data width does not match with memory.\n";
  set_sort(mem->sort());
}

z3::expr ExprOpStore::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 3) << "Store takes 3 arguments.\n";
  auto mem = expr_vec[0];
  auto addr = expr_vec[1];
  auto data = expr_vec[2];
  return z3::store(mem, addr, data);
}

std::ostream& ExprOpStore::Print(std::ostream& out) const {
  return PrintNnaryOp(out, op_name());
}

// ------------------------- Class ExprOpIte -------------------------------- //
ExprOpIte::ExprOpIte(const ExprPtr cnd, const ExprPtr true_expr,
                     const ExprPtr false_expr)
    : ExprOp(cnd, true_expr, false_expr) {
  ILA_ASSERT(cnd->is_bool()) << "Condition must be Boolean.\n";
  ILA_ASSERT(true_expr->sort() == false_expr->sort())
      << "True/false branch sort mismatch.\n";
  set_sort(true_expr->sort());
}

z3::expr ExprOpIte::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 3) << "Ite takes 3 arguments.\n";
  auto cnd = expr_vec[0];
  auto t_e = expr_vec[1];
  auto t_f = expr_vec[2];
  return z3::ite(cnd, t_e, t_f);
}

std::ostream& ExprOpIte::Print(std::ostream& out) const {
  return PrintNnaryOp(out, op_name());
}

} // namespace ila

