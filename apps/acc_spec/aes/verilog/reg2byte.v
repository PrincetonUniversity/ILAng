

// synopsys translate_off

`timescale 1ns/10ps

// synopsys translate_on

module reg2byte(clk, rst, en, wr, addr, data_in, data_out, reg_out);
    input           clk;
    input           rst;
    input           en;
    input           wr;
    input           addr;
    input   [7:0]   data_in;
    output  [7:0]   data_out;
    output  [15:0]  reg_out;

    reg     [15:0]  reg_out;

    wire wr0  = en && wr && addr == 0;
    wire wr1  = en && wr && addr == 1;

    wire [7:0] reg0_next = wr0 ? data_in : reg_out[7:0];
    wire [7:0] reg1_next = wr1 ? data_in : reg_out[15:8];

    wire [7:0] data_out_mux = 
                    addr == 1'd0 ? reg_out[7:0] : reg_out[15:8];
    assign data_out = data_out_mux;

    always @(posedge clk)
    begin
        if (rst) begin
            reg_out <= 16'b0;
        end
        else begin
            reg_out[7:0]     <= reg0_next;
            reg_out[15:8]    <= reg1_next;
        end
    end
endmodule
