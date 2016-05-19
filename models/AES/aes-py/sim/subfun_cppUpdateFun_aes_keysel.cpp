#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_keysel(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_658;
	bool cppVar_660 = (aes_state == 0);
	bool cppVar_662 = (cmd == 2);
	bool cppVar_663 = cppVar_660 && cppVar_662;
	bool cppVar_665 = (cmdaddr == 65286);
	bool cppVar_666 = cppVar_663 && cppVar_665;
	if (cppVar_666) {
	BIT_VEC cppVar_667 = (cmddata >> 0) & cppMask_un_1_;
	cppVar_658 = cppVar_667;
	} else {
	cppVar_658 = aes_keysel;
	}
	return cppVar_658;
}
