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
wire            n10;
wire            n11;
wire            n12;
wire      [7:0] n13;
wire      [7:0] n14;
wire      [7:0] n15;
wire     [63:0] n16;
wire     [63:0] n17;
wire     [63:0] n18;
wire      [8:0] n19;
wire      [8:0] n20;
wire      [8:0] n21;
wire      [9:0] n22;
wire      [9:0] n23;
wire      [9:0] n24;
wire     [71:0] n25;
wire     [71:0] n26;
wire     [71:0] n27;
wire     [71:0] n28;
wire     [71:0] n29;
wire     [71:0] n30;
wire     [71:0] n31;
wire     [71:0] n32;
wire     [71:0] n33;
wire     [71:0] n34;
wire     [71:0] n35;
wire     [71:0] n36;
wire     [71:0] n37;
wire     [71:0] n38;
wire     [71:0] n39;
wire     [71:0] n40;
wire     [71:0] n41;
wire     [71:0] n42;
wire     [71:0] n43;
wire     [71:0] n44;
wire     [71:0] n45;
wire     [71:0] n46;
wire     [71:0] n47;
wire     [71:0] n48;
wire      [8:0] n49;
wire      [8:0] n50;
wire      [8:0] n51;
wire      [9:0] n52;
wire      [9:0] n53;
wire      [9:0] n54;
wire      [7:0] n55;
wire      [7:0] n56;
wire      [7:0] n57;
wire            n58;
wire            n59;
wire            n60;
wire            n61;
wire            n62;
wire            n63;
wire      [7:0] n64;
wire      [7:0] n65;
wire      [7:0] n66;
wire      [7:0] n67;
wire      [7:0] n68;
wire      [7:0] n69;
wire            n70;
wire            n71;
wire            n72;
wire            n73;
wire            n74;
wire            n75;
wire            n76;
wire            n77;
wire     [71:0] n78;
wire     [71:0] n79;
wire     [71:0] n80;
wire     [71:0] n81;
wire     [71:0] n82;
wire     [71:0] n83;
wire            n84;
wire            n85;
wire            n86;
wire            n87;
wire            n88;
wire            n89;
wire    [647:0] n90;
wire    [647:0] n91;
wire    [647:0] n92;
wire    [647:0] n93;
wire    [647:0] n94;
wire    [647:0] n95;
wire            n96;
wire            n97;
wire            n98;
wire            n99;
wire            n100;
wire            n101;
wire            n102;
wire            n103;
wire            n104;
wire            n105;
wire            n106;
wire            n107;
wire            n108;
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
assign n0 =  ( arg_1_TREADY ) == ( 1'd0 )  ;
assign n1 =  ( in_stream_full ) == ( 1'd0 )  ;
assign n2 =  ( n0 ) & ( n1 )  ;
assign n3 =  ( arg_0_TREADY ) == ( 1'd1 )  ;
assign n4 =  ( arg_0_TVALID ) == ( 1'd1 )  ;
assign n5 =  ( n3 ) & ( n4 )  ;
assign n6 =  ( arg_1_TVALID ) == ( 1'd0 )  ;
assign n7 =  ( n5 ) & ( n6 )  ;
assign n8 =  ( arg_1_TREADY ) == ( 1'd1 )  ;
assign n9 =  ( arg_1_TVALID ) == ( 1'd1 )  ;
assign n10 =  ( n8 ) & ( n9 )  ;
assign n11 =  ( arg_0_TREADY ) == ( 1'd0 )  ;
assign n12 =  ( n10 ) & ( n11 )  ;
assign n13 =  ( n12 ) ? ( arg_1_TDATA ) : ( LB1D_buff ) ;
assign n14 =  ( n7 ) ? ( arg_1_TDATA ) : ( n13 ) ;
assign n15 =  ( n2 ) ? ( LB1D_buff ) : ( n14 ) ;
assign n16 =  ( n12 ) ? ( LB2D_proc_w ) : ( LB2D_proc_w ) ;
assign n17 =  ( n7 ) ? ( LB2D_proc_w ) : ( n16 ) ;
assign n18 =  ( n2 ) ? ( LB2D_proc_w ) : ( n17 ) ;
assign n19 =  ( n12 ) ? ( LB2D_proc_x ) : ( LB2D_proc_x ) ;
assign n20 =  ( n7 ) ? ( LB2D_proc_x ) : ( n19 ) ;
assign n21 =  ( n2 ) ? ( LB2D_proc_x ) : ( n20 ) ;
assign n22 =  ( n12 ) ? ( LB2D_proc_y ) : ( LB2D_proc_y ) ;
assign n23 =  ( n7 ) ? ( LB2D_proc_y ) : ( n22 ) ;
assign n24 =  ( n2 ) ? ( LB2D_proc_y ) : ( n23 ) ;
assign n25 =  ( n12 ) ? ( LB2D_shift_0 ) : ( LB2D_shift_0 ) ;
assign n26 =  ( n7 ) ? ( LB2D_shift_0 ) : ( n25 ) ;
assign n27 =  ( n2 ) ? ( LB2D_shift_0 ) : ( n26 ) ;
assign n28 =  ( n12 ) ? ( LB2D_shift_1 ) : ( LB2D_shift_1 ) ;
assign n29 =  ( n7 ) ? ( LB2D_shift_1 ) : ( n28 ) ;
assign n30 =  ( n2 ) ? ( LB2D_shift_1 ) : ( n29 ) ;
assign n31 =  ( n12 ) ? ( LB2D_shift_2 ) : ( LB2D_shift_2 ) ;
assign n32 =  ( n7 ) ? ( LB2D_shift_2 ) : ( n31 ) ;
assign n33 =  ( n2 ) ? ( LB2D_shift_2 ) : ( n32 ) ;
assign n34 =  ( n12 ) ? ( LB2D_shift_3 ) : ( LB2D_shift_3 ) ;
assign n35 =  ( n7 ) ? ( LB2D_shift_3 ) : ( n34 ) ;
assign n36 =  ( n2 ) ? ( LB2D_shift_3 ) : ( n35 ) ;
assign n37 =  ( n12 ) ? ( LB2D_shift_4 ) : ( LB2D_shift_4 ) ;
assign n38 =  ( n7 ) ? ( LB2D_shift_4 ) : ( n37 ) ;
assign n39 =  ( n2 ) ? ( LB2D_shift_4 ) : ( n38 ) ;
assign n40 =  ( n12 ) ? ( LB2D_shift_5 ) : ( LB2D_shift_5 ) ;
assign n41 =  ( n7 ) ? ( LB2D_shift_5 ) : ( n40 ) ;
assign n42 =  ( n2 ) ? ( LB2D_shift_5 ) : ( n41 ) ;
assign n43 =  ( n12 ) ? ( LB2D_shift_6 ) : ( LB2D_shift_6 ) ;
assign n44 =  ( n7 ) ? ( LB2D_shift_6 ) : ( n43 ) ;
assign n45 =  ( n2 ) ? ( LB2D_shift_6 ) : ( n44 ) ;
assign n46 =  ( n12 ) ? ( LB2D_shift_7 ) : ( LB2D_shift_7 ) ;
assign n47 =  ( n7 ) ? ( LB2D_shift_7 ) : ( n46 ) ;
assign n48 =  ( n2 ) ? ( LB2D_shift_7 ) : ( n47 ) ;
assign n49 =  ( n12 ) ? ( LB2D_shift_x ) : ( LB2D_shift_x ) ;
assign n50 =  ( n7 ) ? ( LB2D_shift_x ) : ( n49 ) ;
assign n51 =  ( n2 ) ? ( LB2D_shift_x ) : ( n50 ) ;
assign n52 =  ( n12 ) ? ( LB2D_shift_y ) : ( LB2D_shift_y ) ;
assign n53 =  ( n7 ) ? ( LB2D_shift_y ) : ( n52 ) ;
assign n54 =  ( n2 ) ? ( LB2D_shift_y ) : ( n53 ) ;
assign n55 =  ( n12 ) ? ( arg_0_TDATA ) : ( arg_0_TDATA ) ;
assign n56 =  ( n7 ) ? ( arg_0_TDATA ) : ( n55 ) ;
assign n57 =  ( n2 ) ? ( arg_0_TDATA ) : ( n56 ) ;
assign n58 =  ( n12 ) ? ( arg_0_TVALID ) : ( arg_0_TVALID ) ;
assign n59 =  ( n7 ) ? ( 1'd0 ) : ( n58 ) ;
assign n60 =  ( n2 ) ? ( arg_0_TVALID ) : ( n59 ) ;
assign n61 =  ( n12 ) ? ( 1'd0 ) : ( arg_1_TREADY ) ;
assign n62 =  ( n7 ) ? ( 1'd0 ) : ( n61 ) ;
assign n63 =  ( n2 ) ? ( 1'd1 ) : ( n62 ) ;
assign n64 =  ( n12 ) ? ( in_stream_buff_0 ) : ( in_stream_buff_0 ) ;
assign n65 =  ( n7 ) ? ( in_stream_buff_0 ) : ( n64 ) ;
assign n66 =  ( n2 ) ? ( LB1D_buff ) : ( n65 ) ;
assign n67 =  ( n12 ) ? ( in_stream_buff_1 ) : ( in_stream_buff_1 ) ;
assign n68 =  ( n7 ) ? ( in_stream_buff_1 ) : ( n67 ) ;
assign n69 =  ( n2 ) ? ( in_stream_buff_0 ) : ( n68 ) ;
assign n70 =  ( n12 ) ? ( in_stream_empty ) : ( in_stream_empty ) ;
assign n71 =  ( n7 ) ? ( in_stream_empty ) : ( n70 ) ;
assign n72 =  ( n2 ) ? ( 1'd0 ) : ( n71 ) ;
assign n73 =  ( in_stream_empty ) == ( 1'd1 )  ;
assign n74 =  ( n73 ) ? ( 1'd0 ) : ( 1'd1 ) ;
assign n75 =  ( n12 ) ? ( in_stream_full ) : ( in_stream_full ) ;
assign n76 =  ( n7 ) ? ( in_stream_full ) : ( n75 ) ;
assign n77 =  ( n2 ) ? ( n74 ) : ( n76 ) ;
assign n78 =  ( n12 ) ? ( slice_stream_buff_0 ) : ( slice_stream_buff_0 ) ;
assign n79 =  ( n7 ) ? ( slice_stream_buff_0 ) : ( n78 ) ;
assign n80 =  ( n2 ) ? ( slice_stream_buff_0 ) : ( n79 ) ;
assign n81 =  ( n12 ) ? ( slice_stream_buff_1 ) : ( slice_stream_buff_1 ) ;
assign n82 =  ( n7 ) ? ( slice_stream_buff_1 ) : ( n81 ) ;
assign n83 =  ( n2 ) ? ( slice_stream_buff_1 ) : ( n82 ) ;
assign n84 =  ( n12 ) ? ( slice_stream_empty ) : ( slice_stream_empty ) ;
assign n85 =  ( n7 ) ? ( slice_stream_empty ) : ( n84 ) ;
assign n86 =  ( n2 ) ? ( slice_stream_empty ) : ( n85 ) ;
assign n87 =  ( n12 ) ? ( slice_stream_full ) : ( slice_stream_full ) ;
assign n88 =  ( n7 ) ? ( slice_stream_full ) : ( n87 ) ;
assign n89 =  ( n2 ) ? ( slice_stream_full ) : ( n88 ) ;
assign n90 =  ( n12 ) ? ( stencil_stream_buff_0 ) : ( stencil_stream_buff_0 ) ;
assign n91 =  ( n7 ) ? ( stencil_stream_buff_0 ) : ( n90 ) ;
assign n92 =  ( n2 ) ? ( stencil_stream_buff_0 ) : ( n91 ) ;
assign n93 =  ( n12 ) ? ( stencil_stream_buff_1 ) : ( stencil_stream_buff_1 ) ;
assign n94 =  ( n7 ) ? ( stencil_stream_buff_1 ) : ( n93 ) ;
assign n95 =  ( n2 ) ? ( stencil_stream_buff_1 ) : ( n94 ) ;
assign n96 =  ( n12 ) ? ( stencil_stream_empty ) : ( stencil_stream_empty ) ;
assign n97 =  ( n7 ) ? ( stencil_stream_empty ) : ( n96 ) ;
assign n98 =  ( n2 ) ? ( stencil_stream_empty ) : ( n97 ) ;
assign n99 =  ( n12 ) ? ( stencil_stream_full ) : ( stencil_stream_full ) ;
assign n100 =  ( n7 ) ? ( stencil_stream_full ) : ( n99 ) ;
assign n101 =  ( n2 ) ? ( stencil_stream_full ) : ( n100 ) ;
assign n102 = ~ ( n2 ) ;
assign n103 = ~ ( n7 ) ;
assign n104 =  ( n102 ) & ( n103 )  ;
assign n105 = ~ ( n12 ) ;
assign n106 =  ( n104 ) & ( n105 )  ;
assign n107 =  ( n104 ) & ( n12 )  ;
assign n108 =  ( n102 ) & ( n7 )  ;
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
       LB1D_buff <= n15;
       LB2D_proc_w <= n18;
       LB2D_proc_x <= n21;
       LB2D_proc_y <= n24;
       LB2D_shift_0 <= n27;
       LB2D_shift_1 <= n30;
       LB2D_shift_2 <= n33;
       LB2D_shift_3 <= n36;
       LB2D_shift_4 <= n39;
       LB2D_shift_5 <= n42;
       LB2D_shift_6 <= n45;
       LB2D_shift_7 <= n48;
       LB2D_shift_x <= n51;
       LB2D_shift_y <= n54;
       arg_0_TDATA <= n57;
       arg_0_TVALID <= n60;
       arg_1_TREADY <= n63;
       in_stream_buff_0 <= n66;
       in_stream_buff_1 <= n69;
       in_stream_empty <= n72;
       in_stream_full <= n77;
       slice_stream_buff_0 <= n80;
       slice_stream_buff_1 <= n83;
       slice_stream_empty <= n86;
       slice_stream_full <= n89;
       stencil_stream_buff_0 <= n92;
       stencil_stream_buff_1 <= n95;
       stencil_stream_empty <= n98;
       stencil_stream_full <= n101;
   end
end
endmodule
