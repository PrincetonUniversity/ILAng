# Assumptions initial condition
#
# decompose verification
assume -name {Subset - A} -env \
{ counter == 5 |-> ( \
    hls_LB1D_p_cnt == 0 & \
    hls_LB1D_it_1 == 0 & \
    hls_in_stream_empty == 1 & hls_in_stream_full == 0 & \
    hls_LB2D_proc_x == 0 & \
    hls_LB2D_proc_y == 0 & \
    hls_slice_stream_empty == 1 & hls_slice_stream_full == 0 & \
    hls_LB2D_shift_x == 0 & \
    hls_LB2D_shift_y == 0 & \
    hls_stencil_stream_empty == 1 & hls_stencil_stream_full == 0 & \
    hls_gb_p_cnt == 0 \
)} -type {temporary} -update_db;
#
assume -name {Subset - B} -env \
{ counter == 5 |-> ( \
    hls_LB1D_p_cnt > 0    & hls_LB1D_p_cnt < 3904 & \
    hls_LB1D_it_1 == 1    & \
    hls_LB2D_proc_x > 0   & hls_LB2D_proc_x <= 488 & \
    hls_LB2D_proc_y >= 0  & hls_LB2D_proc_y < 8 & \
    hls_slice_stream_empty == 1 & hls_slice_stream_full == 0 & \
    hls_LB2D_shift_x == 0 & \
    hls_LB2D_shift_y == 0 & \
    hls_stencil_stream_empty == 1 & hls_stencil_stream_full == 0 & \
    hls_gb_p_cnt == 0 \
)} -type {temporary} -update_db;
#
assume -name {Subset - C1} -env \
{ counter == 5 |-> ( \
    ila_LB1D_p_cnt >= 3904 & ila_LB1D_p_cnt < 315736 & \
    ila_LB2D_proc_x > 0    & ila_LB2D_proc_x < 480 & \
    ila_LB2D_proc_y >= 8   & ila_LB2D_proc_y < 648 & \
    ila_LB2D_shift_x >= 8  & ila_LB2D_shift_x < 480 & \
    ila_LB2D_shift_y >= 0  & ila_LB2D_shift_y < 640 & \
    ila_gb_p_cnt >= 10     & ila_gb_p_cnt < 306720 \
)} -type {temporary} -update_db;
#
assume -name {Subset - C2} -env \
{ counter == 5 |-> ( \
    ila_LB1D_p_cnt >= 3904  & ila_LB1D_p_cnt < 315736 & \
    ila_LB2D_proc_x > 0     & ila_LB2D_proc_x <= 488 & \
    ila_LB2D_proc_y >= 8    & ila_LB2D_proc_y < 648 & \
    ila_LB2D_shift_x > 0    & ila_LB2D_shift_x <= 488 & \
    ila_LB2D_shift_y >= 0   & ila_LB2D_shift_y < 640 & \
    ila_gb_p_cnt >= 450     & ila_gb_p_cnt < 306720 \
)} -type {temporary} -update_db;
#
assume -name {Subset - D} -env \
{ counter == 5 |-> ( \
    hls_LB1D_p_cnt >= 315736 & hls_LB1D_p_cnt <= 316222 & \
    hls_LB2D_proc_x > 0      & hls_LB2D_proc_x <= 488 & \
    hls_LB2D_proc_y >= 647   & hls_LB2D_proc_y <= 647 & \
    hls_LB2D_shift_x > 0     & hls_LB2D_shift_x <= 488 & \
    hls_LB2D_shift_y >= 639  & hls_LB2D_shift_y <= 639 & \
    hls_gb_p_cnt >= 306240   & hls_gb_p_cnt < 307200 & \
    ~(hls_LB2D_proc_x >= 486 & hls_LB2D_proc_y == 647) \
)} -type {temporary} -update_db;
#
assume -name {Subset - E} -env \
{ counter == 5 |-> ( \
    hls_LB1D_p_cnt == 316223 & \
    hls_LB2D_proc_x == 486 & \
    hls_LB2D_proc_y == 647 & \
    hls_LB2D_shift_x == 486 & \
    hls_LB2D_shift_y == 639 & \
    hls_gb_p_cnt == 307199 \
)} -type {temporary} -update_db;

