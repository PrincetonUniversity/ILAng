#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_wr_granted(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_163;
	BIT_VEC cppVar_160;
	BIT_VEC cppVar_161;
	bool cppVar_162;
	BIT_VEC cppVar_159;
	cppVar_160 = wr_request & wr_grant;
	cppVar_162 = (cppVar_160 == 1);
	if (cppVar_162) {
	cppVar_159 = 1;
	} else {
	cppVar_159 = wr_granted;
	}
	return cppVar_159;
}
