/// \file
/// The header file for the debug/logging/asserting system.

#ifndef __LOG_H__
#define __LOG_H__

#include <glog/logging.h>
#include <set>
#include <string>

namespace ila {

// Only in Debug mode (Ignored in Release mode)
/******************************************************************************/
/// \def Log debug message to INFO if the "tag" has been enabled.
#define ILA_DLOG(tag) DLOG_IF(INFO, DebugLog::Find(tag))

/// \def Log the message to INFO (lvl 0). (Debug)
#define ILA_INFO DLOG(INFO)
/// \def Log the message to WARNING (lvl 1). (Debug)
#define ILA_WARN DLOG(WARNING)
/// \def Log the message to ERROR (lvl 2). (Debug)
#define ILA_ERROR DLOG(ERROR)
/// \def Conditionally log the message to INFO (lvl 0). (Debug)
#define ILA_INFO_IF(b) DLOG_IF(INFO, b)
/// \def Conditionally log the message to WARNING (lvl 1). (Debug)
#define ILA_WARN_IF(b) DLOG_IF(WARNING, b)
/// \def Conditionally log the message to ERROR (lvl 2). (Debug)
#define ILA_ERROR_IF(b) DLOG_IF(ERROR, b)

/// \def Assertion with message logged to FATAL (lvl 3). (Debug)
#define ILA_ASSERT(b) DLOG_IF(FATAL, !(b))

// Both in Debug and Release mode
// (Use only if high-assurance & non-performance critical)
/******************************************************************************/
/// \def Assertion with message logged to FATAL (lvl 3). (Debug/Release)
#define ILA_CHECK(b) CHECK(b)
/// \def Assert equal with message logged to FATAL (lvl 3). (Debug/Release)
#define ILA_CHECK_EQ(a, b) CHECK_EQ(a, b)
/// \def Assert not equal with message logged to FATAL (lvl 3). (Debug/Release)
#define ILA_CHECK_NE(a, b) CHECK_NE(a, b)
/// \def Assert string equal with FATAL message (lvl 3). (Debug/Release)
#define ILA_CHECK_STREQ(a, b) CHECK_STREQ(a, b)
/// \def Assert point not NULL with FATAL message (lvl 3). (Debug/Release)
#define ILA_NOT_NULL(ptr) CHECK_NOTNULL(ptr)

/// Log messages at or above this level will be logged. (Default: 0)
/// - INFO: level 0
/// - WARNING: level 1
/// - ERROR: level 2
/// - FATAL: level 3
void SetLogLevel(const int& lvl);

/// If specified, logfiles are written into this directory instead of the
/// default logging directory (\tmp).
void SetLogPath(const std::string& path);

/// Log messages to stderr instead of logfiles, if set to 1.
void SetToStdErr(const int& to_err);

// Wrapper for debug tag log system.
/******************************************************************************/
/// \class LogInitter
/// A one-time class for initializing GLog.
class LogInitter {
public:
  /// Constructor to initialize GLog.
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

} // namespace ila

#endif // __LOG_H__

