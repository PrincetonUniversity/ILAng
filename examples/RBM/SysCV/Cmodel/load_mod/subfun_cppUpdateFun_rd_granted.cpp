#include "common.hpp"
#include "model_DMAload_class.hpp"

BIT_VEC model_DMAload::cppUpdateFun_rd_granted(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_223;
	bool cppVar_224;
	BIT_VEC cppVar_222;
	BIT_VEC cppVar_225;
	cppVar_223 = (rd_length >> 0) & cppMask_un_16_;
	cppVar_224 = i < cppVar_223;
	if (cppVar_224) {
	cppVar_222 = rd_granted;
	} else {
	cppVar_222 = 0;
	}
	return cppVar_222;
}
