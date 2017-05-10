module CSRFile(
  input   clock,
  input   reset,
  input   io_interrupts_debug,
  input   io_interrupts_mtip,
  input   io_interrupts_msip,
  input   io_interrupts_meip,
  input  [31:0] io_hartid,
  input  [11:0] io_rw_addr,
  input  [2:0] io_rw_cmd,
  output [31:0] io_rw_rdata,
  input  [31:0] io_rw_wdata,
  output  io_csr_stall,
  output  io_csr_xcpt,
  output  io_eret,
  output  io_singleStep,
  output  io_status_debug,
  output [31:0] io_status_isa,
  output [1:0] io_status_prv,
  output  io_status_sd,
  output [30:0] io_status_zero3,
  output  io_status_sd_rv32,
  output [1:0] io_status_zero2,
  output [4:0] io_status_vm,
  output [3:0] io_status_zero1,
  output  io_status_mxr,
  output  io_status_pum,
  output  io_status_mprv,
  output [1:0] io_status_xs,
  output [1:0] io_status_fs,
  output [1:0] io_status_mpp,
  output [1:0] io_status_hpp,
  output  io_status_spp,
  output  io_status_mpie,
  output  io_status_hpie,
  output  io_status_spie,
  output  io_status_upie,
  output  io_status_mie,
  output  io_status_hie,
  output  io_status_sie,
  output  io_status_uie,
  output [6:0] io_ptbr_asid,
  output [21:0] io_ptbr_ppn,
  output [31:0] io_evec,
  input   io_exception,
  input   io_retire,
  input  [31:0] io_cause,
  input  [31:0] io_pc,
  input  [31:0] io_badaddr,
  output  io_fatc,
  output [31:0] io_time,
  output [2:0] io_fcsr_rm,
  input   io_fcsr_flags_valid,
  input  [4:0] io_fcsr_flags_bits,
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
  output  io_interrupt,
  output [31:0] io_interrupt_cause,
  output [3:0] io_bp_0_control_ttype,
  output  io_bp_0_control_dmode,
  output [5:0] io_bp_0_control_maskmax,
  output [7:0] io_bp_0_control_reserved,
  output  io_bp_0_control_action,
  output  io_bp_0_control_chain,
  output [1:0] io_bp_0_control_zero,
  output [1:0] io_bp_0_control_tmatch,
  output  io_bp_0_control_m,
  output  io_bp_0_control_h,
  output  io_bp_0_control_s,
  output  io_bp_0_control_u,
  output  io_bp_0_control_x,
  output  io_bp_0_control_w,
  output  io_bp_0_control_r,
  output [31:0] io_bp_0_address
);
  wire  T_4258_debug;
  wire [31:0] T_4258_isa;
  wire [1:0] T_4258_prv;
  wire  T_4258_sd;
  wire [30:0] T_4258_zero3;
  wire  T_4258_sd_rv32;
  wire [1:0] T_4258_zero2;
  wire [4:0] T_4258_vm;
  wire [3:0] T_4258_zero1;
  wire  T_4258_mxr;
  wire  T_4258_pum;
  wire  T_4258_mprv;
  wire [1:0] T_4258_xs;
  wire [1:0] T_4258_fs;
  wire [1:0] T_4258_mpp;
  wire [1:0] T_4258_hpp;
  wire  T_4258_spp;
  wire  T_4258_mpie;
  wire  T_4258_hpie;
  wire  T_4258_spie;
  wire  T_4258_upie;
  wire  T_4258_mie;
  wire  T_4258_hie;
  wire  T_4258_sie;
  wire  T_4258_uie;
  wire [98:0] T_4285;
  wire  T_4286;
  wire  T_4287;
  wire  T_4288;
  wire  T_4289;
  wire  T_4290;
  wire  T_4291;
  wire  T_4292;
  wire  T_4293;
  wire  T_4294;
  wire [1:0] T_4295;
  wire [1:0] T_4296;
  wire [1:0] T_4297;
  wire [1:0] T_4298;
  wire  T_4299;
  wire  T_4300;
  wire  T_4301;
  wire [3:0] T_4302;
  wire [4:0] T_4303;
  wire [1:0] T_4304;
  wire  T_4305;
  wire [30:0] T_4306;
  wire  T_4307;
  wire [1:0] T_4308;
  wire [31:0] T_4309;
  wire  T_4310;
  wire  reset_mstatus_debug;
  wire [31:0] reset_mstatus_isa;
  wire [1:0] reset_mstatus_prv;
  wire  reset_mstatus_sd;
  wire [30:0] reset_mstatus_zero3;
  wire  reset_mstatus_sd_rv32;
  wire [1:0] reset_mstatus_zero2;
  wire [4:0] reset_mstatus_vm;
  wire [3:0] reset_mstatus_zero1;
  wire  reset_mstatus_mxr;
  wire  reset_mstatus_pum;
  wire  reset_mstatus_mprv;
  wire [1:0] reset_mstatus_xs;
  wire [1:0] reset_mstatus_fs;
  wire [1:0] reset_mstatus_mpp;
  wire [1:0] reset_mstatus_hpp;
  wire  reset_mstatus_spp;
  wire  reset_mstatus_mpie;
  wire  reset_mstatus_hpie;
  wire  reset_mstatus_spie;
  wire  reset_mstatus_upie;
  wire  reset_mstatus_mie;
  wire  reset_mstatus_hie;
  wire  reset_mstatus_sie;
  wire  reset_mstatus_uie;
  reg  reg_mstatus_debug;
  reg [31:0] GEN_208;
  reg [31:0] reg_mstatus_isa;
  reg [31:0] GEN_210;
  reg [1:0] reg_mstatus_prv;
  reg [31:0] GEN_212;
  reg  reg_mstatus_sd;
  reg [31:0] GEN_214;
  reg [30:0] reg_mstatus_zero3;
  reg [31:0] GEN_215;
  reg  reg_mstatus_sd_rv32;
  reg [31:0] GEN_216;
  reg [1:0] reg_mstatus_zero2;
  reg [31:0] GEN_218;
  reg [4:0] reg_mstatus_vm;
  reg [31:0] GEN_219;
  reg [3:0] reg_mstatus_zero1;
  reg [31:0] GEN_220;
  reg  reg_mstatus_mxr;
  reg [31:0] GEN_221;
  reg  reg_mstatus_pum;
  reg [31:0] GEN_222;
  reg  reg_mstatus_mprv;
  reg [31:0] GEN_224;
  reg [1:0] reg_mstatus_xs;
  reg [31:0] GEN_225;
  reg [1:0] reg_mstatus_fs;
  reg [31:0] GEN_226;
  reg [1:0] reg_mstatus_mpp;
  reg [31:0] GEN_227;
  reg [1:0] reg_mstatus_hpp;
  reg [31:0] GEN_228;
  reg  reg_mstatus_spp;
  reg [31:0] GEN_230;
  reg  reg_mstatus_mpie;
  reg [31:0] GEN_232;
  reg  reg_mstatus_hpie;
  reg [31:0] GEN_233;
  reg  reg_mstatus_spie;
  reg [31:0] GEN_234;
  reg  reg_mstatus_upie;
  reg [31:0] GEN_235;
  reg  reg_mstatus_mie;
  reg [31:0] GEN_236;
  reg  reg_mstatus_hie;
  reg [31:0] GEN_238;
  reg  reg_mstatus_sie;
  reg [31:0] GEN_240;
  reg  reg_mstatus_uie;
  reg [31:0] GEN_242;
  wire [1:0] new_prv;
  wire  T_4363;
  wire [1:0] T_4367;
  wire [1:0] T_4405_xdebugver;
  wire  T_4405_ndreset;
  wire  T_4405_fullreset;
  wire [11:0] T_4405_zero3;
  wire  T_4405_ebreakm;
  wire  T_4405_ebreakh;
  wire  T_4405_ebreaks;
  wire  T_4405_ebreaku;
  wire  T_4405_zero2;
  wire  T_4405_stopcycle;
  wire  T_4405_stoptime;
  wire [2:0] T_4405_cause;
  wire  T_4405_debugint;
  wire  T_4405_zero1;
  wire  T_4405_halt;
  wire  T_4405_step;
  wire [1:0] T_4405_prv;
  wire [31:0] T_4424;
  wire [1:0] T_4425;
  wire  T_4426;
  wire  T_4427;
  wire  T_4428;
  wire  T_4429;
  wire [2:0] T_4430;
  wire  T_4431;
  wire  T_4432;
  wire  T_4433;
  wire  T_4434;
  wire  T_4435;
  wire  T_4436;
  wire  T_4437;
  wire [11:0] T_4438;
  wire  T_4439;
  wire  T_4440;
  wire [1:0] T_4441;
  wire [1:0] reset_dcsr_xdebugver;
  wire  reset_dcsr_ndreset;
  wire  reset_dcsr_fullreset;
  wire [11:0] reset_dcsr_zero3;
  wire  reset_dcsr_ebreakm;
  wire  reset_dcsr_ebreakh;
  wire  reset_dcsr_ebreaks;
  wire  reset_dcsr_ebreaku;
  wire  reset_dcsr_zero2;
  wire  reset_dcsr_stopcycle;
  wire  reset_dcsr_stoptime;
  wire [2:0] reset_dcsr_cause;
  wire  reset_dcsr_debugint;
  wire  reset_dcsr_zero1;
  wire  reset_dcsr_halt;
  wire  reset_dcsr_step;
  wire [1:0] reset_dcsr_prv;
  reg [1:0] reg_dcsr_xdebugver;
  reg [31:0] GEN_244;
  reg  reg_dcsr_ndreset;
  reg [31:0] GEN_246;
  reg  reg_dcsr_fullreset;
  reg [31:0] GEN_270;
  reg [11:0] reg_dcsr_zero3;
  reg [31:0] GEN_271;
  reg  reg_dcsr_ebreakm;
  reg [31:0] GEN_272;
  reg  reg_dcsr_ebreakh;
  reg [31:0] GEN_274;
  reg  reg_dcsr_ebreaks;
  reg [31:0] GEN_275;
  reg  reg_dcsr_ebreaku;
  reg [31:0] GEN_276;
  reg  reg_dcsr_zero2;
  reg [31:0] GEN_277;
  reg  reg_dcsr_stopcycle;
  reg [31:0] GEN_278;
  reg  reg_dcsr_stoptime;
  reg [31:0] GEN_280;
  reg [2:0] reg_dcsr_cause;
  reg [31:0] GEN_281;
  reg  reg_dcsr_debugint;
  reg [31:0] GEN_282;
  reg  reg_dcsr_zero1;
  reg [31:0] GEN_283;
  reg  reg_dcsr_halt;
  reg [31:0] GEN_284;
  reg  reg_dcsr_step;
  reg [31:0] GEN_286;
  reg [1:0] reg_dcsr_prv;
  reg [31:0] GEN_288;
  wire  T_4507_rocc;
  wire  T_4507_meip;
  wire  T_4507_heip;
  wire  T_4507_seip;
  wire  T_4507_ueip;
  wire  T_4507_mtip;
  wire  T_4507_htip;
  wire  T_4507_stip;
  wire  T_4507_utip;
  wire  T_4507_msip;
  wire  T_4507_hsip;
  wire  T_4507_ssip;
  wire  T_4507_usip;
  wire [12:0] T_4522;
  wire  T_4523;
  wire  T_4524;
  wire  T_4525;
  wire  T_4526;
  wire  T_4527;
  wire  T_4528;
  wire  T_4529;
  wire  T_4530;
  wire  T_4531;
  wire  T_4532;
  wire  T_4533;
  wire  T_4534;
  wire  T_4535;
  wire  T_4536_rocc;
  wire  T_4536_meip;
  wire  T_4536_heip;
  wire  T_4536_seip;
  wire  T_4536_ueip;
  wire  T_4536_mtip;
  wire  T_4536_htip;
  wire  T_4536_stip;
  wire  T_4536_utip;
  wire  T_4536_msip;
  wire  T_4536_hsip;
  wire  T_4536_ssip;
  wire  T_4536_usip;
  wire  T_4557_rocc;
  wire  T_4557_meip;
  wire  T_4557_heip;
  wire  T_4557_seip;
  wire  T_4557_ueip;
  wire  T_4557_mtip;
  wire  T_4557_htip;
  wire  T_4557_stip;
  wire  T_4557_utip;
  wire  T_4557_msip;
  wire  T_4557_hsip;
  wire  T_4557_ssip;
  wire  T_4557_usip;
  wire [1:0] T_4574;
  wire [2:0] T_4575;
  wire [1:0] T_4576;
  wire [2:0] T_4577;
  wire [5:0] T_4578;
  wire [1:0] T_4579;
  wire [2:0] T_4580;
  wire [1:0] T_4581;
  wire [1:0] T_4582;
  wire [3:0] T_4583;
  wire [6:0] T_4584;
  wire [12:0] supported_interrupts;
  wire  exception;
  reg  reg_debug;
  reg [31:0] GEN_289;
  reg [31:0] reg_dpc;
  reg [31:0] GEN_290;
  reg [31:0] reg_dscratch;
  reg [31:0] GEN_291;
  reg  reg_singleStepped;
  reg [31:0] GEN_292;
  wire  T_4601;
  wire  GEN_35;
  wire  T_4604;
  wire  GEN_36;
  wire  T_4615;
  wire  T_4617;
  wire  T_4618;
  wire  T_4619;
  wire  T_4621;
  reg  reg_tselect;
  reg [31:0] GEN_294;
  reg [3:0] reg_bp_0_control_ttype;
  reg [31:0] GEN_296;
  reg  reg_bp_0_control_dmode;
  reg [31:0] GEN_298;
  reg [5:0] reg_bp_0_control_maskmax;
  reg [31:0] GEN_300;
  reg [7:0] reg_bp_0_control_reserved;
  reg [31:0] GEN_302;
  reg  reg_bp_0_control_action;
  reg [31:0] GEN_308;
  reg  reg_bp_0_control_chain;
  reg [31:0] GEN_309;
  reg [1:0] reg_bp_0_control_zero;
  reg [31:0] GEN_310;
  reg [1:0] reg_bp_0_control_tmatch;
  reg [31:0] GEN_311;
  reg  reg_bp_0_control_m;
  reg [31:0] GEN_312;
  reg  reg_bp_0_control_h;
  reg [31:0] GEN_328;
  reg  reg_bp_0_control_s;
  reg [31:0] GEN_330;
  reg  reg_bp_0_control_u;
  reg [31:0] GEN_331;
  reg  reg_bp_0_control_x;
  reg [31:0] GEN_332;
  reg  reg_bp_0_control_w;
  reg [31:0] GEN_333;
  reg  reg_bp_0_control_r;
  reg [31:0] GEN_334;
  reg [31:0] reg_bp_0_address;
  reg [31:0] GEN_335;
  reg [3:0] reg_bp_1_control_ttype;
  reg [31:0] GEN_336;
  reg  reg_bp_1_control_dmode;
  reg [31:0] GEN_337;
  reg [5:0] reg_bp_1_control_maskmax;
  reg [31:0] GEN_338;
  reg [7:0] reg_bp_1_control_reserved;
  reg [31:0] GEN_339;
  reg  reg_bp_1_control_action;
  reg [31:0] GEN_340;
  reg  reg_bp_1_control_chain;
  reg [31:0] GEN_341;
  reg [1:0] reg_bp_1_control_zero;
  reg [31:0] GEN_342;
  reg [1:0] reg_bp_1_control_tmatch;
  reg [31:0] GEN_343;
  reg  reg_bp_1_control_m;
  reg [31:0] GEN_344;
  reg  reg_bp_1_control_h;
  reg [31:0] GEN_345;
  reg  reg_bp_1_control_s;
  reg [31:0] GEN_346;
  reg  reg_bp_1_control_u;
  reg [31:0] GEN_347;
  reg  reg_bp_1_control_x;
  reg [31:0] GEN_348;
  reg  reg_bp_1_control_w;
  reg [31:0] GEN_349;
  reg  reg_bp_1_control_r;
  reg [31:0] GEN_350;
  reg [31:0] reg_bp_1_address;
  reg [31:0] GEN_351;
  reg [31:0] reg_mie;
  reg [31:0] GEN_352;
  reg [31:0] reg_mideleg;
  reg [31:0] GEN_353;
  reg [31:0] reg_medeleg;
  reg [31:0] GEN_354;
  reg  reg_mip_rocc;
  reg [31:0] GEN_355;
  reg  reg_mip_meip;
  reg [31:0] GEN_356;
  reg  reg_mip_heip;
  reg [31:0] GEN_357;
  reg  reg_mip_seip;
  reg [31:0] GEN_358;
  reg  reg_mip_ueip;
  reg [31:0] GEN_359;
  reg  reg_mip_mtip;
  reg [31:0] GEN_360;
  reg  reg_mip_htip;
  reg [31:0] GEN_361;
  reg  reg_mip_stip;
  reg [31:0] GEN_362;
  reg  reg_mip_utip;
  reg [31:0] GEN_363;
  reg  reg_mip_msip;
  reg [31:0] GEN_364;
  reg  reg_mip_hsip;
  reg [31:0] GEN_365;
  reg  reg_mip_ssip;
  reg [31:0] GEN_366;
  reg  reg_mip_usip;
  reg [31:0] GEN_367;
  reg [31:0] reg_mepc;
  reg [31:0] GEN_368;
  reg [31:0] reg_mcause;
  reg [31:0] GEN_369;
  reg [31:0] reg_mbadaddr;
  reg [31:0] GEN_370;
  reg [31:0] reg_mscratch;
  reg [31:0] GEN_371;
  reg [31:0] reg_mtvec;
  reg [31:0] GEN_372;
  reg [31:0] reg_mucounteren;
  reg [31:0] GEN_373;
  reg [31:0] reg_mscounteren;
  reg [31:0] GEN_374;
  reg [31:0] reg_sepc;
  reg [31:0] GEN_375;
  reg [31:0] reg_scause;
  reg [31:0] GEN_376;
  reg [31:0] reg_sbadaddr;
  reg [31:0] GEN_377;
  reg [31:0] reg_sscratch;
  reg [31:0] GEN_378;
  reg [31:0] reg_stvec;
  reg [31:0] GEN_379;
  reg [6:0] reg_sptbr_asid;
  reg [31:0] GEN_380;
  reg [21:0] reg_sptbr_ppn;
  reg [31:0] GEN_381;
  reg  reg_wfi;
  reg [31:0] GEN_382;
  reg [4:0] reg_fflags;
  reg [31:0] GEN_383;
  reg [2:0] reg_frm;
  reg [31:0] GEN_384;
  reg [5:0] T_4797;
  reg [31:0] GEN_385;
  wire [5:0] GEN_0;
  wire [6:0] T_4798;
  reg [57:0] T_4800;
  reg [63:0] GEN_386;
  wire  T_4801;
  wire [58:0] T_4803;
  wire [58:0] GEN_37;
  wire [63:0] T_4804;
  reg [5:0] T_4807;
  reg [31:0] GEN_387;
  wire [6:0] T_4808;
  reg [57:0] T_4810;
  reg [63:0] GEN_388;
  wire  T_4811;
  wire [58:0] T_4813;
  wire [58:0] GEN_38;
  wire [63:0] T_4814;
  wire  mip_rocc;
  wire  mip_meip;
  wire  mip_heip;
  wire  mip_seip;
  wire  mip_ueip;
  wire  mip_mtip;
  wire  mip_htip;
  wire  mip_stip;
  wire  mip_utip;
  wire  mip_msip;
  wire  mip_hsip;
  wire  mip_ssip;
  wire  mip_usip;
  wire [1:0] T_4828;
  wire [2:0] T_4829;
  wire [1:0] T_4830;
  wire [2:0] T_4831;
  wire [5:0] T_4832;
  wire [1:0] T_4833;
  wire [2:0] T_4834;
  wire [1:0] T_4835;
  wire [1:0] T_4836;
  wire [3:0] T_4837;
  wire [6:0] T_4838;
  wire [12:0] T_4839;
  wire [12:0] read_mip;
  wire [31:0] GEN_1;
  wire [31:0] pending_interrupts;
  wire  T_4841;
  wire  T_4843;
  wire  T_4845;
  wire  T_4846;
  wire  T_4847;
  wire  T_4848;
  wire [31:0] T_4849;
  wire [31:0] T_4850;
  wire [31:0] m_interrupts;
  wire  T_4855;
  wire  T_4857;
  wire  T_4858;
  wire  T_4859;
  wire  T_4860;
  wire [31:0] T_4861;
  wire [31:0] s_interrupts;
  wire [31:0] all_interrupts;
  wire  T_4864;
  wire  T_4865;
  wire  T_4866;
  wire  T_4867;
  wire  T_4868;
  wire  T_4869;
  wire  T_4870;
  wire  T_4871;
  wire  T_4872;
  wire  T_4873;
  wire  T_4874;
  wire  T_4875;
  wire  T_4876;
  wire  T_4877;
  wire  T_4878;
  wire  T_4879;
  wire  T_4880;
  wire  T_4881;
  wire  T_4882;
  wire  T_4883;
  wire  T_4884;
  wire  T_4885;
  wire  T_4886;
  wire  T_4887;
  wire  T_4888;
  wire  T_4889;
  wire  T_4890;
  wire  T_4891;
  wire  T_4892;
  wire  T_4893;
  wire  T_4894;
  wire [4:0] T_4928;
  wire [4:0] T_4929;
  wire [4:0] T_4930;
  wire [4:0] T_4931;
  wire [4:0] T_4932;
  wire [4:0] T_4933;
  wire [4:0] T_4934;
  wire [4:0] T_4935;
  wire [4:0] T_4936;
  wire [4:0] T_4937;
  wire [4:0] T_4938;
  wire [4:0] T_4939;
  wire [4:0] T_4940;
  wire [4:0] T_4941;
  wire [4:0] T_4942;
  wire [4:0] T_4943;
  wire [4:0] T_4944;
  wire [4:0] T_4945;
  wire [4:0] T_4946;
  wire [4:0] T_4947;
  wire [4:0] T_4948;
  wire [4:0] T_4949;
  wire [4:0] T_4950;
  wire [4:0] T_4951;
  wire [4:0] T_4952;
  wire [4:0] T_4953;
  wire [4:0] T_4954;
  wire [4:0] T_4955;
  wire [4:0] T_4956;
  wire [4:0] T_4957;
  wire [4:0] T_4958;
  wire [31:0] GEN_2;
  wire [32:0] T_4959;
  wire [31:0] interruptCause;
  wire  T_4961;
  wire  T_4964;
  wire  T_4965;
  wire  T_4970;
  wire [32:0] T_4974;
  wire [31:0] T_4975;
  wire  GEN_39;
  wire [31:0] GEN_40;
  wire  system_insn;
  wire  T_4976;
  wire  T_4978;
  wire  cpu_ren;
  wire  T_4979;
  wire  cpu_wen;
  reg [31:0] reg_misa;
  reg [31:0] GEN_389;
  wire [1:0] T_4981;
  wire [2:0] T_4982;
  wire [1:0] T_4983;
  wire [2:0] T_4984;
  wire [5:0] T_4985;
  wire [1:0] T_4986;
  wire [2:0] T_4987;
  wire [3:0] T_4988;
  wire [5:0] T_4989;
  wire [8:0] T_4990;
  wire [14:0] T_4991;
  wire [1:0] T_4992;
  wire [3:0] T_4993;
  wire [8:0] T_4994;
  wire [9:0] T_4995;
  wire [13:0] T_4996;
  wire [31:0] T_4997;
  wire [33:0] T_4998;
  wire [2:0] T_4999;
  wire [32:0] T_5000;
  wire [35:0] T_5001;
  wire [69:0] T_5002;
  wire [83:0] T_5003;
  wire [98:0] T_5004;
  wire [31:0] read_mstatus;
  wire [3:0] GEN_0_control_ttype;
  wire  GEN_0_control_dmode;
  wire [5:0] GEN_0_control_maskmax;
  wire [7:0] GEN_0_control_reserved;
  wire  GEN_0_control_action;
  wire  GEN_0_control_chain;
  wire [1:0] GEN_0_control_zero;
  wire [1:0] GEN_0_control_tmatch;
  wire  GEN_0_control_m;
  wire  GEN_0_control_h;
  wire  GEN_0_control_s;
  wire  GEN_0_control_u;
  wire  GEN_0_control_x;
  wire  GEN_0_control_w;
  wire  GEN_0_control_r;
  wire [31:0] GEN_0_address;
  wire [3:0] GEN_41;
  wire  GEN_42;
  wire [5:0] GEN_43;
  wire [7:0] GEN_44;
  wire  GEN_45;
  wire  GEN_46;
  wire [1:0] GEN_47;
  wire [1:0] GEN_48;
  wire  GEN_49;
  wire  GEN_50;
  wire  GEN_51;
  wire  GEN_52;
  wire  GEN_53;
  wire  GEN_54;
  wire  GEN_55;
  wire [31:0] GEN_56;
  wire [3:0] GEN_1_control_ttype;
  wire  GEN_1_control_dmode;
  wire [5:0] GEN_1_control_maskmax;
  wire [7:0] GEN_1_control_reserved;
  wire  GEN_1_control_action;
  wire  GEN_1_control_chain;
  wire [1:0] GEN_1_control_zero;
  wire [1:0] GEN_1_control_tmatch;
  wire  GEN_1_control_m;
  wire  GEN_1_control_h;
  wire  GEN_1_control_s;
  wire  GEN_1_control_u;
  wire  GEN_1_control_x;
  wire  GEN_1_control_w;
  wire  GEN_1_control_r;
  wire [31:0] GEN_1_address;
  wire [1:0] T_5022;
  wire [3:0] GEN_2_control_ttype;
  wire  GEN_2_control_dmode;
  wire [5:0] GEN_2_control_maskmax;
  wire [7:0] GEN_2_control_reserved;
  wire  GEN_2_control_action;
  wire  GEN_2_control_chain;
  wire [1:0] GEN_2_control_zero;
  wire [1:0] GEN_2_control_tmatch;
  wire  GEN_2_control_m;
  wire  GEN_2_control_h;
  wire  GEN_2_control_s;
  wire  GEN_2_control_u;
  wire  GEN_2_control_x;
  wire  GEN_2_control_w;
  wire  GEN_2_control_r;
  wire [31:0] GEN_2_address;
  wire [2:0] T_5023;
  wire [3:0] GEN_3_control_ttype;
  wire  GEN_3_control_dmode;
  wire [5:0] GEN_3_control_maskmax;
  wire [7:0] GEN_3_control_reserved;
  wire  GEN_3_control_action;
  wire  GEN_3_control_chain;
  wire [1:0] GEN_3_control_zero;
  wire [1:0] GEN_3_control_tmatch;
  wire  GEN_3_control_m;
  wire  GEN_3_control_h;
  wire  GEN_3_control_s;
  wire  GEN_3_control_u;
  wire  GEN_3_control_x;
  wire  GEN_3_control_w;
  wire  GEN_3_control_r;
  wire [31:0] GEN_3_address;
  wire [3:0] GEN_4_control_ttype;
  wire  GEN_4_control_dmode;
  wire [5:0] GEN_4_control_maskmax;
  wire [7:0] GEN_4_control_reserved;
  wire  GEN_4_control_action;
  wire  GEN_4_control_chain;
  wire [1:0] GEN_4_control_zero;
  wire [1:0] GEN_4_control_tmatch;
  wire  GEN_4_control_m;
  wire  GEN_4_control_h;
  wire  GEN_4_control_s;
  wire  GEN_4_control_u;
  wire  GEN_4_control_x;
  wire  GEN_4_control_w;
  wire  GEN_4_control_r;
  wire [31:0] GEN_4_address;
  wire [1:0] T_5024;
  wire [3:0] GEN_5_control_ttype;
  wire  GEN_5_control_dmode;
  wire [5:0] GEN_5_control_maskmax;
  wire [7:0] GEN_5_control_reserved;
  wire  GEN_5_control_action;
  wire  GEN_5_control_chain;
  wire [1:0] GEN_5_control_zero;
  wire [1:0] GEN_5_control_tmatch;
  wire  GEN_5_control_m;
  wire  GEN_5_control_h;
  wire  GEN_5_control_s;
  wire  GEN_5_control_u;
  wire  GEN_5_control_x;
  wire  GEN_5_control_w;
  wire  GEN_5_control_r;
  wire [31:0] GEN_5_address;
  wire [3:0] GEN_6_control_ttype;
  wire  GEN_6_control_dmode;
  wire [5:0] GEN_6_control_maskmax;
  wire [7:0] GEN_6_control_reserved;
  wire  GEN_6_control_action;
  wire  GEN_6_control_chain;
  wire [1:0] GEN_6_control_zero;
  wire [1:0] GEN_6_control_tmatch;
  wire  GEN_6_control_m;
  wire  GEN_6_control_h;
  wire  GEN_6_control_s;
  wire  GEN_6_control_u;
  wire  GEN_6_control_x;
  wire  GEN_6_control_w;
  wire  GEN_6_control_r;
  wire [31:0] GEN_6_address;
  wire [1:0] T_5025;
  wire [3:0] T_5026;
  wire [6:0] T_5027;
  wire [3:0] GEN_7_control_ttype;
  wire  GEN_7_control_dmode;
  wire [5:0] GEN_7_control_maskmax;
  wire [7:0] GEN_7_control_reserved;
  wire  GEN_7_control_action;
  wire  GEN_7_control_chain;
  wire [1:0] GEN_7_control_zero;
  wire [1:0] GEN_7_control_tmatch;
  wire  GEN_7_control_m;
  wire  GEN_7_control_h;
  wire  GEN_7_control_s;
  wire  GEN_7_control_u;
  wire  GEN_7_control_x;
  wire  GEN_7_control_w;
  wire  GEN_7_control_r;
  wire [31:0] GEN_7_address;
  wire [3:0] GEN_8_control_ttype;
  wire  GEN_8_control_dmode;
  wire [5:0] GEN_8_control_maskmax;
  wire [7:0] GEN_8_control_reserved;
  wire  GEN_8_control_action;
  wire  GEN_8_control_chain;
  wire [1:0] GEN_8_control_zero;
  wire [1:0] GEN_8_control_tmatch;
  wire  GEN_8_control_m;
  wire  GEN_8_control_h;
  wire  GEN_8_control_s;
  wire  GEN_8_control_u;
  wire  GEN_8_control_x;
  wire  GEN_8_control_w;
  wire  GEN_8_control_r;
  wire [31:0] GEN_8_address;
  wire [3:0] T_5028;
  wire [3:0] GEN_9_control_ttype;
  wire  GEN_9_control_dmode;
  wire [5:0] GEN_9_control_maskmax;
  wire [7:0] GEN_9_control_reserved;
  wire  GEN_9_control_action;
  wire  GEN_9_control_chain;
  wire [1:0] GEN_9_control_zero;
  wire [1:0] GEN_9_control_tmatch;
  wire  GEN_9_control_m;
  wire  GEN_9_control_h;
  wire  GEN_9_control_s;
  wire  GEN_9_control_u;
  wire  GEN_9_control_x;
  wire  GEN_9_control_w;
  wire  GEN_9_control_r;
  wire [31:0] GEN_9_address;
  wire [3:0] GEN_10_control_ttype;
  wire  GEN_10_control_dmode;
  wire [5:0] GEN_10_control_maskmax;
  wire [7:0] GEN_10_control_reserved;
  wire  GEN_10_control_action;
  wire  GEN_10_control_chain;
  wire [1:0] GEN_10_control_zero;
  wire [1:0] GEN_10_control_tmatch;
  wire  GEN_10_control_m;
  wire  GEN_10_control_h;
  wire  GEN_10_control_s;
  wire  GEN_10_control_u;
  wire  GEN_10_control_x;
  wire  GEN_10_control_w;
  wire  GEN_10_control_r;
  wire [31:0] GEN_10_address;
  wire [1:0] T_5029;
  wire [5:0] T_5030;
  wire [3:0] GEN_11_control_ttype;
  wire  GEN_11_control_dmode;
  wire [5:0] GEN_11_control_maskmax;
  wire [7:0] GEN_11_control_reserved;
  wire  GEN_11_control_action;
  wire  GEN_11_control_chain;
  wire [1:0] GEN_11_control_zero;
  wire [1:0] GEN_11_control_tmatch;
  wire  GEN_11_control_m;
  wire  GEN_11_control_h;
  wire  GEN_11_control_s;
  wire  GEN_11_control_u;
  wire  GEN_11_control_x;
  wire  GEN_11_control_w;
  wire  GEN_11_control_r;
  wire [31:0] GEN_11_address;
  wire [3:0] GEN_12_control_ttype;
  wire  GEN_12_control_dmode;
  wire [5:0] GEN_12_control_maskmax;
  wire [7:0] GEN_12_control_reserved;
  wire  GEN_12_control_action;
  wire  GEN_12_control_chain;
  wire [1:0] GEN_12_control_zero;
  wire [1:0] GEN_12_control_tmatch;
  wire  GEN_12_control_m;
  wire  GEN_12_control_h;
  wire  GEN_12_control_s;
  wire  GEN_12_control_u;
  wire  GEN_12_control_x;
  wire  GEN_12_control_w;
  wire  GEN_12_control_r;
  wire [31:0] GEN_12_address;
  wire [13:0] T_5031;
  wire [3:0] GEN_13_control_ttype;
  wire  GEN_13_control_dmode;
  wire [5:0] GEN_13_control_maskmax;
  wire [7:0] GEN_13_control_reserved;
  wire  GEN_13_control_action;
  wire  GEN_13_control_chain;
  wire [1:0] GEN_13_control_zero;
  wire [1:0] GEN_13_control_tmatch;
  wire  GEN_13_control_m;
  wire  GEN_13_control_h;
  wire  GEN_13_control_s;
  wire  GEN_13_control_u;
  wire  GEN_13_control_x;
  wire  GEN_13_control_w;
  wire  GEN_13_control_r;
  wire [31:0] GEN_13_address;
  wire [3:0] GEN_14_control_ttype;
  wire  GEN_14_control_dmode;
  wire [5:0] GEN_14_control_maskmax;
  wire [7:0] GEN_14_control_reserved;
  wire  GEN_14_control_action;
  wire  GEN_14_control_chain;
  wire [1:0] GEN_14_control_zero;
  wire [1:0] GEN_14_control_tmatch;
  wire  GEN_14_control_m;
  wire  GEN_14_control_h;
  wire  GEN_14_control_s;
  wire  GEN_14_control_u;
  wire  GEN_14_control_x;
  wire  GEN_14_control_w;
  wire  GEN_14_control_r;
  wire [31:0] GEN_14_address;
  wire [4:0] T_5032;
  wire [18:0] T_5033;
  wire [24:0] T_5034;
  wire [31:0] T_5035;
  wire [2:0] T_5056;
  wire [1:0] T_5057;
  wire [4:0] T_5058;
  wire [3:0] T_5059;
  wire [1:0] T_5060;
  wire [5:0] T_5061;
  wire [10:0] T_5062;
  wire [1:0] T_5063;
  wire [1:0] T_5064;
  wire [3:0] T_5065;
  wire [12:0] T_5066;
  wire [2:0] T_5067;
  wire [3:0] T_5068;
  wire [16:0] T_5069;
  wire [20:0] T_5070;
  wire [31:0] T_5071;
  wire [31:0] T_5075;
  wire [31:0] T_5076;
  wire  T_5080;
  wire  T_5082;
  wire  T_5084;
  wire  T_5086;
  wire  T_5088;
  wire  T_5090;
  wire  T_5092;
  wire  T_5094;
  wire  T_5096;
  wire  T_5098;
  wire  T_5100;
  wire  T_5102;
  wire  T_5104;
  wire  T_5106;
  wire  T_5108;
  wire  T_5110;
  wire  T_5112;
  wire  T_5114;
  wire  T_5116;
  wire  T_5118;
  wire  T_5120;
  wire  T_5122;
  wire  T_5124;
  wire  T_5126;
  wire  T_5128;
  wire  T_5130;
  wire  T_5132;
  wire  T_5134;
  wire  T_5136;
  wire  T_5138;
  wire  T_5140;
  wire  T_5142;
  wire  T_5144;
  wire  T_5146;
  wire  T_5148;
  wire  T_5150;
  wire  T_5152;
  wire  T_5154;
  wire  T_5156;
  wire  T_5158;
  wire  T_5160;
  wire  T_5162;
  wire  T_5164;
  wire  T_5166;
  wire  T_5168;
  wire  T_5170;
  wire  T_5172;
  wire  T_5174;
  wire  T_5176;
  wire  T_5178;
  wire  T_5180;
  wire  T_5182;
  wire  T_5184;
  wire  T_5186;
  wire  T_5188;
  wire  T_5190;
  wire  T_5192;
  wire  T_5194;
  wire  T_5196;
  wire  T_5198;
  wire  T_5200;
  wire  T_5202;
  wire  T_5204;
  wire  T_5206;
  wire  T_5208;
  wire  T_5210;
  wire  T_5212;
  wire  T_5214;
  wire  T_5216;
  wire  T_5218;
  wire  T_5220;
  wire  T_5222;
  wire  T_5224;
  wire  T_5226;
  wire  T_5228;
  wire  T_5230;
  wire  T_5232;
  wire  T_5234;
  wire  T_5236;
  wire  T_5238;
  wire  T_5240;
  wire  T_5242;
  wire  T_5244;
  wire  T_5246;
  wire  T_5248;
  wire  T_5250;
  wire  T_5252;
  wire  T_5254;
  wire  T_5256;
  wire  T_5258;
  wire  T_5260;
  wire  T_5262;
  wire  T_5264;
  wire  T_5266;
  wire  T_5268;
  wire  T_5270;
  wire  T_5272;
  wire  T_5274;
  wire  T_5276;
  wire  T_5278;
  wire  T_5280;
  wire  T_5282;
  wire  T_5284;
  wire  T_5286;
  wire  T_5288;
  wire  T_5290;
  wire  T_5292;
  wire  T_5294;
  wire  T_5296;
  wire  T_5298;
  wire  T_5300;
  wire  T_5302;
  wire  T_5304;
  wire  T_5306;
  wire  T_5308;
  wire  T_5310;
  wire  T_5312;
  wire  T_5313;
  wire  T_5314;
  wire  T_5315;
  wire  T_5316;
  wire  T_5317;
  wire  T_5318;
  wire  T_5319;
  wire  T_5320;
  wire  T_5321;
  wire  T_5322;
  wire  T_5323;
  wire  T_5324;
  wire  T_5325;
  wire  T_5326;
  wire  T_5327;
  wire  T_5328;
  wire  T_5329;
  wire  T_5330;
  wire  T_5331;
  wire  T_5332;
  wire  T_5333;
  wire  T_5334;
  wire  T_5335;
  wire  T_5336;
  wire  T_5337;
  wire  T_5338;
  wire  T_5339;
  wire  T_5340;
  wire  T_5341;
  wire  T_5342;
  wire  T_5343;
  wire  T_5344;
  wire  T_5345;
  wire  T_5346;
  wire  T_5347;
  wire  T_5348;
  wire  T_5349;
  wire  T_5350;
  wire  T_5351;
  wire  T_5352;
  wire  T_5353;
  wire  T_5354;
  wire  T_5355;
  wire  T_5356;
  wire  T_5357;
  wire  T_5358;
  wire  T_5359;
  wire  T_5360;
  wire  T_5361;
  wire  T_5362;
  wire  T_5363;
  wire  T_5364;
  wire  T_5365;
  wire  T_5366;
  wire  T_5367;
  wire  T_5368;
  wire  T_5369;
  wire  T_5370;
  wire  T_5371;
  wire  T_5372;
  wire  T_5373;
  wire  T_5374;
  wire  T_5375;
  wire  T_5376;
  wire  T_5377;
  wire  T_5378;
  wire  T_5379;
  wire  T_5380;
  wire  T_5381;
  wire  T_5382;
  wire  T_5383;
  wire  T_5384;
  wire  T_5385;
  wire  T_5386;
  wire  T_5387;
  wire  T_5388;
  wire  T_5389;
  wire  T_5390;
  wire  T_5391;
  wire  T_5392;
  wire  T_5393;
  wire  T_5394;
  wire  T_5395;
  wire  T_5396;
  wire  T_5397;
  wire  T_5398;
  wire  T_5399;
  wire  T_5400;
  wire  T_5401;
  wire  T_5402;
  wire  T_5403;
  wire  T_5404;
  wire  T_5405;
  wire  T_5406;
  wire  T_5407;
  wire  T_5408;
  wire  T_5409;
  wire  T_5410;
  wire  T_5411;
  wire  T_5412;
  wire  T_5413;
  wire  T_5414;
  wire  T_5415;
  wire  T_5416;
  wire  T_5417;
  wire  T_5418;
  wire  T_5419;
  wire  T_5420;
  wire  T_5421;
  wire  T_5422;
  wire  T_5423;
  wire  T_5424;
  wire  T_5425;
  wire  T_5426;
  wire  T_5427;
  wire  addr_valid;
  wire  T_5429;
  wire  T_5431;
  wire  hpm_csr;
  wire  T_5434;
  wire [4:0] T_5437;
  wire [31:0] T_5438;
  wire  T_5439;
  wire  T_5440;
  wire  T_5441;
  wire  T_5443;
  wire [31:0] T_5445;
  wire  T_5446;
  wire  T_5447;
  wire  hpm_en;
  wire [1:0] csr_addr_priv;
  wire [11:0] T_5450;
  wire  T_5452;
  wire  T_5454;
  wire  T_5455;
  wire  T_5456;
  wire  priv_sufficient;
  wire [1:0] T_5457;
  wire [1:0] T_5458;
  wire  read_only;
  wire  T_5460;
  wire  T_5462;
  wire  wen;
  wire  T_5463;
  wire  T_5464;
  wire  T_5465;
  wire [31:0] T_5467;
  wire  T_5468;
  wire [31:0] T_5470;
  wire [31:0] T_5471;
  wire [31:0] T_5474;
  wire [31:0] T_5475;
  wire [31:0] wdata;
  wire  do_system_insn;
  wire [2:0] T_5477;
  wire [7:0] opcode;
  wire  T_5478;
  wire  insn_call;
  wire  T_5479;
  wire  insn_break;
  wire  T_5480;
  wire  insn_ret;
  wire  T_5481;
  wire  insn_sfence_vm;
  wire  T_5482;
  wire  insn_wfi;
  wire  T_5483;
  wire  T_5485;
  wire  T_5487;
  wire  T_5488;
  wire  T_5490;
  wire  T_5491;
  wire  T_5492;
  wire  T_5501;
  wire  T_5502;
  wire  T_5505;
  wire  T_5506;
  wire  T_5507;
  wire  T_5508;
  wire  GEN_57;
  wire  T_5511;
  wire  GEN_58;
  wire  T_5514;
  wire [3:0] GEN_3;
  wire [4:0] T_5516;
  wire [3:0] T_5517;
  wire [1:0] T_5520;
  wire [3:0] T_5521;
  wire [31:0] cause;
  wire [4:0] cause_lsbs;
  wire  T_5522;
  wire  T_5524;
  wire  causeIsDebugInt;
  wire  T_5527;
  wire  causeIsDebugTrigger;
  wire  T_5533;
  wire [1:0] T_5534;
  wire [1:0] T_5535;
  wire [3:0] T_5536;
  wire [3:0] T_5537;
  wire  T_5538;
  wire  causeIsDebugBreak;
  wire  T_5540;
  wire  T_5541;
  wire  T_5542;
  wire  T_5543;
  wire [11:0] debugTVec;
  wire [31:0] tvec;
  wire [31:0] epc;
  wire [31:0] T_5563;
  wire  T_5566;
  wire [1:0] T_5567;
  wire  T_5569;
  wire [1:0] T_5570;
  wire  T_5572;
  wire  T_5573;
  wire [31:0] T_5574;
  wire [31:0] T_5576;
  wire [31:0] T_5577;
  wire [31:0] T_5578;
  wire  T_5579;
  wire  T_5587;
  wire  T_5588;
  wire  T_5589;
  wire  T_5590;
  wire  T_5591;
  wire  T_5592;
  wire  T_5593;
  wire  T_5594;
  wire  T_5595;
  wire  T_5596;
  wire  T_5597;
  wire  T_5598;
  wire  T_5599;
  wire [1:0] T_5605;
  wire [1:0] T_5606;
  wire [2:0] T_5607;
  wire  T_5608;
  wire [1:0] T_5612;
  wire  GEN_59;
  wire [31:0] GEN_60;
  wire [2:0] GEN_61;
  wire [1:0] GEN_62;
  wire  T_5614;
  wire [31:0] T_5616;
  wire  T_5617;
  wire  T_5619;
  wire [1:0] T_5621;
  wire [31:0] GEN_4;
  wire [31:0] T_5622;
  wire [31:0] T_5623;
  wire [1:0] GEN_68;
  wire [31:0] GEN_71;
  wire [31:0] GEN_72;
  wire [31:0] GEN_73;
  wire [31:0] GEN_74;
  wire  GEN_75;
  wire [1:0] GEN_76;
  wire  GEN_77;
  wire [1:0] GEN_78;
  wire  GEN_79;
  wire [31:0] GEN_80;
  wire [2:0] GEN_81;
  wire [1:0] GEN_82;
  wire [1:0] GEN_87;
  wire [1:0] GEN_89;
  wire [31:0] GEN_90;
  wire [31:0] GEN_91;
  wire [31:0] GEN_92;
  wire  GEN_93;
  wire [1:0] GEN_94;
  wire  GEN_95;
  wire [1:0] GEN_101;
  wire  GEN_102;
  wire  T_5663;
  wire  GEN_103;
  wire  GEN_105;
  wire  GEN_107;
  wire [1:0] GEN_108;
  wire [1:0] GEN_109;
  wire [1:0] GEN_113;
  wire  GEN_114;
  wire  GEN_115;
  wire  GEN_116;
  wire [1:0] GEN_117;
  wire [1:0] T_5677;
  wire [1:0] GEN_6;
  wire [2:0] T_5678;
  wire  T_5680;
  wire  T_5681;
  wire  T_5683;
  wire  T_5685;
  wire [31:0] T_5687;
  wire [3:0] GEN_15_control_ttype;
  wire  GEN_15_control_dmode;
  wire [5:0] GEN_15_control_maskmax;
  wire [7:0] GEN_15_control_reserved;
  wire  GEN_15_control_action;
  wire  GEN_15_control_chain;
  wire [1:0] GEN_15_control_zero;
  wire [1:0] GEN_15_control_tmatch;
  wire  GEN_15_control_m;
  wire  GEN_15_control_h;
  wire  GEN_15_control_s;
  wire  GEN_15_control_u;
  wire  GEN_15_control_x;
  wire  GEN_15_control_w;
  wire  GEN_15_control_r;
  wire [31:0] GEN_15_address;
  wire [31:0] T_5689;
  wire [63:0] T_5697;
  wire [63:0] T_5699;
  wire [31:0] T_5701;
  wire [31:0] T_5703;
  wire [31:0] T_5705;
  wire [12:0] T_5707;
  wire [31:0] T_5709;
  wire [31:0] T_5711;
  wire [31:0] T_5713;
  wire [31:0] T_5715;
  wire [31:0] T_5717;
  wire [31:0] T_5719;
  wire [31:0] T_5721;
  wire [31:0] T_5723;
  wire [31:0] T_5725;
  wire [31:0] T_5727;
  wire [31:0] T_5729;
  wire [31:0] T_5905;
  wire [63:0] T_5907;
  wire [63:0] T_5909;
  wire [31:0] T_5911;
  wire [31:0] T_5913;
  wire [31:0] T_5915;
  wire [31:0] T_5917;
  wire [31:0] GEN_7;
  wire [31:0] T_5919;
  wire [31:0] T_5920;
  wire [63:0] GEN_8;
  wire [63:0] T_5924;
  wire [63:0] T_5925;
  wire [63:0] GEN_9;
  wire [63:0] T_5926;
  wire [63:0] GEN_10;
  wire [63:0] T_5927;
  wire [63:0] GEN_11;
  wire [63:0] T_5928;
  wire [63:0] GEN_12;
  wire [63:0] T_5929;
  wire [63:0] GEN_13;
  wire [63:0] T_5930;
  wire [63:0] GEN_14;
  wire [63:0] T_5931;
  wire [63:0] GEN_15;
  wire [63:0] T_5932;
  wire [63:0] GEN_16;
  wire [63:0] T_5933;
  wire [63:0] GEN_313;
  wire [63:0] T_5934;
  wire [63:0] GEN_314;
  wire [63:0] T_5935;
  wire [63:0] GEN_315;
  wire [63:0] T_5936;
  wire [63:0] GEN_316;
  wire [63:0] T_5937;
  wire [63:0] GEN_317;
  wire [63:0] T_5938;
  wire [63:0] GEN_318;
  wire [63:0] T_5939;
  wire [63:0] GEN_319;
  wire [63:0] T_5940;
  wire [63:0] GEN_320;
  wire [63:0] T_6028;
  wire [63:0] T_6029;
  wire [63:0] T_6030;
  wire [63:0] GEN_321;
  wire [63:0] T_6031;
  wire [63:0] GEN_322;
  wire [63:0] T_6032;
  wire [63:0] GEN_323;
  wire [63:0] T_6033;
  wire [63:0] GEN_324;
  wire [63:0] T_6034;
  wire [63:0] T_6035;
  wire [4:0] T_6036;
  wire [4:0] GEN_118;
  wire  T_6089_debug;
  wire [31:0] T_6089_isa;
  wire [1:0] T_6089_prv;
  wire  T_6089_sd;
  wire [30:0] T_6089_zero3;
  wire  T_6089_sd_rv32;
  wire [1:0] T_6089_zero2;
  wire [4:0] T_6089_vm;
  wire [3:0] T_6089_zero1;
  wire  T_6089_mxr;
  wire  T_6089_pum;
  wire  T_6089_mprv;
  wire [1:0] T_6089_xs;
  wire [1:0] T_6089_fs;
  wire [1:0] T_6089_mpp;
  wire [1:0] T_6089_hpp;
  wire  T_6089_spp;
  wire  T_6089_mpie;
  wire  T_6089_hpie;
  wire  T_6089_spie;
  wire  T_6089_upie;
  wire  T_6089_mie;
  wire  T_6089_hie;
  wire  T_6089_sie;
  wire  T_6089_uie;
  wire [98:0] T_6116;
  wire  T_6117;
  wire  T_6118;
  wire  T_6119;
  wire  T_6120;
  wire  T_6121;
  wire  T_6122;
  wire  T_6123;
  wire  T_6124;
  wire  T_6125;
  wire [1:0] T_6126;
  wire [1:0] T_6127;
  wire [1:0] T_6128;
  wire [1:0] T_6129;
  wire  T_6130;
  wire  T_6131;
  wire  T_6132;
  wire [3:0] T_6133;
  wire [4:0] T_6134;
  wire [1:0] T_6135;
  wire  T_6136;
  wire [30:0] T_6137;
  wire  T_6138;
  wire [1:0] T_6139;
  wire [31:0] T_6140;
  wire  T_6141;
  wire  T_6142;
  wire [1:0] T_6146;
  wire  GEN_119;
  wire  GEN_120;
  wire  GEN_121;
  wire [1:0] GEN_122;
  wire  T_6148;
  wire [31:0] T_6149;
  wire  T_6151;
  wire [3:0] GEN_325;
  wire [3:0] T_6152;
  wire [31:0] GEN_326;
  wire [31:0] T_6153;
  wire [31:0] T_6154;
  wire [31:0] T_6155;
  wire [31:0] T_6157;
  wire [31:0] T_6158;
  wire [31:0] GEN_123;
  wire  T_6187_rocc;
  wire  T_6187_meip;
  wire  T_6187_heip;
  wire  T_6187_seip;
  wire  T_6187_ueip;
  wire  T_6187_mtip;
  wire  T_6187_htip;
  wire  T_6187_stip;
  wire  T_6187_utip;
  wire  T_6187_msip;
  wire  T_6187_hsip;
  wire  T_6187_ssip;
  wire  T_6187_usip;
  wire  T_6201;
  wire  T_6202;
  wire  T_6203;
  wire  T_6204;
  wire  T_6205;
  wire  T_6207;
  wire  T_6208;
  wire  T_6209;
  wire  T_6210;
  wire  T_6211;
  wire  T_6212;
  wire  T_6213;
  wire [31:0] GEN_327;
  wire [31:0] T_6214;
  wire [31:0] GEN_124;
  wire [31:0] T_6221;
  wire [31:0] T_6222;
  wire [31:0] GEN_125;
  wire [31:0] GEN_126;
  wire [29:0] T_6223;
  wire [31:0] GEN_329;
  wire [31:0] T_6224;
  wire [31:0] GEN_127;
  wire [31:0] T_6226;
  wire [31:0] GEN_128;
  wire [31:0] GEN_129;
  wire [31:0] T_6228;
  wire [63:0] T_6229;
  wire [57:0] T_6230;
  wire [63:0] GEN_130;
  wire [58:0] GEN_131;
  wire [31:0] T_6231;
  wire [63:0] T_6232;
  wire [57:0] T_6233;
  wire [63:0] GEN_132;
  wire [58:0] GEN_133;
  wire [31:0] T_6234;
  wire [63:0] T_6235;
  wire [57:0] T_6236;
  wire [63:0] GEN_134;
  wire [58:0] GEN_135;
  wire [31:0] T_6237;
  wire [63:0] T_6238;
  wire [57:0] T_6239;
  wire [63:0] GEN_136;
  wire [58:0] GEN_137;
  wire [1:0] T_6276_xdebugver;
  wire  T_6276_ndreset;
  wire  T_6276_fullreset;
  wire [11:0] T_6276_zero3;
  wire  T_6276_ebreakm;
  wire  T_6276_ebreakh;
  wire  T_6276_ebreaks;
  wire  T_6276_ebreaku;
  wire  T_6276_zero2;
  wire  T_6276_stopcycle;
  wire  T_6276_stoptime;
  wire [2:0] T_6276_cause;
  wire  T_6276_debugint;
  wire  T_6276_zero1;
  wire  T_6276_halt;
  wire  T_6276_step;
  wire [1:0] T_6276_prv;
  wire [1:0] T_6294;
  wire [2:0] T_6299;
  wire  T_6304;
  wire  T_6305;
  wire  T_6306;
  wire [11:0] T_6307;
  wire  T_6308;
  wire  T_6309;
  wire [1:0] T_6310;
  wire  T_6311;
  wire [1:0] T_6315;
  wire  GEN_138;
  wire  GEN_139;
  wire  GEN_140;
  wire  GEN_141;
  wire [1:0] GEN_142;
  wire [31:0] T_6318;
  wire [31:0] T_6319;
  wire [31:0] GEN_143;
  wire [31:0] GEN_144;
  wire [31:0] T_6321;
  wire [31:0] GEN_145;
  wire [3:0] GEN_16_control_ttype;
  wire  GEN_16_control_dmode;
  wire [5:0] GEN_16_control_maskmax;
  wire [7:0] GEN_16_control_reserved;
  wire  GEN_16_control_action;
  wire  GEN_16_control_chain;
  wire [1:0] GEN_16_control_zero;
  wire [1:0] GEN_16_control_tmatch;
  wire  GEN_16_control_m;
  wire  GEN_16_control_h;
  wire  GEN_16_control_s;
  wire  GEN_16_control_u;
  wire  GEN_16_control_x;
  wire  GEN_16_control_w;
  wire  GEN_16_control_r;
  wire [31:0] GEN_16_address;
  wire  T_6340;
  wire  T_6341;
  wire [3:0] T_6374_ttype;
  wire  T_6374_dmode;
  wire [5:0] T_6374_maskmax;
  wire [7:0] T_6374_reserved;
  wire  T_6374_action;
  wire  T_6374_chain;
  wire [1:0] T_6374_zero;
  wire [1:0] T_6374_tmatch;
  wire  T_6374_m;
  wire  T_6374_h;
  wire  T_6374_s;
  wire  T_6374_u;
  wire  T_6374_x;
  wire  T_6374_w;
  wire  T_6374_r;
  wire [1:0] T_6397;
  wire [1:0] T_6398;
  wire [7:0] T_6401;
  wire [5:0] T_6402;
  wire  T_6403;
  wire [3:0] T_6404;
  wire  T_6405;
  wire [3:0] GEN_17;
  wire  GEN_18;
  wire  GEN_149;
  wire [5:0] GEN_19;
  wire [7:0] GEN_20;
  wire  GEN_21;
  wire  GEN_155;
  wire  GEN_22;
  wire [1:0] GEN_23;
  wire [1:0] GEN_24;
  wire [1:0] GEN_161;
  wire  GEN_25;
  wire  GEN_163;
  wire  GEN_26;
  wire  GEN_27;
  wire  GEN_28;
  wire  GEN_169;
  wire  GEN_29;
  wire  GEN_171;
  wire  GEN_30;
  wire  GEN_173;
  wire  GEN_31;
  wire  GEN_175;
  wire  GEN_32;
  wire  GEN_177;
  wire  T_6406;
  wire  GEN_33;
  wire  GEN_179;
  wire  GEN_183;
  wire  GEN_189;
  wire [1:0] GEN_195;
  wire  GEN_197;
  wire  GEN_203;
  wire  GEN_205;
  wire  GEN_207;
  wire  GEN_209;
  wire [31:0] GEN_34;
  wire [31:0] GEN_211;
  wire [31:0] GEN_213;
  wire  GEN_217;
  wire  GEN_223;
  wire [1:0] GEN_229;
  wire  GEN_231;
  wire  GEN_237;
  wire  GEN_239;
  wire  GEN_241;
  wire  GEN_243;
  wire [31:0] GEN_245;
  wire  GEN_247;
  wire  GEN_248;
  wire  GEN_249;
  wire [1:0] GEN_250;
  wire [31:0] GEN_251;
  wire [31:0] GEN_252;
  wire [31:0] GEN_253;
  wire [31:0] GEN_254;
  wire [31:0] GEN_255;
  wire [31:0] GEN_256;
  wire [31:0] GEN_257;
  wire [63:0] GEN_258;
  wire [58:0] GEN_259;
  wire [63:0] GEN_260;
  wire [58:0] GEN_261;
  wire  GEN_262;
  wire  GEN_263;
  wire  GEN_264;
  wire  GEN_265;
  wire [1:0] GEN_266;
  wire [31:0] GEN_267;
  wire [31:0] GEN_268;
  wire [31:0] GEN_269;
  wire  GEN_273;
  wire  GEN_279;
  wire [1:0] GEN_285;
  wire  GEN_287;
  wire  GEN_293;
  wire  GEN_295;
  wire  GEN_297;
  wire  GEN_299;
  wire [31:0] GEN_301;
  wire  GEN_303;
  wire  GEN_304;
  wire  GEN_305;
  wire  GEN_306;
  wire  GEN_307;
  wire [3:0] T_6472_control_ttype;
  wire  T_6472_control_dmode;
  wire [5:0] T_6472_control_maskmax;
  wire [7:0] T_6472_control_reserved;
  wire  T_6472_control_action;
  wire  T_6472_control_chain;
  wire [1:0] T_6472_control_zero;
  wire [1:0] T_6472_control_tmatch;
  wire  T_6472_control_m;
  wire  T_6472_control_h;
  wire  T_6472_control_s;
  wire  T_6472_control_u;
  wire  T_6472_control_x;
  wire  T_6472_control_w;
  wire  T_6472_control_r;
  wire [31:0] T_6472_address;
  wire [63:0] T_6491;
  wire [31:0] T_6492;
  wire  T_6493;
  wire  T_6494;
  wire  T_6495;
  wire  T_6496;
  wire  T_6497;
  wire  T_6498;
  wire  T_6499;
  wire [1:0] T_6500;
  wire [1:0] T_6501;
  wire  T_6502;
  wire  T_6503;
  wire [7:0] T_6504;
  wire [5:0] T_6505;
  wire  T_6506;
  wire [3:0] T_6507;
  reg  GEN_5;
  reg [31:0] GEN_390;
  reg [6:0] GEN_63;
  reg [31:0] GEN_391;
  reg [4:0] GEN_64;
  reg [31:0] GEN_392;
  reg [4:0] GEN_65;
  reg [31:0] GEN_393;
  reg  GEN_66;
  reg [31:0] GEN_394;
  reg  GEN_67;
  reg [31:0] GEN_395;
  reg  GEN_69;
  reg [31:0] GEN_396;
  reg [4:0] GEN_70;
  reg [31:0] GEN_397;
  reg [6:0] GEN_83;
  reg [31:0] GEN_398;
  reg [31:0] GEN_84;
  reg [31:0] GEN_399;
  reg [31:0] GEN_85;
  reg [31:0] GEN_400;
  reg  GEN_86;
  reg [31:0] GEN_401;
  reg [31:0] GEN_88;
  reg [31:0] GEN_402;
  reg [1:0] GEN_96;
  reg [31:0] GEN_403;
  reg  GEN_97;
  reg [31:0] GEN_404;
  reg [30:0] GEN_98;
  reg [31:0] GEN_405;
  reg  GEN_99;
  reg [31:0] GEN_406;
  reg [1:0] GEN_100;
  reg [31:0] GEN_407;
  reg [4:0] GEN_104;
  reg [31:0] GEN_408;
  reg [3:0] GEN_106;
  reg [31:0] GEN_409;
  reg  GEN_110;
  reg [31:0] GEN_410;
  reg  GEN_111;
  reg [31:0] GEN_411;
  reg  GEN_112;
  reg [31:0] GEN_412;
  reg [1:0] GEN_146;
  reg [31:0] GEN_413;
  reg [1:0] GEN_147;
  reg [31:0] GEN_414;
  reg [1:0] GEN_148;
  reg [31:0] GEN_415;
  reg [1:0] GEN_150;
  reg [31:0] GEN_416;
  reg  GEN_151;
  reg [31:0] GEN_417;
  reg  GEN_152;
  reg [31:0] GEN_418;
  reg  GEN_153;
  reg [31:0] GEN_419;
  reg  GEN_154;
  reg [31:0] GEN_420;
  reg  GEN_156;
  reg [31:0] GEN_421;
  reg  GEN_157;
  reg [31:0] GEN_422;
  reg  GEN_158;
  reg [31:0] GEN_423;
  reg  GEN_159;
  reg [31:0] GEN_424;
  reg  GEN_160;
  reg [31:0] GEN_425;
  reg  GEN_162;
  reg [31:0] GEN_426;
  reg  GEN_164;
  reg [31:0] GEN_427;
  reg  GEN_165;
  reg [31:0] GEN_428;
  reg  GEN_166;
  reg [31:0] GEN_429;
  reg [31:0] GEN_167;
  reg [31:0] GEN_430;
  reg [6:0] GEN_168;
  reg [31:0] GEN_431;
  reg [4:0] GEN_170;
  reg [31:0] GEN_432;
  reg [2:0] GEN_172;
  reg [31:0] GEN_433;
  reg [31:0] GEN_174;
  reg [31:0] GEN_434;
  reg  GEN_176;
  reg [31:0] GEN_435;
  reg  GEN_178;
  reg [31:0] GEN_436;
  reg [31:0] GEN_180;
  reg [31:0] GEN_437;
  reg [31:0] GEN_181;
  reg [31:0] GEN_438;
  reg  GEN_182;
  reg [31:0] GEN_439;
  reg  GEN_184;
  reg [31:0] GEN_440;
  reg  GEN_185;
  reg [31:0] GEN_441;
  reg  GEN_186;
  reg [31:0] GEN_442;
  reg  GEN_187;
  reg [31:0] GEN_443;
  reg  GEN_188;
  reg [31:0] GEN_444;
  reg  GEN_190;
  reg [31:0] GEN_445;
  reg  GEN_191;
  reg [31:0] GEN_446;
  reg [3:0] GEN_192;
  reg [31:0] GEN_447;
  reg  GEN_193;
  reg [31:0] GEN_448;
  reg [1:0] GEN_194;
  reg [31:0] GEN_449;
  reg  GEN_196;
  reg [31:0] GEN_450;
  reg [3:0] GEN_198;
  reg [31:0] GEN_451;
  reg [31:0] GEN_199;
  reg [31:0] GEN_452;
  reg  GEN_200;
  reg [31:0] GEN_453;
  reg  GEN_201;
  reg [31:0] GEN_454;
  reg [32:0] GEN_202;
  reg [63:0] GEN_455;
  reg [4:0] GEN_204;
  reg [31:0] GEN_456;
  reg  GEN_206;
  reg [31:0] GEN_457;
  assign io_rw_rdata = T_6035[31:0];
  assign io_csr_stall = reg_wfi;
  assign io_csr_xcpt = T_5508;
  assign io_eret = insn_ret;
  assign io_singleStep = T_5566;
  assign io_status_debug = reg_debug;
  assign io_status_isa = reg_misa;
  assign io_status_prv = reg_mstatus_prv;
  assign io_status_sd = T_5573;
  assign io_status_zero3 = reg_mstatus_zero3;
  assign io_status_sd_rv32 = io_status_sd;
  assign io_status_zero2 = reg_mstatus_zero2;
  assign io_status_vm = reg_mstatus_vm;
  assign io_status_zero1 = reg_mstatus_zero1;
  assign io_status_mxr = reg_mstatus_mxr;
  assign io_status_pum = reg_mstatus_pum;
  assign io_status_mprv = reg_mstatus_mprv;
  assign io_status_xs = reg_mstatus_xs;
  assign io_status_fs = reg_mstatus_fs;
  assign io_status_mpp = reg_mstatus_mpp;
  assign io_status_hpp = reg_mstatus_hpp;
  assign io_status_spp = reg_mstatus_spp;
  assign io_status_mpie = reg_mstatus_mpie;
  assign io_status_hpie = reg_mstatus_hpie;
  assign io_status_spie = reg_mstatus_spie;
  assign io_status_upie = reg_mstatus_upie;
  assign io_status_mie = reg_mstatus_mie;
  assign io_status_hie = reg_mstatus_hie;
  assign io_status_sie = reg_mstatus_sie;
  assign io_status_uie = reg_mstatus_uie;
  assign io_ptbr_asid = reg_sptbr_asid;
  assign io_ptbr_ppn = reg_sptbr_ppn;
  assign io_evec = T_5563;
  assign io_fatc = insn_sfence_vm;
  assign io_time = T_4814[31:0];
  assign io_fcsr_rm = reg_frm;
  assign io_rocc_cmd_valid = GEN_5;
  assign io_rocc_cmd_bits_inst_funct = GEN_63;
  assign io_rocc_cmd_bits_inst_rs2 = GEN_64;
  assign io_rocc_cmd_bits_inst_rs1 = GEN_65;
  assign io_rocc_cmd_bits_inst_xd = GEN_66;
  assign io_rocc_cmd_bits_inst_xs1 = GEN_67;
  assign io_rocc_cmd_bits_inst_xs2 = GEN_69;
  assign io_rocc_cmd_bits_inst_rd = GEN_70;
  assign io_rocc_cmd_bits_inst_opcode = GEN_83;
  assign io_rocc_cmd_bits_rs1 = GEN_84;
  assign io_rocc_cmd_bits_rs2 = GEN_85;
  assign io_rocc_cmd_bits_status_debug = GEN_86;
  assign io_rocc_cmd_bits_status_isa = GEN_88;
  assign io_rocc_cmd_bits_status_prv = GEN_96;
  assign io_rocc_cmd_bits_status_sd = GEN_97;
  assign io_rocc_cmd_bits_status_zero3 = GEN_98;
  assign io_rocc_cmd_bits_status_sd_rv32 = GEN_99;
  assign io_rocc_cmd_bits_status_zero2 = GEN_100;
  assign io_rocc_cmd_bits_status_vm = GEN_104;
  assign io_rocc_cmd_bits_status_zero1 = GEN_106;
  assign io_rocc_cmd_bits_status_mxr = GEN_110;
  assign io_rocc_cmd_bits_status_pum = GEN_111;
  assign io_rocc_cmd_bits_status_mprv = GEN_112;
  assign io_rocc_cmd_bits_status_xs = GEN_146;
  assign io_rocc_cmd_bits_status_fs = GEN_147;
  assign io_rocc_cmd_bits_status_mpp = GEN_148;
  assign io_rocc_cmd_bits_status_hpp = GEN_150;
  assign io_rocc_cmd_bits_status_spp = GEN_151;
  assign io_rocc_cmd_bits_status_mpie = GEN_152;
  assign io_rocc_cmd_bits_status_hpie = GEN_153;
  assign io_rocc_cmd_bits_status_spie = GEN_154;
  assign io_rocc_cmd_bits_status_upie = GEN_156;
  assign io_rocc_cmd_bits_status_mie = GEN_157;
  assign io_rocc_cmd_bits_status_hie = GEN_158;
  assign io_rocc_cmd_bits_status_sie = GEN_159;
  assign io_rocc_cmd_bits_status_uie = GEN_160;
  assign io_rocc_resp_ready = GEN_162;
  assign io_rocc_mem_req_ready = GEN_164;
  assign io_rocc_mem_s2_nack = GEN_165;
  assign io_rocc_mem_resp_valid = GEN_166;
  assign io_rocc_mem_resp_bits_addr = GEN_167;
  assign io_rocc_mem_resp_bits_tag = GEN_168;
  assign io_rocc_mem_resp_bits_cmd = GEN_170;
  assign io_rocc_mem_resp_bits_typ = GEN_172;
  assign io_rocc_mem_resp_bits_data = GEN_174;
  assign io_rocc_mem_resp_bits_replay = GEN_176;
  assign io_rocc_mem_resp_bits_has_data = GEN_178;
  assign io_rocc_mem_resp_bits_data_word_bypass = GEN_180;
  assign io_rocc_mem_resp_bits_store_data = GEN_181;
  assign io_rocc_mem_replay_next = GEN_182;
  assign io_rocc_mem_xcpt_ma_ld = GEN_184;
  assign io_rocc_mem_xcpt_ma_st = GEN_185;
  assign io_rocc_mem_xcpt_pf_ld = GEN_186;
  assign io_rocc_mem_xcpt_pf_st = GEN_187;
  assign io_rocc_mem_ordered = GEN_188;
  assign io_rocc_autl_acquire_ready = GEN_190;
  assign io_rocc_autl_grant_valid = GEN_191;
  assign io_rocc_autl_grant_bits_addr_beat = GEN_192;
  assign io_rocc_autl_grant_bits_client_xact_id = GEN_193;
  assign io_rocc_autl_grant_bits_manager_xact_id = GEN_194;
  assign io_rocc_autl_grant_bits_is_builtin_type = GEN_196;
  assign io_rocc_autl_grant_bits_g_type = GEN_198;
  assign io_rocc_autl_grant_bits_data = GEN_199;
  assign io_rocc_fpu_req_ready = GEN_200;
  assign io_rocc_fpu_resp_valid = GEN_201;
  assign io_rocc_fpu_resp_bits_data = GEN_202;
  assign io_rocc_fpu_resp_bits_exc = GEN_204;
  assign io_rocc_exception = GEN_206;
  assign io_interrupt = GEN_39;
  assign io_interrupt_cause = GEN_40;
  assign io_bp_0_control_ttype = reg_bp_0_control_ttype;
  assign io_bp_0_control_dmode = reg_bp_0_control_dmode;
  assign io_bp_0_control_maskmax = reg_bp_0_control_maskmax;
  assign io_bp_0_control_reserved = reg_bp_0_control_reserved;
  assign io_bp_0_control_action = reg_bp_0_control_action;
  assign io_bp_0_control_chain = reg_bp_0_control_chain;
  assign io_bp_0_control_zero = reg_bp_0_control_zero;
  assign io_bp_0_control_tmatch = reg_bp_0_control_tmatch;
  assign io_bp_0_control_m = reg_bp_0_control_m;
  assign io_bp_0_control_h = reg_bp_0_control_h;
  assign io_bp_0_control_s = reg_bp_0_control_s;
  assign io_bp_0_control_u = reg_bp_0_control_u;
  assign io_bp_0_control_x = reg_bp_0_control_x;
  assign io_bp_0_control_w = reg_bp_0_control_w;
  assign io_bp_0_control_r = reg_bp_0_control_r;
  assign io_bp_0_address = reg_bp_0_address;
  assign T_4258_debug = T_4310;
  assign T_4258_isa = T_4309;
  assign T_4258_prv = T_4308;
  assign T_4258_sd = T_4307;
  assign T_4258_zero3 = T_4306;
  assign T_4258_sd_rv32 = T_4305;
  assign T_4258_zero2 = T_4304;
  assign T_4258_vm = T_4303;
  assign T_4258_zero1 = T_4302;
  assign T_4258_mxr = T_4301;
  assign T_4258_pum = T_4300;
  assign T_4258_mprv = T_4299;
  assign T_4258_xs = T_4298;
  assign T_4258_fs = T_4297;
  assign T_4258_mpp = T_4296;
  assign T_4258_hpp = T_4295;
  assign T_4258_spp = T_4294;
  assign T_4258_mpie = T_4293;
  assign T_4258_hpie = T_4292;
  assign T_4258_spie = T_4291;
  assign T_4258_upie = T_4290;
  assign T_4258_mie = T_4289;
  assign T_4258_hie = T_4288;
  assign T_4258_sie = T_4287;
  assign T_4258_uie = T_4286;
  assign T_4285 = 99'h0;
  assign T_4286 = T_4285[0];
  assign T_4287 = T_4285[1];
  assign T_4288 = T_4285[2];
  assign T_4289 = T_4285[3];
  assign T_4290 = T_4285[4];
  assign T_4291 = T_4285[5];
  assign T_4292 = T_4285[6];
  assign T_4293 = T_4285[7];
  assign T_4294 = T_4285[8];
  assign T_4295 = T_4285[10:9];
  assign T_4296 = T_4285[12:11];
  assign T_4297 = T_4285[14:13];
  assign T_4298 = T_4285[16:15];
  assign T_4299 = T_4285[17];
  assign T_4300 = T_4285[18];
  assign T_4301 = T_4285[19];
  assign T_4302 = T_4285[23:20];
  assign T_4303 = T_4285[28:24];
  assign T_4304 = T_4285[30:29];
  assign T_4305 = T_4285[31];
  assign T_4306 = T_4285[62:32];
  assign T_4307 = T_4285[63];
  assign T_4308 = T_4285[65:64];
  assign T_4309 = T_4285[97:66];
  assign T_4310 = T_4285[98];
  assign reset_mstatus_debug = T_4258_debug;
  assign reset_mstatus_isa = T_4258_isa;
  assign reset_mstatus_prv = 2'h3;
  assign reset_mstatus_sd = T_4258_sd;
  assign reset_mstatus_zero3 = T_4258_zero3;
  assign reset_mstatus_sd_rv32 = T_4258_sd_rv32;
  assign reset_mstatus_zero2 = T_4258_zero2;
  assign reset_mstatus_vm = T_4258_vm;
  assign reset_mstatus_zero1 = T_4258_zero1;
  assign reset_mstatus_mxr = T_4258_mxr;
  assign reset_mstatus_pum = T_4258_pum;
  assign reset_mstatus_mprv = T_4258_mprv;
  assign reset_mstatus_xs = T_4258_xs;
  assign reset_mstatus_fs = T_4258_fs;
  assign reset_mstatus_mpp = 2'h3;
  assign reset_mstatus_hpp = T_4258_hpp;
  assign reset_mstatus_spp = T_4258_spp;
  assign reset_mstatus_mpie = T_4258_mpie;
  assign reset_mstatus_hpie = T_4258_hpie;
  assign reset_mstatus_spie = T_4258_spie;
  assign reset_mstatus_upie = T_4258_upie;
  assign reset_mstatus_mie = T_4258_mie;
  assign reset_mstatus_hie = T_4258_hie;
  assign reset_mstatus_sie = T_4258_sie;
  assign reset_mstatus_uie = T_4258_uie;
  assign new_prv = GEN_113;
  assign T_4363 = new_prv[0];
  assign T_4367 = T_4363 ? 2'h3 : 2'h0;
  assign T_4405_xdebugver = T_4441;
  assign T_4405_ndreset = T_4440;
  assign T_4405_fullreset = T_4439;
  assign T_4405_zero3 = T_4438;
  assign T_4405_ebreakm = T_4437;
  assign T_4405_ebreakh = T_4436;
  assign T_4405_ebreaks = T_4435;
  assign T_4405_ebreaku = T_4434;
  assign T_4405_zero2 = T_4433;
  assign T_4405_stopcycle = T_4432;
  assign T_4405_stoptime = T_4431;
  assign T_4405_cause = T_4430;
  assign T_4405_debugint = T_4429;
  assign T_4405_zero1 = T_4428;
  assign T_4405_halt = T_4427;
  assign T_4405_step = T_4426;
  assign T_4405_prv = T_4425;
  assign T_4424 = 32'h0;
  assign T_4425 = T_4424[1:0];
  assign T_4426 = T_4424[2];
  assign T_4427 = T_4424[3];
  assign T_4428 = T_4424[4];
  assign T_4429 = T_4424[5];
  assign T_4430 = T_4424[8:6];
  assign T_4431 = T_4424[9];
  assign T_4432 = T_4424[10];
  assign T_4433 = T_4424[11];
  assign T_4434 = T_4424[12];
  assign T_4435 = T_4424[13];
  assign T_4436 = T_4424[14];
  assign T_4437 = T_4424[15];
  assign T_4438 = T_4424[27:16];
  assign T_4439 = T_4424[28];
  assign T_4440 = T_4424[29];
  assign T_4441 = T_4424[31:30];
  assign reset_dcsr_xdebugver = 2'h1;
  assign reset_dcsr_ndreset = T_4405_ndreset;
  assign reset_dcsr_fullreset = T_4405_fullreset;
  assign reset_dcsr_zero3 = T_4405_zero3;
  assign reset_dcsr_ebreakm = T_4405_ebreakm;
  assign reset_dcsr_ebreakh = T_4405_ebreakh;
  assign reset_dcsr_ebreaks = T_4405_ebreaks;
  assign reset_dcsr_ebreaku = T_4405_ebreaku;
  assign reset_dcsr_zero2 = T_4405_zero2;
  assign reset_dcsr_stopcycle = T_4405_stopcycle;
  assign reset_dcsr_stoptime = T_4405_stoptime;
  assign reset_dcsr_cause = T_4405_cause;
  assign reset_dcsr_debugint = T_4405_debugint;
  assign reset_dcsr_zero1 = T_4405_zero1;
  assign reset_dcsr_halt = T_4405_halt;
  assign reset_dcsr_step = T_4405_step;
  assign reset_dcsr_prv = 2'h3;
  assign T_4507_rocc = T_4535;
  assign T_4507_meip = T_4534;
  assign T_4507_heip = T_4533;
  assign T_4507_seip = T_4532;
  assign T_4507_ueip = T_4531;
  assign T_4507_mtip = T_4530;
  assign T_4507_htip = T_4529;
  assign T_4507_stip = T_4528;
  assign T_4507_utip = T_4527;
  assign T_4507_msip = T_4526;
  assign T_4507_hsip = T_4525;
  assign T_4507_ssip = T_4524;
  assign T_4507_usip = T_4523;
  assign T_4522 = 13'h0;
  assign T_4523 = T_4522[0];
  assign T_4524 = T_4522[1];
  assign T_4525 = T_4522[2];
  assign T_4526 = T_4522[3];
  assign T_4527 = T_4522[4];
  assign T_4528 = T_4522[5];
  assign T_4529 = T_4522[6];
  assign T_4530 = T_4522[7];
  assign T_4531 = T_4522[8];
  assign T_4532 = T_4522[9];
  assign T_4533 = T_4522[10];
  assign T_4534 = T_4522[11];
  assign T_4535 = T_4522[12];
  assign T_4536_rocc = 1'h0;
  assign T_4536_meip = 1'h1;
  assign T_4536_heip = T_4507_heip;
  assign T_4536_seip = 1'h0;
  assign T_4536_ueip = T_4507_ueip;
  assign T_4536_mtip = 1'h1;
  assign T_4536_htip = T_4507_htip;
  assign T_4536_stip = 1'h0;
  assign T_4536_utip = T_4507_utip;
  assign T_4536_msip = 1'h1;
  assign T_4536_hsip = T_4507_hsip;
  assign T_4536_ssip = 1'h0;
  assign T_4536_usip = T_4507_usip;
  assign T_4557_rocc = T_4536_rocc;
  assign T_4557_meip = 1'h0;
  assign T_4557_heip = T_4536_heip;
  assign T_4557_seip = T_4536_seip;
  assign T_4557_ueip = T_4536_ueip;
  assign T_4557_mtip = 1'h0;
  assign T_4557_htip = T_4536_htip;
  assign T_4557_stip = T_4536_stip;
  assign T_4557_utip = T_4536_utip;
  assign T_4557_msip = 1'h0;
  assign T_4557_hsip = T_4536_hsip;
  assign T_4557_ssip = T_4536_ssip;
  assign T_4557_usip = T_4536_usip;
  assign T_4574 = {T_4536_hsip,T_4536_ssip};
  assign T_4575 = {T_4574,T_4536_usip};
  assign T_4576 = {T_4536_stip,T_4536_utip};
  assign T_4577 = {T_4576,T_4536_msip};
  assign T_4578 = {T_4577,T_4575};
  assign T_4579 = {T_4536_ueip,T_4536_mtip};
  assign T_4580 = {T_4579,T_4536_htip};
  assign T_4581 = {T_4536_heip,T_4536_seip};
  assign T_4582 = {T_4536_rocc,T_4536_meip};
  assign T_4583 = {T_4582,T_4581};
  assign T_4584 = {T_4583,T_4580};
  assign supported_interrupts = {T_4584,T_4578};
  assign exception = io_exception | io_csr_xcpt;
  assign T_4601 = io_retire | exception;
  assign GEN_35 = T_4601 ? 1'h1 : reg_singleStepped;
  assign T_4604 = io_singleStep == 1'h0;
  assign GEN_36 = T_4604 ? 1'h0 : GEN_35;
  assign T_4615 = reg_singleStepped == 1'h0;
  assign T_4617 = io_retire == 1'h0;
  assign T_4618 = T_4615 | T_4617;
  assign T_4619 = T_4618 | reset;
  assign T_4621 = T_4619 == 1'h0;
  assign GEN_0 = {{5'd0}, io_retire};
  assign T_4798 = T_4797 + GEN_0;
  assign T_4801 = T_4798[6];
  assign T_4803 = T_4800 + 58'h1;
  assign GEN_37 = T_4801 ? T_4803 : {{1'd0}, T_4800};
  assign T_4804 = {T_4800,T_4797};
  assign T_4808 = T_4807 + 6'h1;
  assign T_4811 = T_4808[6];
  assign T_4813 = T_4810 + 58'h1;
  assign GEN_38 = T_4811 ? T_4813 : {{1'd0}, T_4810};
  assign T_4814 = {T_4810,T_4807};
  assign mip_rocc = io_rocc_interrupt;
  assign mip_meip = reg_mip_meip;
  assign mip_heip = reg_mip_heip;
  assign mip_seip = reg_mip_seip;
  assign mip_ueip = reg_mip_ueip;
  assign mip_mtip = reg_mip_mtip;
  assign mip_htip = reg_mip_htip;
  assign mip_stip = reg_mip_stip;
  assign mip_utip = reg_mip_utip;
  assign mip_msip = reg_mip_msip;
  assign mip_hsip = reg_mip_hsip;
  assign mip_ssip = reg_mip_ssip;
  assign mip_usip = reg_mip_usip;
  assign T_4828 = {mip_hsip,mip_ssip};
  assign T_4829 = {T_4828,mip_usip};
  assign T_4830 = {mip_stip,mip_utip};
  assign T_4831 = {T_4830,mip_msip};
  assign T_4832 = {T_4831,T_4829};
  assign T_4833 = {mip_ueip,mip_mtip};
  assign T_4834 = {T_4833,mip_htip};
  assign T_4835 = {mip_heip,mip_seip};
  assign T_4836 = {mip_rocc,mip_meip};
  assign T_4837 = {T_4836,T_4835};
  assign T_4838 = {T_4837,T_4834};
  assign T_4839 = {T_4838,T_4832};
  assign read_mip = T_4839 & supported_interrupts;
  assign GEN_1 = {{19'd0}, read_mip};
  assign pending_interrupts = GEN_1 & reg_mie;
  assign T_4841 = reg_debug == 1'h0;
  assign T_4843 = reg_mstatus_prv < 2'h3;
  assign T_4845 = reg_mstatus_prv == 2'h3;
  assign T_4846 = T_4845 & reg_mstatus_mie;
  assign T_4847 = T_4843 | T_4846;
  assign T_4848 = T_4841 & T_4847;
  assign T_4849 = ~ reg_mideleg;
  assign T_4850 = pending_interrupts & T_4849;
  assign m_interrupts = T_4848 ? T_4850 : 32'h0;
  assign T_4855 = reg_mstatus_prv < 2'h1;
  assign T_4857 = reg_mstatus_prv == 2'h1;
  assign T_4858 = T_4857 & reg_mstatus_sie;
  assign T_4859 = T_4855 | T_4858;
  assign T_4860 = T_4841 & T_4859;
  assign T_4861 = pending_interrupts & reg_mideleg;
  assign s_interrupts = T_4860 ? T_4861 : 32'h0;
  assign all_interrupts = m_interrupts | s_interrupts;
  assign T_4864 = all_interrupts[0];
  assign T_4865 = all_interrupts[1];
  assign T_4866 = all_interrupts[2];
  assign T_4867 = all_interrupts[3];
  assign T_4868 = all_interrupts[4];
  assign T_4869 = all_interrupts[5];
  assign T_4870 = all_interrupts[6];
  assign T_4871 = all_interrupts[7];
  assign T_4872 = all_interrupts[8];
  assign T_4873 = all_interrupts[9];
  assign T_4874 = all_interrupts[10];
  assign T_4875 = all_interrupts[11];
  assign T_4876 = all_interrupts[12];
  assign T_4877 = all_interrupts[13];
  assign T_4878 = all_interrupts[14];
  assign T_4879 = all_interrupts[15];
  assign T_4880 = all_interrupts[16];
  assign T_4881 = all_interrupts[17];
  assign T_4882 = all_interrupts[18];
  assign T_4883 = all_interrupts[19];
  assign T_4884 = all_interrupts[20];
  assign T_4885 = all_interrupts[21];
  assign T_4886 = all_interrupts[22];
  assign T_4887 = all_interrupts[23];
  assign T_4888 = all_interrupts[24];
  assign T_4889 = all_interrupts[25];
  assign T_4890 = all_interrupts[26];
  assign T_4891 = all_interrupts[27];
  assign T_4892 = all_interrupts[28];
  assign T_4893 = all_interrupts[29];
  assign T_4894 = all_interrupts[30];
  assign T_4928 = T_4894 ? 5'h1e : 5'h1f;
  assign T_4929 = T_4893 ? 5'h1d : T_4928;
  assign T_4930 = T_4892 ? 5'h1c : T_4929;
  assign T_4931 = T_4891 ? 5'h1b : T_4930;
  assign T_4932 = T_4890 ? 5'h1a : T_4931;
  assign T_4933 = T_4889 ? 5'h19 : T_4932;
  assign T_4934 = T_4888 ? 5'h18 : T_4933;
  assign T_4935 = T_4887 ? 5'h17 : T_4934;
  assign T_4936 = T_4886 ? 5'h16 : T_4935;
  assign T_4937 = T_4885 ? 5'h15 : T_4936;
  assign T_4938 = T_4884 ? 5'h14 : T_4937;
  assign T_4939 = T_4883 ? 5'h13 : T_4938;
  assign T_4940 = T_4882 ? 5'h12 : T_4939;
  assign T_4941 = T_4881 ? 5'h11 : T_4940;
  assign T_4942 = T_4880 ? 5'h10 : T_4941;
  assign T_4943 = T_4879 ? 5'hf : T_4942;
  assign T_4944 = T_4878 ? 5'he : T_4943;
  assign T_4945 = T_4877 ? 5'hd : T_4944;
  assign T_4946 = T_4876 ? 5'hc : T_4945;
  assign T_4947 = T_4875 ? 5'hb : T_4946;
  assign T_4948 = T_4874 ? 5'ha : T_4947;
  assign T_4949 = T_4873 ? 5'h9 : T_4948;
  assign T_4950 = T_4872 ? 5'h8 : T_4949;
  assign T_4951 = T_4871 ? 5'h7 : T_4950;
  assign T_4952 = T_4870 ? 5'h6 : T_4951;
  assign T_4953 = T_4869 ? 5'h5 : T_4952;
  assign T_4954 = T_4868 ? 5'h4 : T_4953;
  assign T_4955 = T_4867 ? 5'h3 : T_4954;
  assign T_4956 = T_4866 ? 5'h2 : T_4955;
  assign T_4957 = T_4865 ? 5'h1 : T_4956;
  assign T_4958 = T_4864 ? 5'h0 : T_4957;
  assign GEN_2 = {{27'd0}, T_4958};
  assign T_4959 = 32'h80000000 + GEN_2;
  assign interruptCause = T_4959[31:0];
  assign T_4961 = all_interrupts != 32'h0;
  assign T_4964 = T_4961 & T_4604;
  assign T_4965 = T_4964 | reg_singleStepped;
  assign T_4970 = reg_dcsr_debugint & T_4841;
  assign T_4974 = 32'h80000000 + 32'hd;
  assign T_4975 = T_4974[31:0];
  assign GEN_39 = T_4970 ? 1'h1 : T_4965;
  assign GEN_40 = T_4970 ? T_4975 : interruptCause;
  assign system_insn = io_rw_cmd == 3'h4;
  assign T_4976 = io_rw_cmd != 3'h0;
  assign T_4978 = system_insn == 1'h0;
  assign cpu_ren = T_4976 & T_4978;
  assign T_4979 = io_rw_cmd != 3'h5;
  assign cpu_wen = cpu_ren & T_4979;
  assign T_4981 = {io_status_hie,io_status_sie};
  assign T_4982 = {T_4981,io_status_uie};
  assign T_4983 = {io_status_spie,io_status_upie};
  assign T_4984 = {T_4983,io_status_mie};
  assign T_4985 = {T_4984,T_4982};
  assign T_4986 = {io_status_spp,io_status_mpie};
  assign T_4987 = {T_4986,io_status_hpie};
  assign T_4988 = {io_status_fs,io_status_mpp};
  assign T_4989 = {T_4988,io_status_hpp};
  assign T_4990 = {T_4989,T_4987};
  assign T_4991 = {T_4990,T_4985};
  assign T_4992 = {io_status_pum,io_status_mprv};
  assign T_4993 = {T_4992,io_status_xs};
  assign T_4994 = {io_status_vm,io_status_zero1};
  assign T_4995 = {T_4994,io_status_mxr};
  assign T_4996 = {T_4995,T_4993};
  assign T_4997 = {io_status_zero3,io_status_sd_rv32};
  assign T_4998 = {T_4997,io_status_zero2};
  assign T_4999 = {io_status_prv,io_status_sd};
  assign T_5000 = {io_status_debug,io_status_isa};
  assign T_5001 = {T_5000,T_4999};
  assign T_5002 = {T_5001,T_4998};
  assign T_5003 = {T_5002,T_4996};
  assign T_5004 = {T_5003,T_4991};
  assign read_mstatus = T_5004[31:0];
  assign GEN_0_control_ttype = GEN_41;
  assign GEN_0_control_dmode = GEN_42;
  assign GEN_0_control_maskmax = GEN_43;
  assign GEN_0_control_reserved = GEN_44;
  assign GEN_0_control_action = GEN_45;
  assign GEN_0_control_chain = GEN_46;
  assign GEN_0_control_zero = GEN_47;
  assign GEN_0_control_tmatch = GEN_48;
  assign GEN_0_control_m = GEN_49;
  assign GEN_0_control_h = GEN_50;
  assign GEN_0_control_s = GEN_51;
  assign GEN_0_control_u = GEN_52;
  assign GEN_0_control_x = GEN_53;
  assign GEN_0_control_w = GEN_54;
  assign GEN_0_control_r = GEN_55;
  assign GEN_0_address = GEN_56;
  assign GEN_41 = reg_tselect ? reg_bp_1_control_ttype : reg_bp_0_control_ttype;
  assign GEN_42 = reg_tselect ? reg_bp_1_control_dmode : reg_bp_0_control_dmode;
  assign GEN_43 = reg_tselect ? reg_bp_1_control_maskmax : reg_bp_0_control_maskmax;
  assign GEN_44 = reg_tselect ? reg_bp_1_control_reserved : reg_bp_0_control_reserved;
  assign GEN_45 = reg_tselect ? reg_bp_1_control_action : reg_bp_0_control_action;
  assign GEN_46 = reg_tselect ? reg_bp_1_control_chain : reg_bp_0_control_chain;
  assign GEN_47 = reg_tselect ? reg_bp_1_control_zero : reg_bp_0_control_zero;
  assign GEN_48 = reg_tselect ? reg_bp_1_control_tmatch : reg_bp_0_control_tmatch;
  assign GEN_49 = reg_tselect ? reg_bp_1_control_m : reg_bp_0_control_m;
  assign GEN_50 = reg_tselect ? reg_bp_1_control_h : reg_bp_0_control_h;
  assign GEN_51 = reg_tselect ? reg_bp_1_control_s : reg_bp_0_control_s;
  assign GEN_52 = reg_tselect ? reg_bp_1_control_u : reg_bp_0_control_u;
  assign GEN_53 = reg_tselect ? reg_bp_1_control_x : reg_bp_0_control_x;
  assign GEN_54 = reg_tselect ? reg_bp_1_control_w : reg_bp_0_control_w;
  assign GEN_55 = reg_tselect ? reg_bp_1_control_r : reg_bp_0_control_r;
  assign GEN_56 = reg_tselect ? reg_bp_1_address : reg_bp_0_address;
  assign GEN_1_control_ttype = GEN_41;
  assign GEN_1_control_dmode = GEN_42;
  assign GEN_1_control_maskmax = GEN_43;
  assign GEN_1_control_reserved = GEN_44;
  assign GEN_1_control_action = GEN_45;
  assign GEN_1_control_chain = GEN_46;
  assign GEN_1_control_zero = GEN_47;
  assign GEN_1_control_tmatch = GEN_48;
  assign GEN_1_control_m = GEN_49;
  assign GEN_1_control_h = GEN_50;
  assign GEN_1_control_s = GEN_51;
  assign GEN_1_control_u = GEN_52;
  assign GEN_1_control_x = GEN_53;
  assign GEN_1_control_w = GEN_54;
  assign GEN_1_control_r = GEN_55;
  assign GEN_1_address = GEN_56;
  assign T_5022 = {GEN_0_control_x,GEN_1_control_w};
  assign GEN_2_control_ttype = GEN_41;
  assign GEN_2_control_dmode = GEN_42;
  assign GEN_2_control_maskmax = GEN_43;
  assign GEN_2_control_reserved = GEN_44;
  assign GEN_2_control_action = GEN_45;
  assign GEN_2_control_chain = GEN_46;
  assign GEN_2_control_zero = GEN_47;
  assign GEN_2_control_tmatch = GEN_48;
  assign GEN_2_control_m = GEN_49;
  assign GEN_2_control_h = GEN_50;
  assign GEN_2_control_s = GEN_51;
  assign GEN_2_control_u = GEN_52;
  assign GEN_2_control_x = GEN_53;
  assign GEN_2_control_w = GEN_54;
  assign GEN_2_control_r = GEN_55;
  assign GEN_2_address = GEN_56;
  assign T_5023 = {T_5022,GEN_2_control_r};
  assign GEN_3_control_ttype = GEN_41;
  assign GEN_3_control_dmode = GEN_42;
  assign GEN_3_control_maskmax = GEN_43;
  assign GEN_3_control_reserved = GEN_44;
  assign GEN_3_control_action = GEN_45;
  assign GEN_3_control_chain = GEN_46;
  assign GEN_3_control_zero = GEN_47;
  assign GEN_3_control_tmatch = GEN_48;
  assign GEN_3_control_m = GEN_49;
  assign GEN_3_control_h = GEN_50;
  assign GEN_3_control_s = GEN_51;
  assign GEN_3_control_u = GEN_52;
  assign GEN_3_control_x = GEN_53;
  assign GEN_3_control_w = GEN_54;
  assign GEN_3_control_r = GEN_55;
  assign GEN_3_address = GEN_56;
  assign GEN_4_control_ttype = GEN_41;
  assign GEN_4_control_dmode = GEN_42;
  assign GEN_4_control_maskmax = GEN_43;
  assign GEN_4_control_reserved = GEN_44;
  assign GEN_4_control_action = GEN_45;
  assign GEN_4_control_chain = GEN_46;
  assign GEN_4_control_zero = GEN_47;
  assign GEN_4_control_tmatch = GEN_48;
  assign GEN_4_control_m = GEN_49;
  assign GEN_4_control_h = GEN_50;
  assign GEN_4_control_s = GEN_51;
  assign GEN_4_control_u = GEN_52;
  assign GEN_4_control_x = GEN_53;
  assign GEN_4_control_w = GEN_54;
  assign GEN_4_control_r = GEN_55;
  assign GEN_4_address = GEN_56;
  assign T_5024 = {GEN_3_control_s,GEN_4_control_u};
  assign GEN_5_control_ttype = GEN_41;
  assign GEN_5_control_dmode = GEN_42;
  assign GEN_5_control_maskmax = GEN_43;
  assign GEN_5_control_reserved = GEN_44;
  assign GEN_5_control_action = GEN_45;
  assign GEN_5_control_chain = GEN_46;
  assign GEN_5_control_zero = GEN_47;
  assign GEN_5_control_tmatch = GEN_48;
  assign GEN_5_control_m = GEN_49;
  assign GEN_5_control_h = GEN_50;
  assign GEN_5_control_s = GEN_51;
  assign GEN_5_control_u = GEN_52;
  assign GEN_5_control_x = GEN_53;
  assign GEN_5_control_w = GEN_54;
  assign GEN_5_control_r = GEN_55;
  assign GEN_5_address = GEN_56;
  assign GEN_6_control_ttype = GEN_41;
  assign GEN_6_control_dmode = GEN_42;
  assign GEN_6_control_maskmax = GEN_43;
  assign GEN_6_control_reserved = GEN_44;
  assign GEN_6_control_action = GEN_45;
  assign GEN_6_control_chain = GEN_46;
  assign GEN_6_control_zero = GEN_47;
  assign GEN_6_control_tmatch = GEN_48;
  assign GEN_6_control_m = GEN_49;
  assign GEN_6_control_h = GEN_50;
  assign GEN_6_control_s = GEN_51;
  assign GEN_6_control_u = GEN_52;
  assign GEN_6_control_x = GEN_53;
  assign GEN_6_control_w = GEN_54;
  assign GEN_6_control_r = GEN_55;
  assign GEN_6_address = GEN_56;
  assign T_5025 = {GEN_5_control_m,GEN_6_control_h};
  assign T_5026 = {T_5025,T_5024};
  assign T_5027 = {T_5026,T_5023};
  assign GEN_7_control_ttype = GEN_41;
  assign GEN_7_control_dmode = GEN_42;
  assign GEN_7_control_maskmax = GEN_43;
  assign GEN_7_control_reserved = GEN_44;
  assign GEN_7_control_action = GEN_45;
  assign GEN_7_control_chain = GEN_46;
  assign GEN_7_control_zero = GEN_47;
  assign GEN_7_control_tmatch = GEN_48;
  assign GEN_7_control_m = GEN_49;
  assign GEN_7_control_h = GEN_50;
  assign GEN_7_control_s = GEN_51;
  assign GEN_7_control_u = GEN_52;
  assign GEN_7_control_x = GEN_53;
  assign GEN_7_control_w = GEN_54;
  assign GEN_7_control_r = GEN_55;
  assign GEN_7_address = GEN_56;
  assign GEN_8_control_ttype = GEN_41;
  assign GEN_8_control_dmode = GEN_42;
  assign GEN_8_control_maskmax = GEN_43;
  assign GEN_8_control_reserved = GEN_44;
  assign GEN_8_control_action = GEN_45;
  assign GEN_8_control_chain = GEN_46;
  assign GEN_8_control_zero = GEN_47;
  assign GEN_8_control_tmatch = GEN_48;
  assign GEN_8_control_m = GEN_49;
  assign GEN_8_control_h = GEN_50;
  assign GEN_8_control_s = GEN_51;
  assign GEN_8_control_u = GEN_52;
  assign GEN_8_control_x = GEN_53;
  assign GEN_8_control_w = GEN_54;
  assign GEN_8_control_r = GEN_55;
  assign GEN_8_address = GEN_56;
  assign T_5028 = {GEN_7_control_zero,GEN_8_control_tmatch};
  assign GEN_9_control_ttype = GEN_41;
  assign GEN_9_control_dmode = GEN_42;
  assign GEN_9_control_maskmax = GEN_43;
  assign GEN_9_control_reserved = GEN_44;
  assign GEN_9_control_action = GEN_45;
  assign GEN_9_control_chain = GEN_46;
  assign GEN_9_control_zero = GEN_47;
  assign GEN_9_control_tmatch = GEN_48;
  assign GEN_9_control_m = GEN_49;
  assign GEN_9_control_h = GEN_50;
  assign GEN_9_control_s = GEN_51;
  assign GEN_9_control_u = GEN_52;
  assign GEN_9_control_x = GEN_53;
  assign GEN_9_control_w = GEN_54;
  assign GEN_9_control_r = GEN_55;
  assign GEN_9_address = GEN_56;
  assign GEN_10_control_ttype = GEN_41;
  assign GEN_10_control_dmode = GEN_42;
  assign GEN_10_control_maskmax = GEN_43;
  assign GEN_10_control_reserved = GEN_44;
  assign GEN_10_control_action = GEN_45;
  assign GEN_10_control_chain = GEN_46;
  assign GEN_10_control_zero = GEN_47;
  assign GEN_10_control_tmatch = GEN_48;
  assign GEN_10_control_m = GEN_49;
  assign GEN_10_control_h = GEN_50;
  assign GEN_10_control_s = GEN_51;
  assign GEN_10_control_u = GEN_52;
  assign GEN_10_control_x = GEN_53;
  assign GEN_10_control_w = GEN_54;
  assign GEN_10_control_r = GEN_55;
  assign GEN_10_address = GEN_56;
  assign T_5029 = {GEN_9_control_action,GEN_10_control_chain};
  assign T_5030 = {T_5029,T_5028};
  assign GEN_11_control_ttype = GEN_41;
  assign GEN_11_control_dmode = GEN_42;
  assign GEN_11_control_maskmax = GEN_43;
  assign GEN_11_control_reserved = GEN_44;
  assign GEN_11_control_action = GEN_45;
  assign GEN_11_control_chain = GEN_46;
  assign GEN_11_control_zero = GEN_47;
  assign GEN_11_control_tmatch = GEN_48;
  assign GEN_11_control_m = GEN_49;
  assign GEN_11_control_h = GEN_50;
  assign GEN_11_control_s = GEN_51;
  assign GEN_11_control_u = GEN_52;
  assign GEN_11_control_x = GEN_53;
  assign GEN_11_control_w = GEN_54;
  assign GEN_11_control_r = GEN_55;
  assign GEN_11_address = GEN_56;
  assign GEN_12_control_ttype = GEN_41;
  assign GEN_12_control_dmode = GEN_42;
  assign GEN_12_control_maskmax = GEN_43;
  assign GEN_12_control_reserved = GEN_44;
  assign GEN_12_control_action = GEN_45;
  assign GEN_12_control_chain = GEN_46;
  assign GEN_12_control_zero = GEN_47;
  assign GEN_12_control_tmatch = GEN_48;
  assign GEN_12_control_m = GEN_49;
  assign GEN_12_control_h = GEN_50;
  assign GEN_12_control_s = GEN_51;
  assign GEN_12_control_u = GEN_52;
  assign GEN_12_control_x = GEN_53;
  assign GEN_12_control_w = GEN_54;
  assign GEN_12_control_r = GEN_55;
  assign GEN_12_address = GEN_56;
  assign T_5031 = {GEN_11_control_maskmax,GEN_12_control_reserved};
  assign GEN_13_control_ttype = GEN_41;
  assign GEN_13_control_dmode = GEN_42;
  assign GEN_13_control_maskmax = GEN_43;
  assign GEN_13_control_reserved = GEN_44;
  assign GEN_13_control_action = GEN_45;
  assign GEN_13_control_chain = GEN_46;
  assign GEN_13_control_zero = GEN_47;
  assign GEN_13_control_tmatch = GEN_48;
  assign GEN_13_control_m = GEN_49;
  assign GEN_13_control_h = GEN_50;
  assign GEN_13_control_s = GEN_51;
  assign GEN_13_control_u = GEN_52;
  assign GEN_13_control_x = GEN_53;
  assign GEN_13_control_w = GEN_54;
  assign GEN_13_control_r = GEN_55;
  assign GEN_13_address = GEN_56;
  assign GEN_14_control_ttype = GEN_41;
  assign GEN_14_control_dmode = GEN_42;
  assign GEN_14_control_maskmax = GEN_43;
  assign GEN_14_control_reserved = GEN_44;
  assign GEN_14_control_action = GEN_45;
  assign GEN_14_control_chain = GEN_46;
  assign GEN_14_control_zero = GEN_47;
  assign GEN_14_control_tmatch = GEN_48;
  assign GEN_14_control_m = GEN_49;
  assign GEN_14_control_h = GEN_50;
  assign GEN_14_control_s = GEN_51;
  assign GEN_14_control_u = GEN_52;
  assign GEN_14_control_x = GEN_53;
  assign GEN_14_control_w = GEN_54;
  assign GEN_14_control_r = GEN_55;
  assign GEN_14_address = GEN_56;
  assign T_5032 = {GEN_13_control_ttype,GEN_14_control_dmode};
  assign T_5033 = {T_5032,T_5031};
  assign T_5034 = {T_5033,T_5030};
  assign T_5035 = {T_5034,T_5027};
  assign T_5056 = {reg_dcsr_step,reg_dcsr_prv};
  assign T_5057 = {reg_dcsr_zero1,reg_dcsr_halt};
  assign T_5058 = {T_5057,T_5056};
  assign T_5059 = {reg_dcsr_cause,reg_dcsr_debugint};
  assign T_5060 = {reg_dcsr_stopcycle,reg_dcsr_stoptime};
  assign T_5061 = {T_5060,T_5059};
  assign T_5062 = {T_5061,T_5058};
  assign T_5063 = {reg_dcsr_ebreaku,reg_dcsr_zero2};
  assign T_5064 = {reg_dcsr_ebreakh,reg_dcsr_ebreaks};
  assign T_5065 = {T_5064,T_5063};
  assign T_5066 = {reg_dcsr_zero3,reg_dcsr_ebreakm};
  assign T_5067 = {reg_dcsr_xdebugver,reg_dcsr_ndreset};
  assign T_5068 = {T_5067,reg_dcsr_fullreset};
  assign T_5069 = {T_5068,T_5066};
  assign T_5070 = {T_5069,T_5065};
  assign T_5071 = {T_5070,T_5062};
  assign T_5075 = T_4814[63:32];
  assign T_5076 = T_4804[63:32];
  assign T_5080 = io_rw_addr == 12'h7a0;
  assign T_5082 = io_rw_addr == 12'h7a1;
  assign T_5084 = io_rw_addr == 12'h7a2;
  assign T_5086 = io_rw_addr == 12'hf13;
  assign T_5088 = io_rw_addr == 12'hf12;
  assign T_5090 = io_rw_addr == 12'hf11;
  assign T_5092 = io_rw_addr == 12'hb00;
  assign T_5094 = io_rw_addr == 12'hb02;
  assign T_5096 = io_rw_addr == 12'h301;
  assign T_5098 = io_rw_addr == 12'h300;
  assign T_5100 = io_rw_addr == 12'h305;
  assign T_5102 = io_rw_addr == 12'h344;
  assign T_5104 = io_rw_addr == 12'h304;
  assign T_5106 = io_rw_addr == 12'h303;
  assign T_5108 = io_rw_addr == 12'h302;
  assign T_5110 = io_rw_addr == 12'h340;
  assign T_5112 = io_rw_addr == 12'h341;
  assign T_5114 = io_rw_addr == 12'h343;
  assign T_5116 = io_rw_addr == 12'h342;
  assign T_5118 = io_rw_addr == 12'hf14;
  assign T_5120 = io_rw_addr == 12'h7b0;
  assign T_5122 = io_rw_addr == 12'h7b1;
  assign T_5124 = io_rw_addr == 12'h7b2;
  assign T_5126 = io_rw_addr == 12'h323;
  assign T_5128 = io_rw_addr == 12'hb03;
  assign T_5130 = io_rw_addr == 12'hc03;
  assign T_5132 = io_rw_addr == 12'h324;
  assign T_5134 = io_rw_addr == 12'hb04;
  assign T_5136 = io_rw_addr == 12'hc04;
  assign T_5138 = io_rw_addr == 12'h325;
  assign T_5140 = io_rw_addr == 12'hb05;
  assign T_5142 = io_rw_addr == 12'hc05;
  assign T_5144 = io_rw_addr == 12'h326;
  assign T_5146 = io_rw_addr == 12'hb06;
  assign T_5148 = io_rw_addr == 12'hc06;
  assign T_5150 = io_rw_addr == 12'h327;
  assign T_5152 = io_rw_addr == 12'hb07;
  assign T_5154 = io_rw_addr == 12'hc07;
  assign T_5156 = io_rw_addr == 12'h328;
  assign T_5158 = io_rw_addr == 12'hb08;
  assign T_5160 = io_rw_addr == 12'hc08;
  assign T_5162 = io_rw_addr == 12'h329;
  assign T_5164 = io_rw_addr == 12'hb09;
  assign T_5166 = io_rw_addr == 12'hc09;
  assign T_5168 = io_rw_addr == 12'h32a;
  assign T_5170 = io_rw_addr == 12'hb0a;
  assign T_5172 = io_rw_addr == 12'hc0a;
  assign T_5174 = io_rw_addr == 12'h32b;
  assign T_5176 = io_rw_addr == 12'hb0b;
  assign T_5178 = io_rw_addr == 12'hc0b;
  assign T_5180 = io_rw_addr == 12'h32c;
  assign T_5182 = io_rw_addr == 12'hb0c;
  assign T_5184 = io_rw_addr == 12'hc0c;
  assign T_5186 = io_rw_addr == 12'h32d;
  assign T_5188 = io_rw_addr == 12'hb0d;
  assign T_5190 = io_rw_addr == 12'hc0d;
  assign T_5192 = io_rw_addr == 12'h32e;
  assign T_5194 = io_rw_addr == 12'hb0e;
  assign T_5196 = io_rw_addr == 12'hc0e;
  assign T_5198 = io_rw_addr == 12'h32f;
  assign T_5200 = io_rw_addr == 12'hb0f;
  assign T_5202 = io_rw_addr == 12'hc0f;
  assign T_5204 = io_rw_addr == 12'h330;
  assign T_5206 = io_rw_addr == 12'hb10;
  assign T_5208 = io_rw_addr == 12'hc10;
  assign T_5210 = io_rw_addr == 12'h331;
  assign T_5212 = io_rw_addr == 12'hb11;
  assign T_5214 = io_rw_addr == 12'hc11;
  assign T_5216 = io_rw_addr == 12'h332;
  assign T_5218 = io_rw_addr == 12'hb12;
  assign T_5220 = io_rw_addr == 12'hc12;
  assign T_5222 = io_rw_addr == 12'h333;
  assign T_5224 = io_rw_addr == 12'hb13;
  assign T_5226 = io_rw_addr == 12'hc13;
  assign T_5228 = io_rw_addr == 12'h334;
  assign T_5230 = io_rw_addr == 12'hb14;
  assign T_5232 = io_rw_addr == 12'hc14;
  assign T_5234 = io_rw_addr == 12'h335;
  assign T_5236 = io_rw_addr == 12'hb15;
  assign T_5238 = io_rw_addr == 12'hc15;
  assign T_5240 = io_rw_addr == 12'h336;
  assign T_5242 = io_rw_addr == 12'hb16;
  assign T_5244 = io_rw_addr == 12'hc16;
  assign T_5246 = io_rw_addr == 12'h337;
  assign T_5248 = io_rw_addr == 12'hb17;
  assign T_5250 = io_rw_addr == 12'hc17;
  assign T_5252 = io_rw_addr == 12'h338;
  assign T_5254 = io_rw_addr == 12'hb18;
  assign T_5256 = io_rw_addr == 12'hc18;
  assign T_5258 = io_rw_addr == 12'h339;
  assign T_5260 = io_rw_addr == 12'hb19;
  assign T_5262 = io_rw_addr == 12'hc19;
  assign T_5264 = io_rw_addr == 12'h33a;
  assign T_5266 = io_rw_addr == 12'hb1a;
  assign T_5268 = io_rw_addr == 12'hc1a;
  assign T_5270 = io_rw_addr == 12'h33b;
  assign T_5272 = io_rw_addr == 12'hb1b;
  assign T_5274 = io_rw_addr == 12'hc1b;
  assign T_5276 = io_rw_addr == 12'h33c;
  assign T_5278 = io_rw_addr == 12'hb1c;
  assign T_5280 = io_rw_addr == 12'hc1c;
  assign T_5282 = io_rw_addr == 12'h33d;
  assign T_5284 = io_rw_addr == 12'hb1d;
  assign T_5286 = io_rw_addr == 12'hc1d;
  assign T_5288 = io_rw_addr == 12'h33e;
  assign T_5290 = io_rw_addr == 12'hb1e;
  assign T_5292 = io_rw_addr == 12'hc1e;
  assign T_5294 = io_rw_addr == 12'h33f;
  assign T_5296 = io_rw_addr == 12'hb1f;
  assign T_5298 = io_rw_addr == 12'hc1f;
  assign T_5300 = io_rw_addr == 12'h320;
  assign T_5302 = io_rw_addr == 12'hc00;
  assign T_5304 = io_rw_addr == 12'hc02;
  assign T_5306 = io_rw_addr == 12'hb80;
  assign T_5308 = io_rw_addr == 12'hb82;
  assign T_5310 = io_rw_addr == 12'hc80;
  assign T_5312 = io_rw_addr == 12'hc82;
  assign T_5313 = T_5080 | T_5082;
  assign T_5314 = T_5313 | T_5084;
  assign T_5315 = T_5314 | T_5086;
  assign T_5316 = T_5315 | T_5088;
  assign T_5317 = T_5316 | T_5090;
  assign T_5318 = T_5317 | T_5092;
  assign T_5319 = T_5318 | T_5094;
  assign T_5320 = T_5319 | T_5096;
  assign T_5321 = T_5320 | T_5098;
  assign T_5322 = T_5321 | T_5100;
  assign T_5323 = T_5322 | T_5102;
  assign T_5324 = T_5323 | T_5104;
  assign T_5325 = T_5324 | T_5106;
  assign T_5326 = T_5325 | T_5108;
  assign T_5327 = T_5326 | T_5110;
  assign T_5328 = T_5327 | T_5112;
  assign T_5329 = T_5328 | T_5114;
  assign T_5330 = T_5329 | T_5116;
  assign T_5331 = T_5330 | T_5118;
  assign T_5332 = T_5331 | T_5120;
  assign T_5333 = T_5332 | T_5122;
  assign T_5334 = T_5333 | T_5124;
  assign T_5335 = T_5334 | T_5126;
  assign T_5336 = T_5335 | T_5128;
  assign T_5337 = T_5336 | T_5130;
  assign T_5338 = T_5337 | T_5132;
  assign T_5339 = T_5338 | T_5134;
  assign T_5340 = T_5339 | T_5136;
  assign T_5341 = T_5340 | T_5138;
  assign T_5342 = T_5341 | T_5140;
  assign T_5343 = T_5342 | T_5142;
  assign T_5344 = T_5343 | T_5144;
  assign T_5345 = T_5344 | T_5146;
  assign T_5346 = T_5345 | T_5148;
  assign T_5347 = T_5346 | T_5150;
  assign T_5348 = T_5347 | T_5152;
  assign T_5349 = T_5348 | T_5154;
  assign T_5350 = T_5349 | T_5156;
  assign T_5351 = T_5350 | T_5158;
  assign T_5352 = T_5351 | T_5160;
  assign T_5353 = T_5352 | T_5162;
  assign T_5354 = T_5353 | T_5164;
  assign T_5355 = T_5354 | T_5166;
  assign T_5356 = T_5355 | T_5168;
  assign T_5357 = T_5356 | T_5170;
  assign T_5358 = T_5357 | T_5172;
  assign T_5359 = T_5358 | T_5174;
  assign T_5360 = T_5359 | T_5176;
  assign T_5361 = T_5360 | T_5178;
  assign T_5362 = T_5361 | T_5180;
  assign T_5363 = T_5362 | T_5182;
  assign T_5364 = T_5363 | T_5184;
  assign T_5365 = T_5364 | T_5186;
  assign T_5366 = T_5365 | T_5188;
  assign T_5367 = T_5366 | T_5190;
  assign T_5368 = T_5367 | T_5192;
  assign T_5369 = T_5368 | T_5194;
  assign T_5370 = T_5369 | T_5196;
  assign T_5371 = T_5370 | T_5198;
  assign T_5372 = T_5371 | T_5200;
  assign T_5373 = T_5372 | T_5202;
  assign T_5374 = T_5373 | T_5204;
  assign T_5375 = T_5374 | T_5206;
  assign T_5376 = T_5375 | T_5208;
  assign T_5377 = T_5376 | T_5210;
  assign T_5378 = T_5377 | T_5212;
  assign T_5379 = T_5378 | T_5214;
  assign T_5380 = T_5379 | T_5216;
  assign T_5381 = T_5380 | T_5218;
  assign T_5382 = T_5381 | T_5220;
  assign T_5383 = T_5382 | T_5222;
  assign T_5384 = T_5383 | T_5224;
  assign T_5385 = T_5384 | T_5226;
  assign T_5386 = T_5385 | T_5228;
  assign T_5387 = T_5386 | T_5230;
  assign T_5388 = T_5387 | T_5232;
  assign T_5389 = T_5388 | T_5234;
  assign T_5390 = T_5389 | T_5236;
  assign T_5391 = T_5390 | T_5238;
  assign T_5392 = T_5391 | T_5240;
  assign T_5393 = T_5392 | T_5242;
  assign T_5394 = T_5393 | T_5244;
  assign T_5395 = T_5394 | T_5246;
  assign T_5396 = T_5395 | T_5248;
  assign T_5397 = T_5396 | T_5250;
  assign T_5398 = T_5397 | T_5252;
  assign T_5399 = T_5398 | T_5254;
  assign T_5400 = T_5399 | T_5256;
  assign T_5401 = T_5400 | T_5258;
  assign T_5402 = T_5401 | T_5260;
  assign T_5403 = T_5402 | T_5262;
  assign T_5404 = T_5403 | T_5264;
  assign T_5405 = T_5404 | T_5266;
  assign T_5406 = T_5405 | T_5268;
  assign T_5407 = T_5406 | T_5270;
  assign T_5408 = T_5407 | T_5272;
  assign T_5409 = T_5408 | T_5274;
  assign T_5410 = T_5409 | T_5276;
  assign T_5411 = T_5410 | T_5278;
  assign T_5412 = T_5411 | T_5280;
  assign T_5413 = T_5412 | T_5282;
  assign T_5414 = T_5413 | T_5284;
  assign T_5415 = T_5414 | T_5286;
  assign T_5416 = T_5415 | T_5288;
  assign T_5417 = T_5416 | T_5290;
  assign T_5418 = T_5417 | T_5292;
  assign T_5419 = T_5418 | T_5294;
  assign T_5420 = T_5419 | T_5296;
  assign T_5421 = T_5420 | T_5298;
  assign T_5422 = T_5421 | T_5300;
  assign T_5423 = T_5422 | T_5302;
  assign T_5424 = T_5423 | T_5304;
  assign T_5425 = T_5424 | T_5306;
  assign T_5426 = T_5425 | T_5308;
  assign T_5427 = T_5426 | T_5310;
  assign addr_valid = T_5427 | T_5312;
  assign T_5429 = io_rw_addr >= 12'hc00;
  assign T_5431 = io_rw_addr < 12'hc20;
  assign hpm_csr = T_5429 & T_5431;
  assign T_5434 = reg_debug | T_4845;
  assign T_5437 = io_rw_addr[4:0];
  assign T_5438 = reg_mscounteren >> T_5437;
  assign T_5439 = T_5438[0];
  assign T_5440 = T_4857 & T_5439;
  assign T_5441 = T_5434 | T_5440;
  assign T_5443 = reg_mstatus_prv == 2'h0;
  assign T_5445 = reg_mucounteren >> T_5437;
  assign T_5446 = T_5445[0];
  assign T_5447 = T_5443 & T_5446;
  assign hpm_en = T_5441 | T_5447;
  assign csr_addr_priv = io_rw_addr[9:8];
  assign T_5450 = io_rw_addr & 12'h90;
  assign T_5452 = T_5450 == 12'h90;
  assign T_5454 = T_5452 == 1'h0;
  assign T_5455 = reg_mstatus_prv >= csr_addr_priv;
  assign T_5456 = T_5454 & T_5455;
  assign priv_sufficient = reg_debug | T_5456;
  assign T_5457 = io_rw_addr[11:10];
  assign T_5458 = ~ T_5457;
  assign read_only = T_5458 == 2'h0;
  assign T_5460 = cpu_wen & priv_sufficient;
  assign T_5462 = read_only == 1'h0;
  assign wen = T_5460 & T_5462;
  assign T_5463 = io_rw_cmd == 3'h2;
  assign T_5464 = io_rw_cmd == 3'h3;
  assign T_5465 = T_5463 | T_5464;
  assign T_5467 = T_5465 ? io_rw_rdata : 32'h0;
  assign T_5468 = io_rw_cmd != 3'h3;
  assign T_5470 = T_5468 ? io_rw_wdata : 32'h0;
  assign T_5471 = T_5467 | T_5470;
  assign T_5474 = T_5464 ? io_rw_wdata : 32'h0;
  assign T_5475 = ~ T_5474;
  assign wdata = T_5471 & T_5475;
  assign do_system_insn = priv_sufficient & system_insn;
  assign T_5477 = io_rw_addr[2:0];
  assign opcode = 8'h1 << T_5477;
  assign T_5478 = opcode[0];
  assign insn_call = do_system_insn & T_5478;
  assign T_5479 = opcode[1];
  assign insn_break = do_system_insn & T_5479;
  assign T_5480 = opcode[2];
  assign insn_ret = do_system_insn & T_5480;
  assign T_5481 = opcode[4];
  assign insn_sfence_vm = do_system_insn & T_5481;
  assign T_5482 = opcode[5];
  assign insn_wfi = do_system_insn & T_5482;
  assign T_5483 = cpu_wen & read_only;
  assign T_5485 = priv_sufficient == 1'h0;
  assign T_5487 = addr_valid == 1'h0;
  assign T_5488 = T_5485 | T_5487;
  assign T_5490 = hpm_en == 1'h0;
  assign T_5491 = hpm_csr & T_5490;
  assign T_5492 = T_5488 | T_5491;
  assign T_5501 = cpu_ren & T_5492;
  assign T_5502 = T_5483 | T_5501;
  assign T_5505 = system_insn & T_5485;
  assign T_5506 = T_5502 | T_5505;
  assign T_5507 = T_5506 | insn_call;
  assign T_5508 = T_5507 | insn_break;
  assign GEN_57 = insn_wfi ? 1'h1 : reg_wfi;
  assign T_5511 = pending_interrupts != 32'h0;
  assign GEN_58 = T_5511 ? 1'h0 : GEN_57;
  assign T_5514 = io_csr_xcpt == 1'h0;
  assign GEN_3 = {{2'd0}, reg_mstatus_prv};
  assign T_5516 = GEN_3 + 4'h8;
  assign T_5517 = T_5516[3:0];
  assign T_5520 = insn_break ? 2'h3 : 2'h2;
  assign T_5521 = insn_call ? T_5517 : {{2'd0}, T_5520};
  assign cause = T_5514 ? io_cause : {{28'd0}, T_5521};
  assign cause_lsbs = cause[4:0];
  assign T_5522 = cause[31];
  assign T_5524 = cause_lsbs == 5'hd;
  assign causeIsDebugInt = T_5522 & T_5524;
  assign T_5527 = T_5522 == 1'h0;
  assign causeIsDebugTrigger = T_5527 & T_5524;
  assign T_5533 = T_5527 & insn_break;
  assign T_5534 = {reg_dcsr_ebreaks,reg_dcsr_ebreaku};
  assign T_5535 = {reg_dcsr_ebreakm,reg_dcsr_ebreakh};
  assign T_5536 = {T_5535,T_5534};
  assign T_5537 = T_5536 >> reg_mstatus_prv;
  assign T_5538 = T_5537[0];
  assign causeIsDebugBreak = T_5533 & T_5538;
  assign T_5540 = reg_singleStepped | causeIsDebugInt;
  assign T_5541 = T_5540 | causeIsDebugTrigger;
  assign T_5542 = T_5541 | causeIsDebugBreak;
  assign T_5543 = T_5542 | reg_debug;
  assign debugTVec = reg_debug ? 12'h808 : 12'h800;
  assign tvec = T_5543 ? {{20'd0}, debugTVec} : reg_mtvec;
  assign epc = T_5452 ? reg_dpc : reg_mepc;
  assign T_5563 = exception ? tvec : epc;
  assign T_5566 = reg_dcsr_step & T_4841;
  assign T_5567 = ~ io_status_fs;
  assign T_5569 = T_5567 == 2'h0;
  assign T_5570 = ~ io_status_xs;
  assign T_5572 = T_5570 == 2'h0;
  assign T_5573 = T_5569 | T_5572;
  assign T_5574 = ~ io_pc;
  assign T_5576 = T_5574 | 32'h1;
  assign T_5577 = ~ T_5576;
  assign T_5578 = read_mstatus >> reg_mstatus_prv;
  assign T_5579 = T_5578[0];
  assign T_5587 = cause == 32'h3;
  assign T_5588 = cause == 32'h4;
  assign T_5589 = cause == 32'h6;
  assign T_5590 = cause == 32'h0;
  assign T_5591 = cause == 32'h5;
  assign T_5592 = cause == 32'h7;
  assign T_5593 = cause == 32'h1;
  assign T_5594 = T_5587 | T_5588;
  assign T_5595 = T_5594 | T_5589;
  assign T_5596 = T_5595 | T_5590;
  assign T_5597 = T_5596 | T_5591;
  assign T_5598 = T_5597 | T_5592;
  assign T_5599 = T_5598 | T_5593;
  assign T_5605 = causeIsDebugTrigger ? 2'h2 : 2'h1;
  assign T_5606 = causeIsDebugInt ? 2'h3 : T_5605;
  assign T_5607 = reg_singleStepped ? 3'h4 : {{1'd0}, T_5606};
  assign T_5608 = reg_mstatus_prv[0];
  assign T_5612 = T_5608 ? 2'h3 : 2'h0;
  assign GEN_59 = T_5543 ? 1'h1 : reg_debug;
  assign GEN_60 = T_5543 ? T_5577 : reg_dpc;
  assign GEN_61 = T_5543 ? T_5607 : reg_dcsr_cause;
  assign GEN_62 = T_5543 ? T_5612 : reg_dcsr_prv;
  assign T_5614 = T_5543 == 1'h0;
  assign T_5616 = ~ T_5577;
  assign T_5617 = reg_misa[2];
  assign T_5619 = T_5617 == 1'h0;
  assign T_5621 = {T_5619,1'h1};
  assign GEN_4 = {{30'd0}, T_5621};
  assign T_5622 = T_5616 | GEN_4;
  assign T_5623 = ~ T_5622;
  assign GEN_68 = {{1'd0}, reg_mstatus_spp};
  assign GEN_71 = T_5599 ? io_badaddr : reg_mbadaddr;
  assign GEN_72 = T_5614 ? T_5623 : reg_mepc;
  assign GEN_73 = T_5614 ? cause : reg_mcause;
  assign GEN_74 = T_5614 ? GEN_71 : reg_mbadaddr;
  assign GEN_75 = T_5614 ? T_5579 : reg_mstatus_mpie;
  assign GEN_76 = T_5614 ? T_5612 : reg_mstatus_mpp;
  assign GEN_77 = T_5614 ? 1'h0 : reg_mstatus_mie;
  assign GEN_78 = T_5614 ? 2'h3 : reg_mstatus_prv;
  assign GEN_79 = exception ? GEN_59 : reg_debug;
  assign GEN_80 = exception ? GEN_60 : reg_dpc;
  assign GEN_81 = exception ? GEN_61 : reg_dcsr_cause;
  assign GEN_82 = exception ? GEN_62 : reg_dcsr_prv;
  assign GEN_87 = exception ? GEN_68 : {{1'd0}, reg_mstatus_spp};
  assign GEN_89 = exception ? GEN_78 : reg_mstatus_prv;
  assign GEN_90 = exception ? GEN_72 : reg_mepc;
  assign GEN_91 = exception ? GEN_73 : reg_mcause;
  assign GEN_92 = exception ? GEN_74 : reg_mbadaddr;
  assign GEN_93 = exception ? GEN_75 : reg_mstatus_mpie;
  assign GEN_94 = exception ? GEN_76 : reg_mstatus_mpp;
  assign GEN_95 = exception ? GEN_77 : reg_mstatus_mie;
  assign GEN_101 = T_5452 ? reg_dcsr_prv : GEN_89;
  assign GEN_102 = T_5452 ? 1'h0 : GEN_79;
  assign T_5663 = reg_mstatus_mpp[1];
  assign GEN_103 = T_5663 ? reg_mstatus_mpie : GEN_95;
  assign GEN_105 = T_5454 ? GEN_103 : GEN_95;
  assign GEN_107 = T_5454 ? 1'h0 : GEN_93;
  assign GEN_108 = T_5454 ? 2'h0 : GEN_94;
  assign GEN_109 = T_5454 ? reg_mstatus_mpp : GEN_101;
  assign GEN_113 = insn_ret ? GEN_109 : GEN_89;
  assign GEN_114 = insn_ret ? GEN_102 : GEN_79;
  assign GEN_115 = insn_ret ? GEN_105 : GEN_95;
  assign GEN_116 = insn_ret ? GEN_107 : GEN_93;
  assign GEN_117 = insn_ret ? GEN_108 : GEN_94;
  assign T_5677 = io_exception + io_csr_xcpt;
  assign GEN_6 = {{1'd0}, insn_ret};
  assign T_5678 = GEN_6 + T_5677;
  assign T_5680 = T_5678 <= 3'h1;
  assign T_5681 = T_5680 | reset;
  assign T_5683 = T_5681 == 1'h0;
  assign T_5685 = T_5080 ? reg_tselect : 1'h0;
  assign T_5687 = T_5082 ? T_5035 : 32'h0;
  assign GEN_15_control_ttype = GEN_41;
  assign GEN_15_control_dmode = GEN_42;
  assign GEN_15_control_maskmax = GEN_43;
  assign GEN_15_control_reserved = GEN_44;
  assign GEN_15_control_action = GEN_45;
  assign GEN_15_control_chain = GEN_46;
  assign GEN_15_control_zero = GEN_47;
  assign GEN_15_control_tmatch = GEN_48;
  assign GEN_15_control_m = GEN_49;
  assign GEN_15_control_h = GEN_50;
  assign GEN_15_control_s = GEN_51;
  assign GEN_15_control_u = GEN_52;
  assign GEN_15_control_x = GEN_53;
  assign GEN_15_control_w = GEN_54;
  assign GEN_15_control_r = GEN_55;
  assign GEN_15_address = GEN_56;
  assign T_5689 = T_5084 ? GEN_15_address : 32'h0;
  assign T_5697 = T_5092 ? T_4814 : 64'h0;
  assign T_5699 = T_5094 ? T_4804 : 64'h0;
  assign T_5701 = T_5096 ? reg_misa : 32'h0;
  assign T_5703 = T_5098 ? read_mstatus : 32'h0;
  assign T_5705 = T_5100 ? reg_mtvec : 32'h0;
  assign T_5707 = T_5102 ? read_mip : 13'h0;
  assign T_5709 = T_5104 ? reg_mie : 32'h0;
  assign T_5711 = T_5106 ? reg_mideleg : 32'h0;
  assign T_5713 = T_5108 ? reg_medeleg : 32'h0;
  assign T_5715 = T_5110 ? reg_mscratch : 32'h0;
  assign T_5717 = T_5112 ? reg_mepc : 32'h0;
  assign T_5719 = T_5114 ? reg_mbadaddr : 32'h0;
  assign T_5721 = T_5116 ? reg_mcause : 32'h0;
  assign T_5723 = T_5118 ? io_hartid : 32'h0;
  assign T_5725 = T_5120 ? T_5071 : 32'h0;
  assign T_5727 = T_5122 ? reg_dpc : 32'h0;
  assign T_5729 = T_5124 ? reg_dscratch : 32'h0;
  assign T_5905 = T_5300 ? reg_mucounteren : 32'h0;
  assign T_5907 = T_5302 ? T_4814 : 64'h0;
  assign T_5909 = T_5304 ? T_4804 : 64'h0;
  assign T_5911 = T_5306 ? T_5075 : 32'h0;
  assign T_5913 = T_5308 ? T_5076 : 32'h0;
  assign T_5915 = T_5310 ? T_5075 : 32'h0;
  assign T_5917 = T_5312 ? T_5076 : 32'h0;
  assign GEN_7 = {{31'd0}, T_5685};
  assign T_5919 = GEN_7 | T_5687;
  assign T_5920 = T_5919 | T_5689;
  assign GEN_8 = {{32'd0}, T_5920};
  assign T_5924 = GEN_8 | T_5697;
  assign T_5925 = T_5924 | T_5699;
  assign GEN_9 = {{32'd0}, T_5701};
  assign T_5926 = T_5925 | GEN_9;
  assign GEN_10 = {{32'd0}, T_5703};
  assign T_5927 = T_5926 | GEN_10;
  assign GEN_11 = {{32'd0}, T_5705};
  assign T_5928 = T_5927 | GEN_11;
  assign GEN_12 = {{51'd0}, T_5707};
  assign T_5929 = T_5928 | GEN_12;
  assign GEN_13 = {{32'd0}, T_5709};
  assign T_5930 = T_5929 | GEN_13;
  assign GEN_14 = {{32'd0}, T_5711};
  assign T_5931 = T_5930 | GEN_14;
  assign GEN_15 = {{32'd0}, T_5713};
  assign T_5932 = T_5931 | GEN_15;
  assign GEN_16 = {{32'd0}, T_5715};
  assign T_5933 = T_5932 | GEN_16;
  assign GEN_313 = {{32'd0}, T_5717};
  assign T_5934 = T_5933 | GEN_313;
  assign GEN_314 = {{32'd0}, T_5719};
  assign T_5935 = T_5934 | GEN_314;
  assign GEN_315 = {{32'd0}, T_5721};
  assign T_5936 = T_5935 | GEN_315;
  assign GEN_316 = {{32'd0}, T_5723};
  assign T_5937 = T_5936 | GEN_316;
  assign GEN_317 = {{32'd0}, T_5725};
  assign T_5938 = T_5937 | GEN_317;
  assign GEN_318 = {{32'd0}, T_5727};
  assign T_5939 = T_5938 | GEN_318;
  assign GEN_319 = {{32'd0}, T_5729};
  assign T_5940 = T_5939 | GEN_319;
  assign GEN_320 = {{32'd0}, T_5905};
  assign T_6028 = T_5940 | GEN_320;
  assign T_6029 = T_6028 | T_5907;
  assign T_6030 = T_6029 | T_5909;
  assign GEN_321 = {{32'd0}, T_5911};
  assign T_6031 = T_6030 | GEN_321;
  assign GEN_322 = {{32'd0}, T_5913};
  assign T_6032 = T_6031 | GEN_322;
  assign GEN_323 = {{32'd0}, T_5915};
  assign T_6033 = T_6032 | GEN_323;
  assign GEN_324 = {{32'd0}, T_5917};
  assign T_6034 = T_6033 | GEN_324;
  assign T_6035 = T_6034;
  assign T_6036 = reg_fflags | io_fcsr_flags_bits;
  assign GEN_118 = io_fcsr_flags_valid ? T_6036 : reg_fflags;
  assign T_6089_debug = T_6141;
  assign T_6089_isa = T_6140;
  assign T_6089_prv = T_6139;
  assign T_6089_sd = T_6138;
  assign T_6089_zero3 = T_6137;
  assign T_6089_sd_rv32 = T_6136;
  assign T_6089_zero2 = T_6135;
  assign T_6089_vm = T_6134;
  assign T_6089_zero1 = T_6133;
  assign T_6089_mxr = T_6132;
  assign T_6089_pum = T_6131;
  assign T_6089_mprv = T_6130;
  assign T_6089_xs = T_6129;
  assign T_6089_fs = T_6128;
  assign T_6089_mpp = T_6127;
  assign T_6089_hpp = T_6126;
  assign T_6089_spp = T_6125;
  assign T_6089_mpie = T_6124;
  assign T_6089_hpie = T_6123;
  assign T_6089_spie = T_6122;
  assign T_6089_upie = T_6121;
  assign T_6089_mie = T_6120;
  assign T_6089_hie = T_6119;
  assign T_6089_sie = T_6118;
  assign T_6089_uie = T_6117;
  assign T_6116 = {{67'd0}, wdata};
  assign T_6117 = T_6116[0];
  assign T_6118 = T_6116[1];
  assign T_6119 = T_6116[2];
  assign T_6120 = T_6116[3];
  assign T_6121 = T_6116[4];
  assign T_6122 = T_6116[5];
  assign T_6123 = T_6116[6];
  assign T_6124 = T_6116[7];
  assign T_6125 = T_6116[8];
  assign T_6126 = T_6116[10:9];
  assign T_6127 = T_6116[12:11];
  assign T_6128 = T_6116[14:13];
  assign T_6129 = T_6116[16:15];
  assign T_6130 = T_6116[17];
  assign T_6131 = T_6116[18];
  assign T_6132 = T_6116[19];
  assign T_6133 = T_6116[23:20];
  assign T_6134 = T_6116[28:24];
  assign T_6135 = T_6116[30:29];
  assign T_6136 = T_6116[31];
  assign T_6137 = T_6116[62:32];
  assign T_6138 = T_6116[63];
  assign T_6139 = T_6116[65:64];
  assign T_6140 = T_6116[97:66];
  assign T_6141 = T_6116[98];
  assign T_6142 = T_6089_mpp[0];
  assign T_6146 = T_6142 ? 2'h3 : 2'h0;
  assign GEN_119 = T_5098 ? T_6089_mie : GEN_115;
  assign GEN_120 = T_5098 ? T_6089_mpie : GEN_116;
  assign GEN_121 = T_5098 ? T_6089_mprv : reg_mstatus_mprv;
  assign GEN_122 = T_5098 ? T_6146 : GEN_117;
  assign T_6148 = wdata[5];
  assign T_6149 = ~ wdata;
  assign T_6151 = T_6148 == 1'h0;
  assign GEN_325 = {{3'd0}, T_6151};
  assign T_6152 = GEN_325 << 3;
  assign GEN_326 = {{28'd0}, T_6152};
  assign T_6153 = T_6149 | GEN_326;
  assign T_6154 = ~ T_6153;
  assign T_6155 = T_6154 & 32'h1005;
  assign T_6157 = reg_misa & 32'hffa;
  assign T_6158 = T_6155 | T_6157;
  assign GEN_123 = T_5096 ? T_6158 : reg_misa;
  assign T_6187_rocc = T_6213;
  assign T_6187_meip = T_6212;
  assign T_6187_heip = T_6211;
  assign T_6187_seip = T_6210;
  assign T_6187_ueip = T_6209;
  assign T_6187_mtip = T_6208;
  assign T_6187_htip = T_6207;
  assign T_6187_stip = T_6148;
  assign T_6187_utip = T_6205;
  assign T_6187_msip = T_6204;
  assign T_6187_hsip = T_6203;
  assign T_6187_ssip = T_6202;
  assign T_6187_usip = T_6201;
  assign T_6201 = wdata[0];
  assign T_6202 = wdata[1];
  assign T_6203 = wdata[2];
  assign T_6204 = wdata[3];
  assign T_6205 = wdata[4];
  assign T_6207 = wdata[6];
  assign T_6208 = wdata[7];
  assign T_6209 = wdata[8];
  assign T_6210 = wdata[9];
  assign T_6211 = wdata[10];
  assign T_6212 = wdata[11];
  assign T_6213 = wdata[12];
  assign GEN_327 = {{19'd0}, supported_interrupts};
  assign T_6214 = wdata & GEN_327;
  assign GEN_124 = T_5104 ? T_6214 : reg_mie;
  assign T_6221 = T_6149 | GEN_4;
  assign T_6222 = ~ T_6221;
  assign GEN_125 = T_5112 ? T_6222 : GEN_90;
  assign GEN_126 = T_5110 ? wdata : reg_mscratch;
  assign T_6223 = wdata[31:2];
  assign GEN_329 = {{2'd0}, T_6223};
  assign T_6224 = GEN_329 << 2;
  assign GEN_127 = T_5100 ? T_6224 : reg_mtvec;
  assign T_6226 = wdata & 32'h8000001f;
  assign GEN_128 = T_5116 ? T_6226 : GEN_91;
  assign GEN_129 = T_5114 ? wdata : GEN_92;
  assign T_6228 = T_4814[63:32];
  assign T_6229 = {T_6228,wdata};
  assign T_6230 = T_6229[63:6];
  assign GEN_130 = T_5092 ? T_6229 : {{57'd0}, T_4808};
  assign GEN_131 = T_5092 ? {{1'd0}, T_6230} : GEN_38;
  assign T_6231 = T_4814[31:0];
  assign T_6232 = {wdata,T_6231};
  assign T_6233 = T_6232[63:6];
  assign GEN_132 = T_5306 ? T_6232 : GEN_130;
  assign GEN_133 = T_5306 ? {{1'd0}, T_6233} : GEN_131;
  assign T_6234 = T_4804[63:32];
  assign T_6235 = {T_6234,wdata};
  assign T_6236 = T_6235[63:6];
  assign GEN_134 = T_5094 ? T_6235 : {{57'd0}, T_4798};
  assign GEN_135 = T_5094 ? {{1'd0}, T_6236} : GEN_37;
  assign T_6237 = T_4804[31:0];
  assign T_6238 = {wdata,T_6237};
  assign T_6239 = T_6238[63:6];
  assign GEN_136 = T_5308 ? T_6238 : GEN_134;
  assign GEN_137 = T_5308 ? {{1'd0}, T_6239} : GEN_135;
  assign T_6276_xdebugver = T_6310;
  assign T_6276_ndreset = T_6309;
  assign T_6276_fullreset = T_6308;
  assign T_6276_zero3 = T_6307;
  assign T_6276_ebreakm = T_6306;
  assign T_6276_ebreakh = T_6305;
  assign T_6276_ebreaks = T_6304;
  assign T_6276_ebreaku = T_6213;
  assign T_6276_zero2 = T_6212;
  assign T_6276_stopcycle = T_6211;
  assign T_6276_stoptime = T_6210;
  assign T_6276_cause = T_6299;
  assign T_6276_debugint = T_6148;
  assign T_6276_zero1 = T_6205;
  assign T_6276_halt = T_6204;
  assign T_6276_step = T_6203;
  assign T_6276_prv = T_6294;
  assign T_6294 = wdata[1:0];
  assign T_6299 = wdata[8:6];
  assign T_6304 = wdata[13];
  assign T_6305 = wdata[14];
  assign T_6306 = wdata[15];
  assign T_6307 = wdata[27:16];
  assign T_6308 = wdata[28];
  assign T_6309 = wdata[29];
  assign T_6310 = wdata[31:30];
  assign T_6311 = T_6276_prv[0];
  assign T_6315 = T_6311 ? 2'h3 : 2'h0;
  assign GEN_138 = T_5120 ? T_6276_halt : reg_dcsr_halt;
  assign GEN_139 = T_5120 ? T_6276_step : reg_dcsr_step;
  assign GEN_140 = T_5120 ? T_6276_ebreakm : reg_dcsr_ebreakm;
  assign GEN_141 = T_5120 ? T_6276_ebreaku : reg_dcsr_ebreaku;
  assign GEN_142 = T_5120 ? T_6315 : GEN_82;
  assign T_6318 = T_6149 | 32'h1;
  assign T_6319 = ~ T_6318;
  assign GEN_143 = T_5122 ? T_6319 : GEN_80;
  assign GEN_144 = T_5124 ? wdata : reg_dscratch;
  assign T_6321 = wdata & 32'h7;
  assign GEN_145 = T_5300 ? T_6321 : reg_mucounteren;
  assign GEN_16_control_ttype = GEN_41;
  assign GEN_16_control_dmode = GEN_42;
  assign GEN_16_control_maskmax = GEN_43;
  assign GEN_16_control_reserved = GEN_44;
  assign GEN_16_control_action = GEN_45;
  assign GEN_16_control_chain = GEN_46;
  assign GEN_16_control_zero = GEN_47;
  assign GEN_16_control_tmatch = GEN_48;
  assign GEN_16_control_m = GEN_49;
  assign GEN_16_control_h = GEN_50;
  assign GEN_16_control_s = GEN_51;
  assign GEN_16_control_u = GEN_52;
  assign GEN_16_control_x = GEN_53;
  assign GEN_16_control_w = GEN_54;
  assign GEN_16_control_r = GEN_55;
  assign GEN_16_address = GEN_56;
  assign T_6340 = GEN_16_control_dmode == 1'h0;
  assign T_6341 = T_6340 | reg_debug;
  assign T_6374_ttype = T_6404;
  assign T_6374_dmode = T_6403;
  assign T_6374_maskmax = T_6402;
  assign T_6374_reserved = T_6401;
  assign T_6374_action = T_6213;
  assign T_6374_chain = T_6212;
  assign T_6374_zero = T_6398;
  assign T_6374_tmatch = T_6397;
  assign T_6374_m = T_6207;
  assign T_6374_h = T_6148;
  assign T_6374_s = T_6205;
  assign T_6374_u = T_6204;
  assign T_6374_x = T_6203;
  assign T_6374_w = T_6202;
  assign T_6374_r = T_6201;
  assign T_6397 = wdata[8:7];
  assign T_6398 = wdata[10:9];
  assign T_6401 = wdata[20:13];
  assign T_6402 = wdata[26:21];
  assign T_6403 = wdata[27];
  assign T_6404 = wdata[31:28];
  assign T_6405 = T_6374_dmode & reg_debug;
  assign GEN_17 = T_6374_ttype;
  assign GEN_18 = T_6374_dmode;
  assign GEN_149 = 1'h0 == reg_tselect ? GEN_18 : reg_bp_0_control_dmode;
  assign GEN_19 = T_6374_maskmax;
  assign GEN_20 = T_6374_reserved;
  assign GEN_21 = T_6374_action;
  assign GEN_155 = 1'h0 == reg_tselect ? GEN_21 : reg_bp_0_control_action;
  assign GEN_22 = T_6374_chain;
  assign GEN_23 = T_6374_zero;
  assign GEN_24 = T_6374_tmatch;
  assign GEN_161 = 1'h0 == reg_tselect ? GEN_24 : reg_bp_0_control_tmatch;
  assign GEN_25 = T_6374_m;
  assign GEN_163 = 1'h0 == reg_tselect ? GEN_25 : reg_bp_0_control_m;
  assign GEN_26 = T_6374_h;
  assign GEN_27 = T_6374_s;
  assign GEN_28 = T_6374_u;
  assign GEN_169 = 1'h0 == reg_tselect ? GEN_28 : reg_bp_0_control_u;
  assign GEN_29 = T_6374_x;
  assign GEN_171 = 1'h0 == reg_tselect ? GEN_29 : reg_bp_0_control_x;
  assign GEN_30 = T_6374_w;
  assign GEN_173 = 1'h0 == reg_tselect ? GEN_30 : reg_bp_0_control_w;
  assign GEN_31 = T_6374_r;
  assign GEN_175 = 1'h0 == reg_tselect ? GEN_31 : reg_bp_0_control_r;
  assign GEN_32 = T_6405;
  assign GEN_177 = 1'h0 == reg_tselect ? GEN_32 : GEN_149;
  assign T_6406 = T_6405 & T_6374_action;
  assign GEN_33 = T_6406;
  assign GEN_179 = 1'h0 == reg_tselect ? GEN_33 : GEN_155;
  assign GEN_183 = T_5082 ? GEN_177 : reg_bp_0_control_dmode;
  assign GEN_189 = T_5082 ? GEN_179 : reg_bp_0_control_action;
  assign GEN_195 = T_5082 ? GEN_161 : reg_bp_0_control_tmatch;
  assign GEN_197 = T_5082 ? GEN_163 : reg_bp_0_control_m;
  assign GEN_203 = T_5082 ? GEN_169 : reg_bp_0_control_u;
  assign GEN_205 = T_5082 ? GEN_171 : reg_bp_0_control_x;
  assign GEN_207 = T_5082 ? GEN_173 : reg_bp_0_control_w;
  assign GEN_209 = T_5082 ? GEN_175 : reg_bp_0_control_r;
  assign GEN_34 = wdata;
  assign GEN_211 = 1'h0 == reg_tselect ? GEN_34 : reg_bp_0_address;
  assign GEN_213 = T_5084 ? GEN_211 : reg_bp_0_address;
  assign GEN_217 = T_6341 ? GEN_183 : reg_bp_0_control_dmode;
  assign GEN_223 = T_6341 ? GEN_189 : reg_bp_0_control_action;
  assign GEN_229 = T_6341 ? GEN_195 : reg_bp_0_control_tmatch;
  assign GEN_231 = T_6341 ? GEN_197 : reg_bp_0_control_m;
  assign GEN_237 = T_6341 ? GEN_203 : reg_bp_0_control_u;
  assign GEN_239 = T_6341 ? GEN_205 : reg_bp_0_control_x;
  assign GEN_241 = T_6341 ? GEN_207 : reg_bp_0_control_w;
  assign GEN_243 = T_6341 ? GEN_209 : reg_bp_0_control_r;
  assign GEN_245 = T_6341 ? GEN_213 : reg_bp_0_address;
  assign GEN_247 = wen ? GEN_119 : GEN_115;
  assign GEN_248 = wen ? GEN_120 : GEN_116;
  assign GEN_249 = wen ? GEN_121 : reg_mstatus_mprv;
  assign GEN_250 = wen ? GEN_122 : GEN_117;
  assign GEN_251 = wen ? GEN_123 : reg_misa;
  assign GEN_252 = wen ? GEN_124 : reg_mie;
  assign GEN_253 = wen ? GEN_125 : GEN_90;
  assign GEN_254 = wen ? GEN_126 : reg_mscratch;
  assign GEN_255 = wen ? GEN_127 : reg_mtvec;
  assign GEN_256 = wen ? GEN_128 : GEN_91;
  assign GEN_257 = wen ? GEN_129 : GEN_92;
  assign GEN_258 = wen ? GEN_132 : {{57'd0}, T_4808};
  assign GEN_259 = wen ? GEN_133 : GEN_38;
  assign GEN_260 = wen ? GEN_136 : {{57'd0}, T_4798};
  assign GEN_261 = wen ? GEN_137 : GEN_37;
  assign GEN_262 = wen ? GEN_138 : reg_dcsr_halt;
  assign GEN_263 = wen ? GEN_139 : reg_dcsr_step;
  assign GEN_264 = wen ? GEN_140 : reg_dcsr_ebreakm;
  assign GEN_265 = wen ? GEN_141 : reg_dcsr_ebreaku;
  assign GEN_266 = wen ? GEN_142 : GEN_82;
  assign GEN_267 = wen ? GEN_143 : GEN_80;
  assign GEN_268 = wen ? GEN_144 : reg_dscratch;
  assign GEN_269 = wen ? GEN_145 : reg_mucounteren;
  assign GEN_273 = wen ? GEN_217 : reg_bp_0_control_dmode;
  assign GEN_279 = wen ? GEN_223 : reg_bp_0_control_action;
  assign GEN_285 = wen ? GEN_229 : reg_bp_0_control_tmatch;
  assign GEN_287 = wen ? GEN_231 : reg_bp_0_control_m;
  assign GEN_293 = wen ? GEN_237 : reg_bp_0_control_u;
  assign GEN_295 = wen ? GEN_239 : reg_bp_0_control_x;
  assign GEN_297 = wen ? GEN_241 : reg_bp_0_control_w;
  assign GEN_299 = wen ? GEN_243 : reg_bp_0_control_r;
  assign GEN_301 = wen ? GEN_245 : reg_bp_0_address;
  assign GEN_303 = reset ? 1'h0 : GEN_279;
  assign GEN_304 = reset ? 1'h0 : GEN_273;
  assign GEN_305 = reset ? 1'h0 : GEN_299;
  assign GEN_306 = reset ? 1'h0 : GEN_297;
  assign GEN_307 = reset ? 1'h0 : GEN_295;
  assign T_6472_control_ttype = T_6507;
  assign T_6472_control_dmode = T_6506;
  assign T_6472_control_maskmax = T_6505;
  assign T_6472_control_reserved = T_6504;
  assign T_6472_control_action = T_6503;
  assign T_6472_control_chain = T_6502;
  assign T_6472_control_zero = T_6501;
  assign T_6472_control_tmatch = T_6500;
  assign T_6472_control_m = T_6499;
  assign T_6472_control_h = T_6498;
  assign T_6472_control_s = T_6497;
  assign T_6472_control_u = T_6496;
  assign T_6472_control_x = T_6495;
  assign T_6472_control_w = T_6494;
  assign T_6472_control_r = T_6493;
  assign T_6472_address = T_6492;
  assign T_6491 = 64'h0;
  assign T_6492 = T_6491[31:0];
  assign T_6493 = T_6491[32];
  assign T_6494 = T_6491[33];
  assign T_6495 = T_6491[34];
  assign T_6496 = T_6491[35];
  assign T_6497 = T_6491[36];
  assign T_6498 = T_6491[37];
  assign T_6499 = T_6491[38];
  assign T_6500 = T_6491[40:39];
  assign T_6501 = T_6491[42:41];
  assign T_6502 = T_6491[43];
  assign T_6503 = T_6491[44];
  assign T_6504 = T_6491[52:45];
  assign T_6505 = T_6491[58:53];
  assign T_6506 = T_6491[59];
  assign T_6507 = T_6491[63:60];
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_208 = {1{$random}};
  reg_mstatus_debug = GEN_208[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_210 = {1{$random}};
  reg_mstatus_isa = GEN_210[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_212 = {1{$random}};
  reg_mstatus_prv = GEN_212[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_214 = {1{$random}};
  reg_mstatus_sd = GEN_214[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_215 = {1{$random}};
  reg_mstatus_zero3 = GEN_215[30:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_216 = {1{$random}};
  reg_mstatus_sd_rv32 = GEN_216[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_218 = {1{$random}};
  reg_mstatus_zero2 = GEN_218[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_219 = {1{$random}};
  reg_mstatus_vm = GEN_219[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_220 = {1{$random}};
  reg_mstatus_zero1 = GEN_220[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_221 = {1{$random}};
  reg_mstatus_mxr = GEN_221[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_222 = {1{$random}};
  reg_mstatus_pum = GEN_222[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_224 = {1{$random}};
  reg_mstatus_mprv = GEN_224[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_225 = {1{$random}};
  reg_mstatus_xs = GEN_225[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_226 = {1{$random}};
  reg_mstatus_fs = GEN_226[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_227 = {1{$random}};
  reg_mstatus_mpp = GEN_227[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_228 = {1{$random}};
  reg_mstatus_hpp = GEN_228[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_230 = {1{$random}};
  reg_mstatus_spp = GEN_230[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_232 = {1{$random}};
  reg_mstatus_mpie = GEN_232[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_233 = {1{$random}};
  reg_mstatus_hpie = GEN_233[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_234 = {1{$random}};
  reg_mstatus_spie = GEN_234[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_235 = {1{$random}};
  reg_mstatus_upie = GEN_235[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_236 = {1{$random}};
  reg_mstatus_mie = GEN_236[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_238 = {1{$random}};
  reg_mstatus_hie = GEN_238[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_240 = {1{$random}};
  reg_mstatus_sie = GEN_240[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_242 = {1{$random}};
  reg_mstatus_uie = GEN_242[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_244 = {1{$random}};
  reg_dcsr_xdebugver = GEN_244[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_246 = {1{$random}};
  reg_dcsr_ndreset = GEN_246[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_270 = {1{$random}};
  reg_dcsr_fullreset = GEN_270[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_271 = {1{$random}};
  reg_dcsr_zero3 = GEN_271[11:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_272 = {1{$random}};
  reg_dcsr_ebreakm = GEN_272[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_274 = {1{$random}};
  reg_dcsr_ebreakh = GEN_274[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_275 = {1{$random}};
  reg_dcsr_ebreaks = GEN_275[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_276 = {1{$random}};
  reg_dcsr_ebreaku = GEN_276[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_277 = {1{$random}};
  reg_dcsr_zero2 = GEN_277[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_278 = {1{$random}};
  reg_dcsr_stopcycle = GEN_278[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_280 = {1{$random}};
  reg_dcsr_stoptime = GEN_280[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_281 = {1{$random}};
  reg_dcsr_cause = GEN_281[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_282 = {1{$random}};
  reg_dcsr_debugint = GEN_282[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_283 = {1{$random}};
  reg_dcsr_zero1 = GEN_283[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_284 = {1{$random}};
  reg_dcsr_halt = GEN_284[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_286 = {1{$random}};
  reg_dcsr_step = GEN_286[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_288 = {1{$random}};
  reg_dcsr_prv = GEN_288[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_289 = {1{$random}};
  reg_debug = GEN_289[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_290 = {1{$random}};
  reg_dpc = GEN_290[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_291 = {1{$random}};
  reg_dscratch = GEN_291[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_292 = {1{$random}};
  reg_singleStepped = GEN_292[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_294 = {1{$random}};
  reg_tselect = GEN_294[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_296 = {1{$random}};
  reg_bp_0_control_ttype = GEN_296[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_298 = {1{$random}};
  reg_bp_0_control_dmode = GEN_298[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_300 = {1{$random}};
  reg_bp_0_control_maskmax = GEN_300[5:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_302 = {1{$random}};
  reg_bp_0_control_reserved = GEN_302[7:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_308 = {1{$random}};
  reg_bp_0_control_action = GEN_308[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_309 = {1{$random}};
  reg_bp_0_control_chain = GEN_309[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_310 = {1{$random}};
  reg_bp_0_control_zero = GEN_310[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_311 = {1{$random}};
  reg_bp_0_control_tmatch = GEN_311[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_312 = {1{$random}};
  reg_bp_0_control_m = GEN_312[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_328 = {1{$random}};
  reg_bp_0_control_h = GEN_328[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_330 = {1{$random}};
  reg_bp_0_control_s = GEN_330[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_331 = {1{$random}};
  reg_bp_0_control_u = GEN_331[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_332 = {1{$random}};
  reg_bp_0_control_x = GEN_332[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_333 = {1{$random}};
  reg_bp_0_control_w = GEN_333[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_334 = {1{$random}};
  reg_bp_0_control_r = GEN_334[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_335 = {1{$random}};
  reg_bp_0_address = GEN_335[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_336 = {1{$random}};
  reg_bp_1_control_ttype = GEN_336[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_337 = {1{$random}};
  reg_bp_1_control_dmode = GEN_337[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_338 = {1{$random}};
  reg_bp_1_control_maskmax = GEN_338[5:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_339 = {1{$random}};
  reg_bp_1_control_reserved = GEN_339[7:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_340 = {1{$random}};
  reg_bp_1_control_action = GEN_340[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_341 = {1{$random}};
  reg_bp_1_control_chain = GEN_341[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_342 = {1{$random}};
  reg_bp_1_control_zero = GEN_342[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_343 = {1{$random}};
  reg_bp_1_control_tmatch = GEN_343[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_344 = {1{$random}};
  reg_bp_1_control_m = GEN_344[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_345 = {1{$random}};
  reg_bp_1_control_h = GEN_345[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_346 = {1{$random}};
  reg_bp_1_control_s = GEN_346[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_347 = {1{$random}};
  reg_bp_1_control_u = GEN_347[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_348 = {1{$random}};
  reg_bp_1_control_x = GEN_348[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_349 = {1{$random}};
  reg_bp_1_control_w = GEN_349[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_350 = {1{$random}};
  reg_bp_1_control_r = GEN_350[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_351 = {1{$random}};
  reg_bp_1_address = GEN_351[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_352 = {1{$random}};
  reg_mie = GEN_352[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_353 = {1{$random}};
  reg_mideleg = GEN_353[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_354 = {1{$random}};
  reg_medeleg = GEN_354[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_355 = {1{$random}};
  reg_mip_rocc = GEN_355[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_356 = {1{$random}};
  reg_mip_meip = GEN_356[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_357 = {1{$random}};
  reg_mip_heip = GEN_357[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_358 = {1{$random}};
  reg_mip_seip = GEN_358[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_359 = {1{$random}};
  reg_mip_ueip = GEN_359[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_360 = {1{$random}};
  reg_mip_mtip = GEN_360[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_361 = {1{$random}};
  reg_mip_htip = GEN_361[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_362 = {1{$random}};
  reg_mip_stip = GEN_362[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_363 = {1{$random}};
  reg_mip_utip = GEN_363[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_364 = {1{$random}};
  reg_mip_msip = GEN_364[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_365 = {1{$random}};
  reg_mip_hsip = GEN_365[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_366 = {1{$random}};
  reg_mip_ssip = GEN_366[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_367 = {1{$random}};
  reg_mip_usip = GEN_367[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_368 = {1{$random}};
  reg_mepc = GEN_368[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_369 = {1{$random}};
  reg_mcause = GEN_369[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_370 = {1{$random}};
  reg_mbadaddr = GEN_370[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_371 = {1{$random}};
  reg_mscratch = GEN_371[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_372 = {1{$random}};
  reg_mtvec = GEN_372[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_373 = {1{$random}};
  reg_mucounteren = GEN_373[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_374 = {1{$random}};
  reg_mscounteren = GEN_374[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_375 = {1{$random}};
  reg_sepc = GEN_375[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_376 = {1{$random}};
  reg_scause = GEN_376[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_377 = {1{$random}};
  reg_sbadaddr = GEN_377[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_378 = {1{$random}};
  reg_sscratch = GEN_378[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_379 = {1{$random}};
  reg_stvec = GEN_379[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_380 = {1{$random}};
  reg_sptbr_asid = GEN_380[6:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_381 = {1{$random}};
  reg_sptbr_ppn = GEN_381[21:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_382 = {1{$random}};
  reg_wfi = GEN_382[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_383 = {1{$random}};
  reg_fflags = GEN_383[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_384 = {1{$random}};
  reg_frm = GEN_384[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_385 = {1{$random}};
  T_4797 = GEN_385[5:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_386 = {2{$random}};
  T_4800 = GEN_386[57:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_387 = {1{$random}};
  T_4807 = GEN_387[5:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_388 = {2{$random}};
  T_4810 = GEN_388[57:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_389 = {1{$random}};
  reg_misa = GEN_389[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_390 = {1{$random}};
  GEN_5 = GEN_390[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_391 = {1{$random}};
  GEN_63 = GEN_391[6:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_392 = {1{$random}};
  GEN_64 = GEN_392[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_393 = {1{$random}};
  GEN_65 = GEN_393[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_394 = {1{$random}};
  GEN_66 = GEN_394[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_395 = {1{$random}};
  GEN_67 = GEN_395[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_396 = {1{$random}};
  GEN_69 = GEN_396[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_397 = {1{$random}};
  GEN_70 = GEN_397[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_398 = {1{$random}};
  GEN_83 = GEN_398[6:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_399 = {1{$random}};
  GEN_84 = GEN_399[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_400 = {1{$random}};
  GEN_85 = GEN_400[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_401 = {1{$random}};
  GEN_86 = GEN_401[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_402 = {1{$random}};
  GEN_88 = GEN_402[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_403 = {1{$random}};
  GEN_96 = GEN_403[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_404 = {1{$random}};
  GEN_97 = GEN_404[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_405 = {1{$random}};
  GEN_98 = GEN_405[30:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_406 = {1{$random}};
  GEN_99 = GEN_406[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_407 = {1{$random}};
  GEN_100 = GEN_407[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_408 = {1{$random}};
  GEN_104 = GEN_408[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_409 = {1{$random}};
  GEN_106 = GEN_409[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_410 = {1{$random}};
  GEN_110 = GEN_410[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_411 = {1{$random}};
  GEN_111 = GEN_411[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_412 = {1{$random}};
  GEN_112 = GEN_412[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_413 = {1{$random}};
  GEN_146 = GEN_413[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_414 = {1{$random}};
  GEN_147 = GEN_414[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_415 = {1{$random}};
  GEN_148 = GEN_415[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_416 = {1{$random}};
  GEN_150 = GEN_416[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_417 = {1{$random}};
  GEN_151 = GEN_417[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_418 = {1{$random}};
  GEN_152 = GEN_418[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_419 = {1{$random}};
  GEN_153 = GEN_419[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_420 = {1{$random}};
  GEN_154 = GEN_420[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_421 = {1{$random}};
  GEN_156 = GEN_421[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_422 = {1{$random}};
  GEN_157 = GEN_422[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_423 = {1{$random}};
  GEN_158 = GEN_423[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_424 = {1{$random}};
  GEN_159 = GEN_424[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_425 = {1{$random}};
  GEN_160 = GEN_425[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_426 = {1{$random}};
  GEN_162 = GEN_426[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_427 = {1{$random}};
  GEN_164 = GEN_427[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_428 = {1{$random}};
  GEN_165 = GEN_428[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_429 = {1{$random}};
  GEN_166 = GEN_429[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_430 = {1{$random}};
  GEN_167 = GEN_430[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_431 = {1{$random}};
  GEN_168 = GEN_431[6:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_432 = {1{$random}};
  GEN_170 = GEN_432[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_433 = {1{$random}};
  GEN_172 = GEN_433[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_434 = {1{$random}};
  GEN_174 = GEN_434[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_435 = {1{$random}};
  GEN_176 = GEN_435[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_436 = {1{$random}};
  GEN_178 = GEN_436[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_437 = {1{$random}};
  GEN_180 = GEN_437[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_438 = {1{$random}};
  GEN_181 = GEN_438[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_439 = {1{$random}};
  GEN_182 = GEN_439[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_440 = {1{$random}};
  GEN_184 = GEN_440[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_441 = {1{$random}};
  GEN_185 = GEN_441[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_442 = {1{$random}};
  GEN_186 = GEN_442[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_443 = {1{$random}};
  GEN_187 = GEN_443[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_444 = {1{$random}};
  GEN_188 = GEN_444[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_445 = {1{$random}};
  GEN_190 = GEN_445[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_446 = {1{$random}};
  GEN_191 = GEN_446[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_447 = {1{$random}};
  GEN_192 = GEN_447[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_448 = {1{$random}};
  GEN_193 = GEN_448[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_449 = {1{$random}};
  GEN_194 = GEN_449[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_450 = {1{$random}};
  GEN_196 = GEN_450[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_451 = {1{$random}};
  GEN_198 = GEN_451[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_452 = {1{$random}};
  GEN_199 = GEN_452[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_453 = {1{$random}};
  GEN_200 = GEN_453[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_454 = {1{$random}};
  GEN_201 = GEN_454[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_455 = {2{$random}};
  GEN_202 = GEN_455[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_456 = {1{$random}};
  GEN_204 = GEN_456[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_457 = {1{$random}};
  GEN_206 = GEN_457[0:0];
  `endif
  end
`endif
  always @(posedge clock) begin
    if (reset) begin
      reg_mstatus_debug <= reset_mstatus_debug;
    end
    if (reset) begin
      reg_mstatus_isa <= reset_mstatus_isa;
    end
    if (reset) begin
      reg_mstatus_prv <= reset_mstatus_prv;
    end else begin
      if (T_4363) begin
        reg_mstatus_prv <= 2'h3;
      end else begin
        reg_mstatus_prv <= 2'h0;
      end
    end
    if (reset) begin
      reg_mstatus_sd <= reset_mstatus_sd;
    end
    if (reset) begin
      reg_mstatus_zero3 <= reset_mstatus_zero3;
    end
    if (reset) begin
      reg_mstatus_sd_rv32 <= reset_mstatus_sd_rv32;
    end
    if (reset) begin
      reg_mstatus_zero2 <= reset_mstatus_zero2;
    end
    if (reset) begin
      reg_mstatus_vm <= reset_mstatus_vm;
    end
    if (reset) begin
      reg_mstatus_zero1 <= reset_mstatus_zero1;
    end
    if (reset) begin
      reg_mstatus_mxr <= reset_mstatus_mxr;
    end
    if (reset) begin
      reg_mstatus_pum <= reset_mstatus_pum;
    end
    if (reset) begin
      reg_mstatus_mprv <= reset_mstatus_mprv;
    end else begin
      if (wen) begin
        if (T_5098) begin
          reg_mstatus_mprv <= T_6089_mprv;
        end
      end
    end
    if (reset) begin
      reg_mstatus_xs <= reset_mstatus_xs;
    end
    if (reset) begin
      reg_mstatus_fs <= reset_mstatus_fs;
    end
    if (reset) begin
      reg_mstatus_mpp <= reset_mstatus_mpp;
    end else begin
      if (wen) begin
        if (T_5098) begin
          if (T_6142) begin
            reg_mstatus_mpp <= 2'h3;
          end else begin
            reg_mstatus_mpp <= 2'h0;
          end
        end else begin
          if (insn_ret) begin
            if (T_5454) begin
              reg_mstatus_mpp <= 2'h0;
            end else begin
              if (exception) begin
                if (T_5614) begin
                  if (T_5608) begin
                    reg_mstatus_mpp <= 2'h3;
                  end else begin
                    reg_mstatus_mpp <= 2'h0;
                  end
                end
              end
            end
          end else begin
            if (exception) begin
              if (T_5614) begin
                if (T_5608) begin
                  reg_mstatus_mpp <= 2'h3;
                end else begin
                  reg_mstatus_mpp <= 2'h0;
                end
              end
            end
          end
        end
      end else begin
        if (insn_ret) begin
          if (T_5454) begin
            reg_mstatus_mpp <= 2'h0;
          end else begin
            if (exception) begin
              if (T_5614) begin
                if (T_5608) begin
                  reg_mstatus_mpp <= 2'h3;
                end else begin
                  reg_mstatus_mpp <= 2'h0;
                end
              end
            end
          end
        end else begin
          if (exception) begin
            if (T_5614) begin
              if (T_5608) begin
                reg_mstatus_mpp <= 2'h3;
              end else begin
                reg_mstatus_mpp <= 2'h0;
              end
            end
          end
        end
      end
    end
    if (reset) begin
      reg_mstatus_hpp <= reset_mstatus_hpp;
    end
    if (reset) begin
      reg_mstatus_spp <= reset_mstatus_spp;
    end else begin
      reg_mstatus_spp <= GEN_87[0];
    end
    if (reset) begin
      reg_mstatus_mpie <= reset_mstatus_mpie;
    end else begin
      if (wen) begin
        if (T_5098) begin
          reg_mstatus_mpie <= T_6089_mpie;
        end else begin
          if (insn_ret) begin
            if (T_5454) begin
              reg_mstatus_mpie <= 1'h0;
            end else begin
              if (exception) begin
                if (T_5614) begin
                  reg_mstatus_mpie <= T_5579;
                end
              end
            end
          end else begin
            if (exception) begin
              if (T_5614) begin
                reg_mstatus_mpie <= T_5579;
              end
            end
          end
        end
      end else begin
        if (insn_ret) begin
          if (T_5454) begin
            reg_mstatus_mpie <= 1'h0;
          end else begin
            if (exception) begin
              if (T_5614) begin
                reg_mstatus_mpie <= T_5579;
              end
            end
          end
        end else begin
          if (exception) begin
            if (T_5614) begin
              reg_mstatus_mpie <= T_5579;
            end
          end
        end
      end
    end
    if (reset) begin
      reg_mstatus_hpie <= reset_mstatus_hpie;
    end
    if (reset) begin
      reg_mstatus_spie <= reset_mstatus_spie;
    end
    if (reset) begin
      reg_mstatus_upie <= reset_mstatus_upie;
    end
    if (reset) begin
      reg_mstatus_mie <= reset_mstatus_mie;
    end else begin
      if (wen) begin
        if (T_5098) begin
          reg_mstatus_mie <= T_6089_mie;
        end else begin
          if (insn_ret) begin
            if (T_5454) begin
              if (T_5663) begin
                reg_mstatus_mie <= reg_mstatus_mpie;
              end else begin
                if (exception) begin
                  if (T_5614) begin
                    reg_mstatus_mie <= 1'h0;
                  end
                end
              end
            end else begin
              if (exception) begin
                if (T_5614) begin
                  reg_mstatus_mie <= 1'h0;
                end
              end
            end
          end else begin
            if (exception) begin
              if (T_5614) begin
                reg_mstatus_mie <= 1'h0;
              end
            end
          end
        end
      end else begin
        if (insn_ret) begin
          if (T_5454) begin
            if (T_5663) begin
              reg_mstatus_mie <= reg_mstatus_mpie;
            end else begin
              if (exception) begin
                if (T_5614) begin
                  reg_mstatus_mie <= 1'h0;
                end
              end
            end
          end else begin
            reg_mstatus_mie <= GEN_95;
          end
        end else begin
          reg_mstatus_mie <= GEN_95;
        end
      end
    end
    if (reset) begin
      reg_mstatus_hie <= reset_mstatus_hie;
    end
    if (reset) begin
      reg_mstatus_sie <= reset_mstatus_sie;
    end
    if (reset) begin
      reg_mstatus_uie <= reset_mstatus_uie;
    end
    if (reset) begin
      reg_dcsr_xdebugver <= reset_dcsr_xdebugver;
    end
    if (reset) begin
      reg_dcsr_ndreset <= reset_dcsr_ndreset;
    end
    if (reset) begin
      reg_dcsr_fullreset <= reset_dcsr_fullreset;
    end
    if (reset) begin
      reg_dcsr_zero3 <= reset_dcsr_zero3;
    end
    if (reset) begin
      reg_dcsr_ebreakm <= reset_dcsr_ebreakm;
    end else begin
      if (wen) begin
        if (T_5120) begin
          reg_dcsr_ebreakm <= T_6276_ebreakm;
        end
      end
    end
    if (reset) begin
      reg_dcsr_ebreakh <= reset_dcsr_ebreakh;
    end
    if (reset) begin
      reg_dcsr_ebreaks <= reset_dcsr_ebreaks;
    end
    if (reset) begin
      reg_dcsr_ebreaku <= reset_dcsr_ebreaku;
    end else begin
      if (wen) begin
        if (T_5120) begin
          reg_dcsr_ebreaku <= T_6276_ebreaku;
        end
      end
    end
    if (reset) begin
      reg_dcsr_zero2 <= reset_dcsr_zero2;
    end
    if (reset) begin
      reg_dcsr_stopcycle <= reset_dcsr_stopcycle;
    end
    if (reset) begin
      reg_dcsr_stoptime <= reset_dcsr_stoptime;
    end
    if (reset) begin
      reg_dcsr_cause <= reset_dcsr_cause;
    end else begin
      if (exception) begin
        if (T_5543) begin
          if (reg_singleStepped) begin
            reg_dcsr_cause <= 3'h4;
          end else begin
            reg_dcsr_cause <= {{1'd0}, T_5606};
          end
        end
      end
    end
    if (reset) begin
      reg_dcsr_debugint <= reset_dcsr_debugint;
    end else begin
      reg_dcsr_debugint <= io_interrupts_debug;
    end
    if (reset) begin
      reg_dcsr_zero1 <= reset_dcsr_zero1;
    end
    if (reset) begin
      reg_dcsr_halt <= reset_dcsr_halt;
    end else begin
      if (wen) begin
        if (T_5120) begin
          reg_dcsr_halt <= T_6276_halt;
        end
      end
    end
    if (reset) begin
      reg_dcsr_step <= reset_dcsr_step;
    end else begin
      if (wen) begin
        if (T_5120) begin
          reg_dcsr_step <= T_6276_step;
        end
      end
    end
    if (reset) begin
      reg_dcsr_prv <= reset_dcsr_prv;
    end else begin
      if (wen) begin
        if (T_5120) begin
          if (T_6311) begin
            reg_dcsr_prv <= 2'h3;
          end else begin
            reg_dcsr_prv <= 2'h0;
          end
        end else begin
          if (exception) begin
            if (T_5543) begin
              if (T_5608) begin
                reg_dcsr_prv <= 2'h3;
              end else begin
                reg_dcsr_prv <= 2'h0;
              end
            end
          end
        end
      end else begin
        if (exception) begin
          if (T_5543) begin
            if (T_5608) begin
              reg_dcsr_prv <= 2'h3;
            end else begin
              reg_dcsr_prv <= 2'h0;
            end
          end
        end
      end
    end
    if (reset) begin
      reg_debug <= 1'h0;
    end else begin
      if (insn_ret) begin
        if (T_5452) begin
          reg_debug <= 1'h0;
        end else begin
          if (exception) begin
            if (T_5543) begin
              reg_debug <= 1'h1;
            end
          end
        end
      end else begin
        if (exception) begin
          if (T_5543) begin
            reg_debug <= 1'h1;
          end
        end
      end
    end
    if (wen) begin
      if (T_5122) begin
        reg_dpc <= T_6319;
      end else begin
        if (exception) begin
          if (T_5543) begin
            reg_dpc <= T_5577;
          end
        end
      end
    end else begin
      if (exception) begin
        if (T_5543) begin
          reg_dpc <= T_5577;
        end
      end
    end
    if (wen) begin
      if (T_5124) begin
        reg_dscratch <= wdata;
      end
    end
    if (T_4604) begin
      reg_singleStepped <= 1'h0;
    end else begin
      if (T_4601) begin
        reg_singleStepped <= 1'h1;
      end
    end
    reg_tselect <= 1'h0;
    reg_bp_0_control_ttype <= 4'h2;
    if (reset) begin
      reg_bp_0_control_dmode <= 1'h0;
    end else begin
      if (wen) begin
        if (T_6341) begin
          if (T_5082) begin
            if (1'h0 == reg_tselect) begin
              reg_bp_0_control_dmode <= GEN_32;
            end else begin
              if (1'h0 == reg_tselect) begin
                reg_bp_0_control_dmode <= GEN_18;
              end
            end
          end
        end
      end
    end
    reg_bp_0_control_maskmax <= 6'h4;
    reg_bp_0_control_reserved <= 8'h0;
    if (reset) begin
      reg_bp_0_control_action <= 1'h0;
    end else begin
      if (wen) begin
        if (T_6341) begin
          if (T_5082) begin
            if (1'h0 == reg_tselect) begin
              reg_bp_0_control_action <= GEN_33;
            end else begin
              if (1'h0 == reg_tselect) begin
                reg_bp_0_control_action <= GEN_21;
              end
            end
          end
        end
      end
    end
    reg_bp_0_control_chain <= 1'h0;
    reg_bp_0_control_zero <= 2'h0;
    if (wen) begin
      if (T_6341) begin
        if (T_5082) begin
          if (1'h0 == reg_tselect) begin
            reg_bp_0_control_tmatch <= GEN_24;
          end
        end
      end
    end
    if (wen) begin
      if (T_6341) begin
        if (T_5082) begin
          if (1'h0 == reg_tselect) begin
            reg_bp_0_control_m <= GEN_25;
          end
        end
      end
    end
    reg_bp_0_control_h <= 1'h0;
    reg_bp_0_control_s <= 1'h0;
    if (wen) begin
      if (T_6341) begin
        if (T_5082) begin
          if (1'h0 == reg_tselect) begin
            reg_bp_0_control_u <= GEN_28;
          end
        end
      end
    end
    if (reset) begin
      reg_bp_0_control_x <= 1'h0;
    end else begin
      if (wen) begin
        if (T_6341) begin
          if (T_5082) begin
            if (1'h0 == reg_tselect) begin
              reg_bp_0_control_x <= GEN_29;
            end
          end
        end
      end
    end
    if (reset) begin
      reg_bp_0_control_w <= 1'h0;
    end else begin
      if (wen) begin
        if (T_6341) begin
          if (T_5082) begin
            if (1'h0 == reg_tselect) begin
              reg_bp_0_control_w <= GEN_30;
            end
          end
        end
      end
    end
    if (reset) begin
      reg_bp_0_control_r <= 1'h0;
    end else begin
      if (wen) begin
        if (T_6341) begin
          if (T_5082) begin
            if (1'h0 == reg_tselect) begin
              reg_bp_0_control_r <= GEN_31;
            end
          end
        end
      end
    end
    if (wen) begin
      if (T_6341) begin
        if (T_5084) begin
          if (1'h0 == reg_tselect) begin
            reg_bp_0_address <= GEN_34;
          end
        end
      end
    end
    reg_bp_1_control_ttype <= T_6472_control_ttype;
    reg_bp_1_control_dmode <= T_6472_control_dmode;
    reg_bp_1_control_maskmax <= T_6472_control_maskmax;
    reg_bp_1_control_reserved <= T_6472_control_reserved;
    reg_bp_1_control_action <= T_6472_control_action;
    reg_bp_1_control_chain <= T_6472_control_chain;
    reg_bp_1_control_zero <= T_6472_control_zero;
    reg_bp_1_control_tmatch <= T_6472_control_tmatch;
    reg_bp_1_control_m <= T_6472_control_m;
    reg_bp_1_control_h <= T_6472_control_h;
    reg_bp_1_control_s <= T_6472_control_s;
    reg_bp_1_control_u <= T_6472_control_u;
    reg_bp_1_control_x <= T_6472_control_x;
    reg_bp_1_control_w <= T_6472_control_w;
    reg_bp_1_control_r <= T_6472_control_r;
    reg_bp_1_address <= T_6472_address;
    if (wen) begin
      if (T_5104) begin
        reg_mie <= T_6214;
      end
    end
    reg_mideleg <= 32'h0;
    reg_medeleg <= 32'h0;
    reg_mip_meip <= io_interrupts_meip;
    reg_mip_mtip <= io_interrupts_mtip;
    reg_mip_msip <= io_interrupts_msip;
    if (wen) begin
      if (T_5112) begin
        reg_mepc <= T_6222;
      end else begin
        if (exception) begin
          if (T_5614) begin
            reg_mepc <= T_5623;
          end
        end
      end
    end else begin
      if (exception) begin
        if (T_5614) begin
          reg_mepc <= T_5623;
        end
      end
    end
    if (wen) begin
      if (T_5116) begin
        reg_mcause <= T_6226;
      end else begin
        if (exception) begin
          if (T_5614) begin
            if (T_5514) begin
              reg_mcause <= io_cause;
            end else begin
              reg_mcause <= {{28'd0}, T_5521};
            end
          end
        end
      end
    end else begin
      if (exception) begin
        if (T_5614) begin
          if (T_5514) begin
            reg_mcause <= io_cause;
          end else begin
            reg_mcause <= {{28'd0}, T_5521};
          end
        end
      end
    end
    if (wen) begin
      if (T_5114) begin
        reg_mbadaddr <= wdata;
      end else begin
        if (exception) begin
          if (T_5614) begin
            if (T_5599) begin
              reg_mbadaddr <= io_badaddr;
            end
          end
        end
      end
    end else begin
      if (exception) begin
        if (T_5614) begin
          if (T_5599) begin
            reg_mbadaddr <= io_badaddr;
          end
        end
      end
    end
    if (wen) begin
      if (T_5110) begin
        reg_mscratch <= wdata;
      end
    end
    if (reset) begin
      reg_mtvec <= 32'h0;
    end else begin
      if (wen) begin
        if (T_5100) begin
          reg_mtvec <= T_6224;
        end
      end
    end
    if (wen) begin
      if (T_5300) begin
        reg_mucounteren <= T_6321;
      end
    end
    reg_mscounteren <= 32'h0;
    reg_sptbr_asid <= 7'h0;
    if (reset) begin
      reg_wfi <= 1'h0;
    end else begin
      if (T_5511) begin
        reg_wfi <= 1'h0;
      end else begin
        if (insn_wfi) begin
          reg_wfi <= 1'h1;
        end
      end
    end
    if (io_fcsr_flags_valid) begin
      reg_fflags <= T_6036;
    end
    if (reset) begin
      T_4797 <= 6'h0;
    end else begin
      T_4797 <= GEN_260[5:0];
    end
    if (reset) begin
      T_4800 <= 58'h0;
    end else begin
      T_4800 <= GEN_261[57:0];
    end
    if (reset) begin
      T_4807 <= 6'h0;
    end else begin
      T_4807 <= GEN_258[5:0];
    end
    if (reset) begin
      T_4810 <= 58'h0;
    end else begin
      T_4810 <= GEN_259[57:0];
    end
    if (reset) begin
      reg_misa <= 32'h40101105;
    end else begin
      if (wen) begin
        if (T_5096) begin
          reg_misa <= T_6158;
        end
      end
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (1'h0) begin
          $fwrite(32'h80000002,"Assertion failed\n    at csr.scala:215 assert(!io.singleStep || io.retire <= UInt(1))\n");
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (1'h0) begin
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
        if (T_4621) begin
          $fwrite(32'h80000002,"Assertion failed\n    at csr.scala:216 assert(!reg_singleStepped || io.retire === UInt(0))\n");
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (T_4621) begin
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
        if (T_5683) begin
          $fwrite(32'h80000002,"Assertion failed: these conditions must be mutually exclusive\n    at csr.scala:496 assert(PopCount(insn_ret :: io.exception :: io.csr_xcpt :: Nil) <= 1, \"these conditions must be mutually exclusive\")\n");
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (T_5683) begin
          $fatal;
        end
    `ifdef STOP_COND
      end
    `endif
    `endif
  end

  always @(posedge clock) begin
    reg_mip_usip <= reg_mip_usip; 
    reg_mip_utip <= reg_mip_utip;
    reg_mip_ueip <= reg_mip_ueip;
    reg_mip_ssip <= reg_mip_ssip; 
    reg_mip_stip <= reg_mip_stip;
    reg_mip_seip <= reg_mip_seip;
    reg_mip_hsip <= reg_mip_hsip; 
    reg_mip_htip <= reg_mip_htip;
    reg_mip_heip <= reg_mip_heip;
  end
  assume property (reg_misa == 32'h40101105);
endmodule