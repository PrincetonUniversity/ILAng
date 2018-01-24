/// \file
/// Source for the class Expr

#include "ila/ast/expr.h"
#include "util/log.h"

namespace ila {

typedef Expr::InstrLvlAbsPtr InstrLvlAbsPtr;

const std::string Expr::k_prefix_expr_ = "expr";

Expr::Expr() : arity_(0), num_param_(0) {}

Expr::~Expr() {}

const Sort& Expr::sort() const { return sort_; }

const size_t& Expr::arity() const { return arity_; }

ExprPtr Expr::arg(const size_t& i) const {
  ILA_ASSERT(i <= arity()) << "Invalid argument index " << i << "\n";
  return args_[i];
}

const size_t& Expr::num_param() const { return num_param_; }

const int& Expr::param(const size_t& i) const {
  ILA_ASSERT(i <= num_param_) << "Invalid parameter index " << i << "\n";
  return params_[i];
}

InstrLvlAbsPtr Expr::host() const { return host_; }

void Expr::set_sort(const Sort& sort) { sort_ = sort; }

void Expr::set_arity(const size_t& arity) {
  ILA_ASSERT(arity_ == 0) << "Overwriting non-zero arity " << arity_ << " to "
                          << arity << "\n";
  arity_ = arity;
  args_.reserve(arity_);
}

void Expr::set_args(const ExprPtrVec& args) { args_ = args; }

void Expr::set_num_param(const size_t& num_param) {
  ILA_ASSERT(num_param_ == 0) << "Overwriting non-zero paramter number "
                              << num_param_ << " to " << num_param << "\n";
  num_param_ = num_param;
}

void Expr::set_params(const std::vector<int> params) { params_ = params; }

void Expr::set_host(InstrLvlAbsPtr host) { host_ = host; }

} // namespace ila

