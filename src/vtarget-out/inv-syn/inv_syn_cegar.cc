/// \file Source for invariant synthesis --- using CEGAR loop
// Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/fs.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/verilog-in/verilog_analysis.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>
#include <ilang/vtarget-out/inv-syn/sygus/inv_cex_extract.h>
#include <ilang/vtarget-out/inv-syn/sygus/datapoint_inv_prune.h>

#include <memory>

namespace ilang {

static std::string select_script_to_run(const std::vector<std::string> & scripts, const std::string sel) {
  ILA_ASSERT(not sel.empty()) << "no selection is provided in RunVerifAuto";
  std::vector<std::string>  sels;
  for(auto && sc : scripts)
    if (S_IN(sel,sc))
      sels.push_back(sc);
  ILA_ASSERT(not sels.empty()) << "Auto run: no selection!";
  if (sels.size() > 1) {
    ILA_ERROR << "Multi scripts selected!";
    for(auto && sc : sels)
      ILA_ERROR << sc;
    ILA_ASSERT(false);
  }
  return sels[0];
}


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
    _vtg_config(vtg_config), _vlg_config(config),
    // ------------ statistics bookkeeping --------------- //
    eqcheck_time(0), inv_validate_time(0), inv_proof_attempt_time(0), 
    inv_syn_time(0) 
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

    current_inv_type = cur_inv_tp::NONE;

  } // end of constructor

bool InvariantSynthesizerCegar::check_in_bad_state() const {
  ILA_ERROR_IF(bad_state) << "In bad state, cannot proceed.";
  return bad_state;
}


// -------------------------------- VERIFICATION TARGETS ------------------------------------------- //

/// to generate a target to validate the given and synthesize invariants and guessed ones
void InvariantSynthesizerCegar::GenerateInvariantVerificationTarget() {
  if (check_in_bad_state()) return;

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj;
  adv_param._candidate_inv_ptr = &inv_candidate;

  auto inv_gen_vtg_config = _vtg_config;
  inv_gen_vtg_config.target_select = inv_gen_vtg_config.INV;
  inv_gen_vtg_config.ValidateSynthesizedInvariant = vtg_config_t::_validate_synthesized_inv::ALL; // overwrite
  
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
  adv_param._candidate_inv_ptr = &inv_candidate; 
  
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
  inv_candidate.set_dut_inst_name(vlg_mod_inst_name);

  runnable_script_name = vg.GetRunnableScriptName();
  if (additional_width_info.empty())
    additional_width_info = vg.GetSupplementaryInfo().width_info;

  status = cegar_status::V_RES;
}


/// to generate targets using the provided invariants
void InvariantSynthesizerCegar::GenerateVerificationTarget(const std::vector<std::string> & invs) {
  for(auto && inv : invs)
    inv_obj.AddInvariantFromVerilogExpr(std::to_string(round_id), inv);
  GenerateVerificationTarget();
} // to generate targets using the provided invariants


// -------------------------------- CHC SYNTHESIS TARGETS ------------------------------------------- //

/// to generate synthesis target
void InvariantSynthesizerCegar::GenerateSynthesisTarget() {
  // generate a target -- based on selection
  if (check_in_bad_state()) return;
  ILA_WARN_IF(status != cegar_status::NEXT_S) << "CEGAR-loop: not expecting synthesis step.";

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
  adv_param._candidate_inv_ptr = NULL;
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

  current_inv_type = cur_inv_tp::CHC;
} // GenerateSynthesisTarget

// -------------------------------- EXTRACTIONS ------------------------------------------- //

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

  auto is_reg = [&](const std::string & n) -> bool {
    return VerilogAnalyzerBase::is_reg(
      va.check_hierarchical_name_type(n));
  };

  // not passing
  cex_extract = std::unique_ptr<CexExtractor>(
    new CexExtractor(res_file,vlg_mod_inst_name, is_reg, not _vtg_config.CosaFullTrace));
  // advance to synthesis stage
  status = cegar_status::NEXT_S;
} // extract result


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

  ILA_ASSERT(current_inv_type != cur_inv_tp::SYGUS_CEX) 
    << "API misuse: should not use this function on SYGUS CEX output, they may not be the invariants, but just candidates!";
    
  if (current_inv_type == cur_inv_tp::CHC)
    inv_obj.AddInvariantFromChcResultFile(
      *(design_smt_info.get()), "", res_file, 
      _vtg_config.YosysSmtFlattenDatatype,
      _vtg_config.YosysSmtFlattenHierarchy );
  else if (current_inv_type == cur_inv_tp::SYGUS_CHC) // we reparse even for SyGuS cex
    ILA_ASSERT(
      inv_obj.AddInvariantFromSygusResultFile(
      *(design_smt_info.get()), "", res_file, 
      _vtg_config.YosysSmtFlattenDatatype,
      _vtg_config.YosysSmtFlattenHierarchy ))
    << "SyGuS solver failed to generate an invariant";
  else
    ILA_ERROR<<"Inv type unknown:" << current_inv_type;
  
  std::cout << "Confirmed synthesized invariants:" << std::endl;
  for (auto && v : inv_obj.GetVlgConstraints() )
    std::cout << v << std::endl;

  status = cegar_status::NEXT_V;
  current_inv_type = cur_inv_tp::NONE; // we have extracted, reset this marker

} // ExtractSynthesisResult

