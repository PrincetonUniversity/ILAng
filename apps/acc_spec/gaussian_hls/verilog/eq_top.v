// wrapper to integrate two designs for equivalence checking
//
module eq_top (
    // input ports
    clk,
    rst_init,
    ila_complete,           // terminate when instruction completes
    hls_complete,           // terminate when instruction completes
    ila_exec,               // virtual input for initialization
    hls_exec,               // virtual input for initialization 
    arg_0_TREADY,
    arg_1_TDATA,
    arg_1_TVALID,
    //
    hls_s_axi_config_AWVALID,
    hls_s_axi_config_AWADDR,
    hls_s_axi_config_WVALID,
    hls_s_axi_config_WDATA,
    hls_s_axi_config_WSTRB,
    hls_s_axi_config_ARVALID,
    hls_s_axi_config_ARADDR,
    hls_s_axi_config_RREADY,
    hls_s_axi_config_BREADY,
    hls_arg_1_TLAST,
    // common output states
    ila_arg_0_TDATA,
    ila_arg_0_TVALID,
    ila_arg_1_TREADY,
    hls_arg_0_TDATA,
    hls_arg_0_TVALID,
    hls_arg_1_TREADY
);

parameter    ap_const_int64_8 = 8;
parameter    C_S_AXI_CONFIG_DATA_WIDTH = 32;
parameter    C_S_AXI_CONFIG_ADDR_WIDTH = 5;
parameter    C_S_AXI_DATA_WIDTH = 32;
parameter    C_S_AXI_ADDR_WIDTH = 32;
parameter    C_S_AXI_CONFIG_WSTRB_WIDTH = (C_S_AXI_CONFIG_DATA_WIDTH / ap_const_int64_8);
parameter    C_S_AXI_WSTRB_WIDTH = (C_S_AXI_DATA_WIDTH / ap_const_int64_8);

input           clk;
input           rst_init;
input           ila_complete;
input           hls_complete;
input           ila_exec;
input           hls_exec;
input           arg_0_TREADY;
input   [7:0]   arg_1_TDATA;
input           arg_1_TVALID;
output  [7:0]   ila_arg_0_TDATA;
output          ila_arg_0_TVALID;
output          ila_arg_1_TREADY;
output  [7:0]   hls_arg_0_TDATA;
output          hls_arg_0_TVALID;
output          hls_arg_1_TREADY;

input   hls_s_axi_config_AWVALID;
input  [C_S_AXI_CONFIG_ADDR_WIDTH - 1 : 0] hls_s_axi_config_AWADDR;
input   hls_s_axi_config_WVALID;
input  [C_S_AXI_CONFIG_DATA_WIDTH - 1 : 0] hls_s_axi_config_WDATA;
input  [C_S_AXI_CONFIG_WSTRB_WIDTH - 1 : 0] hls_s_axi_config_WSTRB;
input   hls_s_axi_config_ARVALID;
input  [C_S_AXI_CONFIG_ADDR_WIDTH - 1 : 0] hls_s_axi_config_ARADDR;
input   hls_s_axi_config_RREADY;
input   hls_s_axi_config_BREADY;
input  [0:0] hls_arg_1_TLAST;

reg [7:0] counter;
always @ (posedge clk) begin
    if (rst_init) begin
        counter <= 8'b0;
    end
    else begin
        counter <= counter + 8'b1;
    end
end

wire ila_clk = ~rst_init & clk & ~ila_complete;
wire hls_clk = ~rst_init & clk & ~hls_complete;
wire rst = 1'b0;

// ila 
wire    [7:0]   ila_LB1D_buff;
wire    [8:0]   ila_LB2D_proc_x;
wire    [9:0]   ila_LB2D_proc_y;
wire    [63:0]  ila_LB2D_proc_w;
wire    [71:0]  ila_LB2D_shift_0;
wire    [71:0]  ila_LB2D_shift_1;
wire    [71:0]  ila_LB2D_shift_2;
wire    [71:0]  ila_LB2D_shift_3;
wire    [71:0]  ila_LB2D_shift_4;
wire    [71:0]  ila_LB2D_shift_5;
wire    [71:0]  ila_LB2D_shift_6;
wire    [71:0]  ila_LB2D_shift_7;
wire    [8:0]   ila_LB2D_shift_x;
wire    [9:0]   ila_LB2D_shift_y;
wire    [7:0]   ila_arg_0_TDATA;
wire            ila_arg_0_TVALID;
wire            ila_arg_1_TREADY;
wire    [7:0]   ila_in_stream_buff_0;
wire    [7:0]   ila_in_stream_buff_1;
wire            ila_in_stream_empty;
wire            ila_in_stream_full;
wire    [71:0]  ila_slice_stream_buff_0;
wire    [71:0]  ila_slice_stream_buff_1;
wire            ila_slice_stream_empty;
wire            ila_slice_stream_full;
wire    [647:0] ila_stencil_stream_buff_0;
wire    [647:0] ila_stencil_stream_buff_1;
wire            ila_stencil_stream_empty;
wire            ila_stencil_stream_full;

wire            ila_step = 1'b1;

