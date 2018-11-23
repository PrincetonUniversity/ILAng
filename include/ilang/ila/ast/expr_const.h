/// \file
/// Header for constant expression

#ifndef EXPR_CONST_H__
#define EXPR_CONST_H__

#include "ila/ast/expr.h"
#include "ila/ast/sort_value.h"

/// \namespace ila
namespace ila {

/// \brief Expression for constant values (bool, bv, or memory). Constant should
/// be terminating nodes in the AST.
class ExprConst : public Expr {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for Boolean constant.
  ExprConst(const BoolVal& bool_val);
  /// Constructor for Bitvector constant.
  ExprConst(const BvVal& bv_val, const int& bit_width);
  /// Constructor for Memory constant.
  ExprConst(const MemVal& mem_val, const int& addr_width,
            const int& data_width);
  /// Default destructor.
  ~ExprConst();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return true since this is a constant.
  bool is_const() const { return true; }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the z3 expression for the node.
  z3::expr GetZ3Expr(z3::context& z3_ctx, const Z3ExprVec& z3expr_vec,
                     const std::string& suffix = "") const;

  /// Output to stream.
  std::ostream& Print(std::ostream& out) const;

  /// Return the Boolean value.
  BoolValPtr val_bool() const;
  /// Return the Bitvector value.
  BvValPtr val_bv() const;
  /// Return the Memory value.
  MemValPtr val_mem() const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Value of the constant.
  ValPtr val_;

}; // class ExprConst

} // namespace ila

#endif // EXPR_CONST_H__

