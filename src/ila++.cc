/// \file
/// Source for the c++ API.

#include "ila++.h"
#include "ila/instr_lvl_abs.h"

namespace ila {

NodeRef::NodeRef(std::shared_ptr<Expr> ptr) : ptr_(ptr) {}

NodeRef::~NodeRef() {}

NodeRef NodeRef::ConstBool(bool val) {
  auto v = ExprFuse::BoolConst(val);
  return NodeRef(v);
}

} // namespace ila

