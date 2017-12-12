/// \file
/// Unit test main function.

#include "top.h"
#include "util/log.h"
#include "gtest/gtest.h"

namespace ila {

int main(int argc, char** argv) {
  IlaTop ctx;
  ctx.Init();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace ila

