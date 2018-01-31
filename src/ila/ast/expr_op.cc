/// \file
/// Source for the op expression

#include "ila/ast/expr_op.h"

namespace ila {

// ------------------------- Class ExprOp ----------------------------------- //
ExprOp::ExprOp() { ILA_ERROR << "Undefined ExprOp constructor.\n"; }

ExprOp::ExprOp(const ExprPtr arg) {
  // arg
  ExprPtrVec args = {arg};
  set_args(args);
  // host
  set_host(arg->host());
}

ExprOp::ExprOp(const ExprPtr arg0, const ExprPtr arg1) {
  // args
  ExprPtrVec args = {arg0, arg1};
  set_args(args);
  // set host
  auto host0 = arg0->host();
  auto host1 = arg1->host();
  if (host0 == host1) {
    set_host(host0);
  } else if (host0 == NULL) {
    set_host(host1);
  } else if (host1 == NULL) {
    set_host(host0);
  }
}

ExprOp::ExprOp(const ExprPtr arg0, const ExprPtr arg1, const ExprPtr arg2) {
  // args
  ExprPtrVec args = {arg0, arg1, arg2};
  set_args(args);
  // set host
  auto host0 = arg0->host();
  auto host1 = arg1->host();
  auto host2 = arg2->host();
  if (host0 == host1 && host1 == host2) {
    set_host(host0);
  } else if (host1 == NULL && host2 == NULL) {
    set_host(host0);
  } else if (host0 == NULL && host2 == NULL) {
    set_host(host1);
  } else if (host0 == NULL && host1 == NULL) {
    set_host(host2);
  }
}

ExprOp::ExprOp(const ExprPtr arg0, const int& param1, const int& param2) {
  // args
  ExprPtrVec args = {arg0};
  set_args(args);
  // params
  std::vector<int> params = {param1, param2};
  set_params(params);
  // set hsot
  set_host(arg0->host());
}

ExprOp::~ExprOp() {}

std::ostream& ExprOp::Print(std::ostream& out) const {
  return out << name().format_str(op_name(), "");
}

Sort ExprOp::GetSortBinaryOperation(const Sort& s0, const Sort& s1) {
  ILA_ASSERT(s0 == s1) << "Undefined sorts " << s0 << " and " << s1
                       << " for binary operations.";
  // return the smae sort as input arguments.
  return s0;
}

Sort ExprOp::GetSortBinaryComparison(const Sort& s0, const Sort& s1) {
  ILA_ASSERT(s0 == s1) << "Undefined sorts " << s0 << " and " << s1
                       << " for binary comparison.";
  // return boolean sort.
  return Sort::MakeBoolSort();
}

// ------------------------- Class ExprOpNeg -------------------------------- //
ExprOpNeg::ExprOpNeg(const ExprPtr arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bv()) << "Negate can only be applied to bitvector.";
  set_sort(arg->sort());
}

z3::expr ExprOpNeg::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Negate is a unary function.";
  return -expr_vec[0];
}

// ------------------------- Class ExprOpNot -------------------------------- //
ExprOpNot::ExprOpNot(const ExprPtr arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bool()) << "Not can only be applied to bool.";
  set_sort(arg->sort());
}

z3::expr ExprOpNot::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Not is a unary function.";
  return !expr_vec[0];
}

// ------------------------- Class ExprOpCompl ------------------------------ //
ExprOpCompl::ExprOpCompl(const ExprPtr arg) : ExprOp(arg) {
  ILA_ASSERT(arg->is_bv()) << "Complement can only be applied to bitvector.";
  set_sort(arg->sort());
}

z3::expr ExprOpCompl::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Negate is a unary function.";
  return ~expr_vec[0];
}

// ------------------------- Class ExprOpAnd -------------------------------- //
ExprOpAnd::ExprOpAnd(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpAnd::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  ILA_ASSERT(is_bool() || is_bv()) << "AND can only be either bool or bv.";
  if (is_bool())
    return expr_vec[0] && expr_vec[1];
  else
    return expr_vec[0] & expr_vec[1];
}

// ------------------------- Class ExprOpOr --------------------------------- //
ExprOpOr::ExprOpOr(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpOr::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                             const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  ILA_ASSERT(is_bool() || is_bv()) << "OR can only be either bool or bv.";
  if (is_bool())
    return expr_vec[0] || expr_vec[1];
  else
    return expr_vec[0] | expr_vec[1];
}

