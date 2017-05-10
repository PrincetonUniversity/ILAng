#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_predict_h_cnt(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1489;
	BIT_VEC cppVar_1481;
	bool cppVar_1482;
	BIT_VEC cppVar_1493;
	bool cppVar_1494;
	BIT_VEC cppVar_1520;
	bool cppVar_1521;
	bool cppVar_1484;
	BIT_VEC cppVar_1486;
	BIT_VEC cppVar_1487;
	bool cppVar_1488;
	BIT_VEC cppVar_1490;
	BIT_VEC cppVar_1491;
	BIT_VEC cppVar_1485;
	BIT_VEC cppVar_1483;
	bool cppVar_1500;
	BIT_VEC cppVar_1496;
	bool cppVar_1497;
	bool cppVar_1498;
	BIT_VEC cppVar_1504;
	bool cppVar_1505;
	bool cppVar_1506;
	BIT_VEC cppVar_1508;
	bool cppVar_1509;
	bool cppVar_1510;
	BIT_VEC cppVar_1512;
	bool cppVar_1513;
	bool cppVar_1514;
	BIT_VEC cppVar_1516;
	bool cppVar_1517;
	bool cppVar_1518;
	BIT_VEC cppVar_1501;
	BIT_VEC cppVar_1502;
	BIT_VEC cppVar_1499;
	BIT_VEC cppVar_1515;
	BIT_VEC cppVar_1511;
	BIT_VEC cppVar_1507;
	BIT_VEC cppVar_1503;
	BIT_VEC cppVar_1495;
	BIT_VEC cppVar_1519;
	BIT_VEC cppVar_1492;
	BIT_VEC cppVar_1480;
	cppVar_1482 = (predict_upc == 0);
	if (cppVar_1482) {
	cppVar_1484 = (predict_v_cnt == num_visible);
	if (cppVar_1484) {
	cppVar_1487 = num_hidden - 1;
	cppVar_1487 = (cppVar_1487 & cppMask_un_16_);
	cppVar_1488 = (predict_h_cnt == cppVar_1487);
	if (cppVar_1488) {
	cppVar_1485 = 0;
	} else {
	cppVar_1491 = predict_h_cnt + 1;
	cppVar_1491 = (cppVar_1491 & cppMask_un_16_);
	cppVar_1485 = cppVar_1491;
	}
	cppVar_1483 = cppVar_1485;
	} else {
	cppVar_1483 = predict_h_cnt;
	}
	cppVar_1480 = cppVar_1483;
	} else {
	cppVar_1494 = (predict_upc == 1);
	if (cppVar_1494) {
	cppVar_1497 = (per_v_pc == 0);
	cppVar_1498 = cppVar_1494 && cppVar_1497;
	if (cppVar_1498) {
	cppVar_1500 = (predict_h_cnt == num_hidden);
	if (cppVar_1500) {
	cppVar_1499 = 0;
	} else {
	cppVar_1502 = predict_h_cnt + 1;
	cppVar_1502 = (cppVar_1502 & cppMask_un_16_);
	cppVar_1499 = cppVar_1502;
	}
	cppVar_1495 = cppVar_1499;
	} else {
	cppVar_1505 = (per_v_pc == 1);
	cppVar_1506 = cppVar_1494 && cppVar_1505;
	if (cppVar_1506) {
	cppVar_1503 = predict_h_cnt;
	} else {
	cppVar_1509 = (per_v_pc == 2);
	cppVar_1510 = cppVar_1494 && cppVar_1509;
	if (cppVar_1510) {
	cppVar_1507 = predict_h_cnt;
	} else {
	cppVar_1513 = (per_v_pc == 3);
	cppVar_1514 = cppVar_1494 && cppVar_1513;
	if (cppVar_1514) {
	cppVar_1511 = predict_h_cnt;
	} else {
	cppVar_1517 = (per_v_pc == 4);
	cppVar_1518 = cppVar_1494 && cppVar_1517;
	if (cppVar_1518) {
	cppVar_1515 = predict_h_cnt;
	} else {
	cppVar_1515 = predict_h_cnt;
	}
	cppVar_1511 = cppVar_1515;
	}
	cppVar_1507 = cppVar_1511;
	}
	cppVar_1503 = cppVar_1507;
	}
	cppVar_1495 = cppVar_1503;
	}
	cppVar_1492 = cppVar_1495;
	} else {
	cppVar_1521 = (predict_upc == 2);
	if (cppVar_1521) {
	cppVar_1519 = predict_h_cnt;
	} else {
	cppVar_1519 = predict_h_cnt;
	}
	cppVar_1492 = cppVar_1519;
	}
	cppVar_1480 = cppVar_1492;
	}
	return cppVar_1480;
}
