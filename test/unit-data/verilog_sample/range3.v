module range( clk, rst, r1, r2);

parameter W = 2;
parameter W2 = W + 1;
parameter WV = 2'b00;
parameter WV2 = WV + 1;

input clk;
input rst;
output [W-1:0] r1;
output [W2*2-1:0] r2;


endmodule
