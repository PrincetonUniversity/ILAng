#include "common.hpp"
#include "model_compute_class.hpp"

bool model_compute::assumps_0(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_424;
	bool cppVar_425;
	BIT_VEC cppVar_426;
	bool cppVar_427;
	bool cppVar_428;
	cppVar_425 = (init_done == 1);
	cppVar_427 = (done == 0);
	cppVar_428 = cppVar_425 && cppVar_427;
	return cppVar_428;
}
