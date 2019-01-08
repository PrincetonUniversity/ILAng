#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <lmac.h>

VerilogVerificationTargetGenerator::vtg_config_t HandleArguments(int argc,
                                                                 char** argv);

void VerifyReadFmacTxPktCnt(
    Ila& m, VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg);

int main() {
  // get the config
  auto vtg_cfg = HandleArguments(argc, argv);

  // build the lmac ILA
  auto lmac_ila = GetLmacIla();

  // verify read config regs instructions
  VerifyReadFmacTxPktCnt(lmac_ila, vtg_cfg);

  return 0;
}

void VerifyReadFmacTxPktCnt(
    Ila& m, VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg) {

  // generate vlog
  auto vgen = VerilogGenerator();
  auto instr_ptr = Ila.instr("READ_FMAC_TX_PKT_CNT").get();
  vgen.ExportTopLevelInstr(instr_ptr);

  std::ofstream fout("ila_raed_fmac_tx_pkt_cnt.v");
  if (fout.is_open()) {
    vgen.DumpToFile(fout);
    fout.close();
  }

#if 0
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
#endif
}

