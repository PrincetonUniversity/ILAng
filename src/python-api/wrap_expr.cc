/// \file
/// Source for wrapping Expr.

#include "python-api/wrap_expr.h"

namespace ila {
namespace pyapi {

const ExprPtr ExprWrap::get() const { return ptr_; }

std::string ExprWrap::Name() const { return ptr_->name().str(); }

ExprWrap* ExprWrap::Complement() const {
  return new ExprWrap(ExprFuse::Complement(ptr_));
}

ExprWrap* ExprWrap::Negate() const {
  return new ExprWrap(ExprFuse::Negate(ptr_));
}

ExprWrap* ExprWrap::And(ExprWrap* rhs) const {
  return new ExprWrap(ExprFuse::And(ptr_, rhs->get()));
}

ExprWrap* ExprWrap::Load(ExprWrap* mem, ExprWrap* addr) {
  return new ExprWrap(ExprFuse::Load(mem->get(), addr->get()));
}

} // namespace pyapi
} // namespace ila

