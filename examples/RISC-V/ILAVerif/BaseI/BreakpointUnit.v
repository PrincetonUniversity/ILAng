module BreakpointUnit(
  input   clock,
  input   reset,
  input   io_status_debug,
  input  [31:0] io_status_isa,
  input  [1:0] io_status_prv,
  input   io_status_sd,
  input  [30:0] io_status_zero3,
  input   io_status_sd_rv32,
  input  [1:0] io_status_zero2,
  input  [4:0] io_status_vm,
  input  [3:0] io_status_zero1,
  input   io_status_mxr,
  input   io_status_pum,
  input   io_status_mprv,
  input  [1:0] io_status_xs,
  input  [1:0] io_status_fs,
  input  [1:0] io_status_mpp,
  input  [1:0] io_status_hpp,
  input   io_status_spp,
  input   io_status_mpie,
  input   io_status_hpie,
  input   io_status_spie,
  input   io_status_upie,
  input   io_status_mie,
  input   io_status_hie,
  input   io_status_sie,
  input   io_status_uie,
  input  [3:0] io_bp_0_control_ttype,
  input   io_bp_0_control_dmode,
  input  [5:0] io_bp_0_control_maskmax,
  input  [7:0] io_bp_0_control_reserved,
  input   io_bp_0_control_action,
  input   io_bp_0_control_chain,
  input  [1:0] io_bp_0_control_zero,
  input  [1:0] io_bp_0_control_tmatch,
  input   io_bp_0_control_m,
  input   io_bp_0_control_h,
  input   io_bp_0_control_s,
  input   io_bp_0_control_u,
  input   io_bp_0_control_x,
  input   io_bp_0_control_w,
  input   io_bp_0_control_r,
  input  [31:0] io_bp_0_address,
  input  [31:0] io_pc,
  input  [31:0] io_ea,
  output  io_xcpt_if,
  output  io_xcpt_ld,
  output  io_xcpt_st,
  output  io_debug_if,
  output  io_debug_ld,
  output  io_debug_st
);
  wire  T_170;
  wire [1:0] T_171;
  wire [1:0] T_172;
  wire [3:0] T_173;
  wire [3:0] T_174;
  wire  T_175;
  wire  T_176;
  wire  T_178;
  wire  T_179;
  wire  T_180;
  wire  T_181;
  wire  T_182;
  wire [31:0] T_183;
  wire  T_185;
  wire  T_186;
  wire  T_187;
  wire  T_188;
  wire  T_189;
  wire  T_190;
  wire [1:0] T_191;
  wire [1:0] T_192;
  wire [3:0] T_193;
  wire [31:0] GEN_6;
  wire [31:0] T_194;
  wire [31:0] T_195;
  wire [31:0] T_206;
  wire  T_207;
  wire  T_208;
  wire  T_209;
  wire  T_211;
  wire  T_242;
  wire  T_244;
  wire  T_246;
  wire  T_248;
  wire [31:0] T_249;
  wire [31:0] T_260;
  wire  T_273;
  wire  T_274;
  wire  T_275;
  wire  T_277;
  wire  T_278;
  wire  T_280;
  wire  GEN_0;
  wire  GEN_1;
  wire  T_281;
  wire  GEN_2;
  wire  GEN_3;
  wire  T_284;
  wire  GEN_4;
  wire  GEN_5;
  assign io_xcpt_if = GEN_4;
  assign io_xcpt_ld = GEN_0;
  assign io_xcpt_st = GEN_2;
  assign io_debug_if = GEN_5;
  assign io_debug_ld = GEN_1;
  assign io_debug_st = GEN_3;
  assign T_170 = io_status_debug == 1'h0;
  assign T_171 = {io_bp_0_control_s,io_bp_0_control_u};
  assign T_172 = {io_bp_0_control_m,io_bp_0_control_h};
  assign T_173 = {T_172,T_171};
  assign T_174 = T_173 >> io_status_prv;
  assign T_175 = T_174[0];
  assign T_176 = T_170 & T_175;
  assign T_178 = T_176 & io_bp_0_control_r;
  assign T_179 = io_bp_0_control_tmatch[1];
  assign T_180 = io_ea >= io_bp_0_address;
  assign T_181 = io_bp_0_control_tmatch[0];
  assign T_182 = T_180 ^ T_181;
  assign T_183 = ~ io_ea;
  assign T_185 = io_bp_0_address[0];
  assign T_186 = T_181 & T_185;
  assign T_187 = io_bp_0_address[1];
  assign T_188 = T_186 & T_187;
  assign T_189 = io_bp_0_address[2];
  assign T_190 = T_188 & T_189;
  assign T_191 = {T_186,T_181};
  assign T_192 = {T_190,T_188};
  assign T_193 = {T_192,T_191};
  assign GEN_6 = {{28'd0}, T_193};
  assign T_194 = T_183 | GEN_6;
  assign T_195 = ~ io_bp_0_address;
  assign T_206 = T_195 | GEN_6;
  assign T_207 = T_194 == T_206;
  assign T_208 = T_179 ? T_182 : T_207;
  assign T_209 = T_178 & T_208;
  assign T_211 = T_176 & io_bp_0_control_w;
  assign T_242 = T_211 & T_208;
  assign T_244 = T_176 & io_bp_0_control_x;
  assign T_246 = io_pc >= io_bp_0_address;
  assign T_248 = T_246 ^ T_181;
  assign T_249 = ~ io_pc;
  assign T_260 = T_249 | GEN_6;
  assign T_273 = T_260 == T_206;
  assign T_274 = T_179 ? T_248 : T_273;
  assign T_275 = T_244 & T_274;
  assign T_277 = io_bp_0_control_chain == 1'h0;
  assign T_278 = T_277 & T_209;
  assign T_280 = io_bp_0_control_action == 1'h0;
  assign GEN_0 = T_278 ? T_280 : 1'h0;
  assign GEN_1 = T_278 ? io_bp_0_control_action : 1'h0;
  assign T_281 = T_277 & T_242;
  assign GEN_2 = T_281 ? T_280 : 1'h0;
  assign GEN_3 = T_281 ? io_bp_0_control_action : 1'h0;
  assign T_284 = T_277 & T_275;
  assign GEN_4 = T_284 ? T_280 : 1'h0;
  assign GEN_5 = T_284 ? io_bp_0_control_action : 1'h0;
endmodule