/* PREHEADER */
module fun_divide (
    input [31:0] arg1,
    input [63:0] arg2,
    output [63:0] result
);
//TODO: Add the specific function HERE.
endmodule
module fun_rand (
    output [63:0] result
);
//TODO: Add the specific function HERE.
endmodule
module fun_round (
    input [31:0] arg1,
    output [7:0] result
);
//TODO: Add the specific function HERE.
endmodule
module fun_sigmoid (
    input [15:0] arg1,
    output [63:0] result
);
//TODO: Add the specific function HERE.
endmodule
module fun_to_int_exp (
    input [15:0] arg1,
    output [31:0] result
);
//TODO: Add the specific function HERE.
endmodule

/* END OF PREHEADER */
module predict(
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
pow2_data_n38,
hidden_unit_data_n120,
edges_data_n126,
data_data_n153,
predict_vector_data_n190,
visibleEnergies_data_n199,
count,
data_out,
done,
expectation,
index,
init_done,
jstate,
loop_count,
num_hidden,
num_loops,
num_movies,
num_testusers,
num_users,
num_visible,
per_v_pc,
predict_h_cnt,
predict_input_done,
predict_max,
predict_sum,
predict_upc,
predict_v_cnt,
prediction,
rd_complete,
rd_index,
rd_length,
rd_request,
sumOfpow2,
train_input_done,
upc,
wr_complete,
wr_index,
wr_length,
wr_request,
pow2_addr_n37,
hidden_unit_addr_n119,
edges_addr_n125,
data_addr_n152,
predict_vector_addr_n189,
visibleEnergies_addr_n198,
hidden_unit_addr0,
hidden_unit_data0,
hidden_unit_wen0,
hidden_unit_addr1,
hidden_unit_data1,
hidden_unit_wen1,
pow2_addr0,
pow2_data0,
pow2_wen0,
predict_result_addr0,
predict_result_data0,
predict_result_wen0,
predict_vector_addr0,
predict_vector_data0,
predict_vector_wen0,
predict_vector_addr1,
predict_vector_data1,
predict_vector_wen1,
visibleEnergies_addr0,
visibleEnergies_data0,
visibleEnergies_wen0,
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
input     [31:0] pow2_data_n38;
input            hidden_unit_data_n120;
input      [7:0] edges_data_n126;
input      [7:0] data_data_n153;
input            predict_vector_data_n190;
input     [15:0] visibleEnergies_data_n199;
input clk;
input rst;
input step;
output      [7:0] count;
output     [31:0] data_out;
output            done;
output     [31:0] expectation;
output     [15:0] index;
output            init_done;
output     [15:0] jstate;
output     [15:0] loop_count;
output     [15:0] num_hidden;
output     [15:0] num_loops;
output     [15:0] num_movies;
output     [15:0] num_testusers;
output     [15:0] num_users;
output     [15:0] num_visible;
output      [3:0] per_v_pc;
output     [15:0] predict_h_cnt;
output            predict_input_done;
output     [15:0] predict_max;
output     [15:0] predict_sum;
output      [3:0] predict_upc;
output     [15:0] predict_v_cnt;
output      [7:0] prediction;
output            rd_complete;
output     [31:0] rd_index;
output     [31:0] rd_length;
output            rd_request;
output     [63:0] sumOfpow2;
output            train_input_done;
output      [3:0] upc;
output            wr_complete;
output     [31:0] wr_index;
output     [31:0] wr_length;
output            wr_request;
output      [2:0] pow2_addr_n37;
output      [6:0] hidden_unit_addr_n119;
output     [15:0] edges_addr_n125;
output      [8:0] data_addr_n152;
output      [8:0] predict_vector_addr_n189;
output      [2:0] visibleEnergies_addr_n198;
output      [6:0] hidden_unit_addr0;
output            hidden_unit_data0;
output            hidden_unit_wen0;
output      [6:0] hidden_unit_addr1;
output            hidden_unit_data1;
output            hidden_unit_wen1;
output      [2:0] pow2_addr0;
output     [31:0] pow2_data0;
output            pow2_wen0;
output      [6:0] predict_result_addr0;
output      [7:0] predict_result_data0;
output            predict_result_wen0;
output      [8:0] predict_vector_addr0;
output            predict_vector_data0;
output            predict_vector_wen0;
output      [8:0] predict_vector_addr1;
output            predict_vector_data1;
output            predict_vector_wen1;
output      [2:0] visibleEnergies_addr0;
output     [15:0] visibleEnergies_data0;
output            visibleEnergies_wen0;
reg      [7:0] count;
reg     [31:0] data_out;
reg            done;
reg     [31:0] expectation;
reg     [15:0] index;
reg            init_done;
reg     [15:0] jstate;
reg     [15:0] loop_count;
reg     [15:0] num_hidden;
reg     [15:0] num_loops;
reg     [15:0] num_movies;
reg     [15:0] num_testusers;
reg     [15:0] num_users;
reg     [15:0] num_visible;
reg      [3:0] per_v_pc;
reg     [15:0] predict_h_cnt;
reg            predict_input_done;
reg     [15:0] predict_max;
reg     [15:0] predict_sum;
reg      [3:0] predict_upc;
reg     [15:0] predict_v_cnt;
reg      [7:0] prediction;
reg            rd_complete;
reg     [31:0] rd_index;
reg     [31:0] rd_length;
reg            rd_request;
reg     [63:0] sumOfpow2;
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
wire     [15:0] n4;
wire            n5;
wire            n6;
wire            n7;
wire            n8;
wire            n9;
wire            n10;
wire      [7:0] n11;
wire            n12;
wire      [7:0] n13;
wire      [7:0] n14;
wire            n15;
wire      [7:0] n16;
wire      [7:0] n17;
wire      [7:0] n18;
wire      [7:0] n19;
wire            n20;
wire            n21;
wire            n22;
wire     [15:0] n23;
wire            n24;
wire            n25;
wire            n26;
wire            n27;
wire            n28;
wire            n29;
wire            n30;
wire            n31;
wire            n32;
wire            n33;
wire            n34;
wire     [31:0] n35;
wire      [2:0] n36;
wire     [31:0] n39;
wire     [63:0] n40;
wire     [63:0] n42;
wire     [79:0] n43;
wire     [79:0] n44;
wire     [79:0] n45;
wire     [16:0] n46;
wire      [2:0] n47;
wire     [62:0] n48;
wire     [28:0] n49;
wire     [31:0] n50;
wire     [31:0] n51;
wire     [31:0] n52;
wire     [31:0] n53;
wire     [31:0] n54;
wire     [31:0] n55;
wire            n56;
wire     [15:0] n57;
wire     [15:0] n58;
wire     [15:0] n59;
wire     [15:0] n60;
wire     [15:0] n61;
wire     [15:0] n62;
wire            n63;
wire            n64;
wire            n65;
wire     [15:0] n66;
wire     [15:0] n67;
wire     [15:0] n68;
wire            n69;
wire            n70;
wire            n71;
wire            n72;
wire     [15:0] n73;
wire     [15:0] n74;
wire     [15:0] n75;
wire     [15:0] n76;
wire     [15:0] n77;
wire     [15:0] n78;
wire     [15:0] n79;
wire     [15:0] n80;
wire     [15:0] n81;
wire            n82;
wire      [3:0] n83;
wire      [3:0] n84;
wire      [3:0] n85;
wire      [3:0] n86;
wire      [3:0] n87;
wire      [3:0] n88;
wire      [3:0] n89;
wire      [3:0] n90;
wire      [3:0] n91;
wire      [3:0] n92;
wire      [3:0] n93;
wire      [3:0] n94;
wire      [3:0] n95;
wire      [3:0] n96;
wire            n97;
wire     [15:0] n98;
wire            n99;
wire     [15:0] n100;
wire     [15:0] n101;
wire     [15:0] n102;
wire     [15:0] n103;
wire     [15:0] n104;
wire     [15:0] n105;
wire     [15:0] n106;
wire     [15:0] n107;
wire     [15:0] n108;
wire     [15:0] n109;
wire     [15:0] n110;
wire     [15:0] n111;
wire            n112;
wire            n113;
wire            n114;
wire            n115;
wire            n116;
wire     [15:0] n117;
wire      [6:0] n118;
wire            n121;
wire            n122;
wire     [15:0] n123;
wire     [15:0] n124;
wire      [7:0] n127;
wire      [6:0] n128;
wire     [14:0] n129;
wire            n130;
wire     [15:0] n131;
wire     [15:0] n132;
wire     [15:0] n133;
wire     [15:0] n134;
wire     [15:0] n135;
wire            n136;
wire     [15:0] n137;
wire     [15:0] n138;
wire     [15:0] n139;
wire     [15:0] n140;
wire     [15:0] n141;
wire     [15:0] n142;
wire     [15:0] n143;
wire     [15:0] n144;
wire     [15:0] n145;
wire     [15:0] n146;
wire     [15:0] n147;
wire     [15:0] n148;
wire            n149;
wire     [15:0] n150;
wire      [8:0] n151;
wire      [7:0] n154;
wire            n155;
wire     [15:0] n156;
wire     [15:0] n157;
wire     [15:0] n158;
wire     [15:0] n159;
wire     [15:0] n160;
wire     [15:0] n161;
wire     [15:0] n162;
wire     [15:0] n163;
wire     [15:0] n164;
wire     [15:0] n165;
wire            n166;
wire      [3:0] n167;
wire            n168;
wire            n169;
wire      [3:0] n170;
wire            n171;
wire      [3:0] n172;
wire      [3:0] n173;
wire      [3:0] n174;
wire      [3:0] n175;
wire      [3:0] n176;
wire      [3:0] n177;
wire     [15:0] n178;
wire     [15:0] n179;
wire     [15:0] n180;
wire     [15:0] n181;
wire     [15:0] n182;
wire     [15:0] n183;
wire     [15:0] n184;
wire     [15:0] n185;
wire     [15:0] n186;
wire     [15:0] n187;
wire      [8:0] n188;
wire            n191;
wire            n192;
wire      [7:0] n193;
wire      [7:0] n194;
wire      [7:0] n195;
wire      [7:0] n196;
wire     [63:0] n197;
wire     [15:0] n200;
wire     [31:0] n201;
wire     [31:0] n203;
wire     [31:0] n204;
wire     [63:0] n205;
wire     [63:0] n206;
wire     [63:0] n207;
wire     [63:0] n208;
wire     [63:0] n209;
wire     [63:0] n210;
wire     [63:0] n211;
wire     [63:0] n212;
wire     [63:0] n213;
wire     [63:0] n214;
wire      [3:0] n215;
wire      [3:0] n216;
wire      [3:0] n217;
wire      [3:0] n218;
wire      [3:0] n219;
wire            n220;
wire            n221;
wire            n222;
wire            n223;
wire            n224;
wire            n225;
wire     [31:0] n226;
wire     [31:0] n227;
wire     [31:0] n228;
wire     [31:0] n229;
wire     [31:0] n230;
wire     [31:0] n231;
wire     [31:0] n232;
wire     [31:0] n233;
wire     [31:0] n234;
wire     [31:0] n235;
wire     [31:0] n236;
wire     [31:0] n237;
wire     [31:0] n238;
wire     [31:0] n239;
wire            n240;
wire            n241;
wire            n242;
wire            n243;
wire            n244;
wire      [6:0] hidden_unit_addr0;
wire            hidden_unit_data0;
wire            hidden_unit_wen0;
wire      [6:0] hidden_unit_addr1;
wire            hidden_unit_data1;
wire            hidden_unit_wen1;
wire            n245;
wire            n246;
wire            n247;
wire            n248;
wire            n249;
wire            n250;
wire            n251;
wire            n252;
wire            n253;
wire            n254;
wire            n255;
wire            n256;
wire            n257;
wire            n258;
wire     [63:0] n259;
wire     [63:0] n260;
wire     [63:0] n261;
wire     [63:0] n262;
wire     [63:0] n263;
wire     [63:0] n265;
wire            n266;
wire            n267;
wire            n268;
wire            n269;
wire      [6:0] n270;
wire            n271;
wire      [2:0] pow2_addr0;
wire     [31:0] pow2_data0;
wire            pow2_wen0;
wire            n272;
wire            n273;
wire            n274;
wire            n275;
wire            n276;
wire            n277;
wire            n278;
wire            n279;
wire            n280;
wire            n281;
wire            n282;
wire            n283;
wire            n284;
wire            n285;
wire            n286;
wire      [6:0] predict_result_addr0;
wire      [7:0] predict_result_data0;
wire            predict_result_wen0;
wire            n287;
wire            n288;
wire            n289;
wire            n290;
wire            n291;
wire            n292;
wire      [6:0] n293;
wire      [8:0] predict_vector_addr0;
wire            predict_vector_data0;
wire            predict_vector_wen0;
wire      [8:0] predict_vector_addr1;
wire            predict_vector_data1;
wire            predict_vector_wen1;
wire            n294;
wire            n295;
wire            n296;
wire            n297;
wire      [7:0] n298;
wire      [7:0] n300;
wire     [15:0] n301;
wire            n302;
wire            n303;
wire            n304;
wire      [8:0] n305;
wire      [2:0] visibleEnergies_addr0;
wire     [15:0] visibleEnergies_data0;
wire            visibleEnergies_wen0;
wire     [15:0] n306;
wire            n307;
wire            n308;
wire            n309;
wire clk;
wire rst;
wire step;
assign n0 =  ( predict_upc ) == ( 4'd0 )  ;
assign n1 =  ( predict_upc ) == ( 4'd1 )  ;
assign n2 =  ( per_v_pc ) == ( 4'd4 )  ;
assign n3 =  ( n1 ) & ( n2 )  ;
assign n4 =  ( predict_v_cnt ) + ( 16'd5 )  ;
assign n5 =  ( n4 ) == ( num_visible )  ;
assign n6 =  ( n4 ) >= ( 16'd500 )  ;
assign n7 =  ( n5 ) | ( n6 )  ;
assign n8 =  ( n3 ) & ( n7 )  ;
assign n9 =  ( jstate ) == ( 16'd4 )  ;
assign n10 =  ( n8 ) & ( n9 )  ;
assign n11 =  ( n10 ) ? ( 8'd0 ) : ( count ) ;
assign n12 =  ( predict_upc ) == ( 4'd3 )  ;
assign n13 =  ( count ) + ( 8'd1 )  ;
assign n14 =  ( n9 ) ? ( n13 ) : ( count ) ;
assign n15 =  ( predict_upc ) == ( 4'd2 )  ;
assign n16 =  ( n15 ) ? ( count ) : ( count ) ;
assign n17 =  ( n12 ) ? ( n14 ) : ( n16 ) ;
assign n18 =  ( n1 ) ? ( n11 ) : ( n17 ) ;
assign n19 =  ( n0 ) ? ( 8'd0 ) : ( n18 ) ;
assign n20 =  ( wr_request ) == ( 1'd0 )  ;
assign n21 =  ( wr_complete ) == ( 1'd1 )  ;
assign n22 =  ( n20 ) & ( n21 )  ;
assign n23 =  ( num_testusers ) - ( 16'd1 )  ;
assign n24 =  ( index ) == ( n23 )  ;
assign n25 =  ( n22 ) & ( n24 )  ;
assign n26 =  ( loop_count ) == ( num_loops )  ;
assign n27 =  ( n25 ) & ( n26 )  ;
assign n28 =  ( n27 ) ? ( 1'd1 ) : ( 1'd0 ) ;
assign n29 =  ( n15 ) ? ( n28 ) : ( done ) ;
assign n30 =  ( n1 ) ? ( done ) : ( n29 ) ;
assign n31 =  ( n0 ) ? ( done ) : ( n30 ) ;
assign n32 =  ( per_v_pc ) == ( 4'd3 )  ;
assign n33 =  ( n1 ) & ( n32 )  ;
assign n34 =  ( jstate ) == ( 16'd0 )  ;
assign n35 =  ( n34 ) ? ( 32'd0 ) : ( expectation ) ;
assign n36 = jstate[2:0] ;
assign pow2_addr_n37 = n36 ;
assign n39 = pow2_data_n38 ;
fun_divide  applyFunc_n41(
    .arg1( n39 ),
    .arg2( sumOfpow2 ),
    .result( n40 )
);
assign n42 = n40 ;
assign n43 =  {16'd0 , n42}  ;
assign n44 =  {64'd0 , jstate}  ;
assign n45 =  ( ( n43 ) * ( n44 ))  ;
assign n46 = n45[79:63] ;
assign n47 = n46[2:0] ;
assign n48 = n45[62:0] ;
assign n49 = n48[62:34] ;
assign n50 =  { ( n47 ) , ( n49 ) }  ;
assign n51 =  ( n35 ) + ( n50 )  ;
assign n52 =  ( n33 ) ? ( n51 ) : ( expectation ) ;
assign n53 =  ( n15 ) ? ( expectation ) : ( expectation ) ;
assign n54 =  ( n1 ) ? ( n52 ) : ( n53 ) ;
assign n55 =  ( n0 ) ? ( expectation ) : ( n54 ) ;
assign n56 =  ( n24 ) & ( n26 )  ;
assign n57 =  ( index ) + ( 16'd1 )  ;
assign n58 =  ( n56 ) ? ( index ) : ( n57 ) ;
assign n59 =  ( n22 ) ? ( n58 ) : ( index ) ;
assign n60 =  ( n15 ) ? ( n59 ) : ( index ) ;
assign n61 =  ( n1 ) ? ( index ) : ( n60 ) ;
assign n62 =  ( n0 ) ? ( index ) : ( n61 ) ;
assign n63 =  ( per_v_pc ) == ( 4'd0 )  ;
assign n64 =  ( n1 ) & ( n63 )  ;
assign n65 =  ( predict_h_cnt ) == ( num_hidden )  ;
assign n66 =  ( jstate ) + ( 16'd1 )  ;
assign n67 =  ( n9 ) ? ( 16'd0 ) : ( n66 ) ;
assign n68 =  ( n65 ) ? ( n67 ) : ( jstate ) ;
assign n69 =  ( per_v_pc ) == ( 4'd1 )  ;
assign n70 =  ( n1 ) & ( n69 )  ;
assign n71 =  ( per_v_pc ) == ( 4'd2 )  ;
assign n72 =  ( n1 ) & ( n71 )  ;
assign n73 =  ( n3 ) ? ( n67 ) : ( jstate ) ;
assign n74 =  ( n33 ) ? ( n67 ) : ( n73 ) ;
assign n75 =  ( n72 ) ? ( n67 ) : ( n74 ) ;
assign n76 =  ( n70 ) ? ( n67 ) : ( n75 ) ;
assign n77 =  ( n64 ) ? ( n68 ) : ( n76 ) ;
assign n78 =  ( n15 ) ? ( jstate ) : ( jstate ) ;
assign n79 =  ( n12 ) ? ( n67 ) : ( n78 ) ;
assign n80 =  ( n1 ) ? ( n77 ) : ( n79 ) ;
assign n81 =  ( n0 ) ? ( 16'd0 ) : ( n80 ) ;
assign n82 =  ( n9 ) & ( n65 )  ;
assign n83 =  ( n82 ) ? ( 4'd1 ) : ( per_v_pc ) ;
assign n84 =  ( n9 ) ? ( 4'd2 ) : ( per_v_pc ) ;
assign n85 =  ( n9 ) ? ( 4'd3 ) : ( per_v_pc ) ;
assign n86 =  ( n9 ) ? ( 4'd4 ) : ( per_v_pc ) ;
assign n87 =  ( n7 ) ? ( 4'd0 ) : ( 4'd0 ) ;
assign n88 =  ( n9 ) ? ( n87 ) : ( per_v_pc ) ;
assign n89 =  ( n3 ) ? ( n88 ) : ( per_v_pc ) ;
assign n90 =  ( n33 ) ? ( n86 ) : ( n89 ) ;
assign n91 =  ( n72 ) ? ( n85 ) : ( n90 ) ;
assign n92 =  ( n70 ) ? ( n84 ) : ( n91 ) ;
assign n93 =  ( n64 ) ? ( n83 ) : ( n92 ) ;
assign n94 =  ( n15 ) ? ( per_v_pc ) : ( per_v_pc ) ;
assign n95 =  ( n1 ) ? ( n93 ) : ( n94 ) ;
assign n96 =  ( n0 ) ? ( 4'd0 ) : ( n95 ) ;
assign n97 =  ( predict_v_cnt ) == ( num_visible )  ;
assign n98 =  ( num_hidden ) - ( 16'd1 )  ;
assign n99 =  ( predict_h_cnt ) == ( n98 )  ;
assign n100 =  ( predict_h_cnt ) + ( 16'd1 )  ;
assign n101 =  ( n99 ) ? ( 16'd0 ) : ( n100 ) ;
assign n102 =  ( n97 ) ? ( n101 ) : ( predict_h_cnt ) ;
assign n103 =  ( n65 ) ? ( 16'd0 ) : ( n100 ) ;
assign n104 =  ( n3 ) ? ( predict_h_cnt ) : ( predict_h_cnt ) ;
assign n105 =  ( n33 ) ? ( predict_h_cnt ) : ( n104 ) ;
assign n106 =  ( n72 ) ? ( predict_h_cnt ) : ( n105 ) ;
assign n107 =  ( n70 ) ? ( predict_h_cnt ) : ( n106 ) ;
assign n108 =  ( n64 ) ? ( n103 ) : ( n107 ) ;
assign n109 =  ( n15 ) ? ( predict_h_cnt ) : ( predict_h_cnt ) ;
assign n110 =  ( n1 ) ? ( n108 ) : ( n109 ) ;
assign n111 =  ( n0 ) ? ( n102 ) : ( n110 ) ;
assign n112 =  ( n22 ) ? ( 1'd0 ) : ( predict_input_done ) ;
assign n113 =  ( n15 ) ? ( n112 ) : ( predict_input_done ) ;
assign n114 =  ( n1 ) ? ( predict_input_done ) : ( n113 ) ;
assign n115 =  ( n0 ) ? ( predict_input_done ) : ( n114 ) ;
assign n116 =  ( predict_h_cnt ) == ( 16'd0 )  ;
assign n117 =  ( n116 ) ? ( 16'd0 ) : ( predict_sum ) ;
assign n118 = predict_h_cnt[6:0] ;
assign hidden_unit_addr_n119 = n118 ;
assign n121 = hidden_unit_data_n120 ;
assign n122 =  ( n121 ) == ( 1'd1 )  ;
assign n123 =  ( ( 16'd101 ) * ( predict_v_cnt ))  ;
assign n124 =  ( n123 ) + ( predict_h_cnt )  ;
assign edges_addr_n125 = n124 ;
assign n127 = edges_data_n126 ;
assign n128 = n127[7:1] ;
assign n129 =  { {8{n128[6] }  }, n128}  ;
assign n130 = n127[0:0] ;
assign n131 =  { ( n129 ) , ( n130 ) }  ;
assign n132 =  ( n122 ) ? ( n131 ) : ( 16'd0 ) ;
assign n133 =  ( n117 ) + ( n132 )  ;
assign n134 = ( ~ ( 16'd1000 ) + 1'b1 ) ;
assign n135 =  ( n34 ) ? ( n134 ) : ( predict_max ) ;
assign n136 =  $signed( n133 ) > $signed( n135 )  ;
assign n137 =  ( n136 ) ? ( n133 ) : ( n135 ) ;
assign n138 =  ( n65 ) ? ( n137 ) : ( predict_max ) ;
assign n139 =  ( predict_max ) - ( 16'd62 )  ;
assign n140 =  ( n34 ) ? ( n139 ) : ( predict_max ) ;
assign n141 =  ( n3 ) ? ( predict_max ) : ( predict_max ) ;
assign n142 =  ( n33 ) ? ( predict_max ) : ( n141 ) ;
assign n143 =  ( n72 ) ? ( predict_max ) : ( n142 ) ;
assign n144 =  ( n70 ) ? ( n140 ) : ( n143 ) ;
assign n145 =  ( n64 ) ? ( n138 ) : ( n144 ) ;
assign n146 =  ( n15 ) ? ( predict_max ) : ( predict_max ) ;
assign n147 =  ( n1 ) ? ( n145 ) : ( n146 ) ;
assign n148 =  ( n0 ) ? ( predict_max ) : ( n147 ) ;
assign n149 =  ( predict_v_cnt ) == ( 16'd0 )  ;
assign n150 =  ( n149 ) ? ( 16'd0 ) : ( predict_sum ) ;
assign n151 = predict_v_cnt[8:0] ;
assign data_addr_n152 = n151 ;
assign n154 = data_data_n153 ;
assign n155 =  ( n154 ) == ( 8'd1 )  ;
assign n156 =  ( n155 ) ? ( n131 ) : ( 16'd0 ) ;
assign n157 =  ( n150 ) + ( n156 )  ;
assign n158 =  ( n3 ) ? ( predict_sum ) : ( predict_sum ) ;
assign n159 =  ( n33 ) ? ( predict_sum ) : ( n158 ) ;
assign n160 =  ( n72 ) ? ( predict_sum ) : ( n159 ) ;
assign n161 =  ( n70 ) ? ( predict_sum ) : ( n160 ) ;
assign n162 =  ( n64 ) ? ( n133 ) : ( n161 ) ;
assign n163 =  ( n15 ) ? ( predict_sum ) : ( predict_sum ) ;
assign n164 =  ( n1 ) ? ( n162 ) : ( n163 ) ;
assign n165 =  ( n0 ) ? ( n157 ) : ( n164 ) ;
assign n166 =  ( n97 ) & ( n99 )  ;
assign n167 =  ( n166 ) ? ( 4'd1 ) : ( 4'd0 ) ;
assign n168 =  ( n3 ) & ( n9 )  ;
assign n169 =  ( n168 ) & ( n7 )  ;
assign n170 =  ( n169 ) ? ( 4'd3 ) : ( 4'd1 ) ;
assign n171 =  ( n7 ) & ( n9 )  ;
assign n172 =  ( n171 ) ? ( 4'd2 ) : ( 4'd3 ) ;
assign n173 =  ( n22 ) ? ( 4'd2 ) : ( 4'd2 ) ;
assign n174 =  ( n15 ) ? ( n173 ) : ( predict_upc ) ;
assign n175 =  ( n12 ) ? ( n172 ) : ( n174 ) ;
assign n176 =  ( n1 ) ? ( n170 ) : ( n175 ) ;
assign n177 =  ( n0 ) ? ( n167 ) : ( n176 ) ;
assign n178 =  ( predict_v_cnt ) + ( 16'd1 )  ;
assign n179 =  ( n97 ) ? ( 16'd0 ) : ( n178 ) ;
assign n180 =  ( n7 ) ? ( 16'd0 ) : ( n4 ) ;
assign n181 =  ( n168 ) ? ( n180 ) : ( predict_v_cnt ) ;
assign n182 =  ( n7 ) ? ( n4 ) : ( n4 ) ;
assign n183 =  ( n15 ) ? ( predict_v_cnt ) : ( predict_v_cnt ) ;
assign n184 =  ( n12 ) ? ( n182 ) : ( n183 ) ;
assign n185 =  ( n1 ) ? ( n181 ) : ( n184 ) ;
assign n186 =  ( n0 ) ? ( n179 ) : ( n185 ) ;
assign n187 =  ( predict_v_cnt ) + ( jstate )  ;
assign n188 = n187[8:0] ;
assign predict_vector_addr_n189 = n188 ;
assign n191 = predict_vector_data_n190 ;
assign n192 =  ( n191 ) == ( 1'd1 )  ;
assign n193 = n66[7:0] ;
assign n194 =  ( n34 ) ? ( 8'd0 ) : ( prediction ) ;
assign n195 =  ( n192 ) ? ( n193 ) : ( n194 ) ;
assign n196 =  ( n12 ) ? ( n195 ) : ( prediction ) ;
assign n197 =  ( n34 ) ? ( 64'd0 ) : ( sumOfpow2 ) ;
assign visibleEnergies_addr_n198 = n36 ;
assign n200 = visibleEnergies_data_n199 ;
fun_to_int_exp  applyFunc_n202(
    .arg1( n200 ),
    .result( n201 )
);
assign n203 = n201 ;
assign n204 = n203[31:0] ;
assign n205 =  {32'd0 , n204}  ;
assign n206 =  ( n197 ) + ( n205 )  ;
assign n207 =  ( n3 ) ? ( sumOfpow2 ) : ( sumOfpow2 ) ;
assign n208 =  ( n33 ) ? ( sumOfpow2 ) : ( n207 ) ;
assign n209 =  ( n72 ) ? ( n206 ) : ( n208 ) ;
assign n210 =  ( n70 ) ? ( sumOfpow2 ) : ( n209 ) ;
assign n211 =  ( n64 ) ? ( sumOfpow2 ) : ( n210 ) ;
assign n212 =  ( n15 ) ? ( sumOfpow2 ) : ( sumOfpow2 ) ;
assign n213 =  ( n1 ) ? ( n211 ) : ( n212 ) ;
assign n214 =  ( n0 ) ? ( sumOfpow2 ) : ( n213 ) ;
assign n215 =  ( n56 ) ? ( 4'd3 ) : ( 4'd0 ) ;
assign n216 =  ( n22 ) ? ( n215 ) : ( upc ) ;
assign n217 =  ( n15 ) ? ( n216 ) : ( upc ) ;
assign n218 =  ( n1 ) ? ( upc ) : ( n217 ) ;
assign n219 =  ( n0 ) ? ( upc ) : ( n218 ) ;
assign n220 =  ( n171 ) ? ( 1'd0 ) : ( wr_complete ) ;
assign n221 =  ( n22 ) ? ( 1'd0 ) : ( wr_complete ) ;
assign n222 =  ( n15 ) ? ( n221 ) : ( wr_complete ) ;
assign n223 =  ( n12 ) ? ( n220 ) : ( n222 ) ;
assign n224 =  ( n1 ) ? ( wr_complete ) : ( n223 ) ;
assign n225 =  ( n0 ) ? ( wr_complete ) : ( n224 ) ;
assign n226 =  {16'd0 , num_movies}  ;
assign n227 = n226 ;
assign n228 =  {16'd0 , index}  ;
assign n229 =  ( ( n227 ) * ( n228 ))  ;
assign n230 =  ( n171 ) ? ( n229 ) : ( wr_index ) ;
assign n231 =  ( n15 ) ? ( wr_index ) : ( wr_index ) ;
assign n232 =  ( n12 ) ? ( n230 ) : ( n231 ) ;
assign n233 =  ( n1 ) ? ( wr_index ) : ( n232 ) ;
assign n234 =  ( n0 ) ? ( wr_index ) : ( n233 ) ;
assign n235 =  ( n171 ) ? ( n227 ) : ( wr_length ) ;
assign n236 =  ( n15 ) ? ( wr_length ) : ( wr_length ) ;
assign n237 =  ( n12 ) ? ( n235 ) : ( n236 ) ;
assign n238 =  ( n1 ) ? ( wr_length ) : ( n237 ) ;
assign n239 =  ( n0 ) ? ( wr_length ) : ( n238 ) ;
assign n240 =  ( n171 ) ? ( 1'd1 ) : ( wr_request ) ;
assign n241 =  ( n15 ) ? ( wr_request ) : ( wr_request ) ;
assign n242 =  ( n12 ) ? ( n240 ) : ( n241 ) ;
assign n243 =  ( n1 ) ? ( wr_request ) : ( n242 ) ;
assign n244 =  ( n0 ) ? ( wr_request ) : ( n243 ) ;
assign n245 = ~ ( n0 ) ;
assign n246 =  ( 1'b1 ) & ( n245 )  ;
assign n247 = ~ ( n1 ) ;
assign n248 =  ( n246 ) & ( n247 )  ;
assign n249 = ~ ( n15 ) ;
assign n250 =  ( n248 ) & ( n249 )  ;
assign n251 =  ( n248 ) & ( n15 )  ;
assign n252 =  ( n246 ) & ( n1 )  ;
assign n253 =  ( 1'b1 ) & ( n0 )  ;
assign n254 = ~ ( n166 ) ;
assign n255 =  ( n253 ) & ( n254 )  ;
assign n256 = ~ ( n97 ) ;
assign n257 =  ( n255 ) & ( n256 )  ;
assign n258 =  ( n255 ) & ( n97 )  ;
assign n259 =  ( 64'd0 ) << ( 64'd0 )  ;
assign n260 =  ( 64'd0 ) | ( n259 )  ;
assign n261 =  ( 64'd1073741824 ) << ( 64'd32 )  ;
assign n262 =  ( n260 ) | ( n261 )  ;
fun_sigmoid  applyFunc_n264(
    .arg1( n157 ),
    .result( n263 )
);
assign n265 = n263 ;
assign n266 =  ( n262 ) < ( n265 )  ;
assign n267 =  ( n266 ) ? ( 1'd1 ) : ( 1'd0 ) ;
assign n268 =  ( n253 ) & ( n166 )  ;
assign n269 =  ( n268 ) & ( n256 )  ;
assign n270 = num_hidden[6:0] ;
assign n271 =  ( n268 ) & ( n97 )  ;
assign hidden_unit_addr0 = n271 ? (n270) : (n269 ? (n270) : (n258 ? (n118) : (0)));
assign hidden_unit_data0 = n271 ? (1'd1) : (n269 ? (1'd1) : (n258 ? (n267) : ('dx)));
assign hidden_unit_wen0 = n271 ? ( 1'b1 ) : (n269 ? ( 1'b1 ) : (n258 ? ( 1'b1 ) : (1'b0)));
assign hidden_unit_addr1 = n271 ? (n118) : (0);
assign hidden_unit_data1 = n271 ? (n267) : ('dx);
assign hidden_unit_wen1 = n271 ? ( 1'b1 ) : (1'b0);
assign n272 = ~ ( n64 ) ;
assign n273 =  ( n252 ) & ( n272 )  ;
assign n274 = ~ ( n70 ) ;
assign n275 =  ( n273 ) & ( n274 )  ;
assign n276 = ~ ( n72 ) ;
assign n277 =  ( n275 ) & ( n276 )  ;
assign n278 = ~ ( n33 ) ;
assign n279 =  ( n277 ) & ( n278 )  ;
assign n280 = ~ ( n3 ) ;
assign n281 =  ( n279 ) & ( n280 )  ;
assign n282 =  ( n279 ) & ( n3 )  ;
assign n283 =  ( n277 ) & ( n33 )  ;
assign n284 =  ( n275 ) & ( n72 )  ;
assign n285 =  ( n273 ) & ( n70 )  ;
assign n286 =  ( n252 ) & ( n64 )  ;
assign pow2_addr0 = n284 ? (n36) : (0);
assign pow2_data0 = n284 ? (n203) : ('dx);
assign pow2_wen0 = n284 ? ( 1'b1 ) : (1'b0);
assign n287 = ~ ( n12 ) ;
assign n288 =  ( 1'b1 ) & ( n287 )  ;
assign n289 =  ( 1'b1 ) & ( n12 )  ;
assign n290 = ~ ( n9 ) ;
assign n291 =  ( n289 ) & ( n290 )  ;
assign n292 =  ( n289 ) & ( n9 )  ;
assign n293 = count[6:0] ;
assign predict_result_addr0 = n292 ? (n293) : (0);
assign predict_result_data0 = n292 ? (prediction) : ('dx);
assign predict_result_wen0 = n292 ? ( 1'b1 ) : (1'b0);
assign n294 =  ( n252 ) & ( n280 )  ;
assign n295 =  ( n252 ) & ( n3 )  ;
assign n296 = ~ ( n10 ) ;
assign n297 =  ( n295 ) & ( n296 )  ;
fun_round  applyFunc_n299(
    .arg1( expectation ),
    .result( n298 )
);
assign n300 = n298 ;
assign n301 =  {8'd0 , n300}  ;
assign n302 =  ( jstate ) == ( n301 )  ;
assign n303 =  ( n302 ) ? ( 1'd1 ) : ( 1'd0 ) ;
assign n304 =  ( n295 ) & ( n10 )  ;
assign n305 = num_visible[8:0] ;
assign predict_vector_addr0 = n304 ? (n305) : (n297 ? (n188) : (0));
assign predict_vector_data0 = n304 ? (1'd1) : (n297 ? (n303) : ('dx));
assign predict_vector_wen0 = n304 ? ( 1'b1 ) : (n297 ? ( 1'b1 ) : (1'b0));
assign predict_vector_addr1 = n304 ? (n188) : (0);
assign predict_vector_data1 = n304 ? (n303) : ('dx);
assign predict_vector_wen1 = n304 ? ( 1'b1 ) : (1'b0);
assign n306 =  ( n200 ) - ( n140 )  ;
assign n307 = ~ ( n65 ) ;
assign n308 =  ( n286 ) & ( n307 )  ;
assign n309 =  ( n286 ) & ( n65 )  ;
assign visibleEnergies_addr0 = n309 ? (n36) : (n285 ? (n36) : (0));
assign visibleEnergies_data0 = n309 ? (n133) : (n285 ? (n306) : ('dx));
assign visibleEnergies_wen0 = n309 ? ( 1'b1 ) : (n285 ? ( 1'b1 ) : (1'b0));
always @(posedge clk) begin
   if(rst) begin
       count <= count;
       data_out <= data_out;
       done <= 1'd0;
       expectation <= expectation;
       index <= 16'd0;
       init_done <= 1'd0;
       jstate <= jstate;
       loop_count <= 16'd0;
       num_hidden <= 16'd0;
       num_loops <= 16'd0;
       num_movies <= 16'd0;
       num_testusers <= 16'd0;
       num_users <= 16'd0;
       num_visible <= 16'd0;
       per_v_pc <= per_v_pc;
       predict_h_cnt <= 16'd0;
       predict_input_done <= 1'd0;
       predict_max <= predict_max;
       predict_sum <= predict_sum;
       predict_upc <= 4'd0;
       predict_v_cnt <= 16'd0;
       prediction <= prediction;
       rd_complete <= 1'd0;
       rd_index <= rd_index;
       rd_length <= rd_length;
       rd_request <= rd_request;
       sumOfpow2 <= sumOfpow2;
       train_input_done <= 1'd0;
       upc <= 4'd0;
       wr_complete <= 1'd0;
       wr_index <= wr_index;
       wr_length <= wr_length;
       wr_request <= wr_request;
   end
   else if(step) begin
       count <= n19;
       done <= n31;
       expectation <= n55;
       index <= n62;
       jstate <= n81;
       per_v_pc <= n96;
       predict_h_cnt <= n111;
       predict_input_done <= n115;
       predict_max <= n148;
       predict_sum <= n165;
       predict_upc <= n177;
       predict_v_cnt <= n186;
       prediction <= n196;
       sumOfpow2 <= n214;
       upc <= n219;
       wr_complete <= n225;
       wr_index <= n234;
       wr_length <= n239;
       wr_request <= n244;
   end
end
endmodule
