/// \file
/// The top level wrapper for the ILA infrastructure.

#include "top.h"

namespace ila {

IlaTop::IlaTop() { InitIlaInfra(); }

IlaTop::~IlaTop() { CloseIlaInfra(); }

void IlaTop::InitIlaInfra() {
  log_.InitGlog();
  log_.InitDlog();
}

void IlaTop::CloseIlaInfra() {
  log_.CloseGlog();
  log_.CloseDlog();
}

} // namespace ila

