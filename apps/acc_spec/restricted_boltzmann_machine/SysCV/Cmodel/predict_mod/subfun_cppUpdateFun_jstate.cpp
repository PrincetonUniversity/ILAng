#include "common.hpp"
#include "model_predict_class.hpp"

BIT_VEC model_predict::cppUpdateFun_jstate(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_181;
	bool cppVar_182;
	BIT_VEC cppVar_183;
	BIT_VEC cppVar_185;
	bool cppVar_186;
	bool cppVar_188;
	BIT_VEC cppVar_189;
	bool cppVar_190;
	bool cppVar_191;
	bool cppVar_193;
	BIT_VEC cppVar_195;
	bool cppVar_196;
	BIT_VEC cppVar_197;
	BIT_VEC cppVar_198;
	BIT_VEC cppVar_194;
	BIT_VEC cppVar_192;
	bool cppVar_200;
	BIT_VEC cppVar_201;
	bool cppVar_202;
	bool cppVar_203;
	bool cppVar_205;
	BIT_VEC cppVar_206;
	BIT_VEC cppVar_207;
	BIT_VEC cppVar_204;
	bool cppVar_209;
	BIT_VEC cppVar_210;
	bool cppVar_211;
	bool cppVar_212;
	bool cppVar_214;
	BIT_VEC cppVar_215;
	BIT_VEC cppVar_213;
	bool cppVar_217;
	BIT_VEC cppVar_218;
	bool cppVar_219;
	bool cppVar_220;
	bool cppVar_222;
	BIT_VEC cppVar_223;
	BIT_VEC cppVar_221;
	bool cppVar_225;
	BIT_VEC cppVar_226;
	bool cppVar_227;
	bool cppVar_228;
	bool cppVar_230;
	BIT_VEC cppVar_231;
	BIT_VEC cppVar_229;
	BIT_VEC cppVar_224;
	BIT_VEC cppVar_216;
	BIT_VEC cppVar_208;
	BIT_VEC cppVar_199;
	BIT_VEC cppVar_187;
	BIT_VEC cppVar_233;
	bool cppVar_234;
	BIT_VEC cppVar_236;
	bool cppVar_237;
	BIT_VEC cppVar_238;
	BIT_VEC cppVar_239;
	BIT_VEC cppVar_235;
	BIT_VEC cppVar_241;
	bool cppVar_242;
	BIT_VEC cppVar_240;
	BIT_VEC cppVar_232;
	BIT_VEC cppVar_184;
	BIT_VEC cppVar_180;
	cppVar_182 = (predict_upc == 0);
	if (cppVar_182) {
	cppVar_180 = 0;
	} else {
	cppVar_186 = (predict_upc == 1);
	if (cppVar_186) {
	cppVar_188 = (predict_upc == 1);
	cppVar_190 = (per_v_pc == 0);
	cppVar_191 = cppVar_188 && cppVar_190;
	if (cppVar_191) {
	cppVar_193 = (predict_h_cnt == num_hidden);
	if (cppVar_193) {
	cppVar_196 = (jstate == 4);
	if (cppVar_196) {
	cppVar_194 = 0;
	} else {
	cppVar_198 = jstate + 1;
	cppVar_198 = (cppVar_198 & cppMask_un_16_);
	cppVar_194 = cppVar_198;
	}
	cppVar_192 = cppVar_194;
	} else {
	cppVar_192 = jstate;
	}
	cppVar_187 = cppVar_192;
	} else {
	cppVar_200 = (predict_upc == 1);
	cppVar_202 = (per_v_pc == 1);
	cppVar_203 = cppVar_200 && cppVar_202;
	if (cppVar_203) {
	cppVar_205 = (jstate == 4);
	if (cppVar_205) {
	cppVar_204 = 0;
	} else {
	cppVar_207 = jstate + 1;
	cppVar_207 = (cppVar_207 & cppMask_un_16_);
	cppVar_204 = cppVar_207;
	}
	cppVar_199 = cppVar_204;
	} else {
	cppVar_209 = (predict_upc == 1);
	cppVar_211 = (per_v_pc == 2);
	cppVar_212 = cppVar_209 && cppVar_211;
	if (cppVar_212) {
	cppVar_214 = (jstate == 4);
	if (cppVar_214) {
	cppVar_213 = 0;
	} else {
	cppVar_215 = jstate + 1;
	cppVar_215 = (cppVar_215 & cppMask_un_16_);
	cppVar_213 = cppVar_215;
	}
	cppVar_208 = cppVar_213;
	} else {
	cppVar_217 = (predict_upc == 1);
	cppVar_219 = (per_v_pc == 3);
	cppVar_220 = cppVar_217 && cppVar_219;
	if (cppVar_220) {
	cppVar_222 = (jstate == 4);
	if (cppVar_222) {
	cppVar_221 = 0;
	} else {
	cppVar_223 = jstate + 1;
	cppVar_223 = (cppVar_223 & cppMask_un_16_);
	cppVar_221 = cppVar_223;
	}
	cppVar_216 = cppVar_221;
	} else {
	cppVar_225 = (predict_upc == 1);
	cppVar_227 = (per_v_pc == 4);
	cppVar_228 = cppVar_225 && cppVar_227;
	if (cppVar_228) {
	cppVar_230 = (jstate == 4);
	if (cppVar_230) {
	cppVar_229 = 0;
	} else {
	cppVar_231 = jstate + 1;
	cppVar_231 = (cppVar_231 & cppMask_un_16_);
	cppVar_229 = cppVar_231;
	}
	cppVar_224 = cppVar_229;
	} else {
	cppVar_224 = jstate;
	}
	cppVar_216 = cppVar_224;
	}
	cppVar_208 = cppVar_216;
	}
	cppVar_199 = cppVar_208;
	}
	cppVar_187 = cppVar_199;
	}
	cppVar_184 = cppVar_187;
	} else {
	cppVar_234 = (predict_upc == 3);
	if (cppVar_234) {
	cppVar_237 = (jstate == 4);
	if (cppVar_237) {
	cppVar_235 = 0;
	} else {
	cppVar_239 = jstate + 1;
	cppVar_239 = (cppVar_239 & cppMask_un_16_);
	cppVar_235 = cppVar_239;
	}
	cppVar_232 = cppVar_235;
	} else {
	cppVar_242 = (predict_upc == 2);
	if (cppVar_242) {
	cppVar_240 = jstate;
	} else {
	cppVar_240 = jstate;
	}
	cppVar_232 = cppVar_240;
	}
	cppVar_184 = cppVar_232;
	}
	cppVar_180 = cppVar_184;
	}
	return cppVar_180;
}
