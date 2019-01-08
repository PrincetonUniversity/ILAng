module undetval(input clk, input rst, input [7:0] d);

reg [7:0] r0;
reg [7:0] r1;
reg [7:0] r2;
reg [7:0] r3;
reg [7:0] r4;


wire [7:0] res1;
wire [7:0] res2;
wire [7:0] res3;
wire [7:0] res4;
wire [7:0] res5;

assign res1 = d;
assign res2 = d;
assign res3 = d + 1;
assign res4 = d << 2;
assign res5 = d << 3;


always @(posedge clk) begin 
  r0 <= res1 + 1;
  r1 <= res2 + 2;
  r2 <= res3 + 3;
  r3 <= res4 + 4;
  r4 <= res5 + 5;
end

endmodule