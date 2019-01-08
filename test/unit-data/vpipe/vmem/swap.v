module swap (
  input clk,    // Clock
  input rst,  // Synchronous reset active high
  input [31:0] addra,
  input [31:0] addrb,
  input start,

  output [31:0] mem_a_raddr,
  input  [7:0] mem_a_rdata,

  output  [31:0] mem_a_waddr,
  output  [7:0] mem_a_wdata,
  output  mem_a_wen,

  output [31:0] mem_b_raddr,
  input  [7:0] mem_b_rdata,

  output  [31:0] mem_b_waddr,
  output  [7:0] mem_b_wdata,
  output  mem_b_wen);
`define IDLE 2'd0
`define SEND_READ 2'd1
`define SEND_WRITE 2'd2

reg [1:0] state;
reg [1:0] next_state;

reg [31:0] raddra_buf;
reg [31:0] raddrb_buf;
reg [ 7:0] rdataa_buf;
reg [ 7:0] rdatab_buf;

always @(*) begin
  next_state = state;
  case(state)
    `IDLE: next_state = start ? `SEND_READ : `IDLE;
    `SEND_READ: next_state = `SEND_WRITE;
    `SEND_WRITE: next_state = `IDLE;
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
    raddrb_buf <= addrb;
  end
end

always @(posedge clk) begin
  if(state == `SEND_READ && next_state == `SEND_WRITE) begin
    rdataa_buf <= mem_a_rdata;
    rdatab_buf <= mem_b_rdata;
  end
end


assign mem_a_raddr = raddra_buf;
assign mem_b_raddr = raddrb_buf;
assign mem_a_waddr = raddra_buf;
assign mem_b_waddr = raddrb_buf;
assign mem_a_wdata = rdatab_buf;
assign mem_b_wdata = rdataa_buf;
assign mem_a_wen   = state == `SEND_WRITE;
assign mem_b_wen   = state == `SEND_WRITE;


endmodule