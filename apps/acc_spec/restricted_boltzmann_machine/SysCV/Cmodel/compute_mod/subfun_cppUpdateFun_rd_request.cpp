#include "common.hpp"
#include "model_compute_class.hpp"

BIT_VEC model_compute::cppUpdateFun_rd_request(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_373;
	BIT_VEC cppVar_376;
	BIT_VEC cppVar_374;
	bool cppVar_375;
	cppVar_375 = (upc == 0);
	if (cppVar_375) {
	cppVar_373 = 1;
	} else {
	cppVar_373 = rd_request;
	}
	return cppVar_373;
}
