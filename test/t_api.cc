/// \file
/// Unit test for c++ API

#include "ila++.h"
#include "unit-include/util.h"

namespace ila {

TEST(TestApi, Expr) {
  // SetToStdErr(1);
  // SetToStdErr(0);
}

TEST(TestApi, Ila) {
  // SetToStdErr(1);

  IlaRef("top");

  // SetToSteErr(0);
}

} // namespace ila

