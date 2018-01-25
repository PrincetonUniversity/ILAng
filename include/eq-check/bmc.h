/// \file
/// Header for bounded model checking

#ifndef __BMC_H__
#define __BMC_H__

#include "ila/instr_lvl_abs.h"
#include "ila/model_expr_generator.h"
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

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Add initial condition to the solver.
  void AddInit(InstrLvlAbsPtr m, ExprPtr init);

  /// \brief Add invariant to the solver.
  void AddInvariant(InstrLvlAbsPtr m, ExprPtr inv);

  /// \brief Add property of one ILA.
  void AddProperty(InstrLvlAbsPtr m, ExprPtr prop);

  /// \brief Legacy BMC where two ILAs are unrolled and compared monolithically.
  z3::check_result BmcLegacy(InstrLvlAbsPtr m0, const int& k0,
                             InstrLvlAbsPtr m1, const int& k1);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// z3 context.
  z3::context ctx_;

  /// The set of invariants.
  std::vector<std::pair<InstrLvlAbsPtr, ExprPtr>> invs_;
  /// The set of initial condition.
  std::vector<std::pair<InstrLvlAbsPtr, ExprPtr>> inits_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Bmc

} // namespace ila

#endif // __BMC_H__

