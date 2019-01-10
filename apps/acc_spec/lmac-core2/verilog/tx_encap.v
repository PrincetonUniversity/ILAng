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

module tx_encap(
	clk,			// i-1
	rst_,			// i-1
	
	mode_10G ,		//i-1, speed modes
	mode_1G  ,		//i-1, 
	mode_5G,		//i-1, 

	rts,			// o-1
	wdata,			// o-64
	rbytes,			// o-16

	psaddr,				  // i-48
	mac_pause_value,	  // i-32
	tx_b2b_dly,			  // i-2
	
	rx_pause,			  // i-1
	rx_pvalue,			  // i-16
	rx_pack,			  // o-1
	
	txfifo_empty,		  // i-1
	txfifo_rd_en,		  // o-1
	txfifo_dout,		  // i-64
	
	xreq,				  // i-1
	xon,				  // i-1
	xdone				  // o-1
	
	);
	

input [47:0] psaddr;		// pause source address, source mac address in the pause frame to transmit
input [31:0] mac_pause_value;	   // [31:16] = tx_pause_value,	[15:0] = rx_pause_value
input [1:0]	 tx_b2b_dly;
				
input txfifo_empty;				  // i, high if FIFO is empty
output txfifo_rd_en;			  //o, read request to the FIFO

input [63:0] txfifo_dout; 		  // output of FIFO to input of this module

input clk;						  //i,
input rst_;						  //i,

input	mode_10G ;				  //i, indicates the speed mode.
input	mode_1G  ;				   //i, indicates the speed mode.
input	mode_5G;				   //i, indicates the speed mode.

output rts;						  //o, Request to send data to tx_xgmii.
output [63:0] wdata;			  //o-64, data output
output [15:0] rbytes;			 //o-16, holds the data size in Bytes

input rx_pause;
input [15:0] rx_pvalue;
output rx_pack;

input	xreq; 					  // need to transmit a pause frame, pause value is determined by xon
input	xon;    				  // 1: use tx_pause value as in register , 0: use pause value of 0 to abort the previous pause
output	xdone;  				  // pause frame has been transmitted   
	
reg txfifo_rd_en;
reg [15:0] rbytes;
reg rts;
reg [63:0] wdata;				 // o-64 data output

reg wsel;
reg [16:0] ptimer;
reg [3:0] p_reg_count;
reg p_start;

reg tx_rdy;						  // tell if there is no pause frame activating
reg rx_pack;
reg rx_pause_sync;
reg [15:0] rx_pvalue_sync;

reg [15:0] bytes_remain;		// keeps track of total bytes remaning to transmit

reg [2:0] counter;			   // used for different speed mode. 
reg pulse_0;
reg pulse_1;


parameter[7:0] 
	IDLE		= 8'h01 ,
	READSIZE	= 8'h02 ,
	READ1		= 8'h04 ,
	MAC_HDR		= 8'h08 ,
	MAC_DAT     = 8'h10 ,
	P_REQ		= 8'h20 ,
	P_PREAM		= 8'h40 ,
	P_PKT		= 8'h80	;
reg [7:0] state;

wire st_idle;		assign	st_idle		=	state[0];
wire st_readsize;	assign	st_readsize = 	state[1];
wire st_read1;	    assign	st_read1    = 	state[2];
wire st_mac_hdr;	assign	st_mac_hdr = 	state[3];
wire st_mac_dat;	assign	st_mac_dat	=	state[4];
wire st_p_req;		assign	st_p_req 	=	state[5];
wire st_p_pkt;		assign 	st_p_pkt	=	state[7];

reg tx_dvld;

// Counter for tx_b2b_dly
reg [5:0] b2b_cnt_val ;
always @(posedge clk)
begin
	if(!rst_)
	begin
		b2b_cnt_val <= 2'd0 ;
	end
	else
	begin
		case(tx_b2b_dly)
		2'b10 : b2b_cnt_val <= 6'd5  ; 
		2'b11 : b2b_cnt_val <= 6'd61 ; 	  // 64x64 bit delay (design already has 2, count another 62 clks (61 to 0))
		default: b2b_cnt_val <= 6'd0 ; 
		endcase
	end
end

