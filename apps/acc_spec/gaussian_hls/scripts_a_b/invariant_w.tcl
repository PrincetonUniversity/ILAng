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
