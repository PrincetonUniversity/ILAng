/// \file
/// Header for constant expression

#ifndef __EXPR_CONST_H__
#define __EXPR_CONST_H__

#include "ila/ast/expr.h"
#include "ila/ast/sort_value.h"

/// \namespace ila
namespace ila {

/// \class ExprConst
/// Expression for constant values (bool, bv, or memory). Constant should be
/// terminating nodes in the AST.
class ExprConst : public Expr {
public:
  /// Constructor for Boolean constant.
  ExprConst(const BoolVal& bool_val);
  /// Constructor for Bitvector constant.
  ExprConst(const BvVal& bv_val);
  /// Constructor for Array constant.
  ExprConst(const MemVal& mem_val);

  bool IsConst() const { return true; }

  /// Return the z3 expression for the node.
  virtual z3::expr GetZ3Expr(z3::context& z3_ctx,
                             const Z3ExprVec& z3expr_vec) const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Static prefix for intermediate expression name.
  static const std::string k_prefix_const_;

}; // class ExprConst

} // namespace ila

#endif // __EXPR_CONST_H__
