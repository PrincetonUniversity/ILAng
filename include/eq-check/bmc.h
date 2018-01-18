/// \file
/// Header for bounded model checking

#ifndef __BMC_H__
#define __BMC_H__

#include "ila/instr_lvl_abs.h"
#include "z3++.h"
#include <map>

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
  /// Reset/clear all cached values, including z3 context and expr mapping.
  void clear();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Legacy BMC where two ILAs are unrolled and compared monolithically.
  bool BmcLegacy(InstrLvlAbsPtr m0, const int& k0, InstrLvlAbsPtr m1,
                 const int& k1);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// z3 context.
  z3::context ctx_;
  /// z3 expression mapping.
  std::map<std::string, z3::expr> map_;

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Generate the z3 expression for the instruction.
  /// - Valid is not considered.
  /// - Decode should be satisfied.
  /// - Un-specified update functions are encoded as unchanged.
  z3::expr GetZ3ExprForInstr(InstrLvlAbsPtr m, InstrPtr instr,
                             const std::string& prefix,
                             const std::string& suffix) const;

}; // class Bmc

} // namespace ila

#endif // __BMC_H__

