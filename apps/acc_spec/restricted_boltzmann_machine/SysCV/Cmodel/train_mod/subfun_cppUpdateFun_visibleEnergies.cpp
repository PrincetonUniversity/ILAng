#include "common.hpp"
#include "model_train_class.hpp"

type_mem<BV16,8> model_train::cppUpdateFun_visibleEnergies(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1088;
	bool cppVar_1089;
	BIT_VEC cppVar_1091;
	bool cppVar_1092;
	BIT_VEC cppVar_1142;
	bool cppVar_1143;
	BIT_VEC cppVar_1109;
	BIT_VEC cppVar_1110;
	BIT_VEC cppVar_1111;
	bool cppVar_1098;
	BIT_VEC cppVar_1094;
	bool cppVar_1095;
	bool cppVar_1096;
	BIT_VEC cppVar_1120;
	bool cppVar_1121;
	bool cppVar_1122;
	BIT_VEC cppVar_1134;
	bool cppVar_1135;
	bool cppVar_1136;
	BIT_VEC cppVar_1138;
	bool cppVar_1139;
	bool cppVar_1140;
	BIT_VEC cppVar_1101;
	bool cppVar_1102;
	BIT_VEC cppVar_1100;
	BIT_VEC cppVar_1105;
	BIT_VEC cppVar_1106;
	BIT_VEC cppVar_1107;
	bool cppVar_1108;
	BIT_VEC cppVar_1112;
	BIT_VEC cppVar_1113;
	BIT_VEC cppVar_1114;
	BIT_VEC cppVar_1115;
	BIT_VEC cppVar_1116;
	BIT_VEC cppVar_1104;
	BIT_VEC cppVar_1117;
	BIT_VEC cppVar_1099;
	type_mem<BV16,8> cppVar_1118;
	type_mem<BV16,8> cppVar_1097;
	BIT_VEC cppVar_1129;
	BIT_VEC cppVar_1127;
	bool cppVar_1128;
	BIT_VEC cppVar_1130;
	BIT_VEC cppVar_1126;
	BIT_VEC cppVar_1124;
	BIT_VEC cppVar_1125;
	BIT_VEC cppVar_1131;
	BIT_VEC cppVar_1123;
	type_mem<BV16,8> cppVar_1132;
	type_mem<BV16,8> cppVar_1137;
	type_mem<BV16,8> cppVar_1133;
	type_mem<BV16,8> cppVar_1119;
	type_mem<BV16,8> cppVar_1093;
	type_mem<BV16,8> cppVar_1141;
	type_mem<BV16,8> cppVar_1090;
	type_mem<BV16,8> cppVar_1087;
	BIT_VEC cppVar_1103;
	cppVar_1089 = (train_upc == 0);
	if (cppVar_1089) {
	cppVar_1087 = visibleEnergies;
	} else {
	cppVar_1092 = (train_upc == 1);
	if (cppVar_1092) {
	cppVar_1095 = (per_v_pc == 0);
	cppVar_1096 = cppVar_1092 && cppVar_1095;
	if (cppVar_1096) {
	cppVar_1098 = (train_h_cnt == num_hidden);
	if (cppVar_1098) {
	cppVar_1099 = (jstate >> 0) & cppMask_un_3_;
	cppVar_1102 = (train_h_cnt == 0);
	if (cppVar_1102) {
	cppVar_1100 = 0;
	} else {
	cppVar_1100 = train_sum;
	}
	cppVar_1105 = (train_h_cnt >> 0) & cppMask_un_7_;
	cppVar_1106 = hidden_unit.rd(cppVar_1105);
	cppVar_1108 = (cppVar_1106 == 1);
	if (cppVar_1108) {
	cppVar_1110 = 101 * train_v_cnt;
	cppVar_1110 = (cppVar_1110 & cppMask_un_16_);
	cppVar_1111 = cppVar_1110 + train_h_cnt;
	cppVar_1111 = (cppVar_1111 & cppMask_un_16_);
	cppVar_1112 = edges.rd(cppVar_1111);
	cppVar_1113 = (cppVar_1112 >> 1) & cppMask_un_7_;
	cppVar_1114 = ((cppVar_1113 & cppMask_bit_7_) ? (cppVar_1113 | cppMask_sign_7_) : cppVar_1113);
	cppVar_1115 = (cppVar_1112 >> 0) & cppMask_un_1_;
	cppVar_1116 = (cppVar_1114 << 1) | cppVar_1115;
	cppVar_1116 = (cppVar_1116 & cppMask_un_16_);
	cppVar_1104 = cppVar_1116;
	} else {
	cppVar_1104 = 0;
	}
	cppVar_1117 = cppVar_1100 + cppVar_1104;
	cppVar_1117 = (cppVar_1117 & cppMask_un_16_);
	cppVar_1118 = visibleEnergies;
	cppVar_1118.wr(cppVar_1099, cppVar_1117);
	cppVar_1097 = cppVar_1118;
	} else {
	cppVar_1097 = visibleEnergies;
	}
	cppVar_1093 = cppVar_1097;
	} else {
	cppVar_1121 = (per_v_pc == 1);
	cppVar_1122 = cppVar_1092 && cppVar_1121;
	if (cppVar_1122) {
	cppVar_1123 = (jstate >> 0) & cppMask_un_3_;
	cppVar_1124 = (jstate >> 0) & cppMask_un_3_;
	cppVar_1125 = visibleEnergies.rd(cppVar_1124);
	cppVar_1128 = (jstate == 0);
	if (cppVar_1128) {
	cppVar_1130 = train_max - 62;
	cppVar_1130 = (cppVar_1130 & cppMask_un_16_);
	cppVar_1126 = cppVar_1130;
	} else {
	cppVar_1126 = train_max;
	}
	cppVar_1131 = cppVar_1125 - cppVar_1126;
	cppVar_1131 = (cppVar_1131 & cppMask_un_16_);
	cppVar_1132 = visibleEnergies;
	cppVar_1132.wr(cppVar_1123, cppVar_1131);
	cppVar_1119 = cppVar_1132;
	} else {
	cppVar_1135 = (per_v_pc == 2);
	cppVar_1136 = cppVar_1092 && cppVar_1135;
	if (cppVar_1136) {
	cppVar_1133 = visibleEnergies;
	} else {
	cppVar_1139 = (per_v_pc == 3);
	cppVar_1140 = cppVar_1092 && cppVar_1139;
	if (cppVar_1140) {
	cppVar_1137 = visibleEnergies;
	} else {
	cppVar_1137 = visibleEnergies;
	}
	cppVar_1133 = cppVar_1137;
	}
	cppVar_1119 = cppVar_1133;
	}
	cppVar_1093 = cppVar_1119;
	}
	cppVar_1090 = cppVar_1093;
	} else {
	cppVar_1143 = (train_upc == 2);
	if (cppVar_1143) {
	cppVar_1141 = visibleEnergies;
	} else {
	cppVar_1141 = visibleEnergies;
	}
	cppVar_1090 = cppVar_1141;
	}
	cppVar_1087 = cppVar_1090;
	}
	return cppVar_1087;
}
