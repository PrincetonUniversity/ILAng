# Assumptions initial condition
#
# decompose verification
assume -name {Subset - C1} -env \
{ counter == 0 |=> ( \
    b_LB1D_p_cnt >= 3904 & b_LB1D_p_cnt < 315736 & \
    b_LB2D_proc_x > 0    & b_LB2D_proc_x < 487 & \
    b_LB2D_proc_y >= 8   & b_LB2D_proc_y < 648 & \
    b_LB2D_shift_x > 0   & b_LB2D_shift_x < 487 & \
    b_LB2D_shift_y >= 0  & b_LB2D_shift_y < 640 & \
    b_gb_p_cnt >= 10     & b_gb_p_cnt < 306720 \
)} -type {temporary} -update_db;
#
assume -name {Subset - C2} -env \
{ counter == 0 |=> ( \
    b_LB1D_p_cnt >= 3904  & b_LB1D_p_cnt < 315736 & \
    b_LB2D_proc_x == 487  & \
    b_LB2D_proc_y >= 8    & b_LB2D_proc_y < 648 & \
    b_LB2D_shift_x == 487 & \
    b_LB2D_shift_y >= 0   & b_LB2D_shift_y < 640 & \
    b_gb_p_cnt >= 450     & b_gb_p_cnt < 306720 & \
    ~(b_LB2D_proc_x >= 487 & b_LB2D_proc_y == 647) \
)} -type {temporary} -update_db;
#
assume -name {Subset - C3} -env \
{ counter == 0 |=> ( \
    b_LB1D_p_cnt >= 3904  & b_LB1D_p_cnt < 315736 & \
    b_LB2D_proc_x == 488  & \
    b_LB2D_proc_y >= 8    & b_LB2D_proc_y < 648 & \
    b_LB2D_shift_x == 488 & \
    b_LB2D_shift_y >= 0   & b_LB2D_shift_y < 640 & \
    b_gb_p_cnt >= 450     & b_gb_p_cnt < 306720 & \
    ~(b_LB2D_proc_x >= 487 & b_LB2D_proc_y == 647) \
)} -type {temporary} -update_db;
#
assume -name {Subset - D} -env \
{ counter == 0 |=> ( \
    b_LB1D_p_cnt >= 315736 & b_LB1D_p_cnt <= 316222 & \
    b_LB2D_proc_x > 0      & b_LB2D_proc_x <= 488 & \
    b_LB2D_proc_y == 647   & \
    b_LB2D_shift_x > 0     & b_LB2D_shift_x <= 488 & \
    b_LB2D_shift_y == 639  & \
    b_gb_p_cnt >= 306240   & b_gb_p_cnt < 307200 & \
    ~(b_LB2D_proc_x >= 487 & b_LB2D_proc_y == 647) \
)} -type {temporary} -update_db;
#
assume -name {Subset - E} -env \
{ counter == 0 |=> ( \
    b_LB1D_p_cnt == 316224 & \
    b_LB2D_proc_x == 488 & \
    b_LB2D_proc_y == 648 & \
    b_LB2D_shift_x == 488 & \
    b_LB2D_shift_y == 640 & \
    b_gb_p_cnt == 307200 \
)} -type {temporary} -update_db;

