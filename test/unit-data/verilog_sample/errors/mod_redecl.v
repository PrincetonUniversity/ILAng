module counter(input clk, input rst, input en, output full);

reg [3:0] cnt;

always @(posedge clk) begin
  if(rst)
    cnt <= 0;
  else if(en)
    cnt <= cnt + 1;
end

assign full = cnt == 4'hf;

endmodule

module counter(input clk, input rst, input en, output empty);

reg [3:0] cnt;

always @(posedge clk) begin
  if(rst)
    cnt <= 0;
  else if(en)
    cnt <= cnt + 1;
end

assign empty = cnt == 4'h0;

endmodule
