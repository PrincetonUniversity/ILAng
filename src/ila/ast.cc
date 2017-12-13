/// \file
/// Source for the class Ast.

#include "ila/ast.h"

namespace ila {

Ast::Ast() {}

Ast::Ast(const int& arity) : arity_(arity) {}

Ast::~Ast() {}

const int& Ast::Arity() const { return arity_; }

} // namespace ila

