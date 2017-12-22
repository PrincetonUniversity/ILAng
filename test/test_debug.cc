/// \file
/// Unit test for debug logging.

#include "util/debug.h"
#include "gtest/gtest.h"

namespace ila {

TEST(DebugLog, Enable) {
  DebugLog::Enable("ch1");

  FLAGS_v = 3;
  FLAGS_log_dir = "";
  // FLAGS_alsologtostderr = 1;
  FLAGS_logtostderr = 0;
  ILA_DLOG("ch0") << "This should not happen.\n";
  ILA_DLOG("ch1") << "This should happen.\n";
}

TEST(DebugLog, Disable) {
  DebugLog::Enable("ch1");
  ILA_DLOG("ch1") << "This should happen.\n";
  DebugLog::Disable("ch1");
  ILA_DLOG("ch1") << "This should not happen.\n";
}
}

