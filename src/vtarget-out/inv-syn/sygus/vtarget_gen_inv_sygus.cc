/// \file Verilog Verification Target Generator -- generating one SyGuS target
/// This is only one round of the cex based sygus
/// but it should be allowd to call dp/chc
// ---Hongce Zhang (hongcez@princeton.edu)

#include <algorithm>
#include <fstream>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>
#include <ilang/vtarget-out/inv-syn/sygus/vtarget_gen_inv_sygus.h>
#include <iostream>

namespace ilang {

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

// initialize templates
std::string sygusGenerateSmtScript_wo_Array = R"***(
hierarchy -check
proc
opt
opt_expr -mux_undef
opt
opt
%flatten%
%setundef -undriven -expose%
memory -nordff
proc
opt;;
)***";

// should not be used 
// this is : "%setundef -undriven -expose%", _vtg_config.YosysUndrivenNetAsInput ? "setundef -undriven -expose" : ""
std::string sygusGenerateSmtScript_w_Array = R"***(
hierarchy -check
proc
opt
opt_expr -mux_undef
opt
opt
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




VlgSglTgtGen_Cvc4SyGuS::~VlgSglTgtGen_Cvc4SyGuS() {
  
}

VlgSglTgtGen_Cvc4SyGuS::VlgSglTgtGen_Cvc4SyGuS(
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
    const vtg_config_t& vtg_config,  backend_selector vbackend,
    synthesis_backend_selector sbackend,
    const target_type_t& target_tp,
    advanced_parameters_t* adv_ptr,
    TraceDataPoints * dp,
    const std::vector<std::string> & var_name_set,
    bool _enumerate)
    : VlgSglTgtGen(output_path, instr_ptr, ila_ptr, config, _rf_vmap, _rf_cond, _sup_info,
                   _vlg_info_ptr, vlg_mod_inst_name, ila_mod_inst_name,
                   wrapper_name, implementation_srcs,
                   implementation_include_path, vtg_config, vbackend,
                   target_tp, adv_ptr),
      s_backend(sbackend), datapoints(dp), var_names(var_name_set),
      enumerate(_enumerate) { 
    
    ILA_ASSERT(vbackend == backend_selector::YOSYS)
      << "Only support using yosys for invariant synthesis";

    ILA_ASSERT(not _vtg_config.YosysSmtArrayForRegFile)
      << "Future work to support array in synthesis";
    
    ILA_ASSERT(
      target_tp == target_type_t::INV_SYN_DESIGN_ONLY )
      << "Unsupported target type: " << target_tp;

    ILA_ASSERT (adv_ptr and adv_ptr->_cex_obj_ptr)
      << "Cex object must be provided to synthesize.";

    ILA_ASSERT (
      sbackend == synthesis_backend_selector::CVC4
      ) << "Unknown synthesis backend:" << sbackend;
    
    ILA_ASSERT(_vtg_config.SygusOptions.SygusPassInfo == 
                  VlgVerifTgtGenBase::_vtg_config::_sygus_options_t::TransferFunc
            or
               _vtg_config.SygusOptions.SygusPassInfo == 
                  VlgVerifTgtGenBase::_vtg_config::_sygus_options_t::DataPoints
       ) << "Unknown Sygus passing info: " << _vtg_config.SygusOptions.SygusPassInfo;

    if (_vtg_config.SygusOptions.SygusPassInfo == 
         VlgVerifTgtGenBase::_vtg_config::_sygus_options_t::TransferFunc)
      ILA_ASSERT (vtg_config.YosysSmtFlattenDatatype)
        << "For SyGuS through passing transfer function, datatype must be flattened!";

    if (_vtg_config.SygusOptions.SygusPassInfo == 
         VlgVerifTgtGenBase::_vtg_config::_sygus_options_t::DataPoints)
      ILA_NOT_NULL(dp); // if you choose the datapoint method, datapoint must be supplied
 }


