#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_bytes_read(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1030;
	bool cppVar_1032 = (sha_state != 0);
	if (cppVar_1032) {
	BIT_VEC cppVar_1033;
	bool cppVar_1035 = (sha_state == 1);
	if (cppVar_1035) {
	BIT_VEC cppVar_1037 = sha_bytes_read + 64;
	cppVar_1037 = (cppVar_1037 & cppMask_un_16_);
	cppVar_1033 = cppVar_1037;
	} else {
	cppVar_1033 = sha_bytes_read;
	}
	cppVar_1030 = cppVar_1033;
	} else {
	cppVar_1030 = sha_bytes_read;
	}
	return cppVar_1030;
}
