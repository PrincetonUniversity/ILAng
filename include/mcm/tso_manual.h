/// \file
/// Header for TSO memory model

#ifndef TSO_MANUAL_H__
#define TSO_MANUAL_H__

namespace ila {
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
  void virtual RegisterSteps(InstrVec & _inst_seq,  ZExprVec & _constr, z3::context& ctx_ );
  /// To do some extra bookkeeping work when it is known that no more instruction steps are needed.
  void virtual FinishRegisterSteps(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ );
  /// To apply the axioms, the complete program should be given
  void virtual ApplyAxioms(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ );
  // HZ note: All the step should be registered through the first function: RegisterSteps

}; // class Tso

}

#endif // TSO_MANUAL_H__
