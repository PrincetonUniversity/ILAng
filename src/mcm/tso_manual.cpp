/// \file
/// Source for the base class of TSO memory model
/// This is only an example of what the axiom parser should generate

#include "mcm/memory_model.h"
#include "mcm/tso_manual.h"

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
#define INTERSECT(a,b,r) (std::set_intersection( (a).begin(),(a).end(), (b).begin(), (b).end(), std::back_inserter(r) ))

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
      
    }
    // InstructionSet FENCE
    // InstructionSet RMW
    // InstructionSet PureWrite


  }
}
void Tso::ApplyAxioms(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ )
{

}

}