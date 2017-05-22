# Assertions for proving equivalence between two ILA
#
# instructions terminate
#assert -name {terminate} \
{ (counter > 1) |-> (a_complete == 0) | (b_complete == 0) \
} -update_db;

assert -name {bound} \
{ phase == 1 |-> counter < 12 \
} -update_db;

# equivalence on arch states
# arg_1_TREADY
assert -name {eq - arg_1_TREADY} \
{ (phase == 1 & counter < 12) |-> ( \
    a_arg_1_TREADY == b_arg_1_TREADY \
) } -update_db;

# arg_0_TVALID
assert -name {eq - arg_0_TVALID} \
{ (phase == 1 & counter < 12) |-> ( \
    a_arg_0_TVALID == b_arg_0_TVALID \
) } -update_db;

# RAM_x
assert -name {eq - RAM_x} \
{ (phase == 1 & counter < 12) |-> ( \
    a_RAM_x == b_LB2D_proc_x | \
    a_RAM_x == b_LB1D_p_cnt \
) } -update_db;

# RAM_y
assert -name {eq - RAM_y} \
{ (phase == 1 & counter < 12) |-> ( \
    a_RAM_y == b_LB2D_proc_y \
) } -update_db;

# RAM_w
assert -name {eq - RAM_w} \
{ (phase == 1 & counter < 12) |-> ( \
    a_RAM_w == b_LB2D_proc_w \
) } -update_db;

# cur_pix
assert -name {eq - cur_pix} \
{ (phase == 1 & counter < 12) |-> ( \
    a_cur_pix == b_LB1D_in \
) } -update_db;

# stencil
assert -name {eq - stencil_0} \
{ (phase == 1 & counter < 12) |-> ( \
    a_stencil_0 == b_LB2D_shift_0 \
) } -update_db;
#
assert -name {eq - stencil_1} \
{ (phase == 1 & counter < 12) |-> ( \
    a_stencil_1 == b_LB2D_shift_1 \
) } -update_db;
#
assert -name {eq - stencil_2} \
{ (phase == 1 & counter < 12) |-> ( \
    a_stencil_2 == b_LB2D_shift_2 \
) } -update_db;
#
assert -name {eq - stencil_3} \
{ (phase == 1 & counter < 12) |-> ( \
    a_stencil_3 == b_LB2D_shift_3 \
) } -update_db;
#
assert -name {eq - stencil_4} \
{ (phase == 1 & counter < 12) |-> ( \
    a_stencil_4 == b_LB2D_shift_4 \
) } -update_db;
#
assert -name {eq - stencil_5} \
{ (phase == 1 & counter < 12) |-> ( \
    a_stencil_5 == b_LB2D_shift_5 \
) } -update_db;
#
assert -name {eq - stencil_6} \
{ (phase == 1 & counter < 12) |-> ( \
    a_stencil_6 == b_LB2D_shift_6 \
) } -update_db;
#
assert -name {eq - stencil_7} \
{ (phase == 1 & counter < 12) |-> ( \
    a_stencil_7 == b_LB2D_shift_7 \
) } -update_db;

# arg_0_TDATA
assert -name {eq - arg_0_TDATA} \
{ (phase == 1 & counter < 12) |-> ( \
    a_arg_0_TVALID == 1 & b_arg_0_TVALID == 1) |-> ( \
    a_arg_0_TDATA == b_arg_0_TDATA \
) } -update_db;

# RAM
assert -name {eq - RAM_0} \
{ (phase == 1 & counter < 12) |-> ( \
    ila_a.RAM_0 == ila_b.LB2D_proc_0 \
) } -update_db;
#
assert -name {eq - RAM_1} \
{ (phase == 1 & counter < 12) |-> ( \
    ila_a.RAM_1 == ila_b.LB2D_proc_1 \
) } -update_db;
#
assert -name {eq - RAM_2} \
{ (phase == 1 & counter < 12) |-> ( \
    ila_a.RAM_2 == ila_b.LB2D_proc_2 \
) } -update_db;
#
assert -name {eq - RAM_3} \
{ (phase == 1 & counter < 12) |-> ( \
    ila_a.RAM_3 == ila_b.LB2D_proc_3 \
) } -update_db;
#
assert -name {eq - RAM_4} \
{ (phase == 1 & counter < 12) |-> ( \
    ila_a.RAM_4 == ila_b.LB2D_proc_4 \
) } -update_db;
#
assert -name {eq - RAM_5} \
{ (phase == 1 & counter < 12) |-> ( \
    ila_a.RAM_5 == ila_b.LB2D_proc_5 \
) } -update_db;
#
assert -name {eq - RAM_6} \
{ (phase == 1 & counter < 12) |-> ( \
    ila_a.RAM_6 == ila_b.LB2D_proc_6 \
) } -update_db;
#
assert -name {eq - RAM_7} \
{ (phase == 1 & counter < 12) |-> ( \
    ila_a.RAM_7 == ila_b.LB2D_proc_7 \
) } -update_db;

