#include "common.hpp"
#include "model_compute_class.hpp"

void model_compute::update(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_337 = cppUpdateFun_index(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_338 = cppUpdateFun_loop_count(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_349 = cppUpdateFun_predict_input_done(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_360 = cppUpdateFun_rd_complete(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_365 = cppUpdateFun_rd_index(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_372 = cppUpdateFun_rd_length(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_377 = cppUpdateFun_rd_request(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_388 = cppUpdateFun_train_input_done(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_422 = cppUpdateFun_upc(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV8,65536> cppVar_423 = cppUpdateFun_edges(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	index = cppVar_337;
	loop_count = cppVar_338;
	predict_input_done = cppVar_349;
	rd_complete = cppVar_360;
	rd_index = cppVar_365;
	rd_length = cppVar_372;
	rd_request = cppVar_377;
	train_input_done = cppVar_388;
	upc = cppVar_422;
	edges = cppVar_423;
	return;
}
