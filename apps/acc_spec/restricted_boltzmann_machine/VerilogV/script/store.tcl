# Prove EQ for conf_done 
# Abstraction: RBM
# work with Vtop_RBM.v


stopat acc_0.predict_done

assume -name {store_start} -env \
{
    nondet_start |->  (acc_0.state_rbm_0_cmos32soi_rbm_store_next[5] == 1) 
}  -type {temporary} -update_db;

assume -name {DMA_load_finish} -env \
{
    finish_signal == GM_step_1d
} -type {temporary} -update_db;



assume -name {nvnm} -env \
{
    acc_0.init_done |-> ( (acc_0.num_visible ==  (acc_0.num_movies<<2)+acc_0.num_movies) && (acc_0.num_movies <= 16'h3333))
}


assume -name {step_correct} -env \
{
    GM_step |-> (
    GM.num_hidden == acc_0.num_hidden && 
    GM.num_loops == acc_0.num_loops && 
    GM.num_movies == acc_0.num_movies && 
    GM.num_testusers == acc_0.num_testusers && 
    GM.num_users == acc_0.num_users && 
    GM.num_visible == acc_0.num_visible &&
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
    start |->  (GM.i == acc_0.mux_i_ln983_z  \
        )
} -type {temporary} -update_db;


cover -name {start} {
    start
} -update_db;

cover -name {finish} {
    start |-> ##[1:$] finish
} -update_db;


assume -name {iNotExceedLimit} {
    start |-> (acc_0.mux_i_ln983_z < 100)
}

assert -name {DMA_load_step_assert} \
{
    finish |-> ( \
    GM.i == oldi && \
    GM.data_out == acc_0.data_out_data ) \
}

# register assignment
# (also for parent assignment)
#    //GM.rd_complete == acc_0.rd_complete && 

# lacking memory related staffs
# lacking interleaved instructions
