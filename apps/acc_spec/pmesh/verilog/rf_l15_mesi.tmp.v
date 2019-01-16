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
//  Filename      : rf_l15_mesi.v
//  Created On    : 2014-02-04 18:14:58
//  Last Modified : 2014-12-17 16:09:50
//  Revision      :
//  Author        : Tri Nguyen
//  Company       : Princeton University
//  Email         : trin@princeton.edu
//
//  Description   :
//
//
//==================================================================================================
//rf_l15_mesi.v

//`timescale 1 ns / 10 ps
//`default_nettype none

// 12/17 timing fix: move write to s3

// /home/hongce/ila/openpiton/piton/verif/env/manycore/devices.xml

module rf_l15_mesi(
   input wire clk,
   input wire rst_n,

   input wire read_valid,
   input wire [`L15_CACHE_INDEX_WIDTH-1:0] read_index,

   input wire write_valid,
   input wire [`L15_CACHE_INDEX_WIDTH-1:0] write_index,
   input wire [7:0] write_mask,
   input wire [7:0] write_data,

   output wire [7:0] read_data
   );



// reg read_valid_f;
reg [`L15_CACHE_INDEX_WIDTH-1:0] read_index_f;
reg [`L15_CACHE_INDEX_WIDTH-1:0] write_index_f;
reg [7:0] write_data_f;
reg [7:0] write_mask_f;
reg write_valid_f;

reg [7:0] regfile [0:`L15_CACHE_INDEX_VECTOR_WIDTH-1];

always @ (posedge clk)
begin
   if (!rst_n)
   begin
      read_index_f <= 0;
   end
   else
   if (read_valid)
      read_index_f <= read_index;
   else
      read_index_f <= read_index_f;
end

// read port
assign read_data = regfile[read_index_f];

// Write port
always @ (posedge clk)
begin
   write_valid_f <= write_valid;
   if (write_valid)
   begin
      write_data_f <= write_data;
      write_index_f <= write_index;
      write_mask_f <= write_mask;
   end
end

always @ (posedge clk)
begin
   if (!rst_n)
   begin
      regfile[0] <= 8'b0;
regfile[1] <= 8'b0;
regfile[2] <= 8'b0;
regfile[3] <= 8'b0;
regfile[4] <= 8'b0;
regfile[5] <= 8'b0;
regfile[6] <= 8'b0;
regfile[7] <= 8'b0;
regfile[8] <= 8'b0;
regfile[9] <= 8'b0;
regfile[10] <= 8'b0;
regfile[11] <= 8'b0;
regfile[12] <= 8'b0;
regfile[13] <= 8'b0;
regfile[14] <= 8'b0;
regfile[15] <= 8'b0;
regfile[16] <= 8'b0;
regfile[17] <= 8'b0;
regfile[18] <= 8'b0;
regfile[19] <= 8'b0;
regfile[20] <= 8'b0;
regfile[21] <= 8'b0;
regfile[22] <= 8'b0;
regfile[23] <= 8'b0;
regfile[24] <= 8'b0;
regfile[25] <= 8'b0;
regfile[26] <= 8'b0;
regfile[27] <= 8'b0;
regfile[28] <= 8'b0;
regfile[29] <= 8'b0;
regfile[30] <= 8'b0;
regfile[31] <= 8'b0;
regfile[32] <= 8'b0;
regfile[33] <= 8'b0;
regfile[34] <= 8'b0;
regfile[35] <= 8'b0;
regfile[36] <= 8'b0;
regfile[37] <= 8'b0;
regfile[38] <= 8'b0;
regfile[39] <= 8'b0;
regfile[40] <= 8'b0;
regfile[41] <= 8'b0;
regfile[42] <= 8'b0;
regfile[43] <= 8'b0;
regfile[44] <= 8'b0;
regfile[45] <= 8'b0;
regfile[46] <= 8'b0;
regfile[47] <= 8'b0;
regfile[48] <= 8'b0;
regfile[49] <= 8'b0;
regfile[50] <= 8'b0;
regfile[51] <= 8'b0;
regfile[52] <= 8'b0;
regfile[53] <= 8'b0;
regfile[54] <= 8'b0;
regfile[55] <= 8'b0;
regfile[56] <= 8'b0;
regfile[57] <= 8'b0;
regfile[58] <= 8'b0;
regfile[59] <= 8'b0;
regfile[60] <= 8'b0;
regfile[61] <= 8'b0;
regfile[62] <= 8'b0;
regfile[63] <= 8'b0;
regfile[64] <= 8'b0;
regfile[65] <= 8'b0;
regfile[66] <= 8'b0;
regfile[67] <= 8'b0;
regfile[68] <= 8'b0;
regfile[69] <= 8'b0;
regfile[70] <= 8'b0;
regfile[71] <= 8'b0;
regfile[72] <= 8'b0;
regfile[73] <= 8'b0;
regfile[74] <= 8'b0;
regfile[75] <= 8'b0;
regfile[76] <= 8'b0;
regfile[77] <= 8'b0;
regfile[78] <= 8'b0;
regfile[79] <= 8'b0;
regfile[80] <= 8'b0;
regfile[81] <= 8'b0;
regfile[82] <= 8'b0;
regfile[83] <= 8'b0;
regfile[84] <= 8'b0;
regfile[85] <= 8'b0;
regfile[86] <= 8'b0;
regfile[87] <= 8'b0;
regfile[88] <= 8'b0;
regfile[89] <= 8'b0;
regfile[90] <= 8'b0;
regfile[91] <= 8'b0;
regfile[92] <= 8'b0;
regfile[93] <= 8'b0;
regfile[94] <= 8'b0;
regfile[95] <= 8'b0;
regfile[96] <= 8'b0;
regfile[97] <= 8'b0;
regfile[98] <= 8'b0;
regfile[99] <= 8'b0;
regfile[100] <= 8'b0;
regfile[101] <= 8'b0;
regfile[102] <= 8'b0;
regfile[103] <= 8'b0;
regfile[104] <= 8'b0;
regfile[105] <= 8'b0;
regfile[106] <= 8'b0;
regfile[107] <= 8'b0;
regfile[108] <= 8'b0;
regfile[109] <= 8'b0;
regfile[110] <= 8'b0;
regfile[111] <= 8'b0;
regfile[112] <= 8'b0;
regfile[113] <= 8'b0;
regfile[114] <= 8'b0;
regfile[115] <= 8'b0;
regfile[116] <= 8'b0;
regfile[117] <= 8'b0;
regfile[118] <= 8'b0;
regfile[119] <= 8'b0;
regfile[120] <= 8'b0;
regfile[121] <= 8'b0;
regfile[122] <= 8'b0;
regfile[123] <= 8'b0;
regfile[124] <= 8'b0;
regfile[125] <= 8'b0;
regfile[126] <= 8'b0;
regfile[127] <= 8'b0;

      // regfile <= 1024'b0;
   end
   else
   if (write_valid_f)
   begin
      // regfile[write_index] <= (write_data & write_mask) | (regfile[write_index] & ~write_mask);
      regfile[write_index_f] <= (write_data_f & write_mask_f) | (regfile[write_index_f] & ~write_mask_f);
   end
end
endmodule
