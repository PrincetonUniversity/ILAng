module range( clk, rst, in1, in2, in3, r1, r2, r3);

parameter W = 4;
parameter W2 = (W + 1);
parameter WV = 2'b00;
parameter WV2 = WV + 1;
parameter W3 = 5'hf + 5'o16 + 5'b10; // 15+14+2 = 31
parameter W4 = {2'b10, 2'b11}; // 8+2+1 = 11
parameter W5 = W3 + W4 ; // 42
parameter W6 = (1 && 2) + (1 || 2) ; // 2
parameter W7 = W6 + (1 & 2) + (1 | 2) ; // 2 + (0+3) = 5
parameter W8 = {3{2'b10}}; // 42



input clk;
input rst;
input [W-1:0] in1;
input [W2*2-1:0] in2;
input [W2-1:0] in3;

output [W-1:0] r1;
output [W2*2-1:0] r2;
output [W2-1:0] r3;

wire [W5-1:0] wn1;
wire [W7-1:0] wn2;
wire [W8-1:0] wn3;

// default
subrange i1 (in1,r1);
// call by position
subrange #( W2*2 ) i2 (in1, r2 );
// call by name
subrange #( .W(W2) ) i3 (.in(in1), .out(r2) );
// call by name
subrange #( .W3(W2) ) i4 (.in(in1), .out(r2) );

endmodule


module subrange(in,out);

parameter W = 2;
parameter W3 = W*3;

input [W-1:0] in;
output [W-1:0] out;

wire [W-1:0] sig;

wire [W3-1:0] a;



endmodule