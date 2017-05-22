#include "common.hpp"
#include "model_train_class.hpp"

BIT_VEC model_train::cppUpdateFun_train_upc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_839;
	bool cppVar_840;
	BIT_VEC cppVar_848;
	BIT_VEC cppVar_850;
	bool cppVar_851;
	BIT_VEC cppVar_847;
	BIT_VEC cppVar_870;
	bool cppVar_871;
	BIT_VEC cppVar_868;
	BIT_VEC cppVar_878;
	bool cppVar_879;
	BIT_VEC cppVar_876;
	bool cppVar_842;
	BIT_VEC cppVar_843;
	BIT_VEC cppVar_844;
	bool cppVar_845;
	bool cppVar_846;
	BIT_VEC cppVar_841;
	BIT_VEC cppVar_856;
	bool cppVar_857;
	BIT_VEC cppVar_859;
	BIT_VEC cppVar_860;
	bool cppVar_861;
	BIT_VEC cppVar_862;
	BIT_VEC cppVar_863;
	BIT_VEC cppVar_864;
	bool cppVar_865;
	bool cppVar_866;
	BIT_VEC cppVar_853;
	bool cppVar_854;
	bool cppVar_855;
	bool cppVar_858;
	bool cppVar_867;
	BIT_VEC cppVar_852;
	bool cppVar_873;
	bool cppVar_874;
	bool cppVar_875;
	BIT_VEC cppVar_872;
	bool cppVar_881;
	bool cppVar_882;
	bool cppVar_883;
	BIT_VEC cppVar_880;
	BIT_VEC cppVar_877;
	BIT_VEC cppVar_869;
	BIT_VEC cppVar_849;
	BIT_VEC cppVar_838;
	cppVar_840 = (train_upc == 0);
	if (cppVar_840) {
	cppVar_842 = (train_v_cnt == num_visible);
	cppVar_844 = num_hidden - 1;
	cppVar_844 = (cppVar_844 & cppMask_un_16_);
	cppVar_845 = (train_h_cnt == cppVar_844);
	cppVar_846 = cppVar_842 && cppVar_845;
	if (cppVar_846) {
	cppVar_841 = 1;
	} else {
	cppVar_841 = 0;
	}
	cppVar_838 = cppVar_841;
	} else {
	cppVar_851 = (train_upc == 1);
	if (cppVar_851) {
	cppVar_854 = (per_v_pc == 3);
	cppVar_855 = cppVar_851 && cppVar_854;
	cppVar_857 = (jstate == 4);
	cppVar_858 = cppVar_855 && cppVar_857;
	cppVar_860 = train_v_cnt + 5;
	cppVar_860 = (cppVar_860 & cppMask_un_16_);
	cppVar_861 = (cppVar_860 == num_visible);
	cppVar_863 = train_v_cnt + 5;
	cppVar_863 = (cppVar_863 & cppMask_un_16_);
	cppVar_865 = cppVar_863 >= 500;
	cppVar_866 = cppVar_861 || cppVar_865;
	cppVar_867 = cppVar_858 && cppVar_866;
	if (cppVar_867) {
	cppVar_852 = 3;
	} else {
	cppVar_852 = 1;
	}
	cppVar_849 = cppVar_852;
	} else {
	cppVar_871 = (train_upc == 3);
	if (cppVar_871) {
	cppVar_873 = (train_h_cnt == num_hidden);
	cppVar_874 = (train_v_cnt == num_visible);
	cppVar_875 = cppVar_873 && cppVar_874;
	if (cppVar_875) {
	cppVar_872 = 2;
	} else {
	cppVar_872 = 3;
	}
	cppVar_869 = cppVar_872;
	} else {
	cppVar_879 = (train_upc == 2);
	if (cppVar_879) {
	cppVar_881 = (train_h_cnt == num_hidden);
	cppVar_882 = (train_v_cnt == num_visible);
	cppVar_883 = cppVar_881 && cppVar_882;
	if (cppVar_883) {
	cppVar_880 = 2;
	} else {
	cppVar_880 = 2;
	}
	cppVar_877 = cppVar_880;
	} else {
	cppVar_877 = train_upc;
	}
	cppVar_869 = cppVar_877;
	}
	cppVar_849 = cppVar_869;
	}
	cppVar_838 = cppVar_849;
	}
	return cppVar_838;
}
