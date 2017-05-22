#include "common.hpp"
#include "model_compute_class.hpp"

BIT_VEC model_compute::cppUpdateFun_predict_input_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_340;
	bool cppVar_341;
	BIT_VEC cppVar_342;
	bool cppVar_343;
	bool cppVar_344;
	bool cppVar_346;
	BIT_VEC cppVar_345;
	BIT_VEC cppVar_339;
	BIT_VEC cppVar_348;
	BIT_VEC cppVar_347;
	cppVar_341 = (upc == 1);
	cppVar_343 = (rd_complete == 1);
	cppVar_344 = cppVar_341 && cppVar_343;
	if (cppVar_344) {
	cppVar_346 = (loop_count == num_loops);
	if (cppVar_346) {
	cppVar_345 = 1;
	} else {
	cppVar_345 = 0;
	}
	cppVar_339 = cppVar_345;
	} else {
	cppVar_339 = predict_input_done;
	}
	return cppVar_339;
}
