# Assertions for proving equivalence between ILA and HLS
#
# instructions terminate
assert -name {terminate - ila} \
{ (counter > 1) |-> (ila_complete == 0) \
} -update_db;
# 
assert -name {terminate - hls} \
{ (counter > 1) |-> (hls_step == 0) \
} -update_db;

# equivalence on arch states
# arg_1_TREADY
assert -name {eq - arg_1_TREADY} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.arg_1_TREADY == hls_U.arg_1_TREADY \
) } -update_db;
#
#assert -name {eq wait - arg_1_TREADY} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_U.arg_1_TREADY == hls_U.arg_1_TREADY \
) } -update_db;

# arg_0_TVALID
assert -name {eq - arg_0_TVALID} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.arg_0_TVALID == hls_U.arg_0_TVALID \
) } -update_db;
#
#assert -name {eq wait - arg_0_TVALID} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_U.arg_0_TVALID == hls_U.arg_0_TVALID \
) } -update_db;

# LB1D_p_cnt
assert -name {eq - LB1D_p_cnt} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB1D_p_cnt == hls_LB1D_p_cnt \
) } -update_db;
#
#assert -name {eq wait - LB1D_p_cnt} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_LB1D_p_cnt == hls_LB1D_p_cnt \
) } -update_db;

# in_stream_empty
assert -name {eq - in_stream_empty} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_in_stream_empty == hls_in_stream_empty \
) } -update_db;
#
#assert -name {eq wait - in_stream_empty} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_in_stream_empty == hls_in_stream_empty \
) } -update_db;

# in_stream_full
assert -name {eq - in_stream_full} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_in_stream_full == hls_in_stream_full \
) } -update_db;
#
#assert -name {eq wait - in_stream_full} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_in_stream_full == hls_in_stream_full \
) } -update_db;

# LB2D_proc_x
assert -name {eq - LB2D_proc_x} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB2D_proc_x == hls_LB2D_proc_x \
) } -update_db;

# LB2D_proc_y
assert -name {eq - LB2D_proc_y} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB2D_proc_y == hls_LB2D_proc_y \
) } -update_db;

# LB2D_proc_w
assert -name {eq - LB2D_proc_w} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> (\
    ila_LB2D_proc_w == hls_LB2D_proc_w \
) } -update_db;

# slice_stream_empty
assert -name {eq - slice_stream_empty} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_slice_stream_empty == hls_slice_stream_empty \
) } -update_db;

# slice_stream_full
assert -name {eq - slice_stream_full} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_slice_stream_full == hls_slice_stream_full \
) } -update_db;

# LB2D_shift_x
assert -name {eq - LB2D_shift_x} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB2D_shift_x == hls_LB2D_shift_x \
) } -update_db;

# LB2D_shift_y
assert -name {eq - LB2D_shift_y} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB2D_shift_y == hls_LB2D_shift_y \
) } -update_db;

# stencil_stream_empty
assert -name {eq - stencil_stream_empty} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_stream_empty == hls_stencil_stream_empty \
) } -update_db;

# stencil_stream_full
assert -name {eq - stencil_stream_full} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_stream_full == hls_stencil_stream_full \
) } -update_db;

# pp it
assert -name {eq - pp_it_1} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_1 == hls_gb_pp_it_1 \
) } -update_db;
#
assert -name {eq - pp_it_2} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_2 == hls_gb_pp_it_2 \
) } -update_db;
#
assert -name {eq - pp_it_3} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_3 == hls_gb_pp_it_3 \
) } -update_db;
#
assert -name {eq - pp_it_4} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_4 == hls_gb_pp_it_4 \
) } -update_db;
#
assert -name {eq - pp_it_5} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_5 == hls_gb_pp_it_5 \
) } -update_db;
#
assert -name {eq - pp_it_6} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_6 == hls_gb_pp_it_6 \
) } -update_db;
#
assert -name {eq - pp_it_7} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_7 == hls_gb_pp_it_7 \
) } -update_db;
#
assert -name {eq - pp_it_8} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_8 == hls_gb_pp_it_8 \
) } -update_db;
#
assert -name {eq - pp_it_9} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_pp_it_9 == hls_gb_pp_it_9 \
) } -update_db;

# exit it
assert -name {eq - exit_it_1} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_exit_it_1 == hls_gb_exit_it_1 \
) } -update_db;
#
assert -name {eq - exit_it_2} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_exit_it_2 == hls_gb_exit_it_2 \
) } -update_db;
#
assert -name {eq - exit_it_3} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_exit_it_3 == hls_gb_exit_it_3 \
) } -update_db;
#
assert -name {eq - exit_it_4} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_exit_it_4 == hls_gb_exit_it_4 \
) } -update_db;
#
assert -name {eq - exit_it_5} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_exit_it_5 == hls_gb_exit_it_5 \
) } -update_db;
#
assert -name {eq - exit_it_6} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_exit_it_6 == hls_gb_exit_it_6 \
) } -update_db;
#
assert -name {eq - exit_it_7} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_gb_exit_it_7 == hls_gb_exit_it_7 \
) } -update_db;
#
assert -name {eq - LB1D_in} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB1D_in == hls_LB1D_in \
) } -update_db;
#
assert -name {eq - LB1D_buff} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB1D_buff == hls_LB1D_buff \
) } -update_db;
#
assert -name {eq - in_stream_buff_0} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_in_stream_buff_0 == hls_in_stream_buff_0 \
) } -update_db;
#
assert -name {eq - in_stream_buff_1} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_in_stream_buff_1 == hls_in_stream_buff_1 \
) } -update_db;
#
assert -name {eq - slice_stream_buff_0} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_slice_stream_buff_0 == hls_slice_stream_buff_0 \
) } -update_db;
#
assert -name {eq - slice_stream_buff_1} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_slice_stream_buff_1 == hls_slice_stream_buff_1 \
) } -update_db;
#
assert -name {eq - stencil_stream_buff_0} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_stream_buff_0 == hls_stencil_stream_buff_0 \
) } -update_db;
#
assert -name {eq - stencil_stream_buff_1} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_stream_buff_1 == hls_stencil_stream_buff_1 \
) } -update_db;
#
#assert -name {eq - LB1D_buff_test} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB1D_buff == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_data_reg \
) } -update_db;
#
#assert -name {eq - LB1D_buff_test2} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB1D_buff == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_data_out \
) } -update_db;
