# Assumptions for proving read instruction -- ILA
#
# initial state for read instruction -- ILA.
assume -name {ILA start} -env \
{ (cnt_init == 0) |=> (ila_complete == 0) \
} -type {temporary} -update_db;

# terminating condition -- ILA
assume -name {read instr ILA continue} -env \
{ (cnt_init == 1) |-> \
    ((ila_stencil_full == 1) |=> (ila_complete == 0)) \
} -type {temporary} -update_db;

assume -name {read instr ILA break} -env \
{ (cnt_init == 1) |-> \
    ((ila_stencil_full == 0) |=> (ila_complete == 1)) \
} -type {temporary} -update_db;

