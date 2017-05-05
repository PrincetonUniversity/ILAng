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
module train(
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
visibleEnergies_data_n63,
hidden_unit_data_n101,
edges_data_n107,
data_data_n133,
pos_data_n179,
visible_unit_data_n184,
pow2_data_n243,
data_out,
done,
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
predict_input_done,
rd_complete,
rd_index,
rd_length,
rd_request,
sumOfpow2,
train_h_cnt,
train_input_done,
train_max,
train_sum,
train_upc,
train_v_cnt,
upc,
wr_complete,
wr_index,
wr_length,
wr_request,
visibleEnergies_addr_n62,
hidden_unit_addr_n100,
edges_addr_n106,
data_addr_n132,
edges_addr0,
edges_data0,
edges_wen0,
pos_addr_n178,
visible_unit_addr_n183,
hidden_unit_addr0,
hidden_unit_data0,
hidden_unit_wen0,
hidden_unit_addr1,
hidden_unit_data1,
hidden_unit_wen1,
pos_addr0,
pos_data0,
pos_wen0,
pow2_addr0,
pow2_data0,
pow2_wen0,
visibleEnergies_addr0,
visibleEnergies_data0,
visibleEnergies_wen0,
visible_unit_addr0,
visible_unit_data0,
visible_unit_wen0,
visible_unit_addr1,
visible_unit_data1,
visible_unit_wen1,
pow2_addr_n242,
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
input     [15:0] visibleEnergies_data_n63;
input            hidden_unit_data_n101;
input      [7:0] edges_data_n107;
input      [7:0] data_data_n133;
input            pos_data_n179;
input            visible_unit_data_n184;
input     [31:0] pow2_data_n243;
input rst;
input clk;
input step;
output     [31:0] data_out;
output            done;
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
output            predict_input_done;
output            rd_complete;
output     [31:0] rd_index;
output     [31:0] rd_length;
output            rd_request;
output     [63:0] sumOfpow2;
output     [15:0] train_h_cnt;
output            train_input_done;
output     [15:0] train_max;
output     [15:0] train_sum;
output      [3:0] train_upc;
output     [15:0] train_v_cnt;
output      [3:0] upc;
output            wr_complete;
output     [31:0] wr_index;
output     [31:0] wr_length;
output            wr_request;
output      [2:0] visibleEnergies_addr_n62;
output      [6:0] hidden_unit_addr_n100;
output     [15:0] edges_addr_n106;
output      [8:0] data_addr_n132;
output     [15:0] edges_addr0;
output      [7:0] edges_data0;
output            edges_wen0;
output     [15:0] pos_addr_n178;
output      [8:0] visible_unit_addr_n183;
output      [6:0] hidden_unit_addr0;
output            hidden_unit_data0;
output            hidden_unit_wen0;
output      [6:0] hidden_unit_addr1;
output            hidden_unit_data1;
output            hidden_unit_wen1;
output     [15:0] pos_addr0;
output            pos_data0;
output            pos_wen0;
output      [2:0] pow2_addr0;
output     [31:0] pow2_data0;
output            pow2_wen0;
output      [2:0] visibleEnergies_addr0;
output     [15:0] visibleEnergies_data0;
output            visibleEnergies_wen0;
output      [8:0] visible_unit_addr0;
output            visible_unit_data0;
output            visible_unit_wen0;
output      [8:0] visible_unit_addr1;
output            visible_unit_data1;
output            visible_unit_wen1;
output      [2:0] pow2_addr_n242;
reg     [31:0] data_out;
reg            done;
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
reg            predict_input_done;
reg            rd_complete;
reg     [31:0] rd_index;
reg     [31:0] rd_length;
reg            rd_request;
reg     [63:0] sumOfpow2;
reg     [15:0] train_h_cnt;
reg            train_input_done;
reg     [15:0] train_max;
reg     [15:0] train_sum;
reg      [3:0] train_upc;
reg     [15:0] train_v_cnt;
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
wire     [15:0] n6;
wire            n7;
wire            n8;
wire            n9;
wire     [15:0] n10;
wire     [15:0] n11;
wire     [15:0] n12;
wire     [15:0] n13;
wire     [15:0] n14;
wire     [15:0] n15;
wire            n16;
wire            n17;
wire            n18;
wire     [15:0] n19;
wire     [15:0] n20;
wire     [15:0] n21;
wire            n22;
wire            n23;
wire            n24;
wire            n25;
wire            n26;
wire            n27;
wire     [15:0] n28;
wire     [15:0] n29;
wire     [15:0] n30;
wire     [15:0] n31;
wire     [15:0] n32;
wire     [15:0] n33;
wire     [15:0] n34;
wire            n35;
wire            n36;
wire     [15:0] n37;
wire     [15:0] n38;
wire     [15:0] n39;
wire     [15:0] n40;
wire     [15:0] n41;
wire            n42;
wire      [3:0] n43;
wire      [3:0] n44;
wire      [3:0] n45;
wire     [15:0] n46;
wire            n47;
wire            n48;
wire            n49;
wire      [3:0] n50;
wire      [3:0] n51;
wire      [3:0] n52;
wire      [3:0] n53;
wire      [3:0] n54;
wire      [3:0] n55;
wire      [3:0] n56;
wire      [3:0] n57;
wire      [3:0] n58;
wire            n59;
wire     [63:0] n60;
wire      [2:0] n61;
wire     [15:0] n64;
wire     [31:0] n65;
wire     [31:0] n67;
wire     [31:0] n68;
wire     [63:0] n69;
wire     [63:0] n70;
wire     [63:0] n71;
wire     [63:0] n72;
wire     [63:0] n73;
wire     [63:0] n74;
wire     [63:0] n75;
wire     [63:0] n76;
wire     [63:0] n77;
wire     [15:0] n78;
wire            n79;
wire     [15:0] n80;
wire     [15:0] n81;
wire     [15:0] n82;
wire     [15:0] n83;
wire     [15:0] n84;
wire     [15:0] n85;
wire     [15:0] n86;
wire     [15:0] n87;
wire            n88;
wire     [15:0] n89;
wire     [15:0] n90;
wire     [15:0] n91;
wire     [15:0] n92;
wire            n93;
wire            n94;
wire            n95;
wire            n96;
wire            n97;
wire     [15:0] n98;
wire      [6:0] n99;
wire            n102;
wire            n103;
wire     [15:0] n104;
wire     [15:0] n105;
wire      [7:0] n108;
wire      [6:0] n109;
wire     [14:0] n110;
wire            n111;
wire     [15:0] n112;
wire     [15:0] n113;
wire     [15:0] n114;
wire     [15:0] n115;
wire     [15:0] n116;
wire            n117;
wire     [15:0] n118;
wire     [15:0] n119;
wire     [15:0] n120;
wire     [15:0] n121;
wire     [15:0] n122;
wire     [15:0] n123;
wire     [15:0] n124;
wire     [15:0] n125;
wire     [15:0] n126;
wire     [15:0] n127;
wire     [15:0] n128;
wire            n129;
wire     [15:0] n130;
wire      [8:0] n131;
wire      [7:0] n134;
wire            n135;
wire     [15:0] n136;
wire     [15:0] n137;
wire     [15:0] n138;
wire     [15:0] n139;
wire     [15:0] n140;
wire     [15:0] n141;
wire     [15:0] n142;
wire     [15:0] n143;
wire     [15:0] n144;
wire            n145;
wire      [3:0] n146;
wire            n147;
wire            n148;
wire      [3:0] n149;
wire      [3:0] n150;
wire      [3:0] n151;
wire      [3:0] n152;
wire      [3:0] n153;
wire      [3:0] n154;
wire      [3:0] n155;
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
wire     [15:0] n166;
wire      [3:0] n167;
wire      [3:0] n168;
wire      [3:0] n169;
wire      [3:0] n170;
wire     [15:0] edges_addr0;
wire      [7:0] edges_data0;
wire            edges_wen0;
wire            n171;
wire            n172;
wire            n173;
wire            n174;
wire            n175;
wire            n176;
wire            n177;
wire            n180;
wire            n181;
wire            n182;
wire            n185;
wire            n186;
wire            n187;
wire            n188;
wire            n189;
wire      [7:0] n190;
wire            n191;
wire            n192;
wire      [7:0] n193;
wire      [7:0] n194;
wire      [7:0] n195;
wire            n196;
wire            n197;
wire      [6:0] hidden_unit_addr0;
wire            hidden_unit_data0;
wire            hidden_unit_wen0;
wire      [6:0] hidden_unit_addr1;
wire            hidden_unit_data1;
wire            hidden_unit_wen1;
wire            n198;
wire            n199;
wire            n200;
wire            n201;
wire            n202;
wire     [63:0] n203;
wire     [63:0] n205;
wire     [63:0] n206;
wire     [63:0] n208;
wire            n209;
wire            n210;
wire            n211;
wire            n212;
wire      [6:0] n213;
wire            n214;
wire     [15:0] pos_addr0;
wire            pos_data0;
wire            pos_wen0;
wire            n215;
wire            n216;
wire            n217;
wire            n218;
wire            n219;
wire            n220;
wire      [2:0] pow2_addr0;
wire     [31:0] pow2_data0;
wire            pow2_wen0;
wire            n221;
wire            n222;
wire            n223;
wire            n224;
wire            n225;
wire            n226;
wire            n227;
wire            n228;
wire            n229;
wire            n230;
wire            n231;
wire            n232;
wire      [2:0] visibleEnergies_addr0;
wire     [15:0] visibleEnergies_data0;
wire            visibleEnergies_wen0;
wire     [15:0] n233;
wire            n234;
wire            n235;
wire            n236;
wire      [8:0] visible_unit_addr0;
wire            visible_unit_data0;
wire            visible_unit_wen0;
wire      [8:0] visible_unit_addr1;
wire            visible_unit_data1;
wire            visible_unit_wen1;
wire            n237;
wire            n238;
wire            n239;
wire     [15:0] n240;
wire      [8:0] n241;
wire     [31:0] n244;
wire     [63:0] n245;
wire     [63:0] n247;
wire            n248;
wire            n249;
wire            n250;
wire      [8:0] n251;
wire clk;
wire rst;
wire step;
assign n0 =  ( train_upc ) == ( 4'd0 )  ;
assign n1 =  ( train_upc ) == ( 4'd1 )  ;
assign n2 =  ( train_upc ) == ( 4'd2 )  ;
assign n3 =  ( train_h_cnt ) == ( num_hidden )  ;
assign n4 =  ( train_v_cnt ) == ( num_visible )  ;
assign n5 =  ( n3 ) & ( n4 )  ;
assign n6 =  ( num_users ) - ( 16'd1 )  ;
assign n7 =  ( index ) == ( n6 )  ;
assign n8 =  ( loop_count ) != ( num_loops )  ;
assign n9 =  ( n7 ) & ( n8 )  ;
assign n10 =  ( index ) + ( 16'd1 )  ;
assign n11 =  ( n9 ) ? ( 16'd0 ) : ( n10 ) ;
assign n12 =  ( n5 ) ? ( n11 ) : ( index ) ;
assign n13 =  ( n2 ) ? ( n12 ) : ( index ) ;
assign n14 =  ( n1 ) ? ( index ) : ( n13 ) ;
assign n15 =  ( n0 ) ? ( index ) : ( n14 ) ;
assign n16 =  ( per_v_pc ) == ( 4'd0 )  ;
assign n17 =  ( n1 ) & ( n16 )  ;
assign n18 =  ( jstate ) == ( 16'd4 )  ;
assign n19 =  ( jstate ) + ( 16'd1 )  ;
assign n20 =  ( n18 ) ? ( 16'd0 ) : ( n19 ) ;
assign n21 =  ( n3 ) ? ( n20 ) : ( jstate ) ;
assign n22 =  ( per_v_pc ) == ( 4'd1 )  ;
assign n23 =  ( n1 ) & ( n22 )  ;
assign n24 =  ( per_v_pc ) == ( 4'd2 )  ;
assign n25 =  ( n1 ) & ( n24 )  ;
assign n26 =  ( per_v_pc ) == ( 4'd3 )  ;
assign n27 =  ( n1 ) & ( n26 )  ;
assign n28 =  ( n27 ) ? ( n20 ) : ( jstate ) ;
assign n29 =  ( n25 ) ? ( n20 ) : ( n28 ) ;
assign n30 =  ( n23 ) ? ( n20 ) : ( n29 ) ;
assign n31 =  ( n17 ) ? ( n21 ) : ( n30 ) ;
assign n32 =  ( n2 ) ? ( jstate ) : ( jstate ) ;
assign n33 =  ( n1 ) ? ( n31 ) : ( n32 ) ;
assign n34 =  ( n0 ) ? ( 16'd0 ) : ( n33 ) ;
assign n35 =  ( n5 ) & ( n7 )  ;
assign n36 =  ( n35 ) & ( n8 )  ;
assign n37 =  ( loop_count ) + ( 16'd1 )  ;
assign n38 =  ( n36 ) ? ( n37 ) : ( loop_count ) ;
assign n39 =  ( n2 ) ? ( n38 ) : ( loop_count ) ;
assign n40 =  ( n1 ) ? ( loop_count ) : ( n39 ) ;
assign n41 =  ( n0 ) ? ( loop_count ) : ( n40 ) ;
assign n42 =  ( n18 ) & ( n3 )  ;
assign n43 =  ( n42 ) ? ( 4'd1 ) : ( per_v_pc ) ;
assign n44 =  ( n18 ) ? ( 4'd2 ) : ( per_v_pc ) ;
assign n45 =  ( n18 ) ? ( 4'd3 ) : ( per_v_pc ) ;
assign n46 =  ( train_v_cnt ) + ( 16'd5 )  ;
assign n47 =  ( n46 ) == ( num_visible )  ;
assign n48 =  ( n46 ) >= ( 16'd500 )  ;
assign n49 =  ( n47 ) | ( n48 )  ;
assign n50 =  ( n49 ) ? ( 4'd0 ) : ( 4'd0 ) ;
assign n51 =  ( n18 ) ? ( n50 ) : ( per_v_pc ) ;
assign n52 =  ( n27 ) ? ( n51 ) : ( per_v_pc ) ;
assign n53 =  ( n25 ) ? ( n45 ) : ( n52 ) ;
assign n54 =  ( n23 ) ? ( n44 ) : ( n53 ) ;
assign n55 =  ( n17 ) ? ( n43 ) : ( n54 ) ;
assign n56 =  ( n2 ) ? ( per_v_pc ) : ( per_v_pc ) ;
assign n57 =  ( n1 ) ? ( n55 ) : ( n56 ) ;
assign n58 =  ( n0 ) ? ( 4'd0 ) : ( n57 ) ;
assign n59 =  ( jstate ) == ( 16'd0 )  ;
assign n60 =  ( n59 ) ? ( 64'd0 ) : ( sumOfpow2 ) ;
assign n61 = jstate[2:0] ;
assign visibleEnergies_addr_n62 = n61 ;
assign n64 = visibleEnergies_data_n63 ;
fun_to_int_exp  applyFunc_n66(
    .arg1( n64 ),
    .result( n65 )
);
assign n67 = n65 ;
assign n68 = n67[31:0] ;
assign n69 =  {32'd0 , n68}  ;
assign n70 =  ( n60 ) + ( n69 )  ;
assign n71 =  ( n27 ) ? ( sumOfpow2 ) : ( sumOfpow2 ) ;
assign n72 =  ( n25 ) ? ( n70 ) : ( n71 ) ;
assign n73 =  ( n23 ) ? ( sumOfpow2 ) : ( n72 ) ;
assign n74 =  ( n17 ) ? ( sumOfpow2 ) : ( n73 ) ;
assign n75 =  ( n2 ) ? ( sumOfpow2 ) : ( sumOfpow2 ) ;
assign n76 =  ( n1 ) ? ( n74 ) : ( n75 ) ;
assign n77 =  ( n0 ) ? ( sumOfpow2 ) : ( n76 ) ;
assign n78 =  ( num_hidden ) - ( 16'd1 )  ;
assign n79 =  ( train_h_cnt ) == ( n78 )  ;
assign n80 =  ( train_h_cnt ) + ( 16'd1 )  ;
assign n81 =  ( n79 ) ? ( 16'd0 ) : ( n80 ) ;
assign n82 =  ( n4 ) ? ( n81 ) : ( train_h_cnt ) ;
assign n83 =  ( n3 ) ? ( 16'd0 ) : ( n80 ) ;
assign n84 =  ( n27 ) ? ( train_h_cnt ) : ( train_h_cnt ) ;
assign n85 =  ( n25 ) ? ( train_h_cnt ) : ( n84 ) ;
assign n86 =  ( n23 ) ? ( train_h_cnt ) : ( n85 ) ;
assign n87 =  ( n17 ) ? ( n83 ) : ( n86 ) ;
assign n88 =  ( train_upc ) == ( 4'd3 )  ;
assign n89 =  ( n2 ) ? ( n83 ) : ( train_h_cnt ) ;
assign n90 =  ( n88 ) ? ( n83 ) : ( n89 ) ;
assign n91 =  ( n1 ) ? ( n87 ) : ( n90 ) ;
assign n92 =  ( n0 ) ? ( n82 ) : ( n91 ) ;
assign n93 =  ( n5 ) ? ( 1'd0 ) : ( train_input_done ) ;
assign n94 =  ( n2 ) ? ( n93 ) : ( train_input_done ) ;
assign n95 =  ( n1 ) ? ( train_input_done ) : ( n94 ) ;
assign n96 =  ( n0 ) ? ( train_input_done ) : ( n95 ) ;
assign n97 =  ( train_h_cnt ) == ( 16'd0 )  ;
assign n98 =  ( n97 ) ? ( 16'd0 ) : ( train_sum ) ;
assign n99 = train_h_cnt[6:0] ;
assign hidden_unit_addr_n100 = n99 ;
assign n102 = hidden_unit_data_n101 ;
assign n103 =  ( n102 ) == ( 1'd1 )  ;
assign n104 =  ( ( 16'd101 ) * ( train_v_cnt ))  ;
assign n105 =  ( n104 ) + ( train_h_cnt )  ;
assign edges_addr_n106 = n105 ;
assign n108 = edges_data_n107 ;
assign n109 = n108[7:1] ;
assign n110 =  { {8{n109[6] }  }, n109}  ;
assign n111 = n108[0:0] ;
assign n112 =  { ( n110 ) , ( n111 ) }  ;
assign n113 =  ( n103 ) ? ( n112 ) : ( 16'd0 ) ;
assign n114 =  ( n98 ) + ( n113 )  ;
assign n115 = ( ~ ( 16'd1000 ) + 1'b1 ) ;
assign n116 =  ( n59 ) ? ( n115 ) : ( train_max ) ;
assign n117 =  $signed( n114 ) > $signed( n116 )  ;
assign n118 =  ( n117 ) ? ( n114 ) : ( n116 ) ;
assign n119 =  ( n3 ) ? ( n118 ) : ( train_max ) ;
assign n120 =  ( train_max ) - ( 16'd62 )  ;
assign n121 =  ( n59 ) ? ( n120 ) : ( train_max ) ;
assign n122 =  ( n27 ) ? ( train_max ) : ( train_max ) ;
assign n123 =  ( n25 ) ? ( train_max ) : ( n122 ) ;
assign n124 =  ( n23 ) ? ( n121 ) : ( n123 ) ;
assign n125 =  ( n17 ) ? ( n119 ) : ( n124 ) ;
assign n126 =  ( n2 ) ? ( train_max ) : ( train_max ) ;
assign n127 =  ( n1 ) ? ( n125 ) : ( n126 ) ;
assign n128 =  ( n0 ) ? ( train_max ) : ( n127 ) ;
assign n129 =  ( train_v_cnt ) == ( 16'd0 )  ;
assign n130 =  ( n129 ) ? ( 16'd0 ) : ( train_sum ) ;
assign n131 = train_v_cnt[8:0] ;
assign data_addr_n132 = n131 ;
assign n134 = data_data_n133 ;
assign n135 =  ( n134 ) == ( 8'd1 )  ;
assign n136 =  ( n135 ) ? ( n112 ) : ( 16'd0 ) ;
assign n137 =  ( n130 ) + ( n136 )  ;
assign n138 =  ( n27 ) ? ( train_sum ) : ( train_sum ) ;
assign n139 =  ( n25 ) ? ( train_sum ) : ( n138 ) ;
assign n140 =  ( n23 ) ? ( train_sum ) : ( n139 ) ;
assign n141 =  ( n17 ) ? ( n114 ) : ( n140 ) ;
assign n142 =  ( n2 ) ? ( train_sum ) : ( train_sum ) ;
assign n143 =  ( n1 ) ? ( n141 ) : ( n142 ) ;
assign n144 =  ( n0 ) ? ( n137 ) : ( n143 ) ;
assign n145 =  ( n4 ) & ( n79 )  ;
assign n146 =  ( n145 ) ? ( 4'd1 ) : ( 4'd0 ) ;
assign n147 =  ( n27 ) & ( n18 )  ;
assign n148 =  ( n147 ) & ( n49 )  ;
assign n149 =  ( n148 ) ? ( 4'd3 ) : ( 4'd1 ) ;
assign n150 =  ( n5 ) ? ( 4'd2 ) : ( 4'd3 ) ;
assign n151 =  ( n5 ) ? ( 4'd2 ) : ( 4'd2 ) ;
assign n152 =  ( n2 ) ? ( n151 ) : ( train_upc ) ;
assign n153 =  ( n88 ) ? ( n150 ) : ( n152 ) ;
assign n154 =  ( n1 ) ? ( n149 ) : ( n153 ) ;
assign n155 =  ( n0 ) ? ( n146 ) : ( n154 ) ;
assign n156 =  ( train_v_cnt ) + ( 16'd1 )  ;
assign n157 =  ( n4 ) ? ( 16'd0 ) : ( n156 ) ;
assign n158 =  ( n49 ) ? ( 16'd0 ) : ( n46 ) ;
assign n159 =  ( n147 ) ? ( n158 ) : ( train_v_cnt ) ;
assign n160 =  ( n3 ) ? ( n157 ) : ( train_v_cnt ) ;
assign n161 =  ( n4 ) ? ( train_v_cnt ) : ( n156 ) ;
assign n162 =  ( n3 ) ? ( n161 ) : ( train_v_cnt ) ;
assign n163 =  ( n2 ) ? ( n162 ) : ( train_v_cnt ) ;
assign n164 =  ( n88 ) ? ( n160 ) : ( n163 ) ;
assign n165 =  ( n1 ) ? ( n159 ) : ( n164 ) ;
assign n166 =  ( n0 ) ? ( n157 ) : ( n165 ) ;
assign n167 =  ( n5 ) ? ( 4'd0 ) : ( upc ) ;
assign n168 =  ( n2 ) ? ( n167 ) : ( upc ) ;
assign n169 =  ( n1 ) ? ( upc ) : ( n168 ) ;
assign n170 =  ( n0 ) ? ( upc ) : ( n169 ) ;
assign n171 = ~ ( n0 ) ;
assign n172 =  ( 1'b1 ) & ( n171 )  ;
assign n173 = ~ ( n1 ) ;
assign n174 =  ( n172 ) & ( n173 )  ;
assign n175 = ~ ( n2 ) ;
assign n176 =  ( n174 ) & ( n175 )  ;
assign n177 =  ( n174 ) & ( n2 )  ;
assign pos_addr_n178 = n105 ;
assign n180 = pos_data_n179 ;
assign n181 =  ( n180 ) != ( 1'd0 )  ;
assign n182 =  ( n102 ) != ( 1'd0 )  ;
assign visible_unit_addr_n183 = n131 ;
assign n185 = visible_unit_data_n184 ;
assign n186 =  ( n185 ) != ( 1'd0 )  ;
assign n187 =  ( n182 ) & ( n186 )  ;
assign n188 = ~ ( n187 ) ;
assign n189 =  ( n181 ) & ( n188 )  ;
assign n190 =  ( n108 ) + ( 8'd1 )  ;
assign n191 = ~ ( n181 ) ;
assign n192 =  ( n191 ) & ( n187 )  ;
assign n193 =  ( n108 ) - ( 8'd1 )  ;
assign n194 =  ( n192 ) ? ( n193 ) : ( n108 ) ;
assign n195 =  ( n189 ) ? ( n190 ) : ( n194 ) ;
assign n196 =  ( n172 ) & ( n1 )  ;
assign n197 =  ( 1'b1 ) & ( n0 )  ;
assign edges_addr0 = n177 ? (n105) : (0);
assign edges_data0 = n177 ? (n195) : ('dx);
assign edges_wen0 = n177 ? ( 1'b1 ) : (1'b0);
assign n198 = ~ ( n145 ) ;
assign n199 =  ( n197 ) & ( n198 )  ;
assign n200 = ~ ( n4 ) ;
assign n201 =  ( n199 ) & ( n200 )  ;
assign n202 =  ( n199 ) & ( n4 )  ;
fun_rand  applyFunc_n204(
    .result( n203 )
);
assign n205 = n203 ;
fun_sigmoid  applyFunc_n207(
    .arg1( n137 ),
    .result( n206 )
);
assign n208 = n206 ;
assign n209 =  ( n205 ) < ( n208 )  ;
assign n210 =  ( n209 ) ? ( 1'd1 ) : ( 1'd0 ) ;
assign n211 =  ( n197 ) & ( n145 )  ;
assign n212 =  ( n211 ) & ( n200 )  ;
assign n213 = num_hidden[6:0] ;
assign n214 =  ( n211 ) & ( n4 )  ;
assign hidden_unit_addr0 = n214 ? (n213) : (n212 ? (n213) : (n202 ? (n99) : (0)));
assign hidden_unit_data0 = n214 ? (1'd1) : (n212 ? (1'd1) : (n202 ? (n210) : ('dx)));
assign hidden_unit_wen0 = n214 ? ( 1'b1 ) : (n212 ? ( 1'b1 ) : (n202 ? ( 1'b1 ) : (1'b0)));
assign hidden_unit_addr1 = n214 ? (n99) : (0);
assign hidden_unit_data1 = n214 ? (n210) : ('dx);
assign hidden_unit_wen1 = n214 ? ( 1'b1 ) : (1'b0);
assign n215 = ~ ( n88 ) ;
assign n216 =  ( 1'b1 ) & ( n215 )  ;
assign n217 =  ( 1'b1 ) & ( n88 )  ;
assign n218 =  ( n134 ) != ( 8'd0 )  ;
assign n219 =  ( n218 ) ? ( 1'd1 ) : ( 1'd0 ) ;
assign n220 =  ( n219 ) & ( n102 )  ;
assign pos_addr0 = n217 ? (n105) : (0);
assign pos_data0 = n217 ? (n220) : ('dx);
assign pos_wen0 = n217 ? ( 1'b1 ) : (1'b0);
assign n221 = ~ ( n17 ) ;
assign n222 =  ( n196 ) & ( n221 )  ;
assign n223 = ~ ( n23 ) ;
assign n224 =  ( n222 ) & ( n223 )  ;
assign n225 = ~ ( n25 ) ;
assign n226 =  ( n224 ) & ( n225 )  ;
assign n227 = ~ ( n27 ) ;
assign n228 =  ( n226 ) & ( n227 )  ;
assign n229 =  ( n226 ) & ( n27 )  ;
assign n230 =  ( n224 ) & ( n25 )  ;
assign n231 =  ( n222 ) & ( n23 )  ;
assign n232 =  ( n196 ) & ( n17 )  ;
assign pow2_addr0 = n230 ? (n61) : (0);
assign pow2_data0 = n230 ? (n67) : ('dx);
assign pow2_wen0 = n230 ? ( 1'b1 ) : (1'b0);
assign n233 =  ( n64 ) - ( n121 )  ;
assign n234 = ~ ( n3 ) ;
assign n235 =  ( n232 ) & ( n234 )  ;
assign n236 =  ( n232 ) & ( n3 )  ;
assign visibleEnergies_addr0 = n236 ? (n61) : (n231 ? (n61) : (0));
assign visibleEnergies_data0 = n236 ? (n114) : (n231 ? (n233) : ('dx));
assign visibleEnergies_wen0 = n236 ? ( 1'b1 ) : (n231 ? ( 1'b1 ) : (1'b0));
assign n237 =  ( n18 ) & ( n49 )  ;
assign n238 = ~ ( n237 ) ;
assign n239 =  ( n229 ) & ( n238 )  ;
assign n240 =  ( train_v_cnt ) + ( jstate )  ;
assign n241 = n240[8:0] ;
assign pow2_addr_n242 = n61 ;
assign n244 = pow2_data_n243 ;
fun_divide  applyFunc_n246(
    .arg1( n244 ),
    .arg2( sumOfpow2 ),
    .result( n245 )
);
assign n247 = n245 ;
assign n248 =  ( n247 ) > ( n205 )  ;
assign n249 =  ( n248 ) ? ( 1'd1 ) : ( 1'd0 ) ;
assign n250 =  ( n229 ) & ( n237 )  ;
assign n251 = num_visible[8:0] ;
assign visible_unit_addr0 = n250 ? (n251) : (n239 ? (n241) : (0));
assign visible_unit_data0 = n250 ? (1'd1) : (n239 ? (n249) : ('dx));
assign visible_unit_wen0 = n250 ? ( 1'b1 ) : (n239 ? ( 1'b1 ) : (1'b0));
assign visible_unit_addr1 = n250 ? (n241) : (0);
assign visible_unit_data1 = n250 ? (n249) : ('dx);
assign visible_unit_wen1 = n250 ? ( 1'b1 ) : (1'b0);
always @(posedge clk) begin
   if(rst) begin
       data_out <= data_out;
       done <= 1'd0;
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
       predict_input_done <= 1'd0;
       rd_complete <= 1'd0;
       rd_index <= rd_index;
       rd_length <= rd_length;
       rd_request <= rd_request;
       sumOfpow2 <= sumOfpow2;
       train_h_cnt <= 16'd0;
       train_input_done <= 1'd0;
       train_max <= train_max;
       train_sum <= train_sum;
       train_upc <= 4'd0;
       train_v_cnt <= 16'd0;
       upc <= 4'd0;
       wr_complete <= 1'd0;
       wr_index <= wr_index;
       wr_length <= wr_length;
       wr_request <= wr_request;
   end
   else if(step) begin
       index <= n15;
       jstate <= n34;
       loop_count <= n41;
       per_v_pc <= n58;
       sumOfpow2 <= n77;
       train_h_cnt <= n92;
       train_input_done <= n96;
       train_max <= n128;
       train_sum <= n144;
       train_upc <= n155;
       train_v_cnt <= n166;
       upc <= n170;
   end
end
endmodule
