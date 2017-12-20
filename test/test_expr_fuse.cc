/// \file
/// Unit test for the class ExprFuse

#include "ila/expr_fuse.h"
#include "gtest/gtest.h"

namespace ila {

TEST(ExprFuse, CreateVar) {
  auto flag = ExprFuse::NewBoolVar("flag");
  auto reg_x = ExprFuse::NewBvVar("reg_x", 8);
  auto reg_y = ExprFuse::NewBvVar("reg_y", 8);
  auto mem = ExprFuse::NewMemVar("mem", 8, 8);

  EXPECT_TRUE(flag->is_expr());
  EXPECT_TRUE(flag->is_var());
  EXPECT_TRUE(flag->is_bool());
  EXPECT_TRUE(reg_x->is_bv());
  EXPECT_TRUE(reg_y->is_var());
  EXPECT_TRUE(mem->is_mem());
}

TEST(ExprFuse, CreateConst) {
  auto const_false = ExprFuse::BoolConst(false);
  auto const_true = ExprFuse::BoolConst(BoolVal("True"));
  auto const_bv0 = ExprFuse::BvConst(0, 8);
  auto const_bv1 = ExprFuse::BvConst(BvVal("1"), 8);
  auto const_mem = ExprFuse::MemConst(0, 8, 8);
  // TODO Create mem constant from MemVal

  EXPECT_TRUE(const_false->is_const());
  EXPECT_TRUE(const_true->is_bool());
  // EXPECT_TRUE(const_bv0->val()????
}

TEST(ExprFuse, CreateOp) {
  auto flag = ExprFuse::NewBoolVar("flag");
  auto reg_x = ExprFuse::NewBvVar("reg_x", 8);
  auto reg_y = ExprFuse::NewBvVar("reg_y", 8);

  auto const_true = ExprFuse::BoolConst(BoolVal("True"));
  auto const_bv0 = ExprFuse::BvConst(0, 8);

  auto x_and_y = ExprFuse::And(reg_x, reg_y);
  auto x_and_y_or_y = ExprFuse::Or(x_and_y, x_and_y);
  auto y_or_0 = ExprFuse::Or(reg_y, const_bv0);
  auto equal = ExprFuse::Eq(x_and_y_or_y, y_or_0); // should be alwats true
  auto miter = ExprFuse::Eq(equal, flag);          // bool type eq

  EXPECT_TRUE(x_and_y->is_op());
}

} // namespace ila

