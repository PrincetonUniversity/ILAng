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
x_clk,				// i-1	156.25 Mhz (really coreclkout)
usr_rst_,  			// i-1,	RESET if ext dev reset or PCIE reset 	
                	
mode_10G ,			//i-1, speed modes
mode_5G  ,			//i-1, 
mode_2p5G,	 		//i-1, 
mode_1G  ,			//i-1, 
                	
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
rxfifo_ctrl_dout,	//o-8
rxfifo_empty,		// o-1

//for field debug
rxfifo_full_dbg,	//o-1
rxfifo_usedw_dbg,	//o-12

//---- 1Nov13
drx_pkt_data		,      	//o-64	     
drx_pkt_start 		,       //o-1		     
drx_pkt_end 		,       //o-1		     
drx_pkt_we 			,       //o-1		     
drx_pkt_beat_bcnt	,  		//o-3	 
drx_pkt_be			,       //o-8	 
drx_crc32 			,       //o-32	
drx_crc_vld 		,       //o-1		     
drx_crc_err 		,       //o-1		     
drx_crc_err_dly1 	,     	//o-1		     


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

// tx_xgmii to oddr
xgmii_txc,  			//	o-8
xgmii_txd,  			//	o-64

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
fmac_rx_clr_en		,		//i-1

fmac_tx_clr_en		,


FMAC_RX_PKT_CNT64_LO,   
FMAC_RX_PKT_CNT64_HI,   
                        
FMAC_RX_PKT_CNT127_LO,  
FMAC_RX_PKT_CNT127_HI,  
                        
FMAC_RX_PKT_CNT255_LO,  
FMAC_RX_PKT_CNT255_HI,  
                        
FMAC_RX_PKT_CNT511_LO,  
FMAC_RX_PKT_CNT511_HI,  
                        
FMAC_RX_PKT_CNT1023_LO, 
FMAC_RX_PKT_CNT1023_HI, 
                        
FMAC_RX_PKT_CNT1518_LO, 
FMAC_RX_PKT_CNT1518_HI, 
                        
FMAC_RX_PKT_CNT2047_LO, 
FMAC_RX_PKT_CNT2047_HI, 
                        
FMAC_RX_PKT_CNT4095_LO, 
FMAC_RX_PKT_CNT4095_HI, 
                        
FMAC_RX_PKT_CNT8191_LO, 
FMAC_RX_PKT_CNT8191_HI, 
                        
FMAC_RX_PKT_CNT9018_LO, 
FMAC_RX_PKT_CNT9018_HI, 
                        
FMAC_RX_PKT_CNT9022_LO, 
FMAC_RX_PKT_CNT9022_HI, 
                        
FMAC_RX_PKT_CNT9199P_LO,
FMAC_RX_PKT_CNT9199P_HI

			

);

parameter	FMAC_ID = 10;
parameter	RX_FIFO_DEPTH = 4096;
parameter	RX_FIFO_ADDR_WIDTH = 12;

parameter	RX_DRAM_DEPTH = 3072;		//only use 3K qwds	
parameter	RX_DRAM_ADDR_WIDTH = 12;
parameter	OVERSIZE_MARK = 9022;		//not used


// clock & reset
input usr_clk;
input x_clk;
input usr_rst_;
 
input mode_10G ;		//i-1, speed modes
input mode_5G  ;		//i-1,            
input mode_2p5G;	 	//i-1,           
input mode_1G  ;		//i-1,            
                                    
input TCORE_MODE;

// register config
input tx_xo_en;
input rx_xo_en;
input bcast_en;
input prom_mode;
input [47:0] mac_addr0;
input        mcast_en ;
input [47:0] mcast_saddr;
input [11:0] rx_size;
input rx_check_crc;

// txfifo interface
input [63:0] txfifo_din;
input txfifo_wr_en;
output txfifo_full;
output [12:0] txfifo_usedw;

// tx_encap interface
input [31:0] mac_pause_value;
input [1:0]  tx_b2b_dly;

