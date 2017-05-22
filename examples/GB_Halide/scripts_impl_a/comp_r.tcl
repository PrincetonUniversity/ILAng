# Assumptions for proving read instruction 
# Compositional verification: decode, invariant, ...
#
# helper for phase
assume -name {comp - phase inc} -env \
{ phase == 1 |=> phase == 2 } -type {temporary} -update_db;
#
assume -name {comp - phase stop} -env \
{ phase == 2 |=> phase == 2 } -type {temporary} -update_db;

# decode 
assume -name {comp - decode} -env \
{ counter == 0 |=> ( \
    arg_1_TVALID == 0 & \
    arg_0_TREADY == 1 & \
    ila_arg_0_TVALID == 1 & \
    hls_arg_0_TVALID == 1 \
)} -type {temporary} -update_db;

assume -name {comp - protocol} -env \
{ counter == 0 |-> ( \
    ila_arg_0_TVALID == 1 & \
    hls_arg_0_TVALID == 1 \
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
assume -name {arch equal - iterator} -env \
{ counter == 0 |=> ( \
    (ila_gbit == 0 & \
     hls_gb_exit_it_1 == 0 & \
     hls_gb_exit_it_2 == 0 & \
     hls_gb_exit_it_3 == 0 & \
     hls_gb_exit_it_4 == 0 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) | \
    (ila_gbit == 1 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 0 & \
     hls_gb_exit_it_3 == 0 & \
     hls_gb_exit_it_4 == 0 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) | \
    (ila_gbit == 2 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 0 & \
     hls_gb_exit_it_4 == 0 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) | \
    (ila_gbit == 3 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 0 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) | \
    (ila_gbit == 4 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 0 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) | \
    (ila_gbit == 5 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 1 & \
     hls_gb_exit_it_6 == 0 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) | \
    (ila_gbit == 6 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 1 & \
     hls_gb_exit_it_6 == 1 & \
     hls_gb_exit_it_7 == 0 & \
     hls_gb_exit_it_8 == 0) | \
    (ila_gbit == 7 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 1 & \
     hls_gb_exit_it_6 == 1 & \
     hls_gb_exit_it_7 == 1 & \
     hls_gb_exit_it_8 == 0) | \
    (ila_gbit == 8 & \
     hls_gb_exit_it_1 == 1 & \
     hls_gb_exit_it_2 == 1 & \
     hls_gb_exit_it_3 == 1 & \
     hls_gb_exit_it_4 == 1 & \
     hls_gb_exit_it_5 == 1 & \
     hls_gb_exit_it_6 == 1 & \
     hls_gb_exit_it_7 == 1 & \
     hls_gb_exit_it_8 == 1) \
)} -type {temporary} -update_db;
#
assume -name {arch equal - data} -env \
{ counter == 0 |=> ( \
    ila_arg_0_TDATA == hls_arg_0_TDATA & \
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

