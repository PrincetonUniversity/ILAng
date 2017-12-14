/// \file
/// Source for the class Expr

#include "ila/ast/expr.h"

namespace ila {

Expr::Expr() {}

Expr::Expr(const int& arity) : Ast(arity) {}

Expr::Expr(const std::string& name) : Ast(name) {}

Expr::Expr(const std::string& name, const int& arity) : Ast(name, arity) {}

Expr::~Expr() {}

} // namespace ila

