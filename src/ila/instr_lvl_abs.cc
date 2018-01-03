/// \file
/// The source for the class InstrLvlAbs.

#include "ila/instr_lvl_abs.h"

namespace ila {

InstrLvlAbs::InstrLvlAbs() {
  ILA_WARN << "Initialize ILA without specifying name ...\n";
  set_name("untitled-ILA");
  InitObject();
}

InstrLvlAbs::InstrLvlAbs(const std::string& name) : Object(name) {
  InitObject();
}

InstrLvlAbs::~InstrLvlAbs() {}

bool InstrLvlAbs::is_spec() const { return is_spec_; }

void InstrLvlAbs::set_simplify(bool simplify) { to_simplify_ = simplify; }

void InstrLvlAbs::set_spec(bool spec) { is_spec_ = spec; }

void InstrLvlAbs::InitObject() {
  inputs_.clear();
  states_.clear();
  inits_.clear();
  fetch_ = NULL;
  valid_ = NULL;
  instrs_.clear();
  child_.clear();

  is_spec_ = true;
  to_simplify_ = true;

  expr_mngr_->Reset();
}

} // namespace ila

