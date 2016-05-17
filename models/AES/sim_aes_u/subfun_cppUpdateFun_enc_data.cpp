#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_enc_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_3714;
	bool cppVar_3716 = (aes_state != 0);
	if (cppVar_3716) {
	BIT_VEC cppVar_3717;
	bool cppVar_3719 = (aes_state == 2);
	if (cppVar_3719) {
	BIT_VEC cppVar_3720;
	bool cppVar_3722 = (aes_keysel == 0);
	if (cppVar_3722) {
	cppVar_3720 = aes_key0;
	} else {
	cppVar_3720 = aes_key1;
	}
	BIT_VEC cppVar_3723 = aes(aes_ctr, cppVar_3720, rd_data);
	cppVar_3717 = cppVar_3723;
	} else {
	cppVar_3717 = enc_data;
	}
	cppVar_3714 = cppVar_3717;
	} else {
	cppVar_3714 = enc_data;
	}
	return cppVar_3714;
}
