module proc__DOT__Add(
clk,
rst,
__ILA_proc_valid__,
__ILA_proc_decode_of_Add__,
pc,
r0,
r1,
r2,
r3,
__COUNTER_start__n3
);
input            clk;
input            rst;
output            __ILA_proc_valid__;
output            __ILA_proc_decode_of_Add__;
output reg      [7:0] pc;
output reg      [7:0] r0;
output reg      [7:0] r1;
output reg      [7:0] r2;
output reg      [7:0] r3;
output reg      [7:0] __COUNTER_start__n3;
wire            clk;
wire            rst;
wire            __ILA_proc_valid__;
wire      [7:0] n0;
wire      [1:0] n1;
wire            n2;
wire            __ILA_proc_decode_of_Add__;
wire      [7:0] n4;
wire      [1:0] n5;
wire            n6;
wire      [1:0] n7;
wire            n8;
wire            n9;
wire            n10;
wire      [7:0] n11;
wire      [7:0] n12;
wire      [7:0] n13;
wire      [1:0] n14;
wire            n15;
wire            n16;
wire            n17;
wire      [7:0] n18;
wire      [7:0] n19;
wire      [7:0] n20;
wire      [7:0] n21;
wire      [7:0] n22;
wire            n23;
wire      [7:0] n24;
wire            n25;
wire      [7:0] n26;
wire            n27;
wire      [7:0] n28;
reg      [7:0] ir[255:0];
reg      [7:0] mem[255:0];
assign __ILA_proc_valid__ = 1'b1 ;
assign n0 =  (  ir [ pc ] )  ;
assign n1 = n0[7:6] ;
assign n2 =  ( n1 ) == ( 2'd1 )  ;
assign __ILA_proc_decode_of_Add__ = n2 ;
assign n4 =  ( pc ) + ( 8'd1 )  ;
assign n5 = n0[5:4] ;
assign n6 =  ( n5 ) == ( 2'd0 )  ;
assign n7 = n0[3:2] ;
assign n8 =  ( n7 ) == ( 2'd3 )  ;
assign n9 =  ( n7 ) == ( 2'd2 )  ;
assign n10 =  ( n7 ) == ( 2'd1 )  ;
assign n11 =  ( n10 ) ? ( r1 ) : ( r0 ) ;
assign n12 =  ( n9 ) ? ( r2 ) : ( n11 ) ;
assign n13 =  ( n8 ) ? ( r3 ) : ( n12 ) ;
assign n14 = n0[1:0] ;
assign n15 =  ( n14 ) == ( 2'd3 )  ;
assign n16 =  ( n14 ) == ( 2'd2 )  ;
assign n17 =  ( n14 ) == ( 2'd1 )  ;
assign n18 =  ( n17 ) ? ( r1 ) : ( r0 ) ;
assign n19 =  ( n16 ) ? ( r2 ) : ( n18 ) ;
assign n20 =  ( n15 ) ? ( r3 ) : ( n19 ) ;
assign n21 =  ( n13 ) + ( n20 )  ;
assign n22 =  ( n6 ) ? ( n21 ) : ( r0 ) ;
assign n23 =  ( n5 ) == ( 2'd1 )  ;
assign n24 =  ( n23 ) ? ( n21 ) : ( r1 ) ;
assign n25 =  ( n5 ) == ( 2'd2 )  ;
assign n26 =  ( n25 ) ? ( n21 ) : ( r2 ) ;
assign n27 =  ( n5 ) == ( 2'd3 )  ;
assign n28 =  ( n27 ) ? ( n21 ) : ( r3 ) ;
always @(posedge clk) begin
   if(rst) begin
       __COUNTER_start__n3 <= 0;
   end
   else if(__ILA_proc_valid__) begin
       if ( __ILA_proc_decode_of_Add__ ) begin 
           __COUNTER_start__n3 <= 1; end
       else if( (__COUNTER_start__n3 >= 1 ) && ( __COUNTER_start__n3 < 255 )) begin
           __COUNTER_start__n3 <= __COUNTER_start__n3 + 1; end
       if (__ILA_proc_decode_of_Add__) begin
           pc <= n4 ;
       end
       if (__ILA_proc_decode_of_Add__) begin
           r0 <= n22 ;
       end
       if (__ILA_proc_decode_of_Add__) begin
           r1 <= n24 ;
       end
       if (__ILA_proc_decode_of_Add__) begin
           r2 <= n26 ;
       end
       if (__ILA_proc_decode_of_Add__) begin
           r3 <= n28 ;
       end
   end
end
endmodule
