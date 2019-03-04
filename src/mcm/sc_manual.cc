/// \file
/// Source for the base class of SC memory model
/// This is only an example of what the axiom parser should generate

#include "ilang/mcm/sc_manual.h"
#include "ilang/mcm/inter_ila_unroller.h"
#include "ilang/mcm/memory_model.h"
#include "ilang/mcm/set_op.h"
#include <ilang/util/z3_helper.h>
#include <memory>
#include <set>
#include <string>

namespace ilang {

/******************************************************************************/
// ScTraceStep
/******************************************************************************/

ScTraceStep::ScTraceStep(const InstrPtr& inst, ZExprVec& cstr, z3::context& ctx,
                         size_t pos)
    : TraceStep(inst, cstr, ctx, pos) {}

/******************************************************************************/
// Sc
/******************************************************************************/

void Sc::RegisterSteps(size_t regIdx, const InstrVec& _inst_seq) {
  size_t pos = 1; // start from 1, same as unroller.cpp

  for (auto&& instr_ptr_ : _inst_seq) {
    // this is the same for all instructions
    auto inst_trace_step_ptr =
        std::make_shared<ScTraceStep>(instr_ptr_, _constr, _ctx_, pos);

    // 1 - bookkeeping
    _all_trace_steps.insert(inst_trace_step_ptr);
    _all_inst_trace_steps.insert(inst_trace_step_ptr);
    _ila_trace_steps[regIdx][pos - 1] = inst_trace_step_ptr;

    // InstructionSet WRITE
    if (inst_trace_step_ptr->Access(AccessType::WRITE, m_shared_state_names)) {
      WRITE_list.insert(inst_trace_step_ptr);
      // no facet event
    }

    // InstructionSet READ
    if (inst_trace_step_ptr->Access(AccessType::READ, m_shared_state_names)) {
      READ_list.insert(inst_trace_step_ptr);
      // no facet event
    }

    ++pos;
  }
}

void Sc::FinishRegisterSteps() {
  // eventually, we need to deal with the init trace
  auto init_trace_step_ptr = CreateGlobalInitStep();
  // 1. Bookkeeping
  _all_trace_steps.insert(init_trace_step_ptr);
  _all_inst_trace_steps.insert(init_trace_step_ptr);
  // InstructionSet WRITE
  if (init_trace_step_ptr->Access(AccessType::WRITE, m_shared_state_names))
    WRITE_list.insert(init_trace_step_ptr);
  // InstructionSet READ - skip, they should not read from any other trace
  // steps, if there are, make it arbitrary
}

void Sc::SetFinalProperty(const ExprPtr& property) {
  auto final_property_step_ptr = CreateGlobalFinalStep(property);

  for (auto&& ts : _all_inst_trace_steps)
    _constr.push_back(HB(*ts, *final_property_step_ptr));
  // Bookkeeping
  // _all_inst_trace_steps.insert( final_property_step_ptr );
  // InstructionSet WRITE - skip
  // InstructionSet Read
  if (final_property_step_ptr->Access(AccessType::READ, m_shared_state_names))
    READ_list.insert(final_property_step_ptr);
  // InstructionSet FENCE - skip, name is not FENCE
  // InstructionSet RMW - skip, name not matched

  _constr.push_back(final_property_step_ptr->ConvertZ3OnThisStep(property));
  // This will use the old one
}

// Note: Same Address and Same Data
// should handle memory things
// you may want to do small static tests
// to make smaller constraints

// In order mode: local resolving is possible, only shared state access will be
// translated
//                to pi-function
// Out-of-order mode: all state read will be translated to pi-function? Yes
//
// * maybe we need to apply a certain check?

// SameAddress & Decode & SameCore have their ``static'' form

void Sc::ApplyAxioms() {
  // ----- AXIOM RF_CO_FR BEGIN -----
  ZExprVec var10_L;
  for (auto&& s : m_shared_state_names) { // forall s : m_shared_state_names
    ZExprVec var8_L;
    for (auto&& r : READ_list) { // forall r : READ_list
      if (!r->Access(AccessType::READ, s))
        continue;
      ZExprVec var6_L;
      for (auto&& w : WRITE_list) { // exists w : WRITE_list
        if (w->name() == r->name())
          continue;
        if (!w->Access(AccessType::WRITE, s))
          continue;
        ZExprVec var4_L;
        for (auto&& w2 : WRITE_list) { // forall w2 : WRITE_list
          if (w2->name() == w->name())
            continue;
          if (w2->name() == r->name())
            continue;
          if (!w2->Access(AccessType::WRITE, s))
            continue;
          ZExpr var3 = Z3Implies(
              _ctx_, _ctx_.bool_val(true),
              Z3Implies(_ctx_,
                        ((SameAddress(*r, *w2, s, AxiomFuncHint::HINT_READ,
                                      AxiomFuncHint::HINT_WRITE) &&
                          Decode(*w2))),
                        (CO(w2, w) || FR(r, w2))));
          var4_L.push_back(var3);
        }
        ZExpr var5 = Z3ForallList(var4_L);
        ZExpr var2 = Z3And(_ctx_.bool_val(true),
                           ((((SameAddress(*w, *r, s, AxiomFuncHint::HINT_WRITE,
                                           AxiomFuncHint::HINT_READ) &&
                               SameData(*w, *r, s, AxiomFuncHint::HINT_WRITE,
                                        AxiomFuncHint::HINT_READ)) &&
                              Decode(*w)) &&
                             RF(w, r)) &&
                            (var5)));
        var6_L.push_back(var2);
      }
      ZExpr var7 = Z3ExistsList(var6_L);
      ZExpr var1 = Z3Implies(_ctx_, _ctx_.bool_val(true), var7);
      var8_L.push_back(var1);
    }
    ZExpr var9 = Z3ForallList(var8_L);
    var10_L.push_back(var9);
  }
  ZExpr var11 = Z3ForallList(var10_L);
  _constr.push_back(var11);
  // ----- AXIOM RF_CO_FR END ----
}

// ------------------- Functions ----------------------
z3::expr Sc::RF(const TraceStepPtr& w, const TraceStepPtr& r) {
  return HB(*w, *r);
}

z3::expr Sc::FR(const TraceStepPtr& r, const TraceStepPtr& w) {
  return HB(*r, *w);
}
z3::expr Sc::CO(const TraceStepPtr& w1, const TraceStepPtr& w2) {
  return HB(*w1, *w2);
}

// -------------------------- SC SELECTOR --------------------------------------
// // because we assume C++11 (make_unique is available since C++14)
/*
template<typename T, typename... Args>
std::unique_ptr<T> mm_make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
*/

// -------------------------- SC SELECTOR --------------------------------------
// //
/// \brief Declaration of memory model creator that chooses Sc
InterIlaUnroller::MemoryModelCreator Sc::ScModel =
    [](z3::context& ctx,                             // z3 context
       ZExprVec& _cstrlist,                          // constrain list
       const StateNameSet& shared_states,            // shared state
       const ILANameStateNameSetMap& private_states, // private state
       const InstrLvlAbsPtr& global_ila_ptr) {
      return std::unique_ptr<Sc>(new Sc(ctx, _cstrlist, shared_states,
                                        private_states, global_ila_ptr));
      // mm_make_unique<Sc>( ctx, _cstrlist, shared_states, private_states,
      // global_ila_ptr );
    };

} // namespace ilang
