module MemTest(
    input clock, input reset, 
    input[29:0] read_addr0,
    input[29:0] read_addr1,
    output[7:0] read_data0,
    output[7:0] read_data1
    );

reg[7:0] RegisterFile[0:511];

wire [31:0] byteAddr0 = {read_addr0,2'b00};
wire [31:0] byteAddr1 = {read_addr1,2'b00};
assign read_data0 = RegisterFile[byteAddr0[8:0]];
assign read_data1 = RegisterFile[byteAddr1[8:0]];

integer i;
always @(posedge clock) begin
    for(i=0;i<512;i+=1)
        RegisterFile[i] <= RegisterFile[i];
end

reg[3:0] counter;
always @(posedge clock) begin
    if(reset)
        counter <= 4'd0;
    else
        counter <= counter + 4'd1;
end

assume property ((counter != 4'd3 ) | (read_addr0 == read_addr1));
assert property ((counter != 4'd3 ) | (read_data0 == read_data1));



endmodule