#include "common.hpp"
#include "model_store_class.hpp"

BIT_VEC model_store::cppUpdateFun_i(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	bool cppVar_282;
	BIT_VEC cppVar_283;
	BIT_VEC cppVar_284;
	BIT_VEC cppVar_281;
	cppVar_282 = i < num_movies;
	if (cppVar_282) {
	cppVar_284 = i + 1;
	cppVar_284 = (cppVar_284 & cppMask_un_16_);
	cppVar_281 = cppVar_284;
	} else {
	cppVar_281 = i;
	}
	return cppVar_281;
}
