# Assumptions for proving write instruction 
# Execute: start and stop models
#
# start
assume -name {exec - start model} -env \
{ counter <= 6 |-> ( \
    hls_complete == 0 & \
    ila_complete == 0 \
)} -type {temporary} -update_db;

# stop
assume -name {exec - ila continue} -env \
{ (counter > 5) |-> ( \
    ( \
    (arg_1_TVALID == 1) | \
    ((ila_arg_1_TREADY == 0) & (ila_in_stream_full == 0)) | \
    ((ila_arg_1_TREADY == 1) & (ila_in_stream_full == 0) & (ila_LB1D_it_1 == 1) & (ila_LB1D_p_cnt == 316224)) | \
    ((ila_in_stream_empty == 0) & \
        ((ila_slice_stream_full == 0) | (ila_LB2D_proc_y < 8))) | \
    ((ila_slice_stream_empty == 0) & \
        ((ila_stencil_stream_full == 0) | (ila_LB2D_shift_x < 8))) | \
    ((ila_arg_0_TVALID == 0) & \
        (((ila_gb_exit_it_1 == 0) & (ila_stencil_stream_empty == 0)) | \
        ((ila_gb_exit_it_1 == 1) & (ila_gb_exit_it_8 == 0)))) \
    ) \
    |=> \
    (ila_complete == 0) \
)} -type {temporary} -update_db;
#
assume -name {exec - ila break} -env \
{ (counter > 5) |-> ( \
   ~( \
    (arg_1_TVALID == 1) | \
    ((ila_arg_1_TREADY == 0) & (ila_in_stream_full == 0)) | \
    ((ila_arg_1_TREADY == 1) & (ila_in_stream_full == 0) & (ila_LB1D_it_1 == 1) & (ila_LB1D_p_cnt == 316224)) | \
    ((ila_in_stream_empty == 0) & \
        ((ila_slice_stream_full == 0) | (ila_LB2D_proc_y < 8))) | \
    ((ila_slice_stream_empty == 0) & \
        ((ila_stencil_stream_full == 0) | (ila_LB2D_shift_x < 8))) | \
    ((ila_arg_0_TVALID == 0) & \
        (((ila_gb_exit_it_1 == 0) & (ila_stencil_stream_empty == 0)) | \
        ((ila_gb_exit_it_1 == 1) & (ila_gb_exit_it_8 == 0)))) \
    ) \
    |=> \
    (ila_complete == 1) \
)} -type {temporary} -update_db;
#
assume -name {exec - hls continue} -env \
{ (counter > 5) |-> ( \
    ( \
    (arg_1_TVALID == 1) | \
    ((hls_arg_1_TREADY == 0) & (hls_in_stream_full == 0)) | \
    ((hls_in_stream_empty == 0) & \
        ((hls_slice_stream_full == 0) | (hls_LB2D_proc_y < 8))) | \
    ((hls_slice_stream_empty == 0) & \
        ((hls_stencil_stream_full == 0) | (hls_LB2D_shift_x < 8))) | \
    ((hls_arg_0_TVALID == 0) & \
        (((hls_gb_exit_it_1 == 0) & (hls_stencil_stream_empty == 0)) | \
         ((hls_gb_exit_it_1 == 1) & (hls_gb_exit_it_8 == 0)))) \
    ) \
    | hls_arg_1_TREADY != 1 \
    |=> \
    (hls_complete == 0) \
)} -type {temporary} -update_db;
#
assume -name {exec - hls break} -env \
{ (counter > 5) |-> ( \
   ~( \
    (arg_1_TVALID == 1) | \
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
    |=> \
    (hls_complete == 1) \
)} -type {temporary} -update_db;
