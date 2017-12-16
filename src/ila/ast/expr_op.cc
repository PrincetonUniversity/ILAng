/// \file
/// Source for the op expression

#include "ila/ast/expr_op.h"

namespace ila {

const std::string ExprOp::k_prefix_op_ = "op";

unsigned ExprOp::counter_ = 0;

// ------------------------- Class ExprOp ----------------------------------- //
ExprOp::ExprOp() {
  ILA_ERROR << "Constructor ExprOp with undefined constructor.\n";
}

ExprOp::ExprOp(const size_t& arity) { set_arity(arity); }

ExprOp::~ExprOp() {}

// ------------------------- Class ExprOp ----------------------------------- //
ExprOpAnd::ExprOpAnd(const ExprPtr& arg0, const ExprPtr& arg1) : ExprOp(2) {
  set_args({arg0, arg1});
  // TODO set_sort();
}

} // namespace ila

