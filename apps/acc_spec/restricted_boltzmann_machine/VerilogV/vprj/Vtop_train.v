module Vtop(clk,
rst,
conf_done,
conf_num_hidden, 
conf_num_loops, 
conf_num_movies, 
conf_num_testusers, 
conf_num_users, 
conf_num_visible, 
data_in_data, 
data_in_ready, 
data_in_valid, 
data_out_data, 
data_out_ready, 
data_out_valid, 
done, 
rd_grant, 
rd_index, 
rd_length, 
rd_request, 
rst, 
wr_grant, 
wr_index, 
wr_length, 
wr_request
 );

  input clk;
  input conf_done;
  input [31:0] conf_num_hidden;
  input [31:0] conf_num_loops;
  input [31:0] conf_num_movies;
  input [31:0] conf_num_testusers;
  input [31:0] conf_num_users;
  input [31:0] conf_num_visible;
  input [31:0] data_in_data;
  input data_in_valid;
  input data_out_ready;
  input rd_grant;
  input rst;
  input wr_grant;

  output data_in_ready;
  output [31:0] data_out_data;
  output data_out_valid;
  output done;
  output [31:0] rd_index;
  output [31:0] rd_length;
  output rd_request;
  output [31:0] wr_index;
  output [31:0] wr_length;
  output wr_request;

  reg GM_step; // Free variable, and can change in each cycle


