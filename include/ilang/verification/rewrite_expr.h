/// \file
/// Header for function object for rewriting Expr.

#ifndef REWRITE_EXPR_H__
#define REWRITE_EXPR_H__

#include <ilang/ila/expr_fuse.h>

namespace ilang {

/// \brief Function object for rewriting Expr.
class FuncObjRewrExpr {
public:
  /// Constructor, initialize rewriting rule.
  FuncObjRewrExpr(const ExprMap& rule) : rule_(rule) {}

  /// Return the rewritten result.
  inline ExprPtr get(const ExprPtr e) const {
    auto pos = rule_.find(e);
    ILA_ASSERT(pos != rule_.end()) << e << " not found";
    return pos->second;
  }

  /// Pre-process: return true (break) if the node has been visited.
  bool pre(const ExprPtr e) const;
  /// Post-process: update the rewriting rule map.
  void post(const ExprPtr e);

private:
  /// Internal rewriting table.
  ExprMap rule_;

  /// Rewrite all sorts of Expr.
  ExprPtr Rewrite(const ExprPtr e) const;
  /// Rewrite Operation sorted Expr.
  ExprPtr RewriteOp(const ExprPtr e) const;

}; // class FuncObjRewrExpr

} // namespace ilang

#endif // REWRITE_EXPR_H__