// rxfifo interface
input rxfifo_rd_cycle;
input rxfifo_rd_en;
output [63:0] rxfifo_dout;
output	[7:0]		rxfifo_ctrl_dout;		//rsvd, pkt_end, pkt_start
output rxfifo_empty;

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
output [63:0] 	ipcs_fifo_dout	;	
output			cs_fifo_empty	;	//o-1, for debug

// front end interface
input [07:0] xgmii_rxc; 
input [63:0] xgmii_rxd; 
input [07:0] xgmii_rxp;

input			br_sof4 ;

input  [31:0] fmac_ctrl1_dly	;	//i-32
input		  fmac_rxd_en	;		//i-1
output [07:0] xgmii_txc; 
output [63:0] xgmii_txd;

// to mac_register.v
output [31:0] FMAC_TX_PKT_CNT;
output [31:0] FMAC_RX_PKT_CNT_LO;		
output [31:0] FMAC_RX_PKT_CNT_HI;		

output [31:0] FMAC_TX_BYTE_CNT;
output [31:0] FMAC_RX_BYTE_CNT_LO;		
output [31:0] FMAC_RX_BYTE_CNT_HI;		

output [31:0] FMAC_RX_UNDERSIZE_PKT_CNT;		
output [31:0] FMAC_RX_CRC_ERR_CNT;				
output [31:0] FMAC_DCNT_OVERRUN;
output [31:0] FMAC_DCNT_LINK_ERR;
output [31:0] FMAC_PKT_CNT_OVERSIZE;
output		  FIFO_OV_IPEND;

output [31:0] FMAC_PKT_CNT_JABBER;		
output [31:0] FMAC_PKT_CNT_FRAGMENT;	

//Interface to the FMAC reg IF
output	[31:0]	STAT_GROUP_LO_DOUT;		
output	[31:0]	STAT_GROUP_HI_DOUT;		
input	[9:0]	STAT_GROUP_addr; 
input			STAT_GROUP_sel; 
input			fmac_rx_clr_en;

input			fmac_tx_clr_en;


output	[32:0]		FMAC_RX_PKT_CNT64_LO;
output	[31:0]		FMAC_RX_PKT_CNT64_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT127_LO;
output	[31:0]		FMAC_RX_PKT_CNT127_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT255_LO;
output	[31:0]		FMAC_RX_PKT_CNT255_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT511_LO;
output	[31:0]		FMAC_RX_PKT_CNT511_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT1023_LO;
output	[31:0]		FMAC_RX_PKT_CNT1023_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT1518_LO;
output	[31:0]		FMAC_RX_PKT_CNT1518_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT2047_LO;
output	[31:0]		FMAC_RX_PKT_CNT2047_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT4095_LO;
output	[31:0]		FMAC_RX_PKT_CNT4095_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT8191_LO;
output	[31:0]		FMAC_RX_PKT_CNT8191_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT9018_LO;
output	[31:0]		FMAC_RX_PKT_CNT9018_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT9022_LO;
output	[31:0]		FMAC_RX_PKT_CNT9022_HI;
      	      		
output	[32:0]		FMAC_RX_PKT_CNT9199P_LO;
output	[31:0]		FMAC_RX_PKT_CNT9199P_HI;


reg		cs_fifo_rst ;		//reset pre-parser fifo

wire	wr_nbyte	;

wire	[15:0]	nbytes;

wire	[9:0]	ipcs_fifo_wrusedw ;		

wire	[63:0]	pkt_data;
wire			pkt_we, pkt_start, pkt_end ;


// wires between txfifo & tx_encap
wire txfifo_empty;

//pre signals: input to mux (to read from TX fifo) - 5 sep 2018
wire pre_txfifo_rd_en_1G;  	
wire pre_txfifo_rd_en_10G; 

wire txfifo_rd_en = mode_1G? pre_txfifo_rd_en_1G : 
						pre_txfifo_rd_en_10G;

