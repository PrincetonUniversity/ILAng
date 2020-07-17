/// \file
/// Header for multi-ILA unroller

#ifndef ILANG_MCM_INTER_ILA_UNROLLER_H__
#define ILANG_MCM_INTER_ILA_UNROLLER_H__

#include <functional>
#include <list>
#include <set>
#include <stack>
#include <vector>

#include <z3++.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/mcm/memory_model.h>

/// \namespace ilang
namespace ilang {

class MemoryModel;

/// \brief Base class for unrolling multiple ILAs.
/// There are two ways of unrolling: ordered and unordered.
/// Ordered unrolling assumes an ordered program template,
/// despite that some may not exist in the final outcome.
/// By default the state with the same name among ILAs is
/// considered as the same shared state.
class InterIlaUnroller {
public:
  /// Type alias for z3::expr.
  using ZExpr = MemoryModel::ZExpr;
  /// Type for containing a vector of z3::expr.
  using ZExprVec = MemoryModel::ZExprVec;
  /// Type of state name set
  using StateNameSet = MemoryModel::StateNameSet;
  /// Type of an instruction vector to represent a sequence.
  using InstrVec = MemoryModel::InstrVec;
  /// Type of a vector of instruction sequences (currently please represent
  /// holes via 0-ary functions)
  using ProgramTemplate = MemoryModel::ProgramTemplate;
  /// Type of map ila-name to state-set
  using ILANameStateNameSetMap = MemoryModel::ILANameStateNameSetMap;
  /// Type of set of trace step pointers (DEBUG use)
  using TraceStepPtrSet = MemoryModel::TraceStepPtrSet;
  /// Type of vector of pointers to the ILAs involved
  typedef std::vector<InstrLvlAbsPtr> IlaPtrVec;
  /// Type of list of state variables
  typedef std::list<ExprPtr> StateVarList;
  /// Type of map of shared states (set of names -> list of exprs)
  typedef std::map<std::string, StateVarList> SharedStatesSet;
  /// Type of memory model pointer, we enforce ownership strictly, so it cannot
  /// be used else where
  typedef std::unique_ptr<MemoryModel> MemoryModelPtr;
  /// Type of memory model creator, nees to be the same as the ctor of
  /// MemoryModelClass
  typedef std::function<MemoryModelPtr(
      z3::context&,                  // z3 context
      ZExprVec&,                     // constrain list
      const StateNameSet&,           // shared state
      const ILANameStateNameSetMap&, // private state
      const InstrLvlAbsPtr&          // dummy global ila pointer
      )>
      MemoryModelCreator;
  /// Type of trace step pointer
  typedef std::shared_ptr<TraceStep> TraceStepPtr;

  friend class MemoryModel;
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor. mm_selector is used to create mm internally
  InterIlaUnroller(z3::context& ctx, const IlaPtrVec& iv,
                   MemoryModelCreator mm_selector);
  /// Default destructor.
  virtual ~InterIlaUnroller();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief it generates the initial constraints and put them on to the
  /// constraint list and check should be called before unroll
  void GenSysInitConstraints();

  /// \brief [Application-specific] Unroll, currently just use PathUnroller
  /// \param[in] the program template.
  virtual void Unroll(const ProgramTemplate& tmpl);

  /// \brief [Application-specific] Link states, where each trace step read from
  /// \param[in] whether each template should be treated as ordered or unordered
  virtual void LinkStates(const std::vector<bool>& ordered);

  /// \brief Add a property
  /// \param[in] a property that is going to translated to Z3, note: the state
  /// are treated as prestate \param[in] a filter to choose which trace step to
  /// enforce
  void AddSingleTraceStepProperty(const ExprPtr& property,
                                  std::function<bool(const TraceStep&)> filter);

  /// \brief Get the z3 expression of a property on a trace step, so you can
  /// play with it \param[in] a property that is going to translated to Z3,
  /// note: the state are treated as prestate \param[in] a filter to choose
  /// which trace step to enforce \param[in] a collector (callback function) to
  /// do something as each time a property is created on a step
  void
  GetSingleTraceStepProperty(const ExprPtr& property,
                             std::function<bool(const TraceStep&)> filter,
                             std::function<void(const z3::expr&)> collector);

