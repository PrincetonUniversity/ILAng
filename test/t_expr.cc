/// \file
/// Unit test for Expr

#include "ila/hash_ast.h"
#include "unit-include/expr_bank.h"

namespace ila {

using namespace ExprFuse;

class TestExpr : public ::testing::Test, public ExprBank<8> {
public:
  TestExpr() {}
  ~TestExpr() {}
  void SetUp() {}
  void TearDown() {}
}; // class TestExpr

TEST_F(TestExpr, ReplaceArgIdx) {
  auto a = And(BOOL[0], BOOL[1]);
  auto b = Or(BOOL[2], BOOL[3]);
  auto c = Xor(a, b);

  auto d = And(BOOL[2], BOOL[3]);
  auto e = Xor(a, d);

  c->replace_arg(1, d);

  EXPECT_NE(c, e);
  EXPECT_TRUE(TopEq(c, e));
}

TEST_F(TestExpr, ReplaceArgExpr) {
  auto a = And(BOOL[0], BOOL[1]);
  auto b = Or(BOOL[2], BOOL[3]);
  auto c = Xor(a, b);

  auto d = And(BOOL[2], BOOL[3]);
  auto e = Xor(a, d);

  c->replace_arg(b, d);

  EXPECT_NE(c, e);
  EXPECT_TRUE(TopEq(c, e));

  EXPECT_DEATH(c->replace_arg(b, d), ".*");
}

} // namespace ila

