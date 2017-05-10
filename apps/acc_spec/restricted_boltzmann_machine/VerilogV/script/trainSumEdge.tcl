stopat acc_0.train_input_done

# prelog: 20->21->56
# 56 -> ... 59(next 56)
# 56 -> ... 22->21 (next=56)
# 56 -> ... 22->21 (next=22)

# hidden_read (next=56)
# edges_read (56)
# visibleEnergies_write(59,next=22)
# h_cnt : newvalue@56
# v_cnt : newvalue@20
# j : newvalue@(next=56)


assume -name {nvnm} -env \
{
     acc_0.init_done |-> ( (acc_0.num_visible ==  (acc_0.num_movies<<2)+acc_0.num_movies) // 5x relationship
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

assume -name {onehot-enc} -env \
{
    $onehot(acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next) && $onehot(acc_0.state_rbm_0_cmos32soi_rbm_train_rbm)
}

assume -name {ndstart-1} -env \
{
    (
        GM.jstate == acc_0.mux_j_ln290_z 
    ) ##1 start
}

assume -name {cycle1-decode} \
{
    nondet_start |-> (
        acc_0.init_done == 1 &&  // decode
        acc_0.train_input_done == 1 &&
        GM.init_done == 1 &&
        GM.train_upc == 1 &&
        GM.upc == 2 && GM.train_input_done == 1 && acc_0.train_input_done == 1 &&
        GM.per_v_pc == 0  &&
         acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[56] == 1'b1 && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[89:0] == 0 && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[94:91] == 0 
)}

assume -name {cycle1-match}  \
{
    start |-> (
        GM.train_h_cnt == acc_0.mux_h_ln294_z && // signal match
        GM.train_v_cnt == acc_0.mux_v_ln282_q &&
        GM.train_sum == acc_0.mux_sum_ln294_z
    )
}



assume -name {next_step} -env \
{
    GM_step == ((started & ~finished) && 
        (( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[59] && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[56] ) || 
         ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[21] && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[56] ) ||
         ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[21] && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[22] )
        )  
    )
}

assume -name {state2pc} -env \
{
    GM_step |-> (
        state_to_pc == (
            ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[59] && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[56] && state_to_pc0 == 1 && state_to_pc1 == 0) ||
            ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[21] && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[56] && state_to_pc0 == 1 && state_to_pc1 == 0) ||
            ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[21] && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[22] && state_to_pc0 == 1 && state_to_pc1 == 1)
        )
    )
}

assume -name {finish_sig} -env \
{
    finish_signal == GM_step_1d
}

# memory staffs
assume -name {write_sel} {
    GM_pd_or_tr == 1 && GM_visibleEngeries_compare == finish && GM_visibleEngeries_rec == in_term &&
    GM_hidden_unit_rec == in_term &&
    GM_edges_rec == in_term
}

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
            (GM.train_h_cnt == acc_0.mux_v_ln282_q &&
             GM.train_v_cnt == acc_0.mux_h_ln294_z )  
        ||  (GM.train_h_cnt == 0 &&
             GM.train_v_cnt == 0 ) 
        )
        && ( GM.train_sum == acc_0.mux_sum_ln294_z ) 
        && ( GM.jstate == acc_0.mux_j_ln290_z )
        && ( ~ GM_visibleEnergies_mismatch ) 
        && (GM.train_upc == state_to_pc0 )
        && (GM.per_v_pc  == state_to_pc1 ||  GM.per_v_pc == 0)

        )
}