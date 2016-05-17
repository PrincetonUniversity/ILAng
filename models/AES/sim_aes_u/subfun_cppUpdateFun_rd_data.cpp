#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_3725;
	bool cppVar_3727 = (aes_state != 0);
	if (cppVar_3727) {
	BIT_VEC cppVar_3728;
	bool cppVar_3730 = (aes_state == 1);
	if (cppVar_3730) {
	BIT_VEC cppVar_3731 = aes_addr + byte_cnt;
	cppVar_3731 = (cppVar_3731 & cppMask_un_16_);
	BIT_VEC cppVar_3732 = (XRAM.rd(cppVar_3731) & cppMask_un_8_);
	for (int cppVar_3733 = 1; cppVar_3733 < 16; cppVar_3733++) {
		cppVar_3732 = cppVar_3732 | ((XRAM.rd(cppVar_3731 + cppVar_3733) & cppMask_un_8_) << (8 * cppVar_3733));
	}
	cppVar_3732 = (cppVar_3732 & cppMask_un_128_);
	cppVar_3728 = cppVar_3732;
	} else {
	cppVar_3728 = rd_data;
	}
	cppVar_3725 = cppVar_3728;
	} else {
	cppVar_3725 = rd_data;
	}
	return cppVar_3725;
}
