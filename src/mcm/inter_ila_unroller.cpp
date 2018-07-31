/// \file
/// Source for multi-ILA unroller

#include "mcm/inter_ila_unroller.h"
#include "util/log.h"
#include <map>
#include <vector>

namespace ila {


/******************************************************************************/
// InterIlaUnroller
/******************************************************************************/

  InterIlaUnroller::InterIlaUnroller(z3::context& ctx, const IlaPtrVec & iv, MemoryModelPtr mm)
        : ctx_(ctx), sys_ila_(iv), mm_(mm) {

    CreateUnrollers();
    FindSharedStates();
  }

  InterIlaUnroller::~InterIlaUnroller() {}

  void InterIlaUnroller::FindSharedStates()
  {
    for (auto && ila_ptr_ : sys_ila_) {
      ILA_NOT_NULL(ila_ptr);
      // FIXME: currently not directly handle hierarchy, you need to flatten the ILA first
      ILA_ASSERT( ila_ptr->child_num() == 0 ) << " Implementation bug: " <<
        "currently inter_ila_unroller does not handle hierarchy, please flatten ILA: "<< ila_ptr->name() <<" first.";
      for (size_t i = 0; i != top->state_num() ; i ++ ) {
        auto state_var_ = top->state(i);
        shared_states_[ state_var_->name().str() ].push_back(state_var); 

        // insert to the list of state var of the same name
        // will automatically create an empty list if not previously exists
        // Here I use .str(), because I'm afraid that Symbol("A") != Symbol("A")
      }

    }
    mm->SetSharedStates(& shared_states_);
  }

  void InterIlaUnroller::CreateUnrollers()
  {
    // by default, we use path unroller
    // but this does not mean it is in order
    for (auto && ila_ptr_ : sys_ila_)
      unrollers_.push_back( std::make_shared<PathUnroll>(ctx_) );
  }

  void InterIlaUnroller::Unroll(const ProgramTemplate & tmpl)
  {
    size_t ila_num = sys_ila_.size();
    ILA_ASSERT( ila_num == unrollers_.size() );
    ILA_ASSERT( ila_num == tmpl.size() );
    for (size_t idx = 0; idx != ila_num; ++ idx) {
      mm->RegisterSteps( tmpl[idx] , cstr_ , ctx() ); // register those instructions
      ZExpr constr = unrollers_[idx]->PathNone( tmpl[idx] , 1 ); // starting from 1 : the first but not init.
      ...
      // store to constraints
      // time stamps
      // ordered or not
      // find the shared variables and apply pi-functions?
      // need to know when to create more steps: go through the tmpl?
    }
    mm->FinishRegisterSteps( tmpl, cstr_ , ctx() ); // HZ Question: is it too late?
    mm->ApplyAxioms( tmpl, cstr_, ctx() );
  }

  void InterIlaUnroller::GenSysInitConstraints()
  {
    // we need to get the constraints of init conditions and replace
    // global the variables there with the unified shared names
    // An alternative (currently used) may be directly giving the unroller the exprs
    // with host removed (if they are shared variables).
    auto isSharedVar = [&shared_states_](const ExprPtr &exp) -> bool {
      return shared_states_.find( exp->name().str() ) != shared_states_.end();  };
      // replace if found (is shared state)

    HostRemoveRestore host_remover;
    InstrVec EmptyVec; // dummy 
    
    size_t ila_num = sys_ila_.size();
    ILA_ASSERT( ila_num == unrollers_.size() );

    for (size_t idx = 0; idx != ila_num; ++ idx) {
      auto &ila_ptr = sys_ila_[idx];
      auto &unroller_ptr = unrollers_[idx];

      size_t init_num = ila_ptr->init_num();
      for (size_t init_cond_idx = 0; init_cond_idx != init_num; ++ init_cond ) {
        ExprPtr init_cond = ila_ptr->init(init_cond_idx);
        host_remover.RecordAndRemoveIf(init_cond, isSharedVar);
        unroller_ptr->AddInitPred( init_cond );
      }

      // add the init condition
      ZExpr constr = unroller_ptr->PathNone( EmptyVec , 0 ); // this will only give us the initial condition
      cstr_.push_back(constr);
    }
    host_remover.RestoreAll(); // this will not affect the generated z3
    // A sanity check can be put here to check if the initial conditions of several components are compatible or not
    ILA_ASSERT( CurrConstrSat() ) << "The initial conditions of ILAs are incompatible";
  }

  bool InterIlaUnroller::CurrConstrSat() 
  {
    // This is to check if the current constraints are satisfiable.
    z3::solver solver(ctx());

    auto cnst = ConjPred( cstr_ );
    solver.add(cnst);
    auto result = solver.check();

    if(result == z3::sat) {
      auto m = solver.get_model();
      ILA_DLOG("InterIlaUnroller.CurrConstrSat") << m;
      return true;
    }
    return false;
  }

  ZExpr InterIlaUnroller::ConjPred(const ZExprVec& vec) const {
    auto conj = ctx().bool_val(true);
    for (size_t i = 0; i != vec.size(); i++) {
      conj = (conj && vec[i]);
    }
    conj = conj.simplify();
    return conj;
  }



/******************************************************************************/
// Helper Class: HostRemoveRestore
/******************************************************************************/

// HZ Comment: There are more issues I need to sort out
// e.g., the functions (0-ary or o.w.) depends on host 
// ExprOp seems not (except applying the 0-ary func)
// Should they be removed also? 
// Also, more to think about for hierarchical ila

void HostRemoveRestore::RecordAndRemove( ExprPtr exp )
{
  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; ++i) 
    RecordAndRemove( expr->arg(i) );
  if ( expr->is_var() ) { // currently we only deal with expr vars, maybe also func?
    auto pos = map_->find(expr);
    if ( pos != map_->end() ) { // if exp is already registered
      ILA_ASSERT( pos->second == expr->host() ) << "Implementation bug: host() of expr:" << expr 
          << " is already filled and they do not match." ; 
      // and then, no need to save, just remove 
    }
    else 
      map_.insert( std::make_pair( expr, expr->host() ) );
    expr->set_host(NULL);
  }
}
void HostRemoveRestore::RecordAndRemoveIf( ExprPtr exp , ExprJudgeFunc f )
{
  ILA_ASSERT( f != nullptr ) << "ExprJudgeFunc cannot be a null pointer";

  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; ++i) 
    RecordAndRemoveIf( expr->arg(i) , f);
  if ( expr->is_var() && f(exp) ) { // currently we only deal with expr vars, maybe also func?
    auto pos = map_->find(expr);
    if ( pos != map_->end() ) { // if exp is already registered
      ILA_ASSERT( pos->second == expr->host() ) << "Implementation bug: host() of expr:" << expr 
          << " is already filled and they do not match." ; 
      // and then, no need to save, just remove 
    }
    else 
      map_.insert( std::make_pair( expr, expr->host() ) );
    expr->set_host(NULL);
  }
}
void HostRemoveRestore::Restore( ExprPtr exp )
{
  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; ++i) 
    Restore( expr->arg(i) );
  if ( expr->is_var() && expr->host() == NULL) { // currenlty we only limit ourselves to expr vars
    auto pos = map_->find(expr);
    if (pos != map_->end() ) 
      expr->set_host( pos->second );
  }
}
void HostRemoveRestore::RestoreAll() {
  for (auto & expr_host_pair : map_) {
    ILA_ASSERT(expr_host_pair.first->host() == NULL) << "Unable to restore to expr:" << expr_host_pair.first 
      << " , host field is already set.";
    expr_host_pair.first->set_host( expr_host_pair.second );
  }
}

} // namespace ila