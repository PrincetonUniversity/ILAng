#include "common.hpp"
#include "model_train_class.hpp"

type_mem<BV1,128> model_train::cppUpdateFun_hidden_unit(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_992;
	bool cppVar_993;
	BIT_VEC cppVar_1032;
	bool cppVar_1033;
	BIT_VEC cppVar_1035;
	bool cppVar_1036;
	BIT_VEC cppVar_1014;
	BIT_VEC cppVar_1015;
	BIT_VEC cppVar_1016;
	BIT_VEC cppVar_1006;
	bool cppVar_1007;
	BIT_VEC cppVar_1008;
	BIT_VEC cppVar_1005;
	BIT_VEC cppVar_1010;
	BIT_VEC cppVar_1011;
	BIT_VEC cppVar_1012;
	bool cppVar_1013;
	BIT_VEC cppVar_1017;
	BIT_VEC cppVar_1018;
	BIT_VEC cppVar_1019;
	BIT_VEC cppVar_1020;
	BIT_VEC cppVar_1021;
	BIT_VEC cppVar_1022;
	BIT_VEC cppVar_1009;
	BIT_VEC cppVar_1023;
	BIT_VEC cppVar_1004;
	BIT_VEC cppVar_1024;
	bool cppVar_1025;
	BIT_VEC cppVar_1003;
	bool cppVar_1001;
	BIT_VEC cppVar_1002;
	type_mem<BV1,128> cppVar_1028;
	type_mem<BV1,128> cppVar_1000;
	bool cppVar_995;
	BIT_VEC cppVar_996;
	BIT_VEC cppVar_997;
	bool cppVar_998;
	bool cppVar_999;
	BIT_VEC cppVar_1029;
	type_mem<BV1,128> cppVar_1030;
	type_mem<BV1,128> cppVar_994;
	BIT_VEC cppVar_1027;
	BIT_VEC cppVar_1026;
	type_mem<BV1,128> cppVar_1034;
	type_mem<BV1,128> cppVar_1031;
	type_mem<BV1,128> cppVar_991;
	cppVar_993 = (train_upc == 0);
	if (cppVar_993) {
	cppVar_995 = (train_v_cnt == num_visible);
	cppVar_997 = num_hidden - 1;
	cppVar_997 = (cppVar_997 & cppMask_un_16_);
	cppVar_998 = (train_h_cnt == cppVar_997);
	cppVar_999 = cppVar_995 && cppVar_998;
	if (cppVar_999) {
	cppVar_1001 = (train_v_cnt == num_visible);
	if (cppVar_1001) {
	cppVar_1002 = (train_h_cnt >> 0) & cppMask_un_7_;
	cppVar_1004 = rand();
	cppVar_1007 = (train_v_cnt == 0);
	if (cppVar_1007) {
	cppVar_1005 = 0;
	} else {
	cppVar_1005 = train_sum;
	}
	cppVar_1010 = (train_v_cnt >> 0) & cppMask_un_9_;
	cppVar_1011 = data.rd(cppVar_1010);
	cppVar_1013 = (cppVar_1011 == 1);
	if (cppVar_1013) {
	cppVar_1015 = 101 * train_v_cnt;
	cppVar_1015 = (cppVar_1015 & cppMask_un_16_);
	cppVar_1016 = cppVar_1015 + train_h_cnt;
	cppVar_1016 = (cppVar_1016 & cppMask_un_16_);
	cppVar_1017 = edges.rd(cppVar_1016);
	cppVar_1018 = (cppVar_1017 >> 1) & cppMask_un_7_;
	cppVar_1019 = ((cppVar_1018 & cppMask_bit_7_) ? (cppVar_1018 | cppMask_sign_7_) : cppVar_1018);
	cppVar_1020 = (cppVar_1017 >> 0) & cppMask_un_1_;
	cppVar_1021 = (cppVar_1019 << 1) | cppVar_1020;
	cppVar_1021 = (cppVar_1021 & cppMask_un_16_);
	cppVar_1009 = cppVar_1021;
	} else {
	cppVar_1009 = 0;
	}
	cppVar_1023 = cppVar_1005 + cppVar_1009;
	cppVar_1023 = (cppVar_1023 & cppMask_un_16_);
	cppVar_1024 = sigmoid(cppVar_1023);
	cppVar_1025 = cppVar_1004 < cppVar_1024;
	if (cppVar_1025) {
	cppVar_1003 = 1;
	} else {
	cppVar_1003 = 0;
	}
	cppVar_1028 = hidden_unit;
	cppVar_1028.wr(cppVar_1002, cppVar_1003);
	cppVar_1000 = cppVar_1028;
	} else {
	cppVar_1000 = hidden_unit;
	}
	cppVar_1029 = (num_hidden >> 0) & cppMask_un_7_;
	cppVar_1030 = cppVar_1000;
	cppVar_1030.wr(cppVar_1029, 1);
	cppVar_994 = cppVar_1030;
	} else {
	cppVar_994 = cppVar_1000;
	}
	cppVar_991 = cppVar_994;
	} else {
	cppVar_1033 = (train_upc == 1);
	if (cppVar_1033) {
	cppVar_1031 = hidden_unit;
	} else {
	cppVar_1036 = (train_upc == 2);
	if (cppVar_1036) {
	cppVar_1034 = hidden_unit;
	} else {
	cppVar_1034 = hidden_unit;
	}
	cppVar_1031 = cppVar_1034;
	}
	cppVar_991 = cppVar_1031;
	}
	return cppVar_991;
}
