# Assumptions for refining initial condition by blocking unreachable states
#
# arch states
# buffer status: should not be full and empty at the same time
assume -name {inv - stream buffer status} -env \
{ ( \
    ~(ila_U.in_stream_full == 1 & ila_U.in_stream_empty == 1) & \
    ~(ila_U.slice_stream_full == 1 & ila_U.slice_stream_empty == 1) & \
    ~(ila_U.stencil_stream_full == 1 & ila_U.stencil_stream_empty == 1) & \
    ~(hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n  == 0 & \
      hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n == 0) & \
    ~(hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_full_n  == 0 & \
      hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_empty_n == 0) & \
    ~(hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n  == 0 & \
      hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n == 0) \
)} -type {temporary} -update_db;

# x/y/w index: should fall in valid range
assume -name {inv - x/y/w index} -env \
{ ( \
    ila_U.LB2D_proc_x >= 0 & ila_U.LB2D_proc_x < 488 & \
    ila_U.LB2D_proc_y >= 0 & ila_U.LB2D_proc_y < 648 & \
    ila_U.LB2D_proc_w >= 0 & ila_U.LB2D_proc_w < 8 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.col_reg_349 >= 0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.col_reg_349 <= 488 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_reg_327 >= 0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_reg_327 <= 648 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.write_idx_1_reg_315 >= 0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.write_idx_1_reg_315 < 8 & \
    ila_U.LB2D_shift_x >= 0 & ila_U.LB2D_shift_x <= 488 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.i_0_i_i_reg_152 >= 0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.i_0_i_i_reg_152 <= 488 \
)} -type {temporary} -update_db;

# y idx smaller then 8 --> slice empty
assume -name {inv - y/slice - ila} -env \
{ ( \
    (ila_U.LB2D_proc_y <= 7 |-> ila_U.slice_stream_empty == 1) \
)} -type {temporary} -update_db;

assume -name {inv - y/slice - hls} -env \
{ ( \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.col_reg_349 <= 7 |-> \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_empty_n == 0) \
)} -type {temporary} -update_db;

# micro-arch states
# internal fsm state encoding
assume -name {inv - cs/ns fsm} -env \
{ ( \
    ((hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_CS_fsm == 1) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_CS_fsm == 2) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_CS_fsm == 4)) & \
    ((hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_NS_fsm == 1) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_NS_fsm == 2) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_NS_fsm == 4)) & \
    ((hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_CS_fsm == 1) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_CS_fsm == 2) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_CS_fsm == 4) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_CS_fsm == 8)) & \
    ((hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_NS_fsm == 1) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_NS_fsm == 2) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_NS_fsm == 4) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_NS_fsm == 8)) & \
    ((hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_CS_fsm == 1) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_CS_fsm == 2) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_CS_fsm == 4) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_CS_fsm == 8)) & \
    ((hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_NS_fsm == 1) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_NS_fsm == 2) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_NS_fsm == 4) | \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_NS_fsm == 8)) & \
    ((hls_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 1) | \
     (hls_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 2) | \
     (hls_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 4)) & \
    ((hls_U.hls_target_Loop_1_proc_U0.ap_NS_fsm == 1) | \
     (hls_U.hls_target_Loop_1_proc_U0.ap_NS_fsm == 2) | \
     (hls_U.hls_target_Loop_1_proc_U0.ap_NS_fsm == 4)) \
)} -type {temporary} -update_db;
 
# stream buffer pointer
assume -name {inv - in stream pointer} -env \
{ ( \
    (hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n  == 1 & \
     hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n == 0 & \
     hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.mOutPtr == 3) | \
    (hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n  == 1 & \
     hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n == 1 & \
     hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.mOutPtr == 0) | \
    (hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n  == 0 & \
     hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n == 1 & \
     hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.mOutPtr == 1) \
)} -type {temporary} -update_db;

# iteration interal states 
assume -name {inv = ppiten buf} -env \
{ ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it1 == 1 \
)} -type {temporary} -update_db;

assume -name {inv - Loop fsm} -env \
{ counter == 0 |=> ( \
    hls_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 2 \
)} -type {temporary} -update_db;

assume -name {inv - ppiten Loop} -env \
{ counter == 1 & hls_arg_0_TVALID == 1 |-> ( \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it2 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it3 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it4 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it5 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it6 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it7 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it8 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it9 == 1 \
)} -type {temporary} -update_db;

# axi config
assume -name {inv - axi config} -env \
{ ( \
    hls_U.ap_start == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_areset_d == 0 \
)} -type {temporary} -update_db;

assume -name {inv -axi config init} -env \
{ counter == 0 |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_done_reg == 0 \
)} -type {temporary} -update_db;

# time-out counter
# TODO
assume -name {inv - time out} -env \
{ ( \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.indvar_flatten_reg_61 < 100) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.indvar_flatten_next_fu_78_p2 < 100) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.exitcond_flatten_reg_88 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.indvar_flatten_reg_434 < 100) & \
    (hls_U.hls_target_Loop_1_proc_U0.indvar_flatten_next_fu_473_p2 < 100 ) & \
    (hls_U.hls_target_Loop_1_proc_U0.exitcond_flatten_reg_2790 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it1 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it2 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it3 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it4 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it5 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it6 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it7 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it8 == 0) \
)} -type {temporary} -update_db;

#assume -env \
{ counter == 0 & hls_arg_0_TVALID == 1 |=> ( \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it2 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it3 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it4 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it5 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it6 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it7 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it8 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it9 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 2) \
)} -type {temporary} -update_db;

assume -env \
{ counter == 0 |=> ( \
    #hls_arg_0_TVALID == 0 & \ 
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it2 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it3 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it4 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it5 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it6 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it7 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it8 == 1) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it9 == 0) & \
    (hls_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 2) \
)} -type {temporary} -update_db;

assume -name {tmp - block corner case} -env \
{ counter == 0 |=> ( \
    ila_U.LB2D_proc_x < 100 & \
    ila_U.LB2D_proc_x > 8 & \
    ila_U.LB2D_shift_x < 100 & \
    ila_U.LB2D_shift_x > 8 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.exitcond3_reg_702 == 0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_reg_327 >= 8 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_reg_327 < 100 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_1_reg_693 >= 8 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_1_reg_693 < 100 & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.icmp_reg_698 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.icmp_fu_382_p2) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.icmp_reg_1260 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.icmp_fu_197_p2) & \
    hls_U.hls_target_Loop_1_proc_U0.p_p2_in_bounded_stencil_stream_V_value_V_read == 0 \
)} -type {temporary} -update_db;

assume -name {tmp - inv for corner case} -env \
{ ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.i_0_i_i_reg_152 != 488 |-> \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_CS_fsm == 4 \
)} -type {temporary} -update_db;



