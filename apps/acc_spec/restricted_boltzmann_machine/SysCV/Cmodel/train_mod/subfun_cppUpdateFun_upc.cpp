#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_upc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_946;
	BIT_VEC cppVar_934;
	bool cppVar_935;
	BIT_VEC cppVar_937;
	bool cppVar_938;
	BIT_VEC cppVar_940;
	bool cppVar_941;
	bool cppVar_943;
	bool cppVar_944;
	bool cppVar_945;
	BIT_VEC cppVar_942;
	BIT_VEC cppVar_939;
	BIT_VEC cppVar_936;
	BIT_VEC cppVar_933;
	cppVar_935 = (train_upc == 0);
	if (cppVar_935) {
	cppVar_933 = upc;
	} else {
	cppVar_938 = (train_upc == 1);
	if (cppVar_938) {
	cppVar_936 = upc;
	} else {
	cppVar_941 = (train_upc == 2);
	if (cppVar_941) {
	cppVar_943 = (train_h_cnt == num_hidden);
	cppVar_944 = (train_v_cnt == num_visible);
	cppVar_945 = cppVar_943 && cppVar_944;
	if (cppVar_945) {
	cppVar_942 = 0;
	} else {
	cppVar_942 = upc;
	}
	cppVar_939 = cppVar_942;
	} else {
	cppVar_939 = upc;
	}
	cppVar_936 = cppVar_939;
	}
	cppVar_933 = cppVar_936;
	}
	return cppVar_933;
}
