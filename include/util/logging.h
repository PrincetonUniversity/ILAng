/// \file
/// The header file for the logging/assertion system.

#ifndef __LOGGING_H__
#define __LOGGING_H__

#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <set>
#include <string>

namespace ila {

// Macros for glog-based log system.
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
#define ILA_ASSERT(b) CHECK(b)
/// \def Fatal equal comparison (with fatal log message.)
#define ILA_ASSERT_EQ(a, b) CHECK_EQ(a, b)
/// \def Fatal not equal comparison (with fatal log message.)
#define ILA_ASSERT_NE(a, b) CHECK_NE(a, b)
/// \def Fatal not null assertion for pointer.
#define ILA_NOT_NULL(ptr) CHECK_NOTNULL(ptr)

class Logger {
public:
  /// The constructor for the Logger.
  Logger();
  /// The destructor for the Logger.
  ~Logger();

  // Handlers for glog-based log system.
  /****************************************************************************/
  /// \brief Set the verbose level for glog system.
  /// All verbose log (VLOG) with smaller level will be logged.
  /// \paraam[in] lvl the verbose level (upper bound).
  void SetGlogVerboseLevel(const int& lvl);

  /// Set the path for glog log file. Default no log file.
  /// \param[in] path the path for glog log file.
  void SetGlogFilePath(const std::string& path);

  /// Set whether to enable log (info and warning) to be log to standard error.
  /// \param[in] also set 1 to log to std::cerr.
  void SetGlogAlsoToStdErr(const int& also);

  /// Initialize glog system.
  /// \param[in] lvl verbose level.
  /// \param[in] path log file directory.
  /// \param[in] also set 1 to log INFO and WARNING to std::cerr.
  void InitGlog(const int& lvl = 0, const std::string& path = "",
                const int& also = 0);

  /// Close glog system.
  void CloseGlog();

  // Wrapper for debug log system.
  /****************************************************************************/

  /// Initialize debug log system.
  void InitDlog();

  /// Close debug log system.
  void CloseDlog();

  /// Set the log level and the log file name. Default standard output if no
  /// file
  /// name is specified.
  /// \param[in] l log level.
  /// \param[in] filename name of the log file.
  void SetDlogLevel(int l, const std::string& filename = "");

  /// Enable a log category.
  /// \param[in] tag log category/tag to enable.
  void EnableDlog(const std::string& tag);

  /// Disable a log category.
  /// \param[in] tag log category/tag to disable.
  void DisableDlog(const std::string& tag);

  /// Clear all log categories.
  void ClearDlogs();

  /// Helper function for output the debug message to the channel.
  /// \param[in] l the debug log channel.
  /// \param[in] tag the category to log the message.
  std::ostream& IlaDlog(std::ostream& l, const std::string& tag);

  /// Channel 1 for logging debug message (under the given tag).
  /// \param[in] tag the category to log the message.
  std::ostream& IlaDlog1(const std::string& tag);

  /// Channel 2 for logging debug message (under the given tag).
  /// \param[in] tag the category to log the message.
  std::ostream& IlaDlog2(const std::string& tag);

private:
  /// Stream channel for debug log 1.
  std::ostream* log1_stream = NULL;
  /// Stream channel for debug log 2.
  std::ostream* log2_stream = NULL;
  /// Stream channel for default log.
  std::ostream* null_stream = NULL;
  /// The set of enabled debug tags.
  std::set<std::string> enabled_tags;

}; // class Logger

} // namespace ila

#endif // __LOGGING_H__

