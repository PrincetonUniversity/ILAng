/// \file
/// Header for function object for rewriting Expr.

#ifndef EXPR_REWRITE_H__
#define EXPR_REWRITE_H__

#include "ila/expr_fuse.h"

namespace ila {

class FuncObjRewrite {
public:
  FuncObjRewrite(const ExprMap& rule) : rule_(rule) {}

  ExprPtr get(const ExprPtr e) const;

  bool pre(const ExprPtr e) const;

  void post(const ExprPtr e);

  ExprPtr Copy(const ExprPtr e) const;

private:
  ExprMap rule_;

}; // class DfsFuncObjRewrite

} // namespace ila

#endif // EXPR_REWRITE_H__

