/// \file Source of generating Jasper accepted problem, vlg, mem, script
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_jasper.h>

#include <algorithm>
#include <fstream>
#include <iostream>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

VlgSglTgtGen_Jasper::VlgSglTgtGen_Jasper(
    const std::string&
        output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                               // be used to verify invariants
    const InstrLvlAbsPtr& ila_ptr, const VerilogGenerator::VlgGenConfig& config,
    nlohmann::json& _rf_vmap, nlohmann::json& _rf_cond,
    VlgTgtSupplementaryInfo& _supplementary_info, VerilogInfo* _vlg_info_ptr,
    const std::string& vlg_mod_inst_name, const std::string& ila_mod_inst_name,
    const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const vtg_config_t& vtg_config, backend_selector backend,
    const target_type_t& target_tp, advanced_parameters_t* adv_ptr)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond,
                   _supplementary_info, _vlg_info_ptr, vlg_mod_inst_name,
                   ila_mod_inst_name, wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, backend, target_tp,
                   adv_ptr) {}

void VlgSglTgtGen_Jasper::add_wire_assign_assumption(
    const std::string& varname, const std::string& expression,
    const std::string& dspt) {
  // a plain assign
  vlg_wrapper.add_assign_stmt(varname, expression);
}

void VlgSglTgtGen_Jasper::add_reg_cassign_assumption(
    const std::string& varname, const std::string& expression, int width,
    const std::string& cond, const std::string& dspt) {

  std::string rand_in_name = "__" + varname + "_init__";
  vlg_wrapper.add_input(rand_in_name, width);
  vlg_wrapper.add_wire(rand_in_name, width);

  vlg_wrapper.add_init_stmt(varname + " <= " + rand_in_name + ";");
  vlg_wrapper.add_always_stmt(varname + " <= " + varname + ";");
  add_an_assumption(
      "(~(" + cond + ") || ((" + varname + ") == (" + expression + ")))", dspt);
}

/// Add an assumption
void VlgSglTgtGen_Jasper::add_an_assumption(const std::string& aspt,
                                            const std::string& dspt) {
  assumptions.push_back(std::make_pair(aspt, dspt));
}
/// Add an assertion
void VlgSglTgtGen_Jasper::add_an_assertion(const std::string& asst,
                                           const std::string& dspt) {
  assertions.push_back(std::make_pair(asst, dspt));
}

/// Add an assumption
void VlgSglTgtGen_Jasper::add_a_direct_assumption(const std::string& aspt,
                                                  const std::string& dspt) {
  assumptions.push_back(std::make_pair(aspt, dspt));
}
/// Add an assertion
void VlgSglTgtGen_Jasper::add_a_direct_assertion(const std::string& asst,
                                                 const std::string& dspt) {
  assertions.push_back(std::make_pair(asst, dspt));
}

void VlgSglTgtGen_Jasper::add_addition_clock_info(
    const std::string& clock_expr) {
  additional_clock_expr.push_back(clock_expr);
}

void VlgSglTgtGen_Jasper::add_addition_reset_info(
    const std::string& reset_expr) {
  additional_reset_expr.push_back(reset_expr);
}

/// export the script to run the verification
void VlgSglTgtGen_Jasper::Export_script(const std::string& script_name) {
  auto fn = os_portable_append_dir(_output_path, script_name);

  std::ofstream fout(fn);
  if (!fout.is_open()) {
    ILA_ERROR << "Unable to open " << fn << " for write.";
    return;
  }
  fout << "jg -no_gui -fpv " << jg_script_name << std::endl;
}
/// export extra things (problem)
void VlgSglTgtGen_Jasper::Export_problem(const std::string& extra_name) {
  jg_script_name = extra_name;

  auto fn = os_portable_append_dir(_output_path, extra_name);
  std::ofstream fout(fn);
  if (!fout.is_open()) {
    ILA_ERROR << "Unable to open " << fn << " for write.";
    return;
  }
  fout << "analyze -sva ";
  for (auto&& design_name : vlg_design_files) {
    // remove the directory
    auto fn_no_dir = os_portable_file_name_from_path(design_name);
    fout << " \\\n  " << fn_no_dir;
  }
  if (ila_file_name != "")
    fout << " \\\n  " << ila_file_name;

  if (top_file_name != "")
    fout << " \\\n  " << top_file_name;

  if (abs_mem_name != "")
    fout << " \\\n   " << abs_mem_name;

  fout << "\n\n";

  fout << "elaborate -top " << top_mod_name << std::endl;
  if (additional_clock_expr.empty())
    fout << "clock clk" << std::endl;
  else
    ILA_ERROR << "Not supporting multiple clock. Future work!";

  if (additional_reset_expr.empty())
    fout << "reset rst" << std::endl;
  else
    fout << "reset -expression " << Join(additional_reset_expr, " ")
         << std::endl;

  unsigned No = 0;
  for (auto&& asmpt_dspt_pair : assumptions)
    fout << "assume -name " << asmpt_dspt_pair.second + std::to_string(No++)
         << " {" << asmpt_dspt_pair.first << "}" << std::endl;

  No = 0;
  for (auto&& asst_dspt_pair : assertions)
    fout << "assert -name " << asst_dspt_pair.second + std::to_string(No++)
         << " {" << asst_dspt_pair.first << "}" << std::endl;

} //
/// export the memory abstraction (implementation)
/// Yes, this is also implementation specific, (jasper may use a different one)
void VlgSglTgtGen_Jasper::Export_mem(const std::string& mem_name) {
  // TODO;
  if (!VlgAbsMem::hasAbsMem())
    return;

  abs_mem_name = mem_name;

  auto outfn = os_portable_append_dir(_output_path, mem_name);
  std::ofstream fout(outfn); // will not append

  VlgAbsMem::OutputMemFile(fout,
                           _vtg_config.VerificationSettingAvoidIssueStage);
}
/// For jasper, this means do nothing, for yosys, you need to add (*keep*)
void VlgSglTgtGen_Jasper::Export_modify_verilog() {
  // COPY Files?
  for (auto&& fn : vlg_design_files)
    os_portable_copy_file_to_dir(fn, _output_path);

  // .. (copy all the verilog file in the folder), this has to be os dependent
  if (vlg_include_files_path.size() != 0) {
    // copy the files and specify the -I commandline to the run.sh
    for (auto&& include_path : vlg_include_files_path)
      os_portable_copy_dir(include_path, _output_path);
  }
}

} // namespace ilang
