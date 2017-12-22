/// \file
/// Unit test for the logging system.

#include "test_util.h"
#include "util/log.h"

namespace ila {

TEST(Log, Log) {
  std::string msg = "";
  SetToStdErr(1);

  // Logging level test.
  SetVerboseLevel(0);
  GET_STDERR_MSG((VLOG(1) << "Try using VLOG\n"), msg);
  EXPECT_TRUE(msg.empty());

  SetVerboseLevel(2);
  GET_STDERR_MSG((VLOG(1) << "Try using VLOG\n"), msg);
  EXPECT_FALSE(msg.empty());

// Logging channel test.
#ifndef NDEBUG
  SetToStdErr(0);
  GET_STDERR_MSG((ILA_INFO << "Log the info message.\n"), msg);
  EXPECT_TRUE(msg.empty());

  SetToStdErr(1);
  GET_STDERR_MSG((ILA_INFO << "Log the info message.\n"), msg);
  EXPECT_FALSE(msg.empty());

  SetToStdErr(0);
  GET_STDOUT_MSG((ILA_WARN << "Log the warning message.\n"), msg);
  EXPECT_TRUE(msg.empty());

  GET_STDERR_MSG((ILA_ERROR << "Log error.\n"), msg);
  EXPECT_FALSE(msg.empty());
#endif // NDEBUG

  // Check
  EXPECT_DEATH(ILA_CHECK(1 == 2), ".*");
  EXPECT_DEATH(ILA_CHECK_EQ(3, 5), ".*");
  EXPECT_DEATH(ILA_CHECK_NE(4, 4), ".*");

  std::shared_ptr<int> ptr = std::make_shared<int>(12);
  ILA_NOT_NULL(ptr.get());

// Assert
#ifndef NDEBUG
  EXPECT_DEATH(ILA_ASSERT(1 == 2), ".*");
#endif
}

TEST(Log, DebugEnable) {
  DebugLog::Enable("ch1");

  SetVerboseLevel(3);
  SetLogFilePath("");
  SetToStdErr(0);
  ILA_DLOG("ch0") << "This should not happen.\n";
  ILA_DLOG("ch1") << "This should happen.\n";
}

TEST(og, DebugDisable) {
  DebugLog::Enable("ch1");
  ILA_DLOG("ch1") << "This should happen.\n";
  DebugLog::Disable("ch1");
  ILA_DLOG("ch1") << "This should not happen.\n";
}

} // namespace ila

