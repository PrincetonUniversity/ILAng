#include <ilang/util/log.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <lmac.h>

using namespace ilang;

void VerifyReadFmacTxPktCnt(
    Ila& m, VerilogVerificationTargetGenerator::vtg_config_t vtg_cfg) {

#if 0
  // generate vlog
  auto vgen = VerilogGenerator();
  auto instr_ptr = m.instr("READ_FMAC_TX_PKT_CNT_INSTR").get();
  ILA_DLOG("LMAC") << "export top level instr READ_FMAC_TX_PKT_CNT";
  vgen.ExportTopLevelInstr(instr_ptr);

  std::ofstream fout("ila_raed_fmac_tx_pkt_cnt.v");
  if (fout.is_open()) {
    ILA_DLOG("LMAC") << "dump vlog to file";
    vgen.DumpToFile(fout);
    fout.close();
  }
#endif

  ILA_DLOG("LMAC") << "Start generating verification targets";
  VerilogGeneratorBase::VlgGenConfig vlg_cfg;

  vlg_cfg.pass_node_name = true;

  std::string RootPath = "..";
  std::string VerilogPath = RootPath + "/verilog/";
  std::string RefrelPath = RootPath + "/refinement/";
  std::string OutputPath = RootPath + "/verification/";

  std::vector<std::string> impl_srcs = {"LMAC_CORE_TOP.v",
                                        "br_sfifo4x32.v",
                                        "bsh32_dn_88.v",
                                        "bsh8_dn_64.v",
                                        "byte_reordering.v",
                                        "crc32_d16s.v",
                                        "crc32_d24s.v",
                                        "crc32_d64.v",
                                        "crc32_d8s.v",
                                        "eth_crc32_gen.v",
                                        "fmac_fifo4Kx64.v",
                                        "fmac_fifo4Kx8.v",
                                        "fmac_fifo512x64_2clk.v",
                                        "fmac_register_if_LE2.v",
                                        "fmac_saddr_filter.v",
                                        "g2x_ctrl.v",
                                        "gige_crc32x64.v",
                                        "gige_rx.v",
                                        "gige_s2p.v",
                                        "gige_tx_encap.v",
                                        "gige_tx_gmii.v",
                                        "gigerx_bcnt_fifo256x16.v",
                                        "gigerx_fifo256x64_2clk.v",
                                        "gigerx_fifo256x8.v",
                                        "rx_xgmii_LE2.v",
                                        "tcore_fmac_core_LE2.v",
                                        "txfifo_1024x64.v"};

  for (auto i = 0; i < impl_srcs.size(); i++) {
    auto full_path = VerilogPath + impl_srcs.at(i);
    impl_srcs[i] = full_path;
  }

  VerilogVerificationTargetGenerator vg(
      {}, // no include
          // design
      impl_srcs,
      "LMAC_CORE_TOP",                       // top_module_name
      RefrelPath + "ref-rel-var-map.json",   // variable mapping
      RefrelPath + "ref-rel-inst-cond.json", // conditions of start/ready
      OutputPath,                            // output path
      m.get(),                               // ILA model
      VerilogVerificationTargetGenerator::backend_selector::COSA, // backend:
                                                                  // COSA
      vtg_cfg,  // target generator configuration
      vlg_cfg); // verilog generator configuration

  vg.GenerateTargets();
}

VerilogVerificationTargetGenerator::vtg_config_t HandleArguments(int argc,
                                                                 char** argv) {
  // set ilang option, operators like '<' will refer to unsigned arithmetics
  SetUnsignedComparation(true);

  VerilogVerificationTargetGenerator::vtg_config_t ret;

  for (unsigned p = 1; p < argc; p++) {
    std::string arg = argv[p];
    auto split = arg.find("=");
    auto argName = arg.substr(0, split);
    auto param = arg.substr(split + 1);

    if (argName == "Solver")
      ret.CosaSolver = param;
    else if (argName == "Env")
      ret.CosaPyEnvironment = param;
    else if (argName == "Cosa")
      ret.CosaPath = param;
    // else unknown
    else {
      std::cerr << "Unknown argument:" << argName << std::endl;
      std::cerr << "Expecting Solver/Env/Cosa=???" << std::endl;
    }
  }

  ret.CosaGenTraceVcd = true;

  return ret;
}

int main(int argc, char** argv) {
  SetToStdErr(1);
  DebugLog::Enable("LMAC");

  // get the config
  ILA_DLOG("LMAC") << "handle args";
  auto vtg_cfg = HandleArguments(argc, argv);

  // build the lmac ILA
  ILA_DLOG("LMAC") << "construct LMAC ILA";
  auto lmac_ila = GetLmacIla();

  // verify read config regs instructions
  ILA_DLOG("LMAC") << "verify READ_FMAC_TX_PKT_CNT";
  VerifyReadFmacTxPktCnt(lmac_ila, vtg_cfg);

  return 0;
}

