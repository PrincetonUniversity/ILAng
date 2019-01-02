module rdtop (
  input clk,    // Clock
  input rst,  // Synchronous reset active high
  input [31:0] addra,
  input start,

  output [31:0] mem_a_raddr,
  input  [7:0] mem_a_rdata);

`define IDLE 2'd0
`define SEND_READ 2'd1

reg [1:0] state;
reg [1:0] next_state;

reg [31:0] raddra_buf;
reg [ 7:0] rdataa_buf;

always @(*) begin
  next_state = state;
  case(state)
    `IDLE: next_state = start ? `SEND_READ : `IDLE;
    `SEND_READ: next_state = `IDLE;
    default: next_state = `IDLE;
  endcase
end


always @(posedge clk) begin
  if(rst)
    state <= `IDLE;
  else begin
    state <= next_state;
  end
end


always @(posedge clk) begin
  if(state == `IDLE && next_state == `SEND_READ) begin
    raddra_buf <= addra;
  end
end

always @(posedge clk) begin
  if(state == `SEND_READ && next_state == `IDLE) begin
    rdataa_buf <= mem_a_rdata;
  end
end

assign mem_a_raddr = raddra_buf;

endmodule