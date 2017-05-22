#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_train_v_cnt(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_886;
	bool cppVar_887;
	BIT_VEC cppVar_894;
	bool cppVar_895;
	BIT_VEC cppVar_915;
	bool cppVar_916;
	BIT_VEC cppVar_924;
	bool cppVar_925;
	bool cppVar_889;
	BIT_VEC cppVar_891;
	BIT_VEC cppVar_892;
	BIT_VEC cppVar_888;
	BIT_VEC cppVar_900;
	bool cppVar_901;
	BIT_VEC cppVar_904;
	BIT_VEC cppVar_905;
	bool cppVar_906;
	BIT_VEC cppVar_907;
	BIT_VEC cppVar_908;
	BIT_VEC cppVar_909;
	bool cppVar_910;
	bool cppVar_911;
	BIT_VEC cppVar_897;
	bool cppVar_898;
	bool cppVar_899;
	bool cppVar_902;
	BIT_VEC cppVar_912;
	BIT_VEC cppVar_913;
	BIT_VEC cppVar_903;
	BIT_VEC cppVar_896;
	bool cppVar_918;
	bool cppVar_920;
	BIT_VEC cppVar_921;
	BIT_VEC cppVar_922;
	BIT_VEC cppVar_919;
	BIT_VEC cppVar_917;
	bool cppVar_927;
	bool cppVar_929;
	BIT_VEC cppVar_930;
	BIT_VEC cppVar_931;
	BIT_VEC cppVar_928;
	BIT_VEC cppVar_926;
	BIT_VEC cppVar_923;
	BIT_VEC cppVar_914;
	BIT_VEC cppVar_893;
	BIT_VEC cppVar_885;
	BIT_VEC cppVar_890;
	cppVar_887 = (train_upc == 0);
	if (cppVar_887) {
	cppVar_889 = (train_v_cnt == num_visible);
	if (cppVar_889) {
	cppVar_888 = 0;
	} else {
	cppVar_892 = train_v_cnt + 1;
	cppVar_892 = (cppVar_892 & cppMask_un_16_);
	cppVar_888 = cppVar_892;
	}
	cppVar_885 = cppVar_888;
	} else {
	cppVar_895 = (train_upc == 1);
	if (cppVar_895) {
	cppVar_898 = (per_v_pc == 3);
	cppVar_899 = cppVar_895 && cppVar_898;
	cppVar_901 = (jstate == 4);
	cppVar_902 = cppVar_899 && cppVar_901;
	if (cppVar_902) {
	cppVar_905 = train_v_cnt + 5;
	cppVar_905 = (cppVar_905 & cppMask_un_16_);
	cppVar_906 = (cppVar_905 == num_visible);
	cppVar_908 = train_v_cnt + 5;
	cppVar_908 = (cppVar_908 & cppMask_un_16_);
	cppVar_910 = cppVar_908 >= 500;
	cppVar_911 = cppVar_906 || cppVar_910;
	if (cppVar_911) {
	cppVar_903 = 0;
	} else {
	cppVar_913 = train_v_cnt + 5;
	cppVar_913 = (cppVar_913 & cppMask_un_16_);
	cppVar_903 = cppVar_913;
	}
	cppVar_896 = cppVar_903;
	} else {
	cppVar_896 = train_v_cnt;
	}
	cppVar_893 = cppVar_896;
	} else {
	cppVar_916 = (train_upc == 3);
	if (cppVar_916) {
	cppVar_918 = (train_h_cnt == num_hidden);
	if (cppVar_918) {
	cppVar_920 = (train_v_cnt == num_visible);
	if (cppVar_920) {
	cppVar_919 = 0;
	} else {
	cppVar_922 = train_v_cnt + 1;
	cppVar_922 = (cppVar_922 & cppMask_un_16_);
	cppVar_919 = cppVar_922;
	}
	cppVar_917 = cppVar_919;
	} else {
	cppVar_917 = train_v_cnt;
	}
	cppVar_914 = cppVar_917;
	} else {
	cppVar_925 = (train_upc == 2);
	if (cppVar_925) {
	cppVar_927 = (train_h_cnt == num_hidden);
	if (cppVar_927) {
	cppVar_929 = (train_v_cnt == num_visible);
	if (cppVar_929) {
	cppVar_928 = train_v_cnt;
	} else {
	cppVar_931 = train_v_cnt + 1;
	cppVar_931 = (cppVar_931 & cppMask_un_16_);
	cppVar_928 = cppVar_931;
	}
	cppVar_926 = cppVar_928;
	} else {
	cppVar_926 = train_v_cnt;
	}
	cppVar_923 = cppVar_926;
	} else {
	cppVar_923 = train_v_cnt;
	}
	cppVar_914 = cppVar_923;
	}
	cppVar_893 = cppVar_914;
	}
	cppVar_885 = cppVar_893;
	}
	return cppVar_885;
}
