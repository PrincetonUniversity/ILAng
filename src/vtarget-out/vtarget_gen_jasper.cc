/// \file Source of generating Jasper accepted problem, vlg, mem, script
// --- Hongce Zhang


#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/vtarget_gen_jasper.h>
#include <ilang/util/fs.h>
#include <algorithm>
#include <iostream>
#include <fstream>

namespace ilang {
  
    VlgSglTgtGen_Jasper::VlgSglTgtGen_Jasper(
    const std::string              & output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr                 & instr_ptr, // which could be an empty pointer, and it will be used to verify invariants
    const InstrLvlAbsPtr           & ila_ptr, 
    const VerilogGenerator::VlgGenConfig & config,
    nlohmann::json                 & _rf_vmap,
    nlohmann::json                 & _rf_cond,
    VerilogInfo      *               _vlg_info_ptr,
    const std::string              & vlg_mod_inst_name,
    const std::string              & ila_mod_inst_name,
    const std::string              & wrapper_name,
    const std::vector<std::string> & implementation_srcs,
    const std::vector<std::string> & implementation_include_path
  ):VlgSglTgtGen(
      output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond,
      _vlg_info_ptr, vlg_mod_inst_name, ila_mod_inst_name,
      wrapper_name, implementation_srcs, implementation_include_path )
  {

  }


  /// Add an assumption
  void VlgSglTgtGen_Jasper::add_an_assumption(const std::string & aspt, const std::string & dspt) {
    // TODO: 
  }
  /// Add an assertion
  void VlgSglTgtGen_Jasper::add_an_assertion (const std::string & asst, const std::string & dspt) {

  }

  /// export the script to run the verification
  void VlgSglTgtGen_Jasper::Export_script(const std::string & script_name) {

  }
  /// export extra things (problem)
  void VlgSglTgtGen_Jasper::Export_problem(const std::string & extra_name) {
    return; // do nothing
  } //
  /// export the memory abstraction (implementation)
  /// Yes, this is also implementation specific, (jasper may use a different one)
  void VlgSglTgtGen_Jasper::Export_mem(const std::string & mem_name) {
    // TODO;
  }
  /// For jasper, this means do nothing, for yosys, you need to add (*keep*)
  void VlgSglTgtGen_Jasper::Export_modify_verilog() {
    // COPY Files?
    return; // do nothing
  }

} // namespace ilang