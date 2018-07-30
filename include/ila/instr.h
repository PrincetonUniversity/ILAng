/// \file
/// The header for the class Instr.

#ifndef INSTR_H__
#define INSTR_H__

#include "ila/expr_fuse.h"
#include "ila/hash_ast.h"
#include "ila/object.h"
#include <memory>
#include <string>

/// \namespace ila
namespace ila {

// Forward declaration for adding host ila.
class InstrLvlAbs;

/// \brief The class for the Instruction. An Instr object contains:
/// - the decode function
/// - a set of undate functions for the state variables
/// - several attributes, e.g. view
class Instr : public Object {
public:
  /// Pointer type for normal use of Instr.
  typedef std::shared_ptr<Instr> InstrPtr;
  /// Type for a set of state names
  typedef std::set<std::string> StateNameSet;
  /// Type for storing a set of Expr.
  typedef std::map<std::string, ExprPtr> ExprPtrMap;
  /// Pointer type for ILA.
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the ast simplifier.
  Instr(const std::string& name, const InstrLvlAbsPtr host = NULL);
  /// Default destructor.
  ~Instr();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new instruction (Instr) binded with the host. Used
  /// for hiding implementation specific type details.
  static InstrPtr New(const std::string& name, InstrLvlAbsPtr host = NULL);

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return true if Is type Instr.
  bool is_instr() const { return true; }
  /// Return true if has view. // HZ Comment: I'm not using this currently
  inline bool has_view() const { return has_view_; }
  /// Return the host ILA.
  inline InstrLvlAbsPtr host() const { return host_; }

  /// \brief Set the view flag.
  /// \param[in] v the flag indicating whether the instruction has views.
  inline void set_view(bool v) { has_view_ = v; }

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Set the decode function if not yet assigned.
  /// \param[in] decode is the pointer to the decode function (bool).
  void SetDecode(const ExprPtr decode);

  /// \brief Set the decode function.
  /// \param[in] decode is the pointer to the decode function (bool).
  void ForceSetDecode(const ExprPtr decode);

  /// \brief Add one update function for the state variable specified by name.
  /// \param[in] name the name of the state variable.
  /// \param[in] update the update function expression (same type as state).
  void AddUpdate(const std::string& name, const ExprPtr update);

  /// \brief Add one update function for the state variable specified by var
  /// pointer.
  /// \param[in] state the pointer to the state variable.
  /// \param[in] update the update function expression (same type as state).
  void AddUpdate(const ExprPtr state, const ExprPtr update);

  /// \brief Overwrite update function for the state variable specified by name.
  /// \param[in] name the name of the state variable.
  /// \param[in] update the update function expression (same type as state).
  void ForceAddUpdate(const std::string& name, const ExprPtr update);

  /// Return the decode function.
  ExprPtr GetDecode() const;

  /// \brief Return the update function for the state specified by name.
  /// \param[in] name the name of the state variable.
  /// \return the state update function.
  ExprPtr GetUpdate(const std::string& name) const;

  /// \brief Return the update function for the state specified by var pointer.
  /// \param[in] state the pointer to the state variable.
  ExprPtr GetUpdate(const ExprPtr state) const;

  /// \brief Return the (potential) updated state of this instruction.
  StateNameSet GetUpdatedStates() const;
  /// \brief Get the (potential) updated state of this instruction.
  void GetUpdatedStates(StateNameSet & ret_) const;

  /// Output function.
  std::ostream& Print(std::ostream& out) const;

  /// Overload output stream operator.
  friend std::ostream& operator<<(std::ostream& out, InstrPtr i);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Has view.
  bool has_view_ = false;

  /// The decode function.
  ExprPtr decode_ = NULL;
  /// The set of update functions, mapped by name.
  ExprPtrMap updates_;

  /// The host ILA.
  InstrLvlAbsPtr host_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Simplify AST nodes with the representatives.
  ExprPtr Unify(const ExprPtr e);

}; // class Instr

/// Pointer type for normal use of Instr.
typedef Instr::InstrPtr InstrPtr;

} // namespace ila

#endif // INSTR_H__

