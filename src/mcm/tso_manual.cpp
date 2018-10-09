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

void Tso::RegisterSteps(size_t regIdx , InstrVec & _inst_seq)
{
  size_t pos = 1; // start from 1, same as unroller.cpp

  for (auto && instr_ptr_ : _inst_seq) {
    // this is the same for all instructions
    auto inst_trace_step = std::make_shared<TsoTraceStep>(instr_ptr_ , cstr, _ctx_ , pos , _expr2z3_ptr_);

    // 1 - bookkeeping
    _all_trace_steps.push_back( inst_trace_step );
    _all_inst_trace_steps.push_back( inst_trace_step );
    _ila_trace_steps[regIdx][pos-1] = inst_trace_step;

    // InstructionSet WRITE
    if ( inst_trace_step->Access( AccessType::WRITE , m_p_shared_states ) ) {
      WRITE_list.add( inst_trace_step );
    // now the facet event
      {
        auto _facet_trace_step = std::make_shared<TraceStep>(instr_ptr_ , cstr, _ctx_ , "wfe.global", pos , _expr2z3_ptr_);
        inst_trace_step->wfe_global = _facet_trace_step;
        _all_trace_steps.push_back( _facet_trace_step  );

        // a set of all states
        // a set of all shared states
        // add when needed, and then add the rest if required
        const StateNameSet & read_set_  = inst_trace_step->get_inst_read_set();
        const StateNameSet & write_set_ = inst_trace_step->get_inst_write_set();
        StateNameSet global_read_set_;
        StateNameSet global_write_set_;
        INTERSECT(read_set_, m_shared_state_names,  global_read_set_);  // global_read_set_  := read_set_   & m_shared_state_names
        INTERSECT(write_set_, m_shared_state_names, global_write_set_); // global_write_set_ := write_set_  & m_shared_state_names

        // _facet_trace_step->AddStateAccess( "" , AccessType::WRITE );
        // global_write_set_.erase( "" );

        _facet_trace_step->AddStateAccess( global_write_set_ , AccessType::WRITE );
      }
    }

    // InstructionSet READ
    if ( inst_trace_step->Access( AccessType::READ , m_p_shared_states ) ) {
      READ_list.add( inst_trace_step );
    }

    // InstructionSet FENCE
    if ( instr_ptr_->name() == "fence" || 
         instr_ptr_->name() == "Fence" ||
         instr_ptr_->name() == "FENCE" ) {
      FENCE_list.add( inst_trace_step );
    }

    // InstructionSet RMW
    if ( instr_ptr_->name() == "atomic_add" || 
         instr_ptr_->name() == "atomic_and" ) {
      RMW_list.add( inst_trace_step );
    }

    ++ pos;
  }
}


void Tso::FinishRegisterSteps()
{
  DIFFERENCE(WRITE_list, RMW_list, PureWrite_list);


  // eventually, we need to deal with the init trace 
  auto init_trace_step_ = CreateGlobalInitStep();
  // 1. Bookkeeping
  _all_trace_steps.push_back( init_trace_step_ );
  _all_inst_trace_steps.push_back( init_trace_step_ );
  // InstructionSet WRITE
  if ( init_trace_step_->Access( AccessType::WRITE , m_p_shared_states ) ) 
    WRITE_list.add( init_trace_step_ );
  // InstructionSet READ - skip, they should not read from any other trace steps, if there are, make it arbitrary
  // InstructionSet FENCE - skip, name is not FENCE
  // InstructionSet RMW - skip, name not matched
}

// Note: Same Address and Same Data
// should handle memory things
// you may want to do small static tests
// to make smaller constraints

// In order mode: local resolving is possible, only shared state access will be translated
//                to pi-function
// Out-of-order mode: all state read will be translated to pi-function? Yes
// 
// * maybe we need to apply a certain check?

// SameAddress & Decode & SameCore have their ``static'' form



