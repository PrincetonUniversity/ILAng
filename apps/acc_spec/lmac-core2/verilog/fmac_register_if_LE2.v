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
	clk,     				// i-1, 250MHz	
    reset_,  				// i-1	
     
    fmac_ctrl_dly,				//i-32
    FMAC_TX_PKT_CNT,  			//i-32
    FMAC_RX_PKT_CNT_LO,      	// i-32, clk250 (derived from SYNCLK125 [or FMAC0 clk])
    FMAC_RX_PKT_CNT_HI,      	// i-32, clk250 (derived from SYNCLK125 [or FMAC0 clk])

    FMAC_TX_BYTE_CNT,			// i-32
	FMAC_RX_BYTE_CNT_LO,   		// i-32, clk250 (from synclk)
	FMAC_RX_BYTE_CNT_HI,   		// i-32, clk250 (from synclk)

	FMAC_RX_UNDERSIZE_PKT_CNT,		// i-32
	FMAC_RX_CRC_ERR_CNT,			// i-32
	FMAC_DCNT_OVERRUN,				// i-32
	FMAC_DCNT_LINK_ERR,				// i-32
	FMAC_PKT_CNT_OVERSIZE,			// i-32
	FMAC_PHY_STAT,					// i-32
	fmac_ctrl1	,					// i-32
	
	FMAC_PKT_CNT_JABBER		,		// i-32
	FMAC_PKT_CNT_FRAGMENT	,		// i-32
	FMAC_RAW_FRAME_CNT	,			// i-32
	FMAC_BAD_FRAMESOF_CNT	,		// i-32
	
	STAT_GROUP_LO_DOUT	,			// i-32, clk250
	STAT_GROUP_HI_DOUT	,			// i-32, clk250
	STAT_GROUP_addr	,				// o-10, address to select the register within the STAT GROUP
	STAT_GROUP_sel	,				//o-1
	fmac_rx_clr_en,					//o-1
	
	fmac_tx_clr_en,					//o-1
	reg_rd_start,					// i-1, pulse indicating the start of a reg access
	reg_rd_done,					// i-1, pulse indicating the end of a reg access
	host_addr_reg,					// i-16
	SYS_ADDR,						// i-4
	
	rx_auto_clr_en,					//i-1
	tx_auto_clr_en,					//i-1
	
	
	FMAC_RX_PKT_CNT64_LO,   		// i-33
	FMAC_RX_PKT_CNT64_HI,   		// i-32
	                       
	FMAC_RX_PKT_CNT127_LO,  		// i-33
	FMAC_RX_PKT_CNT127_HI,  		// i-32
	                       
	FMAC_RX_PKT_CNT255_LO,  		// i-33
	FMAC_RX_PKT_CNT255_HI,  		// i-32
	                       
	FMAC_RX_PKT_CNT511_LO,  		// i-33
	FMAC_RX_PKT_CNT511_HI,  		// i-32
	                       
	FMAC_RX_PKT_CNT1023_LO, 		// i-33
	FMAC_RX_PKT_CNT1023_HI, 		 // i-32
	                       
	FMAC_RX_PKT_CNT1518_LO, 		 // i-33
	FMAC_RX_PKT_CNT1518_HI, 		 // i-32
	                       
	FMAC_RX_PKT_CNT2047_LO, 		 // i-33
	FMAC_RX_PKT_CNT2047_HI, 		 // i-32
	                       
	FMAC_RX_PKT_CNT4095_LO, 		 // i-33
	FMAC_RX_PKT_CNT4095_HI, 		 // i-32
	                       
	FMAC_RX_PKT_CNT8191_LO, 		 // i-33
	FMAC_RX_PKT_CNT8191_HI, 		 // i-32
	                       
	FMAC_RX_PKT_CNT9018_LO, 		  // i-33
	FMAC_RX_PKT_CNT9018_HI, 		  // i-32
	                       
	FMAC_RX_PKT_CNT9022_LO, 		  // i-33
	FMAC_RX_PKT_CNT9022_HI, 		  // i-32
	                       
	FMAC_RX_PKT_CNT9199P_LO,		   // i-33
	FMAC_RX_PKT_CNT9199P_HI,		   // i-32
		
	
	FMAC_REGDOUT					   // o-32
	
    );
      

input       clk;
input       reset_;

// Statistic Registers
input	[31:0]	fmac_ctrl_dly	;
input [31:0]	FMAC_TX_PKT_CNT;
input [31:0]	FMAC_RX_PKT_CNT_LO;
input [31:0]	FMAC_RX_PKT_CNT_HI;

