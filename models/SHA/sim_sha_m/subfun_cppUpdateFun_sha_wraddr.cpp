#include "common.hpp"
#include "model_sha_class.hpp"

BIT_VEC model_sha::cppUpdateFun_sha_wraddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_3848;
	bool cppVar_3850 = (sha_state == 0);
	bool cppVar_3852 = (cmd == 2);
	bool cppVar_3853 = cppVar_3850 && cppVar_3852;
	bool cppVar_3855 = (cmdaddr == 65029);
	bool cppVar_3856 = cppVar_3853 && cppVar_3855;
	if (cppVar_3856) {
	BIT_VEC cppVar_3857 = (sha_wraddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_3858 = (cmddata << 8) | cppVar_3857;
	cppVar_3858 = (cppVar_3858 & cppMask_un_16_);
	cppVar_3848 = cppVar_3858;
	} else {
	BIT_VEC cppVar_3859;
	bool cppVar_3861 = (sha_state == 0);
	bool cppVar_3863 = (cmd == 2);
	bool cppVar_3864 = cppVar_3861 && cppVar_3863;
	bool cppVar_3866 = (cmdaddr == 65028);
	bool cppVar_3867 = cppVar_3864 && cppVar_3866;
	if (cppVar_3867) {
	BIT_VEC cppVar_3868 = (sha_wraddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_3869 = (cppVar_3868 << 8) | cmddata;
	cppVar_3869 = (cppVar_3869 & cppMask_un_16_);
	cppVar_3859 = cppVar_3869;
	} else {
	cppVar_3859 = sha_wraddr;
	}
	cppVar_3848 = cppVar_3859;
	}
	return cppVar_3848;
}