assume -name {Subset - all} -env \
{ counter == 5 |-> ( \
    ( \
    hls_LB1D_p_cnt == 0 & \
    hls_LB1D_it_1 == 0 & \
    hls_in_stream_empty == 1 & hls_in_stream_full == 0 & \
    hls_LB2D_proc_x == 0 & \
    hls_LB2D_proc_y == 0 & \
    hls_slice_stream_empty == 1 & hls_slice_stream_full == 0 & \
    hls_LB2D_shift_x == 0 & \
    hls_LB2D_shift_y == 0 & \
    hls_stencil_stream_empty == 1 & hls_stencil_stream_full == 0 & \
    hls_gb_p_cnt == 0 \
    ) | \
    ( \
    hls_LB1D_p_cnt > 0    & hls_LB1D_p_cnt < 3904 & \
    hls_LB1D_it_1 == 1    & \
    hls_LB2D_proc_x > 0   & hls_LB2D_proc_x <= 488 & \
    hls_LB2D_proc_y >= 0  & hls_LB2D_proc_y < 8 & \
    hls_slice_stream_empty == 1 & hls_slice_stream_full == 0 & \
    hls_LB2D_shift_x == 0 & \
    hls_LB2D_shift_y == 0 & \
    hls_stencil_stream_empty == 1 & hls_stencil_stream_full == 0 & \
    hls_gb_p_cnt == 0 \
    ) | \
    ( \
    ila_LB1D_p_cnt >= 3904 & ila_LB1D_p_cnt < 315736 & \
    ila_LB2D_proc_x > 0    & ila_LB2D_proc_x < 480 & \
    ila_LB2D_proc_y >= 8   & ila_LB2D_proc_y < 648 & \
    ila_LB2D_shift_x >= 8  & ila_LB2D_shift_x < 480 & \
    ila_LB2D_shift_y >= 0  & ila_LB2D_shift_y < 640 & \
    ila_gb_p_cnt >= 10     & ila_gb_p_cnt < 306720 \
    ) | \
    ( \
    ila_LB1D_p_cnt >= 3904  & ila_LB1D_p_cnt < 315736 & \
    ila_LB2D_proc_x > 0     & ila_LB2D_proc_x <= 488 & \
    ila_LB2D_proc_y >= 8    & ila_LB2D_proc_y < 648 & \
    ila_LB2D_shift_x > 0    & ila_LB2D_shift_x <= 488 & \
    ila_LB2D_shift_y >= 0   & ila_LB2D_shift_y < 640 & \
    ila_gb_p_cnt >= 450     & ila_gb_p_cnt < 306720 \
    ) | \
    ( \
    hls_LB1D_p_cnt >= 315736 & hls_LB1D_p_cnt <= 316222 & \
    hls_LB2D_proc_x > 0      & hls_LB2D_proc_x <= 488 & \
    hls_LB2D_proc_y >= 647   & hls_LB2D_proc_y <= 647 & \
    hls_LB2D_shift_x > 0     & hls_LB2D_shift_x <= 488 & \
    hls_LB2D_shift_y >= 639  & hls_LB2D_shift_y <= 639 & \
    hls_gb_p_cnt >= 306240   & hls_gb_p_cnt < 307200 & \
    ~(hls_LB2D_proc_x >= 486 & hls_LB2D_proc_y == 647) \
    ) | \
    ( \
    hls_LB1D_p_cnt == 316223 & \
    hls_LB2D_proc_x == 486 & \
    hls_LB2D_proc_y == 647 & \
    hls_LB2D_shift_x == 486 & \
    hls_LB2D_shift_y == 639 & \
    hls_gb_p_cnt == 307199 \
    ) \
)} -type {temporary} -update_db;

