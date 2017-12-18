/// \file
/// Source for the var expression

#include "ila/ast/expr_var.h"
#include "util/log.h"

namespace ila {

const std::string ExprVar::k_prefix_var_ = "var";

ExprVar::ExprVar() { ILA_ERROR << "Undefined ExprVar constructor.\n"; }

ExprVar::ExprVar(const std::string& name) {
  set_name(name);
  set_arity(0);
  // set bool sort
  set_sort(Sort());
}

ExprVar::ExprVar(const std::string& name, const int& bit_width) {
  set_name(name);
  set_arity(0);
  // set bv sort
  set_sort(Sort(bit_width));
}

ExprVar::ExprVar(const std::string& name, const int& addr_width,
                 const int& data_width) {
  set_name(name);
  set_arity(0);
  // set mem sort
  set_sort(Sort(addr_width, data_width));
}

ExprVar::~ExprVar() {}

z3::expr ExprVar::GetZ3Expr(z3::context& z3_ctx,
                            const Z3ExprVec& z3expr_vec) const {
  if (IsBool()) {
    return z3_ctx.bool_const(name().c_str());
  } else if (IsBv()) {
    return z3_ctx.bv_const(name().c_str(), sort().bit_width());
  } else if (IsMem()) {
    ILA_ERROR << "Not implemented.\n"; // TODO
    return z3_ctx.bv_const(name().c_str(), sort().data_width());
  } else {
    ILA_ERROR << "Undefined sort for var " << name().str() << "\n";
    return z3_ctx.bool_const(name().c_str());
  }
}

std::ostream& ExprVar::Print(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

std::ostream& ExprVar::PrintBool(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

std::ostream& ExprVar::PrintBv(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

std::ostream& ExprVar::PrintMem(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

} // namespace ila

