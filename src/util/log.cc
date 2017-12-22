/// \file
/// The source file for the logging/asserting system.

#include "util/log.h"
#include <set>

namespace ila {

#if 0
std::ostream* LogChannel::log1_stream = new std::ofstream("/dev/null");
std::ostream* LogChannel::log2_stream = new std::ofstream("/dev/null");
std::ostream* LogChannel::null_stream = new std::ofstream("/dev/null");

#define log1_stream LogChannel::log1_stream
#define log2_stream LogChannel::log2_stream
#define null_stream LogChannel::null_stream

std::set<std::string> enabled_tags;
#endif

// Macros and handlers for glog-based log system.
/******************************************************************************/

void SetGLogVerboseLevel(const int& lvl) { FLAGS_v = lvl; }

void SetGLogFilePath(const std::string& path) { FLAGS_log_dir = path; }

void SetGLogAlsoToStdErr(const int& b) { FLAGS_alsologtostderr = b; }

static bool glog_inited = false;

void InitGLog(const int& lvl, const std::string& path, const int& also) {
  SetGLogVerboseLevel(lvl);
  SetGLogFilePath(path);
  SetGLogAlsoToStdErr(also);
  if (!glog_inited) {
    // google::InitGoogleLogging("ila_log");
    glog_inited = true;
  }
}

void CloseGLog() {}

#if 0
// Wrapper for debug log system.
/******************************************************************************/

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
    ptr = new std::ofstream(filename.c_str());
  }
}

void InitDLog() {
  log1_stream = new std::ofstream("/dev/null");
  log2_stream = new std::ofstream("/dev/null");
  null_stream = new std::ofstream("/dev/null");
}

void CloseDLog() {
  ClearStream(log1_stream);
  ClearStream(log2_stream);
  ClearStream(null_stream);
}

void SetDLogLevel(int l, const std::string& filename) {
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

void EnableDLog(const std::string& tag) { enabled_tags.insert(tag); }

void DisableDLog(const std::string& tag) { enabled_tags.erase(tag); }

void ClearDLogs() { enabled_tags.clear(); }

std::ostream& IlaDLog(std::ostream& l, const std::string& tag) {
#ifdef NDEBUG
  return *null_stream;
#endif // NDEBUG

  ILA_WARN_IF(l == NULL) << "Debug log stream not initialized.\n";
  if (l == NULL) {
    InitDLog();
  }

  if (enabled_tags.find(tag) != enabled_tags.end()) {
    l << "[" << tag << "]";
    return l.flush();
  }
  return *null_stream;
}

std::ostream& IlaDLog1(const std::string& tag) {
  return IlaDLog(*log1_stream, tag);
}

std::ostream& IlaDLog2(const std::string& tag) {
  return IlaDLog(*log2_stream, tag);
}
#endif

} // namespace ila

