/// \file
/// The manager for all ILA objects, e.g. log, config, ILA, ast, etc

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

//#include "util/logging.h"
#include "util/log.h"

namespace ila {

class Context {
public:
  /// Constructor for the ILA context.
  Context();
  /// Destructor for the ILA context.
  ~Context();

  /// Initialize the logging system.
  void InitLogging();

  /// Clear up and reset the logging system.
  void CloseLogging();

private:
  /// The logging system, including glog and debug log.
  Logger logger_;

}; // class Context

} // namespace ila

#endif // __CONTEXT_H__

