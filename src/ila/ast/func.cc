/// \file
/// Source for the class Func

#include "ila/ast/func.h"
#include "util/log.h"

namespace ila {

Func::Func() {}

Func::~Func() {}

z3::expr Func::GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec,
                         const std::string& suffix) const {
  // TODO
  return z3_ctx.bool_val(true);
}

std::ostream& Func::Print(std::ostream& out) const {
  // TODO
  return out << name();
}

} // namespace ila

