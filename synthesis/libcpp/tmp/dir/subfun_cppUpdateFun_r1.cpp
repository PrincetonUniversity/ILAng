#include "common.hpp"
#include "model_alu_class.hpp"

BIT_VEC model_alu::cppUpdateFun_r1()
{
	BIT_VEC cppVar_171;
	bool cppVar_172;
	BIT_VEC cppVar_167;
	bool cppVar_168;
	BIT_VEC cppVar_163;
	bool cppVar_164;
	BIT_VEC cppVar_159;
	bool cppVar_160;
	BIT_VEC cppVar_142;
	BIT_VEC cppVar_155;
	bool cppVar_156;
	BIT_VEC cppVar_173;
	BIT_VEC cppVar_169;
	BIT_VEC cppVar_151;
	BIT_VEC cppVar_165;
	bool cppVar_152;
	BIT_VEC cppVar_161;
	BIT_VEC cppVar_157;
	BIT_VEC cppVar_147;
	BIT_VEC cppVar_153;
	bool cppVar_148;
	BIT_VEC cppVar_149;
	BIT_VEC cppVar_145;
	BIT_VEC cppVar_170;
	BIT_VEC cppVar_166;
	BIT_VEC cppVar_162;
	BIT_VEC cppVar_158;
	BIT_VEC cppVar_154;
	BIT_VEC cppVar_150;
	BIT_VEC cppVar_146;
	BIT_VEC cppVar_141;
	BIT_VEC cppVar_143;
	bool cppVar_144;
	cppVar_142 = rom.rd(pc);
	cppVar_144 = (cppVar_142 == 15);
	if (cppVar_144) {
	cppVar_145 = -((r1 & cppMask_bit_4_) ? (r1 | cppMask_sign_4_) : r1);
	cppVar_141 = cppVar_145;
	} else {
	cppVar_148 = (cppVar_142 == 13);
	if (cppVar_148) {
	cppVar_149 = r1 | r0;
	cppVar_146 = cppVar_149;
	} else {
	cppVar_152 = (cppVar_142 == 11);
	if (cppVar_152) {
	cppVar_153 = ~r1;
	cppVar_150 = cppVar_153;
	} else {
	cppVar_156 = (cppVar_142 == 9);
	if (cppVar_156) {
	cppVar_157 = r1 & r0;
	cppVar_154 = cppVar_157;
	} else {
	cppVar_160 = (cppVar_142 == 7);
	if (cppVar_160) {
	cppVar_161 = r0 - r0;
	cppVar_161 = (cppVar_161 & cppMask_un_4_);
	cppVar_158 = cppVar_161;
	} else {
	cppVar_164 = (cppVar_142 == 5);
	if (cppVar_164) {
	cppVar_165 = r1 - r0;
	cppVar_165 = (cppVar_165 & cppMask_un_4_);
	cppVar_162 = cppVar_165;
	} else {
	cppVar_168 = (cppVar_142 == 3);
	if (cppVar_168) {
	cppVar_169 = r1 + r1;
	cppVar_169 = (cppVar_169 & cppMask_un_4_);
	cppVar_166 = cppVar_169;
	} else {
	cppVar_172 = (cppVar_142 == 1);
	if (cppVar_172) {
	cppVar_173 = r0 + r1;
	cppVar_173 = (cppVar_173 & cppMask_un_4_);
	cppVar_170 = cppVar_173;
	} else {
	cppVar_170 = r1;
	}
	cppVar_166 = cppVar_170;
	}
	cppVar_162 = cppVar_166;
	}
	cppVar_158 = cppVar_162;
	}
	cppVar_154 = cppVar_158;
	}
	cppVar_150 = cppVar_154;
	}
	cppVar_146 = cppVar_150;
	}
	cppVar_141 = cppVar_146;
	}
	return cppVar_141;
}
