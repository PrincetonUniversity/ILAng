# Assumptions for proving read instruction -- HLS
#
# initial state for read instruction -- HLS.
assume -name {:read instr HLS init} -env \
{(cnt_init == 1) |-> ( \
    # input
    arg_0_TREADY == 1       & \
    arg_1_TDATA == 0        & \
    arg_1_TVALID == 0       & \
    # states
    hls_arg_0_TDATA == 0    & \
    hls_arg_0_TLAST == 0    & \
    hls_arg_1_TLAST == 0    & \
    hls_arg_1_TREADY == 0   & \
    hls_arg_0_TVALID == 0
)} -type {temporary} -update_db;

# invariant state for read instruction -- HLS.
assume -name {:read instr HLS invariant} -env \
{ \
    rst == 0            & \
    arg_1_TVALID == 0   & \
    arg_0_TREADY == 1   \
} -type {temporary} -update_db;

# terminating condition -- HLS
assume -name {:read instr HLS terminate} -env \
{ \
    (hls_target_U.hls_target_Loop_1_proc_U0.ap_ready == 1) |-> (hls_step == 0) \
} -type {temporary} -update_db;
