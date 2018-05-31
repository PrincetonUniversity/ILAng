/// \file
/// Source for the class Expr

#include "ila/ast/expr.h"
#include "util/log.h"

namespace ila {

// typedef Expr::InstrLvlAbsPtr InstrLvlAbsPtr;

Expr::Expr() {}

Expr::Expr(const std::string& name) : Ast(name) {}

Expr::~Expr() {}

void Expr::set_sort(const SortPtr sort) { sort_ = sort; }

void Expr::set_args(const ExprPtrVec& args) { args_ = args; }

void Expr::set_params(const std::vector<int> params) { params_ = params; }

void Expr::replace_arg(const int& idx, const ExprPtr arg) {
  ILA_ASSERT(idx < static_cast<int>(arg_num())) << "Replacing idx overflow.";
  args_[idx] = arg;
}

void Expr::replace_arg(const ExprPtr a, const ExprPtr b) {
  size_t idx = arg_num();
  for (size_t i = 0; i != arg_num(); i++) {
    if (args_[i] == a)
      idx = i;
  }
  ILA_ASSERT(idx != arg_num()) << a << " not found for replacing.";
  args_[idx] = b;
}

} // namespace ila

