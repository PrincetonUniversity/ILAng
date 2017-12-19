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
  ILA_ERROR << "Not imeplemented.\n"; // TODO
  return ctx_.bool_const("dummy");
}

void Z3ExprAdapter::Clear() { expr_map_.clear(); }

void Z3ExprAdapter::operator()(const ExprPtr expr) {
  ILA_ERROR << "Not implemented.\n"; // TODO
}

} // namespace ila

