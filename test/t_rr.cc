/// \file
/// Unit test of the refinement relation

#include "eq-check/ref_rel.h"
#include "unit-include/eq_ilas.h"
#include "unit-include/util.h"

namespace ila {

class TestRR : public ::testing::Test {
public:
  TestRR() {}
  ~TestRR() {}

  void SetUp() {}

  void TearDown() {}

  InstrLvlAbsPtr ma = NULL;
  InstrLvlAbsPtr mb = NULL;

private:
}; // class TestRR

TEST_F(TestRR, RefUnitFF) {
  EqIlaGen gen;
  ma = gen.GetIlaFlat1();
  mb = gen.GetIlaFlat2();
  // TODO
}

TEST_F(TestRR, RefUnitFH) {
  // TODO
}

TEST_F(TestRR, RefUnitHH) {
  // TODO
}

} // namespace ila

