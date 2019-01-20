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
	rst_,  			// i-1
	
	// Interface to tx_encap
	rts,    		  // i-1
	rdata,  		  // i-64
	rbytes,			  // i-16
	cts,			  // o-1
	
	gmii_txd,		  // o-8
	gmii_txc,		  // o-1
	gmii_tx_en,		  // o-1
	gmii_tx_vld,	  // o-1
	
	FMAC_TX_PKT_CNT,  	  // o-32
	FMAC_TX_BYTE_CNT,	  // o-32
	fmac_tx_clr_en		  // i-1
	
	);

	
input clk250;			// i-1
input clk125;			// i-1
input rst_;				// i-1

input   rts;			 // i-1, request to send from tx_encap
input   [63:0] rdata;	 // i-64 , data input
input   [15:0] rbytes;	 // i-16, data size from encap
output	cts;

output [7:0] gmii_txd;			//o-8, 1 byte data output
output 		 gmii_txc;			//o, control output
output 		 gmii_tx_en;
output 		 gmii_tx_vld;

output [31:0] FMAC_TX_PKT_CNT;
output [31:0] FMAC_TX_BYTE_CNT;
input		  fmac_tx_clr_en;
	
reg	   [63:0] pdin;			// use this with gige_crc32x64 to support giving data that are not consec clk
reg    [63:0] bdata1;		// buffer input data 
reg    [63:0] bdata2;
reg    [15:0] wcnt;

wire	[15:0] nbytes;
reg  	[15:0] nbytes_reg;
reg 	[15:0] rbytes_reg;  //holds number of bytes in data

reg    [63:0] txd;			//o-64, data output
reg    [07:0] txc;			//o-8, control output
reg    [07:0] txc_int;

reg    IDLE_sel;
reg    insert_crc;			// a pulse to indicate when to insert crc frame. 

reg    crc_we_;
reg    crc_last_;
reg    crc_clr_;
reg    [15:0] crc_cnt;
wire   [31:0] crc32;	   //crc output

reg		sent;
reg		sent_dly;
reg		statistic_ok;
reg		[31:0]   pkt_transmitted;
reg		[31:0]   FMAC_TX_PKT_CNT;
reg 	[31:0]   accumulated_bcnt;
reg		[31:0]   FMAC_TX_BYTE_CNT;


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

wire st_DAT_4;
wire st_DAT_6;
reg  last_dat;

reg	[15:0] 	bcnt;


