# Assumptions for proving read instruction -- ILA
#
assume -clear -env
assert -clear
# initialization condition for read instruction -- ILA
assume -name {ILA init start} -env \
{ (counter < 1) |-> (ila_exec == 0) \
} -type {temporary} -update_db;

assume -name {ILA init stop} -env \
{ (counter >= 1) |-> (ila_exec == 1) \
} -type {temporary} -update_db;

# execution -- ILA
assume -name {read instr ILA start} -env \
{ (ila_exec == 0) |=> (ila_complete == 0) \
} -type {temporary} -update_db;

# terminating condition -- ILA
assume -name {read instr ILA continue} -env \
{ (ila_exec == 1) |-> ( \
    #(counter == 1) |=> (ila_complete == 0) \ 
    (ila_target_U.arg_0_TVALID == 1) |=> (ila_complete == 1) \
) } -type {temporary} -update_db;

assume -name {read instr ILA break} -env \
{ (ila_exec == 1) |-> ( \
    #(counter != 1) |=> (ila_complete == 1) \ 
    (ila_target_U.arg_0_TVALID == 0) |=> (ila_complete == 1) \
) } -type {temporary} -update_db;

# test
#
assume -env \
{ ( \
    arg_0_TREADY == 1 & \
    arg_1_TVALID == 0 \
) } -type {temporary} -update_db;

assume -env \
{ (ila_exec == 0) |=> (ila_target_U.arg_0_TVALID == 1) \
} -type {temporary} -update_db;

assert \
{ (ila_exec == 1 & ila_complete == 1) |-> ( \
    ila_target_U.arg_0_TVALID == 1 \
) } -update_db;
    
assert \
{ (ila_exec == 1 & ila_complete == 1) |-> ( \
    ila_target_U.arg_0_TVALID == 0 \
) } -update_db;
