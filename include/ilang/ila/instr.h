/// \file
/// The header for the class Instr.

#ifndef INSTR_H__
#define INSTR_H__

#include <ilang/ila/expr_fuse.h>
#include <ilang/ila/hash_ast.h>
#include <ilang/ila/object.h>
#include <memory>
#include <string>

/// \namespace ilang
namespace ilang {

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
  /// Return true if has view.
  inline bool has_view() const { return has_view_; }
  /// Return the host ILA.
  inline InstrLvlAbsPtr host() const { return host_; }

  /// \brief Set the view flag.
  /// \param[in] v the flag indicating whether the instruction has views.
  inline void set_view(bool v) { has_view_ = v; }

  /// \brief Set the decode function if not yet assigned.
  /// \param[in] decode is the pointer to the decode function (bool).
  void set_decode(const ExprPtr decode);

  /// \brief Set the update function for the state variable specified by name.
  /// \param[in] name the name of the state variable.
  /// \param[in] update the update function expression (same type as state).
  void set_update(const std::string& name, const ExprPtr update);

  /// \brief Set the update function for the state variable specified by var
  /// pointer.
  /// \param[in] state the pointer to the state variable.
  /// \param[in] update the update function expression (same type as state).
  void set_update(const ExprPtr state, const ExprPtr update);

  /// \brief Set the child-program (as a child-ILA) of the instruction.
  /// \param[in] program the pointer to the child-ILA.
  void set_program(const InstrLvlAbsPtr program);

  /// Return the decode function.
  inline ExprPtr decode() const { return decode_; }

  /// \brief Return the update function for the state specified by name.
  /// \param[in] name the name of the state variable.
  /// \return the state update function.
  ExprPtr update(const std::string& name) const;

  /// \brief Return the update function for the state specified by var pointer.
  /// \param[in] state the pointer to the state variable.
  ExprPtr update(const ExprPtr state) const;

  /// \brief return the (potentially) updated state of this function
  StateNameSet updated_states() const;

  /// \brief Returun the child-ILA comprising the child-program.
  inline InstrLvlAbsPtr program() const { return prog_; }

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Set the decode function.
  /// \param[in] decode is the pointer to the decode function (bool).
  void ForceSetDecode(const ExprPtr decode);

  /// \brief Overwrite update function for the state variable specified by name.
  /// \param[in] name the name of the state variable.
  /// \param[in] update the update function expression (same type as state).
  void ForceAddUpdate(const std::string& name, const ExprPtr update);

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

  /// The child-program (child-ILA being triggered).
  InstrLvlAbsPtr prog_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Simplify AST nodes with the representatives.
  ExprPtr Unify(const ExprPtr e);

}; // class Instr

/// Pointer type for normal use of Instr.
typedef Instr::InstrPtr InstrPtr;
/// Pointer type for read-only use of Instr.
typedef std::shared_ptr<const Instr> InstrCnstPtr;
/// Type for storing a set of Instr.
typedef std::vector<InstrPtr> InstrVec;

} // namespace ilang

#endif // INSTR_H__
