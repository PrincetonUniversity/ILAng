
`timescale 1 ns / 1 ps

  module hls_target_mul_mul_12ns_8ns_20_1_DSP48_3(a, b, p);
input [12 - 1 : 0] a; 
input [8 - 1 : 0] b; 
output [20 - 1 : 0] p; 

assign p = $unsigned (a) * $unsigned (b);

endmodule

`timescale 1 ns / 1 ps
module hls_target_mul_mul_12ns_8ns_20_1(
    din0,
    din1,
    dout);

parameter ID = 32'd1;
parameter NUM_STAGE = 32'd1;
parameter din0_WIDTH = 32'd1;
parameter din1_WIDTH = 32'd1;
parameter dout_WIDTH = 32'd1;
input[din0_WIDTH - 1:0] din0;
input[din1_WIDTH - 1:0] din1;
output[dout_WIDTH - 1:0] dout;



hls_target_mul_mul_12ns_8ns_20_1_DSP48_3 hls_target_mul_mul_12ns_8ns_20_1_DSP48_3_U(
    .a( din0 ),
    .b( din1 ),
    .p( dout ));

endmodule

