#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_addr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_20;
	bool cppVar_22 = (aes_state == 0);
	bool cppVar_24 = (cmd == 2);
	bool cppVar_25 = cppVar_22 && cppVar_24;
	bool cppVar_27 = (cmdaddr == 65283);
	bool cppVar_28 = cppVar_25 && cppVar_27;
	if (cppVar_28) {
	BIT_VEC cppVar_29 = (aes_addr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_30 = (cmddata << 8) | cppVar_29;
	cppVar_30 = (cppVar_30 & cppMask_un_16_);
	cppVar_20 = cppVar_30;
	} else {
	BIT_VEC cppVar_31;
	bool cppVar_33 = (aes_state == 0);
	bool cppVar_35 = (cmd == 2);
	bool cppVar_36 = cppVar_33 && cppVar_35;
	bool cppVar_38 = (cmdaddr == 65282);
	bool cppVar_39 = cppVar_36 && cppVar_38;
	if (cppVar_39) {
	BIT_VEC cppVar_40 = (aes_addr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_41 = (cppVar_40 << 8) | cmddata;
	cppVar_41 = (cppVar_41 & cppMask_un_16_);
	cppVar_31 = cppVar_41;
	} else {
	cppVar_31 = aes_addr;
	}
	cppVar_20 = cppVar_31;
	}
	return cppVar_20;
}
