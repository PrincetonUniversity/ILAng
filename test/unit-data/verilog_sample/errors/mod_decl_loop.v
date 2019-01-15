module A(input clk, input rst, input in, output out);

B instB(.clk(clk),.rst(rst),.in(in),.out(out));

endmodule

module B(input clk, input rst, input in, output out);

A instA(.clk(clk),.rst(rst),.in(in),.out(out));

endmodule
