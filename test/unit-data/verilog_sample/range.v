
module range( clk, rst, r1, r2);

`include "rangeheader2.v"

input clk;
input rst;
output [`R1:0] r1;
output [`R2-1:0] r2;

wire [`R3:0] r3;
wire [`R4] r4;

reg  [`R12:0] r12;
reg  [`R22-1:0] r22;
wire [`R32:0] r32;
wire [`R42] r42;

reg  [`R14:0] r14;
reg  [`R24-1:0] r24;
wire [`R34:0] r34;
wire [`R44] r44;

wire [1*2/2+2%2:0] rm;
wire [-1:0] a;
wire [d:0] b;
wire [0?2:1:0] c;
wire [1<<1:0] d;

endmodule
