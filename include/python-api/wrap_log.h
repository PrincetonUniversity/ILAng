/// \file
/// Header for wrapping the logging system.

#ifndef __WRAP_LOG_H__
#define __WRAP_LOG_H__

#include "util/log.h"

namespace ila {

void EnableLog(const std::string& tag) { DebugLog::Enable(tag); }

void DisableLog(const std::string& tag) { DebugLog::Disable(tag); }

void ClearLogs() { DebugLog::Clear(); }

} // namespace

#endif // __WRAP_LOG_H__

