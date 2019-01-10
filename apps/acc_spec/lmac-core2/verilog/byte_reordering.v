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
	clk250	,			 //i-1 156.25Mhz
	x_clk,
	reset_,
	fmac_rxd_en	,		//i-1, 
	
	xaui_mode,			//i-1
	
	data_in,		   //i-64
	ctrl_in,		   //i-8
	data_out,		  //o-64
	ctrl_out,		   //o-8
	br_sof4,		   //o-1, special case of SOF & EOF at same time, may contain data
	
	RAW_FRAME_CNT,		   //o-32, 
	BAD_FRAMESOF_CNT,	  //o-32, 
	init_done,			   //i-1
	linkup,					//o-1
	rx_auto_clr_en			
	
	);

input clk250;			  //i, clock 156.25MHz
input x_clk;			  //i, clock 156.25Mhz
input reset_;			  //i, 
input fmac_rxd_en;		  //i-1, 

input xaui_mode;		  //i-1, 

input 	[63:0]	data_in;	  //i-64, data input
input 	[07:0]	ctrl_in;	  //i-8, control input
output	[63:0]	data_out;	  //o-64, output data
output	[07:0]	ctrl_out;	  //o-8, control output
output			br_sof4;	  //o-1, special case of SOF & EOF at same time, may contain data

output	[31:0]	RAW_FRAME_CNT ;		//o-32, 
output	[31:0]	BAD_FRAMESOF_CNT ;	//o-32, 
input	init_done;					//i-1
output	linkup;						//o-1

input	rx_auto_clr_en;
reg		unknown_sof_sticky ;

parameter [2:0]
	LINK_FAIL = 3'h1,
	LINK_RCVR = 3'h2,
	LINK_GOOD = 3'h4;
reg [2:0] state;

reg [4:0] link_cnt;

reg		[63:0]	data_out ;
reg		[63:0]	data_in_dly ;
reg		[07:0]	ctrl_in_dly ;
reg		[07:0]	ctrl_out ;
reg				br_sof4 ;
reg				sof4_cycle ;			   //indicate data is shifted by 4.

reg				shift;			 // indicates data needs to be shifted according to the SOF
reg				eof0 ;			 // End of frame occurring in 0-3 Bytes of incoming data
reg				eof1 ;			 // End of frame occurring in 4-7 Bytes of incoming data
reg				linkup;
reg				link_bad;
reg				link_ok;
wire			link_fault;
assign			link_fault = !init_done || (data_in_dly[39:32] == 8'h9C && ctrl_in_dly[4] == 1'b1) || 
										   (data_in_dly[7:0]   == 8'h9C && ctrl_in_dly[0] == 1'b1);
										   

wire 	seq0 ;					// detects error
assign 	seq0 = (data_in[7:0] == 8'h9C && ctrl_in[0] == 1'b1) ;
wire	seq1 ;					//detects error
assign	seq1 = (data_in[39:32] == 8'h9C && ctrl_in[4] == 1'b1) ;
										   
reg		sof0;			 // Indicate the incoming data has start of frame on 0th byte
reg		sof1;			 // Indicate the incoming data has start of frame on 1st byte
reg		sof2;			 // Indicate the incoming data has start of frame on 2nd byte
reg		sof3;			 // Indicate the incoming data has start of frame on 3rd byte
reg		sof4;			 // Indicate the incoming data has start of frame on 4th byte
reg		sof5;			  // Indicate the incoming data has start of frame on 5th byte
reg		sof6;			 // Indicate the incoming data has start of frame on 6th byte
reg		sof7;			 // Indicate the incoming data has start of frame on 7th byte
reg		has_sof;		 // Indicates the incoming data has a valid sof
reg		frame_done;		 // transmission of frame is done
reg		fmac_rxd_en156 ;

reg		any_sof ;			// having invalid and valid both sof's
reg		any_eof ;			// indicates the incoming data has any eof. 
wire	eof	;
assign	eof	= eof0 | eof1 ;

reg		bad_frame ;			 
reg		bad_frame_noeof ;	 // frames without eof

reg		[31:0]	raw_sof_cnt156 ;	  //counter to store the value 
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


