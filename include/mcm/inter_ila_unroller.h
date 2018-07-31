/// \file
/// Header for multi-ILA unroller

#ifndef INTER_ILA_UNROLLER_H__
#define INTER_ILA_UNROLLER_H__


#include "ila/instr_lvl_abs.h"
#include "ila/z3_expr_adapter.h"
#include "verify/unroller.h"
#include "z3++.h"
#include <set>
#include <vector>
#include <list>
#include <functional>

/// \namespace ila
namespace ila {

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
  typedef z3::expr ZExpr;
  /// Type for containing a vector of z3::expr.
  typedef std::vector<ZExpr> ZExprVec;
  /// Type of vector of pointers to the ILAs involved
  typedef std::vector<InstrLvlAbsPtr> IlaPtrVec;
  /// Type of an instruction vector to represent a sequence.
  typedef std::vector<InstrPtr> InstrVec;
  /// Type of a vector of instruction sequences (currently please represent holes via 0-ary functions)
  typedef std::vector<InstrVec> ProgramTemplate;
  /// Type of unroller pointer
  typedef std::shared_ptr<Unroller> UnrollerPtr;
  /// Type of vector of unrollers /* we may use a different unroller than PathUnroll */
  typedef std::vector<UnrollerPtr>  UnrollerVec;
  /// Type of list of state variables
  typedef std::list<ExprPtr>  StateVarList;
  /// Type of map of shared states (set of names -> list of exprs)
  typedef std::map<std::string, StateVarList> SharedStatesSet;
  /// Type of memory model pointer
  typedef std::shared_ptr<MemoryModel> MemoryModelPtr;

  friend class MemoryModel;
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  InterIlaUnroller(z3::context& ctx, const IlaPtrVec & iv, MemoryModelPtr mm);
  /// Default destructor.
  virtual ~InterIlaUnroller();
  
  // ------------------------- METHODS -------------------------------------- //
  /// Add a predicate that should be asserted globally.
  void AddGlobPred(const ExprPtr p);
  /// Add a predicate that should be asserted on all steps of an ILA.
  void AddIlaPred(const ExprPtr p, InstrLvlAbsPtr i);
  /// Add a predicate that should be asserted in the initial condition.
  void AddInitPred(const ExprPtr p);
  /// Add a predicate that should be asserted when its condition is met.
  // void AddCondPred(const ExprPtr p, FuncPtr p ? what type ? );

  /// Clear the global predicates.
  void ClearGlobPred();
  /// Clear the global predicates.
  void ClearIlaPred();
  /// Clear the initial predicates.
  void ClearInitPred();
  /// Clear the step-specific predicates.
  // void ClearCondPred();

  /// \brief [Application-specific] Unroll (ordered/unordered)
  /// \param[in] iv the program template.
  virtual void Unroll(const ProgramTemplate & tmpl);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// z3::context of the unroller.
  z3::context& ctx_; 
  /// The memory model to be used with the unroller
  MemoryModelPtr mm_;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the underlying z3::context.
  inline z3::context& ctx() const { return ctx_; }

protected:
  // ------------------------- HELPERS -------------------------------------- //

  /// \brief It create a name list. There is no need to create an ExprPtr list
  ///  because their hosts are different and will generate different z3exprs.
  void FindSharedStates();
  /// \brief [Application-specific] Create unrollers (one for each ILA)
  virtual void CreateUnrollers();
  /// \brief Sanity check if the current constraints are satisfiable
  bool CurrConstrSat();
  /// \brief Conjunct (AND) all the predicates in the set.
  ZExpr ConjPred(const ZExprVec& vec) const;

  // ------------------------- MEMBERS -------------------------------------- //
  
  /// The ILAs of an SoC
  IlaPtrVec  sys_ila_;
  /// The given program template
  // ProgramTemplate prog_template_;
  /// The unrollers: one per ILA
  UnrollerVec unrollers_;
  /// Set of names of shared states
  SharedStatesSet shared_states_;

  /// The set of constraints that should be asserted.
  ZExprVec cstr_;
  /// The set of constraints that should be asserted.
  ZExprVec init_shared_vars_z3_;

}; // class InterIlaUnroller

/// \brief Class of ordered unroller (treat the template as ordered)
class InterIlaOrderedUnroller : public InterIlaUnroller {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  InterIlaOrderedUnroller(z3::context& ctx, const IlaPtrVec & iv);
  /// Default destructor.
  virtual ~InterIlaOrderedUnroller();

  // ------------------------- METHODS -------------------------------------- //
  /// \brief [Application-specific] Unroll (ordered)
  /// \param[in] iv the program template
  virtual ZExpr Unroll(const ProgramTemplate & iv);

}; // class InterIlaOrderedUnroller

/// \brief Class of ordered unroller (treat the template as unordered)
class InterIlaUnorderedUnroller : public InterIlaUnroller {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  InterIlaUnorderedUnroller(z3::context& ctx, const IlaPtrVec & iv);
  /// Default destructor.
  virtual ~InterIlaUnorderedUnroller();
  // ------------------------- METHODS -------------------------------------- //
  /// \brief [Application-specific] Unroll (unordered)
  /// \param[in] iv the program template
  virtual ZExpr Unroll(const ProgramTemplate & iv);

}; // class InterIlaUnorderedUnroller




/******************************************************************************/
// Helper Class
/******************************************************************************/


/// \brief Class to remove and restore the host info
/// This is useful as we want the ast with the same name generates
/// the same z3 expr. This framework is based on an assumption that
/// if we call z3 to create the variable of the same name multiple times
/// they refer to the same one internally.
/// FIXME: Need to check this assumption if we want to support other SMT solvers!

class HostRemoveRestore {
public:
  /// type of the internal map
  typedef std::map<ExprPtr, InstrLvlAbsPtr> ExprHostMap;

  typedef std::function<bool(const ExprPtr &)> ExprJudgeFunc;
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor: do nothing
  HostRemoveRestore() {}
  /// Default destructor: do nothing
  ~HostRemoveRestore() {}
  // ------------------------- METHODS -------------------------------------- //
  /// \brief record the host field and remove them 
  void RecordAndRemove( ExprPtr exp );
  /// \brief record the host field and remove them if allowed by the second argument
  /// This only provides more constraints in additional to RecordAndRemove 
  /// (var type, not recorded or compatible with old records)
  /// This is useful as we only need to replace the host() of shared variables
  void RecordAndRemoveIf( ExprPtr exp , ExprJudgeFunc f );
  /// \brief add back the host field according to the map
  void Restore( ExprPtr exp );
  /// \brief restore all the expr recoreded
  void RestoreAll()
private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// \brief The map of ExprPtr ==> typeof( ExprPtr->host() )
  ExprHostMap map_;
}; // class HostRemoveRestore



} // namespace ila

#endif // INTER_ILA_UNROLLER_H__

