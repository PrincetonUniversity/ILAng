/// \file
/// Unit test for operation construction, z3 formula, hash, etc.

#include "ila++.h"
#include "unit-include/util.h"

namespace ila {

class TestOpSanity : public ::testing::Test {
public:
  TestOpSanity() {
    // TODO
  }

  ~TestOpSanity() {
    // TODO
  }

  void SetUp() {
    DebugLog::Enable("OpSanity");
    SetToStdErr(1);
  }

  void TearDown() {
    DebugLog::Disable("OpSanity");
    SetToStdErr(0);
  }

  InstrLvlAbsPtr ila = InstrLvlAbs::New("host");

}; // class TestOpSanity

TEST_F(TestOpSanity, AndBool) {
  // TODO
  // Need to have a API for node equivalence (semantically).
}

} // namespace ila

