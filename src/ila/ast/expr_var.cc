/// \file
/// Source for the var expression

#include "ila/ast/expr_var.h"
#include "ila/instr_lvl_abs.h"
#include "util/log.h"

namespace ila {

ExprVar::ExprVar(const std::string& name) : Expr(name) { set_sort(Sort()); }

ExprVar::ExprVar(const std::string& name, const int& bit_width) : Expr(name) {
  set_sort(Sort(bit_width));
}

ExprVar::ExprVar(const std::string& name, const int& addr_width,
                 const int& data_width)
    : Expr(name) {
  set_sort(Sort(addr_width, data_width));
}

ExprVar::~ExprVar() {}

z3::expr ExprVar::GetZ3Expr(z3::context& ctx, const Z3ExprVec& z3expr_vec,
                            const std::string& suffix) const {
  auto prefix = (host()) ? host()->name().str() : "";
  if (is_bool()) {
    return ctx.bool_const(name().format_str(prefix, suffix).c_str());
  } else if (is_bv()) {
    return ctx.bv_const(name().format_str(prefix, suffix).c_str(),
                        sort().bit_width());
  } else {
    ILA_ASSERT(is_mem()) << "Unknown sort for var " << name();
    auto addr_sort = ctx.bv_sort(sort().addr_width());
    auto data_sort = ctx.bv_sort(sort().data_width());
    auto mem_sort = ctx.array_sort(addr_sort, data_sort);
    return ctx.constant(name().format_str(prefix, suffix).c_str(), mem_sort);
  }
}

std::ostream& ExprVar::Print(std::ostream& out) const {
  if (is_bool()) {
    return PrintBool(out);
  } else if (is_bv()) {
    return PrintBv(out);
  } else {
    ILA_ASSERT(is_mem()) << "Unknown sort for var " << name();
    return PrintMem(out);
  }
}

std::ostream& ExprVar::PrintBool(std::ostream& out) const {
  return out << name().format_str("Bool", "");
}

std::ostream& ExprVar::PrintBv(std::ostream& out) const {
  return out << name().format_str("Bv", std::to_string(sort().bit_width()));
}

std::ostream& ExprVar::PrintMem(std::ostream& out) const {
  return out << name().format_str("Mem", "");
}

} // namespace ila

