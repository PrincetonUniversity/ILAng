module RBM(
conf_done,
conf_num_hidden,
conf_num_loops,
conf_num_movies,
conf_num_testusers,
conf_num_users,
conf_num_visible,
data_in,
rd_grant,
wr_grant,
predict_result_data_n3,
data_out,
done,
init_done,
num_hidden,
num_loops,
num_movies,
num_testusers,
num_users,
num_visible,
rd_complete,
rd_granted,
rd_index,
rd_length,
rd_request,
wr_complete,
wr_granted,
wr_index,
wr_length,
wr_request,
predict_result_addr_n2,
data_addr0,
data_data0,
data_wen0,
clk,rst,
step
);
input            conf_done;
input     [31:0] conf_num_hidden;
input     [31:0] conf_num_loops;
input     [31:0] conf_num_movies;
input     [31:0] conf_num_testusers;
input     [31:0] conf_num_users;
input     [31:0] conf_num_visible;
input     [31:0] data_in;
input            rd_grant;
input            wr_grant;
input      [7:0] predict_result_data_n3;
input clk;
input rst;
input step;
output     [31:0] data_out;
output            done;
output            init_done;
output     [15:0] num_hidden;
output     [15:0] num_loops;
output     [15:0] num_movies;
output     [15:0] num_testusers;
output     [15:0] num_users;
output     [15:0] num_visible;
output            rd_complete;
output            rd_granted;
output     [31:0] rd_index;
output     [31:0] rd_length;
output            rd_request;
output            wr_complete;
output            wr_granted;
output     [31:0] wr_index;
output     [31:0] wr_length;
output            wr_request;
output      [6:0] predict_result_addr_n2;
output      [8:0] data_addr0;
output      [7:0] data_data0;
output            data_wen0;
reg     [31:0] data_out;
reg            done;
reg            init_done;
reg     [15:0] num_hidden;
reg     [15:0] num_loops;
reg     [15:0] num_movies;
reg     [15:0] num_testusers;
reg     [15:0] num_users;
reg     [15:0] num_visible;
reg            rd_complete;
reg            rd_granted;
reg     [31:0] rd_index;
reg     [31:0] rd_length;
reg            rd_request;
reg            wr_complete;
reg            wr_granted;
reg     [31:0] wr_index;
reg     [31:0] wr_length;
reg            wr_request;
wire            conf_done;
wire     [31:0] conf_num_hidden;
wire     [31:0] conf_num_loops;
wire     [31:0] conf_num_movies;
wire     [31:0] conf_num_testusers;
wire     [31:0] conf_num_users;
wire     [31:0] conf_num_visible;
wire     [31:0] data_in;
wire            rd_grant;
wire            rst;
wire            wr_grant;
wire            n0;
wire            n1;
wire      [7:0] n4;
wire     [31:0] n5;
wire     [31:0] n6;
wire            n7;
wire            n8;
wire            n9;
wire            n10;
wire            n11;
wire            n12;
wire            n13;
wire            n14;
wire     [15:0] n15;
wire     [15:0] n16;
wire     [15:0] n17;
wire     [15:0] n18;
wire     [15:0] n19;
wire     [15:0] n20;
wire     [15:0] n21;
wire     [15:0] n22;
wire     [15:0] n23;
wire     [15:0] n24;
wire     [15:0] n25;
wire     [15:0] n26;
wire     [15:0] n27;
wire     [15:0] n28;
wire     [15:0] n29;
wire     [15:0] n30;
wire     [15:0] n31;
wire     [15:0] n32;
wire            n33;
wire            n34;
wire            n35;
wire            n36;
wire            n37;
wire      [8:0] data_addr0;
wire      [7:0] data_data0;
wire            data_wen0;
wire            n38;
wire            n39;
wire            n40;
wire      [7:0] n41;
wire clk;
wire rst;
wire step;
assign n0 =  ( wr_request ) & ( wr_grant )  ;
assign n1 =  ( n0 ) == ( 1'd1 )  ;
assign predict_result_addr_n2 = 7'd0 ;
assign n4 = predict_result_data_n3 ;
assign n5 =  {24'd0 , n4}  ;
assign n6 =  ( n1 ) ? ( n5 ) : ( data_out ) ;
assign n7 =  ( rst ) == ( 1'd1 )  ;
assign n8 =  ( rst ) == ( 1'd0 )  ;
assign n9 =  ( init_done ) == ( 1'd0 )  ;
assign n10 =  ( n8 ) & ( n9 )  ;
assign n11 =  ( conf_done ) == ( 1'd1 )  ;
assign n12 =  ( n10 ) & ( n11 )  ;
assign n13 =  ( n12 ) ? ( 1'd1 ) : ( init_done ) ;
assign n14 =  ( n7 ) ? ( 1'd0 ) : ( n13 ) ;
assign n15 = conf_num_hidden[15:0] ;
assign n16 =  ( n12 ) ? ( n15 ) : ( num_hidden ) ;
assign n17 =  ( n7 ) ? ( 16'd0 ) : ( n16 ) ;
assign n18 = conf_num_loops[15:0] ;
assign n19 =  ( n12 ) ? ( n18 ) : ( num_loops ) ;
assign n20 =  ( n7 ) ? ( 16'd0 ) : ( n19 ) ;
assign n21 = conf_num_movies[15:0] ;
assign n22 =  ( n12 ) ? ( n21 ) : ( num_movies ) ;
assign n23 =  ( n7 ) ? ( 16'd0 ) : ( n22 ) ;
assign n24 = conf_num_testusers[15:0] ;
assign n25 =  ( n12 ) ? ( n24 ) : ( num_testusers ) ;
assign n26 =  ( n7 ) ? ( 16'd0 ) : ( n25 ) ;
assign n27 = conf_num_users[15:0] ;
assign n28 =  ( n12 ) ? ( n27 ) : ( num_users ) ;
assign n29 =  ( n7 ) ? ( 16'd0 ) : ( n28 ) ;
assign n30 = conf_num_visible[15:0] ;
assign n31 =  ( n12 ) ? ( n30 ) : ( num_visible ) ;
assign n32 =  ( n7 ) ? ( 16'd0 ) : ( n31 ) ;
assign n33 =  ( rd_request ) == ( 1'd1 )  ;
assign n34 =  ( rd_grant ) == ( 1'd1 )  ;
assign n35 =  ( n33 ) & ( n34 )  ;
assign n36 =  ( n35 ) ? ( 1'd1 ) : ( rd_granted ) ;
assign n37 =  ( n1 ) ? ( 1'd1 ) : ( wr_granted ) ;
assign n38 = ~ ( n35 ) ;
assign n39 =  ( 1'b1 ) & ( n38 )  ;
assign n40 =  ( 1'b1 ) & ( n35 )  ;
assign n41 = data_in[7:0] ;
assign data_addr0 = n40 ? (9'd0) : (0);
assign data_data0 = n40 ? (n41) : ('dx);
assign data_wen0 = n40 ? ( 1'b1 ) : (1'b0);
always @(posedge clk) begin
   if(rst) begin
       data_out <= data_out;
       done <= 1'd0;
       init_done <= 1'd0;
       num_hidden <= 16'd0;
       num_loops <= 16'd0;
       num_movies <= 16'd0;
       num_testusers <= 16'd0;
       num_users <= 16'd0;
       num_visible <= 16'd0;
       rd_complete <= 1'd0;
       rd_granted <= rd_granted;
       rd_index <= rd_index;
       rd_length <= rd_length;
       rd_request <= rd_request;
       wr_complete <= 1'd0;
       wr_granted <= wr_granted;
       wr_index <= wr_index;
       wr_length <= wr_length;
       wr_request <= wr_request;
   end
   else if(step) begin
       data_out <= n6;
       done <= done;
       init_done <= n14;
       num_hidden <= n17;
       num_loops <= n20;
       num_movies <= n23;
       num_testusers <= n26;
       num_users <= n29;
       num_visible <= n32;
       rd_complete <= rd_complete;
       rd_granted <= n36;
       rd_index <= rd_index;
       rd_length <= rd_length;
       rd_request <= rd_request;
       wr_complete <= wr_complete;
       wr_granted <= n37;
       wr_index <= wr_index;
       wr_length <= wr_length;
       wr_request <= wr_request;
   end
end
endmodule
