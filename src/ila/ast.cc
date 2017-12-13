/// \file
/// Source for the class Ast.

#include "ila/ast.h"

namespace ila {

Ast::Ast() : arity_(0) {}

Ast::Ast(const int& arity) : arity_(arity) {}

Ast::Ast(const std::string& name) : Object(name) {}

Ast::Ast(const std::string& name, const int& arity)
    : Object(name), arity_(arity) {}

Ast::~Ast() {}

const int& Ast::Arity() const { return arity_; }

} // namespace ila

