module DMAload(
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
wr_index,
wr_length,
wr_request,
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
output     [31:0] wr_index;
output     [31:0] wr_length;
output            wr_request;
output      [8:0] data_addr0;
output      [7:0] data_data0;
output            data_wen0;
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
wire     [15:0] n0;
wire            n1;
wire     [15:0] n2;
wire     [15:0] n3;
wire            n4;
wire            n5;
wire      [8:0] data_addr0;
wire      [7:0] data_data0;
wire            data_wen0;
wire            n6;
wire            n7;
wire            n8;
wire            n9;
wire            n10;
wire            n11;
wire      [8:0] n12;
wire            n13;
wire      [8:0] n14;
wire      [7:0] n15;
wire clk;
wire rst;
wire step;
assign n0 = rd_length[15:0] ;
assign n1 =  ( i ) < ( n0 )  ;
assign n2 =  ( i ) + ( 16'd1 )  ;
assign n3 =  ( n1 ) ? ( n2 ) : ( i ) ;
assign n4 =  ( n1 ) ? ( 1'd0 ) : ( 1'd1 ) ;
assign n5 =  ( n1 ) ? ( rd_granted ) : ( 1'd0 ) ;
assign n6 = ~ ( n1 ) ;
assign n7 =  ( 1'b1 ) & ( n6 )  ;
assign n8 =  ( i ) == ( n0 )  ;
assign n9 = ~ ( n8 ) ;
assign n10 =  ( n7 ) & ( n9 )  ;
assign n11 =  ( n7 ) & ( n8 )  ;
assign n12 = rd_length[8:0] ;
assign n13 =  ( 1'b1 ) & ( n1 )  ;
assign n14 = i[8:0] ;
assign n15 = data_in[7:0] ;
assign data_addr0 = n13 ? (n14) : (n11 ? (n12) : (0));
assign data_data0 = n13 ? (n15) : (n11 ? (8'd1) : ('dx));
assign data_wen0 = n13 ? ( 1'b1 ) : (n11 ? ( 1'b1 ) : (1'b0));
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
       wr_index <= wr_index;
       wr_length <= wr_length;
       wr_request <= wr_request;
   end
   else if(step) begin
       i <= n3;
       rd_complete <= n4;
       rd_granted <= n5;
       rd_request <= 1'd0;
   end
end
endmodule
