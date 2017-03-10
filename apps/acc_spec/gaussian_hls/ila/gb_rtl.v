module GB(
arg_0_TREADY,
arg_1_TDATA,
arg_1_TVALID,
LB1D_buff,
LB2D_proc_w,
LB2D_proc_x,
LB2D_proc_y,
LB2D_shift_0,
LB2D_shift_1,
LB2D_shift_2,
LB2D_shift_3,
LB2D_shift_4,
LB2D_shift_5,
LB2D_shift_6,
LB2D_shift_7,
LB2D_shift_x,
LB2D_shift_y,
arg_0_TDATA,
arg_0_TVALID,
arg_1_TREADY,
in_stream_buff_0,
in_stream_buff_1,
in_stream_empty,
in_stream_full,
slice_stream_buff_0,
slice_stream_buff_1,
slice_stream_empty,
slice_stream_full,
stencil_stream_buff_0,
stencil_stream_buff_1,
stencil_stream_empty,
stencil_stream_full,
clk,rst,
step
);
input            arg_0_TREADY;
input      [7:0] arg_1_TDATA;
input            arg_1_TVALID;
input clk;
input rst;
input step;
output      [7:0] LB1D_buff;
output     [63:0] LB2D_proc_w;
output      [8:0] LB2D_proc_x;
output      [9:0] LB2D_proc_y;
output     [71:0] LB2D_shift_0;
output     [71:0] LB2D_shift_1;
output     [71:0] LB2D_shift_2;
output     [71:0] LB2D_shift_3;
output     [71:0] LB2D_shift_4;
output     [71:0] LB2D_shift_5;
output     [71:0] LB2D_shift_6;
output     [71:0] LB2D_shift_7;
output      [8:0] LB2D_shift_x;
output      [9:0] LB2D_shift_y;
output      [7:0] arg_0_TDATA;
output            arg_0_TVALID;
output            arg_1_TREADY;
output      [7:0] in_stream_buff_0;
output      [7:0] in_stream_buff_1;
output            in_stream_empty;
output            in_stream_full;
output     [71:0] slice_stream_buff_0;
output     [71:0] slice_stream_buff_1;
output            slice_stream_empty;
output            slice_stream_full;
output    [647:0] stencil_stream_buff_0;
output    [647:0] stencil_stream_buff_1;
output            stencil_stream_empty;
output            stencil_stream_full;
reg      [7:0] LB1D_buff;
reg     [63:0] LB2D_proc_w;
reg      [8:0] LB2D_proc_x;
reg      [9:0] LB2D_proc_y;
reg     [71:0] LB2D_shift_0;
reg     [71:0] LB2D_shift_1;
reg     [71:0] LB2D_shift_2;
reg     [71:0] LB2D_shift_3;
reg     [71:0] LB2D_shift_4;
reg     [71:0] LB2D_shift_5;
reg     [71:0] LB2D_shift_6;
reg     [71:0] LB2D_shift_7;
reg      [8:0] LB2D_shift_x;
reg      [9:0] LB2D_shift_y;
reg      [7:0] arg_0_TDATA;
reg            arg_0_TVALID;
reg            arg_1_TREADY;
reg      [7:0] in_stream_buff_0;
reg      [7:0] in_stream_buff_1;
reg            in_stream_empty;
reg            in_stream_full;
reg     [71:0] slice_stream_buff_0;
reg     [71:0] slice_stream_buff_1;
reg            slice_stream_empty;
reg            slice_stream_full;
reg    [647:0] stencil_stream_buff_0;
reg    [647:0] stencil_stream_buff_1;
reg            stencil_stream_empty;
reg            stencil_stream_full;
wire            arg_0_TREADY;
wire      [7:0] arg_1_TDATA;
wire            arg_1_TVALID;
wire            n0;
wire            n1;
wire            n2;
wire            n3;
wire            n4;
wire      [7:0] n5;
wire     [63:0] n6;
wire      [8:0] n7;
wire      [9:0] n8;
wire     [71:0] n9;
wire     [71:0] n10;
wire     [71:0] n11;
wire     [71:0] n12;
wire     [71:0] n13;
wire     [71:0] n14;
wire     [71:0] n15;
wire     [71:0] n16;
wire      [8:0] n17;
wire      [9:0] n18;
wire      [7:0] n19;
wire            n20;
wire            n21;
wire      [7:0] n22;
wire      [7:0] n23;
wire            n24;
wire            n25;
wire     [71:0] n26;
wire     [71:0] n27;
wire            n28;
wire            n29;
wire    [647:0] n30;
wire    [647:0] n31;
wire            n32;
wire            n33;
wire            n34;
reg      [7:0] LB2D_proc_0[511:0];
reg      [7:0] LB2D_proc_1[511:0];
reg      [7:0] LB2D_proc_2[511:0];
reg      [7:0] LB2D_proc_3[511:0];
reg      [7:0] LB2D_proc_4[511:0];
reg      [7:0] LB2D_proc_5[511:0];
reg      [7:0] LB2D_proc_6[511:0];
reg      [7:0] LB2D_proc_7[511:0];
wire clk;
wire rst;
wire step;
assign n0 =  ( arg_1_TREADY ) == ( 1'd1 )  ;
assign n1 =  ( arg_1_TVALID ) == ( 1'd1 )  ;
assign n2 =  ( n0 ) & ( n1 )  ;
assign n3 =  ( arg_0_TREADY ) == ( 1'd0 )  ;
assign n4 =  ( n2 ) & ( n3 )  ;
assign n5 =  ( n4 ) ? ( arg_1_TDATA ) : ( LB1D_buff ) ;
assign n6 =  ( n4 ) ? ( LB2D_proc_w ) : ( LB2D_proc_w ) ;
assign n7 =  ( n4 ) ? ( LB2D_proc_x ) : ( LB2D_proc_x ) ;
assign n8 =  ( n4 ) ? ( LB2D_proc_y ) : ( LB2D_proc_y ) ;
assign n9 =  ( n4 ) ? ( LB2D_shift_0 ) : ( LB2D_shift_0 ) ;
assign n10 =  ( n4 ) ? ( LB2D_shift_1 ) : ( LB2D_shift_1 ) ;
assign n11 =  ( n4 ) ? ( LB2D_shift_2 ) : ( LB2D_shift_2 ) ;
assign n12 =  ( n4 ) ? ( LB2D_shift_3 ) : ( LB2D_shift_3 ) ;
assign n13 =  ( n4 ) ? ( LB2D_shift_4 ) : ( LB2D_shift_4 ) ;
assign n14 =  ( n4 ) ? ( LB2D_shift_5 ) : ( LB2D_shift_5 ) ;
assign n15 =  ( n4 ) ? ( LB2D_shift_6 ) : ( LB2D_shift_6 ) ;
assign n16 =  ( n4 ) ? ( LB2D_shift_7 ) : ( LB2D_shift_7 ) ;
assign n17 =  ( n4 ) ? ( LB2D_shift_x ) : ( LB2D_shift_x ) ;
assign n18 =  ( n4 ) ? ( LB2D_shift_y ) : ( LB2D_shift_y ) ;
assign n19 =  ( n4 ) ? ( arg_0_TDATA ) : ( arg_0_TDATA ) ;
assign n20 =  ( n4 ) ? ( arg_0_TVALID ) : ( arg_0_TVALID ) ;
assign n21 =  ( n4 ) ? ( 1'd0 ) : ( arg_1_TREADY ) ;
assign n22 =  ( n4 ) ? ( in_stream_buff_0 ) : ( in_stream_buff_0 ) ;
assign n23 =  ( n4 ) ? ( in_stream_buff_1 ) : ( in_stream_buff_1 ) ;
assign n24 =  ( n4 ) ? ( in_stream_empty ) : ( in_stream_empty ) ;
assign n25 =  ( n4 ) ? ( in_stream_full ) : ( in_stream_full ) ;
assign n26 =  ( n4 ) ? ( slice_stream_buff_0 ) : ( slice_stream_buff_0 ) ;
assign n27 =  ( n4 ) ? ( slice_stream_buff_1 ) : ( slice_stream_buff_1 ) ;
assign n28 =  ( n4 ) ? ( slice_stream_empty ) : ( slice_stream_empty ) ;
assign n29 =  ( n4 ) ? ( slice_stream_full ) : ( slice_stream_full ) ;
assign n30 =  ( n4 ) ? ( stencil_stream_buff_0 ) : ( stencil_stream_buff_0 ) ;
assign n31 =  ( n4 ) ? ( stencil_stream_buff_1 ) : ( stencil_stream_buff_1 ) ;
assign n32 =  ( n4 ) ? ( stencil_stream_empty ) : ( stencil_stream_empty ) ;
assign n33 =  ( n4 ) ? ( stencil_stream_full ) : ( stencil_stream_full ) ;
assign n34 = ~ ( n4 ) ;
always @(posedge clk) begin
   if(rst) begin
       LB1D_buff <= LB1D_buff;
       LB2D_proc_w <= LB2D_proc_w;
       LB2D_proc_x <= LB2D_proc_x;
       LB2D_proc_y <= LB2D_proc_y;
       LB2D_shift_0 <= LB2D_shift_0;
       LB2D_shift_1 <= LB2D_shift_1;
       LB2D_shift_2 <= LB2D_shift_2;
       LB2D_shift_3 <= LB2D_shift_3;
       LB2D_shift_4 <= LB2D_shift_4;
       LB2D_shift_5 <= LB2D_shift_5;
       LB2D_shift_6 <= LB2D_shift_6;
       LB2D_shift_7 <= LB2D_shift_7;
       LB2D_shift_x <= LB2D_shift_x;
       LB2D_shift_y <= LB2D_shift_y;
       arg_0_TDATA <= arg_0_TDATA;
       arg_0_TVALID <= arg_0_TVALID;
       arg_1_TREADY <= arg_1_TREADY;
       in_stream_buff_0 <= in_stream_buff_0;
       in_stream_buff_1 <= in_stream_buff_1;
       in_stream_empty <= in_stream_empty;
       in_stream_full <= in_stream_full;
       slice_stream_buff_0 <= slice_stream_buff_0;
       slice_stream_buff_1 <= slice_stream_buff_1;
       slice_stream_empty <= slice_stream_empty;
       slice_stream_full <= slice_stream_full;
       stencil_stream_buff_0 <= stencil_stream_buff_0;
       stencil_stream_buff_1 <= stencil_stream_buff_1;
       stencil_stream_empty <= stencil_stream_empty;
       stencil_stream_full <= stencil_stream_full;
   end
   else if(step) begin
       LB1D_buff <= n5;
       LB2D_proc_w <= n6;
       LB2D_proc_x <= n7;
       LB2D_proc_y <= n8;
       LB2D_shift_0 <= n9;
       LB2D_shift_1 <= n10;
       LB2D_shift_2 <= n11;
       LB2D_shift_3 <= n12;
       LB2D_shift_4 <= n13;
       LB2D_shift_5 <= n14;
       LB2D_shift_6 <= n15;
       LB2D_shift_7 <= n16;
       LB2D_shift_x <= n17;
       LB2D_shift_y <= n18;
       arg_0_TDATA <= n19;
       arg_0_TVALID <= n20;
       arg_1_TREADY <= n21;
       in_stream_buff_0 <= n22;
       in_stream_buff_1 <= n23;
       in_stream_empty <= n24;
       in_stream_full <= n25;
       slice_stream_buff_0 <= n26;
       slice_stream_buff_1 <= n27;
       slice_stream_empty <= n28;
       slice_stream_full <= n29;
       stencil_stream_buff_0 <= n30;
       stencil_stream_buff_1 <= n31;
       stencil_stream_empty <= n32;
       stencil_stream_full <= n33;
   end
end
endmodule
