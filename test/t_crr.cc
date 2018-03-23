/// \file
/// Unit test for compositional refinement relation.

#include "refinement/comp_ref_rel.h"
#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"

namespace ila {

class TestCrr : public ::testing::Test {
public:
  TestCrr() {}
  ~TestCrr() {}
  void SetUp() { DebugLog::Enable("CRR"); }
  void TearDown() {
    SetToStdErr(0);
    DebugLog::Disable("CRR");
  }

  InstrLvlAbsPtr m0 = SimpleCpu("m0");
  InstrLvlAbsPtr m1 = SimpleCpu("m1");

}; // class TestCrr

TEST_F(TestCrr, Refinement) {
  auto ref = RefinementMap::New();
  ref->set_appl(m0->instr(0)->decode());
  EXPECT_EQ(ref->appl(), m0->instr(0)->decode());

  auto flush = ExprFuse::BoolConst(true);
  for (size_t i = 0; i != m0->instr_num(); i++) {
    flush = ExprFuse::And(flush, ExprFuse::Not(m0->instr(0)->decode()));
  }
  ref->set_flush(flush);
  EXPECT_TRUE(ref->flush()->is_bool());

  ref->set_cmpl(ExprFuse::BoolConst(true));
  EXPECT_TRUE(ExprFuse::TopEq(ExprFuse::BoolConst(true), ref->cmpl()));

  EXPECT_EQ(0, ref->step());
  ref->set_step(1);
}

} // namespace ila

