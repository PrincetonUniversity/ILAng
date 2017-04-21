
// verification wrapper
#include "model_DMAload_class.hpp"
#include "subfun_assumps_0.cpp"
#include "subfun_cppUpdateFun_data.cpp"
#include "subfun_cppUpdateFun_i.cpp"
#include "subfun_cppUpdateFun_rd_complete.cpp"
#include "subfun_cppUpdateFun_rd_granted.cpp"
#include "subfun_cppUpdateFun_rd_request.cpp"
#include "subfun_update.cpp"

model_DMAload GM;

#include "verifyExample.cpp"
rbm IMPL;

int main() {
    // call function 
    IMPL.load();
    return 0;
}
