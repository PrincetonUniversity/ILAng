#include "common.hpp"
#include "model_DMAload_class.hpp"

bool model_DMAload::assumps_0(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_242;
	bool cppVar_243;
	cppVar_243 = (rd_granted == 1);
	return cppVar_243;
}
