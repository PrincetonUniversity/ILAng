#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_num_visible(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_132;
	bool cppVar_133;
	BIT_VEC cppVar_136;
	bool cppVar_137;
	BIT_VEC cppVar_138;
	bool cppVar_139;
	bool cppVar_140;
	BIT_VEC cppVar_141;
	bool cppVar_142;
	bool cppVar_143;
	BIT_VEC cppVar_134;
	BIT_VEC cppVar_144;
	BIT_VEC cppVar_135;
	BIT_VEC cppVar_131;
	cppVar_133 = (rst == 1);
	if (cppVar_133) {
	cppVar_131 = 0;
	} else {
	cppVar_137 = (rst == 0);
	cppVar_139 = (init_done == 0);
	cppVar_140 = cppVar_137 && cppVar_139;
	cppVar_142 = (conf_done == 1);
	cppVar_143 = cppVar_140 && cppVar_142;
	if (cppVar_143) {
	cppVar_144 = (conf_num_visible >> 0) & cppMask_un_16_;
	cppVar_135 = cppVar_144;
	} else {
	cppVar_135 = num_visible;
	}
	cppVar_131 = cppVar_135;
	}
	return cppVar_131;
}
