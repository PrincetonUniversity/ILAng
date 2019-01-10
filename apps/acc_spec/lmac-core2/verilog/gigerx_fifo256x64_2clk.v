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


module gigerx_fifo256x64_2clk

(
			aclr,

			wrclk,                  // i,Clk for writing data                                  
			wrreq,                  // i,request to write                                      
			data,                   // i,Data coming in                                        
			full,                   // o,indicates fifo is full or not (To avoid overiding)    
		                                                                                       
			rdclk,	                // i,Clk for reading data                                  
			rdreq,                  // i,Request to read from FIFO                             
			q, 	                    // o,Data coming out                                       
			empty,                   // o,indicates fifo is empty or not (to avoid underflow)  
			usedw                     //o, number of slots currently in use for reading        

);
	parameter WIDTH = 64,
			  DEPTH = 256,
			  PTR	= 8;
			  
			  
			input wire aclr;

			input  wire 				wrclk;          // Clk for writing data                                    
			input  wire 				wrreq;          // request to write                                        
			input  wire [WIDTH-1 : 0]	data;           // Data coming in                                                    
			output wire					full;           // indicates fifo is full or not (To avoid overiding)      
		                                                                                                           
			input  wire 				rdclk;          // Clk for read data                                                            
			input  wire 				rdreq;           // Request to read from FIFO                                                                                      
			output wire [WIDTH-1 : 0]	q; 	             // Data coming out                                                                                                
			output wire 				empty;           // indicates fifo is empty or not (to avoid underflow)                                       
			output wire [PTR  : 0] 		usedw;           // number of slots currently in use for reading           
                                                           
			                                               
                                                           
asynch_fifo	#(.WIDTH (WIDTH),		  			
					  	  .DEPTH (DEPTH),
					 	  .PTR	 (PTR) )		 
 											
	asynch_256x64		  (
			.reset_	(aclr),
			
			.wrclk	(wrclk),		                      // Clk to write data                                            
			.wren	(wrreq),	   	                      // write enable                                                 
			.datain	(data),			                      // write data                                                   
			.wrfull	(full),			                      // indicates fifo is full or not (To avoid overiding)           
			.wrempty(),				                      // indicates fifo is empty or not (to avoid underflow)          
			.wrusedw(),				                      // wrusedw -number of locations filled in fifo                  
                                                                                                                          
			.rdclk	(rdclk),		                                                                                      
			.rden	(rdreq),		                      // i-1, Clk to read data                                        
			.dataout(q),			                      // i-1, read enable of data FIFO                                
			.rdfull	(),				                      // Dataout of data FIFO                                         
			.rdempty(empty),		                      // indicates fifo is full or not (To avoid overiding) (Not used)
			.rdusedw(usedw),		                      // indicates fifo is empty or not (to avoid underflow)          
                                                          // rdusedw -number of locations filled in fifo (not used )      
			.dbg()

		 );
endmodule