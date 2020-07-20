/// \file
/// Header for AST helpers (some helper classes to handle AST)

#ifndef ILANG_MCM_AST_HELPER_H__
#define ILANG_MCM_AST_HELPER_H__

#include <functional>
#include <set>
#include <unordered_map>
#include <utility>

#include "ilang/ila/instr_lvl_abs.h"
#include "ilang/vtarget-out/directive.h"

/// \namespace ilang
namespace ilang {

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

template <class T> class VarUseFinder {
public:
  /// Type of vector of ExprPtr with is_var() == true
  typedef std::set<T> VarUseList;
  /// Type of the function to process ExprPtr to T
  typedef std::function<T(const ExprPtr&)> ProcessFuncType;
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor: do nothing
  VarUseFinder(ProcessFuncType f) : procFunc(f) {}
  /// Default destructor: do nothing
  ~VarUseFinder() {}

  // ------------------------- METHODS -------------------------------------- //
  /// Find variable uses for an expression
  void Traverse(const ExprPtr& expr, VarUseList& uses);
  /// Find variable uses for an instruction (update + decode)
  void Traverse(const InstrPtr& i, VarUseList& uses);
  /// Find variable uses for an ila (instruction + fetch + valid )
  void Traverse(const InstrLvlAbsPtr& i, VarUseList& uses);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  ProcessFuncType procFunc;
}; // class VarUseFinder

/// \brief Class of traversing to avoid nested memory access in address
class NestedMemAddrDataAvoider {
  /// Type for cacheing the AST checking result.
  typedef std::unordered_map<Expr*, bool>
      HashTable; // here we do use the raw pointer
public:
  // ------------------------- CONSTRUCTOR ---------------------------------- //
  NestedMemAddrDataAvoider() : InAddrOrData(false) {}
  // ------------------------- METHODS -------------------------------------- //
  /// To check for a mem var, if its ast does not contain nested mem
  /// address/data access In its nested check, it should check go into all
  /// types.
  bool NotNested(const ExprPtr& node);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The map for AST nodes.
  HashTable map_;
  /// The mode whether we are in addr or data AST
  bool InAddrOrData;
}; // class NestedMemAddrDataAvoider

/// \brief Function to deal with Ite(c, v, apply(__unknown__) );
bool getIteUnknownCondVal(const ExprPtr& e, ExprPtr& c, ExprPtr& v);

/// \brief Class of traversing to find the application of functions in an AST
class FunctionApplicationFinder {
protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// the functions used in app_func
  std::set<std::shared_ptr<Func>> _func_refs;
  /// record whether a node has been visited
  std::set<Expr*> visited;
  /// does a node contain a funcapp
  void hasFuncAppOnNode(const ExprPtr& e);
  /// does a tree contain funcapps?
  void hasFuncApp(const ExprPtr& expr);

public:
  // ------------------------- CONSTRUCTOR ---------------------------------- //
  FunctionApplicationFinder(const ExprPtr& expr);
  // get the set of the pointer of the functions
  const std::set<std::shared_ptr<Func>> GetReferredFunc() const;
}; // class FunctionApplicationFinder

#if 0
/// \brief Class of traversing to detect nested store
class PureNestedStoreDetector {
  /// Type of vector of (address, data) pair
  typedef std::vector<std::pair<ExprPtr, ExprPtr>>
      AddrDataVec; // (addr,data) list

  /// Type of map, from points of expression to the pair collected so far for
  /// the sub tree
  typedef std::unordered_map<Expr*, AddrDataVec>
      HashTable; // here we do use the raw pointer public:

  // ------------------------- METHODS -------------------------------------- //
  /// \brief To decide if a expr contains nested store or not
  bool isNestedStore(const ExprPtr&);
  /// \brief Get the address/data pair of a given expr ptr
  const AddrDataVec& getStoreAddrDataVec(const ExprPtr&);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  // a map
  HashTable map_;
}
#endif

#if 0
struct MRF_HASH_FUNC {
  std::size_t operator()(const std::pair<TraceStep*, Expr*>& p) const {
    return std::hash()(p.first) ^ std::hash()(p.second);
  }
};
#endif

#if 0
/// \brief class MemReadFinder(MRF) to find (only find) the address and data
part that exists in a trace step ? class MemReadFinder {
public:
  // Type of (addr,data) pair list
  typedef std::vector<std::pair<ExprPtr, ExprPtr>> AddrDataVec;

private:
  /// Type of the Hash Key
  typedef Instr*
      MRFHashKey; // typedef std::pair< TraceStep *, Expr * > MRFHashKey;
  /// Type of the dictionary value
  typedef std::unordered_map<std::string, AddrDataVec>
      MRFVal; // statename -> (addr,data) list
  /// Type for caching the result of the search: Instr * -> (statename ->
  /// (addr,data) list ), for a instruction, for a given state, what are the
  /// addr/data that is read
  typedef std::unordered_map<MRFHashKey, MRFVal> MRFHashTable;

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// A wrapper of calling DepthFirstVisit with a function object
  void FindAddrDataPairVecInExpr(const ExprPtr& node, MRFVal& nad_map_);
  /// a private function to be called to handle a node. The traversal is
  /// original in the Expr (template member function: DepthFirstVisit)
  void VisitNode(const ExprPtr& node, MRFVal& nad_map_);

public:
  /// for an instruction, for a state, return the reference to the (addr,data)
  /// pair list it has no way to check if sname is memvar or not, so it needs to
  /// be guaranteed that it is a memver's name
  const AddrDataVec& FindAddrDataPairVecInInst(const InstrPtr& instr,
                                               const std::string& sname);

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor, it needs a NestedMemAddrDataAvoider reference (so we can
  /// share among different MemReadFinder)
  MemReadFinder(NestedMemAddrDataAvoider& n) : nested_finder_(n) {}

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The table to cache the results
  MRFHashTable map_;
  /// reference to the shared nested avoider
  NestedMemAddrDataAvoider& nested_finder_;

}; // class MemReadFinder
#endif

} // namespace ilang

#endif // ILANG_MCM_AST_HELPER_H__
