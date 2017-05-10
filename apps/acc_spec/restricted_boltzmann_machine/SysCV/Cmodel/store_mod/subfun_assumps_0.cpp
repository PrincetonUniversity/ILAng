#include "common.hpp"
#include "model_store_class.hpp"

bool model_store::assumps_0(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_299;
	bool cppVar_300;
	cppVar_300 = (wr_granted == 1);
	return cppVar_300;
}
