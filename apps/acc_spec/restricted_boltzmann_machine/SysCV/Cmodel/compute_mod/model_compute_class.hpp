#include "common.hpp"

/****************************************************/
#ifndef MODEL_COMPUTE_CLASS
#define MODEL_COMPUTE_CLASS
class model_compute
{
public:
	model_compute():
	data(0),
	edges(0),
	predict_result(0)
	{
		cppMask_un_16_ = ((BIT_VEC)1 << 16) - 1;
		cppMask_un_32_ = ((BIT_VEC)1 << 32) - 1;
	};
	~model_compute() {};
public:
	// State variables.
	type_mem<BV8,512> data;
	BIT_VEC data_out;
	BIT_VEC done;
	type_mem<BV8,65536> edges;
	BIT_VEC index;
	BIT_VEC init_done;
	BIT_VEC loop_count;
	BIT_VEC num_hidden;
	BIT_VEC num_loops;
	BIT_VEC num_movies;
	BIT_VEC num_testusers;
	BIT_VEC num_users;
	BIT_VEC num_visible;
	BIT_VEC predict_input_done;
	type_mem<BV8,128> predict_result;
	BIT_VEC rd_complete;
	BIT_VEC rd_index;
	BIT_VEC rd_length;
	BIT_VEC rd_request;
	BIT_VEC train_input_done;
	BIT_VEC upc;
	BIT_VEC wr_complete;
	BIT_VEC wr_index;
	BIT_VEC wr_length;
	BIT_VEC wr_request;
public:
	// Public functions: fetch, decode, update, ...
	bool assumps_0(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	type_mem<BV8,65536> cppUpdateFun_edges(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_index(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_loop_count(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_predict_input_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_rd_complete(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_rd_index(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_rd_length(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_rd_request(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_train_input_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_upc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	void update(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
private:
	// Bitvector masks.
	BIT_VEC cppMask_un_16_;
	BIT_VEC cppMask_un_32_;

};

/****************************************************/
/****************************************************/
#endif
/****************************************************/
