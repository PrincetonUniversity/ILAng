# Assumptions for proving read instruction -- ILA
#
# initial state for read instruction -- ILA.
assume -name {:read instr ILA init} -env \
{(cnt_init == 1) |-> ( \
    # input
    ila_step == 1           & \
    arg_0_TREADY == 1       & \
    arg_1_TDATA == 0        & \
    arg_1_TVALID == 0       & \
    # states
    ila_arg_0_TDATA == 0    & \
    ila_arg_0_TVALID == 0   & \
    ila_arg_1_TREADY == 1   & \
    ila_stencil_full == 1   \
    # LB2D buff, x/y/w index, stencil buff, slice buff, slice full
)} -type {temporary} -update_db;

# invariant state for read instruction -- ILA.
assume -name {:read instr ILA invariant} -env \
{ \
    rst == 0            & \
    arg_1_TVALID == 0   & \
    arg_0_TREADY == 1   \
} -type {temporary} -update_db;

# terminating condition -- ILA
assume -name {:read instr ILA terminate} -env \
{ \
    (cnt_init == 2) |-> (ila_step == 1) \
} -type {temporary} -update_db;
