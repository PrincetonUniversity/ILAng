/// \file
/// Unit test for the class ExprFuse

#include "ila/expr_fuse.h"
#include "unit-include/util.h"
#include <iostream>

namespace ila {

TEST(TestExprFuse, CreateVar) {
  auto flag = ExprFuse::NewBoolVar("flag");
  auto reg_x = ExprFuse::NewBvVar("reg_x", 8);
  auto mem = ExprFuse::NewMemVar("mem", 8, 8);

  EXPECT_TRUE(flag->is_ast());
  EXPECT_FALSE(flag->is_instr());
  EXPECT_FALSE(flag->is_instr_lvl_abs());
  EXPECT_TRUE(flag->is_expr());
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
  EXPECT_FALSE(reg_x->is_func());
  EXPECT_TRUE(reg_x->is_var());
  EXPECT_FALSE(reg_x->is_const());
  EXPECT_FALSE(reg_x->is_op());
  EXPECT_TRUE(reg_x->is_bv());
  EXPECT_FALSE(reg_x->is_bool());
  EXPECT_FALSE(reg_x->is_mem());
  EXPECT_EQ(8, reg_x->sort()->bit_width());

  EXPECT_TRUE(mem->is_ast());
  EXPECT_FALSE(mem->is_instr());
  EXPECT_FALSE(mem->is_instr_lvl_abs());
  EXPECT_TRUE(mem->is_expr());
  EXPECT_FALSE(mem->is_func());
  EXPECT_TRUE(mem->is_var());
  EXPECT_FALSE(mem->is_const());
  EXPECT_FALSE(mem->is_op());
  EXPECT_TRUE(mem->is_mem());
  EXPECT_FALSE(mem->is_bool());
  EXPECT_FALSE(mem->is_bv());
  EXPECT_EQ(8, mem->sort()->addr_width());
  EXPECT_EQ(8, mem->sort()->data_width());
}

TEST(TestExprFuse, CreateConst) {
  auto const_false = ExprFuse::BoolConst(false);
  auto const_true = ExprFuse::BoolConst(BoolVal("True"));

  EXPECT_TRUE(const_true->is_ast());
  EXPECT_FALSE(const_true->is_instr());
  EXPECT_FALSE(const_true->is_instr_lvl_abs());
  EXPECT_TRUE(const_true->is_expr());
  EXPECT_FALSE(const_true->is_func());
  EXPECT_TRUE(const_true->is_const());
  EXPECT_FALSE(const_true->is_var());
  EXPECT_FALSE(const_true->is_op());
  EXPECT_TRUE(const_true->is_bool());
  EXPECT_FALSE(const_true->is_bv());
  EXPECT_FALSE(const_true->is_mem());

  auto const_bv0 = ExprFuse::BvConst(0, 8);
  auto const_bv1 = ExprFuse::BvConst(BvVal("1"), 8);

  EXPECT_TRUE(const_bv0->is_ast());
  EXPECT_FALSE(const_bv0->is_instr());
  EXPECT_FALSE(const_bv0->is_instr_lvl_abs());
  EXPECT_TRUE(const_bv0->is_expr());
  EXPECT_FALSE(const_bv0->is_func());
  EXPECT_TRUE(const_bv0->is_const());
  EXPECT_FALSE(const_bv0->is_var());
  EXPECT_FALSE(const_bv0->is_op());
  EXPECT_TRUE(const_bv0->is_bv());
  EXPECT_FALSE(const_bv0->is_bool());
  EXPECT_FALSE(const_bv0->is_mem());

  auto const_mem = ExprFuse::MemConst(0, 8, 8);
  auto const_mem_1 = ExprFuse::MemConst(MemVal(1), 8, 8);

  EXPECT_FALSE(const_mem->is_instr());
  EXPECT_FALSE(const_mem->is_instr_lvl_abs());
  EXPECT_TRUE(const_mem->is_expr());
  EXPECT_FALSE(const_mem->is_func());
  EXPECT_TRUE(const_mem->is_const());
  EXPECT_FALSE(const_mem->is_var());
  EXPECT_FALSE(const_mem->is_op());
  EXPECT_TRUE(const_mem->is_mem());
  EXPECT_FALSE(const_mem->is_bool());
  EXPECT_FALSE(const_mem->is_bv());
}

TEST(TestExprFuse, UnaryOp) {
  auto bool_var = ExprFuse::NewBoolVar("bool_var");
  auto bv_var = ExprFuse::NewBvVar("bv_var", 8);
  auto bool_const_true = ExprFuse::BoolConst(true);
  auto bool_const_false = ExprFuse::BoolConst(false);
  auto bv_const_0 = ExprFuse::BvConst(0, 8);
  auto bv_const_1 = ExprFuse::BvConst(1, 8);

  // Negate
  auto bv_neg = ExprFuse::Negate(bv_var);
  EXPECT_TRUE(bv_neg->is_op());
  EXPECT_FALSE(bv_neg->is_var());
  EXPECT_FALSE(bv_neg->is_const());
  EXPECT_TRUE(bv_neg->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Negate(bool_var), ".*");
#endif

  // Not
  auto bool_not = ExprFuse::Not(bool_var);
  EXPECT_TRUE(bool_not->is_op());
  EXPECT_FALSE(bool_not->is_var());
  EXPECT_FALSE(bool_not->is_const());
  EXPECT_TRUE(bool_not->is_bool());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Not(bv_var), ".*");
#endif

