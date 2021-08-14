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
    const InstrLvlAbsPtr& ila_ptr, 
    const rfmap::VerilogRefinementMap & refinement,
    VerilogInfo* _vlg_info_ptr,
    const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const vtg_config_t& vtg_config, backend_selector backend,
    const target_type_t& target_tp, advanced_parameters_t* adv_ptr)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, refinement, 
                   _vlg_info_ptr, wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, backend, target_tp,
                   adv_ptr) {}

/// Add SMT-lib2 assumption
void VlgSglTgtGen_Jasper::add_a_direct_smt_assumption(const std::string& arg,
                                      const std::string& ret,
                                      const std::string& body,
                                      const std::string& dspt) {
  ILA_CHECK(false) << "SMT assumption should not be generated for JasperGold";                                   
}

/// Add SMT-lib2 assertion
void VlgSglTgtGen_Jasper::add_a_direct_smt_assertion(const std::string& arg,
                                    const std::string& ret,
                                    const std::string& body,
                                    const std::string& dspt) {
  ILA_CHECK(false) << "SMT assertions should not be generated for JasperGold";
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

  fout << "\n\n";

  fout << "elaborate -top " << top_mod_name << std::endl;
  fout << "clock clk" << std::endl;
  fout << "reset rst" << std::endl;

  unsigned No = 0;
  for (auto&& asmpt_dspt_pair : assumptions)
    fout << "assume -name " << asmpt_dspt_pair.second + std::to_string(No++)
         << " {" << asmpt_dspt_pair.first << "}" << std::endl;

  No = 0;
  for (auto&& asst_dspt_pair : assertions)
    fout << "assert -name " << asst_dspt_pair.second + std::to_string(No++)
         << " {" << asst_dspt_pair.first << "}" << std::endl;

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
