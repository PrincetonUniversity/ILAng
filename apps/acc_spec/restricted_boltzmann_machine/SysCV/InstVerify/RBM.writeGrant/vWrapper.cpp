
// verification wrapper
#include "model_RBM_class.hpp"
#include "subfun_cppUpdateFun_data.cpp"
#include "subfun_cppUpdateFun_data_out.cpp"
#include "subfun_cppUpdateFun_done.cpp"
#include "subfun_cppUpdateFun_init_done.cpp"
#include "subfun_cppUpdateFun_num_hidden.cpp"
#include "subfun_cppUpdateFun_num_loops.cpp"
#include "subfun_cppUpdateFun_num_movies.cpp"
#include "subfun_cppUpdateFun_num_testusers.cpp"
#include "subfun_cppUpdateFun_num_users.cpp"
#include "subfun_cppUpdateFun_num_visible.cpp"
#include "subfun_cppUpdateFun_rd_complete.cpp"
#include "subfun_cppUpdateFun_rd_granted.cpp"
#include "subfun_cppUpdateFun_rd_index.cpp"
#include "subfun_cppUpdateFun_rd_length.cpp"
#include "subfun_cppUpdateFun_rd_request.cpp"
#include "subfun_cppUpdateFun_wr_complete.cpp"
#include "subfun_cppUpdateFun_wr_granted.cpp"
#include "subfun_cppUpdateFun_wr_index.cpp"
#include "subfun_cppUpdateFun_wr_length.cpp"
#include "subfun_cppUpdateFun_wr_request.cpp"
#include "subfun_update.cpp"

model_RBM GM;

#include "verifyExample.cpp"
rbm IMPL;

int main() {
    // call function 
    IMPL.store();
    return 0;
}
