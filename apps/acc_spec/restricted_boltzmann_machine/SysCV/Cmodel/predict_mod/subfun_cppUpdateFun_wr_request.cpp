#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_wr_request(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1962;
	BIT_VEC cppVar_1942;
	bool cppVar_1943;
	BIT_VEC cppVar_1945;
	bool cppVar_1946;
	BIT_VEC cppVar_1948;
	bool cppVar_1949;
	BIT_VEC cppVar_1964;
	bool cppVar_1965;
	BIT_VEC cppVar_1951;
	BIT_VEC cppVar_1952;
	bool cppVar_1953;
	BIT_VEC cppVar_1954;
	BIT_VEC cppVar_1955;
	BIT_VEC cppVar_1956;
	bool cppVar_1957;
	bool cppVar_1958;
	BIT_VEC cppVar_1959;
	bool cppVar_1960;
	bool cppVar_1961;
	BIT_VEC cppVar_1950;
	BIT_VEC cppVar_1963;
	BIT_VEC cppVar_1947;
	BIT_VEC cppVar_1944;
	BIT_VEC cppVar_1941;
	cppVar_1943 = (predict_upc == 0);
	if (cppVar_1943) {
	cppVar_1941 = wr_request;
	} else {
	cppVar_1946 = (predict_upc == 1);
	if (cppVar_1946) {
	cppVar_1944 = wr_request;
	} else {
	cppVar_1949 = (predict_upc == 3);
	if (cppVar_1949) {
	cppVar_1952 = predict_v_cnt + 5;
	cppVar_1952 = (cppVar_1952 & cppMask_un_16_);
	cppVar_1953 = (cppVar_1952 == num_visible);
	cppVar_1955 = predict_v_cnt + 5;
	cppVar_1955 = (cppVar_1955 & cppMask_un_16_);
	cppVar_1957 = cppVar_1955 >= 500;
	cppVar_1958 = cppVar_1953 || cppVar_1957;
	cppVar_1960 = (jstate == 4);
	cppVar_1961 = cppVar_1958 && cppVar_1960;
	if (cppVar_1961) {
	cppVar_1950 = 1;
	} else {
	cppVar_1950 = wr_request;
	}
	cppVar_1947 = cppVar_1950;
	} else {
	cppVar_1965 = (predict_upc == 2);
	if (cppVar_1965) {
	cppVar_1963 = wr_request;
	} else {
	cppVar_1963 = wr_request;
	}
	cppVar_1947 = cppVar_1963;
	}
	cppVar_1944 = cppVar_1947;
	}
	cppVar_1941 = cppVar_1944;
	}
	return cppVar_1941;
}
