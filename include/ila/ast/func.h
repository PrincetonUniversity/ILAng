/// \file
/// Header for the class Func (uninterpreted function).

#ifndef FUNC_H__
#define FUNC_H__

#include "ila/ast/ast.h"
#include "ila/ast/sort.h"
#include "ila/defines.h"

/// \namespace ila
namespace ila {

/// \brief The class for uninterpreted function declaration and constraints.
class Func : public Ast {
public:
  /// Pointer type for normal use of Func.
  typedef std::shared_ptr<Func> FuncPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Func();
  /// Default destructor.
  ~Func();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3 expression for the function.
  z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec,
                     const std::string& suffix = "") const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  // ------------------------- HELPERS -------------------------------------- //
}; // class Func

/// Pointer type for normal use of Func.
typedef Func::FuncPtr FuncPtr;

} // namespace ila

#endif // FUNC_H__

