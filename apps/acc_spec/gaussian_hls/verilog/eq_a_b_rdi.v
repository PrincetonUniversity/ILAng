// wrapper to integrate two ILA for equivalence checking
//
module eq_top ( 
    clk,
    rst_init,
    a_complete,
    b_complete,
    arg_0_TREADY,
    arg_1_TDATA,
    arg_1_TVALID,
    //
    a_arg_0_TDATA,
    a_arg_0_TVALID,
    a_arg_1_TREADY,
    b_arg_0_TDATA,
    b_arg_0_TVALID,
    b_arg_1_TREADY
);

input           clk;
input           rst_init;
input           a_complete;
input           b_complete;
input           arg_0_TREADY;
input   [7:0]   arg_1_TDATA;
input           arg_1_TVALID;
output  [7:0]   a_arg_0_TDATA;
output          a_arg_0_TVALID;
output          a_arg_1_TREADY;
output  [7:0]   b_arg_0_TDATA;
output          b_arg_0_TVALID;
output          b_arg_1_TREADY;

reg [15:0] counter;
always @ (posedge clk) begin
    if (rst_init) begin
        counter <= 16'b0;
    end
    else if (counter == 15) begin
        counter <= 15;
    end 
    else begin
        counter <= counter + 16'b1;
    end
end

reg [1:0] phase;
always @ (posedge clk) begin
    if (rst_init) begin
        phase <= 0;
    end
    else if (phase == 0 & a_complete == 1 & b_complete == 1) begin
        phase <= 1;
    end
    else if (phase == 1) begin
        phase <= 2;
    end 
    else begin
        phase <= phase;
    end
end

wire a_clk = ~rst_init & clk & ~a_complete;
wire b_clk = ~rst_init & clk & ~b_complete;
wire rst = 1'b0;

// ILA a (high-level)
wire      [2:0] a_RAM_w;
wire      [8:0] a_RAM_x;
wire      [9:0] a_RAM_y;
wire      [7:0] a_arg_0_TDATA;
wire            a_arg_0_TVALID;
wire            a_arg_1_TREADY;
wire      [7:0] a_cur_pix;
wire      [3:0] a_gbit;
wire     [71:0] a_stencil_0;
wire     [71:0] a_stencil_1;
wire     [71:0] a_stencil_2;
wire     [71:0] a_stencil_3;
wire     [71:0] a_stencil_4;
wire     [71:0] a_stencil_5;
wire     [71:0] a_stencil_6;
wire     [71:0] a_stencil_7;
wire     [71:0] a_stencil_8;

wire                a_step = 1'b1;

SPEC_A ila_a (
    .arg_0_TREADY (arg_0_TREADY),
    .arg_1_TDATA (arg_1_TDATA),
    .arg_1_TVALID (arg_1_TVALID),
    .RAM_w (a_RAM_w),
    .RAM_x (a_RAM_x),
    .RAM_y (a_RAM_y),
    .arg_0_TDATA (a_arg_0_TDATA),
    .arg_0_TVALID (a_arg_0_TVALID),
    .arg_1_TREADY (a_arg_1_TREADY),
    .cur_pix (a_cur_pix),
    .gbit (a_gbit),
    .stencil_0 (a_stencil_0),
    .stencil_1 (a_stencil_1),
    .stencil_2 (a_stencil_2),
    .stencil_3 (a_stencil_3),
    .stencil_4 (a_stencil_4),
    .stencil_5 (a_stencil_5),
    .stencil_6 (a_stencil_6),
    .stencil_7 (a_stencil_7),
    .stencil_8 (a_stencil_8),
    .clk (a_clk),
    .rst (rst),
    .step (a_step)
);

