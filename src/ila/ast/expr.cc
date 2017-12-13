/// \file
/// Source for the class Expr

#include "ila/ast/expr.h"

namespace ila {

Expr::Expr() {}

Expr::Expr(const int& arity) : Ast(arity) {}

Expr::~Expr() {}

bool Expr::IsExpr() const { return true; }

} // namespace ila