void VlgSglTgtGen_Cvc4SyGuS::add_wire_assign_assumption(
    const std::string& varname, const std::string& expression,
    const std::string& dspt) {

  vlg_wrapper.add_assign_stmt(varname, expression);
  ILA_ERROR_IF(expression.find(".") == std::string::npos)
      << "-------- expression:" << expression << " contains unfriendly dot.";
}

void VlgSglTgtGen_Cvc4SyGuS::add_reg_cassign_assumption(
    const std::string& varname, const std::string& expression, int width,
    const std::string& cond, const std::string& dspt) {

  ILA_ERROR_IF(expression.find(".") != std::string::npos)
      << "-------- expression:" << expression << " contains unfriendly dot.";

  std::string rand_in_name = "__" + varname + "_init__";
  vlg_wrapper.add_input(rand_in_name, width);
  vlg_wrapper.add_wire (rand_in_name, width);
  
  vlg_wrapper.add_init_stmt(varname + " <= " + rand_in_name + ";");
  vlg_wrapper.add_always_stmt(varname + " <= " + varname + ";");
  add_an_assumption(
      "(~(" + cond + ") || ((" + varname + ") == (" + expression + ")))", dspt);
}

/// Add an assumption
void VlgSglTgtGen_Cvc4SyGuS::add_an_assumption(const std::string& aspt,
                                          const std::string& dspt) {
  auto assumption_wire_name = vlg_wrapper.sanitizeName(dspt) + new_mapping_id();
  
  vlg_wrapper.add_wire(assumption_wire_name, 1, true);
  // I find it is necessary to connect to the output
  vlg_wrapper.add_output(assumption_wire_name, 1);
  vlg_wrapper.add_assign_stmt(assumption_wire_name, aspt);

  ILA_ERROR_IF(aspt.find(".") != std::string::npos)
      << "-------- aspt:" << aspt << " contains unfriendly dot.";
  _problems.assumptions[dspt].exprs.push_back(assumption_wire_name);

}
/// Add an assertion
void VlgSglTgtGen_Cvc4SyGuS::add_an_assertion(const std::string& asst,
                                         const std::string& dspt) {
  auto assrt_wire_name = vlg_wrapper.sanitizeName(dspt) + new_property_id();
  vlg_wrapper.add_wire(assrt_wire_name, 1, true);
  vlg_wrapper.add_output(assrt_wire_name,
                         1); // I find it is necessary to connect to the output
  vlg_wrapper.add_assign_stmt(assrt_wire_name, asst);
  _problems.assertions[dspt].exprs.push_back(assrt_wire_name);
  ILA_ERROR_IF(asst.find(".") != std::string::npos)
      << "-------- asst:" << asst << " contains unfriendly dot.";
}

/// Add an assumption
void VlgSglTgtGen_Cvc4SyGuS::add_a_direct_assumption(const std::string& aspt,
                                                const std::string& dspt) {
  _problems.assumptions[dspt].exprs.push_back(aspt);
}
/// Add an assertion
void VlgSglTgtGen_Cvc4SyGuS::add_a_direct_assertion(const std::string& asst,
                                               const std::string& dspt) {
  _problems.assertions[dspt].exprs.push_back(asst);
}

