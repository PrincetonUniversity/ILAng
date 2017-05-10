stopat acc_0.train_input_done
stopat acc_0.mti_signal

# prelog: 22->23
# 23 -> ... -> 26 (next 24)
# 23 -> ... -> 27

#  SysC:
#
#
#      for (j = 0; j < K; j++) // [27]  [29]->[28]/[30]
#      {
#         /*TODO:fix point; exp function*/
#         tmp1 = visibleEnergies[j];
#         wait();    // [28]
#         if (tmp1[0] == 0)
#         {
#            tmp = tmp1.to_int();
#         }
#         else if (tmp1 > 0)
#         {
#            tmp = tmp1.to_int() + 1;
#         }
#         else
#            tmp = -1;
#
#         DATA_pow dp;
#         if (tmp < 0 )
#            dp = 0;
#         else
#            dp = 1UL << tmp;
#
#         sumOfpow2 += dp;
#         pow2[j] = dp;
#      }

# visibleEnergyRead (next=28) (27,29)
# sumOfpow2  (visible 29)
# pow2 (visible 29)
# j : (next=28, 27,29) (newvalue@28)



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
assume { ( cycles[1] |-> 1 ) }
assume { ( cycles[2] |-> 1 ) }
assume { ( cycles[3] |-> 1 ) }
assume { ( cycles[4] |-> acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[27] ) }
assume { ( cycles[5] |-> acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[28] ) }
assume { ( cycles[6] |-> ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[29] && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm_next[28] )) }


# begin-end-step
assume { ( (nondet_start == 1)   == cycles[4] ) }
assume { ( (GM_nondet_step == 1) == cycles[4] ) }
assume { ( (finish_signal == 1)  == cycles[6] ) }
assume { ( (last_cycle == 1 )    == cycles[6] ) }

# you can change them to acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[]
# but I feel it a little bit ugly


# pre-match
assume { (cycles[4] |-> ( GM.sumOfpow2 == acc_0.mux_sumOfpow2_ln328_z ) ) }
assume { (cycles[3] |-> ( GM.train_max == acc_0.memwrite_rbm_visible_unit_ln365_q[60:45] ) ) }
assume { (cycles[4] |-> ( GM.jstate == acc_0.mux_j_ln328_z ) ) } 
assume { (cycles[4] |-> ( acc_0.mux_j_ln328_z < 5) ) }
assume { (cycles[3] |-> ( acc_0.memwrite_pow2_ln351_q == mem_pow2.mem) ) }


assume -name {pre-set} -env \
{
    cycles[4] |-> (
        GM.per_v_pc ==  2 &&
        GM.train_upc == 1 &&
        GM.upc ==  2 
        )
}


assume -name {mem-sel} -env { GM_pd_or_tr == 1 }

# mem-visibleEnergies-preserve
assume { ( ( visibleEnergies_CE3 & ~finorever ) |-> ( ( load_addr0 == visibleEnergies_A3 ) ##1 ( load_data0 == visibleEnergies_Q3 ) ) ) }
assume { ( GM_visibleEnergies_rec == in_term ) }
assume { ( GM_step && (load_addr0 == GM_visibleEnergies_raddr0) ) |-> (load_data0 == GM_visibleEnergies_rdata0) }


# load_info
assume { ( cycles[5] |->  ( reg0 == acc_0.mux_j_ln328_z ) )   }
# final-check
assert { ( finish |-> ( GM.jstate == reg0 ) ) }

# internal not shared
assert { ( last_cycle |-> (GM.per_v_pc == 2) )}
assert { ( last_cycle |-> (GM.train_upc == 1 )) }
assert { ( last_cycle |-> (GM.upc == 2) )  }
assert { ( last_cycle |-> ( acc_0.mux_j_ln328_z <= 5) ) }

# final-mem-check
assume { GM_pow2_compare == finish }
assert { finish |-> ( ~GM_pow2_mismatch ) }



#check_assumptions -show
#check_assumptions