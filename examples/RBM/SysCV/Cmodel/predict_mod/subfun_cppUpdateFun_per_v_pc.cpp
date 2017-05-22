#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_per_v_pc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1430;
	BIT_VEC cppVar_1443;
	BIT_VEC cppVar_1449;
	BIT_VEC cppVar_1455;
	BIT_VEC cppVar_1461;
	BIT_VEC cppVar_1428;
	bool cppVar_1429;
	BIT_VEC cppVar_1432;
	bool cppVar_1433;
	BIT_VEC cppVar_1477;
	bool cppVar_1478;
	bool cppVar_1441;
	BIT_VEC cppVar_1439;
	bool cppVar_1440;
	BIT_VEC cppVar_1468;
	BIT_VEC cppVar_1469;
	bool cppVar_1470;
	BIT_VEC cppVar_1471;
	BIT_VEC cppVar_1472;
	BIT_VEC cppVar_1473;
	bool cppVar_1474;
	bool cppVar_1475;
	BIT_VEC cppVar_1435;
	bool cppVar_1436;
	bool cppVar_1437;
	BIT_VEC cppVar_1445;
	bool cppVar_1446;
	bool cppVar_1447;
	BIT_VEC cppVar_1451;
	bool cppVar_1452;
	bool cppVar_1453;
	BIT_VEC cppVar_1457;
	bool cppVar_1458;
	bool cppVar_1459;
	BIT_VEC cppVar_1463;
	bool cppVar_1464;
	bool cppVar_1465;
	bool cppVar_1442;
	BIT_VEC cppVar_1438;
	BIT_VEC cppVar_1448;
	BIT_VEC cppVar_1454;
	BIT_VEC cppVar_1460;
	BIT_VEC cppVar_1467;
	BIT_VEC cppVar_1466;
	BIT_VEC cppVar_1462;
	BIT_VEC cppVar_1456;
	BIT_VEC cppVar_1450;
	BIT_VEC cppVar_1444;
	BIT_VEC cppVar_1434;
	BIT_VEC cppVar_1476;
	BIT_VEC cppVar_1431;
	BIT_VEC cppVar_1427;
	cppVar_1429 = (predict_upc == 0);
	if (cppVar_1429) {
	cppVar_1427 = 0;
	} else {
	cppVar_1433 = (predict_upc == 1);
	if (cppVar_1433) {
	cppVar_1436 = (per_v_pc == 0);
	cppVar_1437 = cppVar_1433 && cppVar_1436;
	if (cppVar_1437) {
	cppVar_1440 = (jstate == 4);
	cppVar_1441 = (predict_h_cnt == num_hidden);
	cppVar_1442 = cppVar_1440 && cppVar_1441;
	if (cppVar_1442) {
	cppVar_1438 = 1;
	} else {
	cppVar_1438 = per_v_pc;
	}
	cppVar_1434 = cppVar_1438;
	} else {
	cppVar_1446 = (per_v_pc == 1);
	cppVar_1447 = cppVar_1433 && cppVar_1446;
	if (cppVar_1447) {
	cppVar_1440 = (jstate == 4);
	if (cppVar_1440) {
	cppVar_1448 = 2;
	} else {
	cppVar_1448 = per_v_pc;
	}
	cppVar_1444 = cppVar_1448;
	} else {
	cppVar_1452 = (per_v_pc == 2);
	cppVar_1453 = cppVar_1433 && cppVar_1452;
	if (cppVar_1453) {
	cppVar_1440 = (jstate == 4);
	if (cppVar_1440) {
	cppVar_1454 = 3;
	} else {
	cppVar_1454 = per_v_pc;
	}
	cppVar_1450 = cppVar_1454;
	} else {
	cppVar_1458 = (per_v_pc == 3);
	cppVar_1459 = cppVar_1433 && cppVar_1458;
	if (cppVar_1459) {
	cppVar_1440 = (jstate == 4);
	if (cppVar_1440) {
	cppVar_1460 = 4;
	} else {
	cppVar_1460 = per_v_pc;
	}
	cppVar_1456 = cppVar_1460;
	} else {
	cppVar_1464 = (per_v_pc == 4);
	cppVar_1465 = cppVar_1433 && cppVar_1464;
	if (cppVar_1465) {
	cppVar_1440 = (jstate == 4);
	if (cppVar_1440) {
	cppVar_1469 = predict_v_cnt + 5;
	cppVar_1469 = (cppVar_1469 & cppMask_un_16_);
	cppVar_1470 = (cppVar_1469 == num_visible);
	cppVar_1472 = predict_v_cnt + 5;
	cppVar_1472 = (cppVar_1472 & cppMask_un_16_);
	cppVar_1474 = cppVar_1472 >= 500;
	cppVar_1475 = cppVar_1470 || cppVar_1474;
	if (cppVar_1475) {
	cppVar_1467 = 0;
	} else {
	cppVar_1467 = 0;
	}
	cppVar_1466 = cppVar_1467;
	} else {
	cppVar_1466 = per_v_pc;
	}
	cppVar_1462 = cppVar_1466;
	} else {
	cppVar_1462 = per_v_pc;
	}
	cppVar_1456 = cppVar_1462;
	}
	cppVar_1450 = cppVar_1456;
	}
	cppVar_1444 = cppVar_1450;
	}
	cppVar_1434 = cppVar_1444;
	}
	cppVar_1431 = cppVar_1434;
	} else {
	cppVar_1478 = (predict_upc == 2);
	if (cppVar_1478) {
	cppVar_1476 = per_v_pc;
	} else {
	cppVar_1476 = per_v_pc;
	}
	cppVar_1431 = cppVar_1476;
	}
	cppVar_1427 = cppVar_1431;
	}
	return cppVar_1427;
}
