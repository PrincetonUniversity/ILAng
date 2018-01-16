/// \file
/// Header for wrapping Expr.

#ifndef __WRAP_EXPR_H__
#define __WRAP_EXPR_H__

#include "ila/expr_fuse.h"

namespace ila {

class ExprWrap {
  ExprPtr ptr;

public:
  ExprWrap() : ptr(NULL) {}

  ExprWrap(const ExprPtr e) : ptr(e) {}

}; // class ExprWrap

} // namespace ila

#endif // __WRAP_EXPR_H__

