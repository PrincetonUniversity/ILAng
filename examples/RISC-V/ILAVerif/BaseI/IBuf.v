module IBuf(
  input   clock,
  input   reset,
  output  io_imem_ready,
  input   io_imem_valid,
  input   io_imem_bits_btb_valid,
  input   io_imem_bits_btb_bits_taken,
  input  [1:0] io_imem_bits_btb_bits_mask,
  input   io_imem_bits_btb_bits_bridx,
  input  [31:0] io_imem_bits_btb_bits_target,
  input   io_imem_bits_btb_bits_entry,
  input   io_imem_bits_btb_bits_bht_history,
  input  [1:0] io_imem_bits_btb_bits_bht_value,
  input  [31:0] io_imem_bits_pc,
  input  [31:0] io_imem_bits_data,
  input  [1:0] io_imem_bits_mask,
  input   io_imem_bits_xcpt_if,
  input   io_imem_bits_replay,
  input   io_kill,
  output [31:0] io_pc,
  output  io_btb_resp_taken,
  output [1:0] io_btb_resp_mask,
  output  io_btb_resp_bridx,
  output [31:0] io_btb_resp_target,
  output  io_btb_resp_entry,
  output  io_btb_resp_bht_history,
  output [1:0] io_btb_resp_bht_value,
  input   io_inst_0_ready,
  output  io_inst_0_valid,
  output  io_inst_0_bits_pf0,
  output  io_inst_0_bits_pf1,
  output  io_inst_0_bits_replay,
  output  io_inst_0_bits_btb_hit,
  output  io_inst_0_bits_rvc,
  output [31:0] io_inst_0_bits_inst_bits,
  output [4:0] io_inst_0_bits_inst_rd,
  output [4:0] io_inst_0_bits_inst_rs1,
  output [4:0] io_inst_0_bits_inst_rs2,
  output [4:0] io_inst_0_bits_inst_rs3
);
  reg  nBufValid;
  reg [31:0] GEN_33;
  reg  buf_btb_valid;
  reg [31:0] GEN_34;
  reg  buf_btb_bits_taken;
  reg [31:0] GEN_35;
  reg [1:0] buf_btb_bits_mask;
  reg [31:0] GEN_36;
  reg  buf_btb_bits_bridx;
  reg [31:0] GEN_37;
  reg [31:0] buf_btb_bits_target;
  reg [31:0] GEN_38;
  reg  buf_btb_bits_entry;
  reg [31:0] GEN_43;
  reg  buf_btb_bits_bht_history;
  reg [31:0] GEN_44;
  reg [1:0] buf_btb_bits_bht_value;
  reg [31:0] GEN_48;
  reg [31:0] buf_pc;
  reg [31:0] GEN_51;
  reg [31:0] buf_data;
  reg [31:0] GEN_52;
  reg [1:0] buf_mask;
  reg [31:0] GEN_53;
  reg  buf_xcpt_if;
  reg [31:0] GEN_54;
  reg  buf_replay;
  reg [31:0] GEN_55;
  reg  ibufBTBHit;
  reg [31:0] GEN_56;
  reg  ibufBTBResp_taken;
  reg [31:0] GEN_57;
  reg [1:0] ibufBTBResp_mask;
  reg [31:0] GEN_58;
  reg  ibufBTBResp_bridx;
  reg [31:0] GEN_59;
  reg [31:0] ibufBTBResp_target;
  reg [31:0] GEN_60;
  reg  ibufBTBResp_entry;
  reg [31:0] GEN_61;
  reg  ibufBTBResp_bht_history;
  reg [31:0] GEN_62;
  reg [1:0] ibufBTBResp_bht_value;
  reg [31:0] GEN_63;
  wire  pcWordBits;
  wire [1:0] nReady;
  wire  T_368;
  wire [1:0] T_370;
  wire [1:0] T_372;
  wire [1:0] GEN_31;
  wire [2:0] T_373;
  wire [1:0] nIC;
  wire [1:0] GEN_32;
  wire [2:0] T_374;
  wire [1:0] nICReady;
  wire [1:0] T_376;
  wire [2:0] T_377;
  wire [1:0] nValid;
  wire  T_378;
  wire  T_379;
  wire [2:0] T_381;
  wire [1:0] T_382;
  wire  T_383;
  wire  T_384;
  wire  T_385;
  wire [2:0] T_388;
  wire [1:0] T_389;
  wire [1:0] T_390;
  wire  T_392;
  wire  T_393;
  wire  T_394;
  wire  T_399;
  wire [2:0] T_400;
  wire [1:0] T_401;
  wire [15:0] T_404;
  wire [31:0] T_405;
  wire [63:0] T_406;
  wire [5:0] GEN_39;
  wire [5:0] T_407;
  wire [63:0] T_408;
  wire [15:0] T_409;
  wire [31:0] T_411;
  wire [2:0] GEN_40;
  wire [2:0] T_412;
  wire [31:0] GEN_41;
  wire [32:0] T_413;
  wire [31:0] T_414;
  wire [31:0] T_415;
  wire [31:0] T_416;
  wire [1:0] GEN_42;
  wire [2:0] T_417;
  wire [1:0] T_418;
  wire  GEN_0;
  wire [1:0] GEN_1;
  wire [1:0] GEN_2;
  wire [31:0] GEN_3;
  wire  GEN_4;
  wire  GEN_5;
  wire [1:0] GEN_6;
  wire [1:0] GEN_7;
  wire  GEN_8;
  wire  GEN_9;
  wire [1:0] GEN_10;
  wire  GEN_11;
  wire [31:0] GEN_12;
  wire  GEN_13;
  wire  GEN_14;
  wire [1:0] GEN_15;
  wire [31:0] GEN_16;
  wire [31:0] GEN_17;
  wire [1:0] GEN_18;
  wire  GEN_19;
  wire  GEN_20;
  wire  GEN_21;
  wire  GEN_22;
  wire [1:0] GEN_23;
  wire [1:0] GEN_24;
  wire [31:0] GEN_25;
  wire  GEN_26;
  wire  GEN_27;
  wire [1:0] GEN_28;
  wire [1:0] GEN_29;
  wire [2:0] T_421;
  wire [1:0] T_422;
  wire [2:0] T_423;
  wire [1:0] T_424;
  wire [15:0] T_425;
  wire [31:0] T_426;
  wire [63:0] T_427;
  wire [15:0] T_428;
  wire [31:0] T_429;
  wire [63:0] T_430;
  wire [127:0] T_431;
  wire [5:0] GEN_45;
  wire [5:0] T_432;
  wire [190:0] GEN_46;
  wire [190:0] T_433;
  wire [31:0] icData;
  wire [4:0] GEN_47;
  wire [4:0] T_436;
  wire [62:0] T_437;
  wire [31:0] icMask;
  wire [31:0] T_438;
  wire [31:0] T_439;
  wire [31:0] T_440;
  wire [31:0] inst;
  wire [3:0] T_442;
  wire [4:0] T_444;
  wire [3:0] T_445;
  wire [1:0] valid;
  wire [1:0] T_447;
  wire [2:0] T_449;
  wire [1:0] bufMask;
  wire [1:0] T_451;
  wire [1:0] T_452;
  wire [1:0] T_454;
  wire [1:0] T_455;
  wire [1:0] xcpt_if;
  wire [1:0] T_457;
  wire [1:0] T_460;
  wire [1:0] T_461;
  wire [1:0] ic_replay;
  wire [1:0] T_463;
  wire [1:0] ibufBTBHitMask;
  wire [1:0] T_465;
  wire [2:0] T_466;
  wire [1:0] T_467;
  wire [3:0] T_469;
  wire [3:0] icBTBHitMask;
  wire [1:0] T_471;
  wire [3:0] GEN_49;
  wire [3:0] T_473;
  wire [3:0] GEN_50;
  wire [3:0] btbHitMask;
  wire  T_476;
  wire  T_477_taken;
  wire [1:0] T_477_mask;
  wire  T_477_bridx;
  wire [31:0] T_477_target;
  wire  T_477_entry;
  wire  T_477_bht_history;
  wire [1:0] T_477_bht_value;
  wire  T_487;
  wire [31:0] T_488;
  wire  RVCExpander_1_clock;
  wire  RVCExpander_1_reset;
  wire [31:0] RVCExpander_1_io_in;
  wire [31:0] RVCExpander_1_io_out_bits;
  wire [4:0] RVCExpander_1_io_out_rd;
  wire [4:0] RVCExpander_1_io_out_rs1;
  wire [4:0] RVCExpander_1_io_out_rs2;
  wire [4:0] RVCExpander_1_io_out_rs3;
  wire  RVCExpander_1_io_rvc;
  wire [1:0] T_490;
  wire  T_491;
  wire  T_493;
  wire [3:0] T_494;
  wire  T_495;
  wire [1:0] T_497;
  wire  T_498;
  wire [1:0] T_499;
  wire  T_500;
  wire  T_501;
  wire  T_502;
  wire  T_503;
  wire [1:0] T_504;
  wire  T_505;
  wire [1:0] T_509;
  wire  T_510;
  wire  T_511;
  wire [1:0] T_515;
  wire  T_516;
  wire  T_517;
  wire  T_518;
  wire  T_519;
  wire [1:0] T_520;
  wire  T_521;
  wire  T_529;
  wire [3:0] T_537;
  wire  T_538;
  wire  T_539;
  wire  T_540;
  wire  T_541;
  wire [2:0] T_546;
  wire [1:0] T_547;
  wire [1:0] T_548;
  wire [1:0] GEN_30;
  RVCExpander RVCExpander_1 (
    .clock(RVCExpander_1_clock),
    .reset(RVCExpander_1_reset),
    .io_in(RVCExpander_1_io_in),
    .io_out_bits(RVCExpander_1_io_out_bits),
    .io_out_rd(RVCExpander_1_io_out_rd),
    .io_out_rs1(RVCExpander_1_io_out_rs1),
    .io_out_rs2(RVCExpander_1_io_out_rs2),
    .io_out_rs3(RVCExpander_1_io_out_rs3),
    .io_rvc(RVCExpander_1_io_rvc)
  );
  assign io_imem_ready = T_385;
  assign io_pc = T_488;
  assign io_btb_resp_taken = T_477_taken;
  assign io_btb_resp_mask = T_477_mask;
  assign io_btb_resp_bridx = T_477_bridx;
  assign io_btb_resp_target = T_477_target;
  assign io_btb_resp_entry = T_477_entry;
  assign io_btb_resp_bht_history = T_477_bht_history;
  assign io_btb_resp_bht_value = T_477_bht_value;
  assign io_inst_0_valid = T_519;
  assign io_inst_0_bits_pf0 = T_521;
  assign io_inst_0_bits_pf1 = T_529;
  assign io_inst_0_bits_replay = T_503;
  assign io_inst_0_bits_btb_hit = T_540;
  assign io_inst_0_bits_rvc = RVCExpander_1_io_rvc;
  assign io_inst_0_bits_inst_bits = RVCExpander_1_io_out_bits;
  assign io_inst_0_bits_inst_rd = RVCExpander_1_io_out_rd;
  assign io_inst_0_bits_inst_rs1 = RVCExpander_1_io_out_rs1;
  assign io_inst_0_bits_inst_rs2 = RVCExpander_1_io_out_rs2;
  assign io_inst_0_bits_inst_rs3 = RVCExpander_1_io_out_rs3;
  assign pcWordBits = io_imem_bits_pc[1];
  assign nReady = GEN_30;
  assign T_368 = io_imem_bits_btb_valid & io_imem_bits_btb_bits_taken;
  assign T_370 = io_imem_bits_btb_bits_bridx + 1'h1;
  assign T_372 = T_368 ? T_370 : 2'h2;
  assign GEN_31 = {{1'd0}, pcWordBits};
  assign T_373 = T_372 - GEN_31;
  assign nIC = T_373[1:0];
  assign GEN_32 = {{1'd0}, nBufValid};
  assign T_374 = nReady - GEN_32;
  assign nICReady = T_374[1:0];
  assign T_376 = io_imem_valid ? nIC : 2'h0;
  assign T_377 = T_376 + GEN_32;
  assign nValid = T_377[1:0];
  assign T_378 = nReady >= GEN_32;
  assign T_379 = nICReady >= nIC;
  assign T_381 = nIC - nICReady;
  assign T_382 = T_381[1:0];
  assign T_383 = 2'h1 >= T_382;
  assign T_384 = T_379 | T_383;
  assign T_385 = T_378 & T_384;
  assign T_388 = GEN_32 - nReady;
  assign T_389 = T_388[1:0];
  assign T_390 = T_378 ? 2'h0 : T_389;
  assign T_392 = io_imem_valid & T_378;
  assign T_393 = nICReady < nIC;
  assign T_394 = T_392 & T_393;
  assign T_399 = T_394 & T_383;
  assign T_400 = GEN_31 + nICReady;
  assign T_401 = T_400[1:0];
  assign T_404 = io_imem_bits_data[31:16];
  assign T_405 = {T_404,T_404};
  assign T_406 = {T_405,io_imem_bits_data};
  assign GEN_39 = {{4'd0}, T_401};
  assign T_407 = GEN_39 << 4;
  assign T_408 = T_406 >> T_407;
  assign T_409 = T_408[15:0];
  assign T_411 = io_imem_bits_pc & 32'hfffffffc;
  assign GEN_40 = {{1'd0}, nICReady};
  assign T_412 = GEN_40 << 1;
  assign GEN_41 = {{29'd0}, T_412};
  assign T_413 = io_imem_bits_pc + GEN_41;
  assign T_414 = T_413[31:0];
  assign T_415 = T_414 & 32'h3;
  assign T_416 = T_411 | T_415;
  assign GEN_42 = {{1'd0}, io_imem_bits_btb_bits_bridx};
  assign T_417 = GEN_42 + nICReady;
  assign T_418 = T_417[1:0];
  assign GEN_0 = io_imem_bits_btb_valid ? io_imem_bits_btb_bits_taken : ibufBTBResp_taken;
  assign GEN_1 = io_imem_bits_btb_valid ? io_imem_bits_btb_bits_mask : ibufBTBResp_mask;
  assign GEN_2 = io_imem_bits_btb_valid ? T_418 : {{1'd0}, ibufBTBResp_bridx};
  assign GEN_3 = io_imem_bits_btb_valid ? io_imem_bits_btb_bits_target : ibufBTBResp_target;
  assign GEN_4 = io_imem_bits_btb_valid ? io_imem_bits_btb_bits_entry : ibufBTBResp_entry;
  assign GEN_5 = io_imem_bits_btb_valid ? io_imem_bits_btb_bits_bht_history : ibufBTBResp_bht_history;
  assign GEN_6 = io_imem_bits_btb_valid ? io_imem_bits_btb_bits_bht_value : ibufBTBResp_bht_value;
  assign GEN_7 = T_399 ? T_382 : T_390;
  assign GEN_8 = T_399 ? io_imem_bits_btb_valid : buf_btb_valid;
  assign GEN_9 = T_399 ? io_imem_bits_btb_bits_taken : buf_btb_bits_taken;
  assign GEN_10 = T_399 ? io_imem_bits_btb_bits_mask : buf_btb_bits_mask;
  assign GEN_11 = T_399 ? io_imem_bits_btb_bits_bridx : buf_btb_bits_bridx;
  assign GEN_12 = T_399 ? io_imem_bits_btb_bits_target : buf_btb_bits_target;
  assign GEN_13 = T_399 ? io_imem_bits_btb_bits_entry : buf_btb_bits_entry;
  assign GEN_14 = T_399 ? io_imem_bits_btb_bits_bht_history : buf_btb_bits_bht_history;
  assign GEN_15 = T_399 ? io_imem_bits_btb_bits_bht_value : buf_btb_bits_bht_value;
  assign GEN_16 = T_399 ? T_416 : buf_pc;
  assign GEN_17 = T_399 ? {{16'd0}, T_409} : buf_data;
  assign GEN_18 = T_399 ? io_imem_bits_mask : buf_mask;
  assign GEN_19 = T_399 ? io_imem_bits_xcpt_if : buf_xcpt_if;
  assign GEN_20 = T_399 ? io_imem_bits_replay : buf_replay;
  assign GEN_21 = T_399 ? io_imem_bits_btb_valid : ibufBTBHit;
  assign GEN_22 = T_399 ? GEN_0 : ibufBTBResp_taken;
  assign GEN_23 = T_399 ? GEN_1 : ibufBTBResp_mask;
  assign GEN_24 = T_399 ? GEN_2 : {{1'd0}, ibufBTBResp_bridx};
  assign GEN_25 = T_399 ? GEN_3 : ibufBTBResp_target;
  assign GEN_26 = T_399 ? GEN_4 : ibufBTBResp_entry;
  assign GEN_27 = T_399 ? GEN_5 : ibufBTBResp_bht_history;
  assign GEN_28 = T_399 ? GEN_6 : ibufBTBResp_bht_value;
  assign GEN_29 = io_kill ? 2'h0 : GEN_7;
  assign T_421 = 2'h2 + GEN_32;
  assign T_422 = T_421[1:0];
  assign T_423 = T_422 - GEN_31;
  assign T_424 = T_423[1:0];
  assign T_425 = io_imem_bits_data[15:0];
  assign T_426 = {T_425,T_425};
  assign T_427 = {io_imem_bits_data,T_426};
  assign T_428 = T_427[63:48];
  assign T_429 = {T_428,T_428};
  assign T_430 = {T_429,T_429};
  assign T_431 = {T_430,T_427};
  assign GEN_45 = {{4'd0}, T_424};
  assign T_432 = GEN_45 << 4;
  assign GEN_46 = {{63'd0}, T_431};
  assign T_433 = GEN_46 << T_432;
  assign icData = T_433[95:64];
  assign GEN_47 = {{4'd0}, nBufValid};
  assign T_436 = GEN_47 << 4;
  assign T_437 = 63'hffffffff << T_436;
  assign icMask = T_437[31:0];
  assign T_438 = icData & icMask;
  assign T_439 = ~ icMask;
  assign T_440 = buf_data & T_439;
  assign inst = T_438 | T_440;
  assign T_442 = 4'h1 << nValid;
  assign T_444 = T_442 - 4'h1;
  assign T_445 = T_444[3:0];
  assign valid = T_445[1:0];
  assign T_447 = 2'h1 << nBufValid;
  assign T_449 = T_447 - 2'h1;
  assign bufMask = T_449[1:0];
  assign T_451 = buf_xcpt_if ? bufMask : 2'h0;
  assign T_452 = ~ bufMask;
  assign T_454 = io_imem_bits_xcpt_if ? T_452 : 2'h0;
  assign T_455 = T_451 | T_454;
  assign xcpt_if = valid & T_455;
  assign T_457 = buf_replay ? bufMask : 2'h0;
  assign T_460 = io_imem_bits_replay ? T_452 : 2'h0;
  assign T_461 = T_457 | T_460;
  assign ic_replay = valid & T_461;
  assign T_463 = 2'h1 << ibufBTBResp_bridx;
  assign ibufBTBHitMask = ibufBTBHit ? T_463 : 2'h0;
  assign T_465 = io_imem_bits_btb_bits_bridx + nBufValid;
  assign T_466 = T_465 - GEN_31;
  assign T_467 = T_466[1:0];
  assign T_469 = 4'h1 << T_467;
  assign icBTBHitMask = io_imem_bits_btb_valid ? T_469 : 4'h0;
  assign T_471 = ibufBTBHitMask & bufMask;
  assign GEN_49 = {{2'd0}, T_452};
  assign T_473 = icBTBHitMask & GEN_49;
  assign GEN_50 = {{2'd0}, T_471};
  assign btbHitMask = GEN_50 | T_473;
  assign T_476 = T_471 != 2'h0;
  assign T_477_taken = T_476 ? ibufBTBResp_taken : io_imem_bits_btb_bits_taken;
  assign T_477_mask = T_476 ? ibufBTBResp_mask : io_imem_bits_btb_bits_mask;
  assign T_477_bridx = T_476 ? ibufBTBResp_bridx : io_imem_bits_btb_bits_bridx;
  assign T_477_target = T_476 ? ibufBTBResp_target : io_imem_bits_btb_bits_target;
  assign T_477_entry = T_476 ? ibufBTBResp_entry : io_imem_bits_btb_bits_entry;
  assign T_477_bht_history = T_476 ? ibufBTBResp_bht_history : io_imem_bits_btb_bits_bht_history;
  assign T_477_bht_value = T_476 ? ibufBTBResp_bht_value : io_imem_bits_btb_bits_bht_value;
  assign T_487 = nBufValid > 1'h0;
  assign T_488 = T_487 ? buf_pc : io_imem_bits_pc;
  assign RVCExpander_1_clock = clock;
  assign RVCExpander_1_reset = reset;
  assign RVCExpander_1_io_in = inst;
  assign T_490 = ic_replay >> 1'h0;
  assign T_491 = T_490[0];
  assign T_493 = RVCExpander_1_io_rvc == 1'h0;
  assign T_494 = btbHitMask >> 1'h0;
  assign T_495 = T_494[0];
  assign T_497 = 1'h0 + 1'h1;
  assign T_498 = T_497[0:0];
  assign T_499 = ic_replay >> T_498;
  assign T_500 = T_499[0];
  assign T_501 = T_495 | T_500;
  assign T_502 = T_493 & T_501;
  assign T_503 = T_491 | T_502;
  assign T_504 = valid >> 1'h0;
  assign T_505 = T_504[0];
  assign T_509 = valid >> T_498;
  assign T_510 = T_509[0];
  assign T_511 = RVCExpander_1_io_rvc | T_510;
  assign T_515 = xcpt_if >> T_498;
  assign T_516 = T_515[0];
  assign T_517 = T_511 | T_516;
  assign T_518 = T_517 | T_503;
  assign T_519 = T_505 & T_518;
  assign T_520 = xcpt_if >> 1'h0;
  assign T_521 = T_520[0];
  assign T_529 = T_493 & T_516;
  assign T_537 = btbHitMask >> T_498;
  assign T_538 = T_537[0];
  assign T_539 = T_493 & T_538;
  assign T_540 = T_495 | T_539;
  assign T_541 = io_inst_0_ready & io_inst_0_valid;
  assign T_546 = 2'h0 + 2'h2;
  assign T_547 = T_546[1:0];
  assign T_548 = RVCExpander_1_io_rvc ? {{1'd0}, T_498} : T_547;
  assign GEN_30 = T_541 ? T_548 : 2'h0;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_33 = {1{$random}};
  nBufValid = GEN_33[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_34 = {1{$random}};
  buf_btb_valid = GEN_34[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_35 = {1{$random}};
  buf_btb_bits_taken = GEN_35[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_36 = {1{$random}};
  buf_btb_bits_mask = GEN_36[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_37 = {1{$random}};
  buf_btb_bits_bridx = GEN_37[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_38 = {1{$random}};
  buf_btb_bits_target = GEN_38[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_43 = {1{$random}};
  buf_btb_bits_entry = GEN_43[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_44 = {1{$random}};
  buf_btb_bits_bht_history = GEN_44[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_48 = {1{$random}};
  buf_btb_bits_bht_value = GEN_48[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_51 = {1{$random}};
  buf_pc = GEN_51[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_52 = {1{$random}};
  buf_data = GEN_52[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_53 = {1{$random}};
  buf_mask = GEN_53[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_54 = {1{$random}};
  buf_xcpt_if = GEN_54[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_55 = {1{$random}};
  buf_replay = GEN_55[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_56 = {1{$random}};
  ibufBTBHit = GEN_56[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_57 = {1{$random}};
  ibufBTBResp_taken = GEN_57[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_58 = {1{$random}};
  ibufBTBResp_mask = GEN_58[1:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_59 = {1{$random}};
  ibufBTBResp_bridx = GEN_59[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_60 = {1{$random}};
  ibufBTBResp_target = GEN_60[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_61 = {1{$random}};
  ibufBTBResp_entry = GEN_61[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_62 = {1{$random}};
  ibufBTBResp_bht_history = GEN_62[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_63 = {1{$random}};
  ibufBTBResp_bht_value = GEN_63[1:0];
  `endif
  end
`endif
  always @(posedge clock) begin
    if (reset) begin
      nBufValid <= 1'h0;
    end else begin
      nBufValid <= GEN_29[0];
    end
    if (T_399) begin
      buf_btb_valid <= io_imem_bits_btb_valid;
    end
    if (T_399) begin
      buf_btb_bits_taken <= io_imem_bits_btb_bits_taken;
    end
    if (T_399) begin
      buf_btb_bits_mask <= io_imem_bits_btb_bits_mask;
    end
    if (T_399) begin
      buf_btb_bits_bridx <= io_imem_bits_btb_bits_bridx;
    end
    if (T_399) begin
      buf_btb_bits_target <= io_imem_bits_btb_bits_target;
    end
    if (T_399) begin
      buf_btb_bits_entry <= io_imem_bits_btb_bits_entry;
    end
    if (T_399) begin
      buf_btb_bits_bht_history <= io_imem_bits_btb_bits_bht_history;
    end
    if (T_399) begin
      buf_btb_bits_bht_value <= io_imem_bits_btb_bits_bht_value;
    end
    if (T_399) begin
      buf_pc <= T_416;
    end
    if (T_399) begin
      buf_data <= {{16'd0}, T_409};
    end
    if (T_399) begin
      buf_mask <= io_imem_bits_mask;
    end
    if (T_399) begin
      buf_xcpt_if <= io_imem_bits_xcpt_if;
    end
    if (T_399) begin
      buf_replay <= io_imem_bits_replay;
    end
    if (T_399) begin
      ibufBTBHit <= io_imem_bits_btb_valid;
    end
    if (T_399) begin
      if (io_imem_bits_btb_valid) begin
        ibufBTBResp_taken <= io_imem_bits_btb_bits_taken;
      end
    end
    if (T_399) begin
      if (io_imem_bits_btb_valid) begin
        ibufBTBResp_mask <= io_imem_bits_btb_bits_mask;
      end
    end
    ibufBTBResp_bridx <= GEN_24[0];
    if (T_399) begin
      if (io_imem_bits_btb_valid) begin
        ibufBTBResp_target <= io_imem_bits_btb_bits_target;
      end
    end
    if (T_399) begin
      if (io_imem_bits_btb_valid) begin
        ibufBTBResp_entry <= io_imem_bits_btb_bits_entry;
      end
    end
    if (T_399) begin
      if (io_imem_bits_btb_valid) begin
        ibufBTBResp_bht_history <= io_imem_bits_btb_bits_bht_history;
      end
    end
    if (T_399) begin
      if (io_imem_bits_btb_valid) begin
        ibufBTBResp_bht_value <= io_imem_bits_btb_bits_bht_value;
      end
    end
  end
endmodule