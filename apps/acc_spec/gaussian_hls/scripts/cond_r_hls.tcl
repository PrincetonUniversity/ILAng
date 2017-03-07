# Assumptions for proving read instruction -- HLS
#
# initial state for read instruction -- HLS.
assume -name {HLS init start} -env \
{ (counter < 5) |-> (hls_exec == 0) \
} -type {temporary} -update_db;

assume -name {HLS init stop} -env \
{ (counter >= 5) |-> (hls_exec == 1) \
} -type {temporary} -update_db;

# execution -- HLS
assume -name {HLS start} -env \
{ (hls_exec == 0) |=> (hls_complete == 0) \
} -type {temporary} -update_db;

# terminating condition -- HLS
assume -name {HLS continue} -env \
{ (hls_exec == 1) |-> ( \
    (hls_target_U.arg_0_TVALID == 1) |=> (hls_complete == 0) \
) } -type {temporary} -update_db;

assume -name {HLS break} -env \
{ (hls_exec == 1) |-> ( \
    (hls_target_U.arg_0_TVALID == 0) |=> (hls_complete == 1) \
) } -type {temporary} -update_db;

# initialize micro-architecture states in HLS implementation.
# hls_target_Loop_1_proc_U0
# hls_target_linebuffer_1_U0
