# Assertions for proving equivalence between ILA ans HLS
#
assert -clear;
# arg_0_TVALID
assert -name {:arg_0_TVALID} \
{ ((cnt_init == 2) & (ila_step == 0) & (hls_step == 0)) |-> ( \
    ila_arg_0_TVALID == hls_arg_0_TVALID 
)} -update_db;
