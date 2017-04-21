
// verification wrapper
#include "model_predict_class.hpp"
#include "subfun_assumps_0.cpp"
#include "subfun_cppUpdateFun_count.cpp"
#include "subfun_cppUpdateFun_done.cpp"
#include "subfun_cppUpdateFun_expectation.cpp"
#include "subfun_cppUpdateFun_hidden_unit.cpp"
#include "subfun_cppUpdateFun_index.cpp"
#include "subfun_cppUpdateFun_jstate.cpp"
#include "subfun_cppUpdateFun_per_v_pc.cpp"
#include "subfun_cppUpdateFun_pow2.cpp"
#include "subfun_cppUpdateFun_predict_h_cnt.cpp"
#include "subfun_cppUpdateFun_predict_input_done.cpp"
#include "subfun_cppUpdateFun_predict_max.cpp"
#include "subfun_cppUpdateFun_predict_result.cpp"
#include "subfun_cppUpdateFun_predict_sum.cpp"
#include "subfun_cppUpdateFun_predict_upc.cpp"
#include "subfun_cppUpdateFun_predict_v_cnt.cpp"
#include "subfun_cppUpdateFun_predict_vector.cpp"
#include "subfun_cppUpdateFun_prediction.cpp"
#include "subfun_cppUpdateFun_sumOfpow2.cpp"
#include "subfun_cppUpdateFun_upc.cpp"
#include "subfun_cppUpdateFun_visibleEnergies.cpp"
#include "subfun_cppUpdateFun_wr_complete.cpp"
#include "subfun_cppUpdateFun_wr_index.cpp"
#include "subfun_cppUpdateFun_wr_length.cpp"
#include "subfun_cppUpdateFun_wr_request.cpp"
#include "subfun_update.cpp"

model_predict GM;

#include "verifyExample.cpp"
rbm IMPL;

int main() {
    // call function 
    IMPL.predict_rbm();
    return 0;
}
