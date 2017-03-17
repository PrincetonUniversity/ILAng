# Assertions for proving equivalence between ILA and HLS
#
# instructions terminate
assert -name {terminate - ila} \
{ (counter > 1) |-> (ila_complete == 0) \
} -update_db;
# 
assert -name {terminate - hls} \
{ (counter > 1) |-> (hls_step == 0) \
} -update_db;

# equivalence on arch states
# arg_1_TREADY
assert -name {eq - arg_1_TREADY} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.arg_1_TREADY == hls_U.arg_1_TREADY \
) } -update_db;
#
#assert -name {eq wait - arg_1_TREADY} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_U.arg_1_TREADY == hls_U.arg_1_TREADY \
) } -update_db;

# arg_0_TVALID
assert -name {eq - arg_0_TVALID} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.arg_0_TVALID == hls_U.arg_0_TVALID \
) } -update_db;
#
#assert -name {eq wait - arg_0_TVALID} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_U.arg_0_TVALID == hls_U.arg_0_TVALID \
) } -update_db;

# LB1D_p_cnt
assert -name {eq - LB1D_p_cnt} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB1D_p_cnt == hls_LB1D_p_cnt \
) } -update_db;
#
#assert -name {eq wait - LB1D_p_cnt} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_LB1D_p_cnt == hls_LB1D_p_cnt \
) } -update_db;

# in_stream_empty
assert -name {eq - in_stream_empty} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_in_stream_empty == hls_in_stream_empty \
) } -update_db;
#
#assert -name {eq wait - in_stream_empty} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_in_stream_empty == hls_in_stream_empty \
) } -update_db;

# in_stream_full
assert -name {eq - in_stream_full} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_in_stream_full == hls_in_stream_full \
) } -update_db;
#
#assert -name {eq wait - in_stream_full} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_in_stream_full == hls_in_stream_full \
) } -update_db;

# LB2D_proc_x
assert -name {eq - LB2D_proc_x} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB2D_proc_x == hls_LB2D_proc_x \
) } -update_db;
#
#assert -name {eq wait - LB2D_proc_x} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_LB2D_proc_x == hls_LB2D_proc_x \
) } -update_db;

# LB2D_proc_y
assert -name {eq - LB2D_proc_y} \ 
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_LB2D_shift_y == hls_LB2D_shift_y \
) } -update_db;

