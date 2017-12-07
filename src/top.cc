/// \file
/// The top level wrapper for the ILA infrastructure.

#include "top.h"

namespace ila {

IlaTop::IlaTop() { InitIlaInfra(); }

IlaTop::~IlaTop() { CloseIlaInfra(); }

void IlaTop::InitIlaInfra() {
  InitGlog(0, "", 0);
  InitDlog();
}

void IlaTop::CloseIlaInfra() {
  CloseGlog();
  CloseDlog();
}

} // namespace ila

