#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_num_movies(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_87;
	bool cppVar_88;
	BIT_VEC cppVar_91;
	bool cppVar_92;
	BIT_VEC cppVar_93;
	bool cppVar_94;
	bool cppVar_95;
	BIT_VEC cppVar_96;
	bool cppVar_97;
	bool cppVar_98;
	BIT_VEC cppVar_89;
	BIT_VEC cppVar_99;
	BIT_VEC cppVar_90;
	BIT_VEC cppVar_86;
	cppVar_88 = (rst == 1);
	if (cppVar_88) {
	cppVar_86 = 0;
	} else {
	cppVar_92 = (rst == 0);
	cppVar_94 = (init_done == 0);
	cppVar_95 = cppVar_92 && cppVar_94;
	cppVar_97 = (conf_done == 1);
	cppVar_98 = cppVar_95 && cppVar_97;
	if (cppVar_98) {
	cppVar_99 = (conf_num_movies >> 0) & cppMask_un_16_;
	cppVar_90 = cppVar_99;
	} else {
	cppVar_90 = num_movies;
	}
	cppVar_86 = cppVar_90;
	}
	return cppVar_86;
}
