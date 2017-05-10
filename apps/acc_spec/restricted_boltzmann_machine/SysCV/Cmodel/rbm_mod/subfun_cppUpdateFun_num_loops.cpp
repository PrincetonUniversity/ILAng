#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_num_loops(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_72;
	bool cppVar_73;
	BIT_VEC cppVar_76;
	bool cppVar_77;
	BIT_VEC cppVar_78;
	bool cppVar_79;
	bool cppVar_80;
	BIT_VEC cppVar_81;
	bool cppVar_82;
	bool cppVar_83;
	BIT_VEC cppVar_74;
	BIT_VEC cppVar_84;
	BIT_VEC cppVar_75;
	BIT_VEC cppVar_71;
	cppVar_73 = (rst == 1);
	if (cppVar_73) {
	cppVar_71 = 0;
	} else {
	cppVar_77 = (rst == 0);
	cppVar_79 = (init_done == 0);
	cppVar_80 = cppVar_77 && cppVar_79;
	cppVar_82 = (conf_done == 1);
	cppVar_83 = cppVar_80 && cppVar_82;
	if (cppVar_83) {
	cppVar_84 = (conf_num_loops >> 0) & cppMask_un_16_;
	cppVar_75 = cppVar_84;
	} else {
	cppVar_75 = num_loops;
	}
	cppVar_71 = cppVar_75;
	}
	return cppVar_71;
}
