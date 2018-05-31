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

    m.SetFetch(valx);
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

TEST_F(TestExprOp, Append) {
  { // append
    auto append = rx.Append(ry);
    auto z_app = unr.GetZ3Expr(append);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x == 0x0);
    s.add(z_y == 0x2);
    s.add(z_app != 0x2);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // concat
    auto concat = Concat(rx, ry);
    auto z_con = unr.GetZ3Expr(concat);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x == 0x01);
    s.add(z_y == 0x10);
    s.add(z_con != 0x0110);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(concat);
  }
}

TEST_F(TestExprOp, Extract) {
  { // range
    auto bfx = rx(4, 1);
    auto z_bfx = unr.GetZ3Expr(bfx);
    auto z_x = unr.GetZ3Expr(rx);

    auto bfy = Extract(ry, 5, 2);
    auto z_bfy = unr.GetZ3Expr(bfy);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x == 0b10100101);
    s.add(z_y == 0b11001011);
    s.add(z_bfx != z_bfy);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // single bit
    auto bx = rx(3);
    auto zbx = unr.GetZ3Expr(bx);
    auto z_x = unr.GetZ3Expr(rx);

    auto by = SelectBit(ry, 5);
    auto zby = unr.GetZ3Expr(by);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x == 0b00011110);
    s.add(z_y == 0b11100000);
    s.add(zbx != zby);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(bx);
  }
}

TEST_F(TestExprOp, ZExt) {
  auto extx = rx.ZExt(12);
  auto exty = ZExt(ry, 12);
  auto z_extx = unr.GetZ3Expr(extx);
  auto z_exty = unr.GetZ3Expr(exty);
  auto z_x = unr.GetZ3Expr(rx);
  auto z_y = unr.GetZ3Expr(ry);

  s.add(z_x == z_y);
  s.add(z_extx != z_exty);
  EXPECT_EQ(z3::unsat, s.check());

  s.reset();

  s.add(z_x == 0x44);
  s.add(z_extx != 0x44);
  EXPECT_EQ(z3::unsat, s.check());

  m.SetFetch(extx);
}

TEST_F(TestExprOp, SExt) {
  auto extx = rx.SExt(12);
  auto exty = SExt(ry, 12);
  auto z_extx = unr.GetZ3Expr(extx);
  auto z_exty = unr.GetZ3Expr(exty);
  auto z_x = unr.GetZ3Expr(rx);
  auto z_y = unr.GetZ3Expr(ry);

  s.add(z_x == z_y);
  s.add(z_extx != z_exty);
  EXPECT_EQ(z3::unsat, s.check());

  s.reset();

  s.add(z_x == 0x44);
  s.add(z_y == -0x44);
  s.add((z_extx + z_exty) != 0x0);
  EXPECT_EQ(z3::unsat, s.check());

  m.SetFetch(extx);
}

TEST_F(TestExprOp, Negate) {
  auto neg = -rx;
  auto z_n = unr.GetZ3Expr(neg);
  auto z_x = unr.GetZ3Expr(rx);
  auto z_y = unr.GetZ3Expr(ry);

  s.add(z_x == z_y);
  s.add((z_n + z_y) != 0x0);
  EXPECT_EQ(z3::unsat, s.check());

  m.SetFetch(neg);
}

TEST_F(TestExprOp, Not) {
  auto lnot = !fx;
  auto z_n = unr.GetZ3Expr(lnot);
  auto z_x = unr.GetZ3Expr(fx);
  auto z_y = unr.GetZ3Expr(fy);

  s.add(z_x == z_y);
  s.add(z_n && z_y);
  EXPECT_EQ(z3::unsat, s.check());

  m.SetValid(lnot);
}

TEST_F(TestExprOp, Complement) {
  auto com = ~rx;
  auto z_c = unr.GetZ3Expr(com);
  auto z_x = unr.GetZ3Expr(rx);
  auto z_y = unr.GetZ3Expr(ry);

  s.add(z_x == z_y);
  s.add((z_c & z_y) != 0x0);
  EXPECT_EQ(z3::unsat, s.check());

  m.SetFetch(com);
}

