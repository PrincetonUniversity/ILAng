/// \file
/// The header for the class Context -- the manager for all objects and
/// configurations.

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "util/log.h"
#include <memory>
#include <string>

/// \namespace ila
namespace ila {

/// \class Context
/// The manager of all objects and configurations.
class Context {
public:
  /// The constructor for Context.
  Context();
  /// The destructor for Context.
  ~Context();

  /// Initialize components based on the configuration.
  void Init();

  /// Clear up components based on the configuration.
  void Clear();

  /// Set directory for log file.
  void SetLoggingPath(const std::string& path);

  /// Output INFO/WARNING to std::err.
  void SetLogToStdErr(bool b);

private:
  // Configurations
  /****************************************************************************/
  /// Flag of enabling the logging system.
  bool logging_enable_;
  /// Whether the logging system has been initialized.
  bool logging_inited_;
  /// Verbose level for glog.
  int logging_verbose_;
  /// Whether set INFO/WARNING log to std::err.
  bool logging_stderr_;
  /// Directory path for glog.
  std::string logging_path_;

  // Helper functions
  /****************************************************************************/

  /// Initialize the logging system.
  void InitLogging();

  /// Clear up the logging system.
  void ClearLogging();

}; // class Context

typedef std::shared_ptr<Context> CtxPtr;

} // namespace ila

#endif // __CONTEXT_H__