// ------------------------- Class ExprOpXor -------------------------------- //
ExprOpXor::ExprOpXor(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpXor::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  ILA_ASSERT(is_bool() || is_bv()) << "XOR can only be either bool or bv.";
  if (is_bv()) {
    // auto ast_xor = Z3_mk_bvxor(ctx, expr_vec[0], expr_vec[1]);
    return expr_vec[0] ^ expr_vec[1];
    // return z3::to_expr(ctx, ast_xor);
  } else {
    auto ast_xor = Z3_mk_xor(ctx, expr_vec[0], expr_vec[1]);
    return z3::to_expr(ctx, ast_xor);
  }
}

// ------------------------- Class ExprOpAdd -------------------------------- //
ExprOpAdd::ExprOpAdd(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {
  set_sort(GetSortBinaryOperation(arg0->sort(), arg1->sort()));
}

z3::expr ExprOpAdd::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2) << "Add is binary operation.";
  ILA_ASSERT(is_bv()) << "ADD can only be applied to bv.";
  return expr_vec[0] + expr_vec[1];
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

// ------------------------- Class ExprOpLoad ------------------------------- //
ExprOpLoad::ExprOpLoad(const ExprPtr mem, const ExprPtr addr)
    : ExprOp(mem, addr) {
  ILA_ASSERT(mem->sort().addr_width() == addr->sort().bit_width())
      << "Address width does not match with memory.";
  // sort should be the data sort of the mem
  auto data_sort = Sort::MakeBvSort(mem->sort().data_width());
  set_sort(data_sort);
}

z3::expr ExprOpLoad::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                               const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 2);
  return z3::select(expr_vec[0], expr_vec[1]);
}

// ------------------------- Class ExprOpLoad ------------------------------- //
ExprOpStore::ExprOpStore(const ExprPtr mem, const ExprPtr addr,
                         const ExprPtr data)
    : ExprOp(mem, addr, data) {
  ILA_ASSERT(mem->sort().addr_width() == addr->sort().bit_width())
      << "Address width does not match with memory.";
  ILA_ASSERT(mem->sort().data_width() == data->sort().bit_width())
      << "Data width does not match with memory.";
  set_sort(mem->sort());
}

z3::expr ExprOpStore::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 3) << "Store takes 3 arguments.";
  auto mem = expr_vec[0];
  auto addr = expr_vec[1];
  auto data = expr_vec[2];
  return z3::store(mem, addr, data);
}

// ------------------------- Class ExprOpExtract ---------------------------- //
ExprOpExtract::ExprOpExtract(const ExprPtr bv, const int& hi, const int& lo)
    : ExprOp(bv, hi, lo) {
  ILA_ASSERT(bv->is_bv()) << "Extract can only be applied to bitvector.";
  ILA_ASSERT(hi >= lo) << "Invalid boundary for extraction.";
  set_sort(Sort::MakeBvSort(hi - lo + 1));
}

z3::expr ExprOpExtract::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                                  const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 1) << "Extract tale 1 argument.";
  ILA_ASSERT(num_param() == 2) << "Extract need two parameters.";
  auto bv = expr_vec[0];
  unsigned hi = static_cast<unsigned>(param(0));
  unsigned lo = static_cast<unsigned>(param(1));
  return bv.extract(hi, lo);
}

// ------------------------- Class ExprOpIte -------------------------------- //
ExprOpIte::ExprOpIte(const ExprPtr cnd, const ExprPtr true_expr,
                     const ExprPtr false_expr)
    : ExprOp(cnd, true_expr, false_expr) {
  ILA_ASSERT(cnd->is_bool()) << "Condition must be Boolean.";
  ILA_ASSERT(true_expr->sort() == false_expr->sort())
      << "True/false branch sort mismatch.";
  set_sort(true_expr->sort());
}

z3::expr ExprOpIte::GetZ3Expr(z3::context& ctx, const Z3ExprVec& expr_vec,
                              const std::string& suffix) const {
  ILA_ASSERT(expr_vec.size() == 3) << "Ite takes 3 arguments.";
  auto cnd = expr_vec[0];
  auto t_e = expr_vec[1];
  auto t_f = expr_vec[2];
  return z3::ite(cnd, t_e, t_f);
}

} // namespace ila

