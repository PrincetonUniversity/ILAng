/// \file
/// Header for bounded model checking

#ifndef __BMC_H__
#define __BMC_H__

#include "ila/instr_lvl_abs.h"
#include "z3++.h"

/// \namespace ila
namespace ila {

/// \brief Bounded model checking engine for ILAs.
class Bmc {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  Bmc();
  /// Default destructor.
  ~Bmc();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the z3 context.
  z3::context& ctx();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Legacy BMC where two ILAs are unrolled and compared monolithically.
  bool BmcLegacy(InstrLvlAbsPtr m0, const int& k0, InstrLvlAbsPtr m1,
                 const int& k1);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  z3::context ctx_;

  // ------------------------- HELPERS -------------------------------------- //
  z3::expr Unroll(InstrLvlAbsPtr m, const int& k);

}; // class Bmc

} // namespace ila

#endif // __BMC_H__

