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