/// \file
/// Unit test for BMC

#include "eq-check/bmc.h"
#include "unit-include/eq_ilas.h"
#include "unit-include/util.h"
#include <iostream>

namespace ila {

TEST(TestBmc, Legacy) {
  EqIlaGen ila_gen;

  auto m0 = ila_gen.GetIlaFlat1();
  auto m1 = ila_gen.GetIlaFlat2();

  Bmc bmc;
  auto result = bmc.BmcLegacy(m0, 1, m1, 1);

  std::cout << "BMC: " << result << "\n";
}

} // namespace ila

