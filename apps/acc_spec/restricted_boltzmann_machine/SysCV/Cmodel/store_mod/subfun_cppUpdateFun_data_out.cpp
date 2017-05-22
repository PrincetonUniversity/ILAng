#include "common.hpp"
#include "model_store_class.hpp"

BIT_VEC model_store::cppUpdateFun_data_out(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_277;
	BIT_VEC cppVar_278;
	BIT_VEC cppVar_279;
	cppVar_277 = (i >> 0) & cppMask_un_7_;
	cppVar_278 = predict_result.rd(cppVar_277);
	cppVar_279 = (cppVar_278 & cppMask_un_8_);
	return cppVar_279;
}
