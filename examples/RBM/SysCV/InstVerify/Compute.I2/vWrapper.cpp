
// verification wrapper
#include "model_compute_class.hpp"
#include "subfun_assumps_0.cpp"
#include "subfun_cppUpdateFun_edges.cpp"
#include "subfun_cppUpdateFun_index.cpp"
#include "subfun_cppUpdateFun_loop_count.cpp"
#include "subfun_cppUpdateFun_predict_input_done.cpp"
#include "subfun_cppUpdateFun_rd_complete.cpp"
#include "subfun_cppUpdateFun_rd_index.cpp"
#include "subfun_cppUpdateFun_rd_length.cpp"
#include "subfun_cppUpdateFun_rd_request.cpp"
#include "subfun_cppUpdateFun_train_input_done.cpp"
#include "subfun_cppUpdateFun_upc.cpp"
#include "subfun_update.cpp"

model_compute GM;

#include "verifyExample.cpp"
rbm IMPL;

int main() {
    // call function 
    IMPL.load();
    return 0;
}
