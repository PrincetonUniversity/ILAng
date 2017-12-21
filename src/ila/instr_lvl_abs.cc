/// \file
/// The source for the class InstrLvlAbs.

#include "ila/instr_lvl_abs.h"

namespace ila {

InstrLvlAbs::InstrLvlAbs() {
  ILA_WARN << "Initialize ILA without specifying name ...\n";
}

InstrLvlAbs::InstrLvlAbs(const std::string& name) : Object(name) {
  is_spec_ = true;
  to_simplify_ = true;
  expr_mngr_.Reset();
}

InstrLvlAbs::~InstrLvlAbs() {}

bool InstrLvlAbs::is_spec() const { return is_spec_; }

void InstrLvlAbs::set_simplify(bool simplify) { to_simplify_ = simplify; }

void InstrLvlAbs::set_spec(bool spec) { is_spec_ = spec; }

} // namespace ila

