/// \file
/// Source for the class Expr

#include "ila/ast/expr.h"
#include "util/log.h"

namespace ila {

typedef Expr::InstrLvlAbsPtr InstrLvlAbsPtr;

Expr::Expr() {}

Expr::~Expr() {}

#if 0
const Sort& Expr::sort() const { return sort_; }

const size_t Expr::arity() const { return args_.size(); }

ExprPtr Expr::arg(const size_t& i) const { return args_.at(i); }

const size_t Expr::param_num() const { return params_.size(); }

const int& Expr::param(const size_t& i) const { return params_.at(i); }

InstrLvlAbsPtr Expr::host() const { return host_; }
#endif

void Expr::set_sort(const Sort& sort) { sort_ = sort; }

void Expr::set_args(const ExprPtrVec& args) { args_ = args; }

void Expr::set_params(const std::vector<int> params) { params_ = params; }

void Expr::set_host(InstrLvlAbsPtr host) { host_ = host; }

std::ostream& operator<<(std::ostream& out, ExprPtr expr) {
  return expr->Print(out);
}

} // namespace ila

