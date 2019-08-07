module range( clk, rst, in1, in2, in3, r1, r2, r3);

parameter W = 4;
parameter W2 = (W + 1);
parameter WV = 2'b00;
parameter WV2 = WV + 1;

input clk;
input rst;
input [W-1:0] in1;
input [W2*2-1:0] in2;
input [W2-1:0] in3;

output [W-1:0] r1;
output [W2*2-1:0] r2;
output [W2-1:0] r3;

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