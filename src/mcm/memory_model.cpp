/// \file
/// Source for the base class of memory model

#include <string>
#include "mcm/memory_model.h"
#include "mcm/set_op.h"

namespace ila {

/******************************************************************************/
// TraceStep
/******************************************************************************/

  // counter init
  unsigned TraceStep::trace_step_seq_no = 0;

  std::string TraceStep::GetName()
  {
    ++ trace_step_seq_no; // not thread-safe, but we are not building multi-threaded program anyway
    return _inst->name() + "_ts" + std::to_string(trace_step_seq_no);
  }

  void TraceStep::InitReadWriteSet( const InstrPtr & inst  )  // this can be the inst/parent inst
  {
      VarUseFinder<std::string, ExprPtr2Name> use_finder_;
      use_finder_.Traverse( inst , _inst_read_set );
      inst->GetUpdatedStates(_inst_write_set);
  }

  TraceStep::TraceStep(const InstrPtr & inst , ZExprVec & cstr, z3::context& ctx , size_t pos , const Z3ExprAdapterPtr & z3a  ) :
    _type(TraceStepType::INST_EVT), _inst(inst), _cstr(cstr), _name( GetName() ), timestamp( ctx.int_const( _name.c_str() ) ),
    _pos_suffix(pos) , _expr2z3_ptr_(z3a) , _ctx_(ctx)
    {
      InitReadWriteSet(inst);
      _cstr.push_back( timestamp > 0 ); // if it is not overwritten, then we will set this constraint
    }

  TraceStep::TraceStep(const InstrPtr & inst , ZExprVec & cstr, z3::context& ctx , Z3Expr ts_overwrite ,  size_t pos , const Z3ExprAdapterPtr & z3a) :
    _type(TraceStepType::INST_EVT), _inst(inst), _cstr(cstr), _name( GetName() ), timestamp( ts_overwrite ) ,
    _pos_suffix(pos) , _expr2z3_ptr_(z3a) , _ctx_(ctx)
    { InitReadWriteSet(inst); }


  /// To create a facet event , the last parameter is actually not in use now
  TraceStep::TraceStep(const InstrPtr & ref_inst, ZExprVec & cstr , z3::context& ctx, const std::string & s,  size_t pos , const Z3ExprAdapterPtr & z3a) :
    _type(TraceStepType::FACET_EVT), _parent_inst(ref_inst), _cstr(cstr), _name( GetName() + "_fevt" ), timestamp( ctx.int_const( _name.c_str() ) ) ,
    _pos_suffix(pos) , _expr2z3_ptr_(z3a) , _ctx_(ctx)
    { 
      InitReadWriteSet(_parent_inst); 
      _cstr.push_back( timestamp > 0 ); // For inst event and facet events
    }

  /// To update the set for TraceStepType::FACET_EVT
  void TraceStep::AddStateAccess(const std::string & name, AccessType acc_type)
  {
    ILA_ASSERT( _type == TraceStepType::FACET_EVT ) << "Cannot change the state access info of instruction trace step: "<< _name ;
    switch(acc_type) {
      case AccessType::WRITE: 
        ILA_ASSERT( IN(name, _inst_write_set) ) << "Facet event cannot update state: " << name << " that is not written by the instruction";
        _write_state_set.insert(name);
        break;
      case AccessType::READ: 
        ILA_ASSERT( IN(name, _inst_read_set) ) << "Facet event cannot read state: " << name << " that is not used by the instruction";
        _read_state_set.insert(name);
        break;
      default: ILA_ASSERT( false ) << "Access type of state: " << name << " is neither READ nor WRITE";
    }
  }
  void TraceStep::AddStateAccess(const StateNameSet &s, AccessType acc_type)
  {
    ILA_ASSERT( _type == TraceStepType::FACET_EVT ) << "Cannot change the state access info of instruction trace step: "<< _name ;
    switch(acc_type) {
      case AccessType::WRITE: 
        for (auto & name : s) {
          ILA_ASSERT( IN(name, _inst_write_set) ) << "Facet event cannot update state: " << name << " that is not written by the instruction";
          _write_state_set.insert(name);
        }        
        break;
      case AccessType::READ: 
        for (auto & name : s) {
          ILA_ASSERT( IN(name, _inst_read_set) ) << "Facet event cannot read state: " << name << " that is not used by the instruction";
          _read_state_set.insert(name);
        }  
        break;
      default: ILA_ASSERT( false ) << "Access type of state: " << name << " is neither READ nor WRITE";
    }

  }

  bool TraceStep::Access( AccessType acc_type , const std::string & name) {
    ILA_ASSERT( _type == TraceStepType::INST_EVT ) << "Not implemented for facet event";
    ILA_ASSERT( acc_type == AccessType::READ || acc_type == AccessType::WRITE ) << "Access type must be READ or WRITE";

    StateNameSet & access_set ( acc_type == AccessType::READ ?  _inst_read_set : _inst_write_set);
    return IN(name, access_set) ;
  }


  bool TraceStep::Access( AccessType acc_type , SharedStatesSet * m_p_shared_states ) {
    ILA_ASSERT( m_p_shared_states ) << "Implementation bug: the shared state pointer is not set";
    ILA_ASSERT( _type == TraceStepType::INST_EVT ) << "Not implemented for facet event";
    ILA_ASSERT( acc_type == AccessType::READ || acc_type == AccessType::WRITE ) << "Access type must be READ or WRITE";
    
    StateNameSet & access_set ( acc_type == AccessType::READ ?  _inst_read_set : _inst_write_set);

    for(auto && _s_n : access_set) {
      if ( In_p(_s_n , m_p_shared_states) )
        return true;
    }
    return false;
  }

/******************************************************************************/
// MemoryModel
/******************************************************************************/

  bool MemoryModel::AccessShared ( const InstrPtr & ip, AccessType acc_type )
  {

    ILA_ASSERT(m_p_shared_states) << "Implementation bug: the shared state pointer is not set";

    StateNameSet access_set;
    if (acc_type == AccessType::READ) {
      VarUseFinder<std::string, ExprPtr2Name> use_finder_;
      use_finder_.Traverse( ip , access_set );
    } else if (acc_type == AccessType::WRITE) {
      ip->GetUpdatedStates(access_set);
    }
    else
      ILA_ASSERT(false) << "Access type of querying instruction: "<< ip->name() << " is neither READ or WRITE";

    for(auto && _s_n : access_set) {
      if ( In_p(_s_n , m_p_shared_states) )
        return true;
    }
    return false;
  }
  void MemoryModel::SetSharedStates(SharedStatesSet * p)
  { 
    ILA_ASSERT(m_p_shared_states == NULL) << "Implementation bug: overwriting the shared state pointer";
    m_p_shared_states = p;
    for( auto && n_l_pair : *m_p_shared_states ) {
      m_shared_state_names.insert(n_l_pair.first);
    }    
  }


} // namespace ila