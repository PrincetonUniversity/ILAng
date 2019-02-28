module opposite(input clk, input rst, input [3:0] ui, input en, output [3:0] out);

reg [3:0] v; // explicit state variable (modeled in ILA)
reg [3:0] imp; // implicit (micro-arch, not modeled, but need constraints on it)
// the constraint we want is
// p : v == 4'hf - imp

always @(posedge clk) begin
  if (rst)
    v <= ui;
  else if(en)
    v <= v + 1;
end

always @(posedge clk) begin
  if (rst)
    imp <= ~ui;
  else if(en)
    imp <= imp - 1;
end

assign out = v & ( 4'hf - imp ) ; 
// 4'hf - imp == v
// so, `out` should be the same as `v`

endmodule