  /// \brief Set final property (you should only call this function only ONCE)
  /// \param[in] the property
  void SetFinalProperty(const ExprPtr& property);

  /// \brief Check and potentially set the model: return true if sat , false
  /// o.w.
  bool CheckSat();
  /// \brief Get the model: the reference will only be usable if unroller is not
  /// destroyed
  z3::model& GetModel();
  /// \brief Get access to expr vector, will only be usable if unroller is not
  /// destroyed, only for DEBUG use
  const ZExprVec& DebugAccessConstrList() const;
  /// \brief Get access to expr vector, will only be usable if unroller is not
  /// destroyed, only for DEBUG use
  const TraceStepPtrSet& DebugAccessAllTraceStepPtrSet() const;

  /// \brief Push the size of current set of constraints
  void Push();
  /// \brief Restore the previous set of constraints
  void Pop();

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// z3::context of the unroller.
  z3::context& ctx_;
  /// The memory model to be used with the unroller
  MemoryModelPtr mm_;
  /// The model of the
  std::unique_ptr<z3::model>
      model_ptr_; // should not shared with any one, you need to assume it will
                  // destroy along with the unroller
  /// A stack to hold the position of the stack
  std::stack<size_t> zexpr_vec_pos_stack_;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the underlying z3::context.
  inline z3::context& ctx() const { return ctx_; }
  /// Create a dummy global ila
  void createDummyGlobalIla();

protected:
  // ------------------------- HELPERS -------------------------------------- //
  /// \brief It create a name list. There is no need to create an ExprPtr list
  ///  because their hosts are different and will generate different z3exprs.
  void FindSharedStates();
  /// \brief Sanity check if the current constraints are satisfiable
  bool CurrConstrSat();
  /// \brief Conjunct (AND) all the predicates in the set.
  ZExpr ConjPred(const ZExprVec& vec) const;

  // ------------------------- MEMBERS -------------------------------------- //

  /// The ILAs of an SoC
  IlaPtrVec sys_ila_;
  /// The ILA of the system
  InstrLvlAbsPtr global_ila_;

  /// Set of names of shared states
  StateNameSet shared_states_;
  /// Map from ila-name to set-of-state-names
  ILANameStateNameSetMap private_states_;

  /// The set of constraints that should be asserted.
  ZExprVec cstr_;
  /// The set of constraints that should be asserted.
  ZExprVec init_shared_vars_z3_;

}; // class InterIlaUnroller

/******************************************************************************/
// Helper Class
/******************************************************************************/

/// \brief Class to remove and restore the host info
/// This is useful as we want the ast with the same name generates
/// the same z3 expr. This framework is based on an assumption that
/// if we call z3 to create the variable of the same name multiple times
/// they refer to the same one internally.
/// FIXME: Need to check this assumption if we want to support other SMT
/// solvers!

class HostRemoveRestore {
public:
  /// type of the internal map
  typedef std::map<ExprPtr, InstrLvlAbsPtr> ExprHostMap;
  /// type of function object from to decide if we should remove the host of a
  /// expr or not
  typedef std::function<bool(const ExprPtr&)> ExprJudgeFunc;
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor: do nothing
  HostRemoveRestore() {}
  /// Default destructor: do nothing
  ~HostRemoveRestore() {}
  // ------------------------- METHODS -------------------------------------- //
  /// \brief record the host field and remove them
  void RecordAndRemove(ExprPtr exp);
  /// \brief record the host field and remove them if allowed by the second
  /// argument This only provides more constraints in additional to
  /// RecordAndRemove (var type, not recorded or compatible with old records)
  /// This is useful as we only need to replace the host() of shared variables
  void RecordAndRemoveIf(ExprPtr exp, ExprJudgeFunc f);
  void RecordAndReplaceIf(ExprPtr exp, ExprJudgeFunc f, InstrLvlAbsPtr h);
  /// \brief add back the host field according to the map
  void Restore(ExprPtr exp);
  /// \brief restore all the expr recoreded
  void RestoreAll(InstrLvlAbsPtr h = nullptr);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// \brief The map of ExprPtr ==> typeof( ExprPtr->host() )
  ExprHostMap map_;
}; // class HostRemoveRestore

} // namespace ilang

#endif // ILANG_MCM_INTER_ILA_UNROLLER_H__
