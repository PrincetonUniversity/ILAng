#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_rdaddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_938;
	bool cppVar_940 = (sha_state == 0);
	bool cppVar_942 = (cmd == 2);
	bool cppVar_943 = cppVar_940 && cppVar_942;
	bool cppVar_945 = (cmdaddr == 65027);
	bool cppVar_946 = cppVar_943 && cppVar_945;
	if (cppVar_946) {
	BIT_VEC cppVar_947 = (sha_rdaddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_948 = (cmddata << 8) | cppVar_947;
	cppVar_948 = (cppVar_948 & cppMask_un_16_);
	cppVar_938 = cppVar_948;
	} else {
	BIT_VEC cppVar_949;
	bool cppVar_951 = (sha_state == 0);
	bool cppVar_953 = (cmd == 2);
	bool cppVar_954 = cppVar_951 && cppVar_953;
	bool cppVar_956 = (cmdaddr == 65026);
	bool cppVar_957 = cppVar_954 && cppVar_956;
	if (cppVar_957) {
	BIT_VEC cppVar_958 = (sha_rdaddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_959 = (cppVar_958 << 8) | cmddata;
	cppVar_959 = (cppVar_959 & cppMask_un_16_);
	cppVar_949 = cppVar_959;
	} else {
	cppVar_949 = sha_rdaddr;
	}
	cppVar_938 = cppVar_949;
	}
	return cppVar_938;
}
