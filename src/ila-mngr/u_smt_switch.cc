/// \file
/// Source for the smt-switch interface.

#include <ilang/config.h>

#ifdef SMTSWITCH_INTERFACE

#include <fmt/format.h>

#include <ilang/ila-mngr/u_smt_switch.h>
#include <ilang/ila/ast_fuse.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

#define PARAM_BIT_WIDTH 8

namespace ilang {

SmtSwitchItf::SmtSwitchItf(smt::SmtSolver& solver) : solver_(solver) {}

SmtSwitchItf::~SmtSwitchItf() {}

smt::Term SmtSwitchItf::GetSmtTerm(const ExprPtr expr,
                                   const std::string& suffix) {
  expr_map_.clear();
  suffix_ = suffix;

  expr->DepthFirstVisit(*this);

  auto pos = expr_map_.find(expr);
  ILA_ASSERT(pos != expr_map_.end()) << "SMT Term generating failed.";

  return pos->second;
}

void SmtSwitchItf::operator()(const ExprPtr expr) {
  auto pos = expr_map_.find(expr);
  // Term has been generated
  if (pos != expr_map_.end()) {
    return;
  }

  // Term not generated yet - try to construct
  try {
    PopulateExprMap(expr);
  } catch (SmtException& e) {
    ILA_ERROR << "Error while processing " << expr;
    ILA_ERROR << e.what();
  }
}

void SmtSwitchItf::PopulateExprMap(const ExprPtr expr) {
  // placeholder for argument Terms
  smt::TermVec arg_terms;

  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; i++) {
    auto arg_i_expr = expr->arg(i);
    auto pos = expr_map_.find(arg_i_expr);

    // all arguments should already have thier Terms
    ILA_ASSERT(pos != expr_map_.end())
        << fmt::format("No Term found for the {}-th argument", i);

    arg_terms.push_back(pos->second);
  }

  // get the Term based on its ast node type
  auto res = Expr2Term(expr, arg_terms);

  // update the Term cache
  expr_map_.insert({expr, res});
}

smt::Term SmtSwitchItf::Expr2Term(const ExprPtr expr,
                                  const smt::TermVec& arg_terms) {
  auto expr_uid = GetUidExpr(expr);

  switch (expr_uid) {
  case AST_UID_EXPR::VAR: {
    return ExprVar2Term(expr);
  }
  case AST_UID_EXPR::CONST: {
    return ExprConst2Term(expr);
  }
  case AST_UID_EXPR::OP: {
    return ExprOp2Term(expr, arg_terms);
  }
  default: {
    ILA_CHECK(false) << fmt::format("Unknown type {} for ", expr_uid) << expr;
    return solver_->make_term(true);
  }
  }; // switch expr_uid
}

smt::Term SmtSwitchItf::ExprVar2Term(const ExprPtr expr) {
  // for z3 compatibility
  auto prefix = (expr->host()) ? expr->host()->GetRootName() : "";
  auto e_name = expr->name().format_str(prefix, suffix_);

  auto smt_sort = IlaSort2SmtSort(expr->sort());
  return solver_->make_symbol(e_name, smt_sort);
}

smt::Term SmtSwitchItf::ExprConst2Term(const ExprPtr expr) {
  auto expr_const = std::static_pointer_cast<ExprConst>(expr);
  auto sort_uid = GetUidSort(expr->sort());

  switch (sort_uid) {
  case AST_UID_SORT::BOOL: {
    return solver_->make_term(expr_const->val_bool()->val());
  }
  case AST_UID_SORT::BV: {
    auto bw = expr->sort()->bit_width();
    return solver_->make_term(expr_const->val_bv()->val(),
                              solver_->make_sort(smt::BV, bw));
  }
  case AST_UID_SORT::MEM: {
    auto aw = expr->sort()->addr_width();
    auto dw = expr->sort()->data_width();
    auto addr_sort = solver_->make_sort(smt::BV, aw);
    auto data_sort = solver_->make_sort(smt::BV, dw);

    auto memory_term = solver_->make_symbol(
        expr->name().str(),
        solver_->make_sort(smt::ARRAY, addr_sort, data_sort));

    ILA_WARN << "Ignoring default value of constant memory " << expr;
    auto memory_value = expr_const->val_mem();
    auto& value_map = memory_value->val_map();
    for (auto p : value_map) {
      auto addr_term = solver_->make_term(p.first, addr_sort);
      auto data_term = solver_->make_term(p.second, data_sort);
      auto new_memory = solver_->make_term(smt::PrimOp::Store, memory_term,
                                           addr_term, data_term);
      memory_term = new_memory;
    }

    return solver_->make_term(
        memory_term, solver_->make_sort(smt::ARRAY, addr_sort, data_sort));
  }
  default: {
    ILA_CHECK(false) << fmt::format("Unknown sort {} for ", sort_uid) << expr;
    return solver_->make_term(true);
  }
  }; // switch sort_uid
}

