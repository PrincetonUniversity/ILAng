#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_done(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1322;
	BIT_VEC cppVar_1321;
	BIT_VEC cppVar_1301;
	bool cppVar_1302;
	BIT_VEC cppVar_1304;
	bool cppVar_1305;
	BIT_VEC cppVar_1307;
	bool cppVar_1308;
	BIT_VEC cppVar_1310;
	bool cppVar_1311;
	BIT_VEC cppVar_1312;
	bool cppVar_1313;
	bool cppVar_1314;
	BIT_VEC cppVar_1315;
	BIT_VEC cppVar_1316;
	bool cppVar_1317;
	bool cppVar_1318;
	bool cppVar_1319;
	bool cppVar_1320;
	BIT_VEC cppVar_1309;
	BIT_VEC cppVar_1306;
	BIT_VEC cppVar_1303;
	BIT_VEC cppVar_1300;
	cppVar_1302 = (predict_upc == 0);
	if (cppVar_1302) {
	cppVar_1300 = done;
	} else {
	cppVar_1305 = (predict_upc == 1);
	if (cppVar_1305) {
	cppVar_1303 = done;
	} else {
	cppVar_1308 = (predict_upc == 2);
	if (cppVar_1308) {
	cppVar_1311 = (wr_request == 0);
	cppVar_1313 = (wr_complete == 1);
	cppVar_1314 = cppVar_1311 && cppVar_1313;
	cppVar_1316 = num_testusers - 1;
	cppVar_1316 = (cppVar_1316 & cppMask_un_16_);
	cppVar_1317 = (index == cppVar_1316);
	cppVar_1318 = cppVar_1314 && cppVar_1317;
	cppVar_1319 = (loop_count == num_loops);
	cppVar_1320 = cppVar_1318 && cppVar_1319;
	if (cppVar_1320) {
	cppVar_1309 = 1;
	} else {
	cppVar_1309 = 0;
	}
	cppVar_1306 = cppVar_1309;
	} else {
	cppVar_1306 = done;
	}
	cppVar_1303 = cppVar_1306;
	}
	cppVar_1300 = cppVar_1303;
	}
	return cppVar_1300;
}
