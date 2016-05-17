#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_keysel(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_675;
	bool cppVar_677 = (aes_state == 0);
	bool cppVar_679 = (cmd == 2);
	bool cppVar_680 = cppVar_677 && cppVar_679;
	bool cppVar_682 = (cmdaddr == 65286);
	bool cppVar_683 = cppVar_680 && cppVar_682;
	if (cppVar_683) {
	BIT_VEC cppVar_684 = (cmddata >> 0) & cppMask_un_1_;
	cppVar_675 = cppVar_684;
	} else {
	cppVar_675 = aes_keysel;
	}
	return cppVar_675;
}
