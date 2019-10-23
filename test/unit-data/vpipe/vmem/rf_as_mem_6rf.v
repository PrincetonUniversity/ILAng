module proc(input clk, input rst, input [1:0] op, input [2:0] operand1,  input [2:0] operand2,
output mem_w_en, output [7:0] mem_w_addr, output [7:0] mem_w_data,
output mem_r_en, output [7:0] mem_r_addr, input[7:0] mem_r_data);

reg[7:0] rf[0:5]; 
// r0-r5 3-bit to index

// op == 0 : rf[operand1] <= rf[operand2] + 1
// op == 1 : mem[rf[operand1]] <= rf[operand2] (STORE)
// op == 2 : rf[operand1] <= mem[rf[operand2]] (LOAD)

assign mem_w_en = op == 1;
assign mem_r_en = op == 2;
assign mem_w_addr = rf[operand1];
assign mem_r_addr = rf[operand2];
assign mem_w_data = rf[operand2];

always @(posedge clk) begin
  if (op == 0)  begin
    rf[operand1] <= rf[operand2] + 1;
  end
  else if (op == 1) begin
    // do nothing
  end
  else if (op == 2) begin
    rf[operand1] <= mem_r_data;
  end
end


endmodule
