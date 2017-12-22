/// \file
/// The source for the class Instr.

#include "ila/instr.h"

namespace ila {

Instr::Instr(const std::string& name, bool simplify, ExprSimplifier& expr_mngr)
    : Object(name), to_simplify_(simplify), expr_mngr_(expr_mngr) {
  decode_ = NULL;
  has_view_ = false;
  updates_.clear();
}

Instr::~Instr() {}

} // namespace ila

