#include <map>
#include <stdint.h>
#include <boost/multiprecision/cpp_int.hpp>

#ifndef CPP_BITVEC_TYPE
#define CPP_BITVEC_TYPE
typedef boost::multiprecision::cpp_int BIT_VEC;
#endif

/****************************************************/
#ifndef TYPE_MEM_CLASS
#define TYPE_MEM_CLASS
class type_mem
{
private:
	std::map<BIT_VEC, BIT_VEC> _map;
	BIT_VEC _def_val;
public:
	type_mem(BIT_VEC def = 0)
		: _def_val(def)
	{
	}
	~type_mem() {}

	void setDef(BIT_VEC def)
	{
		_def_val = def;
	}

	void wr(BIT_VEC addr, BIT_VEC data)
	{
		if (data == _def_val) {
			_map.erase(addr);
		} else {
			_map[addr] = data;
		}
	}

	BIT_VEC rd(BIT_VEC addr)
	{
		std::map<BIT_VEC, BIT_VEC>::iterator it = _map.find(addr);
		if (it == _map.end()) {
			return _def_val;
		} else {
			return _map[addr];
		}
	}
};
#endif
/****************************************************/

BIT_VEC sha(BIT_VEC cppVar_11)
{
    return 0;
}

/****************************************************/
#ifndef MODEL_SHA_CLASS
#define MODEL_SHA_CLASS
class model_sha
{
public:
	model_sha() {
		cppMask_un_16_ = ((BIT_VEC)1 << 16) - 1;
		cppMask_un_24_ = ((BIT_VEC)1 << 24) - 1;
		cppMask_un_26_ = ((BIT_VEC)1 << 26) - 1;
		cppMask_un_29_ = ((BIT_VEC)1 << 29) - 1;
		cppMask_un_3_ = ((BIT_VEC)1 << 3) - 1;
		cppMask_un_512_ = ((BIT_VEC)1 << 512) - 1;
		cppMask_un_8_ = ((BIT_VEC)1 << 8) - 1;
	};
	~model_sha() {};
public:
	// State variables.
	type_mem XRAM;
	BIT_VEC dataout;
	BIT_VEC sha_bytes_read;
	BIT_VEC sha_hs_data;
	BIT_VEC sha_len;
	BIT_VEC sha_rd_data;
	BIT_VEC sha_rdaddr;
	BIT_VEC sha_state;
	BIT_VEC sha_wraddr;
public:
	// Public functions: fetch, decode, update, ...
	BIT_VEC cppUpdateFun_dataout(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_bytes_read(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_hs_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_rdaddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_state(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC cppUpdateFun_sha_wraddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_10(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_11(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_12(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_13(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_14(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_15(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_16(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_17(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_18(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_19(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_2(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_20(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_21(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_22(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_23(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_24(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_25(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_26(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_27(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_28(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_29(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_3(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_30(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_31(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_32(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_33(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_34(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_35(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_36(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_37(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_38(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_39(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_4(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_40(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_41(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_42(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_43(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_44(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_45(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_46(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_47(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_48(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_49(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_5(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_50(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_51(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_52(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_53(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_54(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_55(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_56(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_57(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_58(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_59(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_6(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_60(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_61(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_62(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_63(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_64(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_65(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_66(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_67(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_68(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_69(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_7(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_70(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_71(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_72(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_73(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_74(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_75(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_76(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_77(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_78(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_79(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_8(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_80(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_81(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_82(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_83(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_84(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_85(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_86(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_87(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_88(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_89(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_9(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_90(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_91(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_92(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_93(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_94(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_95(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_96(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	BIT_VEC fetch(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool fetchValid(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	void update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
private:
	// Bitvector masks.
	BIT_VEC cppMask_un_16_;
	BIT_VEC cppMask_un_24_;
	BIT_VEC cppMask_un_26_;
	BIT_VEC cppMask_un_29_;
	BIT_VEC cppMask_un_3_;
	BIT_VEC cppMask_un_512_;
	BIT_VEC cppMask_un_8_;

};
BIT_VEC model_sha::cppUpdateFun_dataout(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_28 = (sha_state == 4);
	bool cppVar_30 = (cmd == 1);
	bool cppVar_31 = cppVar_28 && cppVar_30;
	bool cppVar_33 = (cmdaddr == 65031);
	bool cppVar_34 = cppVar_31 && cppVar_33;
	bool cppVar_36 = (sha_state == 3);
	bool cppVar_38 = (cmd == 1);
	bool cppVar_39 = cppVar_36 && cppVar_38;
	bool cppVar_41 = (cmdaddr == 65031);
	bool cppVar_42 = cppVar_39 && cppVar_41;
	bool cppVar_44 = (sha_state == 2);
	bool cppVar_46 = (cmd == 1);
	bool cppVar_47 = cppVar_44 && cppVar_46;
	bool cppVar_49 = (cmdaddr == 65031);
	bool cppVar_50 = cppVar_47 && cppVar_49;
	bool cppVar_52 = (sha_state == 1);
	bool cppVar_54 = (cmd == 1);
	bool cppVar_55 = cppVar_52 && cppVar_54;
	bool cppVar_57 = (cmdaddr == 65031);
	bool cppVar_58 = cppVar_55 && cppVar_57;
	bool cppVar_60 = (sha_state == 0);
	bool cppVar_62 = (cmd == 1);
	bool cppVar_63 = cppVar_60 && cppVar_62;
	bool cppVar_65 = (cmdaddr == 65031);
	bool cppVar_66 = cppVar_63 && cppVar_65;
	bool cppVar_67 = cppVar_58 || cppVar_66;
	bool cppVar_68 = cppVar_50 || cppVar_67;
	bool cppVar_69 = cppVar_42 || cppVar_68;
	bool cppVar_70 = cppVar_34 || cppVar_69;
	BIT_VEC cppVar_71 = (sha_len >> 8) & cppMask_un_8_;
	bool cppVar_73 = (sha_state == 4);
	bool cppVar_75 = (cmd == 1);
	bool cppVar_76 = cppVar_73 && cppVar_75;
	bool cppVar_78 = (cmdaddr == 65030);
	bool cppVar_79 = cppVar_76 && cppVar_78;
	bool cppVar_81 = (sha_state == 3);
	bool cppVar_83 = (cmd == 1);
	bool cppVar_84 = cppVar_81 && cppVar_83;
	bool cppVar_86 = (cmdaddr == 65030);
	bool cppVar_87 = cppVar_84 && cppVar_86;
	bool cppVar_89 = (sha_state == 2);
	bool cppVar_91 = (cmd == 1);
	bool cppVar_92 = cppVar_89 && cppVar_91;
	bool cppVar_94 = (cmdaddr == 65030);
	bool cppVar_95 = cppVar_92 && cppVar_94;
	bool cppVar_97 = (sha_state == 1);
	bool cppVar_99 = (cmd == 1);
	bool cppVar_100 = cppVar_97 && cppVar_99;
	bool cppVar_102 = (cmdaddr == 65030);
	bool cppVar_103 = cppVar_100 && cppVar_102;
	bool cppVar_105 = (sha_state == 0);
	bool cppVar_107 = (cmd == 1);
	bool cppVar_108 = cppVar_105 && cppVar_107;
	bool cppVar_110 = (cmdaddr == 65030);
	bool cppVar_111 = cppVar_108 && cppVar_110;
	bool cppVar_112 = cppVar_103 || cppVar_111;
	bool cppVar_113 = cppVar_95 || cppVar_112;
	bool cppVar_114 = cppVar_87 || cppVar_113;
	bool cppVar_115 = cppVar_79 || cppVar_114;
	BIT_VEC cppVar_116 = (sha_len >> 0) & cppMask_un_8_;
	bool cppVar_118 = (sha_state == 4);
	bool cppVar_120 = (cmd == 1);
	bool cppVar_121 = cppVar_118 && cppVar_120;
	bool cppVar_123 = (cmdaddr == 65029);
	bool cppVar_124 = cppVar_121 && cppVar_123;
	bool cppVar_126 = (sha_state == 3);
	bool cppVar_128 = (cmd == 1);
	bool cppVar_129 = cppVar_126 && cppVar_128;
	bool cppVar_131 = (cmdaddr == 65029);
	bool cppVar_132 = cppVar_129 && cppVar_131;
	bool cppVar_134 = (sha_state == 2);
	bool cppVar_136 = (cmd == 1);
	bool cppVar_137 = cppVar_134 && cppVar_136;
	bool cppVar_139 = (cmdaddr == 65029);
	bool cppVar_140 = cppVar_137 && cppVar_139;
	bool cppVar_142 = (sha_state == 1);
	bool cppVar_144 = (cmd == 1);
	bool cppVar_145 = cppVar_142 && cppVar_144;
	bool cppVar_147 = (cmdaddr == 65029);
	bool cppVar_148 = cppVar_145 && cppVar_147;
	bool cppVar_150 = (sha_state == 0);
	bool cppVar_152 = (cmd == 1);
	bool cppVar_153 = cppVar_150 && cppVar_152;
	bool cppVar_155 = (cmdaddr == 65029);
	bool cppVar_156 = cppVar_153 && cppVar_155;
	bool cppVar_157 = cppVar_148 || cppVar_156;
	bool cppVar_158 = cppVar_140 || cppVar_157;
	bool cppVar_159 = cppVar_132 || cppVar_158;
	bool cppVar_160 = cppVar_124 || cppVar_159;
	BIT_VEC cppVar_161 = (sha_wraddr >> 8) & cppMask_un_8_;
	bool cppVar_163 = (sha_state == 4);
	bool cppVar_165 = (cmd == 1);
	bool cppVar_166 = cppVar_163 && cppVar_165;
	bool cppVar_168 = (cmdaddr == 65028);
	bool cppVar_169 = cppVar_166 && cppVar_168;
	bool cppVar_171 = (sha_state == 3);
	bool cppVar_173 = (cmd == 1);
	bool cppVar_174 = cppVar_171 && cppVar_173;
	bool cppVar_176 = (cmdaddr == 65028);
	bool cppVar_177 = cppVar_174 && cppVar_176;
	bool cppVar_179 = (sha_state == 2);
	bool cppVar_181 = (cmd == 1);
	bool cppVar_182 = cppVar_179 && cppVar_181;
	bool cppVar_184 = (cmdaddr == 65028);
	bool cppVar_185 = cppVar_182 && cppVar_184;
	bool cppVar_187 = (sha_state == 1);
	bool cppVar_189 = (cmd == 1);
	bool cppVar_190 = cppVar_187 && cppVar_189;
	bool cppVar_192 = (cmdaddr == 65028);
	bool cppVar_193 = cppVar_190 && cppVar_192;
	bool cppVar_195 = (sha_state == 0);
	bool cppVar_197 = (cmd == 1);
	bool cppVar_198 = cppVar_195 && cppVar_197;
	bool cppVar_200 = (cmdaddr == 65028);
	bool cppVar_201 = cppVar_198 && cppVar_200;
	bool cppVar_202 = cppVar_193 || cppVar_201;
	bool cppVar_203 = cppVar_185 || cppVar_202;
	bool cppVar_204 = cppVar_177 || cppVar_203;
	bool cppVar_205 = cppVar_169 || cppVar_204;
	BIT_VEC cppVar_206 = (sha_wraddr >> 0) & cppMask_un_8_;
	bool cppVar_208 = (sha_state == 4);
	bool cppVar_210 = (cmd == 1);
	bool cppVar_211 = cppVar_208 && cppVar_210;
	bool cppVar_213 = (cmdaddr == 65027);
	bool cppVar_214 = cppVar_211 && cppVar_213;
	bool cppVar_216 = (sha_state == 3);
	bool cppVar_218 = (cmd == 1);
	bool cppVar_219 = cppVar_216 && cppVar_218;
	bool cppVar_221 = (cmdaddr == 65027);
	bool cppVar_222 = cppVar_219 && cppVar_221;
	bool cppVar_224 = (sha_state == 2);
	bool cppVar_226 = (cmd == 1);
	bool cppVar_227 = cppVar_224 && cppVar_226;
	bool cppVar_229 = (cmdaddr == 65027);
	bool cppVar_230 = cppVar_227 && cppVar_229;
	bool cppVar_232 = (sha_state == 1);
	bool cppVar_234 = (cmd == 1);
	bool cppVar_235 = cppVar_232 && cppVar_234;
	bool cppVar_237 = (cmdaddr == 65027);
	bool cppVar_238 = cppVar_235 && cppVar_237;
	bool cppVar_240 = (sha_state == 0);
	bool cppVar_242 = (cmd == 1);
	bool cppVar_243 = cppVar_240 && cppVar_242;
	bool cppVar_245 = (cmdaddr == 65027);
	bool cppVar_246 = cppVar_243 && cppVar_245;
	bool cppVar_247 = cppVar_238 || cppVar_246;
	bool cppVar_248 = cppVar_230 || cppVar_247;
	bool cppVar_249 = cppVar_222 || cppVar_248;
	bool cppVar_250 = cppVar_214 || cppVar_249;
	BIT_VEC cppVar_251 = (sha_rdaddr >> 8) & cppMask_un_8_;
	bool cppVar_253 = (sha_state == 4);
	bool cppVar_255 = (cmd == 1);
	bool cppVar_256 = cppVar_253 && cppVar_255;
	bool cppVar_258 = (cmdaddr == 65026);
	bool cppVar_259 = cppVar_256 && cppVar_258;
	bool cppVar_261 = (sha_state == 3);
	bool cppVar_263 = (cmd == 1);
	bool cppVar_264 = cppVar_261 && cppVar_263;
	bool cppVar_266 = (cmdaddr == 65026);
	bool cppVar_267 = cppVar_264 && cppVar_266;
	bool cppVar_269 = (sha_state == 2);
	bool cppVar_271 = (cmd == 1);
	bool cppVar_272 = cppVar_269 && cppVar_271;
	bool cppVar_274 = (cmdaddr == 65026);
	bool cppVar_275 = cppVar_272 && cppVar_274;
	bool cppVar_277 = (sha_state == 1);
	bool cppVar_279 = (cmd == 1);
	bool cppVar_280 = cppVar_277 && cppVar_279;
	bool cppVar_282 = (cmdaddr == 65026);
	bool cppVar_283 = cppVar_280 && cppVar_282;
	bool cppVar_285 = (sha_state == 0);
	bool cppVar_287 = (cmd == 1);
	bool cppVar_288 = cppVar_285 && cppVar_287;
	bool cppVar_290 = (cmdaddr == 65026);
	bool cppVar_291 = cppVar_288 && cppVar_290;
	bool cppVar_292 = cppVar_283 || cppVar_291;
	bool cppVar_293 = cppVar_275 || cppVar_292;
	bool cppVar_294 = cppVar_267 || cppVar_293;
	bool cppVar_295 = cppVar_259 || cppVar_294;
	BIT_VEC cppVar_296 = (sha_rdaddr >> 0) & cppMask_un_8_;
	bool cppVar_298 = (sha_state != 0);
	bool cppVar_300 = (cmd != 1);
	bool cppVar_301 = cppVar_298 && cppVar_300;
	bool cppVar_303 = (sha_state == 0);
	bool cppVar_305 = (cmd != 1);
	bool cppVar_306 = cppVar_303 && cppVar_305;
	bool cppVar_308 = (cmd != 2);
	bool cppVar_309 = cppVar_306 && cppVar_308;
	bool cppVar_310 = cppVar_301 || cppVar_309;
	bool cppVar_312 = (sha_state == 4);
	bool cppVar_314 = (cmd == 1);
	bool cppVar_315 = cppVar_312 && cppVar_314;
	bool cppVar_317 = (cmdaddr == 65039);
	bool cppVar_318 = cppVar_315 && cppVar_317;
	bool cppVar_320 = (sha_state == 3);
	bool cppVar_322 = (cmd == 1);
	bool cppVar_323 = cppVar_320 && cppVar_322;
	bool cppVar_325 = (cmdaddr == 65039);
	bool cppVar_326 = cppVar_323 && cppVar_325;
	bool cppVar_328 = (sha_state == 2);
	bool cppVar_330 = (cmd == 1);
	bool cppVar_331 = cppVar_328 && cppVar_330;
	bool cppVar_333 = (cmdaddr == 65039);
	bool cppVar_334 = cppVar_331 && cppVar_333;
	bool cppVar_336 = (sha_state == 1);
	bool cppVar_338 = (cmd == 1);
	bool cppVar_339 = cppVar_336 && cppVar_338;
	bool cppVar_341 = (cmdaddr == 65039);
	bool cppVar_342 = cppVar_339 && cppVar_341;
	bool cppVar_344 = (sha_state == 4);
	bool cppVar_346 = (cmd == 1);
	bool cppVar_347 = cppVar_344 && cppVar_346;
	bool cppVar_349 = (cmdaddr == 65038);
	bool cppVar_350 = cppVar_347 && cppVar_349;
	bool cppVar_352 = (sha_state == 3);
	bool cppVar_354 = (cmd == 1);
	bool cppVar_355 = cppVar_352 && cppVar_354;
	bool cppVar_357 = (cmdaddr == 65038);
	bool cppVar_358 = cppVar_355 && cppVar_357;
	bool cppVar_360 = (sha_state == 2);
	bool cppVar_362 = (cmd == 1);
	bool cppVar_363 = cppVar_360 && cppVar_362;
	bool cppVar_365 = (cmdaddr == 65038);
	bool cppVar_366 = cppVar_363 && cppVar_365;
	bool cppVar_368 = (sha_state == 1);
	bool cppVar_370 = (cmd == 1);
	bool cppVar_371 = cppVar_368 && cppVar_370;
	bool cppVar_373 = (cmdaddr == 65038);
	bool cppVar_374 = cppVar_371 && cppVar_373;
	bool cppVar_376 = (sha_state == 4);
	bool cppVar_378 = (cmd == 1);
	bool cppVar_379 = cppVar_376 && cppVar_378;
	bool cppVar_381 = (cmdaddr == 65037);
	bool cppVar_382 = cppVar_379 && cppVar_381;
	bool cppVar_384 = (sha_state == 3);
	bool cppVar_386 = (cmd == 1);
	bool cppVar_387 = cppVar_384 && cppVar_386;
	bool cppVar_389 = (cmdaddr == 65037);
	bool cppVar_390 = cppVar_387 && cppVar_389;
	bool cppVar_392 = (sha_state == 2);
	bool cppVar_394 = (cmd == 1);
	bool cppVar_395 = cppVar_392 && cppVar_394;
	bool cppVar_397 = (cmdaddr == 65037);
	bool cppVar_398 = cppVar_395 && cppVar_397;
	bool cppVar_400 = (sha_state == 1);
	bool cppVar_402 = (cmd == 1);
	bool cppVar_403 = cppVar_400 && cppVar_402;
	bool cppVar_405 = (cmdaddr == 65037);
	bool cppVar_406 = cppVar_403 && cppVar_405;
	bool cppVar_408 = (sha_state == 4);
	bool cppVar_410 = (cmd == 1);
	bool cppVar_411 = cppVar_408 && cppVar_410;
	bool cppVar_413 = (cmdaddr == 65036);
	bool cppVar_414 = cppVar_411 && cppVar_413;
	bool cppVar_416 = (sha_state == 3);
	bool cppVar_418 = (cmd == 1);
	bool cppVar_419 = cppVar_416 && cppVar_418;
	bool cppVar_421 = (cmdaddr == 65036);
	bool cppVar_422 = cppVar_419 && cppVar_421;
	bool cppVar_424 = (sha_state == 2);
	bool cppVar_426 = (cmd == 1);
	bool cppVar_427 = cppVar_424 && cppVar_426;
	bool cppVar_429 = (cmdaddr == 65036);
	bool cppVar_430 = cppVar_427 && cppVar_429;
	bool cppVar_432 = (sha_state == 1);
	bool cppVar_434 = (cmd == 1);
	bool cppVar_435 = cppVar_432 && cppVar_434;
	bool cppVar_437 = (cmdaddr == 65036);
	bool cppVar_438 = cppVar_435 && cppVar_437;
	bool cppVar_440 = (sha_state == 4);
	bool cppVar_442 = (cmd == 1);
	bool cppVar_443 = cppVar_440 && cppVar_442;
	bool cppVar_445 = (cmdaddr == 65035);
	bool cppVar_446 = cppVar_443 && cppVar_445;
	bool cppVar_448 = (sha_state == 3);
	bool cppVar_450 = (cmd == 1);
	bool cppVar_451 = cppVar_448 && cppVar_450;
	bool cppVar_453 = (cmdaddr == 65035);
	bool cppVar_454 = cppVar_451 && cppVar_453;
	bool cppVar_456 = (sha_state == 2);
	bool cppVar_458 = (cmd == 1);
	bool cppVar_459 = cppVar_456 && cppVar_458;
	bool cppVar_461 = (cmdaddr == 65035);
	bool cppVar_462 = cppVar_459 && cppVar_461;
	bool cppVar_464 = (sha_state == 1);
	bool cppVar_466 = (cmd == 1);
	bool cppVar_467 = cppVar_464 && cppVar_466;
	bool cppVar_469 = (cmdaddr == 65035);
	bool cppVar_470 = cppVar_467 && cppVar_469;
	bool cppVar_472 = (sha_state == 4);
	bool cppVar_474 = (cmd == 1);
	bool cppVar_475 = cppVar_472 && cppVar_474;
	bool cppVar_477 = (cmdaddr == 65034);
	bool cppVar_478 = cppVar_475 && cppVar_477;
	bool cppVar_480 = (sha_state == 3);
	bool cppVar_482 = (cmd == 1);
	bool cppVar_483 = cppVar_480 && cppVar_482;
	bool cppVar_485 = (cmdaddr == 65034);
	bool cppVar_486 = cppVar_483 && cppVar_485;
	bool cppVar_488 = (sha_state == 2);
	bool cppVar_490 = (cmd == 1);
	bool cppVar_491 = cppVar_488 && cppVar_490;
	bool cppVar_493 = (cmdaddr == 65034);
	bool cppVar_494 = cppVar_491 && cppVar_493;
	bool cppVar_496 = (sha_state == 1);
	bool cppVar_498 = (cmd == 1);
	bool cppVar_499 = cppVar_496 && cppVar_498;
	bool cppVar_501 = (cmdaddr == 65034);
	bool cppVar_502 = cppVar_499 && cppVar_501;
	bool cppVar_504 = (sha_state == 4);
	bool cppVar_506 = (cmd == 1);
	bool cppVar_507 = cppVar_504 && cppVar_506;
	bool cppVar_509 = (cmdaddr == 65033);
	bool cppVar_510 = cppVar_507 && cppVar_509;
	bool cppVar_512 = (sha_state == 3);
	bool cppVar_514 = (cmd == 1);
	bool cppVar_515 = cppVar_512 && cppVar_514;
	bool cppVar_517 = (cmdaddr == 65033);
	bool cppVar_518 = cppVar_515 && cppVar_517;
	bool cppVar_520 = (sha_state == 2);
	bool cppVar_522 = (cmd == 1);
	bool cppVar_523 = cppVar_520 && cppVar_522;
	bool cppVar_525 = (cmdaddr == 65033);
	bool cppVar_526 = cppVar_523 && cppVar_525;
	bool cppVar_528 = (sha_state == 1);
	bool cppVar_530 = (cmd == 1);
	bool cppVar_531 = cppVar_528 && cppVar_530;
	bool cppVar_533 = (cmdaddr == 65033);
	bool cppVar_534 = cppVar_531 && cppVar_533;
	bool cppVar_536 = (sha_state == 4);
	bool cppVar_538 = (cmd == 1);
	bool cppVar_539 = cppVar_536 && cppVar_538;
	bool cppVar_541 = (cmdaddr == 65032);
	bool cppVar_542 = cppVar_539 && cppVar_541;
	bool cppVar_544 = (sha_state == 3);
	bool cppVar_546 = (cmd == 1);
	bool cppVar_547 = cppVar_544 && cppVar_546;
	bool cppVar_549 = (cmdaddr == 65032);
	bool cppVar_550 = cppVar_547 && cppVar_549;
	bool cppVar_552 = (sha_state == 2);
	bool cppVar_554 = (cmd == 1);
	bool cppVar_555 = cppVar_552 && cppVar_554;
	bool cppVar_557 = (cmdaddr == 65032);
	bool cppVar_558 = cppVar_555 && cppVar_557;
	bool cppVar_560 = (sha_state == 1);
	bool cppVar_562 = (cmd == 1);
	bool cppVar_563 = cppVar_560 && cppVar_562;
	bool cppVar_565 = (cmdaddr == 65032);
	bool cppVar_566 = cppVar_563 && cppVar_565;
	bool cppVar_568 = (sha_state == 4);
	bool cppVar_570 = (cmd == 1);
	bool cppVar_571 = cppVar_568 && cppVar_570;
	bool cppVar_573 = (cmdaddr == 65024);
	bool cppVar_574 = cppVar_571 && cppVar_573;
	bool cppVar_576 = (sha_state == 3);
	bool cppVar_578 = (cmd == 1);
	bool cppVar_579 = cppVar_576 && cppVar_578;
	bool cppVar_581 = (cmdaddr == 65024);
	bool cppVar_582 = cppVar_579 && cppVar_581;
	bool cppVar_584 = (sha_state == 2);
	bool cppVar_586 = (cmd == 1);
	bool cppVar_587 = cppVar_584 && cppVar_586;
	bool cppVar_589 = (cmdaddr == 65024);
	bool cppVar_590 = cppVar_587 && cppVar_589;
	bool cppVar_592 = (sha_state == 1);
	bool cppVar_594 = (cmd == 1);
	bool cppVar_595 = cppVar_592 && cppVar_594;
	bool cppVar_597 = (cmdaddr == 65024);
	bool cppVar_598 = cppVar_595 && cppVar_597;
	bool cppVar_599 = cppVar_590 || cppVar_598;
	bool cppVar_600 = cppVar_582 || cppVar_599;
	bool cppVar_601 = cppVar_574 || cppVar_600;
	bool cppVar_602 = cppVar_566 || cppVar_601;
	bool cppVar_603 = cppVar_558 || cppVar_602;
	bool cppVar_604 = cppVar_550 || cppVar_603;
	bool cppVar_605 = cppVar_542 || cppVar_604;
	bool cppVar_606 = cppVar_534 || cppVar_605;
	bool cppVar_607 = cppVar_526 || cppVar_606;
	bool cppVar_608 = cppVar_518 || cppVar_607;
	bool cppVar_609 = cppVar_510 || cppVar_608;
	bool cppVar_610 = cppVar_502 || cppVar_609;
	bool cppVar_611 = cppVar_494 || cppVar_610;
	bool cppVar_612 = cppVar_486 || cppVar_611;
	bool cppVar_613 = cppVar_478 || cppVar_612;
	bool cppVar_614 = cppVar_470 || cppVar_613;
	bool cppVar_615 = cppVar_462 || cppVar_614;
	bool cppVar_616 = cppVar_454 || cppVar_615;
	bool cppVar_617 = cppVar_446 || cppVar_616;
	bool cppVar_618 = cppVar_438 || cppVar_617;
	bool cppVar_619 = cppVar_430 || cppVar_618;
	bool cppVar_620 = cppVar_422 || cppVar_619;
	bool cppVar_621 = cppVar_414 || cppVar_620;
	bool cppVar_622 = cppVar_406 || cppVar_621;
	bool cppVar_623 = cppVar_398 || cppVar_622;
	bool cppVar_624 = cppVar_390 || cppVar_623;
	bool cppVar_625 = cppVar_382 || cppVar_624;
	bool cppVar_626 = cppVar_374 || cppVar_625;
	bool cppVar_627 = cppVar_366 || cppVar_626;
	bool cppVar_628 = cppVar_358 || cppVar_627;
	bool cppVar_629 = cppVar_350 || cppVar_628;
	bool cppVar_630 = cppVar_342 || cppVar_629;
	bool cppVar_631 = cppVar_334 || cppVar_630;
	bool cppVar_632 = cppVar_326 || cppVar_631;
	bool cppVar_633 = cppVar_318 || cppVar_632;
	bool cppVar_634 = cppVar_310 || cppVar_633;
	bool cppVar_637 = (sha_state == 0);
	bool cppVar_639 = (cmd == 2);
	bool cppVar_640 = cppVar_637 && cppVar_639;
	bool cppVar_642 = (cmdaddr == 65039);
	bool cppVar_643 = cppVar_640 && cppVar_642;
	bool cppVar_645 = (sha_state == 0);
	bool cppVar_647 = (cmd == 2);
	bool cppVar_648 = cppVar_645 && cppVar_647;
	bool cppVar_650 = (cmdaddr == 65038);
	bool cppVar_651 = cppVar_648 && cppVar_650;
	bool cppVar_653 = (sha_state == 0);
	bool cppVar_655 = (cmd == 2);
	bool cppVar_656 = cppVar_653 && cppVar_655;
	bool cppVar_658 = (cmdaddr == 65037);
	bool cppVar_659 = cppVar_656 && cppVar_658;
	bool cppVar_661 = (sha_state == 0);
	bool cppVar_663 = (cmd == 2);
	bool cppVar_664 = cppVar_661 && cppVar_663;
	bool cppVar_666 = (cmdaddr == 65036);
	bool cppVar_667 = cppVar_664 && cppVar_666;
	bool cppVar_669 = (sha_state == 0);
	bool cppVar_671 = (cmd == 2);
	bool cppVar_672 = cppVar_669 && cppVar_671;
	bool cppVar_674 = (cmdaddr == 65035);
	bool cppVar_675 = cppVar_672 && cppVar_674;
	bool cppVar_677 = (sha_state == 0);
	bool cppVar_679 = (cmd == 2);
	bool cppVar_680 = cppVar_677 && cppVar_679;
	bool cppVar_682 = (cmdaddr == 65034);
	bool cppVar_683 = cppVar_680 && cppVar_682;
	bool cppVar_685 = (sha_state == 0);
	bool cppVar_687 = (cmd == 2);
	bool cppVar_688 = cppVar_685 && cppVar_687;
	bool cppVar_690 = (cmdaddr == 65033);
	bool cppVar_691 = cppVar_688 && cppVar_690;
	bool cppVar_693 = (sha_state == 0);
	bool cppVar_695 = (cmd == 2);
	bool cppVar_696 = cppVar_693 && cppVar_695;
	bool cppVar_698 = (cmdaddr == 65032);
	bool cppVar_699 = cppVar_696 && cppVar_698;
	bool cppVar_701 = (sha_state == 0);
	bool cppVar_703 = (cmd == 2);
	bool cppVar_704 = cppVar_701 && cppVar_703;
	bool cppVar_706 = (cmdaddr == 65031);
	bool cppVar_707 = cppVar_704 && cppVar_706;
	bool cppVar_709 = (sha_state == 0);
	bool cppVar_711 = (cmd == 2);
	bool cppVar_712 = cppVar_709 && cppVar_711;
	bool cppVar_714 = (cmdaddr == 65030);
	bool cppVar_715 = cppVar_712 && cppVar_714;
	bool cppVar_717 = (sha_state == 0);
	bool cppVar_719 = (cmd == 2);
	bool cppVar_720 = cppVar_717 && cppVar_719;
	bool cppVar_722 = (cmdaddr == 65029);
	bool cppVar_723 = cppVar_720 && cppVar_722;
	bool cppVar_725 = (sha_state == 0);
	bool cppVar_727 = (cmd == 2);
	bool cppVar_728 = cppVar_725 && cppVar_727;
	bool cppVar_730 = (cmdaddr == 65028);
	bool cppVar_731 = cppVar_728 && cppVar_730;
	bool cppVar_733 = (sha_state == 0);
	bool cppVar_735 = (cmd == 2);
	bool cppVar_736 = cppVar_733 && cppVar_735;
	bool cppVar_738 = (cmdaddr == 65027);
	bool cppVar_739 = cppVar_736 && cppVar_738;
	bool cppVar_741 = (sha_state == 0);
	bool cppVar_743 = (cmd == 2);
	bool cppVar_744 = cppVar_741 && cppVar_743;
	bool cppVar_746 = (cmdaddr == 65026);
	bool cppVar_747 = cppVar_744 && cppVar_746;
	bool cppVar_749 = (sha_state == 0);
	bool cppVar_751 = (cmd == 2);
	bool cppVar_752 = cppVar_749 && cppVar_751;
	bool cppVar_754 = (cmdaddr == 65025);
	bool cppVar_755 = cppVar_752 && cppVar_754;
	bool cppVar_757 = (sha_state == 0);
	bool cppVar_759 = (cmd == 2);
	bool cppVar_760 = cppVar_757 && cppVar_759;
	bool cppVar_762 = (cmdaddr == 65024);
	bool cppVar_763 = cppVar_760 && cppVar_762;
	bool cppVar_765 = (sha_state == 0);
	bool cppVar_767 = (cmd == 1);
	bool cppVar_768 = cppVar_765 && cppVar_767;
	bool cppVar_770 = (cmdaddr == 65039);
	bool cppVar_771 = cppVar_768 && cppVar_770;
	bool cppVar_773 = (sha_state == 0);
	bool cppVar_775 = (cmd == 1);
	bool cppVar_776 = cppVar_773 && cppVar_775;
	bool cppVar_778 = (cmdaddr == 65038);
	bool cppVar_779 = cppVar_776 && cppVar_778;
	bool cppVar_781 = (sha_state == 0);
	bool cppVar_783 = (cmd == 1);
	bool cppVar_784 = cppVar_781 && cppVar_783;
	bool cppVar_786 = (cmdaddr == 65037);
	bool cppVar_787 = cppVar_784 && cppVar_786;
	bool cppVar_789 = (sha_state == 0);
	bool cppVar_791 = (cmd == 1);
	bool cppVar_792 = cppVar_789 && cppVar_791;
	bool cppVar_794 = (cmdaddr == 65036);
	bool cppVar_795 = cppVar_792 && cppVar_794;
	bool cppVar_797 = (sha_state == 0);
	bool cppVar_799 = (cmd == 1);
	bool cppVar_800 = cppVar_797 && cppVar_799;
	bool cppVar_802 = (cmdaddr == 65035);
	bool cppVar_803 = cppVar_800 && cppVar_802;
	bool cppVar_805 = (sha_state == 0);
	bool cppVar_807 = (cmd == 1);
	bool cppVar_808 = cppVar_805 && cppVar_807;
	bool cppVar_810 = (cmdaddr == 65034);
	bool cppVar_811 = cppVar_808 && cppVar_810;
	bool cppVar_813 = (sha_state == 0);
	bool cppVar_815 = (cmd == 1);
	bool cppVar_816 = cppVar_813 && cppVar_815;
	bool cppVar_818 = (cmdaddr == 65033);
	bool cppVar_819 = cppVar_816 && cppVar_818;
	bool cppVar_821 = (sha_state == 0);
	bool cppVar_823 = (cmd == 1);
	bool cppVar_824 = cppVar_821 && cppVar_823;
	bool cppVar_826 = (cmdaddr == 65032);
	bool cppVar_827 = cppVar_824 && cppVar_826;
	bool cppVar_829 = (sha_state == 4);
	bool cppVar_831 = (cmd == 1);
	bool cppVar_832 = cppVar_829 && cppVar_831;
	bool cppVar_834 = (cmdaddr == 65025);
	bool cppVar_835 = cppVar_832 && cppVar_834;
	bool cppVar_837 = (sha_state == 3);
	bool cppVar_839 = (cmd == 1);
	bool cppVar_840 = cppVar_837 && cppVar_839;
	bool cppVar_842 = (cmdaddr == 65025);
	bool cppVar_843 = cppVar_840 && cppVar_842;
	bool cppVar_845 = (sha_state == 2);
	bool cppVar_847 = (cmd == 1);
	bool cppVar_848 = cppVar_845 && cppVar_847;
	bool cppVar_850 = (cmdaddr == 65025);
	bool cppVar_851 = cppVar_848 && cppVar_850;
	bool cppVar_853 = (sha_state == 1);
	bool cppVar_855 = (cmd == 1);
	bool cppVar_856 = cppVar_853 && cppVar_855;
	bool cppVar_858 = (cmdaddr == 65025);
	bool cppVar_859 = cppVar_856 && cppVar_858;
	bool cppVar_861 = (sha_state == 0);
	bool cppVar_863 = (cmd == 1);
	bool cppVar_864 = cppVar_861 && cppVar_863;
	bool cppVar_866 = (cmdaddr == 65025);
	bool cppVar_867 = cppVar_864 && cppVar_866;
	bool cppVar_869 = (sha_state == 0);
	bool cppVar_871 = (cmd == 1);
	bool cppVar_872 = cppVar_869 && cppVar_871;
	bool cppVar_874 = (cmdaddr == 65024);
	bool cppVar_875 = cppVar_872 && cppVar_874;
	bool cppVar_876 = cppVar_867 || cppVar_875;
	bool cppVar_877 = cppVar_859 || cppVar_876;
	bool cppVar_878 = cppVar_851 || cppVar_877;
	bool cppVar_879 = cppVar_843 || cppVar_878;
	bool cppVar_880 = cppVar_835 || cppVar_879;
	bool cppVar_881 = cppVar_827 || cppVar_880;
	bool cppVar_882 = cppVar_819 || cppVar_881;
	bool cppVar_883 = cppVar_811 || cppVar_882;
	bool cppVar_884 = cppVar_803 || cppVar_883;
	bool cppVar_885 = cppVar_795 || cppVar_884;
	bool cppVar_886 = cppVar_787 || cppVar_885;
	bool cppVar_887 = cppVar_779 || cppVar_886;
	bool cppVar_888 = cppVar_771 || cppVar_887;
	bool cppVar_889 = cppVar_763 || cppVar_888;
	bool cppVar_890 = cppVar_755 || cppVar_889;
	bool cppVar_891 = cppVar_747 || cppVar_890;
	bool cppVar_892 = cppVar_739 || cppVar_891;
	bool cppVar_893 = cppVar_731 || cppVar_892;
	bool cppVar_894 = cppVar_723 || cppVar_893;
	bool cppVar_895 = cppVar_715 || cppVar_894;
	bool cppVar_896 = cppVar_707 || cppVar_895;
	bool cppVar_897 = cppVar_699 || cppVar_896;
	bool cppVar_898 = cppVar_691 || cppVar_897;
	bool cppVar_899 = cppVar_683 || cppVar_898;
	bool cppVar_900 = cppVar_675 || cppVar_899;
	bool cppVar_901 = cppVar_667 || cppVar_900;
	bool cppVar_902 = cppVar_659 || cppVar_901;
	bool cppVar_903 = cppVar_651 || cppVar_902;
	bool cppVar_904 = cppVar_643 || cppVar_903;
	BIT_VEC cppVar_905 = (sha_state & cppMask_un_3_);
	BIT_VEC cppVar_906 = (cppVar_904) ? cppVar_905 : dataout;
	BIT_VEC cppVar_907 = (cppVar_634) ? 0 : cppVar_906;
	BIT_VEC cppVar_908 = (cppVar_295) ? cppVar_296 : cppVar_907;
	BIT_VEC cppVar_909 = (cppVar_250) ? cppVar_251 : cppVar_908;
	BIT_VEC cppVar_910 = (cppVar_205) ? cppVar_206 : cppVar_909;
	BIT_VEC cppVar_911 = (cppVar_160) ? cppVar_161 : cppVar_910;
	BIT_VEC cppVar_912 = (cppVar_115) ? cppVar_116 : cppVar_911;
	BIT_VEC cppVar_913 = (cppVar_70) ? cppVar_71 : cppVar_912;
	return cppVar_913;
}
BIT_VEC model_sha::cppUpdateFun_sha_bytes_read(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1048 = (sha_state != 0);
	bool cppVar_1050 = (sha_state == 1);
	BIT_VEC cppVar_1052 = sha_bytes_read + 64;
	cppVar_1052 = (cppVar_1052 & cppMask_un_16_);
	BIT_VEC cppVar_1053 = (cppVar_1050) ? cppVar_1052 : sha_bytes_read;
	BIT_VEC cppVar_1054 = (cppVar_1048) ? cppVar_1053 : sha_bytes_read;
	return cppVar_1054;
}
BIT_VEC model_sha::cppUpdateFun_sha_hs_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1057 = (sha_state != 0);
	bool cppVar_1059 = (sha_state == 3);
	BIT_VEC cppVar_1060 = sha(sha_rd_data);
	BIT_VEC cppVar_1061 = (cppVar_1059) ? cppVar_1060 : sha_hs_data;
	BIT_VEC cppVar_1062 = (cppVar_1057) ? cppVar_1061 : sha_hs_data;
	return cppVar_1062;
}
BIT_VEC model_sha::cppUpdateFun_sha_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_916 = (sha_state == 0);
	bool cppVar_918 = (cmd == 2);
	bool cppVar_919 = cppVar_916 && cppVar_918;
	bool cppVar_921 = (cmdaddr == 65031);
	bool cppVar_922 = cppVar_919 && cppVar_921;
	BIT_VEC cppVar_923 = (sha_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_924 = (cmddata << 8) | cppVar_923;
	cppVar_924 = (cppVar_924 & cppMask_un_16_);
	bool cppVar_926 = (sha_state == 0);
	bool cppVar_928 = (cmd == 2);
	bool cppVar_929 = cppVar_926 && cppVar_928;
	bool cppVar_931 = (cmdaddr == 65030);
	bool cppVar_932 = cppVar_929 && cppVar_931;
	BIT_VEC cppVar_933 = (sha_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_934 = (cppVar_933 << 8) | cmddata;
	cppVar_934 = (cppVar_934 & cppMask_un_16_);
	BIT_VEC cppVar_935 = (cppVar_932) ? cppVar_934 : sha_len;
	BIT_VEC cppVar_936 = (cppVar_922) ? cppVar_924 : cppVar_935;
	return cppVar_936;
}
BIT_VEC model_sha::cppUpdateFun_sha_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1065 = (sha_state != 0);
	bool cppVar_1067 = (sha_state == 1);
	BIT_VEC cppVar_1068 = sha_rdaddr + sha_bytes_read;
	cppVar_1068 = (cppVar_1068 & cppMask_un_16_);
	BIT_VEC cppVar_1069 = (XRAM.rd(cppVar_1068) & cppMask_un_8_);
	for (int cppVar_1070 = 1; cppVar_1070 < 64; cppVar_1070++) {
		cppVar_1069 = (cppVar_1069 << 8) | (XRAM.rd(cppVar_1068 + cppVar_1070) & cppMask_un_8_);
	}
	cppVar_1069 = (cppVar_1069 & cppMask_un_512_);
	BIT_VEC cppVar_1071 = (cppVar_1067) ? cppVar_1069 : sha_rd_data;
	BIT_VEC cppVar_1072 = (cppVar_1065) ? cppVar_1071 : sha_rd_data;
	return cppVar_1072;
}
BIT_VEC model_sha::cppUpdateFun_sha_rdaddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_939 = (sha_state == 0);
	bool cppVar_941 = (cmd == 2);
	bool cppVar_942 = cppVar_939 && cppVar_941;
	bool cppVar_944 = (cmdaddr == 65027);
	bool cppVar_945 = cppVar_942 && cppVar_944;
	BIT_VEC cppVar_946 = (sha_rdaddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_947 = (cmddata << 8) | cppVar_946;
	cppVar_947 = (cppVar_947 & cppMask_un_16_);
	bool cppVar_949 = (sha_state == 0);
	bool cppVar_951 = (cmd == 2);
	bool cppVar_952 = cppVar_949 && cppVar_951;
	bool cppVar_954 = (cmdaddr == 65026);
	bool cppVar_955 = cppVar_952 && cppVar_954;
	BIT_VEC cppVar_956 = (sha_rdaddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_957 = (cppVar_956 << 8) | cmddata;
	cppVar_957 = (cppVar_957 & cppMask_un_16_);
	BIT_VEC cppVar_958 = (cppVar_955) ? cppVar_957 : sha_rdaddr;
	BIT_VEC cppVar_959 = (cppVar_945) ? cppVar_947 : cppVar_958;
	return cppVar_959;
}
BIT_VEC model_sha::cppUpdateFun_sha_state(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_962 = (sha_state != 0);
	bool cppVar_964 = (sha_state == 4);
	bool cppVar_967 = (sha_state == 3);
	bool cppVar_968 = sha_bytes_read < sha_len;
	BIT_VEC cppVar_971 = (cppVar_968) ? 1 : 4;
	bool cppVar_973 = (sha_state == 2);
	bool cppVar_976 = (sha_state == 1);
	BIT_VEC cppVar_978 = (cppVar_976) ? 2 : sha_state;
	BIT_VEC cppVar_979 = (cppVar_973) ? 3 : cppVar_978;
	BIT_VEC cppVar_980 = (cppVar_967) ? cppVar_971 : cppVar_979;
	BIT_VEC cppVar_981 = (cppVar_964) ? 0 : cppVar_980;
	bool cppVar_983 = (sha_state == 0);
	bool cppVar_985 = (cmd == 2);
	bool cppVar_986 = cppVar_983 && cppVar_985;
	bool cppVar_988 = (cmdaddr == 65024);
	bool cppVar_989 = cppVar_986 && cppVar_988;
	bool cppVar_991 = (sha_state == 1);
	bool cppVar_993 = (cmd == 1);
	bool cppVar_994 = cppVar_991 && cppVar_993;
	bool cppVar_996 = (cmdaddr == 65027);
	bool cppVar_997 = cppVar_994 && cppVar_996;
	bool cppVar_999 = (sha_state == 1);
	bool cppVar_1001 = (cmd == 1);
	bool cppVar_1002 = cppVar_999 && cppVar_1001;
	bool cppVar_1004 = (cmdaddr == 65026);
	bool cppVar_1005 = cppVar_1002 && cppVar_1004;
	bool cppVar_1006 = cppVar_997 || cppVar_1005;
	bool cppVar_1007 = cppVar_989 || cppVar_1006;
	bool cppVar_1009 = (cmddata == 1);
	BIT_VEC cppVar_1011 = (cppVar_1009) ? 1 : sha_state;
	BIT_VEC cppVar_1012 = (cppVar_1007) ? cppVar_1011 : sha_state;
	BIT_VEC cppVar_1013 = (cppVar_962) ? cppVar_981 : cppVar_1012;
	return cppVar_1013;
}
BIT_VEC model_sha::cppUpdateFun_sha_wraddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1016 = (sha_state == 0);
	bool cppVar_1018 = (cmd == 2);
	bool cppVar_1019 = cppVar_1016 && cppVar_1018;
	bool cppVar_1021 = (cmdaddr == 65029);
	bool cppVar_1022 = cppVar_1019 && cppVar_1021;
	BIT_VEC cppVar_1023 = (sha_wraddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_1024 = (cmddata << 8) | cppVar_1023;
	cppVar_1024 = (cppVar_1024 & cppMask_un_16_);
	bool cppVar_1026 = (sha_state == 0);
	bool cppVar_1028 = (cmd == 2);
	bool cppVar_1029 = cppVar_1026 && cppVar_1028;
	bool cppVar_1031 = (cmdaddr == 65028);
	bool cppVar_1032 = cppVar_1029 && cppVar_1031;
	BIT_VEC cppVar_1033 = (sha_wraddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_1034 = (cppVar_1033 << 8) | cmddata;
	cppVar_1034 = (cppVar_1034 & cppMask_un_16_);
	BIT_VEC cppVar_1035 = (cppVar_1032) ? cppVar_1034 : sha_wraddr;
	BIT_VEC cppVar_1036 = (cppVar_1022) ? cppVar_1024 : cppVar_1035;
	return cppVar_1036;
}
bool model_sha::decode_0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1083 = (sha_state == 0);
	bool cppVar_1085 = (cmd == 1);
	bool cppVar_1086 = cppVar_1083 && cppVar_1085;
	bool cppVar_1088 = (cmdaddr == 65024);
	bool cppVar_1089 = cppVar_1086 && cppVar_1088;
	return cppVar_1089;
}
bool model_sha::decode_1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1091 = (sha_state == 1);
	bool cppVar_1093 = (cmd == 1);
	bool cppVar_1094 = cppVar_1091 && cppVar_1093;
	bool cppVar_1096 = (cmdaddr == 65024);
	bool cppVar_1097 = cppVar_1094 && cppVar_1096;
	return cppVar_1097;
}
bool model_sha::decode_10(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1163 = (sha_state == 0);
	bool cppVar_1165 = (cmd == 1);
	bool cppVar_1166 = cppVar_1163 && cppVar_1165;
	bool cppVar_1168 = (cmdaddr == 65026);
	bool cppVar_1169 = cppVar_1166 && cppVar_1168;
	return cppVar_1169;
}
bool model_sha::decode_11(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1171 = (sha_state == 1);
	bool cppVar_1173 = (cmd == 1);
	bool cppVar_1174 = cppVar_1171 && cppVar_1173;
	bool cppVar_1176 = (cmdaddr == 65026);
	bool cppVar_1177 = cppVar_1174 && cppVar_1176;
	return cppVar_1177;
}
bool model_sha::decode_12(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1179 = (sha_state == 2);
	bool cppVar_1181 = (cmd == 1);
	bool cppVar_1182 = cppVar_1179 && cppVar_1181;
	bool cppVar_1184 = (cmdaddr == 65026);
	bool cppVar_1185 = cppVar_1182 && cppVar_1184;
	return cppVar_1185;
}
bool model_sha::decode_13(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1187 = (sha_state == 3);
	bool cppVar_1189 = (cmd == 1);
	bool cppVar_1190 = cppVar_1187 && cppVar_1189;
	bool cppVar_1192 = (cmdaddr == 65026);
	bool cppVar_1193 = cppVar_1190 && cppVar_1192;
	return cppVar_1193;
}
bool model_sha::decode_14(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1195 = (sha_state == 4);
	bool cppVar_1197 = (cmd == 1);
	bool cppVar_1198 = cppVar_1195 && cppVar_1197;
	bool cppVar_1200 = (cmdaddr == 65026);
	bool cppVar_1201 = cppVar_1198 && cppVar_1200;
	return cppVar_1201;
}
bool model_sha::decode_15(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1203 = (sha_state == 0);
	bool cppVar_1205 = (cmd == 1);
	bool cppVar_1206 = cppVar_1203 && cppVar_1205;
	bool cppVar_1208 = (cmdaddr == 65027);
	bool cppVar_1209 = cppVar_1206 && cppVar_1208;
	return cppVar_1209;
}
bool model_sha::decode_16(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1211 = (sha_state == 1);
	bool cppVar_1213 = (cmd == 1);
	bool cppVar_1214 = cppVar_1211 && cppVar_1213;
	bool cppVar_1216 = (cmdaddr == 65027);
	bool cppVar_1217 = cppVar_1214 && cppVar_1216;
	return cppVar_1217;
}
bool model_sha::decode_17(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1219 = (sha_state == 2);
	bool cppVar_1221 = (cmd == 1);
	bool cppVar_1222 = cppVar_1219 && cppVar_1221;
	bool cppVar_1224 = (cmdaddr == 65027);
	bool cppVar_1225 = cppVar_1222 && cppVar_1224;
	return cppVar_1225;
}
bool model_sha::decode_18(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1227 = (sha_state == 3);
	bool cppVar_1229 = (cmd == 1);
	bool cppVar_1230 = cppVar_1227 && cppVar_1229;
	bool cppVar_1232 = (cmdaddr == 65027);
	bool cppVar_1233 = cppVar_1230 && cppVar_1232;
	return cppVar_1233;
}
bool model_sha::decode_19(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1235 = (sha_state == 4);
	bool cppVar_1237 = (cmd == 1);
	bool cppVar_1238 = cppVar_1235 && cppVar_1237;
	bool cppVar_1240 = (cmdaddr == 65027);
	bool cppVar_1241 = cppVar_1238 && cppVar_1240;
	return cppVar_1241;
}
bool model_sha::decode_2(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1099 = (sha_state == 2);
	bool cppVar_1101 = (cmd == 1);
	bool cppVar_1102 = cppVar_1099 && cppVar_1101;
	bool cppVar_1104 = (cmdaddr == 65024);
	bool cppVar_1105 = cppVar_1102 && cppVar_1104;
	return cppVar_1105;
}
bool model_sha::decode_20(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1243 = (sha_state == 0);
	bool cppVar_1245 = (cmd == 1);
	bool cppVar_1246 = cppVar_1243 && cppVar_1245;
	bool cppVar_1248 = (cmdaddr == 65028);
	bool cppVar_1249 = cppVar_1246 && cppVar_1248;
	return cppVar_1249;
}
bool model_sha::decode_21(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1251 = (sha_state == 1);
	bool cppVar_1253 = (cmd == 1);
	bool cppVar_1254 = cppVar_1251 && cppVar_1253;
	bool cppVar_1256 = (cmdaddr == 65028);
	bool cppVar_1257 = cppVar_1254 && cppVar_1256;
	return cppVar_1257;
}
bool model_sha::decode_22(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1259 = (sha_state == 2);
	bool cppVar_1261 = (cmd == 1);
	bool cppVar_1262 = cppVar_1259 && cppVar_1261;
	bool cppVar_1264 = (cmdaddr == 65028);
	bool cppVar_1265 = cppVar_1262 && cppVar_1264;
	return cppVar_1265;
}
bool model_sha::decode_23(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1267 = (sha_state == 3);
	bool cppVar_1269 = (cmd == 1);
	bool cppVar_1270 = cppVar_1267 && cppVar_1269;
	bool cppVar_1272 = (cmdaddr == 65028);
	bool cppVar_1273 = cppVar_1270 && cppVar_1272;
	return cppVar_1273;
}
bool model_sha::decode_24(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1275 = (sha_state == 4);
	bool cppVar_1277 = (cmd == 1);
	bool cppVar_1278 = cppVar_1275 && cppVar_1277;
	bool cppVar_1280 = (cmdaddr == 65028);
	bool cppVar_1281 = cppVar_1278 && cppVar_1280;
	return cppVar_1281;
}
bool model_sha::decode_25(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1283 = (sha_state == 0);
	bool cppVar_1285 = (cmd == 1);
	bool cppVar_1286 = cppVar_1283 && cppVar_1285;
	bool cppVar_1288 = (cmdaddr == 65029);
	bool cppVar_1289 = cppVar_1286 && cppVar_1288;
	return cppVar_1289;
}
bool model_sha::decode_26(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1291 = (sha_state == 1);
	bool cppVar_1293 = (cmd == 1);
	bool cppVar_1294 = cppVar_1291 && cppVar_1293;
	bool cppVar_1296 = (cmdaddr == 65029);
	bool cppVar_1297 = cppVar_1294 && cppVar_1296;
	return cppVar_1297;
}
bool model_sha::decode_27(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1299 = (sha_state == 2);
	bool cppVar_1301 = (cmd == 1);
	bool cppVar_1302 = cppVar_1299 && cppVar_1301;
	bool cppVar_1304 = (cmdaddr == 65029);
	bool cppVar_1305 = cppVar_1302 && cppVar_1304;
	return cppVar_1305;
}
bool model_sha::decode_28(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1307 = (sha_state == 3);
	bool cppVar_1309 = (cmd == 1);
	bool cppVar_1310 = cppVar_1307 && cppVar_1309;
	bool cppVar_1312 = (cmdaddr == 65029);
	bool cppVar_1313 = cppVar_1310 && cppVar_1312;
	return cppVar_1313;
}
bool model_sha::decode_29(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1315 = (sha_state == 4);
	bool cppVar_1317 = (cmd == 1);
	bool cppVar_1318 = cppVar_1315 && cppVar_1317;
	bool cppVar_1320 = (cmdaddr == 65029);
	bool cppVar_1321 = cppVar_1318 && cppVar_1320;
	return cppVar_1321;
}
bool model_sha::decode_3(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1107 = (sha_state == 3);
	bool cppVar_1109 = (cmd == 1);
	bool cppVar_1110 = cppVar_1107 && cppVar_1109;
	bool cppVar_1112 = (cmdaddr == 65024);
	bool cppVar_1113 = cppVar_1110 && cppVar_1112;
	return cppVar_1113;
}
bool model_sha::decode_30(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1323 = (sha_state == 0);
	bool cppVar_1325 = (cmd == 1);
	bool cppVar_1326 = cppVar_1323 && cppVar_1325;
	bool cppVar_1328 = (cmdaddr == 65030);
	bool cppVar_1329 = cppVar_1326 && cppVar_1328;
	return cppVar_1329;
}
bool model_sha::decode_31(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1331 = (sha_state == 1);
	bool cppVar_1333 = (cmd == 1);
	bool cppVar_1334 = cppVar_1331 && cppVar_1333;
	bool cppVar_1336 = (cmdaddr == 65030);
	bool cppVar_1337 = cppVar_1334 && cppVar_1336;
	return cppVar_1337;
}
bool model_sha::decode_32(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1339 = (sha_state == 2);
	bool cppVar_1341 = (cmd == 1);
	bool cppVar_1342 = cppVar_1339 && cppVar_1341;
	bool cppVar_1344 = (cmdaddr == 65030);
	bool cppVar_1345 = cppVar_1342 && cppVar_1344;
	return cppVar_1345;
}
bool model_sha::decode_33(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1347 = (sha_state == 3);
	bool cppVar_1349 = (cmd == 1);
	bool cppVar_1350 = cppVar_1347 && cppVar_1349;
	bool cppVar_1352 = (cmdaddr == 65030);
	bool cppVar_1353 = cppVar_1350 && cppVar_1352;
	return cppVar_1353;
}
bool model_sha::decode_34(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1355 = (sha_state == 4);
	bool cppVar_1357 = (cmd == 1);
	bool cppVar_1358 = cppVar_1355 && cppVar_1357;
	bool cppVar_1360 = (cmdaddr == 65030);
	bool cppVar_1361 = cppVar_1358 && cppVar_1360;
	return cppVar_1361;
}
bool model_sha::decode_35(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1363 = (sha_state == 0);
	bool cppVar_1365 = (cmd == 1);
	bool cppVar_1366 = cppVar_1363 && cppVar_1365;
	bool cppVar_1368 = (cmdaddr == 65031);
	bool cppVar_1369 = cppVar_1366 && cppVar_1368;
	return cppVar_1369;
}
bool model_sha::decode_36(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1371 = (sha_state == 1);
	bool cppVar_1373 = (cmd == 1);
	bool cppVar_1374 = cppVar_1371 && cppVar_1373;
	bool cppVar_1376 = (cmdaddr == 65031);
	bool cppVar_1377 = cppVar_1374 && cppVar_1376;
	return cppVar_1377;
}
bool model_sha::decode_37(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1379 = (sha_state == 2);
	bool cppVar_1381 = (cmd == 1);
	bool cppVar_1382 = cppVar_1379 && cppVar_1381;
	bool cppVar_1384 = (cmdaddr == 65031);
	bool cppVar_1385 = cppVar_1382 && cppVar_1384;
	return cppVar_1385;
}
bool model_sha::decode_38(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1387 = (sha_state == 3);
	bool cppVar_1389 = (cmd == 1);
	bool cppVar_1390 = cppVar_1387 && cppVar_1389;
	bool cppVar_1392 = (cmdaddr == 65031);
	bool cppVar_1393 = cppVar_1390 && cppVar_1392;
	return cppVar_1393;
}
bool model_sha::decode_39(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1395 = (sha_state == 4);
	bool cppVar_1397 = (cmd == 1);
	bool cppVar_1398 = cppVar_1395 && cppVar_1397;
	bool cppVar_1400 = (cmdaddr == 65031);
	bool cppVar_1401 = cppVar_1398 && cppVar_1400;
	return cppVar_1401;
}
bool model_sha::decode_4(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1115 = (sha_state == 4);
	bool cppVar_1117 = (cmd == 1);
	bool cppVar_1118 = cppVar_1115 && cppVar_1117;
	bool cppVar_1120 = (cmdaddr == 65024);
	bool cppVar_1121 = cppVar_1118 && cppVar_1120;
	return cppVar_1121;
}
bool model_sha::decode_40(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1403 = (sha_state == 0);
	bool cppVar_1405 = (cmd == 1);
	bool cppVar_1406 = cppVar_1403 && cppVar_1405;
	bool cppVar_1408 = (cmdaddr == 65032);
	bool cppVar_1409 = cppVar_1406 && cppVar_1408;
	return cppVar_1409;
}
bool model_sha::decode_41(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1411 = (sha_state == 1);
	bool cppVar_1413 = (cmd == 1);
	bool cppVar_1414 = cppVar_1411 && cppVar_1413;
	bool cppVar_1416 = (cmdaddr == 65032);
	bool cppVar_1417 = cppVar_1414 && cppVar_1416;
	return cppVar_1417;
}
bool model_sha::decode_42(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1419 = (sha_state == 2);
	bool cppVar_1421 = (cmd == 1);
	bool cppVar_1422 = cppVar_1419 && cppVar_1421;
	bool cppVar_1424 = (cmdaddr == 65032);
	bool cppVar_1425 = cppVar_1422 && cppVar_1424;
	return cppVar_1425;
}
bool model_sha::decode_43(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1427 = (sha_state == 3);
	bool cppVar_1429 = (cmd == 1);
	bool cppVar_1430 = cppVar_1427 && cppVar_1429;
	bool cppVar_1432 = (cmdaddr == 65032);
	bool cppVar_1433 = cppVar_1430 && cppVar_1432;
	return cppVar_1433;
}
bool model_sha::decode_44(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1435 = (sha_state == 4);
	bool cppVar_1437 = (cmd == 1);
	bool cppVar_1438 = cppVar_1435 && cppVar_1437;
	bool cppVar_1440 = (cmdaddr == 65032);
	bool cppVar_1441 = cppVar_1438 && cppVar_1440;
	return cppVar_1441;
}
bool model_sha::decode_45(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1443 = (sha_state == 0);
	bool cppVar_1445 = (cmd == 1);
	bool cppVar_1446 = cppVar_1443 && cppVar_1445;
	bool cppVar_1448 = (cmdaddr == 65033);
	bool cppVar_1449 = cppVar_1446 && cppVar_1448;
	return cppVar_1449;
}
bool model_sha::decode_46(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1451 = (sha_state == 1);
	bool cppVar_1453 = (cmd == 1);
	bool cppVar_1454 = cppVar_1451 && cppVar_1453;
	bool cppVar_1456 = (cmdaddr == 65033);
	bool cppVar_1457 = cppVar_1454 && cppVar_1456;
	return cppVar_1457;
}
bool model_sha::decode_47(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1459 = (sha_state == 2);
	bool cppVar_1461 = (cmd == 1);
	bool cppVar_1462 = cppVar_1459 && cppVar_1461;
	bool cppVar_1464 = (cmdaddr == 65033);
	bool cppVar_1465 = cppVar_1462 && cppVar_1464;
	return cppVar_1465;
}
bool model_sha::decode_48(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1467 = (sha_state == 3);
	bool cppVar_1469 = (cmd == 1);
	bool cppVar_1470 = cppVar_1467 && cppVar_1469;
	bool cppVar_1472 = (cmdaddr == 65033);
	bool cppVar_1473 = cppVar_1470 && cppVar_1472;
	return cppVar_1473;
}
bool model_sha::decode_49(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1475 = (sha_state == 4);
	bool cppVar_1477 = (cmd == 1);
	bool cppVar_1478 = cppVar_1475 && cppVar_1477;
	bool cppVar_1480 = (cmdaddr == 65033);
	bool cppVar_1481 = cppVar_1478 && cppVar_1480;
	return cppVar_1481;
}
bool model_sha::decode_5(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1123 = (sha_state == 0);
	bool cppVar_1125 = (cmd == 1);
	bool cppVar_1126 = cppVar_1123 && cppVar_1125;
	bool cppVar_1128 = (cmdaddr == 65025);
	bool cppVar_1129 = cppVar_1126 && cppVar_1128;
	return cppVar_1129;
}
bool model_sha::decode_50(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1483 = (sha_state == 0);
	bool cppVar_1485 = (cmd == 1);
	bool cppVar_1486 = cppVar_1483 && cppVar_1485;
	bool cppVar_1488 = (cmdaddr == 65034);
	bool cppVar_1489 = cppVar_1486 && cppVar_1488;
	return cppVar_1489;
}
bool model_sha::decode_51(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1491 = (sha_state == 1);
	bool cppVar_1493 = (cmd == 1);
	bool cppVar_1494 = cppVar_1491 && cppVar_1493;
	bool cppVar_1496 = (cmdaddr == 65034);
	bool cppVar_1497 = cppVar_1494 && cppVar_1496;
	return cppVar_1497;
}
bool model_sha::decode_52(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1499 = (sha_state == 2);
	bool cppVar_1501 = (cmd == 1);
	bool cppVar_1502 = cppVar_1499 && cppVar_1501;
	bool cppVar_1504 = (cmdaddr == 65034);
	bool cppVar_1505 = cppVar_1502 && cppVar_1504;
	return cppVar_1505;
}
bool model_sha::decode_53(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1507 = (sha_state == 3);
	bool cppVar_1509 = (cmd == 1);
	bool cppVar_1510 = cppVar_1507 && cppVar_1509;
	bool cppVar_1512 = (cmdaddr == 65034);
	bool cppVar_1513 = cppVar_1510 && cppVar_1512;
	return cppVar_1513;
}
bool model_sha::decode_54(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1515 = (sha_state == 4);
	bool cppVar_1517 = (cmd == 1);
	bool cppVar_1518 = cppVar_1515 && cppVar_1517;
	bool cppVar_1520 = (cmdaddr == 65034);
	bool cppVar_1521 = cppVar_1518 && cppVar_1520;
	return cppVar_1521;
}
bool model_sha::decode_55(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1523 = (sha_state == 0);
	bool cppVar_1525 = (cmd == 1);
	bool cppVar_1526 = cppVar_1523 && cppVar_1525;
	bool cppVar_1528 = (cmdaddr == 65035);
	bool cppVar_1529 = cppVar_1526 && cppVar_1528;
	return cppVar_1529;
}
bool model_sha::decode_56(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1531 = (sha_state == 1);
	bool cppVar_1533 = (cmd == 1);
	bool cppVar_1534 = cppVar_1531 && cppVar_1533;
	bool cppVar_1536 = (cmdaddr == 65035);
	bool cppVar_1537 = cppVar_1534 && cppVar_1536;
	return cppVar_1537;
}
bool model_sha::decode_57(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1539 = (sha_state == 2);
	bool cppVar_1541 = (cmd == 1);
	bool cppVar_1542 = cppVar_1539 && cppVar_1541;
	bool cppVar_1544 = (cmdaddr == 65035);
	bool cppVar_1545 = cppVar_1542 && cppVar_1544;
	return cppVar_1545;
}
bool model_sha::decode_58(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1547 = (sha_state == 3);
	bool cppVar_1549 = (cmd == 1);
	bool cppVar_1550 = cppVar_1547 && cppVar_1549;
	bool cppVar_1552 = (cmdaddr == 65035);
	bool cppVar_1553 = cppVar_1550 && cppVar_1552;
	return cppVar_1553;
}
bool model_sha::decode_59(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1555 = (sha_state == 4);
	bool cppVar_1557 = (cmd == 1);
	bool cppVar_1558 = cppVar_1555 && cppVar_1557;
	bool cppVar_1560 = (cmdaddr == 65035);
	bool cppVar_1561 = cppVar_1558 && cppVar_1560;
	return cppVar_1561;
}
bool model_sha::decode_6(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1131 = (sha_state == 1);
	bool cppVar_1133 = (cmd == 1);
	bool cppVar_1134 = cppVar_1131 && cppVar_1133;
	bool cppVar_1136 = (cmdaddr == 65025);
	bool cppVar_1137 = cppVar_1134 && cppVar_1136;
	return cppVar_1137;
}
bool model_sha::decode_60(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1563 = (sha_state == 0);
	bool cppVar_1565 = (cmd == 1);
	bool cppVar_1566 = cppVar_1563 && cppVar_1565;
	bool cppVar_1568 = (cmdaddr == 65036);
	bool cppVar_1569 = cppVar_1566 && cppVar_1568;
	return cppVar_1569;
}
bool model_sha::decode_61(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1571 = (sha_state == 1);
	bool cppVar_1573 = (cmd == 1);
	bool cppVar_1574 = cppVar_1571 && cppVar_1573;
	bool cppVar_1576 = (cmdaddr == 65036);
	bool cppVar_1577 = cppVar_1574 && cppVar_1576;
	return cppVar_1577;
}
bool model_sha::decode_62(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1579 = (sha_state == 2);
	bool cppVar_1581 = (cmd == 1);
	bool cppVar_1582 = cppVar_1579 && cppVar_1581;
	bool cppVar_1584 = (cmdaddr == 65036);
	bool cppVar_1585 = cppVar_1582 && cppVar_1584;
	return cppVar_1585;
}
bool model_sha::decode_63(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1587 = (sha_state == 3);
	bool cppVar_1589 = (cmd == 1);
	bool cppVar_1590 = cppVar_1587 && cppVar_1589;
	bool cppVar_1592 = (cmdaddr == 65036);
	bool cppVar_1593 = cppVar_1590 && cppVar_1592;
	return cppVar_1593;
}
bool model_sha::decode_64(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1595 = (sha_state == 4);
	bool cppVar_1597 = (cmd == 1);
	bool cppVar_1598 = cppVar_1595 && cppVar_1597;
	bool cppVar_1600 = (cmdaddr == 65036);
	bool cppVar_1601 = cppVar_1598 && cppVar_1600;
	return cppVar_1601;
}
bool model_sha::decode_65(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1603 = (sha_state == 0);
	bool cppVar_1605 = (cmd == 1);
	bool cppVar_1606 = cppVar_1603 && cppVar_1605;
	bool cppVar_1608 = (cmdaddr == 65037);
	bool cppVar_1609 = cppVar_1606 && cppVar_1608;
	return cppVar_1609;
}
bool model_sha::decode_66(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1611 = (sha_state == 1);
	bool cppVar_1613 = (cmd == 1);
	bool cppVar_1614 = cppVar_1611 && cppVar_1613;
	bool cppVar_1616 = (cmdaddr == 65037);
	bool cppVar_1617 = cppVar_1614 && cppVar_1616;
	return cppVar_1617;
}
bool model_sha::decode_67(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1619 = (sha_state == 2);
	bool cppVar_1621 = (cmd == 1);
	bool cppVar_1622 = cppVar_1619 && cppVar_1621;
	bool cppVar_1624 = (cmdaddr == 65037);
	bool cppVar_1625 = cppVar_1622 && cppVar_1624;
	return cppVar_1625;
}
bool model_sha::decode_68(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1627 = (sha_state == 3);
	bool cppVar_1629 = (cmd == 1);
	bool cppVar_1630 = cppVar_1627 && cppVar_1629;
	bool cppVar_1632 = (cmdaddr == 65037);
	bool cppVar_1633 = cppVar_1630 && cppVar_1632;
	return cppVar_1633;
}
bool model_sha::decode_69(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1635 = (sha_state == 4);
	bool cppVar_1637 = (cmd == 1);
	bool cppVar_1638 = cppVar_1635 && cppVar_1637;
	bool cppVar_1640 = (cmdaddr == 65037);
	bool cppVar_1641 = cppVar_1638 && cppVar_1640;
	return cppVar_1641;
}
bool model_sha::decode_7(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1139 = (sha_state == 2);
	bool cppVar_1141 = (cmd == 1);
	bool cppVar_1142 = cppVar_1139 && cppVar_1141;
	bool cppVar_1144 = (cmdaddr == 65025);
	bool cppVar_1145 = cppVar_1142 && cppVar_1144;
	return cppVar_1145;
}
bool model_sha::decode_70(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1643 = (sha_state == 0);
	bool cppVar_1645 = (cmd == 1);
	bool cppVar_1646 = cppVar_1643 && cppVar_1645;
	bool cppVar_1648 = (cmdaddr == 65038);
	bool cppVar_1649 = cppVar_1646 && cppVar_1648;
	return cppVar_1649;
}
bool model_sha::decode_71(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1651 = (sha_state == 1);
	bool cppVar_1653 = (cmd == 1);
	bool cppVar_1654 = cppVar_1651 && cppVar_1653;
	bool cppVar_1656 = (cmdaddr == 65038);
	bool cppVar_1657 = cppVar_1654 && cppVar_1656;
	return cppVar_1657;
}
bool model_sha::decode_72(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1659 = (sha_state == 2);
	bool cppVar_1661 = (cmd == 1);
	bool cppVar_1662 = cppVar_1659 && cppVar_1661;
	bool cppVar_1664 = (cmdaddr == 65038);
	bool cppVar_1665 = cppVar_1662 && cppVar_1664;
	return cppVar_1665;
}
bool model_sha::decode_73(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1667 = (sha_state == 3);
	bool cppVar_1669 = (cmd == 1);
	bool cppVar_1670 = cppVar_1667 && cppVar_1669;
	bool cppVar_1672 = (cmdaddr == 65038);
	bool cppVar_1673 = cppVar_1670 && cppVar_1672;
	return cppVar_1673;
}
bool model_sha::decode_74(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1675 = (sha_state == 4);
	bool cppVar_1677 = (cmd == 1);
	bool cppVar_1678 = cppVar_1675 && cppVar_1677;
	bool cppVar_1680 = (cmdaddr == 65038);
	bool cppVar_1681 = cppVar_1678 && cppVar_1680;
	return cppVar_1681;
}
bool model_sha::decode_75(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1683 = (sha_state == 0);
	bool cppVar_1685 = (cmd == 1);
	bool cppVar_1686 = cppVar_1683 && cppVar_1685;
	bool cppVar_1688 = (cmdaddr == 65039);
	bool cppVar_1689 = cppVar_1686 && cppVar_1688;
	return cppVar_1689;
}
bool model_sha::decode_76(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1691 = (sha_state == 1);
	bool cppVar_1693 = (cmd == 1);
	bool cppVar_1694 = cppVar_1691 && cppVar_1693;
	bool cppVar_1696 = (cmdaddr == 65039);
	bool cppVar_1697 = cppVar_1694 && cppVar_1696;
	return cppVar_1697;
}
bool model_sha::decode_77(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1699 = (sha_state == 2);
	bool cppVar_1701 = (cmd == 1);
	bool cppVar_1702 = cppVar_1699 && cppVar_1701;
	bool cppVar_1704 = (cmdaddr == 65039);
	bool cppVar_1705 = cppVar_1702 && cppVar_1704;
	return cppVar_1705;
}
bool model_sha::decode_78(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1707 = (sha_state == 3);
	bool cppVar_1709 = (cmd == 1);
	bool cppVar_1710 = cppVar_1707 && cppVar_1709;
	bool cppVar_1712 = (cmdaddr == 65039);
	bool cppVar_1713 = cppVar_1710 && cppVar_1712;
	return cppVar_1713;
}
bool model_sha::decode_79(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1715 = (sha_state == 4);
	bool cppVar_1717 = (cmd == 1);
	bool cppVar_1718 = cppVar_1715 && cppVar_1717;
	bool cppVar_1720 = (cmdaddr == 65039);
	bool cppVar_1721 = cppVar_1718 && cppVar_1720;
	return cppVar_1721;
}
bool model_sha::decode_8(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1147 = (sha_state == 3);
	bool cppVar_1149 = (cmd == 1);
	bool cppVar_1150 = cppVar_1147 && cppVar_1149;
	bool cppVar_1152 = (cmdaddr == 65025);
	bool cppVar_1153 = cppVar_1150 && cppVar_1152;
	return cppVar_1153;
}
bool model_sha::decode_80(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1723 = (sha_state == 0);
	bool cppVar_1725 = (cmd == 2);
	bool cppVar_1726 = cppVar_1723 && cppVar_1725;
	bool cppVar_1728 = (cmdaddr == 65024);
	bool cppVar_1729 = cppVar_1726 && cppVar_1728;
	return cppVar_1729;
}
bool model_sha::decode_81(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1731 = (sha_state == 0);
	bool cppVar_1733 = (cmd == 2);
	bool cppVar_1734 = cppVar_1731 && cppVar_1733;
	bool cppVar_1736 = (cmdaddr == 65025);
	bool cppVar_1737 = cppVar_1734 && cppVar_1736;
	return cppVar_1737;
}
bool model_sha::decode_82(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1739 = (sha_state == 0);
	bool cppVar_1741 = (cmd == 2);
	bool cppVar_1742 = cppVar_1739 && cppVar_1741;
	bool cppVar_1744 = (cmdaddr == 65026);
	bool cppVar_1745 = cppVar_1742 && cppVar_1744;
	return cppVar_1745;
}
bool model_sha::decode_83(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1747 = (sha_state == 0);
	bool cppVar_1749 = (cmd == 2);
	bool cppVar_1750 = cppVar_1747 && cppVar_1749;
	bool cppVar_1752 = (cmdaddr == 65027);
	bool cppVar_1753 = cppVar_1750 && cppVar_1752;
	return cppVar_1753;
}
bool model_sha::decode_84(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1755 = (sha_state == 0);
	bool cppVar_1757 = (cmd == 2);
	bool cppVar_1758 = cppVar_1755 && cppVar_1757;
	bool cppVar_1760 = (cmdaddr == 65028);
	bool cppVar_1761 = cppVar_1758 && cppVar_1760;
	return cppVar_1761;
}
bool model_sha::decode_85(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1763 = (sha_state == 0);
	bool cppVar_1765 = (cmd == 2);
	bool cppVar_1766 = cppVar_1763 && cppVar_1765;
	bool cppVar_1768 = (cmdaddr == 65029);
	bool cppVar_1769 = cppVar_1766 && cppVar_1768;
	return cppVar_1769;
}
bool model_sha::decode_86(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1771 = (sha_state == 0);
	bool cppVar_1773 = (cmd == 2);
	bool cppVar_1774 = cppVar_1771 && cppVar_1773;
	bool cppVar_1776 = (cmdaddr == 65030);
	bool cppVar_1777 = cppVar_1774 && cppVar_1776;
	return cppVar_1777;
}
bool model_sha::decode_87(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1779 = (sha_state == 0);
	bool cppVar_1781 = (cmd == 2);
	bool cppVar_1782 = cppVar_1779 && cppVar_1781;
	bool cppVar_1784 = (cmdaddr == 65031);
	bool cppVar_1785 = cppVar_1782 && cppVar_1784;
	return cppVar_1785;
}
bool model_sha::decode_88(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1787 = (sha_state == 0);
	bool cppVar_1789 = (cmd == 2);
	bool cppVar_1790 = cppVar_1787 && cppVar_1789;
	bool cppVar_1792 = (cmdaddr == 65032);
	bool cppVar_1793 = cppVar_1790 && cppVar_1792;
	return cppVar_1793;
}
bool model_sha::decode_89(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1795 = (sha_state == 0);
	bool cppVar_1797 = (cmd == 2);
	bool cppVar_1798 = cppVar_1795 && cppVar_1797;
	bool cppVar_1800 = (cmdaddr == 65033);
	bool cppVar_1801 = cppVar_1798 && cppVar_1800;
	return cppVar_1801;
}
bool model_sha::decode_9(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1155 = (sha_state == 4);
	bool cppVar_1157 = (cmd == 1);
	bool cppVar_1158 = cppVar_1155 && cppVar_1157;
	bool cppVar_1160 = (cmdaddr == 65025);
	bool cppVar_1161 = cppVar_1158 && cppVar_1160;
	return cppVar_1161;
}
bool model_sha::decode_90(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1803 = (sha_state == 0);
	bool cppVar_1805 = (cmd == 2);
	bool cppVar_1806 = cppVar_1803 && cppVar_1805;
	bool cppVar_1808 = (cmdaddr == 65034);
	bool cppVar_1809 = cppVar_1806 && cppVar_1808;
	return cppVar_1809;
}
bool model_sha::decode_91(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1811 = (sha_state == 0);
	bool cppVar_1813 = (cmd == 2);
	bool cppVar_1814 = cppVar_1811 && cppVar_1813;
	bool cppVar_1816 = (cmdaddr == 65035);
	bool cppVar_1817 = cppVar_1814 && cppVar_1816;
	return cppVar_1817;
}
bool model_sha::decode_92(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1819 = (sha_state == 0);
	bool cppVar_1821 = (cmd == 2);
	bool cppVar_1822 = cppVar_1819 && cppVar_1821;
	bool cppVar_1824 = (cmdaddr == 65036);
	bool cppVar_1825 = cppVar_1822 && cppVar_1824;
	return cppVar_1825;
}
bool model_sha::decode_93(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1827 = (sha_state == 0);
	bool cppVar_1829 = (cmd == 2);
	bool cppVar_1830 = cppVar_1827 && cppVar_1829;
	bool cppVar_1832 = (cmdaddr == 65037);
	bool cppVar_1833 = cppVar_1830 && cppVar_1832;
	return cppVar_1833;
}
bool model_sha::decode_94(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1835 = (sha_state == 0);
	bool cppVar_1837 = (cmd == 2);
	bool cppVar_1838 = cppVar_1835 && cppVar_1837;
	bool cppVar_1840 = (cmdaddr == 65038);
	bool cppVar_1841 = cppVar_1838 && cppVar_1840;
	return cppVar_1841;
}
bool model_sha::decode_95(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1843 = (sha_state == 0);
	bool cppVar_1845 = (cmd == 2);
	bool cppVar_1846 = cppVar_1843 && cppVar_1845;
	bool cppVar_1848 = (cmdaddr == 65039);
	bool cppVar_1849 = cppVar_1846 && cppVar_1848;
	return cppVar_1849;
}
bool model_sha::decode_96(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1851 = (sha_state != 0);
	bool cppVar_1853 = (cmd != 1);
	bool cppVar_1854 = cppVar_1851 && cppVar_1853;
	bool cppVar_1856 = (sha_state == 0);
	bool cppVar_1858 = (cmd != 1);
	bool cppVar_1859 = cppVar_1856 && cppVar_1858;
	bool cppVar_1861 = (cmd != 2);
	bool cppVar_1862 = cppVar_1859 && cppVar_1861;
	bool cppVar_1863 = cppVar_1854 || cppVar_1862;
	return cppVar_1863;
}
BIT_VEC model_sha::fetch(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1074 = (cmdaddr << 8) | cmddata;
	cppVar_1074 = (cppVar_1074 & cppMask_un_24_);
	BIT_VEC cppVar_1075 = (cmd << 24) | cppVar_1074;
	cppVar_1075 = (cppVar_1075 & cppMask_un_26_);
	BIT_VEC cppVar_1076 = (sha_state << 26) | cppVar_1075;
	cppVar_1076 = (cppVar_1076 & cppMask_un_29_);
	return cppVar_1076;
}
bool model_sha::fetchValid(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1078 = (cmd == 1);
	bool cppVar_1080 = (cmd == 2);
	bool cppVar_1081 = cppVar_1078 || cppVar_1080;
	return cppVar_1081;
}
void model_sha::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_914 = cppUpdateFun_dataout(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_937 = cppUpdateFun_sha_len(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_960 = cppUpdateFun_sha_rdaddr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1014 = cppUpdateFun_sha_state(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1037 = cppUpdateFun_sha_wraddr(cmd, cmdaddr, cmddata);
	bool cppVar_1039 = (sha_state != 0);
	bool cppVar_1041 = (sha_state == 4);
	BIT_VEC cppVar_1044;
	type_mem cppVar_1042 = XRAM;
	for (int cppVar_1043 = 0; cppVar_1043 < 20; cppVar_1043++) {
		cppVar_1044 = sha_hs_data >> ((20 - 1 - cppVar_1043) * 8);
		cppVar_1042.wr(sha_wraddr + cppVar_1043, cppVar_1044);
	}
	type_mem& cppVar_1045 = (cppVar_1041) ? cppVar_1042 : XRAM;
	type_mem& cppVar_1046 = (cppVar_1039) ? cppVar_1045 : XRAM;
	BIT_VEC cppVar_1055 = cppUpdateFun_sha_bytes_read(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1063 = cppUpdateFun_sha_hs_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1073 = cppUpdateFun_sha_rd_data(cmd, cmdaddr, cmddata);
	dataout = cppVar_914;
	sha_len = cppVar_937;
	sha_rdaddr = cppVar_960;
	sha_state = cppVar_1014;
	sha_wraddr = cppVar_1037;
	XRAM = cppVar_1046;
	sha_bytes_read = cppVar_1055;
	sha_hs_data = cppVar_1063;
	sha_rd_data = cppVar_1073;
	return;
}

/****************************************************/
/****************************************************/
#endif
/****************************************************/
