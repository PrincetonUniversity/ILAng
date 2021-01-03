/// \file
/// Unit test for asthub

#include <ilang/ila/ast_hub.h>

#include "unit-include/util.h"

namespace ilang {

TEST(Testasthub, CreateVar) {
  auto flag = asthub::NewBoolVar("flag");
  auto reg_x = asthub::NewBvVar("reg_x", 8);
  auto mem = asthub::NewMemVar("mem", 8, 8);

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

TEST(Testasthub, CreateConst) {
  auto const_false = asthub::BoolConst(false);
  auto const_true = asthub::BoolConst(BoolVal("True"));

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

  auto const_bv0 = asthub::BvConst(0, 8);
  auto const_bv1 = asthub::BvConst(BvVal("1"), 8);

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

  auto const_mem = asthub::MemConst(0, 8, 8);
  auto const_mem_1 = asthub::MemConst(MemVal(1), 8, 8);

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

TEST(Testasthub, UnaryOp) {
  auto bool_var = asthub::NewBoolVar("bool_var");
  auto bv_var = asthub::NewBvVar("bv_var", 8);
  auto bool_const_true = asthub::BoolConst(true);
  auto bool_const_false = asthub::BoolConst(false);
  auto bv_const_0 = asthub::BvConst(0, 8);
  auto bv_const_1 = asthub::BvConst(1, 8);

  // Negate
  auto bv_neg = asthub::Negate(bv_var);
  EXPECT_TRUE(bv_neg->is_op());
  EXPECT_FALSE(bv_neg->is_var());
  EXPECT_FALSE(bv_neg->is_const());
  EXPECT_TRUE(bv_neg->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Negate(bool_var), ".*");
#endif

  // Not
  auto bool_not = asthub::Not(bool_var);
  EXPECT_TRUE(bool_not->is_op());
  EXPECT_FALSE(bool_not->is_var());
  EXPECT_FALSE(bool_not->is_const());
  EXPECT_TRUE(bool_not->is_bool());

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Not(bv_var), ".*");
#endif

  // Complement
  auto bv_compl = asthub::Complement(bv_const_0);
  EXPECT_TRUE(bv_compl->is_op());
  EXPECT_FALSE(bv_compl->is_var());
  EXPECT_FALSE(bv_compl->is_const());
  EXPECT_TRUE(bv_compl->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Complement(bool_var), ".*");
#endif
}

TEST(Testasthub, BinaryOp) {
  auto bool_var = asthub::NewBoolVar("bool_var");
  auto bool_const_t = asthub::BoolConst(true);
  auto bool_const_f = asthub::BoolConst(false);

  auto bv_var = asthub::NewBvVar("bv_var", 8);
  auto bv_const_0 = asthub::BvConst(0, 8);
  auto bv_const_1 = asthub::BvConst(BvVal("1"), 8);
  auto bv1_const_0 = asthub::BvConst(0, 1);
  auto bv1_const_1 = asthub::BvConst(1, 1);

  // And
  auto bool_and = asthub::And(bool_var, bool_const_t);
  EXPECT_TRUE(bool_and->is_op());
  EXPECT_TRUE(bool_and->is_bool());

  auto bv_and = asthub::And(bv_var, bv_const_0);
  EXPECT_TRUE(bv_and->is_op());
  EXPECT_TRUE(bv_and->is_bv());

  auto bv_and_bool = asthub::And(bv1_const_0, bool_var);
  EXPECT_TRUE(bv_and_bool->is_bool());
  EXPECT_FALSE(bv_and_bool->is_bv(1));

  auto bool_and_bv = asthub::And(bool_var, bv1_const_1);
  EXPECT_TRUE(bool_and_bv->is_bool());
  EXPECT_FALSE(bool_and_bv->is_bv(1));

#ifndef NDEBUG
  EXPECT_DEATH(asthub::And(bool_var, bv_var), ".*");
#endif

  // Or
  auto bool_or = asthub::Or(bool_var, bool_const_f);
  EXPECT_TRUE(bool_or->is_op());
  EXPECT_TRUE(bool_or->is_bool());

  auto bv_or = asthub::Or(bv_var, bv_const_0);
  EXPECT_TRUE(bv_or->is_op());
  EXPECT_TRUE(bv_or->is_bv());

  auto bool_or_bv = asthub::Or(bool_var, bv1_const_0);
  EXPECT_TRUE(bool_or_bv->is_bool());
  EXPECT_FALSE(bool_or_bv->is_bv(1));

  auto bv_or_bool = asthub::Or(bv1_const_1, bool_var);
  EXPECT_TRUE(bv_or_bool->is_bool());
  EXPECT_FALSE(bv_or_bool->is_bv(1));

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Or(bool_var, bv_var), ".*");
#endif

  // Xor
  auto bool_xor = asthub::Xor(bool_var, bool_const_t);
  EXPECT_TRUE(bool_xor->is_op());
  EXPECT_TRUE(bool_xor->is_bool());

  auto bv_xor = asthub::Xor(bv_var, bv_const_1);
  EXPECT_TRUE(bv_xor->is_op());
  EXPECT_TRUE(bv_xor->is_bv());

  auto bool_xor_bv = asthub::Xor(bool_var, bv1_const_0);
  EXPECT_TRUE(bool_xor_bv->is_bool());
  EXPECT_FALSE(bool_xor_bv->is_bv(1));

  auto bv_xor_bool = asthub::Xor(bv1_const_1, bool_var);
  EXPECT_TRUE(bv_xor_bool->is_bool());
  EXPECT_FALSE(bv_xor_bool->is_bv(1));

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Xor(bool_var, bv_var), ".*");
#endif
}

