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

module tx_xgmii(
	clk250,			// i-1
	clk156,			 // i-1, this really is coreclkout (can be 156 or 125MHz)
	rst_,  			 	// i-1
	
	mode_10G ,			//i-1, speed modes
	mode_5G  ,	
	mode_2p5G,	
	mode_1G  ,	
	
	xaui_mode,
	
	rts,    		   // i-1
	rdata,  		   // i-64
	rbytes,			  // i-16
	cts,			  //o-1, enable ENCAP to read the next QWD (NOT USED, keep for I/O compatibility)
	
	txd,			  // o-64
	txc,			  // o-8
	
	FMAC_TX_PKT_CNT,  	   // o-32
	FMAC_TX_BYTE_CNT,	   // o-32
	fmac_tx_clr_en		   // i-1
	
	);

	

input clk250;
input clk156;		 // 156.25 Mhz
input rst_;
//speed modes
input	mode_10G ;
input	mode_5G  ;
input	mode_2p5G;
input	mode_1G  ;
        
input	xaui_mode	;

input   rts;			  //request to send from encap
input  [63:0] rdata;	  // data input
input   [15:0] rbytes;	   //holds the size of data in Bytes

output	cts;		 wire  cts = 1'b0 ; 	//not used tie low

output [63:0] txd;		 //o, data ouput
output [07:0] txc;		 //o, control output

output [31:0] FMAC_TX_PKT_CNT;
output [31:0] FMAC_TX_BYTE_CNT;
input		  fmac_tx_clr_en;
	

reg    [63:0] bdata1;			  // buffer input data
reg    [63:0] bdata2;
reg    [15:0] wcnt;

wire	[15:0] nbytes;
reg  	[15:0] nbytes_reg;
reg 	[15:0] rbytes_reg;

reg    [63:0] txd;				  //output data
reg    [07:0] txc;				  // control output
reg    [07:0] txc_int;

reg    IDLE_sel;
reg    insert_crc;					// indicates when to transmit CRC frame

reg    crc_we_;
reg    crc_last_;
reg    crc_clr_;
reg    [15:0] crc_cnt;
wire   [31:0] crc32;			   // CRC output

reg		sent;
reg		sent_dly;

reg		[31:0]   pkt_transmitted;
reg		[31:0]   FMAC_TX_PKT_CNT;
reg 	[31:0]   accumulated_bcnt;
reg		[31:0]   FMAC_TX_BYTE_CNT;

reg [2:0] counter;
reg pulse_0;
reg pulse_1;


parameter[4:0] 
    IDLE		= 5'h01 ,
	GET_WAIT1   = 5'h02 ,
	GET_WAIT2   = 5'h04 ,
	TX_DAT		= 5'h08 ,
	TX_CRC		= 5'h10 ;
reg    [4:0] state;

wire st_IDLE;			assign	st_IDLE			=	state[0];
wire st_GET_WAIT1;  	assign	st_GET_WAIT1	=	state[1];
wire st_GET_WAIT2;  	assign	st_GET_WAIT2	=	state[2];
wire st_TX_DAT;     	assign	st_TX_DAT		=	state[3];
wire st_TX_CRC;        	assign	st_TX_CRC		=	state[4];

