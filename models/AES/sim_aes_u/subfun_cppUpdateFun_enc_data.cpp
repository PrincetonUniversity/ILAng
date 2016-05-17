#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_enc_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_4159;
	bool cppVar_4161 = (aes_state != 0);
	if (cppVar_4161) {
	BIT_VEC cppVar_4162;
	bool cppVar_4164 = (aes_state == 2);
	if (cppVar_4164) {
	BIT_VEC cppVar_4165;
	bool cppVar_4167 = (aes_keysel == 0);
	if (cppVar_4167) {
	cppVar_4165 = aes_key0;
	} else {
	cppVar_4165 = aes_key1;
	}
	BIT_VEC cppVar_4168 = aes(aes_ctr, cppVar_4165, rd_data);
	cppVar_4162 = cppVar_4168;
	} else {
	cppVar_4162 = enc_data;
	}
	cppVar_4159 = cppVar_4162;
	} else {
	cppVar_4159 = enc_data;
	}
	return cppVar_4159;
}
