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


`timescale 1ns / 1ns                                                                                                                                               

module g2x_ctrl(
            
    clk,			// i-1
	reset_,			// i-1
                	
	mode_10G ,		//i-1, speed modes
	mode_5G  ,		//i-1, 
	mode_2p5G, 		//i-1, 
	mode_1G  ,		//i-1, 
	
	gf_bcnt_empty,	// i-1
	
	data_in,		// i-64
	ctrl_in,		// i-8
	bcnt_in,		// i-16
	
	gige_bcnt_fifo_re,	// o-1
	gige_data_fifo_re,	// o-1
	
	data_out,		// o-64
	ctrl_out,		// o-8
	            	
	dbg				// o-1, test
);

	input       		clk;
	input				reset_;

	input				mode_10G ;	//i-1, speed modes
	input				mode_5G  ;	//i-1, 
	input				mode_2p5G; 	//i-1, 
	input				mode_1G  ;	//i-1, 
	
	input				gf_bcnt_empty;
	
	input		[63:0]	data_in;
	input		[ 7:0] 	ctrl_in;
	input		[15:0] 	bcnt_in;
	        	
	output	reg 		gige_bcnt_fifo_re;
	output	reg 		gige_data_fifo_re;
	
	output	reg	[63:0]	data_out;
	output	reg	[ 7:0] 	ctrl_out;
	
	output  	 		dbg;

	reg			[15:0] 	qwd_cnt;
	reg 				gige_data_fifo_re_dly1;

			
	//State Machine to read from the gige_rx_bcnt_fifo
	reg		[7:0] 	gf_state;
	
	wire			gf_idle_st;
	wire			gf_rd_bcnt_st;
	wire			gf_bcnt_buf_st;
	wire			gf_rd_data_st;
	wire			gf_done_st;
	
		
	parameter [7:0]       
			GF_IDLE   		= 	8'h01,  
			GF_RD_BCNT		= 	8'h02, 	//read bcnt
			GF_BCNT_BUF		= 	8'h04, 	//store bcnt
			GF_RD_DATA	    = 	8'h08,	//read data based on bcnt	
			GF_DONE   		= 	8'h80;    
	
				
	assign	gf_idle_st		= 	gf_state[0];   
	assign  gf_rd_bcnt_st	= 	gf_state[1];             
	assign  gf_bcnt_buf_st	= 	gf_state[2];             
	assign	gf_rd_data_st	= 	gf_state[3];   
	assign	gf_done_st		= 	gf_state[7];
	
	assign 	dbg	= 1'b0;
		
	
	always @ (posedge clk) begin             
	               	                                
		if (!reset_) begin   
		                       
			gf_state			<=	GF_IDLE ; 
					     
		end  
		                          
		else begin                          
		                               
			if (gf_idle_st)
					//if bcnt_fifo is not empty, i.e. there is atleast one packet              
					gf_state	<=	(!gf_bcnt_empty)? GF_RD_BCNT : GF_IDLE;                            
					                             					                             
			else if (gf_rd_bcnt_st)  
					//read bcnt            
					gf_state	<=	GF_BCNT_BUF;
					  
			else if (gf_bcnt_buf_st)              
					gf_state	<=	GF_RD_DATA;  
											
			else if (gf_rd_data_st)            
					//read data till qwd_cnt is zero              
					gf_state	<=	(qwd_cnt == 16'b0)? GF_DONE : GF_RD_DATA;		
			 
			else if (gf_done_st)                          		
					gf_state	<=	GF_IDLE;                       	  		
		 			    									                          		                             
		end                 
	                                
	end		
	


	always @ (posedge clk) begin
	
	    if(!reset_) begin

	        gige_bcnt_fifo_re	<=	1'b0;
	        gige_data_fifo_re	<=	1'b0;
	    	                  
	    	data_out			<=	64'h0707_0707_0707_0707;
	        ctrl_out			<=	8'hff;
	        
	        qwd_cnt				<=	16'b0;
			
			gige_data_fifo_re_dly1	<=	1'b0;
	                
		end
	    else begin
			//dly signal
	    	gige_data_fifo_re_dly1	<=	gige_data_fifo_re;
	    
	    	data_out			<=	(gige_data_fifo_re_dly1)?	data_in : 64'h0707_0707_0707_0707;
	        ctrl_out			<=	(gige_data_fifo_re_dly1)?	ctrl_in : 8'hff;
	    	        
	    	if (gf_idle_st) begin
	    		//if bcnt_fifo is not empty, i.e. there is atleast one packet
	    		gige_bcnt_fifo_re	<=	(!gf_bcnt_empty)? 1'b1 : 1'b0;
	    	end
			else if (gf_rd_bcnt_st) begin
				//bcnt read
				gige_bcnt_fifo_re	<=	1'b0;
			end
			else if (gf_bcnt_buf_st) begin
				//bcnt_in[15] indicates if the packet is sof4 type. calculate qwd_cnt from the bcnt.
				qwd_cnt				<=	((bcnt_in[15] == 1'b1) & ((|bcnt_in[2:0] == 3'b0) | (bcnt_in[2:0] > 3'b100)))?	(bcnt_in[14:3] + (|bcnt_in[2:0]) + 1'b1) :
											(bcnt_in[14:3] + (|bcnt_in[2:0]));										
			end
			else if (gf_rd_data_st) begin
				qwd_cnt				<=	(qwd_cnt == 16'b0)? 16'b0 : (qwd_cnt - 1'b1);
				gige_data_fifo_re	<=	(qwd_cnt == 16'b0)? 1'b0  : 1'b1;
			end
			else begin
				qwd_cnt				<=	16'b0;
				gige_bcnt_fifo_re	<=	1'b0;
				gige_data_fifo_re	<=	1'b0;
			end
	    	        					
		end
	 
	end	
	
	
	
	//============== Simulation ONLY =======================//
	//synopsys translate_off                                  
		                                                         
	reg [64*8-1:0] ascii_gf_state;                          
	                                                          
	always@(gf_state)                                       
	begin                                                     
		case(gf_state)                                         
	    	GF_IDLE   	:	ascii_gf_state	=	"GF_IDLE";        
			GF_RD_BCNT	:	ascii_gf_state	=	"GF_RD_BCNT";          
			GF_BCNT_BUF	:	ascii_gf_state	=	"GF_BCNT_BUF";          
			GF_RD_DATA	:	ascii_gf_state	=	"GF_RD_DATA";            
			GF_DONE   	:	ascii_gf_state	=	"GF_DONE";
		endcase                                                  
	end 
	     
	//synopsys translate_on
	
	

endmodule