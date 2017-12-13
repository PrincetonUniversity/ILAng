/// \file
/// Source for the class Ast.

#include "ila/ast.h"

namespace ila {

Ast::Ast() {}

Ast::Ast(const int& arity) : arity_(arity) {}

Ast::~Ast() {}

ObjType Ast::GetObjType() const { return ObjType::OBJ_AST; }

AstType Ast::GetAstType() const { return AstType::AST_NONE; }

const int& Ast::Arity() const { return arity_; }

} // namespace ila