assume -name {Subset - all} -env \
{ counter == 0 |=> ( \
    ( \
    b_LB1D_p_cnt >= 3904 & b_LB1D_p_cnt < 315736 & \
    b_LB2D_proc_x > 0    & b_LB2D_proc_x < 487 & \
    b_LB2D_proc_y >= 8   & b_LB2D_proc_y < 648 & \
    b_LB2D_shift_x > 0   & b_LB2D_shift_x < 487 & \
    b_LB2D_shift_y >= 0  & b_LB2D_shift_y < 640 & \
    b_gb_p_cnt >= 10     & b_gb_p_cnt < 306720 \
    ) | \
    ( \
    b_LB1D_p_cnt >= 3904  & b_LB1D_p_cnt < 315736 & \
    b_LB2D_proc_x == 487  & \
    b_LB2D_proc_y >= 8    & b_LB2D_proc_y < 648 & \
    b_LB2D_shift_x == 487 & \
    b_LB2D_shift_y >= 0   & b_LB2D_shift_y < 640 & \
    b_gb_p_cnt >= 450     & b_gb_p_cnt < 306720 & \
    ~(b_LB2D_proc_x >= 487 & b_LB2D_proc_y == 647) \
    ) | \
    ( \
    b_LB1D_p_cnt >= 3904  & b_LB1D_p_cnt < 315736 & \
    b_LB2D_proc_x == 488  & \
    b_LB2D_proc_y >= 8    & b_LB2D_proc_y < 648 & \
    b_LB2D_shift_x == 488 & \
    b_LB2D_shift_y >= 0   & b_LB2D_shift_y < 640 & \
    b_gb_p_cnt >= 450     & b_gb_p_cnt < 306720 & \
    ~(b_LB2D_proc_x >= 487 & b_LB2D_proc_y == 647) \
    ) | \
    ( \
    b_LB1D_p_cnt >= 315736 & b_LB1D_p_cnt <= 316222 & \
    b_LB2D_proc_x > 0      & b_LB2D_proc_x <= 488 & \
    b_LB2D_proc_y == 647   & \
    b_LB2D_shift_x > 0     & b_LB2D_shift_x <= 488 & \
    b_LB2D_shift_y == 639  & \
    b_gb_p_cnt >= 306240   & b_gb_p_cnt < 307200 & \
    ~(b_LB2D_proc_x >= 487 & b_LB2D_proc_y == 647) \
    ) | \
    ( \
    b_LB1D_p_cnt == 316224 & \
    b_LB2D_proc_x == 488 & \
    b_LB2D_proc_y == 648 & \
    b_LB2D_shift_x == 488 & \
    b_LB2D_shift_y == 640 & \
    b_gb_p_cnt == 307200 \
    ) \
)} -type {temporary} -update_db;

# block buffering
assume -name {init - empty buffers} -env \
{ counter == 0 |=> ( \
    b_in_stream_empty == 1 & b_in_stream_full == 0 & \
    b_slice_stream_empty == 1 & b_slice_stream_full == 0 & \
    b_stencil_stream_empty == 1 & b_stencil_stream_full == 0 \
)} -type {temporary} -update_db;

# input holding
assume -name {init - in proc unit it} -env \
{ counter == 0 |=> ( \
    (b_LB1D_p_cnt > 0 & b_LB1D_p_cnt < 316224) |-> (b_LB1D_it_1 == 1) \
)} -type {temporary} -update_db;
#
assume -name {init - in proc unit it flush} -env \
{ counter == 0 |=> (b_LB1D_p_cnt == 316224 |-> b_LB1D_it_1 == 0) } -type {temporary} -update_db;

# data valid must implies iteration done
assume -name {init - output valid vs iterator} -env \
{ counter == 0 |=> ( \
    (b_arg_0_TVALID == 0) | \
    (b_arg_0_TVALID == 1 & b_gb_pp_it_8 == 1) \
)} -type {temporary} -update_db;

# pre cur input pixel
assume -name {child init - consistent input pixel} -env \
{ counter == 0 |-> ( \
    b_LB1D_in == b_LB1D_buff & \
    b_LB1D_in == b_LB1D_uIn & \
    a_cur_pix == b_LB1D_buff \
)} -type {temporary} -update_db;

# consistent buffer index
assume -name {init - consistent buffer x} -env \
{ counter == 0 |=> ( \
    (b_LB2D_proc_x == b_LB2D_shift_x) | \
    (b_LB2D_proc_y <= 7 & b_LB2D_shift_x == 0) \
)} -type {temporary} -update_db;

# consistent buffer index
assume -name {init - consistent buffer y} -env \
{ counter == 0 |=> ( \
    (b_LB2D_proc_y == b_LB2D_shift_y + 8) | \
    (b_LB2D_proc_y <= 7 & b_LB2D_shift_y == 0) \
)} -type {temporary} -update_db;

