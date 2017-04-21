#include "common.hpp"

/****************************************************/
#ifndef MODEL_STORE_CLASS
#define MODEL_STORE_CLASS
class model_store
{
public:
	model_store():
	data(0),
	predict_result(0)
	{
		cppMask_un_16_ = ((BIT_VEC)1 << 16) - 1;
		cppMask_un_7_ = ((BIT_VEC)1 << 7) - 1;
		cppMask_un_8_ = ((BIT_VEC)1 << 8) - 1;
	};
	~model_store() {};
public:
	// State variables.
	type_mem<BV8,512> data;
	BIT_VEC data_out;
	BIT_VEC done;
	BIT_VEC i;
	BIT_VEC init_done;
	BIT_VEC num_hidden;
	BIT_VEC num_loops;
	BIT_VEC num_movies;
	BIT_VEC num_testusers;
	BIT_VEC num_users;
	BIT_VEC num_visible;
	type_mem<BV8,128> predict_result;
	BIT_VEC rd_complete;
	BIT_VEC rd_granted;
	BIT_VEC rd_index;
	BIT_VEC rd_length;
	BIT_VEC rd_request;
	BIT_VEC wr_complete;
	BIT_VEC wr_granted;
	BIT_VEC wr_index;
	BIT_VEC wr_length;
	BIT_VEC wr_request;
public:
	// Public functions: fetch, decode, update, ...
	bool assumps_0(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_data_out(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_i(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_wr_complete(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_wr_granted(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_wr_request(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	void update(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
private:
	// Bitvector masks.
	BIT_VEC cppMask_un_16_;
	BIT_VEC cppMask_un_7_;
	BIT_VEC cppMask_un_8_;

};

/****************************************************/
/****************************************************/
#endif
/****************************************************/