// -------------------------------- AUTO RUNS ------------------------------------------- //

/// a helper function (only locally available)
/// to detect tool error (e.g., verilog parsing error)
bool static has_verify_tool_error_cosa(const std::string & fn) {
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
} // has_verify_tool_error_cosa

  /// a helper function (only locally available)
/// to detect tool error (e.g., verilog parsing error)
bool static has_verify_tool_unknown_cosa(const std::string & fn) {
  std::ifstream fin(fn);
  if (not fin.is_open()) {
    ILA_ERROR<<"Unable to read from:"<<fn;
    return true;
  }
  
  std::string line;
  while(std::getline(fin,line)) {
    if (S_IN("UNKNOWN != TRUE <<<---------| ERROR" , line))
      return true;
  }
  return false;
} // has_verify_tool_error_cosa
/// run Verification
bool InvariantSynthesizerCegar::RunVerifAuto(const std::string & script_selection) {
  auto script_sel = select_script_to_run(runnable_script_name, script_selection );
  if(check_in_bad_state())
    return true;
  // Not implemented
  auto result_fn = os_portable_append_dir(_output_path, "__verification_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__verification_result.txt");
  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(script_sel);
  ILA_ERROR_IF(not os_portable_chdir(new_wd)) 
    << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing verify script:" << script_sel;
  auto res = os_portable_execute_shell({"bash", 
    os_portable_file_name_from_path( script_sel) },
   redirect_fn, redirect_t::BOTH);
  ILA_ERROR_IF(res.failure != execute_result::NONE)
    << "Running verification script " << script_sel << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));
  // the last line contains the result
  // above it you should have *** TRACES ***
  // the vcd file resides within the new dir
  ILA_ERROR_IF(has_verify_tool_error_cosa(result_fn)) << "----------- Verification tool reported error! Please check the log output!";
  ILA_ERROR_IF(has_verify_tool_unknown_cosa(result_fn)) << "UNKNOWN Verif result";

  eqcheck_time += res.seconds;

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
  execute_result res;
  if (current_inv_type == SYGUS_CEX || current_inv_type == SYGUS_CHC) {
    res = os_portable_execute_shell({"bash",
      os_portable_file_name_from_path( runnable_script_name[0] )}); // we don't need to redirect
  }
  else {
    res = os_portable_execute_shell({"bash",
      os_portable_file_name_from_path( runnable_script_name[0] )},
      redirect_fn, redirect_t::BOTH);
  }
  ILA_ERROR_IF(res.failure != execute_result::NONE )
    << "Running synthesis script " << runnable_script_name[0] << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));
  
  inv_syn_time += res.seconds;

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


// -------------------------------- MISCS ------------------------------------------- //

const std::vector<std::string> & InvariantSynthesizerCegar::GetRunnableTargetScriptName() const {
  return runnable_script_name;
}

