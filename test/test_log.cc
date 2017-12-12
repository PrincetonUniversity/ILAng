/// \file
/// Unit test for the logging system.

#include "test_util.h"
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
    SetGLogAlsoToStdErr(0);
    SetGLogFilePath("");
    SetGLogVerboseLevel(0);
  }

  void TeadDown() {
    SetGLogAlsoToStdErr(0);
    SetGLogFilePath("");
    SetGLogVerboseLevel(0);
  }
};

TEST_F(LogTest, GlogTest) {
  std::string msg = "";
  SetGLogAlsoToStdErr(1);

  // Logging level test.
  SetGLogVerboseLevel(0);
  GET_STDERR_MSG((VLOG(1) << "Try using VLOG\n"), msg);
  EXPECT_TRUE(msg.empty());

  SetGLogVerboseLevel(2);
  GET_STDERR_MSG((VLOG(1) << "Try using VLOG\n"), msg);
  EXPECT_FALSE(msg.empty());

// Logging channel test.
#ifdef DEBUG
  SetGLogAlsoToStdErr(0);
  GET_STDERR_MSG((ILA_INFO << "Log the info message.\n"), msg);
  EXPECT_TRUE(msg.empty());

  SetGLogAlsoToStdErr(1);
  GET_STDERR_MSG((ILA_INFO << "Log the info message.\n"), msg);
  EXPECT_FALSE(msg.empty());

  SetGLogAlsoToStdErr(0);
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

  CloseGLog();
}

TEST_F(LogTest, DebugLogTest) {
  std::string msg;

  // Standard output
  SetDLogLevel(2);
  EnableDLog("Channel-1");
  EnableDLog("Channel-2");

#ifdef DEBUG
  GET_STDOUT_MSG((IlaDLog1("Channel-1") << "Channel 1 write to std::cout\n"),
                 msg);
  EXPECT_FALSE(msg.empty());
  GET_STDOUT_MSG((IlaDLog2("Channel-2") << "Channel 2 write to std::cout\n"),
                 msg);
  EXPECT_FALSE(msg.empty());
#endif // DEBUG

  // Log file
  SetDLogLevel(1, "DebugLogTest");
  DisableDLog("Channel-2");

  IlaDLog1("Channel-1") << "Channel 1 write to file\n";
  IlaDLog2("Channel-1") << "Channel 1 should not write to file\n";

  CloseDLog();
}

} // namespace ila

