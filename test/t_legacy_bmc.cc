/// \file
/// Unit test for legacy BMC

#include "unit-include/eq_ilas.h"
#include "unit-include/util.h"
#include <ilang/verification/legacy_bmc.h>
#include <iostream>

namespace ilang {

TEST(TestLegacyBmc, FF) {
  SetToStdErr(0);

  DebugLog::Enable("Bmc.Legacy");
  DebugLog::Enable("ModelGen.IlaOneHotFlat");
  DebugLog::Enable("ModelGen.Instr");

  EqIlaGen ila_gen;

  auto m0 = ila_gen.GetIlaFlat1();
  auto m1 = ila_gen.GetIlaFlat2();

  LegacyBmc bmc;

  { // init for m0
    auto start = m0->input("start");
    auto start_i = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto opcode = m0->input("opcode");
    auto opcode_i = ExprFuse::Eq(opcode, ExprFuse::BvConst(1, 3));
    auto init = ExprFuse::And(start_i, opcode_i);
    // bmc.AddInit(m0, init);
    bmc.AddInit(init);
  }

  { // init for m1
    auto start = m1->input("start");
    auto start_i = ExprFuse::Eq(start, ExprFuse::BoolConst(true));
    auto opcode = m1->input("opcode");
    auto opcode_i = ExprFuse::Eq(opcode, ExprFuse::BvConst(1, 3));
    auto init = ExprFuse::And(start_i, opcode_i);
    // bmc.AddInit(m1, init);
    bmc.AddInit(init);
  }

  auto result = bmc.Check(m0, 1, m1, 1);

  EXPECT_EQ(z3::unsat, result);

  DebugLog::Disable("Bmc.Legacy");
  DebugLog::Disable("ModelGen.IlaOneHotFlat");
  DebugLog::Disable("ModelGen.Instr");

  SetToStdErr(0);
}

} // namespace ilang
