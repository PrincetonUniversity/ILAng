# Assumptions for refining initial condition by blocking unreachable states
#
# alias
assume -name {inv - alias} -env \
{ ( \
    hls_LB1D_in == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_data_out & \
    hls_LB1D_buff == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.empty_18_reg_97_0 & \
    hls_LB1D_it_1 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 & \
    hls_LB1D_p_cnt == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.indvar_flatten_reg_61 & \
    hls_in_stream_empty == ~hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n & \
    hls_in_stream_full == ~hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n & \
    hls_in_stream_buff_0 == hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.U_FIFO_hls_target_linebuffer_1_in_stream_V_value_V_ram.SRL_SIG[0] & \
    hls_in_stream_buff_1 == hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.U_FIFO_hls_target_linebuffer_1_in_stream_V_value_V_ram.SRL_SIG[1] & \
    hls_LB2D_proc_x == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.col_reg_349 & \
    hls_LB2D_proc_y == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.row_1_reg_693 & \
    hls_LB2D_proc_w == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.write_idx_1_1_reg_338 & \
    hls_LB2D_proc_0 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_0_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram & \
    hls_LB2D_proc_1 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_1_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram & \
    hls_LB2D_proc_2 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_2_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram & \
    hls_LB2D_proc_3 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_3_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram & \
    hls_LB2D_proc_4 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_4_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram & \
    hls_LB2D_proc_5 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_5_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram & \
    hls_LB2D_proc_6 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_6_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram & \
    hls_LB2D_proc_7 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.buffer_7_value_V_U.hls_target_call_Loop_LB2D_buf_proc_buffer_0_value_V_ram_U.ram & \
    hls_slice_stream_empty == ~hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_empty_n & \
    hls_slice_stream_full == ~hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_full_n & \
    hls_slice_stream_buff_0 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.U_FIFO_hls_target_call_slice_stream_V_value_V_ram.SRL_SIG[0] & \
    hls_slice_stream_buff_1 == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.U_FIFO_hls_target_call_slice_stream_V_value_V_ram.SRL_SIG[1] & \
    hls_LB2D_shift_x == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.i_0_i_i_reg_152 & \
    hls_LB2D_shift_y == \
        hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.n1_reg_141 & \
    hls_LB2D_shift_0 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.buffer_0_value_V_fu_100 & \
    hls_LB2D_shift_1 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.buffer_1_value_V_fu_104 & \
    hls_LB2D_shift_2 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.buffer_2_value_V_fu_108 & \
    hls_LB2D_shift_3 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.buffer_3_value_V_fu_112 & \
    hls_LB2D_shift_4 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.buffer_4_value_V_fu_116 & \
    hls_LB2D_shift_5 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.buffer_5_value_V_fu_120 & \
    hls_LB2D_shift_6 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.buffer_6_value_V_fu_124 & \
    hls_LB2D_shift_7 == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.buffer_7_value_V_fu_96 & \
    hls_stencil_stream_empty == ~hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n & \
    hls_stencil_stream_full == ~hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n & \
    hls_stencil_stream_buff_0 == hls_U.p_p2_in_bounded_stencil_stream_s_U.U_FIFO_hls_target_p_p2_in_bounded_stencil_stream_s_ram.SRL_SIG[0] & \
    hls_stencil_stream_buff_1 == hls_U.p_p2_in_bounded_stencil_stream_s_U.U_FIFO_hls_target_p_p2_in_bounded_stencil_stream_s_ram.SRL_SIG[1] & \
    hls_gb_p_cnt == hls_U.hls_target_Loop_1_proc_U0.indvar_flatten_reg_434 & \
    hls_gb_pp_it_1 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 & \
    hls_gb_pp_it_2 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it2 & \
    hls_gb_pp_it_3 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it3 & \
    hls_gb_pp_it_4 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it4 & \
    hls_gb_pp_it_5 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it5 & \
    hls_gb_pp_it_6 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it6 & \
    hls_gb_pp_it_7 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it7 & \
    hls_gb_pp_it_8 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it8 & \
    hls_gb_pp_it_9 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it9 & \
    hls_gb_exit_it_1 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it1 & \
    hls_gb_exit_it_2 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it2 & \
    hls_gb_exit_it_3 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it3 & \
    hls_gb_exit_it_4 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it4 & \
    hls_gb_exit_it_5 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it5 & \
    hls_gb_exit_it_6 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it6 & \
    hls_gb_exit_it_7 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it7 & \
    hls_gb_exit_it_8 == hls_U.hls_target_Loop_1_proc_U0.ap_reg_ppstg_exitcond_flatten_reg_2790_pp0_it8 & \
    hls_LB1D_fsm == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_CS_fsm & \
    hls_LB1D_fsm_nxt == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_NS_fsm & \
    hls_LB2D_proc_fsm == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_CS_fsm & \
    hls_LB2D_proc_fsm_nxt == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_buf_proc_U0.ap_NS_fsm & \
    hls_LB2D_shift_fsm == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_CS_fsm & \
    hls_LB2D_shift_fsm_nxt == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.hls_target_call_Loop_LB2D_shift_proc_U0.ap_NS_fsm & \
    hls_GB_fsm == hls_U.hls_target_Loop_1_proc_U0.ap_CS_fsm & \
    hls_GB_fsm_nxt == hls_U.hls_target_Loop_1_proc_U0.ap_NS_fsm & \
    hls_in_stream_mOutPtr == hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.mOutPtr & \
    hls_slice_stream_mOutPtr == hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.mOutPtr & \
    hls_stencil_stream_mOutPtr == hls_U.p_p2_in_bounded_stencil_stream_s_U.mOutPtr \
)} -type {temporary} -update_db;