assign nbytes = {(rbytes[15:3] + |rbytes[2:0]),3'b000};


//   BUFFER
always@(posedge clk125)
begin
	bdata1 <=   rdata;
	
	pdin  <= (!rst_)? 64'h0 :  
	       (crc_we_? pdin : rdata);  
	          
	bdata2 <=   bdata1;
	nbytes_reg <= nbytes;
	rbytes_reg <= rbytes;
	
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
		sent	<=	st_TX_CRC & st_DAT_4;
		sent_dly <= sent;
	end
end

always@ (posedge clk125)
begin
	if (!rst_ | fmac_tx_clr_en)
		pkt_transmitted	<=	32'h0;
	else
		pkt_transmitted	<=	(sent)? (pkt_transmitted + 32'h1) : pkt_transmitted ;
end

always @ (posedge clk250)
begin
	if (!rst_)
		statistic_ok <= 1'b0;
	else
		statistic_ok <= sent_dly;
		
end

always @ (posedge clk250)
begin
	if (!rst_ | fmac_tx_clr_en)
		FMAC_TX_PKT_CNT <= 32'h0;
		
	else
		FMAC_TX_PKT_CNT <= statistic_ok? pkt_transmitted : FMAC_TX_PKT_CNT ;
		 // Make sure capture pkt_transmitted when its value is stable
end


 //   FMAC_TX_BYTE_CNT REGISTER with auto clear
always@ (posedge clk125)
begin
	if (!rst_ | fmac_tx_clr_en)
		accumulated_bcnt	<=	32'h0;
	else
		accumulated_bcnt	<=	(sent)? (accumulated_bcnt + rbytes_reg) : accumulated_bcnt ;
end

always @ (posedge clk250)
begin
	if (!rst_ | fmac_tx_clr_en)
		FMAC_TX_BYTE_CNT <= 32'h0;
		
	else
		FMAC_TX_BYTE_CNT <= statistic_ok? accumulated_bcnt : FMAC_TX_BYTE_CNT ;
end


 //  STATE MACHINE
always@(posedge clk125)
if(!rst_)
begin
	state <=   IDLE;
	txd   <=   64'hf7f7f7f7f7f7f7f7; 	// IDLE for gmii interface (normal inter-frame)
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
	// insert crc frame depending upon the number of data bytes valid in last qwd.	
	if (insert_crc)
			begin 
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
		begin
		if (wcnt[15]& st_TX_DAT)
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
		// if not last data 
		else txd <=   st_TX_DAT? {bdata2[63:0]}: txd;
		end
	
	txc  <=   txc_int;
	 // pulse to indicate, when to transmit crc frame
	insert_crc <=   (st_DAT_6 && last_dat);

	crc_we_    <=   !(st_DAT_4 && !crc_cnt[15]); 
	crc_last_  <=   !(st_DAT_4 && !crc_cnt[15] && wcnt[15]);
	
	crc_cnt    <=   st_GET_WAIT1 ? (rbytes + 16'd7) : (st_TX_DAT? (crc_cnt - 16'd8) : crc_cnt); 
	crc_clr_   <=   !(st_IDLE || st_TX_CRC);
// state machine	
	case(state)
	IDLE:
	begin
		state <= rts? GET_WAIT1: IDLE;
	end

	GET_WAIT1:
	begin
		state <=   GET_WAIT2;
	end

	GET_WAIT2:
	begin
		state   <=   TX_DAT;  
		wcnt    <=   nbytes_reg - 16'd1;
		txc_int <=   8'h01;
		IDLE_sel<=   0;
	end
	
	TX_DAT:
	begin
		state  <=	WAIT_S;
		wcnt   <=   wcnt - 16'd8;
		last_dat <= wcnt[15];
	end
	
	WAIT_S:
	begin
		state <= st_DAT_6? (last_dat? TX_CRC : TX_DAT) : WAIT_S;
		// if last data, sent the control depending on the valid bytes in last qwd.
		if (st_DAT_6 )
		begin
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
			begin	 //if not last data, adjust control according to the number of bytes valid.
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
			else txc_int <= 8'h00;	   // if not last data 
			end
		end
		
		else
			txc_int <=   txc_int; 
	end
//CRC state	
	TX_CRC:
	begin
		state <=   st_DAT_4? (rts? GET_WAIT1: IDLE) : TX_CRC ;
		last_dat <= 1'b0;
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
reg [8:0] gstate ;	

wire 	st_DAT_I	= gstate[0];
assign 	st_DAT_4 	= gstate[5];
assign 	st_DAT_6 	= gstate[7];

reg [7:0] gmii_txd;
reg 	  gmii_txc;
reg		  gmii_tx_en;
reg		  gmii_tx_vld;

reg		  cts;
reg		  gmii_start;
reg [7:0] idle1, idle2, idle3, idle4;

// Control for FSM
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
		cts <= st_DAT_I & (idle3 == 8'h50);
		gmii_start <= st_GET_WAIT2 | (st_DAT_6 & st_WAIT_S);
		
		idle1 <= st_DAT_I? idle2 : 8'hBC;
		idle2 <= st_DAT_I? idle3 : 8'hC5;
		idle3 <= st_DAT_I? idle4 : 8'hBC;
		idle4 <= st_DAT_I? idle1 : 8'h50;
		
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
end

else
begin


	gmii_tx_en	<=	(gstate == DAT_I)?	1'b0	:
						(bcnt	==	16'd0)?	1'b0	:	1'b1;
	
	gmii_tx_vld	<=	((bcnt	==	16'd1)|(bcnt	==	16'd0))?	1'b1	:	(!gmii_tx_en);

	
	case(gstate)
	DAT_I:	   // Transmit Idle Set
	begin
		gstate <= gmii_start? DAT_0 : DAT_I;
		gmii_txd <= idle1;
		gmii_txc <= (idle1 == 8'hbc);
		gmii_tx_en	<=	1'b0; 
		gmii_tx_vld	<=	1'b1; 
	
		bcnt		<=	rbytes + 16'd13; 

	end
	
	DAT_0:	   // Transmit Byte 0
	begin
		gstate <= DAT_1;
		gmii_txd <= txd[7:0];
		gmii_txc <= txc[0];

		bcnt	<=	(bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1);
		
	end
	
	DAT_1:		 // Transmit Byte 1
	begin
		gstate <= DAT_2;
		gmii_txd <= txd[15:8];
		gmii_txc <= txc[1];

		bcnt	<=	(bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1);

	end
	
	DAT_2:		  // Transmit Byte 2
	begin
		gstate <= DAT_3;
		gmii_txd <= txd[23:16];
		gmii_txc <= txc[2];

		bcnt	<=	(bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1);

	end
	
	DAT_3:			  // Transmit Byte 3
	begin
		gstate <= DAT_4;
		gmii_txd <= txd[31:24];
		gmii_txc <= txc[3];

		bcnt	<=	(bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1);

	end
	
	DAT_4:				 // Transmit Byte 4
	begin
		gstate <= DAT_5;
		gmii_txd <= txd[39:32];
		gmii_txc <= txc[4];

		bcnt	<=	(bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1);

	end
	
	DAT_5:			   // Transmit Byte 5
	begin
		gstate <= DAT_6;
		gmii_txd <= txd[47:40];
		gmii_txc <= txc[5];

		bcnt	<=	(bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1);

	end
	
	DAT_6:			 // Transmit Byte 6
	begin
		gstate <= DAT_7;
		gmii_txd <= txd[55:48];
		gmii_txc <= txc[6];

		bcnt	<=	(bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1);

	end
	
	DAT_7:				  // Transmit Byte 7
	begin
		gstate <= (gmii_start)? DAT_0 : DAT_I;
		gmii_txd <= txd[63:56];
		gmii_txc <= txc[7];

		bcnt	<=	(bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1);

	end
	
	default:
	begin
		gstate <=  DAT_I;
	end
	endcase
end


gige_crc32x64 gige_crc32x64(
   	.clk(clk125),					//i,
   	.rst_(rst_),					//i,
   	
   	.bytes  (rbytes_reg[2:0]), 		//i, number of bytes valid in last qwd
   	.clr_  (crc_clr_),
   	.we_   (crc_we_),
   	.last_ (crc_last_),
   	.cdin  (rdata),				   //i, input data
   	.pdin  (pdin),	
   	
   	.crc32({crc32[7:0],crc32[15:8],crc32[23:16],crc32[31:24]}),
   	.crc32_vld_()				   
    );
   
   
//synopsys translate_off
reg [(32 *8)-1:0] ascii_state, ascii_gstate;
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