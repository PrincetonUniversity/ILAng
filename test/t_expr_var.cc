/// \file
/// Unit test for ExprVar

#include "ila/ast/expr_var.h"
#include "util_test.h"
#include "z3++.h"

namespace ila {

TEST(ExprVar, Construct) {
  EXPECT_DEATH(ExprVar(), ".*");
  auto bool_var = std::make_shared<ExprVar>("bool_var");
  auto bv_var = std::make_shared<ExprVar>("bv_var");
  auto mem_var = std::make_shared<ExprVar>("mem_var");

  EXPECT_TRUE(bool_var->is_var());
  EXPECT_FALSE(bv_var->is_const());
  EXPECT_FALSE(mem_var->is_op());
}

} // namespace ila

