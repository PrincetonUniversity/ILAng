#include "common.hpp"
#include "model_DMAload_class.hpp"

BIT_VEC model_DMAload::cppUpdateFun_rd_complete(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_217;
	bool cppVar_218;
	BIT_VEC cppVar_216;
	BIT_VEC cppVar_219;
	BIT_VEC cppVar_220;
	cppVar_217 = (rd_length >> 0) & cppMask_un_16_;
	cppVar_218 = i < cppVar_217;
	if (cppVar_218) {
	cppVar_216 = 0;
	} else {
	cppVar_216 = 1;
	}
	return cppVar_216;
}
