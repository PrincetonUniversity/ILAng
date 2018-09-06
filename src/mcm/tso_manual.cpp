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
  size_t pos = 1; // start from 1, same as unroller.cpp
  _expr2z3_ptr_ = std::make_shared<Z3ExprAdapter>(ctx_);

  for (auto && instr_ptr_ : _inst_seq) {
    // this is the same for all instructions
    auto inst_trace_step = std::make_shared<TsoTraceStep>(instr_ptr_ , cstr, ctx , pos , _expr2z3_ptr_);

    // 1 - bookkeeping
    _all_trace_steps.push_back( inst_trace_step );
    _all_inst_trace_steps.push_back( inst_trace_step );

    // InstructionSet WRITE
    if ( inst_trace_step->Access( AccessType::WRITE , m_p_shared_states ) ) {
      WRITE_list.add( inst_trace_step );
    // now the facet event
      {
        auto _facet_trace_step = std::make_shared<TraceStep>(instr_ptr_ , cstr, ctx , "wfe.global", pos , _expr2z3_ptr_);
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


void Tso::FinishRegisterSteps(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ )
{
  DIFFERENCE(WRITE_list, RMW_list, PureWrite_list);
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



void Tso::ApplyAxioms(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ )
{
  // ----- AXIOM RF_CO_FR BEGIN -----
  ZExprVec var7_L;
  for (auto && r : READ_list) {  // forall r : READ_list
    ZExprVec var5_L;
    for (auto && w : WRITE_list )  { // exists
      if  ( w.name() == r.name() ) continue; 
      if  ( SameAddressStatic(w,r) == StaticResult::STATIC_FALSE ) continue; // statically determined (exists F => F)
      ZExprVec var3_L;
      for (auto && w2 : WRITE_list) {  // forall w2 : WRITE_list
        if  ( w2.name() == w.name() ) continue; 
        if  ( SameAddressStatic(w,w2) == StaticResult::STATIC_FALSE ) continue; // statically determined (forall F => T)
        if  ( DecodeStatic(w2) == StaticResult::STATIC_FALSE ) continue;
        var2 = Z3Implies( ctx_.bool_val(true) , z3::implies( ( ( SameAddress ( w , w2 )  && Decode ( w2 )  )  ) , ( CO ( w2 , w )  || FR ( r , w2 )  )  )  );
        var3_L.push_back( var2); }
      var4 = Z3ForallList( var3_L);
      var1 = Z3And( ctx_.bool_val(true) , ( ( ( ( SameAddress ( w , r )  && SameData ( w , r )  )  && Decode ( w )  )  && RF ( w , r )  )  && ( var4 ) )  );
      var5_L.push_back( var1); }
    var6 = Z3ExistsList( var5_L);
    var7_L.push_back( var6); }
  var8 = Z3ForallList( var7_L);
  _constr.push_back( var8);
  // ----- AXIOM RF_CO_FR END -----
  // ----- AXIOM TSO_WriteFacetOrder BEGIN -----
  ZExprVec var9_L;
  for (auto && w : PureWrite_list) {  // forall w : PureWrite_list
    var9_L.push_back( HB ( w , __wfe_global( w) ) ); }
  var10 = Z3ForallList( var9_L);
  _constr.push_back( var10);
  // ----- AXIOM TSO_WriteFacetOrder END -----
  // ----- AXIOM TSO_Store BEGIN -----
  ZExprVec var14_L;
  for (auto && w1 : WRITE_list) {  // forall w1 : WRITE_list
    ZExprVec var12_L;
    for (auto && w2 : WRITE_list) {  // forall w2 : WRITE_list
      if  ( w2.name() == w1.name() ) continue; 
      if  ( SameCoreStatic(w1,w2) == StaticResult::STATIC_FALSE ) continue;
      var11 = Z3Implies( ctx_.bool_val(true) , z3::implies( PO ( w1 , w2 )  , HB ( __wfe_global( w1) , __wfe_global( w2) )  )  );
      var12_L.push_back( var11); }
    var13 = Z3ForallList( var12_L);
    var14_L.push_back( var13); }
  var15 = Z3ForallList( var14_L);
  _constr.push_back( var15);
  // ----- AXIOM TSO_Store END -----
  // ----- AXIOM TSO_Fence BEGIN -----
  ZExprVec var18_L;
  for (auto && f : FENCE_list) {  // forall f : FENCE_list
    ZExprVec var16_L;
    for (auto && w : WRITE_list) {  // forall w : WRITE_list
      if  ( SameCoreStatic(w,f) == StaticResult::STATIC_FALSE ) continue;
      var16_L.push_back( z3::implies( PO ( w , f )  , HB ( __wfe_global( w) , f )  ) ); }
    var17 = Z3ForallList( var16_L);
    var18_L.push_back( var17); }
  var19 = Z3ForallList( var18_L);
  _constr.push_back( var19);
  // ----- AXIOM TSO_Fence END -----
  // ----- AXIOM TSO_RMW BEGIN -----
  ZExprVec var20_L;
  for (auto && i : RMW_list) {  // forall i : RMW_list
    var20_L.push_back( Sync ( i , __wfe_global( i) ) ); }
  var21 = Z3ForallList( var20_L);
  _constr.push_back( var21);
  // ----- AXIOM TSO_RMW END -----

  // TODO: Translate the functions

}

void Tso::SetLocalState(std::set<bool> ordered, ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ )
{

}

}


// ------------------------- ACCESSOR FUNCTIONs -------------------------------------- //
TraceStep & __wfe_global(TraceStep & ts)
{
  TsoTraceStep * _cts = dynamic_cast<TsoTraceStep>( &ts );
  ILA_ASSERT(_cts) << "MCM: trace step: "<< ts.name() << "has no attribute: wfe.global";
  return *( (_cts->wfe_global) .get() ) ;
}