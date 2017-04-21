#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_init_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_42;
	bool cppVar_43;
	BIT_VEC cppVar_46;
	bool cppVar_47;
	BIT_VEC cppVar_48;
	bool cppVar_49;
	bool cppVar_50;
	BIT_VEC cppVar_51;
	bool cppVar_52;
	bool cppVar_53;
	BIT_VEC cppVar_44;
	BIT_VEC cppVar_54;
	BIT_VEC cppVar_45;
	BIT_VEC cppVar_41;
	cppVar_43 = (rst == 1);
	if (cppVar_43) {
	cppVar_41 = 0;
	} else {
	cppVar_47 = (rst == 0);
	cppVar_49 = (init_done == 0);
	cppVar_50 = cppVar_47 && cppVar_49;
	cppVar_52 = (conf_done == 1);
	cppVar_53 = cppVar_50 && cppVar_52;
	if (cppVar_53) {
	cppVar_45 = 1;
	} else {
	cppVar_45 = init_done;
	}
	cppVar_41 = cppVar_45;
	}
	return cppVar_41;
}
