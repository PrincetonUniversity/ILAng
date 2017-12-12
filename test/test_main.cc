/// \file
/// Unit test main function.

#include "context.h"
#include "util/log.h"
#include "gtest/gtest.h"
#include <memory>

namespace ila {

int main(int argc, char** argv) {
  InitGlog();
  InitDlog();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace ila

