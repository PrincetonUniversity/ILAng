/// \file
/// Header for a collection of ILA helpers.

#ifndef ABS_KNOB_H__
#define ABS_KNOB_H__

#include "ila/instr_lvl_abs.h"

namespace ila {

class AbsKnob {
public:
  AbsKnob();
  ~AbsKnob();

  /// Add dependant state vars of a tree of ILAs to the set.
  static void GetVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars);

private:
}; // class AbsKnob

} // namespace ila

#endif // ABS_KNOB_H__

