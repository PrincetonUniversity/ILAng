/// \file
/// Unit test for the logging system.

#include "unit-include/util.h"
#include "util/log.h"

namespace ila {

class TestLog : public ::testing::Test {
public:
  TestLog() {}
  ~TestLog() {}

  void SetUp() {
    // precondition for log test
    SetLogLevel(0); // log all
    SetLogPath(""); // log to /tmp
    SetToStdErr(1); // log to stderr for easy catching
  }

  void TearDown() {
    // reset to default condition
    SetLogLevel(0); // log all
    SetLogPath(""); // log to /tmp
#ifndef NDEBUG
    SetToStdErr(0); // still log to stderr
#else               // NDEBUG
    SetToStdErr(0); // not log to stderr
#endif              // NDEBUG
  }

}; // Log test fixture

TEST_F(TestLog, Level) {
  std::string msg_info;
  std::string msg_warn;
  std::string msg_error;

  // log with level 0 (INFO/WARNING/ERROR)
  SetLogLevel(0);
  GET_STDERR_MSG((ILA_INFO << "Log with INFO\n"), msg_info);
  GET_STDERR_MSG((ILA_WARN << "Log with WARN\n"), msg_warn);
  GET_STDERR_MSG((ILA_ERROR << "Log with WARN\n"), msg_error);

#ifndef NDEBUG
  EXPECT_FALSE(msg_info.empty());
  EXPECT_FALSE(msg_warn.empty());
  EXPECT_FALSE(msg_error.empty());
#else
  EXPECT_TRUE(msg_info.empty());
  EXPECT_TRUE(msg_warn.empty());
  EXPECT_TRUE(msg_error.empty());
#endif

  // log with level 1 (WARNING/ERROR)
  SetLogLevel(1);
  GET_STDERR_MSG((ILA_INFO << "Log with INFO\n"), msg_info);
  GET_STDERR_MSG((ILA_WARN << "Log with WARN\n"), msg_warn);
  GET_STDERR_MSG((ILA_ERROR << "Log with WARN\n"), msg_error);

#ifndef NDEBUG
  EXPECT_TRUE(msg_info.empty());
  EXPECT_FALSE(msg_warn.empty());
  EXPECT_FALSE(msg_error.empty());
#else
  EXPECT_TRUE(msg_info.empty());
  EXPECT_TRUE(msg_warn.empty());
  EXPECT_TRUE(msg_error.empty());
#endif

  // log with level 2 (ERROR)
  SetLogLevel(2);
  GET_STDERR_MSG((ILA_INFO << "Log with INFO\n"), msg_info);
  GET_STDERR_MSG((ILA_WARN << "Log with WARN\n"), msg_warn);
  GET_STDERR_MSG((ILA_ERROR << "Log with WARN\n"), msg_error);

#ifndef NDEBUG
  EXPECT_TRUE(msg_info.empty());
  EXPECT_TRUE(msg_warn.empty());
  EXPECT_FALSE(msg_error.empty());
#else
  EXPECT_TRUE(msg_info.empty());
  EXPECT_TRUE(msg_warn.empty());
  EXPECT_TRUE(msg_error.empty());
#endif

  // log with level 3 (FATAL only)
  SetLogLevel(3);

  GET_STDERR_MSG((ILA_INFO << "Log with INFO\n"), msg_info);
  GET_STDERR_MSG((ILA_WARN << "Log with WARN\n"), msg_warn);
  GET_STDERR_MSG((ILA_ERROR << "Log with WARN\n"), msg_error);

  EXPECT_TRUE(msg_info.empty());
  EXPECT_TRUE(msg_warn.empty());
  EXPECT_TRUE(msg_error.empty());
}

TEST_F(TestLog, Verbose) {
  std::string msg_info;
  std::string msg_warn;
  std::string msg_error;

  GET_STDERR_MSG((ILA_INFO << "Log with INFO\n"), msg_info);
  GET_STDERR_MSG((ILA_WARN << "Log with WARN\n"), msg_warn);
  GET_STDERR_MSG((ILA_ERROR << "Log with WARN\n"), msg_error);

#ifndef NDEBUG
  EXPECT_FALSE(msg_info.empty());
  EXPECT_FALSE(msg_warn.empty());
  EXPECT_FALSE(msg_error.empty());
#else
  EXPECT_TRUE(msg_info.empty());
  EXPECT_TRUE(msg_warn.empty());
  EXPECT_TRUE(msg_error.empty());
#endif

  GET_STDERR_MSG((ILA_INFO_IF(1 == 2) << "1 == 2\n"), msg_info);
  GET_STDERR_MSG((ILA_WARN_IF(1 == 1) << "1 == 1\n"), msg_warn);
  GET_STDERR_MSG((ILA_ERROR_IF(1 != 2) << "1 != 2\n"), msg_error);

#ifndef NDEBUG
  EXPECT_TRUE(msg_info.empty());
  EXPECT_FALSE(msg_warn.empty());
  EXPECT_FALSE(msg_error.empty());
#else
  EXPECT_TRUE(msg_info.empty());
  EXPECT_TRUE(msg_warn.empty());
  EXPECT_TRUE(msg_error.empty());
#endif
}

TEST_F(TestLog, Death) {
  std::string msg;

  // Assertions (Debug only)
  GET_STDERR_MSG((ILA_ASSERT(1 == 1) << "This should not be printed\n"), msg);
#ifndef NDEBUG
  EXPECT_TRUE(msg.empty());

  EXPECT_DEATH(ILA_ASSERT(1 == 2), ".*");
#endif

  // Check (Debug/Release)
  GET_STDERR_MSG((ILA_CHECK(1 == 1) << "This is true.\n"), msg);
  EXPECT_TRUE(msg.empty());

  EXPECT_DEATH(ILA_CHECK(1 == 2), ".*");
  EXPECT_DEATH(ILA_CHECK_EQ(3, 5), ".*");
  EXPECT_DEATH(ILA_CHECK_NE(4, 4), ".*");
  ILA_CHECK_STREQ("str", "str");

  std::shared_ptr<int> ptr = std::make_shared<int>(12);
  ILA_NOT_NULL(ptr.get());
  ILA_NOT_NULL(ptr);
  std::shared_ptr<int> null_ptr = NULL;
  EXPECT_DEATH(ILA_NOT_NULL(null_ptr.get()), ".*");
  EXPECT_DEATH(ILA_NOT_NULL(null_ptr), ".*");
}

TEST_F(TestLog, DebugEnable) {
  std::string msg0;
  std::string msg1;

  DebugLog::Enable("ch1");

  GET_STDERR_MSG((ILA_DLOG("ch0") << "This should not happen.\n"), msg0);
  GET_STDERR_MSG((ILA_DLOG("ch1") << "This should happen.\n"), msg1);

#ifndef NDEBUG
  EXPECT_TRUE(msg0.empty());
  EXPECT_FALSE(msg1.empty());
#endif
}

TEST_F(TestLog, DebugDisable) {
  std::string msg;

  DebugLog::Enable("ch1");

  GET_STDERR_MSG((ILA_DLOG("ch1") << "This should happen.\n"), msg);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif

  DebugLog::Disable("ch1");
  GET_STDERR_MSG((ILA_DLOG("ch1") << "This should not happen.\n"), msg);
  EXPECT_TRUE(msg.empty());
}

TEST_F(TestLog, Clear) {
  std::string msg;

  DebugLog::Enable("ch1");
  GET_STDERR_MSG((ILA_DLOG("ch1") << "This should happen.\n"), msg);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif

  DebugLog::Clear();
  GET_STDERR_MSG((ILA_DLOG("ch1") << "This should happen.\n"), msg);
  EXPECT_TRUE(msg.empty());
}

} // namespace ila

