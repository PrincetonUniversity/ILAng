
/* in --1d--> out */

/* S_box, S_box, S_box*(x+1), S_box*x */
module T (clk, in, out);
    input         clk;
    input  [7:0]  in;
    /* verilator lint_off UNOPTFLAT */
    output [31:0] out;
    
    /* verilator lint_off UNOPTFLAT */
    S
        s0 (clk, in, out[31:24]);
    assign out[23:16] = out[31:24];
    xS
        s4 (clk, in, out[7:0]);
    assign out[15:8] = out[23:16] ^ out[7:0];
endmodule
