/// file
/// Unit test for ExprOp

#include "ila/ast/expr_op.h"
#include "ila/expr_fuse.h"
#include "ila/z3_expr_adapter.h"
#include "unit-include/util.h"
#include "z3++.h"

namespace ila {

class TestExprOp : public ::testing::Test {
public:
  TestExprOp() {
    s = new z3::solver(ctx);
    gen = new Z3ExprAdapter(ctx);

    bv_var = ExprFuse::NewBvVar("bv_var", 8);
    bv_var_0 = ExprFuse::NewBvVar("bv_var_0", 8);
  }
  ~TestExprOp() {
    delete s;
    delete gen;
  }

  void SetUp() {
    s->reset();
    gen->Clear();
  }

  void TearDown() {}

  z3::context ctx;
  z3::solver* s;
  Z3ExprAdapter* gen;

  ExprPtr bv_var;
  ExprPtr bv_var_0;
  ExprPtr bv_var_1;
  ExprPtr bool_var;
  ExprPtr bool_var_0;
  ExprPtr bool_var_1;
  ExprPtr mem_var;
  ExprPtr mem_var_0;
  ExprPtr mem_var_1;

  ExprPtr bv_const_0;
  ExprPtr bv_const_1;
  ExprPtr bool_const_true;
  ExprPtr bool_const_false;
  ExprPtr mem_const_0;
  ExprPtr mem_const_1;
}; // class TestExprOp

TEST_F(TestExprOp, And) {
  // expr
  ExprPtr bv_and = ExprFuse::And(bv_var, bv_var_0);
  auto e_bv_and = gen->GetZ3Expr(bv_and);
  // print
}

} // namespace ila

