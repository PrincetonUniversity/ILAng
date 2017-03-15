# Assumptions for proving write instruction 
# Compositional verification: decode, invariant, ...
#
# decode 
assume -name {comp - decode} -env \
{ counter == 0 |=> ( \
    arg_1_TVALID == 1 & \
    arg_0_TREADY == 0 & \
    ila_arg_1_TREADY == 1 & \
    hls_arg_1_TREADY == 1 \
)} -type {temporary} -update_db;

assume -name {comp - protocol} -env \
{ counter == 0 |-> ( \
    ila_arg_1_TREADY == 1 & \
    hls_arg_1_TREADY == 1 \
)} -type {temporary} -update_db;

# turn off all other instruction (read and write) throughout verification
assume -name {comp - per instr} -env \
{ counter != 1 |-> ( \
    arg_1_TVALID == 0 & \
    arg_0_TREADY == 0 \
)} -type {temporary} -update_db;

# two models should have same architectural states
assume -name {arch equal - start} -env \
{ counter == 0 |=> ( \
    ila_LB1D_buff == hls_LB1D_buff & \
    ila_arg_0_TDATA  == hls_arg_0_TDATA & \
    ila_arg_0_TVALID == hls_arg_0_TVALID & \
    ila_arg_1_TREADY == hls_arg_1_TREADY & \
    ila_in_stream_full == hls_in_stream_full & \
    ila_in_stream_empty == hls_in_stream_empty & \
    ila_slice_stream_full == hls_slice_stream_full & \
    ila_slice_stream_empty == hls_slice_stream_empty & \
    ila_stencil_stream_full == hls_stencil_stream_full & \
    ila_stencil_stream_empty == hls_stencil_stream_empty & \
    ila_LB2D_proc_x == hls_LB2D_proc_x & \
    ila_LB2D_proc_y == hls_LB2D_proc_y & \
    ila_LB2D_proc_w == hls_LB2D_proc_w & \
    ila_LB2D_shift_x == hls_LB2D_shift_x & \
    ila_LB2D_shift_y == hls_LB2D_shift_y & \
    ila_p_cnt == hls_p_cnt & \
    ila_gb_pp_it_1 == hls_gb_pp_it_1 & \
    ila_gb_pp_it_2 == hls_gb_pp_it_2 & \
    ila_gb_pp_it_3 == hls_gb_pp_it_3 & \
    ila_gb_pp_it_4 == hls_gb_pp_it_4 & \
    ila_gb_pp_it_5 == hls_gb_pp_it_5 & \
    ila_gb_pp_it_6 == hls_gb_pp_it_6 & \
    ila_gb_pp_it_7 == hls_gb_pp_it_7 & \
    ila_gb_pp_it_8 == hls_gb_pp_it_8 & \
    ila_gb_pp_it_9 == hls_gb_pp_it_9 & \
    ila_gb_exit_it_1 == hls_gb_exit_it_1 & \
    ila_gb_exit_it_2 == hls_gb_exit_it_2 & \
    ila_gb_exit_it_3 == hls_gb_exit_it_3 & \
    ila_gb_exit_it_4 == hls_gb_exit_it_4 & \
    ila_gb_exit_it_5 == hls_gb_exit_it_5 & \
    ila_gb_exit_it_6 == hls_gb_exit_it_6 & \
    ila_gb_exit_it_7 == hls_gb_exit_it_7 & \
    ila_gb_exit_it_8 == hls_gb_exit_it_8 \
)} -type {temporary} -update_db;

# block pipeline, all previous instructions complete
#assume -name {block pipeline} -env \
{ (counter == 0) |=> ( \
    ~( \
    ((ila_U.in_stream_full == 0) & (ila_U.arg_1_TREADY == 0)) | \
    ((ila_U.slice_stream_full == 0) & (ila_U.in_stream_empty == 0)) | \
    ((ila_U.stencil_stream_full == 0) & (ila_U.slice_stream_empty == 0)) | \
    ((ila_U.arg_0_TVALID == 0) & (ila_U.stencil_stream_empty == 0)) \
    ) \
)} -type {temporary} -update_db;
