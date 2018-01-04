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
/// Defines the core data structure and APIs for constructing and storing ILA.
namespace ila {

/// \brief The class of Instruction-Level Abstraction (ILA). An ILA contains:
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
  /// Pointer type for normal use of InstrLvlAbs
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;
  /// Type for storing a set of Expr
  typedef std::map<Symbol, ExprPtr> ExprPtrMap;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Consturctor.
  InstrLvlAbs(const std::string& name = "");
  /// Default destructor.
  ~InstrLvlAbs();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new ILA (InstrLvlAbs) with the name. Used for hiding
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
  /// \brief Add one input variable to the ILA, and register to the simplifier.
  /// \param[in] input_var pointer to the input variable being added.
  void AddInput(const ExprPtr input_var);

  /// \brief Add one state variable to the ILA, and register to the simplifier.
  /// \param[in] state_var pointer to the state variable being added.
  void AddState(const ExprPtr state_var);

  /// \brief Add one constraint to the initial condition, i.e. no contraint
  /// means arbitrary initial values to the state variables.
  /// \param[in] cntr_expr pointer to the constraint being added.
  void AddInit(const ExprPtr cntr_expr);

  /// \brief Set the fetch function, and simplify (if needed) by the simplifier.
  /// \param[in] fetch_expr pointer to the fetch function (as an expression).
  void SetFetch(const ExprPtr fetch_expr);

  /// \brief Set the valid function, and simplify (if needed) by the simplifier.
  /// \param[in] valid_expr pointer to the valid function (as an expression).
  void SetValid(const ExprPtr valid_expr);

  /// \brief Add one instruction to the ILA, and simplify (if needed). Note that
  /// only fully constructed instruction can be added.
  /// \param[in] instr pointer to the instruction being added.
  void AddInstr(const InstrPtr instr);

  /// \brief Add one ILA to the child list. No simplification between ILAs.
  /// \param[in] child pointer to the child-ILA being added.
  void AddChild(const InstrLvlAbsPtr child);

  /// \brief Create one Boolean variable and register as an input.
  /// \param[in] name of the bool input.
  /// \return pointer to the input.
  ExprPtr NewBoolInput(const std::string& name);

  /// \brief Create one Bitvector variable and register as an input.
  /// \param[in] name of the bitvector input.
  /// \param[in] bit_width length of the bitvector variable.
  /// \return pointer to the input.
  ExprPtr NewBvInput(const std::string& name, const int& bit_width);

  /// \brief Create one Boolean variable and register as a state.
  /// \param[in] name of the bool state.
  /// \return pointer to the state variable.
  ExprPtr NewBoolState(const std::string& name);

  /// \brief Create one Bitvector variable and register as a state.
  /// \param[in] name of the bitvector state.
  /// \param[in] bit_width value bit-width.
  /// \return pointer to the state variable.
  ExprPtr NewBvState(const std::string& name, const int& bit_width);

  /// \brief Create one Memory variable and register as a state.
  /// \param[in] name of the memory state.
  /// \param[in] addr_width address bit-width.
  /// \param[in] data_width data bit-width.
  /// \return pointer to the memory state.
  ExprPtr NewMemState(const std::string& name, const int& addr_width,
                      const int& data_width);

  /// \brief Create and register one instruction.
  /// \param[in] name of the instruction.
  /// \return pointer to the instruction.
  InstrPtr NewInstr(const std::string& name = "");

  /// \brief Create and register one child-ILA.
  /// \param[in] name of the child.
  /// \return pointer to the child-ILA.
  InstrLvlAbsPtr NewChild(const std::string& name);

  /// \brief Return the state variable pointer; NULL if not registered.
  /// \param[in] name of the state variable.
  /// \return pointer to the state variable.
  ExprPtr GetState(const std::string& name) const;

  /// \brief Return the input variable pointer; NULL if not registered.
  /// \param[in] name of the input variable.
  /// \return pointer to the input variable.
  ExprPtr GetInput(const std::string& name) const;

  /// Return the fetch function.
  ExprPtr GetFetch() const;

  /// Return the valid function.
  ExprPtr GetValid() const;

  /// \brief Return the instruction pointer; NULL if not registered.
  /// \param[in] name of the instruction.
  /// \return pointer to the instruction.
  InstrPtr GetInstr(const std::string& name) const;

  /// \brief Return the number of instruction registered.
  /// \return the number of the instruction registered.
  size_t GetInstrNum() const;

  /// \brief Return the instruction indexed.
  /// \param[in] idx the index of the instruction.
  /// \return pointer to the instruction.
  InstrPtr GetInstr(const size_t& idx) const;

  /// \brief Return the child-ILA pointer; NULL if not registered.
  /// \param[in] name of the child-ILA.
  /// \return pointer to the child-ILA.
  InstrLvlAbsPtr GetChild(const std::string& name) const;

  /// \brief Sanity check for the ILA (e.g. sort marching).
  /// \return True if check pass.
  bool Check() const;

  /// \brief Simplify the ILA (e.g. instructions).
  void Simplify();

  /// \brief Merge child-ILAs, including variables, simplifier, etc.
  void MergeChild();

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
  ExprPtrVec inits_;
  /// The fetch function.
  ExprPtr fetch_;
  /// The valid function.
  ExprPtr valid_;
  /// The set of instructions.
  std::vector<InstrPtr> instrs_;
  /// The name and instruction index mapping.
  std::map<Symbol, size_t> instr_idxs_;
  /// The set of child-ILAs.
  std::vector<InstrLvlAbsPtr> childs_;
  /// The name and child-ILA index mapping.
  std::map<Symbol, size_t> child_idxs_;

  /// Specification/implementation.
  bool is_spec_;
  /// To simplify expr nodes.
  bool simplify_;

  /// The simplifier for expr nodes.
  ExprMngrPtr expr_mngr_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Initialize default configuration, reset members, etc.
  void InitObject();
  /// Check instruction is complete (e.g. update sort matches).
  void CheckInstr(const InstrPtr instr);
  /// Simplify instruction if not already.
  void SimplifyInstr(const InstrPtr instr);

}; // class InstrLvlAbs

/// Pointer type for normal use of InstrLvlAbs
typedef InstrLvlAbs::InstrLvlAbsPtr InstrLvlAbsPtr;

} // namespace ila

#endif // INSTR_LVL_ABS_H__

