/// \file
/// Header for SC memory model (constructed manually, rather than fully
/// automaticated generation)

#ifndef ILANG_MCM_SC_MANUAL_H__
#define ILANG_MCM_SC_MANUAL_H__

#include <ilang/mcm/inter_ila_unroller.h>
#include <ilang/mcm/memory_model.h>

namespace ilang {

/// \brief Class of TSO trace step
class ScTraceStep : public TraceStep {
public:
  /// Type of trace step pointer
  typedef std::shared_ptr<TraceStep> TraceStepPtr;
  // ------------------------- MEMBERS -------------------------------------- //
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// To create a trace step (for inst, we don't need it for facet/init)
  ScTraceStep(const InstrPtr& inst, ZExprVec& cstr, z3::context& ctx,
              size_t pos);
}; // class ScTraceStep

/// \brief Class of TSO
class Sc : public MemoryModel {
public:
  /// Type of trace step pointer
  typedef std::shared_ptr<ScTraceStep> ScTraceStepPtr;
  /// Type of trace steps, we need to collect the set of trace steps (WRITE)
  typedef std::set<ScTraceStepPtr> ScTraceStepPtrSet;
  // -------------------------- TSO SELECTOR
  // -------------------------------------- //
  /// \brief Declaration of memory model creator that chooses Sc
  static InterIlaUnroller::MemoryModelCreator ScModel;

protected:
  TraceStepPtrSet WRITE_list;
  TraceStepPtrSet READ_list;

public:
  /// To create more view operations associated with an instruction, and also to
  /// add them to the set
  void virtual RegisterSteps(size_t regIdx, const InstrVec& _inst_seq) override;
  /// To do some extra bookkeeping work when it is known that no more
  /// instruction steps are needed.
  void virtual FinishRegisterSteps() override;
  /// To apply the axioms, the complete program should be given
  void virtual ApplyAxioms() override;
  // HZ note: All the step should be registered through the first function:
  // RegisterSteps
  /// Set the final property, this is implementation-specific
  void virtual SetFinalProperty(const ExprPtr& property) override;
  /// Constructor
  Sc(z3::context& ctx, ZExprVec& _cstrlist, const StateNameSet& shared_states,
     const ILANameStateNameSetMap& private_states,
     const InstrLvlAbsPtr& global_ila_ptr)
      : MemoryModel(ctx, _cstrlist, shared_states, private_states,
                    global_ila_ptr) {}

private:
  z3::expr RF(const TraceStepPtr& w, const TraceStepPtr& r);
  z3::expr FR(const TraceStepPtr& r, const TraceStepPtr& w);
  z3::expr CO(const TraceStepPtr& w1, const TraceStepPtr& w2);

}; // class Sc

} // namespace ilang

#endif // ILANG_MCM_SC_MANUAL_H__
