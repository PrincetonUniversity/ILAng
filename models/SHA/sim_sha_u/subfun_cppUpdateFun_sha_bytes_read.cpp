#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_bytes_read(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1048;
	bool cppVar_1050 = (sha_state != 0);
	if (cppVar_1050) {
	BIT_VEC cppVar_1051;
	bool cppVar_1053 = (sha_state == 1);
	if (cppVar_1053) {
	BIT_VEC cppVar_1055 = sha_bytes_read + 64;
	cppVar_1055 = (cppVar_1055 & cppMask_un_16_);
	cppVar_1051 = cppVar_1055;
	} else {
	cppVar_1051 = sha_bytes_read;
	}
	cppVar_1048 = cppVar_1051;
	} else {
	cppVar_1048 = sha_bytes_read;
	}
	return cppVar_1048;
}
