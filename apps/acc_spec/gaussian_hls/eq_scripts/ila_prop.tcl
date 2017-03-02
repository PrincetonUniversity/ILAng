
assume -name {:ila_set_init} -env \
{(init_counter == 1 | init_counter == 0) |-> ( \
        arg_1_TVALID == 1 & \
        p_p2_in_bounded_stencil_stream_full == 0 & \
        slice_stream_V_value_V_U_internal_full_n == 0 \
        )} \
-type {temporary} -update_db;

assume -name {:ila_block_reset} -env {rst == 0} -type {temporary} -update_db;

assume -name {:ila_remove_cmd} -env \
{(init_counter == 2) |-> ( \
        arg_1_TVALID == 0
        )} \
-type {temporary} -update_db;

assert -name {:ila_prop_0} \
{(init_counter == 2) |-> ( \
        slice_stream_V_value_V_U_internal_full_n == 0
        )} \
-update_db;        

