# Assumptions initial condition
#
# arch-states
# data valid must implies iteration done
assume -name {init - valid iterator} -env \
{ counter == 0 |=> ( \
    (hls_arg_0_TVALID == 1 & hls_gb_pp_it_8 == 1) | \
    (hls_arg_0_TVALID == 0) \
)} -type {temporary} -update_db;

# micro-states
# axi config
assume -name {init - axi config} -env \
{ counter == 0 |=> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_done_reg == 0 \
)} -type {temporary} -update_db;

# stable fsm
assume -name {init - stable fsm} -env \
{ counter == 0 |=> ( \
    hls_LB1D_fsm == 2 & \
    hls_LB2D_proc_fsm == 4 & \
    hls_LB2D_shift_fsm == 4 & \
    hls_GB_fsm == 2 \
)} -type {temporary} -update_db;

# consistent exit condition
assume -name {init - consistent exitcond} -env \
{ counter == 0 |=> ( \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.exitcond_flatten_reg_88 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.exitcond_flatten_fu_72_p2) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.exitcond3_fu_388_p2 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.exitcond3_reg_702) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.exitcond21_i_i_reg_1251 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.exitcond21_i_i_fu_175_p2) & \
    (hls_U.hls_target_Loop_1_proc_U0.exitcond_flatten_reg_2790 == \
     hls_U.hls_target_Loop_1_proc_U0.exitcond_flatten_fu_467_p2) \
)} -type {temporary} -update_db;

# consistent valid record
assume -name {init - consistent valid record} -env \
{ counter == 0 |=> ( \
    (hls_arg_0_TVALID == 0 & hls_U.hls_target_Loop_1_proc_U0.arg_0_V_value_V_1_mVld == 0) | \
    (hls_arg_0_TVALID == 1) \
)} -type {temporary} -update_db;

# consistent pixel position
assume -name {init - consistent pixel position} -env \
{ counter == 0 |=> ( \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.icmp_reg_698 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.icmp_fu_382_p2) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.icmp_reg_1260 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.icmp_fu_197_p2) \
)} -type {temporary} -update_db;

# abstract holding buffer - interanl iterator
assume -name {init - no holding iterator} -env \
{ counter == 0 |=> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it1 == 1 \
)} -type {temporary} -update_db;

# valid pipeline iterator 
assume -name {init - cnt vs pp - ila} -env \
{ counter == 0 |=> ( \
    (ila_p_cnt == 0 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 0 & \
                      ila_gb_pp_it_3 == 0 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 1 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 0 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 2 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 3 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 4 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 5 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 6 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 1 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 7 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 1 & \
                      ila_gb_pp_it_8 == 1 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt >= 8 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 1 & \
                      ila_gb_pp_it_8 == 1 & \
                      ila_gb_pp_it_9 == 1) \
)} -type {temporary} -update_db;

# valid pipeline iterator 
assume -name {init - cnt vs exit - ila} -env \
{ counter == 0 |=> ( \
    (ila_p_cnt < 307200 & ila_gb_exit_it_1 == 0 & \
                          ila_gb_exit_it_2 == 0 & \
                          ila_gb_exit_it_3 == 0 & \
                          ila_gb_exit_it_4 == 0 & \
                          ila_gb_exit_it_5 == 0 & \
                          ila_gb_exit_it_6 == 0 & \
                          ila_gb_exit_it_7 == 0 & \
                          ila_gb_exit_it_8 == 0) | \
    (ila_p_cnt == 307200 & ((ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 0 & \
                             ila_gb_exit_it_3 == 0 & \
                             ila_gb_exit_it_4 == 0 & \
                             ila_gb_exit_it_5 == 0 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 0 & \
                             ila_gb_exit_it_4 == 0 & \
                             ila_gb_exit_it_5 == 0 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 0 & \
                             ila_gb_exit_it_5 == 0 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 0 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 1 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 1 & \
                             ila_gb_exit_it_6 == 1 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 1 & \
                             ila_gb_exit_it_6 == 1 & \
                             ila_gb_exit_it_7 == 1 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 1 & \
                             ila_gb_exit_it_6 == 1 & \
                             ila_gb_exit_it_7 == 1 & \
                             ila_gb_exit_it_8 == 1))) \
)} -type {temporary} -update_db;
