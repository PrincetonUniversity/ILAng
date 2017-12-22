/// \file
/// Header for logging debug message.

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <glog/logging.h>
#include <set>
#include <string>

/// \namespace ila
namespace ila {

class LogInitter {
public:
  LogInitter();
}; // class LogInitter

/// \class DebugLog
/// The wrapper for enabling and disabling debug tags.
class DebugLog {
public:
  /// Add a debug tag.
  static void Enable(const std::string& tag);

  /// Remove a debug tag.
  static void Disable(const std::string& tag);

  /// Clear all tags.
  static void Clear();

  /// Find if the tag is enabled.
  static bool Find(const std::string& tag);

private:
  /// The set of debug tags.
  static std::set<std::string> debug_tags_;

  /// The one and only initializer for the log system.
  static LogInitter init_;

}; // class DebugLog

/// \def Output debug log to standard output, conditioned on tag
#define ILA_DLOG(tag) DLOG_IF(INFO, DebugLog::Find(tag))

} // namespace ila

#endif // __DEBUG_H__

