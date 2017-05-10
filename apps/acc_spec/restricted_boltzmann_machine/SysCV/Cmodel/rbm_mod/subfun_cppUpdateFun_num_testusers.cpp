#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_num_testusers(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_102;
	bool cppVar_103;
	BIT_VEC cppVar_106;
	bool cppVar_107;
	BIT_VEC cppVar_108;
	bool cppVar_109;
	bool cppVar_110;
	BIT_VEC cppVar_111;
	bool cppVar_112;
	bool cppVar_113;
	BIT_VEC cppVar_104;
	BIT_VEC cppVar_114;
	BIT_VEC cppVar_105;
	BIT_VEC cppVar_101;
	cppVar_103 = (rst == 1);
	if (cppVar_103) {
	cppVar_101 = 0;
	} else {
	cppVar_107 = (rst == 0);
	cppVar_109 = (init_done == 0);
	cppVar_110 = cppVar_107 && cppVar_109;
	cppVar_112 = (conf_done == 1);
	cppVar_113 = cppVar_110 && cppVar_112;
	if (cppVar_113) {
	cppVar_114 = (conf_num_testusers >> 0) & cppMask_un_16_;
	cppVar_105 = cppVar_114;
	} else {
	cppVar_105 = num_testusers;
	}
	cppVar_101 = cppVar_105;
	}
	return cppVar_101;
}
