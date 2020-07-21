/// \file
/// Class ExprMngr - organize and share Expr nodes based on their syntactic
/// structures.

#ifndef ILANG_ILA_HASH_AST_H__
#define ILANG_ILA_HASH_AST_H__

#include <memory>
#include <string>
#include <unordered_map>

#include <ilang/ila/ast_hub.h>

/// \namespace ilang
namespace ilang {

/// \brief Simplifier for AST trees by sharing nodes based on the hash value.
class ExprMngr {
public:
  /// Pointer type for passing shared ast simplifier.
  typedef std::shared_ptr<ExprMngr> ExprMngrPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  ExprMngr();
  /// Default destructor.
  ~ExprMngr();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create an object and return the pointer. Used for hiding
  /// implementation specific types.
  static ExprMngrPtr New();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Reset the hash table
  void clear();

  // ------------------------- METHODS -------------------------------------- //
  /// Return the AST node representative.
  ExprPtr GetRep(const ExprPtr& node);
  /// Function object for sharing ast nodes.
  void operator()(const ExprPtr& node);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The map for AST nodes.
  std::unordered_map<std::string, ExprPtr> map_;

  // ------------------------- HELPER FUNCTIONS ----------------------------- //
  /// Hash function.
  static std::string Hash(const ExprPtr& node);

}; // class ExprMngr

/// Pointer type for passing shared ast simplifier.
typedef ExprMngr::ExprMngrPtr ExprMngrPtr;

} // namespace ilang

#endif // ILANG_ILA_HASH_AST_H__
