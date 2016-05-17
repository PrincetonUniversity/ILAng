#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_4170;
	bool cppVar_4172 = (aes_state != 0);
	if (cppVar_4172) {
	BIT_VEC cppVar_4173;
	bool cppVar_4175 = (aes_state == 1);
	if (cppVar_4175) {
	BIT_VEC cppVar_4176 = aes_addr + byte_cnt;
	cppVar_4176 = (cppVar_4176 & cppMask_un_16_);
	BIT_VEC cppVar_4177 = (XRAM.rd(cppVar_4176) & cppMask_un_8_);
	for (int cppVar_4178 = 1; cppVar_4178 < 16; cppVar_4178++) {
		cppVar_4177 = cppVar_4177 | ((XRAM.rd(cppVar_4176 + cppVar_4178) & cppMask_un_8_) << (8 * cppVar_4178));
	}
	cppVar_4177 = (cppVar_4177 & cppMask_un_128_);
	cppVar_4173 = cppVar_4177;
	} else {
	cppVar_4173 = rd_data;
	}
	cppVar_4170 = cppVar_4173;
	} else {
	cppVar_4170 = rd_data;
	}
	return cppVar_4170;
}
