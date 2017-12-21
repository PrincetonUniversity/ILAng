module alu(
pc,
r0,
r1,
clk,rst,
step
);
input clk;
input rst;
input step;
output      [3:0] pc;
output      [3:0] r0;
output      [3:0] r1;
reg      [3:0] pc;
reg      [3:0] r0;
reg      [3:0] r1;
wire      [3:0] n0;
wire      [3:0] n1;
wire            n2;
wire      [3:0] n3;
wire            n4;
wire      [3:0] n5;
wire            n6;
wire      [3:0] n7;
wire            n8;
wire      [3:0] n9;
wire            n10;
wire      [3:0] n11;
wire            n12;
wire      [3:0] n13;
wire            n14;
wire      [3:0] n15;
wire            n16;
wire      [3:0] n17;
wire      [3:0] n18;
wire      [3:0] n19;
wire      [3:0] n20;
wire      [3:0] n21;
wire      [3:0] n22;
wire      [3:0] n23;
wire      [3:0] n24;
wire      [3:0] n25;
wire            n26;
wire      [3:0] n27;
wire            n28;
wire      [3:0] n29;
wire            n30;
wire      [3:0] n31;
wire            n32;
wire      [3:0] n33;
wire            n34;
wire            n35;
wire      [3:0] n36;
wire            n37;
wire      [3:0] n38;
wire            n39;
wire      [3:0] n40;
wire      [3:0] n41;
wire      [3:0] n42;
wire      [3:0] n43;
wire      [3:0] n44;
wire      [3:0] n45;
wire      [3:0] n46;
wire      [3:0] n47;
reg      [3:0] rom[15:0];
wire clk;
wire rst;
wire step;
assign n0 =  ( pc ) + ( 4'd1 )  ;
assign n1 =  (  rom [ pc ] )  ;
assign n2 =  ( n1 ) == ( 4'd14 )  ;
assign n3 =  ( r0 ) | ( r1 )  ;
assign n4 =  ( n1 ) == ( 4'd12 )  ;
assign n5 = ( ~ ( r0 ) + 1'b1 ) ;
assign n6 =  ( n1 ) == ( 4'd10 )  ;
assign n7 =  ( r0 ) & ( r1 )  ;
assign n8 =  ( n1 ) == ( 4'd8 )  ;
assign n9 = ~ ( r0 ) ;
assign n10 =  ( n1 ) == ( 4'd6 )  ;
assign n11 =  ( r0 ) - ( r1 )  ;
assign n12 =  ( n1 ) == ( 4'd4 )  ;
assign n13 =  ( r0 ) - ( r0 )  ;
assign n14 =  ( n1 ) == ( 4'd2 )  ;
assign n15 =  ( r0 ) + ( r1 )  ;
assign n16 =  ( n1 ) == ( 4'd0 )  ;
assign n17 =  ( r0 ) + ( r0 )  ;
assign n18 =  ( n16 ) ? ( n17 ) : ( r0 ) ;
assign n19 =  ( n14 ) ? ( n15 ) : ( n18 ) ;
assign n20 =  ( n12 ) ? ( n13 ) : ( n19 ) ;
assign n21 =  ( n10 ) ? ( n11 ) : ( n20 ) ;
assign n22 =  ( n8 ) ? ( n9 ) : ( n21 ) ;
assign n23 =  ( n6 ) ? ( n7 ) : ( n22 ) ;
assign n24 =  ( n4 ) ? ( n5 ) : ( n23 ) ;
assign n25 =  ( n2 ) ? ( n3 ) : ( n24 ) ;
assign n26 =  ( n1 ) == ( 4'd15 )  ;
assign n27 = ( ~ ( r1 ) + 1'b1 ) ;
assign n28 =  ( n1 ) == ( 4'd13 )  ;
assign n29 =  ( r1 ) | ( r0 )  ;
assign n30 =  ( n1 ) == ( 4'd11 )  ;
assign n31 = ~ ( r1 ) ;
assign n32 =  ( n1 ) == ( 4'd9 )  ;
assign n33 =  ( r1 ) & ( r0 )  ;
assign n34 =  ( n1 ) == ( 4'd7 )  ;
assign n35 =  ( n1 ) == ( 4'd5 )  ;
assign n36 =  ( r1 ) - ( r0 )  ;
assign n37 =  ( n1 ) == ( 4'd3 )  ;
assign n38 =  ( r1 ) + ( r1 )  ;
assign n39 =  ( n1 ) == ( 4'd1 )  ;
assign n40 =  ( n39 ) ? ( n15 ) : ( r1 ) ;
assign n41 =  ( n37 ) ? ( n38 ) : ( n40 ) ;
assign n42 =  ( n35 ) ? ( n36 ) : ( n41 ) ;
assign n43 =  ( n34 ) ? ( n13 ) : ( n42 ) ;
assign n44 =  ( n32 ) ? ( n33 ) : ( n43 ) ;
assign n45 =  ( n30 ) ? ( n31 ) : ( n44 ) ;
assign n46 =  ( n28 ) ? ( n29 ) : ( n45 ) ;
assign n47 =  ( n26 ) ? ( n27 ) : ( n46 ) ;
always @(posedge clk) begin
   if(rst) begin
       pc <= pc;
       r0 <= r0;
       r1 <= r1;
   end
   else if(step) begin
       pc <= n0;
       r0 <= n25;
       r1 <= n47;
   end
end
endmodule
