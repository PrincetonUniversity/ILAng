#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_hs_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1039;
	bool cppVar_1041 = (sha_state != 0);
	if (cppVar_1041) {
	BIT_VEC cppVar_1042;
	bool cppVar_1044 = (sha_state == 3);
	if (cppVar_1044) {
	BIT_VEC cppVar_1045 = sha(sha_rd_data);
	cppVar_1042 = cppVar_1045;
	} else {
	cppVar_1042 = sha_hs_data;
	}
	cppVar_1039 = cppVar_1042;
	} else {
	cppVar_1039 = sha_hs_data;
	}
	return cppVar_1039;
}