// internal connecting wires

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
          .rst(~rst), // it is rstN actually
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


  wire       gm_step = GM_step;

  wire       GM_data_compare;
  wire       GM_data_sel;
  reg        GM_data_rec;
  wire       GM_data_mismatch;
  wire [8:0] GM_data_raddr0;
  wire [7:0] GM_data_rdata0;
  wire [8:0] GM_data_waddr0;
  wire [7:0] GM_data_wdata0;
  wire       GM_data_wen0;


  //wrapper for buffers (data)
  rbm_0_data mem_data(.CLK(clk),
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
          .rbm_0_data_Q2(data_Q2),

    .gm_raddr0(GM_data_raddr0),
    .gm_rdata0(GM_data_rdata0),

    .gm_waddr0(GM_data_waddr0),
    .gm_wen0(GM_data_wen0),
    .gm_wdata0(GM_data_wdata0),

    .gm_step(gm_step),
    .gm_sel(GM_data_sel), // choose which pingpong buffer to write to 
    .gm_compare(GM_data_compare),
    .impl_rec(GM_data_rec),
    .mismatch(GM_data_mismatch),
    .RST(rst)
          );



  wire        GM_edges_compare;
  // no sel
  wire        GM_edges_rec;
  wire        GM_edges_mismatch;
  wire [15:0] GM_edges_raddr0;
  wire [7:0]  GM_edges_rdata0;
  wire [15:0] GM_edges_waddr0;
  wire [7:0]  GM_edges_wdata0;
  wire        GM_edges_wen0;

  //wrapper for buffers (edges)
  rbm_0_edges mem_edges(.CLK(clk),
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
          .rbm_0_edges_Q2(edges_Q2),

    .gm_raddr0(GM_edges_raddr0),
    .gm_rdata0(GM_edges_rdata0),

    .gm_waddr0(GM_edges_waddr0),
    .gm_wen0  (GM_edges_wen0),
    .gm_wdata0(GM_edges_wdata0),

    .gm_step(gm_step),
    .gm_compare(GM_edges_compare),
    .impl_rec(GM_edges_rec),
    .mismatch(GM_edges_mismatch),
    .RST (rst)
          );


  wire        GM_hidden_unit_compare;
  wire        GM_pd_or_tr;
  // no sel
  wire        GM_hidden_unit_rec;
  wire        GM_hidden_unit_mismatch;
  wire [ 6:0] GM_hidden_unit_raddr0;
  wire        GM_hidden_unit_rdata0;
  wire [ 6:0] GM_hidden_unit_waddr0;
  wire        GM_hidden_unit_wdata0;
  wire        GM_hidden_unit_wen0;
  wire [ 6:0] GM_hidden_unit_waddr1;
  wire        GM_hidden_unit_wdata1;
  wire        GM_hidden_unit_wen1;

  //wrapper for buffers (hidden_unit)
  rbm_0_hidden_unit mem_hidden_unit(.CLK(clk),
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
          .rbm_0_hidden_unit_Q3(hidden_unit_Q3),

    .gm_raddr0(GM_hidden_unit_raddr0),
    .gm_rdata0(GM_hidden_unit_rdata0),

    .gm_waddr0(GM_hidden_unit_waddr0),
    .gm_wen0(GM_hidden_unit_wen0),
    .gm_wdata0(GM_hidden_unit_wdata0),

    .gm_waddr1(GM_hidden_unit_waddr1),
    .gm_wen1(GM_hidden_unit_wen1),
    .gm_wdata1(GM_hidden_unit_wdata1),

    .gm_step(gm_step),
    .gm_compare(GM_hidden_unit_compare),
    .impl_rec(GM_hidden_unit_rec),
    .impl_sel(GM_pd_or_tr),
    .mismatch(GM_hidden_unit_mismatch),
    .RST (rst)
          );

  //wrapper for buffers (mt) NC
  rbm_0_mt mem_3(.CLK(clk),
          .rbm_0_mt_CE0(mt_CE0),
          .rbm_0_mt_A0(mt_A0),
          .rbm_0_mt_D0(mt_D0),
          .rbm_0_mt_WE0(mt_WE0),
          .rbm_0_mt_WEM0(mt_WEM0),
          .rbm_0_mt_CE1(mt_CE1),
          .rbm_0_mt_A1(mt_A1),
          .rbm_0_mt_Q1(mt_Q1),
          .RST(rst)
          );

  //wrapper for buffers (neg) NC
  rbm_0_neg mem_4(.CLK(clk),
          .rbm_0_neg_CE0(neg_CE0),
          .rbm_0_neg_A0(neg_A0),
          .rbm_0_neg_D0(neg_D0),
          .rbm_0_neg_WE0(neg_WE0),
          .rbm_0_neg_WEM0(neg_WEM0),
          .rbm_0_neg_CE1(neg_CE1),
          .rbm_0_neg_A1(neg_A1),
          .rbm_0_neg_Q1(neg_Q1),
          .RST(rst)
          );


  wire        GM_pos_compare;
  //wire      =
  // no sel
  wire        GM_pos_rec;
  wire        GM_pos_mismatch;
  wire [15:0] GM_pos_raddr0;
  wire        GM_pos_rdata0;
  wire [15:0] GM_pos_waddr0;
  wire        GM_pos_wdata0;
  wire        GM_pos_wen0;

  //wrapper for buffers (pos)
  rbm_0_pos mem_pos(.CLK(clk),
          .rbm_0_pos_CE0(pos_CE0),
          .rbm_0_pos_A0(pos_A0),
          .rbm_0_pos_D0(pos_D0),
          .rbm_0_pos_WE0(pos_WE0),
          .rbm_0_pos_WEM0(pos_WEM0),
          .rbm_0_pos_CE1(pos_CE1),
          .rbm_0_pos_A1(pos_A1),
          .rbm_0_pos_Q1(pos_Q1),

    .gm_raddr0(GM_pos_raddr0),
    .gm_rdata0(GM_pos_rdata0),

    .gm_waddr0(GM_pos_waddr0),
    .gm_wen0(GM_pos_wen0),
    .gm_wdata0(GM_pos_wdata0),

    .gm_step(gm_step),
    .gm_compare(GM_pos_compare),
    .impl_rec(GM_pos_rec),
    .mismatch(GM_pos_mismatch),
    .RST (rst)
          );

  wire        GM_predict_result_compare;
  //wire      =
  // no sel
  wire        GM_predict_result_rec;
  wire        GM_predict_result_mismatch;
  wire [ 6:0] GM_predict_result_raddr0;
  wire [ 3:0] GM_predict_result_rdata0;
  wire [ 6:0] GM_predict_result_waddr0;
  wire [ 3:0] GM_predict_result_wdata0;
  wire        GM_predict_result_wen0;

  //wrapper for buffers (predict_result)
  rbm_0_predict_result mem_predict_result(.CLK(clk),
          .rbm_0_predict_result_CE0(predict_result_CE0),
          .rbm_0_predict_result_A0(predict_result_A0),
          .rbm_0_predict_result_D0(predict_result_D0),
          .rbm_0_predict_result_WE0(predict_result_WE0),
          .rbm_0_predict_result_WEM0(predict_result_WEM0),
          .rbm_0_predict_result_CE1(predict_result_CE1),
          .rbm_0_predict_result_A1(predict_result_A1),
          .rbm_0_predict_result_Q1(predict_result_Q1),

    .gm_raddr0(GM_predict_result_raddr0),
    .gm_rdata0(GM_predict_result_rdata0),

    .gm_waddr0(GM_predict_result_waddr0),
    .gm_wen0(GM_predict_result_wen0),
    .gm_wdata0(GM_predict_result_wdata0),

    .gm_step(gm_step),
    .gm_compare(GM_predict_result_compare),
    .impl_rec(GM_predict_result_rec),
    .mismatch(GM_predict_result_mismatch),
    .RST (rst)
          );


  wire        GM_visibleEnergies_compare;
  //wire      =
  // no sel
  wire        GM_visibleEnergies_rec;
  wire        GM_visibleEnergies_mismatch;
  wire [ 2:0] GM_visibleEnergies_raddr0;
  wire [15:0] GM_visibleEnergies_rdata0;
  wire [ 2:0] GM_visibleEnergies_waddr0;
  wire [15:0] GM_visibleEnergies_wdata0;
  wire        GM_visibleEnergies_wen0;

  //wrapper for buffers (visibleEnergies)
  rbm_0_visibleEnergies mem_visibleEnergies(.CLK(clk),
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
          .rbm_0_visibleEnergies_Q3(visibleEnergies_Q3),


    .gm_raddr0(GM_visibleEnergies_raddr0),
    .gm_rdata0(GM_visibleEnergies_rdata0),

    .gm_waddr0(GM_visibleEnergies_waddr0),
    .gm_wen0(GM_visibleEnergies_wen0),
    .gm_wdata0(GM_visibleEnergies_wdata0),

    .gm_step(gm_step),
    .gm_compare(GM_visibleEnergies_compare),

    .impl_sel(GM_pd_or_tr),
    .impl_rec(GM_visibleEnergies_rec),
    .mismatch(GM_visibleEnergies_mismatch),

    .RST (rst)

          );




  wire        GM_pow2_compare;
  //wire      =
  // no sel
  wire        GM_pow2_mismatch;
  wire [ 2:0] GM_pow2_raddr0;
  wire [31:0] GM_pow2_rdata0;
  wire [ 2:0] GM_pow2_waddr0;
  wire [31:0] GM_pow2_wdata0;
  wire        GM_pow2_wen0;

