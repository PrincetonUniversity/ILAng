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


module crc32_d64(
 input      [63:0] data,
 output     [31:0] crc
);

 //registers decalarations
 reg [31:0] data_p0; 

 //remap signal
 assign crc = data_p0;


 always @(*) begin
  data_p0[0] = data[0] ^ data[6] ^ data[9] ^ data[10] ^ data[12] ^ data[16] ^ data[24] ^ data[25] ^ data[26] ^ data[28] ^ data[29] ^ data[30] ^ data[31] ^ data[32] ^ data[34] ^ data[37] ^ data[44] ^ data[45] ^ data[47] ^ data[48] ^ data[50] ^ data[53] ^ data[54] ^ data[55] ^ data[58] ^ data[60] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[1] = data[0] ^ data[1] ^ data[6] ^ data[7] ^ data[9] ^ data[11] ^ data[12] ^ data[13] ^ data[16] ^ data[17] ^ data[24] ^ data[27] ^ data[28] ^ data[33] ^ data[34] ^ data[35] ^ data[37] ^ data[38] ^ data[44] ^ data[46] ^ data[47] ^ data[49] ^ data[50] ^ data[51] ^ data[53] ^ data[56] ^ data[58] ^ data[59] ^ data[60] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[2] = data[0] ^ data[1] ^ data[2] ^ data[6] ^ data[7] ^ data[8] ^ data[9] ^ data[13] ^ data[14] ^ data[16] ^ data[17] ^ data[18] ^ data[24] ^ data[26] ^ data[30] ^ data[31] ^ data[32] ^ data[35] ^ data[36] ^ data[37] ^ data[38] ^ data[39] ^ data[44] ^ data[51] ^ data[52] ^ data[53] ^ data[55] ^ data[57] ^ data[58] ^ data[59];
 end 


 always @(*) begin
  data_p0[3] = data[1] ^ data[2] ^ data[3] ^ data[7] ^ data[8] ^ data[9] ^ data[10] ^ data[14] ^ data[15] ^ data[17] ^ data[18] ^ data[19] ^ data[25] ^ data[27] ^ data[31] ^ data[32] ^ data[33] ^ data[36] ^ data[37] ^ data[38] ^ data[39] ^ data[40] ^ data[45] ^ data[52] ^ data[53] ^ data[54] ^ data[56] ^ data[58] ^ data[59] ^ data[60];
 end 


 always @(*) begin
  data_p0[4] = data[0] ^ data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[8] ^ data[11] ^ data[12] ^ data[15] ^ data[18] ^ data[19] ^ data[20] ^ data[24] ^ data[25] ^ data[29] ^ data[30] ^ data[31] ^ data[33] ^ data[38] ^ data[39] ^ data[40] ^ data[41] ^ data[44] ^ data[45] ^ data[46] ^ data[47] ^ data[48] ^ data[50] ^ data[57] ^ data[58] ^ data[59] ^ data[63];
 end 


 always @(*) begin
  data_p0[5] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13] ^ data[19] ^ data[20] ^ data[21] ^ data[24] ^ data[28] ^ data[29] ^ data[37] ^ data[39] ^ data[40] ^ data[41] ^ data[42] ^ data[44] ^ data[46] ^ data[49] ^ data[50] ^ data[51] ^ data[53] ^ data[54] ^ data[55] ^ data[59] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[6] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14] ^ data[20] ^ data[21] ^ data[22] ^ data[25] ^ data[29] ^ data[30] ^ data[38] ^ data[40] ^ data[41] ^ data[42] ^ data[43] ^ data[45] ^ data[47] ^ data[50] ^ data[51] ^ data[52] ^ data[54] ^ data[55] ^ data[56] ^ data[60] ^ data[62];
 end 


 always @(*) begin
  data_p0[7] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[7] ^ data[8] ^ data[10] ^ data[15] ^ data[16] ^ data[21] ^ data[22] ^ data[23] ^ data[24] ^ data[25] ^ data[28] ^ data[29] ^ data[32] ^ data[34] ^ data[37] ^ data[39] ^ data[41] ^ data[42] ^ data[43] ^ data[45] ^ data[46] ^ data[47] ^ data[50] ^ data[51] ^ data[52] ^ data[54] ^ data[56] ^ data[57] ^ data[58] ^ data[60];
 end 


 always @(*) begin
  data_p0[8] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[8] ^ data[10] ^ data[11] ^ data[12] ^ data[17] ^ data[22] ^ data[23] ^ data[28] ^ data[31] ^ data[32] ^ data[33] ^ data[34] ^ data[35] ^ data[37] ^ data[38] ^ data[40] ^ data[42] ^ data[43] ^ data[45] ^ data[46] ^ data[50] ^ data[51] ^ data[52] ^ data[54] ^ data[57] ^ data[59] ^ data[60] ^ data[63];
 end 


 always @(*) begin
  data_p0[9] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[9] ^ data[11] ^ data[12] ^ data[13] ^ data[18] ^ data[23] ^ data[24] ^ data[29] ^ data[32] ^ data[33] ^ data[34] ^ data[35] ^ data[36] ^ data[38] ^ data[39] ^ data[41] ^ data[43] ^ data[44] ^ data[46] ^ data[47] ^ data[51] ^ data[52] ^ data[53] ^ data[55] ^ data[58] ^ data[60] ^ data[61];
 end 


 always @(*) begin
  data_p0[10] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[9] ^ data[13] ^ data[14] ^ data[16] ^ data[19] ^ data[26] ^ data[28] ^ data[29] ^ data[31] ^ data[32] ^ data[33] ^ data[35] ^ data[36] ^ data[39] ^ data[40] ^ data[42] ^ data[50] ^ data[52] ^ data[55] ^ data[56] ^ data[58] ^ data[59] ^ data[60] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[11] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[9] ^ data[12] ^ data[14] ^ data[15] ^ data[16] ^ data[17] ^ data[20] ^ data[24] ^ data[25] ^ data[26] ^ data[27] ^ data[28] ^ data[31] ^ data[33] ^ data[36] ^ data[40] ^ data[41] ^ data[43] ^ data[44] ^ data[45] ^ data[47] ^ data[48] ^ data[50] ^ data[51] ^ data[54] ^ data[55] ^ data[56] ^ data[57] ^ data[58] ^ data[59];
 end 


 always @(*) begin
  data_p0[12] = data[0] ^ data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[9] ^ data[12] ^ data[13] ^ data[15] ^ data[17] ^ data[18] ^ data[21] ^ data[24] ^ data[27] ^ data[30] ^ data[31] ^ data[41] ^ data[42] ^ data[46] ^ data[47] ^ data[49] ^ data[50] ^ data[51] ^ data[52] ^ data[53] ^ data[54] ^ data[56] ^ data[57] ^ data[59] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[13] = data[1] ^ data[2] ^ data[3] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13] ^ data[14] ^ data[16] ^ data[18] ^ data[19] ^ data[22] ^ data[25] ^ data[28] ^ data[31] ^ data[32] ^ data[42] ^ data[43] ^ data[47] ^ data[48] ^ data[50] ^ data[51] ^ data[52] ^ data[53] ^ data[54] ^ data[55] ^ data[57] ^ data[58] ^ data[60] ^ data[62];
 end 


 always @(*) begin
  data_p0[14] = data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14] ^ data[15] ^ data[17] ^ data[19] ^ data[20] ^ data[23] ^ data[26] ^ data[29] ^ data[32] ^ data[33] ^ data[43] ^ data[44] ^ data[48] ^ data[49] ^ data[51] ^ data[52] ^ data[53] ^ data[54] ^ data[55] ^ data[56] ^ data[58] ^ data[59] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[15] = data[3] ^ data[4] ^ data[5] ^ data[7] ^ data[8] ^ data[9] ^ data[12] ^ data[15] ^ data[16] ^ data[18] ^ data[20] ^ data[21] ^ data[24] ^ data[27] ^ data[30] ^ data[33] ^ data[34] ^ data[44] ^ data[45] ^ data[49] ^ data[50] ^ data[52] ^ data[53] ^ data[54] ^ data[55] ^ data[56] ^ data[57] ^ data[59] ^ data[60] ^ data[62];
 end 


 always @(*) begin
  data_p0[16] = data[0] ^ data[4] ^ data[5] ^ data[8] ^ data[12] ^ data[13] ^ data[17] ^ data[19] ^ data[21] ^ data[22] ^ data[24] ^ data[26] ^ data[29] ^ data[30] ^ data[32] ^ data[35] ^ data[37] ^ data[44] ^ data[46] ^ data[47] ^ data[48] ^ data[51] ^ data[56] ^ data[57];
 end 


 always @(*) begin
  data_p0[17] = data[1] ^ data[5] ^ data[6] ^ data[9] ^ data[13] ^ data[14] ^ data[18] ^ data[20] ^ data[22] ^ data[23] ^ data[25] ^ data[27] ^ data[30] ^ data[31] ^ data[33] ^ data[36] ^ data[38] ^ data[45] ^ data[47] ^ data[48] ^ data[49] ^ data[52] ^ data[57] ^ data[58];
 end 


 always @(*) begin
  data_p0[18] = data[2] ^ data[6] ^ data[7] ^ data[10] ^ data[14] ^ data[15] ^ data[19] ^ data[21] ^ data[23] ^ data[24] ^ data[26] ^ data[28] ^ data[31] ^ data[32] ^ data[34] ^ data[37] ^ data[39] ^ data[46] ^ data[48] ^ data[49] ^ data[50] ^ data[53] ^ data[58] ^ data[59];
 end 


 always @(*) begin
  data_p0[19] = data[3] ^ data[7] ^ data[8] ^ data[11] ^ data[15] ^ data[16] ^ data[20] ^ data[22] ^ data[24] ^ data[25] ^ data[27] ^ data[29] ^ data[32] ^ data[33] ^ data[35] ^ data[38] ^ data[40] ^ data[47] ^ data[49] ^ data[50] ^ data[51] ^ data[54] ^ data[59] ^ data[60];
 end 


 always @(*) begin
  data_p0[20] = data[4] ^ data[8] ^ data[9] ^ data[12] ^ data[16] ^ data[17] ^ data[21] ^ data[23] ^ data[25] ^ data[26] ^ data[28] ^ data[30] ^ data[33] ^ data[34] ^ data[36] ^ data[39] ^ data[41] ^ data[48] ^ data[50] ^ data[51] ^ data[52] ^ data[55] ^ data[60] ^ data[61];
 end 


 always @(*) begin
  data_p0[21] = data[5] ^ data[9] ^ data[10] ^ data[13] ^ data[17] ^ data[18] ^ data[22] ^ data[24] ^ data[26] ^ data[27] ^ data[29] ^ data[31] ^ data[34] ^ data[35] ^ data[37] ^ data[40] ^ data[42] ^ data[49] ^ data[51] ^ data[52] ^ data[53] ^ data[56] ^ data[61] ^ data[62];
 end 


 always @(*) begin
  data_p0[22] = data[0] ^ data[9] ^ data[11] ^ data[12] ^ data[14] ^ data[16] ^ data[18] ^ data[19] ^ data[23] ^ data[24] ^ data[26] ^ data[27] ^ data[29] ^ data[31] ^ data[34] ^ data[35] ^ data[36] ^ data[37] ^ data[38] ^ data[41] ^ data[43] ^ data[44] ^ data[45] ^ data[47] ^ data[48] ^ data[52] ^ data[55] ^ data[57] ^ data[58] ^ data[60] ^ data[61] ^ data[62];
 end 


 always @(*) begin
  data_p0[23] = data[0] ^ data[1] ^ data[6] ^ data[9] ^ data[13] ^ data[15] ^ data[16] ^ data[17] ^ data[19] ^ data[20] ^ data[26] ^ data[27] ^ data[29] ^ data[31] ^ data[34] ^ data[35] ^ data[36] ^ data[38] ^ data[39] ^ data[42] ^ data[46] ^ data[47] ^ data[49] ^ data[50] ^ data[54] ^ data[55] ^ data[56] ^ data[59] ^ data[60] ^ data[62];
 end 


 always @(*) begin
  data_p0[24] = data[1] ^ data[2] ^ data[7] ^ data[10] ^ data[14] ^ data[16] ^ data[17] ^ data[18] ^ data[20] ^ data[21] ^ data[27] ^ data[28] ^ data[30] ^ data[32] ^ data[35] ^ data[36] ^ data[37] ^ data[39] ^ data[40] ^ data[43] ^ data[47] ^ data[48] ^ data[50] ^ data[51] ^ data[55] ^ data[56] ^ data[57] ^ data[60] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[25] = data[2] ^ data[3] ^ data[8] ^ data[11] ^ data[15] ^ data[17] ^ data[18] ^ data[19] ^ data[21] ^ data[22] ^ data[28] ^ data[29] ^ data[31] ^ data[33] ^ data[36] ^ data[37] ^ data[38] ^ data[40] ^ data[41] ^ data[44] ^ data[48] ^ data[49] ^ data[51] ^ data[52] ^ data[56] ^ data[57] ^ data[58] ^ data[61] ^ data[62];
 end 


 always @(*) begin
  data_p0[26] = data[0] ^ data[3] ^ data[4] ^ data[6] ^ data[10] ^ data[18] ^ data[19] ^ data[20] ^ data[22] ^ data[23] ^ data[24] ^ data[25] ^ data[26] ^ data[28] ^ data[31] ^ data[38] ^ data[39] ^ data[41] ^ data[42] ^ data[44] ^ data[47] ^ data[48] ^ data[49] ^ data[52] ^ data[54] ^ data[55] ^ data[57] ^ data[59] ^ data[60] ^ data[61] ^ data[62];
 end 


 always @(*) begin
  data_p0[27] = data[1] ^ data[4] ^ data[5] ^ data[7] ^ data[11] ^ data[19] ^ data[20] ^ data[21] ^ data[23] ^ data[24] ^ data[25] ^ data[26] ^ data[27] ^ data[29] ^ data[32] ^ data[39] ^ data[40] ^ data[42] ^ data[43] ^ data[45] ^ data[48] ^ data[49] ^ data[50] ^ data[53] ^ data[55] ^ data[56] ^ data[58] ^ data[60] ^ data[61] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[28] = data[2] ^ data[5] ^ data[6] ^ data[8] ^ data[12] ^ data[20] ^ data[21] ^ data[22] ^ data[24] ^ data[25] ^ data[26] ^ data[27] ^ data[28] ^ data[30] ^ data[33] ^ data[40] ^ data[41] ^ data[43] ^ data[44] ^ data[46] ^ data[49] ^ data[50] ^ data[51] ^ data[54] ^ data[56] ^ data[57] ^ data[59] ^ data[61] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[29] = data[3] ^ data[6] ^ data[7] ^ data[9] ^ data[13] ^ data[21] ^ data[22] ^ data[23] ^ data[25] ^ data[26] ^ data[27] ^ data[28] ^ data[29] ^ data[31] ^ data[34] ^ data[41] ^ data[42] ^ data[44] ^ data[45] ^ data[47] ^ data[50] ^ data[51] ^ data[52] ^ data[55] ^ data[57] ^ data[58] ^ data[60] ^ data[62] ^ data[63];
 end 


 always @(*) begin
  data_p0[30] = data[4] ^ data[7] ^ data[8] ^ data[10] ^ data[14] ^ data[22] ^ data[23] ^ data[24] ^ data[26] ^ data[27] ^ data[28] ^ data[29] ^ data[30] ^ data[32] ^ data[35] ^ data[42] ^ data[43] ^ data[45] ^ data[46] ^ data[48] ^ data[51] ^ data[52] ^ data[53] ^ data[56] ^ data[58] ^ data[59] ^ data[61] ^ data[63];
 end 


 always @(*) begin
  data_p0[31] = data[5] ^ data[8] ^ data[9] ^ data[11] ^ data[15] ^ data[23] ^ data[24] ^ data[25] ^ data[27] ^ data[28] ^ data[29] ^ data[30] ^ data[31] ^ data[33] ^ data[36] ^ data[43] ^ data[44] ^ data[46] ^ data[47] ^ data[49] ^ data[52] ^ data[53] ^ data[54] ^ data[57] ^ data[59] ^ data[60] ^ data[62];
 end 

endmodule 
