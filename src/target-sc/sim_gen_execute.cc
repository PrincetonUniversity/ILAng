#include <queue>
#include <string>

#include <fmt/format.h>

#include <ilang/target-sc/ila_sim.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>

#include "ast_fuse.h"

namespace ilang {

void IlaSim::execute_init(std::stringstream& execute_kernel,
                          std::string& indent) {
  std::queue<InstrLvlAbsPtr> child_ila_queue;
  for (unsigned int i = 0; i < model_ptr_->child_num(); i++) {
    child_ila_queue.push(model_ptr_->child(i));
  }
  while (!child_ila_queue.empty()) {
    auto current_ila = child_ila_queue.front();
    child_ila_queue.pop();
    for (unsigned int i = 0; i < current_ila->child_num(); i++) {
      child_ila_queue.push(current_ila->child(i));
    }
    execute_kernel << indent << "init_" << current_ila->name() << "();\n";
  }
}

void IlaSim::execute_parent_instructions(std::stringstream& execute_kernel,
                                         std::string& indent) {
  // 04042020: add a file output for the instructions issued.
  for (unsigned int i = 0; i < model_ptr_->instr_num(); i++) {
    execute_instruction(execute_kernel, indent, model_ptr_->instr(i));
  }
}

void IlaSim::execute_child_instructions(std::stringstream& execute_kernel,
                                        std::string& indent) {
  std::queue<InstrLvlAbsPtr> child_ila_queue;
  execute_kernel << indent << "while (1) {\n";
  increase_indent(indent);
  execute_kernel << indent << "int schedule_counter = 0;\n";
  for (unsigned int i = 0; i < model_ptr_->child_num(); i++) {
    child_ila_queue.push(model_ptr_->child(i));
  }
  while (!child_ila_queue.empty()) {
    InstrLvlAbsPtr child_ila = child_ila_queue.front();
    child_ila_queue.pop();
    for (unsigned int i = 0; i < child_ila->child_num(); i++) {
      child_ila_queue.push(child_ila->child(i));
    }
    for (unsigned int i = 0; i < child_ila->instr_num(); i++) {
      execute_instruction(execute_kernel, indent, child_ila->instr(i), true);
    }
  }
  execute_kernel << indent << "if (schedule_counter == 0)\n";
  execute_kernel << indent << "  break;\n";
  decrease_indent(indent);
  execute_kernel << indent << "}\n";
}

void IlaSim::execute_instruction(std::stringstream& execute_kernel,
                                 std::string& indent,
                                 const InstrPtr& instr_expr, bool child) {
  if (get_update_state_num(instr_expr) == 0) {
    return;
  }
  auto decode = instr_expr->decode();
  execute_decode(execute_kernel, indent, instr_expr);
  increase_indent(indent);
  for (auto updated_state_name : instr_expr->updated_states()) {
    auto updated_state = instr_expr->host()->state(updated_state_name);
    auto update_expr = instr_expr->update(updated_state_name);
    if (updated_state->name().id() == update_expr->name().id()) {
      continue;
    }
    execute_state_update_func(execute_kernel, indent, instr_expr,
                              updated_state);
  }
  if (EXTERNAL_MEM_) {
    execute_external_mem_load_begin(execute_kernel, indent, instr_expr);
  }
  for (auto updated_state_name : instr_expr->updated_states()) {
    auto updated_state = instr_expr->host()->state(updated_state_name);
    auto update_expr = instr_expr->update(updated_state_name);
    if (updated_state->name().id() == update_expr->name().id()) {
      continue;
    }
    execute_update_state(execute_kernel, indent, instr_expr, updated_state);
  }
  if (child) {
    execute_kernel << indent << "schedule_counter++;\n";
  }
  if (EXTERNAL_MEM_) {
    execute_external_mem_load_end(execute_kernel, indent);
  }

  // print current instruction information to the terminal
  execute_kernel << "#ifdef ILATOR_VERBOSE\n";

  execute_kernel << indent << "instr_log << "
                 << "\"Instr NO.\" << "
                 << "std::to_string(instr_cntr) << ";
  execute_kernel << "\'\\t\'"
                 << " << ";
  execute_kernel << "\"" << instr_expr->name().str() << "\""
                 << " << "
                 << "\'\\t\'"
                 << " << ";
  execute_kernel << "\"is activated\\n\"; \n";
  execute_kernel << indent << "instr_cntr++;\n";

  execute_kernel << "#endif // ILATOR_VERBOSE\n";

  decrease_indent(indent);
  execute_kernel << indent << "}\n";
}

void IlaSim::execute_decode(std::stringstream& execute_kernel,
                            std::string& indent, const InstrPtr& instr_expr) {
  std::string decode_func_name;
  if (readable_) {
    decode_func_name = "decode_" + instr_expr->host()->name().str() + "_" +
                       instr_expr->name().str();
  } else {
    decode_func_name =
        "decode_" + std::to_string(instr_expr->decode()->name().id());
  }

  execute_kernel << indent << "if (" << decode_func_name << "()) {\n";
  // TODO(yuex) delete the next line (generate debug code).
  // execute_kernel << "cout << \"" << decode_func_name << "\" << std::endl;" <<
  // std::endl;
}

void IlaSim::execute_state_update_func(std::stringstream& execute_kernel,
                                       std::string& indent,
                                       const InstrPtr& instr_expr,
                                       const ExprPtr& updated_state) {
  auto updated_state_type = get_type_str(updated_state);

  auto updated_state_name =
      fmt::format("{}_{}", updated_state->host()->name().str(),
                  updated_state->name().str());

  auto decode_func_name =
      (readable_)
          ? fmt::format("decode_{}_{}", instr_expr->host()->name().str(),
                        instr_expr->name().str())
          : fmt::format("decode_{}", instr_expr->decode()->name().id());

  auto state_update_func_name =
      fmt::format("{}_update_{}", decode_func_name, updated_state_name);

  auto mem_update_map = state_update_func_name + "_map";

  if (updated_state->is_mem()) {
    execute_kernel << fmt::format("{0}{1}({2});\n", indent, // 0
                                  state_update_func_name,   // 1
                                  mem_update_map            // 2
    );
  } else {
    execute_kernel << fmt::format("{0}{1} {2}_next = {3}();\n", indent, // 0
                                  updated_state_type,                   // 1
                                  updated_state_name,                   // 2
                                  state_update_func_name                // 3
    );
  }
}

void IlaSim::execute_update_state(std::stringstream& execute_kernel,
                                  std::string& indent,
                                  const InstrPtr& instr_expr,
                                  const ExprPtr& updated_state) {
  auto updated_state_name =
      fmt::format("{}_{}", updated_state->host()->name().str(),
                  updated_state->name().str());

  auto decode_func_name =
      (readable_)
          ? fmt::format("decode_{}_{}", instr_expr->host()->name().str(),
                        instr_expr->name().str())
          : fmt::format("decode_{}", instr_expr->decode()->name().id());

  auto state_update_func_name =
      fmt::format("{}_update_{}", decode_func_name, updated_state_name);

  auto mem_update_map = state_update_func_name + "_map";

  if (updated_state->is_mem()) {
    if (EXTERNAL_MEM_) {
      return;
    }

    execute_kernel << fmt::format(
        "{0}for (auto it = {1}.begin(); it != {1}.end(); it++) {{\n"
        "{0}  {2}[it->first] = it->second;\n"
        "{0}}}\n",
        indent,            // 0
        mem_update_map,    // 1
        updated_state_name // 2
    );

  } else {
    execute_kernel << indent;
    execute_kernel << fmt::format("{0} = {0}_next;\n", updated_state_name);
  }
}

void IlaSim::execute_external_mem_load_begin(std::stringstream& execute_kernel,
                                             std::string& indent,
                                             const InstrPtr& instr_expr) {
  dfs_ld_search_set_.clear();
  for (auto updated_state_name : instr_expr->updated_states()) {
    auto updated_state = instr_expr->host()->state(updated_state_name);
    auto update_expr = instr_expr->update(updated_state_name);
    bool state_not_updated =
        updated_state->name().id() == update_expr->name().id();
    if (state_not_updated) {
      continue;
    }
    auto DfsExternalMemLoad = [this](const ExprPtr& e) {
      dfs_external_mem_load(e);
    };
    update_expr->DepthFirstVisit(DfsExternalMemLoad);
  }
  if (!dfs_ld_search_set_.empty()) {
    execute_kernel << indent << "if (";

    for (auto& elem : dfs_ld_search_set_) {
      execute_kernel << fmt::format(
          "((c_{0}_ctrl == 0) | (c_{0}_ctrl == 2)) & ", elem);
    }

    execute_kernel << "1) {\n";
    increase_indent(indent);
  }
}

void IlaSim::execute_external_mem_load_end(std::stringstream& execute_kernel,
                                           std::string& indent) {
  if (!dfs_ld_search_set_.empty()) {
    dfs_ld_search_set_.clear();
    decrease_indent(indent);
    execute_kernel << indent << "}\n";
  }
}

void IlaSim::execute_write_external_mem(std::stringstream& execute_kernel,
                                        std::string& indent) {
  for (auto it = external_st_set_.begin(); it != external_st_set_.end(); it++) {
    std::string mem_iterator = it->mem_map + "_iter";
    std::string mem_map = it->mem_map + "_map";
    std::string mem_write_valid = it->mem_str + "_write_valid";
    std::string mem_write_ready = it->mem_str + "_write_ready";
    std::string mem_write_address = it->mem_str + "_write_address";
    std::string mem_write_data = it->mem_str + "_write_data";

    execute_kernel << fmt::format("{0}if ({1} < {2}.size()) {{\n"
                                  "{0}  {3}.write(1);\n"
                                  "{0}  auto it = {2}.begin();\n"
                                  "{0}  for (int i = 0; i < {1}; i++)\n"
                                  "{0}    it++;\n"
                                  "{0}  {4}.write(it->first);\n"
                                  "{0}  {5}.write(it->second);\n"
                                  "{0}}}\n",
                                  indent,            // 0
                                  mem_iterator,      // 1
                                  mem_map,           // 2
                                  mem_write_valid,   // 3
                                  mem_write_address, // 4
                                  mem_write_data     // 5
    );

    execute_kernel << fmt::format("{0}if ({1} < {2}.size()) {{\n"
                                  "{0}  if ({3}.read() == 1)\n"
                                  "{0}    {1}++;\n"
                                  "{0}  return;\n"
                                  "{0}}}\n",
                                  indent,         // 0
                                  mem_iterator,   // 1
                                  mem_map,        // 2
                                  mem_write_ready // 3
    );
  }
}

void IlaSim::execute_read_external_mem(std::stringstream& execute_kernel,
                                       std::string& indent) {
  for (auto it = external_ld_set_.begin(); it != external_ld_set_.end(); it++) {
    auto mem_read_ctrl = it->dest_str + "_ctrl";
    auto mem_read_valid = it->mem_str + "_read_valid";
    auto mem_read_ready = it->mem_str + "_read_ready";
    auto mem_read_address = it->mem_str + "_read_address";
    auto mem_read_data = it->mem_str + "_data";

    execute_kernel << fmt::format("{0}if ({1} == 1) {{\n"
                                  "{0}  if ({2}.read() == 1) {{\n"
                                  "{0}    {1} = 2;\n"
                                  "{0}    {3} = {4}.read();\n"
                                  "{0}    {5}.write(0);\n"
                                  "{0}  }} else {{\n"
                                  "{0}    {6}.write({7});\n"
                                  "{0}    {5}.write(1);\n"
                                  "{0}    return;\n"
                                  "{0}  }}\n"
                                  "{0}}}\n",
                                  indent,           // 0
                                  mem_read_ctrl,    // 1
                                  mem_read_valid,   // 2
                                  it->dest_str,     // 3
                                  mem_read_data,    // 4
                                  mem_read_ready,   // 5
                                  mem_read_address, // 6
                                  it->addr_str      // 7
    );
  }
}

void IlaSim::execute_external_mem_before_input(
    std::stringstream& execute_kernel, std::string& indent) {
  execute_kernel << indent << "if (";
  for (auto it = external_ld_set_.begin(); it != external_ld_set_.end(); it++) {
    execute_kernel << fmt::format("({}_ctrl == 0) & ", it->dest_str);
  }
  execute_kernel << "1) {\n";
  increase_indent(indent);
}

void IlaSim::execute_external_mem_after_output(
    std::stringstream& execute_kernel, std::string& indent) {
  decrease_indent(indent);
  execute_kernel << indent << "}\n";
}

void IlaSim::execute_read_input(std::stringstream& execute_kernel,
                                std::string& indent) {
  for (unsigned int i = 0; i < model_ptr_->input_num(); i++) {
    auto input = model_ptr_->input(i);
    execute_kernel << indent
                   << fmt::format("{0}_{1} = {0}_{1}_in.read();\n",
                                  model_ptr_->name().str(),
                                  input->name().str());
  }
}

void IlaSim::execute_external_mem_return(std::stringstream& execute_kernel,
                                         std::string& indent) {
  std::string unfinished_st_cond = "";
  for (auto it = external_st_set_.begin(); it != external_st_set_.end(); it++) {
    unfinished_st_cond +=
        "(" + it->mem_map + "_iter < " + it->mem_map + "_map.size()) & ";
  }
  unfinished_st_cond.pop_back();
  unfinished_st_cond.pop_back();
  unfinished_st_cond.pop_back();
  execute_kernel << indent << "if (" << unfinished_st_cond << ")\n";
  execute_kernel << indent << "  return;\n";
  std::string unfinished_ld_cond = "";
  for (auto it = external_ld_set_.begin(); it != external_ld_set_.end(); it++) {
    unfinished_ld_cond += "(" + it->dest_str + "_ctrl == 1) | ";
  }
  unfinished_ld_cond.pop_back();
  unfinished_ld_cond.pop_back();
  unfinished_ld_cond.pop_back();
  execute_kernel << indent << "if (" << unfinished_ld_cond << ")\n";
  execute_kernel << indent << "  return;\n";
  for (auto it = external_ld_set_.begin(); it != external_ld_set_.end(); it++) {
    execute_kernel << indent << it->dest_str << "_ctrl = 0;\n";
  }
  for (auto it = external_st_set_.begin(); it != external_st_set_.end(); it++) {
    execute_kernel << indent << it->mem_map << "_map.clear();\n";
    execute_kernel << indent << it->mem_map << "_iter = 0;\n";
  }
}

void IlaSim::execute_write_output(std::stringstream& execute_kernel,
                                  std::string& indent) {
#if 0
  for (unsigned int i = 0; i < model_ptr_->state_num(); i++) {
    auto state = model_ptr_->state(i);
    if (GetUidSort(state->sort()) == AST_UID_SORT::MEM) {
      ILA_WARN << "internal mem state " << state->name().str()
               << "doesn't have output port";
    } else
      execute_kernel << indent << model_ptr_->name() << "_"
                     << model_ptr_->state(i)->name() << "_out.write("
                     << model_ptr_->name() << "_"
                     << model_ptr_->state(i)->name() << ");\n";
  }
#endif
}

void IlaSim::execute_kernel_export(std::stringstream& execute_kernel) {
  std::ofstream outFile;

  std::string file_name = "compute.cc";
  if (cmake_support_) {
    file_name = os_portable_append_dir("src", file_name);
  }

  outFile.open(os_portable_append_dir(export_dir_, file_name));
  outFile << execute_kernel.rdbuf();
  outFile.close();
}

void IlaSim::execute_kernel_mk_file() {
  if (qemu_device_) {
    mk_script_ << "g++ -I./ -c -o compute.o compute.cc\n";
    mk_script_ << "g++ -I./ -c -o help.o ../../uninterpreted_func/"
               << "uninterpreted_func.cc\n";
  } else
    mk_script_ << "g++ -I. -I " << systemc_path_ << "/include/ "
               << "-L. -L " << systemc_path_ << "/lib-linux64/ "
               << "-Wl,-rpath=" << systemc_path_ << "/lib-linux64/ -std=c++11 "
               << "-g -c -o "
               << "compute.o compute.cc "
               << "-lsystemc\n";
  obj_list_ << "compute.o ";

  if (cmake_support_) {
    source_file_list_.push_back("compute.cc");
  }
}

void IlaSim::execute_kernel_header() {
  header_ << header_indent_ << "void compute();\n";
}

}; // namespace ilang
