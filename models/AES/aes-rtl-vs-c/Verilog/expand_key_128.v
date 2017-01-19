
//	in -> out_1 : 2d 
//	in -> out_2 : 1d

module expand_key_128(clk, in, out_1, out_2, rcon);
    input              clk;
    input      [127:0] in;
    input      [7:0]   rcon;
    output     [127:0] out_1;
    output     [127:0] out_2;

    wire       [31:0]  k0, k1, k2, k3,
                       v0, v1, v2, v3;
    reg [127:0] out_1;
    reg        [31:0]  k0a, k1a, k2a, k3a;
    wire       [31:0]  k0b, k1b, k2b, k3b, k4a;

    assign {k0, k1, k2, k3} = in;
    
    assign v0 = {k0[31:24] ^ rcon, k0[23:0]};
    assign v1 = v0 ^ k1;
    assign v2 = v1 ^ k2;
    assign v3 = v2 ^ k3;

    always @ (posedge clk)
        {k0a, k1a, k2a, k3a} <= {v0, v1, v2, v3};  // 1d 

    S4
        S4_0 (clk, {k3[23:0], k3[31:24]}, k4a);  // 1d 

    assign k0b = k0a ^ k4a;
    assign k1b = k1a ^ k4a;
    assign k2b = k2a ^ k4a;
    assign k3b = k3a ^ k4a;

    always @ (posedge clk)
        out_1 <= {k0b, k1b, k2b, k3b}; // 2d 

    assign out_2 = {k0b, k1b, k2b, k3b}; // 1d
endmodule
