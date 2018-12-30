module monitor(input clk, input rst, input en, input [7:0] r0, input [7:0] r1, input execute);


reg [7:0] r0d;
reg [7:0] r1d;
reg [7:0] r2;

always @(posedge clk) begin
  if(en) begin
    r0d <= r0;
    r1d <= r1;
  end
end

always @(posedge clk) begin
  if(execute) begin
    r2 <= r0d + r1d;
  end
end