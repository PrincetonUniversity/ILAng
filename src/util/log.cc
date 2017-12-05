/// \file
/// The source file for the logging system using Google log.

#include "util/log.h"
#include <set>

namespace ila {

// The set of enabled verbose log.
std::set<std::string> enabled_log;

void InitLogging() {
  // Initialize Google's logging library.
  google::InitGoogleLogging("");
  // Reset enabled verbose log.
  ClearLog();
}

void EnableLog(std::string log_tag) { enabled_log.insert(log_tag); }

void DisableLog(std::string log_tag) { enabled_log.erase(log_tag); }

void ClearLog() { enabled_log.clear(); }

} // namespace ila

