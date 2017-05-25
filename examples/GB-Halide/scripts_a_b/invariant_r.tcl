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
    (a_gbit == 0 & \
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
    (a_gbit == 1 & \
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
    (a_gbit == 2 & \
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
    (a_gbit == 3 & \
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
    (a_gbit == 4 & \
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
    (a_gbit == 5 & \
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
    (a_gbit == 6 & \
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
    (a_gbit == 7 & \
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

