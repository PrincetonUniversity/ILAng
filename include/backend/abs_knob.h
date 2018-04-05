/// \file
/// Header for a collection of ILA helpers.

#ifndef ABS_KNOB_H__
#define ABS_KNOB_H__

#include "ila/instr_lvl_abs.h"

namespace ila {

class AbsKnob {
public:
  /****************************************************************************/
  /// Add all dependent vars of the expr to the set.
  static void InsertVar(const ExprPtr e, ExprSet& vars);
  /// Get the set of all dependent vars of the expr.
  static ExprSet GetVar(const ExprPtr e);

  /****************************************************************************/
  /// Add all state vars of the host (excluding child) to the set.
  static void InsertStt(const InstrCnstPtr instrs, ExprSet& stts);
  /// Add all state vars of the host (including child) to the set.
  static void InsertSttTree(const InstrCnstPtr instrs, ExprSet& stts);

  /****************************************************************************/
  /// Add all vars of the ILA (excluding child) to the set.
  static void InsertVar(const InstrLvlAbsCnstPtr m, ExprSet& vars);
  /// Add all state vars of the ILA (excluding child) to the set.
  static void InsertStt(const InstrLvlAbsCnstPtr m, ExprSet& stts);
  /// Add all input vars of the ILA (excluding child) to the set.
  static void InsertInp(const InstrLvlAbsCnstPtr m, ExprSet& inps);
  /// Add all vars of the ILA (including child) to the set.
  static void InsertVarTree(const InstrLvlAbsCnstPtr top, ExprSet& vars);
  /// Add all state vars of the ILA (including child) to the set.
  static void InsertSttTree(const InstrLvlAbsCnstPtr top, ExprSet& stts);
  /// Add all input vars of the ILA (including child) to the set.
  static void InsertInpTree(const InstrLvlAbsCnstPtr top, ExprSet& inps);

  /// Get the set of all vars of the ILA (excluding child).
  static ExprSet GetVar(const InstrLvlAbsCnstPtr m);
  /// Get the set of all state vars of the ILA (excluding child).
  static ExprSet GetStt(const InstrLvlAbsCnstPtr m);
  /// Get the set of all input vars of the ILA (excluding child).
  static ExprSet GetInp(const InstrLvlAbsCnstPtr m);
  /// Get the set of all vars of the ILA (including child).
  static ExprSet GetVarTree(const InstrLvlAbsCnstPtr top);
  /// Get the set of all state vars of the ILA (including child).
  static ExprSet GetSttTree(const InstrLvlAbsCnstPtr top);
  /// Get the set of all input vars of the ILA (including child).
  static ExprSet GetInpTree(const InstrLvlAbsCnstPtr top);

  /// Add all instructions of the ILA (excluding child) to the set.
  static void InsertInstr(const InstrLvlAbsCnstPtr m, InstrVec& instrs);
  /// Add all instructions of the ILA (including child) to the set.
  static void InsertInstrTree(const InstrLvlAbsCnstPtr top, InstrVec& instrs);

  /// Get the set of instructions of the ILA (excluding child).
  static InstrVec GetInstr(const InstrLvlAbsCnstPtr m);
  /// Get the set of instructions of the ILA (including child).
  static InstrVec GetInstrTree(const InstrLvlAbsCnstPtr top);

  /****************************************************************************/
  /// \brief Rewrite an expression by replacing based on the rule.
  /// - If leaves contain non-var nodes, will replace with no further traverse.
  static ExprPtr Rewrite(const ExprPtr e, const ExprMap& rule);

  /// \brief Return a new ILA that contains the dependant instructions and
  /// child-ILAs of an instruction (defined by sub-programs).
  static InstrLvlAbsPtr ExtrDeptModl(const InstrPtr instr,
                                     const std::string& name);

  /// Copy an entire ILA.
  static void CopyIla(const InstrLvlAbsCnstPtr src, const InstrLvlAbsPtr dst);

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

