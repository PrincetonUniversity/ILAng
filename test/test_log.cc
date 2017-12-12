/// \file
/// Unit test for the logging system.

#include "util.h"
#include "util/log.h"
#include "gtest/gtest-spi.h"
#include "gtest/gtest.h"
#include <memory>

namespace ila {

class LogTest : public ::testing::Test {
public:
  LogTest() {}

  ~LogTest() {}

  void SetUp() {
    SetGlogAlsoToStdErr(0);
    SetGlogFilePath("");
    SetGlogVerboseLevel(0);
  }

  void TeadDown() {
    SetGlogAlsoToStdErr(0);
    SetGlogFilePath("");
    SetGlogVerboseLevel(0);
  }
};

TEST_F(LogTest, GlogTest) {
  std::string msg = "";
  SetGlogAlsoToStdErr(1);

  // Logging level test.
  SetGlogVerboseLevel(0);
  GET_STDERR_MSG((VLOG(1) << "Try using VLOG\n"), msg);
  EXPECT_TRUE(msg.empty());

  SetGlogVerboseLevel(2);
  GET_STDERR_MSG((VLOG(1) << "Try using VLOG\n"), msg);
  EXPECT_FALSE(msg.empty());

// Logging channel test.
#ifdef DEBUG
  SetGlogAlsoToStdErr(0);
  GET_STDERR_MSG((ILA_INFO << "Log the info message.\n"), msg);
  EXPECT_TRUE(msg.empty());

  SetGlogAlsoToStdErr(1);
  GET_STDERR_MSG((ILA_INFO << "Log the info message.\n"), msg);
  EXPECT_FALSE(msg.empty());

  SetGlogAlsoToStdErr(0);
  GET_STDOUT_MSG((ILA_WARN << "Log the warning message.\n"), msg);
  EXPECT_TRUE(msg.empty());

  GET_STDERR_MSG((ILA_ERROR << "Log error.\n"), msg);
  EXPECT_FALSE(msg.empty());
#endif // Debug

  // Assertions
  EXPECT_DEATH(ILA_ASSERT(1 == 2), ".*");
  EXPECT_DEATH(ILA_ASSERT_EQ(3, 5), ".*");
  EXPECT_DEATH(ILA_ASSERT_NE(4, 4), ".*");

  std::shared_ptr<int> ptr = std::make_shared<int>(12);
  ILA_NOT_NULL(ptr.get());

  CloseGlog();
}

TEST_F(LogTest, DebugLogTest) {
  std::string msg;

  // Standard output
  SetDlogLevel(2);
  EnableDlog("Channel-1");
  EnableDlog("Channel-2");

#ifdef DEBUG
  GET_STDOUT_MSG((IlaDlog1("Channel-1") << "Channel 1 write to std::cout\n"),
                 msg);
  EXPECT_FALSE(msg.empty());
  GET_STDOUT_MSG((IlaDlog2("Channel-2") << "Channel 2 write to std::cout\n"),
                 msg);
  EXPECT_FALSE(msg.empty());
#endif // DEBUG

  // Log file
  SetDlogLevel(1, "DebugLogTest");
  DisableDlog("Channel-2");

  IlaDlog1("Channel-1") << "Channel 1 write to file\n";
  IlaDlog2("Channel-1") << "Channel 1 should not write to file\n";

  CloseDlog();
}

} // namespace ila

