/// \file Source for invariant synthesis --- using CEGAR loop
// Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/fs.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/verilog-in/verilog_analysis.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>

#include <memory>

namespace ilang {

// problem: you cannot create and keep the objs
// so you need to keep the infos
InvariantSynthesizerCegar::InvariantSynthesizerCegar(
  const std::vector<std::string>& implementation_include_path,
  const std::vector<std::string>& implementation_srcs,
  const std::string& implementation_top_module,
  const std::string& refinement_variable_mapping,
  const std::string& refinement_conditions, const std::string& output_path,
  const InstrLvlAbsPtr& ila_ptr,
  verify_backend_selector vbackend,
  synthesis_backend_selector sbackend,
  const vtg_config_t& vtg_config,
  const VerilogGenerator::VlgGenConfig& config):
    status(cegar_status::NEXT_V), bad_state(false),
    round_id(0),
    // book-keeping
    implementation_incl_path(implementation_include_path),
    implementation_srcs_path(implementation_srcs),
    implementation_top_module_name(implementation_top_module),
    refinement_variable_mapping_path(refinement_variable_mapping),
    refinement_condition_path(refinement_conditions),
    _output_path(output_path),
    _host(ila_ptr),v_backend(vbackend),s_backend(sbackend),
    _vtg_config(vtg_config), _vlg_config(config)
  {
    // detect some wrong settings here
    if(vbackend != verify_backend_selector::COSA) {
      ILA_ERROR << "Implementation bug: currently only support COSA.";
      bad_state = true;
      return;
    }
    // BUG: should also consider Yosys single inv?

    // we need to have the vcd generated
    _vtg_config.CosaGenTraceVcd = true;
    // for other backend, enable similar options

  } // end of constructor

bool InvariantSynthesizerCegar::check_in_bad_state() const {
  ILA_ERROR_IF(bad_state) << "In bad state, cannot proceed.";
  return bad_state;
}

/// to generate a target to validate the given and synthesize invariants
void InvariantSynthesizerCegar::GenerateInvariantVerificationTarget() {
  if (check_in_bad_state()) return;

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj;

  auto inv_gen_vtg_config = _vtg_config;
  inv_gen_vtg_config.target_select = inv_gen_vtg_config.INV;
  inv_gen_vtg_config.AutoValidateSynthesizedInvariant = true; // overwrite
  
  VlgVerifTgtGen vg(
      implementation_incl_path,         // include
      implementation_srcs_path,         // sources
      implementation_top_module_name,   // top_module_name
      refinement_variable_mapping_path, // variable mapping
      refinement_condition_path,        // conditions
      _output_path,                     // output path
      _host,                            // ILA
      v_backend,                        // verification backend setting
      inv_gen_vtg_config,               // target configuration
      _vlg_config,                      // verilog generator configuration
      &adv_param                        // advanced parameter
      );
  
  vg.GenerateTargets();
}

// to do things separately, you can provide the run function yourself
// or even do it step by step
/// to generate targets using the current invariants
void InvariantSynthesizerCegar::GenerateVerificationTarget() {
  // generate a target -- based on selection
  if (check_in_bad_state()) return;
  ILA_WARN_IF(status != cegar_status::NEXT_V) << "CEGAR-loop: repeated verification step.";

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
  
  VlgVerifTgtGen vg(
      implementation_incl_path,         // include
      implementation_srcs_path,         // sources
      implementation_top_module_name,   // top_module_name
      refinement_variable_mapping_path, // variable mapping
      refinement_condition_path,        // conditions
      _output_path,                     // output path
      _host,                            // ILA
      v_backend,                        // verification backend setting
      _vtg_config,                      // target configuration
      _vlg_config,                      // verilog generator configuration
      &adv_param                        // advanced parameter
      );
  
  vg.GenerateTargets();

  vlg_mod_inst_name = vg.GetVlgModuleInstanceName();
  inv_obj.set_dut_inst_name(vlg_mod_inst_name);

  runnable_script_name = vg.GetRunnableScriptName();

  status = cegar_status::V_RES;
}


/// to generate targets using the provided invariants
void InvariantSynthesizerCegar::GenerateVerificationTarget(const std::vector<std::string> & invs) {
  for(auto && inv : invs)
    inv_obj.AddInvariantFromVerilogExpr(std::to_string(round_id), inv);
  GenerateVerificationTarget();
} // to generate targets using the provided invariants

/// to extract result 
void InvariantSynthesizerCegar::ExtractVerificationResult(bool autodet, bool pass, 
  const std::string & vcd_file, const std::string & mod_inst_name ) {
  if(check_in_bad_state()) return;

  std::string res_file = vcd_file;
  if (autodet) {
    res_file = vcd_file_name;
    pass = verification_pass;
  }
  ILA_WARN_IF(status != cegar_status::V_RES) << "CEGAR-loop: repeated verification step.";

  vlg_mod_inst_name = vlg_mod_inst_name.empty() ? mod_inst_name : vlg_mod_inst_name;
  if (vlg_mod_inst_name.empty()) {
    ILA_ERROR << "Instance name in vcd is unknown and not specified";
    bad_state = true;
    return;
  }

  if(pass) {
    ILA_INFO << "No counterexample has been found. CEGAR loop finishes.";
    status = cegar_status::DONE;
    return;
  }

  // we still need to create a verilog info analyzer
  VerilogAnalyzer va(
      implementation_incl_path, implementation_srcs_path,
      vlg_mod_inst_name, implementation_top_module_name );

  auto is_reg = [&](const std::string & n) {
    return VerilogAnalyzerBase::is_reg(
      va.check_hierarchical_name_type(n));
  };

  // not passing
  cex_extract = std::unique_ptr<CexExtractor>(
    new CexExtractor(res_file,vlg_mod_inst_name, is_reg));
  // advance to synthesis stage
  status = cegar_status::NEXT_S;
} // extract result

/// to generate synthesis target
void InvariantSynthesizerCegar::GenerateSynthesisTarget() {
  // generate a target -- based on selection
  if (check_in_bad_state()) return;
  ILA_WARN_IF(status != cegar_status::NEXT_S) << "CEGAR-loop: not expecting synthesis step.";

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
  adv_param._cex_obj_ptr = cex_extract.get();
  
  VlgVerifTgtGen vg(
      implementation_incl_path,         // include
      implementation_srcs_path,         // sources
      implementation_top_module_name,   // top_module_name
      refinement_variable_mapping_path, // variable mapping
      refinement_condition_path,        // conditions
      _output_path,                     // output path
      _host,                            // ILA
      verify_backend_selector::YOSYS,   // verification backend setting
      _vtg_config,                      // target configuration
      _vlg_config,                      // verilog generator configuration
      &adv_param                        // advanced parameter
      );
  
  design_smt_info = vg.GenerateInvSynTargets(s_backend);

  runnable_script_name = vg.GetRunnableScriptName();

  status = cegar_status::S_RES;
} // GenerateSynthesisTarget

/// a helper function (only locally available)
/// to extract vcd file name from the output
std::string extract_vcd_name_from_cex(const std::string & fn) {
  std::ifstream fin(fn);
  if (not fin.is_open()) {
    ILA_ERROR<<"Unable to read from:"<<fn;
    return "";
  }
  std::string line;
  while(std::getline(fin,line)) {
    if (S_IN("*** TRACES ***" , line))
      break;
  }
  if(fin.eof()) {
    ILA_ERROR << "Cannot extract vcd filename, incorrect format, expecting *** TRACES ***";
    return "";
  }
  std::string fname;
  fin >> fname; fin >> fname; // the first is garbage;
  ILA_ERROR_IF (not S_IN(".vcd", fname)) << "Expecting vcd file name, get " << fname;
  return fname;
} // extract_vcd_name_from_cex

/// a helper function (only locally available)
/// to detect tool error (e.g., verilog parsing error)
bool has_verify_tool_error_cosa(const std::string & fn) {
  std::ifstream fin(fn);
  if (not fin.is_open()) {
    ILA_ERROR<<"Unable to read from:"<<fn;
    return true;
  }
  
  std::string line;
  while(std::getline(fin,line)) {
    if (S_IN("See yosys-err.log for more info." , line))
      return true;
  }
  return false;
}


/// run Verification
bool InvariantSynthesizerCegar::RunVerifAuto(unsigned problem_idx) {
  if(check_in_bad_state())
    return true;
  // Not implemented
  auto result_fn = os_portable_append_dir(_output_path, "__verification_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__verification_result.txt");
  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(runnable_script_name[problem_idx]);
  ILA_ERROR_IF(not os_portable_chdir(new_wd)) 
    << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing verify script:" << runnable_script_name[problem_idx];
  ILA_ERROR_IF(not os_portable_execute_shell({"bash", 
    os_portable_file_name_from_path( runnable_script_name[problem_idx]) },
   redirect_fn, redirect_t::BOTH))
  << "Running verification script " << runnable_script_name[problem_idx] << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));
  // the last line contains the result
  // above it you should have *** TRACES ***
  // the vcd file resides within the new dir
  ILA_ERROR_IF(has_verify_tool_error_cosa(result_fn)) << "----------- Verification tool reported error! Please check the log output!";
  auto lastLine = os_portable_read_last_line(result_fn);
  ILA_ERROR_IF(lastLine.empty()) << "Unable to extract verification result.";
  if (S_IN("Verifications with unexpected result", lastLine)) {
    ILA_INFO << "Counterexample found.";

    vcd_file_name = extract_vcd_name_from_cex(result_fn);
    vcd_file_name = os_portable_append_dir(new_wd, vcd_file_name);

    verification_pass = false;
    return false;
  }
  verification_pass = true;
  status = cegar_status::DONE;
  ILA_INFO << "No counterexample has been found. CEGAR loop finishes.";
  return true;
}
/// run Synthesis
bool InvariantSynthesizerCegar::RunSynAuto() {
  if(check_in_bad_state())
    return true;
  
  ILA_ASSERT(runnable_script_name.size() == 1) << "Please run GenerateInvSynTargets function first";
  synthesis_result_fn = os_portable_append_dir(_output_path, "__synthesis_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__synthesis_result.txt");

  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(runnable_script_name[0]);
  ILA_ERROR_IF(not os_portable_chdir(new_wd)) 
    << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing synthesis script:" <<  runnable_script_name[0] ;
  ILA_ERROR_IF(not os_portable_execute_shell({"bash",
    os_portable_file_name_from_path( runnable_script_name[0] )},
    redirect_fn, redirect_t::BOTH))
  << "Running synthesis script " << runnable_script_name[0] << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));
  
  std::string line;
  { // read the result
    std::ifstream fin(synthesis_result_fn);
    if (not fin.is_open()) {
      ILA_ERROR << "Unable to read the synthesis result file:" << synthesis_result_fn;
      status = cegar_status::FAILED;
      bad_state = true;
      return true; // reachable
    } 
    std::getline(fin,line);  
  } // finish file reading
  cex_reachable = true;
  if (S_IN("unsat", line))
    cex_reachable = false; // not reachable
  // else reachable
  return cex_reachable;
}

