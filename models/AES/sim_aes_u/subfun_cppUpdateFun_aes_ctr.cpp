#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_ctr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_60;
	bool cppVar_62 = (aes_state == 0);
	bool cppVar_64 = (cmd == 2);
	bool cppVar_65 = cppVar_62 && cppVar_64;
	bool cppVar_67 = (cmdaddr == 65311);
	bool cppVar_68 = cppVar_65 && cppVar_67;
	if (cppVar_68) {
	BIT_VEC cppVar_69 = (aes_ctr >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_70 = (cmddata << 120) | cppVar_69;
	cppVar_70 = (cppVar_70 & cppMask_un_128_);
	cppVar_60 = cppVar_70;
	} else {
	BIT_VEC cppVar_71;
	bool cppVar_73 = (aes_state == 0);
	bool cppVar_75 = (cmd == 2);
	bool cppVar_76 = cppVar_73 && cppVar_75;
	bool cppVar_78 = (cmdaddr == 65310);
	bool cppVar_79 = cppVar_76 && cppVar_78;
	if (cppVar_79) {
	BIT_VEC cppVar_80 = (aes_ctr >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_81 = (cppVar_80 << 8) | cmddata;
	cppVar_81 = (cppVar_81 & cppMask_un_16_);
	BIT_VEC cppVar_82 = (aes_ctr >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_83 = (cppVar_81 << 112) | cppVar_82;
	cppVar_83 = (cppVar_83 & cppMask_un_128_);
	cppVar_71 = cppVar_83;
	} else {
	BIT_VEC cppVar_84;
	bool cppVar_86 = (aes_state == 0);
	bool cppVar_88 = (cmd == 2);
	bool cppVar_89 = cppVar_86 && cppVar_88;
	bool cppVar_91 = (cmdaddr == 65309);
	bool cppVar_92 = cppVar_89 && cppVar_91;
	if (cppVar_92) {
	BIT_VEC cppVar_93 = (aes_ctr >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_94 = (cppVar_93 << 8) | cmddata;
	cppVar_94 = (cppVar_94 & cppMask_un_24_);
	BIT_VEC cppVar_95 = (aes_ctr >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_96 = (cppVar_94 << 104) | cppVar_95;
	cppVar_96 = (cppVar_96 & cppMask_un_128_);
	cppVar_84 = cppVar_96;
	} else {
	BIT_VEC cppVar_97;
	bool cppVar_99 = (aes_state == 0);
	bool cppVar_101 = (cmd == 2);
	bool cppVar_102 = cppVar_99 && cppVar_101;
	bool cppVar_104 = (cmdaddr == 65308);
	bool cppVar_105 = cppVar_102 && cppVar_104;
	if (cppVar_105) {
	BIT_VEC cppVar_106 = (aes_ctr >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_107 = (cppVar_106 << 8) | cmddata;
	cppVar_107 = (cppVar_107 & cppMask_un_32_);
	BIT_VEC cppVar_108 = (aes_ctr >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_109 = (cppVar_107 << 96) | cppVar_108;
	cppVar_109 = (cppVar_109 & cppMask_un_128_);
	cppVar_97 = cppVar_109;
	} else {
	BIT_VEC cppVar_110;
	bool cppVar_112 = (aes_state == 0);
	bool cppVar_114 = (cmd == 2);
	bool cppVar_115 = cppVar_112 && cppVar_114;
	bool cppVar_117 = (cmdaddr == 65307);
	bool cppVar_118 = cppVar_115 && cppVar_117;
	if (cppVar_118) {
	BIT_VEC cppVar_119 = (aes_ctr >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_120 = (cppVar_119 << 8) | cmddata;
	cppVar_120 = (cppVar_120 & cppMask_un_40_);
	BIT_VEC cppVar_121 = (aes_ctr >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_122 = (cppVar_120 << 88) | cppVar_121;
	cppVar_122 = (cppVar_122 & cppMask_un_128_);
	cppVar_110 = cppVar_122;
	} else {
	BIT_VEC cppVar_123;
	bool cppVar_125 = (aes_state == 0);
	bool cppVar_127 = (cmd == 2);
	bool cppVar_128 = cppVar_125 && cppVar_127;
	bool cppVar_130 = (cmdaddr == 65306);
	bool cppVar_131 = cppVar_128 && cppVar_130;
	if (cppVar_131) {
	BIT_VEC cppVar_132 = (aes_ctr >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_133 = (cppVar_132 << 8) | cmddata;
	cppVar_133 = (cppVar_133 & cppMask_un_48_);
	BIT_VEC cppVar_134 = (aes_ctr >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_135 = (cppVar_133 << 80) | cppVar_134;
	cppVar_135 = (cppVar_135 & cppMask_un_128_);
	cppVar_123 = cppVar_135;
	} else {
	BIT_VEC cppVar_136;
	bool cppVar_138 = (aes_state == 0);
	bool cppVar_140 = (cmd == 2);
	bool cppVar_141 = cppVar_138 && cppVar_140;
	bool cppVar_143 = (cmdaddr == 65305);
	bool cppVar_144 = cppVar_141 && cppVar_143;
	if (cppVar_144) {
	BIT_VEC cppVar_145 = (aes_ctr >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_146 = (cppVar_145 << 8) | cmddata;
	cppVar_146 = (cppVar_146 & cppMask_un_56_);
	BIT_VEC cppVar_147 = (aes_ctr >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_148 = (cppVar_146 << 72) | cppVar_147;
	cppVar_148 = (cppVar_148 & cppMask_un_128_);
	cppVar_136 = cppVar_148;
	} else {
	BIT_VEC cppVar_149;
	bool cppVar_151 = (aes_state == 0);
	bool cppVar_153 = (cmd == 2);
	bool cppVar_154 = cppVar_151 && cppVar_153;
	bool cppVar_156 = (cmdaddr == 65304);
	bool cppVar_157 = cppVar_154 && cppVar_156;
	if (cppVar_157) {
	BIT_VEC cppVar_158 = (aes_ctr >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_159 = (cppVar_158 << 8) | cmddata;
	cppVar_159 = (cppVar_159 & cppMask_un_64_);
	BIT_VEC cppVar_160 = (aes_ctr >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_161 = (cppVar_159 << 64) | cppVar_160;
	cppVar_161 = (cppVar_161 & cppMask_un_128_);
	cppVar_149 = cppVar_161;
	} else {
	BIT_VEC cppVar_162;
	bool cppVar_164 = (aes_state == 0);
	bool cppVar_166 = (cmd == 2);
	bool cppVar_167 = cppVar_164 && cppVar_166;
	bool cppVar_169 = (cmdaddr == 65303);
	bool cppVar_170 = cppVar_167 && cppVar_169;
	if (cppVar_170) {
	BIT_VEC cppVar_171 = (aes_ctr >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_172 = (cppVar_171 << 8) | cmddata;
	cppVar_172 = (cppVar_172 & cppMask_un_72_);
	BIT_VEC cppVar_173 = (aes_ctr >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_174 = (cppVar_172 << 56) | cppVar_173;
	cppVar_174 = (cppVar_174 & cppMask_un_128_);
	cppVar_162 = cppVar_174;
	} else {
	BIT_VEC cppVar_175;
	bool cppVar_177 = (aes_state == 0);
	bool cppVar_179 = (cmd == 2);
	bool cppVar_180 = cppVar_177 && cppVar_179;
	bool cppVar_182 = (cmdaddr == 65302);
	bool cppVar_183 = cppVar_180 && cppVar_182;
	if (cppVar_183) {
	BIT_VEC cppVar_184 = (aes_ctr >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_185 = (cppVar_184 << 8) | cmddata;
	cppVar_185 = (cppVar_185 & cppMask_un_80_);
	BIT_VEC cppVar_186 = (aes_ctr >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_187 = (cppVar_185 << 48) | cppVar_186;
	cppVar_187 = (cppVar_187 & cppMask_un_128_);
	cppVar_175 = cppVar_187;
	} else {
	BIT_VEC cppVar_188;
	bool cppVar_190 = (aes_state == 0);
	bool cppVar_192 = (cmd == 2);
	bool cppVar_193 = cppVar_190 && cppVar_192;
	bool cppVar_195 = (cmdaddr == 65301);
	bool cppVar_196 = cppVar_193 && cppVar_195;
	if (cppVar_196) {
	BIT_VEC cppVar_197 = (aes_ctr >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_198 = (cppVar_197 << 8) | cmddata;
	cppVar_198 = (cppVar_198 & cppMask_un_88_);
	BIT_VEC cppVar_199 = (aes_ctr >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_200 = (cppVar_198 << 40) | cppVar_199;
	cppVar_200 = (cppVar_200 & cppMask_un_128_);
	cppVar_188 = cppVar_200;
	} else {
	BIT_VEC cppVar_201;
	bool cppVar_203 = (aes_state == 0);
	bool cppVar_205 = (cmd == 2);
	bool cppVar_206 = cppVar_203 && cppVar_205;
	bool cppVar_208 = (cmdaddr == 65300);
	bool cppVar_209 = cppVar_206 && cppVar_208;
	if (cppVar_209) {
	BIT_VEC cppVar_210 = (aes_ctr >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_211 = (cppVar_210 << 8) | cmddata;
	cppVar_211 = (cppVar_211 & cppMask_un_96_);
	BIT_VEC cppVar_212 = (aes_ctr >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_213 = (cppVar_211 << 32) | cppVar_212;
	cppVar_213 = (cppVar_213 & cppMask_un_128_);
	cppVar_201 = cppVar_213;
	} else {
	BIT_VEC cppVar_214;
	bool cppVar_216 = (aes_state == 0);
	bool cppVar_218 = (cmd == 2);
	bool cppVar_219 = cppVar_216 && cppVar_218;
	bool cppVar_221 = (cmdaddr == 65299);
	bool cppVar_222 = cppVar_219 && cppVar_221;
	if (cppVar_222) {
	BIT_VEC cppVar_223 = (aes_ctr >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_224 = (cppVar_223 << 8) | cmddata;
	cppVar_224 = (cppVar_224 & cppMask_un_104_);
	BIT_VEC cppVar_225 = (aes_ctr >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_226 = (cppVar_224 << 24) | cppVar_225;
	cppVar_226 = (cppVar_226 & cppMask_un_128_);
	cppVar_214 = cppVar_226;
	} else {
	BIT_VEC cppVar_227;
	bool cppVar_229 = (aes_state == 0);
	bool cppVar_231 = (cmd == 2);
	bool cppVar_232 = cppVar_229 && cppVar_231;
	bool cppVar_234 = (cmdaddr == 65298);
	bool cppVar_235 = cppVar_232 && cppVar_234;
	if (cppVar_235) {
	BIT_VEC cppVar_236 = (aes_ctr >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_237 = (cppVar_236 << 8) | cmddata;
	cppVar_237 = (cppVar_237 & cppMask_un_112_);
	BIT_VEC cppVar_238 = (aes_ctr >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_239 = (cppVar_237 << 16) | cppVar_238;
	cppVar_239 = (cppVar_239 & cppMask_un_128_);
	cppVar_227 = cppVar_239;
	} else {
	BIT_VEC cppVar_240;
	bool cppVar_242 = (aes_state == 0);
	bool cppVar_244 = (cmd == 2);
	bool cppVar_245 = cppVar_242 && cppVar_244;
	bool cppVar_247 = (cmdaddr == 65297);
	bool cppVar_248 = cppVar_245 && cppVar_247;
	if (cppVar_248) {
	BIT_VEC cppVar_249 = (aes_ctr >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_250 = (cppVar_249 << 8) | cmddata;
	cppVar_250 = (cppVar_250 & cppMask_un_120_);
	BIT_VEC cppVar_251 = (aes_ctr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_252 = (cppVar_250 << 8) | cppVar_251;
	cppVar_252 = (cppVar_252 & cppMask_un_128_);
	cppVar_240 = cppVar_252;
	} else {
	BIT_VEC cppVar_253;
	bool cppVar_255 = (aes_state == 0);
	bool cppVar_257 = (cmd == 2);
	bool cppVar_258 = cppVar_255 && cppVar_257;
	bool cppVar_260 = (cmdaddr == 65296);
	bool cppVar_261 = cppVar_258 && cppVar_260;
	if (cppVar_261) {
	BIT_VEC cppVar_262 = (aes_ctr >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_263 = (cppVar_262 << 8) | cmddata;
	cppVar_263 = (cppVar_263 & cppMask_un_128_);
	cppVar_253 = cppVar_263;
	} else {
	cppVar_253 = aes_ctr;
	}
	cppVar_240 = cppVar_253;
	}
	cppVar_227 = cppVar_240;
	}
	cppVar_214 = cppVar_227;
	}
	cppVar_201 = cppVar_214;
	}
	cppVar_188 = cppVar_201;
	}
	cppVar_175 = cppVar_188;
	}
	cppVar_162 = cppVar_175;
	}
	cppVar_149 = cppVar_162;
	}
	cppVar_136 = cppVar_149;
	}
	cppVar_123 = cppVar_136;
	}
	cppVar_110 = cppVar_123;
	}
	cppVar_97 = cppVar_110;
	}
	cppVar_84 = cppVar_97;
	}
	cppVar_71 = cppVar_84;
	}
	cppVar_60 = cppVar_71;
	}
	return cppVar_60;
}
