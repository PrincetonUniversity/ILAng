/// \file Source of generating rel chc synthesis target
/// the inv-syn related horn clasue generation is located in inv-syn/rel_chc.cc
// --- Hongce Zhang

#include <algorithm>
#include <fstream>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>
#include <ilang/vtarget-out/vtarget_gen_relchc.h>
#include <iostream>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

/// template for generating relchc script wo arrays
static std::string relchcGenerateSmtScript_wo_Array = R"***(
hierarchy -check
proc
opt
opt_expr -mux_undef
opt
opt
flatten \%dutmodulename%
%setundef -undriven -init -expose%
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
memory -nordff
proc
opt;;
)***";
// you may want to flatten just 
/// template for generating relchc script
static std::string relchcGenerateSmtScript_w_Array = R"***(
hierarchy -check
proc
opt
opt_expr -mux_undef
opt
opt
flatten \%dutmodulename%
%setundef -undriven -init -expose%
sim -clock clk -reset rst -rstlen %rstlen% -n %cycle% -w %module%
memory_dff -wr_only
memory_collect;
memory_unpack
splitnets -driver
opt;;
memory_collect;
pmuxtree
proc
opt;;
)***";


VlgSglTgtGen_Relchc::VlgSglTgtGen_Relchc(
    const std::string&
        output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                               // be used to verify invariants
    const InstrLvlAbsPtr& ila_ptr, const VerilogGenerator::VlgGenConfig& config,
    nlohmann::json& _rf_vmap, nlohmann::json& _rf_cond, VlgTgtSupplementaryInfo & _sup_info,
    VerilogInfo* _vlg_info_ptr, const std::string& vlg_mod_inst_name,
    const std::string& ila_mod_inst_name, const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const vtg_config_t& vtg_config, backend_selector backend,
    const target_type_t& target_tp,
    advanced_parameters_t* adv_ptr )
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond, _sup_info,
                   _vlg_info_ptr, vlg_mod_inst_name, ila_mod_inst_name,
                   wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, backend,
                   target_tp, adv_ptr) { 
    
    ILA_ASSERT(! _vtg_config.YosysSmtArrayForRegFile)
      << "Future work to support array in synthesis";
    
    ILA_ASSERT(
      target_tp == target_type_t::INSTRUCTIONS )
      << "Only support target type : INSTRUCTIONS, but get: " << target_tp;
    
    ILA_ASSERT(! vtg_config.YosysSmtFlattenHierarchy) 
      << "Monolithic synthesis requires not to flatten hierarchy";

    ILA_ASSERT(! vtg_config.YosysSmtFlattenDatatype)
      << "BUG: not implemented, future work.";

    }



/// Add an assumption
void VlgSglTgtGen_Relchc::add_a_direct_assumption(const std::string& aspt,
                                                const std::string& dspt) {
  _problems.assumptions[dspt].exprs.push_back(aspt);
}
/// Add an assertion
void VlgSglTgtGen_Relchc::add_a_direct_assertion(const std::string& asst,
                                               const std::string& dspt) {
  _problems.assertions[dspt].exprs.push_back(asst);
}

/// Pre export work : add assume and asssert to the top level
/// collect the type of assumptions and assertions
/// Assertions: variable_map_assert (no invariant_assert --- not for invariant target)
/// Assumptions:
///      1. global: noreset, funcmap, absmem, additonal_mapping_control_assume
///      2. only at starting state:
///          variable_map_assume, issue_decode, issue_valid, ...
///      Question: invariant assume? where to put it? Depends on ?

