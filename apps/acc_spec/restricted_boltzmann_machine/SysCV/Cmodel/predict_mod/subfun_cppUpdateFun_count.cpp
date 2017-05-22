#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_count(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1287;
	BIT_VEC cppVar_1265;
	bool cppVar_1266;
	BIT_VEC cppVar_1269;
	bool cppVar_1270;
	BIT_VEC cppVar_1289;
	bool cppVar_1290;
	BIT_VEC cppVar_1297;
	bool cppVar_1298;
	BIT_VEC cppVar_1267;
	BIT_VEC cppVar_1284;
	bool cppVar_1285;
	BIT_VEC cppVar_1275;
	BIT_VEC cppVar_1276;
	bool cppVar_1277;
	BIT_VEC cppVar_1278;
	BIT_VEC cppVar_1279;
	BIT_VEC cppVar_1280;
	bool cppVar_1281;
	bool cppVar_1282;
	BIT_VEC cppVar_1272;
	bool cppVar_1273;
	bool cppVar_1274;
	bool cppVar_1283;
	bool cppVar_1286;
	BIT_VEC cppVar_1271;
	BIT_VEC cppVar_1292;
	bool cppVar_1293;
	BIT_VEC cppVar_1294;
	BIT_VEC cppVar_1295;
	BIT_VEC cppVar_1291;
	BIT_VEC cppVar_1296;
	BIT_VEC cppVar_1288;
	BIT_VEC cppVar_1268;
	BIT_VEC cppVar_1264;
	cppVar_1266 = (predict_upc == 0);
	if (cppVar_1266) {
	cppVar_1264 = 0;
	} else {
	cppVar_1270 = (predict_upc == 1);
	if (cppVar_1270) {
	cppVar_1273 = (per_v_pc == 4);
	cppVar_1274 = cppVar_1270 && cppVar_1273;
	cppVar_1276 = predict_v_cnt + 5;
	cppVar_1276 = (cppVar_1276 & cppMask_un_16_);
	cppVar_1277 = (cppVar_1276 == num_visible);
	cppVar_1279 = predict_v_cnt + 5;
	cppVar_1279 = (cppVar_1279 & cppMask_un_16_);
	cppVar_1281 = cppVar_1279 >= 500;
	cppVar_1282 = cppVar_1277 || cppVar_1281;
	cppVar_1283 = cppVar_1274 && cppVar_1282;
	cppVar_1285 = (jstate == 4);
	cppVar_1286 = cppVar_1283 && cppVar_1285;
	if (cppVar_1286) {
	cppVar_1271 = 0;
	} else {
	cppVar_1271 = count;
	}
	cppVar_1268 = cppVar_1271;
	} else {
	cppVar_1290 = (predict_upc == 3);
	if (cppVar_1290) {
	cppVar_1293 = (jstate == 4);
	if (cppVar_1293) {
	cppVar_1295 = count + 1;
	cppVar_1295 = (cppVar_1295 & cppMask_un_8_);
	cppVar_1291 = cppVar_1295;
	} else {
	cppVar_1291 = count;
	}
	cppVar_1288 = cppVar_1291;
	} else {
	cppVar_1298 = (predict_upc == 2);
	if (cppVar_1298) {
	cppVar_1296 = count;
	} else {
	cppVar_1296 = count;
	}
	cppVar_1288 = cppVar_1296;
	}
	cppVar_1268 = cppVar_1288;
	}
	cppVar_1264 = cppVar_1268;
	}
	return cppVar_1264;
}