pow2_mem mem_pow2(
  .CLK(clk),
  .RST(rst),

  .waddr(GM_pow2_waddr0),
  .wdata(GM_pow2_wdata0),
  .wen(GM_pow2_wen0),

  .raddr(GM_pow2_raddr0),
  .rdata(GM_pow2_rdata0),
  .gm_step(gm_step)

  );

assign GM_pow2_mismatch = ~GM_pow2_compare ? 1'b0 : mem_pow2.mem != acc_0.memwrite_pow2_ln455_q ; //or acc_0.memwrite_pow2_ln351_q


  wire        GM_predict_vector_compare;
  //wire      =
  // no sel
  wire        GM_predict_vector_mismatch;
  wire [ 8:0] GM_predict_vector_raddr0;
  wire        GM_predict_vector_rdata0;
  wire [ 8:0] GM_predict_vector_waddr0;
  wire        GM_predict_vector_wdata0;
  wire        GM_predict_vector_wen0;

predict_vector_mem mem_predict_vector(
  .CLK(clk),
  .RST(rst),

  .waddr(GM_predict_vector_waddr0),
  .wdata(GM_predict_vector_wdata0),
  .wen(GM_predict_vector_wen0),

  .raddr(GM_predict_vector_raddr0),
  .rdata(GM_predict_vector_rdata0),
  .gm_step(gm_step)
  );