# valid pipeline iterator 
assume -name {init - cnt vs pp} -env \
{ counter == 0 |=> ( \
    (b_gb_p_cnt == 0 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 0 & \
                      b_gb_pp_it_3 == 0 & \
                      b_gb_pp_it_4 == 0 & \
                      b_gb_pp_it_5 == 0 & \
                      b_gb_pp_it_6 == 0 & \
                      b_gb_pp_it_7 == 0 & \
                      b_gb_pp_it_8 == 0 & \
                      b_gb_pp_it_9 == 0) | \
    (b_gb_p_cnt == 1 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 1 & \
                      b_gb_pp_it_3 == 0 & \
                      b_gb_pp_it_4 == 0 & \
                      b_gb_pp_it_5 == 0 & \
                      b_gb_pp_it_6 == 0 & \
                      b_gb_pp_it_7 == 0 & \
                      b_gb_pp_it_8 == 0 & \
                      b_gb_pp_it_9 == 0) | \
    (b_gb_p_cnt == 2 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 1 & \
                      b_gb_pp_it_3 == 1 & \
                      b_gb_pp_it_4 == 0 & \
                      b_gb_pp_it_5 == 0 & \
                      b_gb_pp_it_6 == 0 & \
                      b_gb_pp_it_7 == 0 & \
                      b_gb_pp_it_8 == 0 & \
                      b_gb_pp_it_9 == 0) | \
    (b_gb_p_cnt == 3 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 1 & \
                      b_gb_pp_it_3 == 1 & \
                      b_gb_pp_it_4 == 1 & \
                      b_gb_pp_it_5 == 0 & \
                      b_gb_pp_it_6 == 0 & \
                      b_gb_pp_it_7 == 0 & \
                      b_gb_pp_it_8 == 0 & \
                      b_gb_pp_it_9 == 0) | \
    (b_gb_p_cnt == 4 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 1 & \
                      b_gb_pp_it_3 == 1 & \
                      b_gb_pp_it_4 == 1 & \
                      b_gb_pp_it_5 == 1 & \
                      b_gb_pp_it_6 == 0 & \
                      b_gb_pp_it_7 == 0 & \
                      b_gb_pp_it_8 == 0 & \
                      b_gb_pp_it_9 == 0) | \
    (b_gb_p_cnt == 5 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 1 & \
                      b_gb_pp_it_3 == 1 & \
                      b_gb_pp_it_4 == 1 & \
                      b_gb_pp_it_5 == 1 & \
                      b_gb_pp_it_6 == 1 & \
                      b_gb_pp_it_7 == 0 & \
                      b_gb_pp_it_8 == 0 & \
                      b_gb_pp_it_9 == 0) | \
    (b_gb_p_cnt == 6 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 1 & \
                      b_gb_pp_it_3 == 1 & \
                      b_gb_pp_it_4 == 1 & \
                      b_gb_pp_it_5 == 1 & \
                      b_gb_pp_it_6 == 1 & \
                      b_gb_pp_it_7 == 1 & \
                      b_gb_pp_it_8 == 0 & \
                      b_gb_pp_it_9 == 0) | \
    (b_gb_p_cnt == 7 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 1 & \
                      b_gb_pp_it_3 == 1 & \
                      b_gb_pp_it_4 == 1 & \
                      b_gb_pp_it_5 == 1 & \
                      b_gb_pp_it_6 == 1 & \
                      b_gb_pp_it_7 == 1 & \
                      b_gb_pp_it_8 == 1 & \
                      b_gb_pp_it_9 == 0) | \
    (b_gb_p_cnt >= 8 & b_gb_pp_it_1 == 1 & \
                      b_gb_pp_it_2 == 1 & \
                      b_gb_pp_it_3 == 1 & \
                      b_gb_pp_it_4 == 1 & \
                      b_gb_pp_it_5 == 1 & \
                      b_gb_pp_it_6 == 1 & \
                      b_gb_pp_it_7 == 1 & \
                      b_gb_pp_it_8 == 1 & \
                      b_gb_pp_it_9 == 1) \
)} -type {temporary} -update_db;

