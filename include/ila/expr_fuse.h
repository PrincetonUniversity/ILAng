/// \file
/// Header of the class ExprFuse

#ifndef __EXPR_FUSE_H__
#define __EXPR_FUSE_H__

#include "ila/ast/expr.h"
#include "ila/ast/expr_const.h"
#include "ila/ast/expr_op.h"
#include "ila/ast/expr_var.h"
#include "ila/ast/func.h"
#include "ila/ast/sort.h"
#include <string>

/// \namespace ila
namespace ila {

/// \class ExprFuse
/// ExprFuse is the uniform interface and wrapper for different types of
/// expressions, e.g. var, constant, and different operations.
class ExprFuse {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. NOT USED.
  ExprFuse();
  /// Default destructor. NOT USED.
  ~ExprFuse();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the prefix used when creating variables.
  static const std::string& prefix();
  /// Return the suffix used when creating variables.
  static const std::string& suffix();
  /// Set the prefix used when creating variables.
  static void set_prefix(const std::string& prefix);
  /// Set the suffix used when creating variables.
  static void set_suffix(const std::string& suffix);

  // ------------------------- METHODS -------------------------------------- //
  /// Reset string prefix/suffix.
  static void Reset();

  // static functions for wrapping the hierarchy of AST.

  /// Create new Boolean variable.
  static ExprPtr NewBoolVar(const std::string& name);
  /// Create new bitvector variable.
  static ExprPtr NewBvVar(const std::string& name, const int& bit_width);
  /// Create new memory variable.
  static ExprPtr NewMemVar(const std::string& name, const int& addr_width,
                           const int& data_width);

  /// Create a Boolean constant.
  static ExprPtr BoolConst(const bool& val);
  /// Create a Boolean constant from BoolVal.
  static ExprPtr BoolConst(const BoolVal& val);
  /// Create a bitvector constant.
  static ExprPtr BvConst(const int& val, const int& bit_width);
  /// Create a bitvector constant from BvVal.
  static ExprPtr BvConst(const BvVal& val, const int& bit_width);
  /// Create a memory constant with only the defauly value.
  static ExprPtr MemConst(const int& def_val, const int& addr_width,
                          const int& data_width);
  /// Create a memory constant from MemVal.
  static ExprPtr MemConst(const MemVal& val, const int& addr_width,
                          const int& data_width);

  /// Arithematic negate (bv only)
  static ExprPtr Negate(const ExprPtr obj);
  /// Complement (bit-wise "~")
  static ExprPtr Complement(const ExprPtr obj);
  /// Non-zero (bv only)
  static ExprPtr NonZero(const ExprPtr obj);

  /// Logical AND
  static ExprPtr And(const ExprPtr l, const ExprPtr r);
  /// Logical OR
  static ExprPtr Or(const ExprPtr l, const ExprPtr r);
  /// Logical XOR
  static ExprPtr Xor(const ExprPtr l, const ExprPtr r);
  /// Logical left shift (bv only) (l << r)
  static ExprPtr Shl(const ExprPtr l, const ExprPtr r);
  /// Logical right shift (bv only) (l >> r)
  static ExprPtr Shr(const ExprPtr l, const ExprPtr r);
  /// Arithmetic addition (bv only)
  static ExprPtr Add(const ExprPtr l, const ExprPtr r);
  /// Arithmetic subtraction (bv only)
  static ExprPtr Sub(const ExprPtr l, const ExprPtr r);
  /// Arithmetic unsigned division (bv only)
  static ExprPtr Div(const ExprPtr l, const ExprPtr r);
  /// Arithmetic unsigned remainder (bv only)
  static ExprPtr Rem(const ExprPtr l, const ExprPtr r);
  /// Arithmetic unsigned modular (bv only)
  static ExprPtr Mod(const ExprPtr l, const ExprPtr r);
  /// Arithmetic unsigned multiply (bv only)
  static ExprPtr Mul(const ExprPtr l, const ExprPtr r);
  // TODO int version helper functions

  /// Comparison: equal
  static ExprPtr Eq(const ExprPtr l, const ExprPtr r);
  /// Comparison: not equal
  static ExprPtr Neg(const ExprPtr l, const ExprPtr r);
  /// Comparison: unsigned less than (bv only)
  static ExprPtr Lt(const ExprPtr l, const ExprPtr r);
  /// Comparison: unsigned greater than (bv only)
  static ExprPtr Gt(const ExprPtr l, const ExprPtr r);
  /// Comparison: unsigned less than or equal to (bv only)
  static ExprPtr Le(const ExprPtr l, const ExprPtr r);
  /// Comparison: unsigned greater than or equal to (bv only)
  static ExprPtr Ge(const ExprPtr l, const ExprPtr r);
  // TODO int version helper functions

  /// Memory load
  static ExprPtr Load(const ExprPtr mem, const ExprPtr addr);
  /// Memory store
  static ExprPtr Store(const ExprPtr mem, const ExprPtr addr,
                       const ExprPtr data);

  /// Concatenate two bitvectors (bv only)
  static ExprPtr Concat(const ExprPtr lo, const ExprPtr hi);
  /// Extract bit field in the bitvector (bv only)
  static ExprPtr Extract(const ExprPtr obj, const int& hi, const int& lo);
  /// Zero extend the bitvector to the specified length.
  static ExprPtr ZeroExtend(const ExprPtr obj, const int& out_width);

  /// Logical imply (bool only)
  static ExprPtr Imply(const ExprPtr p, const ExprPtr q);

  /// If-then-else (condition bool only)
  static ExprPtr Ite(const ExprPtr cond, const ExprPtr true_expr,
                     const ExprPtr false_expr);

  /// Apply function with zero argument.
  static ExprPtr AppFunc(const FuncPtr func);
  /// Apply function with arguments.
  static ExprPtr AppFunc(const FuncPtr func, const ExprPtrVec& args);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Prefix used when creating variables.
  static std::string prefix_;
  /// Suffix used when creating variables.
  static std::string suffix_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class ExprFuse

} // namespace ila

#endif // __EXPR_FUSE_H__

