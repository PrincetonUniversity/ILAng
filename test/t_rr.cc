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

  void SetUp() {
    ConstructIlaA();
    ConstructIlaB();
  }

  void TearDown() {}

  InstrLvlAbsPtr ma = InstrLvlAbs::New("ma");
  InstrLvlAbsPtr mb = InstrLvlAbs::New("mb");

private:
  void ConstructIlaA() {
    // TODO
  }

  void ConstructIlaB() {
    // TODO
  }
}; // class TestRR

TEST_F(TestRR, RefUnit) {
  // TODO
}

} // namespace ila

