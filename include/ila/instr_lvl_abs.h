/// \file
/// The header for the class InstrLvlAbs.

#ifndef __INSTR_LVL_ABS_H__
#define __INSTR_LVL_ABS_H__

#include "ila/instr.h"
#include "ila/node.h"
#include "ila/object.h"
#include "ila/symbol.h"
#include <memory>
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
  /// The constructor for the class InstrLvlAbs.
  InstrLvlAbs();
  /// The consturctor for the class InstrLvlAbs (with name).
  InstrLvlAbs(const std::string& name);
  /// The destructor for the class InstrLvlAbs.
  ~InstrLvlAbs();

  /// Is type InstrLvlAbs.
  bool IsInstrLvlAbs() const { return true; }

  // Type definitions.
  /****************************************************************************/
  /// \def ILA specific type for the set of node pointers.
  typedef std::set<NodePtr> NodePtrSet;
  /// \def ILA specific type for the set of instruction pointers.
  typedef std::set<InstrPtr> InstrPtrSet;

  // ILA definition.
  /****************************************************************************/
  /// Set the name of the ILA.
  /// \param[in] name ILA name.
  void SetName(const std::string& name);

  /// Get the name of the ILA.
  /// \return the name of the ILA.
  const std::string& GetName() const;

  /// Add one input variable to the ILA.
  /// \param[in] input_var pointer to the input variable being added.
  /// \return added successfully.
  bool AddInput(const NodePtr& input_var);

  /// Add one state variable to the ILA.
  /// \param[in] state_var pointer to the state variable being added.
  /// \return added successfully.
  bool AddState(const NodePtr& state_var);

  /// Add one constraint to the initial condition, i.e. no contraint means
  /// arbitrary initial values to the state variables.
  /// \param[in] cntr_expr pointer to the constraint being added.
  /// \return added successfully.
  bool AddInit(const NodePtr& cntr_expr);

  /// Set the fetch function.
  /// \param[in] fetch_expr pointer to the fetch function (as an expression).
  /// \return added successfully.
  bool SetFetch(const NodePtr& fetch_expr);

  /// Set the valid function.
  /// \param[in] valid_expr pointer to the valid function (as an expression).
  /// \return added successfully.
  bool SetValid(const NodePtr& valid_expr);

  /// Add one instruction to the ILA.
  /// \param[in] instr pointer to the instruction being added.
  /// \return added successfully.
  bool AddInstr(const InstrPtr& instr);

private:
  /// The name of the ILA.
  std::string name_;
  /// The set of input variables.
  NodePtrSet inputs_;
  /// The set of state variables.
  NodePtrSet states_;
  /// The set of initial constraints (not neccessary per-state).
  NodePtrSet inits_;
  /// The fetch function.
  NodePtr fetch_;
  /// The valid function.
  NodePtr valid_;
  /// The set of instructions.
  InstrPtrSet instrs_;

}; // class InstrLvlAbs

/// \def The type for InstrLvlAbs pointer.
typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;

} // namespace ila

#endif // INSTR_LVL_ABS_H__

