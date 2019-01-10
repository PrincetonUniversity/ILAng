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
`timescale 1ns / 1ps
// synopsys translate_on

module fmac_saddr_filter
(
clk,					// i-1
rst_,					// i-1
mcast_en,
mcast_saddr,			  // i-128
mac_saddr,				   // i-128
mac_saddr_vld,			  // i-1
saddr_filter_drop		  // o-1
);


input    clk;			 // i-1
input    rst_;			 // i-1

input        mcast_en ;
input [47:0] mcast_saddr;

input [47:0] mac_saddr;
input         mac_saddr_vld;

output  saddr_filter_drop ;


reg match0;
reg match1;
reg match2;
reg match3;
reg match4;
reg match5;

reg saddr_filter_drop ;

// Comparators

always@(posedge clk)
begin
	if(!rst_)
	begin
		match0 <= 1'b0 ;	
		match1 <= 1'b0 ;	
		match2 <= 1'b0 ;	
		match3 <= 1'b0 ;	
		match4 <= 1'b0 ;	
		match5 <= 1'b0 ;	
	end
	else
	begin
		match0 <= mac_saddr_vld ? (mac_saddr[47:40]   == mcast_saddr[47:40])    : 1'b0 ;
		match1 <= mac_saddr_vld ? (mac_saddr[39:32]   == mcast_saddr[39:32])   : 1'b0 ;
		match2 <= mac_saddr_vld ? (mac_saddr[31:24]   == mcast_saddr[31:24])   : 1'b0 ;
		match3 <= mac_saddr_vld ? (mac_saddr[23:16]   == mcast_saddr[23:16])   : 1'b0 ;
		match4 <= mac_saddr_vld ? (mac_saddr[15:08]   == mcast_saddr[15:08])   : 1'b0 ;
		match5 <= mac_saddr_vld ? (mac_saddr[07:00]   == mcast_saddr[07:00])   : 1'b0 ;
	end
end


 // SADDR Filter

reg [2:0] saddr_filter_st ;

parameter [2:0]
	 SADDR_FILTER_IDLE= 3'b001,
	 SADDR_FILTER_CHK=		3'b010,
	 SADDR_FILTER_END=		3'b100;
	 
always@(posedge clk)
begin
	if(!rst_)
	begin
		saddr_filter_st <= SADDR_FILTER_IDLE ;
		saddr_filter_drop <= 1'b0 ;
	end
	else
	begin
		case(saddr_filter_st)
		
		SADDR_FILTER_IDLE:
		begin
			saddr_filter_st <= mac_saddr_vld ? SADDR_FILTER_CHK : SADDR_FILTER_IDLE ;
		end
		
		SADDR_FILTER_CHK:
		begin
			saddr_filter_st <= SADDR_FILTER_END ;
			saddr_filter_drop <= !mcast_en ?  1'b0 : 
					     ( match0 & match1 &
						match2 & match3 &
						match4 & match5 ) ? 1'b0 : 1'b1 ;
		end		
	
		SADDR_FILTER_END:
		begin
			saddr_filter_st <= SADDR_FILTER_IDLE ;
			saddr_filter_drop <= 1'b0 ;
		end
		
		default:
		begin
			saddr_filter_st <= SADDR_FILTER_IDLE ;
		end
		endcase
	end
end




endmodule