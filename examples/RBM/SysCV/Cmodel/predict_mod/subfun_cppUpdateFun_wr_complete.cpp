#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_wr_complete(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1874;
	BIT_VEC cppVar_1854;
	bool cppVar_1855;
	BIT_VEC cppVar_1857;
	bool cppVar_1858;
	BIT_VEC cppVar_1860;
	bool cppVar_1861;
	BIT_VEC cppVar_1876;
	bool cppVar_1877;
	BIT_VEC cppVar_1863;
	BIT_VEC cppVar_1864;
	bool cppVar_1865;
	BIT_VEC cppVar_1866;
	BIT_VEC cppVar_1867;
	BIT_VEC cppVar_1868;
	bool cppVar_1869;
	bool cppVar_1870;
	BIT_VEC cppVar_1871;
	bool cppVar_1872;
	bool cppVar_1873;
	BIT_VEC cppVar_1862;
	BIT_VEC cppVar_1879;
	bool cppVar_1880;
	BIT_VEC cppVar_1881;
	bool cppVar_1882;
	bool cppVar_1883;
	BIT_VEC cppVar_1878;
	BIT_VEC cppVar_1875;
	BIT_VEC cppVar_1859;
	BIT_VEC cppVar_1856;
	BIT_VEC cppVar_1853;
	cppVar_1855 = (predict_upc == 0);
	if (cppVar_1855) {
	cppVar_1853 = wr_complete;
	} else {
	cppVar_1858 = (predict_upc == 1);
	if (cppVar_1858) {
	cppVar_1856 = wr_complete;
	} else {
	cppVar_1861 = (predict_upc == 3);
	if (cppVar_1861) {
	cppVar_1864 = predict_v_cnt + 5;
	cppVar_1864 = (cppVar_1864 & cppMask_un_16_);
	cppVar_1865 = (cppVar_1864 == num_visible);
	cppVar_1867 = predict_v_cnt + 5;
	cppVar_1867 = (cppVar_1867 & cppMask_un_16_);
	cppVar_1869 = cppVar_1867 >= 500;
	cppVar_1870 = cppVar_1865 || cppVar_1869;
	cppVar_1872 = (jstate == 4);
	cppVar_1873 = cppVar_1870 && cppVar_1872;
	if (cppVar_1873) {
	cppVar_1862 = 0;
	} else {
	cppVar_1862 = wr_complete;
	}
	cppVar_1859 = cppVar_1862;
	} else {
	cppVar_1877 = (predict_upc == 2);
	if (cppVar_1877) {
	cppVar_1880 = (wr_request == 0);
	cppVar_1882 = (wr_complete == 1);
	cppVar_1883 = cppVar_1880 && cppVar_1882;
	if (cppVar_1883) {
	cppVar_1878 = 0;
	} else {
	cppVar_1878 = wr_complete;
	}
	cppVar_1875 = cppVar_1878;
	} else {
	cppVar_1875 = wr_complete;
	}
	cppVar_1859 = cppVar_1875;
	}
	cppVar_1856 = cppVar_1859;
	}
	cppVar_1853 = cppVar_1856;
	}
	return cppVar_1853;
}
