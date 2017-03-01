// top level wrapper for testing ILA RTL in JasperGold

module topILA(
    init_arg_0_TREADY,
    init_arg_1_TDATA,
    init_arg_1_TVALID,
    init_arg_0_TDATA,
    init_arg_0_TVALID,
    init_arg_1_TREADY,
    init_buffer_0_value_V_fu,
    init_buffer_1_value_V_fu,
    init_buffer_2_value_V_fu,
    init_buffer_3_value_V_fu,
    init_buffer_4_value_V_fu,
    init_buffer_5_value_V_fu,
    init_buffer_6_value_V_fu,
    init_buffer_7_value_V_fu,
    init_x_idx,
    init_y_idx,
    init_w_idx,
    init_stencil_buff,
    init_stencil_full,
    init_slice_buff,
    init_slice_full
);

input         init_arg_0_TREADY;
input [7:0]   init_arg_1_TDATA;
input         init_arg_1_TVALID;
input [7:0]   init_arg_0_TDATA;
input         init_arg_0_TVALID;
input         init_arg_1_TREADY;
input [71:0]  init_buffer_0_value_V_fu;
input [71:0]  init_buffer_1_value_V_fu;
input [71:0]  init_buffer_2_value_V_fu;
input [71:0]  init_buffer_3_value_V_fu;
input [71:0]  init_buffer_4_value_V_fu;
input [71:0]  init_buffer_5_value_V_fu;
input [71:0]  init_buffer_6_value_V_fu;
input [71:0]  init_buffer_7_value_V_fu;
input [8:0]   init_x_idx;
input [9:0]   init_y_idx;
input [63:0]  init_w_idx;
input [647:0] init_stencil_buff;
input         init_stencil_full;
input [71:0]  init_slice_buff;
input         init_slice_full;

endmodule
