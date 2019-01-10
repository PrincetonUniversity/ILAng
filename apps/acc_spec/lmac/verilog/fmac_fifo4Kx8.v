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


module fmac_fifo4Kx8

(
			aclr,
			//=== Signals for WRITE
			
			wrclk,      							// Clk for writing data                              
			wrreq,      							// request to write 
			data,     								// Data coming in                                                                    
			wrfull,     							// indicates fifo is full or not (To avoid overiding)
		    wrempty,  								// indicates fifo is empty or not (to avoid underflow)                                                                                                      
            wrusedw,      							// number of slots currently in use for writting                                     

			//=== Signals for READ
            
		    rdclk,       							// Clk for reading data                     
			rdreq,       							// Request to read from FIFO                           
			q, 	    	 							// Data coming out                                     
			rdempty,  	 							// indicates fifo is empty or not (to avoid underflow)  
			rdusedw,      							// number of slots currently in use for reading
			rdfull     								// indicates fifo is full or not (To avoid overiding)
			
);


	parameter WIDTH = 8,
			  DEPTH = 4096,
			  PTR	= 12;
			  
			  
			input  wire 				aclr;
			//=== Signals for WRITE
			
			input  wire 				wrclk;      // Clk for writing data                              
			input  wire 				wrreq;      // request to write 
			input  wire [WIDTH-1 : 0]	data;     	// Data coming in                                                                    
			output wire					wrfull;     // indicates fifo is full or not (To avoid overiding)
			output wire 			    wrempty;  	// indicates fifo is empty or not (to avoid underflow) 		                                       
			output wire	[PTR : 0]		wrusedw;    // number of slots currently in use for writting 
			
			//=== Signals for READ
			
		    input  wire 				rdclk;      // Clk for reading data                   
			input  wire 				rdreq;      // Request to read from FIFO                           
			output wire [WIDTH-1 : 0]	q; 	    	// Data coming out                                     
			output wire 				rdempty;  	// indicates fifo is empty or not (to avoid underflow)  
			output wire [PTR : 0] 	rdusedw;     	// number of slots currently in use for reading
			output wire 				rdfull;     // indicates fifo is full or not (To avoid overiding)


	asynch_fifo 	#(.WIDTH (8),		   			// Making 4096X8 fifo
					  		  .DEPTH (4096),
					 		  .PTR	 (12) )		  	// 2**12 = 4096 (DEPTH)
 								
    async_4Kx8 (
			.reset_	(~aclr),
			
			//=== Signals for WRITE
			.wrclk	(wrclk),						// Clk to write data
			.wren	(wrreq),	   					// write enable
			.datain	(data),							// write data
			.wrfull	(wrfull),						// indicates fifo is full or not (To avoid overiding)
			.wrempty(wrempty),						// indicates fifo is empty or not (to avoid underflow)
			.wrusedw(wrusedw),						// wrusedw -number of locations filled in fifo


			//=== Signals for READ
			.rdclk	(rdclk),						// i-1, Clk to read data
			.rden	(rdreq),						// i-1, read enable of data FIFO
			.dataout(q),							// Dataout of data FIFO
			.rdfull	(rdfull),						// indicates fifo is full or not (To avoid overiding) (Not used)
			.rdempty(rdempty),						// indicates fifo is empty or not (to avoid underflow)
			.rdusedw(rdusedw),						// rdusedw -number of locations filled in fifo (not used )

			//=== Signals for TEST
			.dbg()

		 );
endmodule