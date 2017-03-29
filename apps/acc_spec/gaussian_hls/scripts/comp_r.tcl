# Assumptions for proving write instruction 
# Compositional verification: decode, invariant, ...
#
# decode 
assume -name {comp - decode} -env \
{ counter == 0 |=> ( \
    arg_1_TVALID == 0 & \
    arg_0_TREADY == 1 & \
    ila_arg_0_TVALID == 1 & \
    hls_arg_0_TVALID == 1 \
)} -type {temporary} -update_db;

assume -name {comp - protocol} -env \
{ counter == 0 |-> ( \
    ila_arg_0_TVALID == 1 & \
    hls_arg_0_TVALID == 1 \
)} -type {temporary} -update_db;


