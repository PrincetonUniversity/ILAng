/// \file
/// Source for bounded model checking

#include "eq-check/bmc.h"

namespace ila {
Bmc::Bmc() {}

Bmc::~Bmc() {}

z3::context& Bmc::ctx() { return ctx_; }

} // namespace ila