smt::Term SmtSwitchItf::ExprOp2Term(const ExprPtr expr,
                                    const smt::TermVec& arg_terms) {

  // XXX Boolector (maybe also others) doesn't accept INT sort for param.
  // auto param_sort = solver_->make_sort(smt::INT);
  auto param_sort = solver_->make_sort(smt::BV, PARAM_BIT_WIDTH);
  auto expr_op_uid = GetUidExprOp(expr);

  switch (expr_op_uid) {
  case AST_UID_EXPR_OP::NEG: {
    ILA_WARN << "Negate not fully supported in smt-switch.";
    return solver_->make_term(smt::PrimOp::Negate, arg_terms.at(0));
  }
  case AST_UID_EXPR_OP::NOT: {
    return solver_->make_term(smt::PrimOp::Not, arg_terms.at(0));
  }
  case AST_UID_EXPR_OP::COMPL: {
    ILA_WARN << "Complement not fully supported in smt-switch.";
    return solver_->make_term(smt::PrimOp::BVComp, arg_terms.at(0));
  }
  case AST_UID_EXPR_OP::AND: {
    auto op = expr->is_bool() ? smt::PrimOp::And : smt::PrimOp::BVAnd;
    return solver_->make_term(op, arg_terms.at(0), arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::OR: {
    auto op = expr->is_bool() ? smt::PrimOp::Or : smt::PrimOp::BVOr;
    return solver_->make_term(op, arg_terms.at(0), arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::XOR: {
    auto op = expr->is_bool() ? smt::PrimOp::Xor : smt::PrimOp::BVXor;
    return solver_->make_term(op, arg_terms.at(0), arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::SHL: {
    return solver_->make_term(smt::PrimOp::BVShl, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::ASHR: {
    return solver_->make_term(smt::PrimOp::BVAshr, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::LSHR: {
    return solver_->make_term(smt::PrimOp::BVLshr, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::ADD: {
    return solver_->make_term(smt::PrimOp::BVAdd, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::SUB: {
    return solver_->make_term(smt::PrimOp::BVSub, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::DIV: {
    // signed bv div (not int, not real)
    return solver_->make_term(smt::PrimOp::BVSdiv, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::SREM: {
    return solver_->make_term(smt::PrimOp::BVSrem, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::UREM: {
    return solver_->make_term(smt::PrimOp::BVUrem, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::SMOD: {
    return solver_->make_term(smt::PrimOp::BVSmod, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::MUL: {
    // bv mul (not int, not real)
    return solver_->make_term(smt::PrimOp::BVMul, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::EQ: {
    return solver_->make_term(smt::PrimOp::Equal, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::LT: {
    // bv signed lt (not unsigned, not real)
    return solver_->make_term(smt::PrimOp::BVSlt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::GT: {
    // bv signed gt (not unsigned, not real)
    return solver_->make_term(smt::PrimOp::BVSgt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::ULT: {
    // bv unsigned lt (not real)
    return solver_->make_term(smt::PrimOp::BVUlt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::UGT: {
    // bv unsigned gt (not real)
    return solver_->make_term(smt::PrimOp::BVUgt, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::LOAD: {
    return solver_->make_term(smt::PrimOp::Select, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::STORE: {
    return solver_->make_term(smt::PrimOp::Store, arg_terms.at(0),
                              arg_terms.at(1), arg_terms.at(2));
  }
  case AST_UID_EXPR_OP::CONCAT: {
    return solver_->make_term(smt::PrimOp::Concat, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::EXTRACT: {
    ILA_WARN << "Extract not fully supported in smt-switch.";
    auto p0 = solver_->make_term(expr->param(0), param_sort);
    auto p1 = solver_->make_term(expr->param(1), param_sort);
    return solver_->make_term(smt::PrimOp::Extract, arg_terms.at(0), p0, p1);
  }
  case AST_UID_EXPR_OP::ZEXT: {
    ILA_WARN << "Zero_Extend not fully supported in smt-switch.";
    auto p0 = solver_->make_term(expr->param(0), param_sort);
    return solver_->make_term(smt::PrimOp::Zero_Extend, arg_terms.at(0), p0);
  }
  case AST_UID_EXPR_OP::SEXT: {
    ILA_WARN << "Sign_Extend not fully supported in smt-switch.";
    auto p0 = solver_->make_term(expr->param(0), param_sort);
    return solver_->make_term(smt::PrimOp::Sign_Extend, arg_terms.at(0), p0);
  }
  case AST_UID_EXPR_OP::LROTATE: {
    ILA_WARN << "Rotate_Left not fully supported in smt-switch.";
    auto p0 = solver_->make_term(expr->param(0), param_sort);
    return solver_->make_term(smt::PrimOp::Rotate_Left, arg_terms.at(0), p0);
  }
  case AST_UID_EXPR_OP::RROTATE: {
    ILA_WARN << "Rotate_Right not fully supported in smt-switch.";
    auto p0 = solver_->make_term(expr->param(0), param_sort);
    return solver_->make_term(smt::PrimOp::Rotate_Right, arg_terms.at(0), p0);
  }
  case AST_UID_EXPR_OP::IMPLY: {
    return solver_->make_term(smt::PrimOp::Implies, arg_terms.at(0),
                              arg_terms.at(1));
  }
  case AST_UID_EXPR_OP::ITE: {
    return solver_->make_term(smt::PrimOp::Ite, arg_terms.at(0),
                              arg_terms.at(1), arg_terms.at(2));
  }
  case AST_UID_EXPR_OP::APP_FUNC: {
    auto expr_appfunc = std::static_pointer_cast<ExprOpAppFunc>(expr);
    auto func = expr_appfunc->func();

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
    auto func_term = solver_->make_term(f_name, func_sort);

    // apply func
    // XXX check this is the right order (no doc available)
    smt::TermVec all_terms;
    all_terms.push_back(func_term);
    for (size_t i = 0; i != arg_terms.size(); i++) {
      all_terms.push_back(arg_terms.at(i));
    }
    return solver_->make_term(smt::PrimOp::Apply, all_terms);
  }
  default: {
    ILA_CHECK(false) << "Op " << expr_op_uid << " not supported in smt-switch";
    return solver_->make_term(true);
  }
  }; // switch expr_op_uid
}

smt::Sort SmtSwitchItf::IlaSort2SmtSort(const SortPtr s) {
  auto sort_uid = GetUidSort(s);
  switch (sort_uid) {
  case AST_UID_SORT::BOOL: {
    return solver_->make_sort(smt::BOOL);
  }
  case AST_UID_SORT::BV: {
    return solver_->make_sort(smt::BV, s->bit_width());
  }
  case AST_UID_SORT::MEM: {
    return solver_->make_sort(smt::ARRAY,
                              solver_->make_sort(smt::BV, s->addr_width()),
                              solver_->make_sort(smt::BV, s->data_width()));
  }
  default: {
    ILA_CHECK(false) << "Unknown sort " << sort_uid;
    return solver_->make_sort(smt::BOOL);
  }
  }; // switch sort uid @ lambda Sort2Term
}

}; // namespace ilang

#endif // SMT_SWITCH_INTERFACE
