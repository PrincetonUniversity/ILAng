#include "common.hpp"
#include "model_DMAload_class.hpp"

BIT_VEC model_DMAload::cppUpdateFun_i(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_211;
	bool cppVar_212;
	BIT_VEC cppVar_213;
	BIT_VEC cppVar_214;
	BIT_VEC cppVar_210;
	cppVar_211 = (rd_length >> 0) & cppMask_un_16_;
	cppVar_212 = i < cppVar_211;
	if (cppVar_212) {
	cppVar_214 = i + 1;
	cppVar_214 = (cppVar_214 & cppMask_un_16_);
	cppVar_210 = cppVar_214;
	} else {
	cppVar_210 = i;
	}
	return cppVar_210;
}
