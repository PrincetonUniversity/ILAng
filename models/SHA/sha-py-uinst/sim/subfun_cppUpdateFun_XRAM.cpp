#include "common.hpp"
#include "model_sha_class.hpp"

type_mem model_sha::cppUpdateFun_XRAM(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	type_mem cppVar_1020;
	bool cppVar_1022 = (sha_state != 0);
	if (cppVar_1022) {
	type_mem cppVar_1023;
	bool cppVar_1025 = (sha_state == 4);
	if (cppVar_1025) {
	BIT_VEC cppVar_1028;
	type_mem cppVar_1026 = XRAM;
	for (int cppVar_1027 = 0; cppVar_1027 < 20; cppVar_1027++) {
		cppVar_1028 = sha_hs_data >> ((20 - 1 - cppVar_1027) * 8);
		cppVar_1026.wr(sha_wraddr + cppVar_1027, cppVar_1028);
	}
	cppVar_1023 = cppVar_1026;
	} else {
	cppVar_1023 = XRAM;
	}
	cppVar_1020 = cppVar_1023;
	} else {
	cppVar_1020 = XRAM;
	}
	return cppVar_1020;
}