TEST_F(TestExprOp, And) {
  { // bv
    auto x_and_y = rx & ry;
    auto z_and = unr.GetZ3Expr(x_and_y);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);
    s.add(z_x != z_y);
    s.add(z_and == 0xff);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(x_and_y);
  }

  s.reset();

  { // bool
    auto x_and_y = fx & fy;
    auto z_and = unr.GetZ3Expr(x_and_y);
    auto z_x = unr.GetZ3Expr(fx);
    auto z_y = unr.GetZ3Expr(fy);
    s.add(z_x != z_y);
    s.add(z_and);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // bool const
    auto x_and_y = fx & false;
    auto z_and = unr.GetZ3Expr(x_and_y);
    s.add(z_and);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(x_and_y);
  }
}

TEST_F(TestExprOp, Or) {
  { // bv
    auto x_or_y = rx | ry;
    auto z_or = unr.GetZ3Expr(x_or_y);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);
    s.add(z_x != z_y);
    s.add(z_or == 0x00);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(x_or_y);
  }

  s.reset();

  { // bool
    auto x_or_y = fx | fy;
    auto z_or = unr.GetZ3Expr(x_or_y);
    auto z_x = unr.GetZ3Expr(fx);
    auto z_y = unr.GetZ3Expr(fy);
    s.add(z_x != z_y);
    s.add(!z_or);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // bool const
    auto x_or_y = fx | true;
    auto z_or = unr.GetZ3Expr(x_or_y);
    s.add(!z_or);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(x_or_y);
  }
}

TEST_F(TestExprOp, Xor) {
  { // bv
    auto x_xor_y = rx ^ ry;
    auto z_xor = unr.GetZ3Expr(x_xor_y);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);
    s.add(z_x != z_y);
    s.add(z_xor == 0x00);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(x_xor_y);
  }

  s.reset();

  { // bool
    auto x_xor_y = fx ^ fy;
    auto z_xor = unr.GetZ3Expr(x_xor_y);
    auto z_x = unr.GetZ3Expr(fx);
    auto z_y = unr.GetZ3Expr(fy);
    s.add(z_x != z_y);
    s.add(!z_xor);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // bool const
    auto x_xor_y = fx ^ true;
    auto z_xor = unr.GetZ3Expr(x_xor_y);
    auto z_x = unr.GetZ3Expr(fx);
    s.add(z_x && z_xor);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(x_xor_y);
  }
}

TEST_F(TestExprOp, LeftShift) {
  { // expr
    auto sh = rx << ry;
    auto z_sh = unr.GetZ3Expr(sh);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x == 0xff);
    s.add(z_y < 8);
    s.add(z_y >= 0);
    s.add(z_sh == 0x00);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // const
    auto sh = rx << 4;
    auto z_sh = unr.GetZ3Expr(sh);
    auto z_x = unr.GetZ3Expr(rx);

    s.add((z_sh & 0x0f) != 0x00);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(sh);
  }
}

TEST_F(TestExprOp, RightShift) {
  { // expr
    auto sh = rx >> ry;
    auto z_sh = unr.GetZ3Expr(sh);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x > 0x0f);
    s.add(z_y < 4);
    s.add(z_y >= 0);
    s.add(z_sh == 0x00);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // const
    auto sh = rx >> 4;
    auto z_sh = unr.GetZ3Expr(sh);
    auto z_x = unr.GetZ3Expr(rx);

    s.add(z_x >= 0);
    s.add((z_sh & 0xf0) != 0x00);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(sh);
  }
}

TEST_F(TestExprOp, LogicRightShift) {
  { // expr
    auto sh = Lshr(rx, ry);
    auto z_sh = unr.GetZ3Expr(sh);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x > 0x0f);
    s.add(z_y < 4);
    s.add(z_y >= 0);
    s.add(z_sh == 0x00);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // const
    auto sh = Lshr(rx, 4);
    auto z_sh = unr.GetZ3Expr(sh);

    s.add((z_sh & 0xf0) != 0x00);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(sh);
  }
}

TEST_F(TestExprOp, Add) {
  { // expr
    auto add = rx + ry;
    auto z_add = unr.GetZ3Expr(add);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x < 0x80);
    s.add(z_y < 0x80);
    s.add(z_add < 0xff);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // const
    auto add = rx + 0xf0;
    auto z_add = unr.GetZ3Expr(add);
    auto z_x = unr.GetZ3Expr(rx);

    s.add(z_x > 0);
    s.add(z_x < 0x0f);
    s.add(z_add >= 0xff);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(add);
  }
}