TEST(Testasthub, BinaryCompare) {
  auto bool_var = asthub::NewBoolVar("bool_var");
  auto bool_const_t = asthub::BoolConst(true);
  auto bool_const_f = asthub::BoolConst(false);

  auto bv_var = asthub::NewBvVar("bv_var", 8);
  auto bv_const_0 = asthub::BvConst(0, 8);
  auto bv_const_1 = asthub::BvConst(BvVal("1"), 8);

  // Eq
  auto bool_eq = asthub::Eq(bool_var, bool_const_t);
  EXPECT_TRUE(bool_eq->is_op());
  EXPECT_TRUE(bool_eq->is_bool());

  auto bv_eq = asthub::Eq(bv_var, bv_const_1);
  EXPECT_TRUE(bv_eq->is_op());
  EXPECT_TRUE(bv_eq->is_bool());
  EXPECT_FALSE(bv_eq->is_bv());

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Eq(bv_var, bool_var), ".*");
#endif
}

TEST(Testasthub, Memory) {
  auto mem_var = asthub::NewMemVar("mem_var", 8, 32);
  auto bv_var_8 = asthub::NewBvVar("bv_var_8", 8);
  auto bv_var_32 = asthub::NewBvVar("bv_var_32", 32);

  // Load
  auto load = asthub::Load(mem_var, bv_var_8);
  EXPECT_TRUE(load->is_op());
  EXPECT_TRUE(load->is_bv());
  EXPECT_EQ(32, load->sort()->bit_width());

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Load(mem_var, bv_var_32), ".*");
#endif

  // Store
  auto store = asthub::Store(mem_var, bv_var_8, bv_var_32);
  EXPECT_TRUE(store->is_op());
  EXPECT_TRUE(store->is_mem());
  EXPECT_EQ(store->sort(), mem_var->sort());

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Store(mem_var, bv_var_32, bv_var_32), ".*");
  EXPECT_DEATH(asthub::Store(mem_var, bv_var_8, bv_var_8), ".*");
#endif
}

TEST(Testasthub, BitManipulation) {
  // TODO
}

TEST(Testasthub, FunctionUsage) {
  // TODO
}

TEST(Testasthub, Others) {
  auto varx = asthub::NewBvVar("varx", 8);
  auto vary = asthub::NewBvVar("vary", 8);
  auto cond = asthub::Eq(varx, vary);

  auto ite = asthub::Ite(cond, varx, vary);
  EXPECT_TRUE(ite->is_op());
  EXPECT_TRUE(ite->is_bv());
  EXPECT_EQ(ite->sort(), varx->sort());

  auto flagx = asthub::NewBoolVar("flagx");
  auto flagy = asthub::NewBoolVar("flagx");
  cond = asthub::Eq(flagx, flagy);

  ite = asthub::Ite(cond, flagx, flagy);
  EXPECT_TRUE(ite->is_op());
  EXPECT_TRUE(ite->is_bool());
  EXPECT_EQ(ite->sort(), flagx->sort());

#ifndef NDEBUG
  EXPECT_DEATH(asthub::Ite(varx, varx, vary), ".*");
  EXPECT_DEATH(asthub::Ite(flagx, flagx, vary), ".*");
#endif

  // TODO imply
}

using namespace asthub;
TEST(Testasthub, TopEq) {
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

TEST(Testasthub, MemSize) {
  auto mem = NewMemVar("mem", 8, 8);

  EXPECT_EQ(0, GetMemSize(mem));

#ifndef NDEBUG
  EXPECT_DEATH(SetMemSize(mem, -1), ".*");
#endif
  EXPECT_TRUE(SetMemSize(mem, 8));
  EXPECT_FALSE(SetMemSize(mem, 16));

  EXPECT_EQ(8, GetMemSize(mem));

  auto bl = NewBoolVar("bl");
#ifndef NDEBUG
  EXPECT_DEATH(SetMemSize(bl, 2), ".*");
  EXPECT_DEATH(GetMemSize(bl), ".*");
#endif
}

} // namespace ilang
