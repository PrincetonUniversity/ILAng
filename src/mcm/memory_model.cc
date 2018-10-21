/// \file
/// Source for the base class of memory model

#include <string>
#include "mcm/inter_ila_unroller.h"
#include "mcm/memory_model.h"
#include "mcm/set_op.h"
#include "util/log.h"

namespace ila {

/******************************************************************************/
// TraceStep
/******************************************************************************/

  // counter init
  unsigned TraceStep::trace_step_seq_no = 0;

  std::string TraceStep::GetName()
  {
    ++ trace_step_seq_no; // not thread-safe, but we are not building multi-threaded program anyway
    return _inst->name().str() + "_ts" + std::to_string(trace_step_seq_no);
  }

  // a small helper function
  std::string ExprPtr2Name(const ExprPtr & e) {
      return e->name().str();
  }

  void TraceStep::InitReadWriteSet( const InstrPtr & inst  )  // this can be the inst/parent inst
  {
      VarUseFinder<std::string> use_finder_(ExprPtr2Name);
      use_finder_.Traverse( inst , _inst_read_set );
      inst->GetUpdatedStates(_inst_write_set);
  }

 // constructor of an instruction trace step
  TraceStep::TraceStep(const InstrPtr & inst , ZExprVec & cstr, z3::context& ctx , size_t pos , const Z3ExprAdapterPtr & z3a  ) :
    _type(TraceStepType::INST_EVT), _inst(inst), _cstr(cstr), _name( GetName() ), timestamp( ctx.int_const( _name.c_str() ) ),
    _pos_suffix(pos) , _expr2z3_ptr_(z3a) , _ctx_(ctx)
    {
      InitReadWriteSet(inst);
      _cstr.push_back( timestamp > 0 ); // if it is not overwritten, then we will set this constraint
    }

  // constructor for overwritten timesamp
  // usually, only the init trace step does this
  TraceStep::TraceStep(const InstrPtr & inst , ZExprVec & cstr, z3::context& ctx , ZExpr ts_overwrite ,  size_t pos , const Z3ExprAdapterPtr & z3a) :
    _type(TraceStepType::INIT_EVT), _inst(inst), _cstr(cstr), _name( GetName() ), timestamp( ts_overwrite ) ,
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
      default: ILA_ASSERT( false ) << "Access type has to be READ / WRITE";
    }

  }

  bool TraceStep::Access( AccessType acc_type , const std::string & name) const {
    ILA_ASSERT( _type == TraceStepType::INST_EVT || _type == TraceStepType::INIT_EVT ) << "Not implemented for facet event";
    switch(acc_type) {
      case AccessType::READ : return IN(name,_inst_read_set);
      case AccessType::WRITE: return IN(name,_inst_write_set);
      case AccessType::EITHER: return IN(name,_inst_read_set) || IN(name,_inst_write_set);
      default:
        ILA_ASSERT(false)  << "Access type must be READ or WRITE or EITHER";
        return false;
    }
  }


  bool TraceStep::Access( AccessType acc_type , const StateNameSet & stateset ) const {
    ILA_ASSERT( _type == TraceStepType::INST_EVT || _type == TraceStepType::INIT_EVT ) << "Not implemented for facet event";
    ILA_ASSERT( acc_type == AccessType::READ || acc_type == AccessType::WRITE || acc_type == AccessType::EITHER  ) << "Access type must be READ or WRITE or EITHER";
    
    if(  acc_type == AccessType::READ ||  acc_type == AccessType::EITHER )
      for(auto && _s_n : _inst_read_set) 
        if ( IN(_s_n , stateset) )
          return true;
    if(  acc_type == AccessType::WRITE ||  acc_type == AccessType::EITHER )
      for(auto && _s_n : _inst_write_set) 
        if ( IN(_s_n , stateset) )
          return true;
    return false;
  }

