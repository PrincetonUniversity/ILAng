// Wrapper for hls_target
//
module gb_top (
    eqcheck_init,
    s_axi_config_AWVALID,
    s_axi_config_AWREADY,
    s_axi_config_AWADDR,
    s_axi_config_WVALID,
    s_axi_config_WREADY,
    s_axi_config_WDATA,
    s_axi_config_WSTRB,
    s_axi_config_ARVALID,
    s_axi_config_ARREADY,
    s_axi_config_ARADDR,
    s_axi_config_RVALID,
    s_axi_config_RREADY,
    s_axi_config_RDATA,
    s_axi_config_RRESP,
    s_axi_config_BVALID,
    s_axi_config_BREADY,
    s_axi_config_BRESP,
    //ap_clk,
    //ap_rst_n,
    clk,
    rst,
    interrupt,
    arg_0_TDATA,
    arg_0_TLAST,
    arg_1_TDATA,
    arg_1_TLAST,
    arg_1_TVALID,
    arg_1_TREADY,
    arg_0_TVALID,
    arg_0_TREADY
);

input eqcheck_init;
reg [1:0] init_counter;

always @ (posedge clk) begin
    if (eqcheck_init) begin
        init_counter <= 2'b00;
    end
    else if ((~eqcheck_init) & (init_counter == 2'b00)) begin
        init_counter <= 2'b01;
    end
    else begin
        init_counter <= 2'b10;
    end
end

parameter    C_S_AXI_CONFIG_DATA_WIDTH = 32;
parameter    ap_const_int64_8 = 8;
parameter    C_S_AXI_CONFIG_ADDR_WIDTH = 5;
parameter    C_S_AXI_DATA_WIDTH = 32;
parameter    C_S_AXI_ADDR_WIDTH = 32;
parameter    ap_const_logic_1 = 1'b1;
parameter    ap_const_lv8_0 = 8'b00000000;
parameter    ap_const_lv1_0 = 1'b0;
parameter    ap_const_logic_0 = 1'b0;
parameter    ap_true = 1'b1;
parameter    C_S_AXI_CONFIG_WSTRB_WIDTH = (C_S_AXI_CONFIG_DATA_WIDTH / ap_const_int64_8);
parameter    C_S_AXI_WSTRB_WIDTH = (C_S_AXI_DATA_WIDTH / ap_const_int64_8);

input   s_axi_config_AWVALID;
output   s_axi_config_AWREADY;
input  [C_S_AXI_CONFIG_ADDR_WIDTH - 1 : 0] s_axi_config_AWADDR;
input   s_axi_config_WVALID;
output   s_axi_config_WREADY;
input  [C_S_AXI_CONFIG_DATA_WIDTH - 1 : 0] s_axi_config_WDATA;
input  [C_S_AXI_CONFIG_WSTRB_WIDTH - 1 : 0] s_axi_config_WSTRB;
input   s_axi_config_ARVALID;
output   s_axi_config_ARREADY;
input  [C_S_AXI_CONFIG_ADDR_WIDTH - 1 : 0] s_axi_config_ARADDR;
output   s_axi_config_RVALID;
input   s_axi_config_RREADY;
output  [C_S_AXI_CONFIG_DATA_WIDTH - 1 : 0] s_axi_config_RDATA;
output  [1:0] s_axi_config_RRESP;
output   s_axi_config_BVALID;
input   s_axi_config_BREADY;
output  [1:0] s_axi_config_BRESP;
//input   ap_clk;
//input   ap_rst_n;
input clk;
input rst;
wire ap_clk = clk;
wire ap_rst_n = ~rst;
//
output   interrupt;
output  [7:0] arg_0_TDATA;
output  [0:0] arg_0_TLAST;
input  [7:0] arg_1_TDATA;
input  [0:0] arg_1_TLAST;
input   arg_1_TVALID;
output   arg_1_TREADY;
output   arg_0_TVALID;
input   arg_0_TREADY;

hls_target hls_target_U (
    .s_axi_config_AWVALID (s_axi_config_AWVALID),
    .s_axi_config_AWREADY (s_axi_config_AWREADY),
    .s_axi_config_AWADDR (s_axi_config_AWADDR),
    .s_axi_config_WVALID (s_axi_config_WVALID),
    .s_axi_config_WREADY (s_axi_config_WREADY),
    .s_axi_config_WDATA (s_axi_config_WDATA),
    .s_axi_config_WSTRB (s_axi_config_WSTRB),
    .s_axi_config_ARVALID (s_axi_config_ARVALID),
    .s_axi_config_ARREADY (s_axi_config_ARREADY),
    .s_axi_config_ARADDR (s_axi_config_ARADDR),
    .s_axi_config_RVALID (s_axi_config_RVALID),
    .s_axi_config_RREADY (s_axi_config_RREADY),
    .s_axi_config_RDATA (s_axi_config_RDATA),
    .s_axi_config_RRESP (s_axi_config_RRESP),
    .s_axi_config_BVALID (s_axi_config_BVALID),
    .s_axi_config_BREADY (s_axi_config_BREADY),
    .s_axi_config_BRESP (s_axi_config_BRESP),
    .ap_clk (ap_clk),
    .ap_rst_n (ap_rst_n),
    .interrupt (interrupt),
    .arg_0_TDATA (arg_0_TDATA),
    .arg_0_TLAST (arg_0_TLAST),
    .arg_1_TDATA (arg_1_TDATA),
    .arg_1_TLAST (arg_1_TLAST),
    .arg_1_TVALID (arg_1_TVALID),
    .arg_1_TREADY (arg_1_TREADY),
    .arg_0_TVALID (arg_0_TVALID),
    .arg_0_TREADY (rg_0_TREADY)
);

endmodule
