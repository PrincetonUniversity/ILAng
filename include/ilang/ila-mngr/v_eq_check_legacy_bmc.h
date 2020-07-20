/// \file
/// Header for bounded model checking

#ifndef ILANG_ILA_MNGR_V_LEGACY_BMC_H__
#define ILANG_ILA_MNGR_V_LEGACY_BMC_H__

#include <map>

#include <z3++.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/target-smt/z3_expr_adapter.h>
#include <ilang/util/container.h>

/// \namespace ilang
namespace ilang {

/// \brief Simplified bounded model checking engine for ILAs.
class LegacyBmc {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  LegacyBmc();
  /// Default destructor.
  ~LegacyBmc();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Add initial condition to the solver.
  void AddInit(ExprPtr init);

  /// \brief Add invariant to the solver.
  void AddInvariant(ExprPtr inv);

  /// \brief Add property of one ILA.
  void AddProperty(ExprPtr prop);

  /// \brief Legacy BMC where two ILAs are unrolled and compared monolithically.
  z3::check_result Check(InstrLvlAbsPtr m0, const int& k0, InstrLvlAbsPtr m1,
                         const int& k1);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// z3 context.
  z3::context ctx_;
  /// Z3 expr generator.
  Z3ExprAdapter gen_ = Z3ExprAdapter(ctx_);

  /// The set of invariants.
  ExprPtrVec invs_;
  /// The set of initial condition.
  //
  ExprPtrVec inits_;

  /// Automatically add default transition (unchanged) for un-specified states
  /// if set to true.
  bool def_tran_ = false;

  // ------------------------- HELPERS -------------------------------------- //
  /// Unroll an ILA for k steps
  /// \param[in] m pointer to the ILA to unroll.
  /// \param[in] k number of steps to unroll.
  /// \param[in] pos starting frame number (default 0).
  /// \return the z3 expression representing the constraints.
  z3::expr UnrollCmplIla(InstrLvlAbsPtr m, const int& k, const int& pos = 0);

  /// \brief Get the set of z3 expression (constraints) for the instruction.
  /// - States with no update functions are encoded as unchanged.
  z3::expr Instr(const InstrPtr& instr, const std::string& suffix_prev,
                 const std::string& suffix_next, bool complete);

  /// \brief Get the set of z3 expression (constraints) for the ILA.
  /// - Assume no child-ILAs (not considered).
  /// - States with no update functions are encoded as unchanged.
  /// - Assume one-hot encoding of all instructions.
  z3::expr IlaOneHotFlat(const InstrLvlAbsPtr& ila,
                         const std::string& suffix_prev,
                         const std::string& suffix_next);

}; // class LegacyBmc

} // namespace ilang

#endif // ILANG_ILA_MNGR_V_LEGACY_BMC_H__
