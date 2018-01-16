/// \file
/// Source for wrapping logging system

#include "python-api/wrap_log.h"

namespace ila {
namespace pyapi {

void EnableLog(const std::string& tag) { DebugLog::Enable(tag); }

void DisableLog(const std::string& tag) { DebugLog::Disable(tag); }

void ClearLogs() { DebugLog::Clear(); }

} // namespace pyapi
} // namespace ila

