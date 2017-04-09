#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_669;
	bool cppVar_671 = (aes_state == 0);
	bool cppVar_673 = (cmd == 2);
	bool cppVar_674 = cppVar_671 && cppVar_673;
	bool cppVar_676 = (cmdaddr == 65285);
	bool cppVar_677 = cppVar_674 && cppVar_676;
	if (cppVar_677) {
	BIT_VEC cppVar_678 = (aes_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_679 = (cmddata << 8) | cppVar_678;
	cppVar_679 = (cppVar_679 & cppMask_un_16_);
	cppVar_669 = cppVar_679;
	} else {
	BIT_VEC cppVar_680;
	bool cppVar_682 = (aes_state == 0);
	bool cppVar_684 = (cmd == 2);
	bool cppVar_685 = cppVar_682 && cppVar_684;
	bool cppVar_687 = (cmdaddr == 65284);
	bool cppVar_688 = cppVar_685 && cppVar_687;
	if (cppVar_688) {
	BIT_VEC cppVar_689 = (aes_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_690 = (cppVar_689 << 8) | cmddata;
	cppVar_690 = (cppVar_690 & cppMask_un_16_);
	cppVar_680 = cppVar_690;
	} else {
	cppVar_680 = aes_len;
	}
	cppVar_669 = cppVar_680;
	}
	return cppVar_669;
}
