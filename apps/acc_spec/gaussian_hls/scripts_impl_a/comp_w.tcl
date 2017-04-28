# Assumptions for proving write instruction 
# Compositional verification: decode, invariant, ...
#
# decode 
assume -name {comp - decode} -env \
{ counter == 0 |=> ( \
    arg_1_TVALID == 1 & \
    arg_0_TREADY == 0 & \
    ila_arg_1_TREADY == 1 & \
    hls_arg_1_TREADY == 1 & \
    ila_arg_0_TVALID == 0 & \
    hls_arg_0_TVALID == 0 \
)} -type {temporary} -update_db;

assume -name {comp - protocol} -env \
{ counter == 0 |-> ( \
    ila_arg_1_TREADY == 1 & \
    hls_arg_1_TREADY == 1 \
)} -type {temporary} -update_db;

assume -name {comp - force data value} -env \
{ ( \
    arg_1_TDATA == 255 \
)} -type {temporary} -update_db;

# turn off all other instruction throughout verification
assume -name {comp - per instr} -env \
{ counter != 1 |-> ( \
    arg_1_TVALID == 0 & arg_0_TREADY == 0 \
)} -type {temporary} -update_db;

# two models should have same architectureal states
assume -name {arch equal - control} -env \
{ counter == 0 |=> ( \
    ila_arg_1_TREADY == hls_arg_1_TREADY & \
    ila_arg_0_TVALID == hls_arg_0_TVALID & \
    ila_RAM_x == hls_LB2D_proc_x & \
    ila_RAM_y == hls_LB2D_proc_y & \
    ila_RAM_w == hls_LB2D_proc_w \
)} -type {temporary} -update_db;
#
assume -name {arch equal - data} -env \
{ counter == 0 |=> ( \
    ila_arg_0_TDATA == hls_arg_0_TDATA & \
    ila_U.RAM_0 == hls_LB2D_proc_0 & \
    ila_U.RAM_1 == hls_LB2D_proc_1 & \
    ila_U.RAM_2 == hls_LB2D_proc_2 & \
    ila_U.RAM_3 == hls_LB2D_proc_3 & \
    ila_U.RAM_4 == hls_LB2D_proc_4 & \
    ila_U.RAM_5 == hls_LB2D_proc_5 & \
    ila_U.RAM_6 == hls_LB2D_proc_6 & \
    ila_U.RAM_7 == hls_LB2D_proc_7 & \
    ila_stencil_0 == hls_LB2D_shift_0 & \
    ila_stencil_1 == hls_LB2D_shift_1 & \
    ila_stencil_2 == hls_LB2D_shift_2 & \
    ila_stencil_3 == hls_LB2D_shift_3 & \
    ila_stencil_4 == hls_LB2D_shift_4 & \
    ila_stencil_5 == hls_LB2D_shift_5 & \
    ila_stencil_6 == hls_LB2D_shift_6 & \
    ila_stencil_7 == hls_LB2D_shift_7 & \
    ila_stencil_8 == hls_slice_stream_buff_1 \
)} -type {temporary} -update_db;
#
