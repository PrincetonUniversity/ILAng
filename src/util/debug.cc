/// \file
/// Source for logging debug message.

#include "util/debug.h"

namespace ila {

LogInitter::LogInitter() { google::InitGoogleLogging("ila_log"); }

std::set<std::string> DebugLog::debug_tags_;

LogInitter DebugLog::init_;

void DebugLog::Enable(const std::string& tag) { debug_tags_.insert(tag); }

void DebugLog::Disable(const std::string& tag) { debug_tags_.erase(tag); }

void DebugLog::Clear() { debug_tags_.clear(); }

bool DebugLog::Find(const std::string& tag) {
  return (debug_tags_.find(tag) != debug_tags_.end());
}

} // namespace ila

