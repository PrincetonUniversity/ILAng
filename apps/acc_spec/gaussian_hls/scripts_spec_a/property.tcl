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

# arg_0_TVALID
assert -name {eq - arg_0_TVALID} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_U.arg_0_TVALID == hls_U.arg_0_TVALID \
) } -update_db;

# RAM_x
assert -name {eq - RAM_x} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_RAM_x == hls_LB2D_proc_x | \
    ila_RAM_x == hls_LB1D_p_cnt \
) } -update_db;

# RAM_y
assert -name {eq - RAM_y} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_RAM_y == hls_LB2D_proc_y \
) } -update_db;

# RAM_w
assert -name {eq - RAM_w} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> (\
    ila_RAM_w == hls_LB2D_proc_w \
) } -update_db;

# stencil
assert -name {eq - stencil_0} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_0 == hls_LB2D_shift_0 \
) } -update_db;
#
assert -name {eq - stencil_1} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_1 == hls_LB2D_shift_1 \
) } -update_db;
#
assert -name {eq - stencil_2} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_2 == hls_LB2D_shift_2 \
) } -update_db;
#
assert -name {eq - stencil_3} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_3 == hls_LB2D_shift_3 \
) } -update_db;
#
assert -name {eq - stencil_4} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_4 == hls_LB2D_shift_4 \
) } -update_db;
#
assert -name {eq - stencil_5} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_5 == hls_LB2D_shift_5 \
) } -update_db;
#
assert -name {eq - stencil_6} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_6 == hls_LB2D_shift_6 \
) } -update_db;
#
assert -name {eq - stencil_7} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_stencil_7 == hls_LB2D_shift_7 \
) } -update_db;

# arg_0_TDATA
assert -name {eq - arg_0_TDATA} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_arg_0_TDATA == hls_arg_0_TDATA \
) } -update_db;

# RAM
assert -name {eq - RAM_0} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.RAM_0 == hls_LB2D_proc_0 \
) } -update_db;
#
assert -name {eq - RAM_1} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.RAM_1 == hls_LB2D_proc_1 \
) } -update_db;
#
assert -name {eq - RAM_2} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.RAM_2 == hls_LB2D_proc_2 \
) } -update_db;
#
assert -name {eq - RAM_3} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.RAM_3 == hls_LB2D_proc_3 \
) } -update_db;
#
assert -name {eq - RAM_4} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.RAM_4 == hls_LB2D_proc_4 \
) } -update_db;
#
assert -name {eq - RAM_5} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.RAM_5 == hls_LB2D_proc_5 \
) } -update_db;
#
assert -name {eq - RAM_6} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.RAM_6 == hls_LB2D_proc_6 \
) } -update_db;
#
assert -name {eq - RAM_7} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.RAM_7 == hls_LB2D_proc_7 \
) } -update_db;
#
