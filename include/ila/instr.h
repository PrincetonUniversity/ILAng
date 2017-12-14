/// \file
/// The header for the class Instr.

#ifndef __INSTR_H__
#define __INSTR_H__

#include "ila/node.h"
#include "ila/object.h"
#include <memory>
#include <set>
#include <string>

/// \namespace ila
namespace ila {

/// \class Instr
/// The class for the Instruction. An Instr object should contain the decode
/// function and the state update functions for all the state variables. It can
/// optionally have some extra attributes, e.g. sub/micro, view, etc.
class Instr : public Object {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. DO NOT USE.
  Instr();
  /// Constructor with name.
  Instr(const std::string& name);
  /// Default destructor.
  ~Instr();

  /// \def InstrPtr
  typedef std::shared_ptr<Instr> InstrPtr;
  /// \def Instr specific type for the set of node pointers.
  typedef std::set<NodePtr> NodePtrSet;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// Is type Instr.
  bool IsInstr() const { return true; }

  /// Output function.
  virtual std::ostream& Print(std::ostream& out) const;

  // Instr definition.

  /// Set up decode function.
  /// \param[in] decode_func pointer to the decode function.
  bool SetDecode(NodePtr decode_func);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Has view.
  bool is_view_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Instr

/// \def The type for Instr pointer.
typedef Instr::InstrPtr InstrPtr;

} // namespace il

#endif // __INSTR_H__

