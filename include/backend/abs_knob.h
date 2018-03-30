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

  /// Add all vars (including child) to the set.
  static void GetVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars);
  /// Add all state vars (including child) to the set.
  static void GetStVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars);
  /// Add all input vars (including child) to the set.
  static void GetInVarOfIla(const InstrLvlAbsPtr top, std::set<ExprPtr>& vars);

  /// Get the set of all vars (including child).
  static std::set<ExprPtr> GetVarOfIla(const InstrLvlAbsPtr top);
  /// Get the set of all state vars (including child).
  static std::set<ExprPtr> GetStVarOfIla(const InstrLvlAbsPtr top);
  /// Get the set of all input vars (including child).
  static std::set<ExprPtr> GetInVarOfIla(const InstrLvlAbsPtr top);

  static std::set<ExprPtr> GetVarOfExpr(const ExprPtr e);
  /// Add dependant vars (either state or input) to the set.
  static void GetVarOfExpr(const ExprPtr e, std::set<ExprPtr>& vars);

  /// Add all instructions (including child) to the std::set/std::vector.
  template <class InstrContainer>
  static void GetInstrOfIla(const InstrLvlAbsPtr top, InstrContainer& instrs);

private:
}; // class AbsKnob

} // namespace ila

#endif // ABS_KNOB_H__

