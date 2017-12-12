/// \file
/// Unit test main function.

#include "util/log.h"
#include "gtest/gtest.h"

namespace ila {

int main(int argc, char** argv) {
  InitGLog();
  InitDLog();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace ila

