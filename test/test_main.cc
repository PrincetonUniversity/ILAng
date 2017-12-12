/// \file
/// Unit test main function.

#include "context.h"
#include "util/log.h"
#include "gtest/gtest.h"
#include <memory>

namespace ila {

// Context ctx;
std::shared_ptr<Context> ctx;

int main(int argc, char** argv) {
  // InitGLog();
  // InitDLog();
  // Context ctx;
  ctx = std::make_shared<Context>();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace ila

