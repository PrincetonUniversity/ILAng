/// \file
/// Source for the smt-switch interface.

#include <ilang/config.h>

#ifdef SMTSWITCH_INTERFACE

#include <ilang/ila-mngr/u_smt_switch.h>
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
  smt::TermVec term_vec;

  // all arguments should already have Terms, put them in the placeholder
  size_t num = expr->arg_num();
  for (size_t i = 0; i != num; i++) {
    auto arg_i_expr = expr->arg(i);
    auto pos = expr_map_.find(arg_i_expr);
    // TODO fmt
    ILA_ASSERT(pos != expr_map_.end()) << "No Term found for {}th argument";
    term_vec.push_back(pos->second);
  }

  // get the Term based on different type of the ast node
  smt::Term res = solver_->make_term(true); // TODO

  // populate in the Term cache
  expr_map_.insert({expr, res});
}

}; // namespace ilang

#endif // SMT_SWITCH_INTERFACE
