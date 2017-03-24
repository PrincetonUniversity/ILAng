# Assumptions initial condition
#
# decompose verification
assume -name {Subset - 1} -env \
{ counter == 0 |=> ( \
    ila_LB1D_p_cnt >= 3904 & ila_LB1D_p_cnt < 315736 & \
    ila_LB2D_proc_x >= 0 & ila_LB2D_proc_x < 480 & \
    ila_LB2D_proc_y >= 8 & ila_LB2D_proc_y < 648 & \
    ila_LB2D_shift_x >= 8 & ila_LB2D_shift_x < 480 & \
    ila_LB2D_shift_y >= 0 & ila_LB2D_shift_y < 640 & \
    ila_gb_p_cnt >= 10 & ila_gb_p_cnt < 306720 \
)} -type {temporary} -update_db;
#
assume -name {Subset - 1.1} -env \
{ counter == 0 |=> ( \
    ila_LB1D_p_cnt >= 4000 & ila_LB1D_p_cnt < 5000 & \
    ila_LB2D_proc_x >= 50 & ila_LB2D_proc_x < 100 & \
    ila_LB2D_proc_y >= 10 & ila_LB2D_proc_y < 20 & \
    ila_LB2D_shift_x >= 50 & ila_LB2D_shift_x < 100 & \
    ila_LB2D_shift_y >= 10 & ila_LB2D_shift_y < 20 & \
    ila_gb_p_cnt >= 4000 & ila_gb_p_cnt < 5000 \
)} -type {temporary} -update_db;

assume -name {Subset - 2} -env \
{ counter == 0 |=> ( \
    ila_LB1D_p_cnt >= 3904 & ila_LB1D_p_cnt < 315736 & \
    ila_LB2D_proc_x >= 480 & ila_LB2D_proc_x <= 488 & \
    ila_LB2D_proc_y >= 8 & ila_LB2D_proc_y < 648 & \
    ila_LB2D_shift_x >= 480 & ila_LB2D_proc_x <= 488 & \
    ila_LB2D_shift_y >= 0 & ila_LB2D_shift_y < 640 & \
    ila_gb_p_cnt >= 450 & ila_gb_p_cnt < 306720 \
)} -type {temporary} -update_db;
#
assume -name {Subset - 2.1} -env \
{ counter == 0 |=> ( \
    ila_LB1D_p_cnt >= 4000 & ila_LB1D_p_cnt < 5000 & \
    ila_LB2D_proc_x >= 480 & ila_LB2D_proc_x <= 488 & \
    ila_LB2D_proc_y >= 10 & ila_LB2D_proc_y < 20 & \
    ila_LB2D_shift_x >= 480 & ila_LB2D_proc_x <= 488 & \
    ila_LB2D_shift_y >= 10  & ila_LB2D_shift_y < 20 & \
    ila_gb_p_cnt >= 4000 & ila_gb_p_cnt < 5000 \
)} -type {temporary} -update_db;

assume -name {Subset - 3} -env \
{ counter == 0 |=> ( \
    ila_LB1D_p_cnt > 0 & ila_LB1D_p_cnt < 3904 & \
    ila_LB2D_proc_x >= 0 & ila_LB2D_proc_x <= 488 & \
    ila_LB2D_proc_y >= 0 & ila_LB2D_proc_y < 8 & \
    ila_LB2D_shift_x == 0 & \
    ila_LB2D_shift_y == 0 & \
    ila_gb_p_cnt == 0 \
)} -type {temporary} -update_db;
#
assume -name {Subset - 3.1} -env \
{ counter == 0 |=> ( \
    ila_LB1D_p_cnt >= 50 & ila_LB1D_p_cnt < 150 & \
    ila_LB2D_proc_x >= 50 & ila_LB2D_proc_x < 100 & \
    ila_LB2D_proc_y == 0 & \
    ila_arg_0_TVALID == 0 & \
    ila_gb_p_cnt == 0 \
)} -type {temporary} -update_db;
#
assume -name {Subset - 4} -env \
{ counter == 0 |=> ( \
    ila_LB1D_p_cnt >= 315736 & ila_LB1D_p_cnt <= 316224 & \
    ila_LB2D_proc_x >= 0 & ila_LB2D_proc_x <= 488 & \
    ila_LB2D_proc_y >= 647 & ila_LB2D_proc_y <= 648 & \
    ila_LB2D_shift_x >= 0 & ila_LB2D_shift_x <= 488 & \
    ila_LB2D_shift_y >= 638 & ila_LB2D_shift_y <= 640 & \
    ila_gb_p_cnt >= 306240 & ila_gb_p_cnt <= 307200 \
    #hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_stream_V_value_V_write == 0 \ 
)} -type {temporary} -update_db;

