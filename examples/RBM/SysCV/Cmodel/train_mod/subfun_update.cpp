#include "common.hpp"
#include "model_train_class.hpp"

void model_train::update(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_512 = cppUpdateFun_index(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_549 = cppUpdateFun_jstate(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_571 = cppUpdateFun_loop_count(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_618 = cppUpdateFun_per_v_pc(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_654 = cppUpdateFun_sumOfpow2(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_704 = cppUpdateFun_train_h_cnt(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_719 = cppUpdateFun_train_input_done(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_777 = cppUpdateFun_train_max(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_837 = cppUpdateFun_train_sum(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_884 = cppUpdateFun_train_upc(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_932 = cppUpdateFun_train_v_cnt(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_947 = cppUpdateFun_upc(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV8,65536> cppVar_990 = cppUpdateFun_edges(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV1,128> cppVar_1037 = cppUpdateFun_hidden_unit(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV1,65536> cppVar_1055 = cppUpdateFun_pos(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV32,8> cppVar_1086 = cppUpdateFun_pow2(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV16,8> cppVar_1144 = cppUpdateFun_visibleEnergies(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV1,512> cppVar_1195 = cppUpdateFun_visible_unit(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	index = cppVar_512;
	jstate = cppVar_549;
	loop_count = cppVar_571;
	per_v_pc = cppVar_618;
	sumOfpow2 = cppVar_654;
	train_h_cnt = cppVar_704;
	train_input_done = cppVar_719;
	train_max = cppVar_777;
	train_sum = cppVar_837;
	train_upc = cppVar_884;
	train_v_cnt = cppVar_932;
	upc = cppVar_947;
	edges = cppVar_990;
	hidden_unit = cppVar_1037;
	pos = cppVar_1055;
	pow2 = cppVar_1086;
	visibleEnergies = cppVar_1144;
	visible_unit = cppVar_1195;
	return;
}
