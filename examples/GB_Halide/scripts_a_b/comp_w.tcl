# Assumptions for proving write instruction 
# Compositional verification: decode, invariant, ...
# decode 
assume -name {comp - decode} -env \
{ counter == 0 |=> ( \
    arg_1_TVALID == 1 & \
    arg_0_TREADY == 0 & \
    a_arg_1_TREADY == 1 & \
    b_arg_1_TREADY == 1 & \
    a_arg_0_TVALID == 0 & \
    b_arg_0_TVALID == 0 \
)} -type {temporary} -update_db;

assume -name {comp - protocol} -env \
{ counter == 0 |-> ( \
    a_arg_1_TREADY == 1 & \
    b_arg_1_TREADY == 1 \
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
    a_arg_1_TREADY == b_arg_1_TREADY & \
    a_arg_0_TVALID == b_arg_0_TVALID & \
    a_RAM_x == b_LB2D_proc_x & \
    a_RAM_y == b_LB2D_proc_y & \
    a_RAM_w == b_LB2D_proc_w \
)} -type {temporary} -update_db;
#
assume -name {arch equal - data} -env \
{ counter == 0 |=> ( \
    a_arg_0_TDATA == b_arg_0_TDATA & \
    ila_a.RAM_0 == ila_b.LB2D_proc_0 & \
    ila_a.RAM_1 == ila_b.LB2D_proc_1 & \
    ila_a.RAM_2 == ila_b.LB2D_proc_2 & \
    ila_a.RAM_3 == ila_b.LB2D_proc_3 & \
    ila_a.RAM_4 == ila_b.LB2D_proc_4 & \
    ila_a.RAM_5 == ila_b.LB2D_proc_5 & \
    ila_a.RAM_6 == ila_b.LB2D_proc_6 & \
    ila_a.RAM_7 == ila_b.LB2D_proc_7 & \
    a_stencil_0 == b_LB2D_shift_0 & \
    a_stencil_1 == b_LB2D_shift_1 & \
    a_stencil_2 == b_LB2D_shift_2 & \
    a_stencil_3 == b_LB2D_shift_3 & \
    a_stencil_4 == b_LB2D_shift_4 & \
    a_stencil_5 == b_LB2D_shift_5 & \
    a_stencil_6 == b_LB2D_shift_6 & \
    a_stencil_7 == b_LB2D_shift_7 & \
    a_stencil_8 == b_slice_stream_buff_1 \
)} -type {temporary} -update_db;
#
assume -name {arch equal - iterator} -env \
{ counter == 0 |=> ( \
    (ila_a.gbit == 0 & \
     b_gb_exit_it_1 == 0 & \
     b_gb_exit_it_2 == 0 & \
     b_gb_exit_it_3 == 0 & \
     b_gb_exit_it_4 == 0 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) | \
    (ila_a.gbit == 1 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 0 & \
     b_gb_exit_it_3 == 0 & \
     b_gb_exit_it_4 == 0 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) | \
    (ila_a.gbit == 2 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 0 & \
     b_gb_exit_it_4 == 0 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) | \
    (ila_a.gbit == 3 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 0 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) | \
    (ila_a.gbit == 4 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 1 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) | \
    (ila_a.gbit == 5 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 1 & \
     b_gb_exit_it_5 == 1 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) | \
    (ila_a.gbit == 6 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 1 & \
     b_gb_exit_it_5 == 1 & \
     b_gb_exit_it_6 == 1 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) | \
    (ila_a.gbit == 7 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 1 & \
     b_gb_exit_it_5 == 1 & \
     b_gb_exit_it_6 == 1 & \
     b_gb_exit_it_7 == 1 & \
     b_gb_exit_it_8 == 0) \
)} -type {temporary} -update_db;

