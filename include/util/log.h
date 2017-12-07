/// \file
/// The header file for the logging/asserting  system.

#ifndef __LOG_H__
#define __LOG_H__

#include <fstream>
#include <glog/logging.h>
#include <iostream>
#include <string>

namespace ila {

// Macros and handlers for glog-based log system.
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

/// \brief Set the verbose level for glog system.
/// All verbose log (VLOG) with smaller level will be logged.
/// \paraam[in] lvl the verbose level (upper bound).
void SetGLogVerboseLevel(const int& lvl);

/// Set the path for glog log file. Default no log file.
/// \param[in] path the path for glog log file.
void SetGLogFilePath(const std::string& path);

/// Set whether to enable log (info and warning) to be log to standard error.
/// \param[in] also set 1 to log to std::cerr.
void SetGLogAlsoToStdErr(const int& also);

/// Initialize glog system.
/// \param[in] lvl verbose level.
/// \param[in] path log file directory.
/// \param[in] also set 1 to log INFO and WARNING to std::cerr.
void InitGLog(const int& lvl = 0, const std::string& path = "",
              const int& also = 0);

/// Close glog system.
void CloseGLog();

// Wrapper for debug log system.
/******************************************************************************/

/// Initialize debug log system.
void InitDLog();

/// Close debug log system.
void CloseDLog();

/// Set the log level and the log file name. Default standard output if no file
/// name is specified.
/// \param[in] l log level.
/// \param[in] filename name of the log file.
void SetDLogLevel(int l, const std::string& filename = "");

/// Enable a log category.
/// \param[in] tag log category/tag to enable.
void EnableDLog(const std::string& tag);

/// Disable a log category.
/// \param[in] tag log category/tag to disable.
void DisableDLog(const std::string& tag);

/// Clear all log categories.
void ClearDLogs();

/// Channel 1 for logging debug message (under the given tag).
/// \param[in] tag the category to log the message.
std::ostream& IlaDLog1(const std::string& tag);

/// Channel 2 for logging debug message (under the given tag).
/// \param[in] tag the category to log the message.
std::ostream& IlaDLog2(const std::string& tag);

} // namespace ila

#endif // __LOG_H__

