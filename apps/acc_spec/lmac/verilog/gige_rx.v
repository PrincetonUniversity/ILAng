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

module gige_rx 
	(
	
	clk,		    // i-1                                                                                             
	reset_,			// i-1
	fmac_speed,	    // i-2                                                                                         
	                                                                                    
	data_in_s2p,    // i-8                                                                                  
	ctrl_in_s2p,    // i-1                                                                                 
	pdet_in_s2p,	// i-1
	gmii_rx_dv,	    // i-1                                                                                          
	                                                                                    
	loopback_en,     // i-1                                                                                                 
	sfp_los,	     // i-1                                                                                                    

	gige_rx_dout,	 // o-64
	gige_rx_cout,	 // o-8
	
	linkup,      	 // o-1
	
	dbg        		 // o-1
	
	);
		
	  
	input 				clk;		        // i-1                                                               
	input 				reset_;				// i-1
	input	[ 1:0]		fmac_speed;	        // i-2                                                        
	 				                                                            
	input	[ 7:0]		data_in_s2p;         // i-8                                                  
	input 				ctrl_in_s2p;         // i-1                                                   
	input 				pdet_in_s2p;		// i-1
	input				gmii_rx_dv;	         // i-1                                                   
	 				                                                            
	input 				loopback_en;         // i-1                                                                   
	input 				sfp_los;	         // i-1                                                                      
	
	output	[63:0]		gige_rx_dout;		 // o-64
	output	[ 7:0]		gige_rx_cout;		 // o-8
	
	output				linkup;				 // o-1
	
	output				dbg;	
	
		
	wire				dbg = 0;		
	
	wire	[63:0]		data_out_s2p;		  //to the g_fifo
	wire	[ 7:0]		ctrl_out_s2p;		  //to the g_fifo
	
	wire				linkup;
	wire				x_we; 				  //to the g_fifo
	
	wire				x_bcnt_we;
	wire	[15:0]		x_byte_cnt;

	wire				gf_bcnt_empty;
	
	wire	[63:0]		data_in;
	wire	[ 7:0]		ctrl_in;
	wire	[15:0]		bcnt_in;
	
	wire				gige_bcnt_fifo_re;
	wire				gige_data_fifo_re;
	
	
	
	gige_s2p gige_s2p 
	(
		.clk			(clk),				// i-1
		.reset_			(reset_),			// i-1
		.fmac_speed		(fmac_speed),		// i-2
		
		.data_in		(data_in_s2p),		// i-8
		.ctrl_in		(ctrl_in_s2p),		// i-1
		.pdet_in		(pdet_in_s2p),		// i-1
		.gmii_rx_dv		(gmii_rx_dv),		// i-1
		            	            
		.data_out		(data_out_s2p),		// o-64
		.ctrl_out		(ctrl_out_s2p),		// o-8
		
		.loopback_en	(1'b0),				// i-1
		.sfp_los		(1'b0),				// i-1
		
		.linkup			(linkup),			// o-1
		.x_we			(x_we), 			// o-1
		
		.x_bcnt_we		(x_bcnt_we),		// o-1
		.x_byte_cnt		(x_byte_cnt)		// o-1
	);
	
	
	gigerx_fifo256x64_2clk gigerx_fifo256x64_2clk
	(
		.aclr			(reset_),
		 
		.wrclk			(clk),      	 // Clk for writing data
		.wrreq			(x_we),      	 // request to write 
		.data			(data_out_s2p),  // Data coming in                   
		.full			(),       	
		        	                         
		.rdclk			(clk),				// rd clock
		.rdreq			(gige_data_fifo_re),  // Request to read from FIFO
		.q				(data_in),			  // Data coming out
		.empty			(),  	 			
		.usedw			()					
	);


	gigerx_fifo256x8 gigerx_fifo256x8
	(
		.aclr			(reset_),
		 
		.wrclk			(clk),      		// Clk for writing data
		.wrreq			(x_we),      		// request to write
		.data			(ctrl_out_s2p),	    // Data coming in               
		.full			(),       		
		        	                         
		.rdclk			(clk),				  // rd clock
		.rdreq			(gige_data_fifo_re),  // Request to read from FIFO
		.q				(ctrl_in),			  // Data coming out 
		.empty			(),  	 			
		.usedw			()       			
	);
	
	
	gigerx_bcnt_fifo256x16 gigerx_bcnt_fifo256x16
	(
		.aclr			(reset_),
		 
		.wrclk			(clk),         // Clk for writing data
		.wrreq			(x_bcnt_we),   // request to write
		.data			(x_byte_cnt),  // Data coming in              
		.full			(),       	
		        	                      
		.rdclk			(clk),				  // rd clock
		.rdreq			(gige_bcnt_fifo_re),  // Request to read from FIFO
		.q				(bcnt_in),			  // Data coming out
		.empty			(gf_bcnt_empty),	  // indicates fifo is empty or not (to avoid underflow)
		.usedw			()       			
	);


	g2x_ctrl g2x_ctrl
	(
	            
	    .clk			(clk),				// i-1	
		.reset_			(reset_),			// i-1	
		.fmac_speed		(fmac_speed),		// i-2	
		                                		
		.gf_bcnt_empty	(gf_bcnt_empty),	// i-1	
		                                		
		.data_in		(data_in),			// i-64	
		.ctrl_in		(ctrl_in),			// i-8	
		.bcnt_in		(bcnt_in),			// i-16	
		
		.gige_bcnt_fifo_re	(gige_bcnt_fifo_re),   // o-1
		.gige_data_fifo_re	(gige_data_fifo_re),   // o-1
		
		.data_out		(gige_rx_dout),		// o-64	
		.ctrl_out		(gige_rx_cout),		// o-8	
		                                		
		.dbg			()						
	);

	

endmodule