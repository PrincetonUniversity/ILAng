/// \file
/// Tests for ILA manager utility -absknob

#include <ilang/ilang++.h>

#include "unit-include/util.h"

namespace ilang {

TEST(TestMngrabsknob, FlattenIla) {
  // parent
  auto m = Ila("parent");
  auto x = m.NewBvState("x", 8);
  m.SetValid(x != 0);
  auto i0 = m.NewInstr("i0");
  i0.SetDecode(x > 1);
  i0.SetUpdate(x, x + 1);

  // child <- parent
  auto c = m.NewChild("child");
  auto y = c.NewBvState("y", 8);
  c.SetValid(y != 0);
  auto i1 = c.NewInstr("i1");
  i1.SetDecode(y > 1);
  i1.SetUpdate(y, y + 1);

  EXPECT_EQ(m.instr_num(), 1);
  m.FlattenHierarchy();
  EXPECT_EQ(m.instr_num(), 2);

  // grand <- child <- parent
  auto g = c.NewChild("grand");
  auto z = g.NewBvState("z", 8);
  g.SetValid(z != 0);
  auto i2 = g.NewInstr("i2");
  i2.SetDecode(z > 1);

  EXPECT_EQ(m.instr_num(), 2);
  m.FlattenHierarchy();
  EXPECT_EQ(m.instr_num(), 3);
}

} // namespace ilang
