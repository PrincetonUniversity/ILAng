/// \file Source of generating CoSA accepted problem, vlg, mem, script
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_cosa.h>

#include <algorithm>
#include <fstream>
#include <iostream>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

VlgSglTgtGen_Cosa::VlgSglTgtGen_Cosa(
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

#if 0
// currently this function has no use
std::string convert_expr_to_cosa(const std::string& in) {
  return ReplaceAll(
      ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(in, "&&", "&"),
                                                  "||", "|"),
                                       "~", "!"),
                            "==", "="),
                 VLG_TRUE, "True"),
      VLG_FALSE, "False");
}
#endif

/// Add an assumption
void VlgSglTgtGen_Cosa::add_a_direct_assumption(const std::string& aspt,
                                                const std::string& dspt) {
  _problems.assumptions.push_back(aspt);
}
/// Add an assertion
void VlgSglTgtGen_Cosa::add_a_direct_assertion(const std::string& asst,
                                               const std::string& dspt) {
  _problems.probitem[dspt].assertions.push_back(asst);
}

/// export the script to run the verification
void VlgSglTgtGen_Cosa::Export_script(const std::string& script_name) {
  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;
  if (!_vtg_config.CosaPyEnvironment.empty())
    fout << "source " << _vtg_config.CosaPyEnvironment << std::endl;

  std::string cosa = "CoSA";
  std::string options;

  if (!_vtg_config.CosaSolver.empty())
    options += " --solver-name=" + _vtg_config.CosaSolver;
  if (_vtg_config.CosaGenTraceVcd)
    options += " --vcd";
  if (_vtg_config.CosaFullTrace)
    options += " --full-trace";
  options += " " + _vtg_config.CosaOtherSolverOptions;

  // no need, copy is good enough
  // if(vlg_include_files_path.size() != 0)
  //  options += " -I./";

  if (!_vtg_config.CosaPath.empty()) {
    cosa = os_portable_append_dir(_vtg_config.CosaPath, cosa) + ".py";
  }

  if (cosa_prob_fname != "")
    fout << cosa << " --problem " << cosa_prob_fname << options << std::endl;
  else
    fout << "echo 'Nothing to check!'" << std::endl;
}

void VlgSglTgtGen_Cosa::Export_jg_tester_script(const std::string& extra_name) {
  if (_problems.probitem.size() == 0)
    return;

  std::ofstream fout(os_portable_append_dir(_output_path, extra_name));
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, extra_name);
    return;
  }
  fout << "analyze -sva " << top_file_name << std::endl;
  fout << "elaborate -top " << top_mod_name << std::endl;
  fout << "clock clk" << std::endl;
  fout << "reset rst" << std::endl;

  decltype(_problems.assumptions) local_assumpt;
  for (auto&& p : _problems.assumptions) {
    if (p == "reset_done = 1_1 -> rst = 0_1")
      continue ; // must match with single_target_cond.cc
    if (p == "reset_done = 1_1 -> next( reset_done ) = 1_1")
      continue ; // must match with single_target_cond.cc
    auto eq_idx = p.find('=');
    auto rm_eq_p = p.substr(0, eq_idx);
    local_assumpt.push_back(rm_eq_p);

    fout << "assume { " << rm_eq_p << " }" << std::endl;
  }
  // separate assumptions
  // std::string assmpt = "(" + Join(local_assumpt, ") && (") + ")";

  for (auto&& pbname_prob_pair : _problems.probitem) {
    const auto& prob = pbname_prob_pair.second;

    decltype(prob.assertions) local_asst;
    for (auto&& p : prob.assertions) {
      auto eq_idx = p.find('=');
      auto rm_eq_p = p.substr(0, eq_idx);
      local_asst.push_back(rm_eq_p);
    }

    auto asst = "(" + Join(local_asst, ") && (") + ")";
    fout << "assert { " << asst << " }" << std::endl;
  }
}

