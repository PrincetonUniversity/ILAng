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

  std::string RootPath = "..";
  std::string VerilogPath = RootPath + "/verilog/";
  std::string RefrelPath = RootPath + "/refinement/";
  std::string OutputPath = RootPath + "/verification/";

  std::vector<std::string> path_to_design_files;
  for(auto && f : design_files)
    path_to_design_files.push_back( VerilogPath + f );
  

  VerilogVerificationTargetGenerator vg(
      {},                                                    // no include
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
  auto vtg_cfg = SetConfiguration();

  // build the model
  PMESH_L15 l15_ila_model;

  return 0;
}



VerilogVerificationTargetGenerator::vtg_config_t SetConfiguration() {

  // set ilang option, operators like '<' will refer to unsigned arithmetics
  SetUnsignedComparation(true); 
  
  VerilogVerificationTargetGenerator::vtg_config_t ret;
  ret.CosaSolver = "btor";
  ret.CosaPyEnvironment = "~/cosaEnv/bin/activate";
  ret.CosaPath = "~/CoSA";
  ret.CosaGenTraceVcd = true;

  return ret;
}