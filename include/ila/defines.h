/// \file
/// Headers for macros, type definitions, etc.

#ifndef __DEFINES_H__
#define __DEFINES_H__

#include "ila/symbol.h"
#include "util/container.h"
#include "z3++.h"
#include <memory>
#include <vector>

namespace ila {

typedef std::vector<z3::expr> Z3ExprVec;

typedef std::shared_ptr<Z3ExprVec> Z3ExprVecPtr;

typedef KeyVec<Symbol, z3::expr> Z3ExprMap;

typedef std::shared_ptr<Z3ExprMap> Z3ExprMapPtr;

} // namespace ila

#endif // __DEFINES_H__

