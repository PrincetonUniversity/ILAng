// sim_gen_state_update.cc
#include <ilang/target-sc/ila_sim.h>

#include <fmt/format.h>

#include <ilang/util/fs.h>
#include <ilang/util/log.h>

#include "ast_fuse.h"

namespace ilang {

void IlaSim::create_state_update(const InstrPtr& instr_expr) {
  for (auto updated_state_name : instr_expr->updated_states()) {
    std::stringstream state_update_function;
    std::string indent = "";
    auto update_expr = instr_expr->update(updated_state_name);
    auto update_expr_id = update_expr->name().id();
    auto updated_state = instr_expr->host()->state(updated_state_name);
    auto state_update_func_name =
        (readable_) ? fmt::format("decode_{}_{}_update_{}_{}",
                                  instr_expr->host()->name().str(),
                                  instr_expr->name().str(),
                                  updated_state->host()->name().str(),
                                  updated_state->name().str())
                    : fmt::format("decode_{}_update_{}_{}",
                                  instr_expr->decode()->name().id(),
                                  updated_state->host()->name().str(),
                                  updated_state->name().str());

    ILA_CHECK(!load_from_store_analysis(update_expr))
        << "Load-after-store is not supported in sc-target generation";
    bool state_not_updated = updated_state->name().id() == update_expr_id;
    if (state_not_updated) {
      continue;
    }
    state_update_decl(state_update_function, indent, updated_state, update_expr,
                      state_update_func_name);
    auto DfsKernel = [this, &state_update_function, &indent](const ExprPtr& e) {
      dfs_kernel(state_update_function, indent, e);
    };
    update_expr->DepthFirstVisit(DfsKernel);
    state_update_return(state_update_function, indent, updated_state,
                        update_expr);
    state_update_export(state_update_function, state_update_func_name);
    state_update_mk_file(state_update_func_name);
  }
}

void IlaSim::mem_state_update_decl(std::stringstream& state_update_function,
                                   std::string& indent, const ExprPtr& expr) {
  auto DfsKernel = [this, &state_update_function, &indent](const ExprPtr& e) {
    dfs_kernel(state_update_function, indent, e);
  };
  auto expr_uid = GetUidExpr(expr);
  if (expr_uid == AST_UID_EXPR::OP) {
    auto expr_op_uid = GetUidExprOp(expr);
    auto expr_sort_uid = GetUidSort(expr->sort());
    if ((expr_op_uid == AST_UID_EXPR_OP::ITE) &&
        (expr_sort_uid == AST_UID_SORT::MEM)) {
      auto id = expr->name().id();
      bool store_ite_not_defined =
          (defined_store_ite_set_.find(id) == defined_store_ite_set_.end());
      if (store_ite_not_defined) {
        defined_store_ite_set_.insert(expr->name().id());

        header_ << header_indent_ << "void ite_" << id
                << "(std::map<int, int>& mem_update_map);\n";
        state_update_function << indent << "void " << model_ptr_->name()
                              << "::ite_" << id
                              << "(std::map<int, int>& mem_update_map) {\n";
        increase_indent(indent);
        auto cond_arg = expr->arg(0);
        cond_arg->DepthFirstVisit(DfsKernel);
        auto cond_str = get_arg_str(cond_arg);
        state_update_function << indent << "if (" << cond_str << ") {\n";
        increase_indent(indent);
        auto true_arg = expr->arg(1);
        true_arg->DepthFirstVisit(DfsKernel);
        decrease_indent(indent);
        state_update_function << indent << "} else {\n";
        increase_indent(indent);
        auto false_arg = expr->arg(2);
        false_arg->DepthFirstVisit(DfsKernel);
        decrease_indent(indent);
        state_update_function << indent << "}\n";
        decrease_indent(indent);
        state_update_function << indent << "};\n";
      }
    }
  }
}

void IlaSim::state_update_export(std::stringstream& state_update_function,
                                 std::string& state_update_func_name) {
  std::ofstream outFile;

  auto file_name = fmt::format("{}.cc", state_update_func_name);
  if (cmake_support_) {
    file_name = os_portable_append_dir("src", file_name);
  }

  outFile.open(os_portable_append_dir(export_dir_, file_name));
  outFile << state_update_function.rdbuf();
  outFile.close();
}

void IlaSim::state_update_mk_file(std::string& state_update_func_name) {
  if (qemu_device_)
    mk_script_ << "g++ -I./ -c -o " << state_update_func_name << ".o "
               << state_update_func_name << ".cc\n";
  else
    mk_script_ << "g++ -I. -I " << systemc_path_ << "/include/ "
               << "-L. -L " << systemc_path_ << "/lib-linux64/ "
               << "-Wl,-rpath=" << systemc_path_ << "/lib-linux64/ -std=c++11 "
               << "-g -c -o " << state_update_func_name << ".o "
               << state_update_func_name << ".cc "
               << "-lsystemc\n";
  obj_list_ << state_update_func_name << ".o ";

  if (cmake_support_) {
    source_file_list_.push_back(fmt::format("{}.cc", state_update_func_name));
  }
}

void IlaSim::state_update_decl(std::stringstream& state_update_function,
                               std::string& indent,
                               const ExprPtr& updated_state,
                               const ExprPtr& update_expr,
                               std::string& state_update_func_name) {
  searched_id_set_.clear();
  if (!qemu_device_) {
    state_update_function << indent << "#include \"systemc.h\"\n";
  }
  state_update_function << indent
                        << fmt::format("#include \"{}.h\"\n",
                                       model_ptr_->name().str());

  if (updated_state->is_mem()) {
    auto MemStateUpdateDecl = [this, &state_update_function,
                               &indent](const ExprPtr& e) {
      mem_state_update_decl(state_update_function, indent, e);
    };
    update_expr->DepthFirstVisit(MemStateUpdateDecl);
  }

  std::string return_type =
      (updated_state->is_bool())
          ? "bool"
          : (updated_state->is_mem())
                ? "void"
                : ("sc_biguint<" +
                   std::to_string(updated_state->sort()->bit_width()) + ">");
  if (qemu_device_)
    return_type =
        (updated_state->is_bv())
            ? ("uint" + std::to_string(updated_state->sort()->bit_width()) +
               "_t")
            : return_type;

  std::string arg_list =
      (updated_state->is_mem()) ? "(std::map<int, int>& mem_update_map)" : "()";
  state_update_function << fmt::format("{0}{1} {2}::{3}{4} {{\n", indent,
                                       return_type,              // 1
                                       model_ptr_->name().str(), // 2
                                       state_update_func_name,   // 3
                                       arg_list);                // 4

  increase_indent(indent);
  std::string pre_dfs =
      (updated_state->is_mem()) ? indent + "mem_update_map.clear();\n" : "";
  state_update_function << pre_dfs;

  if (updated_state->is_mem()) {
    header_ << fmt::format("{}std::map<int, int> {}_map;\n", header_indent_,
                           state_update_func_name);
  }

  header_ << fmt::format("{}{} {}{};\n", header_indent_, return_type,
                         state_update_func_name, arg_list);

  if ((updated_state->is_mem()) && (EXTERNAL_MEM_)) {
    header_ << header_indent_ << "int " << state_update_func_name << "_iter;\n";
    auto mem_map_str = state_update_func_name;
    auto mem_str =
        updated_state->host()->name().str() + "_" + updated_state->name().str();
    st_info store_info;
    store_info.mem_map = mem_map_str;
    store_info.mem_str = mem_str;
    external_st_set_.push_back(store_info);
  }
}

void IlaSim::state_update_return(std::stringstream& state_update_function,
                                 std::string& indent,
                                 const ExprPtr& updated_state,
                                 const ExprPtr& update_expr) {
  std::string return_str;
  if (GetUidExpr(update_expr) == AST_UID_EXPR::VAR) {
    return_str =
        update_expr->host()->name().str() + "_" + update_expr->name().str();
  } else if (GetUidExpr(update_expr) == AST_UID_EXPR::OP) {
    return_str = "c_" + std::to_string(update_expr->name().id());
  } else {
    auto expr_const = std::dynamic_pointer_cast<ExprConst>(update_expr);
    if (updated_state->is_bv())
      return_str = std::to_string(expr_const->val_bv()->val());
    else if (updated_state->is_bool())
      return_str = (expr_const->val_bool()->val()) ? "true" : "false";
    else
      return_str = "";
  }
  if (!updated_state->is_mem())
    state_update_function << indent << "return " << return_str << ";\n";
  decrease_indent(indent);
  state_update_function << indent << "};\n";
}

}; // namespace ilang
