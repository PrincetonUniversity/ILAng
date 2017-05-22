#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_train_input_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_706;
	bool cppVar_707;
	BIT_VEC cppVar_709;
	bool cppVar_710;
	BIT_VEC cppVar_712;
	bool cppVar_713;
	BIT_VEC cppVar_718;
	bool cppVar_715;
	bool cppVar_716;
	bool cppVar_717;
	BIT_VEC cppVar_714;
	BIT_VEC cppVar_711;
	BIT_VEC cppVar_708;
	BIT_VEC cppVar_705;
	cppVar_707 = (train_upc == 0);
	if (cppVar_707) {
	cppVar_705 = train_input_done;
	} else {
	cppVar_710 = (train_upc == 1);
	if (cppVar_710) {
	cppVar_708 = train_input_done;
	} else {
	cppVar_713 = (train_upc == 2);
	if (cppVar_713) {
	cppVar_715 = (train_h_cnt == num_hidden);
	cppVar_716 = (train_v_cnt == num_visible);
	cppVar_717 = cppVar_715 && cppVar_716;
	if (cppVar_717) {
	cppVar_714 = 0;
	} else {
	cppVar_714 = train_input_done;
	}
	cppVar_711 = cppVar_714;
	} else {
	cppVar_711 = train_input_done;
	}
	cppVar_708 = cppVar_711;
	}
	cppVar_705 = cppVar_708;
	}
	return cppVar_705;
}
