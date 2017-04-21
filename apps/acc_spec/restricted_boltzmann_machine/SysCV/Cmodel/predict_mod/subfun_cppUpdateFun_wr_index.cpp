#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_wr_index(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1886;
	bool cppVar_1887;
	BIT_VEC cppVar_1889;
	bool cppVar_1890;
	BIT_VEC cppVar_1892;
	bool cppVar_1893;
	BIT_VEC cppVar_1911;
	bool cppVar_1912;
	BIT_VEC cppVar_1895;
	BIT_VEC cppVar_1896;
	bool cppVar_1897;
	BIT_VEC cppVar_1898;
	BIT_VEC cppVar_1899;
	BIT_VEC cppVar_1900;
	bool cppVar_1901;
	bool cppVar_1902;
	BIT_VEC cppVar_1903;
	bool cppVar_1904;
	bool cppVar_1905;
	BIT_VEC cppVar_1907;
	BIT_VEC cppVar_1908;
	BIT_VEC cppVar_1909;
	BIT_VEC cppVar_1894;
	BIT_VEC cppVar_1906;
	BIT_VEC cppVar_1910;
	BIT_VEC cppVar_1891;
	BIT_VEC cppVar_1888;
	BIT_VEC cppVar_1885;
	cppVar_1887 = (predict_upc == 0);
	if (cppVar_1887) {
	cppVar_1885 = wr_index;
	} else {
	cppVar_1890 = (predict_upc == 1);
	if (cppVar_1890) {
	cppVar_1888 = wr_index;
	} else {
	cppVar_1893 = (predict_upc == 3);
	if (cppVar_1893) {
	cppVar_1896 = predict_v_cnt + 5;
	cppVar_1896 = (cppVar_1896 & cppMask_un_16_);
	cppVar_1897 = (cppVar_1896 == num_visible);
	cppVar_1899 = predict_v_cnt + 5;
	cppVar_1899 = (cppVar_1899 & cppMask_un_16_);
	cppVar_1901 = cppVar_1899 >= 500;
	cppVar_1902 = cppVar_1897 || cppVar_1901;
	cppVar_1904 = (jstate == 4);
	cppVar_1905 = cppVar_1902 && cppVar_1904;
	if (cppVar_1905) {
	cppVar_1906 = (num_movies & cppMask_un_16_);
	cppVar_1907 = (cppVar_1906 & cppMask_un_32_);
	cppVar_1908 = (index & cppMask_un_16_);
	cppVar_1909 = cppVar_1907 * cppVar_1908;
	cppVar_1909 = (cppVar_1909 & cppMask_un_32_);
	cppVar_1894 = cppVar_1909;
	} else {
	cppVar_1894 = wr_index;
	}
	cppVar_1891 = cppVar_1894;
	} else {
	cppVar_1912 = (predict_upc == 2);
	if (cppVar_1912) {
	cppVar_1910 = wr_index;
	} else {
	cppVar_1910 = wr_index;
	}
	cppVar_1891 = cppVar_1910;
	}
	cppVar_1888 = cppVar_1891;
	}
	cppVar_1885 = cppVar_1888;
	}
	return cppVar_1885;
}
