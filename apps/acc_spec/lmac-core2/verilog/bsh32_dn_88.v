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
`timescale 1ns/1ps
// synopsys translate_on


module bsh32_dn_88 (
	shft,	//i,
	din,	//i,
	dout	//o,
);

   input  [1:0]                  shft; 
   input  [87:0]                 din; 
   output [87:0]                 dout; 

   wire [87:0]                   shft_data_s0;
   wire [87:0]                   shft_data_s1;

 assign shft_data_s0[88-1:0] = shft[0] ? (din >> 32) : din[88-1:0];
 assign shft_data_s1[88-1:0] = shft[1] ? (shft_data_s0 >> 64) : shft_data_s0;

//signal remap
 assign dout[88-1:0] = shft_data_s1; 

endmodule


