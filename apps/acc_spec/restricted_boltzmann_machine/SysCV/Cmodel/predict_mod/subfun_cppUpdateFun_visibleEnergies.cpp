#include "common.hpp"
#include "model_predict_class.hpp"

type_mem<BV16,8> model_predict::cppUpdateFun_visibleEnergies(BIT_VEC conf_done, BIT_VEC conf_num_hidden, BIT_VEC conf_num_loops, BIT_VEC conf_num_movies, BIT_VEC conf_num_testusers, BIT_VEC conf_num_users, BIT_VEC conf_num_visible, BIT_VEC data_in, BIT_VEC rd_grant, BIT_VEC rst, BIT_VEC wr_grant)
{
	BIT_VEC cppVar_2120;
	BIT_VEC cppVar_2105;
	bool cppVar_2106;
	BIT_VEC cppVar_2108;
	bool cppVar_2109;
	BIT_VEC cppVar_2163;
	bool cppVar_2164;
	BIT_VEC cppVar_2126;
	BIT_VEC cppVar_2127;
	BIT_VEC cppVar_2128;
	bool cppVar_2115;
	BIT_VEC cppVar_2111;
	bool cppVar_2112;
	bool cppVar_2113;
	BIT_VEC cppVar_2137;
	bool cppVar_2138;
	bool cppVar_2139;
	BIT_VEC cppVar_2151;
	bool cppVar_2152;
	bool cppVar_2153;
	BIT_VEC cppVar_2155;
	bool cppVar_2156;
	bool cppVar_2157;
	BIT_VEC cppVar_2159;
	bool cppVar_2160;
	bool cppVar_2161;
	BIT_VEC cppVar_2118;
	bool cppVar_2119;
	BIT_VEC cppVar_2117;
	BIT_VEC cppVar_2122;
	BIT_VEC cppVar_2123;
	BIT_VEC cppVar_2124;
	bool cppVar_2125;
	BIT_VEC cppVar_2129;
	BIT_VEC cppVar_2130;
	BIT_VEC cppVar_2131;
	BIT_VEC cppVar_2132;
	BIT_VEC cppVar_2133;
	BIT_VEC cppVar_2121;
	BIT_VEC cppVar_2134;
	BIT_VEC cppVar_2116;
	type_mem<BV16,8> cppVar_2135;
	type_mem<BV16,8> cppVar_2114;
	BIT_VEC cppVar_2146;
	BIT_VEC cppVar_2144;
	bool cppVar_2145;
	BIT_VEC cppVar_2147;
	BIT_VEC cppVar_2143;
	BIT_VEC cppVar_2141;
	BIT_VEC cppVar_2142;
	BIT_VEC cppVar_2148;
	BIT_VEC cppVar_2140;
	type_mem<BV16,8> cppVar_2149;
	type_mem<BV16,8> cppVar_2158;
	type_mem<BV16,8> cppVar_2154;
	type_mem<BV16,8> cppVar_2150;
	type_mem<BV16,8> cppVar_2136;
	type_mem<BV16,8> cppVar_2110;
	type_mem<BV16,8> cppVar_2162;
	type_mem<BV16,8> cppVar_2107;
	type_mem<BV16,8> cppVar_2104;
	cppVar_2106 = (predict_upc == 0);
	if (cppVar_2106) {
	cppVar_2104 = visibleEnergies;
	} else {
	cppVar_2109 = (predict_upc == 1);
	if (cppVar_2109) {
	cppVar_2112 = (per_v_pc == 0);
	cppVar_2113 = cppVar_2109 && cppVar_2112;
	if (cppVar_2113) {
	cppVar_2115 = (predict_h_cnt == num_hidden);
	if (cppVar_2115) {
	cppVar_2116 = (jstate >> 0) & cppMask_un_3_;
	cppVar_2119 = (predict_h_cnt == 0);
	if (cppVar_2119) {
	cppVar_2117 = 0;
	} else {
	cppVar_2117 = predict_sum;
	}
	cppVar_2122 = (predict_h_cnt >> 0) & cppMask_un_7_;
	cppVar_2123 = hidden_unit.rd(cppVar_2122);
	cppVar_2125 = (cppVar_2123 == 1);
	if (cppVar_2125) {
	cppVar_2127 = 101 * predict_v_cnt;
	cppVar_2127 = (cppVar_2127 & cppMask_un_16_);
	cppVar_2128 = cppVar_2127 + predict_h_cnt;
	cppVar_2128 = (cppVar_2128 & cppMask_un_16_);
	cppVar_2129 = edges.rd(cppVar_2128);
	cppVar_2130 = (cppVar_2129 >> 1) & cppMask_un_7_;
	cppVar_2131 = ((cppVar_2130 & cppMask_bit_7_) ? (cppVar_2130 | cppMask_sign_7_) : cppVar_2130);
	cppVar_2132 = (cppVar_2129 >> 0) & cppMask_un_1_;
	cppVar_2133 = (cppVar_2131 << 1) | cppVar_2132;
	cppVar_2133 = (cppVar_2133 & cppMask_un_16_);
	cppVar_2121 = cppVar_2133;
	} else {
	cppVar_2121 = 0;
	}
	cppVar_2134 = cppVar_2117 + cppVar_2121;
	cppVar_2134 = (cppVar_2134 & cppMask_un_16_);
	cppVar_2135 = visibleEnergies;
	cppVar_2135.wr(cppVar_2116, cppVar_2134);
	cppVar_2114 = cppVar_2135;
	} else {
	cppVar_2114 = visibleEnergies;
	}
	cppVar_2110 = cppVar_2114;
	} else {
	cppVar_2138 = (per_v_pc == 1);
	cppVar_2139 = cppVar_2109 && cppVar_2138;
	if (cppVar_2139) {
	cppVar_2140 = (jstate >> 0) & cppMask_un_3_;
	cppVar_2141 = (jstate >> 0) & cppMask_un_3_;
	cppVar_2142 = visibleEnergies.rd(cppVar_2141);
	cppVar_2145 = (jstate == 0);
	if (cppVar_2145) {
	cppVar_2147 = predict_max - 62;
	cppVar_2147 = (cppVar_2147 & cppMask_un_16_);
	cppVar_2143 = cppVar_2147;
	} else {
	cppVar_2143 = predict_max;
	}
	cppVar_2148 = cppVar_2142 - cppVar_2143;
	cppVar_2148 = (cppVar_2148 & cppMask_un_16_);
	cppVar_2149 = visibleEnergies;
	cppVar_2149.wr(cppVar_2140, cppVar_2148);
	cppVar_2136 = cppVar_2149;
	} else {
	cppVar_2152 = (per_v_pc == 2);
	cppVar_2153 = cppVar_2109 && cppVar_2152;
	if (cppVar_2153) {
	cppVar_2150 = visibleEnergies;
	} else {
	cppVar_2156 = (per_v_pc == 3);
	cppVar_2157 = cppVar_2109 && cppVar_2156;
	if (cppVar_2157) {
	cppVar_2154 = visibleEnergies;
	} else {
	cppVar_2160 = (per_v_pc == 4);
	cppVar_2161 = cppVar_2109 && cppVar_2160;
	if (cppVar_2161) {
	cppVar_2158 = visibleEnergies;
	} else {
	cppVar_2158 = visibleEnergies;
	}
	cppVar_2154 = cppVar_2158;
	}
	cppVar_2150 = cppVar_2154;
	}
	cppVar_2136 = cppVar_2150;
	}
	cppVar_2110 = cppVar_2136;
	}
	cppVar_2107 = cppVar_2110;
	} else {
	cppVar_2164 = (predict_upc == 2);
	if (cppVar_2164) {
	cppVar_2162 = visibleEnergies;
	} else {
	cppVar_2162 = visibleEnergies;
	}
	cppVar_2107 = cppVar_2162;
	}
	cppVar_2104 = cppVar_2107;
	}
	return cppVar_2104;
}
