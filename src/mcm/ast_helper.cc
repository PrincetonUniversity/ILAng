/// \file
/// Source for implementation of MCM AST helpers
#include <functional>
#include <memory>
#include <string>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/mcm/memory_model.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>

namespace ilang {

/******************************************************************************/
// Helper Class: VarUseFinder
/******************************************************************************/

template <class T>
void VarUseFinder<T>::Traverse(const ExprPtr& expr, VarUseList& uses) {
  size_t num = expr->arg_num();

  // DIRTY FIX: we need to rule out the possibility that
  // m1 <= STORE(m1, ADDR, DATA) , here m1 access is not a use of mem variable
  size_t start = 0;
  if (expr->is_op()) {
    auto ptr = std::dynamic_pointer_cast<ExprOp>(expr);
    ILA_NOT_NULL(
        ptr); // << "Implementation bug: expr type and type name do not match!";
    if (ptr->op_name() == "STORE" && ptr->arg(0)->is_var())
      start = 1; // skip the var field of STORE(var,addr, data)
  }

  for (size_t i = start; i < num; ++i)
    Traverse(expr->arg(i), uses);
  if (expr->is_var())
    uses.insert(procFunc(expr));
}

// collect variable usage of an instruction (decode/update)
template <class T>
void VarUseFinder<T>::Traverse(const InstrPtr& i, VarUseList& uses) {
  ILA_NOT_NULL(i);
  auto decode_expr_ = i->decode();
  ILA_NOT_NULL(decode_expr_); // << "The decode function is not set for:
                              // instr:"<< i->name().str() << " of ILA: "<<
                              // i->host()->name().str();
  Traverse(decode_expr_, uses);

  Instr::StateNameSet instr_writes_ =
      i->updated_states(); // get the set of updated state names
  for (auto& state_name_ : instr_writes_) {
    auto update_expr_ = i->update(state_name_);
    ILA_NOT_NULL(update_expr_); // << "The update function is NULL for: instr"<<
                                // i->name().str() << " of ILA: "<<
                                // i->host()->name().str() << " on state " <<
                                // state_name_;

    Traverse(update_expr_, uses); // traverse the update function
  }
}
// collect variable usage of an ila (fetch/valid/instructions)
// question: maybe also init?
template <class T>
void VarUseFinder<T>::Traverse(const InstrLvlAbsPtr& i, VarUseList& uses) {
  Traverse(i->fetch(), uses);
  Traverse(i->valid(), uses);

  size_t num = i->instr_num();
  for (size_t idx = 0; idx != num; ++idx)
    Traverse(i->instr(idx), uses);
}

// let's instantiate it so it will not get linker error
template class VarUseFinder<std::string>;
template class VarUseFinder<ExprPtr>;

/******************************************************************************/
// Helper Class: NestedMemAddrDataAvoider
/******************************************************************************/

// no need now
// NestedMemAddrDataAvoider::HashTable NestedMemAddrDataAvoider::map_; // it is
// shared by the whole project

bool NestedMemAddrDataAvoider::NotNested(const ExprPtr& node) {
  // If we already seen this ast before and know it is nested
  auto pos = map_.find(node.get());
  if (pos != map_.end()) {
    ILA_ASSERT(pos->second == false)
        << "Bug: An error occurred in MCM AST helper class.";
    return false;
  }

  size_t num = node->arg_num();
  auto ldop_ptr = std::dynamic_pointer_cast<ExprOpLoad>(node);
  auto stop_ptr = std::dynamic_pointer_cast<ExprOpStore>(node);

  if (ldop_ptr) {       // here we are in a memLoad's
    if (InAddrOrData) { // if we are already in a memOp's data/addr
      return false;
    }
    InAddrOrData = true;
  } else if (stop_ptr) { // here we are in a memStore's
    if (InAddrOrData) {  // if we are already in a memOp's data/addr
      return false;
    }
    InAddrOrData = true;
  }

  for (size_t i = 0; i != num; ++i) {
    auto argi = node->arg(i);

    /*
    auto pos = map_.find( argi.get() );
    if ( pos != map_.end() ) { // if the subtree is already itself nested,
      ILA_ASSERT( pos.second == false ) << "Bug: An error occurred in MCM AST
    helper class."; map_.insert( {node.get() , false} ); // we can conclude this
    AST is nested.
      // So it actually propagate the false bottom-up the tree
      return false;
    }*/

    if (!NotNested(argi)) {
      map_.insert({node.get(), false}); // we can conclude this AST is nested.
      return false;
    }
  }

  if (ldop_ptr || stop_ptr)
    InAddrOrData = false; // reset the flag
  return true;
}

/******************************************************************************/
// Helper Class: FunctionApplicationFinder
/******************************************************************************/

void FunctionApplicationFinder::hasFuncAppOnNode(const ExprPtr& e) {
  if (!e->is_op())
    return;
  std::shared_ptr<ExprOp> eop = std::dynamic_pointer_cast<ExprOp>(e);
  if (!(eop && eop->op_name() == "APP"))
    return;
  std::shared_ptr<ExprOpAppFunc> apply_op =
      std::dynamic_pointer_cast<ExprOpAppFunc>(eop);
  if (!apply_op)
    return;
  // extract function and added it to the set
  _func_refs.insert(apply_op->func());
}


void FunctionApplicationFinder::hasFuncApp(const ExprPtr& expr) {
  if (IN(expr.get(),visited))
    return;
  visited.insert(expr.get());
  for (size_t i = 0; i != expr->arg_num(); i++) {
    const ExprPtr arg_i = expr->arg(i);
    hasFuncApp(arg_i);
  }
  hasFuncAppOnNode(expr);
}

FunctionApplicationFinder::FunctionApplicationFinder(const ExprPtr& expr) {
  hasFuncApp(expr);
}
// get the set of the pointer of the functions
const std::set<std::shared_ptr<Func>>
FunctionApplicationFinder::GetReferredFunc() const {
  return _func_refs;
}



bool getIteUnknownCondVal(const ExprPtr & e, ExprPtr & c, ExprPtr & v) {
  if (!e->is_op())
    return false;
  std::shared_ptr<ExprOp> eop = std::dynamic_pointer_cast<ExprOp>(e);
  if (!(eop && eop->op_name() == "ITE"))
    return false;
  ILA_ASSERT(eop->arg_num() == 3);
  { // test arg 1
    std::shared_ptr<ExprOp> arg1 = std::dynamic_pointer_cast<ExprOp>(eop->arg(1));
    if ( (arg1 && arg1->op_name() == "APP") ) {
      std::shared_ptr<ExprOpAppFunc> apply_op_arg1 =
        std::dynamic_pointer_cast<ExprOpAppFunc>(arg1);
      if ( StateMappingDirectiveRecorder::isSpecialUnknownFunction(apply_op_arg1->func())) {
        c = eop->arg(0);
        v = eop->arg(2);
        return true;
      }
    }
  } // end test arg 1

  { // test arg 2
    std::shared_ptr<ExprOp> arg2 = std::dynamic_pointer_cast<ExprOp>(eop->arg(2));
    if ( (arg2 && arg2->op_name() == "APP") ) {
      std::shared_ptr<ExprOpAppFunc> apply_op_arg2 =
        std::dynamic_pointer_cast<ExprOpAppFunc>(arg2);
      if ( StateMappingDirectiveRecorder::isSpecialUnknownFunction(apply_op_arg2->func())) {
        c = eop->arg(0);
        v = eop->arg(1);
        return true;
      }
    }
  } // end test arg 2
  
  return false;
}

/******************************************************************************/
// Helper Class: NestedMemAddrDataAvoider
/******************************************************************************/
/* Seems not used, comment out for now
  // we already guarantee that the outer is memop
  bool PureNestedStoreDetector::isNestedStore(const ExprPtr & node, ... ?)
  {
    if ( node->is_var() ) {
      map_[ node.get() ];
      return true;
    }
  }
  const AddrDataVec & PureNestedStoreDetector::getStoreAddrDataVec(const ExprPtr
  &node)
  {

  }
*/
/******************************************************************************/
// Helper Class: MemReadFinder
/******************************************************************************/
/*
void MemReadFinder::FindAddrDataPairVecInTraceStep(const TraceStep & ts, const
std::string &sname) { if ( ts.is_final_tracestep() ) FindAddrDataPairVecInExpr(
ts.final_property() ); else // for facet/... FindAddrDataPairVecInInst(
ts.inst() );
}

void MemReadFinder::FindAddrDataPairVecInExpr(const ExprPtr &node, MRFVal &
nad_map_)
{
  // read from the map_
  // I hope the above will go through, so we don't need to create
  // a operator() that looks strange, and we have no idea what it does
  std::function<void(const ExprPtr &)> func =
std::bind(&MemReadFinder::VisitNode, this, std::placeholders::_1, nad_map_ );
  node->DepthFirstVisit( func  );
}

void MemReadFinder::VisitNode(const ExprPtr &node, MRFVal & nad_map_)
{
  if( node->is_op() ) {
    std::shared_ptr<ExprOp> ptr = std::dynamic_pointer_cast<ExprOp> ( node );
    ILA_ASSERT( ptr );
    if( ptr->op_name() == "LOAD" ) {
      ILA_ASSERT( nested_finder_.NotNested(node) ) << "Implementation bug:
unable to auto-generate addr/data field from AST : nested Load/Store"; auto
mem_var = node->arg(0); std::string  mem_var_name = mem_var->name().str(); auto
addr    = node->arg(1); // we assume it is well-formed auto data    = node;
      // insert to the map
      nad_map_[ mem_var_name ].push_back( { addr , data } );
    }
  }
}


const MemReadFinder::AddrDataVec &
MemReadFinder::FindAddrDataPairVecInInst(const InstrPtr &instr, const
std::string &sname)
{
  auto pos = map_.find( instr.get() );
  MRFVal * nad_map_ptr; // sname->pass
  if( pos == map_.end() ) {
    // if it has not been cached
    MRFVal & item = map_[ instr.get() ]; // this should create an empty sub-map
    FindAddrDataPairVecInExpr( instr->decode(), item );

    Instr::StateNameSet snames;
    instr->GetUpdatedStates(snames);
    for(auto & name : snames)
      FindAddrDataPairVecInExpr( instr->GetUpdate(name) , item );
    nad_map_ptr = &item;
  }
  else
    nad_map_ptr = & (pos->second);

  auto ad_vec = nad_map_ptr->find(sname);
  if( ad_vec != nad_map_ptr->end() ) {
    // Yes, it contains memr name
    return ad_vec->second;
  }
  else {
    // Else,
    return (*nad_map_ptr)[ sname ]; //so it will create an empty list? Yes
  }
}
*/

} // namespace ilang
