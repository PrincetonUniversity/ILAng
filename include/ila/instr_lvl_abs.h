/// \file
/// The header for the class InstrLvlAbs.

#ifndef INSTR_LVL_ABS_H__
#define INSTR_LVL_ABS_H__

#include "ila/ast/func.h"
#include "ila/expr_fuse.h"
#include "ila/hash_ast.h"
#include "ila/instr.h"
#include "ila/object.h"
#include "ila/transition.h"
#include "util/container.h"
#include <map>
#include <memory>
#include <ostream>
#include <string>

/// \namespace ila
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
/// - the child-instruction sequencing (if not parent)
class InstrLvlAbs : public Object,
                    public std::enable_shared_from_this<InstrLvlAbs> {
public:
  /// Pointer type for normal use of InstrLvlAbs.
  typedef std::shared_ptr<InstrLvlAbs> InstrLvlAbsPtr;
  /// Type for storing a set of ExprPtr (input/state variables).
  typedef KeyVec<Symbol, ExprPtr> VarMap;
  /// Type for storing a set of Instr.
  typedef KeyVec<Symbol, InstrPtr> InstrMap;
  /// Type for storing a set of ILA (child-ILAs).
  typedef KeyVec<Symbol, InstrLvlAbsPtr> InstrLvlAbsMap;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Consturctor.
  InstrLvlAbs(const std::string& name = "", const InstrLvlAbsPtr parent = NULL);
  /// Default destructor.
  ~InstrLvlAbs();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new ILA (InstrLvlAbs) with the name. Used for hiding
  /// implementation specific type details.
  static InstrLvlAbsPtr New(const std::string& name,
                            const InstrLvlAbsPtr parent = NULL);

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return true if is InstrLvlAbs.
  bool is_instr_lvl_abs() const { return true; }

  /// Return true if is specification (not implementation).
  bool is_spec() const;
  /// Return the parent ILA.
  inline const InstrLvlAbsPtr parent() const { return parent_; }
  /// Return the ast simplifier.
  const ExprMngrPtr expr_mngr() const;

  /// Set the ILA to be specification if true.
  void set_spec(bool spec);
  /// Update the ast simplifier.
  void set_expr_mngr(const ExprMngrPtr expr_mngr);

  /// Return the number of input variables.
  size_t input_num() const;
  /// Return the number of state variables.
  size_t state_num() const;
  /// Return the number of instructions.
  size_t instr_num() const;
  /// Return the number of child-ILAs.
  size_t child_num() const;
  /// Return the number of initial condition.
  size_t init_num() const;

  /// Return the fetch function.
  const ExprPtr fetch() const;
  /// Return the valid function.
  const ExprPtr valid() const;

  /// Access the i-th input variable.
  const ExprPtr input(const size_t& i) const;
  /// Access the i-th state variable.
  const ExprPtr state(const size_t& i) const;
  /// Access the i-th instruction.
  const InstrPtr instr(const size_t& i) const;
  /// Access the i-th child-ILA.
  const InstrLvlAbsPtr child(const size_t& i) const;
  /// Access the i-th initial condition.
  const ExprPtr init(const size_t& i) const;

  /// Return the named input variable; return NULL if not registered.
  const ExprPtr input(const std::string& name) const;
  /// Return the named state variable; return NULL if not registered.
  const ExprPtr state(const std::string& name) const;
  /// Return the named instruction; return NULL if not registered.
  const InstrPtr instr(const std::string& name) const;
  /// Return the named child-ILA; return NULL if not registered.
  const InstrLvlAbsPtr child(const std::string& name) const;

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
  const ExprPtr NewBoolInput(const std::string& name);

  /// \brief Create one Bitvector variable and register as an input.
  /// \param[in] name of the bitvector input.
  /// \param[in] bit_width length of the bitvector variable.
  /// \return pointer to the input.
  const ExprPtr NewBvInput(const std::string& name, const int& bit_width);

  /// \brief Create one Boolean variable and register as a state.
  /// \param[in] name of the bool state.
  /// \return pointer to the state variable.
  const ExprPtr NewBoolState(const std::string& name);

  /// \brief Create one Bitvector variable and register as a state.
  /// \param[in] name of the bitvector state.
  /// \param[in] bit_width value bit-width.
  /// \return pointer to the state variable.
  const ExprPtr NewBvState(const std::string& name, const int& bit_width);

  /// \brief Create one Memory variable and register as a state.
  /// \param[in] name of the memory state.
  /// \param[in] addr_width address bit-width.
  /// \param[in] data_width data bit-width.
  /// \return pointer to the memory state.
  const ExprPtr NewMemState(const std::string& name, const int& addr_width,
                            const int& data_width);

  /// \brief Create and register one instruction.
  /// \param[in] name of the instruction.
  /// \return pointer to the instruction.
  const InstrPtr NewInstr(const std::string& name = "");

  /// \brief Create and register one child-ILA.
  /// \param[in] name of the child.
  /// \return pointer to the child-ILA.
  const InstrLvlAbsPtr NewChild(const std::string& name);

  /// \brief Sanity check for the ILA (e.g. sort marching).
  /// \return True if check pass.
  bool Check() const;

  /// \brief Simplify the ILA (e.g. instructions).
  void Simplify();

  /// \brief Merge child-ILAs, including variables, simplifier, etc.
  void MergeChild();

  /// \brief Sort instructions based on the sequencing, if any.
  void SortInstr();

  /// \brief Define instruction sequencing by adding a transition edge.
  /// \param[in] src source instruction
  /// \param[in] dst target instruction (destination)
  /// \param[in] cnd transition condition (guard), i.e. dst.DECODE
  void AddSeqTran(const InstrPtr src, const InstrPtr dst, const ExprPtr cnd);

  /// Output stream function.
  std::ostream& Print(std::ostream& out) const;

  /// Overload output stream for object
  friend std::ostream& operator<<(std::ostream& out, InstrLvlAbs& ila);
  /// Overload output stream for pointer
  friend std::ostream& operator<<(std::ostream& out, InstrLvlAbsPtr ila);

  friend class Instr;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Ths parent ILA.
  InstrLvlAbsPtr parent_;
  /// The set of input variables.
  VarMap inputs_;
  /// The set of state variables.
  VarMap states_;
  /// The set of initial constraints (not neccessary per-state).
  ExprPtrVec inits_;
  /// The fetch function.
  ExprPtr fetch_ = NULL;
  /// The valid function.
  ExprPtr valid_ = NULL;
  /// The set of instructions.
  InstrMap instrs_;
  /// The set of child-ILAs.
  InstrLvlAbsMap childs_;
  // child-instr sequencing
  InstrSeq instr_seq_;

  /// Specification/implementation.
  bool is_spec_ = true;

  /// The simplifier for expr nodes. May be shared.
  ExprMngrPtr expr_mngr_ = NULL;

  // ------------------------- HELPERS -------------------------------------- //
  /// Simplify AST nodes with the representatives.
  ExprPtr Unify(const ExprPtr e);
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

