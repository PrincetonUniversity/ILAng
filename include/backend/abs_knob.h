/// \file
/// Header for a collection of ILA helpers.

#ifndef ABS_KNOB_H__
#define ABS_KNOB_H__

#include "ila/instr_lvl_abs.h"

namespace ila {

class AbsKnob {
public:
  /// Add all vars (excluding child) to the set.
  static void InsertVar(const InstrLvlAbsCnstPtr m, ExprSet& vars);
  /// Add all state vars (excluding child) to the set.
  static void InsertStt(const InstrLvlAbsCnstPtr m, ExprSet& stts);
  /// Add all input vars (excluding child) to the set.
  static void InsertInp(const InstrLvlAbsCnstPtr m, ExprSet& inps);
  /// Add all vars (including child) to the set.
  static void InsertVarTree(const InstrLvlAbsCnstPtr top, ExprSet& vars);
  /// Add all state vars (including child) to the set.
  static void InsertSttTree(const InstrLvlAbsCnstPtr top, ExprSet& stts);
  /// Add all input vars (including child) to the set.
  static void InsertInpTree(const InstrLvlAbsCnstPtr top, ExprSet& inps);

  /// Add all dependant state vars (excluding child) to the set.
  static void InsertStt(const InstrCnstPtr instrs, ExprSet& stts);
  /// Add all dependant state vars (including child) to the set.
  static void InsertSttTree(const InstrCnstPtr instrs, ExprSet& stts);

  /// Get the set of all vars (excluding child).
  static ExprSet GetVar(const InstrLvlAbsCnstPtr m);
  /// Get the set of all state vars (excluding child).
  static ExprSet GetStt(const InstrLvlAbsCnstPtr m);
  /// Get the set of all input vars (excluding child).
  static ExprSet GetInp(const InstrLvlAbsCnstPtr m);
  /// Get the set of all vars (including child).
  static ExprSet GetVarTree(const InstrLvlAbsCnstPtr top);
  /// Get the set of all state vars (including child).
  static ExprSet GetSttTree(const InstrLvlAbsCnstPtr top);
  /// Get the set of all input vars (including child).
  static ExprSet GetInpTree(const InstrLvlAbsCnstPtr top);

  /// Add dependant vars (either state or input) to the set.
  static void GetVarOfExpr(const ExprPtr e, std::set<ExprPtr>& vars);
  /// Get the set of dependant vars (either state or input).
  static std::set<ExprPtr> GetVarOfExpr(const ExprPtr e);

  /// Add all instructions (including child) to the std::set/std::vector.
  template <class InstrCntr>
  static void GetInstrOfIla(const InstrLvlAbsPtr top, InstrCntr& instrs);
  /// Get the set of instructions (including child).
  static std::set<InstrPtr> GetInstrOfIla(const InstrLvlAbsPtr top);

  /// \brief Return a new ILA that contains the dependant instructions and
  /// child-ILAs of an instruction (defined by sub-programs).
  static InstrLvlAbsPtr ExtrDeptModl(const InstrPtr instr,
                                     const std::string& name);

  /// Copy an entire ILA.
  static void CopyIla(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst);

  /// \brief Rewrite an expression by replacing based on the rule.
  /// - If leaves contain non-var nodes, will replace with no further traverse.
  static ExprPtr Rewrite(const ExprPtr e, const ExprMap& rule);

private:
  /// Copy all state and input var (not including child).
  static void CopyVar(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst);
  /// Copy ILA attributes, e.g. fetch, valid, spec, etc.
  static void CopyAttr(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst);

  /// Create new state var in dst host based on the given src.
  static ExprPtr CopyStVar(const ExprPtr src, const InstrLvlAbsPtr dst_host);
  /// Create new input var in dst host based on the given src.
  static ExprPtr CopyInVar(const ExprPtr src, const InstrLvlAbsPtr dst_host);

}; // class AbsKnob

} // namespace ila

#endif // ABS_KNOB_H__

