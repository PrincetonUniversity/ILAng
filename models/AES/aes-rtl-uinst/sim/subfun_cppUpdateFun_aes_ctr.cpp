#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_ctr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_62;
	bool cppVar_64 = (aes_state == 0);
	bool cppVar_66 = (cmd == 2);
	bool cppVar_67 = cppVar_64 && cppVar_66;
	bool cppVar_69 = (cmdaddr == 65311);
	bool cppVar_70 = cppVar_67 && cppVar_69;
	if (cppVar_70) {
	BIT_VEC cppVar_71 = (aes_ctr >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_72 = (cmddata << 120) | cppVar_71;
	cppVar_72 = (cppVar_72 & cppMask_un_128_);
	cppVar_62 = cppVar_72;
	} else {
	BIT_VEC cppVar_73;
	bool cppVar_75 = (aes_state == 0);
	bool cppVar_77 = (cmd == 2);
	bool cppVar_78 = cppVar_75 && cppVar_77;
	bool cppVar_80 = (cmdaddr == 65310);
	bool cppVar_81 = cppVar_78 && cppVar_80;
	if (cppVar_81) {
	BIT_VEC cppVar_82 = (aes_ctr >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_83 = (cppVar_82 << 8) | cmddata;
	cppVar_83 = (cppVar_83 & cppMask_un_16_);
	BIT_VEC cppVar_84 = (aes_ctr >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_85 = (cppVar_83 << 112) | cppVar_84;
	cppVar_85 = (cppVar_85 & cppMask_un_128_);
	cppVar_73 = cppVar_85;
	} else {
	BIT_VEC cppVar_86;
	bool cppVar_88 = (aes_state == 0);
	bool cppVar_90 = (cmd == 2);
	bool cppVar_91 = cppVar_88 && cppVar_90;
	bool cppVar_93 = (cmdaddr == 65309);
	bool cppVar_94 = cppVar_91 && cppVar_93;
	if (cppVar_94) {
	BIT_VEC cppVar_95 = (aes_ctr >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_96 = (cppVar_95 << 8) | cmddata;
	cppVar_96 = (cppVar_96 & cppMask_un_24_);
	BIT_VEC cppVar_97 = (aes_ctr >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_98 = (cppVar_96 << 104) | cppVar_97;
	cppVar_98 = (cppVar_98 & cppMask_un_128_);
	cppVar_86 = cppVar_98;
	} else {
	BIT_VEC cppVar_99;
	bool cppVar_101 = (aes_state == 0);
	bool cppVar_103 = (cmd == 2);
	bool cppVar_104 = cppVar_101 && cppVar_103;
	bool cppVar_106 = (cmdaddr == 65308);
	bool cppVar_107 = cppVar_104 && cppVar_106;
	if (cppVar_107) {
	BIT_VEC cppVar_108 = (aes_ctr >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_109 = (cppVar_108 << 8) | cmddata;
	cppVar_109 = (cppVar_109 & cppMask_un_32_);
	BIT_VEC cppVar_110 = (aes_ctr >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_111 = (cppVar_109 << 96) | cppVar_110;
	cppVar_111 = (cppVar_111 & cppMask_un_128_);
	cppVar_99 = cppVar_111;
	} else {
	BIT_VEC cppVar_112;
	bool cppVar_114 = (aes_state == 0);
	bool cppVar_116 = (cmd == 2);
	bool cppVar_117 = cppVar_114 && cppVar_116;
	bool cppVar_119 = (cmdaddr == 65307);
	bool cppVar_120 = cppVar_117 && cppVar_119;
	if (cppVar_120) {
	BIT_VEC cppVar_121 = (aes_ctr >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_122 = (cppVar_121 << 8) | cmddata;
	cppVar_122 = (cppVar_122 & cppMask_un_40_);
	BIT_VEC cppVar_123 = (aes_ctr >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_124 = (cppVar_122 << 88) | cppVar_123;
	cppVar_124 = (cppVar_124 & cppMask_un_128_);
	cppVar_112 = cppVar_124;
	} else {
	BIT_VEC cppVar_125;
	bool cppVar_127 = (aes_state == 0);
	bool cppVar_129 = (cmd == 2);
	bool cppVar_130 = cppVar_127 && cppVar_129;
	bool cppVar_132 = (cmdaddr == 65306);
	bool cppVar_133 = cppVar_130 && cppVar_132;
	if (cppVar_133) {
	BIT_VEC cppVar_134 = (aes_ctr >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_135 = (cppVar_134 << 8) | cmddata;
	cppVar_135 = (cppVar_135 & cppMask_un_48_);
	BIT_VEC cppVar_136 = (aes_ctr >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_137 = (cppVar_135 << 80) | cppVar_136;
	cppVar_137 = (cppVar_137 & cppMask_un_128_);
	cppVar_125 = cppVar_137;
	} else {
	BIT_VEC cppVar_138;
	bool cppVar_140 = (aes_state == 0);
	bool cppVar_142 = (cmd == 2);
	bool cppVar_143 = cppVar_140 && cppVar_142;
	bool cppVar_145 = (cmdaddr == 65305);
	bool cppVar_146 = cppVar_143 && cppVar_145;
	if (cppVar_146) {
	BIT_VEC cppVar_147 = (aes_ctr >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_148 = (cppVar_147 << 8) | cmddata;
	cppVar_148 = (cppVar_148 & cppMask_un_56_);
	BIT_VEC cppVar_149 = (aes_ctr >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_150 = (cppVar_148 << 72) | cppVar_149;
	cppVar_150 = (cppVar_150 & cppMask_un_128_);
	cppVar_138 = cppVar_150;
	} else {
	BIT_VEC cppVar_151;
	bool cppVar_153 = (aes_state == 0);
	bool cppVar_155 = (cmd == 2);
	bool cppVar_156 = cppVar_153 && cppVar_155;
	bool cppVar_158 = (cmdaddr == 65304);
	bool cppVar_159 = cppVar_156 && cppVar_158;
	if (cppVar_159) {
	BIT_VEC cppVar_160 = (aes_ctr >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_161 = (cppVar_160 << 8) | cmddata;
	cppVar_161 = (cppVar_161 & cppMask_un_64_);
	BIT_VEC cppVar_162 = (aes_ctr >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_163 = (cppVar_161 << 64) | cppVar_162;
	cppVar_163 = (cppVar_163 & cppMask_un_128_);
	cppVar_151 = cppVar_163;
	} else {
	BIT_VEC cppVar_164;
	bool cppVar_166 = (aes_state == 0);
	bool cppVar_168 = (cmd == 2);
	bool cppVar_169 = cppVar_166 && cppVar_168;
	bool cppVar_171 = (cmdaddr == 65303);
	bool cppVar_172 = cppVar_169 && cppVar_171;
	if (cppVar_172) {
	BIT_VEC cppVar_173 = (aes_ctr >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_174 = (cppVar_173 << 8) | cmddata;
	cppVar_174 = (cppVar_174 & cppMask_un_72_);
	BIT_VEC cppVar_175 = (aes_ctr >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_176 = (cppVar_174 << 56) | cppVar_175;
	cppVar_176 = (cppVar_176 & cppMask_un_128_);
	cppVar_164 = cppVar_176;
	} else {
	BIT_VEC cppVar_177;
	bool cppVar_179 = (aes_state == 0);
	bool cppVar_181 = (cmd == 2);
	bool cppVar_182 = cppVar_179 && cppVar_181;
	bool cppVar_184 = (cmdaddr == 65302);
	bool cppVar_185 = cppVar_182 && cppVar_184;
	if (cppVar_185) {
	BIT_VEC cppVar_186 = (aes_ctr >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_187 = (cppVar_186 << 8) | cmddata;
	cppVar_187 = (cppVar_187 & cppMask_un_80_);
	BIT_VEC cppVar_188 = (aes_ctr >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_189 = (cppVar_187 << 48) | cppVar_188;
	cppVar_189 = (cppVar_189 & cppMask_un_128_);
	cppVar_177 = cppVar_189;
	} else {
	BIT_VEC cppVar_190;
	bool cppVar_192 = (aes_state == 0);
	bool cppVar_194 = (cmd == 2);
	bool cppVar_195 = cppVar_192 && cppVar_194;
	bool cppVar_197 = (cmdaddr == 65301);
	bool cppVar_198 = cppVar_195 && cppVar_197;
	if (cppVar_198) {
	BIT_VEC cppVar_199 = (aes_ctr >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_200 = (cppVar_199 << 8) | cmddata;
	cppVar_200 = (cppVar_200 & cppMask_un_88_);
	BIT_VEC cppVar_201 = (aes_ctr >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_202 = (cppVar_200 << 40) | cppVar_201;
	cppVar_202 = (cppVar_202 & cppMask_un_128_);
	cppVar_190 = cppVar_202;
	} else {
	BIT_VEC cppVar_203;
	bool cppVar_205 = (aes_state == 0);
	bool cppVar_207 = (cmd == 2);
	bool cppVar_208 = cppVar_205 && cppVar_207;
	bool cppVar_210 = (cmdaddr == 65300);
	bool cppVar_211 = cppVar_208 && cppVar_210;
	if (cppVar_211) {
	BIT_VEC cppVar_212 = (aes_ctr >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_213 = (cppVar_212 << 8) | cmddata;
	cppVar_213 = (cppVar_213 & cppMask_un_96_);
	BIT_VEC cppVar_214 = (aes_ctr >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_215 = (cppVar_213 << 32) | cppVar_214;
	cppVar_215 = (cppVar_215 & cppMask_un_128_);
	cppVar_203 = cppVar_215;
	} else {
	BIT_VEC cppVar_216;
	bool cppVar_218 = (aes_state == 0);
	bool cppVar_220 = (cmd == 2);
	bool cppVar_221 = cppVar_218 && cppVar_220;
	bool cppVar_223 = (cmdaddr == 65299);
	bool cppVar_224 = cppVar_221 && cppVar_223;
	if (cppVar_224) {
	BIT_VEC cppVar_225 = (aes_ctr >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_226 = (cppVar_225 << 8) | cmddata;
	cppVar_226 = (cppVar_226 & cppMask_un_104_);
	BIT_VEC cppVar_227 = (aes_ctr >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_228 = (cppVar_226 << 24) | cppVar_227;
	cppVar_228 = (cppVar_228 & cppMask_un_128_);
	cppVar_216 = cppVar_228;
	} else {
	BIT_VEC cppVar_229;
	bool cppVar_231 = (aes_state == 0);
	bool cppVar_233 = (cmd == 2);
	bool cppVar_234 = cppVar_231 && cppVar_233;
	bool cppVar_236 = (cmdaddr == 65298);
	bool cppVar_237 = cppVar_234 && cppVar_236;
	if (cppVar_237) {
	BIT_VEC cppVar_238 = (aes_ctr >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_239 = (cppVar_238 << 8) | cmddata;
	cppVar_239 = (cppVar_239 & cppMask_un_112_);
	BIT_VEC cppVar_240 = (aes_ctr >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_241 = (cppVar_239 << 16) | cppVar_240;
	cppVar_241 = (cppVar_241 & cppMask_un_128_);
	cppVar_229 = cppVar_241;
	} else {
	BIT_VEC cppVar_242;
	bool cppVar_244 = (aes_state == 0);
	bool cppVar_246 = (cmd == 2);
	bool cppVar_247 = cppVar_244 && cppVar_246;
	bool cppVar_249 = (cmdaddr == 65297);
	bool cppVar_250 = cppVar_247 && cppVar_249;
	if (cppVar_250) {
	BIT_VEC cppVar_251 = (aes_ctr >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_252 = (cppVar_251 << 8) | cmddata;
	cppVar_252 = (cppVar_252 & cppMask_un_120_);
	BIT_VEC cppVar_253 = (aes_ctr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_254 = (cppVar_252 << 8) | cppVar_253;
	cppVar_254 = (cppVar_254 & cppMask_un_128_);
	cppVar_242 = cppVar_254;
	} else {
	BIT_VEC cppVar_255;
	bool cppVar_257 = (aes_state == 0);
	bool cppVar_259 = (cmd == 2);
	bool cppVar_260 = cppVar_257 && cppVar_259;
	bool cppVar_262 = (cmdaddr == 65296);
	bool cppVar_263 = cppVar_260 && cppVar_262;
	if (cppVar_263) {
	BIT_VEC cppVar_264 = (aes_ctr >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_265 = (cppVar_264 << 8) | cmddata;
	cppVar_265 = (cppVar_265 & cppMask_un_128_);
	cppVar_255 = cppVar_265;
	} else {
	cppVar_255 = aes_ctr;
	}
	cppVar_242 = cppVar_255;
	}
	cppVar_229 = cppVar_242;
	}
	cppVar_216 = cppVar_229;
	}
	cppVar_203 = cppVar_216;
	}
	cppVar_190 = cppVar_203;
	}
	cppVar_177 = cppVar_190;
	}
	cppVar_164 = cppVar_177;
	}
	cppVar_151 = cppVar_164;
	}
	cppVar_138 = cppVar_151;
	}
	cppVar_125 = cppVar_138;
	}
	cppVar_112 = cppVar_125;
	}
	cppVar_99 = cppVar_112;
	}
	cppVar_86 = cppVar_99;
	}
	cppVar_73 = cppVar_86;
	}
	cppVar_62 = cppVar_73;
	}
	return cppVar_62;
}
