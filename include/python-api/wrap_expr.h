/// \file
/// Header for wrapping Expr.

#ifndef __WRAP_EXPR_H__
#define __WRAP_EXPR_H__

#include "ila/expr_fuse.h"

namespace ila {

class ExprRef {
  ExprPtr ptr;

public:
  ExprRef() : ptr(NULL) {}

}; // class ExprREf

} // namespace ila

#endif // __WRAP_EXPR_H__

