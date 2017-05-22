#include "common.hpp"
#include "model_predict_class.hpp"

void model_predict::update(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1299 = cppUpdateFun_count(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1323 = cppUpdateFun_done(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1353 = cppUpdateFun_expectation(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1377 = cppUpdateFun_index(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1426 = cppUpdateFun_jstate(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1479 = cppUpdateFun_per_v_pc(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1522 = cppUpdateFun_predict_h_cnt(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1539 = cppUpdateFun_predict_input_done(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1601 = cppUpdateFun_predict_max(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1665 = cppUpdateFun_predict_sum(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1722 = cppUpdateFun_predict_upc(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1771 = cppUpdateFun_predict_v_cnt(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1788 = cppUpdateFun_prediction(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1828 = cppUpdateFun_sumOfpow2(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1852 = cppUpdateFun_upc(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1884 = cppUpdateFun_wr_complete(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1913 = cppUpdateFun_wr_index(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1940 = cppUpdateFun_wr_length(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	BIT_VEC cppVar_1966 = cppUpdateFun_wr_request(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV1,128> cppVar_2021 = cppUpdateFun_hidden_unit(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV32,8> cppVar_2056 = cppUpdateFun_pow2(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV8,128> cppVar_2065 = cppUpdateFun_predict_result(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV1,512> cppVar_2103 = cppUpdateFun_predict_vector(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	type_mem<BV16,8> cppVar_2165 = cppUpdateFun_visibleEnergies(conf_done, conf_num_hidden, conf_num_loops, conf_num_movies, conf_num_testusers, conf_num_users, conf_num_visible, data_in, rd_grant, rst, wr_grant);
	count = cppVar_1299;
	done = cppVar_1323;
	expectation = cppVar_1353;
	index = cppVar_1377;
	jstate = cppVar_1426;
	per_v_pc = cppVar_1479;
	predict_h_cnt = cppVar_1522;
	predict_input_done = cppVar_1539;
	predict_max = cppVar_1601;
	predict_sum = cppVar_1665;
	predict_upc = cppVar_1722;
	predict_v_cnt = cppVar_1771;
	prediction = cppVar_1788;
	sumOfpow2 = cppVar_1828;
	upc = cppVar_1852;
	wr_complete = cppVar_1884;
	wr_index = cppVar_1913;
	wr_length = cppVar_1940;
	wr_request = cppVar_1966;
	hidden_unit = cppVar_2021;
	pow2 = cppVar_2056;
	predict_result = cppVar_2065;
	predict_vector = cppVar_2103;
	visibleEnergies = cppVar_2165;
	return;
}
