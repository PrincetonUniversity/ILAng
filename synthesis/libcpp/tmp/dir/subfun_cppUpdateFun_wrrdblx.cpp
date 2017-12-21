#include "common.hpp"
#include "model_alu_class.hpp"

BIT_VEC model_alu::cppUpdateFun_wrrdblx()
{
	BIT_VEC cppVar_181;
	BIT_VEC cppVar_180;
	type_mem<BV8,256> cppVar_182;
	BIT_VEC cppVar_183;
	type_mem<BV8,256> cppVar_184;
	BIT_VEC cppVar_187;
	cppVar_182 = xram;
	cppVar_182.wr(4, 254);
	BIT_VEC cppVar_186;
	cppVar_184 = cppVar_182;
	for (int cppVar_185 = 0; cppVar_185 < 3; cppVar_185++) {
		cppVar_186 = 983294 >> (cppVar_185 * 8);
		cppVar_186 = (cppVar_186 & cppMask_un_8_);
		cppVar_184.wr(4 + cppVar_185, cppVar_186);
	}
	cppVar_187 = (cppVar_184.rd(4) & cppMask_un_8_);
	for (int cppVar_188 = 1; cppVar_188 < 3; cppVar_188++) {
		cppVar_187 = cppVar_187 | ((cppVar_184.rd(4 + cppVar_188) & cppMask_un_8_) << (8 * cppVar_188));
	}
	cppVar_187 = (cppVar_187 & cppMask_un_24_);
	return cppVar_187;
}
