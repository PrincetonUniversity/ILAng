/// \file
/// Header for TSO memory model

#ifndef TSO_MANUAL_H__
#define TSO_MANUAL_H__

namespace ila {

/// \brief Class of TSO trace step
class TsoTraceStep : public TraceStep {
  /// Type of trace step pointer
  typedef std::shared_ptr<TraceStep> TraceStepPtr;
public:
  // ------------------------- MEMBERS -------------------------------------- //
  TraceStepPtr wfe_global; // maybe we should get away from raw pointer?
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// To create a trace step
  TsoTraceStep(const InstrPtr & inst , ZExprVec & cstr , z3::context& ctx );
}; // class TsoTraceStep

/// \brief Class of TSO
class Tso : public MemoryModel {
  /// Type of trace step pointer
  typedef std::shared_ptr<TsoTraceStep> TsoTraceStepPtr;
  /// Type of trace steps, we need to collect the set of trace steps (WRITE)
  typedef std::set<TsoTraceStepPtr> TsoTraceStepSet;

  TraceStepSet WRITE_list;
  TraceStepSet READ_list;
  TraceStepSet FENCE_list;
  TraceStepSet RMW_list;
  TraceStepSet PureWrite_list;

public:
  /// To create more view operations associated with an instruction, and also to add them to the set
  void virtual RegisterSteps(size_t regIdx , InstrVec & _inst_seq);
  /// To do some extra bookkeeping work when it is known that no more instruction steps are needed.
  void virtual FinishRegisterSteps();
  /// To apply the axioms, the complete program should be given
  void virtual ApplyAxioms();
  // HZ note: All the step should be registered through the first function: RegisterSteps
  /// Constructor
  Tso(z3::context& ctx, 
    ZExprVec & _cstrlist, 
    const StateNameSet & shared_states, 
    const ILANameStateNameSetMap & private_states, 
    const InstrLvlAbsPtr & global_ila_ptr) :
   MemoryModel(ctx, _cstrlist, shared_states, private_states, global_ila_ptr) { }

private:
  z3::expr RF( TraceStep &w,TraceStep &r);
  z3::expr FR( TraceStep &r,TraceStep &w);
  z3::expr CO( TraceStep &w1,TraceStep &w2);

}; // class Tso


// ------------------------- ACCESSOR FUNCTIONs -------------------------------------- //
/// \brief DOT wfe DOT global
TraceStep & __wfe_global(TraceStep & ts);

}

#endif // TSO_MANUAL_H__
