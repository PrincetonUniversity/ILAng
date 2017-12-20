/// \file
/// Unit test for the class ExprRef.

#include "ila/ast/expr_ref.h"
#include "gtest/gtest.h"

namespace ila {

TEST(ExprRef, CreateVar) {
  auto flag = ExprRef::NewBoolVar("flag");
  auto reg_x = ExprRef::NewBvVar("reg_x", 8);
  auto reg_y = ExprRef::NewBvVar("reg_y", 8);
  auto mem = ExprRef::NewMemVar("mem", 8, 8);

  EXPECT_TRUE(flag->IsExpr());
  EXPECT_TRUE(flag->IsVar());
  EXPECT_TRUE(flag->IsBool());
  EXPECT_TRUE(reg_x->IsBv());
  EXPECT_TRUE(reg_y->IsVar());
  EXPECT_TRUE(mem->IsMem());
}

TEST(ExprRef, CreateConst) {
  auto const_false = ExprRef::BoolConst(false);
  auto const_true = ExprRef::BoolConst(BoolVal("True"));
  auto const_bv0 = ExprRef::BvConst(0, 8);
  auto const_bv1 = ExprRef::BvConst(BvVal("1"), 8);
  auto const_mem = ExprRef::MemConst(0, 8, 8);
  // TODO Create mem constant from MemVal

  EXPECT_TRUE(const_false->IsConst());
  EXPECT_TRUE(const_true->IsBool());
  // EXPECT_TRUE(const_bv0->val()????
}

TEST(ExprRef, CreateOp) {
  auto flag = ExprRef::NewBoolVar("flag");
  auto reg_x = ExprRef::NewBvVar("reg_x", 8);
  auto reg_y = ExprRef::NewBvVar("reg_y", 8);

  auto const_true = ExprRef::BoolConst(BoolVal("True"));
  auto const_bv0 = ExprRef::BvConst(0, 8);

  auto x_and_y = ExprRef::LogicalAnd(reg_x, reg_y);
  auto x_and_y_or_y = ExprRef::LogicalOr(x_and_y, x_and_y);
  auto y_or_0 = ExprRef::LogicalOr(reg_y, const_bv0);
  auto equal = ExprRef::CompEq(x_and_y_or_y, y_or_0); // should be alwats true
  auto miter = ExprRef::CompEq(equal, flag);          // bool type eq

  EXPECT_TRUE(x_and_y->IsOp());
}

} // namespace ila

