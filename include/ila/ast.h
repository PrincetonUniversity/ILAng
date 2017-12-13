/// \file
/// Header for the class Ast.

#ifndef __AST_H__
#define __AST_H__

#include "ila/object.h"
#include "ila/symbol.h"
#include <memory>

/// \namespace ila
namespace ila {

/// \class Ast
/// The class for the Abstract Syntax Tree. An Ast object can be an expression
/// or function definition (interpreted or uninterpreted).
class Ast : public Object {
public:
  /// The constructor for the class Ast.
  Ast();
  /// The destructor for the class Ast.
  ~Ast();

  /// Get Object type (inherited virtual function).
  /// \return ObjType::OBJ_AST
  virtual ObjType GetObjType() const;

private:
}; // class Ast

typedef std::shared_ptr<Ast> AstPtr;

} // namespace ila

#endif // __AST_H__

