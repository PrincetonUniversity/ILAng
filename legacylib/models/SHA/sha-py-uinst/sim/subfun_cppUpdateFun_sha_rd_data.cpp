#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1047;
	bool cppVar_1049 = (sha_state != 0);
	if (cppVar_1049) {
	BIT_VEC cppVar_1050;
	bool cppVar_1052 = (sha_state == 1);
	if (cppVar_1052) {
	BIT_VEC cppVar_1053 = sha_rdaddr + sha_bytes_read;
	cppVar_1053 = (cppVar_1053 & cppMask_un_16_);
	BIT_VEC cppVar_1054 = (XRAM.rd(cppVar_1053) & cppMask_un_8_);
	for (int cppVar_1055 = 1; cppVar_1055 < 64; cppVar_1055++) {
		cppVar_1054 = (cppVar_1054 << 8) | (XRAM.rd(cppVar_1053 + cppVar_1055) & cppMask_un_8_);
	}
	cppVar_1054 = (cppVar_1054 & cppMask_un_512_);
	cppVar_1050 = cppVar_1054;
	} else {
	cppVar_1050 = sha_rd_data;
	}
	cppVar_1047 = cppVar_1050;
	} else {
	cppVar_1047 = sha_rd_data;
	}
	return cppVar_1047;
}
