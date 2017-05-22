#include "common.hpp"
#include "model_predict_class.hpp"

type_mem<BV8,128> model_predict::cppUpdateFun_predict_result(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	type_mem<BV8,128> cppVar_2057;
	BIT_VEC cppVar_2058;
	bool cppVar_2059;
	BIT_VEC cppVar_2061;
	bool cppVar_2062;
	BIT_VEC cppVar_2063;
	type_mem<BV8,128> cppVar_2064;
	type_mem<BV8,128> cppVar_2060;
	cppVar_2059 = (predict_upc == 3);
	if (cppVar_2059) {
	cppVar_2062 = (jstate == 4);
	if (cppVar_2062) {
	cppVar_2063 = (count >> 0) & cppMask_un_7_;
	cppVar_2064 = predict_result;
	cppVar_2064.wr(cppVar_2063, prediction);
	cppVar_2060 = cppVar_2064;
	} else {
	cppVar_2060 = predict_result;
	}
	cppVar_2057 = cppVar_2060;
	} else {
	cppVar_2057 = predict_result;
	}
	return cppVar_2057;
}
