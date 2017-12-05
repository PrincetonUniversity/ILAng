/// \file
/// The header file for the logging system using Google log.

#ifndef __LOG_H__
#define __LOG_H__

#include <glog/logging.h>
#include <string>

namespace ila {

/// Initialize Google Log framework and the set of enabled logs.
void InitLogging();

/// Enable verbose log with the log tag.
/// \param[in] log_name log tag.
void EnableLog(std::string log_tag);

/// Disable verbose log with the log tag.
/// \param[in] log_name log tag.
void DisableLog(std::string log_tag);

/// Clear/reset id for verbose log.
void ClearLog();

enum VLOG_TAG { VLOG_TEST1 = 1, VLOG_TEST2 };

} // namespace ila

#endif // __LOG_H__

