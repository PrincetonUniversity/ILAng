/// \file
/// Source for the LIA converter.

#ifdef SMTSWITCH_INTERFACE

#include <ilang/target-smt/lia_cvtr.h>

#include <cmath>

#include <fmt/format.h>

#include <ilang/ila/ast_hub.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

namespace ilang {

LiaCvtr::LiaCvtr(smt::SmtSolver& solver)
    : SmtSwitchItf(solver), solver_(solver) {}

LiaCvtr::~LiaCvtr() {}

smt::Term LiaCvtr::ExprVar2Term(const ExprPtr& expr) {
  auto prefix = (expr->host()) ? expr->host()->GetRootName() : "";
  auto e_name = expr->name().format_str(prefix, suffix_);

  auto smt_sort = IlaSort2LiaSort(expr->sort());
  return solver_->make_symbol(e_name, smt_sort);
}

smt::Term LiaCvtr::ExprConst2Term(const ExprPtr& expr) {
  auto expr_const = std::static_pointer_cast<ExprConst>(expr);

  switch (auto sort_uid = asthub::GetUidSort(expr); sort_uid) {
  case AstUidSort::kBool: {
    return solver_->make_term(expr_const->val_bool()->val());
  }
  case AstUidSort::kBv: {
    return solver_->make_term(expr_const->val_bv()->val(),
                              solver_->make_sort(smt::INT));
  }
  default: {
    ILA_ASSERT(sort_uid == AstUidSort::kMem);
    auto int_sort = solver_->make_sort(smt::INT);
    auto mem_sort = solver_->make_sort(smt::ARRAY, int_sort, int_sort);

    // create const memory with default value
    auto memory_value = expr_const->val_mem();
    auto def_val_term = solver_->make_term(memory_value->def_val(), int_sort);
    auto const_memory = solver_->make_term(def_val_term, mem_sort);

    // write in non-default addr-data pairs
    auto& value_map = memory_value->val_map();
    for (const auto& p : value_map) {
      auto addr_term = solver_->make_term(p.first, int_sort);
      auto data_term = solver_->make_term(p.second, int_sort);
      auto memory_wr = solver_->make_term(smt::PrimOp::Store, const_memory,
                                          addr_term, data_term);
      const_memory = memory_wr;
    }

    return const_memory;
  }
  }; // switch sort_uid
}

smt::Term LiaCvtr::ExprOp2Term(const ExprPtr& expr,
                               const smt::TermVec& arg_terms) {
  // construct based on the operator
  switch (auto expr_op_uid = asthub::GetUidExprOp(expr); expr_op_uid) {
  case AstUidExprOp::kNegate: {
    return solver_->make_term(smt::PrimOp::Negate, arg_terms.at(0));
  }
  case AstUidExprOp::kNot: {
    return solver_->make_term(smt::PrimOp::Not, arg_terms.at(0));
  }
#if 0
  case AstUidExprOp::kComplement: {
    return solver_->make_term(smt::PrimOp::BVNot, arg_terms.at(0));
  }
#endif
  case AstUidExprOp::kAnd: {
    ILA_CHECK(expr->is_bool()) << "BVAnd not supported for LIA";
    return solver_->make_term(smt::PrimOp::And, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kOr: {
    ILA_CHECK(expr->is_bool()) << "BVOr not supported for LIA";
    return solver_->make_term(smt::PrimOp::Or, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kXor: {
    ILA_CHECK(expr->is_bool()) << "BVXor not supported for LIA";
    return solver_->make_term(smt::PrimOp::Xor, arg_terms.at(0),
                              arg_terms.at(1));
  }
#if 0
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
#endif
  case AstUidExprOp::kAdd: {
    return solver_->make_term(smt::PrimOp::Plus, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kSubtract: {
    return solver_->make_term(smt::PrimOp::Minus, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kDivide: {
    return solver_->make_term(smt::PrimOp::IntDiv, arg_terms.at(0),
                              arg_terms.at(1));
  }
#if 0
  case AstUidExprOp::kSignedRemainder: {
    return solver_->make_term(smt::PrimOp::BVSrem, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kUnsignedRemainder: {
    return solver_->make_term(smt::PrimOp::BVUrem, arg_terms.at(0),
                              arg_terms.at(1));
  }
#endif
  case AstUidExprOp::kSignedModular: {
    return solver_->make_term(smt::PrimOp::Mod, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kMultiply: {
    return solver_->make_term(smt::PrimOp::Mult, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kEqual: {
    return solver_->make_term(smt::PrimOp::Equal, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kLessThan: {
    return solver_->make_term(smt::PrimOp::Lt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kGreaterThan: {
    return solver_->make_term(smt::PrimOp::Gt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kUnsignedLessThan: {
    return solver_->make_term(smt::PrimOp::Lt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kUnsignedGreaterThan: {
    return solver_->make_term(smt::PrimOp::Gt, arg_terms.at(0),
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
#if 0
  case AstUidExprOp::kConcatenate: {
    return solver_->make_term(smt::PrimOp::Concat, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AstUidExprOp::kExtract: {
    auto op = smt::Op(smt::PrimOp::Extract, expr->param(0), expr->param(1));
    return solver_->make_term(op, arg_terms.at(0));
  }
#endif
  case AstUidExprOp::kZeroExtend: {
    return arg_terms.at(0);
  }
  case AstUidExprOp::kSignedExtend: {
    return arg_terms.at(0);
  }
#if 0
  case AstUidExprOp::kRotateLeft: {
    auto op = smt::Op(smt::PrimOp::Rotate_Left, expr->param(0));
    return solver_->make_term(op, arg_terms.at(0));
  }
  case AstUidExprOp::kRotateRight: {
    auto op = smt::Op(smt::PrimOp::Rotate_Right, expr->param(0));
    return solver_->make_term(op, arg_terms.at(0));
  }
#endif
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
    ILA_CHECK(false) << "Op " << expr_op_uid << " not supported for LIA (yet)";
    return solver_->make_term(true);
  }
  }; // switch expr_op_uid
}

smt::Term LiaCvtr::Func2Term(const FuncPtr& func) {
  // func name (for z3 compatibility)
  auto prefix = (func->host()) ? func->host()->GetRootName() : "";
  auto f_name = func->name().format_str(prefix, suffix_);

  // func sort
  auto arg_sorts = smt::SortVec();
  for (size_t i = 0; i != func->arg_num(); i++) {
    arg_sorts.push_back(IlaSort2LiaSort(func->arg(i)));
  }
  arg_sorts.push_back(IlaSort2LiaSort(func->out())); // return is the last
  auto func_sort = solver_->make_sort(smt::FUNCTION, arg_sorts);

  // func term
  auto func_term = solver_->make_symbol(f_name, func_sort);
  return func_term;
}

smt::Sort LiaCvtr::IlaSort2LiaSort(const SortPtr& s) {
  switch (auto sort_uid = s->uid(); sort_uid) {
  case AstUidSort::kBool: {
    return solver_->make_sort(smt::BOOL);
  }
  case AstUidSort::kBv: {
    return solver_->make_sort(smt::INT);
  }
  default: {
    ILA_ASSERT(sort_uid == AstUidSort::kMem);
    return solver_->make_sort(smt::ARRAY, solver_->make_sort(smt::INT),
                              solver_->make_sort(smt::INT));
  }
  }; // switch sort uid
}

} // namespace ilang

#endif // SMTSWITCH_INTERFACE
