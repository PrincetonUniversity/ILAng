module GB(
arg_0_TREADY,
arg_1_TDATA,
arg_1_TVALID,
RAM_w,
RAM_x,
RAM_y,
arg_0_TDATA,
arg_0_TVALID,
arg_1_TREADY,
clk,rst,
step
);
input            arg_0_TREADY;
input      [7:0] arg_1_TDATA;
input            arg_1_TVALID;
input clk;
input rst;
input step;
output      [2:0] RAM_w;
output      [8:0] RAM_x;
output      [9:0] RAM_y;
output      [7:0] arg_0_TDATA;
output            arg_0_TVALID;
output            arg_1_TREADY;
reg      [2:0] RAM_w;
reg      [8:0] RAM_x;
reg      [9:0] RAM_y;
reg      [7:0] arg_0_TDATA;
reg            arg_0_TVALID;
reg            arg_1_TREADY;
wire            arg_0_TREADY;
wire      [7:0] arg_1_TDATA;
wire            arg_1_TVALID;
wire            n0;
wire            n1;
wire            n2;
reg      [7:0] RAM_0[511:0];
reg      [7:0] RAM_1[511:0];
reg      [7:0] RAM_2[511:0];
reg      [7:0] RAM_3[511:0];
reg      [7:0] RAM_4[511:0];
reg      [7:0] RAM_5[511:0];
reg      [7:0] RAM_6[511:0];
reg      [7:0] RAM_7[511:0];
wire clk;
wire rst;
wire step;
assign n0 =  ( arg_1_TREADY ) == ( 1'd1 )  ;
assign n1 =  ( n0 ) ? ( 1'd0 ) : ( arg_1_TREADY ) ;
assign n2 =  ( n0 ) ? ( arg_1_TREADY ) : ( n1 ) ;
always @(posedge clk) begin
   if(rst) begin
       RAM_w <= RAM_w;
       RAM_x <= RAM_x;
       RAM_y <= RAM_y;
       arg_0_TDATA <= arg_0_TDATA;
       arg_0_TVALID <= arg_0_TVALID;
       arg_1_TREADY <= arg_1_TREADY;
   end
   else if(step) begin
       RAM_w <= RAM_w;
       RAM_x <= RAM_x;
       RAM_y <= RAM_y;
       arg_0_TDATA <= arg_0_TDATA;
       arg_0_TVALID <= arg_0_TVALID;
       arg_1_TREADY <= n2;
   end
end
endmodule
