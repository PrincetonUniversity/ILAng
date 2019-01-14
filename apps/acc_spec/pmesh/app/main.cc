#include <pmesh_l15_ila.h>
#include <ilang/vtarget-out/vtarget_gen.h>

/// the function to generate configuration
VerilogVerificationTargetGenerator::vtg_config_t SetConfiguration();

void verifyPMeshL15(
  Ila& model, 
  VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg,
  const std::vector<std::string> & design_files
   ) {
  VerilogGeneratorBase::VlgGenConfig vlg_cfg;
  vlg_cfg.pass_node_name = true;

  std::string RootPath    = "..";
  std::string VerilogPath = RootPath    + "/verilog/";
  std::string IncludePath = VerilogPath + "include/";
  std::string RefrelPath  = RootPath    + "/refinement/";
  std::string OutputPath  = RootPath    + "/verification/";

  std::vector<std::string> path_to_design_files;
  for(auto && f : design_files)
    path_to_design_files.push_back( VerilogPath + f );
  

  VerilogVerificationTargetGenerator vg(
      {IncludePath},                                         // one include path
      path_to_design_files,                                  // designs
      "l15_wrap",                                            // top_module_name
      RefrelPath + "ref-rel-var-map.json",                   // variable mapping
      RefrelPath + "ref-rel-inst-cond.json",                 // conditions of start/ready
      OutputPath,                                            // output path
      model.get(),                                           // model
      VerilogVerificationTargetGenerator::backend_selector::COSA, // backend: COSA
      vtg_cfg,  // target generator configuration
      vlg_cfg); // verilog generator configuration

  vg.GenerateTargets();
}


/// Build the model
int main() {
  // extract the configurations
  std::vector<std::string> design_files = {
    "bram_1r1w_wrapper.v",
    "bram_1rw_wrapper.v",
    "flat_id_to_xy.tmp.v",
    "l15_mshr.tmp.v",
    "l15_pipeline.tmp.v",
    "l15.v",
    "l15_csm.tmp.v",
    "l15_hmc.tmp.v",
    "l15_home_encoder.tmp.v",
    "l15_priority_encoder.tmp.v",
    "l15_wrap.v",
    "noc1buffer.tmp.v",
    "noc1encoder.v",
    "noc2decoder.v",
    "noc3buffer.v",
    "noc3encoder.v",
    "rf_l15_lruarray.tmp.v",
    "rf_l15_mesi.tmp.v",
    "rf_l15_wmt.tmp.v",
    "simplenocbuffer.v",
    "sram_l15_data.tmp.v",
    "sram_l15_hmt.tmp.v",
    "sram_l15_tag.tmp.v"
  };

  auto vtg_cfg = SetConfiguration();

  // build the model
  PMESH_L15 l15_ila_model;

  verifyPMeshL15(l15_ila_model.model, vtg_cfg, design_files);

  return 0;
}



VerilogVerificationTargetGenerator::vtg_config_t SetConfiguration() {

  // set ilang option, operators like '<' will refer to unsigned arithmetics
  SetUnsignedComparison(true); 
  
  VerilogVerificationTargetGenerator::vtg_config_t ret;
  ret.CosaSolver = "btor";
  ret.CosaPyEnvironment = "~/cosaEnv/bin/activate";
  ret.CosaPath = "~/CoSA";
  ret.CosaGenTraceVcd = true;

  /// other configurations
  ret.PortDeclStyle = VlgVerifTgtGenBase::vtg_config_t::NEW;
  ret.CosaGenJgTesterScript = true;
  ret.CosaOtherSolverOptions = "--blackbox-array";
  //ret.ForceInstCheckReset = true;

  return ret;
}