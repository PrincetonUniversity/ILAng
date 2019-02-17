/// \file Source of initial constraint synthesis utility
// --- Hongce Zhang

#include <algorithm>
#include <fstream>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>
#include <ilang/vtarget-out/vtarget_gen_yosys.h>
#include <iostream>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

// -----------------  VlgSglTgtGen_Yosys_design_only ------------ //

VlgSglTgtGen_Yosys_design_only::VlgSglTgtGen_Yosys_design_only(
  const std::string& output_path, // will be a sub directory of the
                                  // output_path of its parent
  const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                              // be used to verify invariants
  const InstrLvlAbsPtr& ila_ptr,
  const VerilogGenerator::VlgGenConfig& config, nlohmann::json& _rf_vmap,
  nlohmann::json& _rf_cond, VerilogInfo* _vlg_info_ptr,
  const std::string& vlg_mod_inst_name,
  const std::string& ila_mod_inst_name, const std::string& wrapper_name,
  const std::vector<std::string>& implementation_srcs,
  const std::vector<std::string>& include_dirs,
  const vtg_config_t& vtg_config, backend_selector backend,
  const target_type_t& target_tp) :

  VlgSglTgtGen_Yosys(output_path, instr_ptr, ila_ptr, config, 
    _rf_vmap, _rf_cond, _vlg_info_ptr, vlg_mod_inst_name,
    ila_mod_inst_name, wrapper_name, implementation_srcs,
    include_dirs, vtg_config, backend, target_tp
  )
  {
    ILA_ASSERT(backend == backend_selector::YOSYS);
    ILA_ASSERT(target_tp == target_type_t::INST_INV_SYN);
    ILA_ERROR_IF(_vtg_config.YosysSmtStateSort != vtg_config_t::DataSort)
      << "Bug: future work--extract map function from non-data-sort state variable encoding.";
  }


/// Pre export work : add assume and asssert to the top level
void VlgSglTgtGen_Yosys_design_only::PreExportProcess() {
  // no assertions or assumptions
  // they should not be used here
}

// generating the yosys script to generate smt expressions of the verilog design
void VlgSglTgtGen_Yosys_design_only::Export_problem(const std::string& extra_name) {
  yosys_prob_fname = extra_name; // or the gensmt.ys name

  smt_file_name = os_portable_remove_file_name_extension(top_file_name) + ".smt2";

  std::ofstream fout(os_portable_append_dir(_output_path, extra_name));
  if(!fout.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, extra_name);
    return;
  }

  std::string write_smt2_options;

  write_smt2_options += " -mem -bv -wires" ;
  switch(_vtg_config.YosysSmtStateSort) {
    case vtg_config_t::DataSort: write_smt2_options += " -stdt"; break;
    case vtg_config_t::BitVec: write_smt2_options += " -stbv"; 
      ILA_ERROR_IF(_vtg_config.YosysSmtArrayForRegFile)
        << "Bitvector SMT encoding is not compatible w. option YosysSmtArrayForRegFile";
      break;
    case vtg_config_t::UnintepretedFunc: break; // do nothing
    default: ILA_ERROR << "Unknown option for YosysSmtStateSort option";
  }

  fout << "read_verilog -sv "<<top_file_name<< std::endl;
  fout << "prep -top "<<top_mod_name<<std::endl;


  if(_vtg_config.YosysSmtArrayForRegFile)
    fout << yosysGenerateSmtScript_w_Array;
  else
    fout << yosysGenerateSmtScript_wo_Array;
  fout << "write_smt2" << write_smt2_options << " " << smt_file_name;

} // VlgSglTgtGen_Yosys_design_only::Export_problem


// Export_script : the same as yosys gen
YosysDesignSmtInfo VlgSglTgtGen_Yosys_design_only::RunSmtGeneration() {
  auto script_path = 
    os_portable_append_dir(_output_path, yosys_run_script_name);
  // run the script
  bool succeeded = 
    os_portable_execute_shell( script_path );
  if (not succeeded) {
    ILA_ERROR << "Cannot execute script:"<<script_path;
    return YosysDesignSmtInfo(); // return an empty one
  }

  // okay now we should open the smt file and parse it
  auto smt_file_path =
    os_portable_append_dir(_output_path, smt_file_name);

  YosysDesignSmtInfo ret;
  ret.top_mod_name = top_mod_name;
  ret.state_pos_name_map = extract_state_info_from_smt(smt_file_path);

  return ret;
} // RunSmtGeneration

/// TODO: two trans func may not be a good design!
/// You may need to consider the hierarchical way
/// Deprecation of the one without smt info
void VlgSglTgtGen_Yosys_design_only::ExportAll(const std::string& wrapper_name,
                        const std::string& ila_vlg_name,
                        const std::string& script_name,
                        const std::string& extra_name,
                        const std::string& mem_name) {
  PreExportProcess(); // do nothing : no assumptions or assertions
  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;
  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  // this will include some logics that are not needed
  // basically the top level wrapper and etc.


  // // no need to export ila verilog
  // if (target_type == target_type_t::INSTRUCTIONS)
  //  Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper

  // for Jasper, this will be put to multiple files
  // for CoSA & Yosys, this will be put after the wrapper file (wrapper.v)
  Export_modify_verilog();        // this must be after Export_wrapper
  Export_mem(mem_name);

  // you need to create the map function -- 
  Export_problem(extra_name); // the gensmt.ys 
  
  Export_script(script_name);
}


}; // namespace ilang