void VlgSglTgtGen_Relchc::PreExportProcess() {
/*
  std::string global_assume = "`true";
  std::string start_assume  = "`true";

  for(auto&& dspt_exprs_pair : _problems.assumptions) {
    const auto & dspt = dspt_exprs_pair.first;
    const auto & expr = dspt_exprs_pair.second;
    for (auto&& p: expr.exprs)
      vlg_wrapper.add_stmt(
        "assume property ("+p+"); // " + dspt
      );
  }

  //std::string assmpt = "(" + Join(_problems.assumptions, ") & (") + ")";
  std::string all_assert_wire_content = "`true";
*/

  if(target_type == target_type_t::INSTRUCTIONS) {
    // this is to synthesize invariants
    for (auto & pbname_prob_pair : _problems.assumptions) {
      const auto& prbname = pbname_prob_pair.first;
      auto& prob = pbname_prob_pair.second; // will be modified !!!

      if (prbname == "invariant_assume") { // add to submodule ? why?
        for (auto & p : prob.exprs) {
          // p does not contain "top."

          auto assumption_wire_name = 
            vlg_wrapper.sanitizeName(prbname) + "_sub_" + new_mapping_id();

          vlg_mod_inv_vec.push_back(
            "wire " + assumption_wire_name + 
            " = " + p +";");
          
          p = assumption_wire_name;
        }
      } // dspt == invariant_assume
    } // for assumptions
  } 
#if 0 // Target Type Invariant, we will not handle
  else if(target_type == target_type_t::INVARIANTS) {
    // this is to check given invariants
    for (auto&& pbname_prob_pair : _problems.assertions) {
      const auto& prbname = pbname_prob_pair.first;
      const auto& prob = pbname_prob_pair.second;
      
      ILA_ASSERT(prbname == "invariant_assert"); 
      // sanity check, should only be invariant's related asserts

      for (auto&& p: prob.exprs) {
        vlg_wrapper.add_stmt(
          "assert property ("+p+"); //" + prbname + "\n"
        );
        all_assert_wire_content += "&& ( " + p  + " ) ";
      } // for expr
    } // for problem
  } // target_type == target_type_t::INVARIANTS

  vlg_wrapper.add_wire("__all_assert_wire__", 1, true);
  vlg_wrapper.add_output("__all_assert_wire__",1);
  vlg_wrapper.add_assign_stmt("__all_assert_wire__", all_assert_wire_content);
#endif // Target Type Invariant, we will not handle

} // PreExportProcess

/// export the script to run the verification :
/// like "yosys gemsmt.ys"
void VlgSglTgtGen_Relchc::Export_script(const std::string& script_name) {
  relchc_run_script_name = script_name;

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;
  //fout << "trap \"trap - SIGTERM && kill -- -$$\" SIGINT SIGTERM"<<std::endl;

  std::string yosys = "yosys";

  if (! _vtg_config.YosysPath.empty())
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

  if (relchc_prob_fname != "")
    fout << yosys << " "<< relchc_prob_fname  << std::endl;
  else
    fout << "echo 'Nothing to check!'" << std::endl;
} // Export_script


/// For jasper, this means do nothing, for relchc, you need to add (*keep*)
void VlgSglTgtGen_Relchc::Export_modify_verilog() {
  // collect all locations: filename -> lineno
  // open, read, count and write
  // if it is a port name, we will ask user to specify its upper level
  // signal name
  VerilogModifier vlg_mod(vlg_info_ptr,
                          static_cast<VerilogModifier::port_decl_style_t>(
                              _vtg_config.PortDeclStyle),
                          _vtg_config.CosaAddKeep,
                          supplementary_info.width_info);

  // add mod stmt (wire something ... like that)
  for (auto && stmt : vlg_mod_inv_vec)
    vlg_mod.RecordAdditionalVlgModuleStmt(stmt, _vlg_mod_inst_name);

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


  //auto tmp_fn = os_portable_append_dir(_output_path, tmp_design_file);
  auto tmp_fn = os_portable_append_dir(_output_path, top_file_name);
  // now let's do the job
  for (auto&& fn : vlg_design_files) {
    std::ifstream fin(fn);
    std::ofstream fout(tmp_fn, std::ios_base::app); // append to a temp file
    if (!fin.is_open()) {
      ILA_ERROR << "Cannot read file:" << fn;
      continue;
    }
    if (!fout.is_open()) {
      ILA_ERROR << "Cannot open file for write:" << tmp_fn;
      continue;
    }
    vlg_mod.ReadModifyWrite(fn, fin, fout);
  } // for (auto && fn : vlg_design_files)
  
  // handles the includes
  // .. (copy all the verilog file in the folder), this has to be os independent
  if (vlg_include_files_path.size() != 0) {
    // copy the files and specify the -I commandline to the run.sh
    for (auto&& include_path : vlg_include_files_path)
      os_portable_copy_dir(include_path, _output_path);
  }

} // Export_modify_verilog


/// export the memory abstraction (implementation)
/// Yes, this is also implementation specific, (jasper may use a different one)
void VlgSglTgtGen_Relchc::Export_mem(const std::string& mem_name) {
  // we will ignore the mem_name

  auto outfn = os_portable_append_dir(_output_path, top_file_name);
  std::ofstream fout(outfn, std::ios_base::app); // append

  VlgAbsMem::OutputMemFile(fout, _vtg_config.VerificationSettingAvoidIssueStage);
}


