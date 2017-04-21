#include "common.hpp"
#include "model_compute_class.hpp"

BIT_VEC model_compute::cppUpdateFun_rd_length(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_369;
	BIT_VEC cppVar_371;
	BIT_VEC cppVar_366;
	BIT_VEC cppVar_370;
	BIT_VEC cppVar_367;
	bool cppVar_368;
	cppVar_368 = (upc == 0);
	if (cppVar_368) {
	cppVar_370 = (num_movies & cppMask_un_16_);
	cppVar_371 = 5 * cppVar_370;
	cppVar_371 = (cppVar_371 & cppMask_un_32_);
	cppVar_366 = cppVar_371;
	} else {
	cppVar_366 = rd_length;
	}
	return cppVar_366;
}
