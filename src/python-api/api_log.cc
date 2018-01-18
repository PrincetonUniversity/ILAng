/// \file
/// Source for Python API -- logging system

#include "python-api/ila_py_api.h"
#include "python-api/wrap_log.h"

namespace ila {
namespace pyapi {

void export_log() {

  // Initialize logging

  /// Set log level to the given value.
  def("setLogLevel", SetLogLevel);
  /// Set the path for log files.
  def("setLogPath", SetLogPath);
  /// Output all log to std err.
  def("setToStdErr", SetToStdErr);
  /// Turn on the debug log tag.
  def("enablelog", EnableLog);
  /// Turn off the debug log tag.
  def("disablelog", DisableLog);
  /// Turn off all the debug logs.
  def("clearlogs", ClearLogs);
}

} // namespace pyapi
} // namespace ila

