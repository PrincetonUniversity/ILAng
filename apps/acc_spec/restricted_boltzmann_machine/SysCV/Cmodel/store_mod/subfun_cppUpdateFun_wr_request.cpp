#include "common.hpp"
#include "model_store_class.hpp"

BIT_VEC model_store::cppUpdateFun_wr_request(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_295;
	bool cppVar_296;
	BIT_VEC cppVar_294;
	BIT_VEC cppVar_297;
	cppVar_296 = (i == 0);
	if (cppVar_296) {
	cppVar_294 = 0;
	} else {
	cppVar_294 = wr_request;
	}
	return cppVar_294;
}
