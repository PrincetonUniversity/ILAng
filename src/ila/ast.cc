/// \file
/// Source for the class Ast.

#include "ila/ast.h"

namespace ila {

Ast::Ast() {}

Ast::~Ast() {}

ObjType Ast::GetObjType() const { return ObjType::OBJ_AST; }

} // namespace ila

