#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_index(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_491;
	bool cppVar_492;
	BIT_VEC cppVar_494;
	bool cppVar_495;
	BIT_VEC cppVar_497;
	bool cppVar_498;
	bool cppVar_500;
	bool cppVar_501;
	bool cppVar_502;
	BIT_VEC cppVar_504;
	BIT_VEC cppVar_505;
	bool cppVar_506;
	bool cppVar_507;
	bool cppVar_508;
	BIT_VEC cppVar_510;
	BIT_VEC cppVar_511;
	BIT_VEC cppVar_503;
	BIT_VEC cppVar_499;
	BIT_VEC cppVar_496;
	BIT_VEC cppVar_493;
	BIT_VEC cppVar_490;
	BIT_VEC cppVar_509;
	cppVar_492 = (train_upc == 0);
	if (cppVar_492) {
	cppVar_490 = index;
	} else {
	cppVar_495 = (train_upc == 1);
	if (cppVar_495) {
	cppVar_493 = index;
	} else {
	cppVar_498 = (train_upc == 2);
	if (cppVar_498) {
	cppVar_500 = (train_h_cnt == num_hidden);
	cppVar_501 = (train_v_cnt == num_visible);
	cppVar_502 = cppVar_500 && cppVar_501;
	if (cppVar_502) {
	cppVar_505 = num_users - 1;
	cppVar_505 = (cppVar_505 & cppMask_un_16_);
	cppVar_506 = (index == cppVar_505);
	cppVar_507 = (loop_count != num_loops);
	cppVar_508 = cppVar_506 && cppVar_507;
	if (cppVar_508) {
	cppVar_503 = 0;
	} else {
	cppVar_511 = index + 1;
	cppVar_511 = (cppVar_511 & cppMask_un_16_);
	cppVar_503 = cppVar_511;
	}
	cppVar_499 = cppVar_503;
	} else {
	cppVar_499 = index;
	}
	cppVar_496 = cppVar_499;
	} else {
	cppVar_496 = index;
	}
	cppVar_493 = cppVar_496;
	}
	cppVar_490 = cppVar_493;
	}
	return cppVar_490;
}
