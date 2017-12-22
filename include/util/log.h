/// \file
/// The header file for the debug/logging/asserting system.

#ifndef __LOG_H__
#define __LOG_H__

#include <glog/logging.h>
#include <set>
#include <string>

namespace ila {

// Macros and handlers for normal assert/log system.
/******************************************************************************/

/// \def Debug log for info using glog.
#define ILA_INFO DLOG(INFO)
/// \def Debug log for warning using glog.
#define ILA_WARN DLOG(WARNING)
/// \def Debug log for error using glog.
#define ILA_ERROR DLOG(ERROR)
/// \def Conditional debug log for info using glog.
#define ILA_INFO_IF(b) DLOG_IF(INFO, b)
/// \def Conditional debug log for warning using glog.
#define ILA_WARN_IF(b) DLOG_IF(WARNING, b)
/// \def Conditional debug log for error using glog.
#define ILA_ERROR_IF(b) DLOG_IF(ERROR, b)
/// \def Fatal assertion (with fatal log message.)
#define ILA_ASSERT(b) DLOG_IF(FATAL, !(b))

/// \def Non-debug fatal assertion (with fatal log message.)
#define ILA_CHECK(b) CHECK(b)
/// \def Non-debug Fatal equal comparison (with fatal log message.)
#define ILA_CHECK_EQ(a, b) CHECK_EQ(a, b)
/// \def Non-debug fatal not equal comparison (with fatal log message.)
#define ILA_CHECK_NE(a, b) CHECK_NE(a, b)
/// \def Nond-debug fatal not null assertion for pointer.
#define ILA_NOT_NULL(ptr) CHECK_NOTNULL(ptr)

/// \brief Set the verbose level for glog system.
/// All verbose log (VLOG) with smaller level will be logged.
/// \paraam[in] lvl the verbose level (upper bound).
void SetVerboseLevel(const int& lvl);

/// Set the path for glog log file. Default no log file.
/// \param[in] path the path for glog log file.
void SetLogFilePath(const std::string& path);

/// Set whether to enable log (info and warning) to be log to standard error.
/// \param[in] also set 1 to log to std::cerr.
void SetToStdErr(const int& to_err);

// Wrapper for debug log system.
/******************************************************************************/
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

#endif // __LOG_H__

