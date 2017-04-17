module Rocket(
  input   clock,
  input   reset,
  input   io_interrupts_debug,
  input   io_interrupts_mtip,
  input   io_interrupts_msip,
  input   io_interrupts_meip,
  input  [31:0] io_hartid,
  output  io_imem_req_valid,
  output [31:0] io_imem_req_bits_pc,
  output  io_imem_req_bits_speculative,
  output  io_imem_resp_ready,
  input   io_imem_resp_valid,
  input   io_imem_resp_bits_btb_valid,
  input   io_imem_resp_bits_btb_bits_taken,
  input  [1:0] io_imem_resp_bits_btb_bits_mask,
  input   io_imem_resp_bits_btb_bits_bridx,
  input  [31:0] io_imem_resp_bits_btb_bits_target,
  input   io_imem_resp_bits_btb_bits_entry,
  input   io_imem_resp_bits_btb_bits_bht_history,
  input  [1:0] io_imem_resp_bits_btb_bits_bht_value,
  input  [31:0] io_imem_resp_bits_pc,
  input  [31:0] io_imem_resp_bits_data,
  input  [1:0] io_imem_resp_bits_mask,
  input   io_imem_resp_bits_xcpt_if,
  input   io_imem_resp_bits_replay,
  output  io_imem_btb_update_valid,
  output  io_imem_btb_update_bits_prediction_valid,
  output  io_imem_btb_update_bits_prediction_bits_taken,
  output [1:0] io_imem_btb_update_bits_prediction_bits_mask,
  output  io_imem_btb_update_bits_prediction_bits_bridx,
  output [31:0] io_imem_btb_update_bits_prediction_bits_target,
  output  io_imem_btb_update_bits_prediction_bits_entry,
  output  io_imem_btb_update_bits_prediction_bits_bht_history,
  output [1:0] io_imem_btb_update_bits_prediction_bits_bht_value,
  output [31:0] io_imem_btb_update_bits_pc,
  output [31:0] io_imem_btb_update_bits_target,
  output  io_imem_btb_update_bits_taken,
  output  io_imem_btb_update_bits_isValid,
  output  io_imem_btb_update_bits_isJump,
  output  io_imem_btb_update_bits_isReturn,
  output [31:0] io_imem_btb_update_bits_br_pc,
  output  io_imem_bht_update_valid,
  output  io_imem_bht_update_bits_prediction_valid,
  output  io_imem_bht_update_bits_prediction_bits_taken,
  output [1:0] io_imem_bht_update_bits_prediction_bits_mask,
  output  io_imem_bht_update_bits_prediction_bits_bridx,
  output [31:0] io_imem_bht_update_bits_prediction_bits_target,
  output  io_imem_bht_update_bits_prediction_bits_entry,
  output  io_imem_bht_update_bits_prediction_bits_bht_history,
  output [1:0] io_imem_bht_update_bits_prediction_bits_bht_value,
  output [31:0] io_imem_bht_update_bits_pc,
  output  io_imem_bht_update_bits_taken,
  output  io_imem_bht_update_bits_mispredict,
  output  io_imem_ras_update_valid,
  output  io_imem_ras_update_bits_isCall,
  output  io_imem_ras_update_bits_isReturn,
  output [31:0] io_imem_ras_update_bits_returnAddr,
  output  io_imem_ras_update_bits_prediction_valid,
  output  io_imem_ras_update_bits_prediction_bits_taken,
  output [1:0] io_imem_ras_update_bits_prediction_bits_mask,
  output  io_imem_ras_update_bits_prediction_bits_bridx,
  output [31:0] io_imem_ras_update_bits_prediction_bits_target,
  output  io_imem_ras_update_bits_prediction_bits_entry,
  output  io_imem_ras_update_bits_prediction_bits_bht_history,
  output [1:0] io_imem_ras_update_bits_prediction_bits_bht_value,
  output  io_imem_flush_icache,
  output  io_imem_flush_tlb,
  input  [31:0] io_imem_npc,
  input   io_dmem_req_ready,
  output  io_dmem_req_valid,
  output [31:0] io_dmem_req_bits_addr,
  output [6:0] io_dmem_req_bits_tag,
  output [4:0] io_dmem_req_bits_cmd,
  output [2:0] io_dmem_req_bits_typ,
  output  io_dmem_req_bits_phys,
  output [31:0] io_dmem_req_bits_data,
  output  io_dmem_s1_kill,
  output [31:0] io_dmem_s1_data,
  input   io_dmem_s2_nack,
  input   io_dmem_resp_valid,
  input  [31:0] io_dmem_resp_bits_addr,
  input  [6:0] io_dmem_resp_bits_tag,
  input  [4:0] io_dmem_resp_bits_cmd,
  input  [2:0] io_dmem_resp_bits_typ,
  input  [31:0] io_dmem_resp_bits_data,
  input   io_dmem_resp_bits_replay,
  input   io_dmem_resp_bits_has_data,
  input  [31:0] io_dmem_resp_bits_data_word_bypass,
  input  [31:0] io_dmem_resp_bits_store_data,
  input   io_dmem_replay_next,
  input   io_dmem_xcpt_ma_ld,
  input   io_dmem_xcpt_ma_st,
  input   io_dmem_xcpt_pf_ld,
  input   io_dmem_xcpt_pf_st,
  output  io_dmem_invalidate_lr,
  input   io_dmem_ordered,
  output [6:0] io_ptw_ptbr_asid,
  output [21:0] io_ptw_ptbr_ppn,
  output  io_ptw_invalidate,
  output  io_ptw_status_debug,
  output [31:0] io_ptw_status_isa,
  output [1:0] io_ptw_status_prv,
  output  io_ptw_status_sd,
  output [30:0] io_ptw_status_zero3,
  output  io_ptw_status_sd_rv32,
  output [1:0] io_ptw_status_zero2,
  output [4:0] io_ptw_status_vm,
  output [3:0] io_ptw_status_zero1,
  output  io_ptw_status_mxr,
  output  io_ptw_status_pum,
  output  io_ptw_status_mprv,
  output [1:0] io_ptw_status_xs,
  output [1:0] io_ptw_status_fs,
  output [1:0] io_ptw_status_mpp,
  output [1:0] io_ptw_status_hpp,
  output  io_ptw_status_spp,
  output  io_ptw_status_mpie,
  output  io_ptw_status_hpie,
  output  io_ptw_status_spie,
  output  io_ptw_status_upie,
  output  io_ptw_status_mie,
  output  io_ptw_status_hie,
  output  io_ptw_status_sie,
  output  io_ptw_status_uie,
  output [31:0] io_fpu_inst,
  output [31:0] io_fpu_fromint_data,
  output [2:0] io_fpu_fcsr_rm,
  input   io_fpu_fcsr_flags_valid,
  input  [4:0] io_fpu_fcsr_flags_bits,
  input  [31:0] io_fpu_store_data,
  input  [31:0] io_fpu_toint_data,
  output  io_fpu_dmem_resp_val,
  output [2:0] io_fpu_dmem_resp_type,
  output [4:0] io_fpu_dmem_resp_tag,
  output [31:0] io_fpu_dmem_resp_data,
  output  io_fpu_valid,
  input   io_fpu_fcsr_rdy,
  input   io_fpu_nack_mem,
  input   io_fpu_illegal_rm,
  output  io_fpu_killx,
  output  io_fpu_killm,
  input  [4:0] io_fpu_dec_cmd,
  input   io_fpu_dec_ldst,
  input   io_fpu_dec_wen,
  input   io_fpu_dec_ren1,
  input   io_fpu_dec_ren2,
  input   io_fpu_dec_ren3,
  input   io_fpu_dec_swap12,
  input   io_fpu_dec_swap23,
  input   io_fpu_dec_single,
  input   io_fpu_dec_fromint,
  input   io_fpu_dec_toint,
  input   io_fpu_dec_fastpipe,
  input   io_fpu_dec_fma,
  input   io_fpu_dec_div,
  input   io_fpu_dec_sqrt,
  input   io_fpu_dec_round,
  input   io_fpu_dec_wflags,
  input   io_fpu_sboard_set,
  input   io_fpu_sboard_clr,
  input  [4:0] io_fpu_sboard_clra,
  input   io_fpu_cp_req_ready,
  output  io_fpu_cp_req_valid,
  output [4:0] io_fpu_cp_req_bits_cmd,
  output  io_fpu_cp_req_bits_ldst,
  output  io_fpu_cp_req_bits_wen,
  output  io_fpu_cp_req_bits_ren1,
  output  io_fpu_cp_req_bits_ren2,
  output  io_fpu_cp_req_bits_ren3,
  output  io_fpu_cp_req_bits_swap12,
  output  io_fpu_cp_req_bits_swap23,
  output  io_fpu_cp_req_bits_single,
  output  io_fpu_cp_req_bits_fromint,
  output  io_fpu_cp_req_bits_toint,
  output  io_fpu_cp_req_bits_fastpipe,
  output  io_fpu_cp_req_bits_fma,
  output  io_fpu_cp_req_bits_div,
  output  io_fpu_cp_req_bits_sqrt,
  output  io_fpu_cp_req_bits_round,
  output  io_fpu_cp_req_bits_wflags,
  output [2:0] io_fpu_cp_req_bits_rm,
  output [1:0] io_fpu_cp_req_bits_typ,
  output [32:0] io_fpu_cp_req_bits_in1,
  output [32:0] io_fpu_cp_req_bits_in2,
  output [32:0] io_fpu_cp_req_bits_in3,
  output  io_fpu_cp_resp_ready,
  input   io_fpu_cp_resp_valid,
  input  [32:0] io_fpu_cp_resp_bits_data,
  input  [4:0] io_fpu_cp_resp_bits_exc,
  input   io_rocc_cmd_ready,
  output  io_rocc_cmd_valid,
  output [6:0] io_rocc_cmd_bits_inst_funct,
  output [4:0] io_rocc_cmd_bits_inst_rs2,
  output [4:0] io_rocc_cmd_bits_inst_rs1,
  output  io_rocc_cmd_bits_inst_xd,
  output  io_rocc_cmd_bits_inst_xs1,
  output  io_rocc_cmd_bits_inst_xs2,
  output [4:0] io_rocc_cmd_bits_inst_rd,
  output [6:0] io_rocc_cmd_bits_inst_opcode,
  output [31:0] io_rocc_cmd_bits_rs1,
  output [31:0] io_rocc_cmd_bits_rs2,
  output  io_rocc_cmd_bits_status_debug,
  output [31:0] io_rocc_cmd_bits_status_isa,
  output [1:0] io_rocc_cmd_bits_status_prv,
  output  io_rocc_cmd_bits_status_sd,
  output [30:0] io_rocc_cmd_bits_status_zero3,
  output  io_rocc_cmd_bits_status_sd_rv32,
  output [1:0] io_rocc_cmd_bits_status_zero2,
  output [4:0] io_rocc_cmd_bits_status_vm,
  output [3:0] io_rocc_cmd_bits_status_zero1,
  output  io_rocc_cmd_bits_status_mxr,
  output  io_rocc_cmd_bits_status_pum,
  output  io_rocc_cmd_bits_status_mprv,
  output [1:0] io_rocc_cmd_bits_status_xs,
  output [1:0] io_rocc_cmd_bits_status_fs,
  output [1:0] io_rocc_cmd_bits_status_mpp,
  output [1:0] io_rocc_cmd_bits_status_hpp,
  output  io_rocc_cmd_bits_status_spp,
  output  io_rocc_cmd_bits_status_mpie,
  output  io_rocc_cmd_bits_status_hpie,
  output  io_rocc_cmd_bits_status_spie,
  output  io_rocc_cmd_bits_status_upie,
  output  io_rocc_cmd_bits_status_mie,
  output  io_rocc_cmd_bits_status_hie,
  output  io_rocc_cmd_bits_status_sie,
  output  io_rocc_cmd_bits_status_uie,
  output  io_rocc_resp_ready,
  input   io_rocc_resp_valid,
  input  [4:0] io_rocc_resp_bits_rd,
  input  [31:0] io_rocc_resp_bits_data,
  output  io_rocc_mem_req_ready,
  input   io_rocc_mem_req_valid,
  input  [31:0] io_rocc_mem_req_bits_addr,
  input  [6:0] io_rocc_mem_req_bits_tag,
  input  [4:0] io_rocc_mem_req_bits_cmd,
  input  [2:0] io_rocc_mem_req_bits_typ,
  input   io_rocc_mem_req_bits_phys,
  input  [31:0] io_rocc_mem_req_bits_data,
  input   io_rocc_mem_s1_kill,
  input  [31:0] io_rocc_mem_s1_data,
  output  io_rocc_mem_s2_nack,
  output  io_rocc_mem_resp_valid,
  output [31:0] io_rocc_mem_resp_bits_addr,
  output [6:0] io_rocc_mem_resp_bits_tag,
  output [4:0] io_rocc_mem_resp_bits_cmd,
  output [2:0] io_rocc_mem_resp_bits_typ,
  output [31:0] io_rocc_mem_resp_bits_data,
  output  io_rocc_mem_resp_bits_replay,
  output  io_rocc_mem_resp_bits_has_data,
  output [31:0] io_rocc_mem_resp_bits_data_word_bypass,
  output [31:0] io_rocc_mem_resp_bits_store_data,
  output  io_rocc_mem_replay_next,
  output  io_rocc_mem_xcpt_ma_ld,
  output  io_rocc_mem_xcpt_ma_st,
  output  io_rocc_mem_xcpt_pf_ld,
  output  io_rocc_mem_xcpt_pf_st,
  input   io_rocc_mem_invalidate_lr,
  output  io_rocc_mem_ordered,
  input   io_rocc_busy,
  input   io_rocc_interrupt,
  output  io_rocc_autl_acquire_ready,
  input   io_rocc_autl_acquire_valid,
  input  [25:0] io_rocc_autl_acquire_bits_addr_block,
  input   io_rocc_autl_acquire_bits_client_xact_id,
  input  [3:0] io_rocc_autl_acquire_bits_addr_beat,
  input   io_rocc_autl_acquire_bits_is_builtin_type,
  input  [2:0] io_rocc_autl_acquire_bits_a_type,
  input  [9:0] io_rocc_autl_acquire_bits_union,
  input  [31:0] io_rocc_autl_acquire_bits_data,
  input   io_rocc_autl_grant_ready,
  output  io_rocc_autl_grant_valid,
  output [3:0] io_rocc_autl_grant_bits_addr_beat,
  output  io_rocc_autl_grant_bits_client_xact_id,
  output [1:0] io_rocc_autl_grant_bits_manager_xact_id,
  output  io_rocc_autl_grant_bits_is_builtin_type,
  output [3:0] io_rocc_autl_grant_bits_g_type,
  output [31:0] io_rocc_autl_grant_bits_data,
  output  io_rocc_fpu_req_ready,
  input   io_rocc_fpu_req_valid,
  input  [4:0] io_rocc_fpu_req_bits_cmd,
  input   io_rocc_fpu_req_bits_ldst,
  input   io_rocc_fpu_req_bits_wen,
  input   io_rocc_fpu_req_bits_ren1,
  input   io_rocc_fpu_req_bits_ren2,
  input   io_rocc_fpu_req_bits_ren3,
  input   io_rocc_fpu_req_bits_swap12,
  input   io_rocc_fpu_req_bits_swap23,
  input   io_rocc_fpu_req_bits_single,
  input   io_rocc_fpu_req_bits_fromint,
  input   io_rocc_fpu_req_bits_toint,
  input   io_rocc_fpu_req_bits_fastpipe,
  input   io_rocc_fpu_req_bits_fma,
  input   io_rocc_fpu_req_bits_div,
  input   io_rocc_fpu_req_bits_sqrt,
  input   io_rocc_fpu_req_bits_round,
  input   io_rocc_fpu_req_bits_wflags,
  input  [2:0] io_rocc_fpu_req_bits_rm,
  input  [1:0] io_rocc_fpu_req_bits_typ,
  input  [32:0] io_rocc_fpu_req_bits_in1,
  input  [32:0] io_rocc_fpu_req_bits_in2,
  input  [32:0] io_rocc_fpu_req_bits_in3,
  input   io_rocc_fpu_resp_ready,
  output  io_rocc_fpu_resp_valid,
  output [32:0] io_rocc_fpu_resp_bits_data,
  output [4:0] io_rocc_fpu_resp_bits_exc,
  output  io_rocc_exception,

  // Ibuf inst
  output [31:0] ibuf_io_inst_0_bits_inst_bits_o,
  output        ibuf_io_inst_0_valid_o,
  output        ex_reg_valid_o,
  output        mem_reg_valid_o,
  output        wb_valid_o,
  output        wb_reg_valid_o,
  output [31:0] wb_reg_inst_o,
  output [31:0] ex_reg_inst_o,
  output [31:0] mem_reg_inst_o,

  // Monitor
  output        ctrl_killd_o,
  output        ctrl_killx_o,
  output        ctrl_killm_o,

  // Pc
  output [31:0] ibuf_io_pc_o,
  output [31:0] wb_reg_pc_o,
  output [31:0] first_valid_pc,
  output        no_first_valid_pc,

  // register index
  input  [4:0]  rf_idx_i,
  output [31:0] rf_idx_o,

  // idstage bypass network
  output [31:0] ex_rs_0_o,
  output [31:0] ex_rs_1_o,
  output        id_rs_0_in_use,
  output        id_rs_1_in_use,

  // Output states
  output [31:0] x0,
  output [31:0] x1,
  output [31:0] x10,
  output [31:0] x11,
  output [31:0] x12,
  output [31:0] x13,
  output [31:0] x14,
  output [31:0] x15,
  output [31:0] x16,
  output [31:0] x17,
  output [31:0] x18,
  output [31:0] x19,
  output [31:0] x2,
  output [31:0] x20,
  output [31:0] x21,
  output [31:0] x22,
  output [31:0] x23,
  output [31:0] x24,
  output [31:0] x25,
  output [31:0] x26,
  output [31:0] x27,
  output [31:0] x28,
  output [31:0] x29,
  output [31:0] x3,
  output [31:0] x30,
  output [31:0] x31,
  output [31:0] x4,
  output [31:0] x5,
  output [31:0] x6,
  output [31:0] x7,
  output [31:0] x8,
  output [31:0] x9
);
  reg  ex_ctrl_legal;
  reg [31:0] GEN_272;
  reg  ex_ctrl_fp;
  reg [31:0] GEN_273;
  reg  ex_ctrl_rocc;
  reg [31:0] GEN_274;
  reg  ex_ctrl_branch;
  reg [31:0] GEN_275;
  reg  ex_ctrl_jal;
  reg [31:0] GEN_276;
  reg  ex_ctrl_jalr;
  reg [31:0] GEN_277;
  reg  ex_ctrl_rxs2;
  reg [31:0] GEN_278;
  reg  ex_ctrl_rxs1;
  reg [31:0] GEN_279;
  reg [1:0] ex_ctrl_sel_alu2;
  reg [31:0] GEN_280;
  reg [1:0] ex_ctrl_sel_alu1;
  reg [31:0] GEN_281;
  reg [2:0] ex_ctrl_sel_imm;
  reg [31:0] GEN_282;
  reg  ex_ctrl_alu_dw;
  reg [31:0] GEN_283;
  reg [3:0] ex_ctrl_alu_fn;
  reg [31:0] GEN_284;
  reg  ex_ctrl_mem;
  reg [31:0] GEN_285;
  reg [4:0] ex_ctrl_mem_cmd;
  reg [31:0] GEN_286;
  reg [2:0] ex_ctrl_mem_type;
  reg [31:0] GEN_287;
  reg  ex_ctrl_rfs1;
  reg [31:0] GEN_288;
  reg  ex_ctrl_rfs2;
  reg [31:0] GEN_289;
  reg  ex_ctrl_rfs3;
  reg [31:0] GEN_290;
  reg  ex_ctrl_wfd;
  reg [31:0] GEN_291;
  reg  ex_ctrl_div;
  reg [31:0] GEN_292;
  reg  ex_ctrl_wxd;
  reg [31:0] GEN_293;
  reg [2:0] ex_ctrl_csr;
  reg [31:0] GEN_294;
  reg  ex_ctrl_fence_i;
  reg [31:0] GEN_295;
  reg  ex_ctrl_fence;
  reg [31:0] GEN_296;
  reg  ex_ctrl_amo;
  reg [31:0] GEN_297;
  reg  ex_ctrl_dp;
  reg [31:0] GEN_298;
  reg  mem_ctrl_legal;
  reg [31:0] GEN_299;
  reg  mem_ctrl_fp;
  reg [31:0] GEN_300;
  reg  mem_ctrl_rocc;
  reg [31:0] GEN_301;
  reg  mem_ctrl_branch;
  reg [31:0] GEN_302;
  reg  mem_ctrl_jal;
  reg [31:0] GEN_303;
  reg  mem_ctrl_jalr;
  reg [31:0] GEN_304;
  reg  mem_ctrl_rxs2;
  reg [31:0] GEN_305;
  reg  mem_ctrl_rxs1;
  reg [31:0] GEN_306;
  reg [1:0] mem_ctrl_sel_alu2;
  reg [31:0] GEN_307;
  reg [1:0] mem_ctrl_sel_alu1;
  reg [31:0] GEN_308;
  reg [2:0] mem_ctrl_sel_imm;
  reg [31:0] GEN_309;
  reg  mem_ctrl_alu_dw;
  reg [31:0] GEN_310;
  reg [3:0] mem_ctrl_alu_fn;
  reg [31:0] GEN_311;
  reg  mem_ctrl_mem;
  reg [31:0] GEN_312;
  reg [4:0] mem_ctrl_mem_cmd;
  reg [31:0] GEN_313;
  reg [2:0] mem_ctrl_mem_type;
  reg [31:0] GEN_314;
  reg  mem_ctrl_rfs1;
  reg [31:0] GEN_315;
  reg  mem_ctrl_rfs2;
  reg [31:0] GEN_316;
  reg  mem_ctrl_rfs3;
  reg [31:0] GEN_317;
  reg  mem_ctrl_wfd;
  reg [31:0] GEN_318;
  reg  mem_ctrl_div;
  reg [31:0] GEN_319;
  reg  mem_ctrl_wxd;
  reg [31:0] GEN_320;
  reg [2:0] mem_ctrl_csr;
  reg [31:0] GEN_321;
  reg  mem_ctrl_fence_i;
  reg [31:0] GEN_322;
  reg  mem_ctrl_fence;
  reg [31:0] GEN_323;
  reg  mem_ctrl_amo;
  reg [31:0] GEN_324;
  reg  mem_ctrl_dp;
  reg [31:0] GEN_325;
  reg  wb_ctrl_legal;
  reg [31:0] GEN_326;
  reg  wb_ctrl_fp;
  reg [31:0] GEN_327;
  reg  wb_ctrl_rocc;
  reg [31:0] GEN_328;
  reg  wb_ctrl_branch;
  reg [31:0] GEN_329;
  reg  wb_ctrl_jal;
  reg [31:0] GEN_330;
  reg  wb_ctrl_jalr;
  reg [31:0] GEN_331;
  reg  wb_ctrl_rxs2;
  reg [31:0] GEN_332;
  reg  wb_ctrl_rxs1;
  reg [31:0] GEN_333;
  reg [1:0] wb_ctrl_sel_alu2;
  reg [31:0] GEN_334;
  reg [1:0] wb_ctrl_sel_alu1;
  reg [31:0] GEN_335;
  reg [2:0] wb_ctrl_sel_imm;
  reg [31:0] GEN_336;
  reg  wb_ctrl_alu_dw;
  reg [31:0] GEN_337;
  reg [3:0] wb_ctrl_alu_fn;
  reg [31:0] GEN_338;
  reg  wb_ctrl_mem;
  reg [31:0] GEN_339;
  reg [4:0] wb_ctrl_mem_cmd;
  reg [31:0] GEN_340;
  reg [2:0] wb_ctrl_mem_type;
  reg [31:0] GEN_341;
  reg  wb_ctrl_rfs1;
  reg [31:0] GEN_342;
  reg  wb_ctrl_rfs2;
  reg [31:0] GEN_343;
  reg  wb_ctrl_rfs3;
  reg [31:0] GEN_344;
  reg  wb_ctrl_wfd;
  reg [31:0] GEN_345;
  reg  wb_ctrl_div;
  reg [31:0] GEN_346;
  reg  wb_ctrl_wxd;
  reg [31:0] GEN_347;
  reg [2:0] wb_ctrl_csr;
  reg [31:0] GEN_348;
  reg  wb_ctrl_fence_i;
  reg [31:0] GEN_349;
  reg  wb_ctrl_fence;
  reg [31:0] GEN_350;
  reg  wb_ctrl_amo;
  reg [31:0] GEN_351;
  reg  wb_ctrl_dp;
  reg [31:0] GEN_352;
  reg  ex_reg_xcpt_interrupt;
  reg [31:0] GEN_353;
  reg  ex_reg_valid;
  reg [31:0] GEN_354;
  reg  ex_reg_rvc;
  reg [31:0] GEN_355;
  reg  ex_reg_btb_hit;
  reg [31:0] GEN_356;
  reg  ex_reg_btb_resp_taken;
  reg [31:0] GEN_357;
  reg [1:0] ex_reg_btb_resp_mask;
  reg [31:0] GEN_358;
  reg  ex_reg_btb_resp_bridx;
  reg [31:0] GEN_359;
  reg [31:0] ex_reg_btb_resp_target;
  reg [31:0] GEN_360;
  reg  ex_reg_btb_resp_entry;
  reg [31:0] GEN_361;
  reg  ex_reg_btb_resp_bht_history;
  reg [31:0] GEN_362;
  reg [1:0] ex_reg_btb_resp_bht_value;
  reg [31:0] GEN_363;
  reg  ex_reg_xcpt;
  reg [31:0] GEN_364;
  reg  ex_reg_flush_pipe;
  reg [31:0] GEN_365;
  reg  ex_reg_load_use;
  reg [31:0] GEN_366;
  reg [31:0] ex_reg_cause;
  reg [31:0] GEN_367;
  reg  ex_reg_replay;
  reg [31:0] GEN_368;
  reg [31:0] ex_reg_pc;
  reg [31:0] GEN_369;
  reg [31:0] ex_reg_inst;
  reg [31:0] GEN_370;
  reg  mem_reg_xcpt_interrupt;
  reg [31:0] GEN_371;
  reg  mem_reg_valid;
  reg [31:0] GEN_372;
  reg  mem_reg_rvc;
  reg [31:0] GEN_373;
  reg  mem_reg_btb_hit;
  reg [31:0] GEN_374;
  reg  mem_reg_btb_resp_taken;
  reg [31:0] GEN_375;
  reg [1:0] mem_reg_btb_resp_mask;
  reg [31:0] GEN_376;
  reg  mem_reg_btb_resp_bridx;
  reg [31:0] GEN_377;
  reg [31:0] mem_reg_btb_resp_target;
  reg [31:0] GEN_378;
  reg  mem_reg_btb_resp_entry;
  reg [31:0] GEN_379;
  reg  mem_reg_btb_resp_bht_history;
  reg [31:0] GEN_380;
  reg [1:0] mem_reg_btb_resp_bht_value;
  reg [31:0] GEN_381;
  reg  mem_reg_xcpt;
  reg [31:0] GEN_382;
  reg  mem_reg_replay;
  reg [31:0] GEN_383;
  reg  mem_reg_flush_pipe;
  reg [31:0] GEN_384;
  reg [31:0] mem_reg_cause;
  reg [31:0] GEN_385;
  reg  mem_reg_slow_bypass;
  reg [31:0] GEN_386;
  reg  mem_reg_load;
  reg [31:0] GEN_387;
  reg  mem_reg_store;
  reg [31:0] GEN_388;
  reg [31:0] mem_reg_pc;
  reg [31:0] GEN_389;
  reg [31:0] mem_reg_inst;
  reg [31:0] GEN_390;
  reg [31:0] mem_reg_wdata;
  reg [31:0] GEN_391;
  reg [31:0] mem_reg_rs2;
  reg [31:0] GEN_392;
  wire  take_pc_mem;
  reg  wb_reg_valid;
  reg [31:0] GEN_393;
  reg  wb_reg_xcpt;
  reg [31:0] GEN_394;
  reg  wb_reg_replay;
  reg [31:0] GEN_395;
  reg [31:0] wb_reg_cause;
  reg [31:0] GEN_396;
  reg [31:0] wb_reg_pc;
  reg [31:0] GEN_397;
  reg [31:0] wb_reg_inst;
  reg [31:0] GEN_398;
  reg [31:0] wb_reg_wdata;
  reg [31:0] GEN_399;
  reg [31:0] wb_reg_rs2;
  reg [31:0] GEN_400;
  wire  take_pc_wb;
  wire  take_pc_id;
  wire  take_pc_mem_wb;
  wire  take_pc;
  wire  ibuf_clock;
  wire  ibuf_reset;
  wire  ibuf_io_imem_ready;
  wire  ibuf_io_imem_valid;
  wire  ibuf_io_imem_bits_btb_valid;
  wire  ibuf_io_imem_bits_btb_bits_taken;
  wire [1:0] ibuf_io_imem_bits_btb_bits_mask;
  wire  ibuf_io_imem_bits_btb_bits_bridx;
  wire [31:0] ibuf_io_imem_bits_btb_bits_target;
  wire  ibuf_io_imem_bits_btb_bits_entry;
  wire  ibuf_io_imem_bits_btb_bits_bht_history;
  wire [1:0] ibuf_io_imem_bits_btb_bits_bht_value;
  wire [31:0] ibuf_io_imem_bits_pc;
  wire [31:0] ibuf_io_imem_bits_data;
  wire [1:0] ibuf_io_imem_bits_mask;
  wire  ibuf_io_imem_bits_xcpt_if;
  wire  ibuf_io_imem_bits_replay;
  wire  ibuf_io_kill;
  wire [31:0] ibuf_io_pc;
  wire  ibuf_io_btb_resp_taken;
  wire [1:0] ibuf_io_btb_resp_mask;
  wire  ibuf_io_btb_resp_bridx;
  wire [31:0] ibuf_io_btb_resp_target;
  wire  ibuf_io_btb_resp_entry;
  wire  ibuf_io_btb_resp_bht_history;
  wire [1:0] ibuf_io_btb_resp_bht_value;
  wire  ibuf_io_inst_0_ready;
  wire  ibuf_io_inst_0_valid;
  wire  ibuf_io_inst_0_bits_pf0;
  wire  ibuf_io_inst_0_bits_pf1;
  wire  ibuf_io_inst_0_bits_replay;
  wire  ibuf_io_inst_0_bits_btb_hit;
  wire  ibuf_io_inst_0_bits_rvc;
  wire [31:0] ibuf_io_inst_0_bits_inst_bits;
  wire [4:0] ibuf_io_inst_0_bits_inst_rd;
  wire [4:0] ibuf_io_inst_0_bits_inst_rs1;
  wire [4:0] ibuf_io_inst_0_bits_inst_rs2;
  wire [4:0] ibuf_io_inst_0_bits_inst_rs3;
  wire  id_ctrl_legal;
  wire  id_ctrl_fp;
  wire  id_ctrl_rocc;
  wire  id_ctrl_branch;
  wire  id_ctrl_jal;
  wire  id_ctrl_jalr;
  wire  id_ctrl_rxs2;
  wire  id_ctrl_rxs1;
  wire [1:0] id_ctrl_sel_alu2;
  wire [1:0] id_ctrl_sel_alu1;
  wire [2:0] id_ctrl_sel_imm;
  wire  id_ctrl_alu_dw;
  wire [3:0] id_ctrl_alu_fn;
  wire  id_ctrl_mem;
  wire [4:0] id_ctrl_mem_cmd;
  wire [2:0] id_ctrl_mem_type;
  wire  id_ctrl_rfs1;
  wire  id_ctrl_rfs2;
  wire  id_ctrl_rfs3;
  wire  id_ctrl_wfd;
  wire  id_ctrl_div;
  wire  id_ctrl_wxd;
  wire [2:0] id_ctrl_csr;
  wire  id_ctrl_fence_i;
  wire  id_ctrl_fence;
  wire  id_ctrl_amo;
  wire  id_ctrl_dp;
  wire [31:0] T_6023;
  wire  T_6025;
  wire [31:0] T_6027;
  wire  T_6029;
  wire [31:0] T_6031;
  wire  T_6033;
  wire [31:0] T_6035;
  wire  T_6037;
  wire [31:0] T_6039;
  wire  T_6041;
  wire [31:0] T_6043;
  wire  T_6045;
  wire [31:0] T_6047;
  wire  T_6049;
  wire [31:0] T_6051;
  wire  T_6053;
  wire [31:0] T_6055;
  wire  T_6057;
  wire [31:0] T_6059;
  wire  T_6061;
  wire  T_6065;
  wire [31:0] T_6067;
  wire  T_6069;
  wire  T_6073;
  wire [31:0] T_6075;
  wire  T_6077;
  wire  T_6081;
  wire [31:0] T_6083;
  wire  T_6085;
  wire [31:0] T_6087;
  wire  T_6089;
  wire  T_6091;
  wire  T_6093;
  wire  T_6095;
  wire [31:0] T_6097;
  wire  T_6099;
  wire [31:0] T_6101;
  wire  T_6103;
  wire [31:0] T_6105;
  wire  T_6107;
  wire  T_6111;
  wire  T_6114;
  wire  T_6115;
  wire  T_6116;
  wire  T_6117;
  wire  T_6118;
  wire  T_6119;
  wire  T_6120;
  wire  T_6121;
  wire  T_6122;
  wire  T_6123;
  wire  T_6124;
  wire  T_6125;
  wire  T_6126;
  wire  T_6127;
  wire  T_6128;
  wire  T_6129;
  wire  T_6130;
  wire  T_6131;
  wire  T_6132;
  wire  T_6133;
  wire  T_6134;
  wire  T_6135;
  wire  T_6136;
  wire [31:0] T_6140;
  wire  T_6142;
  wire [31:0] T_6146;
  wire  T_6148;
  wire [31:0] T_6152;
  wire  T_6154;
  wire [31:0] T_6158;
  wire  T_6160;
  wire [31:0] T_6162;
  wire  T_6164;
  wire [31:0] T_6166;
  wire  T_6168;
  wire  T_6171;
  wire  T_6172;
  wire [31:0] T_6174;
  wire  T_6176;
  wire [31:0] T_6178;
  wire  T_6180;
  wire [31:0] T_6182;
  wire  T_6184;
  wire [31:0] T_6186;
  wire  T_6188;
  wire  T_6191;
  wire  T_6192;
  wire  T_6193;
  wire [31:0] T_6195;
  wire  T_6197;
  wire [31:0] T_6199;
  wire  T_6201;
  wire [31:0] T_6203;
  wire  T_6205;
  wire [31:0] T_6207;
  wire  T_6209;
  wire  T_6212;
  wire  T_6213;
  wire  T_6214;
  wire  T_6215;
  wire  T_6219;
  wire [31:0] T_6221;
  wire  T_6223;
  wire  T_6226;
  wire  T_6227;
  wire [1:0] T_6228;
  wire [31:0] T_6230;
  wire  T_6232;
  wire  T_6235;
  wire  T_6236;
  wire  T_6237;
  wire [31:0] T_6239;
  wire  T_6241;
  wire  T_6244;
  wire [1:0] T_6245;
  wire [31:0] T_6247;
  wire  T_6249;
  wire  T_6253;
  wire  T_6256;
  wire  T_6260;
  wire  T_6263;
  wire  T_6267;
  wire [31:0] T_6269;
  wire  T_6271;
  wire  T_6274;
  wire  T_6275;
  wire [1:0] T_6276;
  wire [2:0] T_6277;
  wire [31:0] T_6285;
  wire  T_6287;
  wire [31:0] T_6289;
  wire  T_6291;
  wire [31:0] T_6293;
  wire  T_6295;
  wire  T_6298;
  wire  T_6299;
  wire [31:0] T_6301;
  wire  T_6303;
  wire [31:0] T_6305;
  wire  T_6307;
  wire [31:0] T_6309;
  wire  T_6311;
  wire [31:0] T_6313;
  wire  T_6315;
  wire [31:0] T_6317;
  wire  T_6319;
  wire [31:0] T_6321;
  wire  T_6323;
  wire  T_6326;
  wire  T_6327;
  wire  T_6328;
  wire  T_6329;
  wire  T_6330;
  wire [31:0] T_6332;
  wire  T_6334;
  wire [31:0] T_6336;
  wire  T_6338;
  wire [31:0] T_6340;
  wire  T_6342;
  wire [31:0] T_6344;
  wire  T_6346;
  wire  T_6349;
  wire  T_6350;
  wire  T_6351;
  wire [31:0] T_6353;
  wire  T_6355;
  wire [31:0] T_6357;
  wire  T_6359;
  wire  T_6362;
  wire  T_6363;
  wire  T_6364;
  wire [1:0] T_6365;
  wire [1:0] T_6366;
  wire [3:0] T_6367;
  wire [31:0] T_6369;
  wire  T_6371;
  wire [31:0] T_6373;
  wire  T_6375;
  wire  T_6378;
  wire  T_6379;
  wire  T_6380;
  wire  T_6381;
  wire  T_6382;
  wire  T_6383;
  wire [31:0] T_6385;
  wire  T_6387;
  wire [31:0] T_6389;
  wire  T_6391;
  wire [31:0] T_6393;
  wire  T_6395;
  wire [31:0] T_6397;
  wire  T_6399;
  wire  T_6402;
  wire  T_6403;
  wire  T_6404;
  wire [31:0] T_6406;
  wire  T_6408;
  wire [31:0] T_6410;
  wire  T_6412;
  wire  T_6415;
  wire [31:0] T_6417;
  wire  T_6419;
  wire [31:0] T_6421;
  wire  T_6423;
  wire [31:0] T_6425;
  wire  T_6427;
  wire  T_6430;
  wire  T_6431;
  wire  T_6432;
  wire [31:0] T_6434;
  wire  T_6436;
  wire [1:0] T_6440;
  wire [1:0] T_6441;
  wire [2:0] T_6442;
  wire [4:0] T_6443;
  wire [31:0] T_6445;
  wire  T_6447;
  wire [31:0] T_6451;
  wire  T_6453;
  wire [31:0] T_6457;
  wire  T_6459;
  wire [1:0] T_6462;
  wire [2:0] T_6463;
  wire [31:0] T_6469;
  wire  T_6471;
  wire  T_6477;
  wire  T_6481;
  wire [31:0] T_6483;
  wire  T_6485;
  wire  T_6489;
  wire [31:0] T_6491;
  wire  T_6493;
  wire  T_6496;
  wire  T_6497;
  wire  T_6498;
  wire  T_6499;
  wire  T_6500;
  wire  T_6501;
  wire [31:0] T_6503;
  wire  T_6505;
  wire  T_6511;
  wire [31:0] T_6515;
  wire  T_6517;
  wire [1:0] T_6520;
  wire [2:0] T_6521;
  wire [31:0] T_6523;
  wire  T_6525;
  wire [31:0] T_6529;
  wire  T_6531;
  wire [31:0] T_6535;
  wire  T_6537;
  wire  id_load_use;
  reg  id_reg_fence;
  reg [31:0] GEN_401;
  reg [31:0] T_6545 [0:30];
  reg [31:0] GEN_402;
  wire [31:0] T_6545_T_6554_data;
  wire [4:0] T_6545_T_6554_addr;
  reg [31:0] GEN_403;
  wire [31:0] T_6545_T_6564_data;
  wire [4:0] T_6545_T_6564_addr;
  reg [31:0] GEN_404;
  wire [31:0] T_6545_T_7395_data;
  wire [4:0] T_6545_T_7395_addr;
  wire  T_6545_T_7395_mask;
  wire  T_6545_T_7395_en;
  wire [31:0] id_rs_0;
  wire  T_6549;
  wire [4:0] T_6552;
  wire [4:0] T_6553;
  wire [31:0] T_6555;
  wire [31:0] id_rs_1;
  wire [4:0] T_6562;
  wire [4:0] T_6563;
  wire [31:0] T_6565;
  wire  ctrl_killd;
  wire  T_6643;
  wire  csr_clock;
  wire  csr_reset;
  wire  csr_io_interrupts_debug;
  wire  csr_io_interrupts_mtip;
  wire  csr_io_interrupts_msip;
  wire  csr_io_interrupts_meip;
  wire [31:0] csr_io_hartid;
  wire [11:0] csr_io_rw_addr;
  wire [2:0] csr_io_rw_cmd;
  wire [31:0] csr_io_rw_rdata;
  wire [31:0] csr_io_rw_wdata;
  wire  csr_io_csr_stall;
  wire  csr_io_csr_xcpt;
  wire  csr_io_eret;
  wire  csr_io_singleStep;
  wire  csr_io_status_debug;
  wire [31:0] csr_io_status_isa;
  wire [1:0] csr_io_status_prv;
  wire  csr_io_status_sd;
  wire [30:0] csr_io_status_zero3;
  wire  csr_io_status_sd_rv32;
  wire [1:0] csr_io_status_zero2;
  wire [4:0] csr_io_status_vm;
  wire [3:0] csr_io_status_zero1;
  wire  csr_io_status_mxr;
  wire  csr_io_status_pum;
  wire  csr_io_status_mprv;
  wire [1:0] csr_io_status_xs;
  wire [1:0] csr_io_status_fs;
  wire [1:0] csr_io_status_mpp;
  wire [1:0] csr_io_status_hpp;
  wire  csr_io_status_spp;
  wire  csr_io_status_mpie;
  wire  csr_io_status_hpie;
  wire  csr_io_status_spie;
  wire  csr_io_status_upie;
  wire  csr_io_status_mie;
  wire  csr_io_status_hie;
  wire  csr_io_status_sie;
  wire  csr_io_status_uie;
  wire [6:0] csr_io_ptbr_asid;
  wire [21:0] csr_io_ptbr_ppn;
  wire [31:0] csr_io_evec;
  wire  csr_io_exception;
  wire  csr_io_retire;
  wire [31:0] csr_io_cause;
  wire [31:0] csr_io_pc;
  wire [31:0] csr_io_badaddr;
  wire  csr_io_fatc;
  wire [31:0] csr_io_time;
  wire [2:0] csr_io_fcsr_rm;
  wire  csr_io_fcsr_flags_valid;
  wire [4:0] csr_io_fcsr_flags_bits;
  wire  csr_io_rocc_cmd_ready;
  wire  csr_io_rocc_cmd_valid;
  wire [6:0] csr_io_rocc_cmd_bits_inst_funct;
  wire [4:0] csr_io_rocc_cmd_bits_inst_rs2;
  wire [4:0] csr_io_rocc_cmd_bits_inst_rs1;
  wire  csr_io_rocc_cmd_bits_inst_xd;
  wire  csr_io_rocc_cmd_bits_inst_xs1;
  wire  csr_io_rocc_cmd_bits_inst_xs2;
  wire [4:0] csr_io_rocc_cmd_bits_inst_rd;
  wire [6:0] csr_io_rocc_cmd_bits_inst_opcode;
  wire [31:0] csr_io_rocc_cmd_bits_rs1;
  wire [31:0] csr_io_rocc_cmd_bits_rs2;
  wire  csr_io_rocc_cmd_bits_status_debug;
  wire [31:0] csr_io_rocc_cmd_bits_status_isa;
  wire [1:0] csr_io_rocc_cmd_bits_status_prv;
  wire  csr_io_rocc_cmd_bits_status_sd;
  wire [30:0] csr_io_rocc_cmd_bits_status_zero3;
  wire  csr_io_rocc_cmd_bits_status_sd_rv32;
  wire [1:0] csr_io_rocc_cmd_bits_status_zero2;
  wire [4:0] csr_io_rocc_cmd_bits_status_vm;
  wire [3:0] csr_io_rocc_cmd_bits_status_zero1;
  wire  csr_io_rocc_cmd_bits_status_mxr;
  wire  csr_io_rocc_cmd_bits_status_pum;
  wire  csr_io_rocc_cmd_bits_status_mprv;
  wire [1:0] csr_io_rocc_cmd_bits_status_xs;
  wire [1:0] csr_io_rocc_cmd_bits_status_fs;
  wire [1:0] csr_io_rocc_cmd_bits_status_mpp;
  wire [1:0] csr_io_rocc_cmd_bits_status_hpp;
  wire  csr_io_rocc_cmd_bits_status_spp;
  wire  csr_io_rocc_cmd_bits_status_mpie;
  wire  csr_io_rocc_cmd_bits_status_hpie;
  wire  csr_io_rocc_cmd_bits_status_spie;
  wire  csr_io_rocc_cmd_bits_status_upie;
  wire  csr_io_rocc_cmd_bits_status_mie;
  wire  csr_io_rocc_cmd_bits_status_hie;
  wire  csr_io_rocc_cmd_bits_status_sie;
  wire  csr_io_rocc_cmd_bits_status_uie;
  wire  csr_io_rocc_resp_ready;
  wire  csr_io_rocc_resp_valid;
  wire [4:0] csr_io_rocc_resp_bits_rd;
  wire [31:0] csr_io_rocc_resp_bits_data;
  wire  csr_io_rocc_mem_req_ready;
  wire  csr_io_rocc_mem_req_valid;
  wire [31:0] csr_io_rocc_mem_req_bits_addr;
  wire [6:0] csr_io_rocc_mem_req_bits_tag;
  wire [4:0] csr_io_rocc_mem_req_bits_cmd;
  wire [2:0] csr_io_rocc_mem_req_bits_typ;
  wire  csr_io_rocc_mem_req_bits_phys;
  wire [31:0] csr_io_rocc_mem_req_bits_data;
  wire  csr_io_rocc_mem_s1_kill;
  wire [31:0] csr_io_rocc_mem_s1_data;
  wire  csr_io_rocc_mem_s2_nack;
  wire  csr_io_rocc_mem_resp_valid;
  wire [31:0] csr_io_rocc_mem_resp_bits_addr;
  wire [6:0] csr_io_rocc_mem_resp_bits_tag;
  wire [4:0] csr_io_rocc_mem_resp_bits_cmd;
  wire [2:0] csr_io_rocc_mem_resp_bits_typ;
  wire [31:0] csr_io_rocc_mem_resp_bits_data;
  wire  csr_io_rocc_mem_resp_bits_replay;
  wire  csr_io_rocc_mem_resp_bits_has_data;
  wire [31:0] csr_io_rocc_mem_resp_bits_data_word_bypass;
  wire [31:0] csr_io_rocc_mem_resp_bits_store_data;
  wire  csr_io_rocc_mem_replay_next;
  wire  csr_io_rocc_mem_xcpt_ma_ld;
  wire  csr_io_rocc_mem_xcpt_ma_st;
  wire  csr_io_rocc_mem_xcpt_pf_ld;
  wire  csr_io_rocc_mem_xcpt_pf_st;
  wire  csr_io_rocc_mem_invalidate_lr;
  wire  csr_io_rocc_mem_ordered;
  wire  csr_io_rocc_busy;
  wire  csr_io_rocc_interrupt;
  wire  csr_io_rocc_autl_acquire_ready;
  wire  csr_io_rocc_autl_acquire_valid;
  wire [25:0] csr_io_rocc_autl_acquire_bits_addr_block;
  wire  csr_io_rocc_autl_acquire_bits_client_xact_id;
  wire [3:0] csr_io_rocc_autl_acquire_bits_addr_beat;
  wire  csr_io_rocc_autl_acquire_bits_is_builtin_type;
  wire [2:0] csr_io_rocc_autl_acquire_bits_a_type;
  wire [9:0] csr_io_rocc_autl_acquire_bits_union;
  wire [31:0] csr_io_rocc_autl_acquire_bits_data;
  wire  csr_io_rocc_autl_grant_ready;
  wire  csr_io_rocc_autl_grant_valid;
  wire [3:0] csr_io_rocc_autl_grant_bits_addr_beat;
  wire  csr_io_rocc_autl_grant_bits_client_xact_id;
  wire [1:0] csr_io_rocc_autl_grant_bits_manager_xact_id;
  wire  csr_io_rocc_autl_grant_bits_is_builtin_type;
  wire [3:0] csr_io_rocc_autl_grant_bits_g_type;
  wire [31:0] csr_io_rocc_autl_grant_bits_data;
  wire  csr_io_rocc_fpu_req_ready;
  wire  csr_io_rocc_fpu_req_valid;
  wire [4:0] csr_io_rocc_fpu_req_bits_cmd;
  wire  csr_io_rocc_fpu_req_bits_ldst;
  wire  csr_io_rocc_fpu_req_bits_wen;
  wire  csr_io_rocc_fpu_req_bits_ren1;
  wire  csr_io_rocc_fpu_req_bits_ren2;
  wire  csr_io_rocc_fpu_req_bits_ren3;
  wire  csr_io_rocc_fpu_req_bits_swap12;
  wire  csr_io_rocc_fpu_req_bits_swap23;
  wire  csr_io_rocc_fpu_req_bits_single;
  wire  csr_io_rocc_fpu_req_bits_fromint;
  wire  csr_io_rocc_fpu_req_bits_toint;
  wire  csr_io_rocc_fpu_req_bits_fastpipe;
  wire  csr_io_rocc_fpu_req_bits_fma;
  wire  csr_io_rocc_fpu_req_bits_div;
  wire  csr_io_rocc_fpu_req_bits_sqrt;
  wire  csr_io_rocc_fpu_req_bits_round;
  wire  csr_io_rocc_fpu_req_bits_wflags;
  wire [2:0] csr_io_rocc_fpu_req_bits_rm;
  wire [1:0] csr_io_rocc_fpu_req_bits_typ;
  wire [32:0] csr_io_rocc_fpu_req_bits_in1;
  wire [32:0] csr_io_rocc_fpu_req_bits_in2;
  wire [32:0] csr_io_rocc_fpu_req_bits_in3;
  wire  csr_io_rocc_fpu_resp_ready;
  wire  csr_io_rocc_fpu_resp_valid;
  wire [32:0] csr_io_rocc_fpu_resp_bits_data;
  wire [4:0] csr_io_rocc_fpu_resp_bits_exc;
  wire  csr_io_rocc_exception;
  wire  csr_io_interrupt;
  wire [31:0] csr_io_interrupt_cause;
  wire [3:0] csr_io_bp_0_control_ttype;
  wire  csr_io_bp_0_control_dmode;
  wire [5:0] csr_io_bp_0_control_maskmax;
  wire [7:0] csr_io_bp_0_control_reserved;
  wire  csr_io_bp_0_control_action;
  wire  csr_io_bp_0_control_chain;
  wire [1:0] csr_io_bp_0_control_zero;
  wire [1:0] csr_io_bp_0_control_tmatch;
  wire  csr_io_bp_0_control_m;
  wire  csr_io_bp_0_control_h;
  wire  csr_io_bp_0_control_s;
  wire  csr_io_bp_0_control_u;
  wire  csr_io_bp_0_control_x;
  wire  csr_io_bp_0_control_w;
  wire  csr_io_bp_0_control_r;
  wire [31:0] csr_io_bp_0_address;
  wire  id_csr_en;
  wire  id_system_insn;
  wire  T_6646;
  wire  T_6647;
  wire  T_6648;
  wire  id_csr_ren;
  wire [2:0] id_csr;
  wire [11:0] id_csr_addr;
  wire  T_6652;
  wire  T_6653;
  wire [11:0] T_6783;
  wire  T_6785;
  wire [11:0] T_6787;
  wire  T_6789;
  wire  T_6792;
  wire  T_6795;
  wire  T_6796;
  wire  id_csr_flush;
  wire  T_6798;
  wire  T_6799;
  wire  T_6801;
  wire  T_6802;
  wire  T_6803;
  wire  T_6804;
  wire  T_6806;
  wire  T_6807;
  wire  T_6808;
  wire  T_6810;
  wire  T_6811;
  wire  T_6812;
  wire  T_6814;
  wire  T_6815;
  wire  T_6816;
  wire  T_6817;
  wire  T_6819;
  wire  T_6820;
  wire  T_6821;
  wire  T_6822;
  wire  T_6824;
  wire  T_6825;
  wire  T_6826;
  wire  T_6828;
  wire  T_6829;
  wire  T_6830;
  wire  T_6832;
  wire  T_6833;
  wire  id_illegal_insn;
  wire  id_amo_aq;
  wire  id_amo_rl;
  wire  T_6834;
  wire  id_fence_next;
  wire  T_6836;
  wire  id_mem_busy;
  wire  T_6842;
  wire  T_6844;
  wire  T_6845;
  wire  T_6847;
  wire  T_6848;
  wire  T_6849;
  wire  T_6850;
  wire  T_6851;
  wire  T_6852;
  wire  bpu_clock;
  wire  bpu_reset;
  wire  bpu_io_status_debug;
  wire [31:0] bpu_io_status_isa;
  wire [1:0] bpu_io_status_prv;
  wire  bpu_io_status_sd;
  wire [30:0] bpu_io_status_zero3;
  wire  bpu_io_status_sd_rv32;
  wire [1:0] bpu_io_status_zero2;
  wire [4:0] bpu_io_status_vm;
  wire [3:0] bpu_io_status_zero1;
  wire  bpu_io_status_mxr;
  wire  bpu_io_status_pum;
  wire  bpu_io_status_mprv;
  wire [1:0] bpu_io_status_xs;
  wire [1:0] bpu_io_status_fs;
  wire [1:0] bpu_io_status_mpp;
  wire [1:0] bpu_io_status_hpp;
  wire  bpu_io_status_spp;
  wire  bpu_io_status_mpie;
  wire  bpu_io_status_hpie;
  wire  bpu_io_status_spie;
  wire  bpu_io_status_upie;
  wire  bpu_io_status_mie;
  wire  bpu_io_status_hie;
  wire  bpu_io_status_sie;
  wire  bpu_io_status_uie;
  wire [3:0] bpu_io_bp_0_control_ttype;
  wire  bpu_io_bp_0_control_dmode;
  wire [5:0] bpu_io_bp_0_control_maskmax;
  wire [7:0] bpu_io_bp_0_control_reserved;
  wire  bpu_io_bp_0_control_action;
  wire  bpu_io_bp_0_control_chain;
  wire [1:0] bpu_io_bp_0_control_zero;
  wire [1:0] bpu_io_bp_0_control_tmatch;
  wire  bpu_io_bp_0_control_m;
  wire  bpu_io_bp_0_control_h;
  wire  bpu_io_bp_0_control_s;
  wire  bpu_io_bp_0_control_u;
  wire  bpu_io_bp_0_control_x;
  wire  bpu_io_bp_0_control_w;
  wire  bpu_io_bp_0_control_r;
  wire [31:0] bpu_io_bp_0_address;
  wire [31:0] bpu_io_pc;
  wire [31:0] bpu_io_ea;
  wire  bpu_io_xcpt_if;
  wire  bpu_io_xcpt_ld;
  wire  bpu_io_xcpt_st;
  wire  bpu_io_debug_if;
  wire  bpu_io_debug_ld;
  wire  bpu_io_debug_st;
  wire  id_xcpt_if;
  wire  T_6857;
  wire  T_6858;
  wire  T_6859;
  wire  id_xcpt;
  wire [1:0] T_6860;
  wire [1:0] T_6861;
  wire [3:0] T_6862;
  wire [31:0] id_cause;
  wire [4:0] ex_waddr;
  wire [4:0] mem_waddr;
  wire [4:0] wb_waddr;
  wire  T_6866;
  wire  T_6867;
  wire  T_6869;
  wire  T_6870;
  wire  T_6872;
  wire  T_6873;
  wire  id_bypass_src_0_1;
  wire  T_6874;
  wire  id_bypass_src_0_2;
  wire  id_bypass_src_0_3;
  wire  T_6876;
  wire  T_6877;
  wire  id_bypass_src_1_1;
  wire  T_6878;
  wire  id_bypass_src_1_2;
  wire  id_bypass_src_1_3;
  wire [31:0] bypass_mux_0;
  wire [31:0] bypass_mux_1;
  wire [31:0] bypass_mux_2;
  wire [31:0] bypass_mux_3;
  reg  ex_reg_rs_bypass_0;
  reg [31:0] GEN_405;
  reg  ex_reg_rs_bypass_1;
  reg [31:0] GEN_406;
  reg [1:0] ex_reg_rs_lsb_0;
  reg [31:0] GEN_407;
  reg [1:0] ex_reg_rs_lsb_1;
  reg [31:0] GEN_408;
  reg [29:0] ex_reg_rs_msb_0;
  reg [31:0] GEN_409;
  reg [29:0] ex_reg_rs_msb_1;
  reg [31:0] GEN_410;
  wire [31:0] T_6909;
  wire [31:0] GEN_0;
  wire [31:0] GEN_2;
  wire [31:0] GEN_3;
  wire [31:0] GEN_4;
  wire [31:0] ex_rs_0;
  wire [31:0] T_6914;
  wire [31:0] GEN_1;
  wire [31:0] GEN_5;
  wire [31:0] GEN_6;
  wire [31:0] GEN_7;
  wire [31:0] ex_rs_1;
  wire  T_6915;
  wire  T_6917;
  wire  T_6918;
  wire  T_6919;
  wire  T_6920;
  wire [10:0] T_6921;
  wire [10:0] T_6922;
  wire [10:0] T_6923;
  wire  T_6924;
  wire  T_6925;
  wire  T_6926;
  wire [7:0] T_6927;
  wire [7:0] T_6928;
  wire [7:0] T_6929;
  wire  T_6932;
  wire  T_6934;
  wire  T_6935;
  wire  T_6936;
  wire  T_6937;
  wire  T_6938;
  wire  T_6939;
  wire  T_6940;
  wire  T_6941;
  wire  T_6942;
  wire [5:0] T_6947;
  wire [5:0] T_6948;
  wire  T_6951;
  wire  T_6953;
  wire [3:0] T_6954;
  wire [3:0] T_6956;
  wire [3:0] T_6957;
  wire [3:0] T_6958;
  wire [3:0] T_6959;
  wire [3:0] T_6960;
  wire  T_6963;
  wire  T_6966;
  wire  T_6969;
  wire  T_6971;
  wire  T_6973;
  wire [9:0] T_6974;
  wire [10:0] T_6975;
  wire  T_6976;
  wire [7:0] T_6977;
  wire [8:0] T_6978;
  wire [10:0] T_6979;
  wire  T_6980;
  wire [11:0] T_6981;
  wire [20:0] T_6982;
  wire [31:0] T_6983;
  wire [31:0] ex_imm;
  wire [31:0] T_6985;
  wire [31:0] T_6986;
  wire  T_6987;
  wire [31:0] T_6988;
  wire  T_6989;
  wire [31:0] ex_op1;
  wire [31:0] T_6991;
  wire [3:0] T_6994;
  wire  T_6995;
  wire [3:0] T_6996;
  wire  T_6997;
  wire [31:0] T_6998;
  wire  T_6999;
  wire [31:0] ex_op2;
  wire  alu_clock;
  wire  alu_reset;
  wire  alu_io_dw;
  wire [3:0] alu_io_fn;
  wire [31:0] alu_io_in2;
  wire [31:0] alu_io_in1;
  wire [31:0] alu_io_out;
  wire [31:0] alu_io_adder_out;
  wire  alu_io_cmp_out;
  wire [31:0] T_7000;
  wire [31:0] T_7001;
  wire  div_clock;
  wire  div_reset;
  wire  div_io_req_ready;
  wire  div_io_req_valid;
  wire [3:0] div_io_req_bits_fn;
  wire  div_io_req_bits_dw;
  wire [31:0] div_io_req_bits_in1;
  wire [31:0] div_io_req_bits_in2;
  wire [4:0] div_io_req_bits_tag;
  wire  div_io_kill;
  wire  div_io_resp_ready;
  wire  div_io_resp_valid;
  wire [31:0] div_io_resp_bits_data;
  wire [4:0] div_io_resp_bits_tag;
  wire  T_7002;
  wire  T_7006;
  wire  T_7007;
  wire  T_7008;
  wire  T_7011;
  wire  T_7015;
  wire [31:0] GEN_8;
  wire  GEN_9;
  wire [1:0] GEN_10;
  wire  GEN_11;
  wire [31:0] GEN_12;
  wire  GEN_13;
  wire  GEN_14;
  wire [1:0] GEN_15;
  wire  T_7019;
  wire  T_7021;
  wire  T_7022;
  wire  T_7023;
  wire [1:0] GEN_16;
  wire  GEN_17;
  wire [3:0] GEN_18;
  wire  GEN_19;
  wire [1:0] GEN_20;
  wire [1:0] GEN_21;
  wire  GEN_22;
  wire  T_7025;
  wire  T_7026;
  wire  T_7027;
  wire  GEN_23;
  wire  GEN_24;
  wire  T_7030;
  wire  T_7031;
  wire  T_7032;
  wire [1:0] T_7037;
  wire [1:0] T_7038;
  wire [1:0] T_7039;
  wire  T_7041;
  wire  T_7042;
  wire [1:0] T_7043;
  wire [29:0] T_7044;
  wire [1:0] GEN_25;
  wire [29:0] GEN_26;
  wire  T_7045;
  wire  T_7046;
  wire  T_7047;
  wire [1:0] T_7052;
  wire [1:0] T_7053;
  wire [1:0] T_7054;
  wire  T_7056;
  wire  T_7057;
  wire [1:0] T_7058;
  wire [29:0] T_7059;
  wire [1:0] GEN_27;
  wire [29:0] GEN_28;
  wire  GEN_29;
  wire  GEN_30;
  wire  GEN_31;
  wire  GEN_32;
  wire  GEN_33;
  wire  GEN_34;
  wire  GEN_35;
  wire  GEN_36;
  wire [1:0] GEN_37;
  wire [1:0] GEN_38;
  wire [2:0] GEN_39;
  wire  GEN_40;
  wire [3:0] GEN_41;
  wire  GEN_42;
  wire [4:0] GEN_43;
  wire [2:0] GEN_44;
  wire  GEN_45;
  wire  GEN_46;
  wire  GEN_47;
  wire  GEN_48;
  wire  GEN_49;
  wire  GEN_50;
  wire [2:0] GEN_51;
  wire  GEN_52;
  wire  GEN_53;
  wire  GEN_54;
  wire  GEN_55;
  wire  GEN_56;
  wire  GEN_57;
  wire  GEN_58;
  wire  GEN_59;
  wire [1:0] GEN_60;
  wire [29:0] GEN_61;
  wire  GEN_62;
  wire [1:0] GEN_63;
  wire [29:0] GEN_64;
  wire  T_7062;
  wire  T_7063;
  wire [31:0] GEN_65;
  wire [31:0] GEN_66;
  wire  T_7064;
  wire  ex_pc_valid;
  wire  T_7066;
  wire  wb_dcache_miss;
  wire  T_7068;
  wire  T_7069;
  wire  T_7071;
  wire  T_7072;
  wire  replay_ex_structural;
  wire  replay_ex_load_use;
  wire  T_7073;
  wire  T_7074;
  wire  replay_ex;
  wire  T_7075;
  wire  T_7077;
  wire  ctrl_killx;
  wire  T_7078;
  wire [2:0] T_7086_0;
  wire [2:0] T_7086_1;
  wire [2:0] T_7086_2;
  wire [2:0] T_7086_3;
  wire  T_7093;
  wire  T_7094;
  wire  T_7095;
  wire  T_7096;
  wire  T_7099;
  wire  T_7100;
  wire  T_7101;
  wire  ex_slow_bypass;
  wire  T_7102;
  wire  T_7103;
  wire  ex_xcpt;
  wire [31:0] ex_cause;
  wire  mem_br_taken;
  wire [31:0] T_7105;
  wire  T_7106;
  wire  T_7109;
  wire  T_7110;
  wire [10:0] T_7115;
  wire [7:0] T_7119;
  wire [7:0] T_7120;
  wire [7:0] T_7121;
  wire  T_7127;
  wire  T_7128;
  wire  T_7130;
  wire  T_7131;
  wire [5:0] T_7139;
  wire [3:0] T_7146;
  wire [3:0] T_7149;
  wire [9:0] T_7166;
  wire [10:0] T_7167;
  wire  T_7168;
  wire [7:0] T_7169;
  wire [8:0] T_7170;
  wire [10:0] T_7171;
  wire  T_7172;
  wire [11:0] T_7173;
  wire [20:0] T_7174;
  wire [31:0] T_7175;
  wire [31:0] T_7176;
  wire [9:0] T_7238;
  wire [10:0] T_7239;
  wire  T_7240;
  wire [7:0] T_7241;
  wire [8:0] T_7242;
  wire [20:0] T_7246;
  wire [31:0] T_7247;
  wire [31:0] T_7248;
  wire [3:0] T_7251;
  wire [31:0] T_7252;
  wire [31:0] T_7253;
  wire [32:0] T_7254;
  wire [31:0] T_7255;
  wire [31:0] mem_br_target;
  wire [31:0] T_7256;
  wire [31:0] T_7257;
  wire [31:0] T_7259;
  wire [31:0] T_7260;
  wire [31:0] mem_npc;
  wire  T_7261;
  wire  T_7262;
  wire  T_7264;
  wire  mem_wrong_npc;
  wire  T_7268;
  wire  mem_npc_misaligned;
  wire  T_7270;
  wire  T_7271;
  wire  T_7272;
  wire [31:0] T_7274;
  wire [31:0] mem_int_wdata;
  wire  T_7275;
  wire  mem_cfi;
  wire  T_7277;
  wire  mem_cfi_taken;
  wire  T_7280;
  wire  T_7281;
  wire  T_7283;
  wire  T_7285;
  wire  T_7286;
  wire  T_7289;
  wire  T_7292;
  wire [31:0] GEN_67;
  wire  T_7293;
  wire  T_7294;
  wire  T_7295;
  wire  T_7297;
  wire  T_7298;
  wire  T_7299;
  wire  T_7300;
  wire  T_7301;
  wire  T_7302;
  wire  T_7303;
  wire  T_7305;
  wire  T_7309;
  wire  T_7310;
  wire  GEN_68;
  wire [1:0] GEN_69;
  wire  GEN_70;
  wire [31:0] GEN_71;
  wire  GEN_72;
  wire  GEN_73;
  wire [1:0] GEN_74;
  wire  T_7311;
  wire  T_7312;
  wire [31:0] GEN_75;
  wire  GEN_76;
  wire  GEN_77;
  wire  GEN_78;
  wire  GEN_79;
  wire  GEN_80;
  wire  GEN_81;
  wire  GEN_82;
  wire  GEN_83;
  wire [1:0] GEN_84;
  wire [1:0] GEN_85;
  wire [2:0] GEN_86;
  wire  GEN_87;
  wire [3:0] GEN_88;
  wire  GEN_89;
  wire [4:0] GEN_90;
  wire [2:0] GEN_91;
  wire  GEN_92;
  wire  GEN_93;
  wire  GEN_94;
  wire  GEN_95;
  wire  GEN_96;
  wire  GEN_97;
  wire [2:0] GEN_98;
  wire  GEN_99;
  wire  GEN_100;
  wire  GEN_101;
  wire  GEN_102;
  wire  GEN_103;
  wire  GEN_104;
  wire  GEN_105;
  wire  GEN_106;
  wire  GEN_107;
  wire [1:0] GEN_108;
  wire  GEN_109;
  wire [31:0] GEN_110;
  wire  GEN_111;
  wire  GEN_112;
  wire [1:0] GEN_113;
  wire  GEN_114;
  wire  GEN_115;
  wire [31:0] GEN_116;
  wire [31:0] GEN_117;
  wire [31:0] GEN_118;
  wire [31:0] GEN_119;
  wire  T_7313;
  wire  T_7314;
  wire  mem_breakpoint;
  wire  T_7315;
  wire  T_7316;
  wire  mem_debug_breakpoint;
  wire  T_7320;
  wire  T_7322;
  wire  T_7324;
  wire  T_7326;
  wire  T_7328;
  wire  T_7329;
  wire  T_7330;
  wire  T_7331;
  wire  T_7332;
  wire  mem_new_xcpt;
  wire [2:0] T_7333;
  wire [2:0] T_7334;
  wire [2:0] T_7335;
  wire [2:0] T_7336;
  wire [2:0] T_7337;
  wire [3:0] mem_new_cause;
  wire  T_7338;
  wire  T_7339;
  wire  mem_xcpt;
  wire [31:0] mem_cause;
  wire  dcache_kill_mem;
  wire  T_7341;
  wire  fpu_kill_mem;
  wire  T_7342;
  wire  replay_mem;
  wire  T_7343;
  wire  T_7344;
  wire  T_7346;
  wire  killm_common;
  wire  T_7347;
  reg  T_7348;
  reg [31:0] GEN_411;
  wire  T_7349;
  wire  T_7350;
  wire  ctrl_killm;
  wire  T_7352;
  wire  T_7354;
  wire  T_7355;
  wire  T_7358;
  wire [31:0] GEN_120;
  wire  T_7359;
  wire  T_7360;
  wire  T_7363;
  wire  T_7364;
  wire [31:0] T_7365;
  wire [31:0] GEN_121;
  wire  GEN_122;
  wire  GEN_123;
  wire  GEN_124;
  wire  GEN_125;
  wire  GEN_126;
  wire  GEN_127;
  wire  GEN_128;
  wire  GEN_129;
  wire [1:0] GEN_130;
  wire [1:0] GEN_131;
  wire [2:0] GEN_132;
  wire  GEN_133;
  wire [3:0] GEN_134;
  wire  GEN_135;
  wire [4:0] GEN_136;
  wire [2:0] GEN_137;
  wire  GEN_138;
  wire  GEN_139;
  wire  GEN_140;
  wire  GEN_141;
  wire  GEN_142;
  wire  GEN_143;
  wire [2:0] GEN_144;
  wire  GEN_145;
  wire  GEN_146;
  wire  GEN_147;
  wire  GEN_148;
  wire [31:0] GEN_149;
  wire [31:0] GEN_150;
  wire [31:0] GEN_151;
  wire [31:0] GEN_152;
  wire  wb_wxd;
  wire  T_7366;
  wire  wb_set_sboard;
  wire  replay_wb_common;
  wire  T_7369;
  wire  replay_wb_rocc;
  wire  replay_wb;
  wire  wb_xcpt;
  wire  T_7370;
  wire  T_7371;
  wire  T_7372;
  wire  dmem_resp_xpu;
  wire [4:0] dmem_resp_waddr;
  wire  dmem_resp_valid;
  wire  dmem_resp_replay;
  wire  T_7377;
  wire [31:0] ll_wdata;
  wire [4:0] ll_waddr;
  wire  T_7378;
  wire  ll_wen;
  wire  T_7379;
  wire  GEN_153;
  wire [4:0] GEN_154;
  wire  GEN_155;
  wire  T_7383;
  wire  T_7384;
  wire  T_7386;
  wire  wb_valid;
  wire  wb_wen;
  wire  rf_wen;
  wire [4:0] rf_waddr;
  wire  T_7387;
  wire  T_7388;
  wire [31:0] T_7389;
  wire [31:0] T_7390;
  wire [31:0] rf_wdata;
  wire  T_7392;
  wire [4:0] T_7394;
  wire  T_7396;
  wire [31:0] GEN_156;
  wire  T_7397;
  wire [31:0] GEN_157;
  wire [31:0] GEN_162;
  wire [31:0] GEN_163;
  wire  GEN_166;
  wire [31:0] GEN_168;
  wire [31:0] GEN_169;
  wire [11:0] T_7398;
  wire [2:0] T_7399;
  wire  T_7401;
  wire  T_7402;
  wire  T_7404;
  wire  T_7405;
  wire  T_7407;
  wire  T_7408;
  reg [31:0] T_7410;
  reg [31:0] GEN_412;
  wire [30:0] T_7411;
  wire [31:0] GEN_180;
  wire [31:0] T_7412;
  wire [31:0] T_7415;
  wire [31:0] T_7417;
  wire [31:0] T_7418;
  wire [31:0] T_7419;
  wire [31:0] GEN_170;
  wire [31:0] T_7421;
  wire  T_7422;
  wire  T_7423;
  wire [31:0] T_7424;
  wire  T_7425;
  wire  T_7426;
  wire [31:0] T_7427;
  wire  T_7428;
  wire  T_7429;
  wire  T_7430;
  wire  id_sboard_hazard;
  wire  T_7431;
  wire [31:0] T_7433;
  wire [31:0] T_7435;
  wire [31:0] T_7436;
  wire  T_7437;
  wire [31:0] GEN_171;
  wire  T_7438;
  wire  T_7439;
  wire  T_7440;
  wire  T_7441;
  wire  T_7442;
  wire  ex_cannot_bypass;
  wire  T_7443;
  wire  T_7444;
  wire  T_7445;
  wire  T_7446;
  wire  T_7447;
  wire  T_7448;
  wire  T_7449;
  wire  T_7450;
  wire  data_hazard_ex;
  wire  T_7452;
  wire  T_7454;
  wire  T_7455;
  wire  T_7456;
  wire  T_7458;
  wire  T_7459;
  wire  T_7460;
  wire  T_7461;
  wire  fp_data_hazard_ex;
  wire  T_7462;
  wire  T_7463;
  wire  id_ex_hazard;
  wire  T_7465;
  wire  T_7466;
  wire  T_7467;
  wire  T_7468;
  wire  T_7469;
  wire  mem_cannot_bypass;
  wire  T_7470;
  wire  T_7471;
  wire  T_7472;
  wire  T_7473;
  wire  T_7474;
  wire  T_7475;
  wire  T_7476;
  wire  T_7477;
  wire  data_hazard_mem;
  wire  T_7479;
  wire  T_7481;
  wire  T_7482;
  wire  T_7483;
  wire  T_7485;
  wire  T_7486;
  wire  T_7487;
  wire  T_7488;
  wire  fp_data_hazard_mem;
  wire  T_7489;
  wire  T_7490;
  wire  id_mem_hazard;
  wire  T_7491;
  wire  T_7492;
  wire  T_7493;
  wire  T_7494;
  wire  T_7495;
  wire  T_7496;
  wire  T_7497;
  wire  T_7498;
  wire  T_7499;
  wire  T_7500;
  wire  data_hazard_wb;
  wire  T_7502;
  wire  T_7504;
  wire  T_7505;
  wire  T_7506;
  wire  T_7508;
  wire  T_7509;
  wire  T_7510;
  wire  T_7511;
  wire  fp_data_hazard_wb;
  wire  T_7512;
  wire  T_7513;
  wire  id_wb_hazard;
  reg  dcache_blocked;
  reg [31:0] GEN_413;
  wire  T_7517;
  wire  T_7518;
  reg  rocc_blocked;
  reg [31:0] GEN_414;
  wire  T_7521;
  wire  T_7524;
  wire  T_7525;
  wire  T_7526;
  wire  T_7527;
  wire  T_7528;
  wire  T_7529;
  wire  T_7532;
  wire  T_7533;
  wire  T_7534;
  wire  T_7535;
  wire  T_7538;
  wire  T_7539;
  wire  T_7541;
  wire  T_7542;
  wire  T_7543;
  wire  T_7544;
  wire  T_7545;
  wire  ctrl_stalld;
  wire  T_7547;
  wire  T_7548;
  wire  T_7549;
  wire  T_7550;
  wire  T_7551;
  wire  T_7554;
  wire [31:0] T_7558;
  wire [31:0] T_7559;
  wire  T_7560;
  wire  T_7562;
  wire  T_7563;
  wire  T_7565;
  wire  T_7566;
  wire  T_7567;
  wire  T_7570;
  wire  T_7572;
  wire  T_7573;
  wire  T_7574;
  wire  T_7581;
  wire  T_7582;
  wire  T_7584;
  wire  T_7585;
  wire  T_7586;
  wire [4:0] T_7587;
  wire [4:0] T_7590;
  wire  T_7591;
  wire  T_7592;
  wire [1:0] T_7595;
  wire [31:0] GEN_181;
  wire [32:0] T_7596;
  wire [31:0] T_7597;
  wire [31:0] T_7598;
  wire [31:0] T_7600;
  wire [31:0] T_7601;
  wire  T_7605;
  wire  T_7609;
  wire  T_7610;
  wire  T_7613;
  wire  T_7614;
  wire  T_7615;
  wire [5:0] ex_dcache_tag;
  wire [31:0] T_7617;
  wire  T_7618;
  wire  T_7619;
  wire  T_7621;
  wire  T_7622;
  wire [1:0] T_7623;
  wire [1:0] T_7624;
  wire [3:0] T_7625;
  wire  T_7627;
  wire  T_7628;
  wire  T_7630;
  wire  T_7633;
  wire  T_7634;
  wire  T_7637;
  wire [6:0] T_7656_funct;
  wire [4:0] T_7656_rs2;
  wire [4:0] T_7656_rs1;
  wire  T_7656_xd;
  wire  T_7656_xs1;
  wire  T_7656_xs2;
  wire [4:0] T_7656_rd;
  wire [6:0] T_7656_opcode;
  wire [31:0] T_7666;
  wire [6:0] T_7667;
  wire [4:0] T_7668;
  wire  T_7669;
  wire  T_7670;
  wire  T_7671;
  wire [4:0] T_7672;
  wire [4:0] T_7673;
  wire [6:0] T_7674;
  wire [31:0] T_7675;
  wire [4:0] T_7677;
  wire [4:0] T_7678;
  reg [31:0] T_7679;
  reg [31:0] GEN_415;
  reg [31:0] T_7680;
  reg [31:0] GEN_416;
  wire [4:0] T_7681;
  reg [31:0] T_7682;
  reg [31:0] GEN_417;
  reg [31:0] T_7683;
  reg [31:0] GEN_418;
  wire  T_7685;
  reg  GEN_158;
  reg [31:0] GEN_419;
  reg [31:0] GEN_159;
  reg [31:0] GEN_420;
  reg  GEN_160;
  reg [31:0] GEN_421;
  reg [4:0] GEN_161;
  reg [31:0] GEN_422;
  reg  GEN_164;
  reg [31:0] GEN_423;
  reg  GEN_165;
  reg [31:0] GEN_424;
  reg  GEN_167;
  reg [31:0] GEN_425;
  reg  GEN_172;
  reg [31:0] GEN_426;
  reg  GEN_173;
  reg [31:0] GEN_427;
  reg  GEN_174;
  reg [31:0] GEN_428;
  reg  GEN_175;
  reg [31:0] GEN_429;
  reg  GEN_176;
  reg [31:0] GEN_430;
  reg  GEN_177;
  reg [31:0] GEN_431;
  reg  GEN_178;
  reg [31:0] GEN_432;
  reg  GEN_179;
  reg [31:0] GEN_433;
  reg  GEN_182;
  reg [31:0] GEN_434;
  reg  GEN_183;
  reg [31:0] GEN_435;
  reg  GEN_184;
  reg [31:0] GEN_436;
  reg  GEN_185;
  reg [31:0] GEN_437;
  reg  GEN_186;
  reg [31:0] GEN_438;
  reg [2:0] GEN_187;
  reg [31:0] GEN_439;
  reg [1:0] GEN_188;
  reg [31:0] GEN_440;
  reg [32:0] GEN_189;
  reg [63:0] GEN_441;
  reg [32:0] GEN_190;
  reg [63:0] GEN_442;
  reg [32:0] GEN_191;
  reg [63:0] GEN_443;
  reg  GEN_192;
  reg [31:0] GEN_444;
  reg  GEN_193;
  reg [31:0] GEN_445;
  reg  GEN_194;
  reg [31:0] GEN_446;
  reg  GEN_195;
  reg [31:0] GEN_447;
  reg  GEN_196;
  reg [31:0] GEN_448;
  reg [31:0] GEN_197;
  reg [31:0] GEN_449;
  reg [6:0] GEN_198;
  reg [31:0] GEN_450;
  reg [4:0] GEN_199;
  reg [31:0] GEN_451;
  reg [2:0] GEN_200;
  reg [31:0] GEN_452;
  reg [31:0] GEN_201;
  reg [31:0] GEN_453;
  reg  GEN_202;
  reg [31:0] GEN_454;
  reg  GEN_203;
  reg [31:0] GEN_455;
  reg [31:0] GEN_204;
  reg [31:0] GEN_456;
  reg [31:0] GEN_205;
  reg [31:0] GEN_457;
  reg  GEN_206;
  reg [31:0] GEN_458;
  reg  GEN_207;
  reg [31:0] GEN_459;
  reg  GEN_208;
  reg [31:0] GEN_460;
  reg  GEN_209;
  reg [31:0] GEN_461;
  reg  GEN_210;
  reg [31:0] GEN_462;
  reg  GEN_211;
  reg [31:0] GEN_463;
  reg  GEN_212;
  reg [31:0] GEN_464;
  reg  GEN_213;
  reg [31:0] GEN_465;
  reg [3:0] GEN_214;
  reg [31:0] GEN_466;
  reg  GEN_215;
  reg [31:0] GEN_467;
  reg [1:0] GEN_216;
  reg [31:0] GEN_468;
  reg  GEN_217;
  reg [31:0] GEN_469;
  reg [3:0] GEN_218;
  reg [31:0] GEN_470;
  reg [31:0] GEN_219;
  reg [31:0] GEN_471;
  reg  GEN_220;
  reg [31:0] GEN_472;
  reg  GEN_221;
  reg [31:0] GEN_473;
  reg [32:0] GEN_222;
  reg [63:0] GEN_474;
  reg [4:0] GEN_223;
  reg [31:0] GEN_475;
  reg  GEN_224;
  reg [31:0] GEN_476;
  reg  GEN_225;
  reg [31:0] GEN_477;
  reg [4:0] GEN_226;
  reg [31:0] GEN_478;
  reg [31:0] GEN_227;
  reg [31:0] GEN_479;
  reg  GEN_228;
  reg [31:0] GEN_480;
  reg [31:0] GEN_229;
  reg [31:0] GEN_481;
  reg [6:0] GEN_230;
  reg [31:0] GEN_482;
  reg [4:0] GEN_231;
  reg [31:0] GEN_483;
  reg [2:0] GEN_232;
  reg [31:0] GEN_484;
  reg  GEN_233;
  reg [31:0] GEN_485;
  reg [31:0] GEN_234;
  reg [31:0] GEN_486;
  reg  GEN_235;
  reg [31:0] GEN_487;
  reg [31:0] GEN_236;
  reg [31:0] GEN_488;
  reg  GEN_237;
  reg [31:0] GEN_489;
  reg  GEN_238;
  reg [31:0] GEN_490;
  reg  GEN_239;
  reg [31:0] GEN_491;
  reg [25:0] GEN_240;
  reg [31:0] GEN_492;
  reg  GEN_241;
  reg [31:0] GEN_493;
  reg [3:0] GEN_242;
  reg [31:0] GEN_494;
  reg  GEN_243;
  reg [31:0] GEN_495;
  reg [2:0] GEN_244;
  reg [31:0] GEN_496;
  reg [9:0] GEN_245;
  reg [31:0] GEN_497;
  reg [31:0] GEN_246;
  reg [31:0] GEN_498;
  reg  GEN_247;
  reg [31:0] GEN_499;
  reg  GEN_248;
  reg [31:0] GEN_500;
  reg [4:0] GEN_249;
  reg [31:0] GEN_501;
  reg  GEN_250;
  reg [31:0] GEN_502;
  reg  GEN_251;
  reg [31:0] GEN_503;
  reg  GEN_252;
  reg [31:0] GEN_504;
  reg  GEN_253;
  reg [31:0] GEN_505;
  reg  GEN_254;
  reg [31:0] GEN_506;
  reg  GEN_255;
  reg [31:0] GEN_507;
  reg  GEN_256;
  reg [31:0] GEN_508;
  reg  GEN_257;
  reg [31:0] GEN_509;
  reg  GEN_258;
  reg [31:0] GEN_510;
  reg  GEN_259;
  reg [31:0] GEN_511;
  reg  GEN_260;
  reg [31:0] GEN_512;
  reg  GEN_261;
  reg [31:0] GEN_513;
  reg  GEN_262;
  reg [31:0] GEN_514;
  reg  GEN_263;
  reg [31:0] GEN_515;
  reg  GEN_264;
  reg [31:0] GEN_516;
  reg  GEN_265;
  reg [31:0] GEN_517;
  reg [2:0] GEN_266;
  reg [31:0] GEN_518;
  reg [1:0] GEN_267;
  reg [31:0] GEN_519;
  reg [32:0] GEN_268;
  reg [63:0] GEN_520;
  reg [32:0] GEN_269;
  reg [63:0] GEN_521;
  reg [32:0] GEN_270;
  reg [63:0] GEN_522;
  reg  GEN_271;
  reg [31:0] GEN_523;
  IBuf ibuf (
    .clock(ibuf_clock),
    .reset(ibuf_reset),
    .io_imem_ready(ibuf_io_imem_ready),
    .io_imem_valid(ibuf_io_imem_valid),
    .io_imem_bits_btb_valid(ibuf_io_imem_bits_btb_valid),
    .io_imem_bits_btb_bits_taken(ibuf_io_imem_bits_btb_bits_taken),
    .io_imem_bits_btb_bits_mask(ibuf_io_imem_bits_btb_bits_mask),
    .io_imem_bits_btb_bits_bridx(ibuf_io_imem_bits_btb_bits_bridx),
    .io_imem_bits_btb_bits_target(ibuf_io_imem_bits_btb_bits_target),
    .io_imem_bits_btb_bits_entry(ibuf_io_imem_bits_btb_bits_entry),
    .io_imem_bits_btb_bits_bht_history(ibuf_io_imem_bits_btb_bits_bht_history),
    .io_imem_bits_btb_bits_bht_value(ibuf_io_imem_bits_btb_bits_bht_value),
    .io_imem_bits_pc(ibuf_io_imem_bits_pc),
    .io_imem_bits_data(ibuf_io_imem_bits_data),
    .io_imem_bits_mask(ibuf_io_imem_bits_mask),
    .io_imem_bits_xcpt_if(ibuf_io_imem_bits_xcpt_if),
    .io_imem_bits_replay(ibuf_io_imem_bits_replay),
    .io_kill(ibuf_io_kill),
    .io_pc(ibuf_io_pc),
    .io_btb_resp_taken(ibuf_io_btb_resp_taken),
    .io_btb_resp_mask(ibuf_io_btb_resp_mask),
    .io_btb_resp_bridx(ibuf_io_btb_resp_bridx),
    .io_btb_resp_target(ibuf_io_btb_resp_target),
    .io_btb_resp_entry(ibuf_io_btb_resp_entry),
    .io_btb_resp_bht_history(ibuf_io_btb_resp_bht_history),
    .io_btb_resp_bht_value(ibuf_io_btb_resp_bht_value),
    .io_inst_0_ready(ibuf_io_inst_0_ready),
    .io_inst_0_valid(ibuf_io_inst_0_valid),
    .io_inst_0_bits_pf0(ibuf_io_inst_0_bits_pf0),
    .io_inst_0_bits_pf1(ibuf_io_inst_0_bits_pf1),
    .io_inst_0_bits_replay(ibuf_io_inst_0_bits_replay),
    .io_inst_0_bits_btb_hit(ibuf_io_inst_0_bits_btb_hit),
    .io_inst_0_bits_rvc(ibuf_io_inst_0_bits_rvc),
    .io_inst_0_bits_inst_bits(ibuf_io_inst_0_bits_inst_bits),
    .io_inst_0_bits_inst_rd(ibuf_io_inst_0_bits_inst_rd),
    .io_inst_0_bits_inst_rs1(ibuf_io_inst_0_bits_inst_rs1),
    .io_inst_0_bits_inst_rs2(ibuf_io_inst_0_bits_inst_rs2),
    .io_inst_0_bits_inst_rs3(ibuf_io_inst_0_bits_inst_rs3)
  );
  CSRFile csr (
    .clock(csr_clock),
    .reset(csr_reset),
    .io_interrupts_debug(csr_io_interrupts_debug),
    .io_interrupts_mtip(csr_io_interrupts_mtip),
    .io_interrupts_msip(csr_io_interrupts_msip),
    .io_interrupts_meip(csr_io_interrupts_meip),
    .io_hartid(csr_io_hartid),
    .io_rw_addr(csr_io_rw_addr),
    .io_rw_cmd(csr_io_rw_cmd),
    .io_rw_rdata(csr_io_rw_rdata),
    .io_rw_wdata(csr_io_rw_wdata),
    .io_csr_stall(csr_io_csr_stall),
    .io_csr_xcpt(csr_io_csr_xcpt),
    .io_eret(csr_io_eret),
    .io_singleStep(csr_io_singleStep),
    .io_status_debug(csr_io_status_debug),
    .io_status_isa(csr_io_status_isa),
    .io_status_prv(csr_io_status_prv),
    .io_status_sd(csr_io_status_sd),
    .io_status_zero3(csr_io_status_zero3),
    .io_status_sd_rv32(csr_io_status_sd_rv32),
    .io_status_zero2(csr_io_status_zero2),
    .io_status_vm(csr_io_status_vm),
    .io_status_zero1(csr_io_status_zero1),
    .io_status_mxr(csr_io_status_mxr),
    .io_status_pum(csr_io_status_pum),
    .io_status_mprv(csr_io_status_mprv),
    .io_status_xs(csr_io_status_xs),
    .io_status_fs(csr_io_status_fs),
    .io_status_mpp(csr_io_status_mpp),
    .io_status_hpp(csr_io_status_hpp),
    .io_status_spp(csr_io_status_spp),
    .io_status_mpie(csr_io_status_mpie),
    .io_status_hpie(csr_io_status_hpie),
    .io_status_spie(csr_io_status_spie),
    .io_status_upie(csr_io_status_upie),
    .io_status_mie(csr_io_status_mie),
    .io_status_hie(csr_io_status_hie),
    .io_status_sie(csr_io_status_sie),
    .io_status_uie(csr_io_status_uie),
    .io_ptbr_asid(csr_io_ptbr_asid),
    .io_ptbr_ppn(csr_io_ptbr_ppn),
    .io_evec(csr_io_evec),
    .io_exception(csr_io_exception),
    .io_retire(csr_io_retire),
    .io_cause(csr_io_cause),
    .io_pc(csr_io_pc),
    .io_badaddr(csr_io_badaddr),
    .io_fatc(csr_io_fatc),
    .io_time(csr_io_time),
    .io_fcsr_rm(csr_io_fcsr_rm),
    .io_fcsr_flags_valid(csr_io_fcsr_flags_valid),
    .io_fcsr_flags_bits(csr_io_fcsr_flags_bits),
    .io_rocc_cmd_ready(csr_io_rocc_cmd_ready),
    .io_rocc_cmd_valid(csr_io_rocc_cmd_valid),
    .io_rocc_cmd_bits_inst_funct(csr_io_rocc_cmd_bits_inst_funct),
    .io_rocc_cmd_bits_inst_rs2(csr_io_rocc_cmd_bits_inst_rs2),
    .io_rocc_cmd_bits_inst_rs1(csr_io_rocc_cmd_bits_inst_rs1),
    .io_rocc_cmd_bits_inst_xd(csr_io_rocc_cmd_bits_inst_xd),
    .io_rocc_cmd_bits_inst_xs1(csr_io_rocc_cmd_bits_inst_xs1),
    .io_rocc_cmd_bits_inst_xs2(csr_io_rocc_cmd_bits_inst_xs2),
    .io_rocc_cmd_bits_inst_rd(csr_io_rocc_cmd_bits_inst_rd),
    .io_rocc_cmd_bits_inst_opcode(csr_io_rocc_cmd_bits_inst_opcode),
    .io_rocc_cmd_bits_rs1(csr_io_rocc_cmd_bits_rs1),
    .io_rocc_cmd_bits_rs2(csr_io_rocc_cmd_bits_rs2),
    .io_rocc_cmd_bits_status_debug(csr_io_rocc_cmd_bits_status_debug),
    .io_rocc_cmd_bits_status_isa(csr_io_rocc_cmd_bits_status_isa),
    .io_rocc_cmd_bits_status_prv(csr_io_rocc_cmd_bits_status_prv),
    .io_rocc_cmd_bits_status_sd(csr_io_rocc_cmd_bits_status_sd),
    .io_rocc_cmd_bits_status_zero3(csr_io_rocc_cmd_bits_status_zero3),
    .io_rocc_cmd_bits_status_sd_rv32(csr_io_rocc_cmd_bits_status_sd_rv32),
    .io_rocc_cmd_bits_status_zero2(csr_io_rocc_cmd_bits_status_zero2),
    .io_rocc_cmd_bits_status_vm(csr_io_rocc_cmd_bits_status_vm),
    .io_rocc_cmd_bits_status_zero1(csr_io_rocc_cmd_bits_status_zero1),
    .io_rocc_cmd_bits_status_mxr(csr_io_rocc_cmd_bits_status_mxr),
    .io_rocc_cmd_bits_status_pum(csr_io_rocc_cmd_bits_status_pum),
    .io_rocc_cmd_bits_status_mprv(csr_io_rocc_cmd_bits_status_mprv),
    .io_rocc_cmd_bits_status_xs(csr_io_rocc_cmd_bits_status_xs),
    .io_rocc_cmd_bits_status_fs(csr_io_rocc_cmd_bits_status_fs),
    .io_rocc_cmd_bits_status_mpp(csr_io_rocc_cmd_bits_status_mpp),
    .io_rocc_cmd_bits_status_hpp(csr_io_rocc_cmd_bits_status_hpp),
    .io_rocc_cmd_bits_status_spp(csr_io_rocc_cmd_bits_status_spp),
    .io_rocc_cmd_bits_status_mpie(csr_io_rocc_cmd_bits_status_mpie),
    .io_rocc_cmd_bits_status_hpie(csr_io_rocc_cmd_bits_status_hpie),
    .io_rocc_cmd_bits_status_spie(csr_io_rocc_cmd_bits_status_spie),
    .io_rocc_cmd_bits_status_upie(csr_io_rocc_cmd_bits_status_upie),
    .io_rocc_cmd_bits_status_mie(csr_io_rocc_cmd_bits_status_mie),
    .io_rocc_cmd_bits_status_hie(csr_io_rocc_cmd_bits_status_hie),
    .io_rocc_cmd_bits_status_sie(csr_io_rocc_cmd_bits_status_sie),
    .io_rocc_cmd_bits_status_uie(csr_io_rocc_cmd_bits_status_uie),
    .io_rocc_resp_ready(csr_io_rocc_resp_ready),
    .io_rocc_resp_valid(csr_io_rocc_resp_valid),
    .io_rocc_resp_bits_rd(csr_io_rocc_resp_bits_rd),
    .io_rocc_resp_bits_data(csr_io_rocc_resp_bits_data),
    .io_rocc_mem_req_ready(csr_io_rocc_mem_req_ready),
    .io_rocc_mem_req_valid(csr_io_rocc_mem_req_valid),
    .io_rocc_mem_req_bits_addr(csr_io_rocc_mem_req_bits_addr),
    .io_rocc_mem_req_bits_tag(csr_io_rocc_mem_req_bits_tag),
    .io_rocc_mem_req_bits_cmd(csr_io_rocc_mem_req_bits_cmd),
    .io_rocc_mem_req_bits_typ(csr_io_rocc_mem_req_bits_typ),
    .io_rocc_mem_req_bits_phys(csr_io_rocc_mem_req_bits_phys),
    .io_rocc_mem_req_bits_data(csr_io_rocc_mem_req_bits_data),
    .io_rocc_mem_s1_kill(csr_io_rocc_mem_s1_kill),
    .io_rocc_mem_s1_data(csr_io_rocc_mem_s1_data),
    .io_rocc_mem_s2_nack(csr_io_rocc_mem_s2_nack),
    .io_rocc_mem_resp_valid(csr_io_rocc_mem_resp_valid),
    .io_rocc_mem_resp_bits_addr(csr_io_rocc_mem_resp_bits_addr),
    .io_rocc_mem_resp_bits_tag(csr_io_rocc_mem_resp_bits_tag),
    .io_rocc_mem_resp_bits_cmd(csr_io_rocc_mem_resp_bits_cmd),
    .io_rocc_mem_resp_bits_typ(csr_io_rocc_mem_resp_bits_typ),
    .io_rocc_mem_resp_bits_data(csr_io_rocc_mem_resp_bits_data),
    .io_rocc_mem_resp_bits_replay(csr_io_rocc_mem_resp_bits_replay),
    .io_rocc_mem_resp_bits_has_data(csr_io_rocc_mem_resp_bits_has_data),
    .io_rocc_mem_resp_bits_data_word_bypass(csr_io_rocc_mem_resp_bits_data_word_bypass),
    .io_rocc_mem_resp_bits_store_data(csr_io_rocc_mem_resp_bits_store_data),
    .io_rocc_mem_replay_next(csr_io_rocc_mem_replay_next),
    .io_rocc_mem_xcpt_ma_ld(csr_io_rocc_mem_xcpt_ma_ld),
    .io_rocc_mem_xcpt_ma_st(csr_io_rocc_mem_xcpt_ma_st),
    .io_rocc_mem_xcpt_pf_ld(csr_io_rocc_mem_xcpt_pf_ld),
    .io_rocc_mem_xcpt_pf_st(csr_io_rocc_mem_xcpt_pf_st),
    .io_rocc_mem_invalidate_lr(csr_io_rocc_mem_invalidate_lr),
    .io_rocc_mem_ordered(csr_io_rocc_mem_ordered),
    .io_rocc_busy(csr_io_rocc_busy),
    .io_rocc_interrupt(csr_io_rocc_interrupt),
    .io_rocc_autl_acquire_ready(csr_io_rocc_autl_acquire_ready),
    .io_rocc_autl_acquire_valid(csr_io_rocc_autl_acquire_valid),
    .io_rocc_autl_acquire_bits_addr_block(csr_io_rocc_autl_acquire_bits_addr_block),
    .io_rocc_autl_acquire_bits_client_xact_id(csr_io_rocc_autl_acquire_bits_client_xact_id),
    .io_rocc_autl_acquire_bits_addr_beat(csr_io_rocc_autl_acquire_bits_addr_beat),
    .io_rocc_autl_acquire_bits_is_builtin_type(csr_io_rocc_autl_acquire_bits_is_builtin_type),
    .io_rocc_autl_acquire_bits_a_type(csr_io_rocc_autl_acquire_bits_a_type),
    .io_rocc_autl_acquire_bits_union(csr_io_rocc_autl_acquire_bits_union),
    .io_rocc_autl_acquire_bits_data(csr_io_rocc_autl_acquire_bits_data),
    .io_rocc_autl_grant_ready(csr_io_rocc_autl_grant_ready),
    .io_rocc_autl_grant_valid(csr_io_rocc_autl_grant_valid),
    .io_rocc_autl_grant_bits_addr_beat(csr_io_rocc_autl_grant_bits_addr_beat),
    .io_rocc_autl_grant_bits_client_xact_id(csr_io_rocc_autl_grant_bits_client_xact_id),
    .io_rocc_autl_grant_bits_manager_xact_id(csr_io_rocc_autl_grant_bits_manager_xact_id),
    .io_rocc_autl_grant_bits_is_builtin_type(csr_io_rocc_autl_grant_bits_is_builtin_type),
    .io_rocc_autl_grant_bits_g_type(csr_io_rocc_autl_grant_bits_g_type),
    .io_rocc_autl_grant_bits_data(csr_io_rocc_autl_grant_bits_data),
    .io_rocc_fpu_req_ready(csr_io_rocc_fpu_req_ready),
    .io_rocc_fpu_req_valid(csr_io_rocc_fpu_req_valid),
    .io_rocc_fpu_req_bits_cmd(csr_io_rocc_fpu_req_bits_cmd),
    .io_rocc_fpu_req_bits_ldst(csr_io_rocc_fpu_req_bits_ldst),
    .io_rocc_fpu_req_bits_wen(csr_io_rocc_fpu_req_bits_wen),
    .io_rocc_fpu_req_bits_ren1(csr_io_rocc_fpu_req_bits_ren1),
    .io_rocc_fpu_req_bits_ren2(csr_io_rocc_fpu_req_bits_ren2),
    .io_rocc_fpu_req_bits_ren3(csr_io_rocc_fpu_req_bits_ren3),
    .io_rocc_fpu_req_bits_swap12(csr_io_rocc_fpu_req_bits_swap12),
    .io_rocc_fpu_req_bits_swap23(csr_io_rocc_fpu_req_bits_swap23),
    .io_rocc_fpu_req_bits_single(csr_io_rocc_fpu_req_bits_single),
    .io_rocc_fpu_req_bits_fromint(csr_io_rocc_fpu_req_bits_fromint),
    .io_rocc_fpu_req_bits_toint(csr_io_rocc_fpu_req_bits_toint),
    .io_rocc_fpu_req_bits_fastpipe(csr_io_rocc_fpu_req_bits_fastpipe),
    .io_rocc_fpu_req_bits_fma(csr_io_rocc_fpu_req_bits_fma),
    .io_rocc_fpu_req_bits_div(csr_io_rocc_fpu_req_bits_div),
    .io_rocc_fpu_req_bits_sqrt(csr_io_rocc_fpu_req_bits_sqrt),
    .io_rocc_fpu_req_bits_round(csr_io_rocc_fpu_req_bits_round),
    .io_rocc_fpu_req_bits_wflags(csr_io_rocc_fpu_req_bits_wflags),
    .io_rocc_fpu_req_bits_rm(csr_io_rocc_fpu_req_bits_rm),
    .io_rocc_fpu_req_bits_typ(csr_io_rocc_fpu_req_bits_typ),
    .io_rocc_fpu_req_bits_in1(csr_io_rocc_fpu_req_bits_in1),
    .io_rocc_fpu_req_bits_in2(csr_io_rocc_fpu_req_bits_in2),
    .io_rocc_fpu_req_bits_in3(csr_io_rocc_fpu_req_bits_in3),
    .io_rocc_fpu_resp_ready(csr_io_rocc_fpu_resp_ready),
    .io_rocc_fpu_resp_valid(csr_io_rocc_fpu_resp_valid),
    .io_rocc_fpu_resp_bits_data(csr_io_rocc_fpu_resp_bits_data),
    .io_rocc_fpu_resp_bits_exc(csr_io_rocc_fpu_resp_bits_exc),
    .io_rocc_exception(csr_io_rocc_exception),
    .io_interrupt(csr_io_interrupt),
    .io_interrupt_cause(csr_io_interrupt_cause),
    .io_bp_0_control_ttype(csr_io_bp_0_control_ttype),
    .io_bp_0_control_dmode(csr_io_bp_0_control_dmode),
    .io_bp_0_control_maskmax(csr_io_bp_0_control_maskmax),
    .io_bp_0_control_reserved(csr_io_bp_0_control_reserved),
    .io_bp_0_control_action(csr_io_bp_0_control_action),
    .io_bp_0_control_chain(csr_io_bp_0_control_chain),
    .io_bp_0_control_zero(csr_io_bp_0_control_zero),
    .io_bp_0_control_tmatch(csr_io_bp_0_control_tmatch),
    .io_bp_0_control_m(csr_io_bp_0_control_m),
    .io_bp_0_control_h(csr_io_bp_0_control_h),
    .io_bp_0_control_s(csr_io_bp_0_control_s),
    .io_bp_0_control_u(csr_io_bp_0_control_u),
    .io_bp_0_control_x(csr_io_bp_0_control_x),
    .io_bp_0_control_w(csr_io_bp_0_control_w),
    .io_bp_0_control_r(csr_io_bp_0_control_r),
    .io_bp_0_address(csr_io_bp_0_address)
  );
  BreakpointUnit bpu (
    .clock(bpu_clock),
    .reset(bpu_reset),
    .io_status_debug(bpu_io_status_debug),
    .io_status_isa(bpu_io_status_isa),
    .io_status_prv(bpu_io_status_prv),
    .io_status_sd(bpu_io_status_sd),
    .io_status_zero3(bpu_io_status_zero3),
    .io_status_sd_rv32(bpu_io_status_sd_rv32),
    .io_status_zero2(bpu_io_status_zero2),
    .io_status_vm(bpu_io_status_vm),
    .io_status_zero1(bpu_io_status_zero1),
    .io_status_mxr(bpu_io_status_mxr),
    .io_status_pum(bpu_io_status_pum),
    .io_status_mprv(bpu_io_status_mprv),
    .io_status_xs(bpu_io_status_xs),
    .io_status_fs(bpu_io_status_fs),
    .io_status_mpp(bpu_io_status_mpp),
    .io_status_hpp(bpu_io_status_hpp),
    .io_status_spp(bpu_io_status_spp),
    .io_status_mpie(bpu_io_status_mpie),
    .io_status_hpie(bpu_io_status_hpie),
    .io_status_spie(bpu_io_status_spie),
    .io_status_upie(bpu_io_status_upie),
    .io_status_mie(bpu_io_status_mie),
    .io_status_hie(bpu_io_status_hie),
    .io_status_sie(bpu_io_status_sie),
    .io_status_uie(bpu_io_status_uie),
    .io_bp_0_control_ttype(bpu_io_bp_0_control_ttype),
    .io_bp_0_control_dmode(bpu_io_bp_0_control_dmode),
    .io_bp_0_control_maskmax(bpu_io_bp_0_control_maskmax),
    .io_bp_0_control_reserved(bpu_io_bp_0_control_reserved),
    .io_bp_0_control_action(bpu_io_bp_0_control_action),
    .io_bp_0_control_chain(bpu_io_bp_0_control_chain),
    .io_bp_0_control_zero(bpu_io_bp_0_control_zero),
    .io_bp_0_control_tmatch(bpu_io_bp_0_control_tmatch),
    .io_bp_0_control_m(bpu_io_bp_0_control_m),
    .io_bp_0_control_h(bpu_io_bp_0_control_h),
    .io_bp_0_control_s(bpu_io_bp_0_control_s),
    .io_bp_0_control_u(bpu_io_bp_0_control_u),
    .io_bp_0_control_x(bpu_io_bp_0_control_x),
    .io_bp_0_control_w(bpu_io_bp_0_control_w),
    .io_bp_0_control_r(bpu_io_bp_0_control_r),
    .io_bp_0_address(bpu_io_bp_0_address),
    .io_pc(bpu_io_pc),
    .io_ea(bpu_io_ea),
    .io_xcpt_if(bpu_io_xcpt_if),
    .io_xcpt_ld(bpu_io_xcpt_ld),
    .io_xcpt_st(bpu_io_xcpt_st),
    .io_debug_if(bpu_io_debug_if),
    .io_debug_ld(bpu_io_debug_ld),
    .io_debug_st(bpu_io_debug_st)
  );
  ALU alu (
    .clock(alu_clock),
    .reset(alu_reset),
    .io_dw(alu_io_dw),
    .io_fn(alu_io_fn),
    .io_in2(alu_io_in2),
    .io_in1(alu_io_in1),
    .io_out(alu_io_out),
    .io_adder_out(alu_io_adder_out),
    .io_cmp_out(alu_io_cmp_out)
  );
  MulDiv div (
    .clock(div_clock),
    .reset(div_reset),
    .io_req_ready(div_io_req_ready),
    .io_req_valid(div_io_req_valid),
    .io_req_bits_fn(div_io_req_bits_fn),
    .io_req_bits_dw(div_io_req_bits_dw),
    .io_req_bits_in1(div_io_req_bits_in1),
    .io_req_bits_in2(div_io_req_bits_in2),
    .io_req_bits_tag(div_io_req_bits_tag),
    .io_kill(div_io_kill),
    .io_resp_ready(div_io_resp_ready),
    .io_resp_valid(div_io_resp_valid),
    .io_resp_bits_data(div_io_resp_bits_data),
    .io_resp_bits_tag(div_io_resp_bits_tag)
  );
  assign io_imem_req_valid = take_pc;
  assign io_imem_req_bits_pc = T_7559;
  assign io_imem_req_bits_speculative = T_7354;
  assign io_imem_resp_ready = ibuf_io_imem_ready;
  assign io_imem_btb_update_valid = T_7582;
  assign io_imem_btb_update_bits_prediction_valid = mem_reg_btb_hit;
  assign io_imem_btb_update_bits_prediction_bits_taken = mem_reg_btb_resp_taken;
  assign io_imem_btb_update_bits_prediction_bits_mask = mem_reg_btb_resp_mask;
  assign io_imem_btb_update_bits_prediction_bits_bridx = mem_reg_btb_resp_bridx;
  assign io_imem_btb_update_bits_prediction_bits_target = mem_reg_btb_resp_target;
  assign io_imem_btb_update_bits_prediction_bits_entry = mem_reg_btb_resp_entry;
  assign io_imem_btb_update_bits_prediction_bits_bht_history = mem_reg_btb_resp_bht_history;
  assign io_imem_btb_update_bits_prediction_bits_bht_value = mem_reg_btb_resp_bht_value;
  assign io_imem_btb_update_bits_pc = T_7601;
  assign io_imem_btb_update_bits_target = io_imem_req_bits_pc;
  assign io_imem_btb_update_bits_taken = GEN_158;
  assign io_imem_btb_update_bits_isValid = T_7585;
  assign io_imem_btb_update_bits_isJump = T_7586;
  assign io_imem_btb_update_bits_isReturn = T_7592;
  assign io_imem_btb_update_bits_br_pc = T_7597;
  assign io_imem_bht_update_valid = T_7605;
  assign io_imem_bht_update_bits_prediction_valid = io_imem_btb_update_bits_prediction_valid;
  assign io_imem_bht_update_bits_prediction_bits_taken = io_imem_btb_update_bits_prediction_bits_taken;
  assign io_imem_bht_update_bits_prediction_bits_mask = io_imem_btb_update_bits_prediction_bits_mask;
  assign io_imem_bht_update_bits_prediction_bits_bridx = io_imem_btb_update_bits_prediction_bits_bridx;
  assign io_imem_bht_update_bits_prediction_bits_target = io_imem_btb_update_bits_prediction_bits_target;
  assign io_imem_bht_update_bits_prediction_bits_entry = io_imem_btb_update_bits_prediction_bits_entry;
  assign io_imem_bht_update_bits_prediction_bits_bht_history = io_imem_btb_update_bits_prediction_bits_bht_history;
  assign io_imem_bht_update_bits_prediction_bits_bht_value = io_imem_btb_update_bits_prediction_bits_bht_value;
  assign io_imem_bht_update_bits_pc = io_imem_btb_update_bits_pc;
  assign io_imem_bht_update_bits_taken = mem_br_taken;
  assign io_imem_bht_update_bits_mispredict = mem_wrong_npc;
  assign io_imem_ras_update_valid = T_7570;
  assign io_imem_ras_update_bits_isCall = T_7610;
  assign io_imem_ras_update_bits_isReturn = io_imem_btb_update_bits_isReturn;
  assign io_imem_ras_update_bits_returnAddr = mem_int_wdata;
  assign io_imem_ras_update_bits_prediction_valid = io_imem_btb_update_bits_prediction_valid;
  assign io_imem_ras_update_bits_prediction_bits_taken = io_imem_btb_update_bits_prediction_bits_taken;
  assign io_imem_ras_update_bits_prediction_bits_mask = io_imem_btb_update_bits_prediction_bits_mask;
  assign io_imem_ras_update_bits_prediction_bits_bridx = io_imem_btb_update_bits_prediction_bits_bridx;
  assign io_imem_ras_update_bits_prediction_bits_target = io_imem_btb_update_bits_prediction_bits_target;
  assign io_imem_ras_update_bits_prediction_bits_entry = io_imem_btb_update_bits_prediction_bits_entry;
  assign io_imem_ras_update_bits_prediction_bits_bht_history = io_imem_btb_update_bits_prediction_bits_bht_history;
  assign io_imem_ras_update_bits_prediction_bits_bht_value = io_imem_btb_update_bits_prediction_bits_bht_value;
  assign io_imem_flush_icache = T_7563;
  assign io_imem_flush_tlb = csr_io_fatc;
  assign io_dmem_req_valid = T_7615;
  assign io_dmem_req_bits_addr = alu_io_adder_out;
  assign io_dmem_req_bits_tag = {{1'd0}, ex_dcache_tag};
  assign io_dmem_req_bits_cmd = ex_ctrl_mem_cmd;
  assign io_dmem_req_bits_typ = ex_ctrl_mem_type;
  assign io_dmem_req_bits_phys = 1'h0;
  assign io_dmem_req_bits_data = GEN_159;
  assign io_dmem_s1_kill = T_7618;
  assign io_dmem_s1_data = T_7617;
  assign io_dmem_invalidate_lr = wb_xcpt;
  assign io_ptw_ptbr_asid = csr_io_ptbr_asid;
  assign io_ptw_ptbr_ppn = csr_io_ptbr_ppn;
  assign io_ptw_invalidate = csr_io_fatc;
  assign io_ptw_status_debug = csr_io_status_debug;
  assign io_ptw_status_isa = csr_io_status_isa;
  assign io_ptw_status_prv = csr_io_status_prv;
  assign io_ptw_status_sd = csr_io_status_sd;
  assign io_ptw_status_zero3 = csr_io_status_zero3;
  assign io_ptw_status_sd_rv32 = csr_io_status_sd_rv32;
  assign io_ptw_status_zero2 = csr_io_status_zero2;
  assign io_ptw_status_vm = csr_io_status_vm;
  assign io_ptw_status_zero1 = csr_io_status_zero1;
  assign io_ptw_status_mxr = csr_io_status_mxr;
  assign io_ptw_status_pum = csr_io_status_pum;
  assign io_ptw_status_mprv = csr_io_status_mprv;
  assign io_ptw_status_xs = csr_io_status_xs;
  assign io_ptw_status_fs = csr_io_status_fs;
  assign io_ptw_status_mpp = csr_io_status_mpp;
  assign io_ptw_status_hpp = csr_io_status_hpp;
  assign io_ptw_status_spp = csr_io_status_spp;
  assign io_ptw_status_mpie = csr_io_status_mpie;
  assign io_ptw_status_hpie = csr_io_status_hpie;
  assign io_ptw_status_spie = csr_io_status_spie;
  assign io_ptw_status_upie = csr_io_status_upie;
  assign io_ptw_status_mie = csr_io_status_mie;
  assign io_ptw_status_hie = csr_io_status_hie;
  assign io_ptw_status_sie = csr_io_status_sie;
  assign io_ptw_status_uie = csr_io_status_uie;
  assign io_fpu_inst = ibuf_io_inst_0_bits_inst_bits;
  assign io_fpu_fromint_data = ex_rs_0;
  assign io_fpu_fcsr_rm = csr_io_fcsr_rm;
  assign io_fpu_dmem_resp_val = T_7614;
  assign io_fpu_dmem_resp_type = io_dmem_resp_bits_typ;
  assign io_fpu_dmem_resp_tag = dmem_resp_waddr;
  assign io_fpu_dmem_resp_data = io_dmem_resp_bits_data_word_bypass;
  assign io_fpu_valid = T_7613;
  assign io_fpu_killx = ctrl_killx;
  assign io_fpu_killm = killm_common;
  assign io_fpu_cp_req_valid = GEN_160;
  assign io_fpu_cp_req_bits_cmd = GEN_161;
  assign io_fpu_cp_req_bits_ldst = GEN_164;
  assign io_fpu_cp_req_bits_wen = GEN_165;
  assign io_fpu_cp_req_bits_ren1 = GEN_167;
  assign io_fpu_cp_req_bits_ren2 = GEN_172;
  assign io_fpu_cp_req_bits_ren3 = GEN_173;
  assign io_fpu_cp_req_bits_swap12 = GEN_174;
  assign io_fpu_cp_req_bits_swap23 = GEN_175;
  assign io_fpu_cp_req_bits_single = GEN_176;
  assign io_fpu_cp_req_bits_fromint = GEN_177;
  assign io_fpu_cp_req_bits_toint = GEN_178;
  assign io_fpu_cp_req_bits_fastpipe = GEN_179;
  assign io_fpu_cp_req_bits_fma = GEN_182;
  assign io_fpu_cp_req_bits_div = GEN_183;
  assign io_fpu_cp_req_bits_sqrt = GEN_184;
  assign io_fpu_cp_req_bits_round = GEN_185;
  assign io_fpu_cp_req_bits_wflags = GEN_186;
  assign io_fpu_cp_req_bits_rm = GEN_187;
  assign io_fpu_cp_req_bits_typ = GEN_188;
  assign io_fpu_cp_req_bits_in1 = GEN_189;
  assign io_fpu_cp_req_bits_in2 = GEN_190;
  assign io_fpu_cp_req_bits_in3 = GEN_191;
  assign io_fpu_cp_resp_ready = GEN_192;
  assign io_rocc_cmd_valid = T_7634;
  assign io_rocc_cmd_bits_inst_funct = T_7656_funct;
  assign io_rocc_cmd_bits_inst_rs2 = T_7656_rs2;
  assign io_rocc_cmd_bits_inst_rs1 = T_7656_rs1;
  assign io_rocc_cmd_bits_inst_xd = T_7656_xd;
  assign io_rocc_cmd_bits_inst_xs1 = T_7656_xs1;
  assign io_rocc_cmd_bits_inst_xs2 = T_7656_xs2;
  assign io_rocc_cmd_bits_inst_rd = T_7656_rd;
  assign io_rocc_cmd_bits_inst_opcode = T_7656_opcode;
  assign io_rocc_cmd_bits_rs1 = wb_reg_wdata;
  assign io_rocc_cmd_bits_rs2 = wb_reg_rs2;
  assign io_rocc_cmd_bits_status_debug = csr_io_status_debug;
  assign io_rocc_cmd_bits_status_isa = csr_io_status_isa;
  assign io_rocc_cmd_bits_status_prv = csr_io_status_prv;
  assign io_rocc_cmd_bits_status_sd = csr_io_status_sd;
  assign io_rocc_cmd_bits_status_zero3 = csr_io_status_zero3;
  assign io_rocc_cmd_bits_status_sd_rv32 = csr_io_status_sd_rv32;
  assign io_rocc_cmd_bits_status_zero2 = csr_io_status_zero2;
  assign io_rocc_cmd_bits_status_vm = csr_io_status_vm;
  assign io_rocc_cmd_bits_status_zero1 = csr_io_status_zero1;
  assign io_rocc_cmd_bits_status_mxr = csr_io_status_mxr;
  assign io_rocc_cmd_bits_status_pum = csr_io_status_pum;
  assign io_rocc_cmd_bits_status_mprv = csr_io_status_mprv;
  assign io_rocc_cmd_bits_status_xs = csr_io_status_xs;
  assign io_rocc_cmd_bits_status_fs = csr_io_status_fs;
  assign io_rocc_cmd_bits_status_mpp = csr_io_status_mpp;
  assign io_rocc_cmd_bits_status_hpp = csr_io_status_hpp;
  assign io_rocc_cmd_bits_status_spp = csr_io_status_spp;
  assign io_rocc_cmd_bits_status_mpie = csr_io_status_mpie;
  assign io_rocc_cmd_bits_status_hpie = csr_io_status_hpie;
  assign io_rocc_cmd_bits_status_spie = csr_io_status_spie;
  assign io_rocc_cmd_bits_status_upie = csr_io_status_upie;
  assign io_rocc_cmd_bits_status_mie = csr_io_status_mie;
  assign io_rocc_cmd_bits_status_hie = csr_io_status_hie;
  assign io_rocc_cmd_bits_status_sie = csr_io_status_sie;
  assign io_rocc_cmd_bits_status_uie = csr_io_status_uie;
  assign io_rocc_resp_ready = GEN_193;
  assign io_rocc_mem_req_ready = GEN_194;
  assign io_rocc_mem_s2_nack = GEN_195;
  assign io_rocc_mem_resp_valid = GEN_196;
  assign io_rocc_mem_resp_bits_addr = GEN_197;
  assign io_rocc_mem_resp_bits_tag = GEN_198;
  assign io_rocc_mem_resp_bits_cmd = GEN_199;
  assign io_rocc_mem_resp_bits_typ = GEN_200;
  assign io_rocc_mem_resp_bits_data = GEN_201;
  assign io_rocc_mem_resp_bits_replay = GEN_202;
  assign io_rocc_mem_resp_bits_has_data = GEN_203;
  assign io_rocc_mem_resp_bits_data_word_bypass = GEN_204;
  assign io_rocc_mem_resp_bits_store_data = GEN_205;
  assign io_rocc_mem_replay_next = GEN_206;
  assign io_rocc_mem_xcpt_ma_ld = GEN_207;
  assign io_rocc_mem_xcpt_ma_st = GEN_208;
  assign io_rocc_mem_xcpt_pf_ld = GEN_209;
  assign io_rocc_mem_xcpt_pf_st = GEN_210;
  assign io_rocc_mem_ordered = GEN_211;
  assign io_rocc_autl_acquire_ready = GEN_212;
  assign io_rocc_autl_grant_valid = GEN_213;
  assign io_rocc_autl_grant_bits_addr_beat = GEN_214;
  assign io_rocc_autl_grant_bits_client_xact_id = GEN_215;
  assign io_rocc_autl_grant_bits_manager_xact_id = GEN_216;
  assign io_rocc_autl_grant_bits_is_builtin_type = GEN_217;
  assign io_rocc_autl_grant_bits_g_type = GEN_218;
  assign io_rocc_autl_grant_bits_data = GEN_219;
  assign io_rocc_fpu_req_ready = GEN_220;
  assign io_rocc_fpu_resp_valid = GEN_221;
  assign io_rocc_fpu_resp_bits_data = GEN_222;
  assign io_rocc_fpu_resp_bits_exc = GEN_223;
  assign io_rocc_exception = T_7637;
  assign take_pc_mem = T_7281;
  assign take_pc_wb = T_7371;
  assign take_pc_id = 1'h0;
  assign take_pc_mem_wb = take_pc_wb | take_pc_mem;
  assign take_pc = take_pc_mem_wb | take_pc_id;
  assign ibuf_clock = clock;
  assign ibuf_reset = reset;
  assign ibuf_io_imem_valid = io_imem_resp_valid;
  assign ibuf_io_imem_bits_btb_valid = io_imem_resp_bits_btb_valid;
  assign ibuf_io_imem_bits_btb_bits_taken = io_imem_resp_bits_btb_bits_taken;
  assign ibuf_io_imem_bits_btb_bits_mask = io_imem_resp_bits_btb_bits_mask;
  assign ibuf_io_imem_bits_btb_bits_bridx = io_imem_resp_bits_btb_bits_bridx;
  assign ibuf_io_imem_bits_btb_bits_target = io_imem_resp_bits_btb_bits_target;
  assign ibuf_io_imem_bits_btb_bits_entry = io_imem_resp_bits_btb_bits_entry;
  assign ibuf_io_imem_bits_btb_bits_bht_history = io_imem_resp_bits_btb_bits_bht_history;
  assign ibuf_io_imem_bits_btb_bits_bht_value = io_imem_resp_bits_btb_bits_bht_value;
  assign ibuf_io_imem_bits_pc = io_imem_resp_bits_pc;
  assign ibuf_io_imem_bits_data = io_imem_resp_bits_data;
  assign ibuf_io_imem_bits_mask = io_imem_resp_bits_mask;
  assign ibuf_io_imem_bits_xcpt_if = io_imem_resp_bits_xcpt_if;
  assign ibuf_io_imem_bits_replay = io_imem_resp_bits_replay;
  assign ibuf_io_kill = take_pc;
  assign ibuf_io_inst_0_ready = T_7566;
  assign id_ctrl_legal = T_6136;
  assign id_ctrl_fp = 1'h0;
  assign id_ctrl_rocc = 1'h0;
  assign id_ctrl_branch = T_6142;
  assign id_ctrl_jal = T_6148;
  assign id_ctrl_jalr = T_6154;
  assign id_ctrl_rxs2 = T_6172;
  assign id_ctrl_rxs1 = T_6193;
  assign id_ctrl_sel_alu2 = T_6228;
  assign id_ctrl_sel_alu1 = T_6245;
  assign id_ctrl_sel_imm = T_6277;
  assign id_ctrl_alu_dw = 1'h1;
  assign id_ctrl_alu_fn = T_6367;
  assign id_ctrl_mem = T_6383;
  assign id_ctrl_mem_cmd = T_6443;
  assign id_ctrl_mem_type = T_6463;
  assign id_ctrl_rfs1 = 1'h0;
  assign id_ctrl_rfs2 = 1'h0;
  assign id_ctrl_rfs3 = 1'h0;
  assign id_ctrl_wfd = 1'h0;
  assign id_ctrl_div = T_6471;
  assign id_ctrl_wxd = T_6501;
  assign id_ctrl_csr = T_6521;
  assign id_ctrl_fence_i = T_6525;
  assign id_ctrl_fence = T_6531;
  assign id_ctrl_amo = T_6537;
  assign id_ctrl_dp = 1'h0;
  assign T_6023 = ibuf_io_inst_0_bits_inst_bits & 32'h505f;
  assign T_6025 = T_6023 == 32'h3;
  assign T_6027 = ibuf_io_inst_0_bits_inst_bits & 32'h207f;
  assign T_6029 = T_6027 == 32'h3;
  assign T_6031 = ibuf_io_inst_0_bits_inst_bits & 32'h607f;
  assign T_6033 = T_6031 == 32'hf;
  assign T_6035 = ibuf_io_inst_0_bits_inst_bits & 32'h5f;
  assign T_6037 = T_6035 == 32'h17;
  assign T_6039 = ibuf_io_inst_0_bits_inst_bits & 32'hfc00007f;
  assign T_6041 = T_6039 == 32'h33;
  assign T_6043 = ibuf_io_inst_0_bits_inst_bits & 32'hbe00707f;
  assign T_6045 = T_6043 == 32'h33;
  assign T_6047 = ibuf_io_inst_0_bits_inst_bits & 32'h707b;
  assign T_6049 = T_6047 == 32'h63;
  assign T_6051 = ibuf_io_inst_0_bits_inst_bits & 32'h7f;
  assign T_6053 = T_6051 == 32'h6f;
  assign T_6055 = ibuf_io_inst_0_bits_inst_bits & 32'hffefffff;
  assign T_6057 = T_6055 == 32'h73;
  assign T_6059 = ibuf_io_inst_0_bits_inst_bits & 32'hfc00305f;
  assign T_6061 = T_6059 == 32'h1013;
  assign T_6065 = T_6027 == 32'h2013;
  assign T_6067 = ibuf_io_inst_0_bits_inst_bits & 32'h1800707f;
  assign T_6069 = T_6067 == 32'h202f;
  assign T_6073 = T_6027 == 32'h2073;
  assign T_6075 = ibuf_io_inst_0_bits_inst_bits & 32'hbc00707f;
  assign T_6077 = T_6075 == 32'h5013;
  assign T_6081 = T_6043 == 32'h5033;
  assign T_6083 = ibuf_io_inst_0_bits_inst_bits & 32'he800707f;
  assign T_6085 = T_6083 == 32'h800202f;
  assign T_6087 = ibuf_io_inst_0_bits_inst_bits & 32'hf9f0707f;
  assign T_6089 = T_6087 == 32'h1000202f;
  assign T_6091 = ibuf_io_inst_0_bits_inst_bits == 32'h10500073;
  assign T_6093 = ibuf_io_inst_0_bits_inst_bits == 32'h30200073;
  assign T_6095 = ibuf_io_inst_0_bits_inst_bits == 32'h7b200073;
  assign T_6097 = ibuf_io_inst_0_bits_inst_bits & 32'h603f;
  assign T_6099 = T_6097 == 32'h23;
  assign T_6101 = ibuf_io_inst_0_bits_inst_bits & 32'h306f;
  assign T_6103 = T_6101 == 32'h1063;
  assign T_6105 = ibuf_io_inst_0_bits_inst_bits & 32'h407f;
  assign T_6107 = T_6105 == 32'h4063;
  assign T_6111 = T_6101 == 32'h3;
  assign T_6114 = T_6025 | T_6029;
  assign T_6115 = T_6114 | T_6033;
  assign T_6116 = T_6115 | T_6037;
  assign T_6117 = T_6116 | T_6041;
  assign T_6118 = T_6117 | T_6045;
  assign T_6119 = T_6118 | T_6049;
  assign T_6120 = T_6119 | T_6053;
  assign T_6121 = T_6120 | T_6057;
  assign T_6122 = T_6121 | T_6061;
  assign T_6123 = T_6122 | T_6065;
  assign T_6124 = T_6123 | T_6069;
  assign T_6125 = T_6124 | T_6073;
  assign T_6126 = T_6125 | T_6077;
  assign T_6127 = T_6126 | T_6081;
  assign T_6128 = T_6127 | T_6085;
  assign T_6129 = T_6128 | T_6089;
  assign T_6130 = T_6129 | T_6091;
  assign T_6131 = T_6130 | T_6093;
  assign T_6132 = T_6131 | T_6095;
  assign T_6133 = T_6132 | T_6099;
  assign T_6134 = T_6133 | T_6103;
  assign T_6135 = T_6134 | T_6107;
  assign T_6136 = T_6135 | T_6111;
  assign T_6140 = ibuf_io_inst_0_bits_inst_bits & 32'h54;
  assign T_6142 = T_6140 == 32'h40;
  assign T_6146 = ibuf_io_inst_0_bits_inst_bits & 32'h48;
  assign T_6148 = T_6146 == 32'h48;
  assign T_6152 = ibuf_io_inst_0_bits_inst_bits & 32'h1c;
  assign T_6154 = T_6152 == 32'h4;
  assign T_6158 = ibuf_io_inst_0_bits_inst_bits & 32'h70;
  assign T_6160 = T_6158 == 32'h20;
  assign T_6162 = ibuf_io_inst_0_bits_inst_bits & 32'h64;
  assign T_6164 = T_6162 == 32'h20;
  assign T_6166 = ibuf_io_inst_0_bits_inst_bits & 32'h34;
  assign T_6168 = T_6166 == 32'h20;
  assign T_6171 = T_6160 | T_6164;
  assign T_6172 = T_6171 | T_6168;
  assign T_6174 = ibuf_io_inst_0_bits_inst_bits & 32'h4004;
  assign T_6176 = T_6174 == 32'h0;
  assign T_6178 = ibuf_io_inst_0_bits_inst_bits & 32'h44;
  assign T_6180 = T_6178 == 32'h0;
  assign T_6182 = ibuf_io_inst_0_bits_inst_bits & 32'h18;
  assign T_6184 = T_6182 == 32'h0;
  assign T_6186 = ibuf_io_inst_0_bits_inst_bits & 32'h2050;
  assign T_6188 = T_6186 == 32'h2000;
  assign T_6191 = T_6176 | T_6180;
  assign T_6192 = T_6191 | T_6184;
  assign T_6193 = T_6192 | T_6188;
  assign T_6195 = ibuf_io_inst_0_bits_inst_bits & 32'h58;
  assign T_6197 = T_6195 == 32'h0;
  assign T_6199 = ibuf_io_inst_0_bits_inst_bits & 32'h20;
  assign T_6201 = T_6199 == 32'h0;
  assign T_6203 = ibuf_io_inst_0_bits_inst_bits & 32'hc;
  assign T_6205 = T_6203 == 32'h4;
  assign T_6207 = ibuf_io_inst_0_bits_inst_bits & 32'h4050;
  assign T_6209 = T_6207 == 32'h4050;
  assign T_6212 = T_6197 | T_6201;
  assign T_6213 = T_6212 | T_6205;
  assign T_6214 = T_6213 | T_6148;
  assign T_6215 = T_6214 | T_6209;
  assign T_6219 = T_6146 == 32'h0;
  assign T_6221 = ibuf_io_inst_0_bits_inst_bits & 32'h4008;
  assign T_6223 = T_6221 == 32'h4000;
  assign T_6226 = T_6219 | T_6184;
  assign T_6227 = T_6226 | T_6223;
  assign T_6228 = {T_6227,T_6215};
  assign T_6230 = ibuf_io_inst_0_bits_inst_bits & 32'h50;
  assign T_6232 = T_6230 == 32'h0;
  assign T_6235 = T_6176 | T_6232;
  assign T_6236 = T_6235 | T_6180;
  assign T_6237 = T_6236 | T_6184;
  assign T_6239 = ibuf_io_inst_0_bits_inst_bits & 32'h24;
  assign T_6241 = T_6239 == 32'h4;
  assign T_6244 = T_6241 | T_6148;
  assign T_6245 = {T_6244,T_6237};
  assign T_6247 = ibuf_io_inst_0_bits_inst_bits & 32'h8;
  assign T_6249 = T_6247 == 32'h8;
  assign T_6253 = T_6178 == 32'h40;
  assign T_6256 = T_6249 | T_6253;
  assign T_6260 = T_6178 == 32'h4;
  assign T_6263 = T_6260 | T_6249;
  assign T_6267 = T_6239 == 32'h0;
  assign T_6269 = ibuf_io_inst_0_bits_inst_bits & 32'h14;
  assign T_6271 = T_6269 == 32'h10;
  assign T_6274 = T_6267 | T_6154;
  assign T_6275 = T_6274 | T_6271;
  assign T_6276 = {T_6275,T_6263};
  assign T_6277 = {T_6276,T_6256};
  assign T_6285 = ibuf_io_inst_0_bits_inst_bits & 32'h3054;
  assign T_6287 = T_6285 == 32'h1010;
  assign T_6289 = ibuf_io_inst_0_bits_inst_bits & 32'h1058;
  assign T_6291 = T_6289 == 32'h1040;
  assign T_6293 = ibuf_io_inst_0_bits_inst_bits & 32'h7044;
  assign T_6295 = T_6293 == 32'h7000;
  assign T_6298 = T_6287 | T_6291;
  assign T_6299 = T_6298 | T_6295;
  assign T_6301 = ibuf_io_inst_0_bits_inst_bits & 32'h4054;
  assign T_6303 = T_6301 == 32'h40;
  assign T_6305 = ibuf_io_inst_0_bits_inst_bits & 32'h3044;
  assign T_6307 = T_6305 == 32'h3000;
  assign T_6309 = ibuf_io_inst_0_bits_inst_bits & 32'h6044;
  assign T_6311 = T_6309 == 32'h6000;
  assign T_6313 = ibuf_io_inst_0_bits_inst_bits & 32'h6018;
  assign T_6315 = T_6313 == 32'h6000;
  assign T_6317 = ibuf_io_inst_0_bits_inst_bits & 32'h40003034;
  assign T_6319 = T_6317 == 32'h40000030;
  assign T_6321 = ibuf_io_inst_0_bits_inst_bits & 32'h40001054;
  assign T_6323 = T_6321 == 32'h40001010;
  assign T_6326 = T_6303 | T_6307;
  assign T_6327 = T_6326 | T_6311;
  assign T_6328 = T_6327 | T_6315;
  assign T_6329 = T_6328 | T_6319;
  assign T_6330 = T_6329 | T_6323;
  assign T_6332 = ibuf_io_inst_0_bits_inst_bits & 32'h2054;
  assign T_6334 = T_6332 == 32'h2010;
  assign T_6336 = ibuf_io_inst_0_bits_inst_bits & 32'h40004054;
  assign T_6338 = T_6336 == 32'h4010;
  assign T_6340 = ibuf_io_inst_0_bits_inst_bits & 32'h5054;
  assign T_6342 = T_6340 == 32'h4010;
  assign T_6344 = ibuf_io_inst_0_bits_inst_bits & 32'h4058;
  assign T_6346 = T_6344 == 32'h4040;
  assign T_6349 = T_6334 | T_6338;
  assign T_6350 = T_6349 | T_6342;
  assign T_6351 = T_6350 | T_6346;
  assign T_6353 = ibuf_io_inst_0_bits_inst_bits & 32'h6054;
  assign T_6355 = T_6353 == 32'h2010;
  assign T_6357 = ibuf_io_inst_0_bits_inst_bits & 32'h40003054;
  assign T_6359 = T_6357 == 32'h40001010;
  assign T_6362 = T_6355 | T_6346;
  assign T_6363 = T_6362 | T_6319;
  assign T_6364 = T_6363 | T_6359;
  assign T_6365 = {T_6330,T_6299};
  assign T_6366 = {T_6364,T_6351};
  assign T_6367 = {T_6366,T_6365};
  assign T_6369 = ibuf_io_inst_0_bits_inst_bits & 32'h605f;
  assign T_6371 = T_6369 == 32'h3;
  assign T_6373 = ibuf_io_inst_0_bits_inst_bits & 32'h707f;
  assign T_6375 = T_6373 == 32'h100f;
  assign T_6378 = T_6371 | T_6025;
  assign T_6379 = T_6378 | T_6029;
  assign T_6380 = T_6379 | T_6375;
  assign T_6381 = T_6380 | T_6069;
  assign T_6382 = T_6381 | T_6085;
  assign T_6383 = T_6382 | T_6089;
  assign T_6385 = ibuf_io_inst_0_bits_inst_bits & 32'h2008;
  assign T_6387 = T_6385 == 32'h8;
  assign T_6389 = ibuf_io_inst_0_bits_inst_bits & 32'h28;
  assign T_6391 = T_6389 == 32'h20;
  assign T_6393 = ibuf_io_inst_0_bits_inst_bits & 32'h18000020;
  assign T_6395 = T_6393 == 32'h18000020;
  assign T_6397 = ibuf_io_inst_0_bits_inst_bits & 32'h20000020;
  assign T_6399 = T_6397 == 32'h20000020;
  assign T_6402 = T_6387 | T_6391;
  assign T_6403 = T_6402 | T_6395;
  assign T_6404 = T_6403 | T_6399;
  assign T_6406 = ibuf_io_inst_0_bits_inst_bits & 32'h10001008;
  assign T_6408 = T_6406 == 32'h10000008;
  assign T_6410 = ibuf_io_inst_0_bits_inst_bits & 32'h40001008;
  assign T_6412 = T_6410 == 32'h40000008;
  assign T_6415 = T_6408 | T_6412;
  assign T_6417 = ibuf_io_inst_0_bits_inst_bits & 32'h8000008;
  assign T_6419 = T_6417 == 32'h8000008;
  assign T_6421 = ibuf_io_inst_0_bits_inst_bits & 32'h10000008;
  assign T_6423 = T_6421 == 32'h10000008;
  assign T_6425 = ibuf_io_inst_0_bits_inst_bits & 32'h80000008;
  assign T_6427 = T_6425 == 32'h80000008;
  assign T_6430 = T_6387 | T_6419;
  assign T_6431 = T_6430 | T_6423;
  assign T_6432 = T_6431 | T_6427;
  assign T_6434 = ibuf_io_inst_0_bits_inst_bits & 32'h18001008;
  assign T_6436 = T_6434 == 32'h8;
  assign T_6440 = {T_6415,T_6404};
  assign T_6441 = {1'h0,T_6436};
  assign T_6442 = {T_6441,T_6432};
  assign T_6443 = {T_6442,T_6440};
  assign T_6445 = ibuf_io_inst_0_bits_inst_bits & 32'h1000;
  assign T_6447 = T_6445 == 32'h1000;
  assign T_6451 = ibuf_io_inst_0_bits_inst_bits & 32'h2000;
  assign T_6453 = T_6451 == 32'h2000;
  assign T_6457 = ibuf_io_inst_0_bits_inst_bits & 32'h4000;
  assign T_6459 = T_6457 == 32'h4000;
  assign T_6462 = {T_6459,T_6453};
  assign T_6463 = {T_6462,T_6447};
  assign T_6469 = ibuf_io_inst_0_bits_inst_bits & 32'h2000074;
  assign T_6471 = T_6469 == 32'h2000030;
  assign T_6477 = T_6389 == 32'h0;
  assign T_6481 = T_6230 == 32'h10;
  assign T_6483 = ibuf_io_inst_0_bits_inst_bits & 32'h1010;
  assign T_6485 = T_6483 == 32'h1010;
  assign T_6489 = T_6385 == 32'h2008;
  assign T_6491 = ibuf_io_inst_0_bits_inst_bits & 32'h2010;
  assign T_6493 = T_6491 == 32'h2010;
  assign T_6496 = T_6477 | T_6205;
  assign T_6497 = T_6496 | T_6481;
  assign T_6498 = T_6497 | T_6148;
  assign T_6499 = T_6498 | T_6485;
  assign T_6500 = T_6499 | T_6489;
  assign T_6501 = T_6500 | T_6493;
  assign T_6503 = ibuf_io_inst_0_bits_inst_bits & 32'h1050;
  assign T_6505 = T_6503 == 32'h1050;
  assign T_6511 = T_6186 == 32'h2050;
  assign T_6515 = ibuf_io_inst_0_bits_inst_bits & 32'h3050;
  assign T_6517 = T_6515 == 32'h50;
  assign T_6520 = {T_6517,T_6511};
  assign T_6521 = {T_6520,T_6505};
  assign T_6523 = ibuf_io_inst_0_bits_inst_bits & 32'h1048;
  assign T_6525 = T_6523 == 32'h1008;
  assign T_6529 = ibuf_io_inst_0_bits_inst_bits & 32'h3048;
  assign T_6531 = T_6529 == 32'h8;
  assign T_6535 = ibuf_io_inst_0_bits_inst_bits & 32'h2048;
  assign T_6537 = T_6535 == 32'h2008;
  assign id_load_use = T_7492;
  assign T_6545_T_6554_addr = T_6553;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign T_6545_T_6554_data = T_6545[T_6545_T_6554_addr];
  `else
  assign T_6545_T_6554_data = T_6545_T_6554_addr >= 5'h1f ? GEN_403[31:0] : T_6545[T_6545_T_6554_addr];
  `endif
  assign T_6545_T_6564_addr = T_6563;
  `ifndef RANDOMIZE_GARBAGE_ASSIGN
  assign T_6545_T_6564_data = T_6545[T_6545_T_6564_addr];
  `else
  assign T_6545_T_6564_data = T_6545_T_6564_addr >= 5'h1f ? GEN_404[31:0] : T_6545[T_6545_T_6564_addr];
  `endif
  assign T_6545_T_7395_data = rf_wdata;
  assign T_6545_T_7395_addr = T_7394;
  assign T_6545_T_7395_mask = GEN_166;
  assign T_6545_T_7395_en = GEN_166;
  assign id_rs_0 = GEN_168;
  assign T_6549 = ibuf_io_inst_0_bits_inst_rs1 == 5'h0;
  assign T_6552 = ibuf_io_inst_0_bits_inst_rs1;
  assign T_6553 = ~ T_6552;
  assign T_6555 = T_6545_T_6554_data;
  assign id_rs_1 = GEN_169;
  assign T_6562 = ibuf_io_inst_0_bits_inst_rs2;
  assign T_6563 = ~ T_6562;
  assign T_6565 = T_6545_T_6564_data;
  assign ctrl_killd = T_7551;
  assign T_6643 = ctrl_killd == 1'h0;
  assign csr_clock = clock;
  assign csr_reset = reset;
  assign csr_io_interrupts_debug = io_interrupts_debug;
  assign csr_io_interrupts_mtip = io_interrupts_mtip;
  assign csr_io_interrupts_msip = io_interrupts_msip;
  assign csr_io_interrupts_meip = io_interrupts_meip;
  assign csr_io_hartid = io_hartid;
  assign csr_io_rw_addr = T_7398;
  assign csr_io_rw_cmd = T_7399;
  assign csr_io_rw_wdata = wb_reg_wdata;
  assign csr_io_exception = wb_reg_xcpt;
  assign csr_io_retire = wb_valid;
  assign csr_io_cause = wb_reg_cause;
  assign csr_io_pc = wb_reg_pc;
  assign csr_io_badaddr = wb_reg_wdata;
  assign csr_io_fcsr_flags_valid = io_fpu_fcsr_flags_valid;
  assign csr_io_fcsr_flags_bits = io_fpu_fcsr_flags_bits;
  assign csr_io_rocc_cmd_ready = GEN_224;
  assign csr_io_rocc_resp_valid = GEN_225;
  assign csr_io_rocc_resp_bits_rd = GEN_226;
  assign csr_io_rocc_resp_bits_data = GEN_227;
  assign csr_io_rocc_mem_req_valid = GEN_228;
  assign csr_io_rocc_mem_req_bits_addr = GEN_229;
  assign csr_io_rocc_mem_req_bits_tag = GEN_230;
  assign csr_io_rocc_mem_req_bits_cmd = GEN_231;
  assign csr_io_rocc_mem_req_bits_typ = GEN_232;
  assign csr_io_rocc_mem_req_bits_phys = GEN_233;
  assign csr_io_rocc_mem_req_bits_data = GEN_234;
  assign csr_io_rocc_mem_s1_kill = GEN_235;
  assign csr_io_rocc_mem_s1_data = GEN_236;
  assign csr_io_rocc_mem_invalidate_lr = GEN_237;
  assign csr_io_rocc_busy = GEN_238;
  assign csr_io_rocc_interrupt = io_rocc_interrupt;
  assign csr_io_rocc_autl_acquire_valid = GEN_239;
  assign csr_io_rocc_autl_acquire_bits_addr_block = GEN_240;
  assign csr_io_rocc_autl_acquire_bits_client_xact_id = GEN_241;
  assign csr_io_rocc_autl_acquire_bits_addr_beat = GEN_242;
  assign csr_io_rocc_autl_acquire_bits_is_builtin_type = GEN_243;
  assign csr_io_rocc_autl_acquire_bits_a_type = GEN_244;
  assign csr_io_rocc_autl_acquire_bits_union = GEN_245;
  assign csr_io_rocc_autl_acquire_bits_data = GEN_246;
  assign csr_io_rocc_autl_grant_ready = GEN_247;
  assign csr_io_rocc_fpu_req_valid = GEN_248;
  assign csr_io_rocc_fpu_req_bits_cmd = GEN_249;
  assign csr_io_rocc_fpu_req_bits_ldst = GEN_250;
  assign csr_io_rocc_fpu_req_bits_wen = GEN_251;
  assign csr_io_rocc_fpu_req_bits_ren1 = GEN_252;
  assign csr_io_rocc_fpu_req_bits_ren2 = GEN_253;
  assign csr_io_rocc_fpu_req_bits_ren3 = GEN_254;
  assign csr_io_rocc_fpu_req_bits_swap12 = GEN_255;
  assign csr_io_rocc_fpu_req_bits_swap23 = GEN_256;
  assign csr_io_rocc_fpu_req_bits_single = GEN_257;
  assign csr_io_rocc_fpu_req_bits_fromint = GEN_258;
  assign csr_io_rocc_fpu_req_bits_toint = GEN_259;
  assign csr_io_rocc_fpu_req_bits_fastpipe = GEN_260;
  assign csr_io_rocc_fpu_req_bits_fma = GEN_261;
  assign csr_io_rocc_fpu_req_bits_div = GEN_262;
  assign csr_io_rocc_fpu_req_bits_sqrt = GEN_263;
  assign csr_io_rocc_fpu_req_bits_round = GEN_264;
  assign csr_io_rocc_fpu_req_bits_wflags = GEN_265;
  assign csr_io_rocc_fpu_req_bits_rm = GEN_266;
  assign csr_io_rocc_fpu_req_bits_typ = GEN_267;
  assign csr_io_rocc_fpu_req_bits_in1 = GEN_268;
  assign csr_io_rocc_fpu_req_bits_in2 = GEN_269;
  assign csr_io_rocc_fpu_req_bits_in3 = GEN_270;
  assign csr_io_rocc_fpu_resp_ready = GEN_271;
  assign id_csr_en = id_ctrl_csr != 3'h0;
  assign id_system_insn = id_ctrl_csr == 3'h4;
  assign T_6646 = id_ctrl_csr == 3'h2;
  assign T_6647 = id_ctrl_csr == 3'h3;
  assign T_6648 = T_6646 | T_6647;
  assign id_csr_ren = T_6648 & T_6549;
  assign id_csr = id_csr_ren ? 3'h5 : id_ctrl_csr;
  assign id_csr_addr = ibuf_io_inst_0_bits_inst_bits[31:20];
  assign T_6652 = id_csr_ren == 1'h0;
  assign T_6653 = id_csr_en & T_6652;
  assign T_6783 = id_csr_addr & 12'h46;
  assign T_6785 = T_6783 == 12'h40;
  assign T_6787 = id_csr_addr & 12'h244;
  assign T_6789 = T_6787 == 12'h240;
  assign T_6792 = T_6785 | T_6789;
  assign T_6795 = T_6792 == 1'h0;
  assign T_6796 = T_6653 & T_6795;
  assign id_csr_flush = id_system_insn | T_6796;
  assign T_6798 = id_ctrl_legal == 1'h0;
  assign T_6799 = csr_io_status_isa[12];
  assign T_6801 = T_6799 == 1'h0;
  assign T_6802 = id_ctrl_div & T_6801;
  assign T_6803 = T_6798 | T_6802;
  assign T_6804 = csr_io_status_isa[0];
  assign T_6806 = T_6804 == 1'h0;
  assign T_6807 = id_ctrl_amo & T_6806;
  assign T_6808 = T_6803 | T_6807;
  assign T_6810 = csr_io_status_fs != 2'h0;
  assign T_6811 = csr_io_status_isa[5];
  assign T_6812 = T_6810 & T_6811;
  assign T_6814 = T_6812 == 1'h0;
  assign T_6815 = id_ctrl_fp & T_6814;
  assign T_6816 = T_6808 | T_6815;
  assign T_6817 = csr_io_status_isa[3];
  assign T_6819 = T_6817 == 1'h0;
  assign T_6820 = id_ctrl_dp & T_6819;
  assign T_6821 = T_6816 | T_6820;
  assign T_6822 = csr_io_status_isa[2];
  assign T_6824 = T_6822 == 1'h0;
  assign T_6825 = ibuf_io_inst_0_bits_rvc & T_6824;
  assign T_6826 = T_6821 | T_6825;
  assign T_6828 = csr_io_status_xs != 2'h0;
  assign T_6829 = csr_io_status_isa[23];
  assign T_6830 = T_6828 & T_6829;
  assign T_6832 = T_6830 == 1'h0;
  assign T_6833 = id_ctrl_rocc & T_6832;
  assign id_illegal_insn = T_6826 | T_6833;
  assign id_amo_aq = ibuf_io_inst_0_bits_inst_bits[26];
  assign id_amo_rl = ibuf_io_inst_0_bits_inst_bits[25];
  assign T_6834 = id_ctrl_amo & id_amo_rl;
  assign id_fence_next = id_ctrl_fence | T_6834;
  assign T_6836 = io_dmem_ordered == 1'h0;
  assign id_mem_busy = T_6836 | io_dmem_req_valid;
  assign T_6842 = wb_reg_valid & wb_ctrl_rocc;
  assign T_6844 = id_reg_fence & id_mem_busy;
  assign T_6845 = id_fence_next | T_6844;
  assign T_6847 = id_ctrl_amo & id_amo_aq;
  assign T_6848 = T_6847 | id_ctrl_fence_i;
  assign T_6849 = id_ctrl_mem | id_ctrl_rocc;
  assign T_6850 = id_reg_fence & T_6849;
  assign T_6851 = T_6848 | T_6850;
  assign T_6852 = id_mem_busy & T_6851;
  assign bpu_clock = clock;
  assign bpu_reset = reset;
  assign bpu_io_status_debug = csr_io_status_debug;
  assign bpu_io_status_isa = csr_io_status_isa;
  assign bpu_io_status_prv = csr_io_status_prv;
  assign bpu_io_status_sd = csr_io_status_sd;
  assign bpu_io_status_zero3 = csr_io_status_zero3;
  assign bpu_io_status_sd_rv32 = csr_io_status_sd_rv32;
  assign bpu_io_status_zero2 = csr_io_status_zero2;
  assign bpu_io_status_vm = csr_io_status_vm;
  assign bpu_io_status_zero1 = csr_io_status_zero1;
  assign bpu_io_status_mxr = csr_io_status_mxr;
  assign bpu_io_status_pum = csr_io_status_pum;
  assign bpu_io_status_mprv = csr_io_status_mprv;
  assign bpu_io_status_xs = csr_io_status_xs;
  assign bpu_io_status_fs = csr_io_status_fs;
  assign bpu_io_status_mpp = csr_io_status_mpp;
  assign bpu_io_status_hpp = csr_io_status_hpp;
  assign bpu_io_status_spp = csr_io_status_spp;
  assign bpu_io_status_mpie = csr_io_status_mpie;
  assign bpu_io_status_hpie = csr_io_status_hpie;
  assign bpu_io_status_spie = csr_io_status_spie;
  assign bpu_io_status_upie = csr_io_status_upie;
  assign bpu_io_status_mie = csr_io_status_mie;
  assign bpu_io_status_hie = csr_io_status_hie;
  assign bpu_io_status_sie = csr_io_status_sie;
  assign bpu_io_status_uie = csr_io_status_uie;
  assign bpu_io_bp_0_control_ttype = csr_io_bp_0_control_ttype;
  assign bpu_io_bp_0_control_dmode = csr_io_bp_0_control_dmode;
  assign bpu_io_bp_0_control_maskmax = csr_io_bp_0_control_maskmax;
  assign bpu_io_bp_0_control_reserved = csr_io_bp_0_control_reserved;
  assign bpu_io_bp_0_control_action = csr_io_bp_0_control_action;
  assign bpu_io_bp_0_control_chain = csr_io_bp_0_control_chain;
  assign bpu_io_bp_0_control_zero = csr_io_bp_0_control_zero;
  assign bpu_io_bp_0_control_tmatch = csr_io_bp_0_control_tmatch;
  assign bpu_io_bp_0_control_m = csr_io_bp_0_control_m;
  assign bpu_io_bp_0_control_h = csr_io_bp_0_control_h;
  assign bpu_io_bp_0_control_s = csr_io_bp_0_control_s;
  assign bpu_io_bp_0_control_u = csr_io_bp_0_control_u;
  assign bpu_io_bp_0_control_x = csr_io_bp_0_control_x;
  assign bpu_io_bp_0_control_w = csr_io_bp_0_control_w;
  assign bpu_io_bp_0_control_r = csr_io_bp_0_control_r;
  assign bpu_io_bp_0_address = csr_io_bp_0_address;
  assign bpu_io_pc = ibuf_io_pc;
  assign bpu_io_ea = mem_reg_wdata;
  assign id_xcpt_if = ibuf_io_inst_0_bits_pf0 | ibuf_io_inst_0_bits_pf1;
  assign T_6857 = csr_io_interrupt | bpu_io_debug_if;
  assign T_6858 = T_6857 | bpu_io_xcpt_if;
  assign T_6859 = T_6858 | id_xcpt_if;
  assign id_xcpt = T_6859 | id_illegal_insn;
  assign T_6860 = id_xcpt_if ? 2'h1 : 2'h2;
  assign T_6861 = bpu_io_xcpt_if ? 2'h3 : T_6860;
  assign T_6862 = bpu_io_debug_if ? 4'hd : {{2'd0}, T_6861};
  assign id_cause = csr_io_interrupt ? csr_io_interrupt_cause : {{28'd0}, T_6862};
  assign ex_waddr = ex_reg_inst[11:7];
  assign mem_waddr = mem_reg_inst[11:7];
  assign wb_waddr = wb_reg_inst[11:7];
  assign T_6866 = ex_reg_valid & ex_ctrl_wxd;
  assign T_6867 = mem_reg_valid & mem_ctrl_wxd;
  assign T_6869 = mem_ctrl_mem == 1'h0;
  assign T_6870 = T_6867 & T_6869;
  assign T_6872 = 5'h0 == ibuf_io_inst_0_bits_inst_rs1;
  assign T_6873 = ex_waddr == ibuf_io_inst_0_bits_inst_rs1;
  assign id_bypass_src_0_1 = T_6866 & T_6873;
  assign T_6874 = mem_waddr == ibuf_io_inst_0_bits_inst_rs1;
  assign id_bypass_src_0_2 = T_6870 & T_6874;
  assign id_bypass_src_0_3 = T_6867 & T_6874;
  assign T_6876 = 5'h0 == ibuf_io_inst_0_bits_inst_rs2;
  assign T_6877 = ex_waddr == ibuf_io_inst_0_bits_inst_rs2;
  assign id_bypass_src_1_1 = T_6866 & T_6877;
  assign T_6878 = mem_waddr == ibuf_io_inst_0_bits_inst_rs2;
  assign id_bypass_src_1_2 = T_6870 & T_6878;
  assign id_bypass_src_1_3 = T_6867 & T_6878;
  assign bypass_mux_0 = 32'h0;
  assign bypass_mux_1 = mem_reg_wdata;
  assign bypass_mux_2 = wb_reg_wdata;
  assign bypass_mux_3 = io_dmem_resp_bits_data_word_bypass;
  assign T_6909 = {ex_reg_rs_msb_0,ex_reg_rs_lsb_0};
  assign GEN_0 = GEN_4;
  assign GEN_2 = 2'h1 == ex_reg_rs_lsb_0 ? bypass_mux_1 : bypass_mux_0;
  assign GEN_3 = 2'h2 == ex_reg_rs_lsb_0 ? bypass_mux_2 : GEN_2;
  assign GEN_4 = 2'h3 == ex_reg_rs_lsb_0 ? bypass_mux_3 : GEN_3;
  assign ex_rs_0 = ex_reg_rs_bypass_0 ? GEN_0 : T_6909;
  assign T_6914 = {ex_reg_rs_msb_1,ex_reg_rs_lsb_1};
  assign GEN_1 = GEN_7;
  assign GEN_5 = 2'h1 == ex_reg_rs_lsb_1 ? bypass_mux_1 : bypass_mux_0;
  assign GEN_6 = 2'h2 == ex_reg_rs_lsb_1 ? bypass_mux_2 : GEN_5;
  assign GEN_7 = 2'h3 == ex_reg_rs_lsb_1 ? bypass_mux_3 : GEN_6;
  assign ex_rs_1 = ex_reg_rs_bypass_1 ? GEN_1 : T_6914;
  assign T_6915 = ex_ctrl_sel_imm == 3'h5;
  assign T_6917 = ex_reg_inst[31];
  assign T_6918 = $signed(T_6917);
  assign T_6919 = T_6915 ? $signed(1'sh0) : $signed(T_6918);
  assign T_6920 = ex_ctrl_sel_imm == 3'h2;
  assign T_6921 = ex_reg_inst[30:20];
  assign T_6922 = $signed(T_6921);
  assign T_6923 = T_6920 ? $signed(T_6922) : $signed({11{T_6919}});
  assign T_6924 = ex_ctrl_sel_imm != 3'h2;
  assign T_6925 = ex_ctrl_sel_imm != 3'h3;
  assign T_6926 = T_6924 & T_6925;
  assign T_6927 = ex_reg_inst[19:12];
  assign T_6928 = $signed(T_6927);
  assign T_6929 = T_6926 ? $signed({8{T_6919}}) : $signed(T_6928);
  assign T_6932 = T_6920 | T_6915;
  assign T_6934 = ex_ctrl_sel_imm == 3'h3;
  assign T_6935 = ex_reg_inst[20];
  assign T_6936 = $signed(T_6935);
  assign T_6937 = ex_ctrl_sel_imm == 3'h1;
  assign T_6938 = ex_reg_inst[7];
  assign T_6939 = $signed(T_6938);
  assign T_6940 = T_6937 ? $signed(T_6939) : $signed(T_6919);
  assign T_6941 = T_6934 ? $signed(T_6936) : $signed(T_6940);
  assign T_6942 = T_6932 ? $signed(1'sh0) : $signed(T_6941);
  assign T_6947 = ex_reg_inst[30:25];
  assign T_6948 = T_6932 ? 6'h0 : T_6947;
  assign T_6951 = ex_ctrl_sel_imm == 3'h0;
  assign T_6953 = T_6951 | T_6937;
  assign T_6954 = ex_reg_inst[11:8];
  assign T_6956 = ex_reg_inst[19:16];
  assign T_6957 = ex_reg_inst[24:21];
  assign T_6958 = T_6915 ? T_6956 : T_6957;
  assign T_6959 = T_6953 ? T_6954 : T_6958;
  assign T_6960 = T_6920 ? 4'h0 : T_6959;
  assign T_6963 = ex_ctrl_sel_imm == 3'h4;
  assign T_6966 = ex_reg_inst[15];
  assign T_6969 = T_6915 ? T_6966 : 1'h0;
  assign T_6971 = T_6963 ? T_6935 : T_6969;
  assign T_6973 = T_6951 ? T_6938 : T_6971;
  assign T_6974 = {T_6948,T_6960};
  assign T_6975 = {T_6974,T_6973};
  assign T_6976 = $unsigned(T_6942);
  assign T_6977 = $unsigned(T_6929);
  assign T_6978 = {T_6977,T_6976};
  assign T_6979 = $unsigned(T_6923);
  assign T_6980 = $unsigned(T_6919);
  assign T_6981 = {T_6980,T_6979};
  assign T_6982 = {T_6981,T_6978};
  assign T_6983 = {T_6982,T_6975};
  assign ex_imm = $signed(T_6983);
  assign T_6985 = $signed(ex_rs_0);
  assign T_6986 = $signed(ex_reg_pc);
  assign T_6987 = 2'h2 == ex_ctrl_sel_alu1;
  assign T_6988 = T_6987 ? $signed(T_6986) : $signed(32'sh0);
  assign T_6989 = 2'h1 == ex_ctrl_sel_alu1;
  assign ex_op1 = T_6989 ? $signed(T_6985) : $signed(T_6988);
  assign T_6991 = $signed(ex_rs_1);
  assign T_6994 = ex_reg_rvc ? $signed(4'sh2) : $signed(4'sh4);
  assign T_6995 = 2'h1 == ex_ctrl_sel_alu2;
  assign T_6996 = T_6995 ? $signed(T_6994) : $signed(4'sh0);
  assign T_6997 = 2'h3 == ex_ctrl_sel_alu2;
  assign T_6998 = T_6997 ? $signed(ex_imm) : $signed({{28{T_6996[3]}},T_6996});
  assign T_6999 = 2'h2 == ex_ctrl_sel_alu2;
  assign ex_op2 = T_6999 ? $signed(T_6991) : $signed(T_6998);
  assign alu_clock = clock;
  assign alu_reset = reset;
  assign alu_io_dw = ex_ctrl_alu_dw;
  assign alu_io_fn = ex_ctrl_alu_fn;
  assign alu_io_in2 = T_7000;
  assign alu_io_in1 = T_7001;
  assign T_7000 = $unsigned(ex_op2);
  assign T_7001 = $unsigned(ex_op1);
  assign div_clock = clock;
  assign div_reset = reset;
  assign div_io_req_valid = T_7002;
  assign div_io_req_bits_fn = ex_ctrl_alu_fn;
  assign div_io_req_bits_dw = ex_ctrl_alu_dw;
  assign div_io_req_bits_in1 = ex_rs_0;
  assign div_io_req_bits_in2 = ex_rs_1;
  assign div_io_req_bits_tag = ex_waddr;
  assign div_io_kill = T_7349;
  assign div_io_resp_ready = GEN_153;
  assign T_7002 = ex_reg_valid & ex_ctrl_div;
  assign T_7006 = take_pc == 1'h0;
  assign T_7007 = T_7006 & ibuf_io_inst_0_valid;
  assign T_7008 = T_7007 & ibuf_io_inst_0_bits_replay;
  assign T_7011 = T_6643 & id_xcpt;
  assign T_7015 = T_7007 & csr_io_interrupt;
  assign GEN_8 = id_xcpt ? id_cause : ex_reg_cause;
  assign GEN_9 = ibuf_io_inst_0_bits_btb_hit ? ibuf_io_btb_resp_taken : ex_reg_btb_resp_taken;
  assign GEN_10 = ibuf_io_inst_0_bits_btb_hit ? ibuf_io_btb_resp_mask : ex_reg_btb_resp_mask;
  assign GEN_11 = ibuf_io_inst_0_bits_btb_hit ? ibuf_io_btb_resp_bridx : ex_reg_btb_resp_bridx;
  assign GEN_12 = ibuf_io_inst_0_bits_btb_hit ? ibuf_io_btb_resp_target : ex_reg_btb_resp_target;
  assign GEN_13 = ibuf_io_inst_0_bits_btb_hit ? ibuf_io_btb_resp_entry : ex_reg_btb_resp_entry;
  assign GEN_14 = ibuf_io_inst_0_bits_btb_hit ? ibuf_io_btb_resp_bht_history : ex_reg_btb_resp_bht_history;
  assign GEN_15 = ibuf_io_inst_0_bits_btb_hit ? ibuf_io_btb_resp_bht_value : ex_reg_btb_resp_bht_value;
  assign T_7019 = bpu_io_xcpt_if == 1'h0;
  assign T_7021 = ibuf_io_inst_0_bits_pf0 == 1'h0;
  assign T_7022 = T_7019 & T_7021;
  assign T_7023 = T_7022 & ibuf_io_inst_0_bits_pf1;
  assign GEN_16 = T_7023 ? 2'h1 : 2'h0;
  assign GEN_17 = T_7023 ? 1'h1 : ibuf_io_inst_0_bits_rvc;
  assign GEN_18 = id_xcpt ? 4'h0 : id_ctrl_alu_fn;
  assign GEN_19 = id_xcpt ? 1'h1 : id_ctrl_alu_dw;
  assign GEN_20 = id_xcpt ? 2'h2 : id_ctrl_sel_alu1;
  assign GEN_21 = id_xcpt ? GEN_16 : id_ctrl_sel_alu2;
  assign GEN_22 = id_xcpt ? GEN_17 : ibuf_io_inst_0_bits_rvc;
  assign T_7025 = id_ctrl_fence_i | id_csr_flush;
  assign T_7026 = T_7025 | csr_io_singleStep;
  assign T_7027 = id_ctrl_jalr & csr_io_status_debug;
  assign GEN_23 = T_7027 ? 1'h1 : T_7026;
  assign GEN_24 = T_7027 ? 1'h1 : id_ctrl_fence_i;
  assign T_7030 = T_6872 | id_bypass_src_0_1;
  assign T_7031 = T_7030 | id_bypass_src_0_2;
  assign T_7032 = T_7031 | id_bypass_src_0_3;
  assign T_7037 = id_bypass_src_0_2 ? 2'h2 : 2'h3;
  assign T_7038 = id_bypass_src_0_1 ? 2'h1 : T_7037;
  assign T_7039 = T_6872 ? 2'h0 : T_7038;
  assign T_7041 = T_7032 == 1'h0;
  assign T_7042 = id_ctrl_rxs1 & T_7041;
  assign T_7043 = id_rs_0[1:0];
  assign T_7044 = id_rs_0[31:2];
  assign GEN_25 = T_7042 ? T_7043 : T_7039;
  assign GEN_26 = T_7042 ? T_7044 : ex_reg_rs_msb_0;
  assign T_7045 = T_6876 | id_bypass_src_1_1;
  assign T_7046 = T_7045 | id_bypass_src_1_2;
  assign T_7047 = T_7046 | id_bypass_src_1_3;
  assign T_7052 = id_bypass_src_1_2 ? 2'h2 : 2'h3;
  assign T_7053 = id_bypass_src_1_1 ? 2'h1 : T_7052;
  assign T_7054 = T_6876 ? 2'h0 : T_7053;
  assign T_7056 = T_7047 == 1'h0;
  assign T_7057 = id_ctrl_rxs2 & T_7056;
  assign T_7058 = id_rs_1[1:0];
  assign T_7059 = id_rs_1[31:2];
  assign GEN_27 = T_7057 ? T_7058 : T_7054;
  assign GEN_28 = T_7057 ? T_7059 : ex_reg_rs_msb_1;
  assign GEN_29 = T_6643 ? id_ctrl_legal : ex_ctrl_legal;
  assign GEN_30 = T_6643 ? id_ctrl_fp : ex_ctrl_fp;
  assign GEN_31 = T_6643 ? id_ctrl_rocc : ex_ctrl_rocc;
  assign GEN_32 = T_6643 ? id_ctrl_branch : ex_ctrl_branch;
  assign GEN_33 = T_6643 ? id_ctrl_jal : ex_ctrl_jal;
  assign GEN_34 = T_6643 ? id_ctrl_jalr : ex_ctrl_jalr;
  assign GEN_35 = T_6643 ? id_ctrl_rxs2 : ex_ctrl_rxs2;
  assign GEN_36 = T_6643 ? id_ctrl_rxs1 : ex_ctrl_rxs1;
  assign GEN_37 = T_6643 ? GEN_21 : ex_ctrl_sel_alu2;
  assign GEN_38 = T_6643 ? GEN_20 : ex_ctrl_sel_alu1;
  assign GEN_39 = T_6643 ? id_ctrl_sel_imm : ex_ctrl_sel_imm;
  assign GEN_40 = T_6643 ? GEN_19 : ex_ctrl_alu_dw;
  assign GEN_41 = T_6643 ? GEN_18 : ex_ctrl_alu_fn;
  assign GEN_42 = T_6643 ? id_ctrl_mem : ex_ctrl_mem;
  assign GEN_43 = T_6643 ? id_ctrl_mem_cmd : ex_ctrl_mem_cmd;
  assign GEN_44 = T_6643 ? id_ctrl_mem_type : ex_ctrl_mem_type;
  assign GEN_45 = T_6643 ? id_ctrl_rfs1 : ex_ctrl_rfs1;
  assign GEN_46 = T_6643 ? id_ctrl_rfs2 : ex_ctrl_rfs2;
  assign GEN_47 = T_6643 ? id_ctrl_rfs3 : ex_ctrl_rfs3;
  assign GEN_48 = T_6643 ? id_ctrl_wfd : ex_ctrl_wfd;
  assign GEN_49 = T_6643 ? id_ctrl_div : ex_ctrl_div;
  assign GEN_50 = T_6643 ? id_ctrl_wxd : ex_ctrl_wxd;
  assign GEN_51 = T_6643 ? id_csr : ex_ctrl_csr;
  assign GEN_52 = T_6643 ? GEN_24 : ex_ctrl_fence_i;
  assign GEN_53 = T_6643 ? id_ctrl_fence : ex_ctrl_fence;
  assign GEN_54 = T_6643 ? id_ctrl_amo : ex_ctrl_amo;
  assign GEN_55 = T_6643 ? id_ctrl_dp : ex_ctrl_dp;
  assign GEN_56 = T_6643 ? GEN_22 : ex_reg_rvc;
  assign GEN_57 = T_6643 ? GEN_23 : ex_reg_flush_pipe;
  assign GEN_58 = T_6643 ? id_load_use : ex_reg_load_use;
  assign GEN_59 = T_6643 ? T_7032 : ex_reg_rs_bypass_0;
  assign GEN_60 = T_6643 ? GEN_25 : ex_reg_rs_lsb_0;
  assign GEN_61 = T_6643 ? GEN_26 : ex_reg_rs_msb_0;
  assign GEN_62 = T_6643 ? T_7047 : ex_reg_rs_bypass_1;
  assign GEN_63 = T_6643 ? GEN_27 : ex_reg_rs_lsb_1;
  assign GEN_64 = T_6643 ? GEN_28 : ex_reg_rs_msb_1;
  assign T_7062 = T_6643 | csr_io_interrupt;
  assign T_7063 = T_7062 | ibuf_io_inst_0_bits_replay;
  assign GEN_65 = T_7063 ? ibuf_io_inst_0_bits_inst_bits : ex_reg_inst;
  assign GEN_66 = T_7063 ? ibuf_io_pc : ex_reg_pc;
  assign T_7064 = ex_reg_valid | ex_reg_replay;
  assign ex_pc_valid = T_7064 | ex_reg_xcpt_interrupt;
  assign T_7066 = io_dmem_resp_valid == 1'h0;
  assign wb_dcache_miss = wb_ctrl_mem & T_7066;
  assign T_7068 = io_dmem_req_ready == 1'h0;
  assign T_7069 = ex_ctrl_mem & T_7068;
  assign T_7071 = div_io_req_ready == 1'h0;
  assign T_7072 = ex_ctrl_div & T_7071;
  assign replay_ex_structural = T_7069 | T_7072;
  assign replay_ex_load_use = wb_dcache_miss & ex_reg_load_use;
  assign T_7073 = replay_ex_structural | replay_ex_load_use;
  assign T_7074 = ex_reg_valid & T_7073;
  assign replay_ex = ex_reg_replay | T_7074;
  assign T_7075 = take_pc_mem_wb | replay_ex;
  assign T_7077 = ex_reg_valid == 1'h0;
  assign ctrl_killx = T_7075 | T_7077;
  assign T_7078 = ex_ctrl_mem_cmd == 5'h7;
  assign T_7086_0 = 3'h0;
  assign T_7086_1 = 3'h4;
  assign T_7086_2 = 3'h1;
  assign T_7086_3 = 3'h5;
  assign T_7093 = T_7086_0 == ex_ctrl_mem_type;
  assign T_7094 = T_7086_1 == ex_ctrl_mem_type;
  assign T_7095 = T_7086_2 == ex_ctrl_mem_type;
  assign T_7096 = T_7086_3 == ex_ctrl_mem_type;
  assign T_7099 = T_7093 | T_7094;
  assign T_7100 = T_7099 | T_7095;
  assign T_7101 = T_7100 | T_7096;
  assign ex_slow_bypass = T_7078 | T_7101;
  assign T_7102 = ex_reg_xcpt_interrupt | ex_reg_xcpt;
  assign T_7103 = ex_ctrl_fp & io_fpu_illegal_rm;
  assign ex_xcpt = T_7102 | T_7103;
  assign ex_cause = T_7102 ? ex_reg_cause : 32'h2;
  assign mem_br_taken = mem_reg_wdata[0];
  assign T_7105 = $signed(mem_reg_pc);
  assign T_7106 = mem_ctrl_branch & mem_br_taken;
  assign T_7109 = mem_reg_inst[31];
  assign T_7110 = $signed(T_7109);
  assign T_7115 = {11{T_7110}};
  assign T_7119 = mem_reg_inst[19:12];
  assign T_7120 = $signed(T_7119);
  assign T_7121 = {8{T_7110}};
  assign T_7127 = mem_reg_inst[20];
  assign T_7128 = $signed(T_7127);
  assign T_7130 = mem_reg_inst[7];
  assign T_7131 = $signed(T_7130);
  assign T_7139 = mem_reg_inst[30:25];
  assign T_7146 = mem_reg_inst[11:8];
  assign T_7149 = mem_reg_inst[24:21];
  assign T_7166 = {T_7139,T_7146};
  assign T_7167 = {T_7166,1'h0};
  assign T_7168 = $unsigned(T_7131);
  assign T_7169 = $unsigned(T_7121);
  assign T_7170 = {T_7169,T_7168};
  assign T_7171 = $unsigned(T_7115);
  assign T_7172 = $unsigned(T_7110);
  assign T_7173 = {T_7172,T_7171};
  assign T_7174 = {T_7173,T_7170};
  assign T_7175 = {T_7174,T_7167};
  assign T_7176 = $signed(T_7175);
  assign T_7238 = {T_7139,T_7149};
  assign T_7239 = {T_7238,1'h0};
  assign T_7240 = $unsigned(T_7128);
  assign T_7241 = $unsigned(T_7120);
  assign T_7242 = {T_7241,T_7240};
  assign T_7246 = {T_7173,T_7242};
  assign T_7247 = {T_7246,T_7239};
  assign T_7248 = $signed(T_7247);
  assign T_7251 = mem_reg_rvc ? $signed(4'sh2) : $signed(4'sh4);
  assign T_7252 = mem_ctrl_jal ? $signed(T_7248) : $signed({{28{T_7251[3]}},T_7251});
  assign T_7253 = T_7106 ? $signed(T_7176) : $signed(T_7252);
  assign T_7254 = $signed(T_7105) + $signed(T_7253);
  assign T_7255 = T_7254[31:0];
  assign mem_br_target = $signed(T_7255);
  assign T_7256 = $signed(mem_reg_wdata);
  assign T_7257 = mem_ctrl_jalr ? $signed(T_7256) : $signed(mem_br_target);
  assign T_7259 = $signed(T_7257) & $signed(32'shfffffffe);
  assign T_7260 = $signed(T_7259);
  assign mem_npc = $unsigned(T_7260);
  assign T_7261 = mem_npc != ex_reg_pc;
  assign T_7262 = mem_npc != ibuf_io_pc;
  assign T_7264 = ibuf_io_inst_0_valid ? T_7262 : 1'h1;
  assign mem_wrong_npc = ex_pc_valid ? T_7261 : T_7264;
  assign T_7268 = mem_npc[1];
  assign mem_npc_misaligned = T_6824 & T_7268;
  assign T_7270 = mem_reg_xcpt == 1'h0;
  assign T_7271 = mem_ctrl_jalr ^ mem_npc_misaligned;
  assign T_7272 = T_7270 & T_7271;
  assign T_7274 = T_7272 ? $signed(mem_br_target) : $signed(T_7256);
  assign mem_int_wdata = $unsigned(T_7274);
  assign T_7275 = mem_ctrl_branch | mem_ctrl_jalr;
  assign mem_cfi = T_7275 | mem_ctrl_jal;
  assign T_7277 = T_7106 | mem_ctrl_jalr;
  assign mem_cfi_taken = T_7277 | mem_ctrl_jal;
  assign T_7280 = mem_cfi_taken | mem_reg_flush_pipe;
  assign T_7281 = mem_reg_valid & T_7280;
  assign T_7283 = ctrl_killx == 1'h0;
  assign T_7285 = take_pc_mem_wb == 1'h0;
  assign T_7286 = T_7285 & replay_ex;
  assign T_7289 = T_7283 & ex_xcpt;
  assign T_7292 = T_7285 & ex_reg_xcpt_interrupt;
  assign GEN_67 = ex_xcpt ? ex_cause : mem_reg_cause;
  assign T_7293 = ex_ctrl_mem_cmd == 5'h0;
  assign T_7294 = ex_ctrl_mem_cmd == 5'h6;
  assign T_7295 = T_7293 | T_7294;
  assign T_7297 = T_7295 | T_7078;
  assign T_7298 = ex_ctrl_mem_cmd[3];
  assign T_7299 = ex_ctrl_mem_cmd == 5'h4;
  assign T_7300 = T_7298 | T_7299;
  assign T_7301 = T_7297 | T_7300;
  assign T_7302 = ex_ctrl_mem & T_7301;
  assign T_7303 = ex_ctrl_mem_cmd == 5'h1;
  assign T_7305 = T_7303 | T_7078;
  assign T_7309 = T_7305 | T_7300;
  assign T_7310 = ex_ctrl_mem & T_7309;
  assign GEN_68 = ex_reg_btb_hit ? ex_reg_btb_resp_taken : mem_reg_btb_resp_taken;
  assign GEN_69 = ex_reg_btb_hit ? ex_reg_btb_resp_mask : mem_reg_btb_resp_mask;
  assign GEN_70 = ex_reg_btb_hit ? ex_reg_btb_resp_bridx : mem_reg_btb_resp_bridx;
  assign GEN_71 = ex_reg_btb_hit ? ex_reg_btb_resp_target : mem_reg_btb_resp_target;
  assign GEN_72 = ex_reg_btb_hit ? ex_reg_btb_resp_entry : mem_reg_btb_resp_entry;
  assign GEN_73 = ex_reg_btb_hit ? ex_reg_btb_resp_bht_history : mem_reg_btb_resp_bht_history;
  assign GEN_74 = ex_reg_btb_hit ? ex_reg_btb_resp_bht_value : mem_reg_btb_resp_bht_value;
  assign T_7311 = ex_ctrl_mem | ex_ctrl_rocc;
  assign T_7312 = ex_ctrl_rxs2 & T_7311;
  assign GEN_75 = T_7312 ? ex_rs_1 : mem_reg_rs2;
  assign GEN_76 = ex_pc_valid ? ex_ctrl_legal : mem_ctrl_legal;
  assign GEN_77 = ex_pc_valid ? ex_ctrl_fp : mem_ctrl_fp;
  assign GEN_78 = ex_pc_valid ? ex_ctrl_rocc : mem_ctrl_rocc;
  assign GEN_79 = ex_pc_valid ? ex_ctrl_branch : mem_ctrl_branch;
  assign GEN_80 = ex_pc_valid ? ex_ctrl_jal : mem_ctrl_jal;
  assign GEN_81 = ex_pc_valid ? ex_ctrl_jalr : mem_ctrl_jalr;
  assign GEN_82 = ex_pc_valid ? ex_ctrl_rxs2 : mem_ctrl_rxs2;
  assign GEN_83 = ex_pc_valid ? ex_ctrl_rxs1 : mem_ctrl_rxs1;
  assign GEN_84 = ex_pc_valid ? ex_ctrl_sel_alu2 : mem_ctrl_sel_alu2;
  assign GEN_85 = ex_pc_valid ? ex_ctrl_sel_alu1 : mem_ctrl_sel_alu1;
  assign GEN_86 = ex_pc_valid ? ex_ctrl_sel_imm : mem_ctrl_sel_imm;
  assign GEN_87 = ex_pc_valid ? ex_ctrl_alu_dw : mem_ctrl_alu_dw;
  assign GEN_88 = ex_pc_valid ? ex_ctrl_alu_fn : mem_ctrl_alu_fn;
  assign GEN_89 = ex_pc_valid ? ex_ctrl_mem : mem_ctrl_mem;
  assign GEN_90 = ex_pc_valid ? ex_ctrl_mem_cmd : mem_ctrl_mem_cmd;
  assign GEN_91 = ex_pc_valid ? ex_ctrl_mem_type : mem_ctrl_mem_type;
  assign GEN_92 = ex_pc_valid ? ex_ctrl_rfs1 : mem_ctrl_rfs1;
  assign GEN_93 = ex_pc_valid ? ex_ctrl_rfs2 : mem_ctrl_rfs2;
  assign GEN_94 = ex_pc_valid ? ex_ctrl_rfs3 : mem_ctrl_rfs3;
  assign GEN_95 = ex_pc_valid ? ex_ctrl_wfd : mem_ctrl_wfd;
  assign GEN_96 = ex_pc_valid ? ex_ctrl_div : mem_ctrl_div;
  assign GEN_97 = ex_pc_valid ? ex_ctrl_wxd : mem_ctrl_wxd;
  assign GEN_98 = ex_pc_valid ? ex_ctrl_csr : mem_ctrl_csr;
  assign GEN_99 = ex_pc_valid ? ex_ctrl_fence_i : mem_ctrl_fence_i;
  assign GEN_100 = ex_pc_valid ? ex_ctrl_fence : mem_ctrl_fence;
  assign GEN_101 = ex_pc_valid ? ex_ctrl_amo : mem_ctrl_amo;
  assign GEN_102 = ex_pc_valid ? ex_ctrl_dp : mem_ctrl_dp;
  assign GEN_103 = ex_pc_valid ? ex_reg_rvc : mem_reg_rvc;
  assign GEN_104 = ex_pc_valid ? T_7302 : mem_reg_load;
  assign GEN_105 = ex_pc_valid ? T_7310 : mem_reg_store;
  assign GEN_106 = ex_pc_valid ? ex_reg_btb_hit : mem_reg_btb_hit;
  assign GEN_107 = ex_pc_valid ? GEN_68 : mem_reg_btb_resp_taken;
  assign GEN_108 = ex_pc_valid ? GEN_69 : mem_reg_btb_resp_mask;
  assign GEN_109 = ex_pc_valid ? GEN_70 : mem_reg_btb_resp_bridx;
  assign GEN_110 = ex_pc_valid ? GEN_71 : mem_reg_btb_resp_target;
  assign GEN_111 = ex_pc_valid ? GEN_72 : mem_reg_btb_resp_entry;
  assign GEN_112 = ex_pc_valid ? GEN_73 : mem_reg_btb_resp_bht_history;
  assign GEN_113 = ex_pc_valid ? GEN_74 : mem_reg_btb_resp_bht_value;
  assign GEN_114 = ex_pc_valid ? ex_reg_flush_pipe : mem_reg_flush_pipe;
  assign GEN_115 = ex_pc_valid ? ex_slow_bypass : mem_reg_slow_bypass;
  assign GEN_116 = ex_pc_valid ? ex_reg_inst : mem_reg_inst;
  assign GEN_117 = ex_pc_valid ? ex_reg_pc : mem_reg_pc;
  assign GEN_118 = ex_pc_valid ? alu_io_out : mem_reg_wdata;
  assign GEN_119 = ex_pc_valid ? GEN_75 : mem_reg_rs2;
  assign T_7313 = mem_reg_load & bpu_io_xcpt_ld;
  assign T_7314 = mem_reg_store & bpu_io_xcpt_st;
  assign mem_breakpoint = T_7313 | T_7314;
  assign T_7315 = mem_reg_load & bpu_io_debug_ld;
  assign T_7316 = mem_reg_store & bpu_io_debug_st;
  assign mem_debug_breakpoint = T_7315 | T_7316;
  assign T_7320 = mem_ctrl_mem & io_dmem_xcpt_ma_st;
  assign T_7322 = mem_ctrl_mem & io_dmem_xcpt_ma_ld;
  assign T_7324 = mem_ctrl_mem & io_dmem_xcpt_pf_st;
  assign T_7326 = mem_ctrl_mem & io_dmem_xcpt_pf_ld;
  assign T_7328 = mem_debug_breakpoint | mem_breakpoint;
  assign T_7329 = T_7328 | mem_npc_misaligned;
  assign T_7330 = T_7329 | T_7320;
  assign T_7331 = T_7330 | T_7322;
  assign T_7332 = T_7331 | T_7324;
  assign mem_new_xcpt = T_7332 | T_7326;
  assign T_7333 = T_7324 ? 3'h7 : 3'h5;
  assign T_7334 = T_7322 ? 3'h4 : T_7333;
  assign T_7335 = T_7320 ? 3'h6 : T_7334;
  assign T_7336 = mem_npc_misaligned ? 3'h0 : T_7335;
  assign T_7337 = mem_breakpoint ? 3'h3 : T_7336;
  assign mem_new_cause = mem_debug_breakpoint ? 4'hd : {{1'd0}, T_7337};
  assign T_7338 = mem_reg_xcpt_interrupt | mem_reg_xcpt;
  assign T_7339 = mem_reg_valid & mem_new_xcpt;
  assign mem_xcpt = T_7338 | T_7339;
  assign mem_cause = T_7338 ? mem_reg_cause : {{28'd0}, mem_new_cause};
  assign dcache_kill_mem = T_6867 & io_dmem_replay_next;
  assign T_7341 = mem_reg_valid & mem_ctrl_fp;
  assign fpu_kill_mem = T_7341 & io_fpu_nack_mem;
  assign T_7342 = dcache_kill_mem | mem_reg_replay;
  assign replay_mem = T_7342 | fpu_kill_mem;
  assign T_7343 = dcache_kill_mem | take_pc_wb;
  assign T_7344 = T_7343 | mem_reg_xcpt;
  assign T_7346 = mem_reg_valid == 1'h0;
  assign killm_common = T_7344 | T_7346;
  assign T_7347 = div_io_req_ready & div_io_req_valid;
  assign T_7349 = killm_common & T_7348;
  assign T_7350 = killm_common | mem_xcpt;
  assign ctrl_killm = T_7350 | fpu_kill_mem;
  assign T_7352 = ctrl_killm == 1'h0;
  assign T_7354 = take_pc_wb == 1'h0;
  assign T_7355 = replay_mem & T_7354;
  assign T_7358 = mem_xcpt & T_7354;
  assign GEN_120 = mem_xcpt ? mem_cause : wb_reg_cause;
  assign T_7359 = mem_reg_valid | mem_reg_replay;
  assign T_7360 = T_7359 | mem_reg_xcpt_interrupt;
  assign T_7363 = T_7270 & mem_ctrl_fp;
  assign T_7364 = T_7363 & mem_ctrl_wxd;
  assign T_7365 = T_7364 ? io_fpu_toint_data : mem_int_wdata;
  assign GEN_121 = mem_ctrl_rocc ? mem_reg_rs2 : wb_reg_rs2;
  assign GEN_122 = T_7360 ? mem_ctrl_legal : wb_ctrl_legal;
  assign GEN_123 = T_7360 ? mem_ctrl_fp : wb_ctrl_fp;
  assign GEN_124 = T_7360 ? mem_ctrl_rocc : wb_ctrl_rocc;
  assign GEN_125 = T_7360 ? mem_ctrl_branch : wb_ctrl_branch;
  assign GEN_126 = T_7360 ? mem_ctrl_jal : wb_ctrl_jal;
  assign GEN_127 = T_7360 ? mem_ctrl_jalr : wb_ctrl_jalr;
  assign GEN_128 = T_7360 ? mem_ctrl_rxs2 : wb_ctrl_rxs2;
  assign GEN_129 = T_7360 ? mem_ctrl_rxs1 : wb_ctrl_rxs1;
  assign GEN_130 = T_7360 ? mem_ctrl_sel_alu2 : wb_ctrl_sel_alu2;
  assign GEN_131 = T_7360 ? mem_ctrl_sel_alu1 : wb_ctrl_sel_alu1;
  assign GEN_132 = T_7360 ? mem_ctrl_sel_imm : wb_ctrl_sel_imm;
  assign GEN_133 = T_7360 ? mem_ctrl_alu_dw : wb_ctrl_alu_dw;
  assign GEN_134 = T_7360 ? mem_ctrl_alu_fn : wb_ctrl_alu_fn;
  assign GEN_135 = T_7360 ? mem_ctrl_mem : wb_ctrl_mem;
  assign GEN_136 = T_7360 ? mem_ctrl_mem_cmd : wb_ctrl_mem_cmd;
  assign GEN_137 = T_7360 ? mem_ctrl_mem_type : wb_ctrl_mem_type;
  assign GEN_138 = T_7360 ? mem_ctrl_rfs1 : wb_ctrl_rfs1;
  assign GEN_139 = T_7360 ? mem_ctrl_rfs2 : wb_ctrl_rfs2;
  assign GEN_140 = T_7360 ? mem_ctrl_rfs3 : wb_ctrl_rfs3;
  assign GEN_141 = T_7360 ? mem_ctrl_wfd : wb_ctrl_wfd;
  assign GEN_142 = T_7360 ? mem_ctrl_div : wb_ctrl_div;
  assign GEN_143 = T_7360 ? mem_ctrl_wxd : wb_ctrl_wxd;
  assign GEN_144 = T_7360 ? mem_ctrl_csr : wb_ctrl_csr;
  assign GEN_145 = T_7360 ? mem_ctrl_fence_i : wb_ctrl_fence_i;
  assign GEN_146 = T_7360 ? mem_ctrl_fence : wb_ctrl_fence;
  assign GEN_147 = T_7360 ? mem_ctrl_amo : wb_ctrl_amo;
  assign GEN_148 = T_7360 ? mem_ctrl_dp : wb_ctrl_dp;
  assign GEN_149 = T_7360 ? T_7365 : wb_reg_wdata;
  assign GEN_150 = T_7360 ? GEN_121 : wb_reg_rs2;
  assign GEN_151 = T_7360 ? mem_reg_inst : wb_reg_inst;
  assign GEN_152 = T_7360 ? mem_reg_pc : wb_reg_pc;
  assign wb_wxd = wb_reg_valid & wb_ctrl_wxd;
  assign T_7366 = wb_ctrl_div | wb_dcache_miss;
  assign wb_set_sboard = T_7366 | wb_ctrl_rocc;
  assign replay_wb_common = io_dmem_s2_nack | wb_reg_replay;
  assign T_7369 = io_rocc_cmd_ready == 1'h0;
  assign replay_wb_rocc = T_6842 & T_7369;
  assign replay_wb = replay_wb_common | replay_wb_rocc;
  assign wb_xcpt = wb_reg_xcpt | csr_io_csr_xcpt;
  assign T_7370 = replay_wb | wb_xcpt;
  assign T_7371 = T_7370 | csr_io_eret;
  assign T_7372 = io_dmem_resp_bits_tag[0];
  assign dmem_resp_xpu = T_7372 == 1'h0;
  assign dmem_resp_waddr = io_dmem_resp_bits_tag[5:1];
  assign dmem_resp_valid = io_dmem_resp_valid & io_dmem_resp_bits_has_data;
  assign dmem_resp_replay = dmem_resp_valid & io_dmem_resp_bits_replay;
  assign T_7377 = wb_wxd == 1'h0;
  assign ll_wdata = div_io_resp_bits_data;
  assign ll_waddr = GEN_154;
  assign T_7378 = div_io_resp_ready & div_io_resp_valid;
  assign ll_wen = GEN_155;
  assign T_7379 = dmem_resp_replay & dmem_resp_xpu;
  assign GEN_153 = T_7379 ? 1'h0 : T_7377;
  assign GEN_154 = T_7379 ? dmem_resp_waddr : div_io_resp_bits_tag;
  assign GEN_155 = T_7379 ? 1'h1 : T_7378;
  assign T_7383 = replay_wb == 1'h0;
  assign T_7384 = wb_reg_valid & T_7383;
  assign T_7386 = wb_xcpt == 1'h0;
  assign wb_valid = T_7384 & T_7386;
  assign wb_wen = wb_valid & wb_ctrl_wxd;
  assign rf_wen = wb_wen | ll_wen;
  assign rf_waddr = ll_wen ? ll_waddr : wb_waddr;
  assign T_7387 = dmem_resp_valid & dmem_resp_xpu;
  assign T_7388 = wb_ctrl_csr != 3'h0;
  assign T_7389 = T_7388 ? csr_io_rw_rdata : wb_reg_wdata;
  assign T_7390 = ll_wen ? ll_wdata : T_7389;
  assign rf_wdata = T_7387 ? io_dmem_resp_bits_data : T_7390;
  assign T_7392 = rf_waddr != 5'h0;
  assign T_7394 = ~ rf_waddr;
  assign T_7396 = rf_waddr == ibuf_io_inst_0_bits_inst_rs1;
  assign GEN_156 = T_7396 ? rf_wdata : T_6555;
  assign T_7397 = rf_waddr == ibuf_io_inst_0_bits_inst_rs2;
  assign GEN_157 = T_7397 ? rf_wdata : T_6565;
  assign GEN_162 = T_7392 ? GEN_156 : T_6555;
  assign GEN_163 = T_7392 ? GEN_157 : T_6565;
  assign GEN_166 = rf_wen ? T_7392 : 1'h0;
  assign GEN_168 = rf_wen ? GEN_162 : T_6555;
  assign GEN_169 = rf_wen ? GEN_163 : T_6565;
  assign T_7398 = wb_reg_inst[31:20];
  assign T_7399 = wb_reg_valid ? wb_ctrl_csr : 3'h0;
  assign T_7401 = ibuf_io_inst_0_bits_inst_rs1 != 5'h0;
  assign T_7402 = id_ctrl_rxs1 & T_7401;
  assign T_7404 = ibuf_io_inst_0_bits_inst_rs2 != 5'h0;
  assign T_7405 = id_ctrl_rxs2 & T_7404;
  assign T_7407 = ibuf_io_inst_0_bits_inst_rd != 5'h0;
  assign T_7408 = id_ctrl_wxd & T_7407;
  assign T_7411 = T_7410[31:1];
  assign GEN_180 = {{1'd0}, T_7411};
  assign T_7412 = GEN_180 << 1;
  assign T_7415 = 32'h1 << ll_waddr;
  assign T_7417 = ll_wen ? T_7415 : 32'h0;
  assign T_7418 = ~ T_7417;
  assign T_7419 = T_7412 & T_7418;
  assign GEN_170 = ll_wen ? T_7419 : T_7410;
  assign T_7421 = T_7412 >> ibuf_io_inst_0_bits_inst_rs1;
  assign T_7422 = T_7421[0];
  assign T_7423 = T_7402 & T_7422;
  assign T_7424 = T_7412 >> ibuf_io_inst_0_bits_inst_rs2;
  assign T_7425 = T_7424[0];
  assign T_7426 = T_7405 & T_7425;
  assign T_7427 = T_7412 >> ibuf_io_inst_0_bits_inst_rd;
  assign T_7428 = T_7427[0];
  assign T_7429 = T_7408 & T_7428;
  assign T_7430 = T_7423 | T_7426;
  assign id_sboard_hazard = T_7430 | T_7429;
  assign T_7431 = wb_set_sboard & wb_wen;
  assign T_7433 = 32'h1 << wb_waddr;
  assign T_7435 = T_7431 ? T_7433 : 32'h0;
  assign T_7436 = T_7419 | T_7435;
  assign T_7437 = ll_wen | T_7431;
  assign GEN_171 = T_7437 ? T_7436 : GEN_170;
  assign T_7438 = ex_ctrl_csr != 3'h0;
  assign T_7439 = T_7438 | ex_ctrl_jalr;
  assign T_7440 = T_7439 | ex_ctrl_mem;
  assign T_7441 = T_7440 | ex_ctrl_div;
  assign T_7442 = T_7441 | ex_ctrl_fp;
  assign ex_cannot_bypass = T_7442 | ex_ctrl_rocc;
  assign T_7443 = ibuf_io_inst_0_bits_inst_rs1 == ex_waddr;
  assign T_7444 = T_7402 & T_7443;
  assign T_7445 = ibuf_io_inst_0_bits_inst_rs2 == ex_waddr;
  assign T_7446 = T_7405 & T_7445;
  assign T_7447 = ibuf_io_inst_0_bits_inst_rd == ex_waddr;
  assign T_7448 = T_7408 & T_7447;
  assign T_7449 = T_7444 | T_7446;
  assign T_7450 = T_7449 | T_7448;
  assign data_hazard_ex = ex_ctrl_wxd & T_7450;
  assign T_7452 = io_fpu_dec_ren1 & T_7443;
  assign T_7454 = io_fpu_dec_ren2 & T_7445;
  assign T_7455 = ibuf_io_inst_0_bits_inst_rs3 == ex_waddr;
  assign T_7456 = io_fpu_dec_ren3 & T_7455;
  assign T_7458 = io_fpu_dec_wen & T_7447;
  assign T_7459 = T_7452 | T_7454;
  assign T_7460 = T_7459 | T_7456;
  assign T_7461 = T_7460 | T_7458;
  assign fp_data_hazard_ex = ex_ctrl_wfd & T_7461;
  assign T_7462 = data_hazard_ex & ex_cannot_bypass;
  assign T_7463 = T_7462 | fp_data_hazard_ex;
  assign id_ex_hazard = ex_reg_valid & T_7463;
  assign T_7465 = mem_ctrl_csr != 3'h0;
  assign T_7466 = mem_ctrl_mem & mem_reg_slow_bypass;
  assign T_7467 = T_7465 | T_7466;
  assign T_7468 = T_7467 | mem_ctrl_div;
  assign T_7469 = T_7468 | mem_ctrl_fp;
  assign mem_cannot_bypass = T_7469 | mem_ctrl_rocc;
  assign T_7470 = ibuf_io_inst_0_bits_inst_rs1 == mem_waddr;
  assign T_7471 = T_7402 & T_7470;
  assign T_7472 = ibuf_io_inst_0_bits_inst_rs2 == mem_waddr;
  assign T_7473 = T_7405 & T_7472;
  assign T_7474 = ibuf_io_inst_0_bits_inst_rd == mem_waddr;
  assign T_7475 = T_7408 & T_7474;
  assign T_7476 = T_7471 | T_7473;
  assign T_7477 = T_7476 | T_7475;
  assign data_hazard_mem = mem_ctrl_wxd & T_7477;
  assign T_7479 = io_fpu_dec_ren1 & T_7470;
  assign T_7481 = io_fpu_dec_ren2 & T_7472;
  assign T_7482 = ibuf_io_inst_0_bits_inst_rs3 == mem_waddr;
  assign T_7483 = io_fpu_dec_ren3 & T_7482;
  assign T_7485 = io_fpu_dec_wen & T_7474;
  assign T_7486 = T_7479 | T_7481;
  assign T_7487 = T_7486 | T_7483;
  assign T_7488 = T_7487 | T_7485;
  assign fp_data_hazard_mem = mem_ctrl_wfd & T_7488;
  assign T_7489 = data_hazard_mem & mem_cannot_bypass;
  assign T_7490 = T_7489 | fp_data_hazard_mem;
  assign id_mem_hazard = mem_reg_valid & T_7490;
  assign T_7491 = mem_reg_valid & data_hazard_mem;
  assign T_7492 = T_7491 & mem_ctrl_mem;
  assign T_7493 = ibuf_io_inst_0_bits_inst_rs1 == wb_waddr;
  assign T_7494 = T_7402 & T_7493;
  assign T_7495 = ibuf_io_inst_0_bits_inst_rs2 == wb_waddr;
  assign T_7496 = T_7405 & T_7495;
  assign T_7497 = ibuf_io_inst_0_bits_inst_rd == wb_waddr;
  assign T_7498 = T_7408 & T_7497;
  assign T_7499 = T_7494 | T_7496;
  assign T_7500 = T_7499 | T_7498;
  assign data_hazard_wb = wb_ctrl_wxd & T_7500;
  assign T_7502 = io_fpu_dec_ren1 & T_7493;
  assign T_7504 = io_fpu_dec_ren2 & T_7495;
  assign T_7505 = ibuf_io_inst_0_bits_inst_rs3 == wb_waddr;
  assign T_7506 = io_fpu_dec_ren3 & T_7505;
  assign T_7508 = io_fpu_dec_wen & T_7497;
  assign T_7509 = T_7502 | T_7504;
  assign T_7510 = T_7509 | T_7506;
  assign T_7511 = T_7510 | T_7508;
  assign fp_data_hazard_wb = wb_ctrl_wfd & T_7511;
  assign T_7512 = data_hazard_wb & wb_set_sboard;
  assign T_7513 = T_7512 | fp_data_hazard_wb;
  assign id_wb_hazard = wb_reg_valid & T_7513;
  assign T_7517 = io_dmem_req_valid | dcache_blocked;
  assign T_7518 = T_7068 & T_7517;
  assign T_7521 = wb_reg_xcpt == 1'h0;
  assign T_7524 = T_7521 & T_7369;
  assign T_7525 = io_rocc_cmd_valid | rocc_blocked;
  assign T_7526 = T_7524 & T_7525;
  assign T_7527 = id_ex_hazard | id_mem_hazard;
  assign T_7528 = T_7527 | id_wb_hazard;
  assign T_7529 = T_7528 | id_sboard_hazard;
  assign T_7532 = id_ctrl_mem & dcache_blocked;
  assign T_7533 = T_7529 | T_7532;
  assign T_7534 = id_ctrl_rocc & rocc_blocked;
  assign T_7535 = T_7533 | T_7534;
  assign T_7538 = div_io_resp_valid & T_7377;
  assign T_7539 = div_io_req_ready | T_7538;
  assign T_7541 = T_7539 == 1'h0;
  assign T_7542 = T_7541 | div_io_req_valid;
  assign T_7543 = id_ctrl_div & T_7542;
  assign T_7544 = T_7535 | T_7543;
  assign T_7545 = T_7544 | T_6852;
  assign ctrl_stalld = T_7545 | csr_io_csr_stall;
  assign T_7547 = ibuf_io_inst_0_valid == 1'h0;
  assign T_7548 = T_7547 | ibuf_io_inst_0_bits_replay;
  assign T_7549 = T_7548 | take_pc_mem_wb;
  assign T_7550 = T_7549 | ctrl_stalld;
  assign T_7551 = T_7550 | csr_io_interrupt;
  assign T_7554 = wb_xcpt | csr_io_eret;
  assign T_7558 = replay_wb ? wb_reg_pc : mem_npc;
  assign T_7559 = T_7554 ? csr_io_evec : T_7558;
  assign T_7560 = wb_reg_valid & wb_ctrl_fence_i;
  assign T_7562 = io_dmem_s2_nack == 1'h0;
  assign T_7563 = T_7560 & T_7562;
  assign T_7565 = ctrl_stalld == 1'h0;
  assign T_7566 = T_7565 | csr_io_interrupt;
  assign T_7567 = mem_reg_replay & mem_reg_btb_hit;
  assign T_7570 = mem_reg_valid & T_7354;
  assign T_7572 = mem_cfi == 1'h0;
  assign T_7573 = mem_cfi_taken | T_7572;
  assign T_7574 = T_7573 & mem_wrong_npc;
  assign T_7581 = T_7570 & T_7574;
  assign T_7582 = T_7567 | T_7581;
  assign T_7584 = mem_reg_replay == 1'h0;
  assign T_7585 = T_7584 & mem_cfi;
  assign T_7586 = mem_ctrl_jal | mem_ctrl_jalr;
  assign T_7587 = mem_reg_inst[19:15];
  assign T_7590 = T_7587 & 5'h19;
  assign T_7591 = 5'h1 == T_7590;
  assign T_7592 = mem_ctrl_jalr & T_7591;
  assign T_7595 = mem_reg_rvc ? 2'h0 : 2'h2;
  assign GEN_181 = {{30'd0}, T_7595};
  assign T_7596 = mem_reg_pc + GEN_181;
  assign T_7597 = T_7596[31:0];
  assign T_7598 = ~ io_imem_btb_update_bits_br_pc;
  assign T_7600 = T_7598 | 32'h3;
  assign T_7601 = ~ T_7600;
  assign T_7605 = T_7570 & mem_ctrl_branch;
  assign T_7609 = mem_waddr[0];
  assign T_7610 = io_imem_btb_update_bits_isJump & T_7609;
  assign T_7613 = T_6643 & id_ctrl_fp;
  assign T_7614 = dmem_resp_valid & T_7372;
  assign T_7615 = ex_reg_valid & ex_ctrl_mem;
  assign ex_dcache_tag = {ex_waddr,ex_ctrl_fp};
  assign T_7617 = mem_ctrl_fp ? io_fpu_store_data : mem_reg_rs2;
  assign T_7618 = killm_common | mem_breakpoint;
  assign T_7619 = mem_ctrl_mem & mem_xcpt;
  assign T_7621 = io_dmem_s1_kill == 1'h0;
  assign T_7622 = T_7619 & T_7621;
  assign T_7623 = {io_dmem_xcpt_pf_ld,io_dmem_xcpt_pf_st};
  assign T_7624 = {io_dmem_xcpt_ma_ld,io_dmem_xcpt_ma_st};
  assign T_7625 = {T_7624,T_7623};
  assign T_7627 = T_7625 != 4'h0;
  assign T_7628 = T_7627 | reset;
  assign T_7630 = T_7628 == 1'h0;
  assign T_7633 = replay_wb_common == 1'h0;
  assign T_7634 = T_6842 & T_7633;
  assign T_7637 = wb_xcpt & T_6828;
  assign T_7656_funct = T_7674;
  assign T_7656_rs2 = T_7673;
  assign T_7656_rs1 = T_7672;
  assign T_7656_xd = T_7671;
  assign T_7656_xs1 = T_7670;
  assign T_7656_xs2 = T_7669;
  assign T_7656_rd = T_7668;
  assign T_7656_opcode = T_7667;
  assign T_7666 = wb_reg_inst;
  assign T_7667 = T_7666[6:0];
  assign T_7668 = T_7666[11:7];
  assign T_7669 = T_7666[12];
  assign T_7670 = T_7666[13];
  assign T_7671 = T_7666[14];
  assign T_7672 = T_7666[19:15];
  assign T_7673 = T_7666[24:20];
  assign T_7674 = T_7666[31:25];
  assign T_7675 = csr_io_time;
  assign T_7677 = rf_wen ? rf_waddr : 5'h0;
  assign T_7678 = wb_reg_inst[19:15];
  assign T_7681 = wb_reg_inst[24:20];
  assign T_7685 = reset == 1'h0;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_272 = {1{$random}};
  ex_ctrl_legal = GEN_272[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_273 = {1{$random}};
  ex_ctrl_fp = GEN_273[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_274 = {1{$random}};
  ex_ctrl_rocc = GEN_274[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_275 = {1{$random}};
  ex_ctrl_branch = GEN_275[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_276 = {1{$random}};
  ex_ctrl_jal = GEN_276[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_277 = {1{$random}};
  ex_ctrl_jalr = GEN_277[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_278 = {1{$random}};
  ex_ctrl_rxs2 = GEN_278[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_279 = {1{$random}};
  ex_ctrl_rxs1 = GEN_279[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_280 = {1{$random}};
  ex_ctrl_sel_alu2 = GEN_280[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_281 = {1{$random}};
  ex_ctrl_sel_alu1 = GEN_281[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_282 = {1{$random}};
  ex_ctrl_sel_imm = GEN_282[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_283 = {1{$random}};
  ex_ctrl_alu_dw = GEN_283[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_284 = {1{$random}};
  ex_ctrl_alu_fn = GEN_284[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_285 = {1{$random}};
  ex_ctrl_mem = GEN_285[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_286 = {1{$random}};
  ex_ctrl_mem_cmd = GEN_286[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_287 = {1{$random}};
  ex_ctrl_mem_type = GEN_287[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_288 = {1{$random}};
  ex_ctrl_rfs1 = GEN_288[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_289 = {1{$random}};
  ex_ctrl_rfs2 = GEN_289[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_290 = {1{$random}};
  ex_ctrl_rfs3 = GEN_290[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_291 = {1{$random}};
  ex_ctrl_wfd = GEN_291[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_292 = {1{$random}};
  ex_ctrl_div = GEN_292[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_293 = {1{$random}};
  ex_ctrl_wxd = GEN_293[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_294 = {1{$random}};
  ex_ctrl_csr = GEN_294[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_295 = {1{$random}};
  ex_ctrl_fence_i = GEN_295[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_296 = {1{$random}};
  ex_ctrl_fence = GEN_296[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_297 = {1{$random}};
  ex_ctrl_amo = GEN_297[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_298 = {1{$random}};
  ex_ctrl_dp = GEN_298[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_299 = {1{$random}};
  mem_ctrl_legal = GEN_299[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_300 = {1{$random}};
  mem_ctrl_fp = GEN_300[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_301 = {1{$random}};
  mem_ctrl_rocc = GEN_301[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_302 = {1{$random}};
  mem_ctrl_branch = GEN_302[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_303 = {1{$random}};
  mem_ctrl_jal = GEN_303[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_304 = {1{$random}};
  mem_ctrl_jalr = GEN_304[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_305 = {1{$random}};
  mem_ctrl_rxs2 = GEN_305[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_306 = {1{$random}};
  mem_ctrl_rxs1 = GEN_306[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_307 = {1{$random}};
  mem_ctrl_sel_alu2 = GEN_307[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_308 = {1{$random}};
  mem_ctrl_sel_alu1 = GEN_308[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_309 = {1{$random}};
  mem_ctrl_sel_imm = GEN_309[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_310 = {1{$random}};
  mem_ctrl_alu_dw = GEN_310[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_311 = {1{$random}};
  mem_ctrl_alu_fn = GEN_311[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_312 = {1{$random}};
  mem_ctrl_mem = GEN_312[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_313 = {1{$random}};
  mem_ctrl_mem_cmd = GEN_313[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_314 = {1{$random}};
  mem_ctrl_mem_type = GEN_314[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_315 = {1{$random}};
  mem_ctrl_rfs1 = GEN_315[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_316 = {1{$random}};
  mem_ctrl_rfs2 = GEN_316[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_317 = {1{$random}};
  mem_ctrl_rfs3 = GEN_317[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_318 = {1{$random}};
  mem_ctrl_wfd = GEN_318[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_319 = {1{$random}};
  mem_ctrl_div = GEN_319[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_320 = {1{$random}};
  mem_ctrl_wxd = GEN_320[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_321 = {1{$random}};
  mem_ctrl_csr = GEN_321[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_322 = {1{$random}};
  mem_ctrl_fence_i = GEN_322[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_323 = {1{$random}};
  mem_ctrl_fence = GEN_323[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_324 = {1{$random}};
  mem_ctrl_amo = GEN_324[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_325 = {1{$random}};
  mem_ctrl_dp = GEN_325[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_326 = {1{$random}};
  wb_ctrl_legal = GEN_326[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_327 = {1{$random}};
  wb_ctrl_fp = GEN_327[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_328 = {1{$random}};
  wb_ctrl_rocc = GEN_328[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_329 = {1{$random}};
  wb_ctrl_branch = GEN_329[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_330 = {1{$random}};
  wb_ctrl_jal = GEN_330[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_331 = {1{$random}};
  wb_ctrl_jalr = GEN_331[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_332 = {1{$random}};
  wb_ctrl_rxs2 = GEN_332[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_333 = {1{$random}};
  wb_ctrl_rxs1 = GEN_333[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_334 = {1{$random}};
  wb_ctrl_sel_alu2 = GEN_334[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_335 = {1{$random}};
  wb_ctrl_sel_alu1 = GEN_335[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_336 = {1{$random}};
  wb_ctrl_sel_imm = GEN_336[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_337 = {1{$random}};
  wb_ctrl_alu_dw = GEN_337[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_338 = {1{$random}};
  wb_ctrl_alu_fn = GEN_338[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_339 = {1{$random}};
  wb_ctrl_mem = GEN_339[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_340 = {1{$random}};
  wb_ctrl_mem_cmd = GEN_340[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_341 = {1{$random}};
  wb_ctrl_mem_type = GEN_341[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_342 = {1{$random}};
  wb_ctrl_rfs1 = GEN_342[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_343 = {1{$random}};
  wb_ctrl_rfs2 = GEN_343[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_344 = {1{$random}};
  wb_ctrl_rfs3 = GEN_344[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_345 = {1{$random}};
  wb_ctrl_wfd = GEN_345[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_346 = {1{$random}};
  wb_ctrl_div = GEN_346[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_347 = {1{$random}};
  wb_ctrl_wxd = GEN_347[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_348 = {1{$random}};
  wb_ctrl_csr = GEN_348[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_349 = {1{$random}};
  wb_ctrl_fence_i = GEN_349[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_350 = {1{$random}};
  wb_ctrl_fence = GEN_350[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_351 = {1{$random}};
  wb_ctrl_amo = GEN_351[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_352 = {1{$random}};
  wb_ctrl_dp = GEN_352[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_353 = {1{$random}};
  ex_reg_xcpt_interrupt = GEN_353[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_354 = {1{$random}};
  ex_reg_valid = GEN_354[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_355 = {1{$random}};
  ex_reg_rvc = GEN_355[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_356 = {1{$random}};
  ex_reg_btb_hit = GEN_356[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_357 = {1{$random}};
  ex_reg_btb_resp_taken = GEN_357[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_358 = {1{$random}};
  ex_reg_btb_resp_mask = GEN_358[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_359 = {1{$random}};
  ex_reg_btb_resp_bridx = GEN_359[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_360 = {1{$random}};
  ex_reg_btb_resp_target = GEN_360[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_361 = {1{$random}};
  ex_reg_btb_resp_entry = GEN_361[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_362 = {1{$random}};
  ex_reg_btb_resp_bht_history = GEN_362[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_363 = {1{$random}};
  ex_reg_btb_resp_bht_value = GEN_363[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_364 = {1{$random}};
  ex_reg_xcpt = GEN_364[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_365 = {1{$random}};
  ex_reg_flush_pipe = GEN_365[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_366 = {1{$random}};
  ex_reg_load_use = GEN_366[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_367 = {1{$random}};
  ex_reg_cause = GEN_367[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_368 = {1{$random}};
  ex_reg_replay = GEN_368[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_369 = {1{$random}};
  ex_reg_pc = GEN_369[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_370 = {1{$random}};
  ex_reg_inst = GEN_370[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_371 = {1{$random}};
  mem_reg_xcpt_interrupt = GEN_371[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_372 = {1{$random}};
  mem_reg_valid = GEN_372[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_373 = {1{$random}};
  mem_reg_rvc = GEN_373[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_374 = {1{$random}};
  mem_reg_btb_hit = GEN_374[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_375 = {1{$random}};
  mem_reg_btb_resp_taken = GEN_375[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_376 = {1{$random}};
  mem_reg_btb_resp_mask = GEN_376[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_377 = {1{$random}};
  mem_reg_btb_resp_bridx = GEN_377[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_378 = {1{$random}};
  mem_reg_btb_resp_target = GEN_378[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_379 = {1{$random}};
  mem_reg_btb_resp_entry = GEN_379[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_380 = {1{$random}};
  mem_reg_btb_resp_bht_history = GEN_380[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_381 = {1{$random}};
  mem_reg_btb_resp_bht_value = GEN_381[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_382 = {1{$random}};
  mem_reg_xcpt = GEN_382[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_383 = {1{$random}};
  mem_reg_replay = GEN_383[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_384 = {1{$random}};
  mem_reg_flush_pipe = GEN_384[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_385 = {1{$random}};
  mem_reg_cause = GEN_385[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_386 = {1{$random}};
  mem_reg_slow_bypass = GEN_386[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_387 = {1{$random}};
  mem_reg_load = GEN_387[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_388 = {1{$random}};
  mem_reg_store = GEN_388[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_389 = {1{$random}};
  mem_reg_pc = GEN_389[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_390 = {1{$random}};
  mem_reg_inst = GEN_390[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_391 = {1{$random}};
  mem_reg_wdata = GEN_391[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_392 = {1{$random}};
  mem_reg_rs2 = GEN_392[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_393 = {1{$random}};
  wb_reg_valid = GEN_393[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_394 = {1{$random}};
  wb_reg_xcpt = GEN_394[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_395 = {1{$random}};
  wb_reg_replay = GEN_395[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_396 = {1{$random}};
  wb_reg_cause = GEN_396[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_397 = {1{$random}};
  wb_reg_pc = GEN_397[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_398 = {1{$random}};
  wb_reg_inst = GEN_398[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_399 = {1{$random}};
  wb_reg_wdata = GEN_399[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_400 = {1{$random}};
  wb_reg_rs2 = GEN_400[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_401 = {1{$random}};
  id_reg_fence = GEN_401[0:0];
  `endif
  GEN_402 = {1{$random}};
  `ifdef RANDOMIZE_MEM_INIT
  for (initvar = 0; initvar < 31; initvar = initvar+1)
    T_6545[initvar] = GEN_402[31:0];
  `endif
  GEN_403 = {1{$random}};
  GEN_404 = {1{$random}};
  `ifdef RANDOMIZE_REG_INIT
  GEN_405 = {1{$random}};
  ex_reg_rs_bypass_0 = GEN_405[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_406 = {1{$random}};
  ex_reg_rs_bypass_1 = GEN_406[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_407 = {1{$random}};
  ex_reg_rs_lsb_0 = GEN_407[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_408 = {1{$random}};
  ex_reg_rs_lsb_1 = GEN_408[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_409 = {1{$random}};
  ex_reg_rs_msb_0 = GEN_409[29:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_410 = {1{$random}};
  ex_reg_rs_msb_1 = GEN_410[29:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_411 = {1{$random}};
  T_7348 = GEN_411[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_412 = {1{$random}};
  T_7410 = GEN_412[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_413 = {1{$random}};
  dcache_blocked = GEN_413[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_414 = {1{$random}};
  rocc_blocked = GEN_414[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_415 = {1{$random}};
  T_7679 = GEN_415[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_416 = {1{$random}};
  T_7680 = GEN_416[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_417 = {1{$random}};
  T_7682 = GEN_417[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_418 = {1{$random}};
  T_7683 = GEN_418[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_419 = {1{$random}};
  GEN_158 = GEN_419[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_420 = {1{$random}};
  GEN_159 = GEN_420[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_421 = {1{$random}};
  GEN_160 = GEN_421[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_422 = {1{$random}};
  GEN_161 = GEN_422[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_423 = {1{$random}};
  GEN_164 = GEN_423[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_424 = {1{$random}};
  GEN_165 = GEN_424[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_425 = {1{$random}};
  GEN_167 = GEN_425[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_426 = {1{$random}};
  GEN_172 = GEN_426[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_427 = {1{$random}};
  GEN_173 = GEN_427[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_428 = {1{$random}};
  GEN_174 = GEN_428[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_429 = {1{$random}};
  GEN_175 = GEN_429[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_430 = {1{$random}};
  GEN_176 = GEN_430[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_431 = {1{$random}};
  GEN_177 = GEN_431[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_432 = {1{$random}};
  GEN_178 = GEN_432[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_433 = {1{$random}};
  GEN_179 = GEN_433[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_434 = {1{$random}};
  GEN_182 = GEN_434[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_435 = {1{$random}};
  GEN_183 = GEN_435[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_436 = {1{$random}};
  GEN_184 = GEN_436[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_437 = {1{$random}};
  GEN_185 = GEN_437[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_438 = {1{$random}};
  GEN_186 = GEN_438[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_439 = {1{$random}};
  GEN_187 = GEN_439[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_440 = {1{$random}};
  GEN_188 = GEN_440[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_441 = {2{$random}};
  GEN_189 = GEN_441[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_442 = {2{$random}};
  GEN_190 = GEN_442[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_443 = {2{$random}};
  GEN_191 = GEN_443[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_444 = {1{$random}};
  GEN_192 = GEN_444[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_445 = {1{$random}};
  GEN_193 = GEN_445[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_446 = {1{$random}};
  GEN_194 = GEN_446[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_447 = {1{$random}};
  GEN_195 = GEN_447[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_448 = {1{$random}};
  GEN_196 = GEN_448[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_449 = {1{$random}};
  GEN_197 = GEN_449[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_450 = {1{$random}};
  GEN_198 = GEN_450[6:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_451 = {1{$random}};
  GEN_199 = GEN_451[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_452 = {1{$random}};
  GEN_200 = GEN_452[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_453 = {1{$random}};
  GEN_201 = GEN_453[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_454 = {1{$random}};
  GEN_202 = GEN_454[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_455 = {1{$random}};
  GEN_203 = GEN_455[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_456 = {1{$random}};
  GEN_204 = GEN_456[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_457 = {1{$random}};
  GEN_205 = GEN_457[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_458 = {1{$random}};
  GEN_206 = GEN_458[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_459 = {1{$random}};
  GEN_207 = GEN_459[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_460 = {1{$random}};
  GEN_208 = GEN_460[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_461 = {1{$random}};
  GEN_209 = GEN_461[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_462 = {1{$random}};
  GEN_210 = GEN_462[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_463 = {1{$random}};
  GEN_211 = GEN_463[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_464 = {1{$random}};
  GEN_212 = GEN_464[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_465 = {1{$random}};
  GEN_213 = GEN_465[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_466 = {1{$random}};
  GEN_214 = GEN_466[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_467 = {1{$random}};
  GEN_215 = GEN_467[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_468 = {1{$random}};
  GEN_216 = GEN_468[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_469 = {1{$random}};
  GEN_217 = GEN_469[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_470 = {1{$random}};
  GEN_218 = GEN_470[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_471 = {1{$random}};
  GEN_219 = GEN_471[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_472 = {1{$random}};
  GEN_220 = GEN_472[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_473 = {1{$random}};
  GEN_221 = GEN_473[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_474 = {2{$random}};
  GEN_222 = GEN_474[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_475 = {1{$random}};
  GEN_223 = GEN_475[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_476 = {1{$random}};
  GEN_224 = GEN_476[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_477 = {1{$random}};
  GEN_225 = GEN_477[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_478 = {1{$random}};
  GEN_226 = GEN_478[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_479 = {1{$random}};
  GEN_227 = GEN_479[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_480 = {1{$random}};
  GEN_228 = GEN_480[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_481 = {1{$random}};
  GEN_229 = GEN_481[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_482 = {1{$random}};
  GEN_230 = GEN_482[6:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_483 = {1{$random}};
  GEN_231 = GEN_483[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_484 = {1{$random}};
  GEN_232 = GEN_484[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_485 = {1{$random}};
  GEN_233 = GEN_485[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_486 = {1{$random}};
  GEN_234 = GEN_486[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_487 = {1{$random}};
  GEN_235 = GEN_487[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_488 = {1{$random}};
  GEN_236 = GEN_488[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_489 = {1{$random}};
  GEN_237 = GEN_489[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_490 = {1{$random}};
  GEN_238 = GEN_490[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_491 = {1{$random}};
  GEN_239 = GEN_491[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_492 = {1{$random}};
  GEN_240 = GEN_492[25:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_493 = {1{$random}};
  GEN_241 = GEN_493[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_494 = {1{$random}};
  GEN_242 = GEN_494[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_495 = {1{$random}};
  GEN_243 = GEN_495[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_496 = {1{$random}};
  GEN_244 = GEN_496[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_497 = {1{$random}};
  GEN_245 = GEN_497[9:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_498 = {1{$random}};
  GEN_246 = GEN_498[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_499 = {1{$random}};
  GEN_247 = GEN_499[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_500 = {1{$random}};
  GEN_248 = GEN_500[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_501 = {1{$random}};
  GEN_249 = GEN_501[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_502 = {1{$random}};
  GEN_250 = GEN_502[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_503 = {1{$random}};
  GEN_251 = GEN_503[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_504 = {1{$random}};
  GEN_252 = GEN_504[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_505 = {1{$random}};
  GEN_253 = GEN_505[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_506 = {1{$random}};
  GEN_254 = GEN_506[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_507 = {1{$random}};
  GEN_255 = GEN_507[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_508 = {1{$random}};
  GEN_256 = GEN_508[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_509 = {1{$random}};
  GEN_257 = GEN_509[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_510 = {1{$random}};
  GEN_258 = GEN_510[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_511 = {1{$random}};
  GEN_259 = GEN_511[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_512 = {1{$random}};
  GEN_260 = GEN_512[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_513 = {1{$random}};
  GEN_261 = GEN_513[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_514 = {1{$random}};
  GEN_262 = GEN_514[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_515 = {1{$random}};
  GEN_263 = GEN_515[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_516 = {1{$random}};
  GEN_264 = GEN_516[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_517 = {1{$random}};
  GEN_265 = GEN_517[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_518 = {1{$random}};
  GEN_266 = GEN_518[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_519 = {1{$random}};
  GEN_267 = GEN_519[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_520 = {2{$random}};
  GEN_268 = GEN_520[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_521 = {2{$random}};
  GEN_269 = GEN_521[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_522 = {2{$random}};
  GEN_270 = GEN_522[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_523 = {1{$random}};
  GEN_271 = GEN_523[0:0];
  `endif
  end
`endif
  always @(posedge clock) begin
    if (T_6643) begin
      ex_ctrl_legal <= id_ctrl_legal;
    end
    if (T_6643) begin
      ex_ctrl_fp <= id_ctrl_fp;
    end
    if (T_6643) begin
      ex_ctrl_rocc <= id_ctrl_rocc;
    end
    if (T_6643) begin
      ex_ctrl_branch <= id_ctrl_branch;
    end
    if (T_6643) begin
      ex_ctrl_jal <= id_ctrl_jal;
    end
    if (T_6643) begin
      ex_ctrl_jalr <= id_ctrl_jalr;
    end
    if (T_6643) begin
      ex_ctrl_rxs2 <= id_ctrl_rxs2;
    end
    if (T_6643) begin
      ex_ctrl_rxs1 <= id_ctrl_rxs1;
    end
    if (T_6643) begin
      if (id_xcpt) begin
        if (T_7023) begin
          ex_ctrl_sel_alu2 <= 2'h1;
        end else begin
          ex_ctrl_sel_alu2 <= 2'h0;
        end
      end else begin
        ex_ctrl_sel_alu2 <= id_ctrl_sel_alu2;
      end
    end
    if (T_6643) begin
      if (id_xcpt) begin
        ex_ctrl_sel_alu1 <= 2'h2;
      end else begin
        ex_ctrl_sel_alu1 <= id_ctrl_sel_alu1;
      end
    end
    if (T_6643) begin
      ex_ctrl_sel_imm <= id_ctrl_sel_imm;
    end
    if (T_6643) begin
      if (id_xcpt) begin
        ex_ctrl_alu_dw <= 1'h1;
      end else begin
        ex_ctrl_alu_dw <= id_ctrl_alu_dw;
      end
    end
    if (T_6643) begin
      if (id_xcpt) begin
        ex_ctrl_alu_fn <= 4'h0;
      end else begin
        ex_ctrl_alu_fn <= id_ctrl_alu_fn;
      end
    end
    if (T_6643) begin
      ex_ctrl_mem <= id_ctrl_mem;
    end
    if (T_6643) begin
      ex_ctrl_mem_cmd <= id_ctrl_mem_cmd;
    end
    if (T_6643) begin
      ex_ctrl_mem_type <= id_ctrl_mem_type;
    end
    if (T_6643) begin
      ex_ctrl_rfs1 <= id_ctrl_rfs1;
    end
    if (T_6643) begin
      ex_ctrl_rfs2 <= id_ctrl_rfs2;
    end
    if (T_6643) begin
      ex_ctrl_rfs3 <= id_ctrl_rfs3;
    end
    if (T_6643) begin
      ex_ctrl_wfd <= id_ctrl_wfd;
    end
    if (T_6643) begin
      ex_ctrl_div <= id_ctrl_div;
    end
    if (T_6643) begin
      ex_ctrl_wxd <= id_ctrl_wxd;
    end
    if (T_6643) begin
      if (id_csr_ren) begin
        ex_ctrl_csr <= 3'h5;
      end else begin
        ex_ctrl_csr <= id_ctrl_csr;
      end
    end
    if (T_6643) begin
      if (T_7027) begin
        ex_ctrl_fence_i <= 1'h1;
      end else begin
        ex_ctrl_fence_i <= id_ctrl_fence_i;
      end
    end
    if (T_6643) begin
      ex_ctrl_fence <= id_ctrl_fence;
    end
    if (T_6643) begin
      ex_ctrl_amo <= id_ctrl_amo;
    end
    if (T_6643) begin
      ex_ctrl_dp <= id_ctrl_dp;
    end
    if (ex_pc_valid) begin
      mem_ctrl_legal <= ex_ctrl_legal;
    end
    if (ex_pc_valid) begin
      mem_ctrl_fp <= ex_ctrl_fp;
    end
    if (ex_pc_valid) begin
      mem_ctrl_rocc <= ex_ctrl_rocc;
    end
    if (ex_pc_valid) begin
      mem_ctrl_branch <= ex_ctrl_branch;
    end
    if (ex_pc_valid) begin
      mem_ctrl_jal <= ex_ctrl_jal;
    end
    if (ex_pc_valid) begin
      mem_ctrl_jalr <= ex_ctrl_jalr;
    end
    if (ex_pc_valid) begin
      mem_ctrl_rxs2 <= ex_ctrl_rxs2;
    end
    if (ex_pc_valid) begin
      mem_ctrl_rxs1 <= ex_ctrl_rxs1;
    end
    if (ex_pc_valid) begin
      mem_ctrl_sel_alu2 <= ex_ctrl_sel_alu2;
    end
    if (ex_pc_valid) begin
      mem_ctrl_sel_alu1 <= ex_ctrl_sel_alu1;
    end
    if (ex_pc_valid) begin
      mem_ctrl_sel_imm <= ex_ctrl_sel_imm;
    end
    if (ex_pc_valid) begin
      mem_ctrl_alu_dw <= ex_ctrl_alu_dw;
    end
    if (ex_pc_valid) begin
      mem_ctrl_alu_fn <= ex_ctrl_alu_fn;
    end
    if (ex_pc_valid) begin
      mem_ctrl_mem <= ex_ctrl_mem;
    end
    if (ex_pc_valid) begin
      mem_ctrl_mem_cmd <= ex_ctrl_mem_cmd;
    end
    if (ex_pc_valid) begin
      mem_ctrl_mem_type <= ex_ctrl_mem_type;
    end
    if (ex_pc_valid) begin
      mem_ctrl_rfs1 <= ex_ctrl_rfs1;
    end
    if (ex_pc_valid) begin
      mem_ctrl_rfs2 <= ex_ctrl_rfs2;
    end
    if (ex_pc_valid) begin
      mem_ctrl_rfs3 <= ex_ctrl_rfs3;
    end
    if (ex_pc_valid) begin
      mem_ctrl_wfd <= ex_ctrl_wfd;
    end
    if (ex_pc_valid) begin
      mem_ctrl_div <= ex_ctrl_div;
    end
    if (ex_pc_valid) begin
      mem_ctrl_wxd <= ex_ctrl_wxd;
    end
    if (ex_pc_valid) begin
      mem_ctrl_csr <= ex_ctrl_csr;
    end
    if (ex_pc_valid) begin
      mem_ctrl_fence_i <= ex_ctrl_fence_i;
    end
    if (ex_pc_valid) begin
      mem_ctrl_fence <= ex_ctrl_fence;
    end
    if (ex_pc_valid) begin
      mem_ctrl_amo <= ex_ctrl_amo;
    end
    if (ex_pc_valid) begin
      mem_ctrl_dp <= ex_ctrl_dp;
    end
    if (T_7360) begin
      wb_ctrl_legal <= mem_ctrl_legal;
    end
    if (T_7360) begin
      wb_ctrl_fp <= mem_ctrl_fp;
    end
    if (T_7360) begin
      wb_ctrl_rocc <= mem_ctrl_rocc;
    end
    if (T_7360) begin
      wb_ctrl_branch <= mem_ctrl_branch;
    end
    if (T_7360) begin
      wb_ctrl_jal <= mem_ctrl_jal;
    end
    if (T_7360) begin
      wb_ctrl_jalr <= mem_ctrl_jalr;
    end
    if (T_7360) begin
      wb_ctrl_rxs2 <= mem_ctrl_rxs2;
    end
    if (T_7360) begin
      wb_ctrl_rxs1 <= mem_ctrl_rxs1;
    end
    if (T_7360) begin
      wb_ctrl_sel_alu2 <= mem_ctrl_sel_alu2;
    end
    if (T_7360) begin
      wb_ctrl_sel_alu1 <= mem_ctrl_sel_alu1;
    end
    if (T_7360) begin
      wb_ctrl_sel_imm <= mem_ctrl_sel_imm;
    end
    if (T_7360) begin
      wb_ctrl_alu_dw <= mem_ctrl_alu_dw;
    end
    if (T_7360) begin
      wb_ctrl_alu_fn <= mem_ctrl_alu_fn;
    end
    if (T_7360) begin
      wb_ctrl_mem <= mem_ctrl_mem;
    end
    if (T_7360) begin
      wb_ctrl_mem_cmd <= mem_ctrl_mem_cmd;
    end
    if (T_7360) begin
      wb_ctrl_mem_type <= mem_ctrl_mem_type;
    end
    if (T_7360) begin
      wb_ctrl_rfs1 <= mem_ctrl_rfs1;
    end
    if (T_7360) begin
      wb_ctrl_rfs2 <= mem_ctrl_rfs2;
    end
    if (T_7360) begin
      wb_ctrl_rfs3 <= mem_ctrl_rfs3;
    end
    if (T_7360) begin
      wb_ctrl_wfd <= mem_ctrl_wfd;
    end
    if (T_7360) begin
      wb_ctrl_div <= mem_ctrl_div;
    end
    if (T_7360) begin
      wb_ctrl_wxd <= mem_ctrl_wxd;
    end
    if (T_7360) begin
      wb_ctrl_csr <= mem_ctrl_csr;
    end
    if (T_7360) begin
      wb_ctrl_fence_i <= mem_ctrl_fence_i;
    end
    if (T_7360) begin
      wb_ctrl_fence <= mem_ctrl_fence;
    end
    if (T_7360) begin
      wb_ctrl_amo <= mem_ctrl_amo;
    end
    if (T_7360) begin
      wb_ctrl_dp <= mem_ctrl_dp;
    end
    ex_reg_xcpt_interrupt <= T_7015;

    // ** CHANGE ** //
    // This is what RISC-V people meant
    if(reset)
      ex_reg_valid <= 1'b0;
    else
      ex_reg_valid <= T_6643;

    if (T_6643) begin
      if (id_xcpt) begin
        if (T_7023) begin
          ex_reg_rvc <= 1'h1;
        end else begin
          ex_reg_rvc <= ibuf_io_inst_0_bits_rvc;
        end
      end else begin
        ex_reg_rvc <= ibuf_io_inst_0_bits_rvc;
      end
    end
    ex_reg_btb_hit <= ibuf_io_inst_0_bits_btb_hit;
    if (ibuf_io_inst_0_bits_btb_hit) begin
      ex_reg_btb_resp_taken <= ibuf_io_btb_resp_taken;
    end
    if (ibuf_io_inst_0_bits_btb_hit) begin
      ex_reg_btb_resp_mask <= ibuf_io_btb_resp_mask;
    end
    if (ibuf_io_inst_0_bits_btb_hit) begin
      ex_reg_btb_resp_bridx <= ibuf_io_btb_resp_bridx;
    end
    if (ibuf_io_inst_0_bits_btb_hit) begin
      ex_reg_btb_resp_target <= ibuf_io_btb_resp_target;
    end
    if (ibuf_io_inst_0_bits_btb_hit) begin
      ex_reg_btb_resp_entry <= ibuf_io_btb_resp_entry;
    end
    if (ibuf_io_inst_0_bits_btb_hit) begin
      ex_reg_btb_resp_bht_history <= ibuf_io_btb_resp_bht_history;
    end
    if (ibuf_io_inst_0_bits_btb_hit) begin
      ex_reg_btb_resp_bht_value <= ibuf_io_btb_resp_bht_value;
    end
    ex_reg_xcpt <= T_7011;
    if (T_6643) begin
      if (T_7027) begin
        ex_reg_flush_pipe <= 1'h1;
      end else begin
        ex_reg_flush_pipe <= T_7026;
      end
    end
    if (T_6643) begin
      ex_reg_load_use <= id_load_use;
    end
    if (id_xcpt) begin
      if (csr_io_interrupt) begin
        ex_reg_cause <= csr_io_interrupt_cause;
      end else begin
        ex_reg_cause <= {{28'd0}, T_6862};
      end
    end
    ex_reg_replay <= T_7008;
    if (T_7063) begin
      ex_reg_pc <= ibuf_io_pc;
    end
    if (T_7063) begin
      ex_reg_inst <= ibuf_io_inst_0_bits_inst_bits;
    end
    mem_reg_xcpt_interrupt <= T_7292;
    // *** CHANGE *** //
    if(reset)
      mem_reg_valid <= 1'b0;
    else 
      mem_reg_valid <= T_7283;

    if (ex_pc_valid) begin
      mem_reg_rvc <= ex_reg_rvc;
    end
    if (ex_pc_valid) begin
      mem_reg_btb_hit <= ex_reg_btb_hit;
    end
    if (ex_pc_valid) begin
      if (ex_reg_btb_hit) begin
        mem_reg_btb_resp_taken <= ex_reg_btb_resp_taken;
      end
    end
    if (ex_pc_valid) begin
      if (ex_reg_btb_hit) begin
        mem_reg_btb_resp_mask <= ex_reg_btb_resp_mask;
      end
    end
    if (ex_pc_valid) begin
      if (ex_reg_btb_hit) begin
        mem_reg_btb_resp_bridx <= ex_reg_btb_resp_bridx;
      end
    end
    if (ex_pc_valid) begin
      if (ex_reg_btb_hit) begin
        mem_reg_btb_resp_target <= ex_reg_btb_resp_target;
      end
    end
    if (ex_pc_valid) begin
      if (ex_reg_btb_hit) begin
        mem_reg_btb_resp_entry <= ex_reg_btb_resp_entry;
      end
    end
    if (ex_pc_valid) begin
      if (ex_reg_btb_hit) begin
        mem_reg_btb_resp_bht_history <= ex_reg_btb_resp_bht_history;
      end
    end
    if (ex_pc_valid) begin
      if (ex_reg_btb_hit) begin
        mem_reg_btb_resp_bht_value <= ex_reg_btb_resp_bht_value;
      end
    end
    mem_reg_xcpt <= T_7289;
    mem_reg_replay <= T_7286;
    if (ex_pc_valid) begin
      mem_reg_flush_pipe <= ex_reg_flush_pipe;
    end
    if (ex_xcpt) begin
      if (T_7102) begin
        mem_reg_cause <= ex_reg_cause;
      end else begin
        mem_reg_cause <= 32'h2;
      end
    end
    if (ex_pc_valid) begin
      mem_reg_slow_bypass <= ex_slow_bypass;
    end
    if (ex_pc_valid) begin
      mem_reg_load <= T_7302;
    end
    if (ex_pc_valid) begin
      mem_reg_store <= T_7310;
    end
    if (ex_pc_valid) begin
      mem_reg_pc <= ex_reg_pc;
    end
    if (ex_pc_valid) begin
      mem_reg_inst <= ex_reg_inst;
    end
    if (ex_pc_valid) begin
      mem_reg_wdata <= alu_io_out;
    end
    if (ex_pc_valid) begin
      if (T_7312) begin
        if (ex_reg_rs_bypass_1) begin
          mem_reg_rs2 <= GEN_1;
        end else begin
          mem_reg_rs2 <= T_6914;
        end
      end
    end
    // *** CHANGE *** //
    if(reset)
      wb_reg_valid <= 1'b0;
    else
      wb_reg_valid <= T_7352;
    wb_reg_xcpt <= T_7358;
    wb_reg_replay <= T_7355;
    if (mem_xcpt) begin
      if (T_7338) begin
        wb_reg_cause <= mem_reg_cause;
      end else begin
        wb_reg_cause <= {{28'd0}, mem_new_cause};
      end
    end
    if (T_7360) begin
      wb_reg_pc <= mem_reg_pc;
    end
    if (T_7360) begin
      wb_reg_inst <= mem_reg_inst;
    end
    if (T_7360) begin
      if (T_7364) begin
        wb_reg_wdata <= io_fpu_toint_data;
      end else begin
        wb_reg_wdata <= mem_int_wdata;
      end
    end
    if (T_7360) begin
      if (mem_ctrl_rocc) begin
        wb_reg_rs2 <= mem_reg_rs2;
      end
    end
    if (reset) begin
      id_reg_fence <= 1'h0;
    end else begin
      id_reg_fence <= T_6845;
    end
    if(T_6545_T_7395_en & T_6545_T_7395_mask) begin
      T_6545[T_6545_T_7395_addr] <= T_6545_T_7395_data;
    end
    if (T_6643) begin
      ex_reg_rs_bypass_0 <= T_7032;
    end
    if (T_6643) begin
      ex_reg_rs_bypass_1 <= T_7047;
    end
    if (T_6643) begin
      if (T_7042) begin
        ex_reg_rs_lsb_0 <= T_7043;
      end else begin
        if (T_6872) begin
          ex_reg_rs_lsb_0 <= 2'h0;
        end else begin
          if (id_bypass_src_0_1) begin
            ex_reg_rs_lsb_0 <= 2'h1;
          end else begin
            if (id_bypass_src_0_2) begin
              ex_reg_rs_lsb_0 <= 2'h2;
            end else begin
              ex_reg_rs_lsb_0 <= 2'h3;
            end
          end
        end
      end
    end
    if (T_6643) begin
      if (T_7057) begin
        ex_reg_rs_lsb_1 <= T_7058;
      end else begin
        if (T_6876) begin
          ex_reg_rs_lsb_1 <= 2'h0;
        end else begin
          if (id_bypass_src_1_1) begin
            ex_reg_rs_lsb_1 <= 2'h1;
          end else begin
            if (id_bypass_src_1_2) begin
              ex_reg_rs_lsb_1 <= 2'h2;
            end else begin
              ex_reg_rs_lsb_1 <= 2'h3;
            end
          end
        end
      end
    end
    if (T_6643) begin
      if (T_7042) begin
        ex_reg_rs_msb_0 <= T_7044;
      end
    end
    if (T_6643) begin
      if (T_7057) begin
        ex_reg_rs_msb_1 <= T_7059;
      end
    end
    T_7348 <= T_7347;
    if (reset) begin
      T_7410 <= 32'h0;
    end else begin
      if (T_7437) begin
        T_7410 <= T_7436;
      end else begin
        if (ll_wen) begin
          T_7410 <= T_7419;
        end
      end
    end
    dcache_blocked <= T_7518;
    rocc_blocked <= T_7526;
    if (ex_reg_rs_bypass_0) begin
      T_7679 <= GEN_0;
    end else begin
      T_7679 <= T_6909;
    end
    T_7680 <= T_7679;
    if (ex_reg_rs_bypass_1) begin
      T_7682 <= GEN_1;
    end else begin
      T_7682 <= T_6914;
    end
    T_7683 <= T_7682;
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (T_7622 & T_7630) begin
          $fwrite(32'h80000002,"Assertion failed\n    at rocket.scala:646 assert(io.dmem.xcpt.asUInt.orR) // make sure s1_kill is exhaustive\n");
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (T_7622 & T_7630) begin
          $fatal;
        end
    `ifdef STOP_COND
      end
    `endif
    `endif
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (T_7685) begin
          $fwrite(32'h80000002,"C%d: %d [%d] pc=[%h] W[r%d=%h][%d] R[r%d=%h] R[r%d=%h] inst=[%h] DASM(%h)\n",io_hartid,T_7675,wb_valid,wb_reg_pc,T_7677,rf_wdata,rf_wen,T_7678,T_7680,T_7681,T_7683,wb_reg_inst,wb_reg_inst);
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif
  end

assign x0 = 32'd0;
assign x1 = T_6545[30];
assign x2 = T_6545[29];
assign x3 = T_6545[28];
assign x4 = T_6545[27];
assign x5 = T_6545[26];
assign x6 = T_6545[25];
assign x7 = T_6545[24];
assign x8 = T_6545[23];
assign x9 = T_6545[22];
assign x10 = T_6545[21];
assign x11 = T_6545[20];
assign x12 = T_6545[19];
assign x13 = T_6545[18];
assign x14 = T_6545[17];
assign x15 = T_6545[16];
assign x16 = T_6545[15];
assign x17 = T_6545[14];
assign x18 = T_6545[13];
assign x19 = T_6545[12];
assign x20 = T_6545[11];
assign x21 = T_6545[10];
assign x22 = T_6545[9];
assign x23 = T_6545[8];
assign x24 = T_6545[7];
assign x25 = T_6545[6];
assign x26 = T_6545[5];
assign x27 = T_6545[4];
assign x28 = T_6545[3];
assign x29 = T_6545[2];
assign x30 = T_6545[1];
assign x31 = T_6545[0];


  assign rf_idx_o = rf_idx_i == 5'd0 ? 32'd0 : T_6545[~rf_idx_i]; 

  assign ibuf_io_pc_o = ibuf_io_pc;
  assign wb_reg_pc_o  = wb_reg_pc;

  assign ibuf_io_inst_0_bits_inst_bits_o = ibuf_io_inst_0_bits_inst_bits;
  assign ibuf_io_inst_0_valid_o = ibuf_io_inst_0_valid;
  assign ex_reg_valid_o = ex_reg_valid;
  assign mem_reg_valid_o = mem_reg_valid;
  assign wb_valid_o = wb_valid;
  assign wb_reg_valid_o = wb_reg_valid;
  assign wb_reg_inst_o = wb_reg_inst;
  assign ex_reg_inst_o = ex_reg_inst;
  assign mem_reg_inst_o = mem_reg_inst;

  assign ctrl_killd_o = ctrl_killd;
  assign ctrl_killx_o = ctrl_killx;
  assign ctrl_killm_o = ctrl_killm;

  assign first_valid_pc = wb_valid ? wb_reg_pc : 
                          mem_reg_valid ? mem_reg_pc:
                          ex_reg_valid&ex_pc_valid ? ex_reg_pc : 32'h0;

  assign no_first_valid_pc = ~(wb_valid | mem_reg_valid | (ex_reg_valid&ex_pc_valid)  );

  assert property (div_io_resp_valid == 1'b0);
  assert property (div_io_req_valid == 1'b0);
  assert property (bpu_io_debug_if == 1'b0);
  assert property (bpu_io_debug_ld == 1'b0);
  assert property (bpu_io_debug_st == 1'b0);
  assert property (bpu_io_xcpt_if == 1'b0);
  assert property (bpu_io_xcpt_ld == 1'b0);
  assert property (bpu_io_xcpt_st == 1'b0);
  
  assign  id_rs_0_in_use = id_ctrl_rxs1;
  assign  id_rs_1_in_use = id_ctrl_rxs2;
  assign ex_rs_0_o = ex_rs_0;
  assign ex_rs_1_o = ex_rs_1;

  // no rvc lemma
  // Note: this is not provable, because it should be 
  // only an assumption
  reg error;
  always @(posedge clock) begin
    error <= ( mem_reg_rvc & ~ctrl_killm );
  end
  no_rvc_lemma: assert property ( ~(wb_valid & error) || 1 );


endmodule
