# Assumptions for proving read instruction -- ILA
#
# initialization condition for read instruction -- ILA
assume -name {ILA init start} -env \
{ (counter < 5) |-> (ila_exec == 0) \
} -type {temporary} -update_db;

assume -name {ILA init stop} -env \
{ (counter >= 5) |-> (ila_exec == 1) \
} -type {temporary} -update_db;

# execution -- ILA
assume -name {ILA start} -env \
{ (ila_exec == 0) |=> (ila_complete == 0) \
} -type {temporary} -update_db;

# terminating condition -- ILA
assume -name {ILA continue} -env \
{ (ila_exec == 1) |-> ( \
    (counter == 5) |=> (ila_complete == 0) \
) } -type {temporary} -update_db;

assume -name {ILA break} -env \
{ (ila_exec == 1) |-> ( \
    (counter != 5) |=> (ila_complete == 1) \
) } -type {temporary} -update_db;

