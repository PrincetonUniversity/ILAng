/*
 * This wrapper was written by Pramod Subramanyan.
 *
 * Email: pramod.subramanyan@gmail.com
 */ 

// synopsys translate_off
`include "oc8051_timescale.v"
// synopsys translate_on

module reg16byte(clk, rst, en, wr, addr, data_in, data_out, reg_out);
    input           clk;
    input           rst;
    input           en;
    input           wr;
    input   [3:0]   addr;
    input   [7:0]   data_in;
    output  [7:0]   data_out;
    output  [127:0] reg_out;

    reg     [127:0] reg_out;

    wire wr0  = en && wr && addr == 0;
    wire wr1  = en && wr && addr == 1;
    wire wr2  = en && wr && addr == 2;
    wire wr3  = en && wr && addr == 3;
    wire wr4  = en && wr && addr == 4;
    wire wr5  = en && wr && addr == 5;
    wire wr6  = en && wr && addr == 6;
    wire wr7  = en && wr && addr == 7;
    wire wr8  = en && wr && addr == 8;
    wire wr9  = en && wr && addr == 9;
    wire wr10 = en && wr && addr == 10;
    wire wr11 = en && wr && addr == 11;
    wire wr12 = en && wr && addr == 12;
    wire wr13 = en && wr && addr == 13;
    wire wr14 = en && wr && addr == 14;
    wire wr15 = en && wr && addr == 15;

    wire    [7:0]   reg0_next = wr0   ? data_in : reg_out[7:0];
    wire    [7:0]   reg1_next = wr1   ? data_in : reg_out[15:8];
    wire    [7:0]   reg2_next = wr2   ? data_in : reg_out[23:16];
    wire    [7:0]   reg3_next = wr3   ? data_in : reg_out[31:24];
    wire    [7:0]   reg4_next = wr4   ? data_in : reg_out[39:32];
    wire    [7:0]   reg5_next = wr5   ? data_in : reg_out[47:40];
    wire    [7:0]   reg6_next = wr6   ? data_in : reg_out[55:48];
    wire    [7:0]   reg7_next = wr7   ? data_in : reg_out[63:56];
    wire    [7:0]   reg8_next = wr8   ? data_in : reg_out[71:64];
    wire    [7:0]   reg9_next = wr9   ? data_in : reg_out[79:72];
    wire    [7:0]   reg10_next = wr10 ? data_in : reg_out[87:80];
    wire    [7:0]   reg11_next = wr11 ? data_in : reg_out[95:88];
    wire    [7:0]   reg12_next = wr12 ? data_in : reg_out[103:96];
    wire    [7:0]   reg13_next = wr13 ? data_in : reg_out[111:104];
    wire    [7:0]   reg14_next = wr14 ? data_in : reg_out[119:112];
    wire    [7:0]   reg15_next = wr15 ? data_in : reg_out[127:120];

    wire [7:0] data_out_mux = 
                    addr == 4'd0  ? reg_out[7:0]     :
                    addr == 4'd1  ? reg_out[15:8]    :
                    addr == 4'd2  ? reg_out[23:16]   :
                    addr == 4'd3  ? reg_out[31:24]   :
                    addr == 4'd4  ? reg_out[39:32]   :
                    addr == 4'd5  ? reg_out[47:40]   :
                    addr == 4'd6  ? reg_out[55:48]   :
                    addr == 4'd7  ? reg_out[63:56]   :
                    addr == 4'd8  ? reg_out[71:64]   :
                    addr == 4'd9  ? reg_out[79:72]   :
                    addr == 4'd10 ? reg_out[87:80]   :
                    addr == 4'd11 ? reg_out[95:88]   :
                    addr == 4'd12 ? reg_out[103:96]  :
                    addr == 4'd13 ? reg_out[111:104] :
                    addr == 4'd14 ? reg_out[119:112] :
                    reg_out[127:120];
    assign data_out = data_out_mux;

    always @(posedge clk)
    begin
        if (rst) begin
            reg_out <= 128'b0;
        end
        else begin
            reg_out[7:0]     <= reg0_next;
            reg_out[15:8]    <= reg1_next;
            reg_out[23:16]   <= reg2_next;
            reg_out[31:24]   <= reg3_next;
            reg_out[39:32]   <= reg4_next;
            reg_out[47:40]   <= reg5_next;
            reg_out[55:48]   <= reg6_next;
            reg_out[63:56]   <= reg7_next;
            reg_out[71:64]   <= reg8_next;
            reg_out[79:72]   <= reg9_next;
            reg_out[87:80]   <= reg10_next;
            reg_out[95:88]   <= reg11_next;
            reg_out[103:96]  <= reg12_next;
            reg_out[111:104] <= reg13_next;
            reg_out[119:112] <= reg14_next;
            reg_out[127:120] <= reg15_next;
        end
    end
endmodule
