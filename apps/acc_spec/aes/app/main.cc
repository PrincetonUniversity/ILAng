#include <aes_128.h>
#include <aes_ila.h>
#include <ilang/vtarget-out/vtarget_gen.h>

void verifyAES128(Ila& model) {
  VerilogGeneratorBase::VlgGenConfig vlg_cfg;
  VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg;

  vlg_cfg.pass_node_name = true;

  std::string RootPath = "..";
  std::string VerilogPath = RootPath + "/verilog/";
  std::string RefrelPath = RootPath + "/refinement/";
  std::string OutputPath = RootPath + "/verification/";

  VerilogVerificationTargetGenerator vg(
      {}, // no include
      {VerilogPath + "aes_128.v", VerilogPath + "one_round.v",
       VerilogPath + "final_round.v", VerilogPath + "expand_key_128.v",
       VerilogPath + "S.v", VerilogPath + "S4.v", VerilogPath + "xS.v",
       VerilogPath + "table_lookup.v", VerilogPath + "T.v"}, // designs
      "aes_128",                                             // top_module_name
      RefrelPath + "ref-rel-var-map-aes128.json",            // variable mapping
      RefrelPath + "ref-rel-inst-cond-aes128.json", // conditions of start/ready
      OutputPath,                                   // output path
      model.get(),                                  // model
      VerilogVerificationTargetGenerator::backend_selector::COSA, // backend: COSA
      vtg_cfg,  // target generator configuration
      vlg_cfg); // verilog generator configuration

  vg.GenerateTargets();
}

int main() {
  AES aes_ila_model;

  AES_128 aes128;

  verifyAES128(aes128.model);

  return 0;
}