#include "common.hpp"
#include "model_aes_class.hpp"

type_mem model_aes::cppUpdateFun_XRAM(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	type_mem cppVar_3694;
	bool cppVar_3696 = (aes_state != 0);
	if (cppVar_3696) {
	type_mem cppVar_3697;
	bool cppVar_3699 = (aes_state == 3);
	if (cppVar_3699) {
	BIT_VEC cppVar_3700 = aes_addr + byte_cnt;
	cppVar_3700 = (cppVar_3700 & cppMask_un_16_);
	BIT_VEC cppVar_3703;
	type_mem cppVar_3701 = XRAM;
	for (int cppVar_3702 = 0; cppVar_3702 < 16; cppVar_3702++) {
		cppVar_3703 = enc_data >> (cppVar_3702 * 8);
		cppVar_3701.wr(cppVar_3700 + cppVar_3702, cppVar_3703);
	}
	cppVar_3697 = cppVar_3701;
	} else {
	cppVar_3697 = XRAM;
	}
	cppVar_3694 = cppVar_3697;
	} else {
	cppVar_3694 = XRAM;
	}
	return cppVar_3694;
}
