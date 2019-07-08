/// \file
/// Unit test for generating z3 express for ast.

#include "unit-include/util.h"
#include <ilang/ila/expr_fuse.h>
#include <ilang/ila/z3_expr_adapter.h>
#include <ilang/util/log.h>

namespace ilang {

class TestZ3Expr : public ::testing::Test {
public:
  TestZ3Expr() {
    s = new z3::solver(ctx);
    gen = new Z3ExprAdapter(ctx);

    bv_var_x = ExprFuse::NewBvVar("bv_var_x", 8);
    bv_var_y = ExprFuse::NewBvVar("bv_var_y", 8);
    bv_const_0 = ExprFuse::BvConst(0, 8);
    bv_const_1 = ExprFuse::BvConst(1, 8);
    bool_var_x = ExprFuse::NewBoolVar("bool_var_x");
    bool_var_y = ExprFuse::NewBoolVar("bool_var_y");
    bool_true = ExprFuse::BoolConst(true);
    bool_false = ExprFuse::BoolConst(false);
    mem_var_x = ExprFuse::NewMemVar("mem_var_x", 8, 8);
    mem_var_y = ExprFuse::NewMemVar("mem_var_y", 8, 8);
    mem_const = ExprFuse::MemConst(0, 8, 8);
  }

  ~TestZ3Expr() {
    delete s;
    delete gen;
  }

  void SetUp() {}

  void TearDown() {}

  z3::context ctx;
  z3::solver* s;
  Z3ExprAdapter* gen;