/******************************************************************************/
// MemoryModel
/******************************************************************************/

  MemoryModel::MemoryModel(z3::context& ctx, 
    ZExprVec & _cstrlist, 
    const StateNameSet & shared_states, 
    const ILANameStateNameSetMap & private_states, 
    const InstrLvlAbsPtr & global_ila_ptr)
    : 
      m_shared_state_names(shared_states), 
      m_ila_private_state_names(private_states),
      m_p_global_ila(global_ila_ptr), 
      _ctx_(ctx) , _constr(_cstrlist), nested_finder_(), 
      mem_load_expr_finder_( nested_finder_ ) 
  {
    _expr2z3_ptr_ = std::make_shared<Z3ExprAdapter>(_ctx_); 
  }

  /*
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
      if ( IN_p(_s_n , m_p_shared_states) )
        return true;
    }
    return false;
  }
  */

  MemoryModel::TraceStepPtr MemoryModel::CreateGlobalInitStep()
  // called by specific memory model
  {
    _init_trace_step = std::make_shared<TraceStep>( 
      m_p_global_ila->instr("__INIT__"), // const InstrPtr & inst ,
      _constr, // ZExprVec & cstr,
      _ctx_,   // z3::context& ctx,
      _ctx_.int_val(0), // Z3Expr _ts_overwrite , init trace step starts from 0
      0, // size_t pos,
      _expr2z3_ptr_ // Z3AdapaterPtr
      );
    // but you need to check if it writes some states
    // and this check should be done according to the MCM axioms.
    return _init_trace_step;
  }

  void MemoryModel::InitSize(const ProgramTemplate & _tmpl)
  {
    _ila_trace_steps.resize( _tmpl.size() );
    for (size_t idx = 0 ; idx != _tmpl.size() ; ++idx ) {
      _ila_trace_steps[idx].resize( _tmpl[idx].size() );
    }
  }

  void MemoryModel::SetLocalState(const std::vector<bool> & ordered)
  // link local states
  {
     for(size_t idx = 0; idx != _ila_trace_steps.size(); ++ idx) {
       std::vector<TraceStepPtr> & ts_seq = _ila_trace_steps[idx];       
       bool is_ordered = ordered[idx];
       InstrLvlAbsPtr ila_ptr = ts_seq[0]->host();
       const std::string & ila_name = ila_ptr->name().str();
       auto pos = m_ila_private_state_names.find(ila_name);
       ILA_ASSERT( pos != m_ila_private_state_names.end() ) << "Implementation BUG: host of an instruction is not a provided ILA.";
       const StateNameSet & private_state_name = pos->second;

       if(is_ordered) {
         // for each use of unshared variable, find the latest definition, add (pos_last).nxt == (pos) to constr
         // collect states of a ila, substract shared_state
         // make a state_name to (trace step) write expr, step
         // generate v(step) == write_expr (instead of v(step) == v(step_old).nxt)
         // add to constraints
         std::map<std::string, std::pair<ExprPtr, unsigned> > last_update_of_a_state;
         for (auto && sname : private_state_name) {
           last_update_of_a_state.insert( std::make_pair(sname , std::make_pair( ila_ptr->state(sname) ,0) ) );
           // when later translated, we want it to be v(step) == v,0 and the value of v,0 is constrained by init constraints
         }
         // now go through the the vector of ts_seq
         for(auto && ts : ts_seq) {
           // for all the variable it uses (private), we create  v(step) == write_expr 
           // where write_expr is translated by _expr2z3_ptr_->GetExpr( , suffix = std::to_string(saved_num) )
           StateNameSet private_read_set;
           StateNameSet private_write_set;
           INTERSECT( ts->_inst_read_set , private_state_name , private_read_set );
           INTERSECT( ts->_inst_write_set, private_state_name , private_write_set );
           for( auto && sname : private_read_set ) {
              auto name_expr_pos_pair_ = last_update_of_a_state.find(sname);
              ILA_ASSERT(name_expr_pos_pair_ != last_update_of_a_state.end() ) << "Implementation BUG: instruction should not read outside the provided ILA state";
              auto & expr_ = name_expr_pos_pair_->second.first;
              auto & pos_  = name_expr_pos_pair_->second.second;
              auto z3constr = ts->ConvertZ3OnThisStep( ila_ptr->state(sname) ) == _expr2z3_ptr_->GetExpr( expr_, std::to_string(pos_) );
              _constr.push_back(z3constr);
           }

           // for all the variable it defines (private), we update last_update_of_a_state
           // with its update expression and the trace_steps.pos_suffix()
           for( auto && sname : private_write_set) {
             auto conditional_update = ExprFuse::Ite( ts->inst()->GetDecode() , ts->inst()->GetUpdate(sname), ts->host()->state(sname) );
             // NOT using its direct form 
             //  -- last_update_of_a_state[sname] = std::make_pair( ts->inst()->GetUpdate(sname) , ts->pos_suffix() );
             // But you can still enforce Decode ...
             last_update_of_a_state[sname] = std::make_pair( conditional_update , ts->pos_suffix() );
           } // for( auto && sname : private_write_set)
         } // for(auto && ts : ts_seq)
       } // if( is_ordered )
       else {
         // apply the RF_CO_FR
         // create the global write list 
         // update, decode , pos_suffix, timestamp
        typedef std::vector< std::tuple<ExprPtr, ExprPtr,  z3::expr, unsigned> > UpdateDecodeTsPosList;
         std::map<std::string, UpdateDecodeTsPosList > all_update_of_a_state;
         // one pass to identify all defines of a state
         ExprPtr decode_true = ExprFuse::BoolConst(true); //std::make_shared<ExprConst>( BoolVal(true) );
         z3::expr time_0 = _ctx_.int_val(0);
         for (auto && sname : private_state_name) {
           all_update_of_a_state.insert(std::make_pair(sname , UpdateDecodeTsPosList ()));
           all_update_of_a_state[sname].push_back( std::make_tuple( ila_ptr->state(sname),  decode_true , time_0, 0) );
           // when later translated, we want it to be v(step) == v,0 and the value of v,0 is constrained by init constraints
         }
         // now go through the the vector of ts_seq, and collect the definitions
         for(auto && ts : ts_seq) {
           StateNameSet private_write_set;
           INTERSECT( ts->_inst_write_set, private_state_name , private_write_set );
           for ( auto && sname : private_write_set) {
             all_update_of_a_state[sname].push_back( 
              std::make_tuple( 
                ts->inst()->GetUpdate(sname), 
                ts->inst()->GetDecode() , 
                ts->timestamp,
                ts->pos_suffix() ) );
           } // for ( auto && sname : private_write_set)
         } // for(auto && ts : ts_seq)
         // another pass to enforce rf-co-fr
         for(auto && ts : ts_seq) {
           StateNameSet private_read_set;
           INTERSECT( ts->_inst_read_set , private_state_name , private_read_set );
           for( auto && sname : private_read_set ) {
             // for this state
             auto update_map_pos = all_update_of_a_state.find(sname);
             ILA_ASSERT( update_map_pos != all_update_of_a_state.end() ) << "BUG: private state is not defined!";
             UpdateDecodeTsPosList & defineList = update_map_pos->second;
             for (size_t idx_writer = 0; idx_writer != defineList.size() ; ++ idx_writer) {
               auto & name_expr_pos_tuple_ = defineList[idx_writer];
               auto & expr_   = std::get<0>(name_expr_pos_tuple_);
               auto & decode_ = std::get<1>(name_expr_pos_tuple_);
               auto & tstamp_ = std::get<2>(name_expr_pos_tuple_);
               auto & pos_    = std::get<3>(name_expr_pos_tuple_);
               auto z3constr  = ( ts->ConvertZ3OnThisStep( ila_ptr->state(sname) ) == _expr2z3_ptr_->GetExpr( expr_, std::to_string(pos_) ) )
                             && ( ts->timestamp < tstamp_ ) 
                             && ( _expr2z3_ptr_->GetExpr( decode_, std::to_string(pos_) ) );
               // for all other writer (interference)
               for ( size_t idx_interfere = 0; idx_interfere != defineList.size() ; ++ idx_interfere) {
                 if(idx_interfere == idx_writer) continue;
                 auto & name_expr_pos_tuple_i = defineList[idx_interfere];
                 auto & expr_i   = std::get<0>(name_expr_pos_tuple_i);
                 auto & decode_i = std::get<1>(name_expr_pos_tuple_i);
                 auto & tstamp_i = std::get<2>(name_expr_pos_tuple_i);
                 auto & pos_i    = std::get<3>(name_expr_pos_tuple_i);

                 // if decode == true , either CO or FR
                 z3constr = z3constr && 
                            z3::implies( _expr2z3_ptr_->GetExpr( decode_i, std::to_string(pos_i) ) ,  // decode => 
                                         tstamp_i < tstamp_ || tstamp_i > ts->timestamp );           // CO(i,w) \/ FR(r,i)
                 # warning "what about mem var?"
               } // for ( size_t idx_interfere ...
               _constr.push_back(z3constr);
             } // for (size_t idx_writer ...
           } // for( auto && sname : private_read_set ) 
         } // for(auto && ts : ts_seq)
       } // if( ! is_ordered )

     } // for(size_t idx = 0; idx != _ila_trace_steps.size(); ++ idx)
  } // end of function : SetLocalState

  void MemoryModel::AddSingleTraceStepProperty( ExprPtr property, std::function<bool(const TraceStep &)> filter)
  {
    for (auto && ts : _all_trace_steps) {
      if( filter(*ts) ) {
        _constr.push_back( ts->ConvertZ3OnThisStep(property) );
      }
    }
  }
  void MemoryModel::AddDoubleTraceStepProperty( std::function<z3::expr(const TraceStep &,const TraceStep &)>, std::function<bool(const TraceStep &,const TraceStep &)> )
  {
    ILA_ASSERT(false)<< "Not implemented yet";
  }

} // namespace ila