module proc(
clk,
rst,
__ILA_proc_grant__,
__ILA_proc_valid__,
__ILA_proc_acc_decode__,
__ILA_proc_decode_of_Load__,
__ILA_proc_decode_of_Add__,
__ILA_proc_decode_of_Store__,
pc,
r0,
r1,
r2,
r3,
nouse
);
input            clk;
input            rst;
input      [2:0] __ILA_proc_grant__;
output            __ILA_proc_valid__;
output      [2:0] __ILA_proc_acc_decode__;
output            __ILA_proc_decode_of_Load__;
output            __ILA_proc_decode_of_Add__;
output            __ILA_proc_decode_of_Store__;
output reg      [7:0] pc;
output reg      [7:0] r0;
output reg      [7:0] r1;
output reg      [7:0] r2;
output reg      [7:0] r3;
output reg            nouse;
wire            clk;
wire            rst;
wire            __ILA_proc_valid__;
wire      [2:0] __ILA_proc_grant__;
wire      [2:0] __ILA_proc_acc_decode__;
wire      [7:0] n0;
wire      [1:0] n1;
wire            n2;
wire            __ILA_proc_decode_of_Load__;
wire            n3;
wire            __ILA_proc_decode_of_Add__;
wire            n4;
wire            __ILA_proc_decode_of_Store__;
wire      [7:0] mem_addr0;
wire      [7:0] mem_data0;
wire            mem_wen0;
wire            n5;
wire            n6;
wire            n7;
wire      [3:0] n8;
wire      [7:0] n9;
wire      [1:0] n10;
wire            n11;
wire            n12;
wire            n13;
wire      [7:0] n14;
wire      [7:0] n15;
wire      [7:0] n16;
wire      [7:0] n17;
wire            n18;
wire      [7:0] n19;
wire      [7:0] n20;
wire      [1:0] n21;
wire            n22;
wire            n23;
wire            n24;
wire      [7:0] n25;
wire      [7:0] n26;
wire      [7:0] n27;
wire      [1:0] n28;
wire            n29;
wire            n30;
wire            n31;
wire      [7:0] n32;
wire      [7:0] n33;
wire      [7:0] n34;
wire      [7:0] n35;
wire      [7:0] n36;
wire      [7:0] n37;
wire      [7:0] n38;
wire      [7:0] n39;
wire      [7:0] n40;
wire      [7:0] n41;
wire      [7:0] n42;
reg      [7:0] ir[255:0];
reg      [7:0] mem[255:0];
assign __ILA_proc_valid__ = 1'b1 ;
assign n0 =  (  ir [ pc ] )  ;
assign n1 = n0[7:6] ;
assign n2 =  ( n1 ) == ( 2'd0 )  ;
assign __ILA_proc_decode_of_Load__ = n2 ;
assign __ILA_proc_acc_decode__[0] = __ILA_proc_decode_of_Load__ ;
assign n3 =  ( n1 ) == ( 2'd1 )  ;
assign __ILA_proc_decode_of_Add__ = n3 ;
assign __ILA_proc_acc_decode__[1] = __ILA_proc_decode_of_Add__ ;
assign n4 =  ( n1 ) == ( 2'd2 )  ;
assign __ILA_proc_decode_of_Store__ = n4 ;
assign __ILA_proc_acc_decode__[2] = __ILA_proc_decode_of_Store__ ;
assign n5 = ~ ( n4 )  ;
assign n6 =  ( 1'b1 ) & (n5 )  ;
assign n7 =  ( 1'b1 ) & (n4 )  ;
assign n8 = n0[3:0] ;
assign n9 =  {4'd0 , n8}  ;
assign n10 = n0[5:4] ;
assign n11 =  ( n10 ) == ( 2'd3 )  ;
assign n12 =  ( n10 ) == ( 2'd2 )  ;
assign n13 =  ( n10 ) == ( 2'd1 )  ;
assign n14 =  ( n13 ) ? ( r1 ) : ( r0 ) ;
assign n15 =  ( n12 ) ? ( r2 ) : ( n14 ) ;
assign n16 =  ( n11 ) ? ( r3 ) : ( n15 ) ;
assign mem_addr0 = n7 ? (n9) : (0) ;
assign mem_data0 = n7 ? (n16) : ('d0) ;
assign mem_wen0 = n7 ? ( 1'b1 ) : (1'b0) ;
assign n17 =  ( pc ) + ( 8'd1 )  ;
assign n18 =  ( n10 ) == ( 2'd0 )  ;
assign n19 =  (  mem [ n9 ] )  ;
assign n20 =  ( n18 ) ? ( n19 ) : ( r0 ) ;
assign n21 = n0[3:2] ;
assign n22 =  ( n21 ) == ( 2'd3 )  ;
assign n23 =  ( n21 ) == ( 2'd2 )  ;
assign n24 =  ( n21 ) == ( 2'd1 )  ;
assign n25 =  ( n24 ) ? ( r1 ) : ( r0 ) ;
assign n26 =  ( n23 ) ? ( r2 ) : ( n25 ) ;
assign n27 =  ( n22 ) ? ( r3 ) : ( n26 ) ;
assign n28 = n0[1:0] ;
assign n29 =  ( n28 ) == ( 2'd3 )  ;
assign n30 =  ( n28 ) == ( 2'd2 )  ;
assign n31 =  ( n28 ) == ( 2'd1 )  ;
assign n32 =  ( n31 ) ? ( r1 ) : ( r0 ) ;
assign n33 =  ( n30 ) ? ( r2 ) : ( n32 ) ;
assign n34 =  ( n29 ) ? ( r3 ) : ( n33 ) ;
assign n35 =  ( n27 ) + ( n34 )  ;
assign n36 =  ( n18 ) ? ( n35 ) : ( r0 ) ;
assign n37 =  ( n13 ) ? ( n19 ) : ( r1 ) ;
assign n38 =  ( n13 ) ? ( n35 ) : ( r1 ) ;
assign n39 =  ( n12 ) ? ( n19 ) : ( r2 ) ;
assign n40 =  ( n12 ) ? ( n35 ) : ( r2 ) ;
assign n41 =  ( n11 ) ? ( n19 ) : ( r3 ) ;
assign n42 =  ( n11 ) ? ( n35 ) : ( r3 ) ;
always @(posedge clk) begin
   if(rst) begin
   end
   else if(__ILA_proc_valid__) begin
       if ( __ILA_proc_decode_of_Load__ && __ILA_proc_grant__[0] ) begin
           pc <= n17;
       end else if ( __ILA_proc_decode_of_Add__ && __ILA_proc_grant__[1] ) begin
           pc <= n17;
       end else if ( __ILA_proc_decode_of_Store__ && __ILA_proc_grant__[2] ) begin
           pc <= n17;
       end
       if ( __ILA_proc_decode_of_Load__ && __ILA_proc_grant__[0] ) begin
           r0 <= n20;
       end else if ( __ILA_proc_decode_of_Add__ && __ILA_proc_grant__[1] ) begin
           r0 <= n36;
       end
       if ( __ILA_proc_decode_of_Load__ && __ILA_proc_grant__[0] ) begin
           r1 <= n37;
       end else if ( __ILA_proc_decode_of_Add__ && __ILA_proc_grant__[1] ) begin
           r1 <= n38;
       end
       if ( __ILA_proc_decode_of_Load__ && __ILA_proc_grant__[0] ) begin
           r2 <= n39;
       end else if ( __ILA_proc_decode_of_Add__ && __ILA_proc_grant__[1] ) begin
           r2 <= n40;
       end
       if ( __ILA_proc_decode_of_Load__ && __ILA_proc_grant__[0] ) begin
           r3 <= n41;
       end else if ( __ILA_proc_decode_of_Add__ && __ILA_proc_grant__[1] ) begin
           r3 <= n42;
       end
       if (mem_wen0) begin
           mem [ mem_addr0 ] <= mem_data0 ;
       end
   end
end
endmodule
