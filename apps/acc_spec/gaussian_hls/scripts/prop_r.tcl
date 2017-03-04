# Assertions for proving equivalence between ILA ans HLS
#
assert -clear;

# both instructions terminate
assert -name {terminate} \
{( ((cnt_init == 1) & (ila_step == 0) & (hls_step == 0)) |-> \
    1 == 0 \
)} -update_db;

# arg_0_TVALID
assert -name {arg_0_TVALID} \
{ ((cnt_init == 1) & (ila_step == 0) & (hls_step == 0)) |-> ( \
    ila_arg_0_TVALID == hls_arg_0_TVALID \
)} -update_db;

# stencil_full
assert -name {stencil_full} \
{ ((cnt_init == 1) & (ila_step == 0) & (hls_step == 0)) |-> ( \
    ila_stencil_full == 0 \
)} -update_db;

# arg_0_TDATA
assert -name {arg_0_TDATA} \
{ ((cnt_init == 1) & (ila_step == 0) & (hls_step == 0)) |-> ( \
    ila_arg_0_TDATA == hls_arg_0_TDATA \
)} -update_db;

assert -name {test} \
{ \
    cnt_init == 1 |-> ila_complete == 0 \
} -update_db;
