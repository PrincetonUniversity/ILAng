module Frontend(
  input   clock,
  input   reset,
  input   io_cpu_req_valid,
  input  [31:0] io_cpu_req_bits_pc,
  input   io_cpu_req_bits_speculative,
  input   io_cpu_resp_ready,
  output  io_cpu_resp_valid,
  output  io_cpu_resp_bits_btb_valid,
  output  io_cpu_resp_bits_btb_bits_taken,
  output [1:0] io_cpu_resp_bits_btb_bits_mask,
  output  io_cpu_resp_bits_btb_bits_bridx,
  output [31:0] io_cpu_resp_bits_btb_bits_target,
  output  io_cpu_resp_bits_btb_bits_entry,
  output  io_cpu_resp_bits_btb_bits_bht_history,
  output [1:0] io_cpu_resp_bits_btb_bits_bht_value,
  output [31:0] io_cpu_resp_bits_pc,
  output [31:0] io_cpu_resp_bits_data,
  output [1:0] io_cpu_resp_bits_mask,
  output  io_cpu_resp_bits_xcpt_if,
  output  io_cpu_resp_bits_replay,
  input   io_cpu_btb_update_valid,
  input   io_cpu_btb_update_bits_prediction_valid,
  input   io_cpu_btb_update_bits_prediction_bits_taken,
  input  [1:0] io_cpu_btb_update_bits_prediction_bits_mask,
  input   io_cpu_btb_update_bits_prediction_bits_bridx,
  input  [31:0] io_cpu_btb_update_bits_prediction_bits_target,
  input   io_cpu_btb_update_bits_prediction_bits_entry,
  input   io_cpu_btb_update_bits_prediction_bits_bht_history,
  input  [1:0] io_cpu_btb_update_bits_prediction_bits_bht_value,
  input  [31:0] io_cpu_btb_update_bits_pc,
  input  [31:0] io_cpu_btb_update_bits_target,
  input   io_cpu_btb_update_bits_taken,
  input   io_cpu_btb_update_bits_isValid,
  input   io_cpu_btb_update_bits_isJump,
  input   io_cpu_btb_update_bits_isReturn,
  input  [31:0] io_cpu_btb_update_bits_br_pc,
  input   io_cpu_bht_update_valid,
  input   io_cpu_bht_update_bits_prediction_valid,
  input   io_cpu_bht_update_bits_prediction_bits_taken,
  input  [1:0] io_cpu_bht_update_bits_prediction_bits_mask,
  input   io_cpu_bht_update_bits_prediction_bits_bridx,
  input  [31:0] io_cpu_bht_update_bits_prediction_bits_target,
  input   io_cpu_bht_update_bits_prediction_bits_entry,
  input   io_cpu_bht_update_bits_prediction_bits_bht_history,
  input  [1:0] io_cpu_bht_update_bits_prediction_bits_bht_value,
  input  [31:0] io_cpu_bht_update_bits_pc,
  input   io_cpu_bht_update_bits_taken,
  input   io_cpu_bht_update_bits_mispredict,
  input   io_cpu_ras_update_valid,
  input   io_cpu_ras_update_bits_isCall,
  input   io_cpu_ras_update_bits_isReturn,
  input  [31:0] io_cpu_ras_update_bits_returnAddr,
  input   io_cpu_ras_update_bits_prediction_valid,
  input   io_cpu_ras_update_bits_prediction_bits_taken,
  input  [1:0] io_cpu_ras_update_bits_prediction_bits_mask,
  input   io_cpu_ras_update_bits_prediction_bits_bridx,
  input  [31:0] io_cpu_ras_update_bits_prediction_bits_target,
  input   io_cpu_ras_update_bits_prediction_bits_entry,
  input   io_cpu_ras_update_bits_prediction_bits_bht_history,
  input  [1:0] io_cpu_ras_update_bits_prediction_bits_bht_value,
  input   io_cpu_flush_icache,
  input   io_cpu_flush_tlb,
  output [31:0] io_cpu_npc,
  input   io_ptw_req_ready,
  output  io_ptw_req_valid,
  output [1:0] io_ptw_req_bits_prv,
  output  io_ptw_req_bits_pum,
  output  io_ptw_req_bits_mxr,
  output [19:0] io_ptw_req_bits_addr,
  output  io_ptw_req_bits_store,
  output  io_ptw_req_bits_fetch,
  input   io_ptw_resp_valid,
  input  [15:0] io_ptw_resp_bits_pte_reserved_for_hardware,
  input  [37:0] io_ptw_resp_bits_pte_ppn,
  input  [1:0] io_ptw_resp_bits_pte_reserved_for_software,
  input   io_ptw_resp_bits_pte_d,
  input   io_ptw_resp_bits_pte_a,
  input   io_ptw_resp_bits_pte_g,
  input   io_ptw_resp_bits_pte_u,
  input   io_ptw_resp_bits_pte_x,
  input   io_ptw_resp_bits_pte_w,
  input   io_ptw_resp_bits_pte_r,
  input   io_ptw_resp_bits_pte_v,
  input  [6:0] io_ptw_ptbr_asid,
  input  [21:0] io_ptw_ptbr_ppn,
  input   io_ptw_invalidate,
  input   io_ptw_status_debug,
  input  [31:0] io_ptw_status_isa,
  input  [1:0] io_ptw_status_prv,
  input   io_ptw_status_sd,
  input  [30:0] io_ptw_status_zero3,
  input   io_ptw_status_sd_rv32,
  input  [1:0] io_ptw_status_zero2,
  input  [4:0] io_ptw_status_vm,
  input  [3:0] io_ptw_status_zero1,
  input   io_ptw_status_mxr,
  input   io_ptw_status_pum,
  input   io_ptw_status_mprv,
  input  [1:0] io_ptw_status_xs,
  input  [1:0] io_ptw_status_fs,
  input  [1:0] io_ptw_status_mpp,
  input  [1:0] io_ptw_status_hpp,
  input   io_ptw_status_spp,
  input   io_ptw_status_mpie,
  input   io_ptw_status_hpie,
  input   io_ptw_status_spie,
  input   io_ptw_status_upie,
  input   io_ptw_status_mie,
  input   io_ptw_status_hie,
  input   io_ptw_status_sie,
  input   io_ptw_status_uie,
  input   io_mem_acquire_ready,
  output  io_mem_acquire_valid,
  output [25:0] io_mem_acquire_bits_addr_block,
  output  io_mem_acquire_bits_client_xact_id,
  output [3:0] io_mem_acquire_bits_addr_beat,
  output  io_mem_acquire_bits_is_builtin_type,
  output [2:0] io_mem_acquire_bits_a_type,
  output [9:0] io_mem_acquire_bits_union,
  output [31:0] io_mem_acquire_bits_data,
  output  io_mem_grant_ready,
  input   io_mem_grant_valid,
  input  [3:0] io_mem_grant_bits_addr_beat,
  input   io_mem_grant_bits_client_xact_id,
  input  [1:0] io_mem_grant_bits_manager_xact_id,
  input   io_mem_grant_bits_is_builtin_type,
  input  [3:0] io_mem_grant_bits_g_type,
  input  [31:0] io_mem_grant_bits_data,
  input  [31:0] io_resetVector
);
  wire  icache_clock;
  wire  icache_reset;
  wire  icache_io_req_valid;
  wire [31:0] icache_io_req_bits_addr;
  wire [19:0] icache_io_s1_ppn;
  wire  icache_io_s1_kill;
  wire  icache_io_s2_kill;
  wire  icache_io_resp_ready;
  wire  icache_io_resp_valid;
  wire [15:0] icache_io_resp_bits_data;
  wire [31:0] icache_io_resp_bits_datablock;
  wire  icache_io_invalidate;
  wire  icache_io_mem_acquire_ready;
  wire  icache_io_mem_acquire_valid;
  wire [25:0] icache_io_mem_acquire_bits_addr_block;
  wire  icache_io_mem_acquire_bits_client_xact_id;
  wire [3:0] icache_io_mem_acquire_bits_addr_beat;
  wire  icache_io_mem_acquire_bits_is_builtin_type;
  wire [2:0] icache_io_mem_acquire_bits_a_type;
  wire [9:0] icache_io_mem_acquire_bits_union;
  wire [31:0] icache_io_mem_acquire_bits_data;
  wire  icache_io_mem_grant_ready;
  wire  icache_io_mem_grant_valid;
  wire [3:0] icache_io_mem_grant_bits_addr_beat;
  wire  icache_io_mem_grant_bits_client_xact_id;
  wire [1:0] icache_io_mem_grant_bits_manager_xact_id;
  wire  icache_io_mem_grant_bits_is_builtin_type;
  wire [3:0] icache_io_mem_grant_bits_g_type;
  wire [31:0] icache_io_mem_grant_bits_data;
  wire  tlb_clock;
  wire  tlb_reset;
  wire  tlb_io_req_ready;
  wire  tlb_io_req_valid;
  wire [19:0] tlb_io_req_bits_vpn;
  wire  tlb_io_req_bits_passthrough;
  wire  tlb_io_req_bits_instruction;
  wire  tlb_io_req_bits_store;
  wire  tlb_io_resp_miss;
  wire [19:0] tlb_io_resp_ppn;
  wire  tlb_io_resp_xcpt_ld;
  wire  tlb_io_resp_xcpt_st;
  wire  tlb_io_resp_xcpt_if;
  wire  tlb_io_resp_cacheable;
  wire  tlb_io_ptw_req_ready;
  wire  tlb_io_ptw_req_valid;
  wire [1:0] tlb_io_ptw_req_bits_prv;
  wire  tlb_io_ptw_req_bits_pum;
  wire  tlb_io_ptw_req_bits_mxr;
  wire [19:0] tlb_io_ptw_req_bits_addr;
  wire  tlb_io_ptw_req_bits_store;
  wire  tlb_io_ptw_req_bits_fetch;
  wire  tlb_io_ptw_resp_valid;
  wire [15:0] tlb_io_ptw_resp_bits_pte_reserved_for_hardware;
  wire [37:0] tlb_io_ptw_resp_bits_pte_ppn;
  wire [1:0] tlb_io_ptw_resp_bits_pte_reserved_for_software;
  wire  tlb_io_ptw_resp_bits_pte_d;
  wire  tlb_io_ptw_resp_bits_pte_a;
  wire  tlb_io_ptw_resp_bits_pte_g;
  wire  tlb_io_ptw_resp_bits_pte_u;
  wire  tlb_io_ptw_resp_bits_pte_x;
  wire  tlb_io_ptw_resp_bits_pte_w;
  wire  tlb_io_ptw_resp_bits_pte_r;
  wire  tlb_io_ptw_resp_bits_pte_v;
  wire [6:0] tlb_io_ptw_ptbr_asid;
  wire [21:0] tlb_io_ptw_ptbr_ppn;
  wire  tlb_io_ptw_invalidate;
  wire  tlb_io_ptw_status_debug;
  wire [31:0] tlb_io_ptw_status_isa;
  wire [1:0] tlb_io_ptw_status_prv;
  wire  tlb_io_ptw_status_sd;
  wire [30:0] tlb_io_ptw_status_zero3;
  wire  tlb_io_ptw_status_sd_rv32;
  wire [1:0] tlb_io_ptw_status_zero2;
  wire [4:0] tlb_io_ptw_status_vm;
  wire [3:0] tlb_io_ptw_status_zero1;
  wire  tlb_io_ptw_status_mxr;
  wire  tlb_io_ptw_status_pum;
  wire  tlb_io_ptw_status_mprv;
  wire [1:0] tlb_io_ptw_status_xs;
  wire [1:0] tlb_io_ptw_status_fs;
  wire [1:0] tlb_io_ptw_status_mpp;
  wire [1:0] tlb_io_ptw_status_hpp;
  wire  tlb_io_ptw_status_spp;
  wire  tlb_io_ptw_status_mpie;
  wire  tlb_io_ptw_status_hpie;
  wire  tlb_io_ptw_status_spie;
  wire  tlb_io_ptw_status_upie;
  wire  tlb_io_ptw_status_mie;
  wire  tlb_io_ptw_status_hie;
  wire  tlb_io_ptw_status_sie;
  wire  tlb_io_ptw_status_uie;
  reg [31:0] s1_pc_;
  reg [31:0] GEN_16;
  wire [31:0] T_1550;
  wire [31:0] T_1552;
  wire [31:0] s1_pc;
  reg  s1_speculative;
  reg [31:0] GEN_17;
  reg  s1_same_block;
  reg [31:0] GEN_18;
  reg  s2_valid;
  reg [31:0] GEN_19;
  reg [31:0] s2_pc;
  reg [31:0] GEN_20;
  reg  s2_btb_resp_valid;
  reg [31:0] GEN_21;
  reg  s2_btb_resp_bits_taken;
  reg [31:0] GEN_22;
  reg [1:0] s2_btb_resp_bits_mask;
  reg [31:0] GEN_23;
  reg  s2_btb_resp_bits_bridx;
  reg [31:0] GEN_24;
  reg [31:0] s2_btb_resp_bits_target;
  reg [31:0] GEN_25;
  reg  s2_btb_resp_bits_entry;
  reg [31:0] GEN_26;
  reg  s2_btb_resp_bits_bht_history;
  reg [31:0] GEN_27;
  reg [1:0] s2_btb_resp_bits_bht_value;
  reg [31:0] GEN_28;
  reg  s2_xcpt_if;
  reg [31:0] GEN_29;
  reg  s2_speculative;
  reg [31:0] GEN_30;
  reg  s2_cacheable;
  reg [31:0] GEN_31;
  wire [31:0] T_1577;
  wire [31:0] T_1579;
  wire [31:0] T_1580;
  wire [32:0] T_1582;
  wire [31:0] ntpc;
  wire [31:0] T_1584;
  wire [31:0] T_1586;
  wire  ntpc_same_block;
  wire [31:0] predicted_npc;
  wire  predicted_taken;
  wire  T_1589;
  wire  icmiss;
  wire [31:0] npc;
  wire  T_1591;
  wire  T_1593;
  wire  T_1594;
  wire  T_1596;
  wire  T_1597;
  wire  s0_same_block;
  wire  T_1599;
  wire  stall;
  wire  T_1601;
  wire  T_1603;
  wire  T_1604;
  wire  T_1606;
  wire  T_1607;
  wire  T_1608;
  wire  T_1609;
  wire  T_1610;
  wire  T_1617;
  wire [31:0] GEN_0;
  wire  GEN_1;
  wire  GEN_2;
  wire  GEN_3;
  wire  GEN_4;
  wire [31:0] GEN_5;
  wire  GEN_6;
  wire  GEN_7;
  wire [31:0] GEN_8;
  wire  GEN_9;
  wire  GEN_10;
  wire  GEN_11;
  wire  GEN_12;
  wire [31:0] GEN_13;
  wire  GEN_14;
  wire  GEN_15;
  wire  T_1624;
  wire [19:0] T_1625;
  wire  T_1632;
  wire  T_1633;
  wire  T_1634;
  wire  T_1635;
  wire  T_1636;
  wire  T_1637;
  wire  T_1639;
  wire  T_1640;
  wire  T_1644;
  wire  T_1645;
  wire  T_1646;
  wire  T_1647;
  wire  T_1648;
  wire [31:0] T_1649;
  wire [31:0] T_1652;
  wire  T_1654;
  wire [2:0] T_1655;
  wire  T_1658;
  wire  T_1660;
  wire  T_1661;
  ICache icache (
    .clock(icache_clock),
    .reset(icache_reset),
    .io_req_valid(icache_io_req_valid),
    .io_req_bits_addr(icache_io_req_bits_addr),
    .io_s1_ppn(icache_io_s1_ppn),
    .io_s1_kill(icache_io_s1_kill),
    .io_s2_kill(icache_io_s2_kill),
    .io_resp_ready(icache_io_resp_ready),
    .io_resp_valid(icache_io_resp_valid),
    .io_resp_bits_data(icache_io_resp_bits_data),
    .io_resp_bits_datablock(icache_io_resp_bits_datablock),
    .io_invalidate(icache_io_invalidate),
    .io_mem_acquire_ready(icache_io_mem_acquire_ready),
    .io_mem_acquire_valid(icache_io_mem_acquire_valid),
    .io_mem_acquire_bits_addr_block(icache_io_mem_acquire_bits_addr_block),
    .io_mem_acquire_bits_client_xact_id(icache_io_mem_acquire_bits_client_xact_id),
    .io_mem_acquire_bits_addr_beat(icache_io_mem_acquire_bits_addr_beat),
    .io_mem_acquire_bits_is_builtin_type(icache_io_mem_acquire_bits_is_builtin_type),
    .io_mem_acquire_bits_a_type(icache_io_mem_acquire_bits_a_type),
    .io_mem_acquire_bits_union(icache_io_mem_acquire_bits_union),
    .io_mem_acquire_bits_data(icache_io_mem_acquire_bits_data),
    .io_mem_grant_ready(icache_io_mem_grant_ready),
    .io_mem_grant_valid(icache_io_mem_grant_valid),
    .io_mem_grant_bits_addr_beat(icache_io_mem_grant_bits_addr_beat),
    .io_mem_grant_bits_client_xact_id(icache_io_mem_grant_bits_client_xact_id),
    .io_mem_grant_bits_manager_xact_id(icache_io_mem_grant_bits_manager_xact_id),
    .io_mem_grant_bits_is_builtin_type(icache_io_mem_grant_bits_is_builtin_type),
    .io_mem_grant_bits_g_type(icache_io_mem_grant_bits_g_type),
    .io_mem_grant_bits_data(icache_io_mem_grant_bits_data)
  );
  TLB tlb (
    .clock(tlb_clock),
    .reset(tlb_reset),
    .io_req_ready(tlb_io_req_ready),
    .io_req_valid(tlb_io_req_valid),
    .io_req_bits_vpn(tlb_io_req_bits_vpn),
    .io_req_bits_passthrough(tlb_io_req_bits_passthrough),
    .io_req_bits_instruction(tlb_io_req_bits_instruction),
    .io_req_bits_store(tlb_io_req_bits_store),
    .io_resp_miss(tlb_io_resp_miss),
    .io_resp_ppn(tlb_io_resp_ppn),
    .io_resp_xcpt_ld(tlb_io_resp_xcpt_ld),
    .io_resp_xcpt_st(tlb_io_resp_xcpt_st),
    .io_resp_xcpt_if(tlb_io_resp_xcpt_if),
    .io_resp_cacheable(tlb_io_resp_cacheable),
    .io_ptw_req_ready(tlb_io_ptw_req_ready),
    .io_ptw_req_valid(tlb_io_ptw_req_valid),
    .io_ptw_req_bits_prv(tlb_io_ptw_req_bits_prv),
    .io_ptw_req_bits_pum(tlb_io_ptw_req_bits_pum),
    .io_ptw_req_bits_mxr(tlb_io_ptw_req_bits_mxr),
    .io_ptw_req_bits_addr(tlb_io_ptw_req_bits_addr),
    .io_ptw_req_bits_store(tlb_io_ptw_req_bits_store),
    .io_ptw_req_bits_fetch(tlb_io_ptw_req_bits_fetch),
    .io_ptw_resp_valid(tlb_io_ptw_resp_valid),
    .io_ptw_resp_bits_pte_reserved_for_hardware(tlb_io_ptw_resp_bits_pte_reserved_for_hardware),
    .io_ptw_resp_bits_pte_ppn(tlb_io_ptw_resp_bits_pte_ppn),
    .io_ptw_resp_bits_pte_reserved_for_software(tlb_io_ptw_resp_bits_pte_reserved_for_software),
    .io_ptw_resp_bits_pte_d(tlb_io_ptw_resp_bits_pte_d),
    .io_ptw_resp_bits_pte_a(tlb_io_ptw_resp_bits_pte_a),
    .io_ptw_resp_bits_pte_g(tlb_io_ptw_resp_bits_pte_g),
    .io_ptw_resp_bits_pte_u(tlb_io_ptw_resp_bits_pte_u),
    .io_ptw_resp_bits_pte_x(tlb_io_ptw_resp_bits_pte_x),
    .io_ptw_resp_bits_pte_w(tlb_io_ptw_resp_bits_pte_w),
    .io_ptw_resp_bits_pte_r(tlb_io_ptw_resp_bits_pte_r),
    .io_ptw_resp_bits_pte_v(tlb_io_ptw_resp_bits_pte_v),
    .io_ptw_ptbr_asid(tlb_io_ptw_ptbr_asid),
    .io_ptw_ptbr_ppn(tlb_io_ptw_ptbr_ppn),
    .io_ptw_invalidate(tlb_io_ptw_invalidate),
    .io_ptw_status_debug(tlb_io_ptw_status_debug),
    .io_ptw_status_isa(tlb_io_ptw_status_isa),
    .io_ptw_status_prv(tlb_io_ptw_status_prv),
    .io_ptw_status_sd(tlb_io_ptw_status_sd),
    .io_ptw_status_zero3(tlb_io_ptw_status_zero3),
    .io_ptw_status_sd_rv32(tlb_io_ptw_status_sd_rv32),
    .io_ptw_status_zero2(tlb_io_ptw_status_zero2),
    .io_ptw_status_vm(tlb_io_ptw_status_vm),
    .io_ptw_status_zero1(tlb_io_ptw_status_zero1),
    .io_ptw_status_mxr(tlb_io_ptw_status_mxr),
    .io_ptw_status_pum(tlb_io_ptw_status_pum),
    .io_ptw_status_mprv(tlb_io_ptw_status_mprv),
    .io_ptw_status_xs(tlb_io_ptw_status_xs),
    .io_ptw_status_fs(tlb_io_ptw_status_fs),
    .io_ptw_status_mpp(tlb_io_ptw_status_mpp),
    .io_ptw_status_hpp(tlb_io_ptw_status_hpp),
    .io_ptw_status_spp(tlb_io_ptw_status_spp),
    .io_ptw_status_mpie(tlb_io_ptw_status_mpie),
    .io_ptw_status_hpie(tlb_io_ptw_status_hpie),
    .io_ptw_status_spie(tlb_io_ptw_status_spie),
    .io_ptw_status_upie(tlb_io_ptw_status_upie),
    .io_ptw_status_mie(tlb_io_ptw_status_mie),
    .io_ptw_status_hie(tlb_io_ptw_status_hie),
    .io_ptw_status_sie(tlb_io_ptw_status_sie),
    .io_ptw_status_uie(tlb_io_ptw_status_uie)
  );
  assign io_cpu_resp_valid = T_1648;
  assign io_cpu_resp_bits_btb_valid = s2_btb_resp_valid;
  assign io_cpu_resp_bits_btb_bits_taken = s2_btb_resp_bits_taken;
  assign io_cpu_resp_bits_btb_bits_mask = s2_btb_resp_bits_mask;
  assign io_cpu_resp_bits_btb_bits_bridx = s2_btb_resp_bits_bridx;
  assign io_cpu_resp_bits_btb_bits_target = s2_btb_resp_bits_target;
  assign io_cpu_resp_bits_btb_bits_entry = s2_btb_resp_bits_entry;
  assign io_cpu_resp_bits_btb_bits_bht_history = s2_btb_resp_bits_bht_history;
  assign io_cpu_resp_bits_btb_bits_bht_value = s2_btb_resp_bits_bht_value;
  assign io_cpu_resp_bits_pc = s2_pc;
  assign io_cpu_resp_bits_data = T_1652;
  assign io_cpu_resp_bits_mask = T_1655[1:0];
  assign io_cpu_resp_bits_xcpt_if = s2_xcpt_if;
  assign io_cpu_resp_bits_replay = T_1661;
  assign io_cpu_npc = T_1649;
  assign io_ptw_req_valid = tlb_io_ptw_req_valid;
  assign io_ptw_req_bits_prv = tlb_io_ptw_req_bits_prv;
  assign io_ptw_req_bits_pum = tlb_io_ptw_req_bits_pum;
  assign io_ptw_req_bits_mxr = tlb_io_ptw_req_bits_mxr;
  assign io_ptw_req_bits_addr = tlb_io_ptw_req_bits_addr;
  assign io_ptw_req_bits_store = tlb_io_ptw_req_bits_store;
  assign io_ptw_req_bits_fetch = tlb_io_ptw_req_bits_fetch;
  assign io_mem_acquire_valid = icache_io_mem_acquire_valid;
  assign io_mem_acquire_bits_addr_block = icache_io_mem_acquire_bits_addr_block;
  assign io_mem_acquire_bits_client_xact_id = icache_io_mem_acquire_bits_client_xact_id;
  assign io_mem_acquire_bits_addr_beat = icache_io_mem_acquire_bits_addr_beat;
  assign io_mem_acquire_bits_is_builtin_type = icache_io_mem_acquire_bits_is_builtin_type;
  assign io_mem_acquire_bits_a_type = icache_io_mem_acquire_bits_a_type;
  assign io_mem_acquire_bits_union = icache_io_mem_acquire_bits_union;
  assign io_mem_acquire_bits_data = icache_io_mem_acquire_bits_data;
  assign io_mem_grant_ready = icache_io_mem_grant_ready;
  assign icache_clock = clock;
  assign icache_reset = reset;
  assign icache_io_req_valid = T_1633;
  assign icache_io_req_bits_addr = io_cpu_npc;
  assign icache_io_s1_ppn = tlb_io_resp_ppn;
  assign icache_io_s1_kill = T_1637;
  assign icache_io_s2_kill = T_1640;
  assign icache_io_resp_ready = T_1645;
  assign icache_io_invalidate = io_cpu_flush_icache;
  assign icache_io_mem_acquire_ready = io_mem_acquire_ready;
  assign icache_io_mem_grant_valid = io_mem_grant_valid;
  assign icache_io_mem_grant_bits_addr_beat = io_mem_grant_bits_addr_beat;
  assign icache_io_mem_grant_bits_client_xact_id = io_mem_grant_bits_client_xact_id;
  assign icache_io_mem_grant_bits_manager_xact_id = io_mem_grant_bits_manager_xact_id;
  assign icache_io_mem_grant_bits_is_builtin_type = io_mem_grant_bits_is_builtin_type;
  assign icache_io_mem_grant_bits_g_type = io_mem_grant_bits_g_type;
  assign icache_io_mem_grant_bits_data = io_mem_grant_bits_data;
  assign tlb_clock = clock;
  assign tlb_reset = reset;
  assign tlb_io_req_valid = T_1624;
  assign tlb_io_req_bits_vpn = T_1625;
  assign tlb_io_req_bits_passthrough = 1'h0;
  assign tlb_io_req_bits_instruction = 1'h1;
  assign tlb_io_req_bits_store = 1'h0;
  assign tlb_io_ptw_req_ready = io_ptw_req_ready;
  assign tlb_io_ptw_resp_valid = io_ptw_resp_valid;
  assign tlb_io_ptw_resp_bits_pte_reserved_for_hardware = io_ptw_resp_bits_pte_reserved_for_hardware;
  assign tlb_io_ptw_resp_bits_pte_ppn = io_ptw_resp_bits_pte_ppn;
  assign tlb_io_ptw_resp_bits_pte_reserved_for_software = io_ptw_resp_bits_pte_reserved_for_software;
  assign tlb_io_ptw_resp_bits_pte_d = io_ptw_resp_bits_pte_d;
  assign tlb_io_ptw_resp_bits_pte_a = io_ptw_resp_bits_pte_a;
  assign tlb_io_ptw_resp_bits_pte_g = io_ptw_resp_bits_pte_g;
  assign tlb_io_ptw_resp_bits_pte_u = io_ptw_resp_bits_pte_u;
  assign tlb_io_ptw_resp_bits_pte_x = io_ptw_resp_bits_pte_x;
  assign tlb_io_ptw_resp_bits_pte_w = io_ptw_resp_bits_pte_w;
  assign tlb_io_ptw_resp_bits_pte_r = io_ptw_resp_bits_pte_r;
  assign tlb_io_ptw_resp_bits_pte_v = io_ptw_resp_bits_pte_v;
  assign tlb_io_ptw_ptbr_asid = io_ptw_ptbr_asid;
  assign tlb_io_ptw_ptbr_ppn = io_ptw_ptbr_ppn;
  assign tlb_io_ptw_invalidate = io_ptw_invalidate;
  assign tlb_io_ptw_status_debug = io_ptw_status_debug;
  assign tlb_io_ptw_status_isa = io_ptw_status_isa;
  assign tlb_io_ptw_status_prv = io_ptw_status_prv;
  assign tlb_io_ptw_status_sd = io_ptw_status_sd;
  assign tlb_io_ptw_status_zero3 = io_ptw_status_zero3;
  assign tlb_io_ptw_status_sd_rv32 = io_ptw_status_sd_rv32;
  assign tlb_io_ptw_status_zero2 = io_ptw_status_zero2;
  assign tlb_io_ptw_status_vm = io_ptw_status_vm;
  assign tlb_io_ptw_status_zero1 = io_ptw_status_zero1;
  assign tlb_io_ptw_status_mxr = io_ptw_status_mxr;
  assign tlb_io_ptw_status_pum = io_ptw_status_pum;
  assign tlb_io_ptw_status_mprv = io_ptw_status_mprv;
  assign tlb_io_ptw_status_xs = io_ptw_status_xs;
  assign tlb_io_ptw_status_fs = io_ptw_status_fs;
  assign tlb_io_ptw_status_mpp = io_ptw_status_mpp;
  assign tlb_io_ptw_status_hpp = io_ptw_status_hpp;
  assign tlb_io_ptw_status_spp = io_ptw_status_spp;
  assign tlb_io_ptw_status_mpie = io_ptw_status_mpie;
  assign tlb_io_ptw_status_hpie = io_ptw_status_hpie;
  assign tlb_io_ptw_status_spie = io_ptw_status_spie;
  assign tlb_io_ptw_status_upie = io_ptw_status_upie;
  assign tlb_io_ptw_status_mie = io_ptw_status_mie;
  assign tlb_io_ptw_status_hie = io_ptw_status_hie;
  assign tlb_io_ptw_status_sie = io_ptw_status_sie;
  assign tlb_io_ptw_status_uie = io_ptw_status_uie;
  assign T_1550 = ~ s1_pc_;
  assign T_1552 = T_1550 | 32'h1;
  assign s1_pc = ~ T_1552;
  assign T_1577 = ~ s1_pc;
  assign T_1579 = T_1577 | 32'h3;
  assign T_1580 = ~ T_1579;
  assign T_1582 = T_1580 + 32'h4;
  assign ntpc = T_1582[31:0];
  assign T_1584 = ntpc & 32'h4;
  assign T_1586 = s1_pc & 32'h4;
  assign ntpc_same_block = T_1584 == T_1586;
  assign predicted_npc = ntpc;
  assign predicted_taken = 1'h0;
  assign T_1589 = icache_io_resp_valid == 1'h0;
  assign icmiss = s2_valid & T_1589;
  assign npc = icmiss ? s2_pc : predicted_npc;
  assign T_1591 = predicted_taken == 1'h0;
  assign T_1593 = icmiss == 1'h0;
  assign T_1594 = T_1591 & T_1593;
  assign T_1596 = io_cpu_req_valid == 1'h0;
  assign T_1597 = T_1594 & T_1596;
  assign s0_same_block = T_1597 & ntpc_same_block;
  assign T_1599 = io_cpu_resp_ready == 1'h0;
  assign stall = io_cpu_resp_valid & T_1599;
  assign T_1601 = stall == 1'h0;
  assign T_1603 = tlb_io_resp_miss == 1'h0;
  assign T_1604 = s0_same_block & T_1603;
  assign T_1606 = s2_speculative == 1'h0;
  assign T_1607 = s2_valid & T_1606;
  assign T_1608 = s1_speculative | T_1607;
  assign T_1609 = T_1608 | predicted_taken;
  assign T_1610 = icmiss ? s2_speculative : T_1609;
  assign T_1617 = tlb_io_resp_xcpt_if & T_1603;
  assign GEN_0 = T_1593 ? s1_pc : s2_pc;
  assign GEN_1 = T_1593 ? s1_speculative : s2_speculative;
  assign GEN_2 = T_1593 ? tlb_io_resp_cacheable : s2_cacheable;
  assign GEN_3 = T_1593 ? T_1617 : s2_xcpt_if;
  assign GEN_4 = T_1601 ? T_1604 : s1_same_block;
  assign GEN_5 = T_1601 ? io_cpu_npc : s1_pc_;
  assign GEN_6 = T_1601 ? T_1610 : s1_speculative;
  assign GEN_7 = T_1601 ? T_1593 : s2_valid;
  assign GEN_8 = T_1601 ? GEN_0 : s2_pc;
  assign GEN_9 = T_1601 ? GEN_1 : s2_speculative;
  assign GEN_10 = T_1601 ? GEN_2 : s2_cacheable;
  assign GEN_11 = T_1601 ? GEN_3 : s2_xcpt_if;
  assign GEN_12 = io_cpu_req_valid ? 1'h0 : GEN_4;
  assign GEN_13 = io_cpu_req_valid ? io_cpu_npc : GEN_5;
  assign GEN_14 = io_cpu_req_valid ? io_cpu_req_bits_speculative : GEN_6;
  assign GEN_15 = io_cpu_req_valid ? 1'h0 : GEN_7;
  assign T_1624 = T_1601 & T_1593;
  assign T_1625 = s1_pc[31:12];
  assign T_1632 = s0_same_block == 1'h0;
  assign T_1633 = T_1601 & T_1632;
  assign T_1634 = io_cpu_req_valid | tlb_io_resp_miss;
  assign T_1635 = T_1634 | tlb_io_resp_xcpt_if;
  assign T_1636 = T_1635 | icmiss;
  assign T_1637 = T_1636 | io_cpu_flush_tlb;
  assign T_1639 = s2_cacheable == 1'h0;
  assign T_1640 = s2_speculative & T_1639;
  assign T_1644 = s1_same_block == 1'h0;
  assign T_1645 = T_1601 & T_1644;
  assign T_1646 = icache_io_resp_valid | icache_io_s2_kill;
  assign T_1647 = T_1646 | s2_xcpt_if;
  assign T_1648 = s2_valid & T_1647;
  assign T_1649 = io_cpu_req_valid ? io_cpu_req_bits_pc : npc;
  assign T_1652 = icache_io_resp_bits_datablock >> 6'h0;
  assign T_1654 = s2_pc[1];
  assign T_1655 = 3'h3 << T_1654;
  assign T_1658 = icache_io_s2_kill & T_1589;
  assign T_1660 = s2_xcpt_if == 1'h0;
  assign T_1661 = T_1658 & T_1660;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_16 = {1{$random}};
  s1_pc_ = GEN_16[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_17 = {1{$random}};
  s1_speculative = GEN_17[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_18 = {1{$random}};
  s1_same_block = GEN_18[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_19 = {1{$random}};
  s2_valid = GEN_19[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_20 = {1{$random}};
  s2_pc = GEN_20[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_21 = {1{$random}};
  s2_btb_resp_valid = GEN_21[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_22 = {1{$random}};
  s2_btb_resp_bits_taken = GEN_22[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_23 = {1{$random}};
  s2_btb_resp_bits_mask = GEN_23[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_24 = {1{$random}};
  s2_btb_resp_bits_bridx = GEN_24[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_25 = {1{$random}};
  s2_btb_resp_bits_target = GEN_25[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_26 = {1{$random}};
  s2_btb_resp_bits_entry = GEN_26[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_27 = {1{$random}};
  s2_btb_resp_bits_bht_history = GEN_27[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_28 = {1{$random}};
  s2_btb_resp_bits_bht_value = GEN_28[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_29 = {1{$random}};
  s2_xcpt_if = GEN_29[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_30 = {1{$random}};
  s2_speculative = GEN_30[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_31 = {1{$random}};
  s2_cacheable = GEN_31[0:0];
  `endif
  end
`endif
  always @(posedge clock) begin
    if (io_cpu_req_valid) begin
      s1_pc_ <= io_cpu_npc;
    end else begin
      if (T_1601) begin
        s1_pc_ <= io_cpu_npc;
      end
    end
    if (io_cpu_req_valid) begin
      s1_speculative <= io_cpu_req_bits_speculative;
    end else begin
      if (T_1601) begin
        if (icmiss) begin
          s1_speculative <= s2_speculative;
        end else begin
          s1_speculative <= T_1609;
        end
      end
    end
    if (io_cpu_req_valid) begin
      s1_same_block <= 1'h0;
    end else begin
      if (T_1601) begin
        s1_same_block <= T_1604;
      end
    end
    if (reset) begin
      s2_valid <= 1'h1;
    end else begin
      if (io_cpu_req_valid) begin
        s2_valid <= 1'h0;
      end else begin
        if (T_1601) begin
          s2_valid <= T_1593;
        end
      end
    end
    if (reset) begin
      s2_pc <= io_resetVector;
    end else begin
      if (T_1601) begin
        if (T_1593) begin
          s2_pc <= s1_pc;
        end
      end
    end
    if (reset) begin
      s2_btb_resp_valid <= 1'h0;
    end
    if (reset) begin
      s2_xcpt_if <= 1'h0;
    end else begin
      if (T_1601) begin
        if (T_1593) begin
          s2_xcpt_if <= T_1617;
        end
      end
    end
    if (reset) begin
      s2_speculative <= 1'h0;
    end else begin
      if (T_1601) begin
        if (T_1593) begin
          s2_speculative <= s1_speculative;
        end
      end
    end
    if (reset) begin
      s2_cacheable <= 1'h0;
    end else begin
      if (T_1601) begin
        if (T_1593) begin
          s2_cacheable <= tlb_io_resp_cacheable;
        end
      end
    end
  end
endmodule

