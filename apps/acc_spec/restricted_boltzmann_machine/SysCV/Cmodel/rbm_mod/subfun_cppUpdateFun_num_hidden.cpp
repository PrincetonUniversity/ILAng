#include "common.hpp"
#include "model_RBM_class.hpp"

BIT_VEC model_RBM::cppUpdateFun_num_hidden(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_57;
	bool cppVar_58;
	BIT_VEC cppVar_61;
	bool cppVar_62;
	BIT_VEC cppVar_63;
	bool cppVar_64;
	bool cppVar_65;
	BIT_VEC cppVar_66;
	bool cppVar_67;
	bool cppVar_68;
	BIT_VEC cppVar_59;
	BIT_VEC cppVar_69;
	BIT_VEC cppVar_60;
	BIT_VEC cppVar_56;
	cppVar_58 = (rst == 1);
	if (cppVar_58) {
	cppVar_56 = 0;
	} else {
	cppVar_62 = (rst == 0);
	cppVar_64 = (init_done == 0);
	cppVar_65 = cppVar_62 && cppVar_64;
	cppVar_67 = (conf_done == 1);
	cppVar_68 = cppVar_65 && cppVar_67;
	if (cppVar_68) {
	cppVar_69 = (conf_num_hidden >> 0) & cppMask_un_16_;
	cppVar_60 = cppVar_69;
	} else {
	cppVar_60 = num_hidden;
	}
	cppVar_56 = cppVar_60;
	}
	return cppVar_56;
}
