/// \file
/// Source for the class Z3EXprAdapter

#include "ila/z3_expr_adapter.h"
#include "util/log.h"

namespace ila {

Z3ExprAdapter::Z3ExprAdapter(z3::context& ctx) : ctx_(ctx) {}

Z3ExprAdapter::~Z3ExprAdapter() {}

z3::expr Z3ExprAdapter::GetExpr(const ExprPtr expr, const std::string& suffix) {
  expr_map_.clear();
  suffix_ = suffix;

  expr->DepthFirstVisit(*this);

  // auto pos = expr_map_.find(expr.get());
  auto pos = expr_map_.find(expr);
  ILA_ASSERT(pos != expr_map_.end()) << "z3 expr cannot be generated.";

  return pos->second;
}

void Z3ExprAdapter::operator()(const ExprPtr expr) {
  auto pos = expr_map_.find(expr);
  // expression has been generated.
  if (pos != expr_map_.end()) {
    return;
  }

  // expression not generated yet. Try to construct.
  try {
    PopulateExprMap(expr);
  } catch (z3::exception& e) {
    ILA_ERROR << e.msg();
  }
}

void Z3ExprAdapter::PopulateExprMap(const ExprPtr expr) {
  size_t num = expr->arg_num();

  // reserve the container for argument expressions.
  Z3ExprVec expr_vec;
  expr_vec.reserve(num);

  // all arguments should already have expressions, put them in the container.
  for (size_t i = 0; i != num; i++) {
    ExprPtr arg_i = expr->arg(i);
    auto pos = expr_map_.find(arg_i);
    ILA_ASSERT(pos != expr_map_.end()) << "No expressions found for argument "
                                       << i;
    expr_vec.push_back(pos->second);
  }

  // get the expression based on different type of the ast node.
  z3::expr res = expr->GetZ3Expr(ctx_, expr_vec, suffix_);

  // simplify expression
  res = res.simplify();

  // polulate in the expr cache.
  expr_map_.insert({expr, res});
}

} // namespace ila