assign nbytes = {(rbytes[15:3] + |rbytes[2:0]),3'b000};


//   BUFFER
always@(posedge clk156)
begin
	bdata1 <=   (!rst_)? 64'hD5555555555555FB :
						mode_10G? rdata:
						(pulse_0 ? rdata :bdata1);
	bdata2 <=   (!rst_)? 64'hD5555555555555FB :
						mode_10G? bdata1:
						(pulse_0 ? bdata1 : bdata2);
	nbytes_reg <= (!rst_)? 16'b0 : 
				  mode_10G? nbytes :
	              (pulse_0? nbytes : nbytes_reg);
	rbytes_reg <= (!rst_)?16'b0:
				  mode_10G? rbytes:
				  (pulse_0? rbytes: rbytes_reg);
end


//   FMAC_TX_PKT_CNT REGISTER

always@ (posedge clk156)
begin
	if (!rst_)
	begin
		sent	<=	1'b0;
		sent_dly <= 1'b0;
	end
	
	else
	begin
		sent	<=	mode_10G ? st_TX_CRC:
					pulse_1 ? st_TX_CRC : 1'b0;
		sent_dly <= sent;
	end
end

always@ (posedge clk156)
begin
	if (!rst_ | fmac_tx_clr_en)
		pkt_transmitted	<=	32'h0;
	else
		pkt_transmitted	<=	(sent)? (pkt_transmitted + 32'h1) : pkt_transmitted ;
end

reg		capture_en0_clk250;
reg		capture_en1_clk250;

//detect the capture en for clk250 (if see 2 zeroes in a row)
wire	capture_en_clk250 = capture_en0_clk250 & capture_en1_clk250;

always @ (posedge clk250)
	begin
	
	capture_en0_clk250	<= !sent;
	capture_en1_clk250	<=  capture_en0_clk250;
	
	if ( !rst_  | fmac_tx_clr_en)
		FMAC_TX_PKT_CNT <= 32'h0;
	else
		FMAC_TX_PKT_CNT	<= (capture_en_clk250) ? pkt_transmitted : FMAC_TX_PKT_CNT;
	
	end


always@ (posedge clk156)
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
		FMAC_TX_BYTE_CNT <= capture_en_clk250? accumulated_bcnt : FMAC_TX_BYTE_CNT ;
end


//  STATE MACHINE
always@(posedge clk156)
if(!rst_)
begin
	state <=   IDLE;
	txd   <=   64'h0707070707070707;  // IDLE for xgmii interface (normal inter-frame)
	txc   <=   8'hff; 

	txc_int <=   8'hff;
	IDLE_sel  <=   1;
	insert_crc<=   0;

	wcnt <=   0;
	
	crc_we_ <=   1;
	crc_last_<=   1;
	crc_cnt  <=   0;
	crc_clr_ <=   1;
	
    counter <= (mode_10G | mode_1G)? 3'd0 :
           	   (mode_5G? 3'd1 : 3'd3);
               
    pulse_0 <= 1'b0;
    pulse_1 <= 1'b0;
end
else
begin	
	 //on last qwd in TX_DATa state, insert CRC & EOF
	if (IDLE_sel)	
		begin 
		if (insert_crc)
			begin 
		  //depends on the pkt's byte cnt (last 3 bits indicate the offset
				//to where CRC and EOF should be inserted.
			case (rbytes_reg[2:0])
			3'd0: txd <=   {32'h070707FD, crc32 };
			3'd1: txd <=   {64'h0707070707070707};
			3'd2: txd <=   {64'h0707070707070707};
			3'd3: txd <=   {64'h0707070707070707};
			3'd4: txd <=   {64'h07070707070707FD};
			3'd5: txd <=   {32'h07070707, 24'h0707FD, crc32[31:24] };
			3'd6: txd <=   {32'h07070707, 16'h07FD, crc32[31:16] };
			3'd7: txd <=   {32'h07070707, 8'hFD, crc32[31:8] };
			endcase	
			end
			
		else txd <=   mode_10G	?	64'h0707070707070707:
					  pulse_0	?	64'h0707070707070707:	txd;
		end
		
	else
		begin
			  //on last qwd transmit (in states other than TX_DATa)
		if ((mode_10G & wcnt[15])| (!mode_10G & wcnt[15] & pulse_0))
			begin
			case (rbytes_reg[2:0])
			3'd0: txd <=   {bdata2[63:32], bdata2[31:0] };
			3'd1: txd <=   {24'h0707FD, crc32[31:0], bdata2[7:0] };
			3'd2: txd <=   {16'h07FD, crc32[31:0], bdata2[15:0] };
			3'd3: txd <=   {8'hFD, crc32[31:0], bdata2[23:0] };
			3'd4: txd <=   {crc32, bdata2[31:0]};
			3'd5: txd <=   {crc32[23:0], bdata2[39:0] };
			3'd6: txd <=   {crc32[15:0], bdata2[47:0] };
			3'd7: txd <=   {crc32[7:0], bdata2[55:0] };
			endcase
				
			end
		
		else txd <=   mode_10G	?	{bdata2[63:0]}	:
					  (pulse_0	?	{bdata2[63:0]}	: txd);
		end
	
	txc  <=   mode_10G ? txc_int:
	          pulse_0 ? txc_int : txc;
	insert_crc <=   mode_10G ? (st_TX_DAT && wcnt[15]):
					(st_TX_CRC && pulse_1 && wcnt[15]);

	crc_we_    <=   mode_10G ?	(crc_we_ ? !st_GET_WAIT1 : !crc_last_):
					pulse_0	?	(crc_we_ ? !st_GET_WAIT1 : !crc_last_): crc_we_;  
	
	crc_last_  <=   mode_10G ?	(crc_last_ ? (crc_we_ || !crc_cnt[15]) : 1'b1):
					pulse_0	?	(crc_last_ ? (crc_we_ || !crc_cnt[15]) : 1'b1) : crc_last_;
					
	crc_cnt    <=   mode_10G ? (st_GET_WAIT1 ? (rbytes - 16'd17) : ((st_GET_WAIT2 || st_TX_DAT)? (crc_cnt - 16'd8) : crc_cnt)):
					pulse_0 ?  (st_GET_WAIT1 ? (rbytes - 16'd17) : ((st_GET_WAIT2 || st_TX_DAT)? (crc_cnt - 16'd8) : crc_cnt)): crc_cnt;
					
	crc_clr_   <=   mode_10G ? (!(st_IDLE || st_TX_CRC)):
					pulse_0 ?  (!(st_IDLE || st_TX_CRC)): crc_clr_;
	
    counter <= (mode_10G | mode_1G)? counter :
           	   (mode_5G	? ((|counter)? counter - 3'd1 : 3'd1) :
               ((|counter)? counter - 3'd1 : 3'd3));
                  
    pulse_0 <= (mode_10G | mode_1G)? pulse_0 :
               ((pulse_1)? 1'b1 : 1'b0);
    pulse_1 <= (mode_10G | mode_1G)? pulse_1 :
               ((counter == 3'd1)? 1'b1 : 1'b0);
               
	case(state)
	IDLE:
	begin
		state <= rts? GET_WAIT1: IDLE;
	end

	GET_WAIT1:
	begin
		state <=   mode_10G? GET_WAIT2 : 
		           (pulse_0? GET_WAIT2 : GET_WAIT1);
	end

	GET_WAIT2:
	begin
		state   <=   mode_10G? TX_DAT : 
		             (pulse_0? TX_DAT : GET_WAIT2); 
		             
		wcnt    <=   mode_10G ? nbytes_reg - 16'd1:
					 (pulse_0 ? nbytes_reg - 16'd1 : wcnt);
					 
		txc_int <=   mode_10G ? 8'h01:
					 (pulse_0 ? 8'h01 : txc_int) ;
					 
		IDLE_sel<=   mode_10G ? 1'b0:
					 (pulse_0 ? 1'b0 : IDLE_sel);
	end
	
	TX_DAT:
	begin
	
	   IDLE_sel <= mode_10G ? wcnt[15] : 
	   				pulse_0 ? wcnt[15] : IDLE_sel;
		
		state  <=   mode_10G? (wcnt[15] ? TX_CRC : TX_DAT) : 
		            pulse_0? (wcnt[15] ?  TX_CRC : TX_DAT) : state; 
		
		
		
		wcnt   <=   mode_10G ? wcnt - 16'd8:
					(pulse_0 ? wcnt - 16'd8 : wcnt);
					
		  if ((mode_10G & wcnt[15]) | (!mode_10G & wcnt[15] & pulse_0))			
		
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
			begin
			if ((mode_10G & wcnt <= 7) | (!mode_10G & wcnt <=7 & pulse_0))
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
		else txc_int <=   mode_10G ? 8'h00:
			(pulse_0 ? 8'h00 : txc_int);
			end
	end
	TX_CRC:
	begin
	
		state <=   mode_10G? (rts? GET_WAIT1: IDLE) : 
		           pulse_0 ? (rts ? GET_WAIT1: IDLE) : TX_CRC;
		txc_int <=   mode_10G ? 8'hff:
					(pulse_0 ? 8'hff : txc_int);
	end
	
	default:
	begin
		state <=   IDLE;
	end
	endcase
end

tx_mac10g_crc32x64 tx_mac10g_crc32x64(

   	.clk (clk156),				 //i, 156.25 Mhz
   	.rst_(rst_),				 //i,
   	.pulse_0(pulse_0),			 //for slower speed modes
   	.pulse_1(pulse_1),
   	.mode_10G(mode_10G), 
   	
   	.bytes  (rbytes_reg[2:0]), 		//i, valid data in last qwd
   	
   	.clr_  (crc_clr_),
   	.we_   (crc_we_),
   	.last_ (crc_last_),
   	.cdin  (rdata),				   //i, input data
   	.pdin  (bdata1),
   	
   	.crc32({crc32[7:0],crc32[15:8],crc32[23:16],crc32[31:24]}), //o,crc value
   	.crc32_vld_()
    );

       
//synopsys translate_off
reg [(32 *8)-1:0] ascii_state;
always@(state)
begin
	case(state)
	IDLE: ascii_state = "IDLE";
	GET_WAIT1: ascii_state = "GET_WAIT1";
	GET_WAIT2: ascii_state = "GET_WAIT2";
	TX_DAT: ascii_state = "TX_DAT";
	TX_CRC: ascii_state = "TX_CRC";
	default: ascii_state = "unknown";
	endcase
	
end
//synopsys translate_on


endmodule