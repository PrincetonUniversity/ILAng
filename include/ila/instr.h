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

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor with name.
  Instr(const std::string& name, bool simplify, ExprSimplifier& expr_mngr);
  /// Default destructor.
  ~Instr();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return true if Is type Instr.
  bool is_instr() const { return true; }
  /// Return true if has view.
  bool has_view() const;

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Set the decode function.
  /// \param[in] decode_expr is the pointer to the decode function (bool).
  void SetDecode(const ExprPtr decode_expr);

  /// \brief Add one update function for the state variable specified by name.
  /// \param[in] name the name of the state variable.
  /// \param[in] update the update function expression (same type as state).
  void AddUpdate(const std::string& name, const ExprPtr update);

  /// \brief Add one update function for the state variable specified by var
  /// pointer.
  /// \param[in] state the pointer to the state variable.
  /// \param[in] update the update function expression (same type as state).
  void AddUpdate(const ExprPtr state, const ExprPtr update);

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
  virtual std::ostream& Print(std::ostream& out) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Has view.
  bool has_view_;
  /// To simplify expr nodes.
  bool to_simplify_;

  /// The decode function.
  ExprPtr decode_;
  /// The set of update functions, mapped by name.
  ExprPtrMap updates_;

  /// The simplifier for expr nodes.
  ExprSimplifier& expr_mngr_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class Instr

/// Pointer type for normal use of Instr.
typedef Instr::InstrPtr InstrPtr;

} // namespace ila

#endif // __INSTR_H__

