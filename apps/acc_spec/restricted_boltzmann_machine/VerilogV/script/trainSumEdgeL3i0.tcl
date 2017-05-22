stopat acc_0.train_input_done
#stopat acc_0.mti_signal

# prelog: 30->52-55->52-55->52-55->20/11
# 23 -> ... -> 26 (next 24)
# 23 -> ... -> 27

#  SysC:
#
#
#      for (j = 0; j < K; j++) // [30]
#      {
#         RAND = rand_gen();
#         DATA_pow dp = pow2[j];
#         wait(); // [52]
#         probs = sld::udiv_func<32, 32, 64, 64, 64, 1>(dp, sumOfpow2);
#         bool tmpb = 0;
#         if (RAND < probs)
#            tmpb = 1;
#         visible_unit[v + j] = tmpb;
#         wait(); // [55]
#      }
#   }
#   visible_unit[nv] = 1; // turn on bias
#   wait(); // [11]

#  pow2

# pow2Read ? (next=52) ? (memwrite_pow2_ln351_q)
# visible_unit_update (visible 55)
# j (mux_j_ln356_z) : 2 cycles before 30



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
assume { ( cycles[4] |-> ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[30]) ) }
assume { ( cycles[5] |-> 1 ) }
assume { ( cycles[6] |-> 1 ) }

# complete assertion
assume {  acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[30] |=> acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[51] }
assert { (cycles[4] |-> ##[1:300] acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[55])}
assert { (cycles[4] |-> ##[1:300] finish ) }

# begin-end-step
assume { ( (nondet_start == 1)   == cycles[4] ) }
assume { ( (GM_nondet_step == 1) == cycles[4] ) }
# multi-end
assume { ( (finish_signal == 1)  == 
    (
        (acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[30] == 1 && ~ cycles[4] ) 
     || (~finished && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[11])
     || (~finished && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[20]) 
    ) ) }

assume { ( (last_cycle == 1)     == finish ) }


# pre-match
assume { ( cycles[4] |-> ( GM.jstate == acc_0.mux_j_ln356_z ) ) } 
assume { ( cycles[4] |-> ( acc_0.mux_j_ln356_z < 5) ) }
assume { ( cycles[4] |-> ( acc_0.memwrite_pow2_ln351_q == mem_pow2.mem ) ) }
assume { ( cycles[4] |-> ( acc_0.mux_visible_unit_ln356_z == mem_visible_unit.mem) ) }


assume -name {pre-set} -env \
{
    cycles[4] |-> (
        GM.per_v_pc ==  3 &&
        GM.train_upc == 1 &&
        GM.upc ==  2 
        )
}


assume -name {mem-sel} -env { GM_pd_or_tr == 1 }

# mem-pow2-preserve
# because pow2 is not an external memory
# mem-

# final-check
assert { ( finish |-> ( GM.jstate == acc_0.mux_j_ln356_z ) ) }

# internal not shared
assert { ( last_cycle |-> (
        ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[30] == 1 && ~ cycles[4] && GM.per_v_pc == 3 ) 
     || ( ~finished && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[11] && ~ cycles[4] && 1 )
     || ( ~finished && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[20] && ~ cycles[4] && GM.per_v_pc == 0 ) 
     ))}

assert { ( last_cycle |-> (
        ( acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[30] == 1 && ~ cycles[4] && GM.train_upc == 1 ) 
     || ( ~finished && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[11] && ~ cycles[4] && GM.train_upc == 2 )
     || ( ~finished && acc_0.state_rbm_0_cmos32soi_rbm_train_rbm[20] && ~ cycles[4] && GM.train_upc == 1 ) 
     ))}

assert { ( last_cycle |-> ( GM.upc == 2 ) )  }

# final-mem-check
assume { GM_visible_unit_compare == finish }
assert { finish |-> ( ~GM_visible_unit_mismatch ) }



#check_assumptions -show
#check_assumptions