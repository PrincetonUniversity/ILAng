
// verification wrapper
#include "model_store_class.hpp"
#include "subfun_assumps_0.cpp"
#include "subfun_cppUpdateFun_data_out.cpp"
#include "subfun_cppUpdateFun_i.cpp"
#include "subfun_cppUpdateFun_wr_complete.cpp"
#include "subfun_cppUpdateFun_wr_granted.cpp"
#include "subfun_cppUpdateFun_wr_request.cpp"
#include "subfun_update.cpp"

model_store GM;

#include "verifyExample.cpp"
rbm IMPL;

int main() {
    // call function 
    IMPL.store();
    return 0;
}
