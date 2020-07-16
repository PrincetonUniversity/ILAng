/// \file
/// Source for the class Expr

#include <ilang/ila/ast/expr.h>

#include <ilang/util/log.h>

namespace ilang {

Expr::Expr() {}

Expr::Expr(const std::string& name) : Ast(name) {}

Expr::~Expr() {}

void Expr::set_sort(const SortPtr sort) { sort_ = sort; }

void Expr::set_args(const ExprPtrVec& args) { args_ = args; }

void Expr::set_params(const std::vector<int> params) { params_ = params; }

void Expr::replace_arg(const int& idx, const ExprPtr& arg) {
  args_.at(idx) = arg;
}

void Expr::replace_arg(const ExprPtr& a, const ExprPtr& b) {
  size_t idx = arg_num();
  for (size_t i = 0; i != arg_num(); i++) {
    if (args_.at(i) == a)
      idx = i;
  }
  if (idx != arg_num()) {
    args_.at(idx) = b;
  } else {
    ILA_ERROR << a << " not found for replacing.";
  }
}

} // namespace ilang
