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
            
    clk,				// i-1
	reset_,				// i-1
	fmac_speed,			// i-2
	
	gf_bcnt_empty,		// i-1
	
	data_in,			// i-64
	ctrl_in,			// i-8
	bcnt_in,			// i-16
	
	gige_bcnt_fifo_re,	// o-1
	gige_data_fifo_re,	// o-1
	
	data_out,			// o-64
	ctrl_out,			// o-8
	            		
	dbg					// o-1, test
);

	input       		clk;                // i-1      
	input				reset_;             // i-1      
	input		[ 1:0]	fmac_speed;         // i-2      
	                                                    
	input				gf_bcnt_empty;      // i-1      
	                                                    
	input		[63:0]	data_in;            // i-64     
	input		[ 7:0] 	ctrl_in;            // i-8      
	input		[15:0] 	bcnt_in;            // i-16     
	        	                                        
	output	reg 		gige_bcnt_fifo_re;	// o-1      
	output	reg 		gige_data_fifo_re;  // o-1      
	                                                    
	output	reg	[63:0]	data_out;           // o-64     
	output	reg	[ 7:0] 	ctrl_out;           // o-8      
	                                                    
	output  reg 		dbg;                // o-1, test

	reg			[15:0] 	qwd_cnt;			//counts the number of QWD for every packet
	reg 				gige_data_fifo_re_dly1;

			
	//State Machine to read from the gige_rx_bcnt_fifo
	reg		[7:0] 	gf_state;
	
	wire			gf_idle_st;			//IDLE
	wire			gf_rd_bcnt_st;      //read BCNT from bcnt_fifo
	wire			gf_bcnt_buf_st;     //buffer state one clk
	wire			gf_rd_data_st;      //read data
	wire			gf_done_st;         //DONE
	
		
	parameter [7:0]       
			GF_IDLE   		= 	8'h01,  
			GF_RD_BCNT		= 	8'h02, 
			GF_BCNT_BUF		= 	8'h04, 
			GF_RD_DATA	    = 	8'h08,		
			GF_DONE   		= 	8'h80;    
	
				
	assign	gf_idle_st		= 	gf_state[0];   
	assign  gf_rd_bcnt_st	= 	gf_state[1];             
	assign  gf_bcnt_buf_st	= 	gf_state[2];             
	assign	gf_rd_data_st	= 	gf_state[3];   
	assign	gf_done_st		= 	gf_state[7];
		
	
	always @ (posedge clk) begin             
	               	                                
		if (!reset_) begin   
		                       
			gf_state			<=	GF_IDLE ; 
			
			dbg					<=	1'b0;
		     
		end  
		                          
		else begin                          
		                               
			if (gf_idle_st)              
					//if bcnt_fifo is not empty, then there is at least one packet
					gf_state	<=	(!gf_bcnt_empty)? GF_RD_BCNT : GF_IDLE;                            
					                             					                             
			else if (gf_rd_bcnt_st)
					//read bcnt              
					gf_state	<=	GF_BCNT_BUF;
					  
			else if (gf_bcnt_buf_st) 
					//keep bcnt for one clock             
					gf_state	<=	GF_RD_DATA;  
											
			else if (gf_rd_data_st)  
					//read_data till its done                        
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
			gige_bcnt_fifo_re	<=	1'b0;
			gige_data_fifo_re	<=	1'b0;
			
			gige_data_fifo_re_dly1	<=	1'b0;
	                
		end
	    else begin

	    	gige_data_fifo_re_dly1	<=	gige_data_fifo_re;
	    
	    	//data and ctrl out depend on read_en_dly
	    	data_out			<=	(gige_data_fifo_re_dly1)?	data_in : 64'h0707_0707_0707_0707;
	        ctrl_out			<=	(gige_data_fifo_re_dly1)?	ctrl_in : 8'hff;
	    	        
	    	if (gf_idle_st) begin
	    		gige_bcnt_fifo_re	<=	(!gf_bcnt_empty)? 1'b1 : 1'b0;
	    	end
			else if (gf_rd_bcnt_st) begin
				gige_bcnt_fifo_re	<=	1'b0;
			end
			else if (gf_bcnt_buf_st) begin
				//count the number of quad-words from the byte_count value
				qwd_cnt				<=	(bcnt_in[15:3] + (|bcnt_in[2:0]));
			end
			else if (gf_rd_data_st) begin
				//decrement qwd_cnt after reading data
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