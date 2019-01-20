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


`timescale 1ns/10ps

module fmac_fifo512x64_2clk 

(
			aclr,

			wrclk,                            // i,Clk for writing data                                    
			wrreq,                            // i,request to write                                        
			data,                             // i,Data coming in                                          
			wrfull,                           // o,indicates fifo is full or not (To avoid overiding)      
			wrempty,                          // o,indicates fifo is empty or not (to avoid underflow)        
			wrusedw,                          // o,number of slots currently in use for writting                                                                    
                                                                                                           
		    rdclk,                             // i,Clk for reading data                                   
			rdreq,                           	// i,Request to read from FIFO                               
			q,    	                         	// o,Data coming out                                         
			rdfull,                          	  // o,indicates fifo is full or not (To avoid overiding)     
			rdempty,                         	 // o,indicates fifo is empty or not (to avoid underflow)        
			rdusedw                          	  //o, number of slots currently in use for reading 

);

parameter 	  WIDTH = 64,
			  DEPTH = 512,
			  PTR	= 9;



			input wire aclr;

			input  wire 				wrclk;                       // i,Clk for writing data                                    
			input  wire 				wrreq;                       // i,request to write                                        
			input  wire [WIDTH-1 : 0]	data;                        // i,Data coming in                                          
			output wire					wrfull;                      // o,indicates fifo is full or not (To avoid overiding)      
			output wire 			 	wrempty;                     // o,indicates fifo is empty or not (to avoid underflow)                             
			output wire	[PTR : 0]		wrusedw;                     // o,number of slots currently in use for writting                                                                                         
                                                                                                                                  
		    input  wire 				rdclk;                        // i,Clk for reading data                                   
			input  wire 				rdreq;                      	// i,Request to read from FIFO                               
			output wire [WIDTH-1 : 0]	q;    		                	// o,Data coming out                                         
			output wire 				rdfull;                     	 // o,indicates fifo is full or not (To avoid overiding)   
			output wire 				rdempty;                    	  // o,indicates fifo is empty or not (to avoid underflow)       
			output wire [PTR  : 0] 		rdusedw;                    	    //o, number of slots currently in use for reading     
                                                                         



		   asynch_fifo	#(.WIDTH (64),	
					  	.DEPTH (512),
					 	.PTR	 (9) )	
 										
asynch_512x64_2clk		  (
			.reset_	(~aclr),
			
			.wrclk	(wrclk),			          // i,Clk for writing data                                 
			.wren	(wrreq),	   		          // i,request to write                                     
			.datain	(data),				          // i,Data coming in                                       
			.wrfull	(wrfull),			          // o,indicates fifo is full or not (To avoid overiding)   
			.wrempty(wrempty),			          // o,indicates fifo is empty or not (to avoid underflow)  
			.wrusedw(wrusedw),			          // o,number of slots currently in use for writting        


			.rdclk	(rdclk),			          // i,Clk for reading data                                   
			.rden	(rdreq),			         	// i,Request to read from FIFO                              
			.dataout(q),				         	// o,Data coming out                                        
			.rdfull	(rdfull),			         	 // o,indicates fifo is full or not (To avoid overiding)    
			.rdempty(rdempty),			         	  // o,indicates fifo is empty or not (to avoid underflow)  
			.rdusedw(rdusedw),			         	    //o, number of slots currently in use for reading       

			.dbg()

		 );
endmodule