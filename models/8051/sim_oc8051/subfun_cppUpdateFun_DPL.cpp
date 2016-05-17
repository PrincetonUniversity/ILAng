#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_DPL()
{
	BIT_VEC cppVar_9950;
	BIT_VEC cppVar_9951 = ROM.rd(PC);
	bool cppVar_9953 = (cppVar_9951 == 208);
	if (cppVar_9953) {
	BIT_VEC cppVar_9954;
	BIT_VEC cppVar_9956 = PC + 1;
	cppVar_9956 = (cppVar_9956 & cppMask_un_16_);
	BIT_VEC cppVar_9957 = ROM.rd(cppVar_9956);
	bool cppVar_9959 = (cppVar_9957 == 130);
	if (cppVar_9959) {
	BIT_VEC cppVar_9960 = IRAM.rd(SP);
	cppVar_9954 = cppVar_9960;
	} else {
	cppVar_9954 = DPL;
	}
	cppVar_9950 = cppVar_9954;
	} else {
	BIT_VEC cppVar_9961;
	BIT_VEC cppVar_9962 = ROM.rd(PC);
	bool cppVar_9964 = (cppVar_9962 == 245);
	BIT_VEC cppVar_9965 = ROM.rd(PC);
	bool cppVar_9967 = (cppVar_9965 == 197);
	bool cppVar_9968 = cppVar_9964 || cppVar_9967;
	if (cppVar_9968) {
	BIT_VEC cppVar_9969;
	BIT_VEC cppVar_9971 = PC + 1;
	cppVar_9971 = (cppVar_9971 & cppMask_un_16_);
	BIT_VEC cppVar_9972 = ROM.rd(cppVar_9971);
	bool cppVar_9974 = (cppVar_9972 == 130);
	if (cppVar_9974) {
	cppVar_9969 = ACC;
	} else {
	cppVar_9969 = DPL;
	}
	cppVar_9961 = cppVar_9969;
	} else {
	BIT_VEC cppVar_9975;
	BIT_VEC cppVar_9976 = ROM.rd(PC);
	bool cppVar_9978 = (cppVar_9976 == 163);
	if (cppVar_9978) {
	BIT_VEC cppVar_9979;
	BIT_VEC cppVar_9981 = PC + 2;
	cppVar_9981 = (cppVar_9981 & cppMask_un_16_);
	BIT_VEC cppVar_9982 = ROM.rd(cppVar_9981);
	bool cppVar_9984 = (cppVar_9982 == 130);
	if (cppVar_9984) {
	BIT_VEC cppVar_9985;
	BIT_VEC cppVar_9986 = PC + 2;
	cppVar_9986 = (cppVar_9986 & cppMask_un_16_);
	BIT_VEC cppVar_9987 = ROM.rd(cppVar_9986);
	BIT_VEC cppVar_9988 = (cppVar_9987 >> 7) & cppMask_un_1_;
	bool cppVar_9990 = (cppVar_9988 == 0);
	if (cppVar_9990) {
	BIT_VEC cppVar_9991 = PC + 2;
	cppVar_9991 = (cppVar_9991 & cppMask_un_16_);
	BIT_VEC cppVar_9992 = ROM.rd(cppVar_9991);
	BIT_VEC cppVar_9993 = IRAM.rd(cppVar_9992);
	cppVar_9985 = cppVar_9993;
	} else {
	BIT_VEC cppVar_9994;
	BIT_VEC cppVar_9995 = PC + 2;
	cppVar_9995 = (cppVar_9995 & cppMask_un_16_);
	BIT_VEC cppVar_9996 = ROM.rd(cppVar_9995);
	bool cppVar_9998 = (cppVar_9996 == 128);
	if (cppVar_9998) {
	cppVar_9994 = P0;
	} else {
	BIT_VEC cppVar_9999;
	BIT_VEC cppVar_10000 = PC + 2;
	cppVar_10000 = (cppVar_10000 & cppMask_un_16_);
	BIT_VEC cppVar_10001 = ROM.rd(cppVar_10000);
	bool cppVar_10003 = (cppVar_10001 == 129);
	if (cppVar_10003) {
	cppVar_9999 = SP;
	} else {
	BIT_VEC cppVar_10004;
	BIT_VEC cppVar_10005 = PC + 2;
	cppVar_10005 = (cppVar_10005 & cppMask_un_16_);
	BIT_VEC cppVar_10006 = ROM.rd(cppVar_10005);
	bool cppVar_10008 = (cppVar_10006 == 130);
	if (cppVar_10008) {
	cppVar_10004 = DPL;
	} else {
	BIT_VEC cppVar_10009;
	BIT_VEC cppVar_10010 = PC + 2;
	cppVar_10010 = (cppVar_10010 & cppMask_un_16_);
	BIT_VEC cppVar_10011 = ROM.rd(cppVar_10010);
	bool cppVar_10013 = (cppVar_10011 == 131);
	if (cppVar_10013) {
	cppVar_10009 = DPH;
	} else {
	BIT_VEC cppVar_10014;
	BIT_VEC cppVar_10015 = PC + 2;
	cppVar_10015 = (cppVar_10015 & cppMask_un_16_);
	BIT_VEC cppVar_10016 = ROM.rd(cppVar_10015);
	bool cppVar_10018 = (cppVar_10016 == 135);
	if (cppVar_10018) {
	cppVar_10014 = PCON;
	} else {
	BIT_VEC cppVar_10019;
	BIT_VEC cppVar_10020 = PC + 2;
	cppVar_10020 = (cppVar_10020 & cppMask_un_16_);
	BIT_VEC cppVar_10021 = ROM.rd(cppVar_10020);
	bool cppVar_10023 = (cppVar_10021 == 136);
	if (cppVar_10023) {
	cppVar_10019 = TCON;
	} else {
	BIT_VEC cppVar_10024;
	BIT_VEC cppVar_10025 = PC + 2;
	cppVar_10025 = (cppVar_10025 & cppMask_un_16_);
	BIT_VEC cppVar_10026 = ROM.rd(cppVar_10025);
	bool cppVar_10028 = (cppVar_10026 == 137);
	if (cppVar_10028) {
	cppVar_10024 = TMOD;
	} else {
	BIT_VEC cppVar_10029;
	BIT_VEC cppVar_10030 = PC + 2;
	cppVar_10030 = (cppVar_10030 & cppMask_un_16_);
	BIT_VEC cppVar_10031 = ROM.rd(cppVar_10030);
	bool cppVar_10033 = (cppVar_10031 == 138);
	if (cppVar_10033) {
	cppVar_10029 = TL0;
	} else {
	BIT_VEC cppVar_10034;
	BIT_VEC cppVar_10035 = PC + 2;
	cppVar_10035 = (cppVar_10035 & cppMask_un_16_);
	BIT_VEC cppVar_10036 = ROM.rd(cppVar_10035);
	bool cppVar_10038 = (cppVar_10036 == 140);
	if (cppVar_10038) {
	cppVar_10034 = TH0;
	} else {
	BIT_VEC cppVar_10039;
	BIT_VEC cppVar_10040 = PC + 2;
	cppVar_10040 = (cppVar_10040 & cppMask_un_16_);
	BIT_VEC cppVar_10041 = ROM.rd(cppVar_10040);
	bool cppVar_10043 = (cppVar_10041 == 139);
	if (cppVar_10043) {
	cppVar_10039 = TL1;
	} else {
	BIT_VEC cppVar_10044;
	BIT_VEC cppVar_10045 = PC + 2;
	cppVar_10045 = (cppVar_10045 & cppMask_un_16_);
	BIT_VEC cppVar_10046 = ROM.rd(cppVar_10045);
	bool cppVar_10048 = (cppVar_10046 == 141);
	if (cppVar_10048) {
	cppVar_10044 = TH1;
	} else {
	BIT_VEC cppVar_10049;
	BIT_VEC cppVar_10050 = PC + 2;
	cppVar_10050 = (cppVar_10050 & cppMask_un_16_);
	BIT_VEC cppVar_10051 = ROM.rd(cppVar_10050);
	bool cppVar_10053 = (cppVar_10051 == 144);
	if (cppVar_10053) {
	cppVar_10049 = P1;
	} else {
	BIT_VEC cppVar_10054;
	BIT_VEC cppVar_10055 = PC + 2;
	cppVar_10055 = (cppVar_10055 & cppMask_un_16_);
	BIT_VEC cppVar_10056 = ROM.rd(cppVar_10055);
	bool cppVar_10058 = (cppVar_10056 == 152);
	if (cppVar_10058) {
	cppVar_10054 = SCON;
	} else {
	BIT_VEC cppVar_10059;
	BIT_VEC cppVar_10060 = PC + 2;
	cppVar_10060 = (cppVar_10060 & cppMask_un_16_);
	BIT_VEC cppVar_10061 = ROM.rd(cppVar_10060);
	bool cppVar_10063 = (cppVar_10061 == 153);
	if (cppVar_10063) {
	cppVar_10059 = SBUF;
	} else {
	BIT_VEC cppVar_10064;
	BIT_VEC cppVar_10065 = PC + 2;
	cppVar_10065 = (cppVar_10065 & cppMask_un_16_);
	BIT_VEC cppVar_10066 = ROM.rd(cppVar_10065);
	bool cppVar_10068 = (cppVar_10066 == 160);
	if (cppVar_10068) {
	cppVar_10064 = P2;
	} else {
	BIT_VEC cppVar_10069;
	BIT_VEC cppVar_10070 = PC + 2;
	cppVar_10070 = (cppVar_10070 & cppMask_un_16_);
	BIT_VEC cppVar_10071 = ROM.rd(cppVar_10070);
	bool cppVar_10073 = (cppVar_10071 == 168);
	if (cppVar_10073) {
	cppVar_10069 = IE;
	} else {
	BIT_VEC cppVar_10074;
	BIT_VEC cppVar_10075 = PC + 2;
	cppVar_10075 = (cppVar_10075 & cppMask_un_16_);
	BIT_VEC cppVar_10076 = ROM.rd(cppVar_10075);
	bool cppVar_10078 = (cppVar_10076 == 176);
	if (cppVar_10078) {
	cppVar_10074 = P3;
	} else {
	BIT_VEC cppVar_10079;
	BIT_VEC cppVar_10080 = PC + 2;
	cppVar_10080 = (cppVar_10080 & cppMask_un_16_);
	BIT_VEC cppVar_10081 = ROM.rd(cppVar_10080);
	bool cppVar_10083 = (cppVar_10081 == 184);
	if (cppVar_10083) {
	cppVar_10079 = IP;
	} else {
	BIT_VEC cppVar_10084;
	BIT_VEC cppVar_10085 = PC + 2;
	cppVar_10085 = (cppVar_10085 & cppMask_un_16_);
	BIT_VEC cppVar_10086 = ROM.rd(cppVar_10085);
	bool cppVar_10088 = (cppVar_10086 == 208);
	if (cppVar_10088) {
	cppVar_10084 = PSW;
	} else {
	BIT_VEC cppVar_10089;
	BIT_VEC cppVar_10090 = PC + 2;
	cppVar_10090 = (cppVar_10090 & cppMask_un_16_);
	BIT_VEC cppVar_10091 = ROM.rd(cppVar_10090);
	bool cppVar_10093 = (cppVar_10091 == 224);
	if (cppVar_10093) {
	cppVar_10089 = ACC;
	} else {
	BIT_VEC cppVar_10094;
	BIT_VEC cppVar_10095 = PC + 2;
	cppVar_10095 = (cppVar_10095 & cppMask_un_16_);
	BIT_VEC cppVar_10096 = ROM.rd(cppVar_10095);
	bool cppVar_10098 = (cppVar_10096 == 240);
	if (cppVar_10098) {
	cppVar_10094 = B;
	} else {
	cppVar_10094 = 0;
	}
	cppVar_10089 = cppVar_10094;
	}
	cppVar_10084 = cppVar_10089;
	}
	cppVar_10079 = cppVar_10084;
	}
	cppVar_10074 = cppVar_10079;
	}
	cppVar_10069 = cppVar_10074;
	}
	cppVar_10064 = cppVar_10069;
	}
	cppVar_10059 = cppVar_10064;
	}
	cppVar_10054 = cppVar_10059;
	}
	cppVar_10049 = cppVar_10054;
	}
	cppVar_10044 = cppVar_10049;
	}
	cppVar_10039 = cppVar_10044;
	}
	cppVar_10034 = cppVar_10039;
	}
	cppVar_10029 = cppVar_10034;
	}
	cppVar_10024 = cppVar_10029;
	}
	cppVar_10019 = cppVar_10024;
	}
	cppVar_10014 = cppVar_10019;
	}
	cppVar_10009 = cppVar_10014;
	}
	cppVar_10004 = cppVar_10009;
	}
	cppVar_9999 = cppVar_10004;
	}
	cppVar_9994 = cppVar_9999;
	}
	cppVar_9985 = cppVar_9994;
	}
	BIT_VEC cppVar_10101 = cppVar_9985 + 1;
	cppVar_10101 = (cppVar_10101 & cppMask_un_8_);
	cppVar_9979 = cppVar_10101;
	} else {
	cppVar_9979 = DPL;
	}
	cppVar_9975 = cppVar_9979;
	} else {
	BIT_VEC cppVar_10102;
	BIT_VEC cppVar_10103 = ROM.rd(PC);
	bool cppVar_10105 = (cppVar_10103 == 144);
	if (cppVar_10105) {
	BIT_VEC cppVar_10106;
	BIT_VEC cppVar_10108 = PC + 2;
	cppVar_10108 = (cppVar_10108 & cppMask_un_16_);
	BIT_VEC cppVar_10109 = ROM.rd(cppVar_10108);
	bool cppVar_10111 = (cppVar_10109 == 130);
	if (cppVar_10111) {
	BIT_VEC cppVar_10112 = PC + 2;
	cppVar_10112 = (cppVar_10112 & cppMask_un_16_);
	BIT_VEC cppVar_10113 = ROM.rd(cppVar_10112);
	cppVar_10106 = cppVar_10113;
	} else {
	cppVar_10106 = DPL;
	}
	cppVar_10102 = cppVar_10106;
	} else {
	BIT_VEC cppVar_10114;
	BIT_VEC cppVar_10115 = ROM.rd(PC);
	bool cppVar_10117 = (cppVar_10115 == 143);
	if (cppVar_10117) {
	BIT_VEC cppVar_10118;
	BIT_VEC cppVar_10120 = PC + 1;
	cppVar_10120 = (cppVar_10120 & cppMask_un_16_);
	BIT_VEC cppVar_10121 = ROM.rd(cppVar_10120);
	bool cppVar_10123 = (cppVar_10121 == 130);
	if (cppVar_10123) {
	BIT_VEC cppVar_10124;
	BIT_VEC cppVar_10126 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10128 = (cppVar_10126 << 3) | 7;
	cppVar_10128 = (cppVar_10128 & cppMask_un_5_);
	BIT_VEC cppVar_10129 = (0 << 5) | cppVar_10128;
	cppVar_10129 = (cppVar_10129 & cppMask_un_8_);
	BIT_VEC cppVar_10130 = (cppVar_10129 >> 7) & cppMask_un_1_;
	bool cppVar_10132 = (cppVar_10130 == 0);
	if (cppVar_10132) {
	BIT_VEC cppVar_10133 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10134 = (cppVar_10133 << 3) | 7;
	cppVar_10134 = (cppVar_10134 & cppMask_un_5_);
	BIT_VEC cppVar_10135 = (0 << 5) | cppVar_10134;
	cppVar_10135 = (cppVar_10135 & cppMask_un_8_);
	BIT_VEC cppVar_10136 = IRAM.rd(cppVar_10135);
	cppVar_10124 = cppVar_10136;
	} else {
	BIT_VEC cppVar_10137;
	BIT_VEC cppVar_10138 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10139 = (cppVar_10138 << 3) | 7;
	cppVar_10139 = (cppVar_10139 & cppMask_un_5_);
	BIT_VEC cppVar_10140 = (0 << 5) | cppVar_10139;
	cppVar_10140 = (cppVar_10140 & cppMask_un_8_);
	bool cppVar_10142 = (cppVar_10140 == 128);
	if (cppVar_10142) {
	cppVar_10137 = P0;
	} else {
	BIT_VEC cppVar_10143;
	BIT_VEC cppVar_10144 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10145 = (cppVar_10144 << 3) | 7;
	cppVar_10145 = (cppVar_10145 & cppMask_un_5_);
	BIT_VEC cppVar_10146 = (0 << 5) | cppVar_10145;
	cppVar_10146 = (cppVar_10146 & cppMask_un_8_);
	bool cppVar_10148 = (cppVar_10146 == 129);
	if (cppVar_10148) {
	cppVar_10143 = SP;
	} else {
	BIT_VEC cppVar_10149;
	BIT_VEC cppVar_10150 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10151 = (cppVar_10150 << 3) | 7;
	cppVar_10151 = (cppVar_10151 & cppMask_un_5_);
	BIT_VEC cppVar_10152 = (0 << 5) | cppVar_10151;
	cppVar_10152 = (cppVar_10152 & cppMask_un_8_);
	bool cppVar_10154 = (cppVar_10152 == 130);
	if (cppVar_10154) {
	cppVar_10149 = DPL;
	} else {
	BIT_VEC cppVar_10155;
	BIT_VEC cppVar_10156 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10157 = (cppVar_10156 << 3) | 7;
	cppVar_10157 = (cppVar_10157 & cppMask_un_5_);
	BIT_VEC cppVar_10158 = (0 << 5) | cppVar_10157;
	cppVar_10158 = (cppVar_10158 & cppMask_un_8_);
	bool cppVar_10160 = (cppVar_10158 == 131);
	if (cppVar_10160) {
	cppVar_10155 = DPH;
	} else {
	BIT_VEC cppVar_10161;
	BIT_VEC cppVar_10162 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10163 = (cppVar_10162 << 3) | 7;
	cppVar_10163 = (cppVar_10163 & cppMask_un_5_);
	BIT_VEC cppVar_10164 = (0 << 5) | cppVar_10163;
	cppVar_10164 = (cppVar_10164 & cppMask_un_8_);
	bool cppVar_10166 = (cppVar_10164 == 135);
	if (cppVar_10166) {
	cppVar_10161 = PCON;
	} else {
	BIT_VEC cppVar_10167;
	BIT_VEC cppVar_10168 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10169 = (cppVar_10168 << 3) | 7;
	cppVar_10169 = (cppVar_10169 & cppMask_un_5_);
	BIT_VEC cppVar_10170 = (0 << 5) | cppVar_10169;
	cppVar_10170 = (cppVar_10170 & cppMask_un_8_);
	bool cppVar_10172 = (cppVar_10170 == 136);
	if (cppVar_10172) {
	cppVar_10167 = TCON;
	} else {
	BIT_VEC cppVar_10173;
	BIT_VEC cppVar_10174 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10175 = (cppVar_10174 << 3) | 7;
	cppVar_10175 = (cppVar_10175 & cppMask_un_5_);
	BIT_VEC cppVar_10176 = (0 << 5) | cppVar_10175;
	cppVar_10176 = (cppVar_10176 & cppMask_un_8_);
	bool cppVar_10178 = (cppVar_10176 == 137);
	if (cppVar_10178) {
	cppVar_10173 = TMOD;
	} else {
	BIT_VEC cppVar_10179;
	BIT_VEC cppVar_10180 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10181 = (cppVar_10180 << 3) | 7;
	cppVar_10181 = (cppVar_10181 & cppMask_un_5_);
	BIT_VEC cppVar_10182 = (0 << 5) | cppVar_10181;
	cppVar_10182 = (cppVar_10182 & cppMask_un_8_);
	bool cppVar_10184 = (cppVar_10182 == 138);
	if (cppVar_10184) {
	cppVar_10179 = TL0;
	} else {
	BIT_VEC cppVar_10185;
	BIT_VEC cppVar_10186 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10187 = (cppVar_10186 << 3) | 7;
	cppVar_10187 = (cppVar_10187 & cppMask_un_5_);
	BIT_VEC cppVar_10188 = (0 << 5) | cppVar_10187;
	cppVar_10188 = (cppVar_10188 & cppMask_un_8_);
	bool cppVar_10190 = (cppVar_10188 == 140);
	if (cppVar_10190) {
	cppVar_10185 = TH0;
	} else {
	BIT_VEC cppVar_10191;
	BIT_VEC cppVar_10192 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10193 = (cppVar_10192 << 3) | 7;
	cppVar_10193 = (cppVar_10193 & cppMask_un_5_);
	BIT_VEC cppVar_10194 = (0 << 5) | cppVar_10193;
	cppVar_10194 = (cppVar_10194 & cppMask_un_8_);
	bool cppVar_10196 = (cppVar_10194 == 139);
	if (cppVar_10196) {
	cppVar_10191 = TL1;
	} else {
	BIT_VEC cppVar_10197;
	BIT_VEC cppVar_10198 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10199 = (cppVar_10198 << 3) | 7;
	cppVar_10199 = (cppVar_10199 & cppMask_un_5_);
	BIT_VEC cppVar_10200 = (0 << 5) | cppVar_10199;
	cppVar_10200 = (cppVar_10200 & cppMask_un_8_);
	bool cppVar_10202 = (cppVar_10200 == 141);
	if (cppVar_10202) {
	cppVar_10197 = TH1;
	} else {
	BIT_VEC cppVar_10203;
	BIT_VEC cppVar_10204 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10205 = (cppVar_10204 << 3) | 7;
	cppVar_10205 = (cppVar_10205 & cppMask_un_5_);
	BIT_VEC cppVar_10206 = (0 << 5) | cppVar_10205;
	cppVar_10206 = (cppVar_10206 & cppMask_un_8_);
	bool cppVar_10208 = (cppVar_10206 == 144);
	if (cppVar_10208) {
	cppVar_10203 = P1;
	} else {
	BIT_VEC cppVar_10209;
	BIT_VEC cppVar_10210 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10211 = (cppVar_10210 << 3) | 7;
	cppVar_10211 = (cppVar_10211 & cppMask_un_5_);
	BIT_VEC cppVar_10212 = (0 << 5) | cppVar_10211;
	cppVar_10212 = (cppVar_10212 & cppMask_un_8_);
	bool cppVar_10214 = (cppVar_10212 == 152);
	if (cppVar_10214) {
	cppVar_10209 = SCON;
	} else {
	BIT_VEC cppVar_10215;
	BIT_VEC cppVar_10216 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10217 = (cppVar_10216 << 3) | 7;
	cppVar_10217 = (cppVar_10217 & cppMask_un_5_);
	BIT_VEC cppVar_10218 = (0 << 5) | cppVar_10217;
	cppVar_10218 = (cppVar_10218 & cppMask_un_8_);
	bool cppVar_10220 = (cppVar_10218 == 153);
	if (cppVar_10220) {
	cppVar_10215 = SBUF;
	} else {
	BIT_VEC cppVar_10221;
	BIT_VEC cppVar_10222 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10223 = (cppVar_10222 << 3) | 7;
	cppVar_10223 = (cppVar_10223 & cppMask_un_5_);
	BIT_VEC cppVar_10224 = (0 << 5) | cppVar_10223;
	cppVar_10224 = (cppVar_10224 & cppMask_un_8_);
	bool cppVar_10226 = (cppVar_10224 == 160);
	if (cppVar_10226) {
	cppVar_10221 = P2;
	} else {
	BIT_VEC cppVar_10227;
	BIT_VEC cppVar_10228 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10229 = (cppVar_10228 << 3) | 7;
	cppVar_10229 = (cppVar_10229 & cppMask_un_5_);
	BIT_VEC cppVar_10230 = (0 << 5) | cppVar_10229;
	cppVar_10230 = (cppVar_10230 & cppMask_un_8_);
	bool cppVar_10232 = (cppVar_10230 == 168);
	if (cppVar_10232) {
	cppVar_10227 = IE;
	} else {
	BIT_VEC cppVar_10233;
	BIT_VEC cppVar_10234 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10235 = (cppVar_10234 << 3) | 7;
	cppVar_10235 = (cppVar_10235 & cppMask_un_5_);
	BIT_VEC cppVar_10236 = (0 << 5) | cppVar_10235;
	cppVar_10236 = (cppVar_10236 & cppMask_un_8_);
	bool cppVar_10238 = (cppVar_10236 == 176);
	if (cppVar_10238) {
	cppVar_10233 = P3;
	} else {
	BIT_VEC cppVar_10239;
	BIT_VEC cppVar_10240 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10241 = (cppVar_10240 << 3) | 7;
	cppVar_10241 = (cppVar_10241 & cppMask_un_5_);
	BIT_VEC cppVar_10242 = (0 << 5) | cppVar_10241;
	cppVar_10242 = (cppVar_10242 & cppMask_un_8_);
	bool cppVar_10244 = (cppVar_10242 == 184);
	if (cppVar_10244) {
	cppVar_10239 = IP;
	} else {
	BIT_VEC cppVar_10245;
	BIT_VEC cppVar_10246 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10247 = (cppVar_10246 << 3) | 7;
	cppVar_10247 = (cppVar_10247 & cppMask_un_5_);
	BIT_VEC cppVar_10248 = (0 << 5) | cppVar_10247;
	cppVar_10248 = (cppVar_10248 & cppMask_un_8_);
	bool cppVar_10250 = (cppVar_10248 == 208);
	if (cppVar_10250) {
	cppVar_10245 = PSW;
	} else {
	BIT_VEC cppVar_10251;
	BIT_VEC cppVar_10252 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10253 = (cppVar_10252 << 3) | 7;
	cppVar_10253 = (cppVar_10253 & cppMask_un_5_);
	BIT_VEC cppVar_10254 = (0 << 5) | cppVar_10253;
	cppVar_10254 = (cppVar_10254 & cppMask_un_8_);
	bool cppVar_10256 = (cppVar_10254 == 224);
	if (cppVar_10256) {
	cppVar_10251 = ACC;
	} else {
	BIT_VEC cppVar_10257;
	BIT_VEC cppVar_10258 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10259 = (cppVar_10258 << 3) | 7;
	cppVar_10259 = (cppVar_10259 & cppMask_un_5_);
	BIT_VEC cppVar_10260 = (0 << 5) | cppVar_10259;
	cppVar_10260 = (cppVar_10260 & cppMask_un_8_);
	bool cppVar_10262 = (cppVar_10260 == 240);
	if (cppVar_10262) {
	cppVar_10257 = B;
	} else {
	cppVar_10257 = 0;
	}
	cppVar_10251 = cppVar_10257;
	}
	cppVar_10245 = cppVar_10251;
	}
	cppVar_10239 = cppVar_10245;
	}
	cppVar_10233 = cppVar_10239;
	}
	cppVar_10227 = cppVar_10233;
	}
	cppVar_10221 = cppVar_10227;
	}
	cppVar_10215 = cppVar_10221;
	}
	cppVar_10209 = cppVar_10215;
	}
	cppVar_10203 = cppVar_10209;
	}
	cppVar_10197 = cppVar_10203;
	}
	cppVar_10191 = cppVar_10197;
	}
	cppVar_10185 = cppVar_10191;
	}
	cppVar_10179 = cppVar_10185;
	}
	cppVar_10173 = cppVar_10179;
	}
	cppVar_10167 = cppVar_10173;
	}
	cppVar_10161 = cppVar_10167;
	}
	cppVar_10155 = cppVar_10161;
	}
	cppVar_10149 = cppVar_10155;
	}
	cppVar_10143 = cppVar_10149;
	}
	cppVar_10137 = cppVar_10143;
	}
	cppVar_10124 = cppVar_10137;
	}
	cppVar_10118 = cppVar_10124;
	} else {
	cppVar_10118 = DPL;
	}
	cppVar_10114 = cppVar_10118;
	} else {
	BIT_VEC cppVar_10264;
	BIT_VEC cppVar_10265 = ROM.rd(PC);
	bool cppVar_10267 = (cppVar_10265 == 142);
	if (cppVar_10267) {
	BIT_VEC cppVar_10268;
	BIT_VEC cppVar_10270 = PC + 1;
	cppVar_10270 = (cppVar_10270 & cppMask_un_16_);
	BIT_VEC cppVar_10271 = ROM.rd(cppVar_10270);
	bool cppVar_10273 = (cppVar_10271 == 130);
	if (cppVar_10273) {
	BIT_VEC cppVar_10274;
	BIT_VEC cppVar_10276 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10278 = (cppVar_10276 << 3) | 6;
	cppVar_10278 = (cppVar_10278 & cppMask_un_5_);
	BIT_VEC cppVar_10279 = (0 << 5) | cppVar_10278;
	cppVar_10279 = (cppVar_10279 & cppMask_un_8_);
	BIT_VEC cppVar_10280 = (cppVar_10279 >> 7) & cppMask_un_1_;
	bool cppVar_10282 = (cppVar_10280 == 0);
	if (cppVar_10282) {
	BIT_VEC cppVar_10283 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10284 = (cppVar_10283 << 3) | 6;
	cppVar_10284 = (cppVar_10284 & cppMask_un_5_);
	BIT_VEC cppVar_10285 = (0 << 5) | cppVar_10284;
	cppVar_10285 = (cppVar_10285 & cppMask_un_8_);
	BIT_VEC cppVar_10286 = IRAM.rd(cppVar_10285);
	cppVar_10274 = cppVar_10286;
	} else {
	BIT_VEC cppVar_10287;
	BIT_VEC cppVar_10288 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10289 = (cppVar_10288 << 3) | 6;
	cppVar_10289 = (cppVar_10289 & cppMask_un_5_);
	BIT_VEC cppVar_10290 = (0 << 5) | cppVar_10289;
	cppVar_10290 = (cppVar_10290 & cppMask_un_8_);
	bool cppVar_10292 = (cppVar_10290 == 128);
	if (cppVar_10292) {
	cppVar_10287 = P0;
	} else {
	BIT_VEC cppVar_10293;
	BIT_VEC cppVar_10294 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10295 = (cppVar_10294 << 3) | 6;
	cppVar_10295 = (cppVar_10295 & cppMask_un_5_);
	BIT_VEC cppVar_10296 = (0 << 5) | cppVar_10295;
	cppVar_10296 = (cppVar_10296 & cppMask_un_8_);
	bool cppVar_10298 = (cppVar_10296 == 129);
	if (cppVar_10298) {
	cppVar_10293 = SP;
	} else {
	BIT_VEC cppVar_10299;
	BIT_VEC cppVar_10300 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10301 = (cppVar_10300 << 3) | 6;
	cppVar_10301 = (cppVar_10301 & cppMask_un_5_);
	BIT_VEC cppVar_10302 = (0 << 5) | cppVar_10301;
	cppVar_10302 = (cppVar_10302 & cppMask_un_8_);
	bool cppVar_10304 = (cppVar_10302 == 130);
	if (cppVar_10304) {
	cppVar_10299 = DPL;
	} else {
	BIT_VEC cppVar_10305;
	BIT_VEC cppVar_10306 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10307 = (cppVar_10306 << 3) | 6;
	cppVar_10307 = (cppVar_10307 & cppMask_un_5_);
	BIT_VEC cppVar_10308 = (0 << 5) | cppVar_10307;
	cppVar_10308 = (cppVar_10308 & cppMask_un_8_);
	bool cppVar_10310 = (cppVar_10308 == 131);
	if (cppVar_10310) {
	cppVar_10305 = DPH;
	} else {
	BIT_VEC cppVar_10311;
	BIT_VEC cppVar_10312 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10313 = (cppVar_10312 << 3) | 6;
	cppVar_10313 = (cppVar_10313 & cppMask_un_5_);
	BIT_VEC cppVar_10314 = (0 << 5) | cppVar_10313;
	cppVar_10314 = (cppVar_10314 & cppMask_un_8_);
	bool cppVar_10316 = (cppVar_10314 == 135);
	if (cppVar_10316) {
	cppVar_10311 = PCON;
	} else {
	BIT_VEC cppVar_10317;
	BIT_VEC cppVar_10318 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10319 = (cppVar_10318 << 3) | 6;
	cppVar_10319 = (cppVar_10319 & cppMask_un_5_);
	BIT_VEC cppVar_10320 = (0 << 5) | cppVar_10319;
	cppVar_10320 = (cppVar_10320 & cppMask_un_8_);
	bool cppVar_10322 = (cppVar_10320 == 136);
	if (cppVar_10322) {
	cppVar_10317 = TCON;
	} else {
	BIT_VEC cppVar_10323;
	BIT_VEC cppVar_10324 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10325 = (cppVar_10324 << 3) | 6;
	cppVar_10325 = (cppVar_10325 & cppMask_un_5_);
	BIT_VEC cppVar_10326 = (0 << 5) | cppVar_10325;
	cppVar_10326 = (cppVar_10326 & cppMask_un_8_);
	bool cppVar_10328 = (cppVar_10326 == 137);
	if (cppVar_10328) {
	cppVar_10323 = TMOD;
	} else {
	BIT_VEC cppVar_10329;
	BIT_VEC cppVar_10330 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10331 = (cppVar_10330 << 3) | 6;
	cppVar_10331 = (cppVar_10331 & cppMask_un_5_);
	BIT_VEC cppVar_10332 = (0 << 5) | cppVar_10331;
	cppVar_10332 = (cppVar_10332 & cppMask_un_8_);
	bool cppVar_10334 = (cppVar_10332 == 138);
	if (cppVar_10334) {
	cppVar_10329 = TL0;
	} else {
	BIT_VEC cppVar_10335;
	BIT_VEC cppVar_10336 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10337 = (cppVar_10336 << 3) | 6;
	cppVar_10337 = (cppVar_10337 & cppMask_un_5_);
	BIT_VEC cppVar_10338 = (0 << 5) | cppVar_10337;
	cppVar_10338 = (cppVar_10338 & cppMask_un_8_);
	bool cppVar_10340 = (cppVar_10338 == 140);
	if (cppVar_10340) {
	cppVar_10335 = TH0;
	} else {
	BIT_VEC cppVar_10341;
	BIT_VEC cppVar_10342 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10343 = (cppVar_10342 << 3) | 6;
	cppVar_10343 = (cppVar_10343 & cppMask_un_5_);
	BIT_VEC cppVar_10344 = (0 << 5) | cppVar_10343;
	cppVar_10344 = (cppVar_10344 & cppMask_un_8_);
	bool cppVar_10346 = (cppVar_10344 == 139);
	if (cppVar_10346) {
	cppVar_10341 = TL1;
	} else {
	BIT_VEC cppVar_10347;
	BIT_VEC cppVar_10348 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10349 = (cppVar_10348 << 3) | 6;
	cppVar_10349 = (cppVar_10349 & cppMask_un_5_);
	BIT_VEC cppVar_10350 = (0 << 5) | cppVar_10349;
	cppVar_10350 = (cppVar_10350 & cppMask_un_8_);
	bool cppVar_10352 = (cppVar_10350 == 141);
	if (cppVar_10352) {
	cppVar_10347 = TH1;
	} else {
	BIT_VEC cppVar_10353;
	BIT_VEC cppVar_10354 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10355 = (cppVar_10354 << 3) | 6;
	cppVar_10355 = (cppVar_10355 & cppMask_un_5_);
	BIT_VEC cppVar_10356 = (0 << 5) | cppVar_10355;
	cppVar_10356 = (cppVar_10356 & cppMask_un_8_);
	bool cppVar_10358 = (cppVar_10356 == 144);
	if (cppVar_10358) {
	cppVar_10353 = P1;
	} else {
	BIT_VEC cppVar_10359;
	BIT_VEC cppVar_10360 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10361 = (cppVar_10360 << 3) | 6;
	cppVar_10361 = (cppVar_10361 & cppMask_un_5_);
	BIT_VEC cppVar_10362 = (0 << 5) | cppVar_10361;
	cppVar_10362 = (cppVar_10362 & cppMask_un_8_);
	bool cppVar_10364 = (cppVar_10362 == 152);
	if (cppVar_10364) {
	cppVar_10359 = SCON;
	} else {
	BIT_VEC cppVar_10365;
	BIT_VEC cppVar_10366 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10367 = (cppVar_10366 << 3) | 6;
	cppVar_10367 = (cppVar_10367 & cppMask_un_5_);
	BIT_VEC cppVar_10368 = (0 << 5) | cppVar_10367;
	cppVar_10368 = (cppVar_10368 & cppMask_un_8_);
	bool cppVar_10370 = (cppVar_10368 == 153);
	if (cppVar_10370) {
	cppVar_10365 = SBUF;
	} else {
	BIT_VEC cppVar_10371;
	BIT_VEC cppVar_10372 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10373 = (cppVar_10372 << 3) | 6;
	cppVar_10373 = (cppVar_10373 & cppMask_un_5_);
	BIT_VEC cppVar_10374 = (0 << 5) | cppVar_10373;
	cppVar_10374 = (cppVar_10374 & cppMask_un_8_);
	bool cppVar_10376 = (cppVar_10374 == 160);
	if (cppVar_10376) {
	cppVar_10371 = P2;
	} else {
	BIT_VEC cppVar_10377;
	BIT_VEC cppVar_10378 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10379 = (cppVar_10378 << 3) | 6;
	cppVar_10379 = (cppVar_10379 & cppMask_un_5_);
	BIT_VEC cppVar_10380 = (0 << 5) | cppVar_10379;
	cppVar_10380 = (cppVar_10380 & cppMask_un_8_);
	bool cppVar_10382 = (cppVar_10380 == 168);
	if (cppVar_10382) {
	cppVar_10377 = IE;
	} else {
	BIT_VEC cppVar_10383;
	BIT_VEC cppVar_10384 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10385 = (cppVar_10384 << 3) | 6;
	cppVar_10385 = (cppVar_10385 & cppMask_un_5_);
	BIT_VEC cppVar_10386 = (0 << 5) | cppVar_10385;
	cppVar_10386 = (cppVar_10386 & cppMask_un_8_);
	bool cppVar_10388 = (cppVar_10386 == 176);
	if (cppVar_10388) {
	cppVar_10383 = P3;
	} else {
	BIT_VEC cppVar_10389;
	BIT_VEC cppVar_10390 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10391 = (cppVar_10390 << 3) | 6;
	cppVar_10391 = (cppVar_10391 & cppMask_un_5_);
	BIT_VEC cppVar_10392 = (0 << 5) | cppVar_10391;
	cppVar_10392 = (cppVar_10392 & cppMask_un_8_);
	bool cppVar_10394 = (cppVar_10392 == 184);
	if (cppVar_10394) {
	cppVar_10389 = IP;
	} else {
	BIT_VEC cppVar_10395;
	BIT_VEC cppVar_10396 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10397 = (cppVar_10396 << 3) | 6;
	cppVar_10397 = (cppVar_10397 & cppMask_un_5_);
	BIT_VEC cppVar_10398 = (0 << 5) | cppVar_10397;
	cppVar_10398 = (cppVar_10398 & cppMask_un_8_);
	bool cppVar_10400 = (cppVar_10398 == 208);
	if (cppVar_10400) {
	cppVar_10395 = PSW;
	} else {
	BIT_VEC cppVar_10401;
	BIT_VEC cppVar_10402 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10403 = (cppVar_10402 << 3) | 6;
	cppVar_10403 = (cppVar_10403 & cppMask_un_5_);
	BIT_VEC cppVar_10404 = (0 << 5) | cppVar_10403;
	cppVar_10404 = (cppVar_10404 & cppMask_un_8_);
	bool cppVar_10406 = (cppVar_10404 == 224);
	if (cppVar_10406) {
	cppVar_10401 = ACC;
	} else {
	BIT_VEC cppVar_10407;
	BIT_VEC cppVar_10408 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10409 = (cppVar_10408 << 3) | 6;
	cppVar_10409 = (cppVar_10409 & cppMask_un_5_);
	BIT_VEC cppVar_10410 = (0 << 5) | cppVar_10409;
	cppVar_10410 = (cppVar_10410 & cppMask_un_8_);
	bool cppVar_10412 = (cppVar_10410 == 240);
	if (cppVar_10412) {
	cppVar_10407 = B;
	} else {
	cppVar_10407 = 0;
	}
	cppVar_10401 = cppVar_10407;
	}
	cppVar_10395 = cppVar_10401;
	}
	cppVar_10389 = cppVar_10395;
	}
	cppVar_10383 = cppVar_10389;
	}
	cppVar_10377 = cppVar_10383;
	}
	cppVar_10371 = cppVar_10377;
	}
	cppVar_10365 = cppVar_10371;
	}
	cppVar_10359 = cppVar_10365;
	}
	cppVar_10353 = cppVar_10359;
	}
	cppVar_10347 = cppVar_10353;
	}
	cppVar_10341 = cppVar_10347;
	}
	cppVar_10335 = cppVar_10341;
	}
	cppVar_10329 = cppVar_10335;
	}
	cppVar_10323 = cppVar_10329;
	}
	cppVar_10317 = cppVar_10323;
	}
	cppVar_10311 = cppVar_10317;
	}
	cppVar_10305 = cppVar_10311;
	}
	cppVar_10299 = cppVar_10305;
	}
	cppVar_10293 = cppVar_10299;
	}
	cppVar_10287 = cppVar_10293;
	}
	cppVar_10274 = cppVar_10287;
	}
	cppVar_10268 = cppVar_10274;
	} else {
	cppVar_10268 = DPL;
	}
	cppVar_10264 = cppVar_10268;
	} else {
	BIT_VEC cppVar_10414;
	BIT_VEC cppVar_10415 = ROM.rd(PC);
	bool cppVar_10417 = (cppVar_10415 == 141);
	if (cppVar_10417) {
	BIT_VEC cppVar_10418;
	BIT_VEC cppVar_10420 = PC + 1;
	cppVar_10420 = (cppVar_10420 & cppMask_un_16_);
	BIT_VEC cppVar_10421 = ROM.rd(cppVar_10420);
	bool cppVar_10423 = (cppVar_10421 == 130);
	if (cppVar_10423) {
	BIT_VEC cppVar_10424;
	BIT_VEC cppVar_10426 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10428 = (cppVar_10426 << 3) | 5;
	cppVar_10428 = (cppVar_10428 & cppMask_un_5_);
	BIT_VEC cppVar_10429 = (0 << 5) | cppVar_10428;
	cppVar_10429 = (cppVar_10429 & cppMask_un_8_);
	BIT_VEC cppVar_10430 = (cppVar_10429 >> 7) & cppMask_un_1_;
	bool cppVar_10432 = (cppVar_10430 == 0);
	if (cppVar_10432) {
	BIT_VEC cppVar_10433 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10434 = (cppVar_10433 << 3) | 5;
	cppVar_10434 = (cppVar_10434 & cppMask_un_5_);
	BIT_VEC cppVar_10435 = (0 << 5) | cppVar_10434;
	cppVar_10435 = (cppVar_10435 & cppMask_un_8_);
	BIT_VEC cppVar_10436 = IRAM.rd(cppVar_10435);
	cppVar_10424 = cppVar_10436;
	} else {
	BIT_VEC cppVar_10437;
	BIT_VEC cppVar_10438 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10439 = (cppVar_10438 << 3) | 5;
	cppVar_10439 = (cppVar_10439 & cppMask_un_5_);
	BIT_VEC cppVar_10440 = (0 << 5) | cppVar_10439;
	cppVar_10440 = (cppVar_10440 & cppMask_un_8_);
	bool cppVar_10442 = (cppVar_10440 == 128);
	if (cppVar_10442) {
	cppVar_10437 = P0;
	} else {
	BIT_VEC cppVar_10443;
	BIT_VEC cppVar_10444 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10445 = (cppVar_10444 << 3) | 5;
	cppVar_10445 = (cppVar_10445 & cppMask_un_5_);
	BIT_VEC cppVar_10446 = (0 << 5) | cppVar_10445;
	cppVar_10446 = (cppVar_10446 & cppMask_un_8_);
	bool cppVar_10448 = (cppVar_10446 == 129);
	if (cppVar_10448) {
	cppVar_10443 = SP;
	} else {
	BIT_VEC cppVar_10449;
	BIT_VEC cppVar_10450 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10451 = (cppVar_10450 << 3) | 5;
	cppVar_10451 = (cppVar_10451 & cppMask_un_5_);
	BIT_VEC cppVar_10452 = (0 << 5) | cppVar_10451;
	cppVar_10452 = (cppVar_10452 & cppMask_un_8_);
	bool cppVar_10454 = (cppVar_10452 == 130);
	if (cppVar_10454) {
	cppVar_10449 = DPL;
	} else {
	BIT_VEC cppVar_10455;
	BIT_VEC cppVar_10456 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10457 = (cppVar_10456 << 3) | 5;
	cppVar_10457 = (cppVar_10457 & cppMask_un_5_);
	BIT_VEC cppVar_10458 = (0 << 5) | cppVar_10457;
	cppVar_10458 = (cppVar_10458 & cppMask_un_8_);
	bool cppVar_10460 = (cppVar_10458 == 131);
	if (cppVar_10460) {
	cppVar_10455 = DPH;
	} else {
	BIT_VEC cppVar_10461;
	BIT_VEC cppVar_10462 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10463 = (cppVar_10462 << 3) | 5;
	cppVar_10463 = (cppVar_10463 & cppMask_un_5_);
	BIT_VEC cppVar_10464 = (0 << 5) | cppVar_10463;
	cppVar_10464 = (cppVar_10464 & cppMask_un_8_);
	bool cppVar_10466 = (cppVar_10464 == 135);
	if (cppVar_10466) {
	cppVar_10461 = PCON;
	} else {
	BIT_VEC cppVar_10467;
	BIT_VEC cppVar_10468 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10469 = (cppVar_10468 << 3) | 5;
	cppVar_10469 = (cppVar_10469 & cppMask_un_5_);
	BIT_VEC cppVar_10470 = (0 << 5) | cppVar_10469;
	cppVar_10470 = (cppVar_10470 & cppMask_un_8_);
	bool cppVar_10472 = (cppVar_10470 == 136);
	if (cppVar_10472) {
	cppVar_10467 = TCON;
	} else {
	BIT_VEC cppVar_10473;
	BIT_VEC cppVar_10474 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10475 = (cppVar_10474 << 3) | 5;
	cppVar_10475 = (cppVar_10475 & cppMask_un_5_);
	BIT_VEC cppVar_10476 = (0 << 5) | cppVar_10475;
	cppVar_10476 = (cppVar_10476 & cppMask_un_8_);
	bool cppVar_10478 = (cppVar_10476 == 137);
	if (cppVar_10478) {
	cppVar_10473 = TMOD;
	} else {
	BIT_VEC cppVar_10479;
	BIT_VEC cppVar_10480 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10481 = (cppVar_10480 << 3) | 5;
	cppVar_10481 = (cppVar_10481 & cppMask_un_5_);
	BIT_VEC cppVar_10482 = (0 << 5) | cppVar_10481;
	cppVar_10482 = (cppVar_10482 & cppMask_un_8_);
	bool cppVar_10484 = (cppVar_10482 == 138);
	if (cppVar_10484) {
	cppVar_10479 = TL0;
	} else {
	BIT_VEC cppVar_10485;
	BIT_VEC cppVar_10486 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10487 = (cppVar_10486 << 3) | 5;
	cppVar_10487 = (cppVar_10487 & cppMask_un_5_);
	BIT_VEC cppVar_10488 = (0 << 5) | cppVar_10487;
	cppVar_10488 = (cppVar_10488 & cppMask_un_8_);
	bool cppVar_10490 = (cppVar_10488 == 140);
	if (cppVar_10490) {
	cppVar_10485 = TH0;
	} else {
	BIT_VEC cppVar_10491;
	BIT_VEC cppVar_10492 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10493 = (cppVar_10492 << 3) | 5;
	cppVar_10493 = (cppVar_10493 & cppMask_un_5_);
	BIT_VEC cppVar_10494 = (0 << 5) | cppVar_10493;
	cppVar_10494 = (cppVar_10494 & cppMask_un_8_);
	bool cppVar_10496 = (cppVar_10494 == 139);
	if (cppVar_10496) {
	cppVar_10491 = TL1;
	} else {
	BIT_VEC cppVar_10497;
	BIT_VEC cppVar_10498 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10499 = (cppVar_10498 << 3) | 5;
	cppVar_10499 = (cppVar_10499 & cppMask_un_5_);
	BIT_VEC cppVar_10500 = (0 << 5) | cppVar_10499;
	cppVar_10500 = (cppVar_10500 & cppMask_un_8_);
	bool cppVar_10502 = (cppVar_10500 == 141);
	if (cppVar_10502) {
	cppVar_10497 = TH1;
	} else {
	BIT_VEC cppVar_10503;
	BIT_VEC cppVar_10504 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10505 = (cppVar_10504 << 3) | 5;
	cppVar_10505 = (cppVar_10505 & cppMask_un_5_);
	BIT_VEC cppVar_10506 = (0 << 5) | cppVar_10505;
	cppVar_10506 = (cppVar_10506 & cppMask_un_8_);
	bool cppVar_10508 = (cppVar_10506 == 144);
	if (cppVar_10508) {
	cppVar_10503 = P1;
	} else {
	BIT_VEC cppVar_10509;
	BIT_VEC cppVar_10510 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10511 = (cppVar_10510 << 3) | 5;
	cppVar_10511 = (cppVar_10511 & cppMask_un_5_);
	BIT_VEC cppVar_10512 = (0 << 5) | cppVar_10511;
	cppVar_10512 = (cppVar_10512 & cppMask_un_8_);
	bool cppVar_10514 = (cppVar_10512 == 152);
	if (cppVar_10514) {
	cppVar_10509 = SCON;
	} else {
	BIT_VEC cppVar_10515;
	BIT_VEC cppVar_10516 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10517 = (cppVar_10516 << 3) | 5;
	cppVar_10517 = (cppVar_10517 & cppMask_un_5_);
	BIT_VEC cppVar_10518 = (0 << 5) | cppVar_10517;
	cppVar_10518 = (cppVar_10518 & cppMask_un_8_);
	bool cppVar_10520 = (cppVar_10518 == 153);
	if (cppVar_10520) {
	cppVar_10515 = SBUF;
	} else {
	BIT_VEC cppVar_10521;
	BIT_VEC cppVar_10522 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10523 = (cppVar_10522 << 3) | 5;
	cppVar_10523 = (cppVar_10523 & cppMask_un_5_);
	BIT_VEC cppVar_10524 = (0 << 5) | cppVar_10523;
	cppVar_10524 = (cppVar_10524 & cppMask_un_8_);
	bool cppVar_10526 = (cppVar_10524 == 160);
	if (cppVar_10526) {
	cppVar_10521 = P2;
	} else {
	BIT_VEC cppVar_10527;
	BIT_VEC cppVar_10528 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10529 = (cppVar_10528 << 3) | 5;
	cppVar_10529 = (cppVar_10529 & cppMask_un_5_);
	BIT_VEC cppVar_10530 = (0 << 5) | cppVar_10529;
	cppVar_10530 = (cppVar_10530 & cppMask_un_8_);
	bool cppVar_10532 = (cppVar_10530 == 168);
	if (cppVar_10532) {
	cppVar_10527 = IE;
	} else {
	BIT_VEC cppVar_10533;
	BIT_VEC cppVar_10534 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10535 = (cppVar_10534 << 3) | 5;
	cppVar_10535 = (cppVar_10535 & cppMask_un_5_);
	BIT_VEC cppVar_10536 = (0 << 5) | cppVar_10535;
	cppVar_10536 = (cppVar_10536 & cppMask_un_8_);
	bool cppVar_10538 = (cppVar_10536 == 176);
	if (cppVar_10538) {
	cppVar_10533 = P3;
	} else {
	BIT_VEC cppVar_10539;
	BIT_VEC cppVar_10540 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10541 = (cppVar_10540 << 3) | 5;
	cppVar_10541 = (cppVar_10541 & cppMask_un_5_);
	BIT_VEC cppVar_10542 = (0 << 5) | cppVar_10541;
	cppVar_10542 = (cppVar_10542 & cppMask_un_8_);
	bool cppVar_10544 = (cppVar_10542 == 184);
	if (cppVar_10544) {
	cppVar_10539 = IP;
	} else {
	BIT_VEC cppVar_10545;
	BIT_VEC cppVar_10546 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10547 = (cppVar_10546 << 3) | 5;
	cppVar_10547 = (cppVar_10547 & cppMask_un_5_);
	BIT_VEC cppVar_10548 = (0 << 5) | cppVar_10547;
	cppVar_10548 = (cppVar_10548 & cppMask_un_8_);
	bool cppVar_10550 = (cppVar_10548 == 208);
	if (cppVar_10550) {
	cppVar_10545 = PSW;
	} else {
	BIT_VEC cppVar_10551;
	BIT_VEC cppVar_10552 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10553 = (cppVar_10552 << 3) | 5;
	cppVar_10553 = (cppVar_10553 & cppMask_un_5_);
	BIT_VEC cppVar_10554 = (0 << 5) | cppVar_10553;
	cppVar_10554 = (cppVar_10554 & cppMask_un_8_);
	bool cppVar_10556 = (cppVar_10554 == 224);
	if (cppVar_10556) {
	cppVar_10551 = ACC;
	} else {
	BIT_VEC cppVar_10557;
	BIT_VEC cppVar_10558 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10559 = (cppVar_10558 << 3) | 5;
	cppVar_10559 = (cppVar_10559 & cppMask_un_5_);
	BIT_VEC cppVar_10560 = (0 << 5) | cppVar_10559;
	cppVar_10560 = (cppVar_10560 & cppMask_un_8_);
	bool cppVar_10562 = (cppVar_10560 == 240);
	if (cppVar_10562) {
	cppVar_10557 = B;
	} else {
	cppVar_10557 = 0;
	}
	cppVar_10551 = cppVar_10557;
	}
	cppVar_10545 = cppVar_10551;
	}
	cppVar_10539 = cppVar_10545;
	}
	cppVar_10533 = cppVar_10539;
	}
	cppVar_10527 = cppVar_10533;
	}
	cppVar_10521 = cppVar_10527;
	}
	cppVar_10515 = cppVar_10521;
	}
	cppVar_10509 = cppVar_10515;
	}
	cppVar_10503 = cppVar_10509;
	}
	cppVar_10497 = cppVar_10503;
	}
	cppVar_10491 = cppVar_10497;
	}
	cppVar_10485 = cppVar_10491;
	}
	cppVar_10479 = cppVar_10485;
	}
	cppVar_10473 = cppVar_10479;
	}
	cppVar_10467 = cppVar_10473;
	}
	cppVar_10461 = cppVar_10467;
	}
	cppVar_10455 = cppVar_10461;
	}
	cppVar_10449 = cppVar_10455;
	}
	cppVar_10443 = cppVar_10449;
	}
	cppVar_10437 = cppVar_10443;
	}
	cppVar_10424 = cppVar_10437;
	}
	cppVar_10418 = cppVar_10424;
	} else {
	cppVar_10418 = DPL;
	}
	cppVar_10414 = cppVar_10418;
	} else {
	BIT_VEC cppVar_10564;
	BIT_VEC cppVar_10565 = ROM.rd(PC);
	bool cppVar_10567 = (cppVar_10565 == 140);
	if (cppVar_10567) {
	BIT_VEC cppVar_10568;
	BIT_VEC cppVar_10570 = PC + 1;
	cppVar_10570 = (cppVar_10570 & cppMask_un_16_);
	BIT_VEC cppVar_10571 = ROM.rd(cppVar_10570);
	bool cppVar_10573 = (cppVar_10571 == 130);
	if (cppVar_10573) {
	BIT_VEC cppVar_10574;
	BIT_VEC cppVar_10576 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10578 = (cppVar_10576 << 3) | 4;
	cppVar_10578 = (cppVar_10578 & cppMask_un_5_);
	BIT_VEC cppVar_10579 = (0 << 5) | cppVar_10578;
	cppVar_10579 = (cppVar_10579 & cppMask_un_8_);
	BIT_VEC cppVar_10580 = (cppVar_10579 >> 7) & cppMask_un_1_;
	bool cppVar_10582 = (cppVar_10580 == 0);
	if (cppVar_10582) {
	BIT_VEC cppVar_10583 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10584 = (cppVar_10583 << 3) | 4;
	cppVar_10584 = (cppVar_10584 & cppMask_un_5_);
	BIT_VEC cppVar_10585 = (0 << 5) | cppVar_10584;
	cppVar_10585 = (cppVar_10585 & cppMask_un_8_);
	BIT_VEC cppVar_10586 = IRAM.rd(cppVar_10585);
	cppVar_10574 = cppVar_10586;
	} else {
	BIT_VEC cppVar_10587;
	BIT_VEC cppVar_10588 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10589 = (cppVar_10588 << 3) | 4;
	cppVar_10589 = (cppVar_10589 & cppMask_un_5_);
	BIT_VEC cppVar_10590 = (0 << 5) | cppVar_10589;
	cppVar_10590 = (cppVar_10590 & cppMask_un_8_);
	bool cppVar_10592 = (cppVar_10590 == 128);
	if (cppVar_10592) {
	cppVar_10587 = P0;
	} else {
	BIT_VEC cppVar_10593;
	BIT_VEC cppVar_10594 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10595 = (cppVar_10594 << 3) | 4;
	cppVar_10595 = (cppVar_10595 & cppMask_un_5_);
	BIT_VEC cppVar_10596 = (0 << 5) | cppVar_10595;
	cppVar_10596 = (cppVar_10596 & cppMask_un_8_);
	bool cppVar_10598 = (cppVar_10596 == 129);
	if (cppVar_10598) {
	cppVar_10593 = SP;
	} else {
	BIT_VEC cppVar_10599;
	BIT_VEC cppVar_10600 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10601 = (cppVar_10600 << 3) | 4;
	cppVar_10601 = (cppVar_10601 & cppMask_un_5_);
	BIT_VEC cppVar_10602 = (0 << 5) | cppVar_10601;
	cppVar_10602 = (cppVar_10602 & cppMask_un_8_);
	bool cppVar_10604 = (cppVar_10602 == 130);
	if (cppVar_10604) {
	cppVar_10599 = DPL;
	} else {
	BIT_VEC cppVar_10605;
	BIT_VEC cppVar_10606 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10607 = (cppVar_10606 << 3) | 4;
	cppVar_10607 = (cppVar_10607 & cppMask_un_5_);
	BIT_VEC cppVar_10608 = (0 << 5) | cppVar_10607;
	cppVar_10608 = (cppVar_10608 & cppMask_un_8_);
	bool cppVar_10610 = (cppVar_10608 == 131);
	if (cppVar_10610) {
	cppVar_10605 = DPH;
	} else {
	BIT_VEC cppVar_10611;
	BIT_VEC cppVar_10612 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10613 = (cppVar_10612 << 3) | 4;
	cppVar_10613 = (cppVar_10613 & cppMask_un_5_);
	BIT_VEC cppVar_10614 = (0 << 5) | cppVar_10613;
	cppVar_10614 = (cppVar_10614 & cppMask_un_8_);
	bool cppVar_10616 = (cppVar_10614 == 135);
	if (cppVar_10616) {
	cppVar_10611 = PCON;
	} else {
	BIT_VEC cppVar_10617;
	BIT_VEC cppVar_10618 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10619 = (cppVar_10618 << 3) | 4;
	cppVar_10619 = (cppVar_10619 & cppMask_un_5_);
	BIT_VEC cppVar_10620 = (0 << 5) | cppVar_10619;
	cppVar_10620 = (cppVar_10620 & cppMask_un_8_);
	bool cppVar_10622 = (cppVar_10620 == 136);
	if (cppVar_10622) {
	cppVar_10617 = TCON;
	} else {
	BIT_VEC cppVar_10623;
	BIT_VEC cppVar_10624 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10625 = (cppVar_10624 << 3) | 4;
	cppVar_10625 = (cppVar_10625 & cppMask_un_5_);
	BIT_VEC cppVar_10626 = (0 << 5) | cppVar_10625;
	cppVar_10626 = (cppVar_10626 & cppMask_un_8_);
	bool cppVar_10628 = (cppVar_10626 == 137);
	if (cppVar_10628) {
	cppVar_10623 = TMOD;
	} else {
	BIT_VEC cppVar_10629;
	BIT_VEC cppVar_10630 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10631 = (cppVar_10630 << 3) | 4;
	cppVar_10631 = (cppVar_10631 & cppMask_un_5_);
	BIT_VEC cppVar_10632 = (0 << 5) | cppVar_10631;
	cppVar_10632 = (cppVar_10632 & cppMask_un_8_);
	bool cppVar_10634 = (cppVar_10632 == 138);
	if (cppVar_10634) {
	cppVar_10629 = TL0;
	} else {
	BIT_VEC cppVar_10635;
	BIT_VEC cppVar_10636 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10637 = (cppVar_10636 << 3) | 4;
	cppVar_10637 = (cppVar_10637 & cppMask_un_5_);
	BIT_VEC cppVar_10638 = (0 << 5) | cppVar_10637;
	cppVar_10638 = (cppVar_10638 & cppMask_un_8_);
	bool cppVar_10640 = (cppVar_10638 == 140);
	if (cppVar_10640) {
	cppVar_10635 = TH0;
	} else {
	BIT_VEC cppVar_10641;
	BIT_VEC cppVar_10642 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10643 = (cppVar_10642 << 3) | 4;
	cppVar_10643 = (cppVar_10643 & cppMask_un_5_);
	BIT_VEC cppVar_10644 = (0 << 5) | cppVar_10643;
	cppVar_10644 = (cppVar_10644 & cppMask_un_8_);
	bool cppVar_10646 = (cppVar_10644 == 139);
	if (cppVar_10646) {
	cppVar_10641 = TL1;
	} else {
	BIT_VEC cppVar_10647;
	BIT_VEC cppVar_10648 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10649 = (cppVar_10648 << 3) | 4;
	cppVar_10649 = (cppVar_10649 & cppMask_un_5_);
	BIT_VEC cppVar_10650 = (0 << 5) | cppVar_10649;
	cppVar_10650 = (cppVar_10650 & cppMask_un_8_);
	bool cppVar_10652 = (cppVar_10650 == 141);
	if (cppVar_10652) {
	cppVar_10647 = TH1;
	} else {
	BIT_VEC cppVar_10653;
	BIT_VEC cppVar_10654 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10655 = (cppVar_10654 << 3) | 4;
	cppVar_10655 = (cppVar_10655 & cppMask_un_5_);
	BIT_VEC cppVar_10656 = (0 << 5) | cppVar_10655;
	cppVar_10656 = (cppVar_10656 & cppMask_un_8_);
	bool cppVar_10658 = (cppVar_10656 == 144);
	if (cppVar_10658) {
	cppVar_10653 = P1;
	} else {
	BIT_VEC cppVar_10659;
	BIT_VEC cppVar_10660 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10661 = (cppVar_10660 << 3) | 4;
	cppVar_10661 = (cppVar_10661 & cppMask_un_5_);
	BIT_VEC cppVar_10662 = (0 << 5) | cppVar_10661;
	cppVar_10662 = (cppVar_10662 & cppMask_un_8_);
	bool cppVar_10664 = (cppVar_10662 == 152);
	if (cppVar_10664) {
	cppVar_10659 = SCON;
	} else {
	BIT_VEC cppVar_10665;
	BIT_VEC cppVar_10666 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10667 = (cppVar_10666 << 3) | 4;
	cppVar_10667 = (cppVar_10667 & cppMask_un_5_);
	BIT_VEC cppVar_10668 = (0 << 5) | cppVar_10667;
	cppVar_10668 = (cppVar_10668 & cppMask_un_8_);
	bool cppVar_10670 = (cppVar_10668 == 153);
	if (cppVar_10670) {
	cppVar_10665 = SBUF;
	} else {
	BIT_VEC cppVar_10671;
	BIT_VEC cppVar_10672 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10673 = (cppVar_10672 << 3) | 4;
	cppVar_10673 = (cppVar_10673 & cppMask_un_5_);
	BIT_VEC cppVar_10674 = (0 << 5) | cppVar_10673;
	cppVar_10674 = (cppVar_10674 & cppMask_un_8_);
	bool cppVar_10676 = (cppVar_10674 == 160);
	if (cppVar_10676) {
	cppVar_10671 = P2;
	} else {
	BIT_VEC cppVar_10677;
	BIT_VEC cppVar_10678 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10679 = (cppVar_10678 << 3) | 4;
	cppVar_10679 = (cppVar_10679 & cppMask_un_5_);
	BIT_VEC cppVar_10680 = (0 << 5) | cppVar_10679;
	cppVar_10680 = (cppVar_10680 & cppMask_un_8_);
	bool cppVar_10682 = (cppVar_10680 == 168);
	if (cppVar_10682) {
	cppVar_10677 = IE;
	} else {
	BIT_VEC cppVar_10683;
	BIT_VEC cppVar_10684 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10685 = (cppVar_10684 << 3) | 4;
	cppVar_10685 = (cppVar_10685 & cppMask_un_5_);
	BIT_VEC cppVar_10686 = (0 << 5) | cppVar_10685;
	cppVar_10686 = (cppVar_10686 & cppMask_un_8_);
	bool cppVar_10688 = (cppVar_10686 == 176);
	if (cppVar_10688) {
	cppVar_10683 = P3;
	} else {
	BIT_VEC cppVar_10689;
	BIT_VEC cppVar_10690 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10691 = (cppVar_10690 << 3) | 4;
	cppVar_10691 = (cppVar_10691 & cppMask_un_5_);
	BIT_VEC cppVar_10692 = (0 << 5) | cppVar_10691;
	cppVar_10692 = (cppVar_10692 & cppMask_un_8_);
	bool cppVar_10694 = (cppVar_10692 == 184);
	if (cppVar_10694) {
	cppVar_10689 = IP;
	} else {
	BIT_VEC cppVar_10695;
	BIT_VEC cppVar_10696 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10697 = (cppVar_10696 << 3) | 4;
	cppVar_10697 = (cppVar_10697 & cppMask_un_5_);
	BIT_VEC cppVar_10698 = (0 << 5) | cppVar_10697;
	cppVar_10698 = (cppVar_10698 & cppMask_un_8_);
	bool cppVar_10700 = (cppVar_10698 == 208);
	if (cppVar_10700) {
	cppVar_10695 = PSW;
	} else {
	BIT_VEC cppVar_10701;
	BIT_VEC cppVar_10702 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10703 = (cppVar_10702 << 3) | 4;
	cppVar_10703 = (cppVar_10703 & cppMask_un_5_);
	BIT_VEC cppVar_10704 = (0 << 5) | cppVar_10703;
	cppVar_10704 = (cppVar_10704 & cppMask_un_8_);
	bool cppVar_10706 = (cppVar_10704 == 224);
	if (cppVar_10706) {
	cppVar_10701 = ACC;
	} else {
	BIT_VEC cppVar_10707;
	BIT_VEC cppVar_10708 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10709 = (cppVar_10708 << 3) | 4;
	cppVar_10709 = (cppVar_10709 & cppMask_un_5_);
	BIT_VEC cppVar_10710 = (0 << 5) | cppVar_10709;
	cppVar_10710 = (cppVar_10710 & cppMask_un_8_);
	bool cppVar_10712 = (cppVar_10710 == 240);
	if (cppVar_10712) {
	cppVar_10707 = B;
	} else {
	cppVar_10707 = 0;
	}
	cppVar_10701 = cppVar_10707;
	}
	cppVar_10695 = cppVar_10701;
	}
	cppVar_10689 = cppVar_10695;
	}
	cppVar_10683 = cppVar_10689;
	}
	cppVar_10677 = cppVar_10683;
	}
	cppVar_10671 = cppVar_10677;
	}
	cppVar_10665 = cppVar_10671;
	}
	cppVar_10659 = cppVar_10665;
	}
	cppVar_10653 = cppVar_10659;
	}
	cppVar_10647 = cppVar_10653;
	}
	cppVar_10641 = cppVar_10647;
	}
	cppVar_10635 = cppVar_10641;
	}
	cppVar_10629 = cppVar_10635;
	}
	cppVar_10623 = cppVar_10629;
	}
	cppVar_10617 = cppVar_10623;
	}
	cppVar_10611 = cppVar_10617;
	}
	cppVar_10605 = cppVar_10611;
	}
	cppVar_10599 = cppVar_10605;
	}
	cppVar_10593 = cppVar_10599;
	}
	cppVar_10587 = cppVar_10593;
	}
	cppVar_10574 = cppVar_10587;
	}
	cppVar_10568 = cppVar_10574;
	} else {
	cppVar_10568 = DPL;
	}
	cppVar_10564 = cppVar_10568;
	} else {
	BIT_VEC cppVar_10714;
	BIT_VEC cppVar_10715 = ROM.rd(PC);
	bool cppVar_10717 = (cppVar_10715 == 139);
	if (cppVar_10717) {
	BIT_VEC cppVar_10718;
	BIT_VEC cppVar_10720 = PC + 1;
	cppVar_10720 = (cppVar_10720 & cppMask_un_16_);
	BIT_VEC cppVar_10721 = ROM.rd(cppVar_10720);
	bool cppVar_10723 = (cppVar_10721 == 130);
	if (cppVar_10723) {
	BIT_VEC cppVar_10724;
	BIT_VEC cppVar_10726 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10728 = (cppVar_10726 << 3) | 3;
	cppVar_10728 = (cppVar_10728 & cppMask_un_5_);
	BIT_VEC cppVar_10729 = (0 << 5) | cppVar_10728;
	cppVar_10729 = (cppVar_10729 & cppMask_un_8_);
	BIT_VEC cppVar_10730 = (cppVar_10729 >> 7) & cppMask_un_1_;
	bool cppVar_10732 = (cppVar_10730 == 0);
	if (cppVar_10732) {
	BIT_VEC cppVar_10733 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10734 = (cppVar_10733 << 3) | 3;
	cppVar_10734 = (cppVar_10734 & cppMask_un_5_);
	BIT_VEC cppVar_10735 = (0 << 5) | cppVar_10734;
	cppVar_10735 = (cppVar_10735 & cppMask_un_8_);
	BIT_VEC cppVar_10736 = IRAM.rd(cppVar_10735);
	cppVar_10724 = cppVar_10736;
	} else {
	BIT_VEC cppVar_10737;
	BIT_VEC cppVar_10738 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10739 = (cppVar_10738 << 3) | 3;
	cppVar_10739 = (cppVar_10739 & cppMask_un_5_);
	BIT_VEC cppVar_10740 = (0 << 5) | cppVar_10739;
	cppVar_10740 = (cppVar_10740 & cppMask_un_8_);
	bool cppVar_10742 = (cppVar_10740 == 128);
	if (cppVar_10742) {
	cppVar_10737 = P0;
	} else {
	BIT_VEC cppVar_10743;
	BIT_VEC cppVar_10744 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10745 = (cppVar_10744 << 3) | 3;
	cppVar_10745 = (cppVar_10745 & cppMask_un_5_);
	BIT_VEC cppVar_10746 = (0 << 5) | cppVar_10745;
	cppVar_10746 = (cppVar_10746 & cppMask_un_8_);
	bool cppVar_10748 = (cppVar_10746 == 129);
	if (cppVar_10748) {
	cppVar_10743 = SP;
	} else {
	BIT_VEC cppVar_10749;
	BIT_VEC cppVar_10750 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10751 = (cppVar_10750 << 3) | 3;
	cppVar_10751 = (cppVar_10751 & cppMask_un_5_);
	BIT_VEC cppVar_10752 = (0 << 5) | cppVar_10751;
	cppVar_10752 = (cppVar_10752 & cppMask_un_8_);
	bool cppVar_10754 = (cppVar_10752 == 130);
	if (cppVar_10754) {
	cppVar_10749 = DPL;
	} else {
	BIT_VEC cppVar_10755;
	BIT_VEC cppVar_10756 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10757 = (cppVar_10756 << 3) | 3;
	cppVar_10757 = (cppVar_10757 & cppMask_un_5_);
	BIT_VEC cppVar_10758 = (0 << 5) | cppVar_10757;
	cppVar_10758 = (cppVar_10758 & cppMask_un_8_);
	bool cppVar_10760 = (cppVar_10758 == 131);
	if (cppVar_10760) {
	cppVar_10755 = DPH;
	} else {
	BIT_VEC cppVar_10761;
	BIT_VEC cppVar_10762 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10763 = (cppVar_10762 << 3) | 3;
	cppVar_10763 = (cppVar_10763 & cppMask_un_5_);
	BIT_VEC cppVar_10764 = (0 << 5) | cppVar_10763;
	cppVar_10764 = (cppVar_10764 & cppMask_un_8_);
	bool cppVar_10766 = (cppVar_10764 == 135);
	if (cppVar_10766) {
	cppVar_10761 = PCON;
	} else {
	BIT_VEC cppVar_10767;
	BIT_VEC cppVar_10768 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10769 = (cppVar_10768 << 3) | 3;
	cppVar_10769 = (cppVar_10769 & cppMask_un_5_);
	BIT_VEC cppVar_10770 = (0 << 5) | cppVar_10769;
	cppVar_10770 = (cppVar_10770 & cppMask_un_8_);
	bool cppVar_10772 = (cppVar_10770 == 136);
	if (cppVar_10772) {
	cppVar_10767 = TCON;
	} else {
	BIT_VEC cppVar_10773;
	BIT_VEC cppVar_10774 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10775 = (cppVar_10774 << 3) | 3;
	cppVar_10775 = (cppVar_10775 & cppMask_un_5_);
	BIT_VEC cppVar_10776 = (0 << 5) | cppVar_10775;
	cppVar_10776 = (cppVar_10776 & cppMask_un_8_);
	bool cppVar_10778 = (cppVar_10776 == 137);
	if (cppVar_10778) {
	cppVar_10773 = TMOD;
	} else {
	BIT_VEC cppVar_10779;
	BIT_VEC cppVar_10780 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10781 = (cppVar_10780 << 3) | 3;
	cppVar_10781 = (cppVar_10781 & cppMask_un_5_);
	BIT_VEC cppVar_10782 = (0 << 5) | cppVar_10781;
	cppVar_10782 = (cppVar_10782 & cppMask_un_8_);
	bool cppVar_10784 = (cppVar_10782 == 138);
	if (cppVar_10784) {
	cppVar_10779 = TL0;
	} else {
	BIT_VEC cppVar_10785;
	BIT_VEC cppVar_10786 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10787 = (cppVar_10786 << 3) | 3;
	cppVar_10787 = (cppVar_10787 & cppMask_un_5_);
	BIT_VEC cppVar_10788 = (0 << 5) | cppVar_10787;
	cppVar_10788 = (cppVar_10788 & cppMask_un_8_);
	bool cppVar_10790 = (cppVar_10788 == 140);
	if (cppVar_10790) {
	cppVar_10785 = TH0;
	} else {
	BIT_VEC cppVar_10791;
	BIT_VEC cppVar_10792 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10793 = (cppVar_10792 << 3) | 3;
	cppVar_10793 = (cppVar_10793 & cppMask_un_5_);
	BIT_VEC cppVar_10794 = (0 << 5) | cppVar_10793;
	cppVar_10794 = (cppVar_10794 & cppMask_un_8_);
	bool cppVar_10796 = (cppVar_10794 == 139);
	if (cppVar_10796) {
	cppVar_10791 = TL1;
	} else {
	BIT_VEC cppVar_10797;
	BIT_VEC cppVar_10798 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10799 = (cppVar_10798 << 3) | 3;
	cppVar_10799 = (cppVar_10799 & cppMask_un_5_);
	BIT_VEC cppVar_10800 = (0 << 5) | cppVar_10799;
	cppVar_10800 = (cppVar_10800 & cppMask_un_8_);
	bool cppVar_10802 = (cppVar_10800 == 141);
	if (cppVar_10802) {
	cppVar_10797 = TH1;
	} else {
	BIT_VEC cppVar_10803;
	BIT_VEC cppVar_10804 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10805 = (cppVar_10804 << 3) | 3;
	cppVar_10805 = (cppVar_10805 & cppMask_un_5_);
	BIT_VEC cppVar_10806 = (0 << 5) | cppVar_10805;
	cppVar_10806 = (cppVar_10806 & cppMask_un_8_);
	bool cppVar_10808 = (cppVar_10806 == 144);
	if (cppVar_10808) {
	cppVar_10803 = P1;
	} else {
	BIT_VEC cppVar_10809;
	BIT_VEC cppVar_10810 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10811 = (cppVar_10810 << 3) | 3;
	cppVar_10811 = (cppVar_10811 & cppMask_un_5_);
	BIT_VEC cppVar_10812 = (0 << 5) | cppVar_10811;
	cppVar_10812 = (cppVar_10812 & cppMask_un_8_);
	bool cppVar_10814 = (cppVar_10812 == 152);
	if (cppVar_10814) {
	cppVar_10809 = SCON;
	} else {
	BIT_VEC cppVar_10815;
	BIT_VEC cppVar_10816 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10817 = (cppVar_10816 << 3) | 3;
	cppVar_10817 = (cppVar_10817 & cppMask_un_5_);
	BIT_VEC cppVar_10818 = (0 << 5) | cppVar_10817;
	cppVar_10818 = (cppVar_10818 & cppMask_un_8_);
	bool cppVar_10820 = (cppVar_10818 == 153);
	if (cppVar_10820) {
	cppVar_10815 = SBUF;
	} else {
	BIT_VEC cppVar_10821;
	BIT_VEC cppVar_10822 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10823 = (cppVar_10822 << 3) | 3;
	cppVar_10823 = (cppVar_10823 & cppMask_un_5_);
	BIT_VEC cppVar_10824 = (0 << 5) | cppVar_10823;
	cppVar_10824 = (cppVar_10824 & cppMask_un_8_);
	bool cppVar_10826 = (cppVar_10824 == 160);
	if (cppVar_10826) {
	cppVar_10821 = P2;
	} else {
	BIT_VEC cppVar_10827;
	BIT_VEC cppVar_10828 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10829 = (cppVar_10828 << 3) | 3;
	cppVar_10829 = (cppVar_10829 & cppMask_un_5_);
	BIT_VEC cppVar_10830 = (0 << 5) | cppVar_10829;
	cppVar_10830 = (cppVar_10830 & cppMask_un_8_);
	bool cppVar_10832 = (cppVar_10830 == 168);
	if (cppVar_10832) {
	cppVar_10827 = IE;
	} else {
	BIT_VEC cppVar_10833;
	BIT_VEC cppVar_10834 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10835 = (cppVar_10834 << 3) | 3;
	cppVar_10835 = (cppVar_10835 & cppMask_un_5_);
	BIT_VEC cppVar_10836 = (0 << 5) | cppVar_10835;
	cppVar_10836 = (cppVar_10836 & cppMask_un_8_);
	bool cppVar_10838 = (cppVar_10836 == 176);
	if (cppVar_10838) {
	cppVar_10833 = P3;
	} else {
	BIT_VEC cppVar_10839;
	BIT_VEC cppVar_10840 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10841 = (cppVar_10840 << 3) | 3;
	cppVar_10841 = (cppVar_10841 & cppMask_un_5_);
	BIT_VEC cppVar_10842 = (0 << 5) | cppVar_10841;
	cppVar_10842 = (cppVar_10842 & cppMask_un_8_);
	bool cppVar_10844 = (cppVar_10842 == 184);
	if (cppVar_10844) {
	cppVar_10839 = IP;
	} else {
	BIT_VEC cppVar_10845;
	BIT_VEC cppVar_10846 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10847 = (cppVar_10846 << 3) | 3;
	cppVar_10847 = (cppVar_10847 & cppMask_un_5_);
	BIT_VEC cppVar_10848 = (0 << 5) | cppVar_10847;
	cppVar_10848 = (cppVar_10848 & cppMask_un_8_);
	bool cppVar_10850 = (cppVar_10848 == 208);
	if (cppVar_10850) {
	cppVar_10845 = PSW;
	} else {
	BIT_VEC cppVar_10851;
	BIT_VEC cppVar_10852 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10853 = (cppVar_10852 << 3) | 3;
	cppVar_10853 = (cppVar_10853 & cppMask_un_5_);
	BIT_VEC cppVar_10854 = (0 << 5) | cppVar_10853;
	cppVar_10854 = (cppVar_10854 & cppMask_un_8_);
	bool cppVar_10856 = (cppVar_10854 == 224);
	if (cppVar_10856) {
	cppVar_10851 = ACC;
	} else {
	BIT_VEC cppVar_10857;
	BIT_VEC cppVar_10858 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10859 = (cppVar_10858 << 3) | 3;
	cppVar_10859 = (cppVar_10859 & cppMask_un_5_);
	BIT_VEC cppVar_10860 = (0 << 5) | cppVar_10859;
	cppVar_10860 = (cppVar_10860 & cppMask_un_8_);
	bool cppVar_10862 = (cppVar_10860 == 240);
	if (cppVar_10862) {
	cppVar_10857 = B;
	} else {
	cppVar_10857 = 0;
	}
	cppVar_10851 = cppVar_10857;
	}
	cppVar_10845 = cppVar_10851;
	}
	cppVar_10839 = cppVar_10845;
	}
	cppVar_10833 = cppVar_10839;
	}
	cppVar_10827 = cppVar_10833;
	}
	cppVar_10821 = cppVar_10827;
	}
	cppVar_10815 = cppVar_10821;
	}
	cppVar_10809 = cppVar_10815;
	}
	cppVar_10803 = cppVar_10809;
	}
	cppVar_10797 = cppVar_10803;
	}
	cppVar_10791 = cppVar_10797;
	}
	cppVar_10785 = cppVar_10791;
	}
	cppVar_10779 = cppVar_10785;
	}
	cppVar_10773 = cppVar_10779;
	}
	cppVar_10767 = cppVar_10773;
	}
	cppVar_10761 = cppVar_10767;
	}
	cppVar_10755 = cppVar_10761;
	}
	cppVar_10749 = cppVar_10755;
	}
	cppVar_10743 = cppVar_10749;
	}
	cppVar_10737 = cppVar_10743;
	}
	cppVar_10724 = cppVar_10737;
	}
	cppVar_10718 = cppVar_10724;
	} else {
	cppVar_10718 = DPL;
	}
	cppVar_10714 = cppVar_10718;
	} else {
	BIT_VEC cppVar_10864;
	BIT_VEC cppVar_10865 = ROM.rd(PC);
	bool cppVar_10867 = (cppVar_10865 == 138);
	if (cppVar_10867) {
	BIT_VEC cppVar_10868;
	BIT_VEC cppVar_10870 = PC + 1;
	cppVar_10870 = (cppVar_10870 & cppMask_un_16_);
	BIT_VEC cppVar_10871 = ROM.rd(cppVar_10870);
	bool cppVar_10873 = (cppVar_10871 == 130);
	if (cppVar_10873) {
	BIT_VEC cppVar_10874;
	BIT_VEC cppVar_10876 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10878 = (cppVar_10876 << 3) | 2;
	cppVar_10878 = (cppVar_10878 & cppMask_un_5_);
	BIT_VEC cppVar_10879 = (0 << 5) | cppVar_10878;
	cppVar_10879 = (cppVar_10879 & cppMask_un_8_);
	BIT_VEC cppVar_10880 = (cppVar_10879 >> 7) & cppMask_un_1_;
	bool cppVar_10882 = (cppVar_10880 == 0);
	if (cppVar_10882) {
	BIT_VEC cppVar_10883 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10884 = (cppVar_10883 << 3) | 2;
	cppVar_10884 = (cppVar_10884 & cppMask_un_5_);
	BIT_VEC cppVar_10885 = (0 << 5) | cppVar_10884;
	cppVar_10885 = (cppVar_10885 & cppMask_un_8_);
	BIT_VEC cppVar_10886 = IRAM.rd(cppVar_10885);
	cppVar_10874 = cppVar_10886;
	} else {
	BIT_VEC cppVar_10887;
	BIT_VEC cppVar_10888 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10889 = (cppVar_10888 << 3) | 2;
	cppVar_10889 = (cppVar_10889 & cppMask_un_5_);
	BIT_VEC cppVar_10890 = (0 << 5) | cppVar_10889;
	cppVar_10890 = (cppVar_10890 & cppMask_un_8_);
	bool cppVar_10892 = (cppVar_10890 == 128);
	if (cppVar_10892) {
	cppVar_10887 = P0;
	} else {
	BIT_VEC cppVar_10893;
	BIT_VEC cppVar_10894 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10895 = (cppVar_10894 << 3) | 2;
	cppVar_10895 = (cppVar_10895 & cppMask_un_5_);
	BIT_VEC cppVar_10896 = (0 << 5) | cppVar_10895;
	cppVar_10896 = (cppVar_10896 & cppMask_un_8_);
	bool cppVar_10898 = (cppVar_10896 == 129);
	if (cppVar_10898) {
	cppVar_10893 = SP;
	} else {
	BIT_VEC cppVar_10899;
	BIT_VEC cppVar_10900 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10901 = (cppVar_10900 << 3) | 2;
	cppVar_10901 = (cppVar_10901 & cppMask_un_5_);
	BIT_VEC cppVar_10902 = (0 << 5) | cppVar_10901;
	cppVar_10902 = (cppVar_10902 & cppMask_un_8_);
	bool cppVar_10904 = (cppVar_10902 == 130);
	if (cppVar_10904) {
	cppVar_10899 = DPL;
	} else {
	BIT_VEC cppVar_10905;
	BIT_VEC cppVar_10906 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10907 = (cppVar_10906 << 3) | 2;
	cppVar_10907 = (cppVar_10907 & cppMask_un_5_);
	BIT_VEC cppVar_10908 = (0 << 5) | cppVar_10907;
	cppVar_10908 = (cppVar_10908 & cppMask_un_8_);
	bool cppVar_10910 = (cppVar_10908 == 131);
	if (cppVar_10910) {
	cppVar_10905 = DPH;
	} else {
	BIT_VEC cppVar_10911;
	BIT_VEC cppVar_10912 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10913 = (cppVar_10912 << 3) | 2;
	cppVar_10913 = (cppVar_10913 & cppMask_un_5_);
	BIT_VEC cppVar_10914 = (0 << 5) | cppVar_10913;
	cppVar_10914 = (cppVar_10914 & cppMask_un_8_);
	bool cppVar_10916 = (cppVar_10914 == 135);
	if (cppVar_10916) {
	cppVar_10911 = PCON;
	} else {
	BIT_VEC cppVar_10917;
	BIT_VEC cppVar_10918 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10919 = (cppVar_10918 << 3) | 2;
	cppVar_10919 = (cppVar_10919 & cppMask_un_5_);
	BIT_VEC cppVar_10920 = (0 << 5) | cppVar_10919;
	cppVar_10920 = (cppVar_10920 & cppMask_un_8_);
	bool cppVar_10922 = (cppVar_10920 == 136);
	if (cppVar_10922) {
	cppVar_10917 = TCON;
	} else {
	BIT_VEC cppVar_10923;
	BIT_VEC cppVar_10924 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10925 = (cppVar_10924 << 3) | 2;
	cppVar_10925 = (cppVar_10925 & cppMask_un_5_);
	BIT_VEC cppVar_10926 = (0 << 5) | cppVar_10925;
	cppVar_10926 = (cppVar_10926 & cppMask_un_8_);
	bool cppVar_10928 = (cppVar_10926 == 137);
	if (cppVar_10928) {
	cppVar_10923 = TMOD;
	} else {
	BIT_VEC cppVar_10929;
	BIT_VEC cppVar_10930 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10931 = (cppVar_10930 << 3) | 2;
	cppVar_10931 = (cppVar_10931 & cppMask_un_5_);
	BIT_VEC cppVar_10932 = (0 << 5) | cppVar_10931;
	cppVar_10932 = (cppVar_10932 & cppMask_un_8_);
	bool cppVar_10934 = (cppVar_10932 == 138);
	if (cppVar_10934) {
	cppVar_10929 = TL0;
	} else {
	BIT_VEC cppVar_10935;
	BIT_VEC cppVar_10936 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10937 = (cppVar_10936 << 3) | 2;
	cppVar_10937 = (cppVar_10937 & cppMask_un_5_);
	BIT_VEC cppVar_10938 = (0 << 5) | cppVar_10937;
	cppVar_10938 = (cppVar_10938 & cppMask_un_8_);
	bool cppVar_10940 = (cppVar_10938 == 140);
	if (cppVar_10940) {
	cppVar_10935 = TH0;
	} else {
	BIT_VEC cppVar_10941;
	BIT_VEC cppVar_10942 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10943 = (cppVar_10942 << 3) | 2;
	cppVar_10943 = (cppVar_10943 & cppMask_un_5_);
	BIT_VEC cppVar_10944 = (0 << 5) | cppVar_10943;
	cppVar_10944 = (cppVar_10944 & cppMask_un_8_);
	bool cppVar_10946 = (cppVar_10944 == 139);
	if (cppVar_10946) {
	cppVar_10941 = TL1;
	} else {
	BIT_VEC cppVar_10947;
	BIT_VEC cppVar_10948 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10949 = (cppVar_10948 << 3) | 2;
	cppVar_10949 = (cppVar_10949 & cppMask_un_5_);
	BIT_VEC cppVar_10950 = (0 << 5) | cppVar_10949;
	cppVar_10950 = (cppVar_10950 & cppMask_un_8_);
	bool cppVar_10952 = (cppVar_10950 == 141);
	if (cppVar_10952) {
	cppVar_10947 = TH1;
	} else {
	BIT_VEC cppVar_10953;
	BIT_VEC cppVar_10954 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10955 = (cppVar_10954 << 3) | 2;
	cppVar_10955 = (cppVar_10955 & cppMask_un_5_);
	BIT_VEC cppVar_10956 = (0 << 5) | cppVar_10955;
	cppVar_10956 = (cppVar_10956 & cppMask_un_8_);
	bool cppVar_10958 = (cppVar_10956 == 144);
	if (cppVar_10958) {
	cppVar_10953 = P1;
	} else {
	BIT_VEC cppVar_10959;
	BIT_VEC cppVar_10960 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10961 = (cppVar_10960 << 3) | 2;
	cppVar_10961 = (cppVar_10961 & cppMask_un_5_);
	BIT_VEC cppVar_10962 = (0 << 5) | cppVar_10961;
	cppVar_10962 = (cppVar_10962 & cppMask_un_8_);
	bool cppVar_10964 = (cppVar_10962 == 152);
	if (cppVar_10964) {
	cppVar_10959 = SCON;
	} else {
	BIT_VEC cppVar_10965;
	BIT_VEC cppVar_10966 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10967 = (cppVar_10966 << 3) | 2;
	cppVar_10967 = (cppVar_10967 & cppMask_un_5_);
	BIT_VEC cppVar_10968 = (0 << 5) | cppVar_10967;
	cppVar_10968 = (cppVar_10968 & cppMask_un_8_);
	bool cppVar_10970 = (cppVar_10968 == 153);
	if (cppVar_10970) {
	cppVar_10965 = SBUF;
	} else {
	BIT_VEC cppVar_10971;
	BIT_VEC cppVar_10972 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10973 = (cppVar_10972 << 3) | 2;
	cppVar_10973 = (cppVar_10973 & cppMask_un_5_);
	BIT_VEC cppVar_10974 = (0 << 5) | cppVar_10973;
	cppVar_10974 = (cppVar_10974 & cppMask_un_8_);
	bool cppVar_10976 = (cppVar_10974 == 160);
	if (cppVar_10976) {
	cppVar_10971 = P2;
	} else {
	BIT_VEC cppVar_10977;
	BIT_VEC cppVar_10978 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10979 = (cppVar_10978 << 3) | 2;
	cppVar_10979 = (cppVar_10979 & cppMask_un_5_);
	BIT_VEC cppVar_10980 = (0 << 5) | cppVar_10979;
	cppVar_10980 = (cppVar_10980 & cppMask_un_8_);
	bool cppVar_10982 = (cppVar_10980 == 168);
	if (cppVar_10982) {
	cppVar_10977 = IE;
	} else {
	BIT_VEC cppVar_10983;
	BIT_VEC cppVar_10984 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10985 = (cppVar_10984 << 3) | 2;
	cppVar_10985 = (cppVar_10985 & cppMask_un_5_);
	BIT_VEC cppVar_10986 = (0 << 5) | cppVar_10985;
	cppVar_10986 = (cppVar_10986 & cppMask_un_8_);
	bool cppVar_10988 = (cppVar_10986 == 176);
	if (cppVar_10988) {
	cppVar_10983 = P3;
	} else {
	BIT_VEC cppVar_10989;
	BIT_VEC cppVar_10990 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10991 = (cppVar_10990 << 3) | 2;
	cppVar_10991 = (cppVar_10991 & cppMask_un_5_);
	BIT_VEC cppVar_10992 = (0 << 5) | cppVar_10991;
	cppVar_10992 = (cppVar_10992 & cppMask_un_8_);
	bool cppVar_10994 = (cppVar_10992 == 184);
	if (cppVar_10994) {
	cppVar_10989 = IP;
	} else {
	BIT_VEC cppVar_10995;
	BIT_VEC cppVar_10996 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_10997 = (cppVar_10996 << 3) | 2;
	cppVar_10997 = (cppVar_10997 & cppMask_un_5_);
	BIT_VEC cppVar_10998 = (0 << 5) | cppVar_10997;
	cppVar_10998 = (cppVar_10998 & cppMask_un_8_);
	bool cppVar_11000 = (cppVar_10998 == 208);
	if (cppVar_11000) {
	cppVar_10995 = PSW;
	} else {
	BIT_VEC cppVar_11001;
	BIT_VEC cppVar_11002 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11003 = (cppVar_11002 << 3) | 2;
	cppVar_11003 = (cppVar_11003 & cppMask_un_5_);
	BIT_VEC cppVar_11004 = (0 << 5) | cppVar_11003;
	cppVar_11004 = (cppVar_11004 & cppMask_un_8_);
	bool cppVar_11006 = (cppVar_11004 == 224);
	if (cppVar_11006) {
	cppVar_11001 = ACC;
	} else {
	BIT_VEC cppVar_11007;
	BIT_VEC cppVar_11008 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11009 = (cppVar_11008 << 3) | 2;
	cppVar_11009 = (cppVar_11009 & cppMask_un_5_);
	BIT_VEC cppVar_11010 = (0 << 5) | cppVar_11009;
	cppVar_11010 = (cppVar_11010 & cppMask_un_8_);
	bool cppVar_11012 = (cppVar_11010 == 240);
	if (cppVar_11012) {
	cppVar_11007 = B;
	} else {
	cppVar_11007 = 0;
	}
	cppVar_11001 = cppVar_11007;
	}
	cppVar_10995 = cppVar_11001;
	}
	cppVar_10989 = cppVar_10995;
	}
	cppVar_10983 = cppVar_10989;
	}
	cppVar_10977 = cppVar_10983;
	}
	cppVar_10971 = cppVar_10977;
	}
	cppVar_10965 = cppVar_10971;
	}
	cppVar_10959 = cppVar_10965;
	}
	cppVar_10953 = cppVar_10959;
	}
	cppVar_10947 = cppVar_10953;
	}
	cppVar_10941 = cppVar_10947;
	}
	cppVar_10935 = cppVar_10941;
	}
	cppVar_10929 = cppVar_10935;
	}
	cppVar_10923 = cppVar_10929;
	}
	cppVar_10917 = cppVar_10923;
	}
	cppVar_10911 = cppVar_10917;
	}
	cppVar_10905 = cppVar_10911;
	}
	cppVar_10899 = cppVar_10905;
	}
	cppVar_10893 = cppVar_10899;
	}
	cppVar_10887 = cppVar_10893;
	}
	cppVar_10874 = cppVar_10887;
	}
	cppVar_10868 = cppVar_10874;
	} else {
	cppVar_10868 = DPL;
	}
	cppVar_10864 = cppVar_10868;
	} else {
	BIT_VEC cppVar_11014;
	BIT_VEC cppVar_11015 = ROM.rd(PC);
	bool cppVar_11017 = (cppVar_11015 == 137);
	if (cppVar_11017) {
	BIT_VEC cppVar_11018;
	BIT_VEC cppVar_11020 = PC + 1;
	cppVar_11020 = (cppVar_11020 & cppMask_un_16_);
	BIT_VEC cppVar_11021 = ROM.rd(cppVar_11020);
	bool cppVar_11023 = (cppVar_11021 == 130);
	if (cppVar_11023) {
	BIT_VEC cppVar_11024;
	BIT_VEC cppVar_11026 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11028 = (cppVar_11026 << 3) | 1;
	cppVar_11028 = (cppVar_11028 & cppMask_un_5_);
	BIT_VEC cppVar_11029 = (0 << 5) | cppVar_11028;
	cppVar_11029 = (cppVar_11029 & cppMask_un_8_);
	BIT_VEC cppVar_11030 = (cppVar_11029 >> 7) & cppMask_un_1_;
	bool cppVar_11032 = (cppVar_11030 == 0);
	if (cppVar_11032) {
	BIT_VEC cppVar_11033 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11034 = (cppVar_11033 << 3) | 1;
	cppVar_11034 = (cppVar_11034 & cppMask_un_5_);
	BIT_VEC cppVar_11035 = (0 << 5) | cppVar_11034;
	cppVar_11035 = (cppVar_11035 & cppMask_un_8_);
	BIT_VEC cppVar_11036 = IRAM.rd(cppVar_11035);
	cppVar_11024 = cppVar_11036;
	} else {
	BIT_VEC cppVar_11037;
	BIT_VEC cppVar_11038 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11039 = (cppVar_11038 << 3) | 1;
	cppVar_11039 = (cppVar_11039 & cppMask_un_5_);
	BIT_VEC cppVar_11040 = (0 << 5) | cppVar_11039;
	cppVar_11040 = (cppVar_11040 & cppMask_un_8_);
	bool cppVar_11042 = (cppVar_11040 == 128);
	if (cppVar_11042) {
	cppVar_11037 = P0;
	} else {
	BIT_VEC cppVar_11043;
	BIT_VEC cppVar_11044 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11045 = (cppVar_11044 << 3) | 1;
	cppVar_11045 = (cppVar_11045 & cppMask_un_5_);
	BIT_VEC cppVar_11046 = (0 << 5) | cppVar_11045;
	cppVar_11046 = (cppVar_11046 & cppMask_un_8_);
	bool cppVar_11048 = (cppVar_11046 == 129);
	if (cppVar_11048) {
	cppVar_11043 = SP;
	} else {
	BIT_VEC cppVar_11049;
	BIT_VEC cppVar_11050 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11051 = (cppVar_11050 << 3) | 1;
	cppVar_11051 = (cppVar_11051 & cppMask_un_5_);
	BIT_VEC cppVar_11052 = (0 << 5) | cppVar_11051;
	cppVar_11052 = (cppVar_11052 & cppMask_un_8_);
	bool cppVar_11054 = (cppVar_11052 == 130);
	if (cppVar_11054) {
	cppVar_11049 = DPL;
	} else {
	BIT_VEC cppVar_11055;
	BIT_VEC cppVar_11056 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11057 = (cppVar_11056 << 3) | 1;
	cppVar_11057 = (cppVar_11057 & cppMask_un_5_);
	BIT_VEC cppVar_11058 = (0 << 5) | cppVar_11057;
	cppVar_11058 = (cppVar_11058 & cppMask_un_8_);
	bool cppVar_11060 = (cppVar_11058 == 131);
	if (cppVar_11060) {
	cppVar_11055 = DPH;
	} else {
	BIT_VEC cppVar_11061;
	BIT_VEC cppVar_11062 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11063 = (cppVar_11062 << 3) | 1;
	cppVar_11063 = (cppVar_11063 & cppMask_un_5_);
	BIT_VEC cppVar_11064 = (0 << 5) | cppVar_11063;
	cppVar_11064 = (cppVar_11064 & cppMask_un_8_);
	bool cppVar_11066 = (cppVar_11064 == 135);
	if (cppVar_11066) {
	cppVar_11061 = PCON;
	} else {
	BIT_VEC cppVar_11067;
	BIT_VEC cppVar_11068 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11069 = (cppVar_11068 << 3) | 1;
	cppVar_11069 = (cppVar_11069 & cppMask_un_5_);
	BIT_VEC cppVar_11070 = (0 << 5) | cppVar_11069;
	cppVar_11070 = (cppVar_11070 & cppMask_un_8_);
	bool cppVar_11072 = (cppVar_11070 == 136);
	if (cppVar_11072) {
	cppVar_11067 = TCON;
	} else {
	BIT_VEC cppVar_11073;
	BIT_VEC cppVar_11074 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11075 = (cppVar_11074 << 3) | 1;
	cppVar_11075 = (cppVar_11075 & cppMask_un_5_);
	BIT_VEC cppVar_11076 = (0 << 5) | cppVar_11075;
	cppVar_11076 = (cppVar_11076 & cppMask_un_8_);
	bool cppVar_11078 = (cppVar_11076 == 137);
	if (cppVar_11078) {
	cppVar_11073 = TMOD;
	} else {
	BIT_VEC cppVar_11079;
	BIT_VEC cppVar_11080 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11081 = (cppVar_11080 << 3) | 1;
	cppVar_11081 = (cppVar_11081 & cppMask_un_5_);
	BIT_VEC cppVar_11082 = (0 << 5) | cppVar_11081;
	cppVar_11082 = (cppVar_11082 & cppMask_un_8_);
	bool cppVar_11084 = (cppVar_11082 == 138);
	if (cppVar_11084) {
	cppVar_11079 = TL0;
	} else {
	BIT_VEC cppVar_11085;
	BIT_VEC cppVar_11086 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11087 = (cppVar_11086 << 3) | 1;
	cppVar_11087 = (cppVar_11087 & cppMask_un_5_);
	BIT_VEC cppVar_11088 = (0 << 5) | cppVar_11087;
	cppVar_11088 = (cppVar_11088 & cppMask_un_8_);
	bool cppVar_11090 = (cppVar_11088 == 140);
	if (cppVar_11090) {
	cppVar_11085 = TH0;
	} else {
	BIT_VEC cppVar_11091;
	BIT_VEC cppVar_11092 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11093 = (cppVar_11092 << 3) | 1;
	cppVar_11093 = (cppVar_11093 & cppMask_un_5_);
	BIT_VEC cppVar_11094 = (0 << 5) | cppVar_11093;
	cppVar_11094 = (cppVar_11094 & cppMask_un_8_);
	bool cppVar_11096 = (cppVar_11094 == 139);
	if (cppVar_11096) {
	cppVar_11091 = TL1;
	} else {
	BIT_VEC cppVar_11097;
	BIT_VEC cppVar_11098 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11099 = (cppVar_11098 << 3) | 1;
	cppVar_11099 = (cppVar_11099 & cppMask_un_5_);
	BIT_VEC cppVar_11100 = (0 << 5) | cppVar_11099;
	cppVar_11100 = (cppVar_11100 & cppMask_un_8_);
	bool cppVar_11102 = (cppVar_11100 == 141);
	if (cppVar_11102) {
	cppVar_11097 = TH1;
	} else {
	BIT_VEC cppVar_11103;
	BIT_VEC cppVar_11104 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11105 = (cppVar_11104 << 3) | 1;
	cppVar_11105 = (cppVar_11105 & cppMask_un_5_);
	BIT_VEC cppVar_11106 = (0 << 5) | cppVar_11105;
	cppVar_11106 = (cppVar_11106 & cppMask_un_8_);
	bool cppVar_11108 = (cppVar_11106 == 144);
	if (cppVar_11108) {
	cppVar_11103 = P1;
	} else {
	BIT_VEC cppVar_11109;
	BIT_VEC cppVar_11110 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11111 = (cppVar_11110 << 3) | 1;
	cppVar_11111 = (cppVar_11111 & cppMask_un_5_);
	BIT_VEC cppVar_11112 = (0 << 5) | cppVar_11111;
	cppVar_11112 = (cppVar_11112 & cppMask_un_8_);
	bool cppVar_11114 = (cppVar_11112 == 152);
	if (cppVar_11114) {
	cppVar_11109 = SCON;
	} else {
	BIT_VEC cppVar_11115;
	BIT_VEC cppVar_11116 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11117 = (cppVar_11116 << 3) | 1;
	cppVar_11117 = (cppVar_11117 & cppMask_un_5_);
	BIT_VEC cppVar_11118 = (0 << 5) | cppVar_11117;
	cppVar_11118 = (cppVar_11118 & cppMask_un_8_);
	bool cppVar_11120 = (cppVar_11118 == 153);
	if (cppVar_11120) {
	cppVar_11115 = SBUF;
	} else {
	BIT_VEC cppVar_11121;
	BIT_VEC cppVar_11122 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11123 = (cppVar_11122 << 3) | 1;
	cppVar_11123 = (cppVar_11123 & cppMask_un_5_);
	BIT_VEC cppVar_11124 = (0 << 5) | cppVar_11123;
	cppVar_11124 = (cppVar_11124 & cppMask_un_8_);
	bool cppVar_11126 = (cppVar_11124 == 160);
	if (cppVar_11126) {
	cppVar_11121 = P2;
	} else {
	BIT_VEC cppVar_11127;
	BIT_VEC cppVar_11128 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11129 = (cppVar_11128 << 3) | 1;
	cppVar_11129 = (cppVar_11129 & cppMask_un_5_);
	BIT_VEC cppVar_11130 = (0 << 5) | cppVar_11129;
	cppVar_11130 = (cppVar_11130 & cppMask_un_8_);
	bool cppVar_11132 = (cppVar_11130 == 168);
	if (cppVar_11132) {
	cppVar_11127 = IE;
	} else {
	BIT_VEC cppVar_11133;
	BIT_VEC cppVar_11134 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11135 = (cppVar_11134 << 3) | 1;
	cppVar_11135 = (cppVar_11135 & cppMask_un_5_);
	BIT_VEC cppVar_11136 = (0 << 5) | cppVar_11135;
	cppVar_11136 = (cppVar_11136 & cppMask_un_8_);
	bool cppVar_11138 = (cppVar_11136 == 176);
	if (cppVar_11138) {
	cppVar_11133 = P3;
	} else {
	BIT_VEC cppVar_11139;
	BIT_VEC cppVar_11140 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11141 = (cppVar_11140 << 3) | 1;
	cppVar_11141 = (cppVar_11141 & cppMask_un_5_);
	BIT_VEC cppVar_11142 = (0 << 5) | cppVar_11141;
	cppVar_11142 = (cppVar_11142 & cppMask_un_8_);
	bool cppVar_11144 = (cppVar_11142 == 184);
	if (cppVar_11144) {
	cppVar_11139 = IP;
	} else {
	BIT_VEC cppVar_11145;
	BIT_VEC cppVar_11146 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11147 = (cppVar_11146 << 3) | 1;
	cppVar_11147 = (cppVar_11147 & cppMask_un_5_);
	BIT_VEC cppVar_11148 = (0 << 5) | cppVar_11147;
	cppVar_11148 = (cppVar_11148 & cppMask_un_8_);
	bool cppVar_11150 = (cppVar_11148 == 208);
	if (cppVar_11150) {
	cppVar_11145 = PSW;
	} else {
	BIT_VEC cppVar_11151;
	BIT_VEC cppVar_11152 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11153 = (cppVar_11152 << 3) | 1;
	cppVar_11153 = (cppVar_11153 & cppMask_un_5_);
	BIT_VEC cppVar_11154 = (0 << 5) | cppVar_11153;
	cppVar_11154 = (cppVar_11154 & cppMask_un_8_);
	bool cppVar_11156 = (cppVar_11154 == 224);
	if (cppVar_11156) {
	cppVar_11151 = ACC;
	} else {
	BIT_VEC cppVar_11157;
	BIT_VEC cppVar_11158 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11159 = (cppVar_11158 << 3) | 1;
	cppVar_11159 = (cppVar_11159 & cppMask_un_5_);
	BIT_VEC cppVar_11160 = (0 << 5) | cppVar_11159;
	cppVar_11160 = (cppVar_11160 & cppMask_un_8_);
	bool cppVar_11162 = (cppVar_11160 == 240);
	if (cppVar_11162) {
	cppVar_11157 = B;
	} else {
	cppVar_11157 = 0;
	}
	cppVar_11151 = cppVar_11157;
	}
	cppVar_11145 = cppVar_11151;
	}
	cppVar_11139 = cppVar_11145;
	}
	cppVar_11133 = cppVar_11139;
	}
	cppVar_11127 = cppVar_11133;
	}
	cppVar_11121 = cppVar_11127;
	}
	cppVar_11115 = cppVar_11121;
	}
	cppVar_11109 = cppVar_11115;
	}
	cppVar_11103 = cppVar_11109;
	}
	cppVar_11097 = cppVar_11103;
	}
	cppVar_11091 = cppVar_11097;
	}
	cppVar_11085 = cppVar_11091;
	}
	cppVar_11079 = cppVar_11085;
	}
	cppVar_11073 = cppVar_11079;
	}
	cppVar_11067 = cppVar_11073;
	}
	cppVar_11061 = cppVar_11067;
	}
	cppVar_11055 = cppVar_11061;
	}
	cppVar_11049 = cppVar_11055;
	}
	cppVar_11043 = cppVar_11049;
	}
	cppVar_11037 = cppVar_11043;
	}
	cppVar_11024 = cppVar_11037;
	}
	cppVar_11018 = cppVar_11024;
	} else {
	cppVar_11018 = DPL;
	}
	cppVar_11014 = cppVar_11018;
	} else {
	BIT_VEC cppVar_11164;
	BIT_VEC cppVar_11165 = ROM.rd(PC);
	bool cppVar_11167 = (cppVar_11165 == 136);
	if (cppVar_11167) {
	BIT_VEC cppVar_11168;
	BIT_VEC cppVar_11170 = PC + 1;
	cppVar_11170 = (cppVar_11170 & cppMask_un_16_);
	BIT_VEC cppVar_11171 = ROM.rd(cppVar_11170);
	bool cppVar_11173 = (cppVar_11171 == 130);
	if (cppVar_11173) {
	BIT_VEC cppVar_11174;
	BIT_VEC cppVar_11176 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11178 = (cppVar_11176 << 3) | 0;
	cppVar_11178 = (cppVar_11178 & cppMask_un_5_);
	BIT_VEC cppVar_11179 = (0 << 5) | cppVar_11178;
	cppVar_11179 = (cppVar_11179 & cppMask_un_8_);
	BIT_VEC cppVar_11180 = (cppVar_11179 >> 7) & cppMask_un_1_;
	bool cppVar_11182 = (cppVar_11180 == 0);
	if (cppVar_11182) {
	BIT_VEC cppVar_11183 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11184 = (cppVar_11183 << 3) | 0;
	cppVar_11184 = (cppVar_11184 & cppMask_un_5_);
	BIT_VEC cppVar_11185 = (0 << 5) | cppVar_11184;
	cppVar_11185 = (cppVar_11185 & cppMask_un_8_);
	BIT_VEC cppVar_11186 = IRAM.rd(cppVar_11185);
	cppVar_11174 = cppVar_11186;
	} else {
	BIT_VEC cppVar_11187;
	BIT_VEC cppVar_11188 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11189 = (cppVar_11188 << 3) | 0;
	cppVar_11189 = (cppVar_11189 & cppMask_un_5_);
	BIT_VEC cppVar_11190 = (0 << 5) | cppVar_11189;
	cppVar_11190 = (cppVar_11190 & cppMask_un_8_);
	bool cppVar_11192 = (cppVar_11190 == 128);
	if (cppVar_11192) {
	cppVar_11187 = P0;
	} else {
	BIT_VEC cppVar_11193;
	BIT_VEC cppVar_11194 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11195 = (cppVar_11194 << 3) | 0;
	cppVar_11195 = (cppVar_11195 & cppMask_un_5_);
	BIT_VEC cppVar_11196 = (0 << 5) | cppVar_11195;
	cppVar_11196 = (cppVar_11196 & cppMask_un_8_);
	bool cppVar_11198 = (cppVar_11196 == 129);
	if (cppVar_11198) {
	cppVar_11193 = SP;
	} else {
	BIT_VEC cppVar_11199;
	BIT_VEC cppVar_11200 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11201 = (cppVar_11200 << 3) | 0;
	cppVar_11201 = (cppVar_11201 & cppMask_un_5_);
	BIT_VEC cppVar_11202 = (0 << 5) | cppVar_11201;
	cppVar_11202 = (cppVar_11202 & cppMask_un_8_);
	bool cppVar_11204 = (cppVar_11202 == 130);
	if (cppVar_11204) {
	cppVar_11199 = DPL;
	} else {
	BIT_VEC cppVar_11205;
	BIT_VEC cppVar_11206 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11207 = (cppVar_11206 << 3) | 0;
	cppVar_11207 = (cppVar_11207 & cppMask_un_5_);
	BIT_VEC cppVar_11208 = (0 << 5) | cppVar_11207;
	cppVar_11208 = (cppVar_11208 & cppMask_un_8_);
	bool cppVar_11210 = (cppVar_11208 == 131);
	if (cppVar_11210) {
	cppVar_11205 = DPH;
	} else {
	BIT_VEC cppVar_11211;
	BIT_VEC cppVar_11212 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11213 = (cppVar_11212 << 3) | 0;
	cppVar_11213 = (cppVar_11213 & cppMask_un_5_);
	BIT_VEC cppVar_11214 = (0 << 5) | cppVar_11213;
	cppVar_11214 = (cppVar_11214 & cppMask_un_8_);
	bool cppVar_11216 = (cppVar_11214 == 135);
	if (cppVar_11216) {
	cppVar_11211 = PCON;
	} else {
	BIT_VEC cppVar_11217;
	BIT_VEC cppVar_11218 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11219 = (cppVar_11218 << 3) | 0;
	cppVar_11219 = (cppVar_11219 & cppMask_un_5_);
	BIT_VEC cppVar_11220 = (0 << 5) | cppVar_11219;
	cppVar_11220 = (cppVar_11220 & cppMask_un_8_);
	bool cppVar_11222 = (cppVar_11220 == 136);
	if (cppVar_11222) {
	cppVar_11217 = TCON;
	} else {
	BIT_VEC cppVar_11223;
	BIT_VEC cppVar_11224 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11225 = (cppVar_11224 << 3) | 0;
	cppVar_11225 = (cppVar_11225 & cppMask_un_5_);
	BIT_VEC cppVar_11226 = (0 << 5) | cppVar_11225;
	cppVar_11226 = (cppVar_11226 & cppMask_un_8_);
	bool cppVar_11228 = (cppVar_11226 == 137);
	if (cppVar_11228) {
	cppVar_11223 = TMOD;
	} else {
	BIT_VEC cppVar_11229;
	BIT_VEC cppVar_11230 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11231 = (cppVar_11230 << 3) | 0;
	cppVar_11231 = (cppVar_11231 & cppMask_un_5_);
	BIT_VEC cppVar_11232 = (0 << 5) | cppVar_11231;
	cppVar_11232 = (cppVar_11232 & cppMask_un_8_);
	bool cppVar_11234 = (cppVar_11232 == 138);
	if (cppVar_11234) {
	cppVar_11229 = TL0;
	} else {
	BIT_VEC cppVar_11235;
	BIT_VEC cppVar_11236 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11237 = (cppVar_11236 << 3) | 0;
	cppVar_11237 = (cppVar_11237 & cppMask_un_5_);
	BIT_VEC cppVar_11238 = (0 << 5) | cppVar_11237;
	cppVar_11238 = (cppVar_11238 & cppMask_un_8_);
	bool cppVar_11240 = (cppVar_11238 == 140);
	if (cppVar_11240) {
	cppVar_11235 = TH0;
	} else {
	BIT_VEC cppVar_11241;
	BIT_VEC cppVar_11242 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11243 = (cppVar_11242 << 3) | 0;
	cppVar_11243 = (cppVar_11243 & cppMask_un_5_);
	BIT_VEC cppVar_11244 = (0 << 5) | cppVar_11243;
	cppVar_11244 = (cppVar_11244 & cppMask_un_8_);
	bool cppVar_11246 = (cppVar_11244 == 139);
	if (cppVar_11246) {
	cppVar_11241 = TL1;
	} else {
	BIT_VEC cppVar_11247;
	BIT_VEC cppVar_11248 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11249 = (cppVar_11248 << 3) | 0;
	cppVar_11249 = (cppVar_11249 & cppMask_un_5_);
	BIT_VEC cppVar_11250 = (0 << 5) | cppVar_11249;
	cppVar_11250 = (cppVar_11250 & cppMask_un_8_);
	bool cppVar_11252 = (cppVar_11250 == 141);
	if (cppVar_11252) {
	cppVar_11247 = TH1;
	} else {
	BIT_VEC cppVar_11253;
	BIT_VEC cppVar_11254 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11255 = (cppVar_11254 << 3) | 0;
	cppVar_11255 = (cppVar_11255 & cppMask_un_5_);
	BIT_VEC cppVar_11256 = (0 << 5) | cppVar_11255;
	cppVar_11256 = (cppVar_11256 & cppMask_un_8_);
	bool cppVar_11258 = (cppVar_11256 == 144);
	if (cppVar_11258) {
	cppVar_11253 = P1;
	} else {
	BIT_VEC cppVar_11259;
	BIT_VEC cppVar_11260 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11261 = (cppVar_11260 << 3) | 0;
	cppVar_11261 = (cppVar_11261 & cppMask_un_5_);
	BIT_VEC cppVar_11262 = (0 << 5) | cppVar_11261;
	cppVar_11262 = (cppVar_11262 & cppMask_un_8_);
	bool cppVar_11264 = (cppVar_11262 == 152);
	if (cppVar_11264) {
	cppVar_11259 = SCON;
	} else {
	BIT_VEC cppVar_11265;
	BIT_VEC cppVar_11266 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11267 = (cppVar_11266 << 3) | 0;
	cppVar_11267 = (cppVar_11267 & cppMask_un_5_);
	BIT_VEC cppVar_11268 = (0 << 5) | cppVar_11267;
	cppVar_11268 = (cppVar_11268 & cppMask_un_8_);
	bool cppVar_11270 = (cppVar_11268 == 153);
	if (cppVar_11270) {
	cppVar_11265 = SBUF;
	} else {
	BIT_VEC cppVar_11271;
	BIT_VEC cppVar_11272 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11273 = (cppVar_11272 << 3) | 0;
	cppVar_11273 = (cppVar_11273 & cppMask_un_5_);
	BIT_VEC cppVar_11274 = (0 << 5) | cppVar_11273;
	cppVar_11274 = (cppVar_11274 & cppMask_un_8_);
	bool cppVar_11276 = (cppVar_11274 == 160);
	if (cppVar_11276) {
	cppVar_11271 = P2;
	} else {
	BIT_VEC cppVar_11277;
	BIT_VEC cppVar_11278 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11279 = (cppVar_11278 << 3) | 0;
	cppVar_11279 = (cppVar_11279 & cppMask_un_5_);
	BIT_VEC cppVar_11280 = (0 << 5) | cppVar_11279;
	cppVar_11280 = (cppVar_11280 & cppMask_un_8_);
	bool cppVar_11282 = (cppVar_11280 == 168);
	if (cppVar_11282) {
	cppVar_11277 = IE;
	} else {
	BIT_VEC cppVar_11283;
	BIT_VEC cppVar_11284 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11285 = (cppVar_11284 << 3) | 0;
	cppVar_11285 = (cppVar_11285 & cppMask_un_5_);
	BIT_VEC cppVar_11286 = (0 << 5) | cppVar_11285;
	cppVar_11286 = (cppVar_11286 & cppMask_un_8_);
	bool cppVar_11288 = (cppVar_11286 == 176);
	if (cppVar_11288) {
	cppVar_11283 = P3;
	} else {
	BIT_VEC cppVar_11289;
	BIT_VEC cppVar_11290 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11291 = (cppVar_11290 << 3) | 0;
	cppVar_11291 = (cppVar_11291 & cppMask_un_5_);
	BIT_VEC cppVar_11292 = (0 << 5) | cppVar_11291;
	cppVar_11292 = (cppVar_11292 & cppMask_un_8_);
	bool cppVar_11294 = (cppVar_11292 == 184);
	if (cppVar_11294) {
	cppVar_11289 = IP;
	} else {
	BIT_VEC cppVar_11295;
	BIT_VEC cppVar_11296 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11297 = (cppVar_11296 << 3) | 0;
	cppVar_11297 = (cppVar_11297 & cppMask_un_5_);
	BIT_VEC cppVar_11298 = (0 << 5) | cppVar_11297;
	cppVar_11298 = (cppVar_11298 & cppMask_un_8_);
	bool cppVar_11300 = (cppVar_11298 == 208);
	if (cppVar_11300) {
	cppVar_11295 = PSW;
	} else {
	BIT_VEC cppVar_11301;
	BIT_VEC cppVar_11302 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11303 = (cppVar_11302 << 3) | 0;
	cppVar_11303 = (cppVar_11303 & cppMask_un_5_);
	BIT_VEC cppVar_11304 = (0 << 5) | cppVar_11303;
	cppVar_11304 = (cppVar_11304 & cppMask_un_8_);
	bool cppVar_11306 = (cppVar_11304 == 224);
	if (cppVar_11306) {
	cppVar_11301 = ACC;
	} else {
	BIT_VEC cppVar_11307;
	BIT_VEC cppVar_11308 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11309 = (cppVar_11308 << 3) | 0;
	cppVar_11309 = (cppVar_11309 & cppMask_un_5_);
	BIT_VEC cppVar_11310 = (0 << 5) | cppVar_11309;
	cppVar_11310 = (cppVar_11310 & cppMask_un_8_);
	bool cppVar_11312 = (cppVar_11310 == 240);
	if (cppVar_11312) {
	cppVar_11307 = B;
	} else {
	cppVar_11307 = 0;
	}
	cppVar_11301 = cppVar_11307;
	}
	cppVar_11295 = cppVar_11301;
	}
	cppVar_11289 = cppVar_11295;
	}
	cppVar_11283 = cppVar_11289;
	}
	cppVar_11277 = cppVar_11283;
	}
	cppVar_11271 = cppVar_11277;
	}
	cppVar_11265 = cppVar_11271;
	}
	cppVar_11259 = cppVar_11265;
	}
	cppVar_11253 = cppVar_11259;
	}
	cppVar_11247 = cppVar_11253;
	}
	cppVar_11241 = cppVar_11247;
	}
	cppVar_11235 = cppVar_11241;
	}
	cppVar_11229 = cppVar_11235;
	}
	cppVar_11223 = cppVar_11229;
	}
	cppVar_11217 = cppVar_11223;
	}
	cppVar_11211 = cppVar_11217;
	}
	cppVar_11205 = cppVar_11211;
	}
	cppVar_11199 = cppVar_11205;
	}
	cppVar_11193 = cppVar_11199;
	}
	cppVar_11187 = cppVar_11193;
	}
	cppVar_11174 = cppVar_11187;
	}
	cppVar_11168 = cppVar_11174;
	} else {
	cppVar_11168 = DPL;
	}
	cppVar_11164 = cppVar_11168;
	} else {
	BIT_VEC cppVar_11314;
	BIT_VEC cppVar_11315 = ROM.rd(PC);
	bool cppVar_11317 = (cppVar_11315 == 135);
	if (cppVar_11317) {
	BIT_VEC cppVar_11318;
	BIT_VEC cppVar_11320 = PC + 1;
	cppVar_11320 = (cppVar_11320 & cppMask_un_16_);
	BIT_VEC cppVar_11321 = ROM.rd(cppVar_11320);
	bool cppVar_11323 = (cppVar_11321 == 130);
	if (cppVar_11323) {
	BIT_VEC cppVar_11325 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11327 = (cppVar_11325 << 3) | 1;
	cppVar_11327 = (cppVar_11327 & cppMask_un_5_);
	BIT_VEC cppVar_11328 = (0 << 5) | cppVar_11327;
	cppVar_11328 = (cppVar_11328 & cppMask_un_8_);
	BIT_VEC cppVar_11329 = IRAM.rd(cppVar_11328);
	BIT_VEC cppVar_11330 = IRAM.rd(cppVar_11329);
	cppVar_11318 = cppVar_11330;
	} else {
	cppVar_11318 = DPL;
	}
	cppVar_11314 = cppVar_11318;
	} else {
	BIT_VEC cppVar_11331;
	BIT_VEC cppVar_11332 = ROM.rd(PC);
	bool cppVar_11334 = (cppVar_11332 == 134);
	if (cppVar_11334) {
	BIT_VEC cppVar_11335;
	BIT_VEC cppVar_11337 = PC + 1;
	cppVar_11337 = (cppVar_11337 & cppMask_un_16_);
	BIT_VEC cppVar_11338 = ROM.rd(cppVar_11337);
	bool cppVar_11340 = (cppVar_11338 == 130);
	if (cppVar_11340) {
	BIT_VEC cppVar_11342 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_11344 = (cppVar_11342 << 3) | 0;
	cppVar_11344 = (cppVar_11344 & cppMask_un_5_);
	BIT_VEC cppVar_11345 = (0 << 5) | cppVar_11344;
	cppVar_11345 = (cppVar_11345 & cppMask_un_8_);
	BIT_VEC cppVar_11346 = IRAM.rd(cppVar_11345);
	BIT_VEC cppVar_11347 = IRAM.rd(cppVar_11346);
	cppVar_11335 = cppVar_11347;
	} else {
	cppVar_11335 = DPL;
	}
	cppVar_11331 = cppVar_11335;
	} else {
	BIT_VEC cppVar_11348;
	BIT_VEC cppVar_11349 = ROM.rd(PC);
	bool cppVar_11351 = (cppVar_11349 == 133);
	if (cppVar_11351) {
	BIT_VEC cppVar_11352;
	BIT_VEC cppVar_11354 = PC + 2;
	cppVar_11354 = (cppVar_11354 & cppMask_un_16_);
	BIT_VEC cppVar_11355 = ROM.rd(cppVar_11354);
	bool cppVar_11357 = (cppVar_11355 == 130);
	if (cppVar_11357) {
	BIT_VEC cppVar_11358;
	BIT_VEC cppVar_11360 = PC + 1;
	cppVar_11360 = (cppVar_11360 & cppMask_un_16_);
	BIT_VEC cppVar_11361 = ROM.rd(cppVar_11360);
	BIT_VEC cppVar_11362 = (cppVar_11361 >> 7) & cppMask_un_1_;
	bool cppVar_11364 = (cppVar_11362 == 0);
	if (cppVar_11364) {
	BIT_VEC cppVar_11365 = PC + 1;
	cppVar_11365 = (cppVar_11365 & cppMask_un_16_);
	BIT_VEC cppVar_11366 = ROM.rd(cppVar_11365);
	BIT_VEC cppVar_11367 = IRAM.rd(cppVar_11366);
	cppVar_11358 = cppVar_11367;
	} else {
	BIT_VEC cppVar_11368;
	BIT_VEC cppVar_11369 = PC + 1;
	cppVar_11369 = (cppVar_11369 & cppMask_un_16_);
	BIT_VEC cppVar_11370 = ROM.rd(cppVar_11369);
	bool cppVar_11372 = (cppVar_11370 == 128);
	if (cppVar_11372) {
	cppVar_11368 = P0;
	} else {
	BIT_VEC cppVar_11373;
	BIT_VEC cppVar_11374 = PC + 1;
	cppVar_11374 = (cppVar_11374 & cppMask_un_16_);
	BIT_VEC cppVar_11375 = ROM.rd(cppVar_11374);
	bool cppVar_11377 = (cppVar_11375 == 129);
	if (cppVar_11377) {
	cppVar_11373 = SP;
	} else {
	BIT_VEC cppVar_11378;
	BIT_VEC cppVar_11379 = PC + 1;
	cppVar_11379 = (cppVar_11379 & cppMask_un_16_);
	BIT_VEC cppVar_11380 = ROM.rd(cppVar_11379);
	bool cppVar_11382 = (cppVar_11380 == 130);
	if (cppVar_11382) {
	cppVar_11378 = DPL;
	} else {
	BIT_VEC cppVar_11383;
	BIT_VEC cppVar_11384 = PC + 1;
	cppVar_11384 = (cppVar_11384 & cppMask_un_16_);
	BIT_VEC cppVar_11385 = ROM.rd(cppVar_11384);
	bool cppVar_11387 = (cppVar_11385 == 131);
	if (cppVar_11387) {
	cppVar_11383 = DPH;
	} else {
	BIT_VEC cppVar_11388;
	BIT_VEC cppVar_11389 = PC + 1;
	cppVar_11389 = (cppVar_11389 & cppMask_un_16_);
	BIT_VEC cppVar_11390 = ROM.rd(cppVar_11389);
	bool cppVar_11392 = (cppVar_11390 == 135);
	if (cppVar_11392) {
	cppVar_11388 = PCON;
	} else {
	BIT_VEC cppVar_11393;
	BIT_VEC cppVar_11394 = PC + 1;
	cppVar_11394 = (cppVar_11394 & cppMask_un_16_);
	BIT_VEC cppVar_11395 = ROM.rd(cppVar_11394);
	bool cppVar_11397 = (cppVar_11395 == 136);
	if (cppVar_11397) {
	cppVar_11393 = TCON;
	} else {
	BIT_VEC cppVar_11398;
	BIT_VEC cppVar_11399 = PC + 1;
	cppVar_11399 = (cppVar_11399 & cppMask_un_16_);
	BIT_VEC cppVar_11400 = ROM.rd(cppVar_11399);
	bool cppVar_11402 = (cppVar_11400 == 137);
	if (cppVar_11402) {
	cppVar_11398 = TMOD;
	} else {
	BIT_VEC cppVar_11403;
	BIT_VEC cppVar_11404 = PC + 1;
	cppVar_11404 = (cppVar_11404 & cppMask_un_16_);
	BIT_VEC cppVar_11405 = ROM.rd(cppVar_11404);
	bool cppVar_11407 = (cppVar_11405 == 138);
	if (cppVar_11407) {
	cppVar_11403 = TL0;
	} else {
	BIT_VEC cppVar_11408;
	BIT_VEC cppVar_11409 = PC + 1;
	cppVar_11409 = (cppVar_11409 & cppMask_un_16_);
	BIT_VEC cppVar_11410 = ROM.rd(cppVar_11409);
	bool cppVar_11412 = (cppVar_11410 == 140);
	if (cppVar_11412) {
	cppVar_11408 = TH0;
	} else {
	BIT_VEC cppVar_11413;
	BIT_VEC cppVar_11414 = PC + 1;
	cppVar_11414 = (cppVar_11414 & cppMask_un_16_);
	BIT_VEC cppVar_11415 = ROM.rd(cppVar_11414);
	bool cppVar_11417 = (cppVar_11415 == 139);
	if (cppVar_11417) {
	cppVar_11413 = TL1;
	} else {
	BIT_VEC cppVar_11418;
	BIT_VEC cppVar_11419 = PC + 1;
	cppVar_11419 = (cppVar_11419 & cppMask_un_16_);
	BIT_VEC cppVar_11420 = ROM.rd(cppVar_11419);
	bool cppVar_11422 = (cppVar_11420 == 141);
	if (cppVar_11422) {
	cppVar_11418 = TH1;
	} else {
	BIT_VEC cppVar_11423;
	BIT_VEC cppVar_11424 = PC + 1;
	cppVar_11424 = (cppVar_11424 & cppMask_un_16_);
	BIT_VEC cppVar_11425 = ROM.rd(cppVar_11424);
	bool cppVar_11427 = (cppVar_11425 == 144);
	if (cppVar_11427) {
	cppVar_11423 = P1;
	} else {
	BIT_VEC cppVar_11428;
	BIT_VEC cppVar_11429 = PC + 1;
	cppVar_11429 = (cppVar_11429 & cppMask_un_16_);
	BIT_VEC cppVar_11430 = ROM.rd(cppVar_11429);
	bool cppVar_11432 = (cppVar_11430 == 152);
	if (cppVar_11432) {
	cppVar_11428 = SCON;
	} else {
	BIT_VEC cppVar_11433;
	BIT_VEC cppVar_11434 = PC + 1;
	cppVar_11434 = (cppVar_11434 & cppMask_un_16_);
	BIT_VEC cppVar_11435 = ROM.rd(cppVar_11434);
	bool cppVar_11437 = (cppVar_11435 == 153);
	if (cppVar_11437) {
	cppVar_11433 = SBUF;
	} else {
	BIT_VEC cppVar_11438;
	BIT_VEC cppVar_11439 = PC + 1;
	cppVar_11439 = (cppVar_11439 & cppMask_un_16_);
	BIT_VEC cppVar_11440 = ROM.rd(cppVar_11439);
	bool cppVar_11442 = (cppVar_11440 == 160);
	if (cppVar_11442) {
	cppVar_11438 = P2;
	} else {
	BIT_VEC cppVar_11443;
	BIT_VEC cppVar_11444 = PC + 1;
	cppVar_11444 = (cppVar_11444 & cppMask_un_16_);
	BIT_VEC cppVar_11445 = ROM.rd(cppVar_11444);
	bool cppVar_11447 = (cppVar_11445 == 168);
	if (cppVar_11447) {
	cppVar_11443 = IE;
	} else {
	BIT_VEC cppVar_11448;
	BIT_VEC cppVar_11449 = PC + 1;
	cppVar_11449 = (cppVar_11449 & cppMask_un_16_);
	BIT_VEC cppVar_11450 = ROM.rd(cppVar_11449);
	bool cppVar_11452 = (cppVar_11450 == 176);
	if (cppVar_11452) {
	cppVar_11448 = P3;
	} else {
	BIT_VEC cppVar_11453;
	BIT_VEC cppVar_11454 = PC + 1;
	cppVar_11454 = (cppVar_11454 & cppMask_un_16_);
	BIT_VEC cppVar_11455 = ROM.rd(cppVar_11454);
	bool cppVar_11457 = (cppVar_11455 == 184);
	if (cppVar_11457) {
	cppVar_11453 = IP;
	} else {
	BIT_VEC cppVar_11458;
	BIT_VEC cppVar_11459 = PC + 1;
	cppVar_11459 = (cppVar_11459 & cppMask_un_16_);
	BIT_VEC cppVar_11460 = ROM.rd(cppVar_11459);
	bool cppVar_11462 = (cppVar_11460 == 208);
	if (cppVar_11462) {
	cppVar_11458 = PSW;
	} else {
	BIT_VEC cppVar_11463;
	BIT_VEC cppVar_11464 = PC + 1;
	cppVar_11464 = (cppVar_11464 & cppMask_un_16_);
	BIT_VEC cppVar_11465 = ROM.rd(cppVar_11464);
	bool cppVar_11467 = (cppVar_11465 == 224);
	if (cppVar_11467) {
	cppVar_11463 = ACC;
	} else {
	BIT_VEC cppVar_11468;
	BIT_VEC cppVar_11469 = PC + 1;
	cppVar_11469 = (cppVar_11469 & cppMask_un_16_);
	BIT_VEC cppVar_11470 = ROM.rd(cppVar_11469);
	bool cppVar_11472 = (cppVar_11470 == 240);
	if (cppVar_11472) {
	cppVar_11468 = B;
	} else {
	cppVar_11468 = 0;
	}
	cppVar_11463 = cppVar_11468;
	}
	cppVar_11458 = cppVar_11463;
	}
	cppVar_11453 = cppVar_11458;
	}
	cppVar_11448 = cppVar_11453;
	}
	cppVar_11443 = cppVar_11448;
	}
	cppVar_11438 = cppVar_11443;
	}
	cppVar_11433 = cppVar_11438;
	}
	cppVar_11428 = cppVar_11433;
	}
	cppVar_11423 = cppVar_11428;
	}
	cppVar_11418 = cppVar_11423;
	}
	cppVar_11413 = cppVar_11418;
	}
	cppVar_11408 = cppVar_11413;
	}
	cppVar_11403 = cppVar_11408;
	}
	cppVar_11398 = cppVar_11403;
	}
	cppVar_11393 = cppVar_11398;
	}
	cppVar_11388 = cppVar_11393;
	}
	cppVar_11383 = cppVar_11388;
	}
	cppVar_11378 = cppVar_11383;
	}
	cppVar_11373 = cppVar_11378;
	}
	cppVar_11368 = cppVar_11373;
	}
	cppVar_11358 = cppVar_11368;
	}
	cppVar_11352 = cppVar_11358;
	} else {
	cppVar_11352 = DPL;
	}
	cppVar_11348 = cppVar_11352;
	} else {
	BIT_VEC cppVar_11474;
	BIT_VEC cppVar_11475 = ROM.rd(PC);
	bool cppVar_11477 = (cppVar_11475 == 117);
	if (cppVar_11477) {
	BIT_VEC cppVar_11478;
	BIT_VEC cppVar_11480 = PC + 1;
	cppVar_11480 = (cppVar_11480 & cppMask_un_16_);
	BIT_VEC cppVar_11481 = ROM.rd(cppVar_11480);
	bool cppVar_11483 = (cppVar_11481 == 130);
	if (cppVar_11483) {
	BIT_VEC cppVar_11485 = PC + 2;
	cppVar_11485 = (cppVar_11485 & cppMask_un_16_);
	BIT_VEC cppVar_11486 = ROM.rd(cppVar_11485);
	cppVar_11478 = cppVar_11486;
	} else {
	cppVar_11478 = DPL;
	}
	cppVar_11474 = cppVar_11478;
	} else {
	BIT_VEC cppVar_11487;
	BIT_VEC cppVar_11488 = ROM.rd(PC);
	bool cppVar_11490 = (cppVar_11488 == 99);
	if (cppVar_11490) {
	BIT_VEC cppVar_11491;
	BIT_VEC cppVar_11493 = PC + 1;
	cppVar_11493 = (cppVar_11493 & cppMask_un_16_);
	BIT_VEC cppVar_11494 = ROM.rd(cppVar_11493);
	bool cppVar_11496 = (cppVar_11494 == 130);
	if (cppVar_11496) {
	BIT_VEC cppVar_11497;
	BIT_VEC cppVar_11498 = PC + 1;
	cppVar_11498 = (cppVar_11498 & cppMask_un_16_);
	BIT_VEC cppVar_11499 = ROM.rd(cppVar_11498);
	BIT_VEC cppVar_11500 = (cppVar_11499 >> 7) & cppMask_un_1_;
	bool cppVar_11502 = (cppVar_11500 == 0);
	if (cppVar_11502) {
	BIT_VEC cppVar_11503 = PC + 1;
	cppVar_11503 = (cppVar_11503 & cppMask_un_16_);
	BIT_VEC cppVar_11504 = ROM.rd(cppVar_11503);
	BIT_VEC cppVar_11505 = IRAM.rd(cppVar_11504);
	cppVar_11497 = cppVar_11505;
	} else {
	BIT_VEC cppVar_11506;
	BIT_VEC cppVar_11507 = PC + 1;
	cppVar_11507 = (cppVar_11507 & cppMask_un_16_);
	BIT_VEC cppVar_11508 = ROM.rd(cppVar_11507);
	bool cppVar_11510 = (cppVar_11508 == 128);
	if (cppVar_11510) {
	cppVar_11506 = P0;
	} else {
	BIT_VEC cppVar_11511;
	BIT_VEC cppVar_11512 = PC + 1;
	cppVar_11512 = (cppVar_11512 & cppMask_un_16_);
	BIT_VEC cppVar_11513 = ROM.rd(cppVar_11512);
	bool cppVar_11515 = (cppVar_11513 == 129);
	if (cppVar_11515) {
	cppVar_11511 = SP;
	} else {
	BIT_VEC cppVar_11516;
	BIT_VEC cppVar_11517 = PC + 1;
	cppVar_11517 = (cppVar_11517 & cppMask_un_16_);
	BIT_VEC cppVar_11518 = ROM.rd(cppVar_11517);
	bool cppVar_11520 = (cppVar_11518 == 130);
	if (cppVar_11520) {
	cppVar_11516 = DPL;
	} else {
	BIT_VEC cppVar_11521;
	BIT_VEC cppVar_11522 = PC + 1;
	cppVar_11522 = (cppVar_11522 & cppMask_un_16_);
	BIT_VEC cppVar_11523 = ROM.rd(cppVar_11522);
	bool cppVar_11525 = (cppVar_11523 == 131);
	if (cppVar_11525) {
	cppVar_11521 = DPH;
	} else {
	BIT_VEC cppVar_11526;
	BIT_VEC cppVar_11527 = PC + 1;
	cppVar_11527 = (cppVar_11527 & cppMask_un_16_);
	BIT_VEC cppVar_11528 = ROM.rd(cppVar_11527);
	bool cppVar_11530 = (cppVar_11528 == 135);
	if (cppVar_11530) {
	cppVar_11526 = PCON;
	} else {
	BIT_VEC cppVar_11531;
	BIT_VEC cppVar_11532 = PC + 1;
	cppVar_11532 = (cppVar_11532 & cppMask_un_16_);
	BIT_VEC cppVar_11533 = ROM.rd(cppVar_11532);
	bool cppVar_11535 = (cppVar_11533 == 136);
	if (cppVar_11535) {
	cppVar_11531 = TCON;
	} else {
	BIT_VEC cppVar_11536;
	BIT_VEC cppVar_11537 = PC + 1;
	cppVar_11537 = (cppVar_11537 & cppMask_un_16_);
	BIT_VEC cppVar_11538 = ROM.rd(cppVar_11537);
	bool cppVar_11540 = (cppVar_11538 == 137);
	if (cppVar_11540) {
	cppVar_11536 = TMOD;
	} else {
	BIT_VEC cppVar_11541;
	BIT_VEC cppVar_11542 = PC + 1;
	cppVar_11542 = (cppVar_11542 & cppMask_un_16_);
	BIT_VEC cppVar_11543 = ROM.rd(cppVar_11542);
	bool cppVar_11545 = (cppVar_11543 == 138);
	if (cppVar_11545) {
	cppVar_11541 = TL0;
	} else {
	BIT_VEC cppVar_11546;
	BIT_VEC cppVar_11547 = PC + 1;
	cppVar_11547 = (cppVar_11547 & cppMask_un_16_);
	BIT_VEC cppVar_11548 = ROM.rd(cppVar_11547);
	bool cppVar_11550 = (cppVar_11548 == 140);
	if (cppVar_11550) {
	cppVar_11546 = TH0;
	} else {
	BIT_VEC cppVar_11551;
	BIT_VEC cppVar_11552 = PC + 1;
	cppVar_11552 = (cppVar_11552 & cppMask_un_16_);
	BIT_VEC cppVar_11553 = ROM.rd(cppVar_11552);
	bool cppVar_11555 = (cppVar_11553 == 139);
	if (cppVar_11555) {
	cppVar_11551 = TL1;
	} else {
	BIT_VEC cppVar_11556;
	BIT_VEC cppVar_11557 = PC + 1;
	cppVar_11557 = (cppVar_11557 & cppMask_un_16_);
	BIT_VEC cppVar_11558 = ROM.rd(cppVar_11557);
	bool cppVar_11560 = (cppVar_11558 == 141);
	if (cppVar_11560) {
	cppVar_11556 = TH1;
	} else {
	BIT_VEC cppVar_11561;
	BIT_VEC cppVar_11562 = PC + 1;
	cppVar_11562 = (cppVar_11562 & cppMask_un_16_);
	BIT_VEC cppVar_11563 = ROM.rd(cppVar_11562);
	bool cppVar_11565 = (cppVar_11563 == 144);
	if (cppVar_11565) {
	cppVar_11561 = P1;
	} else {
	BIT_VEC cppVar_11566;
	BIT_VEC cppVar_11567 = PC + 1;
	cppVar_11567 = (cppVar_11567 & cppMask_un_16_);
	BIT_VEC cppVar_11568 = ROM.rd(cppVar_11567);
	bool cppVar_11570 = (cppVar_11568 == 152);
	if (cppVar_11570) {
	cppVar_11566 = SCON;
	} else {
	BIT_VEC cppVar_11571;
	BIT_VEC cppVar_11572 = PC + 1;
	cppVar_11572 = (cppVar_11572 & cppMask_un_16_);
	BIT_VEC cppVar_11573 = ROM.rd(cppVar_11572);
	bool cppVar_11575 = (cppVar_11573 == 153);
	if (cppVar_11575) {
	cppVar_11571 = SBUF;
	} else {
	BIT_VEC cppVar_11576;
	BIT_VEC cppVar_11577 = PC + 1;
	cppVar_11577 = (cppVar_11577 & cppMask_un_16_);
	BIT_VEC cppVar_11578 = ROM.rd(cppVar_11577);
	bool cppVar_11580 = (cppVar_11578 == 160);
	if (cppVar_11580) {
	cppVar_11576 = P2;
	} else {
	BIT_VEC cppVar_11581;
	BIT_VEC cppVar_11582 = PC + 1;
	cppVar_11582 = (cppVar_11582 & cppMask_un_16_);
	BIT_VEC cppVar_11583 = ROM.rd(cppVar_11582);
	bool cppVar_11585 = (cppVar_11583 == 168);
	if (cppVar_11585) {
	cppVar_11581 = IE;
	} else {
	BIT_VEC cppVar_11586;
	BIT_VEC cppVar_11587 = PC + 1;
	cppVar_11587 = (cppVar_11587 & cppMask_un_16_);
	BIT_VEC cppVar_11588 = ROM.rd(cppVar_11587);
	bool cppVar_11590 = (cppVar_11588 == 176);
	if (cppVar_11590) {
	cppVar_11586 = P3;
	} else {
	BIT_VEC cppVar_11591;
	BIT_VEC cppVar_11592 = PC + 1;
	cppVar_11592 = (cppVar_11592 & cppMask_un_16_);
	BIT_VEC cppVar_11593 = ROM.rd(cppVar_11592);
	bool cppVar_11595 = (cppVar_11593 == 184);
	if (cppVar_11595) {
	cppVar_11591 = IP;
	} else {
	BIT_VEC cppVar_11596;
	BIT_VEC cppVar_11597 = PC + 1;
	cppVar_11597 = (cppVar_11597 & cppMask_un_16_);
	BIT_VEC cppVar_11598 = ROM.rd(cppVar_11597);
	bool cppVar_11600 = (cppVar_11598 == 208);
	if (cppVar_11600) {
	cppVar_11596 = PSW;
	} else {
	BIT_VEC cppVar_11601;
	BIT_VEC cppVar_11602 = PC + 1;
	cppVar_11602 = (cppVar_11602 & cppMask_un_16_);
	BIT_VEC cppVar_11603 = ROM.rd(cppVar_11602);
	bool cppVar_11605 = (cppVar_11603 == 224);
	if (cppVar_11605) {
	cppVar_11601 = ACC;
	} else {
	BIT_VEC cppVar_11606;
	BIT_VEC cppVar_11607 = PC + 1;
	cppVar_11607 = (cppVar_11607 & cppMask_un_16_);
	BIT_VEC cppVar_11608 = ROM.rd(cppVar_11607);
	bool cppVar_11610 = (cppVar_11608 == 240);
	if (cppVar_11610) {
	cppVar_11606 = B;
	} else {
	cppVar_11606 = 0;
	}
	cppVar_11601 = cppVar_11606;
	}
	cppVar_11596 = cppVar_11601;
	}
	cppVar_11591 = cppVar_11596;
	}
	cppVar_11586 = cppVar_11591;
	}
	cppVar_11581 = cppVar_11586;
	}
	cppVar_11576 = cppVar_11581;
	}
	cppVar_11571 = cppVar_11576;
	}
	cppVar_11566 = cppVar_11571;
	}
	cppVar_11561 = cppVar_11566;
	}
	cppVar_11556 = cppVar_11561;
	}
	cppVar_11551 = cppVar_11556;
	}
	cppVar_11546 = cppVar_11551;
	}
	cppVar_11541 = cppVar_11546;
	}
	cppVar_11536 = cppVar_11541;
	}
	cppVar_11531 = cppVar_11536;
	}
	cppVar_11526 = cppVar_11531;
	}
	cppVar_11521 = cppVar_11526;
	}
	cppVar_11516 = cppVar_11521;
	}
	cppVar_11511 = cppVar_11516;
	}
	cppVar_11506 = cppVar_11511;
	}
	cppVar_11497 = cppVar_11506;
	}
	BIT_VEC cppVar_11613 = PC + 2;
	cppVar_11613 = (cppVar_11613 & cppMask_un_16_);
	BIT_VEC cppVar_11614 = ROM.rd(cppVar_11613);
	BIT_VEC cppVar_11615 = cppVar_11497 ^ cppVar_11614;
	cppVar_11491 = cppVar_11615;
	} else {
	cppVar_11491 = DPL;
	}
	cppVar_11487 = cppVar_11491;
	} else {
	BIT_VEC cppVar_11616;
	BIT_VEC cppVar_11617 = ROM.rd(PC);
	bool cppVar_11619 = (cppVar_11617 == 98);
	if (cppVar_11619) {
	BIT_VEC cppVar_11620;
	BIT_VEC cppVar_11622 = PC + 1;
	cppVar_11622 = (cppVar_11622 & cppMask_un_16_);
	BIT_VEC cppVar_11623 = ROM.rd(cppVar_11622);
	bool cppVar_11625 = (cppVar_11623 == 130);
	if (cppVar_11625) {
	BIT_VEC cppVar_11626;
	BIT_VEC cppVar_11627 = PC + 1;
	cppVar_11627 = (cppVar_11627 & cppMask_un_16_);
	BIT_VEC cppVar_11628 = ROM.rd(cppVar_11627);
	BIT_VEC cppVar_11629 = (cppVar_11628 >> 7) & cppMask_un_1_;
	bool cppVar_11631 = (cppVar_11629 == 0);
	if (cppVar_11631) {
	BIT_VEC cppVar_11632 = PC + 1;
	cppVar_11632 = (cppVar_11632 & cppMask_un_16_);
	BIT_VEC cppVar_11633 = ROM.rd(cppVar_11632);
	BIT_VEC cppVar_11634 = IRAM.rd(cppVar_11633);
	cppVar_11626 = cppVar_11634;
	} else {
	BIT_VEC cppVar_11635;
	BIT_VEC cppVar_11636 = PC + 1;
	cppVar_11636 = (cppVar_11636 & cppMask_un_16_);
	BIT_VEC cppVar_11637 = ROM.rd(cppVar_11636);
	bool cppVar_11639 = (cppVar_11637 == 128);
	if (cppVar_11639) {
	cppVar_11635 = P0;
	} else {
	BIT_VEC cppVar_11640;
	BIT_VEC cppVar_11641 = PC + 1;
	cppVar_11641 = (cppVar_11641 & cppMask_un_16_);
	BIT_VEC cppVar_11642 = ROM.rd(cppVar_11641);
	bool cppVar_11644 = (cppVar_11642 == 129);
	if (cppVar_11644) {
	cppVar_11640 = SP;
	} else {
	BIT_VEC cppVar_11645;
	BIT_VEC cppVar_11646 = PC + 1;
	cppVar_11646 = (cppVar_11646 & cppMask_un_16_);
	BIT_VEC cppVar_11647 = ROM.rd(cppVar_11646);
	bool cppVar_11649 = (cppVar_11647 == 130);
	if (cppVar_11649) {
	cppVar_11645 = DPL;
	} else {
	BIT_VEC cppVar_11650;
	BIT_VEC cppVar_11651 = PC + 1;
	cppVar_11651 = (cppVar_11651 & cppMask_un_16_);
	BIT_VEC cppVar_11652 = ROM.rd(cppVar_11651);
	bool cppVar_11654 = (cppVar_11652 == 131);
	if (cppVar_11654) {
	cppVar_11650 = DPH;
	} else {
	BIT_VEC cppVar_11655;
	BIT_VEC cppVar_11656 = PC + 1;
	cppVar_11656 = (cppVar_11656 & cppMask_un_16_);
	BIT_VEC cppVar_11657 = ROM.rd(cppVar_11656);
	bool cppVar_11659 = (cppVar_11657 == 135);
	if (cppVar_11659) {
	cppVar_11655 = PCON;
	} else {
	BIT_VEC cppVar_11660;
	BIT_VEC cppVar_11661 = PC + 1;
	cppVar_11661 = (cppVar_11661 & cppMask_un_16_);
	BIT_VEC cppVar_11662 = ROM.rd(cppVar_11661);
	bool cppVar_11664 = (cppVar_11662 == 136);
	if (cppVar_11664) {
	cppVar_11660 = TCON;
	} else {
	BIT_VEC cppVar_11665;
	BIT_VEC cppVar_11666 = PC + 1;
	cppVar_11666 = (cppVar_11666 & cppMask_un_16_);
	BIT_VEC cppVar_11667 = ROM.rd(cppVar_11666);
	bool cppVar_11669 = (cppVar_11667 == 137);
	if (cppVar_11669) {
	cppVar_11665 = TMOD;
	} else {
	BIT_VEC cppVar_11670;
	BIT_VEC cppVar_11671 = PC + 1;
	cppVar_11671 = (cppVar_11671 & cppMask_un_16_);
	BIT_VEC cppVar_11672 = ROM.rd(cppVar_11671);
	bool cppVar_11674 = (cppVar_11672 == 138);
	if (cppVar_11674) {
	cppVar_11670 = TL0;
	} else {
	BIT_VEC cppVar_11675;
	BIT_VEC cppVar_11676 = PC + 1;
	cppVar_11676 = (cppVar_11676 & cppMask_un_16_);
	BIT_VEC cppVar_11677 = ROM.rd(cppVar_11676);
	bool cppVar_11679 = (cppVar_11677 == 140);
	if (cppVar_11679) {
	cppVar_11675 = TH0;
	} else {
	BIT_VEC cppVar_11680;
	BIT_VEC cppVar_11681 = PC + 1;
	cppVar_11681 = (cppVar_11681 & cppMask_un_16_);
	BIT_VEC cppVar_11682 = ROM.rd(cppVar_11681);
	bool cppVar_11684 = (cppVar_11682 == 139);
	if (cppVar_11684) {
	cppVar_11680 = TL1;
	} else {
	BIT_VEC cppVar_11685;
	BIT_VEC cppVar_11686 = PC + 1;
	cppVar_11686 = (cppVar_11686 & cppMask_un_16_);
	BIT_VEC cppVar_11687 = ROM.rd(cppVar_11686);
	bool cppVar_11689 = (cppVar_11687 == 141);
	if (cppVar_11689) {
	cppVar_11685 = TH1;
	} else {
	BIT_VEC cppVar_11690;
	BIT_VEC cppVar_11691 = PC + 1;
	cppVar_11691 = (cppVar_11691 & cppMask_un_16_);
	BIT_VEC cppVar_11692 = ROM.rd(cppVar_11691);
	bool cppVar_11694 = (cppVar_11692 == 144);
	if (cppVar_11694) {
	cppVar_11690 = P1;
	} else {
	BIT_VEC cppVar_11695;
	BIT_VEC cppVar_11696 = PC + 1;
	cppVar_11696 = (cppVar_11696 & cppMask_un_16_);
	BIT_VEC cppVar_11697 = ROM.rd(cppVar_11696);
	bool cppVar_11699 = (cppVar_11697 == 152);
	if (cppVar_11699) {
	cppVar_11695 = SCON;
	} else {
	BIT_VEC cppVar_11700;
	BIT_VEC cppVar_11701 = PC + 1;
	cppVar_11701 = (cppVar_11701 & cppMask_un_16_);
	BIT_VEC cppVar_11702 = ROM.rd(cppVar_11701);
	bool cppVar_11704 = (cppVar_11702 == 153);
	if (cppVar_11704) {
	cppVar_11700 = SBUF;
	} else {
	BIT_VEC cppVar_11705;
	BIT_VEC cppVar_11706 = PC + 1;
	cppVar_11706 = (cppVar_11706 & cppMask_un_16_);
	BIT_VEC cppVar_11707 = ROM.rd(cppVar_11706);
	bool cppVar_11709 = (cppVar_11707 == 160);
	if (cppVar_11709) {
	cppVar_11705 = P2;
	} else {
	BIT_VEC cppVar_11710;
	BIT_VEC cppVar_11711 = PC + 1;
	cppVar_11711 = (cppVar_11711 & cppMask_un_16_);
	BIT_VEC cppVar_11712 = ROM.rd(cppVar_11711);
	bool cppVar_11714 = (cppVar_11712 == 168);
	if (cppVar_11714) {
	cppVar_11710 = IE;
	} else {
	BIT_VEC cppVar_11715;
	BIT_VEC cppVar_11716 = PC + 1;
	cppVar_11716 = (cppVar_11716 & cppMask_un_16_);
	BIT_VEC cppVar_11717 = ROM.rd(cppVar_11716);
	bool cppVar_11719 = (cppVar_11717 == 176);
	if (cppVar_11719) {
	cppVar_11715 = P3;
	} else {
	BIT_VEC cppVar_11720;
	BIT_VEC cppVar_11721 = PC + 1;
	cppVar_11721 = (cppVar_11721 & cppMask_un_16_);
	BIT_VEC cppVar_11722 = ROM.rd(cppVar_11721);
	bool cppVar_11724 = (cppVar_11722 == 184);
	if (cppVar_11724) {
	cppVar_11720 = IP;
	} else {
	BIT_VEC cppVar_11725;
	BIT_VEC cppVar_11726 = PC + 1;
	cppVar_11726 = (cppVar_11726 & cppMask_un_16_);
	BIT_VEC cppVar_11727 = ROM.rd(cppVar_11726);
	bool cppVar_11729 = (cppVar_11727 == 208);
	if (cppVar_11729) {
	cppVar_11725 = PSW;
	} else {
	BIT_VEC cppVar_11730;
	BIT_VEC cppVar_11731 = PC + 1;
	cppVar_11731 = (cppVar_11731 & cppMask_un_16_);
	BIT_VEC cppVar_11732 = ROM.rd(cppVar_11731);
	bool cppVar_11734 = (cppVar_11732 == 224);
	if (cppVar_11734) {
	cppVar_11730 = ACC;
	} else {
	BIT_VEC cppVar_11735;
	BIT_VEC cppVar_11736 = PC + 1;
	cppVar_11736 = (cppVar_11736 & cppMask_un_16_);
	BIT_VEC cppVar_11737 = ROM.rd(cppVar_11736);
	bool cppVar_11739 = (cppVar_11737 == 240);
	if (cppVar_11739) {
	cppVar_11735 = B;
	} else {
	cppVar_11735 = 0;
	}
	cppVar_11730 = cppVar_11735;
	}
	cppVar_11725 = cppVar_11730;
	}
	cppVar_11720 = cppVar_11725;
	}
	cppVar_11715 = cppVar_11720;
	}
	cppVar_11710 = cppVar_11715;
	}
	cppVar_11705 = cppVar_11710;
	}
	cppVar_11700 = cppVar_11705;
	}
	cppVar_11695 = cppVar_11700;
	}
	cppVar_11690 = cppVar_11695;
	}
	cppVar_11685 = cppVar_11690;
	}
	cppVar_11680 = cppVar_11685;
	}
	cppVar_11675 = cppVar_11680;
	}
	cppVar_11670 = cppVar_11675;
	}
	cppVar_11665 = cppVar_11670;
	}
	cppVar_11660 = cppVar_11665;
	}
	cppVar_11655 = cppVar_11660;
	}
	cppVar_11650 = cppVar_11655;
	}
	cppVar_11645 = cppVar_11650;
	}
	cppVar_11640 = cppVar_11645;
	}
	cppVar_11635 = cppVar_11640;
	}
	cppVar_11626 = cppVar_11635;
	}
	BIT_VEC cppVar_11741 = cppVar_11626 ^ ACC;
	cppVar_11620 = cppVar_11741;
	} else {
	cppVar_11620 = DPL;
	}
	cppVar_11616 = cppVar_11620;
	} else {
	BIT_VEC cppVar_11742;
	BIT_VEC cppVar_11743 = ROM.rd(PC);
	bool cppVar_11745 = (cppVar_11743 == 83);
	if (cppVar_11745) {
	BIT_VEC cppVar_11746;
	BIT_VEC cppVar_11748 = PC + 1;
	cppVar_11748 = (cppVar_11748 & cppMask_un_16_);
	BIT_VEC cppVar_11749 = ROM.rd(cppVar_11748);
	bool cppVar_11751 = (cppVar_11749 == 130);
	if (cppVar_11751) {
	BIT_VEC cppVar_11752;
	BIT_VEC cppVar_11753 = PC + 1;
	cppVar_11753 = (cppVar_11753 & cppMask_un_16_);
	BIT_VEC cppVar_11754 = ROM.rd(cppVar_11753);
	BIT_VEC cppVar_11755 = (cppVar_11754 >> 7) & cppMask_un_1_;
	bool cppVar_11757 = (cppVar_11755 == 0);
	if (cppVar_11757) {
	BIT_VEC cppVar_11758 = PC + 1;
	cppVar_11758 = (cppVar_11758 & cppMask_un_16_);
	BIT_VEC cppVar_11759 = ROM.rd(cppVar_11758);
	BIT_VEC cppVar_11760 = IRAM.rd(cppVar_11759);
	cppVar_11752 = cppVar_11760;
	} else {
	BIT_VEC cppVar_11761;
	BIT_VEC cppVar_11762 = PC + 1;
	cppVar_11762 = (cppVar_11762 & cppMask_un_16_);
	BIT_VEC cppVar_11763 = ROM.rd(cppVar_11762);
	bool cppVar_11765 = (cppVar_11763 == 128);
	if (cppVar_11765) {
	cppVar_11761 = P0;
	} else {
	BIT_VEC cppVar_11766;
	BIT_VEC cppVar_11767 = PC + 1;
	cppVar_11767 = (cppVar_11767 & cppMask_un_16_);
	BIT_VEC cppVar_11768 = ROM.rd(cppVar_11767);
	bool cppVar_11770 = (cppVar_11768 == 129);
	if (cppVar_11770) {
	cppVar_11766 = SP;
	} else {
	BIT_VEC cppVar_11771;
	BIT_VEC cppVar_11772 = PC + 1;
	cppVar_11772 = (cppVar_11772 & cppMask_un_16_);
	BIT_VEC cppVar_11773 = ROM.rd(cppVar_11772);
	bool cppVar_11775 = (cppVar_11773 == 130);
	if (cppVar_11775) {
	cppVar_11771 = DPL;
	} else {
	BIT_VEC cppVar_11776;
	BIT_VEC cppVar_11777 = PC + 1;
	cppVar_11777 = (cppVar_11777 & cppMask_un_16_);
	BIT_VEC cppVar_11778 = ROM.rd(cppVar_11777);
	bool cppVar_11780 = (cppVar_11778 == 131);
	if (cppVar_11780) {
	cppVar_11776 = DPH;
	} else {
	BIT_VEC cppVar_11781;
	BIT_VEC cppVar_11782 = PC + 1;
	cppVar_11782 = (cppVar_11782 & cppMask_un_16_);
	BIT_VEC cppVar_11783 = ROM.rd(cppVar_11782);
	bool cppVar_11785 = (cppVar_11783 == 135);
	if (cppVar_11785) {
	cppVar_11781 = PCON;
	} else {
	BIT_VEC cppVar_11786;
	BIT_VEC cppVar_11787 = PC + 1;
	cppVar_11787 = (cppVar_11787 & cppMask_un_16_);
	BIT_VEC cppVar_11788 = ROM.rd(cppVar_11787);
	bool cppVar_11790 = (cppVar_11788 == 136);
	if (cppVar_11790) {
	cppVar_11786 = TCON;
	} else {
	BIT_VEC cppVar_11791;
	BIT_VEC cppVar_11792 = PC + 1;
	cppVar_11792 = (cppVar_11792 & cppMask_un_16_);
	BIT_VEC cppVar_11793 = ROM.rd(cppVar_11792);
	bool cppVar_11795 = (cppVar_11793 == 137);
	if (cppVar_11795) {
	cppVar_11791 = TMOD;
	} else {
	BIT_VEC cppVar_11796;
	BIT_VEC cppVar_11797 = PC + 1;
	cppVar_11797 = (cppVar_11797 & cppMask_un_16_);
	BIT_VEC cppVar_11798 = ROM.rd(cppVar_11797);
	bool cppVar_11800 = (cppVar_11798 == 138);
	if (cppVar_11800) {
	cppVar_11796 = TL0;
	} else {
	BIT_VEC cppVar_11801;
	BIT_VEC cppVar_11802 = PC + 1;
	cppVar_11802 = (cppVar_11802 & cppMask_un_16_);
	BIT_VEC cppVar_11803 = ROM.rd(cppVar_11802);
	bool cppVar_11805 = (cppVar_11803 == 140);
	if (cppVar_11805) {
	cppVar_11801 = TH0;
	} else {
	BIT_VEC cppVar_11806;
	BIT_VEC cppVar_11807 = PC + 1;
	cppVar_11807 = (cppVar_11807 & cppMask_un_16_);
	BIT_VEC cppVar_11808 = ROM.rd(cppVar_11807);
	bool cppVar_11810 = (cppVar_11808 == 139);
	if (cppVar_11810) {
	cppVar_11806 = TL1;
	} else {
	BIT_VEC cppVar_11811;
	BIT_VEC cppVar_11812 = PC + 1;
	cppVar_11812 = (cppVar_11812 & cppMask_un_16_);
	BIT_VEC cppVar_11813 = ROM.rd(cppVar_11812);
	bool cppVar_11815 = (cppVar_11813 == 141);
	if (cppVar_11815) {
	cppVar_11811 = TH1;
	} else {
	BIT_VEC cppVar_11816;
	BIT_VEC cppVar_11817 = PC + 1;
	cppVar_11817 = (cppVar_11817 & cppMask_un_16_);
	BIT_VEC cppVar_11818 = ROM.rd(cppVar_11817);
	bool cppVar_11820 = (cppVar_11818 == 144);
	if (cppVar_11820) {
	cppVar_11816 = P1;
	} else {
	BIT_VEC cppVar_11821;
	BIT_VEC cppVar_11822 = PC + 1;
	cppVar_11822 = (cppVar_11822 & cppMask_un_16_);
	BIT_VEC cppVar_11823 = ROM.rd(cppVar_11822);
	bool cppVar_11825 = (cppVar_11823 == 152);
	if (cppVar_11825) {
	cppVar_11821 = SCON;
	} else {
	BIT_VEC cppVar_11826;
	BIT_VEC cppVar_11827 = PC + 1;
	cppVar_11827 = (cppVar_11827 & cppMask_un_16_);
	BIT_VEC cppVar_11828 = ROM.rd(cppVar_11827);
	bool cppVar_11830 = (cppVar_11828 == 153);
	if (cppVar_11830) {
	cppVar_11826 = SBUF;
	} else {
	BIT_VEC cppVar_11831;
	BIT_VEC cppVar_11832 = PC + 1;
	cppVar_11832 = (cppVar_11832 & cppMask_un_16_);
	BIT_VEC cppVar_11833 = ROM.rd(cppVar_11832);
	bool cppVar_11835 = (cppVar_11833 == 160);
	if (cppVar_11835) {
	cppVar_11831 = P2;
	} else {
	BIT_VEC cppVar_11836;
	BIT_VEC cppVar_11837 = PC + 1;
	cppVar_11837 = (cppVar_11837 & cppMask_un_16_);
	BIT_VEC cppVar_11838 = ROM.rd(cppVar_11837);
	bool cppVar_11840 = (cppVar_11838 == 168);
	if (cppVar_11840) {
	cppVar_11836 = IE;
	} else {
	BIT_VEC cppVar_11841;
	BIT_VEC cppVar_11842 = PC + 1;
	cppVar_11842 = (cppVar_11842 & cppMask_un_16_);
	BIT_VEC cppVar_11843 = ROM.rd(cppVar_11842);
	bool cppVar_11845 = (cppVar_11843 == 176);
	if (cppVar_11845) {
	cppVar_11841 = P3;
	} else {
	BIT_VEC cppVar_11846;
	BIT_VEC cppVar_11847 = PC + 1;
	cppVar_11847 = (cppVar_11847 & cppMask_un_16_);
	BIT_VEC cppVar_11848 = ROM.rd(cppVar_11847);
	bool cppVar_11850 = (cppVar_11848 == 184);
	if (cppVar_11850) {
	cppVar_11846 = IP;
	} else {
	BIT_VEC cppVar_11851;
	BIT_VEC cppVar_11852 = PC + 1;
	cppVar_11852 = (cppVar_11852 & cppMask_un_16_);
	BIT_VEC cppVar_11853 = ROM.rd(cppVar_11852);
	bool cppVar_11855 = (cppVar_11853 == 208);
	if (cppVar_11855) {
	cppVar_11851 = PSW;
	} else {
	BIT_VEC cppVar_11856;
	BIT_VEC cppVar_11857 = PC + 1;
	cppVar_11857 = (cppVar_11857 & cppMask_un_16_);
	BIT_VEC cppVar_11858 = ROM.rd(cppVar_11857);
	bool cppVar_11860 = (cppVar_11858 == 224);
	if (cppVar_11860) {
	cppVar_11856 = ACC;
	} else {
	BIT_VEC cppVar_11861;
	BIT_VEC cppVar_11862 = PC + 1;
	cppVar_11862 = (cppVar_11862 & cppMask_un_16_);
	BIT_VEC cppVar_11863 = ROM.rd(cppVar_11862);
	bool cppVar_11865 = (cppVar_11863 == 240);
	if (cppVar_11865) {
	cppVar_11861 = B;
	} else {
	cppVar_11861 = 0;
	}
	cppVar_11856 = cppVar_11861;
	}
	cppVar_11851 = cppVar_11856;
	}
	cppVar_11846 = cppVar_11851;
	}
	cppVar_11841 = cppVar_11846;
	}
	cppVar_11836 = cppVar_11841;
	}
	cppVar_11831 = cppVar_11836;
	}
	cppVar_11826 = cppVar_11831;
	}
	cppVar_11821 = cppVar_11826;
	}
	cppVar_11816 = cppVar_11821;
	}
	cppVar_11811 = cppVar_11816;
	}
	cppVar_11806 = cppVar_11811;
	}
	cppVar_11801 = cppVar_11806;
	}
	cppVar_11796 = cppVar_11801;
	}
	cppVar_11791 = cppVar_11796;
	}
	cppVar_11786 = cppVar_11791;
	}
	cppVar_11781 = cppVar_11786;
	}
	cppVar_11776 = cppVar_11781;
	}
	cppVar_11771 = cppVar_11776;
	}
	cppVar_11766 = cppVar_11771;
	}
	cppVar_11761 = cppVar_11766;
	}
	cppVar_11752 = cppVar_11761;
	}
	BIT_VEC cppVar_11868 = PC + 2;
	cppVar_11868 = (cppVar_11868 & cppMask_un_16_);
	BIT_VEC cppVar_11869 = ROM.rd(cppVar_11868);
	BIT_VEC cppVar_11870 = cppVar_11752 & cppVar_11869;
	cppVar_11746 = cppVar_11870;
	} else {
	cppVar_11746 = DPL;
	}
	cppVar_11742 = cppVar_11746;
	} else {
	BIT_VEC cppVar_11871;
	BIT_VEC cppVar_11872 = ROM.rd(PC);
	bool cppVar_11874 = (cppVar_11872 == 82);
	if (cppVar_11874) {
	BIT_VEC cppVar_11875;
	BIT_VEC cppVar_11877 = PC + 1;
	cppVar_11877 = (cppVar_11877 & cppMask_un_16_);
	BIT_VEC cppVar_11878 = ROM.rd(cppVar_11877);
	bool cppVar_11880 = (cppVar_11878 == 130);
	if (cppVar_11880) {
	BIT_VEC cppVar_11881;
	BIT_VEC cppVar_11882 = PC + 1;
	cppVar_11882 = (cppVar_11882 & cppMask_un_16_);
	BIT_VEC cppVar_11883 = ROM.rd(cppVar_11882);
	BIT_VEC cppVar_11884 = (cppVar_11883 >> 7) & cppMask_un_1_;
	bool cppVar_11886 = (cppVar_11884 == 0);
	if (cppVar_11886) {
	BIT_VEC cppVar_11887 = PC + 1;
	cppVar_11887 = (cppVar_11887 & cppMask_un_16_);
	BIT_VEC cppVar_11888 = ROM.rd(cppVar_11887);
	BIT_VEC cppVar_11889 = IRAM.rd(cppVar_11888);
	cppVar_11881 = cppVar_11889;
	} else {
	BIT_VEC cppVar_11890;
	BIT_VEC cppVar_11891 = PC + 1;
	cppVar_11891 = (cppVar_11891 & cppMask_un_16_);
	BIT_VEC cppVar_11892 = ROM.rd(cppVar_11891);
	bool cppVar_11894 = (cppVar_11892 == 128);
	if (cppVar_11894) {
	cppVar_11890 = P0;
	} else {
	BIT_VEC cppVar_11895;
	BIT_VEC cppVar_11896 = PC + 1;
	cppVar_11896 = (cppVar_11896 & cppMask_un_16_);
	BIT_VEC cppVar_11897 = ROM.rd(cppVar_11896);
	bool cppVar_11899 = (cppVar_11897 == 129);
	if (cppVar_11899) {
	cppVar_11895 = SP;
	} else {
	BIT_VEC cppVar_11900;
	BIT_VEC cppVar_11901 = PC + 1;
	cppVar_11901 = (cppVar_11901 & cppMask_un_16_);
	BIT_VEC cppVar_11902 = ROM.rd(cppVar_11901);
	bool cppVar_11904 = (cppVar_11902 == 130);
	if (cppVar_11904) {
	cppVar_11900 = DPL;
	} else {
	BIT_VEC cppVar_11905;
	BIT_VEC cppVar_11906 = PC + 1;
	cppVar_11906 = (cppVar_11906 & cppMask_un_16_);
	BIT_VEC cppVar_11907 = ROM.rd(cppVar_11906);
	bool cppVar_11909 = (cppVar_11907 == 131);
	if (cppVar_11909) {
	cppVar_11905 = DPH;
	} else {
	BIT_VEC cppVar_11910;
	BIT_VEC cppVar_11911 = PC + 1;
	cppVar_11911 = (cppVar_11911 & cppMask_un_16_);
	BIT_VEC cppVar_11912 = ROM.rd(cppVar_11911);
	bool cppVar_11914 = (cppVar_11912 == 135);
	if (cppVar_11914) {
	cppVar_11910 = PCON;
	} else {
	BIT_VEC cppVar_11915;
	BIT_VEC cppVar_11916 = PC + 1;
	cppVar_11916 = (cppVar_11916 & cppMask_un_16_);
	BIT_VEC cppVar_11917 = ROM.rd(cppVar_11916);
	bool cppVar_11919 = (cppVar_11917 == 136);
	if (cppVar_11919) {
	cppVar_11915 = TCON;
	} else {
	BIT_VEC cppVar_11920;
	BIT_VEC cppVar_11921 = PC + 1;
	cppVar_11921 = (cppVar_11921 & cppMask_un_16_);
	BIT_VEC cppVar_11922 = ROM.rd(cppVar_11921);
	bool cppVar_11924 = (cppVar_11922 == 137);
	if (cppVar_11924) {
	cppVar_11920 = TMOD;
	} else {
	BIT_VEC cppVar_11925;
	BIT_VEC cppVar_11926 = PC + 1;
	cppVar_11926 = (cppVar_11926 & cppMask_un_16_);
	BIT_VEC cppVar_11927 = ROM.rd(cppVar_11926);
	bool cppVar_11929 = (cppVar_11927 == 138);
	if (cppVar_11929) {
	cppVar_11925 = TL0;
	} else {
	BIT_VEC cppVar_11930;
	BIT_VEC cppVar_11931 = PC + 1;
	cppVar_11931 = (cppVar_11931 & cppMask_un_16_);
	BIT_VEC cppVar_11932 = ROM.rd(cppVar_11931);
	bool cppVar_11934 = (cppVar_11932 == 140);
	if (cppVar_11934) {
	cppVar_11930 = TH0;
	} else {
	BIT_VEC cppVar_11935;
	BIT_VEC cppVar_11936 = PC + 1;
	cppVar_11936 = (cppVar_11936 & cppMask_un_16_);
	BIT_VEC cppVar_11937 = ROM.rd(cppVar_11936);
	bool cppVar_11939 = (cppVar_11937 == 139);
	if (cppVar_11939) {
	cppVar_11935 = TL1;
	} else {
	BIT_VEC cppVar_11940;
	BIT_VEC cppVar_11941 = PC + 1;
	cppVar_11941 = (cppVar_11941 & cppMask_un_16_);
	BIT_VEC cppVar_11942 = ROM.rd(cppVar_11941);
	bool cppVar_11944 = (cppVar_11942 == 141);
	if (cppVar_11944) {
	cppVar_11940 = TH1;
	} else {
	BIT_VEC cppVar_11945;
	BIT_VEC cppVar_11946 = PC + 1;
	cppVar_11946 = (cppVar_11946 & cppMask_un_16_);
	BIT_VEC cppVar_11947 = ROM.rd(cppVar_11946);
	bool cppVar_11949 = (cppVar_11947 == 144);
	if (cppVar_11949) {
	cppVar_11945 = P1;
	} else {
	BIT_VEC cppVar_11950;
	BIT_VEC cppVar_11951 = PC + 1;
	cppVar_11951 = (cppVar_11951 & cppMask_un_16_);
	BIT_VEC cppVar_11952 = ROM.rd(cppVar_11951);
	bool cppVar_11954 = (cppVar_11952 == 152);
	if (cppVar_11954) {
	cppVar_11950 = SCON;
	} else {
	BIT_VEC cppVar_11955;
	BIT_VEC cppVar_11956 = PC + 1;
	cppVar_11956 = (cppVar_11956 & cppMask_un_16_);
	BIT_VEC cppVar_11957 = ROM.rd(cppVar_11956);
	bool cppVar_11959 = (cppVar_11957 == 153);
	if (cppVar_11959) {
	cppVar_11955 = SBUF;
	} else {
	BIT_VEC cppVar_11960;
	BIT_VEC cppVar_11961 = PC + 1;
	cppVar_11961 = (cppVar_11961 & cppMask_un_16_);
	BIT_VEC cppVar_11962 = ROM.rd(cppVar_11961);
	bool cppVar_11964 = (cppVar_11962 == 160);
	if (cppVar_11964) {
	cppVar_11960 = P2;
	} else {
	BIT_VEC cppVar_11965;
	BIT_VEC cppVar_11966 = PC + 1;
	cppVar_11966 = (cppVar_11966 & cppMask_un_16_);
	BIT_VEC cppVar_11967 = ROM.rd(cppVar_11966);
	bool cppVar_11969 = (cppVar_11967 == 168);
	if (cppVar_11969) {
	cppVar_11965 = IE;
	} else {
	BIT_VEC cppVar_11970;
	BIT_VEC cppVar_11971 = PC + 1;
	cppVar_11971 = (cppVar_11971 & cppMask_un_16_);
	BIT_VEC cppVar_11972 = ROM.rd(cppVar_11971);
	bool cppVar_11974 = (cppVar_11972 == 176);
	if (cppVar_11974) {
	cppVar_11970 = P3;
	} else {
	BIT_VEC cppVar_11975;
	BIT_VEC cppVar_11976 = PC + 1;
	cppVar_11976 = (cppVar_11976 & cppMask_un_16_);
	BIT_VEC cppVar_11977 = ROM.rd(cppVar_11976);
	bool cppVar_11979 = (cppVar_11977 == 184);
	if (cppVar_11979) {
	cppVar_11975 = IP;
	} else {
	BIT_VEC cppVar_11980;
	BIT_VEC cppVar_11981 = PC + 1;
	cppVar_11981 = (cppVar_11981 & cppMask_un_16_);
	BIT_VEC cppVar_11982 = ROM.rd(cppVar_11981);
	bool cppVar_11984 = (cppVar_11982 == 208);
	if (cppVar_11984) {
	cppVar_11980 = PSW;
	} else {
	BIT_VEC cppVar_11985;
	BIT_VEC cppVar_11986 = PC + 1;
	cppVar_11986 = (cppVar_11986 & cppMask_un_16_);
	BIT_VEC cppVar_11987 = ROM.rd(cppVar_11986);
	bool cppVar_11989 = (cppVar_11987 == 224);
	if (cppVar_11989) {
	cppVar_11985 = ACC;
	} else {
	BIT_VEC cppVar_11990;
	BIT_VEC cppVar_11991 = PC + 1;
	cppVar_11991 = (cppVar_11991 & cppMask_un_16_);
	BIT_VEC cppVar_11992 = ROM.rd(cppVar_11991);
	bool cppVar_11994 = (cppVar_11992 == 240);
	if (cppVar_11994) {
	cppVar_11990 = B;
	} else {
	cppVar_11990 = 0;
	}
	cppVar_11985 = cppVar_11990;
	}
	cppVar_11980 = cppVar_11985;
	}
	cppVar_11975 = cppVar_11980;
	}
	cppVar_11970 = cppVar_11975;
	}
	cppVar_11965 = cppVar_11970;
	}
	cppVar_11960 = cppVar_11965;
	}
	cppVar_11955 = cppVar_11960;
	}
	cppVar_11950 = cppVar_11955;
	}
	cppVar_11945 = cppVar_11950;
	}
	cppVar_11940 = cppVar_11945;
	}
	cppVar_11935 = cppVar_11940;
	}
	cppVar_11930 = cppVar_11935;
	}
	cppVar_11925 = cppVar_11930;
	}
	cppVar_11920 = cppVar_11925;
	}
	cppVar_11915 = cppVar_11920;
	}
	cppVar_11910 = cppVar_11915;
	}
	cppVar_11905 = cppVar_11910;
	}
	cppVar_11900 = cppVar_11905;
	}
	cppVar_11895 = cppVar_11900;
	}
	cppVar_11890 = cppVar_11895;
	}
	cppVar_11881 = cppVar_11890;
	}
	BIT_VEC cppVar_11996 = cppVar_11881 & ACC;
	cppVar_11875 = cppVar_11996;
	} else {
	cppVar_11875 = DPL;
	}
	cppVar_11871 = cppVar_11875;
	} else {
	BIT_VEC cppVar_11997;
	BIT_VEC cppVar_11998 = ROM.rd(PC);
	bool cppVar_12000 = (cppVar_11998 == 67);
	if (cppVar_12000) {
	BIT_VEC cppVar_12001;
	BIT_VEC cppVar_12003 = PC + 1;
	cppVar_12003 = (cppVar_12003 & cppMask_un_16_);
	BIT_VEC cppVar_12004 = ROM.rd(cppVar_12003);
	bool cppVar_12006 = (cppVar_12004 == 130);
	if (cppVar_12006) {
	BIT_VEC cppVar_12007;
	BIT_VEC cppVar_12008 = PC + 1;
	cppVar_12008 = (cppVar_12008 & cppMask_un_16_);
	BIT_VEC cppVar_12009 = ROM.rd(cppVar_12008);
	BIT_VEC cppVar_12010 = (cppVar_12009 >> 7) & cppMask_un_1_;
	bool cppVar_12012 = (cppVar_12010 == 0);
	if (cppVar_12012) {
	BIT_VEC cppVar_12013 = PC + 1;
	cppVar_12013 = (cppVar_12013 & cppMask_un_16_);
	BIT_VEC cppVar_12014 = ROM.rd(cppVar_12013);
	BIT_VEC cppVar_12015 = IRAM.rd(cppVar_12014);
	cppVar_12007 = cppVar_12015;
	} else {
	BIT_VEC cppVar_12016;
	BIT_VEC cppVar_12017 = PC + 1;
	cppVar_12017 = (cppVar_12017 & cppMask_un_16_);
	BIT_VEC cppVar_12018 = ROM.rd(cppVar_12017);
	bool cppVar_12020 = (cppVar_12018 == 128);
	if (cppVar_12020) {
	cppVar_12016 = P0;
	} else {
	BIT_VEC cppVar_12021;
	BIT_VEC cppVar_12022 = PC + 1;
	cppVar_12022 = (cppVar_12022 & cppMask_un_16_);
	BIT_VEC cppVar_12023 = ROM.rd(cppVar_12022);
	bool cppVar_12025 = (cppVar_12023 == 129);
	if (cppVar_12025) {
	cppVar_12021 = SP;
	} else {
	BIT_VEC cppVar_12026;
	BIT_VEC cppVar_12027 = PC + 1;
	cppVar_12027 = (cppVar_12027 & cppMask_un_16_);
	BIT_VEC cppVar_12028 = ROM.rd(cppVar_12027);
	bool cppVar_12030 = (cppVar_12028 == 130);
	if (cppVar_12030) {
	cppVar_12026 = DPL;
	} else {
	BIT_VEC cppVar_12031;
	BIT_VEC cppVar_12032 = PC + 1;
	cppVar_12032 = (cppVar_12032 & cppMask_un_16_);
	BIT_VEC cppVar_12033 = ROM.rd(cppVar_12032);
	bool cppVar_12035 = (cppVar_12033 == 131);
	if (cppVar_12035) {
	cppVar_12031 = DPH;
	} else {
	BIT_VEC cppVar_12036;
	BIT_VEC cppVar_12037 = PC + 1;
	cppVar_12037 = (cppVar_12037 & cppMask_un_16_);
	BIT_VEC cppVar_12038 = ROM.rd(cppVar_12037);
	bool cppVar_12040 = (cppVar_12038 == 135);
	if (cppVar_12040) {
	cppVar_12036 = PCON;
	} else {
	BIT_VEC cppVar_12041;
	BIT_VEC cppVar_12042 = PC + 1;
	cppVar_12042 = (cppVar_12042 & cppMask_un_16_);
	BIT_VEC cppVar_12043 = ROM.rd(cppVar_12042);
	bool cppVar_12045 = (cppVar_12043 == 136);
	if (cppVar_12045) {
	cppVar_12041 = TCON;
	} else {
	BIT_VEC cppVar_12046;
	BIT_VEC cppVar_12047 = PC + 1;
	cppVar_12047 = (cppVar_12047 & cppMask_un_16_);
	BIT_VEC cppVar_12048 = ROM.rd(cppVar_12047);
	bool cppVar_12050 = (cppVar_12048 == 137);
	if (cppVar_12050) {
	cppVar_12046 = TMOD;
	} else {
	BIT_VEC cppVar_12051;
	BIT_VEC cppVar_12052 = PC + 1;
	cppVar_12052 = (cppVar_12052 & cppMask_un_16_);
	BIT_VEC cppVar_12053 = ROM.rd(cppVar_12052);
	bool cppVar_12055 = (cppVar_12053 == 138);
	if (cppVar_12055) {
	cppVar_12051 = TL0;
	} else {
	BIT_VEC cppVar_12056;
	BIT_VEC cppVar_12057 = PC + 1;
	cppVar_12057 = (cppVar_12057 & cppMask_un_16_);
	BIT_VEC cppVar_12058 = ROM.rd(cppVar_12057);
	bool cppVar_12060 = (cppVar_12058 == 140);
	if (cppVar_12060) {
	cppVar_12056 = TH0;
	} else {
	BIT_VEC cppVar_12061;
	BIT_VEC cppVar_12062 = PC + 1;
	cppVar_12062 = (cppVar_12062 & cppMask_un_16_);
	BIT_VEC cppVar_12063 = ROM.rd(cppVar_12062);
	bool cppVar_12065 = (cppVar_12063 == 139);
	if (cppVar_12065) {
	cppVar_12061 = TL1;
	} else {
	BIT_VEC cppVar_12066;
	BIT_VEC cppVar_12067 = PC + 1;
	cppVar_12067 = (cppVar_12067 & cppMask_un_16_);
	BIT_VEC cppVar_12068 = ROM.rd(cppVar_12067);
	bool cppVar_12070 = (cppVar_12068 == 141);
	if (cppVar_12070) {
	cppVar_12066 = TH1;
	} else {
	BIT_VEC cppVar_12071;
	BIT_VEC cppVar_12072 = PC + 1;
	cppVar_12072 = (cppVar_12072 & cppMask_un_16_);
	BIT_VEC cppVar_12073 = ROM.rd(cppVar_12072);
	bool cppVar_12075 = (cppVar_12073 == 144);
	if (cppVar_12075) {
	cppVar_12071 = P1;
	} else {
	BIT_VEC cppVar_12076;
	BIT_VEC cppVar_12077 = PC + 1;
	cppVar_12077 = (cppVar_12077 & cppMask_un_16_);
	BIT_VEC cppVar_12078 = ROM.rd(cppVar_12077);
	bool cppVar_12080 = (cppVar_12078 == 152);
	if (cppVar_12080) {
	cppVar_12076 = SCON;
	} else {
	BIT_VEC cppVar_12081;
	BIT_VEC cppVar_12082 = PC + 1;
	cppVar_12082 = (cppVar_12082 & cppMask_un_16_);
	BIT_VEC cppVar_12083 = ROM.rd(cppVar_12082);
	bool cppVar_12085 = (cppVar_12083 == 153);
	if (cppVar_12085) {
	cppVar_12081 = SBUF;
	} else {
	BIT_VEC cppVar_12086;
	BIT_VEC cppVar_12087 = PC + 1;
	cppVar_12087 = (cppVar_12087 & cppMask_un_16_);
	BIT_VEC cppVar_12088 = ROM.rd(cppVar_12087);
	bool cppVar_12090 = (cppVar_12088 == 160);
	if (cppVar_12090) {
	cppVar_12086 = P2;
	} else {
	BIT_VEC cppVar_12091;
	BIT_VEC cppVar_12092 = PC + 1;
	cppVar_12092 = (cppVar_12092 & cppMask_un_16_);
	BIT_VEC cppVar_12093 = ROM.rd(cppVar_12092);
	bool cppVar_12095 = (cppVar_12093 == 168);
	if (cppVar_12095) {
	cppVar_12091 = IE;
	} else {
	BIT_VEC cppVar_12096;
	BIT_VEC cppVar_12097 = PC + 1;
	cppVar_12097 = (cppVar_12097 & cppMask_un_16_);
	BIT_VEC cppVar_12098 = ROM.rd(cppVar_12097);
	bool cppVar_12100 = (cppVar_12098 == 176);
	if (cppVar_12100) {
	cppVar_12096 = P3;
	} else {
	BIT_VEC cppVar_12101;
	BIT_VEC cppVar_12102 = PC + 1;
	cppVar_12102 = (cppVar_12102 & cppMask_un_16_);
	BIT_VEC cppVar_12103 = ROM.rd(cppVar_12102);
	bool cppVar_12105 = (cppVar_12103 == 184);
	if (cppVar_12105) {
	cppVar_12101 = IP;
	} else {
	BIT_VEC cppVar_12106;
	BIT_VEC cppVar_12107 = PC + 1;
	cppVar_12107 = (cppVar_12107 & cppMask_un_16_);
	BIT_VEC cppVar_12108 = ROM.rd(cppVar_12107);
	bool cppVar_12110 = (cppVar_12108 == 208);
	if (cppVar_12110) {
	cppVar_12106 = PSW;
	} else {
	BIT_VEC cppVar_12111;
	BIT_VEC cppVar_12112 = PC + 1;
	cppVar_12112 = (cppVar_12112 & cppMask_un_16_);
	BIT_VEC cppVar_12113 = ROM.rd(cppVar_12112);
	bool cppVar_12115 = (cppVar_12113 == 224);
	if (cppVar_12115) {
	cppVar_12111 = ACC;
	} else {
	BIT_VEC cppVar_12116;
	BIT_VEC cppVar_12117 = PC + 1;
	cppVar_12117 = (cppVar_12117 & cppMask_un_16_);
	BIT_VEC cppVar_12118 = ROM.rd(cppVar_12117);
	bool cppVar_12120 = (cppVar_12118 == 240);
	if (cppVar_12120) {
	cppVar_12116 = B;
	} else {
	cppVar_12116 = 0;
	}
	cppVar_12111 = cppVar_12116;
	}
	cppVar_12106 = cppVar_12111;
	}
	cppVar_12101 = cppVar_12106;
	}
	cppVar_12096 = cppVar_12101;
	}
	cppVar_12091 = cppVar_12096;
	}
	cppVar_12086 = cppVar_12091;
	}
	cppVar_12081 = cppVar_12086;
	}
	cppVar_12076 = cppVar_12081;
	}
	cppVar_12071 = cppVar_12076;
	}
	cppVar_12066 = cppVar_12071;
	}
	cppVar_12061 = cppVar_12066;
	}
	cppVar_12056 = cppVar_12061;
	}
	cppVar_12051 = cppVar_12056;
	}
	cppVar_12046 = cppVar_12051;
	}
	cppVar_12041 = cppVar_12046;
	}
	cppVar_12036 = cppVar_12041;
	}
	cppVar_12031 = cppVar_12036;
	}
	cppVar_12026 = cppVar_12031;
	}
	cppVar_12021 = cppVar_12026;
	}
	cppVar_12016 = cppVar_12021;
	}
	cppVar_12007 = cppVar_12016;
	}
	BIT_VEC cppVar_12123 = PC + 2;
	cppVar_12123 = (cppVar_12123 & cppMask_un_16_);
	BIT_VEC cppVar_12124 = ROM.rd(cppVar_12123);
	BIT_VEC cppVar_12125 = cppVar_12007 | cppVar_12124;
	cppVar_12001 = cppVar_12125;
	} else {
	cppVar_12001 = DPL;
	}
	cppVar_11997 = cppVar_12001;
	} else {
	BIT_VEC cppVar_12126;
	BIT_VEC cppVar_12127 = ROM.rd(PC);
	bool cppVar_12129 = (cppVar_12127 == 66);
	if (cppVar_12129) {
	BIT_VEC cppVar_12130;
	BIT_VEC cppVar_12132 = PC + 1;
	cppVar_12132 = (cppVar_12132 & cppMask_un_16_);
	BIT_VEC cppVar_12133 = ROM.rd(cppVar_12132);
	bool cppVar_12135 = (cppVar_12133 == 130);
	if (cppVar_12135) {
	BIT_VEC cppVar_12136;
	BIT_VEC cppVar_12137 = PC + 1;
	cppVar_12137 = (cppVar_12137 & cppMask_un_16_);
	BIT_VEC cppVar_12138 = ROM.rd(cppVar_12137);
	BIT_VEC cppVar_12139 = (cppVar_12138 >> 7) & cppMask_un_1_;
	bool cppVar_12141 = (cppVar_12139 == 0);
	if (cppVar_12141) {
	BIT_VEC cppVar_12142 = PC + 1;
	cppVar_12142 = (cppVar_12142 & cppMask_un_16_);
	BIT_VEC cppVar_12143 = ROM.rd(cppVar_12142);
	BIT_VEC cppVar_12144 = IRAM.rd(cppVar_12143);
	cppVar_12136 = cppVar_12144;
	} else {
	BIT_VEC cppVar_12145;
	BIT_VEC cppVar_12146 = PC + 1;
	cppVar_12146 = (cppVar_12146 & cppMask_un_16_);
	BIT_VEC cppVar_12147 = ROM.rd(cppVar_12146);
	bool cppVar_12149 = (cppVar_12147 == 128);
	if (cppVar_12149) {
	cppVar_12145 = P0;
	} else {
	BIT_VEC cppVar_12150;
	BIT_VEC cppVar_12151 = PC + 1;
	cppVar_12151 = (cppVar_12151 & cppMask_un_16_);
	BIT_VEC cppVar_12152 = ROM.rd(cppVar_12151);
	bool cppVar_12154 = (cppVar_12152 == 129);
	if (cppVar_12154) {
	cppVar_12150 = SP;
	} else {
	BIT_VEC cppVar_12155;
	BIT_VEC cppVar_12156 = PC + 1;
	cppVar_12156 = (cppVar_12156 & cppMask_un_16_);
	BIT_VEC cppVar_12157 = ROM.rd(cppVar_12156);
	bool cppVar_12159 = (cppVar_12157 == 130);
	if (cppVar_12159) {
	cppVar_12155 = DPL;
	} else {
	BIT_VEC cppVar_12160;
	BIT_VEC cppVar_12161 = PC + 1;
	cppVar_12161 = (cppVar_12161 & cppMask_un_16_);
	BIT_VEC cppVar_12162 = ROM.rd(cppVar_12161);
	bool cppVar_12164 = (cppVar_12162 == 131);
	if (cppVar_12164) {
	cppVar_12160 = DPH;
	} else {
	BIT_VEC cppVar_12165;
	BIT_VEC cppVar_12166 = PC + 1;
	cppVar_12166 = (cppVar_12166 & cppMask_un_16_);
	BIT_VEC cppVar_12167 = ROM.rd(cppVar_12166);
	bool cppVar_12169 = (cppVar_12167 == 135);
	if (cppVar_12169) {
	cppVar_12165 = PCON;
	} else {
	BIT_VEC cppVar_12170;
	BIT_VEC cppVar_12171 = PC + 1;
	cppVar_12171 = (cppVar_12171 & cppMask_un_16_);
	BIT_VEC cppVar_12172 = ROM.rd(cppVar_12171);
	bool cppVar_12174 = (cppVar_12172 == 136);
	if (cppVar_12174) {
	cppVar_12170 = TCON;
	} else {
	BIT_VEC cppVar_12175;
	BIT_VEC cppVar_12176 = PC + 1;
	cppVar_12176 = (cppVar_12176 & cppMask_un_16_);
	BIT_VEC cppVar_12177 = ROM.rd(cppVar_12176);
	bool cppVar_12179 = (cppVar_12177 == 137);
	if (cppVar_12179) {
	cppVar_12175 = TMOD;
	} else {
	BIT_VEC cppVar_12180;
	BIT_VEC cppVar_12181 = PC + 1;
	cppVar_12181 = (cppVar_12181 & cppMask_un_16_);
	BIT_VEC cppVar_12182 = ROM.rd(cppVar_12181);
	bool cppVar_12184 = (cppVar_12182 == 138);
	if (cppVar_12184) {
	cppVar_12180 = TL0;
	} else {
	BIT_VEC cppVar_12185;
	BIT_VEC cppVar_12186 = PC + 1;
	cppVar_12186 = (cppVar_12186 & cppMask_un_16_);
	BIT_VEC cppVar_12187 = ROM.rd(cppVar_12186);
	bool cppVar_12189 = (cppVar_12187 == 140);
	if (cppVar_12189) {
	cppVar_12185 = TH0;
	} else {
	BIT_VEC cppVar_12190;
	BIT_VEC cppVar_12191 = PC + 1;
	cppVar_12191 = (cppVar_12191 & cppMask_un_16_);
	BIT_VEC cppVar_12192 = ROM.rd(cppVar_12191);
	bool cppVar_12194 = (cppVar_12192 == 139);
	if (cppVar_12194) {
	cppVar_12190 = TL1;
	} else {
	BIT_VEC cppVar_12195;
	BIT_VEC cppVar_12196 = PC + 1;
	cppVar_12196 = (cppVar_12196 & cppMask_un_16_);
	BIT_VEC cppVar_12197 = ROM.rd(cppVar_12196);
	bool cppVar_12199 = (cppVar_12197 == 141);
	if (cppVar_12199) {
	cppVar_12195 = TH1;
	} else {
	BIT_VEC cppVar_12200;
	BIT_VEC cppVar_12201 = PC + 1;
	cppVar_12201 = (cppVar_12201 & cppMask_un_16_);
	BIT_VEC cppVar_12202 = ROM.rd(cppVar_12201);
	bool cppVar_12204 = (cppVar_12202 == 144);
	if (cppVar_12204) {
	cppVar_12200 = P1;
	} else {
	BIT_VEC cppVar_12205;
	BIT_VEC cppVar_12206 = PC + 1;
	cppVar_12206 = (cppVar_12206 & cppMask_un_16_);
	BIT_VEC cppVar_12207 = ROM.rd(cppVar_12206);
	bool cppVar_12209 = (cppVar_12207 == 152);
	if (cppVar_12209) {
	cppVar_12205 = SCON;
	} else {
	BIT_VEC cppVar_12210;
	BIT_VEC cppVar_12211 = PC + 1;
	cppVar_12211 = (cppVar_12211 & cppMask_un_16_);
	BIT_VEC cppVar_12212 = ROM.rd(cppVar_12211);
	bool cppVar_12214 = (cppVar_12212 == 153);
	if (cppVar_12214) {
	cppVar_12210 = SBUF;
	} else {
	BIT_VEC cppVar_12215;
	BIT_VEC cppVar_12216 = PC + 1;
	cppVar_12216 = (cppVar_12216 & cppMask_un_16_);
	BIT_VEC cppVar_12217 = ROM.rd(cppVar_12216);
	bool cppVar_12219 = (cppVar_12217 == 160);
	if (cppVar_12219) {
	cppVar_12215 = P2;
	} else {
	BIT_VEC cppVar_12220;
	BIT_VEC cppVar_12221 = PC + 1;
	cppVar_12221 = (cppVar_12221 & cppMask_un_16_);
	BIT_VEC cppVar_12222 = ROM.rd(cppVar_12221);
	bool cppVar_12224 = (cppVar_12222 == 168);
	if (cppVar_12224) {
	cppVar_12220 = IE;
	} else {
	BIT_VEC cppVar_12225;
	BIT_VEC cppVar_12226 = PC + 1;
	cppVar_12226 = (cppVar_12226 & cppMask_un_16_);
	BIT_VEC cppVar_12227 = ROM.rd(cppVar_12226);
	bool cppVar_12229 = (cppVar_12227 == 176);
	if (cppVar_12229) {
	cppVar_12225 = P3;
	} else {
	BIT_VEC cppVar_12230;
	BIT_VEC cppVar_12231 = PC + 1;
	cppVar_12231 = (cppVar_12231 & cppMask_un_16_);
	BIT_VEC cppVar_12232 = ROM.rd(cppVar_12231);
	bool cppVar_12234 = (cppVar_12232 == 184);
	if (cppVar_12234) {
	cppVar_12230 = IP;
	} else {
	BIT_VEC cppVar_12235;
	BIT_VEC cppVar_12236 = PC + 1;
	cppVar_12236 = (cppVar_12236 & cppMask_un_16_);
	BIT_VEC cppVar_12237 = ROM.rd(cppVar_12236);
	bool cppVar_12239 = (cppVar_12237 == 208);
	if (cppVar_12239) {
	cppVar_12235 = PSW;
	} else {
	BIT_VEC cppVar_12240;
	BIT_VEC cppVar_12241 = PC + 1;
	cppVar_12241 = (cppVar_12241 & cppMask_un_16_);
	BIT_VEC cppVar_12242 = ROM.rd(cppVar_12241);
	bool cppVar_12244 = (cppVar_12242 == 224);
	if (cppVar_12244) {
	cppVar_12240 = ACC;
	} else {
	BIT_VEC cppVar_12245;
	BIT_VEC cppVar_12246 = PC + 1;
	cppVar_12246 = (cppVar_12246 & cppMask_un_16_);
	BIT_VEC cppVar_12247 = ROM.rd(cppVar_12246);
	bool cppVar_12249 = (cppVar_12247 == 240);
	if (cppVar_12249) {
	cppVar_12245 = B;
	} else {
	cppVar_12245 = 0;
	}
	cppVar_12240 = cppVar_12245;
	}
	cppVar_12235 = cppVar_12240;
	}
	cppVar_12230 = cppVar_12235;
	}
	cppVar_12225 = cppVar_12230;
	}
	cppVar_12220 = cppVar_12225;
	}
	cppVar_12215 = cppVar_12220;
	}
	cppVar_12210 = cppVar_12215;
	}
	cppVar_12205 = cppVar_12210;
	}
	cppVar_12200 = cppVar_12205;
	}
	cppVar_12195 = cppVar_12200;
	}
	cppVar_12190 = cppVar_12195;
	}
	cppVar_12185 = cppVar_12190;
	}
	cppVar_12180 = cppVar_12185;
	}
	cppVar_12175 = cppVar_12180;
	}
	cppVar_12170 = cppVar_12175;
	}
	cppVar_12165 = cppVar_12170;
	}
	cppVar_12160 = cppVar_12165;
	}
	cppVar_12155 = cppVar_12160;
	}
	cppVar_12150 = cppVar_12155;
	}
	cppVar_12145 = cppVar_12150;
	}
	cppVar_12136 = cppVar_12145;
	}
	BIT_VEC cppVar_12251 = cppVar_12136 | ACC;
	cppVar_12130 = cppVar_12251;
	} else {
	cppVar_12130 = DPL;
	}
	cppVar_12126 = cppVar_12130;
	} else {
	BIT_VEC cppVar_12252;
	BIT_VEC cppVar_12253 = ROM.rd(PC);
	bool cppVar_12255 = (cppVar_12253 == 213);
	BIT_VEC cppVar_12256 = ROM.rd(PC);
	bool cppVar_12258 = (cppVar_12256 == 21);
	bool cppVar_12259 = cppVar_12255 || cppVar_12258;
	if (cppVar_12259) {
	BIT_VEC cppVar_12260;
	BIT_VEC cppVar_12262 = PC + 1;
	cppVar_12262 = (cppVar_12262 & cppMask_un_16_);
	BIT_VEC cppVar_12263 = ROM.rd(cppVar_12262);
	bool cppVar_12265 = (cppVar_12263 == 130);
	if (cppVar_12265) {
	BIT_VEC cppVar_12266;
	BIT_VEC cppVar_12267 = PC + 1;
	cppVar_12267 = (cppVar_12267 & cppMask_un_16_);
	BIT_VEC cppVar_12268 = ROM.rd(cppVar_12267);
	BIT_VEC cppVar_12269 = (cppVar_12268 >> 7) & cppMask_un_1_;
	bool cppVar_12271 = (cppVar_12269 == 0);
	if (cppVar_12271) {
	BIT_VEC cppVar_12272 = PC + 1;
	cppVar_12272 = (cppVar_12272 & cppMask_un_16_);
	BIT_VEC cppVar_12273 = ROM.rd(cppVar_12272);
	BIT_VEC cppVar_12274 = IRAM.rd(cppVar_12273);
	cppVar_12266 = cppVar_12274;
	} else {
	BIT_VEC cppVar_12275;
	BIT_VEC cppVar_12276 = PC + 1;
	cppVar_12276 = (cppVar_12276 & cppMask_un_16_);
	BIT_VEC cppVar_12277 = ROM.rd(cppVar_12276);
	bool cppVar_12279 = (cppVar_12277 == 128);
	if (cppVar_12279) {
	cppVar_12275 = P0;
	} else {
	BIT_VEC cppVar_12280;
	BIT_VEC cppVar_12281 = PC + 1;
	cppVar_12281 = (cppVar_12281 & cppMask_un_16_);
	BIT_VEC cppVar_12282 = ROM.rd(cppVar_12281);
	bool cppVar_12284 = (cppVar_12282 == 129);
	if (cppVar_12284) {
	cppVar_12280 = SP;
	} else {
	BIT_VEC cppVar_12285;
	BIT_VEC cppVar_12286 = PC + 1;
	cppVar_12286 = (cppVar_12286 & cppMask_un_16_);
	BIT_VEC cppVar_12287 = ROM.rd(cppVar_12286);
	bool cppVar_12289 = (cppVar_12287 == 130);
	if (cppVar_12289) {
	cppVar_12285 = DPL;
	} else {
	BIT_VEC cppVar_12290;
	BIT_VEC cppVar_12291 = PC + 1;
	cppVar_12291 = (cppVar_12291 & cppMask_un_16_);
	BIT_VEC cppVar_12292 = ROM.rd(cppVar_12291);
	bool cppVar_12294 = (cppVar_12292 == 131);
	if (cppVar_12294) {
	cppVar_12290 = DPH;
	} else {
	BIT_VEC cppVar_12295;
	BIT_VEC cppVar_12296 = PC + 1;
	cppVar_12296 = (cppVar_12296 & cppMask_un_16_);
	BIT_VEC cppVar_12297 = ROM.rd(cppVar_12296);
	bool cppVar_12299 = (cppVar_12297 == 135);
	if (cppVar_12299) {
	cppVar_12295 = PCON;
	} else {
	BIT_VEC cppVar_12300;
	BIT_VEC cppVar_12301 = PC + 1;
	cppVar_12301 = (cppVar_12301 & cppMask_un_16_);
	BIT_VEC cppVar_12302 = ROM.rd(cppVar_12301);
	bool cppVar_12304 = (cppVar_12302 == 136);
	if (cppVar_12304) {
	cppVar_12300 = TCON;
	} else {
	BIT_VEC cppVar_12305;
	BIT_VEC cppVar_12306 = PC + 1;
	cppVar_12306 = (cppVar_12306 & cppMask_un_16_);
	BIT_VEC cppVar_12307 = ROM.rd(cppVar_12306);
	bool cppVar_12309 = (cppVar_12307 == 137);
	if (cppVar_12309) {
	cppVar_12305 = TMOD;
	} else {
	BIT_VEC cppVar_12310;
	BIT_VEC cppVar_12311 = PC + 1;
	cppVar_12311 = (cppVar_12311 & cppMask_un_16_);
	BIT_VEC cppVar_12312 = ROM.rd(cppVar_12311);
	bool cppVar_12314 = (cppVar_12312 == 138);
	if (cppVar_12314) {
	cppVar_12310 = TL0;
	} else {
	BIT_VEC cppVar_12315;
	BIT_VEC cppVar_12316 = PC + 1;
	cppVar_12316 = (cppVar_12316 & cppMask_un_16_);
	BIT_VEC cppVar_12317 = ROM.rd(cppVar_12316);
	bool cppVar_12319 = (cppVar_12317 == 140);
	if (cppVar_12319) {
	cppVar_12315 = TH0;
	} else {
	BIT_VEC cppVar_12320;
	BIT_VEC cppVar_12321 = PC + 1;
	cppVar_12321 = (cppVar_12321 & cppMask_un_16_);
	BIT_VEC cppVar_12322 = ROM.rd(cppVar_12321);
	bool cppVar_12324 = (cppVar_12322 == 139);
	if (cppVar_12324) {
	cppVar_12320 = TL1;
	} else {
	BIT_VEC cppVar_12325;
	BIT_VEC cppVar_12326 = PC + 1;
	cppVar_12326 = (cppVar_12326 & cppMask_un_16_);
	BIT_VEC cppVar_12327 = ROM.rd(cppVar_12326);
	bool cppVar_12329 = (cppVar_12327 == 141);
	if (cppVar_12329) {
	cppVar_12325 = TH1;
	} else {
	BIT_VEC cppVar_12330;
	BIT_VEC cppVar_12331 = PC + 1;
	cppVar_12331 = (cppVar_12331 & cppMask_un_16_);
	BIT_VEC cppVar_12332 = ROM.rd(cppVar_12331);
	bool cppVar_12334 = (cppVar_12332 == 144);
	if (cppVar_12334) {
	cppVar_12330 = P1;
	} else {
	BIT_VEC cppVar_12335;
	BIT_VEC cppVar_12336 = PC + 1;
	cppVar_12336 = (cppVar_12336 & cppMask_un_16_);
	BIT_VEC cppVar_12337 = ROM.rd(cppVar_12336);
	bool cppVar_12339 = (cppVar_12337 == 152);
	if (cppVar_12339) {
	cppVar_12335 = SCON;
	} else {
	BIT_VEC cppVar_12340;
	BIT_VEC cppVar_12341 = PC + 1;
	cppVar_12341 = (cppVar_12341 & cppMask_un_16_);
	BIT_VEC cppVar_12342 = ROM.rd(cppVar_12341);
	bool cppVar_12344 = (cppVar_12342 == 153);
	if (cppVar_12344) {
	cppVar_12340 = SBUF;
	} else {
	BIT_VEC cppVar_12345;
	BIT_VEC cppVar_12346 = PC + 1;
	cppVar_12346 = (cppVar_12346 & cppMask_un_16_);
	BIT_VEC cppVar_12347 = ROM.rd(cppVar_12346);
	bool cppVar_12349 = (cppVar_12347 == 160);
	if (cppVar_12349) {
	cppVar_12345 = P2;
	} else {
	BIT_VEC cppVar_12350;
	BIT_VEC cppVar_12351 = PC + 1;
	cppVar_12351 = (cppVar_12351 & cppMask_un_16_);
	BIT_VEC cppVar_12352 = ROM.rd(cppVar_12351);
	bool cppVar_12354 = (cppVar_12352 == 168);
	if (cppVar_12354) {
	cppVar_12350 = IE;
	} else {
	BIT_VEC cppVar_12355;
	BIT_VEC cppVar_12356 = PC + 1;
	cppVar_12356 = (cppVar_12356 & cppMask_un_16_);
	BIT_VEC cppVar_12357 = ROM.rd(cppVar_12356);
	bool cppVar_12359 = (cppVar_12357 == 176);
	if (cppVar_12359) {
	cppVar_12355 = P3;
	} else {
	BIT_VEC cppVar_12360;
	BIT_VEC cppVar_12361 = PC + 1;
	cppVar_12361 = (cppVar_12361 & cppMask_un_16_);
	BIT_VEC cppVar_12362 = ROM.rd(cppVar_12361);
	bool cppVar_12364 = (cppVar_12362 == 184);
	if (cppVar_12364) {
	cppVar_12360 = IP;
	} else {
	BIT_VEC cppVar_12365;
	BIT_VEC cppVar_12366 = PC + 1;
	cppVar_12366 = (cppVar_12366 & cppMask_un_16_);
	BIT_VEC cppVar_12367 = ROM.rd(cppVar_12366);
	bool cppVar_12369 = (cppVar_12367 == 208);
	if (cppVar_12369) {
	cppVar_12365 = PSW;
	} else {
	BIT_VEC cppVar_12370;
	BIT_VEC cppVar_12371 = PC + 1;
	cppVar_12371 = (cppVar_12371 & cppMask_un_16_);
	BIT_VEC cppVar_12372 = ROM.rd(cppVar_12371);
	bool cppVar_12374 = (cppVar_12372 == 224);
	if (cppVar_12374) {
	cppVar_12370 = ACC;
	} else {
	BIT_VEC cppVar_12375;
	BIT_VEC cppVar_12376 = PC + 1;
	cppVar_12376 = (cppVar_12376 & cppMask_un_16_);
	BIT_VEC cppVar_12377 = ROM.rd(cppVar_12376);
	bool cppVar_12379 = (cppVar_12377 == 240);
	if (cppVar_12379) {
	cppVar_12375 = B;
	} else {
	cppVar_12375 = 0;
	}
	cppVar_12370 = cppVar_12375;
	}
	cppVar_12365 = cppVar_12370;
	}
	cppVar_12360 = cppVar_12365;
	}
	cppVar_12355 = cppVar_12360;
	}
	cppVar_12350 = cppVar_12355;
	}
	cppVar_12345 = cppVar_12350;
	}
	cppVar_12340 = cppVar_12345;
	}
	cppVar_12335 = cppVar_12340;
	}
	cppVar_12330 = cppVar_12335;
	}
	cppVar_12325 = cppVar_12330;
	}
	cppVar_12320 = cppVar_12325;
	}
	cppVar_12315 = cppVar_12320;
	}
	cppVar_12310 = cppVar_12315;
	}
	cppVar_12305 = cppVar_12310;
	}
	cppVar_12300 = cppVar_12305;
	}
	cppVar_12295 = cppVar_12300;
	}
	cppVar_12290 = cppVar_12295;
	}
	cppVar_12285 = cppVar_12290;
	}
	cppVar_12280 = cppVar_12285;
	}
	cppVar_12275 = cppVar_12280;
	}
	cppVar_12266 = cppVar_12275;
	}
	BIT_VEC cppVar_12382 = cppVar_12266 - 1;
	cppVar_12382 = (cppVar_12382 & cppMask_un_8_);
	cppVar_12260 = cppVar_12382;
	} else {
	cppVar_12260 = DPL;
	}
	cppVar_12252 = cppVar_12260;
	} else {
	BIT_VEC cppVar_12383;
	BIT_VEC cppVar_12384 = ROM.rd(PC);
	bool cppVar_12386 = (cppVar_12384 == 5);
	if (cppVar_12386) {
	BIT_VEC cppVar_12387;
	BIT_VEC cppVar_12389 = PC + 1;
	cppVar_12389 = (cppVar_12389 & cppMask_un_16_);
	BIT_VEC cppVar_12390 = ROM.rd(cppVar_12389);
	bool cppVar_12392 = (cppVar_12390 == 130);
	if (cppVar_12392) {
	BIT_VEC cppVar_12393;
	BIT_VEC cppVar_12394 = PC + 1;
	cppVar_12394 = (cppVar_12394 & cppMask_un_16_);
	BIT_VEC cppVar_12395 = ROM.rd(cppVar_12394);
	BIT_VEC cppVar_12396 = (cppVar_12395 >> 7) & cppMask_un_1_;
	bool cppVar_12398 = (cppVar_12396 == 0);
	if (cppVar_12398) {
	BIT_VEC cppVar_12399 = PC + 1;
	cppVar_12399 = (cppVar_12399 & cppMask_un_16_);
	BIT_VEC cppVar_12400 = ROM.rd(cppVar_12399);
	BIT_VEC cppVar_12401 = IRAM.rd(cppVar_12400);
	cppVar_12393 = cppVar_12401;
	} else {
	BIT_VEC cppVar_12402;
	BIT_VEC cppVar_12403 = PC + 1;
	cppVar_12403 = (cppVar_12403 & cppMask_un_16_);
	BIT_VEC cppVar_12404 = ROM.rd(cppVar_12403);
	bool cppVar_12406 = (cppVar_12404 == 128);
	if (cppVar_12406) {
	cppVar_12402 = P0;
	} else {
	BIT_VEC cppVar_12407;
	BIT_VEC cppVar_12408 = PC + 1;
	cppVar_12408 = (cppVar_12408 & cppMask_un_16_);
	BIT_VEC cppVar_12409 = ROM.rd(cppVar_12408);
	bool cppVar_12411 = (cppVar_12409 == 129);
	if (cppVar_12411) {
	cppVar_12407 = SP;
	} else {
	BIT_VEC cppVar_12412;
	BIT_VEC cppVar_12413 = PC + 1;
	cppVar_12413 = (cppVar_12413 & cppMask_un_16_);
	BIT_VEC cppVar_12414 = ROM.rd(cppVar_12413);
	bool cppVar_12416 = (cppVar_12414 == 130);
	if (cppVar_12416) {
	cppVar_12412 = DPL;
	} else {
	BIT_VEC cppVar_12417;
	BIT_VEC cppVar_12418 = PC + 1;
	cppVar_12418 = (cppVar_12418 & cppMask_un_16_);
	BIT_VEC cppVar_12419 = ROM.rd(cppVar_12418);
	bool cppVar_12421 = (cppVar_12419 == 131);
	if (cppVar_12421) {
	cppVar_12417 = DPH;
	} else {
	BIT_VEC cppVar_12422;
	BIT_VEC cppVar_12423 = PC + 1;
	cppVar_12423 = (cppVar_12423 & cppMask_un_16_);
	BIT_VEC cppVar_12424 = ROM.rd(cppVar_12423);
	bool cppVar_12426 = (cppVar_12424 == 135);
	if (cppVar_12426) {
	cppVar_12422 = PCON;
	} else {
	BIT_VEC cppVar_12427;
	BIT_VEC cppVar_12428 = PC + 1;
	cppVar_12428 = (cppVar_12428 & cppMask_un_16_);
	BIT_VEC cppVar_12429 = ROM.rd(cppVar_12428);
	bool cppVar_12431 = (cppVar_12429 == 136);
	if (cppVar_12431) {
	cppVar_12427 = TCON;
	} else {
	BIT_VEC cppVar_12432;
	BIT_VEC cppVar_12433 = PC + 1;
	cppVar_12433 = (cppVar_12433 & cppMask_un_16_);
	BIT_VEC cppVar_12434 = ROM.rd(cppVar_12433);
	bool cppVar_12436 = (cppVar_12434 == 137);
	if (cppVar_12436) {
	cppVar_12432 = TMOD;
	} else {
	BIT_VEC cppVar_12437;
	BIT_VEC cppVar_12438 = PC + 1;
	cppVar_12438 = (cppVar_12438 & cppMask_un_16_);
	BIT_VEC cppVar_12439 = ROM.rd(cppVar_12438);
	bool cppVar_12441 = (cppVar_12439 == 138);
	if (cppVar_12441) {
	cppVar_12437 = TL0;
	} else {
	BIT_VEC cppVar_12442;
	BIT_VEC cppVar_12443 = PC + 1;
	cppVar_12443 = (cppVar_12443 & cppMask_un_16_);
	BIT_VEC cppVar_12444 = ROM.rd(cppVar_12443);
	bool cppVar_12446 = (cppVar_12444 == 140);
	if (cppVar_12446) {
	cppVar_12442 = TH0;
	} else {
	BIT_VEC cppVar_12447;
	BIT_VEC cppVar_12448 = PC + 1;
	cppVar_12448 = (cppVar_12448 & cppMask_un_16_);
	BIT_VEC cppVar_12449 = ROM.rd(cppVar_12448);
	bool cppVar_12451 = (cppVar_12449 == 139);
	if (cppVar_12451) {
	cppVar_12447 = TL1;
	} else {
	BIT_VEC cppVar_12452;
	BIT_VEC cppVar_12453 = PC + 1;
	cppVar_12453 = (cppVar_12453 & cppMask_un_16_);
	BIT_VEC cppVar_12454 = ROM.rd(cppVar_12453);
	bool cppVar_12456 = (cppVar_12454 == 141);
	if (cppVar_12456) {
	cppVar_12452 = TH1;
	} else {
	BIT_VEC cppVar_12457;
	BIT_VEC cppVar_12458 = PC + 1;
	cppVar_12458 = (cppVar_12458 & cppMask_un_16_);
	BIT_VEC cppVar_12459 = ROM.rd(cppVar_12458);
	bool cppVar_12461 = (cppVar_12459 == 144);
	if (cppVar_12461) {
	cppVar_12457 = P1;
	} else {
	BIT_VEC cppVar_12462;
	BIT_VEC cppVar_12463 = PC + 1;
	cppVar_12463 = (cppVar_12463 & cppMask_un_16_);
	BIT_VEC cppVar_12464 = ROM.rd(cppVar_12463);
	bool cppVar_12466 = (cppVar_12464 == 152);
	if (cppVar_12466) {
	cppVar_12462 = SCON;
	} else {
	BIT_VEC cppVar_12467;
	BIT_VEC cppVar_12468 = PC + 1;
	cppVar_12468 = (cppVar_12468 & cppMask_un_16_);
	BIT_VEC cppVar_12469 = ROM.rd(cppVar_12468);
	bool cppVar_12471 = (cppVar_12469 == 153);
	if (cppVar_12471) {
	cppVar_12467 = SBUF;
	} else {
	BIT_VEC cppVar_12472;
	BIT_VEC cppVar_12473 = PC + 1;
	cppVar_12473 = (cppVar_12473 & cppMask_un_16_);
	BIT_VEC cppVar_12474 = ROM.rd(cppVar_12473);
	bool cppVar_12476 = (cppVar_12474 == 160);
	if (cppVar_12476) {
	cppVar_12472 = P2;
	} else {
	BIT_VEC cppVar_12477;
	BIT_VEC cppVar_12478 = PC + 1;
	cppVar_12478 = (cppVar_12478 & cppMask_un_16_);
	BIT_VEC cppVar_12479 = ROM.rd(cppVar_12478);
	bool cppVar_12481 = (cppVar_12479 == 168);
	if (cppVar_12481) {
	cppVar_12477 = IE;
	} else {
	BIT_VEC cppVar_12482;
	BIT_VEC cppVar_12483 = PC + 1;
	cppVar_12483 = (cppVar_12483 & cppMask_un_16_);
	BIT_VEC cppVar_12484 = ROM.rd(cppVar_12483);
	bool cppVar_12486 = (cppVar_12484 == 176);
	if (cppVar_12486) {
	cppVar_12482 = P3;
	} else {
	BIT_VEC cppVar_12487;
	BIT_VEC cppVar_12488 = PC + 1;
	cppVar_12488 = (cppVar_12488 & cppMask_un_16_);
	BIT_VEC cppVar_12489 = ROM.rd(cppVar_12488);
	bool cppVar_12491 = (cppVar_12489 == 184);
	if (cppVar_12491) {
	cppVar_12487 = IP;
	} else {
	BIT_VEC cppVar_12492;
	BIT_VEC cppVar_12493 = PC + 1;
	cppVar_12493 = (cppVar_12493 & cppMask_un_16_);
	BIT_VEC cppVar_12494 = ROM.rd(cppVar_12493);
	bool cppVar_12496 = (cppVar_12494 == 208);
	if (cppVar_12496) {
	cppVar_12492 = PSW;
	} else {
	BIT_VEC cppVar_12497;
	BIT_VEC cppVar_12498 = PC + 1;
	cppVar_12498 = (cppVar_12498 & cppMask_un_16_);
	BIT_VEC cppVar_12499 = ROM.rd(cppVar_12498);
	bool cppVar_12501 = (cppVar_12499 == 224);
	if (cppVar_12501) {
	cppVar_12497 = ACC;
	} else {
	BIT_VEC cppVar_12502;
	BIT_VEC cppVar_12503 = PC + 1;
	cppVar_12503 = (cppVar_12503 & cppMask_un_16_);
	BIT_VEC cppVar_12504 = ROM.rd(cppVar_12503);
	bool cppVar_12506 = (cppVar_12504 == 240);
	if (cppVar_12506) {
	cppVar_12502 = B;
	} else {
	cppVar_12502 = 0;
	}
	cppVar_12497 = cppVar_12502;
	}
	cppVar_12492 = cppVar_12497;
	}
	cppVar_12487 = cppVar_12492;
	}
	cppVar_12482 = cppVar_12487;
	}
	cppVar_12477 = cppVar_12482;
	}
	cppVar_12472 = cppVar_12477;
	}
	cppVar_12467 = cppVar_12472;
	}
	cppVar_12462 = cppVar_12467;
	}
	cppVar_12457 = cppVar_12462;
	}
	cppVar_12452 = cppVar_12457;
	}
	cppVar_12447 = cppVar_12452;
	}
	cppVar_12442 = cppVar_12447;
	}
	cppVar_12437 = cppVar_12442;
	}
	cppVar_12432 = cppVar_12437;
	}
	cppVar_12427 = cppVar_12432;
	}
	cppVar_12422 = cppVar_12427;
	}
	cppVar_12417 = cppVar_12422;
	}
	cppVar_12412 = cppVar_12417;
	}
	cppVar_12407 = cppVar_12412;
	}
	cppVar_12402 = cppVar_12407;
	}
	cppVar_12393 = cppVar_12402;
	}
	BIT_VEC cppVar_12509 = cppVar_12393 + 1;
	cppVar_12509 = (cppVar_12509 & cppMask_un_8_);
	cppVar_12387 = cppVar_12509;
	} else {
	cppVar_12387 = DPL;
	}
	cppVar_12383 = cppVar_12387;
	} else {
	BIT_VEC cppVar_12510;
	BIT_VEC cppVar_12511 = ROM.rd(PC);
	bool cppVar_12513 = (cppVar_12511 == 255);
	BIT_VEC cppVar_12514 = ROM.rd(PC);
	bool cppVar_12516 = (cppVar_12514 == 254);
	BIT_VEC cppVar_12517 = ROM.rd(PC);
	bool cppVar_12519 = (cppVar_12517 == 253);
	BIT_VEC cppVar_12520 = ROM.rd(PC);
	bool cppVar_12522 = (cppVar_12520 == 252);
	BIT_VEC cppVar_12523 = ROM.rd(PC);
	bool cppVar_12525 = (cppVar_12523 == 251);
	BIT_VEC cppVar_12526 = ROM.rd(PC);
	bool cppVar_12528 = (cppVar_12526 == 250);
	BIT_VEC cppVar_12529 = ROM.rd(PC);
	bool cppVar_12531 = (cppVar_12529 == 249);
	BIT_VEC cppVar_12532 = ROM.rd(PC);
	bool cppVar_12534 = (cppVar_12532 == 248);
	BIT_VEC cppVar_12535 = ROM.rd(PC);
	bool cppVar_12537 = (cppVar_12535 == 247);
	BIT_VEC cppVar_12538 = ROM.rd(PC);
	bool cppVar_12540 = (cppVar_12538 == 246);
	BIT_VEC cppVar_12541 = ROM.rd(PC);
	bool cppVar_12543 = (cppVar_12541 == 244);
	BIT_VEC cppVar_12544 = ROM.rd(PC);
	bool cppVar_12546 = (cppVar_12544 == 243);
	BIT_VEC cppVar_12547 = ROM.rd(PC);
	bool cppVar_12549 = (cppVar_12547 == 242);
	BIT_VEC cppVar_12550 = ROM.rd(PC);
	bool cppVar_12552 = (cppVar_12550 == 241);
	BIT_VEC cppVar_12553 = ROM.rd(PC);
	bool cppVar_12555 = (cppVar_12553 == 240);
	BIT_VEC cppVar_12556 = ROM.rd(PC);
	bool cppVar_12558 = (cppVar_12556 == 239);
	BIT_VEC cppVar_12559 = ROM.rd(PC);
	bool cppVar_12561 = (cppVar_12559 == 238);
	BIT_VEC cppVar_12562 = ROM.rd(PC);
	bool cppVar_12564 = (cppVar_12562 == 237);
	BIT_VEC cppVar_12565 = ROM.rd(PC);
	bool cppVar_12567 = (cppVar_12565 == 236);
	BIT_VEC cppVar_12568 = ROM.rd(PC);
	bool cppVar_12570 = (cppVar_12568 == 235);
	BIT_VEC cppVar_12571 = ROM.rd(PC);
	bool cppVar_12573 = (cppVar_12571 == 234);
	BIT_VEC cppVar_12574 = ROM.rd(PC);
	bool cppVar_12576 = (cppVar_12574 == 233);
	BIT_VEC cppVar_12577 = ROM.rd(PC);
	bool cppVar_12579 = (cppVar_12577 == 232);
	BIT_VEC cppVar_12580 = ROM.rd(PC);
	bool cppVar_12582 = (cppVar_12580 == 231);
	BIT_VEC cppVar_12583 = ROM.rd(PC);
	bool cppVar_12585 = (cppVar_12583 == 230);
	BIT_VEC cppVar_12586 = ROM.rd(PC);
	bool cppVar_12588 = (cppVar_12586 == 229);
	BIT_VEC cppVar_12589 = ROM.rd(PC);
	bool cppVar_12591 = (cppVar_12589 == 228);
	BIT_VEC cppVar_12592 = ROM.rd(PC);
	bool cppVar_12594 = (cppVar_12592 == 227);
	BIT_VEC cppVar_12595 = ROM.rd(PC);
	bool cppVar_12597 = (cppVar_12595 == 226);
	BIT_VEC cppVar_12598 = ROM.rd(PC);
	bool cppVar_12600 = (cppVar_12598 == 225);
	BIT_VEC cppVar_12601 = ROM.rd(PC);
	bool cppVar_12603 = (cppVar_12601 == 224);
	BIT_VEC cppVar_12604 = ROM.rd(PC);
	bool cppVar_12606 = (cppVar_12604 == 223);
	BIT_VEC cppVar_12607 = ROM.rd(PC);
	bool cppVar_12609 = (cppVar_12607 == 222);
	BIT_VEC cppVar_12610 = ROM.rd(PC);
	bool cppVar_12612 = (cppVar_12610 == 221);
	BIT_VEC cppVar_12613 = ROM.rd(PC);
	bool cppVar_12615 = (cppVar_12613 == 220);
	BIT_VEC cppVar_12616 = ROM.rd(PC);
	bool cppVar_12618 = (cppVar_12616 == 219);
	BIT_VEC cppVar_12619 = ROM.rd(PC);
	bool cppVar_12621 = (cppVar_12619 == 218);
	BIT_VEC cppVar_12622 = ROM.rd(PC);
	bool cppVar_12624 = (cppVar_12622 == 217);
	BIT_VEC cppVar_12625 = ROM.rd(PC);
	bool cppVar_12627 = (cppVar_12625 == 216);
	BIT_VEC cppVar_12628 = ROM.rd(PC);
	bool cppVar_12630 = (cppVar_12628 == 215);
	BIT_VEC cppVar_12631 = ROM.rd(PC);
	bool cppVar_12633 = (cppVar_12631 == 214);
	BIT_VEC cppVar_12634 = ROM.rd(PC);
	bool cppVar_12636 = (cppVar_12634 == 212);
	BIT_VEC cppVar_12637 = ROM.rd(PC);
	bool cppVar_12639 = (cppVar_12637 == 211);
	BIT_VEC cppVar_12640 = ROM.rd(PC);
	bool cppVar_12642 = (cppVar_12640 == 210);
	BIT_VEC cppVar_12643 = ROM.rd(PC);
	bool cppVar_12645 = (cppVar_12643 == 209);
	BIT_VEC cppVar_12646 = ROM.rd(PC);
	bool cppVar_12648 = (cppVar_12646 == 207);
	BIT_VEC cppVar_12649 = ROM.rd(PC);
	bool cppVar_12651 = (cppVar_12649 == 206);
	BIT_VEC cppVar_12652 = ROM.rd(PC);
	bool cppVar_12654 = (cppVar_12652 == 205);
	BIT_VEC cppVar_12655 = ROM.rd(PC);
	bool cppVar_12657 = (cppVar_12655 == 204);
	BIT_VEC cppVar_12658 = ROM.rd(PC);
	bool cppVar_12660 = (cppVar_12658 == 203);
	BIT_VEC cppVar_12661 = ROM.rd(PC);
	bool cppVar_12663 = (cppVar_12661 == 202);
	BIT_VEC cppVar_12664 = ROM.rd(PC);
	bool cppVar_12666 = (cppVar_12664 == 201);
	BIT_VEC cppVar_12667 = ROM.rd(PC);
	bool cppVar_12669 = (cppVar_12667 == 200);
	BIT_VEC cppVar_12670 = ROM.rd(PC);
	bool cppVar_12672 = (cppVar_12670 == 199);
	BIT_VEC cppVar_12673 = ROM.rd(PC);
	bool cppVar_12675 = (cppVar_12673 == 198);
	BIT_VEC cppVar_12676 = ROM.rd(PC);
	bool cppVar_12678 = (cppVar_12676 == 196);
	BIT_VEC cppVar_12679 = ROM.rd(PC);
	bool cppVar_12681 = (cppVar_12679 == 195);
	BIT_VEC cppVar_12682 = ROM.rd(PC);
	bool cppVar_12684 = (cppVar_12682 == 194);
	BIT_VEC cppVar_12685 = ROM.rd(PC);
	bool cppVar_12687 = (cppVar_12685 == 193);
	BIT_VEC cppVar_12688 = ROM.rd(PC);
	bool cppVar_12690 = (cppVar_12688 == 192);
	BIT_VEC cppVar_12691 = ROM.rd(PC);
	bool cppVar_12693 = (cppVar_12691 == 191);
	BIT_VEC cppVar_12694 = ROM.rd(PC);
	bool cppVar_12696 = (cppVar_12694 == 190);
	BIT_VEC cppVar_12697 = ROM.rd(PC);
	bool cppVar_12699 = (cppVar_12697 == 189);
	BIT_VEC cppVar_12700 = ROM.rd(PC);
	bool cppVar_12702 = (cppVar_12700 == 188);
	BIT_VEC cppVar_12703 = ROM.rd(PC);
	bool cppVar_12705 = (cppVar_12703 == 187);
	BIT_VEC cppVar_12706 = ROM.rd(PC);
	bool cppVar_12708 = (cppVar_12706 == 186);
	BIT_VEC cppVar_12709 = ROM.rd(PC);
	bool cppVar_12711 = (cppVar_12709 == 185);
	BIT_VEC cppVar_12712 = ROM.rd(PC);
	bool cppVar_12714 = (cppVar_12712 == 184);
	BIT_VEC cppVar_12715 = ROM.rd(PC);
	bool cppVar_12717 = (cppVar_12715 == 183);
	BIT_VEC cppVar_12718 = ROM.rd(PC);
	bool cppVar_12720 = (cppVar_12718 == 182);
	BIT_VEC cppVar_12721 = ROM.rd(PC);
	bool cppVar_12723 = (cppVar_12721 == 181);
	BIT_VEC cppVar_12724 = ROM.rd(PC);
	bool cppVar_12726 = (cppVar_12724 == 180);
	BIT_VEC cppVar_12727 = ROM.rd(PC);
	bool cppVar_12729 = (cppVar_12727 == 179);
	BIT_VEC cppVar_12730 = ROM.rd(PC);
	bool cppVar_12732 = (cppVar_12730 == 178);
	BIT_VEC cppVar_12733 = ROM.rd(PC);
	bool cppVar_12735 = (cppVar_12733 == 177);
	BIT_VEC cppVar_12736 = ROM.rd(PC);
	bool cppVar_12738 = (cppVar_12736 == 176);
	BIT_VEC cppVar_12739 = ROM.rd(PC);
	bool cppVar_12741 = (cppVar_12739 == 175);
	BIT_VEC cppVar_12742 = ROM.rd(PC);
	bool cppVar_12744 = (cppVar_12742 == 174);
	BIT_VEC cppVar_12745 = ROM.rd(PC);
	bool cppVar_12747 = (cppVar_12745 == 173);
	BIT_VEC cppVar_12748 = ROM.rd(PC);
	bool cppVar_12750 = (cppVar_12748 == 172);
	BIT_VEC cppVar_12751 = ROM.rd(PC);
	bool cppVar_12753 = (cppVar_12751 == 171);
	BIT_VEC cppVar_12754 = ROM.rd(PC);
	bool cppVar_12756 = (cppVar_12754 == 170);
	BIT_VEC cppVar_12757 = ROM.rd(PC);
	bool cppVar_12759 = (cppVar_12757 == 169);
	BIT_VEC cppVar_12760 = ROM.rd(PC);
	bool cppVar_12762 = (cppVar_12760 == 168);
	BIT_VEC cppVar_12763 = ROM.rd(PC);
	bool cppVar_12765 = (cppVar_12763 == 167);
	BIT_VEC cppVar_12766 = ROM.rd(PC);
	bool cppVar_12768 = (cppVar_12766 == 166);
	BIT_VEC cppVar_12769 = ROM.rd(PC);
	bool cppVar_12771 = (cppVar_12769 == 165);
	BIT_VEC cppVar_12772 = ROM.rd(PC);
	bool cppVar_12774 = (cppVar_12772 == 164);
	BIT_VEC cppVar_12775 = ROM.rd(PC);
	bool cppVar_12777 = (cppVar_12775 == 162);
	BIT_VEC cppVar_12778 = ROM.rd(PC);
	bool cppVar_12780 = (cppVar_12778 == 161);
	BIT_VEC cppVar_12781 = ROM.rd(PC);
	bool cppVar_12783 = (cppVar_12781 == 160);
	BIT_VEC cppVar_12784 = ROM.rd(PC);
	bool cppVar_12786 = (cppVar_12784 == 159);
	BIT_VEC cppVar_12787 = ROM.rd(PC);
	bool cppVar_12789 = (cppVar_12787 == 158);
	BIT_VEC cppVar_12790 = ROM.rd(PC);
	bool cppVar_12792 = (cppVar_12790 == 157);
	BIT_VEC cppVar_12793 = ROM.rd(PC);
	bool cppVar_12795 = (cppVar_12793 == 156);
	BIT_VEC cppVar_12796 = ROM.rd(PC);
	bool cppVar_12798 = (cppVar_12796 == 155);
	BIT_VEC cppVar_12799 = ROM.rd(PC);
	bool cppVar_12801 = (cppVar_12799 == 154);
	BIT_VEC cppVar_12802 = ROM.rd(PC);
	bool cppVar_12804 = (cppVar_12802 == 153);
	BIT_VEC cppVar_12805 = ROM.rd(PC);
	bool cppVar_12807 = (cppVar_12805 == 152);
	BIT_VEC cppVar_12808 = ROM.rd(PC);
	bool cppVar_12810 = (cppVar_12808 == 151);
	BIT_VEC cppVar_12811 = ROM.rd(PC);
	bool cppVar_12813 = (cppVar_12811 == 150);
	BIT_VEC cppVar_12814 = ROM.rd(PC);
	bool cppVar_12816 = (cppVar_12814 == 149);
	BIT_VEC cppVar_12817 = ROM.rd(PC);
	bool cppVar_12819 = (cppVar_12817 == 148);
	BIT_VEC cppVar_12820 = ROM.rd(PC);
	bool cppVar_12822 = (cppVar_12820 == 147);
	BIT_VEC cppVar_12823 = ROM.rd(PC);
	bool cppVar_12825 = (cppVar_12823 == 146);
	BIT_VEC cppVar_12826 = ROM.rd(PC);
	bool cppVar_12828 = (cppVar_12826 == 145);
	BIT_VEC cppVar_12829 = ROM.rd(PC);
	bool cppVar_12831 = (cppVar_12829 == 132);
	BIT_VEC cppVar_12832 = ROM.rd(PC);
	bool cppVar_12834 = (cppVar_12832 == 131);
	BIT_VEC cppVar_12835 = ROM.rd(PC);
	bool cppVar_12837 = (cppVar_12835 == 130);
	BIT_VEC cppVar_12838 = ROM.rd(PC);
	bool cppVar_12840 = (cppVar_12838 == 129);
	BIT_VEC cppVar_12841 = ROM.rd(PC);
	bool cppVar_12843 = (cppVar_12841 == 128);
	BIT_VEC cppVar_12844 = ROM.rd(PC);
	bool cppVar_12846 = (cppVar_12844 == 127);
	BIT_VEC cppVar_12847 = ROM.rd(PC);
	bool cppVar_12849 = (cppVar_12847 == 126);
	BIT_VEC cppVar_12850 = ROM.rd(PC);
	bool cppVar_12852 = (cppVar_12850 == 125);
	BIT_VEC cppVar_12853 = ROM.rd(PC);
	bool cppVar_12855 = (cppVar_12853 == 124);
	BIT_VEC cppVar_12856 = ROM.rd(PC);
	bool cppVar_12858 = (cppVar_12856 == 123);
	BIT_VEC cppVar_12859 = ROM.rd(PC);
	bool cppVar_12861 = (cppVar_12859 == 122);
	BIT_VEC cppVar_12862 = ROM.rd(PC);
	bool cppVar_12864 = (cppVar_12862 == 121);
	BIT_VEC cppVar_12865 = ROM.rd(PC);
	bool cppVar_12867 = (cppVar_12865 == 120);
	BIT_VEC cppVar_12868 = ROM.rd(PC);
	bool cppVar_12870 = (cppVar_12868 == 119);
	BIT_VEC cppVar_12871 = ROM.rd(PC);
	bool cppVar_12873 = (cppVar_12871 == 118);
	BIT_VEC cppVar_12874 = ROM.rd(PC);
	bool cppVar_12876 = (cppVar_12874 == 116);
	BIT_VEC cppVar_12877 = ROM.rd(PC);
	bool cppVar_12879 = (cppVar_12877 == 115);
	BIT_VEC cppVar_12880 = ROM.rd(PC);
	bool cppVar_12882 = (cppVar_12880 == 114);
	BIT_VEC cppVar_12883 = ROM.rd(PC);
	bool cppVar_12885 = (cppVar_12883 == 113);
	BIT_VEC cppVar_12886 = ROM.rd(PC);
	bool cppVar_12888 = (cppVar_12886 == 112);
	BIT_VEC cppVar_12889 = ROM.rd(PC);
	bool cppVar_12891 = (cppVar_12889 == 111);
	BIT_VEC cppVar_12892 = ROM.rd(PC);
	bool cppVar_12894 = (cppVar_12892 == 110);
	BIT_VEC cppVar_12895 = ROM.rd(PC);
	bool cppVar_12897 = (cppVar_12895 == 109);
	BIT_VEC cppVar_12898 = ROM.rd(PC);
	bool cppVar_12900 = (cppVar_12898 == 108);
	BIT_VEC cppVar_12901 = ROM.rd(PC);
	bool cppVar_12903 = (cppVar_12901 == 107);
	BIT_VEC cppVar_12904 = ROM.rd(PC);
	bool cppVar_12906 = (cppVar_12904 == 106);
	BIT_VEC cppVar_12907 = ROM.rd(PC);
	bool cppVar_12909 = (cppVar_12907 == 105);
	BIT_VEC cppVar_12910 = ROM.rd(PC);
	bool cppVar_12912 = (cppVar_12910 == 104);
	BIT_VEC cppVar_12913 = ROM.rd(PC);
	bool cppVar_12915 = (cppVar_12913 == 103);
	BIT_VEC cppVar_12916 = ROM.rd(PC);
	bool cppVar_12918 = (cppVar_12916 == 102);
	BIT_VEC cppVar_12919 = ROM.rd(PC);
	bool cppVar_12921 = (cppVar_12919 == 101);
	BIT_VEC cppVar_12922 = ROM.rd(PC);
	bool cppVar_12924 = (cppVar_12922 == 100);
	BIT_VEC cppVar_12925 = ROM.rd(PC);
	bool cppVar_12927 = (cppVar_12925 == 97);
	BIT_VEC cppVar_12928 = ROM.rd(PC);
	bool cppVar_12930 = (cppVar_12928 == 96);
	BIT_VEC cppVar_12931 = ROM.rd(PC);
	bool cppVar_12933 = (cppVar_12931 == 95);
	BIT_VEC cppVar_12934 = ROM.rd(PC);
	bool cppVar_12936 = (cppVar_12934 == 94);
	BIT_VEC cppVar_12937 = ROM.rd(PC);
	bool cppVar_12939 = (cppVar_12937 == 93);
	BIT_VEC cppVar_12940 = ROM.rd(PC);
	bool cppVar_12942 = (cppVar_12940 == 92);
	BIT_VEC cppVar_12943 = ROM.rd(PC);
	bool cppVar_12945 = (cppVar_12943 == 91);
	BIT_VEC cppVar_12946 = ROM.rd(PC);
	bool cppVar_12948 = (cppVar_12946 == 90);
	BIT_VEC cppVar_12949 = ROM.rd(PC);
	bool cppVar_12951 = (cppVar_12949 == 89);
	BIT_VEC cppVar_12952 = ROM.rd(PC);
	bool cppVar_12954 = (cppVar_12952 == 88);
	BIT_VEC cppVar_12955 = ROM.rd(PC);
	bool cppVar_12957 = (cppVar_12955 == 87);
	BIT_VEC cppVar_12958 = ROM.rd(PC);
	bool cppVar_12960 = (cppVar_12958 == 86);
	BIT_VEC cppVar_12961 = ROM.rd(PC);
	bool cppVar_12963 = (cppVar_12961 == 85);
	BIT_VEC cppVar_12964 = ROM.rd(PC);
	bool cppVar_12966 = (cppVar_12964 == 84);
	BIT_VEC cppVar_12967 = ROM.rd(PC);
	bool cppVar_12969 = (cppVar_12967 == 81);
	BIT_VEC cppVar_12970 = ROM.rd(PC);
	bool cppVar_12972 = (cppVar_12970 == 80);
	BIT_VEC cppVar_12973 = ROM.rd(PC);
	bool cppVar_12975 = (cppVar_12973 == 79);
	BIT_VEC cppVar_12976 = ROM.rd(PC);
	bool cppVar_12978 = (cppVar_12976 == 78);
	BIT_VEC cppVar_12979 = ROM.rd(PC);
	bool cppVar_12981 = (cppVar_12979 == 77);
	BIT_VEC cppVar_12982 = ROM.rd(PC);
	bool cppVar_12984 = (cppVar_12982 == 76);
	BIT_VEC cppVar_12985 = ROM.rd(PC);
	bool cppVar_12987 = (cppVar_12985 == 75);
	BIT_VEC cppVar_12988 = ROM.rd(PC);
	bool cppVar_12990 = (cppVar_12988 == 74);
	BIT_VEC cppVar_12991 = ROM.rd(PC);
	bool cppVar_12993 = (cppVar_12991 == 73);
	BIT_VEC cppVar_12994 = ROM.rd(PC);
	bool cppVar_12996 = (cppVar_12994 == 72);
	BIT_VEC cppVar_12997 = ROM.rd(PC);
	bool cppVar_12999 = (cppVar_12997 == 71);
	BIT_VEC cppVar_13000 = ROM.rd(PC);
	bool cppVar_13002 = (cppVar_13000 == 70);
	BIT_VEC cppVar_13003 = ROM.rd(PC);
	bool cppVar_13005 = (cppVar_13003 == 69);
	BIT_VEC cppVar_13006 = ROM.rd(PC);
	bool cppVar_13008 = (cppVar_13006 == 68);
	BIT_VEC cppVar_13009 = ROM.rd(PC);
	bool cppVar_13011 = (cppVar_13009 == 65);
	BIT_VEC cppVar_13012 = ROM.rd(PC);
	bool cppVar_13014 = (cppVar_13012 == 64);
	BIT_VEC cppVar_13015 = ROM.rd(PC);
	bool cppVar_13017 = (cppVar_13015 == 63);
	BIT_VEC cppVar_13018 = ROM.rd(PC);
	bool cppVar_13020 = (cppVar_13018 == 62);
	BIT_VEC cppVar_13021 = ROM.rd(PC);
	bool cppVar_13023 = (cppVar_13021 == 61);
	BIT_VEC cppVar_13024 = ROM.rd(PC);
	bool cppVar_13026 = (cppVar_13024 == 60);
	BIT_VEC cppVar_13027 = ROM.rd(PC);
	bool cppVar_13029 = (cppVar_13027 == 59);
	BIT_VEC cppVar_13030 = ROM.rd(PC);
	bool cppVar_13032 = (cppVar_13030 == 58);
	BIT_VEC cppVar_13033 = ROM.rd(PC);
	bool cppVar_13035 = (cppVar_13033 == 57);
	BIT_VEC cppVar_13036 = ROM.rd(PC);
	bool cppVar_13038 = (cppVar_13036 == 56);
	BIT_VEC cppVar_13039 = ROM.rd(PC);
	bool cppVar_13041 = (cppVar_13039 == 55);
	BIT_VEC cppVar_13042 = ROM.rd(PC);
	bool cppVar_13044 = (cppVar_13042 == 54);
	BIT_VEC cppVar_13045 = ROM.rd(PC);
	bool cppVar_13047 = (cppVar_13045 == 53);
	BIT_VEC cppVar_13048 = ROM.rd(PC);
	bool cppVar_13050 = (cppVar_13048 == 52);
	BIT_VEC cppVar_13051 = ROM.rd(PC);
	bool cppVar_13053 = (cppVar_13051 == 51);
	BIT_VEC cppVar_13054 = ROM.rd(PC);
	bool cppVar_13056 = (cppVar_13054 == 50);
	BIT_VEC cppVar_13057 = ROM.rd(PC);
	bool cppVar_13059 = (cppVar_13057 == 49);
	BIT_VEC cppVar_13060 = ROM.rd(PC);
	bool cppVar_13062 = (cppVar_13060 == 48);
	BIT_VEC cppVar_13063 = ROM.rd(PC);
	bool cppVar_13065 = (cppVar_13063 == 47);
	BIT_VEC cppVar_13066 = ROM.rd(PC);
	bool cppVar_13068 = (cppVar_13066 == 46);
	BIT_VEC cppVar_13069 = ROM.rd(PC);
	bool cppVar_13071 = (cppVar_13069 == 45);
	BIT_VEC cppVar_13072 = ROM.rd(PC);
	bool cppVar_13074 = (cppVar_13072 == 44);
	BIT_VEC cppVar_13075 = ROM.rd(PC);
	bool cppVar_13077 = (cppVar_13075 == 43);
	BIT_VEC cppVar_13078 = ROM.rd(PC);
	bool cppVar_13080 = (cppVar_13078 == 42);
	BIT_VEC cppVar_13081 = ROM.rd(PC);
	bool cppVar_13083 = (cppVar_13081 == 41);
	BIT_VEC cppVar_13084 = ROM.rd(PC);
	bool cppVar_13086 = (cppVar_13084 == 40);
	BIT_VEC cppVar_13087 = ROM.rd(PC);
	bool cppVar_13089 = (cppVar_13087 == 39);
	BIT_VEC cppVar_13090 = ROM.rd(PC);
	bool cppVar_13092 = (cppVar_13090 == 38);
	BIT_VEC cppVar_13093 = ROM.rd(PC);
	bool cppVar_13095 = (cppVar_13093 == 37);
	BIT_VEC cppVar_13096 = ROM.rd(PC);
	bool cppVar_13098 = (cppVar_13096 == 36);
	BIT_VEC cppVar_13099 = ROM.rd(PC);
	bool cppVar_13101 = (cppVar_13099 == 35);
	BIT_VEC cppVar_13102 = ROM.rd(PC);
	bool cppVar_13104 = (cppVar_13102 == 34);
	BIT_VEC cppVar_13105 = ROM.rd(PC);
	bool cppVar_13107 = (cppVar_13105 == 33);
	BIT_VEC cppVar_13108 = ROM.rd(PC);
	bool cppVar_13110 = (cppVar_13108 == 32);
	BIT_VEC cppVar_13111 = ROM.rd(PC);
	bool cppVar_13113 = (cppVar_13111 == 31);
	BIT_VEC cppVar_13114 = ROM.rd(PC);
	bool cppVar_13116 = (cppVar_13114 == 30);
	BIT_VEC cppVar_13117 = ROM.rd(PC);
	bool cppVar_13119 = (cppVar_13117 == 29);
	BIT_VEC cppVar_13120 = ROM.rd(PC);
	bool cppVar_13122 = (cppVar_13120 == 28);
	BIT_VEC cppVar_13123 = ROM.rd(PC);
	bool cppVar_13125 = (cppVar_13123 == 27);
	BIT_VEC cppVar_13126 = ROM.rd(PC);
	bool cppVar_13128 = (cppVar_13126 == 26);
	BIT_VEC cppVar_13129 = ROM.rd(PC);
	bool cppVar_13131 = (cppVar_13129 == 25);
	BIT_VEC cppVar_13132 = ROM.rd(PC);
	bool cppVar_13134 = (cppVar_13132 == 24);
	BIT_VEC cppVar_13135 = ROM.rd(PC);
	bool cppVar_13137 = (cppVar_13135 == 23);
	BIT_VEC cppVar_13138 = ROM.rd(PC);
	bool cppVar_13140 = (cppVar_13138 == 22);
	BIT_VEC cppVar_13141 = ROM.rd(PC);
	bool cppVar_13143 = (cppVar_13141 == 20);
	BIT_VEC cppVar_13144 = ROM.rd(PC);
	bool cppVar_13146 = (cppVar_13144 == 19);
	BIT_VEC cppVar_13147 = ROM.rd(PC);
	bool cppVar_13149 = (cppVar_13147 == 18);
	BIT_VEC cppVar_13150 = ROM.rd(PC);
	bool cppVar_13152 = (cppVar_13150 == 17);
	BIT_VEC cppVar_13153 = ROM.rd(PC);
	bool cppVar_13155 = (cppVar_13153 == 16);
	BIT_VEC cppVar_13156 = ROM.rd(PC);
	bool cppVar_13158 = (cppVar_13156 == 15);
	BIT_VEC cppVar_13159 = ROM.rd(PC);
	bool cppVar_13161 = (cppVar_13159 == 14);
	BIT_VEC cppVar_13162 = ROM.rd(PC);
	bool cppVar_13164 = (cppVar_13162 == 13);
	BIT_VEC cppVar_13165 = ROM.rd(PC);
	bool cppVar_13167 = (cppVar_13165 == 12);
	BIT_VEC cppVar_13168 = ROM.rd(PC);
	bool cppVar_13170 = (cppVar_13168 == 11);
	BIT_VEC cppVar_13171 = ROM.rd(PC);
	bool cppVar_13173 = (cppVar_13171 == 10);
	BIT_VEC cppVar_13174 = ROM.rd(PC);
	bool cppVar_13176 = (cppVar_13174 == 9);
	BIT_VEC cppVar_13177 = ROM.rd(PC);
	bool cppVar_13179 = (cppVar_13177 == 8);
	BIT_VEC cppVar_13180 = ROM.rd(PC);
	bool cppVar_13182 = (cppVar_13180 == 7);
	BIT_VEC cppVar_13183 = ROM.rd(PC);
	bool cppVar_13185 = (cppVar_13183 == 6);
	BIT_VEC cppVar_13186 = ROM.rd(PC);
	bool cppVar_13188 = (cppVar_13186 == 4);
	BIT_VEC cppVar_13189 = ROM.rd(PC);
	bool cppVar_13191 = (cppVar_13189 == 3);
	BIT_VEC cppVar_13192 = ROM.rd(PC);
	bool cppVar_13194 = (cppVar_13192 == 2);
	BIT_VEC cppVar_13195 = ROM.rd(PC);
	bool cppVar_13197 = (cppVar_13195 == 1);
	BIT_VEC cppVar_13198 = ROM.rd(PC);
	bool cppVar_13200 = (cppVar_13198 == 0);
	bool cppVar_13201 = cppVar_13197 || cppVar_13200;
	bool cppVar_13202 = cppVar_13194 || cppVar_13201;
	bool cppVar_13203 = cppVar_13191 || cppVar_13202;
	bool cppVar_13204 = cppVar_13188 || cppVar_13203;
	bool cppVar_13205 = cppVar_13185 || cppVar_13204;
	bool cppVar_13206 = cppVar_13182 || cppVar_13205;
	bool cppVar_13207 = cppVar_13179 || cppVar_13206;
	bool cppVar_13208 = cppVar_13176 || cppVar_13207;
	bool cppVar_13209 = cppVar_13173 || cppVar_13208;
	bool cppVar_13210 = cppVar_13170 || cppVar_13209;
	bool cppVar_13211 = cppVar_13167 || cppVar_13210;
	bool cppVar_13212 = cppVar_13164 || cppVar_13211;
	bool cppVar_13213 = cppVar_13161 || cppVar_13212;
	bool cppVar_13214 = cppVar_13158 || cppVar_13213;
	bool cppVar_13215 = cppVar_13155 || cppVar_13214;
	bool cppVar_13216 = cppVar_13152 || cppVar_13215;
	bool cppVar_13217 = cppVar_13149 || cppVar_13216;
	bool cppVar_13218 = cppVar_13146 || cppVar_13217;
	bool cppVar_13219 = cppVar_13143 || cppVar_13218;
	bool cppVar_13220 = cppVar_13140 || cppVar_13219;
	bool cppVar_13221 = cppVar_13137 || cppVar_13220;
	bool cppVar_13222 = cppVar_13134 || cppVar_13221;
	bool cppVar_13223 = cppVar_13131 || cppVar_13222;
	bool cppVar_13224 = cppVar_13128 || cppVar_13223;
	bool cppVar_13225 = cppVar_13125 || cppVar_13224;
	bool cppVar_13226 = cppVar_13122 || cppVar_13225;
	bool cppVar_13227 = cppVar_13119 || cppVar_13226;
	bool cppVar_13228 = cppVar_13116 || cppVar_13227;
	bool cppVar_13229 = cppVar_13113 || cppVar_13228;
	bool cppVar_13230 = cppVar_13110 || cppVar_13229;
	bool cppVar_13231 = cppVar_13107 || cppVar_13230;
	bool cppVar_13232 = cppVar_13104 || cppVar_13231;
	bool cppVar_13233 = cppVar_13101 || cppVar_13232;
	bool cppVar_13234 = cppVar_13098 || cppVar_13233;
	bool cppVar_13235 = cppVar_13095 || cppVar_13234;
	bool cppVar_13236 = cppVar_13092 || cppVar_13235;
	bool cppVar_13237 = cppVar_13089 || cppVar_13236;
	bool cppVar_13238 = cppVar_13086 || cppVar_13237;
	bool cppVar_13239 = cppVar_13083 || cppVar_13238;
	bool cppVar_13240 = cppVar_13080 || cppVar_13239;
	bool cppVar_13241 = cppVar_13077 || cppVar_13240;
	bool cppVar_13242 = cppVar_13074 || cppVar_13241;
	bool cppVar_13243 = cppVar_13071 || cppVar_13242;
	bool cppVar_13244 = cppVar_13068 || cppVar_13243;
	bool cppVar_13245 = cppVar_13065 || cppVar_13244;
	bool cppVar_13246 = cppVar_13062 || cppVar_13245;
	bool cppVar_13247 = cppVar_13059 || cppVar_13246;
	bool cppVar_13248 = cppVar_13056 || cppVar_13247;
	bool cppVar_13249 = cppVar_13053 || cppVar_13248;
	bool cppVar_13250 = cppVar_13050 || cppVar_13249;
	bool cppVar_13251 = cppVar_13047 || cppVar_13250;
	bool cppVar_13252 = cppVar_13044 || cppVar_13251;
	bool cppVar_13253 = cppVar_13041 || cppVar_13252;
	bool cppVar_13254 = cppVar_13038 || cppVar_13253;
	bool cppVar_13255 = cppVar_13035 || cppVar_13254;
	bool cppVar_13256 = cppVar_13032 || cppVar_13255;
	bool cppVar_13257 = cppVar_13029 || cppVar_13256;
	bool cppVar_13258 = cppVar_13026 || cppVar_13257;
	bool cppVar_13259 = cppVar_13023 || cppVar_13258;
	bool cppVar_13260 = cppVar_13020 || cppVar_13259;
	bool cppVar_13261 = cppVar_13017 || cppVar_13260;
	bool cppVar_13262 = cppVar_13014 || cppVar_13261;
	bool cppVar_13263 = cppVar_13011 || cppVar_13262;
	bool cppVar_13264 = cppVar_13008 || cppVar_13263;
	bool cppVar_13265 = cppVar_13005 || cppVar_13264;
	bool cppVar_13266 = cppVar_13002 || cppVar_13265;
	bool cppVar_13267 = cppVar_12999 || cppVar_13266;
	bool cppVar_13268 = cppVar_12996 || cppVar_13267;
	bool cppVar_13269 = cppVar_12993 || cppVar_13268;
	bool cppVar_13270 = cppVar_12990 || cppVar_13269;
	bool cppVar_13271 = cppVar_12987 || cppVar_13270;
	bool cppVar_13272 = cppVar_12984 || cppVar_13271;
	bool cppVar_13273 = cppVar_12981 || cppVar_13272;
	bool cppVar_13274 = cppVar_12978 || cppVar_13273;
	bool cppVar_13275 = cppVar_12975 || cppVar_13274;
	bool cppVar_13276 = cppVar_12972 || cppVar_13275;
	bool cppVar_13277 = cppVar_12969 || cppVar_13276;
	bool cppVar_13278 = cppVar_12966 || cppVar_13277;
	bool cppVar_13279 = cppVar_12963 || cppVar_13278;
	bool cppVar_13280 = cppVar_12960 || cppVar_13279;
	bool cppVar_13281 = cppVar_12957 || cppVar_13280;
	bool cppVar_13282 = cppVar_12954 || cppVar_13281;
	bool cppVar_13283 = cppVar_12951 || cppVar_13282;
	bool cppVar_13284 = cppVar_12948 || cppVar_13283;
	bool cppVar_13285 = cppVar_12945 || cppVar_13284;
	bool cppVar_13286 = cppVar_12942 || cppVar_13285;
	bool cppVar_13287 = cppVar_12939 || cppVar_13286;
	bool cppVar_13288 = cppVar_12936 || cppVar_13287;
	bool cppVar_13289 = cppVar_12933 || cppVar_13288;
	bool cppVar_13290 = cppVar_12930 || cppVar_13289;
	bool cppVar_13291 = cppVar_12927 || cppVar_13290;
	bool cppVar_13292 = cppVar_12924 || cppVar_13291;
	bool cppVar_13293 = cppVar_12921 || cppVar_13292;
	bool cppVar_13294 = cppVar_12918 || cppVar_13293;
	bool cppVar_13295 = cppVar_12915 || cppVar_13294;
	bool cppVar_13296 = cppVar_12912 || cppVar_13295;
	bool cppVar_13297 = cppVar_12909 || cppVar_13296;
	bool cppVar_13298 = cppVar_12906 || cppVar_13297;
	bool cppVar_13299 = cppVar_12903 || cppVar_13298;
	bool cppVar_13300 = cppVar_12900 || cppVar_13299;
	bool cppVar_13301 = cppVar_12897 || cppVar_13300;
	bool cppVar_13302 = cppVar_12894 || cppVar_13301;
	bool cppVar_13303 = cppVar_12891 || cppVar_13302;
	bool cppVar_13304 = cppVar_12888 || cppVar_13303;
	bool cppVar_13305 = cppVar_12885 || cppVar_13304;
	bool cppVar_13306 = cppVar_12882 || cppVar_13305;
	bool cppVar_13307 = cppVar_12879 || cppVar_13306;
	bool cppVar_13308 = cppVar_12876 || cppVar_13307;
	bool cppVar_13309 = cppVar_12873 || cppVar_13308;
	bool cppVar_13310 = cppVar_12870 || cppVar_13309;
	bool cppVar_13311 = cppVar_12867 || cppVar_13310;
	bool cppVar_13312 = cppVar_12864 || cppVar_13311;
	bool cppVar_13313 = cppVar_12861 || cppVar_13312;
	bool cppVar_13314 = cppVar_12858 || cppVar_13313;
	bool cppVar_13315 = cppVar_12855 || cppVar_13314;
	bool cppVar_13316 = cppVar_12852 || cppVar_13315;
	bool cppVar_13317 = cppVar_12849 || cppVar_13316;
	bool cppVar_13318 = cppVar_12846 || cppVar_13317;
	bool cppVar_13319 = cppVar_12843 || cppVar_13318;
	bool cppVar_13320 = cppVar_12840 || cppVar_13319;
	bool cppVar_13321 = cppVar_12837 || cppVar_13320;
	bool cppVar_13322 = cppVar_12834 || cppVar_13321;
	bool cppVar_13323 = cppVar_12831 || cppVar_13322;
	bool cppVar_13324 = cppVar_12828 || cppVar_13323;
	bool cppVar_13325 = cppVar_12825 || cppVar_13324;
	bool cppVar_13326 = cppVar_12822 || cppVar_13325;
	bool cppVar_13327 = cppVar_12819 || cppVar_13326;
	bool cppVar_13328 = cppVar_12816 || cppVar_13327;
	bool cppVar_13329 = cppVar_12813 || cppVar_13328;
	bool cppVar_13330 = cppVar_12810 || cppVar_13329;
	bool cppVar_13331 = cppVar_12807 || cppVar_13330;
	bool cppVar_13332 = cppVar_12804 || cppVar_13331;
	bool cppVar_13333 = cppVar_12801 || cppVar_13332;
	bool cppVar_13334 = cppVar_12798 || cppVar_13333;
	bool cppVar_13335 = cppVar_12795 || cppVar_13334;
	bool cppVar_13336 = cppVar_12792 || cppVar_13335;
	bool cppVar_13337 = cppVar_12789 || cppVar_13336;
	bool cppVar_13338 = cppVar_12786 || cppVar_13337;
	bool cppVar_13339 = cppVar_12783 || cppVar_13338;
	bool cppVar_13340 = cppVar_12780 || cppVar_13339;
	bool cppVar_13341 = cppVar_12777 || cppVar_13340;
	bool cppVar_13342 = cppVar_12774 || cppVar_13341;
	bool cppVar_13343 = cppVar_12771 || cppVar_13342;
	bool cppVar_13344 = cppVar_12768 || cppVar_13343;
	bool cppVar_13345 = cppVar_12765 || cppVar_13344;
	bool cppVar_13346 = cppVar_12762 || cppVar_13345;
	bool cppVar_13347 = cppVar_12759 || cppVar_13346;
	bool cppVar_13348 = cppVar_12756 || cppVar_13347;
	bool cppVar_13349 = cppVar_12753 || cppVar_13348;
	bool cppVar_13350 = cppVar_12750 || cppVar_13349;
	bool cppVar_13351 = cppVar_12747 || cppVar_13350;
	bool cppVar_13352 = cppVar_12744 || cppVar_13351;
	bool cppVar_13353 = cppVar_12741 || cppVar_13352;
	bool cppVar_13354 = cppVar_12738 || cppVar_13353;
	bool cppVar_13355 = cppVar_12735 || cppVar_13354;
	bool cppVar_13356 = cppVar_12732 || cppVar_13355;
	bool cppVar_13357 = cppVar_12729 || cppVar_13356;
	bool cppVar_13358 = cppVar_12726 || cppVar_13357;
	bool cppVar_13359 = cppVar_12723 || cppVar_13358;
	bool cppVar_13360 = cppVar_12720 || cppVar_13359;
	bool cppVar_13361 = cppVar_12717 || cppVar_13360;
	bool cppVar_13362 = cppVar_12714 || cppVar_13361;
	bool cppVar_13363 = cppVar_12711 || cppVar_13362;
	bool cppVar_13364 = cppVar_12708 || cppVar_13363;
	bool cppVar_13365 = cppVar_12705 || cppVar_13364;
	bool cppVar_13366 = cppVar_12702 || cppVar_13365;
	bool cppVar_13367 = cppVar_12699 || cppVar_13366;
	bool cppVar_13368 = cppVar_12696 || cppVar_13367;
	bool cppVar_13369 = cppVar_12693 || cppVar_13368;
	bool cppVar_13370 = cppVar_12690 || cppVar_13369;
	bool cppVar_13371 = cppVar_12687 || cppVar_13370;
	bool cppVar_13372 = cppVar_12684 || cppVar_13371;
	bool cppVar_13373 = cppVar_12681 || cppVar_13372;
	bool cppVar_13374 = cppVar_12678 || cppVar_13373;
	bool cppVar_13375 = cppVar_12675 || cppVar_13374;
	bool cppVar_13376 = cppVar_12672 || cppVar_13375;
	bool cppVar_13377 = cppVar_12669 || cppVar_13376;
	bool cppVar_13378 = cppVar_12666 || cppVar_13377;
	bool cppVar_13379 = cppVar_12663 || cppVar_13378;
	bool cppVar_13380 = cppVar_12660 || cppVar_13379;
	bool cppVar_13381 = cppVar_12657 || cppVar_13380;
	bool cppVar_13382 = cppVar_12654 || cppVar_13381;
	bool cppVar_13383 = cppVar_12651 || cppVar_13382;
	bool cppVar_13384 = cppVar_12648 || cppVar_13383;
	bool cppVar_13385 = cppVar_12645 || cppVar_13384;
	bool cppVar_13386 = cppVar_12642 || cppVar_13385;
	bool cppVar_13387 = cppVar_12639 || cppVar_13386;
	bool cppVar_13388 = cppVar_12636 || cppVar_13387;
	bool cppVar_13389 = cppVar_12633 || cppVar_13388;
	bool cppVar_13390 = cppVar_12630 || cppVar_13389;
	bool cppVar_13391 = cppVar_12627 || cppVar_13390;
	bool cppVar_13392 = cppVar_12624 || cppVar_13391;
	bool cppVar_13393 = cppVar_12621 || cppVar_13392;
	bool cppVar_13394 = cppVar_12618 || cppVar_13393;
	bool cppVar_13395 = cppVar_12615 || cppVar_13394;
	bool cppVar_13396 = cppVar_12612 || cppVar_13395;
	bool cppVar_13397 = cppVar_12609 || cppVar_13396;
	bool cppVar_13398 = cppVar_12606 || cppVar_13397;
	bool cppVar_13399 = cppVar_12603 || cppVar_13398;
	bool cppVar_13400 = cppVar_12600 || cppVar_13399;
	bool cppVar_13401 = cppVar_12597 || cppVar_13400;
	bool cppVar_13402 = cppVar_12594 || cppVar_13401;
	bool cppVar_13403 = cppVar_12591 || cppVar_13402;
	bool cppVar_13404 = cppVar_12588 || cppVar_13403;
	bool cppVar_13405 = cppVar_12585 || cppVar_13404;
	bool cppVar_13406 = cppVar_12582 || cppVar_13405;
	bool cppVar_13407 = cppVar_12579 || cppVar_13406;
	bool cppVar_13408 = cppVar_12576 || cppVar_13407;
	bool cppVar_13409 = cppVar_12573 || cppVar_13408;
	bool cppVar_13410 = cppVar_12570 || cppVar_13409;
	bool cppVar_13411 = cppVar_12567 || cppVar_13410;
	bool cppVar_13412 = cppVar_12564 || cppVar_13411;
	bool cppVar_13413 = cppVar_12561 || cppVar_13412;
	bool cppVar_13414 = cppVar_12558 || cppVar_13413;
	bool cppVar_13415 = cppVar_12555 || cppVar_13414;
	bool cppVar_13416 = cppVar_12552 || cppVar_13415;
	bool cppVar_13417 = cppVar_12549 || cppVar_13416;
	bool cppVar_13418 = cppVar_12546 || cppVar_13417;
	bool cppVar_13419 = cppVar_12543 || cppVar_13418;
	bool cppVar_13420 = cppVar_12540 || cppVar_13419;
	bool cppVar_13421 = cppVar_12537 || cppVar_13420;
	bool cppVar_13422 = cppVar_12534 || cppVar_13421;
	bool cppVar_13423 = cppVar_12531 || cppVar_13422;
	bool cppVar_13424 = cppVar_12528 || cppVar_13423;
	bool cppVar_13425 = cppVar_12525 || cppVar_13424;
	bool cppVar_13426 = cppVar_12522 || cppVar_13425;
	bool cppVar_13427 = cppVar_12519 || cppVar_13426;
	bool cppVar_13428 = cppVar_12516 || cppVar_13427;
	bool cppVar_13429 = cppVar_12513 || cppVar_13428;
	if (cppVar_13429) {
	BIT_VEC cppVar_13430 = (DPH << 8) | DPL;
	cppVar_13430 = (cppVar_13430 & cppMask_un_16_);
	BIT_VEC cppVar_13431 = (cppVar_13430 >> 0) & cppMask_un_8_;
	cppVar_12510 = cppVar_13431;
	} else {
	cppVar_12510 = DPL;
	}
	cppVar_12383 = cppVar_12510;
	}
	cppVar_12252 = cppVar_12383;
	}
	cppVar_12126 = cppVar_12252;
	}
	cppVar_11997 = cppVar_12126;
	}
	cppVar_11871 = cppVar_11997;
	}
	cppVar_11742 = cppVar_11871;
	}
	cppVar_11616 = cppVar_11742;
	}
	cppVar_11487 = cppVar_11616;
	}
	cppVar_11474 = cppVar_11487;
	}
	cppVar_11348 = cppVar_11474;
	}
	cppVar_11331 = cppVar_11348;
	}
	cppVar_11314 = cppVar_11331;
	}
	cppVar_11164 = cppVar_11314;
	}
	cppVar_11014 = cppVar_11164;
	}
	cppVar_10864 = cppVar_11014;
	}
	cppVar_10714 = cppVar_10864;
	}
	cppVar_10564 = cppVar_10714;
	}
	cppVar_10414 = cppVar_10564;
	}
	cppVar_10264 = cppVar_10414;
	}
	cppVar_10114 = cppVar_10264;
	}
	cppVar_10102 = cppVar_10114;
	}
	cppVar_9975 = cppVar_10102;
	}
	cppVar_9961 = cppVar_9975;
	}
	cppVar_9950 = cppVar_9961;
	}
	return cppVar_9950;
}