DesignStatistics InvariantSynthesizerCegar::GetDesignStatistics() const {
  DesignStatistics ret;

  ret.TimeOfEqCheck     = eqcheck_time;
  ret.TimeOfInvProof    = inv_proof_attempt_time;
  ret.TimeOfInvSyn      = inv_syn_time;
  ret.TimeOfInvValidate = inv_validate_time;

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


/// Here you can extract the invariants and export them if needed
const InvariantObject & InvariantSynthesizerCegar::GetCandidateInvariants() const {
  return inv_candidate;
}

const TraceDataPoints & InvariantSynthesizerCegar::GetDatapoints() const {
  return datapoints;
}

void InvariantSynthesizerCegar::LoadInvariantsFromFile(const std::string &fn) {
  inv_obj.ImportFromFile(fn);
}
void InvariantSynthesizerCegar::LoadCandidateInvariantsFromFile(const std::string &fn) {
  inv_candidate.ImportFromFile(fn);
}
void InvariantSynthesizerCegar::LoadDatapointFromFile(const std::string &fn) {
  datapoints.ImportNonprovidedPosEx(fn);
}

// -------------------------------- SYGUS SUPPORT ------------------------------------------- //

/// set the initial datapoints (can be empty, but we suggest using the sim_trace_extract)
void InvariantSynthesizerCegar::SetInitialDatapoint(const TraceDataPoints &dp) {
  datapoints = dp;
}
/// set the sygus name lists (cannot be empty)
void InvariantSynthesizerCegar::SetSygusVarnameList(const std::vector<std::string> & sygus_var_name) {
  sygus_vars = sygus_var_name;
  sygus_vars_set.clear();
  for (auto && vname : sygus_var_name)
    sygus_vars_set.insert(vname);
}

/// can be used for datapoints/transfer function
void InvariantSynthesizerCegar::GenerateSynthesisTargetSygusTransFunc(bool enumerate) {
  // generate a target -- based on selection
  if (check_in_bad_state()) return;
  ILA_WARN_IF(status != cegar_status::NEXT_S) << "CEGAR-loop: not expecting synthesis step.";

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
  adv_param._candidate_inv_ptr = NULL;
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
  
  design_smt_info = vg.GenerateInvSynSygusTargets(s_backend, NULL, sygus_vars, enumerate);

  runnable_script_name = vg.GetRunnableScriptName();

  status = cegar_status::S_RES;

  current_inv_type = cur_inv_tp::SYGUS_CHC;
}


/// can be used for datapoints/transfer function
void InvariantSynthesizerCegar::GenerateSynthesisTargetSygusDatapoints(bool enumerate) {
  // generate a target -- based on selection
  if (check_in_bad_state()) return;
  ILA_WARN_IF(status != cegar_status::NEXT_S) << "CEGAR-loop: not expecting synthesis step.";
  ILA_ASSERT(_vtg_config.SygusOptions.SygusPassInfo == _vtg_config.SygusOptions.DataPoints)
    << "API misuse : you must select datapoint approach as the sygus options";

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
  adv_param._candidate_inv_ptr = NULL;
  adv_param._cex_obj_ptr = cex_extract.get();

  // TraceDataPoints dp_w_cex(datapoints);
  // dp_w_cex.SetNegEx(* cex_extract.get() );

  datapoints.SetNegEx(* cex_extract.get()); // you can reset the pos ex using SetInitialDatapoint 
  
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
  
  design_smt_info = vg.GenerateInvSynSygusTargets(s_backend, &datapoints, sygus_vars, enumerate);

  runnable_script_name = vg.GetRunnableScriptName();

  // status = cegar_status::S_RES; -- no yet
  current_inv_type = cur_inv_tp::SYGUS_CEX;
}


/// to extract the synthesis attempt
bool InvariantSynthesizerCegar::ExtractSygusDatapointSynthesisResultAsCandidateInvariant() {
  ILA_ERROR_IF(current_inv_type != cur_inv_tp::SYGUS_CEX ) << "Not using the SyGuS Datapoint synthesis method!";

  if(check_in_bad_state()) return false;

  std::string res_file = synthesis_result_fn;
  
  ILA_WARN_IF(status != cegar_status::NEXT_S) << "CEGAR-loop: expecting synthesis result.";

  if (design_smt_info == nullptr) {
    ILA_ERROR << "Design SMT-LIB2 info is not available. "
      << "You need to run `GenerateSynthesisTarget` first.";
    return false;
  }

  // inv_candidate.ClearAllInvariants();  -- we will keep the old ones
  if( inv_candidate.AddInvariantFromSygusResultFile(
      *(design_smt_info.get()), "", res_file, 
      _vtg_config.YosysSmtFlattenDatatype,
      _vtg_config.YosysSmtFlattenHierarchy ) == false) {
    return false; // sygus failed
  }
    
  std::cout << "INV candidate:" << std::endl;
  for (auto && v : inv_candidate.GetVlgConstraints() )
    std::cout << v << std::endl;
  return true;
}
/// to validate if the previous attempt is good (inductive or not)
/// if not CTI will be extracted
/// return true if this is okay...
InvariantSynthesizerCegar::_inv_check_res_t InvariantSynthesizerCegar::ValidateSygusDatapointCandidateInvariant(unsigned timeout) {
  ILA_ERROR_IF(current_inv_type != cur_inv_tp::SYGUS_CEX ) 
    << "Not using the SyGuS Datapoint synthesis method!";

  if(inv_candidate.NumInvariant() == 0) {
    ILA_ERROR << "No more candidate invariant to check";
    return INV_PROVED;
  }

  if (check_in_bad_state()) return INV_UNKNOWN;

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj;
  adv_param._candidate_inv_ptr = &inv_candidate;

  auto inv_gen_vtg_config = _vtg_config;
  // inv_gen_vtg_config.OnlyEnforceInvariantsOnInitialStateOfInstrCheck = false; // always true
  inv_gen_vtg_config.target_select = inv_gen_vtg_config.INV;
  inv_gen_vtg_config.CosaFullTrace = true;
  inv_gen_vtg_config.ValidateSynthesizedInvariant = vtg_config_t::_validate_synthesized_inv::CANDIDATE; // overwrite
  
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
  
  auto inv_validate_script = vg.GetRunnableScriptName();
  std::string inv_cex_path;
  ILA_ASSERT(inv_validate_script.size() == 1) << "Only expect a single runnable";

  // run the validating
  auto result_fn = os_portable_append_dir(_output_path, "__verification_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__verification_result.txt");
  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(inv_validate_script[0]);
  ILA_ERROR_IF(not os_portable_chdir(new_wd)) 
    << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing verify script:" << inv_validate_script[0];
  auto res = os_portable_execute_shell({"bash", 
    os_portable_file_name_from_path( inv_validate_script[0]) },
   redirect_fn, redirect_t::BOTH, timeout);
  ILA_ERROR_IF(res.failure != execute_result::NONE)
    << "Running verification script " << inv_validate_script[0] << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));

  inv_validate_time += res.seconds;

  if(res.timeout || ! res.subexit_normal)
    return INV_UNKNOWN;
  // the last line contains the result
  // above it you should have *** TRACES ***
  // the vcd file resides within the new dir
  ILA_ERROR_IF(has_verify_tool_error_cosa(result_fn)) << "----------- Verification tool reported error! Please check the log output!";
  if(has_verify_tool_unknown_cosa(result_fn))
    return INV_UNKNOWN;
  auto lastLine = os_portable_read_last_line(result_fn);
  ILA_ERROR_IF(lastLine.empty()) << "Unable to extract verification result.";
  if (S_IN("Verifications with unexpected result", lastLine)) {
    ILA_INFO << "SyGuS-attempt CTI found.";

    inv_cex_path = extract_vcd_name_from_cex(result_fn);
    inv_cex_path = os_portable_append_dir(new_wd, inv_cex_path);

    // determine if a name is something we care about
    auto is_coi = [&](const std::string & n) -> bool {
      return IN(n,sygus_vars_set);
    };

    // load the cex from vcd file
    InvCexExtractor cti_extract(inv_cex_path, vlg_mod_inst_name, is_coi );
    datapoints.AddPosEx( cti_extract );

    return INV_INVALID;
  } // CTI found (you can start another round if you want )
  // otherwise, we are good
  
  // make the candidate as confirmed
  AcceptAllCandidateInvariant();

  return INV_PROVED;
}

