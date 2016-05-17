#include "common.hpp"
#include "model_sha_class.hpp"

type_mem model_sha::cppUpdateFun_XRAM(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	type_mem cppVar_1038;
	bool cppVar_1040 = (sha_state != 0);
	if (cppVar_1040) {
	type_mem cppVar_1041;
	bool cppVar_1043 = (sha_state == 4);
	if (cppVar_1043) {
	BIT_VEC cppVar_1046;
	type_mem cppVar_1044 = XRAM;
	for (int cppVar_1045 = 0; cppVar_1045 < 20; cppVar_1045++) {
		cppVar_1046 = sha_hs_data >> ((20 - 1 - cppVar_1045) * 8);
		cppVar_1044.wr(sha_wraddr + cppVar_1045, cppVar_1046);
	}
	cppVar_1041 = cppVar_1044;
	} else {
	cppVar_1041 = XRAM;
	}
	cppVar_1038 = cppVar_1041;
	} else {
	cppVar_1038 = XRAM;
	}
	return cppVar_1038;
}
