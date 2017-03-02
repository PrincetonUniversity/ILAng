// wrapper to integrate two designs for equivalence checking
//
module eq_top (
    // input ports
    clk,
    rst_init,
    ila_step,           // terminate when instruction completes
    hls_step,           // terminate when instruction completes
    arg_0_TREADY,
    arg_1_TDATA,
    arg_1_TVALID,
    // common output states
    ila_arg_0_TDATA,
    ila_arg_0_TVALID,
    ila_arg_1_TREADY,
    hls_arg_0_TDATA,
    hls_arg_0_TVALID,
    hls_arg_1_TREADY
);

input           clk;
input           rst_init;
input           ila_step;
input           hls_step;
input           arg_0_TREADY;
input   [7:0]   arg_1_TDATA;
input           arg_1_TVALID;
output  [7:0]   ila_arg_0_TDATA;
output          ila_arg_0_TVALID;
output          ila_arg_1_TREADY;
output  [7:0]   hls_arg_0_TDATA;
output          hls_arg_0_TVALID;
output          hls_arg_1_TREADY;

wire ila_clk = clk & ila_step;
wire hls_clk = clk & hls_step;
wire rst = 1'b0;

// ila 
wire    [7:0]   ila_arg_0_TDATA;
wire            ila_arg_0_TVALID;
wire            ila_arg_1_TREADY;
wire    [71:0]  ila_buff_0;
wire    [71:0]  ila_buff_1;
wire    [71:0]  ila_buff_2;
wire    [71:0]  ila_buff_3;
wire    [71:0]  ila_buff_4;
wire    [71:0]  ila_buff_5;
wire    [71:0]  ila_buff_6;
wire    [71:0]  ila_buff_7;
wire    [8:0]   ila_x_idx;
wire            ila_stencil_full;
wire    [647:0] ila_stencil_buff;
wire    [63:0]  ila_w_idx;
wire    [9:0]   ila_y_idx;
wire    [71:0]  ila_slice_buff;
wire            ila_slice_full;

gaussianRTL ila_target (
    .arg_0_TREADY (arg_0_TREADY),
    .arg_1_TDATA (arg_1_TDATA),
    .arg_1_TVALID (arg_1_TVALID),
    .arg_0_TDATA (ila_arg_0_TDATA),
    .arg_0_TVALID (ila_arg_0_TVALID),
    .arg_1_TREADY (ila_arg_1_TREADY),
    .buffer_0_value_V_fu_ (ila_buff_0),
    .buffer_1_value_V_fu_ (ila_buff_1),
    .buffer_2_value_V_fu_ (ila_buff_2),
    .buffer_3_value_V_fu_ (ila_buff_3),
    .buffer_4_value_V_fu_ (ila_buff_4),
    .buffer_5_value_V_fu_ (ila_buff_5),
    .buffer_6_value_V_fu_ (ila_buff_6),
    .buffer_7_value_V_fu_ (ila_buff_7),
    .col_reg_349 (ila_x_idx),
    .p_p2_in_bounded_stencil_stream_full (ila_stencil_full),
    .p_p2_in_bounded_stencil_stream_s_U (ila_stencil_buff),
    .p_write_idx_1_1_reg_723 (ila_w_idx),
    .row_reg_327 (ila_y_idx),
    .slice_stream_V_value_V_U (ila_slice_buff),
    .slice_stream_V_value_V_U_internal_full_n (ila_slice_full),
    .clk (ila_clk),
    .rst (rst),
    .step (ila_step)
);




endmodule