GB ila_U (
    .arg_0_TREADY (arg_0_TREADY),
    .arg_1_TDATA (arg_1_TDATA),
    .arg_1_TVALID (arg_1_TVALID),
    .LB1D_buff (ila_LB1D_buff),
    .LB2D_proc_w (ila_LB2D_proc_w),
    .LB2D_proc_x (ila_LB2D_proc_x),
    .LB2D_proc_y (ila_LB2D_proc_y),
    .LB2D_shift_0 (ila_LB2D_shift_0),
    .LB2D_shift_1 (ila_LB2D_shift_1),
    .LB2D_shift_2 (ila_LB2D_shift_2),
    .LB2D_shift_3 (ila_LB2D_shift_3),
    .LB2D_shift_4 (ila_LB2D_shift_4),
    .LB2D_shift_5 (ila_LB2D_shift_5),
    .LB2D_shift_6 (ila_LB2D_shift_6),
    .LB2D_shift_7 (ila_LB2D_shift_7),
    .LB2D_shift_x (ila_LB2D_shift_x),
    .LB2D_shift_y (ila_LB2D_shift_y),
    .arg_0_TDATA (ila_arg_0_TDATA),
    .arg_0_TVALID (ila_arg_0_TVALID),
    .arg_1_TREADY (ila_arg_1_TREADY),
    .in_stream_buff_0 (ila_in_stream_buff_0),
    .in_stream_buff_1 (ila_in_stream_buff_1),
    .in_stream_empty (ila_in_stream_empty),
    .in_stream_full (ila_in_stream_full),
    .slice_stream_buff_0 (ila_slice_stream_buff_0),
    .slice_stream_buff_1 (ila_slice_stream_buff_1),
    .slice_stream_empty (ila_slice_stream_empty),
    .slice_stream_full (ila_slice_stream_full),
    .stencil_stream_buff_0 (ila_stencil_stream_buff_0),
    .stencil_stream_buff_1 (ila_stencil_stream_buff_1),
    .stencil_stream_empty (ila_stencil_stream_empty),
    .stencil_stream_full (ila_stencil_stream_full),
    .clk (ila_clk),
    .rst (rst),
    .step (ila_step)
);

// hls
wire hls_s_axi_config_AWVALID;
wire hls_s_axi_config_AWREADY;
wire [C_S_AXI_CONFIG_ADDR_WIDTH - 1 : 0] hls_s_axi_config_AWADDR;
wire hls_s_axi_config_WVALID;
wire hls_s_axi_config_WREADY;
wire [C_S_AXI_CONFIG_DATA_WIDTH - 1 : 0] hls_s_axi_config_WDATA;
wire [C_S_AXI_CONFIG_WSTRB_WIDTH - 1 : 0] hls_s_axi_config_WSTRB;
wire hls_s_axi_config_ARVALID;
wire hls_s_axi_config_ARREADY;
wire [C_S_AXI_CONFIG_ADDR_WIDTH - 1 : 0] hls_s_axi_config_ARADDR;
wire hls_s_axi_config_RVALID;
wire hls_s_axi_config_RREADY;
wire [C_S_AXI_CONFIG_DATA_WIDTH - 1 : 0] hls_s_axi_config_RDATA;
wire [1:0] hls_s_axi_config_RRESP;
wire hls_s_axi_config_BVALID;
wire hls_s_axi_config_BREADY;
wire [1:0] hls_s_axi_config_BRESP;
wire hls_interrupt;
wire [7:0] hls_arg_0_TDATA;
wire [0:0] hls_arg_0_TLAST;
wire [0:0] hls_arg_1_TLAST;
wire hls_arg_1_TREADY;
wire hls_arg_0_TVALID;

hls_target hls_U (
    .s_axi_config_AWVALID (hls_s_axi_config_AWVALID),
    .s_axi_config_AWREADY (hls_s_axi_config_AWREADY),
    .s_axi_config_AWADDR (hls_s_axi_config_AWADDR),
    .s_axi_config_WVALID (hls_s_axi_config_WVALID),
    .s_axi_config_WREADY (hls_s_axi_config_WREADY),
    .s_axi_config_WDATA (hls_s_axi_config_WDATA),
    .s_axi_config_WSTRB (hls_s_axi_config_WSTRB),
    .s_axi_config_ARVALID (hls_s_axi_config_ARVALID),
    .s_axi_config_ARREADY (hls_s_axi_config_ARREADY),
    .s_axi_config_ARADDR (hls_s_axi_config_ARADDR),
    .s_axi_config_RVALID (hls_s_axi_config_RVALID),
    .s_axi_config_RREADY (hls_s_axi_config_RREADY),
    .s_axi_config_RDATA (hls_s_axi_config_RDATA),
    .s_axi_config_RRESP (hls_s_axi_config_RRESP),
    .s_axi_config_BVALID (hls_s_axi_config_BVALID),
    .s_axi_config_BREADY (hls_s_axi_config_BREADY),
    .s_axi_config_BRESP (hls_s_axi_config_BRESP),
    .ap_clk (hls_clk),
    .ap_rst_n (~rst),
    .interrupt (hls_interrupt),
    .arg_0_TDATA (hls_arg_0_TDATA),
    .arg_0_TLAST (hls_arg_0_TLAST),
    .arg_1_TDATA (arg_1_TDATA),
    .arg_1_TLAST (hls_arg_1_TLAST),
    .arg_1_TVALID (arg_1_TVALID),
    .arg_1_TREADY (hls_arg_1_TREADY),
    .arg_0_TVALID (hls_arg_0_TVALID),
    .arg_0_TREADY (arg_0_TREADY)
);


endmodule
