# Prove EQ for conf_done 
# Abstraction: RBM
# work with Vtop_RBM.v


assert -name {rdlc-case1} \
{ \
    (( acc_0.state_rbm_0_cmos32soi_rbm_load[0] == 1 ) &&  \
    ( acc_0.init_done == 1) && \
    ( acc_0.train_done == 0) && \
    ( 
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
    GM.wr_length == acc_0.wr_length && 
    ( (  (acc_0.ctrlAnd_1_ln550_z == 1) && (GM.index == 0) )  ||  ( (acc_0.ctrlAnd_1_ln550_z != 1)  && (GM.index == acc_0.mux_dma_index_ln637_q )) ) &&
    (GM.upc == 0) &&
    GM_step == 1
    ) ##1  (acc_0.state_rbm_0_cmos32soi_rbm_load[2] == 1) ) \
    |-> \
    ( \
        GM.rd_index == acc_0.rd_index && 
        GM.rd_length == acc_0.rd_length && 
        GM.rd_request == acc_0.rd_request \
)} -update_db;



assert -name {rdlc-case2} \
{ \
    (( acc_0.state_rbm_0_cmos32soi_rbm_load[0] == 1 ) &&  \
    ( acc_0.init_done == 1) && \
    ( acc_0.train_done == 0) && \
    ( 
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
    ) ##1 ( acc_0.state_rbm_0_cmos32soi_rbm_load[1] == 1 &&
    GM_step == 1 &&
    ( (  (acc_0.ctrlAnd_1_ln550_z == 1) && (GM.index == 0) )  ||  ( (acc_0.ctrlAnd_1_ln550_z != 1)  && (GM.index == acc_0.mux_dma_index_ln637_q )) ) &&
    (GM.upc == 0) 
    ) \
    ##1 (acc_0.state_rbm_0_cmos32soi_rbm_load[2] == 1) ) \
    |-> \
    ( \
        GM.rd_index == acc_0.rd_index && 
        GM.rd_length == acc_0.rd_length && 
        GM.rd_request == acc_0.rd_request \
)} -update_db;


# register assignment
# (also for parent assignment)
#    //GM.rd_complete == acc_0.rd_complete && 

# lacking memory related staffs
# lacking interleaved instructions
