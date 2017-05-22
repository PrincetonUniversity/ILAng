#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_index(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1355;
	bool cppVar_1356;
	BIT_VEC cppVar_1358;
	bool cppVar_1359;
	BIT_VEC cppVar_1361;
	bool cppVar_1362;
	BIT_VEC cppVar_1364;
	bool cppVar_1365;
	BIT_VEC cppVar_1366;
	bool cppVar_1367;
	bool cppVar_1368;
	BIT_VEC cppVar_1370;
	BIT_VEC cppVar_1371;
	bool cppVar_1372;
	bool cppVar_1373;
	bool cppVar_1374;
	BIT_VEC cppVar_1375;
	BIT_VEC cppVar_1376;
	BIT_VEC cppVar_1369;
	BIT_VEC cppVar_1363;
	BIT_VEC cppVar_1360;
	BIT_VEC cppVar_1357;
	BIT_VEC cppVar_1354;
	cppVar_1356 = (predict_upc == 0);
	if (cppVar_1356) {
	cppVar_1354 = index;
	} else {
	cppVar_1359 = (predict_upc == 1);
	if (cppVar_1359) {
	cppVar_1357 = index;
	} else {
	cppVar_1362 = (predict_upc == 2);
	if (cppVar_1362) {
	cppVar_1365 = (wr_request == 0);
	cppVar_1367 = (wr_complete == 1);
	cppVar_1368 = cppVar_1365 && cppVar_1367;
	if (cppVar_1368) {
	cppVar_1371 = num_testusers - 1;
	cppVar_1371 = (cppVar_1371 & cppMask_un_16_);
	cppVar_1372 = (index == cppVar_1371);
	cppVar_1373 = (loop_count == num_loops);
	cppVar_1374 = cppVar_1372 && cppVar_1373;
	if (cppVar_1374) {
	cppVar_1369 = index;
	} else {
	cppVar_1376 = index + 1;
	cppVar_1376 = (cppVar_1376 & cppMask_un_16_);
	cppVar_1369 = cppVar_1376;
	}
	cppVar_1363 = cppVar_1369;
	} else {
	cppVar_1363 = index;
	}
	cppVar_1360 = cppVar_1363;
	} else {
	cppVar_1360 = index;
	}
	cppVar_1357 = cppVar_1360;
	}
	cppVar_1354 = cppVar_1357;
	}
	return cppVar_1354;
}
