/// \file
/// Unit test for the class Z3ExprAdapter

#include "ila/ast/expr.h"
#include "ila/ast/expr_const.h"
#include "ila/ast/expr_op.h"
#include "ila/ast/expr_var.h"
#include "ila/z3_expr_adapter.h"
#include "gtest/gtest.h"

namespace ila {

TEST(Z3ExprAdapter, Construct) {
  z3::context c;
  Z3ExprAdapter adapter(c);

  ExprPtr var_bool = std::make_shared<ExprVar>("var_bool");
  ExprPtr var_bv_0 = std::make_shared<ExprVar>("var_bv_0", 8);
  ExprPtr var_bv_1 = std::make_shared<ExprVar>("var_bv_1", 8);

  ExprPtr op_and = std::make_shared<ExprOpAnd>(var_bv_0, var_bv_1);
  ExprPtr op_or = std::make_shared<ExprOpOr>(var_bv_0, op_and);
  ExprPtr op_eq = std::make_shared<ExprOpEq>(var_bv_0, op_or);

  z3::expr expr_eq = adapter.GetZ3Expr(op_eq);

  // solve the validity
  z3::solver s(c);
  s.add(!expr_eq);

  auto result = s.check();
  EXPECT_TRUE(result == z3::unsat);
}

} // namespace ila