# arch-states
# data valid must implies iteration done
assume -name {init - valid iterator} -env \
{ counter == 0 |=> ( \
    (hls_arg_0_TVALID == 0) | \
    (hls_arg_0_TVALID == 1 & hls_gb_pp_it_8 == 1 & \
                             hls_U.hls_target_Loop_1_proc_U0.arg_0_V_value_V_1_mVld == 1) \
)} -type {temporary} -update_db;

# no incomplete write to the in stream
#assume -name {init - complete input} -env \
{ counter == 0 |=> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_stream_V_value_V_write == 0 \
)} -type {temporary} -update_db;

assume -name {init - consistent input proc} -env \
{ counter == 0 |=> ( \
    ila_LB1D_in == ila_LB1D_uIn \
)} -type {temporary} -update_db;

# no incomplete read to the stencil stream
assume -name {init - complete output} -env \
{ counter == 0 |=> ( \
    hls_U.hls_target_Loop_1_proc_U0.p_p2_in_bounded_stencil_stream_V_value_V_read == 0 \
)} -type {temporary} -update_db;

# micro-states
# axi config
assume -name {init - axi config} -env \
{ counter == 0 |=> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_done_reg == 0 \
)} -type {temporary} -update_db;

# stable fsm
assume -name {init - stable fsm pre} -env \
{ counter == 0 |=> ( \
    hls_LB1D_fsm == 2 & \
    hls_LB2D_proc_fsm == 4 & \
    hls_LB2D_shift_fsm == 4 & \
    hls_GB_fsm == 2 \
)} -type {temporary} -update_db;
#
assume -name {init - stable fsm post} -env \
{ counter == 0 |-> ( \
    hls_LB2D_shift_fsm == 4 \
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

# consistent ready for write instruction
assume -name {init - consistent input ready} -env \
{ counter == 0 |-> ( \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_last_V_0_has_vld_data_reg_i == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_last_V_0_has_vld_data_reg) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_has_vld_data_reg == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_has_vld_data_reg_i) \
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
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_reg_327 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_1_reg_693) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.icmp_reg_698 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.icmp_fu_382_p2) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.icmp_reg_1260 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.icmp_fu_197_p2) \
)} -type {temporary} -update_db;

# abstract holding buffer - interanl iterator
assume -name {init - processing iterator} -env \
{ counter == 0 |=> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it0 == 1 \
)} -type {temporary} -update_db;
#
assume -name {init - no holding iterator} -env \
{ counter == 0 |=> ( \
    hls_gb_p_cnt != 0 |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it1 == 1 \
    ) \
)} -type {temporary} -update_db;
#
assume -name {init - no holding iterator - buff} -env \
{ counter == 0 |=> ( \
    (hls_LB2D_proc_x != 0 | hls_LB2D_proc_y != 0) |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it1 == 1 \
    ) \
)} -type {temporary} -update_db;

#
assume -name {init - no holding iterator - shift} -env \
{ counter == 0 |=> ( \
    (hls_LB2D_shift_x != 0 | hls_LB2D_shift_y != 0) |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it1 == 1 \
    ) \
)} -type {temporary} -update_db;

# valid pipeline iterator 
assume -name {init - cnt vs pp - ila} -env \
{ counter == 0 |=> ( \
    (ila_gb_p_cnt == 0 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 0 & \
                      ila_gb_pp_it_3 == 0 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_gb_p_cnt == 1 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 0 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_gb_p_cnt == 2 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_gb_p_cnt == 3 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_gb_p_cnt == 4 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_gb_p_cnt == 5 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_gb_p_cnt == 6 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 1 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_gb_p_cnt == 7 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 1 & \
                      ila_gb_pp_it_8 == 1 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_gb_p_cnt >= 8 & ila_gb_pp_it_1 == 1 & \
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
    (ila_gb_p_cnt < 307200 & ila_gb_exit_it_1 == 0 & \
                          ila_gb_exit_it_2 == 0 & \
                          ila_gb_exit_it_3 == 0 & \
                          ila_gb_exit_it_4 == 0 & \
                          ila_gb_exit_it_5 == 0 & \
                          ila_gb_exit_it_6 == 0 & \
                          ila_gb_exit_it_7 == 0 & \
                          ila_gb_exit_it_8 == 0) | \
    (ila_gb_p_cnt == 307200 & ((ila_gb_exit_it_1 == 1 & \
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
