stopat acc_0.train_input_done
stopat acc_0.mti_signal

# prelog: 20->21->56
# 56 -> ... 59(next 56)
# 56 -> ... 22->21 (next=56)
# 56 -> ... 23 

# hidden_read (next=56)
# edges_read (56)
# visibleEnergies_write(59,next=22)
# h_cnt : newvalue@56
# v_cnt : newvalue@20
# j : newvalue@(next=56)

assume -name {aux} \
{
    cycles[0] |-> (
      acc_0.read_rbm_num_visible_ln687_d == {acc_0.num_loops, acc_0.num_users, 
          acc_0.num_hidden, acc_0.num_visible}
           )
}

assume -name {aux-2} \
{
    acc_0.num_hidden + 1 == {acc_0.add_ln713_1_q, !acc_0.read_rbm_num_hidden_ln688_q[0]}
}

assume -name {aux-3} \
{
    (acc_0.add_ln713_1_q == acc_0.num_movies)
    // && (acc_0.num_movies == 5) 
    // && (acc_0.num_hidden == 10) 
    // && (acc_0.num_loops == 2) 
    // && (acc_0.num_testusers == 2) 
    // && (acc_0.num_users == 2) 
    // && (acc_0.num_visible == 25) 
}

assume -name {aux-4} \
{
    acc_0.memwrite_rbm_visible_unit_ln365_q[79] == (acc_0.mux_j_ln290_z < 5)
}

assume -name {nvnm} \
{
    ( (acc_0.num_visible ==  (acc_0.num_movies<<2)+acc_0.num_movies) // 5x relationship
        && (acc_0.num_movies <= 16'h3333)
        && (acc_0.num_visible > 0)
        && (acc_0.num_hidden > 0)
        )
}

assume -name {global} \
{
      (
    GM.num_hidden == acc_0.num_hidden &&  // gloabl
    GM.num_loops == acc_0.num_loops && 
    GM.num_movies == acc_0.num_movies && 
    GM.num_testusers == acc_0.num_testusers && 
    GM.num_users == acc_0.num_users && 
    GM.num_visible == acc_0.num_visible )
}


assume -name {global-2} \
{
    GM.init_done == 1&&
    acc_0.init_done == 1
}


assume -name {onehot-enc} \
{
    $onehot(acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next) && $onehot(acc_0.state_rbm_0_cmos32soi_rbm_train_rbm) &&
    $onehot(acc_0.state_rbm_0_cmos32soi_rbm_predict_rbm_next) && $onehot(acc_0.state_rbm_0_cmos32soi_rbm_predict_rbm) &&
    $onehot(acc_0.state_rbm_0_cmos32soi_rbm_load_next) && $onehot(acc_0.state_rbm_0_cmos32soi_rbm_load) &&
    $onehot(acc_0.state_rbm_0_cmos32soi_rbm_store_next) && $onehot(acc_0.state_rbm_0_cmos32soi_rbm_store) &&
    $onehot(acc_0.state_rbm_0_cmos32soi_rbm_config_next) && $onehot(acc_0.state_rbm_0_cmos32soi_rbm_config)
}

# sequence
assume { ( cycles[0] |-> 1 ) }
assume { ( cycles[1] |-> acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[59] ) }
assume { ( cycles[2] |-> acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[56] ) }
assume { ( cycles[3] |-> acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[57] ) }
assume { ( cycles[4] |-> acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[58] ) }
assume { ( cycles[5] |-> acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[59] ) }
assume { ( cycles[6] |-> ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[22] && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[21] )) }


# begin-end-step
assume { ( (nondet_start == 1)   == cycles[2] ) }
assume { ( (GM_nondet_step == 1) == cycles[2] ) }
assume { ( (finish_signal == 1)  == cycles[5] ) }
assume { ( (last_cycle == 1 )    == cycles[6] ) }

# you can change them to acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[]
# but I feel it a little bit ugly


# pre-match
assume { (cycles[1] |-> ( GM.train_sum == acc_0.mux_sum_ln294_z ) ) }
assume { (cycles[1] |-> ( GM.train_v_cnt == acc_0.mux_v_ln282_q ) ) }
assume { (cycles[1] |-> ( GM.train_h_cnt == acc_0.mux_h_ln294_z ) ) }  
# when 59 h matched
assume { (cycles[2] |-> ( GM.train_max == acc_0.memwrite_rbm_visible_unit_ln365_q[60:45] ) ) }
assume { (cycles[0] |-> ( GM.jstate == acc_0.mux_j_ln290_z + 1 ) ) } 
assume { (cycles[0] |-> ( acc_0.mux_j_ln290_z < 5) ) }


assume -name {pre-set} -env \
{
    cycles[2] |-> (
        GM.per_v_pc ==  0 &&
        GM.train_upc == 1 &&
        GM.upc ==  2 
        )
}


assume -name {mem-sel} -env { GM_pd_or_tr == 1 }

# mem-hidden-preserve
assume { ( ( hidden_unit_CE3 & ~finorever ) |-> ( ( load_addr0 == hidden_unit_A3 ) ##1 ( load_data0 == hidden_unit_Q3 ) ) ) }
assume { ( GM_hidden_unit_rec == in_term ) }
assume { ( GM_step && (load_addr0 == GM_hidden_unit_raddr0) ) |-> (load_data0 == GM_hidden_unit_rdata0) }

# mem-edges-preserve
assume { ( ( edges_CE2 & ~ finorever ) |-> ( ( load_addr1 == edges_A2 ) ##1 ( load_data1 == edges_Q2 ) ) ) }
assume { ( GM_edges_rec == in_term ) }
assume { ( GM_step && (load_addr1 == GM_edges_raddr0) ) |-> (load_data1 == GM_edges_rdata0)  }


# visibleEnergies-preserve
assume { (GM_visibleEnergies_rec == in_term) && (GM_visibleEnergies_compare == finish) }

# load_info
assume { ( cycles[3] |->  ( reg0 == acc_0.mux_v_ln282_q ) )   }
assume { ( cycles[3] |->  ( reg1 == acc_0.mux_h_ln294_z ) )   }
assume { ( cycles[6] |->  ( reg2 == acc_0.mux_sum_ln294_z ) ) }
assume { ( cycles[6] |->  ( reg3 == acc_0.memwrite_rbm_visible_unit_ln365_q[60:45] ) ) }
# final-check
assert { ( finish |-> ( GM.train_v_cnt == reg0 ) ) }
assert { ( finish |-> ( (GM.train_h_cnt == reg1) || (GM.train_h_cnt == 0 && reg1 == acc_0.num_hidden +1 ) ) ) }
assert { ( finish |-> ( GM.train_sum == reg2 )   ) }
assert { ( finish |-> ( GM.train_max == reg3 )   ) }

# internal not shared
assert { ( last_cycle |-> (GM.per_v_pc == 0) )}
assert { ( last_cycle |-> (GM.train_upc == 1 )) }
assert { ( last_cycle |-> (GM.upc == 2) )  }
assert { ( last_cycle |-> ( acc_0.mux_j_ln290_z < 5) ) }

# final-mem-check
assert { finish |-> (~GM_visibleEnergies_mismatch) }



#check_assumptions -show
#check_assumptions