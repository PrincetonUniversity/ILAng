#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_915;
	bool cppVar_917 = (sha_state == 0);
	bool cppVar_919 = (cmd == 2);
	bool cppVar_920 = cppVar_917 && cppVar_919;
	bool cppVar_922 = (cmdaddr == 65031);
	bool cppVar_923 = cppVar_920 && cppVar_922;
	if (cppVar_923) {
	BIT_VEC cppVar_924 = (sha_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_925 = (cmddata << 8) | cppVar_924;
	cppVar_925 = (cppVar_925 & cppMask_un_16_);
	cppVar_915 = cppVar_925;
	} else {
	BIT_VEC cppVar_926;
	bool cppVar_928 = (sha_state == 0);
	bool cppVar_930 = (cmd == 2);
	bool cppVar_931 = cppVar_928 && cppVar_930;
	bool cppVar_933 = (cmdaddr == 65030);
	bool cppVar_934 = cppVar_931 && cppVar_933;
	if (cppVar_934) {
	BIT_VEC cppVar_935 = (sha_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_936 = (cppVar_935 << 8) | cmddata;
	cppVar_936 = (cppVar_936 & cppMask_un_16_);
	cppVar_926 = cppVar_936;
	} else {
	cppVar_926 = sha_len;
	}
	cppVar_915 = cppVar_926;
	}
	return cppVar_915;
}
