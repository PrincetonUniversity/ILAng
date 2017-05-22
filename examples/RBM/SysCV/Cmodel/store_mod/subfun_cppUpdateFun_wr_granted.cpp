#include "common.hpp"
#include "model_store_class.hpp"

BIT_VEC model_store::cppUpdateFun_wr_granted(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	bool cppVar_291;
	BIT_VEC cppVar_290;
	BIT_VEC cppVar_292;
	cppVar_291 = i < num_movies;
	if (cppVar_291) {
	cppVar_290 = wr_granted;
	} else {
	cppVar_290 = 0;
	}
	return cppVar_290;
}
