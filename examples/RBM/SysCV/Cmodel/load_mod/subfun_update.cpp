#include "common.hpp"
#include "model_DMAload_class.hpp"

void model_DMAload::update(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_215 = cppUpdateFun_i(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_221 = cppUpdateFun_rd_complete(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_226 = cppUpdateFun_rd_granted(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_228 = cppUpdateFun_rd_request(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV8,512> cppVar_241 = cppUpdateFun_data(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	i = cppVar_215;
	rd_complete = cppVar_221;
	rd_granted = cppVar_226;
	rd_request = 0;
	data = cppVar_241;
	return;
}
