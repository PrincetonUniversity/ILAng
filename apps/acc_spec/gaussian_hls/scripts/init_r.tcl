# Assumptions initial condition
#
# micro-states
# axi config
assume -name {init - axi config} -env \
{ counter == 0 |=> ( \
    hls_U.hls_target_linebuffer_1_U0.hls_target_linebuffer_Loop_1_proc_U0.ap_done_reg == 0 \
)} -type {temporary} -update_db;

# stable fsm
assume -name {init - stable fsm pre} -env \
{ counter == 0 |=> ( \
    hls_LB1D_fsm == 2 & \
    hls_LB2D_proc_fsm == 4 & \
    hls_LB2D_shift_fsm == 4 & \
    hls_GB_fsm == 2 \
)} -type {temporary} -update_db;
#
assume -name {init - stable fsm post} -env \
{ counter == 0 |-> ( \
    hls_LB2D_shift_fsm == 4 \
)} -type {temporary} -update_db;
