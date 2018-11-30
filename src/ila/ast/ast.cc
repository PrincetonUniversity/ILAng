/// \file
/// Source for the class Ast.

#include <ilang/ila/ast/ast.h>

namespace ilang {

typedef Ast::InstrLvlAbsPtr InstrLvlAbsPtr;

Ast::Ast() {}

Ast::Ast(const std::string& name) : Object(name) {}

Ast::~Ast() {}

void Ast::set_host(InstrLvlAbsPtr host) { host_ = host; }

} // namespace ilang
