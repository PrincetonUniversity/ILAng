module proc(input clk, input rst, input [1:0] op, input [1:0] oprand1,  input [1:0] oprand2,
output mem_w_en, output [7:0] mem_w_addr, output [7:0] mem_w_data,
output mem_r_en, output [7:0] mem_r_addr, input[7:0] mem_r_data);

reg[7:0] rf[0:3];

// op == 0 : rf[oprand1] <= rf[oprand2] + 1
// op == 1 : mem[rf[oprand1]] <= rf[oprand2] (STORE)
// op == 2 : rf[oprand1] <= mem[rf[oprand2]] (LOAD)

assign mem_w_en = op == 1;
assign mem_r_en = op == 2;
assign mem_w_addr = rf[oprand1];
assign mem_r_addr = rf[oprand2];
assign mem_w_data = rf[oprand2];

always @(posedge clk) begin
  if (op == 0)  begin
    rf[oprand1] <= rf[oprand2] + 1;
  end
  else if (op == 1) begin
    // do nothing
  end
  else if (op == 2) begin
    rf[oprand1] <= mem_r_data;
  end
end


endmodule
