/// \file
/// The top level wrapper for the ILA infrastructure.

#include "top.h"

namespace ila {

IlaTop::IlaTop() {}

IlaTop::~IlaTop() {}

void IlaTop::Init() {
  InitGLog(0, "", 0);
  InitDLog();
}

void IlaTop::Clear() {
  CloseGLog();
  CloseDLog();
}

} // namespace ila

