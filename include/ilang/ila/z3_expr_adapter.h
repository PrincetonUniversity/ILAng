/// \file
/// Header for the class Z3ExprAdapter

#ifndef Z3_EXPR_ADAPTER_H__
#define Z3_EXPR_ADAPTER_H__

#include "z3++.h"
#include <ilang/ila/expr_fuse.h>
#include <unordered_map>

/// \namespace ilang
namespace ilang {

/// The function object for hashing Expr in generating z3 expression.
typedef ExprHash Z3AdapterHash;

/// \brief The class for generating z3 expression from an ILA.
class Z3ExprAdapter {
public:
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor.
  Z3ExprAdapter(z3::context& ctx);
  /// ~Default destructor.
  ~Z3ExprAdapter();

  /// Type for caching the generated expressions.
  typedef std::unordered_map<const ExprPtr, z3::expr, Z3AdapterHash> ExprMap;

  // ------------------------- METHODS -------------------------------------- //
  /// Get the z3 expression of the AST node.
  z3::expr GetExpr(const ExprPtr expr, const std::string& suffix = "");

  /// Function object for getting z3 expression.
  void operator()(const ExprPtr expr);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying z3 context.
  z3::context& ctx_;
  /// Container for cacheing intermediate expressions.
  ExprMap expr_map_;
  /// Name suffix for each expression generation (e.g. time frame)
  std::string suffix_ = "";

  // ------------------------- HELPERS -------------------------------------- //
  /// Insert the z3 expression of the given node into the map.
  void PopulateExprMap(const ExprPtr expr);

}; // class Z3ExprAdapter

} // namespace ilang

#endif // Z3_EXPR_ADAPTER_H__
