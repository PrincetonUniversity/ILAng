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

`timescale 1ns / 1ps
module asynch_fifo # (parameter WIDTH = 8,         // considering 8X8 fifo
								DEPTH = 16,
								PTR	= 4 )          // 2**3 = 8 (DEPTH)

(
			input wire 					reset_,
			//=== Signals for WRITE
			input  wire 				wrclk,        // Clk for writing data
			input  wire 				wren,         // request to write 
			input  wire [WIDTH-1 : 0]	datain,       // Data coming in 
			output reg					wrfull,       // indicates fifo is full or not (To avoid overiding)
			output reg 			 		wrempty,      // 0- some data is present (atleast 1 data is present)                                          
			output reg	[PTR  : 0]		wrusedw,      // number of slots currently in use for writing                                                                                                
                                                    
			
			//=== Signals for READ

            input  wire 				rdclk,        // Clk for reading data    
			input  wire 				rden,         // Request to read from FIFO 
			output reg [WIDTH-1 : 0]	dataout,      // Data coming out 
			output wire 				rdfull,       // 1-FIFO IS FULL (DATA AVAILABLE FOR READ is == DEPTH)
			output reg 					rdempty,      // indicates fifo is empty or not (to avoid underflow)
			output reg [PTR  : 0] 		rdusedw,      // number of slots currently in use for reading

			output 	 		dbg						  //For Debug

);



//=== INTERNAL SIGNALS
reg	[PTR  : 0]		wrusedw_i;	//async version
reg	[PTR  : 0]		rdusedw_i;	//async version

reg [PTR : 0 ] wr_ptr, rd_ptr;
reg [PTR : 0 ] rd_ptr_d , wr_ptr_d  ;		
reg [PTR : 0 ] rd_ptr_d1, wr_ptr_d1 ;

reg [PTR : 0] ptr_diff;

reg [PTR : 0 ] wr_cnt, rd_cnt;

// MEMORY FOR FIFO USING REG
reg [WIDTH-1 : 0] mem[DEPTH-1:0] ;

assign	dbg	=	1'b0;

// MEMORY FOR FIFO USING REG
always @(wr_ptr,rd_ptr,wrusedw,rdusedw,wren,rden,reset_)
	begin
	
		//need to rise quickly to avoid false writing
		//wrusedw is sync to wrclk
		wrfull =    !reset_ ? 1'b0 : // for full 1 for empty 0
			(wrusedw >= DEPTH) 
			;
		wrempty =    !reset_ ? 1'b1 : // for full 1 for empty 0
			(wrusedw <= 0) 
			;
					
			//dependednt on wrusedw to avoid false reading
		rdusedw_i = 
			!reset_ ? 0 :
			!wrfull ?  wrusedw : DEPTH ;			
			
		rdempty =   !reset_ ? 1'b1 : // for full 0 for empty 1
			(rdusedw <= 0) 
			;
						
	end

always @(wr_ptr, rd_ptr)
begin
	
	ptr_diff = wr_ptr > rd_ptr ? wr_ptr - rd_ptr:
		   wr_ptr < rd_ptr ? rd_ptr - wr_ptr:
		   wr_ptr == rd_ptr ? 0 :
		   ptr_diff;
	
	// may add quickly on wr
	// may sub slowly on rd		   
	wrusedw_i =	
			!reset_ ? 0 :
			wren & rden ? (wrusedw == 0 ? 1'b1 : wrusedw) :  
			wr_ptr < rd_ptr ? DEPTH - ptr_diff :
		    wr_ptr > rd_ptr ? ptr_diff :
		    wr_ptr == rd_ptr ? (
		    	(wr_ptr_d > wr_ptr) & ( wrusedw==3)  ? DEPTH  : 			    	
		    	(wr_ptr_d < rd_ptr) & ( rd_ptr_d < rd_ptr)  ? 4'h0  : 
		    	(rd_ptr_d < wr_ptr) | (rd_ptr_d1 < wr_ptr)  ? 4'b0  :
		    	(rd_ptr_d > wr_ptr) 						? 4'b0  : 	
		    	(wr_ptr_d < rd_ptr) | ( wr_ptr_d1 < rd_ptr) ? DEPTH  : 	
		    	wrusedw)  :
		    wrusedw_i ;
end	

assign rdfull  = wrfull ? 1'b1 : 1'b0;                     

//=== WRITE INTO FIFO
	always @(wrclk, wrusedw_i )
		begin
		if (!reset_ & !wrclk )
			begin
			wrusedw 	<= 0;
			end
		else
			begin
			wrusedw 	<= 
				!wrclk ? wrusedw_i :
				wrusedw ;
			end
			
		end	

	always @(posedge wrclk)
	begin
		if (!reset_)
			begin
			wr_ptr 	  	<= 0;
			wr_ptr_d  	<= 0;
			wr_ptr_d1 	<= 0;
			wr_cnt 		<= 0;
			end
		else
			begin
			wr_ptr 	   	<=  wren ? (!wrfull ? (wr_ptr >= DEPTH  ? 1 : wr_ptr + 1) : wr_ptr  ) :
					  		wr_ptr;
			
			mem [0]		<= 	wren ? (!wrfull ? (wr_ptr == DEPTH | 0 ? datain : mem[0]) : mem[0] ):
							mem[0];
							  		  
			mem[wr_ptr] <= 	wren & rden ? datain : 
							wren ? (!wrfull ? datain : mem[wr_ptr]) :             
						   	mem[wr_ptr];			   

			wr_cnt <= wren ? (!wrfull ? wr_cnt + 1 : wr_cnt) :
					  wr_cnt;
						   	
			wr_ptr_d  <= wr_ptr;
			wr_ptr_d1 <= wr_ptr_d;
			end

	end
//=== READ FROM FIFO

	always @(rdclk, rdusedw_i )
		begin
		if (!reset_ & !rdclk )
			begin
			
			rdusedw 	<= 0;
			end
		else
			begin
			rdusedw 	<= 
				!rdclk ? rdusedw_i :
				rdusedw ;
			end
			
		end	


	always @(posedge rdclk)
	begin
		if (!reset_)
			begin
			rd_ptr 		<= 0;
			rd_ptr_d  	<= 0;
			rd_ptr_d1 	<= 0;
			dataout 	<= 0;
			rd_cnt  	<= 0;
			
			end
	else
			begin
			rd_ptr <= rden ? (!rdempty  ? (rd_ptr == DEPTH ?  8'd1 : rd_ptr + 8'd1 ): rd_ptr  ): 
					  rd_ptr;      
					                                                              
  			dataout <= 
  						wren & rden ? 
  							(rd_ptr <= (DEPTH - 1)  ? mem[rd_ptr]  : 
  							(rd_ptr == DEPTH) & !rdempty ? mem[0]  : 
  							dataout ) :
  						rden ? (rd_ptr <= DEPTH - 1  ? mem[rd_ptr]  : rd_ptr == DEPTH & !rdempty ? mem[0] : dataout ) :
  					  	dataout;                                                              			

  			rd_cnt <= rden ? ( !rdempty ? rd_cnt + 1 : rd_cnt ) :
  					  rd_cnt;
  							
			rd_ptr_d  <= rd_ptr;
			rd_ptr_d1 <= rd_ptr_d;
			
			end

	end

endmodule