/// export extra things (problem)
void VlgSglTgtGen_Cosa::Export_problem(const std::string& extra_name) {
  if (_problems.probitem.size() == 0) {
    ILA_ERROR << "Nothing to prove, no assertions inserted!";
    return;
  }

  cosa_prob_fname = extra_name;

  std::ofstream rstf(os_portable_append_dir(_output_path, "rst.ets"));
  if (!rstf.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, "rst.ets");
    return;
  }

  rstf << "I: rst = 1_1" << std::endl;
  rstf << "I: reset_done = 0_1" << std::endl;

  unsigned cycle_after_i = 1;
  unsigned reset_cycle_needed = 
    (target_type == target_type_t::INSTRUCTIONS) && (!_vtg_config.ForceInstCheckReset )? 1:
    supplementary_info.cosa_yosys_reset_config.reset_cycles;

  for (; cycle_after_i < reset_cycle_needed; ++cycle_after_i) {
    rstf << "S" << cycle_after_i << ": rst = 1_1" << std::endl;
    rstf << "S" << cycle_after_i << ": reset_done = 0_1" << std::endl;
  }
  rstf << "S" << cycle_after_i << ": rst = 0_1" << std::endl;
  rstf << "S" << cycle_after_i << ": reset_done = 1_1" << std::endl;
  rstf << "# TRANS" << std::endl;
  rstf << "I -> S1" << std::endl;
  for (cycle_after_i = 1; cycle_after_i < reset_cycle_needed; ++cycle_after_i)
    rstf << "S" << cycle_after_i << " -> S" << (cycle_after_i + 1) << std::endl;
  rstf << "S" << cycle_after_i << " -> S" << cycle_after_i << std::endl;

  std::ofstream fout(os_portable_append_dir(_output_path, extra_name));
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, extra_name);
    return;
  }

  fout << "[GENERAL]" << std::endl;
  fout << "model_files:"; //
  fout << top_file_name << "[" << top_mod_name << "],";
  // if(target_type != target_type_t::INVARIANTS )
  //	fout << ila_file_name<<","; // will be combined
  fout << "rst.ets";
  // for(auto && fn : vlg_design_files) // will be combined
  //  fout << "," << os_portable_file_name_from_path(fn);
  fout << std::endl;

  fout << "assume_if_true: True" << std::endl;
  fout << "abstract_clock: True" << std::endl;
  fout << "[DEFAULT]" << std::endl;
  fout << "bmc_length: " << std::to_string(max_bound + 5) << std::endl;
  fout << "precondition: reset_done = 1_1" << std::endl;
  fout << std::endl;

  std::string assmpt = "(" + Join(_problems.assumptions, ") & (") + ")";
  for (auto&& pbname_prob_pair : _problems.probitem) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    auto asst = "(" + Join(prob.assertions, ") & (") + ")";
    auto prob_name = vlg_wrapper.sanitizeName(prbname);
    fout << "[" << prob_name << "]" << std::endl;
    fout << "description:\"" << prbname << "\"" << std::endl;
    fout << "properties:" << asst << std::endl;
    if (assmpt != "()")
      fout << "assumptions:" << assmpt << std::endl;
    fout << "prove: True" << std::endl;
    fout << "verification: safety" << std::endl;
    if (VlgAbsMem::hasAbsMem())
      fout << "strategy: AUTO" << std::endl;
    else
      fout << "strategy: ALL" << std::endl;
    fout << "expected: True" << std::endl;
  }

  if (_vtg_config.CosaGenJgTesterScript)
    Export_jg_tester_script("jg.tcl");

} // only for cosa

/// export the memory abstraction (implementation)
/// Yes, this is also implementation specific, (jasper may use a different one)
void VlgSglTgtGen_Cosa::Export_mem(const std::string& mem_name) {
  // we will ignore the mem_name

  auto outfn = os_portable_append_dir(_output_path, top_file_name);
  std::ofstream fout(outfn, std::ios_base::app); // append

  VlgAbsMem::OutputMemFile(fout,
                           _vtg_config.VerificationSettingAvoidIssueStage);
}

/// For jasper, this means do nothing, for yosys, you need to add (*keep*)
void VlgSglTgtGen_Cosa::Export_modify_verilog() {
  // collect all locations: filename -> lineno
  // open, read, count and write
  // if it is a port name, we will ask user to specify its upper level
  // signal name
  VerilogModifier vlg_mod(vlg_info_ptr,
                          static_cast<VerilogModifier::port_decl_style_t>(
                              _vtg_config.PortDeclStyle),
                          _vtg_config.CosaAddKeep,
                          supplementary_info.width_info);

  for (auto&& refered_vlg_item : _all_referred_vlg_names) {
    auto idx = refered_vlg_item.first.find("[");
    auto removed_range_name = refered_vlg_item.first.substr(0, idx);
    vlg_mod.RecordKeepSignalName(removed_range_name);
    // auto sig = // no use, this is too late, vlg_wrapper already exported
    vlg_mod.RecordConnectSigName(removed_range_name,
                                 refered_vlg_item.second.range);
    // vlg_wrapper.add_output(sig.first, sig.second);
  }
  vlg_mod.FinishRecording();

  // now let's do the job
  for (auto&& fn : vlg_design_files) {
    auto outfn = os_portable_append_dir(_output_path, top_file_name);
    std::ifstream fin(fn);
    std::ofstream fout(outfn, std::ios_base::app); // append
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read file:" << fn;
      continue;
    }
    if (!fout.is_open()) {
      ILA_ERROR << "Cannot open file for write:" << outfn;
      continue;
    }
    vlg_mod.ReadModifyWrite(fn, fin, fout);
  } // for (auto && fn : vlg_design_files)
  // .. (copy all the verilog file in the folder), this has to be os dependent
  if (vlg_include_files_path.size() != 0) {
    // copy the files and specify the -I commandline to the run.sh
    for (auto&& include_path : vlg_include_files_path)
      os_portable_copy_dir(include_path, _output_path);
  }

} // Export_modify_verilog

}; // namespace ilang
