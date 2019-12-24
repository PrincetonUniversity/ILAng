module undetfunc(input clk, input rst, input en, input [7:0] ukn);

reg [7:0] r0;
reg [7:0] r1;
reg [7:0] r2;
reg [7:0] r3;


wire [7:0] res1;
wire [7:0] res2;
wire [7:0] res3;
wire [7:0] res4;

assign res1 = en ? r1+1 : 8'hxx;
assign res2 = en ? r0 + 1 : ukn;
assign res3 = r0+r1+1;
assign res4 = r0 + r1 + r2 + r3;


always @(posedge clk) begin 
  r0 <= res1;
  r1 <= res2;

  if(en)
    r2 <= res3;
  
  r3 <= res4;
end

endmodule