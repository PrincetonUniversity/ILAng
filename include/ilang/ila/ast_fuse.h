/// \file
/// Helpers for handling the abstract syntax tree

#ifndef ILANG_ILA_AST_FUSE_H__
#define ILANG_ILA_AST_FUSE_H__

#include <ilang/ila/ast/expr.h>

/// \namespace ilang
namespace ilang {

/******************************************************************************/
// Unified AST ID
/******************************************************************************/
/// Unified ID for Sort.
enum AST_UID_SORT { BOOL = 1, BV, MEM };
/// Unified ID for Expr type.
enum AST_UID_EXPR { VAR = 1, CONST, OP };
/// Unified ID for ExprOp.
enum AST_UID_EXPR_OP {
  // XXX Add new op to the END of the list to make it backward compatible
  INVALID = 0,
  NEG,
  NOT,
  COMPL,
  AND,
  OR,
  XOR,
  SHL,
  ASHR,
  LSHR,
  ADD,
  SUB,
  MUL,
  EQ,
  LT,
  GT,
  ULT,
  UGT,
  LOAD,
  STORE,
  CONCAT,
  EXTRACT,
  ZEXT,
  SEXT,
  APP_FUNC,
  IMPLY,
  ITE,
  DIV,
  LROTATE,
  RROTATE,
  SREM,
  UREM,
  SMOD
};

/******************************************************************************/
// Wrapper for accessing the unified ID of the AST nodes
/******************************************************************************/
/// Return the AST_UID_SORT of the given Sort.
AST_UID_SORT GetUidSort(const SortPtr& sort);
/// Return the AST_UID_EXPR of the given Expr.
AST_UID_EXPR GetUidExpr(const ExprPtr& expr);
/// Return the AST_UID_EXPR_OP of the given Expr (must be ExprOp).
AST_UID_EXPR_OP GetUidExprOp(const ExprPtr& expr);

}; // namespace ilang

#endif // ILANG_ILA_AST_FUSE_H__
