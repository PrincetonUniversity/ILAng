#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_wraddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1015;
	bool cppVar_1017 = (sha_state == 0);
	bool cppVar_1019 = (cmd == 2);
	bool cppVar_1020 = cppVar_1017 && cppVar_1019;
	bool cppVar_1022 = (cmdaddr == 65029);
	bool cppVar_1023 = cppVar_1020 && cppVar_1022;
	if (cppVar_1023) {
	BIT_VEC cppVar_1024 = (sha_wraddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_1025 = (cmddata << 8) | cppVar_1024;
	cppVar_1025 = (cppVar_1025 & cppMask_un_16_);
	cppVar_1015 = cppVar_1025;
	} else {
	BIT_VEC cppVar_1026;
	bool cppVar_1028 = (sha_state == 0);
	bool cppVar_1030 = (cmd == 2);
	bool cppVar_1031 = cppVar_1028 && cppVar_1030;
	bool cppVar_1033 = (cmdaddr == 65028);
	bool cppVar_1034 = cppVar_1031 && cppVar_1033;
	if (cppVar_1034) {
	BIT_VEC cppVar_1035 = (sha_wraddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_1036 = (cppVar_1035 << 8) | cmddata;
	cppVar_1036 = (cppVar_1036 & cppMask_un_16_);
	cppVar_1026 = cppVar_1036;
	} else {
	cppVar_1026 = sha_wraddr;
	}
	cppVar_1015 = cppVar_1026;
	}
	return cppVar_1015;
}
