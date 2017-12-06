/// \file
/// Unit test for logging system

#include "util/log.h"
//#include "util/logging.h"
#include "gtest/gtest.h"

namespace ila {

TEST(LogUnitTest, GlogTest) {
  FLAGS_v = 5;
  InitIlaLogging();

  ILA_INFO << "Log the info message.\n";
  ILA_WARN << "Log the warning message.\n";
  ILA_ERROR << "Log the error message.\n";
}

TEST(LogUnitTest, DebugLogTest) {
  InitIlaLogging();

  SetLogLevel(2);
  EnableLog("Channel-1");
  EnableLog("Channel-2");

  IlaDebugLog1("Channel-1") << "Channel 1 write to std::cout\n";
  IlaDebugLog2("Channel-2") << "Channel 2 write to std::cout\n";

  DisableLog("Channel-2");

  SetLogLevel(1, "DebugLogTest");

  IlaDebugLog1("Channel-1") << "Channel 1 write to file\n";
  IlaDebugLog2("Channel-1") << "Channel 1 should not write to file\n";

  /*
  SetLogLevel(2, "test1");
  EnableLog("test1");
  INFO("test1") << "This is a testing log.\n";
  LOG1("test1") << "This is a testing log.\n";
  LOG2("test1") << "This is a testing log.\n";
  */
  // INFO("test") << "This is a testing log.\n";
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace ila

