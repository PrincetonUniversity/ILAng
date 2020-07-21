#include <queue>

#include <fmt/format.h>

#include <ilang/target-sc/ila_sim.h>

#include "ast_fuse.h"

namespace ilang {

std::string IlaSim::get_arg_str(const ExprPtr& arg) {
  std::string arg_str;
  if (GetUidExpr(arg) == AST_UID_EXPR::VAR)
    arg_str = arg->host()->name().str() + "_" + arg->name().str();
  else if (GetUidExpr(arg) == AST_UID_EXPR::CONST) {
    auto arg_const = std::dynamic_pointer_cast<ExprConst>(arg);
    if (arg->is_bool()) {
      auto arg_val = arg_const->val_bool()->val();
      if (arg_val)
        arg_str = "true";
      else
        arg_str = "false";
    } else if (arg->is_bv())
      arg_str = std::to_string(arg_const->val_bv()->val());
    else {
      arg_str = "c_" + std::to_string(arg->name().id());
    }
  } else
    arg_str = "c_" + std::to_string(arg->name().id());
  return arg_str;
}

void IlaSim::increase_indent(std::string& indent) { indent += "  "; }

void IlaSim::decrease_indent(std::string& indent) {
  indent.pop_back();
  indent.pop_back();
}

int IlaSim::get_update_state_num(const InstrPtr& instr_expr) {
  int update_state_num = 0;
  for (auto updated_state_name : instr_expr->updated_states()) {
    auto update_expr = instr_expr->update(updated_state_name);
    auto updated_state = instr_expr->host()->state(updated_state_name);
    if (updated_state->name().id() != update_expr->name().id())
      update_state_num += 1;
  }
  return update_state_num;
}

bool IlaSim::load_from_store_analysis(const ExprPtr& expr) {
  ld_st_counter_ = 0;
  auto DfsLoadFromStore = [this](const ExprPtr& e) { dfs_load_from_store(e); };
  expr->DepthFirstVisit(DfsLoadFromStore);
  return ld_st_counter_ != 0;
}

void IlaSim::declare_variable_with_id(size_t id, const std::string& v_type,
                                      const std::string& v_name) {
  if (declared_id_set_.find(id) == declared_id_set_.end()) {
    declared_id_set_.insert(id);
    header_ << header_indent_ << fmt::format("{} {};\n", v_type, v_name);
  }
}

void IlaSim::int_var_width_scan() {
  std::queue<InstrLvlAbsPtr> ila_queue;
  ila_queue.push(model_ptr_);
  while (!ila_queue.empty()) {
    auto current_ila = ila_queue.front();
    ila_queue.pop();
    for (unsigned int i = 0; i < current_ila->child_num(); i++)
      ila_queue.push(current_ila->child(i));
    for (unsigned int i = 0; i < current_ila->instr_num(); i++) {
      auto current_instr = current_ila->instr(i);
      auto DfsIntVarWidth = [this](const ExprPtr& e) { dfs_int_var_width(e); };
      current_instr->decode()->DepthFirstVisit(DfsIntVarWidth);
      for (auto updated_state_name : current_instr->updated_states()) {
        current_instr->update(updated_state_name)
            ->DepthFirstVisit(DfsIntVarWidth);
      }
    }
  }
}

}; // namespace ilang
