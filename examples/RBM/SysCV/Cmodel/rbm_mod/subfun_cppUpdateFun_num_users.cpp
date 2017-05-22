#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_num_users(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_117;
	bool cppVar_118;
	BIT_VEC cppVar_121;
	bool cppVar_122;
	BIT_VEC cppVar_123;
	bool cppVar_124;
	bool cppVar_125;
	BIT_VEC cppVar_126;
	bool cppVar_127;
	bool cppVar_128;
	BIT_VEC cppVar_119;
	BIT_VEC cppVar_129;
	BIT_VEC cppVar_120;
	BIT_VEC cppVar_116;
	cppVar_118 = (rst == 1);
	if (cppVar_118) {
	cppVar_116 = 0;
	} else {
	cppVar_122 = (rst == 0);
	cppVar_124 = (init_done == 0);
	cppVar_125 = cppVar_122 && cppVar_124;
	cppVar_127 = (conf_done == 1);
	cppVar_128 = cppVar_125 && cppVar_127;
	if (cppVar_128) {
	cppVar_129 = (conf_num_users >> 0) & cppMask_un_16_;
	cppVar_120 = cppVar_129;
	} else {
	cppVar_120 = num_users;
	}
	cppVar_116 = cppVar_120;
	}
	return cppVar_116;
}
