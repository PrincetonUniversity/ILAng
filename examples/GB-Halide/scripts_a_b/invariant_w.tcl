# Assumptions for refining initial condition by blocking unreachable states
#
# x/y/w index: should fall in valid range
assume -name {inv - index bound} -env \
{ ( \
    b_LB1D_p_cnt  >= 0  & b_LB1D_p_cnt <= 316224 & \
    b_LB2D_proc_x >= 0  & b_LB2D_proc_x <= 488 & \
    b_LB2D_proc_y >= 0  & b_LB2D_proc_y <= 648 & \
    b_LB2D_proc_w >= 0  & b_LB2D_proc_w < 8 & \
    b_LB2D_shift_x >= 0 & b_LB2D_shift_x <= 488 & \
    b_LB2D_shift_y >= 0 & b_LB2D_shift_y <= 640 & \
    b_gb_p_cnt >= 0     & b_gb_p_cnt <= 307200 \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 0} -env \
{ ( \
    (ila_a.gbit == 0 & \
     (a_proc_in == b_stencil_stream_buff_0 | \
      a_proc_in == b_stencil_stream_buff_1) & \
     a_arg_0_TVALID == 1 & \
     b_arg_0_TVALID == 1 & \
     b_gb_exit_it_1 == 0 & \
     b_gb_exit_it_2 == 0 & \
     b_gb_exit_it_3 == 0 & \
     b_gb_exit_it_4 == 0 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) |-> \
     a_arg_0_TDATA == b_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 1} -env \
{ ( \
    (ila_a.gbit == 1 & \
     (a_proc_in == b_stencil_stream_buff_0 | \
      a_proc_in == b_stencil_stream_buff_1) & \
     a_arg_0_TVALID == 1 & \
     b_arg_0_TVALID == 1 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 0 & \
     b_gb_exit_it_3 == 0 & \
     b_gb_exit_it_4 == 0 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) |-> \
     a_arg_0_TDATA == b_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 2} -env \
{ ( \
    (ila_a.gbit == 2 & \
     (a_proc_in == b_stencil_stream_buff_0 | \
      a_proc_in == b_stencil_stream_buff_1) & \
     a_arg_0_TVALID == 1 & \
     b_arg_0_TVALID == 1 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 0 & \
     b_gb_exit_it_4 == 0 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) |-> \
     a_arg_0_TDATA == b_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 3} -env \
{ ( \
    (ila_a.gbit == 3 & \
     (a_proc_in == b_stencil_stream_buff_0 | \
      a_proc_in == b_stencil_stream_buff_1) & \
     a_arg_0_TVALID == 1 & \
     b_arg_0_TVALID == 1 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 0 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) |-> \
     a_arg_0_TDATA == b_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 4} -env \
{ ( \
    (ila_a.gbit == 4 & \
     (a_proc_in == b_stencil_stream_buff_0 | \
      a_proc_in == b_stencil_stream_buff_1) & \
     a_arg_0_TVALID == 1 & \
     b_arg_0_TVALID == 1 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 1 & \
     b_gb_exit_it_5 == 0 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) |-> \
     a_arg_0_TDATA == b_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 5} -env \
{ ( \
    (ila_a.gbit == 5 & \
     (a_proc_in == b_stencil_stream_buff_0 | \
      a_proc_in == b_stencil_stream_buff_1) & \
     a_arg_0_TVALID == 1 & \
     b_arg_0_TVALID == 1 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 1 & \
     b_gb_exit_it_5 == 1 & \
     b_gb_exit_it_6 == 0 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) |-> \
     a_arg_0_TDATA == b_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 6} -env \
{ ( \
    (ila_a.gbit == 6 & \
     (a_proc_in == b_stencil_stream_buff_0 | \
      a_proc_in == b_stencil_stream_buff_1) & \
     a_arg_0_TVALID == 1 & \
     b_arg_0_TVALID == 1 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 1 & \
     b_gb_exit_it_5 == 1 & \
     b_gb_exit_it_6 == 1 & \
     b_gb_exit_it_7 == 0 & \
     b_gb_exit_it_8 == 0) |-> \
     a_arg_0_TDATA == b_arg_0_TDATA \
)} -type {temporary} -update_db;

assume -name {inv - uninterpreted GB 7} -env \
{ ( \
    (ila_a.gbit == 7 & \
     (a_proc_in == b_stencil_stream_buff_0 | \
      a_proc_in == b_stencil_stream_buff_1) & \
     a_arg_0_TVALID == 1 & \
     b_arg_0_TVALID == 1 & \
     b_gb_exit_it_1 == 1 & \
     b_gb_exit_it_2 == 1 & \
     b_gb_exit_it_3 == 1 & \
     b_gb_exit_it_4 == 1 & \
     b_gb_exit_it_5 == 1 & \
     b_gb_exit_it_6 == 1 & \
     b_gb_exit_it_7 == 1 & \
     b_gb_exit_it_8 == 0) |-> \
     a_arg_0_TDATA == b_arg_0_TDATA \
)} -type {temporary} -update_db;