void VlgSglTgtGen_Cvc4SyGuS::PreExportProcess() {

  std::string all_assert_wire_content;
  std::string all_assume_wire_content;

  ILA_ASSERT(target_type == target_type_t::INV_SYN_DESIGN_ONLY);
  ILA_ERROR_IF(_problems.assertions.size() != 1) << "BUG in cex extract";

  // you need to add assumptions as well
  for (auto&& pbname_prob_pair : _problems.assumptions) {
    const auto & prbname = pbname_prob_pair.first;
    const auto & prob = pbname_prob_pair.second;
    ILA_DLOG("VlgSglTgtGen_Cvc4SyGuS.PreExportProcess") << "Adding assumption:" << prbname;
    
    for (auto&& p: prob.exprs) {
      vlg_wrapper.add_stmt(
        "assume property ("+p+"); //" + prbname + "\n");
      if (all_assume_wire_content.empty())
        all_assume_wire_content = "(" + p + ")";
      else
        all_assume_wire_content += "&& (" + p + ")";
    } // for prob.exprs
  } // for _problems.assumption

  // this is to check given invariants
  for (auto&& pbname_prob_pair : _problems.assertions) {
    const auto& prbname = pbname_prob_pair.first;
    const auto& prob = pbname_prob_pair.second;
    
    ILA_ASSERT(prbname == "cex_nonreachable_assert")
      << "BUG: assertion can only be cex reachability queries.";
    // sanity check, should only be invariant's related asserts

    for (auto&& p: prob.exprs) {
      vlg_wrapper.add_stmt(
        "assert property ("+p+"); //" + prbname + "\n"
      ); // there should be only one expression (actually)
      ILA_ASSERT(all_assert_wire_content.empty());
      all_assert_wire_content = "( " + p  + " ) ";
    } // for expr
  } // for problem
  // add assert wire (though no use : make sure will not optimized away)
  ILA_ASSERT(not all_assert_wire_content.empty());

  vlg_wrapper.add_wire("__all_assert_wire__", 1, true);
  vlg_wrapper.add_output("__all_assert_wire__",1);
  vlg_wrapper.add_assign_stmt("__all_assert_wire__", all_assert_wire_content);

  if (not all_assume_wire_content.empty()) {
    vlg_wrapper.add_wire("__all_assume_wire__", 1, true);
    vlg_wrapper.add_output("__all_assume_wire__",1);
    vlg_wrapper.add_assign_stmt("__all_assume_wire__", all_assume_wire_content);
  }
} // PreExportProcess

/// export the script to run the verification :
/// like "yosys gemsmt.ys"
void VlgSglTgtGen_Cvc4SyGuS::Export_script(const std::string& script_name) {
  sygus_run_script_name = script_name;
  /// TODO: BUG: modify this : use z3/freqHorn

  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;
  //fout << "trap \"trap - SIGTERM && kill -- -$$\" SIGINT SIGTERM"<<std::endl;

  std::string runnable = "cvc4";
  std::string redirect_file = "../__synthesis_result.txt";
  std::string options;
  //std::string options = " --sygus-stream --sygus-pbe";
  //if (enumerate)
  //  options = " --sygus-stream"; // force searching all 

  if (not _vtg_config.Cvc4Path.empty())
    runnable = os_portable_append_dir(_vtg_config.Cvc4Path, runnable);

  if (design_prob_fname != "")
    fout << runnable << options << " --lang=sygus "<< design_prob_fname  
         << " > " << redirect_file << " " << std::endl;
  else
    fout << "echo 'Nothing to check!'" << std::endl;

  // we will always return as long as we see some answer
  // fout << "inotifywait " << redirect_file << " -e modify\n";
  // fout << "while [ ! -s \"" << redirect_file << "\" ]; do\n";
  // fout << "  echo \"Empty file ... +1s\"\n";
  // fout << "  sleep 1\n";
  // fout << "done\n";
  // fout << "trap 'kill $(jobs -p)' EXIT\n";
} // Export_script


