# Assumptions for refining initial condition by blocking unreachable states
#
# arch states
assume -name {inv - stream buffer status} -env \
{ ( \
    ~(ila_U.in_stream_full == 1 & ila_U.in_stream_empty == 1) & \
    ~(ila_U.slice_stream_full == 1 & ila_U.slice_stream_empty == 1) & \
    ~(ila_U.stencil_stream_full == 1 & ila_U.stencil_stream_empty == 1) & \
    ~(hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n == 0 & \
      hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n == 0) & \
    ~(hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_full_n == 0 & \
     hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_empty_n == 0) & \
    ~(hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n == 0 & \
      hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n == 0) \
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
