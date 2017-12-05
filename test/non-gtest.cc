#include "util/log.h"

// namespace ila {

using namespace ila;

int main(int argc, char** argv) {

  FLAGS_v = 5;
  FLAGS_log_dir = "";
  // FLAGS_logtostderr = false;
  FLAGS_alsologtostderr = 1;

  InitLogging();

  DLOG(INFO) << "Use DLOG to infro\n";
  VLOG(VLOG_TAG::VLOG_TEST1) << "This should be the verbose log.\n";
  VLOG(VLOG_TAG::VLOG_TEST2) << "This is the 2nd level verbose log.\n";
  return 0;
}

//} // namespace ila