input [31:0]	FMAC_TX_BYTE_CNT;
input [31:0]	FMAC_RX_BYTE_CNT_LO;
input [31:0]	FMAC_RX_BYTE_CNT_HI;

input [31:0]	FMAC_RX_UNDERSIZE_PKT_CNT;
input [31:0]	FMAC_RX_CRC_ERR_CNT;
input [31:0]	FMAC_DCNT_OVERRUN;
input [31:0]	FMAC_DCNT_LINK_ERR;
input [31:0]	FMAC_PKT_CNT_OVERSIZE;
input [31:0]	FMAC_PHY_STAT;
input	[31:0]	fmac_ctrl1	;

input	[31:0]	FMAC_PKT_CNT_JABBER		;		  //i-32
input	[31:0]	FMAC_PKT_CNT_FRAGMENT	;		   //i-32
input	[31:0]	FMAC_RAW_FRAME_CNT	;			   //i-32
input	[31:0]	FMAC_BAD_FRAMESOF_CNT	;		   //i-32
	
input	[31:0]	STAT_GROUP_LO_DOUT	;			// i-32, clk250
input	[31:0]	STAT_GROUP_HI_DOUT	;			// i-32, clk250
output	[9:0]	STAT_GROUP_addr	;				// o-10, address to select the register within the STAT GROUP
output			STAT_GROUP_sel	;				// o-1,
output			fmac_rx_clr_en	;				// o-1,
	
output			fmac_tx_clr_en	;				 // o-1,
input			reg_rd_start;
input			reg_rd_done;
input [15:0]	host_addr_reg;
input [3:0]		SYS_ADDR;

input			rx_auto_clr_en;
input			tx_auto_clr_en;


input	[32:0]		FMAC_RX_PKT_CNT64_LO;
input	[31:0]		FMAC_RX_PKT_CNT64_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT127_LO;
input	[31:0]		FMAC_RX_PKT_CNT127_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT255_LO;
input	[31:0]		FMAC_RX_PKT_CNT255_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT511_LO;
input	[31:0]		FMAC_RX_PKT_CNT511_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT1023_LO;
input	[31:0]		FMAC_RX_PKT_CNT1023_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT1518_LO;
input	[31:0]		FMAC_RX_PKT_CNT1518_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT2047_LO;
input	[31:0]		FMAC_RX_PKT_CNT2047_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT4095_LO;
input	[31:0]		FMAC_RX_PKT_CNT4095_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT8191_LO;
input	[31:0]		FMAC_RX_PKT_CNT8191_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT9018_LO;
input	[31:0]		FMAC_RX_PKT_CNT9018_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT9022_LO;
input	[31:0]		FMAC_RX_PKT_CNT9022_HI;
     	      		
input	[32:0]		FMAC_RX_PKT_CNT9199P_LO;
input	[31:0]		FMAC_RX_PKT_CNT9199P_HI;


output [31:0]	FMAC_REGDOUT;


wire	atomic_cycle_mode;
reg		atm_latch_en;
reg		atm_latch_en_dly;
reg		[31:0]	local32_hi;		 //keeping the upper 32 bit of the 64 bit reg
reg		[31:0]	my_local32_hi;	 //temp mux
reg		[8:0]	atm_tag;		 //keeping the addr of the previous reg read for checking matching
reg				atm_valid;
wire			tag_match;

reg		reg_rd_start_int;
reg		reg_rd_done_int;
reg		atomic_hi_en;					  //enable the access to the ATOMIC HI register

reg	[31:0]	FMAC_RAW_FRAME_CNT_DLY1	;		  //i-32
reg	[31:0]	FMAC_BAD_FRAMESOF_CNT_DLY1	;	  //i-32

reg [8:0]	addr_buf0;
reg [9:0]	STAT_GROUP_addr;		//only bit 9:3 are used, for used by the new statistic regs
reg			upper32_addr;

reg			STAT_GROUP_sel;
reg			fmac_rx_clr_en;
reg			fmac_tx_clr_en;

reg	[3:0]	host_addr_int;				//only upper nibble of the host addr

