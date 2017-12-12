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

  /// Initializating the ILA tools, e.g. logging system.
  void Init();

  /// Clean up the ILA tools, e.g. logging system.
  void Clean();

private:
}; // class IlaTop

} // namespace ila

#endif // __ILA_TOP_H__

