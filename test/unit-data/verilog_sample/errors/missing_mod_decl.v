module counter(input clk, input rst, input en, output full); // no semicolon

reg [3:0] cnt;

always @(posedge clk) begin
  if(rst)
    cnt <= 0;
  else if(en)
    cnt <= cnt + 1;
end

full_logic f( .in(cnt), .out(full) );

endmodule

/*
module full_logic(input [3:0] in, output out);

assign out = in == 4'hf;

endmodule
*/
