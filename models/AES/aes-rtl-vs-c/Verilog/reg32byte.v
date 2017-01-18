// synopsys translate_off
`include "oc8051_timescale.v"
// synopsys translate_on

module reg32byte(clk, rst, en, wr, addr, data_in, data_out, reg_out);
    input           clk;
    input           rst;
    input           en;
    input           wr;
    input   [4:0]   addr;
    input   [7:0]   data_in;
    output  [7:0]   data_out;
    output  [255:0] reg_out;

    reg     [7:0] reg_data [31:0];
    wire    [255:0] reg_out;

    assign data_out = en ? reg_data[addr] : 8'h00;

    assign reg_out = { reg_data[31], reg_data[30], reg_data[29], reg_data[28], reg_data[27], 
                       reg_data[26], reg_data[25], reg_data[24], reg_data[23], reg_data[22], 
                       reg_data[21], reg_data[20], reg_data[19], reg_data[18], reg_data[17], 
                       reg_data[16], reg_data[15], reg_data[14], reg_data[13], reg_data[12], 
                       reg_data[11], reg_data[10], reg_data[9],  reg_data[8],  reg_data[7], 
                       reg_data[6],  reg_data[5],  reg_data[4],  reg_data[3],  reg_data[2], 
                       reg_data[1],  reg_data[0] };

    integer i;
    always @(posedge clk)
    begin
        if (rst) begin
            for (i=0; i < 32; i=i+1) begin
                reg_data[i] <= 8'b0;
            end
        end
        else begin
            if (wr && en) begin
                reg_data[addr] <= data_in;
            end
        end
    end
endmodule
