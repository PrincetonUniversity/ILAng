#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_predict_upc(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1667;
	bool cppVar_1668;
	BIT_VEC cppVar_1676;
	BIT_VEC cppVar_1678;
	bool cppVar_1679;
	BIT_VEC cppVar_1675;
	BIT_VEC cppVar_1698;
	bool cppVar_1699;
	BIT_VEC cppVar_1696;
	BIT_VEC cppVar_1714;
	bool cppVar_1715;
	BIT_VEC cppVar_1712;
	bool cppVar_1670;
	BIT_VEC cppVar_1671;
	BIT_VEC cppVar_1672;
	bool cppVar_1673;
	bool cppVar_1674;
	BIT_VEC cppVar_1669;
	BIT_VEC cppVar_1684;
	bool cppVar_1685;
	BIT_VEC cppVar_1687;
	BIT_VEC cppVar_1688;
	bool cppVar_1689;
	BIT_VEC cppVar_1690;
	BIT_VEC cppVar_1691;
	BIT_VEC cppVar_1692;
	bool cppVar_1693;
	bool cppVar_1694;
	BIT_VEC cppVar_1681;
	bool cppVar_1682;
	bool cppVar_1683;
	bool cppVar_1686;
	bool cppVar_1695;
	BIT_VEC cppVar_1680;
	BIT_VEC cppVar_1701;
	BIT_VEC cppVar_1702;
	bool cppVar_1703;
	BIT_VEC cppVar_1704;
	BIT_VEC cppVar_1705;
	BIT_VEC cppVar_1706;
	bool cppVar_1707;
	bool cppVar_1708;
	BIT_VEC cppVar_1709;
	bool cppVar_1710;
	bool cppVar_1711;
	BIT_VEC cppVar_1700;
	BIT_VEC cppVar_1717;
	bool cppVar_1718;
	BIT_VEC cppVar_1719;
	bool cppVar_1720;
	bool cppVar_1721;
	BIT_VEC cppVar_1716;
	BIT_VEC cppVar_1713;
	BIT_VEC cppVar_1697;
	BIT_VEC cppVar_1677;
	BIT_VEC cppVar_1666;
	cppVar_1668 = (predict_upc == 0);
	if (cppVar_1668) {
	cppVar_1670 = (predict_v_cnt == num_visible);
	cppVar_1672 = num_hidden - 1;
	cppVar_1672 = (cppVar_1672 & cppMask_un_16_);
	cppVar_1673 = (predict_h_cnt == cppVar_1672);
	cppVar_1674 = cppVar_1670 && cppVar_1673;
	if (cppVar_1674) {
	cppVar_1669 = 1;
	} else {
	cppVar_1669 = 0;
	}
	cppVar_1666 = cppVar_1669;
	} else {
	cppVar_1679 = (predict_upc == 1);
	if (cppVar_1679) {
	cppVar_1682 = (per_v_pc == 4);
	cppVar_1683 = cppVar_1679 && cppVar_1682;
	cppVar_1685 = (jstate == 4);
	cppVar_1686 = cppVar_1683 && cppVar_1685;
	cppVar_1688 = predict_v_cnt + 5;
	cppVar_1688 = (cppVar_1688 & cppMask_un_16_);
	cppVar_1689 = (cppVar_1688 == num_visible);
	cppVar_1691 = predict_v_cnt + 5;
	cppVar_1691 = (cppVar_1691 & cppMask_un_16_);
	cppVar_1693 = cppVar_1691 >= 500;
	cppVar_1694 = cppVar_1689 || cppVar_1693;
	cppVar_1695 = cppVar_1686 && cppVar_1694;
	if (cppVar_1695) {
	cppVar_1680 = 3;
	} else {
	cppVar_1680 = 1;
	}
	cppVar_1677 = cppVar_1680;
	} else {
	cppVar_1699 = (predict_upc == 3);
	if (cppVar_1699) {
	cppVar_1702 = predict_v_cnt + 5;
	cppVar_1702 = (cppVar_1702 & cppMask_un_16_);
	cppVar_1703 = (cppVar_1702 == num_visible);
	cppVar_1705 = predict_v_cnt + 5;
	cppVar_1705 = (cppVar_1705 & cppMask_un_16_);
	cppVar_1707 = cppVar_1705 >= 500;
	cppVar_1708 = cppVar_1703 || cppVar_1707;
	cppVar_1710 = (jstate == 4);
	cppVar_1711 = cppVar_1708 && cppVar_1710;
	if (cppVar_1711) {
	cppVar_1700 = 2;
	} else {
	cppVar_1700 = 3;
	}
	cppVar_1697 = cppVar_1700;
	} else {
	cppVar_1715 = (predict_upc == 2);
	if (cppVar_1715) {
	cppVar_1718 = (wr_request == 0);
	cppVar_1720 = (wr_complete == 1);
	cppVar_1721 = cppVar_1718 && cppVar_1720;
	if (cppVar_1721) {
	cppVar_1716 = 2;
	} else {
	cppVar_1716 = 2;
	}
	cppVar_1713 = cppVar_1716;
	} else {
	cppVar_1713 = predict_upc;
	}
	cppVar_1697 = cppVar_1713;
	}
	cppVar_1677 = cppVar_1697;
	}
	cppVar_1666 = cppVar_1677;
	}
	return cppVar_1666;
}
