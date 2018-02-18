/// \file
/// Unit test for hashing ast sub-trees

#include "ila/instr_lvl_abs.h"
#include "unit-include/util.h"

namespace ila {

using namespace ExprFuse;

class TestHashApi : public ::testing::Test {
public:
  TestHashApi() {
    ila = InstrLvlAbs::New("host");
    x = ila->NewBoolState("x");
    y = ila->NewBoolState("y");
    z = ila->NewBoolState("z");
    bv_x = ila->NewBvState("bv_x", 8);
    bv_y = ila->NewBvState("bv_y", 8);
    bv_z = ila->NewBvState("bv_z", 8);
    mngr = ila->expr_mngr();
    if (!mngr) // XXX make it better
      mngr = ExprMngr::New();
  }

  ~TestHashApi() {}

  void SetUp() {
    DebugLog::Enable("HashApi");
    SetToStdErr(1);
  }

  void TearDown() {
    DebugLog::Disable("HashApi");
    SetToStdErr(0);
  }

  InstrLvlAbsPtr ila = NULL;
  ExprPtr x = NULL;
  ExprPtr y = NULL;
  ExprPtr z = NULL;
  ExprPtr bv_x = NULL;
  ExprPtr bv_y = NULL;
  ExprPtr bv_z = NULL;
  ExprMngrPtr mngr = NULL;

}; // TestHashApi

TEST_F(TestHashApi, level0) {
  // bool const
  auto a = BoolConst(true);
  auto b = BoolConst(true);
  auto c = BoolConst(false);

  auto sa = mngr->GetRep(a);
  auto sb = mngr->GetRep(b);
  auto sc = mngr->GetRep(c);

  EXPECT_EQ(sa, sb);
  EXPECT_NE(sa, sc);

  // bv const
  a = BvConst(0, 8);
  b = BvConst(0, 8);
  c = BvConst(1, 8);

  sa = mngr->GetRep(a);
  sb = mngr->GetRep(b);
  sc = mngr->GetRep(c);

  EXPECT_EQ(sa, sb);
  EXPECT_NE(sa, sc);

  // mem const (not shared)
  a = MemConst(0, 8, 8);
  b = MemConst(0, 8, 8);

  sa = mngr->GetRep(a);
  sb = mngr->GetRep(b);

  EXPECT_NE(sa, sb);
}

TEST_F(TestHashApi, level1) {
  // binary
  auto a = And(x, y);
  auto b = And(x, y);

  auto sa = mngr->GetRep(a);
  auto sb = mngr->GetRep(b);

  EXPECT_EQ(sa, sb);

  // ternary
  a = Ite(x, y, z);
  b = Ite(x, y, z);

  sa = mngr->GetRep(a);
  sb = mngr->GetRep(b);

  EXPECT_EQ(sa, sb);

  // param
  a = Extract(bv_x, 4, 0);
  b = Extract(bv_x, 4, 0);
  auto c = Extract(bv_y, 4, 0);
  auto d = Extract(bv_y, 3, 0);

  sa = mngr->GetRep(a);
  sb = mngr->GetRep(b);
  auto sc = mngr->GetRep(c);
  auto sd = mngr->GetRep(d);

  EXPECT_EQ(sa, sb);
  EXPECT_NE(sa, sc);
  EXPECT_NE(sa, sd);
  EXPECT_NE(sc, sd);
}

TEST_F(TestHashApi, level2) {
  auto a = And(x, y);
  auto b = Or(a, z);

  auto c = And(x, y);
  auto d = Or(c, z);

  auto sb = mngr->GetRep(b);
  auto sd = mngr->GetRep(d);

  EXPECT_EQ(sb, sd);

  auto e = Xor(x, y);
  auto f = Or(e, z);

  auto sf = mngr->GetRep(f);

  EXPECT_NE(sb, sf);
}

} // namespace ila

