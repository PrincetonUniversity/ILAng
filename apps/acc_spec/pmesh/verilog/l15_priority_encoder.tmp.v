/*
Copyright (c) 2015 Princeton University
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Princeton University nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY PRINCETON UNIVERSITY "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL PRINCETON UNIVERSITY BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//==================================================================================================
//  Filename      : l15_priority_encoder.v
//  Created On    : 2014-07-09
//  Revision      :
//  Author        : Yaosheng Fu
//  Company       : Princeton University
//  Email         : yfu@princeton.edu
//
//  Description   : The priority encoder for pipeline1 in the L15 cache
//
//
//==================================================================================================


`include "l15.tmp.h"
`include "define.tmp.h"




module l15_priority_encoder_1(
    input wire [1:0] data_in,
    output wire [0:0] data_out,
    output wire [1:0] data_out_mask,
    output wire nonzero_out
);

assign data_out = data_in[0] ? 1'b0 : 1'b1;
assign data_out_mask = data_in[0] ? 2'b10 : 2'b01;
assign nonzero_out = | (data_in[1:0]);
endmodule

module l15_priority_encoder_2(
    input wire [3:0] data_in,
    output wire [1:0] data_out,
    output wire [3:0] data_out_mask,
    output wire nonzero_out
);

wire [0:0] data_low;

wire [0:0] data_high;

wire [1:0] data_low_mask;

wire [1:0] data_high_mask;

wire nonzero_low;

wire nonzero_high;

l15_priority_encoder_1 encoder_high_1 (.data_in(data_in[3:2]), .data_out(data_high), .data_out_mask(data_high_mask), .nonzero_out(nonzero_high));

l15_priority_encoder_1 encoder_low_1(.data_in(data_in[1:0]), .data_out(data_low), .data_out_mask(data_low_mask), .nonzero_out(nonzero_low));

assign data_out = nonzero_low ? {1'b0, data_low} : {1'b1, data_high};

assign data_out_mask = nonzero_low ? {{2{1'b1}}, data_low_mask} : {data_high_mask,{2{1'b1}}};

assign nonzero_out = nonzero_low | nonzero_high;
endmodule

module l15_priority_encoder_3(
    input wire [7:0] data_in,
    output wire [2:0] data_out,
    output wire [7:0] data_out_mask,
    output wire nonzero_out
);

wire [1:0] data_low;

wire [1:0] data_high;

wire [3:0] data_low_mask;

wire [3:0] data_high_mask;

wire nonzero_low;

wire nonzero_high;

l15_priority_encoder_2 encoder_high_2 (.data_in(data_in[7:4]), .data_out(data_high), .data_out_mask(data_high_mask), .nonzero_out(nonzero_high));

l15_priority_encoder_2 encoder_low_2(.data_in(data_in[3:0]), .data_out(data_low), .data_out_mask(data_low_mask), .nonzero_out(nonzero_low));

assign data_out = nonzero_low ? {1'b0, data_low} : {1'b1, data_high};

assign data_out_mask = nonzero_low ? {{4{1'b1}}, data_low_mask} : {data_high_mask,{4{1'b1}}};

assign nonzero_out = nonzero_low | nonzero_high;
endmodule

module l15_priority_encoder_4(
    input wire [15:0] data_in,
    output wire [3:0] data_out,
    output wire [15:0] data_out_mask,
    output wire nonzero_out
);

wire [2:0] data_low;

wire [2:0] data_high;

wire [7:0] data_low_mask;

wire [7:0] data_high_mask;

wire nonzero_low;

wire nonzero_high;

l15_priority_encoder_3 encoder_high_3 (.data_in(data_in[15:8]), .data_out(data_high), .data_out_mask(data_high_mask), .nonzero_out(nonzero_high));

l15_priority_encoder_3 encoder_low_3(.data_in(data_in[7:0]), .data_out(data_low), .data_out_mask(data_low_mask), .nonzero_out(nonzero_low));

assign data_out = nonzero_low ? {1'b0, data_low} : {1'b1, data_high};

assign data_out_mask = nonzero_low ? {{8{1'b1}}, data_low_mask} : {data_high_mask,{8{1'b1}}};

assign nonzero_out = nonzero_low | nonzero_high;
endmodule




