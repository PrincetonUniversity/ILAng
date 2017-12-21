#include "common.hpp"
#include "model_alu_class.hpp"

BIT_VEC model_alu::cppUpdateFun_r0()
{
	BIT_VEC cppVar_137;
	bool cppVar_138;
	BIT_VEC cppVar_133;
	bool cppVar_134;
	BIT_VEC cppVar_139;
	BIT_VEC cppVar_129;
	BIT_VEC cppVar_135;
	bool cppVar_130;
	BIT_VEC cppVar_131;
	BIT_VEC cppVar_127;
	BIT_VEC cppVar_123;
	BIT_VEC cppVar_125;
	BIT_VEC cppVar_119;
	bool cppVar_126;
	BIT_VEC cppVar_115;
	BIT_VEC cppVar_111;
	BIT_VEC cppVar_136;
	BIT_VEC cppVar_132;
	BIT_VEC cppVar_128;
	BIT_VEC cppVar_108;
	BIT_VEC cppVar_121;
	BIT_VEC cppVar_124;
	BIT_VEC cppVar_120;
	BIT_VEC cppVar_116;
	BIT_VEC cppVar_112;
	BIT_VEC cppVar_107;
	bool cppVar_122;
	BIT_VEC cppVar_117;
	bool cppVar_118;
	BIT_VEC cppVar_113;
	bool cppVar_114;
	BIT_VEC cppVar_109;
	bool cppVar_110;
	cppVar_108 = rom.rd(pc);
	cppVar_110 = (cppVar_108 == 14);
	if (cppVar_110) {
	cppVar_111 = r0 | r1;
	cppVar_107 = cppVar_111;
	} else {
	cppVar_114 = (cppVar_108 == 12);
	if (cppVar_114) {
	cppVar_115 = -((r0 & cppMask_bit_4_) ? (r0 | cppMask_sign_4_) : r0);
	cppVar_112 = cppVar_115;
	} else {
	cppVar_118 = (cppVar_108 == 10);
	if (cppVar_118) {
	cppVar_119 = r0 & r1;
	cppVar_116 = cppVar_119;
	} else {
	cppVar_122 = (cppVar_108 == 8);
	if (cppVar_122) {
	cppVar_123 = ~r0;
	cppVar_120 = cppVar_123;
	} else {
	cppVar_126 = (cppVar_108 == 6);
	if (cppVar_126) {
	cppVar_127 = r0 - r1;
	cppVar_127 = (cppVar_127 & cppMask_un_4_);
	cppVar_124 = cppVar_127;
	} else {
	cppVar_130 = (cppVar_108 == 4);
	if (cppVar_130) {
	cppVar_131 = r0 - r0;
	cppVar_131 = (cppVar_131 & cppMask_un_4_);
	cppVar_128 = cppVar_131;
	} else {
	cppVar_134 = (cppVar_108 == 2);
	if (cppVar_134) {
	cppVar_135 = r0 + r1;
	cppVar_135 = (cppVar_135 & cppMask_un_4_);
	cppVar_132 = cppVar_135;
	} else {
	cppVar_138 = (cppVar_108 == 0);
	if (cppVar_138) {
	cppVar_139 = r0 + r0;
	cppVar_139 = (cppVar_139 & cppMask_un_4_);
	cppVar_136 = cppVar_139;
	} else {
	cppVar_136 = r0;
	}
	cppVar_132 = cppVar_136;
	}
	cppVar_128 = cppVar_132;
	}
	cppVar_124 = cppVar_128;
	}
	cppVar_120 = cppVar_124;
	}
	cppVar_116 = cppVar_120;
	}
	cppVar_112 = cppVar_116;
	}
	cppVar_107 = cppVar_112;
	}
	return cppVar_107;
}
