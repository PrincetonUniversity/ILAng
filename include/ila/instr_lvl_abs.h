/// \file
/// The header for the class InstrLvlAbs.

#ifndef __INSTR_LVL_ABS_H__
#define __INSTR_LVL_ABS_H__

#include "ila/ast/func.h"
#include "ila/expr_fuse.h"
#include "ila/instr.h"
#include "ila/object.h"
#include "ila/simplify.h"
#include <map>
#include <memory>
#include <ostream>
#include <string>

/// \namespace ila
namespace ila {

/// The class of Instruction-Level Abstraction (ILA). An ILA contains:
/// - a set of state variables
/// - a set of input variables
/// - the set constraints for initial conditiona
/// - the valid function
/// - the fetch function
/// - the set of instructions
///   -# the decode function
///   -# a set of update functions
/// - the set of child-ILAs
class InstrLvlAbs : public Object {
public:
  /// \def InstrLvlAbsPtr
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;
  /// \def InstrLvlAbsPtrMap
  typedef std::map<std::string, InstrLvlAbsPtr> InstrLvlAbsPtrMap;
  /// \def InstrPtrMap
  typedef std::map<std::string, InstrPtr> InstrPtrMap;
  /// \def ExprPtrMap
  typedef std::map<std::string, ExprPtr> ExprPtrMap;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Default constructor. DO NOT USE.
  InstrLvlAbs();
  /// Consturctor with name.
  InstrLvlAbs(const std::string& name);
  /// Default destructor.
  ~InstrLvlAbs();

  // ------------------------- HELPERS -------------------------------------- //
  /// Create a new ILA (InstrLvlAbs) with the name. Used for hiding
  /// implementation specific type details.
  static InstrLvlAbsPtr NewILA(const std::string& name);

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return true if is InstrLvlAbs.
  bool is_instr_lvl_abs() const { return true; }
  /// Return true if is specification (not implementation).
  bool is_spec() const;

  /// Turn on the expr (AST node) simplification if true.
  void set_simplify(bool simplify);
  /// Set the ILA to be specification if true.
  void set_spec(bool spec);

  // ------------------------- METHODS -------------------------------------- //
  /// Add one input variable to the ILA.
  /// \param[in] input_var pointer to the input variable being added.
  void AddInput(const ExprPtr& input_var);

  /// Add one state variable to the ILA.
  /// \param[in] state_var pointer to the state variable being added.
  void AddState(const ExprPtr& state_var);

  /// Add one function to the ILA.
  /// \param[in] func pointer to the function object.
  void AddFunc(const FuncPtr& func);

  /// Add one constraint to the initial condition, i.e. no contraint means
  /// arbitrary initial values to the state variables.
  /// \param[in] cntr_expr pointer to the constraint being added.
  void AddInit(const ExprPtr& cntr_expr);

  /// Set the fetch function.
  /// \param[in] fetch_expr pointer to the fetch function (as an expression).
  void SetFetch(const ExprPtr& fetch_expr);

  /// Set the valid function.
  /// \param[in] valid_expr pointer to the valid function (as an expression).
  void SetValid(const ExprPtr& valid_expr);

  /// Add one instruction to the ILA.
  /// \param[in] instr pointer to the instruction being added.
  void AddInstr(const InstrPtr& instr);

  /// Add one ILA to the child list.
  /// \param[in] child pointer to the child-ILA being added.
  void AddChild(const InstrLvlAbsPtr& child);

  /// Create one Boolean variable and add as an input.
  /// \param[in] name of the bool input.
  /// \return pointer to the input.
  ExprPtr CreateBoolInput(const std::string& name);

  /// Create one Bitvector variable and add as an input.
  /// \param[in] name of the bitvector input.
  /// \param[in] bit_width length of the bitvector variable.
  /// \return pointer to the input.
  ExprPtr CreateBvInput(const std::string& name, const int& bit_width);

  /// Create one Boolean variable and add as a state.
  /// \param[in] name of the bool state.
  /// \return pointer to the state variable.
  ExprPtr CreateBoolState(const std::string& name);

  /// Create one Bitvector variable and add as a state.
  /// \param[in] name of the bitvector state.
  /// \param[in] bit_width value bit-width.
  /// \return pointer to the state variable.
  ExprPtr CreateBvState(const std::string& name, const int& bit_width);

  /// Create one Memory variable and add as a state.
  /// \param[in] name of the memory state.
  /// \param[in] addr_width address bit-width.
  /// \param[in] data_width data bit-width.
  /// \return pointer to the memory state.
  ExprPtr CreateMemState(const std::string& name, const int& addr_width,
                         const int& data_width);

  /// Create and add one instruction.
  /// \param[in] name of the instruction.
  /// \return pointer to the instruction.
  InstrPtr CreateInstr(const std::string& name);

  /// Create and add one child-ILA.
  /// \param[in] name of the child.
  /// \return pointer to the child-ILA.
  InstrLvlAbsPtr CreateChild(const std::string& name);

  /// Return the state variable with the specified name.
  /// \param[in] name of the state variable.
  /// \return pointer to the state variable.
  ExprPtr GetState(const std::string& name) const;

  /// Return the input variable with the specified name.
  /// \param[in] name of the input variable.
  /// \return pointer to the input variable.
  ExprPtr GetInput(const std::string& name) const;

  /// Return the fetch function.
  ExprPtr GetFetch() const;

  /// Return the valid function.
  ExprPtr GetValid() const;

  /// Return the instruction with the specified name.
  /// \param[in] name of the instruction.
  /// \return pointer to the instruction.
  ExprPtr GetInstr(const std::string& name) const;

  /// Return the child-ILA with the specified name.
  /// \param[in] name of the child-ILA.
  /// \return pointer to the child-ILA.
  ExprPtr GetChild(const std::string& name) const;

  /// Output stream function.
  std::ostream& Print(std::ostream& out) const;

  /// Overload utput stream
  friend std::ostream& operator<<(std::ostream& out, InstrLvlAbs& ila);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The set of input variables.
  ExprPtrMap inputs_;
  /// The set of state variables.
  ExprPtrMap states_;
  /// The set of initial constraints (not neccessary per-state).
  ExprPtrMap inits_;
  /// The fetch function.
  ExprPtr fetch_;
  /// The valid function.
  ExprPtr valid_;
  /// The set of instructions.
  InstrPtrMap instrs_;
  /// The set of child-ILAs.
  InstrLvlAbsPtrMap child_;

  /// Specification/implementation.
  bool is_spec_;
  /// To simplify expr nodes.
  bool to_simplify_;

  /// The simplifier for expr nodes.
  ExprSimplifier expr_mngr_;

  // ------------------------- HELPERS -------------------------------------- //

}; // class InstrLvlAbs

/// \def The type for InstrLvlAbs pointer.
typedef InstrLvlAbs::InstrLvlAbsPtr InstrLvlAbsPtr;

} // namespace ila

#endif // INSTR_LVL_ABS_H__

