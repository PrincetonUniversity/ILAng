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
cur_pix,
stencil_0,
stencil_1,
stencil_2,
stencil_3,
stencil_4,
stencil_5,
stencil_6,
stencil_7,
stencil_8,
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
output      [7:0] cur_pix;
output     [71:0] stencil_0;
output     [71:0] stencil_1;
output     [71:0] stencil_2;
output     [71:0] stencil_3;
output     [71:0] stencil_4;
output     [71:0] stencil_5;
output     [71:0] stencil_6;
output     [71:0] stencil_7;
output     [71:0] stencil_8;
reg      [2:0] RAM_w;
reg      [8:0] RAM_x;
reg      [9:0] RAM_y;
reg      [7:0] arg_0_TDATA;
reg            arg_0_TVALID;
reg            arg_1_TREADY;
reg      [7:0] cur_pix;
reg     [71:0] stencil_0;
reg     [71:0] stencil_1;
reg     [71:0] stencil_2;
reg     [71:0] stencil_3;
reg     [71:0] stencil_4;
reg     [71:0] stencil_5;
reg     [71:0] stencil_6;
reg     [71:0] stencil_7;
reg     [71:0] stencil_8;
wire            arg_0_TREADY;
wire      [7:0] arg_1_TDATA;
wire            arg_1_TVALID;
wire            n0;
wire            n1;
wire            n2;
wire            n3;
wire            n4;
wire      [2:0] n5;
wire      [8:0] n6;
wire      [9:0] n7;
wire      [7:0] n8;
wire            n9;
wire            n10;
wire      [7:0] n11;
wire     [71:0] n12;
wire     [71:0] n13;
wire     [71:0] n14;
wire     [71:0] n15;
wire     [71:0] n16;
wire     [71:0] n17;
wire     [71:0] n18;
wire     [71:0] n19;
wire     [71:0] n20;
wire            n21;
reg      [7:0] RAM_0[487:0];
reg      [7:0] RAM_1[487:0];
reg      [7:0] RAM_2[487:0];
reg      [7:0] RAM_3[487:0];
reg      [7:0] RAM_4[487:0];
reg      [7:0] RAM_5[487:0];
reg      [7:0] RAM_6[487:0];
reg      [7:0] RAM_7[487:0];
wire clk;
wire rst;
wire step;
assign n0 =  ( arg_1_TVALID ) == ( 1'd0 )  ;
assign n1 =  ( arg_0_TVALID ) == ( 1'd1 )  ;
assign n2 =  ( n0 ) & ( n1 )  ;
assign n3 =  ( arg_0_TREADY ) == ( 1'd1 )  ;
assign n4 =  ( n2 ) & ( n3 )  ;
assign n5 =  ( n4 ) ? ( RAM_w ) : ( RAM_w ) ;
assign n6 =  ( n4 ) ? ( RAM_x ) : ( RAM_x ) ;
assign n7 =  ( n4 ) ? ( RAM_y ) : ( RAM_y ) ;
assign n8 =  ( n4 ) ? ( arg_0_TDATA ) : ( arg_0_TDATA ) ;
assign n9 =  ( n4 ) ? ( 1'd0 ) : ( arg_0_TVALID ) ;
assign n10 =  ( n4 ) ? ( arg_1_TREADY ) : ( arg_1_TREADY ) ;
assign n11 =  ( n4 ) ? ( cur_pix ) : ( cur_pix ) ;
assign n12 =  ( n4 ) ? ( stencil_0 ) : ( stencil_0 ) ;
assign n13 =  ( n4 ) ? ( stencil_1 ) : ( stencil_1 ) ;
assign n14 =  ( n4 ) ? ( stencil_2 ) : ( stencil_2 ) ;
assign n15 =  ( n4 ) ? ( stencil_3 ) : ( stencil_3 ) ;
assign n16 =  ( n4 ) ? ( stencil_4 ) : ( stencil_4 ) ;
assign n17 =  ( n4 ) ? ( stencil_5 ) : ( stencil_5 ) ;
assign n18 =  ( n4 ) ? ( stencil_6 ) : ( stencil_6 ) ;
assign n19 =  ( n4 ) ? ( stencil_7 ) : ( stencil_7 ) ;
assign n20 =  ( n4 ) ? ( stencil_8 ) : ( stencil_8 ) ;
assign n21 = ~ ( n4 ) ;

always @(posedge clk) begin
   if(rst) begin
       RAM_w <= RAM_w;
       RAM_x <= RAM_x;
       RAM_y <= RAM_y;
       arg_0_TDATA <= arg_0_TDATA;
       arg_0_TVALID <= arg_0_TVALID;
       arg_1_TREADY <= arg_1_TREADY;
       cur_pix <= cur_pix;
       stencil_0 <= stencil_0;
       stencil_1 <= stencil_1;
       stencil_2 <= stencil_2;
       stencil_3 <= stencil_3;
       stencil_4 <= stencil_4;
       stencil_5 <= stencil_5;
       stencil_6 <= stencil_6;
       stencil_7 <= stencil_7;
       stencil_8 <= stencil_8;
   end
   else if(step) begin
       RAM_w <= n5;
       RAM_x <= n6;
       RAM_y <= n7;
       arg_0_TDATA <= n8;
       arg_0_TVALID <= n9;
       arg_1_TREADY <= n10;
       cur_pix <= n11;
       stencil_0 <= n12;
       stencil_1 <= n13;
       stencil_2 <= n14;
       stencil_3 <= n15;
       stencil_4 <= n16;
       stencil_5 <= n17;
       stencil_6 <= n18;
       stencil_7 <= n19;
       stencil_8 <= n20;
   end
end
endmodule
