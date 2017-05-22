/**
 * Copyright (c) 2014-2015, Columbia University
 *
 * @author Christian Pilato <pilato@cs.columbia.edu>
 */

module rbm_0_data(CLK, rbm_0_data_CE0, rbm_0_data_A0, rbm_0_data_D0, rbm_0_data_WE0, rbm_0_data_WEM0, rbm_0_data_CE2, rbm_0_data_A2, rbm_0_data_Q2, rbm_0_data_CE1, rbm_0_data_A1, rbm_0_data_Q1);
  input CLK;
  //buffer: data - process: load - interface: W
  input rbm_0_data_CE0;
  input [9:0] rbm_0_data_A0;
  input [7:0] rbm_0_data_D0;
  input rbm_0_data_WE0;
  input [7:0] rbm_0_data_WEM0;
  //buffer: data - process: train_rbm - interface: R
  input rbm_0_data_CE2;
  input [9:0] rbm_0_data_A2;
  output [7:0] rbm_0_data_Q2;
  //buffer: data - process: predict_rbm - interface: R
  input rbm_0_data_CE1;
  input [9:0] rbm_0_data_A1;
  output [7:0] rbm_0_data_Q1;

  //signals from banks
  wire [15:0] Q0_out [0:1];
  wire [15:0] Q1_out [0:1];

  //signals to banks
  wire mem_0_CE0;
  wire [9:0] mem_0_A0;
  wire [15:0] mem_0_D0;
  wire mem_0_WE0;
  wire [15:0] mem_0_WEM0;
  wire [15:0] mem_0_Q0;
  wire mem_0_CE1;
  wire [9:0] mem_0_A1;
  wire [15:0] mem_0_D1;
  wire mem_0_WE1;
  wire [15:0] mem_0_WEM1;
  wire [15:0] mem_0_Q1;
  wire mem_1_CE0;
  wire [9:0] mem_1_A0;
  wire [15:0] mem_1_D0;
  wire mem_1_WE0;
  wire [15:0] mem_1_WEM0;
  wire [15:0] mem_1_Q0;
  wire mem_1_CE1;
  wire [9:0] mem_1_A1;
  wire [15:0] mem_1_D1;
  wire mem_1_WE1;
  wire [15:0] mem_1_WEM1;
  wire [15:0] mem_1_Q1;

  //additional wires
  reg sel_Q1_rbm_0_data_2;
  reg sel_Q1_rbm_0_data_1;
  always@(posedge CLK)
  begin
    sel_Q1_rbm_0_data_2 <= rbm_0_data_CE2 ? 0 : ({1{1'b0}});
    sel_Q1_rbm_0_data_1 <= rbm_0_data_CE1 ? 1 : ({1{1'b0}});
  end

  //signals for bank: mem_0
  assign mem_0_CE0 = rbm_0_data_CE0 ? 1'b1 : (1'b0);
  assign mem_0_A0 = rbm_0_data_CE0 ? rbm_0_data_A0[9:0] : ({10{1'b0}});
  assign mem_0_D0 = rbm_0_data_CE0 ? {{8{1'b0}},rbm_0_data_D0[7:0]} : ({16{1'b0}});
  assign mem_0_WE0 = rbm_0_data_CE0 ? rbm_0_data_WE0 : (1'b0);
  assign mem_0_WEM0 = rbm_0_data_CE0 ? {{8{1'b0}},rbm_0_data_WEM0[7:0]} : ({16{1'b0}});
  assign mem_0_CE1 = rbm_0_data_CE2 ? 1'b1 : (1'b0);
  assign mem_0_A1 = rbm_0_data_CE2 ? rbm_0_data_A2[9:0] : ({10{1'b0}});
  assign mem_0_D1 = {16{1'b0}};
  assign mem_0_WE1 = 1'b0;
  assign mem_0_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[0] = mem_0_Q0;
  assign Q1_out[0] = mem_0_Q1;

  //signals for bank: mem_1
  assign mem_1_CE0 = rbm_0_data_CE0 ? 1'b1 : (1'b0);
  assign mem_1_A0 = rbm_0_data_CE0 ? rbm_0_data_A0[9:0] : ({10{1'b0}});
  assign mem_1_D0 = rbm_0_data_CE0 ? {{8{1'b0}},rbm_0_data_D0[7:0]} : ({16{1'b0}});
  assign mem_1_WE0 = rbm_0_data_CE0 ? rbm_0_data_WE0 : (1'b0);
  assign mem_1_WEM0 = rbm_0_data_CE0 ? {{8{1'b0}},rbm_0_data_WEM0[7:0]} : ({16{1'b0}});
  assign mem_1_CE1 = rbm_0_data_CE1 ? 1'b1 : (1'b0);
  assign mem_1_A1 = rbm_0_data_CE1 ? rbm_0_data_A1[9:0] : ({10{1'b0}});
  assign mem_1_D1 = {16{1'b0}};
  assign mem_1_WE1 = 1'b0;
  assign mem_1_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[1] = mem_1_Q0;
  assign Q1_out[1] = mem_1_Q1;

  //assigns to output ports
  assign rbm_0_data_Q2 = Q1_out[sel_Q1_rbm_0_data_2][7:0];
  assign rbm_0_data_Q1 = Q1_out[sel_Q1_rbm_0_data_1][7:0];

  //definitions of the banks
  SRAM2S_1024X16 mem_0(.CLK(CLK),
      .CE0(mem_0_CE0),
      .A0(mem_0_A0),
      .D0(mem_0_D0),
      .WE0(mem_0_WE0),
      .WEM0(mem_0_WEM0),
      .Q0(mem_0_Q0),
      .CE1(mem_0_CE1),
      .A1(mem_0_A1),
      .D1(mem_0_D1),
      .WE1(mem_0_WE1),
      .WEM1(mem_0_WEM1),
      .Q1(mem_0_Q1));

  SRAM2S_1024X16 mem_1(.CLK(CLK),
      .CE0(mem_1_CE0),
      .A0(mem_1_A0),
      .D0(mem_1_D0),
      .WE0(mem_1_WE0),
      .WEM0(mem_1_WEM0),
      .Q0(mem_1_Q0),
      .CE1(mem_1_CE1),
      .A1(mem_1_A1),
      .D1(mem_1_D1),
      .WE1(mem_1_WE1),
      .WEM1(mem_1_WEM1),
      .Q1(mem_1_Q1));

endmodule

module rbm_0_edges(CLK, rbm_0_edges_CE0, rbm_0_edges_A0, rbm_0_edges_D0, rbm_0_edges_WE0, rbm_0_edges_WEM0, rbm_0_edges_CE2, rbm_0_edges_A2, rbm_0_edges_Q2, rbm_0_edges_CE1, rbm_0_edges_A1, rbm_0_edges_Q1);
  input CLK;
  //buffer: edges - process: train_rbm - interface: W
  input rbm_0_edges_CE0;
  input [15:0] rbm_0_edges_A0;
  input [7:0] rbm_0_edges_D0;
  input rbm_0_edges_WE0;
  input [7:0] rbm_0_edges_WEM0;
  //buffer: edges - process: train_rbm - interface: R
  input rbm_0_edges_CE2;
  input [15:0] rbm_0_edges_A2;
  output [7:0] rbm_0_edges_Q2;
  //buffer: edges - process: predict_rbm - interface: R
  input rbm_0_edges_CE1;
  input [15:0] rbm_0_edges_A1;
  output [7:0] rbm_0_edges_Q1;

  //signals from banks
  wire [15:0] Q0_out [0:13];
  wire [15:0] Q1_out [0:13];

  //signals to banks
  wire mem_0_CE0;
  wire [12:0] mem_0_A0;
  wire [15:0] mem_0_D0;
  wire mem_0_WE0;
  wire [15:0] mem_0_WEM0;
  wire [15:0] mem_0_Q0;
  wire mem_0_CE1;
  wire [12:0] mem_0_A1;
  wire [15:0] mem_0_D1;
  wire mem_0_WE1;
  wire [15:0] mem_0_WEM1;
  wire [15:0] mem_0_Q1;
  wire mem_1_CE0;
  wire [12:0] mem_1_A0;
  wire [15:0] mem_1_D0;
  wire mem_1_WE0;
  wire [15:0] mem_1_WEM0;
  wire [15:0] mem_1_Q0;
  wire mem_1_CE1;
  wire [12:0] mem_1_A1;
  wire [15:0] mem_1_D1;
  wire mem_1_WE1;
  wire [15:0] mem_1_WEM1;
  wire [15:0] mem_1_Q1;
  wire mem_2_CE0;
  wire [12:0] mem_2_A0;
  wire [15:0] mem_2_D0;
  wire mem_2_WE0;
  wire [15:0] mem_2_WEM0;
  wire [15:0] mem_2_Q0;
  wire mem_2_CE1;
  wire [12:0] mem_2_A1;
  wire [15:0] mem_2_D1;
  wire mem_2_WE1;
  wire [15:0] mem_2_WEM1;
  wire [15:0] mem_2_Q1;
  wire mem_3_CE0;
  wire [12:0] mem_3_A0;
  wire [15:0] mem_3_D0;
  wire mem_3_WE0;
  wire [15:0] mem_3_WEM0;
  wire [15:0] mem_3_Q0;
  wire mem_3_CE1;
  wire [12:0] mem_3_A1;
  wire [15:0] mem_3_D1;
  wire mem_3_WE1;
  wire [15:0] mem_3_WEM1;
  wire [15:0] mem_3_Q1;
  wire mem_4_CE0;
  wire [12:0] mem_4_A0;
  wire [15:0] mem_4_D0;
  wire mem_4_WE0;
  wire [15:0] mem_4_WEM0;
  wire [15:0] mem_4_Q0;
  wire mem_4_CE1;
  wire [12:0] mem_4_A1;
  wire [15:0] mem_4_D1;
  wire mem_4_WE1;
  wire [15:0] mem_4_WEM1;
  wire [15:0] mem_4_Q1;
  wire mem_5_CE0;
  wire [12:0] mem_5_A0;
  wire [15:0] mem_5_D0;
  wire mem_5_WE0;
  wire [15:0] mem_5_WEM0;
  wire [15:0] mem_5_Q0;
  wire mem_5_CE1;
  wire [12:0] mem_5_A1;
  wire [15:0] mem_5_D1;
  wire mem_5_WE1;
  wire [15:0] mem_5_WEM1;
  wire [15:0] mem_5_Q1;
  wire mem_6_CE0;
  wire [12:0] mem_6_A0;
  wire [15:0] mem_6_D0;
  wire mem_6_WE0;
  wire [15:0] mem_6_WEM0;
  wire [15:0] mem_6_Q0;
  wire mem_6_CE1;
  wire [12:0] mem_6_A1;
  wire [15:0] mem_6_D1;
  wire mem_6_WE1;
  wire [15:0] mem_6_WEM1;
  wire [15:0] mem_6_Q1;
  wire mem_7_CE0;
  wire [12:0] mem_7_A0;
  wire [15:0] mem_7_D0;
  wire mem_7_WE0;
  wire [15:0] mem_7_WEM0;
  wire [15:0] mem_7_Q0;
  wire mem_7_CE1;
  wire [12:0] mem_7_A1;
  wire [15:0] mem_7_D1;
  wire mem_7_WE1;
  wire [15:0] mem_7_WEM1;
  wire [15:0] mem_7_Q1;
  wire mem_8_CE0;
  wire [12:0] mem_8_A0;
  wire [15:0] mem_8_D0;
  wire mem_8_WE0;
  wire [15:0] mem_8_WEM0;
  wire [15:0] mem_8_Q0;
  wire mem_8_CE1;
  wire [12:0] mem_8_A1;
  wire [15:0] mem_8_D1;
  wire mem_8_WE1;
  wire [15:0] mem_8_WEM1;
  wire [15:0] mem_8_Q1;
  wire mem_9_CE0;
  wire [12:0] mem_9_A0;
  wire [15:0] mem_9_D0;
  wire mem_9_WE0;
  wire [15:0] mem_9_WEM0;
  wire [15:0] mem_9_Q0;
  wire mem_9_CE1;
  wire [12:0] mem_9_A1;
  wire [15:0] mem_9_D1;
  wire mem_9_WE1;
  wire [15:0] mem_9_WEM1;
  wire [15:0] mem_9_Q1;
  wire mem_10_CE0;
  wire [12:0] mem_10_A0;
  wire [15:0] mem_10_D0;
  wire mem_10_WE0;
  wire [15:0] mem_10_WEM0;
  wire [15:0] mem_10_Q0;
  wire mem_10_CE1;
  wire [12:0] mem_10_A1;
  wire [15:0] mem_10_D1;
  wire mem_10_WE1;
  wire [15:0] mem_10_WEM1;
  wire [15:0] mem_10_Q1;
  wire mem_11_CE0;
  wire [12:0] mem_11_A0;
  wire [15:0] mem_11_D0;
  wire mem_11_WE0;
  wire [15:0] mem_11_WEM0;
  wire [15:0] mem_11_Q0;
  wire mem_11_CE1;
  wire [12:0] mem_11_A1;
  wire [15:0] mem_11_D1;
  wire mem_11_WE1;
  wire [15:0] mem_11_WEM1;
  wire [15:0] mem_11_Q1;
  wire mem_12_CE0;
  wire [12:0] mem_12_A0;
  wire [15:0] mem_12_D0;
  wire mem_12_WE0;
  wire [15:0] mem_12_WEM0;
  wire [15:0] mem_12_Q0;
  wire mem_12_CE1;
  wire [12:0] mem_12_A1;
  wire [15:0] mem_12_D1;
  wire mem_12_WE1;
  wire [15:0] mem_12_WEM1;
  wire [15:0] mem_12_Q1;
  wire mem_13_CE0;
  wire [12:0] mem_13_A0;
  wire [15:0] mem_13_D0;
  wire mem_13_WE0;
  wire [15:0] mem_13_WEM0;
  wire [15:0] mem_13_Q0;
  wire mem_13_CE1;
  wire [12:0] mem_13_A1;
  wire [15:0] mem_13_D1;
  wire mem_13_WE1;
  wire [15:0] mem_13_WEM1;
  wire [15:0] mem_13_Q1;

  //additional wires
  reg [3:0] sel_Q1_rbm_0_edges_2;
  reg [3:0] sel_Q1_rbm_0_edges_1;
  always@(posedge CLK)
  begin
    sel_Q1_rbm_0_edges_2 <= rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 6 ? 12 : (rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 5 ? 10 : (rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 4 ? 8 : (rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 3 ? 6 : (rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 2 ? 4 : (rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 1 ? 2 : (rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 0 ? 0 : ({4{1'b0}})))))));
    sel_Q1_rbm_0_edges_1 <= rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 6 ? 13 : (rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 5 ? 11 : (rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 4 ? 9 : (rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 3 ? 7 : (rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 2 ? 5 : (rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 1 ? 3 : (rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 0 ? 1 : ({4{1'b0}})))))));
  end

  //signals for bank: mem_0
  assign mem_0_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? 1'b1 : (1'b0);
  assign mem_0_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_0_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_0_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_0_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_0_CE1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 0 ? 1'b1 : (1'b0);
  assign mem_0_A1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 0 ? rbm_0_edges_A2[12:0] : ({13{1'b0}});
  assign mem_0_D1 = {16{1'b0}};
  assign mem_0_WE1 = 1'b0;
  assign mem_0_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[0] = mem_0_Q0;
  assign Q1_out[0] = mem_0_Q1;

  //signals for bank: mem_1
  assign mem_1_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? 1'b1 : (1'b0);
  assign mem_1_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_1_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_1_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_1_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 0 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_1_CE1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 0 ? 1'b1 : (1'b0);
  assign mem_1_A1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 0 ? rbm_0_edges_A1[12:0] : ({13{1'b0}});
  assign mem_1_D1 = {16{1'b0}};
  assign mem_1_WE1 = 1'b0;
  assign mem_1_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[1] = mem_1_Q0;
  assign Q1_out[1] = mem_1_Q1;

  //signals for bank: mem_2
  assign mem_2_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? 1'b1 : (1'b0);
  assign mem_2_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_2_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_2_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_2_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_2_CE1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 1 ? 1'b1 : (1'b0);
  assign mem_2_A1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 1 ? rbm_0_edges_A2[12:0] : ({13{1'b0}});
  assign mem_2_D1 = {16{1'b0}};
  assign mem_2_WE1 = 1'b0;
  assign mem_2_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[2] = mem_2_Q0;
  assign Q1_out[2] = mem_2_Q1;

  //signals for bank: mem_3
  assign mem_3_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? 1'b1 : (1'b0);
  assign mem_3_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_3_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_3_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_3_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 1 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_3_CE1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 1 ? 1'b1 : (1'b0);
  assign mem_3_A1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 1 ? rbm_0_edges_A1[12:0] : ({13{1'b0}});
  assign mem_3_D1 = {16{1'b0}};
  assign mem_3_WE1 = 1'b0;
  assign mem_3_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[3] = mem_3_Q0;
  assign Q1_out[3] = mem_3_Q1;

  //signals for bank: mem_4
  assign mem_4_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? 1'b1 : (1'b0);
  assign mem_4_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_4_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_4_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_4_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_4_CE1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 2 ? 1'b1 : (1'b0);
  assign mem_4_A1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 2 ? rbm_0_edges_A2[12:0] : ({13{1'b0}});
  assign mem_4_D1 = {16{1'b0}};
  assign mem_4_WE1 = 1'b0;
  assign mem_4_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[4] = mem_4_Q0;
  assign Q1_out[4] = mem_4_Q1;

  //signals for bank: mem_5
  assign mem_5_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? 1'b1 : (1'b0);
  assign mem_5_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_5_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_5_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_5_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 2 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_5_CE1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 2 ? 1'b1 : (1'b0);
  assign mem_5_A1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 2 ? rbm_0_edges_A1[12:0] : ({13{1'b0}});
  assign mem_5_D1 = {16{1'b0}};
  assign mem_5_WE1 = 1'b0;
  assign mem_5_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[5] = mem_5_Q0;
  assign Q1_out[5] = mem_5_Q1;

  //signals for bank: mem_6
  assign mem_6_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? 1'b1 : (1'b0);
  assign mem_6_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_6_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_6_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_6_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_6_CE1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 3 ? 1'b1 : (1'b0);
  assign mem_6_A1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 3 ? rbm_0_edges_A2[12:0] : ({13{1'b0}});
  assign mem_6_D1 = {16{1'b0}};
  assign mem_6_WE1 = 1'b0;
  assign mem_6_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[6] = mem_6_Q0;
  assign Q1_out[6] = mem_6_Q1;

  //signals for bank: mem_7
  assign mem_7_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? 1'b1 : (1'b0);
  assign mem_7_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_7_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_7_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_7_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 3 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_7_CE1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 3 ? 1'b1 : (1'b0);
  assign mem_7_A1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 3 ? rbm_0_edges_A1[12:0] : ({13{1'b0}});
  assign mem_7_D1 = {16{1'b0}};
  assign mem_7_WE1 = 1'b0;
  assign mem_7_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[7] = mem_7_Q0;
  assign Q1_out[7] = mem_7_Q1;

  //signals for bank: mem_8
  assign mem_8_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? 1'b1 : (1'b0);
  assign mem_8_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_8_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_8_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_8_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_8_CE1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 4 ? 1'b1 : (1'b0);
  assign mem_8_A1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 4 ? rbm_0_edges_A2[12:0] : ({13{1'b0}});
  assign mem_8_D1 = {16{1'b0}};
  assign mem_8_WE1 = 1'b0;
  assign mem_8_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[8] = mem_8_Q0;
  assign Q1_out[8] = mem_8_Q1;

  //signals for bank: mem_9
  assign mem_9_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? 1'b1 : (1'b0);
  assign mem_9_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_9_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_9_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_9_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 4 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_9_CE1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 4 ? 1'b1 : (1'b0);
  assign mem_9_A1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 4 ? rbm_0_edges_A1[12:0] : ({13{1'b0}});
  assign mem_9_D1 = {16{1'b0}};
  assign mem_9_WE1 = 1'b0;
  assign mem_9_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[9] = mem_9_Q0;
  assign Q1_out[9] = mem_9_Q1;

  //signals for bank: mem_10
  assign mem_10_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? 1'b1 : (1'b0);
  assign mem_10_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_10_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_10_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_10_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_10_CE1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 5 ? 1'b1 : (1'b0);
  assign mem_10_A1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 5 ? rbm_0_edges_A2[12:0] : ({13{1'b0}});
  assign mem_10_D1 = {16{1'b0}};
  assign mem_10_WE1 = 1'b0;
  assign mem_10_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[10] = mem_10_Q0;
  assign Q1_out[10] = mem_10_Q1;

  //signals for bank: mem_11
  assign mem_11_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? 1'b1 : (1'b0);
  assign mem_11_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_11_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_11_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_11_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 5 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_11_CE1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 5 ? 1'b1 : (1'b0);
  assign mem_11_A1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 5 ? rbm_0_edges_A1[12:0] : ({13{1'b0}});
  assign mem_11_D1 = {16{1'b0}};
  assign mem_11_WE1 = 1'b0;
  assign mem_11_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[11] = mem_11_Q0;
  assign Q1_out[11] = mem_11_Q1;

  //signals for bank: mem_12
  assign mem_12_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? 1'b1 : (1'b0);
  assign mem_12_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_12_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_12_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_12_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_12_CE1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 6 ? 1'b1 : (1'b0);
  assign mem_12_A1 = rbm_0_edges_CE2 & rbm_0_edges_A2[15:13] == 6 ? rbm_0_edges_A2[12:0] : ({13{1'b0}});
  assign mem_12_D1 = {16{1'b0}};
  assign mem_12_WE1 = 1'b0;
  assign mem_12_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[12] = mem_12_Q0;
  assign Q1_out[12] = mem_12_Q1;

  //signals for bank: mem_13
  assign mem_13_CE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? 1'b1 : (1'b0);
  assign mem_13_A0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? rbm_0_edges_A0[12:0] : ({13{1'b0}});
  assign mem_13_D0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? {{8{1'b0}},rbm_0_edges_D0[7:0]} : ({16{1'b0}});
  assign mem_13_WE0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? rbm_0_edges_WE0 : (1'b0);
  assign mem_13_WEM0 = rbm_0_edges_CE0 & rbm_0_edges_A0[15:13] == 6 ? {{8{1'b0}},rbm_0_edges_WEM0[7:0]} : ({16{1'b0}});
  assign mem_13_CE1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 6 ? 1'b1 : (1'b0);
  assign mem_13_A1 = rbm_0_edges_CE1 & rbm_0_edges_A1[15:13] == 6 ? rbm_0_edges_A1[12:0] : ({13{1'b0}});
  assign mem_13_D1 = {16{1'b0}};
  assign mem_13_WE1 = 1'b0;
  assign mem_13_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[13] = mem_13_Q0;
  assign Q1_out[13] = mem_13_Q1;

  //assigns to output ports
  assign rbm_0_edges_Q2 = Q1_out[sel_Q1_rbm_0_edges_2][7:0];
  assign rbm_0_edges_Q1 = Q1_out[sel_Q1_rbm_0_edges_1][7:0];

  //definitions of the banks
  SRAM2S_8192X16 mem_0(.CLK(CLK),
      .CE0(mem_0_CE0),
      .A0(mem_0_A0),
      .D0(mem_0_D0),
      .WE0(mem_0_WE0),
      .WEM0(mem_0_WEM0),
      .Q0(mem_0_Q0),
      .CE1(mem_0_CE1),
      .A1(mem_0_A1),
      .D1(mem_0_D1),
      .WE1(mem_0_WE1),
      .WEM1(mem_0_WEM1),
      .Q1(mem_0_Q1));

  SRAM2S_8192X16 mem_1(.CLK(CLK),
      .CE0(mem_1_CE0),
      .A0(mem_1_A0),
      .D0(mem_1_D0),
      .WE0(mem_1_WE0),
      .WEM0(mem_1_WEM0),
      .Q0(mem_1_Q0),
      .CE1(mem_1_CE1),
      .A1(mem_1_A1),
      .D1(mem_1_D1),
      .WE1(mem_1_WE1),
      .WEM1(mem_1_WEM1),
      .Q1(mem_1_Q1));

  SRAM2S_8192X16 mem_2(.CLK(CLK),
      .CE0(mem_2_CE0),
      .A0(mem_2_A0),
      .D0(mem_2_D0),
      .WE0(mem_2_WE0),
      .WEM0(mem_2_WEM0),
      .Q0(mem_2_Q0),
      .CE1(mem_2_CE1),
      .A1(mem_2_A1),
      .D1(mem_2_D1),
      .WE1(mem_2_WE1),
      .WEM1(mem_2_WEM1),
      .Q1(mem_2_Q1));

  SRAM2S_8192X16 mem_3(.CLK(CLK),
      .CE0(mem_3_CE0),
      .A0(mem_3_A0),
      .D0(mem_3_D0),
      .WE0(mem_3_WE0),
      .WEM0(mem_3_WEM0),
      .Q0(mem_3_Q0),
      .CE1(mem_3_CE1),
      .A1(mem_3_A1),
      .D1(mem_3_D1),
      .WE1(mem_3_WE1),
      .WEM1(mem_3_WEM1),
      .Q1(mem_3_Q1));

  SRAM2S_8192X16 mem_4(.CLK(CLK),
      .CE0(mem_4_CE0),
      .A0(mem_4_A0),
      .D0(mem_4_D0),
      .WE0(mem_4_WE0),
      .WEM0(mem_4_WEM0),
      .Q0(mem_4_Q0),
      .CE1(mem_4_CE1),
      .A1(mem_4_A1),
      .D1(mem_4_D1),
      .WE1(mem_4_WE1),
      .WEM1(mem_4_WEM1),
      .Q1(mem_4_Q1));

  SRAM2S_8192X16 mem_5(.CLK(CLK),
      .CE0(mem_5_CE0),
      .A0(mem_5_A0),
      .D0(mem_5_D0),
      .WE0(mem_5_WE0),
      .WEM0(mem_5_WEM0),
      .Q0(mem_5_Q0),
      .CE1(mem_5_CE1),
      .A1(mem_5_A1),
      .D1(mem_5_D1),
      .WE1(mem_5_WE1),
      .WEM1(mem_5_WEM1),
      .Q1(mem_5_Q1));

  SRAM2S_8192X16 mem_6(.CLK(CLK),
      .CE0(mem_6_CE0),
      .A0(mem_6_A0),
      .D0(mem_6_D0),
      .WE0(mem_6_WE0),
      .WEM0(mem_6_WEM0),
      .Q0(mem_6_Q0),
      .CE1(mem_6_CE1),
      .A1(mem_6_A1),
      .D1(mem_6_D1),
      .WE1(mem_6_WE1),
      .WEM1(mem_6_WEM1),
      .Q1(mem_6_Q1));

  SRAM2S_8192X16 mem_7(.CLK(CLK),
      .CE0(mem_7_CE0),
      .A0(mem_7_A0),
      .D0(mem_7_D0),
      .WE0(mem_7_WE0),
      .WEM0(mem_7_WEM0),
      .Q0(mem_7_Q0),
      .CE1(mem_7_CE1),
      .A1(mem_7_A1),
      .D1(mem_7_D1),
      .WE1(mem_7_WE1),
      .WEM1(mem_7_WEM1),
      .Q1(mem_7_Q1));

  SRAM2S_8192X16 mem_8(.CLK(CLK),
      .CE0(mem_8_CE0),
      .A0(mem_8_A0),
      .D0(mem_8_D0),
      .WE0(mem_8_WE0),
      .WEM0(mem_8_WEM0),
      .Q0(mem_8_Q0),
      .CE1(mem_8_CE1),
      .A1(mem_8_A1),
      .D1(mem_8_D1),
      .WE1(mem_8_WE1),
      .WEM1(mem_8_WEM1),
      .Q1(mem_8_Q1));

  SRAM2S_8192X16 mem_9(.CLK(CLK),
      .CE0(mem_9_CE0),
      .A0(mem_9_A0),
      .D0(mem_9_D0),
      .WE0(mem_9_WE0),
      .WEM0(mem_9_WEM0),
      .Q0(mem_9_Q0),
      .CE1(mem_9_CE1),
      .A1(mem_9_A1),
      .D1(mem_9_D1),
      .WE1(mem_9_WE1),
      .WEM1(mem_9_WEM1),
      .Q1(mem_9_Q1));

  SRAM2S_8192X16 mem_10(.CLK(CLK),
      .CE0(mem_10_CE0),
      .A0(mem_10_A0),
      .D0(mem_10_D0),
      .WE0(mem_10_WE0),
      .WEM0(mem_10_WEM0),
      .Q0(mem_10_Q0),
      .CE1(mem_10_CE1),
      .A1(mem_10_A1),
      .D1(mem_10_D1),
      .WE1(mem_10_WE1),
      .WEM1(mem_10_WEM1),
      .Q1(mem_10_Q1));

  SRAM2S_8192X16 mem_11(.CLK(CLK),
      .CE0(mem_11_CE0),
      .A0(mem_11_A0),
      .D0(mem_11_D0),
      .WE0(mem_11_WE0),
      .WEM0(mem_11_WEM0),
      .Q0(mem_11_Q0),
      .CE1(mem_11_CE1),
      .A1(mem_11_A1),
      .D1(mem_11_D1),
      .WE1(mem_11_WE1),
      .WEM1(mem_11_WEM1),
      .Q1(mem_11_Q1));

  SRAM2S_8192X16 mem_12(.CLK(CLK),
      .CE0(mem_12_CE0),
      .A0(mem_12_A0),
      .D0(mem_12_D0),
      .WE0(mem_12_WE0),
      .WEM0(mem_12_WEM0),
      .Q0(mem_12_Q0),
      .CE1(mem_12_CE1),
      .A1(mem_12_A1),
      .D1(mem_12_D1),
      .WE1(mem_12_WE1),
      .WEM1(mem_12_WEM1),
      .Q1(mem_12_Q1));

  SRAM2S_8192X16 mem_13(.CLK(CLK),
      .CE0(mem_13_CE0),
      .A0(mem_13_A0),
      .D0(mem_13_D0),
      .WE0(mem_13_WE0),
      .WEM0(mem_13_WEM0),
      .Q0(mem_13_Q0),
      .CE1(mem_13_CE1),
      .A1(mem_13_A1),
      .D1(mem_13_D1),
      .WE1(mem_13_WE1),
      .WEM1(mem_13_WEM1),
      .Q1(mem_13_Q1));

endmodule

module rbm_0_hidden_unit(CLK, rbm_0_hidden_unit_CE1, rbm_0_hidden_unit_A1, rbm_0_hidden_unit_D1, rbm_0_hidden_unit_WE1, rbm_0_hidden_unit_WEM1, rbm_0_hidden_unit_CE3, rbm_0_hidden_unit_A3, rbm_0_hidden_unit_Q3, rbm_0_hidden_unit_CE0, rbm_0_hidden_unit_A0, rbm_0_hidden_unit_D0, rbm_0_hidden_unit_WE0, rbm_0_hidden_unit_WEM0, rbm_0_hidden_unit_CE2, rbm_0_hidden_unit_A2, rbm_0_hidden_unit_Q2);
  input CLK;
  //buffer: hidden_unit - process: train_rbm - interface: W
  input rbm_0_hidden_unit_CE1;
  input [6:0] rbm_0_hidden_unit_A1;
  input rbm_0_hidden_unit_D1;
  input rbm_0_hidden_unit_WE1;
  input rbm_0_hidden_unit_WEM1;
  //buffer: hidden_unit - process: train_rbm - interface: R
  input rbm_0_hidden_unit_CE3;
  input [6:0] rbm_0_hidden_unit_A3;
  output rbm_0_hidden_unit_Q3;
  //buffer: hidden_unit - process: predict_rbm - interface: W
  input rbm_0_hidden_unit_CE0;
  input [6:0] rbm_0_hidden_unit_A0;
  input rbm_0_hidden_unit_D0;
  input rbm_0_hidden_unit_WE0;
  input rbm_0_hidden_unit_WEM0;
  //buffer: hidden_unit - process: predict_rbm - interface: R
  input rbm_0_hidden_unit_CE2;
  input [6:0] rbm_0_hidden_unit_A2;
  output rbm_0_hidden_unit_Q2;

  //signals from banks
  wire [15:0] Q0_out [0:1];
  wire [15:0] Q1_out [0:1];

  //signals to banks
  wire mem_0_CE0;
  wire [6:0] mem_0_A0;
  wire [15:0] mem_0_D0;
  wire mem_0_WE0;
  wire [15:0] mem_0_WEM0;
  wire [15:0] mem_0_Q0;
  wire mem_0_CE1;
  wire [6:0] mem_0_A1;
  wire [15:0] mem_0_D1;
  wire mem_0_WE1;
  wire [15:0] mem_0_WEM1;
  wire [15:0] mem_0_Q1;
  wire mem_1_CE0;
  wire [6:0] mem_1_A0;
  wire [15:0] mem_1_D0;
  wire mem_1_WE0;
  wire [15:0] mem_1_WEM0;
  wire [15:0] mem_1_Q0;
  wire mem_1_CE1;
  wire [6:0] mem_1_A1;
  wire [15:0] mem_1_D1;
  wire mem_1_WE1;
  wire [15:0] mem_1_WEM1;
  wire [15:0] mem_1_Q1;

  //additional wires
  reg sel_Q1_rbm_0_hidden_unit_3;
  reg sel_Q1_rbm_0_hidden_unit_2;
  always@(posedge CLK)
  begin
    sel_Q1_rbm_0_hidden_unit_3 <= rbm_0_hidden_unit_CE3 ? 0 : ({1{1'b0}});
    sel_Q1_rbm_0_hidden_unit_2 <= rbm_0_hidden_unit_CE2 ? 1 : ({1{1'b0}});
  end

  //signals for bank: mem_0
  assign mem_0_CE0 = rbm_0_hidden_unit_CE0 ? 1'b1 :
           (rbm_0_hidden_unit_CE1 ? 1'b1 : (1'b0));
  assign mem_0_A0 = rbm_0_hidden_unit_CE0 ? rbm_0_hidden_unit_A0[6:0] :
           (rbm_0_hidden_unit_CE1 ? rbm_0_hidden_unit_A1[6:0] : ({7{1'b0}}));
  assign mem_0_D0 = rbm_0_hidden_unit_CE0 ? {{15{1'b0}},rbm_0_hidden_unit_D0} :
           (rbm_0_hidden_unit_CE1 ? {{15{1'b0}},rbm_0_hidden_unit_D1} : ({16{1'b0}}));
  assign mem_0_WE0 = rbm_0_hidden_unit_CE0 ? rbm_0_hidden_unit_WE0 :
           (rbm_0_hidden_unit_CE1 ? rbm_0_hidden_unit_WE1 : (1'b0));
  assign mem_0_WEM0 = rbm_0_hidden_unit_CE0 ? {{15{1'b0}},rbm_0_hidden_unit_WEM0} :
           (rbm_0_hidden_unit_CE1 ? {{15{1'b0}},rbm_0_hidden_unit_WEM1} : ({16{1'b0}}));
  assign mem_0_CE1 = rbm_0_hidden_unit_CE3 ? 1'b1 : (1'b0);
  assign mem_0_A1 = rbm_0_hidden_unit_CE3 ? rbm_0_hidden_unit_A3[6:0] : ({7{1'b0}});
  assign mem_0_D1 = {16{1'b0}};
  assign mem_0_WE1 = 1'b0;
  assign mem_0_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[0] = mem_0_Q0;
  assign Q1_out[0] = mem_0_Q1;

  //signals for bank: mem_1
  assign mem_1_CE0 = rbm_0_hidden_unit_CE0 ? 1'b1 :
           (rbm_0_hidden_unit_CE1 ? 1'b1 : (1'b0));
  assign mem_1_A0 = rbm_0_hidden_unit_CE0 ? rbm_0_hidden_unit_A0[6:0] :
           (rbm_0_hidden_unit_CE1 ? rbm_0_hidden_unit_A1[6:0] : ({7{1'b0}}));
  assign mem_1_D0 = rbm_0_hidden_unit_CE0 ? {{15{1'b0}},rbm_0_hidden_unit_D0} :
           (rbm_0_hidden_unit_CE1 ? {{15{1'b0}},rbm_0_hidden_unit_D1} : ({16{1'b0}}));
  assign mem_1_WE0 = rbm_0_hidden_unit_CE0 ? rbm_0_hidden_unit_WE0 :
           (rbm_0_hidden_unit_CE1 ? rbm_0_hidden_unit_WE1 : (1'b0));
  assign mem_1_WEM0 = rbm_0_hidden_unit_CE0 ? {{15{1'b0}},rbm_0_hidden_unit_WEM0} :
           (rbm_0_hidden_unit_CE1 ? {{15{1'b0}},rbm_0_hidden_unit_WEM1} : ({16{1'b0}}));
  assign mem_1_CE1 = rbm_0_hidden_unit_CE2 ? 1'b1 : (1'b0);
  assign mem_1_A1 = rbm_0_hidden_unit_CE2 ? rbm_0_hidden_unit_A2[6:0] : ({7{1'b0}});
  assign mem_1_D1 = {16{1'b0}};
  assign mem_1_WE1 = 1'b0;
  assign mem_1_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[1] = mem_1_Q0;
  assign Q1_out[1] = mem_1_Q1;

  //assigns to output ports
  assign rbm_0_hidden_unit_Q3 = Q1_out[sel_Q1_rbm_0_hidden_unit_3][0:0];
  assign rbm_0_hidden_unit_Q2 = Q1_out[sel_Q1_rbm_0_hidden_unit_2][0:0];

  //definitions of the banks
  SRAM2S_128X16 mem_0(.CLK(CLK),
      .CE0(mem_0_CE0),
      .A0(mem_0_A0),
      .D0(mem_0_D0),
      .WE0(mem_0_WE0),
      .WEM0(mem_0_WEM0),
      .Q0(mem_0_Q0),
      .CE1(mem_0_CE1),
      .A1(mem_0_A1),
      .D1(mem_0_D1),
      .WE1(mem_0_WE1),
      .WEM1(mem_0_WEM1),
      .Q1(mem_0_Q1));

  SRAM2S_128X16 mem_1(.CLK(CLK),
      .CE0(mem_1_CE0),
      .A0(mem_1_A0),
      .D0(mem_1_D0),
      .WE0(mem_1_WE0),
      .WEM0(mem_1_WEM0),
      .Q0(mem_1_Q0),
      .CE1(mem_1_CE1),
      .A1(mem_1_A1),
      .D1(mem_1_D1),
      .WE1(mem_1_WE1),
      .WEM1(mem_1_WEM1),
      .Q1(mem_1_Q1));

endmodule

module rbm_0_mt(CLK, rbm_0_mt_CE0, rbm_0_mt_A0, rbm_0_mt_D0, rbm_0_mt_WE0, rbm_0_mt_WEM0, rbm_0_mt_CE1, rbm_0_mt_A1, rbm_0_mt_Q1);
  input CLK;
  //buffer: mt - process: train_rbm - interface: W
  input rbm_0_mt_CE0;
  input [9:0] rbm_0_mt_A0;
  input [31:0] rbm_0_mt_D0;
  input rbm_0_mt_WE0;
  input [31:0] rbm_0_mt_WEM0;
  //buffer: mt - process: train_rbm - interface: R
  input rbm_0_mt_CE1;
  input [9:0] rbm_0_mt_A1;
  output [31:0] rbm_0_mt_Q1;

  //signals to banks
  wire mem_0_CE0;
  wire [9:0] mem_0_A0;
  wire [31:0] mem_0_D0;
  wire mem_0_WE0;
  wire [31:0] mem_0_WEM0;
  wire [31:0] mem_0_Q0;
  wire mem_0_CE1;
  wire [9:0] mem_0_A1;
  wire [31:0] mem_0_D1;
  wire mem_0_WE1;
  wire [31:0] mem_0_WEM1;
  wire [31:0] mem_0_Q1;

  //additional wires

  //signals for bank: mem_0
  assign mem_0_CE0 = rbm_0_mt_CE0 ? 1'b1 : (1'b0);
  assign mem_0_A0 = rbm_0_mt_CE0 ? rbm_0_mt_A0[9:0] : ({10{1'b0}});
  assign mem_0_D0 = rbm_0_mt_CE0 ? rbm_0_mt_D0[31:0] : ({32{1'b0}});
  assign mem_0_WE0 = rbm_0_mt_CE0 ? rbm_0_mt_WE0 : (1'b0);
  assign mem_0_WEM0 = rbm_0_mt_CE0 ? rbm_0_mt_WEM0[31:0] : ({32{1'b0}});
  assign mem_0_CE1 = rbm_0_mt_CE1 ? 1'b1 : (1'b0);
  assign mem_0_A1 = rbm_0_mt_CE1 ? rbm_0_mt_A1[9:0] : ({10{1'b0}});
  assign mem_0_D1 = {32{1'b0}};
  assign mem_0_WE1 = 1'b0;
  assign mem_0_WEM1 = {32{1'b0}};

  //assigns to output ports
  assign rbm_0_mt_Q1 = mem_0_Q1;

  //definitions of the banks
  SRAM2S_1024X32 mem_0(.CLK(CLK),
      .CE0(mem_0_CE0),
      .A0(mem_0_A0),
      .D0(mem_0_D0),
      .WE0(mem_0_WE0),
      .WEM0(mem_0_WEM0),
      .Q0(mem_0_Q0),
      .CE1(mem_0_CE1),
      .A1(mem_0_A1),
      .D1(mem_0_D1),
      .WE1(mem_0_WE1),
      .WEM1(mem_0_WEM1),
      .Q1(mem_0_Q1));

endmodule

module rbm_0_neg(CLK, rbm_0_neg_CE0, rbm_0_neg_A0, rbm_0_neg_D0, rbm_0_neg_WE0, rbm_0_neg_WEM0, rbm_0_neg_CE1, rbm_0_neg_A1, rbm_0_neg_Q1);
  input CLK;
  //buffer: neg - process: train_rbm - interface: W
  input rbm_0_neg_CE0;
  input [15:0] rbm_0_neg_A0;
  input rbm_0_neg_D0;
  input rbm_0_neg_WE0;
  input rbm_0_neg_WEM0;
  //buffer: neg - process: train_rbm - interface: R
  input rbm_0_neg_CE1;
  input [15:0] rbm_0_neg_A1;
  output rbm_0_neg_Q1;

  //signals from banks
  wire [15:0] Q0_out [0:6];
  wire [15:0] Q1_out [0:6];

  //signals to banks
  wire mem_0_CE0;
  wire [12:0] mem_0_A0;
  wire [15:0] mem_0_D0;
  wire mem_0_WE0;
  wire [15:0] mem_0_WEM0;
  wire [15:0] mem_0_Q0;
  wire mem_0_CE1;
  wire [12:0] mem_0_A1;
  wire [15:0] mem_0_D1;
  wire mem_0_WE1;
  wire [15:0] mem_0_WEM1;
  wire [15:0] mem_0_Q1;
  wire mem_1_CE0;
  wire [12:0] mem_1_A0;
  wire [15:0] mem_1_D0;
  wire mem_1_WE0;
  wire [15:0] mem_1_WEM0;
  wire [15:0] mem_1_Q0;
  wire mem_1_CE1;
  wire [12:0] mem_1_A1;
  wire [15:0] mem_1_D1;
  wire mem_1_WE1;
  wire [15:0] mem_1_WEM1;
  wire [15:0] mem_1_Q1;
  wire mem_2_CE0;
  wire [12:0] mem_2_A0;
  wire [15:0] mem_2_D0;
  wire mem_2_WE0;
  wire [15:0] mem_2_WEM0;
  wire [15:0] mem_2_Q0;
  wire mem_2_CE1;
  wire [12:0] mem_2_A1;
  wire [15:0] mem_2_D1;
  wire mem_2_WE1;
  wire [15:0] mem_2_WEM1;
  wire [15:0] mem_2_Q1;
  wire mem_3_CE0;
  wire [12:0] mem_3_A0;
  wire [15:0] mem_3_D0;
  wire mem_3_WE0;
  wire [15:0] mem_3_WEM0;
  wire [15:0] mem_3_Q0;
  wire mem_3_CE1;
  wire [12:0] mem_3_A1;
  wire [15:0] mem_3_D1;
  wire mem_3_WE1;
  wire [15:0] mem_3_WEM1;
  wire [15:0] mem_3_Q1;
  wire mem_4_CE0;
  wire [12:0] mem_4_A0;
  wire [15:0] mem_4_D0;
  wire mem_4_WE0;
  wire [15:0] mem_4_WEM0;
  wire [15:0] mem_4_Q0;
  wire mem_4_CE1;
  wire [12:0] mem_4_A1;
  wire [15:0] mem_4_D1;
  wire mem_4_WE1;
  wire [15:0] mem_4_WEM1;
  wire [15:0] mem_4_Q1;
  wire mem_5_CE0;
  wire [12:0] mem_5_A0;
  wire [15:0] mem_5_D0;
  wire mem_5_WE0;
  wire [15:0] mem_5_WEM0;
  wire [15:0] mem_5_Q0;
  wire mem_5_CE1;
  wire [12:0] mem_5_A1;
  wire [15:0] mem_5_D1;
  wire mem_5_WE1;
  wire [15:0] mem_5_WEM1;
  wire [15:0] mem_5_Q1;
  wire mem_6_CE0;
  wire [12:0] mem_6_A0;
  wire [15:0] mem_6_D0;
  wire mem_6_WE0;
  wire [15:0] mem_6_WEM0;
  wire [15:0] mem_6_Q0;
  wire mem_6_CE1;
  wire [12:0] mem_6_A1;
  wire [15:0] mem_6_D1;
  wire mem_6_WE1;
  wire [15:0] mem_6_WEM1;
  wire [15:0] mem_6_Q1;

  //additional wires
  reg [2:0] sel_Q1_rbm_0_neg_1;
  always@(posedge CLK)
  begin
    sel_Q1_rbm_0_neg_1 <= rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 6 ? 6 : (rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 5 ? 5 : (rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 4 ? 4 : (rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 3 ? 3 : (rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 2 ? 2 : (rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 1 ? 1 : (rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 0 ? 0 : ({3{1'b0}})))))));
  end

  //signals for bank: mem_0
  assign mem_0_CE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 0 ? 1'b1 : (1'b0);
  assign mem_0_A0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 0 ? rbm_0_neg_A0[12:0] : ({13{1'b0}});
  assign mem_0_D0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 0 ? {{15{1'b0}},rbm_0_neg_D0} : ({16{1'b0}});
  assign mem_0_WE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 0 ? rbm_0_neg_WE0 : (1'b0);
  assign mem_0_WEM0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 0 ? {{15{1'b0}},rbm_0_neg_WEM0} : ({16{1'b0}});
  assign mem_0_CE1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 0 ? 1'b1 : (1'b0);
  assign mem_0_A1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 0 ? rbm_0_neg_A1[12:0] : ({13{1'b0}});
  assign mem_0_D1 = {16{1'b0}};
  assign mem_0_WE1 = 1'b0;
  assign mem_0_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[0] = mem_0_Q0;
  assign Q1_out[0] = mem_0_Q1;

  //signals for bank: mem_1
  assign mem_1_CE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 1 ? 1'b1 : (1'b0);
  assign mem_1_A0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 1 ? rbm_0_neg_A0[12:0] : ({13{1'b0}});
  assign mem_1_D0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 1 ? {{15{1'b0}},rbm_0_neg_D0} : ({16{1'b0}});
  assign mem_1_WE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 1 ? rbm_0_neg_WE0 : (1'b0);
  assign mem_1_WEM0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 1 ? {{15{1'b0}},rbm_0_neg_WEM0} : ({16{1'b0}});
  assign mem_1_CE1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 1 ? 1'b1 : (1'b0);
  assign mem_1_A1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 1 ? rbm_0_neg_A1[12:0] : ({13{1'b0}});
  assign mem_1_D1 = {16{1'b0}};
  assign mem_1_WE1 = 1'b0;
  assign mem_1_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[1] = mem_1_Q0;
  assign Q1_out[1] = mem_1_Q1;

  //signals for bank: mem_2
  assign mem_2_CE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 2 ? 1'b1 : (1'b0);
  assign mem_2_A0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 2 ? rbm_0_neg_A0[12:0] : ({13{1'b0}});
  assign mem_2_D0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 2 ? {{15{1'b0}},rbm_0_neg_D0} : ({16{1'b0}});
  assign mem_2_WE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 2 ? rbm_0_neg_WE0 : (1'b0);
  assign mem_2_WEM0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 2 ? {{15{1'b0}},rbm_0_neg_WEM0} : ({16{1'b0}});
  assign mem_2_CE1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 2 ? 1'b1 : (1'b0);
  assign mem_2_A1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 2 ? rbm_0_neg_A1[12:0] : ({13{1'b0}});
  assign mem_2_D1 = {16{1'b0}};
  assign mem_2_WE1 = 1'b0;
  assign mem_2_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[2] = mem_2_Q0;
  assign Q1_out[2] = mem_2_Q1;

  //signals for bank: mem_3
  assign mem_3_CE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 3 ? 1'b1 : (1'b0);
  assign mem_3_A0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 3 ? rbm_0_neg_A0[12:0] : ({13{1'b0}});
  assign mem_3_D0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 3 ? {{15{1'b0}},rbm_0_neg_D0} : ({16{1'b0}});
  assign mem_3_WE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 3 ? rbm_0_neg_WE0 : (1'b0);
  assign mem_3_WEM0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 3 ? {{15{1'b0}},rbm_0_neg_WEM0} : ({16{1'b0}});
  assign mem_3_CE1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 3 ? 1'b1 : (1'b0);
  assign mem_3_A1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 3 ? rbm_0_neg_A1[12:0] : ({13{1'b0}});
  assign mem_3_D1 = {16{1'b0}};
  assign mem_3_WE1 = 1'b0;
  assign mem_3_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[3] = mem_3_Q0;
  assign Q1_out[3] = mem_3_Q1;

  //signals for bank: mem_4
  assign mem_4_CE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 4 ? 1'b1 : (1'b0);
  assign mem_4_A0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 4 ? rbm_0_neg_A0[12:0] : ({13{1'b0}});
  assign mem_4_D0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 4 ? {{15{1'b0}},rbm_0_neg_D0} : ({16{1'b0}});
  assign mem_4_WE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 4 ? rbm_0_neg_WE0 : (1'b0);
  assign mem_4_WEM0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 4 ? {{15{1'b0}},rbm_0_neg_WEM0} : ({16{1'b0}});
  assign mem_4_CE1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 4 ? 1'b1 : (1'b0);
  assign mem_4_A1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 4 ? rbm_0_neg_A1[12:0] : ({13{1'b0}});
  assign mem_4_D1 = {16{1'b0}};
  assign mem_4_WE1 = 1'b0;
  assign mem_4_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[4] = mem_4_Q0;
  assign Q1_out[4] = mem_4_Q1;

  //signals for bank: mem_5
  assign mem_5_CE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 5 ? 1'b1 : (1'b0);
  assign mem_5_A0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 5 ? rbm_0_neg_A0[12:0] : ({13{1'b0}});
  assign mem_5_D0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 5 ? {{15{1'b0}},rbm_0_neg_D0} : ({16{1'b0}});
  assign mem_5_WE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 5 ? rbm_0_neg_WE0 : (1'b0);
  assign mem_5_WEM0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 5 ? {{15{1'b0}},rbm_0_neg_WEM0} : ({16{1'b0}});
  assign mem_5_CE1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 5 ? 1'b1 : (1'b0);
  assign mem_5_A1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 5 ? rbm_0_neg_A1[12:0] : ({13{1'b0}});
  assign mem_5_D1 = {16{1'b0}};
  assign mem_5_WE1 = 1'b0;
  assign mem_5_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[5] = mem_5_Q0;
  assign Q1_out[5] = mem_5_Q1;

  //signals for bank: mem_6
  assign mem_6_CE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 6 ? 1'b1 : (1'b0);
  assign mem_6_A0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 6 ? rbm_0_neg_A0[12:0] : ({13{1'b0}});
  assign mem_6_D0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 6 ? {{15{1'b0}},rbm_0_neg_D0} : ({16{1'b0}});
  assign mem_6_WE0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 6 ? rbm_0_neg_WE0 : (1'b0);
  assign mem_6_WEM0 = rbm_0_neg_CE0 & rbm_0_neg_A0[15:13] == 6 ? {{15{1'b0}},rbm_0_neg_WEM0} : ({16{1'b0}});
  assign mem_6_CE1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 6 ? 1'b1 : (1'b0);
  assign mem_6_A1 = rbm_0_neg_CE1 & rbm_0_neg_A1[15:13] == 6 ? rbm_0_neg_A1[12:0] : ({13{1'b0}});
  assign mem_6_D1 = {16{1'b0}};
  assign mem_6_WE1 = 1'b0;
  assign mem_6_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[6] = mem_6_Q0;
  assign Q1_out[6] = mem_6_Q1;

  //assigns to output ports
  assign rbm_0_neg_Q1 = Q1_out[sel_Q1_rbm_0_neg_1][0:0];

  //definitions of the banks
  SRAM2S_8192X16 mem_0(.CLK(CLK),
      .CE0(mem_0_CE0),
      .A0(mem_0_A0),
      .D0(mem_0_D0),
      .WE0(mem_0_WE0),
      .WEM0(mem_0_WEM0),
      .Q0(mem_0_Q0),
      .CE1(mem_0_CE1),
      .A1(mem_0_A1),
      .D1(mem_0_D1),
      .WE1(mem_0_WE1),
      .WEM1(mem_0_WEM1),
      .Q1(mem_0_Q1));

  SRAM2S_8192X16 mem_1(.CLK(CLK),
      .CE0(mem_1_CE0),
      .A0(mem_1_A0),
      .D0(mem_1_D0),
      .WE0(mem_1_WE0),
      .WEM0(mem_1_WEM0),
      .Q0(mem_1_Q0),
      .CE1(mem_1_CE1),
      .A1(mem_1_A1),
      .D1(mem_1_D1),
      .WE1(mem_1_WE1),
      .WEM1(mem_1_WEM1),
      .Q1(mem_1_Q1));

  SRAM2S_8192X16 mem_2(.CLK(CLK),
      .CE0(mem_2_CE0),
      .A0(mem_2_A0),
      .D0(mem_2_D0),
      .WE0(mem_2_WE0),
      .WEM0(mem_2_WEM0),
      .Q0(mem_2_Q0),
      .CE1(mem_2_CE1),
      .A1(mem_2_A1),
      .D1(mem_2_D1),
      .WE1(mem_2_WE1),
      .WEM1(mem_2_WEM1),
      .Q1(mem_2_Q1));

  SRAM2S_8192X16 mem_3(.CLK(CLK),
      .CE0(mem_3_CE0),
      .A0(mem_3_A0),
      .D0(mem_3_D0),
      .WE0(mem_3_WE0),
      .WEM0(mem_3_WEM0),
      .Q0(mem_3_Q0),
      .CE1(mem_3_CE1),
      .A1(mem_3_A1),
      .D1(mem_3_D1),
      .WE1(mem_3_WE1),
      .WEM1(mem_3_WEM1),
      .Q1(mem_3_Q1));

  SRAM2S_8192X16 mem_4(.CLK(CLK),
      .CE0(mem_4_CE0),
      .A0(mem_4_A0),
      .D0(mem_4_D0),
      .WE0(mem_4_WE0),
      .WEM0(mem_4_WEM0),
      .Q0(mem_4_Q0),
      .CE1(mem_4_CE1),
      .A1(mem_4_A1),
      .D1(mem_4_D1),
      .WE1(mem_4_WE1),
      .WEM1(mem_4_WEM1),
      .Q1(mem_4_Q1));

  SRAM2S_8192X16 mem_5(.CLK(CLK),
      .CE0(mem_5_CE0),
      .A0(mem_5_A0),
      .D0(mem_5_D0),
      .WE0(mem_5_WE0),
      .WEM0(mem_5_WEM0),
      .Q0(mem_5_Q0),
      .CE1(mem_5_CE1),
      .A1(mem_5_A1),
      .D1(mem_5_D1),
      .WE1(mem_5_WE1),
      .WEM1(mem_5_WEM1),
      .Q1(mem_5_Q1));

  SRAM2S_8192X16 mem_6(.CLK(CLK),
      .CE0(mem_6_CE0),
      .A0(mem_6_A0),
      .D0(mem_6_D0),
      .WE0(mem_6_WE0),
      .WEM0(mem_6_WEM0),
      .Q0(mem_6_Q0),
      .CE1(mem_6_CE1),
      .A1(mem_6_A1),
      .D1(mem_6_D1),
      .WE1(mem_6_WE1),
      .WEM1(mem_6_WEM1),
      .Q1(mem_6_Q1));

endmodule

module rbm_0_pos(CLK, rbm_0_pos_CE0, rbm_0_pos_A0, rbm_0_pos_D0, rbm_0_pos_WE0, rbm_0_pos_WEM0, rbm_0_pos_CE1, rbm_0_pos_A1, rbm_0_pos_Q1);
  input CLK;
  //buffer: pos - process: train_rbm - interface: W
  input rbm_0_pos_CE0;
  input [15:0] rbm_0_pos_A0;
  input rbm_0_pos_D0;
  input rbm_0_pos_WE0;
  input rbm_0_pos_WEM0;
  //buffer: pos - process: train_rbm - interface: R
  input rbm_0_pos_CE1;
  input [15:0] rbm_0_pos_A1;
  output rbm_0_pos_Q1;

  //signals from banks
  wire [15:0] Q0_out [0:6];
  wire [15:0] Q1_out [0:6];

  //signals to banks
  wire mem_0_CE0;
  wire [12:0] mem_0_A0;
  wire [15:0] mem_0_D0;
  wire mem_0_WE0;
  wire [15:0] mem_0_WEM0;
  wire [15:0] mem_0_Q0;
  wire mem_0_CE1;
  wire [12:0] mem_0_A1;
  wire [15:0] mem_0_D1;
  wire mem_0_WE1;
  wire [15:0] mem_0_WEM1;
  wire [15:0] mem_0_Q1;
  wire mem_1_CE0;
  wire [12:0] mem_1_A0;
  wire [15:0] mem_1_D0;
  wire mem_1_WE0;
  wire [15:0] mem_1_WEM0;
  wire [15:0] mem_1_Q0;
  wire mem_1_CE1;
  wire [12:0] mem_1_A1;
  wire [15:0] mem_1_D1;
  wire mem_1_WE1;
  wire [15:0] mem_1_WEM1;
  wire [15:0] mem_1_Q1;
  wire mem_2_CE0;
  wire [12:0] mem_2_A0;
  wire [15:0] mem_2_D0;
  wire mem_2_WE0;
  wire [15:0] mem_2_WEM0;
  wire [15:0] mem_2_Q0;
  wire mem_2_CE1;
  wire [12:0] mem_2_A1;
  wire [15:0] mem_2_D1;
  wire mem_2_WE1;
  wire [15:0] mem_2_WEM1;
  wire [15:0] mem_2_Q1;
  wire mem_3_CE0;
  wire [12:0] mem_3_A0;
  wire [15:0] mem_3_D0;
  wire mem_3_WE0;
  wire [15:0] mem_3_WEM0;
  wire [15:0] mem_3_Q0;
  wire mem_3_CE1;
  wire [12:0] mem_3_A1;
  wire [15:0] mem_3_D1;
  wire mem_3_WE1;
  wire [15:0] mem_3_WEM1;
  wire [15:0] mem_3_Q1;
  wire mem_4_CE0;
  wire [12:0] mem_4_A0;
  wire [15:0] mem_4_D0;
  wire mem_4_WE0;
  wire [15:0] mem_4_WEM0;
  wire [15:0] mem_4_Q0;
  wire mem_4_CE1;
  wire [12:0] mem_4_A1;
  wire [15:0] mem_4_D1;
  wire mem_4_WE1;
  wire [15:0] mem_4_WEM1;
  wire [15:0] mem_4_Q1;
  wire mem_5_CE0;
  wire [12:0] mem_5_A0;
  wire [15:0] mem_5_D0;
  wire mem_5_WE0;
  wire [15:0] mem_5_WEM0;
  wire [15:0] mem_5_Q0;
  wire mem_5_CE1;
  wire [12:0] mem_5_A1;
  wire [15:0] mem_5_D1;
  wire mem_5_WE1;
  wire [15:0] mem_5_WEM1;
  wire [15:0] mem_5_Q1;
  wire mem_6_CE0;
  wire [12:0] mem_6_A0;
  wire [15:0] mem_6_D0;
  wire mem_6_WE0;
  wire [15:0] mem_6_WEM0;
  wire [15:0] mem_6_Q0;
  wire mem_6_CE1;
  wire [12:0] mem_6_A1;
  wire [15:0] mem_6_D1;
  wire mem_6_WE1;
  wire [15:0] mem_6_WEM1;
  wire [15:0] mem_6_Q1;

  //additional wires
  reg [2:0] sel_Q1_rbm_0_pos_1;
  always@(posedge CLK)
  begin
    sel_Q1_rbm_0_pos_1 <= rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 6 ? 6 : (rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 5 ? 5 : (rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 4 ? 4 : (rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 3 ? 3 : (rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 2 ? 2 : (rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 1 ? 1 : (rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 0 ? 0 : ({3{1'b0}})))))));
  end

  //signals for bank: mem_0
  assign mem_0_CE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 0 ? 1'b1 : (1'b0);
  assign mem_0_A0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 0 ? rbm_0_pos_A0[12:0] : ({13{1'b0}});
  assign mem_0_D0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 0 ? {{15{1'b0}},rbm_0_pos_D0} : ({16{1'b0}});
  assign mem_0_WE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 0 ? rbm_0_pos_WE0 : (1'b0);
  assign mem_0_WEM0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 0 ? {{15{1'b0}},rbm_0_pos_WEM0} : ({16{1'b0}});
  assign mem_0_CE1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 0 ? 1'b1 : (1'b0);
  assign mem_0_A1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 0 ? rbm_0_pos_A1[12:0] : ({13{1'b0}});
  assign mem_0_D1 = {16{1'b0}};
  assign mem_0_WE1 = 1'b0;
  assign mem_0_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[0] = mem_0_Q0;
  assign Q1_out[0] = mem_0_Q1;

  //signals for bank: mem_1
  assign mem_1_CE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 1 ? 1'b1 : (1'b0);
  assign mem_1_A0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 1 ? rbm_0_pos_A0[12:0] : ({13{1'b0}});
  assign mem_1_D0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 1 ? {{15{1'b0}},rbm_0_pos_D0} : ({16{1'b0}});
  assign mem_1_WE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 1 ? rbm_0_pos_WE0 : (1'b0);
  assign mem_1_WEM0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 1 ? {{15{1'b0}},rbm_0_pos_WEM0} : ({16{1'b0}});
  assign mem_1_CE1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 1 ? 1'b1 : (1'b0);
  assign mem_1_A1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 1 ? rbm_0_pos_A1[12:0] : ({13{1'b0}});
  assign mem_1_D1 = {16{1'b0}};
  assign mem_1_WE1 = 1'b0;
  assign mem_1_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[1] = mem_1_Q0;
  assign Q1_out[1] = mem_1_Q1;

  //signals for bank: mem_2
  assign mem_2_CE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 2 ? 1'b1 : (1'b0);
  assign mem_2_A0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 2 ? rbm_0_pos_A0[12:0] : ({13{1'b0}});
  assign mem_2_D0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 2 ? {{15{1'b0}},rbm_0_pos_D0} : ({16{1'b0}});
  assign mem_2_WE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 2 ? rbm_0_pos_WE0 : (1'b0);
  assign mem_2_WEM0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 2 ? {{15{1'b0}},rbm_0_pos_WEM0} : ({16{1'b0}});
  assign mem_2_CE1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 2 ? 1'b1 : (1'b0);
  assign mem_2_A1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 2 ? rbm_0_pos_A1[12:0] : ({13{1'b0}});
  assign mem_2_D1 = {16{1'b0}};
  assign mem_2_WE1 = 1'b0;
  assign mem_2_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[2] = mem_2_Q0;
  assign Q1_out[2] = mem_2_Q1;

  //signals for bank: mem_3
  assign mem_3_CE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 3 ? 1'b1 : (1'b0);
  assign mem_3_A0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 3 ? rbm_0_pos_A0[12:0] : ({13{1'b0}});
  assign mem_3_D0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 3 ? {{15{1'b0}},rbm_0_pos_D0} : ({16{1'b0}});
  assign mem_3_WE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 3 ? rbm_0_pos_WE0 : (1'b0);
  assign mem_3_WEM0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 3 ? {{15{1'b0}},rbm_0_pos_WEM0} : ({16{1'b0}});
  assign mem_3_CE1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 3 ? 1'b1 : (1'b0);
  assign mem_3_A1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 3 ? rbm_0_pos_A1[12:0] : ({13{1'b0}});
  assign mem_3_D1 = {16{1'b0}};
  assign mem_3_WE1 = 1'b0;
  assign mem_3_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[3] = mem_3_Q0;
  assign Q1_out[3] = mem_3_Q1;

  //signals for bank: mem_4
  assign mem_4_CE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 4 ? 1'b1 : (1'b0);
  assign mem_4_A0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 4 ? rbm_0_pos_A0[12:0] : ({13{1'b0}});
  assign mem_4_D0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 4 ? {{15{1'b0}},rbm_0_pos_D0} : ({16{1'b0}});
  assign mem_4_WE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 4 ? rbm_0_pos_WE0 : (1'b0);
  assign mem_4_WEM0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 4 ? {{15{1'b0}},rbm_0_pos_WEM0} : ({16{1'b0}});
  assign mem_4_CE1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 4 ? 1'b1 : (1'b0);
  assign mem_4_A1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 4 ? rbm_0_pos_A1[12:0] : ({13{1'b0}});
  assign mem_4_D1 = {16{1'b0}};
  assign mem_4_WE1 = 1'b0;
  assign mem_4_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[4] = mem_4_Q0;
  assign Q1_out[4] = mem_4_Q1;

  //signals for bank: mem_5
  assign mem_5_CE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 5 ? 1'b1 : (1'b0);
  assign mem_5_A0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 5 ? rbm_0_pos_A0[12:0] : ({13{1'b0}});
  assign mem_5_D0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 5 ? {{15{1'b0}},rbm_0_pos_D0} : ({16{1'b0}});
  assign mem_5_WE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 5 ? rbm_0_pos_WE0 : (1'b0);
  assign mem_5_WEM0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 5 ? {{15{1'b0}},rbm_0_pos_WEM0} : ({16{1'b0}});
  assign mem_5_CE1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 5 ? 1'b1 : (1'b0);
  assign mem_5_A1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 5 ? rbm_0_pos_A1[12:0] : ({13{1'b0}});
  assign mem_5_D1 = {16{1'b0}};
  assign mem_5_WE1 = 1'b0;
  assign mem_5_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[5] = mem_5_Q0;
  assign Q1_out[5] = mem_5_Q1;

  //signals for bank: mem_6
  assign mem_6_CE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 6 ? 1'b1 : (1'b0);
  assign mem_6_A0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 6 ? rbm_0_pos_A0[12:0] : ({13{1'b0}});
  assign mem_6_D0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 6 ? {{15{1'b0}},rbm_0_pos_D0} : ({16{1'b0}});
  assign mem_6_WE0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 6 ? rbm_0_pos_WE0 : (1'b0);
  assign mem_6_WEM0 = rbm_0_pos_CE0 & rbm_0_pos_A0[15:13] == 6 ? {{15{1'b0}},rbm_0_pos_WEM0} : ({16{1'b0}});
  assign mem_6_CE1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 6 ? 1'b1 : (1'b0);
  assign mem_6_A1 = rbm_0_pos_CE1 & rbm_0_pos_A1[15:13] == 6 ? rbm_0_pos_A1[12:0] : ({13{1'b0}});
  assign mem_6_D1 = {16{1'b0}};
  assign mem_6_WE1 = 1'b0;
  assign mem_6_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[6] = mem_6_Q0;
  assign Q1_out[6] = mem_6_Q1;

  //assigns to output ports
  assign rbm_0_pos_Q1 = Q1_out[sel_Q1_rbm_0_pos_1][0:0];

  //definitions of the banks
  SRAM2S_8192X16 mem_0(.CLK(CLK),
      .CE0(mem_0_CE0),
      .A0(mem_0_A0),
      .D0(mem_0_D0),
      .WE0(mem_0_WE0),
      .WEM0(mem_0_WEM0),
      .Q0(mem_0_Q0),
      .CE1(mem_0_CE1),
      .A1(mem_0_A1),
      .D1(mem_0_D1),
      .WE1(mem_0_WE1),
      .WEM1(mem_0_WEM1),
      .Q1(mem_0_Q1));

  SRAM2S_8192X16 mem_1(.CLK(CLK),
      .CE0(mem_1_CE0),
      .A0(mem_1_A0),
      .D0(mem_1_D0),
      .WE0(mem_1_WE0),
      .WEM0(mem_1_WEM0),
      .Q0(mem_1_Q0),
      .CE1(mem_1_CE1),
      .A1(mem_1_A1),
      .D1(mem_1_D1),
      .WE1(mem_1_WE1),
      .WEM1(mem_1_WEM1),
      .Q1(mem_1_Q1));

  SRAM2S_8192X16 mem_2(.CLK(CLK),
      .CE0(mem_2_CE0),
      .A0(mem_2_A0),
      .D0(mem_2_D0),
      .WE0(mem_2_WE0),
      .WEM0(mem_2_WEM0),
      .Q0(mem_2_Q0),
      .CE1(mem_2_CE1),
      .A1(mem_2_A1),
      .D1(mem_2_D1),
      .WE1(mem_2_WE1),
      .WEM1(mem_2_WEM1),
      .Q1(mem_2_Q1));

  SRAM2S_8192X16 mem_3(.CLK(CLK),
      .CE0(mem_3_CE0),
      .A0(mem_3_A0),
      .D0(mem_3_D0),
      .WE0(mem_3_WE0),
      .WEM0(mem_3_WEM0),
      .Q0(mem_3_Q0),
      .CE1(mem_3_CE1),
      .A1(mem_3_A1),
      .D1(mem_3_D1),
      .WE1(mem_3_WE1),
      .WEM1(mem_3_WEM1),
      .Q1(mem_3_Q1));

  SRAM2S_8192X16 mem_4(.CLK(CLK),
      .CE0(mem_4_CE0),
      .A0(mem_4_A0),
      .D0(mem_4_D0),
      .WE0(mem_4_WE0),
      .WEM0(mem_4_WEM0),
      .Q0(mem_4_Q0),
      .CE1(mem_4_CE1),
      .A1(mem_4_A1),
      .D1(mem_4_D1),
      .WE1(mem_4_WE1),
      .WEM1(mem_4_WEM1),
      .Q1(mem_4_Q1));

  SRAM2S_8192X16 mem_5(.CLK(CLK),
      .CE0(mem_5_CE0),
      .A0(mem_5_A0),
      .D0(mem_5_D0),
      .WE0(mem_5_WE0),
      .WEM0(mem_5_WEM0),
      .Q0(mem_5_Q0),
      .CE1(mem_5_CE1),
      .A1(mem_5_A1),
      .D1(mem_5_D1),
      .WE1(mem_5_WE1),
      .WEM1(mem_5_WEM1),
      .Q1(mem_5_Q1));

  SRAM2S_8192X16 mem_6(.CLK(CLK),
      .CE0(mem_6_CE0),
      .A0(mem_6_A0),
      .D0(mem_6_D0),
      .WE0(mem_6_WE0),
      .WEM0(mem_6_WEM0),
      .Q0(mem_6_Q0),
      .CE1(mem_6_CE1),
      .A1(mem_6_A1),
      .D1(mem_6_D1),
      .WE1(mem_6_WE1),
      .WEM1(mem_6_WEM1),
      .Q1(mem_6_Q1));

endmodule

module rbm_0_predict_result(CLK, rbm_0_predict_result_CE1, rbm_0_predict_result_A1, rbm_0_predict_result_Q1, rbm_0_predict_result_CE0, rbm_0_predict_result_A0, rbm_0_predict_result_D0, rbm_0_predict_result_WE0, rbm_0_predict_result_WEM0);
  input CLK;
  //buffer: predict_result - process: store - interface: R
  input rbm_0_predict_result_CE1;
  input [6:0] rbm_0_predict_result_A1;
  output [3:0] rbm_0_predict_result_Q1;
  //buffer: predict_result - process: predict_rbm - interface: W
  input rbm_0_predict_result_CE0;
  input [6:0] rbm_0_predict_result_A0;
  input [3:0] rbm_0_predict_result_D0;
  input rbm_0_predict_result_WE0;
  input [3:0] rbm_0_predict_result_WEM0;

  //signals to banks
  wire mem_0_CE0;
  wire [6:0] mem_0_A0;
  wire [15:0] mem_0_D0;
  wire mem_0_WE0;
  wire [15:0] mem_0_WEM0;
  wire [15:0] mem_0_Q0;
  wire mem_0_CE1;
  wire [6:0] mem_0_A1;
  wire [15:0] mem_0_D1;
  wire mem_0_WE1;
  wire [15:0] mem_0_WEM1;
  wire [15:0] mem_0_Q1;

  //additional wires

  //signals for bank: mem_0
  assign mem_0_CE0 = rbm_0_predict_result_CE0 ? 1'b1 : (1'b0);
  assign mem_0_A0 = rbm_0_predict_result_CE0 ? rbm_0_predict_result_A0[6:0] : ({7{1'b0}});
  assign mem_0_D0 = rbm_0_predict_result_CE0 ? {{12{1'b0}},rbm_0_predict_result_D0[3:0]} : ({16{1'b0}});
  assign mem_0_WE0 = rbm_0_predict_result_CE0 ? rbm_0_predict_result_WE0 : (1'b0);
  assign mem_0_WEM0 = rbm_0_predict_result_CE0 ? {{12{1'b0}},rbm_0_predict_result_WEM0[3:0]} : ({16{1'b0}});
  assign mem_0_CE1 = rbm_0_predict_result_CE1 ? 1'b1 : (1'b0);
  assign mem_0_A1 = rbm_0_predict_result_CE1 ? rbm_0_predict_result_A1[6:0] : ({7{1'b0}});
  assign mem_0_D1 = {16{1'b0}};
  assign mem_0_WE1 = 1'b0;
  assign mem_0_WEM1 = {16{1'b0}};

  //assigns to output ports
  assign rbm_0_predict_result_Q1 = mem_0_Q1[3:0];

  //definitions of the banks
  SRAM2S_128X16 mem_0(.CLK(CLK),
      .CE0(mem_0_CE0),
      .A0(mem_0_A0),
      .D0(mem_0_D0),
      .WE0(mem_0_WE0),
      .WEM0(mem_0_WEM0),
      .Q0(mem_0_Q0),
      .CE1(mem_0_CE1),
      .A1(mem_0_A1),
      .D1(mem_0_D1),
      .WE1(mem_0_WE1),
      .WEM1(mem_0_WEM1),
      .Q1(mem_0_Q1));

endmodule

module rbm_0_visibleEnergies(CLK, rbm_0_visibleEnergies_CE1, rbm_0_visibleEnergies_A1, rbm_0_visibleEnergies_D1, rbm_0_visibleEnergies_WE1, rbm_0_visibleEnergies_WEM1, rbm_0_visibleEnergies_CE3, rbm_0_visibleEnergies_A3, rbm_0_visibleEnergies_Q3, rbm_0_visibleEnergies_CE0, rbm_0_visibleEnergies_A0, rbm_0_visibleEnergies_D0, rbm_0_visibleEnergies_WE0, rbm_0_visibleEnergies_WEM0, rbm_0_visibleEnergies_CE2, rbm_0_visibleEnergies_A2, rbm_0_visibleEnergies_Q2);
  input CLK;
  //buffer: visibleEnergies - process: train_rbm - interface: W
  input rbm_0_visibleEnergies_CE1;
  input [2:0] rbm_0_visibleEnergies_A1;
  input [15:0] rbm_0_visibleEnergies_D1;
  input rbm_0_visibleEnergies_WE1;
  input [15:0] rbm_0_visibleEnergies_WEM1;
  //buffer: visibleEnergies - process: train_rbm - interface: R
  input rbm_0_visibleEnergies_CE3;
  input [2:0] rbm_0_visibleEnergies_A3;
  output [15:0] rbm_0_visibleEnergies_Q3;
  //buffer: visibleEnergies - process: predict_rbm - interface: W
  input rbm_0_visibleEnergies_CE0;
  input [2:0] rbm_0_visibleEnergies_A0;
  input [15:0] rbm_0_visibleEnergies_D0;
  input rbm_0_visibleEnergies_WE0;
  input [15:0] rbm_0_visibleEnergies_WEM0;
  //buffer: visibleEnergies - process: predict_rbm - interface: R
  input rbm_0_visibleEnergies_CE2;
  input [2:0] rbm_0_visibleEnergies_A2;
  output [15:0] rbm_0_visibleEnergies_Q2;

  //signals from banks
  wire [15:0] Q0_out [0:1];
  wire [15:0] Q1_out [0:1];

  //signals to banks
  wire mem_0_CE0;
  wire [6:0] mem_0_A0;
  wire [15:0] mem_0_D0;
  wire mem_0_WE0;
  wire [15:0] mem_0_WEM0;
  wire [15:0] mem_0_Q0;
  wire mem_0_CE1;
  wire [6:0] mem_0_A1;
  wire [15:0] mem_0_D1;
  wire mem_0_WE1;
  wire [15:0] mem_0_WEM1;
  wire [15:0] mem_0_Q1;
  wire mem_1_CE0;
  wire [6:0] mem_1_A0;
  wire [15:0] mem_1_D0;
  wire mem_1_WE0;
  wire [15:0] mem_1_WEM0;
  wire [15:0] mem_1_Q0;
  wire mem_1_CE1;
  wire [6:0] mem_1_A1;
  wire [15:0] mem_1_D1;
  wire mem_1_WE1;
  wire [15:0] mem_1_WEM1;
  wire [15:0] mem_1_Q1;

  //additional wires
  reg sel_Q1_rbm_0_visibleEnergies_3;
  reg sel_Q1_rbm_0_visibleEnergies_2;
  always@(posedge CLK)
  begin
    sel_Q1_rbm_0_visibleEnergies_3 <= rbm_0_visibleEnergies_CE3 ? 0 : ({1{1'b0}});
    sel_Q1_rbm_0_visibleEnergies_2 <= rbm_0_visibleEnergies_CE2 ? 1 : ({1{1'b0}});
  end

  //signals for bank: mem_0
  assign mem_0_CE0 = rbm_0_visibleEnergies_CE0 ? 1'b1 :
           (rbm_0_visibleEnergies_CE1 ? 1'b1 : (1'b0));
  assign mem_0_A0 = rbm_0_visibleEnergies_CE0 ? {{4{1'b0}},rbm_0_visibleEnergies_A0[2:0]} :
           (rbm_0_visibleEnergies_CE1 ? {{4{1'b0}},rbm_0_visibleEnergies_A1[2:0]} : ({7{1'b0}}));
  assign mem_0_D0 = rbm_0_visibleEnergies_CE0 ? rbm_0_visibleEnergies_D0[15:0] :
           (rbm_0_visibleEnergies_CE1 ? rbm_0_visibleEnergies_D1[15:0] : ({16{1'b0}}));
  assign mem_0_WE0 = rbm_0_visibleEnergies_CE0 ? rbm_0_visibleEnergies_WE0 :
           (rbm_0_visibleEnergies_CE1 ? rbm_0_visibleEnergies_WE1 : (1'b0));
  assign mem_0_WEM0 = rbm_0_visibleEnergies_CE0 ? rbm_0_visibleEnergies_WEM0[15:0] :
           (rbm_0_visibleEnergies_CE1 ? rbm_0_visibleEnergies_WEM1[15:0] : ({16{1'b0}}));
  assign mem_0_CE1 = rbm_0_visibleEnergies_CE3 ? 1'b1 : (1'b0);
  assign mem_0_A1 = rbm_0_visibleEnergies_CE3 ? {{4{1'b0}},rbm_0_visibleEnergies_A3[2:0]} : ({7{1'b0}});
  assign mem_0_D1 = {16{1'b0}};
  assign mem_0_WE1 = 1'b0;
  assign mem_0_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[0] = mem_0_Q0;
  assign Q1_out[0] = mem_0_Q1;

  //signals for bank: mem_1
  assign mem_1_CE0 = rbm_0_visibleEnergies_CE0 ? 1'b1 :
           (rbm_0_visibleEnergies_CE1 ? 1'b1 : (1'b0));
  assign mem_1_A0 = rbm_0_visibleEnergies_CE0 ? {{4{1'b0}},rbm_0_visibleEnergies_A0[2:0]} :
           (rbm_0_visibleEnergies_CE1 ? {{4{1'b0}},rbm_0_visibleEnergies_A1[2:0]} : ({7{1'b0}}));
  assign mem_1_D0 = rbm_0_visibleEnergies_CE0 ? rbm_0_visibleEnergies_D0[15:0] :
           (rbm_0_visibleEnergies_CE1 ? rbm_0_visibleEnergies_D1[15:0] : ({16{1'b0}}));
  assign mem_1_WE0 = rbm_0_visibleEnergies_CE0 ? rbm_0_visibleEnergies_WE0 :
           (rbm_0_visibleEnergies_CE1 ? rbm_0_visibleEnergies_WE1 : (1'b0));
  assign mem_1_WEM0 = rbm_0_visibleEnergies_CE0 ? rbm_0_visibleEnergies_WEM0[15:0] :
           (rbm_0_visibleEnergies_CE1 ? rbm_0_visibleEnergies_WEM1[15:0] : ({16{1'b0}}));
  assign mem_1_CE1 = rbm_0_visibleEnergies_CE2 ? 1'b1 : (1'b0);
  assign mem_1_A1 = rbm_0_visibleEnergies_CE2 ? {{4{1'b0}},rbm_0_visibleEnergies_A2[2:0]} : ({7{1'b0}});
  assign mem_1_D1 = {16{1'b0}};
  assign mem_1_WE1 = 1'b0;
  assign mem_1_WEM1 = {16{1'b0}};
  //output bank selection
  assign Q0_out[1] = mem_1_Q0;
  assign Q1_out[1] = mem_1_Q1;

  //assigns to output ports
  assign rbm_0_visibleEnergies_Q3 = Q1_out[sel_Q1_rbm_0_visibleEnergies_3];
  assign rbm_0_visibleEnergies_Q2 = Q1_out[sel_Q1_rbm_0_visibleEnergies_2];

  //definitions of the banks
  SRAM2S_128X16 mem_0(.CLK(CLK),
      .CE0(mem_0_CE0),
      .A0(mem_0_A0),
      .D0(mem_0_D0),
      .WE0(mem_0_WE0),
      .WEM0(mem_0_WEM0),
      .Q0(mem_0_Q0),
      .CE1(mem_0_CE1),
      .A1(mem_0_A1),
      .D1(mem_0_D1),
      .WE1(mem_0_WE1),
      .WEM1(mem_0_WEM1),
      .Q1(mem_0_Q1));

  SRAM2S_128X16 mem_1(.CLK(CLK),
      .CE0(mem_1_CE0),
      .A0(mem_1_A0),
      .D0(mem_1_D0),
      .WE0(mem_1_WE0),
      .WEM0(mem_1_WEM0),
      .Q0(mem_1_Q0),
      .CE1(mem_1_CE1),
      .A1(mem_1_A1),
      .D1(mem_1_D1),
      .WE1(mem_1_WE1),
      .WEM1(mem_1_WEM1),
      .Q1(mem_1_Q1));

endmodule

module PLM (clk, rst, rbm_0_data_CE0, rbm_0_data_A0, rbm_0_data_D0, rbm_0_data_WE0, rbm_0_data_WEM0, rbm_0_data_CE2, rbm_0_data_A2, rbm_0_data_Q2, rbm_0_data_CE1, rbm_0_data_A1, rbm_0_data_Q1, rbm_0_edges_CE0, rbm_0_edges_A0, rbm_0_edges_D0, rbm_0_edges_WE0, rbm_0_edges_WEM0, rbm_0_edges_CE2, rbm_0_edges_A2, rbm_0_edges_Q2, rbm_0_edges_CE1, rbm_0_edges_A1, rbm_0_edges_Q1, rbm_0_hidden_unit_CE1, rbm_0_hidden_unit_A1, rbm_0_hidden_unit_D1, rbm_0_hidden_unit_WE1, rbm_0_hidden_unit_WEM1, rbm_0_hidden_unit_CE3, rbm_0_hidden_unit_A3, rbm_0_hidden_unit_Q3, rbm_0_hidden_unit_CE0, rbm_0_hidden_unit_A0, rbm_0_hidden_unit_D0, rbm_0_hidden_unit_WE0, rbm_0_hidden_unit_WEM0, rbm_0_hidden_unit_CE2, rbm_0_hidden_unit_A2, rbm_0_hidden_unit_Q2, rbm_0_mt_CE0, rbm_0_mt_A0, rbm_0_mt_D0, rbm_0_mt_WE0, rbm_0_mt_WEM0, rbm_0_mt_CE1, rbm_0_mt_A1, rbm_0_mt_Q1, rbm_0_neg_CE0, rbm_0_neg_A0, rbm_0_neg_D0, rbm_0_neg_WE0, rbm_0_neg_WEM0, rbm_0_neg_CE1, rbm_0_neg_A1, rbm_0_neg_Q1, rbm_0_pos_CE0, rbm_0_pos_A0, rbm_0_pos_D0, rbm_0_pos_WE0, rbm_0_pos_WEM0, rbm_0_pos_CE1, rbm_0_pos_A1, rbm_0_pos_Q1, rbm_0_predict_result_CE1, rbm_0_predict_result_A1, rbm_0_predict_result_Q1, rbm_0_predict_result_CE0, rbm_0_predict_result_A0, rbm_0_predict_result_D0, rbm_0_predict_result_WE0, rbm_0_predict_result_WEM0, rbm_0_visibleEnergies_CE1, rbm_0_visibleEnergies_A1, rbm_0_visibleEnergies_D1, rbm_0_visibleEnergies_WE1, rbm_0_visibleEnergies_WEM1, rbm_0_visibleEnergies_CE3, rbm_0_visibleEnergies_A3, rbm_0_visibleEnergies_Q3, rbm_0_visibleEnergies_CE0, rbm_0_visibleEnergies_A0, rbm_0_visibleEnergies_D0, rbm_0_visibleEnergies_WE0, rbm_0_visibleEnergies_WEM0, rbm_0_visibleEnergies_CE2, rbm_0_visibleEnergies_A2, rbm_0_visibleEnergies_Q2);
  input clk;
  input rst;
  //buffer: data - process: load - interface: W
  input rbm_0_data_CE0;
  input [9:0] rbm_0_data_A0;
  input [7:0] rbm_0_data_D0;
  input rbm_0_data_WE0;
  input [7:0] rbm_0_data_WEM0;
  //buffer: data - process: train_rbm - interface: R
  input rbm_0_data_CE2;
  input [9:0] rbm_0_data_A2;
  output [7:0] rbm_0_data_Q2;
  //buffer: data - process: predict_rbm - interface: R
  input rbm_0_data_CE1;
  input [9:0] rbm_0_data_A1;
  output [7:0] rbm_0_data_Q1;

  //buffer: edges - process: train_rbm - interface: W
  input rbm_0_edges_CE0;
  input [15:0] rbm_0_edges_A0;
  input [7:0] rbm_0_edges_D0;
  input rbm_0_edges_WE0;
  input [7:0] rbm_0_edges_WEM0;
  //buffer: edges - process: train_rbm - interface: R
  input rbm_0_edges_CE2;
  input [15:0] rbm_0_edges_A2;
  output [7:0] rbm_0_edges_Q2;
  //buffer: edges - process: predict_rbm - interface: R
  input rbm_0_edges_CE1;
  input [15:0] rbm_0_edges_A1;
  output [7:0] rbm_0_edges_Q1;

  //buffer: hidden_unit - process: train_rbm - interface: W
  input rbm_0_hidden_unit_CE1;
  input [6:0] rbm_0_hidden_unit_A1;
  input rbm_0_hidden_unit_D1;
  input rbm_0_hidden_unit_WE1;
  input rbm_0_hidden_unit_WEM1;
  //buffer: hidden_unit - process: train_rbm - interface: R
  input rbm_0_hidden_unit_CE3;
  input [6:0] rbm_0_hidden_unit_A3;
  output rbm_0_hidden_unit_Q3;
  //buffer: hidden_unit - process: predict_rbm - interface: W
  input rbm_0_hidden_unit_CE0;
  input [6:0] rbm_0_hidden_unit_A0;
  input rbm_0_hidden_unit_D0;
  input rbm_0_hidden_unit_WE0;
  input rbm_0_hidden_unit_WEM0;
  //buffer: hidden_unit - process: predict_rbm - interface: R
  input rbm_0_hidden_unit_CE2;
  input [6:0] rbm_0_hidden_unit_A2;
  output rbm_0_hidden_unit_Q2;

  //buffer: mt - process: train_rbm - interface: W
  input rbm_0_mt_CE0;
  input [9:0] rbm_0_mt_A0;
  input [31:0] rbm_0_mt_D0;
  input rbm_0_mt_WE0;
  input [31:0] rbm_0_mt_WEM0;
  //buffer: mt - process: train_rbm - interface: R
  input rbm_0_mt_CE1;
  input [9:0] rbm_0_mt_A1;
  output [31:0] rbm_0_mt_Q1;

  //buffer: neg - process: train_rbm - interface: W
  input rbm_0_neg_CE0;
  input [15:0] rbm_0_neg_A0;
  input rbm_0_neg_D0;
  input rbm_0_neg_WE0;
  input rbm_0_neg_WEM0;
  //buffer: neg - process: train_rbm - interface: R
  input rbm_0_neg_CE1;
  input [15:0] rbm_0_neg_A1;
  output rbm_0_neg_Q1;

  //buffer: pos - process: train_rbm - interface: W
  input rbm_0_pos_CE0;
  input [15:0] rbm_0_pos_A0;
  input rbm_0_pos_D0;
  input rbm_0_pos_WE0;
  input rbm_0_pos_WEM0;
  //buffer: pos - process: train_rbm - interface: R
  input rbm_0_pos_CE1;
  input [15:0] rbm_0_pos_A1;
  output rbm_0_pos_Q1;

  //buffer: predict_result - process: store - interface: R
  input rbm_0_predict_result_CE1;
  input [6:0] rbm_0_predict_result_A1;
  output [3:0] rbm_0_predict_result_Q1;
  //buffer: predict_result - process: predict_rbm - interface: W
  input rbm_0_predict_result_CE0;
  input [6:0] rbm_0_predict_result_A0;
  input [3:0] rbm_0_predict_result_D0;
  input rbm_0_predict_result_WE0;
  input [3:0] rbm_0_predict_result_WEM0;

  //buffer: visibleEnergies - process: train_rbm - interface: W
  input rbm_0_visibleEnergies_CE1;
  input [2:0] rbm_0_visibleEnergies_A1;
  input [15:0] rbm_0_visibleEnergies_D1;
  input rbm_0_visibleEnergies_WE1;
  input [15:0] rbm_0_visibleEnergies_WEM1;
  //buffer: visibleEnergies - process: train_rbm - interface: R
  input rbm_0_visibleEnergies_CE3;
  input [2:0] rbm_0_visibleEnergies_A3;
  output [15:0] rbm_0_visibleEnergies_Q3;
  //buffer: visibleEnergies - process: predict_rbm - interface: W
  input rbm_0_visibleEnergies_CE0;
  input [2:0] rbm_0_visibleEnergies_A0;
  input [15:0] rbm_0_visibleEnergies_D0;
  input rbm_0_visibleEnergies_WE0;
  input [15:0] rbm_0_visibleEnergies_WEM0;
  //buffer: visibleEnergies - process: predict_rbm - interface: R
  input rbm_0_visibleEnergies_CE2;
  input [2:0] rbm_0_visibleEnergies_A2;
  output [15:0] rbm_0_visibleEnergies_Q2;

  rbm_0_data rbm_0_data_0 (.CLK(clk),
     .rbm_0_data_CE0(rbm_0_data_CE0),
     .rbm_0_data_A0(rbm_0_data_A0),
     .rbm_0_data_D0(rbm_0_data_D0),
     .rbm_0_data_WE0(rbm_0_data_WE0),
     .rbm_0_data_WEM0(rbm_0_data_WEM0),
     .rbm_0_data_CE2(rbm_0_data_CE2),
     .rbm_0_data_A2(rbm_0_data_A2),
     .rbm_0_data_Q2(rbm_0_data_Q2),
     .rbm_0_data_CE1(rbm_0_data_CE1),
     .rbm_0_data_A1(rbm_0_data_A1),
     .rbm_0_data_Q1(rbm_0_data_Q1));

  rbm_0_edges rbm_0_edges_0 (.CLK(clk),
     .rbm_0_edges_CE0(rbm_0_edges_CE0),
     .rbm_0_edges_A0(rbm_0_edges_A0),
     .rbm_0_edges_D0(rbm_0_edges_D0),
     .rbm_0_edges_WE0(rbm_0_edges_WE0),
     .rbm_0_edges_WEM0(rbm_0_edges_WEM0),
     .rbm_0_edges_CE2(rbm_0_edges_CE2),
     .rbm_0_edges_A2(rbm_0_edges_A2),
     .rbm_0_edges_Q2(rbm_0_edges_Q2),
     .rbm_0_edges_CE1(rbm_0_edges_CE1),
     .rbm_0_edges_A1(rbm_0_edges_A1),
     .rbm_0_edges_Q1(rbm_0_edges_Q1));

  rbm_0_hidden_unit rbm_0_hidden_unit_0 (.CLK(clk),
     .rbm_0_hidden_unit_CE1(rbm_0_hidden_unit_CE1),
     .rbm_0_hidden_unit_A1(rbm_0_hidden_unit_A1),
     .rbm_0_hidden_unit_D1(rbm_0_hidden_unit_D1),
     .rbm_0_hidden_unit_WE1(rbm_0_hidden_unit_WE1),
     .rbm_0_hidden_unit_WEM1(rbm_0_hidden_unit_WEM1),
     .rbm_0_hidden_unit_CE3(rbm_0_hidden_unit_CE3),
     .rbm_0_hidden_unit_A3(rbm_0_hidden_unit_A3),
     .rbm_0_hidden_unit_Q3(rbm_0_hidden_unit_Q3),
     .rbm_0_hidden_unit_CE0(rbm_0_hidden_unit_CE0),
     .rbm_0_hidden_unit_A0(rbm_0_hidden_unit_A0),
     .rbm_0_hidden_unit_D0(rbm_0_hidden_unit_D0),
     .rbm_0_hidden_unit_WE0(rbm_0_hidden_unit_WE0),
     .rbm_0_hidden_unit_WEM0(rbm_0_hidden_unit_WEM0),
     .rbm_0_hidden_unit_CE2(rbm_0_hidden_unit_CE2),
     .rbm_0_hidden_unit_A2(rbm_0_hidden_unit_A2),
     .rbm_0_hidden_unit_Q2(rbm_0_hidden_unit_Q2));

  rbm_0_mt rbm_0_mt_0 (.CLK(clk),
     .rbm_0_mt_CE0(rbm_0_mt_CE0),
     .rbm_0_mt_A0(rbm_0_mt_A0),
     .rbm_0_mt_D0(rbm_0_mt_D0),
     .rbm_0_mt_WE0(rbm_0_mt_WE0),
     .rbm_0_mt_WEM0(rbm_0_mt_WEM0),
     .rbm_0_mt_CE1(rbm_0_mt_CE1),
     .rbm_0_mt_A1(rbm_0_mt_A1),
     .rbm_0_mt_Q1(rbm_0_mt_Q1));

  rbm_0_neg rbm_0_neg_0 (.CLK(clk),
     .rbm_0_neg_CE0(rbm_0_neg_CE0),
     .rbm_0_neg_A0(rbm_0_neg_A0),
     .rbm_0_neg_D0(rbm_0_neg_D0),
     .rbm_0_neg_WE0(rbm_0_neg_WE0),
     .rbm_0_neg_WEM0(rbm_0_neg_WEM0),
     .rbm_0_neg_CE1(rbm_0_neg_CE1),
     .rbm_0_neg_A1(rbm_0_neg_A1),
     .rbm_0_neg_Q1(rbm_0_neg_Q1));

  rbm_0_pos rbm_0_pos_0 (.CLK(clk),
     .rbm_0_pos_CE0(rbm_0_pos_CE0),
     .rbm_0_pos_A0(rbm_0_pos_A0),
     .rbm_0_pos_D0(rbm_0_pos_D0),
     .rbm_0_pos_WE0(rbm_0_pos_WE0),
     .rbm_0_pos_WEM0(rbm_0_pos_WEM0),
     .rbm_0_pos_CE1(rbm_0_pos_CE1),
     .rbm_0_pos_A1(rbm_0_pos_A1),
     .rbm_0_pos_Q1(rbm_0_pos_Q1));

  rbm_0_predict_result rbm_0_predict_result_0 (.CLK(clk),
     .rbm_0_predict_result_CE1(rbm_0_predict_result_CE1),
     .rbm_0_predict_result_A1(rbm_0_predict_result_A1),
     .rbm_0_predict_result_Q1(rbm_0_predict_result_Q1),
     .rbm_0_predict_result_CE0(rbm_0_predict_result_CE0),
     .rbm_0_predict_result_A0(rbm_0_predict_result_A0),
     .rbm_0_predict_result_D0(rbm_0_predict_result_D0),
     .rbm_0_predict_result_WE0(rbm_0_predict_result_WE0),
     .rbm_0_predict_result_WEM0(rbm_0_predict_result_WEM0));

  rbm_0_visibleEnergies rbm_0_visibleEnergies_0 (.CLK(clk),
     .rbm_0_visibleEnergies_CE1(rbm_0_visibleEnergies_CE1),
     .rbm_0_visibleEnergies_A1(rbm_0_visibleEnergies_A1),
     .rbm_0_visibleEnergies_D1(rbm_0_visibleEnergies_D1),
     .rbm_0_visibleEnergies_WE1(rbm_0_visibleEnergies_WE1),
     .rbm_0_visibleEnergies_WEM1(rbm_0_visibleEnergies_WEM1),
     .rbm_0_visibleEnergies_CE3(rbm_0_visibleEnergies_CE3),
     .rbm_0_visibleEnergies_A3(rbm_0_visibleEnergies_A3),
     .rbm_0_visibleEnergies_Q3(rbm_0_visibleEnergies_Q3),
     .rbm_0_visibleEnergies_CE0(rbm_0_visibleEnergies_CE0),
     .rbm_0_visibleEnergies_A0(rbm_0_visibleEnergies_A0),
     .rbm_0_visibleEnergies_D0(rbm_0_visibleEnergies_D0),
     .rbm_0_visibleEnergies_WE0(rbm_0_visibleEnergies_WE0),
     .rbm_0_visibleEnergies_WEM0(rbm_0_visibleEnergies_WEM0),
     .rbm_0_visibleEnergies_CE2(rbm_0_visibleEnergies_CE2),
     .rbm_0_visibleEnergies_A2(rbm_0_visibleEnergies_A2),
     .rbm_0_visibleEnergies_Q2(rbm_0_visibleEnergies_Q2));

endmodule

