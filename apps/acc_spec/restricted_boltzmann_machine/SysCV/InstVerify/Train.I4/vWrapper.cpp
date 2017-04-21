
// verification wrapper
#include "model_train_class.hpp"
#include "subfun_assumps_0.cpp"
#include "subfun_cppUpdateFun_edges.cpp"
#include "subfun_cppUpdateFun_hidden_unit.cpp"
#include "subfun_cppUpdateFun_index.cpp"
#include "subfun_cppUpdateFun_jstate.cpp"
#include "subfun_cppUpdateFun_loop_count.cpp"
#include "subfun_cppUpdateFun_per_v_pc.cpp"
#include "subfun_cppUpdateFun_pos.cpp"
#include "subfun_cppUpdateFun_pow2.cpp"
#include "subfun_cppUpdateFun_sumOfpow2.cpp"
#include "subfun_cppUpdateFun_train_h_cnt.cpp"
#include "subfun_cppUpdateFun_train_input_done.cpp"
#include "subfun_cppUpdateFun_train_max.cpp"
#include "subfun_cppUpdateFun_train_sum.cpp"
#include "subfun_cppUpdateFun_train_upc.cpp"
#include "subfun_cppUpdateFun_train_v_cnt.cpp"
#include "subfun_cppUpdateFun_upc.cpp"
#include "subfun_cppUpdateFun_visibleEnergies.cpp"
#include "subfun_cppUpdateFun_visible_unit.cpp"
#include "subfun_update.cpp"

model_train GM;

#include "verifyExample.cpp"
rbm IMPL;

int main() {
    // call function 
    IMPL.train_rbm();
    return 0;
}
