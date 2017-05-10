module wrapper(input clk, input rst
);

wire[127:0] encr1;
wire[127:0] keyr1;

wire [31:0] in_key0;
wire [31:0] in_key1;
wire [31:0] in_key2;
wire [31:0] in_key3;

wire[31:0] state0;
wire[31:0] state1;
wire[31:0] state2;
wire[31:0] state3;


aesr a( .debug(), .vdb(), .encr1(encr1),.keyr1(keyr1), .i() ,.rcon(), 
        .in_key0(in_key0),
        .in_key1(in_key1),
        .in_key2(in_key2),
        .in_key3(in_key3),

        .state0(state0),
        .state1(state1),
        .state2(state2),
        .state3(state3),
        
        .clk(clk),
        .rst(rst),
        .step(1'b1)
        );

reg[7:0] ctr;
always @(posedge clk) begin
    if(rst)
        ctr <= 0;
    else if(ctr<10) begin
        ctr <= ctr +1;
    end
end

assert property (ctr == 1 |-> ({in_key0, in_key1, in_key2, in_key3 } == keyr1) );
assert property (ctr == 1 |-> ({state0, state1, state2, state3 } == encr1) );


endmodule
