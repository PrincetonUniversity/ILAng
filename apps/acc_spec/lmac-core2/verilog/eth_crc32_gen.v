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
`timescale 1ns/10ps
// synopsys translate_on

module eth_crc32_gen(
	clk,         	   //i, clock
	rst_n,       	   //i, active low reset
	data_vld,    	   //i, data valid
	data_eop,    	   //i, end of frame
	data_sop,    	   //i, start of frame
	data_in,     	   //i, align first byte on bit [7:0] ... last byte [63:56]
	data_offset, 	   //i, number of starting bytes invalid on SOF beat, non SOF should set to 0
					
	data_be,     	   //i,0 - all bytes valid  (really is beat_bcnt)
	             	             
	crc_out,     	   //o-32, final generated crc32 value
	crc_vld      	   //o, crc check valid
 );

 parameter CRC_DWIDTH  = 32;
           
 input            clk;         	   //clock
 input            rst_n;       	    //active low reset
                          
                           
 input            data_vld;    		//packet data is valid
 input            data_eop;    	   //indicates last packet data for this packet
 input            data_sop;    	   //indicates the first packet data for this packet
 input  [64-1:0]  data_in;     	   //packet data
 input  [3-1:0]   data_be;     	  //total number of bytes valid, regardless of the where the first data is align on this clock
 input  [3-1:0]   data_offset; 	  //offset to first valid byte in the sof data beat, set to zero if non sof beat

 output [31:0]    crc_out;     	  //final crc32 value
 output reg       crc_vld;     	   //indicates crc status is valid
 
 reg              data_vld_s2;
 reg    [64-1:0]  shft_dout_s2;
 reg              data_eop_s2;
 reg              be_lt4_s2;
 reg    [32-1:0]  crc_dout_s3;
 reg    [32-1:0]  crc_dout_mux_s2;
 reg    [24-1:0]  shft_odd_dout_s2;
 reg    [64-1:0]  data_mask; 
 reg              info_mux_s2_crc_eop;
 reg    [2-1:0]   info_s2_crc_sel;  
 reg    [32-1:0]  crc_mux_s2;
 
 wire   [32-1:0]  crc_dout_d32_s2;
 wire   [4-1:0]   data_shft;  
 wire   [4-1:0]   seed_shft;
 wire   [3-1:0]   sum_data_be_offset;  
 wire   [64-1:0]  data_in_mask_s1;
 wire   [88-1:0]  adj_data_in_mask_s1;
 wire   [64-1:0]  adj_seed_crc_s1;
 wire   [88-1:0]  shft_dout_s1;
 wire   [64-1:0]  shft_crc_mux_s1;
 wire             be_lt4_s1;
 
 //number of bytes to shift down so that last valid byte is align on bit[7:0] of "data_in"
 assign sum_data_be_offset = data_offset  + data_be;
 assign data_shft          = ~(|sum_data_be_offset) ? 3'd0 : {1'b0, ~sum_data_be_offset} + 4'd1;
 
 //number of bytes to shift down the seed-crc so that it align with first valid data byte
 assign seed_shft = ~(|data_be) ? 4'd0 : {1'b0, ~data_be} + 4'd1;
 
 //packet data mask, use to mask out the data invalid data bytes in the data_in bus
 always@(*)
  begin
   case(data_offset)
    3'd1:    data_mask = data_sop ? {8'h0, {56{1'b1}}} : {64{1'b1}};
    3'd2:    data_mask = data_sop ? {16'h0,{48{1'b1}}} : {64{1'b1}};
    3'd3:    data_mask = data_sop ? {24'h0,{40{1'b1}}} : {64{1'b1}};
    3'd4:    data_mask = data_sop ? {32'h0,{32{1'b1}}} : {64{1'b1}};
    3'd5:    data_mask = data_sop ? {40'h0,{24{1'b1}}} : {64{1'b1}};
    3'd6:    data_mask = data_sop ? {48'h0,{16{1'b1}}} : {64{1'b1}};
    3'd7:    data_mask = data_sop ? {56'h0,{8{1'b1}}}  : {64{1'b1}};
    default: data_mask = {64{1'b1}}; 
   endcase
  end
 
 assign be_lt4_s1 = (data_be < 3'd4);
 
 //logic to pipe the data valid signal along
 always@(*)
  begin
   data_vld_s2     = data_vld;
   data_eop_s2     = data_eop;
   info_s2_crc_sel = sum_data_be_offset[1:0];
   be_lt4_s2       = be_lt4_s1;
  end

  //STAGE 1: logic to shift the input data from MSB to LSB to prepend zero's 
 assign data_in_mask_s1 = data_mask & SWAP_LEWIZ_DATA64(data_in);
 
 wire [4-1:0] adj_data_shft_s1 = (|sum_data_be_offset[2-1:0]) ? {data_shft[4-1:2], 2'd0} + 4'd4 : {data_shft[4-1:2], 2'd0};
 wire [4-1:0] adj_seed_shft_s1 = (|data_offset)      ? seed_shft :
                                 (|seed_shft[2-1:0]) ? {seed_shft[4-1:2], 2'd0} + 4'd4 : {seed_shft[4-1:2], 2'd0};
 
 assign adj_data_in_mask_s1 = {data_in_mask_s1, 24'd0};

 //logic to adjust the data shift value, to shift odd byte all the way down
 bsh32_dn_88 u_bsh32_dn_88_data(
  .shft(adj_data_shft_s1[4-1:2]),
  .din (adj_data_in_mask_s1),
  .dout(shft_dout_s1)
 );
 
 //adjust the input data after masking if starting byte is not align on 32 bits boundary
 assign adj_seed_crc_s1 = {SWAP_CRC(crc_mux_s2), 32'd0};
 
 //logic to shift the crc from MSB to LSB to xor with beginning bytes of input data
 bsh8_dn_64 u_bsh8_dn_64_crc(
  .shft(adj_seed_shft_s1[2:0]),
  .din (adj_seed_crc_s1),
  .dout(shft_crc_mux_s1)
 );
 
 always@(*) begin
  shft_dout_s2     = shft_dout_s1[88-1:24] ^ shft_crc_mux_s1;  
  shft_odd_dout_s2 = shft_dout_s1[24-1:0];
 end
 
 //STAGE 2: Compute the CRC32 for input data
 wire [64-1:0] swap_shft_dout_s2 = SWAP_DATA64(shft_dout_s2);
 wire [24-1:0] swap_shft_odd_dout_s2 = SWAP_DATA24(shft_odd_dout_s2);

 crc32_d64 u_crc32_d64(
  .data(swap_shft_dout_s2),
  .crc (crc_dout_d32_s2)
 );
 
 wire [32-1:0] crc_gen_d32_s2 = ~SWAP_NO_CRC(crc_dout_d32_s2);
  
 //logic to compute the non-word align data byte crc
 always@(*) begin
  crc_mux_s2 = crc_dout_s3 | {32{data_sop}};
 end 
  
 wire [32-1:0] crc_dout_d8_s2;
 wire [32-1:0] crc_seed_d8_s2 = be_lt4_s2 ? crc_mux_s2 : crc_dout_d32_s2;
 wire [32-1:0] crc_gen_d8_s2  = ~SWAP_NO_CRC(crc_dout_d8_s2); 
  
 crc32_d8s u_crc32_d8s(
  .seed(crc_seed_d8_s2),
  .data(swap_shft_odd_dout_s2[23:16]),
  .crc (crc_dout_d8_s2)
 );

 wire [32-1:0] crc_dout_d16_s2;
 wire [32-1:0] crc_seed_d16_s2 = be_lt4_s2 ? crc_mux_s2 : crc_dout_d32_s2;
 wire [32-1:0] crc_gen_d16_s2  = ~SWAP_NO_CRC(crc_dout_d16_s2); 
  
 crc32_d16s u_crc32_d16s(
  .seed(crc_seed_d16_s2),
  .data(swap_shft_odd_dout_s2[23:8]),
  .crc (crc_dout_d16_s2)
 );

 wire [32-1:0] crc_dout_d24_s2;
 wire [32-1:0] crc_seed_d24_s2 = be_lt4_s2 ? crc_mux_s2 : crc_dout_d32_s2;
 wire [32-1:0] crc_gen_d24_s2  = ~SWAP_NO_CRC(crc_dout_d24_s2);  
  
 crc32_d24s u_crc32_d24s(
  .seed(crc_seed_d24_s2),
  .data(swap_shft_odd_dout_s2[23:0]),
  .crc (crc_dout_d24_s2)
 );

 //STAGE 2: Multiplex out the current accumulate crc value from table
 always@(*) begin
   case(info_s2_crc_sel)
    2'd1:    crc_dout_mux_s2 = crc_dout_d8_s2;
    2'd2:    crc_dout_mux_s2 = crc_dout_d16_s2;
    2'd3:    crc_dout_mux_s2 = crc_dout_d24_s2;
    default: crc_dout_mux_s2 = crc_dout_d32_s2;
   endcase
 end
 
 always@(*) begin
   info_mux_s2_crc_eop = (data_eop && ~(|data_be));
  end
 
 
 //STAGE 3: Per Port CRC Accumulation Table Update and CRC Valid Output
 always@(posedge clk) 
  if(!rst_n) begin
   crc_dout_s3 <= {CRC_DWIDTH{1'b1}};
  end else begin 
   crc_dout_s3 <= crc_dout_mux_s2;
  end

 //logic to perform crc swap + inversion  
 assign crc_out = ~SWAP_NO_CRC(crc_dout_s3);
 
 //logic to swap and invert the final crc and assert crc valid
 always@(posedge clk) 
  if(!rst_n)
   crc_vld <= 1'b0;
  else
   crc_vld <= data_vld_s2 && data_eop_s2;

 //function to swap the final crc result 
 function [32-1:0] SWAP_CRC;
 input [32-1:0] crc;
 reg   [32-1:0] temp;
 begin
  temp[31] = crc[24];
  temp[30] = crc[25];
  temp[29] = crc[26];
  temp[28] = crc[27];
  temp[27] = crc[28];
  temp[26] = crc[29];
  temp[25] = crc[30];
  temp[24] = crc[31];
  temp[23] = crc[16];
  temp[22] = crc[17];
  temp[21] = crc[18];
  temp[20] = crc[19];
  temp[19] = crc[20];
  temp[18] = crc[21];
  temp[17] = crc[22];
  temp[16] = crc[23];
  temp[15] = crc[8];
  temp[14] = crc[9];
  temp[13] = crc[10];
  temp[12] = crc[11];
  temp[11] = crc[12];
  temp[10] = crc[13];
  temp[9] = crc[14];
  temp[8] = crc[15];
  temp[7] = crc[0];
  temp[6] = crc[1];
  temp[5] = crc[2];
  temp[4] = crc[3];
  temp[3] = crc[4];
  temp[2] = crc[5];
  temp[1] = crc[6];
  temp[0] = crc[7];
  SWAP_CRC = temp;
 end
 endfunction                
 
 function [32-1:0] SWAP_NO_CRC;
 input [32-1:0] crc;
 reg   [32-1:0] temp;
 begin
  temp[31] = crc[0];
  temp[30] = crc[1];
  temp[29] = crc[2];
  temp[28] = crc[3];
  temp[27] = crc[4];
  temp[26] = crc[5];
  temp[25] = crc[6];
  temp[24] = crc[7];
  temp[23] = crc[8]; 
  temp[22] = crc[9]; 
  temp[21] = crc[10];
  temp[20] = crc[11];
  temp[19] = crc[12];
  temp[18] = crc[13];
  temp[17] = crc[14];
  temp[16] = crc[15];
  temp[15] = crc[16];
  temp[14] = crc[17];
  temp[13] = crc[18];
  temp[12] = crc[19];
  temp[11] = crc[20];
  temp[10] = crc[21];
  temp[9]  = crc[22];
  temp[8]  = crc[23];
  temp[7]  = crc[24];
  temp[6]  = crc[25];
  temp[5]  = crc[26];
  temp[4]  = crc[27];
  temp[3]  = crc[28];
  temp[2]  = crc[29];
  temp[1]  = crc[30];
  temp[0]  = crc[31];
  SWAP_NO_CRC = temp;
 end
 endfunction                                
 
 //fucntion to swap the input data before sending it to the crc compute module
 function [64-1:0] SWAP_DATA64;
 input [64-1:0] DIN;
 reg   [64-1:0] DOUT;
 begin
   DOUT[63] = DIN[56];
   DOUT[62] = DIN[57];
   DOUT[61] = DIN[58];
   DOUT[60] = DIN[59];
   DOUT[59] = DIN[60];
   DOUT[58] = DIN[61];
   DOUT[57] = DIN[62];
   DOUT[56] = DIN[63];
   DOUT[55] = DIN[48];
   DOUT[54] = DIN[49];
   DOUT[53] = DIN[50];
   DOUT[52] = DIN[51];
   DOUT[51] = DIN[52];
   DOUT[50] = DIN[53];
   DOUT[49] = DIN[54];
   DOUT[48] = DIN[55];
   DOUT[47] = DIN[40];
   DOUT[46] = DIN[41];
   DOUT[45] = DIN[42];
   DOUT[44] = DIN[43];
   DOUT[43] = DIN[44];
   DOUT[42] = DIN[45];
   DOUT[41] = DIN[46];
   DOUT[40] = DIN[47];
   DOUT[39] = DIN[32];
   DOUT[38] = DIN[33];
   DOUT[37] = DIN[34];
   DOUT[36] = DIN[35];
   DOUT[35] = DIN[36];
   DOUT[34] = DIN[37];
   DOUT[33] = DIN[38];
   DOUT[32] = DIN[39];
   DOUT[31] = DIN[24];
   DOUT[30] = DIN[25];
   DOUT[29] = DIN[26];
   DOUT[28] = DIN[27];
   DOUT[27] = DIN[28];
   DOUT[26] = DIN[29];
   DOUT[25] = DIN[30];
   DOUT[24] = DIN[31];
   DOUT[23] = DIN[16];
   DOUT[22] = DIN[17];
   DOUT[21] = DIN[18];
   DOUT[20] = DIN[19];
   DOUT[19] = DIN[20];
   DOUT[18] = DIN[21];
   DOUT[17] = DIN[22];
   DOUT[16] = DIN[23];
   DOUT[15] = DIN[8];
   DOUT[14] = DIN[9];
   DOUT[13] = DIN[10];
   DOUT[12] = DIN[11];
   DOUT[11] = DIN[12];
   DOUT[10] = DIN[13];
   DOUT[9] = DIN[14];
   DOUT[8] = DIN[15];
   DOUT[7] = DIN[0];
   DOUT[6] = DIN[1];
   DOUT[5] = DIN[2];
   DOUT[4] = DIN[3];
   DOUT[3] = DIN[4];
   DOUT[2] = DIN[5];
   DOUT[1] = DIN[6];
   DOUT[0] = DIN[7];
   
   SWAP_DATA64 = DOUT; 
 end
 endfunction
 
 function [24-1:0] SWAP_DATA24;
 input [24-1:0] DIN;
 reg   [24-1:0] DOUT;
 begin
   DOUT[23] = DIN[16];
   DOUT[22] = DIN[17];
   DOUT[21] = DIN[18];
   DOUT[20] = DIN[19];
   DOUT[19] = DIN[20];
   DOUT[18] = DIN[21];
   DOUT[17] = DIN[22];
   DOUT[16] = DIN[23];
   DOUT[15] = DIN[8];
   DOUT[14] = DIN[9];
   DOUT[13] = DIN[10];
   DOUT[12] = DIN[11];
   DOUT[11] = DIN[12];
   DOUT[10] = DIN[13];
   DOUT[9] = DIN[14];
   DOUT[8] = DIN[15];
   DOUT[7] = DIN[0];
   DOUT[6] = DIN[1];
   DOUT[5] = DIN[2];
   DOUT[4] = DIN[3];
   DOUT[3] = DIN[4];
   DOUT[2] = DIN[5];
   DOUT[1] = DIN[6];
   DOUT[0] = DIN[7];
   
   SWAP_DATA24 = DOUT; 
 end
 endfunction
 
 //function to swap lewiz data format to crc data format
 function [64-1:0] SWAP_LEWIZ_DATA64;
 input [64-1:0] DIN;
 reg   [64-1:0] DOUT;
 begin
   DOUT[63] = DIN[7];
   DOUT[62] = DIN[6];
   DOUT[61] = DIN[5];
   DOUT[60] = DIN[4];
   DOUT[59] = DIN[3];
   DOUT[58] = DIN[2];
   DOUT[57] = DIN[1];
   DOUT[56] = DIN[0];
   DOUT[55] = DIN[15];
   DOUT[54] = DIN[14];
   DOUT[53] = DIN[13];
   DOUT[52] = DIN[12];
   DOUT[51] = DIN[11];
   DOUT[50] = DIN[10];
   DOUT[49] = DIN[9];
   DOUT[48] = DIN[8];
   DOUT[47] = DIN[23];
   DOUT[46] = DIN[22];
   DOUT[45] = DIN[21];
   DOUT[44] = DIN[20];
   DOUT[43] = DIN[19];
   DOUT[42] = DIN[18];
   DOUT[41] = DIN[17];
   DOUT[40] = DIN[16];
   DOUT[39] = DIN[31];
   DOUT[38] = DIN[30];
   DOUT[37] = DIN[29];
   DOUT[36] = DIN[28];
   DOUT[35] = DIN[27];
   DOUT[34] = DIN[26];
   DOUT[33] = DIN[25];
   DOUT[32] = DIN[24];
   DOUT[31] = DIN[39];
   DOUT[30] = DIN[38];
   DOUT[29] = DIN[37];
   DOUT[28] = DIN[36];
   DOUT[27] = DIN[35];
   DOUT[26] = DIN[34];
   DOUT[25] = DIN[33];
   DOUT[24] = DIN[32];
   DOUT[23] = DIN[47];
   DOUT[22] = DIN[46];
   DOUT[21] = DIN[45];
   DOUT[20] = DIN[44];
   DOUT[19] = DIN[43];
   DOUT[18] = DIN[42];
   DOUT[17] = DIN[41];
   DOUT[16] = DIN[40];
   DOUT[15] = DIN[55];
   DOUT[14] = DIN[54];
   DOUT[13] = DIN[53];
   DOUT[12] = DIN[52];
   DOUT[11] = DIN[51];
   DOUT[10] = DIN[50];
   DOUT[9]  = DIN[49];
   DOUT[8]  = DIN[48];
   DOUT[7]  = DIN[63];
   DOUT[6]  = DIN[62];
   DOUT[5]  = DIN[61];
   DOUT[4]  = DIN[60];
   DOUT[3]  = DIN[59];
   DOUT[2]  = DIN[58];
   DOUT[1]  = DIN[57];
   DOUT[0]  = DIN[56];
   
   SWAP_LEWIZ_DATA64 = DOUT; 
 end
 endfunction

endmodule

