/// \file
/// The header for the class Instr.

#ifndef __INSTR_H__
#define __INSTR_H__

#include "ila/expr_fuse.h"
#include "ila/object.h"
#include "ila/simplify.h"
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
  /// Type for storing a set of Expr.
  typedef std::map<std::string, ExprPtr> ExprPtrMap;
  /// Pointer type for ILA.
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with the ast simplifier.
  Instr(const std::string& name = "", ExprMngrPtr expr_mngr = NULL);
  /// Default destructor.
  ~Instr();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new instruction (Instr) binded with the simplifier. Used
  /// for hiding implementation specific type details.
  static InstrPtr New(const std::string& name = "",
                      ExprMngrPtr expr_mngr = NULL);

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return true if Is type Instr.
  bool is_instr() const { return true; }
  /// Return true if has view.
  bool has_view() const;
  /// Return true if simplification is performed.
  bool has_simplify() const;

  /// \brief Set the view flag.
  /// \param[in] v the flag indicating whether the instruction has views.
  void set_view(bool v);
  /// \brief Turn on simplification if true.
  /// \param[in] s the flag indicating whether to share the ast nodes.
  void set_simplify(bool s);
  /// \brief Assign the simplifier.
  /// \param[in] mngr the ast simplifier.
  void set_mngr(const ExprMngrPtr mngr);
  /// \brief Set the host ILA.
  /// \param[in] host the host ILA.
  void set_host(const InstrLvlAbsPtr host);

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

  /// Output function.
  std::ostream& Print(std::ostream& out) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Has view.
  bool has_view_ = false;
  /// To simplify expr nodes.
  bool simplify_;

  /// The decode function.
  ExprPtr decode_ = NULL;
  /// The set of update functions, mapped by name.
  ExprPtrMap updates_;

  /// The simplifier for expr nodes.
  ExprMngrPtr expr_mngr_;

  /// The host ILA.
  InstrLvlAbsPtr host_ = NULL;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Instr

/// Pointer type for normal use of Instr.
typedef Instr::InstrPtr InstrPtr;

} // namespace ila

#endif // __INSTR_H__

