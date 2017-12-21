/// \file
/// The source for the class InstrLvlAbs.

#include "ila/instr_lvl_abs.h"

namespace ila {

InstrLvlAbs::InstrLvlAbs() {
  ILA_WARN << "Initialize ILA without specifying name ...\n";
}

InstrLvlAbs::InstrLvlAbs(const std::string& name) : Object(name) {
  is_spec_ = true;
}

InstrLvlAbs::~InstrLvlAbs() {}

bool InstrLvlAbs::is_spec() const { return is_spec_; }

} // namespace ila

