#include "common.hpp"
#include "model_store_class.hpp"

BIT_VEC model_store::cppUpdateFun_wr_complete(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	bool cppVar_287;
	BIT_VEC cppVar_286;
	BIT_VEC cppVar_288;
	cppVar_287 = i < num_movies;
	if (cppVar_287) {
	cppVar_286 = wr_complete;
	} else {
	cppVar_286 = 1;
	}
	return cppVar_286;
}
