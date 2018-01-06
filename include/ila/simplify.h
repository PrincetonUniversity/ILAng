/// \file
/// Header for the class ExprMngr

#ifndef __SIMPLIFY_H__
#define __SIMPLIFY_H__

#include "ila/expr_fuse.h"
#include <unordered_map>

/// \namespace ila
namespace ila {

/// \brief Simplifier for AST trees by sharing nodes based on the hash value.
class ExprMngr {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  ExprMngr();
  /// Default destructor.
  ~ExprMngr();

  /// Pointer type for passing shared ast simplifier.
  typedef std::shared_ptr<ExprMngr> ExprMngrPtr;
  /// Type for cacheing the AST node hashing.
  typedef std::map<std::string, ExprPtr> HashTable; // TODO unordermap
  // std::unordered_map<AstHash, ExprPtr> HashTable;

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create an object and return the pointer. Used for hiding
  /// implementation specific types.
  static ExprMngrPtr New();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Reset the hash table
  void clear();

  // ------------------------- METHODS -------------------------------------- //
  /// Simplify the AST node.
  ExprPtr Simplify(const ExprPtr node, bool simplify);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The map for AST nodes.
  HashTable map_;

}; // class ExprMngr

/// Pointer type for passing shared ast simplifier.
typedef ExprMngr::ExprMngrPtr ExprMngrPtr;

} // namespace ila

#endif // __SIMPLIFY_H__

