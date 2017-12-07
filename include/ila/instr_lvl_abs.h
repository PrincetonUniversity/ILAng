/// \file
/// The header for the class InstrLvlAbs.

#ifndef __INSTR_LVL_ABS_H__
#define __INSTR_LVL_ABS_H__

#include "ila/instr.h"
#include "ila/node.h"
#include <memory>
#include <set>
#include <string>

namespace ila {

/// \brief The class for the Instruction-Level Abstraction (ILA).
/// An Ila object should contain state variables, input varialbes, the valid
/// function, the fetch function, the set of instructions, and the set of
/// child-ILAs.
class InstrLvlAbs {
public:
  /// The constructor for the class InstrLvlAbs.
  InstrLvlAbs();
  /// The consturctor for the class InstrLvlAbs (with name).
  InstrLvlAbs(const std::string& name);
  /// The destructor for the class InstrLvlAbs.
  ~InstrLvlAbs();

  // Type definitions.
  /****************************************************************************/
  /// \def ILA specific type for the node pointer.
  typedef Node::NodePtr NodePtr;
  /// \def ILA specific type for the instruction pointer.
  typedef Instr::InstrPtr InstrPtr;
  /// \def ILA specific type for the set of node pointers.
  typedef std::set<NodePtr> NodePtrSet;
  /// \def ILA specific type for the set of instruction pointers.
  typedef std::set<InstrPtr> InstrPtrSet;
  /// \def Type of the ILA pointer.
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;

  // ILA definition.
  /****************************************************************************/
  /// Set the name of the ILA.
  /// \param[in] name ILA name.
  void SetName(const std::string& name);

  /// Get the name of the ILA.
  /// \return the name of the ILA.
  const std::string& GetName() const;

private:
  /// The name of the ILA.
  std::string name_;
  /// The set of input variables.
  NodePtrSet inputs_;
  /// The set of state variables.
  NodePtrSet states_;
  /// The set of initial constraints for the state variables.
  NodePtrSet inits_;
  /// The fetch function.
  NodePtr fetch_;
  /// The valid function.
  NodePtr valid_;
  /// The set of instructions.
  InstrPtrSet instrs_;

}; // class InstrLvlAbs

} // namespace ila

#endif // INSTR_LVL_ABS_H__

