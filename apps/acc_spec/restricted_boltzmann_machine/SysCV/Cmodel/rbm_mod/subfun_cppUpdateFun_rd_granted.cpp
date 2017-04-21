#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_rd_granted(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_147;
	BIT_VEC cppVar_148;
	bool cppVar_149;
	BIT_VEC cppVar_150;
	bool cppVar_151;
	bool cppVar_152;
	BIT_VEC cppVar_153;
	cppVar_149 = (rd_request == 1);
	cppVar_151 = (rd_grant == 1);
	cppVar_152 = cppVar_149 && cppVar_151;
	if (cppVar_152) {
	cppVar_147 = 1;
	} else {
	cppVar_147 = rd_granted;
	}
	return cppVar_147;
}
