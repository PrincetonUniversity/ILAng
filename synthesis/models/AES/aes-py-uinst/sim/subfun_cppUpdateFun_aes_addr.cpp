#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_addr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_37;
	bool cppVar_39 = (aes_state == 0);
	bool cppVar_41 = (cmd == 2);
	bool cppVar_42 = cppVar_39 && cppVar_41;
	bool cppVar_44 = (cmdaddr == 65283);
	bool cppVar_45 = cppVar_42 && cppVar_44;
	if (cppVar_45) {
	BIT_VEC cppVar_46 = (aes_addr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_47 = (cmddata << 8) | cppVar_46;
	cppVar_47 = (cppVar_47 & cppMask_un_16_);
	cppVar_37 = cppVar_47;
	} else {
	BIT_VEC cppVar_48;
	bool cppVar_50 = (aes_state == 0);
	bool cppVar_52 = (cmd == 2);
	bool cppVar_53 = cppVar_50 && cppVar_52;
	bool cppVar_55 = (cmdaddr == 65282);
	bool cppVar_56 = cppVar_53 && cppVar_55;
	if (cppVar_56) {
	BIT_VEC cppVar_57 = (aes_addr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_58 = (cppVar_57 << 8) | cmddata;
	cppVar_58 = (cppVar_58 & cppMask_un_16_);
	cppVar_48 = cppVar_58;
	} else {
	cppVar_48 = aes_addr;
	}
	cppVar_37 = cppVar_48;
	}
	return cppVar_37;
}
