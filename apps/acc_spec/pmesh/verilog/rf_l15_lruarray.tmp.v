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
//  Filename      : rf_l15_lruarray.v
//  Created On    : 2014-02-04 18:14:58
//  Last Modified : 2014-02-13 18:30:34
//  Revision      :
//  Author        : Tri Nguyen
//  Company       : Princeton University
//  Email         : trin@princeton.edu
//
//  Description   :
//
//
//==================================================================================================
//rf_l15_lruarray.v


// /home/hongce/ila/openpiton/piton/verif/env/manycore/devices.xml

//`timescale 1 ns / 10 ps
//`default_nettype none
module rf_l15_lruarray(
   input wire clk,
   input wire rst_n,

   input wire read_valid,
   input wire [`L15_CACHE_INDEX_WIDTH-1:0] read_index,

   input wire write_valid,
   input wire [`L15_CACHE_INDEX_WIDTH-1:0] write_index,
   input wire [5:0] write_mask,
   input wire [5:0] write_data,

   output wire [5:0] read_data
   );



// reg read_valid_f;
reg [`L15_CACHE_INDEX_WIDTH-1:0] read_index_f;

reg [5:0] regfile [0:`L15_CACHE_INDEX_VECTOR_WIDTH-1];

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
   if (!rst_n)
   begin
      regfile[0] <= 6'b0;
regfile[1] <= 6'b0;
regfile[2] <= 6'b0;
regfile[3] <= 6'b0;
regfile[4] <= 6'b0;
regfile[5] <= 6'b0;
regfile[6] <= 6'b0;
regfile[7] <= 6'b0;
regfile[8] <= 6'b0;
regfile[9] <= 6'b0;
regfile[10] <= 6'b0;
regfile[11] <= 6'b0;
regfile[12] <= 6'b0;
regfile[13] <= 6'b0;
regfile[14] <= 6'b0;
regfile[15] <= 6'b0;
regfile[16] <= 6'b0;
regfile[17] <= 6'b0;
regfile[18] <= 6'b0;
regfile[19] <= 6'b0;
regfile[20] <= 6'b0;
regfile[21] <= 6'b0;
regfile[22] <= 6'b0;
regfile[23] <= 6'b0;
regfile[24] <= 6'b0;
regfile[25] <= 6'b0;
regfile[26] <= 6'b0;
regfile[27] <= 6'b0;
regfile[28] <= 6'b0;
regfile[29] <= 6'b0;
regfile[30] <= 6'b0;
regfile[31] <= 6'b0;
regfile[32] <= 6'b0;
regfile[33] <= 6'b0;
regfile[34] <= 6'b0;
regfile[35] <= 6'b0;
regfile[36] <= 6'b0;
regfile[37] <= 6'b0;
regfile[38] <= 6'b0;
regfile[39] <= 6'b0;
regfile[40] <= 6'b0;
regfile[41] <= 6'b0;
regfile[42] <= 6'b0;
regfile[43] <= 6'b0;
regfile[44] <= 6'b0;
regfile[45] <= 6'b0;
regfile[46] <= 6'b0;
regfile[47] <= 6'b0;
regfile[48] <= 6'b0;
regfile[49] <= 6'b0;
regfile[50] <= 6'b0;
regfile[51] <= 6'b0;
regfile[52] <= 6'b0;
regfile[53] <= 6'b0;
regfile[54] <= 6'b0;
regfile[55] <= 6'b0;
regfile[56] <= 6'b0;
regfile[57] <= 6'b0;
regfile[58] <= 6'b0;
regfile[59] <= 6'b0;
regfile[60] <= 6'b0;
regfile[61] <= 6'b0;
regfile[62] <= 6'b0;
regfile[63] <= 6'b0;
regfile[64] <= 6'b0;
regfile[65] <= 6'b0;
regfile[66] <= 6'b0;
regfile[67] <= 6'b0;
regfile[68] <= 6'b0;
regfile[69] <= 6'b0;
regfile[70] <= 6'b0;
regfile[71] <= 6'b0;
regfile[72] <= 6'b0;
regfile[73] <= 6'b0;
regfile[74] <= 6'b0;
regfile[75] <= 6'b0;
regfile[76] <= 6'b0;
regfile[77] <= 6'b0;
regfile[78] <= 6'b0;
regfile[79] <= 6'b0;
regfile[80] <= 6'b0;
regfile[81] <= 6'b0;
regfile[82] <= 6'b0;
regfile[83] <= 6'b0;
regfile[84] <= 6'b0;
regfile[85] <= 6'b0;
regfile[86] <= 6'b0;
regfile[87] <= 6'b0;
regfile[88] <= 6'b0;
regfile[89] <= 6'b0;
regfile[90] <= 6'b0;
regfile[91] <= 6'b0;
regfile[92] <= 6'b0;
regfile[93] <= 6'b0;
regfile[94] <= 6'b0;
regfile[95] <= 6'b0;
regfile[96] <= 6'b0;
regfile[97] <= 6'b0;
regfile[98] <= 6'b0;
regfile[99] <= 6'b0;
regfile[100] <= 6'b0;
regfile[101] <= 6'b0;
regfile[102] <= 6'b0;
regfile[103] <= 6'b0;
regfile[104] <= 6'b0;
regfile[105] <= 6'b0;
regfile[106] <= 6'b0;
regfile[107] <= 6'b0;
regfile[108] <= 6'b0;
regfile[109] <= 6'b0;
regfile[110] <= 6'b0;
regfile[111] <= 6'b0;
regfile[112] <= 6'b0;
regfile[113] <= 6'b0;
regfile[114] <= 6'b0;
regfile[115] <= 6'b0;
regfile[116] <= 6'b0;
regfile[117] <= 6'b0;
regfile[118] <= 6'b0;
regfile[119] <= 6'b0;
regfile[120] <= 6'b0;
regfile[121] <= 6'b0;
regfile[122] <= 6'b0;
regfile[123] <= 6'b0;
regfile[124] <= 6'b0;
regfile[125] <= 6'b0;
regfile[126] <= 6'b0;
regfile[127] <= 6'b0;

      // regfile <= 1024'b0;
   end
   else
   if (write_valid)
   begin
      regfile[write_index] <= (write_data & write_mask) | (regfile[write_index] & ~write_mask);
   end
end
endmodule
