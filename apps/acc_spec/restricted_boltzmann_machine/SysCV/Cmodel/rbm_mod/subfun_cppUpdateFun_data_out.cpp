#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_data_out(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_36;
	BIT_VEC cppVar_37;
	BIT_VEC cppVar_38;
	BIT_VEC cppVar_33;
	BIT_VEC cppVar_34;
	bool cppVar_35;
	BIT_VEC cppVar_32;
	cppVar_33 = wr_request & wr_grant;
	cppVar_35 = (cppVar_33 == 1);
	if (cppVar_35) {
	cppVar_37 = predict_result.rd(0);
	cppVar_38 = (cppVar_37 & cppMask_un_8_);
	cppVar_32 = cppVar_38;
	} else {
	cppVar_32 = data_out;
	}
	return cppVar_32;
}
