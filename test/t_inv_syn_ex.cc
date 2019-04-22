/// \file
/// Unit test for generating Verilog verification target

#include <ilang/util/fs.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ilang++.h>
#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/vtarget-out/inv-syn/inv_syn_cegar.h>
#include <ilang/vtarget-out/inv-syn/sygus/sim_trace_extract.h>

#include "unit-include/config.h"
#include "unit-include/pipe_ila.h"
#include "unit-include/memswap.h"
#include "unit-include/util.h"

namespace ilang {

TEST(TestInvSynEx, Pipe) {
  // datatype and flatten and generate a inv verify target
  
  // let's get a datatype and flatten
  
  auto ila_model = SimplePipe::BuildModel();

  VerilogVerificationTargetGenerator::vtg_config_t cfg;
  cfg.InvariantSynthesisReachableCheckKeepOldInvariant = false;
  cfg.CosaAddKeep = false;
  cfg.VerificationSettingAvoidIssueStage = true;
  cfg.YosysSmtFlattenDatatype = false; // if not using transfunc it does not matter
  cfg.YosysSmtFlattenHierarchy = true;
  cfg.CosaPyEnvironment = "/home/hongce/cosaEnv/bin/activate";
  cfg.CosaPath = "/home/hongce/CoSA/";
  cfg.Z3Path = "/home/hongce/z3s/bin/";
  cfg.Cvc4Path = "/home/hongce/cvc-installs/latest/bin/";
  cfg.CosaSolver = "btor";
  cfg.SygusOptions.SygusPassInfo = 
    VerilogVerificationTargetGenerator::vtg_config_t::_sygus_options_t::DataPoints;
  
  auto dirName = std::string(ILANG_TEST_SRC_ROOT) + "/unit-data/vpipe/";
  auto outDir  = std::string(ILANG_TEST_SRC_ROOT) + "/test-data-do-not-commit/pipe-bv/";
  
  InvariantSynthesizerCegar vg(
    {},                          // no include
    {dirName + "simple_pipe.v"}, //
    "pipeline_v",                // top_module_name
    dirName + "rfmap/vmap.json", // variable mapping
    dirName + "rfmap/cond-noinv.json", outDir, ila_model.get(),
    VerilogVerificationTargetGenerator::backend_selector::COSA,
    VerilogVerificationTargetGenerator::synthesis_backend_selector::CVC4,
    cfg);
    
    vg.SupplyCandidateInvariant("(! (m1.reg_0_w_stage == 2'b00 ) ) ||  ( ( (m1.id_ex_reg_wen == 0) || (m1.id_ex_rd != 2'd0) ) && ( (m1.ex_wb_reg_wen == 0) || (m1.ex_wb_rd != 2'd0) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_1_w_stage == 2'b00 ) ) ||  ( ( (m1.id_ex_reg_wen == 0) || (m1.id_ex_rd != 2'd1) ) && ( (m1.ex_wb_reg_wen == 0) || (m1.ex_wb_rd != 2'd1) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_2_w_stage == 2'b00 ) ) ||  ( ( (m1.id_ex_reg_wen == 0) || (m1.id_ex_rd != 2'd2) ) && ( (m1.ex_wb_reg_wen == 0) || (m1.ex_wb_rd != 2'd2) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_3_w_stage == 2'b00 ) ) ||  ( ( (m1.id_ex_reg_wen == 0) || (m1.id_ex_rd != 2'd3) ) && ( (m1.ex_wb_reg_wen == 0) || (m1.ex_wb_rd != 2'd3) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_0_w_stage == 2'b10 ) ) ||  ( ( (m1.id_ex_reg_wen == 1) && (m1.id_ex_rd == 2'd0) ) && ( (m1.ex_wb_reg_wen == 0) || (m1.ex_wb_rd != 2'd0) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_1_w_stage == 2'b10 ) ) ||  ( ( (m1.id_ex_reg_wen == 1) && (m1.id_ex_rd == 2'd1) ) && ( (m1.ex_wb_reg_wen == 0) || (m1.ex_wb_rd != 2'd1) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_2_w_stage == 2'b10 ) ) ||  ( ( (m1.id_ex_reg_wen == 1) && (m1.id_ex_rd == 2'd2) ) && ( (m1.ex_wb_reg_wen == 0) || (m1.ex_wb_rd != 2'd2) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_3_w_stage == 2'b10 ) ) ||  ( ( (m1.id_ex_reg_wen == 1) && (m1.id_ex_rd == 2'd3) ) && ( (m1.ex_wb_reg_wen == 0) || (m1.ex_wb_rd != 2'd3) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_0_w_stage == 2'b11 ) ) ||  ( ( (m1.id_ex_reg_wen == 1) && (m1.id_ex_rd == 2'd0) ) && ( (m1.ex_wb_reg_wen == 1) && (m1.ex_wb_rd == 2'd0) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_1_w_stage == 2'b11 ) ) ||  ( ( (m1.id_ex_reg_wen == 1) && (m1.id_ex_rd == 2'd1) ) && ( (m1.ex_wb_reg_wen == 1) && (m1.ex_wb_rd == 2'd1) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_2_w_stage == 2'b11 ) ) ||  ( ( (m1.id_ex_reg_wen == 1) && (m1.id_ex_rd == 2'd2) ) && ( (m1.ex_wb_reg_wen == 1) && (m1.ex_wb_rd == 2'd2) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_3_w_stage == 2'b11 ) ) ||  ( ( (m1.id_ex_reg_wen == 1) && (m1.id_ex_rd == 2'd3) ) && ( (m1.ex_wb_reg_wen == 1) && (m1.ex_wb_rd == 2'd3) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_0_w_stage == 2'b01 ) ) ||  ( ( (m1.id_ex_reg_wen == 0) || (m1.id_ex_rd != 2'd0) ) && ( (m1.ex_wb_reg_wen == 1) && (m1.ex_wb_rd == 2'd0) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_1_w_stage == 2'b01 ) ) ||  ( ( (m1.id_ex_reg_wen == 0) || (m1.id_ex_rd != 2'd1) ) && ( (m1.ex_wb_reg_wen == 1) && (m1.ex_wb_rd == 2'd1) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_2_w_stage == 2'b01 ) ) ||  ( ( (m1.id_ex_reg_wen == 0) || (m1.id_ex_rd != 2'd2) ) && ( (m1.ex_wb_reg_wen == 1) && (m1.ex_wb_rd == 2'd2) ) )");
    vg.SupplyCandidateInvariant("(! (m1.reg_3_w_stage == 2'b01 ) ) ||  ( ( (m1.id_ex_reg_wen == 0) || (m1.id_ex_rd != 2'd3) ) && ( (m1.ex_wb_reg_wen == 1) && (m1.ex_wb_rd == 2'd3) ) )");
    
    vg.ProofCandidateInvariants();
 }
 
 

}
