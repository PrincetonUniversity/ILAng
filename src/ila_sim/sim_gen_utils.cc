#include "ila_sim.h"

namespace ilang {

string IlaSim::get_arg_str(const ExprPtr &arg) {
  string arg_str;
  if (GetUidExpr(arg) == AST_UID_EXPR::VAR)
    arg_str = arg->host()->name().str() + "_" + arg->name().str();
  else if (GetUidExpr(arg) == AST_UID_EXPR::CONST) {
    auto arg_const = dynamic_pointer_cast<ExprConst>(arg);
    if (arg->is_bool()) {
      auto arg_val = arg_const->val_bool()->val();
      if (arg_val)
        arg_str = "true";
      else
        arg_str = "false";
    } else if (arg->is_bv())
      arg_str = to_string(arg_const->val_bv()->val());
    else {
      arg_str = "c_" + to_string(arg->name().id());
    }
  } else
    arg_str = "c_" + to_string(arg->name().id());
  return arg_str;
}

void IlaSim::increase_indent(string &indent) { indent += "  "; }

void IlaSim::decrease_indent(string &indent) {
  indent.pop_back();
  indent.pop_back();
}

int IlaSim::get_update_state_num(const InstrPtr &instr_expr) {
  int update_state_num = 0;
  for (auto updated_state_name : instr_expr->updated_states()) {
    auto update_expr = instr_expr->update(updated_state_name);
    auto updated_state = instr_expr->host()->state(updated_state_name);
    if (updated_state->name().id() != update_expr->name().id())
      update_state_num += 1;
  }
  return update_state_num;
}

bool IlaSim::load_from_store_analysis(const ExprPtr &expr) {
  ld_st_counter_ = 0;
  dfs_load_from_store(expr);
  return ld_st_counter_ != 0;
}

void IlaSim::declare_variable_with_id(size_t id, string v_type, string v_name) {
  if (declared_id_set_.find(id) == declared_id_set_.end()) {
    declared_id_set_.insert(id);
    header_ << header_indent_ << v_type << v_name << ";" << endl;
  }
}

}; // namespace ilang
