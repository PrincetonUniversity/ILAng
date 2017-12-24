/// \file
/// Unit test for generating z3 express for ast.

#include "ila/expr_fuse.h"
#include "ila/z3_expr_adapter.h"
#include "gtest/gtest.h"

namespace ila {

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

TEST_F(TestZ3Expr, unary) {
  auto inverse = ExprFuse::Not(bool_var_x);
  auto inverse2 = ExprFuse::Not(inverse);
  auto notnot = ExprFuse::Eq(bool_var_x, inverse2);

  auto expr_notnot = gen->GetZ3Expr(notnot);
  s->add(!expr_notnot);
  auto result = s->check();
  EXPECT_TRUE(result == z3::unsat);
}

} // namespace ila

