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
  void AddInit(ExprPtr init);

  /// \brief Add invariant to the solver.
  void AddInvariant(ExprPtr inv);

  /// \brief Add property of one ILA.
  void AddProperty(ExprPtr prop);

  /// \brief Legacy BMC where two ILAs are unrolled and compared monolithically.
  z3::check_result BmcLegacy(InstrLvlAbsPtr m0, const int& k0,
                             InstrLvlAbsPtr m1, const int& k1);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// z3 context.
  z3::context ctx_;

  /// The set of invariants.
  ExprPtrVec invs_;
  /// The set of initial condition.
  ExprPtrVec inits_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Unroll an ILA for k steps
  /// \param[in] m pointer to the ILA to unroll.
  /// \param[in] k number of steps to unroll.
  /// \param[in] pos starting frame number (default 0).
  /// \return the z3 expression representing the constraints.
  z3::expr UnrollCmplIla(InstrLvlAbsPtr m, const int& k, const int& pos = 0);

  /// Match the states for flat ILAs.
  z3::expr MatchStateFlat(InstrLvlAbsPtr m0, const int& pos0, InstrLvlAbsPtr m1,
                          const int& pos1);

}; // class Bmc

} // namespace ila

#endif // __BMC_H__

