#include <aes_128.h>
#include <aes_ila.h>
#include <ilang/vtarget-out/vtarget_gen.h>

/// the function to parse commandline arguments
VerilogVerificationTargetGenerator::vtg_config_t HandleArguments(int argc, char **argv);

/// To verify the exact AES128 ILA
void verifyAES128(Ila& model, VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg) {
  VerilogGeneratorBase::VlgGenConfig vlg_cfg;

  vlg_cfg.pass_node_name = true;

  std::string RootPath = "..";
  std::string VerilogPath = RootPath + "/verilog/";
  std::string RefrelPath = RootPath + "/refinement/";
  std::string OutputPath = RootPath + "/verification/";

  VerilogVerificationTargetGenerator vg(
      {},                                                    // no include
      {VerilogPath + "aes_abs.v", VerilogPath + "one_round.v",
       VerilogPath + "final_round.v", VerilogPath + "expand_key_128.v",
       VerilogPath + "S.v", VerilogPath + "S4.v", VerilogPath + "xS.v",
       VerilogPath + "table_lookup.v", VerilogPath + "T.v"}, // designs
      "aes_128",                                             // top_module_name
      RefrelPath + "ref-rel-var-map-aes128.json",            // variable mapping
      RefrelPath + "ref-rel-inst-cond-aes128.json",          // conditions of start/ready
      OutputPath,                                            // output path
      model.get(),                                           // model
      VerilogVerificationTargetGenerator::backend_selector::COSA, // backend: COSA
      vtg_cfg,  // target generator configuration
      vlg_cfg); // verilog generator configuration

  vg.GenerateTargets();
}

/// To verify the IO ILA
void verifyIO(Ila& model, VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg) {

  VerilogGeneratorBase::VlgGenConfig vlg_cfg;

  vtg_cfg.MemAbsReadAbstraction = true; // enable read abstraction
  vlg_cfg.pass_node_name = true;

  std::string RootPath = "..";
  std::string VerilogPath = RootPath + "/verilog/";
  std::string RefrelPath = RootPath + "/refinement/";
  std::string OutputPath = RootPath + "/verification/";

  VerilogVerificationTargetGenerator vg(
      {}, // no include
      {VerilogPath + "aes_top.v",   VerilogPath + "reg2byte.v",
       VerilogPath + "reg16byte.v", VerilogPath + "reg32byte.v",
       VerilogPath + "reg256byte.v",
       VerilogPath + "aes_128_abs.v"},                // designs
      "aes_top",                                      // top_module_name
      RefrelPath + "ref-rel-var-map.json",            // variable mapping
      RefrelPath + "ref-rel-inst-cond.json",          // conditions of start/ready
      OutputPath,                                     // output path
      model.get(),                                    // model
      VerilogVerificationTargetGenerator::backend_selector::COSA, // backend: COSA
      vtg_cfg,  // target generator configuration
      vlg_cfg); // verilog generator configuration

  vg.GenerateTargets();
}

/// To verify the block level operation of ILA
void verifyBlockLevel(Ila& model, VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg) {

  VerilogGeneratorBase::VlgGenConfig vlg_cfg;

  vtg_cfg.MemAbsReadAbstraction = true; // enable read abstraction
  vtg_cfg.MaxBound = 40;                // bound of BMC
  vlg_cfg.pass_node_name = true;	// whether to use node name in Verilog

  std::string RootPath = "..";
  std::string VerilogPath = RootPath + "/verilog/";
  std::string RefrelPath = RootPath + "/refinement/";
  std::string OutputPath = RootPath + "/verification/";

  VerilogVerificationTargetGenerator vg(
      {}, // no include
      {VerilogPath + "aes_top.v",   VerilogPath + "reg2byte.v",
       VerilogPath + "reg16byte.v", VerilogPath + "reg32byte.v",
       VerilogPath + "reg256byte.v",
       VerilogPath + "aes_128_abs.v"},                // designs
      "aes_top",                                      // top_module_name
      RefrelPath + "ref-rel-var-map-uaes.json",       // variable mapping
      RefrelPath + "ref-rel-inst-cond-uaes.json",     // conditions of start/ready
      OutputPath,                                     // output path
      model.child(0).get(),                           // model
      VerilogVerificationTargetGenerator::backend_selector::COSA, // backend: COSA
      vtg_cfg,  // target generator configuration
      vlg_cfg); // verilog generator configuration

  vg.GenerateTargets();
}

/// Build the model
int main(int argc, char **argv) {
  // extract the configurations
  auto vtg_cfg = HandleArguments(argc, argv);

  // build the aes model
  AES aes_ila_model;
  // build the aes128 model
  AES_128 aes128;
  // verify separately the hierarchical ILA
  // from IO level down to the AES 128 function
  verifyIO(aes_ila_model.model, vtg_cfg);
  verifyBlockLevel(aes_ila_model.model, vtg_cfg);
  verifyAES128(aes128.model, vtg_cfg);

  return 0;
}



VerilogVerificationTargetGenerator::vtg_config_t HandleArguments(int argc, char **argv) {
  // the solver, the cosa environment
  // you can use a commandline parser if desired, but since it is not the main focus of
  // this demo, we skip it

  // set ilang option, operators like '<' will refer to unsigned arithmetics
  SetUnsignedComparison(true); 
  
  VerilogVerificationTargetGenerator::vtg_config_t ret;

  for(unsigned p = 1; p<argc; p++) {
    std::string arg = argv[p];
    auto split = arg.find("=");
    auto argName = arg.substr(0,split);
    auto param   = arg.substr(split+1);

    if(argName == "Solver")
      ret.CosaSolver = param;
    else if(argName == "Env")
      ret.CosaPyEnvironment = param;
    else if(argName == "Cosa")
      ret.CosaPath = param;
    // else unknown
    else {
      std::cerr<<"Unknown argument:" << argName << std::endl;
      std::cerr<<"Expecting Solver/Env/Cosa=???" << std::endl;
    }
  }

  ret.CosaGenTraceVcd = true;

  return ret;
}