
assume -name {::hls_block_rst} -env {ap_rst_n == 1} -type {temporary} -annotation {Block reset effect} -update_db;

assume -name {::::hls_init_state} -env {eqcheck_init |-> (
        arg_1_TVALID == 1 & 
        arg_0_TREADY == 0 &
        arg_0_TVALID == 0
        )} -type {temporary} -annotation {Use eqcheck_init to set inital condition for states and input ports} -update_db -replace;

assume -name {::hls_exec_state} -env {!eqcheck_init |-> (
        arg_1_TVALID == 0 &
        arg_0_TREADY == 0
        )} -type {temporary} -annotation {Block input ports (cmd) when executing} -update_db;

assert -name {<embedded>::hls_prop_0} {arg_0_TVALID == 0} -annotation {Test if output valid can be true} -update_db;
