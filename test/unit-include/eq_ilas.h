/// \file
/// Functions to construct equivalent ILAs (wrapped in a class).

#include "ila/instr_lvl_abs.h"

namespace ila {

/// \brief The class wrapper for constructing equivalent ILAs with behavior:
///
/// Input variables:
///  - start
///  - opcode
///
/// Architecture states:
///  - register [0-15] (at least 8 bits) (parameterized, with 16 for example)
///  - address
///  - counter
///  - memory (data width is 8)
///
/// Instruction 1: (start == 1 && opcode = 1)
///  - copy the value of %reg n-1 to %reg n (for all n = [1:15])
///
/// Instruction 2: (start == 1 && opcode == 2)
///  - copy the value of %reg n-1 to %reg n (n = %counter).
///  - if (%counter == 0) then copy %reg 15 to %reg 0
///
/// Instruction 3: (start == 1 && opcode == 3)
///  - swap the value stored in %memory, pointed by %address, with %register n.
///  - (n == %counter)
///
/// Instruction 4: (start == 1 && opcode == 4)
///  - sum up the value in %register [0-14] and store to %register 15.
class EqIlaGen {
public:
  /// \brief Flat ILA 1:
  /// - no child-ILA
  /// - every computation is done in an increasing order of the index.
  InstrLvlAbsPtr GetIlaFlat1();

  /// \brief Flag ILA 2:
  /// - no child-ILA
  /// - every computation is done in a decreasing order of the index.
  InstrLvlAbsPtr GetIlaFlat2();

  /// \brief Hierarchical ILA 1:
  /// - with child-ILA for instruction 3, storing intermediate value of reg.
  /// - with child-ILA for instruction 4, increasingly step-wise sum up.
  InstrLvlAbsPtr GetIlaHier1();

  /// \brief Hierarchical ILA 2:
  /// - with child-ILA for instruction 3, check reg iteratively.
  /// - with child-ILA for instruction 4. decreasingly step-wise sum up.
  InstrLvlAbsPtr GetIlaHier2();

private:
  /// parameterized register number. (must >= 3)
  int reg_num_ = 8;

}; // class EqIlaGen

} // namespace ila

