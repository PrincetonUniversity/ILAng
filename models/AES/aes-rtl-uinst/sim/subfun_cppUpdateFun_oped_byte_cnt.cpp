#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_oped_byte_cnt(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_4268;
	bool cppVar_4270 = (aes_state != 0);
	if (cppVar_4270) {
	BIT_VEC cppVar_4271;
	bool cppVar_4273 = (aes_state == 3);
	bool cppVar_4275 = (byte_cnt == 15);
	bool cppVar_4276 = cppVar_4273 && cppVar_4275;
	if (cppVar_4276) {
	BIT_VEC cppVar_4278 = oped_byte_cnt + 16;
	cppVar_4278 = (cppVar_4278 & cppMask_un_16_);
	cppVar_4271 = cppVar_4278;
	} else {
	cppVar_4271 = oped_byte_cnt;
	}
	cppVar_4268 = cppVar_4271;
	} else {
	cppVar_4268 = oped_byte_cnt;
	}
	return cppVar_4268;
}
