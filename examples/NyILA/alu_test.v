module counter (
out, 
enable,
clk,
reset);
output reg [7:0] out;
input enable, clk, reset;
always @(posedge clk) begin
    if(reset) begin
	out <= 8'b0;
    end
    else if(enable) begin
        out <= out + 1;
    end
end

endmodule
