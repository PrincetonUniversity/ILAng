module vtb();
    reg clk;
    reg rst;

    initial begin

        $dumpfile("test.vcd");
        $dumpvars;

        clk = 0; rst = 0;
        #1 rst = 1;
        #4 clk = 1;
        #5 clk = 0;
        #1 rst = 0;
        #4 clk = 1;
        forever #5 clk = ~ clk;
    end

    reg [127:0] state;
    reg [127:0] key;


    always @(posedge clk) begin
        state <= $random;
        key   <= $random;
    end

    vtop vt( .clk(clk),.rst(rst), .state(state) , .key(key) );

endmodule
