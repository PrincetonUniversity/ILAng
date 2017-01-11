#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_rdaddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_2373;
	bool cppVar_2375 = (sha_state == 0);
	bool cppVar_2377 = (cmd == 2);
	bool cppVar_2378 = cppVar_2375 && cppVar_2377;
	bool cppVar_2380 = (cmdaddr == 65027);
	bool cppVar_2381 = cppVar_2378 && cppVar_2380;
	if (cppVar_2381) {
	BIT_VEC cppVar_2382 = (sha_rdaddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_2383 = (cmddata << 8) | cppVar_2382;
	cppVar_2383 = (cppVar_2383 & cppMask_un_16_);
	cppVar_2373 = cppVar_2383;
	} else {
	BIT_VEC cppVar_2384;
	bool cppVar_2386 = (sha_state == 0);
	bool cppVar_2388 = (cmd == 2);
	bool cppVar_2389 = cppVar_2386 && cppVar_2388;
	bool cppVar_2391 = (cmdaddr == 65026);
	bool cppVar_2392 = cppVar_2389 && cppVar_2391;
	if (cppVar_2392) {
	BIT_VEC cppVar_2393 = (sha_rdaddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_2394 = (cppVar_2393 << 8) | cmddata;
	cppVar_2394 = (cppVar_2394 & cppMask_un_16_);
	cppVar_2384 = cppVar_2394;
	} else {
	cppVar_2384 = sha_rdaddr;
	}
	cppVar_2373 = cppVar_2384;
	}
	return cppVar_2373;
}
