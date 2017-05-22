# Assertions for proving equivalence between ILA and HLS
#
# instructions terminate
#assert -name {terminate} \
{ (counter > 1) |-> (hls_step == 1) | (ila_complete == 0) \
} -update_db;

assert -name {bound help 0} { counter == 0 |=> counter == 1 } -update_db;
assert -name {bound help 1} { counter == 1 |=> counter == 2 } -update_db;
assert -name {bound help 2} { counter == 2 |=> counter == 3 } -update_db;
assert -name {bound help 3} { counter == 3 |=> counter == 4 } -update_db;
assert -name {bound help 4} { counter == 4 |=> counter == 5 } -update_db;
assert -name {bound help 5} { counter == 5 |=> counter == 6 } -update_db;
assert -name {bound help 6} { counter == 6 |=> counter == 7 } -update_db;
assert -name {bound help 7} { counter == 7 |=> counter == 8 } -update_db;
assert -name {bound help 8} { counter == 8 |=> counter == 9 } -update_db;
assert -name {bound help 9} { counter == 9 |=> counter == 10 } -update_db;
assert -name {bound help 10} { counter == 10 |=> counter == 11 } -update_db;
assert -name {bound help 11} { counter == 11 |=> counter == 12 } -update_db;
assert -name {bound help 12} { counter == 12 |=> counter == 13 } -update_db;
assert -name {bound help 13} { counter == 13 |=> counter == 14 } -update_db;
assert -name {bound help 14} { counter == 14 |=> counter == 15 } -update_db;
assert -name {bound help 15} { counter == 15 |=> counter == 15 } -update_db;

assert -name {bound} \
{ phase == 1 |-> counter < 15 \
} -update_db;

# equivalence on arch states
# arg_1_TREADY
assert -name {eq - arg_1_TREADY} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.arg_1_TREADY == hls_U.arg_1_TREADY \
) } -update_db;

# arg_0_TVALID
assert -name {eq - arg_0_TVALID} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.arg_0_TVALID == hls_U.arg_0_TVALID \
) } -update_db;

# RAM_x
assert -name {eq - RAM_x} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_RAM_x == hls_LB2D_proc_x | \
    ila_RAM_x == hls_LB1D_p_cnt \
) } -update_db;

# RAM_y
assert -name {eq - RAM_y} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_RAM_y == hls_LB2D_proc_y \
) } -update_db;

# RAM_w
assert -name {eq - RAM_w} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_RAM_w == hls_LB2D_proc_w \
) } -update_db;

# cur_pix
assert -name {eq - cur_pix} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_cur_pix == hls_LB1D_buff \
) } -update_db;

# stencil
assert -name {eq - stencil_0} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_stencil_0 == hls_LB2D_shift_0 \
) } -update_db;
#
assert -name {eq - stencil_1} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_stencil_1 == hls_LB2D_shift_1 \
) } -update_db;
#
assert -name {eq - stencil_2} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_stencil_2 == hls_LB2D_shift_2 \
) } -update_db;
#
assert -name {eq - stencil_3} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_stencil_3 == hls_LB2D_shift_3 \
) } -update_db;
#
assert -name {eq - stencil_4} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_stencil_4 == hls_LB2D_shift_4 \
) } -update_db;
#
assert -name {eq - stencil_5} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_stencil_5 == hls_LB2D_shift_5 \
) } -update_db;
#
assert -name {eq - stencil_6} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_stencil_6 == hls_LB2D_shift_6 \
) } -update_db;
#
assert -name {eq - stencil_7} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_stencil_7 == hls_LB2D_shift_7 \
) } -update_db;

# arg_0_TDATA
assert -name {eq - arg_0_TDATA} \
{ (phase == 1 & counter < 15) |-> ( \
   ila_arg_0_TVALID == 1 & hls_arg_0_TVALID == 1) |-> ( \
    ila_arg_0_TDATA == hls_arg_0_TDATA \
) } -update_db;

# RAM
assert -name {eq - RAM_0} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.RAM_0 == hls_LB2D_proc_0 \
) } -update_db;
#
assert -name {eq - RAM_1} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.RAM_1 == hls_LB2D_proc_1 \
) } -update_db;
#
assert -name {eq - RAM_2} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.RAM_2 == hls_LB2D_proc_2 \
) } -update_db;
#
assert -name {eq - RAM_3} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.RAM_3 == hls_LB2D_proc_3 \
) } -update_db;
#
assert -name {eq - RAM_4} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.RAM_4 == hls_LB2D_proc_4 \
) } -update_db;
#
assert -name {eq - RAM_5} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.RAM_5 == hls_LB2D_proc_5 \
) } -update_db;
#
assert -name {eq - RAM_6} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.RAM_6 == hls_LB2D_proc_6 \
) } -update_db;
#
assert -name {eq - RAM_7} \
{ (phase == 1 & counter < 15) |-> ( \
    ila_U.RAM_7 == hls_LB2D_proc_7 \
) } -update_db;
#
