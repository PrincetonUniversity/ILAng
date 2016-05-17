#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_hs_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1057;
	bool cppVar_1059 = (sha_state != 0);
	if (cppVar_1059) {
	BIT_VEC cppVar_1060;
	bool cppVar_1062 = (sha_state == 3);
	if (cppVar_1062) {
	BIT_VEC cppVar_1063 = sha(sha_rd_data);
	cppVar_1060 = cppVar_1063;
	} else {
	cppVar_1060 = sha_hs_data;
	}
	cppVar_1057 = cppVar_1060;
	} else {
	cppVar_1057 = sha_hs_data;
	}
	return cppVar_1057;
}
