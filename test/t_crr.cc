/// \file
/// Unit test for compositional refinement relation.

#include "unit-include/simple_cpu.h"
#include "unit-include/util.h"
#include <ilang/ila/comp_ref_rel.h>

namespace ilang {

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

  EXPECT_EQ(-1, ref->step_appl());
  ref->set_step_appl(1);
  ref->set_step_orig(4);
  EXPECT_EQ(4, ref->step_orig());
}

TEST_F(TestCrr, Relation) {
  auto rel = RelationMap::New();

  for (size_t i = 0; i != m0->state_num(); i++) {
    rel->add(ExprFuse::Eq(m0->state(i), m1->state(i)));
  }

  EXPECT_FALSE(ExprFuse::TopEq(ExprFuse::BoolConst(true), rel->get()));
}

TEST_F(TestCrr, CompRefRel) {
#ifndef NDEBUG
  EXPECT_DEATH(CompRefRel(NULL, NULL, NULL), ".*");
#endif

  auto crr = CompRefRel::New();
  EXPECT_TRUE(crr->refine_a());
  EXPECT_TRUE(crr->refine_b());
  EXPECT_TRUE(crr->relation());
}

} // namespace ilang
