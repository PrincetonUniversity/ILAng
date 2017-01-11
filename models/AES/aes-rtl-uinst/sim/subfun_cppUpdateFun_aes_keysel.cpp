#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_keysel(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_677;
	bool cppVar_679 = (aes_state == 0);
	bool cppVar_681 = (cmd == 2);
	bool cppVar_682 = cppVar_679 && cppVar_681;
	bool cppVar_684 = (cmdaddr == 65286);
	bool cppVar_685 = cppVar_682 && cppVar_684;
	if (cppVar_685) {
	BIT_VEC cppVar_686 = (cmddata >> 0) & cppMask_un_1_;
	cppVar_677 = cppVar_686;
	} else {
	cppVar_677 = aes_keysel;
	}
	return cppVar_677;
}
