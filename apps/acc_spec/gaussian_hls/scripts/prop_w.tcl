# Assertions for proving equivalence between ILA and HLS
#
# instructions terminate
assert -name {terminate - ila} \
{ (counter > 1) |-> (ila_complete == 0) \
} -update_db;
# 
assert -name {terminate - hls} \
{ (counter > 1) |-> (hls_step == 0) \
} -update_db;

# equivalence on arch states
# arg_1_TREADY
assert -name {equivalence - arg_1_TREADY} \
{ (counter > 1 & ila_complete == 1 & hls_complete == 1) |-> ( \
    ila_U.arg_1_TREADY == hls_U.arg_1_TREADY \
) } -update_db;

assert -name {eq wait - arg_1_TREADY} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_U.arg_1_TREADY == hls_U.arg_1_TREADY \
) } -update_db;

assert -name {eq wait - arg_0_TVALID} \
{ (counter > 1 & ila_complete == 1 & hls_step == 0) |-> ( \
    ila_U.arg_0_TVALID == hls_U.arg_0_TVALID \
) } -update_db;

#assert { \
    counter > 1 |-> ( \
        hls_arg_0_TVALID == 0) \
}

#assert { counter > 1 & hls_step == 0 |-> hls_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 2 }
