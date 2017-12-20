/// \file
/// Unit test for the class Expr.

#include "ila/ast/expr.h"
#include "ila/ast/expr_const.h"
#include "ila/ast/expr_op.h"
#include "ila/ast/expr_var.h"
#include "gtest/gtest.h"

namespace ila {

TEST(ExprVar, Construct) {
  // ExprPtr var_null = std::make_shared<ExprVar>();
  ExprPtr var_bool = std::make_shared<ExprVar>("var_bool");
  ExprPtr var_bv_0 = std::make_shared<ExprVar>("var_bv_0", 8);
  ExprPtr var_bv_1 = std::make_shared<ExprVar>("var_bv_1", 8);
  ExprPtr var_mem = std::make_shared<ExprVar>("var_mem", 8, 8);

  EXPECT_TRUE(var_bool->is_expr());
  EXPECT_FALSE(var_bv_0->is_sort());
  EXPECT_FALSE(var_bv_0->is_func());

  EXPECT_TRUE(var_bool->is_var());
  EXPECT_TRUE(var_bv_0->is_var());
  EXPECT_FALSE(var_bv_1->is_op());
  EXPECT_FALSE(var_mem->is_const());
}

TEST(ExprConst, Construct) {
  BoolVal val_true(true);
  BoolVal val_false("False");
  ExprPtr const_true = std::make_shared<ExprConst>(val_true);
  ExprPtr const_false = std::make_shared<ExprConst>(val_false);

  EXPECT_TRUE(const_true->is_const());
  EXPECT_TRUE(const_false->is_expr());
  EXPECT_TRUE(const_true->is_bool());
  EXPECT_FALSE(const_false->is_bv());

  BvVal val_0(0);
  BvVal val_1("1");
  ExprPtr const_0 = std::make_shared<ExprConst>(val_0, 8);
  ExprPtr const_1 = std::make_shared<ExprConst>(val_1, 8);

  EXPECT_TRUE(const_0->is_bv());
  EXPECT_FALSE(const_1->is_bool());
}

TEST(ExprOp, Construct) {
  ExprPtr var_bool = std::make_shared<ExprVar>("var_bool");
  ExprPtr var_bv_0 = std::make_shared<ExprVar>("var_bv_0", 8);
  ExprPtr var_bv_1 = std::make_shared<ExprVar>("var_bv_1", 8);

  ExprPtr op_and = std::make_shared<ExprOpAnd>(var_bv_0, var_bv_1);
  EXPECT_EQ("AND", std::dynamic_pointer_cast<ExprOp>(op_and)->op_name());

  ExprPtr op_or = std::make_shared<ExprOpOr>(var_bv_0, op_and);
  EXPECT_EQ("OR", std::dynamic_pointer_cast<ExprOp>(op_or)->op_name());

  ExprPtr op_eq = std::make_shared<ExprOpEq>(var_bv_1, op_or);
  EXPECT_EQ("EQ", std::dynamic_pointer_cast<ExprOp>(op_eq)->op_name());
  EXPECT_TRUE(op_eq->is_bool());
}

} // namespace ila

