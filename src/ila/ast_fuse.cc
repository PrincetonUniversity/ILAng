/// \file
/// Source of AstFuse

#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>
#include <memory>

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
  if (exprr->is_var()) {
    return AST_UID_EXPR::VAR;
  } else if (expr->is_const()) {
    return AST_UID_EXPR::CONST;
  } else {
    return AST_UID_EXPR::OP;
  }
}

AST_UID_EXPR_OP GetUidExprOp(const ExprPtr& expr) {
  auto expr_op = std::dynamic_poiner_cast<ExprOp>(expr);
  if (!expr_op) {
    return AST_UID_EXPR::INVALID;
  }

  if (std::dynamic_pointer_cast<ExprOpNeg>(expr_op)) {
    return AST_UID_EXPR::NEG;
  } else if (std::dynamic_pointer_cast<ExprOpNot>(expr_op)) {
    return AST_UID_EXPR::NOT;
  } else if (std::dynamic_pointer_cast<ExprOpCompl>(expr_op)) {
    return AST_UID_EXPR::COMPL;
  } else if (std::dynamic_pointer_cast<ExprOpAnd>(expr_op)) {
    return AST_UID_EXPR::AND;
  } else if (std::dynamic_pointer_cast<ExprOpOr>(expr_op)) {
    return AST_UID_EXPR::OR;
  } else if (std::dynamic_pointer_cast<ExprOpXor>(expr_op)) {
    return AST_UID_EXPR::XOR;
  } else if (std::dynamic_pointer_cast<ExprOpShl>(expr_op)) {
    return AST_UID_EXPR::SHL;
  } else if (std::dynamic_pointer_cast<ExprOpAshr>(expr_op)) {
    return AST_UID_EXPR::ASHR;
  } else if (std::dynamic_pointer_cast<ExprOpLshr>(expr_op)) {
    return AST_UID_EXPR::LSHR;
  } else if (std::dynamic_pointer_cast<ExprOpAdd>(expr_op)) {
    return AST_UID_EXPR::ADD;
  } else if (std::dynamic_pointer_cast<ExprOpSub>(expr_op)) {
    return AST_UID_EXPR::SUB;
  } else if (std::dynamic_pointer_cast<ExprOpEq>(expr_op)) {
    return AST_UID_EXPR::EQ;
  } else if (std::dynamic_pointer_cast<ExprOpLt>(expr_op)) {
    return AST_UID_EXPR::LT;
  } else if (std::dynamic_pointer_cast<ExprOpGt>(expr_op)) {
    return AST_UID_EXPR::GT;
  } else if (std::dynamic_pointer_cast<ExprOpUlt>(expr_op)) {
    return AST_UID_EXPR::ULT;
  } else if (std::dynamic_pointer_cast<ExprOpUgt>(expr_op)) {
    return AST_UID_EXPR::UGT;
  } else if (std::dynamic_pointer_cast<ExprOpLoad>(expr_op)) {
    return AST_UID_EXPR::LOAD;
  } else if (std::dynamic_pointer_cast<ExprOpStore>(expr_op)) {
    return AST_UID_EXPR::STORE;
  } else if (std::dynamic_pointer_cast<ExprOpConcat>(expr_op)) {
    return AST_UID_EXPR::CONCAT;
  } else if (std::dynamic_pointer_cast<ExprOpExtract>(expr_op)) {
    return AST_UID_EXPR::EXTRACT;
  } else if (std::dynamic_pointer_cast<ExprOpZExt>(expr_op)) {
    return AST_UID_EXPR::ZEXT;
  } else if (std::dynamic_pointer_cast<ExprOpSExt>(expr_op)) {
    return AST_UID_EXPR::SEXT;
  } else if (std::dynamic_pointer_cast<ExprOpAppFunc>(expr_op)) {
    return AST_UID_EXPR::APP_FUNC;
  } else if (std::dynamic_pointer_cast<ExprOpImply>(expr_op)) {
    return AST_UID_EXPR::IMPLY;
  } else {
    auto expr_op_ite = std::dynamic_pointer_cast<ExprOpIte>(expr_op);
    ILA_NOT_NULL(expr_op_ite);
    return AST_UID_EXPR::ITE;
  }
}

}; // namespace ilang

