/// \file
/// Source for the op expression

#include "ila/ast/expr_op.h"

namespace ila {

const std::string ExprOp::k_prefix_op_ = "op";

unsigned ExprOp::counter_ = 0;

// ------------------------- Class ExprOp ----------------------------------- //
ExprOp::ExprOp() {
  ILA_ERROR << "Construct ExprOp with undefined default constructor.\n";
}

ExprOp::ExprOp(const ExprPtrVec& args)
    : Expr((op_name() + "_" + (++counter_).to_string()), args) {}

ExprOp::ExprOp(const std::string& name, const ExprPtrVec& args)
    : Expr(name, args) {}

ExprOp::~ExprOp() {}

// ------------------------- Class ExprOp ----------------------------------- //
ExprOpAnd::ExprOpAnd(const ExprPtr& arg0, const ExprPtr& arg1) : ExprOp(2) {
  set_args({arg0, arg1});
}

} // namespace ila

