#include "common.hpp"
#include "model_compute_class.hpp"

BIT_VEC model_compute::cppUpdateFun_rd_complete(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_355;
	bool cppVar_356;
	BIT_VEC cppVar_357;
	bool cppVar_358;
	bool cppVar_359;
	BIT_VEC cppVar_354;
	BIT_VEC cppVar_350;
	BIT_VEC cppVar_353;
	BIT_VEC cppVar_351;
	bool cppVar_352;
	cppVar_352 = (upc == 0);
	if (cppVar_352) {
	cppVar_350 = 0;
	} else {
	cppVar_356 = (upc == 1);
	cppVar_358 = (rd_complete == 1);
	cppVar_359 = cppVar_356 && cppVar_358;
	if (cppVar_359) {
	cppVar_354 = 0;
	} else {
	cppVar_354 = rd_complete;
	}
	cppVar_350 = cppVar_354;
	}
	return cppVar_350;
}
