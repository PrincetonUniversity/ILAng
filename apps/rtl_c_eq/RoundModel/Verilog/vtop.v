module vtop(input clk, input rst, input  [127:0] state, input  [127:0] key,
    output [127:0] out);

wire [31:0] k0,k1,k2,k3;
wire [31:0] s0,s1,s2,s3;


wire [127:0] keyr1;
wire [127:0] encr1;
wire GM_step;
wire finish;
wire [3:0] i;

aes_128 IMPL(.clk(clk), .state(state), .key(key), .out(out) );
aesr GM(.clk(clk), .i(i), 
    .in_key0(k0),
    .in_key1(k1),
    .in_key2(k2),
    .in_key3(k3),

    .state0(s0),
    .state1(s1),
    .state2(s2),
    .state3(s3),

    .keyr1(keyr1),
    .encr1(encr1),

    .step(GM_step),
    .rst(rst)
    );

reg [10:0]ctr;
always @(posedge clk) begin
    if (rst) begin
        ctr <= 0;
    end
    else if (ctr < 10) begin
        ctr <= ctr + 1;
    end
end


wire beg = (ctr == 1) ;
assign GM_step = ctr == 2;
assign finish = ctr == 4;
/*
always @(posedge clk) begin
    if(rst) begin
        
    end
    else if(beg) begin
        force GM.in_key0 = key[127:96];
        force GM.in_key1 = key[95:64];
        force GM.in_key2 = key[63:32];
        force GM.in_key3 = key[31:0];

        force GM.state0 = state[127:96];
        force GM.state1 = state[95:64];
        force GM.state2 = state[63:32];
        force GM.state3 = state[31:0];

    end
    else begin
        release GM.in_key0;
        release GM.in_key1;
        release GM.in_key2;
        release GM.in_key3;

        release GM.state0;
        release GM.state1;
        release GM.state2;
        release GM.state3;
    end
end


always @(posedge clk) begin
    if(ctr == 3) begin
        $display("DEBUG:%x", GM.vdb );
    end
end

always @(posedge clk) begin
    if(ctr==2) begin
        $display("s0:%x", IMPL.r1.s0);
        $display("s1:%x", IMPL.r1.s1);
        $display("s2:%x", IMPL.r1.s2);
        $display("s3:%x", IMPL.r1.s3);
    end
    if(ctr==3) begin
        $display("p00:%x", IMPL.r1.p00);
        $display("p10:%x", IMPL.r1.p10);
        $display("p30:%x", IMPL.r1.p30);
        $display("z0:%x", IMPL.r1.z0);
        $display("z1:%x", IMPL.r1.z1);
        $display("z2:%x", IMPL.r1.z2);
        $display("z3:%x", IMPL.r1.z3);
    end
end
*/
/*
assume property ((ctr == 2) |-> ( {k0,k1,k2,k3} == key ) );
assume property ((ctr == 2) |-> ( {s0,s1,s2,s3} == state ) );
assert property (finish |-> ( keyr1 == IMPL.k1) );
assert property (finish |-> ( encr1 == IMPL.s1) );
*/

reg[127:0] kd;
reg[127:0] sd;

always @(posedge clk) begin
	kd <= key;
	sd <= state;
end

assume property ((ctr == 2) |-> ( {k0,k1,k2,k3} == kd ) );
assume property ((ctr == 2) |-> ( {s0,s1,s2,s3} == sd ) );
assert property (finish |-> ( keyr1 == IMPL.k1) );
assert property (finish |-> ( encr1 == IMPL.s1) );

endmodule
