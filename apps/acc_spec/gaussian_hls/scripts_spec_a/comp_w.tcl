# Assumptions for proving write instruction 
# Compositional verification: decode, invariant, ...
#
# decode 
assume -name {comp - decode} -env \
{ counter == 0 |=> ( \
    arg_1_TVALID == 1 & \
    arg_0_TREADY == 0 & \
    ila_arg_1_TREADY == 1 & \
    hls_arg_1_TREADY == 1 \
)} -type {temporary} -update_db;

