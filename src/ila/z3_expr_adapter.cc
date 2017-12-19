/// \file
/// Source for the class Z3EXprAdapter

#include "ila/z3_expr_adapter.h"
#include "util/log.h"

namespace ila {

Z3ExprAdapter::Z3ExprAdapter(z3::context& ctx) : ctx_(ctx) { simplify_ = true; }

Z3ExprAdapter::~Z3ExprAdapter() {}

const bool& Z3ExprAdapter::simplify() const { return simplify_; }

z3::context& Z3ExprAdapter::ctx() const { return ctx_; }

void Z3ExprAdapter::set_simplify(const bool& sim) { simplify_ = sim; }

z3::expr Z3ExprAdapter::GetZ3Expr(const ExprPtr expr,
                                  const std::string& suffix) {
  suffix_ = suffix;
  expr->DepthFirstVisit(*this);

  auto pos = expr_map_.find(expr.get());
  ILA_ASSERT(pos != expr_map_.end()) << "z3 expr cannot be generated.\n";

  if (pos != expr_map_.end()) {
    return pos->second;
  } else {
    return ctx_.bool_val(false);
  }
}

void Z3ExprAdapter::Clear() { expr_map_.clear(); }

void Z3ExprAdapter::operator()(const ExprPtrRaw expr) {
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

void Z3ExprAdapter::PopulateExprMap(const ExprPtrRaw expr) {
  size_t num_arg = expr->arity();

  // reserve the container for argument expressions.
  Z3ExprVec expr_vec;
  expr_vec.reserve(num_arg);

  // all brguments should already have expressions, put them in the container.
  for (size_t i = 0; i != num_arg; i++) {
    ExprPtr arg_i = expr->arg(i);
    auto pos = expr_map_.find(arg_i.get());
    ILA_ASSERT(pos != expr_map_.end()) << "No expressions found for argument "
                                       << i << ".\n";
    expr_vec.push_back(pos->second);
  }

  // get the expression based on different type of the ast node.
  z3::expr res = expr->GetZ3Expr(ctx_, expr_vec, suffix_);
  // FIXME need to pass the suffix to nodes.

  // polulate in the expr cache.
  expr_map_.insert({expr, res});
}

} // namespace ila

