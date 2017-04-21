#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_sumOfpow2(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1790;
	bool cppVar_1791;
	BIT_VEC cppVar_1793;
	bool cppVar_1794;
	BIT_VEC cppVar_1826;
	bool cppVar_1827;
	BIT_VEC cppVar_1810;
	BIT_VEC cppVar_1796;
	bool cppVar_1797;
	bool cppVar_1798;
	BIT_VEC cppVar_1800;
	bool cppVar_1801;
	bool cppVar_1802;
	BIT_VEC cppVar_1804;
	bool cppVar_1805;
	bool cppVar_1806;
	BIT_VEC cppVar_1818;
	bool cppVar_1819;
	bool cppVar_1820;
	BIT_VEC cppVar_1822;
	bool cppVar_1823;
	bool cppVar_1824;
	BIT_VEC cppVar_1811;
	BIT_VEC cppVar_1812;
	BIT_VEC cppVar_1813;
	BIT_VEC cppVar_1814;
	BIT_VEC cppVar_1815;
	BIT_VEC cppVar_1808;
	bool cppVar_1809;
	BIT_VEC cppVar_1807;
	BIT_VEC cppVar_1816;
	BIT_VEC cppVar_1821;
	BIT_VEC cppVar_1817;
	BIT_VEC cppVar_1803;
	BIT_VEC cppVar_1799;
	BIT_VEC cppVar_1795;
	BIT_VEC cppVar_1825;
	BIT_VEC cppVar_1792;
	BIT_VEC cppVar_1789;
	cppVar_1791 = (predict_upc == 0);
	if (cppVar_1791) {
	cppVar_1789 = sumOfpow2;
	} else {
	cppVar_1794 = (predict_upc == 1);
	if (cppVar_1794) {
	cppVar_1797 = (per_v_pc == 0);
	cppVar_1798 = cppVar_1794 && cppVar_1797;
	if (cppVar_1798) {
	cppVar_1795 = sumOfpow2;
	} else {
	cppVar_1801 = (per_v_pc == 1);
	cppVar_1802 = cppVar_1794 && cppVar_1801;
	if (cppVar_1802) {
	cppVar_1799 = sumOfpow2;
	} else {
	cppVar_1805 = (per_v_pc == 2);
	cppVar_1806 = cppVar_1794 && cppVar_1805;
	if (cppVar_1806) {
	cppVar_1809 = (jstate == 0);
	if (cppVar_1809) {
	cppVar_1807 = 0;
	} else {
	cppVar_1807 = sumOfpow2;
	}
	cppVar_1811 = (jstate >> 0) & cppMask_un_3_;
	cppVar_1812 = visibleEnergies.rd(cppVar_1811);
	cppVar_1813 = to_int_exp(cppVar_1812);
	cppVar_1814 = (cppVar_1813 >> 0) & cppMask_un_32_;
	cppVar_1815 = (cppVar_1814 & cppMask_un_32_);
	cppVar_1816 = cppVar_1807 + cppVar_1815;
	cppVar_1816 = (cppVar_1816 & cppMask_un_64_);
	cppVar_1803 = cppVar_1816;
	} else {
	cppVar_1819 = (per_v_pc == 3);
	cppVar_1820 = cppVar_1794 && cppVar_1819;
	if (cppVar_1820) {
	cppVar_1817 = sumOfpow2;
	} else {
	cppVar_1823 = (per_v_pc == 4);
	cppVar_1824 = cppVar_1794 && cppVar_1823;
	if (cppVar_1824) {
	cppVar_1821 = sumOfpow2;
	} else {
	cppVar_1821 = sumOfpow2;
	}
	cppVar_1817 = cppVar_1821;
	}
	cppVar_1803 = cppVar_1817;
	}
	cppVar_1799 = cppVar_1803;
	}
	cppVar_1795 = cppVar_1799;
	}
	cppVar_1792 = cppVar_1795;
	} else {
	cppVar_1827 = (predict_upc == 2);
	if (cppVar_1827) {
	cppVar_1825 = sumOfpow2;
	} else {
	cppVar_1825 = sumOfpow2;
	}
	cppVar_1792 = cppVar_1825;
	}
	cppVar_1789 = cppVar_1792;
	}
	return cppVar_1789;
}
