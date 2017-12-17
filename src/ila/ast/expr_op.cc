/// \file
/// Source for the op expression

#include "ila/ast/expr_op.h"

namespace ila {

const std::string ExprOp::k_prefix_op_ = "op";

unsigned ExprOp::counter_ = 0;

// ------------------------- Class ExprOp ----------------------------------- //
ExprOp::ExprOp() { ILA_ERROR << "Undefined ExprOp constructor.\n"; }

ExprOp::ExprOp(const ExprPtr arg0, const ExprPtr arg1) {
  set_arity(2);
  ExprPtrVec args = {arg0, arg1};
  set_args(args);
  set_sort(DeriveSortSymBinary(arg0->sort(), arg1->sort()));
}

ExprOp::~ExprOp() {}

SortPtr ExprOp::DeriveSortSymBinary(const SortPtr s0, const SortPtr s1) {
  ILA_ASSERT(s0 == s1) << "Undefined sorts " << s0 << " & " << s1
                       << " for symmetric binary operations.\n";
  return s0;
}

// ------------------------- Class ExprOp ----------------------------------- //
ExprOpAnd::ExprOpAnd(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {}

// ------------------------- Class ExprOp ----------------------------------- //
ExprOpOr::ExprOpOr(const ExprPtr arg0, const ExprPtr arg1)
    : ExprOp(arg0, arg1) {}

} // namespace ila

