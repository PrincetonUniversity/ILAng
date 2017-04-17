module SPEC_A(
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
gbit,
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
output      [3:0] gbit;
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
reg      [3:0] gbit;
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
wire            n11;
wire            n12;
wire            n13;
wire            n14;
wire      [7:0] n15;
wire            n16;
wire            n17;
wire            n18;
wire      [3:0] n19;
wire      [3:0] n20;
wire      [3:0] n21;
wire     [71:0] n22;
wire     [71:0] n23;
wire     [71:0] n24;
wire     [71:0] n25;
wire     [71:0] n26;
wire     [71:0] n27;
wire     [71:0] n28;
wire     [71:0] n29;
wire     [71:0] n30;
wire            n31;
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
assign n9 =  ( gbit ) == ( 4'd0 )  ;
assign n10 =  ( gbit ) == ( 4'd7 )  ;
assign n11 =  ( n9 ) | ( n10 )  ;
assign n12 =  ( n11 ) ? ( 1'd0 ) : ( 1'd1 ) ;
assign n13 =  ( n4 ) ? ( n12 ) : ( arg_0_TVALID ) ;
assign n14 =  ( n4 ) ? ( arg_1_TREADY ) : ( arg_1_TREADY ) ;
assign n15 =  ( n4 ) ? ( cur_pix ) : ( cur_pix ) ;
assign n16 =  ( RAM_x ) == ( 9'd488 )  ;
assign n17 =  ( RAM_y ) == ( 10'd648 )  ;
assign n18 =  ( n16 ) & ( n17 )  ;
assign n19 =  ( gbit ) + ( 4'd1 )  ;
assign n20 =  ( n18 ) ? ( n19 ) : ( gbit ) ;
assign n21 =  ( n4 ) ? ( n20 ) : ( gbit ) ;
assign n22 =  ( n4 ) ? ( stencil_0 ) : ( stencil_0 ) ;
assign n23 =  ( n4 ) ? ( stencil_1 ) : ( stencil_1 ) ;
assign n24 =  ( n4 ) ? ( stencil_2 ) : ( stencil_2 ) ;
assign n25 =  ( n4 ) ? ( stencil_3 ) : ( stencil_3 ) ;
assign n26 =  ( n4 ) ? ( stencil_4 ) : ( stencil_4 ) ;
assign n27 =  ( n4 ) ? ( stencil_5 ) : ( stencil_5 ) ;
assign n28 =  ( n4 ) ? ( stencil_6 ) : ( stencil_6 ) ;
assign n29 =  ( n4 ) ? ( stencil_7 ) : ( stencil_7 ) ;
assign n30 =  ( n4 ) ? ( stencil_8 ) : ( stencil_8 ) ;
assign n31 = ~ ( n4 ) ;
/*
function [7:0] gb_fun ;
input [647:0] arg0;
    begin
//TODO: Add the specific function HERE.    end
endfunction
*/

always @(posedge clk) begin
   if(rst) begin
       RAM_w <= RAM_w;
       RAM_x <= RAM_x;
       RAM_y <= RAM_y;
       arg_0_TDATA <= arg_0_TDATA;
       arg_0_TVALID <= arg_0_TVALID;
       arg_1_TREADY <= arg_1_TREADY;
       cur_pix <= cur_pix;
       gbit <= gbit;
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
       arg_0_TVALID <= n13;
       arg_1_TREADY <= n14;
       cur_pix <= n15;
       gbit <= n21;
       stencil_0 <= n22;
       stencil_1 <= n23;
       stencil_2 <= n24;
       stencil_3 <= n25;
       stencil_4 <= n26;
       stencil_5 <= n27;
       stencil_6 <= n28;
       stencil_7 <= n29;
       stencil_8 <= n30;
   end
end
endmodule
