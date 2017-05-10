#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_predict_sum(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1634;
	BIT_VEC cppVar_1603;
	bool cppVar_1604;
	BIT_VEC cppVar_1625;
	bool cppVar_1626;
	BIT_VEC cppVar_1663;
	bool cppVar_1664;
	BIT_VEC cppVar_1614;
	BIT_VEC cppVar_1615;
	BIT_VEC cppVar_1616;
	BIT_VEC cppVar_1606;
	bool cppVar_1607;
	BIT_VEC cppVar_1608;
	BIT_VEC cppVar_1605;
	BIT_VEC cppVar_1610;
	BIT_VEC cppVar_1611;
	BIT_VEC cppVar_1612;
	bool cppVar_1613;
	BIT_VEC cppVar_1617;
	BIT_VEC cppVar_1618;
	BIT_VEC cppVar_1619;
	BIT_VEC cppVar_1620;
	BIT_VEC cppVar_1621;
	BIT_VEC cppVar_1622;
	BIT_VEC cppVar_1609;
	BIT_VEC cppVar_1623;
	BIT_VEC cppVar_1628;
	bool cppVar_1629;
	bool cppVar_1630;
	BIT_VEC cppVar_1647;
	bool cppVar_1648;
	bool cppVar_1649;
	BIT_VEC cppVar_1651;
	bool cppVar_1652;
	bool cppVar_1653;
	BIT_VEC cppVar_1655;
	bool cppVar_1656;
	bool cppVar_1657;
	BIT_VEC cppVar_1659;
	bool cppVar_1660;
	bool cppVar_1661;
	BIT_VEC cppVar_1632;
	bool cppVar_1633;
	BIT_VEC cppVar_1631;
	BIT_VEC cppVar_1636;
	BIT_VEC cppVar_1637;
	BIT_VEC cppVar_1638;
	bool cppVar_1639;
	BIT_VEC cppVar_1640;
	BIT_VEC cppVar_1641;
	BIT_VEC cppVar_1642;
	BIT_VEC cppVar_1643;
	BIT_VEC cppVar_1644;
	BIT_VEC cppVar_1635;
	BIT_VEC cppVar_1645;
	BIT_VEC cppVar_1658;
	BIT_VEC cppVar_1654;
	BIT_VEC cppVar_1650;
	BIT_VEC cppVar_1646;
	BIT_VEC cppVar_1627;
	BIT_VEC cppVar_1662;
	BIT_VEC cppVar_1624;
	BIT_VEC cppVar_1602;
	cppVar_1604 = (predict_upc == 0);
	if (cppVar_1604) {
	cppVar_1607 = (predict_v_cnt == 0);
	if (cppVar_1607) {
	cppVar_1605 = 0;
	} else {
	cppVar_1605 = predict_sum;
	}
	cppVar_1610 = (predict_v_cnt >> 0) & cppMask_un_9_;
	cppVar_1611 = data.rd(cppVar_1610);
	cppVar_1613 = (cppVar_1611 == 1);
	if (cppVar_1613) {
	cppVar_1615 = 101 * predict_v_cnt;
	cppVar_1615 = (cppVar_1615 & cppMask_un_16_);
	cppVar_1616 = cppVar_1615 + predict_h_cnt;
	cppVar_1616 = (cppVar_1616 & cppMask_un_16_);
	cppVar_1617 = edges.rd(cppVar_1616);
	cppVar_1618 = (cppVar_1617 >> 1) & cppMask_un_7_;
	cppVar_1619 = ((cppVar_1618 & cppMask_bit_7_) ? (cppVar_1618 | cppMask_sign_7_) : cppVar_1618);
	cppVar_1620 = (cppVar_1617 >> 0) & cppMask_un_1_;
	cppVar_1621 = (cppVar_1619 << 1) | cppVar_1620;
	cppVar_1621 = (cppVar_1621 & cppMask_un_16_);
	cppVar_1609 = cppVar_1621;
	} else {
	cppVar_1609 = 0;
	}
	cppVar_1623 = cppVar_1605 + cppVar_1609;
	cppVar_1623 = (cppVar_1623 & cppMask_un_16_);
	cppVar_1602 = cppVar_1623;
	} else {
	cppVar_1626 = (predict_upc == 1);
	if (cppVar_1626) {
	cppVar_1629 = (per_v_pc == 0);
	cppVar_1630 = cppVar_1626 && cppVar_1629;
	if (cppVar_1630) {
	cppVar_1633 = (predict_h_cnt == 0);
	if (cppVar_1633) {
	cppVar_1631 = 0;
	} else {
	cppVar_1631 = predict_sum;
	}
	cppVar_1636 = (predict_h_cnt >> 0) & cppMask_un_7_;
	cppVar_1637 = hidden_unit.rd(cppVar_1636);
	cppVar_1639 = (cppVar_1637 == 1);
	if (cppVar_1639) {
	cppVar_1640 = edges.rd(cppVar_1616);
	cppVar_1641 = (cppVar_1640 >> 1) & cppMask_un_7_;
	cppVar_1642 = ((cppVar_1641 & cppMask_bit_7_) ? (cppVar_1641 | cppMask_sign_7_) : cppVar_1641);
	cppVar_1643 = (cppVar_1640 >> 0) & cppMask_un_1_;
	cppVar_1644 = (cppVar_1642 << 1) | cppVar_1643;
	cppVar_1644 = (cppVar_1644 & cppMask_un_16_);
	cppVar_1635 = cppVar_1644;
	} else {
	cppVar_1635 = 0;
	}
	cppVar_1645 = cppVar_1631 + cppVar_1635;
	cppVar_1645 = (cppVar_1645 & cppMask_un_16_);
	cppVar_1627 = cppVar_1645;
	} else {
	cppVar_1648 = (per_v_pc == 1);
	cppVar_1649 = cppVar_1626 && cppVar_1648;
	if (cppVar_1649) {
	cppVar_1646 = predict_sum;
	} else {
	cppVar_1652 = (per_v_pc == 2);
	cppVar_1653 = cppVar_1626 && cppVar_1652;
	if (cppVar_1653) {
	cppVar_1650 = predict_sum;
	} else {
	cppVar_1656 = (per_v_pc == 3);
	cppVar_1657 = cppVar_1626 && cppVar_1656;
	if (cppVar_1657) {
	cppVar_1654 = predict_sum;
	} else {
	cppVar_1660 = (per_v_pc == 4);
	cppVar_1661 = cppVar_1626 && cppVar_1660;
	if (cppVar_1661) {
	cppVar_1658 = predict_sum;
	} else {
	cppVar_1658 = predict_sum;
	}
	cppVar_1654 = cppVar_1658;
	}
	cppVar_1650 = cppVar_1654;
	}
	cppVar_1646 = cppVar_1650;
	}
	cppVar_1627 = cppVar_1646;
	}
	cppVar_1624 = cppVar_1627;
	} else {
	cppVar_1664 = (predict_upc == 2);
	if (cppVar_1664) {
	cppVar_1662 = predict_sum;
	} else {
	cppVar_1662 = predict_sum;
	}
	cppVar_1624 = cppVar_1662;
	}
	cppVar_1602 = cppVar_1624;
	}
	return cppVar_1602;
}
