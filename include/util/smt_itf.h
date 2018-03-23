/// \file
/// Interface for SMT solver. Currently support z3.

#ifndef SMT_ITF_H__
#define SMT_ITF_H__

#include "z3++.h"

namespace ila {

/// SMT context
typedef z3::context SMT_CTX;
/// SMT expression
typedef z3::expr SMT_EXP;

} // namespace ila

#endif // SMT_ITF_H__

