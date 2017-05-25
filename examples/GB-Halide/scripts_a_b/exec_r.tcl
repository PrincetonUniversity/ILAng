# Assumptions for proving write instruction 
# Execute: start and stop models
#
# start
assume -name {exec - start model} -env \
{ counter <= 2 |-> ( \
    a_complete == 0 & \
    b_complete == 0 \
)} -type {temporary} -update_db;

# stop
assume -name {exec - a continue} -env \
{ (counter > 1) |-> ( \
    (a_arg_0_TVALID == 1 & \
     arg_1_TVALID == 0 & \
     arg_0_TREADY == 1) \
    |=> \
    (a_complete == 0) \
)} -type {temporary} -update_db;
#
assume -name {exec - a break} -env \
{ (counter > 1) |-> ( \
   ~( \
    (a_arg_0_TVALID == 1 & \
     arg_1_TVALID == 0 & \
     arg_0_TREADY == 1) \
    ) \
    |=> \
    (a_complete == 1) \
)} -type {temporary} -update_db;
#
assume -name {exec - b continue} -env \
{ (counter > 1) |-> ( \
    ( \
    (arg_1_TVALID == 1) | \
    ((b_arg_1_TREADY == 0) & (b_in_stream_full == 0)) | \
    ((b_arg_1_TREADY == 1) & (b_in_stream_full == 0) & (b_LB1D_it_1 == 1) & (b_LB1D_p_cnt == 316224)) | \
    ((b_in_stream_empty == 0) & \
        ((b_slice_stream_full == 0) | (b_LB2D_proc_y < 8))) | \
    ((b_slice_stream_empty == 0) & \
        ((b_stencil_stream_full == 0) | (b_LB2D_shift_x < 8))) | \
    ((b_arg_0_TVALID == 0) & \
        (((b_gb_exit_it_1 == 0) & (b_stencil_stream_empty == 0)) | \
         ((b_gb_exit_it_1 == 1) & (b_gb_exit_it_8 == 0)))) \
    ) \
    |=> \
    (b_complete == 0) \
)} -type {temporary} -update_db;
#
assume -name {exec - b break} -env \
{ (counter > 1) |-> ( \
    ~( \
    (arg_1_TVALID == 1) | \
    ((b_arg_1_TREADY == 0) & (b_in_stream_full == 0)) | \
    ((b_arg_1_TREADY == 1) & (b_in_stream_full == 0) & (b_LB1D_it_1 == 1) & (b_LB1D_p_cnt == 316224)) | \
    ((b_in_stream_empty == 0) & \
        ((b_slice_stream_full == 0) | (b_LB2D_proc_y < 8))) | \
    ((b_slice_stream_empty == 0) & \
        ((b_stencil_stream_full == 0) | (b_LB2D_shift_x < 8))) | \
    ((b_arg_0_TVALID == 0) & \
        (((b_gb_exit_it_1 == 0) & (b_stencil_stream_empty == 0)) | \
         ((b_gb_exit_it_1 == 1) & (b_gb_exit_it_8 == 0)))) \
    ) \
    |=> \
    (b_complete == 1) \
)} -type {temporary} -update_db;