reg [5:0] b2b_counter;
reg		  b2b_ok;
always @ (posedge clk)
begin
	if (!rst_)
	begin
		b2b_counter	<=	6'd0;
		b2b_ok		<=	1'b1;
	end
	
	else
	begin
		b2b_counter <= (st_mac_dat)? b2b_cnt_val : ((st_idle & |b2b_counter)? (b2b_counter - 6'd1) : b2b_counter);
		b2b_ok		<=	!(|b2b_counter); // b2b_counter == 6'h0
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
		p_reg_count <=   4'h7 ;
		p_start <=   0;
	end
	
	else
	begin
		ptimer    <=   rx_pause_sync ? {rx_pvalue_sync - 17'h1} : (ptimer[16] ? ptimer : ((|p_reg_count)? ptimer: (ptimer - 17'h1)));
		p_start <=   ptimer[16]? 1'b0 : (rx_pause_sync? 1'b0 : 1'b1);
		p_reg_count <=   p_start? ((|p_reg_count)? (p_reg_count - 4'h1) : 4'h7) : 4'h7;
	end
end


// Transmit Pause
reg [63:0] 	p_data;
reg	[2:0]	p_cnt;
reg			p_1;
reg			p_done;
reg			p_send;
reg			xdone;

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
	end
	
	else
	begin
		p_cnt <= st_p_pkt? (p_cnt - 3'd1) : 3'd7;
		p_1 <= st_p_req;
		p_done <= p_cnt == 3'h0;
		p_send <= p_1? 1'b1 : (p_done? 1'b0 : p_send);
		xdone  <= p_cnt == 3'h1;
		
		case ({p_1, p_cnt})
		4'b1111: p_data <= {psaddr[39:32], psaddr[47:40], 48'h0100_00c2_8001}; 
		4'b0111: p_data <= {32'h0100_0888, psaddr[7:0], psaddr[15:8], psaddr[23:16], psaddr[31:24]};	
		4'b0110: p_data <= xon? {48'h0, mac_pause_value[23:16], mac_pause_value[31:24]}: 64'h0;
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
		wdata	<=	mode_10G? (p_send? p_data : (wsel? 64'hd5555555555555FB : txfifo_dout)) :
	            	(p_send? p_data : 
	            	(wsel? ((st_idle & pulse_0)? 64'hd5555555555555FB : wdata) : (( (st_mac_hdr | st_mac_dat) & pulse_0)? txfifo_dout : wdata)));
	            	
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
	rts <= 1'b0;
// different values for different speed modes.	
	counter <= (mode_10G | mode_1G)? 3'd0 :
	           (mode_5G? 3'd1 : 3'd3);
	           
	pulse_0 <= 1'b0;
    pulse_1 <= 1'b0;
end
else
begin
	tx_rdy    <=   ptimer[16];
	rx_pack   <=   rx_pause_sync; 
	rts		  <=   mode_10G? (st_readsize | st_p_req) :
	               ((st_read1 & pulse_1)  | st_p_req);
	
    counter <= (mode_10G | mode_1G)? counter :
               (mode_5G? ((|counter)? counter - 3'd1 : 3'd1) :
               ((|counter)? counter - 3'd1 : 3'd3));
                  
    pulse_0 <= (mode_10G | mode_1G)? pulse_0 :
               ((pulse_1)? 1'b1 : 1'b0);
    pulse_1 <= (mode_10G | mode_1G)? pulse_1 :
               ((counter == 3'd1)? 1'b1 : 1'b0);
	
	case(state)
	
	IDLE:
	begin
		wsel  <= 1'b1;
		
		if (b2b_ok && xreq)
		begin
			state <= P_REQ;
			txfifo_rd_en <= 1'b0;
		end
		
		else if (b2b_ok && !txfifo_empty && tx_rdy && !rx_pause_sync)
		begin
			state <= mode_10G? READSIZE : 
			         (pulse_0? READSIZE : IDLE); 
			txfifo_rd_en <= mode_10G? 1'b1 : txfifo_rd_en;
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
		txfifo_rd_en <=   mode_10G? 1'b1 :
                         (pulse_1? 1'b1 : 1'b0);
		state <=  mode_10G? READ1 : 
		          (pulse_0? READ1 : READSIZE);
	end
// read the size of data in bytes, caluclate byte remaining.	
	READ1:
	begin
		txfifo_rd_en <=  mode_10G? 1'b1 :
                         (pulse_1? 1'b1 : 1'b0);
		state <=   mode_10G? MAC_HDR :
		           (pulse_0? MAC_HDR : READ1);
		rbytes <=  mode_10G? txfifo_dout[15:0] :
		           (pulse_0? txfifo_dout[15:0] : rbytes);
		bytes_remain <=  mode_10G? txfifo_dout[15:0]-16'h8 :
		                 (pulse_0? txfifo_dout[15:0]-16'h8 : bytes_remain);
		wsel <= mode_10G? 1'b0 :
		        (pulse_0? 1'b0 : wsel);
		
	end
	
	MAC_HDR:
	begin
		wsel  <=   1'b0;
		state <=   mode_10G? MAC_DAT : 
		           (pulse_0? MAC_DAT : MAC_HDR);
		tx_dvld <= mode_10G? 1'b1 :
		           (pulse_0? 1'b1 : tx_dvld);
		txfifo_rd_en <=  mode_10G? 1'b1 :
                        (pulse_1? 1'b1 : 1'b0);
		bytes_remain <=   mode_10G? bytes_remain - 16'h8 :
		                  (pulse_0? bytes_remain - 16'h8 : bytes_remain);
	end
	
	MAC_DAT:
	begin
		wsel <= 1'b0;
		
		state <=   mode_10G? ((tx_dvld) ? MAC_DAT : IDLE) : 
		           ( tx_dvld? MAC_DAT : (pulse_0? IDLE : MAC_DAT) );
		           
		bytes_remain <=   mode_10G? bytes_remain - 16'h8 :
		                  (pulse_0? bytes_remain - 16'h8 : bytes_remain);
		                  
		tx_dvld <=    mode_10G? ((bytes_remain[15] || bytes_remain == 0)? 1'b0: 1'b1) :
		              ((bytes_remain[15] || bytes_remain == 0)? ((pulse_0)? 1'b0: tx_dvld) : tx_dvld);
		              
		txfifo_rd_en <=   mode_10G? ((bytes_remain > 8 && !bytes_remain[15])? 1'b1 : 1'b0) :
		                  ( (bytes_remain > 0 && !bytes_remain[15] && pulse_1)? 1'b1 : 1'b0);
		                  
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
	MAC_HDR: 	ascii_state = "MAC_HDR";
	MAC_DAT: 	ascii_state = "MAC_DAT";
	P_REQ:	    ascii_state = "P_REQ";  
	P_PREAM:	ascii_state = "P_PREAM";
	P_PKT:	    ascii_state = "P_PKT";
	default: 	ascii_state = "unknown";
	
	endcase
	
end
//synopsys translate_on


endmodule