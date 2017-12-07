/// \file
/// The header for the class Instr.

#ifndef __INSTR_H__
#define __INSTR_H__

#include "ila/node.h"
#include <memory>
#include <set>
#include <string>

namespace ila {

/// \brief The class for the Instruction.
/// An Instr object should contain the decode function and the state update
/// functions for all the state variables. It can optionally have some extra
/// attributes, e.g. sub/micro, view, etc.
class Instr {
public:
  /// The constructor for the class Instr.
  Instr();
  /// The destructor for the class Instr.
  ~Instr();

  // Type definitions.
  /****************************************************************************/
  /// \def Instr specific type for the node pointer.
  typedef Node::NodePtr NodePtr;
  /// \def Instr specific type for the set of node pointers.
  typedef std::set<NodePtr> NodePtrSet;
  /// \def Type of the Instr pointer.
  typedef std::shared_ptr<Instr> InstrPtr;

  // Instr definition.
  /****************************************************************************/
  /// Set the name of the Instr.
  /// \param[in] name Instr name.
  void SetName(const std::string& name);

  /// Get the name of the Instr.
  /// \return the name of the Instr.
  const std::string& GetName() const;

private:
  /// The name of the Instr.
  std::string name_;

}; // class Instr

} // namespace il

#endif // __INSTR_H__

