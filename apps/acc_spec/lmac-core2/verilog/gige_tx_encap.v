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
	clk,		         // i-1		
	rst_,		// i-1		

	rts,		// o-1		
	wdata,		// o-64		
	rbytes,		// o-16		
	cts,		// i-1		

	psaddr,		// i-48		
	mac_pause_value,	  // i-32
	tx_b2b_dly,		// i-2	
	
	rx_pause,   		// i-1
	rx_pvalue,             // i-16
	rx_pack,            // o-1
	
	txfifo_empty,		 // i-1
	txfifo_rd_en,    	 // o-1
	txfifo_dout,  		 // i-64
	
	xreq,				 // i-1					
	xon,				 // i-1
	xdone				 // o-1
	
	);

		
input [47:0] psaddr;		// pause source address, source mac address in the pause frame to transmit	
input [31:0] mac_pause_value; 	 // [31:16] = tx_pause_value,	[15:0] = rx_pause_value
input [1:0]	 tx_b2b_dly;
				
input txfifo_empty;
output txfifo_rd_en;

input [63:0] txfifo_dout; 		 // output of FIFO to input of this module

input clk;					   //i,
input rst_;					   //i,

output rts;					   //o, to gmii 
output [63:0] wdata;		   //o, data output
output [15:0] rbytes;		   //o, hold the length of data
input	cts;				   //i, from gmii

input rx_pause;
input [15:0] rx_pvalue;
output rx_pack;

// Interface to tx_decap
input	xreq; 		// need to transmit a pause frame, pause value is determined by xon
input	xon;    	// 1: use tx_pause value as in register , 0: use pause value of 0 to abort the previous pause
output	xdone;  	// pause frame has been transmitted

reg txfifo_rd_en;		 //o, read request to the FIFO
reg [15:0] rbytes;		 //o, hold the size of data in BYtes
reg rts;				 //o, request to send to xgmii
reg [63:0] wdata;		 //o-64, data output

reg wsel;
reg [16:0] ptimer;
reg [5:0] p_reg_count;	  // count 64 clk (8 bits per clk) for 512 bit time for each pause value
reg p_start;

reg tx_rdy;				  // tell if there is no pause frame activating
reg rx_pack;
reg rx_pause_sync;
reg [15:0] rx_pvalue_sync;

reg [15:0] bytes_remain;	// how many Bytes of data remaining for transmission 

reg [3:0] count8;
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
wire st_mac_dat;	assign	st_mac_dat	=	state[4];
wire st_p_req;		assign	st_p_req 	=	state[5];
wire st_p_pkt;		assign 	st_p_pkt	=	state[7];

reg tx_dvld;

// Counter for tx_b2b_dly
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
		2'b01 : b2b_cnt_val <= 9'd13 ; 			 // 16x8 bit delay (design already has 2, count another 14 clocks (13 to 0))
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
		b2b_ok		<=	!(|b2b_counter); 			 // b2b_counter == 9'h0
	end
end

// PAUSE TX
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

 // Transmit Pause
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

// PAUSE TX
always@(posedge clk)
begin

	if(!rst_)
		wdata <= 64'hd5555555555555FB;
	
	else
		wdata	<=	p_send? p_data : (wsel? 64'hd5555555555555FB : txfifo_dout);
	
end

 // STATE MACHINE

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
end
else
begin
	tx_rdy    <=   ptimer[16];
	rx_pack   <=   rx_pause_sync; 
	rts		  <=   st_readsize | st_p_req;
	
	case(state)
	// disable the read request. 
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
			txfifo_rd_en <= 1'b1;
		end
		
		else
		begin
			state <= IDLE;
			txfifo_rd_en <= 1'b0;
		end
	end
	// disable the read request to the FIFo
	READSIZE:
	begin
		wsel  <= 1'b1;
		txfifo_rd_en <=   1'b0;
		state <=   READ1;
	end
// Collect the total data size in BYtes	
	READ1:
	begin
		txfifo_rd_en <=   1'b0;
		state <=   WAIT;
		rbytes <=   txfifo_dout[15:0];
		bytes_remain <=   txfifo_dout[15:0]-16'h8;	   // calculate how many bytes remaining to transmit
		wsel <= 1'b1;
		count8 <= 4'd6;
		tx_dvld <= 1'b1;
	end
	// wait state to transmit one byte of data.
	WAIT:
	begin
		state <=  (|count8)? WAIT : (tx_dvld)? MAC_DAT : IDLE;
		count8 <= count8 - 4'd1;
		txfifo_rd_en <= (count8 == 4'd1) & tx_dvld;
		wsel <= (|count8)? wsel : (tx_dvld)? 1'b0 : 1'b1;
	end
	
	MAC_DAT:
	begin
		wsel <= 1'b0;
		state <= WAIT;
		bytes_remain <=   bytes_remain - 16'h8;
		tx_dvld <=   (bytes_remain[15] || bytes_remain == 0)? 1'b0: 1'b1;
		count8 	  <=   (bytes_remain[15] || bytes_remain == 0)? 4'd12: 4'd6;
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