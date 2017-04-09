#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_686;
	bool cppVar_688 = (aes_state == 0);
	bool cppVar_690 = (cmd == 2);
	bool cppVar_691 = cppVar_688 && cppVar_690;
	bool cppVar_693 = (cmdaddr == 65285);
	bool cppVar_694 = cppVar_691 && cppVar_693;
	if (cppVar_694) {
	BIT_VEC cppVar_695 = (aes_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_696 = (cmddata << 8) | cppVar_695;
	cppVar_696 = (cppVar_696 & cppMask_un_16_);
	cppVar_686 = cppVar_696;
	} else {
	BIT_VEC cppVar_697;
	bool cppVar_699 = (aes_state == 0);
	bool cppVar_701 = (cmd == 2);
	bool cppVar_702 = cppVar_699 && cppVar_701;
	bool cppVar_704 = (cmdaddr == 65284);
	bool cppVar_705 = cppVar_702 && cppVar_704;
	if (cppVar_705) {
	BIT_VEC cppVar_706 = (aes_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_707 = (cppVar_706 << 8) | cmddata;
	cppVar_707 = (cppVar_707 & cppMask_un_16_);
	cppVar_697 = cppVar_707;
	} else {
	cppVar_697 = aes_len;
	}
	cppVar_686 = cppVar_697;
	}
	return cppVar_686;
}
