module counter(clk,rst,full,rst); // no semicolon

input rst;
wire rst;
wire rst;
input rst;
reg rst;
inout full;
reg full;

reg [3:0] cnt;

always @(posedge clk) begin
  if(rst)
    cnt <= 0;
  else if(en)
    cnt <= cnt + 1;
end

assign full = cnt == 4'hf;

endmodule
