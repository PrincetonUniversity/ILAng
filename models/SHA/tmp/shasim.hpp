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

extern BIT_VEC sha(BIT_VEC cppVar_14);

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
	bool decode_0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_10(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_100(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_101(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_102(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_103(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_104(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_105(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_106(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_107(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_108(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_109(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_11(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_110(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_111(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_112(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_113(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_114(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_115(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_116(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_117(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_118(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_119(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_12(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_120(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_121(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_122(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_123(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_124(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_125(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_126(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_127(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_128(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_129(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_13(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_130(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_131(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_132(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_133(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_134(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_135(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_136(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_137(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_138(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_139(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_14(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_140(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_141(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_142(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_143(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_144(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_145(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_146(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_147(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_148(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_149(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_15(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_150(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_151(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_152(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_153(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_154(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_155(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_156(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_157(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_158(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_159(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
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
	bool decode_97(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_98(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
	bool decode_99(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata);
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
bool model_sha::decode_0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2219 = (sha_state == 0);
	bool cppVar_2221 = (cmd == 1);
	bool cppVar_2222 = cppVar_2219 && cppVar_2221;
	bool cppVar_2224 = (cmdaddr == 65024);
	bool cppVar_2225 = cppVar_2222 && cppVar_2224;
	return cppVar_2225;
}
bool model_sha::decode_1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2227 = (sha_state == 1);
	bool cppVar_2229 = (cmd == 1);
	bool cppVar_2230 = cppVar_2227 && cppVar_2229;
	bool cppVar_2232 = (cmdaddr == 65024);
	bool cppVar_2233 = cppVar_2230 && cppVar_2232;
	return cppVar_2233;
}
bool model_sha::decode_10(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2299 = (sha_state == 0);
	bool cppVar_2301 = (cmd == 1);
	bool cppVar_2302 = cppVar_2299 && cppVar_2301;
	bool cppVar_2304 = (cmdaddr == 65026);
	bool cppVar_2305 = cppVar_2302 && cppVar_2304;
	return cppVar_2305;
}
bool model_sha::decode_100(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3019 = (sha_state == 1);
	bool cppVar_3021 = (cmd != 1);
	bool cppVar_3022 = cppVar_3019 && cppVar_3021;
	bool cppVar_3024 = (cmdaddr == 65025);
	bool cppVar_3025 = cppVar_3022 && cppVar_3024;
	return cppVar_3025;
}
bool model_sha::decode_101(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3027 = (sha_state == 2);
	bool cppVar_3029 = (cmd != 1);
	bool cppVar_3030 = cppVar_3027 && cppVar_3029;
	bool cppVar_3032 = (cmdaddr == 65025);
	bool cppVar_3033 = cppVar_3030 && cppVar_3032;
	return cppVar_3033;
}
bool model_sha::decode_102(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3035 = (sha_state == 3);
	bool cppVar_3037 = (cmd != 1);
	bool cppVar_3038 = cppVar_3035 && cppVar_3037;
	bool cppVar_3040 = (cmdaddr == 65025);
	bool cppVar_3041 = cppVar_3038 && cppVar_3040;
	return cppVar_3041;
}
bool model_sha::decode_103(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3043 = (sha_state == 4);
	bool cppVar_3045 = (cmd != 1);
	bool cppVar_3046 = cppVar_3043 && cppVar_3045;
	bool cppVar_3048 = (cmdaddr == 65025);
	bool cppVar_3049 = cppVar_3046 && cppVar_3048;
	return cppVar_3049;
}
bool model_sha::decode_104(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3051 = (sha_state == 1);
	bool cppVar_3053 = (cmd != 1);
	bool cppVar_3054 = cppVar_3051 && cppVar_3053;
	bool cppVar_3056 = (cmdaddr == 65026);
	bool cppVar_3057 = cppVar_3054 && cppVar_3056;
	return cppVar_3057;
}
bool model_sha::decode_105(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3059 = (sha_state == 2);
	bool cppVar_3061 = (cmd != 1);
	bool cppVar_3062 = cppVar_3059 && cppVar_3061;
	bool cppVar_3064 = (cmdaddr == 65026);
	bool cppVar_3065 = cppVar_3062 && cppVar_3064;
	return cppVar_3065;
}
bool model_sha::decode_106(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3067 = (sha_state == 3);
	bool cppVar_3069 = (cmd != 1);
	bool cppVar_3070 = cppVar_3067 && cppVar_3069;
	bool cppVar_3072 = (cmdaddr == 65026);
	bool cppVar_3073 = cppVar_3070 && cppVar_3072;
	return cppVar_3073;
}
bool model_sha::decode_107(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3075 = (sha_state == 4);
	bool cppVar_3077 = (cmd != 1);
	bool cppVar_3078 = cppVar_3075 && cppVar_3077;
	bool cppVar_3080 = (cmdaddr == 65026);
	bool cppVar_3081 = cppVar_3078 && cppVar_3080;
	return cppVar_3081;
}
bool model_sha::decode_108(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3083 = (sha_state == 1);
	bool cppVar_3085 = (cmd != 1);
	bool cppVar_3086 = cppVar_3083 && cppVar_3085;
	bool cppVar_3088 = (cmdaddr == 65027);
	bool cppVar_3089 = cppVar_3086 && cppVar_3088;
	return cppVar_3089;
}
bool model_sha::decode_109(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3091 = (sha_state == 2);
	bool cppVar_3093 = (cmd != 1);
	bool cppVar_3094 = cppVar_3091 && cppVar_3093;
	bool cppVar_3096 = (cmdaddr == 65027);
	bool cppVar_3097 = cppVar_3094 && cppVar_3096;
	return cppVar_3097;
}
bool model_sha::decode_11(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2307 = (sha_state == 1);
	bool cppVar_2309 = (cmd == 1);
	bool cppVar_2310 = cppVar_2307 && cppVar_2309;
	bool cppVar_2312 = (cmdaddr == 65026);
	bool cppVar_2313 = cppVar_2310 && cppVar_2312;
	return cppVar_2313;
}
bool model_sha::decode_110(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3099 = (sha_state == 3);
	bool cppVar_3101 = (cmd != 1);
	bool cppVar_3102 = cppVar_3099 && cppVar_3101;
	bool cppVar_3104 = (cmdaddr == 65027);
	bool cppVar_3105 = cppVar_3102 && cppVar_3104;
	return cppVar_3105;
}
bool model_sha::decode_111(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3107 = (sha_state == 4);
	bool cppVar_3109 = (cmd != 1);
	bool cppVar_3110 = cppVar_3107 && cppVar_3109;
	bool cppVar_3112 = (cmdaddr == 65027);
	bool cppVar_3113 = cppVar_3110 && cppVar_3112;
	return cppVar_3113;
}
bool model_sha::decode_112(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3115 = (sha_state == 1);
	bool cppVar_3117 = (cmd != 1);
	bool cppVar_3118 = cppVar_3115 && cppVar_3117;
	bool cppVar_3120 = (cmdaddr == 65028);
	bool cppVar_3121 = cppVar_3118 && cppVar_3120;
	return cppVar_3121;
}
bool model_sha::decode_113(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3123 = (sha_state == 2);
	bool cppVar_3125 = (cmd != 1);
	bool cppVar_3126 = cppVar_3123 && cppVar_3125;
	bool cppVar_3128 = (cmdaddr == 65028);
	bool cppVar_3129 = cppVar_3126 && cppVar_3128;
	return cppVar_3129;
}
bool model_sha::decode_114(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3131 = (sha_state == 3);
	bool cppVar_3133 = (cmd != 1);
	bool cppVar_3134 = cppVar_3131 && cppVar_3133;
	bool cppVar_3136 = (cmdaddr == 65028);
	bool cppVar_3137 = cppVar_3134 && cppVar_3136;
	return cppVar_3137;
}
bool model_sha::decode_115(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3139 = (sha_state == 4);
	bool cppVar_3141 = (cmd != 1);
	bool cppVar_3142 = cppVar_3139 && cppVar_3141;
	bool cppVar_3144 = (cmdaddr == 65028);
	bool cppVar_3145 = cppVar_3142 && cppVar_3144;
	return cppVar_3145;
}
bool model_sha::decode_116(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3147 = (sha_state == 1);
	bool cppVar_3149 = (cmd != 1);
	bool cppVar_3150 = cppVar_3147 && cppVar_3149;
	bool cppVar_3152 = (cmdaddr == 65029);
	bool cppVar_3153 = cppVar_3150 && cppVar_3152;
	return cppVar_3153;
}
bool model_sha::decode_117(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3155 = (sha_state == 2);
	bool cppVar_3157 = (cmd != 1);
	bool cppVar_3158 = cppVar_3155 && cppVar_3157;
	bool cppVar_3160 = (cmdaddr == 65029);
	bool cppVar_3161 = cppVar_3158 && cppVar_3160;
	return cppVar_3161;
}
bool model_sha::decode_118(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3163 = (sha_state == 3);
	bool cppVar_3165 = (cmd != 1);
	bool cppVar_3166 = cppVar_3163 && cppVar_3165;
	bool cppVar_3168 = (cmdaddr == 65029);
	bool cppVar_3169 = cppVar_3166 && cppVar_3168;
	return cppVar_3169;
}
bool model_sha::decode_119(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3171 = (sha_state == 4);
	bool cppVar_3173 = (cmd != 1);
	bool cppVar_3174 = cppVar_3171 && cppVar_3173;
	bool cppVar_3176 = (cmdaddr == 65029);
	bool cppVar_3177 = cppVar_3174 && cppVar_3176;
	return cppVar_3177;
}
bool model_sha::decode_12(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2315 = (sha_state == 2);
	bool cppVar_2317 = (cmd == 1);
	bool cppVar_2318 = cppVar_2315 && cppVar_2317;
	bool cppVar_2320 = (cmdaddr == 65026);
	bool cppVar_2321 = cppVar_2318 && cppVar_2320;
	return cppVar_2321;
}
bool model_sha::decode_120(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3179 = (sha_state == 1);
	bool cppVar_3181 = (cmd != 1);
	bool cppVar_3182 = cppVar_3179 && cppVar_3181;
	bool cppVar_3184 = (cmdaddr == 65030);
	bool cppVar_3185 = cppVar_3182 && cppVar_3184;
	return cppVar_3185;
}
bool model_sha::decode_121(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3187 = (sha_state == 2);
	bool cppVar_3189 = (cmd != 1);
	bool cppVar_3190 = cppVar_3187 && cppVar_3189;
	bool cppVar_3192 = (cmdaddr == 65030);
	bool cppVar_3193 = cppVar_3190 && cppVar_3192;
	return cppVar_3193;
}
bool model_sha::decode_122(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3195 = (sha_state == 3);
	bool cppVar_3197 = (cmd != 1);
	bool cppVar_3198 = cppVar_3195 && cppVar_3197;
	bool cppVar_3200 = (cmdaddr == 65030);
	bool cppVar_3201 = cppVar_3198 && cppVar_3200;
	return cppVar_3201;
}
bool model_sha::decode_123(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3203 = (sha_state == 4);
	bool cppVar_3205 = (cmd != 1);
	bool cppVar_3206 = cppVar_3203 && cppVar_3205;
	bool cppVar_3208 = (cmdaddr == 65030);
	bool cppVar_3209 = cppVar_3206 && cppVar_3208;
	return cppVar_3209;
}
bool model_sha::decode_124(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3211 = (sha_state == 1);
	bool cppVar_3213 = (cmd != 1);
	bool cppVar_3214 = cppVar_3211 && cppVar_3213;
	bool cppVar_3216 = (cmdaddr == 65031);
	bool cppVar_3217 = cppVar_3214 && cppVar_3216;
	return cppVar_3217;
}
bool model_sha::decode_125(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3219 = (sha_state == 2);
	bool cppVar_3221 = (cmd != 1);
	bool cppVar_3222 = cppVar_3219 && cppVar_3221;
	bool cppVar_3224 = (cmdaddr == 65031);
	bool cppVar_3225 = cppVar_3222 && cppVar_3224;
	return cppVar_3225;
}
bool model_sha::decode_126(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3227 = (sha_state == 3);
	bool cppVar_3229 = (cmd != 1);
	bool cppVar_3230 = cppVar_3227 && cppVar_3229;
	bool cppVar_3232 = (cmdaddr == 65031);
	bool cppVar_3233 = cppVar_3230 && cppVar_3232;
	return cppVar_3233;
}
bool model_sha::decode_127(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3235 = (sha_state == 4);
	bool cppVar_3237 = (cmd != 1);
	bool cppVar_3238 = cppVar_3235 && cppVar_3237;
	bool cppVar_3240 = (cmdaddr == 65031);
	bool cppVar_3241 = cppVar_3238 && cppVar_3240;
	return cppVar_3241;
}
bool model_sha::decode_128(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3243 = (sha_state == 1);
	bool cppVar_3245 = (cmd != 1);
	bool cppVar_3246 = cppVar_3243 && cppVar_3245;
	bool cppVar_3248 = (cmdaddr == 65032);
	bool cppVar_3249 = cppVar_3246 && cppVar_3248;
	return cppVar_3249;
}
bool model_sha::decode_129(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3251 = (sha_state == 2);
	bool cppVar_3253 = (cmd != 1);
	bool cppVar_3254 = cppVar_3251 && cppVar_3253;
	bool cppVar_3256 = (cmdaddr == 65032);
	bool cppVar_3257 = cppVar_3254 && cppVar_3256;
	return cppVar_3257;
}
bool model_sha::decode_13(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2323 = (sha_state == 3);
	bool cppVar_2325 = (cmd == 1);
	bool cppVar_2326 = cppVar_2323 && cppVar_2325;
	bool cppVar_2328 = (cmdaddr == 65026);
	bool cppVar_2329 = cppVar_2326 && cppVar_2328;
	return cppVar_2329;
}
bool model_sha::decode_130(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3259 = (sha_state == 3);
	bool cppVar_3261 = (cmd != 1);
	bool cppVar_3262 = cppVar_3259 && cppVar_3261;
	bool cppVar_3264 = (cmdaddr == 65032);
	bool cppVar_3265 = cppVar_3262 && cppVar_3264;
	return cppVar_3265;
}
bool model_sha::decode_131(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3267 = (sha_state == 4);
	bool cppVar_3269 = (cmd != 1);
	bool cppVar_3270 = cppVar_3267 && cppVar_3269;
	bool cppVar_3272 = (cmdaddr == 65032);
	bool cppVar_3273 = cppVar_3270 && cppVar_3272;
	return cppVar_3273;
}
bool model_sha::decode_132(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3275 = (sha_state == 1);
	bool cppVar_3277 = (cmd != 1);
	bool cppVar_3278 = cppVar_3275 && cppVar_3277;
	bool cppVar_3280 = (cmdaddr == 65033);
	bool cppVar_3281 = cppVar_3278 && cppVar_3280;
	return cppVar_3281;
}
bool model_sha::decode_133(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3283 = (sha_state == 2);
	bool cppVar_3285 = (cmd != 1);
	bool cppVar_3286 = cppVar_3283 && cppVar_3285;
	bool cppVar_3288 = (cmdaddr == 65033);
	bool cppVar_3289 = cppVar_3286 && cppVar_3288;
	return cppVar_3289;
}
bool model_sha::decode_134(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3291 = (sha_state == 3);
	bool cppVar_3293 = (cmd != 1);
	bool cppVar_3294 = cppVar_3291 && cppVar_3293;
	bool cppVar_3296 = (cmdaddr == 65033);
	bool cppVar_3297 = cppVar_3294 && cppVar_3296;
	return cppVar_3297;
}
bool model_sha::decode_135(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3299 = (sha_state == 4);
	bool cppVar_3301 = (cmd != 1);
	bool cppVar_3302 = cppVar_3299 && cppVar_3301;
	bool cppVar_3304 = (cmdaddr == 65033);
	bool cppVar_3305 = cppVar_3302 && cppVar_3304;
	return cppVar_3305;
}
bool model_sha::decode_136(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3307 = (sha_state == 1);
	bool cppVar_3309 = (cmd != 1);
	bool cppVar_3310 = cppVar_3307 && cppVar_3309;
	bool cppVar_3312 = (cmdaddr == 65034);
	bool cppVar_3313 = cppVar_3310 && cppVar_3312;
	return cppVar_3313;
}
bool model_sha::decode_137(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3315 = (sha_state == 2);
	bool cppVar_3317 = (cmd != 1);
	bool cppVar_3318 = cppVar_3315 && cppVar_3317;
	bool cppVar_3320 = (cmdaddr == 65034);
	bool cppVar_3321 = cppVar_3318 && cppVar_3320;
	return cppVar_3321;
}
bool model_sha::decode_138(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3323 = (sha_state == 3);
	bool cppVar_3325 = (cmd != 1);
	bool cppVar_3326 = cppVar_3323 && cppVar_3325;
	bool cppVar_3328 = (cmdaddr == 65034);
	bool cppVar_3329 = cppVar_3326 && cppVar_3328;
	return cppVar_3329;
}
bool model_sha::decode_139(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3331 = (sha_state == 4);
	bool cppVar_3333 = (cmd != 1);
	bool cppVar_3334 = cppVar_3331 && cppVar_3333;
	bool cppVar_3336 = (cmdaddr == 65034);
	bool cppVar_3337 = cppVar_3334 && cppVar_3336;
	return cppVar_3337;
}
bool model_sha::decode_14(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2331 = (sha_state == 4);
	bool cppVar_2333 = (cmd == 1);
	bool cppVar_2334 = cppVar_2331 && cppVar_2333;
	bool cppVar_2336 = (cmdaddr == 65026);
	bool cppVar_2337 = cppVar_2334 && cppVar_2336;
	return cppVar_2337;
}
bool model_sha::decode_140(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3339 = (sha_state == 1);
	bool cppVar_3341 = (cmd != 1);
	bool cppVar_3342 = cppVar_3339 && cppVar_3341;
	bool cppVar_3344 = (cmdaddr == 65035);
	bool cppVar_3345 = cppVar_3342 && cppVar_3344;
	return cppVar_3345;
}
bool model_sha::decode_141(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3347 = (sha_state == 2);
	bool cppVar_3349 = (cmd != 1);
	bool cppVar_3350 = cppVar_3347 && cppVar_3349;
	bool cppVar_3352 = (cmdaddr == 65035);
	bool cppVar_3353 = cppVar_3350 && cppVar_3352;
	return cppVar_3353;
}
bool model_sha::decode_142(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3355 = (sha_state == 3);
	bool cppVar_3357 = (cmd != 1);
	bool cppVar_3358 = cppVar_3355 && cppVar_3357;
	bool cppVar_3360 = (cmdaddr == 65035);
	bool cppVar_3361 = cppVar_3358 && cppVar_3360;
	return cppVar_3361;
}
bool model_sha::decode_143(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3363 = (sha_state == 4);
	bool cppVar_3365 = (cmd != 1);
	bool cppVar_3366 = cppVar_3363 && cppVar_3365;
	bool cppVar_3368 = (cmdaddr == 65035);
	bool cppVar_3369 = cppVar_3366 && cppVar_3368;
	return cppVar_3369;
}
bool model_sha::decode_144(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3371 = (sha_state == 1);
	bool cppVar_3373 = (cmd != 1);
	bool cppVar_3374 = cppVar_3371 && cppVar_3373;
	bool cppVar_3376 = (cmdaddr == 65036);
	bool cppVar_3377 = cppVar_3374 && cppVar_3376;
	return cppVar_3377;
}
bool model_sha::decode_145(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3379 = (sha_state == 2);
	bool cppVar_3381 = (cmd != 1);
	bool cppVar_3382 = cppVar_3379 && cppVar_3381;
	bool cppVar_3384 = (cmdaddr == 65036);
	bool cppVar_3385 = cppVar_3382 && cppVar_3384;
	return cppVar_3385;
}
bool model_sha::decode_146(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3387 = (sha_state == 3);
	bool cppVar_3389 = (cmd != 1);
	bool cppVar_3390 = cppVar_3387 && cppVar_3389;
	bool cppVar_3392 = (cmdaddr == 65036);
	bool cppVar_3393 = cppVar_3390 && cppVar_3392;
	return cppVar_3393;
}
bool model_sha::decode_147(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3395 = (sha_state == 4);
	bool cppVar_3397 = (cmd != 1);
	bool cppVar_3398 = cppVar_3395 && cppVar_3397;
	bool cppVar_3400 = (cmdaddr == 65036);
	bool cppVar_3401 = cppVar_3398 && cppVar_3400;
	return cppVar_3401;
}
bool model_sha::decode_148(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3403 = (sha_state == 1);
	bool cppVar_3405 = (cmd != 1);
	bool cppVar_3406 = cppVar_3403 && cppVar_3405;
	bool cppVar_3408 = (cmdaddr == 65037);
	bool cppVar_3409 = cppVar_3406 && cppVar_3408;
	return cppVar_3409;
}
bool model_sha::decode_149(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3411 = (sha_state == 2);
	bool cppVar_3413 = (cmd != 1);
	bool cppVar_3414 = cppVar_3411 && cppVar_3413;
	bool cppVar_3416 = (cmdaddr == 65037);
	bool cppVar_3417 = cppVar_3414 && cppVar_3416;
	return cppVar_3417;
}
bool model_sha::decode_15(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2339 = (sha_state == 0);
	bool cppVar_2341 = (cmd == 1);
	bool cppVar_2342 = cppVar_2339 && cppVar_2341;
	bool cppVar_2344 = (cmdaddr == 65027);
	bool cppVar_2345 = cppVar_2342 && cppVar_2344;
	return cppVar_2345;
}
bool model_sha::decode_150(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3419 = (sha_state == 3);
	bool cppVar_3421 = (cmd != 1);
	bool cppVar_3422 = cppVar_3419 && cppVar_3421;
	bool cppVar_3424 = (cmdaddr == 65037);
	bool cppVar_3425 = cppVar_3422 && cppVar_3424;
	return cppVar_3425;
}
bool model_sha::decode_151(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3427 = (sha_state == 4);
	bool cppVar_3429 = (cmd != 1);
	bool cppVar_3430 = cppVar_3427 && cppVar_3429;
	bool cppVar_3432 = (cmdaddr == 65037);
	bool cppVar_3433 = cppVar_3430 && cppVar_3432;
	return cppVar_3433;
}
bool model_sha::decode_152(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3435 = (sha_state == 1);
	bool cppVar_3437 = (cmd != 1);
	bool cppVar_3438 = cppVar_3435 && cppVar_3437;
	bool cppVar_3440 = (cmdaddr == 65038);
	bool cppVar_3441 = cppVar_3438 && cppVar_3440;
	return cppVar_3441;
}
bool model_sha::decode_153(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3443 = (sha_state == 2);
	bool cppVar_3445 = (cmd != 1);
	bool cppVar_3446 = cppVar_3443 && cppVar_3445;
	bool cppVar_3448 = (cmdaddr == 65038);
	bool cppVar_3449 = cppVar_3446 && cppVar_3448;
	return cppVar_3449;
}
bool model_sha::decode_154(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3451 = (sha_state == 3);
	bool cppVar_3453 = (cmd != 1);
	bool cppVar_3454 = cppVar_3451 && cppVar_3453;
	bool cppVar_3456 = (cmdaddr == 65038);
	bool cppVar_3457 = cppVar_3454 && cppVar_3456;
	return cppVar_3457;
}
bool model_sha::decode_155(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3459 = (sha_state == 4);
	bool cppVar_3461 = (cmd != 1);
	bool cppVar_3462 = cppVar_3459 && cppVar_3461;
	bool cppVar_3464 = (cmdaddr == 65038);
	bool cppVar_3465 = cppVar_3462 && cppVar_3464;
	return cppVar_3465;
}
bool model_sha::decode_156(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3467 = (sha_state == 1);
	bool cppVar_3469 = (cmd != 1);
	bool cppVar_3470 = cppVar_3467 && cppVar_3469;
	bool cppVar_3472 = (cmdaddr == 65039);
	bool cppVar_3473 = cppVar_3470 && cppVar_3472;
	return cppVar_3473;
}
bool model_sha::decode_157(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3475 = (sha_state == 2);
	bool cppVar_3477 = (cmd != 1);
	bool cppVar_3478 = cppVar_3475 && cppVar_3477;
	bool cppVar_3480 = (cmdaddr == 65039);
	bool cppVar_3481 = cppVar_3478 && cppVar_3480;
	return cppVar_3481;
}
bool model_sha::decode_158(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3483 = (sha_state == 3);
	bool cppVar_3485 = (cmd != 1);
	bool cppVar_3486 = cppVar_3483 && cppVar_3485;
	bool cppVar_3488 = (cmdaddr == 65039);
	bool cppVar_3489 = cppVar_3486 && cppVar_3488;
	return cppVar_3489;
}
bool model_sha::decode_159(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3491 = (sha_state == 4);
	bool cppVar_3493 = (cmd != 1);
	bool cppVar_3494 = cppVar_3491 && cppVar_3493;
	bool cppVar_3496 = (cmdaddr == 65039);
	bool cppVar_3497 = cppVar_3494 && cppVar_3496;
	return cppVar_3497;
}
bool model_sha::decode_16(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2347 = (sha_state == 1);
	bool cppVar_2349 = (cmd == 1);
	bool cppVar_2350 = cppVar_2347 && cppVar_2349;
	bool cppVar_2352 = (cmdaddr == 65027);
	bool cppVar_2353 = cppVar_2350 && cppVar_2352;
	return cppVar_2353;
}
bool model_sha::decode_17(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2355 = (sha_state == 2);
	bool cppVar_2357 = (cmd == 1);
	bool cppVar_2358 = cppVar_2355 && cppVar_2357;
	bool cppVar_2360 = (cmdaddr == 65027);
	bool cppVar_2361 = cppVar_2358 && cppVar_2360;
	return cppVar_2361;
}
bool model_sha::decode_18(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2363 = (sha_state == 3);
	bool cppVar_2365 = (cmd == 1);
	bool cppVar_2366 = cppVar_2363 && cppVar_2365;
	bool cppVar_2368 = (cmdaddr == 65027);
	bool cppVar_2369 = cppVar_2366 && cppVar_2368;
	return cppVar_2369;
}
bool model_sha::decode_19(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2371 = (sha_state == 4);
	bool cppVar_2373 = (cmd == 1);
	bool cppVar_2374 = cppVar_2371 && cppVar_2373;
	bool cppVar_2376 = (cmdaddr == 65027);
	bool cppVar_2377 = cppVar_2374 && cppVar_2376;
	return cppVar_2377;
}
bool model_sha::decode_2(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2235 = (sha_state == 2);
	bool cppVar_2237 = (cmd == 1);
	bool cppVar_2238 = cppVar_2235 && cppVar_2237;
	bool cppVar_2240 = (cmdaddr == 65024);
	bool cppVar_2241 = cppVar_2238 && cppVar_2240;
	return cppVar_2241;
}
bool model_sha::decode_20(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2379 = (sha_state == 0);
	bool cppVar_2381 = (cmd == 1);
	bool cppVar_2382 = cppVar_2379 && cppVar_2381;
	bool cppVar_2384 = (cmdaddr == 65028);
	bool cppVar_2385 = cppVar_2382 && cppVar_2384;
	return cppVar_2385;
}
bool model_sha::decode_21(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2387 = (sha_state == 1);
	bool cppVar_2389 = (cmd == 1);
	bool cppVar_2390 = cppVar_2387 && cppVar_2389;
	bool cppVar_2392 = (cmdaddr == 65028);
	bool cppVar_2393 = cppVar_2390 && cppVar_2392;
	return cppVar_2393;
}
bool model_sha::decode_22(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2395 = (sha_state == 2);
	bool cppVar_2397 = (cmd == 1);
	bool cppVar_2398 = cppVar_2395 && cppVar_2397;
	bool cppVar_2400 = (cmdaddr == 65028);
	bool cppVar_2401 = cppVar_2398 && cppVar_2400;
	return cppVar_2401;
}
bool model_sha::decode_23(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2403 = (sha_state == 3);
	bool cppVar_2405 = (cmd == 1);
	bool cppVar_2406 = cppVar_2403 && cppVar_2405;
	bool cppVar_2408 = (cmdaddr == 65028);
	bool cppVar_2409 = cppVar_2406 && cppVar_2408;
	return cppVar_2409;
}
bool model_sha::decode_24(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2411 = (sha_state == 4);
	bool cppVar_2413 = (cmd == 1);
	bool cppVar_2414 = cppVar_2411 && cppVar_2413;
	bool cppVar_2416 = (cmdaddr == 65028);
	bool cppVar_2417 = cppVar_2414 && cppVar_2416;
	return cppVar_2417;
}
bool model_sha::decode_25(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2419 = (sha_state == 0);
	bool cppVar_2421 = (cmd == 1);
	bool cppVar_2422 = cppVar_2419 && cppVar_2421;
	bool cppVar_2424 = (cmdaddr == 65029);
	bool cppVar_2425 = cppVar_2422 && cppVar_2424;
	return cppVar_2425;
}
bool model_sha::decode_26(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2427 = (sha_state == 1);
	bool cppVar_2429 = (cmd == 1);
	bool cppVar_2430 = cppVar_2427 && cppVar_2429;
	bool cppVar_2432 = (cmdaddr == 65029);
	bool cppVar_2433 = cppVar_2430 && cppVar_2432;
	return cppVar_2433;
}
bool model_sha::decode_27(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2435 = (sha_state == 2);
	bool cppVar_2437 = (cmd == 1);
	bool cppVar_2438 = cppVar_2435 && cppVar_2437;
	bool cppVar_2440 = (cmdaddr == 65029);
	bool cppVar_2441 = cppVar_2438 && cppVar_2440;
	return cppVar_2441;
}
bool model_sha::decode_28(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2443 = (sha_state == 3);
	bool cppVar_2445 = (cmd == 1);
	bool cppVar_2446 = cppVar_2443 && cppVar_2445;
	bool cppVar_2448 = (cmdaddr == 65029);
	bool cppVar_2449 = cppVar_2446 && cppVar_2448;
	return cppVar_2449;
}
bool model_sha::decode_29(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2451 = (sha_state == 4);
	bool cppVar_2453 = (cmd == 1);
	bool cppVar_2454 = cppVar_2451 && cppVar_2453;
	bool cppVar_2456 = (cmdaddr == 65029);
	bool cppVar_2457 = cppVar_2454 && cppVar_2456;
	return cppVar_2457;
}
bool model_sha::decode_3(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2243 = (sha_state == 3);
	bool cppVar_2245 = (cmd == 1);
	bool cppVar_2246 = cppVar_2243 && cppVar_2245;
	bool cppVar_2248 = (cmdaddr == 65024);
	bool cppVar_2249 = cppVar_2246 && cppVar_2248;
	return cppVar_2249;
}
bool model_sha::decode_30(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2459 = (sha_state == 0);
	bool cppVar_2461 = (cmd == 1);
	bool cppVar_2462 = cppVar_2459 && cppVar_2461;
	bool cppVar_2464 = (cmdaddr == 65030);
	bool cppVar_2465 = cppVar_2462 && cppVar_2464;
	return cppVar_2465;
}
bool model_sha::decode_31(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2467 = (sha_state == 1);
	bool cppVar_2469 = (cmd == 1);
	bool cppVar_2470 = cppVar_2467 && cppVar_2469;
	bool cppVar_2472 = (cmdaddr == 65030);
	bool cppVar_2473 = cppVar_2470 && cppVar_2472;
	return cppVar_2473;
}
bool model_sha::decode_32(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2475 = (sha_state == 2);
	bool cppVar_2477 = (cmd == 1);
	bool cppVar_2478 = cppVar_2475 && cppVar_2477;
	bool cppVar_2480 = (cmdaddr == 65030);
	bool cppVar_2481 = cppVar_2478 && cppVar_2480;
	return cppVar_2481;
}
bool model_sha::decode_33(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2483 = (sha_state == 3);
	bool cppVar_2485 = (cmd == 1);
	bool cppVar_2486 = cppVar_2483 && cppVar_2485;
	bool cppVar_2488 = (cmdaddr == 65030);
	bool cppVar_2489 = cppVar_2486 && cppVar_2488;
	return cppVar_2489;
}
bool model_sha::decode_34(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2491 = (sha_state == 4);
	bool cppVar_2493 = (cmd == 1);
	bool cppVar_2494 = cppVar_2491 && cppVar_2493;
	bool cppVar_2496 = (cmdaddr == 65030);
	bool cppVar_2497 = cppVar_2494 && cppVar_2496;
	return cppVar_2497;
}
bool model_sha::decode_35(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2499 = (sha_state == 0);
	bool cppVar_2501 = (cmd == 1);
	bool cppVar_2502 = cppVar_2499 && cppVar_2501;
	bool cppVar_2504 = (cmdaddr == 65031);
	bool cppVar_2505 = cppVar_2502 && cppVar_2504;
	return cppVar_2505;
}
bool model_sha::decode_36(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2507 = (sha_state == 1);
	bool cppVar_2509 = (cmd == 1);
	bool cppVar_2510 = cppVar_2507 && cppVar_2509;
	bool cppVar_2512 = (cmdaddr == 65031);
	bool cppVar_2513 = cppVar_2510 && cppVar_2512;
	return cppVar_2513;
}
bool model_sha::decode_37(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2515 = (sha_state == 2);
	bool cppVar_2517 = (cmd == 1);
	bool cppVar_2518 = cppVar_2515 && cppVar_2517;
	bool cppVar_2520 = (cmdaddr == 65031);
	bool cppVar_2521 = cppVar_2518 && cppVar_2520;
	return cppVar_2521;
}
bool model_sha::decode_38(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2523 = (sha_state == 3);
	bool cppVar_2525 = (cmd == 1);
	bool cppVar_2526 = cppVar_2523 && cppVar_2525;
	bool cppVar_2528 = (cmdaddr == 65031);
	bool cppVar_2529 = cppVar_2526 && cppVar_2528;
	return cppVar_2529;
}
bool model_sha::decode_39(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2531 = (sha_state == 4);
	bool cppVar_2533 = (cmd == 1);
	bool cppVar_2534 = cppVar_2531 && cppVar_2533;
	bool cppVar_2536 = (cmdaddr == 65031);
	bool cppVar_2537 = cppVar_2534 && cppVar_2536;
	return cppVar_2537;
}
bool model_sha::decode_4(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2251 = (sha_state == 4);
	bool cppVar_2253 = (cmd == 1);
	bool cppVar_2254 = cppVar_2251 && cppVar_2253;
	bool cppVar_2256 = (cmdaddr == 65024);
	bool cppVar_2257 = cppVar_2254 && cppVar_2256;
	return cppVar_2257;
}
bool model_sha::decode_40(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2539 = (sha_state == 0);
	bool cppVar_2541 = (cmd == 1);
	bool cppVar_2542 = cppVar_2539 && cppVar_2541;
	bool cppVar_2544 = (cmdaddr == 65032);
	bool cppVar_2545 = cppVar_2542 && cppVar_2544;
	return cppVar_2545;
}
bool model_sha::decode_41(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2547 = (sha_state == 1);
	bool cppVar_2549 = (cmd == 1);
	bool cppVar_2550 = cppVar_2547 && cppVar_2549;
	bool cppVar_2552 = (cmdaddr == 65032);
	bool cppVar_2553 = cppVar_2550 && cppVar_2552;
	return cppVar_2553;
}
bool model_sha::decode_42(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2555 = (sha_state == 2);
	bool cppVar_2557 = (cmd == 1);
	bool cppVar_2558 = cppVar_2555 && cppVar_2557;
	bool cppVar_2560 = (cmdaddr == 65032);
	bool cppVar_2561 = cppVar_2558 && cppVar_2560;
	return cppVar_2561;
}
bool model_sha::decode_43(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2563 = (sha_state == 3);
	bool cppVar_2565 = (cmd == 1);
	bool cppVar_2566 = cppVar_2563 && cppVar_2565;
	bool cppVar_2568 = (cmdaddr == 65032);
	bool cppVar_2569 = cppVar_2566 && cppVar_2568;
	return cppVar_2569;
}
bool model_sha::decode_44(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2571 = (sha_state == 4);
	bool cppVar_2573 = (cmd == 1);
	bool cppVar_2574 = cppVar_2571 && cppVar_2573;
	bool cppVar_2576 = (cmdaddr == 65032);
	bool cppVar_2577 = cppVar_2574 && cppVar_2576;
	return cppVar_2577;
}
bool model_sha::decode_45(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2579 = (sha_state == 0);
	bool cppVar_2581 = (cmd == 1);
	bool cppVar_2582 = cppVar_2579 && cppVar_2581;
	bool cppVar_2584 = (cmdaddr == 65033);
	bool cppVar_2585 = cppVar_2582 && cppVar_2584;
	return cppVar_2585;
}
bool model_sha::decode_46(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2587 = (sha_state == 1);
	bool cppVar_2589 = (cmd == 1);
	bool cppVar_2590 = cppVar_2587 && cppVar_2589;
	bool cppVar_2592 = (cmdaddr == 65033);
	bool cppVar_2593 = cppVar_2590 && cppVar_2592;
	return cppVar_2593;
}
bool model_sha::decode_47(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2595 = (sha_state == 2);
	bool cppVar_2597 = (cmd == 1);
	bool cppVar_2598 = cppVar_2595 && cppVar_2597;
	bool cppVar_2600 = (cmdaddr == 65033);
	bool cppVar_2601 = cppVar_2598 && cppVar_2600;
	return cppVar_2601;
}
bool model_sha::decode_48(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2603 = (sha_state == 3);
	bool cppVar_2605 = (cmd == 1);
	bool cppVar_2606 = cppVar_2603 && cppVar_2605;
	bool cppVar_2608 = (cmdaddr == 65033);
	bool cppVar_2609 = cppVar_2606 && cppVar_2608;
	return cppVar_2609;
}
bool model_sha::decode_49(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2611 = (sha_state == 4);
	bool cppVar_2613 = (cmd == 1);
	bool cppVar_2614 = cppVar_2611 && cppVar_2613;
	bool cppVar_2616 = (cmdaddr == 65033);
	bool cppVar_2617 = cppVar_2614 && cppVar_2616;
	return cppVar_2617;
}
bool model_sha::decode_5(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2259 = (sha_state == 0);
	bool cppVar_2261 = (cmd == 1);
	bool cppVar_2262 = cppVar_2259 && cppVar_2261;
	bool cppVar_2264 = (cmdaddr == 65025);
	bool cppVar_2265 = cppVar_2262 && cppVar_2264;
	return cppVar_2265;
}
bool model_sha::decode_50(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2619 = (sha_state == 0);
	bool cppVar_2621 = (cmd == 1);
	bool cppVar_2622 = cppVar_2619 && cppVar_2621;
	bool cppVar_2624 = (cmdaddr == 65034);
	bool cppVar_2625 = cppVar_2622 && cppVar_2624;
	return cppVar_2625;
}
bool model_sha::decode_51(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2627 = (sha_state == 1);
	bool cppVar_2629 = (cmd == 1);
	bool cppVar_2630 = cppVar_2627 && cppVar_2629;
	bool cppVar_2632 = (cmdaddr == 65034);
	bool cppVar_2633 = cppVar_2630 && cppVar_2632;
	return cppVar_2633;
}
bool model_sha::decode_52(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2635 = (sha_state == 2);
	bool cppVar_2637 = (cmd == 1);
	bool cppVar_2638 = cppVar_2635 && cppVar_2637;
	bool cppVar_2640 = (cmdaddr == 65034);
	bool cppVar_2641 = cppVar_2638 && cppVar_2640;
	return cppVar_2641;
}
bool model_sha::decode_53(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2643 = (sha_state == 3);
	bool cppVar_2645 = (cmd == 1);
	bool cppVar_2646 = cppVar_2643 && cppVar_2645;
	bool cppVar_2648 = (cmdaddr == 65034);
	bool cppVar_2649 = cppVar_2646 && cppVar_2648;
	return cppVar_2649;
}
bool model_sha::decode_54(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2651 = (sha_state == 4);
	bool cppVar_2653 = (cmd == 1);
	bool cppVar_2654 = cppVar_2651 && cppVar_2653;
	bool cppVar_2656 = (cmdaddr == 65034);
	bool cppVar_2657 = cppVar_2654 && cppVar_2656;
	return cppVar_2657;
}
bool model_sha::decode_55(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2659 = (sha_state == 0);
	bool cppVar_2661 = (cmd == 1);
	bool cppVar_2662 = cppVar_2659 && cppVar_2661;
	bool cppVar_2664 = (cmdaddr == 65035);
	bool cppVar_2665 = cppVar_2662 && cppVar_2664;
	return cppVar_2665;
}
bool model_sha::decode_56(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2667 = (sha_state == 1);
	bool cppVar_2669 = (cmd == 1);
	bool cppVar_2670 = cppVar_2667 && cppVar_2669;
	bool cppVar_2672 = (cmdaddr == 65035);
	bool cppVar_2673 = cppVar_2670 && cppVar_2672;
	return cppVar_2673;
}
bool model_sha::decode_57(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2675 = (sha_state == 2);
	bool cppVar_2677 = (cmd == 1);
	bool cppVar_2678 = cppVar_2675 && cppVar_2677;
	bool cppVar_2680 = (cmdaddr == 65035);
	bool cppVar_2681 = cppVar_2678 && cppVar_2680;
	return cppVar_2681;
}
bool model_sha::decode_58(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2683 = (sha_state == 3);
	bool cppVar_2685 = (cmd == 1);
	bool cppVar_2686 = cppVar_2683 && cppVar_2685;
	bool cppVar_2688 = (cmdaddr == 65035);
	bool cppVar_2689 = cppVar_2686 && cppVar_2688;
	return cppVar_2689;
}
bool model_sha::decode_59(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2691 = (sha_state == 4);
	bool cppVar_2693 = (cmd == 1);
	bool cppVar_2694 = cppVar_2691 && cppVar_2693;
	bool cppVar_2696 = (cmdaddr == 65035);
	bool cppVar_2697 = cppVar_2694 && cppVar_2696;
	return cppVar_2697;
}
bool model_sha::decode_6(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2267 = (sha_state == 1);
	bool cppVar_2269 = (cmd == 1);
	bool cppVar_2270 = cppVar_2267 && cppVar_2269;
	bool cppVar_2272 = (cmdaddr == 65025);
	bool cppVar_2273 = cppVar_2270 && cppVar_2272;
	return cppVar_2273;
}
bool model_sha::decode_60(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2699 = (sha_state == 0);
	bool cppVar_2701 = (cmd == 1);
	bool cppVar_2702 = cppVar_2699 && cppVar_2701;
	bool cppVar_2704 = (cmdaddr == 65036);
	bool cppVar_2705 = cppVar_2702 && cppVar_2704;
	return cppVar_2705;
}
bool model_sha::decode_61(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2707 = (sha_state == 1);
	bool cppVar_2709 = (cmd == 1);
	bool cppVar_2710 = cppVar_2707 && cppVar_2709;
	bool cppVar_2712 = (cmdaddr == 65036);
	bool cppVar_2713 = cppVar_2710 && cppVar_2712;
	return cppVar_2713;
}
bool model_sha::decode_62(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2715 = (sha_state == 2);
	bool cppVar_2717 = (cmd == 1);
	bool cppVar_2718 = cppVar_2715 && cppVar_2717;
	bool cppVar_2720 = (cmdaddr == 65036);
	bool cppVar_2721 = cppVar_2718 && cppVar_2720;
	return cppVar_2721;
}
bool model_sha::decode_63(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2723 = (sha_state == 3);
	bool cppVar_2725 = (cmd == 1);
	bool cppVar_2726 = cppVar_2723 && cppVar_2725;
	bool cppVar_2728 = (cmdaddr == 65036);
	bool cppVar_2729 = cppVar_2726 && cppVar_2728;
	return cppVar_2729;
}
bool model_sha::decode_64(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2731 = (sha_state == 4);
	bool cppVar_2733 = (cmd == 1);
	bool cppVar_2734 = cppVar_2731 && cppVar_2733;
	bool cppVar_2736 = (cmdaddr == 65036);
	bool cppVar_2737 = cppVar_2734 && cppVar_2736;
	return cppVar_2737;
}
bool model_sha::decode_65(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2739 = (sha_state == 0);
	bool cppVar_2741 = (cmd == 1);
	bool cppVar_2742 = cppVar_2739 && cppVar_2741;
	bool cppVar_2744 = (cmdaddr == 65037);
	bool cppVar_2745 = cppVar_2742 && cppVar_2744;
	return cppVar_2745;
}
bool model_sha::decode_66(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2747 = (sha_state == 1);
	bool cppVar_2749 = (cmd == 1);
	bool cppVar_2750 = cppVar_2747 && cppVar_2749;
	bool cppVar_2752 = (cmdaddr == 65037);
	bool cppVar_2753 = cppVar_2750 && cppVar_2752;
	return cppVar_2753;
}
bool model_sha::decode_67(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2755 = (sha_state == 2);
	bool cppVar_2757 = (cmd == 1);
	bool cppVar_2758 = cppVar_2755 && cppVar_2757;
	bool cppVar_2760 = (cmdaddr == 65037);
	bool cppVar_2761 = cppVar_2758 && cppVar_2760;
	return cppVar_2761;
}
bool model_sha::decode_68(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2763 = (sha_state == 3);
	bool cppVar_2765 = (cmd == 1);
	bool cppVar_2766 = cppVar_2763 && cppVar_2765;
	bool cppVar_2768 = (cmdaddr == 65037);
	bool cppVar_2769 = cppVar_2766 && cppVar_2768;
	return cppVar_2769;
}
bool model_sha::decode_69(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2771 = (sha_state == 4);
	bool cppVar_2773 = (cmd == 1);
	bool cppVar_2774 = cppVar_2771 && cppVar_2773;
	bool cppVar_2776 = (cmdaddr == 65037);
	bool cppVar_2777 = cppVar_2774 && cppVar_2776;
	return cppVar_2777;
}
bool model_sha::decode_7(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2275 = (sha_state == 2);
	bool cppVar_2277 = (cmd == 1);
	bool cppVar_2278 = cppVar_2275 && cppVar_2277;
	bool cppVar_2280 = (cmdaddr == 65025);
	bool cppVar_2281 = cppVar_2278 && cppVar_2280;
	return cppVar_2281;
}
bool model_sha::decode_70(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2779 = (sha_state == 0);
	bool cppVar_2781 = (cmd == 1);
	bool cppVar_2782 = cppVar_2779 && cppVar_2781;
	bool cppVar_2784 = (cmdaddr == 65038);
	bool cppVar_2785 = cppVar_2782 && cppVar_2784;
	return cppVar_2785;
}
bool model_sha::decode_71(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2787 = (sha_state == 1);
	bool cppVar_2789 = (cmd == 1);
	bool cppVar_2790 = cppVar_2787 && cppVar_2789;
	bool cppVar_2792 = (cmdaddr == 65038);
	bool cppVar_2793 = cppVar_2790 && cppVar_2792;
	return cppVar_2793;
}
bool model_sha::decode_72(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2795 = (sha_state == 2);
	bool cppVar_2797 = (cmd == 1);
	bool cppVar_2798 = cppVar_2795 && cppVar_2797;
	bool cppVar_2800 = (cmdaddr == 65038);
	bool cppVar_2801 = cppVar_2798 && cppVar_2800;
	return cppVar_2801;
}
bool model_sha::decode_73(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2803 = (sha_state == 3);
	bool cppVar_2805 = (cmd == 1);
	bool cppVar_2806 = cppVar_2803 && cppVar_2805;
	bool cppVar_2808 = (cmdaddr == 65038);
	bool cppVar_2809 = cppVar_2806 && cppVar_2808;
	return cppVar_2809;
}
bool model_sha::decode_74(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2811 = (sha_state == 4);
	bool cppVar_2813 = (cmd == 1);
	bool cppVar_2814 = cppVar_2811 && cppVar_2813;
	bool cppVar_2816 = (cmdaddr == 65038);
	bool cppVar_2817 = cppVar_2814 && cppVar_2816;
	return cppVar_2817;
}
bool model_sha::decode_75(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2819 = (sha_state == 0);
	bool cppVar_2821 = (cmd == 1);
	bool cppVar_2822 = cppVar_2819 && cppVar_2821;
	bool cppVar_2824 = (cmdaddr == 65039);
	bool cppVar_2825 = cppVar_2822 && cppVar_2824;
	return cppVar_2825;
}
bool model_sha::decode_76(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2827 = (sha_state == 1);
	bool cppVar_2829 = (cmd == 1);
	bool cppVar_2830 = cppVar_2827 && cppVar_2829;
	bool cppVar_2832 = (cmdaddr == 65039);
	bool cppVar_2833 = cppVar_2830 && cppVar_2832;
	return cppVar_2833;
}
bool model_sha::decode_77(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2835 = (sha_state == 2);
	bool cppVar_2837 = (cmd == 1);
	bool cppVar_2838 = cppVar_2835 && cppVar_2837;
	bool cppVar_2840 = (cmdaddr == 65039);
	bool cppVar_2841 = cppVar_2838 && cppVar_2840;
	return cppVar_2841;
}
bool model_sha::decode_78(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2843 = (sha_state == 3);
	bool cppVar_2845 = (cmd == 1);
	bool cppVar_2846 = cppVar_2843 && cppVar_2845;
	bool cppVar_2848 = (cmdaddr == 65039);
	bool cppVar_2849 = cppVar_2846 && cppVar_2848;
	return cppVar_2849;
}
bool model_sha::decode_79(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2851 = (sha_state == 4);
	bool cppVar_2853 = (cmd == 1);
	bool cppVar_2854 = cppVar_2851 && cppVar_2853;
	bool cppVar_2856 = (cmdaddr == 65039);
	bool cppVar_2857 = cppVar_2854 && cppVar_2856;
	return cppVar_2857;
}
bool model_sha::decode_8(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2283 = (sha_state == 3);
	bool cppVar_2285 = (cmd == 1);
	bool cppVar_2286 = cppVar_2283 && cppVar_2285;
	bool cppVar_2288 = (cmdaddr == 65025);
	bool cppVar_2289 = cppVar_2286 && cppVar_2288;
	return cppVar_2289;
}
bool model_sha::decode_80(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2859 = (sha_state == 0);
	bool cppVar_2861 = (cmd == 2);
	bool cppVar_2862 = cppVar_2859 && cppVar_2861;
	bool cppVar_2864 = (cmdaddr == 65024);
	bool cppVar_2865 = cppVar_2862 && cppVar_2864;
	return cppVar_2865;
}
bool model_sha::decode_81(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2867 = (sha_state == 0);
	bool cppVar_2869 = (cmd == 2);
	bool cppVar_2870 = cppVar_2867 && cppVar_2869;
	bool cppVar_2872 = (cmdaddr == 65025);
	bool cppVar_2873 = cppVar_2870 && cppVar_2872;
	return cppVar_2873;
}
bool model_sha::decode_82(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2875 = (sha_state == 0);
	bool cppVar_2877 = (cmd == 2);
	bool cppVar_2878 = cppVar_2875 && cppVar_2877;
	bool cppVar_2880 = (cmdaddr == 65026);
	bool cppVar_2881 = cppVar_2878 && cppVar_2880;
	return cppVar_2881;
}
bool model_sha::decode_83(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2883 = (sha_state == 0);
	bool cppVar_2885 = (cmd == 2);
	bool cppVar_2886 = cppVar_2883 && cppVar_2885;
	bool cppVar_2888 = (cmdaddr == 65027);
	bool cppVar_2889 = cppVar_2886 && cppVar_2888;
	return cppVar_2889;
}
bool model_sha::decode_84(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2891 = (sha_state == 0);
	bool cppVar_2893 = (cmd == 2);
	bool cppVar_2894 = cppVar_2891 && cppVar_2893;
	bool cppVar_2896 = (cmdaddr == 65028);
	bool cppVar_2897 = cppVar_2894 && cppVar_2896;
	return cppVar_2897;
}
bool model_sha::decode_85(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2899 = (sha_state == 0);
	bool cppVar_2901 = (cmd == 2);
	bool cppVar_2902 = cppVar_2899 && cppVar_2901;
	bool cppVar_2904 = (cmdaddr == 65029);
	bool cppVar_2905 = cppVar_2902 && cppVar_2904;
	return cppVar_2905;
}
bool model_sha::decode_86(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2907 = (sha_state == 0);
	bool cppVar_2909 = (cmd == 2);
	bool cppVar_2910 = cppVar_2907 && cppVar_2909;
	bool cppVar_2912 = (cmdaddr == 65030);
	bool cppVar_2913 = cppVar_2910 && cppVar_2912;
	return cppVar_2913;
}
bool model_sha::decode_87(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2915 = (sha_state == 0);
	bool cppVar_2917 = (cmd == 2);
	bool cppVar_2918 = cppVar_2915 && cppVar_2917;
	bool cppVar_2920 = (cmdaddr == 65031);
	bool cppVar_2921 = cppVar_2918 && cppVar_2920;
	return cppVar_2921;
}
bool model_sha::decode_88(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2923 = (sha_state == 0);
	bool cppVar_2925 = (cmd == 2);
	bool cppVar_2926 = cppVar_2923 && cppVar_2925;
	bool cppVar_2928 = (cmdaddr == 65032);
	bool cppVar_2929 = cppVar_2926 && cppVar_2928;
	return cppVar_2929;
}
bool model_sha::decode_89(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2931 = (sha_state == 0);
	bool cppVar_2933 = (cmd == 2);
	bool cppVar_2934 = cppVar_2931 && cppVar_2933;
	bool cppVar_2936 = (cmdaddr == 65033);
	bool cppVar_2937 = cppVar_2934 && cppVar_2936;
	return cppVar_2937;
}
bool model_sha::decode_9(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2291 = (sha_state == 4);
	bool cppVar_2293 = (cmd == 1);
	bool cppVar_2294 = cppVar_2291 && cppVar_2293;
	bool cppVar_2296 = (cmdaddr == 65025);
	bool cppVar_2297 = cppVar_2294 && cppVar_2296;
	return cppVar_2297;
}
bool model_sha::decode_90(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2939 = (sha_state == 0);
	bool cppVar_2941 = (cmd == 2);
	bool cppVar_2942 = cppVar_2939 && cppVar_2941;
	bool cppVar_2944 = (cmdaddr == 65034);
	bool cppVar_2945 = cppVar_2942 && cppVar_2944;
	return cppVar_2945;
}
bool model_sha::decode_91(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2947 = (sha_state == 0);
	bool cppVar_2949 = (cmd == 2);
	bool cppVar_2950 = cppVar_2947 && cppVar_2949;
	bool cppVar_2952 = (cmdaddr == 65035);
	bool cppVar_2953 = cppVar_2950 && cppVar_2952;
	return cppVar_2953;
}
bool model_sha::decode_92(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2955 = (sha_state == 0);
	bool cppVar_2957 = (cmd == 2);
	bool cppVar_2958 = cppVar_2955 && cppVar_2957;
	bool cppVar_2960 = (cmdaddr == 65036);
	bool cppVar_2961 = cppVar_2958 && cppVar_2960;
	return cppVar_2961;
}
bool model_sha::decode_93(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2963 = (sha_state == 0);
	bool cppVar_2965 = (cmd == 2);
	bool cppVar_2966 = cppVar_2963 && cppVar_2965;
	bool cppVar_2968 = (cmdaddr == 65037);
	bool cppVar_2969 = cppVar_2966 && cppVar_2968;
	return cppVar_2969;
}
bool model_sha::decode_94(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2971 = (sha_state == 0);
	bool cppVar_2973 = (cmd == 2);
	bool cppVar_2974 = cppVar_2971 && cppVar_2973;
	bool cppVar_2976 = (cmdaddr == 65038);
	bool cppVar_2977 = cppVar_2974 && cppVar_2976;
	return cppVar_2977;
}
bool model_sha::decode_95(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2979 = (sha_state == 0);
	bool cppVar_2981 = (cmd == 2);
	bool cppVar_2982 = cppVar_2979 && cppVar_2981;
	bool cppVar_2984 = (cmdaddr == 65039);
	bool cppVar_2985 = cppVar_2982 && cppVar_2984;
	return cppVar_2985;
}
bool model_sha::decode_96(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2987 = (sha_state == 1);
	bool cppVar_2989 = (cmd != 1);
	bool cppVar_2990 = cppVar_2987 && cppVar_2989;
	bool cppVar_2992 = (cmdaddr == 65024);
	bool cppVar_2993 = cppVar_2990 && cppVar_2992;
	return cppVar_2993;
}
bool model_sha::decode_97(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2995 = (sha_state == 2);
	bool cppVar_2997 = (cmd != 1);
	bool cppVar_2998 = cppVar_2995 && cppVar_2997;
	bool cppVar_3000 = (cmdaddr == 65024);
	bool cppVar_3001 = cppVar_2998 && cppVar_3000;
	return cppVar_3001;
}
bool model_sha::decode_98(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3003 = (sha_state == 3);
	bool cppVar_3005 = (cmd != 1);
	bool cppVar_3006 = cppVar_3003 && cppVar_3005;
	bool cppVar_3008 = (cmdaddr == 65024);
	bool cppVar_3009 = cppVar_3006 && cppVar_3008;
	return cppVar_3009;
}
bool model_sha::decode_99(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3011 = (sha_state == 4);
	bool cppVar_3013 = (cmd != 1);
	bool cppVar_3014 = cppVar_3011 && cppVar_3013;
	bool cppVar_3016 = (cmdaddr == 65024);
	bool cppVar_3017 = cppVar_3014 && cppVar_3016;
	return cppVar_3017;
}
BIT_VEC model_sha::fetch(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_2210 = (cmdaddr << 8) | cmddata;
	cppVar_2210 = (cppVar_2210 & cppMask_un_24_);
	BIT_VEC cppVar_2211 = (cmd << 24) | cppVar_2210;
	cppVar_2211 = (cppVar_2211 & cppMask_un_26_);
	BIT_VEC cppVar_2212 = (sha_state << 26) | cppVar_2211;
	cppVar_2212 = (cppVar_2212 & cppMask_un_29_);
	return cppVar_2212;
}
bool model_sha::fetchValid(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2214 = (cmd == 1);
	bool cppVar_2216 = (cmd == 2);
	bool cppVar_2217 = cppVar_2214 || cppVar_2216;
	return cppVar_2217;
}
void model_sha::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_16 = (sha_state == 4);
	bool cppVar_18 = (cmd == 1);
	bool cppVar_19 = cppVar_16 && cppVar_18;
	bool cppVar_21 = (cmdaddr == 65031);
	bool cppVar_22 = cppVar_19 && cppVar_21;
	bool cppVar_24 = (sha_state == 3);
	bool cppVar_26 = (cmd == 1);
	bool cppVar_27 = cppVar_24 && cppVar_26;
	bool cppVar_29 = (cmdaddr == 65031);
	bool cppVar_30 = cppVar_27 && cppVar_29;
	bool cppVar_32 = (sha_state == 2);
	bool cppVar_34 = (cmd == 1);
	bool cppVar_35 = cppVar_32 && cppVar_34;
	bool cppVar_37 = (cmdaddr == 65031);
	bool cppVar_38 = cppVar_35 && cppVar_37;
	bool cppVar_40 = (sha_state == 1);
	bool cppVar_42 = (cmd == 1);
	bool cppVar_43 = cppVar_40 && cppVar_42;
	bool cppVar_45 = (cmdaddr == 65031);
	bool cppVar_46 = cppVar_43 && cppVar_45;
	bool cppVar_48 = (sha_state == 0);
	bool cppVar_50 = (cmd == 1);
	bool cppVar_51 = cppVar_48 && cppVar_50;
	bool cppVar_53 = (cmdaddr == 65031);
	bool cppVar_54 = cppVar_51 && cppVar_53;
	bool cppVar_55 = cppVar_46 || cppVar_54;
	bool cppVar_56 = cppVar_38 || cppVar_55;
	bool cppVar_57 = cppVar_30 || cppVar_56;
	bool cppVar_58 = cppVar_22 || cppVar_57;
	BIT_VEC cppVar_59 = (sha_len >> 8) & cppMask_un_8_;
	bool cppVar_61 = (sha_state == 4);
	bool cppVar_63 = (cmd == 1);
	bool cppVar_64 = cppVar_61 && cppVar_63;
	bool cppVar_66 = (cmdaddr == 65030);
	bool cppVar_67 = cppVar_64 && cppVar_66;
	bool cppVar_69 = (sha_state == 3);
	bool cppVar_71 = (cmd == 1);
	bool cppVar_72 = cppVar_69 && cppVar_71;
	bool cppVar_74 = (cmdaddr == 65030);
	bool cppVar_75 = cppVar_72 && cppVar_74;
	bool cppVar_77 = (sha_state == 2);
	bool cppVar_79 = (cmd == 1);
	bool cppVar_80 = cppVar_77 && cppVar_79;
	bool cppVar_82 = (cmdaddr == 65030);
	bool cppVar_83 = cppVar_80 && cppVar_82;
	bool cppVar_85 = (sha_state == 1);
	bool cppVar_87 = (cmd == 1);
	bool cppVar_88 = cppVar_85 && cppVar_87;
	bool cppVar_90 = (cmdaddr == 65030);
	bool cppVar_91 = cppVar_88 && cppVar_90;
	bool cppVar_93 = (sha_state == 0);
	bool cppVar_95 = (cmd == 1);
	bool cppVar_96 = cppVar_93 && cppVar_95;
	bool cppVar_98 = (cmdaddr == 65030);
	bool cppVar_99 = cppVar_96 && cppVar_98;
	bool cppVar_100 = cppVar_91 || cppVar_99;
	bool cppVar_101 = cppVar_83 || cppVar_100;
	bool cppVar_102 = cppVar_75 || cppVar_101;
	bool cppVar_103 = cppVar_67 || cppVar_102;
	BIT_VEC cppVar_104 = (sha_len >> 0) & cppMask_un_8_;
	bool cppVar_106 = (sha_state == 4);
	bool cppVar_108 = (cmd == 1);
	bool cppVar_109 = cppVar_106 && cppVar_108;
	bool cppVar_111 = (cmdaddr == 65029);
	bool cppVar_112 = cppVar_109 && cppVar_111;
	bool cppVar_114 = (sha_state == 3);
	bool cppVar_116 = (cmd == 1);
	bool cppVar_117 = cppVar_114 && cppVar_116;
	bool cppVar_119 = (cmdaddr == 65029);
	bool cppVar_120 = cppVar_117 && cppVar_119;
	bool cppVar_122 = (sha_state == 2);
	bool cppVar_124 = (cmd == 1);
	bool cppVar_125 = cppVar_122 && cppVar_124;
	bool cppVar_127 = (cmdaddr == 65029);
	bool cppVar_128 = cppVar_125 && cppVar_127;
	bool cppVar_130 = (sha_state == 1);
	bool cppVar_132 = (cmd == 1);
	bool cppVar_133 = cppVar_130 && cppVar_132;
	bool cppVar_135 = (cmdaddr == 65029);
	bool cppVar_136 = cppVar_133 && cppVar_135;
	bool cppVar_138 = (sha_state == 0);
	bool cppVar_140 = (cmd == 1);
	bool cppVar_141 = cppVar_138 && cppVar_140;
	bool cppVar_143 = (cmdaddr == 65029);
	bool cppVar_144 = cppVar_141 && cppVar_143;
	bool cppVar_145 = cppVar_136 || cppVar_144;
	bool cppVar_146 = cppVar_128 || cppVar_145;
	bool cppVar_147 = cppVar_120 || cppVar_146;
	bool cppVar_148 = cppVar_112 || cppVar_147;
	BIT_VEC cppVar_149 = (sha_wraddr >> 8) & cppMask_un_8_;
	bool cppVar_151 = (sha_state == 4);
	bool cppVar_153 = (cmd == 1);
	bool cppVar_154 = cppVar_151 && cppVar_153;
	bool cppVar_156 = (cmdaddr == 65028);
	bool cppVar_157 = cppVar_154 && cppVar_156;
	bool cppVar_159 = (sha_state == 3);
	bool cppVar_161 = (cmd == 1);
	bool cppVar_162 = cppVar_159 && cppVar_161;
	bool cppVar_164 = (cmdaddr == 65028);
	bool cppVar_165 = cppVar_162 && cppVar_164;
	bool cppVar_167 = (sha_state == 2);
	bool cppVar_169 = (cmd == 1);
	bool cppVar_170 = cppVar_167 && cppVar_169;
	bool cppVar_172 = (cmdaddr == 65028);
	bool cppVar_173 = cppVar_170 && cppVar_172;
	bool cppVar_175 = (sha_state == 1);
	bool cppVar_177 = (cmd == 1);
	bool cppVar_178 = cppVar_175 && cppVar_177;
	bool cppVar_180 = (cmdaddr == 65028);
	bool cppVar_181 = cppVar_178 && cppVar_180;
	bool cppVar_183 = (sha_state == 0);
	bool cppVar_185 = (cmd == 1);
	bool cppVar_186 = cppVar_183 && cppVar_185;
	bool cppVar_188 = (cmdaddr == 65028);
	bool cppVar_189 = cppVar_186 && cppVar_188;
	bool cppVar_190 = cppVar_181 || cppVar_189;
	bool cppVar_191 = cppVar_173 || cppVar_190;
	bool cppVar_192 = cppVar_165 || cppVar_191;
	bool cppVar_193 = cppVar_157 || cppVar_192;
	BIT_VEC cppVar_194 = (sha_wraddr >> 0) & cppMask_un_8_;
	bool cppVar_196 = (sha_state == 4);
	bool cppVar_198 = (cmd == 1);
	bool cppVar_199 = cppVar_196 && cppVar_198;
	bool cppVar_201 = (cmdaddr == 65027);
	bool cppVar_202 = cppVar_199 && cppVar_201;
	bool cppVar_204 = (sha_state == 3);
	bool cppVar_206 = (cmd == 1);
	bool cppVar_207 = cppVar_204 && cppVar_206;
	bool cppVar_209 = (cmdaddr == 65027);
	bool cppVar_210 = cppVar_207 && cppVar_209;
	bool cppVar_212 = (sha_state == 2);
	bool cppVar_214 = (cmd == 1);
	bool cppVar_215 = cppVar_212 && cppVar_214;
	bool cppVar_217 = (cmdaddr == 65027);
	bool cppVar_218 = cppVar_215 && cppVar_217;
	bool cppVar_220 = (sha_state == 1);
	bool cppVar_222 = (cmd == 1);
	bool cppVar_223 = cppVar_220 && cppVar_222;
	bool cppVar_225 = (cmdaddr == 65027);
	bool cppVar_226 = cppVar_223 && cppVar_225;
	bool cppVar_228 = (sha_state == 0);
	bool cppVar_230 = (cmd == 1);
	bool cppVar_231 = cppVar_228 && cppVar_230;
	bool cppVar_233 = (cmdaddr == 65027);
	bool cppVar_234 = cppVar_231 && cppVar_233;
	bool cppVar_235 = cppVar_226 || cppVar_234;
	bool cppVar_236 = cppVar_218 || cppVar_235;
	bool cppVar_237 = cppVar_210 || cppVar_236;
	bool cppVar_238 = cppVar_202 || cppVar_237;
	BIT_VEC cppVar_239 = (sha_rdaddr >> 8) & cppMask_un_8_;
	bool cppVar_241 = (sha_state == 4);
	bool cppVar_243 = (cmd == 1);
	bool cppVar_244 = cppVar_241 && cppVar_243;
	bool cppVar_246 = (cmdaddr == 65026);
	bool cppVar_247 = cppVar_244 && cppVar_246;
	bool cppVar_249 = (sha_state == 3);
	bool cppVar_251 = (cmd == 1);
	bool cppVar_252 = cppVar_249 && cppVar_251;
	bool cppVar_254 = (cmdaddr == 65026);
	bool cppVar_255 = cppVar_252 && cppVar_254;
	bool cppVar_257 = (sha_state == 2);
	bool cppVar_259 = (cmd == 1);
	bool cppVar_260 = cppVar_257 && cppVar_259;
	bool cppVar_262 = (cmdaddr == 65026);
	bool cppVar_263 = cppVar_260 && cppVar_262;
	bool cppVar_265 = (sha_state == 1);
	bool cppVar_267 = (cmd == 1);
	bool cppVar_268 = cppVar_265 && cppVar_267;
	bool cppVar_270 = (cmdaddr == 65026);
	bool cppVar_271 = cppVar_268 && cppVar_270;
	bool cppVar_273 = (sha_state == 0);
	bool cppVar_275 = (cmd == 1);
	bool cppVar_276 = cppVar_273 && cppVar_275;
	bool cppVar_278 = (cmdaddr == 65026);
	bool cppVar_279 = cppVar_276 && cppVar_278;
	bool cppVar_280 = cppVar_271 || cppVar_279;
	bool cppVar_281 = cppVar_263 || cppVar_280;
	bool cppVar_282 = cppVar_255 || cppVar_281;
	bool cppVar_283 = cppVar_247 || cppVar_282;
	BIT_VEC cppVar_284 = (sha_rdaddr >> 0) & cppMask_un_8_;
	bool cppVar_286 = (sha_state == 0);
	bool cppVar_288 = (cmd == 1);
	bool cppVar_289 = cppVar_286 && cppVar_288;
	bool cppVar_291 = (cmdaddr == 65036);
	bool cppVar_292 = cppVar_289 && cppVar_291;
	bool cppVar_294 = (sha_state == 4);
	bool cppVar_296 = (cmd == 1);
	bool cppVar_297 = cppVar_294 && cppVar_296;
	bool cppVar_299 = (cmdaddr == 65025);
	bool cppVar_300 = cppVar_297 && cppVar_299;
	bool cppVar_302 = (sha_state == 3);
	bool cppVar_304 = (cmd == 1);
	bool cppVar_305 = cppVar_302 && cppVar_304;
	bool cppVar_307 = (cmdaddr == 65025);
	bool cppVar_308 = cppVar_305 && cppVar_307;
	bool cppVar_310 = (sha_state == 2);
	bool cppVar_312 = (cmd == 1);
	bool cppVar_313 = cppVar_310 && cppVar_312;
	bool cppVar_315 = (cmdaddr == 65025);
	bool cppVar_316 = cppVar_313 && cppVar_315;
	bool cppVar_318 = (sha_state == 1);
	bool cppVar_320 = (cmd == 1);
	bool cppVar_321 = cppVar_318 && cppVar_320;
	bool cppVar_323 = (cmdaddr == 65025);
	bool cppVar_324 = cppVar_321 && cppVar_323;
	bool cppVar_325 = cppVar_316 || cppVar_324;
	bool cppVar_326 = cppVar_308 || cppVar_325;
	bool cppVar_327 = cppVar_300 || cppVar_326;
	bool cppVar_328 = cppVar_292 || cppVar_327;
	BIT_VEC cppVar_329 = (sha_state & cppMask_un_3_);
	bool cppVar_331 = (sha_state == 4);
	bool cppVar_333 = (cmd != 1);
	bool cppVar_334 = cppVar_331 && cppVar_333;
	bool cppVar_336 = (cmdaddr == 65039);
	bool cppVar_337 = cppVar_334 && cppVar_336;
	bool cppVar_339 = (sha_state == 3);
	bool cppVar_341 = (cmd != 1);
	bool cppVar_342 = cppVar_339 && cppVar_341;
	bool cppVar_344 = (cmdaddr == 65039);
	bool cppVar_345 = cppVar_342 && cppVar_344;
	bool cppVar_347 = (sha_state == 2);
	bool cppVar_349 = (cmd != 1);
	bool cppVar_350 = cppVar_347 && cppVar_349;
	bool cppVar_352 = (cmdaddr == 65039);
	bool cppVar_353 = cppVar_350 && cppVar_352;
	bool cppVar_355 = (sha_state == 1);
	bool cppVar_357 = (cmd != 1);
	bool cppVar_358 = cppVar_355 && cppVar_357;
	bool cppVar_360 = (cmdaddr == 65039);
	bool cppVar_361 = cppVar_358 && cppVar_360;
	bool cppVar_363 = (sha_state == 4);
	bool cppVar_365 = (cmd != 1);
	bool cppVar_366 = cppVar_363 && cppVar_365;
	bool cppVar_368 = (cmdaddr == 65038);
	bool cppVar_369 = cppVar_366 && cppVar_368;
	bool cppVar_371 = (sha_state == 3);
	bool cppVar_373 = (cmd != 1);
	bool cppVar_374 = cppVar_371 && cppVar_373;
	bool cppVar_376 = (cmdaddr == 65038);
	bool cppVar_377 = cppVar_374 && cppVar_376;
	bool cppVar_379 = (sha_state == 2);
	bool cppVar_381 = (cmd != 1);
	bool cppVar_382 = cppVar_379 && cppVar_381;
	bool cppVar_384 = (cmdaddr == 65038);
	bool cppVar_385 = cppVar_382 && cppVar_384;
	bool cppVar_387 = (sha_state == 1);
	bool cppVar_389 = (cmd != 1);
	bool cppVar_390 = cppVar_387 && cppVar_389;
	bool cppVar_392 = (cmdaddr == 65038);
	bool cppVar_393 = cppVar_390 && cppVar_392;
	bool cppVar_395 = (sha_state == 4);
	bool cppVar_397 = (cmd != 1);
	bool cppVar_398 = cppVar_395 && cppVar_397;
	bool cppVar_400 = (cmdaddr == 65037);
	bool cppVar_401 = cppVar_398 && cppVar_400;
	bool cppVar_403 = (sha_state == 3);
	bool cppVar_405 = (cmd != 1);
	bool cppVar_406 = cppVar_403 && cppVar_405;
	bool cppVar_408 = (cmdaddr == 65037);
	bool cppVar_409 = cppVar_406 && cppVar_408;
	bool cppVar_411 = (sha_state == 2);
	bool cppVar_413 = (cmd != 1);
	bool cppVar_414 = cppVar_411 && cppVar_413;
	bool cppVar_416 = (cmdaddr == 65037);
	bool cppVar_417 = cppVar_414 && cppVar_416;
	bool cppVar_419 = (sha_state == 1);
	bool cppVar_421 = (cmd != 1);
	bool cppVar_422 = cppVar_419 && cppVar_421;
	bool cppVar_424 = (cmdaddr == 65037);
	bool cppVar_425 = cppVar_422 && cppVar_424;
	bool cppVar_427 = (sha_state == 4);
	bool cppVar_429 = (cmd != 1);
	bool cppVar_430 = cppVar_427 && cppVar_429;
	bool cppVar_432 = (cmdaddr == 65036);
	bool cppVar_433 = cppVar_430 && cppVar_432;
	bool cppVar_435 = (sha_state == 3);
	bool cppVar_437 = (cmd != 1);
	bool cppVar_438 = cppVar_435 && cppVar_437;
	bool cppVar_440 = (cmdaddr == 65036);
	bool cppVar_441 = cppVar_438 && cppVar_440;
	bool cppVar_443 = (sha_state == 2);
	bool cppVar_445 = (cmd != 1);
	bool cppVar_446 = cppVar_443 && cppVar_445;
	bool cppVar_448 = (cmdaddr == 65036);
	bool cppVar_449 = cppVar_446 && cppVar_448;
	bool cppVar_451 = (sha_state == 1);
	bool cppVar_453 = (cmd != 1);
	bool cppVar_454 = cppVar_451 && cppVar_453;
	bool cppVar_456 = (cmdaddr == 65036);
	bool cppVar_457 = cppVar_454 && cppVar_456;
	bool cppVar_459 = (sha_state == 4);
	bool cppVar_461 = (cmd != 1);
	bool cppVar_462 = cppVar_459 && cppVar_461;
	bool cppVar_464 = (cmdaddr == 65035);
	bool cppVar_465 = cppVar_462 && cppVar_464;
	bool cppVar_467 = (sha_state == 3);
	bool cppVar_469 = (cmd != 1);
	bool cppVar_470 = cppVar_467 && cppVar_469;
	bool cppVar_472 = (cmdaddr == 65035);
	bool cppVar_473 = cppVar_470 && cppVar_472;
	bool cppVar_475 = (sha_state == 2);
	bool cppVar_477 = (cmd != 1);
	bool cppVar_478 = cppVar_475 && cppVar_477;
	bool cppVar_480 = (cmdaddr == 65035);
	bool cppVar_481 = cppVar_478 && cppVar_480;
	bool cppVar_483 = (sha_state == 1);
	bool cppVar_485 = (cmd != 1);
	bool cppVar_486 = cppVar_483 && cppVar_485;
	bool cppVar_488 = (cmdaddr == 65035);
	bool cppVar_489 = cppVar_486 && cppVar_488;
	bool cppVar_491 = (sha_state == 4);
	bool cppVar_493 = (cmd != 1);
	bool cppVar_494 = cppVar_491 && cppVar_493;
	bool cppVar_496 = (cmdaddr == 65034);
	bool cppVar_497 = cppVar_494 && cppVar_496;
	bool cppVar_499 = (sha_state == 3);
	bool cppVar_501 = (cmd != 1);
	bool cppVar_502 = cppVar_499 && cppVar_501;
	bool cppVar_504 = (cmdaddr == 65034);
	bool cppVar_505 = cppVar_502 && cppVar_504;
	bool cppVar_507 = (sha_state == 2);
	bool cppVar_509 = (cmd != 1);
	bool cppVar_510 = cppVar_507 && cppVar_509;
	bool cppVar_512 = (cmdaddr == 65034);
	bool cppVar_513 = cppVar_510 && cppVar_512;
	bool cppVar_515 = (sha_state == 1);
	bool cppVar_517 = (cmd != 1);
	bool cppVar_518 = cppVar_515 && cppVar_517;
	bool cppVar_520 = (cmdaddr == 65034);
	bool cppVar_521 = cppVar_518 && cppVar_520;
	bool cppVar_523 = (sha_state == 4);
	bool cppVar_525 = (cmd != 1);
	bool cppVar_526 = cppVar_523 && cppVar_525;
	bool cppVar_528 = (cmdaddr == 65033);
	bool cppVar_529 = cppVar_526 && cppVar_528;
	bool cppVar_531 = (sha_state == 3);
	bool cppVar_533 = (cmd != 1);
	bool cppVar_534 = cppVar_531 && cppVar_533;
	bool cppVar_536 = (cmdaddr == 65033);
	bool cppVar_537 = cppVar_534 && cppVar_536;
	bool cppVar_539 = (sha_state == 2);
	bool cppVar_541 = (cmd != 1);
	bool cppVar_542 = cppVar_539 && cppVar_541;
	bool cppVar_544 = (cmdaddr == 65033);
	bool cppVar_545 = cppVar_542 && cppVar_544;
	bool cppVar_547 = (sha_state == 1);
	bool cppVar_549 = (cmd != 1);
	bool cppVar_550 = cppVar_547 && cppVar_549;
	bool cppVar_552 = (cmdaddr == 65033);
	bool cppVar_553 = cppVar_550 && cppVar_552;
	bool cppVar_555 = (sha_state == 4);
	bool cppVar_557 = (cmd != 1);
	bool cppVar_558 = cppVar_555 && cppVar_557;
	bool cppVar_560 = (cmdaddr == 65032);
	bool cppVar_561 = cppVar_558 && cppVar_560;
	bool cppVar_563 = (sha_state == 3);
	bool cppVar_565 = (cmd != 1);
	bool cppVar_566 = cppVar_563 && cppVar_565;
	bool cppVar_568 = (cmdaddr == 65032);
	bool cppVar_569 = cppVar_566 && cppVar_568;
	bool cppVar_571 = (sha_state == 2);
	bool cppVar_573 = (cmd != 1);
	bool cppVar_574 = cppVar_571 && cppVar_573;
	bool cppVar_576 = (cmdaddr == 65032);
	bool cppVar_577 = cppVar_574 && cppVar_576;
	bool cppVar_579 = (sha_state == 1);
	bool cppVar_581 = (cmd != 1);
	bool cppVar_582 = cppVar_579 && cppVar_581;
	bool cppVar_584 = (cmdaddr == 65032);
	bool cppVar_585 = cppVar_582 && cppVar_584;
	bool cppVar_587 = (sha_state == 4);
	bool cppVar_589 = (cmd != 1);
	bool cppVar_590 = cppVar_587 && cppVar_589;
	bool cppVar_592 = (cmdaddr == 65031);
	bool cppVar_593 = cppVar_590 && cppVar_592;
	bool cppVar_595 = (sha_state == 3);
	bool cppVar_597 = (cmd != 1);
	bool cppVar_598 = cppVar_595 && cppVar_597;
	bool cppVar_600 = (cmdaddr == 65031);
	bool cppVar_601 = cppVar_598 && cppVar_600;
	bool cppVar_603 = (sha_state == 2);
	bool cppVar_605 = (cmd != 1);
	bool cppVar_606 = cppVar_603 && cppVar_605;
	bool cppVar_608 = (cmdaddr == 65031);
	bool cppVar_609 = cppVar_606 && cppVar_608;
	bool cppVar_611 = (sha_state == 1);
	bool cppVar_613 = (cmd != 1);
	bool cppVar_614 = cppVar_611 && cppVar_613;
	bool cppVar_616 = (cmdaddr == 65031);
	bool cppVar_617 = cppVar_614 && cppVar_616;
	bool cppVar_619 = (sha_state == 4);
	bool cppVar_621 = (cmd != 1);
	bool cppVar_622 = cppVar_619 && cppVar_621;
	bool cppVar_624 = (cmdaddr == 65030);
	bool cppVar_625 = cppVar_622 && cppVar_624;
	bool cppVar_627 = (sha_state == 3);
	bool cppVar_629 = (cmd != 1);
	bool cppVar_630 = cppVar_627 && cppVar_629;
	bool cppVar_632 = (cmdaddr == 65030);
	bool cppVar_633 = cppVar_630 && cppVar_632;
	bool cppVar_635 = (sha_state == 2);
	bool cppVar_637 = (cmd != 1);
	bool cppVar_638 = cppVar_635 && cppVar_637;
	bool cppVar_640 = (cmdaddr == 65030);
	bool cppVar_641 = cppVar_638 && cppVar_640;
	bool cppVar_643 = (sha_state == 1);
	bool cppVar_645 = (cmd != 1);
	bool cppVar_646 = cppVar_643 && cppVar_645;
	bool cppVar_648 = (cmdaddr == 65030);
	bool cppVar_649 = cppVar_646 && cppVar_648;
	bool cppVar_651 = (sha_state == 4);
	bool cppVar_653 = (cmd != 1);
	bool cppVar_654 = cppVar_651 && cppVar_653;
	bool cppVar_656 = (cmdaddr == 65029);
	bool cppVar_657 = cppVar_654 && cppVar_656;
	bool cppVar_659 = (sha_state == 3);
	bool cppVar_661 = (cmd != 1);
	bool cppVar_662 = cppVar_659 && cppVar_661;
	bool cppVar_664 = (cmdaddr == 65029);
	bool cppVar_665 = cppVar_662 && cppVar_664;
	bool cppVar_667 = (sha_state == 2);
	bool cppVar_669 = (cmd != 1);
	bool cppVar_670 = cppVar_667 && cppVar_669;
	bool cppVar_672 = (cmdaddr == 65029);
	bool cppVar_673 = cppVar_670 && cppVar_672;
	bool cppVar_675 = (sha_state == 1);
	bool cppVar_677 = (cmd != 1);
	bool cppVar_678 = cppVar_675 && cppVar_677;
	bool cppVar_680 = (cmdaddr == 65029);
	bool cppVar_681 = cppVar_678 && cppVar_680;
	bool cppVar_683 = (sha_state == 4);
	bool cppVar_685 = (cmd != 1);
	bool cppVar_686 = cppVar_683 && cppVar_685;
	bool cppVar_688 = (cmdaddr == 65028);
	bool cppVar_689 = cppVar_686 && cppVar_688;
	bool cppVar_691 = (sha_state == 3);
	bool cppVar_693 = (cmd != 1);
	bool cppVar_694 = cppVar_691 && cppVar_693;
	bool cppVar_696 = (cmdaddr == 65028);
	bool cppVar_697 = cppVar_694 && cppVar_696;
	bool cppVar_699 = (sha_state == 2);
	bool cppVar_701 = (cmd != 1);
	bool cppVar_702 = cppVar_699 && cppVar_701;
	bool cppVar_704 = (cmdaddr == 65028);
	bool cppVar_705 = cppVar_702 && cppVar_704;
	bool cppVar_707 = (sha_state == 1);
	bool cppVar_709 = (cmd != 1);
	bool cppVar_710 = cppVar_707 && cppVar_709;
	bool cppVar_712 = (cmdaddr == 65028);
	bool cppVar_713 = cppVar_710 && cppVar_712;
	bool cppVar_715 = (sha_state == 4);
	bool cppVar_717 = (cmd != 1);
	bool cppVar_718 = cppVar_715 && cppVar_717;
	bool cppVar_720 = (cmdaddr == 65027);
	bool cppVar_721 = cppVar_718 && cppVar_720;
	bool cppVar_723 = (sha_state == 3);
	bool cppVar_725 = (cmd != 1);
	bool cppVar_726 = cppVar_723 && cppVar_725;
	bool cppVar_728 = (cmdaddr == 65027);
	bool cppVar_729 = cppVar_726 && cppVar_728;
	bool cppVar_731 = (sha_state == 2);
	bool cppVar_733 = (cmd != 1);
	bool cppVar_734 = cppVar_731 && cppVar_733;
	bool cppVar_736 = (cmdaddr == 65027);
	bool cppVar_737 = cppVar_734 && cppVar_736;
	bool cppVar_739 = (sha_state == 1);
	bool cppVar_741 = (cmd != 1);
	bool cppVar_742 = cppVar_739 && cppVar_741;
	bool cppVar_744 = (cmdaddr == 65027);
	bool cppVar_745 = cppVar_742 && cppVar_744;
	bool cppVar_747 = (sha_state == 4);
	bool cppVar_749 = (cmd != 1);
	bool cppVar_750 = cppVar_747 && cppVar_749;
	bool cppVar_752 = (cmdaddr == 65026);
	bool cppVar_753 = cppVar_750 && cppVar_752;
	bool cppVar_755 = (sha_state == 3);
	bool cppVar_757 = (cmd != 1);
	bool cppVar_758 = cppVar_755 && cppVar_757;
	bool cppVar_760 = (cmdaddr == 65026);
	bool cppVar_761 = cppVar_758 && cppVar_760;
	bool cppVar_763 = (sha_state == 2);
	bool cppVar_765 = (cmd != 1);
	bool cppVar_766 = cppVar_763 && cppVar_765;
	bool cppVar_768 = (cmdaddr == 65026);
	bool cppVar_769 = cppVar_766 && cppVar_768;
	bool cppVar_771 = (sha_state == 1);
	bool cppVar_773 = (cmd != 1);
	bool cppVar_774 = cppVar_771 && cppVar_773;
	bool cppVar_776 = (cmdaddr == 65026);
	bool cppVar_777 = cppVar_774 && cppVar_776;
	bool cppVar_779 = (sha_state == 4);
	bool cppVar_781 = (cmd != 1);
	bool cppVar_782 = cppVar_779 && cppVar_781;
	bool cppVar_784 = (cmdaddr == 65025);
	bool cppVar_785 = cppVar_782 && cppVar_784;
	bool cppVar_787 = (sha_state == 3);
	bool cppVar_789 = (cmd != 1);
	bool cppVar_790 = cppVar_787 && cppVar_789;
	bool cppVar_792 = (cmdaddr == 65025);
	bool cppVar_793 = cppVar_790 && cppVar_792;
	bool cppVar_795 = (sha_state == 2);
	bool cppVar_797 = (cmd != 1);
	bool cppVar_798 = cppVar_795 && cppVar_797;
	bool cppVar_800 = (cmdaddr == 65025);
	bool cppVar_801 = cppVar_798 && cppVar_800;
	bool cppVar_803 = (sha_state == 1);
	bool cppVar_805 = (cmd != 1);
	bool cppVar_806 = cppVar_803 && cppVar_805;
	bool cppVar_808 = (cmdaddr == 65025);
	bool cppVar_809 = cppVar_806 && cppVar_808;
	bool cppVar_811 = (sha_state == 4);
	bool cppVar_813 = (cmd != 1);
	bool cppVar_814 = cppVar_811 && cppVar_813;
	bool cppVar_816 = (cmdaddr == 65024);
	bool cppVar_817 = cppVar_814 && cppVar_816;
	bool cppVar_819 = (sha_state == 3);
	bool cppVar_821 = (cmd != 1);
	bool cppVar_822 = cppVar_819 && cppVar_821;
	bool cppVar_824 = (cmdaddr == 65024);
	bool cppVar_825 = cppVar_822 && cppVar_824;
	bool cppVar_827 = (sha_state == 2);
	bool cppVar_829 = (cmd != 1);
	bool cppVar_830 = cppVar_827 && cppVar_829;
	bool cppVar_832 = (cmdaddr == 65024);
	bool cppVar_833 = cppVar_830 && cppVar_832;
	bool cppVar_835 = (sha_state == 1);
	bool cppVar_837 = (cmd != 1);
	bool cppVar_838 = cppVar_835 && cppVar_837;
	bool cppVar_840 = (cmdaddr == 65024);
	bool cppVar_841 = cppVar_838 && cppVar_840;
	bool cppVar_843 = (sha_state == 0);
	bool cppVar_845 = (cmd == 2);
	bool cppVar_846 = cppVar_843 && cppVar_845;
	bool cppVar_848 = (cmdaddr == 65039);
	bool cppVar_849 = cppVar_846 && cppVar_848;
	bool cppVar_851 = (sha_state == 0);
	bool cppVar_853 = (cmd == 2);
	bool cppVar_854 = cppVar_851 && cppVar_853;
	bool cppVar_856 = (cmdaddr == 65038);
	bool cppVar_857 = cppVar_854 && cppVar_856;
	bool cppVar_859 = (sha_state == 0);
	bool cppVar_861 = (cmd == 2);
	bool cppVar_862 = cppVar_859 && cppVar_861;
	bool cppVar_864 = (cmdaddr == 65037);
	bool cppVar_865 = cppVar_862 && cppVar_864;
	bool cppVar_867 = (sha_state == 0);
	bool cppVar_869 = (cmd == 2);
	bool cppVar_870 = cppVar_867 && cppVar_869;
	bool cppVar_872 = (cmdaddr == 65036);
	bool cppVar_873 = cppVar_870 && cppVar_872;
	bool cppVar_875 = (sha_state == 0);
	bool cppVar_877 = (cmd == 2);
	bool cppVar_878 = cppVar_875 && cppVar_877;
	bool cppVar_880 = (cmdaddr == 65035);
	bool cppVar_881 = cppVar_878 && cppVar_880;
	bool cppVar_883 = (sha_state == 0);
	bool cppVar_885 = (cmd == 2);
	bool cppVar_886 = cppVar_883 && cppVar_885;
	bool cppVar_888 = (cmdaddr == 65034);
	bool cppVar_889 = cppVar_886 && cppVar_888;
	bool cppVar_891 = (sha_state == 0);
	bool cppVar_893 = (cmd == 2);
	bool cppVar_894 = cppVar_891 && cppVar_893;
	bool cppVar_896 = (cmdaddr == 65033);
	bool cppVar_897 = cppVar_894 && cppVar_896;
	bool cppVar_899 = (sha_state == 0);
	bool cppVar_901 = (cmd == 2);
	bool cppVar_902 = cppVar_899 && cppVar_901;
	bool cppVar_904 = (cmdaddr == 65032);
	bool cppVar_905 = cppVar_902 && cppVar_904;
	bool cppVar_907 = (sha_state == 0);
	bool cppVar_909 = (cmd == 2);
	bool cppVar_910 = cppVar_907 && cppVar_909;
	bool cppVar_912 = (cmdaddr == 65031);
	bool cppVar_913 = cppVar_910 && cppVar_912;
	bool cppVar_915 = (sha_state == 0);
	bool cppVar_917 = (cmd == 2);
	bool cppVar_918 = cppVar_915 && cppVar_917;
	bool cppVar_920 = (cmdaddr == 65030);
	bool cppVar_921 = cppVar_918 && cppVar_920;
	bool cppVar_923 = (sha_state == 0);
	bool cppVar_925 = (cmd == 2);
	bool cppVar_926 = cppVar_923 && cppVar_925;
	bool cppVar_928 = (cmdaddr == 65029);
	bool cppVar_929 = cppVar_926 && cppVar_928;
	bool cppVar_931 = (sha_state == 0);
	bool cppVar_933 = (cmd == 2);
	bool cppVar_934 = cppVar_931 && cppVar_933;
	bool cppVar_936 = (cmdaddr == 65028);
	bool cppVar_937 = cppVar_934 && cppVar_936;
	bool cppVar_939 = (sha_state == 0);
	bool cppVar_941 = (cmd == 2);
	bool cppVar_942 = cppVar_939 && cppVar_941;
	bool cppVar_944 = (cmdaddr == 65027);
	bool cppVar_945 = cppVar_942 && cppVar_944;
	bool cppVar_947 = (sha_state == 0);
	bool cppVar_949 = (cmd == 2);
	bool cppVar_950 = cppVar_947 && cppVar_949;
	bool cppVar_952 = (cmdaddr == 65026);
	bool cppVar_953 = cppVar_950 && cppVar_952;
	bool cppVar_955 = (sha_state == 0);
	bool cppVar_957 = (cmd == 2);
	bool cppVar_958 = cppVar_955 && cppVar_957;
	bool cppVar_960 = (cmdaddr == 65025);
	bool cppVar_961 = cppVar_958 && cppVar_960;
	bool cppVar_963 = (sha_state == 0);
	bool cppVar_965 = (cmd == 2);
	bool cppVar_966 = cppVar_963 && cppVar_965;
	bool cppVar_968 = (cmdaddr == 65024);
	bool cppVar_969 = cppVar_966 && cppVar_968;
	bool cppVar_971 = (sha_state == 4);
	bool cppVar_973 = (cmd == 1);
	bool cppVar_974 = cppVar_971 && cppVar_973;
	bool cppVar_976 = (cmdaddr == 65039);
	bool cppVar_977 = cppVar_974 && cppVar_976;
	bool cppVar_979 = (sha_state == 3);
	bool cppVar_981 = (cmd == 1);
	bool cppVar_982 = cppVar_979 && cppVar_981;
	bool cppVar_984 = (cmdaddr == 65039);
	bool cppVar_985 = cppVar_982 && cppVar_984;
	bool cppVar_987 = (sha_state == 2);
	bool cppVar_989 = (cmd == 1);
	bool cppVar_990 = cppVar_987 && cppVar_989;
	bool cppVar_992 = (cmdaddr == 65039);
	bool cppVar_993 = cppVar_990 && cppVar_992;
	bool cppVar_995 = (sha_state == 1);
	bool cppVar_997 = (cmd == 1);
	bool cppVar_998 = cppVar_995 && cppVar_997;
	bool cppVar_1000 = (cmdaddr == 65039);
	bool cppVar_1001 = cppVar_998 && cppVar_1000;
	bool cppVar_1003 = (sha_state == 0);
	bool cppVar_1005 = (cmd == 1);
	bool cppVar_1006 = cppVar_1003 && cppVar_1005;
	bool cppVar_1008 = (cmdaddr == 65039);
	bool cppVar_1009 = cppVar_1006 && cppVar_1008;
	bool cppVar_1011 = (sha_state == 4);
	bool cppVar_1013 = (cmd == 1);
	bool cppVar_1014 = cppVar_1011 && cppVar_1013;
	bool cppVar_1016 = (cmdaddr == 65038);
	bool cppVar_1017 = cppVar_1014 && cppVar_1016;
	bool cppVar_1019 = (sha_state == 3);
	bool cppVar_1021 = (cmd == 1);
	bool cppVar_1022 = cppVar_1019 && cppVar_1021;
	bool cppVar_1024 = (cmdaddr == 65038);
	bool cppVar_1025 = cppVar_1022 && cppVar_1024;
	bool cppVar_1027 = (sha_state == 2);
	bool cppVar_1029 = (cmd == 1);
	bool cppVar_1030 = cppVar_1027 && cppVar_1029;
	bool cppVar_1032 = (cmdaddr == 65038);
	bool cppVar_1033 = cppVar_1030 && cppVar_1032;
	bool cppVar_1035 = (sha_state == 1);
	bool cppVar_1037 = (cmd == 1);
	bool cppVar_1038 = cppVar_1035 && cppVar_1037;
	bool cppVar_1040 = (cmdaddr == 65038);
	bool cppVar_1041 = cppVar_1038 && cppVar_1040;
	bool cppVar_1043 = (sha_state == 0);
	bool cppVar_1045 = (cmd == 1);
	bool cppVar_1046 = cppVar_1043 && cppVar_1045;
	bool cppVar_1048 = (cmdaddr == 65038);
	bool cppVar_1049 = cppVar_1046 && cppVar_1048;
	bool cppVar_1051 = (sha_state == 4);
	bool cppVar_1053 = (cmd == 1);
	bool cppVar_1054 = cppVar_1051 && cppVar_1053;
	bool cppVar_1056 = (cmdaddr == 65037);
	bool cppVar_1057 = cppVar_1054 && cppVar_1056;
	bool cppVar_1059 = (sha_state == 3);
	bool cppVar_1061 = (cmd == 1);
	bool cppVar_1062 = cppVar_1059 && cppVar_1061;
	bool cppVar_1064 = (cmdaddr == 65037);
	bool cppVar_1065 = cppVar_1062 && cppVar_1064;
	bool cppVar_1067 = (sha_state == 2);
	bool cppVar_1069 = (cmd == 1);
	bool cppVar_1070 = cppVar_1067 && cppVar_1069;
	bool cppVar_1072 = (cmdaddr == 65037);
	bool cppVar_1073 = cppVar_1070 && cppVar_1072;
	bool cppVar_1075 = (sha_state == 1);
	bool cppVar_1077 = (cmd == 1);
	bool cppVar_1078 = cppVar_1075 && cppVar_1077;
	bool cppVar_1080 = (cmdaddr == 65037);
	bool cppVar_1081 = cppVar_1078 && cppVar_1080;
	bool cppVar_1083 = (sha_state == 0);
	bool cppVar_1085 = (cmd == 1);
	bool cppVar_1086 = cppVar_1083 && cppVar_1085;
	bool cppVar_1088 = (cmdaddr == 65037);
	bool cppVar_1089 = cppVar_1086 && cppVar_1088;
	bool cppVar_1091 = (sha_state == 4);
	bool cppVar_1093 = (cmd == 1);
	bool cppVar_1094 = cppVar_1091 && cppVar_1093;
	bool cppVar_1096 = (cmdaddr == 65036);
	bool cppVar_1097 = cppVar_1094 && cppVar_1096;
	bool cppVar_1099 = (sha_state == 3);
	bool cppVar_1101 = (cmd == 1);
	bool cppVar_1102 = cppVar_1099 && cppVar_1101;
	bool cppVar_1104 = (cmdaddr == 65036);
	bool cppVar_1105 = cppVar_1102 && cppVar_1104;
	bool cppVar_1107 = (sha_state == 2);
	bool cppVar_1109 = (cmd == 1);
	bool cppVar_1110 = cppVar_1107 && cppVar_1109;
	bool cppVar_1112 = (cmdaddr == 65036);
	bool cppVar_1113 = cppVar_1110 && cppVar_1112;
	bool cppVar_1115 = (sha_state == 1);
	bool cppVar_1117 = (cmd == 1);
	bool cppVar_1118 = cppVar_1115 && cppVar_1117;
	bool cppVar_1120 = (cmdaddr == 65036);
	bool cppVar_1121 = cppVar_1118 && cppVar_1120;
	bool cppVar_1123 = (sha_state == 4);
	bool cppVar_1125 = (cmd == 1);
	bool cppVar_1126 = cppVar_1123 && cppVar_1125;
	bool cppVar_1128 = (cmdaddr == 65035);
	bool cppVar_1129 = cppVar_1126 && cppVar_1128;
	bool cppVar_1131 = (sha_state == 3);
	bool cppVar_1133 = (cmd == 1);
	bool cppVar_1134 = cppVar_1131 && cppVar_1133;
	bool cppVar_1136 = (cmdaddr == 65035);
	bool cppVar_1137 = cppVar_1134 && cppVar_1136;
	bool cppVar_1139 = (sha_state == 2);
	bool cppVar_1141 = (cmd == 1);
	bool cppVar_1142 = cppVar_1139 && cppVar_1141;
	bool cppVar_1144 = (cmdaddr == 65035);
	bool cppVar_1145 = cppVar_1142 && cppVar_1144;
	bool cppVar_1147 = (sha_state == 1);
	bool cppVar_1149 = (cmd == 1);
	bool cppVar_1150 = cppVar_1147 && cppVar_1149;
	bool cppVar_1152 = (cmdaddr == 65035);
	bool cppVar_1153 = cppVar_1150 && cppVar_1152;
	bool cppVar_1155 = (sha_state == 0);
	bool cppVar_1157 = (cmd == 1);
	bool cppVar_1158 = cppVar_1155 && cppVar_1157;
	bool cppVar_1160 = (cmdaddr == 65035);
	bool cppVar_1161 = cppVar_1158 && cppVar_1160;
	bool cppVar_1163 = (sha_state == 4);
	bool cppVar_1165 = (cmd == 1);
	bool cppVar_1166 = cppVar_1163 && cppVar_1165;
	bool cppVar_1168 = (cmdaddr == 65034);
	bool cppVar_1169 = cppVar_1166 && cppVar_1168;
	bool cppVar_1171 = (sha_state == 3);
	bool cppVar_1173 = (cmd == 1);
	bool cppVar_1174 = cppVar_1171 && cppVar_1173;
	bool cppVar_1176 = (cmdaddr == 65034);
	bool cppVar_1177 = cppVar_1174 && cppVar_1176;
	bool cppVar_1179 = (sha_state == 2);
	bool cppVar_1181 = (cmd == 1);
	bool cppVar_1182 = cppVar_1179 && cppVar_1181;
	bool cppVar_1184 = (cmdaddr == 65034);
	bool cppVar_1185 = cppVar_1182 && cppVar_1184;
	bool cppVar_1187 = (sha_state == 1);
	bool cppVar_1189 = (cmd == 1);
	bool cppVar_1190 = cppVar_1187 && cppVar_1189;
	bool cppVar_1192 = (cmdaddr == 65034);
	bool cppVar_1193 = cppVar_1190 && cppVar_1192;
	bool cppVar_1195 = (sha_state == 0);
	bool cppVar_1197 = (cmd == 1);
	bool cppVar_1198 = cppVar_1195 && cppVar_1197;
	bool cppVar_1200 = (cmdaddr == 65034);
	bool cppVar_1201 = cppVar_1198 && cppVar_1200;
	bool cppVar_1203 = (sha_state == 4);
	bool cppVar_1205 = (cmd == 1);
	bool cppVar_1206 = cppVar_1203 && cppVar_1205;
	bool cppVar_1208 = (cmdaddr == 65033);
	bool cppVar_1209 = cppVar_1206 && cppVar_1208;
	bool cppVar_1211 = (sha_state == 3);
	bool cppVar_1213 = (cmd == 1);
	bool cppVar_1214 = cppVar_1211 && cppVar_1213;
	bool cppVar_1216 = (cmdaddr == 65033);
	bool cppVar_1217 = cppVar_1214 && cppVar_1216;
	bool cppVar_1219 = (sha_state == 2);
	bool cppVar_1221 = (cmd == 1);
	bool cppVar_1222 = cppVar_1219 && cppVar_1221;
	bool cppVar_1224 = (cmdaddr == 65033);
	bool cppVar_1225 = cppVar_1222 && cppVar_1224;
	bool cppVar_1227 = (sha_state == 1);
	bool cppVar_1229 = (cmd == 1);
	bool cppVar_1230 = cppVar_1227 && cppVar_1229;
	bool cppVar_1232 = (cmdaddr == 65033);
	bool cppVar_1233 = cppVar_1230 && cppVar_1232;
	bool cppVar_1235 = (sha_state == 0);
	bool cppVar_1237 = (cmd == 1);
	bool cppVar_1238 = cppVar_1235 && cppVar_1237;
	bool cppVar_1240 = (cmdaddr == 65033);
	bool cppVar_1241 = cppVar_1238 && cppVar_1240;
	bool cppVar_1243 = (sha_state == 4);
	bool cppVar_1245 = (cmd == 1);
	bool cppVar_1246 = cppVar_1243 && cppVar_1245;
	bool cppVar_1248 = (cmdaddr == 65032);
	bool cppVar_1249 = cppVar_1246 && cppVar_1248;
	bool cppVar_1251 = (sha_state == 3);
	bool cppVar_1253 = (cmd == 1);
	bool cppVar_1254 = cppVar_1251 && cppVar_1253;
	bool cppVar_1256 = (cmdaddr == 65032);
	bool cppVar_1257 = cppVar_1254 && cppVar_1256;
	bool cppVar_1259 = (sha_state == 2);
	bool cppVar_1261 = (cmd == 1);
	bool cppVar_1262 = cppVar_1259 && cppVar_1261;
	bool cppVar_1264 = (cmdaddr == 65032);
	bool cppVar_1265 = cppVar_1262 && cppVar_1264;
	bool cppVar_1267 = (sha_state == 1);
	bool cppVar_1269 = (cmd == 1);
	bool cppVar_1270 = cppVar_1267 && cppVar_1269;
	bool cppVar_1272 = (cmdaddr == 65032);
	bool cppVar_1273 = cppVar_1270 && cppVar_1272;
	bool cppVar_1275 = (sha_state == 0);
	bool cppVar_1277 = (cmd == 1);
	bool cppVar_1278 = cppVar_1275 && cppVar_1277;
	bool cppVar_1280 = (cmdaddr == 65032);
	bool cppVar_1281 = cppVar_1278 && cppVar_1280;
	bool cppVar_1283 = (sha_state == 0);
	bool cppVar_1285 = (cmd == 1);
	bool cppVar_1286 = cppVar_1283 && cppVar_1285;
	bool cppVar_1288 = (cmdaddr == 65025);
	bool cppVar_1289 = cppVar_1286 && cppVar_1288;
	bool cppVar_1291 = (sha_state == 4);
	bool cppVar_1293 = (cmd == 1);
	bool cppVar_1294 = cppVar_1291 && cppVar_1293;
	bool cppVar_1296 = (cmdaddr == 65024);
	bool cppVar_1297 = cppVar_1294 && cppVar_1296;
	bool cppVar_1299 = (sha_state == 3);
	bool cppVar_1301 = (cmd == 1);
	bool cppVar_1302 = cppVar_1299 && cppVar_1301;
	bool cppVar_1304 = (cmdaddr == 65024);
	bool cppVar_1305 = cppVar_1302 && cppVar_1304;
	bool cppVar_1307 = (sha_state == 2);
	bool cppVar_1309 = (cmd == 1);
	bool cppVar_1310 = cppVar_1307 && cppVar_1309;
	bool cppVar_1312 = (cmdaddr == 65024);
	bool cppVar_1313 = cppVar_1310 && cppVar_1312;
	bool cppVar_1315 = (sha_state == 1);
	bool cppVar_1317 = (cmd == 1);
	bool cppVar_1318 = cppVar_1315 && cppVar_1317;
	bool cppVar_1320 = (cmdaddr == 65024);
	bool cppVar_1321 = cppVar_1318 && cppVar_1320;
	bool cppVar_1323 = (sha_state == 0);
	bool cppVar_1325 = (cmd == 1);
	bool cppVar_1326 = cppVar_1323 && cppVar_1325;
	bool cppVar_1328 = (cmdaddr == 65024);
	bool cppVar_1329 = cppVar_1326 && cppVar_1328;
	bool cppVar_1330 = cppVar_1321 || cppVar_1329;
	bool cppVar_1331 = cppVar_1313 || cppVar_1330;
	bool cppVar_1332 = cppVar_1305 || cppVar_1331;
	bool cppVar_1333 = cppVar_1297 || cppVar_1332;
	bool cppVar_1334 = cppVar_1289 || cppVar_1333;
	bool cppVar_1335 = cppVar_1281 || cppVar_1334;
	bool cppVar_1336 = cppVar_1273 || cppVar_1335;
	bool cppVar_1337 = cppVar_1265 || cppVar_1336;
	bool cppVar_1338 = cppVar_1257 || cppVar_1337;
	bool cppVar_1339 = cppVar_1249 || cppVar_1338;
	bool cppVar_1340 = cppVar_1241 || cppVar_1339;
	bool cppVar_1341 = cppVar_1233 || cppVar_1340;
	bool cppVar_1342 = cppVar_1225 || cppVar_1341;
	bool cppVar_1343 = cppVar_1217 || cppVar_1342;
	bool cppVar_1344 = cppVar_1209 || cppVar_1343;
	bool cppVar_1345 = cppVar_1201 || cppVar_1344;
	bool cppVar_1346 = cppVar_1193 || cppVar_1345;
	bool cppVar_1347 = cppVar_1185 || cppVar_1346;
	bool cppVar_1348 = cppVar_1177 || cppVar_1347;
	bool cppVar_1349 = cppVar_1169 || cppVar_1348;
	bool cppVar_1350 = cppVar_1161 || cppVar_1349;
	bool cppVar_1351 = cppVar_1153 || cppVar_1350;
	bool cppVar_1352 = cppVar_1145 || cppVar_1351;
	bool cppVar_1353 = cppVar_1137 || cppVar_1352;
	bool cppVar_1354 = cppVar_1129 || cppVar_1353;
	bool cppVar_1355 = cppVar_1121 || cppVar_1354;
	bool cppVar_1356 = cppVar_1113 || cppVar_1355;
	bool cppVar_1357 = cppVar_1105 || cppVar_1356;
	bool cppVar_1358 = cppVar_1097 || cppVar_1357;
	bool cppVar_1359 = cppVar_1089 || cppVar_1358;
	bool cppVar_1360 = cppVar_1081 || cppVar_1359;
	bool cppVar_1361 = cppVar_1073 || cppVar_1360;
	bool cppVar_1362 = cppVar_1065 || cppVar_1361;
	bool cppVar_1363 = cppVar_1057 || cppVar_1362;
	bool cppVar_1364 = cppVar_1049 || cppVar_1363;
	bool cppVar_1365 = cppVar_1041 || cppVar_1364;
	bool cppVar_1366 = cppVar_1033 || cppVar_1365;
	bool cppVar_1367 = cppVar_1025 || cppVar_1366;
	bool cppVar_1368 = cppVar_1017 || cppVar_1367;
	bool cppVar_1369 = cppVar_1009 || cppVar_1368;
	bool cppVar_1370 = cppVar_1001 || cppVar_1369;
	bool cppVar_1371 = cppVar_993 || cppVar_1370;
	bool cppVar_1372 = cppVar_985 || cppVar_1371;
	bool cppVar_1373 = cppVar_977 || cppVar_1372;
	bool cppVar_1374 = cppVar_969 || cppVar_1373;
	bool cppVar_1375 = cppVar_961 || cppVar_1374;
	bool cppVar_1376 = cppVar_953 || cppVar_1375;
	bool cppVar_1377 = cppVar_945 || cppVar_1376;
	bool cppVar_1378 = cppVar_937 || cppVar_1377;
	bool cppVar_1379 = cppVar_929 || cppVar_1378;
	bool cppVar_1380 = cppVar_921 || cppVar_1379;
	bool cppVar_1381 = cppVar_913 || cppVar_1380;
	bool cppVar_1382 = cppVar_905 || cppVar_1381;
	bool cppVar_1383 = cppVar_897 || cppVar_1382;
	bool cppVar_1384 = cppVar_889 || cppVar_1383;
	bool cppVar_1385 = cppVar_881 || cppVar_1384;
	bool cppVar_1386 = cppVar_873 || cppVar_1385;
	bool cppVar_1387 = cppVar_865 || cppVar_1386;
	bool cppVar_1388 = cppVar_857 || cppVar_1387;
	bool cppVar_1389 = cppVar_849 || cppVar_1388;
	bool cppVar_1390 = cppVar_841 || cppVar_1389;
	bool cppVar_1391 = cppVar_833 || cppVar_1390;
	bool cppVar_1392 = cppVar_825 || cppVar_1391;
	bool cppVar_1393 = cppVar_817 || cppVar_1392;
	bool cppVar_1394 = cppVar_809 || cppVar_1393;
	bool cppVar_1395 = cppVar_801 || cppVar_1394;
	bool cppVar_1396 = cppVar_793 || cppVar_1395;
	bool cppVar_1397 = cppVar_785 || cppVar_1396;
	bool cppVar_1398 = cppVar_777 || cppVar_1397;
	bool cppVar_1399 = cppVar_769 || cppVar_1398;
	bool cppVar_1400 = cppVar_761 || cppVar_1399;
	bool cppVar_1401 = cppVar_753 || cppVar_1400;
	bool cppVar_1402 = cppVar_745 || cppVar_1401;
	bool cppVar_1403 = cppVar_737 || cppVar_1402;
	bool cppVar_1404 = cppVar_729 || cppVar_1403;
	bool cppVar_1405 = cppVar_721 || cppVar_1404;
	bool cppVar_1406 = cppVar_713 || cppVar_1405;
	bool cppVar_1407 = cppVar_705 || cppVar_1406;
	bool cppVar_1408 = cppVar_697 || cppVar_1407;
	bool cppVar_1409 = cppVar_689 || cppVar_1408;
	bool cppVar_1410 = cppVar_681 || cppVar_1409;
	bool cppVar_1411 = cppVar_673 || cppVar_1410;
	bool cppVar_1412 = cppVar_665 || cppVar_1411;
	bool cppVar_1413 = cppVar_657 || cppVar_1412;
	bool cppVar_1414 = cppVar_649 || cppVar_1413;
	bool cppVar_1415 = cppVar_641 || cppVar_1414;
	bool cppVar_1416 = cppVar_633 || cppVar_1415;
	bool cppVar_1417 = cppVar_625 || cppVar_1416;
	bool cppVar_1418 = cppVar_617 || cppVar_1417;
	bool cppVar_1419 = cppVar_609 || cppVar_1418;
	bool cppVar_1420 = cppVar_601 || cppVar_1419;
	bool cppVar_1421 = cppVar_593 || cppVar_1420;
	bool cppVar_1422 = cppVar_585 || cppVar_1421;
	bool cppVar_1423 = cppVar_577 || cppVar_1422;
	bool cppVar_1424 = cppVar_569 || cppVar_1423;
	bool cppVar_1425 = cppVar_561 || cppVar_1424;
	bool cppVar_1426 = cppVar_553 || cppVar_1425;
	bool cppVar_1427 = cppVar_545 || cppVar_1426;
	bool cppVar_1428 = cppVar_537 || cppVar_1427;
	bool cppVar_1429 = cppVar_529 || cppVar_1428;
	bool cppVar_1430 = cppVar_521 || cppVar_1429;
	bool cppVar_1431 = cppVar_513 || cppVar_1430;
	bool cppVar_1432 = cppVar_505 || cppVar_1431;
	bool cppVar_1433 = cppVar_497 || cppVar_1432;
	bool cppVar_1434 = cppVar_489 || cppVar_1433;
	bool cppVar_1435 = cppVar_481 || cppVar_1434;
	bool cppVar_1436 = cppVar_473 || cppVar_1435;
	bool cppVar_1437 = cppVar_465 || cppVar_1436;
	bool cppVar_1438 = cppVar_457 || cppVar_1437;
	bool cppVar_1439 = cppVar_449 || cppVar_1438;
	bool cppVar_1440 = cppVar_441 || cppVar_1439;
	bool cppVar_1441 = cppVar_433 || cppVar_1440;
	bool cppVar_1442 = cppVar_425 || cppVar_1441;
	bool cppVar_1443 = cppVar_417 || cppVar_1442;
	bool cppVar_1444 = cppVar_409 || cppVar_1443;
	bool cppVar_1445 = cppVar_401 || cppVar_1444;
	bool cppVar_1446 = cppVar_393 || cppVar_1445;
	bool cppVar_1447 = cppVar_385 || cppVar_1446;
	bool cppVar_1448 = cppVar_377 || cppVar_1447;
	bool cppVar_1449 = cppVar_369 || cppVar_1448;
	bool cppVar_1450 = cppVar_361 || cppVar_1449;
	bool cppVar_1451 = cppVar_353 || cppVar_1450;
	bool cppVar_1452 = cppVar_345 || cppVar_1451;
	bool cppVar_1453 = cppVar_337 || cppVar_1452;
	BIT_VEC cppVar_1455 = (cppVar_1453) ? 0 : dataout;
	BIT_VEC cppVar_1456 = (cppVar_328) ? cppVar_329 : cppVar_1455;
	BIT_VEC cppVar_1457 = (cppVar_283) ? cppVar_284 : cppVar_1456;
	BIT_VEC cppVar_1458 = (cppVar_238) ? cppVar_239 : cppVar_1457;
	BIT_VEC cppVar_1459 = (cppVar_193) ? cppVar_194 : cppVar_1458;
	BIT_VEC cppVar_1460 = (cppVar_148) ? cppVar_149 : cppVar_1459;
	BIT_VEC cppVar_1461 = (cppVar_103) ? cppVar_104 : cppVar_1460;
	BIT_VEC cppVar_1462 = (cppVar_58) ? cppVar_59 : cppVar_1461;
	bool cppVar_1464 = (cmddata == 1);
	BIT_VEC cppVar_1466 = (cppVar_1464) ? 0 : sha_bytes_read;
	bool cppVar_1467 = cppVar_324 || cppVar_1321;
	bool cppVar_1468 = cppVar_271 || cppVar_1467;
	bool cppVar_1469 = cppVar_226 || cppVar_1468;
	bool cppVar_1470 = cppVar_181 || cppVar_1469;
	bool cppVar_1471 = cppVar_136 || cppVar_1470;
	bool cppVar_1472 = cppVar_91 || cppVar_1471;
	bool cppVar_1473 = cppVar_46 || cppVar_1472;
	bool cppVar_1474 = cppVar_1273 || cppVar_1473;
	bool cppVar_1475 = cppVar_1233 || cppVar_1474;
	bool cppVar_1476 = cppVar_1193 || cppVar_1475;
	bool cppVar_1477 = cppVar_1153 || cppVar_1476;
	bool cppVar_1478 = cppVar_1121 || cppVar_1477;
	bool cppVar_1479 = cppVar_1081 || cppVar_1478;
	bool cppVar_1480 = cppVar_1041 || cppVar_1479;
	bool cppVar_1481 = cppVar_1001 || cppVar_1480;
	bool cppVar_1482 = cppVar_841 || cppVar_1481;
	bool cppVar_1483 = cppVar_809 || cppVar_1482;
	bool cppVar_1484 = cppVar_777 || cppVar_1483;
	bool cppVar_1485 = cppVar_745 || cppVar_1484;
	bool cppVar_1486 = cppVar_713 || cppVar_1485;
	bool cppVar_1487 = cppVar_681 || cppVar_1486;
	bool cppVar_1488 = cppVar_649 || cppVar_1487;
	bool cppVar_1489 = cppVar_617 || cppVar_1488;
	bool cppVar_1490 = cppVar_585 || cppVar_1489;
	bool cppVar_1491 = cppVar_553 || cppVar_1490;
	bool cppVar_1492 = cppVar_521 || cppVar_1491;
	bool cppVar_1493 = cppVar_489 || cppVar_1492;
	bool cppVar_1494 = cppVar_457 || cppVar_1493;
	bool cppVar_1495 = cppVar_425 || cppVar_1494;
	bool cppVar_1496 = cppVar_393 || cppVar_1495;
	bool cppVar_1497 = cppVar_361 || cppVar_1496;
	BIT_VEC cppVar_1499 = sha_bytes_read + 64;
	cppVar_1499 = (cppVar_1499 & cppMask_un_16_);
	BIT_VEC cppVar_1500 = (cppVar_1497) ? cppVar_1499 : sha_bytes_read;
	BIT_VEC cppVar_1501 = (cppVar_969) ? cppVar_1466 : cppVar_1500;
	bool cppVar_1502 = cppVar_308 || cppVar_1305;
	bool cppVar_1503 = cppVar_255 || cppVar_1502;
	bool cppVar_1504 = cppVar_210 || cppVar_1503;
	bool cppVar_1505 = cppVar_165 || cppVar_1504;
	bool cppVar_1506 = cppVar_120 || cppVar_1505;
	bool cppVar_1507 = cppVar_75 || cppVar_1506;
	bool cppVar_1508 = cppVar_30 || cppVar_1507;
	bool cppVar_1509 = cppVar_1257 || cppVar_1508;
	bool cppVar_1510 = cppVar_1217 || cppVar_1509;
	bool cppVar_1511 = cppVar_1177 || cppVar_1510;
	bool cppVar_1512 = cppVar_1137 || cppVar_1511;
	bool cppVar_1513 = cppVar_1105 || cppVar_1512;
	bool cppVar_1514 = cppVar_1065 || cppVar_1513;
	bool cppVar_1515 = cppVar_1025 || cppVar_1514;
	bool cppVar_1516 = cppVar_985 || cppVar_1515;
	bool cppVar_1517 = cppVar_825 || cppVar_1516;
	bool cppVar_1518 = cppVar_793 || cppVar_1517;
	bool cppVar_1519 = cppVar_761 || cppVar_1518;
	bool cppVar_1520 = cppVar_729 || cppVar_1519;
	bool cppVar_1521 = cppVar_697 || cppVar_1520;
	bool cppVar_1522 = cppVar_665 || cppVar_1521;
	bool cppVar_1523 = cppVar_633 || cppVar_1522;
	bool cppVar_1524 = cppVar_601 || cppVar_1523;
	bool cppVar_1525 = cppVar_569 || cppVar_1524;
	bool cppVar_1526 = cppVar_537 || cppVar_1525;
	bool cppVar_1527 = cppVar_505 || cppVar_1526;
	bool cppVar_1528 = cppVar_473 || cppVar_1527;
	bool cppVar_1529 = cppVar_441 || cppVar_1528;
	bool cppVar_1530 = cppVar_409 || cppVar_1529;
	bool cppVar_1531 = cppVar_377 || cppVar_1530;
	bool cppVar_1532 = cppVar_345 || cppVar_1531;
	BIT_VEC cppVar_1533 = sha(sha_rd_data);
	BIT_VEC cppVar_1534 = (cppVar_1532) ? cppVar_1533 : sha_hs_data;
	BIT_VEC cppVar_1535 = (sha_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_1536 = (cmddata << 8) | cppVar_1535;
	cppVar_1536 = (cppVar_1536 & cppMask_un_16_);
	BIT_VEC cppVar_1537 = (sha_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_1538 = (cppVar_1537 << 8) | cmddata;
	cppVar_1538 = (cppVar_1538 & cppMask_un_16_);
	BIT_VEC cppVar_1539 = (cppVar_921) ? cppVar_1538 : sha_len;
	BIT_VEC cppVar_1540 = (cppVar_913) ? cppVar_1536 : cppVar_1539;
	bool cppVar_1541 = cppVar_324 || cppVar_1321;
	bool cppVar_1542 = cppVar_271 || cppVar_1541;
	bool cppVar_1543 = cppVar_226 || cppVar_1542;
	bool cppVar_1544 = cppVar_181 || cppVar_1543;
	bool cppVar_1545 = cppVar_136 || cppVar_1544;
	bool cppVar_1546 = cppVar_91 || cppVar_1545;
	bool cppVar_1547 = cppVar_46 || cppVar_1546;
	bool cppVar_1548 = cppVar_1273 || cppVar_1547;
	bool cppVar_1549 = cppVar_1233 || cppVar_1548;
	bool cppVar_1550 = cppVar_1193 || cppVar_1549;
	bool cppVar_1551 = cppVar_1153 || cppVar_1550;
	bool cppVar_1552 = cppVar_1121 || cppVar_1551;
	bool cppVar_1553 = cppVar_1081 || cppVar_1552;
	bool cppVar_1554 = cppVar_1041 || cppVar_1553;
	bool cppVar_1555 = cppVar_1001 || cppVar_1554;
	bool cppVar_1556 = cppVar_841 || cppVar_1555;
	bool cppVar_1557 = cppVar_809 || cppVar_1556;
	bool cppVar_1558 = cppVar_777 || cppVar_1557;
	bool cppVar_1559 = cppVar_745 || cppVar_1558;
	bool cppVar_1560 = cppVar_713 || cppVar_1559;
	bool cppVar_1561 = cppVar_681 || cppVar_1560;
	bool cppVar_1562 = cppVar_649 || cppVar_1561;
	bool cppVar_1563 = cppVar_617 || cppVar_1562;
	bool cppVar_1564 = cppVar_585 || cppVar_1563;
	bool cppVar_1565 = cppVar_553 || cppVar_1564;
	bool cppVar_1566 = cppVar_521 || cppVar_1565;
	bool cppVar_1567 = cppVar_489 || cppVar_1566;
	bool cppVar_1568 = cppVar_457 || cppVar_1567;
	bool cppVar_1569 = cppVar_425 || cppVar_1568;
	bool cppVar_1570 = cppVar_393 || cppVar_1569;
	bool cppVar_1571 = cppVar_361 || cppVar_1570;
	BIT_VEC cppVar_1572 = sha_rdaddr + sha_bytes_read;
	cppVar_1572 = (cppVar_1572 & cppMask_un_16_);
	BIT_VEC cppVar_1573 = (XRAM.rd(cppVar_1572) & cppMask_un_8_);
	for (int cppVar_1574 = 1; cppVar_1574 < 64; cppVar_1574++) {
		cppVar_1573 = (cppVar_1573 << 8) | (XRAM.rd(cppVar_1572 + cppVar_1574) & cppMask_un_8_);
	}
	cppVar_1573 = (cppVar_1573 & cppMask_un_512_);
	BIT_VEC cppVar_1575 = (cppVar_1571) ? cppVar_1573 : sha_rd_data;
	BIT_VEC cppVar_1576 = (sha_rdaddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_1577 = (cmddata << 8) | cppVar_1576;
	cppVar_1577 = (cppVar_1577 & cppMask_un_16_);
	BIT_VEC cppVar_1578 = (sha_rdaddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_1579 = (cppVar_1578 << 8) | cmddata;
	cppVar_1579 = (cppVar_1579 & cppMask_un_16_);
	BIT_VEC cppVar_1580 = (cppVar_953) ? cppVar_1579 : sha_rdaddr;
	BIT_VEC cppVar_1581 = (cppVar_945) ? cppVar_1577 : cppVar_1580;
	bool cppVar_1583 = (cmddata == 1);
	BIT_VEC cppVar_1585 = (cppVar_1583) ? 1 : sha_state;
	bool cppVar_1586 = cppVar_308 || cppVar_1305;
	bool cppVar_1587 = cppVar_255 || cppVar_1586;
	bool cppVar_1588 = cppVar_210 || cppVar_1587;
	bool cppVar_1589 = cppVar_165 || cppVar_1588;
	bool cppVar_1590 = cppVar_120 || cppVar_1589;
	bool cppVar_1591 = cppVar_75 || cppVar_1590;
	bool cppVar_1592 = cppVar_30 || cppVar_1591;
	bool cppVar_1593 = cppVar_1257 || cppVar_1592;
	bool cppVar_1594 = cppVar_1217 || cppVar_1593;
	bool cppVar_1595 = cppVar_1177 || cppVar_1594;
	bool cppVar_1596 = cppVar_1137 || cppVar_1595;
	bool cppVar_1597 = cppVar_1105 || cppVar_1596;
	bool cppVar_1598 = cppVar_1065 || cppVar_1597;
	bool cppVar_1599 = cppVar_1025 || cppVar_1598;
	bool cppVar_1600 = cppVar_985 || cppVar_1599;
	bool cppVar_1601 = cppVar_825 || cppVar_1600;
	bool cppVar_1602 = cppVar_793 || cppVar_1601;
	bool cppVar_1603 = cppVar_761 || cppVar_1602;
	bool cppVar_1604 = cppVar_729 || cppVar_1603;
	bool cppVar_1605 = cppVar_697 || cppVar_1604;
	bool cppVar_1606 = cppVar_665 || cppVar_1605;
	bool cppVar_1607 = cppVar_633 || cppVar_1606;
	bool cppVar_1608 = cppVar_601 || cppVar_1607;
	bool cppVar_1609 = cppVar_569 || cppVar_1608;
	bool cppVar_1610 = cppVar_537 || cppVar_1609;
	bool cppVar_1611 = cppVar_505 || cppVar_1610;
	bool cppVar_1612 = cppVar_473 || cppVar_1611;
	bool cppVar_1613 = cppVar_441 || cppVar_1612;
	bool cppVar_1614 = cppVar_409 || cppVar_1613;
	bool cppVar_1615 = cppVar_377 || cppVar_1614;
	bool cppVar_1616 = cppVar_345 || cppVar_1615;
	bool cppVar_1617 = sha_bytes_read < sha_len;
	BIT_VEC cppVar_1620 = (cppVar_1617) ? 1 : 4;
	bool cppVar_1621 = cppVar_316 || cppVar_1313;
	bool cppVar_1622 = cppVar_263 || cppVar_1621;
	bool cppVar_1623 = cppVar_218 || cppVar_1622;
	bool cppVar_1624 = cppVar_173 || cppVar_1623;
	bool cppVar_1625 = cppVar_128 || cppVar_1624;
	bool cppVar_1626 = cppVar_83 || cppVar_1625;
	bool cppVar_1627 = cppVar_38 || cppVar_1626;
	bool cppVar_1628 = cppVar_1265 || cppVar_1627;
	bool cppVar_1629 = cppVar_1225 || cppVar_1628;
	bool cppVar_1630 = cppVar_1185 || cppVar_1629;
	bool cppVar_1631 = cppVar_1145 || cppVar_1630;
	bool cppVar_1632 = cppVar_1113 || cppVar_1631;
	bool cppVar_1633 = cppVar_1073 || cppVar_1632;
	bool cppVar_1634 = cppVar_1033 || cppVar_1633;
	bool cppVar_1635 = cppVar_993 || cppVar_1634;
	bool cppVar_1636 = cppVar_833 || cppVar_1635;
	bool cppVar_1637 = cppVar_801 || cppVar_1636;
	bool cppVar_1638 = cppVar_769 || cppVar_1637;
	bool cppVar_1639 = cppVar_737 || cppVar_1638;
	bool cppVar_1640 = cppVar_705 || cppVar_1639;
	bool cppVar_1641 = cppVar_673 || cppVar_1640;
	bool cppVar_1642 = cppVar_641 || cppVar_1641;
	bool cppVar_1643 = cppVar_609 || cppVar_1642;
	bool cppVar_1644 = cppVar_577 || cppVar_1643;
	bool cppVar_1645 = cppVar_545 || cppVar_1644;
	bool cppVar_1646 = cppVar_513 || cppVar_1645;
	bool cppVar_1647 = cppVar_481 || cppVar_1646;
	bool cppVar_1648 = cppVar_449 || cppVar_1647;
	bool cppVar_1649 = cppVar_417 || cppVar_1648;
	bool cppVar_1650 = cppVar_385 || cppVar_1649;
	bool cppVar_1651 = cppVar_353 || cppVar_1650;
	bool cppVar_1653 = cppVar_324 || cppVar_1321;
	bool cppVar_1654 = cppVar_271 || cppVar_1653;
	bool cppVar_1655 = cppVar_226 || cppVar_1654;
	bool cppVar_1656 = cppVar_181 || cppVar_1655;
	bool cppVar_1657 = cppVar_136 || cppVar_1656;
	bool cppVar_1658 = cppVar_91 || cppVar_1657;
	bool cppVar_1659 = cppVar_46 || cppVar_1658;
	bool cppVar_1660 = cppVar_1273 || cppVar_1659;
	bool cppVar_1661 = cppVar_1233 || cppVar_1660;
	bool cppVar_1662 = cppVar_1193 || cppVar_1661;
	bool cppVar_1663 = cppVar_1153 || cppVar_1662;
	bool cppVar_1664 = cppVar_1121 || cppVar_1663;
	bool cppVar_1665 = cppVar_1081 || cppVar_1664;
	bool cppVar_1666 = cppVar_1041 || cppVar_1665;
	bool cppVar_1667 = cppVar_1001 || cppVar_1666;
	bool cppVar_1668 = cppVar_841 || cppVar_1667;
	bool cppVar_1669 = cppVar_809 || cppVar_1668;
	bool cppVar_1670 = cppVar_777 || cppVar_1669;
	bool cppVar_1671 = cppVar_745 || cppVar_1670;
	bool cppVar_1672 = cppVar_713 || cppVar_1671;
	bool cppVar_1673 = cppVar_681 || cppVar_1672;
	bool cppVar_1674 = cppVar_649 || cppVar_1673;
	bool cppVar_1675 = cppVar_617 || cppVar_1674;
	bool cppVar_1676 = cppVar_585 || cppVar_1675;
	bool cppVar_1677 = cppVar_553 || cppVar_1676;
	bool cppVar_1678 = cppVar_521 || cppVar_1677;
	bool cppVar_1679 = cppVar_489 || cppVar_1678;
	bool cppVar_1680 = cppVar_457 || cppVar_1679;
	bool cppVar_1681 = cppVar_425 || cppVar_1680;
	bool cppVar_1682 = cppVar_393 || cppVar_1681;
	bool cppVar_1683 = cppVar_361 || cppVar_1682;
	bool cppVar_1685 = cppVar_1297 || cppVar_1329;
	bool cppVar_1686 = cppVar_1289 || cppVar_1685;
	bool cppVar_1687 = cppVar_300 || cppVar_1686;
	bool cppVar_1688 = cppVar_279 || cppVar_1687;
	bool cppVar_1689 = cppVar_247 || cppVar_1688;
	bool cppVar_1690 = cppVar_234 || cppVar_1689;
	bool cppVar_1691 = cppVar_202 || cppVar_1690;
	bool cppVar_1692 = cppVar_189 || cppVar_1691;
	bool cppVar_1693 = cppVar_157 || cppVar_1692;
	bool cppVar_1694 = cppVar_144 || cppVar_1693;
	bool cppVar_1695 = cppVar_112 || cppVar_1694;
	bool cppVar_1696 = cppVar_99 || cppVar_1695;
	bool cppVar_1697 = cppVar_67 || cppVar_1696;
	bool cppVar_1698 = cppVar_54 || cppVar_1697;
	bool cppVar_1699 = cppVar_22 || cppVar_1698;
	bool cppVar_1700 = cppVar_1281 || cppVar_1699;
	bool cppVar_1701 = cppVar_1249 || cppVar_1700;
	bool cppVar_1702 = cppVar_1241 || cppVar_1701;
	bool cppVar_1703 = cppVar_1209 || cppVar_1702;
	bool cppVar_1704 = cppVar_1201 || cppVar_1703;
	bool cppVar_1705 = cppVar_1169 || cppVar_1704;
	bool cppVar_1706 = cppVar_1161 || cppVar_1705;
	bool cppVar_1707 = cppVar_1129 || cppVar_1706;
	bool cppVar_1708 = cppVar_292 || cppVar_1707;
	bool cppVar_1709 = cppVar_1097 || cppVar_1708;
	bool cppVar_1710 = cppVar_1089 || cppVar_1709;
	bool cppVar_1711 = cppVar_1057 || cppVar_1710;
	bool cppVar_1712 = cppVar_1049 || cppVar_1711;
	bool cppVar_1713 = cppVar_1017 || cppVar_1712;
	bool cppVar_1714 = cppVar_1009 || cppVar_1713;
	bool cppVar_1715 = cppVar_977 || cppVar_1714;
	bool cppVar_1716 = cppVar_961 || cppVar_1715;
	bool cppVar_1717 = cppVar_953 || cppVar_1716;
	bool cppVar_1718 = cppVar_945 || cppVar_1717;
	bool cppVar_1719 = cppVar_937 || cppVar_1718;
	bool cppVar_1720 = cppVar_929 || cppVar_1719;
	bool cppVar_1721 = cppVar_921 || cppVar_1720;
	bool cppVar_1722 = cppVar_913 || cppVar_1721;
	bool cppVar_1723 = cppVar_905 || cppVar_1722;
	bool cppVar_1724 = cppVar_897 || cppVar_1723;
	bool cppVar_1725 = cppVar_889 || cppVar_1724;
	bool cppVar_1726 = cppVar_881 || cppVar_1725;
	bool cppVar_1727 = cppVar_873 || cppVar_1726;
	bool cppVar_1728 = cppVar_865 || cppVar_1727;
	bool cppVar_1729 = cppVar_857 || cppVar_1728;
	bool cppVar_1730 = cppVar_849 || cppVar_1729;
	bool cppVar_1731 = cppVar_817 || cppVar_1730;
	bool cppVar_1732 = cppVar_785 || cppVar_1731;
	bool cppVar_1733 = cppVar_753 || cppVar_1732;
	bool cppVar_1734 = cppVar_721 || cppVar_1733;
	bool cppVar_1735 = cppVar_689 || cppVar_1734;
	bool cppVar_1736 = cppVar_657 || cppVar_1735;
	bool cppVar_1737 = cppVar_625 || cppVar_1736;
	bool cppVar_1738 = cppVar_593 || cppVar_1737;
	bool cppVar_1739 = cppVar_561 || cppVar_1738;
	bool cppVar_1740 = cppVar_529 || cppVar_1739;
	bool cppVar_1741 = cppVar_497 || cppVar_1740;
	bool cppVar_1742 = cppVar_465 || cppVar_1741;
	bool cppVar_1743 = cppVar_433 || cppVar_1742;
	bool cppVar_1744 = cppVar_401 || cppVar_1743;
	bool cppVar_1745 = cppVar_369 || cppVar_1744;
	bool cppVar_1746 = cppVar_337 || cppVar_1745;
	BIT_VEC cppVar_1748 = (cppVar_1746) ? 0 : sha_state;
	BIT_VEC cppVar_1749 = (cppVar_1683) ? 2 : cppVar_1748;
	BIT_VEC cppVar_1750 = (cppVar_1651) ? 3 : cppVar_1749;
	BIT_VEC cppVar_1751 = (cppVar_1616) ? cppVar_1620 : cppVar_1750;
	BIT_VEC cppVar_1752 = (cppVar_969) ? cppVar_1585 : cppVar_1751;
	BIT_VEC cppVar_1753 = (sha_wraddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_1754 = (cmddata << 8) | cppVar_1753;
	cppVar_1754 = (cppVar_1754 & cppMask_un_16_);
	BIT_VEC cppVar_1755 = (sha_wraddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_1756 = (cppVar_1755 << 8) | cmddata;
	cppVar_1756 = (cppVar_1756 & cppMask_un_16_);
	BIT_VEC cppVar_1757 = (cppVar_937) ? cppVar_1756 : sha_wraddr;
	BIT_VEC cppVar_1758 = (cppVar_929) ? cppVar_1754 : cppVar_1757;
	bool cppVar_1759 = cppVar_1321 || cppVar_1329;
	bool cppVar_1760 = cppVar_1313 || cppVar_1759;
	bool cppVar_1761 = cppVar_1305 || cppVar_1760;
	bool cppVar_1762 = cppVar_1297 || cppVar_1761;
	bool cppVar_1763 = cppVar_1289 || cppVar_1762;
	bool cppVar_1764 = cppVar_324 || cppVar_1763;
	bool cppVar_1765 = cppVar_316 || cppVar_1764;
	bool cppVar_1766 = cppVar_308 || cppVar_1765;
	bool cppVar_1767 = cppVar_300 || cppVar_1766;
	bool cppVar_1768 = cppVar_279 || cppVar_1767;
	bool cppVar_1769 = cppVar_271 || cppVar_1768;
	bool cppVar_1770 = cppVar_263 || cppVar_1769;
	bool cppVar_1771 = cppVar_255 || cppVar_1770;
	bool cppVar_1772 = cppVar_247 || cppVar_1771;
	bool cppVar_1773 = cppVar_234 || cppVar_1772;
	bool cppVar_1774 = cppVar_226 || cppVar_1773;
	bool cppVar_1775 = cppVar_218 || cppVar_1774;
	bool cppVar_1776 = cppVar_210 || cppVar_1775;
	bool cppVar_1777 = cppVar_202 || cppVar_1776;
	bool cppVar_1778 = cppVar_189 || cppVar_1777;
	bool cppVar_1779 = cppVar_181 || cppVar_1778;
	bool cppVar_1780 = cppVar_173 || cppVar_1779;
	bool cppVar_1781 = cppVar_165 || cppVar_1780;
	bool cppVar_1782 = cppVar_157 || cppVar_1781;
	bool cppVar_1783 = cppVar_144 || cppVar_1782;
	bool cppVar_1784 = cppVar_136 || cppVar_1783;
	bool cppVar_1785 = cppVar_128 || cppVar_1784;
	bool cppVar_1786 = cppVar_120 || cppVar_1785;
	bool cppVar_1787 = cppVar_112 || cppVar_1786;
	bool cppVar_1788 = cppVar_99 || cppVar_1787;
	bool cppVar_1789 = cppVar_91 || cppVar_1788;
	bool cppVar_1790 = cppVar_83 || cppVar_1789;
	bool cppVar_1791 = cppVar_75 || cppVar_1790;
	bool cppVar_1792 = cppVar_67 || cppVar_1791;
	bool cppVar_1793 = cppVar_54 || cppVar_1792;
	bool cppVar_1794 = cppVar_46 || cppVar_1793;
	bool cppVar_1795 = cppVar_38 || cppVar_1794;
	bool cppVar_1796 = cppVar_30 || cppVar_1795;
	bool cppVar_1797 = cppVar_22 || cppVar_1796;
	bool cppVar_1798 = cppVar_1281 || cppVar_1797;
	bool cppVar_1799 = cppVar_1273 || cppVar_1798;
	bool cppVar_1800 = cppVar_1265 || cppVar_1799;
	bool cppVar_1801 = cppVar_1257 || cppVar_1800;
	bool cppVar_1802 = cppVar_1249 || cppVar_1801;
	bool cppVar_1803 = cppVar_1241 || cppVar_1802;
	bool cppVar_1804 = cppVar_1233 || cppVar_1803;
	bool cppVar_1805 = cppVar_1225 || cppVar_1804;
	bool cppVar_1806 = cppVar_1217 || cppVar_1805;
	bool cppVar_1807 = cppVar_1209 || cppVar_1806;
	bool cppVar_1808 = cppVar_1201 || cppVar_1807;
	bool cppVar_1809 = cppVar_1193 || cppVar_1808;
	bool cppVar_1810 = cppVar_1185 || cppVar_1809;
	bool cppVar_1811 = cppVar_1177 || cppVar_1810;
	bool cppVar_1812 = cppVar_1169 || cppVar_1811;
	bool cppVar_1813 = cppVar_1161 || cppVar_1812;
	bool cppVar_1814 = cppVar_1153 || cppVar_1813;
	bool cppVar_1815 = cppVar_1145 || cppVar_1814;
	bool cppVar_1816 = cppVar_1137 || cppVar_1815;
	bool cppVar_1817 = cppVar_1129 || cppVar_1816;
	bool cppVar_1818 = cppVar_292 || cppVar_1817;
	bool cppVar_1819 = cppVar_1121 || cppVar_1818;
	bool cppVar_1820 = cppVar_1113 || cppVar_1819;
	bool cppVar_1821 = cppVar_1105 || cppVar_1820;
	bool cppVar_1822 = cppVar_1097 || cppVar_1821;
	bool cppVar_1823 = cppVar_1089 || cppVar_1822;
	bool cppVar_1824 = cppVar_1081 || cppVar_1823;
	bool cppVar_1825 = cppVar_1073 || cppVar_1824;
	bool cppVar_1826 = cppVar_1065 || cppVar_1825;
	bool cppVar_1827 = cppVar_1057 || cppVar_1826;
	bool cppVar_1828 = cppVar_1049 || cppVar_1827;
	bool cppVar_1829 = cppVar_1041 || cppVar_1828;
	bool cppVar_1830 = cppVar_1033 || cppVar_1829;
	bool cppVar_1831 = cppVar_1025 || cppVar_1830;
	bool cppVar_1832 = cppVar_1017 || cppVar_1831;
	bool cppVar_1833 = cppVar_1009 || cppVar_1832;
	bool cppVar_1834 = cppVar_1001 || cppVar_1833;
	bool cppVar_1835 = cppVar_993 || cppVar_1834;
	bool cppVar_1836 = cppVar_985 || cppVar_1835;
	bool cppVar_1837 = cppVar_977 || cppVar_1836;
	bool cppVar_1838 = cppVar_969 || cppVar_1837;
	bool cppVar_1839 = cppVar_961 || cppVar_1838;
	bool cppVar_1840 = cppVar_953 || cppVar_1839;
	bool cppVar_1841 = cppVar_945 || cppVar_1840;
	bool cppVar_1842 = cppVar_937 || cppVar_1841;
	bool cppVar_1843 = cppVar_929 || cppVar_1842;
	bool cppVar_1844 = cppVar_921 || cppVar_1843;
	bool cppVar_1845 = cppVar_913 || cppVar_1844;
	bool cppVar_1846 = cppVar_905 || cppVar_1845;
	bool cppVar_1847 = cppVar_897 || cppVar_1846;
	bool cppVar_1848 = cppVar_889 || cppVar_1847;
	bool cppVar_1849 = cppVar_881 || cppVar_1848;
	bool cppVar_1850 = cppVar_873 || cppVar_1849;
	bool cppVar_1851 = cppVar_865 || cppVar_1850;
	bool cppVar_1852 = cppVar_857 || cppVar_1851;
	bool cppVar_1853 = cppVar_849 || cppVar_1852;
	bool cppVar_1854 = cppVar_841 || cppVar_1853;
	bool cppVar_1855 = cppVar_833 || cppVar_1854;
	bool cppVar_1856 = cppVar_825 || cppVar_1855;
	bool cppVar_1857 = cppVar_817 || cppVar_1856;
	bool cppVar_1858 = cppVar_809 || cppVar_1857;
	bool cppVar_1859 = cppVar_801 || cppVar_1858;
	bool cppVar_1860 = cppVar_793 || cppVar_1859;
	bool cppVar_1861 = cppVar_785 || cppVar_1860;
	bool cppVar_1862 = cppVar_777 || cppVar_1861;
	bool cppVar_1863 = cppVar_769 || cppVar_1862;
	bool cppVar_1864 = cppVar_761 || cppVar_1863;
	bool cppVar_1865 = cppVar_753 || cppVar_1864;
	bool cppVar_1866 = cppVar_745 || cppVar_1865;
	bool cppVar_1867 = cppVar_737 || cppVar_1866;
	bool cppVar_1868 = cppVar_729 || cppVar_1867;
	bool cppVar_1869 = cppVar_721 || cppVar_1868;
	bool cppVar_1870 = cppVar_713 || cppVar_1869;
	bool cppVar_1871 = cppVar_705 || cppVar_1870;
	bool cppVar_1872 = cppVar_697 || cppVar_1871;
	bool cppVar_1873 = cppVar_689 || cppVar_1872;
	bool cppVar_1874 = cppVar_681 || cppVar_1873;
	bool cppVar_1875 = cppVar_673 || cppVar_1874;
	bool cppVar_1876 = cppVar_665 || cppVar_1875;
	bool cppVar_1877 = cppVar_657 || cppVar_1876;
	bool cppVar_1878 = cppVar_649 || cppVar_1877;
	bool cppVar_1879 = cppVar_641 || cppVar_1878;
	bool cppVar_1880 = cppVar_633 || cppVar_1879;
	bool cppVar_1881 = cppVar_625 || cppVar_1880;
	bool cppVar_1882 = cppVar_617 || cppVar_1881;
	bool cppVar_1883 = cppVar_609 || cppVar_1882;
	bool cppVar_1884 = cppVar_601 || cppVar_1883;
	bool cppVar_1885 = cppVar_593 || cppVar_1884;
	bool cppVar_1886 = cppVar_585 || cppVar_1885;
	bool cppVar_1887 = cppVar_577 || cppVar_1886;
	bool cppVar_1888 = cppVar_569 || cppVar_1887;
	bool cppVar_1889 = cppVar_561 || cppVar_1888;
	bool cppVar_1890 = cppVar_553 || cppVar_1889;
	bool cppVar_1891 = cppVar_545 || cppVar_1890;
	bool cppVar_1892 = cppVar_537 || cppVar_1891;
	bool cppVar_1893 = cppVar_529 || cppVar_1892;
	bool cppVar_1894 = cppVar_521 || cppVar_1893;
	bool cppVar_1895 = cppVar_513 || cppVar_1894;
	bool cppVar_1896 = cppVar_505 || cppVar_1895;
	bool cppVar_1897 = cppVar_497 || cppVar_1896;
	bool cppVar_1898 = cppVar_489 || cppVar_1897;
	bool cppVar_1899 = cppVar_481 || cppVar_1898;
	bool cppVar_1900 = cppVar_473 || cppVar_1899;
	bool cppVar_1901 = cppVar_465 || cppVar_1900;
	bool cppVar_1902 = cppVar_457 || cppVar_1901;
	bool cppVar_1903 = cppVar_449 || cppVar_1902;
	bool cppVar_1904 = cppVar_441 || cppVar_1903;
	bool cppVar_1905 = cppVar_433 || cppVar_1904;
	bool cppVar_1906 = cppVar_425 || cppVar_1905;
	bool cppVar_1907 = cppVar_417 || cppVar_1906;
	bool cppVar_1908 = cppVar_409 || cppVar_1907;
	bool cppVar_1909 = cppVar_401 || cppVar_1908;
	bool cppVar_1910 = cppVar_393 || cppVar_1909;
	bool cppVar_1911 = cppVar_385 || cppVar_1910;
	bool cppVar_1912 = cppVar_377 || cppVar_1911;
	bool cppVar_1913 = cppVar_369 || cppVar_1912;
	bool cppVar_1914 = cppVar_361 || cppVar_1913;
	bool cppVar_1915 = cppVar_353 || cppVar_1914;
	bool cppVar_1916 = cppVar_345 || cppVar_1915;
	bool cppVar_1917 = cppVar_337 || cppVar_1916;
	bool cppVar_1919 = (sha_state == 4);
	bool cppVar_1921 = (cmd != 1);
	bool cppVar_1922 = cppVar_1919 && cppVar_1921;
	bool cppVar_1924 = (cmdaddr == 65039);
	bool cppVar_1925 = cppVar_1922 && cppVar_1924;
	bool cppVar_1927 = (sha_state == 4);
	bool cppVar_1929 = (cmd != 1);
	bool cppVar_1930 = cppVar_1927 && cppVar_1929;
	bool cppVar_1932 = (cmdaddr == 65038);
	bool cppVar_1933 = cppVar_1930 && cppVar_1932;
	bool cppVar_1935 = (sha_state == 4);
	bool cppVar_1937 = (cmd != 1);
	bool cppVar_1938 = cppVar_1935 && cppVar_1937;
	bool cppVar_1940 = (cmdaddr == 65037);
	bool cppVar_1941 = cppVar_1938 && cppVar_1940;
	bool cppVar_1943 = (sha_state == 4);
	bool cppVar_1945 = (cmd != 1);
	bool cppVar_1946 = cppVar_1943 && cppVar_1945;
	bool cppVar_1948 = (cmdaddr == 65036);
	bool cppVar_1949 = cppVar_1946 && cppVar_1948;
	bool cppVar_1951 = (sha_state == 4);
	bool cppVar_1953 = (cmd != 1);
	bool cppVar_1954 = cppVar_1951 && cppVar_1953;
	bool cppVar_1956 = (cmdaddr == 65035);
	bool cppVar_1957 = cppVar_1954 && cppVar_1956;
	bool cppVar_1959 = (sha_state == 4);
	bool cppVar_1961 = (cmd != 1);
	bool cppVar_1962 = cppVar_1959 && cppVar_1961;
	bool cppVar_1964 = (cmdaddr == 65034);
	bool cppVar_1965 = cppVar_1962 && cppVar_1964;
	bool cppVar_1967 = (sha_state == 4);
	bool cppVar_1969 = (cmd != 1);
	bool cppVar_1970 = cppVar_1967 && cppVar_1969;
	bool cppVar_1972 = (cmdaddr == 65033);
	bool cppVar_1973 = cppVar_1970 && cppVar_1972;
	bool cppVar_1975 = (sha_state == 4);
	bool cppVar_1977 = (cmd != 1);
	bool cppVar_1978 = cppVar_1975 && cppVar_1977;
	bool cppVar_1980 = (cmdaddr == 65032);
	bool cppVar_1981 = cppVar_1978 && cppVar_1980;
	bool cppVar_1983 = (sha_state == 4);
	bool cppVar_1985 = (cmd != 1);
	bool cppVar_1986 = cppVar_1983 && cppVar_1985;
	bool cppVar_1988 = (cmdaddr == 65031);
	bool cppVar_1989 = cppVar_1986 && cppVar_1988;
	bool cppVar_1991 = (sha_state == 4);
	bool cppVar_1993 = (cmd != 1);
	bool cppVar_1994 = cppVar_1991 && cppVar_1993;
	bool cppVar_1996 = (cmdaddr == 65030);
	bool cppVar_1997 = cppVar_1994 && cppVar_1996;
	bool cppVar_1999 = (sha_state == 4);
	bool cppVar_2001 = (cmd != 1);
	bool cppVar_2002 = cppVar_1999 && cppVar_2001;
	bool cppVar_2004 = (cmdaddr == 65029);
	bool cppVar_2005 = cppVar_2002 && cppVar_2004;
	bool cppVar_2007 = (sha_state == 4);
	bool cppVar_2009 = (cmd != 1);
	bool cppVar_2010 = cppVar_2007 && cppVar_2009;
	bool cppVar_2012 = (cmdaddr == 65028);
	bool cppVar_2013 = cppVar_2010 && cppVar_2012;
	bool cppVar_2015 = (sha_state == 4);
	bool cppVar_2017 = (cmd != 1);
	bool cppVar_2018 = cppVar_2015 && cppVar_2017;
	bool cppVar_2020 = (cmdaddr == 65027);
	bool cppVar_2021 = cppVar_2018 && cppVar_2020;
	bool cppVar_2023 = (sha_state == 4);
	bool cppVar_2025 = (cmd != 1);
	bool cppVar_2026 = cppVar_2023 && cppVar_2025;
	bool cppVar_2028 = (cmdaddr == 65026);
	bool cppVar_2029 = cppVar_2026 && cppVar_2028;
	bool cppVar_2031 = (sha_state == 4);
	bool cppVar_2033 = (cmd != 1);
	bool cppVar_2034 = cppVar_2031 && cppVar_2033;
	bool cppVar_2036 = (cmdaddr == 65025);
	bool cppVar_2037 = cppVar_2034 && cppVar_2036;
	bool cppVar_2039 = (sha_state == 4);
	bool cppVar_2041 = (cmd != 1);
	bool cppVar_2042 = cppVar_2039 && cppVar_2041;
	bool cppVar_2044 = (cmdaddr == 65024);
	bool cppVar_2045 = cppVar_2042 && cppVar_2044;
	bool cppVar_2047 = (sha_state == 4);
	bool cppVar_2049 = (cmd == 1);
	bool cppVar_2050 = cppVar_2047 && cppVar_2049;
	bool cppVar_2052 = (cmdaddr == 65039);
	bool cppVar_2053 = cppVar_2050 && cppVar_2052;
	bool cppVar_2055 = (sha_state == 4);
	bool cppVar_2057 = (cmd == 1);
	bool cppVar_2058 = cppVar_2055 && cppVar_2057;
	bool cppVar_2060 = (cmdaddr == 65038);
	bool cppVar_2061 = cppVar_2058 && cppVar_2060;
	bool cppVar_2063 = (sha_state == 4);
	bool cppVar_2065 = (cmd == 1);
	bool cppVar_2066 = cppVar_2063 && cppVar_2065;
	bool cppVar_2068 = (cmdaddr == 65037);
	bool cppVar_2069 = cppVar_2066 && cppVar_2068;
	bool cppVar_2071 = (sha_state == 4);
	bool cppVar_2073 = (cmd == 1);
	bool cppVar_2074 = cppVar_2071 && cppVar_2073;
	bool cppVar_2076 = (cmdaddr == 65036);
	bool cppVar_2077 = cppVar_2074 && cppVar_2076;
	bool cppVar_2079 = (sha_state == 4);
	bool cppVar_2081 = (cmd == 1);
	bool cppVar_2082 = cppVar_2079 && cppVar_2081;
	bool cppVar_2084 = (cmdaddr == 65035);
	bool cppVar_2085 = cppVar_2082 && cppVar_2084;
	bool cppVar_2087 = (sha_state == 4);
	bool cppVar_2089 = (cmd == 1);
	bool cppVar_2090 = cppVar_2087 && cppVar_2089;
	bool cppVar_2092 = (cmdaddr == 65034);
	bool cppVar_2093 = cppVar_2090 && cppVar_2092;
	bool cppVar_2095 = (sha_state == 4);
	bool cppVar_2097 = (cmd == 1);
	bool cppVar_2098 = cppVar_2095 && cppVar_2097;
	bool cppVar_2100 = (cmdaddr == 65033);
	bool cppVar_2101 = cppVar_2098 && cppVar_2100;
	bool cppVar_2103 = (sha_state == 4);
	bool cppVar_2105 = (cmd == 1);
	bool cppVar_2106 = cppVar_2103 && cppVar_2105;
	bool cppVar_2108 = (cmdaddr == 65032);
	bool cppVar_2109 = cppVar_2106 && cppVar_2108;
	bool cppVar_2111 = (sha_state == 4);
	bool cppVar_2113 = (cmd == 1);
	bool cppVar_2114 = cppVar_2111 && cppVar_2113;
	bool cppVar_2116 = (cmdaddr == 65031);
	bool cppVar_2117 = cppVar_2114 && cppVar_2116;
	bool cppVar_2119 = (sha_state == 4);
	bool cppVar_2121 = (cmd == 1);
	bool cppVar_2122 = cppVar_2119 && cppVar_2121;
	bool cppVar_2124 = (cmdaddr == 65030);
	bool cppVar_2125 = cppVar_2122 && cppVar_2124;
	bool cppVar_2127 = (sha_state == 4);
	bool cppVar_2129 = (cmd == 1);
	bool cppVar_2130 = cppVar_2127 && cppVar_2129;
	bool cppVar_2132 = (cmdaddr == 65029);
	bool cppVar_2133 = cppVar_2130 && cppVar_2132;
	bool cppVar_2135 = (sha_state == 4);
	bool cppVar_2137 = (cmd == 1);
	bool cppVar_2138 = cppVar_2135 && cppVar_2137;
	bool cppVar_2140 = (cmdaddr == 65028);
	bool cppVar_2141 = cppVar_2138 && cppVar_2140;
	bool cppVar_2143 = (sha_state == 4);
	bool cppVar_2145 = (cmd == 1);
	bool cppVar_2146 = cppVar_2143 && cppVar_2145;
	bool cppVar_2148 = (cmdaddr == 65027);
	bool cppVar_2149 = cppVar_2146 && cppVar_2148;
	bool cppVar_2151 = (sha_state == 4);
	bool cppVar_2153 = (cmd == 1);
	bool cppVar_2154 = cppVar_2151 && cppVar_2153;
	bool cppVar_2156 = (cmdaddr == 65026);
	bool cppVar_2157 = cppVar_2154 && cppVar_2156;
	bool cppVar_2159 = (sha_state == 4);
	bool cppVar_2161 = (cmd == 1);
	bool cppVar_2162 = cppVar_2159 && cppVar_2161;
	bool cppVar_2164 = (cmdaddr == 65025);
	bool cppVar_2165 = cppVar_2162 && cppVar_2164;
	bool cppVar_2167 = (sha_state == 4);
	bool cppVar_2169 = (cmd == 1);
	bool cppVar_2170 = cppVar_2167 && cppVar_2169;
	bool cppVar_2172 = (cmdaddr == 65024);
	bool cppVar_2173 = cppVar_2170 && cppVar_2172;
	bool cppVar_2174 = cppVar_2165 || cppVar_2173;
	bool cppVar_2175 = cppVar_2157 || cppVar_2174;
	bool cppVar_2176 = cppVar_2149 || cppVar_2175;
	bool cppVar_2177 = cppVar_2141 || cppVar_2176;
	bool cppVar_2178 = cppVar_2133 || cppVar_2177;
	bool cppVar_2179 = cppVar_2125 || cppVar_2178;
	bool cppVar_2180 = cppVar_2117 || cppVar_2179;
	bool cppVar_2181 = cppVar_2109 || cppVar_2180;
	bool cppVar_2182 = cppVar_2101 || cppVar_2181;
	bool cppVar_2183 = cppVar_2093 || cppVar_2182;
	bool cppVar_2184 = cppVar_2085 || cppVar_2183;
	bool cppVar_2185 = cppVar_2077 || cppVar_2184;
	bool cppVar_2186 = cppVar_2069 || cppVar_2185;
	bool cppVar_2187 = cppVar_2061 || cppVar_2186;
	bool cppVar_2188 = cppVar_2053 || cppVar_2187;
	bool cppVar_2189 = cppVar_2045 || cppVar_2188;
	bool cppVar_2190 = cppVar_2037 || cppVar_2189;
	bool cppVar_2191 = cppVar_2029 || cppVar_2190;
	bool cppVar_2192 = cppVar_2021 || cppVar_2191;
	bool cppVar_2193 = cppVar_2013 || cppVar_2192;
	bool cppVar_2194 = cppVar_2005 || cppVar_2193;
	bool cppVar_2195 = cppVar_1997 || cppVar_2194;
	bool cppVar_2196 = cppVar_1989 || cppVar_2195;
	bool cppVar_2197 = cppVar_1981 || cppVar_2196;
	bool cppVar_2198 = cppVar_1973 || cppVar_2197;
	bool cppVar_2199 = cppVar_1965 || cppVar_2198;
	bool cppVar_2200 = cppVar_1957 || cppVar_2199;
	bool cppVar_2201 = cppVar_1949 || cppVar_2200;
	bool cppVar_2202 = cppVar_1941 || cppVar_2201;
	bool cppVar_2203 = cppVar_1933 || cppVar_2202;
	bool cppVar_2204 = cppVar_1925 || cppVar_2203;
	BIT_VEC cppVar_2207;
	type_mem cppVar_2205 = XRAM;
	for (int cppVar_2206 = 0; cppVar_2206 < 20; cppVar_2206++) {
		cppVar_2207 = sha_hs_data >> ((20 - 1 - cppVar_2206) * 8);
		cppVar_2205.wr(sha_wraddr + cppVar_2206, cppVar_2207);
	}
	type_mem& cppVar_2208 = (cppVar_2204) ? cppVar_2205 : XRAM;
	type_mem& cppVar_2209 = (cppVar_1917) ? cppVar_2208 : XRAM;
	dataout = cppVar_1462;
	sha_bytes_read = cppVar_1501;
	sha_hs_data = cppVar_1534;
	sha_len = cppVar_1540;
	sha_rd_data = cppVar_1575;
	sha_rdaddr = cppVar_1581;
	sha_state = cppVar_1752;
	sha_wraddr = cppVar_1758;
	XRAM = cppVar_2209;
	return;
}

/****************************************************/
/****************************************************/
#endif
/****************************************************/
