/// \file
/// The top level class for wrapping the ILA infrastructure.

#ifndef __ILA_TOP_H__
#define __ILA_TOP_H__

#include "util/log.h"

namespace ila {

class IlaTop {
public:
  /// Constructor for IlaTop.
  IlaTop(bool enable_logging = true);
  /// Destructor for IlaTop.
  ~IlaTop();

  /// Initializating the ILA Tools, including the logging system, etc.
  void Init();

  /// Clear up the ILA Tools, including the logging system, etc.
  void Clear();

private:
  /// Flag of enabling the logging system.
  bool enable_logging_;

}; // class IlaTop

} // namespace ila

#endif // __ILA_TOP_H__

