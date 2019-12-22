module range( clk, rst, in1, in2, in3, r1, r2, r3);

parameter W = 4;
parameter W2 = (W100 + 1); // W100 is undefined should be an error


input clk;
input rst;
input [W-1:0] in1;
input [W2*2-1:0] in2;
input [W2-1:0] in3;

output [W-1:0] r1;
output [W2*2-1:0] r2;
output [W2-1:0] r3;


endmodule