// spec b (detailed)
wire    [7:0]   b_LB1D_in;
wire    [7:0]   b_LB1D_uIn;
wire    [7:0]   b_LB1D_buff;
wire            b_LB1D_it_1;
wire    [18:0]  b_LB1D_p_cnt;
wire    [8:0]   b_LB2D_proc_x;
wire    [9:0]   b_LB2D_proc_y;
wire    [63:0]  b_LB2D_proc_w;
wire    [71:0]  b_LB2D_shift_0;
wire    [71:0]  b_LB2D_shift_1;
wire    [71:0]  b_LB2D_shift_2;
wire    [71:0]  b_LB2D_shift_3;
wire    [71:0]  b_LB2D_shift_4;
wire    [71:0]  b_LB2D_shift_5;
wire    [71:0]  b_LB2D_shift_6;
wire    [71:0]  b_LB2D_shift_7;
wire    [8:0]   b_LB2D_shift_x;
wire    [9:0]   b_LB2D_shift_y;
wire    [7:0]   b_arg_0_TDATA;
wire            b_arg_0_TVALID;
wire            b_arg_1_TREADY;
wire            b_gb_exit_it_1;
wire            b_gb_exit_it_2;
wire            b_gb_exit_it_3;
wire            b_gb_exit_it_4;
wire            b_gb_exit_it_5;
wire            b_gb_exit_it_6;
wire            b_gb_exit_it_7;
wire            b_gb_exit_it_8;
wire    [18:0]  b_gb_p_cnt;
wire            b_gb_pp_it_1;
wire            b_gb_pp_it_2;
wire            b_gb_pp_it_3;
wire            b_gb_pp_it_4;
wire            b_gb_pp_it_5;
wire            b_gb_pp_it_6;
wire            b_gb_pp_it_7;
wire            b_gb_pp_it_8;
wire            b_gb_pp_it_9;
wire    [7:0]   b_in_stream_buff_0;
wire    [7:0]   b_in_stream_buff_1;
wire            b_in_stream_empty;
wire            b_in_stream_full;
wire    [71:0]  b_slice_stream_buff_0;
wire    [71:0]  b_slice_stream_buff_1;
wire            b_slice_stream_empty;
wire            b_slice_stream_full;
wire    [647:0] b_stencil_stream_buff_0;
wire    [647:0] b_stencil_stream_buff_1;
wire            b_stencil_stream_empty;
wire            b_stencil_stream_full;

wire            b_step = 1'b1;

SPEC_B ila_b (
    .arg_0_TREADY (arg_0_TREADY),
    .arg_1_TDATA (arg_1_TDATA),
    .arg_1_TVALID (arg_1_TVALID),
    .LB1D_in (b_LB1D_in),
    .LB1D_uIn (b_LB1D_uIn),
    .LB1D_buff (b_LB1D_buff),
    .LB1D_it_1 (b_LB1D_it_1),
    .LB1D_p_cnt (b_LB1D_p_cnt),
    .LB2D_proc_w (b_LB2D_proc_w),
    .LB2D_proc_x (b_LB2D_proc_x),
    .LB2D_proc_y (b_LB2D_proc_y),
    .LB2D_shift_0 (b_LB2D_shift_0),
    .LB2D_shift_1 (b_LB2D_shift_1),
    .LB2D_shift_2 (b_LB2D_shift_2),
    .LB2D_shift_3 (b_LB2D_shift_3),
    .LB2D_shift_4 (b_LB2D_shift_4),
    .LB2D_shift_5 (b_LB2D_shift_5),
    .LB2D_shift_6 (b_LB2D_shift_6),
    .LB2D_shift_7 (b_LB2D_shift_7),
    .LB2D_shift_x (b_LB2D_shift_x),
    .LB2D_shift_y (b_LB2D_shift_y),
    .arg_0_TDATA (b_arg_0_TDATA),
    .arg_0_TVALID (b_arg_0_TVALID),
    .arg_1_TREADY (b_arg_1_TREADY),
    .gb_exit_it_1 (b_gb_exit_it_1),
    .gb_exit_it_2 (b_gb_exit_it_2),
    .gb_exit_it_3 (b_gb_exit_it_3),
    .gb_exit_it_4 (b_gb_exit_it_4),
    .gb_exit_it_5 (b_gb_exit_it_5),
    .gb_exit_it_6 (b_gb_exit_it_6),
    .gb_exit_it_7 (b_gb_exit_it_7),
    .gb_exit_it_8 (b_gb_exit_it_8),
    .gb_p_cnt (b_gb_p_cnt),
    .gb_pp_it_1 (b_gb_pp_it_1),
    .gb_pp_it_2 (b_gb_pp_it_2),
    .gb_pp_it_3 (b_gb_pp_it_3),
    .gb_pp_it_4 (b_gb_pp_it_4),
    .gb_pp_it_5 (b_gb_pp_it_5),
    .gb_pp_it_6 (b_gb_pp_it_6),
    .gb_pp_it_7 (b_gb_pp_it_7),
    .gb_pp_it_8 (b_gb_pp_it_8),
    .gb_pp_it_9 (b_gb_pp_it_9),
    .in_stream_buff_0 (b_in_stream_buff_0),
    .in_stream_buff_1 (b_in_stream_buff_1),
    .in_stream_empty (b_in_stream_empty),
    .in_stream_full (b_in_stream_full),
    .slice_stream_buff_0 (b_slice_stream_buff_0),
    .slice_stream_buff_1 (b_slice_stream_buff_1),
    .slice_stream_empty (b_slice_stream_empty),
    .slice_stream_full (b_slice_stream_full),
    .stencil_stream_buff_0 (b_stencil_stream_buff_0),
    .stencil_stream_buff_1 (b_stencil_stream_buff_1),
    .stencil_stream_empty (b_stencil_stream_empty),
    .stencil_stream_full (b_stencil_stream_full),
    .clk (b_clk),
    .rst (rst),
    .step (b_step)
);

endmodule
