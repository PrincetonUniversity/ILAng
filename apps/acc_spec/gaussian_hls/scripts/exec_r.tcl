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

