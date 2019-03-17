/// \file Source for invariant synthesis --- using CEGAR loop
// Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/vtarget-out/inv_syn_cegar.h>

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

    // Future work : all instructions and re-use
    // we allow both inv and inst, but you need to specify the instruction
    if(_vtg_config.CheckThisInstructionOnly.empty()) {
      ILA_ERROR << << "You must specify which instruction to check.";
      bad_state = true;
      return;
    }


  } // end of constructor

bool InvariantSynthesizerCegar::check_in_bad_state() const {
  if(bad_state)
    ILA_ERROR << "In bad state, cannot proceed.";
  return !bad_state;
}

// to do things separately, you can provide the run function yourself
// or even do it step by step
/// to generate targets using the current invariants
void InvariantSynthesizerCegar::GenerateVerificationTarget() {
  GenerateVerificationTarget(invariants);
}
/// to generate targets using the provided invariants
void InvariantSynthesizerCegar::GenerateVerificationTarget(const std::vector<std::string> & invs) {
  // generate a target -- based on selection
  if (check_in_bad_state()) return;
  
  VerilogVerificationTargetGenerator vg(
      implementation_incl_path,         // include
      implementation_srcs_path,         // sources
      implementation_top_module_name,   // top_module_name
      refinement_variable_mapping_path, // variable mapping
      refinement_condition_path,        // conditions
      _output_path,                     // output path
      _host,                            // ILA
      v_backend,
      _vtg_config,
      _vlg_config);
  
  vg.GenerateTargets();
}

/// to extract result 
void InvariantSynthesizerCegar::ExtractVerificationResult(bool autodet, bool pass, const std::string & res_file) {
  
}
/// to generate synthesis target
void InvariantSynthesizerCegar::GenerateSynthesisTarget() {

}
/// run Verification
bool InvariantSynthesizerCegar::RunVerifAuto() {

}
/// run Synthesis
bool InvariantSynthesizerCegar::RunSynAuto() {

}

}; // namespace ilang
