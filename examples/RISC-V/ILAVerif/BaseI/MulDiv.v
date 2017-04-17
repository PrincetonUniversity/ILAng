module MulDiv(
  input   clock,
  input   reset,
  output  io_req_ready,
  input   io_req_valid,
  input  [3:0] io_req_bits_fn,
  input   io_req_bits_dw,
  input  [31:0] io_req_bits_in1,
  input  [31:0] io_req_bits_in2,
  input  [4:0] io_req_bits_tag,
  input   io_kill,
  input   io_resp_ready,
  output  io_resp_valid,
  output [31:0] io_resp_bits_data,
  output [4:0] io_resp_bits_tag
);
  reg [2:0] state;
  reg [31:0] GEN_14;
  reg [3:0] req_fn;
  reg [31:0] GEN_15;
  reg  req_dw;
  reg [31:0] GEN_36;
  reg [31:0] req_in1;
  reg [31:0] GEN_37;
  reg [31:0] req_in2;
  reg [31:0] GEN_38;
  reg [4:0] req_tag;
  reg [31:0] GEN_39;
  reg [5:0] count;
  reg [31:0] GEN_40;
  reg  neg_out;
  reg [31:0] GEN_41;
  reg  isMul;
  reg [31:0] GEN_42;
  reg  isHi;
  reg [31:0] GEN_43;
  reg [32:0] divisor;
  reg [63:0] GEN_44;
  reg [65:0] remainder;
  reg [95:0] GEN_45;
  wire [3:0] T_71;
  wire  T_73;
  wire [3:0] T_75;
  wire  T_77;
  wire  T_80;
  wire [3:0] T_82;
  wire  T_84;
  wire [3:0] T_86;
  wire  T_88;
  wire  T_91;
  wire  T_92;
  wire [3:0] T_94;
  wire  T_96;
  wire [3:0] T_98;
  wire  T_100;
  wire  T_103;
  wire  T_104;
  wire  T_112;
  wire  lhs_sign;
  wire [15:0] T_118;
  wire [15:0] T_120;
  wire [31:0] lhs_in;
  wire  T_125;
  wire  rhs_sign;
  wire [15:0] T_131;
  wire [15:0] T_133;
  wire [31:0] rhs_in;
  wire [32:0] T_134;
  wire [33:0] T_136;
  wire [32:0] subtractor;
  wire  less;
  wire [31:0] T_137;
  wire [32:0] T_139;
  wire [31:0] negated_remainder;
  wire  T_140;
  wire  T_141;
  wire  T_142;
  wire [65:0] GEN_0;
  wire  T_143;
  wire  T_144;
  wire [32:0] GEN_1;
  wire [65:0] GEN_2;
  wire [32:0] GEN_3;
  wire [2:0] GEN_4;
  wire  T_145;
  wire [65:0] GEN_5;
  wire [2:0] GEN_6;
  wire  T_146;
  wire [31:0] T_147;
  wire [2:0] T_148;
  wire [65:0] GEN_7;
  wire [2:0] GEN_8;
  wire  T_149;
  wire  T_150;
  wire [32:0] T_151;
  wire [64:0] T_153;
  wire [31:0] T_154;
  wire [32:0] T_155;
  wire [32:0] T_156;
  wire [32:0] T_157;
  wire  T_158;
  wire [32:0] GEN_34;
  wire [33:0] T_159;
  wire [33:0] GEN_35;
  wire [34:0] T_160;
  wire [33:0] T_161;
  wire [33:0] T_162;
  wire [30:0] T_163;
  wire [33:0] T_164;
  wire [64:0] T_165;
  wire  T_180;
  wire [32:0] T_194;
  wire [31:0] T_196;
  wire [64:0] T_197;
  wire [32:0] T_198;
  wire [31:0] T_200;
  wire [33:0] T_201;
  wire [65:0] T_202;
  wire [6:0] T_204;
  wire [5:0] T_205;
  wire  T_207;
  wire [2:0] T_209;
  wire [2:0] GEN_9;
  wire [65:0] GEN_10;
  wire [5:0] GEN_11;
  wire [2:0] GEN_12;
  wire  T_212;
  wire  T_213;
  wire  T_215;
  wire [2:0] T_217;
  wire [2:0] GEN_13;
  wire [31:0] T_221;
  wire [31:0] T_222;
  wire [31:0] T_223;
  wire  T_226;
  wire [63:0] T_227;
  wire [64:0] T_228;
  wire  T_450;
  wire  T_467;
  wire  T_470;
  wire  GEN_16;
  wire [2:0] GEN_17;
  wire [5:0] GEN_18;
  wire [65:0] GEN_19;
  wire  GEN_20;
  wire  T_472;
  wire  T_473;
  wire [2:0] GEN_21;
  wire  T_474;
  wire  T_476;
  wire  T_477;
  wire  T_478;
  wire [2:0] T_479;
  wire  T_483;
  wire  T_484;
  wire  T_485;
  wire [32:0] T_486;
  wire [2:0] GEN_22;
  wire  GEN_23;
  wire  GEN_24;
  wire [5:0] GEN_25;
  wire  GEN_26;
  wire [32:0] GEN_27;
  wire [65:0] GEN_28;
  wire [3:0] GEN_29;
  wire  GEN_30;
  wire [31:0] GEN_31;
  wire [31:0] GEN_32;
  wire [4:0] GEN_33;
  wire  T_499;
  wire  T_500;
  assign io_req_ready = T_500;
  assign io_resp_valid = T_499;
  assign io_resp_bits_data = T_137;
  assign io_resp_bits_tag = req_tag;
  assign T_71 = io_req_bits_fn & 4'h4;
  assign T_73 = T_71 == 4'h0;
  assign T_75 = io_req_bits_fn & 4'h8;
  assign T_77 = T_75 == 4'h8;
  assign T_80 = T_73 | T_77;
  assign T_82 = io_req_bits_fn & 4'h5;
  assign T_84 = T_82 == 4'h1;
  assign T_86 = io_req_bits_fn & 4'h2;
  assign T_88 = T_86 == 4'h2;
  assign T_91 = T_84 | T_88;
  assign T_92 = T_91 | T_77;
  assign T_94 = io_req_bits_fn & 4'h9;
  assign T_96 = T_94 == 4'h0;
  assign T_98 = io_req_bits_fn & 4'h3;
  assign T_100 = T_98 == 4'h0;
  assign T_103 = T_96 | T_73;
  assign T_104 = T_103 | T_100;
  assign T_112 = io_req_bits_in1[31];
  assign lhs_sign = T_104 & T_112;
  assign T_118 = io_req_bits_in1[31:16];
  assign T_120 = io_req_bits_in1[15:0];
  assign lhs_in = {T_118,T_120};
  assign T_125 = io_req_bits_in2[31];
  assign rhs_sign = T_103 & T_125;
  assign T_131 = io_req_bits_in2[31:16];
  assign T_133 = io_req_bits_in2[15:0];
  assign rhs_in = {T_131,T_133};
  assign T_134 = remainder[64:32];
  assign T_136 = T_134 - divisor;
  assign subtractor = T_136[32:0];
  assign less = subtractor[32];
  assign T_137 = remainder[31:0];
  assign T_139 = 32'h0 - T_137;
  assign negated_remainder = T_139[31:0];
  assign T_140 = state == 3'h1;
  assign T_141 = remainder[31];
  assign T_142 = T_141 | isMul;
  assign GEN_0 = T_142 ? {{34'd0}, negated_remainder} : remainder;
  assign T_143 = divisor[31];
  assign T_144 = T_143 | isMul;
  assign GEN_1 = T_144 ? subtractor : divisor;
  assign GEN_2 = T_140 ? GEN_0 : remainder;
  assign GEN_3 = T_140 ? GEN_1 : divisor;
  assign GEN_4 = T_140 ? 3'h2 : state;
  assign T_145 = state == 3'h4;
  assign GEN_5 = T_145 ? {{34'd0}, negated_remainder} : GEN_2;
  assign GEN_6 = T_145 ? 3'h5 : GEN_4;
  assign T_146 = state == 3'h3;
  assign T_147 = remainder[64:33];
  assign T_148 = neg_out ? 3'h4 : 3'h5;
  assign GEN_7 = T_146 ? {{34'd0}, T_147} : GEN_5;
  assign GEN_8 = T_146 ? T_148 : GEN_6;
  assign T_149 = state == 3'h2;
  assign T_150 = T_149 & isMul;
  assign T_151 = remainder[65:33];
  assign T_153 = {T_151,T_137};
  assign T_154 = T_153[31:0];
  assign T_155 = T_153[64:32];
  assign T_156 = $signed(T_155);
  assign T_157 = $signed(divisor);
  assign T_158 = T_154[0];
  assign GEN_34 = {{32'd0}, T_158};
  assign T_159 = $signed(T_157) * $signed({1'b0,GEN_34});
  assign GEN_35 = {{1{T_156[32]}},T_156};
  assign T_160 = $signed(T_159) + $signed(GEN_35);
  assign T_161 = T_160[33:0];
  assign T_162 = $signed(T_161);
  assign T_163 = T_154[31:1];
  assign T_164 = $unsigned(T_162);
  assign T_165 = {T_164,T_163};
  assign T_180 = isHi == 1'h0;
  assign T_194 = T_165[64:32];
  assign T_196 = T_165[31:0];
  assign T_197 = {T_194,T_196};
  assign T_198 = T_197[64:32];
  assign T_200 = T_197[31:0];
  assign T_201 = {T_198,1'h0};
  assign T_202 = {T_201,T_200};
  assign T_204 = count + 6'h1;
  assign T_205 = T_204[5:0];
  assign T_207 = count == 6'h1f;
  assign T_209 = isHi ? 3'h3 : 3'h5;
  assign GEN_9 = T_207 ? T_209 : GEN_8;
  assign GEN_10 = T_150 ? T_202 : GEN_7;
  assign GEN_11 = T_150 ? T_205 : count;
  assign GEN_12 = T_150 ? GEN_9 : GEN_8;
  assign T_212 = isMul == 1'h0;
  assign T_213 = T_149 & T_212;
  assign T_215 = count == 6'h20;
  assign T_217 = isHi ? 3'h3 : T_148;
  assign GEN_13 = T_215 ? T_217 : GEN_12;
  assign T_221 = remainder[63:32];
  assign T_222 = subtractor[31:0];
  assign T_223 = less ? T_221 : T_222;
  assign T_226 = less == 1'h0;
  assign T_227 = {T_223,T_137};
  assign T_228 = {T_227,T_226};
  assign T_450 = count == 6'h0;
  assign T_467 = T_450 & T_226;
  assign T_470 = T_467 & T_180;
  assign GEN_16 = T_470 ? 1'h0 : neg_out;
  assign GEN_17 = T_213 ? GEN_13 : GEN_12;
  assign GEN_18 = T_213 ? T_205 : GEN_11;
  assign GEN_19 = T_213 ? {{1'd0}, T_228} : GEN_10;
  assign GEN_20 = T_213 ? GEN_16 : neg_out;
  assign T_472 = io_resp_ready & io_resp_valid;
  assign T_473 = T_472 | io_kill;
  assign GEN_21 = T_473 ? 3'h0 : GEN_17;
  assign T_474 = io_req_ready & io_req_valid;
  assign T_476 = T_80 == 1'h0;
  assign T_477 = rhs_sign & T_476;
  assign T_478 = lhs_sign | T_477;
  assign T_479 = T_478 ? 3'h1 : 3'h2;
  assign T_483 = lhs_sign != rhs_sign;
  assign T_484 = T_92 ? lhs_sign : T_483;
  assign T_485 = T_476 & T_484;
  assign T_486 = {rhs_sign,rhs_in};
  assign GEN_22 = T_474 ? T_479 : GEN_21;
  assign GEN_23 = T_474 ? T_80 : isMul;
  assign GEN_24 = T_474 ? T_92 : isHi;
  assign GEN_25 = T_474 ? 6'h0 : GEN_18;
  assign GEN_26 = T_474 ? T_485 : GEN_20;
  assign GEN_27 = T_474 ? T_486 : GEN_3;
  assign GEN_28 = T_474 ? {{34'd0}, lhs_in} : GEN_19;
  assign GEN_29 = T_474 ? io_req_bits_fn : req_fn;
  assign GEN_30 = T_474 ? io_req_bits_dw : req_dw;
  assign GEN_31 = T_474 ? io_req_bits_in1 : req_in1;
  assign GEN_32 = T_474 ? io_req_bits_in2 : req_in2;
  assign GEN_33 = T_474 ? io_req_bits_tag : req_tag;
  assign T_499 = state == 3'h5;
  assign T_500 = state == 3'h0;
`ifdef RANDOMIZE
  integer initvar;
  initial begin
    `ifndef verilator
      #0.002 begin end
    `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_14 = {1{$random}};
  state = GEN_14[2:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_15 = {1{$random}};
  req_fn = GEN_15[3:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_36 = {1{$random}};
  req_dw = GEN_36[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_37 = {1{$random}};
  req_in1 = GEN_37[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_38 = {1{$random}};
  req_in2 = GEN_38[31:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_39 = {1{$random}};
  req_tag = GEN_39[4:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_40 = {1{$random}};
  count = GEN_40[5:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_41 = {1{$random}};
  neg_out = GEN_41[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_42 = {1{$random}};
  isMul = GEN_42[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_43 = {1{$random}};
  isHi = GEN_43[0:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_44 = {2{$random}};
  divisor = GEN_44[32:0];
  `endif
  `ifdef RANDOMIZE_REG_INIT
  GEN_45 = {3{$random}};
  remainder = GEN_45[65:0];
  `endif
  end
`endif
  always @(posedge clock) begin
    if (reset) begin
      state <= 3'h0;
    end else begin
      if (T_474) begin
        if (T_478) begin
          state <= 3'h1;
        end else begin
          state <= 3'h2;
        end
      end else begin
        if (T_473) begin
          state <= 3'h0;
        end else begin
          if (T_213) begin
            if (T_215) begin
              if (isHi) begin
                state <= 3'h3;
              end else begin
                if (neg_out) begin
                  state <= 3'h4;
                end else begin
                  state <= 3'h5;
                end
              end
            end else begin
              if (T_150) begin
                if (T_207) begin
                  if (isHi) begin
                    state <= 3'h3;
                  end else begin
                    state <= 3'h5;
                  end
                end else begin
                  if (T_146) begin
                    if (neg_out) begin
                      state <= 3'h4;
                    end else begin
                      state <= 3'h5;
                    end
                  end else begin
                    if (T_145) begin
                      state <= 3'h5;
                    end else begin
                      if (T_140) begin
                        state <= 3'h2;
                      end
                    end
                  end
                end
              end else begin
                if (T_146) begin
                  if (neg_out) begin
                    state <= 3'h4;
                  end else begin
                    state <= 3'h5;
                  end
                end else begin
                  if (T_145) begin
                    state <= 3'h5;
                  end else begin
                    if (T_140) begin
                      state <= 3'h2;
                    end
                  end
                end
              end
            end
          end else begin
            if (T_150) begin
              if (T_207) begin
                if (isHi) begin
                  state <= 3'h3;
                end else begin
                  state <= 3'h5;
                end
              end else begin
                if (T_146) begin
                  if (neg_out) begin
                    state <= 3'h4;
                  end else begin
                    state <= 3'h5;
                  end
                end else begin
                  if (T_145) begin
                    state <= 3'h5;
                  end else begin
                    if (T_140) begin
                      state <= 3'h2;
                    end
                  end
                end
              end
            end else begin
              if (T_146) begin
                state <= T_148;
              end else begin
                if (T_145) begin
                  state <= 3'h5;
                end else begin
                  if (T_140) begin
                    state <= 3'h2;
                  end
                end
              end
            end
          end
        end
      end
    end
    if (T_474) begin
      req_fn <= io_req_bits_fn;
    end
    if (T_474) begin
      req_dw <= io_req_bits_dw;
    end
    if (T_474) begin
      req_in1 <= io_req_bits_in1;
    end
    if (T_474) begin
      req_in2 <= io_req_bits_in2;
    end
    if (T_474) begin
      req_tag <= io_req_bits_tag;
    end
    if (T_474) begin
      count <= 6'h0;
    end else begin
      if (T_213) begin
        count <= T_205;
      end else begin
        if (T_150) begin
          count <= T_205;
        end
      end
    end
    if (T_474) begin
      neg_out <= T_485;
    end else begin
      if (T_213) begin
        if (T_470) begin
          neg_out <= 1'h0;
        end
      end
    end
    if (T_474) begin
      isMul <= T_80;
    end
    if (T_474) begin
      isHi <= T_92;
    end
    if (T_474) begin
      divisor <= T_486;
    end else begin
      if (T_140) begin
        if (T_144) begin
          divisor <= subtractor;
        end
      end
    end
    if (T_474) begin
      remainder <= {{34'd0}, lhs_in};
    end else begin
      if (T_213) begin
        remainder <= {{1'd0}, T_228};
      end else begin
        if (T_150) begin
          remainder <= T_202;
        end else begin
          if (T_146) begin
            remainder <= {{34'd0}, T_147};
          end else begin
            if (T_145) begin
              remainder <= {{34'd0}, negated_remainder};
            end else begin
              if (T_140) begin
                if (T_142) begin
                  remainder <= {{34'd0}, negated_remainder};
                end
              end
            end
          end
        end
      end
    end
  end
endmodule