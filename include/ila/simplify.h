/// \file
/// Header for the class ExprSimplifier

#ifndef __SIMPLIFY_H__
#define __SIMPLIFY_H__

#include "ila/expr_fuse.h"
#include <unordered_map>

/// \namespace ila
namespace ila {

/// \brief The simplify the AST tree by sharing nodes based on the hash value.
class ExprSimplifier {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  ExprSimplifier();
  /// Default destructor.
  ~ExprSimplifier();

  /// Type for cacheing the AST node hashing.
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
}; // class ExprSimplifier

} // namespace ila

#endif // __SIMPLIFY_H__

