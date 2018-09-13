/// \file
/// Source for implementation of MCM AST helpers

#include <functional>

#include "ila/instr_lvl_abs.h"
#include "mcm/memory_model.h"

namespace ila {

    /******************************************************************************/
    // Helper Class: VarUseFinder
    /******************************************************************************/

    template <class T, typename C> 
    void VarUseFinder::Traverse(const ExprPtr & expr, VarUseList & uses ) {
      size_t num = expr->arg_num();
      for (size_t i = 0; i != num; ++i) 
        Traverse( expr->arg(i) );
      if ( expr->is_var() )
        uses.push_back( C(expr) );
    }

    template <class T, typename C> 
    void VarUseFinder::Traverse(const InstrPtr & i, VarUseList & uses ) {
      Traverse( i->GetDecode , uses);

      StateNameSet instr_writes_ = i->GetUpdatedStates(); // get the set of updated state names
      for (auto & state_name_ : instr_writes_) 
        Traverse( i->GetUpdate(state_name_) , uses ); // traverse the update function
    }

    template <class T, typename C> 
    void VarUseFinder::Traverse(const InstrLvlAbsPtr & i, VarUseList & uses ) {
      Traverse(i->fetch() , uses);
      Traverse(i->valid() , uses);

      size_t num = i->instr_num();
      for (size_t idx = 0; idx != num ; ++ idx) 
        Traverse(i->instr(idx) , uses);
    }

    std::string ExprPtr2Name(const ExprPtr & e) {
      return e->name();
    }


    /******************************************************************************/
    // Helper Class: NestedMemAddrDataAvoider
    /******************************************************************************/

    // no need now
    // NestedMemAddrDataAvoider::HashTable NestedMemAddrDataAvoider::map_; // it is shared by the whole project

    bool NestedMemAddrDataAvoider::NotNested(const ExprPtr node)
    {
      // If we already seen this ast before and know it is nested
      auto pos = map_.find( node.get() );
      if( pos != map_.end() ) {
        ILA_ASSERT( pos.second == false ) << "Bug: An error occurred in MCM AST helper class.";
        return false;
      }

      size_t num = node->arg_num();
      auto ldop_ptr = dynamic_pointer_cast<ExprOpLoad>(node);
      auto stop_ptr = dynamic_pointer_cast<ExprOpStore>(node);

      if( ldop_ptr ) {     // here we are in a memLoad's
        if(InAddrOrData) { // if we are already in a memOp's data/addr
          return false;
        }
        InAddrOrData = true;
      }
      else if( stop_ptr ) { // here we are in a memStore's
        if(InAddrOrData) {  // if we are already in a memOp's data/addr
          return false;
        }
        InAddrOrData = true;
      }

      for (size_t i = 0; i != num; ++i) {
        auto argi = node->arg(i);

        /*
        auto pos = map_.find( argi.get() );
        if ( pos != map_.end() ) { // if the subtree is already itself nested,
          ILA_ASSERT( pos.second == false ) << "Bug: An error occurred in MCM AST helper class.";
          map_.insert( {node.get() , false} ); // we can conclude this AST is nested.
          // So it actually propagate the false bottom-up the tree
          return false;
        }*/

        if( ! NotNested( argi ) ) {
          map_.insert( {node.get() , false} ); // we can conclude this AST is nested.
          return false;
        }
      }
      
      if( ldop_ptr || stop_ptr )
        InAddrOrData = false; // reset the flag
      return true;
    }
    

  void MemReadFinder::FindAddrDataPairVecInExpr(const ExprPtr &node, MRFVal & nad_map_)
  {
    // read from the map_
    node->DepthFirstVisit( std::bind(&MemReadFinder::VisitNode, this, _1, nad_map_ )  );
  }

  void MemReadFinder::VisitNode(const ExprPtr &node, MRFVal & nad_map_)
  {
    if( node->is_op() ) {
      std::shared_ptr<ExprOp> ptr = dynamic_pointer_cast<ExprOp> ( node );
      ILA_ASSERT( ptr );
      if( ptr->op_name() == "LOAD" ) {
        ILA_ASSERT( nested_finder_.NotNested(node) ) << "Implementation bug: unable to auto-generate addr/data field from AST : nested Load/Store";
        auto mem_var = node->arg(0);
        std::string  mem_var_name = mem_var->name().str();
        auto addr    = node_>arg(1); // we assume it is well-formed 
        auto data    = node;
        // insert to the map
        nad_map_[ mem_var_name ].push_back( { addr , data } );
      }
    }
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


  const AddrDataVec & MemReadFinder::FindAddrDataPairVecInInst(const InstrPtr &instr, const std::string &sname)
  {
    auto pos = map_.find( instr.get() );
    MRFVal * nad_map_ptr; // sname->pass
    if( pos == map_.end() ) {
      // if it has not been cached
      MRFVal & item = map_[ instr.get() ]; // this should create an empty sub-map
      FindAddrDataPairVecInExpr( instr->GetDecode(), item );

      StateNameSet snames;
      instr->GetUpdatedStates(snames);
      for(auto & name : snames) 
        FindAddrDataPairVecInExpr( instr->GetUpdate(name) , item );
      nad_map_ptr = &item;
    }
    else
      nad_map_ptr = & (pos.second);

    auto ad_vec = nad_map_ptr->find(sname);
    if( ad_vec != nad_map_ptr->end() ) {
      // Yes, it contains memr name
      return ad_vec.second();
    }
    else {
      // Else, 
      return (*nad_map_ptr)[ sname ]; // I hope this would be fine
    }
  }

} // namespace ila