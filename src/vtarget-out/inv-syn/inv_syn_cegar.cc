/// \file Source for invariant synthesis --- using CEGAR loop
// Hongce Zhang

#include <ilang/util/log.h>
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

  status = cegar_status::V_RES;
}
/// to generate targets using the provided invariants
void InvariantSynthesizerCegar::GenerateVerificationTarget(const std::vector<std::string> & invs) {
  for(auto && inv : invs)
    inv_obj.AddInvariantFromVerilog(std::to_string(round_id), inv);
  GenerateVerificationTarget();
} // to generate targets using the provided invariants

/// to extract result 
void InvariantSynthesizerCegar::ExtractVerificationResult(bool autodet, bool pass, 
  const std::string & res_file, const std::string & mod_inst_name ) {
  ILA_ASSERT(not autodet) << "Future work, not able to auto-determine verify result";
  ILA_WARN_IF(status != cegar_status::V_RES) << "CEGAR-loop: repeated verification step.";

  vlg_mod_inst_name = vlg_mod_inst_name.empty() ? mod_inst_name : vlg_mod_inst_name;
  if (vlg_mod_inst_name.empty()) {
    ILA_ERROR << "Instance name in vcd is unknown and not specified";
    bad_state = true;
    return;
  }

  if(pass) {
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
  
  vg.GenerateInvSynTargets(s_backend);
} // GenerateSynthesisTarget
/// run Verification
bool InvariantSynthesizerCegar::RunVerifAuto() {
  return true;
}
/// run Synthesis
bool InvariantSynthesizerCegar::RunSynAuto() {
  return true;
}

}; // namespace ilang
