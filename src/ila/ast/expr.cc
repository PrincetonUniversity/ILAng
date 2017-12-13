/// \file
/// Source for the class Expr

#include "ila/ast/expr.h"

namespace ila {

Expr::Expr() {}

Expr::Expr(const int& arity) : Ast(arity) {}

Expr::~Expr() {}

AstType Expr::GetAstType() const { return AstType::AST_EXPR; }

} // namespace ila

