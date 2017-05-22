#include "common.hpp"
#include "model_compute_class.hpp"

BIT_VEC model_compute::cppUpdateFun_upc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_394;
	bool cppVar_395;
	BIT_VEC cppVar_396;
	bool cppVar_397;
	bool cppVar_398;
	BIT_VEC cppVar_400;
	bool cppVar_401;
	BIT_VEC cppVar_402;
	bool cppVar_403;
	bool cppVar_404;
	BIT_VEC cppVar_407;
	bool cppVar_408;
	BIT_VEC cppVar_409;
	bool cppVar_410;
	bool cppVar_411;
	BIT_VEC cppVar_413;
	bool cppVar_414;
	BIT_VEC cppVar_415;
	bool cppVar_416;
	bool cppVar_417;
	BIT_VEC cppVar_419;
	bool cppVar_420;
	BIT_VEC cppVar_392;
	BIT_VEC cppVar_405;
	BIT_VEC cppVar_421;
	BIT_VEC cppVar_418;
	BIT_VEC cppVar_412;
	BIT_VEC cppVar_406;
	BIT_VEC cppVar_399;
	BIT_VEC cppVar_393;
	BIT_VEC cppVar_389;
	BIT_VEC cppVar_390;
	bool cppVar_391;
	cppVar_391 = (upc == 0);
	if (cppVar_391) {
	cppVar_389 = 1;
	} else {
	cppVar_395 = (upc == 1);
	cppVar_397 = (rd_complete == 0);
	cppVar_398 = cppVar_395 && cppVar_397;
	if (cppVar_398) {
	cppVar_393 = upc;
	} else {
	cppVar_401 = (upc == 1);
	cppVar_403 = (rd_complete == 1);
	cppVar_404 = cppVar_401 && cppVar_403;
	if (cppVar_404) {
	cppVar_399 = 2;
	} else {
	cppVar_408 = (upc == 2);
	cppVar_410 = (train_input_done == 1);
	cppVar_411 = cppVar_408 && cppVar_410;
	if (cppVar_411) {
	cppVar_406 = 2;
	} else {
	cppVar_414 = (upc == 2);
	cppVar_416 = (predict_input_done == 1);
	cppVar_417 = cppVar_414 && cppVar_416;
	if (cppVar_417) {
	cppVar_412 = 2;
	} else {
	cppVar_420 = (upc == 3);
	if (cppVar_420) {
	cppVar_418 = 3;
	} else {
	cppVar_418 = upc;
	}
	cppVar_412 = cppVar_418;
	}
	cppVar_406 = cppVar_412;
	}
	cppVar_399 = cppVar_406;
	}
	cppVar_393 = cppVar_399;
	}
	cppVar_389 = cppVar_393;
	}
	return cppVar_389;
}
