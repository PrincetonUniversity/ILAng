# Prove EQ for conf_done 
# Abstraction: RBM
# work with Vtop_RBM.v

assume -name {RBM_read_grant_cond} -env \
{
    finish_signal == ( acc_0.state_rbm_0_cmos32soi_rbm_load[3] == 1 )
} -type {temporary} -update_db;

assume -name {RBM_read_grant_start} -env \
{
    nondet_start |-> ( acc_0.state_rbm_0_cmos32soi_rbm_load[2] == 1 )
} -type {temporary} -update_db;

assume -name {RBM_read_grant_assume} -env \
{  start |-> ( 
    conf_done == 0 && 
    rst == 0 && 
    acc_0.init_done == 1 && 
    (rd_grant & acc_0.rd_request) &&
    ~(wr_grant & acc_0.wr_request) &&
    GM.data_out ==  acc_0.data_out_data && 
    GM.done  == acc_0.done && 
    GM.init_done == acc_0.init_done && 
    GM.num_hidden == acc_0.num_hidden && 
    GM.num_loops == acc_0.num_loops && 
    GM.num_movies == acc_0.num_movies && 
    GM.num_testusers == acc_0.num_testusers && 
    GM.num_users == acc_0.num_users && 
    GM.num_visible == acc_0.num_visible && 
    GM.rd_index == acc_0.rd_index && 
    GM.rd_length == acc_0.rd_length && 
    GM.rd_request == acc_0.rd_request && 
    GM.wr_index == acc_0.wr_index && 
    GM.wr_request == acc_0.wr_request
)} -type {temporary} -update_db;

assume -name {RBM_read_grant_step} -env \
{
    ( GM_step == 1  ) |=> finish
} -type {temporary} -update_db;

assert -name {RBM_read_grant_check} \
{ \
    finish |-> ( \
    GM.init_done == acc_0.init_done && \
    GM.done == acc_0.done && \
    GM.num_hidden == acc_0.num_hidden && \
    GM.num_visible == acc_0.num_visible && \
    GM.num_users == acc_0.num_users && \
    GM.num_loops == acc_0.num_loops && \
    GM.num_testusers == acc_0.num_testusers && \
    GM.num_movies == acc_0.num_movies && \
    GM.rd_index == acc_0.rd_index && \
    GM.rd_length == acc_0.rd_length && \
    GM.rd_request == acc_0.rd_request && \
    GM.wr_request == acc_0.wr_request && \
    GM.wr_index == acc_0.wr_index && \
    GM.wr_length == acc_0.wr_length && \
    GM.data_out == acc_0.data_out_data && \
    (GM_data_mismatch == 1'b0 ) && \
    (GM_predict_result_mismatch == 1'b0) && \
    GM.data_out ==  acc_0.data_out_data && \
    (mem_data.GM_dirty == 1'b1) \
    ) } -update_db;
    


# decode
# register assignment
# (also for parent assignment)
#    //GM.rd_complete == acc_0.rd_complete && 

# lacking memory related staffs
# lacking interleaved instructions
