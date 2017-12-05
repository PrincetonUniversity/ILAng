/// \file
/// Unit test for logging system

//#include "util/log.h"
#include "util/logging.h"
#include "gtest/gtest.h"

namespace ila {

/*
TEST(GLogUnitTest, VerboseLog) {
FLAGS_v = 5;
// FLAGS_logtostderr = true;
InitLogging();

// FLAGS_log_dir = "$(pwd)/";

VLOG(VLOG_TAG::VLOG_TEST1) << "This should be the verbose log.\n";
VLOG(VLOG_TAG::VLOG_TEST2) << "This is the 2nd level verbose log.\n";
}
*/

TEST(LogUnitTest, VerboseLog) {
  InitLog();
  /*
  SetLogLevel(2, "test1");
  EnableLog("test1");
  INFO("test1") << "This is a testing log.\n";
  LOG1("test1") << "This is a testing log.\n";
  LOG2("test1") << "This is a testing log.\n";
  */
  INFO("test") << "This is a testing log.\n";
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace ila

