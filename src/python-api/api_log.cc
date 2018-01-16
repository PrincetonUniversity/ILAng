/// \file
/// Source for Python API -- logging system

#include "python-api/ila_py_api.h"
#include "python-api/wrap_log.h"

namespace ila {
using namespace boost::python;

void export_log() {

  // Initialization, e.g. logging

  /// Set the minimun log level.
  def("setLogLevel", SetLogLevel);

  /// Set the path for log file.
  def("setLogPath", SetLogPath);

  /// Pipe log to stderr.
  def("setToStdErr", SetToStdErr);

  /// Add a debug tag.
  def("enablelog", EnableLog);

  /// Remove a debug tag.
  def("disablelog", DisableLog);

  /// Clear all tags.
  def("clearlogs", ClearLogs);
}

} // namespace ila

