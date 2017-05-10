// *****************************************************************************
//                         Cadence C-to-Silicon Compiler
//          Version 14.10-p100  (64 bit), build 50398 Tue, 27 May 2014
// 
// File created on Tue Jun  7 08:13:20 2016
// 
// The code contained herein is generated for Cadences customer and third
// parties authorized by customer.  It may be used in accordance with a
// previously executed license agreement between Cadence and that customer.
// Absolutely no disassembling, decompiling, reverse-translations or
// reverse-engineering of the generated code is allowed.
// 
//*****************************************************************************
module rbm_0_cmos32soi_rtl(clk, rst, rd_grant, wr_grant, conf_done, 
conf_num_hidden, conf_num_visible, conf_num_users, conf_num_loops, 
conf_num_testusers, conf_num_movies, data_in_valid, data_in_data, data_out_ready, 
mt_Q1, pos_Q1, neg_Q1, predict_result_Q1, edges_Q1, edges_Q2, visibleEnergies_Q2, 
visibleEnergies_Q3, data_Q1, data_Q2, hidden_unit_Q2, hidden_unit_Q3, rd_index, 
rd_length, rd_request, wr_index, wr_length, wr_request, done, data_in_ready, 
data_out_valid, data_out_data, mt_CE0, mt_A0, mt_D0, mt_WE0, mt_CE1, mt_A1, 
pos_CE0, pos_A0, pos_D0, pos_WE0, pos_CE1, pos_A1, neg_CE0, neg_A0, neg_D0, 
neg_WE0, neg_CE1, neg_A1, predict_result_CE0, predict_result_A0, 
predict_result_D0, predict_result_WE0, predict_result_CE1, predict_result_A1, 
edges_CE0, edges_A0, edges_D0, edges_WE0, edges_CE1, edges_A1, edges_CE2, 
edges_A2, visibleEnergies_CE0, visibleEnergies_A0, visibleEnergies_D0, 
visibleEnergies_WE0, visibleEnergies_CE1, visibleEnergies_A1, visibleEnergies_D1, 
visibleEnergies_WE1, visibleEnergies_CE2, visibleEnergies_A2, 
visibleEnergies_CE3, visibleEnergies_A3, data_CE0, data_A0, data_D0, data_WE0, 
data_CE1, data_A1, data_CE2, data_A2, hidden_unit_CE0, hidden_unit_A0, 
hidden_unit_D0, hidden_unit_WE0, hidden_unit_CE1, hidden_unit_A1, hidden_unit_D1, 
hidden_unit_WE1, hidden_unit_CE2, hidden_unit_A2, hidden_unit_CE3, 
hidden_unit_A3);
  input clk;
  input rst;
  input rd_grant;
  input wr_grant;
  input conf_done;
  input [31:0] conf_num_hidden;
  input [31:0] conf_num_visible;
  input [31:0] conf_num_users;
  input [31:0] conf_num_loops;
  input [31:0] conf_num_testusers;
  input [31:0] conf_num_movies;
  input data_in_valid;
  input [31:0] data_in_data;
  input data_out_ready;
  input [31:0] mt_Q1;
  input pos_Q1;
  input neg_Q1;
  input [3:0] predict_result_Q1;
  input [7:0] edges_Q1;
  input [7:0] edges_Q2;
  input [15:0] visibleEnergies_Q2;
  input [15:0] visibleEnergies_Q3;
  input [7:0] data_Q1;
  input [7:0] data_Q2;
  input hidden_unit_Q2;
  input hidden_unit_Q3;
  output reg [31:0] rd_index;
  output reg [31:0] rd_length;
  output reg rd_request;
  output reg [31:0] wr_index;
  output reg [31:0] wr_length;
  output reg wr_request;
  output reg done;
  output reg data_in_ready;
  output data_out_valid;
  output reg [31:0] data_out_data;
  output mt_CE0;
  output [9:0] mt_A0;
  output [31:0] mt_D0;
  output mt_WE0;
  output mt_CE1;
  output [9:0] mt_A1;
  output pos_CE0;
  output [15:0] pos_A0;
  output pos_D0;
  output pos_WE0;
  output pos_CE1;
  output [15:0] pos_A1;
  output neg_CE0;
  output [15:0] neg_A0;
  output neg_D0;
  output neg_WE0;
  output neg_CE1;
  output [15:0] neg_A1;
  output predict_result_CE0;
  output [6:0] predict_result_A0;
  output [3:0] predict_result_D0;
  output predict_result_WE0;
  output predict_result_CE1;
  output [6:0] predict_result_A1;
  output edges_CE0;
  output [15:0] edges_A0;
  output [7:0] edges_D0;
  output edges_WE0;
  output edges_CE1;
  output [15:0] edges_A1;
  output edges_CE2;
  output [15:0] edges_A2;
  output visibleEnergies_CE0;
  output [2:0] visibleEnergies_A0;
  output [15:0] visibleEnergies_D0;
  output visibleEnergies_WE0;
  output visibleEnergies_CE1;
  output [2:0] visibleEnergies_A1;
  output [15:0] visibleEnergies_D1;
  output visibleEnergies_WE1;
  output visibleEnergies_CE2;
  output [2:0] visibleEnergies_A2;
  output visibleEnergies_CE3;
  output [2:0] visibleEnergies_A3;
  output data_CE0;
  output [9:0] data_A0;
  output [7:0] data_D0;
  output data_WE0;
  output data_CE1;
  output [9:0] data_A1;
  output data_CE2;
  output [9:0] data_A2;
  output hidden_unit_CE0;
  output [6:0] hidden_unit_A0;
  output hidden_unit_D0;
  output hidden_unit_WE0;
  output hidden_unit_CE1;
  output [6:0] hidden_unit_A1;
  output hidden_unit_D1;
  output hidden_unit_WE1;
  output hidden_unit_CE2;
  output [6:0] hidden_unit_A2;
  output hidden_unit_CE3;
  output [6:0] hidden_unit_A3;
  reg [15:0] num_hidden;
  reg [15:0] num_visible;
  reg [15:0] num_users;
  reg [15:0] num_loops;
  reg [15:0] num_testusers;
  reg [15:0] num_movies;
  reg init_done;
  reg train_input_done;
  reg predict_input_done;
  reg train_start;
  reg train_done;
  reg predict_start;
  reg predict_done;
  reg output_start;
  reg output_done;
  reg data_out_set_valid_curr;
  wire data_out_can_put_sig;
  wire data_out_sync_snd_set_valid_prev;
  wire data_out_sync_snd_reset_valid_prev;
  wire data_out_sync_snd_reset_valid_curr;
  wire data_out_sync_snd_valid_flop;
  wire [6:0] rbm_0_cmos32soi_sigmoid_ln205_z;
  wire [6:0] rbm_0_cmos32soi_sigmoid_ln250_z;
  wire [3:0] rbm_0_cmos32soi_round__ln469_z;
  reg [2:0] state_rbm_0_cmos32soi_rbm_config;
  reg [2:0] state_rbm_0_cmos32soi_rbm_config_next;
  reg [15:0] num_hidden_d;
  reg [15:0] num_loops_d;
  reg [15:0] num_movies_d;
  reg [15:0] num_users_d;
  reg [15:0] num_visible_d;
  reg init_done_d;
  reg [15:0] num_testusers_d;
  reg [15:0] state_rbm_0_cmos32soi_rbm_load;
  reg [15:0] state_rbm_0_cmos32soi_rbm_load_next;
  reg [15:0] read_rbm_num_testusers_ln554_q;
  reg [15:0] read_rbm_num_users_ln555_q;
  reg [15:0] read_rbm_num_visible_ln553_q;
  reg [15:0] read_rbm_num_loops_ln556_q;
  reg [31:0] mul_ln638_q;
  reg ternaryMux_ln629_0_q;
  reg eq_ln629_0_Z_0_tag_0;
  reg [9:0] mult_ln665_q;
  reg [31:0] mux_dma_index_ln637_q;
  reg [15:0] mux_index_ln624_q;
  reg [15:0] mux_loop_count_ln624_q;
  reg [9:0] add_ln669_q;
  reg data_bridge0_rtl_CE_en;
  reg [9:0] data_bridge0_rtl_a;
  reg [7:0] data_bridge0_rtl_d;
  reg [31:0] rd_length_d;
  reg [31:0] rd_index_d;
  reg predict_input_done_d;
  reg train_input_done_d;
  reg rd_request_d;
  reg data_in_ready_d;
  reg [63:0] read_rbm_num_visible_ln553_d;
  reg [31:0] mul_ln638_d;
  reg [1:0] eq_ln629_0_Z_0_tag_d_0;
  reg [9:0] mult_ln665_d;
  reg [15:0] mux_dma_index_ln637_d;
  reg [2:0] mux_dma_index_ln637_1_d_0;
  reg [7:0] mux_dma_index_ln637_19_d_0;
  reg [4:0] mux_dma_index_ln637_27_d_0;
  reg [32:0] mux_index_ln624_d;
  reg [8:0] add_ln669_d;
  reg [38:0] state_rbm_0_cmos32soi_rbm_predict_rbm;
  reg [38:0] state_rbm_0_cmos32soi_rbm_predict_rbm_next;
  reg memread_rbm_hidden_unit_ln405_Q_0_tag_0;
  reg mux_count_ln895_Z_7_tag_0;
  reg lt_ln471_q;
  reg [1:0] add_ln281_reg_0_0;
  reg mux_sum_ln236_14_q;
  reg [8:0] mux_v_ln388_q;
  reg [159:0] memwrite_pow2_ln455_q;
  reg [7:0] add_ln388_1_q;
  reg [500:0] mux_predict_vector_ln471_0_q;
  reg mux_user_ln863_q;
  reg [500:0] memwrite_rbm_predict_vector_ln481_q;
  reg [15:0] read_rbm_num_hidden_ln852_q;
  reg [15:0] read_rbm_num_testusers_ln850_q;
  reg [15:0] read_rbm_num_visible_ln851_q;
  reg [15:0] add_ln238_1_q;
  reg and_ln886_q;
  reg [15:0] add_ln402_1_q;
  reg [14:0] add_ln925_1_q;
  reg [3:0] rbm_0_cmos32soi_round_ln469_round_out_q;
  reg edges_bridge1_rtl_CE_en;
  wire [7:0] edges_bridge1_rtl_Q;
  reg memwrite_rbm_predict_result_ln910_en;
  reg visibleEnergies_bridge2_rtl_CE_en;
  reg [2:0] visibleEnergies_bridge2_rtl_a;
  wire [15:0] visibleEnergies_bridge2_rtl_Q;
  reg ctrlAnd_1_ln402_z;
  reg [6:0] mux_h_ln400_z;
  wire memread_rbm_hidden_unit_ln405_rtl_Q;
  reg ctrlAnd_1_ln238_z;
  reg [9:0] add_ln240_z;
  wire [7:0] memread_rbm_data_ln240_rtl_Q;
  reg hidden_unit_bridge0_rtl_CE_en;
  reg [6:0] hidden_unit_bridge0_rtl_a;
  reg hidden_unit_bridge0_rtl_d;
  reg visibleEnergies_bridge0_rtl_CE_en;
  reg [15:0] visibleEnergies_bridge0_rtl_d;
  reg memread_rbm_hidden_unit_ln405_Q_0_tag_d;
  reg predict_start_d;
  reg predict_done_d;
  reg mux_count_ln895_Z_7_tag_d;
  reg lt_ln471_z;
  reg [63:0] add_ln281_reg_0_d;
  reg [14:0] mux_predict_vector_ln471_0_487_d_0;
  reg [63:0] mux_v_ln388_d;
  reg [63:0] memwrite_pow2_ln455_55_d_0;
  reg [48:0] memwrite_pow2_ln455_119_d_0;
  reg [37:0] mux_predict_vector_ln471_0_62_d_0;
  reg [63:0] mux_predict_vector_ln471_0_100_d_0;
  reg [9:0] mux_predict_vector_ln471_0_101_d_0;
  reg mux_predict_vector_ln471_0_111_d;
  reg [30:0] mux_predict_vector_ln471_0_112_d_0;
  reg [7:0] mux_predict_vector_ln471_0_144_d_0;
  reg [1:0] mux_predict_vector_ln471_0_152_d_0;
  reg [6:0] mux_predict_vector_ln471_0_154_d_0;
  reg [63:0] mux_predict_vector_ln471_0_223_d_0;
  reg [12:0] mux_predict_vector_ln471_0_287_d_0;
  reg [31:0] mux_predict_vector_ln471_0_300_d_0;
  reg [3:0] mux_predict_vector_ln471_0_332_d_0;
  reg [31:0] mux_predict_vector_ln471_0_336_d_0;
  reg mux_predict_vector_ln471_0_368_d;
  reg [1:0] mux_predict_vector_ln471_0_369_d_0;
  reg [1:0] mux_predict_vector_ln471_0_371_d_0;
  reg [16:0] mux_predict_vector_ln471_0_373_d_0;
  reg [15:0] mux_predict_vector_ln471_0_389_d_0;
  reg [15:0] mux_predict_vector_ln471_0_406_d_0;
  reg [6:0] mux_predict_vector_ln471_0_422_d_0;
  reg [9:0] mux_predict_vector_ln471_0_429_d_0;
  reg [5:0] mux_predict_vector_ln471_0_430_d_0;
  reg [1:0] mux_predict_vector_ln471_0_445_d_0;
  reg [13:0] mux_predict_vector_ln471_0_447_d_0;
  reg [2:0] mux_predict_vector_ln471_0_461_d_0;
  reg [9:0] mux_predict_vector_ln471_0_464_d_0;
  reg [6:0] mux_predict_vector_ln471_0_474_d_0;
  reg [5:0] mux_predict_vector_ln471_0_475_d_0;
  reg [63:0] mux_user_ln863_d_0;
  reg [63:0] memwrite_rbm_predict_vector_ln481_63_d_0;
  reg [63:0] memwrite_rbm_predict_vector_ln481_127_d_0;
  reg [63:0] memwrite_rbm_predict_vector_ln481_191_d_0;
  reg [63:0] memwrite_rbm_predict_vector_ln481_255_d_0;
  reg [63:0] memwrite_rbm_predict_vector_ln481_319_d_0;
  reg [63:0] memwrite_rbm_predict_vector_ln481_383_d_0;
  reg [63:0] memwrite_rbm_predict_vector_ln481_447_d_0;
  reg [63:0] read_rbm_num_testusers_ln850_d;
  reg [16:0] add_ln402_1_d;
  reg [4:0] add_ln925_1_10_d_0;
  reg [3:0] rbm_0_cmos32soi_round_ln469_round_out_d;
  reg [15:0] mux_sum_ln236_z;
  reg [31:0] add_ln271_z_0;
  reg [6:0] state_rbm_0_cmos32soi_rbm_store;
  reg [6:0] state_rbm_0_cmos32soi_rbm_store_next;
  reg [31:0] mul_ln971_q;
  reg mux_index_ln951_q;
  reg [15:0] read_rbm_num_movies_ln945_q;
  reg [15:0] read_rbm_num_testusers_ln944_q;
  reg [30:0] add_ln974_1_q;
  reg ctrlAnd_1_ln985_z;
  reg [6:0] mux_i_ln983_z;
  wire [3:0] memread_rbm_predict_result_ln987_rtl_Q;
  reg output_start_d;
  reg [31:0] wr_length_d;
  reg [31:0] wr_index_d;
  reg wr_request_d;
  reg data_out_set_valid_curr_d;
  reg [31:0] data_out_data_d;
  reg output_done_d;
  reg [6:0] mul_ln971_d;
  reg [3:0] mul_ln971_7_d_0;
  reg [20:0] mul_ln971_11_d_0;
  reg [63:0] read_rbm_num_testusers_ln944_d;
  reg done_d;
  reg [94:0] state_rbm_0_cmos32soi_rbm_train_rbm;
  reg [94:0] state_rbm_0_cmos32soi_rbm_train_rbm_next;
  reg memread_rbm_mt_ln116_0_Q_0_tag_0;
  reg memread_rbm_mt_ln116_Q_0_tag_0;
  reg memread_rbm_mt_ln134_0_Q_0_tag_0;
  reg memread_rbm_mt_ln134_Q_0_tag_0;
  reg memread_rbm_mt_ln91_0_Q_0_tag_0;
  reg memread_rbm_mt_ln91_Q_0_tag_0;
  reg memread_rbm_hidden_unit_ln298_Q_0_tag_0;
  reg signed [31:0] mti_signal;
  reg lt_ln51_q;
  reg [10:0] mux_this_ln361_0_2_q;
  reg [17:0] memread_rbm_mt_ln116_0_2_q;
  reg [31:0] memread_pow2_ln359_q;
  reg [8:0] add_ln365_q;
  reg lt_ln356_q;
  reg mux_j_ln356_q;
  reg [1:0] add_ln356_1_q;
  reg [63:0] add_ln281_q;
  reg [63:0] add_ln271_q;
  reg sub_ln196_0_1_q;
  reg [8:0] mux_v_ln282_q;
  reg [159:0] memwrite_pow2_ln351_q;
  reg [7:0] add_ln282_1_q;
  reg [8:0] mux_mti_ln59_0_q;
  reg [63:0] mux_rem_ln58_q;
  reg [500:0] memwrite_rbm_visible_unit_ln365_q;
  reg [500:0] memwrite_rbm_visible_unit_ln369_q;
  reg [9:0] mult_ln195_q;
  reg mux_user_ln745_q;
  reg [30:0] add_ln745_1_q;
  reg and_ln757_q;
  reg mux_current_loop_ln733_q;
  reg [30:0] add_ln836_1_q;
  reg [15:0] read_rbm_num_loops_ln690_q;
  reg [15:0] read_rbm_num_users_ln689_q;
  reg [15:0] read_rbm_num_visible_ln687_q;
  reg [15:0] read_rbm_num_hidden_ln688_q;
  reg [15:0] add_ln713_1_q;
  reg [15:0] add_ln708_1_q;
  reg expand_ln809_q;
  reg Wait_ln782_q;
  reg edges_bridge0_rtl_CE_en;
  reg [7:0] edges_bridge0_rtl_d;
  reg visibleEnergies_bridge3_rtl_CE_en;
  reg [2:0] visibleEnergies_bridge3_rtl_a;
  wire [15:0] visibleEnergies_bridge3_rtl_Q;
  reg ctrlOr_ln803_z;
  reg [15:0] mux_add_ln811_Z_v;
  wire memread_rbm_neg_ln813_rtl_Q;
  wire memread_rbm_pos_ln812_rtl_Q;
  reg hidden_unit_bridge3_rtl_CE_en;
  reg [6:0] hidden_unit_bridge3_rtl_a;
  wire hidden_unit_bridge3_rtl_Q;
  reg visibleEnergies_bridge1_rtl_CE_en;
  reg [15:0] visibleEnergies_bridge1_rtl_d;
  reg hidden_unit_bridge1_rtl_CE_en;
  reg [6:0] hidden_unit_bridge1_rtl_a;
  reg hidden_unit_bridge1_rtl_d;
  reg mt_bridge0_rtl_CE_en;
  reg [9:0] mt_bridge0_rtl_a;
  reg [31:0] mt_bridge0_rtl_d;
  reg edges_bridge2_rtl_CE_en;
  reg [15:0] edges_bridge2_rtl_a;
  wire [7:0] edges_bridge2_rtl_Q;
  reg mt_bridge1_rtl_CE_en;
  reg [9:0] mt_bridge1_rtl_a;
  wire [31:0] mt_bridge1_rtl_Q;
  reg data_bridge1_rtl_CE_en;
  reg [9:0] data_bridge1_rtl_a;
  wire [7:0] data_bridge1_rtl_Q;
  reg memread_rbm_mt_ln116_0_Q_0_tag_d;
  reg memread_rbm_mt_ln116_Q_0_tag_d;
  reg memread_rbm_mt_ln134_0_Q_0_tag_d;
  reg memread_rbm_mt_ln134_Q_0_tag_d;
  reg memread_rbm_mt_ln91_0_Q_0_tag_d;
  reg memread_rbm_mt_ln91_Q_0_tag_d;
  reg memread_rbm_hidden_unit_ln298_Q_0_tag_d;
  reg [31:0] mti_signal_d;
  reg train_done_d;
  reg train_start_d;
  reg lt_ln51_z;
  reg mux_this_ln361_0_2_0_d;
  reg [9:0] mux_this_ln361_0_2_1_d_0;
  reg [28:0] memread_rbm_mt_ln116_0_2_d;
  reg [40:0] add_ln365_d;
  reg [3:0] mux_j_ln356_d_0;
  reg [63:0] add_ln281_d;
  reg add_ln271_11_d;
  reg [1:0] add_ln271_12_d_0;
  reg [1:0] add_ln271_14_d_0;
  reg [4:0] add_ln271_16_d_0;
  reg add_ln271_21_d;
  reg add_ln271_22_d;
  reg add_ln271_23_d;
  reg [30:0] add_ln271_24_d_0;
  reg add_ln271_55_d;
  reg [1:0] add_ln271_56_d_0;
  reg [4:0] add_ln271_58_d_0;
  reg add_ln271_63_d;
  reg sub_ln196_0_1_d;
  reg [63:0] mux_v_ln282_d;
  reg [63:0] memwrite_pow2_ln351_55_d_0;
  reg [48:0] memwrite_pow2_ln351_119_d_0;
  reg mux_mti_ln59_0_0_d;
  reg [6:0] mux_mti_ln59_0_1_d_0;
  reg mux_mti_ln59_0_8_d;
  reg [10:0] mux_rem_ln58_d;
  reg [2:0] mux_rem_ln58_11_d_0;
  reg [6:0] mux_rem_ln58_14_d_0;
  reg [5:0] mux_rem_ln58_15_d_0;
  reg [3:0] mux_rem_ln58_27_d_0;
  reg [2:0] mux_rem_ln58_31_d_0;
  reg [9:0] mux_rem_ln58_34_d_0;
  reg [1:0] mux_rem_ln58_44_d_0;
  reg mux_rem_ln58_46_d;
  reg [1:0] mux_rem_ln58_47_d_0;
  reg [4:0] mux_rem_ln58_49_d_0;
  reg mux_rem_ln58_54_d;
  reg [7:0] mux_rem_ln58_55_d_0;
  reg mux_rem_ln58_63_d;
  reg [3:0] memwrite_rbm_visible_unit_ln365_d;
  reg [1:0] memwrite_rbm_visible_unit_ln365_4_d_0;
  reg [3:0] memwrite_rbm_visible_unit_ln365_6_d_0;
  reg [31:0] memwrite_rbm_visible_unit_ln365_10_d_0;
  reg memwrite_rbm_visible_unit_ln365_42_d;
  reg [1:0] memwrite_rbm_visible_unit_ln365_43_d_0;
  reg [1:0] memwrite_rbm_visible_unit_ln365_45_d_0;
  reg [16:0] memwrite_rbm_visible_unit_ln365_47_d_0;
  reg [15:0] memwrite_rbm_visible_unit_ln365_63_d_0;
  reg [15:0] memwrite_rbm_visible_unit_ln365_80_d_0;
  reg memwrite_rbm_visible_unit_ln365_96_d;
  reg [5:0] memwrite_rbm_visible_unit_ln365_97_d_0;
  reg [9:0] memwrite_rbm_visible_unit_ln365_103_d_0;
  reg [5:0] memwrite_rbm_visible_unit_ln365_104_d_0;
  reg [1:0] memwrite_rbm_visible_unit_ln365_119_d_0;
  reg [18:0] memwrite_rbm_visible_unit_ln365_121_d_0;
  reg memwrite_rbm_visible_unit_ln365_140_d;
  reg [6:0] memwrite_rbm_visible_unit_ln365_141_d_0;
  reg [7:0] memwrite_rbm_visible_unit_ln365_148_d_0;
  reg [24:0] memwrite_rbm_visible_unit_ln365_156_d_0;
  reg memwrite_rbm_visible_unit_ln365_181_d;
  reg memwrite_rbm_visible_unit_ln365_182_d;
  reg [30:0] memwrite_rbm_visible_unit_ln365_183_d_0;
  reg [25:0] memwrite_rbm_visible_unit_ln365_214_d_0;
  reg memwrite_rbm_visible_unit_ln365_240_d;
  reg [22:0] memwrite_rbm_visible_unit_ln365_241_d_0;
  reg memwrite_rbm_visible_unit_ln365_264_d;
  reg memwrite_rbm_visible_unit_ln365_265_d;
  reg memwrite_rbm_visible_unit_ln365_266_d;
  reg memwrite_rbm_visible_unit_ln365_267_d;
  reg [25:0] memwrite_rbm_visible_unit_ln365_268_d_0;
  reg [8:0] memwrite_rbm_visible_unit_ln365_294_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln365_303_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln365_367_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln365_431_d_0;
  reg [5:0] memwrite_rbm_visible_unit_ln365_495_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln369_d;
  reg [63:0] memwrite_rbm_visible_unit_ln369_64_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln369_128_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln369_192_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln369_256_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln369_320_d_0;
  reg [63:0] memwrite_rbm_visible_unit_ln369_384_d_0;
  reg [52:0] memwrite_rbm_visible_unit_ln369_448_d_0;
  reg [41:0] mux_user_ln745_d_0;
  reg [32:0] mux_current_loop_ln733_d_0;
  reg [63:0] read_rbm_num_visible_ln687_d;
  reg [31:0] add_ln708_1_d;
  reg [15:0] mux_sum_ln191_z;

  // synopsys sync_set_reset_local rbm_0_cmos32soi_rbm_config_seq_block rst
  always @(posedge clk) // rbm_0_cmos32soi_rbm_config_sequential
    begin : rbm_0_cmos32soi_rbm_config_seq_block
      if (!rst) // Initialize state and outputs
      begin
        num_hidden <= 16'sh0;
        num_loops <= 16'sh0;
        num_movies <= 16'sh0;
        num_users <= 16'sh0;
        num_visible <= 16'sh0;
        init_done <= 1'sb0;
        num_testusers <= 16'sh0;
        state_rbm_0_cmos32soi_rbm_config <= 3'h1;
      end
      else // Update Q values
      begin
        num_hidden <= num_hidden_d;
        num_loops <= num_loops_d;
        num_movies <= num_movies_d;
        num_users <= num_users_d;
        num_visible <= num_visible_d;
        init_done <= init_done_d;
        num_testusers <= num_testusers_d;
        state_rbm_0_cmos32soi_rbm_config <= 
        state_rbm_0_cmos32soi_rbm_config_next;
      end
    end
  always @(*) begin : rbm_0_cmos32soi_rbm_config_combinational
      reg ctrlAnd_1_ln517_z;
      reg ctrlAnd_0_ln517_z;
      reg write_rbm_num_testusers_ln525_en;
      reg ctrlOr_ln532_z;
      reg ctrlOr_ln517_z;

      state_rbm_0_cmos32soi_rbm_config_next = 3'h0;
      ctrlAnd_1_ln517_z = conf_done & state_rbm_0_cmos32soi_rbm_config[1];
      ctrlAnd_0_ln517_z = !conf_done & state_rbm_0_cmos32soi_rbm_config[1];
      write_rbm_num_testusers_ln525_en = rst & ctrlAnd_1_ln517_z;
      ctrlOr_ln532_z = state_rbm_0_cmos32soi_rbm_config[2] | ctrlAnd_1_ln517_z;
      ctrlOr_ln517_z = ctrlAnd_0_ln517_z | state_rbm_0_cmos32soi_rbm_config[0];
      if (ctrlAnd_1_ln517_z) 
        num_hidden_d = conf_num_hidden[15:0];
      else 
        num_hidden_d = num_hidden;
      if (ctrlAnd_1_ln517_z) 
        num_loops_d = conf_num_loops[15:0];
      else 
        num_loops_d = num_loops;
      if (ctrlAnd_1_ln517_z) 
        num_movies_d = conf_num_movies[15:0];
      else 
        num_movies_d = num_movies;
      if (ctrlAnd_1_ln517_z) 
        num_users_d = conf_num_users[15:0];
      else 
        num_users_d = num_users;
      if (ctrlAnd_1_ln517_z) 
        num_visible_d = conf_num_visible[15:0];
      else 
        num_visible_d = num_visible;
      if (ctrlAnd_1_ln517_z) 
        init_done_d = 1'b1;
      else 
        init_done_d = init_done;
      if (write_rbm_num_testusers_ln525_en) 
        num_testusers_d = conf_num_testusers[15:0];
      else 
        num_testusers_d = num_testusers;
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_config[0]: // Wait_ln514
          state_rbm_0_cmos32soi_rbm_config_next[1] = 1'b1;
        state_rbm_0_cmos32soi_rbm_config[1]: // Wait_ln517
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln517_z: state_rbm_0_cmos32soi_rbm_config_next[1] = 1'b1;
              ctrlOr_ln532_z: state_rbm_0_cmos32soi_rbm_config_next[2] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_config_next = 3'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_config[2]: // Wait_ln534
          state_rbm_0_cmos32soi_rbm_config_next[2] = 1'b1;
        default: // Don't care
          state_rbm_0_cmos32soi_rbm_config_next = 3'hX;
      endcase
    end
  rbm_0_cmos32soi_rbm_data_out_can_put_mod_process 
                                                   rbm_0_cmos32soi_rbm_data_out_can_put_mod_process(
                                                   .data_out_valid(
                                                   data_out_valid), .data_out_ready(
                                                   data_out_ready), .data_out_can_put_sig(
                                                   data_out_can_put_sig));
  rbm_0_cmos32soi_rbm_data_out_sync_snd_back_method 
                                                    rbm_0_cmos32soi_rbm_data_out_sync_snd_back_method(
                                                    .clk(clk), .rst(rst), .data_out_ready(
                                                    data_out_ready), .data_out_valid(
                                                    data_out_valid), .data_out_set_valid_curr(
                                                    data_out_set_valid_curr), .data_out_sync_snd_set_valid_prev(
                                                    data_out_sync_snd_set_valid_prev), 
                                                    .data_out_sync_snd_reset_valid_prev(
                                                    data_out_sync_snd_reset_valid_prev), 
                                                    .data_out_sync_snd_reset_valid_curr(
                                                    data_out_sync_snd_reset_valid_curr), 
                                                    .data_out_sync_snd_valid_flop(
                                                    data_out_sync_snd_valid_flop));
  rbm_0_cmos32soi_rbm_data_out_sync_snd_valid_arb 
                                                  rbm_0_cmos32soi_rbm_data_out_sync_snd_valid_arb(
                                                  .data_out_set_valid_curr(
                                                  data_out_set_valid_curr), .data_out_sync_snd_set_valid_prev(
                                                  data_out_sync_snd_set_valid_prev), 
                                                  .data_out_sync_snd_reset_valid_curr(
                                                  data_out_sync_snd_reset_valid_curr), 
                                                  .data_out_sync_snd_reset_valid_prev(
                                                  data_out_sync_snd_reset_valid_prev), 
                                                  .data_out_sync_snd_valid_flop(
                                                  data_out_sync_snd_valid_flop), 
                                                  .data_out_valid(data_out_valid));
  rbm_0_cmos32soi_identity_sync_write_1002x8m0 data_bridge0(.rtl_CE(
                                               data_bridge0_rtl_CE_en), .rtl_A(
                                               data_bridge0_rtl_a), .rtl_D(
                                               data_bridge0_rtl_d), .rtl_WE(
                                               data_bridge0_rtl_CE_en), .CLK(clk), 
                                               .mem_CE(data_CE0), .mem_A(data_A0), 
                                               .mem_D(data_D0), .mem_WE(data_WE0));
  // synopsys sync_set_reset_local rbm_0_cmos32soi_rbm_load_seq_block rst
  always @(posedge clk) // rbm_0_cmos32soi_rbm_load_sequential
    begin : rbm_0_cmos32soi_rbm_load_seq_block
      if (!rst) // Initialize state and outputs
      begin
        rd_length <= 32'sh0;
        rd_index <= 32'sh0;
        predict_input_done <= 1'sb0;
        train_input_done <= 1'sb0;
        rd_request <= 1'sb0;
        data_in_ready <= 1'sb0;
        read_rbm_num_testusers_ln554_q <= 16'sh0;
        read_rbm_num_users_ln555_q <= 16'sh0;
        read_rbm_num_visible_ln553_q <= 16'sh0;
        read_rbm_num_loops_ln556_q <= 16'sh0;
        mul_ln638_q <= 32'sh0;
        ternaryMux_ln629_0_q <= 1'sb0;
        eq_ln629_0_Z_0_tag_0 <= 1'sb0;
        mult_ln665_q <= 10'sh0;
        mux_dma_index_ln637_q <= 32'sh0;
        mux_index_ln624_q <= 16'sh0;
        mux_loop_count_ln624_q <= 16'sh0;
        add_ln669_q <= 10'sh0;
        state_rbm_0_cmos32soi_rbm_load <= 16'h1;
      end
      else // Update Q values
      begin
        rd_length <= rd_length_d;
        rd_index <= rd_index_d;
        predict_input_done <= predict_input_done_d;
        train_input_done <= train_input_done_d;
        rd_request <= rd_request_d;
        data_in_ready <= data_in_ready_d;
        read_rbm_num_testusers_ln554_q <= read_rbm_num_visible_ln553_d[31:16];
        read_rbm_num_users_ln555_q <= read_rbm_num_visible_ln553_d[47:32];
        read_rbm_num_visible_ln553_q <= read_rbm_num_visible_ln553_d[15:0];
        read_rbm_num_loops_ln556_q <= read_rbm_num_visible_ln553_d[63:48];
        mul_ln638_q <= mul_ln638_d;
        ternaryMux_ln629_0_q <= eq_ln629_0_Z_0_tag_d_0[1];
        eq_ln629_0_Z_0_tag_0 <= eq_ln629_0_Z_0_tag_d_0[0];
        mult_ln665_q <= mult_ln665_d;
        mux_dma_index_ln637_q <= {mux_dma_index_ln637_27_d_0, 
        mux_dma_index_ln637_19_d_0, mux_dma_index_ln637_d[15:1], 
        mux_dma_index_ln637_1_d_0, mux_dma_index_ln637_d[0]};
        mux_index_ln624_q <= mux_index_ln624_d[15:0];
        mux_loop_count_ln624_q <= mux_index_ln624_d[31:16];
        add_ln669_q <= {mux_index_ln624_d[32], add_ln669_d};
        state_rbm_0_cmos32soi_rbm_load <= state_rbm_0_cmos32soi_rbm_load_next;
      end
    end

      reg [16:0] add_ln566_z;
      reg eq_ln569_z;
      reg ctrlOr_ln598_z;
      reg data_bridge0_rtl_d_sel;
      reg [31:0] mul_ln638_z;
      reg [15:0] mux_loop_count_ln598_z;
      reg [15:0] mux_index_ln598_z;
      reg ctrlAnd_1_ln237_z;
      reg ctrlAnd_0_ln237_z;
      reg ctrlAnd_1_ln237_0_z;
      reg ctrlAnd_0_ln237_0_z;
      reg ctrlAnd_1_ln550_z;
      reg ctrlAnd_0_ln550_z;
      reg ctrlAnd_1_ln570_z;
      reg ctrlAnd_0_ln570_z;
      reg ctrlAnd_1_ln575_z;
      reg ctrlAnd_0_ln575_z;
      reg ctrlAnd_1_ln604_z;
      reg ctrlAnd_0_ln604_z;
      reg ctrlAnd_1_ln607_z;
      reg ctrlAnd_0_ln607_z;
      reg ctrlAnd_1_ln614_z;
      reg ctrlAnd_0_ln614_z;
      reg ctrlAnd_1_ln617_z;
      reg ctrlAnd_0_ln617_z;
      reg ctrlAnd_1_ln644_z;
      reg ctrlAnd_0_ln644_z;
      reg ctrlAnd_1_ln649_z;
      reg ctrlAnd_0_ln649_z;
      reg [8:0] mux_i_ln585_z;
      reg [15:0] mux_read_rbm_num_loops_ln556_Z_0_mux_0_v;
      reg [15:0] mux_read_rbm_num_testusers_ln554_Z_0_mux_0_v;
      reg [15:0] mux_read_rbm_num_users_ln555_Z_0_mux_0_v;
      reg [15:0] mux_read_rbm_num_visible_ln553_Z_0_mux_0_v;
      reg [15:0] mux_read_rbm_num_loops_ln556_Z_v;
      reg [15:0] mux_read_rbm_num_testusers_ln554_Z_v;
      reg [15:0] mux_read_rbm_num_users_ln555_Z_v;
      reg [15:0] mux_read_rbm_num_visible_ln553_Z_v;
      reg [8:0] mux_i_0_ln659_z;
      reg [31:0] mux_mul_ln638_Z_v;
      reg [31:0] mux_mul_ln638_Z_0_mux_0_v;
      reg ne_ln600_z;
      reg [15:0] add_ln626_z;
      reg [15:0] add_ln623_z;
      reg data_in_ready_sel_0;
      reg ctrlAnd_1_ln569_z;
      reg ctrlAnd_0_ln569_z;
      reg ctrlOr_ln585_0_z;
      reg ctrlOr_ln607_z;
      reg ctrlOr_ln600_z;
      reg ctrlOr_ln617_z;
      reg rd_request_sel_0;
      reg ctrlOr_ln659_0_z;
      reg eq_ln587_z;
      reg lt_ln585_z;
      reg [8:0] mux_mux_i_ln585_Z_v;
      reg [8:0] add_ln585_z;
      reg [15:0] mux_read_rbm_num_loops_ln556_Z_0_mux_1_v;
      reg [15:0] mux_read_rbm_num_testusers_ln554_Z_0_mux_1_v;
      reg [15:0] mux_read_rbm_num_users_ln555_Z_0_mux_1_v;
      reg [15:0] mux_read_rbm_num_visible_ln553_Z_0_mux_1_v;
      reg [8:0] add_ln659_z;
      reg eq_ln661_z;
      reg lt_ln659_z;
      reg mux_mux_i_0_ln659_Z_0_v;
      reg [9:0] add_ln665_z;
      reg [31:0] mux_mul_ln638_Z_0_mux_1_v;
      reg eq_ln624_z;
      reg ctrlOr_ln569_z;
      reg ctrlOr_ln570_z;
      reg ctrlAnd_1_ln629_z;
      reg ctrlAnd_0_ln629_z;
      reg mux_dma_index_ln637_19_mux_0_sel;
      reg mux_dma_index_ln637_1_mux_0_sel;
      reg mux_dma_index_ln637_27_mux_0_sel;
      reg mux_dma_index_ln637_sel;
      reg if_ln587_z;
      reg if_ln585_z;
      reg [7:0] mux_add_ln585_Z_1_v_0;
      reg [7:0] mux_add_ln659_Z_1_v_0;
      reg if_ln661_z;
      reg if_ln659_z;
      reg [9:0] mux_add_ln665_Z_v;
      reg ctrlAnd_1_ln600_z;
      reg ctrlAnd_0_ln600_z;
      reg ternaryMux_ln624_0_z;
      reg ctrlOr_ln575_z;
      reg ctrlAnd_1_ln643_z;
      reg rd_index_hold;
      reg ctrlAnd_0_ln643_z;
      reg ctrlOr_ln632_z;
      reg and_1_ln587_z;
      reg or_and_0_ln587_Z_0_z;
      reg and_1_ln661_z;
      reg or_and_0_ln661_Z_0_z;
      reg predict_input_done_hold;
      reg ctrlOr_ln614_z;
      reg train_input_done_hold;
      reg ctrlOr_ln604_z;
      reg [15:0] mux_loop_count_ln624_z;
      reg [15:0] mux_index_ln624_z;
      reg ctrlOr_ln643_z;
      reg ctrlOr_ln644_z;
      reg ctrlAnd_1_ln587_z;
      reg ctrlAnd_0_ln587_z;
      reg ctrlAnd_1_ln661_z;
      reg ctrlAnd_0_ln661_z;
      reg [15:0] mux_mux_loop_count_ln624_Z_0_mux_0_v;
      reg [15:0] mux_mux_loop_count_ln624_Z_v;
      reg and_ln653_z;
      reg [15:0] mux_mux_index_ln624_Z_0_mux_0_v;
      reg [15:0] mux_mux_index_ln624_Z_v;
      reg [31:0] mul_ln636_z;
      reg eq_ln629_z;
      reg eq_ln629_0_z;
      reg rd_request_hold;
      reg rd_request_sel;
      reg ctrlOr_ln649_z;
      reg ctrlOr_ln237_0_z;
      reg data_in_ready_hold;
      reg data_in_ready_sel;
      reg ctrlOr_ln237_z;
      reg xor_ln654_z;
      reg [31:0] add_ln638_z;
      reg mux_eq_ln629_0_Z_0_v;
      reg mux_eq_ln629_0_Z_0_v_0;
      reg ternaryMux_ln629_0_z;
      reg add_ln669_sel;
      reg mult_ln665_sel;
      reg mux_index_ln624_sel;
      reg read_rbm_num_visible_ln553_sel;
      reg [9:0] mult_ln665_z;
      reg mux_ternaryMux_ln629_0_Z_0_v;
      reg mux_ternaryMux_ln629_0_Z_0_v_0;
      reg [31:0] mux_dma_index_ln637_z;
      reg [9:0] mux_mult_ln665_Z_0_mux_0_v;
      reg [9:0] mux_mult_ln665_Z_v;
      reg [9:0] add_ln669_z;
      reg [31:0] mux_mux_dma_index_ln637_Z_27_v_1;
      reg [31:0] mux_mux_dma_index_ln637_Z_27_mux_0_v;
      reg [9:0] mux_add_ln669_Z_v;
      reg [9:0] mux_add_ln669_Z_0_mux_0_v;
    
  always @(*) begin : rbm_0_cmos32soi_rbm_load_combinational

      state_rbm_0_cmos32soi_rbm_load_next = 16'h0;
      add_ln566_z = {1'b0, num_movies} + num_movies[15:2];
      eq_ln569_z = num_loops == 16'h0;
      ctrlOr_ln598_z = state_rbm_0_cmos32soi_rbm_load[9] | 
      state_rbm_0_cmos32soi_rbm_load[3];
      data_bridge0_rtl_CE_en = state_rbm_0_cmos32soi_rbm_load[9] | 
      state_rbm_0_cmos32soi_rbm_load[11] | state_rbm_0_cmos32soi_rbm_load[3] | 
      state_rbm_0_cmos32soi_rbm_load[15];
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_load[15]: data_bridge0_rtl_a = {1'b0, 
          add_ln669_q[8:0]};
        state_rbm_0_cmos32soi_rbm_load[3]: data_bridge0_rtl_a = 
          read_rbm_num_visible_ln553_q[9:0];
        state_rbm_0_cmos32soi_rbm_load[11]: data_bridge0_rtl_a = 
          mux_dma_index_ln637_q[18:9];
        state_rbm_0_cmos32soi_rbm_load[9]: data_bridge0_rtl_a = add_ln669_q;
        default: data_bridge0_rtl_a = 10'hX;
      endcase
      data_bridge0_rtl_d_sel = state_rbm_0_cmos32soi_rbm_load[11] | 
      state_rbm_0_cmos32soi_rbm_load[15];
      mul_ln638_z = num_visible * num_users;
      if (state_rbm_0_cmos32soi_rbm_load[3]) 
        mux_loop_count_ln598_z = 16'h0;
      else 
        mux_loop_count_ln598_z = mux_loop_count_ln624_q;
      if (state_rbm_0_cmos32soi_rbm_load[3]) 
        mux_index_ln598_z = 16'h0;
      else 
        mux_index_ln598_z = mux_index_ln624_q;
      ctrlAnd_1_ln237_z = data_in_valid & state_rbm_0_cmos32soi_rbm_load[10];
      ctrlAnd_0_ln237_z = !data_in_valid & state_rbm_0_cmos32soi_rbm_load[10];
      ctrlAnd_1_ln237_0_z = data_in_valid & state_rbm_0_cmos32soi_rbm_load[14];
      ctrlAnd_0_ln237_0_z = !data_in_valid & state_rbm_0_cmos32soi_rbm_load[14];
      ctrlAnd_1_ln550_z = init_done & state_rbm_0_cmos32soi_rbm_load[0];
      ctrlAnd_0_ln550_z = !init_done & state_rbm_0_cmos32soi_rbm_load[0];
      ctrlAnd_1_ln570_z = train_done & state_rbm_0_cmos32soi_rbm_load[1];
      ctrlAnd_0_ln570_z = !train_done & state_rbm_0_cmos32soi_rbm_load[1];
      ctrlAnd_1_ln575_z = rd_grant & state_rbm_0_cmos32soi_rbm_load[2];
      ctrlAnd_0_ln575_z = !rd_grant & state_rbm_0_cmos32soi_rbm_load[2];
      ctrlAnd_1_ln604_z = train_start & state_rbm_0_cmos32soi_rbm_load[4];
      ctrlAnd_0_ln604_z = !train_start & state_rbm_0_cmos32soi_rbm_load[4];
      ctrlAnd_1_ln607_z = !train_start & state_rbm_0_cmos32soi_rbm_load[5];
      ctrlAnd_0_ln607_z = train_start & state_rbm_0_cmos32soi_rbm_load[5];
      ctrlAnd_1_ln614_z = predict_start & state_rbm_0_cmos32soi_rbm_load[12];
      ctrlAnd_0_ln614_z = !predict_start & state_rbm_0_cmos32soi_rbm_load[12];
      ctrlAnd_1_ln617_z = !predict_start & state_rbm_0_cmos32soi_rbm_load[13];
      ctrlAnd_0_ln617_z = predict_start & state_rbm_0_cmos32soi_rbm_load[13];
      ctrlAnd_1_ln644_z = train_done & state_rbm_0_cmos32soi_rbm_load[7];
      ctrlAnd_0_ln644_z = !train_done & state_rbm_0_cmos32soi_rbm_load[7];
      ctrlAnd_1_ln649_z = rd_grant & state_rbm_0_cmos32soi_rbm_load[8];
      ctrlAnd_0_ln649_z = !rd_grant & state_rbm_0_cmos32soi_rbm_load[8];
      case (1'b1)// synopsys parallel_case
        data_bridge0_rtl_d_sel: data_bridge0_rtl_d = mux_dma_index_ln637_q[26:19];
        ctrlOr_ln598_z: data_bridge0_rtl_d = 8'h1;
        default: data_bridge0_rtl_d = 8'hX;
      endcase
      if (state_rbm_0_cmos32soi_rbm_load[2]) 
        mux_i_ln585_z = 9'h0;
      else 
        mux_i_ln585_z = {mux_dma_index_ln637_q[3:1], mux_dma_index_ln637_q[31:27], 
        !add_ln669_q[0]};
      if (state_rbm_0_cmos32soi_rbm_load[1]) 
        mux_read_rbm_num_loops_ln556_Z_0_mux_0_v = read_rbm_num_loops_ln556_q;
      else 
        mux_read_rbm_num_loops_ln556_Z_0_mux_0_v = num_loops;
      if (state_rbm_0_cmos32soi_rbm_load[1]) 
        mux_read_rbm_num_testusers_ln554_Z_0_mux_0_v = 
        read_rbm_num_testusers_ln554_q;
      else 
        mux_read_rbm_num_testusers_ln554_Z_0_mux_0_v = num_testusers;
      if (state_rbm_0_cmos32soi_rbm_load[1]) 
        mux_read_rbm_num_users_ln555_Z_0_mux_0_v = read_rbm_num_users_ln555_q;
      else 
        mux_read_rbm_num_users_ln555_Z_0_mux_0_v = num_users;
      if (state_rbm_0_cmos32soi_rbm_load[1]) 
        mux_read_rbm_num_visible_ln553_Z_0_mux_0_v = 
        read_rbm_num_visible_ln553_q;
      else 
        mux_read_rbm_num_visible_ln553_Z_0_mux_0_v = num_visible;
      if (state_rbm_0_cmos32soi_rbm_load[0]) 
        mux_read_rbm_num_loops_ln556_Z_v = num_loops;
      else 
        mux_read_rbm_num_loops_ln556_Z_v = read_rbm_num_loops_ln556_q;
      if (state_rbm_0_cmos32soi_rbm_load[0]) 
        mux_read_rbm_num_testusers_ln554_Z_v = num_testusers;
      else 
        mux_read_rbm_num_testusers_ln554_Z_v = read_rbm_num_testusers_ln554_q;
      if (state_rbm_0_cmos32soi_rbm_load[0]) 
        mux_read_rbm_num_users_ln555_Z_v = num_users;
      else 
        mux_read_rbm_num_users_ln555_Z_v = read_rbm_num_users_ln555_q;
      if (state_rbm_0_cmos32soi_rbm_load[0]) 
        mux_read_rbm_num_visible_ln553_Z_v = num_visible;
      else 
        mux_read_rbm_num_visible_ln553_Z_v = read_rbm_num_visible_ln553_q;
      if (state_rbm_0_cmos32soi_rbm_load[8]) 
        mux_i_0_ln659_z = 9'h0;
      else 
        mux_i_0_ln659_z = {mux_dma_index_ln637_q[8:1], !mux_dma_index_ln637_q[0]};
      if (state_rbm_0_cmos32soi_rbm_load[0]) 
        mux_mul_ln638_Z_v = mul_ln638_z;
      else 
        mux_mul_ln638_Z_v = mul_ln638_q;
      if (state_rbm_0_cmos32soi_rbm_load[1]) 
        mux_mul_ln638_Z_0_mux_0_v = mul_ln638_q;
      else 
        mux_mul_ln638_Z_0_mux_0_v = mul_ln638_z;
      ne_ln600_z = mux_loop_count_ln598_z != read_rbm_num_loops_ln556_q;
      add_ln626_z = mux_loop_count_ln598_z + 16'h1;
      add_ln623_z = mux_index_ln598_z + 16'h1;
      data_in_ready_sel_0 = ctrlAnd_1_ln237_z | ctrlAnd_1_ln237_0_z;
      ctrlAnd_1_ln569_z = !eq_ln569_z & ctrlAnd_1_ln550_z;
      ctrlAnd_0_ln569_z = eq_ln569_z & ctrlAnd_1_ln550_z;
      ctrlOr_ln585_0_z = state_rbm_0_cmos32soi_rbm_load[15] | ctrlAnd_1_ln575_z;
      ctrlOr_ln607_z = ctrlAnd_0_ln607_z | ctrlAnd_1_ln604_z;
      ctrlOr_ln600_z = ctrlAnd_1_ln617_z | ctrlAnd_1_ln607_z;
      ctrlOr_ln617_z = ctrlAnd_0_ln617_z | ctrlAnd_1_ln614_z;
      rd_request_sel_0 = ctrlAnd_1_ln649_z | ctrlAnd_1_ln575_z;
      ctrlOr_ln659_0_z = state_rbm_0_cmos32soi_rbm_load[11] | ctrlAnd_1_ln649_z;
      eq_ln587_z = {7'h0, mux_i_ln585_z} == read_rbm_num_visible_ln553_q;
      lt_ln585_z = mux_i_ln585_z[8:2] <= 7'h7c;
      if (state_rbm_0_cmos32soi_rbm_load[14]) 
        mux_mux_i_ln585_Z_v = add_ln669_q[8:0];
      else 
        mux_mux_i_ln585_Z_v = mux_i_ln585_z;
      add_ln585_z = mux_i_ln585_z + 9'h1;
      if (state_rbm_0_cmos32soi_rbm_load[2]) 
        mux_read_rbm_num_loops_ln556_Z_0_mux_1_v = read_rbm_num_loops_ln556_q;
      else 
        mux_read_rbm_num_loops_ln556_Z_0_mux_1_v = 
        mux_read_rbm_num_loops_ln556_Z_0_mux_0_v;
      if (state_rbm_0_cmos32soi_rbm_load[2]) 
        mux_read_rbm_num_testusers_ln554_Z_0_mux_1_v = 
        read_rbm_num_testusers_ln554_q;
      else 
        mux_read_rbm_num_testusers_ln554_Z_0_mux_1_v = 
        mux_read_rbm_num_testusers_ln554_Z_0_mux_0_v;
      if (state_rbm_0_cmos32soi_rbm_load[2]) 
        mux_read_rbm_num_users_ln555_Z_0_mux_1_v = read_rbm_num_users_ln555_q;
      else 
        mux_read_rbm_num_users_ln555_Z_0_mux_1_v = 
        mux_read_rbm_num_users_ln555_Z_0_mux_0_v;
      if (state_rbm_0_cmos32soi_rbm_load[2]) 
        mux_read_rbm_num_visible_ln553_Z_0_mux_1_v = 
        read_rbm_num_visible_ln553_q;
      else 
        mux_read_rbm_num_visible_ln553_Z_0_mux_1_v = 
        mux_read_rbm_num_visible_ln553_Z_0_mux_0_v;
      add_ln659_z = mux_i_0_ln659_z + 9'h1;
      eq_ln661_z = {7'h0, mux_i_0_ln659_z} == read_rbm_num_visible_ln553_q;
      lt_ln659_z = mux_i_0_ln659_z[8:2] <= 7'h7c;
      if (state_rbm_0_cmos32soi_rbm_load[10]) 
        mux_mux_i_0_ln659_Z_0_v = mux_dma_index_ln637_q[0];
      else 
        mux_mux_i_0_ln659_Z_0_v = mux_i_0_ln659_z[0];
      add_ln665_z = mult_ln665_q + mux_i_0_ln659_z;
      if (state_rbm_0_cmos32soi_rbm_load[2]) 
        mux_mul_ln638_Z_0_mux_1_v = mul_ln638_q;
      else 
        mux_mul_ln638_Z_0_mux_1_v = mux_mul_ln638_Z_0_mux_0_v;
      eq_ln624_z = add_ln623_z == read_rbm_num_users_ln555_q;
      ctrlOr_ln569_z = ctrlAnd_1_ln569_z | ctrlAnd_1_ln570_z;
      ctrlOr_ln570_z = ctrlAnd_0_ln570_z | ctrlAnd_0_ln569_z;
      ctrlAnd_1_ln629_z = !ternaryMux_ln629_0_q & ctrlOr_ln600_z;
      ctrlAnd_0_ln629_z = ternaryMux_ln629_0_q & ctrlOr_ln600_z;
      mux_dma_index_ln637_19_mux_0_sel = ctrlOr_ln617_z | ctrlOr_ln607_z;
      mux_dma_index_ln637_1_mux_0_sel = ctrlOr_ln617_z | ctrlOr_ln607_z | 
      ctrlAnd_1_ln237_z | ctrlAnd_1_ln237_0_z;
      mux_dma_index_ln637_27_mux_0_sel = ctrlOr_ln617_z | ctrlOr_ln607_z | 
      ctrlAnd_1_ln237_0_z;
      mux_dma_index_ln637_sel = ctrlOr_ln617_z | ctrlOr_ln607_z | 
      ctrlAnd_1_ln237_z;
      if_ln587_z = ~eq_ln587_z;
      if_ln585_z = ~lt_ln585_z;
      if (state_rbm_0_cmos32soi_rbm_load[14]) 
        mux_add_ln585_Z_1_v_0 = {mux_dma_index_ln637_q[3:1], 
        mux_dma_index_ln637_q[31:27]};
      else 
        mux_add_ln585_Z_1_v_0 = add_ln585_z[8:1];
      if (state_rbm_0_cmos32soi_rbm_load[10]) 
        mux_add_ln659_Z_1_v_0 = mux_dma_index_ln637_q[8:1];
      else 
        mux_add_ln659_Z_1_v_0 = add_ln659_z[8:1];
      if_ln661_z = ~eq_ln661_z;
      if_ln659_z = ~lt_ln659_z;
      if (state_rbm_0_cmos32soi_rbm_load[10]) 
        mux_add_ln665_Z_v = mux_dma_index_ln637_q[18:9];
      else 
        mux_add_ln665_Z_v = add_ln665_z;
      ctrlAnd_1_ln600_z = !ne_ln600_z & ctrlOr_ln598_z;
      ctrlAnd_0_ln600_z = ne_ln600_z & ctrlOr_ln598_z;
      ternaryMux_ln624_0_z = eq_ln624_z & ne_ln600_z;
      ctrlOr_ln575_z = ctrlAnd_0_ln575_z | ctrlOr_ln569_z;
      ctrlAnd_1_ln643_z = !eq_ln629_0_Z_0_tag_0 & ctrlAnd_1_ln629_z;
      rd_index_hold = ~(ctrlAnd_1_ln629_z | ctrlAnd_1_ln550_z);
      ctrlAnd_0_ln643_z = eq_ln629_0_Z_0_tag_0 & ctrlAnd_1_ln629_z;
      ctrlOr_ln632_z = state_rbm_0_cmos32soi_rbm_load[6] | ctrlAnd_0_ln629_z;
      and_1_ln587_z = if_ln587_z & lt_ln585_z;
      or_and_0_ln587_Z_0_z = if_ln585_z | eq_ln587_z;
      and_1_ln661_z = if_ln661_z & lt_ln659_z;
      or_and_0_ln661_Z_0_z = if_ln659_z | eq_ln661_z;
      predict_input_done_hold = ~(ctrlAnd_1_ln614_z | ctrlAnd_1_ln600_z);
      ctrlOr_ln614_z = ctrlAnd_0_ln614_z | ctrlAnd_1_ln600_z;
      train_input_done_hold = ~(ctrlAnd_1_ln604_z | ctrlAnd_0_ln600_z);
      ctrlOr_ln604_z = ctrlAnd_0_ln604_z | ctrlAnd_0_ln600_z;
      if (ternaryMux_ln624_0_z) begin
        mux_loop_count_ln624_z = add_ln626_z;
        mux_index_ln624_z = 16'h0;
      end
      else begin
        mux_loop_count_ln624_z = mux_loop_count_ln598_z;
        mux_index_ln624_z = add_ln623_z;
      end
      ctrlOr_ln643_z = ctrlAnd_1_ln643_z | ctrlAnd_1_ln644_z;
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln550_z: rd_length_d = {13'h0, add_ln566_z, num_movies[1:0]};
        ctrlAnd_1_ln629_z: rd_length_d = {13'h0, rd_length[18:0]};
        rd_index_hold: rd_length_d = rd_length;
        default: rd_length_d = 32'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln550_z: rd_index_d = 32'h0;
        ctrlAnd_1_ln629_z: rd_index_d = mux_dma_index_ln637_q;
        rd_index_hold: rd_index_d = rd_index;
        default: rd_index_d = 32'hX;
      endcase
      ctrlOr_ln644_z = ctrlAnd_0_ln644_z | ctrlAnd_0_ln643_z;
      ctrlAnd_1_ln587_z = and_1_ln587_z & ctrlOr_ln585_0_z;
      ctrlAnd_0_ln587_z = or_and_0_ln587_Z_0_z & ctrlOr_ln585_0_z;
      ctrlAnd_1_ln661_z = and_1_ln661_z & ctrlOr_ln659_0_z;
      ctrlAnd_0_ln661_z = or_and_0_ln661_Z_0_z & ctrlOr_ln659_0_z;
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln600_z: predict_input_done_d = 1'b1;
        ctrlAnd_1_ln614_z: predict_input_done_d = 1'b0;
        predict_input_done_hold: predict_input_done_d = predict_input_done;
        default: predict_input_done_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln600_z: train_input_done_d = 1'b1;
        ctrlAnd_1_ln604_z: train_input_done_d = 1'b0;
        train_input_done_hold: train_input_done_d = train_input_done;
        default: train_input_done_d = 1'bX;
      endcase
      if (state_rbm_0_cmos32soi_rbm_load[4]) 
        mux_mux_loop_count_ln624_Z_0_mux_0_v = mux_loop_count_ln624_q;
      else 
        mux_mux_loop_count_ln624_Z_0_mux_0_v = mux_loop_count_ln624_z;
      if (state_rbm_0_cmos32soi_rbm_load[12]) 
        mux_mux_loop_count_ln624_Z_v = mux_loop_count_ln624_q;
      else 
        mux_mux_loop_count_ln624_Z_v = mux_loop_count_ln624_z;
      and_ln653_z = read_rbm_num_users_ln555_q[0] & mux_loop_count_ln624_z[0];
      if (state_rbm_0_cmos32soi_rbm_load[4]) 
        mux_mux_index_ln624_Z_0_mux_0_v = mux_index_ln624_q;
      else 
        mux_mux_index_ln624_Z_0_mux_0_v = mux_index_ln624_z;
      if (state_rbm_0_cmos32soi_rbm_load[12]) 
        mux_mux_index_ln624_Z_v = mux_index_ln624_q;
      else 
        mux_mux_index_ln624_Z_v = mux_index_ln624_z;
      mul_ln636_z = read_rbm_num_visible_ln553_q * mux_index_ln624_z;
      eq_ln629_z = mux_index_ln624_z == read_rbm_num_testusers_ln554_q;
      eq_ln629_0_z = mux_loop_count_ln624_z == read_rbm_num_loops_ln556_q;
      rd_request_hold = ~(ctrlOr_ln643_z | ctrlOr_ln569_z | ctrlAnd_1_ln649_z | 
      ctrlAnd_1_ln575_z);
      rd_request_sel = ctrlOr_ln643_z | ctrlOr_ln569_z;
      ctrlOr_ln649_z = ctrlAnd_0_ln649_z | ctrlOr_ln643_z;
      ctrlOr_ln237_0_z = ctrlAnd_0_ln237_0_z | ctrlAnd_1_ln587_z;
      data_in_ready_hold = ~(ctrlAnd_1_ln661_z | ctrlAnd_1_ln587_z | 
      ctrlAnd_1_ln237_z | ctrlAnd_1_ln237_0_z);
      data_in_ready_sel = ctrlAnd_1_ln661_z | ctrlAnd_1_ln587_z;
      ctrlOr_ln237_z = ctrlAnd_0_ln237_z | ctrlAnd_1_ln661_z;
      xor_ln654_z = mux_index_ln624_z[0] ^ and_ln653_z;
      add_ln638_z = mul_ln636_z + mul_ln638_q;
      if (state_rbm_0_cmos32soi_rbm_load[12]) 
        mux_eq_ln629_0_Z_0_v = eq_ln629_0_Z_0_tag_0;
      else 
        mux_eq_ln629_0_Z_0_v = eq_ln629_0_z;
      if (state_rbm_0_cmos32soi_rbm_load[4]) 
        mux_eq_ln629_0_Z_0_v_0 = eq_ln629_0_Z_0_tag_0;
      else 
        mux_eq_ln629_0_Z_0_v_0 = eq_ln629_0_z;
      ternaryMux_ln629_0_z = eq_ln629_z & eq_ln629_0_z;
      case (1'b1)// synopsys parallel_case
        rd_request_sel: rd_request_d = 1'b1;
        rd_request_sel_0: rd_request_d = 1'b0;
        rd_request_hold: rd_request_d = rd_request;
        default: rd_request_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        data_in_ready_sel: data_in_ready_d = 1'b1;
        data_in_ready_sel_0: data_in_ready_d = 1'b0;
        data_in_ready_hold: data_in_ready_d = data_in_ready;
        default: data_in_ready_d = 1'bX;
      endcase
      add_ln669_sel = ctrlOr_ln649_z | ctrlOr_ln644_z | ctrlOr_ln617_z | 
      ctrlOr_ln607_z | ctrlOr_ln237_z | ctrlAnd_1_ln237_z | ctrlAnd_1_ln237_0_z | 
      ctrlAnd_0_ln661_z;
      mult_ln665_sel = ctrlOr_ln649_z | ctrlOr_ln644_z | ctrlOr_ln617_z | 
      ctrlOr_ln607_z | ctrlOr_ln237_z | ctrlAnd_1_ln237_z;
      mux_index_ln624_sel = ctrlOr_ln649_z | ctrlOr_ln644_z | ctrlOr_ln617_z | 
      ctrlOr_ln607_z | ctrlOr_ln237_z | ctrlAnd_1_ln237_z | ctrlAnd_0_ln661_z;
      read_rbm_num_visible_ln553_sel = ctrlOr_ln649_z | ctrlOr_ln644_z | 
      ctrlOr_ln617_z | ctrlOr_ln614_z | ctrlOr_ln607_z | ctrlOr_ln604_z | 
      ctrlOr_ln237_z | ctrlOr_ln237_0_z | ctrlAnd_1_ln237_z | 
      ctrlAnd_1_ln237_0_z | ctrlAnd_0_ln661_z | ctrlAnd_0_ln587_z;
      mult_ln665_z = xor_ln654_z * 9'h1f5;
      if (state_rbm_0_cmos32soi_rbm_load[12]) 
        mux_ternaryMux_ln629_0_Z_0_v = ternaryMux_ln629_0_q;
      else 
        mux_ternaryMux_ln629_0_Z_0_v = ternaryMux_ln629_0_z;
      if (state_rbm_0_cmos32soi_rbm_load[4]) 
        mux_ternaryMux_ln629_0_Z_0_v_0 = ternaryMux_ln629_0_q;
      else 
        mux_ternaryMux_ln629_0_Z_0_v_0 = ternaryMux_ln629_0_z;
      if (eq_ln629_0_z) 
        mux_dma_index_ln637_z = add_ln638_z;
      else 
        mux_dma_index_ln637_z = mul_ln636_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln570_z: read_rbm_num_visible_ln553_d = {
          mux_read_rbm_num_loops_ln556_Z_v, mux_read_rbm_num_users_ln555_Z_v, 
          mux_read_rbm_num_testusers_ln554_Z_v, 
          mux_read_rbm_num_visible_ln553_Z_v};
        ctrlOr_ln575_z: read_rbm_num_visible_ln553_d = {
          mux_read_rbm_num_loops_ln556_Z_0_mux_1_v, 
          mux_read_rbm_num_users_ln555_Z_0_mux_1_v, 
          mux_read_rbm_num_testusers_ln554_Z_0_mux_1_v, 
          mux_read_rbm_num_visible_ln553_Z_0_mux_1_v};
        read_rbm_num_visible_ln553_sel: read_rbm_num_visible_ln553_d = {
          read_rbm_num_loops_ln556_q, read_rbm_num_users_ln555_q, 
          read_rbm_num_testusers_ln554_q, read_rbm_num_visible_ln553_q};
        default: read_rbm_num_visible_ln553_d = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln570_z: mul_ln638_d = mux_mul_ln638_Z_v;
        ctrlOr_ln575_z: mul_ln638_d = mux_mul_ln638_Z_0_mux_1_v;
        read_rbm_num_visible_ln553_sel: mul_ln638_d = mul_ln638_q;
        default: mul_ln638_d = 32'hX;
      endcase
      if (state_rbm_0_cmos32soi_rbm_load[4]) 
        mux_mult_ln665_Z_0_mux_0_v = mult_ln665_q;
      else 
        mux_mult_ln665_Z_0_mux_0_v = mult_ln665_z;
      if (state_rbm_0_cmos32soi_rbm_load[12]) 
        mux_mult_ln665_Z_v = mult_ln665_q;
      else 
        mux_mult_ln665_Z_v = mult_ln665_z;
      add_ln669_z = read_rbm_num_visible_ln553_q[9:0] + mult_ln665_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln614_z: eq_ln629_0_Z_0_tag_d_0 = {mux_ternaryMux_ln629_0_Z_0_v, 
          mux_eq_ln629_0_Z_0_v};
        mux_dma_index_ln637_19_mux_0_sel: eq_ln629_0_Z_0_tag_d_0 = {
          ternaryMux_ln629_0_q, eq_ln629_0_Z_0_tag_0};
        ctrlOr_ln604_z: eq_ln629_0_Z_0_tag_d_0 = {mux_ternaryMux_ln629_0_Z_0_v_0, 
          mux_eq_ln629_0_Z_0_v_0};
        default: eq_ln629_0_Z_0_tag_d_0 = 2'hX;
      endcase
      if (state_rbm_0_cmos32soi_rbm_load[12]) 
        mux_mux_dma_index_ln637_Z_27_v_1 = {mux_dma_index_ln637_q[18:4], 
        mux_dma_index_ln637_q[0], mux_dma_index_ln637_q[26:19], 
        mux_dma_index_ln637_q[3:1], mux_dma_index_ln637_q[31:27]};
      else 
        mux_mux_dma_index_ln637_Z_27_v_1 = {mux_dma_index_ln637_z[18:4], 
        mux_dma_index_ln637_z[0], mux_dma_index_ln637_z[26:19], 
        mux_dma_index_ln637_z[3:1], mux_dma_index_ln637_z[31:27]};
      if (state_rbm_0_cmos32soi_rbm_load[4]) 
        mux_mux_dma_index_ln637_Z_27_mux_0_v = {mux_dma_index_ln637_q[18:4], 
        mux_dma_index_ln637_q[0], mux_dma_index_ln637_q[26:19], 
        mux_dma_index_ln637_q[3:1], mux_dma_index_ln637_q[31:27]};
      else 
        mux_mux_dma_index_ln637_Z_27_mux_0_v = {mux_dma_index_ln637_z[18:4], 
        mux_dma_index_ln637_z[0], mux_dma_index_ln637_z[26:19], 
        mux_dma_index_ln637_z[3:1], mux_dma_index_ln637_z[31:27]};
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln614_z: mult_ln665_d = mux_mult_ln665_Z_v;
        mult_ln665_sel: mult_ln665_d = mult_ln665_q;
        ctrlOr_ln604_z: mult_ln665_d = mux_mult_ln665_Z_0_mux_0_v;
        default: mult_ln665_d = 10'hX;
      endcase
      if (state_rbm_0_cmos32soi_rbm_load[12]) 
        mux_add_ln669_Z_v = add_ln669_q;
      else 
        mux_add_ln669_Z_v = add_ln669_z;
      if (state_rbm_0_cmos32soi_rbm_load[4]) 
        mux_add_ln669_Z_0_mux_0_v = add_ln669_q;
      else 
        mux_add_ln669_Z_0_mux_0_v = add_ln669_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln237_0_z: mux_dma_index_ln637_1_d_0 = mux_add_ln585_Z_1_v_0[7:5];
        mux_dma_index_ln637_1_mux_0_sel: mux_dma_index_ln637_1_d_0 = 
          mux_dma_index_ln637_q[3:1];
        ctrlOr_ln614_z: mux_dma_index_ln637_1_d_0 = 
          mux_mux_dma_index_ln637_Z_27_v_1[7:5];
        ctrlOr_ln604_z: mux_dma_index_ln637_1_d_0 = 
          mux_mux_dma_index_ln637_Z_27_mux_0_v[7:5];
        ctrlOr_ln237_z: mux_dma_index_ln637_1_d_0 = mux_add_ln659_Z_1_v_0[2:0];
        default: mux_dma_index_ln637_1_d_0 = 3'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln237_0_z: mux_dma_index_ln637_27_d_0 = mux_add_ln585_Z_1_v_0[4:0];
        mux_dma_index_ln637_27_mux_0_sel: mux_dma_index_ln637_27_d_0 = 
          mux_dma_index_ln637_q[31:27];
        ctrlOr_ln614_z: mux_dma_index_ln637_27_d_0 = 
          mux_mux_dma_index_ln637_Z_27_v_1[4:0];
        ctrlOr_ln604_z: mux_dma_index_ln637_27_d_0 = 
          mux_mux_dma_index_ln637_Z_27_mux_0_v[4:0];
        default: mux_dma_index_ln637_27_d_0 = 5'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln614_z: mux_dma_index_ln637_d = mux_mux_dma_index_ln637_Z_27_v_1
          [31:16];
        mux_dma_index_ln637_sel: mux_dma_index_ln637_d = {mux_dma_index_ln637_q[
          18:4], mux_dma_index_ln637_q[0]};
        ctrlOr_ln604_z: mux_dma_index_ln637_d = 
          mux_mux_dma_index_ln637_Z_27_mux_0_v[31:16];
        ctrlOr_ln237_z: mux_dma_index_ln637_d = {mux_add_ln665_Z_v, 
          mux_add_ln659_Z_1_v_0[7:3], mux_mux_i_0_ln659_Z_0_v};
        default: mux_dma_index_ln637_d = 16'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        data_in_ready_sel_0: mux_dma_index_ln637_19_d_0 = data_in_data[7:0];
        ctrlOr_ln614_z: mux_dma_index_ln637_19_d_0 = 
          mux_mux_dma_index_ln637_Z_27_v_1[15:8];
        mux_dma_index_ln637_19_mux_0_sel: mux_dma_index_ln637_19_d_0 = 
          mux_dma_index_ln637_q[26:19];
        ctrlOr_ln604_z: mux_dma_index_ln637_19_d_0 = 
          mux_mux_dma_index_ln637_Z_27_mux_0_v[15:8];
        default: mux_dma_index_ln637_19_d_0 = 8'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln614_z: mux_index_ln624_d = {mux_add_ln669_Z_v[9], 
          mux_mux_loop_count_ln624_Z_v, mux_mux_index_ln624_Z_v};
        mux_index_ln624_sel: mux_index_ln624_d = {add_ln669_q[9], 
          mux_loop_count_ln624_q, mux_index_ln624_q};
        ctrlOr_ln604_z: mux_index_ln624_d = {mux_add_ln669_Z_0_mux_0_v[9], 
          mux_mux_loop_count_ln624_Z_0_mux_0_v, mux_mux_index_ln624_Z_0_mux_0_v};
        default: mux_index_ln624_d = 33'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln237_0_z: add_ln669_d = mux_mux_i_ln585_Z_v;
        add_ln669_sel: add_ln669_d = add_ln669_q[8:0];
        ctrlOr_ln614_z: add_ln669_d = mux_add_ln669_Z_v[8:0];
        ctrlOr_ln604_z: add_ln669_d = mux_add_ln669_Z_0_mux_0_v[8:0];
        default: add_ln669_d = 9'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_load[0]: // Wait_ln550
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln550_z: state_rbm_0_cmos32soi_rbm_load_next[0] = 1'b1;
              ctrlOr_ln570_z: state_rbm_0_cmos32soi_rbm_load_next[1] = 1'b1;
              ctrlOr_ln575_z: state_rbm_0_cmos32soi_rbm_load_next[2] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[1]: // Wait_ln570
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln570_z: state_rbm_0_cmos32soi_rbm_load_next[1] = 1'b1;
              ctrlOr_ln575_z: state_rbm_0_cmos32soi_rbm_load_next[2] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[2]: // Wait_ln575
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln575_z: state_rbm_0_cmos32soi_rbm_load_next[2] = 1'b1;
              ctrlAnd_0_ln587_z: state_rbm_0_cmos32soi_rbm_load_next[3] = 1'b1;
              ctrlOr_ln237_0_z: state_rbm_0_cmos32soi_rbm_load_next[14] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[3]: // Wait_ln594
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln604_z: state_rbm_0_cmos32soi_rbm_load_next[4] = 1'b1;
              ctrlOr_ln614_z: state_rbm_0_cmos32soi_rbm_load_next[12] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[4]: // Wait_ln604
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln604_z: state_rbm_0_cmos32soi_rbm_load_next[4] = 1'b1;
              ctrlOr_ln607_z: state_rbm_0_cmos32soi_rbm_load_next[5] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[5]: // Wait_ln607
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln607_z: state_rbm_0_cmos32soi_rbm_load_next[5] = 1'b1;
              ctrlOr_ln632_z: state_rbm_0_cmos32soi_rbm_load_next[6] = 1'b1;
              ctrlOr_ln644_z: state_rbm_0_cmos32soi_rbm_load_next[7] = 1'b1;
              ctrlOr_ln649_z: state_rbm_0_cmos32soi_rbm_load_next[8] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[6]: // Wait_ln632
          state_rbm_0_cmos32soi_rbm_load_next[6] = 1'b1;
        state_rbm_0_cmos32soi_rbm_load[7]: // Wait_ln644
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln644_z: state_rbm_0_cmos32soi_rbm_load_next[7] = 1'b1;
              ctrlOr_ln649_z: state_rbm_0_cmos32soi_rbm_load_next[8] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[8]: // Wait_ln649
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln649_z: state_rbm_0_cmos32soi_rbm_load_next[8] = 1'b1;
              ctrlAnd_0_ln661_z: state_rbm_0_cmos32soi_rbm_load_next[9] = 1'b1;
              ctrlOr_ln237_z: state_rbm_0_cmos32soi_rbm_load_next[10] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[9]: // Wait_ln668
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln604_z: state_rbm_0_cmos32soi_rbm_load_next[4] = 1'b1;
              ctrlOr_ln614_z: state_rbm_0_cmos32soi_rbm_load_next[12] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[10]: // Wait_ln237
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln237_z: state_rbm_0_cmos32soi_rbm_load_next[10] = 1'b1;
              ctrlAnd_1_ln237_z: state_rbm_0_cmos32soi_rbm_load_next[11] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[11]: // Wait_ln664
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln661_z: state_rbm_0_cmos32soi_rbm_load_next[9] = 1'b1;
              ctrlOr_ln237_z: state_rbm_0_cmos32soi_rbm_load_next[10] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[12]: // Wait_ln614
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln614_z: state_rbm_0_cmos32soi_rbm_load_next[12] = 1'b1;
              ctrlOr_ln617_z: state_rbm_0_cmos32soi_rbm_load_next[13] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[13]: // Wait_ln617
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln617_z: state_rbm_0_cmos32soi_rbm_load_next[13] = 1'b1;
              ctrlOr_ln632_z: state_rbm_0_cmos32soi_rbm_load_next[6] = 1'b1;
              ctrlOr_ln644_z: state_rbm_0_cmos32soi_rbm_load_next[7] = 1'b1;
              ctrlOr_ln649_z: state_rbm_0_cmos32soi_rbm_load_next[8] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[14]: // Wait_ln237_0
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln237_0_z: state_rbm_0_cmos32soi_rbm_load_next[14] = 1'b1;
              ctrlAnd_1_ln237_0_z: state_rbm_0_cmos32soi_rbm_load_next[15] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_load[15]: // Wait_ln590
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln587_z: state_rbm_0_cmos32soi_rbm_load_next[3] = 1'b1;
              ctrlOr_ln237_0_z: state_rbm_0_cmos32soi_rbm_load_next[14] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
            endcase
          end
        default: // Don't care
          state_rbm_0_cmos32soi_rbm_load_next = 16'hX;
      endcase
    end
  rbm_0_cmos32soi_identity_sync_read_50601x8m0 edges_bridge1(.rtl_CE(
                                               edges_bridge1_rtl_CE_en), .rtl_A(
                                               mux_predict_vector_ln471_0_q[444:
                                               429]), .mem_Q(edges_Q1), .CLK(clk), 
                                               .mem_CE(edges_CE1), .mem_A(
                                               edges_A1), .rtl_Q(
                                               edges_bridge1_rtl_Q));
  rbm_0_cmos32soi_identity_sync_write_128x4m0 predict_result_bridge0(.rtl_CE(
                                              memwrite_rbm_predict_result_ln910_en), 
                                              .rtl_A(
                                              mux_predict_vector_ln471_0_q[127:
                                              121]), .rtl_D(
                                              mux_predict_vector_ln471_0_q[151:
                                              148]), .rtl_WE(
                                              memwrite_rbm_predict_result_ln910_en), 
                                              .CLK(clk), .mem_CE(
                                              predict_result_CE0), .mem_A(
                                              predict_result_A0), .mem_D(
                                              predict_result_D0), .mem_WE(
                                              predict_result_WE0));
  rbm_0_cmos32soi_identity_sync_read_5x16m0 visibleEnergies_bridge2(.rtl_CE(
                                            visibleEnergies_bridge2_rtl_CE_en), 
                                            .rtl_A(visibleEnergies_bridge2_rtl_a), 
                                            .mem_Q(visibleEnergies_Q2), .CLK(clk), 
                                            .mem_CE(visibleEnergies_CE2), .mem_A(
                                            visibleEnergies_A2), .rtl_Q(
                                            visibleEnergies_bridge2_rtl_Q));
  rbm_0_cmos32soi_identity_sync_read_101x1m0 hidden_unit_bridge2(.rtl_CE(
                                             ctrlAnd_1_ln402_z), .rtl_A(
                                             mux_h_ln400_z), .mem_Q(
                                             hidden_unit_Q2), .CLK(clk), .mem_CE(
                                             hidden_unit_CE2), .mem_A(
                                             hidden_unit_A2), .rtl_Q(
                                             memread_rbm_hidden_unit_ln405_rtl_Q));
  rbm_0_cmos32soi_identity_sync_read_1002x8m0 data_bridge2(.rtl_CE(
                                              ctrlAnd_1_ln238_z), .rtl_A(
                                              add_ln240_z), .mem_Q(data_Q2), .CLK(
                                              clk), .mem_CE(data_CE2), .mem_A(
                                              data_A2), .rtl_Q(
                                              memread_rbm_data_ln240_rtl_Q));
  rbm_0_cmos32soi_identity_sync_write_101x1m0 hidden_unit_bridge0(.rtl_CE(
                                              hidden_unit_bridge0_rtl_CE_en), .rtl_A(
                                              hidden_unit_bridge0_rtl_a), .rtl_D(
                                              hidden_unit_bridge0_rtl_d), .rtl_WE(
                                              hidden_unit_bridge0_rtl_CE_en), .CLK(
                                              clk), .mem_CE(hidden_unit_CE0), .mem_A(
                                              hidden_unit_A0), .mem_D(
                                              hidden_unit_D0), .mem_WE(
                                              hidden_unit_WE0));
  rbm_0_cmos32soi_identity_sync_write_5x16m0 visibleEnergies_bridge0(.rtl_CE(
                                             visibleEnergies_bridge0_rtl_CE_en), 
                                             .rtl_A(mux_predict_vector_ln471_0_q
                                             [370:368]), .rtl_D(
                                             visibleEnergies_bridge0_rtl_d), .rtl_WE(
                                             visibleEnergies_bridge0_rtl_CE_en), 
                                             .CLK(clk), .mem_CE(
                                             visibleEnergies_CE0), .mem_A(
                                             visibleEnergies_A0), .mem_D(
                                             visibleEnergies_D0), .mem_WE(
                                             visibleEnergies_WE0));
  // synopsys sync_set_reset_local rbm_0_cmos32soi_rbm_predict_rbm_seq_block rst
  always @(posedge clk) // rbm_0_cmos32soi_rbm_predict_rbm_sequential //**predict**//
    begin : rbm_0_cmos32soi_rbm_predict_rbm_seq_block
      if (!rst) // Initialize state and outputs
      begin
        memread_rbm_hidden_unit_ln405_Q_0_tag_0 <= 1'sb0;
        predict_start <= 1'sb0;
        predict_done <= 1'sb0;
        mux_count_ln895_Z_7_tag_0 <= 1'sb0;
        lt_ln471_q <= 1'sb0;
        add_ln281_reg_0_0 <= 2'sh0;
        mux_sum_ln236_14_q <= 1'sb0;
        mux_v_ln388_q <= 9'sh0;
        memwrite_pow2_ln455_q <= 160'sh0;
        add_ln388_1_q <= 8'sh0;
        mux_predict_vector_ln471_0_q <= 501'sh0;
        mux_user_ln863_q <= 1'sb0;
        memwrite_rbm_predict_vector_ln481_q <= 501'sh0;
        read_rbm_num_hidden_ln852_q <= 16'sh0;
        read_rbm_num_testusers_ln850_q <= 16'sh0;
        read_rbm_num_visible_ln851_q <= 16'sh0;
        add_ln238_1_q <= 16'sh0;
        and_ln886_q <= 1'sb0;
        add_ln402_1_q <= 16'sh0;
        add_ln925_1_q <= 15'sh0;
        rbm_0_cmos32soi_round_ln469_round_out_q <= 4'sh0;
        state_rbm_0_cmos32soi_rbm_predict_rbm <= 39'h1;
      end
      else // Update Q values
      begin
        memread_rbm_hidden_unit_ln405_Q_0_tag_0 <= 
        memread_rbm_hidden_unit_ln405_Q_0_tag_d;
        predict_start <= predict_start_d;
        predict_done <= predict_done_d;
        mux_count_ln895_Z_7_tag_0 <= mux_count_ln895_Z_7_tag_d;
        lt_ln471_q <= lt_ln471_z;
        add_ln281_reg_0_0 <= add_ln281_reg_0_d[1:0];
        mux_sum_ln236_14_q <= mux_predict_vector_ln471_0_487_d_0[14];
        mux_v_ln388_q <= mux_v_ln388_d[8:0];
        memwrite_pow2_ln455_q <= {memwrite_pow2_ln455_119_d_0[40:0], 
        memwrite_pow2_ln455_55_d_0, mux_v_ln388_d[63:9]};
        add_ln388_1_q <= memwrite_pow2_ln455_119_d_0[48:41];
        mux_predict_vector_ln471_0_q <= {mux_predict_vector_ln471_0_487_d_0[13:0], 
        mux_predict_vector_ln471_0_474_d_0[6:1], 
        mux_predict_vector_ln471_0_475_d_0, mux_predict_vector_ln471_0_474_d_0[0], 
        mux_predict_vector_ln471_0_464_d_0, mux_predict_vector_ln471_0_461_d_0, 
        mux_predict_vector_ln471_0_447_d_0, mux_predict_vector_ln471_0_445_d_0, 
        mux_predict_vector_ln471_0_429_d_0[9:1], 
        mux_predict_vector_ln471_0_430_d_0, mux_predict_vector_ln471_0_429_d_0[0], 
        mux_predict_vector_ln471_0_422_d_0, mux_predict_vector_ln471_0_406_d_0, 
        mux_predict_vector_ln471_0_373_d_0[16], 
        mux_predict_vector_ln471_0_389_d_0, mux_predict_vector_ln471_0_373_d_0[
        15:0], mux_predict_vector_ln471_0_371_d_0, 
        mux_predict_vector_ln471_0_369_d_0, mux_predict_vector_ln471_0_368_d, 
        mux_predict_vector_ln471_0_336_d_0, mux_predict_vector_ln471_0_332_d_0, 
        mux_predict_vector_ln471_0_300_d_0, mux_predict_vector_ln471_0_287_d_0, 
        mux_predict_vector_ln471_0_223_d_0, mux_predict_vector_ln471_0_100_d_0[
        63:2], mux_predict_vector_ln471_0_154_d_0, 
        mux_predict_vector_ln471_0_152_d_0, mux_predict_vector_ln471_0_144_d_0, 
        mux_predict_vector_ln471_0_112_d_0[30:27], 
        mux_predict_vector_ln471_0_100_d_0[1], 
        mux_predict_vector_ln471_0_112_d_0[26:0], 
        mux_predict_vector_ln471_0_111_d, mux_predict_vector_ln471_0_101_d_0, 
        mux_predict_vector_ln471_0_100_d_0[0], mux_predict_vector_ln471_0_62_d_0, 
        add_ln281_reg_0_d[63:2]};
        mux_user_ln863_q <= mux_user_ln863_d_0[0];
        memwrite_rbm_predict_vector_ln481_q <= {
        memwrite_rbm_predict_vector_ln481_447_d_0[53:0], 
        memwrite_rbm_predict_vector_ln481_383_d_0, 
        memwrite_rbm_predict_vector_ln481_319_d_0, 
        memwrite_rbm_predict_vector_ln481_255_d_0, 
        memwrite_rbm_predict_vector_ln481_191_d_0, 
        memwrite_rbm_predict_vector_ln481_127_d_0, 
        memwrite_rbm_predict_vector_ln481_63_d_0, mux_user_ln863_d_0[63:1]};
        read_rbm_num_hidden_ln852_q <= read_rbm_num_testusers_ln850_d[47:32];
        read_rbm_num_testusers_ln850_q <= read_rbm_num_testusers_ln850_d[15:0];
        read_rbm_num_visible_ln851_q <= read_rbm_num_testusers_ln850_d[31:16];
        add_ln238_1_q <= read_rbm_num_testusers_ln850_d[63:48];
        and_ln886_q <= add_ln402_1_d[16];
        add_ln402_1_q <= add_ln402_1_d[15:0];
        add_ln925_1_q <= {add_ln925_1_10_d_0, 
        memwrite_rbm_predict_vector_ln481_447_d_0[63:54]};
        rbm_0_cmos32soi_round_ln469_round_out_q <= 
        rbm_0_cmos32soi_round_ln469_round_out_d;
        state_rbm_0_cmos32soi_rbm_predict_rbm <= 
        state_rbm_0_cmos32soi_rbm_predict_rbm_next;
      end
    end
  rbm_0_cmos32soi_sigmoid_0 rbm_0_cmos32soi_sigmoid_0(.sum_in(mux_sum_ln236_z), 
                            .sigmoid_out(rbm_0_cmos32soi_sigmoid_ln250_z));
  rbm_0_cmos32soi_round_ rbm_0_cmos32soi_round_(.num_in(add_ln271_z_0[31:28]), .round__out(
                         rbm_0_cmos32soi_round__ln469_z));
  always @(*) begin : rbm_0_cmos32soi_rbm_predict_rbm_combinational
      reg ACTIVATE_VISIBLE_PREDICT_ENERGY_UPDATE_for_begin_or_0;
      reg ctrlAnd_0_ln242_z;
      reg [15:0] add_ln407_0_z;
      reg [63:0] add_ln281_z_0;
      reg [16:0] add_ln238_z;
      reg [16:0] add_ln402_z;
      reg and_ln886_z;
      reg ctrlAnd_1_ln897_z;
      reg ctrlOr_ln229_0_z;
      reg ctrlAnd_0_ln396_z;
      reg ctrlOr_ln400_0_z;
      reg ctrlAnd_0_ln423_z;
      reg ctrlAnd_0_ln434_z;
      reg ctrlAnd_0_ln471_z;
      reg ctrlAnd_0_ln51_z_0;
      reg ctrlAnd_0_ln897_z;
      reg ctrlAnd_0_ln901_z;
      reg memread_rbm_edges_ln407_en;
      reg lt_ln786_z_0;
      reg [159:0] mux_pow2_0_ln434_z;
      reg [500:0] mux_predict_vector_ln388_z;
      reg mux_predict_vector_ln471_0_406_mux_0_sel;
      reg mux_predict_vector_ln471_0_422_mux_0_sel;
      reg mux_predict_vector_ln471_0_461_mux_0_sel;
      reg mux_predict_vector_ln471_0_487_mux_0_sel;
      reg [159:0] mux_pow2_0_ln388_z;
      reg [31:0] mux_num_adj_ln51_z_0;
      reg [63:0] mux_quotient_ln51_z_0;
      reg [63:0] mux_rem_ln51_z_0;
      reg [15:0] add_ln176_0_z_0;
      reg [15:0] add_ln176_z_0;
      reg [4:0] add_ln443_z;
      reg ctrlOr_ln396_z;
      reg ctrlOr_ln423_z;
      reg ctrlOr_ln434_z;
      reg ctrlOr_ln471_z;
      reg ctrlOr_ln51_z_0;
      reg ctrlAnd_1_ln847_z;
      reg ctrlAnd_0_ln847_z;
      reg ctrlAnd_1_ln876_z;
      reg ctrlAnd_0_ln876_z;
      reg ctrlAnd_1_ln879_z;
      reg ctrlAnd_0_ln879_z;
      reg ctrlAnd_1_ln883_z;
      reg ctrlAnd_0_ln883_z;
      reg ctrlOr_ln901_z;
      reg ctrlAnd_1_ln918_z;
      reg ctrlAnd_0_ln918_z;
      reg ctrlAnd_1_ln921_z;
      reg ctrlAnd_0_ln921_z;
      reg ctrlAnd_1_ln242_z;
      reg ctrlAnd_1_ln396_z;
      reg ctrlAnd_1_ln423_z;
      reg ctrlAnd_1_ln434_z;
      reg ctrlAnd_1_ln471_z;
      reg ctrlAnd_1_ln51_z_0;
      reg ctrlAnd_1_ln901_z;
      reg eq_ln242_z;
      reg [15:0] mux_max_ln396_z;
      reg [15:0] mux_sum_ln400_z;
      reg [63:0] mux_sumOfpow2_ln434_z;
      reg [31:0] mux_expectation_ln461_z;
      reg [500:0] mux_predict_vector_ln471_z;
      reg [500:0] mux_predict_vector_ln863_z;
      reg [3:0] mux_prediction_ln901_z;
      reg [500:0] memwrite_rbm_predict_vector_ln481_z;
      reg [7:0] mux_count_ln895_z;
      reg [6:0] mux_h_ln229_z;
      reg [6:0] mux_i_ln51_z_0;
      reg [8:0] mux_i_ln895_z;
      reg [2:0] mux_j_ln423_z;
      reg [2:0] mux_j_ln396_z;
      reg [2:0] mux_j_ln434_z;
      reg [2:0] mux_j_ln461_z;
      reg [2:0] mux_j_ln471_z;
      reg [2:0] mux_j_ln901_z;
      reg [8:0] mux_v_ln236_z;
      reg [15:0] sub_ln196_0_z_0;
      reg [15:0] mux_user_ln863_z;
      reg [8:0] mux_v_ln388_z;
      reg eq_ln368_0_0_z_0;
      reg eq_ln368_0_z_0;
      reg [63:0] sub_ln301_z_0;
      reg le_ln820_z_0;
      reg [15:0] mux_sum_ln409_z;
      reg [15:0] mux_sum_ln242_z;
      reg [2:0] case_mux_tmp_ln439_z;
      reg predict_start_hold;
      reg ctrlOr_ln879_z;
      reg ctrlOr_ln883_z;
      reg mux_count_ln895_Z_7_tag_sel;
      reg predict_done_hold;
      reg ctrlOr_ln918_z;
      reg ctrlOr_ln863_z;
      reg ctrlOr_ln921_z;
      reg ctrlOr_ln242_z;
      reg mux_predict_vector_ln471_0_447_mux_0_sel;
      reg ctrlOr_ln388_0_z;
      reg ctrlAnd_1_ln461_z;
      reg ctrlAnd_0_ln461_z;
      reg ctrlOr_ln895_0_z;
      reg gt_ln856_z_0;
      reg [63:0] mux_mux_predict_vector_ln863_Z_192_v_0;
      reg [63:0] mux_mux_predict_vector_ln863_Z_256_v_0;
      reg [63:0] mux_mux_predict_vector_ln863_Z_320_v_0;
      reg [63:0] mux_mux_predict_vector_ln863_Z_384_v_0;
      reg [52:0] mux_mux_predict_vector_ln863_Z_448_v_0;
      reg [63:0] mux_mux_predict_vector_ln863_Z_64_v_0;
      reg [63:0] mux_mux_predict_vector_ln863_Z_v;
      reg [63:0] mux_mux_predict_vector_ln863_Z_128_v_0;
      reg [7:0] add_ln912_z;
      reg eq_ln231_z;
      reg lt_ln229_z;
      reg [6:0] add_ln229_z;
      reg eq_ln402_z;
      reg lt_ln400_z;
      reg [6:0] add_ln400_z;
      reg [6:0] add_ln51_z_0;
      reg eq_ln897_z;
      reg lt_ln895_z;
      reg [8:0] add_ln895_z;
      reg [2:0] add_ln423_z;
      reg [2:0] add_ln396_z;
      reg [9:0] add_ln407_z;
      reg [2:0] add_ln434_z;
      reg [31:0] memread_pow2_ln463_z;
      reg [2:0] add_ln461_z;
      reg [2:0] add_ln471_z;
      reg eq_ln473_z;
      reg [8:0] add_ln474_z;
      reg [2:0] add_ln901_z;
      reg [3:0] add_ln907_z;
      reg [8:0] add_ln903_z;
      reg [8:0] add_ln236_z;
      reg eq_ln238_z;
      reg lt_ln236_z;
      reg [15:0] mult_ln244_z;
      reg eq_ln866_z;
      reg mux_mux_user_ln863_Z_0_v;
      reg xor_ln887_z;
      reg [15:0] add_ln925_z;
      reg eq_ln390_z;
      reg lt_ln388_z;
      reg [8:0] add_ln388_z;
      reg [31:0] mux_this__ln361_0_z_0;
      reg [63:0] mux_this__ln361_z_0;
      reg [5:0] mux_tmp_ln439_z;
      reg ctrlOr_ln236_0_z;
      reg rbm_0_cmos32soi_round_ln469_round_out_sel;
      reg ctrlOr_ln461_z;
      reg if_ln231_z;
      reg if_ln229_z;
      reg if_ln402_z;
      reg if_ln400_z;
      reg lt_ln51_z_0;
      reg if_ln897_z;
      reg if_ln895_z;
      reg lt_ln423_z;
      reg lt_ln396_z;
      reg [15:0] mult_ln407_z;
      reg lt_ln434_z;
      reg lt_ln461_z;
      reg [500:0] memwrite_rbm_predict_vector_ln476_z;
      reg [500:0] memwrite_rbm_predict_vector_ln474_z;
      reg lt_ln901_z;
      reg memread_rbm_predict_vector_ln903_z;
      reg if_ln238_z;
      reg if_ln236_z;
      reg [15:0] add_ln244_z;
      reg [9:0] mult_ln240_z;
      reg [14:0] mux_add_ln925_Z_1_v_0;
      reg if_ln390_z;
      reg if_ln388_z;
      reg [63:0] mux_rem_ln58_z_0;
      reg [63:0] add_ln271_0_z;
      reg [31:0] lsh_ln452_z;
      reg add_ln281_reg_0_sel;
      reg [15:0] mux_max_ln417_z;
      reg and_1_ln231_z;
      reg or_and_0_ln231_Z_0_z;
      reg and_1_ln402_z;
      reg or_and_0_ln402_Z_0_z;
      reg and_1_ln897_z;
      reg or_and_0_ln897_Z_0_z;
      reg [500:0] mux_predict_vector_ln471_0_z;
      reg [500:0] mux_predict_vector_ln388_0_z;
      reg and_1_ln238_z;
      reg or_and_0_ln238_Z_0_z;
      reg ctrlAnd_1_ln866_z;
      reg ctrlAnd_0_ln866_z;
      reg [9:0] mux_mult_ln240_Z_v;
      reg and_1_ln390_z;
      reg or_and_0_ln390_Z_0_z;
      reg [65:0] mul_ln256_z;
      reg [31:0] mux_dp_ln449_z;
      reg [14:0] sub_ln196_z_0;
      reg ctrlAnd_1_ln231_z;
      reg ctrlAnd_0_ln231_z;
      reg ctrlAnd_0_ln402_z;
      reg [3:0] mux_prediction_ln905_z;
      reg ctrlAnd_0_ln238_z;
      reg ctrlOr_ln876_z;
      reg ctrlOr_ln869_z;
      reg ctrlAnd_1_ln390_z;
      reg ctrlAnd_0_ln390_z;
      reg [159:0] memwrite_pow2_ln455_z;
      reg mux_predict_vector_ln471_0_369_mux_0_sel;
      reg mux_predict_vector_ln471_0_371_mux_0_sel;
      reg mux_predict_vector_ln471_0_373_mux_0_sel;
      reg mux_predict_vector_ln471_0_368_sel;
      reg mux_v_ln388_sel;
      reg mux_predict_vector_ln471_0_464_mux_0_sel;
      reg mux_predict_vector_ln471_0_474_mux_0_sel;
      reg mux_predict_vector_ln471_0_475_mux_0_sel;
      reg mux_user_ln863_mux_0_sel;
      reg read_rbm_num_testusers_ln850_sel;
      reg add_ln925_1_10_mux_0_sel;

      state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'h0;
      ACTIVATE_VISIBLE_PREDICT_ENERGY_UPDATE_for_begin_or_0 = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[20];
      ctrlAnd_0_ln242_z = mux_predict_vector_ln471_0_q[111] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[37];
      add_ln407_0_z = mux_predict_vector_ln471_0_q[404:389] + {
      mux_predict_vector_ln471_0_q[435:430], mux_predict_vector_ln471_0_q[422]};
      add_ln281_z_0 = {mux_predict_vector_ln471_0_q[61:0], add_ln281_reg_0_0} + 
      mux_predict_vector_ln471_0_q[367:336];
      add_ln238_z = {1'b0, num_visible} + 17'h1;
      add_ln402_z = {1'b0, num_hidden} + 17'h1;
      and_ln886_z = num_users[0] & num_loops[0];
      ctrlAnd_1_ln897_z = mux_predict_vector_ln471_0_q[153] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[9];
      ctrlOr_ln229_0_z = state_rbm_0_cmos32soi_rbm_predict_rbm[35] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[6];
      ctrlAnd_0_ln396_z = mux_predict_vector_ln471_0_q[405] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[16];
      ctrlOr_ln400_0_z = state_rbm_0_cmos32soi_rbm_predict_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[15];
      ctrlAnd_0_ln423_z = mux_predict_vector_ln471_0_q[463] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[20];
      ctrlAnd_0_ln434_z = mux_predict_vector_ln471_0_q[335] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[23];
      ctrlAnd_0_ln471_z = lt_ln471_q & state_rbm_0_cmos32soi_rbm_predict_rbm[28];
      ctrlAnd_0_ln51_z_0 = mux_predict_vector_ln471_0_q[139] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[26];
      ctrlAnd_0_ln897_z = mux_predict_vector_ln471_0_q[152] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[9];
      ctrlAnd_0_ln901_z = mux_predict_vector_ln471_0_q[147] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[13];
      memread_rbm_edges_ln407_en = memread_rbm_hidden_unit_ln405_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30];
      lt_ln786_z_0 = mux_predict_vector_ln471_0_q[160:154] > 7'h20;
      mux_pow2_0_ln434_z = memwrite_pow2_ln455_q;
      mux_predict_vector_ln388_z = memwrite_rbm_predict_vector_ln481_q;
      mux_predict_vector_ln471_0_406_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30];
      mux_predict_vector_ln471_0_422_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30];
      mux_predict_vector_ln471_0_461_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[19];
      mux_predict_vector_ln471_0_487_mux_0_sel = ctrlAnd_0_ln242_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[36];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[7]) 
        mux_pow2_0_ln388_z = 160'h0;
      else 
        mux_pow2_0_ln388_z = memwrite_pow2_ln455_q;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[25]) 
        mux_num_adj_ln51_z_0 = mux_predict_vector_ln471_0_q[331:300];
      else 
        mux_num_adj_ln51_z_0 = mux_predict_vector_ln471_0_q[138:107];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[25]) 
        mux_quotient_ln51_z_0 = 64'h0;
      else 
        mux_quotient_ln51_z_0 = mux_predict_vector_ln471_0_q[203:140];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[25]) 
        mux_rem_ln51_z_0 = 64'h0;
      else 
        mux_rem_ln51_z_0 = mux_predict_vector_ln471_0_q[267:204];
      add_ln176_0_z_0 = mux_predict_vector_ln471_0_q[421:406] + {{8{
      edges_bridge1_rtl_Q[7]}}, edges_bridge1_rtl_Q};
      add_ln176_z_0 = {mux_predict_vector_ln471_0_q[101], mux_sum_ln236_14_q, 
      mux_predict_vector_ln471_0_q[500:487]} + {{8{edges_bridge1_rtl_Q[7]}}, 
      edges_bridge1_rtl_Q};
      add_ln443_z = visibleEnergies_bridge2_rtl_Q[5:1] + 5'h1;
      ctrlOr_ln396_z = ctrlAnd_0_ln396_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[14];
      ctrlOr_ln423_z = ctrlAnd_0_ln423_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[17];
      ctrlOr_ln434_z = ctrlAnd_0_ln434_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[21];
      ctrlOr_ln471_z = ctrlAnd_0_ln471_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[27];
      ctrlOr_ln51_z_0 = ctrlAnd_0_ln51_z_0 | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[25];
      ctrlAnd_1_ln847_z = init_done & state_rbm_0_cmos32soi_rbm_predict_rbm[0];
      ctrlAnd_0_ln847_z = !init_done & state_rbm_0_cmos32soi_rbm_predict_rbm[0];
      ctrlAnd_1_ln876_z = predict_input_done & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[3];
      ctrlAnd_0_ln876_z = !predict_input_done & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[3];
      ctrlAnd_1_ln879_z = !predict_input_done & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[4];
      ctrlAnd_0_ln879_z = predict_input_done & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[4];
      ctrlAnd_1_ln883_z = output_done & state_rbm_0_cmos32soi_rbm_predict_rbm[5];
      ctrlAnd_0_ln883_z = !output_done & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[5];
      ctrlOr_ln901_z = ctrlAnd_0_ln901_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[12];
      ctrlAnd_1_ln918_z = output_start & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[10];
      ctrlAnd_0_ln918_z = !output_start & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[10];
      ctrlAnd_1_ln921_z = !output_start & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[11];
      ctrlAnd_0_ln921_z = output_start & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[11];
      ctrlAnd_1_ln242_z = !mux_predict_vector_ln471_0_q[111] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[37];
      ctrlAnd_1_ln396_z = !mux_predict_vector_ln471_0_q[405] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[16];
      ctrlAnd_1_ln423_z = !mux_predict_vector_ln471_0_q[463] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[20];
      ctrlAnd_1_ln434_z = !mux_predict_vector_ln471_0_q[335] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[23];
      ctrlAnd_1_ln471_z = !lt_ln471_q & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[28];
      ctrlAnd_1_ln51_z_0 = !mux_predict_vector_ln471_0_q[139] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[26];
      ctrlAnd_1_ln901_z = !mux_predict_vector_ln471_0_q[147] & 
      state_rbm_0_cmos32soi_rbm_predict_rbm[13];
      eq_ln242_z = memread_rbm_data_ln240_rtl_Q == 8'h1;
      edges_bridge1_rtl_CE_en = memread_rbm_edges_ln407_en | ctrlAnd_0_ln242_z;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[34]) 
        hidden_unit_bridge0_rtl_a = mux_predict_vector_ln471_0_q[480:474];
      else 
        hidden_unit_bridge0_rtl_a = read_rbm_num_hidden_ln852_q[6:0];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[14]) 
        mux_max_ln396_z = 16'hfc18;
      else 
        mux_max_ln396_z = mux_predict_vector_ln471_0_q[386:371];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[15]) 
        mux_sum_ln400_z = 16'h0;
      else 
        mux_sum_ln400_z = mux_predict_vector_ln471_0_q[421:406];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[21]) 
        mux_sumOfpow2_ln434_z = 64'h0;
      else 
        mux_sumOfpow2_ln434_z = add_ln281_z_0;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[24]) 
        mux_expectation_ln461_z = 32'h0;
      else 
        mux_expectation_ln461_z = mux_predict_vector_ln471_0_q[299:268];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[27]) 
        mux_predict_vector_ln471_z = memwrite_rbm_predict_vector_ln481_q;
      else 
        mux_predict_vector_ln471_z = mux_predict_vector_ln471_0_q;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[1]) 
        mux_predict_vector_ln863_z = 501'h0;
      else 
        mux_predict_vector_ln863_z = memwrite_rbm_predict_vector_ln481_q;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[12]) 
        mux_prediction_ln901_z = 4'h0;
      else 
        mux_prediction_ln901_z = mux_predict_vector_ln471_0_q[151:148];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[34]) 
        hidden_unit_bridge0_rtl_d = lt_ln786_z_0;
      else 
        hidden_unit_bridge0_rtl_d = 1'b1;
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_predict_rbm[29]: 
          memread_rbm_hidden_unit_ln405_Q_0_tag_d = 
          memread_rbm_hidden_unit_ln405_rtl_Q;
        state_rbm_0_cmos32soi_rbm_predict_rbm[30]: 
          memread_rbm_hidden_unit_ln405_Q_0_tag_d = 
          memread_rbm_hidden_unit_ln405_Q_0_tag_0;
        default: memread_rbm_hidden_unit_ln405_Q_0_tag_d = 1'bX;
      endcase
      memwrite_rbm_predict_vector_ln481_z = mux_predict_vector_ln388_z;
      memwrite_rbm_predict_vector_ln481_z[read_rbm_num_visible_ln851_q[8:0]] = 
      1'b1;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[8]) 
        mux_count_ln895_z = 8'h0;
      else 
        mux_count_ln895_z = {mux_predict_vector_ln471_0_q[134:128], !
        mux_predict_vector_ln471_0_q[121]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[6]) 
        mux_h_ln229_z = 7'h0;
      else 
        mux_h_ln229_z = {mux_predict_vector_ln471_0_q[486:481], !
        mux_predict_vector_ln471_0_q[474]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[15]) 
        mux_h_ln400_z = 7'h0;
      else 
        mux_h_ln400_z = {mux_predict_vector_ln471_0_q[428:423], !
        mux_predict_vector_ln471_0_q[422]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[25]) 
        mux_i_ln51_z_0 = 7'h0;
      else 
        mux_i_ln51_z_0 = {mux_predict_vector_ln471_0_q[106:101], !
        mux_predict_vector_ln471_0_q[100]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[8]) 
        mux_i_ln895_z = 9'h0;
      else 
        mux_i_ln895_z = {mux_predict_vector_ln471_0_q[143:140], 
        mux_predict_vector_ln471_0_q[138:135], !mux_predict_vector_ln471_0_q[112]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[17]) 
        mux_j_ln423_z = 3'h0;
      else 
        mux_j_ln423_z = {mux_predict_vector_ln471_0_q[462:461], !
        mux_predict_vector_ln471_0_q[368]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[14]) 
        mux_j_ln396_z = 3'h0;
      else 
        mux_j_ln396_z = {mux_predict_vector_ln471_0_q[388:387], !
        mux_predict_vector_ln471_0_q[368]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[21]) 
        mux_j_ln434_z = 3'h0;
      else 
        mux_j_ln434_z = {mux_predict_vector_ln471_0_q[334:333], !
        mux_predict_vector_ln471_0_q[332]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[24]) 
        mux_j_ln461_z = 3'h0;
      else 
        mux_j_ln461_z = {mux_predict_vector_ln471_0_q[98:97], !
        mux_predict_vector_ln471_0_q[62]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[27]) 
        mux_j_ln471_z = 3'h0;
      else 
        mux_j_ln471_z = {add_ln281_reg_0_0, !mux_sum_ln236_14_q};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[12]) 
        mux_j_ln901_z = 3'h0;
      else 
        mux_j_ln901_z = {mux_predict_vector_ln471_0_q[146:145], !
        mux_predict_vector_ln471_0_q[144]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[33]) 
        mux_v_ln236_z = 9'h0;
      else 
        mux_v_ln236_z = {mux_predict_vector_ln471_0_q[110:103], !
        mux_predict_vector_ln471_0_q[102]};
      sub_ln196_0_z_0 = visibleEnergies_bridge2_rtl_Q - {
      mux_predict_vector_ln471_0_q[460:447], !mux_predict_vector_ln471_0_q[372], 
      mux_predict_vector_ln471_0_q[371]};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[1]) 
        mux_user_ln863_z = 16'h0;
      else 
        mux_user_ln863_z = {add_ln925_1_q, !mux_user_ln863_q};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[7]) 
        mux_v_ln388_z = 9'h0;
      else 
        mux_v_ln388_z = {add_ln388_1_q, !mux_v_ln388_q[0]};
      eq_ln368_0_0_z_0 = mux_num_adj_ln51_z_0 == 32'h0;
      eq_ln368_0_z_0 = mux_quotient_ln51_z_0 == 64'h0;
      sub_ln301_z_0 = {mux_rem_ln51_z_0[62:0], mux_num_adj_ln51_z_0[31]} - {
      mux_predict_vector_ln471_0_q[61:0], add_ln281_reg_0_0};
      le_ln820_z_0 = {2'h0, mux_predict_vector_ln471_0_q[61:0], 
      add_ln281_reg_0_0} > {1'b0, mux_rem_ln51_z_0, mux_num_adj_ln51_z_0[31]};
      if (memread_rbm_hidden_unit_ln405_Q_0_tag_0) 
        mux_sum_ln409_z = add_ln176_0_z_0;
      else 
        mux_sum_ln409_z = mux_predict_vector_ln471_0_q[421:406];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[38]) 
        mux_sum_ln242_z = add_ln176_z_0;
      else 
        mux_sum_ln242_z = {mux_predict_vector_ln471_0_q[101], mux_sum_ln236_14_q, 
        mux_predict_vector_ln471_0_q[500:487]};
      case (1'b1)
        !visibleEnergies_bridge2_rtl_Q[0]: case_mux_tmp_ln439_z = 3'h1;
        !visibleEnergies_bridge2_rtl_Q[15]: case_mux_tmp_ln439_z = 3'h2;
        default: case_mux_tmp_ln439_z = 3'h4;
      endcase
      visibleEnergies_bridge2_rtl_CE_en = ctrlOr_ln434_z | ctrlOr_ln423_z;
      predict_start_hold = ~(ctrlAnd_1_ln879_z | ctrlAnd_1_ln876_z);
      ctrlOr_ln879_z = ctrlAnd_0_ln879_z | ctrlAnd_1_ln876_z;
      ctrlOr_ln883_z = ctrlAnd_0_ln883_z | ctrlAnd_1_ln879_z;
      mux_count_ln895_Z_7_tag_sel = ctrlOr_ln901_z | ctrlAnd_1_ln897_z;
      predict_done_hold = ~(ctrlAnd_1_ln918_z | ctrlAnd_0_ln897_z);
      ctrlOr_ln918_z = ctrlAnd_0_ln918_z | ctrlAnd_0_ln897_z;
      ctrlOr_ln863_z = ctrlAnd_1_ln921_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[1];
      ctrlOr_ln921_z = ctrlAnd_0_ln921_z | ctrlAnd_1_ln918_z;
      ctrlOr_ln242_z = ctrlAnd_1_ln242_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[38];
      mux_predict_vector_ln471_0_447_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[18] | ctrlOr_ln423_z | 
      ctrlAnd_1_ln396_z | state_rbm_0_cmos32soi_rbm_predict_rbm[19];
      ctrlOr_ln388_0_z = ctrlAnd_1_ln471_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[7];
      ctrlAnd_1_ln461_z = !mux_predict_vector_ln471_0_q[99] & ctrlAnd_1_ln51_z_0;
      ctrlAnd_0_ln461_z = mux_predict_vector_ln471_0_q[99] & ctrlAnd_1_ln51_z_0;
      memwrite_rbm_predict_result_ln910_en = !mux_count_ln895_Z_7_tag_0 & 
      ctrlAnd_1_ln901_z;
      ctrlOr_ln895_0_z = ctrlAnd_1_ln901_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[8];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[19]) 
        visibleEnergies_bridge0_rtl_d = mux_predict_vector_ln471_0_q[421:406];
      else 
        visibleEnergies_bridge0_rtl_d = mux_sum_ln400_z;
      gt_ln856_z_0 = $signed(mux_sum_ln400_z) > $signed(
      mux_predict_vector_ln471_0_q[386:371]);
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_predict_vector_ln863_Z_192_v_0 = 
        memwrite_rbm_predict_vector_ln481_q[255:192];
      else 
        mux_mux_predict_vector_ln863_Z_192_v_0 = mux_predict_vector_ln863_z[255:
        192];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_predict_vector_ln863_Z_256_v_0 = 
        memwrite_rbm_predict_vector_ln481_q[319:256];
      else 
        mux_mux_predict_vector_ln863_Z_256_v_0 = mux_predict_vector_ln863_z[319:
        256];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_predict_vector_ln863_Z_320_v_0 = 
        memwrite_rbm_predict_vector_ln481_q[383:320];
      else 
        mux_mux_predict_vector_ln863_Z_320_v_0 = mux_predict_vector_ln863_z[383:
        320];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_predict_vector_ln863_Z_384_v_0 = 
        memwrite_rbm_predict_vector_ln481_q[447:384];
      else 
        mux_mux_predict_vector_ln863_Z_384_v_0 = mux_predict_vector_ln863_z[447:
        384];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_predict_vector_ln863_Z_448_v_0 = 
        memwrite_rbm_predict_vector_ln481_q[500:448];
      else 
        mux_mux_predict_vector_ln863_Z_448_v_0 = mux_predict_vector_ln863_z[500:
        448];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_predict_vector_ln863_Z_64_v_0 = 
        memwrite_rbm_predict_vector_ln481_q[127:64];
      else 
        mux_mux_predict_vector_ln863_Z_64_v_0 = mux_predict_vector_ln863_z[127:
        64];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_predict_vector_ln863_Z_v = memwrite_rbm_predict_vector_ln481_q[
        63:0];
      else 
        mux_mux_predict_vector_ln863_Z_v = mux_predict_vector_ln863_z[63:0];
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_predict_vector_ln863_Z_128_v_0 = 
        memwrite_rbm_predict_vector_ln481_q[191:128];
      else 
        mux_mux_predict_vector_ln863_Z_128_v_0 = mux_predict_vector_ln863_z[191:
        128];
      add_ln912_z = mux_count_ln895_z + 8'h1;
      eq_ln231_z = {9'h0, mux_h_ln229_z} == read_rbm_num_hidden_ln852_q;
      lt_ln229_z = mux_h_ln229_z[6:2] <= 5'h18;
      add_ln229_z = mux_h_ln229_z + 7'h1;
      eq_ln402_z = {10'h0, mux_h_ln400_z} == {add_ln402_1_q, !
      read_rbm_num_hidden_ln852_q[0]};
      lt_ln400_z = mux_h_ln400_z <= 7'h64;
      add_ln400_z = mux_h_ln400_z + 7'h1;
      add_ln51_z_0 = mux_i_ln51_z_0 + 7'h1;
      eq_ln897_z = {7'h0, mux_i_ln895_z} == read_rbm_num_visible_ln851_q;
      lt_ln895_z = mux_i_ln895_z[8:2] <= 7'h7c;
      add_ln895_z = mux_i_ln895_z + 9'h5;
      add_ln423_z = mux_j_ln423_z + 3'h1;
      add_ln396_z = mux_j_ln396_z + 3'h1;
      add_ln407_z = {1'b0, mux_v_ln388_q} + mux_j_ln396_z;
      if (ACTIVATE_VISIBLE_PREDICT_ENERGY_UPDATE_for_begin_or_0) 
        visibleEnergies_bridge2_rtl_a = mux_j_ln423_z;
      else 
        visibleEnergies_bridge2_rtl_a = mux_j_ln434_z;
      add_ln434_z = mux_j_ln434_z + 3'h1;
      memread_pow2_ln463_z = memwrite_pow2_ln455_q[{mux_j_ln461_z, 5'h0}+:32];
      add_ln461_z = mux_j_ln461_z + 3'h1;
      add_ln471_z = mux_j_ln471_z + 3'h1;
      eq_ln473_z = {1'b0, mux_j_ln471_z} == 
      rbm_0_cmos32soi_round_ln469_round_out_q;
      add_ln474_z = mux_v_ln388_q + mux_j_ln471_z;
      add_ln901_z = mux_j_ln901_z + 3'h1;
      add_ln907_z = {1'b0, mux_j_ln901_z} + 4'h1;
      add_ln903_z = mux_predict_vector_ln471_0_q[120:112] + mux_j_ln901_z;
      add_ln236_z = mux_v_ln236_z + 9'h1;
      eq_ln238_z = {8'h0, mux_v_ln236_z} == {add_ln238_1_q, !
      read_rbm_num_visible_ln851_q[0]};
      lt_ln236_z = mux_v_ln236_z <= 9'h1f4;
      mult_ln244_z = mux_v_ln236_z * 9'h65;
      add_ln240_z = mux_predict_vector_ln471_0_q[473:464] + mux_v_ln236_z;
      eq_ln866_z = mux_user_ln863_z == read_rbm_num_testusers_ln850_q;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mux_user_ln863_Z_0_v = mux_user_ln863_q;
      else 
        mux_mux_user_ln863_Z_0_v = mux_user_ln863_z[0];
      xor_ln887_z = mux_user_ln863_z[0] ^ and_ln886_q;
      add_ln925_z = mux_user_ln863_z + 16'h1;
      eq_ln390_z = {7'h0, mux_v_ln388_z} == read_rbm_num_visible_ln851_q;
      lt_ln388_z = mux_v_ln388_z[8:2] <= 7'h7c;
      add_ln388_z = mux_v_ln388_z + 9'h5;
      if (eq_ln368_0_0_z_0) 
        mux_this__ln361_0_z_0 = mux_num_adj_ln51_z_0;
      else 
        mux_this__ln361_0_z_0 = {mux_num_adj_ln51_z_0[30:0], 1'b0};
      if (eq_ln368_0_z_0) 
        mux_this__ln361_z_0 = mux_quotient_ln51_z_0;
      else 
        mux_this__ln361_z_0 = {mux_quotient_ln51_z_0[62:0], 1'b0};
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[33]) 
        mux_sum_ln236_z = 16'h0;
      else 
        mux_sum_ln236_z = mux_sum_ln242_z;
      case (1'b1)// synopsys parallel_case
        case_mux_tmp_ln439_z[0]: mux_tmp_ln439_z = {
          visibleEnergies_bridge2_rtl_Q[15], visibleEnergies_bridge2_rtl_Q[5:1]};
        case_mux_tmp_ln439_z[1]: mux_tmp_ln439_z = {1'b0, add_ln443_z};
        case_mux_tmp_ln439_z[2]: mux_tmp_ln439_z = 6'h3f;
        default: mux_tmp_ln439_z = 6'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln876_z: predict_start_d = 1'b1;
        ctrlAnd_1_ln879_z: predict_start_d = 1'b0;
        predict_start_hold: predict_start_d = predict_start;
        default: predict_start_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln897_z: predict_done_d = 1'b1;
        ctrlAnd_1_ln918_z: predict_done_d = 1'b0;
        predict_done_hold: predict_done_d = predict_done;
        default: predict_done_d = 1'bX;
      endcase
      ctrlOr_ln236_0_z = ctrlOr_ln242_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[33];
      rbm_0_cmos32soi_round_ln469_round_out_sel = ctrlOr_ln471_z | 
      ctrlAnd_1_ln461_z;
      ctrlOr_ln461_z = ctrlAnd_0_ln461_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[24];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln895_0_z: mux_count_ln895_Z_7_tag_d = mux_count_ln895_z[7];
        mux_count_ln895_Z_7_tag_sel: mux_count_ln895_Z_7_tag_d = 
          mux_count_ln895_Z_7_tag_0;
        default: mux_count_ln895_Z_7_tag_d = 1'bX;
      endcase
      if_ln231_z = ~eq_ln231_z;
      if_ln229_z = ~lt_ln229_z;
      if_ln402_z = ~eq_ln402_z;
      if_ln400_z = ~lt_ln400_z;
      lt_ln51_z_0 = add_ln51_z_0 <= 7'h5e;
      if_ln897_z = ~eq_ln897_z;
      if_ln895_z = ~lt_ln895_z;
      lt_ln423_z = add_ln423_z <= 3'h4;
      lt_ln396_z = add_ln396_z <= 3'h4;
      mult_ln407_z = add_ln407_z * 10'h65;
      lt_ln434_z = add_ln434_z <= 3'h4;
      lt_ln461_z = add_ln461_z <= 3'h4;
      lt_ln471_z = add_ln471_z <= 3'h4;
      memwrite_rbm_predict_vector_ln476_z = mux_predict_vector_ln471_z;
      memwrite_rbm_predict_vector_ln476_z[add_ln474_z] = 1'b0;
      memwrite_rbm_predict_vector_ln474_z = mux_predict_vector_ln471_z;
      memwrite_rbm_predict_vector_ln474_z[add_ln474_z] = 1'b1;
      lt_ln901_z = add_ln901_z <= 3'h4;
      memread_rbm_predict_vector_ln903_z = memwrite_rbm_predict_vector_ln481_q[
      add_ln903_z];
      if_ln238_z = ~eq_ln238_z;
      if_ln236_z = ~lt_ln236_z;
      add_ln244_z = mult_ln244_z + mux_predict_vector_ln471_0_q[480:474];
      mult_ln240_z = xor_ln887_z * 9'h1f5;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_add_ln925_Z_1_v_0 = add_ln925_1_q;
      else 
        mux_add_ln925_Z_1_v_0 = add_ln925_z[15:1];
      if_ln390_z = ~eq_ln390_z;
      if_ln388_z = ~lt_ln388_z;
      if (!le_ln820_z_0) 
        mux_rem_ln58_z_0 = sub_ln301_z_0;
      else 
        mux_rem_ln58_z_0 = {mux_rem_ln51_z_0[62:0], mux_num_adj_ln51_z_0[31]};
      add_ln271_0_z = mux_this__ln361_z_0 + !le_ln820_z_0;
      case (mux_tmp_ln439_z[4:0])
        5'h0: lsh_ln452_z = 32'h1;
        5'h1: lsh_ln452_z = 32'h2;
        5'h2: lsh_ln452_z = 32'h4;
        5'h3: lsh_ln452_z = 32'h8;
        5'h4: lsh_ln452_z = 32'h10;
        5'h5: lsh_ln452_z = 32'h20;
        5'h6: lsh_ln452_z = 32'h40;
        5'h7: lsh_ln452_z = 32'h80;
        5'h8: lsh_ln452_z = 32'h100;
        5'h9: lsh_ln452_z = 32'h200;
        5'ha: lsh_ln452_z = 32'h400;
        5'hb: lsh_ln452_z = 32'h800;
        5'hc: lsh_ln452_z = 32'h1000;
        5'hd: lsh_ln452_z = 32'h2000;
        5'he: lsh_ln452_z = 32'h4000;
        5'hf: lsh_ln452_z = 32'h8000;
        5'h10: lsh_ln452_z = 32'h10000;
        5'h11: lsh_ln452_z = 32'h20000;
        5'h12: lsh_ln452_z = 32'h40000;
        5'h13: lsh_ln452_z = 32'h80000;
        5'h14: lsh_ln452_z = 32'h100000;
        5'h15: lsh_ln452_z = 32'h200000;
        5'h16: lsh_ln452_z = 32'h400000;
        5'h17: lsh_ln452_z = 32'h800000;
        5'h18: lsh_ln452_z = 32'h1000000;
        5'h19: lsh_ln452_z = 32'h2000000;
        5'h1a: lsh_ln452_z = 32'h4000000;
        5'h1b: lsh_ln452_z = 32'h8000000;
        5'h1c: lsh_ln452_z = 32'h10000000;
        5'h1d: lsh_ln452_z = 32'h20000000;
        5'h1e: lsh_ln452_z = 32'h40000000;
        5'h1f: lsh_ln452_z = 32'h80000000;
        default: lsh_ln452_z = 32'h0;
      endcase
      add_ln281_reg_0_sel = ctrlOr_ln51_z_0 | ctrlOr_ln461_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[22];
      if (gt_ln856_z_0) 
        mux_max_ln417_z = mux_sum_ln400_z;
      else 
        mux_max_ln417_z = mux_predict_vector_ln471_0_q[386:371];
      and_1_ln231_z = if_ln231_z & lt_ln229_z;
      or_and_0_ln231_Z_0_z = if_ln229_z | eq_ln231_z;
      and_1_ln402_z = if_ln402_z & lt_ln400_z;
      or_and_0_ln402_Z_0_z = if_ln400_z | eq_ln402_z;
      and_1_ln897_z = if_ln897_z & lt_ln895_z;
      or_and_0_ln897_Z_0_z = if_ln895_z | eq_ln897_z;
      if (eq_ln473_z) begin
        mux_predict_vector_ln471_0_z = memwrite_rbm_predict_vector_ln474_z;
        mux_predict_vector_ln388_0_z = memwrite_rbm_predict_vector_ln474_z;
      end
      else begin
        mux_predict_vector_ln471_0_z = memwrite_rbm_predict_vector_ln476_z;
        mux_predict_vector_ln388_0_z = memwrite_rbm_predict_vector_ln476_z;
      end
      and_1_ln238_z = if_ln238_z & lt_ln236_z;
      or_and_0_ln238_Z_0_z = if_ln236_z | eq_ln238_z;
      ctrlAnd_1_ln866_z = !eq_ln866_z & ctrlOr_ln863_z;
      ctrlAnd_0_ln866_z = eq_ln866_z & ctrlOr_ln863_z;
      if (state_rbm_0_cmos32soi_rbm_predict_rbm[3]) 
        mux_mult_ln240_Z_v = mux_predict_vector_ln471_0_q[473:464];
      else 
        mux_mult_ln240_Z_v = mult_ln240_z;
      and_1_ln390_z = if_ln390_z & lt_ln388_z;
      or_and_0_ln390_Z_0_z = if_ln388_z | eq_ln390_z;
      mul_ln256_z = add_ln271_0_z * mux_predict_vector_ln471_0_q[64:62];
      if (mux_tmp_ln439_z[5]) 
        mux_dp_ln449_z = 32'h0;
      else 
        mux_dp_ln449_z = lsh_ln452_z;
      sub_ln196_z_0 = mux_max_ln417_z[15:1] - 15'h1f;
      ctrlAnd_1_ln231_z = and_1_ln231_z & ctrlOr_ln229_0_z;
      ctrlAnd_0_ln231_z = or_and_0_ln231_Z_0_z & ctrlOr_ln229_0_z;
      ctrlAnd_1_ln402_z = and_1_ln402_z & ctrlOr_ln400_0_z;
      ctrlAnd_0_ln402_z = or_and_0_ln402_Z_0_z & ctrlOr_ln400_0_z;
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_predict_rbm[36]: 
          mux_predict_vector_ln471_0_111_d = eq_ln242_z;
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_111_d = 
          mux_this__ln361_0_z_0[4];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_111_d = 
          mux_predict_vector_ln471_0_z[111];
        default: mux_predict_vector_ln471_0_111_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_112_d_0 = {add_ln271_0_z[3:0], 
          mux_this__ln361_0_z_0[31:5]};
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_112_d_0 = {
          mux_predict_vector_ln471_0_z[143:140], mux_predict_vector_ln471_0_z[
          138:112]};
        ctrlOr_ln895_0_z: mux_predict_vector_ln471_0_112_d_0 = {add_ln895_z[8:1], 
          add_ln912_z[7:1], mux_count_ln895_z[6:0], mux_i_ln895_z};
        mux_count_ln895_Z_7_tag_sel: mux_predict_vector_ln471_0_112_d_0 = {
          mux_predict_vector_ln471_0_q[143:140], mux_predict_vector_ln471_0_q[
          138:112]};
        default: mux_predict_vector_ln471_0_112_d_0 = 31'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_152_d_0 = add_ln271_0_z[13:
          12];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_152_d_0 = 
          mux_predict_vector_ln471_0_z[153:152];
        ctrlOr_ln895_0_z: mux_predict_vector_ln471_0_152_d_0 = {and_1_ln897_z, 
          or_and_0_ln897_Z_0_z};
        default: mux_predict_vector_ln471_0_152_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln461_z: mux_predict_vector_ln471_0_300_d_0 = 
          memread_pow2_ln463_z;
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_300_d_0 = 
          mux_predict_vector_ln471_0_z[331:300];
        default: mux_predict_vector_ln471_0_300_d_0 = 32'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln434_z: mux_predict_vector_ln471_0_332_d_0 = {lt_ln434_z, 
          add_ln434_z[2:1], mux_j_ln434_z[0]};
        state_rbm_0_cmos32soi_rbm_predict_rbm[22]: 
          mux_predict_vector_ln471_0_332_d_0 = mux_predict_vector_ln471_0_q[335:
          332];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_332_d_0 = 
          mux_predict_vector_ln471_0_z[335:332];
        default: mux_predict_vector_ln471_0_332_d_0 = 4'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln434_z: mux_predict_vector_ln471_0_445_d_0 = mux_j_ln434_z[2:1];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_445_d_0 = 
          mux_predict_vector_ln471_0_z[446:445];
        default: mux_predict_vector_ln471_0_445_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln423_z: mux_predict_vector_ln471_0_461_d_0 = {lt_ln423_z, 
          add_ln423_z[2:1]};
        mux_predict_vector_ln471_0_461_mux_0_sel: 
          mux_predict_vector_ln471_0_461_d_0 = mux_predict_vector_ln471_0_q[463:
          461];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_461_d_0 = 
          mux_predict_vector_ln471_0_z[463:461];
        default: mux_predict_vector_ln471_0_461_d_0 = 3'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln461_z: mux_predict_vector_ln471_0_62_d_0 = {lt_ln461_z, 
          add_ln461_z[2:1], mux_expectation_ln461_z, mux_j_ln461_z};
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_62_d_0 = 
          mux_predict_vector_ln471_0_q[99:62];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_62_d_0 = 
          mux_predict_vector_ln471_0_z[99:62];
        default: mux_predict_vector_ln471_0_62_d_0 = 38'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln434_z: add_ln281_reg_0_d = mux_sumOfpow2_ln434_z;
        add_ln281_reg_0_sel: add_ln281_reg_0_d = {mux_predict_vector_ln471_0_q[
          61:0], add_ln281_reg_0_0};
        ctrlAnd_1_ln434_z: add_ln281_reg_0_d = add_ln281_z_0;
        ctrlOr_ln471_z: add_ln281_reg_0_d = {mux_predict_vector_ln471_0_z[61:0], 
          add_ln471_z[2:1]};
        default: add_ln281_reg_0_d = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_100_d_0 = {mux_rem_ln58_z_0[
          18:0], add_ln271_0_z[63:21], lt_ln51_z_0, mux_i_ln51_z_0[0]};
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_100_d_0 = {
          mux_predict_vector_ln471_0_z[222:161], mux_predict_vector_ln471_0_z[
          139], mux_predict_vector_ln471_0_z[100]};
        default: mux_predict_vector_ln471_0_100_d_0 = 64'hX;
      endcase
      if (memread_rbm_predict_vector_ln903_z) 
        mux_prediction_ln905_z = add_ln907_z;
      else 
        mux_prediction_ln905_z = mux_prediction_ln901_z;
      ctrlAnd_1_ln238_z = and_1_ln238_z & ctrlOr_ln236_0_z;
      ctrlAnd_0_ln238_z = or_and_0_ln238_Z_0_z & ctrlOr_ln236_0_z;
      ctrlOr_ln876_z = ctrlAnd_0_ln876_z | ctrlAnd_1_ln866_z;
      ctrlOr_ln869_z = state_rbm_0_cmos32soi_rbm_predict_rbm[2] | 
      ctrlAnd_0_ln866_z;
      ctrlAnd_1_ln390_z = and_1_ln390_z & ctrlOr_ln388_0_z;
      ctrlAnd_0_ln390_z = or_and_0_ln390_Z_0_z & ctrlOr_ln388_0_z;
      add_ln271_z_0 = mul_ln256_z[65:34] + mux_predict_vector_ln471_0_q[96:65];
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_predict_rbm[22]: 
          mux_predict_vector_ln471_0_336_d_0 = mux_dp_ln449_z;
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_336_d_0 = 
          mux_predict_vector_ln471_0_z[367:336];
        default: mux_predict_vector_ln471_0_336_d_0 = 32'hX;
      endcase
      memwrite_pow2_ln455_z = memwrite_pow2_ln455_q;
      memwrite_pow2_ln455_z[{{mux_predict_vector_ln471_0_q[446:445], 
      mux_predict_vector_ln471_0_q[332]}, 5'h0}+:32] = mux_dp_ln449_z;
      hidden_unit_bridge0_rtl_CE_en = state_rbm_0_cmos32soi_rbm_predict_rbm[34] | 
      ctrlAnd_0_ln231_z;
      mux_predict_vector_ln471_0_369_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | ctrlAnd_1_ln402_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30];
      mux_predict_vector_ln471_0_371_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | ctrlOr_ln423_z | 
      ctrlAnd_1_ln402_z | ctrlAnd_1_ln396_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[19] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30];
      mux_predict_vector_ln471_0_373_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | ctrlAnd_1_ln402_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30];
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln402_z: mux_predict_vector_ln471_0_406_d_0 = mux_sum_ln400_z;
        mux_predict_vector_ln471_0_406_mux_0_sel: 
          mux_predict_vector_ln471_0_406_d_0 = mux_predict_vector_ln471_0_q[421:
          406];
        state_rbm_0_cmos32soi_rbm_predict_rbm[31]: 
          mux_predict_vector_ln471_0_406_d_0 = mux_sum_ln409_z;
        state_rbm_0_cmos32soi_rbm_predict_rbm[18]: 
          mux_predict_vector_ln471_0_406_d_0 = sub_ln196_0_z_0;
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_406_d_0 = 
          mux_predict_vector_ln471_0_z[421:406];
        default: mux_predict_vector_ln471_0_406_d_0 = 16'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln402_z: mux_predict_vector_ln471_0_422_d_0 = {add_ln400_z[6:1], 
          mux_h_ln400_z[0]};
        mux_predict_vector_ln471_0_422_mux_0_sel: 
          mux_predict_vector_ln471_0_422_d_0 = mux_predict_vector_ln471_0_q[428:
          422];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_422_d_0 = 
          mux_predict_vector_ln471_0_z[428:422];
        default: mux_predict_vector_ln471_0_422_d_0 = 7'hX;
      endcase
      mux_predict_vector_ln471_0_368_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | ctrlAnd_1_ln402_z | 
      ctrlAnd_0_ln402_z | state_rbm_0_cmos32soi_rbm_predict_rbm[19] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30];
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln402_z: mux_predict_vector_ln471_0_447_d_0 = sub_ln196_z_0[14:
          1];
        mux_predict_vector_ln471_0_447_mux_0_sel: 
          mux_predict_vector_ln471_0_447_d_0 = mux_predict_vector_ln471_0_q[460:
          447];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_447_d_0 = 
          mux_predict_vector_ln471_0_z[460:447];
        default: mux_predict_vector_ln471_0_447_d_0 = 14'hX;
      endcase
      mux_v_ln388_sel = state_rbm_0_cmos32soi_rbm_predict_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | ctrlOr_ln51_z_0 | 
      ctrlOr_ln471_z | ctrlOr_ln461_z | ctrlOr_ln423_z | ctrlOr_ln396_z | 
      ctrlAnd_1_ln461_z | ctrlAnd_1_ln434_z | ctrlAnd_1_ln423_z | 
      ctrlAnd_1_ln402_z | ctrlAnd_1_ln396_z | ctrlAnd_0_ln402_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[19] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30];
      visibleEnergies_bridge0_rtl_CE_en = ctrlAnd_0_ln402_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[19];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_144_d_0 = add_ln271_0_z[11:4];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_144_d_0 = 
          mux_predict_vector_ln471_0_z[151:144];
        ctrlOr_ln901_z: mux_predict_vector_ln471_0_144_d_0 = {
          mux_prediction_ln905_z, lt_ln901_z, add_ln901_z[2:1], mux_j_ln901_z[0]};
        default: mux_predict_vector_ln471_0_144_d_0 = 8'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln238_z: mux_predict_vector_ln471_0_101_d_0 = {add_ln236_z[8:1], 
          mux_v_ln236_z[0], mux_sum_ln236_z[15]};
        mux_predict_vector_ln471_0_487_mux_0_sel: 
          mux_predict_vector_ln471_0_101_d_0 = mux_predict_vector_ln471_0_q[110:
          101];
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_101_d_0 = {
          mux_this__ln361_0_z_0[3:0], add_ln51_z_0[6:1]};
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_101_d_0 = 
          mux_predict_vector_ln471_0_z[110:101];
        default: mux_predict_vector_ln471_0_101_d_0 = 10'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln238_z: mux_predict_vector_ln471_0_429_d_0 = {add_ln244_z[15:
          7], add_ln244_z[0]};
        state_rbm_0_cmos32soi_rbm_predict_rbm[36]: 
          mux_predict_vector_ln471_0_429_d_0 = {mux_predict_vector_ln471_0_q[444:
          436], mux_predict_vector_ln471_0_q[429]};
        state_rbm_0_cmos32soi_rbm_predict_rbm[29]: 
          mux_predict_vector_ln471_0_429_d_0 = {add_ln407_0_z[15:7], 
          add_ln407_0_z[0]};
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_429_d_0 = {
          mux_predict_vector_ln471_0_z[444:436], mux_predict_vector_ln471_0_z[
          429]};
        default: mux_predict_vector_ln471_0_429_d_0 = 10'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln238_z: mux_predict_vector_ln471_0_430_d_0 = add_ln244_z[6:1];
        state_rbm_0_cmos32soi_rbm_predict_rbm[36]: 
          mux_predict_vector_ln471_0_430_d_0 = mux_predict_vector_ln471_0_q[435:
          430];
        ctrlAnd_1_ln402_z: mux_predict_vector_ln471_0_430_d_0 = mux_h_ln400_z[6:
          1];
        state_rbm_0_cmos32soi_rbm_predict_rbm[29]: 
          mux_predict_vector_ln471_0_430_d_0 = add_ln407_0_z[6:1];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_430_d_0 = 
          mux_predict_vector_ln471_0_z[435:430];
        default: mux_predict_vector_ln471_0_430_d_0 = 6'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln238_z: mux_predict_vector_ln471_0_487_d_0 = mux_sum_ln236_z[
          14:0];
        mux_predict_vector_ln471_0_487_mux_0_sel: 
          mux_predict_vector_ln471_0_487_d_0 = {mux_sum_ln236_14_q, 
          mux_predict_vector_ln471_0_q[500:487]};
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_487_d_0 = {mux_j_ln471_z[0], 
          mux_predict_vector_ln471_0_z[500:487]};
        default: mux_predict_vector_ln471_0_487_d_0 = 15'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln238_z: mux_predict_vector_ln471_0_154_d_0 = 
          rbm_0_cmos32soi_sigmoid_ln250_z;
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_154_d_0 = add_ln271_0_z[20:
          14];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_154_d_0 = 
          mux_predict_vector_ln471_0_z[160:154];
        default: mux_predict_vector_ln471_0_154_d_0 = 7'hX;
      endcase
      mux_predict_vector_ln471_0_464_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[34] | ctrlOr_ln883_z | 
      ctrlOr_ln879_z | ctrlAnd_1_ln883_z | ctrlAnd_1_ln238_z | ctrlAnd_1_ln231_z | 
      ctrlAnd_0_ln242_z | ctrlAnd_0_ln238_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[36];
      mux_predict_vector_ln471_0_474_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[34] | ctrlAnd_1_ln238_z | 
      ctrlAnd_0_ln242_z | ctrlAnd_0_ln238_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[36];
      mux_predict_vector_ln471_0_475_mux_0_sel = ctrlAnd_1_ln238_z | 
      ctrlAnd_0_ln242_z | ctrlAnd_0_ln238_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[36];
      mux_user_ln863_mux_0_sel = state_rbm_0_cmos32soi_rbm_predict_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[34] | ctrlOr_ln921_z | 
      ctrlOr_ln918_z | ctrlOr_ln901_z | ctrlOr_ln895_0_z | ctrlOr_ln883_z | 
      ctrlOr_ln879_z | ctrlOr_ln51_z_0 | ctrlOr_ln461_z | ctrlOr_ln434_z | 
      ctrlOr_ln423_z | ctrlOr_ln396_z | ctrlAnd_1_ln897_z | ctrlAnd_1_ln883_z | 
      ctrlAnd_1_ln461_z | ctrlAnd_1_ln434_z | ctrlAnd_1_ln423_z | 
      ctrlAnd_1_ln402_z | ctrlAnd_1_ln396_z | ctrlAnd_1_ln238_z | 
      ctrlAnd_1_ln231_z | ctrlAnd_0_ln402_z | ctrlAnd_0_ln242_z | 
      ctrlAnd_0_ln238_z | ctrlAnd_0_ln231_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[22] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[19] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[36];
      read_rbm_num_testusers_ln850_sel = 
      state_rbm_0_cmos32soi_rbm_predict_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[34] | ctrlOr_ln921_z | 
      ctrlOr_ln918_z | ctrlOr_ln901_z | ctrlOr_ln895_0_z | ctrlOr_ln883_z | 
      ctrlOr_ln879_z | ctrlOr_ln876_z | ctrlOr_ln51_z_0 | ctrlOr_ln471_z | 
      ctrlOr_ln461_z | ctrlOr_ln434_z | ctrlOr_ln423_z | ctrlOr_ln396_z | 
      ctrlAnd_1_ln897_z | ctrlAnd_1_ln883_z | ctrlAnd_1_ln461_z | 
      ctrlAnd_1_ln434_z | ctrlAnd_1_ln423_z | ctrlAnd_1_ln402_z | 
      ctrlAnd_1_ln396_z | ctrlAnd_1_ln390_z | ctrlAnd_1_ln238_z | 
      ctrlAnd_1_ln231_z | ctrlAnd_0_ln402_z | ctrlAnd_0_ln390_z | 
      ctrlAnd_0_ln242_z | ctrlAnd_0_ln238_z | ctrlAnd_0_ln231_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[22] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[19] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[36];
      add_ln925_1_10_mux_0_sel = state_rbm_0_cmos32soi_rbm_predict_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[29] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[34] | ctrlOr_ln921_z | 
      ctrlOr_ln918_z | ctrlOr_ln901_z | ctrlOr_ln895_0_z | ctrlOr_ln883_z | 
      ctrlOr_ln879_z | ctrlOr_ln51_z_0 | ctrlOr_ln471_z | ctrlOr_ln461_z | 
      ctrlOr_ln434_z | ctrlOr_ln423_z | ctrlOr_ln396_z | ctrlAnd_1_ln897_z | 
      ctrlAnd_1_ln883_z | ctrlAnd_1_ln461_z | ctrlAnd_1_ln434_z | 
      ctrlAnd_1_ln423_z | ctrlAnd_1_ln402_z | ctrlAnd_1_ln396_z | 
      ctrlAnd_1_ln390_z | ctrlAnd_1_ln238_z | ctrlAnd_1_ln231_z | 
      ctrlAnd_0_ln402_z | ctrlAnd_0_ln390_z | ctrlAnd_0_ln242_z | 
      ctrlAnd_0_ln238_z | ctrlAnd_0_ln231_z | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[22] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[19] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[31] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[30] | 
      state_rbm_0_cmos32soi_rbm_predict_rbm[36];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_287_d_0 = add_ln271_z_0[31:
          19];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_287_d_0 = 
          mux_predict_vector_ln471_0_z[299:287];
        default: mux_predict_vector_ln471_0_287_d_0 = 13'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z_0: mux_predict_vector_ln471_0_223_d_0 = {add_ln271_z_0[18:
          0], mux_rem_ln58_z_0[63:19]};
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_223_d_0 = 
          mux_predict_vector_ln471_0_z[286:223];
        default: mux_predict_vector_ln471_0_223_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln396_z: mux_predict_vector_ln471_0_369_d_0 = mux_j_ln396_z[2:1];
        mux_predict_vector_ln471_0_369_mux_0_sel: 
          mux_predict_vector_ln471_0_369_d_0 = mux_predict_vector_ln471_0_q[370:
          369];
        ctrlOr_ln423_z: mux_predict_vector_ln471_0_369_d_0 = mux_j_ln423_z[2:1];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_369_d_0 = 
          mux_predict_vector_ln471_0_z[370:369];
        default: mux_predict_vector_ln471_0_369_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln396_z: mux_predict_vector_ln471_0_371_d_0 = mux_max_ln396_z[1:0];
        mux_predict_vector_ln471_0_371_mux_0_sel: 
          mux_predict_vector_ln471_0_371_d_0 = mux_predict_vector_ln471_0_q[372:
          371];
        ctrlAnd_0_ln402_z: mux_predict_vector_ln471_0_371_d_0 = mux_max_ln417_z[
          1:0];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_371_d_0 = 
          mux_predict_vector_ln471_0_z[372:371];
        default: mux_predict_vector_ln471_0_371_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln396_z: mux_predict_vector_ln471_0_389_d_0 = mult_ln407_z;
        mux_predict_vector_ln471_0_373_mux_0_sel: 
          mux_predict_vector_ln471_0_389_d_0 = mux_predict_vector_ln471_0_q[404:
          389];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_389_d_0 = 
          mux_predict_vector_ln471_0_z[404:389];
        default: mux_predict_vector_ln471_0_389_d_0 = 16'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln396_z: mux_predict_vector_ln471_0_373_d_0 = {lt_ln396_z, 
          add_ln396_z[2:1], mux_max_ln396_z[15:2]};
        mux_predict_vector_ln471_0_373_mux_0_sel: 
          mux_predict_vector_ln471_0_373_d_0 = {mux_predict_vector_ln471_0_q[405], 
          mux_predict_vector_ln471_0_q[388:373]};
        ctrlAnd_0_ln402_z: mux_predict_vector_ln471_0_373_d_0 = {
          mux_predict_vector_ln471_0_q[405], mux_predict_vector_ln471_0_q[388:
          387], mux_max_ln417_z[15:2]};
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_373_d_0 = {
          mux_predict_vector_ln471_0_z[405], mux_predict_vector_ln471_0_z[388:
          373]};
        default: mux_predict_vector_ln471_0_373_d_0 = 17'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln396_z: mux_predict_vector_ln471_0_368_d = mux_j_ln396_z[0];
        mux_predict_vector_ln471_0_368_sel: mux_predict_vector_ln471_0_368_d = 
          mux_predict_vector_ln471_0_q[368];
        ctrlOr_ln423_z: mux_predict_vector_ln471_0_368_d = mux_j_ln423_z[0];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_368_d = 
          mux_predict_vector_ln471_0_z[368];
        default: mux_predict_vector_ln471_0_368_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln390_z: memwrite_pow2_ln455_55_d_0 = mux_pow2_0_ln388_z[118:
          55];
        mux_v_ln388_sel: memwrite_pow2_ln455_55_d_0 = memwrite_pow2_ln455_q[118:
          55];
        ctrlOr_ln434_z: memwrite_pow2_ln455_55_d_0 = mux_pow2_0_ln434_z[118:55];
        state_rbm_0_cmos32soi_rbm_predict_rbm[22]: memwrite_pow2_ln455_55_d_0 = 
          memwrite_pow2_ln455_z[118:55];
        default: memwrite_pow2_ln455_55_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln390_z: mux_v_ln388_d = {mux_pow2_0_ln388_z[54:0], 
          mux_v_ln388_z};
        mux_v_ln388_sel: mux_v_ln388_d = {memwrite_pow2_ln455_q[54:0], 
          mux_v_ln388_q};
        ctrlOr_ln434_z: mux_v_ln388_d = {mux_pow2_0_ln434_z[54:0], mux_v_ln388_q};
        state_rbm_0_cmos32soi_rbm_predict_rbm[22]: mux_v_ln388_d = {
          memwrite_pow2_ln455_z[54:0], mux_v_ln388_q};
        default: mux_v_ln388_d = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln390_z: memwrite_pow2_ln455_119_d_0 = {add_ln388_z[8:1], 
          mux_pow2_0_ln388_z[159:119]};
        mux_v_ln388_sel: memwrite_pow2_ln455_119_d_0 = {add_ln388_1_q, 
          memwrite_pow2_ln455_q[159:119]};
        ctrlOr_ln434_z: memwrite_pow2_ln455_119_d_0 = {add_ln388_1_q, 
          mux_pow2_0_ln434_z[159:119]};
        state_rbm_0_cmos32soi_rbm_predict_rbm[22]: memwrite_pow2_ln455_119_d_0 = 
          {add_ln388_1_q, memwrite_pow2_ln455_z[159:119]};
        default: memwrite_pow2_ln455_119_d_0 = 49'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: mux_predict_vector_ln471_0_464_d_0 = mux_mult_ln240_Z_v;
        mux_predict_vector_ln471_0_464_mux_0_sel: 
          mux_predict_vector_ln471_0_464_d_0 = mux_predict_vector_ln471_0_q[473:
          464];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_464_d_0 = 
          mux_predict_vector_ln471_0_z[473:464];
        default: mux_predict_vector_ln471_0_464_d_0 = 10'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln231_z: mux_predict_vector_ln471_0_474_d_0 = {add_ln229_z[6:1], 
          mux_h_ln229_z[0]};
        mux_predict_vector_ln471_0_474_mux_0_sel: 
          mux_predict_vector_ln471_0_474_d_0 = {mux_predict_vector_ln471_0_q[486:
          481], mux_predict_vector_ln471_0_q[474]};
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_474_d_0 = {
          mux_predict_vector_ln471_0_z[486:481], mux_predict_vector_ln471_0_z[
          474]};
        default: mux_predict_vector_ln471_0_474_d_0 = 7'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln231_z: mux_predict_vector_ln471_0_475_d_0 = mux_h_ln229_z[6:
          1];
        mux_predict_vector_ln471_0_475_mux_0_sel: 
          mux_predict_vector_ln471_0_475_d_0 = mux_predict_vector_ln471_0_q[480:
          475];
        ctrlOr_ln471_z: mux_predict_vector_ln471_0_475_d_0 = 
          mux_predict_vector_ln471_0_z[480:475];
        default: mux_predict_vector_ln471_0_475_d_0 = 6'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: memwrite_rbm_predict_vector_ln481_191_d_0 = {
          mux_mux_predict_vector_ln863_Z_192_v_0[62:0], 
          mux_mux_predict_vector_ln863_Z_128_v_0[63]};
        mux_user_ln863_mux_0_sel: memwrite_rbm_predict_vector_ln481_191_d_0 = 
          memwrite_rbm_predict_vector_ln481_q[254:191];
        ctrlAnd_1_ln390_z: memwrite_rbm_predict_vector_ln481_191_d_0 = 
          mux_predict_vector_ln388_z[254:191];
        ctrlOr_ln471_z: memwrite_rbm_predict_vector_ln481_191_d_0 = 
          mux_predict_vector_ln388_0_z[254:191];
        ctrlAnd_0_ln390_z: memwrite_rbm_predict_vector_ln481_191_d_0 = 
          memwrite_rbm_predict_vector_ln481_z[254:191];
        default: memwrite_rbm_predict_vector_ln481_191_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: memwrite_rbm_predict_vector_ln481_255_d_0 = {
          mux_mux_predict_vector_ln863_Z_256_v_0[62:0], 
          mux_mux_predict_vector_ln863_Z_192_v_0[63]};
        mux_user_ln863_mux_0_sel: memwrite_rbm_predict_vector_ln481_255_d_0 = 
          memwrite_rbm_predict_vector_ln481_q[318:255];
        ctrlAnd_1_ln390_z: memwrite_rbm_predict_vector_ln481_255_d_0 = 
          mux_predict_vector_ln388_z[318:255];
        ctrlOr_ln471_z: memwrite_rbm_predict_vector_ln481_255_d_0 = 
          mux_predict_vector_ln388_0_z[318:255];
        ctrlAnd_0_ln390_z: memwrite_rbm_predict_vector_ln481_255_d_0 = 
          memwrite_rbm_predict_vector_ln481_z[318:255];
        default: memwrite_rbm_predict_vector_ln481_255_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: memwrite_rbm_predict_vector_ln481_319_d_0 = {
          mux_mux_predict_vector_ln863_Z_320_v_0[62:0], 
          mux_mux_predict_vector_ln863_Z_256_v_0[63]};
        mux_user_ln863_mux_0_sel: memwrite_rbm_predict_vector_ln481_319_d_0 = 
          memwrite_rbm_predict_vector_ln481_q[382:319];
        ctrlAnd_1_ln390_z: memwrite_rbm_predict_vector_ln481_319_d_0 = 
          mux_predict_vector_ln388_z[382:319];
        ctrlOr_ln471_z: memwrite_rbm_predict_vector_ln481_319_d_0 = 
          mux_predict_vector_ln388_0_z[382:319];
        ctrlAnd_0_ln390_z: memwrite_rbm_predict_vector_ln481_319_d_0 = 
          memwrite_rbm_predict_vector_ln481_z[382:319];
        default: memwrite_rbm_predict_vector_ln481_319_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: memwrite_rbm_predict_vector_ln481_383_d_0 = {
          mux_mux_predict_vector_ln863_Z_384_v_0[62:0], 
          mux_mux_predict_vector_ln863_Z_320_v_0[63]};
        mux_user_ln863_mux_0_sel: memwrite_rbm_predict_vector_ln481_383_d_0 = 
          memwrite_rbm_predict_vector_ln481_q[446:383];
        ctrlAnd_1_ln390_z: memwrite_rbm_predict_vector_ln481_383_d_0 = 
          mux_predict_vector_ln388_z[446:383];
        ctrlOr_ln471_z: memwrite_rbm_predict_vector_ln481_383_d_0 = 
          mux_predict_vector_ln388_0_z[446:383];
        ctrlAnd_0_ln390_z: memwrite_rbm_predict_vector_ln481_383_d_0 = 
          memwrite_rbm_predict_vector_ln481_z[446:383];
        default: memwrite_rbm_predict_vector_ln481_383_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: memwrite_rbm_predict_vector_ln481_447_d_0 = {
          mux_add_ln925_Z_1_v_0[9:0], mux_mux_predict_vector_ln863_Z_448_v_0, 
          mux_mux_predict_vector_ln863_Z_384_v_0[63]};
        mux_user_ln863_mux_0_sel: memwrite_rbm_predict_vector_ln481_447_d_0 = {
          add_ln925_1_q[9:0], memwrite_rbm_predict_vector_ln481_q[500:447]};
        ctrlAnd_1_ln390_z: memwrite_rbm_predict_vector_ln481_447_d_0 = {
          add_ln925_1_q[9:0], mux_predict_vector_ln388_z[500:447]};
        ctrlOr_ln471_z: memwrite_rbm_predict_vector_ln481_447_d_0 = {
          add_ln925_1_q[9:0], mux_predict_vector_ln388_0_z[500:447]};
        ctrlAnd_0_ln390_z: memwrite_rbm_predict_vector_ln481_447_d_0 = {
          add_ln925_1_q[9:0], memwrite_rbm_predict_vector_ln481_z[500:447]};
        default: memwrite_rbm_predict_vector_ln481_447_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: memwrite_rbm_predict_vector_ln481_63_d_0 = {
          mux_mux_predict_vector_ln863_Z_64_v_0[62:0], 
          mux_mux_predict_vector_ln863_Z_v[63]};
        mux_user_ln863_mux_0_sel: memwrite_rbm_predict_vector_ln481_63_d_0 = 
          memwrite_rbm_predict_vector_ln481_q[126:63];
        ctrlAnd_1_ln390_z: memwrite_rbm_predict_vector_ln481_63_d_0 = 
          mux_predict_vector_ln388_z[126:63];
        ctrlOr_ln471_z: memwrite_rbm_predict_vector_ln481_63_d_0 = 
          mux_predict_vector_ln388_0_z[126:63];
        ctrlAnd_0_ln390_z: memwrite_rbm_predict_vector_ln481_63_d_0 = 
          memwrite_rbm_predict_vector_ln481_z[126:63];
        default: memwrite_rbm_predict_vector_ln481_63_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: mux_user_ln863_d_0 = {mux_mux_predict_vector_ln863_Z_v[
          62:0], mux_mux_user_ln863_Z_0_v};
        mux_user_ln863_mux_0_sel: mux_user_ln863_d_0 = {
          memwrite_rbm_predict_vector_ln481_q[62:0], mux_user_ln863_q};
        ctrlAnd_1_ln390_z: mux_user_ln863_d_0 = {mux_predict_vector_ln388_z[62:0], 
          mux_user_ln863_q};
        ctrlOr_ln471_z: mux_user_ln863_d_0 = {mux_predict_vector_ln388_0_z[62:0], 
          mux_user_ln863_q};
        ctrlAnd_0_ln390_z: mux_user_ln863_d_0 = {
          memwrite_rbm_predict_vector_ln481_z[62:0], mux_user_ln863_q};
        default: mux_user_ln863_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: memwrite_rbm_predict_vector_ln481_127_d_0 = {
          mux_mux_predict_vector_ln863_Z_128_v_0[62:0], 
          mux_mux_predict_vector_ln863_Z_64_v_0[63]};
        mux_user_ln863_mux_0_sel: memwrite_rbm_predict_vector_ln481_127_d_0 = 
          memwrite_rbm_predict_vector_ln481_q[190:127];
        ctrlAnd_1_ln390_z: memwrite_rbm_predict_vector_ln481_127_d_0 = 
          mux_predict_vector_ln388_z[190:127];
        ctrlOr_ln471_z: memwrite_rbm_predict_vector_ln481_127_d_0 = 
          mux_predict_vector_ln388_0_z[190:127];
        ctrlAnd_0_ln390_z: memwrite_rbm_predict_vector_ln481_127_d_0 = 
          memwrite_rbm_predict_vector_ln481_z[190:127];
        default: memwrite_rbm_predict_vector_ln481_127_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln847_z: read_rbm_num_testusers_ln850_d = {add_ln238_z[16:1], 
          num_hidden, num_visible, num_testusers};
        read_rbm_num_testusers_ln850_sel: read_rbm_num_testusers_ln850_d = {
          add_ln238_1_q, read_rbm_num_hidden_ln852_q, 
          read_rbm_num_visible_ln851_q, read_rbm_num_testusers_ln850_q};
        default: read_rbm_num_testusers_ln850_d = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln847_z: add_ln402_1_d = {and_ln886_z, add_ln402_z[16:1]};
        read_rbm_num_testusers_ln850_sel: add_ln402_1_d = {and_ln886_q, 
          add_ln402_1_q};
        default: add_ln402_1_d = 17'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln876_z: add_ln925_1_10_d_0 = mux_add_ln925_Z_1_v_0[14:10];
        add_ln925_1_10_mux_0_sel: add_ln925_1_10_d_0 = add_ln925_1_q[14:10];
        default: add_ln925_1_10_d_0 = 5'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z_0: rbm_0_cmos32soi_round_ln469_round_out_d = 
          rbm_0_cmos32soi_round__ln469_z;
        rbm_0_cmos32soi_round_ln469_round_out_sel: 
          rbm_0_cmos32soi_round_ln469_round_out_d = 
          rbm_0_cmos32soi_round_ln469_round_out_q;
        default: rbm_0_cmos32soi_round_ln469_round_out_d = 4'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_predict_rbm[0]: // Wait_ln847
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln847_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[0] = 
                1'b1;
              ctrlAnd_1_ln847_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[1] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[1]: // expand_ln863
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln869_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[2] = 
                1'b1;
              ctrlOr_ln876_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[3] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[2]: // Wait_ln869
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[2] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[3]: // Wait_ln876
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln876_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[3] = 
                1'b1;
              ctrlOr_ln879_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[4] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[4]: // Wait_ln879
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln879_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[4] = 
                1'b1;
              ctrlOr_ln883_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[5] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[5]: // Wait_ln883
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln883_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[5] = 
                1'b1;
              ctrlAnd_1_ln883_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[6] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[6]: // expand_ln229
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln231_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[7] = 
                1'b1;
              ctrlAnd_1_ln231_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[33] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[7]: // Wait_ln263
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln390_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[8] = 
                1'b1;
              ctrlAnd_1_ln390_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[14] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[8]: // expand_ln895
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[9] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[9]: // xformState_ln895
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln918_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[10] = 
                1'b1;
              ctrlAnd_1_ln897_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[12] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[10]: // Wait_ln918
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln918_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[10] = 
                1'b1;
              ctrlOr_ln921_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[11] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[11]: // Wait_ln921
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln921_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[11] = 
                1'b1;
              ctrlOr_ln869_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[2] = 
                1'b1;
              ctrlOr_ln876_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[3] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[12]: // expand_ln901
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[13] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[13]: // Wait_ln904
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln901_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[13] = 
                1'b1;
              ctrlOr_ln895_0_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[9] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[14]: // expand_ln396
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[15] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[15]: // expand_ln400
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln402_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[16] = 
                1'b1;
              ctrlAnd_1_ln402_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[29] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[16]: // Wait_ln416
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln396_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[15] = 
                1'b1;
              ctrlAnd_1_ln396_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[17] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[17]: // expand_ln423
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[18] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[18]: // expand_ln426
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[19] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[19]: // Wait_ln426
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[20] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[20]: // Wait_ln428
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln423_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[18] = 
                1'b1;
              ctrlAnd_1_ln423_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[21] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[21]: // expand_ln434
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[22] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[22]: // Wait_ln438
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[23] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[23]: // expand_ln434_0
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln434_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[22] = 
                1'b1;
              ctrlAnd_1_ln434_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[24] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[24]: // expand_ln461
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[25] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[25]: // Wait_ln464
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[26] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[26]: // expand_ln51
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln51_z_0: state_rbm_0_cmos32soi_rbm_predict_rbm_next[26] = 
                1'b1;
              ctrlOr_ln461_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[25] = 
                1'b1;
              ctrlAnd_1_ln461_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[27] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[27]: // expand_ln471
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[28] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[28]: // Wait_ln477
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln471_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[28] = 
                1'b1;
              ctrlAnd_0_ln390_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[8] = 
                1'b1;
              ctrlAnd_1_ln390_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[14] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[29]: // expand_ln406
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[30] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[30]: // Wait_ln406
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[31] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[31]: // Wait_ln408
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[32] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[32]: // Wait_ln413
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln402_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[16] = 
                1'b1;
              ctrlAnd_1_ln402_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[29] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[33]: // expand_ln236
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln238_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[34] = 
                1'b1;
              ctrlAnd_1_ln238_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[36] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[34]: // expand_ln236_0
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[35] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[35]: // Wait_ln259
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln231_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[7] = 
                1'b1;
              ctrlAnd_1_ln231_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[33] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[36]: // Wait_ln241
          state_rbm_0_cmos32soi_rbm_predict_rbm_next[37] = 1'b1;
        state_rbm_0_cmos32soi_rbm_predict_rbm[37]: // expand_ln242
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln242_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[38] = 
                1'b1;
              ctrlAnd_0_ln238_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[34] = 
                1'b1;
              ctrlAnd_1_ln238_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[36] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_predict_rbm[38]: // Wait_ln245
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln238_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[34] = 
                1'b1;
              ctrlAnd_1_ln238_z: state_rbm_0_cmos32soi_rbm_predict_rbm_next[36] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
            endcase
          end
        default: // Don't care
          state_rbm_0_cmos32soi_rbm_predict_rbm_next = 39'hX;
      endcase
    end
  rbm_0_cmos32soi_identity_sync_read_128x4m0 predict_result_bridge1(.rtl_CE(
                                             ctrlAnd_1_ln985_z), .rtl_A(
                                             mux_i_ln983_z), .mem_Q(
                                             predict_result_Q1), .CLK(clk), .mem_CE(
                                             predict_result_CE1), .mem_A(
                                             predict_result_A1), .rtl_Q(
                                             memread_rbm_predict_result_ln987_rtl_Q));
  // synopsys sync_set_reset_local rbm_0_cmos32soi_rbm_store_seq_block rst
  always @(posedge clk) // rbm_0_cmos32soi_rbm_store_sequential
    begin : rbm_0_cmos32soi_rbm_store_seq_block
      if (!rst) // Initialize state and outputs
      begin
        output_start <= 1'sb0;
        wr_length <= 32'sh0;
        wr_index <= 32'sh0;
        wr_request <= 1'sb0;
        data_out_set_valid_curr <= 1'sb0;
        data_out_data <= 32'sh0;
        output_done <= 1'b1;
        mul_ln971_q <= 32'sh0;
        mux_index_ln951_q <= 1'sb0;
        read_rbm_num_movies_ln945_q <= 16'sh0;
        read_rbm_num_testusers_ln944_q <= 16'sh0;
        add_ln974_1_q <= 31'sh0;
        done <= 1'sb0;
        state_rbm_0_cmos32soi_rbm_store <= 7'h1;
      end
      else // Update Q values
      begin
        output_start <= output_start_d;
        wr_length <= wr_length_d;
        wr_index <= wr_index_d;
        wr_request <= wr_request_d;
        data_out_set_valid_curr <= data_out_set_valid_curr_d;
        data_out_data <= data_out_data_d;
        output_done <= output_done_d;
        mul_ln971_q <= {mul_ln971_11_d_0, mul_ln971_7_d_0, mul_ln971_d};
        mux_index_ln951_q <= read_rbm_num_testusers_ln944_d[32];
        read_rbm_num_movies_ln945_q <= read_rbm_num_testusers_ln944_d[31:16];
        read_rbm_num_testusers_ln944_q <= read_rbm_num_testusers_ln944_d[15:0];
        add_ln974_1_q <= read_rbm_num_testusers_ln944_d[63:33];
        done <= done_d;
        state_rbm_0_cmos32soi_rbm_store <= state_rbm_0_cmos32soi_rbm_store_next;
      end
    end
      reg ctrlOr_ln272_z;
      reg unary_nor_ln95_z;
      reg ctrlAnd_1_ln941_z;
      reg ctrlAnd_0_ln941_z;
      reg ctrlAnd_1_ln963_z;
      reg ctrlAnd_0_ln963_z;
      reg ctrlAnd_1_ln966_z;
      reg ctrlAnd_0_ln966_z;
      reg ctrlAnd_1_ln978_z;
      reg ctrlAnd_0_ln978_z;
      reg [15:0] mux_read_rbm_num_movies_ln945_Z_v;
      reg [15:0] mux_read_rbm_num_testusers_ln944_Z_v;
      reg [31:0] mux_index_ln951_z;
      reg [3:0] mux_memread_rbm_predict_result_ln987_Q_v;
      reg output_start_hold;
      reg ctrlOr_ln966_z;
      reg wr_request_hold;
      reg ctrlOr_ln978_z;
      reg [15:0] mux_read_rbm_num_movies_ln945_Z_0_mux_0_v;
      reg [15:0] mux_read_rbm_num_testusers_ln944_Z_0_mux_0_v;
      reg eq_ln985_z;
      reg lt_ln983_z;
      reg [6:0] add_ln983_z;
      reg eq_ln954_z;
      reg mux_mux_index_ln951_Z_0_v;
      reg [31:0] mul_ln971_z;
      reg [31:0] add_ln974_z;
      reg if_ln985_z;
      reg if_ln983_z;
      reg [31:0] mux_mul_ln971_Z_v;
      reg [30:0] mux_add_ln974_Z_1_v_0;
      reg ctrlAnd_1_ln272_z;
      reg ctrlAnd_0_ln272_z;
      reg and_1_ln985_z;
      reg or_and_0_ln985_Z_0_z;
      reg write_rbm_data_out_data_ln274_en;
      reg ctrlOr_ln983_0_z;
      reg mul_ln971_sel;
      reg ctrlAnd_0_ln985_z;
      reg read_rbm_num_testusers_ln944_sel;
      reg output_done_hold;
      reg ctrlOr_ln951_z;
      reg ctrlAnd_1_ln954_z;
      reg ctrlAnd_0_ln954_z;
      reg ctrlOr_ln963_z;
      reg ctrlOr_ln958_z;
  always @(*) begin : rbm_0_cmos32soi_rbm_store_combinational

      state_rbm_0_cmos32soi_rbm_store_next = 7'h0;
      ctrlOr_ln272_z = state_rbm_0_cmos32soi_rbm_store[6] | 
      state_rbm_0_cmos32soi_rbm_store[5];
      unary_nor_ln95_z = ~data_out_set_valid_curr;
      ctrlAnd_1_ln941_z = init_done & state_rbm_0_cmos32soi_rbm_store[0];
      ctrlAnd_0_ln941_z = !init_done & state_rbm_0_cmos32soi_rbm_store[0];
      ctrlAnd_1_ln963_z = predict_done & state_rbm_0_cmos32soi_rbm_store[2];
      ctrlAnd_0_ln963_z = !predict_done & state_rbm_0_cmos32soi_rbm_store[2];
      ctrlAnd_1_ln966_z = !predict_done & state_rbm_0_cmos32soi_rbm_store[3];
      ctrlAnd_0_ln966_z = predict_done & state_rbm_0_cmos32soi_rbm_store[3];
      ctrlAnd_1_ln978_z = wr_grant & state_rbm_0_cmos32soi_rbm_store[4];
      ctrlAnd_0_ln978_z = !wr_grant & state_rbm_0_cmos32soi_rbm_store[4];
      if (state_rbm_0_cmos32soi_rbm_store[0]) 
        mux_read_rbm_num_movies_ln945_Z_v = num_movies;
      else 
        mux_read_rbm_num_movies_ln945_Z_v = read_rbm_num_movies_ln945_q;
      if (state_rbm_0_cmos32soi_rbm_store[0]) 
        mux_read_rbm_num_testusers_ln944_Z_v = num_testusers;
      else 
        mux_read_rbm_num_testusers_ln944_Z_v = read_rbm_num_testusers_ln944_q;
      if (state_rbm_0_cmos32soi_rbm_store[4]) 
        mux_i_ln983_z = 7'h0;
      else 
        mux_i_ln983_z = {mul_ln971_q[6:1], !mul_ln971_q[0]};
      if (state_rbm_0_cmos32soi_rbm_store[0]) 
        mux_index_ln951_z = 32'h0;
      else 
        mux_index_ln951_z = {add_ln974_1_q, !mux_index_ln951_q};
      if (state_rbm_0_cmos32soi_rbm_store[5]) 
        mux_memread_rbm_predict_result_ln987_Q_v = 
        memread_rbm_predict_result_ln987_rtl_Q;
      else 
        mux_memread_rbm_predict_result_ln987_Q_v = mul_ln971_q[10:7];
      output_start_hold = ~(ctrlAnd_1_ln966_z | ctrlAnd_1_ln963_z);
      ctrlOr_ln966_z = ctrlAnd_0_ln966_z | ctrlAnd_1_ln963_z;
      wr_request_hold = ~(ctrlAnd_1_ln978_z | ctrlAnd_1_ln966_z);
      ctrlOr_ln978_z = ctrlAnd_0_ln978_z | ctrlAnd_1_ln966_z;
      if (state_rbm_0_cmos32soi_rbm_store[2]) 
        mux_read_rbm_num_movies_ln945_Z_0_mux_0_v = read_rbm_num_movies_ln945_q;
      else 
        mux_read_rbm_num_movies_ln945_Z_0_mux_0_v = 
        mux_read_rbm_num_movies_ln945_Z_v;
      if (state_rbm_0_cmos32soi_rbm_store[2]) 
        mux_read_rbm_num_testusers_ln944_Z_0_mux_0_v = 
        read_rbm_num_testusers_ln944_q;
      else 
        mux_read_rbm_num_testusers_ln944_Z_0_mux_0_v = 
        mux_read_rbm_num_testusers_ln944_Z_v;
      eq_ln985_z = {9'h0, mux_i_ln983_z} == read_rbm_num_movies_ln945_q;
      lt_ln983_z = mux_i_ln983_z[6:2] <= 5'h18;
      add_ln983_z = mux_i_ln983_z + 7'h1;
      eq_ln954_z = mux_index_ln951_z == {16'h0, 
      mux_read_rbm_num_testusers_ln944_Z_v};
      if (state_rbm_0_cmos32soi_rbm_store[2]) 
        mux_mux_index_ln951_Z_0_v = mux_index_ln951_q;
      else 
        mux_mux_index_ln951_Z_0_v = mux_index_ln951_z[0];
      mul_ln971_z = mux_index_ln951_z * mux_read_rbm_num_movies_ln945_Z_v;
      add_ln974_z = mux_index_ln951_z + 32'h1;
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln963_z: output_start_d = 1'b1;
        ctrlAnd_1_ln966_z: output_start_d = 1'b0;
        output_start_hold: output_start_d = output_start;
        default: output_start_d = 1'bX;
      endcase
      if (ctrlAnd_1_ln966_z) 
        wr_length_d = {16'h0, num_movies};
      else 
        wr_length_d = wr_length;
      if (ctrlAnd_1_ln966_z) 
        wr_index_d = mul_ln971_q;
      else 
        wr_index_d = wr_index;
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln966_z: wr_request_d = 1'b1;
        ctrlAnd_1_ln978_z: wr_request_d = 1'b0;
        wr_request_hold: wr_request_d = wr_request;
        default: wr_request_d = 1'bX;
      endcase
      if_ln985_z = ~eq_ln985_z;
      if_ln983_z = ~lt_ln983_z;
      if (state_rbm_0_cmos32soi_rbm_store[2]) 
        mux_mul_ln971_Z_v = mul_ln971_q;
      else 
        mux_mul_ln971_Z_v = mul_ln971_z;
      if (state_rbm_0_cmos32soi_rbm_store[2]) 
        mux_add_ln974_Z_1_v_0 = add_ln974_1_q;
      else 
        mux_add_ln974_Z_1_v_0 = add_ln974_z[31:1];
      ctrlAnd_1_ln272_z = data_out_can_put_sig & ctrlOr_ln272_z;
      ctrlAnd_0_ln272_z = !data_out_can_put_sig & ctrlOr_ln272_z;
      and_1_ln985_z = if_ln985_z & lt_ln983_z;
      or_and_0_ln985_Z_0_z = if_ln983_z | eq_ln985_z;
      write_rbm_data_out_data_ln274_en = rst & ctrlAnd_1_ln272_z;
      ctrlOr_ln983_0_z = ctrlAnd_1_ln272_z | ctrlAnd_1_ln978_z;
      mul_ln971_sel = ctrlOr_ln966_z | ctrlAnd_0_ln272_z;
      if (ctrlAnd_1_ln272_z) 
        data_out_set_valid_curr_d = unary_nor_ln95_z;
      else 
        data_out_set_valid_curr_d = data_out_set_valid_curr;
      ctrlAnd_1_ln985_z = and_1_ln985_z & ctrlOr_ln983_0_z;
      ctrlAnd_0_ln985_z = or_and_0_ln985_Z_0_z & ctrlOr_ln983_0_z;
      if (write_rbm_data_out_data_ln274_en) 
        data_out_data_d = {28'h0, mux_memread_rbm_predict_result_ln987_Q_v};
      else 
        data_out_data_d = data_out_data;
      read_rbm_num_testusers_ln944_sel = ctrlOr_ln978_z | ctrlOr_ln966_z | 
      ctrlAnd_1_ln985_z | ctrlAnd_0_ln272_z;
      output_done_hold = ~(ctrlAnd_1_ln966_z | ctrlAnd_0_ln985_z);
      ctrlOr_ln951_z = ctrlAnd_0_ln985_z | ctrlAnd_1_ln941_z;
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln966_z: output_done_d = 1'b0;
        ctrlAnd_0_ln985_z: output_done_d = 1'b1;
        output_done_hold: output_done_d = output_done;
        default: output_done_d = 1'bX;
      endcase
      ctrlAnd_1_ln954_z = !eq_ln954_z & ctrlOr_ln951_z;
      ctrlAnd_0_ln954_z = eq_ln954_z & ctrlOr_ln951_z;
      ctrlOr_ln963_z = ctrlAnd_0_ln963_z | ctrlAnd_1_ln954_z;
      ctrlOr_ln958_z = state_rbm_0_cmos32soi_rbm_store[1] | ctrlAnd_0_ln954_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln963_z: mul_ln971_11_d_0 = mux_mul_ln971_Z_v[31:11];
        ctrlOr_ln966_z: mul_ln971_11_d_0 = mul_ln971_q[31:11];
        default: mul_ln971_11_d_0 = 21'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln963_z: mul_ln971_7_d_0 = mux_mul_ln971_Z_v[10:7];
        ctrlOr_ln966_z: mul_ln971_7_d_0 = mul_ln971_q[10:7];
        ctrlAnd_0_ln272_z: mul_ln971_7_d_0 = 
          mux_memread_rbm_predict_result_ln987_Q_v;
        default: mul_ln971_7_d_0 = 4'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln963_z: mul_ln971_d = mux_mul_ln971_Z_v[6:0];
        mul_ln971_sel: mul_ln971_d = mul_ln971_q[6:0];
        ctrlAnd_1_ln985_z: mul_ln971_d = {add_ln983_z[6:1], mux_i_ln983_z[0]};
        default: mul_ln971_d = 7'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln963_z: read_rbm_num_testusers_ln944_d = {mux_add_ln974_Z_1_v_0, 
          mux_mux_index_ln951_Z_0_v, mux_read_rbm_num_movies_ln945_Z_0_mux_0_v, 
          mux_read_rbm_num_testusers_ln944_Z_0_mux_0_v};
        read_rbm_num_testusers_ln944_sel: read_rbm_num_testusers_ln944_d = {
          add_ln974_1_q, mux_index_ln951_q, read_rbm_num_movies_ln945_q, 
          read_rbm_num_testusers_ln944_q};
        default: read_rbm_num_testusers_ln944_d = 64'hX;
      endcase
      if (ctrlAnd_0_ln954_z) 
        done_d = 1'b1;
      else 
        done_d = done;
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_store[0]: // Wait_ln941
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln941_z: state_rbm_0_cmos32soi_rbm_store_next[0] = 1'b1;
              ctrlOr_ln958_z: state_rbm_0_cmos32soi_rbm_store_next[1] = 1'b1;
              ctrlOr_ln963_z: state_rbm_0_cmos32soi_rbm_store_next[2] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_store_next = 7'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_store[1]: // Wait_ln958
          state_rbm_0_cmos32soi_rbm_store_next[1] = 1'b1;
        state_rbm_0_cmos32soi_rbm_store[2]: // Wait_ln963
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln963_z: state_rbm_0_cmos32soi_rbm_store_next[2] = 1'b1;
              ctrlOr_ln966_z: state_rbm_0_cmos32soi_rbm_store_next[3] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_store_next = 7'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_store[3]: // Wait_ln966
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln966_z: state_rbm_0_cmos32soi_rbm_store_next[3] = 1'b1;
              ctrlOr_ln978_z: state_rbm_0_cmos32soi_rbm_store_next[4] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_store_next = 7'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_store[4]: // Wait_ln978
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln978_z: state_rbm_0_cmos32soi_rbm_store_next[4] = 1'b1;
              ctrlOr_ln958_z: state_rbm_0_cmos32soi_rbm_store_next[1] = 1'b1;
              ctrlOr_ln963_z: state_rbm_0_cmos32soi_rbm_store_next[2] = 1'b1;
              ctrlAnd_1_ln985_z: state_rbm_0_cmos32soi_rbm_store_next[5] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_store_next = 7'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_store[5]: // Wait_ln988
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln272_z: state_rbm_0_cmos32soi_rbm_store_next[6] = 1'b1;
              ctrlOr_ln958_z: state_rbm_0_cmos32soi_rbm_store_next[1] = 1'b1;
              ctrlOr_ln963_z: state_rbm_0_cmos32soi_rbm_store_next[2] = 1'b1;
              ctrlAnd_1_ln985_z: state_rbm_0_cmos32soi_rbm_store_next[5] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_store_next = 7'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_store[6]: // Wait_ln272
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln272_z: state_rbm_0_cmos32soi_rbm_store_next[6] = 1'b1;
              ctrlOr_ln958_z: state_rbm_0_cmos32soi_rbm_store_next[1] = 1'b1;
              ctrlOr_ln963_z: state_rbm_0_cmos32soi_rbm_store_next[2] = 1'b1;
              ctrlAnd_1_ln985_z: state_rbm_0_cmos32soi_rbm_store_next[5] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_store_next = 7'hX;
            endcase
          end
        default: // Don't care
          state_rbm_0_cmos32soi_rbm_store_next = 7'hX;
      endcase
    end
  rbm_0_cmos32soi_identity_sync_write_50601x1m0 neg_bridge0(.rtl_CE(
                                                state_rbm_0_cmos32soi_rbm_train_rbm[15]), 
                                                .rtl_A(
                                                memwrite_rbm_visible_unit_ln365_q
                                                [118:103]), .rtl_D(
                                                memwrite_rbm_visible_unit_ln365_q
                                                [182]), .rtl_WE(
                                                state_rbm_0_cmos32soi_rbm_train_rbm[15]), 
                                                .CLK(clk), .mem_CE(neg_CE0), .mem_A(
                                                neg_A0), .mem_D(neg_D0), .mem_WE(
                                                neg_WE0));
  rbm_0_cmos32soi_identity_sync_write_50601x1m0 pos_bridge0(.rtl_CE(
                                                state_rbm_0_cmos32soi_rbm_train_rbm[64]), 
                                                .rtl_A(
                                                memwrite_rbm_visible_unit_ln365_q
                                                [262:247]), .rtl_D(
                                                memwrite_rbm_visible_unit_ln365_q
                                                [264]), .rtl_WE(
                                                state_rbm_0_cmos32soi_rbm_train_rbm[64]), 
                                                .CLK(clk), .mem_CE(pos_CE0), .mem_A(
                                                pos_A0), .mem_D(pos_D0), .mem_WE(
                                                pos_WE0));
  rbm_0_cmos32soi_identity_sync_write_50601x8m0 edges_bridge0(.rtl_CE(
                                                edges_bridge0_rtl_CE_en), .rtl_A(
                                                memwrite_rbm_visible_unit_ln365_q
                                                [118:103]), .rtl_D(
                                                edges_bridge0_rtl_d), .rtl_WE(
                                                edges_bridge0_rtl_CE_en), .CLK(
                                                clk), .mem_CE(edges_CE0), .mem_A(
                                                edges_A0), .mem_D(edges_D0), .mem_WE(
                                                edges_WE0));
  rbm_0_cmos32soi_identity_sync_read_5x16m0 visibleEnergies_bridge3(.rtl_CE(
                                            visibleEnergies_bridge3_rtl_CE_en), 
                                            .rtl_A(visibleEnergies_bridge3_rtl_a), 
                                            .mem_Q(visibleEnergies_Q3), .CLK(clk), 
                                            .mem_CE(visibleEnergies_CE3), .mem_A(
                                            visibleEnergies_A3), .rtl_Q(
                                            visibleEnergies_bridge3_rtl_Q));
  rbm_0_cmos32soi_identity_sync_read_50601x1m0 neg_bridge1(.rtl_CE(
                                               ctrlOr_ln803_z), .rtl_A(
                                               mux_add_ln811_Z_v), .mem_Q(neg_Q1), 
                                               .CLK(clk), .mem_CE(neg_CE1), .mem_A(
                                               neg_A1), .rtl_Q(
                                               memread_rbm_neg_ln813_rtl_Q));
  rbm_0_cmos32soi_identity_sync_read_50601x1m0 pos_bridge1(.rtl_CE(
                                               ctrlOr_ln803_z), .rtl_A(
                                               mux_add_ln811_Z_v), .mem_Q(pos_Q1), 
                                               .CLK(clk), .mem_CE(pos_CE1), .mem_A(
                                               pos_A1), .rtl_Q(
                                               memread_rbm_pos_ln812_rtl_Q));
  rbm_0_cmos32soi_identity_sync_read_101x1m0 hidden_unit_bridge3(.rtl_CE(
                                             hidden_unit_bridge3_rtl_CE_en), .rtl_A(
                                             hidden_unit_bridge3_rtl_a), .mem_Q(
                                             hidden_unit_Q3), .CLK(clk), .mem_CE(
                                             hidden_unit_CE3), .mem_A(
                                             hidden_unit_A3), .rtl_Q(
                                             hidden_unit_bridge3_rtl_Q));
  rbm_0_cmos32soi_identity_sync_write_5x16m0 visibleEnergies_bridge1(.rtl_CE(
                                             visibleEnergies_bridge1_rtl_CE_en), 
                                             .rtl_A(
                                             memwrite_rbm_visible_unit_ln365_q[
                                             44:42]), .rtl_D(
                                             visibleEnergies_bridge1_rtl_d), .rtl_WE(
                                             visibleEnergies_bridge1_rtl_CE_en), 
                                             .CLK(clk), .mem_CE(
                                             visibleEnergies_CE1), .mem_A(
                                             visibleEnergies_A1), .mem_D(
                                             visibleEnergies_D1), .mem_WE(
                                             visibleEnergies_WE1));
  rbm_0_cmos32soi_identity_sync_write_101x1m0 hidden_unit_bridge1(.rtl_CE(
                                              hidden_unit_bridge1_rtl_CE_en), .rtl_A(
                                              hidden_unit_bridge1_rtl_a), .rtl_D(
                                              hidden_unit_bridge1_rtl_d), .rtl_WE(
                                              hidden_unit_bridge1_rtl_CE_en), .CLK(
                                              clk), .mem_CE(hidden_unit_CE1), .mem_A(
                                              hidden_unit_A1), .mem_D(
                                              hidden_unit_D1), .mem_WE(
                                              hidden_unit_WE1));
  rbm_0_cmos32soi_identity_sync_write_624x32m0 mt_bridge0(.rtl_CE(
                                               mt_bridge0_rtl_CE_en), .rtl_A(
                                               mt_bridge0_rtl_a), .rtl_D(
                                               mt_bridge0_rtl_d), .rtl_WE(
                                               mt_bridge0_rtl_CE_en), .CLK(clk), 
                                               .mem_CE(mt_CE0), .mem_A(mt_A0), .mem_D(
                                               mt_D0), .mem_WE(mt_WE0));
  rbm_0_cmos32soi_identity_sync_read_50601x8m0 edges_bridge2(.rtl_CE(
                                               edges_bridge2_rtl_CE_en), .rtl_A(
                                               edges_bridge2_rtl_a), .mem_Q(
                                               edges_Q2), .CLK(clk), .mem_CE(
                                               edges_CE2), .mem_A(edges_A2), .rtl_Q(
                                               edges_bridge2_rtl_Q));
  rbm_0_cmos32soi_identity_sync_read_624x32m0 mt_bridge1(.rtl_CE(
                                              mt_bridge1_rtl_CE_en), .rtl_A(
                                              mt_bridge1_rtl_a), .mem_Q(mt_Q1), 
                                              .CLK(clk), .mem_CE(mt_CE1), .mem_A(
                                              mt_A1), .rtl_Q(mt_bridge1_rtl_Q));
  rbm_0_cmos32soi_identity_sync_read_1002x8m0 data_bridge1(.rtl_CE(
                                              data_bridge1_rtl_CE_en), .rtl_A(
                                              data_bridge1_rtl_a), .mem_Q(
                                              data_Q1), .CLK(clk), .mem_CE(
                                              data_CE1), .mem_A(data_A1), .rtl_Q(
                                              data_bridge1_rtl_Q));
  // synopsys sync_set_reset_local rbm_0_cmos32soi_rbm_train_rbm_seq_block rst //**train**//
  always @(posedge clk) // rbm_0_cmos32soi_rbm_train_rbm_sequential
    begin : rbm_0_cmos32soi_rbm_train_rbm_seq_block
      if (!rst) // Initialize state and outputs
      begin
        memread_rbm_mt_ln116_0_Q_0_tag_0 <= 1'sb0;
        memread_rbm_mt_ln116_Q_0_tag_0 <= 1'sb0;
        memread_rbm_mt_ln134_0_Q_0_tag_0 <= 1'sb0;
        memread_rbm_mt_ln134_Q_0_tag_0 <= 1'sb0;
        memread_rbm_mt_ln91_0_Q_0_tag_0 <= 1'sb0;
        memread_rbm_mt_ln91_Q_0_tag_0 <= 1'sb0;
        memread_rbm_hidden_unit_ln298_Q_0_tag_0 <= 1'sb0;
        mti_signal <= 32'h271;
        train_done <= 1'sb0;
        train_start <= 1'sb0;
        lt_ln51_q <= 1'sb0;
        mux_this_ln361_0_2_q <= 11'sh0;
        memread_rbm_mt_ln116_0_2_q <= 18'sh0;
        memread_pow2_ln359_q <= 32'sh0;
        add_ln365_q <= 9'sh0;
        lt_ln356_q <= 1'sb0;
        mux_j_ln356_q <= 1'sb0;
        add_ln356_1_q <= 2'sh0;
        add_ln281_q <= 64'sh0;
        add_ln271_q <= 64'sh0;
        sub_ln196_0_1_q <= 1'sb0;
        mux_v_ln282_q <= 9'sh0;
        memwrite_pow2_ln351_q <= 160'sh0;
        add_ln282_1_q <= 8'sh0;
        mux_mti_ln59_0_q <= 9'sh0;
        mux_rem_ln58_q <= 64'sh0;
        memwrite_rbm_visible_unit_ln365_q <= 501'sh0;
        memwrite_rbm_visible_unit_ln369_q <= 501'sh0;
        mult_ln195_q <= 10'sh0;
        mux_user_ln745_q <= 1'sb0;
        add_ln745_1_q <= 31'sh0;
        and_ln757_q <= 1'sb0;
        mux_current_loop_ln733_q <= 1'sb0;
        add_ln836_1_q <= 31'sh0;
        read_rbm_num_loops_ln690_q <= 16'sh0;
        read_rbm_num_users_ln689_q <= 16'sh0;
        read_rbm_num_visible_ln687_q <= 16'sh0;
        read_rbm_num_hidden_ln688_q <= 16'sh0;
        add_ln713_1_q <= 16'sh0;
        add_ln708_1_q <= 16'sh0;
        state_rbm_0_cmos32soi_rbm_train_rbm <= 95'h1;
      end
      else // Update Q values
      begin
        memread_rbm_mt_ln116_0_Q_0_tag_0 <= memread_rbm_mt_ln116_0_Q_0_tag_d;
        memread_rbm_mt_ln116_Q_0_tag_0 <= memread_rbm_mt_ln116_Q_0_tag_d;
        memread_rbm_mt_ln134_0_Q_0_tag_0 <= memread_rbm_mt_ln134_0_Q_0_tag_d;
        memread_rbm_mt_ln134_Q_0_tag_0 <= memread_rbm_mt_ln134_Q_0_tag_d;
        memread_rbm_mt_ln91_0_Q_0_tag_0 <= memread_rbm_mt_ln91_0_Q_0_tag_d;
        memread_rbm_mt_ln91_Q_0_tag_0 <= memread_rbm_mt_ln91_Q_0_tag_d;
        memread_rbm_hidden_unit_ln298_Q_0_tag_0 <= 
        memread_rbm_hidden_unit_ln298_Q_0_tag_d;
        mti_signal <= mti_signal_d;
        train_done <= train_done_d;
        train_start <= train_start_d;
        lt_ln51_q <= lt_ln51_z;
        mux_this_ln361_0_2_q <= {mux_this_ln361_0_2_1_d_0, 
        mux_this_ln361_0_2_0_d};
        memread_rbm_mt_ln116_0_2_q <= memread_rbm_mt_ln116_0_2_d[17:0];
        memread_pow2_ln359_q <= add_ln365_d[40:9];
        add_ln365_q <= add_ln365_d[8:0];
        lt_ln356_q <= mux_j_ln356_d_0[3];
        mux_j_ln356_q <= mux_j_ln356_d_0[0];
        add_ln356_1_q <= mux_j_ln356_d_0[2:1];
        add_ln281_q <= add_ln281_d;
        add_ln271_q <= {add_ln271_63_d, add_ln271_58_d_0, add_ln271_56_d_0, 
        add_ln271_55_d, add_ln271_24_d_0, add_ln271_23_d, add_ln271_22_d, 
        add_ln271_21_d, add_ln271_16_d_0, add_ln271_14_d_0, add_ln271_12_d_0, 
        add_ln271_11_d, memread_rbm_mt_ln116_0_2_d[28:18]};
        sub_ln196_0_1_q <= sub_ln196_0_1_d;
        mux_v_ln282_q <= mux_v_ln282_d[8:0];
        memwrite_pow2_ln351_q <= {memwrite_pow2_ln351_119_d_0[40:0], 
        memwrite_pow2_ln351_55_d_0, mux_v_ln282_d[63:9]};
        add_ln282_1_q <= memwrite_pow2_ln351_119_d_0[48:41];
        mux_mti_ln59_0_q <= {mux_mti_ln59_0_8_d, mux_mti_ln59_0_1_d_0, 
        mux_mti_ln59_0_0_d};
        mux_rem_ln58_q <= {mux_rem_ln58_63_d, mux_rem_ln58_55_d_0, 
        mux_rem_ln58_54_d, mux_rem_ln58_49_d_0, mux_rem_ln58_47_d_0, 
        mux_rem_ln58_46_d, mux_rem_ln58_44_d_0, mux_rem_ln58_34_d_0, 
        mux_rem_ln58_31_d_0, mux_rem_ln58_27_d_0, mux_rem_ln58_14_d_0[6:1], 
        mux_rem_ln58_15_d_0, mux_rem_ln58_14_d_0[0], mux_rem_ln58_11_d_0, 
        mux_rem_ln58_d};
        memwrite_rbm_visible_unit_ln365_q <= {
        memwrite_rbm_visible_unit_ln365_495_d_0, 
        memwrite_rbm_visible_unit_ln365_431_d_0, 
        memwrite_rbm_visible_unit_ln365_367_d_0, 
        memwrite_rbm_visible_unit_ln365_303_d_0, 
        memwrite_rbm_visible_unit_ln365_294_d_0, 
        memwrite_rbm_visible_unit_ln365_268_d_0, 
        memwrite_rbm_visible_unit_ln365_267_d, 
        memwrite_rbm_visible_unit_ln365_266_d, 
        memwrite_rbm_visible_unit_ln365_265_d, 
        memwrite_rbm_visible_unit_ln365_264_d, 
        memwrite_rbm_visible_unit_ln365_241_d_0, 
        memwrite_rbm_visible_unit_ln365_240_d, 
        memwrite_rbm_visible_unit_ln365_214_d_0, 
        memwrite_rbm_visible_unit_ln365_183_d_0, 
        memwrite_rbm_visible_unit_ln365_182_d, 
        memwrite_rbm_visible_unit_ln365_181_d, 
        memwrite_rbm_visible_unit_ln365_156_d_0, 
        memwrite_rbm_visible_unit_ln365_148_d_0, 
        memwrite_rbm_visible_unit_ln365_141_d_0, 
        memwrite_rbm_visible_unit_ln365_140_d, 
        memwrite_rbm_visible_unit_ln365_121_d_0, 
        memwrite_rbm_visible_unit_ln365_119_d_0, 
        memwrite_rbm_visible_unit_ln365_103_d_0[9:1], 
        memwrite_rbm_visible_unit_ln365_104_d_0, 
        memwrite_rbm_visible_unit_ln365_103_d_0[0], 
        memwrite_rbm_visible_unit_ln365_97_d_0, 
        memwrite_rbm_visible_unit_ln365_96_d, 
        memwrite_rbm_visible_unit_ln365_80_d_0, 
        memwrite_rbm_visible_unit_ln365_47_d_0[16], 
        memwrite_rbm_visible_unit_ln365_63_d_0, 
        memwrite_rbm_visible_unit_ln365_47_d_0[15:0], 
        memwrite_rbm_visible_unit_ln365_45_d_0, 
        memwrite_rbm_visible_unit_ln365_43_d_0, 
        memwrite_rbm_visible_unit_ln365_42_d, 
        memwrite_rbm_visible_unit_ln365_10_d_0, 
        memwrite_rbm_visible_unit_ln365_6_d_0, 
        memwrite_rbm_visible_unit_ln365_4_d_0, memwrite_rbm_visible_unit_ln365_d};
        memwrite_rbm_visible_unit_ln369_q <= {
        memwrite_rbm_visible_unit_ln369_448_d_0, 
        memwrite_rbm_visible_unit_ln369_384_d_0, 
        memwrite_rbm_visible_unit_ln369_320_d_0, 
        memwrite_rbm_visible_unit_ln369_256_d_0, 
        memwrite_rbm_visible_unit_ln369_192_d_0, 
        memwrite_rbm_visible_unit_ln369_128_d_0, 
        memwrite_rbm_visible_unit_ln369_64_d_0, 
        memwrite_rbm_visible_unit_ln369_d};
        mult_ln195_q <= mux_user_ln745_d_0[41:32];
        mux_user_ln745_q <= mux_user_ln745_d_0[0];
        add_ln745_1_q <= mux_user_ln745_d_0[31:1];
        and_ln757_q <= mux_current_loop_ln733_d_0[32];
        mux_current_loop_ln733_q <= mux_current_loop_ln733_d_0[0];
        add_ln836_1_q <= mux_current_loop_ln733_d_0[31:1];
        read_rbm_num_loops_ln690_q <= read_rbm_num_visible_ln687_d[63:48];
        read_rbm_num_users_ln689_q <= read_rbm_num_visible_ln687_d[47:32];
        read_rbm_num_visible_ln687_q <= read_rbm_num_visible_ln687_d[15:0];
        read_rbm_num_hidden_ln688_q <= read_rbm_num_visible_ln687_d[31:16];
        add_ln713_1_q <= add_ln708_1_d[31:16];
        add_ln708_1_q <= add_ln708_1_d[15:0];
        state_rbm_0_cmos32soi_rbm_train_rbm <= 
        state_rbm_0_cmos32soi_rbm_train_rbm_next;
      end
    end
  rbm_0_cmos32soi_sigmoid rbm_0_cmos32soi_sigmoid(.sum_in(mux_sum_ln191_z), .sigmoid_out(
                          rbm_0_cmos32soi_sigmoid_ln205_z));


      reg ACTIVATE_HIDDEN_TRAIN_V_for_exit_1_or_0;
      reg ACTIVATE_VISIBLE_TRAIN_ENERGY_UPDATE_for_begin_or_0;
      reg RAND_LOOP1_for_begin_0_or_0;
      reg RAND_LOOP1_for_begin_or_0;
      reg RAND_LOOP2_for_begin_0_or_0;
      reg RAND_LOOP2_for_begin_or_0;
      reg ctrlAnd_0_ln198_z;
      reg [15:0] add_ln300_0_z;
      reg [31:0] mul_ln74_z;
      reg [31:0] mul_ln74_0_z;
      reg [63:0] add_ln281_z;
      reg [16:0] add_ln708_z;
      reg [16:0] add_ln713_z;
      reg add_ln271_11_sel;
      reg add_ln271_11_sel_0;
      reg mt_bridge1_rtl_a_sel;
      reg add_ln271_22_sel;
      reg add_ln271_23_sel;
      reg add_ln271_56_mux_0_sel;
      reg add_ln271_58_mux_0_sel;
      reg add_ln271_63_sel;
      reg eq_ln62_z;
      reg eq_ln62_0_z;
      reg ctrlAnd_0_ln111_z;
      reg ctrlAnd_0_ln111_0_z;
      reg ctrlOr_ln184_0_z;
      reg ctrlAnd_0_ln290_z;
      reg ctrlOr_ln294_0_z;
      reg ctrlAnd_0_ln316_z;
      reg ctrlAnd_0_ln328_z;
      reg ctrlAnd_0_ln356_z;
      reg ctrlAnd_0_ln51_z;
      reg ctrlAnd_0_ln67_z;
      reg ctrlAnd_0_ln67_0_z;
      reg ctrlAnd_0_ln713_z;
      reg ctrlAnd_0_ln735_z;
      reg ctrlAnd_0_ln775_z;
      reg ctrlAnd_0_ln799_z;
      reg ctrlAnd_0_ln86_z;
      reg ctrlAnd_0_ln86_0_z;
      reg ctrlAnd_1_ln772_z;
      reg if_ln768_1_or_0;
      reg if_ln794_1_or_0;
      reg memread_rbm_edges_ln300_en;
      reg edges_bridge2_rtl_a_sel;
      reg ifBot_ln803_or_0;
      reg ge_ln59_z;
      reg ge_ln59_0_z;
      reg if_ln777_1_or_0;
      reg if_ln801_1_or_0;
      reg ifBot_ln59_or_0;
      reg if_ln59_0_0_or_0;
      reg memread_rbm_mt_ln116_0_2_sel;
      reg [159:0] mux_pow2_ln328_z;
      reg memwrite_rbm_mt_ln103_0_en;
      reg memwrite_rbm_mt_ln103_en;
      reg memwrite_rbm_mt_ln127_0_en;
      reg memwrite_rbm_mt_ln127_en;
      reg memwrite_rbm_mt_ln144_0_en;
      reg memwrite_rbm_mt_ln144_en;
      reg mt_bridge1_rtl_a_sel_0;
      reg mt_bridge1_rtl_a_sel_1;
      reg mt_bridge1_rtl_a_sel_3;
      reg mt_bridge1_rtl_a_sel_4;
      reg mti_signal_hold;
      reg mux_mti_ln59_0_1_mux_0_sel;
      reg mux_mti_ln59_0_8_sel;
      reg [500:0] mux_visible_unit_ln745_z;
      reg mux_rem_ln58_11_mux_0_sel;
      reg mux_rem_ln58_34_mux_0_sel;
      reg mux_rem_ln58_46_sel;
      reg mux_rem_ln58_47_mux_0_sel;
      reg mux_rem_ln58_49_mux_0_sel;
      reg mux_rem_ln58_54_sel;
      reg mux_rem_ln58_63_sel;
      reg mux_this_ln361_0_2_1_mux_0_sel;
      reg [31:0] mux_mti_ln59_0_z;
      reg [31:0] mux_mti_ln59_z;
      reg [15:0] add_ln176_1_z;
      reg [7:0] add_ln176_z;
      reg [7:0] sub_ln196_z;
      reg [15:0] add_ln176_0_z;
      reg [31:0] add_ln75_z;
      reg [31:0] add_ln75_0_z;
      reg [4:0] add_ln339_z;
      reg [30:0] xor_ln101_z;
      reg [30:0] xor_ln101_0_z;
      reg [30:0] xor_ln125_z;
      reg [30:0] xor_ln125_0_z;
      reg [30:0] xor_ln142_z;
      reg [30:0] xor_ln142_0_z;
      reg [8:0] xor_ln157_z;
      reg [17:0] xor_ln157_0_z;
      reg xor_ln165_3_z;
      reg [1:0] xor_ln73_z;
      reg [1:0] xor_ln73_0_z;
      reg ctrlAnd_1_ln111_0_z;
      reg ctrlAnd_1_ln86_0_z;
      reg ctrlOr_ln111_z;
      reg ctrlOr_ln111_0_z;
      reg ctrlOr_ln290_z;
      reg ctrlOr_ln316_z;
      reg ctrlOr_ln328_z;
      reg ctrlOr_ln356_z;
      reg ctrlOr_ln51_z;
      reg ctrlOr_ln67_z;
      reg ctrlOr_ln67_0_z;
      reg ctrlAnd_1_ln684_z;
      reg ctrlAnd_0_ln684_z;
      reg ctrlOr_ln740_z;
      reg ctrlAnd_1_ln750_z;
      reg ctrlAnd_0_ln750_z;
      reg ctrlAnd_1_ln753_z;
      reg ctrlAnd_0_ln753_z;
      reg ctrlAnd_0_ln772_z;
      reg ctrlOr_ln775_0_z;
      reg ctrlOr_ln799_0_z;
      reg ctrlOr_ln86_z;
      reg ctrlOr_ln86_0_z;
      reg ctrlAnd_1_ln111_z;
      reg ctrlAnd_1_ln198_z;
      reg ctrlAnd_1_ln290_z;
      reg ctrlAnd_1_ln316_z;
      reg ctrlAnd_1_ln328_z;
      reg ctrlAnd_1_ln356_z;
      reg ctrlAnd_1_ln51_z;
      reg ctrlAnd_1_ln67_z;
      reg ctrlAnd_1_ln67_0_z;
      reg ctrlAnd_1_ln713_z;
      reg ctrlAnd_1_ln735_z;
      reg ctrlAnd_1_ln775_z;
      reg ctrlAnd_1_ln799_z;
      reg ctrlAnd_1_ln86_z;
      reg ne_ln772_z;
      reg ne_ln803_z;
      reg unary_or_ln781_z;
      reg eq_ln198_z;
      reg [500:0] mux_visible_unit_ln282_z;
      reg [159:0] mux_pow2_ln282_z;
      reg [15:0] mux_max_ln290_z;
      reg [15:0] mux_sum_ln294_z;
      reg [63:0] mux_sumOfpow2_ln328_z;
      reg [500:0] mux_visible_unit_ln356_z;
      reg [31:0] mux_num_adj_ln51_z;
      reg [63:0] mux_quotient_ln51_z;
      reg [63:0] mux_rem_ln51_z;
      reg [31:0] mux_xor_ln165_0_Z_v;
      reg ternaryMux_ln781_0_z;
      reg ternaryMux_ln808_0_z;
      reg mt_bridge0_rtl_a_sel;
      reg memwrite_rbm_mt_ln129_0_en;
      reg memwrite_rbm_mt_ln129_en;
      reg memwrite_rbm_mt_ln146_0_en;
      reg memwrite_rbm_mt_ln146_en;
      reg memwrite_rbm_mt_ln105_0_en;
      reg memwrite_rbm_mt_ln105_en;
      reg mt_bridge0_rtl_d_sel;
      reg [8:0] mux_v_ln191_z;
      reg [8:0] mux_v_ln766_z;
      reg [8:0] mux_v_ln706_z;
      reg [6:0] mux_h_ln711_z;
      reg [2:0] mux_j_ln316_z;
      reg [2:0] mux_j_ln290_z;
      reg [15:0] sub_ln196_0_0_z;
      reg [2:0] mux_j_ln328_z;
      reg [6:0] mux_h_ln775_z;
      reg [6:0] mux_h_ln799_z;
      reg [6:0] mux_h_ln294_z;
      reg [9:0] mux_kk_ln111_z;
      reg [9:0] mux_kk_ln111_0_z;
      reg [7:0] mux_kk_ln86_z;
      reg [7:0] mux_kk_ln86_0_z;
      reg [9:0] mux_mti_ln67_z;
      reg [9:0] mux_mti_ln67_0_z;
      reg [31:0] mux_current_loop_ln733_z;
      reg [6:0] mux_h_ln184_z;
      reg [6:0] mux_i_ln51_z;
      reg [2:0] mux_j_ln356_z;
      reg [63:0] mux_mux_visible_unit_ln745_Z_192_v_0;
      reg [63:0] mux_mux_visible_unit_ln745_Z_256_v_0;
      reg [63:0] mux_mux_visible_unit_ln745_Z_320_v_0;
      reg [63:0] mux_mux_visible_unit_ln745_Z_384_v_0;
      reg [52:0] mux_mux_visible_unit_ln745_Z_448_v_0;
      reg [63:0] mux_mux_visible_unit_ln745_Z_64_v_0;
      reg [63:0] mux_mux_visible_unit_ln745_Z_v;
      reg [500:0] mux_visible_unit_ln733_z;
      reg [63:0] mux_mux_visible_unit_ln745_Z_128_v_0;
      reg [8:0] mux_v_ln792_z;
      reg [31:0] mux_user_ln745_z;
      reg [8:0] mux_v_ln282_z;
      reg unary_nor_ln817_z;
      reg [31:0] add_ln153_0_z;
      reg [31:0] add_ln153_z;
      reg [15:0] mux_sum_ln302_z;
      reg [15:0] mux_sum_ln198_z;
      reg [2:0] case_mux_tmp_ln333_z;
      reg [14:0] xor_ln103_z;
      reg [14:0] xor_ln103_0_z;
      reg [14:0] xor_ln127_z;
      reg [14:0] xor_ln127_0_z;
      reg [14:0] xor_ln144_z;
      reg [14:0] xor_ln144_0_z;
      reg [5:0] xor_ln160_z;
      reg [12:0] xor_ln160_0_z;
      reg xor_ln165_0_z;
      reg xor_ln165_1_z;
      reg xor_ln165_10_z;
      reg xor_ln165_13_z;
      reg xor_ln165_8_z;
      reg add_ln271_21_sel;
      reg train_start_hold;
      reg ctrlOr_ln753_z;
      reg add_ln365_sel;
      reg add_ln271_14_mux_0_sel;
      reg mt_bridge1_rtl_a_sel_2;
      reg mux_mti_ln59_0_0_sel;
      reg mux_this_ln361_0_2_0_sel;
      reg ctrlOr_ln198_z;
      reg sub_ln196_0_1_sel;
      reg ctrlOr_ln282_0_z;
      reg memwrite_rbm_visible_unit_ln365_103_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_141_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_156_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_183_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_241_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_4_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_6_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_80_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_96_sel;
      reg memwrite_rbm_visible_unit_ln365_97_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_sel;
      reg mux_j_ln356_mux_0_sel;
      reg ctrlAnd_1_ln711_z;
      reg ctrlAnd_0_ln711_z;
      reg mux_rem_ln58_27_mux_0_sel;
      reg [500:0] memwrite_rbm_visible_unit_ln369_z;
      reg gt_ln856_z;
      reg [63:0] mux_mux_visible_unit_ln356_Z_0_mux_0_v;
      reg [63:0] mux_mux_visible_unit_ln356_Z_128_mux_0_v;
      reg [63:0] mux_mux_visible_unit_ln356_Z_128_v_1;
      reg [63:0] mux_mux_visible_unit_ln356_Z_192_mux_0_v;
      reg [63:0] mux_mux_visible_unit_ln356_Z_192_v_1;
      reg [63:0] mux_mux_visible_unit_ln356_Z_256_mux_0_v;
      reg [63:0] mux_mux_visible_unit_ln356_Z_256_v_1;
      reg [63:0] mux_mux_visible_unit_ln356_Z_320_mux_0_v;
      reg [63:0] mux_mux_visible_unit_ln356_Z_320_v_1;
      reg [63:0] mux_mux_visible_unit_ln356_Z_384_mux_0_v;
      reg [63:0] mux_mux_visible_unit_ln356_Z_384_v_1;
      reg [52:0] mux_mux_visible_unit_ln356_Z_448_mux_0_v;
      reg [52:0] mux_mux_visible_unit_ln356_Z_448_v_1;
      reg [63:0] mux_mux_visible_unit_ln356_Z_64_mux_0_v;
      reg [63:0] mux_mux_visible_unit_ln356_Z_64_v_1;
      reg [63:0] mux_mux_visible_unit_ln356_Z_v;
      reg eq_ln368_0_0_z;
      reg eq_ln368_0_z;
      reg [63:0] sub_ln301_z;
      reg le_ln820_z;
      reg and_1_ln62_z;
      reg and_0_ln62_z;
      reg and_1_ln62_0_z;
      reg ctrlAnd_1_ln59_0_z;
      reg and_0_ln62_0_z;
      reg ternaryMux_ln821_0_z;
      reg mt_bridge0_rtl_a_sel_3;
      reg mt_bridge0_rtl_a_sel_0;
      reg mt_bridge0_rtl_a_sel_4;
      reg mt_bridge0_rtl_a_sel_2;
      reg mt_bridge0_rtl_a_sel_1;
      reg mt_bridge0_rtl_d_sel_0;
      reg [8:0] add_ln191_z;
      reg eq_ln193_z;
      reg lt_ln191_z;
      reg [15:0] mult_ln200_z;
      reg [9:0] add_ln195_z;
      reg [8:0] add_ln766_z;
      reg eq_ln768_z;
      reg [15:0] mult_ln781_z;
      reg [9:0] add_ln770_z;
      reg eq_ln708_z;
      reg [15:0] mult_ln715_1_z;
      reg [8:0] add_ln706_z;
      reg [6:0] add_ln711_z;
      reg eq_ln713_z;
      reg [15:0] add_ln715_1_z;
      reg [2:0] add_ln316_z;
      reg [2:0] add_ln290_z;
      reg [9:0] add_ln300_z;
      reg [2:0] add_ln328_z;
      reg [6:0] add_ln775_z;
      reg eq_ln777_z;
      reg [15:0] add_ln781_z;
      reg [15:0] add_ln811_z;
      reg [6:0] add_ln799_z;
      reg eq_ln801_z;
      reg mux_mux_h_ln799_Z_0_v;
      reg [15:0] add_ln808_z;
      reg eq_ln296_z;
      reg lt_ln294_z;
      reg [6:0] add_ln294_z;
      reg [9:0] add_ln117_z;
      reg [9:0] add_ln114_z;
      reg [9:0] add_ln117_0_z;
      reg [9:0] add_ln114_0_z;
      reg [8:0] add_ln89_z;
      reg [9:0] add_ln92_z;
      reg [7:0] add_ln86_z;
      reg [8:0] add_ln89_0_z;
      reg [9:0] add_ln92_0_z;
      reg [7:0] add_ln86_0_z;
      reg [9:0] sub_ln69_z;
      reg [9:0] add_ln67_z;
      reg [9:0] sub_ln69_0_z;
      reg [9:0] add_ln67_0_z;
      reg and_ln757_z;
      reg eq_ln735_z;
      reg [31:0] add_ln836_z;
      reg eq_ln186_z;
      reg lt_ln184_z;
      reg [6:0] add_ln184_z;
      reg [6:0] add_ln51_z;
      reg [2:0] add_ln356_z;
      reg [31:0] memread_pow2_ln359_z;
      reg mux_mux_j_ln356_Z_0_v;
      reg mux_mux_j_ln356_Z_0_v_0;
      reg [8:0] add_ln365_z;
      reg [8:0] add_ln792_z;
      reg eq_ln794_z;
      reg memread_rbm_visible_unit_ln806_z;
      reg [15:0] mult_ln808_z;
      reg [9:0] add_ln796_z;
      reg lt_ln745_z;
      reg mux_mux_user_ln745_Z_0_v;
      reg xor_ln758_z;
      reg [31:0] add_ln745_z;
      reg eq_ln284_z;
      reg lt_ln282_z;
      reg [8:0] add_ln282_z;
      reg ternaryMux_ln817_0_z;
      reg [5:0] mux_tmp_ln333_z;
      reg [4:0] xor_ln163_z;
      reg [10:0] xor_ln163_0_z;
      reg xor_ln165_6_z;
      reg xor_ln165_9_z;
      reg ctrlOr_ln191_0_z;
      reg ctrlOr_ln711_z;
      reg ctrlOr_ln711_0_z;
      reg [31:0] mux_this__ln361_0_z;
      reg [63:0] mux_this__ln361_z;
      reg ctrlAnd_1_ln62_0_z;
      reg ctrlOr_ln59_0_z;
      reg ctrlAnd_0_ln62_0_z;
      reg if_ln193_z;
      reg if_ln191_z;
      reg [15:0] add_ln200_z;
      reg lt_ln766_z;
      reg lt_ln706_z;
      reg lt_ln711_z;
      reg lt_ln316_z;
      reg lt_ln290_z;
      reg [15:0] mult_ln300_z;
      reg lt_ln328_z;
      reg lt_ln775_z;
      reg [5:0] mux_add_ln799_Z_1_v_0;
      reg lt_ln799_z;
      reg if_ln296_z;
      reg if_ln294_z;
      reg lt_ln111_z;
      reg lt_ln111_0_z;
      reg lt_ln86_z;
      reg lt_ln86_0_z;
      reg lt_ln67_z;
      reg lt_ln67_0_z;
      reg if_ln186_z;
      reg if_ln184_z;
      reg [1:0] mux_add_ln356_Z_1_mux_0_v;
      reg [1:0] mux_add_ln356_Z_1_v_1;
      reg lt_ln356_z;
      reg [31:0] mux_memread_pow2_ln359_Z_0_mux_0_v;
      reg [31:0] mux_memread_pow2_ln359_Z_v;
      reg [8:0] mux_add_ln365_Z_0_mux_0_v;
      reg [8:0] mux_add_ln365_Z_v;
      reg lt_ln792_z;
      reg [9:0] mult_ln195_z;
      reg [30:0] mux_add_ln745_Z_1_v_0;
      reg if_ln284_z;
      reg if_ln282_z;
      reg [31:0] lsh_ln348_z;
      reg lt_ln786_z;
      reg [5:0] xor_ln165_z;
      reg ctrlAnd_1_ln706_z;
      reg ctrlAnd_0_ln706_z;
      reg memwrite_rbm_visible_unit_ln365_268_mux_0_sel;
      reg [15:0] mux_max_ln310_z;
      reg [63:0] mux_rem_ln58_z;
      reg [63:0] add_ln271_z;
      reg ctrlOr_ln62_0_z;
      reg and_1_ln193_z;
      reg or_and_0_ln193_Z_0_z;
      reg ctrlAnd_1_ln777_z;
      reg ctrlAnd_0_ln777_z;
      reg mux_lt_ln799_Z_0_v;
      reg and_1_ln803_z;
      reg ctrlAnd_0_ln801_z;
      reg and_0_ln803_z;
      reg and_1_ln296_z;
      reg or_and_0_ln296_Z_0_z;
      reg and_1_ln186_z;
      reg or_and_0_ln186_Z_0_z;
      reg mux_lt_ln356_Z_0_v;
      reg mux_lt_ln356_Z_0_v_0;
      reg [9:0] mux_mult_ln195_Z_v;
      reg and_1_ln284_z;
      reg or_and_0_ln284_Z_0_z;
      reg [2:0] case_mux_de_ln817_z;
      reg [6:0] mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_v;
      reg [6:0] mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_0_mux_0_v;
      reg [31:0] mux_dp_ln345_z;
      reg ctrlOr_ln706_0_z;
      reg [14:0] sub_ln196_0_z;
      reg lt_ln786_0_z;
      reg add_ln281_sel;
      reg ctrlAnd_1_ln193_z;
      reg ctrlAnd_0_ln193_z;
      reg memwrite_rbm_visible_unit_ln365_214_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_240_sel;
      reg ctrlOr_ln772_z;
      reg ctrlAnd_1_ln803_z;
      reg ctrlOr_ln799_z;
      reg ctrlAnd_0_ln803_z;
      reg ctrlAnd_1_ln296_z;
      reg ctrlAnd_0_ln296_z;
      reg ctrlAnd_1_ln186_z;
      reg ctrlAnd_0_ln186_z;
      reg ctrlAnd_1_ln284_z;
      reg ctrlAnd_0_ln284_z;
      reg [7:0] mux_de_ln817_z;
      reg [159:0] memwrite_pow2_ln351_z;
      reg ctrlAnd_1_ln708_z;
      reg ctrlAnd_0_ln708_z;
      reg [500:0] memwrite_rbm_visible_unit_ln365_z;
      reg ctrlAnd_1_ln59_z;
      reg ctrlAnd_1_ln62_z;
      reg ctrlAnd_0_ln62_z;
      reg ctrlAnd_1_ln766_z;
      reg ctrlAnd_0_ln766_z;
      reg ctrlAnd_1_ln792_z;
      reg ctrlAnd_0_ln792_z;
      reg memwrite_rbm_visible_unit_ln365_43_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_45_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_47_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_42_sel;
      reg mux_v_ln282_sel;
      reg ctrlOr_ln706_z;
      reg ctrlOr_ln59_z;
      reg ctrlOr_ln62_z;
      reg ctrlOr_ln766_0_z;
      reg memwrite_rbm_visible_unit_ln365_121_mux_0_sel;
      reg memwrite_rbm_visible_unit_ln365_140_sel;
      reg mux_rem_ln58_55_mux_0_sel;
      reg ctrlOr_ln792_0_z;
      reg mux_rem_ln58_14_mux_0_sel;
      reg mux_rem_ln58_15_mux_0_sel;
      reg ctrlAnd_1_ln768_z;
      reg ctrlAnd_0_ln768_z;
      reg ctrlAnd_1_ln794_z;
      reg ctrlAnd_0_ln794_z;
      reg ctrlOr_ln766_z;
      reg ctrlOr_ln792_z;
      reg memwrite_rbm_visible_unit_ln369_sel;
      reg mux_user_ln745_mux_0_sel;
      reg ctrlOr_ln745_z;
      reg ctrlAnd_1_ln745_z;
      reg ctrlAnd_0_ln745_z;
      reg ctrlOr_ln733_z;
      reg ctrlOr_ln750_z;
      reg mux_current_loop_ln733_mux_0_sel;
      reg read_rbm_num_visible_ln687_sel;

  always @(*) begin : rbm_0_cmos32soi_rbm_train_rbm_combinational
      state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'h0;
      ACTIVATE_HIDDEN_TRAIN_V_for_exit_1_or_0 = 
      state_rbm_0_cmos32soi_rbm_train_rbm[91] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[65] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[92];
      ACTIVATE_VISIBLE_TRAIN_ENERGY_UPDATE_for_begin_or_0 = 
      state_rbm_0_cmos32soi_rbm_train_rbm[23] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[26];
      RAND_LOOP1_for_begin_0_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[34] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[31];
      RAND_LOOP1_for_begin_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[69] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[66];
      RAND_LOOP2_for_begin_0_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[40] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[35];
      RAND_LOOP2_for_begin_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[70] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[75];
      ctrlAnd_0_ln198_z = memwrite_rbm_visible_unit_ln365_q[181] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[91];
      add_ln300_0_z = memwrite_rbm_visible_unit_ln365_q[78:63] + {
      memwrite_rbm_visible_unit_ln365_q[109:104], 
      memwrite_rbm_visible_unit_ln365_q[96]};
      mul_ln74_z = {add_ln271_q[11:0], memread_rbm_mt_ln116_0_2_q, 
      mux_rem_ln58_q[45:44]} * 32'h6c078965;
      mul_ln74_0_z = {add_ln271_q[11:0], memread_rbm_mt_ln116_0_2_q, add_ln271_q
      [13:12]} * 32'h6c078965;
      add_ln281_z = add_ln281_q + memwrite_rbm_visible_unit_ln365_q[41:10];
      add_ln708_z = {1'b0, num_visible} + 17'h1;
      add_ln713_z = {1'b0, num_hidden} + 17'h1;
      add_ln271_11_sel = state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      add_ln271_11_sel_0 = state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43];
      mt_bridge1_rtl_a_sel = state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36];
      add_ln271_22_sel = state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      add_ln271_23_sel = state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      add_ln271_56_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      add_ln271_58_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      add_ln271_63_sel = state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      eq_ln62_z = mti_signal == 32'h271;
      eq_ln62_0_z = mti_signal == 32'h271;
      ctrlAnd_0_ln111_z = mux_rem_ln58_q[46] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[81];
      ctrlAnd_0_ln111_0_z = add_ln271_q[23] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[46];
      ctrlOr_ln184_0_z = state_rbm_0_cmos32soi_rbm_train_rbm[89] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[8];
      ctrlAnd_0_ln290_z = memwrite_rbm_visible_unit_ln365_q[79] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[22];
      ctrlOr_ln294_0_z = state_rbm_0_cmos32soi_rbm_train_rbm[59] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[21];
      ctrlAnd_0_ln316_z = mux_rem_ln58_q[13] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[26];
      ctrlAnd_0_ln328_z = memwrite_rbm_visible_unit_ln365_q[9] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[29];
      ctrlAnd_0_ln356_z = lt_ln356_q & state_rbm_0_cmos32soi_rbm_train_rbm[55];
      ctrlAnd_0_ln51_z = lt_ln51_q & state_rbm_0_cmos32soi_rbm_train_rbm[54];
      ctrlAnd_0_ln67_z = mux_rem_ln58_q[43] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[69];
      ctrlAnd_0_ln67_0_z = mux_this_ln361_0_2_q[10] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[34];
      ctrlAnd_0_ln713_z = memwrite_rbm_visible_unit_ln365_q[295] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[94];
      ctrlAnd_0_ln735_z = memwrite_rbm_visible_unit_ln365_q[267] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[3];
      ctrlAnd_0_ln775_z = memwrite_rbm_visible_unit_ln365_q[263] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[64];
      ctrlAnd_0_ln799_z = memwrite_rbm_visible_unit_ln365_q[147] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[19];
      ctrlAnd_0_ln86_z = mux_rem_ln58_q[54] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[75];
      ctrlAnd_0_ln86_0_z = add_ln271_q[63] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[40];
      ctrlAnd_1_ln772_z = memwrite_rbm_visible_unit_ln365_q[266] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[61];
      if_ln768_1_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[62] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[61] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[64] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[9];
      if_ln794_1_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[13] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[19] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[11];
      memread_rbm_edges_ln300_en = memread_rbm_hidden_unit_ln298_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      edges_bridge2_rtl_a_sel = state_rbm_0_cmos32soi_rbm_train_rbm[91] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      ifBot_ln803_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[13] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[19] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[16];
      ge_ln59_z = $signed(mti_signal[31:4]) > $signed(7'h26);
      ge_ln59_0_z = $signed(mti_signal[31:4]) > $signed(7'h26);
      if_ln777_1_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[62] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[64];
      if_ln801_1_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[13] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[19];
      ifBot_ln59_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[91] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[65] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[92] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[86];
      if_ln59_0_0_or_0 = state_rbm_0_cmos32soi_rbm_train_rbm[30] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[55];
      memread_rbm_mt_ln116_0_2_sel = state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43];
      mux_pow2_ln328_z = memwrite_pow2_ln351_q;
      memwrite_rbm_mt_ln103_0_en = memread_rbm_mt_ln91_0_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      memwrite_rbm_mt_ln103_en = memread_rbm_mt_ln91_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[74];
      memwrite_rbm_mt_ln127_0_en = memread_rbm_mt_ln116_0_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[45];
      memwrite_rbm_mt_ln127_en = memread_rbm_mt_ln116_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[80];
      memwrite_rbm_mt_ln144_0_en = memread_rbm_mt_ln134_0_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[50];
      memwrite_rbm_mt_ln144_en = memread_rbm_mt_ln134_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[85];
      mt_bridge1_rtl_a_sel_0 = state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37];
      mt_bridge1_rtl_a_sel_1 = state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43];
      mt_bridge1_rtl_a_sel_3 = state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47];
      mt_bridge1_rtl_a_sel_4 = state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48];
      mti_signal_hold = ~(state_rbm_0_cmos32soi_rbm_train_rbm[88] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51]);
      mux_mti_ln59_0_1_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      mux_mti_ln59_0_8_sel = state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      mux_visible_unit_ln745_z = memwrite_rbm_visible_unit_ln369_q;
      mux_rem_ln58_11_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24];
      mux_rem_ln58_34_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67];
      mux_rem_ln58_46_sel = state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77];
      mux_rem_ln58_47_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74];
      mux_rem_ln58_49_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74];
      mux_rem_ln58_54_sel = state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74];
      mux_rem_ln58_63_sel = state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      mux_this_ln361_0_2_1_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mti_ln59_0_z = 32'h0;
      else 
        mux_mti_ln59_0_z = mti_signal;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[86]) 
        mux_mti_ln59_z = 32'h0;
      else 
        mux_mti_ln59_z = mti_signal;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[88]) 
        hidden_unit_bridge1_rtl_d = memwrite_rbm_visible_unit_ln365_q[265];
      else 
        hidden_unit_bridge1_rtl_d = 1'b1;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[88]) 
        hidden_unit_bridge1_rtl_a = mux_rem_ln58_q[20:14];
      else 
        hidden_unit_bridge1_rtl_a = read_rbm_num_hidden_ln688_q[6:0];
      add_ln176_1_z = memwrite_rbm_visible_unit_ln365_q[95:80] + {{8{
      edges_bridge2_rtl_Q[7]}}, edges_bridge2_rtl_Q};
      add_ln176_z = edges_bridge2_rtl_Q + 8'h1;
      sub_ln196_z = edges_bridge2_rtl_Q - 8'h1;
      add_ln176_0_z = memwrite_rbm_visible_unit_ln365_q[171:156] + {{8{
      edges_bridge2_rtl_Q[7]}}, edges_bridge2_rtl_Q};
      add_ln75_z = mul_ln74_z + {mux_mti_ln59_0_q[8], add_ln271_q[21], 
      mux_mti_ln59_0_q[7:0]};
      add_ln75_0_z = mul_ln74_0_z + {mux_mti_ln59_0_q[8], mux_this_ln361_0_2_q[0], 
      mux_mti_ln59_0_q[7:0]};
      add_ln339_z = visibleEnergies_bridge3_rtl_Q[5:1] + 5'h1;
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[43]: 
          memread_rbm_mt_ln116_0_Q_0_tag_d = mt_bridge1_rtl_Q[0];
        state_rbm_0_cmos32soi_rbm_train_rbm[44]: 
          memread_rbm_mt_ln116_0_Q_0_tag_d = memread_rbm_mt_ln116_0_Q_0_tag_0;
        default: memread_rbm_mt_ln116_0_Q_0_tag_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[78]: memread_rbm_mt_ln116_Q_0_tag_d = 
          mt_bridge1_rtl_Q[0];
        state_rbm_0_cmos32soi_rbm_train_rbm[79]: memread_rbm_mt_ln116_Q_0_tag_d = 
          memread_rbm_mt_ln116_Q_0_tag_0;
        default: memread_rbm_mt_ln116_Q_0_tag_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[48]: 
          memread_rbm_mt_ln134_0_Q_0_tag_d = mt_bridge1_rtl_Q[0];
        state_rbm_0_cmos32soi_rbm_train_rbm[49]: 
          memread_rbm_mt_ln134_0_Q_0_tag_d = memread_rbm_mt_ln134_0_Q_0_tag_0;
        default: memread_rbm_mt_ln134_0_Q_0_tag_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[83]: memread_rbm_mt_ln134_Q_0_tag_d = 
          mt_bridge1_rtl_Q[0];
        state_rbm_0_cmos32soi_rbm_train_rbm[84]: memread_rbm_mt_ln134_Q_0_tag_d = 
          memread_rbm_mt_ln134_Q_0_tag_0;
        default: memread_rbm_mt_ln134_Q_0_tag_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[37]: memread_rbm_mt_ln91_0_Q_0_tag_d = 
          mt_bridge1_rtl_Q[0];
        state_rbm_0_cmos32soi_rbm_train_rbm[38]: memread_rbm_mt_ln91_0_Q_0_tag_d = 
          memread_rbm_mt_ln91_0_Q_0_tag_0;
        default: memread_rbm_mt_ln91_0_Q_0_tag_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[72]: memread_rbm_mt_ln91_Q_0_tag_d = 
          mt_bridge1_rtl_Q[0];
        state_rbm_0_cmos32soi_rbm_train_rbm[73]: memread_rbm_mt_ln91_Q_0_tag_d = 
          memread_rbm_mt_ln91_Q_0_tag_0;
        default: memread_rbm_mt_ln91_Q_0_tag_d = 1'bX;
      endcase
      xor_ln101_z = mt_bridge1_rtl_Q[30:0] ^ {add_ln271_q[11:0], 
      memread_rbm_mt_ln116_0_2_q, add_ln271_q[55]};
      xor_ln101_0_z = mt_bridge1_rtl_Q[30:0] ^ {add_ln271_q[11:0], 
      memread_rbm_mt_ln116_0_2_q, add_ln271_q[55]};
      xor_ln125_z = mt_bridge1_rtl_Q[30:0] ^ {add_ln271_q[11:0], 
      memread_rbm_mt_ln116_0_2_q, add_ln271_q[55]};
      xor_ln125_0_z = mt_bridge1_rtl_Q[30:0] ^ {add_ln271_q[11:0], 
      memread_rbm_mt_ln116_0_2_q, add_ln271_q[55]};
      xor_ln142_z = mt_bridge1_rtl_Q[30:0] ^ {add_ln271_q[11:0], 
      memread_rbm_mt_ln116_0_2_q, add_ln271_q[55]};
      xor_ln142_0_z = mt_bridge1_rtl_Q[30:0] ^ {add_ln271_q[11:0], 
      memread_rbm_mt_ln116_0_2_q, add_ln271_q[55]};
      xor_ln157_z = {mt_bridge1_rtl_Q[20:19], mt_bridge1_rtl_Q[16:14], 
      mt_bridge1_rtl_Q[12:11], mt_bridge1_rtl_Q[7], mt_bridge1_rtl_Q[5]} ^ {
      mt_bridge1_rtl_Q[31:30], mt_bridge1_rtl_Q[27:25], mt_bridge1_rtl_Q[23:22], 
      mt_bridge1_rtl_Q[18], mt_bridge1_rtl_Q[16]};
      xor_ln157_0_z = {mt_bridge1_rtl_Q[20:14], mt_bridge1_rtl_Q[12:7], 
      mt_bridge1_rtl_Q[5:2], mt_bridge1_rtl_Q[0]} ^ {mt_bridge1_rtl_Q[31:25], 
      mt_bridge1_rtl_Q[23:18], mt_bridge1_rtl_Q[16:13], mt_bridge1_rtl_Q[11]};
      xor_ln165_3_z = ^{mt_bridge1_rtl_Q[25], mt_bridge1_rtl_Q[21], 
      mt_bridge1_rtl_Q[3]};
      xor_ln73_z = mt_bridge1_rtl_Q[1:0] ^ mt_bridge1_rtl_Q[31:30];
      xor_ln73_0_z = mt_bridge1_rtl_Q[1:0] ^ mt_bridge1_rtl_Q[31:30];
      ctrlAnd_1_ln111_0_z = !add_ln271_q[23] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[46];
      ctrlAnd_1_ln86_0_z = !add_ln271_q[63] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[40];
      ctrlOr_ln111_z = ctrlAnd_0_ln111_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[76];
      ctrlOr_ln111_0_z = ctrlAnd_0_ln111_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[41];
      ctrlOr_ln290_z = ctrlAnd_0_ln290_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[20];
      ctrlOr_ln316_z = ctrlAnd_0_ln316_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[23];
      ctrlOr_ln328_z = ctrlAnd_0_ln328_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[27];
      ctrlOr_ln356_z = ctrlAnd_0_ln356_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[30];
      ctrlOr_ln51_z = ctrlAnd_0_ln51_z | state_rbm_0_cmos32soi_rbm_train_rbm[53];
      ctrlOr_ln67_z = ctrlAnd_0_ln67_z | state_rbm_0_cmos32soi_rbm_train_rbm[66];
      ctrlOr_ln67_0_z = ctrlAnd_0_ln67_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[31];
      ctrlAnd_1_ln684_z = init_done & state_rbm_0_cmos32soi_rbm_train_rbm[0];
      ctrlAnd_0_ln684_z = !init_done & state_rbm_0_cmos32soi_rbm_train_rbm[0];
      ctrlOr_ln740_z = state_rbm_0_cmos32soi_rbm_train_rbm[4] | 
      ctrlAnd_0_ln735_z;
      ctrlAnd_1_ln750_z = train_input_done & 
      state_rbm_0_cmos32soi_rbm_train_rbm[6];
      ctrlAnd_0_ln750_z = !train_input_done & 
      state_rbm_0_cmos32soi_rbm_train_rbm[6];
      ctrlAnd_1_ln753_z = !train_input_done & 
      state_rbm_0_cmos32soi_rbm_train_rbm[7];
      ctrlAnd_0_ln753_z = train_input_done & 
      state_rbm_0_cmos32soi_rbm_train_rbm[7];
      ctrlAnd_0_ln772_z = !memwrite_rbm_visible_unit_ln365_q[266] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[61];
      ctrlOr_ln775_0_z = ctrlAnd_0_ln775_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[62];
      ctrlOr_ln799_0_z = ctrlAnd_0_ln799_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[13];
      ctrlOr_ln86_z = ctrlAnd_0_ln86_z | state_rbm_0_cmos32soi_rbm_train_rbm[70];
      ctrlOr_ln86_0_z = ctrlAnd_0_ln86_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[35];
      ctrlAnd_1_ln111_z = !mux_rem_ln58_q[46] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[81];
      ctrlAnd_1_ln198_z = !memwrite_rbm_visible_unit_ln365_q[181] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[91];
      ctrlAnd_1_ln290_z = !memwrite_rbm_visible_unit_ln365_q[79] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[22];
      ctrlAnd_1_ln316_z = !mux_rem_ln58_q[13] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[26];
      ctrlAnd_1_ln328_z = !memwrite_rbm_visible_unit_ln365_q[9] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[29];
      ctrlAnd_1_ln356_z = !lt_ln356_q & state_rbm_0_cmos32soi_rbm_train_rbm[55];
      ctrlAnd_1_ln51_z = !lt_ln51_q & state_rbm_0_cmos32soi_rbm_train_rbm[54];
      ctrlAnd_1_ln67_z = !mux_rem_ln58_q[43] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[69];
      ctrlAnd_1_ln67_0_z = !mux_this_ln361_0_2_q[10] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[34];
      ctrlAnd_1_ln713_z = !memwrite_rbm_visible_unit_ln365_q[295] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[94];
      ctrlAnd_1_ln735_z = !memwrite_rbm_visible_unit_ln365_q[267] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[3];
      ctrlAnd_1_ln775_z = !memwrite_rbm_visible_unit_ln365_q[263] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[64];
      ctrlAnd_1_ln799_z = !memwrite_rbm_visible_unit_ln365_q[147] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[19];
      ctrlAnd_1_ln86_z = !mux_rem_ln58_q[54] & 
      state_rbm_0_cmos32soi_rbm_train_rbm[75];
      ne_ln772_z = data_bridge1_rtl_Q == 8'h2;
      ne_ln803_z = data_bridge1_rtl_Q == 8'h2;
      unary_or_ln781_z = |data_bridge1_rtl_Q;
      eq_ln198_z = data_bridge1_rtl_Q == 8'h1;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[94]) 
        edges_bridge0_rtl_d = 8'h0;
      else 
        edges_bridge0_rtl_d = memwrite_rbm_visible_unit_ln365_q[155:148];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[10]) 
        mux_visible_unit_ln282_z = memwrite_rbm_visible_unit_ln369_q;
      else 
        mux_visible_unit_ln282_z = memwrite_rbm_visible_unit_ln365_q;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[10]) 
        mux_pow2_ln282_z = 160'h0;
      else 
        mux_pow2_ln282_z = memwrite_pow2_ln351_q;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[20]) 
        mux_max_ln290_z = 16'hfc18;
      else 
        mux_max_ln290_z = memwrite_rbm_visible_unit_ln365_q[60:45];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[21]) 
        mux_sum_ln294_z = 16'h0;
      else 
        mux_sum_ln294_z = memwrite_rbm_visible_unit_ln365_q[95:80];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[27]) 
        mux_sumOfpow2_ln328_z = 64'h0;
      else 
        mux_sumOfpow2_ln328_z = add_ln281_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[30]) 
        mux_visible_unit_ln356_z = memwrite_rbm_visible_unit_ln369_q;
      else 
        mux_visible_unit_ln356_z = memwrite_rbm_visible_unit_ln365_q;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[53]) 
        mux_num_adj_ln51_z = memread_pow2_ln359_q;
      else 
        mux_num_adj_ln51_z = {memread_rbm_mt_ln116_0_2_q, mux_this_ln361_0_2_q[
        10:1], mux_mti_ln59_0_q[8], mux_this_ln361_0_2_q[0], mux_mti_ln59_0_q[7:
        6]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[53]) 
        mux_quotient_ln51_z = 64'h0;
      else 
        mux_quotient_ln51_z = add_ln271_q;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[53]) 
        mux_rem_ln51_z = 64'h0;
      else 
        mux_rem_ln51_z = mux_rem_ln58_q;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[53]) 
        mux_xor_ln165_0_Z_v = {mux_rem_ln58_q[54:52], mux_rem_ln58_q[38], 
        mux_rem_ln58_q[51:46], mux_rem_ln58_q[37], mux_rem_ln58_q[33], 
        mux_rem_ln58_q[36], mux_rem_ln58_q[45:44], mux_rem_ln58_q[32:31], 
        mux_rem_ln58_q[35], mux_rem_ln58_q[39], mux_rem_ln58_q[62:61], 
        mux_rem_ln58_q[40], mux_rem_ln58_q[55], mux_rem_ln58_q[41], 
        mux_rem_ln58_q[60], mux_rem_ln58_q[56], mux_rem_ln58_q[59:58], 
        mux_rem_ln58_q[34], mux_rem_ln58_q[57], mux_rem_ln58_q[42], 
        mux_rem_ln58_q[43]};
      else 
        mux_xor_ln165_0_Z_v = {memread_pow2_ln359_q[23:21], memread_pow2_ln359_q
        [7], memread_pow2_ln359_q[20:15], memread_pow2_ln359_q[6], 
        memread_pow2_ln359_q[2], memread_pow2_ln359_q[5], memread_pow2_ln359_q[
        14:13], memread_pow2_ln359_q[1:0], memread_pow2_ln359_q[4], 
        memread_pow2_ln359_q[8], memread_pow2_ln359_q[31:30], 
        memread_pow2_ln359_q[9], memread_pow2_ln359_q[24], memread_pow2_ln359_q[
        10], memread_pow2_ln359_q[29], memread_pow2_ln359_q[25], 
        memread_pow2_ln359_q[28:27], memread_pow2_ln359_q[3], 
        memread_pow2_ln359_q[26], memread_pow2_ln359_q[11], memread_pow2_ln359_q
        [12]};
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[56]: 
          memread_rbm_hidden_unit_ln298_Q_0_tag_d = hidden_unit_bridge3_rtl_Q;
        state_rbm_0_cmos32soi_rbm_train_rbm[57]: 
          memread_rbm_hidden_unit_ln298_Q_0_tag_d = 
          memread_rbm_hidden_unit_ln298_Q_0_tag_0;
        default: memread_rbm_hidden_unit_ln298_Q_0_tag_d = 1'bX;
      endcase
      ternaryMux_ln781_0_z = memwrite_rbm_visible_unit_ln365_q[240] & 
      hidden_unit_bridge3_rtl_Q;
      ternaryMux_ln808_0_z = hidden_unit_bridge3_rtl_Q & 
      memwrite_rbm_visible_unit_ln365_q[138];
      mt_bridge0_rtl_a_sel = if_ln59_0_0_or_0 | 
      ACTIVATE_HIDDEN_TRAIN_V_for_exit_1_or_0;
      memwrite_rbm_mt_ln129_0_en = !memread_rbm_mt_ln116_0_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[45];
      memwrite_rbm_mt_ln129_en = !memread_rbm_mt_ln116_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[80];
      memwrite_rbm_mt_ln146_0_en = !memread_rbm_mt_ln134_0_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[50];
      memwrite_rbm_mt_ln146_en = !memread_rbm_mt_ln134_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[85];
      memwrite_rbm_mt_ln105_0_en = !memread_rbm_mt_ln91_0_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      memwrite_rbm_mt_ln105_en = !memread_rbm_mt_ln91_Q_0_tag_0 & 
      state_rbm_0_cmos32soi_rbm_train_rbm[74];
      mt_bridge0_rtl_d_sel = memwrite_rbm_mt_ln144_en | 
      memwrite_rbm_mt_ln144_0_en | memwrite_rbm_mt_ln127_en | 
      memwrite_rbm_mt_ln127_0_en | memwrite_rbm_mt_ln103_en | 
      memwrite_rbm_mt_ln103_0_en;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[65]) 
        mux_v_ln191_z = 9'h0;
      else 
        mux_v_ln191_z = {memwrite_rbm_visible_unit_ln365_q[180:173], !
        memwrite_rbm_visible_unit_ln365_q[172]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[9]) 
        mux_v_ln766_z = 9'h0;
      else 
        mux_v_ln766_z = {memwrite_rbm_visible_unit_ln365_q[222:215], !
        memwrite_rbm_visible_unit_ln365_q[214]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[1]) 
        mux_v_ln706_z = 9'h0;
      else 
        mux_v_ln706_z = {memwrite_rbm_visible_unit_ln365_q[276:269], !
        memwrite_rbm_visible_unit_ln365_q[268]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[93]) 
        mux_h_ln711_z = 7'h0;
      else 
        mux_h_ln711_z = {memwrite_rbm_visible_unit_ln365_q[301:296], !
        memwrite_rbm_visible_unit_ln365_q[294]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[23]) 
        mux_j_ln316_z = 3'h0;
      else 
        mux_j_ln316_z = {mux_rem_ln58_q[12:11], !
        memwrite_rbm_visible_unit_ln365_q[42]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[20]) 
        mux_j_ln290_z = 3'h0;
      else 
        mux_j_ln290_z = {memwrite_rbm_visible_unit_ln365_q[62:61], !
        memwrite_rbm_visible_unit_ln365_q[42]};
      sub_ln196_0_0_z = visibleEnergies_bridge3_rtl_Q - {mux_rem_ln58_q[10:0], 
      add_ln271_q[13:12], sub_ln196_0_1_q, !memwrite_rbm_visible_unit_ln365_q[46], 
      memwrite_rbm_visible_unit_ln365_q[45]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[27]) 
        mux_j_ln328_z = 3'h0;
      else 
        mux_j_ln328_z = {memwrite_rbm_visible_unit_ln365_q[8:7], !
        memwrite_rbm_visible_unit_ln365_q[6]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[62]) 
        mux_h_ln775_z = 7'h0;
      else 
        mux_h_ln775_z = {memwrite_rbm_visible_unit_ln365_q[246:241], !
        memwrite_rbm_visible_unit_ln365_q[96]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[13]) 
        mux_h_ln799_z = 7'h0;
      else 
        mux_h_ln799_z = {memwrite_rbm_visible_unit_ln365_q[146:141], !
        memwrite_rbm_visible_unit_ln365_q[96]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[21]) 
        mux_h_ln294_z = 7'h0;
      else 
        mux_h_ln294_z = {memwrite_rbm_visible_unit_ln365_q[102:97], !
        memwrite_rbm_visible_unit_ln365_q[96]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[76]) 
        mux_kk_ln111_z = 10'he3;
      else 
        mux_kk_ln111_z = {add_ln271_q[22], mux_this_ln361_0_2_q[0], add_ln271_q[
        20:14], !mux_mti_ln59_0_q[0]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[41]) 
        mux_kk_ln111_0_z = 10'he3;
      else 
        mux_kk_ln111_0_z = {add_ln271_q[22:14], !mux_mti_ln59_0_q[0]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[70]) 
        mux_kk_ln86_z = 8'h0;
      else 
        mux_kk_ln86_z = {mux_rem_ln58_q[53:47], !mux_mti_ln59_0_q[0]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[35]) 
        mux_kk_ln86_0_z = 8'h0;
      else 
        mux_kk_ln86_0_z = {add_ln271_q[62:56], !mux_mti_ln59_0_q[0]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[66]) 
        mux_mti_ln67_z = 10'h1;
      else 
        mux_mti_ln67_z = {mux_rem_ln58_q[42:34], !mux_mti_ln59_0_q[0]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[31]) 
        mux_mti_ln67_0_z = 10'h1;
      else 
        mux_mti_ln67_0_z = {mux_this_ln361_0_2_q[9:1], !mux_mti_ln59_0_q[0]};
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[88]: mti_signal_d = {
          memwrite_rbm_visible_unit_ln365_q[213:183], !mux_mti_ln59_0_q[0]};
        state_rbm_0_cmos32soi_rbm_train_rbm[51]: mti_signal_d = {mux_rem_ln58_q[
          30:0], !mux_mti_ln59_0_q[0]};
        mti_signal_hold: mti_signal_d = mti_signal;
        default: mti_signal_d = 32'hX;
      endcase
      if (state_rbm_0_cmos32soi_rbm_train_rbm[2]) 
        mux_current_loop_ln733_z = 32'h0;
      else 
        mux_current_loop_ln733_z = {add_ln836_1_q, !mux_current_loop_ln733_q};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[8]) 
        mux_h_ln184_z = 7'h0;
      else 
        mux_h_ln184_z = {mux_rem_ln58_q[26:21], !mux_rem_ln58_q[14]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[53]) 
        mux_i_ln51_z = 7'h0;
      else 
        mux_i_ln51_z = {mux_mti_ln59_0_q[5:0], !sub_ln196_0_1_q};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[30]) 
        mux_j_ln356_z = 3'h0;
      else 
        mux_j_ln356_z = {add_ln356_1_q, !mux_j_ln356_q};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_visible_unit_ln745_Z_192_v_0 = memwrite_rbm_visible_unit_ln369_q
        [255:192];
      else 
        mux_mux_visible_unit_ln745_Z_192_v_0 = mux_visible_unit_ln745_z[255:192];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_visible_unit_ln745_Z_256_v_0 = memwrite_rbm_visible_unit_ln369_q
        [319:256];
      else 
        mux_mux_visible_unit_ln745_Z_256_v_0 = mux_visible_unit_ln745_z[319:256];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_visible_unit_ln745_Z_320_v_0 = memwrite_rbm_visible_unit_ln369_q
        [383:320];
      else 
        mux_mux_visible_unit_ln745_Z_320_v_0 = mux_visible_unit_ln745_z[383:320];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_visible_unit_ln745_Z_384_v_0 = memwrite_rbm_visible_unit_ln369_q
        [447:384];
      else 
        mux_mux_visible_unit_ln745_Z_384_v_0 = mux_visible_unit_ln745_z[447:384];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_visible_unit_ln745_Z_448_v_0 = memwrite_rbm_visible_unit_ln369_q
        [500:448];
      else 
        mux_mux_visible_unit_ln745_Z_448_v_0 = mux_visible_unit_ln745_z[500:448];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_visible_unit_ln745_Z_64_v_0 = memwrite_rbm_visible_unit_ln369_q[
        127:64];
      else 
        mux_mux_visible_unit_ln745_Z_64_v_0 = mux_visible_unit_ln745_z[127:64];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_visible_unit_ln745_Z_v = memwrite_rbm_visible_unit_ln369_q[63:0];
      else 
        mux_mux_visible_unit_ln745_Z_v = mux_visible_unit_ln745_z[63:0];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[2]) 
        mux_visible_unit_ln733_z = 501'h0;
      else 
        mux_visible_unit_ln733_z = mux_visible_unit_ln745_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_visible_unit_ln745_Z_128_v_0 = memwrite_rbm_visible_unit_ln369_q
        [191:128];
      else 
        mux_mux_visible_unit_ln745_Z_128_v_0 = mux_visible_unit_ln745_z[191:128];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[11]) 
        mux_v_ln792_z = 9'h0;
      else 
        mux_v_ln792_z = {memwrite_rbm_visible_unit_ln365_q[121], mux_rem_ln58_q[
        62:56], !mux_rem_ln58_q[55]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[5]) 
        mux_user_ln745_z = 32'h0;
      else 
        mux_user_ln745_z = {add_ln745_1_q, !mux_user_ln745_q};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[10]) 
        mux_v_ln282_z = 9'h0;
      else 
        mux_v_ln282_z = {add_ln282_1_q, !mux_v_ln282_q[0]};
      unary_nor_ln817_z = ~memread_rbm_neg_ln813_rtl_Q;
      add_ln153_0_z = mux_mti_ln59_0_z + 32'h1;
      add_ln153_z = mux_mti_ln59_z + 32'h1;
      if (memread_rbm_hidden_unit_ln298_Q_0_tag_0) 
        mux_sum_ln302_z = add_ln176_1_z;
      else 
        mux_sum_ln302_z = memwrite_rbm_visible_unit_ln365_q[95:80];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[92]) 
        mux_sum_ln198_z = add_ln176_0_z;
      else 
        mux_sum_ln198_z = memwrite_rbm_visible_unit_ln365_q[171:156];
      case (1'b1)
        !visibleEnergies_bridge3_rtl_Q[0]: case_mux_tmp_ln333_z = 3'h1;
        !visibleEnergies_bridge3_rtl_Q[15]: case_mux_tmp_ln333_z = 3'h2;
        default: case_mux_tmp_ln333_z = 3'h4;
      endcase
      xor_ln103_z = ~{mt_bridge1_rtl_Q[31], xor_ln101_z[28:27], xor_ln101_z[24], 
      xor_ln101_z[19], xor_ln101_z[15], xor_ln101_z[13:12], xor_ln101_z[7:6], 
      xor_ln101_z[4:0]};
      xor_ln103_0_z = ~{mt_bridge1_rtl_Q[31], xor_ln101_0_z[28:27], 
      xor_ln101_0_z[24], xor_ln101_0_z[19], xor_ln101_0_z[15], xor_ln101_0_z[13:
      12], xor_ln101_0_z[7:6], xor_ln101_0_z[4:0]};
      xor_ln127_z = ~{mt_bridge1_rtl_Q[31], xor_ln125_z[28:27], xor_ln125_z[24], 
      xor_ln125_z[19], xor_ln125_z[15], xor_ln125_z[13:12], xor_ln125_z[7:6], 
      xor_ln125_z[4:0]};
      xor_ln127_0_z = ~{mt_bridge1_rtl_Q[31], xor_ln125_0_z[28:27], 
      xor_ln125_0_z[24], xor_ln125_0_z[19], xor_ln125_0_z[15], xor_ln125_0_z[13:
      12], xor_ln125_0_z[7:6], xor_ln125_0_z[4:0]};
      xor_ln144_z = ~{mt_bridge1_rtl_Q[31], xor_ln142_z[28:27], xor_ln142_z[24], 
      xor_ln142_z[19], xor_ln142_z[15], xor_ln142_z[13:12], xor_ln142_z[7:6], 
      xor_ln142_z[4:0]};
      xor_ln144_0_z = ~{mt_bridge1_rtl_Q[31], xor_ln142_0_z[28:27], 
      xor_ln142_0_z[24], xor_ln142_0_z[19], xor_ln142_0_z[15], xor_ln142_0_z[13:
      12], xor_ln142_0_z[7:6], xor_ln142_0_z[4:0]};
      xor_ln160_z = {mt_bridge1_rtl_Q[31], mt_bridge1_rtl_Q[28:26], xor_ln157_z[
      4:3]} ^ {mt_bridge1_rtl_Q[24], mt_bridge1_rtl_Q[21], xor_ln157_z[8:7], 
      xor_ln157_z[1:0]};
      xor_ln160_0_z = {mt_bridge1_rtl_Q[31], mt_bridge1_rtl_Q[28:26], 
      mt_bridge1_rtl_Q[24], mt_bridge1_rtl_Q[21], xor_ln157_0_z[16:15], 
      xor_ln157_0_z[11:10], xor_ln157_0_z[8:7], xor_ln157_0_z[5]} ^ {
      mt_bridge1_rtl_Q[24], mt_bridge1_rtl_Q[21], xor_ln157_0_z[17:16], 
      xor_ln157_0_z[14], xor_ln157_0_z[11:9], xor_ln157_0_z[5:4], xor_ln157_0_z[
      2:0]};
      xor_ln165_0_z = mt_bridge1_rtl_Q[22] ^ mt_bridge1_rtl_Q[0] ^ xor_ln157_0_z
      [15] ^ xor_ln157_0_z[2];
      xor_ln165_1_z = mt_bridge1_rtl_Q[23] ^ mt_bridge1_rtl_Q[1] ^ xor_ln157_0_z
      [16];
      xor_ln165_10_z = mt_bridge1_rtl_Q[28] ^ mt_bridge1_rtl_Q[10] ^ 
      xor_ln157_0_z[2];
      xor_ln165_13_z = mt_bridge1_rtl_Q[31] ^ mt_bridge1_rtl_Q[13] ^ 
      xor_ln157_0_z[13];
      xor_ln165_8_z = mt_bridge1_rtl_Q[30] ^ mt_bridge1_rtl_Q[26] ^ 
      mt_bridge1_rtl_Q[8] ^ xor_ln157_0_z[9];
      add_ln271_21_sel = ctrlAnd_1_ln111_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      visibleEnergies_bridge3_rtl_CE_en = ctrlOr_ln328_z | ctrlOr_ln316_z;
      if (ctrlAnd_0_ln735_z) 
        train_done_d = 1'b1;
      else 
        train_done_d = train_done;
      train_start_hold = ~(ctrlAnd_1_ln753_z | ctrlAnd_1_ln750_z);
      ctrlOr_ln753_z = ctrlAnd_0_ln753_z | ctrlAnd_1_ln750_z;
      add_ln365_sel = ctrlOr_ln86_0_z | ctrlOr_ln67_0_z | ctrlOr_ln111_0_z | 
      ctrlAnd_1_ln86_0_z | ctrlAnd_1_ln111_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[52] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      add_ln271_14_mux_0_sel = ctrlAnd_1_ln111_z | ctrlAnd_1_ln111_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      mt_bridge1_rtl_a_sel_2 = ctrlAnd_1_ln111_z | ctrlAnd_1_ln111_0_z;
      mux_mti_ln59_0_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[87] | 
      ctrlAnd_1_ln111_z | ctrlAnd_1_ln111_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      mux_this_ln361_0_2_0_sel = ctrlAnd_1_ln111_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      ctrlOr_ln198_z = ctrlAnd_1_ln198_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[92];
      sub_ln196_0_1_sel = ctrlOr_ln316_z | ctrlAnd_1_ln290_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24];
      ctrlOr_ln282_0_z = ctrlAnd_1_ln356_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[10];
      memwrite_rbm_visible_unit_ln365_103_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[90];
      memwrite_rbm_visible_unit_ln365_141_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14];
      memwrite_rbm_visible_unit_ln365_156_mux_0_sel = ctrlAnd_1_ln51_z | 
      ctrlAnd_0_ln198_z | state_rbm_0_cmos32soi_rbm_train_rbm[90];
      memwrite_rbm_visible_unit_ln365_183_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[87] | ctrlAnd_1_ln51_z;
      memwrite_rbm_visible_unit_ln365_241_mux_0_sel = ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[63];
      memwrite_rbm_visible_unit_ln365_4_mux_0_sel = ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      memwrite_rbm_visible_unit_ln365_6_mux_0_sel = ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[28];
      memwrite_rbm_visible_unit_ln365_80_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      memwrite_rbm_visible_unit_ln365_96_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[63] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      memwrite_rbm_visible_unit_ln365_97_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      memwrite_rbm_visible_unit_ln365_sel = ctrlAnd_1_ln51_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      mux_j_ln356_mux_0_sel = ctrlOr_ln86_0_z | ctrlOr_ln67_0_z | ctrlOr_ln51_z | 
      ctrlOr_ln111_0_z | ctrlAnd_1_ln86_0_z | ctrlAnd_1_ln51_z | 
      ctrlAnd_1_ln111_0_z | state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[52] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      ctrlAnd_1_ln711_z = !memwrite_rbm_visible_unit_ln365_q[302] & 
      ctrlAnd_1_ln713_z;
      edges_bridge0_rtl_CE_en = ctrlAnd_1_ln713_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18];
      ctrlAnd_0_ln711_z = memwrite_rbm_visible_unit_ln365_q[302] & 
      ctrlAnd_1_ln713_z;
      mux_rem_ln58_27_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[85] | 
      ctrlOr_ln86_z | ctrlOr_ln67_z | ctrlOr_ln111_z | ctrlAnd_1_ln86_z | 
      ctrlAnd_1_ln111_z | state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74];
      memwrite_rbm_visible_unit_ln369_z = mux_visible_unit_ln282_z;
      memwrite_rbm_visible_unit_ln369_z[read_rbm_num_visible_ln687_q[8:0]] = 
      1'b1;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[25]) 
        visibleEnergies_bridge1_rtl_d = memwrite_rbm_visible_unit_ln365_q[95:80];
      else 
        visibleEnergies_bridge1_rtl_d = mux_sum_ln294_z;
      gt_ln856_z = $signed(mux_sum_ln294_z) > $signed(
      memwrite_rbm_visible_unit_ln365_q[60:45]);
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_visible_unit_ln356_Z_0_mux_0_v = 
        memwrite_rbm_visible_unit_ln369_q[63:0];
      else 
        mux_mux_visible_unit_ln356_Z_0_mux_0_v = mux_visible_unit_ln356_z[63:0];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_visible_unit_ln356_Z_128_mux_0_v = 
        memwrite_rbm_visible_unit_ln369_q[191:128];
      else 
        mux_mux_visible_unit_ln356_Z_128_mux_0_v = mux_visible_unit_ln356_z[191:
        128];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_visible_unit_ln356_Z_128_v_1 = memwrite_rbm_visible_unit_ln369_q
        [191:128];
      else 
        mux_mux_visible_unit_ln356_Z_128_v_1 = mux_visible_unit_ln356_z[191:128];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_visible_unit_ln356_Z_192_mux_0_v = 
        memwrite_rbm_visible_unit_ln369_q[255:192];
      else 
        mux_mux_visible_unit_ln356_Z_192_mux_0_v = mux_visible_unit_ln356_z[255:
        192];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_visible_unit_ln356_Z_192_v_1 = memwrite_rbm_visible_unit_ln369_q
        [255:192];
      else 
        mux_mux_visible_unit_ln356_Z_192_v_1 = mux_visible_unit_ln356_z[255:192];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_visible_unit_ln356_Z_256_mux_0_v = 
        memwrite_rbm_visible_unit_ln369_q[319:256];
      else 
        mux_mux_visible_unit_ln356_Z_256_mux_0_v = mux_visible_unit_ln356_z[319:
        256];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_visible_unit_ln356_Z_256_v_1 = memwrite_rbm_visible_unit_ln369_q
        [319:256];
      else 
        mux_mux_visible_unit_ln356_Z_256_v_1 = mux_visible_unit_ln356_z[319:256];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_visible_unit_ln356_Z_320_mux_0_v = 
        memwrite_rbm_visible_unit_ln369_q[383:320];
      else 
        mux_mux_visible_unit_ln356_Z_320_mux_0_v = mux_visible_unit_ln356_z[383:
        320];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_visible_unit_ln356_Z_320_v_1 = memwrite_rbm_visible_unit_ln369_q
        [383:320];
      else 
        mux_mux_visible_unit_ln356_Z_320_v_1 = mux_visible_unit_ln356_z[383:320];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_visible_unit_ln356_Z_384_mux_0_v = 
        memwrite_rbm_visible_unit_ln369_q[447:384];
      else 
        mux_mux_visible_unit_ln356_Z_384_mux_0_v = mux_visible_unit_ln356_z[447:
        384];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_visible_unit_ln356_Z_384_v_1 = memwrite_rbm_visible_unit_ln369_q
        [447:384];
      else 
        mux_mux_visible_unit_ln356_Z_384_v_1 = mux_visible_unit_ln356_z[447:384];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_visible_unit_ln356_Z_448_mux_0_v = 
        memwrite_rbm_visible_unit_ln369_q[500:448];
      else 
        mux_mux_visible_unit_ln356_Z_448_mux_0_v = mux_visible_unit_ln356_z[500:
        448];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_visible_unit_ln356_Z_448_v_1 = memwrite_rbm_visible_unit_ln369_q
        [500:448];
      else 
        mux_mux_visible_unit_ln356_Z_448_v_1 = mux_visible_unit_ln356_z[500:448];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_visible_unit_ln356_Z_64_mux_0_v = 
        memwrite_rbm_visible_unit_ln369_q[127:64];
      else 
        mux_mux_visible_unit_ln356_Z_64_mux_0_v = mux_visible_unit_ln356_z[127:
        64];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_visible_unit_ln356_Z_64_v_1 = memwrite_rbm_visible_unit_ln369_q[
        127:64];
      else 
        mux_mux_visible_unit_ln356_Z_64_v_1 = mux_visible_unit_ln356_z[127:64];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_visible_unit_ln356_Z_v = memwrite_rbm_visible_unit_ln369_q[63:0];
      else 
        mux_mux_visible_unit_ln356_Z_v = mux_visible_unit_ln356_z[63:0];
      eq_ln368_0_0_z = mux_num_adj_ln51_z == 32'h0;
      eq_ln368_0_z = mux_quotient_ln51_z == 64'h0;
      sub_ln301_z = {mux_rem_ln51_z[62:0], mux_num_adj_ln51_z[31]} - add_ln281_q;
      le_ln820_z = {2'h0, add_ln281_q} > {1'b0, mux_rem_ln51_z, 
      mux_num_adj_ln51_z[31]};
      and_1_ln62_z = !eq_ln62_z & ge_ln59_z;
      and_0_ln62_z = eq_ln62_z & ge_ln59_z;
      and_1_ln62_0_z = !eq_ln62_0_z & ge_ln59_0_z;
      ctrlAnd_1_ln59_0_z = !ge_ln59_0_z & ctrlOr_ln356_z;
      and_0_ln62_0_z = eq_ln62_0_z & ge_ln59_0_z;
      ternaryMux_ln821_0_z = !memread_rbm_pos_ln812_rtl_Q & 
      memread_rbm_neg_ln813_rtl_Q;
      mt_bridge0_rtl_a_sel_3 = memwrite_rbm_mt_ln129_0_en | 
      memwrite_rbm_mt_ln127_0_en | state_rbm_0_cmos32soi_rbm_train_rbm[33];
      mt_bridge0_rtl_a_sel_0 = memwrite_rbm_mt_ln129_en | 
      memwrite_rbm_mt_ln127_en | state_rbm_0_cmos32soi_rbm_train_rbm[68];
      mt_bridge0_rtl_a_sel_4 = memwrite_rbm_mt_ln146_0_en | 
      memwrite_rbm_mt_ln144_0_en;
      mt_bridge0_rtl_a_sel_2 = memwrite_rbm_mt_ln146_en | 
      memwrite_rbm_mt_ln144_en;
      mt_bridge0_rtl_a_sel_1 = memwrite_rbm_mt_ln105_en | 
      memwrite_rbm_mt_ln105_0_en | memwrite_rbm_mt_ln103_en | 
      memwrite_rbm_mt_ln103_0_en;
      mt_bridge0_rtl_d_sel_0 = memwrite_rbm_mt_ln146_en | 
      memwrite_rbm_mt_ln146_0_en | memwrite_rbm_mt_ln129_en | 
      memwrite_rbm_mt_ln129_0_en | memwrite_rbm_mt_ln105_en | 
      memwrite_rbm_mt_ln105_0_en;
      add_ln191_z = mux_v_ln191_z + 9'h1;
      eq_ln193_z = {8'h0, mux_v_ln191_z} == {add_ln708_1_q, !
      read_rbm_num_visible_ln687_q[0]};
      lt_ln191_z = mux_v_ln191_z <= 9'h1f4;
      mult_ln200_z = mux_v_ln191_z * 9'h65;
      add_ln195_z = mult_ln195_q + mux_v_ln191_z;
      add_ln766_z = mux_v_ln766_z + 9'h1;
      eq_ln768_z = {8'h0, mux_v_ln766_z} == {add_ln708_1_q, !
      read_rbm_num_visible_ln687_q[0]};
      mult_ln781_z = mux_v_ln766_z * 9'h65;
      add_ln770_z = mult_ln195_q + mux_v_ln766_z;
      eq_ln708_z = {8'h0, mux_v_ln706_z} == {add_ln708_1_q, !
      read_rbm_num_visible_ln687_q[0]};
      mult_ln715_1_z = mux_v_ln706_z * 9'h65;
      add_ln706_z = mux_v_ln706_z + 9'h1;
      add_ln711_z = mux_h_ln711_z + 7'h1;
      eq_ln713_z = {10'h0, mux_h_ln711_z} == {add_ln713_1_q, !
      read_rbm_num_hidden_ln688_q[0]};
      add_ln715_1_z = memwrite_rbm_visible_unit_ln365_q[292:277] + mux_h_ln711_z;
      add_ln316_z = mux_j_ln316_z + 3'h1;
      add_ln290_z = mux_j_ln290_z + 3'h1;
      add_ln300_z = {1'b0, mux_v_ln282_q} + mux_j_ln290_z;
      if (ACTIVATE_VISIBLE_TRAIN_ENERGY_UPDATE_for_begin_or_0) 
        visibleEnergies_bridge3_rtl_a = mux_j_ln316_z;
      else 
        visibleEnergies_bridge3_rtl_a = mux_j_ln328_z;
      add_ln328_z = mux_j_ln328_z + 3'h1;
      add_ln775_z = mux_h_ln775_z + 7'h1;
      eq_ln777_z = {10'h0, mux_h_ln775_z} == {add_ln713_1_q, !
      read_rbm_num_hidden_ln688_q[0]};
      add_ln781_z = memwrite_rbm_visible_unit_ln365_q[238:223] + mux_h_ln775_z;
      add_ln811_z = memwrite_rbm_visible_unit_ln365_q[137:122] + mux_h_ln799_z;
      add_ln799_z = mux_h_ln799_z + 7'h1;
      eq_ln801_z = {10'h0, mux_h_ln799_z} == {add_ln713_1_q, !
      read_rbm_num_hidden_ln688_q[0]};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[16]) 
        mux_mux_h_ln799_Z_0_v = memwrite_rbm_visible_unit_ln365_q[96];
      else 
        mux_mux_h_ln799_Z_0_v = mux_h_ln799_z[0];
      add_ln808_z = memwrite_rbm_visible_unit_ln365_q[137:122] + mux_h_ln799_z;
      eq_ln296_z = {10'h0, mux_h_ln294_z} == {add_ln713_1_q, !
      read_rbm_num_hidden_ln688_q[0]};
      case (1'b1)// synopsys parallel_case
        if_ln777_1_or_0: hidden_unit_bridge3_rtl_a = mux_h_ln775_z;
        ctrlOr_ln294_0_z: hidden_unit_bridge3_rtl_a = mux_h_ln294_z;
        if_ln801_1_or_0: hidden_unit_bridge3_rtl_a = mux_h_ln799_z;
        default: hidden_unit_bridge3_rtl_a = 7'hX;
      endcase
      lt_ln294_z = mux_h_ln294_z <= 7'h64;
      add_ln294_z = mux_h_ln294_z + 7'h1;
      add_ln117_z = mux_kk_ln111_z + 10'h31d;
      add_ln114_z = mux_kk_ln111_z + 10'h1;
      add_ln117_0_z = mux_kk_ln111_0_z + 10'h31d;
      add_ln114_0_z = mux_kk_ln111_0_z + 10'h1;
      add_ln89_z = {1'b0, mux_kk_ln86_z} + 9'h1;
      add_ln92_z = {2'h0, mux_kk_ln86_z} + 10'h18d;
      add_ln86_z = mux_kk_ln86_z + 8'h1;
      add_ln89_0_z = {1'b0, mux_kk_ln86_0_z} + 9'h1;
      add_ln92_0_z = {2'h0, mux_kk_ln86_0_z} + 10'h18d;
      add_ln86_0_z = mux_kk_ln86_0_z + 8'h1;
      sub_ln69_z = mux_mti_ln67_z - 10'h1;
      add_ln67_z = mux_mti_ln67_z + 10'h1;
      sub_ln69_0_z = mux_mti_ln67_0_z - 10'h1;
      add_ln67_0_z = mux_mti_ln67_0_z + 10'h1;
      and_ln757_z = read_rbm_num_users_ln689_q[0] & mux_current_loop_ln733_z[0];
      eq_ln735_z = mux_current_loop_ln733_z == {16'h0, 
      read_rbm_num_loops_ln690_q};
      add_ln836_z = mux_current_loop_ln733_z + 32'h1;
      eq_ln186_z = {9'h0, mux_h_ln184_z} == read_rbm_num_hidden_ln688_q;
      lt_ln184_z = mux_h_ln184_z[6:2] <= 5'h18;
      add_ln184_z = mux_h_ln184_z + 7'h1;
      add_ln51_z = mux_i_ln51_z + 7'h1;
      add_ln356_z = mux_j_ln356_z + 3'h1;
      memread_pow2_ln359_z = memwrite_pow2_ln351_q[{mux_j_ln356_z, 5'h0}+:32];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_mux_j_ln356_Z_0_v = mux_j_ln356_q;
      else 
        mux_mux_j_ln356_Z_0_v = mux_j_ln356_z[0];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_mux_j_ln356_Z_0_v_0 = mux_j_ln356_q;
      else 
        mux_mux_j_ln356_Z_0_v_0 = mux_j_ln356_z[0];
      add_ln365_z = mux_v_ln282_q + mux_j_ln356_z;
      add_ln792_z = mux_v_ln792_z + 9'h1;
      eq_ln794_z = {8'h0, mux_v_ln792_z} == {add_ln708_1_q, !
      read_rbm_num_visible_ln687_q[0]};
      memread_rbm_visible_unit_ln806_z = memwrite_rbm_visible_unit_ln369_q[
      mux_v_ln792_z];
      mult_ln808_z = mux_v_ln792_z * 9'h65;
      add_ln796_z = mult_ln195_q + mux_v_ln792_z;
      lt_ln745_z = {17'h0, read_rbm_num_users_ln689_q} > {1'b0, mux_user_ln745_z};
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mux_user_ln745_Z_0_v = mux_user_ln745_q;
      else 
        mux_mux_user_ln745_Z_0_v = mux_user_ln745_z[0];
      xor_ln758_z = mux_user_ln745_z[0] ^ and_ln757_q;
      add_ln745_z = mux_user_ln745_z + 32'h1;
      eq_ln284_z = {7'h0, mux_v_ln282_z} == read_rbm_num_visible_ln687_q;
      lt_ln282_z = mux_v_ln282_z[8:2] <= 7'h7c;
      add_ln282_z = mux_v_ln282_z + 9'h5;
      ternaryMux_ln817_0_z = memread_rbm_pos_ln812_rtl_Q & unary_nor_ln817_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[65]) 
        mux_sum_ln191_z = 16'h0;
      else 
        mux_sum_ln191_z = mux_sum_ln198_z;
      case (1'b1)// synopsys parallel_case
        case_mux_tmp_ln333_z[0]: mux_tmp_ln333_z = {
          visibleEnergies_bridge3_rtl_Q[15], visibleEnergies_bridge3_rtl_Q[5:1]};
        case_mux_tmp_ln333_z[1]: mux_tmp_ln333_z = {1'b0, add_ln339_z};
        case_mux_tmp_ln333_z[2]: mux_tmp_ln333_z = 6'h3f;
        default: mux_tmp_ln333_z = 6'hX;
      endcase
      xor_ln163_z = {xor_ln160_z[5], mt_bridge1_rtl_Q[30:29], xor_ln160_z[3:2]} ^ 
      {xor_ln157_z[6:5], xor_ln160_z[1:0], xor_ln157_z[2]};
      xor_ln163_0_z = {xor_ln160_0_z[12], mt_bridge1_rtl_Q[30:29], xor_ln160_0_z
      [10:9], mt_bridge1_rtl_Q[25], xor_ln160_0_z[8], mt_bridge1_rtl_Q[23:22], 
      xor_ln160_0_z[5], xor_ln157_0_z[14]} ^ {xor_ln157_0_z[13:12], 
      xor_ln160_0_z[4:3], xor_ln157_0_z[9], xor_ln160_0_z[2:1], xor_ln157_0_z[6], 
      xor_ln160_0_z[0], xor_ln157_0_z[2:1]};
      xor_ln165_6_z = mt_bridge1_rtl_Q[28] ^ mt_bridge1_rtl_Q[24] ^ 
      mt_bridge1_rtl_Q[6] ^ xor_ln160_0_z[1];
      xor_ln165_9_z = mt_bridge1_rtl_Q[31] ^ mt_bridge1_rtl_Q[27] ^ 
      mt_bridge1_rtl_Q[9] ^ xor_ln157_0_z[1] ^ xor_ln160_0_z[3];
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln750_z: train_start_d = 1'b1;
        ctrlAnd_1_ln753_z: train_start_d = 1'b0;
        train_start_hold: train_start_d = train_start;
        default: train_start_d = 1'bX;
      endcase
      ctrlOr_ln191_0_z = ctrlOr_ln198_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[65];
      ctrlOr_ln711_z = ctrlAnd_0_ln713_z | ctrlAnd_1_ln711_z;
      ctrlOr_ln711_0_z = ctrlAnd_0_ln711_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[93];
      if (eq_ln368_0_0_z) 
        mux_this__ln361_0_z = mux_num_adj_ln51_z;
      else 
        mux_this__ln361_0_z = {mux_num_adj_ln51_z[30:0], 1'b0};
      if (eq_ln368_0_z) 
        mux_this__ln361_z = mux_quotient_ln51_z;
      else 
        mux_this__ln361_z = {mux_quotient_ln51_z[62:0], 1'b0};
      ctrlAnd_1_ln62_0_z = and_1_ln62_0_z & ctrlOr_ln356_z;
      ctrlOr_ln59_0_z = ctrlAnd_1_ln59_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[50];
      ctrlAnd_0_ln62_0_z = and_0_ln62_0_z & ctrlOr_ln356_z;
      case (1'b1)// synopsys parallel_case
        mt_bridge0_rtl_a_sel: mt_bridge0_rtl_a = 10'h0;
        mt_bridge0_rtl_a_sel_0: mt_bridge0_rtl_a = {mux_mti_ln59_0_q[8], 
          add_ln271_q[21], mux_mti_ln59_0_q[7:0]};
        mt_bridge0_rtl_a_sel_1: mt_bridge0_rtl_a = {2'h0, mux_mti_ln59_0_q[7:0]};
        mt_bridge0_rtl_a_sel_2: mt_bridge0_rtl_a = {1'b1, mux_this_ln361_0_2_q[0], 
          add_ln271_q[20:14], !mux_mti_ln59_0_q[0]};
        mt_bridge0_rtl_a_sel_3: mt_bridge0_rtl_a = {mux_mti_ln59_0_q[8], 
          mux_this_ln361_0_2_q[0], mux_mti_ln59_0_q[7:0]};
        mt_bridge0_rtl_a_sel_4: mt_bridge0_rtl_a = {1'b1, add_ln271_q[21:14], !
          mux_mti_ln59_0_q[0]};
        default: mt_bridge0_rtl_a = 10'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        mt_bridge0_rtl_a_sel: mt_bridge0_rtl_d = 32'h1571;
        state_rbm_0_cmos32soi_rbm_train_rbm[68]: mt_bridge0_rtl_d = add_ln75_z;
        mt_bridge0_rtl_d_sel: mt_bridge0_rtl_d = {!add_ln271_q[11], add_ln271_q[
          54:53], !add_ln271_q[52], !add_ln271_q[51], add_ln271_q[50:49], !
          add_ln271_q[48], add_ln271_q[47:44], !add_ln271_q[43], add_ln271_q[42:
          40], !add_ln271_q[39], add_ln271_q[38], !add_ln271_q[37], !add_ln271_q
          [36], add_ln271_q[35:32], !add_ln271_q[31], !add_ln271_q[30], 
          add_ln271_q[29], !add_ln271_q[28], !add_ln271_q[27], !add_ln271_q[26], 
          !add_ln271_q[25], !add_ln271_q[24]};
        mt_bridge0_rtl_d_sel_0: mt_bridge0_rtl_d = {add_ln271_q[11], add_ln271_q
          [54:24]};
        state_rbm_0_cmos32soi_rbm_train_rbm[33]: mt_bridge0_rtl_d = add_ln75_0_z;
        default: mt_bridge0_rtl_d = 32'hX;
      endcase
      if_ln193_z = ~eq_ln193_z;
      if_ln191_z = ~lt_ln191_z;
      add_ln200_z = mult_ln200_z + mux_rem_ln58_q[20:14];
      lt_ln766_z = add_ln766_z <= 9'h1f4;
      lt_ln706_z = add_ln706_z <= 9'h1f4;
      lt_ln711_z = add_ln711_z <= 7'h64;
      lt_ln316_z = add_ln316_z <= 3'h4;
      lt_ln290_z = add_ln290_z <= 3'h4;
      mult_ln300_z = add_ln300_z * 10'h65;
      lt_ln328_z = add_ln328_z <= 3'h4;
      lt_ln775_z = add_ln775_z <= 7'h64;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[16]) 
        mux_add_ln811_Z_v = memwrite_rbm_visible_unit_ln365_q[118:103];
      else 
        mux_add_ln811_Z_v = add_ln811_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[16]) 
        mux_add_ln799_Z_1_v_0 = memwrite_rbm_visible_unit_ln365_q[146:141];
      else 
        mux_add_ln799_Z_1_v_0 = add_ln799_z[6:1];
      lt_ln799_z = add_ln799_z <= 7'h64;
      if_ln296_z = ~eq_ln296_z;
      if_ln294_z = ~lt_ln294_z;
      lt_ln111_z = add_ln114_z <= 10'h26e;
      lt_ln111_0_z = add_ln114_0_z <= 10'h26e;
      lt_ln86_z = add_ln86_z <= 8'he2;
      lt_ln86_0_z = add_ln86_0_z <= 8'he2;
      lt_ln67_z = add_ln67_z[9:4] <= 6'h26;
      case (1'b1)// synopsys parallel_case
        RAND_LOOP1_for_begin_or_0: mt_bridge1_rtl_a = sub_ln69_z;
        RAND_LOOP2_for_begin_or_0: mt_bridge1_rtl_a = {2'h0, mux_kk_ln86_z};
        mt_bridge1_rtl_a_sel: mt_bridge1_rtl_a = {1'b0, add_ln271_q[21:14], !
          mux_mti_ln59_0_q[0]};
        mt_bridge1_rtl_a_sel_0: mt_bridge1_rtl_a = {mux_mti_ln59_0_q[8], 
          mux_this_ln361_0_2_q[0], memwrite_rbm_visible_unit_ln365_q[3:0], 
          mux_rem_ln58_q[63], add_ln271_q[15:14], !mux_mti_ln59_0_q[0]};
        ctrlOr_ln111_z: mt_bridge1_rtl_a = mux_kk_ln111_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[77]: mt_bridge1_rtl_a = {add_ln271_q
          [22], mux_this_ln361_0_2_q[0], add_ln271_q[20:14], !mux_mti_ln59_0_q[0]};
        mt_bridge1_rtl_a_sel_1: mt_bridge1_rtl_a = {
          memwrite_rbm_visible_unit_ln365_q[5:0], mux_rem_ln58_q[63], !
          add_ln271_q[15], add_ln271_q[14], !mux_mti_ln59_0_q[0]};
        mt_bridge1_rtl_a_sel_2: mt_bridge1_rtl_a = 10'h26f;
        mt_bridge1_rtl_a_sel_3: mt_bridge1_rtl_a = 10'h0;
        mt_bridge1_rtl_a_sel_4: mt_bridge1_rtl_a = 10'h18c;
        ifBot_ln59_or_0: mt_bridge1_rtl_a = mux_mti_ln59_z[9:0];
        RAND_LOOP1_for_begin_0_or_0: mt_bridge1_rtl_a = sub_ln69_0_z;
        RAND_LOOP2_for_begin_0_or_0: mt_bridge1_rtl_a = {2'h0, mux_kk_ln86_0_z};
        ctrlOr_ln111_0_z: mt_bridge1_rtl_a = mux_kk_ln111_0_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[42]: mt_bridge1_rtl_a = {add_ln271_q
          [22:14], !mux_mti_ln59_0_q[0]};
        state_rbm_0_cmos32soi_rbm_train_rbm[51]: mt_bridge1_rtl_a = {
          mux_mti_ln59_0_q[8], add_ln271_q[21], mux_mti_ln59_0_q[7:0]};
        default: mt_bridge1_rtl_a = 10'hX;
      endcase
      lt_ln67_0_z = add_ln67_0_z[9:4] <= 6'h26;
      if_ln186_z = ~eq_ln186_z;
      if_ln184_z = ~lt_ln184_z;
      lt_ln51_z = add_ln51_z <= 7'h5e;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_add_ln356_Z_1_mux_0_v = add_ln356_1_q;
      else 
        mux_add_ln356_Z_1_mux_0_v = add_ln356_z[2:1];
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_add_ln356_Z_1_v_1 = add_ln356_1_q;
      else 
        mux_add_ln356_Z_1_v_1 = add_ln356_z[2:1];
      lt_ln356_z = add_ln356_z <= 3'h4;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_memread_pow2_ln359_Z_0_mux_0_v = memread_pow2_ln359_q;
      else 
        mux_memread_pow2_ln359_Z_0_mux_0_v = memread_pow2_ln359_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_memread_pow2_ln359_Z_v = memread_pow2_ln359_q;
      else 
        mux_memread_pow2_ln359_Z_v = memread_pow2_ln359_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_add_ln365_Z_0_mux_0_v = add_ln365_q;
      else 
        mux_add_ln365_Z_0_mux_0_v = add_ln365_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_add_ln365_Z_v = add_ln365_q;
      else 
        mux_add_ln365_Z_v = add_ln365_z;
      lt_ln792_z = add_ln792_z <= 9'h1f4;
      case (1'b1)// synopsys parallel_case
        ACTIVATE_HIDDEN_TRAIN_V_for_exit_1_or_0: data_bridge1_rtl_a = 
          add_ln195_z;
        if_ln768_1_or_0: data_bridge1_rtl_a = add_ln770_z;
        if_ln794_1_or_0: data_bridge1_rtl_a = add_ln796_z;
        default: data_bridge1_rtl_a = 10'hX;
      endcase
      mult_ln195_z = xor_ln758_z * 9'h1f5;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_add_ln745_Z_1_v_0 = add_ln745_1_q;
      else 
        mux_add_ln745_Z_1_v_0 = add_ln745_z[31:1];
      if_ln284_z = ~eq_ln284_z;
      if_ln282_z = ~lt_ln282_z;
      case (mux_tmp_ln333_z[4:0])
        5'h0: lsh_ln348_z = 32'h1;
        5'h1: lsh_ln348_z = 32'h2;
        5'h2: lsh_ln348_z = 32'h4;
        5'h3: lsh_ln348_z = 32'h8;
        5'h4: lsh_ln348_z = 32'h10;
        5'h5: lsh_ln348_z = 32'h20;
        5'h6: lsh_ln348_z = 32'h40;
        5'h7: lsh_ln348_z = 32'h80;
        5'h8: lsh_ln348_z = 32'h100;
        5'h9: lsh_ln348_z = 32'h200;
        5'ha: lsh_ln348_z = 32'h400;
        5'hb: lsh_ln348_z = 32'h800;
        5'hc: lsh_ln348_z = 32'h1000;
        5'hd: lsh_ln348_z = 32'h2000;
        5'he: lsh_ln348_z = 32'h4000;
        5'hf: lsh_ln348_z = 32'h8000;
        5'h10: lsh_ln348_z = 32'h10000;
        5'h11: lsh_ln348_z = 32'h20000;
        5'h12: lsh_ln348_z = 32'h40000;
        5'h13: lsh_ln348_z = 32'h80000;
        5'h14: lsh_ln348_z = 32'h100000;
        5'h15: lsh_ln348_z = 32'h200000;
        5'h16: lsh_ln348_z = 32'h400000;
        5'h17: lsh_ln348_z = 32'h800000;
        5'h18: lsh_ln348_z = 32'h1000000;
        5'h19: lsh_ln348_z = 32'h2000000;
        5'h1a: lsh_ln348_z = 32'h4000000;
        5'h1b: lsh_ln348_z = 32'h8000000;
        5'h1c: lsh_ln348_z = 32'h10000000;
        5'h1d: lsh_ln348_z = 32'h20000000;
        5'h1e: lsh_ln348_z = 32'h40000000;
        5'h1f: lsh_ln348_z = 32'h80000000;
        default: lsh_ln348_z = 32'h0;
      endcase
      lt_ln786_z = {1'b0, mux_rem_ln58_q[33:27]} > {1'b0, xor_ln163_z[4:2], 
      xor_ln160_z[4], xor_ln163_z[1:0]};
      xor_ln165_z = {xor_ln160_0_z[3], xor_ln157_0_z[9], xor_ln160_0_z[0], 
      xor_ln157_0_z[4:3], xor_ln157_0_z[1]} ^ {xor_ln163_0_z[9:8], xor_ln163_0_z
      [5], xor_ln163_0_z[3:2], xor_ln157_0_z[17]};
      ctrlAnd_1_ln706_z = !memwrite_rbm_visible_unit_ln365_q[293] & 
      ctrlOr_ln711_z;
      ctrlAnd_0_ln706_z = memwrite_rbm_visible_unit_ln365_q[293] & 
      ctrlOr_ln711_z;
      memwrite_rbm_visible_unit_ln365_268_mux_0_sel = ctrlOr_ln711_0_z | 
      ctrlAnd_1_ln51_z;
      if (gt_ln856_z) 
        mux_max_ln310_z = mux_sum_ln294_z;
      else 
        mux_max_ln310_z = memwrite_rbm_visible_unit_ln365_q[60:45];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln86_z: mux_this_ln361_0_2_0_d = add_ln92_z[8];
        mux_this_ln361_0_2_0_sel: mux_this_ln361_0_2_0_d = mux_this_ln361_0_2_q[
          0];
        ctrlOr_ln111_z: mux_this_ln361_0_2_0_d = add_ln114_z[8];
        ctrlOr_ln67_0_z: mux_this_ln361_0_2_0_d = mux_mti_ln67_0_z[8];
        ctrlOr_ln86_0_z: mux_this_ln361_0_2_0_d = add_ln92_0_z[8];
        ctrlOr_ln111_0_z: mux_this_ln361_0_2_0_d = mux_kk_ln111_0_z[8];
        ctrlOr_ln51_z: mux_this_ln361_0_2_0_d = mux_this__ln361_0_z[2];
        default: mux_this_ln361_0_2_0_d = 1'bX;
      endcase
      if (!le_ln820_z) 
        mux_rem_ln58_z = sub_ln301_z;
      else 
        mux_rem_ln58_z = {mux_rem_ln51_z[62:0], mux_num_adj_ln51_z[31]};
      add_ln271_z = mux_this__ln361_z + !le_ln820_z;
      ctrlOr_ln62_0_z = ctrlAnd_1_ln62_0_z | ctrlAnd_1_ln67_0_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln67_z: mux_mti_ln59_0_1_d_0 = mux_mti_ln67_z[7:1];
        mux_mti_ln59_0_1_mux_0_sel: mux_mti_ln59_0_1_d_0 = mux_mti_ln59_0_q[7:1];
        ctrlOr_ln86_z: mux_mti_ln59_0_1_d_0 = mux_kk_ln86_z[7:1];
        ctrlOr_ln111_z: mux_mti_ln59_0_1_d_0 = mux_kk_ln111_z[7:1];
        ctrlOr_ln67_0_z: mux_mti_ln59_0_1_d_0 = mux_mti_ln67_0_z[7:1];
        ctrlOr_ln86_0_z: mux_mti_ln59_0_1_d_0 = mux_kk_ln86_0_z[7:1];
        ctrlOr_ln111_0_z: mux_mti_ln59_0_1_d_0 = mux_kk_ln111_0_z[7:1];
        ctrlOr_ln59_0_z: mux_mti_ln59_0_1_d_0 = mux_mti_ln59_0_z[7:1];
        ctrlOr_ln51_z: mux_mti_ln59_0_1_d_0 = {mux_this__ln361_0_z[1:0], 
          add_ln51_z[6:2]};
        default: mux_mti_ln59_0_1_d_0 = 7'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln67_z: mux_mti_ln59_0_8_d = mux_mti_ln67_z[9];
        mux_mti_ln59_0_8_sel: mux_mti_ln59_0_8_d = mux_mti_ln59_0_q[8];
        ctrlOr_ln86_z: mux_mti_ln59_0_8_d = add_ln92_z[9];
        ctrlOr_ln111_z: mux_mti_ln59_0_8_d = mux_kk_ln111_z[9];
        ctrlOr_ln67_0_z: mux_mti_ln59_0_8_d = mux_mti_ln67_0_z[9];
        ctrlOr_ln86_0_z: mux_mti_ln59_0_8_d = add_ln92_0_z[9];
        ctrlOr_ln111_0_z: mux_mti_ln59_0_8_d = mux_kk_ln111_0_z[9];
        ctrlOr_ln59_0_z: mux_mti_ln59_0_8_d = mux_mti_ln59_0_z[9];
        ctrlOr_ln51_z: mux_mti_ln59_0_8_d = mux_this__ln361_0_z[3];
        default: mux_mti_ln59_0_8_d = 1'bX;
      endcase
      and_1_ln193_z = if_ln193_z & lt_ln191_z;
      or_and_0_ln193_Z_0_z = if_ln191_z | eq_ln193_z;
      ctrlAnd_1_ln777_z = !eq_ln777_z & ctrlOr_ln775_0_z;
      ctrlAnd_0_ln777_z = eq_ln777_z & ctrlOr_ln775_0_z;
      case (1'b1)// synopsys parallel_case
        edges_bridge2_rtl_a_sel: edges_bridge2_rtl_a = 
          memwrite_rbm_visible_unit_ln365_q[118:103];
        ifBot_ln803_or_0: edges_bridge2_rtl_a = mux_add_ln811_Z_v;
        default: edges_bridge2_rtl_a = 16'hX;
      endcase
      if (state_rbm_0_cmos32soi_rbm_train_rbm[16]) 
        mux_lt_ln799_Z_0_v = memwrite_rbm_visible_unit_ln365_q[147];
      else 
        mux_lt_ln799_Z_0_v = lt_ln799_z;
      and_1_ln803_z = memwrite_rbm_visible_unit_ln365_q[140] & !eq_ln801_z;
      ctrlAnd_0_ln801_z = eq_ln801_z & ctrlOr_ln799_0_z;
      and_0_ln803_z = !memwrite_rbm_visible_unit_ln365_q[140] & !eq_ln801_z;
      and_1_ln296_z = if_ln296_z & lt_ln294_z;
      or_and_0_ln296_Z_0_z = if_ln294_z | eq_ln296_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln67_0_z: mux_this_ln361_0_2_1_d_0 = {lt_ln67_0_z, add_ln67_0_z[9:
          1]};
        mux_this_ln361_0_2_1_mux_0_sel: mux_this_ln361_0_2_1_d_0 = 
          mux_this_ln361_0_2_q[10:1];
        ctrlOr_ln51_z: mux_this_ln361_0_2_1_d_0 = mux_this__ln361_0_z[13:4];
        default: mux_this_ln361_0_2_1_d_0 = 10'hX;
      endcase
      and_1_ln186_z = if_ln186_z & lt_ln184_z;
      or_and_0_ln186_Z_0_z = if_ln184_z | eq_ln186_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[34]) 
        mux_lt_ln356_Z_0_v = lt_ln356_q;
      else 
        mux_lt_ln356_Z_0_v = lt_ln356_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[50]) 
        mux_lt_ln356_Z_0_v_0 = lt_ln356_q;
      else 
        mux_lt_ln356_Z_0_v_0 = lt_ln356_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[6]) 
        mux_mult_ln195_Z_v = mult_ln195_q;
      else 
        mux_mult_ln195_Z_v = mult_ln195_z;
      and_1_ln284_z = if_ln284_z & lt_ln282_z;
      or_and_0_ln284_Z_0_z = if_ln282_z | eq_ln284_z;
      case (1'b1)
        ternaryMux_ln817_0_z: case_mux_de_ln817_z = 3'h1;
        ternaryMux_ln821_0_z: case_mux_de_ln817_z = 3'h2;
        default: case_mux_de_ln817_z = 3'h4;
      endcase
      if (state_rbm_0_cmos32soi_rbm_train_rbm[69]) 
        mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_v = mux_rem_ln58_q[33:27];
      else 
        mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_v = 
        rbm_0_cmos32soi_sigmoid_ln205_z;
      if (state_rbm_0_cmos32soi_rbm_train_rbm[86]) 
        mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_0_mux_0_v = mux_rem_ln58_q
        [33:27];
      else 
        mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_0_mux_0_v = 
        rbm_0_cmos32soi_sigmoid_ln205_z;
      if (mux_tmp_ln333_z[5]) 
        mux_dp_ln345_z = 32'h0;
      else 
        mux_dp_ln345_z = lsh_ln348_z;
      ctrlOr_ln706_0_z = ctrlAnd_0_ln706_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[1];
      sub_ln196_0_z = mux_max_ln310_z[15:1] - 15'h1f;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln67_z: mux_rem_ln58_34_d_0 = {lt_ln67_z, add_ln67_z[9:1]};
        mux_rem_ln58_34_mux_0_sel: mux_rem_ln58_34_d_0 = mux_rem_ln58_q[43:34];
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: mux_rem_ln58_34_d_0 = {
          xor_ln165_0_z, xor_ln165_1_z, xor_ln165_8_z, xor_ln165_10_z, 
          xor_ln165_13_z, xor_ln160_0_z[11], xor_ln160_0_z[7:6], xor_ln160_0_z[4], 
          xor_ln165_3_z};
        ctrlOr_ln51_z: mux_rem_ln58_34_d_0 = mux_rem_ln58_z[43:34];
        default: mux_rem_ln58_34_d_0 = 10'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[67]: mux_rem_ln58_44_d_0 = 
          xor_ln73_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: mux_rem_ln58_44_d_0 = 
          xor_ln163_0_z[1:0];
        ctrlOr_ln51_z: mux_rem_ln58_44_d_0 = mux_rem_ln58_z[45:44];
        default: mux_rem_ln58_44_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln111_z: mux_rem_ln58_46_d = lt_ln111_z;
        mux_rem_ln58_46_sel: mux_rem_ln58_46_d = mux_rem_ln58_q[46];
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: mux_rem_ln58_46_d = 
          xor_ln163_0_z[2];
        ctrlOr_ln51_z: mux_rem_ln58_46_d = mux_rem_ln58_z[46];
        default: mux_rem_ln58_46_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[72]: mux_rem_ln58_47_d_0 = {!
          add_ln271_q[15], add_ln271_q[14]};
        mux_rem_ln58_47_mux_0_sel: mux_rem_ln58_47_d_0 = mux_rem_ln58_q[48:47];
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: mux_rem_ln58_47_d_0 = 
          xor_ln163_0_z[4:3];
        ctrlOr_ln51_z: mux_rem_ln58_47_d_0 = mux_rem_ln58_z[48:47];
        default: mux_rem_ln58_47_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[71]: mux_rem_ln58_49_d_0 = 
          add_ln271_q[20:16];
        mux_rem_ln58_49_mux_0_sel: mux_rem_ln58_49_d_0 = mux_rem_ln58_q[53:49];
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: mux_rem_ln58_49_d_0 = 
          xor_ln163_0_z[9:5];
        ctrlOr_ln51_z: mux_rem_ln58_49_d_0 = mux_rem_ln58_z[53:49];
        default: mux_rem_ln58_49_d_0 = 5'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln86_z: mux_rem_ln58_54_d = lt_ln86_z;
        mux_rem_ln58_54_sel: mux_rem_ln58_54_d = mux_rem_ln58_q[54];
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: mux_rem_ln58_54_d = 
          xor_ln163_0_z[10];
        ctrlOr_ln51_z: mux_rem_ln58_54_d = mux_rem_ln58_z[54];
        default: mux_rem_ln58_54_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln86_z: mux_rem_ln58_63_d = add_ln92_z[3];
        mux_rem_ln58_63_sel: mux_rem_ln58_63_d = mux_rem_ln58_q[63];
        ctrlOr_ln111_z: mux_rem_ln58_63_d = add_ln117_z[3];
        ctrlOr_ln86_0_z: mux_rem_ln58_63_d = add_ln92_0_z[3];
        ctrlOr_ln111_0_z: mux_rem_ln58_63_d = add_ln117_0_z[3];
        ctrlOr_ln51_z: mux_rem_ln58_63_d = mux_rem_ln58_z[63];
        default: mux_rem_ln58_63_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln316_z: mux_rem_ln58_11_d_0 = {lt_ln316_z, add_ln316_z[2:1]};
        mux_rem_ln58_11_mux_0_sel: mux_rem_ln58_11_d_0 = mux_rem_ln58_q[13:11];
        ctrlOr_ln59_0_z: mux_rem_ln58_11_d_0 = add_ln153_0_z[14:12];
        ctrlOr_ln51_z: mux_rem_ln58_11_d_0 = mux_rem_ln58_z[13:11];
        default: mux_rem_ln58_11_d_0 = 3'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln86_z: add_ln271_14_d_0 = add_ln89_z[2:1];
        mt_bridge1_rtl_a_sel: add_ln271_14_d_0 = {!add_ln271_q[15], add_ln271_q[
          14]};
        ctrlOr_ln111_z: add_ln271_14_d_0 = add_ln114_z[2:1];
        add_ln271_14_mux_0_sel: add_ln271_14_d_0 = add_ln271_q[15:14];
        ctrlOr_ln86_0_z: add_ln271_14_d_0 = add_ln89_0_z[2:1];
        ctrlOr_ln111_0_z: add_ln271_14_d_0 = add_ln114_0_z[2:1];
        ctrlOr_ln51_z: add_ln271_14_d_0 = add_ln271_z[15:14];
        default: add_ln271_14_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln86_z: add_ln271_16_d_0 = add_ln89_z[7:3];
        ctrlOr_ln111_z: add_ln271_16_d_0 = add_ln114_z[7:3];
        add_ln271_14_mux_0_sel: add_ln271_16_d_0 = add_ln271_q[20:16];
        ctrlOr_ln86_0_z: add_ln271_16_d_0 = add_ln89_0_z[7:3];
        ctrlOr_ln111_0_z: add_ln271_16_d_0 = add_ln114_0_z[7:3];
        ctrlOr_ln51_z: add_ln271_16_d_0 = add_ln271_z[20:16];
        default: add_ln271_16_d_0 = 5'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln67_z: add_ln271_21_d = mux_mti_ln67_z[8];
        add_ln271_21_sel: add_ln271_21_d = add_ln271_q[21];
        ctrlOr_ln86_z: add_ln271_21_d = add_ln89_z[8];
        ctrlOr_ln111_z: add_ln271_21_d = mux_kk_ln111_z[8];
        ctrlOr_ln86_0_z: add_ln271_21_d = add_ln89_0_z[8];
        ctrlOr_ln111_0_z: add_ln271_21_d = add_ln114_0_z[8];
        ctrlOr_ln59_0_z: add_ln271_21_d = mux_mti_ln59_0_z[8];
        ctrlOr_ln51_z: add_ln271_21_d = add_ln271_z[21];
        default: add_ln271_21_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln111_z: add_ln271_22_d = add_ln114_z[9];
        add_ln271_22_sel: add_ln271_22_d = add_ln271_q[22];
        ctrlOr_ln111_0_z: add_ln271_22_d = add_ln114_0_z[9];
        ctrlOr_ln51_z: add_ln271_22_d = add_ln271_z[22];
        default: add_ln271_22_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln111_0_z: add_ln271_23_d = lt_ln111_0_z;
        add_ln271_23_sel: add_ln271_23_d = add_ln271_q[23];
        ctrlOr_ln51_z: add_ln271_23_d = add_ln271_z[23];
        default: add_ln271_23_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[73]: add_ln271_24_d_0 = xor_ln101_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[79]: add_ln271_24_d_0 = xor_ln125_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[84]: add_ln271_24_d_0 = xor_ln142_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[38]: add_ln271_24_d_0 = 
          xor_ln101_0_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[44]: add_ln271_24_d_0 = 
          xor_ln125_0_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[49]: add_ln271_24_d_0 = 
          xor_ln142_0_z;
        ctrlOr_ln51_z: add_ln271_24_d_0 = add_ln271_z[54:24];
        default: add_ln271_24_d_0 = 31'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        add_ln271_11_sel_0: add_ln271_55_d = mt_bridge1_rtl_Q[1];
        ctrlOr_ln51_z: add_ln271_55_d = add_ln271_z[55];
        default: add_ln271_55_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[37]: add_ln271_56_d_0 = {!
          add_ln271_q[15], add_ln271_q[14]};
        add_ln271_56_mux_0_sel: add_ln271_56_d_0 = add_ln271_q[57:56];
        ctrlOr_ln51_z: add_ln271_56_d_0 = add_ln271_z[57:56];
        default: add_ln271_56_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[36]: add_ln271_58_d_0 = add_ln271_q[
          20:16];
        add_ln271_58_mux_0_sel: add_ln271_58_d_0 = add_ln271_q[62:58];
        ctrlOr_ln51_z: add_ln271_58_d_0 = add_ln271_z[62:58];
        default: add_ln271_58_d_0 = 5'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln86_0_z: add_ln271_63_d = lt_ln86_0_z;
        add_ln271_63_sel: add_ln271_63_d = add_ln271_q[63];
        ctrlOr_ln51_z: add_ln271_63_d = add_ln271_z[63];
        default: add_ln271_63_d = 1'bX;
      endcase
      lt_ln786_0_z = {1'b0, add_ln271_z} > {1'b0, mux_xor_ln165_0_Z_v, 31'h0};
      case (1'b1)// synopsys parallel_case
        memread_rbm_mt_ln116_0_2_sel: memread_rbm_mt_ln116_0_2_d = 
          mt_bridge1_rtl_Q[30:2];
        ctrlOr_ln51_z: memread_rbm_mt_ln116_0_2_d = {add_ln271_z[10:0], 
          mux_this__ln361_0_z[31:14]};
        default: memread_rbm_mt_ln116_0_2_d = 29'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        add_ln271_11_sel: add_ln271_11_d = mt_bridge1_rtl_Q[31];
        add_ln271_11_sel_0: add_ln271_11_d = add_ln271_q[11];
        ctrlOr_ln51_z: add_ln271_11_d = add_ln271_z[11];
        default: add_ln271_11_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln62_0_z: add_ln365_d = {memread_pow2_ln359_z, add_ln365_z};
        add_ln365_sel: add_ln365_d = {memread_pow2_ln359_q, add_ln365_q};
        ctrlOr_ln62_0_z: add_ln365_d = {mux_memread_pow2_ln359_Z_v, 
          mux_add_ln365_Z_v};
        ctrlOr_ln59_0_z: add_ln365_d = {mux_memread_pow2_ln359_Z_0_mux_0_v, 
          mux_add_ln365_Z_0_mux_0_v};
        ctrlOr_ln51_z: add_ln365_d = {mux_xor_ln165_0_Z_v[12:11], 
          mux_xor_ln165_0_Z_v[7], mux_xor_ln165_0_Z_v[5:4], mux_xor_ln165_0_Z_v[
          2], mux_xor_ln165_0_Z_v[6], mux_xor_ln165_0_Z_v[9], 
          mux_xor_ln165_0_Z_v[31:29], mux_xor_ln165_0_Z_v[27:22], 
          mux_xor_ln165_0_Z_v[18:17], mux_xor_ln165_0_Z_v[0], 
          mux_xor_ln165_0_Z_v[1], mux_xor_ln165_0_Z_v[8], mux_xor_ln165_0_Z_v[10], 
          mux_xor_ln165_0_Z_v[13], mux_xor_ln165_0_Z_v[28], mux_xor_ln165_0_Z_v[
          21], mux_xor_ln165_0_Z_v[19], mux_xor_ln165_0_Z_v[14], 
          mux_xor_ln165_0_Z_v[3], mux_xor_ln165_0_Z_v[20], mux_xor_ln165_0_Z_v[
          16:15], add_ln365_q};
        default: add_ln365_d = 41'hX;
      endcase
      add_ln281_sel = ctrlOr_ln86_0_z | ctrlOr_ln67_0_z | ctrlOr_ln62_0_z | 
      ctrlOr_ln59_0_z | ctrlOr_ln51_z | ctrlOr_ln111_0_z | ctrlAnd_1_ln86_0_z | 
      ctrlAnd_1_ln51_z | ctrlAnd_1_ln111_0_z | ctrlAnd_0_ln62_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[52] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[28] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      ctrlAnd_1_ln193_z = and_1_ln193_z & ctrlOr_ln191_0_z;
      ctrlAnd_0_ln193_z = or_and_0_ln193_Z_0_z & ctrlOr_ln191_0_z;
      memwrite_rbm_visible_unit_ln365_214_mux_0_sel = ctrlAnd_1_ln777_z | 
      ctrlAnd_1_ln51_z | ctrlAnd_0_ln772_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[63] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[60];
      memwrite_rbm_visible_unit_ln365_240_sel = ctrlAnd_1_ln777_z | 
      ctrlAnd_1_ln51_z | ctrlAnd_0_ln772_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[63];
      ctrlOr_ln772_z = ctrlAnd_0_ln777_z | ctrlAnd_1_ln772_z | ctrlAnd_1_ln775_z;
      ctrlAnd_1_ln803_z = and_1_ln803_z & ctrlOr_ln799_0_z;
      ctrlOr_ln799_z = ctrlAnd_0_ln801_z | ctrlAnd_1_ln799_z;
      ctrlAnd_0_ln803_z = and_0_ln803_z & ctrlOr_ln799_0_z;
      ctrlAnd_1_ln296_z = and_1_ln296_z & ctrlOr_ln294_0_z;
      ctrlAnd_0_ln296_z = or_and_0_ln296_Z_0_z & ctrlOr_ln294_0_z;
      ctrlAnd_1_ln186_z = and_1_ln186_z & ctrlOr_ln184_0_z;
      ctrlAnd_0_ln186_z = or_and_0_ln186_Z_0_z & ctrlOr_ln184_0_z;
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln62_0_z: mux_j_ln356_d_0 = {lt_ln356_z, add_ln356_z[2:1], 
          mux_j_ln356_z[0]};
        mux_j_ln356_mux_0_sel: mux_j_ln356_d_0 = {lt_ln356_q, add_ln356_1_q, 
          mux_j_ln356_q};
        ctrlOr_ln62_0_z: mux_j_ln356_d_0 = {mux_lt_ln356_Z_0_v, 
          mux_add_ln356_Z_1_v_1, mux_mux_j_ln356_Z_0_v};
        ctrlOr_ln59_0_z: mux_j_ln356_d_0 = {mux_lt_ln356_Z_0_v_0, 
          mux_add_ln356_Z_1_mux_0_v, mux_mux_j_ln356_Z_0_v_0};
        default: mux_j_ln356_d_0 = 4'hX;
      endcase
      ctrlAnd_1_ln284_z = and_1_ln284_z & ctrlOr_ln282_0_z;
      ctrlAnd_0_ln284_z = or_and_0_ln284_Z_0_z & ctrlOr_ln282_0_z;
      case (1'b1)// synopsys parallel_case
        case_mux_de_ln817_z[0]: mux_de_ln817_z = add_ln176_z;
        case_mux_de_ln817_z[1]: mux_de_ln817_z = sub_ln196_z;
        case_mux_de_ln817_z[2]: mux_de_ln817_z = edges_bridge2_rtl_Q;
        default: mux_de_ln817_z = 8'hX;
      endcase
      memwrite_pow2_ln351_z = memwrite_pow2_ln351_q;
      memwrite_pow2_ln351_z[{{memwrite_rbm_visible_unit_ln365_q[120:119], 
      memwrite_rbm_visible_unit_ln365_q[6]}, 5'h0}+:32] = mux_dp_ln345_z;
      ctrlAnd_1_ln708_z = !eq_ln708_z & ctrlOr_ln706_0_z;
      ctrlAnd_0_ln708_z = eq_ln708_z & ctrlOr_ln706_0_z;
      memwrite_rbm_visible_unit_ln365_z = memwrite_rbm_visible_unit_ln369_q;
      memwrite_rbm_visible_unit_ln365_z[add_ln365_q] = lt_ln786_0_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln328_z: add_ln281_d = mux_sumOfpow2_ln328_z;
        add_ln281_sel: add_ln281_d = add_ln281_q;
        ctrlAnd_1_ln328_z: add_ln281_d = add_ln281_z;
        default: add_ln281_d = 64'hX;
      endcase
      ctrlAnd_1_ln59_z = !ge_ln59_z & ctrlAnd_0_ln193_z;
      ctrlAnd_1_ln62_z = and_1_ln62_z & ctrlAnd_0_ln193_z;
      ctrlAnd_0_ln62_z = and_0_ln62_z & ctrlAnd_0_ln193_z;
      ctrlAnd_1_ln766_z = !memwrite_rbm_visible_unit_ln365_q[239] & 
      ctrlOr_ln772_z;
      ctrlAnd_0_ln766_z = memwrite_rbm_visible_unit_ln365_q[239] & 
      ctrlOr_ln772_z;
      ctrlOr_ln803_z = ctrlAnd_1_ln803_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[16];
      ctrlAnd_1_ln792_z = !memwrite_rbm_visible_unit_ln365_q[139] & 
      ctrlOr_ln799_z;
      ctrlAnd_0_ln792_z = memwrite_rbm_visible_unit_ln365_q[139] & 
      ctrlOr_ln799_z;
      hidden_unit_bridge3_rtl_CE_en = ctrlAnd_1_ln777_z | ctrlAnd_1_ln296_z | 
      ctrlAnd_0_ln803_z;
      memwrite_rbm_visible_unit_ln365_43_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | ctrlAnd_1_ln51_z | 
      ctrlAnd_1_ln296_z | state_rbm_0_cmos32soi_rbm_train_rbm[24] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      memwrite_rbm_visible_unit_ln365_45_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | ctrlOr_ln316_z | 
      ctrlAnd_1_ln51_z | ctrlAnd_1_ln296_z | ctrlAnd_1_ln290_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      memwrite_rbm_visible_unit_ln365_47_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | ctrlAnd_1_ln51_z | 
      ctrlAnd_1_ln296_z | state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln296_z: add_ln271_12_d_0 = sub_ln196_0_z[3:2];
        sub_ln196_0_1_sel: add_ln271_12_d_0 = add_ln271_q[13:12];
        state_rbm_0_cmos32soi_rbm_train_rbm[32]: add_ln271_12_d_0 = xor_ln73_0_z;
        ctrlOr_ln51_z: add_ln271_12_d_0 = add_ln271_z[13:12];
        default: add_ln271_12_d_0 = 2'hX;
      endcase
      memwrite_rbm_visible_unit_ln365_42_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | ctrlAnd_1_ln51_z | 
      ctrlAnd_1_ln296_z | ctrlAnd_0_ln296_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57];
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln296_z: mux_rem_ln58_d = sub_ln196_0_z[14:4];
        sub_ln196_0_1_sel: mux_rem_ln58_d = mux_rem_ln58_q[10:0];
        ctrlOr_ln59_0_z: mux_rem_ln58_d = add_ln153_0_z[11:1];
        ctrlOr_ln51_z: mux_rem_ln58_d = mux_rem_ln58_z[10:0];
        default: mux_rem_ln58_d = 11'hX;
      endcase
      mux_v_ln282_sel = state_rbm_0_cmos32soi_rbm_train_rbm[56] | 
      ctrlOr_ln86_0_z | ctrlOr_ln67_0_z | ctrlOr_ln62_0_z | ctrlOr_ln59_0_z | 
      ctrlOr_ln51_z | ctrlOr_ln316_z | ctrlOr_ln290_z | ctrlOr_ln111_0_z | 
      ctrlAnd_1_ln86_0_z | ctrlAnd_1_ln51_z | ctrlAnd_1_ln328_z | 
      ctrlAnd_1_ln316_z | ctrlAnd_1_ln296_z | ctrlAnd_1_ln290_z | 
      ctrlAnd_1_ln111_0_z | ctrlAnd_0_ln62_0_z | ctrlAnd_0_ln296_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[52] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln296_z: sub_ln196_0_1_d = sub_ln196_0_z[1];
        sub_ln196_0_1_sel: sub_ln196_0_1_d = sub_ln196_0_1_q;
        ctrlOr_ln51_z: sub_ln196_0_1_d = mux_i_ln51_z[0];
        default: sub_ln196_0_1_d = 1'bX;
      endcase
      visibleEnergies_bridge1_rtl_CE_en = ctrlAnd_0_ln296_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25];
      hidden_unit_bridge1_rtl_CE_en = ctrlAnd_0_ln186_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[88];
      ctrlOr_ln706_z = ctrlAnd_0_ln708_z | ctrlAnd_1_ln706_z;
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[28]: 
          memwrite_rbm_visible_unit_ln365_10_d_0 = mux_dp_ln345_z;
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_10_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[41:10];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_10_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[41:10];
        default: memwrite_rbm_visible_unit_ln365_10_d_0 = 32'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln328_z: memwrite_rbm_visible_unit_ln365_119_d_0 = mux_j_ln328_z[
          2:1];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_119_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[120:119];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_119_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[120:119];
        default: memwrite_rbm_visible_unit_ln365_119_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_148_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[155:148];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_148_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[155:148];
        state_rbm_0_cmos32soi_rbm_train_rbm[17]: 
          memwrite_rbm_visible_unit_ln365_148_d_0 = mux_de_ln817_z;
        default: memwrite_rbm_visible_unit_ln365_148_d_0 = 8'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln193_z: memwrite_rbm_visible_unit_ln365_156_d_0 = {
          add_ln191_z[8:1], mux_v_ln191_z[0], mux_sum_ln191_z};
        memwrite_rbm_visible_unit_ln365_156_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_156_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[180:156];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_156_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[180:156];
        default: memwrite_rbm_visible_unit_ln365_156_d_0 = 25'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[90]: 
          memwrite_rbm_visible_unit_ln365_181_d = eq_ln198_z;
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_181_d = 
          memwrite_rbm_visible_unit_ln365_z[181];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_181_d = 
          memwrite_rbm_visible_unit_ln365_q[181];
        default: memwrite_rbm_visible_unit_ln365_181_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_182_d = 
          memwrite_rbm_visible_unit_ln365_z[182];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_182_d = 
          memwrite_rbm_visible_unit_ln365_q[182];
        state_rbm_0_cmos32soi_rbm_train_rbm[14]: 
          memwrite_rbm_visible_unit_ln365_182_d = ternaryMux_ln808_0_z;
        default: memwrite_rbm_visible_unit_ln365_182_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[60]: 
          memwrite_rbm_visible_unit_ln365_240_d = unary_or_ln781_z;
        memwrite_rbm_visible_unit_ln365_240_sel: 
          memwrite_rbm_visible_unit_ln365_240_d = 
          memwrite_rbm_visible_unit_ln365_q[240];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_240_d = 
          memwrite_rbm_visible_unit_ln365_z[240];
        default: memwrite_rbm_visible_unit_ln365_240_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln777_z: memwrite_rbm_visible_unit_ln365_241_d_0 = {lt_ln775_z, 
          add_ln781_z, add_ln775_z[6:1]};
        memwrite_rbm_visible_unit_ln365_241_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_241_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[263:241];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_241_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[263:241];
        default: memwrite_rbm_visible_unit_ln365_241_d_0 = 23'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[63]: 
          memwrite_rbm_visible_unit_ln365_264_d = ternaryMux_ln781_0_z;
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_264_d = 
          memwrite_rbm_visible_unit_ln365_z[264];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_264_d = 
          memwrite_rbm_visible_unit_ln365_q[264];
        default: memwrite_rbm_visible_unit_ln365_264_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[87]: 
          memwrite_rbm_visible_unit_ln365_265_d = lt_ln786_z;
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_265_d = 
          memwrite_rbm_visible_unit_ln365_z[265];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_265_d = 
          memwrite_rbm_visible_unit_ln365_q[265];
        default: memwrite_rbm_visible_unit_ln365_265_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[60]: 
          memwrite_rbm_visible_unit_ln365_266_d = ne_ln772_z;
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_266_d = 
          memwrite_rbm_visible_unit_ln365_z[266];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_266_d = 
          memwrite_rbm_visible_unit_ln365_q[266];
        default: memwrite_rbm_visible_unit_ln365_266_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln708_z: memwrite_rbm_visible_unit_ln365_268_d_0 = {lt_ln706_z, 
          mult_ln715_1_z, add_ln706_z[8:1], mux_v_ln706_z[0]};
        memwrite_rbm_visible_unit_ln365_268_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_268_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[293:268];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_268_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[293:268];
        default: memwrite_rbm_visible_unit_ln365_268_d_0 = 26'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln711_0_z: memwrite_rbm_visible_unit_ln365_294_d_0 = {lt_ln711_z, 
          add_ln711_z[6:1], eq_ln713_z, mux_h_ln711_z[0]};
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_294_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[302:294];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_294_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[302:294];
        default: memwrite_rbm_visible_unit_ln365_294_d_0 = 9'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_303_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[366:303];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_303_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[366:303];
        default: memwrite_rbm_visible_unit_ln365_303_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_367_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[430:367];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_367_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[430:367];
        default: memwrite_rbm_visible_unit_ln365_367_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_431_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[494:431];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_431_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[494:431];
        default: memwrite_rbm_visible_unit_ln365_431_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_495_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[500:495];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_495_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[500:495];
        default: memwrite_rbm_visible_unit_ln365_495_d_0 = 6'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln111_z: memwrite_rbm_visible_unit_ln365_4_d_0 = add_ln117_z[9:8];
        memwrite_rbm_visible_unit_ln365_4_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_4_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[5:4];
        ctrlOr_ln111_0_z: memwrite_rbm_visible_unit_ln365_4_d_0 = add_ln117_0_z[
          9:8];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_4_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[5:4];
        default: memwrite_rbm_visible_unit_ln365_4_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln328_z: memwrite_rbm_visible_unit_ln365_6_d_0 = {lt_ln328_z, 
          add_ln328_z[2:1], mux_j_ln328_z[0]};
        memwrite_rbm_visible_unit_ln365_6_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_6_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[9:6];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_6_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[9:6];
        default: memwrite_rbm_visible_unit_ln365_6_d_0 = 4'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln296_z: memwrite_rbm_visible_unit_ln365_80_d_0 = 
          mux_sum_ln294_z;
        memwrite_rbm_visible_unit_ln365_80_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_80_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[95:80];
        state_rbm_0_cmos32soi_rbm_train_rbm[58]: 
          memwrite_rbm_visible_unit_ln365_80_d_0 = mux_sum_ln302_z;
        state_rbm_0_cmos32soi_rbm_train_rbm[24]: 
          memwrite_rbm_visible_unit_ln365_80_d_0 = sub_ln196_0_0_z;
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_80_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[95:80];
        default: memwrite_rbm_visible_unit_ln365_80_d_0 = 16'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln296_z: memwrite_rbm_visible_unit_ln365_97_d_0 = add_ln294_z[
          6:1];
        memwrite_rbm_visible_unit_ln365_97_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_97_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[102:97];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_97_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[102:97];
        default: memwrite_rbm_visible_unit_ln365_97_d_0 = 6'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln86_z: memwrite_rbm_visible_unit_ln365_d = add_ln92_z[7:4];
        memwrite_rbm_visible_unit_ln365_sel: memwrite_rbm_visible_unit_ln365_d = 
          memwrite_rbm_visible_unit_ln365_q[3:0];
        ctrlOr_ln111_z: memwrite_rbm_visible_unit_ln365_d = add_ln117_z[7:4];
        ctrlOr_ln86_0_z: memwrite_rbm_visible_unit_ln365_d = add_ln92_0_z[7:4];
        ctrlOr_ln111_0_z: memwrite_rbm_visible_unit_ln365_d = add_ln117_0_z[7:4];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_d = 
          memwrite_rbm_visible_unit_ln365_z[3:0];
        default: memwrite_rbm_visible_unit_ln365_d = 4'hX;
      endcase
      ctrlOr_ln59_z = ctrlAnd_1_ln59_z | state_rbm_0_cmos32soi_rbm_train_rbm[86];
      ctrlOr_ln62_z = ctrlAnd_1_ln62_z | ctrlAnd_1_ln67_z;
      mt_bridge0_rtl_CE_en = memwrite_rbm_mt_ln146_en | 
      memwrite_rbm_mt_ln146_0_en | memwrite_rbm_mt_ln144_en | 
      memwrite_rbm_mt_ln144_0_en | memwrite_rbm_mt_ln129_en | 
      memwrite_rbm_mt_ln129_0_en | memwrite_rbm_mt_ln127_en | 
      memwrite_rbm_mt_ln127_0_en | memwrite_rbm_mt_ln105_en | 
      memwrite_rbm_mt_ln105_0_en | memwrite_rbm_mt_ln103_en | 
      memwrite_rbm_mt_ln103_0_en | ctrlAnd_0_ln62_z | ctrlAnd_0_ln62_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33];
      ctrlOr_ln766_0_z = ctrlAnd_0_ln766_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[9];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln711_0_z: memwrite_rbm_visible_unit_ln365_103_d_0 = {
          add_ln715_1_z[15:7], add_ln715_1_z[0]};
        ctrlAnd_1_ln193_z: memwrite_rbm_visible_unit_ln365_103_d_0 = {
          add_ln200_z[15:7], add_ln200_z[0]};
        memwrite_rbm_visible_unit_ln365_103_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_103_d_0 = {
          memwrite_rbm_visible_unit_ln365_q[118:110], 
          memwrite_rbm_visible_unit_ln365_q[103]};
        state_rbm_0_cmos32soi_rbm_train_rbm[56]: 
          memwrite_rbm_visible_unit_ln365_103_d_0 = {add_ln300_0_z[15:7], 
          add_ln300_0_z[0]};
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_103_d_0 = {
          memwrite_rbm_visible_unit_ln365_z[118:110], 
          memwrite_rbm_visible_unit_ln365_z[103]};
        ctrlAnd_0_ln803_z: memwrite_rbm_visible_unit_ln365_103_d_0 = {
          add_ln811_z[15:7], add_ln811_z[0]};
        ctrlOr_ln803_z: memwrite_rbm_visible_unit_ln365_103_d_0 = {
          mux_add_ln811_Z_v[15:7], mux_add_ln811_Z_v[0]};
        default: memwrite_rbm_visible_unit_ln365_103_d_0 = 10'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln711_0_z: memwrite_rbm_visible_unit_ln365_104_d_0 = 
          add_ln715_1_z[6:1];
        ctrlAnd_1_ln193_z: memwrite_rbm_visible_unit_ln365_104_d_0 = add_ln200_z
          [6:1];
        memwrite_rbm_visible_unit_ln365_103_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_104_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[109:104];
        ctrlAnd_1_ln296_z: memwrite_rbm_visible_unit_ln365_104_d_0 = 
          mux_h_ln294_z[6:1];
        state_rbm_0_cmos32soi_rbm_train_rbm[56]: 
          memwrite_rbm_visible_unit_ln365_104_d_0 = add_ln300_0_z[6:1];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_104_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[109:104];
        ctrlAnd_0_ln803_z: memwrite_rbm_visible_unit_ln365_104_d_0 = add_ln811_z
          [6:1];
        ctrlOr_ln803_z: memwrite_rbm_visible_unit_ln365_104_d_0 = 
          mux_add_ln811_Z_v[6:1];
        default: memwrite_rbm_visible_unit_ln365_104_d_0 = 6'hX;
      endcase
      memwrite_rbm_visible_unit_ln365_121_mux_0_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | ctrlOr_ln803_z | 
      ctrlAnd_1_ln51_z | ctrlAnd_0_ln803_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[12];
      memwrite_rbm_visible_unit_ln365_140_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | ctrlOr_ln803_z | 
      ctrlAnd_1_ln51_z | ctrlAnd_0_ln803_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_141_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[147:141];
        memwrite_rbm_visible_unit_ln365_141_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_141_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[147:141];
        ctrlAnd_0_ln803_z: memwrite_rbm_visible_unit_ln365_141_d_0 = {lt_ln799_z, 
          add_ln799_z[6:1]};
        ctrlOr_ln803_z: memwrite_rbm_visible_unit_ln365_141_d_0 = {
          mux_lt_ln799_Z_0_v, mux_add_ln799_Z_1_v_0};
        default: memwrite_rbm_visible_unit_ln365_141_d_0 = 7'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln777_z: memwrite_rbm_visible_unit_ln365_96_d = mux_h_ln775_z[
          0];
        memwrite_rbm_visible_unit_ln365_96_sel: 
          memwrite_rbm_visible_unit_ln365_96_d = 
          memwrite_rbm_visible_unit_ln365_q[96];
        ctrlAnd_1_ln296_z: memwrite_rbm_visible_unit_ln365_96_d = mux_h_ln294_z[
          0];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_96_d = 
          memwrite_rbm_visible_unit_ln365_z[96];
        ctrlAnd_0_ln803_z: memwrite_rbm_visible_unit_ln365_96_d = mux_h_ln799_z[
          0];
        ctrlOr_ln803_z: memwrite_rbm_visible_unit_ln365_96_d = 
          mux_mux_h_ln799_Z_0_v;
        default: memwrite_rbm_visible_unit_ln365_96_d = 1'bX;
      endcase
      mux_rem_ln58_55_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | ctrlOr_ln803_z | 
      ctrlAnd_0_ln803_z | state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[12];
      edges_bridge2_rtl_CE_en = memread_rbm_edges_ln300_en | ctrlOr_ln803_z | 
      ctrlAnd_0_ln198_z;
      ctrlOr_ln792_0_z = ctrlAnd_0_ln792_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[11];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln290_z: memwrite_rbm_visible_unit_ln365_43_d_0 = mux_j_ln290_z[2:
          1];
        memwrite_rbm_visible_unit_ln365_43_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_43_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[44:43];
        ctrlOr_ln316_z: memwrite_rbm_visible_unit_ln365_43_d_0 = mux_j_ln316_z[2:
          1];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_43_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[44:43];
        default: memwrite_rbm_visible_unit_ln365_43_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln290_z: memwrite_rbm_visible_unit_ln365_45_d_0 = mux_max_ln290_z
          [1:0];
        memwrite_rbm_visible_unit_ln365_45_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_45_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[46:45];
        ctrlAnd_0_ln296_z: memwrite_rbm_visible_unit_ln365_45_d_0 = 
          mux_max_ln310_z[1:0];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_45_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[46:45];
        default: memwrite_rbm_visible_unit_ln365_45_d_0 = 2'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln290_z: memwrite_rbm_visible_unit_ln365_63_d_0 = mult_ln300_z;
        memwrite_rbm_visible_unit_ln365_47_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_63_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[78:63];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_63_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[78:63];
        default: memwrite_rbm_visible_unit_ln365_63_d_0 = 16'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln290_z: memwrite_rbm_visible_unit_ln365_47_d_0 = {lt_ln290_z, 
          add_ln290_z[2:1], mux_max_ln290_z[15:2]};
        memwrite_rbm_visible_unit_ln365_47_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_47_d_0 = {
          memwrite_rbm_visible_unit_ln365_q[79], 
          memwrite_rbm_visible_unit_ln365_q[62:47]};
        ctrlAnd_0_ln296_z: memwrite_rbm_visible_unit_ln365_47_d_0 = {
          memwrite_rbm_visible_unit_ln365_q[79], 
          memwrite_rbm_visible_unit_ln365_q[62:61], mux_max_ln310_z[15:2]};
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_47_d_0 = {
          memwrite_rbm_visible_unit_ln365_z[79], 
          memwrite_rbm_visible_unit_ln365_z[62:47]};
        default: memwrite_rbm_visible_unit_ln365_47_d_0 = 17'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln290_z: memwrite_rbm_visible_unit_ln365_42_d = mux_j_ln290_z[0];
        memwrite_rbm_visible_unit_ln365_42_sel: 
          memwrite_rbm_visible_unit_ln365_42_d = 
          memwrite_rbm_visible_unit_ln365_q[42];
        ctrlOr_ln316_z: memwrite_rbm_visible_unit_ln365_42_d = mux_j_ln316_z[0];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_42_d = 
          memwrite_rbm_visible_unit_ln365_z[42];
        default: memwrite_rbm_visible_unit_ln365_42_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln284_z: memwrite_pow2_ln351_55_d_0 = mux_pow2_ln282_z[118:55];
        mux_v_ln282_sel: memwrite_pow2_ln351_55_d_0 = memwrite_pow2_ln351_q[118:
          55];
        ctrlOr_ln328_z: memwrite_pow2_ln351_55_d_0 = mux_pow2_ln328_z[118:55];
        state_rbm_0_cmos32soi_rbm_train_rbm[28]: memwrite_pow2_ln351_55_d_0 = 
          memwrite_pow2_ln351_z[118:55];
        default: memwrite_pow2_ln351_55_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln284_z: mux_v_ln282_d = {mux_pow2_ln282_z[54:0], 
          mux_v_ln282_z};
        mux_v_ln282_sel: mux_v_ln282_d = {memwrite_pow2_ln351_q[54:0], 
          mux_v_ln282_q};
        ctrlOr_ln328_z: mux_v_ln282_d = {mux_pow2_ln328_z[54:0], mux_v_ln282_q};
        state_rbm_0_cmos32soi_rbm_train_rbm[28]: mux_v_ln282_d = {
          memwrite_pow2_ln351_z[54:0], mux_v_ln282_q};
        default: mux_v_ln282_d = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln284_z: memwrite_pow2_ln351_119_d_0 = {add_ln282_z[8:1], 
          mux_pow2_ln282_z[159:119]};
        mux_v_ln282_sel: memwrite_pow2_ln351_119_d_0 = {add_ln282_1_q, 
          memwrite_pow2_ln351_q[159:119]};
        ctrlOr_ln328_z: memwrite_pow2_ln351_119_d_0 = {add_ln282_1_q, 
          mux_pow2_ln328_z[159:119]};
        state_rbm_0_cmos32soi_rbm_train_rbm[28]: memwrite_pow2_ln351_119_d_0 = {
          add_ln282_1_q, memwrite_pow2_ln351_z[159:119]};
        default: memwrite_pow2_ln351_119_d_0 = 49'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln59_z: memwrite_rbm_visible_unit_ln365_183_d_0 = add_ln153_z[31:
          1];
        memwrite_rbm_visible_unit_ln365_183_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_183_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[213:183];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_183_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[213:183];
        default: memwrite_rbm_visible_unit_ln365_183_d_0 = 31'hX;
      endcase
      mt_bridge1_rtl_CE_en = ctrlOr_ln86_z | ctrlOr_ln86_0_z | ctrlOr_ln67_z | 
      ctrlOr_ln67_0_z | ctrlOr_ln59_z | ctrlOr_ln111_z | ctrlOr_ln111_0_z | 
      ctrlAnd_1_ln111_z | ctrlAnd_1_ln111_0_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln67_z: mux_mti_ln59_0_0_d = mux_mti_ln67_z[0];
        mux_mti_ln59_0_0_sel: mux_mti_ln59_0_0_d = mux_mti_ln59_0_q[0];
        ctrlOr_ln86_z: mux_mti_ln59_0_0_d = mux_kk_ln86_z[0];
        ctrlOr_ln111_z: mux_mti_ln59_0_0_d = mux_kk_ln111_z[0];
        ctrlOr_ln59_z: mux_mti_ln59_0_0_d = mux_mti_ln59_z[0];
        ctrlOr_ln67_0_z: mux_mti_ln59_0_0_d = mux_mti_ln67_0_z[0];
        ctrlOr_ln86_0_z: mux_mti_ln59_0_0_d = mux_kk_ln86_0_z[0];
        ctrlOr_ln111_0_z: mux_mti_ln59_0_0_d = mux_kk_ln111_0_z[0];
        ctrlOr_ln59_0_z: mux_mti_ln59_0_0_d = mux_mti_ln59_0_z[0];
        ctrlOr_ln51_z: mux_mti_ln59_0_0_d = add_ln51_z[1];
        default: mux_mti_ln59_0_0_d = 1'bX;
      endcase
      mux_rem_ln58_14_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[87] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[85] | ctrlOr_ln86_z | ctrlOr_ln67_z | 
      ctrlOr_ln62_z | ctrlOr_ln59_z | ctrlOr_ln111_z | ctrlAnd_1_ln86_z | 
      ctrlAnd_1_ln193_z | ctrlAnd_1_ln111_z | ctrlAnd_0_ln62_z | 
      ctrlAnd_0_ln198_z | state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[90] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[88] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74];
      mux_rem_ln58_15_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[87] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[85] | ctrlOr_ln86_z | ctrlOr_ln67_z | 
      ctrlOr_ln62_z | ctrlOr_ln59_z | ctrlOr_ln111_z | ctrlAnd_1_ln86_z | 
      ctrlAnd_1_ln193_z | ctrlAnd_1_ln111_z | ctrlAnd_0_ln62_z | 
      ctrlAnd_0_ln198_z | state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[90] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74];
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln62_z: mux_rem_ln58_27_d_0 = rbm_0_cmos32soi_sigmoid_ln205_z[
          3:0];
        mux_rem_ln58_27_mux_0_sel: mux_rem_ln58_27_d_0 = mux_rem_ln58_q[30:27];
        ctrlOr_ln62_z: mux_rem_ln58_27_d_0 = 
          mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_v[3:0];
        ctrlOr_ln59_z: mux_rem_ln58_27_d_0 = 
          mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_0_mux_0_v[3:0];
        ctrlOr_ln59_0_z: mux_rem_ln58_27_d_0 = add_ln153_0_z[31:28];
        ctrlOr_ln51_z: mux_rem_ln58_27_d_0 = mux_rem_ln58_z[30:27];
        default: mux_rem_ln58_27_d_0 = 4'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_0_ln62_z: mux_rem_ln58_31_d_0 = rbm_0_cmos32soi_sigmoid_ln205_z[
          6:4];
        mux_rem_ln58_27_mux_0_sel: mux_rem_ln58_31_d_0 = mux_rem_ln58_q[33:31];
        ctrlOr_ln62_z: mux_rem_ln58_31_d_0 = 
          mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_v[6:4];
        ctrlOr_ln59_z: mux_rem_ln58_31_d_0 = 
          mux_rbm_0_cmos32soi_sigmoid_ln205_sigmoid_out_0_mux_0_v[6:4];
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: mux_rem_ln58_31_d_0 = {
          xor_ln157_0_z[17], xor_ln157_0_z[13:12]};
        ctrlOr_ln51_z: mux_rem_ln58_31_d_0 = mux_rem_ln58_z[33:31];
        default: mux_rem_ln58_31_d_0 = 3'hX;
      endcase
      ctrlAnd_1_ln768_z = !eq_ln768_z & ctrlOr_ln766_0_z;
      ctrlAnd_0_ln768_z = eq_ln768_z & ctrlOr_ln766_0_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_140_d = 
          memwrite_rbm_visible_unit_ln365_z[140];
        memwrite_rbm_visible_unit_ln365_140_sel: 
          memwrite_rbm_visible_unit_ln365_140_d = 
          memwrite_rbm_visible_unit_ln365_q[140];
        state_rbm_0_cmos32soi_rbm_train_rbm[12]: 
          memwrite_rbm_visible_unit_ln365_140_d = ne_ln803_z;
        default: memwrite_rbm_visible_unit_ln365_140_d = 1'bX;
      endcase
      ctrlAnd_1_ln794_z = !eq_ln794_z & ctrlOr_ln792_0_z;
      ctrlAnd_0_ln794_z = eq_ln794_z & ctrlOr_ln792_0_z;
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln186_z: mux_rem_ln58_14_d_0 = {add_ln184_z[6:1], 
          mux_h_ln184_z[0]};
        mux_rem_ln58_14_mux_0_sel: mux_rem_ln58_14_d_0 = {mux_rem_ln58_q[26:21], 
          mux_rem_ln58_q[14]};
        ctrlOr_ln59_0_z: mux_rem_ln58_14_d_0 = {add_ln153_0_z[27:22], 
          add_ln153_0_z[15]};
        ctrlOr_ln51_z: mux_rem_ln58_14_d_0 = {mux_rem_ln58_z[26:21], 
          mux_rem_ln58_z[14]};
        default: mux_rem_ln58_14_d_0 = 7'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln186_z: mux_rem_ln58_15_d_0 = mux_h_ln184_z[6:1];
        mux_rem_ln58_15_mux_0_sel: mux_rem_ln58_15_d_0 = mux_rem_ln58_q[20:15];
        ctrlOr_ln59_0_z: mux_rem_ln58_15_d_0 = add_ln153_0_z[21:16];
        ctrlOr_ln51_z: mux_rem_ln58_15_d_0 = mux_rem_ln58_z[20:15];
        default: mux_rem_ln58_15_d_0 = 6'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln768_z: memwrite_rbm_visible_unit_ln365_214_d_0 = {lt_ln766_z, 
          mult_ln781_z, add_ln766_z[8:1], mux_v_ln766_z[0]};
        memwrite_rbm_visible_unit_ln365_214_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_214_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[239:214];
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_214_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[239:214];
        default: memwrite_rbm_visible_unit_ln365_214_d_0 = 26'hX;
      endcase
      ctrlOr_ln766_z = ctrlAnd_0_ln768_z | ctrlAnd_1_ln766_z;
      data_bridge1_rtl_CE_en = ctrlAnd_1_ln794_z | ctrlAnd_1_ln768_z | 
      ctrlAnd_1_ln193_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_121_d_0 = 
          memwrite_rbm_visible_unit_ln365_z[139:121];
        memwrite_rbm_visible_unit_ln365_121_mux_0_sel: 
          memwrite_rbm_visible_unit_ln365_121_d_0 = 
          memwrite_rbm_visible_unit_ln365_q[139:121];
        ctrlAnd_1_ln794_z: memwrite_rbm_visible_unit_ln365_121_d_0 = {lt_ln792_z, 
          memread_rbm_visible_unit_ln806_z, mult_ln808_z, add_ln792_z[8]};
        default: memwrite_rbm_visible_unit_ln365_121_d_0 = 19'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: mux_rem_ln58_55_d_0 = {
          xor_ln165_z, xor_ln165_6_z, xor_ln165_9_z};
        ctrlOr_ln51_z: mux_rem_ln58_55_d_0 = mux_rem_ln58_z[62:55];
        ctrlAnd_1_ln794_z: mux_rem_ln58_55_d_0 = {add_ln792_z[7:1], 
          mux_v_ln792_z[0]};
        mux_rem_ln58_55_mux_0_sel: mux_rem_ln58_55_d_0 = mux_rem_ln58_q[62:55];
        default: mux_rem_ln58_55_d_0 = 8'hX;
      endcase
      ctrlOr_ln792_z = ctrlAnd_0_ln794_z | ctrlAnd_1_ln792_z;
      memwrite_rbm_visible_unit_ln369_sel = 
      state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[87] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[85] | ctrlOr_ln86_z | ctrlOr_ln86_0_z | 
      ctrlOr_ln803_z | ctrlOr_ln766_z | ctrlOr_ln753_z | ctrlOr_ln67_z | 
      ctrlOr_ln67_0_z | ctrlOr_ln62_z | ctrlOr_ln59_z | ctrlOr_ln51_z | 
      ctrlOr_ln328_z | ctrlOr_ln316_z | ctrlOr_ln290_z | ctrlOr_ln111_z | 
      ctrlOr_ln111_0_z | ctrlAnd_1_ln86_z | ctrlAnd_1_ln86_0_z | 
      ctrlAnd_1_ln794_z | ctrlAnd_1_ln777_z | ctrlAnd_1_ln768_z | 
      ctrlAnd_1_ln753_z | ctrlAnd_1_ln735_z | ctrlAnd_1_ln328_z | 
      ctrlAnd_1_ln316_z | ctrlAnd_1_ln296_z | ctrlAnd_1_ln290_z | 
      ctrlAnd_1_ln193_z | ctrlAnd_1_ln186_z | ctrlAnd_1_ln111_z | 
      ctrlAnd_1_ln111_0_z | ctrlAnd_0_ln803_z | ctrlAnd_0_ln772_z | 
      ctrlAnd_0_ln62_z | ctrlAnd_0_ln296_z | ctrlAnd_0_ln198_z | 
      ctrlAnd_0_ln186_z | state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[12] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[63] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[60] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[52] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[28] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[90] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[88] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      mux_user_ln745_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[87] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[85] | ctrlOr_ln86_z | ctrlOr_ln86_0_z | 
      ctrlOr_ln803_z | ctrlOr_ln766_z | ctrlOr_ln753_z | ctrlOr_ln67_z | 
      ctrlOr_ln67_0_z | ctrlOr_ln62_z | ctrlOr_ln62_0_z | ctrlOr_ln59_z | 
      ctrlOr_ln59_0_z | ctrlOr_ln51_z | ctrlOr_ln328_z | ctrlOr_ln316_z | 
      ctrlOr_ln290_z | ctrlOr_ln111_z | ctrlOr_ln111_0_z | ctrlAnd_1_ln86_z | 
      ctrlAnd_1_ln86_0_z | ctrlAnd_1_ln794_z | ctrlAnd_1_ln777_z | 
      ctrlAnd_1_ln768_z | ctrlAnd_1_ln753_z | ctrlAnd_1_ln51_z | 
      ctrlAnd_1_ln328_z | ctrlAnd_1_ln316_z | ctrlAnd_1_ln296_z | 
      ctrlAnd_1_ln290_z | ctrlAnd_1_ln284_z | ctrlAnd_1_ln193_z | 
      ctrlAnd_1_ln186_z | ctrlAnd_1_ln111_z | ctrlAnd_1_ln111_0_z | 
      ctrlAnd_0_ln803_z | ctrlAnd_0_ln772_z | ctrlAnd_0_ln62_z | 
      ctrlAnd_0_ln62_0_z | ctrlAnd_0_ln296_z | ctrlAnd_0_ln284_z | 
      ctrlAnd_0_ln198_z | ctrlAnd_0_ln186_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[12] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[63] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[60] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[52] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[28] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[90] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[88] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      ctrlOr_ln745_z = ctrlOr_ln792_z | state_rbm_0_cmos32soi_rbm_train_rbm[5];
      ctrlAnd_1_ln745_z = !lt_ln745_z & ctrlOr_ln745_z;
      ctrlAnd_0_ln745_z = lt_ln745_z & ctrlOr_ln745_z;
      ctrlOr_ln733_z = ctrlAnd_1_ln745_z | 
      state_rbm_0_cmos32soi_rbm_train_rbm[2];
      ctrlOr_ln750_z = ctrlAnd_0_ln750_z | ctrlAnd_0_ln745_z;
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln365_267_d = eq_ln735_z;
        ctrlOr_ln51_z: memwrite_rbm_visible_unit_ln365_267_d = 
          memwrite_rbm_visible_unit_ln365_z[267];
        ctrlAnd_1_ln51_z: memwrite_rbm_visible_unit_ln365_267_d = 
          memwrite_rbm_visible_unit_ln365_q[267];
        default: memwrite_rbm_visible_unit_ln365_267_d = 1'bX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln369_128_d_0 = 
          mux_visible_unit_ln733_z[191:128];
        memwrite_rbm_visible_unit_ln369_sel: 
          memwrite_rbm_visible_unit_ln369_128_d_0 = 
          memwrite_rbm_visible_unit_ln369_q[191:128];
        ctrlOr_ln750_z: memwrite_rbm_visible_unit_ln369_128_d_0 = 
          mux_mux_visible_unit_ln745_Z_128_v_0;
        ctrlAnd_1_ln284_z: memwrite_rbm_visible_unit_ln369_128_d_0 = 
          mux_visible_unit_ln282_z[191:128];
        ctrlAnd_0_ln62_0_z: memwrite_rbm_visible_unit_ln369_128_d_0 = 
          mux_visible_unit_ln356_z[191:128];
        ctrlOr_ln62_0_z: memwrite_rbm_visible_unit_ln369_128_d_0 = 
          mux_mux_visible_unit_ln356_Z_128_v_1;
        ctrlOr_ln59_0_z: memwrite_rbm_visible_unit_ln369_128_d_0 = 
          mux_mux_visible_unit_ln356_Z_128_mux_0_v;
        ctrlAnd_0_ln284_z: memwrite_rbm_visible_unit_ln369_128_d_0 = 
          memwrite_rbm_visible_unit_ln369_z[191:128];
        default: memwrite_rbm_visible_unit_ln369_128_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln369_192_d_0 = 
          mux_visible_unit_ln733_z[255:192];
        memwrite_rbm_visible_unit_ln369_sel: 
          memwrite_rbm_visible_unit_ln369_192_d_0 = 
          memwrite_rbm_visible_unit_ln369_q[255:192];
        ctrlOr_ln750_z: memwrite_rbm_visible_unit_ln369_192_d_0 = 
          mux_mux_visible_unit_ln745_Z_192_v_0;
        ctrlAnd_1_ln284_z: memwrite_rbm_visible_unit_ln369_192_d_0 = 
          mux_visible_unit_ln282_z[255:192];
        ctrlAnd_0_ln62_0_z: memwrite_rbm_visible_unit_ln369_192_d_0 = 
          mux_visible_unit_ln356_z[255:192];
        ctrlOr_ln62_0_z: memwrite_rbm_visible_unit_ln369_192_d_0 = 
          mux_mux_visible_unit_ln356_Z_192_v_1;
        ctrlOr_ln59_0_z: memwrite_rbm_visible_unit_ln369_192_d_0 = 
          mux_mux_visible_unit_ln356_Z_192_mux_0_v;
        ctrlAnd_0_ln284_z: memwrite_rbm_visible_unit_ln369_192_d_0 = 
          memwrite_rbm_visible_unit_ln369_z[255:192];
        default: memwrite_rbm_visible_unit_ln369_192_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln369_256_d_0 = 
          mux_visible_unit_ln733_z[319:256];
        memwrite_rbm_visible_unit_ln369_sel: 
          memwrite_rbm_visible_unit_ln369_256_d_0 = 
          memwrite_rbm_visible_unit_ln369_q[319:256];
        ctrlOr_ln750_z: memwrite_rbm_visible_unit_ln369_256_d_0 = 
          mux_mux_visible_unit_ln745_Z_256_v_0;
        ctrlAnd_1_ln284_z: memwrite_rbm_visible_unit_ln369_256_d_0 = 
          mux_visible_unit_ln282_z[319:256];
        ctrlAnd_0_ln62_0_z: memwrite_rbm_visible_unit_ln369_256_d_0 = 
          mux_visible_unit_ln356_z[319:256];
        ctrlOr_ln62_0_z: memwrite_rbm_visible_unit_ln369_256_d_0 = 
          mux_mux_visible_unit_ln356_Z_256_v_1;
        ctrlOr_ln59_0_z: memwrite_rbm_visible_unit_ln369_256_d_0 = 
          mux_mux_visible_unit_ln356_Z_256_mux_0_v;
        ctrlAnd_0_ln284_z: memwrite_rbm_visible_unit_ln369_256_d_0 = 
          memwrite_rbm_visible_unit_ln369_z[319:256];
        default: memwrite_rbm_visible_unit_ln369_256_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln369_320_d_0 = 
          mux_visible_unit_ln733_z[383:320];
        memwrite_rbm_visible_unit_ln369_sel: 
          memwrite_rbm_visible_unit_ln369_320_d_0 = 
          memwrite_rbm_visible_unit_ln369_q[383:320];
        ctrlOr_ln750_z: memwrite_rbm_visible_unit_ln369_320_d_0 = 
          mux_mux_visible_unit_ln745_Z_320_v_0;
        ctrlAnd_1_ln284_z: memwrite_rbm_visible_unit_ln369_320_d_0 = 
          mux_visible_unit_ln282_z[383:320];
        ctrlAnd_0_ln62_0_z: memwrite_rbm_visible_unit_ln369_320_d_0 = 
          mux_visible_unit_ln356_z[383:320];
        ctrlOr_ln62_0_z: memwrite_rbm_visible_unit_ln369_320_d_0 = 
          mux_mux_visible_unit_ln356_Z_320_v_1;
        ctrlOr_ln59_0_z: memwrite_rbm_visible_unit_ln369_320_d_0 = 
          mux_mux_visible_unit_ln356_Z_320_mux_0_v;
        ctrlAnd_0_ln284_z: memwrite_rbm_visible_unit_ln369_320_d_0 = 
          memwrite_rbm_visible_unit_ln369_z[383:320];
        default: memwrite_rbm_visible_unit_ln369_320_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln369_384_d_0 = 
          mux_visible_unit_ln733_z[447:384];
        memwrite_rbm_visible_unit_ln369_sel: 
          memwrite_rbm_visible_unit_ln369_384_d_0 = 
          memwrite_rbm_visible_unit_ln369_q[447:384];
        ctrlOr_ln750_z: memwrite_rbm_visible_unit_ln369_384_d_0 = 
          mux_mux_visible_unit_ln745_Z_384_v_0;
        ctrlAnd_1_ln284_z: memwrite_rbm_visible_unit_ln369_384_d_0 = 
          mux_visible_unit_ln282_z[447:384];
        ctrlAnd_0_ln62_0_z: memwrite_rbm_visible_unit_ln369_384_d_0 = 
          mux_visible_unit_ln356_z[447:384];
        ctrlOr_ln62_0_z: memwrite_rbm_visible_unit_ln369_384_d_0 = 
          mux_mux_visible_unit_ln356_Z_384_v_1;
        ctrlOr_ln59_0_z: memwrite_rbm_visible_unit_ln369_384_d_0 = 
          mux_mux_visible_unit_ln356_Z_384_mux_0_v;
        ctrlAnd_0_ln284_z: memwrite_rbm_visible_unit_ln369_384_d_0 = 
          memwrite_rbm_visible_unit_ln369_z[447:384];
        default: memwrite_rbm_visible_unit_ln369_384_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln369_448_d_0 = 
          mux_visible_unit_ln733_z[500:448];
        memwrite_rbm_visible_unit_ln369_sel: 
          memwrite_rbm_visible_unit_ln369_448_d_0 = 
          memwrite_rbm_visible_unit_ln369_q[500:448];
        ctrlOr_ln750_z: memwrite_rbm_visible_unit_ln369_448_d_0 = 
          mux_mux_visible_unit_ln745_Z_448_v_0;
        ctrlAnd_1_ln284_z: memwrite_rbm_visible_unit_ln369_448_d_0 = 
          mux_visible_unit_ln282_z[500:448];
        ctrlAnd_0_ln62_0_z: memwrite_rbm_visible_unit_ln369_448_d_0 = 
          mux_visible_unit_ln356_z[500:448];
        ctrlOr_ln62_0_z: memwrite_rbm_visible_unit_ln369_448_d_0 = 
          mux_mux_visible_unit_ln356_Z_448_v_1;
        ctrlOr_ln59_0_z: memwrite_rbm_visible_unit_ln369_448_d_0 = 
          mux_mux_visible_unit_ln356_Z_448_mux_0_v;
        ctrlAnd_0_ln284_z: memwrite_rbm_visible_unit_ln369_448_d_0 = 
          memwrite_rbm_visible_unit_ln369_z[500:448];
        default: memwrite_rbm_visible_unit_ln369_448_d_0 = 53'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln369_64_d_0 = 
          mux_visible_unit_ln733_z[127:64];
        memwrite_rbm_visible_unit_ln369_sel: 
          memwrite_rbm_visible_unit_ln369_64_d_0 = 
          memwrite_rbm_visible_unit_ln369_q[127:64];
        ctrlOr_ln750_z: memwrite_rbm_visible_unit_ln369_64_d_0 = 
          mux_mux_visible_unit_ln745_Z_64_v_0;
        ctrlAnd_1_ln284_z: memwrite_rbm_visible_unit_ln369_64_d_0 = 
          mux_visible_unit_ln282_z[127:64];
        ctrlAnd_0_ln62_0_z: memwrite_rbm_visible_unit_ln369_64_d_0 = 
          mux_visible_unit_ln356_z[127:64];
        ctrlOr_ln62_0_z: memwrite_rbm_visible_unit_ln369_64_d_0 = 
          mux_mux_visible_unit_ln356_Z_64_v_1;
        ctrlOr_ln59_0_z: memwrite_rbm_visible_unit_ln369_64_d_0 = 
          mux_mux_visible_unit_ln356_Z_64_mux_0_v;
        ctrlAnd_0_ln284_z: memwrite_rbm_visible_unit_ln369_64_d_0 = 
          memwrite_rbm_visible_unit_ln369_z[127:64];
        default: memwrite_rbm_visible_unit_ln369_64_d_0 = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: memwrite_rbm_visible_unit_ln369_d = 
          mux_visible_unit_ln733_z[63:0];
        memwrite_rbm_visible_unit_ln369_sel: memwrite_rbm_visible_unit_ln369_d = 
          memwrite_rbm_visible_unit_ln369_q[63:0];
        ctrlOr_ln750_z: memwrite_rbm_visible_unit_ln369_d = 
          mux_mux_visible_unit_ln745_Z_v;
        ctrlAnd_1_ln284_z: memwrite_rbm_visible_unit_ln369_d = 
          mux_visible_unit_ln282_z[63:0];
        ctrlAnd_0_ln62_0_z: memwrite_rbm_visible_unit_ln369_d = 
          mux_visible_unit_ln356_z[63:0];
        ctrlOr_ln62_0_z: memwrite_rbm_visible_unit_ln369_d = 
          mux_mux_visible_unit_ln356_Z_v;
        ctrlOr_ln59_0_z: memwrite_rbm_visible_unit_ln369_d = 
          mux_mux_visible_unit_ln356_Z_0_mux_0_v;
        ctrlAnd_0_ln284_z: memwrite_rbm_visible_unit_ln369_d = 
          memwrite_rbm_visible_unit_ln369_z[63:0];
        default: memwrite_rbm_visible_unit_ln369_d = 64'hX;
      endcase
      mux_current_loop_ln733_mux_0_sel = state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[87] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[85] | ctrlOr_ln86_z | ctrlOr_ln86_0_z | 
      ctrlOr_ln803_z | ctrlOr_ln766_z | ctrlOr_ln753_z | ctrlOr_ln750_z | 
      ctrlOr_ln67_z | ctrlOr_ln67_0_z | ctrlOr_ln62_z | ctrlOr_ln62_0_z | 
      ctrlOr_ln59_z | ctrlOr_ln59_0_z | ctrlOr_ln51_z | ctrlOr_ln328_z | 
      ctrlOr_ln316_z | ctrlOr_ln290_z | ctrlOr_ln111_z | ctrlOr_ln111_0_z | 
      ctrlAnd_1_ln86_z | ctrlAnd_1_ln86_0_z | ctrlAnd_1_ln794_z | 
      ctrlAnd_1_ln777_z | ctrlAnd_1_ln768_z | ctrlAnd_1_ln753_z | 
      ctrlAnd_1_ln735_z | ctrlAnd_1_ln51_z | ctrlAnd_1_ln328_z | 
      ctrlAnd_1_ln316_z | ctrlAnd_1_ln296_z | ctrlAnd_1_ln290_z | 
      ctrlAnd_1_ln284_z | ctrlAnd_1_ln193_z | ctrlAnd_1_ln186_z | 
      ctrlAnd_1_ln111_z | ctrlAnd_1_ln111_0_z | ctrlAnd_0_ln803_z | 
      ctrlAnd_0_ln772_z | ctrlAnd_0_ln62_z | ctrlAnd_0_ln62_0_z | 
      ctrlAnd_0_ln296_z | ctrlAnd_0_ln284_z | ctrlAnd_0_ln198_z | 
      ctrlAnd_0_ln186_z | state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[12] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[63] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[60] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[52] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[28] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[90] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[88] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln750_z: mux_user_ln745_d_0 = {mux_mult_ln195_Z_v, 
          mux_add_ln745_Z_1_v_0, mux_mux_user_ln745_Z_0_v};
        mux_user_ln745_mux_0_sel: mux_user_ln745_d_0 = {mult_ln195_q, 
          add_ln745_1_q, mux_user_ln745_q};
        default: mux_user_ln745_d_0 = 42'hX;
      endcase
      read_rbm_num_visible_ln687_sel = state_rbm_0_cmos32soi_rbm_train_rbm[17] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[15] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[56] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[87] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[85] | ctrlOr_ln86_z | ctrlOr_ln86_0_z | 
      ctrlOr_ln803_z | ctrlOr_ln766_z | ctrlOr_ln753_z | ctrlOr_ln750_z | 
      ctrlOr_ln733_z | ctrlOr_ln711_0_z | ctrlOr_ln706_z | ctrlOr_ln67_z | 
      ctrlOr_ln67_0_z | ctrlOr_ln62_z | ctrlOr_ln62_0_z | ctrlOr_ln59_z | 
      ctrlOr_ln59_0_z | ctrlOr_ln51_z | ctrlOr_ln328_z | ctrlOr_ln316_z | 
      ctrlOr_ln290_z | ctrlOr_ln111_z | ctrlOr_ln111_0_z | ctrlAnd_1_ln86_z | 
      ctrlAnd_1_ln86_0_z | ctrlAnd_1_ln794_z | ctrlAnd_1_ln777_z | 
      ctrlAnd_1_ln768_z | ctrlAnd_1_ln753_z | ctrlAnd_1_ln735_z | 
      ctrlAnd_1_ln708_z | ctrlAnd_1_ln51_z | ctrlAnd_1_ln328_z | 
      ctrlAnd_1_ln316_z | ctrlAnd_1_ln296_z | ctrlAnd_1_ln290_z | 
      ctrlAnd_1_ln284_z | ctrlAnd_1_ln193_z | ctrlAnd_1_ln186_z | 
      ctrlAnd_1_ln111_z | ctrlAnd_1_ln111_0_z | ctrlAnd_0_ln803_z | 
      ctrlAnd_0_ln772_z | ctrlAnd_0_ln62_z | ctrlAnd_0_ln62_0_z | 
      ctrlAnd_0_ln296_z | ctrlAnd_0_ln284_z | ctrlAnd_0_ln198_z | 
      ctrlAnd_0_ln186_z | state_rbm_0_cmos32soi_rbm_train_rbm[73] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[38] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[72] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[37] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[71] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[36] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[18] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[68] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[33] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[14] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[12] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[63] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[60] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[67] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[32] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[52] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[28] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[25] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[24] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[58] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[57] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[90] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[88] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[51] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[84] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[49] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[83] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[48] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[82] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[47] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[80] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[45] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[79] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[44] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[78] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[43] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[77] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[42] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[74] | 
      state_rbm_0_cmos32soi_rbm_train_rbm[39];
      case (1'b1)// synopsys parallel_case
        ctrlOr_ln733_z: mux_current_loop_ln733_d_0 = {and_ln757_z, add_ln836_z[
          31:1], mux_current_loop_ln733_z[0]};
        mux_current_loop_ln733_mux_0_sel: mux_current_loop_ln733_d_0 = {
          and_ln757_q, add_ln836_1_q, mux_current_loop_ln733_q};
        default: mux_current_loop_ln733_d_0 = 33'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln684_z: read_rbm_num_visible_ln687_d = {num_loops, num_users, 
          num_hidden, num_visible};
        read_rbm_num_visible_ln687_sel: read_rbm_num_visible_ln687_d = {
          read_rbm_num_loops_ln690_q, read_rbm_num_users_ln689_q, 
          read_rbm_num_hidden_ln688_q, read_rbm_num_visible_ln687_q};
        default: read_rbm_num_visible_ln687_d = 64'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ctrlAnd_1_ln684_z: add_ln708_1_d = {add_ln713_z[16:1], add_ln708_z[16:1]};
        read_rbm_num_visible_ln687_sel: add_ln708_1_d = {add_ln713_1_q, 
          add_ln708_1_q};
        default: add_ln708_1_d = 32'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        state_rbm_0_cmos32soi_rbm_train_rbm[0]: // Wait_ln684
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln684_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[0] = 
                1'b1;
              ctrlAnd_1_ln684_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[1] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[1]: // expand_ln706
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln706_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[2] = 1'b1;
              ctrlAnd_1_ln708_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[93] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[2]: // expand_ln733
          state_rbm_0_cmos32soi_rbm_train_rbm_next[3] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[3]: // expand_ln735
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln740_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[4] = 1'b1;
              ctrlAnd_1_ln735_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[5] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[4]: // Wait_ln740
          state_rbm_0_cmos32soi_rbm_train_rbm_next[4] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[5]: // expand_ln745
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln750_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[6] = 1'b1;
              ctrlOr_ln733_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[3] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[6]: // Wait_ln750
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln750_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[6] = 1'b1;
              ctrlOr_ln753_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[7] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[7]: // Wait_ln753
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln753_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[7] = 1'b1;
              ctrlAnd_1_ln753_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[8] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[8]: // expand_ln184
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln186_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[9] = 
                1'b1;
              ctrlAnd_1_ln186_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[65] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[9]: // Wait_ln220
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln766_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[10] = 
                1'b1;
              ctrlAnd_1_ln768_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[60] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[10]: // expand_ln282
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln284_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[11] = 
                1'b1;
              ctrlAnd_1_ln284_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[20] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[11]: // Wait_ln370
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln750_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[6] = 1'b1;
              ctrlOr_ln733_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[3] = 1'b1;
              ctrlAnd_1_ln794_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[12] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[12]: // Wait_ln797
          state_rbm_0_cmos32soi_rbm_train_rbm_next[13] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[13]: // expand_ln799
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln750_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[6] = 1'b1;
              ctrlOr_ln733_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[3] = 1'b1;
              ctrlAnd_1_ln794_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[12] = 
                1'b1;
              ctrlAnd_0_ln803_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[14] = 
                1'b1;
              ctrlOr_ln803_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[17] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[14]: // Wait_ln807
          state_rbm_0_cmos32soi_rbm_train_rbm_next[15] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[15]: // expand_ln809
          state_rbm_0_cmos32soi_rbm_train_rbm_next[16] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[16]: // Wait_ln809
          state_rbm_0_cmos32soi_rbm_train_rbm_next[17] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[17]: // expand_ln814
          state_rbm_0_cmos32soi_rbm_train_rbm_next[18] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[18]: // Wait_ln814
          state_rbm_0_cmos32soi_rbm_train_rbm_next[19] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[19]: // Wait_ln831
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln750_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[6] = 1'b1;
              ctrlOr_ln733_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[3] = 1'b1;
              ctrlAnd_1_ln794_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[12] = 
                1'b1;
              ctrlAnd_0_ln803_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[14] = 
                1'b1;
              ctrlOr_ln803_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[17] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[20]: // expand_ln290
          state_rbm_0_cmos32soi_rbm_train_rbm_next[21] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[21]: // expand_ln294
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln296_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[22] = 
                1'b1;
              ctrlAnd_1_ln296_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[56] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[22]: // Wait_ln309
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln290_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[21] = 
                1'b1;
              ctrlAnd_1_ln290_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[23] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[23]: // expand_ln316
          state_rbm_0_cmos32soi_rbm_train_rbm_next[24] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[24]: // Wait_ln319
          state_rbm_0_cmos32soi_rbm_train_rbm_next[25] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[25]: // Wait_ln321
          state_rbm_0_cmos32soi_rbm_train_rbm_next[26] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[26]: // Wait_ln323
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln316_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[24] = 
                1'b1;
              ctrlAnd_1_ln316_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[27] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[27]: // expand_ln328
          state_rbm_0_cmos32soi_rbm_train_rbm_next[28] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[28]: // Wait_ln332
          state_rbm_0_cmos32soi_rbm_train_rbm_next[29] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[29]: // expand_ln328_0
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln328_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[28] = 
                1'b1;
              ctrlAnd_1_ln328_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[30] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[30]: // expand_ln356
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln62_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[31] = 
                1'b1;
              ctrlOr_ln59_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[51] = 
                1'b1;
              ctrlOr_ln62_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[35] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[31]: // Wait_ln65_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[32] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[32]: // Wait_ln71_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[33] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[33]: // Wait_ln80_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[34] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[34]: // expand_ln67_2
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln67_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[32] = 
                1'b1;
              ctrlOr_ln62_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[35] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[35]: // expand_ln86_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[36] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[36]: // Wait_ln90_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[37] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[37]: // Wait_ln94_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[38] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[38]: // Wait_ln98_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[39] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[39]: // Wait_ln106_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[40] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[40]: // expand_ln86_4
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln86_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[36] = 
                1'b1;
              ctrlAnd_1_ln86_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[41] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[41]: // expand_ln111_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[42] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[42]: // Wait_ln115_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[43] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[43]: // Wait_ln119_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[44] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[44]: // Wait_ln123_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[45] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[45]: // Wait_ln130_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[46] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[46]: // expand_ln111_4
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln111_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[42] = 
                1'b1;
              ctrlAnd_1_ln111_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[47] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[47]: // Wait_ln133_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[48] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[48]: // Wait_ln135_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[49] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[49]: // Wait_ln137_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[50] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[50]: // Wait_ln147_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[51] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[51]: // Wait_ln152_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[52] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[52]: // Wait_ln360
          state_rbm_0_cmos32soi_rbm_train_rbm_next[53] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[53]: // expand_ln51_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[54] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[54]: // expand_ln51
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln51_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[54] = 1'b1;
              ctrlAnd_1_ln51_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[55] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[55]: // Wait_ln366
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln62_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[31] = 
                1'b1;
              ctrlOr_ln59_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[51] = 
                1'b1;
              ctrlOr_ln62_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[35] = 
                1'b1;
              ctrlAnd_0_ln284_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[11] = 
                1'b1;
              ctrlAnd_1_ln284_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[20] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[56]: // expand_ln299
          state_rbm_0_cmos32soi_rbm_train_rbm_next[57] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[57]: // Wait_ln299
          state_rbm_0_cmos32soi_rbm_train_rbm_next[58] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[58]: // Wait_ln301
          state_rbm_0_cmos32soi_rbm_train_rbm_next[59] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[59]: // Wait_ln306
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln296_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[22] = 
                1'b1;
              ctrlAnd_1_ln296_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[56] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[60]: // Wait_ln771
          state_rbm_0_cmos32soi_rbm_train_rbm_next[61] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[61]: // expand_ln772
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln772_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[62] = 
                1'b1;
              ctrlOr_ln766_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[10] = 
                1'b1;
              ctrlAnd_1_ln768_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[60] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[62]: // expand_ln775
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln766_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[10] = 
                1'b1;
              ctrlAnd_1_ln768_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[60] = 
                1'b1;
              ctrlAnd_1_ln777_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[63] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[63]: // Wait_ln780
          state_rbm_0_cmos32soi_rbm_train_rbm_next[64] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[64]: // Wait_ln782
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln766_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[10] = 
                1'b1;
              ctrlAnd_1_ln768_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[60] = 
                1'b1;
              ctrlAnd_1_ln777_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[63] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[65]: // expand_ln191 // activate hidden: for (v = 0; v < NUM_VISIBLE_MAX + 1; v++) 
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln62_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[66] = 
                1'b1;                                                             // goto rand_gen()
              ctrlOr_ln59_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[87] = 1'b1; //
              ctrlOr_ln62_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[70] = 1'b1;
              ctrlAnd_1_ln193_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[90] = 
                1'b1; // do the load and 
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[66]: // Wait_ln65  // START of ** rand_gen()
          state_rbm_0_cmos32soi_rbm_train_rbm_next[67] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[67]: // Wait_ln71
          state_rbm_0_cmos32soi_rbm_train_rbm_next[68] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[68]: // Wait_ln80
          state_rbm_0_cmos32soi_rbm_train_rbm_next[69] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[69]: // expand_ln67_1
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln67_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[67] = 1'b1;
              ctrlOr_ln62_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[70] = 1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[70]: // expand_ln86
          state_rbm_0_cmos32soi_rbm_train_rbm_next[71] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[71]: // Wait_ln90
          state_rbm_0_cmos32soi_rbm_train_rbm_next[72] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[72]: // Wait_ln94
          state_rbm_0_cmos32soi_rbm_train_rbm_next[73] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[73]: // Wait_ln98
          state_rbm_0_cmos32soi_rbm_train_rbm_next[74] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[74]: // Wait_ln106
          state_rbm_0_cmos32soi_rbm_train_rbm_next[75] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[75]: // expand_ln86_1
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln86_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[71] = 1'b1;
              ctrlAnd_1_ln86_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[76] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[76]: // expand_ln111
          state_rbm_0_cmos32soi_rbm_train_rbm_next[77] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[77]: // Wait_ln115
          state_rbm_0_cmos32soi_rbm_train_rbm_next[78] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[78]: // Wait_ln119
          state_rbm_0_cmos32soi_rbm_train_rbm_next[79] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[79]: // Wait_ln123
          state_rbm_0_cmos32soi_rbm_train_rbm_next[80] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[80]: // Wait_ln130
          state_rbm_0_cmos32soi_rbm_train_rbm_next[81] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[81]: // expand_ln111_1
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln111_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[77] = 
                1'b1;
              ctrlAnd_1_ln111_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[82] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[82]: // Wait_ln133
          state_rbm_0_cmos32soi_rbm_train_rbm_next[83] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[83]: // Wait_ln135
          state_rbm_0_cmos32soi_rbm_train_rbm_next[84] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[84]: // Wait_ln137
          state_rbm_0_cmos32soi_rbm_train_rbm_next[85] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[85]: // expand_ln147_0
          state_rbm_0_cmos32soi_rbm_train_rbm_next[86] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[86]: // Wait_ln147
          state_rbm_0_cmos32soi_rbm_train_rbm_next[87] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[87]: // expand_ln152
          state_rbm_0_cmos32soi_rbm_train_rbm_next[88] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[88]: // Wait_ln152         **END of rand_gen() **
          state_rbm_0_cmos32soi_rbm_train_rbm_next[89] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[89]: // Wait_ln216
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln186_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[9] = 
                1'b1;                                                   // wait: end of train_aH
              ctrlAnd_1_ln186_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[65] =  
                1'b1;                                                   // Line 65: inner:V for (v = 0; v < NUM_VISIBLE_MAX + 1; v++) 
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[90]: // Wait_ln197      
          state_rbm_0_cmos32soi_rbm_train_rbm_next[91] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[91]: // expand_ln198
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln198_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[92] = 
                1'b1;
              ctrlAnd_0_ln62_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[66] = 
                1'b1;
              ctrlOr_ln59_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[87] = 1'b1;
              ctrlOr_ln62_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[70] = 1'b1;
              ctrlAnd_1_ln193_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[90] = 
                1'b1; // if not reached then goto 90
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[92]: // Wait_ln202
          begin
            case (1'b1)// synopsys parallel_case
              ctrlAnd_0_ln62_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[66] = 
                1'b1;
              ctrlOr_ln59_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[87] = 1'b1;
              ctrlOr_ln62_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[70] = 1'b1;
              ctrlAnd_1_ln193_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[90] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        state_rbm_0_cmos32soi_rbm_train_rbm[93]: // expand_ln711
          state_rbm_0_cmos32soi_rbm_train_rbm_next[94] = 1'b1;
        state_rbm_0_cmos32soi_rbm_train_rbm[94]: // expand_ln713
          begin
            case (1'b1)// synopsys parallel_case
              ctrlOr_ln706_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[2] = 1'b1;
              ctrlAnd_1_ln708_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[93] = 
                1'b1;
              ctrlOr_ln711_0_z: state_rbm_0_cmos32soi_rbm_train_rbm_next[94] = 
                1'b1;
              default: state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
            endcase
          end
        default: // Don't care
          state_rbm_0_cmos32soi_rbm_train_rbm_next = 95'hX;
      endcase
    end
endmodule


module rbm_0_cmos32soi_rbm_data_out_can_put_mod_process(data_out_valid, 
data_out_ready, data_out_can_put_sig);
  input data_out_valid;
  input data_out_ready;
  output reg data_out_can_put_sig;

  always @(*) begin : rbm_0_cmos32soi_rbm_data_out_can_put_mod_process_combinational
      reg unary_nor_ln35_z;
      reg ternaryMux_ln35_0_z;

      unary_nor_ln35_z = ~data_out_ready;
      ternaryMux_ln35_0_z = ~(data_out_valid & unary_nor_ln35_z);
      data_out_can_put_sig = ternaryMux_ln35_0_z;
    end
endmodule


module rbm_0_cmos32soi_rbm_data_out_sync_snd_back_method(clk, rst, 
data_out_ready, data_out_valid, data_out_set_valid_curr, 
data_out_sync_snd_set_valid_prev, data_out_sync_snd_reset_valid_prev, 
data_out_sync_snd_reset_valid_curr, data_out_sync_snd_valid_flop);
  input clk;
  input rst;
  input data_out_ready;
  input data_out_valid;
  input data_out_set_valid_curr;
  output reg data_out_sync_snd_set_valid_prev;
  output reg data_out_sync_snd_reset_valid_prev;
  output reg data_out_sync_snd_reset_valid_curr;
  output reg data_out_sync_snd_valid_flop;
  reg data_out_sync_snd_reset_valid_prev_d;
  reg data_out_sync_snd_set_valid_prev_d;
  reg data_out_sync_snd_valid_flop_d;
  reg data_out_sync_snd_reset_valid_curr_d;

  // synopsys async_set_reset_local rbm_0_cmos32soi_rbm_data_out_sync_snd_back_method_seq_block rst
  always @(posedge clk ) // rbm_0_cmos32soi_rbm_data_out_sync_snd_back_method_sequential
    begin : rbm_0_cmos32soi_rbm_data_out_sync_snd_back_method_seq_block
      if (!rst) // Initialize state and outputs
      begin
        data_out_sync_snd_reset_valid_prev <= 1'b0;
        data_out_sync_snd_set_valid_prev <= 1'b0;
        data_out_sync_snd_valid_flop <= 1'b0;
        data_out_sync_snd_reset_valid_curr <= 1'b0;
      end
      else // Update Q values
      begin
        data_out_sync_snd_reset_valid_prev <= 
        data_out_sync_snd_reset_valid_prev_d;
        data_out_sync_snd_set_valid_prev <= data_out_sync_snd_set_valid_prev_d;
        data_out_sync_snd_valid_flop <= data_out_sync_snd_valid_flop_d;
        data_out_sync_snd_reset_valid_curr <= 
        data_out_sync_snd_reset_valid_curr_d;
      end
    end
  always @(*) begin : rbm_0_cmos32soi_rbm_data_out_sync_snd_back_method_combinational
      reg unary_nor_ln72_z;

      unary_nor_ln72_z = ~data_out_sync_snd_reset_valid_curr;
      data_out_sync_snd_reset_valid_prev_d = data_out_sync_snd_reset_valid_curr;
      data_out_sync_snd_set_valid_prev_d = data_out_set_valid_curr;
      data_out_sync_snd_valid_flop_d = data_out_valid;
      if (data_out_ready) 
        data_out_sync_snd_reset_valid_curr_d = unary_nor_ln72_z;
      else 
        data_out_sync_snd_reset_valid_curr_d = 
        data_out_sync_snd_reset_valid_curr;
    end
endmodule


module rbm_0_cmos32soi_rbm_data_out_sync_snd_valid_arb(data_out_set_valid_curr, 
data_out_sync_snd_set_valid_prev, data_out_sync_snd_reset_valid_curr, 
data_out_sync_snd_reset_valid_prev, data_out_sync_snd_valid_flop, data_out_valid);
  input data_out_set_valid_curr;
  input data_out_sync_snd_set_valid_prev;
  input data_out_sync_snd_reset_valid_curr;
  input data_out_sync_snd_reset_valid_prev;
  input data_out_sync_snd_valid_flop;
  output reg data_out_valid;

  always @(*) begin : rbm_0_cmos32soi_rbm_data_out_sync_snd_valid_arb_combinational
      reg ne_ln93_z;
      reg ne_ln95_z;
      reg mux_b_ln95_0_z;
      reg mux_b_ln93_0_z;

      ne_ln93_z = data_out_sync_snd_set_valid_prev ^ data_out_set_valid_curr;
      ne_ln95_z = ~(data_out_sync_snd_reset_valid_prev ^ 
      data_out_sync_snd_reset_valid_curr);
      mux_b_ln95_0_z = ne_ln95_z & data_out_sync_snd_valid_flop;
      mux_b_ln93_0_z = ne_ln93_z | mux_b_ln95_0_z;
      data_out_valid = mux_b_ln93_0_z;
    end
endmodule


module rbm_0_cmos32soi_sigmoid_0(sum_in, sigmoid_out);
  input [15:0] sum_in;
  output reg [6:0] sigmoid_out;

  always @(*) begin : rbm_0_cmos32soi_sigmoid_0_combinational
      reg [5:0] add_ln281_z;
      reg [5:0] add_ln281_0_z;
      reg [3:0] add_ln281_1_z;
      reg [1:0] add_ln281_3_z;
      reg ge_ln890_z;
      reg ge_ln890_0_0_z;
      reg ge_ln890_1_z;
      reg gt_ln842_z;
      reg le_ln794_1_0_z;
      reg le_ln794_z;
      reg lt_ln746_z;
      reg lt_ln746_0_z;
      reg le_ln794_0_0_z;
      reg xor_ln281_2_z;
      reg ge_ln890_0_z;
      reg ternaryMux_ln29_0_z;
      reg gt_ln842_0_z;
      reg and_if_ln22_z;
      reg ternaryMux_ln24_0_z;
      reg ternaryMux_ln34_0_z;
      reg ternaryMux_ln39_0_z;
      reg [2:0] case_mux_prob_ln24_z;
      reg [2:0] case_mux_prob_ln34_z;
      reg and_case_mux_prob_ln24_1_0_z;
      reg and_case_mux_prob_ln24_2_z;
      reg and_case_mux_prob_ln24_0_0_z;
      reg [4:0] mux_prob_ln34_z;
      reg [6:0] mux_prob_ln20_z;

      add_ln281_z = sum_in[6:1] + 6'h1b;
      add_ln281_0_z = sum_in[6:1] + 6'h5;
      add_ln281_1_z = sum_in[4:1] + 4'h5;
      add_ln281_3_z = sum_in[3:2] + 2'h1;
      ge_ln890_z = $signed(sum_in[15:1]) > $signed(4'h4);
      ge_ln890_0_0_z = ~|sum_in[14:1];
      ge_ln890_1_z = $signed(sum_in) > $signed(4'h4);
      gt_ln842_z = $signed(sum_in) > $signed(5'h16);
      le_ln794_1_0_z = ~&sum_in[14:2];
      le_ln794_z = $signed(sum_in) > $signed(5'h16);
      lt_ln746_z = $signed(sum_in[15:1]) > $signed(4'h4);
      lt_ln746_0_z = $signed(sum_in) > $signed(4'h4);
      le_ln794_0_0_z = ~&sum_in[14:0];
      xor_ln281_2_z = ~sum_in[1];
      ge_ln890_0_z = ~(sum_in[15] | ge_ln890_0_0_z);
      ternaryMux_ln29_0_z = sum_in[15] & le_ln794_1_0_z & gt_ln842_z;
      gt_ln842_0_z = sum_in[15] & le_ln794_1_0_z;
      and_if_ln22_z = !ge_ln890_z & !le_ln794_z;
      ternaryMux_ln24_0_z = !lt_ln746_z & ge_ln890_1_z;
      ternaryMux_ln34_0_z = !lt_ln746_0_z & ge_ln890_0_z;
      ternaryMux_ln39_0_z = sum_in[15] & le_ln794_0_0_z & !gt_ln842_0_z;
      case (1'b1)
        ternaryMux_ln24_0_z: case_mux_prob_ln24_z = 3'h1;
        ternaryMux_ln29_0_z: case_mux_prob_ln24_z = 3'h2;
        default: case_mux_prob_ln24_z = 3'h4;
      endcase
      case (1'b1)
        ternaryMux_ln34_0_z: case_mux_prob_ln34_z = 3'h1;
        ternaryMux_ln39_0_z: case_mux_prob_ln34_z = 3'h2;
        default: case_mux_prob_ln34_z = 3'h4;
      endcase
      and_case_mux_prob_ln24_1_0_z = !(!le_ln794_z) & case_mux_prob_ln24_z[2] & 
      !ge_ln890_z;
      and_case_mux_prob_ln24_2_z = !(!le_ln794_z) & case_mux_prob_ln24_z[0] & !
      ge_ln890_z;
      and_case_mux_prob_ln24_0_0_z = !(!le_ln794_z) & case_mux_prob_ln24_z[1] & 
      !ge_ln890_z;
      case (1'b1)// synopsys parallel_case
        case_mux_prob_ln34_z[0]: mux_prob_ln34_z = {add_ln281_1_z, sum_in[0]};
        case_mux_prob_ln34_z[1]: mux_prob_ln34_z = {2'h0, sum_in[1], 
          xor_ln281_2_z, sum_in[0]};
        case_mux_prob_ln34_z[2]: mux_prob_ln34_z = {add_ln281_3_z, sum_in[1:0], 
          1'b0};
        default: mux_prob_ln34_z = 5'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ge_ln890_z: mux_prob_ln20_z = 7'h40;
        and_if_ln22_z: mux_prob_ln20_z = 7'h0;
        and_case_mux_prob_ln24_2_z: mux_prob_ln20_z = {add_ln281_z, sum_in[0]};
        and_case_mux_prob_ln24_0_0_z: mux_prob_ln20_z = {add_ln281_0_z, sum_in[0]};
        and_case_mux_prob_ln24_1_0_z: mux_prob_ln20_z = {mux_prob_ln34_z, 2'h0};
        default: mux_prob_ln20_z = 7'hX;
      endcase
      sigmoid_out = mux_prob_ln20_z;
    end
endmodule


module rbm_0_cmos32soi_round_(num_in, round__out);
  input [3:0] num_in;
  output reg [3:0] round__out;

  always @(*) begin : rbm_0_cmos32soi_round__combinational
      reg [3:0] add_ln11_z;
      reg [3:0] mux_round__ln3_z;

      add_ln11_z = {1'b0, num_in[3:1]} + 4'h1;
      if (num_in[0]) 
        mux_round__ln3_z = add_ln11_z;
      else 
        mux_round__ln3_z = {1'b0, num_in[3:1]};
      round__out = mux_round__ln3_z;
    end
endmodule


module rbm_0_cmos32soi_sigmoid(sum_in, sigmoid_out);
  input [15:0] sum_in;
  output reg [6:0] sigmoid_out;

  always @(*) begin : rbm_0_cmos32soi_sigmoid_combinational
      reg [5:0] add_ln281_z;
      reg [5:0] add_ln281_0_z;
      reg [3:0] add_ln281_1_z;
      reg [1:0] add_ln281_3_z;
      reg ge_ln890_z;
      reg ge_ln890_0_0_z;
      reg ge_ln890_1_z;
      reg gt_ln842_z;
      reg le_ln794_1_0_z;
      reg le_ln794_z;
      reg lt_ln746_z;
      reg lt_ln746_0_z;
      reg le_ln794_0_0_z;
      reg xor_ln281_2_z;
      reg ge_ln890_0_z;
      reg ternaryMux_ln29_0_z;
      reg gt_ln842_0_z;
      reg and_if_ln22_z;
      reg ternaryMux_ln24_0_z;
      reg ternaryMux_ln34_0_z;
      reg ternaryMux_ln39_0_z;
      reg [2:0] case_mux_prob_ln24_z;
      reg [2:0] case_mux_prob_ln34_z;
      reg and_case_mux_prob_ln24_1_0_z;
      reg and_case_mux_prob_ln24_2_z;
      reg and_case_mux_prob_ln24_0_0_z;
      reg [4:0] mux_prob_ln34_z;
      reg [6:0] mux_prob_ln20_z;

      add_ln281_z = sum_in[6:1] + 6'h1b;
      add_ln281_0_z = sum_in[6:1] + 6'h5;
      add_ln281_1_z = sum_in[4:1] + 4'h5;
      add_ln281_3_z = sum_in[3:2] + 2'h1;
      ge_ln890_z = $signed(sum_in[15:1]) > $signed(4'h4);
      ge_ln890_0_0_z = ~|sum_in[14:1];
      ge_ln890_1_z = $signed(sum_in) > $signed(4'h4);
      gt_ln842_z = $signed(sum_in) > $signed(5'h16);
      le_ln794_1_0_z = ~&sum_in[14:2];
      le_ln794_z = $signed(sum_in) > $signed(5'h16);
      lt_ln746_z = $signed(sum_in[15:1]) > $signed(4'h4);
      lt_ln746_0_z = $signed(sum_in) > $signed(4'h4);
      le_ln794_0_0_z = ~&sum_in[14:0];
      xor_ln281_2_z = ~sum_in[1];
      ge_ln890_0_z = ~(sum_in[15] | ge_ln890_0_0_z);
      ternaryMux_ln29_0_z = sum_in[15] & le_ln794_1_0_z & gt_ln842_z;
      gt_ln842_0_z = sum_in[15] & le_ln794_1_0_z;
      and_if_ln22_z = !ge_ln890_z & !le_ln794_z;
      ternaryMux_ln24_0_z = !lt_ln746_z & ge_ln890_1_z;
      ternaryMux_ln34_0_z = !lt_ln746_0_z & ge_ln890_0_z;
      ternaryMux_ln39_0_z = sum_in[15] & le_ln794_0_0_z & !gt_ln842_0_z;
      case (1'b1)
        ternaryMux_ln24_0_z: case_mux_prob_ln24_z = 3'h1;
        ternaryMux_ln29_0_z: case_mux_prob_ln24_z = 3'h2;
        default: case_mux_prob_ln24_z = 3'h4;
      endcase
      case (1'b1)
        ternaryMux_ln34_0_z: case_mux_prob_ln34_z = 3'h1;
        ternaryMux_ln39_0_z: case_mux_prob_ln34_z = 3'h2;
        default: case_mux_prob_ln34_z = 3'h4;
      endcase
      and_case_mux_prob_ln24_1_0_z = !(!le_ln794_z) & case_mux_prob_ln24_z[2] & 
      !ge_ln890_z;
      and_case_mux_prob_ln24_2_z = !(!le_ln794_z) & case_mux_prob_ln24_z[0] & !
      ge_ln890_z;
      and_case_mux_prob_ln24_0_0_z = !(!le_ln794_z) & case_mux_prob_ln24_z[1] & 
      !ge_ln890_z;
      case (1'b1)// synopsys parallel_case
        case_mux_prob_ln34_z[0]: mux_prob_ln34_z = {add_ln281_1_z, sum_in[0]};
        case_mux_prob_ln34_z[1]: mux_prob_ln34_z = {2'h0, sum_in[1], 
          xor_ln281_2_z, sum_in[0]};
        case_mux_prob_ln34_z[2]: mux_prob_ln34_z = {add_ln281_3_z, sum_in[1:0], 
          1'b0};
        default: mux_prob_ln34_z = 5'hX;
      endcase
      case (1'b1)// synopsys parallel_case
        ge_ln890_z: mux_prob_ln20_z = 7'h40;
        and_if_ln22_z: mux_prob_ln20_z = 7'h0;
        and_case_mux_prob_ln24_2_z: mux_prob_ln20_z = {add_ln281_z, sum_in[0]};
        and_case_mux_prob_ln24_0_0_z: mux_prob_ln20_z = {add_ln281_0_z, sum_in[0]};
        and_case_mux_prob_ln24_1_0_z: mux_prob_ln20_z = {mux_prob_ln34_z, 2'h0};
        default: mux_prob_ln20_z = 7'hX;
      endcase
      sigmoid_out = mux_prob_ln20_z;
    end
endmodule


module rbm_0_cmos32soi_identity_sync_write_1002x8m0(rtl_CE, rtl_A, rtl_D, rtl_WE, CLK, mem_CE, mem_A, mem_D, mem_WE);
    input rtl_CE;
    input [9 : 0] rtl_A;
    input [7 : 0] rtl_D;
    input rtl_WE;
    input CLK;
    output mem_CE;
    output [9 : 0] mem_A;
    output [7 : 0] mem_D;
    output mem_WE;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
    assign mem_D = rtl_D;
    assign mem_WE = rtl_WE;
`ifdef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    // This is only required when simulating a multi-language design.
    bit use_dpi;
    wire m_ready;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(10), .DATA_WIDTH(8), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE && rtl_WE) begin
                arr_ref.write(rtl_A, rtl_D);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_read_50601x8m0(rtl_CE, rtl_A, mem_Q, CLK, mem_CE, mem_A, rtl_Q);
    input rtl_CE;
    input [15 : 0] rtl_A;
    input [7 : 0] mem_Q;
    input CLK;
    output mem_CE;
    output [15 : 0] mem_A;
    output [7 : 0] rtl_Q;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
`ifndef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    assign rtl_Q = mem_Q;

`else
    // This is only required when simulating a multi-language design.
    reg [7:0] dpi_Q;
    bit use_dpi;
    wire m_ready;
    // Pick which Q drives the RTL Q.
    assign rtl_Q = use_dpi ? dpi_Q : mem_Q;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(16), .DATA_WIDTH(8), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE) begin
                arr_ref.read(rtl_A, dpi_Q);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_write_128x4m0(rtl_CE, rtl_A, rtl_D, rtl_WE, CLK, mem_CE, mem_A, mem_D, mem_WE);
    input rtl_CE;
    input [6 : 0] rtl_A;
    input [3 : 0] rtl_D;
    input rtl_WE;
    input CLK;
    output mem_CE;
    output [6 : 0] mem_A;
    output [3 : 0] mem_D;
    output mem_WE;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
    assign mem_D = rtl_D;
    assign mem_WE = rtl_WE;
`ifdef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    // This is only required when simulating a multi-language design.
    bit use_dpi;
    wire m_ready;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(7), .DATA_WIDTH(4), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE && rtl_WE) begin
                arr_ref.write(rtl_A, rtl_D);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_read_5x16m0(rtl_CE, rtl_A, mem_Q, CLK, mem_CE, mem_A, rtl_Q);
    input rtl_CE;
    input [2 : 0] rtl_A;
    input [15 : 0] mem_Q;
    input CLK;
    output mem_CE;
    output [2 : 0] mem_A;
    output [15 : 0] rtl_Q;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
`ifndef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    assign rtl_Q = mem_Q;

`else
    // This is only required when simulating a multi-language design.
    reg [15:0] dpi_Q;
    bit use_dpi;
    wire m_ready;
    // Pick which Q drives the RTL Q.
    assign rtl_Q = use_dpi ? dpi_Q : mem_Q;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(3), .DATA_WIDTH(16), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE) begin
                arr_ref.read(rtl_A, dpi_Q);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_read_101x1m0(rtl_CE, rtl_A, mem_Q, CLK, mem_CE, mem_A, rtl_Q);
    input rtl_CE;
    input [6 : 0] rtl_A;
    input mem_Q;
    input CLK;
    output mem_CE;
    output [6 : 0] mem_A;
    output rtl_Q;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
`ifndef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    assign rtl_Q = mem_Q;

`else
    // This is only required when simulating a multi-language design.
    reg dpi_Q;
    bit use_dpi;
    wire m_ready;
    // Pick which Q drives the RTL Q.
    assign rtl_Q = use_dpi ? dpi_Q : mem_Q;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(7), .DATA_WIDTH(1), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE) begin
                arr_ref.read(rtl_A, dpi_Q);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_read_1002x8m0(rtl_CE, rtl_A, mem_Q, CLK, mem_CE, mem_A, rtl_Q);
    input rtl_CE;
    input [9 : 0] rtl_A;
    input [7 : 0] mem_Q;
    input CLK;
    output mem_CE;
    output [9 : 0] mem_A;
    output [7 : 0] rtl_Q;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
`ifndef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    assign rtl_Q = mem_Q;

`else
    // This is only required when simulating a multi-language design.
    reg [7:0] dpi_Q;
    bit use_dpi;
    wire m_ready;
    // Pick which Q drives the RTL Q.
    assign rtl_Q = use_dpi ? dpi_Q : mem_Q;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(10), .DATA_WIDTH(8), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE) begin
                arr_ref.read(rtl_A, dpi_Q);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_write_101x1m0(rtl_CE, rtl_A, rtl_D, rtl_WE, CLK, mem_CE, mem_A, mem_D, mem_WE);
    input rtl_CE;
    input [6 : 0] rtl_A;
    input rtl_D;
    input rtl_WE;
    input CLK;
    output mem_CE;
    output [6 : 0] mem_A;
    output mem_D;
    output mem_WE;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
    assign mem_D = rtl_D;
    assign mem_WE = rtl_WE;
`ifdef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    // This is only required when simulating a multi-language design.
    bit use_dpi;
    wire m_ready;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(7), .DATA_WIDTH(1), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE && rtl_WE) begin
                arr_ref.write(rtl_A, rtl_D);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_write_5x16m0(rtl_CE, rtl_A, rtl_D, rtl_WE, CLK, mem_CE, mem_A, mem_D, mem_WE);
    input rtl_CE;
    input [2 : 0] rtl_A;
    input [15 : 0] rtl_D;
    input rtl_WE;
    input CLK;
    output mem_CE;
    output [2 : 0] mem_A;
    output [15 : 0] mem_D;
    output mem_WE;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
    assign mem_D = rtl_D;
    assign mem_WE = rtl_WE;
`ifdef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    // This is only required when simulating a multi-language design.
    bit use_dpi;
    wire m_ready;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(3), .DATA_WIDTH(16), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE && rtl_WE) begin
                arr_ref.write(rtl_A, rtl_D);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_read_128x4m0(rtl_CE, rtl_A, mem_Q, CLK, mem_CE, mem_A, rtl_Q);
    input rtl_CE;
    input [6 : 0] rtl_A;
    input [3 : 0] mem_Q;
    input CLK;
    output mem_CE;
    output [6 : 0] mem_A;
    output [3 : 0] rtl_Q;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
`ifndef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    assign rtl_Q = mem_Q;

`else
    // This is only required when simulating a multi-language design.
    reg [3:0] dpi_Q;
    bit use_dpi;
    wire m_ready;
    // Pick which Q drives the RTL Q.
    assign rtl_Q = use_dpi ? dpi_Q : mem_Q;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(7), .DATA_WIDTH(4), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE) begin
                arr_ref.read(rtl_A, dpi_Q);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_write_50601x1m0(rtl_CE, rtl_A, rtl_D, rtl_WE, CLK, mem_CE, mem_A, mem_D, mem_WE);
    input rtl_CE;
    input [15 : 0] rtl_A;
    input rtl_D;
    input rtl_WE;
    input CLK;
    output mem_CE;
    output [15 : 0] mem_A;
    output mem_D;
    output mem_WE;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
    assign mem_D = rtl_D;
    assign mem_WE = rtl_WE;
`ifdef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    // This is only required when simulating a multi-language design.
    bit use_dpi;
    wire m_ready;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(16), .DATA_WIDTH(1), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE && rtl_WE) begin
                arr_ref.write(rtl_A, rtl_D);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_write_50601x8m0(rtl_CE, rtl_A, rtl_D, rtl_WE, CLK, mem_CE, mem_A, mem_D, mem_WE);
    input rtl_CE;
    input [15 : 0] rtl_A;
    input [7 : 0] rtl_D;
    input rtl_WE;
    input CLK;
    output mem_CE;
    output [15 : 0] mem_A;
    output [7 : 0] mem_D;
    output mem_WE;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
    assign mem_D = rtl_D;
    assign mem_WE = rtl_WE;
`ifdef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    // This is only required when simulating a multi-language design.
    bit use_dpi;
    wire m_ready;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(16), .DATA_WIDTH(8), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE && rtl_WE) begin
                arr_ref.write(rtl_A, rtl_D);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_read_50601x1m0(rtl_CE, rtl_A, mem_Q, CLK, mem_CE, mem_A, rtl_Q);
    input rtl_CE;
    input [15 : 0] rtl_A;
    input mem_Q;
    input CLK;
    output mem_CE;
    output [15 : 0] mem_A;
    output rtl_Q;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
`ifndef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    assign rtl_Q = mem_Q;

`else
    // This is only required when simulating a multi-language design.
    reg dpi_Q;
    bit use_dpi;
    wire m_ready;
    // Pick which Q drives the RTL Q.
    assign rtl_Q = use_dpi ? dpi_Q : mem_Q;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(16), .DATA_WIDTH(1), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE) begin
                arr_ref.read(rtl_A, dpi_Q);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_write_624x32m0(rtl_CE, rtl_A, rtl_D, rtl_WE, CLK, mem_CE, mem_A, mem_D, mem_WE);
    input rtl_CE;
    input [9 : 0] rtl_A;
    input [31 : 0] rtl_D;
    input rtl_WE;
    input CLK;
    output mem_CE;
    output [9 : 0] mem_A;
    output [31 : 0] mem_D;
    output mem_WE;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
    assign mem_D = rtl_D;
    assign mem_WE = rtl_WE;
`ifdef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    // This is only required when simulating a multi-language design.
    bit use_dpi;
    wire m_ready;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(10), .DATA_WIDTH(32), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE && rtl_WE) begin
                arr_ref.write(rtl_A, rtl_D);
            end
        end
    end
`endif
endmodule


module rbm_0_cmos32soi_identity_sync_read_624x32m0(rtl_CE, rtl_A, mem_Q, CLK, mem_CE, mem_A, rtl_Q);
    input rtl_CE;
    input [9 : 0] rtl_A;
    input [31 : 0] mem_Q;
    input CLK;
    output mem_CE;
    output [9 : 0] mem_A;
    output [31 : 0] rtl_Q;

    assign mem_CE = rtl_CE;
    assign mem_A = rtl_A;
`ifndef CTOS_SIM_MULTI_LANGUAGE_EXTERNAL_ARRAY
    assign rtl_Q = mem_Q;

`else
    // This is only required when simulating a multi-language design.
    reg [31:0] dpi_Q;
    bit use_dpi;
    wire m_ready;
    // Pick which Q drives the RTL Q.
    assign rtl_Q = use_dpi ? dpi_Q : mem_Q;
    initial begin
        use_dpi = 0;

        @(posedge m_ready)
        use_dpi = 1;
    end
    ctos_external_array_accessor #(.ADDR_WIDTH(10), .DATA_WIDTH(32), .TRACE(`CTOS_TRACE_EXT_ARRAY_)) arr_ref(m_ready);

    always @(posedge CLK) begin
        if (use_dpi) begin
            if (rtl_CE) begin
                arr_ref.read(rtl_A, dpi_Q);
            end
        end
    end
`endif
endmodule


