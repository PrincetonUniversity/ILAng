/// \file
/// Unit test for the class ExprFuse

#include "ila/expr_fuse.h"
#include "test_util.h"
#include "gtest/gtest.h"
#include <iostream>

namespace ila {

TEST(ExprFuse, CreateVar) {
  auto flag = ExprFuse::NewBoolVar("flag");
  auto reg_x = ExprFuse::NewBvVar("reg_x", 8);
  auto mem = ExprFuse::NewMemVar("mem", 8, 8);

  EXPECT_TRUE(flag->is_ast());
  EXPECT_FALSE(flag->is_instr());
  EXPECT_FALSE(flag->is_instr_lvl_abs());
  EXPECT_TRUE(flag->is_expr());
  EXPECT_FALSE(flag->is_sort());
  EXPECT_FALSE(flag->is_func());
  EXPECT_TRUE(flag->is_var());
  EXPECT_FALSE(flag->is_const());
  EXPECT_FALSE(flag->is_op());
  EXPECT_TRUE(flag->is_bool());
  EXPECT_FALSE(flag->is_bv());
  EXPECT_FALSE(flag->is_mem());

  EXPECT_TRUE(reg_x->is_ast());
  EXPECT_FALSE(reg_x->is_instr());
  EXPECT_FALSE(reg_x->is_instr_lvl_abs());
  EXPECT_TRUE(reg_x->is_expr());
  EXPECT_FALSE(reg_x->is_sort());
  EXPECT_FALSE(reg_x->is_func());
  EXPECT_TRUE(reg_x->is_var());
  EXPECT_FALSE(reg_x->is_const());
  EXPECT_FALSE(reg_x->is_op());
  EXPECT_TRUE(reg_x->is_bv());
  EXPECT_FALSE(reg_x->is_bool());
  EXPECT_FALSE(reg_x->is_mem());

  EXPECT_TRUE(mem->is_ast());
  EXPECT_FALSE(mem->is_instr());
  EXPECT_FALSE(mem->is_instr_lvl_abs());
  EXPECT_TRUE(mem->is_expr());
  EXPECT_FALSE(mem->is_sort());
  EXPECT_FALSE(mem->is_func());
  EXPECT_TRUE(mem->is_var());
  EXPECT_FALSE(mem->is_const());
  EXPECT_FALSE(mem->is_op());
  EXPECT_TRUE(mem->is_mem());
  EXPECT_FALSE(mem->is_bool());
  EXPECT_FALSE(mem->is_bv());
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
  EXPECT_TRUE(const_bv0->is_bv());

  std::string msg = "";
  GET_STDOUT_MSG(const_false->Print(std::cout), msg);
  EXPECT_EQ("FALSE", msg);

  GET_STDOUT_MSG(const_true->Print(std::cout), msg);
  EXPECT_EQ("TRUE", msg);

  GET_STDOUT_MSG(const_bv0->Print(std::cout), msg);
  EXPECT_EQ("0", msg);

  GET_STDOUT_MSG(const_bv1->Print(std::cout), msg);
  EXPECT_EQ("1", msg);
}

TEST(ExprFuse, UnaryOp) {
  auto bv_var = ExprFuse::NewBvVar("reg", 8);
  auto const_1 = ExprFuse::BvConst(1, 8);

#if 0
  auto negated = ExprFuse::Negate(bv_var);
  auto compl1 = ExprFuse::Complement(bv_var);
  auto compl2 = ExprFuse::Complement(compl1);
  auto non_zero = ExprFuse::NonZero(const_1);
#endif
}

TEST(ExprFuse, BinaryOp) {
  auto flag = ExprFuse::NewBoolVar("flag");
  auto reg_x = ExprFuse::NewBvVar("reg_x", 8);
  auto reg_y = ExprFuse::NewBvVar("reg_y", 8);

  auto const_true = ExprFuse::BoolConst(BoolVal("True"));
  auto const_bv0 = ExprFuse::BvConst(0, 8);

  auto x_and_y = ExprFuse::And(reg_x, reg_y);
  auto x_and_y_or_y = ExprFuse::Or(x_and_y, x_and_y);
  auto y_or_0 = ExprFuse::Or(reg_y, const_bv0);
  auto bv_equal = ExprFuse::Eq(x_and_y_or_y, y_or_0); // should be alwats true
  auto bool_equal = ExprFuse::Eq(bv_equal, flag);
  auto bool_and = ExprFuse::And(flag, bool_equal);
  auto bool_or = ExprFuse::Or(bool_equal, bool_and);

  EXPECT_TRUE(x_and_y->is_op());
}

} // namespace ila

