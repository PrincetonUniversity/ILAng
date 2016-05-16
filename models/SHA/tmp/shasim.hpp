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

BIT_VEC sha(BIT_VEC cppVar_14)
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
BIT_VEC model_sha::cppUpdateFun_dataout(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
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
	bool cppVar_286 = (sha_state == 4);
	bool cppVar_288 = (cmd != 1);
	bool cppVar_289 = cppVar_286 && cppVar_288;
	bool cppVar_291 = (cmdaddr == 65039);
	bool cppVar_292 = cppVar_289 && cppVar_291;
	bool cppVar_294 = (sha_state == 3);
	bool cppVar_296 = (cmd != 1);
	bool cppVar_297 = cppVar_294 && cppVar_296;
	bool cppVar_299 = (cmdaddr == 65039);
	bool cppVar_300 = cppVar_297 && cppVar_299;
	bool cppVar_302 = (sha_state == 2);
	bool cppVar_304 = (cmd != 1);
	bool cppVar_305 = cppVar_302 && cppVar_304;
	bool cppVar_307 = (cmdaddr == 65039);
	bool cppVar_308 = cppVar_305 && cppVar_307;
	bool cppVar_310 = (sha_state == 1);
	bool cppVar_312 = (cmd != 1);
	bool cppVar_313 = cppVar_310 && cppVar_312;
	bool cppVar_315 = (cmdaddr == 65039);
	bool cppVar_316 = cppVar_313 && cppVar_315;
	bool cppVar_318 = (sha_state == 4);
	bool cppVar_320 = (cmd != 1);
	bool cppVar_321 = cppVar_318 && cppVar_320;
	bool cppVar_323 = (cmdaddr == 65038);
	bool cppVar_324 = cppVar_321 && cppVar_323;
	bool cppVar_326 = (sha_state == 3);
	bool cppVar_328 = (cmd != 1);
	bool cppVar_329 = cppVar_326 && cppVar_328;
	bool cppVar_331 = (cmdaddr == 65038);
	bool cppVar_332 = cppVar_329 && cppVar_331;
	bool cppVar_334 = (sha_state == 2);
	bool cppVar_336 = (cmd != 1);
	bool cppVar_337 = cppVar_334 && cppVar_336;
	bool cppVar_339 = (cmdaddr == 65038);
	bool cppVar_340 = cppVar_337 && cppVar_339;
	bool cppVar_342 = (sha_state == 1);
	bool cppVar_344 = (cmd != 1);
	bool cppVar_345 = cppVar_342 && cppVar_344;
	bool cppVar_347 = (cmdaddr == 65038);
	bool cppVar_348 = cppVar_345 && cppVar_347;
	bool cppVar_350 = (sha_state == 4);
	bool cppVar_352 = (cmd != 1);
	bool cppVar_353 = cppVar_350 && cppVar_352;
	bool cppVar_355 = (cmdaddr == 65037);
	bool cppVar_356 = cppVar_353 && cppVar_355;
	bool cppVar_358 = (sha_state == 3);
	bool cppVar_360 = (cmd != 1);
	bool cppVar_361 = cppVar_358 && cppVar_360;
	bool cppVar_363 = (cmdaddr == 65037);
	bool cppVar_364 = cppVar_361 && cppVar_363;
	bool cppVar_366 = (sha_state == 2);
	bool cppVar_368 = (cmd != 1);
	bool cppVar_369 = cppVar_366 && cppVar_368;
	bool cppVar_371 = (cmdaddr == 65037);
	bool cppVar_372 = cppVar_369 && cppVar_371;
	bool cppVar_374 = (sha_state == 1);
	bool cppVar_376 = (cmd != 1);
	bool cppVar_377 = cppVar_374 && cppVar_376;
	bool cppVar_379 = (cmdaddr == 65037);
	bool cppVar_380 = cppVar_377 && cppVar_379;
	bool cppVar_382 = (sha_state == 4);
	bool cppVar_384 = (cmd != 1);
	bool cppVar_385 = cppVar_382 && cppVar_384;
	bool cppVar_387 = (cmdaddr == 65036);
	bool cppVar_388 = cppVar_385 && cppVar_387;
	bool cppVar_390 = (sha_state == 3);
	bool cppVar_392 = (cmd != 1);
	bool cppVar_393 = cppVar_390 && cppVar_392;
	bool cppVar_395 = (cmdaddr == 65036);
	bool cppVar_396 = cppVar_393 && cppVar_395;
	bool cppVar_398 = (sha_state == 2);
	bool cppVar_400 = (cmd != 1);
	bool cppVar_401 = cppVar_398 && cppVar_400;
	bool cppVar_403 = (cmdaddr == 65036);
	bool cppVar_404 = cppVar_401 && cppVar_403;
	bool cppVar_406 = (sha_state == 1);
	bool cppVar_408 = (cmd != 1);
	bool cppVar_409 = cppVar_406 && cppVar_408;
	bool cppVar_411 = (cmdaddr == 65036);
	bool cppVar_412 = cppVar_409 && cppVar_411;
	bool cppVar_414 = (sha_state == 4);
	bool cppVar_416 = (cmd != 1);
	bool cppVar_417 = cppVar_414 && cppVar_416;
	bool cppVar_419 = (cmdaddr == 65035);
	bool cppVar_420 = cppVar_417 && cppVar_419;
	bool cppVar_422 = (sha_state == 3);
	bool cppVar_424 = (cmd != 1);
	bool cppVar_425 = cppVar_422 && cppVar_424;
	bool cppVar_427 = (cmdaddr == 65035);
	bool cppVar_428 = cppVar_425 && cppVar_427;
	bool cppVar_430 = (sha_state == 2);
	bool cppVar_432 = (cmd != 1);
	bool cppVar_433 = cppVar_430 && cppVar_432;
	bool cppVar_435 = (cmdaddr == 65035);
	bool cppVar_436 = cppVar_433 && cppVar_435;
	bool cppVar_438 = (sha_state == 1);
	bool cppVar_440 = (cmd != 1);
	bool cppVar_441 = cppVar_438 && cppVar_440;
	bool cppVar_443 = (cmdaddr == 65035);
	bool cppVar_444 = cppVar_441 && cppVar_443;
	bool cppVar_446 = (sha_state == 4);
	bool cppVar_448 = (cmd != 1);
	bool cppVar_449 = cppVar_446 && cppVar_448;
	bool cppVar_451 = (cmdaddr == 65034);
	bool cppVar_452 = cppVar_449 && cppVar_451;
	bool cppVar_454 = (sha_state == 3);
	bool cppVar_456 = (cmd != 1);
	bool cppVar_457 = cppVar_454 && cppVar_456;
	bool cppVar_459 = (cmdaddr == 65034);
	bool cppVar_460 = cppVar_457 && cppVar_459;
	bool cppVar_462 = (sha_state == 2);
	bool cppVar_464 = (cmd != 1);
	bool cppVar_465 = cppVar_462 && cppVar_464;
	bool cppVar_467 = (cmdaddr == 65034);
	bool cppVar_468 = cppVar_465 && cppVar_467;
	bool cppVar_470 = (sha_state == 1);
	bool cppVar_472 = (cmd != 1);
	bool cppVar_473 = cppVar_470 && cppVar_472;
	bool cppVar_475 = (cmdaddr == 65034);
	bool cppVar_476 = cppVar_473 && cppVar_475;
	bool cppVar_478 = (sha_state == 4);
	bool cppVar_480 = (cmd != 1);
	bool cppVar_481 = cppVar_478 && cppVar_480;
	bool cppVar_483 = (cmdaddr == 65033);
	bool cppVar_484 = cppVar_481 && cppVar_483;
	bool cppVar_486 = (sha_state == 3);
	bool cppVar_488 = (cmd != 1);
	bool cppVar_489 = cppVar_486 && cppVar_488;
	bool cppVar_491 = (cmdaddr == 65033);
	bool cppVar_492 = cppVar_489 && cppVar_491;
	bool cppVar_494 = (sha_state == 2);
	bool cppVar_496 = (cmd != 1);
	bool cppVar_497 = cppVar_494 && cppVar_496;
	bool cppVar_499 = (cmdaddr == 65033);
	bool cppVar_500 = cppVar_497 && cppVar_499;
	bool cppVar_502 = (sha_state == 1);
	bool cppVar_504 = (cmd != 1);
	bool cppVar_505 = cppVar_502 && cppVar_504;
	bool cppVar_507 = (cmdaddr == 65033);
	bool cppVar_508 = cppVar_505 && cppVar_507;
	bool cppVar_510 = (sha_state == 4);
	bool cppVar_512 = (cmd != 1);
	bool cppVar_513 = cppVar_510 && cppVar_512;
	bool cppVar_515 = (cmdaddr == 65032);
	bool cppVar_516 = cppVar_513 && cppVar_515;
	bool cppVar_518 = (sha_state == 3);
	bool cppVar_520 = (cmd != 1);
	bool cppVar_521 = cppVar_518 && cppVar_520;
	bool cppVar_523 = (cmdaddr == 65032);
	bool cppVar_524 = cppVar_521 && cppVar_523;
	bool cppVar_526 = (sha_state == 2);
	bool cppVar_528 = (cmd != 1);
	bool cppVar_529 = cppVar_526 && cppVar_528;
	bool cppVar_531 = (cmdaddr == 65032);
	bool cppVar_532 = cppVar_529 && cppVar_531;
	bool cppVar_534 = (sha_state == 1);
	bool cppVar_536 = (cmd != 1);
	bool cppVar_537 = cppVar_534 && cppVar_536;
	bool cppVar_539 = (cmdaddr == 65032);
	bool cppVar_540 = cppVar_537 && cppVar_539;
	bool cppVar_542 = (sha_state == 4);
	bool cppVar_544 = (cmd != 1);
	bool cppVar_545 = cppVar_542 && cppVar_544;
	bool cppVar_547 = (cmdaddr == 65031);
	bool cppVar_548 = cppVar_545 && cppVar_547;
	bool cppVar_550 = (sha_state == 3);
	bool cppVar_552 = (cmd != 1);
	bool cppVar_553 = cppVar_550 && cppVar_552;
	bool cppVar_555 = (cmdaddr == 65031);
	bool cppVar_556 = cppVar_553 && cppVar_555;
	bool cppVar_558 = (sha_state == 2);
	bool cppVar_560 = (cmd != 1);
	bool cppVar_561 = cppVar_558 && cppVar_560;
	bool cppVar_563 = (cmdaddr == 65031);
	bool cppVar_564 = cppVar_561 && cppVar_563;
	bool cppVar_566 = (sha_state == 1);
	bool cppVar_568 = (cmd != 1);
	bool cppVar_569 = cppVar_566 && cppVar_568;
	bool cppVar_571 = (cmdaddr == 65031);
	bool cppVar_572 = cppVar_569 && cppVar_571;
	bool cppVar_574 = (sha_state == 4);
	bool cppVar_576 = (cmd != 1);
	bool cppVar_577 = cppVar_574 && cppVar_576;
	bool cppVar_579 = (cmdaddr == 65030);
	bool cppVar_580 = cppVar_577 && cppVar_579;
	bool cppVar_582 = (sha_state == 3);
	bool cppVar_584 = (cmd != 1);
	bool cppVar_585 = cppVar_582 && cppVar_584;
	bool cppVar_587 = (cmdaddr == 65030);
	bool cppVar_588 = cppVar_585 && cppVar_587;
	bool cppVar_590 = (sha_state == 2);
	bool cppVar_592 = (cmd != 1);
	bool cppVar_593 = cppVar_590 && cppVar_592;
	bool cppVar_595 = (cmdaddr == 65030);
	bool cppVar_596 = cppVar_593 && cppVar_595;
	bool cppVar_598 = (sha_state == 1);
	bool cppVar_600 = (cmd != 1);
	bool cppVar_601 = cppVar_598 && cppVar_600;
	bool cppVar_603 = (cmdaddr == 65030);
	bool cppVar_604 = cppVar_601 && cppVar_603;
	bool cppVar_606 = (sha_state == 4);
	bool cppVar_608 = (cmd != 1);
	bool cppVar_609 = cppVar_606 && cppVar_608;
	bool cppVar_611 = (cmdaddr == 65029);
	bool cppVar_612 = cppVar_609 && cppVar_611;
	bool cppVar_614 = (sha_state == 3);
	bool cppVar_616 = (cmd != 1);
	bool cppVar_617 = cppVar_614 && cppVar_616;
	bool cppVar_619 = (cmdaddr == 65029);
	bool cppVar_620 = cppVar_617 && cppVar_619;
	bool cppVar_622 = (sha_state == 2);
	bool cppVar_624 = (cmd != 1);
	bool cppVar_625 = cppVar_622 && cppVar_624;
	bool cppVar_627 = (cmdaddr == 65029);
	bool cppVar_628 = cppVar_625 && cppVar_627;
	bool cppVar_630 = (sha_state == 1);
	bool cppVar_632 = (cmd != 1);
	bool cppVar_633 = cppVar_630 && cppVar_632;
	bool cppVar_635 = (cmdaddr == 65029);
	bool cppVar_636 = cppVar_633 && cppVar_635;
	bool cppVar_638 = (sha_state == 4);
	bool cppVar_640 = (cmd != 1);
	bool cppVar_641 = cppVar_638 && cppVar_640;
	bool cppVar_643 = (cmdaddr == 65028);
	bool cppVar_644 = cppVar_641 && cppVar_643;
	bool cppVar_646 = (sha_state == 3);
	bool cppVar_648 = (cmd != 1);
	bool cppVar_649 = cppVar_646 && cppVar_648;
	bool cppVar_651 = (cmdaddr == 65028);
	bool cppVar_652 = cppVar_649 && cppVar_651;
	bool cppVar_654 = (sha_state == 2);
	bool cppVar_656 = (cmd != 1);
	bool cppVar_657 = cppVar_654 && cppVar_656;
	bool cppVar_659 = (cmdaddr == 65028);
	bool cppVar_660 = cppVar_657 && cppVar_659;
	bool cppVar_662 = (sha_state == 1);
	bool cppVar_664 = (cmd != 1);
	bool cppVar_665 = cppVar_662 && cppVar_664;
	bool cppVar_667 = (cmdaddr == 65028);
	bool cppVar_668 = cppVar_665 && cppVar_667;
	bool cppVar_670 = (sha_state == 4);
	bool cppVar_672 = (cmd != 1);
	bool cppVar_673 = cppVar_670 && cppVar_672;
	bool cppVar_675 = (cmdaddr == 65027);
	bool cppVar_676 = cppVar_673 && cppVar_675;
	bool cppVar_678 = (sha_state == 3);
	bool cppVar_680 = (cmd != 1);
	bool cppVar_681 = cppVar_678 && cppVar_680;
	bool cppVar_683 = (cmdaddr == 65027);
	bool cppVar_684 = cppVar_681 && cppVar_683;
	bool cppVar_686 = (sha_state == 2);
	bool cppVar_688 = (cmd != 1);
	bool cppVar_689 = cppVar_686 && cppVar_688;
	bool cppVar_691 = (cmdaddr == 65027);
	bool cppVar_692 = cppVar_689 && cppVar_691;
	bool cppVar_694 = (sha_state == 1);
	bool cppVar_696 = (cmd != 1);
	bool cppVar_697 = cppVar_694 && cppVar_696;
	bool cppVar_699 = (cmdaddr == 65027);
	bool cppVar_700 = cppVar_697 && cppVar_699;
	bool cppVar_702 = (sha_state == 4);
	bool cppVar_704 = (cmd != 1);
	bool cppVar_705 = cppVar_702 && cppVar_704;
	bool cppVar_707 = (cmdaddr == 65026);
	bool cppVar_708 = cppVar_705 && cppVar_707;
	bool cppVar_710 = (sha_state == 3);
	bool cppVar_712 = (cmd != 1);
	bool cppVar_713 = cppVar_710 && cppVar_712;
	bool cppVar_715 = (cmdaddr == 65026);
	bool cppVar_716 = cppVar_713 && cppVar_715;
	bool cppVar_718 = (sha_state == 2);
	bool cppVar_720 = (cmd != 1);
	bool cppVar_721 = cppVar_718 && cppVar_720;
	bool cppVar_723 = (cmdaddr == 65026);
	bool cppVar_724 = cppVar_721 && cppVar_723;
	bool cppVar_726 = (sha_state == 1);
	bool cppVar_728 = (cmd != 1);
	bool cppVar_729 = cppVar_726 && cppVar_728;
	bool cppVar_731 = (cmdaddr == 65026);
	bool cppVar_732 = cppVar_729 && cppVar_731;
	bool cppVar_734 = (sha_state == 4);
	bool cppVar_736 = (cmd != 1);
	bool cppVar_737 = cppVar_734 && cppVar_736;
	bool cppVar_739 = (cmdaddr == 65025);
	bool cppVar_740 = cppVar_737 && cppVar_739;
	bool cppVar_742 = (sha_state == 3);
	bool cppVar_744 = (cmd != 1);
	bool cppVar_745 = cppVar_742 && cppVar_744;
	bool cppVar_747 = (cmdaddr == 65025);
	bool cppVar_748 = cppVar_745 && cppVar_747;
	bool cppVar_750 = (sha_state == 2);
	bool cppVar_752 = (cmd != 1);
	bool cppVar_753 = cppVar_750 && cppVar_752;
	bool cppVar_755 = (cmdaddr == 65025);
	bool cppVar_756 = cppVar_753 && cppVar_755;
	bool cppVar_758 = (sha_state == 1);
	bool cppVar_760 = (cmd != 1);
	bool cppVar_761 = cppVar_758 && cppVar_760;
	bool cppVar_763 = (cmdaddr == 65025);
	bool cppVar_764 = cppVar_761 && cppVar_763;
	bool cppVar_766 = (sha_state == 4);
	bool cppVar_768 = (cmd != 1);
	bool cppVar_769 = cppVar_766 && cppVar_768;
	bool cppVar_771 = (cmdaddr == 65024);
	bool cppVar_772 = cppVar_769 && cppVar_771;
	bool cppVar_774 = (sha_state == 3);
	bool cppVar_776 = (cmd != 1);
	bool cppVar_777 = cppVar_774 && cppVar_776;
	bool cppVar_779 = (cmdaddr == 65024);
	bool cppVar_780 = cppVar_777 && cppVar_779;
	bool cppVar_782 = (sha_state == 2);
	bool cppVar_784 = (cmd != 1);
	bool cppVar_785 = cppVar_782 && cppVar_784;
	bool cppVar_787 = (cmdaddr == 65024);
	bool cppVar_788 = cppVar_785 && cppVar_787;
	bool cppVar_790 = (sha_state == 1);
	bool cppVar_792 = (cmd != 1);
	bool cppVar_793 = cppVar_790 && cppVar_792;
	bool cppVar_795 = (cmdaddr == 65024);
	bool cppVar_796 = cppVar_793 && cppVar_795;
	bool cppVar_798 = (sha_state == 4);
	bool cppVar_800 = (cmd == 1);
	bool cppVar_801 = cppVar_798 && cppVar_800;
	bool cppVar_803 = (cmdaddr == 65039);
	bool cppVar_804 = cppVar_801 && cppVar_803;
	bool cppVar_806 = (sha_state == 3);
	bool cppVar_808 = (cmd == 1);
	bool cppVar_809 = cppVar_806 && cppVar_808;
	bool cppVar_811 = (cmdaddr == 65039);
	bool cppVar_812 = cppVar_809 && cppVar_811;
	bool cppVar_814 = (sha_state == 2);
	bool cppVar_816 = (cmd == 1);
	bool cppVar_817 = cppVar_814 && cppVar_816;
	bool cppVar_819 = (cmdaddr == 65039);
	bool cppVar_820 = cppVar_817 && cppVar_819;
	bool cppVar_822 = (sha_state == 1);
	bool cppVar_824 = (cmd == 1);
	bool cppVar_825 = cppVar_822 && cppVar_824;
	bool cppVar_827 = (cmdaddr == 65039);
	bool cppVar_828 = cppVar_825 && cppVar_827;
	bool cppVar_830 = (sha_state == 4);
	bool cppVar_832 = (cmd == 1);
	bool cppVar_833 = cppVar_830 && cppVar_832;
	bool cppVar_835 = (cmdaddr == 65038);
	bool cppVar_836 = cppVar_833 && cppVar_835;
	bool cppVar_838 = (sha_state == 3);
	bool cppVar_840 = (cmd == 1);
	bool cppVar_841 = cppVar_838 && cppVar_840;
	bool cppVar_843 = (cmdaddr == 65038);
	bool cppVar_844 = cppVar_841 && cppVar_843;
	bool cppVar_846 = (sha_state == 2);
	bool cppVar_848 = (cmd == 1);
	bool cppVar_849 = cppVar_846 && cppVar_848;
	bool cppVar_851 = (cmdaddr == 65038);
	bool cppVar_852 = cppVar_849 && cppVar_851;
	bool cppVar_854 = (sha_state == 1);
	bool cppVar_856 = (cmd == 1);
	bool cppVar_857 = cppVar_854 && cppVar_856;
	bool cppVar_859 = (cmdaddr == 65038);
	bool cppVar_860 = cppVar_857 && cppVar_859;
	bool cppVar_862 = (sha_state == 4);
	bool cppVar_864 = (cmd == 1);
	bool cppVar_865 = cppVar_862 && cppVar_864;
	bool cppVar_867 = (cmdaddr == 65037);
	bool cppVar_868 = cppVar_865 && cppVar_867;
	bool cppVar_870 = (sha_state == 3);
	bool cppVar_872 = (cmd == 1);
	bool cppVar_873 = cppVar_870 && cppVar_872;
	bool cppVar_875 = (cmdaddr == 65037);
	bool cppVar_876 = cppVar_873 && cppVar_875;
	bool cppVar_878 = (sha_state == 2);
	bool cppVar_880 = (cmd == 1);
	bool cppVar_881 = cppVar_878 && cppVar_880;
	bool cppVar_883 = (cmdaddr == 65037);
	bool cppVar_884 = cppVar_881 && cppVar_883;
	bool cppVar_886 = (sha_state == 1);
	bool cppVar_888 = (cmd == 1);
	bool cppVar_889 = cppVar_886 && cppVar_888;
	bool cppVar_891 = (cmdaddr == 65037);
	bool cppVar_892 = cppVar_889 && cppVar_891;
	bool cppVar_894 = (sha_state == 4);
	bool cppVar_896 = (cmd == 1);
	bool cppVar_897 = cppVar_894 && cppVar_896;
	bool cppVar_899 = (cmdaddr == 65036);
	bool cppVar_900 = cppVar_897 && cppVar_899;
	bool cppVar_902 = (sha_state == 3);
	bool cppVar_904 = (cmd == 1);
	bool cppVar_905 = cppVar_902 && cppVar_904;
	bool cppVar_907 = (cmdaddr == 65036);
	bool cppVar_908 = cppVar_905 && cppVar_907;
	bool cppVar_910 = (sha_state == 2);
	bool cppVar_912 = (cmd == 1);
	bool cppVar_913 = cppVar_910 && cppVar_912;
	bool cppVar_915 = (cmdaddr == 65036);
	bool cppVar_916 = cppVar_913 && cppVar_915;
	bool cppVar_918 = (sha_state == 1);
	bool cppVar_920 = (cmd == 1);
	bool cppVar_921 = cppVar_918 && cppVar_920;
	bool cppVar_923 = (cmdaddr == 65036);
	bool cppVar_924 = cppVar_921 && cppVar_923;
	bool cppVar_926 = (sha_state == 4);
	bool cppVar_928 = (cmd == 1);
	bool cppVar_929 = cppVar_926 && cppVar_928;
	bool cppVar_931 = (cmdaddr == 65035);
	bool cppVar_932 = cppVar_929 && cppVar_931;
	bool cppVar_934 = (sha_state == 3);
	bool cppVar_936 = (cmd == 1);
	bool cppVar_937 = cppVar_934 && cppVar_936;
	bool cppVar_939 = (cmdaddr == 65035);
	bool cppVar_940 = cppVar_937 && cppVar_939;
	bool cppVar_942 = (sha_state == 2);
	bool cppVar_944 = (cmd == 1);
	bool cppVar_945 = cppVar_942 && cppVar_944;
	bool cppVar_947 = (cmdaddr == 65035);
	bool cppVar_948 = cppVar_945 && cppVar_947;
	bool cppVar_950 = (sha_state == 1);
	bool cppVar_952 = (cmd == 1);
	bool cppVar_953 = cppVar_950 && cppVar_952;
	bool cppVar_955 = (cmdaddr == 65035);
	bool cppVar_956 = cppVar_953 && cppVar_955;
	bool cppVar_958 = (sha_state == 4);
	bool cppVar_960 = (cmd == 1);
	bool cppVar_961 = cppVar_958 && cppVar_960;
	bool cppVar_963 = (cmdaddr == 65034);
	bool cppVar_964 = cppVar_961 && cppVar_963;
	bool cppVar_966 = (sha_state == 3);
	bool cppVar_968 = (cmd == 1);
	bool cppVar_969 = cppVar_966 && cppVar_968;
	bool cppVar_971 = (cmdaddr == 65034);
	bool cppVar_972 = cppVar_969 && cppVar_971;
	bool cppVar_974 = (sha_state == 2);
	bool cppVar_976 = (cmd == 1);
	bool cppVar_977 = cppVar_974 && cppVar_976;
	bool cppVar_979 = (cmdaddr == 65034);
	bool cppVar_980 = cppVar_977 && cppVar_979;
	bool cppVar_982 = (sha_state == 1);
	bool cppVar_984 = (cmd == 1);
	bool cppVar_985 = cppVar_982 && cppVar_984;
	bool cppVar_987 = (cmdaddr == 65034);
	bool cppVar_988 = cppVar_985 && cppVar_987;
	bool cppVar_990 = (sha_state == 4);
	bool cppVar_992 = (cmd == 1);
	bool cppVar_993 = cppVar_990 && cppVar_992;
	bool cppVar_995 = (cmdaddr == 65033);
	bool cppVar_996 = cppVar_993 && cppVar_995;
	bool cppVar_998 = (sha_state == 3);
	bool cppVar_1000 = (cmd == 1);
	bool cppVar_1001 = cppVar_998 && cppVar_1000;
	bool cppVar_1003 = (cmdaddr == 65033);
	bool cppVar_1004 = cppVar_1001 && cppVar_1003;
	bool cppVar_1006 = (sha_state == 2);
	bool cppVar_1008 = (cmd == 1);
	bool cppVar_1009 = cppVar_1006 && cppVar_1008;
	bool cppVar_1011 = (cmdaddr == 65033);
	bool cppVar_1012 = cppVar_1009 && cppVar_1011;
	bool cppVar_1014 = (sha_state == 1);
	bool cppVar_1016 = (cmd == 1);
	bool cppVar_1017 = cppVar_1014 && cppVar_1016;
	bool cppVar_1019 = (cmdaddr == 65033);
	bool cppVar_1020 = cppVar_1017 && cppVar_1019;
	bool cppVar_1022 = (sha_state == 4);
	bool cppVar_1024 = (cmd == 1);
	bool cppVar_1025 = cppVar_1022 && cppVar_1024;
	bool cppVar_1027 = (cmdaddr == 65032);
	bool cppVar_1028 = cppVar_1025 && cppVar_1027;
	bool cppVar_1030 = (sha_state == 3);
	bool cppVar_1032 = (cmd == 1);
	bool cppVar_1033 = cppVar_1030 && cppVar_1032;
	bool cppVar_1035 = (cmdaddr == 65032);
	bool cppVar_1036 = cppVar_1033 && cppVar_1035;
	bool cppVar_1038 = (sha_state == 2);
	bool cppVar_1040 = (cmd == 1);
	bool cppVar_1041 = cppVar_1038 && cppVar_1040;
	bool cppVar_1043 = (cmdaddr == 65032);
	bool cppVar_1044 = cppVar_1041 && cppVar_1043;
	bool cppVar_1046 = (sha_state == 1);
	bool cppVar_1048 = (cmd == 1);
	bool cppVar_1049 = cppVar_1046 && cppVar_1048;
	bool cppVar_1051 = (cmdaddr == 65032);
	bool cppVar_1052 = cppVar_1049 && cppVar_1051;
	bool cppVar_1054 = (sha_state == 4);
	bool cppVar_1056 = (cmd == 1);
	bool cppVar_1057 = cppVar_1054 && cppVar_1056;
	bool cppVar_1059 = (cmdaddr == 65024);
	bool cppVar_1060 = cppVar_1057 && cppVar_1059;
	bool cppVar_1062 = (sha_state == 3);
	bool cppVar_1064 = (cmd == 1);
	bool cppVar_1065 = cppVar_1062 && cppVar_1064;
	bool cppVar_1067 = (cmdaddr == 65024);
	bool cppVar_1068 = cppVar_1065 && cppVar_1067;
	bool cppVar_1070 = (sha_state == 2);
	bool cppVar_1072 = (cmd == 1);
	bool cppVar_1073 = cppVar_1070 && cppVar_1072;
	bool cppVar_1075 = (cmdaddr == 65024);
	bool cppVar_1076 = cppVar_1073 && cppVar_1075;
	bool cppVar_1078 = (sha_state == 1);
	bool cppVar_1080 = (cmd == 1);
	bool cppVar_1081 = cppVar_1078 && cppVar_1080;
	bool cppVar_1083 = (cmdaddr == 65024);
	bool cppVar_1084 = cppVar_1081 && cppVar_1083;
	bool cppVar_1085 = cppVar_1076 || cppVar_1084;
	bool cppVar_1086 = cppVar_1068 || cppVar_1085;
	bool cppVar_1087 = cppVar_1060 || cppVar_1086;
	bool cppVar_1088 = cppVar_1052 || cppVar_1087;
	bool cppVar_1089 = cppVar_1044 || cppVar_1088;
	bool cppVar_1090 = cppVar_1036 || cppVar_1089;
	bool cppVar_1091 = cppVar_1028 || cppVar_1090;
	bool cppVar_1092 = cppVar_1020 || cppVar_1091;
	bool cppVar_1093 = cppVar_1012 || cppVar_1092;
	bool cppVar_1094 = cppVar_1004 || cppVar_1093;
	bool cppVar_1095 = cppVar_996 || cppVar_1094;
	bool cppVar_1096 = cppVar_988 || cppVar_1095;
	bool cppVar_1097 = cppVar_980 || cppVar_1096;
	bool cppVar_1098 = cppVar_972 || cppVar_1097;
	bool cppVar_1099 = cppVar_964 || cppVar_1098;
	bool cppVar_1100 = cppVar_956 || cppVar_1099;
	bool cppVar_1101 = cppVar_948 || cppVar_1100;
	bool cppVar_1102 = cppVar_940 || cppVar_1101;
	bool cppVar_1103 = cppVar_932 || cppVar_1102;
	bool cppVar_1104 = cppVar_924 || cppVar_1103;
	bool cppVar_1105 = cppVar_916 || cppVar_1104;
	bool cppVar_1106 = cppVar_908 || cppVar_1105;
	bool cppVar_1107 = cppVar_900 || cppVar_1106;
	bool cppVar_1108 = cppVar_892 || cppVar_1107;
	bool cppVar_1109 = cppVar_884 || cppVar_1108;
	bool cppVar_1110 = cppVar_876 || cppVar_1109;
	bool cppVar_1111 = cppVar_868 || cppVar_1110;
	bool cppVar_1112 = cppVar_860 || cppVar_1111;
	bool cppVar_1113 = cppVar_852 || cppVar_1112;
	bool cppVar_1114 = cppVar_844 || cppVar_1113;
	bool cppVar_1115 = cppVar_836 || cppVar_1114;
	bool cppVar_1116 = cppVar_828 || cppVar_1115;
	bool cppVar_1117 = cppVar_820 || cppVar_1116;
	bool cppVar_1118 = cppVar_812 || cppVar_1117;
	bool cppVar_1119 = cppVar_804 || cppVar_1118;
	bool cppVar_1120 = cppVar_796 || cppVar_1119;
	bool cppVar_1121 = cppVar_788 || cppVar_1120;
	bool cppVar_1122 = cppVar_780 || cppVar_1121;
	bool cppVar_1123 = cppVar_772 || cppVar_1122;
	bool cppVar_1124 = cppVar_764 || cppVar_1123;
	bool cppVar_1125 = cppVar_756 || cppVar_1124;
	bool cppVar_1126 = cppVar_748 || cppVar_1125;
	bool cppVar_1127 = cppVar_740 || cppVar_1126;
	bool cppVar_1128 = cppVar_732 || cppVar_1127;
	bool cppVar_1129 = cppVar_724 || cppVar_1128;
	bool cppVar_1130 = cppVar_716 || cppVar_1129;
	bool cppVar_1131 = cppVar_708 || cppVar_1130;
	bool cppVar_1132 = cppVar_700 || cppVar_1131;
	bool cppVar_1133 = cppVar_692 || cppVar_1132;
	bool cppVar_1134 = cppVar_684 || cppVar_1133;
	bool cppVar_1135 = cppVar_676 || cppVar_1134;
	bool cppVar_1136 = cppVar_668 || cppVar_1135;
	bool cppVar_1137 = cppVar_660 || cppVar_1136;
	bool cppVar_1138 = cppVar_652 || cppVar_1137;
	bool cppVar_1139 = cppVar_644 || cppVar_1138;
	bool cppVar_1140 = cppVar_636 || cppVar_1139;
	bool cppVar_1141 = cppVar_628 || cppVar_1140;
	bool cppVar_1142 = cppVar_620 || cppVar_1141;
	bool cppVar_1143 = cppVar_612 || cppVar_1142;
	bool cppVar_1144 = cppVar_604 || cppVar_1143;
	bool cppVar_1145 = cppVar_596 || cppVar_1144;
	bool cppVar_1146 = cppVar_588 || cppVar_1145;
	bool cppVar_1147 = cppVar_580 || cppVar_1146;
	bool cppVar_1148 = cppVar_572 || cppVar_1147;
	bool cppVar_1149 = cppVar_564 || cppVar_1148;
	bool cppVar_1150 = cppVar_556 || cppVar_1149;
	bool cppVar_1151 = cppVar_548 || cppVar_1150;
	bool cppVar_1152 = cppVar_540 || cppVar_1151;
	bool cppVar_1153 = cppVar_532 || cppVar_1152;
	bool cppVar_1154 = cppVar_524 || cppVar_1153;
	bool cppVar_1155 = cppVar_516 || cppVar_1154;
	bool cppVar_1156 = cppVar_508 || cppVar_1155;
	bool cppVar_1157 = cppVar_500 || cppVar_1156;
	bool cppVar_1158 = cppVar_492 || cppVar_1157;
	bool cppVar_1159 = cppVar_484 || cppVar_1158;
	bool cppVar_1160 = cppVar_476 || cppVar_1159;
	bool cppVar_1161 = cppVar_468 || cppVar_1160;
	bool cppVar_1162 = cppVar_460 || cppVar_1161;
	bool cppVar_1163 = cppVar_452 || cppVar_1162;
	bool cppVar_1164 = cppVar_444 || cppVar_1163;
	bool cppVar_1165 = cppVar_436 || cppVar_1164;
	bool cppVar_1166 = cppVar_428 || cppVar_1165;
	bool cppVar_1167 = cppVar_420 || cppVar_1166;
	bool cppVar_1168 = cppVar_412 || cppVar_1167;
	bool cppVar_1169 = cppVar_404 || cppVar_1168;
	bool cppVar_1170 = cppVar_396 || cppVar_1169;
	bool cppVar_1171 = cppVar_388 || cppVar_1170;
	bool cppVar_1172 = cppVar_380 || cppVar_1171;
	bool cppVar_1173 = cppVar_372 || cppVar_1172;
	bool cppVar_1174 = cppVar_364 || cppVar_1173;
	bool cppVar_1175 = cppVar_356 || cppVar_1174;
	bool cppVar_1176 = cppVar_348 || cppVar_1175;
	bool cppVar_1177 = cppVar_340 || cppVar_1176;
	bool cppVar_1178 = cppVar_332 || cppVar_1177;
	bool cppVar_1179 = cppVar_324 || cppVar_1178;
	bool cppVar_1180 = cppVar_316 || cppVar_1179;
	bool cppVar_1181 = cppVar_308 || cppVar_1180;
	bool cppVar_1182 = cppVar_300 || cppVar_1181;
	bool cppVar_1183 = cppVar_292 || cppVar_1182;
	bool cppVar_1186 = (sha_state == 0);
	bool cppVar_1188 = (cmd == 2);
	bool cppVar_1189 = cppVar_1186 && cppVar_1188;
	bool cppVar_1191 = (cmdaddr == 65039);
	bool cppVar_1192 = cppVar_1189 && cppVar_1191;
	bool cppVar_1194 = (sha_state == 0);
	bool cppVar_1196 = (cmd == 2);
	bool cppVar_1197 = cppVar_1194 && cppVar_1196;
	bool cppVar_1199 = (cmdaddr == 65038);
	bool cppVar_1200 = cppVar_1197 && cppVar_1199;
	bool cppVar_1202 = (sha_state == 0);
	bool cppVar_1204 = (cmd == 2);
	bool cppVar_1205 = cppVar_1202 && cppVar_1204;
	bool cppVar_1207 = (cmdaddr == 65037);
	bool cppVar_1208 = cppVar_1205 && cppVar_1207;
	bool cppVar_1210 = (sha_state == 0);
	bool cppVar_1212 = (cmd == 2);
	bool cppVar_1213 = cppVar_1210 && cppVar_1212;
	bool cppVar_1215 = (cmdaddr == 65036);
	bool cppVar_1216 = cppVar_1213 && cppVar_1215;
	bool cppVar_1218 = (sha_state == 0);
	bool cppVar_1220 = (cmd == 2);
	bool cppVar_1221 = cppVar_1218 && cppVar_1220;
	bool cppVar_1223 = (cmdaddr == 65035);
	bool cppVar_1224 = cppVar_1221 && cppVar_1223;
	bool cppVar_1226 = (sha_state == 0);
	bool cppVar_1228 = (cmd == 2);
	bool cppVar_1229 = cppVar_1226 && cppVar_1228;
	bool cppVar_1231 = (cmdaddr == 65034);
	bool cppVar_1232 = cppVar_1229 && cppVar_1231;
	bool cppVar_1234 = (sha_state == 0);
	bool cppVar_1236 = (cmd == 2);
	bool cppVar_1237 = cppVar_1234 && cppVar_1236;
	bool cppVar_1239 = (cmdaddr == 65033);
	bool cppVar_1240 = cppVar_1237 && cppVar_1239;
	bool cppVar_1242 = (sha_state == 0);
	bool cppVar_1244 = (cmd == 2);
	bool cppVar_1245 = cppVar_1242 && cppVar_1244;
	bool cppVar_1247 = (cmdaddr == 65032);
	bool cppVar_1248 = cppVar_1245 && cppVar_1247;
	bool cppVar_1250 = (sha_state == 0);
	bool cppVar_1252 = (cmd == 2);
	bool cppVar_1253 = cppVar_1250 && cppVar_1252;
	bool cppVar_1255 = (cmdaddr == 65031);
	bool cppVar_1256 = cppVar_1253 && cppVar_1255;
	bool cppVar_1258 = (sha_state == 0);
	bool cppVar_1260 = (cmd == 2);
	bool cppVar_1261 = cppVar_1258 && cppVar_1260;
	bool cppVar_1263 = (cmdaddr == 65030);
	bool cppVar_1264 = cppVar_1261 && cppVar_1263;
	bool cppVar_1266 = (sha_state == 0);
	bool cppVar_1268 = (cmd == 2);
	bool cppVar_1269 = cppVar_1266 && cppVar_1268;
	bool cppVar_1271 = (cmdaddr == 65029);
	bool cppVar_1272 = cppVar_1269 && cppVar_1271;
	bool cppVar_1274 = (sha_state == 0);
	bool cppVar_1276 = (cmd == 2);
	bool cppVar_1277 = cppVar_1274 && cppVar_1276;
	bool cppVar_1279 = (cmdaddr == 65028);
	bool cppVar_1280 = cppVar_1277 && cppVar_1279;
	bool cppVar_1282 = (sha_state == 0);
	bool cppVar_1284 = (cmd == 2);
	bool cppVar_1285 = cppVar_1282 && cppVar_1284;
	bool cppVar_1287 = (cmdaddr == 65027);
	bool cppVar_1288 = cppVar_1285 && cppVar_1287;
	bool cppVar_1290 = (sha_state == 0);
	bool cppVar_1292 = (cmd == 2);
	bool cppVar_1293 = cppVar_1290 && cppVar_1292;
	bool cppVar_1295 = (cmdaddr == 65026);
	bool cppVar_1296 = cppVar_1293 && cppVar_1295;
	bool cppVar_1298 = (sha_state == 0);
	bool cppVar_1300 = (cmd == 2);
	bool cppVar_1301 = cppVar_1298 && cppVar_1300;
	bool cppVar_1303 = (cmdaddr == 65025);
	bool cppVar_1304 = cppVar_1301 && cppVar_1303;
	bool cppVar_1306 = (sha_state == 0);
	bool cppVar_1308 = (cmd == 2);
	bool cppVar_1309 = cppVar_1306 && cppVar_1308;
	bool cppVar_1311 = (cmdaddr == 65024);
	bool cppVar_1312 = cppVar_1309 && cppVar_1311;
	bool cppVar_1314 = (sha_state == 0);
	bool cppVar_1316 = (cmd == 1);
	bool cppVar_1317 = cppVar_1314 && cppVar_1316;
	bool cppVar_1319 = (cmdaddr == 65039);
	bool cppVar_1320 = cppVar_1317 && cppVar_1319;
	bool cppVar_1322 = (sha_state == 0);
	bool cppVar_1324 = (cmd == 1);
	bool cppVar_1325 = cppVar_1322 && cppVar_1324;
	bool cppVar_1327 = (cmdaddr == 65038);
	bool cppVar_1328 = cppVar_1325 && cppVar_1327;
	bool cppVar_1330 = (sha_state == 0);
	bool cppVar_1332 = (cmd == 1);
	bool cppVar_1333 = cppVar_1330 && cppVar_1332;
	bool cppVar_1335 = (cmdaddr == 65037);
	bool cppVar_1336 = cppVar_1333 && cppVar_1335;
	bool cppVar_1338 = (sha_state == 0);
	bool cppVar_1340 = (cmd == 1);
	bool cppVar_1341 = cppVar_1338 && cppVar_1340;
	bool cppVar_1343 = (cmdaddr == 65036);
	bool cppVar_1344 = cppVar_1341 && cppVar_1343;
	bool cppVar_1346 = (sha_state == 0);
	bool cppVar_1348 = (cmd == 1);
	bool cppVar_1349 = cppVar_1346 && cppVar_1348;
	bool cppVar_1351 = (cmdaddr == 65035);
	bool cppVar_1352 = cppVar_1349 && cppVar_1351;
	bool cppVar_1354 = (sha_state == 0);
	bool cppVar_1356 = (cmd == 1);
	bool cppVar_1357 = cppVar_1354 && cppVar_1356;
	bool cppVar_1359 = (cmdaddr == 65034);
	bool cppVar_1360 = cppVar_1357 && cppVar_1359;
	bool cppVar_1362 = (sha_state == 0);
	bool cppVar_1364 = (cmd == 1);
	bool cppVar_1365 = cppVar_1362 && cppVar_1364;
	bool cppVar_1367 = (cmdaddr == 65033);
	bool cppVar_1368 = cppVar_1365 && cppVar_1367;
	bool cppVar_1370 = (sha_state == 0);
	bool cppVar_1372 = (cmd == 1);
	bool cppVar_1373 = cppVar_1370 && cppVar_1372;
	bool cppVar_1375 = (cmdaddr == 65032);
	bool cppVar_1376 = cppVar_1373 && cppVar_1375;
	bool cppVar_1378 = (sha_state == 4);
	bool cppVar_1380 = (cmd == 1);
	bool cppVar_1381 = cppVar_1378 && cppVar_1380;
	bool cppVar_1383 = (cmdaddr == 65025);
	bool cppVar_1384 = cppVar_1381 && cppVar_1383;
	bool cppVar_1386 = (sha_state == 3);
	bool cppVar_1388 = (cmd == 1);
	bool cppVar_1389 = cppVar_1386 && cppVar_1388;
	bool cppVar_1391 = (cmdaddr == 65025);
	bool cppVar_1392 = cppVar_1389 && cppVar_1391;
	bool cppVar_1394 = (sha_state == 2);
	bool cppVar_1396 = (cmd == 1);
	bool cppVar_1397 = cppVar_1394 && cppVar_1396;
	bool cppVar_1399 = (cmdaddr == 65025);
	bool cppVar_1400 = cppVar_1397 && cppVar_1399;
	bool cppVar_1402 = (sha_state == 1);
	bool cppVar_1404 = (cmd == 1);
	bool cppVar_1405 = cppVar_1402 && cppVar_1404;
	bool cppVar_1407 = (cmdaddr == 65025);
	bool cppVar_1408 = cppVar_1405 && cppVar_1407;
	bool cppVar_1410 = (sha_state == 0);
	bool cppVar_1412 = (cmd == 1);
	bool cppVar_1413 = cppVar_1410 && cppVar_1412;
	bool cppVar_1415 = (cmdaddr == 65025);
	bool cppVar_1416 = cppVar_1413 && cppVar_1415;
	bool cppVar_1418 = (sha_state == 0);
	bool cppVar_1420 = (cmd == 1);
	bool cppVar_1421 = cppVar_1418 && cppVar_1420;
	bool cppVar_1423 = (cmdaddr == 65024);
	bool cppVar_1424 = cppVar_1421 && cppVar_1423;
	bool cppVar_1425 = cppVar_1416 || cppVar_1424;
	bool cppVar_1426 = cppVar_1408 || cppVar_1425;
	bool cppVar_1427 = cppVar_1400 || cppVar_1426;
	bool cppVar_1428 = cppVar_1392 || cppVar_1427;
	bool cppVar_1429 = cppVar_1384 || cppVar_1428;
	bool cppVar_1430 = cppVar_1376 || cppVar_1429;
	bool cppVar_1431 = cppVar_1368 || cppVar_1430;
	bool cppVar_1432 = cppVar_1360 || cppVar_1431;
	bool cppVar_1433 = cppVar_1352 || cppVar_1432;
	bool cppVar_1434 = cppVar_1344 || cppVar_1433;
	bool cppVar_1435 = cppVar_1336 || cppVar_1434;
	bool cppVar_1436 = cppVar_1328 || cppVar_1435;
	bool cppVar_1437 = cppVar_1320 || cppVar_1436;
	bool cppVar_1438 = cppVar_1312 || cppVar_1437;
	bool cppVar_1439 = cppVar_1304 || cppVar_1438;
	bool cppVar_1440 = cppVar_1296 || cppVar_1439;
	bool cppVar_1441 = cppVar_1288 || cppVar_1440;
	bool cppVar_1442 = cppVar_1280 || cppVar_1441;
	bool cppVar_1443 = cppVar_1272 || cppVar_1442;
	bool cppVar_1444 = cppVar_1264 || cppVar_1443;
	bool cppVar_1445 = cppVar_1256 || cppVar_1444;
	bool cppVar_1446 = cppVar_1248 || cppVar_1445;
	bool cppVar_1447 = cppVar_1240 || cppVar_1446;
	bool cppVar_1448 = cppVar_1232 || cppVar_1447;
	bool cppVar_1449 = cppVar_1224 || cppVar_1448;
	bool cppVar_1450 = cppVar_1216 || cppVar_1449;
	bool cppVar_1451 = cppVar_1208 || cppVar_1450;
	bool cppVar_1452 = cppVar_1200 || cppVar_1451;
	bool cppVar_1453 = cppVar_1192 || cppVar_1452;
	BIT_VEC cppVar_1454 = (sha_state & cppMask_un_3_);
	BIT_VEC cppVar_1455 = (cppVar_1453) ? cppVar_1454 : dataout;
	BIT_VEC cppVar_1456 = (cppVar_1183) ? 0 : cppVar_1455;
	BIT_VEC cppVar_1457 = (cppVar_283) ? cppVar_284 : cppVar_1456;
	BIT_VEC cppVar_1458 = (cppVar_238) ? cppVar_239 : cppVar_1457;
	BIT_VEC cppVar_1459 = (cppVar_193) ? cppVar_194 : cppVar_1458;
	BIT_VEC cppVar_1460 = (cppVar_148) ? cppVar_149 : cppVar_1459;
	BIT_VEC cppVar_1461 = (cppVar_103) ? cppVar_104 : cppVar_1460;
	BIT_VEC cppVar_1462 = (cppVar_58) ? cppVar_59 : cppVar_1461;
	return cppVar_1462;
}
BIT_VEC model_sha::cppUpdateFun_sha_bytes_read(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1465 = (sha_state == 0);
	bool cppVar_1467 = (cmd == 2);
	bool cppVar_1468 = cppVar_1465 && cppVar_1467;
	bool cppVar_1470 = (cmdaddr == 65024);
	bool cppVar_1471 = cppVar_1468 && cppVar_1470;
	bool cppVar_1473 = (cmddata == 1);
	BIT_VEC cppVar_1475 = (cppVar_1473) ? 0 : sha_bytes_read;
	bool cppVar_1477 = (sha_state == 1);
	bool cppVar_1479 = (cmd != 1);
	bool cppVar_1480 = cppVar_1477 && cppVar_1479;
	bool cppVar_1482 = (cmdaddr == 65039);
	bool cppVar_1483 = cppVar_1480 && cppVar_1482;
	bool cppVar_1485 = (sha_state == 1);
	bool cppVar_1487 = (cmd != 1);
	bool cppVar_1488 = cppVar_1485 && cppVar_1487;
	bool cppVar_1490 = (cmdaddr == 65038);
	bool cppVar_1491 = cppVar_1488 && cppVar_1490;
	bool cppVar_1493 = (sha_state == 1);
	bool cppVar_1495 = (cmd != 1);
	bool cppVar_1496 = cppVar_1493 && cppVar_1495;
	bool cppVar_1498 = (cmdaddr == 65037);
	bool cppVar_1499 = cppVar_1496 && cppVar_1498;
	bool cppVar_1501 = (sha_state == 1);
	bool cppVar_1503 = (cmd != 1);
	bool cppVar_1504 = cppVar_1501 && cppVar_1503;
	bool cppVar_1506 = (cmdaddr == 65036);
	bool cppVar_1507 = cppVar_1504 && cppVar_1506;
	bool cppVar_1509 = (sha_state == 1);
	bool cppVar_1511 = (cmd != 1);
	bool cppVar_1512 = cppVar_1509 && cppVar_1511;
	bool cppVar_1514 = (cmdaddr == 65035);
	bool cppVar_1515 = cppVar_1512 && cppVar_1514;
	bool cppVar_1517 = (sha_state == 1);
	bool cppVar_1519 = (cmd != 1);
	bool cppVar_1520 = cppVar_1517 && cppVar_1519;
	bool cppVar_1522 = (cmdaddr == 65034);
	bool cppVar_1523 = cppVar_1520 && cppVar_1522;
	bool cppVar_1525 = (sha_state == 1);
	bool cppVar_1527 = (cmd != 1);
	bool cppVar_1528 = cppVar_1525 && cppVar_1527;
	bool cppVar_1530 = (cmdaddr == 65033);
	bool cppVar_1531 = cppVar_1528 && cppVar_1530;
	bool cppVar_1533 = (sha_state == 1);
	bool cppVar_1535 = (cmd != 1);
	bool cppVar_1536 = cppVar_1533 && cppVar_1535;
	bool cppVar_1538 = (cmdaddr == 65032);
	bool cppVar_1539 = cppVar_1536 && cppVar_1538;
	bool cppVar_1541 = (sha_state == 1);
	bool cppVar_1543 = (cmd != 1);
	bool cppVar_1544 = cppVar_1541 && cppVar_1543;
	bool cppVar_1546 = (cmdaddr == 65031);
	bool cppVar_1547 = cppVar_1544 && cppVar_1546;
	bool cppVar_1549 = (sha_state == 1);
	bool cppVar_1551 = (cmd != 1);
	bool cppVar_1552 = cppVar_1549 && cppVar_1551;
	bool cppVar_1554 = (cmdaddr == 65030);
	bool cppVar_1555 = cppVar_1552 && cppVar_1554;
	bool cppVar_1557 = (sha_state == 1);
	bool cppVar_1559 = (cmd != 1);
	bool cppVar_1560 = cppVar_1557 && cppVar_1559;
	bool cppVar_1562 = (cmdaddr == 65029);
	bool cppVar_1563 = cppVar_1560 && cppVar_1562;
	bool cppVar_1565 = (sha_state == 1);
	bool cppVar_1567 = (cmd != 1);
	bool cppVar_1568 = cppVar_1565 && cppVar_1567;
	bool cppVar_1570 = (cmdaddr == 65028);
	bool cppVar_1571 = cppVar_1568 && cppVar_1570;
	bool cppVar_1573 = (sha_state == 1);
	bool cppVar_1575 = (cmd != 1);
	bool cppVar_1576 = cppVar_1573 && cppVar_1575;
	bool cppVar_1578 = (cmdaddr == 65027);
	bool cppVar_1579 = cppVar_1576 && cppVar_1578;
	bool cppVar_1581 = (sha_state == 1);
	bool cppVar_1583 = (cmd != 1);
	bool cppVar_1584 = cppVar_1581 && cppVar_1583;
	bool cppVar_1586 = (cmdaddr == 65026);
	bool cppVar_1587 = cppVar_1584 && cppVar_1586;
	bool cppVar_1589 = (sha_state == 1);
	bool cppVar_1591 = (cmd != 1);
	bool cppVar_1592 = cppVar_1589 && cppVar_1591;
	bool cppVar_1594 = (cmdaddr == 65025);
	bool cppVar_1595 = cppVar_1592 && cppVar_1594;
	bool cppVar_1597 = (sha_state == 1);
	bool cppVar_1599 = (cmd != 1);
	bool cppVar_1600 = cppVar_1597 && cppVar_1599;
	bool cppVar_1602 = (cmdaddr == 65024);
	bool cppVar_1603 = cppVar_1600 && cppVar_1602;
	bool cppVar_1605 = (sha_state == 1);
	bool cppVar_1607 = (cmd == 1);
	bool cppVar_1608 = cppVar_1605 && cppVar_1607;
	bool cppVar_1610 = (cmdaddr == 65039);
	bool cppVar_1611 = cppVar_1608 && cppVar_1610;
	bool cppVar_1613 = (sha_state == 1);
	bool cppVar_1615 = (cmd == 1);
	bool cppVar_1616 = cppVar_1613 && cppVar_1615;
	bool cppVar_1618 = (cmdaddr == 65038);
	bool cppVar_1619 = cppVar_1616 && cppVar_1618;
	bool cppVar_1621 = (sha_state == 1);
	bool cppVar_1623 = (cmd == 1);
	bool cppVar_1624 = cppVar_1621 && cppVar_1623;
	bool cppVar_1626 = (cmdaddr == 65037);
	bool cppVar_1627 = cppVar_1624 && cppVar_1626;
	bool cppVar_1629 = (sha_state == 1);
	bool cppVar_1631 = (cmd == 1);
	bool cppVar_1632 = cppVar_1629 && cppVar_1631;
	bool cppVar_1634 = (cmdaddr == 65036);
	bool cppVar_1635 = cppVar_1632 && cppVar_1634;
	bool cppVar_1637 = (sha_state == 1);
	bool cppVar_1639 = (cmd == 1);
	bool cppVar_1640 = cppVar_1637 && cppVar_1639;
	bool cppVar_1642 = (cmdaddr == 65035);
	bool cppVar_1643 = cppVar_1640 && cppVar_1642;
	bool cppVar_1645 = (sha_state == 1);
	bool cppVar_1647 = (cmd == 1);
	bool cppVar_1648 = cppVar_1645 && cppVar_1647;
	bool cppVar_1650 = (cmdaddr == 65034);
	bool cppVar_1651 = cppVar_1648 && cppVar_1650;
	bool cppVar_1653 = (sha_state == 1);
	bool cppVar_1655 = (cmd == 1);
	bool cppVar_1656 = cppVar_1653 && cppVar_1655;
	bool cppVar_1658 = (cmdaddr == 65033);
	bool cppVar_1659 = cppVar_1656 && cppVar_1658;
	bool cppVar_1661 = (sha_state == 1);
	bool cppVar_1663 = (cmd == 1);
	bool cppVar_1664 = cppVar_1661 && cppVar_1663;
	bool cppVar_1666 = (cmdaddr == 65032);
	bool cppVar_1667 = cppVar_1664 && cppVar_1666;
	bool cppVar_1669 = (sha_state == 1);
	bool cppVar_1671 = (cmd == 1);
	bool cppVar_1672 = cppVar_1669 && cppVar_1671;
	bool cppVar_1674 = (cmdaddr == 65031);
	bool cppVar_1675 = cppVar_1672 && cppVar_1674;
	bool cppVar_1677 = (sha_state == 1);
	bool cppVar_1679 = (cmd == 1);
	bool cppVar_1680 = cppVar_1677 && cppVar_1679;
	bool cppVar_1682 = (cmdaddr == 65030);
	bool cppVar_1683 = cppVar_1680 && cppVar_1682;
	bool cppVar_1685 = (sha_state == 1);
	bool cppVar_1687 = (cmd == 1);
	bool cppVar_1688 = cppVar_1685 && cppVar_1687;
	bool cppVar_1690 = (cmdaddr == 65029);
	bool cppVar_1691 = cppVar_1688 && cppVar_1690;
	bool cppVar_1693 = (sha_state == 1);
	bool cppVar_1695 = (cmd == 1);
	bool cppVar_1696 = cppVar_1693 && cppVar_1695;
	bool cppVar_1698 = (cmdaddr == 65028);
	bool cppVar_1699 = cppVar_1696 && cppVar_1698;
	bool cppVar_1701 = (sha_state == 1);
	bool cppVar_1703 = (cmd == 1);
	bool cppVar_1704 = cppVar_1701 && cppVar_1703;
	bool cppVar_1706 = (cmdaddr == 65027);
	bool cppVar_1707 = cppVar_1704 && cppVar_1706;
	bool cppVar_1709 = (sha_state == 1);
	bool cppVar_1711 = (cmd == 1);
	bool cppVar_1712 = cppVar_1709 && cppVar_1711;
	bool cppVar_1714 = (cmdaddr == 65026);
	bool cppVar_1715 = cppVar_1712 && cppVar_1714;
	bool cppVar_1717 = (sha_state == 1);
	bool cppVar_1719 = (cmd == 1);
	bool cppVar_1720 = cppVar_1717 && cppVar_1719;
	bool cppVar_1722 = (cmdaddr == 65025);
	bool cppVar_1723 = cppVar_1720 && cppVar_1722;
	bool cppVar_1725 = (sha_state == 1);
	bool cppVar_1727 = (cmd == 1);
	bool cppVar_1728 = cppVar_1725 && cppVar_1727;
	bool cppVar_1730 = (cmdaddr == 65024);
	bool cppVar_1731 = cppVar_1728 && cppVar_1730;
	bool cppVar_1732 = cppVar_1723 || cppVar_1731;
	bool cppVar_1733 = cppVar_1715 || cppVar_1732;
	bool cppVar_1734 = cppVar_1707 || cppVar_1733;
	bool cppVar_1735 = cppVar_1699 || cppVar_1734;
	bool cppVar_1736 = cppVar_1691 || cppVar_1735;
	bool cppVar_1737 = cppVar_1683 || cppVar_1736;
	bool cppVar_1738 = cppVar_1675 || cppVar_1737;
	bool cppVar_1739 = cppVar_1667 || cppVar_1738;
	bool cppVar_1740 = cppVar_1659 || cppVar_1739;
	bool cppVar_1741 = cppVar_1651 || cppVar_1740;
	bool cppVar_1742 = cppVar_1643 || cppVar_1741;
	bool cppVar_1743 = cppVar_1635 || cppVar_1742;
	bool cppVar_1744 = cppVar_1627 || cppVar_1743;
	bool cppVar_1745 = cppVar_1619 || cppVar_1744;
	bool cppVar_1746 = cppVar_1611 || cppVar_1745;
	bool cppVar_1747 = cppVar_1603 || cppVar_1746;
	bool cppVar_1748 = cppVar_1595 || cppVar_1747;
	bool cppVar_1749 = cppVar_1587 || cppVar_1748;
	bool cppVar_1750 = cppVar_1579 || cppVar_1749;
	bool cppVar_1751 = cppVar_1571 || cppVar_1750;
	bool cppVar_1752 = cppVar_1563 || cppVar_1751;
	bool cppVar_1753 = cppVar_1555 || cppVar_1752;
	bool cppVar_1754 = cppVar_1547 || cppVar_1753;
	bool cppVar_1755 = cppVar_1539 || cppVar_1754;
	bool cppVar_1756 = cppVar_1531 || cppVar_1755;
	bool cppVar_1757 = cppVar_1523 || cppVar_1756;
	bool cppVar_1758 = cppVar_1515 || cppVar_1757;
	bool cppVar_1759 = cppVar_1507 || cppVar_1758;
	bool cppVar_1760 = cppVar_1499 || cppVar_1759;
	bool cppVar_1761 = cppVar_1491 || cppVar_1760;
	bool cppVar_1762 = cppVar_1483 || cppVar_1761;
	BIT_VEC cppVar_1764 = sha_bytes_read + 64;
	cppVar_1764 = (cppVar_1764 & cppMask_un_16_);
	BIT_VEC cppVar_1765 = (cppVar_1762) ? cppVar_1764 : sha_bytes_read;
	BIT_VEC cppVar_1766 = (cppVar_1471) ? cppVar_1475 : cppVar_1765;
	return cppVar_1766;
}
BIT_VEC model_sha::cppUpdateFun_sha_hs_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1769 = (sha_state == 3);
	bool cppVar_1771 = (cmd != 1);
	bool cppVar_1772 = cppVar_1769 && cppVar_1771;
	bool cppVar_1774 = (cmdaddr == 65039);
	bool cppVar_1775 = cppVar_1772 && cppVar_1774;
	bool cppVar_1777 = (sha_state == 3);
	bool cppVar_1779 = (cmd != 1);
	bool cppVar_1780 = cppVar_1777 && cppVar_1779;
	bool cppVar_1782 = (cmdaddr == 65038);
	bool cppVar_1783 = cppVar_1780 && cppVar_1782;
	bool cppVar_1785 = (sha_state == 3);
	bool cppVar_1787 = (cmd != 1);
	bool cppVar_1788 = cppVar_1785 && cppVar_1787;
	bool cppVar_1790 = (cmdaddr == 65037);
	bool cppVar_1791 = cppVar_1788 && cppVar_1790;
	bool cppVar_1793 = (sha_state == 3);
	bool cppVar_1795 = (cmd != 1);
	bool cppVar_1796 = cppVar_1793 && cppVar_1795;
	bool cppVar_1798 = (cmdaddr == 65036);
	bool cppVar_1799 = cppVar_1796 && cppVar_1798;
	bool cppVar_1801 = (sha_state == 3);
	bool cppVar_1803 = (cmd != 1);
	bool cppVar_1804 = cppVar_1801 && cppVar_1803;
	bool cppVar_1806 = (cmdaddr == 65035);
	bool cppVar_1807 = cppVar_1804 && cppVar_1806;
	bool cppVar_1809 = (sha_state == 3);
	bool cppVar_1811 = (cmd != 1);
	bool cppVar_1812 = cppVar_1809 && cppVar_1811;
	bool cppVar_1814 = (cmdaddr == 65034);
	bool cppVar_1815 = cppVar_1812 && cppVar_1814;
	bool cppVar_1817 = (sha_state == 3);
	bool cppVar_1819 = (cmd != 1);
	bool cppVar_1820 = cppVar_1817 && cppVar_1819;
	bool cppVar_1822 = (cmdaddr == 65033);
	bool cppVar_1823 = cppVar_1820 && cppVar_1822;
	bool cppVar_1825 = (sha_state == 3);
	bool cppVar_1827 = (cmd != 1);
	bool cppVar_1828 = cppVar_1825 && cppVar_1827;
	bool cppVar_1830 = (cmdaddr == 65032);
	bool cppVar_1831 = cppVar_1828 && cppVar_1830;
	bool cppVar_1833 = (sha_state == 3);
	bool cppVar_1835 = (cmd != 1);
	bool cppVar_1836 = cppVar_1833 && cppVar_1835;
	bool cppVar_1838 = (cmdaddr == 65031);
	bool cppVar_1839 = cppVar_1836 && cppVar_1838;
	bool cppVar_1841 = (sha_state == 3);
	bool cppVar_1843 = (cmd != 1);
	bool cppVar_1844 = cppVar_1841 && cppVar_1843;
	bool cppVar_1846 = (cmdaddr == 65030);
	bool cppVar_1847 = cppVar_1844 && cppVar_1846;
	bool cppVar_1849 = (sha_state == 3);
	bool cppVar_1851 = (cmd != 1);
	bool cppVar_1852 = cppVar_1849 && cppVar_1851;
	bool cppVar_1854 = (cmdaddr == 65029);
	bool cppVar_1855 = cppVar_1852 && cppVar_1854;
	bool cppVar_1857 = (sha_state == 3);
	bool cppVar_1859 = (cmd != 1);
	bool cppVar_1860 = cppVar_1857 && cppVar_1859;
	bool cppVar_1862 = (cmdaddr == 65028);
	bool cppVar_1863 = cppVar_1860 && cppVar_1862;
	bool cppVar_1865 = (sha_state == 3);
	bool cppVar_1867 = (cmd != 1);
	bool cppVar_1868 = cppVar_1865 && cppVar_1867;
	bool cppVar_1870 = (cmdaddr == 65027);
	bool cppVar_1871 = cppVar_1868 && cppVar_1870;
	bool cppVar_1873 = (sha_state == 3);
	bool cppVar_1875 = (cmd != 1);
	bool cppVar_1876 = cppVar_1873 && cppVar_1875;
	bool cppVar_1878 = (cmdaddr == 65026);
	bool cppVar_1879 = cppVar_1876 && cppVar_1878;
	bool cppVar_1881 = (sha_state == 3);
	bool cppVar_1883 = (cmd != 1);
	bool cppVar_1884 = cppVar_1881 && cppVar_1883;
	bool cppVar_1886 = (cmdaddr == 65025);
	bool cppVar_1887 = cppVar_1884 && cppVar_1886;
	bool cppVar_1889 = (sha_state == 3);
	bool cppVar_1891 = (cmd != 1);
	bool cppVar_1892 = cppVar_1889 && cppVar_1891;
	bool cppVar_1894 = (cmdaddr == 65024);
	bool cppVar_1895 = cppVar_1892 && cppVar_1894;
	bool cppVar_1897 = (sha_state == 3);
	bool cppVar_1899 = (cmd == 1);
	bool cppVar_1900 = cppVar_1897 && cppVar_1899;
	bool cppVar_1902 = (cmdaddr == 65039);
	bool cppVar_1903 = cppVar_1900 && cppVar_1902;
	bool cppVar_1905 = (sha_state == 3);
	bool cppVar_1907 = (cmd == 1);
	bool cppVar_1908 = cppVar_1905 && cppVar_1907;
	bool cppVar_1910 = (cmdaddr == 65038);
	bool cppVar_1911 = cppVar_1908 && cppVar_1910;
	bool cppVar_1913 = (sha_state == 3);
	bool cppVar_1915 = (cmd == 1);
	bool cppVar_1916 = cppVar_1913 && cppVar_1915;
	bool cppVar_1918 = (cmdaddr == 65037);
	bool cppVar_1919 = cppVar_1916 && cppVar_1918;
	bool cppVar_1921 = (sha_state == 3);
	bool cppVar_1923 = (cmd == 1);
	bool cppVar_1924 = cppVar_1921 && cppVar_1923;
	bool cppVar_1926 = (cmdaddr == 65036);
	bool cppVar_1927 = cppVar_1924 && cppVar_1926;
	bool cppVar_1929 = (sha_state == 3);
	bool cppVar_1931 = (cmd == 1);
	bool cppVar_1932 = cppVar_1929 && cppVar_1931;
	bool cppVar_1934 = (cmdaddr == 65035);
	bool cppVar_1935 = cppVar_1932 && cppVar_1934;
	bool cppVar_1937 = (sha_state == 3);
	bool cppVar_1939 = (cmd == 1);
	bool cppVar_1940 = cppVar_1937 && cppVar_1939;
	bool cppVar_1942 = (cmdaddr == 65034);
	bool cppVar_1943 = cppVar_1940 && cppVar_1942;
	bool cppVar_1945 = (sha_state == 3);
	bool cppVar_1947 = (cmd == 1);
	bool cppVar_1948 = cppVar_1945 && cppVar_1947;
	bool cppVar_1950 = (cmdaddr == 65033);
	bool cppVar_1951 = cppVar_1948 && cppVar_1950;
	bool cppVar_1953 = (sha_state == 3);
	bool cppVar_1955 = (cmd == 1);
	bool cppVar_1956 = cppVar_1953 && cppVar_1955;
	bool cppVar_1958 = (cmdaddr == 65032);
	bool cppVar_1959 = cppVar_1956 && cppVar_1958;
	bool cppVar_1961 = (sha_state == 3);
	bool cppVar_1963 = (cmd == 1);
	bool cppVar_1964 = cppVar_1961 && cppVar_1963;
	bool cppVar_1966 = (cmdaddr == 65031);
	bool cppVar_1967 = cppVar_1964 && cppVar_1966;
	bool cppVar_1969 = (sha_state == 3);
	bool cppVar_1971 = (cmd == 1);
	bool cppVar_1972 = cppVar_1969 && cppVar_1971;
	bool cppVar_1974 = (cmdaddr == 65030);
	bool cppVar_1975 = cppVar_1972 && cppVar_1974;
	bool cppVar_1977 = (sha_state == 3);
	bool cppVar_1979 = (cmd == 1);
	bool cppVar_1980 = cppVar_1977 && cppVar_1979;
	bool cppVar_1982 = (cmdaddr == 65029);
	bool cppVar_1983 = cppVar_1980 && cppVar_1982;
	bool cppVar_1985 = (sha_state == 3);
	bool cppVar_1987 = (cmd == 1);
	bool cppVar_1988 = cppVar_1985 && cppVar_1987;
	bool cppVar_1990 = (cmdaddr == 65028);
	bool cppVar_1991 = cppVar_1988 && cppVar_1990;
	bool cppVar_1993 = (sha_state == 3);
	bool cppVar_1995 = (cmd == 1);
	bool cppVar_1996 = cppVar_1993 && cppVar_1995;
	bool cppVar_1998 = (cmdaddr == 65027);
	bool cppVar_1999 = cppVar_1996 && cppVar_1998;
	bool cppVar_2001 = (sha_state == 3);
	bool cppVar_2003 = (cmd == 1);
	bool cppVar_2004 = cppVar_2001 && cppVar_2003;
	bool cppVar_2006 = (cmdaddr == 65026);
	bool cppVar_2007 = cppVar_2004 && cppVar_2006;
	bool cppVar_2009 = (sha_state == 3);
	bool cppVar_2011 = (cmd == 1);
	bool cppVar_2012 = cppVar_2009 && cppVar_2011;
	bool cppVar_2014 = (cmdaddr == 65025);
	bool cppVar_2015 = cppVar_2012 && cppVar_2014;
	bool cppVar_2017 = (sha_state == 3);
	bool cppVar_2019 = (cmd == 1);
	bool cppVar_2020 = cppVar_2017 && cppVar_2019;
	bool cppVar_2022 = (cmdaddr == 65024);
	bool cppVar_2023 = cppVar_2020 && cppVar_2022;
	bool cppVar_2024 = cppVar_2015 || cppVar_2023;
	bool cppVar_2025 = cppVar_2007 || cppVar_2024;
	bool cppVar_2026 = cppVar_1999 || cppVar_2025;
	bool cppVar_2027 = cppVar_1991 || cppVar_2026;
	bool cppVar_2028 = cppVar_1983 || cppVar_2027;
	bool cppVar_2029 = cppVar_1975 || cppVar_2028;
	bool cppVar_2030 = cppVar_1967 || cppVar_2029;
	bool cppVar_2031 = cppVar_1959 || cppVar_2030;
	bool cppVar_2032 = cppVar_1951 || cppVar_2031;
	bool cppVar_2033 = cppVar_1943 || cppVar_2032;
	bool cppVar_2034 = cppVar_1935 || cppVar_2033;
	bool cppVar_2035 = cppVar_1927 || cppVar_2034;
	bool cppVar_2036 = cppVar_1919 || cppVar_2035;
	bool cppVar_2037 = cppVar_1911 || cppVar_2036;
	bool cppVar_2038 = cppVar_1903 || cppVar_2037;
	bool cppVar_2039 = cppVar_1895 || cppVar_2038;
	bool cppVar_2040 = cppVar_1887 || cppVar_2039;
	bool cppVar_2041 = cppVar_1879 || cppVar_2040;
	bool cppVar_2042 = cppVar_1871 || cppVar_2041;
	bool cppVar_2043 = cppVar_1863 || cppVar_2042;
	bool cppVar_2044 = cppVar_1855 || cppVar_2043;
	bool cppVar_2045 = cppVar_1847 || cppVar_2044;
	bool cppVar_2046 = cppVar_1839 || cppVar_2045;
	bool cppVar_2047 = cppVar_1831 || cppVar_2046;
	bool cppVar_2048 = cppVar_1823 || cppVar_2047;
	bool cppVar_2049 = cppVar_1815 || cppVar_2048;
	bool cppVar_2050 = cppVar_1807 || cppVar_2049;
	bool cppVar_2051 = cppVar_1799 || cppVar_2050;
	bool cppVar_2052 = cppVar_1791 || cppVar_2051;
	bool cppVar_2053 = cppVar_1783 || cppVar_2052;
	bool cppVar_2054 = cppVar_1775 || cppVar_2053;
	BIT_VEC cppVar_2055 = sha(sha_rd_data);
	BIT_VEC cppVar_2056 = (cppVar_2054) ? cppVar_2055 : sha_hs_data;
	return cppVar_2056;
}
BIT_VEC model_sha::cppUpdateFun_sha_len(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2059 = (sha_state == 0);
	bool cppVar_2061 = (cmd == 2);
	bool cppVar_2062 = cppVar_2059 && cppVar_2061;
	bool cppVar_2064 = (cmdaddr == 65031);
	bool cppVar_2065 = cppVar_2062 && cppVar_2064;
	BIT_VEC cppVar_2066 = (sha_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_2067 = (cmddata << 8) | cppVar_2066;
	cppVar_2067 = (cppVar_2067 & cppMask_un_16_);
	bool cppVar_2069 = (sha_state == 0);
	bool cppVar_2071 = (cmd == 2);
	bool cppVar_2072 = cppVar_2069 && cppVar_2071;
	bool cppVar_2074 = (cmdaddr == 65030);
	bool cppVar_2075 = cppVar_2072 && cppVar_2074;
	BIT_VEC cppVar_2076 = (sha_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_2077 = (cppVar_2076 << 8) | cmddata;
	cppVar_2077 = (cppVar_2077 & cppMask_un_16_);
	BIT_VEC cppVar_2078 = (cppVar_2075) ? cppVar_2077 : sha_len;
	BIT_VEC cppVar_2079 = (cppVar_2065) ? cppVar_2067 : cppVar_2078;
	return cppVar_2079;
}
BIT_VEC model_sha::cppUpdateFun_sha_rd_data(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2082 = (sha_state == 1);
	bool cppVar_2084 = (cmd != 1);
	bool cppVar_2085 = cppVar_2082 && cppVar_2084;
	bool cppVar_2087 = (cmdaddr == 65039);
	bool cppVar_2088 = cppVar_2085 && cppVar_2087;
	bool cppVar_2090 = (sha_state == 1);
	bool cppVar_2092 = (cmd != 1);
	bool cppVar_2093 = cppVar_2090 && cppVar_2092;
	bool cppVar_2095 = (cmdaddr == 65038);
	bool cppVar_2096 = cppVar_2093 && cppVar_2095;
	bool cppVar_2098 = (sha_state == 1);
	bool cppVar_2100 = (cmd != 1);
	bool cppVar_2101 = cppVar_2098 && cppVar_2100;
	bool cppVar_2103 = (cmdaddr == 65037);
	bool cppVar_2104 = cppVar_2101 && cppVar_2103;
	bool cppVar_2106 = (sha_state == 1);
	bool cppVar_2108 = (cmd != 1);
	bool cppVar_2109 = cppVar_2106 && cppVar_2108;
	bool cppVar_2111 = (cmdaddr == 65036);
	bool cppVar_2112 = cppVar_2109 && cppVar_2111;
	bool cppVar_2114 = (sha_state == 1);
	bool cppVar_2116 = (cmd != 1);
	bool cppVar_2117 = cppVar_2114 && cppVar_2116;
	bool cppVar_2119 = (cmdaddr == 65035);
	bool cppVar_2120 = cppVar_2117 && cppVar_2119;
	bool cppVar_2122 = (sha_state == 1);
	bool cppVar_2124 = (cmd != 1);
	bool cppVar_2125 = cppVar_2122 && cppVar_2124;
	bool cppVar_2127 = (cmdaddr == 65034);
	bool cppVar_2128 = cppVar_2125 && cppVar_2127;
	bool cppVar_2130 = (sha_state == 1);
	bool cppVar_2132 = (cmd != 1);
	bool cppVar_2133 = cppVar_2130 && cppVar_2132;
	bool cppVar_2135 = (cmdaddr == 65033);
	bool cppVar_2136 = cppVar_2133 && cppVar_2135;
	bool cppVar_2138 = (sha_state == 1);
	bool cppVar_2140 = (cmd != 1);
	bool cppVar_2141 = cppVar_2138 && cppVar_2140;
	bool cppVar_2143 = (cmdaddr == 65032);
	bool cppVar_2144 = cppVar_2141 && cppVar_2143;
	bool cppVar_2146 = (sha_state == 1);
	bool cppVar_2148 = (cmd != 1);
	bool cppVar_2149 = cppVar_2146 && cppVar_2148;
	bool cppVar_2151 = (cmdaddr == 65031);
	bool cppVar_2152 = cppVar_2149 && cppVar_2151;
	bool cppVar_2154 = (sha_state == 1);
	bool cppVar_2156 = (cmd != 1);
	bool cppVar_2157 = cppVar_2154 && cppVar_2156;
	bool cppVar_2159 = (cmdaddr == 65030);
	bool cppVar_2160 = cppVar_2157 && cppVar_2159;
	bool cppVar_2162 = (sha_state == 1);
	bool cppVar_2164 = (cmd != 1);
	bool cppVar_2165 = cppVar_2162 && cppVar_2164;
	bool cppVar_2167 = (cmdaddr == 65029);
	bool cppVar_2168 = cppVar_2165 && cppVar_2167;
	bool cppVar_2170 = (sha_state == 1);
	bool cppVar_2172 = (cmd != 1);
	bool cppVar_2173 = cppVar_2170 && cppVar_2172;
	bool cppVar_2175 = (cmdaddr == 65028);
	bool cppVar_2176 = cppVar_2173 && cppVar_2175;
	bool cppVar_2178 = (sha_state == 1);
	bool cppVar_2180 = (cmd != 1);
	bool cppVar_2181 = cppVar_2178 && cppVar_2180;
	bool cppVar_2183 = (cmdaddr == 65027);
	bool cppVar_2184 = cppVar_2181 && cppVar_2183;
	bool cppVar_2186 = (sha_state == 1);
	bool cppVar_2188 = (cmd != 1);
	bool cppVar_2189 = cppVar_2186 && cppVar_2188;
	bool cppVar_2191 = (cmdaddr == 65026);
	bool cppVar_2192 = cppVar_2189 && cppVar_2191;
	bool cppVar_2194 = (sha_state == 1);
	bool cppVar_2196 = (cmd != 1);
	bool cppVar_2197 = cppVar_2194 && cppVar_2196;
	bool cppVar_2199 = (cmdaddr == 65025);
	bool cppVar_2200 = cppVar_2197 && cppVar_2199;
	bool cppVar_2202 = (sha_state == 1);
	bool cppVar_2204 = (cmd != 1);
	bool cppVar_2205 = cppVar_2202 && cppVar_2204;
	bool cppVar_2207 = (cmdaddr == 65024);
	bool cppVar_2208 = cppVar_2205 && cppVar_2207;
	bool cppVar_2210 = (sha_state == 1);
	bool cppVar_2212 = (cmd == 1);
	bool cppVar_2213 = cppVar_2210 && cppVar_2212;
	bool cppVar_2215 = (cmdaddr == 65039);
	bool cppVar_2216 = cppVar_2213 && cppVar_2215;
	bool cppVar_2218 = (sha_state == 1);
	bool cppVar_2220 = (cmd == 1);
	bool cppVar_2221 = cppVar_2218 && cppVar_2220;
	bool cppVar_2223 = (cmdaddr == 65038);
	bool cppVar_2224 = cppVar_2221 && cppVar_2223;
	bool cppVar_2226 = (sha_state == 1);
	bool cppVar_2228 = (cmd == 1);
	bool cppVar_2229 = cppVar_2226 && cppVar_2228;
	bool cppVar_2231 = (cmdaddr == 65037);
	bool cppVar_2232 = cppVar_2229 && cppVar_2231;
	bool cppVar_2234 = (sha_state == 1);
	bool cppVar_2236 = (cmd == 1);
	bool cppVar_2237 = cppVar_2234 && cppVar_2236;
	bool cppVar_2239 = (cmdaddr == 65036);
	bool cppVar_2240 = cppVar_2237 && cppVar_2239;
	bool cppVar_2242 = (sha_state == 1);
	bool cppVar_2244 = (cmd == 1);
	bool cppVar_2245 = cppVar_2242 && cppVar_2244;
	bool cppVar_2247 = (cmdaddr == 65035);
	bool cppVar_2248 = cppVar_2245 && cppVar_2247;
	bool cppVar_2250 = (sha_state == 1);
	bool cppVar_2252 = (cmd == 1);
	bool cppVar_2253 = cppVar_2250 && cppVar_2252;
	bool cppVar_2255 = (cmdaddr == 65034);
	bool cppVar_2256 = cppVar_2253 && cppVar_2255;
	bool cppVar_2258 = (sha_state == 1);
	bool cppVar_2260 = (cmd == 1);
	bool cppVar_2261 = cppVar_2258 && cppVar_2260;
	bool cppVar_2263 = (cmdaddr == 65033);
	bool cppVar_2264 = cppVar_2261 && cppVar_2263;
	bool cppVar_2266 = (sha_state == 1);
	bool cppVar_2268 = (cmd == 1);
	bool cppVar_2269 = cppVar_2266 && cppVar_2268;
	bool cppVar_2271 = (cmdaddr == 65032);
	bool cppVar_2272 = cppVar_2269 && cppVar_2271;
	bool cppVar_2274 = (sha_state == 1);
	bool cppVar_2276 = (cmd == 1);
	bool cppVar_2277 = cppVar_2274 && cppVar_2276;
	bool cppVar_2279 = (cmdaddr == 65031);
	bool cppVar_2280 = cppVar_2277 && cppVar_2279;
	bool cppVar_2282 = (sha_state == 1);
	bool cppVar_2284 = (cmd == 1);
	bool cppVar_2285 = cppVar_2282 && cppVar_2284;
	bool cppVar_2287 = (cmdaddr == 65030);
	bool cppVar_2288 = cppVar_2285 && cppVar_2287;
	bool cppVar_2290 = (sha_state == 1);
	bool cppVar_2292 = (cmd == 1);
	bool cppVar_2293 = cppVar_2290 && cppVar_2292;
	bool cppVar_2295 = (cmdaddr == 65029);
	bool cppVar_2296 = cppVar_2293 && cppVar_2295;
	bool cppVar_2298 = (sha_state == 1);
	bool cppVar_2300 = (cmd == 1);
	bool cppVar_2301 = cppVar_2298 && cppVar_2300;
	bool cppVar_2303 = (cmdaddr == 65028);
	bool cppVar_2304 = cppVar_2301 && cppVar_2303;
	bool cppVar_2306 = (sha_state == 1);
	bool cppVar_2308 = (cmd == 1);
	bool cppVar_2309 = cppVar_2306 && cppVar_2308;
	bool cppVar_2311 = (cmdaddr == 65027);
	bool cppVar_2312 = cppVar_2309 && cppVar_2311;
	bool cppVar_2314 = (sha_state == 1);
	bool cppVar_2316 = (cmd == 1);
	bool cppVar_2317 = cppVar_2314 && cppVar_2316;
	bool cppVar_2319 = (cmdaddr == 65026);
	bool cppVar_2320 = cppVar_2317 && cppVar_2319;
	bool cppVar_2322 = (sha_state == 1);
	bool cppVar_2324 = (cmd == 1);
	bool cppVar_2325 = cppVar_2322 && cppVar_2324;
	bool cppVar_2327 = (cmdaddr == 65025);
	bool cppVar_2328 = cppVar_2325 && cppVar_2327;
	bool cppVar_2330 = (sha_state == 1);
	bool cppVar_2332 = (cmd == 1);
	bool cppVar_2333 = cppVar_2330 && cppVar_2332;
	bool cppVar_2335 = (cmdaddr == 65024);
	bool cppVar_2336 = cppVar_2333 && cppVar_2335;
	bool cppVar_2337 = cppVar_2328 || cppVar_2336;
	bool cppVar_2338 = cppVar_2320 || cppVar_2337;
	bool cppVar_2339 = cppVar_2312 || cppVar_2338;
	bool cppVar_2340 = cppVar_2304 || cppVar_2339;
	bool cppVar_2341 = cppVar_2296 || cppVar_2340;
	bool cppVar_2342 = cppVar_2288 || cppVar_2341;
	bool cppVar_2343 = cppVar_2280 || cppVar_2342;
	bool cppVar_2344 = cppVar_2272 || cppVar_2343;
	bool cppVar_2345 = cppVar_2264 || cppVar_2344;
	bool cppVar_2346 = cppVar_2256 || cppVar_2345;
	bool cppVar_2347 = cppVar_2248 || cppVar_2346;
	bool cppVar_2348 = cppVar_2240 || cppVar_2347;
	bool cppVar_2349 = cppVar_2232 || cppVar_2348;
	bool cppVar_2350 = cppVar_2224 || cppVar_2349;
	bool cppVar_2351 = cppVar_2216 || cppVar_2350;
	bool cppVar_2352 = cppVar_2208 || cppVar_2351;
	bool cppVar_2353 = cppVar_2200 || cppVar_2352;
	bool cppVar_2354 = cppVar_2192 || cppVar_2353;
	bool cppVar_2355 = cppVar_2184 || cppVar_2354;
	bool cppVar_2356 = cppVar_2176 || cppVar_2355;
	bool cppVar_2357 = cppVar_2168 || cppVar_2356;
	bool cppVar_2358 = cppVar_2160 || cppVar_2357;
	bool cppVar_2359 = cppVar_2152 || cppVar_2358;
	bool cppVar_2360 = cppVar_2144 || cppVar_2359;
	bool cppVar_2361 = cppVar_2136 || cppVar_2360;
	bool cppVar_2362 = cppVar_2128 || cppVar_2361;
	bool cppVar_2363 = cppVar_2120 || cppVar_2362;
	bool cppVar_2364 = cppVar_2112 || cppVar_2363;
	bool cppVar_2365 = cppVar_2104 || cppVar_2364;
	bool cppVar_2366 = cppVar_2096 || cppVar_2365;
	bool cppVar_2367 = cppVar_2088 || cppVar_2366;
	BIT_VEC cppVar_2368 = sha_rdaddr + sha_bytes_read;
	cppVar_2368 = (cppVar_2368 & cppMask_un_16_);
	BIT_VEC cppVar_2369 = (XRAM.rd(cppVar_2368) & cppMask_un_8_);
	for (int cppVar_2370 = 1; cppVar_2370 < 64; cppVar_2370++) {
		cppVar_2369 = (cppVar_2369 << 8) | (XRAM.rd(cppVar_2368 + cppVar_2370) & cppMask_un_8_);
	}
	cppVar_2369 = (cppVar_2369 & cppMask_un_512_);
	BIT_VEC cppVar_2371 = (cppVar_2367) ? cppVar_2369 : sha_rd_data;
	return cppVar_2371;
}
BIT_VEC model_sha::cppUpdateFun_sha_rdaddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2374 = (sha_state == 0);
	bool cppVar_2376 = (cmd == 2);
	bool cppVar_2377 = cppVar_2374 && cppVar_2376;
	bool cppVar_2379 = (cmdaddr == 65027);
	bool cppVar_2380 = cppVar_2377 && cppVar_2379;
	BIT_VEC cppVar_2381 = (sha_rdaddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_2382 = (cmddata << 8) | cppVar_2381;
	cppVar_2382 = (cppVar_2382 & cppMask_un_16_);
	bool cppVar_2384 = (sha_state == 0);
	bool cppVar_2386 = (cmd == 2);
	bool cppVar_2387 = cppVar_2384 && cppVar_2386;
	bool cppVar_2389 = (cmdaddr == 65026);
	bool cppVar_2390 = cppVar_2387 && cppVar_2389;
	BIT_VEC cppVar_2391 = (sha_rdaddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_2392 = (cppVar_2391 << 8) | cmddata;
	cppVar_2392 = (cppVar_2392 & cppMask_un_16_);
	BIT_VEC cppVar_2393 = (cppVar_2390) ? cppVar_2392 : sha_rdaddr;
	BIT_VEC cppVar_2394 = (cppVar_2380) ? cppVar_2382 : cppVar_2393;
	return cppVar_2394;
}
BIT_VEC model_sha::cppUpdateFun_sha_state(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_2397 = (sha_state == 0);
	bool cppVar_2399 = (cmd == 2);
	bool cppVar_2400 = cppVar_2397 && cppVar_2399;
	bool cppVar_2402 = (cmdaddr == 65024);
	bool cppVar_2403 = cppVar_2400 && cppVar_2402;
	bool cppVar_2405 = (cmddata == 1);
	BIT_VEC cppVar_2407 = (cppVar_2405) ? 1 : sha_state;
	bool cppVar_2409 = (sha_state == 3);
	bool cppVar_2411 = (cmd != 1);
	bool cppVar_2412 = cppVar_2409 && cppVar_2411;
	bool cppVar_2414 = (cmdaddr == 65039);
	bool cppVar_2415 = cppVar_2412 && cppVar_2414;
	bool cppVar_2417 = (sha_state == 3);
	bool cppVar_2419 = (cmd != 1);
	bool cppVar_2420 = cppVar_2417 && cppVar_2419;
	bool cppVar_2422 = (cmdaddr == 65038);
	bool cppVar_2423 = cppVar_2420 && cppVar_2422;
	bool cppVar_2425 = (sha_state == 3);
	bool cppVar_2427 = (cmd != 1);
	bool cppVar_2428 = cppVar_2425 && cppVar_2427;
	bool cppVar_2430 = (cmdaddr == 65037);
	bool cppVar_2431 = cppVar_2428 && cppVar_2430;
	bool cppVar_2433 = (sha_state == 3);
	bool cppVar_2435 = (cmd != 1);
	bool cppVar_2436 = cppVar_2433 && cppVar_2435;
	bool cppVar_2438 = (cmdaddr == 65036);
	bool cppVar_2439 = cppVar_2436 && cppVar_2438;
	bool cppVar_2441 = (sha_state == 3);
	bool cppVar_2443 = (cmd != 1);
	bool cppVar_2444 = cppVar_2441 && cppVar_2443;
	bool cppVar_2446 = (cmdaddr == 65035);
	bool cppVar_2447 = cppVar_2444 && cppVar_2446;
	bool cppVar_2449 = (sha_state == 3);
	bool cppVar_2451 = (cmd != 1);
	bool cppVar_2452 = cppVar_2449 && cppVar_2451;
	bool cppVar_2454 = (cmdaddr == 65034);
	bool cppVar_2455 = cppVar_2452 && cppVar_2454;
	bool cppVar_2457 = (sha_state == 3);
	bool cppVar_2459 = (cmd != 1);
	bool cppVar_2460 = cppVar_2457 && cppVar_2459;
	bool cppVar_2462 = (cmdaddr == 65033);
	bool cppVar_2463 = cppVar_2460 && cppVar_2462;
	bool cppVar_2465 = (sha_state == 3);
	bool cppVar_2467 = (cmd != 1);
	bool cppVar_2468 = cppVar_2465 && cppVar_2467;
	bool cppVar_2470 = (cmdaddr == 65032);
	bool cppVar_2471 = cppVar_2468 && cppVar_2470;
	bool cppVar_2473 = (sha_state == 3);
	bool cppVar_2475 = (cmd != 1);
	bool cppVar_2476 = cppVar_2473 && cppVar_2475;
	bool cppVar_2478 = (cmdaddr == 65031);
	bool cppVar_2479 = cppVar_2476 && cppVar_2478;
	bool cppVar_2481 = (sha_state == 3);
	bool cppVar_2483 = (cmd != 1);
	bool cppVar_2484 = cppVar_2481 && cppVar_2483;
	bool cppVar_2486 = (cmdaddr == 65030);
	bool cppVar_2487 = cppVar_2484 && cppVar_2486;
	bool cppVar_2489 = (sha_state == 3);
	bool cppVar_2491 = (cmd != 1);
	bool cppVar_2492 = cppVar_2489 && cppVar_2491;
	bool cppVar_2494 = (cmdaddr == 65029);
	bool cppVar_2495 = cppVar_2492 && cppVar_2494;
	bool cppVar_2497 = (sha_state == 3);
	bool cppVar_2499 = (cmd != 1);
	bool cppVar_2500 = cppVar_2497 && cppVar_2499;
	bool cppVar_2502 = (cmdaddr == 65028);
	bool cppVar_2503 = cppVar_2500 && cppVar_2502;
	bool cppVar_2505 = (sha_state == 3);
	bool cppVar_2507 = (cmd != 1);
	bool cppVar_2508 = cppVar_2505 && cppVar_2507;
	bool cppVar_2510 = (cmdaddr == 65027);
	bool cppVar_2511 = cppVar_2508 && cppVar_2510;
	bool cppVar_2513 = (sha_state == 3);
	bool cppVar_2515 = (cmd != 1);
	bool cppVar_2516 = cppVar_2513 && cppVar_2515;
	bool cppVar_2518 = (cmdaddr == 65026);
	bool cppVar_2519 = cppVar_2516 && cppVar_2518;
	bool cppVar_2521 = (sha_state == 3);
	bool cppVar_2523 = (cmd != 1);
	bool cppVar_2524 = cppVar_2521 && cppVar_2523;
	bool cppVar_2526 = (cmdaddr == 65025);
	bool cppVar_2527 = cppVar_2524 && cppVar_2526;
	bool cppVar_2529 = (sha_state == 3);
	bool cppVar_2531 = (cmd != 1);
	bool cppVar_2532 = cppVar_2529 && cppVar_2531;
	bool cppVar_2534 = (cmdaddr == 65024);
	bool cppVar_2535 = cppVar_2532 && cppVar_2534;
	bool cppVar_2537 = (sha_state == 3);
	bool cppVar_2539 = (cmd == 1);
	bool cppVar_2540 = cppVar_2537 && cppVar_2539;
	bool cppVar_2542 = (cmdaddr == 65039);
	bool cppVar_2543 = cppVar_2540 && cppVar_2542;
	bool cppVar_2545 = (sha_state == 3);
	bool cppVar_2547 = (cmd == 1);
	bool cppVar_2548 = cppVar_2545 && cppVar_2547;
	bool cppVar_2550 = (cmdaddr == 65038);
	bool cppVar_2551 = cppVar_2548 && cppVar_2550;
	bool cppVar_2553 = (sha_state == 3);
	bool cppVar_2555 = (cmd == 1);
	bool cppVar_2556 = cppVar_2553 && cppVar_2555;
	bool cppVar_2558 = (cmdaddr == 65037);
	bool cppVar_2559 = cppVar_2556 && cppVar_2558;
	bool cppVar_2561 = (sha_state == 3);
	bool cppVar_2563 = (cmd == 1);
	bool cppVar_2564 = cppVar_2561 && cppVar_2563;
	bool cppVar_2566 = (cmdaddr == 65036);
	bool cppVar_2567 = cppVar_2564 && cppVar_2566;
	bool cppVar_2569 = (sha_state == 3);
	bool cppVar_2571 = (cmd == 1);
	bool cppVar_2572 = cppVar_2569 && cppVar_2571;
	bool cppVar_2574 = (cmdaddr == 65035);
	bool cppVar_2575 = cppVar_2572 && cppVar_2574;
	bool cppVar_2577 = (sha_state == 3);
	bool cppVar_2579 = (cmd == 1);
	bool cppVar_2580 = cppVar_2577 && cppVar_2579;
	bool cppVar_2582 = (cmdaddr == 65034);
	bool cppVar_2583 = cppVar_2580 && cppVar_2582;
	bool cppVar_2585 = (sha_state == 3);
	bool cppVar_2587 = (cmd == 1);
	bool cppVar_2588 = cppVar_2585 && cppVar_2587;
	bool cppVar_2590 = (cmdaddr == 65033);
	bool cppVar_2591 = cppVar_2588 && cppVar_2590;
	bool cppVar_2593 = (sha_state == 3);
	bool cppVar_2595 = (cmd == 1);
	bool cppVar_2596 = cppVar_2593 && cppVar_2595;
	bool cppVar_2598 = (cmdaddr == 65032);
	bool cppVar_2599 = cppVar_2596 && cppVar_2598;
	bool cppVar_2601 = (sha_state == 3);
	bool cppVar_2603 = (cmd == 1);
	bool cppVar_2604 = cppVar_2601 && cppVar_2603;
	bool cppVar_2606 = (cmdaddr == 65031);
	bool cppVar_2607 = cppVar_2604 && cppVar_2606;
	bool cppVar_2609 = (sha_state == 3);
	bool cppVar_2611 = (cmd == 1);
	bool cppVar_2612 = cppVar_2609 && cppVar_2611;
	bool cppVar_2614 = (cmdaddr == 65030);
	bool cppVar_2615 = cppVar_2612 && cppVar_2614;
	bool cppVar_2617 = (sha_state == 3);
	bool cppVar_2619 = (cmd == 1);
	bool cppVar_2620 = cppVar_2617 && cppVar_2619;
	bool cppVar_2622 = (cmdaddr == 65029);
	bool cppVar_2623 = cppVar_2620 && cppVar_2622;
	bool cppVar_2625 = (sha_state == 3);
	bool cppVar_2627 = (cmd == 1);
	bool cppVar_2628 = cppVar_2625 && cppVar_2627;
	bool cppVar_2630 = (cmdaddr == 65028);
	bool cppVar_2631 = cppVar_2628 && cppVar_2630;
	bool cppVar_2633 = (sha_state == 3);
	bool cppVar_2635 = (cmd == 1);
	bool cppVar_2636 = cppVar_2633 && cppVar_2635;
	bool cppVar_2638 = (cmdaddr == 65027);
	bool cppVar_2639 = cppVar_2636 && cppVar_2638;
	bool cppVar_2641 = (sha_state == 3);
	bool cppVar_2643 = (cmd == 1);
	bool cppVar_2644 = cppVar_2641 && cppVar_2643;
	bool cppVar_2646 = (cmdaddr == 65026);
	bool cppVar_2647 = cppVar_2644 && cppVar_2646;
	bool cppVar_2649 = (sha_state == 3);
	bool cppVar_2651 = (cmd == 1);
	bool cppVar_2652 = cppVar_2649 && cppVar_2651;
	bool cppVar_2654 = (cmdaddr == 65025);
	bool cppVar_2655 = cppVar_2652 && cppVar_2654;
	bool cppVar_2657 = (sha_state == 3);
	bool cppVar_2659 = (cmd == 1);
	bool cppVar_2660 = cppVar_2657 && cppVar_2659;
	bool cppVar_2662 = (cmdaddr == 65024);
	bool cppVar_2663 = cppVar_2660 && cppVar_2662;
	bool cppVar_2664 = cppVar_2655 || cppVar_2663;
	bool cppVar_2665 = cppVar_2647 || cppVar_2664;
	bool cppVar_2666 = cppVar_2639 || cppVar_2665;
	bool cppVar_2667 = cppVar_2631 || cppVar_2666;
	bool cppVar_2668 = cppVar_2623 || cppVar_2667;
	bool cppVar_2669 = cppVar_2615 || cppVar_2668;
	bool cppVar_2670 = cppVar_2607 || cppVar_2669;
	bool cppVar_2671 = cppVar_2599 || cppVar_2670;
	bool cppVar_2672 = cppVar_2591 || cppVar_2671;
	bool cppVar_2673 = cppVar_2583 || cppVar_2672;
	bool cppVar_2674 = cppVar_2575 || cppVar_2673;
	bool cppVar_2675 = cppVar_2567 || cppVar_2674;
	bool cppVar_2676 = cppVar_2559 || cppVar_2675;
	bool cppVar_2677 = cppVar_2551 || cppVar_2676;
	bool cppVar_2678 = cppVar_2543 || cppVar_2677;
	bool cppVar_2679 = cppVar_2535 || cppVar_2678;
	bool cppVar_2680 = cppVar_2527 || cppVar_2679;
	bool cppVar_2681 = cppVar_2519 || cppVar_2680;
	bool cppVar_2682 = cppVar_2511 || cppVar_2681;
	bool cppVar_2683 = cppVar_2503 || cppVar_2682;
	bool cppVar_2684 = cppVar_2495 || cppVar_2683;
	bool cppVar_2685 = cppVar_2487 || cppVar_2684;
	bool cppVar_2686 = cppVar_2479 || cppVar_2685;
	bool cppVar_2687 = cppVar_2471 || cppVar_2686;
	bool cppVar_2688 = cppVar_2463 || cppVar_2687;
	bool cppVar_2689 = cppVar_2455 || cppVar_2688;
	bool cppVar_2690 = cppVar_2447 || cppVar_2689;
	bool cppVar_2691 = cppVar_2439 || cppVar_2690;
	bool cppVar_2692 = cppVar_2431 || cppVar_2691;
	bool cppVar_2693 = cppVar_2423 || cppVar_2692;
	bool cppVar_2694 = cppVar_2415 || cppVar_2693;
	bool cppVar_2695 = sha_bytes_read < sha_len;
	BIT_VEC cppVar_2698 = (cppVar_2695) ? 1 : 4;
	bool cppVar_2700 = (sha_state == 2);
	bool cppVar_2702 = (cmd != 1);
	bool cppVar_2703 = cppVar_2700 && cppVar_2702;
	bool cppVar_2705 = (cmdaddr == 65039);
	bool cppVar_2706 = cppVar_2703 && cppVar_2705;
	bool cppVar_2708 = (sha_state == 2);
	bool cppVar_2710 = (cmd != 1);
	bool cppVar_2711 = cppVar_2708 && cppVar_2710;
	bool cppVar_2713 = (cmdaddr == 65038);
	bool cppVar_2714 = cppVar_2711 && cppVar_2713;
	bool cppVar_2716 = (sha_state == 2);
	bool cppVar_2718 = (cmd != 1);
	bool cppVar_2719 = cppVar_2716 && cppVar_2718;
	bool cppVar_2721 = (cmdaddr == 65037);
	bool cppVar_2722 = cppVar_2719 && cppVar_2721;
	bool cppVar_2724 = (sha_state == 2);
	bool cppVar_2726 = (cmd != 1);
	bool cppVar_2727 = cppVar_2724 && cppVar_2726;
	bool cppVar_2729 = (cmdaddr == 65036);
	bool cppVar_2730 = cppVar_2727 && cppVar_2729;
	bool cppVar_2732 = (sha_state == 2);
	bool cppVar_2734 = (cmd != 1);
	bool cppVar_2735 = cppVar_2732 && cppVar_2734;
	bool cppVar_2737 = (cmdaddr == 65035);
	bool cppVar_2738 = cppVar_2735 && cppVar_2737;
	bool cppVar_2740 = (sha_state == 2);
	bool cppVar_2742 = (cmd != 1);
	bool cppVar_2743 = cppVar_2740 && cppVar_2742;
	bool cppVar_2745 = (cmdaddr == 65034);
	bool cppVar_2746 = cppVar_2743 && cppVar_2745;
	bool cppVar_2748 = (sha_state == 2);
	bool cppVar_2750 = (cmd != 1);
	bool cppVar_2751 = cppVar_2748 && cppVar_2750;
	bool cppVar_2753 = (cmdaddr == 65033);
	bool cppVar_2754 = cppVar_2751 && cppVar_2753;
	bool cppVar_2756 = (sha_state == 2);
	bool cppVar_2758 = (cmd != 1);
	bool cppVar_2759 = cppVar_2756 && cppVar_2758;
	bool cppVar_2761 = (cmdaddr == 65032);
	bool cppVar_2762 = cppVar_2759 && cppVar_2761;
	bool cppVar_2764 = (sha_state == 2);
	bool cppVar_2766 = (cmd != 1);
	bool cppVar_2767 = cppVar_2764 && cppVar_2766;
	bool cppVar_2769 = (cmdaddr == 65031);
	bool cppVar_2770 = cppVar_2767 && cppVar_2769;
	bool cppVar_2772 = (sha_state == 2);
	bool cppVar_2774 = (cmd != 1);
	bool cppVar_2775 = cppVar_2772 && cppVar_2774;
	bool cppVar_2777 = (cmdaddr == 65030);
	bool cppVar_2778 = cppVar_2775 && cppVar_2777;
	bool cppVar_2780 = (sha_state == 2);
	bool cppVar_2782 = (cmd != 1);
	bool cppVar_2783 = cppVar_2780 && cppVar_2782;
	bool cppVar_2785 = (cmdaddr == 65029);
	bool cppVar_2786 = cppVar_2783 && cppVar_2785;
	bool cppVar_2788 = (sha_state == 2);
	bool cppVar_2790 = (cmd != 1);
	bool cppVar_2791 = cppVar_2788 && cppVar_2790;
	bool cppVar_2793 = (cmdaddr == 65028);
	bool cppVar_2794 = cppVar_2791 && cppVar_2793;
	bool cppVar_2796 = (sha_state == 2);
	bool cppVar_2798 = (cmd != 1);
	bool cppVar_2799 = cppVar_2796 && cppVar_2798;
	bool cppVar_2801 = (cmdaddr == 65027);
	bool cppVar_2802 = cppVar_2799 && cppVar_2801;
	bool cppVar_2804 = (sha_state == 2);
	bool cppVar_2806 = (cmd != 1);
	bool cppVar_2807 = cppVar_2804 && cppVar_2806;
	bool cppVar_2809 = (cmdaddr == 65026);
	bool cppVar_2810 = cppVar_2807 && cppVar_2809;
	bool cppVar_2812 = (sha_state == 2);
	bool cppVar_2814 = (cmd != 1);
	bool cppVar_2815 = cppVar_2812 && cppVar_2814;
	bool cppVar_2817 = (cmdaddr == 65025);
	bool cppVar_2818 = cppVar_2815 && cppVar_2817;
	bool cppVar_2820 = (sha_state == 2);
	bool cppVar_2822 = (cmd != 1);
	bool cppVar_2823 = cppVar_2820 && cppVar_2822;
	bool cppVar_2825 = (cmdaddr == 65024);
	bool cppVar_2826 = cppVar_2823 && cppVar_2825;
	bool cppVar_2828 = (sha_state == 2);
	bool cppVar_2830 = (cmd == 1);
	bool cppVar_2831 = cppVar_2828 && cppVar_2830;
	bool cppVar_2833 = (cmdaddr == 65039);
	bool cppVar_2834 = cppVar_2831 && cppVar_2833;
	bool cppVar_2836 = (sha_state == 2);
	bool cppVar_2838 = (cmd == 1);
	bool cppVar_2839 = cppVar_2836 && cppVar_2838;
	bool cppVar_2841 = (cmdaddr == 65038);
	bool cppVar_2842 = cppVar_2839 && cppVar_2841;
	bool cppVar_2844 = (sha_state == 2);
	bool cppVar_2846 = (cmd == 1);
	bool cppVar_2847 = cppVar_2844 && cppVar_2846;
	bool cppVar_2849 = (cmdaddr == 65037);
	bool cppVar_2850 = cppVar_2847 && cppVar_2849;
	bool cppVar_2852 = (sha_state == 2);
	bool cppVar_2854 = (cmd == 1);
	bool cppVar_2855 = cppVar_2852 && cppVar_2854;
	bool cppVar_2857 = (cmdaddr == 65036);
	bool cppVar_2858 = cppVar_2855 && cppVar_2857;
	bool cppVar_2860 = (sha_state == 2);
	bool cppVar_2862 = (cmd == 1);
	bool cppVar_2863 = cppVar_2860 && cppVar_2862;
	bool cppVar_2865 = (cmdaddr == 65035);
	bool cppVar_2866 = cppVar_2863 && cppVar_2865;
	bool cppVar_2868 = (sha_state == 2);
	bool cppVar_2870 = (cmd == 1);
	bool cppVar_2871 = cppVar_2868 && cppVar_2870;
	bool cppVar_2873 = (cmdaddr == 65034);
	bool cppVar_2874 = cppVar_2871 && cppVar_2873;
	bool cppVar_2876 = (sha_state == 2);
	bool cppVar_2878 = (cmd == 1);
	bool cppVar_2879 = cppVar_2876 && cppVar_2878;
	bool cppVar_2881 = (cmdaddr == 65033);
	bool cppVar_2882 = cppVar_2879 && cppVar_2881;
	bool cppVar_2884 = (sha_state == 2);
	bool cppVar_2886 = (cmd == 1);
	bool cppVar_2887 = cppVar_2884 && cppVar_2886;
	bool cppVar_2889 = (cmdaddr == 65032);
	bool cppVar_2890 = cppVar_2887 && cppVar_2889;
	bool cppVar_2892 = (sha_state == 2);
	bool cppVar_2894 = (cmd == 1);
	bool cppVar_2895 = cppVar_2892 && cppVar_2894;
	bool cppVar_2897 = (cmdaddr == 65031);
	bool cppVar_2898 = cppVar_2895 && cppVar_2897;
	bool cppVar_2900 = (sha_state == 2);
	bool cppVar_2902 = (cmd == 1);
	bool cppVar_2903 = cppVar_2900 && cppVar_2902;
	bool cppVar_2905 = (cmdaddr == 65030);
	bool cppVar_2906 = cppVar_2903 && cppVar_2905;
	bool cppVar_2908 = (sha_state == 2);
	bool cppVar_2910 = (cmd == 1);
	bool cppVar_2911 = cppVar_2908 && cppVar_2910;
	bool cppVar_2913 = (cmdaddr == 65029);
	bool cppVar_2914 = cppVar_2911 && cppVar_2913;
	bool cppVar_2916 = (sha_state == 2);
	bool cppVar_2918 = (cmd == 1);
	bool cppVar_2919 = cppVar_2916 && cppVar_2918;
	bool cppVar_2921 = (cmdaddr == 65028);
	bool cppVar_2922 = cppVar_2919 && cppVar_2921;
	bool cppVar_2924 = (sha_state == 2);
	bool cppVar_2926 = (cmd == 1);
	bool cppVar_2927 = cppVar_2924 && cppVar_2926;
	bool cppVar_2929 = (cmdaddr == 65027);
	bool cppVar_2930 = cppVar_2927 && cppVar_2929;
	bool cppVar_2932 = (sha_state == 2);
	bool cppVar_2934 = (cmd == 1);
	bool cppVar_2935 = cppVar_2932 && cppVar_2934;
	bool cppVar_2937 = (cmdaddr == 65026);
	bool cppVar_2938 = cppVar_2935 && cppVar_2937;
	bool cppVar_2940 = (sha_state == 2);
	bool cppVar_2942 = (cmd == 1);
	bool cppVar_2943 = cppVar_2940 && cppVar_2942;
	bool cppVar_2945 = (cmdaddr == 65025);
	bool cppVar_2946 = cppVar_2943 && cppVar_2945;
	bool cppVar_2948 = (sha_state == 2);
	bool cppVar_2950 = (cmd == 1);
	bool cppVar_2951 = cppVar_2948 && cppVar_2950;
	bool cppVar_2953 = (cmdaddr == 65024);
	bool cppVar_2954 = cppVar_2951 && cppVar_2953;
	bool cppVar_2955 = cppVar_2946 || cppVar_2954;
	bool cppVar_2956 = cppVar_2938 || cppVar_2955;
	bool cppVar_2957 = cppVar_2930 || cppVar_2956;
	bool cppVar_2958 = cppVar_2922 || cppVar_2957;
	bool cppVar_2959 = cppVar_2914 || cppVar_2958;
	bool cppVar_2960 = cppVar_2906 || cppVar_2959;
	bool cppVar_2961 = cppVar_2898 || cppVar_2960;
	bool cppVar_2962 = cppVar_2890 || cppVar_2961;
	bool cppVar_2963 = cppVar_2882 || cppVar_2962;
	bool cppVar_2964 = cppVar_2874 || cppVar_2963;
	bool cppVar_2965 = cppVar_2866 || cppVar_2964;
	bool cppVar_2966 = cppVar_2858 || cppVar_2965;
	bool cppVar_2967 = cppVar_2850 || cppVar_2966;
	bool cppVar_2968 = cppVar_2842 || cppVar_2967;
	bool cppVar_2969 = cppVar_2834 || cppVar_2968;
	bool cppVar_2970 = cppVar_2826 || cppVar_2969;
	bool cppVar_2971 = cppVar_2818 || cppVar_2970;
	bool cppVar_2972 = cppVar_2810 || cppVar_2971;
	bool cppVar_2973 = cppVar_2802 || cppVar_2972;
	bool cppVar_2974 = cppVar_2794 || cppVar_2973;
	bool cppVar_2975 = cppVar_2786 || cppVar_2974;
	bool cppVar_2976 = cppVar_2778 || cppVar_2975;
	bool cppVar_2977 = cppVar_2770 || cppVar_2976;
	bool cppVar_2978 = cppVar_2762 || cppVar_2977;
	bool cppVar_2979 = cppVar_2754 || cppVar_2978;
	bool cppVar_2980 = cppVar_2746 || cppVar_2979;
	bool cppVar_2981 = cppVar_2738 || cppVar_2980;
	bool cppVar_2982 = cppVar_2730 || cppVar_2981;
	bool cppVar_2983 = cppVar_2722 || cppVar_2982;
	bool cppVar_2984 = cppVar_2714 || cppVar_2983;
	bool cppVar_2985 = cppVar_2706 || cppVar_2984;
	bool cppVar_2988 = (sha_state == 1);
	bool cppVar_2990 = (cmd != 1);
	bool cppVar_2991 = cppVar_2988 && cppVar_2990;
	bool cppVar_2993 = (cmdaddr == 65039);
	bool cppVar_2994 = cppVar_2991 && cppVar_2993;
	bool cppVar_2996 = (sha_state == 1);
	bool cppVar_2998 = (cmd != 1);
	bool cppVar_2999 = cppVar_2996 && cppVar_2998;
	bool cppVar_3001 = (cmdaddr == 65038);
	bool cppVar_3002 = cppVar_2999 && cppVar_3001;
	bool cppVar_3004 = (sha_state == 1);
	bool cppVar_3006 = (cmd != 1);
	bool cppVar_3007 = cppVar_3004 && cppVar_3006;
	bool cppVar_3009 = (cmdaddr == 65037);
	bool cppVar_3010 = cppVar_3007 && cppVar_3009;
	bool cppVar_3012 = (sha_state == 1);
	bool cppVar_3014 = (cmd != 1);
	bool cppVar_3015 = cppVar_3012 && cppVar_3014;
	bool cppVar_3017 = (cmdaddr == 65036);
	bool cppVar_3018 = cppVar_3015 && cppVar_3017;
	bool cppVar_3020 = (sha_state == 1);
	bool cppVar_3022 = (cmd != 1);
	bool cppVar_3023 = cppVar_3020 && cppVar_3022;
	bool cppVar_3025 = (cmdaddr == 65035);
	bool cppVar_3026 = cppVar_3023 && cppVar_3025;
	bool cppVar_3028 = (sha_state == 1);
	bool cppVar_3030 = (cmd != 1);
	bool cppVar_3031 = cppVar_3028 && cppVar_3030;
	bool cppVar_3033 = (cmdaddr == 65034);
	bool cppVar_3034 = cppVar_3031 && cppVar_3033;
	bool cppVar_3036 = (sha_state == 1);
	bool cppVar_3038 = (cmd != 1);
	bool cppVar_3039 = cppVar_3036 && cppVar_3038;
	bool cppVar_3041 = (cmdaddr == 65033);
	bool cppVar_3042 = cppVar_3039 && cppVar_3041;
	bool cppVar_3044 = (sha_state == 1);
	bool cppVar_3046 = (cmd != 1);
	bool cppVar_3047 = cppVar_3044 && cppVar_3046;
	bool cppVar_3049 = (cmdaddr == 65032);
	bool cppVar_3050 = cppVar_3047 && cppVar_3049;
	bool cppVar_3052 = (sha_state == 1);
	bool cppVar_3054 = (cmd != 1);
	bool cppVar_3055 = cppVar_3052 && cppVar_3054;
	bool cppVar_3057 = (cmdaddr == 65031);
	bool cppVar_3058 = cppVar_3055 && cppVar_3057;
	bool cppVar_3060 = (sha_state == 1);
	bool cppVar_3062 = (cmd != 1);
	bool cppVar_3063 = cppVar_3060 && cppVar_3062;
	bool cppVar_3065 = (cmdaddr == 65030);
	bool cppVar_3066 = cppVar_3063 && cppVar_3065;
	bool cppVar_3068 = (sha_state == 1);
	bool cppVar_3070 = (cmd != 1);
	bool cppVar_3071 = cppVar_3068 && cppVar_3070;
	bool cppVar_3073 = (cmdaddr == 65029);
	bool cppVar_3074 = cppVar_3071 && cppVar_3073;
	bool cppVar_3076 = (sha_state == 1);
	bool cppVar_3078 = (cmd != 1);
	bool cppVar_3079 = cppVar_3076 && cppVar_3078;
	bool cppVar_3081 = (cmdaddr == 65028);
	bool cppVar_3082 = cppVar_3079 && cppVar_3081;
	bool cppVar_3084 = (sha_state == 1);
	bool cppVar_3086 = (cmd != 1);
	bool cppVar_3087 = cppVar_3084 && cppVar_3086;
	bool cppVar_3089 = (cmdaddr == 65027);
	bool cppVar_3090 = cppVar_3087 && cppVar_3089;
	bool cppVar_3092 = (sha_state == 1);
	bool cppVar_3094 = (cmd != 1);
	bool cppVar_3095 = cppVar_3092 && cppVar_3094;
	bool cppVar_3097 = (cmdaddr == 65026);
	bool cppVar_3098 = cppVar_3095 && cppVar_3097;
	bool cppVar_3100 = (sha_state == 1);
	bool cppVar_3102 = (cmd != 1);
	bool cppVar_3103 = cppVar_3100 && cppVar_3102;
	bool cppVar_3105 = (cmdaddr == 65025);
	bool cppVar_3106 = cppVar_3103 && cppVar_3105;
	bool cppVar_3108 = (sha_state == 1);
	bool cppVar_3110 = (cmd != 1);
	bool cppVar_3111 = cppVar_3108 && cppVar_3110;
	bool cppVar_3113 = (cmdaddr == 65024);
	bool cppVar_3114 = cppVar_3111 && cppVar_3113;
	bool cppVar_3116 = (sha_state == 1);
	bool cppVar_3118 = (cmd == 1);
	bool cppVar_3119 = cppVar_3116 && cppVar_3118;
	bool cppVar_3121 = (cmdaddr == 65039);
	bool cppVar_3122 = cppVar_3119 && cppVar_3121;
	bool cppVar_3124 = (sha_state == 1);
	bool cppVar_3126 = (cmd == 1);
	bool cppVar_3127 = cppVar_3124 && cppVar_3126;
	bool cppVar_3129 = (cmdaddr == 65038);
	bool cppVar_3130 = cppVar_3127 && cppVar_3129;
	bool cppVar_3132 = (sha_state == 1);
	bool cppVar_3134 = (cmd == 1);
	bool cppVar_3135 = cppVar_3132 && cppVar_3134;
	bool cppVar_3137 = (cmdaddr == 65037);
	bool cppVar_3138 = cppVar_3135 && cppVar_3137;
	bool cppVar_3140 = (sha_state == 1);
	bool cppVar_3142 = (cmd == 1);
	bool cppVar_3143 = cppVar_3140 && cppVar_3142;
	bool cppVar_3145 = (cmdaddr == 65036);
	bool cppVar_3146 = cppVar_3143 && cppVar_3145;
	bool cppVar_3148 = (sha_state == 1);
	bool cppVar_3150 = (cmd == 1);
	bool cppVar_3151 = cppVar_3148 && cppVar_3150;
	bool cppVar_3153 = (cmdaddr == 65035);
	bool cppVar_3154 = cppVar_3151 && cppVar_3153;
	bool cppVar_3156 = (sha_state == 1);
	bool cppVar_3158 = (cmd == 1);
	bool cppVar_3159 = cppVar_3156 && cppVar_3158;
	bool cppVar_3161 = (cmdaddr == 65034);
	bool cppVar_3162 = cppVar_3159 && cppVar_3161;
	bool cppVar_3164 = (sha_state == 1);
	bool cppVar_3166 = (cmd == 1);
	bool cppVar_3167 = cppVar_3164 && cppVar_3166;
	bool cppVar_3169 = (cmdaddr == 65033);
	bool cppVar_3170 = cppVar_3167 && cppVar_3169;
	bool cppVar_3172 = (sha_state == 1);
	bool cppVar_3174 = (cmd == 1);
	bool cppVar_3175 = cppVar_3172 && cppVar_3174;
	bool cppVar_3177 = (cmdaddr == 65032);
	bool cppVar_3178 = cppVar_3175 && cppVar_3177;
	bool cppVar_3180 = (sha_state == 1);
	bool cppVar_3182 = (cmd == 1);
	bool cppVar_3183 = cppVar_3180 && cppVar_3182;
	bool cppVar_3185 = (cmdaddr == 65031);
	bool cppVar_3186 = cppVar_3183 && cppVar_3185;
	bool cppVar_3188 = (sha_state == 1);
	bool cppVar_3190 = (cmd == 1);
	bool cppVar_3191 = cppVar_3188 && cppVar_3190;
	bool cppVar_3193 = (cmdaddr == 65030);
	bool cppVar_3194 = cppVar_3191 && cppVar_3193;
	bool cppVar_3196 = (sha_state == 1);
	bool cppVar_3198 = (cmd == 1);
	bool cppVar_3199 = cppVar_3196 && cppVar_3198;
	bool cppVar_3201 = (cmdaddr == 65029);
	bool cppVar_3202 = cppVar_3199 && cppVar_3201;
	bool cppVar_3204 = (sha_state == 1);
	bool cppVar_3206 = (cmd == 1);
	bool cppVar_3207 = cppVar_3204 && cppVar_3206;
	bool cppVar_3209 = (cmdaddr == 65028);
	bool cppVar_3210 = cppVar_3207 && cppVar_3209;
	bool cppVar_3212 = (sha_state == 1);
	bool cppVar_3214 = (cmd == 1);
	bool cppVar_3215 = cppVar_3212 && cppVar_3214;
	bool cppVar_3217 = (cmdaddr == 65027);
	bool cppVar_3218 = cppVar_3215 && cppVar_3217;
	bool cppVar_3220 = (sha_state == 1);
	bool cppVar_3222 = (cmd == 1);
	bool cppVar_3223 = cppVar_3220 && cppVar_3222;
	bool cppVar_3225 = (cmdaddr == 65026);
	bool cppVar_3226 = cppVar_3223 && cppVar_3225;
	bool cppVar_3228 = (sha_state == 1);
	bool cppVar_3230 = (cmd == 1);
	bool cppVar_3231 = cppVar_3228 && cppVar_3230;
	bool cppVar_3233 = (cmdaddr == 65025);
	bool cppVar_3234 = cppVar_3231 && cppVar_3233;
	bool cppVar_3236 = (sha_state == 1);
	bool cppVar_3238 = (cmd == 1);
	bool cppVar_3239 = cppVar_3236 && cppVar_3238;
	bool cppVar_3241 = (cmdaddr == 65024);
	bool cppVar_3242 = cppVar_3239 && cppVar_3241;
	bool cppVar_3243 = cppVar_3234 || cppVar_3242;
	bool cppVar_3244 = cppVar_3226 || cppVar_3243;
	bool cppVar_3245 = cppVar_3218 || cppVar_3244;
	bool cppVar_3246 = cppVar_3210 || cppVar_3245;
	bool cppVar_3247 = cppVar_3202 || cppVar_3246;
	bool cppVar_3248 = cppVar_3194 || cppVar_3247;
	bool cppVar_3249 = cppVar_3186 || cppVar_3248;
	bool cppVar_3250 = cppVar_3178 || cppVar_3249;
	bool cppVar_3251 = cppVar_3170 || cppVar_3250;
	bool cppVar_3252 = cppVar_3162 || cppVar_3251;
	bool cppVar_3253 = cppVar_3154 || cppVar_3252;
	bool cppVar_3254 = cppVar_3146 || cppVar_3253;
	bool cppVar_3255 = cppVar_3138 || cppVar_3254;
	bool cppVar_3256 = cppVar_3130 || cppVar_3255;
	bool cppVar_3257 = cppVar_3122 || cppVar_3256;
	bool cppVar_3258 = cppVar_3114 || cppVar_3257;
	bool cppVar_3259 = cppVar_3106 || cppVar_3258;
	bool cppVar_3260 = cppVar_3098 || cppVar_3259;
	bool cppVar_3261 = cppVar_3090 || cppVar_3260;
	bool cppVar_3262 = cppVar_3082 || cppVar_3261;
	bool cppVar_3263 = cppVar_3074 || cppVar_3262;
	bool cppVar_3264 = cppVar_3066 || cppVar_3263;
	bool cppVar_3265 = cppVar_3058 || cppVar_3264;
	bool cppVar_3266 = cppVar_3050 || cppVar_3265;
	bool cppVar_3267 = cppVar_3042 || cppVar_3266;
	bool cppVar_3268 = cppVar_3034 || cppVar_3267;
	bool cppVar_3269 = cppVar_3026 || cppVar_3268;
	bool cppVar_3270 = cppVar_3018 || cppVar_3269;
	bool cppVar_3271 = cppVar_3010 || cppVar_3270;
	bool cppVar_3272 = cppVar_3002 || cppVar_3271;
	bool cppVar_3273 = cppVar_2994 || cppVar_3272;
	bool cppVar_3276 = (sha_state == 4);
	bool cppVar_3278 = (cmd != 1);
	bool cppVar_3279 = cppVar_3276 && cppVar_3278;
	bool cppVar_3281 = (cmdaddr == 65039);
	bool cppVar_3282 = cppVar_3279 && cppVar_3281;
	bool cppVar_3284 = (sha_state == 4);
	bool cppVar_3286 = (cmd != 1);
	bool cppVar_3287 = cppVar_3284 && cppVar_3286;
	bool cppVar_3289 = (cmdaddr == 65038);
	bool cppVar_3290 = cppVar_3287 && cppVar_3289;
	bool cppVar_3292 = (sha_state == 4);
	bool cppVar_3294 = (cmd != 1);
	bool cppVar_3295 = cppVar_3292 && cppVar_3294;
	bool cppVar_3297 = (cmdaddr == 65037);
	bool cppVar_3298 = cppVar_3295 && cppVar_3297;
	bool cppVar_3300 = (sha_state == 4);
	bool cppVar_3302 = (cmd != 1);
	bool cppVar_3303 = cppVar_3300 && cppVar_3302;
	bool cppVar_3305 = (cmdaddr == 65036);
	bool cppVar_3306 = cppVar_3303 && cppVar_3305;
	bool cppVar_3308 = (sha_state == 4);
	bool cppVar_3310 = (cmd != 1);
	bool cppVar_3311 = cppVar_3308 && cppVar_3310;
	bool cppVar_3313 = (cmdaddr == 65035);
	bool cppVar_3314 = cppVar_3311 && cppVar_3313;
	bool cppVar_3316 = (sha_state == 4);
	bool cppVar_3318 = (cmd != 1);
	bool cppVar_3319 = cppVar_3316 && cppVar_3318;
	bool cppVar_3321 = (cmdaddr == 65034);
	bool cppVar_3322 = cppVar_3319 && cppVar_3321;
	bool cppVar_3324 = (sha_state == 4);
	bool cppVar_3326 = (cmd != 1);
	bool cppVar_3327 = cppVar_3324 && cppVar_3326;
	bool cppVar_3329 = (cmdaddr == 65033);
	bool cppVar_3330 = cppVar_3327 && cppVar_3329;
	bool cppVar_3332 = (sha_state == 4);
	bool cppVar_3334 = (cmd != 1);
	bool cppVar_3335 = cppVar_3332 && cppVar_3334;
	bool cppVar_3337 = (cmdaddr == 65032);
	bool cppVar_3338 = cppVar_3335 && cppVar_3337;
	bool cppVar_3340 = (sha_state == 4);
	bool cppVar_3342 = (cmd != 1);
	bool cppVar_3343 = cppVar_3340 && cppVar_3342;
	bool cppVar_3345 = (cmdaddr == 65031);
	bool cppVar_3346 = cppVar_3343 && cppVar_3345;
	bool cppVar_3348 = (sha_state == 4);
	bool cppVar_3350 = (cmd != 1);
	bool cppVar_3351 = cppVar_3348 && cppVar_3350;
	bool cppVar_3353 = (cmdaddr == 65030);
	bool cppVar_3354 = cppVar_3351 && cppVar_3353;
	bool cppVar_3356 = (sha_state == 4);
	bool cppVar_3358 = (cmd != 1);
	bool cppVar_3359 = cppVar_3356 && cppVar_3358;
	bool cppVar_3361 = (cmdaddr == 65029);
	bool cppVar_3362 = cppVar_3359 && cppVar_3361;
	bool cppVar_3364 = (sha_state == 4);
	bool cppVar_3366 = (cmd != 1);
	bool cppVar_3367 = cppVar_3364 && cppVar_3366;
	bool cppVar_3369 = (cmdaddr == 65028);
	bool cppVar_3370 = cppVar_3367 && cppVar_3369;
	bool cppVar_3372 = (sha_state == 4);
	bool cppVar_3374 = (cmd != 1);
	bool cppVar_3375 = cppVar_3372 && cppVar_3374;
	bool cppVar_3377 = (cmdaddr == 65027);
	bool cppVar_3378 = cppVar_3375 && cppVar_3377;
	bool cppVar_3380 = (sha_state == 4);
	bool cppVar_3382 = (cmd != 1);
	bool cppVar_3383 = cppVar_3380 && cppVar_3382;
	bool cppVar_3385 = (cmdaddr == 65026);
	bool cppVar_3386 = cppVar_3383 && cppVar_3385;
	bool cppVar_3388 = (sha_state == 4);
	bool cppVar_3390 = (cmd != 1);
	bool cppVar_3391 = cppVar_3388 && cppVar_3390;
	bool cppVar_3393 = (cmdaddr == 65025);
	bool cppVar_3394 = cppVar_3391 && cppVar_3393;
	bool cppVar_3396 = (sha_state == 4);
	bool cppVar_3398 = (cmd != 1);
	bool cppVar_3399 = cppVar_3396 && cppVar_3398;
	bool cppVar_3401 = (cmdaddr == 65024);
	bool cppVar_3402 = cppVar_3399 && cppVar_3401;
	bool cppVar_3404 = (sha_state == 0);
	bool cppVar_3406 = (cmd == 2);
	bool cppVar_3407 = cppVar_3404 && cppVar_3406;
	bool cppVar_3409 = (cmdaddr == 65039);
	bool cppVar_3410 = cppVar_3407 && cppVar_3409;
	bool cppVar_3412 = (sha_state == 0);
	bool cppVar_3414 = (cmd == 2);
	bool cppVar_3415 = cppVar_3412 && cppVar_3414;
	bool cppVar_3417 = (cmdaddr == 65038);
	bool cppVar_3418 = cppVar_3415 && cppVar_3417;
	bool cppVar_3420 = (sha_state == 0);
	bool cppVar_3422 = (cmd == 2);
	bool cppVar_3423 = cppVar_3420 && cppVar_3422;
	bool cppVar_3425 = (cmdaddr == 65037);
	bool cppVar_3426 = cppVar_3423 && cppVar_3425;
	bool cppVar_3428 = (sha_state == 0);
	bool cppVar_3430 = (cmd == 2);
	bool cppVar_3431 = cppVar_3428 && cppVar_3430;
	bool cppVar_3433 = (cmdaddr == 65036);
	bool cppVar_3434 = cppVar_3431 && cppVar_3433;
	bool cppVar_3436 = (sha_state == 0);
	bool cppVar_3438 = (cmd == 2);
	bool cppVar_3439 = cppVar_3436 && cppVar_3438;
	bool cppVar_3441 = (cmdaddr == 65035);
	bool cppVar_3442 = cppVar_3439 && cppVar_3441;
	bool cppVar_3444 = (sha_state == 0);
	bool cppVar_3446 = (cmd == 2);
	bool cppVar_3447 = cppVar_3444 && cppVar_3446;
	bool cppVar_3449 = (cmdaddr == 65034);
	bool cppVar_3450 = cppVar_3447 && cppVar_3449;
	bool cppVar_3452 = (sha_state == 0);
	bool cppVar_3454 = (cmd == 2);
	bool cppVar_3455 = cppVar_3452 && cppVar_3454;
	bool cppVar_3457 = (cmdaddr == 65033);
	bool cppVar_3458 = cppVar_3455 && cppVar_3457;
	bool cppVar_3460 = (sha_state == 0);
	bool cppVar_3462 = (cmd == 2);
	bool cppVar_3463 = cppVar_3460 && cppVar_3462;
	bool cppVar_3465 = (cmdaddr == 65032);
	bool cppVar_3466 = cppVar_3463 && cppVar_3465;
	bool cppVar_3468 = (sha_state == 0);
	bool cppVar_3470 = (cmd == 2);
	bool cppVar_3471 = cppVar_3468 && cppVar_3470;
	bool cppVar_3473 = (cmdaddr == 65031);
	bool cppVar_3474 = cppVar_3471 && cppVar_3473;
	bool cppVar_3476 = (sha_state == 0);
	bool cppVar_3478 = (cmd == 2);
	bool cppVar_3479 = cppVar_3476 && cppVar_3478;
	bool cppVar_3481 = (cmdaddr == 65030);
	bool cppVar_3482 = cppVar_3479 && cppVar_3481;
	bool cppVar_3484 = (sha_state == 0);
	bool cppVar_3486 = (cmd == 2);
	bool cppVar_3487 = cppVar_3484 && cppVar_3486;
	bool cppVar_3489 = (cmdaddr == 65029);
	bool cppVar_3490 = cppVar_3487 && cppVar_3489;
	bool cppVar_3492 = (sha_state == 0);
	bool cppVar_3494 = (cmd == 2);
	bool cppVar_3495 = cppVar_3492 && cppVar_3494;
	bool cppVar_3497 = (cmdaddr == 65028);
	bool cppVar_3498 = cppVar_3495 && cppVar_3497;
	bool cppVar_3500 = (sha_state == 0);
	bool cppVar_3502 = (cmd == 2);
	bool cppVar_3503 = cppVar_3500 && cppVar_3502;
	bool cppVar_3505 = (cmdaddr == 65027);
	bool cppVar_3506 = cppVar_3503 && cppVar_3505;
	bool cppVar_3508 = (sha_state == 0);
	bool cppVar_3510 = (cmd == 2);
	bool cppVar_3511 = cppVar_3508 && cppVar_3510;
	bool cppVar_3513 = (cmdaddr == 65026);
	bool cppVar_3514 = cppVar_3511 && cppVar_3513;
	bool cppVar_3516 = (sha_state == 0);
	bool cppVar_3518 = (cmd == 2);
	bool cppVar_3519 = cppVar_3516 && cppVar_3518;
	bool cppVar_3521 = (cmdaddr == 65025);
	bool cppVar_3522 = cppVar_3519 && cppVar_3521;
	bool cppVar_3524 = (sha_state == 4);
	bool cppVar_3526 = (cmd == 1);
	bool cppVar_3527 = cppVar_3524 && cppVar_3526;
	bool cppVar_3529 = (cmdaddr == 65039);
	bool cppVar_3530 = cppVar_3527 && cppVar_3529;
	bool cppVar_3532 = (sha_state == 0);
	bool cppVar_3534 = (cmd == 1);
	bool cppVar_3535 = cppVar_3532 && cppVar_3534;
	bool cppVar_3537 = (cmdaddr == 65039);
	bool cppVar_3538 = cppVar_3535 && cppVar_3537;
	bool cppVar_3540 = (sha_state == 4);
	bool cppVar_3542 = (cmd == 1);
	bool cppVar_3543 = cppVar_3540 && cppVar_3542;
	bool cppVar_3545 = (cmdaddr == 65038);
	bool cppVar_3546 = cppVar_3543 && cppVar_3545;
	bool cppVar_3548 = (sha_state == 0);
	bool cppVar_3550 = (cmd == 1);
	bool cppVar_3551 = cppVar_3548 && cppVar_3550;
	bool cppVar_3553 = (cmdaddr == 65038);
	bool cppVar_3554 = cppVar_3551 && cppVar_3553;
	bool cppVar_3556 = (sha_state == 4);
	bool cppVar_3558 = (cmd == 1);
	bool cppVar_3559 = cppVar_3556 && cppVar_3558;
	bool cppVar_3561 = (cmdaddr == 65037);
	bool cppVar_3562 = cppVar_3559 && cppVar_3561;
	bool cppVar_3564 = (sha_state == 0);
	bool cppVar_3566 = (cmd == 1);
	bool cppVar_3567 = cppVar_3564 && cppVar_3566;
	bool cppVar_3569 = (cmdaddr == 65037);
	bool cppVar_3570 = cppVar_3567 && cppVar_3569;
	bool cppVar_3572 = (sha_state == 4);
	bool cppVar_3574 = (cmd == 1);
	bool cppVar_3575 = cppVar_3572 && cppVar_3574;
	bool cppVar_3577 = (cmdaddr == 65036);
	bool cppVar_3578 = cppVar_3575 && cppVar_3577;
	bool cppVar_3580 = (sha_state == 0);
	bool cppVar_3582 = (cmd == 1);
	bool cppVar_3583 = cppVar_3580 && cppVar_3582;
	bool cppVar_3585 = (cmdaddr == 65036);
	bool cppVar_3586 = cppVar_3583 && cppVar_3585;
	bool cppVar_3588 = (sha_state == 4);
	bool cppVar_3590 = (cmd == 1);
	bool cppVar_3591 = cppVar_3588 && cppVar_3590;
	bool cppVar_3593 = (cmdaddr == 65035);
	bool cppVar_3594 = cppVar_3591 && cppVar_3593;
	bool cppVar_3596 = (sha_state == 0);
	bool cppVar_3598 = (cmd == 1);
	bool cppVar_3599 = cppVar_3596 && cppVar_3598;
	bool cppVar_3601 = (cmdaddr == 65035);
	bool cppVar_3602 = cppVar_3599 && cppVar_3601;
	bool cppVar_3604 = (sha_state == 4);
	bool cppVar_3606 = (cmd == 1);
	bool cppVar_3607 = cppVar_3604 && cppVar_3606;
	bool cppVar_3609 = (cmdaddr == 65034);
	bool cppVar_3610 = cppVar_3607 && cppVar_3609;
	bool cppVar_3612 = (sha_state == 0);
	bool cppVar_3614 = (cmd == 1);
	bool cppVar_3615 = cppVar_3612 && cppVar_3614;
	bool cppVar_3617 = (cmdaddr == 65034);
	bool cppVar_3618 = cppVar_3615 && cppVar_3617;
	bool cppVar_3620 = (sha_state == 4);
	bool cppVar_3622 = (cmd == 1);
	bool cppVar_3623 = cppVar_3620 && cppVar_3622;
	bool cppVar_3625 = (cmdaddr == 65033);
	bool cppVar_3626 = cppVar_3623 && cppVar_3625;
	bool cppVar_3628 = (sha_state == 0);
	bool cppVar_3630 = (cmd == 1);
	bool cppVar_3631 = cppVar_3628 && cppVar_3630;
	bool cppVar_3633 = (cmdaddr == 65033);
	bool cppVar_3634 = cppVar_3631 && cppVar_3633;
	bool cppVar_3636 = (sha_state == 4);
	bool cppVar_3638 = (cmd == 1);
	bool cppVar_3639 = cppVar_3636 && cppVar_3638;
	bool cppVar_3641 = (cmdaddr == 65032);
	bool cppVar_3642 = cppVar_3639 && cppVar_3641;
	bool cppVar_3644 = (sha_state == 0);
	bool cppVar_3646 = (cmd == 1);
	bool cppVar_3647 = cppVar_3644 && cppVar_3646;
	bool cppVar_3649 = (cmdaddr == 65032);
	bool cppVar_3650 = cppVar_3647 && cppVar_3649;
	bool cppVar_3652 = (sha_state == 4);
	bool cppVar_3654 = (cmd == 1);
	bool cppVar_3655 = cppVar_3652 && cppVar_3654;
	bool cppVar_3657 = (cmdaddr == 65031);
	bool cppVar_3658 = cppVar_3655 && cppVar_3657;
	bool cppVar_3660 = (sha_state == 0);
	bool cppVar_3662 = (cmd == 1);
	bool cppVar_3663 = cppVar_3660 && cppVar_3662;
	bool cppVar_3665 = (cmdaddr == 65031);
	bool cppVar_3666 = cppVar_3663 && cppVar_3665;
	bool cppVar_3668 = (sha_state == 4);
	bool cppVar_3670 = (cmd == 1);
	bool cppVar_3671 = cppVar_3668 && cppVar_3670;
	bool cppVar_3673 = (cmdaddr == 65030);
	bool cppVar_3674 = cppVar_3671 && cppVar_3673;
	bool cppVar_3676 = (sha_state == 0);
	bool cppVar_3678 = (cmd == 1);
	bool cppVar_3679 = cppVar_3676 && cppVar_3678;
	bool cppVar_3681 = (cmdaddr == 65030);
	bool cppVar_3682 = cppVar_3679 && cppVar_3681;
	bool cppVar_3684 = (sha_state == 4);
	bool cppVar_3686 = (cmd == 1);
	bool cppVar_3687 = cppVar_3684 && cppVar_3686;
	bool cppVar_3689 = (cmdaddr == 65029);
	bool cppVar_3690 = cppVar_3687 && cppVar_3689;
	bool cppVar_3692 = (sha_state == 0);
	bool cppVar_3694 = (cmd == 1);
	bool cppVar_3695 = cppVar_3692 && cppVar_3694;
	bool cppVar_3697 = (cmdaddr == 65029);
	bool cppVar_3698 = cppVar_3695 && cppVar_3697;
	bool cppVar_3700 = (sha_state == 4);
	bool cppVar_3702 = (cmd == 1);
	bool cppVar_3703 = cppVar_3700 && cppVar_3702;
	bool cppVar_3705 = (cmdaddr == 65028);
	bool cppVar_3706 = cppVar_3703 && cppVar_3705;
	bool cppVar_3708 = (sha_state == 0);
	bool cppVar_3710 = (cmd == 1);
	bool cppVar_3711 = cppVar_3708 && cppVar_3710;
	bool cppVar_3713 = (cmdaddr == 65028);
	bool cppVar_3714 = cppVar_3711 && cppVar_3713;
	bool cppVar_3716 = (sha_state == 4);
	bool cppVar_3718 = (cmd == 1);
	bool cppVar_3719 = cppVar_3716 && cppVar_3718;
	bool cppVar_3721 = (cmdaddr == 65027);
	bool cppVar_3722 = cppVar_3719 && cppVar_3721;
	bool cppVar_3724 = (sha_state == 0);
	bool cppVar_3726 = (cmd == 1);
	bool cppVar_3727 = cppVar_3724 && cppVar_3726;
	bool cppVar_3729 = (cmdaddr == 65027);
	bool cppVar_3730 = cppVar_3727 && cppVar_3729;
	bool cppVar_3732 = (sha_state == 4);
	bool cppVar_3734 = (cmd == 1);
	bool cppVar_3735 = cppVar_3732 && cppVar_3734;
	bool cppVar_3737 = (cmdaddr == 65026);
	bool cppVar_3738 = cppVar_3735 && cppVar_3737;
	bool cppVar_3740 = (sha_state == 0);
	bool cppVar_3742 = (cmd == 1);
	bool cppVar_3743 = cppVar_3740 && cppVar_3742;
	bool cppVar_3745 = (cmdaddr == 65026);
	bool cppVar_3746 = cppVar_3743 && cppVar_3745;
	bool cppVar_3748 = (sha_state == 4);
	bool cppVar_3750 = (cmd == 1);
	bool cppVar_3751 = cppVar_3748 && cppVar_3750;
	bool cppVar_3753 = (cmdaddr == 65025);
	bool cppVar_3754 = cppVar_3751 && cppVar_3753;
	bool cppVar_3756 = (sha_state == 0);
	bool cppVar_3758 = (cmd == 1);
	bool cppVar_3759 = cppVar_3756 && cppVar_3758;
	bool cppVar_3761 = (cmdaddr == 65025);
	bool cppVar_3762 = cppVar_3759 && cppVar_3761;
	bool cppVar_3764 = (sha_state == 4);
	bool cppVar_3766 = (cmd == 1);
	bool cppVar_3767 = cppVar_3764 && cppVar_3766;
	bool cppVar_3769 = (cmdaddr == 65024);
	bool cppVar_3770 = cppVar_3767 && cppVar_3769;
	bool cppVar_3772 = (sha_state == 0);
	bool cppVar_3774 = (cmd == 1);
	bool cppVar_3775 = cppVar_3772 && cppVar_3774;
	bool cppVar_3777 = (cmdaddr == 65024);
	bool cppVar_3778 = cppVar_3775 && cppVar_3777;
	bool cppVar_3779 = cppVar_3770 || cppVar_3778;
	bool cppVar_3780 = cppVar_3762 || cppVar_3779;
	bool cppVar_3781 = cppVar_3754 || cppVar_3780;
	bool cppVar_3782 = cppVar_3746 || cppVar_3781;
	bool cppVar_3783 = cppVar_3738 || cppVar_3782;
	bool cppVar_3784 = cppVar_3730 || cppVar_3783;
	bool cppVar_3785 = cppVar_3722 || cppVar_3784;
	bool cppVar_3786 = cppVar_3714 || cppVar_3785;
	bool cppVar_3787 = cppVar_3706 || cppVar_3786;
	bool cppVar_3788 = cppVar_3698 || cppVar_3787;
	bool cppVar_3789 = cppVar_3690 || cppVar_3788;
	bool cppVar_3790 = cppVar_3682 || cppVar_3789;
	bool cppVar_3791 = cppVar_3674 || cppVar_3790;
	bool cppVar_3792 = cppVar_3666 || cppVar_3791;
	bool cppVar_3793 = cppVar_3658 || cppVar_3792;
	bool cppVar_3794 = cppVar_3650 || cppVar_3793;
	bool cppVar_3795 = cppVar_3642 || cppVar_3794;
	bool cppVar_3796 = cppVar_3634 || cppVar_3795;
	bool cppVar_3797 = cppVar_3626 || cppVar_3796;
	bool cppVar_3798 = cppVar_3618 || cppVar_3797;
	bool cppVar_3799 = cppVar_3610 || cppVar_3798;
	bool cppVar_3800 = cppVar_3602 || cppVar_3799;
	bool cppVar_3801 = cppVar_3594 || cppVar_3800;
	bool cppVar_3802 = cppVar_3586 || cppVar_3801;
	bool cppVar_3803 = cppVar_3578 || cppVar_3802;
	bool cppVar_3804 = cppVar_3570 || cppVar_3803;
	bool cppVar_3805 = cppVar_3562 || cppVar_3804;
	bool cppVar_3806 = cppVar_3554 || cppVar_3805;
	bool cppVar_3807 = cppVar_3546 || cppVar_3806;
	bool cppVar_3808 = cppVar_3538 || cppVar_3807;
	bool cppVar_3809 = cppVar_3530 || cppVar_3808;
	bool cppVar_3810 = cppVar_3522 || cppVar_3809;
	bool cppVar_3811 = cppVar_3514 || cppVar_3810;
	bool cppVar_3812 = cppVar_3506 || cppVar_3811;
	bool cppVar_3813 = cppVar_3498 || cppVar_3812;
	bool cppVar_3814 = cppVar_3490 || cppVar_3813;
	bool cppVar_3815 = cppVar_3482 || cppVar_3814;
	bool cppVar_3816 = cppVar_3474 || cppVar_3815;
	bool cppVar_3817 = cppVar_3466 || cppVar_3816;
	bool cppVar_3818 = cppVar_3458 || cppVar_3817;
	bool cppVar_3819 = cppVar_3450 || cppVar_3818;
	bool cppVar_3820 = cppVar_3442 || cppVar_3819;
	bool cppVar_3821 = cppVar_3434 || cppVar_3820;
	bool cppVar_3822 = cppVar_3426 || cppVar_3821;
	bool cppVar_3823 = cppVar_3418 || cppVar_3822;
	bool cppVar_3824 = cppVar_3410 || cppVar_3823;
	bool cppVar_3825 = cppVar_3402 || cppVar_3824;
	bool cppVar_3826 = cppVar_3394 || cppVar_3825;
	bool cppVar_3827 = cppVar_3386 || cppVar_3826;
	bool cppVar_3828 = cppVar_3378 || cppVar_3827;
	bool cppVar_3829 = cppVar_3370 || cppVar_3828;
	bool cppVar_3830 = cppVar_3362 || cppVar_3829;
	bool cppVar_3831 = cppVar_3354 || cppVar_3830;
	bool cppVar_3832 = cppVar_3346 || cppVar_3831;
	bool cppVar_3833 = cppVar_3338 || cppVar_3832;
	bool cppVar_3834 = cppVar_3330 || cppVar_3833;
	bool cppVar_3835 = cppVar_3322 || cppVar_3834;
	bool cppVar_3836 = cppVar_3314 || cppVar_3835;
	bool cppVar_3837 = cppVar_3306 || cppVar_3836;
	bool cppVar_3838 = cppVar_3298 || cppVar_3837;
	bool cppVar_3839 = cppVar_3290 || cppVar_3838;
	bool cppVar_3840 = cppVar_3282 || cppVar_3839;
	BIT_VEC cppVar_3842 = (cppVar_3840) ? 0 : sha_state;
	BIT_VEC cppVar_3843 = (cppVar_3273) ? 2 : cppVar_3842;
	BIT_VEC cppVar_3844 = (cppVar_2985) ? 3 : cppVar_3843;
	BIT_VEC cppVar_3845 = (cppVar_2694) ? cppVar_2698 : cppVar_3844;
	BIT_VEC cppVar_3846 = (cppVar_2403) ? cppVar_2407 : cppVar_3845;
	return cppVar_3846;
}
BIT_VEC model_sha::cppUpdateFun_sha_wraddr(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_3849 = (sha_state == 0);
	bool cppVar_3851 = (cmd == 2);
	bool cppVar_3852 = cppVar_3849 && cppVar_3851;
	bool cppVar_3854 = (cmdaddr == 65029);
	bool cppVar_3855 = cppVar_3852 && cppVar_3854;
	BIT_VEC cppVar_3856 = (sha_wraddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_3857 = (cmddata << 8) | cppVar_3856;
	cppVar_3857 = (cppVar_3857 & cppMask_un_16_);
	bool cppVar_3859 = (sha_state == 0);
	bool cppVar_3861 = (cmd == 2);
	bool cppVar_3862 = cppVar_3859 && cppVar_3861;
	bool cppVar_3864 = (cmdaddr == 65028);
	bool cppVar_3865 = cppVar_3862 && cppVar_3864;
	BIT_VEC cppVar_3866 = (sha_wraddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_3867 = (cppVar_3866 << 8) | cmddata;
	cppVar_3867 = (cppVar_3867 & cppMask_un_16_);
	BIT_VEC cppVar_3868 = (cppVar_3865) ? cppVar_3867 : sha_wraddr;
	BIT_VEC cppVar_3869 = (cppVar_3855) ? cppVar_3857 : cppVar_3868;
	return cppVar_3869;
}
bool model_sha::decode_0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4171 = (sha_state == 0);
	bool cppVar_4173 = (cmd == 1);
	bool cppVar_4174 = cppVar_4171 && cppVar_4173;
	bool cppVar_4176 = (cmdaddr == 65024);
	bool cppVar_4177 = cppVar_4174 && cppVar_4176;
	return cppVar_4177;
}
bool model_sha::decode_1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4179 = (sha_state == 1);
	bool cppVar_4181 = (cmd == 1);
	bool cppVar_4182 = cppVar_4179 && cppVar_4181;
	bool cppVar_4184 = (cmdaddr == 65024);
	bool cppVar_4185 = cppVar_4182 && cppVar_4184;
	return cppVar_4185;
}
bool model_sha::decode_10(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4251 = (sha_state == 0);
	bool cppVar_4253 = (cmd == 1);
	bool cppVar_4254 = cppVar_4251 && cppVar_4253;
	bool cppVar_4256 = (cmdaddr == 65026);
	bool cppVar_4257 = cppVar_4254 && cppVar_4256;
	return cppVar_4257;
}
bool model_sha::decode_100(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4971 = (sha_state == 1);
	bool cppVar_4973 = (cmd != 1);
	bool cppVar_4974 = cppVar_4971 && cppVar_4973;
	bool cppVar_4976 = (cmdaddr == 65025);
	bool cppVar_4977 = cppVar_4974 && cppVar_4976;
	return cppVar_4977;
}
bool model_sha::decode_101(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4979 = (sha_state == 2);
	bool cppVar_4981 = (cmd != 1);
	bool cppVar_4982 = cppVar_4979 && cppVar_4981;
	bool cppVar_4984 = (cmdaddr == 65025);
	bool cppVar_4985 = cppVar_4982 && cppVar_4984;
	return cppVar_4985;
}
bool model_sha::decode_102(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4987 = (sha_state == 3);
	bool cppVar_4989 = (cmd != 1);
	bool cppVar_4990 = cppVar_4987 && cppVar_4989;
	bool cppVar_4992 = (cmdaddr == 65025);
	bool cppVar_4993 = cppVar_4990 && cppVar_4992;
	return cppVar_4993;
}
bool model_sha::decode_103(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4995 = (sha_state == 4);
	bool cppVar_4997 = (cmd != 1);
	bool cppVar_4998 = cppVar_4995 && cppVar_4997;
	bool cppVar_5000 = (cmdaddr == 65025);
	bool cppVar_5001 = cppVar_4998 && cppVar_5000;
	return cppVar_5001;
}
bool model_sha::decode_104(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5003 = (sha_state == 1);
	bool cppVar_5005 = (cmd != 1);
	bool cppVar_5006 = cppVar_5003 && cppVar_5005;
	bool cppVar_5008 = (cmdaddr == 65026);
	bool cppVar_5009 = cppVar_5006 && cppVar_5008;
	return cppVar_5009;
}
bool model_sha::decode_105(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5011 = (sha_state == 2);
	bool cppVar_5013 = (cmd != 1);
	bool cppVar_5014 = cppVar_5011 && cppVar_5013;
	bool cppVar_5016 = (cmdaddr == 65026);
	bool cppVar_5017 = cppVar_5014 && cppVar_5016;
	return cppVar_5017;
}
bool model_sha::decode_106(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5019 = (sha_state == 3);
	bool cppVar_5021 = (cmd != 1);
	bool cppVar_5022 = cppVar_5019 && cppVar_5021;
	bool cppVar_5024 = (cmdaddr == 65026);
	bool cppVar_5025 = cppVar_5022 && cppVar_5024;
	return cppVar_5025;
}
bool model_sha::decode_107(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5027 = (sha_state == 4);
	bool cppVar_5029 = (cmd != 1);
	bool cppVar_5030 = cppVar_5027 && cppVar_5029;
	bool cppVar_5032 = (cmdaddr == 65026);
	bool cppVar_5033 = cppVar_5030 && cppVar_5032;
	return cppVar_5033;
}
bool model_sha::decode_108(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5035 = (sha_state == 1);
	bool cppVar_5037 = (cmd != 1);
	bool cppVar_5038 = cppVar_5035 && cppVar_5037;
	bool cppVar_5040 = (cmdaddr == 65027);
	bool cppVar_5041 = cppVar_5038 && cppVar_5040;
	return cppVar_5041;
}
bool model_sha::decode_109(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5043 = (sha_state == 2);
	bool cppVar_5045 = (cmd != 1);
	bool cppVar_5046 = cppVar_5043 && cppVar_5045;
	bool cppVar_5048 = (cmdaddr == 65027);
	bool cppVar_5049 = cppVar_5046 && cppVar_5048;
	return cppVar_5049;
}
bool model_sha::decode_11(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4259 = (sha_state == 1);
	bool cppVar_4261 = (cmd == 1);
	bool cppVar_4262 = cppVar_4259 && cppVar_4261;
	bool cppVar_4264 = (cmdaddr == 65026);
	bool cppVar_4265 = cppVar_4262 && cppVar_4264;
	return cppVar_4265;
}
bool model_sha::decode_110(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5051 = (sha_state == 3);
	bool cppVar_5053 = (cmd != 1);
	bool cppVar_5054 = cppVar_5051 && cppVar_5053;
	bool cppVar_5056 = (cmdaddr == 65027);
	bool cppVar_5057 = cppVar_5054 && cppVar_5056;
	return cppVar_5057;
}
bool model_sha::decode_111(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5059 = (sha_state == 4);
	bool cppVar_5061 = (cmd != 1);
	bool cppVar_5062 = cppVar_5059 && cppVar_5061;
	bool cppVar_5064 = (cmdaddr == 65027);
	bool cppVar_5065 = cppVar_5062 && cppVar_5064;
	return cppVar_5065;
}
bool model_sha::decode_112(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5067 = (sha_state == 1);
	bool cppVar_5069 = (cmd != 1);
	bool cppVar_5070 = cppVar_5067 && cppVar_5069;
	bool cppVar_5072 = (cmdaddr == 65028);
	bool cppVar_5073 = cppVar_5070 && cppVar_5072;
	return cppVar_5073;
}
bool model_sha::decode_113(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5075 = (sha_state == 2);
	bool cppVar_5077 = (cmd != 1);
	bool cppVar_5078 = cppVar_5075 && cppVar_5077;
	bool cppVar_5080 = (cmdaddr == 65028);
	bool cppVar_5081 = cppVar_5078 && cppVar_5080;
	return cppVar_5081;
}
bool model_sha::decode_114(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5083 = (sha_state == 3);
	bool cppVar_5085 = (cmd != 1);
	bool cppVar_5086 = cppVar_5083 && cppVar_5085;
	bool cppVar_5088 = (cmdaddr == 65028);
	bool cppVar_5089 = cppVar_5086 && cppVar_5088;
	return cppVar_5089;
}
bool model_sha::decode_115(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5091 = (sha_state == 4);
	bool cppVar_5093 = (cmd != 1);
	bool cppVar_5094 = cppVar_5091 && cppVar_5093;
	bool cppVar_5096 = (cmdaddr == 65028);
	bool cppVar_5097 = cppVar_5094 && cppVar_5096;
	return cppVar_5097;
}
bool model_sha::decode_116(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5099 = (sha_state == 1);
	bool cppVar_5101 = (cmd != 1);
	bool cppVar_5102 = cppVar_5099 && cppVar_5101;
	bool cppVar_5104 = (cmdaddr == 65029);
	bool cppVar_5105 = cppVar_5102 && cppVar_5104;
	return cppVar_5105;
}
bool model_sha::decode_117(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5107 = (sha_state == 2);
	bool cppVar_5109 = (cmd != 1);
	bool cppVar_5110 = cppVar_5107 && cppVar_5109;
	bool cppVar_5112 = (cmdaddr == 65029);
	bool cppVar_5113 = cppVar_5110 && cppVar_5112;
	return cppVar_5113;
}
bool model_sha::decode_118(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5115 = (sha_state == 3);
	bool cppVar_5117 = (cmd != 1);
	bool cppVar_5118 = cppVar_5115 && cppVar_5117;
	bool cppVar_5120 = (cmdaddr == 65029);
	bool cppVar_5121 = cppVar_5118 && cppVar_5120;
	return cppVar_5121;
}
bool model_sha::decode_119(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5123 = (sha_state == 4);
	bool cppVar_5125 = (cmd != 1);
	bool cppVar_5126 = cppVar_5123 && cppVar_5125;
	bool cppVar_5128 = (cmdaddr == 65029);
	bool cppVar_5129 = cppVar_5126 && cppVar_5128;
	return cppVar_5129;
}
bool model_sha::decode_12(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4267 = (sha_state == 2);
	bool cppVar_4269 = (cmd == 1);
	bool cppVar_4270 = cppVar_4267 && cppVar_4269;
	bool cppVar_4272 = (cmdaddr == 65026);
	bool cppVar_4273 = cppVar_4270 && cppVar_4272;
	return cppVar_4273;
}
bool model_sha::decode_120(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5131 = (sha_state == 1);
	bool cppVar_5133 = (cmd != 1);
	bool cppVar_5134 = cppVar_5131 && cppVar_5133;
	bool cppVar_5136 = (cmdaddr == 65030);
	bool cppVar_5137 = cppVar_5134 && cppVar_5136;
	return cppVar_5137;
}
bool model_sha::decode_121(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5139 = (sha_state == 2);
	bool cppVar_5141 = (cmd != 1);
	bool cppVar_5142 = cppVar_5139 && cppVar_5141;
	bool cppVar_5144 = (cmdaddr == 65030);
	bool cppVar_5145 = cppVar_5142 && cppVar_5144;
	return cppVar_5145;
}
bool model_sha::decode_122(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5147 = (sha_state == 3);
	bool cppVar_5149 = (cmd != 1);
	bool cppVar_5150 = cppVar_5147 && cppVar_5149;
	bool cppVar_5152 = (cmdaddr == 65030);
	bool cppVar_5153 = cppVar_5150 && cppVar_5152;
	return cppVar_5153;
}
bool model_sha::decode_123(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5155 = (sha_state == 4);
	bool cppVar_5157 = (cmd != 1);
	bool cppVar_5158 = cppVar_5155 && cppVar_5157;
	bool cppVar_5160 = (cmdaddr == 65030);
	bool cppVar_5161 = cppVar_5158 && cppVar_5160;
	return cppVar_5161;
}
bool model_sha::decode_124(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5163 = (sha_state == 1);
	bool cppVar_5165 = (cmd != 1);
	bool cppVar_5166 = cppVar_5163 && cppVar_5165;
	bool cppVar_5168 = (cmdaddr == 65031);
	bool cppVar_5169 = cppVar_5166 && cppVar_5168;
	return cppVar_5169;
}
bool model_sha::decode_125(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5171 = (sha_state == 2);
	bool cppVar_5173 = (cmd != 1);
	bool cppVar_5174 = cppVar_5171 && cppVar_5173;
	bool cppVar_5176 = (cmdaddr == 65031);
	bool cppVar_5177 = cppVar_5174 && cppVar_5176;
	return cppVar_5177;
}
bool model_sha::decode_126(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5179 = (sha_state == 3);
	bool cppVar_5181 = (cmd != 1);
	bool cppVar_5182 = cppVar_5179 && cppVar_5181;
	bool cppVar_5184 = (cmdaddr == 65031);
	bool cppVar_5185 = cppVar_5182 && cppVar_5184;
	return cppVar_5185;
}
bool model_sha::decode_127(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5187 = (sha_state == 4);
	bool cppVar_5189 = (cmd != 1);
	bool cppVar_5190 = cppVar_5187 && cppVar_5189;
	bool cppVar_5192 = (cmdaddr == 65031);
	bool cppVar_5193 = cppVar_5190 && cppVar_5192;
	return cppVar_5193;
}
bool model_sha::decode_128(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5195 = (sha_state == 1);
	bool cppVar_5197 = (cmd != 1);
	bool cppVar_5198 = cppVar_5195 && cppVar_5197;
	bool cppVar_5200 = (cmdaddr == 65032);
	bool cppVar_5201 = cppVar_5198 && cppVar_5200;
	return cppVar_5201;
}
bool model_sha::decode_129(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5203 = (sha_state == 2);
	bool cppVar_5205 = (cmd != 1);
	bool cppVar_5206 = cppVar_5203 && cppVar_5205;
	bool cppVar_5208 = (cmdaddr == 65032);
	bool cppVar_5209 = cppVar_5206 && cppVar_5208;
	return cppVar_5209;
}
bool model_sha::decode_13(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4275 = (sha_state == 3);
	bool cppVar_4277 = (cmd == 1);
	bool cppVar_4278 = cppVar_4275 && cppVar_4277;
	bool cppVar_4280 = (cmdaddr == 65026);
	bool cppVar_4281 = cppVar_4278 && cppVar_4280;
	return cppVar_4281;
}
bool model_sha::decode_130(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5211 = (sha_state == 3);
	bool cppVar_5213 = (cmd != 1);
	bool cppVar_5214 = cppVar_5211 && cppVar_5213;
	bool cppVar_5216 = (cmdaddr == 65032);
	bool cppVar_5217 = cppVar_5214 && cppVar_5216;
	return cppVar_5217;
}
bool model_sha::decode_131(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5219 = (sha_state == 4);
	bool cppVar_5221 = (cmd != 1);
	bool cppVar_5222 = cppVar_5219 && cppVar_5221;
	bool cppVar_5224 = (cmdaddr == 65032);
	bool cppVar_5225 = cppVar_5222 && cppVar_5224;
	return cppVar_5225;
}
bool model_sha::decode_132(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5227 = (sha_state == 1);
	bool cppVar_5229 = (cmd != 1);
	bool cppVar_5230 = cppVar_5227 && cppVar_5229;
	bool cppVar_5232 = (cmdaddr == 65033);
	bool cppVar_5233 = cppVar_5230 && cppVar_5232;
	return cppVar_5233;
}
bool model_sha::decode_133(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5235 = (sha_state == 2);
	bool cppVar_5237 = (cmd != 1);
	bool cppVar_5238 = cppVar_5235 && cppVar_5237;
	bool cppVar_5240 = (cmdaddr == 65033);
	bool cppVar_5241 = cppVar_5238 && cppVar_5240;
	return cppVar_5241;
}
bool model_sha::decode_134(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5243 = (sha_state == 3);
	bool cppVar_5245 = (cmd != 1);
	bool cppVar_5246 = cppVar_5243 && cppVar_5245;
	bool cppVar_5248 = (cmdaddr == 65033);
	bool cppVar_5249 = cppVar_5246 && cppVar_5248;
	return cppVar_5249;
}
bool model_sha::decode_135(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5251 = (sha_state == 4);
	bool cppVar_5253 = (cmd != 1);
	bool cppVar_5254 = cppVar_5251 && cppVar_5253;
	bool cppVar_5256 = (cmdaddr == 65033);
	bool cppVar_5257 = cppVar_5254 && cppVar_5256;
	return cppVar_5257;
}
bool model_sha::decode_136(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5259 = (sha_state == 1);
	bool cppVar_5261 = (cmd != 1);
	bool cppVar_5262 = cppVar_5259 && cppVar_5261;
	bool cppVar_5264 = (cmdaddr == 65034);
	bool cppVar_5265 = cppVar_5262 && cppVar_5264;
	return cppVar_5265;
}
bool model_sha::decode_137(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5267 = (sha_state == 2);
	bool cppVar_5269 = (cmd != 1);
	bool cppVar_5270 = cppVar_5267 && cppVar_5269;
	bool cppVar_5272 = (cmdaddr == 65034);
	bool cppVar_5273 = cppVar_5270 && cppVar_5272;
	return cppVar_5273;
}
bool model_sha::decode_138(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5275 = (sha_state == 3);
	bool cppVar_5277 = (cmd != 1);
	bool cppVar_5278 = cppVar_5275 && cppVar_5277;
	bool cppVar_5280 = (cmdaddr == 65034);
	bool cppVar_5281 = cppVar_5278 && cppVar_5280;
	return cppVar_5281;
}
bool model_sha::decode_139(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5283 = (sha_state == 4);
	bool cppVar_5285 = (cmd != 1);
	bool cppVar_5286 = cppVar_5283 && cppVar_5285;
	bool cppVar_5288 = (cmdaddr == 65034);
	bool cppVar_5289 = cppVar_5286 && cppVar_5288;
	return cppVar_5289;
}
bool model_sha::decode_14(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4283 = (sha_state == 4);
	bool cppVar_4285 = (cmd == 1);
	bool cppVar_4286 = cppVar_4283 && cppVar_4285;
	bool cppVar_4288 = (cmdaddr == 65026);
	bool cppVar_4289 = cppVar_4286 && cppVar_4288;
	return cppVar_4289;
}
bool model_sha::decode_140(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5291 = (sha_state == 1);
	bool cppVar_5293 = (cmd != 1);
	bool cppVar_5294 = cppVar_5291 && cppVar_5293;
	bool cppVar_5296 = (cmdaddr == 65035);
	bool cppVar_5297 = cppVar_5294 && cppVar_5296;
	return cppVar_5297;
}
bool model_sha::decode_141(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5299 = (sha_state == 2);
	bool cppVar_5301 = (cmd != 1);
	bool cppVar_5302 = cppVar_5299 && cppVar_5301;
	bool cppVar_5304 = (cmdaddr == 65035);
	bool cppVar_5305 = cppVar_5302 && cppVar_5304;
	return cppVar_5305;
}
bool model_sha::decode_142(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5307 = (sha_state == 3);
	bool cppVar_5309 = (cmd != 1);
	bool cppVar_5310 = cppVar_5307 && cppVar_5309;
	bool cppVar_5312 = (cmdaddr == 65035);
	bool cppVar_5313 = cppVar_5310 && cppVar_5312;
	return cppVar_5313;
}
bool model_sha::decode_143(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5315 = (sha_state == 4);
	bool cppVar_5317 = (cmd != 1);
	bool cppVar_5318 = cppVar_5315 && cppVar_5317;
	bool cppVar_5320 = (cmdaddr == 65035);
	bool cppVar_5321 = cppVar_5318 && cppVar_5320;
	return cppVar_5321;
}
bool model_sha::decode_144(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5323 = (sha_state == 1);
	bool cppVar_5325 = (cmd != 1);
	bool cppVar_5326 = cppVar_5323 && cppVar_5325;
	bool cppVar_5328 = (cmdaddr == 65036);
	bool cppVar_5329 = cppVar_5326 && cppVar_5328;
	return cppVar_5329;
}
bool model_sha::decode_145(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5331 = (sha_state == 2);
	bool cppVar_5333 = (cmd != 1);
	bool cppVar_5334 = cppVar_5331 && cppVar_5333;
	bool cppVar_5336 = (cmdaddr == 65036);
	bool cppVar_5337 = cppVar_5334 && cppVar_5336;
	return cppVar_5337;
}
bool model_sha::decode_146(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5339 = (sha_state == 3);
	bool cppVar_5341 = (cmd != 1);
	bool cppVar_5342 = cppVar_5339 && cppVar_5341;
	bool cppVar_5344 = (cmdaddr == 65036);
	bool cppVar_5345 = cppVar_5342 && cppVar_5344;
	return cppVar_5345;
}
bool model_sha::decode_147(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5347 = (sha_state == 4);
	bool cppVar_5349 = (cmd != 1);
	bool cppVar_5350 = cppVar_5347 && cppVar_5349;
	bool cppVar_5352 = (cmdaddr == 65036);
	bool cppVar_5353 = cppVar_5350 && cppVar_5352;
	return cppVar_5353;
}
bool model_sha::decode_148(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5355 = (sha_state == 1);
	bool cppVar_5357 = (cmd != 1);
	bool cppVar_5358 = cppVar_5355 && cppVar_5357;
	bool cppVar_5360 = (cmdaddr == 65037);
	bool cppVar_5361 = cppVar_5358 && cppVar_5360;
	return cppVar_5361;
}
bool model_sha::decode_149(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5363 = (sha_state == 2);
	bool cppVar_5365 = (cmd != 1);
	bool cppVar_5366 = cppVar_5363 && cppVar_5365;
	bool cppVar_5368 = (cmdaddr == 65037);
	bool cppVar_5369 = cppVar_5366 && cppVar_5368;
	return cppVar_5369;
}
bool model_sha::decode_15(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4291 = (sha_state == 0);
	bool cppVar_4293 = (cmd == 1);
	bool cppVar_4294 = cppVar_4291 && cppVar_4293;
	bool cppVar_4296 = (cmdaddr == 65027);
	bool cppVar_4297 = cppVar_4294 && cppVar_4296;
	return cppVar_4297;
}
bool model_sha::decode_150(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5371 = (sha_state == 3);
	bool cppVar_5373 = (cmd != 1);
	bool cppVar_5374 = cppVar_5371 && cppVar_5373;
	bool cppVar_5376 = (cmdaddr == 65037);
	bool cppVar_5377 = cppVar_5374 && cppVar_5376;
	return cppVar_5377;
}
bool model_sha::decode_151(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5379 = (sha_state == 4);
	bool cppVar_5381 = (cmd != 1);
	bool cppVar_5382 = cppVar_5379 && cppVar_5381;
	bool cppVar_5384 = (cmdaddr == 65037);
	bool cppVar_5385 = cppVar_5382 && cppVar_5384;
	return cppVar_5385;
}
bool model_sha::decode_152(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5387 = (sha_state == 1);
	bool cppVar_5389 = (cmd != 1);
	bool cppVar_5390 = cppVar_5387 && cppVar_5389;
	bool cppVar_5392 = (cmdaddr == 65038);
	bool cppVar_5393 = cppVar_5390 && cppVar_5392;
	return cppVar_5393;
}
bool model_sha::decode_153(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5395 = (sha_state == 2);
	bool cppVar_5397 = (cmd != 1);
	bool cppVar_5398 = cppVar_5395 && cppVar_5397;
	bool cppVar_5400 = (cmdaddr == 65038);
	bool cppVar_5401 = cppVar_5398 && cppVar_5400;
	return cppVar_5401;
}
bool model_sha::decode_154(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5403 = (sha_state == 3);
	bool cppVar_5405 = (cmd != 1);
	bool cppVar_5406 = cppVar_5403 && cppVar_5405;
	bool cppVar_5408 = (cmdaddr == 65038);
	bool cppVar_5409 = cppVar_5406 && cppVar_5408;
	return cppVar_5409;
}
bool model_sha::decode_155(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5411 = (sha_state == 4);
	bool cppVar_5413 = (cmd != 1);
	bool cppVar_5414 = cppVar_5411 && cppVar_5413;
	bool cppVar_5416 = (cmdaddr == 65038);
	bool cppVar_5417 = cppVar_5414 && cppVar_5416;
	return cppVar_5417;
}
bool model_sha::decode_156(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5419 = (sha_state == 1);
	bool cppVar_5421 = (cmd != 1);
	bool cppVar_5422 = cppVar_5419 && cppVar_5421;
	bool cppVar_5424 = (cmdaddr == 65039);
	bool cppVar_5425 = cppVar_5422 && cppVar_5424;
	return cppVar_5425;
}
bool model_sha::decode_157(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5427 = (sha_state == 2);
	bool cppVar_5429 = (cmd != 1);
	bool cppVar_5430 = cppVar_5427 && cppVar_5429;
	bool cppVar_5432 = (cmdaddr == 65039);
	bool cppVar_5433 = cppVar_5430 && cppVar_5432;
	return cppVar_5433;
}
bool model_sha::decode_158(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5435 = (sha_state == 3);
	bool cppVar_5437 = (cmd != 1);
	bool cppVar_5438 = cppVar_5435 && cppVar_5437;
	bool cppVar_5440 = (cmdaddr == 65039);
	bool cppVar_5441 = cppVar_5438 && cppVar_5440;
	return cppVar_5441;
}
bool model_sha::decode_159(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_5443 = (sha_state == 4);
	bool cppVar_5445 = (cmd != 1);
	bool cppVar_5446 = cppVar_5443 && cppVar_5445;
	bool cppVar_5448 = (cmdaddr == 65039);
	bool cppVar_5449 = cppVar_5446 && cppVar_5448;
	return cppVar_5449;
}
bool model_sha::decode_16(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4299 = (sha_state == 1);
	bool cppVar_4301 = (cmd == 1);
	bool cppVar_4302 = cppVar_4299 && cppVar_4301;
	bool cppVar_4304 = (cmdaddr == 65027);
	bool cppVar_4305 = cppVar_4302 && cppVar_4304;
	return cppVar_4305;
}
bool model_sha::decode_17(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4307 = (sha_state == 2);
	bool cppVar_4309 = (cmd == 1);
	bool cppVar_4310 = cppVar_4307 && cppVar_4309;
	bool cppVar_4312 = (cmdaddr == 65027);
	bool cppVar_4313 = cppVar_4310 && cppVar_4312;
	return cppVar_4313;
}
bool model_sha::decode_18(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4315 = (sha_state == 3);
	bool cppVar_4317 = (cmd == 1);
	bool cppVar_4318 = cppVar_4315 && cppVar_4317;
	bool cppVar_4320 = (cmdaddr == 65027);
	bool cppVar_4321 = cppVar_4318 && cppVar_4320;
	return cppVar_4321;
}
bool model_sha::decode_19(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4323 = (sha_state == 4);
	bool cppVar_4325 = (cmd == 1);
	bool cppVar_4326 = cppVar_4323 && cppVar_4325;
	bool cppVar_4328 = (cmdaddr == 65027);
	bool cppVar_4329 = cppVar_4326 && cppVar_4328;
	return cppVar_4329;
}
bool model_sha::decode_2(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4187 = (sha_state == 2);
	bool cppVar_4189 = (cmd == 1);
	bool cppVar_4190 = cppVar_4187 && cppVar_4189;
	bool cppVar_4192 = (cmdaddr == 65024);
	bool cppVar_4193 = cppVar_4190 && cppVar_4192;
	return cppVar_4193;
}
bool model_sha::decode_20(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4331 = (sha_state == 0);
	bool cppVar_4333 = (cmd == 1);
	bool cppVar_4334 = cppVar_4331 && cppVar_4333;
	bool cppVar_4336 = (cmdaddr == 65028);
	bool cppVar_4337 = cppVar_4334 && cppVar_4336;
	return cppVar_4337;
}
bool model_sha::decode_21(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4339 = (sha_state == 1);
	bool cppVar_4341 = (cmd == 1);
	bool cppVar_4342 = cppVar_4339 && cppVar_4341;
	bool cppVar_4344 = (cmdaddr == 65028);
	bool cppVar_4345 = cppVar_4342 && cppVar_4344;
	return cppVar_4345;
}
bool model_sha::decode_22(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4347 = (sha_state == 2);
	bool cppVar_4349 = (cmd == 1);
	bool cppVar_4350 = cppVar_4347 && cppVar_4349;
	bool cppVar_4352 = (cmdaddr == 65028);
	bool cppVar_4353 = cppVar_4350 && cppVar_4352;
	return cppVar_4353;
}
bool model_sha::decode_23(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4355 = (sha_state == 3);
	bool cppVar_4357 = (cmd == 1);
	bool cppVar_4358 = cppVar_4355 && cppVar_4357;
	bool cppVar_4360 = (cmdaddr == 65028);
	bool cppVar_4361 = cppVar_4358 && cppVar_4360;
	return cppVar_4361;
}
bool model_sha::decode_24(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4363 = (sha_state == 4);
	bool cppVar_4365 = (cmd == 1);
	bool cppVar_4366 = cppVar_4363 && cppVar_4365;
	bool cppVar_4368 = (cmdaddr == 65028);
	bool cppVar_4369 = cppVar_4366 && cppVar_4368;
	return cppVar_4369;
}
bool model_sha::decode_25(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4371 = (sha_state == 0);
	bool cppVar_4373 = (cmd == 1);
	bool cppVar_4374 = cppVar_4371 && cppVar_4373;
	bool cppVar_4376 = (cmdaddr == 65029);
	bool cppVar_4377 = cppVar_4374 && cppVar_4376;
	return cppVar_4377;
}
bool model_sha::decode_26(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4379 = (sha_state == 1);
	bool cppVar_4381 = (cmd == 1);
	bool cppVar_4382 = cppVar_4379 && cppVar_4381;
	bool cppVar_4384 = (cmdaddr == 65029);
	bool cppVar_4385 = cppVar_4382 && cppVar_4384;
	return cppVar_4385;
}
bool model_sha::decode_27(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4387 = (sha_state == 2);
	bool cppVar_4389 = (cmd == 1);
	bool cppVar_4390 = cppVar_4387 && cppVar_4389;
	bool cppVar_4392 = (cmdaddr == 65029);
	bool cppVar_4393 = cppVar_4390 && cppVar_4392;
	return cppVar_4393;
}
bool model_sha::decode_28(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4395 = (sha_state == 3);
	bool cppVar_4397 = (cmd == 1);
	bool cppVar_4398 = cppVar_4395 && cppVar_4397;
	bool cppVar_4400 = (cmdaddr == 65029);
	bool cppVar_4401 = cppVar_4398 && cppVar_4400;
	return cppVar_4401;
}
bool model_sha::decode_29(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4403 = (sha_state == 4);
	bool cppVar_4405 = (cmd == 1);
	bool cppVar_4406 = cppVar_4403 && cppVar_4405;
	bool cppVar_4408 = (cmdaddr == 65029);
	bool cppVar_4409 = cppVar_4406 && cppVar_4408;
	return cppVar_4409;
}
bool model_sha::decode_3(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4195 = (sha_state == 3);
	bool cppVar_4197 = (cmd == 1);
	bool cppVar_4198 = cppVar_4195 && cppVar_4197;
	bool cppVar_4200 = (cmdaddr == 65024);
	bool cppVar_4201 = cppVar_4198 && cppVar_4200;
	return cppVar_4201;
}
bool model_sha::decode_30(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4411 = (sha_state == 0);
	bool cppVar_4413 = (cmd == 1);
	bool cppVar_4414 = cppVar_4411 && cppVar_4413;
	bool cppVar_4416 = (cmdaddr == 65030);
	bool cppVar_4417 = cppVar_4414 && cppVar_4416;
	return cppVar_4417;
}
bool model_sha::decode_31(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4419 = (sha_state == 1);
	bool cppVar_4421 = (cmd == 1);
	bool cppVar_4422 = cppVar_4419 && cppVar_4421;
	bool cppVar_4424 = (cmdaddr == 65030);
	bool cppVar_4425 = cppVar_4422 && cppVar_4424;
	return cppVar_4425;
}
bool model_sha::decode_32(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4427 = (sha_state == 2);
	bool cppVar_4429 = (cmd == 1);
	bool cppVar_4430 = cppVar_4427 && cppVar_4429;
	bool cppVar_4432 = (cmdaddr == 65030);
	bool cppVar_4433 = cppVar_4430 && cppVar_4432;
	return cppVar_4433;
}
bool model_sha::decode_33(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4435 = (sha_state == 3);
	bool cppVar_4437 = (cmd == 1);
	bool cppVar_4438 = cppVar_4435 && cppVar_4437;
	bool cppVar_4440 = (cmdaddr == 65030);
	bool cppVar_4441 = cppVar_4438 && cppVar_4440;
	return cppVar_4441;
}
bool model_sha::decode_34(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4443 = (sha_state == 4);
	bool cppVar_4445 = (cmd == 1);
	bool cppVar_4446 = cppVar_4443 && cppVar_4445;
	bool cppVar_4448 = (cmdaddr == 65030);
	bool cppVar_4449 = cppVar_4446 && cppVar_4448;
	return cppVar_4449;
}
bool model_sha::decode_35(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4451 = (sha_state == 0);
	bool cppVar_4453 = (cmd == 1);
	bool cppVar_4454 = cppVar_4451 && cppVar_4453;
	bool cppVar_4456 = (cmdaddr == 65031);
	bool cppVar_4457 = cppVar_4454 && cppVar_4456;
	return cppVar_4457;
}
bool model_sha::decode_36(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4459 = (sha_state == 1);
	bool cppVar_4461 = (cmd == 1);
	bool cppVar_4462 = cppVar_4459 && cppVar_4461;
	bool cppVar_4464 = (cmdaddr == 65031);
	bool cppVar_4465 = cppVar_4462 && cppVar_4464;
	return cppVar_4465;
}
bool model_sha::decode_37(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4467 = (sha_state == 2);
	bool cppVar_4469 = (cmd == 1);
	bool cppVar_4470 = cppVar_4467 && cppVar_4469;
	bool cppVar_4472 = (cmdaddr == 65031);
	bool cppVar_4473 = cppVar_4470 && cppVar_4472;
	return cppVar_4473;
}
bool model_sha::decode_38(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4475 = (sha_state == 3);
	bool cppVar_4477 = (cmd == 1);
	bool cppVar_4478 = cppVar_4475 && cppVar_4477;
	bool cppVar_4480 = (cmdaddr == 65031);
	bool cppVar_4481 = cppVar_4478 && cppVar_4480;
	return cppVar_4481;
}
bool model_sha::decode_39(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4483 = (sha_state == 4);
	bool cppVar_4485 = (cmd == 1);
	bool cppVar_4486 = cppVar_4483 && cppVar_4485;
	bool cppVar_4488 = (cmdaddr == 65031);
	bool cppVar_4489 = cppVar_4486 && cppVar_4488;
	return cppVar_4489;
}
bool model_sha::decode_4(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4203 = (sha_state == 4);
	bool cppVar_4205 = (cmd == 1);
	bool cppVar_4206 = cppVar_4203 && cppVar_4205;
	bool cppVar_4208 = (cmdaddr == 65024);
	bool cppVar_4209 = cppVar_4206 && cppVar_4208;
	return cppVar_4209;
}
bool model_sha::decode_40(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4491 = (sha_state == 0);
	bool cppVar_4493 = (cmd == 1);
	bool cppVar_4494 = cppVar_4491 && cppVar_4493;
	bool cppVar_4496 = (cmdaddr == 65032);
	bool cppVar_4497 = cppVar_4494 && cppVar_4496;
	return cppVar_4497;
}
bool model_sha::decode_41(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4499 = (sha_state == 1);
	bool cppVar_4501 = (cmd == 1);
	bool cppVar_4502 = cppVar_4499 && cppVar_4501;
	bool cppVar_4504 = (cmdaddr == 65032);
	bool cppVar_4505 = cppVar_4502 && cppVar_4504;
	return cppVar_4505;
}
bool model_sha::decode_42(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4507 = (sha_state == 2);
	bool cppVar_4509 = (cmd == 1);
	bool cppVar_4510 = cppVar_4507 && cppVar_4509;
	bool cppVar_4512 = (cmdaddr == 65032);
	bool cppVar_4513 = cppVar_4510 && cppVar_4512;
	return cppVar_4513;
}
bool model_sha::decode_43(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4515 = (sha_state == 3);
	bool cppVar_4517 = (cmd == 1);
	bool cppVar_4518 = cppVar_4515 && cppVar_4517;
	bool cppVar_4520 = (cmdaddr == 65032);
	bool cppVar_4521 = cppVar_4518 && cppVar_4520;
	return cppVar_4521;
}
bool model_sha::decode_44(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4523 = (sha_state == 4);
	bool cppVar_4525 = (cmd == 1);
	bool cppVar_4526 = cppVar_4523 && cppVar_4525;
	bool cppVar_4528 = (cmdaddr == 65032);
	bool cppVar_4529 = cppVar_4526 && cppVar_4528;
	return cppVar_4529;
}
bool model_sha::decode_45(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4531 = (sha_state == 0);
	bool cppVar_4533 = (cmd == 1);
	bool cppVar_4534 = cppVar_4531 && cppVar_4533;
	bool cppVar_4536 = (cmdaddr == 65033);
	bool cppVar_4537 = cppVar_4534 && cppVar_4536;
	return cppVar_4537;
}
bool model_sha::decode_46(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4539 = (sha_state == 1);
	bool cppVar_4541 = (cmd == 1);
	bool cppVar_4542 = cppVar_4539 && cppVar_4541;
	bool cppVar_4544 = (cmdaddr == 65033);
	bool cppVar_4545 = cppVar_4542 && cppVar_4544;
	return cppVar_4545;
}
bool model_sha::decode_47(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4547 = (sha_state == 2);
	bool cppVar_4549 = (cmd == 1);
	bool cppVar_4550 = cppVar_4547 && cppVar_4549;
	bool cppVar_4552 = (cmdaddr == 65033);
	bool cppVar_4553 = cppVar_4550 && cppVar_4552;
	return cppVar_4553;
}
bool model_sha::decode_48(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4555 = (sha_state == 3);
	bool cppVar_4557 = (cmd == 1);
	bool cppVar_4558 = cppVar_4555 && cppVar_4557;
	bool cppVar_4560 = (cmdaddr == 65033);
	bool cppVar_4561 = cppVar_4558 && cppVar_4560;
	return cppVar_4561;
}
bool model_sha::decode_49(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4563 = (sha_state == 4);
	bool cppVar_4565 = (cmd == 1);
	bool cppVar_4566 = cppVar_4563 && cppVar_4565;
	bool cppVar_4568 = (cmdaddr == 65033);
	bool cppVar_4569 = cppVar_4566 && cppVar_4568;
	return cppVar_4569;
}
bool model_sha::decode_5(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4211 = (sha_state == 0);
	bool cppVar_4213 = (cmd == 1);
	bool cppVar_4214 = cppVar_4211 && cppVar_4213;
	bool cppVar_4216 = (cmdaddr == 65025);
	bool cppVar_4217 = cppVar_4214 && cppVar_4216;
	return cppVar_4217;
}
bool model_sha::decode_50(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4571 = (sha_state == 0);
	bool cppVar_4573 = (cmd == 1);
	bool cppVar_4574 = cppVar_4571 && cppVar_4573;
	bool cppVar_4576 = (cmdaddr == 65034);
	bool cppVar_4577 = cppVar_4574 && cppVar_4576;
	return cppVar_4577;
}
bool model_sha::decode_51(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4579 = (sha_state == 1);
	bool cppVar_4581 = (cmd == 1);
	bool cppVar_4582 = cppVar_4579 && cppVar_4581;
	bool cppVar_4584 = (cmdaddr == 65034);
	bool cppVar_4585 = cppVar_4582 && cppVar_4584;
	return cppVar_4585;
}
bool model_sha::decode_52(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4587 = (sha_state == 2);
	bool cppVar_4589 = (cmd == 1);
	bool cppVar_4590 = cppVar_4587 && cppVar_4589;
	bool cppVar_4592 = (cmdaddr == 65034);
	bool cppVar_4593 = cppVar_4590 && cppVar_4592;
	return cppVar_4593;
}
bool model_sha::decode_53(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4595 = (sha_state == 3);
	bool cppVar_4597 = (cmd == 1);
	bool cppVar_4598 = cppVar_4595 && cppVar_4597;
	bool cppVar_4600 = (cmdaddr == 65034);
	bool cppVar_4601 = cppVar_4598 && cppVar_4600;
	return cppVar_4601;
}
bool model_sha::decode_54(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4603 = (sha_state == 4);
	bool cppVar_4605 = (cmd == 1);
	bool cppVar_4606 = cppVar_4603 && cppVar_4605;
	bool cppVar_4608 = (cmdaddr == 65034);
	bool cppVar_4609 = cppVar_4606 && cppVar_4608;
	return cppVar_4609;
}
bool model_sha::decode_55(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4611 = (sha_state == 0);
	bool cppVar_4613 = (cmd == 1);
	bool cppVar_4614 = cppVar_4611 && cppVar_4613;
	bool cppVar_4616 = (cmdaddr == 65035);
	bool cppVar_4617 = cppVar_4614 && cppVar_4616;
	return cppVar_4617;
}
bool model_sha::decode_56(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4619 = (sha_state == 1);
	bool cppVar_4621 = (cmd == 1);
	bool cppVar_4622 = cppVar_4619 && cppVar_4621;
	bool cppVar_4624 = (cmdaddr == 65035);
	bool cppVar_4625 = cppVar_4622 && cppVar_4624;
	return cppVar_4625;
}
bool model_sha::decode_57(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4627 = (sha_state == 2);
	bool cppVar_4629 = (cmd == 1);
	bool cppVar_4630 = cppVar_4627 && cppVar_4629;
	bool cppVar_4632 = (cmdaddr == 65035);
	bool cppVar_4633 = cppVar_4630 && cppVar_4632;
	return cppVar_4633;
}
bool model_sha::decode_58(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4635 = (sha_state == 3);
	bool cppVar_4637 = (cmd == 1);
	bool cppVar_4638 = cppVar_4635 && cppVar_4637;
	bool cppVar_4640 = (cmdaddr == 65035);
	bool cppVar_4641 = cppVar_4638 && cppVar_4640;
	return cppVar_4641;
}
bool model_sha::decode_59(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4643 = (sha_state == 4);
	bool cppVar_4645 = (cmd == 1);
	bool cppVar_4646 = cppVar_4643 && cppVar_4645;
	bool cppVar_4648 = (cmdaddr == 65035);
	bool cppVar_4649 = cppVar_4646 && cppVar_4648;
	return cppVar_4649;
}
bool model_sha::decode_6(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4219 = (sha_state == 1);
	bool cppVar_4221 = (cmd == 1);
	bool cppVar_4222 = cppVar_4219 && cppVar_4221;
	bool cppVar_4224 = (cmdaddr == 65025);
	bool cppVar_4225 = cppVar_4222 && cppVar_4224;
	return cppVar_4225;
}
bool model_sha::decode_60(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4651 = (sha_state == 0);
	bool cppVar_4653 = (cmd == 1);
	bool cppVar_4654 = cppVar_4651 && cppVar_4653;
	bool cppVar_4656 = (cmdaddr == 65036);
	bool cppVar_4657 = cppVar_4654 && cppVar_4656;
	return cppVar_4657;
}
bool model_sha::decode_61(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4659 = (sha_state == 1);
	bool cppVar_4661 = (cmd == 1);
	bool cppVar_4662 = cppVar_4659 && cppVar_4661;
	bool cppVar_4664 = (cmdaddr == 65036);
	bool cppVar_4665 = cppVar_4662 && cppVar_4664;
	return cppVar_4665;
}
bool model_sha::decode_62(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4667 = (sha_state == 2);
	bool cppVar_4669 = (cmd == 1);
	bool cppVar_4670 = cppVar_4667 && cppVar_4669;
	bool cppVar_4672 = (cmdaddr == 65036);
	bool cppVar_4673 = cppVar_4670 && cppVar_4672;
	return cppVar_4673;
}
bool model_sha::decode_63(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4675 = (sha_state == 3);
	bool cppVar_4677 = (cmd == 1);
	bool cppVar_4678 = cppVar_4675 && cppVar_4677;
	bool cppVar_4680 = (cmdaddr == 65036);
	bool cppVar_4681 = cppVar_4678 && cppVar_4680;
	return cppVar_4681;
}
bool model_sha::decode_64(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4683 = (sha_state == 4);
	bool cppVar_4685 = (cmd == 1);
	bool cppVar_4686 = cppVar_4683 && cppVar_4685;
	bool cppVar_4688 = (cmdaddr == 65036);
	bool cppVar_4689 = cppVar_4686 && cppVar_4688;
	return cppVar_4689;
}
bool model_sha::decode_65(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4691 = (sha_state == 0);
	bool cppVar_4693 = (cmd == 1);
	bool cppVar_4694 = cppVar_4691 && cppVar_4693;
	bool cppVar_4696 = (cmdaddr == 65037);
	bool cppVar_4697 = cppVar_4694 && cppVar_4696;
	return cppVar_4697;
}
bool model_sha::decode_66(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4699 = (sha_state == 1);
	bool cppVar_4701 = (cmd == 1);
	bool cppVar_4702 = cppVar_4699 && cppVar_4701;
	bool cppVar_4704 = (cmdaddr == 65037);
	bool cppVar_4705 = cppVar_4702 && cppVar_4704;
	return cppVar_4705;
}
bool model_sha::decode_67(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4707 = (sha_state == 2);
	bool cppVar_4709 = (cmd == 1);
	bool cppVar_4710 = cppVar_4707 && cppVar_4709;
	bool cppVar_4712 = (cmdaddr == 65037);
	bool cppVar_4713 = cppVar_4710 && cppVar_4712;
	return cppVar_4713;
}
bool model_sha::decode_68(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4715 = (sha_state == 3);
	bool cppVar_4717 = (cmd == 1);
	bool cppVar_4718 = cppVar_4715 && cppVar_4717;
	bool cppVar_4720 = (cmdaddr == 65037);
	bool cppVar_4721 = cppVar_4718 && cppVar_4720;
	return cppVar_4721;
}
bool model_sha::decode_69(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4723 = (sha_state == 4);
	bool cppVar_4725 = (cmd == 1);
	bool cppVar_4726 = cppVar_4723 && cppVar_4725;
	bool cppVar_4728 = (cmdaddr == 65037);
	bool cppVar_4729 = cppVar_4726 && cppVar_4728;
	return cppVar_4729;
}
bool model_sha::decode_7(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4227 = (sha_state == 2);
	bool cppVar_4229 = (cmd == 1);
	bool cppVar_4230 = cppVar_4227 && cppVar_4229;
	bool cppVar_4232 = (cmdaddr == 65025);
	bool cppVar_4233 = cppVar_4230 && cppVar_4232;
	return cppVar_4233;
}
bool model_sha::decode_70(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4731 = (sha_state == 0);
	bool cppVar_4733 = (cmd == 1);
	bool cppVar_4734 = cppVar_4731 && cppVar_4733;
	bool cppVar_4736 = (cmdaddr == 65038);
	bool cppVar_4737 = cppVar_4734 && cppVar_4736;
	return cppVar_4737;
}
bool model_sha::decode_71(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4739 = (sha_state == 1);
	bool cppVar_4741 = (cmd == 1);
	bool cppVar_4742 = cppVar_4739 && cppVar_4741;
	bool cppVar_4744 = (cmdaddr == 65038);
	bool cppVar_4745 = cppVar_4742 && cppVar_4744;
	return cppVar_4745;
}
bool model_sha::decode_72(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4747 = (sha_state == 2);
	bool cppVar_4749 = (cmd == 1);
	bool cppVar_4750 = cppVar_4747 && cppVar_4749;
	bool cppVar_4752 = (cmdaddr == 65038);
	bool cppVar_4753 = cppVar_4750 && cppVar_4752;
	return cppVar_4753;
}
bool model_sha::decode_73(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4755 = (sha_state == 3);
	bool cppVar_4757 = (cmd == 1);
	bool cppVar_4758 = cppVar_4755 && cppVar_4757;
	bool cppVar_4760 = (cmdaddr == 65038);
	bool cppVar_4761 = cppVar_4758 && cppVar_4760;
	return cppVar_4761;
}
bool model_sha::decode_74(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4763 = (sha_state == 4);
	bool cppVar_4765 = (cmd == 1);
	bool cppVar_4766 = cppVar_4763 && cppVar_4765;
	bool cppVar_4768 = (cmdaddr == 65038);
	bool cppVar_4769 = cppVar_4766 && cppVar_4768;
	return cppVar_4769;
}
bool model_sha::decode_75(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4771 = (sha_state == 0);
	bool cppVar_4773 = (cmd == 1);
	bool cppVar_4774 = cppVar_4771 && cppVar_4773;
	bool cppVar_4776 = (cmdaddr == 65039);
	bool cppVar_4777 = cppVar_4774 && cppVar_4776;
	return cppVar_4777;
}
bool model_sha::decode_76(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4779 = (sha_state == 1);
	bool cppVar_4781 = (cmd == 1);
	bool cppVar_4782 = cppVar_4779 && cppVar_4781;
	bool cppVar_4784 = (cmdaddr == 65039);
	bool cppVar_4785 = cppVar_4782 && cppVar_4784;
	return cppVar_4785;
}
bool model_sha::decode_77(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4787 = (sha_state == 2);
	bool cppVar_4789 = (cmd == 1);
	bool cppVar_4790 = cppVar_4787 && cppVar_4789;
	bool cppVar_4792 = (cmdaddr == 65039);
	bool cppVar_4793 = cppVar_4790 && cppVar_4792;
	return cppVar_4793;
}
bool model_sha::decode_78(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4795 = (sha_state == 3);
	bool cppVar_4797 = (cmd == 1);
	bool cppVar_4798 = cppVar_4795 && cppVar_4797;
	bool cppVar_4800 = (cmdaddr == 65039);
	bool cppVar_4801 = cppVar_4798 && cppVar_4800;
	return cppVar_4801;
}
bool model_sha::decode_79(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4803 = (sha_state == 4);
	bool cppVar_4805 = (cmd == 1);
	bool cppVar_4806 = cppVar_4803 && cppVar_4805;
	bool cppVar_4808 = (cmdaddr == 65039);
	bool cppVar_4809 = cppVar_4806 && cppVar_4808;
	return cppVar_4809;
}
bool model_sha::decode_8(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4235 = (sha_state == 3);
	bool cppVar_4237 = (cmd == 1);
	bool cppVar_4238 = cppVar_4235 && cppVar_4237;
	bool cppVar_4240 = (cmdaddr == 65025);
	bool cppVar_4241 = cppVar_4238 && cppVar_4240;
	return cppVar_4241;
}
bool model_sha::decode_80(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4811 = (sha_state == 0);
	bool cppVar_4813 = (cmd == 2);
	bool cppVar_4814 = cppVar_4811 && cppVar_4813;
	bool cppVar_4816 = (cmdaddr == 65024);
	bool cppVar_4817 = cppVar_4814 && cppVar_4816;
	return cppVar_4817;
}
bool model_sha::decode_81(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4819 = (sha_state == 0);
	bool cppVar_4821 = (cmd == 2);
	bool cppVar_4822 = cppVar_4819 && cppVar_4821;
	bool cppVar_4824 = (cmdaddr == 65025);
	bool cppVar_4825 = cppVar_4822 && cppVar_4824;
	return cppVar_4825;
}
bool model_sha::decode_82(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4827 = (sha_state == 0);
	bool cppVar_4829 = (cmd == 2);
	bool cppVar_4830 = cppVar_4827 && cppVar_4829;
	bool cppVar_4832 = (cmdaddr == 65026);
	bool cppVar_4833 = cppVar_4830 && cppVar_4832;
	return cppVar_4833;
}
bool model_sha::decode_83(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4835 = (sha_state == 0);
	bool cppVar_4837 = (cmd == 2);
	bool cppVar_4838 = cppVar_4835 && cppVar_4837;
	bool cppVar_4840 = (cmdaddr == 65027);
	bool cppVar_4841 = cppVar_4838 && cppVar_4840;
	return cppVar_4841;
}
bool model_sha::decode_84(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4843 = (sha_state == 0);
	bool cppVar_4845 = (cmd == 2);
	bool cppVar_4846 = cppVar_4843 && cppVar_4845;
	bool cppVar_4848 = (cmdaddr == 65028);
	bool cppVar_4849 = cppVar_4846 && cppVar_4848;
	return cppVar_4849;
}
bool model_sha::decode_85(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4851 = (sha_state == 0);
	bool cppVar_4853 = (cmd == 2);
	bool cppVar_4854 = cppVar_4851 && cppVar_4853;
	bool cppVar_4856 = (cmdaddr == 65029);
	bool cppVar_4857 = cppVar_4854 && cppVar_4856;
	return cppVar_4857;
}
bool model_sha::decode_86(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4859 = (sha_state == 0);
	bool cppVar_4861 = (cmd == 2);
	bool cppVar_4862 = cppVar_4859 && cppVar_4861;
	bool cppVar_4864 = (cmdaddr == 65030);
	bool cppVar_4865 = cppVar_4862 && cppVar_4864;
	return cppVar_4865;
}
bool model_sha::decode_87(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4867 = (sha_state == 0);
	bool cppVar_4869 = (cmd == 2);
	bool cppVar_4870 = cppVar_4867 && cppVar_4869;
	bool cppVar_4872 = (cmdaddr == 65031);
	bool cppVar_4873 = cppVar_4870 && cppVar_4872;
	return cppVar_4873;
}
bool model_sha::decode_88(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4875 = (sha_state == 0);
	bool cppVar_4877 = (cmd == 2);
	bool cppVar_4878 = cppVar_4875 && cppVar_4877;
	bool cppVar_4880 = (cmdaddr == 65032);
	bool cppVar_4881 = cppVar_4878 && cppVar_4880;
	return cppVar_4881;
}
bool model_sha::decode_89(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4883 = (sha_state == 0);
	bool cppVar_4885 = (cmd == 2);
	bool cppVar_4886 = cppVar_4883 && cppVar_4885;
	bool cppVar_4888 = (cmdaddr == 65033);
	bool cppVar_4889 = cppVar_4886 && cppVar_4888;
	return cppVar_4889;
}
bool model_sha::decode_9(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4243 = (sha_state == 4);
	bool cppVar_4245 = (cmd == 1);
	bool cppVar_4246 = cppVar_4243 && cppVar_4245;
	bool cppVar_4248 = (cmdaddr == 65025);
	bool cppVar_4249 = cppVar_4246 && cppVar_4248;
	return cppVar_4249;
}
bool model_sha::decode_90(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4891 = (sha_state == 0);
	bool cppVar_4893 = (cmd == 2);
	bool cppVar_4894 = cppVar_4891 && cppVar_4893;
	bool cppVar_4896 = (cmdaddr == 65034);
	bool cppVar_4897 = cppVar_4894 && cppVar_4896;
	return cppVar_4897;
}
bool model_sha::decode_91(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4899 = (sha_state == 0);
	bool cppVar_4901 = (cmd == 2);
	bool cppVar_4902 = cppVar_4899 && cppVar_4901;
	bool cppVar_4904 = (cmdaddr == 65035);
	bool cppVar_4905 = cppVar_4902 && cppVar_4904;
	return cppVar_4905;
}
bool model_sha::decode_92(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4907 = (sha_state == 0);
	bool cppVar_4909 = (cmd == 2);
	bool cppVar_4910 = cppVar_4907 && cppVar_4909;
	bool cppVar_4912 = (cmdaddr == 65036);
	bool cppVar_4913 = cppVar_4910 && cppVar_4912;
	return cppVar_4913;
}
bool model_sha::decode_93(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4915 = (sha_state == 0);
	bool cppVar_4917 = (cmd == 2);
	bool cppVar_4918 = cppVar_4915 && cppVar_4917;
	bool cppVar_4920 = (cmdaddr == 65037);
	bool cppVar_4921 = cppVar_4918 && cppVar_4920;
	return cppVar_4921;
}
bool model_sha::decode_94(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4923 = (sha_state == 0);
	bool cppVar_4925 = (cmd == 2);
	bool cppVar_4926 = cppVar_4923 && cppVar_4925;
	bool cppVar_4928 = (cmdaddr == 65038);
	bool cppVar_4929 = cppVar_4926 && cppVar_4928;
	return cppVar_4929;
}
bool model_sha::decode_95(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4931 = (sha_state == 0);
	bool cppVar_4933 = (cmd == 2);
	bool cppVar_4934 = cppVar_4931 && cppVar_4933;
	bool cppVar_4936 = (cmdaddr == 65039);
	bool cppVar_4937 = cppVar_4934 && cppVar_4936;
	return cppVar_4937;
}
bool model_sha::decode_96(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4939 = (sha_state == 1);
	bool cppVar_4941 = (cmd != 1);
	bool cppVar_4942 = cppVar_4939 && cppVar_4941;
	bool cppVar_4944 = (cmdaddr == 65024);
	bool cppVar_4945 = cppVar_4942 && cppVar_4944;
	return cppVar_4945;
}
bool model_sha::decode_97(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4947 = (sha_state == 2);
	bool cppVar_4949 = (cmd != 1);
	bool cppVar_4950 = cppVar_4947 && cppVar_4949;
	bool cppVar_4952 = (cmdaddr == 65024);
	bool cppVar_4953 = cppVar_4950 && cppVar_4952;
	return cppVar_4953;
}
bool model_sha::decode_98(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4955 = (sha_state == 3);
	bool cppVar_4957 = (cmd != 1);
	bool cppVar_4958 = cppVar_4955 && cppVar_4957;
	bool cppVar_4960 = (cmdaddr == 65024);
	bool cppVar_4961 = cppVar_4958 && cppVar_4960;
	return cppVar_4961;
}
bool model_sha::decode_99(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4963 = (sha_state == 4);
	bool cppVar_4965 = (cmd != 1);
	bool cppVar_4966 = cppVar_4963 && cppVar_4965;
	bool cppVar_4968 = (cmdaddr == 65024);
	bool cppVar_4969 = cppVar_4966 && cppVar_4968;
	return cppVar_4969;
}
BIT_VEC model_sha::fetch(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_4162 = (cmdaddr << 8) | cmddata;
	cppVar_4162 = (cppVar_4162 & cppMask_un_24_);
	BIT_VEC cppVar_4163 = (cmd << 24) | cppVar_4162;
	cppVar_4163 = (cppVar_4163 & cppMask_un_26_);
	BIT_VEC cppVar_4164 = (sha_state << 26) | cppVar_4163;
	cppVar_4164 = (cppVar_4164 & cppMask_un_29_);
	return cppVar_4164;
}
bool model_sha::fetchValid(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_4166 = (cmd == 1);
	bool cppVar_4168 = (cmd == 2);
	bool cppVar_4169 = cppVar_4166 || cppVar_4168;
	return cppVar_4169;
}
void model_sha::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_1463 = cppUpdateFun_dataout(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_1767 = cppUpdateFun_sha_bytes_read(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_2057 = cppUpdateFun_sha_hs_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_2080 = cppUpdateFun_sha_len(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_2372 = cppUpdateFun_sha_rd_data(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_2395 = cppUpdateFun_sha_rdaddr(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_3847 = cppUpdateFun_sha_state(cmd, cmdaddr, cmddata);
	BIT_VEC cppVar_3870 = cppUpdateFun_sha_wraddr(cmd, cmdaddr, cmddata);
	bool cppVar_3872 = (sha_state == 4);
	bool cppVar_3874 = (cmd != 1);
	bool cppVar_3875 = cppVar_3872 && cppVar_3874;
	bool cppVar_3877 = (cmdaddr == 65039);
	bool cppVar_3878 = cppVar_3875 && cppVar_3877;
	bool cppVar_3880 = (sha_state == 4);
	bool cppVar_3882 = (cmd != 1);
	bool cppVar_3883 = cppVar_3880 && cppVar_3882;
	bool cppVar_3885 = (cmdaddr == 65038);
	bool cppVar_3886 = cppVar_3883 && cppVar_3885;
	bool cppVar_3888 = (sha_state == 4);
	bool cppVar_3890 = (cmd != 1);
	bool cppVar_3891 = cppVar_3888 && cppVar_3890;
	bool cppVar_3893 = (cmdaddr == 65037);
	bool cppVar_3894 = cppVar_3891 && cppVar_3893;
	bool cppVar_3896 = (sha_state == 4);
	bool cppVar_3898 = (cmd != 1);
	bool cppVar_3899 = cppVar_3896 && cppVar_3898;
	bool cppVar_3901 = (cmdaddr == 65036);
	bool cppVar_3902 = cppVar_3899 && cppVar_3901;
	bool cppVar_3904 = (sha_state == 4);
	bool cppVar_3906 = (cmd != 1);
	bool cppVar_3907 = cppVar_3904 && cppVar_3906;
	bool cppVar_3909 = (cmdaddr == 65035);
	bool cppVar_3910 = cppVar_3907 && cppVar_3909;
	bool cppVar_3912 = (sha_state == 4);
	bool cppVar_3914 = (cmd != 1);
	bool cppVar_3915 = cppVar_3912 && cppVar_3914;
	bool cppVar_3917 = (cmdaddr == 65034);
	bool cppVar_3918 = cppVar_3915 && cppVar_3917;
	bool cppVar_3920 = (sha_state == 4);
	bool cppVar_3922 = (cmd != 1);
	bool cppVar_3923 = cppVar_3920 && cppVar_3922;
	bool cppVar_3925 = (cmdaddr == 65033);
	bool cppVar_3926 = cppVar_3923 && cppVar_3925;
	bool cppVar_3928 = (sha_state == 4);
	bool cppVar_3930 = (cmd != 1);
	bool cppVar_3931 = cppVar_3928 && cppVar_3930;
	bool cppVar_3933 = (cmdaddr == 65032);
	bool cppVar_3934 = cppVar_3931 && cppVar_3933;
	bool cppVar_3936 = (sha_state == 4);
	bool cppVar_3938 = (cmd != 1);
	bool cppVar_3939 = cppVar_3936 && cppVar_3938;
	bool cppVar_3941 = (cmdaddr == 65031);
	bool cppVar_3942 = cppVar_3939 && cppVar_3941;
	bool cppVar_3944 = (sha_state == 4);
	bool cppVar_3946 = (cmd != 1);
	bool cppVar_3947 = cppVar_3944 && cppVar_3946;
	bool cppVar_3949 = (cmdaddr == 65030);
	bool cppVar_3950 = cppVar_3947 && cppVar_3949;
	bool cppVar_3952 = (sha_state == 4);
	bool cppVar_3954 = (cmd != 1);
	bool cppVar_3955 = cppVar_3952 && cppVar_3954;
	bool cppVar_3957 = (cmdaddr == 65029);
	bool cppVar_3958 = cppVar_3955 && cppVar_3957;
	bool cppVar_3960 = (sha_state == 4);
	bool cppVar_3962 = (cmd != 1);
	bool cppVar_3963 = cppVar_3960 && cppVar_3962;
	bool cppVar_3965 = (cmdaddr == 65028);
	bool cppVar_3966 = cppVar_3963 && cppVar_3965;
	bool cppVar_3968 = (sha_state == 4);
	bool cppVar_3970 = (cmd != 1);
	bool cppVar_3971 = cppVar_3968 && cppVar_3970;
	bool cppVar_3973 = (cmdaddr == 65027);
	bool cppVar_3974 = cppVar_3971 && cppVar_3973;
	bool cppVar_3976 = (sha_state == 4);
	bool cppVar_3978 = (cmd != 1);
	bool cppVar_3979 = cppVar_3976 && cppVar_3978;
	bool cppVar_3981 = (cmdaddr == 65026);
	bool cppVar_3982 = cppVar_3979 && cppVar_3981;
	bool cppVar_3984 = (sha_state == 4);
	bool cppVar_3986 = (cmd != 1);
	bool cppVar_3987 = cppVar_3984 && cppVar_3986;
	bool cppVar_3989 = (cmdaddr == 65025);
	bool cppVar_3990 = cppVar_3987 && cppVar_3989;
	bool cppVar_3992 = (sha_state == 4);
	bool cppVar_3994 = (cmd != 1);
	bool cppVar_3995 = cppVar_3992 && cppVar_3994;
	bool cppVar_3997 = (cmdaddr == 65024);
	bool cppVar_3998 = cppVar_3995 && cppVar_3997;
	bool cppVar_4000 = (sha_state == 4);
	bool cppVar_4002 = (cmd == 1);
	bool cppVar_4003 = cppVar_4000 && cppVar_4002;
	bool cppVar_4005 = (cmdaddr == 65039);
	bool cppVar_4006 = cppVar_4003 && cppVar_4005;
	bool cppVar_4008 = (sha_state == 4);
	bool cppVar_4010 = (cmd == 1);
	bool cppVar_4011 = cppVar_4008 && cppVar_4010;
	bool cppVar_4013 = (cmdaddr == 65038);
	bool cppVar_4014 = cppVar_4011 && cppVar_4013;
	bool cppVar_4016 = (sha_state == 4);
	bool cppVar_4018 = (cmd == 1);
	bool cppVar_4019 = cppVar_4016 && cppVar_4018;
	bool cppVar_4021 = (cmdaddr == 65037);
	bool cppVar_4022 = cppVar_4019 && cppVar_4021;
	bool cppVar_4024 = (sha_state == 4);
	bool cppVar_4026 = (cmd == 1);
	bool cppVar_4027 = cppVar_4024 && cppVar_4026;
	bool cppVar_4029 = (cmdaddr == 65036);
	bool cppVar_4030 = cppVar_4027 && cppVar_4029;
	bool cppVar_4032 = (sha_state == 4);
	bool cppVar_4034 = (cmd == 1);
	bool cppVar_4035 = cppVar_4032 && cppVar_4034;
	bool cppVar_4037 = (cmdaddr == 65035);
	bool cppVar_4038 = cppVar_4035 && cppVar_4037;
	bool cppVar_4040 = (sha_state == 4);
	bool cppVar_4042 = (cmd == 1);
	bool cppVar_4043 = cppVar_4040 && cppVar_4042;
	bool cppVar_4045 = (cmdaddr == 65034);
	bool cppVar_4046 = cppVar_4043 && cppVar_4045;
	bool cppVar_4048 = (sha_state == 4);
	bool cppVar_4050 = (cmd == 1);
	bool cppVar_4051 = cppVar_4048 && cppVar_4050;
	bool cppVar_4053 = (cmdaddr == 65033);
	bool cppVar_4054 = cppVar_4051 && cppVar_4053;
	bool cppVar_4056 = (sha_state == 4);
	bool cppVar_4058 = (cmd == 1);
	bool cppVar_4059 = cppVar_4056 && cppVar_4058;
	bool cppVar_4061 = (cmdaddr == 65032);
	bool cppVar_4062 = cppVar_4059 && cppVar_4061;
	bool cppVar_4064 = (sha_state == 4);
	bool cppVar_4066 = (cmd == 1);
	bool cppVar_4067 = cppVar_4064 && cppVar_4066;
	bool cppVar_4069 = (cmdaddr == 65031);
	bool cppVar_4070 = cppVar_4067 && cppVar_4069;
	bool cppVar_4072 = (sha_state == 4);
	bool cppVar_4074 = (cmd == 1);
	bool cppVar_4075 = cppVar_4072 && cppVar_4074;
	bool cppVar_4077 = (cmdaddr == 65030);
	bool cppVar_4078 = cppVar_4075 && cppVar_4077;
	bool cppVar_4080 = (sha_state == 4);
	bool cppVar_4082 = (cmd == 1);
	bool cppVar_4083 = cppVar_4080 && cppVar_4082;
	bool cppVar_4085 = (cmdaddr == 65029);
	bool cppVar_4086 = cppVar_4083 && cppVar_4085;
	bool cppVar_4088 = (sha_state == 4);
	bool cppVar_4090 = (cmd == 1);
	bool cppVar_4091 = cppVar_4088 && cppVar_4090;
	bool cppVar_4093 = (cmdaddr == 65028);
	bool cppVar_4094 = cppVar_4091 && cppVar_4093;
	bool cppVar_4096 = (sha_state == 4);
	bool cppVar_4098 = (cmd == 1);
	bool cppVar_4099 = cppVar_4096 && cppVar_4098;
	bool cppVar_4101 = (cmdaddr == 65027);
	bool cppVar_4102 = cppVar_4099 && cppVar_4101;
	bool cppVar_4104 = (sha_state == 4);
	bool cppVar_4106 = (cmd == 1);
	bool cppVar_4107 = cppVar_4104 && cppVar_4106;
	bool cppVar_4109 = (cmdaddr == 65026);
	bool cppVar_4110 = cppVar_4107 && cppVar_4109;
	bool cppVar_4112 = (sha_state == 4);
	bool cppVar_4114 = (cmd == 1);
	bool cppVar_4115 = cppVar_4112 && cppVar_4114;
	bool cppVar_4117 = (cmdaddr == 65025);
	bool cppVar_4118 = cppVar_4115 && cppVar_4117;
	bool cppVar_4120 = (sha_state == 4);
	bool cppVar_4122 = (cmd == 1);
	bool cppVar_4123 = cppVar_4120 && cppVar_4122;
	bool cppVar_4125 = (cmdaddr == 65024);
	bool cppVar_4126 = cppVar_4123 && cppVar_4125;
	bool cppVar_4127 = cppVar_4118 || cppVar_4126;
	bool cppVar_4128 = cppVar_4110 || cppVar_4127;
	bool cppVar_4129 = cppVar_4102 || cppVar_4128;
	bool cppVar_4130 = cppVar_4094 || cppVar_4129;
	bool cppVar_4131 = cppVar_4086 || cppVar_4130;
	bool cppVar_4132 = cppVar_4078 || cppVar_4131;
	bool cppVar_4133 = cppVar_4070 || cppVar_4132;
	bool cppVar_4134 = cppVar_4062 || cppVar_4133;
	bool cppVar_4135 = cppVar_4054 || cppVar_4134;
	bool cppVar_4136 = cppVar_4046 || cppVar_4135;
	bool cppVar_4137 = cppVar_4038 || cppVar_4136;
	bool cppVar_4138 = cppVar_4030 || cppVar_4137;
	bool cppVar_4139 = cppVar_4022 || cppVar_4138;
	bool cppVar_4140 = cppVar_4014 || cppVar_4139;
	bool cppVar_4141 = cppVar_4006 || cppVar_4140;
	bool cppVar_4142 = cppVar_3998 || cppVar_4141;
	bool cppVar_4143 = cppVar_3990 || cppVar_4142;
	bool cppVar_4144 = cppVar_3982 || cppVar_4143;
	bool cppVar_4145 = cppVar_3974 || cppVar_4144;
	bool cppVar_4146 = cppVar_3966 || cppVar_4145;
	bool cppVar_4147 = cppVar_3958 || cppVar_4146;
	bool cppVar_4148 = cppVar_3950 || cppVar_4147;
	bool cppVar_4149 = cppVar_3942 || cppVar_4148;
	bool cppVar_4150 = cppVar_3934 || cppVar_4149;
	bool cppVar_4151 = cppVar_3926 || cppVar_4150;
	bool cppVar_4152 = cppVar_3918 || cppVar_4151;
	bool cppVar_4153 = cppVar_3910 || cppVar_4152;
	bool cppVar_4154 = cppVar_3902 || cppVar_4153;
	bool cppVar_4155 = cppVar_3894 || cppVar_4154;
	bool cppVar_4156 = cppVar_3886 || cppVar_4155;
	bool cppVar_4157 = cppVar_3878 || cppVar_4156;
	BIT_VEC cppVar_4160;
	type_mem cppVar_4158 = XRAM;
	for (int cppVar_4159 = 0; cppVar_4159 < 20; cppVar_4159++) {
		cppVar_4160 = sha_hs_data >> ((20 - 1 - cppVar_4159) * 8);
		cppVar_4158.wr(sha_wraddr + cppVar_4159, cppVar_4160);
	}
	type_mem& cppVar_4161 = (cppVar_4157) ? cppVar_4158 : XRAM;
	dataout = cppVar_1463;
	sha_bytes_read = cppVar_1767;
	sha_hs_data = cppVar_2057;
	sha_len = cppVar_2080;
	sha_rd_data = cppVar_2372;
	sha_rdaddr = cppVar_2395;
	sha_state = cppVar_3847;
	sha_wraddr = cppVar_3870;
	XRAM = cppVar_4161;
	return;
}

/****************************************************/
/****************************************************/
#endif
/****************************************************/
