/// \file
/// Unit test main function.

#include "context.h"
#include "util/log.h"
#include "gtest/gtest.h"

namespace ila {

int main(int argc, char** argv) {
  Context ctx;

  ctx.SetLoggingPath(".");
  ctx.SetLogToStdErr(true);

  ctx.Init();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace ila

