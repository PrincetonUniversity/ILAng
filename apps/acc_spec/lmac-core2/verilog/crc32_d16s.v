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


module crc32_d16s(
 input      [15:0] data,
 input      [31:0] seed,
 output     [31:0] crc
);

 //registers decalarations
 reg [31:0] data_p0; 
 reg [31:0] seed_p0; 

 //remap signal
 assign crc = data_p0 ^ seed_p0;


 always @(*) begin
  data_p0[0] = data[0] ^ data[6] ^ data[9] ^ data[10] ^ data[12];
 end 


 always @(*) begin
  data_p0[1] = data[0] ^ data[1] ^ data[6] ^ data[7] ^ data[9] ^ data[11] ^ data[12] ^ data[13];
 end 


 always @(*) begin
  data_p0[2] = data[0] ^ data[1] ^ data[2] ^ data[6] ^ data[7] ^ data[8] ^ data[9] ^ data[13] ^ data[14];
 end 


 always @(*) begin
  data_p0[3] = data[1] ^ data[2] ^ data[3] ^ data[7] ^ data[8] ^ data[9] ^ data[10] ^ data[14] ^ data[15];
 end 


 always @(*) begin
  data_p0[4] = data[0] ^ data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[8] ^ data[11] ^ data[12] ^ data[15];
 end 


 always @(*) begin
  data_p0[5] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13];
 end 


 always @(*) begin
  data_p0[6] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14];
 end 


 always @(*) begin
  data_p0[7] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[7] ^ data[8] ^ data[10] ^ data[15];
 end 


 always @(*) begin
  data_p0[8] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[8] ^ data[10] ^ data[11] ^ data[12];
 end 


 always @(*) begin
  data_p0[9] = data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[9] ^ data[11] ^ data[12] ^ data[13];
 end 


 always @(*) begin
  data_p0[10] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[9] ^ data[13] ^ data[14];
 end 


 always @(*) begin
  data_p0[11] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[9] ^ data[12] ^ data[14] ^ data[15];
 end 


 always @(*) begin
  data_p0[12] = data[0] ^ data[1] ^ data[2] ^ data[4] ^ data[5] ^ data[6] ^ data[9] ^ data[12] ^ data[13] ^ data[15];
 end 


 always @(*) begin
  data_p0[13] = data[1] ^ data[2] ^ data[3] ^ data[5] ^ data[6] ^ data[7] ^ data[10] ^ data[13] ^ data[14];
 end 


 always @(*) begin
  data_p0[14] = data[2] ^ data[3] ^ data[4] ^ data[6] ^ data[7] ^ data[8] ^ data[11] ^ data[14] ^ data[15];
 end 


 always @(*) begin
  data_p0[15] = data[3] ^ data[4] ^ data[5] ^ data[7] ^ data[8] ^ data[9] ^ data[12] ^ data[15];
 end 


 always @(*) begin
  data_p0[16] = data[0] ^ data[4] ^ data[5] ^ data[8] ^ data[12] ^ data[13];
 end 


 always @(*) begin
  data_p0[17] = data[1] ^ data[5] ^ data[6] ^ data[9] ^ data[13] ^ data[14];
 end 


 always @(*) begin
  data_p0[18] = data[2] ^ data[6] ^ data[7] ^ data[10] ^ data[14] ^ data[15];
 end 


 always @(*) begin
  data_p0[19] = data[3] ^ data[7] ^ data[8] ^ data[11] ^ data[15];
 end 


 always @(*) begin
  data_p0[20] = data[4] ^ data[8] ^ data[9] ^ data[12];
 end 


 always @(*) begin
  data_p0[21] = data[5] ^ data[9] ^ data[10] ^ data[13];
 end 


 always @(*) begin
  data_p0[22] = data[0] ^ data[9] ^ data[11] ^ data[12] ^ data[14];
 end 


 always @(*) begin
  data_p0[23] = data[0] ^ data[1] ^ data[6] ^ data[9] ^ data[13] ^ data[15];
 end 


 always @(*) begin
  data_p0[24] = data[1] ^ data[2] ^ data[7] ^ data[10] ^ data[14];
 end 


 always @(*) begin
  data_p0[25] = data[2] ^ data[3] ^ data[8] ^ data[11] ^ data[15];
 end 


 always @(*) begin
  data_p0[26] = data[0] ^ data[3] ^ data[4] ^ data[6] ^ data[10];
 end 


 always @(*) begin
  data_p0[27] = data[1] ^ data[4] ^ data[5] ^ data[7] ^ data[11];
 end 


 always @(*) begin
  data_p0[28] = data[2] ^ data[5] ^ data[6] ^ data[8] ^ data[12];
 end 


 always @(*) begin
  data_p0[29] = data[3] ^ data[6] ^ data[7] ^ data[9] ^ data[13];
 end 


 always @(*) begin
  data_p0[30] = data[4] ^ data[7] ^ data[8] ^ data[10] ^ data[14];
 end 


 always @(*) begin
  data_p0[31] = data[5] ^ data[8] ^ data[9] ^ data[11] ^ data[15];
 end 


 always @(*) begin
 seed_p0[0] = seed[16] ^ seed[22] ^ seed[25] ^ seed[26] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[1] = seed[16] ^ seed[17] ^ seed[22] ^ seed[23] ^ seed[25] ^ seed[27] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[2] = seed[16] ^ seed[17] ^ seed[18] ^ seed[22] ^ seed[23] ^ seed[24] ^ seed[25] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[3] = seed[17] ^ seed[18] ^ seed[19] ^ seed[23] ^ seed[24] ^ seed[25] ^ seed[26] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[4] = seed[16] ^ seed[18] ^ seed[19] ^ seed[20] ^ seed[22] ^ seed[24] ^ seed[27] ^ seed[28] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[5] = seed[16] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[21] ^ seed[22] ^ seed[23] ^ seed[26] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[6] = seed[17] ^ seed[18] ^ seed[20] ^ seed[21] ^ seed[22] ^ seed[23] ^ seed[24] ^ seed[27] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[7] = seed[16] ^ seed[18] ^ seed[19] ^ seed[21] ^ seed[23] ^ seed[24] ^ seed[26] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[8] = seed[16] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[24] ^ seed[26] ^ seed[27] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[9] = seed[17] ^ seed[18] ^ seed[20] ^ seed[21] ^ seed[25] ^ seed[27] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[10] = seed[16] ^ seed[18] ^ seed[19] ^ seed[21] ^ seed[25] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[11] = seed[16] ^ seed[17] ^ seed[19] ^ seed[20] ^ seed[25] ^ seed[28] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[12] = seed[16] ^ seed[17] ^ seed[18] ^ seed[20] ^ seed[21] ^ seed[22] ^ seed[25] ^ seed[28] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[13] = seed[17] ^ seed[18] ^ seed[19] ^ seed[21] ^ seed[22] ^ seed[23] ^ seed[26] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[14] = seed[18] ^ seed[19] ^ seed[20] ^ seed[22] ^ seed[23] ^ seed[24] ^ seed[27] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[15] = seed[19] ^ seed[20] ^ seed[21] ^ seed[23] ^ seed[24] ^ seed[25] ^ seed[28] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[16] = seed[0] ^ seed[16] ^ seed[20] ^ seed[21] ^ seed[24] ^ seed[28] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[17] = seed[1] ^ seed[17] ^ seed[21] ^ seed[22] ^ seed[25] ^ seed[29] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[18] = seed[2] ^ seed[18] ^ seed[22] ^ seed[23] ^ seed[26] ^ seed[30] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[19] = seed[3] ^ seed[19] ^ seed[23] ^ seed[24] ^ seed[27] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[20] = seed[4] ^ seed[20] ^ seed[24] ^ seed[25] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[21] = seed[5] ^ seed[21] ^ seed[25] ^ seed[26] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[22] = seed[6] ^ seed[16] ^ seed[25] ^ seed[27] ^ seed[28] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[23] = seed[7] ^ seed[16] ^ seed[17] ^ seed[22] ^ seed[25] ^ seed[29] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[24] = seed[8] ^ seed[17] ^ seed[18] ^ seed[23] ^ seed[26] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[25] = seed[9] ^ seed[18] ^ seed[19] ^ seed[24] ^ seed[27] ^ seed[31];
 end 


 always @(*) begin
 seed_p0[26] = seed[10] ^ seed[16] ^ seed[19] ^ seed[20] ^ seed[22] ^ seed[26];
 end 


 always @(*) begin
 seed_p0[27] = seed[11] ^ seed[17] ^ seed[20] ^ seed[21] ^ seed[23] ^ seed[27];
 end 


 always @(*) begin
 seed_p0[28] = seed[12] ^ seed[18] ^ seed[21] ^ seed[22] ^ seed[24] ^ seed[28];
 end 


 always @(*) begin
 seed_p0[29] = seed[13] ^ seed[19] ^ seed[22] ^ seed[23] ^ seed[25] ^ seed[29];
 end 


 always @(*) begin
 seed_p0[30] = seed[14] ^ seed[20] ^ seed[23] ^ seed[24] ^ seed[26] ^ seed[30];
 end 


 always @(*) begin
 seed_p0[31] = seed[15] ^ seed[21] ^ seed[24] ^ seed[25] ^ seed[27] ^ seed[31];
 end 

endmodule 
