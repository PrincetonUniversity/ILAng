#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_blk_cnt(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_4036;
	bool cppVar_4038 = (aes_state != 0);
	if (cppVar_4038) {
	BIT_VEC cppVar_4039;
	bool cppVar_4041 = (aes_state == 3);
	bool cppVar_4043 = (byte_cnt == 15);
	bool cppVar_4044 = cppVar_4041 && cppVar_4043;
	if (cppVar_4044) {
	BIT_VEC cppVar_4045;
	BIT_VEC cppVar_4047 = oped_byte_cnt + 16;
	cppVar_4047 = (cppVar_4047 & cppMask_un_16_);
	bool cppVar_4048 = cppVar_4047 < aes_len;
	if (cppVar_4048) {
	BIT_VEC cppVar_4050 = blk_cnt + 16;
	cppVar_4050 = (cppVar_4050 & cppMask_un_16_);
	cppVar_4045 = cppVar_4050;
	} else {
	cppVar_4045 = blk_cnt;
	}
	cppVar_4039 = cppVar_4045;
	} else {
	cppVar_4039 = blk_cnt;
	}
	cppVar_4036 = cppVar_4039;
	} else {
	cppVar_4036 = blk_cnt;
	}
	return cppVar_4036;
}
