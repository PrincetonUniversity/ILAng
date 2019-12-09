module resetter(input clk, input rst, output v);

reg v1;
reg v2;


always @(posedge clk) begin
  if(rst) begin
    v1 <= !v1;
    v2 <= v1;
  end
  else begin
     v1 <= v2;
     v2 <= v1;
  end
end

assign v =  v1 ^ v2;


endmodule
