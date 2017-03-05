# Assumptions for proving read instruction -- HLS
#
# initial state for read instruction -- HLS.
assume -name {read instr HLS init} -env \
{(cnt_init == 0) |=> ( \
    hls_complete == 0 \
    # input
    & arg_0_TREADY == 1 \
    # arg_1_TDATA
    & arg_1_TVALID == 0 \
    # states
    & hls_arg_0_TVALID == 0 \
    & hls_target_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n == 1 \
    & hls_target_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n == 1 \
    #& hls_target_U.hls_target_Loop_1_proc_U0.p_p2_in_bounded_stencil_stream_V_value_V_empty_n == 1 \ 
    & hls_target_U.hls_target_Loop_1_proc_U0.ap_start == 1 \
    # hls_arg_0_TDATA, hls_arg_0_TLAST, hls_arg_1_TLAST, hls_arg_1_TREADY
    # LB2D buff, x/y/w index, stencil buff, slice buff, slice full
)} -type {temporary} -update_db;

# invariant state for read instruction -- HLS.
assume -name {read instr HLS invariant} -env \
{ \
    rst == 0 \
    & arg_1_TVALID == 0 \
    & arg_0_TREADY == 1 \
} -type {temporary} -update_db;

# terminating condition -- HLS
assume -name {read instr HLS continue} -env \
{ (cnt_init == 1) |-> ( \
    ((hls_arg_0_TVALID == 1) & \
     (hls_target_U.hls_target_Loop_1_proc_U0.p_p2_in_bounded_stencil_stream_V_value_V_read == 0)) \
     |=> (hls_complete == 1) \
)} -type {temporary} -update_db;

assume -name {read instr HLS break} -env \
{ (cnt_init == 1) |-> ( \
   ((hls_arg_0_TVALID == 0) | \
    (hls_target_U.hls_target_Loop_1_proc_U0.p_p2_in_bounded_stencil_stream_V_value_V_read == 1)) \
     |=> (hls_complete == 0) \
)} -type {temporary} -update_db;

# initialize micro-architecture states in HLS implementation.
# ap_ST_st1_fsm_0 == 1
assume -name {read instr HLS micro-init} -env \
{ (cnt_init == 0) |=> ( \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_done_reg == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it2 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it3 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it4 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it5 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it6 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it7 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it8 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it9 == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.arg_0_V_last_V_1_mVld == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.arg_0_V_value_V_1_mVld == 0 & \
    hls_target_U.hls_target_Loop_1_proc_U0.p_p2_in_bounded_stencil_stream_V_value_V_read == 0 \
    # indvar_flatten_reg_434
    # p_hw_output_1_x_scan_dim_0_reg_456
    # p_hw_output_1_y_scan_dim_0_reg_445
    # ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it1
    # ap_reg_ppstg_tmp_last_V_reg_2804_pp0_it1
    # exitcond_flatten_reg_2790
    # others
)} -update_db;
