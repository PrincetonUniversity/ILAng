/// \file
/// Unit test for Expr

#include <ilang/ila/hash_ast.h>

#include "unit-include/expr_bank.h"

namespace ilang {

using namespace asthub;

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

  std::string msg = "";
  GET_STDERR_MSG(c->replace_arg(b, d), msg);
  EXPECT_TRUE(TopEq(c, e));
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif
}

} // namespace ilang
