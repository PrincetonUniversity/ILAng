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
    & hls_arg_0_TVALID == 0    \
    & hls_target_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n == 0 \
    & hls_target_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n == 0 \
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
    (hls_arg_0_TVALID == 1) |=> (hls_complete == 1) \
)} -type {temporary} -update_db;

assume -name {read instr HLS break} -env \
{ (cnt_init == 1) |-> ( \
    (hls_arg_0_TVALID == 0) |=> (hls_complete == 0) \
)} -type {temporary} -update_db;
