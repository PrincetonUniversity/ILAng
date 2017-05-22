/**
 * Copyright (c) 2014-2015, Columbia University
 *
 * @author Christian Pilato <pilato@cs.columbia.edu>
 */
module rbm_0_top_cmos32soi_rtl(clk, conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in_data, data_in_ready, data_in_valid, data_out_data, data_out_ready, data_out_valid, done, rd_grant, rd_index, rd_length, rd_request, rst, wr_grant, wr_index, wr_length, wr_request);
  input clk;
  input conf_done;
  input [31:0] conf_num_hidden;
  input [31:0] conf_num_loops;
  input [31:0] conf_num_movies;
  input [31:0] conf_num_testusers;
  input [31:0] conf_num_users;
  input [31:0] conf_num_visible;
  input [31:0] data_in_data;
  output data_in_ready;
  input data_in_valid;
  output [31:0] data_out_data;
  input data_out_ready;
  output data_out_valid;
  output done;
  input rd_grant;
  output [31:0] rd_index;
  output [31:0] rd_length;
  output rd_request;
  input rst;
  input wr_grant;
  output [31:0] wr_index;
  output [31:0] wr_length;
  output wr_request;

  //signals to memories
  wire [9:0] data_A0;
  wire [9:0] data_A1;
  wire [9:0] data_A2;
  wire data_CE0;
  wire data_CE1;
  wire data_CE2;
  wire [7:0] data_D0;
  wire [7:0] data_Q1;
  wire [7:0] data_Q2;
  wire data_WE0;
  wire [15:0] edges_A0;
  wire [15:0] edges_A1;
  wire [15:0] edges_A2;
  wire edges_CE0;
  wire edges_CE1;
  wire edges_CE2;
  wire [7:0] edges_D0;
  wire [7:0] edges_Q1;
  wire [7:0] edges_Q2;
  wire edges_WE0;
  wire [6:0] hidden_unit_A0;
  wire [6:0] hidden_unit_A1;
  wire [6:0] hidden_unit_A2;
  wire [6:0] hidden_unit_A3;
  wire hidden_unit_CE0;
  wire hidden_unit_CE1;
  wire hidden_unit_CE2;
  wire hidden_unit_CE3;
  wire hidden_unit_D0;
  wire hidden_unit_D1;
  wire hidden_unit_Q2;
  wire hidden_unit_Q3;
  wire hidden_unit_WE0;
  wire hidden_unit_WE1;
  wire [9:0] mt_A0;
  wire [9:0] mt_A1;
  wire mt_CE0;
  wire mt_CE1;
  wire [31:0] mt_D0;
  wire [31:0] mt_Q1;
  wire mt_WE0;
  wire [15:0] neg_A0;
  wire [15:0] neg_A1;
  wire neg_CE0;
  wire neg_CE1;
  wire neg_D0;
  wire neg_Q1;
  wire neg_WE0;
  wire [15:0] pos_A0;
  wire [15:0] pos_A1;
  wire pos_CE0;
  wire pos_CE1;
  wire pos_D0;
  wire pos_Q1;
  wire pos_WE0;
  wire [6:0] predict_result_A0;
  wire [6:0] predict_result_A1;
  wire predict_result_CE0;
  wire predict_result_CE1;
  wire [3:0] predict_result_D0;
  wire [3:0] predict_result_Q1;
  wire predict_result_WE0;
  wire [2:0] visibleEnergies_A0;
  wire [2:0] visibleEnergies_A1;
  wire [2:0] visibleEnergies_A2;
  wire [2:0] visibleEnergies_A3;
  wire visibleEnergies_CE0;
  wire visibleEnergies_CE1;
  wire visibleEnergies_CE2;
  wire visibleEnergies_CE3;
  wire [15:0] visibleEnergies_D0;
  wire [15:0] visibleEnergies_D1;
  wire [15:0] visibleEnergies_Q2;
  wire [15:0] visibleEnergies_Q3;
  wire visibleEnergies_WE0;
  wire visibleEnergies_WE1;

  //other signals
  wire [7:0] data_WEM0;
  assign data_WEM0 = {8{1'b1}};
  wire [7:0] edges_WEM0;
  assign edges_WEM0 = {8{1'b1}};
  wire [0:0] hidden_unit_WEM0;
  assign hidden_unit_WEM0 = {1{1'b1}};
  wire [0:0] hidden_unit_WEM1;
  assign hidden_unit_WEM1 = {1{1'b1}};
  wire [31:0] mt_WEM0;
  assign mt_WEM0 = {32{1'b1}};
  wire [0:0] neg_WEM0;
  assign neg_WEM0 = {1{1'b1}};
  wire [0:0] pos_WEM0;
  assign pos_WEM0 = {1{1'b1}};
  wire [3:0] predict_result_WEM0;
  assign predict_result_WEM0 = {4{1'b1}};
  wire [15:0] visibleEnergies_WEM0;
  assign visibleEnergies_WEM0 = {16{1'b1}};
  wire [15:0] visibleEnergies_WEM1;
  assign visibleEnergies_WEM1 = {16{1'b1}};

  //accelerators
  rbm_0_cmos32soi_rtl acc_0(.clk(clk),
          .conf_done(conf_done),
          .conf_num_hidden(conf_num_hidden),
          .conf_num_loops(conf_num_loops),
          .conf_num_movies(conf_num_movies),
          .conf_num_testusers(conf_num_testusers),
          .conf_num_users(conf_num_users),
          .conf_num_visible(conf_num_visible),
          .data_A0(data_A0),
          .data_A1(data_A1),
          .data_A2(data_A2),
          .data_CE0(data_CE0),
          .data_CE1(data_CE1),
          .data_CE2(data_CE2),
          .data_D0(data_D0),
          .data_Q1(data_Q1),
          .data_Q2(data_Q2),
          .data_WE0(data_WE0),
          .data_in_data(data_in_data),
          .data_in_ready(data_in_ready),
          .data_in_valid(data_in_valid),
          .data_out_data(data_out_data),
          .data_out_ready(data_out_ready),
          .data_out_valid(data_out_valid),
          .done(done),
          .edges_A0(edges_A0),
          .edges_A1(edges_A1),
          .edges_A2(edges_A2),
          .edges_CE0(edges_CE0),
          .edges_CE1(edges_CE1),
          .edges_CE2(edges_CE2),
          .edges_D0(edges_D0),
          .edges_Q1(edges_Q1),
          .edges_Q2(edges_Q2),
          .edges_WE0(edges_WE0),
          .hidden_unit_A0(hidden_unit_A0),
          .hidden_unit_A1(hidden_unit_A1),
          .hidden_unit_A2(hidden_unit_A2),
          .hidden_unit_A3(hidden_unit_A3),
          .hidden_unit_CE0(hidden_unit_CE0),
          .hidden_unit_CE1(hidden_unit_CE1),
          .hidden_unit_CE2(hidden_unit_CE2),
          .hidden_unit_CE3(hidden_unit_CE3),
          .hidden_unit_D0(hidden_unit_D0),
          .hidden_unit_D1(hidden_unit_D1),
          .hidden_unit_Q2(hidden_unit_Q2),
          .hidden_unit_Q3(hidden_unit_Q3),
          .hidden_unit_WE0(hidden_unit_WE0),
          .hidden_unit_WE1(hidden_unit_WE1),
          .mt_A0(mt_A0),
          .mt_A1(mt_A1),
          .mt_CE0(mt_CE0),
          .mt_CE1(mt_CE1),
          .mt_D0(mt_D0),
          .mt_Q1(mt_Q1),
          .mt_WE0(mt_WE0),
          .neg_A0(neg_A0),
          .neg_A1(neg_A1),
          .neg_CE0(neg_CE0),
          .neg_CE1(neg_CE1),
          .neg_D0(neg_D0),
          .neg_Q1(neg_Q1),
          .neg_WE0(neg_WE0),
          .pos_A0(pos_A0),
          .pos_A1(pos_A1),
          .pos_CE0(pos_CE0),
          .pos_CE1(pos_CE1),
          .pos_D0(pos_D0),
          .pos_Q1(pos_Q1),
          .pos_WE0(pos_WE0),
          .predict_result_A0(predict_result_A0),
          .predict_result_A1(predict_result_A1),
          .predict_result_CE0(predict_result_CE0),
          .predict_result_CE1(predict_result_CE1),
          .predict_result_D0(predict_result_D0),
          .predict_result_Q1(predict_result_Q1),
          .predict_result_WE0(predict_result_WE0),
          .rd_grant(rd_grant),
          .rd_index(rd_index),
          .rd_length(rd_length),
          .rd_request(rd_request),
          .rst(rst),
          .visibleEnergies_A0(visibleEnergies_A0),
          .visibleEnergies_A1(visibleEnergies_A1),
          .visibleEnergies_A2(visibleEnergies_A2),
          .visibleEnergies_A3(visibleEnergies_A3),
          .visibleEnergies_CE0(visibleEnergies_CE0),
          .visibleEnergies_CE1(visibleEnergies_CE1),
          .visibleEnergies_CE2(visibleEnergies_CE2),
          .visibleEnergies_CE3(visibleEnergies_CE3),
          .visibleEnergies_D0(visibleEnergies_D0),
          .visibleEnergies_D1(visibleEnergies_D1),
          .visibleEnergies_Q2(visibleEnergies_Q2),
          .visibleEnergies_Q3(visibleEnergies_Q3),
          .visibleEnergies_WE0(visibleEnergies_WE0),
          .visibleEnergies_WE1(visibleEnergies_WE1),
          .wr_grant(wr_grant),
          .wr_index(wr_index),
          .wr_length(wr_length),
          .wr_request(wr_request));

  //wrapper for buffers (data)
  rbm_0_data mem_0(.CLK(clk),
          .rbm_0_data_CE0(data_CE0),
          .rbm_0_data_A0(data_A0),
          .rbm_0_data_D0(data_D0),
          .rbm_0_data_WE0(data_WE0),
          .rbm_0_data_WEM0(data_WEM0),
          .rbm_0_data_CE1(data_CE1),
          .rbm_0_data_A1(data_A1),
          .rbm_0_data_Q1(data_Q1),
          .rbm_0_data_CE2(data_CE2),
          .rbm_0_data_A2(data_A2),
          .rbm_0_data_Q2(data_Q2));

  //wrapper for buffers (edges)
  rbm_0_edges mem_1(.CLK(clk),
          .rbm_0_edges_CE0(edges_CE0),
          .rbm_0_edges_A0(edges_A0),
          .rbm_0_edges_D0(edges_D0),
          .rbm_0_edges_WE0(edges_WE0),
          .rbm_0_edges_WEM0(edges_WEM0),
          .rbm_0_edges_CE1(edges_CE1),
          .rbm_0_edges_A1(edges_A1),
          .rbm_0_edges_Q1(edges_Q1),
          .rbm_0_edges_CE2(edges_CE2),
          .rbm_0_edges_A2(edges_A2),
          .rbm_0_edges_Q2(edges_Q2));

  //wrapper for buffers (hidden_unit)
  rbm_0_hidden_unit mem_2(.CLK(clk),
          .rbm_0_hidden_unit_CE0(hidden_unit_CE0),
          .rbm_0_hidden_unit_A0(hidden_unit_A0),
          .rbm_0_hidden_unit_D0(hidden_unit_D0),
          .rbm_0_hidden_unit_WE0(hidden_unit_WE0),
          .rbm_0_hidden_unit_WEM0(hidden_unit_WEM0),
          .rbm_0_hidden_unit_CE1(hidden_unit_CE1),
          .rbm_0_hidden_unit_A1(hidden_unit_A1),
          .rbm_0_hidden_unit_D1(hidden_unit_D1),
          .rbm_0_hidden_unit_WE1(hidden_unit_WE1),
          .rbm_0_hidden_unit_WEM1(hidden_unit_WEM1),
          .rbm_0_hidden_unit_CE2(hidden_unit_CE2),
          .rbm_0_hidden_unit_A2(hidden_unit_A2),
          .rbm_0_hidden_unit_Q2(hidden_unit_Q2),
          .rbm_0_hidden_unit_CE3(hidden_unit_CE3),
          .rbm_0_hidden_unit_A3(hidden_unit_A3),
          .rbm_0_hidden_unit_Q3(hidden_unit_Q3));

  //wrapper for buffers (mt)
  rbm_0_mt mem_3(.CLK(clk),
          .rbm_0_mt_CE0(mt_CE0),
          .rbm_0_mt_A0(mt_A0),
          .rbm_0_mt_D0(mt_D0),
          .rbm_0_mt_WE0(mt_WE0),
          .rbm_0_mt_WEM0(mt_WEM0),
          .rbm_0_mt_CE1(mt_CE1),
          .rbm_0_mt_A1(mt_A1),
          .rbm_0_mt_Q1(mt_Q1));

  //wrapper for buffers (neg)
  rbm_0_neg mem_4(.CLK(clk),
          .rbm_0_neg_CE0(neg_CE0),
          .rbm_0_neg_A0(neg_A0),
          .rbm_0_neg_D0(neg_D0),
          .rbm_0_neg_WE0(neg_WE0),
          .rbm_0_neg_WEM0(neg_WEM0),
          .rbm_0_neg_CE1(neg_CE1),
          .rbm_0_neg_A1(neg_A1),
          .rbm_0_neg_Q1(neg_Q1));

  //wrapper for buffers (pos)
  rbm_0_pos mem_5(.CLK(clk),
          .rbm_0_pos_CE0(pos_CE0),
          .rbm_0_pos_A0(pos_A0),
          .rbm_0_pos_D0(pos_D0),
          .rbm_0_pos_WE0(pos_WE0),
          .rbm_0_pos_WEM0(pos_WEM0),
          .rbm_0_pos_CE1(pos_CE1),
          .rbm_0_pos_A1(pos_A1),
          .rbm_0_pos_Q1(pos_Q1));

  //wrapper for buffers (predict_result)
  rbm_0_predict_result mem_6(.CLK(clk),
          .rbm_0_predict_result_CE0(predict_result_CE0),
          .rbm_0_predict_result_A0(predict_result_A0),
          .rbm_0_predict_result_D0(predict_result_D0),
          .rbm_0_predict_result_WE0(predict_result_WE0),
          .rbm_0_predict_result_WEM0(predict_result_WEM0),
          .rbm_0_predict_result_CE1(predict_result_CE1),
          .rbm_0_predict_result_A1(predict_result_A1),
          .rbm_0_predict_result_Q1(predict_result_Q1));

  //wrapper for buffers (visibleEnergies)
  rbm_0_visibleEnergies mem_7(.CLK(clk),
          .rbm_0_visibleEnergies_CE0(visibleEnergies_CE0),
          .rbm_0_visibleEnergies_A0(visibleEnergies_A0),
          .rbm_0_visibleEnergies_D0(visibleEnergies_D0),
          .rbm_0_visibleEnergies_WE0(visibleEnergies_WE0),
          .rbm_0_visibleEnergies_WEM0(visibleEnergies_WEM0),
          .rbm_0_visibleEnergies_CE1(visibleEnergies_CE1),
          .rbm_0_visibleEnergies_A1(visibleEnergies_A1),
          .rbm_0_visibleEnergies_D1(visibleEnergies_D1),
          .rbm_0_visibleEnergies_WE1(visibleEnergies_WE1),
          .rbm_0_visibleEnergies_WEM1(visibleEnergies_WEM1),
          .rbm_0_visibleEnergies_CE2(visibleEnergies_CE2),
          .rbm_0_visibleEnergies_A2(visibleEnergies_A2),
          .rbm_0_visibleEnergies_Q2(visibleEnergies_Q2),
          .rbm_0_visibleEnergies_CE3(visibleEnergies_CE3),
          .rbm_0_visibleEnergies_A3(visibleEnergies_A3),
          .rbm_0_visibleEnergies_Q3(visibleEnergies_Q3));

endmodule

