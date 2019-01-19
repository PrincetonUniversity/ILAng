module counter(input clk, input rst, input en, output full); // no semicolon

reg [3:0] cnt;

always @(posedge clk) begin
  if(rst)
    cnt <= 0;
  else if(en)
    cnt <= cnt + 1;
end

full_logic1 f( .in(cnt), .out(full) );

endmodule


module full_logic1(input [3:0] in, output out);

full_logic2 f( .in(in), .out(out) );

endmodule



module full_logic2(input [3:0] in, output out);

assign out = in == 4'hf;

endmodule
