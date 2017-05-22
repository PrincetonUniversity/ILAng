module compute(
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
data_out,
done,
index,
init_done,
loop_count,
num_hidden,
num_loops,
num_movies,
num_testusers,
num_users,
num_visible,
predict_input_done,
rd_complete,
rd_index,
rd_length,
rd_request,
train_input_done,
upc,
wr_complete,
wr_index,
wr_length,
wr_request,
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
input clk;
input rst;
input step;
output     [31:0] data_out;
output            done;
output     [15:0] index;
output            init_done;
output     [15:0] loop_count;
output     [15:0] num_hidden;
output     [15:0] num_loops;
output     [15:0] num_movies;
output     [15:0] num_testusers;
output     [15:0] num_users;
output     [15:0] num_visible;
output            predict_input_done;
output            rd_complete;
output     [31:0] rd_index;
output     [31:0] rd_length;
output            rd_request;
output            train_input_done;
output      [3:0] upc;
output            wr_complete;
output     [31:0] wr_index;
output     [31:0] wr_length;
output            wr_request;
reg     [31:0] data_out;
reg            done;
reg     [15:0] index;
reg            init_done;
reg     [15:0] loop_count;
reg     [15:0] num_hidden;
reg     [15:0] num_loops;
reg     [15:0] num_movies;
reg     [15:0] num_testusers;
reg     [15:0] num_users;
reg     [15:0] num_visible;
reg            predict_input_done;
reg            rd_complete;
reg     [31:0] rd_index;
reg     [31:0] rd_length;
reg            rd_request;
reg            train_input_done;
reg      [3:0] upc;
reg            wr_complete;
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
wire            n2;
wire            n3;
wire            n4;
wire            n5;
wire            n6;
wire            n7;
wire            n8;
wire     [31:0] n9;
wire     [31:0] n10;
wire     [31:0] n11;
wire     [31:0] n12;
wire     [31:0] n13;
wire            n14;
wire            n15;
wire            n16;
wire            n17;
wire            n18;
wire            n19;
wire            n20;
wire            n21;
wire            n22;
wire            n23;
wire            n24;
wire            n25;
wire      [3:0] n26;
wire      [3:0] n27;
wire      [3:0] n28;
wire      [3:0] n29;
wire      [3:0] n30;
wire      [3:0] n31;
wire clk;
wire rst;
wire step;
assign n0 =  ( upc ) == ( 4'd1 )  ;
assign n1 =  ( rd_complete ) == ( 1'd1 )  ;
assign n2 =  ( n0 ) & ( n1 )  ;
assign n3 =  ( loop_count ) == ( num_loops )  ;
assign n4 =  ( n3 ) ? ( 1'd1 ) : ( 1'd0 ) ;
assign n5 =  ( n2 ) ? ( n4 ) : ( predict_input_done ) ;
assign n6 =  ( upc ) == ( 4'd0 )  ;
assign n7 =  ( n2 ) ? ( 1'd0 ) : ( rd_complete ) ;
assign n8 =  ( n6 ) ? ( 1'd0 ) : ( n7 ) ;
assign n9 =  {16'd0 , index}  ;
assign n10 =  ( n6 ) ? ( n9 ) : ( rd_index ) ;
assign n11 =  {16'd0 , num_movies}  ;
assign n12 =  (  ( n11 ) << 2 ) +  n11 ;
assign n13 =  ( n6 ) ? ( n12 ) : ( rd_length ) ;
assign n14 =  ( n6 ) ? ( 1'd1 ) : ( rd_request ) ;
assign n15 =  ( loop_count ) < ( num_loops )  ;
assign n16 =  ( n15 ) ? ( 1'd1 ) : ( 1'd0 ) ;
assign n17 =  ( n2 ) ? ( n16 ) : ( train_input_done ) ;
assign n18 =  ( rd_complete ) == ( 1'd0 )  ;
assign n19 =  ( n0 ) & ( n18 )  ;
assign n20 =  ( upc ) == ( 4'd2 )  ;
assign n21 =  ( train_input_done ) == ( 1'd1 )  ;
assign n22 =  ( n20 ) & ( n21 )  ;
assign n23 =  ( predict_input_done ) == ( 1'd1 )  ;
assign n24 =  ( n20 ) & ( n23 )  ;
assign n25 =  ( upc ) == ( 4'd3 )  ;
assign n26 =  ( n25 ) ? ( 4'd3 ) : ( upc ) ;
assign n27 =  ( n24 ) ? ( 4'd2 ) : ( n26 ) ;
assign n28 =  ( n22 ) ? ( 4'd2 ) : ( n27 ) ;
assign n29 =  ( n2 ) ? ( 4'd2 ) : ( n28 ) ;
assign n30 =  ( n19 ) ? ( upc ) : ( n29 ) ;
assign n31 =  ( n6 ) ? ( 4'd1 ) : ( n30 ) ;
always @(posedge clk) begin
   if(rst) begin
       data_out <= data_out;
       done <= 1'd0;
       index <= 16'd0;
       init_done <= 1'd0;
       loop_count <= 16'd0;
       num_hidden <= 16'd0;
       num_loops <= 16'd0;
       num_movies <= 16'd0;
       num_testusers <= 16'd0;
       num_users <= 16'd0;
       num_visible <= 16'd0;
       predict_input_done <= 1'd0;
       rd_complete <= 1'd0;
       rd_index <= rd_index;
       rd_length <= rd_length;
       rd_request <= rd_request;
       train_input_done <= 1'd0;
       upc <= 4'd0;
       wr_complete <= 1'd0;
       wr_index <= wr_index;
       wr_length <= wr_length;
       wr_request <= wr_request;
   end
   else if(step) begin
       index <= index;
       loop_count <= loop_count;
       predict_input_done <= n5;
       rd_complete <= n8;
       rd_index <= n10;
       rd_length <= n13;
       rd_request <= n14;
       train_input_done <= n17;
       upc <= n31;
   end
end
endmodule
