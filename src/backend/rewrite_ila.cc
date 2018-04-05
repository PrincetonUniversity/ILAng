/// \file
/// Source for function object for rewriting ILA.

#include "backend/rewrite_ila.h"
#include "backend/abs_knob.h"

namespace ila {

bool FuncObjRewrIla::pre(const InstrLvlAbsCnstPtr src) const {
  //
  return false;
}

void FuncObjRewrIla::post(const InstrLvlAbsCnstPtr src) const {
  //
}

} // namespace ila

