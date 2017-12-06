/// \file
/// Unit test for logging system

#include "util/log.h"
#include "gtest/gtest.h"

namespace ila {

class LogTest : public ::testing::Test {
public:
  LogTest() {}

  ~LogTest() {}

  void SetUp() {}

  void TeadDown() {}
};

TEST_F(LogTest, GlogTest) {
  InitGLog();

  SetGLogVerboseLevel(0);

  VLOG(1) << "Try using VLOG\n";
  ILA_INFO << "Log the info message.\n";
  ILA_WARN << "Log the warning message.\n";
  ILA_ERROR << "Log the error message.\n";
}

TEST_F(LogTest, DebugLogTest) {
  SetDLogLevel(2);
  EnableDLog("Channel-1");
  EnableDLog("Channel-2");

  IlaDLog1("Channel-1") << "Channel 1 write to std::cout\n";
  IlaDLog2("Channel-2") << "Channel 2 write to std::cout\n";

  DisableDLog("Channel-2");

  SetDLogLevel(1, "DebugLogTest");

  IlaDLog1("Channel-1") << "Channel 1 write to file\n";
  IlaDLog2("Channel-1") << "Channel 1 should not write to file\n";
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

#if 0
  FLAGS_v = 5;
  // FLAGS_log_dir = "~/workspace/compute";
  FLAGS_alsologtostderr = 1;

  google::SetLogDestination(google::GLOG_INFO, "~/workspace/compute");
  InitIlaLogging();
#endif

  return RUN_ALL_TESTS();
}

} // namespace ila

