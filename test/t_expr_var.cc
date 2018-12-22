/// \file
/// Unit test for ExprVar

#include "unit-include/util.h"
#include "z3++.h"
#include <ilang/ila/ast/expr_var.h>

namespace ilang {

TEST(TestExprVar, Construct) {
  auto bool_var = std::make_shared<ExprVar>("bool_var");
  auto bv_var = std::make_shared<ExprVar>("bv_var", 8);
  auto mem_var = std::make_shared<ExprVar>("mem_var", 8, 32);

  EXPECT_TRUE(bool_var->is_var());
  EXPECT_TRUE(bool_var->is_bool());
  EXPECT_FALSE(bool_var->is_const());
  EXPECT_FALSE(bool_var->is_op());

  EXPECT_TRUE(bv_var->is_bv());
  EXPECT_TRUE(bv_var->is_var());
  EXPECT_FALSE(bv_var->is_const());
  EXPECT_FALSE(bv_var->is_op());

  EXPECT_TRUE(mem_var->is_mem());
  EXPECT_TRUE(mem_var->is_var());
  EXPECT_FALSE(mem_var->is_const());
  EXPECT_FALSE(mem_var->is_op());
}

TEST(TestExprVar, BoolZ3Expr) {
  z3::context ctx;
  Z3ExprVec arg_vec;
  z3::solver s(ctx);

  auto bool_var_0 = std::make_shared<ExprVar>("bool_var");
  auto bool_var_1 = std::make_shared<ExprVar>("bool_var");
  auto e_0 = bool_var_0->GetZ3Expr(ctx, arg_vec, "");
  auto e_1 = bool_var_1->GetZ3Expr(ctx, arg_vec, "");
  auto bool_eq = (e_0 == e_1);
  s.add(!bool_eq);
  EXPECT_EQ(z3::unsat, s.check());

  auto e_2 = bool_var_0->GetZ3Expr(ctx, arg_vec, "n");
  auto bool_ne = (e_0 == e_1);
  s.add(bool_ne);
  EXPECT_EQ(z3::unsat, s.check());
}

TEST(TestExprVar, BvZ3Expr) {
  z3::context ctx;
  Z3ExprVec arg_vec;
  z3::solver s(ctx);

  auto bv_var_0 = std::make_shared<ExprVar>("bv_var_0", 8);
  auto bv_var_1 = std::make_shared<ExprVar>("bv_var_1", 8);
  auto e_0 = bv_var_0->GetZ3Expr(ctx, arg_vec, "x");
  auto e_1 = bv_var_1->GetZ3Expr(ctx, arg_vec, "x");
  auto bv_ne = (e_0 == e_1);
  s.add(bv_ne);
  EXPECT_EQ(z3::sat, s.check());

  s.reset();

  auto e_2 = bv_var_0->GetZ3Expr(ctx, arg_vec, "x");
  auto e_link1 = (e_0 == e_1);
  auto e_link2 = (e_1 == e_2);
  auto e_prop = (e_link1 && !e_link2);
  s.add(e_prop);
  EXPECT_EQ(z3::unsat, s.check());
}

TEST(TestExprVar, MemZ3Expr) {
  z3::context ctx;
  Z3ExprVec arg_vec;
  z3::solver s(ctx);

  auto mem_var = std::make_shared<ExprVar>("mem_var", 8, 32);
  auto e_0 = mem_var->GetZ3Expr(ctx, arg_vec, "0");
  auto e_1 = mem_var->GetZ3Expr(ctx, arg_vec, "1");
  auto e_2 = mem_var->GetZ3Expr(ctx, arg_vec, "2");

  s.add(e_0 == e_1);
  s.add(e_1 == e_2);
  s.add(e_0 != e_2);
  EXPECT_EQ(z3::unsat, s.check());
}

TEST(TestExprVar, BoolPrint) {
  auto bool_var = std::make_shared<ExprVar>("bool_var");
  std::string ref_str = "bool_var";

  std::string msg;
  GET_STDOUT_MSG(bool_var->Print(std::cout), msg);
  EXPECT_EQ(ref_str, msg);
}

TEST(TestExprVar, BvPrint) {
  auto bv_var = std::make_shared<ExprVar>("bv_var", 8);
  std::string ref_str = "bv_var(8)";

  std::string msg;
  GET_STDOUT_MSG(bv_var->Print(std::cout), msg);
  EXPECT_EQ(ref_str, msg);
}

TEST(TestExprVar, MemPrint) {
  auto mem_var = std::make_shared<ExprVar>("mem_var", 8, 32);
  std::string ref_str = "mem_var(8, 32)";

  std::string msg;
  GET_STDOUT_MSG(mem_var->Print(std::cout), msg);
  EXPECT_EQ(ref_str, msg);
}

} // namespace ilang
