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