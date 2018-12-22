/// \file
/// Header for wrapping the logging system.

#ifndef WRAP_LOG_H__
#define WRAP_LOG_H__

namespace ilang {
namespace pyapi {

void EnableLog(const std::string& tag);

void DisableLog(const std::string& tag);

void ClearLogs();

} // namespace pyapi
} // namespace ilang

#endif // WRAP_LOG_H__
