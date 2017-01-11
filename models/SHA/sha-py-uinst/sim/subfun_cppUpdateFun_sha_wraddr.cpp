#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_wraddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_997;
	bool cppVar_999 = (sha_state == 0);
	bool cppVar_1001 = (cmd == 2);
	bool cppVar_1002 = cppVar_999 && cppVar_1001;
	bool cppVar_1004 = (cmdaddr == 65029);
	bool cppVar_1005 = cppVar_1002 && cppVar_1004;
	if (cppVar_1005) {
	BIT_VEC cppVar_1006 = (sha_wraddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_1007 = (cmddata << 8) | cppVar_1006;
	cppVar_1007 = (cppVar_1007 & cppMask_un_16_);
	cppVar_997 = cppVar_1007;
	} else {
	BIT_VEC cppVar_1008;
	bool cppVar_1010 = (sha_state == 0);
	bool cppVar_1012 = (cmd == 2);
	bool cppVar_1013 = cppVar_1010 && cppVar_1012;
	bool cppVar_1015 = (cmdaddr == 65028);
	bool cppVar_1016 = cppVar_1013 && cppVar_1015;
	if (cppVar_1016) {
	BIT_VEC cppVar_1017 = (sha_wraddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_1018 = (cppVar_1017 << 8) | cmddata;
	cppVar_1018 = (cppVar_1018 & cppMask_un_16_);
	cppVar_1008 = cppVar_1018;
	} else {
	cppVar_1008 = sha_wraddr;
	}
	cppVar_997 = cppVar_1008;
	}
	return cppVar_997;
}
