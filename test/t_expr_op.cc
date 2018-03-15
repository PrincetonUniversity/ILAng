/// file
/// Unit test for ExprOp

#include "ila++.h"
#include "unit-include/util.h"
#include "z3++.h"

namespace ila {

class TestExprOp : public ::testing::Test {
public:
  TestExprOp() : s(ctx), unr(ctx) {}
  ~TestExprOp() {}

  void SetUp() {
    s.reset();
    SetToStdErr(1);
    DebugLog::Enable("TestExprOp");
  }

  void TearDown() {
    SetToStdErr(0);
    DebugLog::Disable("TestExprOp");
  }

  z3::context ctx;
  z3::solver s;
  IlaZ3Unroller unr;

  Ila m = Ila("abs");
  ExprRef fx = m.NewBoolState("fx");
  ExprRef fy = m.NewBoolState("fy");
  ExprRef rx = m.NewBvState("rx", 8);
  ExprRef ry = m.NewBvState("ry", 8);
  ExprRef mx = m.NewMemState("mx", 8, 8);
  ExprRef my = m.NewMemState("my", 8, 8);

}; // class TestExprOp

TEST_F(TestExprOp, Load) {
  { // expr
    auto valx = mx.Load(rx);
    auto z_valx = unr.GetZ3Expr(valx);
    auto z_memx = unr.GetZ3Expr(mx);
    auto z_idxx = unr.GetZ3Expr(rx);

    auto valy = Load(my, ry);
    auto z_valy = unr.GetZ3Expr(valy);
    auto z_memy = unr.GetZ3Expr(my);
    auto z_idxy = unr.GetZ3Expr(ry);

    s.add(z_memx == z_memy);
    s.add(z_idxx == z_idxy);
    s.add(z_valx != z_valy);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // constant
    auto valx = mx.Load(5);
    auto z_valx = unr.GetZ3Expr(valx);
    auto z_memx = unr.GetZ3Expr(mx);

    auto valy = Load(my, 5);
    auto z_valy = unr.GetZ3Expr(valy);
    auto z_memy = unr.GetZ3Expr(my);

    s.add(z_memx == z_memy);
    s.add(z_valx != z_valy);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, Store) {
  { // expr
    auto storex = mx.Store(rx, ry);
    auto z_strx = unr.GetZ3Expr(storex);
    auto z_memx = unr.GetZ3Expr(mx);
    auto z_idxx = unr.GetZ3Expr(rx);
    auto z_valx = unr.GetZ3Expr(ry);

    auto storey = Store(my, ry, rx);
    auto z_stry = unr.GetZ3Expr(storey);
    auto z_memy = unr.GetZ3Expr(my);
    auto z_idxy = unr.GetZ3Expr(ry);
    auto z_valy = unr.GetZ3Expr(rx);

    s.add(z_memx == z_memy);
    s.add(z_idxx == z_idxy);
    s.add(z_valx == z_valy);
    s.add(z_strx != z_stry);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // constant
    auto storex = mx.Store(4, 4);
    auto z_strx = unr.GetZ3Expr(storex);
    auto z_memx = unr.GetZ3Expr(mx);

    auto storey = Store(my, 4, 4);
    auto z_stry = unr.GetZ3Expr(storey);
    auto z_memy = unr.GetZ3Expr(my);

    s.add(z_memx == z_memy);
    s.add(z_strx != z_stry);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, And) {
  { // bv
    auto x_and_y = rx & ry;
    auto z_and = unr.GetZ3Expr(x_and_y);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);
    s.add(z_x == 0x0);
    s.add(z_y == 0x1);
    s.add(z_and != 0x0);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // bool
    auto x_and_y = fx & fy;
    auto z_and = unr.GetZ3Expr(x_and_y);
    auto z_x = unr.GetZ3Expr(fx);
    auto z_y = unr.GetZ3Expr(fy);
    s.add(!z_x);
    s.add(z_y);
    s.add(z_and);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

} // namespace ila

