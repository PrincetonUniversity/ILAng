#include "common.hpp"
#include "model_aes_class.hpp"

type_mem model_aes::cppUpdateFun_XRAM(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	type_mem cppVar_4135;
	bool cppVar_4137 = (aes_state != 0);
	if (cppVar_4137) {
	type_mem cppVar_4138;
	bool cppVar_4140 = (aes_state == 3);
	if (cppVar_4140) {
	BIT_VEC cppVar_4141 = aes_addr + byte_cnt;
	cppVar_4141 = (cppVar_4141 & cppMask_un_16_);
	BIT_VEC cppVar_4144;
	type_mem cppVar_4142 = XRAM;
	for (int cppVar_4143 = 0; cppVar_4143 < 16; cppVar_4143++) {
		cppVar_4144 = enc_data >> (cppVar_4143 * 8);
		cppVar_4142.wr(cppVar_4141 + cppVar_4143, cppVar_4144);
	}
	cppVar_4138 = cppVar_4142;
	} else {
	cppVar_4138 = XRAM;
	}
	cppVar_4135 = cppVar_4138;
	} else {
	cppVar_4135 = XRAM;
	}
	return cppVar_4135;
}
