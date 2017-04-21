#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_prediction(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_1787;
	BIT_VEC cppVar_1773;
	bool cppVar_1774;
	BIT_VEC cppVar_1785;
	bool cppVar_1786;
	BIT_VEC cppVar_1784;
	BIT_VEC cppVar_1776;
	BIT_VEC cppVar_1777;
	BIT_VEC cppVar_1778;
	BIT_VEC cppVar_1779;
	bool cppVar_1780;
	BIT_VEC cppVar_1781;
	BIT_VEC cppVar_1782;
	BIT_VEC cppVar_1783;
	BIT_VEC cppVar_1775;
	BIT_VEC cppVar_1772;
	cppVar_1774 = (predict_upc == 3);
	if (cppVar_1774) {
	cppVar_1776 = predict_v_cnt + jstate;
	cppVar_1776 = (cppVar_1776 & cppMask_un_16_);
	cppVar_1777 = (cppVar_1776 >> 0) & cppMask_un_9_;
	cppVar_1778 = predict_vector.rd(cppVar_1777);
	cppVar_1780 = (cppVar_1778 == 1);
	if (cppVar_1780) {
	cppVar_1782 = jstate + 1;
	cppVar_1782 = (cppVar_1782 & cppMask_un_16_);
	cppVar_1783 = (cppVar_1782 >> 0) & cppMask_un_8_;
	cppVar_1775 = cppVar_1783;
	} else {
	cppVar_1786 = (jstate == 0);
	if (cppVar_1786) {
	cppVar_1784 = 0;
	} else {
	cppVar_1784 = prediction;
	}
	cppVar_1775 = cppVar_1784;
	}
	cppVar_1772 = cppVar_1775;
	} else {
	cppVar_1772 = prediction;
	}
	return cppVar_1772;
}
