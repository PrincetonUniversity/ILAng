/// \file
/// The top level wrapper for the ILA infrastructure.

#include "top.h"

namespace ila {

IlaTop::IlaTop(bool enable_logging) : enable_logging_(enable_logging) {}

IlaTop::~IlaTop() {}

void IlaTop::Init() {
  if (enable_logging_) {
    InitGlog(0, "", 0);
    InitDlog();
  }
}

void IlaTop::Clear() {
  if (enable_logging_) {
    CloseGlog();
    CloseDlog();
  }
}

} // namespace ila

