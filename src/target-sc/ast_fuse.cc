/// \file
/// Source of AstFuse

#include "ast_fuse.h"

#include <memory>

#include <ilang/ila/ast/expr_const.h>
#include <ilang/ila/ast/expr_op.h>
#include <ilang/ila/ast/expr_var.h>
#include <ilang/ila/ast/sort.h>
#include <ilang/ila/ast/sort_value.h>
#include <ilang/util/log.h>

namespace ilang {

AST_UID_SORT GetUidSort(const SortPtr& sort) {
  if (sort->is_bool()) {
    return AST_UID_SORT::BOOL;
  } else if (sort->is_bv()) {
    return AST_UID_SORT::BV;
  } else {
    return AST_UID_SORT::MEM;
  }
}

AST_UID_EXPR GetUidExpr(const ExprPtr& expr) {
  if (expr->is_var()) {
    return AST_UID_EXPR::VAR;
  } else if (expr->is_const()) {
    return AST_UID_EXPR::CONST;
  } else {
    return AST_UID_EXPR::OP;
  }
}

AST_UID_EXPR_OP GetUidExprOp(const ExprPtr& expr) {
  auto expr_op = std::dynamic_pointer_cast<ExprOp>(expr);
  if (!expr_op) {
    return AST_UID_EXPR_OP::INVALID;
  }

  if (std::dynamic_pointer_cast<ExprOpNeg>(expr_op)) {
    return AST_UID_EXPR_OP::NEG;
  } else if (std::dynamic_pointer_cast<ExprOpNot>(expr_op)) {
    return AST_UID_EXPR_OP::NOT;
  } else if (std::dynamic_pointer_cast<ExprOpCompl>(expr_op)) {
    return AST_UID_EXPR_OP::COMPL;
  } else if (std::dynamic_pointer_cast<ExprOpAnd>(expr_op)) {
    return AST_UID_EXPR_OP::AND;
  } else if (std::dynamic_pointer_cast<ExprOpOr>(expr_op)) {
    return AST_UID_EXPR_OP::OR;
  } else if (std::dynamic_pointer_cast<ExprOpXor>(expr_op)) {
    return AST_UID_EXPR_OP::XOR;
  } else if (std::dynamic_pointer_cast<ExprOpShl>(expr_op)) {
    return AST_UID_EXPR_OP::SHL;
  } else if (std::dynamic_pointer_cast<ExprOpAshr>(expr_op)) {
    return AST_UID_EXPR_OP::ASHR;
  } else if (std::dynamic_pointer_cast<ExprOpLshr>(expr_op)) {
    return AST_UID_EXPR_OP::LSHR;
  } else if (std::dynamic_pointer_cast<ExprOpAdd>(expr_op)) {
    return AST_UID_EXPR_OP::ADD;
  } else if (std::dynamic_pointer_cast<ExprOpSub>(expr_op)) {
    return AST_UID_EXPR_OP::SUB;
  } else if (std::dynamic_pointer_cast<ExprOpDiv>(expr_op)) {
    return AST_UID_EXPR_OP::DIV;
  } else if (std::dynamic_pointer_cast<ExprOpSRem>(expr_op)) {
    return AST_UID_EXPR_OP::SREM;
  } else if (std::dynamic_pointer_cast<ExprOpURem>(expr_op)) {
    return AST_UID_EXPR_OP::UREM;
  } else if (std::dynamic_pointer_cast<ExprOpSMod>(expr_op)) {
    return AST_UID_EXPR_OP::SMOD;
  } else if (std::dynamic_pointer_cast<ExprOpMul>(expr_op)) {
    return AST_UID_EXPR_OP::MUL;
  } else if (std::dynamic_pointer_cast<ExprOpEq>(expr_op)) {
    return AST_UID_EXPR_OP::EQ;
  } else if (std::dynamic_pointer_cast<ExprOpLt>(expr_op)) {
    return AST_UID_EXPR_OP::LT;
  } else if (std::dynamic_pointer_cast<ExprOpGt>(expr_op)) {
    return AST_UID_EXPR_OP::GT;
  } else if (std::dynamic_pointer_cast<ExprOpUlt>(expr_op)) {
    return AST_UID_EXPR_OP::ULT;
  } else if (std::dynamic_pointer_cast<ExprOpUgt>(expr_op)) {
    return AST_UID_EXPR_OP::UGT;
  } else if (std::dynamic_pointer_cast<ExprOpLoad>(expr_op)) {
    return AST_UID_EXPR_OP::LOAD;
  } else if (std::dynamic_pointer_cast<ExprOpStore>(expr_op)) {
    return AST_UID_EXPR_OP::STORE;
  } else if (std::dynamic_pointer_cast<ExprOpConcat>(expr_op)) {
    return AST_UID_EXPR_OP::CONCAT;
  } else if (std::dynamic_pointer_cast<ExprOpExtract>(expr_op)) {
    return AST_UID_EXPR_OP::EXTRACT;
  } else if (std::dynamic_pointer_cast<ExprOpZExt>(expr_op)) {
    return AST_UID_EXPR_OP::ZEXT;
  } else if (std::dynamic_pointer_cast<ExprOpSExt>(expr_op)) {
    return AST_UID_EXPR_OP::SEXT;
  } else if (std::dynamic_pointer_cast<ExprOpLRotate>(expr_op)) {
    return AST_UID_EXPR_OP::LROTATE;
  } else if (std::dynamic_pointer_cast<ExprOpRRotate>(expr_op)) {
    return AST_UID_EXPR_OP::RROTATE;
  } else if (std::dynamic_pointer_cast<ExprOpAppFunc>(expr_op)) {
    return AST_UID_EXPR_OP::APP_FUNC;
  } else if (std::dynamic_pointer_cast<ExprOpImply>(expr_op)) {
    return AST_UID_EXPR_OP::IMPLY;
  } else {
    auto expr_op_ite = std::dynamic_pointer_cast<ExprOpIte>(expr_op);
    ILA_NOT_NULL(expr_op_ite);
    return AST_UID_EXPR_OP::ITE;
  }
}

}; // namespace ilang
