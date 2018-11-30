/// \file
/// Header for the class ExprMngr and the corresponding hash

#ifndef AST_HASH_H__
#define AST_HASH_H__

#include <ilang/ila/expr_fuse.h>
#include <unordered_map>

/// \namespace ilang
namespace ilang {

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
  typedef std::unordered_map<size_t, const ExprPtr> HashTable;

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create an object and return the pointer. Used for hiding
  /// implementation specific types.
  static ExprMngrPtr New();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Reset the hash table
  void clear();

  // ------------------------- METHODS -------------------------------------- //
  /// Return the AST node representative.
  ExprPtr GetRep(const ExprPtr node);
  /// Function object for sharing ast nodes.
  void operator()(const ExprPtr node);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The map for AST nodes.
  HashTable map_;

  // ------------------------- HELPER FUNCTIONS ----------------------------- //
  /// Hash function.
  size_t Hash(const ExprPtr node) const;

}; // class ExprMngr

/// Pointer type for passing shared ast simplifier.
typedef ExprMngr::ExprMngrPtr ExprMngrPtr;

} // namespace ilang

#endif // HASH_AST_H__
