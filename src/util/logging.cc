/// \file
/// The source file for the logging/asserting system.

#include "util/logging.h"

namespace ila {

Logger::Logger() {
  InitGLog();
  InitDLog();
}

Logger::~Logger() {
  CloseGLog();
  CloseDLog();
}

// Macros and handlers for glog-based log system.
/******************************************************************************/

void Logger::SetGLogVerboseLevel(const int& lvl) { FLAGS_v = lvl; }

void Logger::SetGLogFilePath(const std::string& path) { FLAGS_log_dir = path; }

void Logger::SetGLogAlsoToStdErr(const int& b) { FLAGS_alsologtostderr = b; }

void Logger::InitGLog(const int& lvl, const std::string& path,
                      const int& also) {
  SetGLogVerboseLevel(lvl);
  SetGLogFilePath(path);
  SetGLogAlsoToStdErr(also);
  google::InitGoogleLogging("ila_log");
}

void CloseGLog() {}

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
    ptr = new std::ofstream(filename);
  }
}

void Logger::InitDLog() {
  log1_stream = new std::ofstream("/dev/null");
  log2_stream = new std::ofstream("/dev/null");
  null_stream = new std::ofstream("/dev/null");
}

void Logger::CloseDLog() {
  ClearStream(log1_stream);
  ClearStream(log2_stream);
  ClearStream(null_stream);
}

void Logger::SetDLogLevel(int l, const std::string& filename) {
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

void Logger::EnableDLog(const std::string& tag) { enabled_tags.insert(tag); }

void Logger::DisableDLog(const std::string& tag) { enabled_tags.erase(tag); }

void Logger::ClearDLogs() { enabled_tags.clear(); }

std::ostream& Logger::IlaDLog(std::ostream& l, const std::string& tag) {
  ILA_WARN_IF(l == NULL) << "Debug log stream not initialized.\n";
  if (l == NULL) {
    InitDLog();
  }

#ifdef DEBUG
  if (enabled_tags.find(tag) != enabled_tags.end()) {
    l << "[" << tag << "]";
    return l.flush();
  }
#endif // DEBUG
  return *null_stream;
}

std::ostream& Logger::IlaDLog1(const std::string& tag) {
  return IlaDLog(*log1_stream, tag);
}

std::ostream& Logger::IlaDLog2(const std::string& tag) {
  return IlaDLog(*log2_stream, tag);
}

} // namespace ila