const std::vector<std::string> & InvariantSynthesizerCegar::GetRunnableTargetScriptName() const {
  return runnable_script_name;
}


void InvariantSynthesizerCegar::ExtractSynthesisResult(bool autodet, bool reachable, 
  const std::string & given_smt_chc_result_txt) {
  
  if(check_in_bad_state()) return;

  std::string res_file = given_smt_chc_result_txt;
  if (autodet) {
    reachable = cex_reachable;
    res_file = synthesis_result_fn;
  }
  
  ILA_WARN_IF(status != cegar_status::S_RES) << "CEGAR-loop: expecting synthesis result.";

  if (design_smt_info == nullptr) {
    ILA_ERROR << "Design SMT-LIB2 info is not available. "
      << "You need to run `GenerateSynthesisTarget` first.";
    return;
  }

  if (reachable) {
    ILA_ERROR << "Verification failed with true counterexample!";
    status = cegar_status::FAILED;
    return;
  }

  inv_obj.AddInvariantFromChcResultFile(
    *(design_smt_info.get()), "", res_file, 
    _vtg_config.YosysSmtFlattenDatatype,
    _vtg_config.YosysSmtFlattenHierarchy );
  
  for (auto && v : inv_obj.GetVlgConstraints() )
    std::cout << v << std::endl;

  status = cegar_status::NEXT_V;

} // ExtractSynthesisResult

DesignStatistics InvariantSynthesizerCegar::GetDesignStatistics() const {
  DesignStatistics ret;

  if (design_smt_info == nullptr) {
    ILA_ERROR << "Design information not available!";
    return ret;
  }
  std::string query_mod_name = implementation_top_module_name;
  
  ILA_ERROR_IF(vlg_mod_inst_name.empty()) << "vlg_mod_inst_name is empty, will not distinguish in/out module state";

  for (auto && st : design_smt_info->get_module_flatten_dt("wrapper")) {
    
    if ( st.verilog_name.find(vlg_mod_inst_name + ".") == 0 ) {
      ret.NumOfDesignStateBits += st._type.GetBoolBvWidth();
      ret.NumOfDesignStateVars ++;
    } else {
      ret.NumOfExtraStateBits += st._type.GetBoolBvWidth();
      ret.NumOfExtraStateVars ++;
    }
  }
  return ret;
}
const InvariantObject & InvariantSynthesizerCegar::GetInvariants() const {
  return inv_obj;
}

}; // namespace ilang
