#include "common.hpp"
#include "model_predict_class.hpp"

type_mem<BV1,512> model_predict::cppUpdateFun_predict_vector(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_2096;
	BIT_VEC cppVar_2095;
	BIT_VEC cppVar_2067;
	bool cppVar_2068;
	BIT_VEC cppVar_2070;
	bool cppVar_2071;
	BIT_VEC cppVar_2101;
	bool cppVar_2102;
	BIT_VEC cppVar_2086;
	bool cppVar_2087;
	BIT_VEC cppVar_2077;
	BIT_VEC cppVar_2078;
	bool cppVar_2079;
	BIT_VEC cppVar_2080;
	BIT_VEC cppVar_2081;
	BIT_VEC cppVar_2082;
	bool cppVar_2083;
	bool cppVar_2084;
	BIT_VEC cppVar_2073;
	bool cppVar_2074;
	bool cppVar_2075;
	BIT_VEC cppVar_2092;
	BIT_VEC cppVar_2093;
	bool cppVar_2094;
	BIT_VEC cppVar_2091;
	BIT_VEC cppVar_2089;
	BIT_VEC cppVar_2090;
	type_mem<BV1,512> cppVar_2097;
	bool cppVar_2085;
	bool cppVar_2088;
	BIT_VEC cppVar_2098;
	type_mem<BV1,512> cppVar_2099;
	type_mem<BV1,512> cppVar_2076;
	type_mem<BV1,512> cppVar_2072;
	type_mem<BV1,512> cppVar_2100;
	type_mem<BV1,512> cppVar_2069;
	type_mem<BV1,512> cppVar_2066;
	cppVar_2068 = (predict_upc == 0);
	if (cppVar_2068) {
	cppVar_2066 = predict_vector;
	} else {
	cppVar_2071 = (predict_upc == 1);
	if (cppVar_2071) {
	cppVar_2074 = (per_v_pc == 4);
	cppVar_2075 = cppVar_2071 && cppVar_2074;
	if (cppVar_2075) {
	cppVar_2078 = predict_v_cnt + 5;
	cppVar_2078 = (cppVar_2078 & cppMask_un_16_);
	cppVar_2079 = (cppVar_2078 == num_visible);
	cppVar_2081 = predict_v_cnt + 5;
	cppVar_2081 = (cppVar_2081 & cppMask_un_16_);
	cppVar_2083 = cppVar_2081 >= 500;
	cppVar_2084 = cppVar_2079 || cppVar_2083;
	cppVar_2085 = cppVar_2075 && cppVar_2084;
	cppVar_2087 = (jstate == 4);
	cppVar_2088 = cppVar_2085 && cppVar_2087;
	if (cppVar_2088) {
	cppVar_2089 = predict_v_cnt + jstate;
	cppVar_2089 = (cppVar_2089 & cppMask_un_16_);
	cppVar_2090 = (cppVar_2089 >> 0) & cppMask_un_9_;
	cppVar_2092 = round(expectation);
	cppVar_2093 = (cppVar_2092 & cppMask_un_8_);
	cppVar_2094 = (jstate == cppVar_2093);
	if (cppVar_2094) {
	cppVar_2091 = 1;
	} else {
	cppVar_2091 = 0;
	}
	cppVar_2097 = predict_vector;
	cppVar_2097.wr(cppVar_2090, cppVar_2091);
	cppVar_2098 = (num_visible >> 0) & cppMask_un_9_;
	cppVar_2099 = cppVar_2097;
	cppVar_2099.wr(cppVar_2098, 1);
	cppVar_2076 = cppVar_2099;
	} else {
	cppVar_2076 = cppVar_2097;
	}
	cppVar_2072 = cppVar_2076;
	} else {
	cppVar_2072 = predict_vector;
	}
	cppVar_2069 = cppVar_2072;
	} else {
	cppVar_2102 = (predict_upc == 2);
	if (cppVar_2102) {
	cppVar_2100 = predict_vector;
	} else {
	cppVar_2100 = predict_vector;
	}
	cppVar_2069 = cppVar_2100;
	}
	cppVar_2066 = cppVar_2069;
	}
	return cppVar_2066;
}
