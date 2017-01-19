module simXramAes_top( 

	data_out,
	cmddata,
	cmd,  // the translation from 2b cmd to 1b cmd is done by c sim wrapper
	cmdaddr,
	ack,
	stb,
	
    aes_state,
    aes_addr,
    aes_len,
    aes_ctr,
    aes_key0,
    aes_step,
	
	clk,
	rst
	
);

input clk;
input rst;


output [7:0] data_out;
input  [7:0] cmddata;
input  		 cmd;
input  [15:0]cmdaddr;
output 		 ack;
input		 stb;



assign data_out = aes_data_out  ;
assign ack =  aes_ack  ;

output [1:0] aes_state;
output [15:0] aes_addr, aes_len;
output [127:0] aes_ctr, aes_key0;
output aes_step;

wire [7:0] aes_data_in = cmddata;
wire [7:0] aes_data_out;

wire aes_wr = cmd  ;
wire aes_stb = stb ;
wire aes_ack;

aes_top aes_top1(
	.clk(clk),
	.rst(rst),
	
	.wr(aes_wr),
	.addr(cmdaddr),
	.data_in(aes_data_in),
	.data_out(aes_data_out),
	.ack(aes_ack),
	.stb(aes_stb),
	
	.xram_addr(xram_addr),
	.xram_data_out(xram_data_out),
	.xram_data_in(xram_data_in),
	.xram_ack(xram_ack),
	.xram_stb(xram_stb),
	.xram_wr(xram_wr),
	
	.aes_state(aes_state),
	.aes_addr(aes_addr),
    .aes_len(aes_len),
    .aes_ctr(aes_ctr),
    .aes_key0(aes_key0),
    .aes_step(aes_step)
);

wire [15:0] xram_addr;
wire [7:0] xram_data_out;
wire [7:0] xram_data_in;
wire xram_ack;
wire xram_stb;
wire xram_wr;


oc8051_xram oc8051_xram1(
	.clk(clk),
	.rst(rst),
	.wr(xram_wr),
	.wr_en(xram_stb),
	.addr(xram_addr),
	.data_in(xram_data_out),
	.data_out(xram_data_in),
	.ack(xram_ack),
	.stb(xram_stb),
	.rd_en(xram_stb)
);

endmodule