void Tso::ApplyAxioms()
{ 
  // ----- AXIOM RF_CO_FR BEGIN -----
  ZExprVec var10_L;
  for (auto && s : m_shared_state_names) {  // forall s : *m_p_shared_states
    ZExprVec var8_L;
    for (auto && r : READ_list) {  // forall r : READ_list
      if  ( ! r.Access(AccessType::READ, s) ) continue;
      ZExprVec var6_L;
      for (auto && w : WRITE_list )  { // exists w : WRITE_list
        if  ( w.name() == r.name() ) continue; 
        if  ( ! w.Access(AccessType::WRITE, s) ) continue;
        ZExprVec var4_L;
        for (auto && w2 : WRITE_list) {  // forall w2 : WRITE_list
          if  ( w2.name() == w.name() ) continue; 
          if  ( w2.name() == r.name() ) continue; 
          if  ( ! w2.Access(AccessType::WRITE, s) ) continue;
          var3 = Z3Implies( _ctx_.bool_val(true) , z3::implies( ( ( SameAddress ( w,w2,s,AccessType::WRITE,AccessType::WRITE )  && Decode ( w2 )  )  ) , ( CO ( w2,w )  || FR ( r,w2 )  )  )  );
          var4_L.push_back( var3); }
        var5 = Z3ForallList( var4_L);
        var2 = Z3And( _ctx_.bool_val(true) , ( ( ( ( SameAddress ( w,r,s,AccessType::WRITE,AccessType::READ )  && SameData ( w,r,s,AccessType::WRITE,AccessType::READ )  )  && Decode ( w )  )  && RF ( w,r )  )  && ( var5 ) )  );
        var6_L.push_back( var2); }
      var7 = Z3ExistsList( var6_L);
      var1 = Z3Implies( _ctx_.bool_val(true) , var7 );
      var8_L.push_back( var1); }
    var9 = Z3ForallList( var8_L);
    var10_L.push_back( var9); }
  var11 = Z3ForallList( var10_L);
  _constr.push_back( var11);
  // ----- AXIOM RF_CO_FR END -----
  // ----- AXIOM TSO_WriteFacetOrder BEGIN -----
  ZExprVec var12_L;
  for (auto && w : PureWrite_list) {  // forall w : PureWrite_list
    var12_L.push_back( HB ( w,__wfe_global( w) ) ); }
  var13 = Z3ForallList( var12_L);
  _constr.push_back( var13);
  // ----- AXIOM TSO_WriteFacetOrder END -----
  // ----- AXIOM TSO_Store BEGIN -----
  ZExprVec var17_L;
  for (auto && w1 : WRITE_list) {  // forall w1 : WRITE_list
    ZExprVec var15_L;
    for (auto && w2 : WRITE_list) {  // forall w2 : WRITE_list
      if  ( w2.name() == w1.name() ) continue; 
      if ( !SameCore ( w1,w2 )  ) continue;
      var14 = Z3Implies( _ctx_.bool_val(true) , z3::implies( ( ( SameCore ( w1,w2 )  && HB ( w1,w2 )  )  ) , HB ( __wfe_global( w1),__wfe_global( w2) )  )  );
      var15_L.push_back( var14); }
    var16 = Z3ForallList( var15_L);
    var17_L.push_back( var16); }
  var18 = Z3ForallList( var17_L);
  _constr.push_back( var18);
  // ----- AXIOM TSO_Store END -----
  // ----- AXIOM TSO_Fence BEGIN -----
  ZExprVec var21_L;
  for (auto && f : FENCE_list) {  // forall f : FENCE_list
    ZExprVec var19_L;
    for (auto && w : WRITE_list) {  // forall w : WRITE_list
      if ( !SameCore ( w,f )  ) continue;
      var19_L.push_back( z3::implies( ( ( SameCore ( w,f )  && HB ( w,f )  )  ) , HB ( __wfe_global( w),f )  ) ); }
    var20 = Z3ForallList( var19_L);
    var21_L.push_back( var20); }
  var22 = Z3ForallList( var21_L);
  _constr.push_back( var22);
  // ----- AXIOM TSO_Fence END -----
  // ----- AXIOM TSO_RMW BEGIN -----
  ZExprVec var23_L;
  for (auto && i : RMW_list) {  // forall i : RMW_list
    var23_L.push_back( Sync ( i,__wfe_global( i) ) ); }
  var24 = Z3ForallList( var23_L);
  _constr.push_back( var24);
  // ----- AXIOM TSO_RMW END -----

}


}


// ------------------------- ACCESSOR FUNCTIONs -------------------------------------- //
TraceStep & __wfe_global(TraceStep & ts)
{
  TsoTraceStep * _cts = dynamic_cast<TsoTraceStep>( &ts );
  ILA_ASSERT(_cts) << "MCM: trace step: "<< ts.name() << "has no attribute: wfe.global";
  return *( (_cts->wfe_global) .get() ) ;
}


z3::expr Tso::RF( TraceStep &w,TraceStep &r) {
  if (SameCore ( w,r )  ) return HB ( w,r ) ; 
  if ( !SameCore ( w,r )  ) return HB ( __wfe_global( w),r ) ; 
  return ( ( ( z3::implies( SameCore ( w,r )  , HB ( w,r )  )  ) && ( z3::implies( !( SameCore ( w,r )  )  , HB ( __wfe_global( w),r )  )  ) )  );
}

z3::expr Tso::FR( TraceStep &r,TraceStep &w) {
  if (SameCore ( r,w )  ) return HB ( r,w ) ; 
  if ( !SameCore ( r,w )  ) return HB ( r,__wfe_global( w) ) ; 
  return ( ( ( z3::implies( SameCore ( r,w )  , HB ( r,w )  )  ) && ( z3::implies( !( SameCore ( r,w )  )  , HB ( r,__wfe_global( w) )  )  ) )  );
}

z3::expr Tso::CO( TraceStep &w1,TraceStep &w2) {
  if (SameCore ( w1,w2 )  ) return HB ( w1,w2 ) ; 
  if ( !SameCore ( w1,w2 )  ) return HB ( __wfe_global( w1),__wfe_global( w2) ) ; 
  return ( ( ( z3::implies( SameCore ( w1,w2 )  , HB ( w1,w2 )  )  ) && ( z3::implies( !( SameCore ( w1,w2 )  )  , HB ( __wfe_global( w1),__wfe_global( w2) )  )  ) )  );
}