# arch-states
assume -name {init - flush ila} -env \
{ counter < 5 |-> ( \
   ~( \
    ((ila_arg_1_TREADY == 0) & (ila_in_stream_full == 0)) | \
    ((ila_in_stream_empty == 0) & \
        ((ila_slice_stream_full == 0) | (ila_LB2D_proc_y < 8))) | \
    ((ila_slice_stream_empty == 0) & \
        ((ila_stencil_stream_full == 0) | (ila_LB2D_shift_x < 8))) | \
    ((ila_arg_0_TVALID == 0) & \
        (((ila_gb_exit_it_1 == 0) & (ila_stencil_stream_empty == 0)) | \
        ((ila_gb_exit_it_1 == 1) & (ila_gb_exit_it_8 == 0)))) \
    ) \
)} -type {temporary} -update_db;

assume -name {init - flush hls} -env \
{ counter < 5 |-> ( \
   ~( \
    ((hls_arg_1_TREADY == 0) & (hls_in_stream_full == 0)) | \
    ((hls_in_stream_empty == 0) & \
        ((hls_slice_stream_full == 0) | (hls_LB2D_proc_y < 8))) | \
    ((hls_slice_stream_empty == 0) & \
        ((hls_stencil_stream_full == 0) | (hls_LB2D_shift_x < 8))) | \
    ((hls_arg_0_TVALID == 0) & \
        (((hls_gb_exit_it_1 == 0) & (hls_stencil_stream_empty == 0)) | \
         ((hls_gb_exit_it_1 == 1) & (hls_gb_exit_it_8 == 0)))) \
    ) \
    & hls_arg_1_TREADY == 1 \
)} -type {temporary} -update_db;

    
# data valid must implies iteration done
assume -name {init - valid iterator} -env \
{ counter == 5 |-> ( \
    (hls_arg_0_TVALID == 0) | \
    (hls_arg_0_TVALID == 1 & hls_gb_pp_it_8 == 1 & \
                             hls_U.hls_target_Loop_1_proc_U0.arg_0_V_value_V_1_mVld == 1) \
)} -type {temporary} -update_db;

assume -name {init - consistent input buffer} -env \
{ counter == 5 |-> ( \
    ila_LB1D_in == ila_LB1D_buff & \
    ila_LB1D_in == ila_LB1D_uIn \
)} -type {temporary} -update_db;

# axi config
assume -name {init - axi config} -env \
{ counter == 5 |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_done_reg == 0 \
)} -type {temporary} -update_db;

# stable fsm
assume -name {init - stable fsm pre} -env \
{ counter == 5 |-> ( \
    hls_LB1D_fsm == 2 & \
    hls_LB2D_proc_fsm == 4 & \
    hls_LB2D_shift_fsm == 4 & \
    hls_GB_fsm == 2 \
)} -type {temporary} -update_db;
#
assume -name {init - stable fsm post} -env \
{ counter == 4 |-> ( \
    hls_LB2D_shift_fsm == 4 \
)} -type {temporary} -update_db;

# input holding
assume -name {init - input processing unit iterator} -env \
{ (counter == 5 & hls_LB1D_p_cnt > 0) |-> ( \
    hls_LB1D_it_1 == 1 \
)} -type {temporary} -update_db;

# consistent write index
assume -name {init - consistent proc_w} -env \
{ counter == 5 |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.p_write_idx_1_1_reg_723 == \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.write_idx_1_reg_315 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.write_idx_1_reg_315 == \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.write_idx_1_1_reg_338 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.tmp_13_reg_780 == \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.tmp_13_fu_446_p1 \
)} -type {temporary} -update_db;

