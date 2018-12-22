/// \file
/// Functions to construct ILAs (wrapped in a class) and MCMs for tests
#ifndef T_MCM_ILA_H__
#define T_MCM_ILA_H__
#include "ilang/ila/instr_lvl_abs.h"

/// \brief The class wrapper for constructing Mcm ILAs with behavior:
/// No input variables (why you need them?)
///
/// state r0-r7 pc
/// decode is on pc
/// this is just a simplify version

namespace ilang {
class McmIlaGen {
public:
  void GetLitmusSbReg(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2);
  void GetLitmusMpReg(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2);
  void GetLitmusSbMem(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2);
  void GetLitmusMpMem(InstrLvlAbsPtr& T1, InstrLvlAbsPtr& T2);

  /// \brief An ILA with only one instruction
  /// - decode on pc
  /// - no Memvars
  InstrLvlAbsPtr GetIlaOneInstSimp();

  /// \brief An ILA with multi instructions
  /// - no Memvars
  /// - decode on pc
  /// - multiInst are linear
  InstrLvlAbsPtr GetIlaMultiInstLinearSimp();

  /// \brief An ILA with multi instructions
  /// - no Memvars
  /// - decode on pc
  /// - concurrent decode true
  InstrLvlAbsPtr GetIlaMultiInstCcSimp();

  /// \brief An ILA with only one instruction
  InstrLvlAbsPtr
  GetIlaOneInstPcDecode(const std::string& ila_name = "IlaInstPcDecode",
                        bool initRegs = false);

  /// \brief An ILA with only one instruction
  /// - full features
  // InstrLvlAbsPtr GetIlaOneInstFull();

  /// \brief An ILA with multi instructions
  /// - full features
  // InstrLvlAbsPtr GetIlaMultiInstFull();

  /// \brief
  InstrLvlAbsPtr GetSys1Ila1();
  InstrLvlAbsPtr GetSys1Ila2();

  InstrLvlAbsPtr GetSys2Ila1();
  InstrLvlAbsPtr GetSys2Ila2();
  InstrLvlAbsPtr GetSys2Ila3();
};
} // namespace ilang

#endif // T_MCM_ILA_H__