void InvariantSynthesizerCegar::AcceptAllCandidateInvariant() {
  if(inv_candidate.NumInvariant() != 0) {
    inv_obj.InsertFromAnotherInvObj(inv_candidate);
    inv_candidate.ClearAllInvariants();
  } else 
    ILA_INFO <<"All candidate invariants have been accepted.";
}

void InvariantSynthesizerCegar::PruneCandidateInvariant() {
  // future work : remove only obvious failing ones
  // inv_candidate.ClearAllInvariants();
  ILA_ASSERT(not sygus_vars.empty());
  
  DatapointInvariantPruner pruner(inv_candidate,datapoints);
  pruner.PruneByLastFramePosEx(*(design_smt_info.get()), sygus_vars, additional_width_info );
}


/// Supply Verilog candidate invariants
void InvariantSynthesizerCegar::SupplyCandidateInvariant(const std::string &vlg_expr) {
  ILA_WARN << "Verilog invariant cannot be pruned";
  inv_candidate.AddInvariantFromVerilogExpr("",vlg_expr);
}


/// to generate synthesis target
InvariantSynthesizerCegar::_inv_check_res_t InvariantSynthesizerCegar::ProofCandidateInvariants(
  unsigned timeout, _state_sort_t state_encoding, bool flatten_dp) {
  // generate a target -- based on selection
  if (check_in_bad_state()) return INV_UNKNOWN;
  ILA_WARN_IF(status != cegar_status::NEXT_S) << "CEGAR-loop: not expecting synthesis step.";

  ILA_ERROR_IF(current_inv_type != cur_inv_tp::SYGUS_CEX ) 
      << "Not using the SyGuS Datapoint synthesis method!";

  if (inv_candidate.NumInvariant() == 0) {
    ILA_ERROR << "No more candidate invariants to prove!";
    return INV_PROVED;
  }

  // to send in the invariants
  advanced_parameters_t adv_param;
  adv_param._inv_obj_ptr = &inv_obj; 
  adv_param._candidate_inv_ptr = &inv_candidate;
  adv_param._cex_obj_ptr = NULL;

  auto inv_proof_vtg_config = _vtg_config;
  // inv_gen_vtg_config.OnlyEnforceInvariantsOnInitialStateOfInstrCheck = false; // always true
  inv_proof_vtg_config.YosysSmtStateSort = state_encoding;
  inv_proof_vtg_config.YosysSmtFlattenHierarchy = true;
  inv_proof_vtg_config.YosysSmtFlattenDatatype = flatten_dp;
  inv_proof_vtg_config.CosaGenTraceVcd = false;
  // this does not matter actually
  inv_proof_vtg_config.target_select = inv_proof_vtg_config.INV; 
  // this does not matter either
  inv_proof_vtg_config.ValidateSynthesizedInvariant = vtg_config_t::_validate_synthesized_inv::CANDIDATE; // overwrite
 
  VlgVerifTgtGen vg(
      implementation_incl_path,         // include
      implementation_srcs_path,         // sources
      implementation_top_module_name,   // top_module_name
      refinement_variable_mapping_path, // variable mapping
      refinement_condition_path,        // conditions
      _output_path,                     // output path
      _host,                            // ILA
      verify_backend_selector::YOSYS,   // verification backend setting
      inv_proof_vtg_config,             // target configuration
      _vlg_config,                      // verilog generator configuration
      &adv_param                        // advanced parameter
      );
  
  vg.GenerateDesignOnlyCandidateInvChcCheckTargets(synthesis_backend_selector::Z3);

  auto run_script = vg.GetRunnableScriptName();

  ILA_ASSERT(run_script.size() == 1) << "Need exactly one script";
  auto synthesis_result_fn = os_portable_append_dir(_output_path, "__chc_check_result.txt");
  auto redirect_fn = os_portable_append_dir("../", "__chc_check_result.txt");

  auto cwd = os_portable_getcwd();
  auto new_wd = os_portable_path_from_path(run_script[0]);
  ILA_ERROR_IF(not os_portable_chdir(new_wd)) 
    << "RunVerifAuto: cannot change dir to:" << new_wd;
  ILA_INFO << "Executing synthesis script:" <<  run_script[0] ;
  auto res = os_portable_execute_shell({"bash",
    os_portable_file_name_from_path( run_script[0] )}, redirect_fn, BOTH, timeout);
  
  ILA_ERROR_IF(res.failure != execute_result::NONE )
    << "Running synthesis script " << run_script[0] << " results in error."; 
  ILA_ASSERT(os_portable_chdir(cwd));
  
  inv_proof_attempt_time += res.seconds;

  if (res.timeout || ! res.subexit_normal)
    return INV_UNKNOWN;
  std::string line;
  { // read the result
    std::ifstream fin(synthesis_result_fn);
    if (not fin.is_open()) {
      ILA_ASSERT(false) << "Unable to read the synthesis result file:" << synthesis_result_fn;
      status = cegar_status::FAILED;
      bad_state = true;
      return INV_UNKNOWN; // reachable
    } 
    std::getline(fin,line);  
  } // finish file reading
  if (S_IN("unsat", line))
  {
    AcceptAllCandidateInvariant();
    return INV_PROVED;
  }
  if (S_IN("Terminated",line)) {
    ILA_ERROR << "Z3 has terminated!";
    return INV_UNKNOWN;
  }
  if (S_IN("(error", line))
    return INV_UNKNOWN;
  // else reachable
  return INV_INVALID;

} // GenerateSynthesisTarget

}; // namespace ilang
