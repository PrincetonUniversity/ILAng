/// \file
/// Unit test for MapSet

#include <set>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/container.h>

#include "unit-include/util.h"

namespace ilang {

TEST(TestMapSet, IntInt) {
  MapSet<int, int> map;
  map.insert(0, 0);
  map.insert(0, 1);
  map.insert(0, 1);

  map.insert(5, 0);
  map.insert(5, 2);

  std::set<int> set0_ref = {0, 1};
  auto set0_tar = map.get(0);
  EXPECT_EQ(set0_ref.size(), set0_tar.size());

  for (auto i = set0_tar.begin(); i != set0_tar.end(); i++) {
    auto res = set0_ref.find(*i);
    EXPECT_NE(res, set0_ref.end());
  }

  EXPECT_ANY_THROW(map.get(1));

  for (auto i = map.begin(); i != map.end(); i++) {
    EXPECT_FALSE(i->second.empty());
  }
}

TEST(TestMapSet, ExprInstr) {
  using namespace asthub;

  MapSet<ExprPtr, InstrPtr> map;

  auto va = BvConst(0, 8);
  auto vb = NewBoolVar("bool_var");
  auto vc = BoolConst(true);

  auto i0 = Instr::New("i0");
  auto i1 = Instr::New("i1");
  auto i2 = Instr::New("i2");

  map.insert(va, i0);
  map.insert(va, i1);
  map.insert(va, i2);

  map.insert(vb, i0);
  map.insert(vb, i2);

  std::set<InstrPtr> ref = {i0, i2};
  auto tar = map.get(vb);
  EXPECT_EQ(ref.size(), tar.size());

  for (auto i = ref.begin(); i != ref.end(); i++) {
    auto res = tar.find(*i);
    EXPECT_NE(res, tar.end());
  }

  EXPECT_ANY_THROW(map.get(vc));

  for (auto i = map.begin(); i != map.end(); i++) {
    EXPECT_FALSE(i->second.empty());
  }
}

} // namespace ilang
