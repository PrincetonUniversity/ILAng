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
  /// Default constructor. DO NOT USE.
  ExprConst();
  /// Constructor for Boolean constant.
  ExprConst(const BoolVal& bool_val);
  /// Constructor for Bitvector constant.
  ExprConst(const BvVal& bv_val, const int& bit_width);
  /// Constructor for Array constant.
  ExprConst(const MemVal& mem_val, const int& addr_width,
            const int& data_width);
  /// Default destructor.
  ~ExprConst();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the prefix of the constant expression.
  const std::string& prefix() const { return k_prefix_const_; }

  /// Return true since this is a constant.
  bool is_const() const { return true; }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3 expression for the node.
  z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec,
                     const std::string& suffix = "") const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Value for Bool constant.
  BoolValPtr bool_ptr_;
  /// Value for Bitvector constant.
  BvValPtr bv_ptr_;
  /// Value for Memory constant.
  MemValPtr mem_ptr_;

  /// Static prefix for constant expression.
  static const std::string k_prefix_const_;

}; // class ExprConst

} // namespace ila

#endif // __EXPR_CONST_H__
