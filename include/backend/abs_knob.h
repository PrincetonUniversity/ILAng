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

  /// Add dependant vars to the set.
  static void GetVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars);
  /// Add dependant state vars to the set.
  static void GetStVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars);
  /// Add dependant state vars to the set.
  static void GetInVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars);

  /// Add dependant vars (either state or input) to the set.
  static void GetVarOfExpr(const ExprPtr e, std::set<ExprPtr>& vars);

private:
}; // class AbsKnob

} // namespace ila

#endif // ABS_KNOB_H__

