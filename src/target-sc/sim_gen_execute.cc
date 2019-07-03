#include <ilang/target-sc/ila_sim.h>

#include <queue>

#include <ilang/ila/ast_fuse.h>
#include <ilang/util/log.h>

namespace ilang {

void IlaSim::execute_init(stringstream& execute_kernel, string& indent) {
  std::queue<InstrLvlAbsPtr> child_ila_queue;
  for (int i = 0; i < model_ptr_->child_num(); i++) {
    child_ila_queue.push(model_ptr_->child(i));
  }
  while(!child_ila_queue.empty()) {
    auto current_ila = child_ila_queue.front();
    child_ila_queue.pop();
    for(int i = 0; i < current_ila->child_num(); i++) {
      child_ila_queue.push(current_ila->child(i));
    }
    execute_kernel << indent << "init_" << current_ila->name() << "();" << endl; 
  }
}

void IlaSim::execute_parent_instructions(stringstream& execute_kernel,
                                         string& indent) {
  for (unsigned int i = 0; i < model_ptr_->instr_num(); i++) {
    execute_instruction(execute_kernel, indent, model_ptr_->instr(i));
  }
}

void IlaSim::execute_child_instructions(stringstream& execute_kernel,
                                        string& indent) {
  std::queue<InstrLvlAbsPtr> child_ila_queue;
  execute_kernel << indent << "while (1) {" << endl;
  increase_indent(indent);
  execute_kernel << indent << "int schedule_counter = 0;" << endl;
  for (unsigned int i = 0; i < model_ptr_->child_num(); i++)
    child_ila_queue.push(model_ptr_->child(i));
  while (!child_ila_queue.empty()) {
    InstrLvlAbsPtr child_ila = child_ila_queue.front();
    child_ila_queue.pop();
    for (unsigned int i = 0; i < child_ila->child_num(); i++)
      child_ila_queue.push(child_ila->child(i));
    for (unsigned int i = 0; i < child_ila->instr_num(); i++)
      execute_instruction(execute_kernel, indent, child_ila->instr(i), true);
  }
  execute_kernel << indent << "if (schedule_counter == 0) " << endl;
  execute_kernel << indent << "  break;" << endl;
  decrease_indent(indent);
  execute_kernel << indent << "}" << endl;
}

void IlaSim::execute_instruction(stringstream& execute_kernel, string& indent,
                                 const InstrPtr& instr_expr, bool child) {
  if (get_update_state_num(instr_expr) == 0)
    return;
  auto decode = instr_expr->decode();
  execute_decode(execute_kernel, indent, instr_expr);
  increase_indent(indent);
  for (auto updated_state_name : instr_expr->updated_states()) {
    auto updated_state = instr_expr->host()->state(updated_state_name);
    auto update_expr = instr_expr->update(updated_state_name);
    if (updated_state->name().id() == update_expr->name().id())
      continue;
    execute_state_update_func(execute_kernel, indent, instr_expr,
                              updated_state);
  }
  if (EXTERNAL_MEM_)
    execute_external_mem_load_begin(execute_kernel, indent, instr_expr);
  for (auto updated_state_name : instr_expr->updated_states()) {
    auto updated_state = instr_expr->host()->state(updated_state_name);
    auto update_expr = instr_expr->update(updated_state_name);
    if (updated_state->name().id() == update_expr->name().id())
      continue;
    execute_update_state(execute_kernel, indent, instr_expr, updated_state);
  }
  if (child)
    execute_kernel << indent << "schedule_counter++;" << endl;
  if (EXTERNAL_MEM_)
    execute_external_mem_load_end(execute_kernel, indent);
  decrease_indent(indent);
  execute_kernel << indent << "}" << endl;
}

void IlaSim::execute_decode(stringstream& execute_kernel, string& indent,
                            const InstrPtr& instr_expr) {
  string decode_func_name;
  if (readable_)
    decode_func_name = "decode_" + instr_expr->host()->name().str() + "_" +
                       instr_expr->name().str();
  else
    decode_func_name = "decode_" + to_string(instr_expr->decode()->name().id());

  execute_kernel << indent << "if (" << decode_func_name << "()) {" << endl;
  // TODO(yuex) delete the next line (generate debug code).
  // execute_kernel << "cout << \"" << decode_func_name << "\" << endl;" << endl;
}

void IlaSim::execute_state_update_func(stringstream& execute_kernel,
                                       string& indent,
                                       const InstrPtr& instr_expr,
                                       const ExprPtr& updated_state) {
  string updated_state_type =
      (updated_state->is_bool())
          ? "bool "
          : (updated_state->is_bv())
                ? "sc_biguint<" +
                      to_string(updated_state->sort()->bit_width()) + "> "
                : "";
  if (qemu_device_)
    updated_state_type = (updated_state->is_bv()) ? "uint" + to_string(updated_state->sort()->bit_width()) + "_t " : updated_state_type;
  string updated_state_name =
      updated_state->host()->name().str() + "_" + updated_state->name().str();

  string decode_func_name;
  if (readable_)
    decode_func_name = "decode_" + instr_expr->host()->name().str() + "_" +
                       instr_expr->name().str();
  else
    decode_func_name = "decode_" + to_string(instr_expr->decode()->name().id());
  string state_update_func_name =
      decode_func_name + "_update_" + updated_state_name;
  string mem_update_map = state_update_func_name + "_map";
  if (updated_state->is_mem())
    execute_kernel << indent << state_update_func_name << "(" << mem_update_map
                   << ");" << endl;
  else
    execute_kernel << indent << updated_state_type << updated_state_name
                   << "_next = " << state_update_func_name << "();" << endl;
}

void IlaSim::execute_update_state(stringstream& execute_kernel, string& indent,
                                  const InstrPtr& instr_expr,
                                  const ExprPtr& updated_state) {
  string updated_state_name =
      updated_state->host()->name().str() + "_" + updated_state->name().str();
  string decode_func_name;
  if (readable_)
    decode_func_name = "decode_" + instr_expr->host()->name().str() + "_" +
                       instr_expr->name().str();
  else
    decode_func_name = "decode_" + to_string(instr_expr->decode()->name().id());
  string state_update_func_name =
      decode_func_name + "_update_" + updated_state_name;
  string mem_update_map = state_update_func_name + "_map";

  if (updated_state->is_mem()) {
    if (EXTERNAL_MEM_)
      return;
    execute_kernel << indent << "for (std::map<int, int>::iterator it = "
                   << mem_update_map << ".begin(); it != " << mem_update_map
                   << ".end(); it++) {" << endl;
    increase_indent(indent);
    execute_kernel << indent << updated_state_name << "[it->first] = "
                   << "it->second;" << endl;
    decrease_indent(indent);
    execute_kernel << indent << "}" << endl;
  } else {
    execute_kernel << indent << updated_state_name << " = "
                   << updated_state_name << "_next;" << endl;
  }
}

void IlaSim::execute_external_mem_load_begin(stringstream& execute_kernel,
                                             string& indent,
                                             const InstrPtr& instr_expr) {
  dfs_ld_search_set_.clear();
  for (auto updated_state_name : instr_expr->updated_states()) {
    auto updated_state = instr_expr->host()->state(updated_state_name);
    auto update_expr = instr_expr->update(updated_state_name);
    bool state_not_updated =
        updated_state->name().id() == update_expr->name().id();
    if (state_not_updated)
      continue;
    auto DfsExternalMemLoad = [this](const ExprPtr& e) {
      dfs_external_mem_load(e);
    };
    update_expr->DepthFirstVisit(DfsExternalMemLoad);
  }
  if (!dfs_ld_search_set_.empty()) {
    execute_kernel << indent << "if (";
    for (auto iter = dfs_ld_search_set_.begin();
         iter != dfs_ld_search_set_.end(); iter++) {
      execute_kernel << "((c_" << (*iter) << "_ctrl == 0) | "
                     << "(c_" << (*iter) << "_ctrl == 2)) & ";
    }
    execute_kernel << "1) {" << endl;
    increase_indent(indent);
  }
}

void IlaSim::execute_external_mem_load_end(stringstream& execute_kernel,
                                           string& indent) {
  if (!dfs_ld_search_set_.empty()) {
    dfs_ld_search_set_.clear();
    decrease_indent(indent);
    execute_kernel << indent << "}" << endl;
  }
}

void IlaSim::execute_write_external_mem(stringstream& execute_kernel,
                                        string& indent) {
  for (auto it = external_st_set_.begin(); it != external_st_set_.end(); it++) {
    string mem_iterator = it->mem_map + "_iter";
    string mem_map = it->mem_map + "_map";
    string mem_map_size = mem_map + ".size()";
    string mem_write_valid = it->mem_str + "_write_valid";
    string mem_write_ready = it->mem_str + "_write_ready";
    string mem_write_address = it->mem_str + "_write_address";
    string mem_write_data = it->mem_str + "_write_data";

    execute_kernel << indent << "if (" << mem_iterator << " < " << mem_map_size
                   << ") {" << endl;
    increase_indent(indent);
    execute_kernel << indent << mem_write_valid << ".write(1);" << endl;
    execute_kernel << indent << "std::map<int, int>::iterator it = " << mem_map
                   << ".begin();" << endl;
    execute_kernel << indent << "for (int i = 0; i < " << mem_iterator
                   << "; i++)" << endl;
    execute_kernel << indent << "  it++;" << endl;
    execute_kernel << indent << mem_write_address << ".write(it->first);"
                   << endl;
    execute_kernel << indent << mem_write_data << ".write(it->second);" << endl;
    decrease_indent(indent);
    execute_kernel << indent << "}" << endl;
    execute_kernel << indent << "if (" << mem_iterator << " < " << mem_map
                   << ".size()) {" << endl;
    increase_indent(indent);
    execute_kernel << indent << "if (" << mem_write_ready << ".read() == 1) "
                   << endl;
    increase_indent(indent);
    execute_kernel << indent << mem_iterator << "++;" << endl;
    decrease_indent(indent);
    execute_kernel << indent << "return;" << endl;
    decrease_indent(indent);
    execute_kernel << indent << "}" << endl;
  }
}

void IlaSim::execute_read_external_mem(stringstream& execute_kernel,
                                       string& indent) {
  for (auto it = external_ld_set_.begin(); it != external_ld_set_.end(); it++) {
    auto mem_read_ctrl = it->dest_str + "_ctrl";
    auto mem_read_valid = it->mem_str + "_read_valid";
    auto mem_read_ready = it->mem_str + "_read_ready";
    auto mem_read_address = it->mem_str + "_read_address";
    auto mem_read_data = it->mem_str + "_data";

    execute_kernel << indent << "if (" << mem_read_ctrl << " == 1) {" << endl;
    increase_indent(indent);
    execute_kernel << indent << "if (" << mem_read_valid << ".read() == 1) {"
                   << endl;
    increase_indent(indent);
    execute_kernel << indent << mem_read_ctrl << " = 2;" << endl;
    execute_kernel << indent << it->dest_str << " = " << mem_read_data
                   << ".read();" << endl;
    execute_kernel << indent << mem_read_ready << ".write(0);" << endl;
    decrease_indent(indent);
    execute_kernel << indent << "} else {" << endl;
    increase_indent(indent);
    execute_kernel << indent << mem_read_address << ".write(" << it->addr_str
                   << ");" << endl;
    execute_kernel << indent << mem_read_ready << ".write(1);" << endl;
    execute_kernel << indent << "return;" << endl;
    decrease_indent(indent);
    execute_kernel << indent << "}" << endl;
    decrease_indent(indent);
    execute_kernel << indent << "}" << endl;
  }
}

void IlaSim::execute_external_mem_before_input(stringstream& execute_kernel,
                                               string& indent) {
  execute_kernel << indent << "if (";
  for (auto it = external_ld_set_.begin(); it != external_ld_set_.end(); it++)
    execute_kernel << "(" << it->dest_str << "_ctrl == 0) & ";
  execute_kernel << "1) {" << endl;
  increase_indent(indent);
}

void IlaSim::execute_external_mem_after_output(stringstream& execute_kernel,
                                               string& indent) {
  decrease_indent(indent);
  execute_kernel << indent << "}" << endl;
}

void IlaSim::execute_read_input(stringstream& execute_kernel, string& indent) {
  for (unsigned int i = 0; i < model_ptr_->input_num(); i++) {
    auto input = model_ptr_->input(i);
    execute_kernel << indent << model_ptr_->name() << "_" << input->name()
                   << " = " << model_ptr_->name() << "_" << input->name()
                   << "_in.read();" << endl;
  }
}

void IlaSim::execute_external_mem_return(stringstream& execute_kernel,
                                         string& indent) {
  string unfinished_st_cond = "";
  for (auto it = external_st_set_.begin(); it != external_st_set_.end(); it++)
    unfinished_st_cond +=
        "(" + it->mem_map + "_iter < " + it->mem_map + "_map.size()) & ";
  unfinished_st_cond.pop_back();
  unfinished_st_cond.pop_back();
  unfinished_st_cond.pop_back();
  execute_kernel << indent << "if (" << unfinished_st_cond << ")" << endl;
  execute_kernel << indent << "  return;" << endl;
  string unfinished_ld_cond = "";
  for (auto it = external_ld_set_.begin(); it != external_ld_set_.end(); it++) {
    unfinished_ld_cond += "(" + it->dest_str + "_ctrl == 1) | ";
  }
  unfinished_ld_cond.pop_back();
  unfinished_ld_cond.pop_back();
  unfinished_ld_cond.pop_back();
  execute_kernel << indent << "if (" << unfinished_ld_cond << ")" << endl;
  execute_kernel << indent << "  return;" << endl;
  for (auto it = external_ld_set_.begin(); it != external_ld_set_.end(); it++) {
    execute_kernel << indent << it->dest_str << "_ctrl = 0;" << endl;
  }
  for (auto it = external_st_set_.begin(); it != external_st_set_.end(); it++) {
    execute_kernel << indent << it->mem_map << "_map.clear();" << endl;
    execute_kernel << indent << it->mem_map << "_iter = 0;" << endl;
  }
}

void IlaSim::execute_write_output(stringstream& execute_kernel,
                                  string& indent) {
  for (unsigned int i = 0; i < model_ptr_->state_num(); i++) {
    auto state = model_ptr_->state(i);
    if (GetUidSort(state->sort()) == AST_UID_SORT::MEM) {
      ILA_WARN << "internal mem state " << state->name().str()
               << "doesn't have output port";
    } else
      execute_kernel << indent << model_ptr_->name() << "_"
                     << model_ptr_->state(i)->name() << "_out.write("
                     << model_ptr_->name() << "_"
                     << model_ptr_->state(i)->name() << ");" << endl;
  }
}

void IlaSim::execute_kernel_export(stringstream& execute_kernel) {
  ofstream outFile;
  outFile.open(export_dir_ + "compute.cc");
  outFile << execute_kernel.rdbuf();
  outFile.close();
}

void IlaSim::execute_kernel_mk_file() {
  if (qemu_device_) {
    mk_script_ << "g++ -I./ -c -o compute.o compute.cc " << endl;
    mk_script_ << "g++ -I./ -c -o help.o ../../src/help.cc " << endl;
  }
  else
    mk_script_ << "g++ -I. -I " << systemc_path_ << "/include/ "
               << "-L. -L " << systemc_path_ << "/lib-linux64/ "
               << "-Wl,-rpath=" << systemc_path_ << "/lib-linux64/ "
               << "-c -o "
               << "compute.o compute.cc "
               << "-lsystemc" << endl;
  obj_list_ << "compute.o ";
}

void IlaSim::execute_kernel_header() {
  header_ << header_indent_ << "void compute();" << endl;
}

}; // namespace ilang