  // Complement
  auto bv_compl = ExprFuse::Complement(bv_const_0);
  EXPECT_TRUE(bv_compl->is_op());
  EXPECT_FALSE(bv_compl->is_var());
  EXPECT_FALSE(bv_compl->is_const());
  EXPECT_TRUE(bv_compl->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Complement(bool_var), ".*");
#endif
}

TEST(TestExprFuse, BinaryOp) {
  auto bool_var = ExprFuse::NewBoolVar("bool_var");
  auto bool_const_t = ExprFuse::BoolConst(true);
  auto bool_const_f = ExprFuse::BoolConst(false);

  auto bv_var = ExprFuse::NewBvVar("bv_var", 8);
  auto bv_const_0 = ExprFuse::BvConst(0, 8);
  auto bv_const_1 = ExprFuse::BvConst(BvVal("1"), 8);

  // And
  auto bool_and = ExprFuse::And(bool_var, bool_const_t);
  EXPECT_TRUE(bool_and->is_op());
  EXPECT_TRUE(bool_and->is_bool());

  auto bv_and = ExprFuse::And(bv_var, bv_const_0);
  EXPECT_TRUE(bv_and->is_op());
  EXPECT_TRUE(bv_and->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::And(bool_var, bv_var), ".*");
#endif

  // Or
  auto bool_or = ExprFuse::Or(bool_var, bool_const_f);
  EXPECT_TRUE(bool_or->is_op());
  EXPECT_TRUE(bool_or->is_bool());

  auto bv_or = ExprFuse::Or(bv_var, bv_const_0);
  EXPECT_TRUE(bv_or->is_op());
  EXPECT_TRUE(bv_or->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Or(bool_var, bv_var), ".*");
#endif

  // Xor
  auto bool_xor = ExprFuse::Xor(bool_var, bool_const_t);
  EXPECT_TRUE(bool_xor->is_op());
  EXPECT_TRUE(bool_xor->is_bool());

  auto bv_xor = ExprFuse::Xor(bv_var, bv_const_1);
  EXPECT_TRUE(bv_xor->is_op());
  EXPECT_TRUE(bv_xor->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Xor(bool_var, bv_var), ".*");
#endif
}

