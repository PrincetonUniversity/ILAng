#include "common.hpp"
#include "model_compute_class.hpp"

BIT_VEC model_compute::cppUpdateFun_train_input_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_379;
	bool cppVar_380;
	BIT_VEC cppVar_381;
	bool cppVar_382;
	bool cppVar_383;
	bool cppVar_385;
	BIT_VEC cppVar_384;
	BIT_VEC cppVar_378;
	BIT_VEC cppVar_387;
	BIT_VEC cppVar_386;
	cppVar_380 = (upc == 1);
	cppVar_382 = (rd_complete == 1);
	cppVar_383 = cppVar_380 && cppVar_382;
	if (cppVar_383) {
	cppVar_385 = loop_count < num_loops;
	if (cppVar_385) {
	cppVar_384 = 1;
	} else {
	cppVar_384 = 0;
	}
	cppVar_378 = cppVar_384;
	} else {
	cppVar_378 = train_input_done;
	}
	return cppVar_378;
}
