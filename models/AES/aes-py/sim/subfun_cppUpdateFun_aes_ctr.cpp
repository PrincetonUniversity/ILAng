#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_ctr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_43;
	bool cppVar_45 = (aes_state == 0);
	bool cppVar_47 = (cmd == 2);
	bool cppVar_48 = cppVar_45 && cppVar_47;
	bool cppVar_50 = (cmdaddr == 65311);
	bool cppVar_51 = cppVar_48 && cppVar_50;
	if (cppVar_51) {
	BIT_VEC cppVar_52 = (aes_ctr >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_53 = (cmddata << 120) | cppVar_52;
	cppVar_53 = (cppVar_53 & cppMask_un_128_);
	cppVar_43 = cppVar_53;
	} else {
	BIT_VEC cppVar_54;
	bool cppVar_56 = (aes_state == 0);
	bool cppVar_58 = (cmd == 2);
	bool cppVar_59 = cppVar_56 && cppVar_58;
	bool cppVar_61 = (cmdaddr == 65310);
	bool cppVar_62 = cppVar_59 && cppVar_61;
	if (cppVar_62) {
	BIT_VEC cppVar_63 = (aes_ctr >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_64 = (cppVar_63 << 8) | cmddata;
	cppVar_64 = (cppVar_64 & cppMask_un_16_);
	BIT_VEC cppVar_65 = (aes_ctr >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_66 = (cppVar_64 << 112) | cppVar_65;
	cppVar_66 = (cppVar_66 & cppMask_un_128_);
	cppVar_54 = cppVar_66;
	} else {
	BIT_VEC cppVar_67;
	bool cppVar_69 = (aes_state == 0);
	bool cppVar_71 = (cmd == 2);
	bool cppVar_72 = cppVar_69 && cppVar_71;
	bool cppVar_74 = (cmdaddr == 65309);
	bool cppVar_75 = cppVar_72 && cppVar_74;
	if (cppVar_75) {
	BIT_VEC cppVar_76 = (aes_ctr >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_77 = (cppVar_76 << 8) | cmddata;
	cppVar_77 = (cppVar_77 & cppMask_un_24_);
	BIT_VEC cppVar_78 = (aes_ctr >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_79 = (cppVar_77 << 104) | cppVar_78;
	cppVar_79 = (cppVar_79 & cppMask_un_128_);
	cppVar_67 = cppVar_79;
	} else {
	BIT_VEC cppVar_80;
	bool cppVar_82 = (aes_state == 0);
	bool cppVar_84 = (cmd == 2);
	bool cppVar_85 = cppVar_82 && cppVar_84;
	bool cppVar_87 = (cmdaddr == 65308);
	bool cppVar_88 = cppVar_85 && cppVar_87;
	if (cppVar_88) {
	BIT_VEC cppVar_89 = (aes_ctr >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_90 = (cppVar_89 << 8) | cmddata;
	cppVar_90 = (cppVar_90 & cppMask_un_32_);
	BIT_VEC cppVar_91 = (aes_ctr >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_92 = (cppVar_90 << 96) | cppVar_91;
	cppVar_92 = (cppVar_92 & cppMask_un_128_);
	cppVar_80 = cppVar_92;
	} else {
	BIT_VEC cppVar_93;
	bool cppVar_95 = (aes_state == 0);
	bool cppVar_97 = (cmd == 2);
	bool cppVar_98 = cppVar_95 && cppVar_97;
	bool cppVar_100 = (cmdaddr == 65307);
	bool cppVar_101 = cppVar_98 && cppVar_100;
	if (cppVar_101) {
	BIT_VEC cppVar_102 = (aes_ctr >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_103 = (cppVar_102 << 8) | cmddata;
	cppVar_103 = (cppVar_103 & cppMask_un_40_);
	BIT_VEC cppVar_104 = (aes_ctr >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_105 = (cppVar_103 << 88) | cppVar_104;
	cppVar_105 = (cppVar_105 & cppMask_un_128_);
	cppVar_93 = cppVar_105;
	} else {
	BIT_VEC cppVar_106;
	bool cppVar_108 = (aes_state == 0);
	bool cppVar_110 = (cmd == 2);
	bool cppVar_111 = cppVar_108 && cppVar_110;
	bool cppVar_113 = (cmdaddr == 65306);
	bool cppVar_114 = cppVar_111 && cppVar_113;
	if (cppVar_114) {
	BIT_VEC cppVar_115 = (aes_ctr >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_116 = (cppVar_115 << 8) | cmddata;
	cppVar_116 = (cppVar_116 & cppMask_un_48_);
	BIT_VEC cppVar_117 = (aes_ctr >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_118 = (cppVar_116 << 80) | cppVar_117;
	cppVar_118 = (cppVar_118 & cppMask_un_128_);
	cppVar_106 = cppVar_118;
	} else {
	BIT_VEC cppVar_119;
	bool cppVar_121 = (aes_state == 0);
	bool cppVar_123 = (cmd == 2);
	bool cppVar_124 = cppVar_121 && cppVar_123;
	bool cppVar_126 = (cmdaddr == 65305);
	bool cppVar_127 = cppVar_124 && cppVar_126;
	if (cppVar_127) {
	BIT_VEC cppVar_128 = (aes_ctr >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_129 = (cppVar_128 << 8) | cmddata;
	cppVar_129 = (cppVar_129 & cppMask_un_56_);
	BIT_VEC cppVar_130 = (aes_ctr >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_131 = (cppVar_129 << 72) | cppVar_130;
	cppVar_131 = (cppVar_131 & cppMask_un_128_);
	cppVar_119 = cppVar_131;
	} else {
	BIT_VEC cppVar_132;
	bool cppVar_134 = (aes_state == 0);
	bool cppVar_136 = (cmd == 2);
	bool cppVar_137 = cppVar_134 && cppVar_136;
	bool cppVar_139 = (cmdaddr == 65304);
	bool cppVar_140 = cppVar_137 && cppVar_139;
	if (cppVar_140) {
	BIT_VEC cppVar_141 = (aes_ctr >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_142 = (cppVar_141 << 8) | cmddata;
	cppVar_142 = (cppVar_142 & cppMask_un_64_);
	BIT_VEC cppVar_143 = (aes_ctr >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_144 = (cppVar_142 << 64) | cppVar_143;
	cppVar_144 = (cppVar_144 & cppMask_un_128_);
	cppVar_132 = cppVar_144;
	} else {
	BIT_VEC cppVar_145;
	bool cppVar_147 = (aes_state == 0);
	bool cppVar_149 = (cmd == 2);
	bool cppVar_150 = cppVar_147 && cppVar_149;
	bool cppVar_152 = (cmdaddr == 65303);
	bool cppVar_153 = cppVar_150 && cppVar_152;
	if (cppVar_153) {
	BIT_VEC cppVar_154 = (aes_ctr >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_155 = (cppVar_154 << 8) | cmddata;
	cppVar_155 = (cppVar_155 & cppMask_un_72_);
	BIT_VEC cppVar_156 = (aes_ctr >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_157 = (cppVar_155 << 56) | cppVar_156;
	cppVar_157 = (cppVar_157 & cppMask_un_128_);
	cppVar_145 = cppVar_157;
	} else {
	BIT_VEC cppVar_158;
	bool cppVar_160 = (aes_state == 0);
	bool cppVar_162 = (cmd == 2);
	bool cppVar_163 = cppVar_160 && cppVar_162;
	bool cppVar_165 = (cmdaddr == 65302);
	bool cppVar_166 = cppVar_163 && cppVar_165;
	if (cppVar_166) {
	BIT_VEC cppVar_167 = (aes_ctr >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_168 = (cppVar_167 << 8) | cmddata;
	cppVar_168 = (cppVar_168 & cppMask_un_80_);
	BIT_VEC cppVar_169 = (aes_ctr >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_170 = (cppVar_168 << 48) | cppVar_169;
	cppVar_170 = (cppVar_170 & cppMask_un_128_);
	cppVar_158 = cppVar_170;
	} else {
	BIT_VEC cppVar_171;
	bool cppVar_173 = (aes_state == 0);
	bool cppVar_175 = (cmd == 2);
	bool cppVar_176 = cppVar_173 && cppVar_175;
	bool cppVar_178 = (cmdaddr == 65301);
	bool cppVar_179 = cppVar_176 && cppVar_178;
	if (cppVar_179) {
	BIT_VEC cppVar_180 = (aes_ctr >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_181 = (cppVar_180 << 8) | cmddata;
	cppVar_181 = (cppVar_181 & cppMask_un_88_);
	BIT_VEC cppVar_182 = (aes_ctr >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_183 = (cppVar_181 << 40) | cppVar_182;
	cppVar_183 = (cppVar_183 & cppMask_un_128_);
	cppVar_171 = cppVar_183;
	} else {
	BIT_VEC cppVar_184;
	bool cppVar_186 = (aes_state == 0);
	bool cppVar_188 = (cmd == 2);
	bool cppVar_189 = cppVar_186 && cppVar_188;
	bool cppVar_191 = (cmdaddr == 65300);
	bool cppVar_192 = cppVar_189 && cppVar_191;
	if (cppVar_192) {
	BIT_VEC cppVar_193 = (aes_ctr >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_194 = (cppVar_193 << 8) | cmddata;
	cppVar_194 = (cppVar_194 & cppMask_un_96_);
	BIT_VEC cppVar_195 = (aes_ctr >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_196 = (cppVar_194 << 32) | cppVar_195;
	cppVar_196 = (cppVar_196 & cppMask_un_128_);
	cppVar_184 = cppVar_196;
	} else {
	BIT_VEC cppVar_197;
	bool cppVar_199 = (aes_state == 0);
	bool cppVar_201 = (cmd == 2);
	bool cppVar_202 = cppVar_199 && cppVar_201;
	bool cppVar_204 = (cmdaddr == 65299);
	bool cppVar_205 = cppVar_202 && cppVar_204;
	if (cppVar_205) {
	BIT_VEC cppVar_206 = (aes_ctr >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_207 = (cppVar_206 << 8) | cmddata;
	cppVar_207 = (cppVar_207 & cppMask_un_104_);
	BIT_VEC cppVar_208 = (aes_ctr >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_209 = (cppVar_207 << 24) | cppVar_208;
	cppVar_209 = (cppVar_209 & cppMask_un_128_);
	cppVar_197 = cppVar_209;
	} else {
	BIT_VEC cppVar_210;
	bool cppVar_212 = (aes_state == 0);
	bool cppVar_214 = (cmd == 2);
	bool cppVar_215 = cppVar_212 && cppVar_214;
	bool cppVar_217 = (cmdaddr == 65298);
	bool cppVar_218 = cppVar_215 && cppVar_217;
	if (cppVar_218) {
	BIT_VEC cppVar_219 = (aes_ctr >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_220 = (cppVar_219 << 8) | cmddata;
	cppVar_220 = (cppVar_220 & cppMask_un_112_);
	BIT_VEC cppVar_221 = (aes_ctr >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_222 = (cppVar_220 << 16) | cppVar_221;
	cppVar_222 = (cppVar_222 & cppMask_un_128_);
	cppVar_210 = cppVar_222;
	} else {
	BIT_VEC cppVar_223;
	bool cppVar_225 = (aes_state == 0);
	bool cppVar_227 = (cmd == 2);
	bool cppVar_228 = cppVar_225 && cppVar_227;
	bool cppVar_230 = (cmdaddr == 65297);
	bool cppVar_231 = cppVar_228 && cppVar_230;
	if (cppVar_231) {
	BIT_VEC cppVar_232 = (aes_ctr >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_233 = (cppVar_232 << 8) | cmddata;
	cppVar_233 = (cppVar_233 & cppMask_un_120_);
	BIT_VEC cppVar_234 = (aes_ctr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_235 = (cppVar_233 << 8) | cppVar_234;
	cppVar_235 = (cppVar_235 & cppMask_un_128_);
	cppVar_223 = cppVar_235;
	} else {
	BIT_VEC cppVar_236;
	bool cppVar_238 = (aes_state == 0);
	bool cppVar_240 = (cmd == 2);
	bool cppVar_241 = cppVar_238 && cppVar_240;
	bool cppVar_243 = (cmdaddr == 65296);
	bool cppVar_244 = cppVar_241 && cppVar_243;
	if (cppVar_244) {
	BIT_VEC cppVar_245 = (aes_ctr >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_246 = (cppVar_245 << 8) | cmddata;
	cppVar_246 = (cppVar_246 & cppMask_un_128_);
	cppVar_236 = cppVar_246;
	} else {
	cppVar_236 = aes_ctr;
	}
	cppVar_223 = cppVar_236;
	}
	cppVar_210 = cppVar_223;
	}
	cppVar_197 = cppVar_210;
	}
	cppVar_184 = cppVar_197;
	}
	cppVar_171 = cppVar_184;
	}
	cppVar_158 = cppVar_171;
	}
	cppVar_145 = cppVar_158;
	}
	cppVar_132 = cppVar_145;
	}
	cppVar_119 = cppVar_132;
	}
	cppVar_106 = cppVar_119;
	}
	cppVar_93 = cppVar_106;
	}
	cppVar_80 = cppVar_93;
	}
	cppVar_67 = cppVar_80;
	}
	cppVar_54 = cppVar_67;
	}
	cppVar_43 = cppVar_54;
	}
	return cppVar_43;
}
