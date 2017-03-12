# Assumptions for proving write instruction 
# Execute: start and stop models
#
# start
assume -name {start model} -env \
{ counter <= 2 |-> ( \
    hls_complete == 0 & \
    ila_complete == 0 \
)} -type {temporary} -update_db;

# stop
assume -name {exec ila - continue} -env \
{ (counter > 1) |-> ( \
    ( \
    ((ila_U.in_stream_full == 0) & (ila_U.arg_1_TREADY == 0)) | \
    ((ila_U.slice_stream_full == 0) & (ila_U.in_stream_empty == 0)) | \
    ((ila_U.stencil_stream_full == 0) & (ila_U.slice_stream_empty == 0)) | \
    ((ila_U.arg_0_TVALID == 0) & (ila_U.stencil_stream_empty == 0)) 
    ) \
    |=> \
    (ila_complete == 0) \
)} -type {temporary} -update_db;
# 
assume -name {exec ila - break} -env \
{ (counter > 1) |-> ( \
    ~( \
    ((ila_U.in_stream_full == 0) & (ila_U.arg_1_TREADY == 0)) | \
    ((ila_U.slice_stream_full == 0) & (ila_U.in_stream_empty == 0)) | \
    ((ila_U.stencil_stream_full == 0) & (ila_U.slice_stream_empty == 0)) | \
    ((ila_U.arg_0_TVALID == 0) & (ila_U.stencil_stream_empty == 0)) 
    ) \
    |=> \
    (ila_complete == 1) \
)} -type {temporary} -update_db;
#
assume -name {exec hls - continue} -env \
{ (counter > 1) |-> ( \
    ( \
    ((hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n == 1) & \
     (hls_U.arg_1_TREADY == 0)) | \
    ((hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_full_n == 1) & \
     (hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n == 1)) | \
    ((hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n == 1) & \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_empty_n == 1)) | \
    ((hls_U.arg_0_TVALID == 0) & \
     (hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n == 1)) \
    ) \
    |=> \
    (hls_complete == 0) \
)} -type {temporary} -update_db;
#
assume -name {exec hls - break} -env \
{ (counter > 1) |-> ( \
    ~( \
    ((hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n == 1) & \
     (hls_U.arg_1_TREADY == 0)) | \
    ((hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_full_n == 1) & \
     (hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n == 1)) | \
    ((hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n == 1) & \
     (hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_U0.hls_target_call_U0.slice_stream_V_value_V_U.internal_empty_n == 1)) | \
    ((hls_U.arg_0_TVALID == 0) & \
     (hls_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n == 1)) \
    ) \
    |=> \
    (hls_complete == 1) \
)} -type {temporary} -update_db;