# arch states
# buffer status: should not be full and empty at the same time
assume -name {inv - stream buffer status} -env \
{ ( \
    ~(hls_in_stream_full == 1 & hls_in_stream_empty == 1) & \
    ~(hls_slice_stream_full == 1 & hls_slice_stream_empty == 1) & \
    ~(hls_stencil_stream_full == 1 & hls_stencil_stream_empty == 1) \
)} -type {temporary} -update_db;

# x/y/w index: should fall in valid range
assume -name {inv - index bound} -env \
{ ( \
    ila_RAM_x >= 0 & ila_RAM_x <= 488 & \
    ila_RAM_y >= 0 & ila_RAM_y <= 648 & \
    ila_RAM_w >= 0 & ila_RAM_w < 8 & \
    hls_LB1D_p_cnt >= 0 & hls_LB1D_p_cnt <= 316224 & \
    hls_LB2D_proc_x >= 0 & hls_LB2D_proc_x <= 488 & \
    hls_LB2D_proc_y >= 0 & hls_LB2D_proc_y <= 648 & \
    hls_LB2D_proc_w >= 0 & hls_LB2D_proc_w < 8 & \
    hls_LB2D_shift_x >= 0 & hls_LB2D_shift_x <= 488 & \
    hls_LB2D_shift_y >= 0 & hls_LB2D_shift_y <= 640 & \
    hls_gb_p_cnt >= 0 & hls_gb_p_cnt <= 307200 \
)} -type {temporary} -update_db;

