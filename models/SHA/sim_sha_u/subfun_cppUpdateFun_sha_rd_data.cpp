#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1065;
	bool cppVar_1067 = (sha_state != 0);
	if (cppVar_1067) {
	BIT_VEC cppVar_1068;
	bool cppVar_1070 = (sha_state == 1);
	if (cppVar_1070) {
	BIT_VEC cppVar_1071 = sha_rdaddr + sha_bytes_read;
	cppVar_1071 = (cppVar_1071 & cppMask_un_16_);
	BIT_VEC cppVar_1072 = (XRAM.rd(cppVar_1071) & cppMask_un_8_);
	for (int cppVar_1073 = 1; cppVar_1073 < 64; cppVar_1073++) {
		cppVar_1072 = (cppVar_1072 << 8) | (XRAM.rd(cppVar_1071 + cppVar_1073) & cppMask_un_8_);
	}
	cppVar_1072 = (cppVar_1072 & cppMask_un_512_);
	cppVar_1068 = cppVar_1072;
	} else {
	cppVar_1068 = sha_rd_data;
	}
	cppVar_1065 = cppVar_1068;
	} else {
	cppVar_1065 = sha_rd_data;
	}
	return cppVar_1065;
}
