module (input clk, input rst, input en, output full); // no semicolon

reg [3:0] cnt;

always @(posedge clk) begin
  if(rst)
    cnt <= 0;
  else if(en)
    cnt <= cnt + 1;
end

assign full = cnt == 4'hf;

endmodule
