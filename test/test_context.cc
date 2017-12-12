/// \file
/// Unite test for ILA context.

#include "context.h"
#include "gtest/gtest.h"

namespace ila {

TEST(ContextUnitTest, InitializaLogging) {

  std::string msg = "";

  EXPECT_DEATH(ILA_ASSERT(1 == 2), ".*");
}

} // namespace ila

