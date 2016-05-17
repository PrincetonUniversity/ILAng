#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_byte_cnt(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_4146;
	bool cppVar_4148 = (aes_state != 0);
	if (cppVar_4148) {
	BIT_VEC cppVar_4149;
	bool cppVar_4151 = (aes_state == 3);
	if (cppVar_4151) {
	BIT_VEC cppVar_4152;
	BIT_VEC cppVar_4154 = byte_cnt + 16;
	cppVar_4154 = (cppVar_4154 & cppMask_un_16_);
	bool cppVar_4155 = cppVar_4154 < aes_len;
	if (cppVar_4155) {
	BIT_VEC cppVar_4157 = byte_cnt + 16;
	cppVar_4157 = (cppVar_4157 & cppMask_un_16_);
	cppVar_4152 = cppVar_4157;
	} else {
	cppVar_4152 = byte_cnt;
	}
	cppVar_4149 = cppVar_4152;
	} else {
	cppVar_4149 = byte_cnt;
	}
	cppVar_4146 = cppVar_4149;
	} else {
	cppVar_4146 = byte_cnt;
	}
	return cppVar_4146;
}