TEST(TestExprFuse, BinaryCompare) {
  auto bool_var = ExprFuse::NewBoolVar("bool_var");
  auto bool_const_t = ExprFuse::BoolConst(true);
  auto bool_const_f = ExprFuse::BoolConst(false);

  auto bv_var = ExprFuse::NewBvVar("bv_var", 8);
  auto bv_const_0 = ExprFuse::BvConst(0, 8);
  auto bv_const_1 = ExprFuse::BvConst(BvVal("1"), 8);

  // Eq
  auto bool_eq = ExprFuse::Eq(bool_var, bool_const_t);
  EXPECT_TRUE(bool_eq->is_op());
  EXPECT_TRUE(bool_eq->is_bool());

  auto bv_eq = ExprFuse::Eq(bv_var, bv_const_1);
  EXPECT_TRUE(bv_eq->is_op());
  EXPECT_TRUE(bv_eq->is_bool());
  EXPECT_FALSE(bv_eq->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Eq(bv_var, bool_var), ".*");
#endif
}

TEST(TestExprFuse, Memory) {
  auto mem_var = ExprFuse::NewMemVar("mem_var", 8, 32);
  auto bv_var_8 = ExprFuse::NewBvVar("bv_var_8", 8);
  auto bv_var_32 = ExprFuse::NewBvVar("bv_var_32", 32);

  // Load
  auto load = ExprFuse::Load(mem_var, bv_var_8);
  EXPECT_TRUE(load->is_op());
  EXPECT_TRUE(load->is_bv());
  EXPECT_EQ(32, load->sort()->bit_width());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Load(mem_var, bv_var_32), ".*");
#endif

  // Store
  auto store = ExprFuse::Store(mem_var, bv_var_8, bv_var_32);
  EXPECT_TRUE(store->is_op());
  EXPECT_TRUE(store->is_mem());
  EXPECT_EQ(store->sort(), mem_var->sort());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Store(mem_var, bv_var_32, bv_var_32), ".*");
  EXPECT_DEATH(ExprFuse::Store(mem_var, bv_var_8, bv_var_8), ".*");
#endif
}

TEST(TestExprFuse, BitManipulation) {
  // TODO
}

TEST(TestExprFuse, FunctionUsage) {
  // TODO
}

TEST(TestExprFuse, Others) {
  auto varx = ExprFuse::NewBvVar("varx", 8);
  auto vary = ExprFuse::NewBvVar("vary", 8);
  auto cond = ExprFuse::Eq(varx, vary);

  auto ite = ExprFuse::Ite(cond, varx, vary);
  EXPECT_TRUE(ite->is_op());
  EXPECT_TRUE(ite->is_bv());
  EXPECT_EQ(ite->sort(), varx->sort());

  auto flagx = ExprFuse::NewBoolVar("flagx");
  auto flagy = ExprFuse::NewBoolVar("flagx");
  cond = ExprFuse::Eq(flagx, flagy);

  ite = ExprFuse::Ite(cond, flagx, flagy);
  EXPECT_TRUE(ite->is_op());
  EXPECT_TRUE(ite->is_bool());
  EXPECT_EQ(ite->sort(), flagx->sort());

#ifndef NDEBUG
  EXPECT_DEATH(ExprFuse::Ite(varx, varx, vary), ".*");
  EXPECT_DEATH(ExprFuse::Ite(flagx, flagx, vary), ".*");
#endif

  // TODO imply
}

using namespace ExprFuse;
TEST(TestExprFuse, TopEq) {
  auto x = NewBoolVar("x");
  auto y = NewBoolVar("y");
  auto z = NewBoolVar("z");

  auto a = And(x, y);
  auto b = Or(a, z);
  auto c = Xor(a, b);

  auto d = And(x, y);
  auto e = Or(d, z);
  auto f = Xor(d, e);

  auto g = Xor(e, d);

  EXPECT_TRUE(TopEq(c, f));
  EXPECT_FALSE(TopEq(c, g));
}

} // namespace ila