reg			high_sel;
always @ (posedge clk)
	begin
	addr_buf0	 <=	host_addr_reg[11:3];
	
	upper32_addr	<= host_addr_reg[2];
	
   //keeping the bit numbering the same as the address
	host_addr_int		<= host_addr_reg[15:12];
	
	STAT_GROUP_addr	 	<= {host_addr_reg[9:3], 3'b000} ;
	
	STAT_GROUP_sel		<= host_addr_reg[11];
	
	fmac_rx_clr_en			<= 
		!reset_ ? 1'b0 :
		(host_addr_int == SYS_ADDR) & reg_rd_done_int & rx_auto_clr_en ;
		
	fmac_tx_clr_en			<= 
		!reset_ ? 1'b0 :
		(host_addr_int == SYS_ADDR) & reg_rd_done_int & tx_auto_clr_en ;

	high_sel				<=
		host_addr_reg[2] | host_addr_reg[1];
	end
	

parameter	[9:0]	FMAC_CTRL_addr							= 	10'h0_00;
parameter	[9:0]	FMAC_TX_PKT_CNT_addr					= 	10'h0_20;
parameter 	[9:0]	FMAC_RX_PKT_CNT_addr					= 	10'h0_28;	  // - RX_PKT_CNT_LO
parameter	[9:0]	FMAC_TX_BYTE_CNT_addr					= 	10'h0_30;	  // - RX_PKT_CNT_LO
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

// Decode address to Select lines 

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

reg		[31:0]	REGU_GROUP_HI_DOUT;
always@ (posedge clk)
	begin
		if (!reset_) begin
			REGU_GROUP_HI_DOUT		<=		0;
		end
		else begin
			case (host_addr_reg)
				16'h102C	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT_HI;
				16'h103C	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_BYTE_CNT_HI;
				16'h1804	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT64_HI;
				16'h180C	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT127_HI;
				16'h1814	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT255_HI;
				16'h181C	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT511_HI;
				16'h1824	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT1023_HI;
				16'h182C	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT1518_HI;
				16'h1834	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT2047_HI;
				16'h183C	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT4095_HI;
				16'h1844	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT8191_HI;
				16'h184C	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT9018_HI;
				16'h1854	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT9022_HI;
				16'h185C	:	REGU_GROUP_HI_DOUT		<=		FMAC_RX_PKT_CNT9199P_HI;		 
				default		:	REGU_GROUP_HI_DOUT		<= 		0;
			endcase
		end
	end
reg [31:0]	FMAC_REGDOUT;


always@(posedge clk)
begin
							
	FMAC_REGDOUT	<=		high_sel	?
							REGU_GROUP_HI_DOUT		:
							{32{ !STAT_GROUP_sel & !upper32_addr	}} & 		REGU_GROUP_LO_DOUT	|
							{32{  STAT_GROUP_sel & !upper32_addr	}} & 		STAT_GROUP_LO_DOUT	|
							{32{ atomic_hi_en }} & local32_hi
							;
										
end


// ATOMIC CONTROLLER - Enforce ATOMICITY for 64 bit reg reads
assign		atomic_cycle_mode = 
							( !STAT_GROUP_sel & DLY_FMAC_RX_PKT_CNT_sel 	& !upper32_addr )
						|	( !STAT_GROUP_sel & DLY_FMAC_RX_BYTE_CNT_sel 	& !upper32_addr )
						|	(  STAT_GROUP_sel 		& !upper32_addr )
						
						;

 	//HI access cycle
assign	tag_match	= (addr_buf0 == atm_tag);


always@(posedge clk)	
	if (!reset_)
		begin
		reg_rd_start_int	<= 1'b0;
		reg_rd_done_int	<= 1'b0;
		end
	else
		begin
		reg_rd_start_int	<= reg_rd_start;		//reg_rd_start and done are from MAC_REG module
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
			atm_latch_en_dly & atomic_cycle_mode ? 1'b1 : 1'b0;
			
		1'b1:
		atm_valid	<=
			(reg_rd_done & tag_match & upper32_addr) ? 1'b0 : 1'b1;
			
		endcase

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
	atm_latch_en		<= reg_rd_start_int & atomic_cycle_mode;				//enable latching if it's atomic access start
	atm_latch_en_dly	<= atm_latch_en;										//delay to wait for address propagation
	local32_hi			<= atm_latch_en_dly ? my_local32_hi : local32_hi;
	atm_tag				<= atm_latch_en_dly ? addr_buf0 : atm_tag;
				
	my_local32_hi			<=
	                        	{32{ !STAT_GROUP_sel & DLY_FMAC_RX_PKT_CNT_sel	}} &	FMAC_RX_PKT_CNT_HI		
							|	{32{ !STAT_GROUP_sel & DLY_FMAC_RX_BYTE_CNT_sel	}} &	FMAC_RX_BYTE_CNT_HI		
							|	{32{  STAT_GROUP_sel			}} & 	STAT_GROUP_HI_DOUT
							
									;
	
	atomic_hi_en	<=
			atomic_hi_en & reg_rd_done ? 1'b0 :
			atm_valid & tag_match & upper32_addr ? 1'b1 :
			atomic_hi_en
			;
	end
			
end



endmodule