assign GM_predict_vector_mismatch = ~GM_predict_vector_compare ? 1'b0 : mem_predict_vector.mem != acc_0.memwrite_rbm_predict_vector_ln481_q ; // ? mux_predict_vector_ln471_0_q


  wire        GM_visible_unit_compare;
  //wire      =
  // no sel
  wire        GM_visible_unit_mismatch;
  wire [ 8:0] GM_visible_unit_raddr0;
  wire        GM_visible_unit_rdata0;
  wire [ 8:0] GM_visible_unit_waddr0;
  wire        GM_visible_unit_wdata0;
  wire        GM_visible_unit_wen0;
  wire [ 8:0] GM_visible_unit_waddr1;
  wire        GM_visible_unit_wdata1;
  wire        GM_visible_unit_wen1;


visible_unit_mem mem_visible_unit(
  .CLK(clk),
  .RST(rst),

  .waddr0(GM_visible_unit_waddr0),
  .wdata0(GM_visible_unit_wdata0),
  .wen0(GM_visible_unit_wen0),

  .waddr1(GM_visible_unit_waddr1),
  .wdata1(GM_visible_unit_wdata1),
  .wen1(GM_visible_unit_wen1),

  .raddr(GM_visible_unit_raddr0),
  .rdata(GM_visible_unit_rdata0),
  .gm_step(gm_step)
  );

assign GM_visible_unit_mismatch = ~GM_visible_unit_compare ? 1'b0 : mem_visible_unit.mem != acc_0. memwrite_rbm_visible_unit_ln365_q ; //or memwrite_rbm_visible_unit_ln365_q


