/// \file
/// Source for wrapping logging system

#include <ilang/python-api/wrap_log.h>
#include <ilang/util/log.h>

namespace ilang {
namespace pyapi {

void EnableLog(const std::string& tag) { DebugLog::Enable(tag); }

void DisableLog(const std::string& tag) { DebugLog::Disable(tag); }

void ClearLogs() { DebugLog::Clear(); }

} // namespace pyapi
} // namespace ilang
