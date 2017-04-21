#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_upc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1851;
	BIT_VEC cppVar_1850;
	BIT_VEC cppVar_1830;
	bool cppVar_1831;
	BIT_VEC cppVar_1833;
	bool cppVar_1834;
	BIT_VEC cppVar_1836;
	bool cppVar_1837;
	BIT_VEC cppVar_1839;
	bool cppVar_1840;
	BIT_VEC cppVar_1841;
	bool cppVar_1842;
	bool cppVar_1843;
	BIT_VEC cppVar_1845;
	BIT_VEC cppVar_1846;
	bool cppVar_1847;
	bool cppVar_1848;
	bool cppVar_1849;
	BIT_VEC cppVar_1844;
	BIT_VEC cppVar_1838;
	BIT_VEC cppVar_1835;
	BIT_VEC cppVar_1832;
	BIT_VEC cppVar_1829;
	cppVar_1831 = (predict_upc == 0);
	if (cppVar_1831) {
	cppVar_1829 = upc;
	} else {
	cppVar_1834 = (predict_upc == 1);
	if (cppVar_1834) {
	cppVar_1832 = upc;
	} else {
	cppVar_1837 = (predict_upc == 2);
	if (cppVar_1837) {
	cppVar_1840 = (wr_request == 0);
	cppVar_1842 = (wr_complete == 1);
	cppVar_1843 = cppVar_1840 && cppVar_1842;
	if (cppVar_1843) {
	cppVar_1846 = num_testusers - 1;
	cppVar_1846 = (cppVar_1846 & cppMask_un_16_);
	cppVar_1847 = (index == cppVar_1846);
	cppVar_1848 = (loop_count == num_loops);
	cppVar_1849 = cppVar_1847 && cppVar_1848;
	if (cppVar_1849) {
	cppVar_1844 = 3;
	} else {
	cppVar_1844 = 0;
	}
	cppVar_1838 = cppVar_1844;
	} else {
	cppVar_1838 = upc;
	}
	cppVar_1835 = cppVar_1838;
	} else {
	cppVar_1835 = upc;
	}
	cppVar_1832 = cppVar_1835;
	}
	cppVar_1829 = cppVar_1832;
	}
	return cppVar_1829;
}
