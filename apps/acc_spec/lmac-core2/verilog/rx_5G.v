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


`timescale 1ns/1ns

module rx_5g(

	clk,              //i-1, Clock  
	reset_,           //i-1, reset   

	mode_10G,		  //i-1, speed modes
	mode_5G,		  //i-1, speed modes
	mode_2p5G, 		  //i-1, speed modes
	mode_1G,		  //i-1, speed modes
	                   
	data_in,           //i-64, Input data 
	ctrl_in,           //i-8, Input control
	                   
	data_out,          //o-64, Output data
	ctrl_out,          //o-8, output control 
	                   
	linkup_1g,         //o-1
	linkup_5g          //o-1
	
	);

		input  			clk				;			//i-1, Clock
		input  			reset_			;   		 //i-1, reset

		input			mode_10G 		;			//i-1, speed modes
		input			mode_5G  		;			//i-1,
		input			mode_2p5G		; 			//i-1,
		input			mode_1G  		;			//i-1, 
		
		input 	[63:0] 	data_in			;   		//i-64, Input data
		input 	[7:0] 	ctrl_in			;   		//i-8, Input control
		
		output 	[63:0] 	data_out		;   		//o-64, Output data
		output 	[7:0] 	ctrl_out		;   		//o-8, output control
		output 			linkup_1g		;   		 //o-1,
		output 			linkup_5g		;   	   //o-1,
		
		wire 	[63:0] 	data_out		;
		wire 	[7:0] 	ctrl_out		; 
		reg 			f_we			;
		
		wire 			x_bcnt_we_s2p	;      
		wire 	[15:0] 	x_byte_cnt_s2p	;
		wire 			x_bcnt_we_5g	;      
		wire 	[15:0] 	x_byte_cnt_5g	;
		wire 			x_we			;
		wire 			we_5g			;
		wire 	[63:0] 	data_out_s2p	;
		wire 	[7:0] 	ctrl_out_s2p	;
		wire 	[63:0] 	data_out_5g		;
		wire 	[7:0] 	ctrl_out_5g		;
		wire 	[63:0] 	data_out_ff		;
		wire 	[7:0] 	ctrl_out_ff		; 
		wire 			gf_bcnt_empty	;
		wire 	[15:0]	bcnt_in			;                               
		wire 			gige_bcnt_fifo_re;
		wire 			gige_data_fifo_re;
		
		reg 	[63:0] 	data_mux		;
		reg 	[7:0] 	ctrl_mux		; 
		reg 			x_bcnt_we		;       
		reg 	[15:0] 	x_byte_cnt		;

		reg				mode_10G_buf	; 		//buffer speed modes
		reg				mode_5G_buf 	;		 //buffer speed modes
		reg				mode_2p5G_buf 	;		//buffer speed modes
		reg				mode_1G_buf 	;		//buffer speed modes

		
	gige_s2p gige_s2p                          		 //S2P Module Instantiation
		(
			.clk			(clk),		
			.reset_			(reset_),	

			.mode_10G 		(mode_10G_buf), 		 //i-1, speed modes
			.mode_5G  		(mode_5G_buf), 			 //i-1,
			.mode_2p5G		(mode_2p5G_buf), 		 //i-1,
			.mode_1G  		(mode_1G_buf), 			  //i-1,
			
			.data_in		(data_in[7:0]),
			.ctrl_in		(ctrl_in[0]),
			.pdet_in		(ctrl_in[0]),
			            	            
			.data_out		(data_out_s2p),
			.ctrl_out		(ctrl_out_s2p),
			
			.loopback_en	(1'b0),		
			.sfp_los		(1'b0),		
			
			.linkup			(linkup_1g),	
			.x_we			(x_we), 	
			
			.x_bcnt_we		(x_bcnt_we_s2p),
			.x_byte_cnt		(x_byte_cnt_s2p)
		);
	
	ctrl_2g_5g ctrl_2g_5g                 		    //5G/2.5 speed control module instantiation
		(
    	
			.clk		(clk),
			.reset_		(reset_),

			.mode_10G 	(mode_10G_buf), 	 //i-1, speed modes
			.mode_5G  	(mode_5G_buf), 		 //i-1, 
			.mode_2p5G	(mode_2p5G_buf), 	  //i-1, 
			.mode_1G  	(mode_1G_buf), 		  //i-1, 
			
			.data_in	(data_in),
			.ctrl_in	(ctrl_in),
			
			.data_out	(data_out_5g),
			.ctrl_out	(ctrl_out_5g),
			.we_5g		(we_5g),
			.x_byte_cnt	(x_byte_cnt_5g),
			.x_bcnt_we	(x_bcnt_we_5g),
			.linkup_5g	(linkup_5g)
		
		);	

    gigerx_fifo256x64_2clk gigerx_fifo256x64_2clk  			//Gige RX fifo for data
		(                                          
			.aclr			(reset_),              
			                                       
			.wrclk			(clk),             //i, clock    
			.wrreq			(f_we),            //i, write request                
			.data			(data_mux),       //i              
			.full			(),       	                         
			        	                                   
			.rdclk			(clk),				 //i                        
			.rdreq			(gige_data_fifo_re),  //i             
			.q				(data_out_ff),			//o,                         
			.empty			(),  	 			                         
			.usedw			()					                            
		);                                           
	                                             
	                                             
	gigerx_fifo256x8 gigerx_fifo256x8         
		(                                     
			.aclr			(reset_),         		//i,
			                                  
			.wrclk			(clk),      	  		//i,
			.wrreq			(f_we),      	        //i,             
			.data			(ctrl_mux),	            //i,        
			.full			(),       		                        
			        	                                   
			.rdclk			(clk),				    //i,                     
			.rdreq			(gige_data_fifo_re),    //i,           
			.q				(ctrl_out_ff),			//o,                         
			.empty			(),  	 			                         
			.usedw			()       			                       
		);                                           
	                                             
	                                             
	gigerx_bcnt_fifo256x16 gigerx_bcnt_fifo256x16 
		(                                         
			.aclr			(reset_),             	 //i,
			                                      
			.wrclk			(clk),                     //i,         
			.wrreq			(x_bcnt_we),              //i,          
			.data			(x_byte_cnt),             //i,           
			.full			(),       	                         
			        	                                   
			.rdclk			(clk),				       //i,                   
			.rdreq			(gige_bcnt_fifo_re),        //i,        
			.q				(bcnt_in),			        //o,                 
			.empty			(gf_bcnt_empty),	        //o           
			.usedw			()       			         //o,               
		);                                           
	                                         
	                                         
	g2x_ctrl g2x_ctrl                        		 //Readout control from the fifo, to give as an output to the byte reordering module
		(                                    
		                                     		    
		    .clk			(clk),					   //i,
			.reset_			(reset_),				    //i,

			.mode_10G 		(mode_10G_buf), 		    //i,
			.mode_5G  		(mode_5G_buf), 			    //i,
			.mode_2p5G		(mode_2p5G_buf), 		    //i,
			.mode_1G  		(mode_1G_buf), 				 //i,
			                                
			.gf_bcnt_empty	(gf_bcnt_empty),
			                                		          
			.data_in		(data_out_ff),				  //i,                   
			.ctrl_in		(ctrl_out_ff),				   //i,                  
			.bcnt_in		(bcnt_in),		   			                    
			                                            
			.gige_bcnt_fifo_re	(gige_bcnt_fifo_re),     
			.gige_data_fifo_re	(gige_data_fifo_re),     
			                                            
			.data_out		(data_out),		              //o,  
			.ctrl_out		(ctrl_out),		               //o, 
			                                		          
			.dbg			()						                             
		);                                           
	
	
	always @ (posedge clk)
	begin
		mode_10G_buf	<=	mode_10G	;	
		mode_5G_buf 	<=	mode_5G 	;	
		mode_2p5G_buf	<=	mode_2p5G	;	
		mode_1G_buf 	<=	mode_1G 	;	
	end
		
			
	always @ (posedge clk)
		begin
		
			if (!reset_)
				begin
				
					f_we <= 1'b0;
					data_mux <= 64'h0707_0707_0707_0707;
					ctrl_mux <= 8'hff;
					x_byte_cnt <= 16'd0;
					x_bcnt_we <= 1'b0;
								
				end
			else
				begin
																				
					data_mux <= (mode_2p5G_buf | mode_5G_buf) ? data_out_5g :				//Register Mux for output data
						data_out_s2p                            				
						;										                  
																				
					ctrl_mux <=	(mode_2p5G_buf | mode_5G_buf) ? ctrl_out_5g :				//Register Mux for output control								
						ctrl_out_s2p                                              
						;											              
																				
					f_we <= (mode_2p5G_buf | mode_5G_buf) ? we_5g :							 //Write Mux	
						x_we                             
						;                                
							
					x_byte_cnt <= (mode_2p5G_buf | mode_5G_buf) ? x_byte_cnt_5g : 			 	//Byte count
						x_byte_cnt_s2p                             
						;                                                	
						      		
					x_bcnt_we <= (mode_2p5G_buf | mode_5G_buf) ? x_bcnt_we_5g :  				//Byte count write enable	
						x_bcnt_we_s2p                             
						;                                                	
						    													
				end
				
		end 	
				
endmodule	