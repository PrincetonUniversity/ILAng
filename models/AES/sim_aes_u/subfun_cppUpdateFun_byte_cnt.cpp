#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_byte_cnt(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_3705;
	bool cppVar_3707 = (aes_state != 0);
	if (cppVar_3707) {
	BIT_VEC cppVar_3708;
	bool cppVar_3710 = (aes_state == 3);
	if (cppVar_3710) {
	BIT_VEC cppVar_3712 = byte_cnt + 16;
	cppVar_3712 = (cppVar_3712 & cppMask_un_16_);
	cppVar_3708 = cppVar_3712;
	} else {
	cppVar_3708 = byte_cnt;
	}
	cppVar_3705 = cppVar_3708;
	} else {
	cppVar_3705 = byte_cnt;
	}
	return cppVar_3705;
}