// export the gensmt.ys
void VlgSglTgtGen_Relchc::Export_problem(const std::string& extra_name) {
  // used by export script!
  relchc_prob_fname = extra_name;

  ILA_CHECK(!_vtg_config.ForceInstCheckReset) <<
     "If start from init, please use Yosys target.";
  // generate tpl

    // first generate a temporary smt
    // and extract from it the necessary info
    auto smt_info = dual_inv_gen_smt("__design_smt.smt2","__gen_smt_script.ys");
    auto final_smt_name = 
      os_portable_append_dir(_output_path,
        os_portable_remove_file_name_extension(top_file_name) + ".smt2" );

    dual_inv_tpl(final_smt_name, smt_info);
    dual_inv_problem(extra_name);

} // Export_problem


void VlgSglTgtGen_Relchc::ExportAll(const std::string& wrapper_name,
                        const std::string& ila_vlg_name,
                        const std::string& script_name,
                        const std::string& extra_name,
                        const std::string& mem_name) {

  PreExportProcess();
  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;

  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  if (target_type == target_type_t::INSTRUCTIONS)
    Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper

  // for Jasper, this will be put to multiple files
  // for CoSA & Yosys, this will be put after the wrapper file (wrapper.v)
  Export_modify_verilog();        // this must be after Export_wrapper
  Export_mem(mem_name);

  // you need to create the map function -- 
  Export_problem(extra_name); // the gensmt.ys 
  
  Export_script(script_name);
}


/// generate the wrapper's smt first
std::string VlgSglTgtGen_Relchc::dual_inv_gen_smt(
  const std::string & smt_name,
  const std::string & ys_script_name) {
  
  auto ys_full_name =
      os_portable_append_dir(_output_path, ys_script_name);
  { // export to ys_full_name
    std::ofstream ys_script_fout( ys_full_name );
    
    std::string write_smt2_options = " -mem -bv -stdt "; // future work : -stbv, or nothing

    ys_script_fout << "read_verilog -sv " 
      << os_portable_append_dir( _output_path , top_file_name ) << std::endl;
    ys_script_fout << "prep -top " << top_mod_name << std::endl;
    ys_script_fout << 
      ReplaceAll(
      ReplaceAll(
      ReplaceAll(
      ReplaceAll(
      ReplaceAll(
      relchcGenerateSmtScript_wo_Array, 
      "%setundef -undriven -init -expose%", _vtg_config.YosysUndrivenNetAsInput ? "setundef -undriven -init -expose" : ""),
      "%module%", top_mod_name),
      "%rstlen%", "1" // this is because, the reset analysis is applied on the DUT not the wrapper
            /*std::to_string(
                supplementary_info.cosa_yosys_reset_config.reset_cycles)*/),
      "%cycle%", "1" // this is because, the reset analysis is applied on the DUT not the wrapper
        /*std::to_string(
            supplementary_info.cosa_yosys_reset_config.reset_cycles) */),
      "%dutmodulename%", vlg_info_ptr->get_top_module_name())
      ;
    ys_script_fout << "write_smt2"<<write_smt2_options 
      << os_portable_append_dir( _output_path, smt_name );   
  } // finish writing

  std::string yosys = "yosys";

  if (! _vtg_config.YosysPath.empty())
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

  // execute it
  std::vector<std::string> cmd;
  cmd.push_back(yosys); cmd.push_back("-s"); cmd.push_back(ys_full_name);

  std::string logfilename = 
      os_portable_append_dir(_output_path, "yosys_output.log");

  auto res = os_portable_execute_shell( cmd , logfilename); // this does not redirect
    ILA_ERROR_IF( res.failure != res.NONE  )
      << "Executing Yosys failed!";
    ILA_ERROR_IF( res.failure == res.NONE && res.ret != 0)
      << "Yosys returns error code:" << res.ret;

  { // now read in the file 
    std::stringstream ibuf;
    auto smt_in_fn = os_portable_append_dir(_output_path, smt_name);
    std::ifstream smtfin( smt_in_fn );

    if (! smtfin.is_open()) {
      ILA_ERROR << "Cannot read from: " << smt_in_fn;
      return "";
    }
    ibuf << smtfin.rdbuf();
    return ibuf.str();
  } // finish file readin
} // dual_inv_gen_smt


}; // namespace ilang
