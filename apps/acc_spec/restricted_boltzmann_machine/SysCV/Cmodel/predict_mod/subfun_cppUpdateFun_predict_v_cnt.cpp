#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_predict_v_cnt(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1728;
	BIT_VEC cppVar_1724;
	bool cppVar_1725;
	BIT_VEC cppVar_1732;
	bool cppVar_1733;
	BIT_VEC cppVar_1753;
	bool cppVar_1754;
	BIT_VEC cppVar_1769;
	bool cppVar_1770;
	bool cppVar_1727;
	BIT_VEC cppVar_1729;
	BIT_VEC cppVar_1730;
	BIT_VEC cppVar_1726;
	BIT_VEC cppVar_1738;
	bool cppVar_1739;
	BIT_VEC cppVar_1742;
	BIT_VEC cppVar_1743;
	bool cppVar_1744;
	BIT_VEC cppVar_1745;
	BIT_VEC cppVar_1746;
	BIT_VEC cppVar_1747;
	bool cppVar_1748;
	bool cppVar_1749;
	BIT_VEC cppVar_1735;
	bool cppVar_1736;
	bool cppVar_1737;
	bool cppVar_1740;
	BIT_VEC cppVar_1750;
	BIT_VEC cppVar_1751;
	BIT_VEC cppVar_1741;
	BIT_VEC cppVar_1734;
	BIT_VEC cppVar_1756;
	BIT_VEC cppVar_1757;
	bool cppVar_1758;
	BIT_VEC cppVar_1759;
	BIT_VEC cppVar_1760;
	BIT_VEC cppVar_1761;
	bool cppVar_1762;
	bool cppVar_1763;
	BIT_VEC cppVar_1764;
	BIT_VEC cppVar_1765;
	BIT_VEC cppVar_1766;
	BIT_VEC cppVar_1767;
	BIT_VEC cppVar_1755;
	BIT_VEC cppVar_1768;
	BIT_VEC cppVar_1752;
	BIT_VEC cppVar_1731;
	BIT_VEC cppVar_1723;
	cppVar_1725 = (predict_upc == 0);
	if (cppVar_1725) {
	cppVar_1727 = (predict_v_cnt == num_visible);
	if (cppVar_1727) {
	cppVar_1726 = 0;
	} else {
	cppVar_1730 = predict_v_cnt + 1;
	cppVar_1730 = (cppVar_1730 & cppMask_un_16_);
	cppVar_1726 = cppVar_1730;
	}
	cppVar_1723 = cppVar_1726;
	} else {
	cppVar_1733 = (predict_upc == 1);
	if (cppVar_1733) {
	cppVar_1736 = (per_v_pc == 4);
	cppVar_1737 = cppVar_1733 && cppVar_1736;
	cppVar_1739 = (jstate == 4);
	cppVar_1740 = cppVar_1737 && cppVar_1739;
	if (cppVar_1740) {
	cppVar_1743 = predict_v_cnt + 5;
	cppVar_1743 = (cppVar_1743 & cppMask_un_16_);
	cppVar_1744 = (cppVar_1743 == num_visible);
	cppVar_1746 = predict_v_cnt + 5;
	cppVar_1746 = (cppVar_1746 & cppMask_un_16_);
	cppVar_1748 = cppVar_1746 >= 500;
	cppVar_1749 = cppVar_1744 || cppVar_1748;
	if (cppVar_1749) {
	cppVar_1741 = 0;
	} else {
	cppVar_1751 = predict_v_cnt + 5;
	cppVar_1751 = (cppVar_1751 & cppMask_un_16_);
	cppVar_1741 = cppVar_1751;
	}
	cppVar_1734 = cppVar_1741;
	} else {
	cppVar_1734 = predict_v_cnt;
	}
	cppVar_1731 = cppVar_1734;
	} else {
	cppVar_1754 = (predict_upc == 3);
	if (cppVar_1754) {
	cppVar_1757 = predict_v_cnt + 5;
	cppVar_1757 = (cppVar_1757 & cppMask_un_16_);
	cppVar_1758 = (cppVar_1757 == num_visible);
	cppVar_1760 = predict_v_cnt + 5;
	cppVar_1760 = (cppVar_1760 & cppMask_un_16_);
	cppVar_1762 = cppVar_1760 >= 500;
	cppVar_1763 = cppVar_1758 || cppVar_1762;
	if (cppVar_1763) {
	cppVar_1765 = predict_v_cnt + 5;
	cppVar_1765 = (cppVar_1765 & cppMask_un_16_);
	cppVar_1755 = cppVar_1765;
	} else {
	cppVar_1767 = predict_v_cnt + 5;
	cppVar_1767 = (cppVar_1767 & cppMask_un_16_);
	cppVar_1755 = cppVar_1767;
	}
	cppVar_1752 = cppVar_1755;
	} else {
	cppVar_1770 = (predict_upc == 2);
	if (cppVar_1770) {
	cppVar_1768 = predict_v_cnt;
	} else {
	cppVar_1768 = predict_v_cnt;
	}
	cppVar_1752 = cppVar_1768;
	}
	cppVar_1731 = cppVar_1752;
	}
	cppVar_1723 = cppVar_1731;
	}
	return cppVar_1723;
}
