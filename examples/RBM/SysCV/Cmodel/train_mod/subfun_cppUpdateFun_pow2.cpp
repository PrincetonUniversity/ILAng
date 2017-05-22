#include "common.hpp"
#include "model_train_class.hpp"

type_mem<BV32,8> model_train::cppUpdateFun_pow2(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1057;
	bool cppVar_1058;
	BIT_VEC cppVar_1060;
	bool cppVar_1061;
	BIT_VEC cppVar_1084;
	bool cppVar_1085;
	BIT_VEC cppVar_1063;
	bool cppVar_1064;
	bool cppVar_1065;
	BIT_VEC cppVar_1067;
	bool cppVar_1068;
	bool cppVar_1069;
	BIT_VEC cppVar_1071;
	bool cppVar_1072;
	bool cppVar_1073;
	BIT_VEC cppVar_1080;
	bool cppVar_1081;
	bool cppVar_1082;
	BIT_VEC cppVar_1075;
	BIT_VEC cppVar_1076;
	BIT_VEC cppVar_1077;
	BIT_VEC cppVar_1074;
	type_mem<BV32,8> cppVar_1078;
	type_mem<BV32,8> cppVar_1079;
	type_mem<BV32,8> cppVar_1070;
	type_mem<BV32,8> cppVar_1066;
	type_mem<BV32,8> cppVar_1062;
	type_mem<BV32,8> cppVar_1083;
	type_mem<BV32,8> cppVar_1059;
	type_mem<BV32,8> cppVar_1056;
	cppVar_1058 = (train_upc == 0);
	if (cppVar_1058) {
	cppVar_1056 = pow2;
	} else {
	cppVar_1061 = (train_upc == 1);
	if (cppVar_1061) {
	cppVar_1064 = (per_v_pc == 0);
	cppVar_1065 = cppVar_1061 && cppVar_1064;
	if (cppVar_1065) {
	cppVar_1062 = pow2;
	} else {
	cppVar_1068 = (per_v_pc == 1);
	cppVar_1069 = cppVar_1061 && cppVar_1068;
	if (cppVar_1069) {
	cppVar_1066 = pow2;
	} else {
	cppVar_1072 = (per_v_pc == 2);
	cppVar_1073 = cppVar_1061 && cppVar_1072;
	if (cppVar_1073) {
	cppVar_1074 = (jstate >> 0) & cppMask_un_3_;
	cppVar_1075 = (jstate >> 0) & cppMask_un_3_;
	cppVar_1076 = visibleEnergies.rd(cppVar_1075);
	cppVar_1077 = to_int_exp(cppVar_1076);
	cppVar_1078 = pow2;
	cppVar_1078.wr(cppVar_1074, cppVar_1077);
	cppVar_1070 = cppVar_1078;
	} else {
	cppVar_1081 = (per_v_pc == 3);
	cppVar_1082 = cppVar_1061 && cppVar_1081;
	if (cppVar_1082) {
	cppVar_1079 = pow2;
	} else {
	cppVar_1079 = pow2;
	}
	cppVar_1070 = cppVar_1079;
	}
	cppVar_1066 = cppVar_1070;
	}
	cppVar_1062 = cppVar_1066;
	}
	cppVar_1059 = cppVar_1062;
	} else {
	cppVar_1085 = (train_upc == 2);
	if (cppVar_1085) {
	cppVar_1083 = pow2;
	} else {
	cppVar_1083 = pow2;
	}
	cppVar_1059 = cppVar_1083;
	}
	cppVar_1056 = cppVar_1059;
	}
	return cppVar_1056;
}
