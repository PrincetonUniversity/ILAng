#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_wr_length(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1915;
	bool cppVar_1916;
	BIT_VEC cppVar_1918;
	bool cppVar_1919;
	BIT_VEC cppVar_1921;
	bool cppVar_1922;
	BIT_VEC cppVar_1938;
	bool cppVar_1939;
	BIT_VEC cppVar_1924;
	BIT_VEC cppVar_1925;
	bool cppVar_1926;
	BIT_VEC cppVar_1927;
	BIT_VEC cppVar_1928;
	BIT_VEC cppVar_1929;
	bool cppVar_1930;
	bool cppVar_1931;
	BIT_VEC cppVar_1932;
	bool cppVar_1933;
	bool cppVar_1934;
	BIT_VEC cppVar_1936;
	BIT_VEC cppVar_1923;
	BIT_VEC cppVar_1935;
	BIT_VEC cppVar_1937;
	BIT_VEC cppVar_1920;
	BIT_VEC cppVar_1917;
	BIT_VEC cppVar_1914;
	cppVar_1916 = (predict_upc == 0);
	if (cppVar_1916) {
	cppVar_1914 = wr_length;
	} else {
	cppVar_1919 = (predict_upc == 1);
	if (cppVar_1919) {
	cppVar_1917 = wr_length;
	} else {
	cppVar_1922 = (predict_upc == 3);
	if (cppVar_1922) {
	cppVar_1925 = predict_v_cnt + 5;
	cppVar_1925 = (cppVar_1925 & cppMask_un_16_);
	cppVar_1926 = (cppVar_1925 == num_visible);
	cppVar_1928 = predict_v_cnt + 5;
	cppVar_1928 = (cppVar_1928 & cppMask_un_16_);
	cppVar_1930 = cppVar_1928 >= 500;
	cppVar_1931 = cppVar_1926 || cppVar_1930;
	cppVar_1933 = (jstate == 4);
	cppVar_1934 = cppVar_1931 && cppVar_1933;
	if (cppVar_1934) {
	cppVar_1935 = (num_movies & cppMask_un_16_);
	cppVar_1936 = (cppVar_1935 & cppMask_un_32_);
	cppVar_1923 = cppVar_1936;
	} else {
	cppVar_1923 = wr_length;
	}
	cppVar_1920 = cppVar_1923;
	} else {
	cppVar_1939 = (predict_upc == 2);
	if (cppVar_1939) {
	cppVar_1937 = wr_length;
	} else {
	cppVar_1937 = wr_length;
	}
	cppVar_1920 = cppVar_1937;
	}
	cppVar_1917 = cppVar_1920;
	}
	cppVar_1914 = cppVar_1917;
	}
	return cppVar_1914;
}
