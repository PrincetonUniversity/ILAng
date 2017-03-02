
assume -name {::Initial Condition} -env \
{rst |-> ( \
        init_arg_0_TDATA == 0 & \
        init_arg_0_TVALID == 0 \
        )} \
-type {temporary} \
-annotation {Set up initial condition when rst is raised} \
-update_db;

assert -name {<embedded>::Test Property 1} \
{arg_0_TVALID |-> \
    p_p2_in_bounded_stencil_stream_full == 0} \
-annotation {Check if output valid then stencil is empty} \
-update_db;

