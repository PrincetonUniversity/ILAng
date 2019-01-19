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
//  Filename      : l15_home_encoder.v
//  Created On    : 2014-06-23
//  Revision      :
//  Author        : Yaosheng Fu
//  Company       : Princeton University
//  Email         : yfu@princeton.edu
//
//  Description   : Home encoder for the L15 cache
//
//
//====================================================================================================


`include "l15.tmp.h"
`include "define.tmp.h"



module l15_home_encoder(
    // input wire clk,
    // input wire rst_n,
    input wire [`HOME_ID_WIDTH-1:0] home_in,
    //num_homes = 0 means have the maximum number of homes
    input wire [`HOME_ID_WIDTH-1:0] num_homes,

    output reg [`HOME_ID_WIDTH-1:0] lhid_out
);

reg [`HOME_ID_WIDTH-1:0] home_mask;
reg [`HOME_ID_WIDTH-1:0] home_low_mask;
reg [`HOME_ID_WIDTH-1:0] home_mod;
reg isPowerOf2;

always @ *
begin
    if (num_homes[5])
    begin
        home_low_mask = 6'b011111;
        isPowerOf2 = ~(|(num_homes[4:0]));
    end
    else if (num_homes[4])
    begin
        home_low_mask = 6'b001111;
        isPowerOf2 = ~(|(num_homes[3:0]));
    end
    else if (num_homes[3])
    begin
        home_low_mask = 6'b000111;
        isPowerOf2 = ~(|(num_homes[2:0]));
    end
    else if (num_homes[2])
    begin
        home_low_mask = 6'b000011;
        isPowerOf2 = ~(|(num_homes[1:0]));
    end
    else if (num_homes[1])
    begin
        home_low_mask = 6'b000001;
        isPowerOf2 = ~(|(num_homes[0:0]));
    end
    else if (num_homes[0])
    begin
        home_low_mask = 6'b000000;
        isPowerOf2 = 1'b1;
    end
    else
    begin
        home_low_mask = 6'b111111;
        isPowerOf2 = 1'b1;
    end

end

always @ *
begin
    if (isPowerOf2) 
    begin
        home_mask = home_low_mask;
    end
    else 
    begin
        home_mask = {home_low_mask[`HOME_ID_WIDTH-2:0], 1'b1};
    end
end

always @ *
begin
    home_mod = home_in & home_mask;
end

always @ *
begin
    if (home_mod < num_homes)
    begin
        lhid_out = home_mod;
    end
    else
    begin
        lhid_out = home_mod & home_low_mask;
    end
end

endmodule
