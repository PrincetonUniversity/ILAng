/// \file
/// Source for the var expression

#include "ila/ast/expr_var.h"
#include "ila/instr_lvl_abs.h"
#include "util/log.h"

namespace ila {

ExprVar::ExprVar(const std::string& name) : Expr(name) {
  set_sort(Sort::MakeBoolSort());
}

ExprVar::ExprVar(const std::string& name, const int& bit_width) : Expr(name) {
  set_sort(Sort::MakeBvSort(bit_width));
}

ExprVar::ExprVar(const std::string& name, const int& addr_width,
                 const int& data_width)
    : Expr(name) {
  set_sort(Sort::MakeMemSort(addr_width, data_width));
}

ExprVar::~ExprVar() {}

z3::expr ExprVar::GetZ3Expr(z3::context& ctx, const Z3ExprVec& z3expr_vec,
                            const std::string& suffix) const {
  auto prefix = (host()) ? host()->name().str() : "";
  auto e_name = name().format_str(prefix, suffix);
  return sort()->GetZ3Expr(ctx, e_name);
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
  // return out << name().format_str("Bool", "");
  return out << name();
}

std::ostream& ExprVar::PrintBv(std::ostream& out) const {
  // return out << name().format_str("Bv", std::to_string(sort()->bit_width()));
  return out << name().str() + "(" + std::to_string(sort()->bit_width()) + ")";
}

std::ostream& ExprVar::PrintMem(std::ostream& out) const {
  // return out << name().format_str("Mem", "");
  return out << name().str() + "(" + std::to_string(sort()->addr_width()) +
                    ", " + std::to_string(sort()->data_width()) + ")";
}

} // namespace ila

