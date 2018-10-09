/// \file
/// Header for AST helpers (some helper classes to handle AST)

#ifndef AST_HELPER_H__
#define AST_HELPER_H__

#include <unordered_map>
#include <utility>

/// \namespace ila
namespace ila {


/******************************************************************************/
// Helper Class
/******************************************************************************/

/// \brief Class of finding variable uses.
/// So that we don't need to create pi variables
/// for unused state variables.
/// FIXME: currently there is no need to 
/// make a class for it, but in the future it is 
/// possible to use a hash table to avoid traverse
/// the same sub-tree twice.
// T can be ExprPtr or std::string
// C is the converter from ExprPtr to T
template <class T, typename C> 
class VarUseFinder {
public:
  /// Type of vector of ExprPtr with is_var() == true
  typedef std::set<T> VarUseList;
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor: do nothing
  VarUseFinder() {}
  /// Default destructor: do nothing
  ~VarUseFinder() {}

  // ------------------------- METHODS -------------------------------------- //
  /// Find variable uses for an expression
  void Traverse(const ExprPtr & expr, VarUseList & uses );
  /// Find variable uses for an instruction (update + decode)
  void Traverse(const InstrPtr & i, VarUseList & uses );
  /// Find variable uses for an ila (instruction + fetch + valid )
  void Traverse(const InstrLvlAbsPtr & i, VarUseList & uses );

}; // class VarUseFinder


/// \brief Class of traversing to avoid nested memory access in address
class NestedMemAddrDataAvoider {
  /// Type for cacheing the AST checking result.
  typedef std::unordered_map<Expr *, bool> HashTable; // here we do use the raw pointer
public:
  // ------------------------- CONSTRUCTOR ---------------------------------- //
  NestedMemAddrDataAvoider() : InAddrOrData(false) { }
  // ------------------------- MEMBERS -------------------------------------- //
  /// To check for a mem var, if its ast does not contain nested mem address/data access
  /// In its nested check, it should check go into all types.
  bool NotNested(const ExprPtr node);
private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The map for AST nodes.
  HashTable map_;
  /// The mode whether we are in addr or data AST
  bool InAddrOrData;
}; // class NestedMemAddrDataAvoider

class PureNestedStoreDetector {
  typedef std::vector<ExprPtr,ExprPtr> > AddrDataVec; // (addr,data) list
  typedef std::unordered_map<Expr *, AddrDataVec> HashTable; // here we do use the raw pointer
public:
  bool isNestedStore(const ExprPtr &);
  const AddrDataVec & getStoreAddrDataVec(const ExprPtr &);
private:
  HashTable map_;
}

/*
struct MRF_HASH_FUNC {
  std::size_t operator() (const std::pair<TraceStep *, Expr *> & p) const {
    return std::hash()(p.first) ^ std::hash()(p.second);
  }
};
*/


/// \brief class MemReadFinder(MRF) to find (only find) the address and data part that exists in a trace step?
class MemReadFinder {
  /// Type of the Hash Key
  typedef Instr *  MRFHashKey; // typedef std::pair< TraceStep *, Expr * > MRFHashKey;

  typedef std::vector<ExprPtr,ExprPtr> > AddrDataVec; // (addr,data) list
  /// Type of the dictionary value
  typedef std::unordered_map<std::string,AddrDataVec> MRFVal;  // statename -> (addr,data) list
  /// Type for caching the result of the search
  typedef std::unordered_map<MRFHashKey, MRFVal> MRFHashTable; // Instr * -> (statename -> (addr,data) list )
public:
  // ------------------------- MEMBERS -------------------------------------- //
  /// 
  void FindAddrDataPairVecInExpr(const ExprPtr &node, MRFVal & nad_map_);
  /// 
  void VisitNode(const ExprPtr &node, MRFVal & nad_map_);
  ///
  const AddrDataVec & FindAddrDataPairVecInInst(const InstrPtr &instr, const std::string &sname);

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  MemReadFinder(NestedMemAddrDataAvoider & n) : nested_finder_(n) {}

private:
  // ------------------------- MEMBERS -------------------------------------- //
  MRFHashTable map_;
  NestedMemAddrDataAvoider & nested_finder_;

}; // class MemReadFinder

} // namespace ila

#endif // AST_HELPER_H__

