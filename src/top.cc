/// \file
/// The top level wrapper for the ILA infrastructure.

#include "top.h"

namespace ila {

IlaTop::IlaTop() {}

IlaTop::~IlaTop() {}

void IlaTop::Init() {
  InitGlog(0, "", 0);
  InitDlog();
}

void IlaTop::Clean() {
  CloseGlog();
  CloseDlog();
}

} // namespace ila

