/// \file
/// Header for the class ExprSimplifier

#ifndef __SIMPLIFY_H__
#define __SIMPLIFY_H__

#include "ila/expr_fuse.h"
#include <unordered_map>

/// \namespace ila
namespace ila {

/// \class ExprSimplify
/// The simplify the AST tree by sharing nodes based on the hash value.
class ExprSimplify {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  ExprSimplify();
  /// Default destructor.
  ~ExprSimplify();

  /// \def HashTable
  typedef std::map<std::string, ExprPtr> HashTable;
  // std::unordered_map<AstHash, ExprPtr> HashTable;

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// Reset the hash table
  void Reset();
  /// Simplify the AST node.
  ExprPtr Simplify(const ExprPtr node);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The map for AST nodes.
  HashTable map_;

  // ------------------------- HELPERS -------------------------------------- //
}; // class ExprSimplify

} // namespace ila

#endif // __SIMPLIFY_H__

