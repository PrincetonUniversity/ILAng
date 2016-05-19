#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_688;
	bool cppVar_690 = (aes_state == 0);
	bool cppVar_692 = (cmd == 2);
	bool cppVar_693 = cppVar_690 && cppVar_692;
	bool cppVar_695 = (cmdaddr == 65285);
	bool cppVar_696 = cppVar_693 && cppVar_695;
	if (cppVar_696) {
	BIT_VEC cppVar_697 = (aes_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_698 = (cmddata << 8) | cppVar_697;
	cppVar_698 = (cppVar_698 & cppMask_un_16_);
	cppVar_688 = cppVar_698;
	} else {
	BIT_VEC cppVar_699;
	bool cppVar_701 = (aes_state == 0);
	bool cppVar_703 = (cmd == 2);
	bool cppVar_704 = cppVar_701 && cppVar_703;
	bool cppVar_706 = (cmdaddr == 65284);
	bool cppVar_707 = cppVar_704 && cppVar_706;
	if (cppVar_707) {
	BIT_VEC cppVar_708 = (aes_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_709 = (cppVar_708 << 8) | cmddata;
	cppVar_709 = (cppVar_709 & cppMask_un_16_);
	cppVar_699 = cppVar_709;
	} else {
	cppVar_699 = aes_len;
	}
	cppVar_688 = cppVar_699;
	}
	return cppVar_688;
}
