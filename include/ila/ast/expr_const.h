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
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for Boolean constant.
  ExprConst(const BoolVal& bool_val);
  /// Constructor for Bitvector constant.
  ExprConst(const BvVal& bv_val, const int& bit_width);
  /// Constructor for Array constant.
  ExprConst(const MemVal& mem_val, const int& addr_width,
            const int& data_width);

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the prefix of the constant expression.
  const std::string& prefix() const { return k_prefix_const_; }

  // ------------------------- METHODS -------------------------------------- //
  /// Return true since this is a constant.
  bool IsConst() const { return true; }

  /// Return the z3 expression for the node.
  z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec) const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Value for Bool constant.
  BoolVal bool_val_;
  /// Value for Bitvector constant.
  BvVal bv_val_;
  /// Value for Memory constant.
  MemVal mem_val_;

  /// Static prefix for constant expression.
  static const std::string k_prefix_const_;

}; // class ExprConst

} // namespace ila

#endif // __EXPR_CONST_H__