/// For jasper, this means do nothing, for yosys, you need to add (*keep*)
void VlgSglTgtGen_Cvc4SyGuS::Export_modify_verilog() {
  // collect all locations: filename -> lineno
  // open, read, count and write
  // if it is a port name, we will ask user to specify its upper level
  // signal name
  VerilogModifier vlg_mod(vlg_info_ptr,
    static_cast<VerilogModifier::port_decl_style_t>(_vtg_config.PortDeclStyle),
    _vtg_config.CosaAddKeep, sup_info.width_info);

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
void VlgSglTgtGen_Cvc4SyGuS::Export_mem(const std::string& mem_name) {
  // we will ignore the mem_name

  auto outfn = os_portable_append_dir(_output_path, top_file_name);
  std::ofstream fout(outfn, std::ios_base::app); // append

  VlgAbsMem::OutputMemFile(fout, _vtg_config.VerificationSettingAvoidIssueStage);
}

void VlgSglTgtGen_Cvc4SyGuS::Export_problem(const std::string& extra_name) {
  ILA_ASSERT(false) << "Illegal use of VlgSglTgtGen_Cvc4SyGuS::Export_problem, not implemented";
}

// export the sygus file
void VlgSglTgtGen_Cvc4SyGuS::Export_problem(const std::string& extra_name, const Cvc4Syntax & syntax) {
  // used by export script!
  design_prob_fname = extra_name;

  // first generate a temporary smt
  // and extract from it the necessary info

  // first generate a temporary smt
  // and extract from it the necessary info

  design_only_gen_smt(
    os_portable_append_dir(_output_path, "__design_smt.smt2"),
    os_portable_append_dir(_output_path, "__gen_smt_script.ys"));

  if (_vtg_config.SygusOptions.SygusPassInfo == 
       VlgVerifTgtGenBase::_vtg_config::_sygus_options_t::TransferFunc)
    convert_smt_to_chc_sygus (
      os_portable_append_dir(_output_path, "__design_smt.smt2"), 
      os_portable_append_dir(_output_path, extra_name), syntax);
  else  // datapoints
    convert_datapoints_to_sygus(
      os_portable_append_dir(_output_path, "__design_smt.smt2"), 
      datapoints,
      os_portable_append_dir(_output_path, extra_name), syntax);

} // Export_problem

std::shared_ptr<smt::YosysSmtParser> VlgSglTgtGen_Cvc4SyGuS::GetDesignSmtInfo() const {
  return design_smt_info;
}

Cvc4SygusBase::correction_t VlgSglTgtGen_Cvc4SyGuS::GetParsingCorrections() const {
  return inv_parsing_corrections;
}


void VlgSglTgtGen_Cvc4SyGuS::ExportAll(const std::string& wrapper_name,
                        const std::string& ila_vlg_name,
                        const std::string& script_name,
                        const std::string& extra_name,
                        const std::string& mem_name) {
  ILA_ASSERT(false) << "Illegal use of class VlgSglTgtGen_Cvc4SyGuS";
}

void VlgSglTgtGen_Cvc4SyGuS::ExportAll(const std::string& wrapper_name, // wrapper.v
                        const std::string& ila_vlg_name, // no use
                        const std::string& script_name,  // the run.sh
                        const std::string& extra_name,   // the sygus
                        const std::string& mem_name,
                        const Cvc4Syntax & syntax) {   // no use

  PreExportProcess();

  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;

  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  // design only
  //if (target_type == target_type_t::INSTRUCTIONS)
  //  Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper

  // for Jasper, this will be put to multiple files
  // for CoSA & Yosys, this will be put after the wrapper file (wrapper.v)
  Export_modify_verilog();        // this must be after Export_wrapper
  Export_mem(mem_name);

  // you need to create the map function -- 
  Export_problem(extra_name, syntax); // the gensmt.ys 
  
  Export_script(script_name);
}

// --------------------------- HELPER FUNCTIONS ---------------------------- //

/// generate the wrapper's smt first
void VlgSglTgtGen_Cvc4SyGuS::design_only_gen_smt(
  const std::string & smt_name,
  const std::string & ys_script_name) {
  
  auto ys_output_full_name =
      os_portable_append_dir(_output_path, "__yosys_exec_result.txt");
  { // export to ys_script_name
    std::ofstream ys_script_fout( ys_script_name );

    std::string write_smt2_options;
    if (_vtg_config.SygusOptions.SygusPassInfo == _vtg_config.SygusOptions.TransferFunc)
      write_smt2_options = " -mem -bv -stdt "; // future work : -stbv, or nothing
    else
      write_smt2_options = " -mem -bv -wires -stdt ";

    ys_script_fout << "read_verilog -sv " 
      << os_portable_append_dir( _output_path , top_file_name ) << std::endl;
    ys_script_fout << "prep -top " << top_mod_name << std::endl;
    ys_script_fout << 
      ReplaceAll(
      ReplaceAll(sygusGenerateSmtScript_wo_Array, "%flatten%", 
        _vtg_config.YosysSmtFlattenHierarchy ? "flatten;" : ""),
        "%setundef -undriven -expose%", _vtg_config.YosysUndrivenNetAsInput ? "setundef -undriven -expose" : "");
    ys_script_fout << "write_smt2"<<write_smt2_options 
      << smt_name;   
  } // finish writing

  std::string yosys = "yosys";

  if (not _vtg_config.YosysPath.empty())
    yosys = os_portable_append_dir(_vtg_config.YosysPath, yosys);

  // execute it
  std::vector<std::string> cmd;
  cmd.push_back(yosys); cmd.push_back("-s"); cmd.push_back(ys_script_name);
  auto res = os_portable_execute_shell( cmd, ys_output_full_name );
  ILA_ERROR_IF( res.failure != res.NONE  )
    << "Executing Yosys failed!";
  ILA_ERROR_IF( res.failure == res.NONE && res.ret != 0)
    << "Yosys returns error code:" << res.ret;
} // design_only_gen_smt


void VlgSglTgtGen_Cvc4SyGuS::load_smt_from_file(const std::string & smt_fname, std::string & smt_converted) {
  std::stringstream ibuf;
  { // read file
    std::ifstream smt_fin( smt_fname );
    if(not smt_fin.is_open()) {
      ILA_ERROR << "Cannot read from " << smt_fname;
      return;
    }
    ibuf << smt_fin.rdbuf();
  } // end read file  

  design_smt_info = std::make_shared<smt::YosysSmtParser> (ibuf.str());
  if (_vtg_config.YosysSmtFlattenDatatype) {
    design_smt_info->BreakDatatypes();
    //smt_rewriter.AddNoChangeStateUpdateFunction();
    smt_converted = design_smt_info->Export();
  } else {
    smt_converted = ibuf.str();
  }
} // load_smt_from_file

void VlgSglTgtGen_Cvc4SyGuS::convert_datapoints_to_sygus(const std::string & smt_fname, TraceDataPoints * dp, const std::string & sygus_fname, const Cvc4Syntax & syntax) {

  std::string smt_converted;
  load_smt_from_file(smt_fname, smt_converted);

  Cvc4SygusInputGenerator gen_sygus_input(
    *(design_smt_info.get()), var_names, _vtg_config.SygusOptions, dp, sup_info.width_info, syntax );
  gen_sygus_input.ExportToFile(sygus_fname);

  inv_parsing_corrections = gen_sygus_input.GetCorrectionMap();
} // convert_datapoints_to_sygus

void VlgSglTgtGen_Cvc4SyGuS::convert_smt_to_chc_sygus(const std::string & smt_fname, const std::string & sygus_chc_fname, const Cvc4Syntax & syntax) {
  
  ILA_ASSERT (_vtg_config.YosysSmtFlattenDatatype)
     << "For SyGuS through passing transfer function, datatype must be flattened!";
  // now when you call load_smt_from_file, it has already been flattened

  std::string smt_converted;
  load_smt_from_file(smt_fname, smt_converted);

  Cvc4SygusChcGenerator gen_sygus_input(
    *(design_smt_info.get()), var_names, _vtg_config.SygusOptions,
    smt_converted, sup_info.width_info, syntax);
  gen_sygus_input.ExportToFile(sygus_chc_fname);

  inv_parsing_corrections = gen_sygus_input.GetCorrectionMap();
} // convert_smt_to_chc
  

}; // namespace ilang
