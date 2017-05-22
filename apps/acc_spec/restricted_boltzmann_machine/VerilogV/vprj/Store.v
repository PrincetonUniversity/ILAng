module store(
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
predict_result_data_n2,
data_out,
done,
i,
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
predict_result_addr_n1,
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
input      [7:0] predict_result_data_n2;
input clk;
input rst;
input step;
output     [31:0] data_out;
output            done;
output     [15:0] i;
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
output      [6:0] predict_result_addr_n1;
reg     [31:0] data_out;
reg            done;
reg     [15:0] i;
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
wire      [6:0] n0;
wire      [7:0] n3;
wire     [31:0] n4;
wire            n5;
wire     [15:0] n6;
wire     [15:0] n7;
wire            n8;
wire            n9;
wire            n10;
wire            n11;
wire clk;
wire rst;
wire step;
assign n0 = i[6:0] ;
assign predict_result_addr_n1 = n0 ;
assign n3 = predict_result_data_n2 ;
assign n4 =  {24'd0 , n3}  ;
assign n5 =  ( i ) < ( num_movies )  ;
assign n6 =  ( i ) + ( 16'd1 )  ;
assign n7 =  ( n5 ) ? ( n6 ) : ( i ) ;
assign n8 =  ( n5 ) ? ( wr_complete ) : ( 1'd1 ) ;
assign n9 =  ( n5 ) ? ( wr_granted ) : ( 1'd0 ) ;
assign n10 =  ( i ) == ( 16'd0 )  ;
assign n11 =  ( n10 ) ? ( 1'd0 ) : ( wr_request ) ;
always @(posedge clk) begin
   if(rst) begin
       data_out <= data_out;
       done <= 1'd0;
       i <= 16'd1;
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
       data_out <= n4;
       i <= n7;
       wr_complete <= n8;
       wr_granted <= n9;
       wr_request <= n11;
   end
end
endmodule
