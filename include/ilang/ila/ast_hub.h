/// \file
///

#ifndef ILANG_ILA_AST_HUB_H__
#define ILANG_ILA_AST_HUB_H__

#include <ilang/ila/ast/expr_const.h>
#include <ilang/ila/ast/expr_op.h>
#include <ilang/ila/ast/expr_var.h>
#include <ilang/ila/ast/func.h>

/// \namespace ilang
namespace ilang {

/// \namespace asthub
namespace asthub {

/// Helper to get the unified id of expr's sort.
inline AstUidSort GetUidSort(const ExprPtr& expr) {
  return expr->sort()->uid();
}

/// Helper to get the unified id of expr's operation.
inline AstUidExprOp GetUidExprOp(const ExprPtr& expr) {
  return std::dynamic_pointer_cast<ExprOp>(expr)->uid();
}

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
ExprPtr BvConst(const BvValType& val, const int& bit_width);
/// Create a bitvector constant from BvVal.
ExprPtr BvConst(const BvVal& val, const int& bit_width);
/// Create a memory constant with only the defauly value.
ExprPtr MemConst(const BvValType& def_val, const int& addr_width,
                 const int& data_width);
/// Create a memory constant from MemVal.
ExprPtr MemConst(const MemVal& val, const int& addr_width,
                 const int& data_width);

/******************************************************************************/
// Unary operation
/******************************************************************************/
/// Arithematic negate (bv only)
ExprPtr Negate(const ExprPtr& obj);
/// Boolean not (bool only)
ExprPtr Not(const ExprPtr& obj);
/// Bit-wise Complement (bv only)
ExprPtr Complement(const ExprPtr& obj);

/******************************************************************************/
// Binary operation
/******************************************************************************/
/// Logical AND
ExprPtr And(const ExprPtr& l, const ExprPtr& r);
/// Logical OR
ExprPtr Or(const ExprPtr& l, const ExprPtr& r);
/// Logical XOR
ExprPtr Xor(const ExprPtr& l, const ExprPtr& r);
/// Left shift (bv only) (l << r)
ExprPtr Shl(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic right shift (bv only) (l >> r)
ExprPtr Ashr(const ExprPtr& l, const ExprPtr& r);
/// Logical right shift (bv only) (l >> r)
ExprPtr Lshr(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic addition (bv only)
ExprPtr Add(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic subtraction (bv only)
ExprPtr Sub(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic unsigned division (bv only)
ExprPtr Div(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic signed remainder (bv only)
ExprPtr SRem(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic unsigned remainder (bv only)
ExprPtr URem(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic signed modular (bv only)
ExprPtr SMod(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic unsigned modular (bv only)
ExprPtr Mod(const ExprPtr& l, const ExprPtr& r);
/// Arithmetic unsigned multiply (bv only)
ExprPtr Mul(const ExprPtr& l, const ExprPtr& r);

// helper functions for constant arguments
/// Logical AND with Boolean constant.
ExprPtr And(const ExprPtr& l, const bool& r);
/// Logical OR with Boolean constant.
ExprPtr Or(const ExprPtr& l, const bool& r);
/// Logical XOR with Boolean constant.
ExprPtr Xor(const ExprPtr& l, const bool& r);
/// Left shift with int.
ExprPtr Shl(const ExprPtr& l, const int& r);
/// Arithmetic right shift with int.
ExprPtr Ashr(const ExprPtr& l, const int& r);
/// Logical right shift with int.
ExprPtr Lshr(const ExprPtr& l, const int& r);
/// Arithmetic addition with constant.
ExprPtr Add(const ExprPtr& l, const BvValType& r);
/// Arithmetic subtraction with constant.
ExprPtr Sub(const ExprPtr& l, const BvValType& r);
/// Arithmetic unsigned multiply with constant (bv only).
ExprPtr Mul(const ExprPtr& l, const BvValType& r);

/******************************************************************************/
// Comparison
/******************************************************************************/
/// Comparison: equal
ExprPtr Eq(const ExprPtr& l, const ExprPtr& r);
/// Comparison: not equal
ExprPtr Ne(const ExprPtr& l, const ExprPtr& r);
/// Comparison: signed less than (bv only)
ExprPtr Lt(const ExprPtr& l, const ExprPtr& r);
/// Comparison: signed greater than (bv only)
ExprPtr Gt(const ExprPtr& l, const ExprPtr& r);
/// Comparison: signed less than or equal to (bv only)
ExprPtr Le(const ExprPtr& l, const ExprPtr& r);
/// Comparison: signed greater than or equal to (bv only)
ExprPtr Ge(const ExprPtr& l, const ExprPtr& r);
/// Comparison: unsigned less than (bv only)
ExprPtr Ult(const ExprPtr& l, const ExprPtr& r);
/// Comparison: unsigned greater than (bv only)
ExprPtr Ugt(const ExprPtr& l, const ExprPtr& r);
/// Comparison: unsigned less than or equal to (bv only)
ExprPtr Ule(const ExprPtr& l, const ExprPtr& r);
/// Comparison: unsigned greater than or equal to (bv only)
ExprPtr Uge(const ExprPtr& l, const ExprPtr& r);

// helper functions for constant arguments
#if 0
/// Equal to Boolean.
ExprPtr Eq(const ExprPtr& l, const bool& r);
#endif
/// Equal to constant.
ExprPtr Eq(const ExprPtr& l, const BvValType& r);
/// Not equal to constant.
ExprPtr Ne(const ExprPtr& l, const BvValType& r);
/// Signed less than constant.
ExprPtr Lt(const ExprPtr& l, const BvValType& r);
/// Signed greater than constant.
ExprPtr Gt(const ExprPtr& l, const BvValType& r);
/// Signed less than or equal to constant.
ExprPtr Le(const ExprPtr& l, const BvValType& r);
/// Signed greater than or equal to constant.
ExprPtr Ge(const ExprPtr& l, const BvValType& r);
/// Unsgned less than constant.
ExprPtr Ult(const ExprPtr& l, const BvValType& r);
/// Unsigned greater than constant.
ExprPtr Ugt(const ExprPtr& l, const BvValType& r);
/// Unsigned less than or equal to constant.
ExprPtr Ule(const ExprPtr& l, const BvValType& r);
/// Unsigned greater than or equal to constant.
ExprPtr Uge(const ExprPtr& l, const BvValType& r);

/******************************************************************************/
// Memory
/******************************************************************************/
/// Memory load
ExprPtr Load(const ExprPtr& mem, const ExprPtr& addr);
/// Memory store
ExprPtr Store(const ExprPtr& mem, const ExprPtr& addr, const ExprPtr& data);

/// Memory load from constant address
ExprPtr Load(const ExprPtr& mem, const BvValType& addr);
/// Memory store to constant address and data
ExprPtr Store(const ExprPtr& mem, const BvValType& addr, const BvValType& data);

/// Set memory size.
bool SetMemSize(const ExprPtr& mem, const int& size = 0);
/// Get memory size.
int GetMemSize(const ExprPtr& mem);

/******************************************************************************/
// Bit manipulation
/******************************************************************************/
/// Concatenate two bitvectors (bv only)
ExprPtr Concat(const ExprPtr& hi, const ExprPtr& lo);
/// Extract bit field in the bitvector (bv only)
ExprPtr Extract(const ExprPtr& bv, const int& hi, const int& lo);
/// Zero extend the bitvector to the specified length.
ExprPtr ZExt(const ExprPtr& bv, const int& out_width);
/// Sign extend the bitvector to the specified length.
ExprPtr SExt(const ExprPtr& bv, const int& out_width);
/// Left rotate the bitvector to immediate number of times.
ExprPtr LRotate(const ExprPtr& bv, const int& immediate);
/// Right rotate the bitvector to immediate number of times.
ExprPtr RRotate(const ExprPtr& bv, const int& immediate);

/******************************************************************************/
// Function usage
/******************************************************************************/
/// Apply function with zero argument.
ExprPtr AppFunc(const FuncPtr& func);
/// Apply function with one argument.
ExprPtr AppFunc(const FuncPtr& func, const ExprPtr& arg0);
/// Apply function with two argument.
ExprPtr AppFunc(const FuncPtr& func, const ExprPtr& arg0, const ExprPtr& arg1);
/// Apply function with arguments.
ExprPtr AppFunc(const FuncPtr& func, const ExprPtrVec& args);

/******************************************************************************/
// Others
/******************************************************************************/
/// Logical imply (bool only)
ExprPtr Imply(const ExprPtr& p, const ExprPtr& q);
/// If-then-else (condition bool only)
ExprPtr Ite(const ExprPtr& cnd, const ExprPtr& true_expr,
            const ExprPtr& false_expr);

/******************************************************************************/
// Non-AST construction utilities
/******************************************************************************/
/// Topologically equivalent.
bool TopEq(const ExprPtr& a, const ExprPtr& b);

} // namespace asthub

} // namespace ilang

#endif // ILANG_ILA_AST_HUB_H__
