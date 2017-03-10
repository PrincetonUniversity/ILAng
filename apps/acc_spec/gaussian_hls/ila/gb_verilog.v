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
wire            n5;
wire            n6;
wire            n7;
wire            n8;
wire            n9;
wire      [7:0] n10;
wire      [7:0] n11;
wire     [63:0] n12;
wire     [63:0] n13;
wire      [8:0] n14;
wire      [8:0] n15;
wire      [9:0] n16;
wire      [9:0] n17;
wire     [71:0] n18;
wire     [71:0] n19;
wire     [71:0] n20;
wire     [71:0] n21;
wire     [71:0] n22;
wire     [71:0] n23;
wire     [71:0] n24;
wire     [71:0] n25;
wire     [71:0] n26;
wire     [71:0] n27;
wire     [71:0] n28;
wire     [71:0] n29;
wire     [71:0] n30;
wire     [71:0] n31;
wire     [71:0] n32;
wire     [71:0] n33;
wire      [8:0] n34;
wire      [8:0] n35;
wire      [9:0] n36;
wire      [9:0] n37;
wire      [7:0] n38;
wire      [7:0] n39;
wire            n40;
wire            n41;
wire            n42;
wire            n43;
wire      [7:0] n44;
wire      [7:0] n45;
wire      [7:0] n46;
wire      [7:0] n47;
wire            n48;
wire            n49;
wire            n50;
wire            n51;
wire     [71:0] n52;
wire     [71:0] n53;
wire     [71:0] n54;
wire     [71:0] n55;
wire            n56;
wire            n57;
wire            n58;
wire            n59;
wire    [647:0] n60;
wire    [647:0] n61;
wire    [647:0] n62;
wire    [647:0] n63;
wire            n64;
wire            n65;
wire            n66;
wire            n67;
wire            n68;
wire            n69;
wire            n70;
wire            n71;
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
assign n0 =  ( arg_0_TREADY ) == ( 1'd1 )  ;
assign n1 =  ( arg_0_TVALID ) == ( 1'd1 )  ;
assign n2 =  ( n0 ) & ( n1 )  ;
assign n3 =  ( arg_1_TVALID ) == ( 1'd0 )  ;
assign n4 =  ( n2 ) & ( n3 )  ;
assign n5 =  ( arg_1_TREADY ) == ( 1'd1 )  ;
assign n6 =  ( arg_1_TVALID ) == ( 1'd1 )  ;
assign n7 =  ( n5 ) & ( n6 )  ;
assign n8 =  ( arg_0_TREADY ) == ( 1'd0 )  ;
assign n9 =  ( n7 ) & ( n8 )  ;
assign n10 =  ( n9 ) ? ( arg_1_TDATA ) : ( LB1D_buff ) ;
assign n11 =  ( n4 ) ? ( arg_1_TDATA ) : ( n10 ) ;
assign n12 =  ( n9 ) ? ( LB2D_proc_w ) : ( LB2D_proc_w ) ;
assign n13 =  ( n4 ) ? ( LB2D_proc_w ) : ( n12 ) ;
assign n14 =  ( n9 ) ? ( LB2D_proc_x ) : ( LB2D_proc_x ) ;
assign n15 =  ( n4 ) ? ( LB2D_proc_x ) : ( n14 ) ;
assign n16 =  ( n9 ) ? ( LB2D_proc_y ) : ( LB2D_proc_y ) ;
assign n17 =  ( n4 ) ? ( LB2D_proc_y ) : ( n16 ) ;
assign n18 =  ( n9 ) ? ( LB2D_shift_0 ) : ( LB2D_shift_0 ) ;
assign n19 =  ( n4 ) ? ( LB2D_shift_0 ) : ( n18 ) ;
assign n20 =  ( n9 ) ? ( LB2D_shift_1 ) : ( LB2D_shift_1 ) ;
assign n21 =  ( n4 ) ? ( LB2D_shift_1 ) : ( n20 ) ;
assign n22 =  ( n9 ) ? ( LB2D_shift_2 ) : ( LB2D_shift_2 ) ;
assign n23 =  ( n4 ) ? ( LB2D_shift_2 ) : ( n22 ) ;
assign n24 =  ( n9 ) ? ( LB2D_shift_3 ) : ( LB2D_shift_3 ) ;
assign n25 =  ( n4 ) ? ( LB2D_shift_3 ) : ( n24 ) ;
assign n26 =  ( n9 ) ? ( LB2D_shift_4 ) : ( LB2D_shift_4 ) ;
assign n27 =  ( n4 ) ? ( LB2D_shift_4 ) : ( n26 ) ;
assign n28 =  ( n9 ) ? ( LB2D_shift_5 ) : ( LB2D_shift_5 ) ;
assign n29 =  ( n4 ) ? ( LB2D_shift_5 ) : ( n28 ) ;
assign n30 =  ( n9 ) ? ( LB2D_shift_6 ) : ( LB2D_shift_6 ) ;
assign n31 =  ( n4 ) ? ( LB2D_shift_6 ) : ( n30 ) ;
assign n32 =  ( n9 ) ? ( LB2D_shift_7 ) : ( LB2D_shift_7 ) ;
assign n33 =  ( n4 ) ? ( LB2D_shift_7 ) : ( n32 ) ;
assign n34 =  ( n9 ) ? ( LB2D_shift_x ) : ( LB2D_shift_x ) ;
assign n35 =  ( n4 ) ? ( LB2D_shift_x ) : ( n34 ) ;
assign n36 =  ( n9 ) ? ( LB2D_shift_y ) : ( LB2D_shift_y ) ;
assign n37 =  ( n4 ) ? ( LB2D_shift_y ) : ( n36 ) ;
assign n38 =  ( n9 ) ? ( arg_0_TDATA ) : ( arg_0_TDATA ) ;
assign n39 =  ( n4 ) ? ( arg_0_TDATA ) : ( n38 ) ;
assign n40 =  ( n9 ) ? ( arg_0_TVALID ) : ( arg_0_TVALID ) ;
assign n41 =  ( n4 ) ? ( 1'd0 ) : ( n40 ) ;
assign n42 =  ( n9 ) ? ( 1'd0 ) : ( arg_1_TREADY ) ;
assign n43 =  ( n4 ) ? ( 1'd0 ) : ( n42 ) ;
assign n44 =  ( n9 ) ? ( in_stream_buff_0 ) : ( in_stream_buff_0 ) ;
assign n45 =  ( n4 ) ? ( in_stream_buff_0 ) : ( n44 ) ;
assign n46 =  ( n9 ) ? ( in_stream_buff_1 ) : ( in_stream_buff_1 ) ;
assign n47 =  ( n4 ) ? ( in_stream_buff_1 ) : ( n46 ) ;
assign n48 =  ( n9 ) ? ( in_stream_empty ) : ( in_stream_empty ) ;
assign n49 =  ( n4 ) ? ( in_stream_empty ) : ( n48 ) ;
assign n50 =  ( n9 ) ? ( in_stream_full ) : ( in_stream_full ) ;
assign n51 =  ( n4 ) ? ( in_stream_full ) : ( n50 ) ;
assign n52 =  ( n9 ) ? ( slice_stream_buff_0 ) : ( slice_stream_buff_0 ) ;
assign n53 =  ( n4 ) ? ( slice_stream_buff_0 ) : ( n52 ) ;
assign n54 =  ( n9 ) ? ( slice_stream_buff_1 ) : ( slice_stream_buff_1 ) ;
assign n55 =  ( n4 ) ? ( slice_stream_buff_1 ) : ( n54 ) ;
assign n56 =  ( n9 ) ? ( slice_stream_empty ) : ( slice_stream_empty ) ;
assign n57 =  ( n4 ) ? ( slice_stream_empty ) : ( n56 ) ;
assign n58 =  ( n9 ) ? ( slice_stream_full ) : ( slice_stream_full ) ;
assign n59 =  ( n4 ) ? ( slice_stream_full ) : ( n58 ) ;
assign n60 =  ( n9 ) ? ( stencil_stream_buff_0 ) : ( stencil_stream_buff_0 ) ;
assign n61 =  ( n4 ) ? ( stencil_stream_buff_0 ) : ( n60 ) ;
assign n62 =  ( n9 ) ? ( stencil_stream_buff_1 ) : ( stencil_stream_buff_1 ) ;
assign n63 =  ( n4 ) ? ( stencil_stream_buff_1 ) : ( n62 ) ;
assign n64 =  ( n9 ) ? ( stencil_stream_empty ) : ( stencil_stream_empty ) ;
assign n65 =  ( n4 ) ? ( stencil_stream_empty ) : ( n64 ) ;
assign n66 =  ( n9 ) ? ( stencil_stream_full ) : ( stencil_stream_full ) ;
assign n67 =  ( n4 ) ? ( stencil_stream_full ) : ( n66 ) ;
assign n68 = ~ ( n4 ) ;
assign n69 = ~ ( n9 ) ;
assign n70 =  ( n68 ) & ( n69 )  ;
assign n71 =  ( n68 ) & ( n9 )  ;
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
       LB1D_buff <= n11;
       LB2D_proc_w <= n13;
       LB2D_proc_x <= n15;
       LB2D_proc_y <= n17;
       LB2D_shift_0 <= n19;
       LB2D_shift_1 <= n21;
       LB2D_shift_2 <= n23;
       LB2D_shift_3 <= n25;
       LB2D_shift_4 <= n27;
       LB2D_shift_5 <= n29;
       LB2D_shift_6 <= n31;
       LB2D_shift_7 <= n33;
       LB2D_shift_x <= n35;
       LB2D_shift_y <= n37;
       arg_0_TDATA <= n39;
       arg_0_TVALID <= n41;
       arg_1_TREADY <= n43;
       in_stream_buff_0 <= n45;
       in_stream_buff_1 <= n47;
       in_stream_empty <= n49;
       in_stream_full <= n51;
       slice_stream_buff_0 <= n53;
       slice_stream_buff_1 <= n55;
       slice_stream_empty <= n57;
       slice_stream_full <= n59;
       stencil_stream_buff_0 <= n61;
       stencil_stream_buff_1 <= n63;
       stencil_stream_empty <= n65;
       stencil_stream_full <= n67;
   end
end
endmodule
