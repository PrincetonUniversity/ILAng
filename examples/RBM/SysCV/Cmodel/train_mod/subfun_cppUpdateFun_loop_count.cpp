#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_loop_count(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_551;
	bool cppVar_552;
	BIT_VEC cppVar_554;
	bool cppVar_555;
	BIT_VEC cppVar_557;
	bool cppVar_558;
	bool cppVar_560;
	bool cppVar_561;
	bool cppVar_562;
	BIT_VEC cppVar_563;
	BIT_VEC cppVar_564;
	bool cppVar_565;
	bool cppVar_566;
	bool cppVar_567;
	bool cppVar_568;
	BIT_VEC cppVar_569;
	BIT_VEC cppVar_570;
	BIT_VEC cppVar_559;
	BIT_VEC cppVar_556;
	BIT_VEC cppVar_553;
	BIT_VEC cppVar_550;
	cppVar_552 = (train_upc == 0);
	if (cppVar_552) {
	cppVar_550 = loop_count;
	} else {
	cppVar_555 = (train_upc == 1);
	if (cppVar_555) {
	cppVar_553 = loop_count;
	} else {
	cppVar_558 = (train_upc == 2);
	if (cppVar_558) {
	cppVar_560 = (train_h_cnt == num_hidden);
	cppVar_561 = (train_v_cnt == num_visible);
	cppVar_562 = cppVar_560 && cppVar_561;
	cppVar_564 = num_users - 1;
	cppVar_564 = (cppVar_564 & cppMask_un_16_);
	cppVar_565 = (index == cppVar_564);
	cppVar_566 = cppVar_562 && cppVar_565;
	cppVar_567 = (loop_count != num_loops);
	cppVar_568 = cppVar_566 && cppVar_567;
	if (cppVar_568) {
	cppVar_570 = loop_count + 1;
	cppVar_570 = (cppVar_570 & cppMask_un_16_);
	cppVar_559 = cppVar_570;
	} else {
	cppVar_559 = loop_count;
	}
	cppVar_556 = cppVar_559;
	} else {
	cppVar_556 = loop_count;
	}
	cppVar_553 = cppVar_556;
	}
	cppVar_550 = cppVar_553;
	}
	return cppVar_550;
}
