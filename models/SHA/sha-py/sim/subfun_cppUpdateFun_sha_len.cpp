#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_2058;
	bool cppVar_2060 = (sha_state == 0);
	bool cppVar_2062 = (cmd == 2);
	bool cppVar_2063 = cppVar_2060 && cppVar_2062;
	bool cppVar_2065 = (cmdaddr == 65031);
	bool cppVar_2066 = cppVar_2063 && cppVar_2065;
	if (cppVar_2066) {
	BIT_VEC cppVar_2067 = (sha_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_2068 = (cmddata << 8) | cppVar_2067;
	cppVar_2068 = (cppVar_2068 & cppMask_un_16_);
	cppVar_2058 = cppVar_2068;
	} else {
	BIT_VEC cppVar_2069;
	bool cppVar_2071 = (sha_state == 0);
	bool cppVar_2073 = (cmd == 2);
	bool cppVar_2074 = cppVar_2071 && cppVar_2073;
	bool cppVar_2076 = (cmdaddr == 65030);
	bool cppVar_2077 = cppVar_2074 && cppVar_2076;
	if (cppVar_2077) {
	BIT_VEC cppVar_2078 = (sha_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_2079 = (cppVar_2078 << 8) | cmddata;
	cppVar_2079 = (cppVar_2079 & cppMask_un_16_);
	cppVar_2069 = cppVar_2079;
	} else {
	cppVar_2069 = sha_len;
	}
	cppVar_2058 = cppVar_2069;
	}
	return cppVar_2058;
}
