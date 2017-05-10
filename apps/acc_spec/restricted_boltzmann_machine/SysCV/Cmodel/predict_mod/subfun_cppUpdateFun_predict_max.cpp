#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_predict_max(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1556;
	BIT_VEC cppVar_1541;
	bool cppVar_1542;
	BIT_VEC cppVar_1544;
	bool cppVar_1545;
	BIT_VEC cppVar_1599;
	bool cppVar_1600;
	BIT_VEC cppVar_1562;
	BIT_VEC cppVar_1563;
	BIT_VEC cppVar_1564;
	bool cppVar_1551;
	BIT_VEC cppVar_1547;
	bool cppVar_1548;
	bool cppVar_1549;
	BIT_VEC cppVar_1578;
	bool cppVar_1579;
	bool cppVar_1580;
	BIT_VEC cppVar_1587;
	bool cppVar_1588;
	bool cppVar_1589;
	BIT_VEC cppVar_1591;
	bool cppVar_1592;
	bool cppVar_1593;
	BIT_VEC cppVar_1595;
	bool cppVar_1596;
	bool cppVar_1597;
	BIT_VEC cppVar_1554;
	bool cppVar_1555;
	BIT_VEC cppVar_1553;
	BIT_VEC cppVar_1558;
	BIT_VEC cppVar_1559;
	BIT_VEC cppVar_1560;
	bool cppVar_1561;
	BIT_VEC cppVar_1565;
	BIT_VEC cppVar_1566;
	BIT_VEC cppVar_1567;
	BIT_VEC cppVar_1568;
	BIT_VEC cppVar_1569;
	BIT_VEC cppVar_1557;
	BIT_VEC cppVar_1570;
	BIT_VEC cppVar_1572;
	bool cppVar_1573;
	BIT_VEC cppVar_1574;
	BIT_VEC cppVar_1575;
	BIT_VEC cppVar_1571;
	bool cppVar_1576;
	BIT_VEC cppVar_1552;
	BIT_VEC cppVar_1550;
	BIT_VEC cppVar_1584;
	BIT_VEC cppVar_1582;
	bool cppVar_1583;
	BIT_VEC cppVar_1585;
	BIT_VEC cppVar_1581;
	BIT_VEC cppVar_1594;
	BIT_VEC cppVar_1590;
	BIT_VEC cppVar_1586;
	BIT_VEC cppVar_1577;
	BIT_VEC cppVar_1546;
	BIT_VEC cppVar_1598;
	BIT_VEC cppVar_1543;
	BIT_VEC cppVar_1540;
	cppVar_1542 = (predict_upc == 0);
	if (cppVar_1542) {
	cppVar_1540 = predict_max;
	} else {
	cppVar_1545 = (predict_upc == 1);
	if (cppVar_1545) {
	cppVar_1548 = (per_v_pc == 0);
	cppVar_1549 = cppVar_1545 && cppVar_1548;
	if (cppVar_1549) {
	cppVar_1551 = (predict_h_cnt == num_hidden);
	if (cppVar_1551) {
	cppVar_1555 = (predict_h_cnt == 0);
	if (cppVar_1555) {
	cppVar_1553 = 0;
	} else {
	cppVar_1553 = predict_sum;
	}
	cppVar_1558 = (predict_h_cnt >> 0) & cppMask_un_7_;
	cppVar_1559 = hidden_unit.rd(cppVar_1558);
	cppVar_1561 = (cppVar_1559 == 1);
	if (cppVar_1561) {
	cppVar_1563 = 101 * predict_v_cnt;
	cppVar_1563 = (cppVar_1563 & cppMask_un_16_);
	cppVar_1564 = cppVar_1563 + predict_h_cnt;
	cppVar_1564 = (cppVar_1564 & cppMask_un_16_);
	cppVar_1565 = edges.rd(cppVar_1564);
	cppVar_1566 = (cppVar_1565 >> 1) & cppMask_un_7_;
	cppVar_1567 = ((cppVar_1566 & cppMask_bit_7_) ? (cppVar_1566 | cppMask_sign_7_) : cppVar_1566);
	cppVar_1568 = (cppVar_1565 >> 0) & cppMask_un_1_;
	cppVar_1569 = (cppVar_1567 << 1) | cppVar_1568;
	cppVar_1569 = (cppVar_1569 & cppMask_un_16_);
	cppVar_1557 = cppVar_1569;
	} else {
	cppVar_1557 = 0;
	}
	cppVar_1570 = cppVar_1553 + cppVar_1557;
	cppVar_1570 = (cppVar_1570 & cppMask_un_16_);
	cppVar_1573 = (jstate == 0);
	if (cppVar_1573) {
	cppVar_1575 = -1000;
	cppVar_1571 = cppVar_1575;
	} else {
	cppVar_1571 = predict_max;
	}
	cppVar_1576 = ((cppVar_1570 & cppMask_bit_16_) ? (cppVar_1570 | cppMask_sign_16_) : cppVar_1570) > ((cppVar_1571 & cppMask_bit_16_) ? (cppVar_1571 | cppMask_sign_16_) : cppVar_1571);
	if (cppVar_1576) {
	cppVar_1552 = cppVar_1570;
	} else {
	cppVar_1552 = cppVar_1571;
	}
	cppVar_1550 = cppVar_1552;
	} else {
	cppVar_1550 = predict_max;
	}
	cppVar_1546 = cppVar_1550;
	} else {
	cppVar_1579 = (per_v_pc == 1);
	cppVar_1580 = cppVar_1545 && cppVar_1579;
	if (cppVar_1580) {
	cppVar_1583 = (jstate == 0);
	if (cppVar_1583) {
	cppVar_1585 = predict_max - 62;
	cppVar_1585 = (cppVar_1585 & cppMask_un_16_);
	cppVar_1581 = cppVar_1585;
	} else {
	cppVar_1581 = predict_max;
	}
	cppVar_1577 = cppVar_1581;
	} else {
	cppVar_1588 = (per_v_pc == 2);
	cppVar_1589 = cppVar_1545 && cppVar_1588;
	if (cppVar_1589) {
	cppVar_1586 = predict_max;
	} else {
	cppVar_1592 = (per_v_pc == 3);
	cppVar_1593 = cppVar_1545 && cppVar_1592;
	if (cppVar_1593) {
	cppVar_1590 = predict_max;
	} else {
	cppVar_1596 = (per_v_pc == 4);
	cppVar_1597 = cppVar_1545 && cppVar_1596;
	if (cppVar_1597) {
	cppVar_1594 = predict_max;
	} else {
	cppVar_1594 = predict_max;
	}
	cppVar_1590 = cppVar_1594;
	}
	cppVar_1586 = cppVar_1590;
	}
	cppVar_1577 = cppVar_1586;
	}
	cppVar_1546 = cppVar_1577;
	}
	cppVar_1543 = cppVar_1546;
	} else {
	cppVar_1600 = (predict_upc == 2);
	if (cppVar_1600) {
	cppVar_1598 = predict_max;
	} else {
	cppVar_1598 = predict_max;
	}
	cppVar_1543 = cppVar_1598;
	}
	cppVar_1540 = cppVar_1543;
	}
	return cppVar_1540;
}
