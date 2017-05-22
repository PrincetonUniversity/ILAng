#include "common.hpp"

/****************************************************/
#ifndef MODEL_PREDICT_CLASS
#define MODEL_PREDICT_CLASS

typedef unsigned short u_16;
u_16 divide_p1;
u_16 divide_p2;
u_16 divide_r;

u_16 rand_r;

u_16 sigmoid_p1;
u_16 sigmoid_r;

u_16 to_int_exp_p1;
u_16 to_int_exp_r;

u_16 round_p1;
u_16 round_r;


bool t=false;

u_16 divide(BIT_VEC cppVar_480, BIT_VEC cppVar_481){
	BIT_VEC ret;
	if(cppVar_480 == divide_p1 && cppVar_481 == divide_p2)
		ret = divide_r;
	t = true;
	divide_p1 = cppVar_480; divide_p2 = cppVar_481; divide_r = ret;
	return ret;
}
u_16 rand(){
	return rand_r;
}
u_16 sigmoid(BIT_VEC cppVar_486){
	BIT_VEC ret;
	if(sigmoid_p1 == cppVar_486)
		ret = sigmoid_r;
	sigmoid_r = ret;
	sigmoid_p1 = cppVar_486;
	return ret;
}
u_16 to_int_exp(BIT_VEC cppVar_489){
	BIT_VEC ret;
	if(to_int_exp_p1 == cppVar_489) {
		ret = to_int_exp_r;
	}

	to_int_exp_r = ret;
	to_int_exp_p1 = cppVar_489;
	return ret;
}

u_16 round(BIT_VEC cppVar_1257) {
	BIT_VEC ret;
	if(cppVar_1257 == round_p1) {
		ret = round_r;
	}
	round_r = ret;
	round_p1 = cppVar_1257;
	return ret;
}

class model_predict
{
public:
	model_predict():
	data(0),
	edges(0),
	hidden_unit(0),
	pow2(0),
	predict_result(0),
	predict_vector(0),
	visibleEnergies(0)
	{
		cppMask_un_1_ = ((BIT_VEC)1 << 1) - 1;
		cppMask_un_16_ = ((BIT_VEC)1 << 16) - 1;
		cppMask_un_17_ = ((BIT_VEC)1 << 17) - 1;
		cppMask_un_29_ = ((BIT_VEC)1 << 29) - 1;
		cppMask_un_3_ = ((BIT_VEC)1 << 3) - 1;
		cppMask_un_32_ = ((BIT_VEC)1 << 32) - 1;
		cppMask_un_63_ = ((BIT_VEC)1 << 63) - 1;
		cppMask_un_64_ = ((BIT_VEC)-1);
		cppMask_un_7_ = ((BIT_VEC)1 << 7) - 1;
		cppMask_un_8_ = ((BIT_VEC)1 << 8) - 1;
		cppMask_un_80_ = ((BIT_VEC)-1);
		cppMask_un_9_ = ((BIT_VEC)1 << 9) - 1;
		cppMask_bit_16_ = (BIT_VEC)1 << (16 - 1);
		cppMask_bit_7_ = (BIT_VEC)1 << (7 - 1);
		cppMask_sign_16_ = ~cppMask_un_16_;
		cppMask_sign_7_ = ~cppMask_un_7_;
	};
	~model_predict() {};
public:
	// State variables.
	BIT_VEC count;
	type_mem<BV8,512> data;
	BIT_VEC data_out;
	BIT_VEC done;
	type_mem<BV8,65536> edges;
	BIT_VEC expectation;
	type_mem<BV1,128> hidden_unit;
	BIT_VEC index;
	BIT_VEC init_done;
	BIT_VEC jstate;
	BIT_VEC loop_count;
	BIT_VEC num_hidden;
	BIT_VEC num_loops;
	BIT_VEC num_movies;
	BIT_VEC num_testusers;
	BIT_VEC num_users;
	BIT_VEC num_visible;
	BIT_VEC per_v_pc;
	type_mem<BV32,8> pow2;
	BIT_VEC predict_h_cnt;
	BIT_VEC predict_input_done;
	BIT_VEC predict_max;
	type_mem<BV8,128> predict_result;
	BIT_VEC predict_sum;
	BIT_VEC predict_upc;
	BIT_VEC predict_v_cnt;
	type_mem<BV1,512> predict_vector;
	BIT_VEC prediction;
	BIT_VEC rd_complete;
	BIT_VEC rd_index;
	BIT_VEC rd_length;
	BIT_VEC rd_request;
	BIT_VEC sumOfpow2;
	BIT_VEC train_input_done;
	BIT_VEC upc;
	type_mem<BV16,8> visibleEnergies;
	BIT_VEC wr_complete;
	BIT_VEC wr_index;
	BIT_VEC wr_length;
	BIT_VEC wr_request;
public:
	// Public functions: fetch, decode, update, ...
	bool assumps_0(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_count(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_expectation(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	type_mem<BV1,128> cppUpdateFun_hidden_unit(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_index(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_jstate(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_per_v_pc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	type_mem<BV32,8> cppUpdateFun_pow2(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_predict_h_cnt(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_predict_input_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_predict_max(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	type_mem<BV8,128> cppUpdateFun_predict_result(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_predict_sum(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_predict_upc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_predict_v_cnt(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	type_mem<BV1,512> cppUpdateFun_predict_vector(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_prediction(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_sumOfpow2(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_upc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	type_mem<BV16,8> cppUpdateFun_visibleEnergies(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_wr_complete(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_wr_index(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_wr_length(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	BIT_VEC cppUpdateFun_wr_request(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
	void update(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant);
private:
	// Bitvector masks.
	BIT_VEC cppMask_un_1_;
	BIT_VEC cppMask_un_16_;
	BIT_VEC cppMask_un_17_;
	BIT_VEC cppMask_un_29_;
	BIT_VEC cppMask_un_3_;
	BIT_VEC cppMask_un_32_;
	BIT_VEC cppMask_un_63_;
	BIT_VEC cppMask_un_64_;
	BIT_VEC cppMask_un_7_;
	BIT_VEC cppMask_un_8_;
	BIT_VEC cppMask_un_80_;
	BIT_VEC cppMask_un_9_;
	BIT_VEC cppMask_bit_16_;
	BIT_VEC cppMask_bit_7_;
	BIT_VEC cppMask_sign_16_;
	BIT_VEC cppMask_sign_7_;

};

/****************************************************/
/****************************************************/
#endif
/****************************************************/
