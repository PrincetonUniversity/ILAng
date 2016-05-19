#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_enc_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_4257;
	bool cppVar_4259 = (aes_state != 0);
	if (cppVar_4259) {
	BIT_VEC cppVar_4260;
	bool cppVar_4262 = (aes_state == 2);
	if (cppVar_4262) {
	BIT_VEC cppVar_4263;
	bool cppVar_4265 = (aes_keysel == 0);
	if (cppVar_4265) {
	cppVar_4263 = aes_key0;
	} else {
	cppVar_4263 = aes_key1;
	}
	BIT_VEC cppVar_4266 = aes(aes_ctr, cppVar_4263, rd_data);
	cppVar_4260 = cppVar_4266;
	} else {
	cppVar_4260 = enc_data;
	}
	cppVar_4257 = cppVar_4260;
	} else {
	cppVar_4257 = enc_data;
	}
	return cppVar_4257;
}
