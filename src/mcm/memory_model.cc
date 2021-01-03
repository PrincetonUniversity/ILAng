/// \file
/// Source for the base class of memory model

#include <ilang/mcm/memory_model.h>

#include <string>

#include <ilang/mcm/axiom_helper.h>
#include <ilang/mcm/inter_ila_unroller.h>
#include <ilang/mcm/set_op.h>
#include <ilang/util/log.h>
#include <ilang/util/z3_helper.h>

namespace ilang {

/******************************************************************************/
// TraceStep
/******************************************************************************/

#define TsPrintDecode true
#define TsPrintReadSet true
#define TsPrintReadVal true
#define TsPrintNewVal true

// counter init
unsigned TraceStep::trace_step_seq_no = 0;

std::string TraceStep::GetName() {
  ++trace_step_seq_no; // not thread-safe, but we are not building
                       // multi-threaded program anyway
  return inst()->name().str() + "_ts" + std::to_string(trace_step_seq_no);
}

// a small helper function
std::string ExprPtr2Name(const ExprPtr& e) { return e->name().str(); }

void TraceStep::InitReadWriteSet(
    const InstrPtr& inst) // this can be the inst/parent inst
{
  VarUseFinder<std::string> use_finder_(ExprPtr2Name);
  use_finder_.Traverse(inst, _inst_read_set);
  _inst_write_set = inst->updated_states();
}
void TraceStep::InitReadSetForProperty(const ExprPtr& e) {
  VarUseFinder<std::string> use_finder_(ExprPtr2Name);
  use_finder_.Traverse(e, _inst_read_set);
  // leave _inst_write_set unchanged
}

// constructor of an instruction trace step
TraceStep::TraceStep(const InstrPtr& inst, ZExprVec& cstr, z3::context& ctx,
                     size_t pos)
    : already_searched_for_memreadpair_(false), _type(TraceStepType::INST_EVT),
      _inst(inst), _cstr(cstr), _name(GetName()),
      timestamp(ctx.int_const(_name.c_str())), _pos_suffix(pos), _expr2z3_(ctx),
      _ctx_(ctx) {
  InitReadWriteSet(inst);
  _cstr.push_back(
      timestamp >
      0); // if it is not overwritten, then we will set this constraint
}

// constructor for overwritten timesamp
// usually, only the init trace step does this
TraceStep::TraceStep(const InstrPtr& inst, ZExprVec& cstr, z3::context& ctx,
                     ZExpr ts_overwrite, size_t pos)
    : already_searched_for_memreadpair_(false), _type(TraceStepType::INIT_EVT),
      _inst(inst), _cstr(cstr), _name(GetName()), timestamp(ts_overwrite),
      _pos_suffix(pos), _expr2z3_(ctx), _ctx_(ctx) {
  InitReadWriteSet(inst);
}

/// To create a facet event , the last parameter is actually not in use now
TraceStep::TraceStep(const InstrPtr& ref_inst, ZExprVec& cstr, z3::context& ctx,
                     const std::string& s, size_t pos)
    : already_searched_for_memreadpair_(false), _type(TraceStepType::FACET_EVT),
      _parent_inst(ref_inst), _cstr(cstr), _name(GetName() + "_fevt"),
      timestamp(ctx.int_const(_name.c_str())), _pos_suffix(pos), _expr2z3_(ctx),
      _ctx_(ctx) {
  InitReadWriteSet(_parent_inst);
  _cstr.push_back(timestamp > 0); // For inst event and facet events
}

/// To create a final step event
TraceStep::TraceStep(const ExprPtr& property, ZExprVec& cstr, z3::context& ctx,
                     const InstrLvlAbsPtr& host)
    : already_searched_for_memreadpair_(false), _type(TraceStepType::FINAL_EVT),
      _cstr(cstr), _name("__FINAL_STEP__"),
      timestamp(ctx.int_const(_name.c_str())), _pos_suffix(65536),
      _expr2z3_(ctx), _ctx_(ctx), _host_final_(host),
      _final_property(property) {
  InitReadSetForProperty(property);
}

/// To update the set for TraceStepType::FACET_EVT
void TraceStep::AddStateAccess(const std::string& name, AccessType acc_type) {
  ILA_ASSERT(_type == TraceStepType::FACET_EVT)
      << "Cannot change the state access info of non-facet-event trace step: "
      << _name;
  // ILA_ASSERT( _type != TraceStepType::FINAL_EVT ) << "Cannot change the state
  // access info of instruction trace step: "<< _name ;

  switch (acc_type) {
  case AccessType::WRITE:
    ILA_ASSERT(IN(name, _inst_write_set))
        << "Facet event cannot update state: " << name
        << " that is not written by the instruction";
    _write_state_set.insert(name);
    break;
  case AccessType::READ:
    ILA_ASSERT(IN(name, _inst_read_set))
        << "Facet event cannot read state: " << name
        << " that is not used by the instruction";
    _read_state_set.insert(name);
    break;
  default:
    ILA_ASSERT(false) << "Access type of state: " << name
                      << " is neither READ nor WRITE";
  }
}
void TraceStep::AddStateAccess(const StateNameSet& s, AccessType acc_type) {
  ILA_ASSERT(_type == TraceStepType::FACET_EVT)
      << "Cannot change the state access info of non-facet-event trace step: "
      << _name;
  switch (acc_type) {
  case AccessType::WRITE:
    for (auto& name : s) {
      ILA_ASSERT(IN(name, _inst_write_set))
          << "Facet event cannot update state: " << name
          << " that is not written by the instruction";
      _write_state_set.insert(name);
    }
    break;
  case AccessType::READ:
    for (auto& name : s) {
      ILA_ASSERT(IN(name, _inst_read_set))
          << "Facet event cannot read state: " << name
          << " that is not used by the instruction";
      _read_state_set.insert(name);
    }
    break;
  default:
    ILA_ASSERT(false) << "Access type has to be READ / WRITE";
  }
}

bool TraceStep::Access(AccessType acc_type, const std::string& name) const {
  ILA_ASSERT(_type == TraceStepType::INST_EVT ||
             _type == TraceStepType::INIT_EVT ||
             _type == TraceStepType::FINAL_EVT)
      << "Not implemented for facet event";
  switch (acc_type) {
  case AccessType::READ:
    return IN(name, _inst_read_set);
  case AccessType::WRITE:
    return IN(name, _inst_write_set);
  case AccessType::EITHER:
    return IN(name, _inst_read_set) || IN(name, _inst_write_set);
  default:
    ILA_ASSERT(false) << "Access type must be READ or WRITE or EITHER";
    return false;
  }
}

bool TraceStep::Access(AccessType acc_type,
                       const StateNameSet& stateset) const {
  ILA_ASSERT(_type == TraceStepType::INST_EVT ||
             _type == TraceStepType::INIT_EVT ||
             _type == TraceStepType::FINAL_EVT)
      << "Not implemented for facet event";
  ILA_ASSERT(acc_type == AccessType::READ || acc_type == AccessType::WRITE ||
             acc_type == AccessType::EITHER)
      << "Access type must be READ or WRITE or EITHER";

  if (acc_type == AccessType::READ || acc_type == AccessType::EITHER)
    for (auto&& _s_n : _inst_read_set)
      if (IN(_s_n, stateset))
        return true;
  if (acc_type == AccessType::WRITE || acc_type == AccessType::EITHER)
    for (auto&& _s_n : _inst_write_set)
      if (IN(_s_n, stateset))
        return true;
  return false;
}

std::string TraceStep::Print(z3::model& m) const {
  std::string retStr;
  switch (_type) {
  case TraceStepType::INST_EVT:
    retStr += "[InstrTs]";
    break;
  case TraceStepType::FACET_EVT:
    retStr += "[FacetTs]";
    break;
  case TraceStepType::INIT_EVT:
    retStr += "[InitTs] ";
    break;
  case TraceStepType::FINAL_EVT:
    retStr += "[FinalTs]";
    break;
  default:
    retStr += "[Type:?]";
  }
  retStr += " " + name() + " ";
  retStr += "@";

  retStr += Z3Expr2String(m.ctx(), m.eval(timestamp));

  if (TsPrintDecode && type() != TraceStepType::FINAL_EVT)
    retStr +=
        "   DECODE:" +
        Z3Expr2String(m.ctx(), m.eval(ConvertZ3OnThisStep(inst()->decode())));

  retStr += " seq#" + std::to_string(_pos_suffix) + "\n";
  if (TsPrintReadSet) {
    // header
    if (_type == TraceStepType::FACET_EVT)
      retStr += "Parent R set: ";
    else
      retStr += "R set: \n\t";
    // traverse states
    for (auto sname : _inst_read_set) {
      retStr += sname;
      if (TsPrintReadVal) {
        retStr += " : " + Z3Expr2String(m.ctx(), m.eval(ConvertZ3OnThisStep(
                                                     host()->state(sname))));
        retStr += ",\n\t";
      } else
        retStr += ", ";
    }
    // If it is facet event, dump read state
    if (_type == TraceStepType::FACET_EVT) {
      retStr += "\n\tfacet read states: ";
      for (auto sname : _read_state_set) {
        retStr += sname + ", ";
      }
    }
    retStr += "\n";
  }
  if (TsPrintNewVal) {
    if (_type == TraceStepType::FACET_EVT) {
      retStr += "Facet W set: ";
      for (auto sname : _write_state_set)
        retStr +=
            "\n\t" + sname + " : " +
            Z3Expr2String(m.ctx(),
                          m.eval(ConvertZ3OnThisStep(inst()->update(sname))));
    } else {
      retStr += "W set: ";
      for (auto sname : _inst_write_set)
        retStr +=
            "\n\t" + sname + " : " +
            Z3Expr2String(m.ctx(),
                          m.eval(ConvertZ3OnThisStep(inst()->update(sname))));
    }
  }
  return retStr;
}

// --------------- Some accessors that are too long in the header
// ------------------- //
InstrLvlAbsPtr TraceStep::host() const {
  return (_type == TraceStepType::FINAL_EVT) ? _host_final_ : inst()->host();
}

InstrPtr TraceStep::inst() const {
  ILA_ASSERT(_type != TraceStepType::FINAL_EVT);
  return _type == TraceStepType::INST_EVT || _type == TraceStepType::INIT_EVT
             ? _inst
             : _parent_inst;
}
size_t TraceStep::pos_suffix() const {
  ILA_ASSERT(_type != TraceStepType::FINAL_EVT);
  return _pos_suffix;
}

TraceStep::ZExpr TraceStep::ConvertZ3OnThisStep(const ExprPtr& ast) const {
  if (is_final_tracestep())
    return z3adapter().GetExpr(ast, FINAL_STEP_SUFFIX);
  return z3adapter().GetExpr(ast, std::to_string(pos_suffix()));
}

/******************************************************************************/
// MemoryModel
/******************************************************************************/

MemoryModel::MemoryModel(z3::context& ctx, ZExprVec& _cstrlist,
                         const StateNameSet& shared_states,
                         const ILANameStateNameSetMap& private_states,
                         const InstrLvlAbsPtr& global_ila_ptr)
    : m_shared_state_names(shared_states),
      m_ila_private_state_names(private_states), m_p_global_ila(global_ila_ptr),
      _ctx_(ctx), _constr(_cstrlist), _expr2z3_(ctx), nested_finder_() {}

/*
bool MemoryModel::AccessShared ( const InstrPtr & ip, AccessType acc_type )
{
  ILA_ASSERT(m_p_shared_states) << "Implementation bug: the shared state pointer
is not set";

  StateNameSet access_set;
  if (acc_type == AccessType::READ) {
    VarUseFinder<std::string, ExprPtr2Name> use_finder_;
    use_finder_.Traverse( ip , access_set );
  } else if (acc_type == AccessType::WRITE) {
    ip->updatedStates(access_set);
  }
  else
    ILA_ASSERT(false) << "Access type of querying instruction: "<< ip->name() <<
" is neither READ or WRITE";

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
      _constr,                           // ZExprVec & cstr,
      _ctx_,                             // z3::context& ctx,
      _ctx_.int_val(0), // Z3Expr _ts_overwrite , init trace step starts from 0
      0                 // size_t pos
  );
  // but you need to check if it writes some states and you need to add it to
  // the set of tracesteps and this check should be done according to the MCM
  // axioms.
  return _init_trace_step;
}

MemoryModel::TraceStepPtr
MemoryModel::CreateGlobalFinalStep(const ExprPtr& property)
// should be called by specific memory model
{
  _final_trace_step =
      std::make_shared<TraceStep>(property,      // const ExprPtr &
                                  _constr,       // ZExprVec & cstr,
                                  _ctx_,         // z3::context& ctx,
                                  m_p_global_ila // const InstrLvlAbsPtr & host
      );
  return _final_trace_step;
}

void MemoryModel::InitSize(const ProgramTemplate& _tmpl) {
  _ila_trace_steps.resize(_tmpl.size());
  for (size_t idx = 0; idx != _tmpl.size(); ++idx) {
    _ila_trace_steps[idx].resize(_tmpl[idx].size());
  }
}

// have a final trace step (ts greatest)
// SetLocalState provide the expression for each local state of it
// have a procedure to determine the expression for shared state

// # error we need to collect last states to used in last property?

void MemoryModel::SetLocalState(const std::vector<bool>& ordered)
// link local states
{
  for (size_t idx = 0; idx != _ila_trace_steps.size(); ++idx) {
    std::vector<TraceStepPtr>& ts_seq = _ila_trace_steps[idx];
    bool is_ordered = ordered[idx];
    InstrLvlAbsPtr ila_ptr = ts_seq[0]->host();
    const std::string& ila_name = ila_ptr->name().str();
    auto pos = m_ila_private_state_names.find(ila_name);

    ILA_ASSERT(pos != m_ila_private_state_names.end())
        << "Implementation BUG: the private state set should exist for ILA:"
        << ila_name;
    const StateNameSet& private_state_name = pos->second;

    if (is_ordered) {
      // for each use of unshared variable, find the latest definition, add
      // (pos_last).nxt == (pos) to constr collect states of a ila, substract
      // shared_state make a state_name to (trace step) write expr, step
      // generate v(step) == write_expr (instead of v(step) == v(step_old).nxt)
      // add to constraints
      std::map<std::string, std::pair<ExprPtr, unsigned>>
          last_update_of_a_state;
      for (auto&& sname : private_state_name) {
        last_update_of_a_state.insert(
            std::make_pair(sname, std::make_pair(ila_ptr->state(sname), 0)));
        // when later translated, we want it to be v(step) == v,0 and the value
        // of v,0 is constrained by init constraints
      }
      // now go through the the vector of ts_seq
      auto prev_ts = ts_seq[0];
      for (auto&& ts : ts_seq) {
        // for all the variable it uses (private), we create  v(step) ==
        // write_expr where write_expr is translated by ConvertZ3( , suffix =
        // std::to_string(saved_num) )
        StateNameSet private_read_set;
        StateNameSet private_write_set;
        INTERSECT(ts->_inst_read_set, private_state_name, private_read_set);
        INTERSECT(ts->_inst_write_set, private_state_name, private_write_set);
        for (auto&& sname : private_read_set) {
          auto name_expr_pos_pair_ = last_update_of_a_state.find(sname);
          ILA_ASSERT(name_expr_pos_pair_ != last_update_of_a_state.end())
              << "Implementation BUG: instruction should not read outside the "
                 "provided ILA state";
          auto& expr_ = name_expr_pos_pair_->second.first;
          auto& pos_ = name_expr_pos_pair_->second.second;
          auto z3constr = ts->ConvertZ3OnThisStep(ila_ptr->state(sname)) ==
                          ConvertZ3(expr_, std::to_string(pos_));
          _constr.push_back(z3constr);
        }

        // for all the variable it defines (private), we update
        // last_update_of_a_state with its update expression and the
        // trace_steps.pos_suffix()
        for (auto&& sname : private_write_set) {
          auto conditional_update =
              asthub::Ite(ts->inst()->decode(), ts->inst()->update(sname),
                          ts->host()->state(sname));
          // NOT using its direct form
          //  -- last_update_of_a_state[sname] = std::make_pair(
          //  ts->inst()->update(sname) , ts->pos_suffix() );
          // But you can still enforce Decode ...
          last_update_of_a_state[sname] =
              std::make_pair(conditional_update, ts->pos_suffix());
        } // for( auto && sname : private_write_set)

        // Enforcing the ordering relation among them
        if (prev_ts != ts) { // for not the first ts
          _constr.push_back(HB(*prev_ts, *ts));
        }
        prev_ts = ts;

      } // for(auto && ts : ts_seq)
      // now let's calculate the final state (translated by suffix : final)
      for (auto&& sname : private_state_name) {
        // ILA_INFO<<"Enumerating:"<<sname<<" (pv state) for
        // ila:"<<(ila_ptr->name().str());
        auto name_expr_pos_pair_ = last_update_of_a_state.find(sname);
        ILA_ASSERT(name_expr_pos_pair_ != last_update_of_a_state.end())
            << "Implementation BUG: all private state should at least has its "
               "default initializer";
        auto& expr_ = name_expr_pos_pair_->second.first;
        auto& pos_ = name_expr_pos_pair_->second.second;
        auto z3constr = ConvertZ3(ila_ptr->state(sname), FINAL_STEP_SUFFIX) ==
                        ConvertZ3(expr_, std::to_string(pos_));
        _constr.push_back(z3constr);
      }

    } // if( is_ordered )
    else {
      // apply the RF_CO_FR
      // create the global write list
      // update, decode , timestamp, pos_suffix
      typedef std::vector<std::tuple<ExprPtr, ExprPtr, z3::expr, unsigned>>
          UpdateDecodeTsPosList;
      std::map<std::string, UpdateDecodeTsPosList> all_update_of_a_state;
      // one pass to identify all defines of a state
      ExprPtr decode_true = asthub::BoolConst(
          true); // std::make_shared<ExprConst>( BoolVal(true) );
      z3::expr time_0 = _ctx_.int_val(0);
      for (auto&& sname : private_state_name) {
        all_update_of_a_state.insert(
            std::make_pair(sname, UpdateDecodeTsPosList()));
        all_update_of_a_state[sname].push_back(
            std::make_tuple(ila_ptr->state(sname), decode_true, time_0, 0));
        // when later translated, we want it to be v(step) == v,0 and the value
        // of v,0 is constrained by init constraints
      }
      // now go through the vector of ts_seq, and collect the definitions
      for (auto&& ts : ts_seq) {
        StateNameSet private_write_set;
        INTERSECT(ts->_inst_write_set, private_state_name, private_write_set);
        for (auto&& sname : private_write_set) {
          all_update_of_a_state[sname].push_back(
              std::make_tuple(ts->inst()->update(sname), ts->inst()->decode(),
                              ts->timestamp, ts->pos_suffix()));
        } // for ( auto && sname : private_write_set)
      }   // for(auto && ts : ts_seq)

      ILA_DLOG("MCM.SetLocalState.Unordered")
          << "==== DEBUG private state: all_update_of_a_state ====";
      for (auto&& name_update_tuple_ : all_update_of_a_state) {
        ILA_DLOG("MCM.SetLocalState.Unordered")
            << name_update_tuple_.first << " : ";
        for (auto&& tpl_ : name_update_tuple_.second) {
          auto& expr_ = std::get<0>(tpl_);
          auto& decode_ = std::get<1>(tpl_);
          auto& tstamp_ = std::get<2>(tpl_);
          auto& pos_ = std::get<3>(tpl_);
          ILA_DLOG("MCM.SetLocalState.Unordered")
              << "\t@" << pos_ << " (" << tstamp_ << ") "
              << " Upon D:" << ConvertZ3(decode_, std::to_string(pos_))
              << " --> " << ConvertZ3(expr_, std::to_string(pos_));
        }
      }

      // another pass to enforce rf-co-fr
      for (auto&& ts_read : ts_seq) {
        StateNameSet private_read_set;
        INTERSECT(ts_read->_inst_read_set, private_state_name,
                  private_read_set);
        for (auto&& sname : private_read_set) {
          // for this state
          ILA_DLOG("MCM.SetLocalState.Unordered") << "For state:" << sname;
          auto update_map_pos = all_update_of_a_state.find(sname);
          ILA_ASSERT(update_map_pos != all_update_of_a_state.end())
              << "BUG: private state is not defined!";

          z3::expr constr_exists_a_writer_ = _ctx_.bool_val(false);
          UpdateDecodeTsPosList& defineList = update_map_pos->second;
          for (size_t idx_writer = 0; idx_writer != defineList.size();
               ++idx_writer) {
            auto& name_expr_pos_tuple_ = defineList[idx_writer];
            auto& expr_ = std::get<0>(name_expr_pos_tuple_);
            auto& decode_ = std::get<1>(name_expr_pos_tuple_);
            auto& tstamp_ = std::get<2>(name_expr_pos_tuple_);
            auto& pos_ = std::get<3>(name_expr_pos_tuple_);
            auto z3constr =
                (ts_read->ConvertZ3OnThisStep(ila_ptr->state(sname)) ==
                 ConvertZ3(expr_, std::to_string(pos_))) &&
                (tstamp_ < ts_read->timestamp) // HB (writer, ts_read)
                && (ConvertZ3(decode_, std::to_string(pos_)));

            // avoid read-from itself !
            if (pos_ == ts_read->pos_suffix()) {
              ILA_DLOG("MCM.SetLocalState.Unordered")
                  << "-- Skip writer idx:" << idx_writer
                  << " (timestamp: " << tstamp_ << ")";
              continue;
            }

            ILA_DLOG("MCM.SetLocalState.Unordered")
                << "For writer idx:" << idx_writer << " (timestamp: " << tstamp_
                << ")";
            // for all other writer (interference)
            for (size_t idx_interfere = 0; idx_interfere != defineList.size();
                 ++idx_interfere) {
              if (idx_interfere == idx_writer) {
                ILA_DLOG("MCM.SetLocalState.Unordered")
                    << "  --skip" << idx_interfere << " (timestamp: "
                    << (std::get<2>(defineList[idx_interfere])) << ")";
                continue;
              }

              auto& name_expr_pos_tuple_i = defineList[idx_interfere];
              // auto & expr_i   = std::get<0>(name_expr_pos_tuple_i);
              auto& decode_i = std::get<1>(name_expr_pos_tuple_i);
              auto& tstamp_i = std::get<2>(name_expr_pos_tuple_i);
              auto& pos_i = std::get<3>(name_expr_pos_tuple_i);

              // avoid interfere with itself
              if (pos_i == ts_read->pos_suffix()) {
                ILA_DLOG("MCM.SetLocalState.Unordered")
                    << "  --skip" << idx_interfere << " (timestamp: "
                    << (std::get<2>(defineList[idx_interfere])) << ")";
                continue;
              }

              ILA_DLOG("MCM.SetLocalState.Unordered")
                  << "  " << idx_interfere << " (timestamp: " << (tstamp_i)
                  << ")";
              // if decode == true , either CO or FR
              z3constr =
                  z3constr &&
                  Z3Implies(
                      _ctx_,
                      ConvertZ3(decode_i, std::to_string(pos_i)), // decode =>
                      tstamp_i < tstamp_ ||
                          tstamp_i > ts_read->timestamp); // CO(i,w) \/ FR(r,i)
              // # warning "what about mem var?" HZ Comment: should be okay
            } // for ( size_t idx_interfere ...
            constr_exists_a_writer_ = constr_exists_a_writer_ || z3constr;
          } // for (size_t idx_writer ...
          _constr.push_back(constr_exists_a_writer_);
        } // for( auto && sname : private_read_set )
      }   // for(auto && ts : ts_seq)

      // Now let's enforce the final update expression
      // r --- w (--co-- other w)   RF-CO, we don't need the final timestamp
      for (auto&& sname : private_state_name) {
        z3::expr constr_exists_a_writer_ = _ctx_.bool_val(false);
        auto update_map_pos = all_update_of_a_state.find(sname);
        ILA_ASSERT(update_map_pos != all_update_of_a_state.end())
            << "BUG: private state:" << sname << " is not defined yet";
        UpdateDecodeTsPosList& defineList = update_map_pos->second;
        for (size_t idx_writer = 0; idx_writer != defineList.size();
             ++idx_writer) {
          auto& name_expr_pos_tuple_ = defineList[idx_writer];
          auto& expr_ = std::get<0>(name_expr_pos_tuple_);
          auto& decode_ = std::get<1>(name_expr_pos_tuple_);
          auto& tstamp_ = std::get<2>(name_expr_pos_tuple_);
          auto& pos_ = std::get<3>(name_expr_pos_tuple_);
          auto z3constr =
              (ConvertZ3(ila_ptr->state(sname), FINAL_STEP_SUFFIX) ==
               ConvertZ3(expr_, std::to_string(pos_)))
              // && ( tstamp_ < ts_read->timestamp  )  // HB (writer, ts_read),
              // always true no need for this
              && (ConvertZ3(decode_, std::to_string(pos_)));
          for (size_t idx_interfere = 0; idx_interfere != defineList.size();
               ++idx_interfere) {
            if (idx_interfere == idx_writer)
              continue;

            auto& name_expr_pos_tuple_i = defineList[idx_interfere];
            // auto & expr_i   = std::get<0>(name_expr_pos_tuple_i);
            auto& decode_i = std::get<1>(name_expr_pos_tuple_i);
            auto& tstamp_i = std::get<2>(name_expr_pos_tuple_i);
            auto& pos_i = std::get<3>(name_expr_pos_tuple_i);
            z3constr = z3constr &&
                       Z3Implies(_ctx_,
                                 ConvertZ3(decode_i,
                                           std::to_string(pos_i)), // decode =>
                                 tstamp_i < tstamp_); // CO(i,w) \/ FR(r,i)

          } // for the interference writer
          constr_exists_a_writer_ = constr_exists_a_writer_ || z3constr;
        } // for the writer
        _constr.push_back(constr_exists_a_writer_);
      } // for all private state name

    } // if( ! is_ordered )

  } // for(size_t idx = 0; idx != _ila_trace_steps.size(); ++ idx) (For all
    // entity)
} // end of function : SetLocalState

void MemoryModel::AddSingleTraceStepProperty(
    const ExprPtr& property, std::function<bool(const TraceStep&)> filter) {
  GetSingleTraceStepProperty(
      property, filter,
      [this](const z3::expr& e) -> void { this->_constr.push_back(e); });
  // set the call back function as  to add it to the current _constr list
}

void MemoryModel::GetSingleTraceStepProperty(
    const ExprPtr& property, std::function<bool(const TraceStep&)> filter,
    std::function<void(const z3::expr&)> collector) {
  for (auto&& ts : _all_trace_steps) {
    if (filter(*ts)) {
      collector(ts->ConvertZ3OnThisStep(property));

      // also we need to make sure that it is added to the read lists
      VarUseFinder<std::string> use_finder_(ExprPtr2Name);

      StateNameSet read_set;
      use_finder_.Traverse(property, read_set); // warning? if it is value

      for (auto&& sname : read_set) {
        if (!IN(sname,
                ts->_inst_read_set)) { // in case we need to change read set
          // we need to warn users of some possiblility of errors
          if (!((ts->type() == TraceStepType::INST_EVT) ||
                (ts->type() == TraceStepType::FACET_EVT)))
            ILA_WARN << "Add Property: trying to change the read set of a "
                        "facet event:"
                     << ts->name() << " with new state:" << sname;
          if (IN(sname, m_shared_state_names))
            ILA_WARN << "Add Property: add READ SHARED state " << sname
                     << " to ts:" << ts->name()
                     << " does not change the ts SET";
          ILA_ERROR_IF(!ts->host()->state(sname))
              << "Adding a read state: " << sname
              << " that does not belongs to the ILA:"
              << ts->host()->name().str()
              << ", please consider using a tighter tracestep filter for "
                 "function: AddSingleTraceStepProperty";
          // if it is just read local, then we have nothing to worry about. we
          // can safely add it
          ts->_inst_read_set.insert(sname);
        }
      }
    }
  }
}
void MemoryModel::AddDoubleTraceStepProperty(
    std::function<z3::expr(const TraceStep&, const TraceStep&)>,
    std::function<bool(const TraceStep&, const TraceStep&)>) {
  ILA_ASSERT(false) << "Not implemented yet";
}

} // namespace ilang
