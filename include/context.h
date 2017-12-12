/// \file
/// The manager for all ILA objects, e.g. log, config, ILA, ast, etc

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "util/logging.h"

namespace ila {

class Context {
public:
  /// Constructor for the ILA context.
  Context(bool enable_logging = true);
  /// Destructor for the ILA context.
  ~Context();

  /// Initialize the context, such as the logging system.
  void Initialize();

  /// Clear up the context, such as the logging system.
  void ClearUp();

private:
  /// Flag of enabling the logging system.
  bool enable_logging_;
  /// The logging system, including glog and debug log.
  Logger logger_;

}; // class Context

} // namespace ila

#endif // __CONTEXT_H__

