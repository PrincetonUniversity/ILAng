# Assumptions for proving write instruction 
# Compositional verification: decode, invariant, ...
#
# decode 
assume -name {decode} -env \
{ counter == 0 |=> ( \
    arg_1_TVALID == 1 & \
    arg_0_TREADY == 0 & \
    ila_U.arg_1_TREADY == 1 & \
    hls_U.arg_1_TREADY == 1 \
)} -type {temporary} -update_db;

# turn off all other instruction (read and write) throughout verification
assume -name {composition} -env \
{ counter != 1 |-> ( \
    arg_1_TVALID == 0 & \
    arg_0_TREADY == 0 \
)} -type {temporary} -update_db;

# two models should have same architectural states
assume -name {arch equal - start} -env \
{ counter == 0 |=> ( \
    ila_U.arg_1_TREADY == hls_U.arg_1_TREADY & \
    ila_U.arg_0_TVALID == hls_U.arg_0_TVALID & \
    ila_U.arg_0_TDATA  == hls_U.arg_0_TDATA & \
    ila_U.in_stream_full == ~hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_full_n & \
    ila_U.in_stream_empty == ~hls_U.hls_target_linebuffer_1_U0.in_stream_V_value_V_U.internal_empty_n \
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
