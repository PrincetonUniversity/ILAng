/* PREHEADER */

`define true  1'b1

`define false 1'b0

/* END OF PREHEADER */
module wrapper(
SYS_ADDR,
TCORE_MODE,
__ILA_I_clk,
__ILA_I_host_addr,
__ILA_I_mac_ctrl,
__ILA_I_mac_ctrl_1,
__ILA_I_mac_rxv_en,
__ILA_I_phy_rst,
__ILA_I_reg_clk,
__ILA_I_reg_read_start,
__ILA_I_rst,
clk,
cs_fifo_rd_en,
dummy_reset,
fail_over,
fmac_ctrl,
fmac_ctrl1,
fmac_rxd_en,
fmac_speed,
gige_clk,
gmii_rx_dv,
gmii_rxc,
gmii_rxd,
host_addr_reg,
mac_addr0,
mac_pause_value,
mcast_saddr,
reg_rd_done,
reg_rd_start,
reset_,
rst,
rx_mac_rd,
rx_mac_rd_cycle,
sfp_los,
tx_mac_data,
tx_mac_wr,
xauiA_clk,
FIFO_OV_IPEND,
FMAC_REGDOUT,
__ILA_SO_FMAC_RX_BYTE_CNT_HI,
__ILA_SO_FMAC_RX_BYTE_CNT_LO,
__ILA_SO_FMAC_RX_PKT_CNT_HI,
__ILA_SO_FMAC_RX_PKT_CNT_LO,
__ILA_SO_FMAC_TX_BYTE_CNT,
__ILA_SO_FMAC_TX_PKT_CNT,
__ILA_SO_link_up,
__ILA_SO_lmac_read_reg_cache_val,
__ILA_SO_lmac_read_reg_cycle_cnt,
__ILA_SO_mac_reg_d_out,
__ILA_SO_read_reg_done_out,
additional_mapping_control_assume__m1__,
additional_mapping_control_assume__m2__,
additional_mapping_control_assume__m3__,
additional_mapping_control_assume__m4__,
additional_mapping_control_assume__m5__,
cs_fifo_empty,
gmii_tx_en,
gmii_tx_vld,
gmii_txc,
gmii_txd,
ipcs_fifo_dout,
issue_decode__m6__,
issue_valid__m7__,
noreset__m0__,
rx_mac_ctrl,
rx_mac_data,
rx_mac_empty,
rx_mac_full_dbg,
rx_mac_usedw_dbg,
tx_mac_full,
tx_mac_usedw,
xauiA_linkup,
__CYCLE_CNT__,
__START__,
__STARTED__,
__ENDED__,
__RESETED__
);
input      [3:0] SYS_ADDR;
input            TCORE_MODE;
input            __ILA_I_clk;
input     [15:0] __ILA_I_host_addr;
input     [31:0] __ILA_I_mac_ctrl;
input     [31:0] __ILA_I_mac_ctrl_1;
input            __ILA_I_mac_rxv_en;
input            __ILA_I_phy_rst;
input            __ILA_I_reg_clk;
input            __ILA_I_reg_read_start;
input            __ILA_I_rst;
input            clk;
input            cs_fifo_rd_en;
input            dummy_reset;
input            fail_over;
input     [31:0] fmac_ctrl;
input     [31:0] fmac_ctrl1;
input            fmac_rxd_en;
input      [1:0] fmac_speed;
input            gige_clk;
input            gmii_rx_dv;
input            gmii_rxc;
input      [7:0] gmii_rxd;
input     [15:0] host_addr_reg;
input     [47:0] mac_addr0;
input     [31:0] mac_pause_value;
input     [47:0] mcast_saddr;
input            reg_rd_done;
input            reg_rd_start;
input            reset_;
input            rst;
input            rx_mac_rd;
input            rx_mac_rd_cycle;
input            sfp_los;
input     [63:0] tx_mac_data;
input            tx_mac_wr;
input            xauiA_clk;
output            FIFO_OV_IPEND;
output     [31:0] FMAC_REGDOUT;
output     [31:0] __ILA_SO_FMAC_RX_BYTE_CNT_HI;
output     [31:0] __ILA_SO_FMAC_RX_BYTE_CNT_LO;
output     [31:0] __ILA_SO_FMAC_RX_PKT_CNT_HI;
output     [31:0] __ILA_SO_FMAC_RX_PKT_CNT_LO;
output     [31:0] __ILA_SO_FMAC_TX_BYTE_CNT;
output     [31:0] __ILA_SO_FMAC_TX_PKT_CNT;
output            __ILA_SO_link_up;
output     [31:0] __ILA_SO_lmac_read_reg_cache_val;
output      [7:0] __ILA_SO_lmac_read_reg_cycle_cnt;
output     [31:0] __ILA_SO_mac_reg_d_out;
output            __ILA_SO_read_reg_done_out;
output            additional_mapping_control_assume__m1__;
output            additional_mapping_control_assume__m2__;
output            additional_mapping_control_assume__m3__;
output            additional_mapping_control_assume__m4__;
output            additional_mapping_control_assume__m5__;
output            cs_fifo_empty;
output            gmii_tx_en;
output            gmii_tx_vld;
output            gmii_txc;
output      [7:0] gmii_txd;
output     [63:0] ipcs_fifo_dout;
output            issue_decode__m6__;
output            issue_valid__m7__;
output            noreset__m0__;
output      [7:0] rx_mac_ctrl;
output     [63:0] rx_mac_data;
output            rx_mac_empty;
output            rx_mac_full_dbg;
output     [11:0] rx_mac_usedw_dbg;
output            tx_mac_full;
output     [12:0] tx_mac_usedw;
output            xauiA_linkup;
output reg      [3:0] __CYCLE_CNT__;
output reg            __START__;
output reg            __STARTED__;
output reg            __ENDED__;
output reg            __RESETED__;
(* keep *) wire            FIFO_OV_IPEND;
(* keep *) wire     [31:0] FMAC_REGDOUT;
(* keep *) wire      [3:0] SYS_ADDR;
(* keep *) wire            TCORE_MODE;
(* keep *) wire            __IEND__;
(* keep *) wire            __ILA_I_clk;
(* keep *) wire     [15:0] __ILA_I_host_addr;
(* keep *) wire     [31:0] __ILA_I_mac_ctrl;
(* keep *) wire     [31:0] __ILA_I_mac_ctrl_1;
(* keep *) wire            __ILA_I_mac_rxv_en;
(* keep *) wire            __ILA_I_phy_rst;
(* keep *) wire            __ILA_I_reg_clk;
(* keep *) wire            __ILA_I_reg_read_start;
(* keep *) wire            __ILA_I_rst;
(* keep *) wire     [31:0] __ILA_SO_FMAC_RX_BYTE_CNT_HI;
(* keep *) wire     [31:0] __ILA_SO_FMAC_RX_BYTE_CNT_LO;
(* keep *) wire     [31:0] __ILA_SO_FMAC_RX_PKT_CNT_HI;
(* keep *) wire     [31:0] __ILA_SO_FMAC_RX_PKT_CNT_LO;
(* keep *) wire     [31:0] __ILA_SO_FMAC_TX_BYTE_CNT;
(* keep *) wire     [31:0] __ILA_SO_FMAC_TX_PKT_CNT;
(* keep *) wire            __ILA_SO_link_up;
(* keep *) wire     [31:0] __ILA_SO_lmac_read_reg_cache_val;
(* keep *) wire      [7:0] __ILA_SO_lmac_read_reg_cycle_cnt;
(* keep *) wire     [31:0] __ILA_SO_mac_reg_d_out;
(* keep *) wire            __ILA_SO_read_reg_done_out;
(* keep *) wire            __ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__;
(* keep *) wire            __ILA_lmac_valid__;
(* keep *) wire            __ISSUE__;
(* keep *) wire            additional_mapping_control_assume__m1__;
(* keep *) wire            additional_mapping_control_assume__m2__;
(* keep *) wire            additional_mapping_control_assume__m3__;
(* keep *) wire            additional_mapping_control_assume__m4__;
(* keep *) wire            additional_mapping_control_assume__m5__;
wire            clk;
(* keep *) wire            cs_fifo_empty;
(* keep *) wire            cs_fifo_rd_en;
(* keep *) wire            dummy_reset;
(* keep *) wire            fail_over;
(* keep *) wire     [31:0] fmac_ctrl;
(* keep *) wire     [31:0] fmac_ctrl1;
(* keep *) wire            fmac_rxd_en;
(* keep *) wire      [1:0] fmac_speed;
(* keep *) wire            gige_clk;
(* keep *) wire            gmii_rx_dv;
(* keep *) wire            gmii_rxc;
(* keep *) wire      [7:0] gmii_rxd;
(* keep *) wire            gmii_tx_en;
(* keep *) wire            gmii_tx_vld;
(* keep *) wire            gmii_txc;
(* keep *) wire      [7:0] gmii_txd;
(* keep *) wire     [15:0] host_addr_reg;
(* keep *) wire     [63:0] ipcs_fifo_dout;
(* keep *) wire            issue_decode__m6__;
(* keep *) wire            issue_valid__m7__;
(* keep *) wire     [47:0] mac_addr0;
(* keep *) wire     [31:0] mac_pause_value;
(* keep *) wire     [47:0] mcast_saddr;
(* keep *) wire            noreset__m0__;
(* keep *) wire            reg_rd_done;
(* keep *) wire            reg_rd_start;
(* keep *) wire            reset_;
wire            rst;
(* keep *) wire      [7:0] rx_mac_ctrl;
(* keep *) wire     [63:0] rx_mac_data;
(* keep *) wire            rx_mac_empty;
(* keep *) wire            rx_mac_full_dbg;
(* keep *) wire            rx_mac_rd;
(* keep *) wire            rx_mac_rd_cycle;
(* keep *) wire     [11:0] rx_mac_usedw_dbg;
(* keep *) wire            sfp_los;
(* keep *) wire     [63:0] tx_mac_data;
(* keep *) wire            tx_mac_full;
(* keep *) wire     [12:0] tx_mac_usedw;
(* keep *) wire            tx_mac_wr;
(* keep *) wire            xauiA_clk;
(* keep *) wire            xauiA_linkup;
assign noreset__m0__ =  (~__RESETED__) || (dummy_reset == 0)  ;
always @(posedge clk) begin
if (rst) __CYCLE_CNT__ <= 0;
else if ( ( __START__ || __STARTED__ ) &&  __CYCLE_CNT__ < 10) __CYCLE_CNT__ <= __CYCLE_CNT__ + 1;
end
always @(posedge clk) begin
if (rst) __START__ <= 0;
else if (__START__ || __STARTED__) __START__ <= 0;
else if (__ISSUE__) __START__ <= 1;
end
always @(posedge clk) begin
if (rst) __STARTED__ <= 0;
else if (__START__) __STARTED__ <= 1;
end
always @(posedge clk) begin
if (rst) __ENDED__ <= 0;
else if (__IEND__) __ENDED__ <= 1;
end
always @(posedge clk) begin
if (rst) __RESETED__ <= 1;
end
assign additional_mapping_control_assume__m1__ = (m1.xram_wr & m1.xram_stb) == __MEM_XRAM_0_wen ;
assign additional_mapping_control_assume__m2__ = (~ ( m0.cmd == 2 )) || ( m1.wr == 1) ;
assign additional_mapping_control_assume__m3__ = (~ ( m0.cmd == 1 )) || ( m1.wr == 0) ;
assign additional_mapping_control_assume__m4__ =  m1.xram_addr ==  __MEM_XRAM_0_raddr  ;
assign additional_mapping_control_assume__m5__ =  m1.xram_addr ==  __MEM_XRAM_0_waddr  ;
assign __IEND__ = (`false|| ( __CYCLE_CNT__ == 4'd5)) && __STARTED__ && (~ __ENDED__) ;
assign issue_decode__m6__ = (~ __START__) || (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) ;
assign issue_valid__m7__ = (~ __START__) || (__ILA_lmac_valid__) ;
assign __ISSUE__ = 1 ;

lmac__DOT__READ_FMAC_TX_PKT_CNT_SINGLE m0 (
   .__START__(__START__),
   .clk(clk),
   .host_addr(__ILA_I_host_addr),
   .mac_ctrl(__ILA_I_mac_ctrl),
   .mac_ctrl_1(__ILA_I_mac_ctrl_1),
   .mac_rxv_en(__ILA_I_mac_rxv_en),
   .phy_rst(__ILA_I_phy_rst),
   .reg_clk(__ILA_I_reg_clk),
   .reg_read_start(__ILA_I_reg_read_start),
   .rst(rst),
   .__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__(__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__),
   .__ILA_lmac_valid__(__ILA_lmac_valid__),
   .link_up(__ILA_SO_link_up),
   .read_reg_done_out(__ILA_SO_read_reg_done_out),
   .mac_reg_d_out(__ILA_SO_mac_reg_d_out),
   .FMAC_TX_PKT_CNT(__ILA_SO_FMAC_TX_PKT_CNT),
   .FMAC_RX_PKT_CNT_LO(__ILA_SO_FMAC_RX_PKT_CNT_LO),
   .FMAC_RX_PKT_CNT_HI(__ILA_SO_FMAC_RX_PKT_CNT_HI),
   .FMAC_TX_BYTE_CNT(__ILA_SO_FMAC_TX_BYTE_CNT),
   .FMAC_RX_BYTE_CNT_LO(__ILA_SO_FMAC_RX_BYTE_CNT_LO),
   .FMAC_RX_BYTE_CNT_HI(__ILA_SO_FMAC_RX_BYTE_CNT_HI),
   .lmac_read_reg_cycle_cnt(__ILA_SO_lmac_read_reg_cycle_cnt),
   .lmac_read_reg_cache_val(__ILA_SO_lmac_read_reg_cache_val),
   .__COUNTER_start__n3()
);
LMAC_CORE_TOP m1(
    .FIFO_OV_IPEND(FIFO_OV_IPEND),
    .FMAC_REGDOUT(FMAC_REGDOUT),
    .SYS_ADDR(SYS_ADDR),
    .TCORE_MODE(TCORE_MODE),
    .clk(clk),
    .cs_fifo_empty(cs_fifo_empty),
    .cs_fifo_rd_en(cs_fifo_rd_en),
    .fail_over(fail_over),
    .fmac_ctrl(fmac_ctrl),
    .fmac_ctrl1(fmac_ctrl1),
    .fmac_rxd_en(fmac_rxd_en),
    .fmac_speed(fmac_speed),
    .gige_clk(gige_clk),
    .gmii_rx_dv(gmii_rx_dv),
    .gmii_rxc(gmii_rxc),
    .gmii_rxd(gmii_rxd),
    .gmii_tx_en(gmii_tx_en),
    .gmii_tx_vld(gmii_tx_vld),
    .gmii_txc(gmii_txc),
    .gmii_txd(gmii_txd),
    .host_addr_reg(host_addr_reg),
    .ipcs_fifo_dout(ipcs_fifo_dout),
    .mac_addr0(mac_addr0),
    .mac_pause_value(mac_pause_value),
    .mcast_saddr(mcast_saddr),
    .reg_rd_done(reg_rd_done),
    .reg_rd_start(reg_rd_start),
    .reset_(reset_),
    .rx_mac_ctrl(rx_mac_ctrl),
    .rx_mac_data(rx_mac_data),
    .rx_mac_empty(rx_mac_empty),
    .rx_mac_full_dbg(rx_mac_full_dbg),
    .rx_mac_rd(rx_mac_rd),
    .rx_mac_rd_cycle(rx_mac_rd_cycle),
    .rx_mac_usedw_dbg(rx_mac_usedw_dbg),
    .sfp_los(sfp_los),
    .tx_mac_data(tx_mac_data),
    .tx_mac_full(tx_mac_full),
    .tx_mac_usedw(tx_mac_usedw),
    .tx_mac_wr(tx_mac_wr),
    .xauiA_clk(xauiA_clk),
    .xauiA_linkup(xauiA_linkup)
);
endmodule
module lmac__DOT__READ_FMAC_TX_PKT_CNT_SINGLE(
__START__,
clk,
host_addr,
mac_ctrl,
mac_ctrl_1,
mac_rxv_en,
phy_rst,
reg_clk,
reg_read_start,
rst,
__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__,
__ILA_lmac_valid__,
link_up,
read_reg_done_out,
mac_reg_d_out,
FMAC_TX_PKT_CNT,
FMAC_RX_PKT_CNT_LO,
FMAC_RX_PKT_CNT_HI,
FMAC_TX_BYTE_CNT,
FMAC_RX_BYTE_CNT_LO,
FMAC_RX_BYTE_CNT_HI,
lmac_read_reg_cycle_cnt,
lmac_read_reg_cache_val,
__COUNTER_start__n3
);
input            __START__;
input            clk;
input     [15:0] host_addr;
input     [31:0] mac_ctrl;
input     [31:0] mac_ctrl_1;
input            mac_rxv_en;
input            phy_rst;
input            reg_clk;
input            reg_read_start;
input            rst;
output            __ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__;
output            __ILA_lmac_valid__;
output reg            link_up;
output reg            read_reg_done_out;
output reg     [31:0] mac_reg_d_out;
output reg     [31:0] FMAC_TX_PKT_CNT;
output reg     [31:0] FMAC_RX_PKT_CNT_LO;
output reg     [31:0] FMAC_RX_PKT_CNT_HI;
output reg     [31:0] FMAC_TX_BYTE_CNT;
output reg     [31:0] FMAC_RX_BYTE_CNT_LO;
output reg     [31:0] FMAC_RX_BYTE_CNT_HI;
output reg      [7:0] lmac_read_reg_cycle_cnt;
output reg     [31:0] lmac_read_reg_cache_val;
output reg      [7:0] __COUNTER_start__n3;
(* keep *) wire     [31:0] FMAC_RX_BYTE_CNT_HI_randinit;
(* keep *) wire     [31:0] FMAC_RX_BYTE_CNT_LO_randinit;
(* keep *) wire     [31:0] FMAC_RX_PKT_CNT_HI_randinit;
(* keep *) wire     [31:0] FMAC_RX_PKT_CNT_LO_randinit;
(* keep *) wire     [31:0] FMAC_TX_BYTE_CNT_randinit;
(* keep *) wire     [31:0] FMAC_TX_PKT_CNT_randinit;
wire            __ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__;
wire            __ILA_lmac_valid__;
wire            __START__;
wire            clk;
wire     [15:0] host_addr;
(* keep *) wire            link_up_randinit;
(* keep *) wire     [31:0] lmac_read_reg_cache_val_randinit;
(* keep *) wire      [7:0] lmac_read_reg_cycle_cnt_randinit;
wire     [31:0] mac_ctrl;
wire     [31:0] mac_ctrl_1;
(* keep *) wire     [31:0] mac_reg_d_out_randinit;
wire            mac_rxv_en;
wire            n0____DOLLAR__105;
wire            n1____DOLLAR__100;
wire            n2____DOLLAR__107;
wire            phy_rst;
(* keep *) wire            read_reg_done_out_randinit;
wire            reg_clk;
wire            reg_read_start;
wire            rst;
assign __ILA_lmac_valid__ = 1'b1 ;
assign n0____DOLLAR__105 =  ( reg_read_start ) == ( 1'b1 )  ;
assign n1____DOLLAR__100 =  ( host_addr ) == ( 16'd4128 )  ;
assign n2____DOLLAR__107 =  ( n0____DOLLAR__105 ) & (n1____DOLLAR__100 )  ;
assign __ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__ = n2____DOLLAR__107 ;
always @(posedge clk) begin
   if(rst) begin
       link_up <= link_up_randinit ;
       read_reg_done_out <= read_reg_done_out_randinit ;
       mac_reg_d_out <= mac_reg_d_out_randinit ;
       FMAC_TX_PKT_CNT <= FMAC_TX_PKT_CNT_randinit ;
       FMAC_RX_PKT_CNT_LO <= FMAC_RX_PKT_CNT_LO_randinit ;
       FMAC_RX_PKT_CNT_HI <= FMAC_RX_PKT_CNT_HI_randinit ;
       FMAC_TX_BYTE_CNT <= FMAC_TX_BYTE_CNT_randinit ;
       FMAC_RX_BYTE_CNT_LO <= FMAC_RX_BYTE_CNT_LO_randinit ;
       FMAC_RX_BYTE_CNT_HI <= FMAC_RX_BYTE_CNT_HI_randinit ;
       lmac_read_reg_cycle_cnt <= lmac_read_reg_cycle_cnt_randinit ;
       lmac_read_reg_cache_val <= lmac_read_reg_cache_val_randinit ;
       __COUNTER_start__n3 <= 0;
   end
   else if(__START__ && __ILA_lmac_valid__) begin
       if ( __ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__ ) begin 
           __COUNTER_start__n3 <= 1; end
       else if( (__COUNTER_start__n3 >= 1 ) && ( __COUNTER_start__n3 < 255 )) begin
           __COUNTER_start__n3 <= __COUNTER_start__n3 + 1; end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           link_up <= link_up ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           read_reg_done_out <= 1'b1 ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           mac_reg_d_out <= FMAC_TX_PKT_CNT ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           FMAC_TX_PKT_CNT <= FMAC_TX_PKT_CNT ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           FMAC_RX_PKT_CNT_LO <= FMAC_RX_PKT_CNT_LO ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           FMAC_RX_PKT_CNT_HI <= FMAC_RX_PKT_CNT_HI ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           FMAC_TX_BYTE_CNT <= FMAC_TX_BYTE_CNT ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           FMAC_RX_BYTE_CNT_LO <= FMAC_RX_BYTE_CNT_LO ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           FMAC_RX_BYTE_CNT_HI <= FMAC_RX_BYTE_CNT_HI ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           lmac_read_reg_cycle_cnt <= lmac_read_reg_cycle_cnt ;
       end
       if (__ILA_lmac_decode_of_READ_FMAC_TX_PKT_CNT_SINGLE__) begin
           lmac_read_reg_cache_val <= lmac_read_reg_cache_val ;
       end
   end
end
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/10ps
// synopsys translate_on

module LMAC_CORE_TOP 
		(
		
		clk,				//i-1	250 Mhz		// changed to 125 MHz - 7 june 2018		
		xauiA_clk,			//i-1	156.25 Mhz  // changed to 125 MHz - 7 june 2018
		gige_clk,			//i-1	125MHz
		reset_,				//i-1 	FMAC specific reset
		                
		fmac_speed,		    //i, 1G, 23jul18
		                
		TCORE_MODE	,		//i-1, Always tie to 1		   

		// Interface to TX PATH
		tx_mac_wr,			// i-1
		tx_mac_data,		// i-64
		tx_mac_full,		// o-1
		tx_mac_usedw,		// o-13
		
		// Interface to RX PATH
		rx_mac_data,		// o-64
		rx_mac_ctrl,		//o-8, rsvd, pkt_end, pkt_start
		rx_mac_empty,		// o-1
		rx_mac_rd,			// i-1
		rx_mac_rd_cycle,	// i-1, from EXTR
		
		//for field debug
		rx_mac_full_dbg,	//o-1
		rx_mac_usedw_dbg,	//o-12
		
		//for pre_CS/parser (I/F to RX Path/EXTR)
		cs_fifo_rd_en 	,	//i-1
		cs_fifo_empty 	,	//o-1
		ipcs_fifo_dout	,	//o-64
		
        //gige_gmii 11 July 2018
		gmii_txd, 
		gmii_txc,
		gmii_tx_en,			//12 july 2018
		gmii_tx_vld,		//17 july 2018  
                        	
		xauiA_linkup,		// o-1, link up for either 10G or 10G mode
		
		// From central decoder	
		host_addr_reg,		// i-16
		SYS_ADDR,			//i-4, system assigned addr for the FMAC
		
		// From mac_register
		fail_over,			// i-1
		fmac_ctrl,			// i-32
		fmac_ctrl1,			// i-32
		
		fmac_rxd_en	,		//i-1, 13jul11
		
		mac_pause_value,	// i-32
		mac_addr0, 			// i-48
		mcast_saddr, 		// i-48
		
		reg_rd_start,		// i-1
		reg_rd_done,		// i-1
		
		// To mac_register
		FMAC_REGDOUT,		// o-32
		FIFO_OV_IPEND,		// o-1

		//gige_rx_gmii signals 16jul2018
		gmii_rxd,			//i-8
		gmii_rxc,			//i-1
		gmii_rx_dv,			//i-1

		sfp_los				//i-1, assign to zero   
			
	);
	
// Clock and Reset
input			clk;				// 250 Mhz
input			xauiA_clk; 			// 156.25 Mhz
input			gige_clk;
input			reset_;

input 	[1:0]	fmac_speed;			//i, 1G, 23jul18

input			TCORE_MODE;

// Interface to TX PATH
input			tx_mac_wr;
input 	[63:0]	tx_mac_data;
output			tx_mac_full;
output 	[12:0]	tx_mac_usedw;
		
// Interface to RX PATH
output 	[63:0]	rx_mac_data;
output	[7:0]	rx_mac_ctrl;
output 			rx_mac_empty;
input			rx_mac_rd;
input			rx_mac_rd_cycle;

//for field debug
output			rx_mac_full_dbg;
output	[11:0]	rx_mac_usedw_dbg;
	
//for pattern search (I/F to RX Path/EXTR)
input			cs_fifo_rd_en 	;	//i-1
output			cs_fifo_empty 	;	
output	[63:0]	ipcs_fifo_dout	;		
 
//gige_gmii 11 July 2018
output	[7:0]	gmii_txd; 
output 			gmii_txc;
output 			gmii_tx_en;			//12 july 2018
output 			gmii_tx_vld;		//17 july 2018    
                                    
output			xauiA_linkup;		// to LED on board 

// From central decoder
input 	[15:0]	host_addr_reg;
input	[3:0]	SYS_ADDR;
		
// From mac_register
input			fail_over;
input 	[31:0]	fmac_ctrl;
input 	[31:0]	fmac_ctrl1;
      	
input			fmac_rxd_en	;
      	
input 	[31:0]	mac_pause_value;	// [31:16] = tx_pause_value to send a pause frame, [15:0] = rx_pause_value (not implement)
input 	[47:0]	mac_addr0;			// mac_addr to check in non-promiscuous mode
input 	[47:0]  mcast_saddr;

input			reg_rd_start;
input			reg_rd_done;
		
// To mac_register
output 	[31:0]	FMAC_REGDOUT;
output			FIFO_OV_IPEND;

//gige_rx_gmii signals 16jul2018
input [7:0]		gmii_rxd;			//i-8
input			gmii_rxc;			//i-1
input			gmii_rx_dv;			//i-1
                           
input			sfp_los;			//i-1, assign to zero   

parameter		FMAC_ID = 10;

wire			loopback_en	= fmac_ctrl[2];		// i-1, =1 for loopback
	
wire			cs_fifo_rd_en 	;				// i-1
wire			cs_fifo_empty 	;		
wire	[63:0]	ipcs_fifo_dout	;				//o-64 {cs_tsum 3, 2, 1, 0}
                                           	
wire 	[31:0] 	FMAC_TX_PKT_CNT;
wire 	[31:0] 	FMAC_RX_PKT_CNT_LO;
wire 	[31:0] 	FMAC_RX_PKT_CNT_HI;
wire 	[31:0]	FMAC_TX_BYTE_CNT;
wire 	[31:0] 	FMAC_RX_BYTE_CNT_LO;
wire 	[31:0] 	FMAC_RX_BYTE_CNT_HI;
wire 	[31:0]	FMAC_RX_UNDERSIZE_PKT_CNT;
wire 	[31:0]	FMAC_RX_CRC_ERR_CNT;
wire 	[31:0]  FMAC_DCNT_OVERRUN;
wire 	[31:0]  FMAC_DCNT_LINK_ERR;
wire 	[31:0]	FMAC_PKT_CNT_OVERSIZE;
wire 	[31:0]	FMAC_PKT_CNT_JABBER;
wire 	[31:0]	FMAC_PKT_CNT_FRAGMENT;
wire 	[31:0]	RAW_FRAME_CNT;

wire	[31:0]	BAD_FRAMESOF_CNT ;

wire	[31:0]	STAT_GROUP_LO_DOUT	;			//o-32
wire	[31:0]	STAT_GROUP_HI_DOUT	;		    //o-32
wire	[9:0]	STAT_GROUP_addr		;			//i-10
wire			STAT_GROUP_sel	;
wire			fmac_rx_clr_en	;

reg				xauiA_linkup;
wire			linkup_10g;
wire			linkup_1g;

wire			reg_rd_start;
wire			reg_rd_done;

wire 	[07:0] 	rxc_reorder;
wire 	[63:0] 	rxd_reorder;

wire			br_sof4 ;

reg				tx_auto_clr_en;
reg				rx_auto_clr_en;
reg		[31:0]	fmac_ctrl_dly;
reg		[31:0]	fmac_ctrl1_dly;

wire			write_all_SW			= fmac_ctrl1_dly[18] ;		//default to 0
wire			soft_reconfig_reset		= fmac_ctrl1_dly[19] ;
wire	[2:0]	reconfig_mode_sel_SW 	= fmac_ctrl1_dly[22:20];



//gige_rx_gmii
wire	[63:0]	gige_rx_dout;
wire	[7:0]	gige_rx_cout;


reg			xaui_mode;				//	= (fmac_speed == 2'b00);


always @(posedge clk)
	begin
	
	tx_auto_clr_en			<=	fmac_ctrl[6];
	rx_auto_clr_en			<=	fmac_ctrl[7];
		//rebuffering
	fmac_ctrl_dly			<=	fmac_ctrl	;
	fmac_ctrl1_dly[31:18]	<=	fmac_ctrl1[31:18]	;
	fmac_ctrl1_dly[17:16]	<=	2'b00	;
	fmac_ctrl1_dly[15:0]	<=	fmac_ctrl1[15:0]	;
	
	end

			  		
always @ (posedge xauiA_clk)
begin

	xaui_mode	= (fmac_speed == 2'b00);	  //may need to be on coreclkout domain

	xauiA_linkup		<= 
		xaui_mode ? linkup_10g :
		linkup_1g	;
		
		
end



tcore_fmac_core #(FMAC_ID) core(

	// clock & reset
	.usr_clk  			(clk),       			// i-1	125 Mhz    
	.xaui_clk 			(xauiA_clk),  			// i-1	125 Mhz    
	.usr_rst_ 			(reset_),  				// i-1   			
	.fmac_speed 		(fmac_speed)    ,   	// i-2
	            		                    	
	.TCORE_MODE 		(TCORE_MODE),    		// i-1 	
	
	// register config
	.tx_xo_en			(fmac_ctrl[0]),			// i-1
	.rx_xo_en			(fmac_ctrl[1]),			// i-1   
	.bcast_en			(fmac_ctrl[11]),		// i-1  
	.prom_mode			(fmac_ctrl[4]),   		// i-1  
	.mac_addr0			(mac_addr0),    		// i-48 
	.mcast_en			(1'b0),                	// i-1 filter not needed for TCP codes
	.mcast_saddr		(mcast_saddr),			// i-48
	.rx_size			(12'h100),        		// i-12
	.rx_check_crc 		(fmac_ctrl[3]),   		// i-1 , CRC_EN bit
	
	// txfifo interface
	.txfifo_din 		(tx_mac_data),    		// i-64
	.txfifo_wr_en		(tx_mac_wr),    		// i-1 
	.txfifo_full 		(tx_mac_full),   		// o-1 
	.txfifo_usedw 		(tx_mac_usedw), 		// o-13
	
	// tx_encap interface
	.mac_pause_value	(mac_pause_value), 		// i-32
	.tx_b2b_dly			(fmac_ctrl[9:8]),		// i-2
	
	// rxfifo interface
	.rxfifo_rd_cycle 	(rx_mac_rd_cycle),     	// i-1 
	.rxfifo_rd_en 		(rx_mac_rd),     		// i-1 
	.rxfifo_dout 		(rx_mac_data),    		// o-64
	.rxfifo_ctrl_dout	(rx_mac_ctrl),			// o-8
	.rxfifo_empty 		(rx_mac_empty),  		// o-1  (rdempty 250MHz)
	
	//for debug
	.rxfifo_full_dbg	(rx_mac_full_dbg),		//o-1
	.rxfifo_usedw_dbg	(rx_mac_usedw_dbg),		//o-12
	
	//not used
	.drx_pkt_data 		(),    					//o-64	     
	.drx_pkt_start 		(),     				//o-1		     
	.drx_pkt_end 		(),     				//o-1		     
	.drx_pkt_we 		(),     				//o-1		     
	.drx_pkt_beat_bcnt 	(),  					//o-3	 
	.drx_pkt_be 		(),     				//o-8	 
	.drx_crc32 			(),     				//o-32	
	.drx_crc_vld 		(),     				//o-1		     
	.drx_crc_err 		(),     				//o-1		     
	.drx_crc_err_dly1 	(),     				//o-1		     
	
	//pre-parser FIFO
	.cs_fifo_rd_en		(cs_fifo_rd_en),		//i-1
	.ipcs_fifo_dout		(ipcs_fifo_dout),		//o-64, {32'b0, fpseudo, fast_ipsum}
	.cs_fifo_empty		(cs_fifo_empty),		//o-1, for EXTR	
	    
	// rx_xgmii            	
	.xgmii_rxc			(rxc_reorder), 			//i-8    
	.xgmii_rxd			(rxd_reorder), 			//i-64    
	.xgmii_rxp			(8'h00),       			//i-8, intended for PORT ID but not used (use fmac_id) 
                         	
	.br_sof4			(br_sof4),				//i-4
                         	
	.fmac_ctrl1_dly		(fmac_ctrl1_dly),		//i-32
	.fmac_rxd_en		(fmac_rxd_en),			//i-1
	    
	//gige_gmii 11 July 2018            	
	.gmii_txd 			(gmii_txd), 
	.gmii_txc 			(gmii_txc),
	.gmii_tx_en 		(gmii_tx_en),			//12 july 2018
	.gmii_tx_vld 		(gmii_tx_vld),			//17 july 2018
	         
	//11 July 2018 GMII       	
	.linkup_1g			(xauiA_linkup),			// i-1
	.gige_clk 			(gige_clk),				// i-1


	
	// to mac_register.v
	.FMAC_TX_PKT_CNT	(FMAC_TX_PKT_CNT),  	// o-32
	.FMAC_RX_PKT_CNT_LO	(FMAC_RX_PKT_CNT_LO),   // o-32
	.FMAC_RX_PKT_CNT_HI	(FMAC_RX_PKT_CNT_HI),   // o-32
	
	.FMAC_TX_BYTE_CNT	(FMAC_TX_BYTE_CNT),		// o-32
	.FMAC_RX_BYTE_CNT_LO(FMAC_RX_BYTE_CNT_LO),  // o-32
	.FMAC_RX_BYTE_CNT_HI(FMAC_RX_BYTE_CNT_HI),  // o-32
	
	.STAT_GROUP_LO_DOUT	(STAT_GROUP_LO_DOUT),	//o-32
	.STAT_GROUP_HI_DOUT	(STAT_GROUP_HI_DOUT),	//o-32
	.STAT_GROUP_addr	(STAT_GROUP_addr) ,		//i-10
	.STAT_GROUP_sel		(STAT_GROUP_sel) ,		//i-1
	.fmac_rx_clr_en		(fmac_rx_clr_en),		//i-1
	
	.FMAC_RX_UNDERSIZE_PKT_CNT	(FMAC_RX_UNDERSIZE_PKT_CNT),	// o-32	[CORE]
	.FMAC_RX_CRC_ERR_CNT		(FMAC_RX_CRC_ERR_CNT),			// o-32
	.FMAC_DCNT_OVERRUN			(FMAC_DCNT_OVERRUN),			// o-32
	.FMAC_DCNT_LINK_ERR			(FMAC_DCNT_LINK_ERR),			// o-32  
	.FMAC_PKT_CNT_OVERSIZE		(FMAC_PKT_CNT_OVERSIZE),		// o-32 
	.FIFO_OV_IPEND				(FIFO_OV_IPEND),				// o-1 
	 
	.FMAC_PKT_CNT_JABBER		(FMAC_PKT_CNT_JABBER),			// o-32		
	.FMAC_PKT_CNT_FRAGMENT		(FMAC_PKT_CNT_FRAGMENT)			// o-32	
	
);
	
tcore_byte_reordering byte_reordering(

	.clk250 			(clk), 			// i-1
	.xaui_clk 			(xauiA_clk), 	// i-1
	.reset_				(reset_),   	// i-1
	.fmac_rxd_en 		(fmac_rxd_en),	//i-1
	
	.xaui_mode			(xaui_mode),   	// i-1
	
	.data_in			(gige_rx_dout), // i-64
	.ctrl_in			(gige_rx_cout), // i-8
	
	.data_out			(rxd_reorder), 	// o-64		//-- use pkt_gen for simulation ???
	.ctrl_out			(rxc_reorder), 	// o-8		//-- use pkt_gen for simulation ???
	
	.br_sof4			(br_sof4),		//o-1, byte_reorder sof4
	
	.RAW_FRAME_CNT 		(RAW_FRAME_CNT ),		//o-32, 250MHz domain
	.BAD_FRAMESOF_CNT	(BAD_FRAMESOF_CNT ),	//o-32, 250MHz domain
	.init_done			(1'b1),					// i-1	//16aug18 kp
	.linkup				(linkup_10g),			// o-1, 10G link up, 
	
	.br_trig 			()				//o-1
	);
	
	
gige_rx gige_rx (
	
	.clk			(clk),				// i-1                                                                                                                                                
	.reset_			(reset_),			// i-1 
	.fmac_speed		(fmac_speed),		// i-2                                                                                                                                           
	                                                                                                                                                 
	.data_in_s2p	(gmii_rxd),			// i-8                                                                                                                                     
	.ctrl_in_s2p	(gmii_rxc),			// i-1                                                                                                                                     
	.pdet_in_s2p	(gmii_rxc),			// i-1		//same as ctrl_in 
	.gmii_rx_dv		(gmii_rx_dv),		// i-1                                                                                                                                        
	                                                                                                                                                 
	.loopback_en	(loopback_en),		// i-1   	//assign to zero                                                                                                                                
	.sfp_los		(sfp_los),			// i-1		//assign to zero                                                                                                                                   

	.gige_rx_dout	(gige_rx_dout),		// o-64
	.gige_rx_cout	(gige_rx_cout),     // o-8
	
	.linkup			(linkup_1g),	    // o-1
	
	.dbg			()
	
	);

	
	
fmac_register_if fmac_register_if(
	.clk						(clk),     					// i-1
    .reset_						(reset_),  					// i-1
                                                        	
    // Statistic Registers                              	
    	//REGULAR GROUP                                 	     	
    .fmac_ctrl_dly				(fmac_ctrl_dly)	,			//i-32
    .fmac_ctrl1					(fmac_ctrl1)	,			//i-32
                                                        	
    .FMAC_TX_PKT_CNT			(FMAC_TX_PKT_CNT),  		// i-32
    .FMAC_RX_PKT_CNT_LO			(FMAC_RX_PKT_CNT_LO),   	// i-32
    .FMAC_RX_PKT_CNT_HI			(FMAC_RX_PKT_CNT_HI),   	// i-32
                                                        	
    .FMAC_TX_BYTE_CNT			(FMAC_TX_BYTE_CNT),			// i-32
	.FMAC_RX_BYTE_CNT_LO		(FMAC_RX_BYTE_CNT_LO),  	// i-32
	.FMAC_RX_BYTE_CNT_HI		(FMAC_RX_BYTE_CNT_HI),  	// i-32
	
	.FMAC_RX_UNDERSIZE_PKT_CNT	(FMAC_RX_UNDERSIZE_PKT_CNT),	// i-32
	.FMAC_RX_CRC_ERR_CNT		(FMAC_RX_CRC_ERR_CNT),			// i-32
	.FMAC_DCNT_OVERRUN			(FMAC_DCNT_OVERRUN),			// i-32
	.FMAC_DCNT_LINK_ERR			(FMAC_DCNT_LINK_ERR),			// i-32
	.FMAC_PKT_CNT_OVERSIZE		(FMAC_PKT_CNT_OVERSIZE),		// i-32
	.FMAC_PHY_STAT				({31'h0, linkup_1g}),		// i-32		//16aug18			
	
	.FMAC_PKT_CNT_JABBER		(FMAC_PKT_CNT_JABBER),		// i-32	
	.FMAC_PKT_CNT_FRAGMENT		(FMAC_PKT_CNT_FRAGMENT),	// i-32
	.FMAC_RAW_FRAME_CNT			(RAW_FRAME_CNT),			// i-32
	.FMAC_BAD_FRAMESOF_CNT		(BAD_FRAMESOF_CNT),			// i-32

	//STATISTIC GROUP
	.STAT_GROUP_LO_DOUT			(STAT_GROUP_LO_DOUT),		//i-32
	.STAT_GROUP_HI_DOUT			(STAT_GROUP_HI_DOUT),		//i-32
	.STAT_GROUP_addr			(STAT_GROUP_addr),			//o-10
	.STAT_GROUP_sel				(STAT_GROUP_sel),			//o-1
	.fmac_rx_clr_en				(fmac_rx_clr_en),			//o-1
	
	// Interface to mac_register
	.reg_rd_start				(reg_rd_start),				// i-1
	.reg_rd_done				(reg_rd_done),				// i-1
	.host_addr_reg				(host_addr_reg),			// i-16
	.SYS_ADDR					(SYS_ADDR),					//i-4
	
	.rx_auto_clr_en				(rx_auto_clr_en),			//i-1
	.tx_auto_clr_en				(tx_auto_clr_en),			//i-1
	
	.FMAC_REGDOUT				(FMAC_REGDOUT)				// o-32
	
    );
        
    
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//

`timescale 1ns / 1ns


module br_sfifo4x32

(
			aclr,

			wrclk,  	  // Clk for writing data 
			wrreq,  	  // request to write
			data,   	  // Data coming in 
			wrfull, 	  // indicates fifo is full or not (To avoid overiding)
		            
		    rdclk,  	   // Clk for reading data 
			rdreq,  	   // Request to read from FIFO
			q, 	    	   // Data coming out 
			rdempty,	   // indicates fifo is empty or not (to avoid underflow)
			rdusedw 	   // number of slots currently in use for reading

);	 
    //setting default values.
	parameter WIDTH = 32,
			  DEPTH = 4,
			  PTR	= 2;
			  
			  
			input wire aclr;

			input  wire 				wrclk;     // Clk for writing data
			input  wire 				wrreq;     // request to write
			input  wire [WIDTH-1 : 0]	data;      // Data coming in
			output wire					wrfull;    // indicates fifo is full or not (To avoid overiding)

			input  wire 				rdclk;     // Clk for reading data 
			input  wire 				rdreq;     // Request to read from FIFO
			output wire [WIDTH-1 : 0]	q; 	       // Data coming out
			output wire 				rdempty;   // indicates fifo is empty or not (to avoid underflow)
			output wire [PTR  : 0] 		rdusedw;   // number of slots currently in use for reading

			
			
	asynch_fifo	#(.WIDTH (WIDTH),
					  	  .DEPTH (DEPTH),
					 	  .PTR	 (PTR) )
 										
	asynch_br4x32		  (
			.reset_	(~aclr),
			
			.wrclk	(wrclk),		  // Clk to write data
			.wren	(wrreq),	 	  // write enable
			.datain	(data),			  // write data
			.wrfull	(wrfull),		  // indicates fifo is full or not (To avoid overiding)
			.wrempty(),				  // indicates fifo is empty or not (to avoid underflow)
			.wrusedw(),				  // wrusedw -number of locations filled in fifo

			.rdclk	(rdclk),		  // i-1, Clk to read data
			.rden	(rdreq),		  // i-1, read enable of data FIFO
			.dataout(q),			  // Dataout of data FIFO
			.rdfull	(),				  // indicates fifo is full or not (To avoid overiding) (Not used)
			.rdempty(rdempty),		  // indicates fifo is empty or not (to avoid underflow)
			.rdusedw(rdusedw),		  // rdusedw -number of locations filled in fifo (not used )

			.dbg()

		 );
		 
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/1ps
// synopsys translate_on


module bsh32_dn_88 (
	shft,	 //i,
	din,	 //i,
	dout	 //o,
);

   	input  [1:0]                  shft; 
   	input  [87:0]                 din; 
   	output [87:0]                 dout; 
   	
   	wire [87:0]                   shft_data_s0;
   	wire [87:0]                   shft_data_s1;

 	assign shft_data_s0[88-1:0] = shft[0] ? (din >> 32) : din[88-1:0];
 	assign shft_data_s1[88-1:0] = shft[1] ? (shft_data_s0 >> 64) : shft_data_s0;

	//signal remap
	assign dout[88-1:0] = shft_data_s1; 

endmodule


//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/1ps
// synopsys translate_on


module bsh8_dn_64 (
   shft,		  //i,
   din,			  //i,
   dout			  //o,
);

  	input  [2:0]                  shft; 
  	input  [63:0]                 din; 
  	output [63:0]                 dout; 
  	
  	wire [63:0]                   shft_data_s0;

 	assign shft_data_s0 = (din >> {shft,3'd0});

 	//signal remap
	assign dout = shft_data_s0; 

endmodule


//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/10ps
// synopsys translate_on

module tcore_byte_reordering (
	clk250	,		//i-1
	xaui_clk,
	reset_,
	fmac_rxd_en	,	//i-1, 250MHz domain
	
	xaui_mode,		 //i-1
	
	data_in,		 //i-64
	ctrl_in,		 //i-8
	data_out,		//o-64
	ctrl_out,		//o-8
	br_sof4,		//o-1, special case of SOF & EOF at same time, may contain data
	
	RAW_FRAME_CNT,		//o-32, 250MHz domain
	BAD_FRAMESOF_CNT,	//o-32, 250MHz domain
	init_done,			//i-1
	linkup,				//o-1
	
	br_trig
	
	);

input clk250;
input xaui_clk;
input reset_;
input fmac_rxd_en;				   //register interface signal

input xaui_mode;

input 	[63:0]	data_in;		   //input data
input 	[07:0]	ctrl_in;		   //input ctrl
output	[63:0]	data_out;		   // shifted data out
output	[07:0]	ctrl_out;		   // shifted control out
output			br_sof4;		   // indicates outgoing data is having sof4

output	[31:0]	RAW_FRAME_CNT ;	   //Frame counter
output	[31:0]	BAD_FRAMESOF_CNT ; // bad frames count
input	init_done;
output	linkup;						 //for 10G mode only (not used in 1G mode)

output	br_trig ;

wire	br_trig = 0;
reg		unknown_sof_sticky ;

parameter [2:0]
	LINK_FAIL = 3'h1,
	LINK_RCVR = 3'h2,
	LINK_GOOD = 3'h4;
reg [2:0] state;

reg [4:0] link_cnt;

reg		[63:0]	data_out ;		   //output data
reg		[63:0]	data_in_dly ;	   //buffer input data
reg		[07:0]	ctrl_in_dly ;	   //buffer input control
reg		[07:0]	ctrl_out ;		   // output control
reg				br_sof4 ;		   // pulse indicating outgoing data is sof 4.
reg				sof4_cycle ;	   // pulse indicating sof4 data

reg				shift;			   // Event indicating shifting of data is in process
reg				eof0 ;			   // end of frame in 0-3bytes 
reg				eof1 ;			   // end of frame in 4-7Bytes
reg				linkup;
reg				link_bad;
reg				link_ok;
wire			link_fault;
assign			link_fault = !init_done || (data_in_dly[39:32] == 8'h9C && ctrl_in_dly[4] == 1'b1) || 
										   (data_in_dly[7:0]   == 8'h9C && ctrl_in_dly[0] == 1'b1);
										   

wire 	seq0 ;
assign 	seq0 = (data_in[7:0] == 8'h9C && ctrl_in[0] == 1'b1) ;
wire	seq1 ;
assign	seq1 = (data_in[39:32] == 8'h9C && ctrl_in[4] == 1'b1) ;
										   
reg		sof0;					  // start of frame on 0th byte
reg		sof1;					  // start of frame on 1st byte
reg		sof2;					  // start of frame on 2nd byte
reg		sof3;					  // start of frame on 3rd byte
reg		sof4;					  // start of frame on 4th byte
reg		sof5;					  // start of frame on 5th byte
reg		sof6;					  // start of frame on 6th byte
reg		sof7;					  // start of frame on 7th byte
reg		has_sof;
reg		frame_done;
reg		fmac_rxd_en156 ;

reg		any_sof ;				  //having any sof
reg		any_eof ;
wire	eof	;					  // pulse indicating end of frame.
assign	eof	= eof0 | eof1 ;

reg		bad_frame ;
reg		bad_frame_noeof ;

reg		[31:0]	raw_sof_cnt156 ;
reg		[31:0]	raw_eof_cnt156 ;
reg		[31:0]	raw_frame_cnt156 ;
reg		[31:0]	RAW_FRAME_CNT ;

reg		[31:0]	BAD_FRAMESOF_CNT ;
reg		[31:0]	bad_framesof_cnt156 ;		

wire	rf_sfifo_full ;
wire	rf_sfifo_empty ;
wire	[31:0]	rf_sfifo_dout ;

wire	bfsof_sfifo_full ;
wire	bfsof_sfifo_empty ;
wire	[31:0]	bfsof_sfifo_dout ;


always @ (posedge xaui_clk)
begin
		data_in_dly	<=	data_in ;
		
		ctrl_in_dly[3:0] <= seq0? 4'hf : ctrl_in[3:0] ; 
		ctrl_in_dly[7:4] <= seq1? 4'hf : ctrl_in[7:4] ;	  
		
		fmac_rxd_en156	<= fmac_rxd_en ;
end

always @ (posedge xaui_clk)
begin
	if (!reset_)
	//initialize all registers to zero
	begin
		shift		<=	1'b0;
		eof0      	<=	1'b0;
		eof1		<=	1'b0;
		linkup		<=	1'b0;
		link_bad	<=	1'b0;
		link_ok		<=	1'b0;
		
		sof0		<=  1'b0;
		sof1		<=  1'b0;
		sof2		<=  1'b0;
		sof3		<=  1'b0;
		sof4		<=	1'b0;
		sof5		<=	1'b0;
		sof6		<=	1'b0;
		sof7		<=	1'b0;
		
		br_sof4		<=	1'b0;
		sof4_cycle	<=	1'b0;
		
		has_sof		<=	1'b0;
		frame_done	<=	1'b0;
		
		bad_framesof_cnt156	<=	32'h0;
		raw_frame_cnt156	<=	32'h0;
		raw_sof_cnt156		<=	32'h0;
		raw_eof_cnt156		<=	32'h0;
		
	end
	
	else
	begin						
		sof4_cycle	<=	
			sof4 ? 1'b1 :
			eof  ? 1'b0 :
			sof4_cycle ;
		
		//shift the data to right align for XGMII if see SOF4 type 
		shift		<= 	(
				(data_in[39:32]==8'hFB) && (ctrl_in[4] == 1'b1))? 1'b1 :
				( ( ((eof0 ||eof1) & !sof4) || (sof0 & !sof4) )? 1'b0 :
				  shift
				);
		//detect End of Frame on the lower 32 bit
		eof0      	<=  (ctrl_in[0] && (data_in[7:0] == 8'hFD)) || (ctrl_in[1] && (data_in[15:8] == 8'hFD)) || 
						(ctrl_in[2] && (data_in[23:16] == 8'hFD)) || (ctrl_in[3] && (data_in[31:24] == 8'hFD));
		  //detect End of Frame on the upper 32 bits
		eof1      	<=  (ctrl_in[4] && (data_in[39:32] == 8'hFD)) || (ctrl_in[5] && (data_in[47:40] == 8'hFD)) || 
						(ctrl_in[6] && (data_in[55:48] == 8'hFD)) || (ctrl_in[7] && (data_in[63:56] == 8'hFD));	
						
		linkup		<=	state[2];
		link_bad	<=	link_fault;
		link_ok		<=	(link_cnt == 5'd0);
		
		sof0		<=  (data_in[7:0]==8'hFB) & ctrl_in[0];
		sof4		<=	(data_in[39:32]==8'hFB) & ctrl_in[4];
		
		br_sof4	<= sof4 ;
		
		// sof checking mechanism
		sof1		<=  (data_in[15:8]==8'hFB)  & ctrl_in[1];
		sof2		<=  (data_in[23:16]==8'hFB) & ctrl_in[2];
		sof3		<=  (data_in[31:24]==8'hFB) & ctrl_in[3];
		
		sof5		<=  (data_in[47:40]==8'hFB) & ctrl_in[5];
		sof6		<=  (data_in[55:48]==8'hFB) & ctrl_in[6];
		sof7		<=  (data_in[63:56]==8'hFB) & ctrl_in[7];
		
//check whether the input data has valid sof.		
		has_sof		<=	  (sof0 | sof4) ? 1'b1: 
						( (eof0 | eof1) ? 1'b0 :
						has_sof );		
//pulse when frame done transmitting.						
		frame_done	<=
						frame_done ? 1'b0 :
						(eof0 | eof1) & has_sof ? 1'b1 :
						1'b0 ;
//bad frame counter	
		bad_framesof_cnt156	<=	
			!fmac_rxd_en156 ? 32'h0 :		
			(bad_frame | bad_frame_noeof) ? bad_framesof_cnt156 + 8'd1 :
			bad_framesof_cnt156;
//raw frame counter			
		raw_frame_cnt156	<=	
			!fmac_rxd_en156 ? 32'h0 :
			frame_done ? raw_frame_cnt156 + 8'd1 :
			raw_frame_cnt156;
			
		raw_sof_cnt156	<=	
			!fmac_rxd_en156 ? 32'h0 :
			any_sof ? raw_sof_cnt156 + 8'd1 :
			raw_sof_cnt156;
			
		raw_eof_cnt156	<=	
			!fmac_rxd_en156 ? 32'h0 :
			any_eof ? raw_eof_cnt156 + 8'd1 :
			raw_eof_cnt156;
			
		
	end
end

always @(posedge xaui_clk)
begin
	if (!reset_)
		begin
			data_out		<= 64'h0707070707070707;
			ctrl_out		<= 8'hff;
		end
	
	else
		begin
			data_out	<= 
				!xaui_mode ? data_in :
				
				//1st shift qwd is special due to EOF & SOF4 at same time
				(sof4_cycle & eof0 )? {32'h07070707, 32'h07070707} :
				(shift & sof4)? {32'h07070707, data_in_dly[31:0]} :
				
				(shift & eof0)? {32'h07070707, 32'h07070707} : 
				(shift & eof1)? {32'h07070707, data_in_dly[63:32]} : 
// shift is not first and last qwd				
				(shift )? {data_in[31:0], data_in_dly[63:32]} : 
				data_in_dly ;	
			

				//output control 				
			ctrl_out[3:0]	<= 
				!xaui_mode ? ctrl_in[3:0] :
				//shift if sof4 detected
				(sof4_cycle & eof0)? {4'hf} :
				(shift & sof4)? { ctrl_in_dly[3:0]} : 
				
				//shift during ending time (if more SOF4 coming, it must have priority above)
				(shift & eof0)? {4'hf} :
				(shift & eof1)? {ctrl_in_dly[7:4]} : 
			
				(shift & !sof4 )? ctrl_in_dly[7:4] : 
				
				ctrl_in_dly[3:0] ;
			
			//output control upper bits	
			ctrl_out[7:4]	<= 
				!xaui_mode ? ctrl_in[7:4] :
			//shift for sof4	
				(sof4_cycle & eof0)? {4'hf } :
				(shift & sof4)     ? {4'hf } : 
				
				(shift & eof0)? {4'hf} :
				(shift & eof1)? {4'hf} : 
				
				(shift & seq0)? 4'hf : 
				
				(shift )? ctrl_in[3:0] : 
				
				ctrl_in_dly[7:4]  ;
		end
end


// LINKUP DETECTION FSM

always @ (posedge xaui_clk)
begin
	if (!reset_)
	begin
		state <= LINK_FAIL;
		link_cnt <= 5'd25;
	end
	
	else
	begin
		case (state)
		LINK_FAIL:
			begin
				state <= link_bad? LINK_FAIL : LINK_RCVR;
				link_cnt <= 5'd25;
			end
			
		LINK_RCVR:
			begin
				state <= link_bad? LINK_FAIL : (link_ok? LINK_GOOD : LINK_RCVR);
				link_cnt <= link_cnt - 5'd1;
			end
			
		LINK_GOOD:
			begin
				state <= link_bad? LINK_FAIL : LINK_GOOD;
				link_cnt <= 5'd25;
			end
			
		default: 
			state <= LINK_FAIL;
		endcase		
	end
end



br_sfifo4x32	rf_sfifo (

	.aclr		(!reset_ | !fmac_rxd_en156),         //i-1        
	.wrclk		(xaui_clk),                          //i-1, clk156
	.data		(raw_frame_cnt156 ),                 //i-32
	.wrreq		(!rf_sfifo_full),                    //i-1
	.rdclk		(clk250),                            //i-1
	.rdreq		(!rf_sfifo_empty),                   //i-1
	.q			(rf_sfifo_dout ),                    //o-32,
	.rdempty	(rf_sfifo_empty),                    //o-1
	.rdusedw	(),
	.wrfull		(rf_sfifo_full)                      //o-1
	
	);
	

always @ (posedge clk250)
	if (!reset_ | !fmac_rxd_en )
		begin
		RAW_FRAME_CNT		<=	32'h0;		
		end
	else
		begin
		RAW_FRAME_CNT		<=	rf_sfifo_dout ;		
		end
	

		
br_sfifo4x32	bfsof_sfifo (

	.aclr		(!reset_ | !fmac_rxd_en156),	 //i-1
	.wrclk		(xaui_clk),						 //i-1, clk156
	.data		({unknown_sof_sticky, bad_framesof_cnt156[30:0]} ),		//i-32
	.wrreq		(!bfsof_sfifo_full),	   //i-1
	.rdclk		(clk250),					//i-1
	.rdreq		(!bfsof_sfifo_empty),		//i-1
	.q			(bfsof_sfifo_dout ),		//o-32,
	.rdempty	(bfsof_sfifo_empty),		//o-1
	.rdusedw	(),							//o-2
	.wrfull		(bfsof_sfifo_full)			//o-1
	
	);

	
	
always @ (posedge clk250)
	if (!reset_ | !fmac_rxd_en )
		begin
		BAD_FRAMESOF_CNT		<=	32'h0;
		end
	else
		begin
		BAD_FRAMESOF_CNT		<=	bfsof_sfifo_dout ;
		end



always @ (posedge xaui_clk)
begin
	if (!reset_)
		begin
		
		bad_frame	<= 1'b0 ;		 //EOF but no SOF
		bad_frame_noeof	<= 1'b0 ;	 //frame has no EOF
		
		unknown_sof_sticky	<= 1'b0 ;
		any_sof	<= 1'b0 ;
		any_eof	<= 1'b0 ;
		
		end
	else
		begin
		//if eof and no sof
		bad_frame	<= 
			(eof0 | eof1) & !has_sof
			;
	//frame without eof		
		bad_frame_noeof	<= 
			(sof0 | sof1 | sof2 | sof3 |
			 sof4 | sof5 | sof6 | sof7 ) & has_sof
			;
	//if not sof0 and sof4		
		unknown_sof_sticky	<=
			(sof1 | sof2 | sof3 |
			 sof5 | sof6 | sof7 ) ? 1'b1 :
			 unknown_sof_sticky;
			 
		any_sof		<=
			(sof0 | sof1 | sof2 | sof3 |
			 sof4 | sof5 | sof6 | sof7 ) 
			;
		
		any_eof		<=
			eof0 | eof1
			;
			 
		end
		
end


endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/1ps
// synopsys translate_on


module crc32_d16s(
 input      [15:0] data,
 input      [31:0] seed,
 output     [31:0] crc
);

		 //registers decalarations
 reg [31:0] data_p0; 
 reg [31:0] seed_p0; 

		 //remap signal
 assign crc = data_p0 ^ seed_p0;


 always @(*) begin
  data_p0[0] = data[0] ^ data[6] ^ data[9] ^ data[10] ^ data[12];
 end 


 always @(*) begin
  data_p0[1] = data[0] ^ data[1] ^ data[6] ^ data[7] ^ data[9] ^ data[11] ^ data[12] ^ data[13];
 end 


 always @(*) begin
  data_p0[2] = data[0] ^ data[1] ^ data[2] ^ data[6] ^ data[7] ^ data[8] ^ data[9] ^ data[13] ^ data[14];
 end 


 always @(*) begin
  data_p0[3] = data[1] ^ data[2] ^ data[3] ^ data[7] ^ data[8] ^ data[9] ^ data[10] ^ data[14] ^ data[15];
 end 


 always @(*) begin
  data_p0[4] = data[0] ^ data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[8] ^ data[11] ^ data[12] ^ data[15];
 end 


 always @(*) begin
  data_p0[5] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13];
 end 


 always @(*) begin
  data_p0[6] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14];
 end 


 always @(*) begin
  data_p0[7] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[7] ^ data[8] ^ data[10] ^ data[15];
 end 


 always @(*) begin
  data_p0[8] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[8] ^ data[10] ^ data[11] ^ data[12];
 end 


 always @(*) begin
  data_p0[9] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[9] ^ data[11] ^ data[12] ^ data[13];
 end 


 always @(*) begin
  data_p0[10] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[9] ^ data[13] ^ data[14];
 end 


 always @(*) begin
  data_p0[11] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[9] ^ data[12] ^ data[14] ^ data[15];
 end 


 always @(*) begin
  data_p0[12] = data[0] ^ data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[9] ^ data[12] ^ data[13] ^ data[15];
 end 


 always @(*) begin
  data_p0[13] = data[1] ^ data[2] ^ data[3] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13] ^ data[14];
 end 


 always @(*) begin
  data_p0[14] = data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14] ^ data[15];
 end 


 always @(*) begin
  data_p0[15] = data[3] ^ data[4] ^ data[5] ^ data[7] ^ data[8] ^ data[9] ^ data[12] ^ data[15];
 end 


 always @(*) begin
  data_p0[16] = data[0] ^ data[4] ^ data[5] ^ data[8] ^ data[12] ^ data[13];
 end 


 always @(*) begin
  data_p0[17] = data[1] ^ data[5] ^ data[6] ^ data[9] ^ data[13] ^ data[14];
 end 


 always @(*) begin
  data_p0[18] = data[2] ^ data[6] ^ data[7] ^ data[10] ^ data[14] ^ data[15];
 end 


 always @(*) begin
  data_p0[19] = data[3] ^ data[7] ^ data[8] ^ data[11] ^ data[15];
 end 


 always @(*) begin
  data_p0[20] = data[4] ^ data[8] ^ data[9] ^ data[12];
 end 


 always @(*) begin
  data_p0[21] = data[5] ^ data[9] ^ data[10] ^ data[13];
 end 


 always @(*) begin
  data_p0[22] = data[0] ^ data[9] ^ data[11] ^ data[12] ^ data[14];
 end 


 always @(*) begin
  data_p0[23] = data[0] ^ data[1] ^ data[6] ^ data[9] ^ data[13] ^ data[15];
 end 


 always @(*) begin
  data_p0[24] = data[1] ^ data[2] ^ data[7] ^ data[10] ^ data[14];
 end 


 always @(*) begin
  data_p0[25] = data[2] ^ data[3] ^ data[8] ^ data[11] ^ data[15];
 end 


 always @(*) begin
  data_p0[26] = data[0] ^ data[3] ^ data[4] ^ data[6] ^ data[10];
 end 


 always @(*) begin
  data_p0[27] = data[1] ^ data[4] ^ data[5] ^ data[7] ^ data[11];
 end 


 always @(*) begin
  data_p0[28] = data[2] ^ data[5] ^ data[6] ^ data[8] ^ data[12];
 end 


 always @(*) begin
  data_p0[29] = data[3] ^ data[6] ^ data[7] ^ data[9] ^ data[13];
 end 


 always @(*) begin
  data_p0[30] = data[4] ^ data[7] ^ data[8] ^ data[10] ^ data[14];
 end 


 always @(*) begin
  data_p0[31] = data[5] ^ data[8] ^ data[9] ^ data[11] ^ data[15];
 end 


 always @(*) begin
 seed_p0[0] = seed[16] ^ seed[22] ^ seed[25] ^ seed[26] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[1] = seed[16] ^ seed[17] ^ seed[22] ^ seed[23] ^ seed[25] ^ seed[27] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[2] = seed[16] ^ seed[17] ^ seed[18] ^ seed[22] ^ seed[23] ^ seed[24] ^ seed[25] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[3] = seed[17] ^ seed[18] ^ seed[19] ^ seed[23] ^ seed[24] ^ seed[25] ^ seed[26] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[4] = seed[16] ^ seed[18] ^ seed[19] ^ seed[20] ^ seed[22] ^ seed[24] ^ seed[27] ^ seed[28] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[5] = seed[16] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[21] ^ seed[22] ^ seed[23] ^ seed[26] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[6] = seed[17] ^ seed[18] ^ seed[20] ^ seed[21] ^ seed[22] ^ seed[23] ^ seed[24] ^ seed[27] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[7] = seed[16] ^ seed[18] ^ seed[19] ^ seed[21] ^ seed[23] ^ seed[24] ^ seed[26] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[8] = seed[16] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[24] ^ seed[26] ^ seed[27] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[9] = seed[17] ^ seed[18] ^ seed[20] ^ seed[21] ^ seed[25] ^ seed[27] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[10] = seed[16] ^ seed[18] ^ seed[19] ^ seed[21] ^ seed[25] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[11] = seed[16] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[25] ^ seed[28] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[12] = seed[16] ^ seed[17] ^ seed[18] ^ seed[20] ^ seed[21] ^ seed[22] ^ seed[25] ^ seed[28] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[13] = seed[17] ^ seed[18] ^ seed[19] ^ seed[21] ^ seed[22] ^ seed[23] ^ seed[26] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[14] = seed[18] ^ seed[19] ^ seed[20] ^ seed[22] ^ seed[23] ^ seed[24] ^ seed[27] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[15] = seed[19] ^ seed[20] ^ seed[21] ^ seed[23] ^ seed[24] ^ seed[25] ^ seed[28] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[16] = seed[0] ^ seed[16] ^ seed[20] ^ seed[21] ^ seed[24] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[17] = seed[1] ^ seed[17] ^ seed[21] ^ seed[22] ^ seed[25] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[18] = seed[2] ^ seed[18] ^ seed[22] ^ seed[23] ^ seed[26] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[19] = seed[3] ^ seed[19] ^ seed[23] ^ seed[24] ^ seed[27] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[20] = seed[4] ^ seed[20] ^ seed[24] ^ seed[25] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[21] = seed[5] ^ seed[21] ^ seed[25] ^ seed[26] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[22] = seed[6] ^ seed[16] ^ seed[25] ^ seed[27] ^ seed[28] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[23] = seed[7] ^ seed[16] ^ seed[17] ^ seed[22] ^ seed[25] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[24] = seed[8] ^ seed[17] ^ seed[18] ^ seed[23] ^ seed[26] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[25] = seed[9] ^ seed[18] ^ seed[19] ^ seed[24] ^ seed[27] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[26] = seed[10] ^ seed[16] ^ seed[19] ^ seed[20] ^ seed[22] ^ seed[26];
 end 


 always @(*) begin
 seed_p0[27] = seed[11] ^ seed[17] ^ seed[20] ^ seed[21] ^ seed[23] ^ seed[27];
 end 


 always @(*) begin
 seed_p0[28] = seed[12] ^ seed[18] ^ seed[21] ^ seed[22] ^ seed[24] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[29] = seed[13] ^ seed[19] ^ seed[22] ^ seed[23] ^ seed[25] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[30] = seed[14] ^ seed[20] ^ seed[23] ^ seed[24] ^ seed[26] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[31] = seed[15] ^ seed[21] ^ seed[24] ^ seed[25] ^ seed[27] ^ seed[31];
 end 

endmodule 
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/1ps
// synopsys translate_on


module crc32_d24s(
 input      [23:0] data,
 input      [31:0] seed,
 output     [31:0] crc
);

//registers decalarations
 reg [31:0] data_p0; 
 reg [31:0] seed_p0; 

 //remap signal
 assign crc = data_p0 ^ seed_p0;


 always @(*) begin
  data_p0[0] = data[0] ^ data[6] ^ data[9] ^ data[10] ^ data[12] ^ data[16];
 end 


 always @(*) begin
  data_p0[1] = data[0] ^ data[1] ^ data[6] ^ data[7] ^ data[9] ^ data[11] ^ data[12] ^ data[13] ^ data[16] ^ data[17];
 end 


 always @(*) begin
  data_p0[2] = data[0] ^ data[1] ^ data[2] ^ data[6] ^ data[7] ^ data[8] ^ data[9] ^ data[13] ^ data[14] ^ data[16] ^ data[17] ^ data[18];
 end 


 always @(*) begin
  data_p0[3] = data[1] ^ data[2] ^ data[3] ^ data[7] ^ data[8] ^ data[9] ^ data[10] ^ data[14] ^ data[15] ^ data[17] ^ data[18] ^ data[19];
 end 


 always @(*) begin
  data_p0[4] = data[0] ^ data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[8] ^ data[11] ^ data[12] ^ data[15] ^ data[18] ^ data[19] ^ data[20];
 end 


 always @(*) begin
  data_p0[5] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13] ^ data[19] ^ data[20] ^ data[21];
 end 


 always @(*) begin
  data_p0[6] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14] ^ data[20] ^ data[21] ^ data[22];
 end 


 always @(*) begin
  data_p0[7] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[7] ^ data[8] ^ data[10] ^ data[15] ^ data[16] ^ data[21] ^ data[22] ^ data[23];
 end 


 always @(*) begin
  data_p0[8] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[8] ^ data[10] ^ data[11] ^ data[12] ^ data[17] ^ data[22] ^ data[23];
 end 


 always @(*) begin
  data_p0[9] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[9] ^ data[11] ^ data[12] ^ data[13] ^ data[18] ^ data[23];
 end 


 always @(*) begin
  data_p0[10] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[9] ^ data[13] ^ data[14] ^ data[16] ^ data[19];
 end 


 always @(*) begin
  data_p0[11] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[9] ^ data[12] ^ data[14] ^ data[15] ^ data[16] ^ data[17] ^ data[20];
 end 


 always @(*) begin
  data_p0[12] = data[0] ^ data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[9] ^ data[12] ^ data[13] ^ data[15] ^ data[17] ^ data[18] ^ data[21];
 end 


 always @(*) begin
  data_p0[13] = data[1] ^ data[2] ^ data[3] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13] ^ data[14] ^ data[16] ^ data[18] ^ data[19] ^ data[22];
 end 


 always @(*) begin
  data_p0[14] = data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14] ^ data[15] ^ data[17] ^ data[19] ^ data[20] ^ data[23];
 end 


 always @(*) begin
  data_p0[15] = data[3] ^ data[4] ^ data[5] ^ data[7] ^ data[8] ^ data[9] ^ data[12] ^ data[15] ^ data[16] ^ data[18] ^ data[20] ^ data[21];
 end 


 always @(*) begin
  data_p0[16] = data[0] ^ data[4] ^ data[5] ^ data[8] ^ data[12] ^ data[13] ^ data[17] ^ data[19] ^ data[21] ^ data[22];
 end 


 always @(*) begin
  data_p0[17] = data[1] ^ data[5] ^ data[6] ^ data[9] ^ data[13] ^ data[14] ^ data[18] ^ data[20] ^ data[22] ^ data[23];
 end 


 always @(*) begin
  data_p0[18] = data[2] ^ data[6] ^ data[7] ^ data[10] ^ data[14] ^ data[15] ^ data[19] ^ data[21] ^ data[23];
 end 


 always @(*) begin
  data_p0[19] = data[3] ^ data[7] ^ data[8] ^ data[11] ^ data[15] ^ data[16] ^ data[20] ^ data[22];
 end 


 always @(*) begin
  data_p0[20] = data[4] ^ data[8] ^ data[9] ^ data[12] ^ data[16] ^ data[17] ^ data[21] ^ data[23];
 end 


 always @(*) begin
  data_p0[21] = data[5] ^ data[9] ^ data[10] ^ data[13] ^ data[17] ^ data[18] ^ data[22];
 end 


 always @(*) begin
  data_p0[22] = data[0] ^ data[9] ^ data[11] ^ data[12] ^ data[14] ^ data[16] ^ data[18] ^ data[19] ^ data[23];
 end 


 always @(*) begin
  data_p0[23] = data[0] ^ data[1] ^ data[6] ^ data[9] ^ data[13] ^ data[15] ^ data[16] ^ data[17] ^ data[19] ^ data[20];
 end 


 always @(*) begin
  data_p0[24] = data[1] ^ data[2] ^ data[7] ^ data[10] ^ data[14] ^ data[16] ^ data[17] ^ data[18] ^ data[20] ^ data[21];
 end 


 always @(*) begin
  data_p0[25] = data[2] ^ data[3] ^ data[8] ^ data[11] ^ data[15] ^ data[17] ^ data[18] ^ data[19] ^ data[21] ^ data[22];
 end 


 always @(*) begin
  data_p0[26] = data[0] ^ data[3] ^ data[4] ^ data[6] ^ data[10] ^ data[18] ^ data[19] ^ data[20] ^ data[22] ^ data[23];
 end 


 always @(*) begin
  data_p0[27] = data[1] ^ data[4] ^ data[5] ^ data[7] ^ data[11] ^ data[19] ^ data[20] ^ data[21] ^ data[23];
 end 


 always @(*) begin
  data_p0[28] = data[2] ^ data[5] ^ data[6] ^ data[8] ^ data[12] ^ data[20] ^ data[21] ^ data[22];
 end 


 always @(*) begin
  data_p0[29] = data[3] ^ data[6] ^ data[7] ^ data[9] ^ data[13] ^ data[21] ^ data[22] ^ data[23];
 end 


 always @(*) begin
  data_p0[30] = data[4] ^ data[7] ^ data[8] ^ data[10] ^ data[14] ^ data[22] ^ data[23];
 end 


 always @(*) begin
  data_p0[31] = data[5] ^ data[8] ^ data[9] ^ data[11] ^ data[15] ^ data[23];
 end 


 always @(*) begin
 seed_p0[0] = seed[8] ^ seed[14] ^ seed[17] ^ seed[18] ^ seed[20] ^ seed[24];
 end 


 always @(*) begin
 seed_p0[1] = seed[8] ^ seed[9] ^ seed[14] ^ seed[15] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[21] ^ seed[24] ^ seed[25];
 end 


 always @(*) begin
 seed_p0[2] = seed[8] ^ seed[9] ^ seed[10] ^ seed[14] ^ seed[15] ^ seed[16] ^ seed[17] ^ seed[21] ^ seed[22] ^ seed[24] ^ seed[25] ^ seed[26];
 end 


 always @(*) begin
 seed_p0[3] = seed[9] ^ seed[10] ^ seed[11] ^ seed[15] ^ seed[16] ^ seed[17] ^ seed[18] ^ seed[22] ^ seed[23] ^ seed[25] ^ seed[26] ^ seed[27];
 end 


 always @(*) begin
 seed_p0[4] = seed[8] ^ seed[10] ^ seed[11] ^ seed[12] ^ seed[14] ^ seed[16] ^ seed[19] ^ seed[20] ^ seed[23] ^ seed[26] ^ seed[27] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[5] = seed[8] ^ seed[9] ^ seed[11] ^ seed[12] ^ seed[13] ^ seed[14] ^ seed[15] ^ seed[18] ^ seed[21] ^ seed[27] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[6] = seed[9] ^ seed[10] ^ seed[12] ^ seed[13] ^ seed[14] ^ seed[15] ^ seed[16] ^ seed[19] ^ seed[22] ^ seed[28] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[7] = seed[8] ^ seed[10] ^ seed[11] ^ seed[13] ^ seed[15] ^ seed[16] ^ seed[18] ^ seed[23] ^ seed[24] ^ seed[29] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[8] = seed[8] ^ seed[9] ^ seed[11] ^ seed[12] ^ seed[16] ^ seed[18] ^ seed[19] ^ seed[20] ^ seed[25] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[9] = seed[9] ^ seed[10] ^ seed[12] ^ seed[13] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[21] ^ seed[26] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[10] = seed[8] ^ seed[10] ^ seed[11] ^ seed[13] ^ seed[17] ^ seed[21] ^ seed[22] ^ seed[24] ^ seed[27];
 end 


 always @(*) begin
 seed_p0[11] = seed[8] ^ seed[9] ^ seed[11] ^ seed[12] ^ seed[17] ^ seed[20] ^ seed[22] ^ seed[23] ^ seed[24] ^ seed[25] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[12] = seed[8] ^ seed[9] ^ seed[10] ^ seed[12] ^ seed[13] ^ seed[14] ^ seed[17] ^ seed[20] ^ seed[21] ^ seed[23] ^ seed[25] ^ seed[26] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[13] = seed[9] ^ seed[10] ^ seed[11] ^ seed[13] ^ seed[14] ^ seed[15] ^ seed[18] ^ seed[21] ^ seed[22] ^ seed[24] ^ seed[26] ^ seed[27] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[14] = seed[10] ^ seed[11] ^ seed[12] ^ seed[14] ^ seed[15] ^ seed[16] ^ seed[19] ^ seed[22] ^ seed[23] ^ seed[25] ^ seed[27] ^ seed[28] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[15] = seed[11] ^ seed[12] ^ seed[13] ^ seed[15] ^ seed[16] ^ seed[17] ^ seed[20] ^ seed[23] ^ seed[24] ^ seed[26] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[16] = seed[8] ^ seed[12] ^ seed[13] ^ seed[16] ^ seed[20] ^ seed[21] ^ seed[25] ^ seed[27] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[17] = seed[9] ^ seed[13] ^ seed[14] ^ seed[17] ^ seed[21] ^ seed[22] ^ seed[26] ^ seed[28] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[18] = seed[10] ^ seed[14] ^ seed[15] ^ seed[18] ^ seed[22] ^ seed[23] ^ seed[27] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[19] = seed[11] ^ seed[15] ^ seed[16] ^ seed[19] ^ seed[23] ^ seed[24] ^ seed[28] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[20] = seed[12] ^ seed[16] ^ seed[17] ^ seed[20] ^ seed[24] ^ seed[25] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[21] = seed[13] ^ seed[17] ^ seed[18] ^ seed[21] ^ seed[25] ^ seed[26] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[22] = seed[8] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[22] ^ seed[24] ^ seed[26] ^ seed[27] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[23] = seed[8] ^ seed[9] ^ seed[14] ^ seed[17] ^ seed[21] ^ seed[23] ^ seed[24] ^ seed[25] ^ seed[27] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[24] = seed[0] ^ seed[9] ^ seed[10] ^ seed[15] ^ seed[18] ^ seed[22] ^ seed[24] ^ seed[25] ^ seed[26] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[25] = seed[1] ^ seed[10] ^ seed[11] ^ seed[16] ^ seed[19] ^ seed[23] ^ seed[25] ^ seed[26] ^ seed[27] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[26] = seed[2] ^ seed[8] ^ seed[11] ^ seed[12] ^ seed[14] ^ seed[18] ^ seed[26] ^ seed[27] ^ seed[28] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[27] = seed[3] ^ seed[9] ^ seed[12] ^ seed[13] ^ seed[15] ^ seed[19] ^ seed[27] ^ seed[28] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[28] = seed[4] ^ seed[10] ^ seed[13] ^ seed[14] ^ seed[16] ^ seed[20] ^ seed[28] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[29] = seed[5] ^ seed[11] ^ seed[14] ^ seed[15] ^ seed[17] ^ seed[21] ^ seed[29] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[30] = seed[6] ^ seed[12] ^ seed[15] ^ seed[16] ^ seed[18] ^ seed[22] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[31] = seed[7] ^ seed[13] ^ seed[16] ^ seed[17] ^ seed[19] ^ seed[23] ^ seed[31];
 end 

endmodule 
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/1ps
// synopsys translate_on


module crc32_d64(
 input      [63:0] data,
 output     [31:0] crc
);

//registers decalarations
 reg [31:0] data_p0; 

 //remap signal
 assign crc = data_p0;


 always @(*) begin
  data_p0[0] = data[0] ^ data[6] ^ data[9] ^ data[10] ^ data[12] ^ data[16] ^ data[24] ^ data[25] ^ data[26] ^ data[28] ^ data[29] ^ data[30] ^ data[31] ^ data[32] ^ data[34] ^ data[37] ^ data[44] ^ data[45] ^ data[47] ^ data[48] ^ data[50] ^ data[53] ^ data[54] ^ data[55] ^ data[58] ^ data[60] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[1] = data[0] ^ data[1] ^ data[6] ^ data[7] ^ data[9] ^ data[11] ^ data[12] ^ data[13] ^ data[16] ^ data[17] ^ data[24] ^ data[27] ^ data[28] ^ data[33] ^ data[34] ^ data[35] ^ data[37] ^ data[38] ^ data[44] ^ data[46] ^ data[47] ^ data[49] ^ data[50] ^ data[51] ^ data[53] ^ data[56] ^ data[58] ^ data[59] ^ data[60] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[2] = data[0] ^ data[1] ^ data[2] ^ data[6] ^ data[7] ^ data[8] ^ data[9] ^ data[13] ^ data[14] ^ data[16] ^ data[17] ^ data[18] ^ data[24] ^ data[26] ^ data[30] ^ data[31] ^ data[32] ^ data[35] ^ data[36] ^ data[37] ^ data[38] ^ data[39] ^ data[44] ^ data[51] ^ data[52] ^ data[53] ^ data[55] ^ data[57] ^ data[58] ^ data[59];
 end 


 always @(*) begin
  data_p0[3] = data[1] ^ data[2] ^ data[3] ^ data[7] ^ data[8] ^ data[9] ^ data[10] ^ data[14] ^ data[15] ^ data[17] ^ data[18] ^ data[19] ^ data[25] ^ data[27] ^ data[31] ^ data[32] ^ data[33] ^ data[36] ^ data[37] ^ data[38] ^ data[39] ^ data[40] ^ data[45] ^ data[52] ^ data[53] ^ data[54] ^ data[56] ^ data[58] ^ data[59] ^ data[60];
 end 


 always @(*) begin
  data_p0[4] = data[0] ^ data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[8] ^ data[11] ^ data[12] ^ data[15] ^ data[18] ^ data[19] ^ data[20] ^ data[24] ^ data[25] ^ data[29] ^ data[30] ^ data[31] ^ data[33] ^ data[38] ^ data[39] ^ data[40] ^ data[41] ^ data[44] ^ data[45] ^ data[46] ^ data[47] ^ data[48] ^ data[50] ^ data[57] ^ data[58] ^ data[59] ^ data[63];
 end 


 always @(*) begin
  data_p0[5] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13] ^ data[19] ^ data[20] ^ data[21] ^ data[24] ^ data[28] ^ data[29] ^ data[37] ^ data[39] ^ data[40] ^ data[41] ^ data[42] ^ data[44] ^ data[46] ^ data[49] ^ data[50] ^ data[51] ^ data[53] ^ data[54] ^ data[55] ^ data[59] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[6] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14] ^ data[20] ^ data[21] ^ data[22] ^ data[25] ^ data[29] ^ data[30] ^ data[38] ^ data[40] ^ data[41] ^ data[42] ^ data[43] ^ data[45] ^ data[47] ^ data[50] ^ data[51] ^ data[52] ^ data[54] ^ data[55] ^ data[56] ^ data[60] ^ data[62];
 end 


 always @(*) begin
  data_p0[7] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[7] ^ data[8] ^ data[10] ^ data[15] ^ data[16] ^ data[21] ^ data[22] ^ data[23] ^ data[24] ^ data[25] ^ data[28] ^ data[29] ^ data[32] ^ data[34] ^ data[37] ^ data[39] ^ data[41] ^ data[42] ^ data[43] ^ data[45] ^ data[46] ^ data[47] ^ data[50] ^ data[51] ^ data[52] ^ data[54] ^ data[56] ^ data[57] ^ data[58] ^ data[60];
 end 


 always @(*) begin
  data_p0[8] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[8] ^ data[10] ^ data[11] ^ data[12] ^ data[17] ^ data[22] ^ data[23] ^ data[28] ^ data[31] ^ data[32] ^ data[33] ^ data[34] ^ data[35] ^ data[37] ^ data[38] ^ data[40] ^ data[42] ^ data[43] ^ data[45] ^ data[46] ^ data[50] ^ data[51] ^ data[52] ^ data[54] ^ data[57] ^ data[59] ^ data[60] ^ data[63];
 end 


 always @(*) begin
  data_p0[9] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[9] ^ data[11] ^ data[12] ^ data[13] ^ data[18] ^ data[23] ^ data[24] ^ data[29] ^ data[32] ^ data[33] ^ data[34] ^ data[35] ^ data[36] ^ data[38] ^ data[39] ^ data[41] ^ data[43] ^ data[44] ^ data[46] ^ data[47] ^ data[51] ^ data[52] ^ data[53] ^ data[55] ^ data[58] ^ data[60] ^ data[61];
 end 


 always @(*) begin
  data_p0[10] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[9] ^ data[13] ^ data[14] ^ data[16] ^ data[19] ^ data[26] ^ data[28] ^ data[29] ^ data[31] ^ data[32] ^ data[33] ^ data[35] ^ data[36] ^ data[39] ^ data[40] ^ data[42] ^ data[50] ^ data[52] ^ data[55] ^ data[56] ^ data[58] ^ data[59] ^ data[60] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[11] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[9] ^ data[12] ^ data[14] ^ data[15] ^ data[16] ^ data[17] ^ data[20] ^ data[24] ^ data[25] ^ data[26] ^ data[27] ^ data[28] ^ data[31] ^ data[33] ^ data[36] ^ data[40] ^ data[41] ^ data[43] ^ data[44] ^ data[45] ^ data[47] ^ data[48] ^ data[50] ^ data[51] ^ data[54] ^ data[55] ^ data[56] ^ data[57] ^ data[58] ^ data[59];
 end 


 always @(*) begin
  data_p0[12] = data[0] ^ data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[9] ^ data[12] ^ data[13] ^ data[15] ^ data[17] ^ data[18] ^ data[21] ^ data[24] ^ data[27] ^ data[30] ^ data[31] ^ data[41] ^ data[42] ^ data[46] ^ data[47] ^ data[49] ^ data[50] ^ data[51] ^ data[52] ^ data[53] ^ data[54] ^ data[56] ^ data[57] ^ data[59] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[13] = data[1] ^ data[2] ^ data[3] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13] ^ data[14] ^ data[16] ^ data[18] ^ data[19] ^ data[22] ^ data[25] ^ data[28] ^ data[31] ^ data[32] ^ data[42] ^ data[43] ^ data[47] ^ data[48] ^ data[50] ^ data[51] ^ data[52] ^ data[53] ^ data[54] ^ data[55] ^ data[57] ^ data[58] ^ data[60] ^ data[62];
 end 


 always @(*) begin
  data_p0[14] = data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14] ^ data[15] ^ data[17] ^ data[19] ^ data[20] ^ data[23] ^ data[26] ^ data[29] ^ data[32] ^ data[33] ^ data[43] ^ data[44] ^ data[48] ^ data[49] ^ data[51] ^ data[52] ^ data[53] ^ data[54] ^ data[55] ^ data[56] ^ data[58] ^ data[59] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[15] = data[3] ^ data[4] ^ data[5] ^ data[7] ^ data[8] ^ data[9] ^ data[12] ^ data[15] ^ data[16] ^ data[18] ^ data[20] ^ data[21] ^ data[24] ^ data[27] ^ data[30] ^ data[33] ^ data[34] ^ data[44] ^ data[45] ^ data[49] ^ data[50] ^ data[52] ^ data[53] ^ data[54] ^ data[55] ^ data[56] ^ data[57] ^ data[59] ^ data[60] ^ data[62];
 end 


 always @(*) begin
  data_p0[16] = data[0] ^ data[4] ^ data[5] ^ data[8] ^ data[12] ^ data[13] ^ data[17] ^ data[19] ^ data[21] ^ data[22] ^ data[24] ^ data[26] ^ data[29] ^ data[30] ^ data[32] ^ data[35] ^ data[37] ^ data[44] ^ data[46] ^ data[47] ^ data[48] ^ data[51] ^ data[56] ^ data[57];
 end 


 always @(*) begin
  data_p0[17] = data[1] ^ data[5] ^ data[6] ^ data[9] ^ data[13] ^ data[14] ^ data[18] ^ data[20] ^ data[22] ^ data[23] ^ data[25] ^ data[27] ^ data[30] ^ data[31] ^ data[33] ^ data[36] ^ data[38] ^ data[45] ^ data[47] ^ data[48] ^ data[49] ^ data[52] ^ data[57] ^ data[58];
 end 


 always @(*) begin
  data_p0[18] = data[2] ^ data[6] ^ data[7] ^ data[10] ^ data[14] ^ data[15] ^ data[19] ^ data[21] ^ data[23] ^ data[24] ^ data[26] ^ data[28] ^ data[31] ^ data[32] ^ data[34] ^ data[37] ^ data[39] ^ data[46] ^ data[48] ^ data[49] ^ data[50] ^ data[53] ^ data[58] ^ data[59];
 end 


 always @(*) begin
  data_p0[19] = data[3] ^ data[7] ^ data[8] ^ data[11] ^ data[15] ^ data[16] ^ data[20] ^ data[22] ^ data[24] ^ data[25] ^ data[27] ^ data[29] ^ data[32] ^ data[33] ^ data[35] ^ data[38] ^ data[40] ^ data[47] ^ data[49] ^ data[50] ^ data[51] ^ data[54] ^ data[59] ^ data[60];
 end 


 always @(*) begin
  data_p0[20] = data[4] ^ data[8] ^ data[9] ^ data[12] ^ data[16] ^ data[17] ^ data[21] ^ data[23] ^ data[25] ^ data[26] ^ data[28] ^ data[30] ^ data[33] ^ data[34] ^ data[36] ^ data[39] ^ data[41] ^ data[48] ^ data[50] ^ data[51] ^ data[52] ^ data[55] ^ data[60] ^ data[61];
 end 


 always @(*) begin
  data_p0[21] = data[5] ^ data[9] ^ data[10] ^ data[13] ^ data[17] ^ data[18] ^ data[22] ^ data[24] ^ data[26] ^ data[27] ^ data[29] ^ data[31] ^ data[34] ^ data[35] ^ data[37] ^ data[40] ^ data[42] ^ data[49] ^ data[51] ^ data[52] ^ data[53] ^ data[56] ^ data[61] ^ data[62];
 end 


 always @(*) begin
  data_p0[22] = data[0] ^ data[9] ^ data[11] ^ data[12] ^ data[14] ^ data[16] ^ data[18] ^ data[19] ^ data[23] ^ data[24] ^ data[26] ^ data[27] ^ data[29] ^ data[31] ^ data[34] ^ data[35] ^ data[36] ^ data[37] ^ data[38] ^ data[41] ^ data[43] ^ data[44] ^ data[45] ^ data[47] ^ data[48] ^ data[52] ^ data[55] ^ data[57] ^ data[58] ^ data[60] ^ data[61] ^ data[62];
 end 


 always @(*) begin
  data_p0[23] = data[0] ^ data[1] ^ data[6] ^ data[9] ^ data[13] ^ data[15] ^ data[16] ^ data[17] ^ data[19] ^ data[20] ^ data[26] ^ data[27] ^ data[29] ^ data[31] ^ data[34] ^ data[35] ^ data[36] ^ data[38] ^ data[39] ^ data[42] ^ data[46] ^ data[47] ^ data[49] ^ data[50] ^ data[54] ^ data[55] ^ data[56] ^ data[59] ^ data[60] ^ data[62];
 end 


 always @(*) begin
  data_p0[24] = data[1] ^ data[2] ^ data[7] ^ data[10] ^ data[14] ^ data[16] ^ data[17] ^ data[18] ^ data[20] ^ data[21] ^ data[27] ^ data[28] ^ data[30] ^ data[32] ^ data[35] ^ data[36] ^ data[37] ^ data[39] ^ data[40] ^ data[43] ^ data[47] ^ data[48] ^ data[50] ^ data[51] ^ data[55] ^ data[56] ^ data[57] ^ data[60] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[25] = data[2] ^ data[3] ^ data[8] ^ data[11] ^ data[15] ^ data[17] ^ data[18] ^ data[19] ^ data[21] ^ data[22] ^ data[28] ^ data[29] ^ data[31] ^ data[33] ^ data[36] ^ data[37] ^ data[38] ^ data[40] ^ data[41] ^ data[44] ^ data[48] ^ data[49] ^ data[51] ^ data[52] ^ data[56] ^ data[57] ^ data[58] ^ data[61] ^ data[62];
 end 


 always @(*) begin
  data_p0[26] = data[0] ^ data[3] ^ data[4] ^ data[6] ^ data[10] ^ data[18] ^ data[19] ^ data[20] ^ data[22] ^ data[23] ^ data[24] ^ data[25] ^ data[26] ^ data[28] ^ data[31] ^ data[38] ^ data[39] ^ data[41] ^ data[42] ^ data[44] ^ data[47] ^ data[48] ^ data[49] ^ data[52] ^ data[54] ^ data[55] ^ data[57] ^ data[59] ^ data[60] ^ data[61] ^ data[62];
 end 


 always @(*) begin
  data_p0[27] = data[1] ^ data[4] ^ data[5] ^ data[7] ^ data[11] ^ data[19] ^ data[20] ^ data[21] ^ data[23] ^ data[24] ^ data[25] ^ data[26] ^ data[27] ^ data[29] ^ data[32] ^ data[39] ^ data[40] ^ data[42] ^ data[43] ^ data[45] ^ data[48] ^ data[49] ^ data[50] ^ data[53] ^ data[55] ^ data[56] ^ data[58] ^ data[60] ^ data[61] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[28] = data[2] ^ data[5] ^ data[6] ^ data[8] ^ data[12] ^ data[20] ^ data[21] ^ data[22] ^ data[24] ^ data[25] ^ data[26] ^ data[27] ^ data[28] ^ data[30] ^ data[33] ^ data[40] ^ data[41] ^ data[43] ^ data[44] ^ data[46] ^ data[49] ^ data[50] ^ data[51] ^ data[54] ^ data[56] ^ data[57] ^ data[59] ^ data[61] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[29] = data[3] ^ data[6] ^ data[7] ^ data[9] ^ data[13] ^ data[21] ^ data[22] ^ data[23] ^ data[25] ^ data[26] ^ data[27] ^ data[28] ^ data[29] ^ data[31] ^ data[34] ^ data[41] ^ data[42] ^ data[44] ^ data[45] ^ data[47] ^ data[50] ^ data[51] ^ data[52] ^ data[55] ^ data[57] ^ data[58] ^ data[60] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[30] = data[4] ^ data[7] ^ data[8] ^ data[10] ^ data[14] ^ data[22] ^ data[23] ^ data[24] ^ data[26] ^ data[27] ^ data[28] ^ data[29] ^ data[30] ^ data[32] ^ data[35] ^ data[42] ^ data[43] ^ data[45] ^ data[46] ^ data[48] ^ data[51] ^ data[52] ^ data[53] ^ data[56] ^ data[58] ^ data[59] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[31] = data[5] ^ data[8] ^ data[9] ^ data[11] ^ data[15] ^ data[23] ^ data[24] ^ data[25] ^ data[27] ^ data[28] ^ data[29] ^ data[30] ^ data[31] ^ data[33] ^ data[36] ^ data[43] ^ data[44] ^ data[46] ^ data[47] ^ data[49] ^ data[52] ^ data[53] ^ data[54] ^ data[57] ^ data[59] ^ data[60] ^ data[62];
 end 

endmodule 
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/1ps
// synopsys translate_on


module crc32_d8s(
 input      [7:0] data,
 input      [31:0] seed,
 output     [31:0] crc
);

   //registers decalarations
 reg [31:0] data_p0; 
 reg [31:0] seed_p0; 

   //remap signal
 assign crc = data_p0 ^ seed_p0;


 always @(*) begin
  data_p0[0] = data[0] ^ data[6];
 end 


 always @(*) begin
  data_p0[1] = data[0] ^ data[1] ^ data[6] ^ data[7];
 end 


 always @(*) begin
  data_p0[2] = data[0] ^ data[1] ^ data[2] ^ data[6] ^ data[7];
 end 


 always @(*) begin
  data_p0[3] = data[1] ^ data[2] ^ data[3] ^ data[7];
 end 


 always @(*) begin
  data_p0[4] = data[0] ^ data[2] ^ data[3] ^ data[4] ^ data[6];
 end 


 always @(*) begin
  data_p0[5] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7];
 end 


 always @(*) begin
  data_p0[6] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[7];
 end 


 always @(*) begin
  data_p0[7] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[7];
 end 


 always @(*) begin
  data_p0[8] = data[0] ^ data[1] ^ data[3] ^ data[4];
 end 


 always @(*) begin
  data_p0[9] = data[1] ^ data[2] ^ data[4] ^ data[5];
 end 


 always @(*) begin
  data_p0[10] = data[0] ^ data[2] ^ data[3] ^ data[5];
 end 


 always @(*) begin
  data_p0[11] = data[0] ^ data[1] ^ data[3] ^ data[4];
 end 


 always @(*) begin
  data_p0[12] = data[0] ^ data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6];
 end 


 always @(*) begin
  data_p0[13] = data[1] ^ data[2] ^ data[3] ^ data[5] ^ data[6] ^ data[7];
 end 


 always @(*) begin
  data_p0[14] = data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[7];
 end 


 always @(*) begin
  data_p0[15] = data[3] ^ data[4] ^ data[5] ^ data[7];
 end 


 always @(*) begin
  data_p0[16] = data[0] ^ data[4] ^ data[5];
 end 


 always @(*) begin
  data_p0[17] = data[1] ^ data[5] ^ data[6];
 end 


 always @(*) begin
  data_p0[18] = data[2] ^ data[6] ^ data[7];
 end 


 always @(*) begin
  data_p0[19] = data[3] ^ data[7];
 end 


 always @(*) begin
  data_p0[20] = data[4];
 end 


 always @(*) begin
  data_p0[21] = data[5];
 end 


 always @(*) begin
  data_p0[22] = data[0];
 end 


 always @(*) begin
  data_p0[23] = data[0] ^ data[1] ^ data[6];
 end 


 always @(*) begin
  data_p0[24] = data[1] ^ data[2] ^ data[7];
 end 


 always @(*) begin
  data_p0[25] = data[2] ^ data[3];
 end 


 always @(*) begin
  data_p0[26] = data[0] ^ data[3] ^ data[4] ^ data[6];
 end 


 always @(*) begin
  data_p0[27] = data[1] ^ data[4] ^ data[5] ^ data[7];
 end 


 always @(*) begin
  data_p0[28] = data[2] ^ data[5] ^ data[6];
 end 


 always @(*) begin
  data_p0[29] = data[3] ^ data[6] ^ data[7];
 end 


 always @(*) begin
  data_p0[30] = data[4] ^ data[7];
 end 


 always @(*) begin
  data_p0[31] = data[5];
 end 


 always @(*) begin
 seed_p0[0] = seed[24] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[1] = seed[24] ^ seed[25] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[2] = seed[24] ^ seed[25] ^ seed[26] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[3] = seed[25] ^ seed[26] ^ seed[27] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[4] = seed[24] ^ seed[26] ^ seed[27] ^ seed[28] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[5] = seed[24] ^ seed[25] ^ seed[27] ^ seed[28] ^ seed[29] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[6] = seed[25] ^ seed[26] ^ seed[28] ^ seed[29] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[7] = seed[24] ^ seed[26] ^ seed[27] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[8] = seed[0] ^ seed[24] ^ seed[25] ^ seed[27] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[9] = seed[1] ^ seed[25] ^ seed[26] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[10] = seed[2] ^ seed[24] ^ seed[26] ^ seed[27] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[11] = seed[3] ^ seed[24] ^ seed[25] ^ seed[27] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[12] = seed[4] ^ seed[24] ^ seed[25] ^ seed[26] ^ seed[28] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[13] = seed[5] ^ seed[25] ^ seed[26] ^ seed[27] ^ seed[29] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[14] = seed[6] ^ seed[26] ^ seed[27] ^ seed[28] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[15] = seed[7] ^ seed[27] ^ seed[28] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[16] = seed[8] ^ seed[24] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[17] = seed[9] ^ seed[25] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[18] = seed[10] ^ seed[26] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[19] = seed[11] ^ seed[27] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[20] = seed[12] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[21] = seed[13] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[22] = seed[14] ^ seed[24];
 end 


 always @(*) begin
 seed_p0[23] = seed[15] ^ seed[24] ^ seed[25] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[24] = seed[16] ^ seed[25] ^ seed[26] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[25] = seed[17] ^ seed[26] ^ seed[27];
 end 


 always @(*) begin
 seed_p0[26] = seed[18] ^ seed[24] ^ seed[27] ^ seed[28] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[27] = seed[19] ^ seed[25] ^ seed[28] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[28] = seed[20] ^ seed[26] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[29] = seed[21] ^ seed[27] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[30] = seed[22] ^ seed[28] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[31] = seed[23] ^ seed[29];
 end 

endmodule 
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/1ps
// synopsys translate_on

// Any Polynomial CRC Generator                                               
//
/**** CRC32 Generate/Check Timing Diagram ****
                   __    __    __    __    __    __  
   clock        __|  |__|  |__|  |__|  |__|  |__|  |__
                      ____
   data_vld     _____|    |_____________________
                      ____    |
   data_eop     _____|    |_____________________
                            __|_
   crc_vld      ___________|    |_______________ 
                              |   
   crc_out      -----------[crc ]---------------
                              |
****/                 
module eth_crc32_gen(
   /* i */ clk,         //clock
   /* i */ rst_n,       //active low reset
   /* i */ data_vld,    //data valid
   /* i */ data_eop,    //end of frame
   /* i */ data_sop,    //start of frame
   /* i */ data_in,     //align first byte on bit [7:0] ... last byte [63:56]
   /* i */ data_offset, //number of starting bytes invalid on SOF beat, non SOF should set to 0
   						//     data_offset should be 0 for this module if contained in RX_GMII
   /* i */ data_be,     //0 - all bytes valid  (really is beat_bcnt)
                        //1 - 1 byte valid bit[7:0]
                        //..
                        //7 - 7 bytes valid bit[55:0]
   /* o */ crc_out,     //final generated crc32 value
   /* o */ crc_vld      //crc check valid
 );

 //synopsys sync_set_reset "rst_n"
 parameter CRC_DWIDTH  = 32;
   
 //system clock and reset        
 input            clk;         //clock
 input            rst_n;       //active low reset
           
 //data inputs                                        
 input            data_vld;    //packet data is valid
 input            data_eop;    //indicates last packet data for this packet
 input            data_sop;    //indicates the first packet data for this packet
 input  [64-1:0]  data_in;     //packet data
 input  [3-1:0]   data_be;     //total number of bytes valid, regardless of the where the first data is align on this clock
 input  [3-1:0]   data_offset; //offset to first valid byte in the sof data beat, set to zero if non sof beat

 //crc outputs
 output [31:0]    crc_out;     //final crc32 value
 output reg       crc_vld;     //indicates crc status is valid
 
 //register declarations
 reg              data_vld_s2;
 reg    [64-1:0]  shft_dout_s2;
 reg              data_eop_s2;
 reg              be_lt4_s2;
 reg    [32-1:0]  crc_dout_s3;
 reg    [32-1:0]  crc_dout_mux_s2;
 reg    [24-1:0]  shft_odd_dout_s2;
 reg    [64-1:0]  data_mask; 
 reg              info_mux_s2_crc_eop;
 reg    [2-1:0]   info_s2_crc_sel;  
 reg    [32-1:0]  crc_mux_s2;
 
 //wire declarations
 wire   [32-1:0]  crc_dout_d32_s2;
 wire   [4-1:0]   data_shft;  
 wire   [4-1:0]   seed_shft;
 wire   [3-1:0]   sum_data_be_offset;  
 wire   [64-1:0]  data_in_mask_s1;
 wire   [88-1:0]  adj_data_in_mask_s1;
 wire   [64-1:0]  adj_seed_crc_s1;
 wire   [88-1:0]  shft_dout_s1;
 wire   [64-1:0]  shft_crc_mux_s1;
 wire             be_lt4_s1;
 
 //number of bytes to shift down so that last valid byte is align on bit[7:0] of "data_in"
 assign sum_data_be_offset = data_offset  + data_be;
 assign data_shft          = ~(|sum_data_be_offset) ? 3'd0 : {1'b0, ~sum_data_be_offset} + 4'd1;
 
 //number of bytes to shift down the seed-crc so that it align with first valid data byte
 assign seed_shft = ~(|data_be) ? 4'd0 : {1'b0, ~data_be} + 4'd1;
 
 //packet data mask, use to mask out the data invalid data bytes in the data_in bus
 always@(*)
  begin
   case(data_offset)
    3'd1:    data_mask = data_sop ? {8'h0, {56{1'b1}}} : {64{1'b1}};
    3'd2:    data_mask = data_sop ? {16'h0,{48{1'b1}}} : {64{1'b1}};
    3'd3:    data_mask = data_sop ? {24'h0,{40{1'b1}}} : {64{1'b1}};
    3'd4:    data_mask = data_sop ? {32'h0,{32{1'b1}}} : {64{1'b1}};
    3'd5:    data_mask = data_sop ? {40'h0,{24{1'b1}}} : {64{1'b1}};
    3'd6:    data_mask = data_sop ? {48'h0,{16{1'b1}}} : {64{1'b1}};
    3'd7:    data_mask = data_sop ? {56'h0,{8{1'b1}}}  : {64{1'b1}};
    default: data_mask = {64{1'b1}}; 
   endcase
  end
 
 //logic to determine if there are less than word align bytes
 assign be_lt4_s1 = (data_be < 3'd4);
 
 //logic to pipe the data valid signal along
 always@(*)
  begin
   data_vld_s2     = data_vld;
   data_eop_s2     = data_eop;
   info_s2_crc_sel = sum_data_be_offset[1:0];
   be_lt4_s2       = be_lt4_s1;
  end

 //STAGE 1: logic to shift the input data from MSB to LSB to prepend zero's  
 //assumption: MSB bits contains the first byte from network
 //            shift dout is valid on same clock
 assign data_in_mask_s1 = data_mask & SWAP_LEWIZ_DATA64(data_in);
 
 wire [4-1:0] adj_data_shft_s1 = (|sum_data_be_offset[2-1:0]) ? {data_shft[4-1:2], 2'd0} + 4'd4 : {data_shft[4-1:2], 2'd0};
 wire [4-1:0] adj_seed_shft_s1 = (|data_offset)      ? seed_shft :
                                 (|seed_shft[2-1:0]) ? {seed_shft[4-1:2], 2'd0} + 4'd4 : {seed_shft[4-1:2], 2'd0};
 
 //adjust the input data after masking if starting byte is not align on 32 bits boundary
 assign adj_data_in_mask_s1 = {data_in_mask_s1, 24'd0};

 //logic to adjust the data shift value, to shift odd byte all the way down
 bsh32_dn_88 u_bsh32_dn_88_data(
  .shft(adj_data_shft_s1[4-1:2]),
  .din (adj_data_in_mask_s1),
  .dout(shft_dout_s1)
 );
 
 //adjust the input data after masking if starting byte is not align on 32 bits boundary
 assign adj_seed_crc_s1 = {SWAP_CRC(crc_mux_s2), 32'd0};
 
 //logic to shift the crc from MSB to LSB to xor with beginning bytes of input data
 bsh8_dn_64 u_bsh8_dn_64_crc(
  .shft(adj_seed_shft_s1[2:0]),
  .din (adj_seed_crc_s1),
  .dout(shft_crc_mux_s1)
 );
 
 //flop the shift dout to next stage
 always@(*) begin
  shft_dout_s2     = shft_dout_s1[88-1:24] ^ shft_crc_mux_s1;  
  shft_odd_dout_s2 = shft_dout_s1[24-1:0];
 end
 
 //STAGE 2: Compute the CRC32 for input data
 //assumption: crc out is valid on same clock, pure crc computation logic, no accumulation needed
 wire [64-1:0] swap_shft_dout_s2 = SWAP_DATA64(shft_dout_s2);
 wire [24-1:0] swap_shft_odd_dout_s2 = SWAP_DATA24(shft_odd_dout_s2);

 crc32_d64 u_crc32_d64(
  .data(swap_shft_dout_s2),
  .crc (crc_dout_d32_s2)
 );
 
 //for debugging purpose only
 wire [32-1:0] crc_gen_d32_s2 = ~SWAP_NO_CRC(crc_dout_d32_s2);
  
 //logic to compute the non-word align data byte crc
 always@(*) begin
  crc_mux_s2 = crc_dout_s3 | {32{data_sop}};
 end 
  
 wire [32-1:0] crc_dout_d8_s2;
 wire [32-1:0] crc_seed_d8_s2 = be_lt4_s2 ? crc_mux_s2 : crc_dout_d32_s2;
 wire [32-1:0] crc_gen_d8_s2  = ~SWAP_NO_CRC(crc_dout_d8_s2);  //for debugging purpose only
  
 crc32_d8s u_crc32_d8s(
  .seed(crc_seed_d8_s2),
  .data(swap_shft_odd_dout_s2[23:16]),
  .crc (crc_dout_d8_s2)
 );

 wire [32-1:0] crc_dout_d16_s2;
 wire [32-1:0] crc_seed_d16_s2 = be_lt4_s2 ? crc_mux_s2 : crc_dout_d32_s2;
 wire [32-1:0] crc_gen_d16_s2  = ~SWAP_NO_CRC(crc_dout_d16_s2);  //for debugging purpose only
  
 crc32_d16s u_crc32_d16s(
  .seed(crc_seed_d16_s2),
  .data(swap_shft_odd_dout_s2[23:8]),
  .crc (crc_dout_d16_s2)
 );

 wire [32-1:0] crc_dout_d24_s2;
 wire [32-1:0] crc_seed_d24_s2 = be_lt4_s2 ? crc_mux_s2 : crc_dout_d32_s2;
 wire [32-1:0] crc_gen_d24_s2  = ~SWAP_NO_CRC(crc_dout_d24_s2);  //for debugging purpose only
  
 crc32_d24s u_crc32_d24s(
  .seed(crc_seed_d24_s2),
  .data(swap_shft_odd_dout_s2[23:0]),
  .crc (crc_dout_d24_s2)
 );

 //STAGE 2: Multiplex out the current accumulate crc value from table
 //logic to pipe the computed crc value to next stage
 always@(*) begin
   case(info_s2_crc_sel)
    2'd1:    crc_dout_mux_s2 = crc_dout_d8_s2;
    2'd2:    crc_dout_mux_s2 = crc_dout_d16_s2;
    2'd3:    crc_dout_mux_s2 = crc_dout_d24_s2;
    default: crc_dout_mux_s2 = crc_dout_d32_s2;
   endcase
 end
 
 //logic to pipe the info to next stage
 always@(*) begin
   info_mux_s2_crc_eop = (data_eop && ~(|data_be));
  end
 
 
 //STAGE 3: Per Port CRC Accumulation Table Update and CRC Valid Output
 always@(posedge clk) 
  if(!rst_n) begin
   crc_dout_s3 <= {CRC_DWIDTH{1'b1}};
  end else begin 
  	//*mux_32 is combinational
   crc_dout_s3 <= crc_dout_mux_s2;
  end

 //logic to perform crc swap + inversion  
 assign crc_out = ~SWAP_NO_CRC(crc_dout_s3);
 
 //logic to swap and invert the final crc and assert crc valid
 always@(posedge clk) 
  if(!rst_n)
   crc_vld <= 1'b0;
  else
   crc_vld <= data_vld_s2 && data_eop_s2;

 //GV_OFF
 //function to swap the final crc result 
 function [32-1:0] SWAP_CRC;
 input [32-1:0] crc;
 reg   [32-1:0] temp;
 begin
  temp[31] = crc[24];
  temp[30] = crc[25];
  temp[29] = crc[26];
  temp[28] = crc[27];
  temp[27] = crc[28];
  temp[26] = crc[29];
  temp[25] = crc[30];
  temp[24] = crc[31];
  temp[23] = crc[16];
  temp[22] = crc[17];
  temp[21] = crc[18];
  temp[20] = crc[19];
  temp[19] = crc[20];
  temp[18] = crc[21];
  temp[17] = crc[22];
  temp[16] = crc[23];
  temp[15] = crc[8];
  temp[14] = crc[9];
  temp[13] = crc[10];
  temp[12] = crc[11];
  temp[11] = crc[12];
  temp[10] = crc[13];
  temp[9] = crc[14];
  temp[8] = crc[15];
  temp[7] = crc[0];
  temp[6] = crc[1];
  temp[5] = crc[2];
  temp[4] = crc[3];
  temp[3] = crc[4];
  temp[2] = crc[5];
  temp[1] = crc[6];
  temp[0] = crc[7];
  SWAP_CRC = temp;
 end
 endfunction                
 
 function [32-1:0] SWAP_NO_CRC;
 input [32-1:0] crc;
 reg   [32-1:0] temp;
 begin
  temp[31] = crc[0];
  temp[30] = crc[1];
  temp[29] = crc[2];
  temp[28] = crc[3];
  temp[27] = crc[4];
  temp[26] = crc[5];
  temp[25] = crc[6];
  temp[24] = crc[7];
  temp[23] = crc[8]; 
  temp[22] = crc[9]; 
  temp[21] = crc[10];
  temp[20] = crc[11];
  temp[19] = crc[12];
  temp[18] = crc[13];
  temp[17] = crc[14];
  temp[16] = crc[15];
  temp[15] = crc[16];
  temp[14] = crc[17];
  temp[13] = crc[18];
  temp[12] = crc[19];
  temp[11] = crc[20];
  temp[10] = crc[21];
  temp[9]  = crc[22];
  temp[8]  = crc[23];
  temp[7]  = crc[24];
  temp[6]  = crc[25];
  temp[5]  = crc[26];
  temp[4]  = crc[27];
  temp[3]  = crc[28];
  temp[2]  = crc[29];
  temp[1]  = crc[30];
  temp[0]  = crc[31];
  SWAP_NO_CRC = temp;
 end
 endfunction                                
 
 //fucntion to swap the input data before sending it to the crc compute module
 function [64-1:0] SWAP_DATA64;
 input [64-1:0] DIN;
 reg   [64-1:0] DOUT;
 begin
   DOUT[63] = DIN[56];
   DOUT[62] = DIN[57];
   DOUT[61] = DIN[58];
   DOUT[60] = DIN[59];
   DOUT[59] = DIN[60];
   DOUT[58] = DIN[61];
   DOUT[57] = DIN[62];
   DOUT[56] = DIN[63];
   DOUT[55] = DIN[48];
   DOUT[54] = DIN[49];
   DOUT[53] = DIN[50];
   DOUT[52] = DIN[51];
   DOUT[51] = DIN[52];
   DOUT[50] = DIN[53];
   DOUT[49] = DIN[54];
   DOUT[48] = DIN[55];
   DOUT[47] = DIN[40];
   DOUT[46] = DIN[41];
   DOUT[45] = DIN[42];
   DOUT[44] = DIN[43];
   DOUT[43] = DIN[44];
   DOUT[42] = DIN[45];
   DOUT[41] = DIN[46];
   DOUT[40] = DIN[47];
   DOUT[39] = DIN[32];
   DOUT[38] = DIN[33];
   DOUT[37] = DIN[34];
   DOUT[36] = DIN[35];
   DOUT[35] = DIN[36];
   DOUT[34] = DIN[37];
   DOUT[33] = DIN[38];
   DOUT[32] = DIN[39];
   DOUT[31] = DIN[24];
   DOUT[30] = DIN[25];
   DOUT[29] = DIN[26];
   DOUT[28] = DIN[27];
   DOUT[27] = DIN[28];
   DOUT[26] = DIN[29];
   DOUT[25] = DIN[30];
   DOUT[24] = DIN[31];
   DOUT[23] = DIN[16];
   DOUT[22] = DIN[17];
   DOUT[21] = DIN[18];
   DOUT[20] = DIN[19];
   DOUT[19] = DIN[20];
   DOUT[18] = DIN[21];
   DOUT[17] = DIN[22];
   DOUT[16] = DIN[23];
   DOUT[15] = DIN[8];
   DOUT[14] = DIN[9];
   DOUT[13] = DIN[10];
   DOUT[12] = DIN[11];
   DOUT[11] = DIN[12];
   DOUT[10] = DIN[13];
   DOUT[9] = DIN[14];
   DOUT[8] = DIN[15];
   DOUT[7] = DIN[0];
   DOUT[6] = DIN[1];
   DOUT[5] = DIN[2];
   DOUT[4] = DIN[3];
   DOUT[3] = DIN[4];
   DOUT[2] = DIN[5];
   DOUT[1] = DIN[6];
   DOUT[0] = DIN[7];
   
   SWAP_DATA64 = DOUT; 
 end
 endfunction
 
 //fucntion to swap the input data before sending it to the crc compute module
 function [24-1:0] SWAP_DATA24;
 input [24-1:0] DIN;
 reg   [24-1:0] DOUT;
 begin
   DOUT[23] = DIN[16];
   DOUT[22] = DIN[17];
   DOUT[21] = DIN[18];
   DOUT[20] = DIN[19];
   DOUT[19] = DIN[20];
   DOUT[18] = DIN[21];
   DOUT[17] = DIN[22];
   DOUT[16] = DIN[23];
   DOUT[15] = DIN[8];
   DOUT[14] = DIN[9];
   DOUT[13] = DIN[10];
   DOUT[12] = DIN[11];
   DOUT[11] = DIN[12];
   DOUT[10] = DIN[13];
   DOUT[9] = DIN[14];
   DOUT[8] = DIN[15];
   DOUT[7] = DIN[0];
   DOUT[6] = DIN[1];
   DOUT[5] = DIN[2];
   DOUT[4] = DIN[3];
   DOUT[3] = DIN[4];
   DOUT[2] = DIN[5];
   DOUT[1] = DIN[6];
   DOUT[0] = DIN[7];
   
   SWAP_DATA24 = DOUT; 
 end
 endfunction
 
 //function to swap lewiz data format to crc data format
 function [64-1:0] SWAP_LEWIZ_DATA64;
 input [64-1:0] DIN;
 reg   [64-1:0] DOUT;
 begin
   DOUT[63] = DIN[7];
   DOUT[62] = DIN[6];
   DOUT[61] = DIN[5];
   DOUT[60] = DIN[4];
   DOUT[59] = DIN[3];
   DOUT[58] = DIN[2];
   DOUT[57] = DIN[1];
   DOUT[56] = DIN[0];
   DOUT[55] = DIN[15];
   DOUT[54] = DIN[14];
   DOUT[53] = DIN[13];
   DOUT[52] = DIN[12];
   DOUT[51] = DIN[11];
   DOUT[50] = DIN[10];
   DOUT[49] = DIN[9];
   DOUT[48] = DIN[8];
   DOUT[47] = DIN[23];
   DOUT[46] = DIN[22];
   DOUT[45] = DIN[21];
   DOUT[44] = DIN[20];
   DOUT[43] = DIN[19];
   DOUT[42] = DIN[18];
   DOUT[41] = DIN[17];
   DOUT[40] = DIN[16];
   DOUT[39] = DIN[31];
   DOUT[38] = DIN[30];
   DOUT[37] = DIN[29];
   DOUT[36] = DIN[28];
   DOUT[35] = DIN[27];
   DOUT[34] = DIN[26];
   DOUT[33] = DIN[25];
   DOUT[32] = DIN[24];
   DOUT[31] = DIN[39];
   DOUT[30] = DIN[38];
   DOUT[29] = DIN[37];
   DOUT[28] = DIN[36];
   DOUT[27] = DIN[35];
   DOUT[26] = DIN[34];
   DOUT[25] = DIN[33];
   DOUT[24] = DIN[32];
   DOUT[23] = DIN[47];
   DOUT[22] = DIN[46];
   DOUT[21] = DIN[45];
   DOUT[20] = DIN[44];
   DOUT[19] = DIN[43];
   DOUT[18] = DIN[42];
   DOUT[17] = DIN[41];
   DOUT[16] = DIN[40];
   DOUT[15] = DIN[55];
   DOUT[14] = DIN[54];
   DOUT[13] = DIN[53];
   DOUT[12] = DIN[52];
   DOUT[11] = DIN[51];
   DOUT[10] = DIN[50];
   DOUT[9]  = DIN[49];
   DOUT[8]  = DIN[48];
   DOUT[7]  = DIN[63];
   DOUT[6]  = DIN[62];
   DOUT[5]  = DIN[61];
   DOUT[4]  = DIN[60];
   DOUT[3]  = DIN[59];
   DOUT[2]  = DIN[58];
   DOUT[1]  = DIN[57];
   DOUT[0]  = DIN[56];
   
   SWAP_LEWIZ_DATA64 = DOUT; 
 end
 endfunction
 //GV_ON

endmodule

//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


`timescale 1ns / 1ns


module fmac_fifo4Kx64

(
			aclr,
			//=== Signals for WRITE
			
			wrclk,	      				// Clk for writing data                              
			wrreq,  	     			// Data coming in                                    
			data,    					// request to write                                  
			wrfull,     				// indicates fifo is full or not (To avoid overiding)
			wrempty,    				// 0- some data is present (atleast 1 data is present)                                            
			wrusedw,    				// number of slots currently in use for writing                                                                                                         

			
			//=== Signals for READ
			
			rdclk,      				// Clk for reading data                                
			rdreq,       				// Request to read from FIFO                           
			q,    						// Data coming out                                     
			rdfull,   
			rdempty,    				// indicates fifo is empty or not (to avoid underflow)  
			rdusedw    					// number of slots currently in use for reading
		//=== Other Signals 
			
);
parameter 	  WIDTH = 64,
			  DEPTH = 4096,
			  PTR	= 12;
			  
			input  wire 				aclr;
			//=== Signals for WRITE
			
			input  wire 				wrclk;      	// Clk for writing data                              
			input  wire 				wrreq;       	// Data coming in                                    
			input  wire [WIDTH-1 : 0]	data;     		// request to write                                  
			output wire					wrfull;     	// indicates fifo is full or not (To avoid overiding)
			output wire 			 	wrempty;    	// 0- some data is present (atleast 1 data is present)                                            
			output wire	[PTR : 0]		wrusedw;    	// number of slots currently in use for writing                                                                                                         
                                         
			
			//=== Signals for READ
			         
			input  wire 				rdclk;      	// Clk for reading data                                
			input  wire 				rdreq;       	// Request to read from FIFO                           
			output wire [WIDTH-1 : 0]	q;    			// Data coming out                                     
			output wire 				rdfull;     	//  
			output wire 				rdempty;    	// indicates fifo is empty or not (to avoid underflow)  
			output wire [PTR  : 0] 	rdusedw;   			// number of slots currently in use for reading




asynch_fifo		#(.WIDTH (64),			   				// Making 512X64 fifo
				  .DEPTH (4096),
				  .PTR	 (12) )		  					// 2**12 = 4096 (DEPTH)
 								
	async	  (
			.reset_		(~aclr),
			        	
			//=== Signals for WRITE
			.wrclk		(wrclk),	   					// Clk to write data
			.wren		(wrreq),	   					// write enable
			.datain		(data),		   					// write data
			.wrfull		(wrfull),	   					// indicates fifo is full or not (To avoid overiding)
			.wrempty	(wrempty),	   					// indicates fifo is empty or not (to avoid underflow)
			.wrusedw	(wrusedw),	   					// wrusedw -number of locations filled in fifo
                    	               					
			                           					
			//=== Signals for READ     					
			.rdclk		(rdclk),	   					// i-1, Clk to read data
			.rden		(rdreq),	   					// i-1, read enable of data FIFO
			.dataout	(q),		   					// Dataout of data FIFO
			.rdfull		(rdfull),	   					// indicates fifo is full or not (To avoid overiding) (Not used)
			.rdempty	(rdempty),	   					// indicates fifo is empty or not (to avoid underflow)
			.rdusedw	(rdusedw),	   					// rdusedw -number of locations filled in fifo (not used )

			//=== Signals for TEST
			.dbg()

		 );
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


`timescale 1ns / 1ns


module fmac_fifo4Kx8

(
			aclr,
			//=== Signals for WRITE
			
			wrclk,      							// Clk for writing data                              
			wrreq,      							// request to write 
			data,     								// Data coming in                                                                    
			wrfull,     							// indicates fifo is full or not (To avoid overiding)
		    wrempty,  								// indicates fifo is empty or not (to avoid underflow)                                                                                                      
            wrusedw,      							// number of slots currently in use for writting                                     

			//=== Signals for READ
            
		    rdclk,       							// Clk for reading data                     
			rdreq,       							// Request to read from FIFO                           
			q, 	    	 							// Data coming out                                     
			rdempty,  	 							// indicates fifo is empty or not (to avoid underflow)  
			rdusedw,      							// number of slots currently in use for reading
			rdfull     								// indicates fifo is full or not (To avoid overiding)
			
);


	parameter WIDTH = 8,
			  DEPTH = 4096,
			  PTR	= 12;
			  
			  
			input  wire 				aclr;
			//=== Signals for WRITE
			
			input  wire 				wrclk;      // Clk for writing data                              
			input  wire 				wrreq;      // request to write 
			input  wire [WIDTH-1 : 0]	data;     	// Data coming in                                                                    
			output wire					wrfull;     // indicates fifo is full or not (To avoid overiding)
			output wire 			    wrempty;  	// indicates fifo is empty or not (to avoid underflow) 		                                       
			output wire	[PTR : 0]		wrusedw;    // number of slots currently in use for writting 
			
			//=== Signals for READ
			
		    input  wire 				rdclk;      // Clk for reading data                   
			input  wire 				rdreq;      // Request to read from FIFO                           
			output wire [WIDTH-1 : 0]	q; 	    	// Data coming out                                     
			output wire 				rdempty;  	// indicates fifo is empty or not (to avoid underflow)  
			output wire [PTR : 0] 	rdusedw;     	// number of slots currently in use for reading
			output wire 				rdfull;     // indicates fifo is full or not (To avoid overiding)


	asynch_fifo 	#(.WIDTH (8),		   			// Making 4096X8 fifo
					  		  .DEPTH (4096),
					 		  .PTR	 (12) )		  	// 2**12 = 4096 (DEPTH)
 								
    async_4Kx8 (
			.reset_	(~aclr),
			
			//=== Signals for WRITE
			.wrclk	(wrclk),						// Clk to write data
			.wren	(wrreq),	   					// write enable
			.datain	(data),							// write data
			.wrfull	(wrfull),						// indicates fifo is full or not (To avoid overiding)
			.wrempty(wrempty),						// indicates fifo is empty or not (to avoid underflow)
			.wrusedw(wrusedw),						// wrusedw -number of locations filled in fifo


			//=== Signals for READ
			.rdclk	(rdclk),						// i-1, Clk to read data
			.rden	(rdreq),						// i-1, read enable of data FIFO
			.dataout(q),							// Dataout of data FIFO
			.rdfull	(rdfull),						// indicates fifo is full or not (To avoid overiding) (Not used)
			.rdempty(rdempty),						// indicates fifo is empty or not (to avoid underflow)
			.rdusedw(rdusedw),						// rdusedw -number of locations filled in fifo (not used )

			//=== Signals for TEST
			.dbg()

		 );
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


`timescale 1ns/10ps

module fmac_fifo512x64_2clk 

(
			aclr,
			//=== Signals for WRITE

			wrclk,       							// Clk for writing data                              
			wrreq,       							//  request to write                                      
			data,     	 							// Data coming in                            
			wrfull,      							// indicates fifo is full or not (To avoid overiding)
			wrempty,     							// 0- some data is present (atleast 1 data is present)                                            
			wrusedw,     							// number of slots currently in use for writing                                                                                                         

			//=== Signals for READ
		    rdclk,      							// Clk for  reading data                            
			rdreq,      							// Request to read from FIFO                           
			q,    									// Data coming out                                     
			rdfull,     							  
			rdempty,    							// indicates fifo is empty or not (to avoid underflow)  
			rdusedw     							// number of slots currently in use for reading

);

parameter 	  WIDTH = 64,
			  DEPTH = 512,
			  PTR	= 9;



			input  wire 				aclr;
			//=== Signals for WRITE
			
			input  wire 				wrclk;      // Clk for writing data                              
			input  wire 				wrreq;      //  request to write                                      
			input  wire [WIDTH-1 : 0]	data;       // Data coming in                            
			output wire					wrfull;     // indicates fifo is full or not (To avoid overiding)
			output wire 			 	wrempty;    // 0- some data is present (atleast 1 data is present)                                            
			output wire	[PTR : 0]		wrusedw;    // number of slots currently in use for writing                                                                                                         
                                                  
			
			//=== Signals for READ
			
		    input  wire 				rdclk;      // Clk for  reading data                            
			input  wire 				rdreq;      // Request to read from FIFO                           
			output wire [WIDTH-1 : 0]	q;    		// Data coming out                                     
			output wire 				rdfull;   
			output wire 				rdempty;    // indicates fifo is empty or not (to avoid underflow)  
			output wire [PTR  : 0] 		rdusedw;    // number of slots currently in use for reading



	asynch_fifo	#(.WIDTH (64),						// Making 512X64 fifo
					  	.DEPTH (512),
					 	.PTR	 (9) )		  		// 2**9 = 512 (DEPTH)
 											
	asynch_512x64_2clk		  (
			.reset_		(~aclr),
			        	
			//=== Signals for WRITE
			.wrclk		(wrclk),			  		// Clk to write data
			.wren		(wrreq),	   		  		// write enable
			.datain		(data),				  		// write data
			.wrfull		(wrfull),			  		// indicates fifo is full or not (To avoid overiding)
			.wrempty	(wrempty),			  		// indicates fifo is empty or not (to avoid underflow)
			.wrusedw	(wrusedw),			  		// wrusedw -number of locations filled in fifo
                    	                      		
                    	                      		
			//=== Signals for READ            		
			.rdclk		(rdclk),			  		// i-1, Clk to read data
			.rden		(rdreq),			  		// i-1, read enable of data FIFO
			.dataout	(q),				  		// Dataout of data FIFO
			.rdfull		(rdfull),			  		// indicates fifo is full or not (To avoid overiding) (Not used)
			.rdempty	(rdempty),			  		// indicates fifo is empty or not (to avoid underflow)
			.rdusedw	(rdusedw),			  		// rdusedw -number of locations filled in fifo (not used )

			//=== Signals for TEST
			.dbg		()

		 );
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns / 1ps
// synopsys translate_on

module fmac_register_if(
	clk,     						// i-1, 250MHz
    reset_,  						// i-1
     
    //REGULAR Statistic Registers
    //NOTE:  Each mac should do its own count then resync one time only
    fmac_ctrl_dly,					//i-32
    FMAC_TX_PKT_CNT,  				// i-32
    FMAC_RX_PKT_CNT_LO,      		// i-32, clk250 (derived from SYNCLK125 [or FMAC0 clk])
    FMAC_RX_PKT_CNT_HI,      		// i-32, clk250 (derived from SYNCLK125 [or FMAC0 clk])

    FMAC_TX_BYTE_CNT,				// i-32
	FMAC_RX_BYTE_CNT_LO,   			// i-32, clk250 (from synclk)
	FMAC_RX_BYTE_CNT_HI,   			// i-32, clk250 (from synclk)
	                            	
	
	FMAC_RX_UNDERSIZE_PKT_CNT,		// i-32
	FMAC_RX_CRC_ERR_CNT,			// i-32
	FMAC_DCNT_OVERRUN,				// i-32
	FMAC_DCNT_LINK_ERR,				// i-32
	FMAC_PKT_CNT_OVERSIZE,			// i-32
	FMAC_PHY_STAT,					// i-32
	fmac_ctrl1	,					// i-32
	
	FMAC_PKT_CNT_JABBER		,		//i-32
	FMAC_PKT_CNT_FRAGMENT	,		//i-32
	FMAC_RAW_FRAME_CNT	,			//i-32
	FMAC_BAD_FRAMESOF_CNT	,		//i-32
	
	//Interface to 64 bit Statistic register group, in DECAP
	STAT_GROUP_LO_DOUT	,			// i-32, clk250
	STAT_GROUP_HI_DOUT	,			// i-32, clk250
	STAT_GROUP_addr	,				// o-10, address to select the register within the STAT GROUP
	STAT_GROUP_sel	,				//o-1
	fmac_rx_clr_en,					//o-1
	
	// Interface to mac_register
	reg_rd_start,					// i-1, pulse indicating the start of a reg access
	reg_rd_done,					// i-1, pulse indicating the end of a reg access
	host_addr_reg,					// i-16
	SYS_ADDR,						// i-4
	
	rx_auto_clr_en,					//i-1
	tx_auto_clr_en,					//i-1
	
	FMAC_REGDOUT					// o-32
	
    );
      
// ----------------------------------------------------------------------------
// PORT DECLARATIONS
// ----------------------------------------------------------------------------
input       	clk;                    	// i-1
input       	reset_;                 	// i-1
                                    		
// Statistic Registers              		
input	[31:0]	fmac_ctrl_dly	;   		//i-32
input 	[31:0]	FMAC_TX_PKT_CNT;    		//i-32
input 	[31:0]	FMAC_RX_PKT_CNT_LO; 		//i-32
input 	[31:0]	FMAC_RX_PKT_CNT_HI; 		//i-32
      	
input 	[31:0]	FMAC_TX_BYTE_CNT;           // i-32
input 	[31:0]	FMAC_RX_BYTE_CNT_LO;        // i-32
input 	[31:0]	FMAC_RX_BYTE_CNT_HI;        // i-32
      	
input 	[31:0]	FMAC_RX_UNDERSIZE_PKT_CNT;  // i-32
input 	[31:0]	FMAC_RX_CRC_ERR_CNT;        // i-32
input 	[31:0]	FMAC_DCNT_OVERRUN;          // i-32
input 	[31:0]	FMAC_DCNT_LINK_ERR;         // i-32
input 	[31:0]	FMAC_PKT_CNT_OVERSIZE;      // i-32
input 	[31:0]	FMAC_PHY_STAT;              // i-32
input	[31:0]	fmac_ctrl1	;               // i-32

input	[31:0]	FMAC_PKT_CNT_JABBER		;	//i-32
input	[31:0]	FMAC_PKT_CNT_FRAGMENT	;	//i-32
input	[31:0]	FMAC_RAW_FRAME_CNT	;		//i-32
input	[31:0]	FMAC_BAD_FRAMESOF_CNT	;	//i-32
	
input	[31:0]	STAT_GROUP_LO_DOUT	;		// i-32, clk250
input	[31:0]	STAT_GROUP_HI_DOUT	;		// i-32, clk250
output	[9:0]	STAT_GROUP_addr	;			// o-10, address to select the register within the STAT GROUP
output			STAT_GROUP_sel	;			// o-1, 
output			fmac_rx_clr_en	;			// o-1, 
	
// Interface to mac_register
input			reg_rd_start;               //i-1
input			reg_rd_done;                //i-1
input 	[15:0]	host_addr_reg;              //i-16
input 	[3:0]	SYS_ADDR;                   //i-4

input			rx_auto_clr_en;             //i-1
input			tx_auto_clr_en;             //i-1

output 	[31:0]	FMAC_REGDOUT;               //o-32

//===================================================
//  VARIABLES
//===================================================
//variables for atomic controller
wire			atomic_cycle_mode;
reg				atm_latch_en;
reg				atm_latch_en_dly;      	
reg		[31:0]	local32_hi;								//keeping the upper 32 bit of the 64 bit reg
reg		[31:0]	my_local32_hi;							//temp mux
reg		[8:0]	atm_tag;								//keeping the addr of the previous reg read for checking matching
reg				atm_valid; 	   	
wire			tag_match;     	
                               	
reg				reg_rd_start_int;
reg				reg_rd_done_int;
reg				atomic_hi_en;							//enable the access to the ATOMIC HI register

reg		[31:0]	FMAC_RAW_FRAME_CNT_DLY1	;				//i-32
reg		[31:0]	FMAC_BAD_FRAMESOF_CNT_DLY1	;			//i-32

reg 	[8:0]	addr_buf0;
reg 	[9:0]	STAT_GROUP_addr;						//only bit 9:3 are used, for used by the new statistic regs
reg				upper32_addr;

reg				STAT_GROUP_sel;
reg				fmac_rx_clr_en;
reg				fmac_tx_clr_en;

reg		[3:0]	host_addr_int;							//only upper nibble of the host addr

always @ (posedge clk)
	begin
	addr_buf0	 <=	host_addr_reg[11:3];
	upper32_addr	<= host_addr_reg[2];
														//keeping the bit numbering the same as the address
	host_addr_int		<= host_addr_reg[15:12];
	STAT_GROUP_addr	 	<= {host_addr_reg[9:3], 3'b000} ;
														//use 1 bit for NO decoding
	STAT_GROUP_sel		<= host_addr_reg[11];
														//sys_addr is a constant
														//the DONE signal may be a clock too late and can cause conflict
	fmac_rx_clr_en			<= 
		!reset_ ? 1'b0 :
		(host_addr_int == SYS_ADDR) & reg_rd_done_int & rx_auto_clr_en ;
	fmac_tx_clr_en			<= 
		!reset_ ? 1'b0 :
		(host_addr_int == SYS_ADDR) & reg_rd_done_int & tx_auto_clr_en ;

	end
	
//================ STATISTIC & DIAGNOSTIC REGISTERS
parameter	[9:0]	FMAC_CTRL_addr							= 	10'h0_00;
parameter	[9:0]	FMAC_TX_PKT_CNT_addr					= 	10'h0_20;
																			//addr bit 2 indicates the lo or hi 32bit of 64 bit register
parameter 	[9:0]	FMAC_RX_PKT_CNT_addr					= 	10'h0_28;	// - RX_PKT_CNT_LO
parameter	[9:0]	FMAC_TX_BYTE_CNT_addr					= 	10'h0_30;	// - RX_BYTE_CNT_LO
														
parameter	[9:0]	FMAC_RX_BYTE_CNT_addr  					= 	10'h0_38;
parameter 	[9:0]	FMAC_RX_UNDERSIZE_PKT_CNT_addr			= 	10'h0_40;
parameter 	[9:0]	FMAC_RX_CRC_ERR_CNT_addr				= 	10'h0_48;
parameter	[9:0]	FMAC_DCNT_OVERRUN_addr 			   		= 	10'h0_50;
parameter	[9:0]	FMAC_DCNT_LINK_ERR_addr 		   		= 	10'h0_58;
parameter	[9:0]	FMAC_PKT_CNT_OVERSIZE_addr 		   		= 	10'h0_60;
parameter	[9:0]	FMAC_PHY_STAT_addr  			 		= 	10'h0_68;
parameter	[9:0]	FMAC_CTRL1_addr  			 			= 	10'h0_70;

parameter	[9:0]	FMAC_PKT_CNT_JABBER_addr 		   		= 	10'h0_78;
parameter	[9:0]	FMAC_PKT_CNT_FRAGMENT_addr 		   		= 	10'h0_80;
parameter	[9:0]	FMAC_RAW_FRAME_CNT_addr 		   		= 	10'h0_88;
parameter	[9:0]	FMAC_BAD_FRAMESOF_CNT_addr 		   		= 	10'h0_90;

// ========================================	
// Decode address to Select lines           	
// ======================================== 

wire		FMAC_CTRL_sel		;
wire		FMAC_TX_PKT_CNT_sel;
wire		FMAC_RX_PKT_CNT_sel;
wire		FMAC_TX_BYTE_CNT_sel;
wire		FMAC_RX_BYTE_CNT_sel;
wire		FMAC_RX_UNDERSIZE_PKT_CNT_sel;
wire	 	FMAC_RX_CRC_ERR_CNT_sel;
wire		FMAC_DCNT_OVERRUN_sel;
wire		FMAC_DCNT_LINK_ERR_sel;

wire		FMAC_PKT_CNT_OVERSIZE_sel;
wire		FMAC_PHY_STAT_sel;
wire		FMAC_CTRL1_sel		;

wire		FMAC_PKT_CNT_JABBER_sel		;
wire		FMAC_PKT_CNT_FRAGMENT_sel	;
wire		FMAC_RAW_FRAME_CNT_sel	;
wire		FMAC_BAD_FRAMESOF_CNT_sel	;

assign	FMAC_CTRL_sel					=	( addr_buf0[6:0] == FMAC_CTRL_addr[9:3]						); 
assign	FMAC_TX_PKT_CNT_sel				=	( addr_buf0[6:0] == FMAC_TX_PKT_CNT_addr[9:3]				); 
assign	FMAC_TX_BYTE_CNT_sel			=	( addr_buf0[6:0] == FMAC_TX_BYTE_CNT_addr[9:3]				); 
assign	FMAC_RX_PKT_CNT_sel				=	( addr_buf0[6:0] == FMAC_RX_PKT_CNT_addr[9:3]				); 
assign	FMAC_RX_BYTE_CNT_sel			=	( addr_buf0[6:0] == FMAC_RX_BYTE_CNT_addr[9:3]				); 
assign	FMAC_RX_UNDERSIZE_PKT_CNT_sel	=	( addr_buf0[6:0] == FMAC_RX_UNDERSIZE_PKT_CNT_addr[9:3]		); 
assign	FMAC_RX_CRC_ERR_CNT_sel			=	( addr_buf0[6:0] == FMAC_RX_CRC_ERR_CNT_addr[9:3]			);
assign	FMAC_DCNT_OVERRUN_sel			=	( addr_buf0[6:0] == FMAC_DCNT_OVERRUN_addr[9:3]				); 
assign	FMAC_DCNT_LINK_ERR_sel			=	( addr_buf0[6:0] == FMAC_DCNT_LINK_ERR_addr[9:3]			); 
assign	FMAC_PKT_CNT_OVERSIZE_sel		=	( addr_buf0[6:0] == FMAC_PKT_CNT_OVERSIZE_addr[9:3]			); 
assign	FMAC_PHY_STAT_sel				=	( addr_buf0[6:0] == FMAC_PHY_STAT_addr[9:3]					); 	
assign	FMAC_CTRL1_sel					=	( addr_buf0[6:0] == FMAC_CTRL1_addr[9:3]					); 
assign	FMAC_PKT_CNT_JABBER_sel			=	( addr_buf0[6:0] == FMAC_PKT_CNT_JABBER_addr[9:3]			); 
assign	FMAC_PKT_CNT_FRAGMENT_sel		=	( addr_buf0[6:0] == FMAC_PKT_CNT_FRAGMENT_addr[9:3]			); 
assign	FMAC_RAW_FRAME_CNT_sel			=	( addr_buf0[6:0] == FMAC_RAW_FRAME_CNT_addr[9:3]			); 
assign	FMAC_BAD_FRAMESOF_CNT_sel		=	( addr_buf0[6:0] == FMAC_BAD_FRAMESOF_CNT_addr[9:3]			); 

//=================================================
//DELAYED VERSION FOR READING - better timing
reg		DLY_FMAC_CTRL_sel		;
reg		DLY_FMAC_TX_PKT_CNT_sel;
reg		DLY_FMAC_RX_PKT_CNT_sel;
reg		DLY_FMAC_TX_BYTE_CNT_sel;
reg		DLY_FMAC_RX_BYTE_CNT_sel;
reg		DLY_FMAC_RX_UNDERSIZE_PKT_CNT_sel;
reg	 	DLY_FMAC_RX_CRC_ERR_CNT_sel;
reg		DLY_FMAC_DCNT_OVERRUN_sel;
reg		DLY_FMAC_DCNT_LINK_ERR_sel;
reg		DLY_FMAC_PKT_CNT_OVERSIZE_sel;
reg		DLY_FMAC_PHY_STAT_sel;
reg		DLY_FMAC_CTRL1_sel		;
reg		DLY_FMAC_PKT_CNT_JABBER_sel;
reg		DLY_FMAC_PKT_CNT_FRAGMENT_sel;
reg		DLY_FMAC_RAW_FRAME_CNT_sel;
reg		DLY_FMAC_BAD_FRAMESOF_CNT_sel;

always@(posedge clk)
begin
		DLY_FMAC_CTRL_sel					<= !reset_ ? 1'b0 : FMAC_CTRL_sel			      		;
		DLY_FMAC_TX_PKT_CNT_sel				<= !reset_ ? 1'b0 : FMAC_TX_PKT_CNT_sel			      	;
		DLY_FMAC_RX_PKT_CNT_sel				<= !reset_ ? 1'b0 : FMAC_RX_PKT_CNT_sel				   	;
		DLY_FMAC_TX_BYTE_CNT_sel			<= !reset_ ? 1'b0 : FMAC_TX_BYTE_CNT_sel			   	;
		DLY_FMAC_RX_BYTE_CNT_sel			<= !reset_ ? 1'b0 : FMAC_RX_BYTE_CNT_sel			   	;
		DLY_FMAC_RX_UNDERSIZE_PKT_CNT_sel	<= !reset_ ? 1'b0 : FMAC_RX_UNDERSIZE_PKT_CNT_sel		;
	 	DLY_FMAC_RX_CRC_ERR_CNT_sel			<= !reset_ ? 1'b0 : FMAC_RX_CRC_ERR_CNT_sel			    ;
		DLY_FMAC_DCNT_OVERRUN_sel			<= !reset_ ? 1'b0 : FMAC_DCNT_OVERRUN_sel			    ;
		DLY_FMAC_DCNT_LINK_ERR_sel			<= !reset_ ? 1'b0 : FMAC_DCNT_LINK_ERR_sel			    ;
		DLY_FMAC_PKT_CNT_OVERSIZE_sel		<= !reset_ ? 1'b0 : FMAC_PKT_CNT_OVERSIZE_sel		   	;
		DLY_FMAC_PHY_STAT_sel				<= !reset_ ? 1'b0 : FMAC_PHY_STAT_sel				    ;
		DLY_FMAC_CTRL1_sel					<= !reset_ ? 1'b0 : FMAC_CTRL1_sel			      		;
	
		DLY_FMAC_PKT_CNT_JABBER_sel			<= !reset_ ? 1'b0 : FMAC_PKT_CNT_JABBER_sel		   		;
		DLY_FMAC_PKT_CNT_FRAGMENT_sel		<= !reset_ ? 1'b0 : FMAC_PKT_CNT_FRAGMENT_sel		   	;
		DLY_FMAC_RAW_FRAME_CNT_sel			<= !reset_ ? 1'b0 : FMAC_RAW_FRAME_CNT_sel		   	;
		DLY_FMAC_BAD_FRAMESOF_CNT_sel		<= !reset_ ? 1'b0 : FMAC_BAD_FRAMESOF_CNT_sel		   	;
end
	
reg		[31:0]	REGU_GROUP_LO_DOUT;

// REGULAR GROUP register - LOW 32
always@(posedge clk)
	begin
		FMAC_RAW_FRAME_CNT_DLY1		<= !reset_ ? 32'h0	   	: FMAC_RAW_FRAME_CNT	;	
		FMAC_BAD_FRAMESOF_CNT_DLY1	<= !reset_ ? 32'h0 		: FMAC_BAD_FRAMESOF_CNT	;	
	
	REGU_GROUP_LO_DOUT		<=
	
			fmac_ctrl_dly 				&	{32{ DLY_FMAC_CTRL_sel					}}	| 
			fmac_ctrl1		 			&	{32{ DLY_FMAC_CTRL1_sel					}}	| 
			
			FMAC_TX_PKT_CNT 			&	{32{ DLY_FMAC_TX_PKT_CNT_sel			}}  | 
			FMAC_TX_BYTE_CNT 			&	{32{ DLY_FMAC_TX_BYTE_CNT_sel			}}  | 
			FMAC_RX_PKT_CNT_LO 			&	{32{ DLY_FMAC_RX_PKT_CNT_sel			}}  | 
			FMAC_RX_BYTE_CNT_LO 		&	{32{ DLY_FMAC_RX_BYTE_CNT_sel			}}  | 
			FMAC_RX_UNDERSIZE_PKT_CNT 	&	{32{ DLY_FMAC_RX_UNDERSIZE_PKT_CNT_sel	}}  | 
			FMAC_RX_CRC_ERR_CNT 		&	{32{ DLY_FMAC_RX_CRC_ERR_CNT_sel		}}  |
			FMAC_DCNT_OVERRUN 			&	{32{ DLY_FMAC_DCNT_OVERRUN_sel			}}  | 
			FMAC_DCNT_LINK_ERR 			&	{32{ DLY_FMAC_DCNT_LINK_ERR_sel			}}  | 
			FMAC_PKT_CNT_OVERSIZE 		&	{32{ DLY_FMAC_PKT_CNT_OVERSIZE_sel		}}  | 
			FMAC_PHY_STAT 				&	{32{ DLY_FMAC_PHY_STAT_sel				}}  |
			FMAC_PKT_CNT_JABBER 		&	{32{ DLY_FMAC_PKT_CNT_JABBER_sel		}}  | 
			
			FMAC_RAW_FRAME_CNT_DLY1 		&	{32{ DLY_FMAC_RAW_FRAME_CNT_sel			}}	|   
			FMAC_BAD_FRAMESOF_CNT_DLY1 		&	{32{ DLY_FMAC_BAD_FRAMESOF_CNT_sel		}}	| 
			FMAC_PKT_CNT_FRAGMENT 		&	{32{ DLY_FMAC_PKT_CNT_FRAGMENT_sel		}}   
			;	
		
	end

//NOTE:  The REGU_GROUP_HI only has 2 registers so output it directly rather than via a bus
//if more registers later, a bus may be needed for this group.
// ========================================	
// Muxing for FMAC_REGDOUT - SEE ATOMIC ENFORCEMENT BELOW
// ========================================
reg [31:0]	FMAC_REGDOUT;

always@(posedge clk)
begin
	//The address of the registers are structured for fast decode
	//bit 11:10 are used to decode which reg group within the FMAC
	//so at this level of muxing still preserve the old regs while allow room to add
	//new regs
	//bit 11:10 = 0 is for the old group
	//bit 11 = 1 is for the new statistic regs which are many
				
	FMAC_REGDOUT	<=						
							//REGULAR statistic group (for lower 32 bit only)
							{32{ !STAT_GROUP_sel & !upper32_addr	}} & 		REGU_GROUP_LO_DOUT	|
							//new statistic group (for lower 32 bit only)
							{32{  STAT_GROUP_sel & !upper32_addr	}} & 		STAT_GROUP_LO_DOUT	|							
							//data from the atomic mode controller (for the upper 32)
							//all upper 32 bit regs go through here
							{32{ atomic_hi_en }} & local32_hi
							;			
end

//=======================================
// ATOMIC CONTROLLER - Enforce ATOMICITY for 64 bit reg reads
//=======================================
// SW always read the lo of the 64 bit reg first
// the LO regs go directly to the MUX
// the HI is being kept in the ATOMIC reg
// need more precise timing to avoid stale data

//if detect a read to LO of PKT_CNT or BYTE_CNT (host_addr[2] = 0)
//only HW can write to these registers
assign		atomic_cycle_mode = 
							( !STAT_GROUP_sel & DLY_FMAC_RX_PKT_CNT_sel 	& !upper32_addr )
						|	( !STAT_GROUP_sel & DLY_FMAC_RX_BYTE_CNT_sel 	& !upper32_addr )
						//add the regs from the STAT GROUP
						|	(  STAT_GROUP_sel 		& !upper32_addr )
						
						;

	//HI access cycle
assign	tag_match	= (addr_buf0 == atm_tag);

//internal signals
always@(posedge clk)		//250MHz
	if (!reset_)
		begin
		reg_rd_start_int	<= 1'b0;
		reg_rd_done_int	<= 1'b0;
		end
	else
		begin
		reg_rd_start_int	<= reg_rd_start;	//reg_rd_start and done are from MAC_REG module
		reg_rd_done_int	<= reg_rd_done;	
		end
		

always@(posedge clk)	
begin
	
		//local ATMOMIC HI valid bit
	if (!reset_)
		atm_valid	<= 1'b0;
	else case (atm_valid)
		1'b0:
		atm_valid	<=
			//set on 1st latch, or keep
			atm_latch_en_dly & atomic_cycle_mode ? 1'b1 : 1'b0;
			
		1'b1:
		atm_valid	<=
			//negate on next read ending
			(reg_rd_done & tag_match & upper32_addr) ? 1'b0 : 1'b1;
			
		endcase

	//add reset for simulation
if (!reset_ )
	begin
	atm_latch_en		<= 1'b0 ;
	atm_latch_en_dly	<= 1'b0 ;
	local32_hi			<= 32'h0 ;
	atm_tag				<= 9'h0 ;
	my_local32_hi		<= 32'h0 ;
	atomic_hi_en		<= 1'b0 ;
	
	end
else
	begin		
	atm_latch_en		<= reg_rd_start_int & atomic_cycle_mode;	//enable latching if it's atomic access start
	atm_latch_en_dly	<= atm_latch_en;							//delay to wait for address propagation
	local32_hi			<= atm_latch_en_dly ? my_local32_hi : local32_hi;
	atm_tag				<= atm_latch_en_dly ? addr_buf0 : atm_tag;
				
	    //32 bit mux
		//this is used to mux 15 64 bit reg to 1
	my_local32_hi			<=
	                        	{32{ !STAT_GROUP_sel & DLY_FMAC_RX_PKT_CNT_sel	}} &	FMAC_RX_PKT_CNT_HI		
							|	{32{ !STAT_GROUP_sel & DLY_FMAC_RX_BYTE_CNT_sel	}} &	FMAC_RX_BYTE_CNT_HI		
							|	{32{  STAT_GROUP_sel			}} & 	STAT_GROUP_HI_DOUT
							
									;
	
	atomic_hi_en	<=
			//clr if see reg_rd_done
			atomic_hi_en & reg_rd_done ? 1'b0 :
			//set, if this cycle matches my tag
			//need to allow the data to drive back as soon as possible for downstream to latch
			atm_valid & tag_match & upper32_addr ? 1'b1 :
			//keep otherwise
			atomic_hi_en
			;
	end
			
end



endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns / 1ps
// synopsys translate_on

module fmac_saddr_filter
(
	clk,							// i-1
	rst_,							// i-1
// Input from mac_regs
	mcast_en,           
	mcast_saddr,					// i-128
// Inputs from mac_ppr
	mac_saddr,						// i-128
	mac_saddr_vld,					// i-1
// Output
	saddr_filter_drop				// o-1
);


// In / Out
input    clk;				// i-1
input    rst_;				// i-1

input        mcast_en ;
input [47:0] mcast_saddr;

input [47:0] mac_saddr;
input         mac_saddr_vld;

output  saddr_filter_drop ;

// Sigs

reg match0;
reg match1;
reg match2;
reg match3;
reg match4;
reg match5;

reg saddr_filter_drop ;

// Logic
//===========
// Comparators
//===========
always@(posedge clk)
begin
	if(!rst_)
	begin
		match0 <= 1'b0 ;	
		match1 <= 1'b0 ;	
		match2 <= 1'b0 ;	
		match3 <= 1'b0 ;	
		match4 <= 1'b0 ;	
		match5 <= 1'b0 ;	
	end
	else
	begin
		match0 <= mac_saddr_vld ? (mac_saddr[47:40]   == mcast_saddr[47:40])    : 1'b0 ;
		match1 <= mac_saddr_vld ? (mac_saddr[39:32]   == mcast_saddr[39:32])   : 1'b0 ;
		match2 <= mac_saddr_vld ? (mac_saddr[31:24]   == mcast_saddr[31:24])   : 1'b0 ;
		match3 <= mac_saddr_vld ? (mac_saddr[23:16]   == mcast_saddr[23:16])   : 1'b0 ;
		match4 <= mac_saddr_vld ? (mac_saddr[15:08]   == mcast_saddr[15:08])   : 1'b0 ;
		match5 <= mac_saddr_vld ? (mac_saddr[07:00]   == mcast_saddr[07:00])   : 1'b0 ;
	end
end


// Logic
//===========
// SADDR Filter
// FSM
//===========
reg [2:0] saddr_filter_st ;

parameter [2:0]
	 SADDR_FILTER_IDLE= 3'b001,
	 SADDR_FILTER_CHK=		3'b010,
	 SADDR_FILTER_END=		3'b100;
	 
always@(posedge clk)
begin
	if(!rst_)
	begin
		saddr_filter_st <= SADDR_FILTER_IDLE ;
		saddr_filter_drop <= 1'b0 ;
	end
	else
	begin
		case(saddr_filter_st)
		
		SADDR_FILTER_IDLE:
		begin
			saddr_filter_st <= mac_saddr_vld ? SADDR_FILTER_CHK : SADDR_FILTER_IDLE ;
		end
		
		SADDR_FILTER_CHK:
		begin
			saddr_filter_st <= SADDR_FILTER_END ;
			// Ipv6 Filter ( intsruct Rx to Drop Pkt) 
			saddr_filter_drop <= !mcast_en ?  1'b0 : 
					     ( match0 & match1 &
						match2 & match3 &
						match4 & match5 ) ? 1'b0 : 1'b1 ;
		end		
	
		SADDR_FILTER_END:
		begin
			saddr_filter_st <= SADDR_FILTER_IDLE ;
			saddr_filter_drop <= 1'b0 ;
		end
		
		default:
		begin
			saddr_filter_st <= SADDR_FILTER_IDLE ;
		end
		endcase
	end
end


endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


`timescale 1ns / 1ns                                                                                                                                               

module g2x_ctrl(
            
    clk,				// i-1
	reset_,				// i-1
	fmac_speed,			// i-2
	
	gf_bcnt_empty,		// i-1
	
	data_in,			// i-64
	ctrl_in,			// i-8
	bcnt_in,			// i-16
	
	gige_bcnt_fifo_re,	// o-1
	gige_data_fifo_re,	// o-1
	
	data_out,			// o-64
	ctrl_out,			// o-8
	            		
	dbg					// o-1, test
);

	input       		clk;                // i-1      
	input				reset_;             // i-1      
	input		[ 1:0]	fmac_speed;         // i-2      
	                                                    
	input				gf_bcnt_empty;      // i-1      
	                                                    
	input		[63:0]	data_in;            // i-64     
	input		[ 7:0] 	ctrl_in;            // i-8      
	input		[15:0] 	bcnt_in;            // i-16     
	        	                                        
	output	reg 		gige_bcnt_fifo_re;	// o-1      
	output	reg 		gige_data_fifo_re;  // o-1      
	                                                    
	output	reg	[63:0]	data_out;           // o-64     
	output	reg	[ 7:0] 	ctrl_out;           // o-8      
	                                                    
	output  reg 		dbg;                // o-1, test

	reg			[15:0] 	qwd_cnt;			//counts the number of QWD for every packet
	reg 				gige_data_fifo_re_dly1;

			
	//State Machine to read from the gige_rx_bcnt_fifo
	reg		[7:0] 	gf_state;
	
	wire			gf_idle_st;			//IDLE
	wire			gf_rd_bcnt_st;      //read BCNT from bcnt_fifo
	wire			gf_bcnt_buf_st;     //buffer state one clk
	wire			gf_rd_data_st;      //read data
	wire			gf_done_st;         //DONE
	
		
	parameter [7:0]       
			GF_IDLE   		= 	8'h01,  
			GF_RD_BCNT		= 	8'h02, 
			GF_BCNT_BUF		= 	8'h04, 
			GF_RD_DATA	    = 	8'h08,		
			GF_DONE   		= 	8'h80;    
	
				
	assign	gf_idle_st		= 	gf_state[0];   
	assign  gf_rd_bcnt_st	= 	gf_state[1];             
	assign  gf_bcnt_buf_st	= 	gf_state[2];             
	assign	gf_rd_data_st	= 	gf_state[3];   
	assign	gf_done_st		= 	gf_state[7];
		
	
	always @ (posedge clk) begin             
	               	                                
		if (!reset_) begin   
		                       
			gf_state			<=	GF_IDLE ; 
			
			dbg					<=	1'b0;
		     
		end  
		                          
		else begin                          
		                               
			if (gf_idle_st)              
					//if bcnt_fifo is not empty, then there is at least one packet
					gf_state	<=	(!gf_bcnt_empty)? GF_RD_BCNT : GF_IDLE;                            
					                             					                             
			else if (gf_rd_bcnt_st)
					//read bcnt              
					gf_state	<=	GF_BCNT_BUF;
					  
			else if (gf_bcnt_buf_st) 
					//keep bcnt for one clock             
					gf_state	<=	GF_RD_DATA;  
											
			else if (gf_rd_data_st)  
					//read_data till its done                        
					gf_state	<=	(qwd_cnt == 16'b0)? GF_DONE : GF_RD_DATA;		
			 
			else if (gf_done_st)                          		
					gf_state	<=	GF_IDLE;                       	  		
		 			    									                          		                             
		end                 
	                                
	end		
	


	always @ (posedge clk) begin
	
	    if(!reset_) begin

	        gige_bcnt_fifo_re	<=	1'b0;
	        gige_data_fifo_re	<=	1'b0;
	    	                  
	    	data_out			<=	64'h0707_0707_0707_0707;
	        ctrl_out			<=	8'hff;
	        
	        qwd_cnt				<=	16'b0;
			gige_bcnt_fifo_re	<=	1'b0;
			gige_data_fifo_re	<=	1'b0;
			
			gige_data_fifo_re_dly1	<=	1'b0;
	                
		end
	    else begin

	    	gige_data_fifo_re_dly1	<=	gige_data_fifo_re;
	    
	    	//data and ctrl out depend on read_en_dly
	    	data_out			<=	(gige_data_fifo_re_dly1)?	data_in : 64'h0707_0707_0707_0707;
	        ctrl_out			<=	(gige_data_fifo_re_dly1)?	ctrl_in : 8'hff;
	    	        
	    	if (gf_idle_st) begin
	    		gige_bcnt_fifo_re	<=	(!gf_bcnt_empty)? 1'b1 : 1'b0;
	    	end
			else if (gf_rd_bcnt_st) begin
				gige_bcnt_fifo_re	<=	1'b0;
			end
			else if (gf_bcnt_buf_st) begin
				//count the number of quad-words from the byte_count value
				qwd_cnt				<=	(bcnt_in[15:3] + (|bcnt_in[2:0]));
			end
			else if (gf_rd_data_st) begin
				//decrement qwd_cnt after reading data
				qwd_cnt				<=	(qwd_cnt == 16'b0)? 16'b0 : (qwd_cnt - 1'b1);
				gige_data_fifo_re	<=	(qwd_cnt == 16'b0)? 1'b0  : 1'b1;
			end
			else begin
				qwd_cnt				<=	16'b0;
				gige_bcnt_fifo_re	<=	1'b0;
				gige_data_fifo_re	<=	1'b0;
			end
	    	        					
		end
	 
	end	
	
	
	
	//============== Simulation ONLY =======================//
	//synopsys translate_off                                  
		                                                         
	reg [64*8-1:0] ascii_gf_state;                          
	                                                          
	always@(gf_state)                                       
	begin                                                     
		case(gf_state)                                         
	    	GF_IDLE   	:	ascii_gf_state	=	"GF_IDLE";        
			GF_RD_BCNT	:	ascii_gf_state	=	"GF_RD_BCNT";          
			GF_BCNT_BUF	:	ascii_gf_state	=	"GF_BCNT_BUF";          
			GF_RD_DATA	:	ascii_gf_state	=	"GF_RD_DATA";            
			GF_DONE   	:	ascii_gf_state	=	"GF_DONE";
		endcase                                                  
	end 
	     
	//synopsys translate_on

	
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//

`timescale 1ns/10ps

module gige_crc32x64(
   	clk,                            //i-1
   	rst_,                           //i-1
                                        
   	pulse_0,                        //i-1
   	pulse_1,                        //i-1
   	mode_1G, mode_100M, mode_10M,	//i-1
   	crc_cnt,						//i-16
   	wcnt,                           //i-16
   	st_DAT_6,                       //i-1
   	
   	clr_,                          	//i-1
   	bytes,                          //i-3
   	we_,                            //i-1
   	last_,                          //i-1
   	cdin,                           //i-64
   	pdin,                           //i-64
   	
   	crc32,                          //o-32
   	crc32_vld_                      //o-1
    );
   
input 	clk;
input 	rst_;
input 	clr_;

input 	pulse_0;
input 	pulse_1;
input 	mode_1G, mode_100M, mode_10M;
input 	st_DAT_6;
input 	[15:0] wcnt;
input 	[15:0] crc_cnt;

input 	[63:0] cdin;
input 	[63:0] pdin;
input 	[02:0] bytes;
input 	we_;
input 	last_;
output 	[31:0] crc32;
output 	crc32_vld_;
reg    	crc32_vld_;
reg    	[31:0] new_crc;
wire 	[63:0] din_int;
reg 	we_int_;
reg 	last_int_;
reg 	[31:0] init_value;
reg 	[63:0] bdin;


parameter[02:0] 
    IDLE	= 3'h1 ,
	CALC  	= 3'h2 ,
	WAIT1 	= 3'h4 ;
reg [02:0] state;

assign din_int[63:0] = {
		    bdin[0], bdin[1], bdin[2], bdin[3], bdin[4], bdin[5], bdin[6], bdin[7],
		    bdin[8], bdin[9], bdin[10], bdin[11], bdin[12], bdin[13], bdin[14], bdin[15], 
		    bdin[16], bdin[17], bdin[18], bdin[19], bdin[20], bdin[21], bdin[22], bdin[23],
		    bdin[24], bdin[25], bdin[26], bdin[27], bdin[28], bdin[29], bdin[30], bdin[31], 
		    bdin[32], bdin[33], bdin[34], bdin[35], bdin[36], bdin[37], bdin[38], bdin[39], 
		    bdin[40], bdin[41], bdin[42], bdin[43], bdin[44], bdin[45], bdin[46], bdin[47], 
		    bdin[48], bdin[49], bdin[50], bdin[51], bdin[52], bdin[53], bdin[54], bdin[55],
		    bdin[56], bdin[57], bdin[58], bdin[59], bdin[60], bdin[61], bdin[62], bdin[63]};

assign crc32 = ~{new_crc[24],new_crc[25],new_crc[26],new_crc[27],new_crc[28],new_crc[29],new_crc[30],new_crc[31],new_crc[16],new_crc[17],new_crc[18],new_crc[19],new_crc[20],
                new_crc[21],new_crc[22],new_crc[23],new_crc[8],new_crc[9],new_crc[10],new_crc[11],new_crc[12],new_crc[13],new_crc[14],new_crc[15],new_crc[0],new_crc[1],
                new_crc[2],new_crc[3],new_crc[4],new_crc[5],new_crc[6],new_crc[7]};
              
always@(bytes)
begin
	case(bytes)
	0: init_value = 32'hffffffff;
	1: init_value = 32'h955a6162;
	2: init_value = 32'h68b932f5;
	3: init_value = 32'h339fde2f;
	4: init_value = 32'h46af6449;
	5: init_value = 32'h816474c5;
	6: init_value = 32'h09b93859;
	7: init_value = 32'h9bf1a90f;
	endcase
end

always@(posedge clk)
begin

	if(!rst_) begin
		new_crc	<=	32'b0;
		bdin	<=	64'b0;
	end
	else begin
	
	new_crc   <=   mode_1G ? ( state[0] ? init_value : ((state[1] & !we_int_) ? nextCRC32_D64(din_int,new_crc) : new_crc) ) :
	               ( ((state[0] & pulse_0)? init_value : ((state[1] & !we_int_) ? nextCRC32_D64(din_int,new_crc) : new_crc))   );

	case(bytes)
    0: bdin <=   mode_1G? cdin  :
                 (pulse_0? cdin : bdin);
                 
	1: bdin <=   mode_1G? ( state[0] ? {cdin[7:0], 56'h0} : {cdin[7:0], pdin[63:8]} ) :
	             ( pulse_0? ( state[0]? {cdin[7:0], 56'h0} : {cdin[7:0], pdin[63:8]} )   : bdin );
	             	             
	2: bdin <=   mode_1G? ( state[0] ? {cdin[15:0], 48'h0} : {cdin[15:0], pdin[63:16]} ) :
	             ( pulse_0? (state[0] ? {cdin[15:0], 48'h0} : {cdin[15:0], pdin[63:16]}) : bdin );
	             
	3: bdin <=   mode_1G? ( state[0] ? {cdin[23:0], 40'h0} : {cdin[23:0], pdin[63:24]} ) :
	             ( pulse_0? (state[0]? {cdin[23:0], 40'h0} : {cdin[23:0], pdin[63:24]}) : bdin );
	             
	4: bdin <=   mode_1G? ( state[0] ? {cdin[31:0], 32'h0} : {cdin[31:0], pdin[63:32]} ) :
	             ( pulse_0? (state[0]? {cdin[31:0], 32'h0} : {cdin[31:0], pdin[63:32]}) : bdin );
	             
	5: bdin <=   mode_1G? ( state[0] ? {cdin[39:0], 24'h0} : {cdin[39:0], pdin[63:40]} ):
	             ( pulse_0? (state[0]? {cdin[39:0], 24'h0} : {cdin[39:0], pdin[63:40]}) : bdin );
	             
	6: bdin <=   mode_1G? ( state[0] ? {cdin[47:0], 16'h0} : {cdin[47:0], pdin[63:48]} ) :
	             ( pulse_0? (state[0]? {cdin[47:0], 16'h0} : {cdin[47:0], pdin[63:48]}) : bdin );
	             
	7: bdin <=   mode_1G? ( state[0] ? {cdin[55:0], 8'h0}  : {cdin[55:0], pdin[63:56]} ) :
	             ( pulse_0? (state[0]? {cdin[55:0], 8'h0}  : {cdin[55:0], pdin[63:56]}) : bdin );
	endcase
	
	end
end

always@(posedge clk)
if(!rst_)
begin
	state   <=   IDLE;
	we_int_ <=   1'b1;
	crc32_vld_<=   1'b1;
	last_int_ <=   1'b1;
end
else
begin
	we_int_  <=  mode_1G?  we_ :
	            ( !crc_cnt[15]? !(st_DAT_6 & pulse_1) : 1'b1);
	last_int_ <=  mode_1G? last_ :
	             ( (wcnt[15] & !crc_cnt[15])? !(st_DAT_6 & pulse_1) : last_int_);
	crc32_vld_<=   last_int_;
	
	case(state)
	IDLE: 
	begin
		state   <=   we_ ? IDLE : CALC;
	end
	CALC:
	begin
		state   <=   last_int_ ? CALC : WAIT1;
	end
	WAIT1:
	begin
		state   <=   mode_1G? (clr_ ? WAIT1 : IDLE) : 
		             ( (!clr_ & pulse_0)? IDLE : WAIT1);
	end
	default:
	begin
		state <=   IDLE;
	end
	endcase
end

function [31:0] nextCRC32_D64;

    input [63:0] Data;
    input [31:0] CRC;

    reg [63:0] D;
    reg [31:0] C;
    reg [31:0] NewCRC;
//CRC logic
  begin

    D = Data;
    C = CRC;

    NewCRC[0] = D[63] ^ D[61] ^ D[60] ^ D[58] ^ D[55] ^ D[54] ^ D[53] ^ 
                D[50] ^ D[48] ^ D[47] ^ D[45] ^ D[44] ^ D[37] ^ D[34] ^ 
                D[32] ^ D[31] ^ D[30] ^ D[29] ^ D[28] ^ D[26] ^ D[25] ^ 
                D[24] ^ D[16] ^ D[12] ^ D[10] ^ D[9] ^ D[6] ^ D[0] ^ 
                C[0] ^ C[2] ^ C[5] ^ C[12] ^ C[13] ^ C[15] ^ C[16] ^ 
                C[18] ^ C[21] ^ C[22] ^ C[23] ^ C[26] ^ C[28] ^ C[29] ^ 
                C[31];
    NewCRC[1] = D[63] ^ D[62] ^ D[60] ^ D[59] ^ D[58] ^ D[56] ^ D[53] ^ 
                D[51] ^ D[50] ^ D[49] ^ D[47] ^ D[46] ^ D[44] ^ D[38] ^ 
                D[37] ^ D[35] ^ D[34] ^ D[33] ^ D[28] ^ D[27] ^ D[24] ^ 
                D[17] ^ D[16] ^ D[13] ^ D[12] ^ D[11] ^ D[9] ^ D[7] ^ 
                D[6] ^ D[1] ^ D[0] ^ C[1] ^ C[2] ^ C[3] ^ C[5] ^ C[6] ^ 
                C[12] ^ C[14] ^ C[15] ^ C[17] ^ C[18] ^ C[19] ^ C[21] ^ 
                C[24] ^ C[26] ^ C[27] ^ C[28] ^ C[30] ^ C[31];
    NewCRC[2] = D[59] ^ D[58] ^ D[57] ^ D[55] ^ D[53] ^ D[52] ^ D[51] ^ 
                D[44] ^ D[39] ^ D[38] ^ D[37] ^ D[36] ^ D[35] ^ D[32] ^ 
                D[31] ^ D[30] ^ D[26] ^ D[24] ^ D[18] ^ D[17] ^ D[16] ^ 
                D[14] ^ D[13] ^ D[9] ^ D[8] ^ D[7] ^ D[6] ^ D[2] ^ 
                D[1] ^ D[0] ^ C[0] ^ C[3] ^ C[4] ^ C[5] ^ C[6] ^ C[7] ^ 
                C[12] ^ C[19] ^ C[20] ^ C[21] ^ C[23] ^ C[25] ^ C[26] ^ 
                C[27];
    NewCRC[3] = D[60] ^ D[59] ^ D[58] ^ D[56] ^ D[54] ^ D[53] ^ D[52] ^ 
                D[45] ^ D[40] ^ D[39] ^ D[38] ^ D[37] ^ D[36] ^ D[33] ^ 
                D[32] ^ D[31] ^ D[27] ^ D[25] ^ D[19] ^ D[18] ^ D[17] ^ 
                D[15] ^ D[14] ^ D[10] ^ D[9] ^ D[8] ^ D[7] ^ D[3] ^ 
                D[2] ^ D[1] ^ C[0] ^ C[1] ^ C[4] ^ C[5] ^ C[6] ^ C[7] ^ 
                C[8] ^ C[13] ^ C[20] ^ C[21] ^ C[22] ^ C[24] ^ C[26] ^ 
                C[27] ^ C[28];
    NewCRC[4] = D[63] ^ D[59] ^ D[58] ^ D[57] ^ D[50] ^ D[48] ^ D[47] ^ 
                D[46] ^ D[45] ^ D[44] ^ D[41] ^ D[40] ^ D[39] ^ D[38] ^ 
                D[33] ^ D[31] ^ D[30] ^ D[29] ^ D[25] ^ D[24] ^ D[20] ^ 
                D[19] ^ D[18] ^ D[15] ^ D[12] ^ D[11] ^ D[8] ^ D[6] ^ 
                D[4] ^ D[3] ^ D[2] ^ D[0] ^ C[1] ^ C[6] ^ C[7] ^ C[8] ^ 
                C[9] ^ C[12] ^ C[13] ^ C[14] ^ C[15] ^ C[16] ^ C[18] ^ 
                C[25] ^ C[26] ^ C[27] ^ C[31];
    NewCRC[5] = D[63] ^ D[61] ^ D[59] ^ D[55] ^ D[54] ^ D[53] ^ D[51] ^ 
                D[50] ^ D[49] ^ D[46] ^ D[44] ^ D[42] ^ D[41] ^ D[40] ^ 
                D[39] ^ D[37] ^ D[29] ^ D[28] ^ D[24] ^ D[21] ^ D[20] ^ 
                D[19] ^ D[13] ^ D[10] ^ D[7] ^ D[6] ^ D[5] ^ D[4] ^ 
                D[3] ^ D[1] ^ D[0] ^ C[5] ^ C[7] ^ C[8] ^ C[9] ^ C[10] ^ 
                C[12] ^ C[14] ^ C[17] ^ C[18] ^ C[19] ^ C[21] ^ C[22] ^ 
                C[23] ^ C[27] ^ C[29] ^ C[31];
    NewCRC[6] = D[62] ^ D[60] ^ D[56] ^ D[55] ^ D[54] ^ D[52] ^ D[51] ^ 
                D[50] ^ D[47] ^ D[45] ^ D[43] ^ D[42] ^ D[41] ^ D[40] ^ 
                D[38] ^ D[30] ^ D[29] ^ D[25] ^ D[22] ^ D[21] ^ D[20] ^ 
                D[14] ^ D[11] ^ D[8] ^ D[7] ^ D[6] ^ D[5] ^ D[4] ^ 
                D[2] ^ D[1] ^ C[6] ^ C[8] ^ C[9] ^ C[10] ^ C[11] ^ 
                C[13] ^ C[15] ^ C[18] ^ C[19] ^ C[20] ^ C[22] ^ C[23] ^ 
                C[24] ^ C[28] ^ C[30];
    NewCRC[7] = D[60] ^ D[58] ^ D[57] ^ D[56] ^ D[54] ^ D[52] ^ D[51] ^ 
                D[50] ^ D[47] ^ D[46] ^ D[45] ^ D[43] ^ D[42] ^ D[41] ^ 
                D[39] ^ D[37] ^ D[34] ^ D[32] ^ D[29] ^ D[28] ^ D[25] ^ 
                D[24] ^ D[23] ^ D[22] ^ D[21] ^ D[16] ^ D[15] ^ D[10] ^ 
                D[8] ^ D[7] ^ D[5] ^ D[3] ^ D[2] ^ D[0] ^ C[0] ^ C[2] ^ 
                C[5] ^ C[7] ^ C[9] ^ C[10] ^ C[11] ^ C[13] ^ C[14] ^ 
                C[15] ^ C[18] ^ C[19] ^ C[20] ^ C[22] ^ C[24] ^ C[25] ^ 
                C[26] ^ C[28];
    NewCRC[8] = D[63] ^ D[60] ^ D[59] ^ D[57] ^ D[54] ^ D[52] ^ D[51] ^ 
                D[50] ^ D[46] ^ D[45] ^ D[43] ^ D[42] ^ D[40] ^ D[38] ^ 
                D[37] ^ D[35] ^ D[34] ^ D[33] ^ D[32] ^ D[31] ^ D[28] ^ 
                D[23] ^ D[22] ^ D[17] ^ D[12] ^ D[11] ^ D[10] ^ D[8] ^ 
                D[4] ^ D[3] ^ D[1] ^ D[0] ^ C[0] ^ C[1] ^ C[2] ^ C[3] ^ 
                C[5] ^ C[6] ^ C[8] ^ C[10] ^ C[11] ^ C[13] ^ C[14] ^ 
                C[18] ^ C[19] ^ C[20] ^ C[22] ^ C[25] ^ C[27] ^ C[28] ^ 
                C[31];
    NewCRC[9] = D[61] ^ D[60] ^ D[58] ^ D[55] ^ D[53] ^ D[52] ^ D[51] ^ 
                D[47] ^ D[46] ^ D[44] ^ D[43] ^ D[41] ^ D[39] ^ D[38] ^ 
                D[36] ^ D[35] ^ D[34] ^ D[33] ^ D[32] ^ D[29] ^ D[24] ^ 
                D[23] ^ D[18] ^ D[13] ^ D[12] ^ D[11] ^ D[9] ^ D[5] ^ 
                D[4] ^ D[2] ^ D[1] ^ C[0] ^ C[1] ^ C[2] ^ C[3] ^ C[4] ^ 
                C[6] ^ C[7] ^ C[9] ^ C[11] ^ C[12] ^ C[14] ^ C[15] ^ 
                C[19] ^ C[20] ^ C[21] ^ C[23] ^ C[26] ^ C[28] ^ C[29];
    NewCRC[10] = D[63] ^ D[62] ^ D[60] ^ D[59] ^ D[58] ^ D[56] ^ D[55] ^ 
                 D[52] ^ D[50] ^ D[42] ^ D[40] ^ D[39] ^ D[36] ^ D[35] ^ 
                 D[33] ^ D[32] ^ D[31] ^ D[29] ^ D[28] ^ D[26] ^ D[19] ^ 
                 D[16] ^ D[14] ^ D[13] ^ D[9] ^ D[5] ^ D[3] ^ D[2] ^ 
                 D[0] ^ C[0] ^ C[1] ^ C[3] ^ C[4] ^ C[7] ^ C[8] ^ C[10] ^ 
                 C[18] ^ C[20] ^ C[23] ^ C[24] ^ C[26] ^ C[27] ^ C[28] ^ 
                 C[30] ^ C[31];
    NewCRC[11] = D[59] ^ D[58] ^ D[57] ^ D[56] ^ D[55] ^ D[54] ^ D[51] ^ 
                 D[50] ^ D[48] ^ D[47] ^ D[45] ^ D[44] ^ D[43] ^ D[41] ^ 
                 D[40] ^ D[36] ^ D[33] ^ D[31] ^ D[28] ^ D[27] ^ D[26] ^ 
                 D[25] ^ D[24] ^ D[20] ^ D[17] ^ D[16] ^ D[15] ^ D[14] ^ 
                 D[12] ^ D[9] ^ D[4] ^ D[3] ^ D[1] ^ D[0] ^ C[1] ^ C[4] ^ 
                 C[8] ^ C[9] ^ C[11] ^ C[12] ^ C[13] ^ C[15] ^ C[16] ^ 
                 C[18] ^ C[19] ^ C[22] ^ C[23] ^ C[24] ^ C[25] ^ C[26] ^ 
                 C[27];
    NewCRC[12] = D[63] ^ D[61] ^ D[59] ^ D[57] ^ D[56] ^ D[54] ^ D[53] ^ 
                 D[52] ^ D[51] ^ D[50] ^ D[49] ^ D[47] ^ D[46] ^ D[42] ^ 
                 D[41] ^ D[31] ^ D[30] ^ D[27] ^ D[24] ^ D[21] ^ D[18] ^ 
                 D[17] ^ D[15] ^ D[13] ^ D[12] ^ D[9] ^ D[6] ^ D[5] ^ 
                 D[4] ^ D[2] ^ D[1] ^ D[0] ^ C[9] ^ C[10] ^ C[14] ^ 
                 C[15] ^ C[17] ^ C[18] ^ C[19] ^ C[20] ^ C[21] ^ C[22] ^ 
                 C[24] ^ C[25] ^ C[27] ^ C[29] ^ C[31];
    NewCRC[13] = D[62] ^ D[60] ^ D[58] ^ D[57] ^ D[55] ^ D[54] ^ D[53] ^ 
                 D[52] ^ D[51] ^ D[50] ^ D[48] ^ D[47] ^ D[43] ^ D[42] ^ 
                 D[32] ^ D[31] ^ D[28] ^ D[25] ^ D[22] ^ D[19] ^ D[18] ^ 
                 D[16] ^ D[14] ^ D[13] ^ D[10] ^ D[7] ^ D[6] ^ D[5] ^ 
                 D[3] ^ D[2] ^ D[1] ^ C[0] ^ C[10] ^ C[11] ^ C[15] ^ 
                 C[16] ^ C[18] ^ C[19] ^ C[20] ^ C[21] ^ C[22] ^ C[23] ^ 
                 C[25] ^ C[26] ^ C[28] ^ C[30];
    NewCRC[14] = D[63] ^ D[61] ^ D[59] ^ D[58] ^ D[56] ^ D[55] ^ D[54] ^ 
                 D[53] ^ D[52] ^ D[51] ^ D[49] ^ D[48] ^ D[44] ^ D[43] ^ 
                 D[33] ^ D[32] ^ D[29] ^ D[26] ^ D[23] ^ D[20] ^ D[19] ^ 
                 D[17] ^ D[15] ^ D[14] ^ D[11] ^ D[8] ^ D[7] ^ D[6] ^ 
                 D[4] ^ D[3] ^ D[2] ^ C[0] ^ C[1] ^ C[11] ^ C[12] ^ 
                 C[16] ^ C[17] ^ C[19] ^ C[20] ^ C[21] ^ C[22] ^ C[23] ^ 
                 C[24] ^ C[26] ^ C[27] ^ C[29] ^ C[31];
    NewCRC[15] = D[62] ^ D[60] ^ D[59] ^ D[57] ^ D[56] ^ D[55] ^ D[54] ^ 
                 D[53] ^ D[52] ^ D[50] ^ D[49] ^ D[45] ^ D[44] ^ D[34] ^ 
                 D[33] ^ D[30] ^ D[27] ^ D[24] ^ D[21] ^ D[20] ^ D[18] ^ 
                 D[16] ^ D[15] ^ D[12] ^ D[9] ^ D[8] ^ D[7] ^ D[5] ^ 
                 D[4] ^ D[3] ^ C[1] ^ C[2] ^ C[12] ^ C[13] ^ C[17] ^ 
                 C[18] ^ C[20] ^ C[21] ^ C[22] ^ C[23] ^ C[24] ^ C[25] ^ 
                 C[27] ^ C[28] ^ C[30];
    NewCRC[16] = D[57] ^ D[56] ^ D[51] ^ D[48] ^ D[47] ^ D[46] ^ D[44] ^ 
                 D[37] ^ D[35] ^ D[32] ^ D[30] ^ D[29] ^ D[26] ^ D[24] ^ 
                 D[22] ^ D[21] ^ D[19] ^ D[17] ^ D[13] ^ D[12] ^ D[8] ^ 
                 D[5] ^ D[4] ^ D[0] ^ C[0] ^ C[3] ^ C[5] ^ C[12] ^ C[14] ^ 
                 C[15] ^ C[16] ^ C[19] ^ C[24] ^ C[25];
    NewCRC[17] = D[58] ^ D[57] ^ D[52] ^ D[49] ^ D[48] ^ D[47] ^ D[45] ^ 
                 D[38] ^ D[36] ^ D[33] ^ D[31] ^ D[30] ^ D[27] ^ D[25] ^ 
                 D[23] ^ D[22] ^ D[20] ^ D[18] ^ D[14] ^ D[13] ^ D[9] ^ 
                 D[6] ^ D[5] ^ D[1] ^ C[1] ^ C[4] ^ C[6] ^ C[13] ^ C[15] ^ 
                 C[16] ^ C[17] ^ C[20] ^ C[25] ^ C[26];
    NewCRC[18] = D[59] ^ D[58] ^ D[53] ^ D[50] ^ D[49] ^ D[48] ^ D[46] ^ 
                 D[39] ^ D[37] ^ D[34] ^ D[32] ^ D[31] ^ D[28] ^ D[26] ^ 
                 D[24] ^ D[23] ^ D[21] ^ D[19] ^ D[15] ^ D[14] ^ D[10] ^ 
                 D[7] ^ D[6] ^ D[2] ^ C[0] ^ C[2] ^ C[5] ^ C[7] ^ C[14] ^ 
                 C[16] ^ C[17] ^ C[18] ^ C[21] ^ C[26] ^ C[27];
    NewCRC[19] = D[60] ^ D[59] ^ D[54] ^ D[51] ^ D[50] ^ D[49] ^ D[47] ^ 
                 D[40] ^ D[38] ^ D[35] ^ D[33] ^ D[32] ^ D[29] ^ D[27] ^ 
                 D[25] ^ D[24] ^ D[22] ^ D[20] ^ D[16] ^ D[15] ^ D[11] ^ 
                 D[8] ^ D[7] ^ D[3] ^ C[0] ^ C[1] ^ C[3] ^ C[6] ^ C[8] ^ 
                 C[15] ^ C[17] ^ C[18] ^ C[19] ^ C[22] ^ C[27] ^ C[28];
    NewCRC[20] = D[61] ^ D[60] ^ D[55] ^ D[52] ^ D[51] ^ D[50] ^ D[48] ^ 
                 D[41] ^ D[39] ^ D[36] ^ D[34] ^ D[33] ^ D[30] ^ D[28] ^ 
                 D[26] ^ D[25] ^ D[23] ^ D[21] ^ D[17] ^ D[16] ^ D[12] ^ 
                 D[9] ^ D[8] ^ D[4] ^ C[1] ^ C[2] ^ C[4] ^ C[7] ^ C[9] ^ 
                 C[16] ^ C[18] ^ C[19] ^ C[20] ^ C[23] ^ C[28] ^ C[29];
    NewCRC[21] = D[62] ^ D[61] ^ D[56] ^ D[53] ^ D[52] ^ D[51] ^ D[49] ^ 
                 D[42] ^ D[40] ^ D[37] ^ D[35] ^ D[34] ^ D[31] ^ D[29] ^ 
                 D[27] ^ D[26] ^ D[24] ^ D[22] ^ D[18] ^ D[17] ^ D[13] ^ 
                 D[10] ^ D[9] ^ D[5] ^ C[2] ^ C[3] ^ C[5] ^ C[8] ^ C[10] ^ 
                 C[17] ^ C[19] ^ C[20] ^ C[21] ^ C[24] ^ C[29] ^ C[30];
    NewCRC[22] = D[62] ^ D[61] ^ D[60] ^ D[58] ^ D[57] ^ D[55] ^ D[52] ^ 
                 D[48] ^ D[47] ^ D[45] ^ D[44] ^ D[43] ^ D[41] ^ D[38] ^ 
                 D[37] ^ D[36] ^ D[35] ^ D[34] ^ D[31] ^ D[29] ^ D[27] ^ 
                 D[26] ^ D[24] ^ D[23] ^ D[19] ^ D[18] ^ D[16] ^ D[14] ^ 
                 D[12] ^ D[11] ^ D[9] ^ D[0] ^ C[2] ^ C[3] ^ C[4] ^ 
                 C[5] ^ C[6] ^ C[9] ^ C[11] ^ C[12] ^ C[13] ^ C[15] ^ 
                 C[16] ^ C[20] ^ C[23] ^ C[25] ^ C[26] ^ C[28] ^ C[29] ^ 
                 C[30];
    NewCRC[23] = D[62] ^ D[60] ^ D[59] ^ D[56] ^ D[55] ^ D[54] ^ D[50] ^ 
                 D[49] ^ D[47] ^ D[46] ^ D[42] ^ D[39] ^ D[38] ^ D[36] ^ 
                 D[35] ^ D[34] ^ D[31] ^ D[29] ^ D[27] ^ D[26] ^ D[20] ^ 
                 D[19] ^ D[17] ^ D[16] ^ D[15] ^ D[13] ^ D[9] ^ D[6] ^ 
                 D[1] ^ D[0] ^ C[2] ^ C[3] ^ C[4] ^ C[6] ^ C[7] ^ C[10] ^ 
                 C[14] ^ C[15] ^ C[17] ^ C[18] ^ C[22] ^ C[23] ^ C[24] ^ 
                 C[27] ^ C[28] ^ C[30];
    NewCRC[24] = D[63] ^ D[61] ^ D[60] ^ D[57] ^ D[56] ^ D[55] ^ D[51] ^ 
                 D[50] ^ D[48] ^ D[47] ^ D[43] ^ D[40] ^ D[39] ^ D[37] ^ 
                 D[36] ^ D[35] ^ D[32] ^ D[30] ^ D[28] ^ D[27] ^ D[21] ^ 
                 D[20] ^ D[18] ^ D[17] ^ D[16] ^ D[14] ^ D[10] ^ D[7] ^ 
                 D[2] ^ D[1] ^ C[0] ^ C[3] ^ C[4] ^ C[5] ^ C[7] ^ C[8] ^ 
                 C[11] ^ C[15] ^ C[16] ^ C[18] ^ C[19] ^ C[23] ^ C[24] ^ 
                 C[25] ^ C[28] ^ C[29] ^ C[31];
    NewCRC[25] = D[62] ^ D[61] ^ D[58] ^ D[57] ^ D[56] ^ D[52] ^ D[51] ^ 
                 D[49] ^ D[48] ^ D[44] ^ D[41] ^ D[40] ^ D[38] ^ D[37] ^ 
                 D[36] ^ D[33] ^ D[31] ^ D[29] ^ D[28] ^ D[22] ^ D[21] ^ 
                 D[19] ^ D[18] ^ D[17] ^ D[15] ^ D[11] ^ D[8] ^ D[3] ^ 
                 D[2] ^ C[1] ^ C[4] ^ C[5] ^ C[6] ^ C[8] ^ C[9] ^ C[12] ^ 
                 C[16] ^ C[17] ^ C[19] ^ C[20] ^ C[24] ^ C[25] ^ C[26] ^ 
                 C[29] ^ C[30];
    NewCRC[26] = D[62] ^ D[61] ^ D[60] ^ D[59] ^ D[57] ^ D[55] ^ D[54] ^ 
                 D[52] ^ D[49] ^ D[48] ^ D[47] ^ D[44] ^ D[42] ^ D[41] ^ 
                 D[39] ^ D[38] ^ D[31] ^ D[28] ^ D[26] ^ D[25] ^ D[24] ^ 
                 D[23] ^ D[22] ^ D[20] ^ D[19] ^ D[18] ^ D[10] ^ D[6] ^ 
                 D[4] ^ D[3] ^ D[0] ^ C[6] ^ C[7] ^ C[9] ^ C[10] ^ C[12] ^ 
                 C[15] ^ C[16] ^ C[17] ^ C[20] ^ C[22] ^ C[23] ^ C[25] ^ 
                 C[27] ^ C[28] ^ C[29] ^ C[30];
    NewCRC[27] = D[63] ^ D[62] ^ D[61] ^ D[60] ^ D[58] ^ D[56] ^ D[55] ^ 
                 D[53] ^ D[50] ^ D[49] ^ D[48] ^ D[45] ^ D[43] ^ D[42] ^ 
                 D[40] ^ D[39] ^ D[32] ^ D[29] ^ D[27] ^ D[26] ^ D[25] ^ 
                 D[24] ^ D[23] ^ D[21] ^ D[20] ^ D[19] ^ D[11] ^ D[7] ^ 
                 D[5] ^ D[4] ^ D[1] ^ C[0] ^ C[7] ^ C[8] ^ C[10] ^ C[11] ^ 
                 C[13] ^ C[16] ^ C[17] ^ C[18] ^ C[21] ^ C[23] ^ C[24] ^ 
                 C[26] ^ C[28] ^ C[29] ^ C[30] ^ C[31];
    NewCRC[28] = D[63] ^ D[62] ^ D[61] ^ D[59] ^ D[57] ^ D[56] ^ D[54] ^ 
                 D[51] ^ D[50] ^ D[49] ^ D[46] ^ D[44] ^ D[43] ^ D[41] ^ 
                 D[40] ^ D[33] ^ D[30] ^ D[28] ^ D[27] ^ D[26] ^ D[25] ^ 
                 D[24] ^ D[22] ^ D[21] ^ D[20] ^ D[12] ^ D[8] ^ D[6] ^ 
                 D[5] ^ D[2] ^ C[1] ^ C[8] ^ C[9] ^ C[11] ^ C[12] ^ 
                 C[14] ^ C[17] ^ C[18] ^ C[19] ^ C[22] ^ C[24] ^ C[25] ^ 
                 C[27] ^ C[29] ^ C[30] ^ C[31];
    NewCRC[29] = D[63] ^ D[62] ^ D[60] ^ D[58] ^ D[57] ^ D[55] ^ D[52] ^ 
                 D[51] ^ D[50] ^ D[47] ^ D[45] ^ D[44] ^ D[42] ^ D[41] ^ 
                 D[34] ^ D[31] ^ D[29] ^ D[28] ^ D[27] ^ D[26] ^ D[25] ^ 
                 D[23] ^ D[22] ^ D[21] ^ D[13] ^ D[9] ^ D[7] ^ D[6] ^ 
                 D[3] ^ C[2] ^ C[9] ^ C[10] ^ C[12] ^ C[13] ^ C[15] ^ 
                 C[18] ^ C[19] ^ C[20] ^ C[23] ^ C[25] ^ C[26] ^ C[28] ^ 
                 C[30] ^ C[31];
    NewCRC[30] = D[63] ^ D[61] ^ D[59] ^ D[58] ^ D[56] ^ D[53] ^ D[52] ^ 
                 D[51] ^ D[48] ^ D[46] ^ D[45] ^ D[43] ^ D[42] ^ D[35] ^ 
                 D[32] ^ D[30] ^ D[29] ^ D[28] ^ D[27] ^ D[26] ^ D[24] ^ 
                 D[23] ^ D[22] ^ D[14] ^ D[10] ^ D[8] ^ D[7] ^ D[4] ^ 
                 C[0] ^ C[3] ^ C[10] ^ C[11] ^ C[13] ^ C[14] ^ C[16] ^ 
                 C[19] ^ C[20] ^ C[21] ^ C[24] ^ C[26] ^ C[27] ^ C[29] ^ 
                 C[31];
    NewCRC[31] = D[62] ^ D[60] ^ D[59] ^ D[57] ^ D[54] ^ D[53] ^ D[52] ^ 
                 D[49] ^ D[47] ^ D[46] ^ D[44] ^ D[43] ^ D[36] ^ D[33] ^ 
                 D[31] ^ D[30] ^ D[29] ^ D[28] ^ D[27] ^ D[25] ^ D[24] ^ 
                 D[23] ^ D[15] ^ D[11] ^ D[9] ^ D[8] ^ D[5] ^ C[1] ^ 
                 C[4] ^ C[11] ^ C[12] ^ C[14] ^ C[15] ^ C[17] ^ C[20] ^ 
                 C[21] ^ C[22] ^ C[25] ^ C[27] ^ C[28] ^ C[30];

    nextCRC32_D64 = NewCRC;

  end
  endfunction
  
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


`timescale 1ns / 1ns

module gige_rx 
	(
	
	clk,		    // i-1                                                                                             
	reset_,			// i-1
	fmac_speed,	    // i-2                                                                                         
	                                                                                    
	data_in_s2p,    // i-8                                                                                  
	ctrl_in_s2p,    // i-1                                                                                 
	pdet_in_s2p,	// i-1
	gmii_rx_dv,	    // i-1                                                                                          
	                                                                                    
	loopback_en,     // i-1                                                                                                 
	sfp_los,	     // i-1                                                                                                    

	gige_rx_dout,	 // o-64
	gige_rx_cout,	 // o-8
	
	linkup,      	 // o-1
	
	dbg        		 // o-1
	
	);
		
	  
	input 				clk;		        // i-1                                                               
	input 				reset_;				// i-1
	input	[ 1:0]		fmac_speed;	        // i-2                                                        
	 				                                                            
	input	[ 7:0]		data_in_s2p;         // i-8                                                  
	input 				ctrl_in_s2p;         // i-1                                                   
	input 				pdet_in_s2p;		// i-1
	input				gmii_rx_dv;	         // i-1                                                   
	 				                                                            
	input 				loopback_en;         // i-1                                                                   
	input 				sfp_los;	         // i-1                                                                      
	
	output	[63:0]		gige_rx_dout;		 // o-64
	output	[ 7:0]		gige_rx_cout;		 // o-8
	
	output				linkup;				 // o-1
	
	output				dbg;	
	
		
	wire				dbg = 0;		
	
	wire	[63:0]		data_out_s2p;		  //to the g_fifo
	wire	[ 7:0]		ctrl_out_s2p;		  //to the g_fifo
	
	wire				linkup;
	wire				x_we; 				  //to the g_fifo
	
	wire				x_bcnt_we;
	wire	[15:0]		x_byte_cnt;

	wire				gf_bcnt_empty;
	
	wire	[63:0]		data_in;
	wire	[ 7:0]		ctrl_in;
	wire	[15:0]		bcnt_in;
	
	wire				gige_bcnt_fifo_re;
	wire				gige_data_fifo_re;
	
	
	
	gige_s2p gige_s2p 
	(
		.clk			(clk),				// i-1
		.reset_			(reset_),			// i-1
		.fmac_speed		(fmac_speed),		// i-2
		
		.data_in		(data_in_s2p),		// i-8
		.ctrl_in		(ctrl_in_s2p),		// i-1
		.pdet_in		(pdet_in_s2p),		// i-1
		.gmii_rx_dv		(gmii_rx_dv),		// i-1
		            	            
		.data_out		(data_out_s2p),		// o-64
		.ctrl_out		(ctrl_out_s2p),		// o-8
		
		.loopback_en	(1'b0),				// i-1
		.sfp_los		(1'b0),				// i-1
		
		.linkup			(linkup),			// o-1
		.x_we			(x_we), 			// o-1
		
		.x_bcnt_we		(x_bcnt_we),		// o-1
		.x_byte_cnt		(x_byte_cnt)		// o-1
	);
	
	
	gigerx_fifo256x64_2clk gigerx_fifo256x64_2clk
	(
		.aclr			(reset_),
		 
		.wrclk			(clk),      	 // Clk for writing data
		.wrreq			(x_we),      	 // request to write 
		.data			(data_out_s2p),  // Data coming in                   
		.full			(),       	
		        	                         
		.rdclk			(clk),				// rd clock
		.rdreq			(gige_data_fifo_re),  // Request to read from FIFO
		.q				(data_in),			  // Data coming out
		.empty			(),  	 			
		.usedw			()					
	);


	gigerx_fifo256x8 gigerx_fifo256x8
	(
		.aclr			(reset_),
		 
		.wrclk			(clk),      		// Clk for writing data
		.wrreq			(x_we),      		// request to write
		.data			(ctrl_out_s2p),	    // Data coming in               
		.full			(),       		
		        	                         
		.rdclk			(clk),				  // rd clock
		.rdreq			(gige_data_fifo_re),  // Request to read from FIFO
		.q				(ctrl_in),			  // Data coming out 
		.empty			(),  	 			
		.usedw			()       			
	);
	
	
	gigerx_bcnt_fifo256x16 gigerx_bcnt_fifo256x16
	(
		.aclr			(reset_),
		 
		.wrclk			(clk),         // Clk for writing data
		.wrreq			(x_bcnt_we),   // request to write
		.data			(x_byte_cnt),  // Data coming in              
		.full			(),       	
		        	                      
		.rdclk			(clk),				  // rd clock
		.rdreq			(gige_bcnt_fifo_re),  // Request to read from FIFO
		.q				(bcnt_in),			  // Data coming out
		.empty			(gf_bcnt_empty),	  // indicates fifo is empty or not (to avoid underflow)
		.usedw			()       			
	);


	g2x_ctrl g2x_ctrl
	(
	            
	    .clk			(clk),				// i-1	
		.reset_			(reset_),			// i-1	
		.fmac_speed		(fmac_speed),		// i-2	
		                                		
		.gf_bcnt_empty	(gf_bcnt_empty),	// i-1	
		                                		
		.data_in		(data_in),			// i-64	
		.ctrl_in		(ctrl_in),			// i-8	
		.bcnt_in		(bcnt_in),			// i-16	
		
		.gige_bcnt_fifo_re	(gige_bcnt_fifo_re),   // o-1
		.gige_data_fifo_re	(gige_data_fifo_re),   // o-1
		
		.data_out		(gige_rx_dout),		// o-64	
		.ctrl_out		(gige_rx_cout),		// o-8	
		                                		
		.dbg			()						
	);

	

endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns / 1ns                                                                                                                                               
// synopsys translate_on

module gige_s2p (
		clk,					 //i-1, FMAC clk, 125Mhz
		reset_,					 //i-1, Reset signal
		fmac_speed, 			 //i-2, FMAC Speed 2-bit wide
		
		
		
		data_in,				 //i-8, Data in signal from PHY
		ctrl_in,				 //i-1, Ctrl in signal from PHY
		pdet_in,				 //i-1, pattern detect
		gmii_rx_dv,				 //i-1, Valid data signal
		
		data_out,				 //o-64, Output in parallel 64-bit form
		ctrl_out,				 //o-8, Output ctrl sign in parallel 8-bit
		
		loopback_en,			 //i-1, loopback signal
		sfp_los,				 //i-1, 
		linkup,					 //o-1
		x_we,					 //o-1, Write Signal for Gige FIFO
		x_bcnt_we,				 //o-1, Write Signal for Byte Count FIFO
		x_byte_cnt				 //o-32, Byte Count of every Packet
	);

input 			clk;			 //i-1, FMAC clk, 125Mhz
input 			reset_;			 //i-1, Reset signal
input	[1:0]	fmac_speed;		 //i-2, FMAC Speed 2-bit wide
input 	[7:0]	data_in;		 //i-8, Data in signal from PHY
input 			ctrl_in;		 //i-1, Ctrl in signal from PHY
input			pdet_in;		 //i-1, pattern detect
input			gmii_rx_dv;		 //i-1, Valid data signal

output	[63:0]	data_out;		 //o-64, Output in parallel 64-bit form
output	[07:0]	ctrl_out;		 //o-8, Output ctrl sign in parallel 8-bit

input			loopback_en;	 //i-1, loopback signal
input			sfp_los;		 //i-1, 
output			linkup;			 //o-1
output          x_we;			 //o-1, Write Signal for Gige FIFO
output          x_bcnt_we;		 //o-1, Write Signal for Byte Count FIFO
output	[15:0]	x_byte_cnt;		 //o-32, Byte Count of every Packet

reg			linkup;
reg         x_we;
reg         x_bcnt_we;
reg [15:0]	x_byte_cnt;


reg 	[7:0]	data_in_dly;	 //Delayed data
reg 			ctrl_in_dly;

reg			frame;				 //Shows how much data coming in to the module is valid or how long the packet lasts
reg			insert;

reg			sof;				 //Start of Frame
reg			eof;				 //End of Frame

reg			eof0;				 //Packet End on byte 0
reg			eof1;				 //Packet End on byte 1
reg			eof2;				 //Packet End on byte 2
reg			eof3;				 //Packet End on byte 3
reg			eof4;				 //Packet End on byte 4
reg			eof5;				 //Packet End on byte 5
reg			eof6;				 //Packet End on byte 6
reg	[15:0]	count;				 //Counter to give out parallel valid data

reg			pvld;				 //Shows if the data in parallel is valid or not

reg [63:0]	data_out;
reg [7:0]	ctrl_out;

reg [7:0]	dff0, dff1, dff2, dff3, dff4, dff5, dff6, dff7;
reg 		cff0, cff1, cff2, cff3, cff4, cff5, cff6, cff7;

wire [63:0] pdata = {dff0, dff1, dff2, dff3, dff4, dff5, dff6, dff7};
wire [7:0]	pctrl = {cff0, cff1, cff2, cff3, cff4, cff5, cff6, cff7};

reg 		eof_dly1;
reg 		eof_dly2;
reg	[7:0]	counter2;
reg [15:0]	count100;

reg		pulse10 ;
reg		pulse100;
reg		eof_seen ;
reg		pulse10_dly1;
reg		pulse100_dly1;

reg frame_dly1;


 
always @ (posedge clk)
begin
	if (!reset_)
	begin
		data_in_dly <= 8'h07;
		ctrl_in_dly <= 1'b1; 
	
		frame <= 1'b0;
		insert <= 1'b0;
		
		sof <= 1'b0;
		eof <= 1'b0;
		eof_dly1 <= 1'b0;
		eof_dly2 <= 1'b0;
		eof_seen <= 1'b0 ;
		
		eof0 <= 1'b0;
		eof1 <= 1'b0;
		eof2 <= 1'b0;
		eof3 <= 1'b0;
		eof4 <= 1'b0;
		eof5 <= 1'b0;
		eof6 <= 1'b0;
		
		count <= 16'h0;
		pvld <= 1'b0;
		
		data_out <= 64'h0707_0707_0707_0707;
		ctrl_out <= 8'hff;
		x_bcnt_we <= 1'b0;
		x_we <= 1'b0;
		
		pulse10 <= 1'b0;
		x_byte_cnt <= 16'h0;
		pulse10_dly1 <= 1'b0;
	end
	
	else
	begin

		data_in_dly <= data_in;
		ctrl_in_dly <= ctrl_in;
	
		frame <= (ctrl_in & (data_in == 8'hfb))? 1'b1 : ((ctrl_in & (data_in == 8'hfd))? 1'b0 : frame);
		insert <= frame & !ctrl_in;
	
		sof <= ctrl_in & (data_in == 8'hfb);
		eof <= ctrl_in & (data_in == 8'hfd);
		eof_dly1	<= eof ;
		eof_dly2 <= eof_dly1;
		eof_seen	<=
			frame & !frame_dly1 ? 1'b0 :
			eof & !eof_dly1 ? 1'b1 :
			eof_seen ;
		
		if (fmac_speed == 2'd1)
			begin                  
				eof0 <= eof & (count == 16'd7);
				eof1 <= eof & (count == 16'd6);
				eof2 <= eof & (count == 16'd5);
				eof3 <= eof & (count == 16'd4);
				eof4 <= eof & (count == 16'd3);
				eof5 <= eof & (count == 16'd2);
				eof6 <= eof & (count == 16'd1);
				
				count <= (frame & count != 16'h0)? (count - 16'h1) : 16'h7 ;   //Down Counter for 8 counts
				
				x_byte_cnt <= (data_in == 8'hfb & ctrl_in) ? 16'd1 :		   //Calculate byte count
						(frame) ? x_byte_cnt + 16'd1 :     
						x_byte_cnt;                                       
				
		        x_bcnt_we <= eof_dly2;										   //Wite to byte count fifo once byte count calculated
				
			end
			
		else if (fmac_speed == 2'd2)
			begin
				eof0 <= eof & (count == 16'd69);
			    eof1 <= eof & (count == 16'd59);
			    eof2 <= eof & (count == 16'd49);
			    eof3 <= eof & (count == 16'd39);
			    eof4 <= eof & (count == 16'd29);
			    eof5 <= eof & (count == 16'd19);
			    eof6 <= eof & (count == 16'd09);
			    
			    count <= 
					(frame & !frame_dly1) ? 16'd77 :
					( count != 16'h0)? (count - 16'h1) : 16'd79 ;
				
				x_byte_cnt <= (data_in == 8'hfb & ctrl_in) ? 16'd1 :	
						(pulse10_dly1 & frame) ? x_byte_cnt + 16'd1 :     	
						x_byte_cnt;                                       	
						
				x_bcnt_we <= (eof & counter2 == 8'd0) ? 1'b1 :
    						1'b0;
    						
			end
			
		else if (fmac_speed == 2'd3)
			begin
			    eof0 <= eof & (count == 16'd699);
			    eof1 <= eof & (count == 16'd599);
			    eof2 <= eof & (count == 16'd499);
			    eof3 <= eof & (count == 16'd399);
			    eof4 <= eof & (count == 16'd299);
			    eof5 <= eof & (count == 16'd199);
			    eof6 <= eof & (count == 16'd099);
			
				count <= 
					(frame & !frame_dly1) ? 16'd797 :
					( count != 16'h0)? (count - 16'h1) : 16'd799 ;
					
				x_byte_cnt <= (data_in == 8'hfb & ctrl_in) ? 16'd1 :	
						(pulse100_dly1 & frame) ? x_byte_cnt + 16'd1 :     	
						x_byte_cnt;                                       	
					
					
				x_bcnt_we <= (eof & count100 == 16'd0) ? 1'b1 :
							1'b0;
											
		    end
		    			
		pvld <= (count == 16'h1);	
				
		
		casez ({linkup, pvld, eof0, eof1, eof2, eof3, eof4, eof5, eof6})
		9'b11???????:// data within the frame
				begin
				data_out <= pdata;
		        ctrl_out <= pctrl;
		        
		        x_we <=  (fmac_speed == 2'b01)?	1'b1 :
		        			((frame & frame_dly1) | (pvld & eof))? 1'b1:
		        				1'b0; 			
	        						
				end
		
		9'b101??????:// eof on lane 0
				begin
				data_out <= 64'h0707_0707_0707_07fd;
		        ctrl_out <= 8'hff;
		        x_we <= 1'b1;                  
				end
				
		9'b1001?????:// eof on lane 1
				begin
				data_out <= {56'h070707070707fd, dff2};
		        ctrl_out <= {7'b1111111, cff2};
		        x_we <= 1'b1;                  
				end
				
		9'b10001????:// eof on lane 2
				begin
				data_out <= {48'h0707070707fd, dff2, dff3};
		        ctrl_out <= {6'b111111, cff2, cff3};
		        x_we <= 1'b1;                  
				end
				
		9'b100001???:// eof on lane 3
				begin
				data_out <= {40'h07070707fd, dff2, dff3, dff4};
		        ctrl_out <= {5'b11111, cff2, cff3, cff4};
		        x_we <= 1'b1;      
				end
		
		9'b1000001??:// eof on lane 4
				begin
				data_out <= {32'h070707fd, dff2, dff3, dff4, dff5};
		        ctrl_out <= {4'b1111, cff2, cff3, cff4, cff5};
		        x_we <= 1'b1;   
				end
				
		9'b10000001?:// eof on lane 5
				begin
				data_out <= {24'h0707fd, dff2, dff3, dff4, dff5, dff6};
		        ctrl_out <= {3'b111, cff2, cff3, cff4, cff5, cff6};
		        x_we <= 1'b1;   
				end
				
		9'b100000001:// eof on lane 6
				begin
				data_out <= {16'h07fd, dff2, dff3, dff4, dff5, dff6, dff7};
		        ctrl_out <= {2'b11, cff2, cff3, cff4, cff5, cff6, cff7};
		        x_we <= 1'b1;   
				end
		// If eof on lane 7, it is multiple of 8, pvld will take care of it		
		default:
				begin
				data_out <= 64'h0707_0707_0707_0707;
		        ctrl_out <= 8'hff;
		        x_we <= 1'b0;                  
				end
		endcase
		
	end
end


always @ (posedge clk)
begin
	frame_dly1 <= frame;
		//count relative to data_in
	counter2 <= 
		(!reset_) ? 8'h0 :
		(frame & !frame_dly1) ? 8'd2 :	//initialize (count 0 already passed due to delay)
		(counter2 != 8'h9)? (counter2 + 8'h1) : 8'h0 ;
		
	count100 <=                                                                 
		(!reset_) ? 16'h0 :                                                         	
		(frame & !frame_dly1) ? 16'd2 :	//initialize (count 0 already passed due to delay)	
		(count100 != 16'h63)? (count100 + 16'h1) : 16'h0 ;                             		
	
	pulse100 <=
		(!reset_) ? 1'h0 :
		(count100 == 16'd98) ;
	
	pulse10	<= 
		(!reset_) ? 1'h0 :
		(counter2 == 8'd8) ;
	
	pulse10_dly1 <= pulse10;
	pulse100_dly1 <= pulse100;
	
	
	if (!reset_)
		begin
		dff0 <= 8'b0;
		dff1 <= 8'b0;
		dff2 <= 8'b0;
		dff3 <= 8'b0;
		dff4 <= 8'b0;
		dff5 <= 8'b0;
		dff6 <= 8'b0;
		dff7 <= 8'b0;
		
		cff0 <= 1'b0;
		cff1 <= 1'b0;
		cff2 <= 1'b0;
		cff3 <= 1'b0;
		cff4 <= 1'b0;
		cff5 <= 1'b0;
		cff6 <= 1'b0;
		cff7 <= 1'b0;
		end
	else if (fmac_speed == 2'd1)		//1G
		begin
		dff0 <= data_in;
		dff1 <= dff0;
		dff2 <= dff1;
		dff3 <= dff2;
		dff4 <= dff3;
		dff5 <= dff4;
		dff6 <= dff5;
		dff7 <= dff6;
		
		cff0 <= ctrl_in;
		cff1 <= cff0;
		cff2 <= cff1;
		cff3 <= cff2;
		cff4 <= cff3;
		cff5 <= cff4;
		cff6 <= cff5;
		cff7 <= cff6;
		end
	else if (fmac_speed ==2'd2)		//100M
		begin
		if ((counter2 == 8'h0) | (frame & !frame_dly1))
			begin
				dff0 <= data_in;
				dff1 <= dff0;
				dff2 <= dff1;
				dff3 <= dff2;
				dff4 <= dff3;
				dff5 <= dff4;
				dff6 <= dff5;
				dff7 <= dff6;
				
				cff0 <= ctrl_in;
				cff1 <= cff0;
				cff2 <= cff1;
				cff3 <= cff2;
				cff4 <= cff3;
				cff5 <= cff4;
				cff6 <= cff5;
				cff7 <= cff6;
			end
		end
	else if (fmac_speed == 2'd3)	//10M
		begin
		if ((count100 == 16'h0) | (frame & !frame_dly1))
			begin
				dff0 <= data_in;	
			    dff1 <= dff0;   
			    dff2 <= dff1;   
			    dff3 <= dff2;   
			    dff4 <= dff3;   
			    dff5 <= dff4;   
			    dff6 <= dff5;   
			    dff7 <= dff6;   
			                    
			    cff0 <= ctrl_in;
			    cff1 <= cff0;   
			    cff2 <= cff1;   
			    cff3 <= cff2;   
			    cff4 <= cff3;   
			    cff5 <= cff4;   
			    cff6 <= cff5;   
			    cff7 <= cff6;
			end   		
		end		
end


reg pdet_in_dly;
reg idle_detect;
reg [7:0] consec_idle;	// use to detect 4 consecutive idle pattern
reg link_ok;
reg	link_break;
reg real_los;

always @ (posedge clk)
begin
	if (!reset_)
	begin
		pdet_in_dly <= 1'b0;
		idle_detect <= 1'b0;
		consec_idle <= 8'h0;
		link_ok 	<= 1'b0;
		link_break	<= 1'b0;
		real_los	<= 1'b0;
		linkup		<= 1'b0;
	end
	
	else
	begin
		pdet_in_dly <= pdet_in;
		idle_detect <= pdet_in | pdet_in_dly;
		consec_idle <= linkup? 8'h00 : {consec_idle[6:0], idle_detect};
		link_ok		<= (consec_idle == 8'hff) & !real_los;
		link_break	<= (pdata == 64'h0000_42BC_0000_B5BC) | real_los;
		real_los	<= (sfp_los & !loopback_en);
		linkup		<= link_ok? 1'b1 : (link_break? 1'b0 : linkup);
	end
end

endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//

// synopsys translate_off
`timescale 1ns/10ps
// synopsys translate_on

module gige_tx_encap(
	clk,					  //i, clock 125Mhz
	rst_,					  //i, reset
	fmac_speed ,       		  //i-2, for differetn speed modes.
	
	rts,					  //o, request to send data to gmii.
	wdata,					  //o, data output of encap
	rbytes,					  //o, indicates the size of the data.
	cts,				

	psaddr,					  //i,
	mac_pause_value,		  //i,
	tx_b2b_dly,				  //i,
	
	rx_pause,   			  //i,
	rx_pvalue,         		  //i,
	rx_pack,          		  //o,
	
	txfifo_empty,			  //i, an event indicating fifo is empty
	txfifo_rd_en,    		   //o, an event to read data from the FIFO.
	txfifo_dout,  			  //i, input data
	
	xreq,					  //i,
	xon,					  //i,
	xdone					  //o,

	);
	
input [47:0] psaddr;			  
input [31:0] mac_pause_value;
input [1:0]	 tx_b2b_dly;
				
input txfifo_empty;				  //an event indicating FIFO is empty
output txfifo_rd_en;			  //an event, if high == reads data from the FIFO

input [63:0] txfifo_dout;		 //input data

input clk;						 //clock 125Mhz
input rst_;						 //reset
input [1:0] fmac_speed    ;		 // for different speed modes

output rts;					   //request to send data to gmii
output [63:0] wdata;			//output data
output [15:0] rbytes;		   // stores total byte size of data
input	cts;				   // clear to send. starts sending data to gmii. 

input rx_pause;
input [15:0] rx_pvalue;
output rx_pack;

input	xreq; 	          
input	xon;   
output	xdone; 

reg txfifo_rd_en;				 //an event to read data from the FIFO.
reg [15:0] rbytes;               //indicates the size of the data.
reg rts;                         //request to send data to gmii.
reg [63:0] wdata;                //data output of encap         

reg wsel;
reg [16:0] ptimer;
reg [5:0] p_reg_count;
reg p_start;

reg tx_rdy;		
reg rx_pack;
reg rx_pause_sync;
reg [15:0] rx_pvalue_sync;

reg [15:0] bytes_remain;          //number of bytes left to transmit
reg [3:0] count8;

reg [7:0] counter;				// to make module compatible for slow speeds
reg pulse_0;
reg pulse_1;


   //speed modes
wire    mode_1G   =   (fmac_speed == 2'b01) ;
wire    mode_100M =   (fmac_speed == 2'b10) ;
wire    mode_10M  =   (fmac_speed == 2'b11) ;
	
//setting default values
parameter[7:0] 
	IDLE		= 8'h01 ,
	READSIZE	= 8'h02 ,
	READ1		= 8'h04 ,
	WAIT		= 8'h08 ,
	MAC_DAT     = 8'h10 ,
	P_REQ		= 8'h20 ,
	P_PREAM		= 8'h40 ,
	P_PKT		= 8'h80	;
reg [7:0] state;

wire st_idle;		assign	st_idle		=	state[0];
wire st_readsize;	assign	st_readsize = 	state[1];
wire st_read1;	    assign	st_read1    = 	state[2];
wire st_wait;	    assign	st_wait    = 	state[3];
wire st_mac_dat;	assign	st_mac_dat	=	state[4];
wire st_p_req;		assign	st_p_req 	=	state[5];
wire st_p_pkt;		assign 	st_p_pkt	=	state[7];

reg tx_dvld;					 //shows valid data


reg [8:0] b2b_cnt_val ;
always @(posedge clk)
begin
	if(!rst_)
	begin
		b2b_cnt_val <= 9'd0 ;
	end
	else
	begin
		case(tx_b2b_dly)
		2'b01 : b2b_cnt_val <= 9'd13 ; 	
		2'b10 : b2b_cnt_val <= 9'd61 ; 	
		2'b11 : b2b_cnt_val <= 9'd509 ; 
		default: b2b_cnt_val <= 9'd0 ; 
		endcase
	end
end

reg [8:0] b2b_counter;
reg		  b2b_ok;
always @ (posedge clk)
begin
	if (!rst_)
	begin
		b2b_counter	<=	9'd0;
		b2b_ok		<=	1'b1;
	end
	
	else
	begin
		b2b_counter <= (st_mac_dat)? b2b_cnt_val : ((st_idle & |b2b_counter)? (b2b_counter - 9'd1) : b2b_counter);
		b2b_ok		<=	!(|b2b_counter);
	end
end

always @ (posedge clk)
begin
	rx_pause_sync <=   rx_pause;
	rx_pvalue_sync<=   rx_pvalue;
end

always @ (posedge clk)
begin
	if (!rst_)
	begin
		ptimer <=   17'h1ffff;
		p_reg_count <=   6'd63 ;
		p_start <=   0;
	end
	
	else
	begin
		ptimer    <=   rx_pause_sync ? {rx_pvalue_sync - 17'h1} : (ptimer[16] ? ptimer : ((|p_reg_count)? ptimer: (ptimer - 17'h1)));
		p_start <=   ptimer[16]? 1'b0 : (rx_pause_sync? 1'b0 : 1'b1);
		p_reg_count <=   p_start? ((|p_reg_count)? (p_reg_count - 6'd1) : 6'd63) : 6'd63;
	end
end

reg [63:0] 	p_data;
reg	[2:0]	p_cnt;
reg			p_1;
reg			p_done;
reg			p_send;
reg			xdone;
reg			clk_pulse;	
reg [2:0]	p_qwcnt;

always @ (posedge clk)
begin
	if (!rst_)
	begin
		p_data <= 64'h0;
		p_cnt <= 3'd7;
		p_1 <= 1'b0;
		p_done <= 1'b0;
		p_send <= 1'b0;
		xdone  <= 1'h0; 
		clk_pulse <= 1'b0;
		p_qwcnt <= 3'h0;
	end
	
	else
	begin
		p_cnt <= st_p_pkt? (p_cnt - 3'd1) : 3'd7;
		p_1 <= st_p_req? 1'b1 : (clk_pulse? 1'b0 : p_1);
		p_done <= xdone;
		p_send <= (p_1 & clk_pulse)? 1'b1 : (p_done? 1'b0 : p_send);
		xdone  <= clk_pulse & (p_qwcnt == 8'h7);
		clk_pulse <= p_cnt == 3'h2;
		p_qwcnt <= clk_pulse? (p_qwcnt + 3'd1) : p_qwcnt;
		
		case (p_qwcnt)
		3'b000: p_data <= {psaddr[39:32], psaddr[47:40], 48'h0100_00c2_8001}; 
		3'b001: p_data <= {32'h0100_0888, psaddr[7:0], psaddr[15:8], psaddr[23:16], psaddr[31:24]};	
  		3'b010: p_data <= xon? {48'h0, mac_pause_value[23:16], mac_pause_value[31:24]}: 64'h0;
		default: p_data <= 64'h0;
		endcase
	end
end

always@(posedge clk)
begin
	if(!rst_)
	wdata <= 64'hd5555555555555FB;
	
	else begin	   
// data output
	wdata <= mode_1G? (p_send? p_data : (wsel? 64'hd5555555555555FB : txfifo_dout)) :
	         (p_send? p_data : (wsel? ((st_idle & pulse_0)? 64'hd5555555555555FB : wdata) : ((st_mac_dat & pulse_0)? txfifo_dout : wdata)));
	end
end

//state machine
always@(posedge clk)
if(!rst_)
begin
	state 	<=  IDLE;
	rbytes 	<=  16'h0;
	wsel   	<=  1'b1;
	rx_pack	<=  1'b0;
	tx_rdy 	<=  1'b0;
	tx_dvld <= 	1'b0;
	bytes_remain <=   16'h0;
	txfifo_rd_en <=   1'b0;
	count8 <= 4'd6;
	rts <= 1'b0;
	
	counter <= mode_1G? 8'd0 :		  //counter values for different speed modes.
	          (mode_100M? 8'd9 :
	          8'd99);
	
	pulse_0 <= 1'b0;
	pulse_1 <= 1'b0;
end
else
begin
	tx_rdy    <=   ptimer[16];
	rx_pack   <=   rx_pause_sync; 
	rts <= mode_1G? (st_readsize | st_p_req) :				//request to send data, indicating gmii that encap is ready to send data.
	       ((st_read1 & pulse_1)  | st_p_req);				// for 100M and 10M speed modes

	
	counter <= mode_1G? counter :
                   (mode_100M? ((|counter)? counter - 8'd1 : 8'd9) :		//100M speed
                   ((|counter)? counter - 8'd1 : 8'd99));					//10M speed
	           	   
    pulse_0 <= mode_1G? pulse_0 :
                     ((pulse_1)? 1'b1 : 1'b0);
    pulse_1 <= mode_1G? pulse_1 :
                     ((counter == 8'd2)? 1'b1 : 1'b0);

//state machine for output
	case(state)	
	IDLE:
	begin
		wsel  <= 1'b1;
		if (b2b_ok & cts & xreq)
		begin
			state <= P_REQ;
			txfifo_rd_en <= 1'b0;
		end
		
		else if (b2b_ok & !txfifo_empty & tx_rdy & !rx_pause_sync & cts)
		begin
			state <= READSIZE;	
			txfifo_rd_en <= mode_1G? 1'b1 : txfifo_rd_en; 				//enabling the read signal to read the data from the FIFo
		end
		
		else
		begin
			state <= IDLE;
			txfifo_rd_en <= 1'b0;
		end
	end
	
	READSIZE:
	begin
		wsel  <= 1'b1;
	    state <= mode_1G ? READ1 :
	             ((pulse_0)? READ1 : READSIZE);
	   //generate read signal to read data from the FIFO 
	    txfifo_rd_en <= mode_1G? 1'b0 :
	                   ((pulse_1)? 1'b1 : 1'b0);
	end
	
	READ1:
	begin
		txfifo_rd_en <=   1'b0;
		state <= mode_1G? WAIT :
		         ((pulse_0)? WAIT : READ1);
		// to get the byte count of data.		
		rbytes        <= mode_1G? txfifo_dout[15:0] :				//get the byte size of data
		                ((pulse_0)? txfifo_dout[15:0] : rbytes);
		bytes_remain  <= mode_1G? txfifo_dout[15:0]-16'h8 :			   //decrement the byte count by 8 after every transmission.
		                ((pulse_0)?  txfifo_dout[15:0]-16'h8 : bytes_remain);
        wsel <= 1'b1;
        count8 <= 4'd6; 
		tx_dvld       <= mode_1G? 1'b1 :							//shows valid data
		                 ((pulse_0)? 1'b1 : tx_dvld);         
	end
	
	WAIT:			//hold 64 bits data for 8 clock cycles.
	begin	
		state <= mode_1G? ((|count8)? WAIT : (tx_dvld)? MAC_DAT : IDLE) :
		         ((count8 == 1'd0 && pulse_0)? ((tx_dvld)? MAC_DAT : IDLE) : WAIT);
        count8 <= mode_1G? count8 - 4'd1 :
                  (pulse_0? count8 - 4'd1 : count8);
                  
        txfifo_rd_en <= mode_1G? ((count8 == 4'd1) & tx_dvld) :
                        ((count8 == 4'd0 & pulse_1 & tx_dvld));

        wsel <= mode_1G? ((|count8)? wsel : (tx_dvld)? 1'b0 : 1'b1) :
                ((count8 == 4'd0 & pulse_0)? ((tx_dvld)? 1'b0 : 1'b1) : wsel);
	end
	
	MAC_DAT:
	begin
		wsel <= 1'b0;
			 
        state <= mode_1G? WAIT :
                (pulse_0? WAIT : MAC_DAT);       
		
		bytes_remain <= mode_1G? bytes_remain - 16'h8 :
		               (pulse_0? bytes_remain - 16'h8 : bytes_remain);
		tx_dvld      <= mode_1G? ((bytes_remain[15] || bytes_remain == 0)? 1'b0: 1'b1) :						//indicates valid data
		                ((bytes_remain[15] || bytes_remain == 0)? ((pulse_0)? 1'b0: 1'b1) : tx_dvld);
		
		count8        <=   mode_1G? ((bytes_remain[15] || bytes_remain == 0)? 4'd12: 4'd6) :
		                   ((bytes_remain[15] || bytes_remain == 0)? ((pulse_0)? 4'd12 : count8) : ((pulse_0)? 4'd6 : count8));
		
		txfifo_rd_en <= 1'b0;		
	end
	
	P_REQ:
	begin
		state <= P_PREAM;			
	end
		
	P_PREAM:
	begin
		state <= P_PKT;
		rbytes <= 16'd60;
	end
		
	P_PKT:
	begin
		state <= p_done? IDLE : P_PKT;
	end	
	
	default:
	begin
		state <=   IDLE;
	end
	endcase

end


//synopsys translate_off
reg [(8*32)-1:0] ascii_state;

always@(state)
begin
	case(state)
	IDLE: 		ascii_state = "IDLE";
	READSIZE: 	ascii_state = "READSIZE";
	READ1: 		ascii_state = "READ1";
	WAIT: 		ascii_state = "WAIT";
	MAC_DAT: 	ascii_state = "MAC_DAT";
	P_REQ:	    ascii_state = "P_REQ";  
	P_PREAM:	ascii_state = "P_PREAM";
	P_PKT:	    ascii_state = "P_PKT";
	default: 	ascii_state = "unknown";
	endcase
	
end
//synopsys translate_on


endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/10ps
// synopsys translate_on

module gige_tx_gmii(
	clk250,			 // i-1
	clk125,   		// i-1
	rst_,  		   // i-1
	fmac_speed ,   //i-2
	
	rts,    	   // i-1
	rdata,  	   // i-64
	rbytes,		   // i-16
	cts,		   // o-1
	
	gmii_txd,		// o-8
	gmii_txc,		// o-1
	gmii_tx_en,		// o-1
	gmii_tx_vld,	// o-1
	linkup,			// i-1
	
	FMAC_TX_PKT_CNT,  		// o-32
	FMAC_TX_BYTE_CNT,		// o-32
	fmac_tx_byte_cnt_clr	// i-1	
	);

input clk250;		   
input clk125;
input rst_;
input [1:0] fmac_speed    ;	   //speed mode register. 

input   rts;				//request to send signal.
input   [63:0] rdata;
input   [15:0] rbytes;	   //Size of packet,
output	cts;			   // clear to send from gmii to encap.

output [7:0] gmii_txd;		   //0-8 1 byte output.
output 		 gmii_txc;		   // control output.
output 		 gmii_tx_en;	   
output 		 gmii_tx_vld;	   // To indicate valid data. 
input		 linkup;

output [31:0] FMAC_TX_PKT_CNT;		// counts the number of packet transmitted.
output [31:0] FMAC_TX_BYTE_CNT;		// total bytes transmitted.
input		  fmac_tx_byte_cnt_clr;
	
reg	   [63:0] pdin;			 // use this with gige_crc32x64 to support giving data that are not consec clk
reg    [63:0] bdata1;		 // buffer the incoming data
reg    [63:0] bdata2;		 //buffer twice the incoming data.
reg    [15:0] wcnt;			 //  write count.

wire	[15:0] nbytes;
reg  	[15:0] nbytes_reg;
reg 	[15:0] rbytes_reg;

reg    [63:0] txd;			  //data output of gmii. 
reg    [07:0] txc;			  //control output of gmii. 
reg    [07:0] txc_int;

reg    IDLE_sel;
reg    insert_crc;		   // Indication of inserting the crc frame. 

reg    crc_we_;
reg    crc_last_;		   
reg    crc_clr_;
reg    [15:0] crc_cnt;
wire   [31:0] crc32;	  // 32 bits crc. 

reg		sent;
reg		sent_dly;
reg		statistic_ok;
reg		[31:0]   pkt_transmitted;
reg		[31:0]   FMAC_TX_PKT_CNT;
reg 	[31:0]   accumulated_bcnt;
reg		[31:0]   FMAC_TX_BYTE_CNT;

wire    mode_1G   =   (fmac_speed == 2'b01) ;
wire    mode_100M =   (fmac_speed == 2'b10) ;
wire    mode_10M  =   (fmac_speed == 2'b11) ;

reg     [8:0] counter;
reg     pulse_0 ;
reg     pulse_1 ;

parameter[5:0] 
    IDLE		= 6'h01 ,
	GET_WAIT1   = 6'h02 ,
	GET_WAIT2   = 6'h04 ,
	TX_DAT		= 6'h08 ,
	TX_CRC		= 6'h10 ,
	WAIT_S		= 6'h20 ;
reg    [5:0] state;

wire st_IDLE;			assign	st_IDLE			=	state[0];
wire st_GET_WAIT1;  	assign	st_GET_WAIT1	=	state[1];
wire st_GET_WAIT2;  	assign	st_GET_WAIT2	=	state[2];
wire st_TX_DAT;     	assign	st_TX_DAT		=	state[3];
wire st_TX_CRC;        	assign	st_TX_CRC		=	state[4];
wire st_WAIT_S;			assign 	st_WAIT_S		=  	state[5];

wire st_DAT_0;
wire st_DAT_1;
wire st_DAT_4;
wire st_DAT_5; 
wire st_DAT_6;
wire st_DAT_7; 
reg  last_dat;

reg	[15:0] 	bcnt;
assign nbytes = {(rbytes[15:3] + |rbytes[2:0]),3'b000};

always@(posedge clk125)
begin
	bdata1 <=   (!rst_)? 64'hD5555555555555FB :
				mode_1G? rdata :
	            (pulse_0? rdata : bdata1);
	pdin  <= (!rst_)? 64'h0 :  
	       (crc_we_? pdin : rdata);     
	        
	bdata2 <=   (!rst_)? 64'hD5555555555555FB :
				mode_1G? bdata1 :
	            (pulse_0? bdata1 : bdata2);
	nbytes_reg <= (!rst_)? 16'b0 : 
				  mode_1G? nbytes :
	              (pulse_0? nbytes : nbytes_reg);
	rbytes_reg <= (!rst_)? 16'b0 :
				  mode_1G? rbytes :
	              (pulse_0? rbytes : rbytes_reg);
	
end

 //   FMAC_TX_PKT_CNT REGISTER
always@ (posedge clk125)
begin
	if (!rst_)
	begin
		sent	<=	1'b0;
		sent_dly <= 1'b0;
	end
	
	else
	begin
		sent	<=	mode_1G? (st_TX_CRC & st_DAT_4) :
		            (st_IDLE & st_DAT_5 & pulse_1);
		sent_dly <= mode_1G? sent :
		            (st_IDLE & st_DAT_6 & pulse_1);
	end
end

always@ (posedge clk125)
begin
	if (!rst_)
		pkt_transmitted	<=	32'h0;
	else
		pkt_transmitted	<=	(sent)? (pkt_transmitted + 32'h1) : pkt_transmitted ;
end

always @ (posedge clk250)
begin
	if (!rst_)
		statistic_ok <= 1'b0;
	else
		statistic_ok <= mode_1G? sent_dly :
		                (st_IDLE & st_DAT_7 & pulse_1);
		
end

always @ (posedge clk250)
begin
	if (!rst_)
		FMAC_TX_PKT_CNT <= 32'h0;
		
	else
		FMAC_TX_PKT_CNT <= statistic_ok? pkt_transmitted : FMAC_TX_PKT_CNT ;
end
// to store the accumulated total byte count of all the packets
always@ (posedge clk125)
begin
	if (!rst_ | fmac_tx_byte_cnt_clr)
		accumulated_bcnt	<=	32'h0;
	else
		accumulated_bcnt	<=	(sent)? (accumulated_bcnt + rbytes_reg) : accumulated_bcnt ;
end

always @ (posedge clk250)
begin
	if (!rst_ | fmac_tx_byte_cnt_clr)
		FMAC_TX_BYTE_CNT <= 32'h0;
		
	else
		FMAC_TX_BYTE_CNT <= statistic_ok? accumulated_bcnt : FMAC_TX_BYTE_CNT ;
end

always@(posedge clk125)
if(!rst_)
begin
	state <=   IDLE;
	txd   <=   64'hf7f7f7f7f7f7f7f7;   // IDLE for gmii interface (normal inter-frame)
	txc   <=   8'hff; 

	txc_int <=   8'hff;
	IDLE_sel  <=   1;
	insert_crc<=   0;

	wcnt <=   0;
	
	crc_we_ <=   1;
	crc_last_<=   1;
	crc_cnt  <=   0;
	crc_clr_ <=   1;
	
	last_dat <= 1'b0;	
end
else
begin		
	if (insert_crc)					 // insert the crc frame depending upon the valid data.
			begin 					//lower 3 bits of rbytes register stores the number of valid bytes in last qwd
			case (rbytes_reg[2:0])
			3'd0: txd <=   {32'hf7f7f7FD, crc32 };
			3'd1: txd <=   {64'hf7f7f7f7f7f7f7f7};
			3'd2: txd <=   {64'hf7f7f7f7f7f7f7f7};
			3'd3: txd <=   {64'hf7f7f7f7f7f7f7f7};
			3'd4: txd <=   {64'hf7f7f7f7f7f7f7FD};
			3'd5: txd <=   {32'hf7f7f7f7, 24'hf7f7FD, crc32[31:24] };
			3'd6: txd <=   {32'hf7f7f7f7, 16'hf7FD, crc32[31:16] };
			3'd7: txd <=   {32'hf7f7f7f7, 8'hFD, crc32[31:8] };
			endcase	
			end
		
	else
		begin					// before the crc frame, second last data frame according to the number of bytes valid.
		if((mode_1G & wcnt[15]& st_TX_DAT) | ((mode_100M | mode_10M) & wcnt[15] & st_TX_DAT & pulse_0) )
			begin
			case (rbytes_reg[2:0])
			3'd0: txd <=   {bdata2[63:32], bdata2[31:0] };
			3'd1: txd <=   {24'hf7f7FD, crc32[31:0], bdata2[7:0] };
			3'd2: txd <=   {16'hf7FD, crc32[31:0], bdata2[15:0] };
			3'd3: txd <=   {8'hFD, crc32[31:0], bdata2[23:0] };
			3'd4: txd <=   {crc32, bdata2[31:0]};
			3'd5: txd <=   {crc32[23:0], bdata2[39:0] };
			3'd6: txd <=   {crc32[15:0], bdata2[47:0] };
			3'd7: txd <=   {crc32[7:0], bdata2[55:0] };
			endcase
				
			end
		// if not last qwd
		else txd <= mode_1G? (st_TX_DAT? {bdata2[63:0]}: txd) :     
		            (st_TX_DAT? (pulse_0? {bdata2[63:0]}: txd) : txd);		     
		end
	
	txc <= mode_1G? txc_int :
	       (( (st_TX_DAT & pulse_0) || (st_TX_CRC & pulse_0) )?  txc_int : txc);
	
    insert_crc <= mode_1G? ((st_DAT_6 && last_dat)) :			//pulse indicating when to insert the crc frame
                  ((st_DAT_7 && pulse_1 && last_dat));
	
	crc_we_ <= mode_1G? (!(st_DAT_4 && !crc_cnt[15])) :
	           (!(st_DAT_5 && pulse_1 && !crc_cnt[15]));
	
	crc_last_ <= mode_1G? (!(st_DAT_4 && !crc_cnt[15] && wcnt[15])) :
	             (!(st_DAT_5 && pulse_1 && !crc_cnt[15] && wcnt[15]));
		
	crc_cnt <= mode_1G? (st_GET_WAIT1 ? (rbytes + 16'd7) : (st_TX_DAT? (crc_cnt - 16'd8) : crc_cnt)) :
	           ((st_GET_WAIT1 && pulse_0) ? (rbytes + 16'd7) : (st_TX_DAT? (pulse_0? (crc_cnt - 16'd8) : crc_cnt) : crc_cnt));
	
	crc_clr_   <=  mode_1G? (!(st_IDLE || st_TX_CRC)) :
	              ( (st_GET_WAIT1 & pulse_0)? 1'b1 :
	              (st_TX_CRC & st_DAT_7 & pulse_0)? 1'b0 :
	              crc_clr_);
    
	//state machine
	case(state)
	IDLE:
	begin
		state <= rts? GET_WAIT1: IDLE;
	end

	GET_WAIT1:
	begin
        state <= mode_1G? GET_WAIT2 :
                 ((pulse_0)? GET_WAIT2 : GET_WAIT1);
	end

	GET_WAIT2:
	begin
		state <= mode_1G? TX_DAT :
		         ((pulse_0)? TX_DAT : GET_WAIT2);
		
        wcnt     <= mode_1G? nbytes_reg - 16'd1 :
                    ((pulse_0)?  nbytes_reg - 16'd1 : wcnt);
        txc_int  <= mode_1G? 8'h01 :
                    ((pulse_0)? 8'h01 : txc_int);
        IDLE_sel <= mode_1G? 0 :
                    ((pulse_0)? 0 : IDLE_sel);
	end
	
	TX_DAT:
	begin
		state <= mode_1G? WAIT_S :
		         (pulse_0? WAIT_S : TX_DAT);
		
		wcnt <= mode_1G? wcnt - 16'd8 :
		        (pulse_0? wcnt - 16'd8 : wcnt);
		        
		last_dat <= mode_1G? wcnt[15] :
		            (pulse_0? wcnt[15] : last_dat);		
	end
	
	WAIT_S:
	begin
		state <= mode_1G? (st_DAT_6? (last_dat? TX_CRC : TX_DAT) : WAIT_S) :
		         (st_DAT_6? 
                         (|counter)? WAIT_S :
                         (last_dat? TX_CRC : TX_DAT) : 
                         WAIT_S);
		
		if ( (mode_1G & st_DAT_6) | ((mode_100M | mode_10M) & st_DAT_6 & pulse_0) )
		begin					//controls for the last qwd data
			if (wcnt[15]& last_dat)
				begin
				case (rbytes_reg[2:0])
				3'd0: txc_int <=   8'hF0;
				3'd1: txc_int <=   8'hFF;
				3'd2: txc_int <=   8'hFF;
				3'd3: txc_int <=   8'hFF;
				3'd4: txc_int <=   8'hFF;
				3'd5: txc_int <=   8'hFE;
				3'd6: txc_int <=   8'hFC;
				3'd7: txc_int <=   8'hF8;
				endcase
				end
			else
			begin		// control for the qwd if not last
			if (wcnt[15] & !last_dat)
				begin
				case (rbytes_reg[2:0])
				3'd0: txc_int <=   8'h00;
				3'd1: txc_int <=   8'hE0;
				3'd2: txc_int <=   8'hC0;
				3'd3: txc_int <=   8'h80;
				3'd4: txc_int <=   8'h00;
				3'd5: txc_int <=   8'h00;
				3'd6: txc_int <=   8'h00;
				3'd7: txc_int <=   8'h00;
				endcase
				end
			else txc_int <= 8'h00;
			end
		end
		
		else
			txc_int <=   txc_int; 
	end
	
	TX_CRC:		//after inserting CRC frame, wait if there is more data or else go to idle state.
	begin
		state <= mode_1G? (st_DAT_4? (rts? GET_WAIT1: IDLE) : TX_CRC) :
		         ((st_DAT_4 && pulse_0)? (rts? GET_WAIT1: IDLE) : TX_CRC);
		
		last_dat <= mode_1G? 1'b0 :
		            ((pulse_0)? 1'b0 : last_dat);
	end
		
	default:
	begin
		state <=   IDLE;
	end
	endcase
end

 // State machine that takes 64 bits data and output 8 bits at a time for gmii interface

parameter[8:0] 
	DAT_I  	= 9'h001 ,
	DAT_0	= 9'h002 ,
	DAT_1	= 9'h004 ,
	DAT_2	= 9'h008 ,
	DAT_3	= 9'h010 ,
	DAT_4	= 9'h020 ,
	DAT_5   = 9'h040 ,
	DAT_6   = 9'h080 ,
	DAT_7	= 9'h100 ;             
reg [8:0] gstate ;	// gmii state

wire 	st_DAT_I	= gstate[0];
assign 	st_DAT_0 	= gstate[1];
assign 	st_DAT_1 	= gstate[2];
assign 	st_DAT_4 	= gstate[5];
assign 	st_DAT_5 	= gstate[6];
assign 	st_DAT_6 	= gstate[7];
assign 	st_DAT_7 	= gstate[8];

reg [7:0] gmii_txd;						//output 8bit data 
reg 	  gmii_txc;						//output 1 bit control
reg		  gmii_tx_en;				
reg		  gmii_tx_vld;					//indicates valid data

reg		  cts;
reg		  gmii_start;					//pulse to start transmitting data
reg [7:0] idle1, idle2, idle3, idle4;

always @ (posedge clk125)
begin
	if (!rst_)
	begin
		cts <= 1'b0;
		gmii_start <= 1'b0;
		
		idle1 <= 8'hBC; 
		idle2 <= 8'hC5; 
		idle3 <= 8'hBC; 
		idle4 <= 8'h50;		
	end
	
	else
	begin
		cts <= mode_1G? (st_DAT_I & (idle3 == 8'h50)) :				//clear to send signal, for gige_encap showing gmii is ready to get data.
		       (st_DAT_I & (idle2 == 8'h50) & pulse_1);
		
		gmii_start <= mode_1G? (st_GET_WAIT2 | (st_DAT_6 & st_WAIT_S)) :
		              ((st_TX_DAT & pulse_1) | (st_DAT_7 & st_TX_CRC & pulse_1));
		
        idle1 <= mode_1G? (st_DAT_I? idle2 : 8'hBC) :
                (st_DAT_I? ((pulse_0)? idle2 : idle1) : 8'hBC);
		idle2 <= mode_1G? (st_DAT_I? idle3 : 8'hC5) :
		        (st_DAT_I? ((pulse_0)? idle3 : idle2) : 8'hC5);
		idle3 <= mode_1G? (st_DAT_I? idle4 : 8'hBC) :
		        (st_DAT_I? ((pulse_0)? idle4 : idle3) : 8'hBC);
		idle4 <= mode_1G? (st_DAT_I? idle1 : 8'h50) :
		        (st_DAT_I? ((pulse_0)? idle1 : idle4) : 8'h50);
	end
end

always@(posedge clk125)
if(!rst_)
begin
	gstate <= DAT_I;
	gmii_txd <= 8'hbc;
	gmii_txc <= 1'b1;
	gmii_tx_en	<=	1'b0;
	gmii_tx_vld	<=	1'b1;
   
	bcnt		<=	16'd0;
	
	pulse_0   <= 1'b0;
	pulse_1   <= 1'b0;
	
	//counter initilization 
	//for 100M count 10 clock cycle
	//for 10M count 100 clock cycle
	counter <= mode_1G? 8'd0 :
              (mode_100M? 8'd9 :
              8'd99);
end

else
begin                        
    gmii_tx_en	<=  mode_1G? ((gstate == DAT_I)? 1'b0 : (bcnt    ==    16'd0)?    1'b0    :    1'b1) :
                    ((bcnt != 16'd0 && st_DAT_0  && pulse_0)?  1'b1 : 
                       ((bcnt == 16'd0 & pulse_0 & (st_WAIT_S | st_TX_CRC | st_IDLE)))?  1'b0 : 
                       gmii_tx_en);
    
    gmii_tx_vld <=  mode_1G? (((bcnt	==	16'd1)|(bcnt	==	16'd0))?	1'b1	:	(!gmii_tx_en)) :
                    ((bcnt == 16'd1 && pulse_0)? 1'b1 :
                       (bcnt != 16'd0 && st_DAT_1  && pulse_0)?  (!gmii_tx_en) : 
                       gmii_tx_vld);
    
	counter <= mode_1G? counter :										//counter for different speed modes.
              (mode_100M? ((|counter)? counter - 8'd1 : 8'd9) :
              ((|counter)? counter - 8'd1 : 8'd99));
       
    pulse_0 <= mode_1G? pulse_0 : pulse_1; 
    pulse_1 <= mode_1G? pulse_1 : (counter == 8'd2);
    //state machine to output 8bits data.
	case(gstate)
	DAT_I:
	begin
		gstate <= gmii_start? DAT_0 : DAT_I;
        
        gmii_txd <= mode_1G? idle1 :
                    ((pulse_0)? idle1 : gmii_txd);
        gmii_txc <= mode_1G? (idle1 == 8'hbc) :
                    ((pulse_0)? (idle1 == 8'hbc) :gmii_txc);
        
		gmii_tx_en	<=	1'b0; 
		gmii_tx_vld	<=	1'b1; 
	
		//bcnt = 8 bytes (from start frame D555...55FB) + rbytes + 4 bytes CRC Data + 1 Byte for end frame (8'hFD)
		bcnt		<=	mode_1G? rbytes + 16'd13 :
		                ((pulse_0)? rbytes + 16'd13 : bcnt);

	end
	
	DAT_0:		 // Transmit Byte 0
	begin
		gstate <= mode_1G? DAT_1 :
		          (pulse_0? DAT_1 : DAT_0);
        
		gmii_txd <= mode_1G? txd[7:0] :
                    (pulse_0? txd[7:0] : gmii_txd);
        gmii_txc <= mode_1G? txc[0] :
                    (pulse_0? txc[0] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	DAT_1:	   // Transmit Byte 1
	begin
        gstate <= mode_1G? DAT_2 :
                  (pulse_0? DAT_2 : DAT_1);

		gmii_txd <= mode_1G? txd[15:8] :
		            (pulse_0? txd[15:8] : gmii_txd);
		gmii_txc <= mode_1G? txc[1] :
		            (pulse_0? txc[1] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	DAT_2:			// Transmit Byte 2
	begin
		gstate <= mode_1G? DAT_3 :
		          ((|counter)? DAT_2 : DAT_3);
        
        gmii_txd <= mode_1G? txd[23:16] :
                   (pulse_0? txd[23:16] : gmii_txd);
        gmii_txc <= mode_1G? txc[2] :
                    (pulse_0? txc[2] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	DAT_3:		   // Transmit Byte 3
	begin
		gstate <= mode_1G? DAT_4:
		          (pulse_0? DAT_4 : DAT_3);
		
		gmii_txd <= mode_1G? txd[31:24] :
		            (pulse_0? txd[31:24] : gmii_txd);
		gmii_txc <= mode_1G? txc[3] :
		            (pulse_0? txc[3] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));

	end
	
	DAT_4:			 // Transmit Byte 4
	begin
		gstate <= mode_1G? DAT_5 :
		          (pulse_0? DAT_5 : DAT_4);
        
		gmii_txd <= mode_1G? txd[39:32] :
		            (pulse_0? txd[39:32] : gmii_txd);
		gmii_txc <= mode_1G? txc[4] :
		            (pulse_0? txc[4] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));

	end
	
	DAT_5:			// Transmit Byte 5
	begin
		gstate <= mode_1G? DAT_6 :
		          (pulse_0? DAT_6 : DAT_5);
        
        gmii_txd <= mode_1G? txd[47:40] :
                    (pulse_0? txd[47:40] : gmii_txd);
        gmii_txc <= mode_1G? txc[5] :
                    (pulse_0? txc[5] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));

	end
	
	DAT_6:			 // Transmit Byte 6
	begin
		gstate <= mode_1G? DAT_7 :
		          (pulse_0? DAT_7 : DAT_6);
        	
        gmii_txd <= mode_1G? txd[55:48] :
                    (pulse_0? txd[55:48] : gmii_txd);
        gmii_txc <= mode_1G? txc[6] :
                    (pulse_0? txc[6] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	DAT_7:			// Transmit Byte 7
	begin
        gstate <= mode_1G? ((gmii_start)? DAT_0 : DAT_I) :
                  (pulse_0? ((gmii_start)? DAT_0 : DAT_I) :
                  DAT_7);
		
		gmii_txd <= mode_1G? txd[63:56] :
		            (pulse_0? txd[63:56] : gmii_txd);
		gmii_txc <= mode_1G? txc[7] :
		            (pulse_0? txc[7] : gmii_txc);
		
        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                               ((bcnt == 16'd0)? 16'd0 : 
                               (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	default:
	begin
		gstate <=  DAT_I;
	end
	endcase
end

gige_crc32x64 gige_crc32x64(
   	.clk(clk125),				//i, clock
   	.rst_(rst_),				//i, reset
	
   	.pulse_0(pulse_0),			//i, for slower speed modes
   	.pulse_1(pulse_1),			//i, for slower speed modes.
   	.mode_1G(mode_1G), 		
   	.mode_100M(mode_100M), 
   	.mode_10M(mode_10M),
   	.st_DAT_6(st_DAT_6),
   	.wcnt(wcnt),			
   	.crc_cnt(crc_cnt),
   	
   	.bytes  (rbytes_reg[2:0]),		//number of bytes valid in last qwd 	
   	.clr_  (crc_clr_),
   	.we_   (crc_we_),
   	.last_ (crc_last_),
   	.cdin  (rdata),
   	.pdin  (pdin),	
   	
   	.crc32({crc32[7:0],crc32[15:8],crc32[23:16],crc32[31:24]}),
   	.crc32_vld_()
    );
   
//synopsys translate_off
reg [(16 *8)-1:0] ascii_state, ascii_gstate;
always@(state)
begin
	case(state)
	IDLE: ascii_state = "IDLE";
	GET_WAIT1: ascii_state = "GET_WAIT1";
	GET_WAIT2: ascii_state = "GET_WAIT2";
	TX_DAT: ascii_state = "TX_DAT";
	TX_CRC: ascii_state = "TX_CRC";
	WAIT_S: ascii_state = "WAIT_S";
	default: ascii_state = "unknown";
	endcase
end

always@(gstate)
begin
	case(gstate)
	DAT_I: ascii_gstate = "DAT_I";
	DAT_0: ascii_gstate = "DAT_0";
	DAT_1: ascii_gstate = "DAT_1";
	DAT_2: ascii_gstate = "DAT_2";
	DAT_3: ascii_gstate = "DAT_3";
	DAT_4: ascii_gstate = "DAT_4";
	DAT_5: ascii_gstate = "DAT_5";
	DAT_6: ascii_gstate = "DAT_6";
	DAT_7: ascii_gstate = "DAT_7";
	default: ascii_state = "unknown";
	endcase
end
//synopsys translate_on
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


`timescale 1ns / 1ns                                                                                                                                               


module gigerx_bcnt_fifo256x16

(
		aclr,
				
		wrclk,  		// Clk for writing data 
		wrreq,  		// request to write
		data,   	   // Data coming in
		full,   	   // indicates fifo is full or not (To avoid overiding)
		        
		rdclk,		   //rd clock
		rdreq,  	   // Request to read from FIFO 
		q, 	    	   // Data coming out 
		empty,  	   // indicates fifo is empty or not (to avoid underflow) 
		usedw   	   // number of slots currently in use for reading
);

	parameter WIDTH = 16,
			  DEPTH = 256,
			  PTR	= 8;
			  
			  
			input  wire 				aclr;
			
			input  wire 				wrclk;		// Clk for writing data   
			input  wire 				wrreq;		// request to write
			input  wire [WIDTH-1 : 0]	data;       // Data coming in            
			output wire					full; 		// indicates fifo is full or not (To avoid overiding)

			input  wire 				rdclk;		 // Clk for read data 
			input  wire 				rdreq;		 // Request to read from FIFO
			output wire [WIDTH-1 : 0]	q; 	  		  // Data coming out 
			output wire 				empty;		// indicates fifo is empty or not (to avoid underflow)
			output wire [PTR  : 0] 		usedw;		// number of slots currently in use for reading



asynch_fifo	#(.WIDTH (WIDTH),
					  	  .DEPTH (DEPTH),
					 	  .PTR	 (PTR) )
 											
	asynch_256x64		  (
			.reset_	(aclr),
			
			.wrclk	(wrclk),		// Clk to write data
			.wren	(wrreq),	   	// write enable
			.datain	(data),			// write data
			.wrfull	(full),			// indicates fifo is full or not (To avoid overiding)
			.wrempty(),				// indicates fifo is empty or not (to avoid underflow)
			.wrusedw(),				// wrusedw -number of locations filled in fifo

			.rdclk	(rdclk),		// i-1, Clk to read data
			.rden	(rdreq),		// i-1, read enable of data FIFO
			.dataout(q),			// Dataout of data FIFO
			.rdfull	(),				// indicates fifo is full or not (To avoid overiding) (Not used)
			.rdempty(empty),		// indicates fifo is empty or not (to avoid underflow)
			.rdusedw(usedw),		// rdusedw -number of locations filled in fifo.

			.dbg()

		 );
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


`timescale 1ns / 1ns                                                                                                                                               


module gigerx_fifo256x64_2clk

(
			aclr,
			
			wrclk, 				 // Clk for writing data 
			wrreq, 				 // request to write 
			data,            	 // Data coming in
			full,  				 // indicates fifo is full or not (To avoid overiding)
		                        
			rdclk,				 //rd clock
			rdreq, 				 // Request to read from FIFO 
			q, 	   				 // Data coming out
			empty, 				 // indicates fifo is empty or not (to avoid underflow)
			usedw  				 // number of slots currently in use for reading

);
	parameter WIDTH = 64,
			  DEPTH = 256,
			  PTR	= 8;
			  
			  
			input  wire 				aclr;

			input  wire 				wrclk; 		   // Clk for writing data  
			input  wire 				wrreq; 		   // request to write
			input  wire [WIDTH-1 : 0]	data;      	   // Data coming in
			output wire					full;  		   // indicates fifo is full or not (To avoid overiding)
		                                       
			input  wire 				rdclk; 		   // Clk for read data 
			input  wire 				rdreq; 		   // Request to read from FIFO
			output wire [WIDTH-1 : 0]	q; 	   		  // Data coming out
			output wire 				empty; 		   // indicates fifo is empty or not (to avoid underflow)
			output wire [PTR  : 0] 		usedw; 		   // number of slots currently in use for reading




asynch_fifo	#(.WIDTH (WIDTH),
					  	  .DEPTH (DEPTH),
					 	  .PTR	 (PTR) )
 											
	asynch_256x64		  (
			.reset_	(aclr),
			
			.wrclk		(wrclk),		   // Clk to write data
			.wren		(wrreq),		   // write enable
			.datain		(data),			   // write data
			.wrfull		(full),			   // indicates fifo is full or not (To avoid overiding)
			.wrempty	(),				   // indicates fifo is empty or not (to avoid underflow)
			.wrusedw	(),				   // wrusedw -number of locations filled in fifo
                    	
			.rdclk		(rdclk),		   // i-1, Clk to read data
			.rden		(rdreq),		   // i-1, read enable of data FIFO
			.dataout	(q),			   // Dataout of data FIFO
			.rdfull		(),				   // indicates fifo is full or not (To avoid overiding) (Not used)
			.rdempty	(empty),		   // indicates fifo is empty or not (to avoid underflow)
			.rdusedw	(usedw),		   // rdusedw -number of locations filled in fifo (not used )

			.dbg		()

		 );
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


`timescale 1ns / 1ns


module gigerx_fifo256x8

(
			aclr,
			wrclk,  		 // Clk for writing data 
			wrreq,  		// request to write 
			data,           // Data coming in             
			full,   		// indicates fifo is full or not (To avoid overiding)
		                                   
			rdclk,			//rd clock
			rdreq,  		// Request to read from FIFO
			q, 	    		// Data coming out 
			empty,  		// indicates fifo is empty or not (to avoid underflow)  
			usedw   		// number of slots currently in use for reading

);
	parameter WIDTH = 8,
			  DEPTH = 256,
			  PTR	= 8;
			  
			  
			input  wire 				aclr;

			input  wire 				wrclk; 		 // Clk for writing data   
			input  wire 				wrreq; 		 // request to write 
			input  wire [WIDTH-1 : 0]	data;  		// Data coming in 
			output wire					full;  		// indicates fifo is full or not (To avoid overiding)
		                                       
			input  wire 				rdclk; 		  // Clk for read data 
			input  wire 				rdreq; 		  // Request to read from FIFO  
			output wire [WIDTH-1 : 0]	q; 	   		  // Data coming out 
			output wire 				empty; 		  // indicates fifo is empty or not (to avoid underflow)
			output wire [PTR  : 0] 		usedw; 		  // number of slots currently in use for reading


			
asynch_fifo	#(.WIDTH (WIDTH),
					  	  .DEPTH (DEPTH),
					 	  .PTR	 (PTR) )	
 											
	asynch_256x8		  (
			.reset_	(aclr),
			
			.wrclk	(wrclk),			 // Clk to write data
			.wren	(wrreq),	   		 // write enable
			.datain	(data),				 // write data
			.wrfull	(full),				 // indicates fifo is full or not (To avoid overiding)
			.wrempty(),					 // indicates fifo is empty or not (to avoid underflow)
			.wrusedw(),					 // wrusedw -number of locations filled in fifo

			.rdclk	(rdclk),			 // i-1, Clk to read data
			.rden	(rdreq),			 // i-1, read enable of data FIFO
			.dataout(q),				// Dataout of data FIFO
			.rdfull	(),					 // indicates fifo is full or not (To avoid overiding) (Not used)
			.rdempty(empty),			 // indicates fifo is empty or not (to avoid underflow)
			.rdusedw(usedw),			 // rdusedw -number of locations filled in fifo (not used )

			.dbg()

		 );
endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns / 1ns                                                                                                                                               
// synopsys translate_on

module tcore_rx_xgmii(
	clk156,						// i-1
	clk250,						// i-1
	rst_,						// i-1
                        		
	TCORE_MODE	,				//i-1
                    
	pkt_data	,		 		//o-64	Data output from xgmii
	pkt_start	,		 		//o-1   Indicates when the packet starts with valid data
	pkt_end		,		 		//o-1   Indicates when the packet ends. Ignores the end of packet pattern and CRC
	pkt_we		,		 		//o-1   Write enable signal for RX FIFO
	
	drx_pkt_data		,     	//o-64	Same as pkt_data
	drx_pkt_start 		,     	//o-1   Same as pkt_start
	drx_pkt_end 		,     	//o-1   Same as pkt_end
	drx_pkt_we 			,     	//o-1   Same as pkt_we
	drx_pkt_beat_bcnt	,  	  	//o-3   
	drx_pkt_be			,     	//o-8
	drx_crc32 			,     	//o-32
	drx_crc_vld 		,     	//o-1
	drx_crc_err 		,     	//o-1
	drx_crc_err_dly1 	,     	//o-1
	
	wen,						// o-1
	waddr,						// o-param
	wptr,						// o-param
	raddr_marker,				// i-param
	wdata,						// o-64
	                			
	rx_pause,					// o-1
	rx_pvalue,					// o-16
	rx_pack,					// i-1
	                			
	pause_en,					// i-1
	bcast_en,					// i-1
	pmode,						// i-1, promiscuous mode enable bit
	daddr0,						// i-48
	mcast_en,					// i-1
	mcast_saddr,				// i-48
             	
	rsize,						// i-12
	rxd,						// i-64 Input data from byte reordering module
	rxc,						// i-8  Input control corresponding to the data from byte reordering module
	br_sof4,					// i-1, byte_reordering's sof4_out
	rxp,						// i-8

	fmac_ctrl1_dly	,			//i-32, contains the max_pkt_size and enable
	fmac_rxd_en	,				//i-1, from TSPE_CTRL1  reg	                    		
	                    		
	FMAC_DCNT_OVERRUN,			// o-32  Indicates when the FIFO overrun
	FMAC_DCNT_LINK_ERR,			// o-32  Indicates when there is any link error
	FMAC_PKT_CNT_OVERSIZE, 		// o-32  Indicates when the incoming packet is more than 1518 bytes
	FIFO_OV_IPEND,				// o-1
	
	clr_pkt_cnt_oversize	,	//o-1
	
	add_lo_bcast	,		 	// o-1	for broadcast packet
	add_lo_mcast	,		 	// o-1  for multicast packet
	clr_carry_cast	,		 	// o-1
	add_hi_cast		,		 	// o-1
              	      
    vlan_ip,					//o-1   VLAN IP type packet
    normal_ip,					//o-1   Normal IP type packet
    non_ip,						//o-1   Neither VLAN nor Normal IP packet
    pkt_reject,					//o-1, EXTR use to drop the pkt at end
    pkt_jumbo_flag,				//o-1    (not used)
    pkt_ipver,					//o-4    (not used)
        
    wr_nbyte	,				//o-1   Indicates when nybytes should be written to the FIFO
    nbytes_out		,			//o-16, pkt byte cnt
    rxfifo_full					//i-1   Indicates that the rx fifo is full
	
	);

//These are parameters indiccated at instantiation
parameter	RX_DRAM_DEPTH = 3072;
parameter	RX_DRAM_ADDR_WIDTH = 12;

input 			clk156;				// i-1
input 			clk250;             // i-1
input 			rst_;               // i-1
      			                      
input 			TCORE_MODE	;       //i-1
      			                      
input 			pause_en;           // i-1
input 			bcast_en;           // i-1
input 			pmode;              // i-1
                                	
input	[47:0]	daddr0;            	// i-48

input       	mcast_en;			// i-1
input	[47:0]	mcast_saddr;		// i-48

input 			rx_pack;            // i-1
output 			rx_pause;           // o-1
output 	[15:0] 	rx_pvalue;          // o-16

output	[63:0]	pkt_data	;		//o-64
output			pkt_start	;		//o-1
output			pkt_end		;		//o-1
output			pkt_we		;

output	[63:0]	drx_pkt_data	;   //o-64          
output			drx_pkt_start ;     //o-1
output			drx_pkt_end ;       //o-1
output			drx_pkt_we ;        //o-1
output	[2:0]	drx_pkt_beat_bcnt;	//o-3
output	[7:0]	drx_pkt_be	;       //o-8
output	[31:0]	drx_crc32 ;         //o-32
output			drx_crc_vld ;       //o-1
output			drx_crc_err ;       //o-1
output			drx_crc_err_dly1 ;  //o-1

//output to the DRAM buffer where the pkt from the Ethernet port is 1st stored
output 								wen;                    	//o-1
output 	[RX_DRAM_ADDR_WIDTH-1:0] 	waddr;         				//o-param current DRAM buffer Write Addr
input  	[RX_DRAM_ADDR_WIDTH-1:0] 	raddr_marker;           	//i-param
output 	[RX_DRAM_ADDR_WIDTH:0] 		wptr; 						//o-param pointer of the start of the last pkt
output 	[63:0] 						wdata;                  	// o-64
                                                            	
input  	[63:0] 						rxd;                    	// i-64
input  	[07:0] 						rxc;                    	// i-8
input  	[07:0] 						rxp;                    	// i-8
input  	[11:0] 						rsize;                  	// i-12
input								br_sof4 ;               	// i-1
                                                            	
input 	[31:0]						fmac_ctrl1_dly;         	//i-32
                					                        	
input								fmac_rxd_en	;           	//i-1
                					                        	
output 	[31:0]						FMAC_DCNT_OVERRUN;      	// o-32
output 	[31:0]						FMAC_DCNT_LINK_ERR;     	// o-32
output 	[31:0]						FMAC_PKT_CNT_OVERSIZE;  	// o-32
output								FIFO_OV_IPEND;          	// o-1

input								clr_pkt_cnt_oversize	;	//o-1 control signal to clear the PKT_CNT_OVERSIZE reg

output								add_lo_bcast	;			// o-1, these signals are 250Mhz pre-synced
output								add_lo_mcast	;			// o-1                                     	
output								clr_carry_cast	;			// o-1 clr the carry of the B/Mcast group	
output								add_hi_cast		;			// o-1 add the HI reg of the B/Mcast group  	

output								vlan_ip ;                   //o-1
output								normal_ip ;                 //o-1
output								non_ip ;                    //o-1
output		    					pkt_reject;                 //o-1
output		    					pkt_jumbo_flag;				//o-1
output	[3:0]						pkt_ipver ;                 //o-4
      	
output								wr_nbyte	;               //o-1
output	[15:0]						nbytes_out		;           //o-16
input								rxfifo_full	;               //i-1

reg									wr_nbyte ;		   			//pulse if writing the NBYTE qwd
        							
wire								sof_n_eof ;
reg									sof_n_eof_dly1, sof_n_eof_dly2 ;

reg									pre_eof	;

reg		[13:0]						MAX_PKT_SIZE	;			//this is a dynamic parameter vary from system to system
reg									pkt_slice_en	;

parameter	[15:0]					MAX_RSVD_SIZE = (16'd1138 + 8'd16);			//MAX reserved size (=> jumbo pkt size) (regardless of the dynamic MAX_PKT_SIZE)
parameter	[15:0]					MAX_ALLOW		= (RX_DRAM_DEPTH - 8'd16)	;

reg		[RX_DRAM_ADDR_WIDTH-1:0] 	raddr_chk;  				// buffer the raddr_marker from rx_decap
   		
reg		[RX_DRAM_ADDR_WIDTH:0] 		wptr;
reg		[RX_DRAM_ADDR_WIDTH-1:0] 	wrusedw;					//current used qwd in the DRAM buffer

reg									wrfull	;					//if full do not write in any more new pkt until the old one had read out
reg									space_ok;

reg									has_pre_sof ;
reg		   							has_sof;					// use to detect a frame that has EOF but no SOF
reg		   							has_sof_dly1;

reg		   							valid_frame; 				// when see EOF, if does see that it has SOF, it is not valid

reg 	[03:0] 						bcnt;
reg									pre_sof;
reg 								sof;

reg 								sof_dly;
reg 								post_sof_dly;					//a 1 clk delay of SOF_DLY

reg									sof_pending ;					//must be quick enough to avoid racing conditions


reg 								rx_err0;
reg 								rx_err1;
reg 								err;
    								
reg 								eof0;
reg 								eof1;
wire 								eof;
wire								eof_qwd ;						//current incoming control qwd contains EOF (direct detect to be on time)
wire								eof_dqwd ;
reg									eof_dqwd_dly1 ;

reg 								eof_dly;
reg 								eof_dly2;

reg									ok_clk250	;
reg		[63:0] 						bdata1;
reg		[63:0] 						bdata2;
reg		[07:0] 						brxc1;

reg		[63:0]						pkt_data	;             		//same time as bdata2
reg									pkt_start, pkt_end, pkt_we ;

reg 	[15:0] 						nbytes, nbytes_out;
reg 	[63:0] 						wdata, pre_wdata;
reg 	[RX_DRAM_ADDR_WIDTH-1:0] 	waddr1; 
reg		   							b2b_pkt;						// indicate packets that have only 1 or no Idle gap in between
reg		  							reject;			

wire								pkt_reject = reject ;			//over all late rejection signal
reg									type_reject;					//protocol type reject

reg 	[RX_DRAM_ADDR_WIDTH-1:0] 	waddr, pre_waddr;  
reg 	[11:0] 						upd_cnt;

reg 								overwrite;
reg 								first_time;
reg  								wen1;
reg  								wen, pre_wen;
reg  								nowr;

reg 								daddr_hit0;
reg 								baddr_hit;
reg 								bcast_addr;						//if 1, MAC dest addr is broadcast addr
reg 								mcast_addr;

reg 								paddr_hit;

wire 	[47:0] 						chk_daddr_order;
wire 	[47:0] 						qchk_daddr_order;
     	       						
reg  	[31:0] 						chk_crc;
reg  	[15:0] 						rx_opcode;
reg  	[15:0] 						rx_type;
reg  	[15:0] 						rx_pvalue;
reg  	[47:0] 						chk_daddr;
reg  	[47:0] 						qchk_daddr;

reg  	[07:0]	 					rport;
reg  								mac_hit;
reg  								my_mac_hit;
reg  								mcast_hit;
     								
reg  								rx_pause;
reg  								sof_dly2;
reg  								opcode_pause;
reg  								port0_hit;
reg  								pmode_hit;

reg									vlan_ip	;
reg 								pppoe_ip ;
reg 								normal_ip ;
    								
reg									isl_frame ;

reg 	[3:0] 						pkt_ipver;
wire 								pkt_jumbo_flag;
reg 	[47:0]		 				mac_saddr ;
wire       							mac_saddr_vld  ;
wire       							saddr_filter_drop ;
reg 								saddr_filter_drop_flag ;

reg		[2:0]						count8 		;
reg									count8_en1 	;
reg									count8_en2 	;
reg									count8_en3  ;
reg		[63:0]						qwd0_data_dly1 	;
reg									qwd0_time	;    	 				//for 10G it's SOF time, for 1G, this is immediately after 1st qwd
                					
wire	[1:0]						fmac_speed 	= fmac_ctrl1_dly[17:16] ;
reg									xaui_mode;

assign	sof_n_eof	= sof & (eof & has_sof) ;							//both same time

assign chk_daddr_order = {chk_daddr[7:0],chk_daddr[15:8],chk_daddr[23:16],chk_daddr[31:24],chk_daddr[39:32],chk_daddr[47:40]};
assign qchk_daddr_order = {qchk_daddr[7:0],qchk_daddr[15:8],qchk_daddr[23:16],qchk_daddr[31:24],qchk_daddr[39:32],qchk_daddr[47:40]};

wire advance_wptr;


assign	advance_wptr = 
				//valid_frame is too late for sof_n_eof case (pre gated has_sof)
			!wrfull &  sof_n_eof                & mac_hit & !reject               & !overwrite & !saddr_filter_drop_flag |
			!wrfull & !sof_n_eof_dly1 & eof_dly & mac_hit & !reject & valid_frame & !overwrite & !saddr_filter_drop_flag ;

//2nd set of pre-detections for the packet
//7 reserved bits
wire	[7:0]	pre_stat2 = {isl_frame, 7'h0 };

always@(posedge clk156)
begin

	xaui_mode	<= (fmac_speed == 2'b00);

	bdata1   <=   rxd;
	bdata2   <=   bdata1;
		//control bytes, if all 0, has data otherwise control is presence
	brxc1    <=   rxc;
	
	pre_wdata    <=   
		//write the special parameter immediately after EOF
		//rport field is not used, and being used for pre_stat2
		//ETHER_TYPE field becomes the LEN field for ISL_FRAME, so need to gate this
		//  in IP detections.  Cannot gate at the start of the pkt due to timing events
																	
		(sof_n_eof |
		!sof_n_eof_dly1 & eof_dly ) ? {chk_crc,									
						{ (vlan_ip & !isl_frame), pkt_jumbo_flag,				
								(pppoe_ip & !isl_frame), (normal_ip & !isl_frame),
										pkt_ipver},								
							pre_stat2,											
							nbytes} : 											
							//otherwise write in the incoming data
							bdata2;
							
	wdata	<= pre_wdata ;
	
	//saving away the pkt's original CRC for checking later
	if(eof0 || eof1)
		//hold if EOF
		chk_crc <=   chk_crc;
	else
		//getting new values in
	begin
		//add 1G support
		if (xaui_mode)
			//data valid each clock
			case(brxc1)
			//extract the 32 bit CRC field continuously
			//if current incoming has only 1 byte (in BDATA1)
			//take the current byte, combine with previous 3 bytes
			8'hfe: chk_crc <=   {bdata1[7:0], bdata2[63:40]};
			8'hfc: chk_crc <=   {bdata1[15:0],bdata2[63:48]};
			8'hf8: chk_crc <=   {bdata1[23:0],bdata2[63:56]};
			8'hf0: chk_crc <=   bdata1[31:0];
			8'he0: chk_crc <=   bdata1[39:8];
			8'hc0: chk_crc <=   bdata1[47:16];
		8'h80: chk_crc <=   bdata1[55:24];	//7 bytes, take last 4 bytes
		default: chk_crc <=   bdata2[63:32];	//8 bytes, take last 4 bytes
			endcase
		else
			//gige must use chk_crc (32bit) since BDATA2 is not correct
			//data valid each 8th clk
			case(brxc1)
			8'hfe: chk_crc <=   {bdata1[7:0], chk_crc[31:8]};
			8'hfc: chk_crc <=   {bdata1[15:0],chk_crc[31:16]};
			8'hf8: chk_crc <=   {bdata1[23:0],chk_crc[31:24]};
			8'hf0: chk_crc <=   bdata1[31:0];
				//some CRC code is in upper data
			8'he0: chk_crc <=   bdata1[39:8];
			8'hc0: chk_crc <=   bdata1[47:16];
			8'h80: chk_crc <=   bdata1[55:24];
			8'h00: chk_crc <=   bdata1[63:32];
			default: chk_crc <=  chk_crc;
			endcase
		
	end
	
	//counting the byte of the current BDATA1
	case(brxc1)
	8'hfe: bcnt <=   4'd1;
	8'hfc: bcnt <=   4'd2;
	8'hf8: bcnt <=   4'd3;
	8'hf0: bcnt <=   4'd4;
	8'he0: bcnt <=   4'd5;
	8'hc0: bcnt <=   4'd6;
	8'h80: bcnt <=   4'd7;
	8'h00: bcnt <=   4'd8;		
		//control word can have DATA pattern h55 & cannot be counted as 8
	default: bcnt <=   4'd0;
	endcase
	
	//for GigE support
	qwd0_data_dly1	<= 
		!rst_ ? 64'h0 :
		(qwd0_time & !xaui_mode) ? bdata1[63:0] : 
		qwd0_data_dly1;
	
		//latching dest MAC addr
	chk_daddr <=   
		!rst_ ? 48'h0 :		
		//10G case
		(sof_dly & xaui_mode) ? bdata2[47:0] : 
		//1G case
		(qwd0_time & !xaui_mode) ? bdata1[47:0] : 
		//hold
		chk_daddr;
	port0_hit <=   daddr_hit0;
		//incoming MAC addr matches MAC ADDR (daddr0)
	daddr_hit0<=   (chk_daddr_order == daddr0);
		//Broadcast dest addr all F
	baddr_hit <=   (&chk_daddr) & bcast_en;
	
	bcast_addr	<=	(!rst_) ? 1'b0 : (&chk_daddr)	;
		//01-00-5E-{1'b0, 23 bit multicast group address}
	mcast_addr	<=	(!rst_) ? 1'b0 : ( chk_daddr_order[47:23] == {24'h01005E, 1'b0} );
	
	//------------ 11oct13 - FAST checking of dest MAC ADDR
	qchk_daddr <=   
		!rst_ ? 48'h0 :			
		rxd[47:0] ; 

	my_mac_hit	<=
		!rst_ |		
		TCORE_MODE & sof & (qchk_daddr_order[47:23] == {24'h01005E, 1'b0}) ? 1'b0 :		//mcast in TCORE_MODE
		
		sof & (qchk_daddr_order == daddr0) |											//uni
		sof & (&qchk_daddr_order) |														//bcast, all 1's
		!TCORE_MODE & sof & (qchk_daddr_order[47:23] == {24'h01005E, 1'b0}) ? 1'b1 :	//mcast
		sof & (qchk_daddr_order != daddr0) ? 1'b0 :										//uni
		my_mac_hit
		;
		
	mcast_hit	<=
		!rst_ ? 1'b0 :	
		sof & (qchk_daddr_order[47:23] == {24'h01005E, 1'b0}) ? 1'b1 :					//mcast
		mcast_hit
		;
	
	paddr_hit <=   (chk_daddr_order == 48'h0180C2000001) && (rx_type == 16'h8808);
	
	opcode_pause <=   (rx_opcode == 16'h0001);
	
		//detect Inter-Switch Link frame (ISL frame)
		//these are special multicast addr
		//chk_daddr_order is the same time as chk_daddr but re-wired to the correct order
	isl_frame	<= 
		(!rst_) ? 1'b0 : 
			//must keep the value until EOF_DLY
			//clear at the start of each frame to avoid spill over problems
		(pre_sof) ? 1'b0 : 
		(sof_dly2 ) &		
				( ( chk_daddr_order[47:8] == 40'h01000C_0000) |
				  ( chk_daddr_order[47:8] == 40'h03000C_0000) ) ? 1'b1 :
		isl_frame ;
			
end

assign eof = (eof0 || eof1);

wire 	[RX_DRAM_ADDR_WIDTH:0]	wptr_plus_upd_cnt;	//wptr plus updated count
wire	[RX_DRAM_ADDR_WIDTH:0]	new_wptr;
wire 	[RX_DRAM_ADDR_WIDTH:0]	new_wptr_plus1;

				//UPD_CNT is the number of QWD in the current pkt
				//the addr of the DRAM buffer is in QWD
assign			wptr_plus_upd_cnt = wptr + upd_cnt;
					//new pkt write ptr, ie the pkt after this current one
					//detect wrap around if old pkt length + current start location
					//  exceed the RAM max depth
					//if wrap, go to the DELTA location since RAM starts at addr 0 (a wrap does not need to inc 1)
					//normally not wrap so just incr by the update count of the current pkt
assign		    new_wptr = (wptr_plus_upd_cnt > (RX_DRAM_DEPTH-1))? (wptr_plus_upd_cnt - RX_DRAM_DEPTH) : wptr_plus_upd_cnt ;

assign 			new_wptr_plus1 = (wptr_plus_upd_cnt >= (RX_DRAM_DEPTH-1))? (wptr_plus_upd_cnt - (RX_DRAM_DEPTH-1)) : (wptr_plus_upd_cnt + 1);

wire	[RX_DRAM_ADDR_WIDTH:0]	wptr_plus1;

assign			wptr_plus1 = (wptr == (RX_DRAM_DEPTH-1))? 0 : (wptr[RX_DRAM_ADDR_WIDTH-1:0] + 8'd1);

wire	[RX_DRAM_ADDR_WIDTH-1:0]	waddr1_plus1;
							//if waddr1== BFF wrap to 0, otherwise add as normal
assign			waddr1_plus1	=	(waddr1 == (RX_DRAM_DEPTH-1))? 0 : (waddr1 + 8'd1);

always @ (posedge clk156)
begin
	//indicating very first pkt written into the DRAM buffer
	first_time	 <=		
		//reset (indicating 1st pkt)
		(!rst_ | !fmac_rxd_en)? 1'b1 : 
		//if wptr incremented, negate
		((wptr != 0)? 1'b0 : 
		//hold
		first_time);
		
end

//---------- PRE-detect some critical events ------------

assign	eof_qwd =  	(brxc1[0] && (bdata1[7:0] == 8'hFD))   || 
					(brxc1[1] && (bdata1[15:8] == 8'hFD))  || 
					(brxc1[2] && (bdata1[23:16] == 8'hFD)) || 
					(brxc1[3] && (bdata1[31:24] == 8'hFD)) ||
					
	         		(brxc1[4] && (bdata1[39:32] == 8'hFD)) || 
					(brxc1[5] && (bdata1[47:40] == 8'hFD)) || 
					(brxc1[6] && (bdata1[55:48] == 8'hFD)) || 
					(brxc1[7] && (bdata1[63:56] == 8'hFD));
	//EOF but contains data
					
assign	eof_dqwd =  eof_qwd & ( (brxc1 == 8'hE0) | (brxc1 == 8'hC0) | (brxc1 == 8'h80) ) ; 


always@(posedge clk156)
if( !rst_ | !fmac_rxd_en )
begin
	eof_dqwd_dly1	<= 1'b0;
	
	raddr_chk <=   0;
	wr_nbyte       <=   1'b0;
	pre_wen       <=   1'b0;
	wen       <=   1'b0;
	wen1      <=   1'b0;
	pre_sof	  <=   1'b0;
	sof       <=   1'b0;
	sof_pending       <=   1'b0;				
	
	eof0      <=   1'b0;
	eof1      <=   1'b0;
	err       <=   1'b0;
	nbytes    <=   16'h0;
	nbytes_out    <=   16'h0;
	rx_err0   <=   1'b0;
	rx_err1   <=   1'b0;

	eof_dly   <=   1'b0;
	eof_dly2  <=   1'b0;
	overwrite <=   1'b0;
	wptr      <=   0;
	upd_cnt   <=   12'h0;
	waddr1    <=   0;
	b2b_pkt	  <=   1'b0;
	reject	  <=   1'b0;
	waddr     <=   0;
	pre_waddr     <=   0;
	
	wrfull		<= 1'b0;
	wrusedw		<= 0;
	space_ok	<= 1'b1;
	
	nowr      <=   1'b0;
	sof_dly   <=   1'b0;
	post_sof_dly   <=   1'b0;
	
	sof_dly2  <=   1'b0;
	mac_hit   <=   1'b0;
	rx_pvalue <=   16'h0;
	rx_pause  <=   1'b0;
	rx_opcode <=   16'h0;
	rx_type   <=   16'h0;
	rport     <=   8'h0;
	pmode_hit <=   1'b0;
	has_pre_sof		<=	1'b0;
	has_sof		<=	1'b0;
	has_sof_dly1		<=	1'b0;
	
	valid_frame	<=	1'b0;
	
	count8 		<= 3'd7;
	count8_en1 	<= 1'b0;
	count8_en2 	<= 1'b0;
	count8_en3  <= 1'b0;
	qwd0_time	<= 1'b0;
	
end
else
begin

	raddr_chk <=  raddr_marker; 
	pmode_hit <=   pmode;
	
	rx_pause  <=   rx_pause ? !rx_pack : ((pause_en && !rport[0])? (eof_dly2 && paddr_hit && opcode_pause) : 1'b0);
	rx_opcode <=   (sof_dly)  ? {bdata1[55:48],bdata1[63:56]} : rx_opcode;	//for PAUSE frame
		//Ethernet Type field
	rx_type   <=   (sof_dly)  ? {bdata1[39:32],bdata1[47:40]} : rx_type;
	
	rx_pvalue <=   (sof_dly2) ? {bdata1[7:0],bdata1[15:8]} : rx_pvalue;
	mac_hit   <=   (port0_hit || baddr_hit || pmode_hit) && !paddr_hit;
	rport     <=   sof ? rxp : rport;	
	
	sof_dly   <=   
		xaui_mode ? sof :
		//gige support (note the count8 is 1 clk behind)
			//gige may need to recheck due to changes in byte_reorder(5jun13)
		(count8 == 3'd2) & count8_en2
		;
		
	post_sof_dly  <=   sof_dly;
	
	sof_dly2  <=   
		xaui_mode ? sof_dly :
		//gige support (note the count8 is 1 clk behind)
		(count8 == 3'd2) & count8_en3
		;
		//do not write on error codes
		//if the last incoming qwd is 4 bytes, 3 bytes, 2 bytes, or 1 byte
		//  ie the last qword contain only CRC info
	nowr      <=   (brxc1[7:0] == 8'hf0) || (brxc1[7:0] == 8'hf8) || (brxc1[7:0] == 8'hfc) || (brxc1[7:0] == 8'hfe);
	
		//pkt length in QWD count
		//NBYTE is the number of bytes in the current pkt
		// UPD_CNT = updated qwd count
		//if NBYTE has some extra bytes, add the extra qwd
		//this is used in calculating the next wptr
		//increment as pkt's qwd coming in
		//dynamic qwd cnt, increment on each qwd coming in
	upd_cnt   <=   
		//if NBYTE has extra bytes (not even number of qwd), add 2 qwds
		(|nbytes[2:0]) ? (nbytes[14:3] + 12'd2) : 	 
		//otherwise add 1 qwd
		(nbytes[14:3] + 12'd1);  	 // only need bits [14:0] to represent 16384 bytes
		
	overwrite	<= 1'b0 ;
	
	wr_nbyte	<=
		( wr_nbyte ) ? 1'b0 :
		//VERY last write (1 pulse), write in the NBYTE (if not rejected)
		(sof_n_eof & my_mac_hit & !type_reject |
		!sof_n_eof_dly1 & eof_dly & has_sof_dly1 & my_mac_hit & !type_reject ) ? 1'b1 : 
		1'b0 ;
		
	
	wen			<= pre_wen ;
	
	pre_wen     <=   
		//last data write for data mixing in EOF qwd (no CRC write.  Last eof_dqwd may have 1, 2, or 3 bytes)
		eof_dqwd_dly1 & space_ok & has_sof ? 1'b1 :
		//follows WEN1 pulse if
			//gating with sof_pending to avoid erroneous writes during boot or driver load
			//writing of the pkt
		(wen1 & sof_pending & space_ok
			//no error
			& !err & !rx_err0 & !rx_err1 
			//not overflow
			& !overwrite 
			//not start or end of frame or no write conditions
			//this prevents the PRE-AMBLE from writing in
			& !(sof |(nowr & eof)));
			
		//write en 1 if all lanes are good data (this is during the data phase, not begin or end)
		//WEN1 matched to BDATA1 timing (except for the very 1st pkt, or after long gap between pkts)
	wen1      <=   fmac_rxd_en & has_pre_sof 
						& !(&brxc1) 	
						& ( !eof_qwd  )
						& !err;
						
		//this is the WADDR for the DRAM buffer
		//WADDR1 is the consecutive writing (inc by 1 each time)
		//WPTR is the addr where the length of the packet is written if end_of_frame is reached
		//		WPTR is aligned to Qword
	pre_waddr     <=   
		//1st DRAM write addr is the WPTR aligned to Qwd
			//if full just keep the waddr
			(wrfull ) ? pre_waddr :
			//at end of normal write cycle, write the last one (NBYTE) to the beginning
			//cannot use EOF here due to uneven Qwd pkt
			(sof_n_eof |			
			!sof_n_eof_dly1 & eof_dly & !reject )  ? wptr[RX_DRAM_ADDR_WIDTH-1:0] : 
			//during write, keep if not OK (space OK does not change during the pkt)
			(!space_ok ) ? pre_waddr :
			//increment during write
		//subsequent write follows waddr1
			//increment during write
			waddr1;
			
	waddr	<= pre_waddr ;
			
			//should only check at EOF.  No because always guarantee enough space for a pkt at the beginning
	wrfull		<= rxfifo_full;
	
	wrusedw		<=		//TRUE WRUSEDW
		//init at reset time
		//NOTE:  raddr_chk may change on a clk basis during some interval
		//add during write, subtract on read out
		//just use the old raddr for calc the used size.  If raddr increment late it just implies we have
		//less available space than we actualy have
			//normal condition
		!(raddr_chk > wptr) ? (wptr - raddr_chk) :
		wptr + (RX_DRAM_DEPTH - raddr_chk)
		;
		
	space_ok	<= !rxfifo_full ;
	
	//back 2 back pkt, if next pkt (pre_sof) come in while previous GOOD pkt ending
	//pre_sof is of current pkt; has_sof_dly1 is of previous good pkt
	b2b_pkt	  <=   pre_sof & has_sof_dly1 & (eof | eof_dly);
	
	reject	  <=   
		//reject current data if EOF and got error or not enough space
			//not mac_hit must drop (if pmode, it will hit)
		eof ? (err | rx_err0 | rx_err1 | overwrite | !space_ok | !mac_hit) : 
		//clear
		(eof_dly2? 1'b0 : 
		//hold
		reject);
		
		
	has_pre_sof		<=	pre_sof? 1'b1: 	//assert
						(eof & !sof ? 1'b0 : 	//negate at the end
						has_pre_sof);		//hold
						
	has_sof		<=	sof? 1'b1: 	//assert
						(eof? 1'b0 : 	//negate at the end
						has_sof);		//hold
						
	has_sof_dly1	<= has_sof ;
							
		//only assert from EOF to EOF_DLY2 for advancing the WPTR
	valid_frame	<=	
		eof? has_sof : 
		eof_dly2? 1'b0 : 	
		valid_frame ; 
	
	err       <=   
		//clear
		pre_sof ? 1'b0 : 
		//capture error conditions
		(rx_err0 || rx_err1 || err); 
	eof_dly   <=   eof;
	eof_dly2  <=   eof_dly;
	
		//for XGMII (aligned data), FB only happens on lane 0
	pre_sof	  <=   (rxc[0] && (rxd[7:0] == 8'hFB)) | br_sof4 ;
		
	sof		  <=	pre_sof & fmac_rxd_en;
	
	sof_pending	<=
		//keep negate if NOT RXD enabled
		!fmac_rxd_en ? 1'b0 :
		//assert if seen SOF
		pre_sof & fmac_rxd_en ? 1'b1 :
		//negate on EOF
		eof & !sof ? 1'b0 :	//if got sof must keep 1
		//hold
		sof_pending ;
	
	eof0      <=   	fmac_rxd_en & (brxc1[0] && (bdata1[7:0] == 8'hFD))   || 
					fmac_rxd_en & (brxc1[1] && (bdata1[15:8] == 8'hFD))  || 
					fmac_rxd_en & (brxc1[2] && (bdata1[23:16] == 8'hFD)) || 
					fmac_rxd_en & (brxc1[3] && (bdata1[31:24] == 8'hFD));
					
	eof1      <=   	fmac_rxd_en & (brxc1[4] && (bdata1[39:32] == 8'hFD)) || 
					fmac_rxd_en & (brxc1[5] && (bdata1[47:40] == 8'hFD)) || 
					fmac_rxd_en & (brxc1[6] && (bdata1[55:48] == 8'hFD)) || 
					fmac_rxd_en & (brxc1[7] && (bdata1[63:56] == 8'hFD));
	
		//link err
	rx_err0   <=   (brxc1[0] && (bdata1[7:0] == 8'hFE)) || (brxc1[1] && (bdata1[15:8] == 8'hFE)) || (brxc1[2] && (bdata1[23:16] == 8'hFE)) || (brxc1[3] && (bdata1[31:24] == 8'hFE));
	rx_err1   <=   (brxc1[4] && (bdata1[39:32] == 8'hFE)) || (brxc1[5] && (bdata1[47:40] == 8'hFE)) || (brxc1[6] && (bdata1[55:48] == 8'hFE)) || (brxc1[7] && (bdata1[63:56] == 8'hFE));
	
		//bcnt is the byte cnt of each received QWD
		//but skip 1st 4 bytes in the count (ie pre-skip the CRC bytes)
	nbytes    <=   
		//init
		sof ? 16'hfffc : 
		//norm - adding the byte cnt coming in (dynamic)
		(wen1 |
			//ending, compensate for extra bytes in odd cases due to pre-skip of CRC
			eof & (bcnt < 8'd8) ? (nbytes + bcnt) :
		//hold
		nbytes);
		
	nbytes_out	<= nbytes	;
	
		//if got a good pkt advance wptr, else hold
		//don't advance if wrfull
		//only advance at end of a packet to guarantee the DECAP that it has a complete pkt
		//if wrap waddr1 should also wrap
		//advance at EOF_DLY time if the frame is valid
	wptr[RX_DRAM_ADDR_WIDTH-1:0]      <=   advance_wptr ? waddr1 : wptr;
	
	//============= FOR 1G SUPPORT
		//count every 8 clks (for assembling to 64 bits)
	count8 		<= (count8_en1 | count8_en2 | count8_en3)? (count8 - 3'd1) : 3'd7 ;
		//tracking 1st qwd (qwd0)
	count8_en1 	<= 
		//see SOF assert
		sof? 1'b1 : 
		//negate if signal currently tracking is asserted
		(qwd0_time? 1'b0 : 
		//hold
		count8_en1);
	count8_en2 	<= 	//tracking qwd1_time or same as SOF_DLY
		qwd0_time? 1'b1 : 
		(sof_dly ? 1'b0 : 
		count8_en2);
	count8_en3 	<= 
		sof_dly ? 1'b1 : 
		(sof_dly2? 1'b0 : 
		count8_en3);
	
	qwd0_time   <=   (count8 == 3'd2) & count8_en1;		//qwd0 time
	
	
	if (sof_n_eof )
		waddr1	<= waddr1 + 4'd1 ;
	else
	casez ({eof_dqwd_dly1, wrfull, sof, b2b_pkt, reject, wen1, has_sof})
		7'b0010??? :	waddr1	<=	wptr_plus1 ;		// restart, 2 or more gap between packets, wptr is already valid
		
		7'b00111?? :	waddr1	<=	wptr_plus1 ;		// 1 or 0 gap between packets but drop the packet, restart
		
		
		
		7'b00110?? : 	waddr1	<=	waddr1_plus1;		// 1 or 0 gap between packets, wptr is not valid yet, 
		
		7'b000??11 : 	waddr1	<=	waddr1_plus1 ;	// advance addr for consecutive write
		
			//case of very last data straddle into EOF qwd
		7'b100???1 :	waddr1	<=	waddr1_plus1 ;
		
		default	:	waddr1	<=	waddr1 ;			//hold if full
	endcase
	
	//for taking care of pkt with 1 to 3 bytes extra
	eof_dqwd_dly1	<= eof_dqwd;

end	

// ========================================================
// Logic : Pre-Detetcion of IPv version , Jumbo Pkt , Vlan
// ========================================================

wire	qvlan_type;
wire	vlan_type;
wire	pppoe_session_type;
wire	pppoe_disc_type;

wire	vlan_ip_type;	//VLAN and next layer is IP
wire	pppoe_ip_type;	//PPPoE and next layer is IP
wire	normal_ip_type;	//normal IP packet and next layer is IP
wire	qnormal_ip_type;	//normal IP packet and next layer is IP

wire	qenet_arp_pkt ;

	//decoding the various Ether Types
		//quick versions
assign	qnormal_ip_type 	= (rxd[39:32]==8'h08)&&(rxd[47:40]==8'h00) ;
assign	qvlan_type 			= (rxd[39:32]==8'h81)&&(rxd[47:40]==8'h00) ;
assign	qenet_arp_pkt		=
			(rxd[63:32] == 32'h0100_0608) ; 


assign	normal_ip_type 		= (bdata1[39:32]==8'h08)&&(bdata1[47:40]==8'h00) ;
assign	vlan_type 			= (bdata1[39:32]==8'h81)&&(bdata1[47:40]==8'h00) ;
assign	pppoe_session_type 	= (bdata1[39:32]==8'h88)&&(bdata1[47:40]==8'h64) ;
assign	pppoe_disc_type 	= (bdata1[39:32]==8'h88)&&(bdata1[47:40]==8'h63) ;

assign	vlan_ip_type		= 
			 xaui_mode & vlan_type & ( (rxd[7:0]   ==8'h08) & (rxd[15:8]   ==8'h00) ) |
			 	//Gige mode only look at BDATA1
			!xaui_mode & vlan_type & ( (bdata1[7:0]==8'h08) & (bdata1[15:8]==8'h00) ) 
			;

assign	pppoe_ip_type		= 
			 xaui_mode & pppoe_session_type & ( (rxd[39:32]   ==8'h00) & (rxd[47:40]   ==8'h21) ) |
			!xaui_mode & pppoe_session_type & ( (bdata1[39:32]==8'h00) & (bdata1[47:40]==8'h21) ) 
			;

	reg		non_ip ;
	
always@(posedge clk156)
if(!rst_)
begin
	normal_ip			<= 1'b0 ;
	vlan_ip				<= 1'b0 ;
	pppoe_ip		 	<= 1'b0 ;	// IP only
	
	pkt_ipver 		<= 4'd0 ;
	non_ip			<= 1'b0 ;
	type_reject		<= 1'b0 ;
end
else
begin
	normal_ip	<=	sof_dly ? normal_ip_type : normal_ip ;
	
	vlan_ip		<=	
		 xaui_mode & sof_dly  ? vlan_ip_type : 
		!xaui_mode & sof_dly2 ? vlan_ip_type : 
		vlan_ip ;
	
	non_ip		<= !(vlan_ip | normal_ip) ;
			
		//if had SOF, 2nd Qwd [47:32] = 0x8864 type means PPPoE_Session pkt
		//and potentially has IP layer if the next type is 0x0021
	pppoe_ip <= 
			//update PPPoE_Session IP field
			 xaui_mode & sof_dly  ? pppoe_ip_type :  
			!xaui_mode & sof_dly2 ? pppoe_ip_type :  
			//hold
			pppoe_ip ;

	//reject unwanted pkt types
	//only coded for 10G
	//!!!for VLAN, EXTR needs to check for IP type before accepting
	type_reject	<=	
		sof & !(qnormal_ip_type | qvlan_type | qenet_arp_pkt) ? 1'b1  :
		sof &  (qnormal_ip_type | qvlan_type | qenet_arp_pkt) ? 1'b0  :
		type_reject
		;
		
	pkt_ipver      <= 
		xaui_mode & sof_dly ? 
					//if VLAN & IP case, use next qwd bit 23:20
					( (vlan_ip_type) ? rxd[23:20] :  
					//if PPPoE_Session & IP Type
					  (pppoe_ip_type) ? rxd[55:52] :
					//if NORMAL IP Type
					  (normal_ip_type) ? bdata1[55:52] :
					  
					//if not VLAN & PPPoE Session & not normal IP case
					//put in junk
					//Note that this field will not be valid if not IP packet type
					  
					   4'he ) :    //E = error or junk
		//gige mode
					//if NORMAL IP Type
					!xaui_mode & sof_dly & (normal_ip_type) ? bdata1[55:52] : 
					//if VLAN & IP case, use next qwd bit 23:20
					!xaui_mode & sof_dly2 & (vlan_ip_type) ? bdata1[23:20] : 
					//if PPPoE_Session & IP Type
					!xaui_mode & sof_dly2 & (pppoe_ip_type) ? bdata1[55:52] : 
					//hold
					pkt_ipver ;
	
	
					
end


	//avoid latch condition, making this equation simpler since EOF_DLY is already gated
	// when pkt_jumbo_flag is used
assign pkt_jumbo_flag = (nbytes>16'd1500) ? 1'b1 : 1'b0 ;

//======================
// EXtract Mac Source Address
//======================

always@(posedge clk156)
if(!rst_)
begin
	mac_saddr <= 0 ;
end
else
begin
	mac_saddr <= 
		xaui_mode & sof ? {bdata1[55:48],bdata1[63:56],rxd[7:0],rxd[15:8],rxd[23:16],rxd[31:24] } :  
		//gige mode
		sof_dly ? {qwd0_data_dly1[55:48],qwd0_data_dly1[63:56],  bdata1[7:0],bdata1[15:8],bdata1[23:16],bdata1[31:24] } :
		mac_saddr ;
end

assign mac_saddr_vld =  
			 xaui_mode & sof_dly |
			!xaui_mode & post_sof_dly ;

//====================
// Mac Ipv6 Multicast
// Filter Function
//====================
			
fmac_saddr_filter fmac_saddr_filter_U1
(
.clk(clk156),				// i-1
.rst_(rst_),				// i-1
// Input from mac_regs
.mcast_en(mcast_en),				// i-1
.mcast_saddr(mcast_saddr),				// i-48
// Inputs from mac_ppr
.mac_saddr(mac_saddr),				// i-48
.mac_saddr_vld(mac_saddr_vld),				// i-1
// Output
.saddr_filter_drop(saddr_filter_drop)				// o-1
);


//======================
// EXtract Mac Source Address
//======================

always@(posedge clk156)
if(!rst_)
begin
	saddr_filter_drop_flag <= 0 ;
end
else
begin
	saddr_filter_drop_flag <= 
					saddr_filter_drop ? (pkt_ipver==4'h6) : 
					eof_dly2 ? 1'b0 : 
					//hold
					saddr_filter_drop_flag ;
end


// ========================================================
// REGISTER and SYNCHRONIZATION
// ========================================================
reg [31:0]	no_space_drop_cnt;
reg			no_space_drop;
reg [31:0]	FMAC_DCNT_OVERRUN;	// 250 Mhz


reg [31:0]	bad_link_drop_cnt;
reg			bad_link_drop;
reg [31:0]	FMAC_DCNT_LINK_ERR;	// 250 Mhz
reg			FIFO_OV_IPEND;		// 250 Mhz

reg [31:0]	FMAC_PKT_CNT_OVERSIZE;	// 250 Mhz
reg			pkt_oversize;

always @ (posedge clk156)
begin
	if (!rst_)
	begin
		no_space_drop_cnt <= 32'h0;
		no_space_drop <= 1'b0;
		
		bad_link_drop_cnt <= 32'h0;
		bad_link_drop <= 1'b0;
		
		MAX_PKT_SIZE	<=	14'd1518	;
		pkt_slice_en	<=	1'b0	;
		
		pkt_oversize <= 1'b0	;
		
		sof_n_eof_dly1	<= 1'b0 ;
		sof_n_eof_dly2	<= 1'b0 ;
	end
	
	else
	begin
		sof_n_eof_dly1	<= sof_n_eof ;
		sof_n_eof_dly2	<= sof_n_eof_dly1 ;
	
		MAX_PKT_SIZE	<=	fmac_ctrl1_dly[13:0]	;
		pkt_slice_en	<=	fmac_ctrl1_dly[15]		;
		
		no_space_drop_cnt <= no_space_drop? (no_space_drop_cnt + 32'd1) : no_space_drop_cnt;
			//does not allow the DRAM buffer to overwrite any more
			//so account only when got new pkt coming in & the buffer is full
		no_space_drop <= 
			sof & !space_ok;
		
		bad_link_drop_cnt <= bad_link_drop? (bad_link_drop_cnt + 32'd1) : bad_link_drop_cnt;
		bad_link_drop <= eof & (err | rx_err0 | rx_err1);
		
		pkt_oversize	<= 
				//clr
				eof_dly2 ? 1'b0 : 
				//set
				( eof & (nbytes > MAX_PKT_SIZE) ) ? 1'b1 : 
				//hold
				pkt_oversize;
				
	end
end

//============== SYNC the reg for output to internal logic

reg		no_space_drop0_clk250;
reg		no_space_drop1_clk250;

reg		bad_link_drop0_clk250;
reg		bad_link_drop1_clk250;

//detect the capture en for clk250 (if see 2 zeroes in a row)
wire	no_space_drop_clk250 = no_space_drop0_clk250 & no_space_drop1_clk250;
wire	bad_link_drop_clk250 = bad_link_drop0_clk250 & bad_link_drop1_clk250;

always @ (posedge clk250)
	begin
		//if see 2 zero in a row (not updating by clk156), can capture the data
	no_space_drop0_clk250	<= !no_space_drop;
	no_space_drop1_clk250	<=  no_space_drop0_clk250;
	
	bad_link_drop0_clk250	<= !bad_link_drop;
	bad_link_drop1_clk250	<=  bad_link_drop0_clk250;
	
	
	end

	
wire	no_space_drop_ok = no_space_drop_clk250;
wire	bad_link_drop_ok = bad_link_drop_clk250;

always @ (posedge clk250)
begin
	if (!rst_)
	begin
		FMAC_DCNT_OVERRUN <= 32'h0;
		FMAC_DCNT_LINK_ERR <= 32'h0;
		FIFO_OV_IPEND <= 1'b0;
	end
	
	else
	begin
		FMAC_DCNT_OVERRUN <= no_space_drop_ok? no_space_drop_cnt : FMAC_DCNT_OVERRUN;
		
			//sync the sampling - should be whenever EOF low for 2 clks in a row.
		FMAC_DCNT_LINK_ERR <= bad_link_drop_ok? bad_link_drop_cnt : FMAC_DCNT_LINK_ERR;
		
		FIFO_OV_IPEND <= no_space_drop_ok;
	end
end

// ========================================================
//====== SUPPORT FOR COUNTING B/MCAST, OverSize PKTS
//========================================================

reg		add_lo_bcast156	;
reg		add_lo_mcast156	;

reg		add_lo_bcast	;
reg		add_lo_mcast	;

reg		clr_carry_cast	;
reg		add_hi_cast		;

reg		eof_sync_wait	;
reg		eof_sync_wait_dly	;
reg		clr_pkt_cnt_oversize_dly	;


always @(posedge clk156)
	if (!rst_)
		begin
		add_lo_bcast156		<= 1'b0;
		add_lo_mcast156		<= 1'b0;	
		end
		
	else
		begin
		add_lo_bcast156		<= 
				//clr
				(eof_dly2) ? 1'b0 :
				//set
				(eof & bcast_addr) ? 1'b1 :
				//hold
				add_lo_bcast156
				;
		add_lo_mcast156		<= 
				//clr
				(eof_dly2) ? 1'b0 :
				//set
				(eof & mcast_addr) ? 1'b1 :
				//hold
				add_lo_mcast156
				;
		end

//250MHz domain
		
reg		ok_clk250_dly1;
reg		ok_clk250_dly2;
reg		ok_clk250_dly3;
reg		ok_clk250_dly4;


//clk 250 see EOF low for 2 clks in a row
always @(posedge clk250)
	if (!rst_)
		begin
		
		ok_clk250			<= 1'b0;
		
		ok_clk250_dly1		<= 1'b0 ;
		ok_clk250_dly2		<= 1'b0 ;
		ok_clk250_dly3		<= 1'b0 ;
		ok_clk250_dly4		<= 1'b0 ;
		
		eof_sync_wait		<= 1'b0;
		eof_sync_wait_dly	<= 1'b0;
		
		end
	
	else
		begin
		ok_clk250			<=
				//clear if set
				ok_clk250 ? 1'b0 :
				//asserts when seeing the 1st valid EOF
				(!ok_clk250 & !eof_sync_wait & eof_dly) ? 1'b1 :
				//hold
				ok_clk250;
				
				
		ok_clk250_dly1		<= ok_clk250 ;
		ok_clk250_dly2		<= ok_clk250_dly1 ;
		ok_clk250_dly3		<= ok_clk250_dly2 ;
		ok_clk250_dly4		<= ok_clk250_dly3 ;
		
		eof_sync_wait				<= 
							//Force clear at stat OK delay 4
							ok_clk250_dly4 ? 1'b0 :
							//set at stat ok
							ok_clk250 ? 1'b1 :
							//hold
							eof_sync_wait;
							
		eof_sync_wait_dly			<= eof_sync_wait ;

		end

//======== GENERATING 250MHz outputs
always @(posedge clk250)
	if (!rst_)
		begin
		add_lo_bcast	<= 1'b0 ;
		add_lo_mcast	<= 1'b0 ;
		clr_carry_cast	<= 1'b0 ;
		add_hi_cast		<= 1'b0 ;
		end
		
	else
		begin
		add_lo_bcast	<= add_lo_bcast156 & !eof_sync_wait & ok_clk250 ;
		add_lo_mcast	<= add_lo_mcast156 & !eof_sync_wait & ok_clk250 ;
		
		clr_carry_cast	<= ok_clk250_dly3 ;
		
		add_hi_cast		<= ok_clk250_dly1 & !eof_sync_wait_dly  ;		
		end

// ========================================================
// RECODE of registers
// ========================================================
		
always @(posedge clk250)
	if (!rst_)
		begin
		FMAC_PKT_CNT_OVERSIZE		<= 32'h0 ;
		
		clr_pkt_cnt_oversize_dly	<= 1'b0	;
		end
		
	else
		begin
		clr_pkt_cnt_oversize_dly <= clr_pkt_cnt_oversize;
		
		FMAC_PKT_CNT_OVERSIZE	<= 
				//clear
				(clr_pkt_cnt_oversize_dly ) ? 32'h0 :
				//add, pkt_oversize is 156MHz signal
				(ok_clk250 & !eof_sync_wait & pkt_oversize ) ? FMAC_PKT_CNT_OVERSIZE + 1'b1 :
				//keep
				FMAC_PKT_CNT_OVERSIZE;
		
		end
		

//================= PKT Info for saving into the FIFO

reg		[63:0]	pre_pkt_data	;
reg				pre_pkt_start	;

always@(posedge clk156)
if( !rst_ | !fmac_rxd_en )
	begin
	pre_pkt_data		<= 64'h0;
	pre_pkt_start		<= 1'b0;
	pkt_data		<= 64'h0;
	pkt_start		<= 1'b0;
	pkt_end			<= 1'b0;
	pkt_we			<= 1'b0;
	
	pre_eof		<= 1'b0 ;
	end
else
	begin
	pre_pkt_data		<= 
		bdata1;
	pre_pkt_start		<= 
		//case of SOF4 took care of in SOF
		sof;
		
	pkt_data	<= pre_pkt_data;
	pkt_start	<= pre_pkt_start & my_mac_hit & !type_reject;	
	pkt_end			<= 
		pkt_end ? 1'b0 :
		eof_dqwd ? 1'b0 :
		eof_dqwd_dly1 & pkt_we ? 1'b1 :
		pre_eof	& pkt_we
		;
		
	pkt_we		<=
		pkt_end ? 1'b0 :
		pre_pkt_start & my_mac_hit & !type_reject ? 1'b1 :
		pkt_we
		;		
	pre_eof		<=		//too late so need to delay the data
	   	fmac_rxd_en & (rxc[0] && (rxd[7:0] == 8'hFD))   || 
		fmac_rxd_en & (rxc[1] && (rxd[15:8] == 8'hFD))  || 
		fmac_rxd_en & (rxc[2] && (rxd[23:16] == 8'hFD)) || 
		fmac_rxd_en & (rxc[3] && (rxd[31:24] == 8'hFD)) ||
					
	   	fmac_rxd_en & (rxc[4] && (rxd[39:32] == 8'hFD)) || 
		fmac_rxd_en & (rxc[5] && (rxd[47:40] == 8'hFD)) ||       
		fmac_rxd_en & (rxc[6] && (rxd[55:48] == 8'hFD)) ||       
		fmac_rxd_en & (rxc[7] && (rxd[63:56] == 8'hFD))          
		;
		
		end

//========================================================
// CRC32
//========================================================
wire			pre_pkt_we_wire	;

wire			pre_pkt_eof	;
wire	[2:0]	pre_pkt_beat_bcnt_wire	;

reg		[2:0]	pre_pkt_beat_bcnt	;
reg		[2:0]	pre_pkt_beat_bcnt_dly1	;
wire	[31:0]	crc32_out ;
wire			crc32_vld ;
reg				pre_eof_dly1	;
reg				pre_eof_dly2	;
reg				eof_dqwd_dly2 ;



assign	pre_pkt_we_wire	=
		!rst_  ? 1'b0 :
		pre_eof_dly1 & !eof_dqwd_dly1 & pre_pkt_we_wire  ? 1'b0 :
		pre_eof_dly2 &  eof_dqwd_dly2 & pre_pkt_we_wire	 ? 1'b0 :
		pre_pkt_start & my_mac_hit & !type_reject 		 ? 1'b1 :
		pre_pkt_we_wire
		;		
	
// needed for eof with data			
assign	pre_pkt_eof	=
  			pre_eof 	 & !eof_dqwd 		? 1'b1 :
			pre_eof_dly1 & eof_dqwd_dly1 	? 1'b1 :
			1'b0 ;
		
assign	pre_pkt_beat_bcnt_wire	=
  			pre_eof 	 & !eof_dqwd 		? pre_pkt_beat_bcnt :
			pre_eof_dly1 & eof_dqwd_dly1 	? pre_pkt_beat_bcnt_dly1 :
			3'h0 ;
			

always@(posedge clk156)
begin

if( !rst_ | !fmac_rxd_en )
	begin
	pre_eof_dly1		<= 1'b0;
	pre_eof_dly2		<= 1'b0;
	pre_pkt_beat_bcnt	<= 3'b0;
	pre_pkt_beat_bcnt_dly1	<= 3'b0;
	
	eof_dqwd_dly2		<= 1'b0 ;
	end
else
	begin

	pre_eof_dly1		<= pre_eof;
	pre_eof_dly2		<= pre_eof_dly1;
	eof_dqwd_dly2		<= eof_dqwd_dly1 ;
	
		case(rxc)
			8'hff: pre_pkt_beat_bcnt <=   3'd4;
			8'hfe: pre_pkt_beat_bcnt <=   3'd5;
			8'hfc: pre_pkt_beat_bcnt <=   3'd6;
			8'hf8: pre_pkt_beat_bcnt <=   3'd7;
			8'hf0: pre_pkt_beat_bcnt <=   3'd0;
			8'he0: pre_pkt_beat_bcnt <=   3'd1;
			8'hc0: pre_pkt_beat_bcnt <=   3'd2;
			8'h80: pre_pkt_beat_bcnt <=   3'd3;
			8'h00: pre_pkt_beat_bcnt <=   3'd0;				
			
			default: pre_pkt_beat_bcnt <=   3'd0;
		endcase
	
	pre_pkt_beat_bcnt_dly1	<= pre_pkt_beat_bcnt ;
	 
	end
end


eth_crc32_gen eth_crc32_gen(
   .clk			(clk156),         				//clock
   .rst_n		(rst_),        	  				//active low reset
   .data_vld	(pre_pkt_we_wire),     			//data valid
   .data_eop	(pre_pkt_eof),    	   			//end of frame
   .data_sop	(pre_pkt_start),  				//start of frame
   .data_in		(pre_pkt_data),   				//align first byte on bit [7:0] ... last byte [63:56]
   .data_offset	(3'h0), 		  				//number of starting bytes invalid on SOF beat, non SOF should set to 0
   								  				//sdata_offset should be 0 for this module if contained in RX_GMII
   .data_be		(pre_pkt_beat_bcnt_wire),     	//0 - all bytes valid  (really is beat_bcnt)
   	             			 				  	//1 - 1 byte valid bit[7:0]
   	             			 				  	//..
   	             			 				  	//7 - 7 bytes valid bit[55:0]
   .crc_out		(crc32_out),     				//final generated crc32 value
   .crc_vld     (crc32_vld)		 				//crc check valid
 );


wire	crc32_ok ;
assign	crc32_ok	=	crc32_vld ? (crc32_out == chk_crc) : 1'b0 ;



//========================================================
// DRX_PKT_DATA
//========================================================
reg		[63:0]	drx_pkt_data	;             //same time as bdata2
reg				drx_pkt_start ; 
reg				drx_pkt_end ; 
reg				drx_pkt_we ;

reg		[2:0]	drx_pkt_beat_bcnt	;
reg		[7:0]	drx_pkt_be	;

wire	[31:0]	drx_crc32 ;
wire			drx_crc_vld ;
wire			drx_crc_err ;

reg				drx_crc_err_dly1 ;


assign		drx_crc_err = !crc32_ok ;
assign		drx_crc_vld = crc32_vld ;
assign		drx_crc32 	= crc32_out ;


always@(posedge clk156)
if( !rst_ | !fmac_rxd_en )
	begin
		drx_pkt_data		<= 64'h0;
		drx_pkt_start		<= 1'b0;
		drx_pkt_end			<= 1'b0;
		drx_pkt_we			<= 1'b0;
		
		drx_pkt_beat_bcnt	<= 3'h0;
		drx_pkt_be			<= 8'h0;
		
		drx_crc_err_dly1	<= 1'b0;
		
	end
else
	begin
		
		//support MCAST on this port
		drx_pkt_data	<= pre_pkt_data;
		drx_pkt_start	<= pre_pkt_start & (my_mac_hit | mcast_hit) & !type_reject;	
		drx_pkt_end			<= 
			drx_pkt_end ? 1'b0 :
			eof_dqwd ? 1'b0 :
			eof_dqwd_dly1 & drx_pkt_we ? 1'b1 :
			pre_eof	& drx_pkt_we	
			;
		drx_pkt_we		<=
			drx_pkt_end ? 1'b0 :
			pre_pkt_start & (my_mac_hit | mcast_hit) & !type_reject ? 1'b1 :
			drx_pkt_we
			;		
		drx_pkt_beat_bcnt	<=	pre_pkt_beat_bcnt_wire ;
		
		case(pre_pkt_beat_bcnt_wire)
			3'h0: drx_pkt_be <=   8'hff;
			3'h1: drx_pkt_be <=   8'h01;
			3'h2: drx_pkt_be <=   8'h03;
			3'h3: drx_pkt_be <=   8'h07;
			3'h4: drx_pkt_be <=   8'h0f;
			3'h5: drx_pkt_be <=   8'h1f;
			3'h6: drx_pkt_be <=   8'h3f;	
			3'h7: drx_pkt_be <=   8'h7f;	
			
			default: drx_pkt_be <=   8'hff;
		endcase
		
		drx_crc_err_dly1	<= drx_crc_err ;
		
		end


endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/10ps
// synopsys translate_on

module tcore_fmac_core(

// clock & reset
usr_clk,    		// i-1	250Mhz
xaui_clk,			// i-1	125 Mhz (really coreclkout)
usr_rst_,   		// i-1,	RESET if ext dev reset or PCIE reset
fmac_speed,      	// i-2

TCORE_MODE	,		//i-1

// register config
tx_xo_en,			// i-1
rx_xo_en,			// i-1
bcast_en,			// i-1
prom_mode,			// i-1         	
mac_addr0, 			// i-48
mcast_en ,			// i-1
mcast_saddr,		// i-48   
rx_size, 			// i-12
rx_check_crc,		// i-1

// txfifo interface
txfifo_din, 		// i-64
txfifo_wr_en,		// i-1
txfifo_full, 		// o-1
txfifo_usedw,		// o-13

// tx_encap interface
mac_pause_value,	// i-32
tx_b2b_dly,			// i-2

// rxfifo interface
rxfifo_rd_cycle,	// i-1, from EXTR
rxfifo_rd_en,		// i-1
rxfifo_dout,		// o-64
rxfifo_ctrl_dout,	// o-8
rxfifo_empty,		// o-1
//for field debug
rxfifo_full_dbg,	//o-1
rxfifo_usedw_dbg,	//o-12

//---- 1Nov13
drx_pkt_data		,	//o-64	     
drx_pkt_start 		,	//o-1		     
drx_pkt_end 		,	//o-1		     
drx_pkt_we 			,	//o-1		     
drx_pkt_beat_bcnt	,	//o-3	 
drx_pkt_be			,	//o-8	 
drx_crc32 			,	//o-32	
drx_crc_vld 		,	//o-1		     
drx_crc_err 		,	//o-1		     
drx_crc_err_dly1 	,	//o-1		     

//PRE-parser FIFO
cs_fifo_rd_en	,		//i-1, also rd the pre-parser fifo
ipcs_fifo_dout	,		//o-64, {32'b0, fpseudo, fast_ipsum}
cs_fifo_empty	,		//o-1, for debug

// rx_xgmii to iddr
xgmii_rxc,  			// i-8
xgmii_rxd,  			// i-64
xgmii_rxp,  			// i-8
                    	
br_sof4	,				//i-1

fmac_ctrl1_dly,			//i-32
                		
fmac_rxd_en	,			//i-1

//gige_gmii 11 July 2018
gmii_txd, 
gmii_txc,
gmii_tx_en,				//12 july 2018
gmii_tx_vld,			//17 july 2018

//11 July 2018 GMII
linkup_1g,				// i-1
gige_clk,				// i-1

// to mac_register.v
FMAC_TX_PKT_CNT,  		// o-32
FMAC_RX_PKT_CNT_LO,     // o-32
FMAC_RX_PKT_CNT_HI,     // o-32

FMAC_TX_BYTE_CNT,		// o-32
FMAC_RX_BYTE_CNT_LO,    // o-32
FMAC_RX_BYTE_CNT_HI,    // o-32

FMAC_RX_UNDERSIZE_PKT_CNT,	// o-32
FMAC_RX_CRC_ERR_CNT,		// o-32
FMAC_DCNT_OVERRUN,			// o-32
FMAC_DCNT_LINK_ERR,			// o-32
FMAC_PKT_CNT_OVERSIZE,		// o-32
FIFO_OV_IPEND,				// o-1

FMAC_PKT_CNT_JABBER,		// o-32
FMAC_PKT_CNT_FRAGMENT,		// o-32

STAT_GROUP_LO_DOUT	,		//o-32
STAT_GROUP_HI_DOUT	,		//o-32
STAT_GROUP_addr		,		//i-10
STAT_GROUP_sel		,		//i-1
fmac_rx_clr_en				//i-1

);


parameter	FMAC_ID = 10;
parameter	RX_FIFO_DEPTH = 4096;
parameter	RX_FIFO_ADDR_WIDTH = 12;
parameter	RX_DRAM_DEPTH = 3072;	   	//only use 3K qwds
parameter	RX_DRAM_ADDR_WIDTH = 12;
parameter	OVERSIZE_MARK = 9022;		//not used


// clock & reset
input 			usr_clk;
input 			xaui_clk;
input 			gige_clk;
input 			usr_rst_;
input 			[1:0] fmac_speed;
      			
input 			TCORE_MODE;

// register config
input 			tx_xo_en;
input 			rx_xo_en;
input 			bcast_en;
input 			prom_mode;
input 	[47:0] 	mac_addr0;
input 	       	mcast_en ;
input 	[47:0] 	mcast_saddr;
input 	[11:0] 	rx_size;
input 			rx_check_crc;

// txfifo interface
input 	[63:0] 	txfifo_din;
input 			txfifo_wr_en;
output			txfifo_full;
output 	[12:0] 	txfifo_usedw;

// tx_encap interface
input 	[31:0] 	mac_pause_value;
input 	[1:0]  	tx_b2b_dly;

// rxfifo interface
input 			rxfifo_rd_cycle;
input 			rxfifo_rd_en;
output 	[63:0] 	rxfifo_dout;
output	[7:0]		rxfifo_ctrl_dout;		//rsvd, pkt_end, pkt_start
output 			rxfifo_empty;

//for debug
output								rxfifo_full_dbg;
output	[RX_FIFO_ADDR_WIDTH-1 : 0]	rxfifo_usedw_dbg;

output	[63:0]	drx_pkt_data	;             
output			drx_pkt_start ; 
output			drx_pkt_end ; 
output			drx_pkt_we ;
output	[2:0]	drx_pkt_beat_bcnt	;
output	[7:0]	drx_pkt_be	;
output	[31:0]	drx_crc32 ;
output			drx_crc_vld ;
output			drx_crc_err ;
output			drx_crc_err_dly1 ;


//pre-parser FIFO
input			cs_fifo_rd_en	;	//i-1
output 	[63:0] 	ipcs_fifo_dout	;	
output			cs_fifo_empty	;	//o-1, for debug

// front end interface
input 	[07:0] 	xgmii_rxc; 
input 	[63:0] 	xgmii_rxd; 
input 	[07:0] 	xgmii_rxp;
               	
input			br_sof4 ;

input	[31:0]	fmac_ctrl1_dly	;	//i-32
input			fmac_rxd_en	;		//i-1

input			linkup_1g;		

//gige_gmii 11 July 2018
output	[7 : 0]	gmii_txd; 
output 			gmii_txc;
output 				gmii_tx_en;		//12 july 2018
output 				gmii_tx_vld;	//17 july 2018

// to mac_register.v
output 	[31:0] 	FMAC_TX_PKT_CNT;

//temp, tie lo , MAY NOT need
output 	[31:0] 	FMAC_RX_PKT_CNT_LO;				wire	[31:0]	FMAC_RX_PKT_CNT_LO = 32'h0 ;
output 	[31:0] 	FMAC_RX_PKT_CNT_HI;				wire	[31:0]	FMAC_RX_PKT_CNT_HI = 32'h0 ;
       	       	                          	
output 	[31:0] 	FMAC_TX_BYTE_CNT;         	
output 	[31:0] 	FMAC_RX_BYTE_CNT_LO;			wire	[31:0]	FMAC_RX_BYTE_CNT_LO = 32'h0 ;
output 	[31:0] 	FMAC_RX_BYTE_CNT_HI;			wire	[31:0]	FMAC_RX_BYTE_CNT_HI = 32'h0 ;
       	       	
output 	[31:0] 	FMAC_RX_UNDERSIZE_PKT_CNT;		wire	[31:0]	FMAC_RX_UNDERSIZE_PKT_CNT = 32'h0 ;
output 	[31:0] 	FMAC_RX_CRC_ERR_CNT;			wire	[31:0]	FMAC_RX_CRC_ERR_CNT = 32'h0 ;
output 	[31:0] 	FMAC_DCNT_OVERRUN;
output 	[31:0] 	FMAC_DCNT_LINK_ERR;
output 	[31:0] 	FMAC_PKT_CNT_OVERSIZE;
output			FIFO_OV_IPEND;
       	
output 	[31:0] 	FMAC_PKT_CNT_JABBER;			wire	[31:0]	FMAC_PKT_CNT_JABBER = 32'h0 ;
output 	[31:0] 	FMAC_PKT_CNT_FRAGMENT;			wire	[31:0]	FMAC_PKT_CNT_FRAGMENT = 32'h0 ;
                                        		
//Interface to the FMAC reg IF
output	[31:0]	STAT_GROUP_LO_DOUT;				wire	[31:0]	STAT_GROUP_LO_DOUT = 32'h0 ;
output	[31:0]	STAT_GROUP_HI_DOUT;				wire	[31:0]	STAT_GROUP_HI_DOUT = 32'h0 ;
input	[9:0]	STAT_GROUP_addr; 
input			STAT_GROUP_sel; 
input			fmac_rx_clr_en;



reg				cs_fifo_rst ;	
        		
wire			wr_nbyte	;

wire	[15:0]	nbytes;

wire	[9:0]	ipcs_fifo_wrusedw ;			//14 June 2018

wire	[63:0]	pkt_data;
wire			pkt_we, pkt_start, pkt_end ;

//TEMP
wire			fmac_tx_byte_cnt_clr = 0 ;

// wires between txfifo & tx_encap
wire 			txfifo_empty;
wire 			txfifo_rd_en;
wire 	[63:0] 	txfifo_dout; 

// wires between tx_enccap & tx_xgmii
wire 	[63:0] 	entx2ram_wdata;
wire 			rts;
wire 	[15:0] 	rbytes;

wire 			rxfifo_full;
reg	 			rxfifo_full_dbg;

wire 	[RX_FIFO_ADDR_WIDTH : 0] 	rxfifo_rdusedw;
                                 	
wire 	[RX_FIFO_ADDR_WIDTH-1:0] 	rxfifo_usedw;	
                                 	
assign	rxfifo_usedw	= 12'd0 ;						//keep from floating

reg 	[RX_FIFO_ADDR_WIDTH-1:0] 	rxfifo_usedw_dbg;
                                 	
wire 	[RX_FIFO_ADDR_WIDTH : 0] 	rxfifo_wrusedw;	   	//NJP ??? 1aug13, really 11:0

wire 	[RX_DRAM_ADDR_WIDTH:0]    	xgmir2derx_wptr;
wire 	[RX_DRAM_ADDR_WIDTH-1:0]  	raddr_marker;

wire			clr_pkt_cnt_oversize;
        		
wire	add_lo_bcast	;			//  these signals are 250Mhz pre-synced
wire	add_lo_mcast	;			// 
wire	clr_carry_cast	;			// clr the carry of the B/Mcast group
wire	add_hi_cast		;			// add the HI reg of the B/Mcast group

// wires between rxdram & rx_xgmii
wire 	[63:0] 	xgmir2ram_wdata;

wire 	[RX_DRAM_ADDR_WIDTH-1:0]  	xgmir2ram_waddr;

wire 			xgmir2ram_wen;

// wires between tx_encap & rx_xgmii
wire 	[15:0] 	rx_pvalue;
wire 			rx_pause;
wire 			rx_pack;

// wires between tx_decap & rx_decap
wire			xreq;
wire			xon;
wire			xdone;

wire	[1:0]	fmac_speed 	 ;
wire			xaui_mode;

wire			cts_1g;

wire 	[10:0] 	txfifo_usedw_int;    


assign txfifo_usedw = {3'h0, txfifo_usedw_int};

//initialisation to zero: 15 AUG 2018
assign raddr_marker	= 12'b0;
assign clr_pkt_cnt_oversize = 1'b0;
assign xreq = 1'b0;
assign xon = 1'b0;



// =========================================
// TRANSMIT PATH
// txfifo -> tx_encap -> tx_xgmii
// =========================================	
txfifo_1024x64 txfifo(
	.data	(txfifo_din),
	.wrreq	(txfifo_wr_en),
	.rdreq	(txfifo_rd_en),
	.wrclk	(usr_clk),
	.rdclk	(xaui_clk),
	.aclr	(~usr_rst_),
	.q		(txfifo_dout),
	.wrfull	(txfifo_full),
	.rdempty(txfifo_empty),
	.wrusedw(txfifo_usedw_int)
	);

	                               	
gige_tx_encap gige_tx_encap(

	.clk				(xaui_clk),     	// i-1  
	.rst_				(usr_rst_),         // i-1  
	.fmac_speed 		(fmac_speed), 		//i-2
	                                   	
	.rts				(rts),              // o-1, for older TX_ENCAP
	.wdata				(entx2ram_wdata),   // o-64	
	.rbytes				(rbytes),           // o-16
     
	.cts				(cts_1g),			// i-1, 1G clear to send
	
	.psaddr				(mac_addr0),		// i-48                                  	        
	.mac_pause_value	(mac_pause_value),	// i-32 
	.tx_b2b_dly			(tx_b2b_dly),       // i-2  
	                                   	    
	.rx_pause			(rx_pause),         // i-1  
	.rx_pvalue			(rx_pvalue),        // i-16 
	.rx_pack			(rx_pack),          // o-1  
	                                   	    
	.txfifo_empty 		(txfifo_empty),     // i-1  
    .txfifo_rd_en 		(txfifo_rd_en),     // o-1 
	.txfifo_dout 		(txfifo_dout),      // i-64
	    
	// Interface to rx_decap                       	
	.xreq				(xreq),				// 	i-1
	.xon				(xon),				// 	i-1
	.xdone				(xdone)				// 	o-1
	                        			
	); 	                               	
	
	
assign			xaui_mode	= (fmac_speed == 2'b00);
		
	
	
gige_tx_gmii gige_tx_gmii(

	.clk250			(gige_clk),			// i-1
	.clk125			(gige_clk),   		// i-1
	.rst_			(usr_rst_),			// i-1
	.fmac_speed		(fmac_speed),		// i-2
	
	// Interface to tx_encap
	.rts			(rts),    			// i-1
	.rdata			(entx2ram_wdata),	// i-64
	.rbytes			(rbytes),			// i-16
	.cts			(cts_1g),			// o-1
	      
	// To gige_top                      	
	.gmii_txd		(gmii_txd),			// o-8
	.gmii_txc		(gmii_txc),			// o-1
	.gmii_tx_en		(gmii_tx_en),		// o-1	//12 july 2018
	.gmii_tx_vld	(gmii_tx_vld),		// o-1	//17 july 2018
	.linkup			(linkup_1g),		// i-1
	
	// To mac_register.v
	.FMAC_TX_PKT_CNT		(FMAC_TX_PKT_CNT),  	// o-32
	.FMAC_TX_BYTE_CNT		(FMAC_TX_BYTE_CNT),		// o-32
	.fmac_tx_byte_cnt_clr	(fmac_tx_byte_cnt_clr)	// i-1		TEMP ???
	
	);

	

wire	rxfifo_wrempty156	;			//156


fmac_fifo4Kx64 rxfifo(                     
	.aclr			(!usr_rst_ | !fmac_rxd_en),		//i-1
	.data			(pkt_data),						//i-64 from RX_XGMII     
	.rdclk 			(usr_clk),             			//i-1, 250Mhz         
	.rdreq			(rxfifo_rd_en),   				//i-1, from EXTR
	.wrclk			(xaui_clk),						//i-1, 156MHz
	.wrreq			(pkt_we),						//i-1	
	.q				(rxfifo_dout),          		//o-64 to EXTR                  
	.rdempty		(rxfifo_empty),         		//o-1         (RD EMPTY 250) 
	.rdfull			(),								//o-1	
	.rdusedw		(rxfifo_rdusedw),				//o-12                    
	.wrempty		(rxfifo_wrempty156),			//o-1
	.wrfull			(),                     		
	.wrusedw		(rxfifo_wrusedw)				//o-12
	);
	
	
wire	[7:0]	pktctrl_din	= {
					6'h0	,			//7:2
					pkt_end	,			//1
					pkt_start			//0
					};
				
						
reg		[7:0]	rxfifo_ctrl_dout ;
wire	[7:0]	rxfifo_ctrl_q ;


fmac_fifo4Kx8 pktctrl_fifo (
	.aclr			(!usr_rst_ | !fmac_rxd_en)	,	//i-1
	.data			(pktctrl_din ),					//i-8
	.rdclk 			(usr_clk),             			//i-1, 250Mhz         
	.rdreq			(rxfifo_rd_en),   				//i-1, from EXTR
	.wrclk			(xaui_clk),						//i-1, 156MHz
	.wrreq			(pkt_we),						//i-1
	.q				(rxfifo_ctrl_q),				//o-8
	.rdempty		(),
	.rdfull			(),
	.rdusedw		(),
	.wrempty		(),
	.wrfull			(),
	.wrusedw		()
	);
	
	
//always reserve 2048 bytes
assign	rxfifo_full	= (rxfifo_wrusedw >= 16'd3840 ) | (ipcs_fifo_wrusedw >= 9'd500) ;
	

//for field debug support
always @ (posedge usr_clk)
begin
	rxfifo_usedw_dbg 	<= 	rxfifo_usedw;
	rxfifo_full_dbg		<=	rxfifo_full;
	
	//reset the pattern search fifo on RESET and 
	cs_fifo_rst			<= 
		//reset
		!usr_rst_ ? 1'b1 :
		!fmac_rxd_en ? 1'b1 :
		//negate
		1'b0 ;
		
	rxfifo_ctrl_dout	<= 
		//reset
		!usr_rst_ ? 8'd0 :
		rxfifo_ctrl_q ;
	
end
	

wire	[63:0]	ipcs_fifo_din = {
					2'h0,			//63:62
					nbytes[13:0],	//61:48
					16'h0,			//47:32
					16'h0	,		//31:16 temp???
					16'h0			//15:0, temp???
					};
				

//NOTE:  NBYTES is only correct for non_ip pkts
fmac_fifo512x64_2clk ipcs_fifo (
	.aclr			(cs_fifo_rst),   	//i-1
	.data			(ipcs_fifo_din ),	//i-64
	.rdclk			(usr_clk),
	.rdreq			(cs_fifo_rd_en), 	//i-1, 1 pulse rd enable
	.wrclk			(xaui_clk),
	.wrreq			(wr_nbyte),			//i-1, from RX_XGMII	//26jul2018 kp
	.q				(ipcs_fifo_dout),	//o-64, data out to EXTR {32 rsvd, pseudo, ipsum)
	.rdempty		(cs_fifo_empty),	//26jul2018 kp, used to generate cs_fifo_empty	
	.rdfull			(),
	.rdusedw		(),
	.wrempty		(),
	.wrfull			(),
	.wrusedw		(ipcs_fifo_wrusedw)	//o-9
	);
	

	
tcore_rx_xgmii #(RX_DRAM_DEPTH, RX_DRAM_ADDR_WIDTH)
	rx_xgmii(
	.clk156				(xaui_clk),			// i-1
	.clk250				(usr_clk),			// i-1
	.rst_				(usr_rst_),			// i-1
                    	
	.TCORE_MODE			(TCORE_MODE	),		// i-1
	
	.pkt_data			(pkt_data),			//o-64
	.pkt_start			(pkt_start),		//o-1
	.pkt_end			(pkt_end),			//o-1
	.pkt_we				(pkt_we	),			//o-1
	
	.drx_pkt_data			(drx_pkt_data  ),     	//o-64	     
	.drx_pkt_start 			(drx_pkt_start ),     	//o-1		     
	.drx_pkt_end 			(drx_pkt_end   ),     	//o-1		     
	.drx_pkt_we 			(drx_pkt_we    ),     	//o-1		     
	.drx_pkt_beat_bcnt		(drx_pkt_beat_bcnt),  	//o-3	 
	.drx_pkt_be				(drx_pkt_be	 ),       	//o-8	 
	.drx_crc32 				(drx_crc32 	 ),       	//o-32	
	.drx_crc_vld 			(drx_crc_vld ),       	//o-1		     
	.drx_crc_err 			(drx_crc_err ),       	//o-1		     
	.drx_crc_err_dly1 		(drx_crc_err_dly1 ),  	//o-1		     
	
	.wen					(xgmir2ram_wen),		// o-1
	.waddr					(xgmir2ram_waddr),		// o-param 12
	.wptr					(xgmir2derx_wptr),		// o-param 13
	.raddr_marker			(raddr_marker),			// i-param 12		(XGMII)
	.wdata					(xgmir2ram_wdata),		// o-14
	
	.rx_pause				(rx_pause),				// o-1
	.rx_pvalue				(rx_pvalue),			// o-16
	.rx_pack				(rx_pack),				// i-1

	.pause_en				(rx_xo_en),				// i-1
	.bcast_en				(bcast_en),				// i-1
	.pmode					(prom_mode),			// i-1
	.daddr0					(mac_addr0),			// i-48
	.mcast_en				(mcast_en),				// i-1
	.mcast_saddr			(mcast_saddr),			// i-48
	
	.rsize					(rx_size),				// i-12
	.rxp					(xgmii_rxp),			// i-8
	.rxd					(xgmii_rxd),			// i-64
	.rxc					(xgmii_rxc),			// i-8
	
	.br_sof4				(br_sof4),				//i-1
	
	//from Register
	.fmac_ctrl1_dly			(fmac_ctrl1_dly),		//i-32
	.fmac_rxd_en			(fmac_rxd_en),			//i-1, 13jul11
	
	// To Register
	.FMAC_DCNT_OVERRUN		(FMAC_DCNT_OVERRUN),		// o-32
	.FMAC_DCNT_LINK_ERR		(FMAC_DCNT_LINK_ERR),		// o-32
	.FMAC_PKT_CNT_OVERSIZE	(FMAC_PKT_CNT_OVERSIZE),	// o-32
	.FIFO_OV_IPEND			(FIFO_OV_IPEND),			// o-1
	
	//from DECAP
	.clr_pkt_cnt_oversize	(clr_pkt_cnt_oversize),	//i-1
	
	//to DECAP unit for register tracking
	.add_lo_bcast			(add_lo_bcast),			// o-1, these signals are 250Mhz pre-synced
	.add_lo_mcast			(add_lo_mcast),			// o-1                                     	
	.clr_carry_cast			(clr_carry_cast),		// o-1 clr the carry of the B/Mcast group	
	.add_hi_cast			(add_hi_cast),			// o-1 add the HI reg of the B/Mcast group  	
	                		
    .vlan_ip				(),   					//o-1
    .normal_ip				(),						//o-1	(RXGMII)
    .non_ip					(),						//o-1
    .pkt_reject				(),						//o-1
    .pkt_jumbo_flag			(),						//o-1
    .pkt_ipver				(),						//o-4
                    		
    .wr_nbyte				(wr_nbyte	),	  		//o-1
    .nbytes_out				(nbytes		),			//o-16
    .rxfifo_full			(rxfifo_full)			//i-1
	
	);	
	


endmodule
//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//

`timescale 1ns / 1ns

module txfifo_1024x64

(
			aclr,

			wrclk,       	// Clk for writing data                         
			wrreq,       	// request to write
			data,        	// Data coming in                                                               
			wrfull,  		// indicates fifo is full or not (To avoid overiding)
		                                                                                                 
            wrusedw,     	// number of slots currently in use for writting                             

		    rdclk,        	// Clk for reading data                
			rdreq,        	// Request to read from FIFO                        
			q, 	    	   	// Data coming out                                  
			rdempty  	   	// indicates fifo is empty or not (to avoid underflow)
);

	//setting default values
	parameter WIDTH = 64,
			  DEPTH = 1024,
			  PTR	= 10;
			  
			  
			input wire 					aclr;		//reset
			input  wire 				wrclk;     	// Clk for writing data                             
			input  wire 				wrreq;     	// request to write  
			input  wire [WIDTH-1 : 0]	data;     	// Data coming in                                                                  
			output wire					wrfull;     // indicates fifo is full or not (To avoid overiding)                                                                                              
            output wire	[PTR  : 0]	    wrusedw;    // number of slots currently in use for writing                                    

		    input  wire 				rdclk;      // Clk for reading data               
			input  wire 				rdreq;      // Request to read from FIFO                   
			output wire [WIDTH-1 : 0]	q; 	        // Data coming out                               
			output wire 				rdempty; 	// indicates fifo is empty or not (to avoid underflow)

			asynch_fifo	#(.WIDTH ( WIDTH),
					  	  .DEPTH (DEPTH),
					 	  .PTR	 (PTR) )
 											
	tx_f (
			.reset_		(~aclr),
			        	
			.wrclk		(wrclk),	// i,Clk to write data	
			.wren		(wrreq),	// i,write enable  
			.datain		(data),		// i,write data
			.wrfull		(wrfull),	// o,indicates fifo is full or not (To avoid overiding)
			.wrempty	(),			// o,indicates fifo is empty or not (to avoid underflow)
			.wrusedw	(wrusedw),	// wrusedw -number of locations filled in fifo
                    	
			.rdclk		(rdclk),	// i-1, Clk to read data
			.rden		(rdreq),	// i-1, read enable of data FIFO		
			.dataout	(q),		// Dataout of data FIFO
			.rdfull		(),	
			.rdempty	(rdempty),	// indicates fifo is empty or not (to avoid underflow)
			.rdusedw	(),	
			.dbg		()
		 );
endmodule
