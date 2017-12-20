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

  EXPECT_TRUE(flag->IsExpr());
  EXPECT_TRUE(flag->IsVar());
  EXPECT_TRUE(flag->IsBool());
  EXPECT_TRUE(reg_x->IsBv());
  EXPECT_TRUE(reg_y->IsVar());
  EXPECT_TRUE(mem->IsMem());
}

TEST(ExprFuse, CreateConst) {
  auto const_false = ExprFuse::BoolConst(false);
  auto const_true = ExprFuse::BoolConst(BoolVal("True"));
  auto const_bv0 = ExprFuse::BvConst(0, 8);
  auto const_bv1 = ExprFuse::BvConst(BvVal("1"), 8);
  auto const_mem = ExprFuse::MemConst(0, 8, 8);
  // TODO Create mem constant from MemVal

  EXPECT_TRUE(const_false->IsConst());
  EXPECT_TRUE(const_true->IsBool());
  // EXPECT_TRUE(const_bv0->val()????
}

TEST(ExprFuse, CreateOp) {
  auto flag = ExprFuse::NewBoolVar("flag");
  auto reg_x = ExprFuse::NewBvVar("reg_x", 8);
  auto reg_y = ExprFuse::NewBvVar("reg_y", 8);

  auto const_true = ExprFuse::BoolConst(BoolVal("True"));
  auto const_bv0 = ExprFuse::BvConst(0, 8);

  auto x_and_y = ExprFuse::LogicalAnd(reg_x, reg_y);
  auto x_and_y_or_y = ExprFuse::LogicalOr(x_and_y, x_and_y);
  auto y_or_0 = ExprFuse::LogicalOr(reg_y, const_bv0);
  auto equal = ExprFuse::CompEq(x_and_y_or_y, y_or_0); // should be alwats true
  auto miter = ExprFuse::CompEq(equal, flag);          // bool type eq

  EXPECT_TRUE(x_and_y->IsOp());
}

} // namespace ila

