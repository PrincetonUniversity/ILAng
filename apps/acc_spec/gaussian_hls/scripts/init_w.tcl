# Assumptions initial condition
#
# stable fsm
assume -name {init - stable fsm} -env \
{ counter == 0 |=> ( \
    hls_LB1D_fsm == 2 & \
    hls_LB2D_proc_fsm == 4 & \
    hls_LB2D_shift_fsm == 4 & \
    hls_GB_fsm == 2 \
)} -update_db;

# valid pipeline iterator 
assume -name {init - cnt vs pp - ila} -env \
{ counter == 0 |=> ( \
    (ila_p_cnt == 0 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 0 & \
                      ila_gb_pp_it_3 == 0 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 1 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 0 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 2 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 0 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 3 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 0 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 4 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 0 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 5 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 0 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 6 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 1 & \
                      ila_gb_pp_it_8 == 0 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt == 7 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 1 & \
                      ila_gb_pp_it_8 == 1 & \
                      ila_gb_pp_it_9 == 0) | \
    (ila_p_cnt >= 8 & ila_gb_pp_it_1 == 1 & \
                      ila_gb_pp_it_2 == 1 & \
                      ila_gb_pp_it_3 == 1 & \
                      ila_gb_pp_it_4 == 1 & \
                      ila_gb_pp_it_5 == 1 & \
                      ila_gb_pp_it_6 == 1 & \
                      ila_gb_pp_it_7 == 1 & \
                      ila_gb_pp_it_8 == 1 & \
                      ila_gb_pp_it_9 == 1) \
)} -type {temporary} -update_db;

# valid pipeline iterator 
assume -name {init - cnt vs exit - ila} -env \
{ counter == 0 |=> ( \
    (ila_p_cnt <= 307200 & ila_gb_exit_it_1 == 0 & \
                           ila_gb_exit_it_2 == 0 & \
                           ila_gb_exit_it_3 == 0 & \
                           ila_gb_exit_it_4 == 0 & \
                           ila_gb_exit_it_5 == 0 & \
                           ila_gb_exit_it_6 == 0 & \
                           ila_gb_exit_it_7 == 0 & \
                           ila_gb_exit_it_8 == 0) | \
    (ila_p_cnt == 307200 & ((ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 0 & \
                             ila_gb_exit_it_3 == 0 & \
                             ila_gb_exit_it_4 == 0 & \
                             ila_gb_exit_it_5 == 0 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 0 & \
                             ila_gb_exit_it_4 == 0 & \
                             ila_gb_exit_it_5 == 0 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 0 & \
                             ila_gb_exit_it_5 == 0 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 0 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 1 & \
                             ila_gb_exit_it_6 == 0 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 1 & \
                             ila_gb_exit_it_6 == 1 & \
                             ila_gb_exit_it_7 == 0 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 1 & \
                             ila_gb_exit_it_6 == 1 & \
                             ila_gb_exit_it_7 == 1 & \
                             ila_gb_exit_it_8 == 0) | \
                            (ila_gb_exit_it_1 == 1 & \
                             ila_gb_exit_it_2 == 1 & \
                             ila_gb_exit_it_3 == 1 & \
                             ila_gb_exit_it_4 == 1 & \
                             ila_gb_exit_it_5 == 1 & \
                             ila_gb_exit_it_6 == 1 & \
                             ila_gb_exit_it_7 == 1 & \
                             ila_gb_exit_it_8 == 1))) \
)} -type {temporary} -update_db;
