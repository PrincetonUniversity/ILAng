/// \file
/// Class Z3ExprAdapter - the generator for ilang::Expr to z3::expr

#ifndef ILANG_TARGET_SMT_Z3_EXPR_ADAPTER_H__
#define ILANG_TARGET_SMT_Z3_EXPR_ADAPTER_H__

#include <unordered_map>

#include <z3++.h>

#include <ilang/ila/ast_hub.h>

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

  // ------------------------- METHODS -------------------------------------- //
  /// Get the z3 expression of the AST node.
  z3::expr GetExpr(const ExprPtr& expr, const std::string& suffix = "");

  /// Function object for getting z3 expression.
  void operator()(const ExprPtr& expr);

  /// Return the underlying z3 context.
  inline z3::context& context() const { return ctx_; }

  // ------------------------- SHIM INTERFACE ------------------------------- //
  /// Unified SmtShim interface to get z3::expr.
  inline auto GetShimExpr(const ExprPtr& expr, const std::string& suffix) {
    return GetExpr(expr, suffix);
  }
  /// Unified SmtShim interface to get z3::func_decl.
  inline auto GetShimFunc(const FuncPtr& func) {
    return func->GetZ3FuncDecl(ctx_);
  }
  /// Unified SmtShim interface to AND two boolean z3::expr.
  inline auto BoolAnd(const z3::expr& a, const z3::expr& b) { return a && b; }
  /// Unified SmtShim interface to EQUAL two z3::expr.
  inline auto Equal(const z3::expr& a, const z3::expr& b) { return a == b; }

private:
  /// Type for caching the generated expressions.
  typedef std::unordered_map<const ExprPtr, z3::expr, Z3AdapterHash> ExprMap;

  // ------------------------- MEMBERS -------------------------------------- //
  /// The underlying z3 context.
  z3::context& ctx_;
  /// Container for cacheing intermediate expressions.
  ExprMap expr_map_;
  /// Name suffix for each expression generation (e.g. time frame)
  std::string suffix_ = "";

  // ------------------------- HELPERS -------------------------------------- //
  /// Insert the z3 expression of the given node into the map.
  void PopulateExprMap(const ExprPtr& expr);

}; // class Z3ExprAdapter

} // namespace ilang

#endif // ILANG_TARGET_SMT_Z3_EXPR_ADAPTER_H__
