/// \file
/// The source file for the logging/asserting system.

#include "util/log.h"
#include <set>

namespace ila {

// Wrapper for file-based log system for debuging.
/******************************************************************************/

std::ostream* log1_stream;
std::ostream* log2_stream;
std::ostream* null_stream;
std::set<std::string> enabled_tags;

void InitIlaLogging() {
  // Initialize glog.
  FLAGS_alsologtostderr = 1;
  google::InitGoogleLogging("ila_log");

  // Initialize debug log.
  log1_stream = new std::ofstream("/dev/null");
  log2_stream = new std::ofstream("/dev/null");
  null_stream = new std::ofstream("/dev/null");
}

void ClearStream(std::ostream*& ptr) {
  // Clear previous specified log file.
  if (ptr != &std::cout) {
    delete ptr;
  }
  ptr = new std::ofstream("/dev/null");
}

void SetStream(std::ostream*& ptr, const std::string& filename) {
  // Clear previous specified log file.
  if (ptr != &std::cout) {
    delete ptr;
  }
  // If no file name specified, default use standard output.
  if (filename == "") {
    ptr = &std::cout;
  } else {
    ptr = new std::ofstream(filename);
  }
}

void SetLogLevel(int l, const std::string& filename) {
  if (l == 0) {
    // No debug logging.
    ClearStream(log1_stream);
    ClearStream(log2_stream);
  } else if (l == 1) {
    // Channel 1 turned on.
    SetStream(log1_stream, filename);
    ClearStream(log2_stream);
  } else if (l >= 2) {
    // Channel 1 & 2 turned on.
    SetStream(log1_stream, filename);
    log2_stream = log1_stream;
  }
}

void EnableLog(const std::string& tag) { enabled_tags.insert(tag); }

void DisableLog(const std::string& tag) { enabled_tags.erase(tag); }

void ClearLogs() { enabled_tags.clear(); }

std::ostream& IlaDebugLog(std::ostream& l, const std::string& tag) {
  if (enabled_tags.find(tag) != enabled_tags.end()) {
    return l << "[" << tag << "]";
  }
  return *null_stream;
}

std::ostream& IlaDebugLog1(const std::string& tag) {
  return IlaDebugLog(*log1_stream, tag);
}

std::ostream& IlaDebugLog2(const std::string& tag) {
  return IlaDebugLog(*log2_stream, tag);
}

} // namespace ila

