// swap_im.v
// swap with internal memory (im)
module swap (
  input clk,    // Clock
  input rst,  // Synchronous reset active high
  input [3:0] addra,
  input [3:0] addrb,
  input start,
  output [3:0] dummyrd,
  output reg [7:0] dummyv);

(* keep *)  reg [7:0] mema[0:15];
(* keep *) reg [7:0] memb[0:15];


always @(posedge clk) begin
  if (start) begin
    mema[addra] <= memb[addrb];
    memb[addrb] <= mema[addra];
  end
end

always @(posedge clk) begin
  dummyv <= (^dummyrd) ? mema[dummyrd] : memb[dummyrd];
end

endmodule