# micro-arch states
# internal fsm state encoding
assume -name {inv - valid fsm} -env \
{ ( \
    ((hls_LB1D_fsm == 1) | (hls_LB1D_fsm == 2) | (hls_LB1D_fsm == 4)) & \
    ((hls_LB2D_proc_fsm == 1) | (hls_LB2D_proc_fsm == 2) | (hls_LB2D_proc_fsm == 4) | (hls_LB2D_proc_fsm == 8)) & \
    ((hls_LB2D_shift_fsm == 1) | (hls_LB2D_shift_fsm == 2) | (hls_LB2D_shift_fsm == 4) | (hls_LB2D_shift_fsm == 8)) & \
    ((hls_GB_fsm == 1) | (hls_GB_fsm == 2) | (hls_GB_fsm == 4)) & \
    ((hls_LB1D_fsm_nxt == 1) | (hls_LB1D_fsm_nxt == 2) | (hls_LB1D_fsm_nxt == 4)) & \
    ((hls_LB2D_proc_fsm_nxt == 1) | (hls_LB2D_proc_fsm_nxt == 2) | (hls_LB2D_proc_fsm_nxt == 4) | (hls_LB2D_proc_fsm_nxt == 8)) & \
    ((hls_LB2D_shift_fsm_nxt == 1) | (hls_LB2D_shift_fsm_nxt == 2) | (hls_LB2D_shift_fsm_nxt == 4) | (hls_LB2D_shift_fsm_nxt == 8)) & \
    ((hls_GB_fsm_nxt == 1) | (hls_GB_fsm_nxt == 2) | (hls_GB_fsm_nxt == 4)) \
)} -type {temporary} -update_db;
 
# stream buffer pointer
assume -name {inv - valid in stream pointer} -env \
{ ( \
    (hls_in_stream_full == 0 & hls_in_stream_empty == 1 & hls_in_stream_mOutPtr == 3) | \
    (hls_in_stream_full == 0 & hls_in_stream_empty == 0 & hls_in_stream_mOutPtr == 0) | \
    (hls_in_stream_full == 1 & hls_in_stream_empty == 0 & hls_in_stream_mOutPtr == 1) \
)} -type {temporary} -update_db;
#
assume -name {inv - valid slice stream pointer} -env \
{ ( \
    (hls_slice_stream_full == 0 & hls_slice_stream_empty == 1 & hls_slice_stream_mOutPtr == 3) | \
    (hls_slice_stream_full == 0 & hls_slice_stream_empty == 0 & hls_slice_stream_mOutPtr == 0) | \
    (hls_slice_stream_full == 1 & hls_slice_stream_empty == 0 & hls_slice_stream_mOutPtr == 1) \
)} -type {temporary} -update_db;
#
assume -name {inv - valid stencil stream pointer} -env \
{ ( \
    (hls_stencil_stream_full == 0 & hls_stencil_stream_empty == 1 & hls_stencil_stream_mOutPtr == 3) | \
    (hls_stencil_stream_full == 0 & hls_stencil_stream_empty == 0 & hls_stencil_stream_mOutPtr == 0) | \
    (hls_stencil_stream_full == 1 & hls_stencil_stream_empty == 0 & hls_stencil_stream_mOutPtr == 1) \
)} -type {temporary} -update_db;

# axi config
assume -name {inv - axi config} -env \
{ ( \
    hls_U.ap_start == 1 & \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.in_axi_stream_V_value_V_0_areset_d == 0 \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 0} -env \
{ ( \
    (ila_gbit == 0 & \
     hls_gb_exit_it_1 == 0 & \
     hls_gb_exit_it_2 == 0 & \
     hls_gb_exit_it_3 == 0 & \
     hls_gb_exit_it_4 == 0 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) |-> \
     ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 1} -env \
{ ( \
    (ila_gbit == 1 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 0 & \
     hls_gb_exit_it_3 == 0 & \
     hls_gb_exit_it_4 == 0 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) |-> \
     ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 2} -env \
{ ( \
    (ila_gbit == 2 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 0 & \
     hls_gb_exit_it_4 == 0 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) |-> \
     ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 3} -env \
{ ( \
    (ila_gbit == 3 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 0 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) |-> \
     ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 4} -env \
{ ( \
    (ila_gbit == 4 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) |-> \
     ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 5} -env \
{ ( \
    (ila_gbit == 5 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 1 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) |-> \
     ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 6} -env \
{ ( \
    (ila_gbit == 6 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 1 & \
     hls_gb_exit_it_6 == 1 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) |-> \
     ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 7} -env \
{ ( \
    (ila_gbit == 7 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 1 & \
     hls_gb_exit_it_6 == 1 & \
     hls_gb_exit_it_7 == 1 & \
     hls_gb_exit_it_8 == 0) |-> \
     ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -type {temporary} -update_db;

