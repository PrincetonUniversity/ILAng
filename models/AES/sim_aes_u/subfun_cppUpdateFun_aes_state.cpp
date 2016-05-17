#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_state(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_709;
	bool cppVar_711 = (aes_state != 0);
	if (cppVar_711) {
	BIT_VEC cppVar_712;
	bool cppVar_714 = (aes_state == 3);
	if (cppVar_714) {
	BIT_VEC cppVar_715;
	BIT_VEC cppVar_717 = byte_cnt + 16;
	cppVar_717 = (cppVar_717 & cppMask_un_16_);
	bool cppVar_718 = cppVar_717 < aes_len;
	if (cppVar_718) {
	cppVar_715 = 1;
	} else {
	cppVar_715 = 0;
	}
	cppVar_712 = cppVar_715;
	} else {
	BIT_VEC cppVar_721;
	bool cppVar_723 = (aes_state == 2);
	if (cppVar_723) {
	cppVar_721 = 3;
	} else {
	BIT_VEC cppVar_725;
	bool cppVar_727 = (aes_state == 1);
	if (cppVar_727) {
	cppVar_725 = 2;
	} else {
	cppVar_725 = aes_state;
	}
	cppVar_721 = cppVar_725;
	}
	cppVar_712 = cppVar_721;
	}
	cppVar_709 = cppVar_712;
	} else {
	BIT_VEC cppVar_729;
	bool cppVar_731 = (aes_state == 0);
	bool cppVar_733 = (cmd == 2);
	bool cppVar_734 = cppVar_731 && cppVar_733;
	bool cppVar_736 = (cmdaddr == 65280);
	bool cppVar_737 = cppVar_734 && cppVar_736;
	if (cppVar_737) {
	BIT_VEC cppVar_738;
	bool cppVar_740 = (cmddata == 1);
	if (cppVar_740) {
	cppVar_738 = 1;
	} else {
	cppVar_738 = aes_state;
	}
	cppVar_729 = cppVar_738;
	} else {
	cppVar_729 = aes_state;
	}
	cppVar_709 = cppVar_729;
	}
	return cppVar_709;
}
