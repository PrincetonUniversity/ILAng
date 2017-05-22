#include "common.hpp"
#include "model_RBM_class.hpp"

void model_RBM::update(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_39 = cppUpdateFun_data_out(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_40 = cppUpdateFun_done(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_55 = cppUpdateFun_init_done(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_70 = cppUpdateFun_num_hidden(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_85 = cppUpdateFun_num_loops(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_100 = cppUpdateFun_num_movies(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_115 = cppUpdateFun_num_testusers(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_130 = cppUpdateFun_num_users(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_145 = cppUpdateFun_num_visible(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_146 = cppUpdateFun_rd_complete(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_154 = cppUpdateFun_rd_granted(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_155 = cppUpdateFun_rd_index(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_156 = cppUpdateFun_rd_length(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_157 = cppUpdateFun_rd_request(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_158 = cppUpdateFun_wr_complete(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_164 = cppUpdateFun_wr_granted(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_165 = cppUpdateFun_wr_index(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_166 = cppUpdateFun_wr_length(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_167 = cppUpdateFun_wr_request(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV8,512> cppVar_177 = cppUpdateFun_data(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	data_out = cppVar_39;
	done = cppVar_40;
	init_done = cppVar_55;
	num_hidden = cppVar_70;
	num_loops = cppVar_85;
	num_movies = cppVar_100;
	num_testusers = cppVar_115;
	num_users = cppVar_130;
	num_visible = cppVar_145;
	rd_complete = cppVar_146;
	rd_granted = cppVar_154;
	rd_index = cppVar_155;
	rd_length = cppVar_156;
	rd_request = cppVar_157;
	wr_complete = cppVar_158;
	wr_granted = cppVar_164;
	wr_index = cppVar_165;
	wr_length = cppVar_166;
	wr_request = cppVar_167;
	data = cppVar_177;
	return;
}
