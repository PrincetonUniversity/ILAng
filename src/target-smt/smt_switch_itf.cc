/// \file
/// Source for the smt-switch interface.

#ifdef SMTSWITCH_INTERFACE

#include <ilang/target-smt/smt_switch_itf.h>

#include <fmt/format.h>

#include <ilang/ila/ast_hub.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

#define PARAM_BIT_WIDTH 8

namespace ilang {

SmtSwitchItf::SmtSwitchItf(smt::SmtSolver& solver) : solver_(solver) {}

SmtSwitchItf::~SmtSwitchItf() {}

void SmtSwitchItf::Reset() {
  try {
    solver_->reset();
  } catch (SmtException& e) {
    ILA_ERROR << e.what();
  }
  expr_map_.clear();
  func_map_.clear();
}

smt::Term SmtSwitchItf::GetSmtTerm(const ExprPtr& expr,
                                   const std::string& suffix) {
  suffix_ = suffix;
  expr->DepthFirstVisitPrePost(*this);

  auto pos = expr_map_.find(expr);
  ILA_ASSERT(pos != expr_map_.end()) << expr;
  return pos->second;
}

bool SmtSwitchItf::pre(const ExprPtr& expr) {
  return (expr_map_.find(expr) != expr_map_.end());
}

void SmtSwitchItf::post(const ExprPtr& expr) {
  try {
    PopulateExprMap(expr);
  } catch (SmtException& e) {
    ILA_ERROR << expr << e.what();
  }
}

void SmtSwitchItf::PopulateExprMap(const ExprPtr& expr) {
  // placeholder for argument Terms
  smt::TermVec arg_terms;

  for (size_t i = 0; i < expr->arg_num(); i++) {
    auto arg_i_expr = expr->arg(i);
    auto pos = expr_map_.find(arg_i_expr);

    ILA_ASSERT(pos != expr_map_.end()) << arg_i_expr;
    arg_terms.push_back(pos->second);
  }

  // get the Term based on its ast node type
  auto Expr2Term = [this](const ExprPtr& e, const smt::TermVec& args) {
    if (e->is_var()) {
      return ExprVar2Term(e);
    } else if (e->is_const()) {
      return ExprConst2Term(e);
    } else {
      ILA_ASSERT(e->is_op());
      return ExprOp2Term(e, args);
    }
  };

  auto res = Expr2Term(expr, arg_terms);

  // update the Term cache
  expr_map_.insert({expr, res});
}

smt::Term SmtSwitchItf::ExprVar2Term(const ExprPtr& expr) {
  // for z3 compatibility
  auto prefix = (expr->host()) ? expr->host()->GetRootName() : "";
  auto e_name = expr->name().format_str(prefix, suffix_);

  auto smt_sort = IlaSort2SmtSort(expr->sort());
  return solver_->make_symbol(e_name, smt_sort);
}

smt::Term SmtSwitchItf::ExprConst2Term(const ExprPtr& expr) {
  auto expr_const = std::static_pointer_cast<ExprConst>(expr);

  switch (auto sort_uid = asthub::GetUidSort(expr); sort_uid) {
  case AstUidSort::kBool: {
    return solver_->make_term(expr_const->val_bool()->val());
  }
  case AstUidSort::kBv: {
    auto bw = expr->sort()->bit_width();
    return solver_->make_term(expr_const->val_bv()->val(),
                              solver_->make_sort(smt::BV, bw));
  }
  default: {
    ILA_ASSERT(sort_uid == AstUidSort::kMem);
    auto addr_sort = solver_->make_sort(smt::BV, expr->sort()->addr_width());
    auto data_sort = solver_->make_sort(smt::BV, expr->sort()->data_width());
    auto mem_sort = solver_->make_sort(smt::ARRAY, addr_sort, data_sort);

    // create const memory with default value
    auto memory_value = expr_const->val_mem();
    auto def_val_term = solver_->make_term(memory_value->def_val(), data_sort);
    auto const_memory = solver_->make_term(def_val_term, mem_sort);

    // write in non-default addr-data pairs
    auto& value_map = memory_value->val_map();
    for (const auto& p : value_map) {
      auto addr_term = solver_->make_term(p.first, addr_sort);
      auto data_term = solver_->make_term(p.second, data_sort);
      auto memory_wr = solver_->make_term(smt::PrimOp::Store, const_memory,
                                          addr_term, data_term);
      const_memory = memory_wr;
    }

    return const_memory;
  }
  }; // switch sort_uid
}

smt::Term SmtSwitchItf::ExprOp2Term(const ExprPtr& expr,
                                    const smt::TermVec& arg_terms) {
  // construct based on the operator
  switch (auto expr_op_uid = asthub::GetUidExprOp(expr); expr_op_uid) {
  case AstUidExprOp::kNegate: {
    return solver_->make_term(smt::PrimOp::BVNeg, arg_terms.at(0));
  }
  case AstUidExprOp::kNot: {
    return solver_->make_term(smt::PrimOp::Not, arg_terms.at(0));
  }
  case AstUidExprOp::kComplement: {
    // PrimOp::BVComp seems to be compare (equal)
    return solver_->make_term(smt::PrimOp::BVNot, arg_terms.at(0));
  }
  case AstUidExprOp::kAnd: {
    auto op = expr->is_bool() ? smt::PrimOp::And : smt::PrimOp::BVAnd;
    return solver_->make_term(op, arg_terms.at(0), arg_terms.at(1));
  }
  case AstUidExprOp::kOr: {
    auto op = expr->is_bool() ? smt::PrimOp::Or : smt::PrimOp::BVOr;
    return solver_->make_term(op, arg_terms.at(0), arg_terms.at(1));
  }
  case AstUidExprOp::kXor: {
    auto op = expr->is_bool() ? smt::PrimOp::Xor : smt::PrimOp::BVXor;
    return solver_->make_term(op, arg_terms.at(0), arg_terms.at(1));
  }
  case AstUidExprOp::kShiftLeft: {
    return solver_->make_term(smt::PrimOp::BVShl, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kArithShiftRight: {
    return solver_->make_term(smt::PrimOp::BVAshr, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kLogicShiftRight: {
    return solver_->make_term(smt::PrimOp::BVLshr, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kAdd: {
    return solver_->make_term(smt::PrimOp::BVAdd, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kSubtract: {
    return solver_->make_term(smt::PrimOp::BVSub, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kDivide: {
    // signed bv div (not int, not real)
    return solver_->make_term(smt::PrimOp::BVSdiv, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kSignedRemainder: {
    return solver_->make_term(smt::PrimOp::BVSrem, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kUnsignedRemainder: {
    return solver_->make_term(smt::PrimOp::BVUrem, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kSignedModular: {
    return solver_->make_term(smt::PrimOp::BVSmod, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kMultiply: {
    // bv mul (not int, not real)
    return solver_->make_term(smt::PrimOp::BVMul, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kEqual: {
    return solver_->make_term(smt::PrimOp::Equal, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kLessThan: {
    // bv signed lt (not unsigned, not real)
    return solver_->make_term(smt::PrimOp::BVSlt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kGreaterThan: {
    // bv signed gt (not unsigned, not real)
    return solver_->make_term(smt::PrimOp::BVSgt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kUnsignedLessThan: {
    // bv unsigned lt (not real)
    return solver_->make_term(smt::PrimOp::BVUlt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kUnsignedGreaterThan: {
    // bv unsigned gt (not real)
    return solver_->make_term(smt::PrimOp::BVUgt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kLoad: {
    return solver_->make_term(smt::PrimOp::Select, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kStore: {
    return solver_->make_term(smt::PrimOp::Store, arg_terms.at(0),
                              arg_terms.at(1), arg_terms.at(2));
  }
  case AstUidExprOp::kConcatenate: {
    return solver_->make_term(smt::PrimOp::Concat, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kExtract: {
    auto op = smt::Op(smt::PrimOp::Extract, expr->param(0), expr->param(1));
    return solver_->make_term(op, arg_terms.at(0));
  }
  case AstUidExprOp::kZeroExtend: {
    // the param in smt-switch (at least for btor) is the diff
    auto diff = expr->param(0) - expr->arg(0)->sort()->bit_width();
    auto op = smt::Op(smt::PrimOp::Zero_Extend, diff);
    return solver_->make_term(op, arg_terms.at(0));
  }
  case AstUidExprOp::kSignedExtend: {
    // the param in smt-switch (at least for btor) is the diff
    auto diff = expr->param(0) - expr->arg(0)->sort()->bit_width();
    auto op = smt::Op(smt::PrimOp::Sign_Extend, diff);
    return solver_->make_term(op, arg_terms.at(0));
  }
  case AstUidExprOp::kRotateLeft: {
    auto op = smt::Op(smt::PrimOp::Rotate_Left, expr->param(0));
    return solver_->make_term(op, arg_terms.at(0));
  }
  case AstUidExprOp::kRotateRight: {
    auto op = smt::Op(smt::PrimOp::Rotate_Right, expr->param(0));
    return solver_->make_term(op, arg_terms.at(0));
  }
  case AstUidExprOp::kImply: {
    return solver_->make_term(smt::PrimOp::Implies, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kIfThenElse: {
    return solver_->make_term(smt::PrimOp::Ite, arg_terms.at(0),
                              arg_terms.at(1), arg_terms.at(2));
  }
  case AstUidExprOp::kApplyFunc: {
    auto expr_appfunc = std::static_pointer_cast<ExprOpAppFunc>(expr);
    auto func = expr_appfunc->func();

    // term placeholder for the solver
    smt::TermVec func_arg_terms;

    // check if the func has been visited
    auto pos = func_map_.find(func);
    if (pos != func_map_.end()) {
      func_arg_terms.push_back(pos->second);
    } else { // fist visit - create new term
      auto func_term = Func2Term(func);
      func_arg_terms.push_back(func_term);
      func_map_[func] = func_term;
    }

    // apply func
    for (auto arg_i : arg_terms) {
      func_arg_terms.push_back(arg_i);
    }
    return solver_->make_term(smt::PrimOp::Apply, func_arg_terms);
  }
  default: {
    ILA_CHECK(false) << "Op " << expr_op_uid << " not supported in smt-switch";
    return solver_->make_term(true);
  }
  }; // switch expr_op_uid
}

smt::Term SmtSwitchItf::Func2Term(const FuncPtr& func) {
  // func name (for z3 compatibility)
  auto prefix = (func->host()) ? func->host()->GetRootName() : "";
  auto f_name = func->name().format_str(prefix, suffix_);

  // func sort
  auto arg_sorts = smt::SortVec();
  for (size_t i = 0; i != func->arg_num(); i++) {
    arg_sorts.push_back(IlaSort2SmtSort(func->arg(i)));
  }
  arg_sorts.push_back(IlaSort2SmtSort(func->out())); // return is the last
  auto func_sort = solver_->make_sort(smt::FUNCTION, arg_sorts);

  // func term
  auto func_term = solver_->make_symbol(f_name, func_sort);
  return func_term;
}

smt::Sort SmtSwitchItf::IlaSort2SmtSort(const SortPtr& s) {
  switch (auto sort_uid = s->uid(); sort_uid) {
  case AstUidSort::kBool: {
    return solver_->make_sort(smt::BOOL);
  }
  case AstUidSort::kBv: {
    return solver_->make_sort(smt::BV, s->bit_width());
  }
  default: {
    ILA_ASSERT(sort_uid == AstUidSort::kMem);
    return solver_->make_sort(smt::ARRAY,
                              solver_->make_sort(smt::BV, s->addr_width()),
                              solver_->make_sort(smt::BV, s->data_width()));
  }
  }; // switch sort uid
}

} // namespace ilang

#endif // SMT_SWITCH_INTERFACE