wire [63:0] txfifo_dout; 

//pre output signals from 1G wrapper
wire	[7:0]	pre_gmii_txd;
wire			pre_gmii_txc;

//pre output signals from 10G wrapper
wire	[63:0]	pre_xgmii_txd;
wire	[7:0]	pre_xgmii_txc;

wire rxfifo_full;
reg	 rxfifo_full_dbg;

wire 	[RX_FIFO_ADDR_WIDTH : 0] rxfifo_rdusedw;	

wire 	[RX_FIFO_ADDR_WIDTH-1:0] rxfifo_usedw;		//not used, tie lo
assign	rxfifo_usedw	= 12'd0 ;		//keep from floating

reg 	[RX_FIFO_ADDR_WIDTH-1:0] rxfifo_usedw_dbg;

wire 	[RX_FIFO_ADDR_WIDTH : 0] rxfifo_wrusedw;

wire [RX_DRAM_ADDR_WIDTH:0]    xgmir2derx_wptr;
wire [RX_DRAM_ADDR_WIDTH-1:0]  raddr_marker;

wire	clr_pkt_cnt_oversize;

wire	add_lo_bcast	;		//  these signals are 250Mhz pre-synced
wire	add_lo_mcast	;		// 
wire	clr_carry_cast	;		// clr the carry of the B/Mcast group
wire	add_hi_cast		;		// add the HI reg of the B/Mcast group

// wires between rxdram & rx_xgmii
wire [63:0] xgmir2ram_wdata;
wire [RX_DRAM_ADDR_WIDTH-1:0]  xgmir2ram_waddr;
wire 		xgmir2ram_wen;

// wires between tx_encap & rx_xgmii
wire [15:0] rx_pvalue;
wire rx_pause;


//pre signals to differentiate the output to RX
wire pre_rx_pack_1G;
wire pre_rx_pack_10G;
wire rx_pack = mode_1G? pre_rx_pack_1G :
					pre_rx_pack_10G;

// wires between tx_decap & rx_decap
wire	xreq;
wire	xon;

wire pre_xdone_1G;
wire pre_xdone_10G;
wire xdone = mode_1G? pre_xdone_1G :
				pre_xdone_10G;

wire			xaui_mode;

reg	mode_10G_buf ; 
reg	mode_5G_buf  ; 
reg	mode_2p5G_buf; 
reg	mode_1G_buf  ; 


wire [31:0]	chk_crc;
wire [63:0] ram2derx_rdata = 0;

wire		crc32_ok;


