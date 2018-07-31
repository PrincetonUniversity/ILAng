/// \file
/// Source for the base class of TSO memory model
/// This is only an example of what the axiom parser should generate

#include "mcm/memory_model.h"
#include "mcm/tso_manual.h"
#include "mcm/set_op.h"

namespace ila {

/******************************************************************************/
// TsoTraceStep
/******************************************************************************/

TsoTraceStep::TsoTraceStep(const InstrPtr & inst , ZExprVec & cstr , z3::context& ctx )
: TraceStep( inst, cstr, ctx )
{ }

/******************************************************************************/
// Tso
/******************************************************************************/


void Tso::RegisterSteps(InstrVec & _inst_seq,  ZExprVec & _constr, z3::context& ctx_ )
{
  for (auto && instr_ptr_ : _inst_seq) {
    // this is the same for all instructions
    auto inst_trace_step = std::make_shared<TsoTraceStep>(instr_ptr_ , cstr, ctx);

    // 1 - bookkeeping
    _all_trace_steps.push_back( inst_trace_step );
    _all_inst_trace_steps.push_back( inst_trace_step );

    // InstructionSet WRITE
    if ( inst_trace_step->Access( AccessType::WRITE , m_p_shared_states ) ) {
      WRITE.add( inst_trace_step );
    // now the facet event
      {
        auto _facet_trace_step = std::make_shared<TraceStep>(instr_ptr_ , cstr, ctx , "wfe.global");
        inst_trace_step->wfe_global = _facet_trace_step;
        _all_trace_steps.push_back( _facet_trace_step  );

        // a set of all states
        // a set of all shared states
        // add when needed, and then add the rest if required
        const StateNameSet & read_set_  = inst_trace_step->get_inst_read_set();
        const StateNameSet & write_set_ = inst_trace_step->get_inst_write_set();
        StateNameSet global_read_set_;
        StateNameSet global_write_set_;
        INTERSECT(read_set_, m_shared_state_names,  global_read_set_);
        INTERSECT(write_set_, m_shared_state_names, global_write_set_);

        // _facet_trace_step->AddStateAccess( "" , AccessType::WRITE );
        // global_write_set_.erase( "" );

        _facet_trace_step->AddStateAccess( global_write_set_ , AccessType::WRITE );
      }
    }

    // InstructionSet READ
    if ( inst_trace_step->Access( AccessType::READ , m_p_shared_states ) ) {
      READ.add( inst_trace_step );
    }

    // InstructionSet FENCE
    if ( instr_ptr_->name() == "fence" || 
         instr_ptr_->name() == "Fence" ||
         instr_ptr_->name() == "FENCE" ) {
      FENCE.add( inst_trace_step );
    }

    // InstructionSet RMW
    if ( instr_ptr_->name() == "atomic_add" || 
         instr_ptr_->name() == "atomic_and" ) {
      RMW.add( inst_trace_step );
    }

  }
}


void Tso::FinishRegisterSteps(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ )
{
  DIFFERENCE(WRITE, RMW, PureWrite);
}

// Note: Same Address and Same Data
// should handle memory things
// you may want to do small static tests
// to make smaller constraints

// In order mode: local resolve is possible, only shared state access will be translated
//                to pi-function
// Out-of-order mode: all state read will be translated to pi-function?
// 
// * maybe we need to apply a certain check?


void Tso::ApplyAxioms(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ )
{
  // Axiom RF_CO_FR

  // Axiom TSO_WriteFacetOrder
  ZExprVec _L1;
  for( auto && w : PureWrite ) {
    ZExpr var1 = HB( w, __wfe_global(w) )
    _L1.push_back(  );
  }
  _constr.push_back( Z3ForallList(_L1) );
  // Axiom TSO_Store



}

void Tso::SetLocalState(std::set<bool> ordered, ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ )
{

}

}