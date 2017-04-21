#include "common.hpp"
#include "model_predict_class.hpp"

bool model_predict::assumps_0(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_2166;
	bool cppVar_2167;
	cppVar_2167 = (predict_input_done == 1);
	return cppVar_2167;
}
