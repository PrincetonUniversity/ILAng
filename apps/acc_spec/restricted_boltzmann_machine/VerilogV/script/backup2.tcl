stopat acc_0.train_input_done
stopat acc_0.mti_signal

cover -name {forln65} {
    acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[90] ##1 acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[91] ##1 acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[92]  ##1 acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[90]
}
cover -name {forln656} {
    (   acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[90] == 1 && 
        acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[89:0] == 0 &&
        acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[94:91] == 0  ) ##1 acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[90] ##1 acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[91] ##1 acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[92]  ##1 acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[90]
}



assume -name {nvnm} -env \
{
     ( (acc_0.num_visible ==  (acc_0.num_movies<<2)+acc_0.num_movies) && (acc_0.num_movies <= 16'h3333))
}

assume -name {global} -env \ 
{
    GM.num_hidden == acc_0.num_hidden && 
    GM.num_loops == acc_0.num_loops && 
    GM.num_movies == acc_0.num_movies && 
    GM.num_testusers == acc_0.num_testusers && 
    GM.num_users == acc_0.num_users && 
    GM.num_visible == acc_0.num_visible 
}

assume -name {init_done} -env \
{
    cycle1 |-> ( (

    acc_0.init_done == 1 && // decode
    GM.init_done == 1 &&

    GM.train_upc == 0 &&
    GM.upc == 2 && GM.train_input_done == 1 && acc_0.train_input_done == 1 &&
    GM.per_v_pc == 0 && GM.jstate == 0 &&

    // start condition
    acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[90] == 1'b1 && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[89:0] == 0 && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[94:91] == 0 &&

    GM.train_h_cnt == acc_0.mux_v_ln191_z &&
    GM.train_v_cnt == acc_0.mux_h_ln184_z &&
    GM.train_sum == acc_0.mux_sum_ln191_z &&

    nondet_start == 1

    ) )
}

assume -name {step} -env \
{
    GM_step == (started & ~finished) && 
        (( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[89] && ~acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[9] ) || 
         ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[90] && ~start_1d) ||
         ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[9]) )
}

assume -name {finish} -env \
{
    finish_signal == GM_step_1d
}

assume -name {write_sel} {GM_pd_or_tr == 1 && GM_hidden_unit_compare == finish && GM_hidden_unit_rec == in_term}

assume -name {read_match_pre} {
    start |-> ( ( load_addr == data_A0 ) ##1 ( load_data == data_D0 ) )
}

assume -name {read_match_post} {
   ( GM_step &&  ( load_addr ==  GM_data_raddr0 ) ) |-> ( load_data == GM_data_rdata0 ) 
}

assert -name {check} \
{
    finish |-> (
        GM.train_h_cnt == acc_0.mux_v_ln191_z &&
        GM.train_v_cnt == acc_0.mux_h_ln184_z &&
        GM.train_sum == acc_0.mux_sum_ln191_z &&
        //(~ GM_hidden_unit_mismatch) &&
        (1)
        )
}
