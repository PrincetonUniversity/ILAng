/// \file
/// Source for the class Expr

#include "ila/ast/expr.h"
#include "util/log.h"

namespace ila {

typedef Expr::InstrLvlAbsPtr InstrLvlAbsPtr;

Expr::Expr() {}

Expr::~Expr() {}

void Expr::set_sort(const Sort& sort) { sort_ = sort; }

void Expr::set_args(const ExprPtrVec& args) { args_ = args; }

void Expr::set_params(const std::vector<int> params) { params_ = params; }

void Expr::set_host(InstrLvlAbsPtr host) { host_ = host; }

std::ostream& operator<<(std::ostream& out, ExprPtr expr) {
  return expr->Print(out);
}

} // namespace ila

