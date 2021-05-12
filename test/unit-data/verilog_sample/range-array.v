
module range( clk, rst, r1, r2);

`include "rangeheader2.v"

input clk;
input rst;
output [`R1:0] r1;
output [`R2-1:0] r2;

wire [`R3:0] r3;
wire [`R4] r4;

reg  [`R12:0] r12 [`R12-1:0];
reg  [`R22-1:0] r22 [`R22-2:0];
wire [`R32:0] r32;
wire [`R42] r42;

reg  [`R14:0] r14 [`R14-1:0];
reg  [`R24-1:0] r24 [`R24-2:0];
wire [`R34:0] r34;
wire [`R44] r44;


endmodule
