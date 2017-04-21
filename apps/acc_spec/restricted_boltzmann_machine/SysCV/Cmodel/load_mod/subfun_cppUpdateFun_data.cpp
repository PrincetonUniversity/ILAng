#include "common.hpp"
#include "model_DMAload_class.hpp"

type_mem<BV8,512> model_DMAload::cppUpdateFun_data(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_230;
	bool cppVar_231;
	BIT_VEC cppVar_236;
	bool cppVar_237;
	BIT_VEC cppVar_232;
	BIT_VEC cppVar_233;
	type_mem<BV8,512> cppVar_234;
	BIT_VEC cppVar_238;
	type_mem<BV8,512> cppVar_240;
	type_mem<BV8,512> cppVar_235;
	type_mem<BV8,512> cppVar_229;
	BIT_VEC cppVar_239;
	cppVar_230 = (rd_length >> 0) & cppMask_un_16_;
	cppVar_231 = i < cppVar_230;
	if (cppVar_231) {
	cppVar_232 = (i >> 0) & cppMask_un_9_;
	cppVar_233 = (data_in >> 0) & cppMask_un_8_;
	cppVar_234 = data;
	cppVar_234.wr(cppVar_232, cppVar_233);
	cppVar_229 = cppVar_234;
	} else {
	cppVar_236 = (rd_length >> 0) & cppMask_un_16_;
	cppVar_237 = (i == cppVar_236);
	if (cppVar_237) {
	cppVar_238 = (rd_length >> 0) & cppMask_un_9_;
	cppVar_240 = data;
	cppVar_240.wr(cppVar_238, 1);
	cppVar_235 = cppVar_240;
	} else {
	cppVar_235 = data;
	}
	cppVar_229 = cppVar_235;
	}
	return cppVar_229;
}
