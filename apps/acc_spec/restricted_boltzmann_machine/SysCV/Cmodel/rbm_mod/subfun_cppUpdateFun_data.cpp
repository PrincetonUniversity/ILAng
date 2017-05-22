#include "common.hpp"
#include "model_RBM_class.hpp"

type_mem<BV8,512> model_RBM::cppUpdateFun_data(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_174;
	BIT_VEC cppVar_175;
	type_mem<BV8,512> cppVar_176;
	type_mem<BV8,512> cppVar_168;
	BIT_VEC cppVar_169;
	bool cppVar_170;
	BIT_VEC cppVar_171;
	bool cppVar_172;
	bool cppVar_173;
	cppVar_170 = (rd_request == 1);
	cppVar_172 = (rd_grant == 1);
	cppVar_173 = cppVar_170 && cppVar_172;
	if (cppVar_173) {
	cppVar_175 = (data_in >> 0) & cppMask_un_8_;
	cppVar_176 = data;
	cppVar_176.wr(0, cppVar_175);
	cppVar_168 = cppVar_176;
	} else {
	cppVar_168 = data;
	}
	return cppVar_168;
}
