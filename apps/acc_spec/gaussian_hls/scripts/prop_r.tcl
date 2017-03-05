# Assertions for proving equivalence between ILA ans HLS
#

# both instructions terminate
assert -name {ILA terminate} \
{ (cnt_init == 1) |-> (ila_complete == 0) \
} -update_db;

assert -name {HLS terminate} \
{ (cnt_init == 1) |-> (hls_complete == 0) \
} -update_db;

# arg_0_TVALID
assert -name {arg_0_TVALID} \
{ (cnt_init & ila_complete & hls_complete) |-> ( \
    ila_arg_0_TVALID == hls_arg_0_TVALID \
)} -update_db;

# stencil_full
assert -name {stencil_full} \
{ (cnt_init & ila_complete & hls_complete) |-> ( \
    ila_stencil_full == 0 \
    & (hls_target_U.p_p2_in_bounded_stencil_stream_s_U.internal_full_n == 1) \
    & (hls_target_U.p_p2_in_bounded_stencil_stream_s_U.internal_empty_n == 0) \
)} -update_db;

# arg_0_TDATA
assert -name {arg_0_TDATA} \
{ (cnt_init & ila_complete & hls_complete) |-> ( \
    ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -update_db;

# check fsm
assert -name {sanity - fsm_st_1} \
{ (cnt_init & ila_complete & hls_complete) |-> ( \
    (hls_target_U.hls_target_Loop_1_proc_U0.ap_CS_fsm == 2) \
)} -update_db;

# check micro states
assert -name {sanity - u states} \
{ (cnt_init & ila_complete & hls_complete) |-> ( \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it0 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it1 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it2 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it3 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it4 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it5 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it6 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it7 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it8 == 1 & \
    hls_target_U.hls_target_Loop_1_proc_U0.ap_reg_ppiten_pp0_it9 == 1 \
)} -update_db;

