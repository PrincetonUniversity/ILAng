#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_addr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_39;
	bool cppVar_41 = (aes_state == 0);
	bool cppVar_43 = (cmd == 2);
	bool cppVar_44 = cppVar_41 && cppVar_43;
	bool cppVar_46 = (cmdaddr == 65283);
	bool cppVar_47 = cppVar_44 && cppVar_46;
	if (cppVar_47) {
	BIT_VEC cppVar_48 = (aes_addr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_49 = (cmddata << 8) | cppVar_48;
	cppVar_49 = (cppVar_49 & cppMask_un_16_);
	cppVar_39 = cppVar_49;
	} else {
	BIT_VEC cppVar_50;
	bool cppVar_52 = (aes_state == 0);
	bool cppVar_54 = (cmd == 2);
	bool cppVar_55 = cppVar_52 && cppVar_54;
	bool cppVar_57 = (cmdaddr == 65282);
	bool cppVar_58 = cppVar_55 && cppVar_57;
	if (cppVar_58) {
	BIT_VEC cppVar_59 = (aes_addr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_60 = (cppVar_59 << 8) | cmddata;
	cppVar_60 = (cppVar_60 & cppMask_un_16_);
	cppVar_50 = cppVar_60;
	} else {
	cppVar_50 = aes_addr;
	}
	cppVar_39 = cppVar_50;
	}
	return cppVar_39;
}