always @ (posedge x_clk)
begin
		data_in_dly	<=	data_in ;
		
		ctrl_in_dly[3:0] <= seq0? 4'hf : ctrl_in[3:0] ; 
		ctrl_in_dly[7:4] <= seq1? 4'hf : ctrl_in[7:4] ;	  
		
		fmac_rxd_en156	<= fmac_rxd_en ;
end

always @ (posedge x_clk)
begin
	if (!reset_)
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
		
		// if FB is not on the 0th Byte, then shift the incoming data. 
		shift		<= 	(
				(data_in[39:32]==8'hFB) && (ctrl_in[4] == 1'b1))? 1'b1 :     
				( ( ((eof0 ||eof1) & !sof4) || (sof0 & !sof4) )? 1'b0 : 	 
				  shift
				);
		// detects the position of eof in lower half of incoming data
		eof0      	<=  (ctrl_in[0] && (data_in[7:0] == 8'hFD)) || (ctrl_in[1] && (data_in[15:8] == 8'hFD)) || 
						(ctrl_in[2] && (data_in[23:16] == 8'hFD)) || (ctrl_in[3] && (data_in[31:24] == 8'hFD));
		 // detects the position of eof in upper half of incoming data
		eof1      	<=  (ctrl_in[4] && (data_in[39:32] == 8'hFD)) || (ctrl_in[5] && (data_in[47:40] == 8'hFD)) || 
						(ctrl_in[6] && (data_in[55:48] == 8'hFD)) || (ctrl_in[7] && (data_in[63:56] == 8'hFD));	
						
		linkup		<=	state[2];
		link_bad	<=	link_fault;
		link_ok		<=	(link_cnt == 5'd0);
	  //start of frame (FB) can occur on lane 0 or 4
		sof0		<=  (data_in[7:0]==8'hFB) & ctrl_in[0];
	  
		sof4		<=	(data_in[39:32]==8'hFB) & ctrl_in[4];
		
		br_sof4	<= sof4 ;
		
		// invalid sof's
		sof1		<=  (data_in[15:8]==8'hFB)  & ctrl_in[1];
		sof2		<=  (data_in[23:16]==8'hFB) & ctrl_in[2];
		sof3		<=  (data_in[31:24]==8'hFB) & ctrl_in[3];
		
		sof5		<=  (data_in[47:40]==8'hFB) & ctrl_in[5];
		sof6		<=  (data_in[55:48]==8'hFB) & ctrl_in[6];
		sof7		<=  (data_in[63:56]==8'hFB) & ctrl_in[7];
		
	// registers to keep track of different types of frame. 	
		has_sof		<=	  (sof0 | sof4) ? 1'b1: 
						( (eof0 | eof1) ? 1'b0 :
						has_sof );		
						
		frame_done	<=
						frame_done ? 1'b0 :	
						(eof0 | eof1) & has_sof ? 1'b1 : 	
						1'b0 ;
	
		bad_framesof_cnt156	<=	
			!fmac_rxd_en156 ? 32'h0 :		
			(bad_frame | bad_frame_noeof) ? bad_framesof_cnt156 + 8'd1 :
			bad_framesof_cnt156;
			
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

always @(posedge x_clk)
begin
	if (!reset_)
		begin
			data_out		<= 64'h0707070707070707;
			ctrl_out		<= 8'hff;
		end
	
	else
		begin
		
			data_out	<= 
					//GIGE mode data come out directly
				!xaui_mode ? data_in :
				//1st shift qwd is special due to EOF & SOF4 at same time
				(sof4_cycle & eof0 )? {32'h07070707, 32'h07070707} :		  //SOF4-SOF4 cycles , eof in 1st half
				(shift & sof4)? {32'h07070707, data_in_dly[31:0]} : 		  	//previously NOT SOF4 cycle
				(shift & eof0)? {32'h07070707, 32'h07070707} : 		
				(shift & eof1)? {32'h07070707, data_in_dly[63:32]} : 
				//shift during data time
				(shift )? {data_in[31:0], data_in_dly[63:32]} : 
				data_in_dly ;	
				
			ctrl_out[3:0]	<= 
				 //GIGE support
				!xaui_mode ? ctrl_in[3:0] :
				//1st shift qwd is special due to EOF & SOF4 at same time
				(sof4_cycle & eof0)? {4'hf} : 		
				(shift & sof4)? { ctrl_in_dly[3:0]} : 
			   //shift during ending time (if more SOF4 coming, it must have priority above)
				(shift & eof0)? {4'hf} : 		
				(shift & eof1)? {ctrl_in_dly[7:4]} : 
				(shift & !sof4 )? ctrl_in_dly[7:4] : 
				ctrl_in_dly[3:0] ;
			
			ctrl_out[7:4]	<= 
				 //GIGE support
				!xaui_mode ? ctrl_in[7:4] :
				(sof4_cycle & eof0)? {4'hf } : 
				(shift & sof4)     ? {4'hf } : 
				//shift during ending time (if more SOF4 coming, it must have priority above)
				(shift & eof0)? {4'hf} : 	
				(shift & eof1)? {4'hf} : 
				//shift but first sequence (error case)
				(shift & seq0)? 4'hf : 
				(shift )? ctrl_in[3:0] : 
				 //norm, keep as info come in
				ctrl_in_dly[7:4]  ;
		end
end

// LINKUP DETECTION FSM

always @ (posedge x_clk)
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


br_sfifo4x32	rf_sfifo (				 //raw frame fifo
	.aclr	(!reset_ | !fmac_rxd_en156), //i-1
	.wrclk	(x_clk),					 //i-1, clk156
	.data	(raw_frame_cnt156 ),		 //i-32
	.wrreq	(!rf_sfifo_full),			 //i-1
	.rdclk	(clk250),					 //i-1
	.rdreq	(!rf_sfifo_empty),			 //i-1
	.q			(rf_sfifo_dout ),		 //o-32, 
	.rdempty	(rf_sfifo_empty),		 //o-1
	.rdusedw	(),						 //o-2,
	.wrfull		(rf_sfifo_full)			 //o-1
	);
	

always @ (posedge clk250)
	if (!reset_ | !fmac_rxd_en )
		begin
		
		RAW_FRAME_CNT		<=	32'h0;
		
		end
	else
		begin
		
		RAW_FRAME_CNT		<=	rx_auto_clr_en ? 32'h0 : rf_sfifo_dout ;
		
		end
	


br_sfifo4x32	bfsof_sfifo (			  	//bad frameSOF fifo
	.aclr	(!reset_ | !fmac_rxd_en156),	//i-1
	.wrclk	(x_clk),						//i-1, clk156
	.data	({unknown_sof_sticky, bad_framesof_cnt156[30:0]} ),		 //i-32
	.wrreq	(!bfsof_sfifo_full),		   //i-1
	.rdclk	(clk250),						//i-1
	.rdreq	(!bfsof_sfifo_empty),		   //i-1
	.q			(bfsof_sfifo_dout ),	   //o-32,
	.rdempty	(bfsof_sfifo_empty),	   //o-1
	.rdusedw	(),						   //o-2,
	.wrfull		(bfsof_sfifo_full)		   //o-1
	);
	

always @ (posedge clk250)
	if (!reset_ | !fmac_rxd_en )
		begin
		
		BAD_FRAMESOF_CNT		<=	32'h0;
		
		end
	else
		begin

		BAD_FRAMESOF_CNT		<=	rx_auto_clr_en ? 32'h0 : bfsof_sfifo_dout ;
		
		end




always @ (posedge x_clk)
begin
	if (!reset_)
		begin
		bad_frame	<= 1'b0 ;			   //EOF but no SOF
		bad_frame_noeof	<= 1'b0 ;		   //frame has no EOF
		
		unknown_sof_sticky	<= 1'b0 ;
		any_sof	<= 1'b0 ;
		any_eof	<= 1'b0 ;
		
		end
	else
		begin
		
		bad_frame	<= 
			(eof0 | eof1) & !has_sof
			;
			
		bad_frame_noeof	<= 
			(sof0 | sof1 | sof2 | sof3 |
			 sof4 | sof5 | sof6 | sof7 ) & has_sof
			;
			
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