# consistent exit condition
assume -name {init - consistent exitcond in} -env \
{ counter == 5 |-> ( \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.exitcond_flatten_reg_88 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.exitcond_flatten_fu_72_p2) \
)} -type {temporary} -update_db;
#
assume -name {init - consistent exitcond buff} -env \
{ counter == 5 |-> ( \
    (hls_LB2D_proc_x == 488 & \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.exitcond3_reg_702 == 0) | \
    (hls_LB2D_proc_x != 488 & \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.exitcond3_fu_388_p2 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.exitcond3_reg_702) \
)} -type {temporary} -update_db;
#
assume -name {init - consistent exitcond shift} -env \
{ counter == 5 |-> ( \
    (hls_LB2D_shift_x == 488 & \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.exitcond21_i_i_reg_1251 == 0) | \
    (hls_LB2D_shift_x != 488 & \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.exitcond21_i_i_reg_1251 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.exitcond21_i_i_fu_175_p2) \
)} -type {temporary} -update_db;
#
assume -name {init - consistent exitcond GB} -env \
{ counter == 5 |-> ( \
    (hls_U.hls_target_Loop_1_proc_U0.exitcond_flatten_reg_2790 == \
     hls_U.hls_target_Loop_1_proc_U0.exitcond_flatten_fu_467_p2) \
)} -type {temporary} -update_db;

# consistent ready for write instruction
assume -name {init - consistent input ready} -env \
{ counter == 5 |-> ( \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_last_V_0_has_vld_data_reg_i == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_last_V_0_has_vld_data_reg) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_has_vld_data_reg == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_has_vld_data_reg_i) \
)} -type {temporary} -update_db;

# consistent valid record
assume -name {init - consistent valid record} -env \
{ counter == 5 |-> ( \
    (hls_arg_0_TVALID == 0 & hls_U.hls_target_Loop_1_proc_U0.arg_0_V_value_V_1_mVld == 0) | \
    (hls_arg_0_TVALID == 1) \
)} -type {temporary} -update_db;

# consistent pixel position
assume -name {init - consistent pixel position} -env \
{ counter == 5 |-> ( \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_reg_327 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_1_reg_693) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.icmp_reg_698 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.icmp_fu_382_p2) & \
    (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.icmp_reg_1260 == \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.icmp_fu_197_p2) \
)} -type {temporary} -update_db;

# consistent RAM row select
assume -name {init - consistent RAM select} -env \
{ counter == 5 |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.tmp_12_reg_728 == \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.tmp_12_fu_442_p1 \
)} -type {temporary} -update_db;

assume -name {init - consistent RAM RW} -env \
{ (counter == 5 & hls_LB2D_proc_x != 0) |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.col_cast_reg_711 == \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.col_cast_fu_400_p1 - 1 \
)} -type {temporary} -update_db;

# consistent RAM read port
assume -name {init - consistent RAM access} -env \
{ counter == 4 |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_0_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram[hls_LB2D_proc_x-1] == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_0_value_V_q0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_1_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram[hls_LB2D_proc_x-1] == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_1_value_V_q0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_2_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram[hls_LB2D_proc_x-1] == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_2_value_V_q0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_3_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram[hls_LB2D_proc_x-1] == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_3_value_V_q0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_4_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram[hls_LB2D_proc_x-1] == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_4_value_V_q0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_5_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram[hls_LB2D_proc_x-1] == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_5_value_V_q0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_6_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram[hls_LB2D_proc_x-1] == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_6_value_V_q0 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_7_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram[hls_LB2D_proc_x-1] == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_7_value_V_q0 \
)} -type {temporary} -update_db;

# abstract holding buffer - interanl iterator
assume -name {init - processing iterator} -env \
{ counter == 5 |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 \
)} -type {temporary} -update_db;
#
assume -name {init - no holding iterator} -env \
{ counter == 5 |-> ( \
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
{ counter == 5 |-> ( \
    (hls_LB2D_proc_x != 0 | hls_LB2D_proc_y != 0) |-> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_reg_ppiten_pp0_it1 == 1 \
    ) \
)} -type {temporary} -update_db;

#
assume -name {init - no holding iterator - shift} -env \
{ counter == 5 |-> ( \
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
{ counter == 5 |-> ( \
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
{ counter == 5 |-> ( \
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
