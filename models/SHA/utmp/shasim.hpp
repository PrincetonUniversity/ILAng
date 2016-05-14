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

extern BIT_VEC sha(BIT_VEC cppVar_11);

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
bool model_sha::decode_0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1000 = (sha_state == 0);
	bool cppVar_1002 = (cmd == 1);
	bool cppVar_1003 = cppVar_1000 && cppVar_1002;
	bool cppVar_1005 = (cmdaddr == 65024);
	bool cppVar_1006 = cppVar_1003 && cppVar_1005;
	return cppVar_1006;
}
bool model_sha::decode_1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1008 = (sha_state == 1);
	bool cppVar_1010 = (cmd == 1);
	bool cppVar_1011 = cppVar_1008 && cppVar_1010;
	bool cppVar_1013 = (cmdaddr == 65024);
	bool cppVar_1014 = cppVar_1011 && cppVar_1013;
	return cppVar_1014;
}
bool model_sha::decode_10(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1080 = (sha_state == 0);
	bool cppVar_1082 = (cmd == 1);
	bool cppVar_1083 = cppVar_1080 && cppVar_1082;
	bool cppVar_1085 = (cmdaddr == 65026);
	bool cppVar_1086 = cppVar_1083 && cppVar_1085;
	return cppVar_1086;
}
bool model_sha::decode_11(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1088 = (sha_state == 1);
	bool cppVar_1090 = (cmd == 1);
	bool cppVar_1091 = cppVar_1088 && cppVar_1090;
	bool cppVar_1093 = (cmdaddr == 65026);
	bool cppVar_1094 = cppVar_1091 && cppVar_1093;
	return cppVar_1094;
}
bool model_sha::decode_12(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1096 = (sha_state == 2);
	bool cppVar_1098 = (cmd == 1);
	bool cppVar_1099 = cppVar_1096 && cppVar_1098;
	bool cppVar_1101 = (cmdaddr == 65026);
	bool cppVar_1102 = cppVar_1099 && cppVar_1101;
	return cppVar_1102;
}
bool model_sha::decode_13(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1104 = (sha_state == 3);
	bool cppVar_1106 = (cmd == 1);
	bool cppVar_1107 = cppVar_1104 && cppVar_1106;
	bool cppVar_1109 = (cmdaddr == 65026);
	bool cppVar_1110 = cppVar_1107 && cppVar_1109;
	return cppVar_1110;
}
bool model_sha::decode_14(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1112 = (sha_state == 4);
	bool cppVar_1114 = (cmd == 1);
	bool cppVar_1115 = cppVar_1112 && cppVar_1114;
	bool cppVar_1117 = (cmdaddr == 65026);
	bool cppVar_1118 = cppVar_1115 && cppVar_1117;
	return cppVar_1118;
}
bool model_sha::decode_15(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1120 = (sha_state == 0);
	bool cppVar_1122 = (cmd == 1);
	bool cppVar_1123 = cppVar_1120 && cppVar_1122;
	bool cppVar_1125 = (cmdaddr == 65027);
	bool cppVar_1126 = cppVar_1123 && cppVar_1125;
	return cppVar_1126;
}
bool model_sha::decode_16(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1128 = (sha_state == 1);
	bool cppVar_1130 = (cmd == 1);
	bool cppVar_1131 = cppVar_1128 && cppVar_1130;
	bool cppVar_1133 = (cmdaddr == 65027);
	bool cppVar_1134 = cppVar_1131 && cppVar_1133;
	return cppVar_1134;
}
bool model_sha::decode_17(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1136 = (sha_state == 2);
	bool cppVar_1138 = (cmd == 1);
	bool cppVar_1139 = cppVar_1136 && cppVar_1138;
	bool cppVar_1141 = (cmdaddr == 65027);
	bool cppVar_1142 = cppVar_1139 && cppVar_1141;
	return cppVar_1142;
}
bool model_sha::decode_18(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1144 = (sha_state == 3);
	bool cppVar_1146 = (cmd == 1);
	bool cppVar_1147 = cppVar_1144 && cppVar_1146;
	bool cppVar_1149 = (cmdaddr == 65027);
	bool cppVar_1150 = cppVar_1147 && cppVar_1149;
	return cppVar_1150;
}
bool model_sha::decode_19(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1152 = (sha_state == 4);
	bool cppVar_1154 = (cmd == 1);
	bool cppVar_1155 = cppVar_1152 && cppVar_1154;
	bool cppVar_1157 = (cmdaddr == 65027);
	bool cppVar_1158 = cppVar_1155 && cppVar_1157;
	return cppVar_1158;
}
bool model_sha::decode_2(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1016 = (sha_state == 2);
	bool cppVar_1018 = (cmd == 1);
	bool cppVar_1019 = cppVar_1016 && cppVar_1018;
	bool cppVar_1021 = (cmdaddr == 65024);
	bool cppVar_1022 = cppVar_1019 && cppVar_1021;
	return cppVar_1022;
}
bool model_sha::decode_20(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1160 = (sha_state == 0);
	bool cppVar_1162 = (cmd == 1);
	bool cppVar_1163 = cppVar_1160 && cppVar_1162;
	bool cppVar_1165 = (cmdaddr == 65028);
	bool cppVar_1166 = cppVar_1163 && cppVar_1165;
	return cppVar_1166;
}
bool model_sha::decode_21(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1168 = (sha_state == 1);
	bool cppVar_1170 = (cmd == 1);
	bool cppVar_1171 = cppVar_1168 && cppVar_1170;
	bool cppVar_1173 = (cmdaddr == 65028);
	bool cppVar_1174 = cppVar_1171 && cppVar_1173;
	return cppVar_1174;
}
bool model_sha::decode_22(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1176 = (sha_state == 2);
	bool cppVar_1178 = (cmd == 1);
	bool cppVar_1179 = cppVar_1176 && cppVar_1178;
	bool cppVar_1181 = (cmdaddr == 65028);
	bool cppVar_1182 = cppVar_1179 && cppVar_1181;
	return cppVar_1182;
}
bool model_sha::decode_23(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1184 = (sha_state == 3);
	bool cppVar_1186 = (cmd == 1);
	bool cppVar_1187 = cppVar_1184 && cppVar_1186;
	bool cppVar_1189 = (cmdaddr == 65028);
	bool cppVar_1190 = cppVar_1187 && cppVar_1189;
	return cppVar_1190;
}
bool model_sha::decode_24(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1192 = (sha_state == 4);
	bool cppVar_1194 = (cmd == 1);
	bool cppVar_1195 = cppVar_1192 && cppVar_1194;
	bool cppVar_1197 = (cmdaddr == 65028);
	bool cppVar_1198 = cppVar_1195 && cppVar_1197;
	return cppVar_1198;
}
bool model_sha::decode_25(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1200 = (sha_state == 0);
	bool cppVar_1202 = (cmd == 1);
	bool cppVar_1203 = cppVar_1200 && cppVar_1202;
	bool cppVar_1205 = (cmdaddr == 65029);
	bool cppVar_1206 = cppVar_1203 && cppVar_1205;
	return cppVar_1206;
}
bool model_sha::decode_26(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1208 = (sha_state == 1);
	bool cppVar_1210 = (cmd == 1);
	bool cppVar_1211 = cppVar_1208 && cppVar_1210;
	bool cppVar_1213 = (cmdaddr == 65029);
	bool cppVar_1214 = cppVar_1211 && cppVar_1213;
	return cppVar_1214;
}
bool model_sha::decode_27(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1216 = (sha_state == 2);
	bool cppVar_1218 = (cmd == 1);
	bool cppVar_1219 = cppVar_1216 && cppVar_1218;
	bool cppVar_1221 = (cmdaddr == 65029);
	bool cppVar_1222 = cppVar_1219 && cppVar_1221;
	return cppVar_1222;
}
bool model_sha::decode_28(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1224 = (sha_state == 3);
	bool cppVar_1226 = (cmd == 1);
	bool cppVar_1227 = cppVar_1224 && cppVar_1226;
	bool cppVar_1229 = (cmdaddr == 65029);
	bool cppVar_1230 = cppVar_1227 && cppVar_1229;
	return cppVar_1230;
}
bool model_sha::decode_29(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1232 = (sha_state == 4);
	bool cppVar_1234 = (cmd == 1);
	bool cppVar_1235 = cppVar_1232 && cppVar_1234;
	bool cppVar_1237 = (cmdaddr == 65029);
	bool cppVar_1238 = cppVar_1235 && cppVar_1237;
	return cppVar_1238;
}
bool model_sha::decode_3(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1024 = (sha_state == 3);
	bool cppVar_1026 = (cmd == 1);
	bool cppVar_1027 = cppVar_1024 && cppVar_1026;
	bool cppVar_1029 = (cmdaddr == 65024);
	bool cppVar_1030 = cppVar_1027 && cppVar_1029;
	return cppVar_1030;
}
bool model_sha::decode_30(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1240 = (sha_state == 0);
	bool cppVar_1242 = (cmd == 1);
	bool cppVar_1243 = cppVar_1240 && cppVar_1242;
	bool cppVar_1245 = (cmdaddr == 65030);
	bool cppVar_1246 = cppVar_1243 && cppVar_1245;
	return cppVar_1246;
}
bool model_sha::decode_31(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1248 = (sha_state == 1);
	bool cppVar_1250 = (cmd == 1);
	bool cppVar_1251 = cppVar_1248 && cppVar_1250;
	bool cppVar_1253 = (cmdaddr == 65030);
	bool cppVar_1254 = cppVar_1251 && cppVar_1253;
	return cppVar_1254;
}
bool model_sha::decode_32(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1256 = (sha_state == 2);
	bool cppVar_1258 = (cmd == 1);
	bool cppVar_1259 = cppVar_1256 && cppVar_1258;
	bool cppVar_1261 = (cmdaddr == 65030);
	bool cppVar_1262 = cppVar_1259 && cppVar_1261;
	return cppVar_1262;
}
bool model_sha::decode_33(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1264 = (sha_state == 3);
	bool cppVar_1266 = (cmd == 1);
	bool cppVar_1267 = cppVar_1264 && cppVar_1266;
	bool cppVar_1269 = (cmdaddr == 65030);
	bool cppVar_1270 = cppVar_1267 && cppVar_1269;
	return cppVar_1270;
}
bool model_sha::decode_34(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1272 = (sha_state == 4);
	bool cppVar_1274 = (cmd == 1);
	bool cppVar_1275 = cppVar_1272 && cppVar_1274;
	bool cppVar_1277 = (cmdaddr == 65030);
	bool cppVar_1278 = cppVar_1275 && cppVar_1277;
	return cppVar_1278;
}
bool model_sha::decode_35(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1280 = (sha_state == 0);
	bool cppVar_1282 = (cmd == 1);
	bool cppVar_1283 = cppVar_1280 && cppVar_1282;
	bool cppVar_1285 = (cmdaddr == 65031);
	bool cppVar_1286 = cppVar_1283 && cppVar_1285;
	return cppVar_1286;
}
bool model_sha::decode_36(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1288 = (sha_state == 1);
	bool cppVar_1290 = (cmd == 1);
	bool cppVar_1291 = cppVar_1288 && cppVar_1290;
	bool cppVar_1293 = (cmdaddr == 65031);
	bool cppVar_1294 = cppVar_1291 && cppVar_1293;
	return cppVar_1294;
}
bool model_sha::decode_37(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1296 = (sha_state == 2);
	bool cppVar_1298 = (cmd == 1);
	bool cppVar_1299 = cppVar_1296 && cppVar_1298;
	bool cppVar_1301 = (cmdaddr == 65031);
	bool cppVar_1302 = cppVar_1299 && cppVar_1301;
	return cppVar_1302;
}
bool model_sha::decode_38(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1304 = (sha_state == 3);
	bool cppVar_1306 = (cmd == 1);
	bool cppVar_1307 = cppVar_1304 && cppVar_1306;
	bool cppVar_1309 = (cmdaddr == 65031);
	bool cppVar_1310 = cppVar_1307 && cppVar_1309;
	return cppVar_1310;
}
bool model_sha::decode_39(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1312 = (sha_state == 4);
	bool cppVar_1314 = (cmd == 1);
	bool cppVar_1315 = cppVar_1312 && cppVar_1314;
	bool cppVar_1317 = (cmdaddr == 65031);
	bool cppVar_1318 = cppVar_1315 && cppVar_1317;
	return cppVar_1318;
}
bool model_sha::decode_4(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1032 = (sha_state == 4);
	bool cppVar_1034 = (cmd == 1);
	bool cppVar_1035 = cppVar_1032 && cppVar_1034;
	bool cppVar_1037 = (cmdaddr == 65024);
	bool cppVar_1038 = cppVar_1035 && cppVar_1037;
	return cppVar_1038;
}
bool model_sha::decode_40(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1320 = (sha_state == 0);
	bool cppVar_1322 = (cmd == 1);
	bool cppVar_1323 = cppVar_1320 && cppVar_1322;
	bool cppVar_1325 = (cmdaddr == 65032);
	bool cppVar_1326 = cppVar_1323 && cppVar_1325;
	return cppVar_1326;
}
bool model_sha::decode_41(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1328 = (sha_state == 1);
	bool cppVar_1330 = (cmd == 1);
	bool cppVar_1331 = cppVar_1328 && cppVar_1330;
	bool cppVar_1333 = (cmdaddr == 65032);
	bool cppVar_1334 = cppVar_1331 && cppVar_1333;
	return cppVar_1334;
}
bool model_sha::decode_42(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1336 = (sha_state == 2);
	bool cppVar_1338 = (cmd == 1);
	bool cppVar_1339 = cppVar_1336 && cppVar_1338;
	bool cppVar_1341 = (cmdaddr == 65032);
	bool cppVar_1342 = cppVar_1339 && cppVar_1341;
	return cppVar_1342;
}
bool model_sha::decode_43(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1344 = (sha_state == 3);
	bool cppVar_1346 = (cmd == 1);
	bool cppVar_1347 = cppVar_1344 && cppVar_1346;
	bool cppVar_1349 = (cmdaddr == 65032);
	bool cppVar_1350 = cppVar_1347 && cppVar_1349;
	return cppVar_1350;
}
bool model_sha::decode_44(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1352 = (sha_state == 4);
	bool cppVar_1354 = (cmd == 1);
	bool cppVar_1355 = cppVar_1352 && cppVar_1354;
	bool cppVar_1357 = (cmdaddr == 65032);
	bool cppVar_1358 = cppVar_1355 && cppVar_1357;
	return cppVar_1358;
}
bool model_sha::decode_45(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1360 = (sha_state == 0);
	bool cppVar_1362 = (cmd == 1);
	bool cppVar_1363 = cppVar_1360 && cppVar_1362;
	bool cppVar_1365 = (cmdaddr == 65033);
	bool cppVar_1366 = cppVar_1363 && cppVar_1365;
	return cppVar_1366;
}
bool model_sha::decode_46(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1368 = (sha_state == 1);
	bool cppVar_1370 = (cmd == 1);
	bool cppVar_1371 = cppVar_1368 && cppVar_1370;
	bool cppVar_1373 = (cmdaddr == 65033);
	bool cppVar_1374 = cppVar_1371 && cppVar_1373;
	return cppVar_1374;
}
bool model_sha::decode_47(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1376 = (sha_state == 2);
	bool cppVar_1378 = (cmd == 1);
	bool cppVar_1379 = cppVar_1376 && cppVar_1378;
	bool cppVar_1381 = (cmdaddr == 65033);
	bool cppVar_1382 = cppVar_1379 && cppVar_1381;
	return cppVar_1382;
}
bool model_sha::decode_48(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1384 = (sha_state == 3);
	bool cppVar_1386 = (cmd == 1);
	bool cppVar_1387 = cppVar_1384 && cppVar_1386;
	bool cppVar_1389 = (cmdaddr == 65033);
	bool cppVar_1390 = cppVar_1387 && cppVar_1389;
	return cppVar_1390;
}
bool model_sha::decode_49(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1392 = (sha_state == 4);
	bool cppVar_1394 = (cmd == 1);
	bool cppVar_1395 = cppVar_1392 && cppVar_1394;
	bool cppVar_1397 = (cmdaddr == 65033);
	bool cppVar_1398 = cppVar_1395 && cppVar_1397;
	return cppVar_1398;
}
bool model_sha::decode_5(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1040 = (sha_state == 0);
	bool cppVar_1042 = (cmd == 1);
	bool cppVar_1043 = cppVar_1040 && cppVar_1042;
	bool cppVar_1045 = (cmdaddr == 65025);
	bool cppVar_1046 = cppVar_1043 && cppVar_1045;
	return cppVar_1046;
}
bool model_sha::decode_50(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1400 = (sha_state == 0);
	bool cppVar_1402 = (cmd == 1);
	bool cppVar_1403 = cppVar_1400 && cppVar_1402;
	bool cppVar_1405 = (cmdaddr == 65034);
	bool cppVar_1406 = cppVar_1403 && cppVar_1405;
	return cppVar_1406;
}
bool model_sha::decode_51(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1408 = (sha_state == 1);
	bool cppVar_1410 = (cmd == 1);
	bool cppVar_1411 = cppVar_1408 && cppVar_1410;
	bool cppVar_1413 = (cmdaddr == 65034);
	bool cppVar_1414 = cppVar_1411 && cppVar_1413;
	return cppVar_1414;
}
bool model_sha::decode_52(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1416 = (sha_state == 2);
	bool cppVar_1418 = (cmd == 1);
	bool cppVar_1419 = cppVar_1416 && cppVar_1418;
	bool cppVar_1421 = (cmdaddr == 65034);
	bool cppVar_1422 = cppVar_1419 && cppVar_1421;
	return cppVar_1422;
}
bool model_sha::decode_53(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1424 = (sha_state == 3);
	bool cppVar_1426 = (cmd == 1);
	bool cppVar_1427 = cppVar_1424 && cppVar_1426;
	bool cppVar_1429 = (cmdaddr == 65034);
	bool cppVar_1430 = cppVar_1427 && cppVar_1429;
	return cppVar_1430;
}
bool model_sha::decode_54(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1432 = (sha_state == 4);
	bool cppVar_1434 = (cmd == 1);
	bool cppVar_1435 = cppVar_1432 && cppVar_1434;
	bool cppVar_1437 = (cmdaddr == 65034);
	bool cppVar_1438 = cppVar_1435 && cppVar_1437;
	return cppVar_1438;
}
bool model_sha::decode_55(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1440 = (sha_state == 0);
	bool cppVar_1442 = (cmd == 1);
	bool cppVar_1443 = cppVar_1440 && cppVar_1442;
	bool cppVar_1445 = (cmdaddr == 65035);
	bool cppVar_1446 = cppVar_1443 && cppVar_1445;
	return cppVar_1446;
}
bool model_sha::decode_56(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1448 = (sha_state == 1);
	bool cppVar_1450 = (cmd == 1);
	bool cppVar_1451 = cppVar_1448 && cppVar_1450;
	bool cppVar_1453 = (cmdaddr == 65035);
	bool cppVar_1454 = cppVar_1451 && cppVar_1453;
	return cppVar_1454;
}
bool model_sha::decode_57(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1456 = (sha_state == 2);
	bool cppVar_1458 = (cmd == 1);
	bool cppVar_1459 = cppVar_1456 && cppVar_1458;
	bool cppVar_1461 = (cmdaddr == 65035);
	bool cppVar_1462 = cppVar_1459 && cppVar_1461;
	return cppVar_1462;
}
bool model_sha::decode_58(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1464 = (sha_state == 3);
	bool cppVar_1466 = (cmd == 1);
	bool cppVar_1467 = cppVar_1464 && cppVar_1466;
	bool cppVar_1469 = (cmdaddr == 65035);
	bool cppVar_1470 = cppVar_1467 && cppVar_1469;
	return cppVar_1470;
}
bool model_sha::decode_59(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1472 = (sha_state == 4);
	bool cppVar_1474 = (cmd == 1);
	bool cppVar_1475 = cppVar_1472 && cppVar_1474;
	bool cppVar_1477 = (cmdaddr == 65035);
	bool cppVar_1478 = cppVar_1475 && cppVar_1477;
	return cppVar_1478;
}
bool model_sha::decode_6(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1048 = (sha_state == 1);
	bool cppVar_1050 = (cmd == 1);
	bool cppVar_1051 = cppVar_1048 && cppVar_1050;
	bool cppVar_1053 = (cmdaddr == 65025);
	bool cppVar_1054 = cppVar_1051 && cppVar_1053;
	return cppVar_1054;
}
bool model_sha::decode_60(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1480 = (sha_state == 0);
	bool cppVar_1482 = (cmd == 1);
	bool cppVar_1483 = cppVar_1480 && cppVar_1482;
	bool cppVar_1485 = (cmdaddr == 65036);
	bool cppVar_1486 = cppVar_1483 && cppVar_1485;
	return cppVar_1486;
}
bool model_sha::decode_61(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1488 = (sha_state == 1);
	bool cppVar_1490 = (cmd == 1);
	bool cppVar_1491 = cppVar_1488 && cppVar_1490;
	bool cppVar_1493 = (cmdaddr == 65036);
	bool cppVar_1494 = cppVar_1491 && cppVar_1493;
	return cppVar_1494;
}
bool model_sha::decode_62(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1496 = (sha_state == 2);
	bool cppVar_1498 = (cmd == 1);
	bool cppVar_1499 = cppVar_1496 && cppVar_1498;
	bool cppVar_1501 = (cmdaddr == 65036);
	bool cppVar_1502 = cppVar_1499 && cppVar_1501;
	return cppVar_1502;
}
bool model_sha::decode_63(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1504 = (sha_state == 3);
	bool cppVar_1506 = (cmd == 1);
	bool cppVar_1507 = cppVar_1504 && cppVar_1506;
	bool cppVar_1509 = (cmdaddr == 65036);
	bool cppVar_1510 = cppVar_1507 && cppVar_1509;
	return cppVar_1510;
}
bool model_sha::decode_64(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1512 = (sha_state == 4);
	bool cppVar_1514 = (cmd == 1);
	bool cppVar_1515 = cppVar_1512 && cppVar_1514;
	bool cppVar_1517 = (cmdaddr == 65036);
	bool cppVar_1518 = cppVar_1515 && cppVar_1517;
	return cppVar_1518;
}
bool model_sha::decode_65(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1520 = (sha_state == 0);
	bool cppVar_1522 = (cmd == 1);
	bool cppVar_1523 = cppVar_1520 && cppVar_1522;
	bool cppVar_1525 = (cmdaddr == 65037);
	bool cppVar_1526 = cppVar_1523 && cppVar_1525;
	return cppVar_1526;
}
bool model_sha::decode_66(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1528 = (sha_state == 1);
	bool cppVar_1530 = (cmd == 1);
	bool cppVar_1531 = cppVar_1528 && cppVar_1530;
	bool cppVar_1533 = (cmdaddr == 65037);
	bool cppVar_1534 = cppVar_1531 && cppVar_1533;
	return cppVar_1534;
}
bool model_sha::decode_67(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1536 = (sha_state == 2);
	bool cppVar_1538 = (cmd == 1);
	bool cppVar_1539 = cppVar_1536 && cppVar_1538;
	bool cppVar_1541 = (cmdaddr == 65037);
	bool cppVar_1542 = cppVar_1539 && cppVar_1541;
	return cppVar_1542;
}
bool model_sha::decode_68(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1544 = (sha_state == 3);
	bool cppVar_1546 = (cmd == 1);
	bool cppVar_1547 = cppVar_1544 && cppVar_1546;
	bool cppVar_1549 = (cmdaddr == 65037);
	bool cppVar_1550 = cppVar_1547 && cppVar_1549;
	return cppVar_1550;
}
bool model_sha::decode_69(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1552 = (sha_state == 4);
	bool cppVar_1554 = (cmd == 1);
	bool cppVar_1555 = cppVar_1552 && cppVar_1554;
	bool cppVar_1557 = (cmdaddr == 65037);
	bool cppVar_1558 = cppVar_1555 && cppVar_1557;
	return cppVar_1558;
}
bool model_sha::decode_7(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1056 = (sha_state == 2);
	bool cppVar_1058 = (cmd == 1);
	bool cppVar_1059 = cppVar_1056 && cppVar_1058;
	bool cppVar_1061 = (cmdaddr == 65025);
	bool cppVar_1062 = cppVar_1059 && cppVar_1061;
	return cppVar_1062;
}
bool model_sha::decode_70(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1560 = (sha_state == 0);
	bool cppVar_1562 = (cmd == 1);
	bool cppVar_1563 = cppVar_1560 && cppVar_1562;
	bool cppVar_1565 = (cmdaddr == 65038);
	bool cppVar_1566 = cppVar_1563 && cppVar_1565;
	return cppVar_1566;
}
bool model_sha::decode_71(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1568 = (sha_state == 1);
	bool cppVar_1570 = (cmd == 1);
	bool cppVar_1571 = cppVar_1568 && cppVar_1570;
	bool cppVar_1573 = (cmdaddr == 65038);
	bool cppVar_1574 = cppVar_1571 && cppVar_1573;
	return cppVar_1574;
}
bool model_sha::decode_72(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1576 = (sha_state == 2);
	bool cppVar_1578 = (cmd == 1);
	bool cppVar_1579 = cppVar_1576 && cppVar_1578;
	bool cppVar_1581 = (cmdaddr == 65038);
	bool cppVar_1582 = cppVar_1579 && cppVar_1581;
	return cppVar_1582;
}
bool model_sha::decode_73(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1584 = (sha_state == 3);
	bool cppVar_1586 = (cmd == 1);
	bool cppVar_1587 = cppVar_1584 && cppVar_1586;
	bool cppVar_1589 = (cmdaddr == 65038);
	bool cppVar_1590 = cppVar_1587 && cppVar_1589;
	return cppVar_1590;
}
bool model_sha::decode_74(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1592 = (sha_state == 4);
	bool cppVar_1594 = (cmd == 1);
	bool cppVar_1595 = cppVar_1592 && cppVar_1594;
	bool cppVar_1597 = (cmdaddr == 65038);
	bool cppVar_1598 = cppVar_1595 && cppVar_1597;
	return cppVar_1598;
}
bool model_sha::decode_75(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1600 = (sha_state == 0);
	bool cppVar_1602 = (cmd == 1);
	bool cppVar_1603 = cppVar_1600 && cppVar_1602;
	bool cppVar_1605 = (cmdaddr == 65039);
	bool cppVar_1606 = cppVar_1603 && cppVar_1605;
	return cppVar_1606;
}
bool model_sha::decode_76(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1608 = (sha_state == 1);
	bool cppVar_1610 = (cmd == 1);
	bool cppVar_1611 = cppVar_1608 && cppVar_1610;
	bool cppVar_1613 = (cmdaddr == 65039);
	bool cppVar_1614 = cppVar_1611 && cppVar_1613;
	return cppVar_1614;
}
bool model_sha::decode_77(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1616 = (sha_state == 2);
	bool cppVar_1618 = (cmd == 1);
	bool cppVar_1619 = cppVar_1616 && cppVar_1618;
	bool cppVar_1621 = (cmdaddr == 65039);
	bool cppVar_1622 = cppVar_1619 && cppVar_1621;
	return cppVar_1622;
}
bool model_sha::decode_78(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1624 = (sha_state == 3);
	bool cppVar_1626 = (cmd == 1);
	bool cppVar_1627 = cppVar_1624 && cppVar_1626;
	bool cppVar_1629 = (cmdaddr == 65039);
	bool cppVar_1630 = cppVar_1627 && cppVar_1629;
	return cppVar_1630;
}
bool model_sha::decode_79(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1632 = (sha_state == 4);
	bool cppVar_1634 = (cmd == 1);
	bool cppVar_1635 = cppVar_1632 && cppVar_1634;
	bool cppVar_1637 = (cmdaddr == 65039);
	bool cppVar_1638 = cppVar_1635 && cppVar_1637;
	return cppVar_1638;
}
bool model_sha::decode_8(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1064 = (sha_state == 3);
	bool cppVar_1066 = (cmd == 1);
	bool cppVar_1067 = cppVar_1064 && cppVar_1066;
	bool cppVar_1069 = (cmdaddr == 65025);
	bool cppVar_1070 = cppVar_1067 && cppVar_1069;
	return cppVar_1070;
}
bool model_sha::decode_80(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1640 = (sha_state == 0);
	bool cppVar_1642 = (cmd == 2);
	bool cppVar_1643 = cppVar_1640 && cppVar_1642;
	bool cppVar_1645 = (cmdaddr == 65024);
	bool cppVar_1646 = cppVar_1643 && cppVar_1645;
	return cppVar_1646;
}
bool model_sha::decode_81(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1648 = (sha_state == 0);
	bool cppVar_1650 = (cmd == 2);
	bool cppVar_1651 = cppVar_1648 && cppVar_1650;
	bool cppVar_1653 = (cmdaddr == 65025);
	bool cppVar_1654 = cppVar_1651 && cppVar_1653;
	return cppVar_1654;
}
bool model_sha::decode_82(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1656 = (sha_state == 0);
	bool cppVar_1658 = (cmd == 2);
	bool cppVar_1659 = cppVar_1656 && cppVar_1658;
	bool cppVar_1661 = (cmdaddr == 65026);
	bool cppVar_1662 = cppVar_1659 && cppVar_1661;
	return cppVar_1662;
}
bool model_sha::decode_83(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1664 = (sha_state == 0);
	bool cppVar_1666 = (cmd == 2);
	bool cppVar_1667 = cppVar_1664 && cppVar_1666;
	bool cppVar_1669 = (cmdaddr == 65027);
	bool cppVar_1670 = cppVar_1667 && cppVar_1669;
	return cppVar_1670;
}
bool model_sha::decode_84(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1672 = (sha_state == 0);
	bool cppVar_1674 = (cmd == 2);
	bool cppVar_1675 = cppVar_1672 && cppVar_1674;
	bool cppVar_1677 = (cmdaddr == 65028);
	bool cppVar_1678 = cppVar_1675 && cppVar_1677;
	return cppVar_1678;
}
bool model_sha::decode_85(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1680 = (sha_state == 0);
	bool cppVar_1682 = (cmd == 2);
	bool cppVar_1683 = cppVar_1680 && cppVar_1682;
	bool cppVar_1685 = (cmdaddr == 65029);
	bool cppVar_1686 = cppVar_1683 && cppVar_1685;
	return cppVar_1686;
}
bool model_sha::decode_86(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1688 = (sha_state == 0);
	bool cppVar_1690 = (cmd == 2);
	bool cppVar_1691 = cppVar_1688 && cppVar_1690;
	bool cppVar_1693 = (cmdaddr == 65030);
	bool cppVar_1694 = cppVar_1691 && cppVar_1693;
	return cppVar_1694;
}
bool model_sha::decode_87(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1696 = (sha_state == 0);
	bool cppVar_1698 = (cmd == 2);
	bool cppVar_1699 = cppVar_1696 && cppVar_1698;
	bool cppVar_1701 = (cmdaddr == 65031);
	bool cppVar_1702 = cppVar_1699 && cppVar_1701;
	return cppVar_1702;
}
bool model_sha::decode_88(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1704 = (sha_state == 0);
	bool cppVar_1706 = (cmd == 2);
	bool cppVar_1707 = cppVar_1704 && cppVar_1706;
	bool cppVar_1709 = (cmdaddr == 65032);
	bool cppVar_1710 = cppVar_1707 && cppVar_1709;
	return cppVar_1710;
}
bool model_sha::decode_89(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1712 = (sha_state == 0);
	bool cppVar_1714 = (cmd == 2);
	bool cppVar_1715 = cppVar_1712 && cppVar_1714;
	bool cppVar_1717 = (cmdaddr == 65033);
	bool cppVar_1718 = cppVar_1715 && cppVar_1717;
	return cppVar_1718;
}
bool model_sha::decode_9(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1072 = (sha_state == 4);
	bool cppVar_1074 = (cmd == 1);
	bool cppVar_1075 = cppVar_1072 && cppVar_1074;
	bool cppVar_1077 = (cmdaddr == 65025);
	bool cppVar_1078 = cppVar_1075 && cppVar_1077;
	return cppVar_1078;
}
bool model_sha::decode_90(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1720 = (sha_state == 0);
	bool cppVar_1722 = (cmd == 2);
	bool cppVar_1723 = cppVar_1720 && cppVar_1722;
	bool cppVar_1725 = (cmdaddr == 65034);
	bool cppVar_1726 = cppVar_1723 && cppVar_1725;
	return cppVar_1726;
}
bool model_sha::decode_91(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1728 = (sha_state == 0);
	bool cppVar_1730 = (cmd == 2);
	bool cppVar_1731 = cppVar_1728 && cppVar_1730;
	bool cppVar_1733 = (cmdaddr == 65035);
	bool cppVar_1734 = cppVar_1731 && cppVar_1733;
	return cppVar_1734;
}
bool model_sha::decode_92(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1736 = (sha_state == 0);
	bool cppVar_1738 = (cmd == 2);
	bool cppVar_1739 = cppVar_1736 && cppVar_1738;
	bool cppVar_1741 = (cmdaddr == 65036);
	bool cppVar_1742 = cppVar_1739 && cppVar_1741;
	return cppVar_1742;
}
bool model_sha::decode_93(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1744 = (sha_state == 0);
	bool cppVar_1746 = (cmd == 2);
	bool cppVar_1747 = cppVar_1744 && cppVar_1746;
	bool cppVar_1749 = (cmdaddr == 65037);
	bool cppVar_1750 = cppVar_1747 && cppVar_1749;
	return cppVar_1750;
}
bool model_sha::decode_94(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1752 = (sha_state == 0);
	bool cppVar_1754 = (cmd == 2);
	bool cppVar_1755 = cppVar_1752 && cppVar_1754;
	bool cppVar_1757 = (cmdaddr == 65038);
	bool cppVar_1758 = cppVar_1755 && cppVar_1757;
	return cppVar_1758;
}
bool model_sha::decode_95(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1760 = (sha_state == 0);
	bool cppVar_1762 = (cmd == 2);
	bool cppVar_1763 = cppVar_1760 && cppVar_1762;
	bool cppVar_1765 = (cmdaddr == 65039);
	bool cppVar_1766 = cppVar_1763 && cppVar_1765;
	return cppVar_1766;
}
bool model_sha::decode_96(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_1768 = (sha_state != 0);
	bool cppVar_1770 = (cmd != 1);
	bool cppVar_1771 = cppVar_1768 && cppVar_1770;
	bool cppVar_1773 = (sha_state == 0);
	bool cppVar_1775 = (cmd != 1);
	bool cppVar_1776 = cppVar_1773 && cppVar_1775;
	bool cppVar_1778 = (cmd != 2);
	bool cppVar_1779 = cppVar_1776 && cppVar_1778;
	bool cppVar_1780 = cppVar_1771 || cppVar_1779;
	return cppVar_1780;
}
BIT_VEC model_sha::fetch(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_991 = (cmdaddr << 8) | cmddata;
	cppVar_991 = (cppVar_991 & cppMask_un_24_);
	BIT_VEC cppVar_992 = (cmd << 24) | cppVar_991;
	cppVar_992 = (cppVar_992 & cppMask_un_26_);
	BIT_VEC cppVar_993 = (sha_state << 26) | cppVar_992;
	cppVar_993 = (cppVar_993 & cppMask_un_29_);
	return cppVar_993;
}
bool model_sha::fetchValid(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	bool cppVar_995 = (cmd == 1);
	bool cppVar_997 = (cmd == 2);
	bool cppVar_998 = cppVar_995 || cppVar_997;
	return cppVar_998;
}
void model_sha::update(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
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
	bool cppVar_298 = (sha_state == 0);
	bool cppVar_300 = (cmd == 1);
	bool cppVar_301 = cppVar_298 && cppVar_300;
	bool cppVar_303 = (cmdaddr == 65033);
	bool cppVar_304 = cppVar_301 && cppVar_303;
	bool cppVar_306 = (sha_state == 4);
	bool cppVar_308 = (cmd == 1);
	bool cppVar_309 = cppVar_306 && cppVar_308;
	bool cppVar_311 = (cmdaddr == 65025);
	bool cppVar_312 = cppVar_309 && cppVar_311;
	bool cppVar_314 = (sha_state == 3);
	bool cppVar_316 = (cmd == 1);
	bool cppVar_317 = cppVar_314 && cppVar_316;
	bool cppVar_319 = (cmdaddr == 65025);
	bool cppVar_320 = cppVar_317 && cppVar_319;
	bool cppVar_322 = (sha_state == 2);
	bool cppVar_324 = (cmd == 1);
	bool cppVar_325 = cppVar_322 && cppVar_324;
	bool cppVar_327 = (cmdaddr == 65025);
	bool cppVar_328 = cppVar_325 && cppVar_327;
	bool cppVar_330 = (sha_state == 1);
	bool cppVar_332 = (cmd == 1);
	bool cppVar_333 = cppVar_330 && cppVar_332;
	bool cppVar_335 = (cmdaddr == 65025);
	bool cppVar_336 = cppVar_333 && cppVar_335;
	bool cppVar_337 = cppVar_328 || cppVar_336;
	bool cppVar_338 = cppVar_320 || cppVar_337;
	bool cppVar_339 = cppVar_312 || cppVar_338;
	bool cppVar_340 = cppVar_304 || cppVar_339;
	BIT_VEC cppVar_341 = (sha_state & cppMask_un_3_);
	bool cppVar_343 = (sha_state != 0);
	bool cppVar_345 = (cmd != 1);
	bool cppVar_346 = cppVar_343 && cppVar_345;
	bool cppVar_348 = (sha_state == 0);
	bool cppVar_350 = (cmd != 1);
	bool cppVar_351 = cppVar_348 && cppVar_350;
	bool cppVar_353 = (cmd != 2);
	bool cppVar_354 = cppVar_351 && cppVar_353;
	bool cppVar_355 = cppVar_346 || cppVar_354;
	bool cppVar_357 = (sha_state == 0);
	bool cppVar_359 = (cmd == 2);
	bool cppVar_360 = cppVar_357 && cppVar_359;
	bool cppVar_362 = (cmdaddr == 65039);
	bool cppVar_363 = cppVar_360 && cppVar_362;
	bool cppVar_365 = (sha_state == 0);
	bool cppVar_367 = (cmd == 2);
	bool cppVar_368 = cppVar_365 && cppVar_367;
	bool cppVar_370 = (cmdaddr == 65038);
	bool cppVar_371 = cppVar_368 && cppVar_370;
	bool cppVar_373 = (sha_state == 0);
	bool cppVar_375 = (cmd == 2);
	bool cppVar_376 = cppVar_373 && cppVar_375;
	bool cppVar_378 = (cmdaddr == 65037);
	bool cppVar_379 = cppVar_376 && cppVar_378;
	bool cppVar_381 = (sha_state == 0);
	bool cppVar_383 = (cmd == 2);
	bool cppVar_384 = cppVar_381 && cppVar_383;
	bool cppVar_386 = (cmdaddr == 65036);
	bool cppVar_387 = cppVar_384 && cppVar_386;
	bool cppVar_389 = (sha_state == 0);
	bool cppVar_391 = (cmd == 2);
	bool cppVar_392 = cppVar_389 && cppVar_391;
	bool cppVar_394 = (cmdaddr == 65035);
	bool cppVar_395 = cppVar_392 && cppVar_394;
	bool cppVar_397 = (sha_state == 0);
	bool cppVar_399 = (cmd == 2);
	bool cppVar_400 = cppVar_397 && cppVar_399;
	bool cppVar_402 = (cmdaddr == 65034);
	bool cppVar_403 = cppVar_400 && cppVar_402;
	bool cppVar_405 = (sha_state == 0);
	bool cppVar_407 = (cmd == 2);
	bool cppVar_408 = cppVar_405 && cppVar_407;
	bool cppVar_410 = (cmdaddr == 65033);
	bool cppVar_411 = cppVar_408 && cppVar_410;
	bool cppVar_413 = (sha_state == 0);
	bool cppVar_415 = (cmd == 2);
	bool cppVar_416 = cppVar_413 && cppVar_415;
	bool cppVar_418 = (cmdaddr == 65032);
	bool cppVar_419 = cppVar_416 && cppVar_418;
	bool cppVar_421 = (sha_state == 0);
	bool cppVar_423 = (cmd == 2);
	bool cppVar_424 = cppVar_421 && cppVar_423;
	bool cppVar_426 = (cmdaddr == 65031);
	bool cppVar_427 = cppVar_424 && cppVar_426;
	bool cppVar_429 = (sha_state == 0);
	bool cppVar_431 = (cmd == 2);
	bool cppVar_432 = cppVar_429 && cppVar_431;
	bool cppVar_434 = (cmdaddr == 65030);
	bool cppVar_435 = cppVar_432 && cppVar_434;
	bool cppVar_437 = (sha_state == 0);
	bool cppVar_439 = (cmd == 2);
	bool cppVar_440 = cppVar_437 && cppVar_439;
	bool cppVar_442 = (cmdaddr == 65029);
	bool cppVar_443 = cppVar_440 && cppVar_442;
	bool cppVar_445 = (sha_state == 0);
	bool cppVar_447 = (cmd == 2);
	bool cppVar_448 = cppVar_445 && cppVar_447;
	bool cppVar_450 = (cmdaddr == 65028);
	bool cppVar_451 = cppVar_448 && cppVar_450;
	bool cppVar_453 = (sha_state == 0);
	bool cppVar_455 = (cmd == 2);
	bool cppVar_456 = cppVar_453 && cppVar_455;
	bool cppVar_458 = (cmdaddr == 65027);
	bool cppVar_459 = cppVar_456 && cppVar_458;
	bool cppVar_461 = (sha_state == 0);
	bool cppVar_463 = (cmd == 2);
	bool cppVar_464 = cppVar_461 && cppVar_463;
	bool cppVar_466 = (cmdaddr == 65026);
	bool cppVar_467 = cppVar_464 && cppVar_466;
	bool cppVar_469 = (sha_state == 0);
	bool cppVar_471 = (cmd == 2);
	bool cppVar_472 = cppVar_469 && cppVar_471;
	bool cppVar_474 = (cmdaddr == 65025);
	bool cppVar_475 = cppVar_472 && cppVar_474;
	bool cppVar_477 = (sha_state == 0);
	bool cppVar_479 = (cmd == 2);
	bool cppVar_480 = cppVar_477 && cppVar_479;
	bool cppVar_482 = (cmdaddr == 65024);
	bool cppVar_483 = cppVar_480 && cppVar_482;
	bool cppVar_485 = (sha_state == 4);
	bool cppVar_487 = (cmd == 1);
	bool cppVar_488 = cppVar_485 && cppVar_487;
	bool cppVar_490 = (cmdaddr == 65039);
	bool cppVar_491 = cppVar_488 && cppVar_490;
	bool cppVar_493 = (sha_state == 3);
	bool cppVar_495 = (cmd == 1);
	bool cppVar_496 = cppVar_493 && cppVar_495;
	bool cppVar_498 = (cmdaddr == 65039);
	bool cppVar_499 = cppVar_496 && cppVar_498;
	bool cppVar_501 = (sha_state == 2);
	bool cppVar_503 = (cmd == 1);
	bool cppVar_504 = cppVar_501 && cppVar_503;
	bool cppVar_506 = (cmdaddr == 65039);
	bool cppVar_507 = cppVar_504 && cppVar_506;
	bool cppVar_509 = (sha_state == 1);
	bool cppVar_511 = (cmd == 1);
	bool cppVar_512 = cppVar_509 && cppVar_511;
	bool cppVar_514 = (cmdaddr == 65039);
	bool cppVar_515 = cppVar_512 && cppVar_514;
	bool cppVar_517 = (sha_state == 0);
	bool cppVar_519 = (cmd == 1);
	bool cppVar_520 = cppVar_517 && cppVar_519;
	bool cppVar_522 = (cmdaddr == 65039);
	bool cppVar_523 = cppVar_520 && cppVar_522;
	bool cppVar_525 = (sha_state == 4);
	bool cppVar_527 = (cmd == 1);
	bool cppVar_528 = cppVar_525 && cppVar_527;
	bool cppVar_530 = (cmdaddr == 65038);
	bool cppVar_531 = cppVar_528 && cppVar_530;
	bool cppVar_533 = (sha_state == 3);
	bool cppVar_535 = (cmd == 1);
	bool cppVar_536 = cppVar_533 && cppVar_535;
	bool cppVar_538 = (cmdaddr == 65038);
	bool cppVar_539 = cppVar_536 && cppVar_538;
	bool cppVar_541 = (sha_state == 2);
	bool cppVar_543 = (cmd == 1);
	bool cppVar_544 = cppVar_541 && cppVar_543;
	bool cppVar_546 = (cmdaddr == 65038);
	bool cppVar_547 = cppVar_544 && cppVar_546;
	bool cppVar_549 = (sha_state == 1);
	bool cppVar_551 = (cmd == 1);
	bool cppVar_552 = cppVar_549 && cppVar_551;
	bool cppVar_554 = (cmdaddr == 65038);
	bool cppVar_555 = cppVar_552 && cppVar_554;
	bool cppVar_557 = (sha_state == 0);
	bool cppVar_559 = (cmd == 1);
	bool cppVar_560 = cppVar_557 && cppVar_559;
	bool cppVar_562 = (cmdaddr == 65038);
	bool cppVar_563 = cppVar_560 && cppVar_562;
	bool cppVar_565 = (sha_state == 4);
	bool cppVar_567 = (cmd == 1);
	bool cppVar_568 = cppVar_565 && cppVar_567;
	bool cppVar_570 = (cmdaddr == 65037);
	bool cppVar_571 = cppVar_568 && cppVar_570;
	bool cppVar_573 = (sha_state == 3);
	bool cppVar_575 = (cmd == 1);
	bool cppVar_576 = cppVar_573 && cppVar_575;
	bool cppVar_578 = (cmdaddr == 65037);
	bool cppVar_579 = cppVar_576 && cppVar_578;
	bool cppVar_581 = (sha_state == 2);
	bool cppVar_583 = (cmd == 1);
	bool cppVar_584 = cppVar_581 && cppVar_583;
	bool cppVar_586 = (cmdaddr == 65037);
	bool cppVar_587 = cppVar_584 && cppVar_586;
	bool cppVar_589 = (sha_state == 1);
	bool cppVar_591 = (cmd == 1);
	bool cppVar_592 = cppVar_589 && cppVar_591;
	bool cppVar_594 = (cmdaddr == 65037);
	bool cppVar_595 = cppVar_592 && cppVar_594;
	bool cppVar_597 = (sha_state == 0);
	bool cppVar_599 = (cmd == 1);
	bool cppVar_600 = cppVar_597 && cppVar_599;
	bool cppVar_602 = (cmdaddr == 65037);
	bool cppVar_603 = cppVar_600 && cppVar_602;
	bool cppVar_605 = (sha_state == 4);
	bool cppVar_607 = (cmd == 1);
	bool cppVar_608 = cppVar_605 && cppVar_607;
	bool cppVar_610 = (cmdaddr == 65036);
	bool cppVar_611 = cppVar_608 && cppVar_610;
	bool cppVar_613 = (sha_state == 3);
	bool cppVar_615 = (cmd == 1);
	bool cppVar_616 = cppVar_613 && cppVar_615;
	bool cppVar_618 = (cmdaddr == 65036);
	bool cppVar_619 = cppVar_616 && cppVar_618;
	bool cppVar_621 = (sha_state == 2);
	bool cppVar_623 = (cmd == 1);
	bool cppVar_624 = cppVar_621 && cppVar_623;
	bool cppVar_626 = (cmdaddr == 65036);
	bool cppVar_627 = cppVar_624 && cppVar_626;
	bool cppVar_629 = (sha_state == 1);
	bool cppVar_631 = (cmd == 1);
	bool cppVar_632 = cppVar_629 && cppVar_631;
	bool cppVar_634 = (cmdaddr == 65036);
	bool cppVar_635 = cppVar_632 && cppVar_634;
	bool cppVar_637 = (sha_state == 0);
	bool cppVar_639 = (cmd == 1);
	bool cppVar_640 = cppVar_637 && cppVar_639;
	bool cppVar_642 = (cmdaddr == 65036);
	bool cppVar_643 = cppVar_640 && cppVar_642;
	bool cppVar_645 = (sha_state == 4);
	bool cppVar_647 = (cmd == 1);
	bool cppVar_648 = cppVar_645 && cppVar_647;
	bool cppVar_650 = (cmdaddr == 65035);
	bool cppVar_651 = cppVar_648 && cppVar_650;
	bool cppVar_653 = (sha_state == 3);
	bool cppVar_655 = (cmd == 1);
	bool cppVar_656 = cppVar_653 && cppVar_655;
	bool cppVar_658 = (cmdaddr == 65035);
	bool cppVar_659 = cppVar_656 && cppVar_658;
	bool cppVar_661 = (sha_state == 2);
	bool cppVar_663 = (cmd == 1);
	bool cppVar_664 = cppVar_661 && cppVar_663;
	bool cppVar_666 = (cmdaddr == 65035);
	bool cppVar_667 = cppVar_664 && cppVar_666;
	bool cppVar_669 = (sha_state == 1);
	bool cppVar_671 = (cmd == 1);
	bool cppVar_672 = cppVar_669 && cppVar_671;
	bool cppVar_674 = (cmdaddr == 65035);
	bool cppVar_675 = cppVar_672 && cppVar_674;
	bool cppVar_677 = (sha_state == 0);
	bool cppVar_679 = (cmd == 1);
	bool cppVar_680 = cppVar_677 && cppVar_679;
	bool cppVar_682 = (cmdaddr == 65035);
	bool cppVar_683 = cppVar_680 && cppVar_682;
	bool cppVar_685 = (sha_state == 4);
	bool cppVar_687 = (cmd == 1);
	bool cppVar_688 = cppVar_685 && cppVar_687;
	bool cppVar_690 = (cmdaddr == 65034);
	bool cppVar_691 = cppVar_688 && cppVar_690;
	bool cppVar_693 = (sha_state == 3);
	bool cppVar_695 = (cmd == 1);
	bool cppVar_696 = cppVar_693 && cppVar_695;
	bool cppVar_698 = (cmdaddr == 65034);
	bool cppVar_699 = cppVar_696 && cppVar_698;
	bool cppVar_701 = (sha_state == 2);
	bool cppVar_703 = (cmd == 1);
	bool cppVar_704 = cppVar_701 && cppVar_703;
	bool cppVar_706 = (cmdaddr == 65034);
	bool cppVar_707 = cppVar_704 && cppVar_706;
	bool cppVar_709 = (sha_state == 1);
	bool cppVar_711 = (cmd == 1);
	bool cppVar_712 = cppVar_709 && cppVar_711;
	bool cppVar_714 = (cmdaddr == 65034);
	bool cppVar_715 = cppVar_712 && cppVar_714;
	bool cppVar_717 = (sha_state == 0);
	bool cppVar_719 = (cmd == 1);
	bool cppVar_720 = cppVar_717 && cppVar_719;
	bool cppVar_722 = (cmdaddr == 65034);
	bool cppVar_723 = cppVar_720 && cppVar_722;
	bool cppVar_725 = (sha_state == 4);
	bool cppVar_727 = (cmd == 1);
	bool cppVar_728 = cppVar_725 && cppVar_727;
	bool cppVar_730 = (cmdaddr == 65033);
	bool cppVar_731 = cppVar_728 && cppVar_730;
	bool cppVar_733 = (sha_state == 3);
	bool cppVar_735 = (cmd == 1);
	bool cppVar_736 = cppVar_733 && cppVar_735;
	bool cppVar_738 = (cmdaddr == 65033);
	bool cppVar_739 = cppVar_736 && cppVar_738;
	bool cppVar_741 = (sha_state == 2);
	bool cppVar_743 = (cmd == 1);
	bool cppVar_744 = cppVar_741 && cppVar_743;
	bool cppVar_746 = (cmdaddr == 65033);
	bool cppVar_747 = cppVar_744 && cppVar_746;
	bool cppVar_749 = (sha_state == 1);
	bool cppVar_751 = (cmd == 1);
	bool cppVar_752 = cppVar_749 && cppVar_751;
	bool cppVar_754 = (cmdaddr == 65033);
	bool cppVar_755 = cppVar_752 && cppVar_754;
	bool cppVar_757 = (sha_state == 4);
	bool cppVar_759 = (cmd == 1);
	bool cppVar_760 = cppVar_757 && cppVar_759;
	bool cppVar_762 = (cmdaddr == 65032);
	bool cppVar_763 = cppVar_760 && cppVar_762;
	bool cppVar_765 = (sha_state == 3);
	bool cppVar_767 = (cmd == 1);
	bool cppVar_768 = cppVar_765 && cppVar_767;
	bool cppVar_770 = (cmdaddr == 65032);
	bool cppVar_771 = cppVar_768 && cppVar_770;
	bool cppVar_773 = (sha_state == 2);
	bool cppVar_775 = (cmd == 1);
	bool cppVar_776 = cppVar_773 && cppVar_775;
	bool cppVar_778 = (cmdaddr == 65032);
	bool cppVar_779 = cppVar_776 && cppVar_778;
	bool cppVar_781 = (sha_state == 1);
	bool cppVar_783 = (cmd == 1);
	bool cppVar_784 = cppVar_781 && cppVar_783;
	bool cppVar_786 = (cmdaddr == 65032);
	bool cppVar_787 = cppVar_784 && cppVar_786;
	bool cppVar_789 = (sha_state == 0);
	bool cppVar_791 = (cmd == 1);
	bool cppVar_792 = cppVar_789 && cppVar_791;
	bool cppVar_794 = (cmdaddr == 65032);
	bool cppVar_795 = cppVar_792 && cppVar_794;
	bool cppVar_797 = (sha_state == 0);
	bool cppVar_799 = (cmd == 1);
	bool cppVar_800 = cppVar_797 && cppVar_799;
	bool cppVar_802 = (cmdaddr == 65025);
	bool cppVar_803 = cppVar_800 && cppVar_802;
	bool cppVar_805 = (sha_state == 4);
	bool cppVar_807 = (cmd == 1);
	bool cppVar_808 = cppVar_805 && cppVar_807;
	bool cppVar_810 = (cmdaddr == 65024);
	bool cppVar_811 = cppVar_808 && cppVar_810;
	bool cppVar_813 = (sha_state == 3);
	bool cppVar_815 = (cmd == 1);
	bool cppVar_816 = cppVar_813 && cppVar_815;
	bool cppVar_818 = (cmdaddr == 65024);
	bool cppVar_819 = cppVar_816 && cppVar_818;
	bool cppVar_821 = (sha_state == 2);
	bool cppVar_823 = (cmd == 1);
	bool cppVar_824 = cppVar_821 && cppVar_823;
	bool cppVar_826 = (cmdaddr == 65024);
	bool cppVar_827 = cppVar_824 && cppVar_826;
	bool cppVar_829 = (sha_state == 1);
	bool cppVar_831 = (cmd == 1);
	bool cppVar_832 = cppVar_829 && cppVar_831;
	bool cppVar_834 = (cmdaddr == 65024);
	bool cppVar_835 = cppVar_832 && cppVar_834;
	bool cppVar_837 = (sha_state == 0);
	bool cppVar_839 = (cmd == 1);
	bool cppVar_840 = cppVar_837 && cppVar_839;
	bool cppVar_842 = (cmdaddr == 65024);
	bool cppVar_843 = cppVar_840 && cppVar_842;
	bool cppVar_844 = cppVar_835 || cppVar_843;
	bool cppVar_845 = cppVar_827 || cppVar_844;
	bool cppVar_846 = cppVar_819 || cppVar_845;
	bool cppVar_847 = cppVar_811 || cppVar_846;
	bool cppVar_848 = cppVar_803 || cppVar_847;
	bool cppVar_849 = cppVar_795 || cppVar_848;
	bool cppVar_850 = cppVar_787 || cppVar_849;
	bool cppVar_851 = cppVar_779 || cppVar_850;
	bool cppVar_852 = cppVar_771 || cppVar_851;
	bool cppVar_853 = cppVar_763 || cppVar_852;
	bool cppVar_854 = cppVar_755 || cppVar_853;
	bool cppVar_855 = cppVar_747 || cppVar_854;
	bool cppVar_856 = cppVar_739 || cppVar_855;
	bool cppVar_857 = cppVar_731 || cppVar_856;
	bool cppVar_858 = cppVar_723 || cppVar_857;
	bool cppVar_859 = cppVar_715 || cppVar_858;
	bool cppVar_860 = cppVar_707 || cppVar_859;
	bool cppVar_861 = cppVar_699 || cppVar_860;
	bool cppVar_862 = cppVar_691 || cppVar_861;
	bool cppVar_863 = cppVar_683 || cppVar_862;
	bool cppVar_864 = cppVar_675 || cppVar_863;
	bool cppVar_865 = cppVar_667 || cppVar_864;
	bool cppVar_866 = cppVar_659 || cppVar_865;
	bool cppVar_867 = cppVar_651 || cppVar_866;
	bool cppVar_868 = cppVar_643 || cppVar_867;
	bool cppVar_869 = cppVar_635 || cppVar_868;
	bool cppVar_870 = cppVar_627 || cppVar_869;
	bool cppVar_871 = cppVar_619 || cppVar_870;
	bool cppVar_872 = cppVar_611 || cppVar_871;
	bool cppVar_873 = cppVar_603 || cppVar_872;
	bool cppVar_874 = cppVar_595 || cppVar_873;
	bool cppVar_875 = cppVar_587 || cppVar_874;
	bool cppVar_876 = cppVar_579 || cppVar_875;
	bool cppVar_877 = cppVar_571 || cppVar_876;
	bool cppVar_878 = cppVar_563 || cppVar_877;
	bool cppVar_879 = cppVar_555 || cppVar_878;
	bool cppVar_880 = cppVar_547 || cppVar_879;
	bool cppVar_881 = cppVar_539 || cppVar_880;
	bool cppVar_882 = cppVar_531 || cppVar_881;
	bool cppVar_883 = cppVar_523 || cppVar_882;
	bool cppVar_884 = cppVar_515 || cppVar_883;
	bool cppVar_885 = cppVar_507 || cppVar_884;
	bool cppVar_886 = cppVar_499 || cppVar_885;
	bool cppVar_887 = cppVar_491 || cppVar_886;
	bool cppVar_888 = cppVar_483 || cppVar_887;
	bool cppVar_889 = cppVar_475 || cppVar_888;
	bool cppVar_890 = cppVar_467 || cppVar_889;
	bool cppVar_891 = cppVar_459 || cppVar_890;
	bool cppVar_892 = cppVar_451 || cppVar_891;
	bool cppVar_893 = cppVar_443 || cppVar_892;
	bool cppVar_894 = cppVar_435 || cppVar_893;
	bool cppVar_895 = cppVar_427 || cppVar_894;
	bool cppVar_896 = cppVar_419 || cppVar_895;
	bool cppVar_897 = cppVar_411 || cppVar_896;
	bool cppVar_898 = cppVar_403 || cppVar_897;
	bool cppVar_899 = cppVar_395 || cppVar_898;
	bool cppVar_900 = cppVar_387 || cppVar_899;
	bool cppVar_901 = cppVar_379 || cppVar_900;
	bool cppVar_902 = cppVar_371 || cppVar_901;
	bool cppVar_903 = cppVar_363 || cppVar_902;
	bool cppVar_904 = cppVar_355 || cppVar_903;
	BIT_VEC cppVar_906 = (cppVar_904) ? 0 : dataout;
	BIT_VEC cppVar_907 = (cppVar_340) ? cppVar_341 : cppVar_906;
	BIT_VEC cppVar_908 = (cppVar_295) ? cppVar_296 : cppVar_907;
	BIT_VEC cppVar_909 = (cppVar_250) ? cppVar_251 : cppVar_908;
	BIT_VEC cppVar_910 = (cppVar_205) ? cppVar_206 : cppVar_909;
	BIT_VEC cppVar_911 = (cppVar_160) ? cppVar_161 : cppVar_910;
	BIT_VEC cppVar_912 = (cppVar_115) ? cppVar_116 : cppVar_911;
	BIT_VEC cppVar_913 = (cppVar_70) ? cppVar_71 : cppVar_912;
	BIT_VEC cppVar_914 = (sha_len >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_915 = (cmddata << 8) | cppVar_914;
	cppVar_915 = (cppVar_915 & cppMask_un_16_);
	BIT_VEC cppVar_916 = (sha_len >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_917 = (cppVar_916 << 8) | cmddata;
	cppVar_917 = (cppVar_917 & cppMask_un_16_);
	BIT_VEC cppVar_918 = (cppVar_435) ? cppVar_917 : sha_len;
	BIT_VEC cppVar_919 = (cppVar_427) ? cppVar_915 : cppVar_918;
	BIT_VEC cppVar_920 = (sha_rdaddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_921 = (cmddata << 8) | cppVar_920;
	cppVar_921 = (cppVar_921 & cppMask_un_16_);
	BIT_VEC cppVar_922 = (sha_rdaddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_923 = (cppVar_922 << 8) | cmddata;
	cppVar_923 = (cppVar_923 & cppMask_un_16_);
	BIT_VEC cppVar_924 = (cppVar_467) ? cppVar_923 : sha_rdaddr;
	BIT_VEC cppVar_925 = (cppVar_459) ? cppVar_921 : cppVar_924;
	bool cppVar_927 = (sha_state != 0);
	bool cppVar_929 = (sha_state == 4);
	bool cppVar_932 = (sha_state == 3);
	bool cppVar_933 = sha_bytes_read < sha_len;
	BIT_VEC cppVar_936 = (cppVar_933) ? 1 : 4;
	bool cppVar_938 = (sha_state == 2);
	bool cppVar_941 = (sha_state == 1);
	BIT_VEC cppVar_943 = (cppVar_941) ? 2 : sha_state;
	BIT_VEC cppVar_944 = (cppVar_938) ? 3 : cppVar_943;
	BIT_VEC cppVar_945 = (cppVar_932) ? cppVar_936 : cppVar_944;
	BIT_VEC cppVar_946 = (cppVar_929) ? 0 : cppVar_945;
	bool cppVar_947 = cppVar_283 || cppVar_336;
	bool cppVar_948 = cppVar_238 || cppVar_947;
	bool cppVar_949 = cppVar_193 || cppVar_948;
	bool cppVar_950 = cppVar_148 || cppVar_949;
	bool cppVar_951 = cppVar_103 || cppVar_950;
	bool cppVar_952 = cppVar_58 || cppVar_951;
	bool cppVar_953 = cppVar_787 || cppVar_952;
	bool cppVar_954 = cppVar_755 || cppVar_953;
	bool cppVar_955 = cppVar_715 || cppVar_954;
	bool cppVar_956 = cppVar_675 || cppVar_955;
	bool cppVar_957 = cppVar_635 || cppVar_956;
	bool cppVar_958 = cppVar_595 || cppVar_957;
	bool cppVar_959 = cppVar_555 || cppVar_958;
	bool cppVar_960 = cppVar_515 || cppVar_959;
	bool cppVar_961 = cppVar_483 || cppVar_960;
	bool cppVar_963 = (cmddata == 1);
	BIT_VEC cppVar_965 = (cppVar_963) ? 1 : sha_state;
	BIT_VEC cppVar_966 = (cppVar_961) ? cppVar_965 : sha_state;
	BIT_VEC cppVar_967 = (cppVar_927) ? cppVar_946 : cppVar_966;
	BIT_VEC cppVar_968 = (sha_wraddr >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_969 = (cmddata << 8) | cppVar_968;
	cppVar_969 = (cppVar_969 & cppMask_un_16_);
	BIT_VEC cppVar_970 = (sha_wraddr >> 8) & cppMask_un_8_;
	BIT_VEC cppVar_971 = (cppVar_970 << 8) | cmddata;
	cppVar_971 = (cppVar_971 & cppMask_un_16_);
	BIT_VEC cppVar_972 = (cppVar_451) ? cppVar_971 : sha_wraddr;
	BIT_VEC cppVar_973 = (cppVar_443) ? cppVar_969 : cppVar_972;
	BIT_VEC cppVar_976;
	type_mem cppVar_974 = XRAM;
	for (int cppVar_975 = 0; cppVar_975 < 20; cppVar_975++) {
		cppVar_976 = sha_hs_data >> ((20 - 1 - cppVar_975) * 8);
		cppVar_974.wr(sha_wraddr + cppVar_975, cppVar_976);
	}
	type_mem& cppVar_977 = (cppVar_929) ? cppVar_974 : XRAM;
	type_mem& cppVar_978 = (cppVar_927) ? cppVar_977 : XRAM;
	BIT_VEC cppVar_980 = sha_bytes_read + 64;
	cppVar_980 = (cppVar_980 & cppMask_un_16_);
	BIT_VEC cppVar_981 = (cppVar_941) ? cppVar_980 : sha_bytes_read;
	BIT_VEC cppVar_982 = (cppVar_927) ? cppVar_981 : sha_bytes_read;
	BIT_VEC cppVar_983 = sha(sha_rd_data);
	BIT_VEC cppVar_984 = (cppVar_932) ? cppVar_983 : sha_hs_data;
	BIT_VEC cppVar_985 = (cppVar_927) ? cppVar_984 : sha_hs_data;
	BIT_VEC cppVar_986 = sha_rdaddr + sha_bytes_read;
	cppVar_986 = (cppVar_986 & cppMask_un_16_);
	BIT_VEC cppVar_987 = (XRAM.rd(cppVar_986) & cppMask_un_8_);
	for (int cppVar_988 = 1; cppVar_988 < 64; cppVar_988++) {
		cppVar_987 = (cppVar_987 << 8) | (XRAM.rd(cppVar_986 + cppVar_988) & cppMask_un_8_);
	}
	cppVar_987 = (cppVar_987 & cppMask_un_512_);
	BIT_VEC cppVar_989 = (cppVar_941) ? cppVar_987 : sha_rd_data;
	BIT_VEC cppVar_990 = (cppVar_927) ? cppVar_989 : sha_rd_data;
	dataout = cppVar_913;
	sha_len = cppVar_919;
	sha_rdaddr = cppVar_925;
	sha_state = cppVar_967;
	sha_wraddr = cppVar_973;
	XRAM = cppVar_978;
	sha_bytes_read = cppVar_982;
	sha_hs_data = cppVar_985;
	sha_rd_data = cppVar_990;
	return;
}

/****************************************************/
/****************************************************/
#endif
/****************************************************/
