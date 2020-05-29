/// \file
/// Source for the smt-switch interface.

#include <ilang/config.h>

#ifdef SMTSWITCH_INTERFACE

#include <fmt/format.h>

#include <ilang/ila-mngr/u_smt_switch.h>
#include <ilang/ila/ast_fuse.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

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
  // for compatibility to z3
  auto prefix = (expr->host()) ? expr->host()->GetRootName() : "";
  auto e_name = expr->name().format_str(prefix, suffix_);

  auto sort_uid = GetUidSort(expr->sort());

  switch (sort_uid) {
  case AST_UID_SORT::BOOL: {
    return solver_->make_symbol(e_name, solver_->make_sort(smt::BOOL));
  }
  case AST_UID_SORT::BV: {
    auto bw = expr->sort()->bit_width();
    return solver_->make_symbol(e_name, solver_->make_sort(smt::BV, bw));
  }
  case AST_UID_SORT::MEM: {
    auto aw = expr->sort()->addr_width();
    auto dw = expr->sort()->data_width();
    return solver_->make_symbol(
        e_name, solver_->make_sort(smt::ARRAY,
                                   solver_->make_sort(smt::BV, aw), // address
                                   solver_->make_sort(smt::BV, dw)  // data
                                   ));
  }
  default: {
    ILA_CHECK(false) << fmt::format("Unknown sort {} for ", sort_uid) << expr;
    return solver_->make_term(true);
  }
  }; // switch sort_uid
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
  // TODO
  return solver_->make_term(true);
}

}; // namespace ilang

#endif // SMT_SWITCH_INTERFACE
