/// \file
/// Header for the class Ast.

#ifndef __AST_H__
#define __AST_H__

#include "ila/object.h"
#include <memory>

/// \namespace ila
namespace ila {

/// \def AstType
typedef enum { AST_EXPR, AST_FUNC, AST_NONE } AstType;

/// \class Ast
/// The class for the Abstract Syntax Tree. An Ast object can be an expression
/// or function definition (interpreted or uninterpreted).
class Ast : public Object {
public:
  /// The constructor for the class Ast.
  Ast();
  /// The constructor for the class Ast with arity.
  Ast(const int& arity);
  /// The destructor for the class Ast.
  ~Ast();

  /// Get Object type (inherited virtual function).
  /// \return ObjType::OBJ_AST
  ObjType GetObjType() const;

  /// Virtual function for getting ast type, e.g. expr, func, etc.
  virtual AstType GetAstType() const;

  /// Getting the arity.
  const int& Arity() const;

private:
  /// Arity.
  int arity_;

}; // class Ast

typedef std::shared_ptr<Ast> AstPtr;

} // namespace ila

#endif // __AST_H__

