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

