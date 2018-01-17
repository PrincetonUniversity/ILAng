/// \file
/// Source for bounded model checking

#include "eq-check/bmc.h"

namespace ila {
Bmc::Bmc() { clear(); }

Bmc::~Bmc() { clear(); }

z3::context& Bmc::ctx() { return ctx_; }

void Bmc::clear() { map_.clear(); }

} // namespace ila
