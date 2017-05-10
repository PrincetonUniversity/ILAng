# Prove EQ for conf_done 
# Abstraction: RBM
# work with Vtop_RBM.v


assume -name {DMA_load_start} -env \
{
    nondet_start |->  (acc_0.state_rbm_0_cmos32soi_rbm_load[14] == 1) 
}  -type {temporary} -update_db;

assume -name {DMA_load_finish} -env \
{
    finish_signal == GM_step_1d
} -type {temporary} -update_db;



assume -name {nvnm} -env \
{
    acc_0.init_done |-> ( (acc_0.num_visible ==  (acc_0.num_movies<<2)+acc_0.num_movies) && (acc_0.num_movies <= 16'h3333))
}

assume -name {DMA_load_step} -env \
{
    ( GM_step == 1  ) == (acc_0.state_rbm_0_cmos32soi_rbm_load[15] == 1) 
} -type {temporary} -update_db;


assume -name {step_correct} -env \
{
    GM_step |-> (
    GM.num_hidden == acc_0.num_hidden && 
    GM.num_loops == acc_0.num_loops && 
    GM.num_movies == acc_0.num_movies && 
    GM.num_testusers == acc_0.num_testusers && 
    GM.num_users == acc_0.num_users && 
    GM.num_visible == acc_0.num_visible &&
    GM.data_out ==  acc_0.data_out_data && 
    GM.done  == acc_0.done && 
    GM.init_done == acc_0.init_done && 
    GM.rd_index == acc_0.rd_index && 
    GM.rd_length == acc_0.rd_length && 
    GM.rd_request == acc_0.rd_request && 
    GM.wr_request == acc_0.wr_request && 
    GM.wr_index == acc_0.wr_index && 
    GM.wr_length == acc_0.wr_length 
    )
}  -type {temporary} -update_db;
 
assume -name {assI} -env {
    start |->  (GM.i == acc_0.mux_mux_i_ln585_Z_v  \
        )
} -type {temporary} -update_db;


cover -name {start} {
    start
} -update_db;

cover -name {finish} {
    start |-> ##[1:$] finish
} -update_db;


assert -name {DMA_load_step_assert} \
{
    finish |-> ( \
    GM.i == acc_0.mux_mux_i_ln585_Z_v && \
    (GM_data_mismatch == 0) ) \
}

# register assignment
# (also for parent assignment)
#    //GM.rd_complete == acc_0.rd_complete && 

# lacking memory related staffs
# lacking interleaved instructions
