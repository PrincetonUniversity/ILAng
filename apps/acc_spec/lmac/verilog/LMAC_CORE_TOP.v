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