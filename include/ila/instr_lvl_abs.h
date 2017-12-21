/// \file
/// The header for the class InstrLvlAbs.

#ifndef __INSTR_LVL_ABS_H__
#define __INSTR_LVL_ABS_H__

#include "ila/expr_fuse.h"
#include "ila/instr.h"
#include "ila/object.h"
#include <memory>
#include <ostream>
#include <set>
#include <string>

/// \namespace ila
namespace ila {

/// \class InstrLvlAbs
/// The class for the Instruction-Level Abstraction (ILA). An ILA object should
/// contain state variables, input varialbes, the valid function, the fetch
/// function, the set of instructions, and the set of child-ILAs.
class InstrLvlAbs : public Object {
public:
  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Default constructor. DO NOT USE.
  InstrLvlAbs();
  /// Consturctor with name.
  InstrLvlAbs(const std::string& name);
  /// Default destructor.
  ~InstrLvlAbs();

  /// \def InstrLvlAbsPtr
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;
  /// \def InstrLvlAbsPtrSet
  typedef std::shared_ptr<InstrLvlAbsPtr> InstrLvlAbsPtrSet;
  /// \def ILA specific type for the set of instruction pointers.
  typedef std::set<InstrPtr> InstrPtrSet;
  /// \def ILA specific type for the set of expr (ast node) pointers.
  typedef std::set<ExprPtr> ExprPtrSet;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Is type InstrLvlAbs.
  bool is_instr_lvl_abs() const { return true; }
  /// Return true if is specification (not implementation).
  bool is_spec() const;

  // ------------------------- METHODS -------------------------------------- //
  /// Add one input variable to the ILA.
  /// \param[in] input_var pointer to the input variable being added.
  /// \return added successfully.
  void AddInput(const ExprPtr& input_var);

  /// Add one state variable to the ILA.
  /// \param[in] state_var pointer to the state variable being added.
  /// \return added successfully.
  void AddState(const ExprPtr& state_var);

  /// Add one constraint to the initial condition, i.e. no contraint means
  /// arbitrary initial values to the state variables.
  /// \param[in] cntr_expr pointer to the constraint being added.
  /// \return added successfully.
  void AddInit(const ExprPtr& cntr_expr);

  /// Set the fetch function.
  /// \param[in] fetch_expr pointer to the fetch function (as an expression).
  /// \return added successfully.
  void SetFetch(const ExprPtr& fetch_expr);

  /// Set the valid function.
  /// \param[in] valid_expr pointer to the valid function (as an expression).
  /// \return added successfully.
  void SetValid(const ExprPtr& valid_expr);

  /// Add one instruction to the ILA.
  /// \param[in] instr pointer to the instruction being added.
  /// \return added successfully.
  void AddInstr(const InstrPtr& instr);

  /// Create one instruction and add to the ILA.
  /// \param[in] name instruction name (optional?)
  void CreateInstr(const std::string& name);

  /// Output stream function.
  std::ostream& Print(std::ostream& out) const;

  /// Overload utput stream
  friend std::ostream& operator<<(std::ostream& out, InstrLvlAbs& ila);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The set of input variables.
  ExprPtrSet inputs_;
  /// The set of state variables.
  ExprPtrSet states_;
  /// The set of initial constraints (not neccessary per-state).
  ExprPtrSet inits_;
  /// The fetch function.
  ExprPtr fetch_;
  /// The valid function.
  ExprPtr valid_;
  /// The set of instructions.
  InstrPtrSet instrs_;
  /// The set of child-ILAs.
  InstrLvlAbsPtrSet child_;

  /// Specification/implementation.
  bool is_spec_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class InstrLvlAbs

/// \def The type for InstrLvlAbs pointer.
typedef InstrLvlAbs::InstrLvlAbsPtr InstrLvlAbsPtr;

} // namespace ila

#endif // INSTR_LVL_ABS_H__

