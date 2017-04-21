#include "common.hpp"
#include "model_train_class.hpp"

type_mem<BV1,512> model_train::cppUpdateFun_visible_unit(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1146;
	bool cppVar_1147;
	BIT_VEC cppVar_1149;
	bool cppVar_1150;
	BIT_VEC cppVar_1193;
	bool cppVar_1194;
	BIT_VEC cppVar_1168;
	bool cppVar_1169;
	BIT_VEC cppVar_1170;
	BIT_VEC cppVar_1171;
	bool cppVar_1172;
	BIT_VEC cppVar_1173;
	BIT_VEC cppVar_1174;
	BIT_VEC cppVar_1175;
	bool cppVar_1176;
	bool cppVar_1177;
	BIT_VEC cppVar_1152;
	bool cppVar_1153;
	bool cppVar_1154;
	BIT_VEC cppVar_1156;
	bool cppVar_1157;
	bool cppVar_1158;
	BIT_VEC cppVar_1160;
	bool cppVar_1161;
	bool cppVar_1162;
	BIT_VEC cppVar_1164;
	bool cppVar_1165;
	bool cppVar_1166;
	BIT_VEC cppVar_1182;
	BIT_VEC cppVar_1183;
	BIT_VEC cppVar_1184;
	BIT_VEC cppVar_1185;
	bool cppVar_1186;
	BIT_VEC cppVar_1181;
	BIT_VEC cppVar_1179;
	BIT_VEC cppVar_1180;
	type_mem<BV1,512> cppVar_1189;
	bool cppVar_1178;
	BIT_VEC cppVar_1190;
	type_mem<BV1,512> cppVar_1191;
	type_mem<BV1,512> cppVar_1167;
	type_mem<BV1,512> cppVar_1163;
	type_mem<BV1,512> cppVar_1159;
	type_mem<BV1,512> cppVar_1155;
	type_mem<BV1,512> cppVar_1151;
	BIT_VEC cppVar_1188;
	BIT_VEC cppVar_1187;
	type_mem<BV1,512> cppVar_1192;
	type_mem<BV1,512> cppVar_1148;
	type_mem<BV1,512> cppVar_1145;
	cppVar_1147 = (train_upc == 0);
	if (cppVar_1147) {
	cppVar_1145 = visible_unit;
	} else {
	cppVar_1150 = (train_upc == 1);
	if (cppVar_1150) {
	cppVar_1153 = (per_v_pc == 0);
	cppVar_1154 = cppVar_1150 && cppVar_1153;
	if (cppVar_1154) {
	cppVar_1151 = visible_unit;
	} else {
	cppVar_1157 = (per_v_pc == 1);
	cppVar_1158 = cppVar_1150 && cppVar_1157;
	if (cppVar_1158) {
	cppVar_1155 = visible_unit;
	} else {
	cppVar_1161 = (per_v_pc == 2);
	cppVar_1162 = cppVar_1150 && cppVar_1161;
	if (cppVar_1162) {
	cppVar_1159 = visible_unit;
	} else {
	cppVar_1165 = (per_v_pc == 3);
	cppVar_1166 = cppVar_1150 && cppVar_1165;
	if (cppVar_1166) {
	cppVar_1169 = (jstate == 4);
	cppVar_1171 = train_v_cnt + 5;
	cppVar_1171 = (cppVar_1171 & cppMask_un_16_);
	cppVar_1172 = (cppVar_1171 == num_visible);
	cppVar_1174 = train_v_cnt + 5;
	cppVar_1174 = (cppVar_1174 & cppMask_un_16_);
	cppVar_1176 = cppVar_1174 >= 500;
	cppVar_1177 = cppVar_1172 || cppVar_1176;
	cppVar_1178 = cppVar_1169 && cppVar_1177;
	if (cppVar_1178) {
	cppVar_1179 = train_v_cnt + jstate;
	cppVar_1179 = (cppVar_1179 & cppMask_un_16_);
	cppVar_1180 = (cppVar_1179 >> 0) & cppMask_un_9_;
	cppVar_1182 = (jstate >> 0) & cppMask_un_3_;
	cppVar_1183 = pow2.rd(cppVar_1182);
	cppVar_1184 = divide(cppVar_1183, sumOfpow2);
	cppVar_1185 = rand();
	cppVar_1186 = cppVar_1184 > cppVar_1185;
	if (cppVar_1186) {
	cppVar_1181 = 1;
	} else {
	cppVar_1181 = 0;
	}
	cppVar_1189 = visible_unit;
	cppVar_1189.wr(cppVar_1180, cppVar_1181);
	cppVar_1190 = (num_visible >> 0) & cppMask_un_9_;
	cppVar_1191 = cppVar_1189;
	cppVar_1191.wr(cppVar_1190, 1);
	cppVar_1167 = cppVar_1191;
	} else {
	cppVar_1167 = cppVar_1189;
	}
	cppVar_1163 = cppVar_1167;
	} else {
	cppVar_1163 = visible_unit;
	}
	cppVar_1159 = cppVar_1163;
	}
	cppVar_1155 = cppVar_1159;
	}
	cppVar_1151 = cppVar_1155;
	}
	cppVar_1148 = cppVar_1151;
	} else {
	cppVar_1194 = (train_upc == 2);
	if (cppVar_1194) {
	cppVar_1192 = visible_unit;
	} else {
	cppVar_1192 = visible_unit;
	}
	cppVar_1148 = cppVar_1192;
	}
	cppVar_1145 = cppVar_1148;
	}
	return cppVar_1145;
}
