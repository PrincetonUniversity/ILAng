/// \file
/// Source for implementation of MCM Axiom helpers

#include "ila/instr_lvl_abs.h"
#include "mcm/memory_model.h"

namespace ila {

/******************************************************************************/
// Helper Functions
/******************************************************************************/

z3::expr Z3Implies(const z3::expr &a, const z3::expr &b) { return z3::implies(a,b); }
z3::expr Z3And(const z3::expr &a, const z3::expr &b) { return a&&b; }


/******************************************************************************/
// Axiom Functions
/******************************************************************************/

/// This is to deal with forall (if does not exist, it should be true also)
z3::expr MemoryModel::Z3ForallList(const ZExprVec & l) {
  if ( l.size() == 0 )
    return ctx().bool_val(true); // forall x, (if does not exist, it should be true also)
  if ( l.size() == 1 )
    return l[0];
  z3::expr ret = l[0];
  auto it = l.begin();   ++it;
  for(;it!= l.end(); ++it)
    ret = ret && (*it);
  return ret;
}

/// This is to apply to exists, (if does not exist, it should be false)
z3::expr MemoryModel::Z3ExistsList(const ZExprVec & l) {
  if ( l.size() == 0 )
    return ctx().bool_val(false); // exists x, (if does not exist, it should be false)
  if ( l.size() == 1 )
    return l[0];
  z3::expr ret = l[0];
  auto it = l.begin();   ++it;
  for(;it!= l.end(); ++it)
    ret = ret || (*it);
  return ret;  
}

z3::expr MemoryModel::HB( TraceStep & l, TraceStep & r )
{
  return l.timestamp < r.timestamp;
}
z3::expr MemoryModel::PO( TraceStep & l, TraceStep & r )
{
  return SameCore(l,r) && HB(l,r);
}
z3::expr MemoryModel::Decode( TraceStep & l) {
  auto decodeExprAst = l.inst()->GetDecode();
  return l.ConvertZ3OnThisStep( decodeExprAst );
  /// NOTE: in fact, there may be also an extra_suffix
}
/*
z3::expr MemoryModel::MemVarSameAddress( const ExprPtr & l , const ExprPtr & r , const z3::expr &f, const z3::expr &t, TraceStep & tracel , TraceStep & tracer ) 
{
  if( l->is_var() || r->is_var() )
    return f;
  // Here we try to peel the mem op
  ILA_ASSERT( l->is_op() && r->is_op() ) << "Implementation bug: unable to derive z3 expression from AST about for SameAddress function, requiring AST to be ExprOp";
  std::shared_ptr<ExprOp> lptr = dynamic_pointer_cast<ExprOp>( l );
  std::shared_ptr<ExprOp> rptr = dynamic_pointer_cast<ExprOp>( r );
  // Both should be convertible to ExprOp
  ILA_ASSERT( lptr && rptr ) << "Implementation bug: unable to derive z3 expression from AST about for SameAddress function, requiring AST to be ExprOp";
  // Now we need to make sure : either it is a load or a store
  ILA_ASSERT( lptr->op_name() == "LOAD" || lptr->op_name() == "STORE" ) << "Implementation bug: unable to derive z3 expression from AST about for SameAddress function, requiring AST to be ExprOpLoad/Store";
  ILA_ASSERT( rptr->op_name() == "LOAD" || rptr->op_name() == "STORE" ) << "Implementation bug: unable to derive z3 expression from AST about for SameAddress function, requiring AST to be ExprOpLoad/Store";  
  // and not nested from here
  ILA_ASSERT( nested_finder_.NotNested(l) && nested_finder_.NotNested(r) ) << "Implementation bug: unable to derive z3 expression from AST about for SameAddress function, unable to handle nested MemOp";
  // So now we can extract the address field ( arg(1) ) // we don't even need to convert to the derived type
  auto laddr = l->arg(1);
  auto raddr = r->arg(1);

  return tracel.ConvertZ3OnThisStep(laddr) == tracer.ConvertZ3OnThisStep(raddr);
}
*/

z3::expr MemoryModel::MemVarSameAddress(
  const ExprPtr &leftWAddr, AddrDataVec & leftRAddrDataVec, 
  const ExprPtr &rightWAddr, AddrDataVec &rightRAddrDataVec, 
  TraceStep & traceL , TraceStep & traceR) // the last two parameters are just for invoking ConvertZ3OnThisStep
{
  z3::expr retVal = ctx().bool_val(true);
  bool RWMatchedFlag = false;

  if( (!leftWAddr) && leftRAddrDataVec.empty() )
    return retVal; // no constraints needed
  if( (!rightWAddr) && rightRAddrDataVec.empty() )  
    return retVal;

  if( leftWAddr && (!rightRAddrDataVec.empty()) ) {
    RWMatchedFlag = true;
    z3::expr match_of_addr_
    for( auto & addr_data_pair_ : rightRAddrDataVec ) {
      match_of_addr_ = match_of_addr_  || 
        ( traceL.ConvertZ3OnThisStep(leftWAddr) == traceR.ConvertZ3OnThisStep(addr_data_pair_.first) );
    }
    retVal = retVal && match_of_addr_; 
  }

  if( rightWAddr && (!leftRAddrDataVec.emtpy()) ) {
    RWMatchedFlag = true;
    z3::expr match_of_addr_
    for( auto & addr_data_pair_ : leftRAddrDataVec ) {
      match_of_addr_ = match_of_addr_  || 
        ( traceR.ConvertZ3OnThisStep(rightWAddr) == traceL.ConvertZ3OnThisStep(addr_data_pair_.first) ); // first is the address
    }
    retVal = retVal && match_of_addr_;  // add it to the constraints
    // so, we requestinng R-W && W-R matching, so it is important to provide hints if we don't want double match
  }
  // there should be nothing more than t in retVal
  if(!RWMatchedFlag) {
    // now we check for RR match or WW match
    if( leftWAddr && rightWAddr )  // WW matching
      retVal = traceL.ConvertZ3OnThisStep(leftWAddr) == traceR.ConvertZ3OnThisStep(rightWAddr);
    else { // RR matching
      for(auto & addr_data_pair_L : leftRAddrDataVec)
        for(auto & addr_data_pair_R : rightRAddrDataVec) {
          retVal = retVal ||
           ( traceL.ConvertZ3OnThisStep(addr_data_pair_L.first) == traceR.ConvertZ3OnThisStep(addr_data_pair_R.first) ) ;
          // we say some address should match
        }
    }
  }
  return retVal;
}


z3::expr MemoryModel::MemVarSameData(
  const std::pair<ExprPtr,ExprPtr> &leftAddrDataPair , AddrDataVec & leftRAddrDataVec, 
  const std::pair<ExprPtr,ExprPtr> &rightAddrDataPair, AddrDataVec & rightRAddrDataVec, 
  TraceStep & traceL , TraceStep & traceR) // the last two parameters are just for invoking ConvertZ3OnThisStep
{
  z3::expr retVal = ctx().bool_val(true);
  bool RWMatchedFlag = false;
   
  auto leftWAddr = leftAddrDataPair.first;
  auto leftWData = leftAddrDataPair.second;

  auto rightWAddr = rightAddrDataPair.first;
  auto rightWData = rightAddrDataPair.second;

  if( (!leftWData) && leftRAddrDataVec.empty() )
    return retVal; // no constraints needed
  if( (!rightWData) && rightRAddrDataVec.empty() )  
    return retVal;

  if( leftWData && (!rightRAddrDataVec.empty()) ) {
    RWMatchedFlag = true;
    z3::expr match_of_data_
    for( auto & addr_data_pair_ : rightRAddrDataVec ) {
      match_of_data_ = match_of_data_  && z3::implies(
          traceL.ConvertZ3OnThisStep(leftWAddr) == traceR.ConvertZ3OnThisStep(addr_data_pair_.first) 
          ,
          traceL.ConvertZ3OnThisStep(leftWData) == traceR.ConvertZ3OnThisStep(addr_data_pair_.second)          
        );
    }
    retVal = retVal && match_of_data_; 
  }

  if( rightWData && (!leftRAddrDataVec.emtpy()) ) {
    RWMatchedFlag = true;
    z3::expr match_of_data_
    for( auto & addr_data_pair_ : leftRAddrDataVec ) {
      match_of_data_ = match_of_data_  && z3::implies( 
        traceR.ConvertZ3OnThisStep(rightWAddr) == traceL.ConvertZ3OnThisStep(addr_data_pair_.first)
        , // =>
        ( traceR.ConvertZ3OnThisStep(rightWData) == traceL.ConvertZ3OnThisStep(addr_data_pair_.second) ) // first is the address
      );
    }
    retVal = retVal && match_of_data_;  // add it to the constraints
    // so, we requestinng R-W && W-R matching, so it is important to provide hints if we don't want double match
  }
  // there should be nothing more than t in retVal
  if(!RWMatchedFlag) {
    // now we check for RR match or WW match
    if( leftWData && rightWData )  // WW matching
      retVal = z3::implies(
        traceL.ConvertZ3OnThisStep(leftWAddr) == traceR.ConvertZ3OnThisStep(rightWAddr) 
        ,
        traceL.ConvertZ3OnThisStep(leftWData) == traceR.ConvertZ3OnThisStep(rightWData) );
    else { // RR matching
      for(auto & addr_data_pair_L : leftRAddrDataVec)
        for(auto & addr_data_pair_R : rightRAddrDataVec) {
          retVal = retVal &&
           z3::implies( 
            traceL.ConvertZ3OnThisStep(addr_data_pair_L.first) == traceR.ConvertZ3OnThisStep(addr_data_pair_R.first)
            ,
            traceL.ConvertZ3OnThisStep(addr_data_pair_L.second) == traceR.ConvertZ3OnThisStep(addr_data_pair_R.second) ) ;
          // we say some address should match
        }
    }
  }
  return retVal;
}


#define ARG_ADDR 1
#define ARG_DATA 2
ExprPtr MemoryModel::CheckAndPeel(const ExprPtr &e , const std::string & type, size_t argn)
{
  if ( !e->is_op() )
    return NULL;
  
  std::shared_ptr<ExprOp> ptr = dynamic_pointer_cast<ExprOp> ( e );
  if ( !ptr )
    return NULL;
  if( type != "" && ptr->op_name() != type)
    return NULL;

  if( ! nested_finder_.NotNested(e) )
    return NULL;

  if( e->arg_num() <= argn )
    return NULL;

  return e->arg(argn);
}

// so maybe, in the future, we will have SameAddress[ts1,ts2, mem]
// it should written as 
//    Forall s:STATE | Forall w:WRITE(s) | Forall r:READ(s) | SameAddress[w,r, s ]
// 
// z3::expr MemoryModel::SameAddress( TraceStep & l, TraceStep & r , const std::string & sname , AxiomFuncHint lhint, AxiomFuncHint rhint )
//

z3::expr MemoryModel::SameAddress( TraceStep & l, TraceStep & r , 
  const std::string & sname, 
  AxiomFuncHint lhint, AxiomFuncHint rhint )
{
  SameAddrDataSanityCheck(l,r,sname);  

  auto mem_var_left = l.inst()->host()->state(sname);
  if( ! ( mem_var_left->sort()->is_mem() ) )
    return ctx().bool_val(true); // skip if not a memory variable, that's enough, we are not requiring more constraints other than same name for bv or bool

  // Now: here is the most difficult thing 
  // we need to analyze the ast to get the address and data
  // and convert them to z3 expression
  auto mem_var_right = r.inst()->host()->state(sname);

  // find read and write addr expr for left and right
  // we also need to take into consideration of the hints
  const AddrDataVec emtpyReadList;

  ExprPtr leftW; // Future Work: Store(Store(Store())) AST support (multi-store)
  {
    // disable write expression if we are looking it as a read
    ExprPtr wexpr = ( lhint == AxiomFuncHint::HINT_READ ) ? NULL : l.inst()->GetUpdate(sname);
    if (wexpr) { // if it is updated
      leftW = CheckAndPeel(wexpr, "STORE", ARG_ADDR);
      ILA_ASSERT(leftW) << "Implementation bug: unable to auto derive addr/data field from MemUpdate Function";
    }
  } 
  const AddrDataVec & leftR = ( lhint == AxiomFuncHint::HINT_WRITE ) ? 
                              emtpyReadList :
                              mem_load_expr_finder_.FindAddrDataPairVecInInst( l.inst() , sname );

  ExprPtr rightW;
  {
    ExprPtr wexpr = ( rhint == AxiomFuncHint::HINT_READ ) ? NULL : r.inst()->GetUpdate(sname);
    if (wexpr) { // if it is indeed updated
      rightW = CheckAndPeel(wexpr, "STORE", ARG_ADDR);
      ILA_ASSERT(rightW) << "Implementation bug: unable to auto derive addr/data field from MemUpdate Function";
    }
  } 
  const AddrDataVec & rightR = ( rhint == AxiomFuncHint::HINT_WRITE ) ? 
                              emtpyReadList :
                              mem_load_expr_finder_.FindAddrDataPairVecInInst( r.inst() , sname );

  // now we need to decide how to pair the two 
  return MemVarSameAddress( leftW, leftR, rightW, rightR , l, r );
}


z3::expr MemoryModel::NonMemVarSameData(
  TraceStep & l, TraceStep & r,
  const std::string & sname,
  AxiomFuncHint lhint, AxiomFuncHint rhint)
{ 
  bool RWMatchedFlag = false;
  z3::expr retVal = ctx().bool_val(true);


  auto var_left = l.inst()->host()->state(sname);
  auto var_right = r.inst()->host()->state(sname);

  bool leftW = l.Access( AccessType::WRITE, sname ) && lhint != AxiomFuncHint::READ; // l shoud be an instruction event
  bool leftR = l.Access( AccessType::READ , sname ) && lhint != AxiomFuncHint::WRITE;

  bool rightW = r.Access( AccessType::WRITE, sname ) && rhint != AxiomFuncHint::READ; // r shoud be an instruction event
  bool rightR = r.Access( AccessType::READ , sname ) && rhint != AxiomFuncHint::WRITE;

  if (!leftW && !leftR)
    return ctx().bool_val(true);
  if (!rightW && !rightR)
    return ctx().bool_val(true);

  if (leftW && rightR) {
    RWMatchedFlag = true;
    retVal = retVal && ( l.ConvertZ3OnThisStep( l.inst()->GetUpdate(sname) ) == r.ConvertZ3OnThisStep(var_right) );
  }
  if (rightW && leftR) {
    RWMatchedFlag = true;
    retVal = retVal && ( r.ConvertZ3OnThisStep( r.inst()->GetUpdate(sname) ) == l.ConvertZ3OnThisStep(var_left) );
  }

  if( !RWMatchedFlag ) {
    if (leftW && rightW) {
      retVal = retVal && ( l.ConvertZ3OnThisStep( l.inst()->GetUpdate(sname) ) == r.ConvertZ3OnThisStep( r.inst()->GetUpdate(sname) ) );
    }
    if (leftR && rightR) {
      retVal = retVal && ( l.ConvertZ3OnThisStep( var_left ) == r.ConvertZ3OnThisStep( var_left) );
    }
  }
  return retVal;

  // leftR and leftW empty
  // rightR and rightW empty
  // leftR and rightW ?
  // leftW and rightR ?
  // finally RR/WW
}

z3::expr MemoryModel::SameData( TraceStep & l, TraceStep & r ,
  const std::string & sname,
  AxiomFuncHint lhint, AxiomFuncHint rhint)
{
    // First of all, we need to find the same address part and for each of them
  SameAddrDataSanityCheck(l,r,sname);

  auto mem_var_left = l.inst()->host()->state(sname);
  auto mem_var_right = r.inst()->host()->state(sname);
  if( ! ( mem_var_left->sort()->is_mem() ) )  {
    return NonMemVarSameData( l,r,sname,lhint, rhint );
    // skip if not a memory variable,  that's enough, we are not requiring more constraints other than the same data
  }

  // Now: here is the most difficult thing 
  // we need to analyze the ast to get the address and data
  // and convert them to z3 expression

  // find read and write addr expr for left and right
  // we also need to take into consideration of the hints
  const AddrDataVec emtpyReadList;

  ExprPtr leftWAddr;
  ExprPtr leftWData;
  {
    // disable write expression if we are looking it as a read
    ExprPtr wexpr = ( lhint == AxiomFuncHint::HINT_READ ) ? NULL : l.inst()->GetUpdate(sname);
    if (wexpr) { // if it is updated
      leftWAddr = CheckAndPeel(wexpr, "STORE", ARG_ADDR);
      leftWData = CheckAndPeel(wexpr, "STORE", ARG_DATA);
      ILA_ASSERT(leftWAddr && leftWData) << "Implementation bug: unable to auto derive addr/data field from MemUpdate Function";
    }
  } 
  const AddrDataVec & leftR = ( lhint == AxiomFuncHint::HINT_WRITE ) ? 
                              emtpyReadList :
                              mem_load_expr_finder_.FindAddrDataPairVecInInst( l.inst() , sname );

  ExprPtr rightWAddr;
  ExprPtr rightWData;
  {
    ExprPtr wexpr = ( rhint == AxiomFuncHint::HINT_READ ) ? NULL : r.inst()->GetUpdate(sname);
    if (wexpr) { // if it is indeed updated
      rightWAddr = CheckAndPeel(wexpr, "STORE", ARG_ADDR);
      rightWData = CheckAndPeel(wexpr, "STORE", ARG_DATA);
      ILA_ASSERT(rightWAddr && rightWData) << "Implementation bug: unable to auto derive addr/data field from MemUpdate Function";
    }
  } 
  const AddrDataVec & rightR = ( rhint == AxiomFuncHint::HINT_WRITE ) ? 
                              emtpyReadList :
                              mem_load_expr_finder_.FindAddrDataPairVecInInst( r.inst() , sname );

  // now we need to decide how to pair the two 
  return MemVarSameData( {leftWAddr, leftWData}, leftR, {rightWAddr, rightWData}, rightR , l, r );
}



bool MemoryModel::SameCore( TraceStep & l, TraceStep & r) {
  // I hope this won't be a problem (it may require ctx to create constant)

  std::string & left =  l.inst()->host()->name().str();
  std::string & right = r.inst()->host()->name().str();
  if (left == right)
    return true;
  return false;
}

void MemoryModel::SameAddrDataSanityCheck( TraceStep & l, TraceStep & r , const std::string & sname ) {
  // Need to do optimization here (make a lookup table)
  static std::map<std::string, StateNameSet> l_r_names_to_state;
  auto _lookup_index = l.name() + "&" r.name();

  if ( IN(_lookup_index, l_r_names_to_state ) ) {
    ILA_ASSERT( IN(sname,l_r_names_to_state[_lookup_index]) ) 
      << "Axiom bug: you need to first choose the trace steps accessing the shared state named: " << sname 
      << ", and please be sure they have the same SORT";
    return;
  }

  StateNameSet left; // = read UNION write 
  switch( l.type() ) {
    case TraceStepType::FACET_EVT: UNION(l._read_state_set , l._write_state_set, left );  break;
    case TraceStepType::INST_EVT : UNION(l._inst_read_set  , l._inst_write_set,  left );  break; // it should be the instruction,  not the facet event
    default:
      ILA_ASSERT(false) << "TraceStepType is neither facet event or instruction event.";
  }

  StateNameSet right; // = read UNION write 
  switch( r.type() ) {
    case TraceStepType::FACET_EVT: UNION(r._read_state_set , r._write_state_set, right );  break;
    case TraceStepType::INST_EVT : UNION(r._inst_read_set  , r._inst_write_set,  right );  break;
    default:
      ILA_ASSERT(false) << "TraceStepType is neither facet event or instruction event.";
  }

  StateNameSet intersect;
  INTERSECT( left, right, intersect );

  StateNameSet & same_type_intersect = l_r_names_to_state[_lookup_index];
  for(auto & state_name : intersect) {

    /// Implementational bug: input 
    auto left_state_ptr  = l.inst()->host()->state(state_name);
    auto right_state_ptr = r.inst()->host()->state(state_name);

    if( left_state_ptr->sort() == right_state_ptr->sort()  ) 
      same_type_intersect.insert(state_name); // skip sort
  }

  ILA_ASSERT( IN(sname,same_type_intersect) ) 
    << "Axiom bug: you need to first choose the trace steps accessing the shared state named: " << sname 
    << ", and please be sure they have the same SORT";

}



} // namespace ila