train GM
(
    .conf_done(conf_done),

    .conf_num_hidden(conf_num_hidden),
    .conf_num_loops(conf_num_loops),
    .conf_num_movies(conf_num_movies),
    .conf_num_testusers(conf_num_testusers),
    .conf_num_users(conf_num_users),
    .conf_num_visible(conf_num_visible),
    .data_in(data_in_data),
    .rd_grant(rd_grant),
    .wr_grant(wr_grant),

    // memread
    .visibleEnergies_data_n63(GM_visibleEnergies_raddr0),
    .visibleEnergies_addr_n62(GM_visibleEnergies_rdata0),
    .hidden_unit_data_n101(GM_hidden_unit_rdata0),
    .hidden_unit_addr_n100(GM_hidden_unit_raddr0),
    .edges_data_n107(GM_edges_rdata0),
    .edges_addr_n106(GM_edges_raddr0),
    .data_data_n133(GM_data_rdata0),
    .data_addr_n132(GM_data_raddr0),
    .pos_data_n179(GM_pos_rdata0),
    .pos_addr_n178(GM_pos_raddr0),
    .visible_unit_data_n184(GM_visible_unit_rdata0),
    .visible_unit_addr_n183(GM_visible_unit_raddr0),
    .pow2_data_n243(GM_pow2_rdata0),
    .pow2_addr_n242(GM_pow2_raddr0),

    .edges_addr0(GM_edges_waddr0),
    .edges_data0(GM_edges_wdata0),
    .edges_wen0(GM_edges_wen0),

    .hidden_unit_addr0(GM_hidden_unit_waddr0),
    .hidden_unit_data0(GM_hidden_unit_wdata0),
    .hidden_unit_wen0(GM_hidden_unit_wen0),

    .hidden_unit_addr1(GM_hidden_unit_waddr1),
    .hidden_unit_data1(GM_hidden_unit_wdata1),
    .hidden_unit_wen1(GM_hidden_unit_wen1),

    .visible_unit_addr0(GM_visible_unit_waddr0),
    .visible_unit_data0(GM_visible_unit_wdata0),
    .visible_unit_wen0(GM_visible_unit_wen0),

    .visible_unit_addr1(GM_hidden_unit_waddr1),
    .visible_unit_data1(GM_hidden_unit_wdata1),
    .visible_unit_wen1(GM_hidden_unit_wen1),

    .pos_addr0(GM_pos_waddr0),
    .pos_data0(GM_pos_wdata0),
    .pos_wen0(GM_pos_wen0),

    .pow2_addr0(GM_pow2_waddr0),
    .pow2_data0(GM_pow2_wdata0),
    .pow2_wen0(GM_pow2_wen0),

    .visibleEnergies_addr0(GM_visibleEnergies_waddr0),
    .visibleEnergies_data0(GM_visibleEnergies_wdata0),
    .visibleEnergies_wen0(GM_visibleEnergies_wen0),

    .clk(clk),
    .rst(1'b0),
    .step(GM_step)
);


  
  reg GM_has_step;
  reg GM_has_step_1d;


  wire GM_step_1d = GM_has_step & ~GM_has_step_1d;

  always @(posedge clk) begin
    if(rst)
      GM_has_step <= 1'b0;
    else if(GM_step)
      GM_has_step <= 1'b1;
  end

  always @(posedge clk) begin
    if(rst)
      GM_has_step_1d <= 1'b0;
    else if(GM_step_1d)
      GM_has_step_1d <= 1'b1;
  end
  
  reg nondet_start; // rand
  reg started;
  reg started_1d;
  wire start_1d = started && ~started_1d;
  reg finished;
  reg finish_signal; // = acc_0.state_rbm_0_cmos32soi_rbm_config[2] == 1 ;

  wire finish = started & finish_signal & ~finished;
  wire start =  nondet_start & ~started; // rand one shot

  always @(posedge clk) begin
    if (rst) begin
      started <= 1'b0;
    end
    else if (start) begin
      started <= 1'b1;
    end
  end

  always @(posedge clk) begin
    if(rst)
      started_1d <= 1'b0;
    else 
      started_1d <= started;
  end

  always @(posedge clk) begin
    if (rst) begin
      finished <= 1'b0;
    end
    else if (finish_signal) begin
      finished <= 1'b1;
    end
  end

  wire in_term = (start | started) & ~ (finish | finished);

  assign GM_data_rec = in_term;
  assign GM_predict_result_rec = in_term;
  assign GM_data_compare = finish;
  assign GM_predict_result_compare = finish;



  reg cycle1;
  always @(posedge clk) begin
    if(rst)
      cycle1 <= 1'b1;
    else
      cycle1 <= 1'b0;
  end

  reg[31:0] load_addr0;
  reg[31:0] load_data0;
  reg[31:0] state_to_pc0;
  reg[31:0] load_addr1;
  reg[31:0] load_data1;
  reg[31:0] state_to_pc1;

  always @(posedge clk) begin
    load_addr0 <= load_addr0;
  end

  always @(posedge clk) begin
    load_data0 <= load_data0;
  end
  always @(posedge clk) begin
    state_to_pc0 <= state_to_pc0;
  end

  always @(posedge clk) begin
    load_addr1 <= load_addr1;
  end

  always @(posedge clk) begin
    load_data1 <= load_data1;
  end
  always @(posedge clk) begin
    state_to_pc1 <= state_to_pc1;
  end

  //assign GM_step = (start || started) && ( acc_0.state_rbm_0_cmos32soi_rbm_load_next[2] == 1); 
  

endmodule
    