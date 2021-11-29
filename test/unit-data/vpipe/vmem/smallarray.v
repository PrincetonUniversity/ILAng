module top(input clk, input rst, input [3:0] addr, input[7:0] data,
  input wen, input ren, output [7:0] odata);

wire array1_sel = addr[3] == 1'b0;
wire array2_sel = addr[3] == 1'b1;
wire [2:0] subaddr = addr[2:0];
wire[7:0] odata1,odata2;

reg array1_sel_d1;
always @(posedge clk) begin
  array1_sel_d1 <= array1_sel;
end

subarray a1(.clk(clk), .rst(rst), .addr(subaddr), .data(data), .wen(wen&array1_sel), .ren(ren&array1_sel), .odata(odata1));
subarray a2(.clk(clk), .rst(rst), .addr(subaddr), .data(data), .wen(wen&array2_sel), .ren(ren&array2_sel), .odata(odata2));

assign odata = array1_sel_d1 ? odata1 : odata2;

endmodule

module subarray(input clk, input rst, input [2:0] addr, input[7:0] data,
  input wen, input ren, output reg [7:0] odata);

  reg [7:0] array[0:7];
  
    always @(posedge clk) begin
      if(wen)
        array[addr] <= data;
    end

    always @(posedge clk) begin
      if(ren)
        odata <= array[addr];
    end
  
endmodule