# valid pipeline iterator 
assume -name {init - cnt vs exit} -env \
{ counter == 0 |=> ( \
    (b_gb_p_cnt < 307200 & b_gb_exit_it_1 == 0 & \
                          b_gb_exit_it_2 == 0 & \
                          b_gb_exit_it_3 == 0 & \
                          b_gb_exit_it_4 == 0 & \
                          b_gb_exit_it_5 == 0 & \
                          b_gb_exit_it_6 == 0 & \
                          b_gb_exit_it_7 == 0 & \
                          b_gb_exit_it_8 == 0) | \
    (b_gb_p_cnt == 307200 & ((b_gb_exit_it_1 == 1 & \
                             b_gb_exit_it_2 == 0 & \
                             b_gb_exit_it_3 == 0 & \
                             b_gb_exit_it_4 == 0 & \
                             b_gb_exit_it_5 == 0 & \
                             b_gb_exit_it_6 == 0 & \
                             b_gb_exit_it_7 == 0 & \
                             b_gb_exit_it_8 == 0) | \
                            (b_gb_exit_it_1 == 1 & \
                             b_gb_exit_it_2 == 1 & \
                             b_gb_exit_it_3 == 0 & \
                             b_gb_exit_it_4 == 0 & \
                             b_gb_exit_it_5 == 0 & \
                             b_gb_exit_it_6 == 0 & \
                             b_gb_exit_it_7 == 0 & \
                             b_gb_exit_it_8 == 0) | \
                            (b_gb_exit_it_1 == 1 & \
                             b_gb_exit_it_2 == 1 & \
                             b_gb_exit_it_3 == 1 & \
                             b_gb_exit_it_4 == 0 & \
                             b_gb_exit_it_5 == 0 & \
                             b_gb_exit_it_6 == 0 & \
                             b_gb_exit_it_7 == 0 & \
                             b_gb_exit_it_8 == 0) | \
                            (b_gb_exit_it_1 == 1 & \
                             b_gb_exit_it_2 == 1 & \
                             b_gb_exit_it_3 == 1 & \
                             b_gb_exit_it_4 == 1 & \
                             b_gb_exit_it_5 == 0 & \
                             b_gb_exit_it_6 == 0 & \
                             b_gb_exit_it_7 == 0 & \
                             b_gb_exit_it_8 == 0) | \
                            (b_gb_exit_it_1 == 1 & \
                             b_gb_exit_it_2 == 1 & \
                             b_gb_exit_it_3 == 1 & \
                             b_gb_exit_it_4 == 1 & \
                             b_gb_exit_it_5 == 1 & \
                             b_gb_exit_it_6 == 0 & \
                             b_gb_exit_it_7 == 0 & \
                             b_gb_exit_it_8 == 0) | \
                            (b_gb_exit_it_1 == 1 & \
                             b_gb_exit_it_2 == 1 & \
                             b_gb_exit_it_3 == 1 & \
                             b_gb_exit_it_4 == 1 & \
                             b_gb_exit_it_5 == 1 & \
                             b_gb_exit_it_6 == 1 & \
                             b_gb_exit_it_7 == 0 & \
                             b_gb_exit_it_8 == 0) | \
                            (b_gb_exit_it_1 == 1 & \
                             b_gb_exit_it_2 == 1 & \
                             b_gb_exit_it_3 == 1 & \
                             b_gb_exit_it_4 == 1 & \
                             b_gb_exit_it_5 == 1 & \
                             b_gb_exit_it_6 == 1 & \
                             b_gb_exit_it_7 == 1 & \
                             b_gb_exit_it_8 == 0) | \
                            (b_gb_exit_it_1 == 1 & \
                             b_gb_exit_it_2 == 1 & \
                             b_gb_exit_it_3 == 1 & \
                             b_gb_exit_it_4 == 1 & \
                             b_gb_exit_it_5 == 1 & \
                             b_gb_exit_it_6 == 1 & \
                             b_gb_exit_it_7 == 1 & \
                             b_gb_exit_it_8 == 1))) \
)} -type {temporary} -update_db;

