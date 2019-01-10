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
`timescale 1ns / 1ns                                                                                                                                               
// synopsys translate_on

module gige_s2p (
	clk,				// i-1
	reset_,				// i-1

	mode_10G ,			//i-1, speed modes
	mode_5G  ,			//i-1, speed modes
	mode_2p5G, 			//i-1, speed modes
	mode_1G  ,			//i-1, speed modes
	
	data_in,			// i-8, input data
	ctrl_in,			// i-1
	pdet_in,			// i-1
	
	data_out,			// o-64
	ctrl_out,			// o-8
	
	loopback_en,		// i-1
	sfp_los,			// i-1
	linkup,				// o-1
	x_we,
	x_bcnt_we,
	x_byte_cnt
	);

input 			clk;
input 			reset_;

input			mode_10G ;		//i-1, speed modes
input			mode_5G  ;		//i-1, speed modes
input			mode_2p5G; 		//i-1, speed modes
input			mode_1G  ;		//i-1, speed modes


input 	[7:0]	data_in;		// i-8, input data
input 			ctrl_in;		// i-1
input			pdet_in;		// i-1

output	[63:0]	data_out;		// o-64, data output
output	[07:0]	ctrl_out;		// o-8, control output

input			loopback_en;	 // i-1
input			sfp_los;		 // i-1
output			linkup;			 // o-1
output          x_we;
output          x_bcnt_we;
output	[15:0]	x_byte_cnt;

reg			linkup;
reg         x_we;
reg         x_bcnt_we;
reg [15:0]	x_byte_cnt;

reg 	[7:0]	data_in_dly;
reg 			ctrl_in_dly;

reg			frame;
reg			insert;

reg			sof;
reg			eof;

reg			eof0;
reg			eof1;
reg			eof2;	
reg			eof3;
reg			eof4;
reg			eof5;
reg			eof6;
reg	[15:0]	count;

reg			pvld; 				   // parallel data is valid

reg [63:0]	data_out;
reg [7:0]	ctrl_out;

reg [7:0]	dff0, dff1, dff2, dff3, dff4, dff5, dff6, dff7;
reg 		cff0, cff1, cff2, cff3, cff4, cff5, cff6, cff7;

wire [63:0] pdata = {dff0, dff1, dff2, dff3, dff4, dff5, dff6, dff7};		  // parallel data
wire [7:0]	pctrl = {cff0, cff1, cff2, cff3, cff4, cff5, cff6, cff7};		  // parallel control

reg 		eof_dly1;
reg 		eof_dly2;
 
always @ (posedge clk)
begin
	if (!reset_)
	begin
		data_in_dly <= 8'h07;
		ctrl_in_dly <= 1'b1; 
	
		frame <= 1'b0;
		insert <= 1'b0;
		
		sof <= 1'b0;
		eof <= 1'b0;
		eof_dly1 <= 1'b0;
		eof_dly2 <= 1'b0;
		
		eof0 <= 1'b0;
		eof1 <= 1'b0;
		eof2 <= 1'b0;
		eof3 <= 1'b0;
		eof4 <= 1'b0;
		eof5 <= 1'b0;
		eof6 <= 1'b0;
		
		count <= 16'h0;
		pvld <= 1'b0;
		
		data_out <= 64'h0707_0707_0707_0707;
		ctrl_out <= 8'hff;
		x_bcnt_we <= 1'b0;
		x_we <= 1'b0;
		
		x_byte_cnt <= 16'h0;
	end
	
	else
	begin
				
		data_in_dly <= data_in;
		ctrl_in_dly <= ctrl_in;
	
		frame <= (ctrl_in & (data_in == 8'hfb))? 1'b1 : ((ctrl_in & (data_in == 8'hfd))? 1'b0 : frame);
		insert <= frame & !ctrl_in;
	
		sof <= ctrl_in & (data_in == 8'hfb);
		eof <= ctrl_in & (data_in == 8'hfd);
		eof_dly1	<= eof ;
		eof_dly2 <= eof_dly1;
		
		if (mode_1G)
			begin                  
				eof0 <= eof & (count == 16'd7);
				eof1 <= eof & (count == 16'd6);
				eof2 <= eof & (count == 16'd5);
				eof3 <= eof & (count == 16'd4);
				eof4 <= eof & (count == 16'd3);
				eof5 <= eof & (count == 16'd2);
				eof6 <= eof & (count == 16'd1);
				
				count <= (frame & count != 16'h0)? (count - 16'h1) : 16'h7 ;
				
				x_byte_cnt <= (data_in == 8'hfb & ctrl_in) ? 16'd1 :
						(frame) ? x_byte_cnt + 16'd1 :     
						x_byte_cnt;                                       
				
		        x_bcnt_we <= eof_dly2;
				
			end
		    			
		pvld <= (count == 16'h1);
				
		
		casez ({linkup, pvld, eof0, eof1, eof2, eof3, eof4, eof5, eof6})
		9'b11???????:			  // data within the frame
				begin
				data_out <= pdata;
		        ctrl_out <= pctrl;		        
		        x_we <=	1'b1;							
				end
		
		9'b101??????:			  // eof on lane 0
				begin
				data_out <= 64'h0707_0707_0707_07fd;
		        ctrl_out <= 8'hff;
		        x_we <= 1'b1;                  
				end
				
		9'b1001?????:			  // eof on lane 1
				begin
				data_out <= {56'h070707070707fd, dff2};
		        ctrl_out <= {7'b1111111, cff2};
		        x_we <= 1'b1;                  
				end
				
		9'b10001????:			 // eof on lane 2
				begin
				data_out <= {48'h0707070707fd, dff2, dff3};
		        ctrl_out <= {6'b111111, cff2, cff3};
		        x_we <= 1'b1;                  
				end
				
		9'b100001???:			 // eof on lane 3
				begin
				data_out <= {40'h07070707fd, dff2, dff3, dff4};
		        ctrl_out <= {5'b11111, cff2, cff3, cff4};
		        x_we <= 1'b1;      
				end
		
		9'b1000001??:		   // eof on lane 4
				begin
				data_out <= {32'h070707fd, dff2, dff3, dff4, dff5};
		        ctrl_out <= {4'b1111, cff2, cff3, cff4, cff5};
		        x_we <= 1'b1;   
				end
				
		9'b10000001?:			// eof on lane 5
				begin
				data_out <= {24'h0707fd, dff2, dff3, dff4, dff5, dff6};
		        ctrl_out <= {3'b111, cff2, cff3, cff4, cff5, cff6};
		        x_we <= 1'b1;   
				end
				
		9'b100000001:		   // eof on lane 6
				begin
				data_out <= {16'h07fd, dff2, dff3, dff4, dff5, dff6, dff7};
		        ctrl_out <= {2'b11, cff2, cff3, cff4, cff5, cff6, cff7};
		        x_we <= 1'b1;   
				end
			   // If eof on lane 7, it is multiple of 8, pvld will take care of it		
		default:
				begin
				data_out <= 64'h0707_0707_0707_0707;
		        ctrl_out <= 8'hff;
		        x_we <= 1'b0;                  
				end
		endcase
		
	end
end

// Cascading D flip flop 
always @ (posedge clk)
begin	
	if (!reset_)
		begin
			dff0 <= 8'b0;
			dff1 <= 8'b0;
			dff2 <= 8'b0;
			dff3 <= 8'b0;
			dff4 <= 8'b0;
			dff5 <= 8'b0;
			dff6 <= 8'b0;
			dff7 <= 8'b0;
			
			cff0 <= 1'b0;
			cff1 <= 1'b0;
			cff2 <= 1'b0;
			cff3 <= 1'b0;
			cff4 <= 1'b0;
			cff5 <= 1'b0;
			cff6 <= 1'b0;
			cff7 <= 1'b0;
		end
	else if (mode_1G)	
		begin
			dff0 <= data_in;
			dff1 <= dff0;
			dff2 <= dff1;
			dff3 <= dff2;
			dff4 <= dff3;
			dff5 <= dff4;
			dff6 <= dff5;
			dff7 <= dff6;
			
			cff0 <= ctrl_in;
			cff1 <= cff0;
			cff2 <= cff1;
			cff3 <= cff2;
			cff4 <= cff3;
			cff5 <= cff4;
			cff6 <= cff5;
			cff7 <= cff6;
		end		
end


// LINKUP DETECTION 
reg pdet_in_dly;
reg idle_detect;
reg [7:0] consec_idle;
reg link_ok;
reg	link_break;
reg real_los;

always @ (posedge clk)
begin
	if (!reset_)
	begin
		pdet_in_dly <= 1'b0;
		idle_detect <= 1'b0;
		consec_idle <= 8'h0;
		link_ok 	<= 1'b0;
		link_break	<= 1'b0;
		real_los	<= 1'b0;
		linkup		<= 1'b0;
	end
	
	else
	begin
		pdet_in_dly <= pdet_in;
		idle_detect <= pdet_in | pdet_in_dly;
		consec_idle <= linkup? 8'h00 : {consec_idle[6:0], idle_detect};
		link_ok		<= (consec_idle == 8'hff) & !real_los;
		link_break	<= (pdata == 64'h0000_42BC_0000_B5BC) | real_los;
		real_los	<= (sfp_los & !loopback_en);
		linkup		<= link_ok? 1'b1 : (link_break? 1'b0 : linkup);
	end
end

endmodule