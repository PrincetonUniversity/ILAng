stopat acc_0.train_input_done



assume -name {nvnm} -env \
{
     acc_0.init_done |-> ( (acc_0.num_visible ==  (acc_0.num_movies<<2)+acc_0.num_movies) 
        && (acc_0.num_movies <= 16'h3333)
        && (acc_0.num_visible > 0)
        && (acc_0.num_hidden > 0)
        )
}

assume -name {global} -env \
{
     acc_0.init_done |-> (
    GM.num_hidden == acc_0.num_hidden &&  // gloabl
    GM.num_loops == acc_0.num_loops && 
    GM.num_movies == acc_0.num_movies && 
    GM.num_testusers == acc_0.num_testusers && 
    GM.num_users == acc_0.num_users && 
    GM.num_visible == acc_0.num_visible )
}

assume -name {cycle1-decode} \
{
    nondet_start |-> (
        acc_0.init_done == 1 &&  // decode
        acc_0.train_input_done == 1 &&
        GM.init_done == 1 &&
        GM.train_upc == 0 &&
        GM.upc == 2 && GM.train_input_done == 1 && acc_0.train_input_done == 1 &&
        GM.per_v_pc == 0 && GM.jstate == 0 &&
         acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[90] == 1'b1 && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[89:0] == 0 && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[94:91] == 0 
)}

assume -name {cycle1-match}  \
{
    start |-> (
        GM.train_h_cnt == acc_0.mux_h_ln184_z && // signal match
        GM.train_v_cnt == acc_0.mux_v_ln191_z &&
        GM.train_sum == acc_0.mux_sum_ln191_z 
    )
}



assume -name {next_step} -env \
{
    GM_step == ((started & ~finished) && 
        (( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[89] && ~acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[9] ) || 
         ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[90] && ~start_1d) ||
         ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[9]) ) )
}

assume -name {state2pc} -env \
{
    GM_step |-> (
        state_to_pc == (
            ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[89] && ~acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[9] && state_to_pc == 0) ||
            ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[90] && ~start_1d &&  state_to_pc == 0 ) ||
            ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[9] && state_to_pc == 1)
        )
    )
}

assume -name {finish_sig} -env \
{
    finish_signal == GM_step_1d
}

# memory staffs
assume -name {write_sel} {GM_pd_or_tr == 1 && GM_hidden_unit_compare == finish && GM_hidden_unit_rec == in_term}

assume -name {read_match_pre} {
    start |-> ( ( load_addr == data_A0 ) ##1 ( load_data == data_D0 ) )
}

assume -name {read_match_post} {
   ( GM_step &&  ( load_addr ==  GM_data_raddr0 ) ) |-> ( load_data == GM_data_rdata0 ) 
}

stopat acc_0.mti_signal_d
assume -name {rand_blackbox} {
    1
}

assert -name {check} \
{
    finish |-> (
        (
            (GM.train_h_cnt == acc_0.mux_v_ln191_z &&
             GM.train_v_cnt == acc_0.mux_h_ln184_z )  
        ||  (GM.train_h_cnt == 0 &&
             GM.train_v_cnt == 0 ) 
        )
        && ( GM.train_sum == acc_0.mux_sum_ln191_z ) 
        //&& ( ~ GM_hidden_unit_mismatch ) 
        && (GM.train_upc == state_to_pc )

        )
}