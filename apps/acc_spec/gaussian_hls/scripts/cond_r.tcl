# Assumptions for proving read instruction -- common architecture states
#
# decode -- arg_1_TVALID & arg_0_TREADY
assume -name {decode first} -env \
{ (ila_exec == 1 & hls_exec == 1 & counter == 5) |-> ( \
    arg_0_TREADY == 1 \
) } -type {temporary} -update_db;
#
assume -name {decode rest} -env \
{ (counter != 5) |-> ( \
    arg_0_TREADY == 0 \
) } -type {temporary} -update_db;
#
assume -name {invariant} -env \
{ ( \
    arg_1_TVALID == 0 \
) } -type {temporary} -update_db;

# arg_0_TVALID
assume -name {eq arg_0_TVALID} -env \
{ (ila_exec == 0 & hls_exec == 0) |=> ( \
    ila_target_U.arg_0_TVALID == 1 & \
    hls_target_U.arg_0_TVALID == 1 \
) } -type {temporary} -update_db;

# arg_0_TDATA
assume -name {eq arg_0_TDATA} -env \
{ (ila_exec == 0 & hls_exec == 0) |=> ( \
    ila_target_U.arg_0_TDATA == hls_target_U.arg_0_TDATA \
) } -type {temporary} -update_db;

# stencil_full
#assume -name {init all stencil_full} -env \
{ (cnt_init == 0) |=> ( \
    ila_target_U.p_p2_in_bounded_stencil_stream_full == 1 & \
    hls_target_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n == 1 & \
    hls_target_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n == 0 \
) } -type {temporary} -update_db;

# stencil_buff
#assume -name {init all stencil_buff} -env \
{ (cnt_init == 0) |=> ( \
    ila_target_U.p_p2_in_bounded_stencil_stream_s_U == 1 & \
    hls_target_U.p_p2_in_bounded_stencil_stream_s_U.U_FIFO_hls_target_p_p2_in_bounded_stencil_stream_s_ram.SRL_SIG[0] == 0 & \
    hls_target_U.p_p2_in_bounded_stencil_stream_s_U.U_FIFO_hls_target_p_p2_in_bounded_stencil_stream_s_ram.q == 1 \
) } -type {temporary} -update_db;

# hls_arg_0_TDATA, hls_arg_0_TLAST, hls_arg_1_TLAST, hls_arg_1_TREADY
# LB2D buff, x/y/w index, stencil buff, slice buff, slice full
