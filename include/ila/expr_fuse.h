/// \file
/// Header of the wrapping Expr usage

#ifndef EXPR_FUSE_H__
#define EXPR_FUSE_H__

#include "ila/ast/expr.h"
#include "ila/ast/expr_const.h"
#include "ila/ast/expr_op.h"
#include "ila/ast/expr_var.h"
#include "ila/ast/func.h"
#include "ila/ast/sort.h"
#include <string>

/// \namespace ila
namespace ila {

/// \namespace ExprFuse
/// Defines the wrapper for hiding imeplementation dependent type details.
namespace ExprFuse {
/******************************************************************************/
// Variable
/******************************************************************************/
/// Create new Boolean variable.
ExprPtr NewBoolVar(const std::string& name);
/// Create new bitvector variable.
ExprPtr NewBvVar(const std::string& name, const int& bit_width);
/// Create new memory variable.
ExprPtr NewMemVar(const std::string& name, const int& addr_width,
                  const int& data_width);

/******************************************************************************/
// Constant
/******************************************************************************/
/// Create a Boolean constant.
ExprPtr BoolConst(const bool& val);
/// Create a Boolean constant from BoolVal.
ExprPtr BoolConst(const BoolVal& val);
/// Create a bitvector constant.
ExprPtr BvConst(const int& val, const int& bit_width);
/// Create a bitvector constant from BvVal.
ExprPtr BvConst(const BvVal& val, const int& bit_width);
/// Create a memory constant with only the defauly value.
ExprPtr MemConst(const int& def_val, const int& addr_width,
                 const int& data_width);
/// Create a memory constant from MemVal.
ExprPtr MemConst(const MemVal& val, const int& addr_width,
                 const int& data_width);

/******************************************************************************/
// Unary operation
/******************************************************************************/
/// Arithematic negate (bv only)
ExprPtr Negate(const ExprPtr obj);
/// Boolean not (bool only)
ExprPtr Not(const ExprPtr obj);
/// Bit-wise Complement (bv only)
ExprPtr Complement(const ExprPtr obj);

/******************************************************************************/
// Binary operation
/******************************************************************************/
/// Logical AND
ExprPtr And(const ExprPtr l, const ExprPtr r);
/// Logical OR
ExprPtr Or(const ExprPtr l, const ExprPtr r);
/// Logical XOR
ExprPtr Xor(const ExprPtr l, const ExprPtr r);
/// Left shift (bv only) (l << r)
ExprPtr Shl(const ExprPtr l, const ExprPtr r);
/// Arithmetic right shift (bv only) (l >> r)
ExprPtr Ashr(const ExprPtr l, const ExprPtr r);
/// Logical right shift (bv only) (l >> r)
ExprPtr Lshr(const ExprPtr l, const ExprPtr r);
/// Arithmetic addition (bv only)
ExprPtr Add(const ExprPtr l, const ExprPtr r);
/// Arithmetic subtraction (bv only)
ExprPtr Sub(const ExprPtr l, const ExprPtr r);
/// Arithmetic unsigned division (bv only)
ExprPtr Div(const ExprPtr l, const ExprPtr r);
/// Arithmetic unsigned remainder (bv only)
ExprPtr Rem(const ExprPtr l, const ExprPtr r);
/// Arithmetic unsigned modular (bv only)
ExprPtr Mod(const ExprPtr l, const ExprPtr r);
/// Arithmetic unsigned multiply (bv only)
ExprPtr Mul(const ExprPtr l, const ExprPtr r);

// helper functions for constant arguments
/// Logical AND with Boolean constant.
ExprPtr And(const ExprPtr l, const bool& r);
/// Logical OR with Boolean constant.
ExprPtr Or(const ExprPtr l, const bool& r);
/// Logical XOR with Boolean constant.
ExprPtr Xor(const ExprPtr l, const bool& r);
/// Left shift with int.
ExprPtr Shl(const ExprPtr l, const int& r);
/// Arithmetic right shift with int.
ExprPtr Ashr(const ExprPtr l, const int& r);
/// Logical right shift with int.
ExprPtr Lshr(const ExprPtr l, const int& r);
/// Arithmetic addition with int.
ExprPtr Add(const ExprPtr l, const int& r);
/// Arithmetic subtraction with int.
ExprPtr Sub(const ExprPtr l, const int& r);

/******************************************************************************/
// Comparison
/******************************************************************************/
/// Comparison: equal
ExprPtr Eq(const ExprPtr l, const ExprPtr r);
/// Comparison: not equal
ExprPtr Ne(const ExprPtr l, const ExprPtr r);
/// Comparison: signed less than (bv only)
ExprPtr Lt(const ExprPtr l, const ExprPtr r);
/// Comparison: signed greater than (bv only)
ExprPtr Gt(const ExprPtr l, const ExprPtr r);
/// Comparison: signed less than or equal to (bv only)
ExprPtr Le(const ExprPtr l, const ExprPtr r);
/// Comparison: signed greater than or equal to (bv only)
ExprPtr Ge(const ExprPtr l, const ExprPtr r);
/// Comparison: unsigned less than (bv only)
ExprPtr Ult(const ExprPtr l, const ExprPtr r);
/// Comparison: unsigned greater than (bv only)
ExprPtr Ugt(const ExprPtr l, const ExprPtr r);
/// Comparison: unsigned less than or equal to (bv only)
ExprPtr Ule(const ExprPtr l, const ExprPtr r);
/// Comparison: unsigned greater than or equal to (bv only)
ExprPtr Uge(const ExprPtr l, const ExprPtr r);

// helper functions for constant arguments
/// Equal to Boolean.
ExprPtr Eq(const ExprPtr l, const bool& r);
/// Equal to int.
ExprPtr Eq(const ExprPtr l, const int& r);
/// Not equal to int.
ExprPtr Ne(const ExprPtr l, const int& r);
/// Signed less than int.
ExprPtr Lt(const ExprPtr l, const int& r);
/// Signed greater than int.
ExprPtr Gt(const ExprPtr l, const int& r);
/// Signed less than or equal to int.
ExprPtr Le(const ExprPtr l, const int& r);
/// Signed greater than or equal to int.
ExprPtr Ge(const ExprPtr l, const int& r);
/// Unsgned less than int.
ExprPtr Ult(const ExprPtr l, const int& r);
/// Unsigned greater than int.
ExprPtr Ugt(const ExprPtr l, const int& r);
/// Unsigned less than or equal to int.
ExprPtr Ule(const ExprPtr l, const int& r);
/// Unsigned greater than or equal to int.
ExprPtr Uge(const ExprPtr l, const int& r);

/******************************************************************************/
// Memory
/******************************************************************************/
/// Memory load
ExprPtr Load(const ExprPtr mem, const ExprPtr addr);
/// Memory store
ExprPtr Store(const ExprPtr mem, const ExprPtr addr, const ExprPtr data);

/// Memory load from constant address
ExprPtr Load(const ExprPtr mem, const int& addr);
/// Memory store to constant address and data
ExprPtr Store(const ExprPtr mem, const int& addr, const int& data);

/******************************************************************************/
// Bit manipulation
/******************************************************************************/
/// Concatenate two bitvectors (bv only)
ExprPtr Concat(const ExprPtr hi, const ExprPtr lo);
/// Extract bit field in the bitvector (bv only)
ExprPtr Extract(const ExprPtr bv, const int& hi, const int& lo);
/// Zero extend the bitvector to the specified length.
ExprPtr ZExt(const ExprPtr bv, const int& out_width);
/// Sign extend the bitvector to the specified length.
ExprPtr SExt(const ExprPtr bv, const int& out_width);

/******************************************************************************/
// Function usage
/******************************************************************************/
/// Apply function with zero argument.
ExprPtr AppFunc(const FuncPtr func);
/// Apply function with one argument.
ExprPtr AppFunc(const FuncPtr func, const ExprPtr arg0);
/// Apply function with two argument.
ExprPtr AppFunc(const FuncPtr func, const ExprPtr arg0, const ExprPtr arg1);
/// Apply function with arguments.
ExprPtr AppFunc(const FuncPtr func, const ExprPtrVec& args);

/******************************************************************************/
// Others
/******************************************************************************/
/// Logical imply (bool only)
ExprPtr Imply(const ExprPtr p, const ExprPtr q);
/// If-then-else (condition bool only)
ExprPtr Ite(const ExprPtr cnd, const ExprPtr true_expr,
            const ExprPtr false_expr);

/******************************************************************************/
// Non-AST construction utilities
/******************************************************************************/
/// Topologically equivalent.
bool TopEq(const ExprPtr a, const ExprPtr b);

} // namespace ExprFuse

} // namespace ila

#endif // EXPR_FUSE_H__

