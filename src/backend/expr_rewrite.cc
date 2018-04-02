/// \file
/// Source for function object for rewriting Expr.

#include "backend/expr_rewrite.h"

namespace ila {

ExprPtr FuncObjRewrite::get(const ExprPtr e) const {
  auto pos = rule_.find(e);
  ILA_ASSERT(pos != rule_.end()) << e << " not found";
  return pos->second;
}

bool FuncObjRewrite::pre(const ExprPtr e) const {
  // check rewriting rule to see if defined/visited
  auto pos = rule_.find(e);
  return pos != rule_.end(); // if found --> break
}

void FuncObjRewrite::post(const ExprPtr e) {
  // leaf -- remain unchanged and add to the rule
  if (e->arg_num() == 0) {
    auto ok = rule_.insert({e, e}).second;
    // must not be defined, otherwise, there is a cycle.
    ILA_ASSERT(ok) << "Rewriting rule redefined (exist cycle in the AST)";
  }
  // non-leaf
  auto dst = Copy(e);
}

ExprPtr FuncObjRewrite::Copy(const ExprPtr e) const {
  decltype(Copy(NULL)) res = NULL;
  if (e->is_const()) {
    //
  } else if (e->is_var()) {
    //
  } else {
    ILA_ASSERT(e->is_op()) << "Unknown Expr type";
    //
  }
  ILA_ASSERT(res) << "Fail copying Expr during rewriting";
  return res;
}

} // namespace ila