wire [10:0] txfifo_usedw_int;   
assign txfifo_usedw = {3'h0, txfifo_usedw_int};

assign raddr_marker	= 12'b0;
assign xreq = 1'b0;
assign xon = 1'b0;

//packet cnt and bcnt from 1G and 10G wrapper 5 sep 2018
wire	[31:0]	PRE_FMAC_TX_PKT_CNT_1G;
wire	[31:0]	PRE_FMAC_TX_PKT_CNT_10G;
wire	[31:0]	PRE_FMAC_TX_BYTE_CNT_1G;
wire	[31:0]	PRE_FMAC_TX_BYTE_CNT_10G;


//buffer
always @(posedge usr_clk) 
	begin
	
		mode_10G_buf    <=	mode_10G ;
		mode_5G_buf     <=	mode_5G  ;
		mode_2p5G_buf	<=	mode_2p5G;
		mode_1G_buf     <=	mode_1G  ;
	
	end




// =========================================
// TRANSMIT PATH
// txfifo -> tx_encap -> tx_xgmii
// =========================================	
txfifo_1024x64 txfifo(
	.data(txfifo_din),
	.wrreq(txfifo_wr_en),
	.rdreq(txfifo_rd_en),
	.wrclk(usr_clk),
	.rdclk(x_clk),
	.aclr(~usr_rst_),
	.q(txfifo_dout),
	.wrfull(txfifo_full),
	.rdempty(txfifo_empty),
	.wrusedw(txfifo_usedw_int)
	);
	
	
	
tx_1G_wrap tx_1G_wrap(
	.x_clk					(x_clk),
	.usr_rst_				(usr_rst_),	

	//tx_encap interface
	.mac_addr0				(mac_addr0),
	.mac_pause_value		(mac_pause_value),
	.tx_b2b_dly				(tx_b2b_dly),
	
	.txfifo_dout			(txfifo_dout),
	.txfifo_empty			(txfifo_empty),
	.pre_txfifo_rd_en_1G	(pre_txfifo_rd_en_1G),				//o-1  read data from tx_fifo
	                                                        	
	.rx_pause				(rx_pause),                     	
	.rx_pvalue				(rx_pvalue),	                	
	.pre_rx_pack_1G			(pre_rx_pack_1G),					//o-1  output to rx
	                                                        	
	.xreq					(xreq),					        	
	.xon					(xon),                          	
	.pre_xdone_1G			(pre_xdone_1G),						//o-1  output to internal wire in tcore
		
	//tx_gmii interface
	.pre_gmii_txd				(pre_gmii_txd),					//o-8
	.pre_gmii_txc				(pre_gmii_txc),					//o-1
	.PRE_FMAC_TX_PKT_CNT_1G		(PRE_FMAC_TX_PKT_CNT_1G),		//o-1
	.PRE_FMAC_TX_BYTE_CNT_1G	(PRE_FMAC_TX_BYTE_CNT_1G),		//o-1
	.fmac_tx_clr_en				(fmac_tx_clr_en)

	);


	
tx_10G_wrap tx_10G_wrap(
	.usr_clk				(usr_clk),			//i-1
	.x_clk					(x_clk),
	.usr_rst_				(usr_rst_),	
	
	.mode_10G 				(mode_10G_buf), 	//i-1, speed modes
	.mode_1G 				(mode_1G_buf), 		//i-1, speed modes
	.mode_5G  				(mode_5G_buf), 		//i-1, 
	.mode_2p5G				(mode_2p5G_buf), 	//i-1, 

	//tx_encap interface
	.mac_addr0				(mac_addr0),
	.mac_pause_value		(mac_pause_value),
	.tx_b2b_dly				(tx_b2b_dly),
	
	.txfifo_dout			(txfifo_dout),
	.txfifo_empty			(txfifo_empty),
	.pre_txfifo_rd_en_10G	(pre_txfifo_rd_en_10G),			//o-1  read data from tx_fifo
	
	.rx_pause				(rx_pause),
	.rx_pvalue				(rx_pvalue),	
	.pre_rx_pack_10G		(pre_rx_pack_10G), 				//o-1  output to rx
	
	.xreq					(xreq),					  
	.xon					(xon),
	.pre_xdone_10G			(pre_xdone_10G),				//o-1  output to internal wire in tcore
		
	//tx_gmii interface
	.xaui_mode					(xaui_mode),				//i-1 a wire 
	.pre_xgmii_txd				(pre_xgmii_txd),			//o-64
	.pre_xgmii_txc				(pre_xgmii_txc),			//o-8
	.PRE_FMAC_TX_PKT_CNT_10G	(PRE_FMAC_TX_PKT_CNT_10G),	//o-1
	.PRE_FMAC_TX_BYTE_CNT_10G	(PRE_FMAC_TX_BYTE_CNT_10G),	//o-1
	.fmac_tx_clr_en				(fmac_tx_clr_en)
	);	

	
assign	xaui_mode	= (mode_10G_buf);	

wire	rxfifo_wrempty156	;	

fmac_fifo4Kx64 rxfifo(                      
	.aclr		(!usr_rst_ | !fmac_rxd_en)	,	//i-1	
	.data		(pkt_data),                     //i-64 from RX_XGMII 
	.rdclk 		(usr_clk),             			//i-1, 250Mhz         
	.rdreq		(rxfifo_rd_en),   				//i-1, from EXTR
	.wrclk		(x_clk),						//i-1, 156MHz
	.wrreq		(pkt_we),						//i-1
	.q			(rxfifo_dout),            		//o-64 to EXTR                  
	.rdempty	(rxfifo_empty),           		//o-1         (RD EMPTY 250) 
	.rdfull		(),								//o-1	
	.rdusedw	(rxfifo_rdusedw),				//o-12                    
	.wrempty	(rxfifo_wrempty156),			//o-1
	.wrfull		(),
	.wrusedw	(rxfifo_wrusedw)				//o-12
	);
	
wire	[7:0]	pktctrl_din	= {
					6'h0	,	//7:2
					pkt_end	,	//1
					pkt_start	//0
					};
					
reg		[7:0]	rxfifo_ctrl_dout ;
wire	[7:0]	rxfifo_ctrl_q ;

fmac_fifo4Kx8 pktctrl_fifo (
	.aclr		(!usr_rst_ | !fmac_rxd_en)	,	//i-1
	.data		(pktctrl_din ),					//i-8
	.rdclk 		(usr_clk),             			//i-1, 250Mhz         
	.rdreq		(rxfifo_rd_en),   				//i-1, from EXTR
	.wrclk		(x_clk),						//i-1, 156MHz
	.wrreq		(pkt_we),						//i-1   		
	.q			(rxfifo_ctrl_q),				//o-8
	.rdempty	(),
	.rdfull		(),
	.rdusedw	(),
	.wrempty	(),
	.wrfull		(),
	.wrusedw	()
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
					2'h0,		//63:62
					//nbyte_out[13:0],	//61:48
					nbytes[13:0],	//61:48
					16'h0,		//47:32
					//fpseudo,	//31:16
					16'h0	,	//31:16 temp???
					//fast_ipsum	//15:0
					16'h0			//15:0, temp???
					};
				

//NOTE:  NBYTES is only correct for non_ip pkts
fmac_fifo512x64_2clk ipcs_fifo (
	.aclr		(cs_fifo_rst),   	//i-1
	.data		(ipcs_fifo_din ),   //i-64
	.rdclk		(usr_clk),
	.rdreq		(cs_fifo_rd_en), 	//i-1, 1 pulse rd enable
	.wrclk		(x_clk),
	.wrreq		(wr_nbyte),			//i-1, from RX_XGMII	//26jul2018 kp
	.q			(ipcs_fifo_dout),   //o-64, data out to EXTR {32 rsvd, pseudo, ipsum)
	.rdempty	(cs_fifo_empty),	//26jul2018 kp, used to generate cs_fifo_empty	
	.rdfull		(),
	.rdusedw	(),
	.wrempty	(),
	.wrfull		(),
	.wrusedw	(ipcs_fifo_wrusedw)	//o-9
	);
	
				
	
tcore_rx_xgmii #(RX_DRAM_DEPTH, RX_DRAM_ADDR_WIDTH)	
	rx_xgmii(
	.clk156		(x_clk),		// i-1
	.clk250		(usr_clk),		// i-1
	.rst_		(usr_rst_),		// i-1
                                
	.TCORE_MODE	(TCORE_MODE	),	//i-1
	                                 
	.xaui_mode	(1'b1),			//i-1
		
	.pkt_data	(pkt_data),		//o-64
	.pkt_start	(pkt_start),	//o-1 
	.pkt_end	(pkt_end),		//o-1 
	.pkt_we		(pkt_we	),		//o-1 
	
	.drx_pkt_data		(drx_pkt_data  ),     	//o-64	
	.drx_pkt_start 		(drx_pkt_start ),     	//o-1	 
	.drx_pkt_end 		(drx_pkt_end   ),     	//o-1	 
	.drx_pkt_we 		(drx_pkt_we    ),     	//o-1	 
	.drx_pkt_beat_bcnt	(drx_pkt_beat_bcnt),  	//o-3	 
	.drx_pkt_be			(drx_pkt_be	 ),       	//o-8	 
	.drx_crc32 			(drx_crc32 	 ),       	//o-32	
	.drx_crc_vld 		(drx_crc_vld ),       	//o-1	 
	.drx_crc_err 		(drx_crc_err ),       	//o-1	 
	.drx_crc_err_dly1 	(drx_crc_err_dly1 ),  	//o-1	 
	
	.wen	(xgmir2ram_wen),			// o-1    
	.waddr	(xgmir2ram_waddr),			// o-param
	.wptr	(xgmir2derx_wptr),			// o-param
	.raddr_marker	(raddr_marker),		// i-param
	.wdata			(xgmir2ram_wdata),	// o-64   
	
	.rx_pause	(rx_pause),		   	// o-1                             
	.rx_pvalue	(rx_pvalue),		// o-16                            
	.rx_pack	(rx_pack),			// i-1                             
                                   	                                   
	.pause_en	(rx_xo_en),		   	// i-1                             
	.bcast_en	(bcast_en),		   	// i-1                             
	.pmode		(prom_mode),		// i-1, promiscuous mode enable bit
	.daddr0		(mac_addr0),		// i-48                            
	.mcast_en	(mcast_en),		   	// i-1                             
	.mcast_saddr(mcast_saddr),	   	// i-48                            
	                               	
	.rsize		(rx_size),			// i-12                           
	.rxp		(xgmii_rxp),   		// i-8, not used, always 0                           
	.rxd		(xgmii_rxd),		// i-64
	.rxc		(xgmii_rxc),		// i-8 
	                                       
	.br_sof4	(br_sof4),		
	
	//from Register
	.fmac_ctrl1_dly	(fmac_ctrl1_dly),	//i-32, contains the max_pkt_size and enable	
	.fmac_rxd_en	(fmac_rxd_en),		//i-1, from TSPE_CTRL1  reg                 
	
	// To Register
	.FMAC_DCNT_OVERRUN	(FMAC_DCNT_OVERRUN),		    // o-32
	.FMAC_DCNT_LINK_ERR	(FMAC_DCNT_LINK_ERR),	    	// o-32
	.FMAC_PKT_CNT_OVERSIZE	(FMAC_PKT_CNT_OVERSIZE),	// o-32
	.FIFO_OV_IPEND			(FIFO_OV_IPEND),			// o-1 
	
	//from DECAP unit (instead of passing the addr bus around)
	.clr_pkt_cnt_oversize(clr_pkt_cnt_oversize),    	//o-1
	
	//to DECAP unit for register tracking
	.add_lo_bcast	(add_lo_bcast),		  // o-1, these signals are 250Mhz pre-synced
	.add_lo_mcast	(add_lo_mcast),		  // o-1                                     
	.clr_carry_cast	(clr_carry_cast),	  // o-1 clr the carry of the B/Mcast group  
	.add_hi_cast	(add_hi_cast),		  // o-1 add the HI reg of the B/Mcast group 
	
    .vlan_ip		(		),	          //o-1                                 
    .normal_ip		(	  	),	          //o-1                                 
    .non_ip			(		    ),	      //o-1                                 
    .pkt_reject		(	),		          //o-1, EXTR use to drop the pkt at end
    .pkt_jumbo_flag	(	),		          //o-1    (not used)                   
    .pkt_ipver		(	  	),	          //o-4    (not used)                   
    
    .wr_nbyte		(wr_nbyte	),        //o-1               
    .nbytes_out		(nbytes		),        //o-16, pkt byte cnt
    .rxfifo_full	(rxfifo_full),        //i-1               
    
    .chk_crc		(chk_crc),
    
    .crc32_ok		(crc32_ok),
    .fmac_rx_clr_en	(fmac_rx_clr_en)
	
	);	
	
	
	
rx_decap #(FMAC_ID, RX_FIFO_DEPTH, RX_FIFO_ADDR_WIDTH, RX_DRAM_DEPTH, RX_DRAM_ADDR_WIDTH) 
	rx_decap(
	.clk250		(usr_clk),				// i-1
	.clk156		(x_clk),				// i-1
	.rst_		(usr_rst_),				// i-1
	
	//output to pre-parser FIFO  for EXTR & filter				
	.full		(rxfifo_full),			// i-1				
	.usedw		(rxfifo_usedw),			// i-param 12
			
	.rx_check_crc		(rx_check_crc),		// i-1	From Register		
	.fmac_ctrl1_dly 	(fmac_ctrl1_dly),	//i-32 from reg
	.fmac_rxd_en		(fmac_rxd_en),		//i-1

	// To fmac_register_if
	.FMAC_RX_CRC_ERR_CNT		(FMAC_RX_CRC_ERR_CNT),			// o-32
	.FMAC_RX_UNDERSIZE_PKT_CNT	(FMAC_RX_UNDERSIZE_PKT_CNT),	// o-32
	.FMAC_RX_PKT_CNT_LO			(FMAC_RX_PKT_CNT_LO),			// o-32
	.FMAC_RX_PKT_CNT_HI			(FMAC_RX_PKT_CNT_HI),			// o-32
	.FMAC_RX_BYTE_CNT_LO		(FMAC_RX_BYTE_CNT_LO),			// o-32
	.FMAC_RX_BYTE_CNT_HI		(FMAC_RX_BYTE_CNT_HI),			// o-32
	
	.FMAC_PKT_CNT_JABBER(FMAC_PKT_CNT_JABBER),			// o-32
	.FMAC_PKT_CNT_FRAGMENT(FMAC_PKT_CNT_FRAGMENT),		// o-32
	
	//Interface to 64 bit Statistic register group, in DECAP
	.STAT_GROUP_LO_DOUT	(STAT_GROUP_LO_DOUT),			// o-32, clk250
	.STAT_GROUP_HI_DOUT	(STAT_GROUP_HI_DOUT),			// o-32, clk250
	.STAT_GROUP_addr	(STAT_GROUP_addr),				// i-10, address to select the register within the STAT GROUP
	.STAT_GROUP_sel		(STAT_GROUP_sel),				// i-1
	.fmac_rx_clr_en		(fmac_rx_clr_en),				//i-1
	
	.wptr				(xgmir2derx_wptr),	 			// i-param 13bit, from XGMII 156MHz signal           
	.rdata				(ram2derx_rdata),             	// i-64, from dual RAM buffer to DECAP, 250MHz
	
	//to RX_XGMII
	.clr_pkt_cnt_oversize	(clr_pkt_cnt_oversize),		//o-1
	
		//to RX_XGMII unit for register tracking
	.add_lo_bcast		(add_lo_bcast),		// i-1, these signals are 250Mhz pre-synced
	.add_lo_mcast		(add_lo_mcast),		// i-1                                     	
	.clr_carry_cast		(clr_carry_cast),	// i-1 clr the carry of the B/Mcast group	
	.add_hi_cast		(add_hi_cast),		// i-1 add the HI reg of the B/Mcast group  	
	
	// Interface to tx_encap
	.tx_xo_en			(tx_xo_en),			// i-1 From Register
	.xdone				(xdone),			// i-1		
	
						
		
	.FMAC_RX_PKT_CNT64_LO(FMAC_RX_PKT_CNT64_LO),
	.FMAC_RX_PKT_CNT64_HI(FMAC_RX_PKT_CNT64_HI),
	
	.FMAC_RX_PKT_CNT127_LO(FMAC_RX_PKT_CNT127_LO),
	.FMAC_RX_PKT_CNT127_HI(FMAC_RX_PKT_CNT127_HI),
	
	.FMAC_RX_PKT_CNT255_LO(FMAC_RX_PKT_CNT255_LO),
	.FMAC_RX_PKT_CNT255_HI(FMAC_RX_PKT_CNT255_HI),
	
	.FMAC_RX_PKT_CNT511_LO(FMAC_RX_PKT_CNT511_LO),
	.FMAC_RX_PKT_CNT511_HI(FMAC_RX_PKT_CNT511_HI),
	
	.FMAC_RX_PKT_CNT1023_LO(FMAC_RX_PKT_CNT1023_LO),
	.FMAC_RX_PKT_CNT1023_HI(FMAC_RX_PKT_CNT1023_HI),
	
	.FMAC_RX_PKT_CNT1518_LO(FMAC_RX_PKT_CNT1518_LO),
	.FMAC_RX_PKT_CNT1518_HI(FMAC_RX_PKT_CNT1518_HI),
	
	.FMAC_RX_PKT_CNT2047_LO(FMAC_RX_PKT_CNT2047_LO),
	.FMAC_RX_PKT_CNT2047_HI(FMAC_RX_PKT_CNT2047_HI),
	
	.FMAC_RX_PKT_CNT4095_LO(FMAC_RX_PKT_CNT4095_LO),
	.FMAC_RX_PKT_CNT4095_HI(FMAC_RX_PKT_CNT4095_HI),
	
	.FMAC_RX_PKT_CNT8191_LO(FMAC_RX_PKT_CNT8191_LO),
	.FMAC_RX_PKT_CNT8191_HI(FMAC_RX_PKT_CNT8191_HI),
	
	.FMAC_RX_PKT_CNT9018_LO(FMAC_RX_PKT_CNT9018_LO),
	.FMAC_RX_PKT_CNT9018_HI(FMAC_RX_PKT_CNT9018_HI),
	
	.FMAC_RX_PKT_CNT9022_LO(FMAC_RX_PKT_CNT9022_LO),
	.FMAC_RX_PKT_CNT9022_HI(FMAC_RX_PKT_CNT9022_HI),
	
	.FMAC_RX_PKT_CNT9199P_LO(FMAC_RX_PKT_CNT9199P_LO),
	.FMAC_RX_PKT_CNT9199P_HI(FMAC_RX_PKT_CNT9199P_HI),
	.nbyte 			(nbytes),
	.pkt_done		(wr_nbyte),
					
	.crc_chk		(chk_crc),
	.crc32			(drx_crc32),
	.crc32_vld_		(drx_crc_vld),
	
	.crc_ok 		(crc32_ok)
	
	);	

	
	
	
	
reg		[63:0]	xgmii_dout_reg;
reg		[7:0]	xgmii_cout_reg;
reg		[31:0]	FMAC_TX_PKT_CNT;
reg		[31:0]	FMAC_TX_BYTE_CNT;

always @(posedge x_clk)
begin
	if (!usr_rst_)
		begin
		FMAC_TX_PKT_CNT 		<= 32'h0;
		FMAC_TX_BYTE_CNT 		<= 32'h0;
		xgmii_dout_reg		<= 64'h0707070707070707;
		xgmii_cout_reg		<= 8'hFF;
		end
	else
		begin
		FMAC_TX_PKT_CNT <= mode_1G? PRE_FMAC_TX_PKT_CNT_1G : PRE_FMAC_TX_PKT_CNT_10G;
		FMAC_TX_BYTE_CNT <= mode_1G? PRE_FMAC_TX_BYTE_CNT_1G : PRE_FMAC_TX_BYTE_CNT_10G;
		
		xgmii_dout_reg[63:8] <= mode_1G? 56'h07070707070707 : pre_xgmii_txd[63:8];
		xgmii_dout_reg[7:0]	 <= mode_1G? pre_gmii_txd : pre_xgmii_txd[7:0];
		
		xgmii_cout_reg[7:1]	<=	mode_1G? 7'b1111111 : pre_xgmii_txc[7:1];
		xgmii_cout_reg[0]	<=	mode_1G? pre_gmii_txc : pre_xgmii_txc[0];	
		end
end		

assign xgmii_txd 	= xgmii_dout_reg;
assign xgmii_txc 	= xgmii_cout_reg;

	
	
	
endmodule