  ExprPtr bv_var_x;
  ExprPtr bv_var_y;
  ExprPtr bv_const_0;
  ExprPtr bv_const_1;
  ExprPtr bool_var_x;
  ExprPtr bool_var_y;
  ExprPtr bool_true;
  ExprPtr bool_false;
  ExprPtr mem_var_x;
  ExprPtr mem_var_y;
  ExprPtr mem_const;

}; // class TestZ3Expr

TEST_F(TestZ3Expr, XorBool) {
  auto ast_xor = ExprFuse::Xor(bool_var_x, bool_var_y);
  auto ast_xnoty = ExprFuse::And(bool_var_x, ExprFuse::Not(bool_var_y));
  auto ast_notxy = ExprFuse::And(ExprFuse::Not(bool_var_x), bool_var_y);
  auto ast_raw = ExprFuse::Or(ast_xnoty, ast_notxy);
  auto ast_eq = ExprFuse::Eq(ast_xor, ast_raw);

  auto expr_eq = gen->GetExpr(ast_eq);
  s->add(!expr_eq);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, XorBv) {
  auto ast_xor = ExprFuse::Xor(bv_var_x, bv_var_y);
  auto ast_xnoty = ExprFuse::And(bv_var_x, ExprFuse::Complement(bv_var_y));
  auto ast_notxy = ExprFuse::And(ExprFuse::Complement(bv_var_x), bv_var_y);
  auto ast_raw = ExprFuse::Or(ast_xnoty, ast_notxy);
  auto ast_eq = ExprFuse::Eq(ast_xor, ast_raw);

  auto expr_eq = gen->GetExpr(ast_eq);
  s->add(!expr_eq);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, NotNot) {
  auto ast_not = ExprFuse::Not(bool_var_x);
  auto ast_notnot = ExprFuse::Not(ast_not);
  auto ast_eq = ExprFuse::Eq(bool_var_x, ast_notnot);

  auto expr_eq = gen->GetExpr(ast_eq);
  s->add(!expr_eq);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, NegNeg) {
  auto ast_neg = ExprFuse::Negate(bv_var_x);
  auto ast_negneg = ExprFuse::Negate(ast_neg);
  auto ast_eq = ExprFuse::Eq(bv_var_x, ast_negneg);

  auto expr_eq = gen->GetExpr(ast_eq);
  s->add(!expr_eq);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, Div) {
  auto ast_div = ExprFuse::Div(bv_var_x, bv_var_y);
  auto ast_div_ge_1 = ExprFuse::Ge(ast_div, 1);
  auto ast_x_gt_y = ExprFuse::Gt(bv_var_x, bv_var_y);
  auto ast_y_gt_0 = ExprFuse::Gt(bv_var_y, 0);
  auto ast_cond = ExprFuse::And(ast_x_gt_y, ast_y_gt_0);
  auto ast_target = ExprFuse::Ite(ast_cond, ast_div_ge_1, bool_true);

  auto expr_target = gen->GetExpr(ast_target);
  s->add(!expr_target);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, SRem) {
  auto ast_urem = ExprFuse::URem(bv_var_x, bv_var_y);
  auto ast_urem_eq_1 = ExprFuse::Eq(ast_urem, 1);
  auto ast_y_plus_1 = ExprFuse::Add(bv_var_y, bv_const_1);
  auto ast_x_eq_y_plus_1 = ExprFuse::Eq(bv_var_x, ast_y_plus_1);
  auto ast_y_gt_1 = ExprFuse::Gt(bv_var_y, 1);
  auto ast_x_gt_0 = ExprFuse::Gt(bv_var_x, 0);
  auto ast_cond = ExprFuse::And(ExprFuse::And(ast_y_gt_1, ast_x_eq_y_plus_1), ast_x_gt_0);
  auto ast_target = ExprFuse::Ite(ast_cond, ast_urem_eq_1, bool_true);
  auto expr_target = gen->GetExpr(ast_target);
  s->add(!expr_target);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, URem) {
  auto ast_urem = ExprFuse::URem(bv_var_x, bv_var_y);
  auto ast_urem_eq_1 = ExprFuse::Eq(ast_urem, 1);
  auto ast_y_plus_1 = ExprFuse::Add(bv_var_y, bv_const_1);
  auto ast_x_eq_y_plus_1 = ExprFuse::Eq(bv_var_x, ast_y_plus_1);
  auto ast_y_gt_1 = ExprFuse::Gt(bv_var_y, 1);
  auto ast_cond = ExprFuse::And(ast_y_gt_1, ast_x_eq_y_plus_1);
  auto ast_target = ExprFuse::Ite(ast_cond, ast_urem_eq_1, bool_true);
  auto expr_target = gen->GetExpr(ast_target);
  s->add(!expr_target);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, SMod) {
  auto ast_smod = ExprFuse::SMod(bv_var_x, bv_var_y);
  auto ast_smod_gt_0 = ExprFuse::Gt(ast_smod, 0);
  auto ast_y_gt_1 = ExprFuse::Gt(bv_var_y, 1);
  auto ast_y_plus_1 = ExprFuse::Add(bv_var_y, bv_const_1);
  auto ast_x_eq_y_plus_1 = ExprFuse::Eq(bv_var_x, ast_y_plus_1);
  auto ast_cond = ExprFuse::And(ast_y_gt_1, ast_x_eq_y_plus_1);
  auto ast_target = ExprFuse::Ite(ast_cond, ast_smod_gt_0, bool_true);
  auto expr_target = gen->GetExpr(ast_target);
  s->add(!expr_target);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, LRotate) {
  auto ast_b0 = ExprFuse::Extract(bv_var_x, 0, 0);
  auto ast_b1 = ExprFuse::Extract(bv_var_x, 1, 1);
  auto ast_cond = ExprFuse::Not(ExprFuse::Eq(ast_b0, ast_b1));

  auto ast_lrotate = ExprFuse::LRotate(bv_var_x, 1);
  auto ast_neq = ExprFuse::Not(ExprFuse::Eq(bv_var_x, ast_lrotate));
  auto ast_target = ExprFuse::Ite(ast_cond, ast_neq, bool_true);
  auto expr_target = gen->GetExpr(ast_target);
  s->add(!expr_target);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, RRotate) {
  auto ast_b0 = ExprFuse::Extract(bv_var_x, 0, 0);
  auto ast_b1 = ExprFuse::Extract(bv_var_x, 1, 1);
  auto ast_cond = ExprFuse::Not(ExprFuse::Eq(ast_b0, ast_b1));

  auto ast_rrotate = ExprFuse::RRotate(bv_var_x, 1);
  auto ast_neq = ExprFuse::Not(ExprFuse::Eq(bv_var_x, ast_rrotate));
  auto ast_target = ExprFuse::Ite(ast_cond, ast_neq, bool_true);
  auto expr_target = gen->GetExpr(ast_target);
  s->add(!expr_target);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, LoadStore) {
  auto ast_load = ExprFuse::Load(mem_var_x, bv_var_x);
  auto ast_store = ExprFuse::Store(mem_var_x, bv_var_x, ast_load);
  auto ast_eq = ExprFuse::Eq(mem_var_x, ast_store);

  auto expr_eq = gen->GetExpr(ast_eq);
  s->add(!expr_eq);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, StoreLoad) {
  auto ast_store = ExprFuse::Store(mem_var_x, bv_var_x, bv_var_y);
  auto ast_load = ExprFuse::Load(ast_store, bv_var_x);
  auto ast_eq = ExprFuse::Eq(bv_var_y, ast_load);

  auto expr_eq = gen->GetExpr(ast_eq);
  s->add(!expr_eq);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, Extract) {
  auto ast_hi_0 = ExprFuse::Extract(bv_const_0, 7, 6);
  auto ast_hi_1 = ExprFuse::Extract(bv_const_1, 7, 6);
  auto ast_eq = ExprFuse::Eq(ast_hi_0, ast_hi_1);

  auto expr_eq = gen->GetExpr(ast_eq);
  s->add(!expr_eq);
  EXPECT_EQ(z3::unsat, s->check());

  auto ast_full_1 = ExprFuse::Extract(bv_const_1, 7, 0);
  auto ast_full_eq = ExprFuse::Eq(ast_full_1, bv_const_1);
  auto expr_full_eq = gen->GetExpr(ast_full_eq);
  s->add(!expr_full_eq);
  EXPECT_EQ(z3::unsat, s->check());
}

TEST_F(TestZ3Expr, Concat) {
  using namespace ExprFuse;
  auto seg0 = bv_var_x;
  auto seg1 = bv_var_y;
  auto seg2 = NewBvVar("bv_var_z", 8);

  auto con0 = Concat(seg0, Concat(seg1, seg2));
  auto con1 = Concat(Concat(seg0, seg1), seg2);

  auto eq = Eq(con0, con1);
  auto ex = gen->GetExpr(eq);
  s->add(!ex);
  EXPECT_EQ(z3::unsat, s->check());

  s->reset();
  auto con2 = Concat(bv_const_0, bv_const_1);
  auto bv16 = BvConst(1, 16);
  auto veq = Eq(bv16, con2);
  auto eveq = gen->GetExpr(veq);
  s->add(!eveq);
  EXPECT_EQ(z3::unsat, s->check());
}

} // namespace ilang