TEST_F(TestExprOp, Sub) {
  { // expr
    auto sub = rx - ry;
    auto z_sub = unr.GetZ3Expr(sub);
    auto z_x = unr.GetZ3Expr(rx);
    auto z_y = unr.GetZ3Expr(ry);

    s.add(z_x > z_y);
    s.add(z_x > 0);
    s.add(z_y > 0);
    s.add(z_sub < 0);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // const
    auto sub = rx - 0x0f;
    auto z_sub = unr.GetZ3Expr(sub);
    auto z_x = unr.GetZ3Expr(rx);

    s.add(z_x > 0x0f);
    s.add(z_sub < 0);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(sub);
  }
}

TEST_F(TestExprOp, Equal) {
  { // bv expr
    auto eq = (rx == ry);
    auto ze = unr.GetZ3Expr(eq);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(zx != zy);
    s.add(ze);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(eq);
  }

  s.reset();

  { // bv const
    auto eq = (rx == 0x00);
    auto ze = unr.GetZ3Expr(eq);
    auto zx = unr.GetZ3Expr(rx);

    s.add(ze);
    s.add(zx > 0);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // bool expr
    auto eq = (fx == fy);
    auto ze = unr.GetZ3Expr(eq);
    auto zx = unr.GetZ3Expr(fx);
    auto zy = unr.GetZ3Expr(fy);

    s.add(zx != zy);
    s.add(ze);
    EXPECT_EQ(z3::unsat, s.check());
  }

  s.reset();

  { // bool const
    auto eq = (fx == false);
    auto ze = unr.GetZ3Expr(eq);
    auto zx = unr.GetZ3Expr(fx);
    auto zy = unr.GetZ3Expr(fy);

    s.add(ze);
    s.add(z3::forall(zy, zy == (zx && zy)));
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, NotEqual) {
  { // expr
    auto ne = (rx != ry);
    auto zn = unr.GetZ3Expr(ne);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add((zx ^ zy) == 0x00);
    s.add(zn);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(ne);
  }

  s.reset();

  { // const
    auto ne = (rx != 0x00);
    auto zn = unr.GetZ3Expr(ne);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(z3::forall(zy, (zx & zy) == 0x00));
    s.add(zn);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, LessThan) {
  { // expr
    auto lt = rx < ry;
    auto zl = unr.GetZ3Expr(lt);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(zx >= 0x0f);
    s.add(zy <= 0x0f);
    s.add(zl);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(lt);
  }

  s.reset();

  { // const
    auto lt = rx < 0x0f;
    auto zl = unr.GetZ3Expr(lt);
    auto zx = unr.GetZ3Expr(rx);

    s.add(!zl);
    s.add((zx & 0x0f) == zx);
    s.add(zx != 0x0f);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, GreaterThan) {
  { // expr
    auto gt = rx > ry;
    auto zg = unr.GetZ3Expr(gt);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(zx <= 0x0f);
    s.add(zy >= 0x0f);
    s.add(zg);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(gt);
  }

  s.reset();

  { // const
    auto gt = rx > 0x0f;
    auto zg = unr.GetZ3Expr(gt);
    auto zx = unr.GetZ3Expr(rx);

    s.add(zg);
    s.add((zx & 0xf0) == 0x0);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, LessThanOrEqual) {
  { // expr
    auto le = rx <= ry;
    auto zl = unr.GetZ3Expr(le);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(zx > 0x0f);
    s.add(zy < 0x0f);
    s.add(zl);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(le);
  }

  s.reset();

  { // const
    auto le = rx <= 0x0f;
    auto zl = unr.GetZ3Expr(le);
    auto zx = unr.GetZ3Expr(rx);

    s.add(!zl);
    s.add((zx & 0x0f) == zx);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, GreaterThanOrEqual) {
  { // expr
    auto ge = rx >= ry;
    auto zg = unr.GetZ3Expr(ge);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(zx < 0x0f);
    s.add(zy > 0x0f);
    s.add(zg);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(ge);
  }

  s.reset();

  { // const
    auto ge = rx >= 0x0f;
    auto zg = unr.GetZ3Expr(ge);
    auto zx = unr.GetZ3Expr(rx);

    s.add(zg);
    s.add((zx & 0xf0) == 0x0);
    s.add(zx != 0x0f);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, UnsignedLessThan) {
  { // expr
    auto lt = Ult(rx, ry);
    auto zl = unr.GetZ3Expr(lt);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(z3::uge(zx, 0x0f));
    s.add(z3::ule(zy, 0x0f));
    s.add(zl);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(lt);
  }

  s.reset();

  { // const
    auto lt = Ult(rx, 0x0f);
    auto zl = unr.GetZ3Expr(lt);
    auto zx = unr.GetZ3Expr(rx);

    s.add(!zl);
    s.add((zx & 0x0f) == zx);
    s.add(zx != 0x0f);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, UnsignedGreaterThan) {
  { // expr
    auto gt = Ugt(rx, ry);
    auto zg = unr.GetZ3Expr(gt);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(z3::ule(zx, 0x0f));
    s.add(z3::uge(zy, 0x0f));
    s.add(zg);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(gt);
  }

  s.reset();

  { // const
    auto gt = Ugt(rx, 0x0f);
    auto zg = unr.GetZ3Expr(gt);
    auto zx = unr.GetZ3Expr(rx);

    s.add(zg);
    s.add((zx & 0xf0) == 0x0);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, UnsignedLessThanOrEqual) {
  { // expr
    auto le = Ule(rx, ry);
    auto zl = unr.GetZ3Expr(le);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(z3::ugt(zx, 0x0f));
    s.add(z3::ult(zy, 0x0f));
    s.add(zl);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(le);
  }

  s.reset();

  { // const
    auto le = Ule(rx, 0x0f);
    auto zl = unr.GetZ3Expr(le);
    auto zx = unr.GetZ3Expr(rx);

    s.add(!zl);
    s.add((zx & 0x0f) == zx);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, UnsignedGreaterThanOrEqual) {
  { // expr
    auto ge = Uge(rx, ry);
    auto zg = unr.GetZ3Expr(ge);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);

    s.add(z3::ult(zx, 0x0f));
    s.add(z3::ugt(zy, 0x0f));
    s.add(zg);
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(ge);
  }

  s.reset();

  { // const
    auto ge = Uge(rx, 0x0f);
    auto zg = unr.GetZ3Expr(ge);
    auto zx = unr.GetZ3Expr(rx);

    s.add(zg);
    s.add((zx & 0xf0) == 0x0);
    s.add(zx != 0x0f);
    EXPECT_EQ(z3::unsat, s.check());
  }
}

TEST_F(TestExprOp, Imply) {
  auto imply = Imply(fx, fy);
  auto zi = unr.GetZ3Expr(imply);
  auto zx = unr.GetZ3Expr(fx);
  auto zy = unr.GetZ3Expr(fy);

  s.add(zi);
  s.add(zx && !zy);
  EXPECT_EQ(z3::unsat, s.check());

  m.SetValid(imply);
}

TEST_F(TestExprOp, Ite) {
  { // bv
    auto ite = Ite(fx, rx, ry);
    auto zi = unr.GetZ3Expr(ite);
    auto zx = unr.GetZ3Expr(rx);
    auto zy = unr.GetZ3Expr(ry);
    auto zf = unr.GetZ3Expr(fx);

    s.add(zx != zy);
    s.add(z3::forall(zf, zi == zx));
    EXPECT_EQ(z3::unsat, s.check());

    m.SetFetch(ite);
  }

  s.reset();

  { // bool
    auto ite = Ite(rx == ry, fx, fy);
    auto zi = unr.GetZ3Expr(ite);
    auto zx = unr.GetZ3Expr(fx);
    auto zy = unr.GetZ3Expr(fy);
    auto zcx = unr.GetZ3Expr(rx);
    auto zcy = unr.GetZ3Expr(ry);

    s.add(zx != zy);
    s.add(z3::forall(zcx, zcy, zi == zx));
    EXPECT_EQ(z3::unsat, s.check());

    m.SetValid(ite);
  }

  s.reset();

  { // mem
    auto ite = Ite(fx, mx, my);
    auto zi = unr.GetZ3Expr(ite);
    auto zx = unr.GetZ3Expr(mx);
    auto zy = unr.GetZ3Expr(my);
    auto zf = unr.GetZ3Expr(fx);

    s.add(zx != zy);
    s.add(z3::forall(zf, zi == zx));
    EXPECT_EQ(z3::unsat, s.check());
  }
}

} // namespace ila

