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
//  Filename      : rf_l15_wmt.v
//  Created On    : 2014-02-04 18:14:58
//  Last Modified : 2014-12-18 17:10:02
//  Revision      :
//  Author        : Tri Nguyen
//  Company       : Princeton University
//  Email         : trin@princeton.edu
//
//  Description   :
//
//
//==================================================================================================
//rf_l15_wmt.v

// trin timing fix 12/16: move read s3 to s2
// timing 12/17: move write to s2 to s3

// /home/hongce/ila/openpiton/piton/verif/env/manycore/devices.xml

module rf_l15_wmt(
   input wire clk,
   input wire rst_n,

   input wire read_valid,
   input wire [`L1D_SET_IDX_MASK] read_index,

   input wire write_valid,
   input wire [`L1D_SET_IDX_MASK] write_index,
   input wire [`L15_WMT_MASK] write_mask,
   input wire [`L15_WMT_MASK] write_data,

   output wire [`L15_WMT_MASK] read_data
   );


// reg [`L15_WMT_MASK] data_out_f;

// reg [`L15_WMT_MASK] regfile [0:127];

// always @ (posedge clk)
// begin
//    if (read_valid)
//       data_out_f <= regfile[read_index];
// end


// assign read_data = data_out_f;


reg [`L15_WMT_MASK] data_out_f;
reg [`L1D_SET_IDX_MASK] write_index_f;
reg [`L15_WMT_MASK] write_data_f;
reg [`L15_WMT_MASK] write_mask_f;
reg write_valid_f;

reg [`L15_WMT_MASK] regfile [0:`L15_WMT_ENTRY_COUNT-1];

always @ (posedge clk)
begin
   if (read_valid)
      data_out_f <= regfile[read_index];
end


assign read_data = data_out_f;

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
      regfile[0][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[0][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[0][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[0][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[1][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[1][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[1][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[1][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[2][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[2][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[2][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[2][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[3][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[3][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[3][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[3][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[4][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[4][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[4][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[4][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[5][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[5][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[5][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[5][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[6][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[6][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[6][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[6][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[7][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[7][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[7][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[7][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[8][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[8][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[8][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[8][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[9][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[9][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[9][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[9][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[10][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[10][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[10][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[10][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[11][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[11][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[11][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[11][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[12][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[12][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[12][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[12][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[13][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[13][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[13][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[13][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[14][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[14][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[14][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[14][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[15][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[15][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[15][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[15][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[16][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[16][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[16][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[16][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[17][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[17][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[17][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[17][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[18][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[18][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[18][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[18][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[19][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[19][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[19][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[19][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[20][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[20][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[20][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[20][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[21][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[21][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[21][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[21][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[22][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[22][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[22][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[22][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[23][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[23][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[23][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[23][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[24][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[24][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[24][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[24][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[25][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[25][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[25][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[25][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[26][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[26][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[26][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[26][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[27][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[27][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[27][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[27][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[28][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[28][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[28][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[28][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[29][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[29][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[29][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[29][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[30][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[30][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[30][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[30][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[31][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[31][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[31][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[31][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[32][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[32][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[32][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[32][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[33][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[33][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[33][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[33][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[34][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[34][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[34][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[34][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[35][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[35][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[35][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[35][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[36][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[36][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[36][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[36][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[37][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[37][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[37][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[37][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[38][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[38][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[38][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[38][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[39][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[39][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[39][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[39][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[40][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[40][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[40][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[40][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[41][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[41][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[41][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[41][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[42][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[42][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[42][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[42][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[43][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[43][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[43][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[43][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[44][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[44][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[44][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[44][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[45][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[45][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[45][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[45][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[46][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[46][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[46][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[46][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[47][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[47][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[47][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[47][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[48][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[48][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[48][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[48][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[49][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[49][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[49][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[49][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[50][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[50][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[50][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[50][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[51][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[51][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[51][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[51][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[52][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[52][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[52][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[52][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[53][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[53][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[53][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[53][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[54][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[54][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[54][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[54][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[55][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[55][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[55][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[55][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[56][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[56][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[56][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[56][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[57][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[57][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[57][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[57][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[58][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[58][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[58][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[58][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[59][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[59][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[59][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[59][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[60][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[60][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[60][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[60][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[61][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[61][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[61][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[61][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[62][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[62][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[62][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[62][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[63][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[63][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[63][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[63][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[64][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[64][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[64][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[64][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[65][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[65][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[65][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[65][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[66][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[66][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[66][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[66][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[67][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[67][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[67][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[67][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[68][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[68][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[68][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[68][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[69][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[69][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[69][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[69][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[70][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[70][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[70][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[70][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[71][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[71][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[71][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[71][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[72][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[72][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[72][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[72][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[73][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[73][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[73][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[73][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[74][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[74][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[74][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[74][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[75][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[75][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[75][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[75][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[76][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[76][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[76][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[76][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[77][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[77][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[77][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[77][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[78][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[78][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[78][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[78][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[79][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[79][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[79][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[79][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[80][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[80][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[80][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[80][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[81][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[81][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[81][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[81][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[82][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[82][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[82][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[82][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[83][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[83][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[83][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[83][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[84][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[84][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[84][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[84][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[85][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[85][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[85][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[85][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[86][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[86][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[86][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[86][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[87][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[87][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[87][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[87][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[88][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[88][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[88][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[88][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[89][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[89][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[89][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[89][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[90][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[90][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[90][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[90][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[91][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[91][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[91][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[91][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[92][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[92][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[92][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[92][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[93][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[93][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[93][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[93][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[94][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[94][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[94][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[94][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[95][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[95][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[95][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[95][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[96][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[96][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[96][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[96][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[97][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[97][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[97][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[97][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[98][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[98][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[98][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[98][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[99][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[99][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[99][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[99][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[100][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[100][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[100][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[100][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[101][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[101][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[101][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[101][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[102][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[102][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[102][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[102][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[103][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[103][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[103][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[103][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[104][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[104][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[104][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[104][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[105][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[105][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[105][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[105][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[106][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[106][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[106][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[106][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[107][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[107][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[107][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[107][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[108][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[108][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[108][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[108][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[109][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[109][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[109][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[109][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[110][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[110][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[110][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[110][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[111][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[111][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[111][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[111][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[112][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[112][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[112][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[112][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[113][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[113][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[113][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[113][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[114][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[114][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[114][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[114][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[115][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[115][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[115][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[115][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[116][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[116][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[116][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[116][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[117][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[117][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[117][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[117][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[118][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[118][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[118][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[118][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[119][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[119][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[119][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[119][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[120][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[120][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[120][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[120][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[121][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[121][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[121][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[121][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[122][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[122][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[122][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[122][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[123][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[123][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[123][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[123][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[124][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[124][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[124][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[124][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[125][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[125][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[125][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[125][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[126][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[126][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[126][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[126][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;
regfile[127][`L15_WMT_ENTRY_0_VALID_MASK] <= 1'b0;
regfile[127][`L15_WMT_ENTRY_1_VALID_MASK] <= 1'b0;
regfile[127][`L15_WMT_ENTRY_2_VALID_MASK] <= 1'b0;
regfile[127][`L15_WMT_ENTRY_3_VALID_MASK] <= 1'b0;

   end
   else
   if (write_valid_f)
   begin
      // regfile[write_index] <= (write_data & write_mask) | (regfile[write_index] & ~write_mask);
      regfile[write_index_f] <= (write_data_f & write_mask_f) | (regfile[write_index_f] & ~write_mask_f);
   end
end
endmodule
