# Assumptions for proving read instruction 
# Execute: start and stop models
#
# start
assume -name {exec - start model} -env \
{ counter <= 2 |-> ( \
    hls_complete == 0 & \
    ila_complete == 0 \
)} -type {temporary} -update_db;

# stop
assume -name {exec - ila continue} -env \
{ (counter > 1) |-> ( \
    (ila_arg_0_TVALID == 1 & \
     arg_1_TVALID == 0 & \
     arg_0_TREADY == 1) \
    |=> \
    (ila_complete == 0) \
)} -type {temporary} -update_db;
#
assume -name {exec - ila break} -env \
{ (counter > 1) |-> ( \
   ~( \
    (ila_arg_0_TVALID == 1 & \
     arg_1_TVALID == 0 & \
     arg_0_TREADY == 1) \
    ) \
    |=> \
    (ila_complete == 1) \
)} -type {temporary} -update_db;
#
assume -name {exec - hls continue} -env \
{ (counter > 1) |-> ( \
    (hls_arg_0_TVALID == 1 & \
     arg_1_TVALID == 0 & \
     arg_0_TREADY == 1) \
    |=> \
    (hls_complete == 0) \
)} -type {temporary} -update_db;
#
assume -name {exec - hls break} -env \
{ (counter > 1) |-> ( \
   ~( \
    (hls_arg_0_TVALID == 1 & \
     arg_1_TVALID == 0 & \
     arg_0_TREADY == 1) \
    ) \
    |=> \
    (hls_complete == 1) \
)} -type {temporary} -update_db;
