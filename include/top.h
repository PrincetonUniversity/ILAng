/// \file
/// The top level class for wrapping the ILA infrastructure.

#ifndef __ILA_TOP_H__
#define __ILA_TOP_H__

#include "util/log.h"

namespace ila {

class IlaTop() {
public:
  /// Constructor for IlaTop.
  IlaTop();
  /// Destructor for IlaTop.
  ~IlaTop();

  /// \brief Initializating the ILA infrastructure.
  /// Initialize the logging system (including glog and debug log).
  void InitIlaInfra();

  /// \brief Clear up the ILA infrastructure.
  /// Clear up and reset the logging system (especially the debug log).
  void CloseIlaInfra();

private:
}; // class IlaTop

} // namespace ila

#endif // __ILA_TOP_H__

