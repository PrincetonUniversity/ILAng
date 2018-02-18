/// \file
/// Header for the class ExprVar

#ifndef EXPR_VAR_H__
#define EXPR_VAR_H__

#include "ila/ast/expr.h"
#include <string>

/// \namespace ila
namespace ila {

/// \brief Expression for variables (bool, bv, or mem). Variable should be the
/// terminating nodes in the AST.
class ExprVar : public Expr {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for Boolean variable.
  ExprVar(const std::string& name);
  /// Constructor for Bitvector variable.
  ExprVar(const std::string& name, const int& bit_width);
  /// Constructor for Memory variable.
  ExprVar(const std::string& name, const int& addr_width,
          const int& data_width);

  /// Default destructor.
  ~ExprVar();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return true since this is a variable.
  bool is_var() const { return true; }

  // ------------------------- METHODS -------------------------------------- //

  /// Return the z3 expression for the node.
  z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec,
                     const std::string& suffix = "") const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //
  /// Print Boolean variable.
  std::ostream& PrintBool(std::ostream& out) const;
  /// Print Bitvector variable.
  std::ostream& PrintBv(std::ostream& out) const;
  /// Print Memory variable.
  std::ostream& PrintMem(std::ostream& out) const;

}; // class ExprVar

} // namespace ila

#endif // EXPR_VAR_H__

