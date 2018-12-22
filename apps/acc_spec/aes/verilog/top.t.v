module top;
    reg clk;
    reg rst;

    reg[15:0] cmdaddr;
    reg[7:0]  cmddata;
    reg       cmd;
    reg       stb;

    initial begin
        $dumpfile("test.vcd");
        $dumpvars();

        clk = 0; #1;
        rst = 1; #1; 
        clk = 1; #1;
        dut.aes_top1.aes_reg_oplen_i.reg_out = 32;
        clk = 0; #1;
        rst = 0; #1;
        cmdaddr = 16'hff00;
        cmd = 1;
        stb = 1;
        cmddata = 1;
        #1; clk = 1;
        #1; clk = 0;
        stb = 0;
        cmd = 0;
        forever #5 clk = ~clk;
    end

    simXramAes_top dut(
        .clk(clk),
        .rst(rst),
        .cmd(cmd),
        .cmddata(cmddata),
        .cmdaddr(cmdaddr),
        .stb(stb)
        );


endmodule