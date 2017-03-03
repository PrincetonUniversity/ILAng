# Assertions for proving equivalence between ILA ans HLS
#
assert -clear;
# arg_0_TVALID
assert -name {:arg_0_TVALID} \
{ ((cnt_init == 2) & (ila_step == 1) & (hls_step == 0)) |-> ( \
    ila_arg_0_TVALID == hls_arg_0_TVALID & \
    ila_arg_0_TVALID == 1 \
)} -update_db;

# arg_0_TDATA
assert -name {:arg_0_TDATA} \
{ ((cnt_init == 2) & (ila_step == 0) & (hls_step == 0)) |-> ( \
    ila_arg_0_TDATA == hls_arg_0_TDATA & \
    ila_arg_0_TVALID == 0
)} -update_db;

