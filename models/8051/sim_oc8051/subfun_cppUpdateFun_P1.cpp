#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_P1()
{
	BIT_VEC cppVar_27089;
	BIT_VEC cppVar_27090 = ROM.rd(PC);
	bool cppVar_27092 = (cppVar_27090 == 210);
	if (cppVar_27092) {
	BIT_VEC cppVar_27093;
	BIT_VEC cppVar_27094;
	BIT_VEC cppVar_27096 = PC + 1;
	cppVar_27096 = (cppVar_27096 & cppMask_un_16_);
	BIT_VEC cppVar_27097 = ROM.rd(cppVar_27096);
	BIT_VEC cppVar_27098 = (cppVar_27097 >> 7) & cppMask_un_1_;
	bool cppVar_27100 = (cppVar_27098 == 1);
	if (cppVar_27100) {
	BIT_VEC cppVar_27101 = PC + 1;
	cppVar_27101 = (cppVar_27101 & cppMask_un_16_);
	BIT_VEC cppVar_27102 = ROM.rd(cppVar_27101);
	BIT_VEC cppVar_27103 = (cppVar_27102 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27105 = (cppVar_27103 << 3) | 0;
	cppVar_27105 = (cppVar_27105 & cppMask_un_8_);
	cppVar_27094 = cppVar_27105;
	} else {
	BIT_VEC cppVar_27106 = PC + 1;
	cppVar_27106 = (cppVar_27106 & cppMask_un_16_);
	BIT_VEC cppVar_27107 = ROM.rd(cppVar_27106);
	BIT_VEC cppVar_27108 = (cppVar_27107 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27109 = (cppVar_27108 & cppMask_un_5_);
	BIT_VEC cppVar_27111 = cppVar_27109 + 32;
	cppVar_27111 = (cppVar_27111 & cppMask_un_8_);
	cppVar_27094 = cppVar_27111;
	}
	bool cppVar_27113 = (cppVar_27094 == 144);
	if (cppVar_27113) {
	BIT_VEC cppVar_27115 = PC + 1;
	cppVar_27115 = (cppVar_27115 & cppMask_un_16_);
	BIT_VEC cppVar_27116 = ROM.rd(cppVar_27115);
	BIT_VEC cppVar_27117 = (cppVar_27116 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_27118 = (cppVar_27117 & cppMask_un_3_);
	BIT_VEC cppVar_27119 = 1 << static_cast<unsigned>(cppVar_27118);
	cppVar_27119 = (cppVar_27119 & cppMask_un_8_);
	BIT_VEC cppVar_27120 = ~cppVar_27119;
	BIT_VEC cppVar_27121;
	BIT_VEC cppVar_27122;
	BIT_VEC cppVar_27123 = PC + 1;
	cppVar_27123 = (cppVar_27123 & cppMask_un_16_);
	BIT_VEC cppVar_27124 = ROM.rd(cppVar_27123);
	BIT_VEC cppVar_27125 = (cppVar_27124 >> 7) & cppMask_un_1_;
	bool cppVar_27126 = (cppVar_27125 == 1);
	if (cppVar_27126) {
	BIT_VEC cppVar_27127 = PC + 1;
	cppVar_27127 = (cppVar_27127 & cppMask_un_16_);
	BIT_VEC cppVar_27128 = ROM.rd(cppVar_27127);
	BIT_VEC cppVar_27129 = (cppVar_27128 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27130 = (cppVar_27129 << 3) | 0;
	cppVar_27130 = (cppVar_27130 & cppMask_un_8_);
	cppVar_27122 = cppVar_27130;
	} else {
	BIT_VEC cppVar_27131 = PC + 1;
	cppVar_27131 = (cppVar_27131 & cppMask_un_16_);
	BIT_VEC cppVar_27132 = ROM.rd(cppVar_27131);
	BIT_VEC cppVar_27133 = (cppVar_27132 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27134 = (cppVar_27133 & cppMask_un_5_);
	BIT_VEC cppVar_27135 = cppVar_27134 + 32;
	cppVar_27135 = (cppVar_27135 & cppMask_un_8_);
	cppVar_27122 = cppVar_27135;
	}
	BIT_VEC cppVar_27136 = (cppVar_27122 >> 7) & cppMask_un_1_;
	bool cppVar_27138 = (cppVar_27136 == 0);
	if (cppVar_27138) {
	BIT_VEC cppVar_27139;
	BIT_VEC cppVar_27140 = PC + 1;
	cppVar_27140 = (cppVar_27140 & cppMask_un_16_);
	BIT_VEC cppVar_27141 = ROM.rd(cppVar_27140);
	BIT_VEC cppVar_27142 = (cppVar_27141 >> 7) & cppMask_un_1_;
	bool cppVar_27143 = (cppVar_27142 == 1);
	if (cppVar_27143) {
	BIT_VEC cppVar_27144 = PC + 1;
	cppVar_27144 = (cppVar_27144 & cppMask_un_16_);
	BIT_VEC cppVar_27145 = ROM.rd(cppVar_27144);
	BIT_VEC cppVar_27146 = (cppVar_27145 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27147 = (cppVar_27146 << 3) | 0;
	cppVar_27147 = (cppVar_27147 & cppMask_un_8_);
	cppVar_27139 = cppVar_27147;
	} else {
	BIT_VEC cppVar_27148 = PC + 1;
	cppVar_27148 = (cppVar_27148 & cppMask_un_16_);
	BIT_VEC cppVar_27149 = ROM.rd(cppVar_27148);
	BIT_VEC cppVar_27150 = (cppVar_27149 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27151 = (cppVar_27150 & cppMask_un_5_);
	BIT_VEC cppVar_27152 = cppVar_27151 + 32;
	cppVar_27152 = (cppVar_27152 & cppMask_un_8_);
	cppVar_27139 = cppVar_27152;
	}
	BIT_VEC cppVar_27153 = IRAM.rd(cppVar_27139);
	cppVar_27121 = cppVar_27153;
	} else {
	BIT_VEC cppVar_27154;
	BIT_VEC cppVar_27155;
	BIT_VEC cppVar_27156 = PC + 1;
	cppVar_27156 = (cppVar_27156 & cppMask_un_16_);
	BIT_VEC cppVar_27157 = ROM.rd(cppVar_27156);
	BIT_VEC cppVar_27158 = (cppVar_27157 >> 7) & cppMask_un_1_;
	bool cppVar_27159 = (cppVar_27158 == 1);
	if (cppVar_27159) {
	BIT_VEC cppVar_27160 = PC + 1;
	cppVar_27160 = (cppVar_27160 & cppMask_un_16_);
	BIT_VEC cppVar_27161 = ROM.rd(cppVar_27160);
	BIT_VEC cppVar_27162 = (cppVar_27161 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27163 = (cppVar_27162 << 3) | 0;
	cppVar_27163 = (cppVar_27163 & cppMask_un_8_);
	cppVar_27155 = cppVar_27163;
	} else {
	BIT_VEC cppVar_27164 = PC + 1;
	cppVar_27164 = (cppVar_27164 & cppMask_un_16_);
	BIT_VEC cppVar_27165 = ROM.rd(cppVar_27164);
	BIT_VEC cppVar_27166 = (cppVar_27165 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27167 = (cppVar_27166 & cppMask_un_5_);
	BIT_VEC cppVar_27168 = cppVar_27167 + 32;
	cppVar_27168 = (cppVar_27168 & cppMask_un_8_);
	cppVar_27155 = cppVar_27168;
	}
	bool cppVar_27170 = (cppVar_27155 == 128);
	if (cppVar_27170) {
	cppVar_27154 = P0;
	} else {
	BIT_VEC cppVar_27171;
	BIT_VEC cppVar_27172;
	BIT_VEC cppVar_27173 = PC + 1;
	cppVar_27173 = (cppVar_27173 & cppMask_un_16_);
	BIT_VEC cppVar_27174 = ROM.rd(cppVar_27173);
	BIT_VEC cppVar_27175 = (cppVar_27174 >> 7) & cppMask_un_1_;
	bool cppVar_27176 = (cppVar_27175 == 1);
	if (cppVar_27176) {
	BIT_VEC cppVar_27177 = PC + 1;
	cppVar_27177 = (cppVar_27177 & cppMask_un_16_);
	BIT_VEC cppVar_27178 = ROM.rd(cppVar_27177);
	BIT_VEC cppVar_27179 = (cppVar_27178 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27180 = (cppVar_27179 << 3) | 0;
	cppVar_27180 = (cppVar_27180 & cppMask_un_8_);
	cppVar_27172 = cppVar_27180;
	} else {
	BIT_VEC cppVar_27181 = PC + 1;
	cppVar_27181 = (cppVar_27181 & cppMask_un_16_);
	BIT_VEC cppVar_27182 = ROM.rd(cppVar_27181);
	BIT_VEC cppVar_27183 = (cppVar_27182 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27184 = (cppVar_27183 & cppMask_un_5_);
	BIT_VEC cppVar_27185 = cppVar_27184 + 32;
	cppVar_27185 = (cppVar_27185 & cppMask_un_8_);
	cppVar_27172 = cppVar_27185;
	}
	bool cppVar_27187 = (cppVar_27172 == 129);
	if (cppVar_27187) {
	cppVar_27171 = SP;
	} else {
	BIT_VEC cppVar_27188;
	BIT_VEC cppVar_27189;
	BIT_VEC cppVar_27190 = PC + 1;
	cppVar_27190 = (cppVar_27190 & cppMask_un_16_);
	BIT_VEC cppVar_27191 = ROM.rd(cppVar_27190);
	BIT_VEC cppVar_27192 = (cppVar_27191 >> 7) & cppMask_un_1_;
	bool cppVar_27193 = (cppVar_27192 == 1);
	if (cppVar_27193) {
	BIT_VEC cppVar_27194 = PC + 1;
	cppVar_27194 = (cppVar_27194 & cppMask_un_16_);
	BIT_VEC cppVar_27195 = ROM.rd(cppVar_27194);
	BIT_VEC cppVar_27196 = (cppVar_27195 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27197 = (cppVar_27196 << 3) | 0;
	cppVar_27197 = (cppVar_27197 & cppMask_un_8_);
	cppVar_27189 = cppVar_27197;
	} else {
	BIT_VEC cppVar_27198 = PC + 1;
	cppVar_27198 = (cppVar_27198 & cppMask_un_16_);
	BIT_VEC cppVar_27199 = ROM.rd(cppVar_27198);
	BIT_VEC cppVar_27200 = (cppVar_27199 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27201 = (cppVar_27200 & cppMask_un_5_);
	BIT_VEC cppVar_27202 = cppVar_27201 + 32;
	cppVar_27202 = (cppVar_27202 & cppMask_un_8_);
	cppVar_27189 = cppVar_27202;
	}
	bool cppVar_27204 = (cppVar_27189 == 130);
	if (cppVar_27204) {
	cppVar_27188 = DPL;
	} else {
	BIT_VEC cppVar_27205;
	BIT_VEC cppVar_27206;
	BIT_VEC cppVar_27207 = PC + 1;
	cppVar_27207 = (cppVar_27207 & cppMask_un_16_);
	BIT_VEC cppVar_27208 = ROM.rd(cppVar_27207);
	BIT_VEC cppVar_27209 = (cppVar_27208 >> 7) & cppMask_un_1_;
	bool cppVar_27210 = (cppVar_27209 == 1);
	if (cppVar_27210) {
	BIT_VEC cppVar_27211 = PC + 1;
	cppVar_27211 = (cppVar_27211 & cppMask_un_16_);
	BIT_VEC cppVar_27212 = ROM.rd(cppVar_27211);
	BIT_VEC cppVar_27213 = (cppVar_27212 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27214 = (cppVar_27213 << 3) | 0;
	cppVar_27214 = (cppVar_27214 & cppMask_un_8_);
	cppVar_27206 = cppVar_27214;
	} else {
	BIT_VEC cppVar_27215 = PC + 1;
	cppVar_27215 = (cppVar_27215 & cppMask_un_16_);
	BIT_VEC cppVar_27216 = ROM.rd(cppVar_27215);
	BIT_VEC cppVar_27217 = (cppVar_27216 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27218 = (cppVar_27217 & cppMask_un_5_);
	BIT_VEC cppVar_27219 = cppVar_27218 + 32;
	cppVar_27219 = (cppVar_27219 & cppMask_un_8_);
	cppVar_27206 = cppVar_27219;
	}
	bool cppVar_27221 = (cppVar_27206 == 131);
	if (cppVar_27221) {
	cppVar_27205 = DPH;
	} else {
	BIT_VEC cppVar_27222;
	BIT_VEC cppVar_27223;
	BIT_VEC cppVar_27224 = PC + 1;
	cppVar_27224 = (cppVar_27224 & cppMask_un_16_);
	BIT_VEC cppVar_27225 = ROM.rd(cppVar_27224);
	BIT_VEC cppVar_27226 = (cppVar_27225 >> 7) & cppMask_un_1_;
	bool cppVar_27227 = (cppVar_27226 == 1);
	if (cppVar_27227) {
	BIT_VEC cppVar_27228 = PC + 1;
	cppVar_27228 = (cppVar_27228 & cppMask_un_16_);
	BIT_VEC cppVar_27229 = ROM.rd(cppVar_27228);
	BIT_VEC cppVar_27230 = (cppVar_27229 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27231 = (cppVar_27230 << 3) | 0;
	cppVar_27231 = (cppVar_27231 & cppMask_un_8_);
	cppVar_27223 = cppVar_27231;
	} else {
	BIT_VEC cppVar_27232 = PC + 1;
	cppVar_27232 = (cppVar_27232 & cppMask_un_16_);
	BIT_VEC cppVar_27233 = ROM.rd(cppVar_27232);
	BIT_VEC cppVar_27234 = (cppVar_27233 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27235 = (cppVar_27234 & cppMask_un_5_);
	BIT_VEC cppVar_27236 = cppVar_27235 + 32;
	cppVar_27236 = (cppVar_27236 & cppMask_un_8_);
	cppVar_27223 = cppVar_27236;
	}
	bool cppVar_27238 = (cppVar_27223 == 135);
	if (cppVar_27238) {
	cppVar_27222 = PCON;
	} else {
	BIT_VEC cppVar_27239;
	BIT_VEC cppVar_27240;
	BIT_VEC cppVar_27241 = PC + 1;
	cppVar_27241 = (cppVar_27241 & cppMask_un_16_);
	BIT_VEC cppVar_27242 = ROM.rd(cppVar_27241);
	BIT_VEC cppVar_27243 = (cppVar_27242 >> 7) & cppMask_un_1_;
	bool cppVar_27244 = (cppVar_27243 == 1);
	if (cppVar_27244) {
	BIT_VEC cppVar_27245 = PC + 1;
	cppVar_27245 = (cppVar_27245 & cppMask_un_16_);
	BIT_VEC cppVar_27246 = ROM.rd(cppVar_27245);
	BIT_VEC cppVar_27247 = (cppVar_27246 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27248 = (cppVar_27247 << 3) | 0;
	cppVar_27248 = (cppVar_27248 & cppMask_un_8_);
	cppVar_27240 = cppVar_27248;
	} else {
	BIT_VEC cppVar_27249 = PC + 1;
	cppVar_27249 = (cppVar_27249 & cppMask_un_16_);
	BIT_VEC cppVar_27250 = ROM.rd(cppVar_27249);
	BIT_VEC cppVar_27251 = (cppVar_27250 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27252 = (cppVar_27251 & cppMask_un_5_);
	BIT_VEC cppVar_27253 = cppVar_27252 + 32;
	cppVar_27253 = (cppVar_27253 & cppMask_un_8_);
	cppVar_27240 = cppVar_27253;
	}
	bool cppVar_27255 = (cppVar_27240 == 136);
	if (cppVar_27255) {
	cppVar_27239 = TCON;
	} else {
	BIT_VEC cppVar_27256;
	BIT_VEC cppVar_27257;
	BIT_VEC cppVar_27258 = PC + 1;
	cppVar_27258 = (cppVar_27258 & cppMask_un_16_);
	BIT_VEC cppVar_27259 = ROM.rd(cppVar_27258);
	BIT_VEC cppVar_27260 = (cppVar_27259 >> 7) & cppMask_un_1_;
	bool cppVar_27261 = (cppVar_27260 == 1);
	if (cppVar_27261) {
	BIT_VEC cppVar_27262 = PC + 1;
	cppVar_27262 = (cppVar_27262 & cppMask_un_16_);
	BIT_VEC cppVar_27263 = ROM.rd(cppVar_27262);
	BIT_VEC cppVar_27264 = (cppVar_27263 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27265 = (cppVar_27264 << 3) | 0;
	cppVar_27265 = (cppVar_27265 & cppMask_un_8_);
	cppVar_27257 = cppVar_27265;
	} else {
	BIT_VEC cppVar_27266 = PC + 1;
	cppVar_27266 = (cppVar_27266 & cppMask_un_16_);
	BIT_VEC cppVar_27267 = ROM.rd(cppVar_27266);
	BIT_VEC cppVar_27268 = (cppVar_27267 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27269 = (cppVar_27268 & cppMask_un_5_);
	BIT_VEC cppVar_27270 = cppVar_27269 + 32;
	cppVar_27270 = (cppVar_27270 & cppMask_un_8_);
	cppVar_27257 = cppVar_27270;
	}
	bool cppVar_27272 = (cppVar_27257 == 137);
	if (cppVar_27272) {
	cppVar_27256 = TMOD;
	} else {
	BIT_VEC cppVar_27273;
	BIT_VEC cppVar_27274;
	BIT_VEC cppVar_27275 = PC + 1;
	cppVar_27275 = (cppVar_27275 & cppMask_un_16_);
	BIT_VEC cppVar_27276 = ROM.rd(cppVar_27275);
	BIT_VEC cppVar_27277 = (cppVar_27276 >> 7) & cppMask_un_1_;
	bool cppVar_27278 = (cppVar_27277 == 1);
	if (cppVar_27278) {
	BIT_VEC cppVar_27279 = PC + 1;
	cppVar_27279 = (cppVar_27279 & cppMask_un_16_);
	BIT_VEC cppVar_27280 = ROM.rd(cppVar_27279);
	BIT_VEC cppVar_27281 = (cppVar_27280 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27282 = (cppVar_27281 << 3) | 0;
	cppVar_27282 = (cppVar_27282 & cppMask_un_8_);
	cppVar_27274 = cppVar_27282;
	} else {
	BIT_VEC cppVar_27283 = PC + 1;
	cppVar_27283 = (cppVar_27283 & cppMask_un_16_);
	BIT_VEC cppVar_27284 = ROM.rd(cppVar_27283);
	BIT_VEC cppVar_27285 = (cppVar_27284 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27286 = (cppVar_27285 & cppMask_un_5_);
	BIT_VEC cppVar_27287 = cppVar_27286 + 32;
	cppVar_27287 = (cppVar_27287 & cppMask_un_8_);
	cppVar_27274 = cppVar_27287;
	}
	bool cppVar_27289 = (cppVar_27274 == 138);
	if (cppVar_27289) {
	cppVar_27273 = TL0;
	} else {
	BIT_VEC cppVar_27290;
	BIT_VEC cppVar_27291;
	BIT_VEC cppVar_27292 = PC + 1;
	cppVar_27292 = (cppVar_27292 & cppMask_un_16_);
	BIT_VEC cppVar_27293 = ROM.rd(cppVar_27292);
	BIT_VEC cppVar_27294 = (cppVar_27293 >> 7) & cppMask_un_1_;
	bool cppVar_27295 = (cppVar_27294 == 1);
	if (cppVar_27295) {
	BIT_VEC cppVar_27296 = PC + 1;
	cppVar_27296 = (cppVar_27296 & cppMask_un_16_);
	BIT_VEC cppVar_27297 = ROM.rd(cppVar_27296);
	BIT_VEC cppVar_27298 = (cppVar_27297 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27299 = (cppVar_27298 << 3) | 0;
	cppVar_27299 = (cppVar_27299 & cppMask_un_8_);
	cppVar_27291 = cppVar_27299;
	} else {
	BIT_VEC cppVar_27300 = PC + 1;
	cppVar_27300 = (cppVar_27300 & cppMask_un_16_);
	BIT_VEC cppVar_27301 = ROM.rd(cppVar_27300);
	BIT_VEC cppVar_27302 = (cppVar_27301 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27303 = (cppVar_27302 & cppMask_un_5_);
	BIT_VEC cppVar_27304 = cppVar_27303 + 32;
	cppVar_27304 = (cppVar_27304 & cppMask_un_8_);
	cppVar_27291 = cppVar_27304;
	}
	bool cppVar_27306 = (cppVar_27291 == 140);
	if (cppVar_27306) {
	cppVar_27290 = TH0;
	} else {
	BIT_VEC cppVar_27307;
	BIT_VEC cppVar_27308;
	BIT_VEC cppVar_27309 = PC + 1;
	cppVar_27309 = (cppVar_27309 & cppMask_un_16_);
	BIT_VEC cppVar_27310 = ROM.rd(cppVar_27309);
	BIT_VEC cppVar_27311 = (cppVar_27310 >> 7) & cppMask_un_1_;
	bool cppVar_27312 = (cppVar_27311 == 1);
	if (cppVar_27312) {
	BIT_VEC cppVar_27313 = PC + 1;
	cppVar_27313 = (cppVar_27313 & cppMask_un_16_);
	BIT_VEC cppVar_27314 = ROM.rd(cppVar_27313);
	BIT_VEC cppVar_27315 = (cppVar_27314 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27316 = (cppVar_27315 << 3) | 0;
	cppVar_27316 = (cppVar_27316 & cppMask_un_8_);
	cppVar_27308 = cppVar_27316;
	} else {
	BIT_VEC cppVar_27317 = PC + 1;
	cppVar_27317 = (cppVar_27317 & cppMask_un_16_);
	BIT_VEC cppVar_27318 = ROM.rd(cppVar_27317);
	BIT_VEC cppVar_27319 = (cppVar_27318 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27320 = (cppVar_27319 & cppMask_un_5_);
	BIT_VEC cppVar_27321 = cppVar_27320 + 32;
	cppVar_27321 = (cppVar_27321 & cppMask_un_8_);
	cppVar_27308 = cppVar_27321;
	}
	bool cppVar_27323 = (cppVar_27308 == 139);
	if (cppVar_27323) {
	cppVar_27307 = TL1;
	} else {
	BIT_VEC cppVar_27324;
	BIT_VEC cppVar_27325;
	BIT_VEC cppVar_27326 = PC + 1;
	cppVar_27326 = (cppVar_27326 & cppMask_un_16_);
	BIT_VEC cppVar_27327 = ROM.rd(cppVar_27326);
	BIT_VEC cppVar_27328 = (cppVar_27327 >> 7) & cppMask_un_1_;
	bool cppVar_27329 = (cppVar_27328 == 1);
	if (cppVar_27329) {
	BIT_VEC cppVar_27330 = PC + 1;
	cppVar_27330 = (cppVar_27330 & cppMask_un_16_);
	BIT_VEC cppVar_27331 = ROM.rd(cppVar_27330);
	BIT_VEC cppVar_27332 = (cppVar_27331 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27333 = (cppVar_27332 << 3) | 0;
	cppVar_27333 = (cppVar_27333 & cppMask_un_8_);
	cppVar_27325 = cppVar_27333;
	} else {
	BIT_VEC cppVar_27334 = PC + 1;
	cppVar_27334 = (cppVar_27334 & cppMask_un_16_);
	BIT_VEC cppVar_27335 = ROM.rd(cppVar_27334);
	BIT_VEC cppVar_27336 = (cppVar_27335 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27337 = (cppVar_27336 & cppMask_un_5_);
	BIT_VEC cppVar_27338 = cppVar_27337 + 32;
	cppVar_27338 = (cppVar_27338 & cppMask_un_8_);
	cppVar_27325 = cppVar_27338;
	}
	bool cppVar_27340 = (cppVar_27325 == 141);
	if (cppVar_27340) {
	cppVar_27324 = TH1;
	} else {
	BIT_VEC cppVar_27341;
	BIT_VEC cppVar_27342;
	BIT_VEC cppVar_27343 = PC + 1;
	cppVar_27343 = (cppVar_27343 & cppMask_un_16_);
	BIT_VEC cppVar_27344 = ROM.rd(cppVar_27343);
	BIT_VEC cppVar_27345 = (cppVar_27344 >> 7) & cppMask_un_1_;
	bool cppVar_27346 = (cppVar_27345 == 1);
	if (cppVar_27346) {
	BIT_VEC cppVar_27347 = PC + 1;
	cppVar_27347 = (cppVar_27347 & cppMask_un_16_);
	BIT_VEC cppVar_27348 = ROM.rd(cppVar_27347);
	BIT_VEC cppVar_27349 = (cppVar_27348 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27350 = (cppVar_27349 << 3) | 0;
	cppVar_27350 = (cppVar_27350 & cppMask_un_8_);
	cppVar_27342 = cppVar_27350;
	} else {
	BIT_VEC cppVar_27351 = PC + 1;
	cppVar_27351 = (cppVar_27351 & cppMask_un_16_);
	BIT_VEC cppVar_27352 = ROM.rd(cppVar_27351);
	BIT_VEC cppVar_27353 = (cppVar_27352 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27354 = (cppVar_27353 & cppMask_un_5_);
	BIT_VEC cppVar_27355 = cppVar_27354 + 32;
	cppVar_27355 = (cppVar_27355 & cppMask_un_8_);
	cppVar_27342 = cppVar_27355;
	}
	bool cppVar_27357 = (cppVar_27342 == 144);
	if (cppVar_27357) {
	cppVar_27341 = P1;
	} else {
	BIT_VEC cppVar_27358;
	BIT_VEC cppVar_27359;
	BIT_VEC cppVar_27360 = PC + 1;
	cppVar_27360 = (cppVar_27360 & cppMask_un_16_);
	BIT_VEC cppVar_27361 = ROM.rd(cppVar_27360);
	BIT_VEC cppVar_27362 = (cppVar_27361 >> 7) & cppMask_un_1_;
	bool cppVar_27363 = (cppVar_27362 == 1);
	if (cppVar_27363) {
	BIT_VEC cppVar_27364 = PC + 1;
	cppVar_27364 = (cppVar_27364 & cppMask_un_16_);
	BIT_VEC cppVar_27365 = ROM.rd(cppVar_27364);
	BIT_VEC cppVar_27366 = (cppVar_27365 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27367 = (cppVar_27366 << 3) | 0;
	cppVar_27367 = (cppVar_27367 & cppMask_un_8_);
	cppVar_27359 = cppVar_27367;
	} else {
	BIT_VEC cppVar_27368 = PC + 1;
	cppVar_27368 = (cppVar_27368 & cppMask_un_16_);
	BIT_VEC cppVar_27369 = ROM.rd(cppVar_27368);
	BIT_VEC cppVar_27370 = (cppVar_27369 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27371 = (cppVar_27370 & cppMask_un_5_);
	BIT_VEC cppVar_27372 = cppVar_27371 + 32;
	cppVar_27372 = (cppVar_27372 & cppMask_un_8_);
	cppVar_27359 = cppVar_27372;
	}
	bool cppVar_27374 = (cppVar_27359 == 152);
	if (cppVar_27374) {
	cppVar_27358 = SCON;
	} else {
	BIT_VEC cppVar_27375;
	BIT_VEC cppVar_27376;
	BIT_VEC cppVar_27377 = PC + 1;
	cppVar_27377 = (cppVar_27377 & cppMask_un_16_);
	BIT_VEC cppVar_27378 = ROM.rd(cppVar_27377);
	BIT_VEC cppVar_27379 = (cppVar_27378 >> 7) & cppMask_un_1_;
	bool cppVar_27380 = (cppVar_27379 == 1);
	if (cppVar_27380) {
	BIT_VEC cppVar_27381 = PC + 1;
	cppVar_27381 = (cppVar_27381 & cppMask_un_16_);
	BIT_VEC cppVar_27382 = ROM.rd(cppVar_27381);
	BIT_VEC cppVar_27383 = (cppVar_27382 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27384 = (cppVar_27383 << 3) | 0;
	cppVar_27384 = (cppVar_27384 & cppMask_un_8_);
	cppVar_27376 = cppVar_27384;
	} else {
	BIT_VEC cppVar_27385 = PC + 1;
	cppVar_27385 = (cppVar_27385 & cppMask_un_16_);
	BIT_VEC cppVar_27386 = ROM.rd(cppVar_27385);
	BIT_VEC cppVar_27387 = (cppVar_27386 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27388 = (cppVar_27387 & cppMask_un_5_);
	BIT_VEC cppVar_27389 = cppVar_27388 + 32;
	cppVar_27389 = (cppVar_27389 & cppMask_un_8_);
	cppVar_27376 = cppVar_27389;
	}
	bool cppVar_27391 = (cppVar_27376 == 153);
	if (cppVar_27391) {
	cppVar_27375 = SBUF;
	} else {
	BIT_VEC cppVar_27392;
	BIT_VEC cppVar_27393;
	BIT_VEC cppVar_27394 = PC + 1;
	cppVar_27394 = (cppVar_27394 & cppMask_un_16_);
	BIT_VEC cppVar_27395 = ROM.rd(cppVar_27394);
	BIT_VEC cppVar_27396 = (cppVar_27395 >> 7) & cppMask_un_1_;
	bool cppVar_27397 = (cppVar_27396 == 1);
	if (cppVar_27397) {
	BIT_VEC cppVar_27398 = PC + 1;
	cppVar_27398 = (cppVar_27398 & cppMask_un_16_);
	BIT_VEC cppVar_27399 = ROM.rd(cppVar_27398);
	BIT_VEC cppVar_27400 = (cppVar_27399 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27401 = (cppVar_27400 << 3) | 0;
	cppVar_27401 = (cppVar_27401 & cppMask_un_8_);
	cppVar_27393 = cppVar_27401;
	} else {
	BIT_VEC cppVar_27402 = PC + 1;
	cppVar_27402 = (cppVar_27402 & cppMask_un_16_);
	BIT_VEC cppVar_27403 = ROM.rd(cppVar_27402);
	BIT_VEC cppVar_27404 = (cppVar_27403 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27405 = (cppVar_27404 & cppMask_un_5_);
	BIT_VEC cppVar_27406 = cppVar_27405 + 32;
	cppVar_27406 = (cppVar_27406 & cppMask_un_8_);
	cppVar_27393 = cppVar_27406;
	}
	bool cppVar_27408 = (cppVar_27393 == 160);
	if (cppVar_27408) {
	cppVar_27392 = P2;
	} else {
	BIT_VEC cppVar_27409;
	BIT_VEC cppVar_27410;
	BIT_VEC cppVar_27411 = PC + 1;
	cppVar_27411 = (cppVar_27411 & cppMask_un_16_);
	BIT_VEC cppVar_27412 = ROM.rd(cppVar_27411);
	BIT_VEC cppVar_27413 = (cppVar_27412 >> 7) & cppMask_un_1_;
	bool cppVar_27414 = (cppVar_27413 == 1);
	if (cppVar_27414) {
	BIT_VEC cppVar_27415 = PC + 1;
	cppVar_27415 = (cppVar_27415 & cppMask_un_16_);
	BIT_VEC cppVar_27416 = ROM.rd(cppVar_27415);
	BIT_VEC cppVar_27417 = (cppVar_27416 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27418 = (cppVar_27417 << 3) | 0;
	cppVar_27418 = (cppVar_27418 & cppMask_un_8_);
	cppVar_27410 = cppVar_27418;
	} else {
	BIT_VEC cppVar_27419 = PC + 1;
	cppVar_27419 = (cppVar_27419 & cppMask_un_16_);
	BIT_VEC cppVar_27420 = ROM.rd(cppVar_27419);
	BIT_VEC cppVar_27421 = (cppVar_27420 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27422 = (cppVar_27421 & cppMask_un_5_);
	BIT_VEC cppVar_27423 = cppVar_27422 + 32;
	cppVar_27423 = (cppVar_27423 & cppMask_un_8_);
	cppVar_27410 = cppVar_27423;
	}
	bool cppVar_27425 = (cppVar_27410 == 168);
	if (cppVar_27425) {
	cppVar_27409 = IE;
	} else {
	BIT_VEC cppVar_27426;
	BIT_VEC cppVar_27427;
	BIT_VEC cppVar_27428 = PC + 1;
	cppVar_27428 = (cppVar_27428 & cppMask_un_16_);
	BIT_VEC cppVar_27429 = ROM.rd(cppVar_27428);
	BIT_VEC cppVar_27430 = (cppVar_27429 >> 7) & cppMask_un_1_;
	bool cppVar_27431 = (cppVar_27430 == 1);
	if (cppVar_27431) {
	BIT_VEC cppVar_27432 = PC + 1;
	cppVar_27432 = (cppVar_27432 & cppMask_un_16_);
	BIT_VEC cppVar_27433 = ROM.rd(cppVar_27432);
	BIT_VEC cppVar_27434 = (cppVar_27433 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27435 = (cppVar_27434 << 3) | 0;
	cppVar_27435 = (cppVar_27435 & cppMask_un_8_);
	cppVar_27427 = cppVar_27435;
	} else {
	BIT_VEC cppVar_27436 = PC + 1;
	cppVar_27436 = (cppVar_27436 & cppMask_un_16_);
	BIT_VEC cppVar_27437 = ROM.rd(cppVar_27436);
	BIT_VEC cppVar_27438 = (cppVar_27437 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27439 = (cppVar_27438 & cppMask_un_5_);
	BIT_VEC cppVar_27440 = cppVar_27439 + 32;
	cppVar_27440 = (cppVar_27440 & cppMask_un_8_);
	cppVar_27427 = cppVar_27440;
	}
	bool cppVar_27442 = (cppVar_27427 == 176);
	if (cppVar_27442) {
	cppVar_27426 = P3;
	} else {
	BIT_VEC cppVar_27443;
	BIT_VEC cppVar_27444;
	BIT_VEC cppVar_27445 = PC + 1;
	cppVar_27445 = (cppVar_27445 & cppMask_un_16_);
	BIT_VEC cppVar_27446 = ROM.rd(cppVar_27445);
	BIT_VEC cppVar_27447 = (cppVar_27446 >> 7) & cppMask_un_1_;
	bool cppVar_27448 = (cppVar_27447 == 1);
	if (cppVar_27448) {
	BIT_VEC cppVar_27449 = PC + 1;
	cppVar_27449 = (cppVar_27449 & cppMask_un_16_);
	BIT_VEC cppVar_27450 = ROM.rd(cppVar_27449);
	BIT_VEC cppVar_27451 = (cppVar_27450 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27452 = (cppVar_27451 << 3) | 0;
	cppVar_27452 = (cppVar_27452 & cppMask_un_8_);
	cppVar_27444 = cppVar_27452;
	} else {
	BIT_VEC cppVar_27453 = PC + 1;
	cppVar_27453 = (cppVar_27453 & cppMask_un_16_);
	BIT_VEC cppVar_27454 = ROM.rd(cppVar_27453);
	BIT_VEC cppVar_27455 = (cppVar_27454 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27456 = (cppVar_27455 & cppMask_un_5_);
	BIT_VEC cppVar_27457 = cppVar_27456 + 32;
	cppVar_27457 = (cppVar_27457 & cppMask_un_8_);
	cppVar_27444 = cppVar_27457;
	}
	bool cppVar_27459 = (cppVar_27444 == 184);
	if (cppVar_27459) {
	cppVar_27443 = IP;
	} else {
	BIT_VEC cppVar_27460;
	BIT_VEC cppVar_27461;
	BIT_VEC cppVar_27462 = PC + 1;
	cppVar_27462 = (cppVar_27462 & cppMask_un_16_);
	BIT_VEC cppVar_27463 = ROM.rd(cppVar_27462);
	BIT_VEC cppVar_27464 = (cppVar_27463 >> 7) & cppMask_un_1_;
	bool cppVar_27465 = (cppVar_27464 == 1);
	if (cppVar_27465) {
	BIT_VEC cppVar_27466 = PC + 1;
	cppVar_27466 = (cppVar_27466 & cppMask_un_16_);
	BIT_VEC cppVar_27467 = ROM.rd(cppVar_27466);
	BIT_VEC cppVar_27468 = (cppVar_27467 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27469 = (cppVar_27468 << 3) | 0;
	cppVar_27469 = (cppVar_27469 & cppMask_un_8_);
	cppVar_27461 = cppVar_27469;
	} else {
	BIT_VEC cppVar_27470 = PC + 1;
	cppVar_27470 = (cppVar_27470 & cppMask_un_16_);
	BIT_VEC cppVar_27471 = ROM.rd(cppVar_27470);
	BIT_VEC cppVar_27472 = (cppVar_27471 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27473 = (cppVar_27472 & cppMask_un_5_);
	BIT_VEC cppVar_27474 = cppVar_27473 + 32;
	cppVar_27474 = (cppVar_27474 & cppMask_un_8_);
	cppVar_27461 = cppVar_27474;
	}
	bool cppVar_27476 = (cppVar_27461 == 208);
	if (cppVar_27476) {
	cppVar_27460 = PSW;
	} else {
	BIT_VEC cppVar_27477;
	BIT_VEC cppVar_27478;
	BIT_VEC cppVar_27479 = PC + 1;
	cppVar_27479 = (cppVar_27479 & cppMask_un_16_);
	BIT_VEC cppVar_27480 = ROM.rd(cppVar_27479);
	BIT_VEC cppVar_27481 = (cppVar_27480 >> 7) & cppMask_un_1_;
	bool cppVar_27482 = (cppVar_27481 == 1);
	if (cppVar_27482) {
	BIT_VEC cppVar_27483 = PC + 1;
	cppVar_27483 = (cppVar_27483 & cppMask_un_16_);
	BIT_VEC cppVar_27484 = ROM.rd(cppVar_27483);
	BIT_VEC cppVar_27485 = (cppVar_27484 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27486 = (cppVar_27485 << 3) | 0;
	cppVar_27486 = (cppVar_27486 & cppMask_un_8_);
	cppVar_27478 = cppVar_27486;
	} else {
	BIT_VEC cppVar_27487 = PC + 1;
	cppVar_27487 = (cppVar_27487 & cppMask_un_16_);
	BIT_VEC cppVar_27488 = ROM.rd(cppVar_27487);
	BIT_VEC cppVar_27489 = (cppVar_27488 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27490 = (cppVar_27489 & cppMask_un_5_);
	BIT_VEC cppVar_27491 = cppVar_27490 + 32;
	cppVar_27491 = (cppVar_27491 & cppMask_un_8_);
	cppVar_27478 = cppVar_27491;
	}
	bool cppVar_27493 = (cppVar_27478 == 224);
	if (cppVar_27493) {
	cppVar_27477 = ACC;
	} else {
	BIT_VEC cppVar_27494;
	BIT_VEC cppVar_27495;
	BIT_VEC cppVar_27496 = PC + 1;
	cppVar_27496 = (cppVar_27496 & cppMask_un_16_);
	BIT_VEC cppVar_27497 = ROM.rd(cppVar_27496);
	BIT_VEC cppVar_27498 = (cppVar_27497 >> 7) & cppMask_un_1_;
	bool cppVar_27499 = (cppVar_27498 == 1);
	if (cppVar_27499) {
	BIT_VEC cppVar_27500 = PC + 1;
	cppVar_27500 = (cppVar_27500 & cppMask_un_16_);
	BIT_VEC cppVar_27501 = ROM.rd(cppVar_27500);
	BIT_VEC cppVar_27502 = (cppVar_27501 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27503 = (cppVar_27502 << 3) | 0;
	cppVar_27503 = (cppVar_27503 & cppMask_un_8_);
	cppVar_27495 = cppVar_27503;
	} else {
	BIT_VEC cppVar_27504 = PC + 1;
	cppVar_27504 = (cppVar_27504 & cppMask_un_16_);
	BIT_VEC cppVar_27505 = ROM.rd(cppVar_27504);
	BIT_VEC cppVar_27506 = (cppVar_27505 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27507 = (cppVar_27506 & cppMask_un_5_);
	BIT_VEC cppVar_27508 = cppVar_27507 + 32;
	cppVar_27508 = (cppVar_27508 & cppMask_un_8_);
	cppVar_27495 = cppVar_27508;
	}
	bool cppVar_27510 = (cppVar_27495 == 240);
	if (cppVar_27510) {
	cppVar_27494 = B;
	} else {
	cppVar_27494 = 0;
	}
	cppVar_27477 = cppVar_27494;
	}
	cppVar_27460 = cppVar_27477;
	}
	cppVar_27443 = cppVar_27460;
	}
	cppVar_27426 = cppVar_27443;
	}
	cppVar_27409 = cppVar_27426;
	}
	cppVar_27392 = cppVar_27409;
	}
	cppVar_27375 = cppVar_27392;
	}
	cppVar_27358 = cppVar_27375;
	}
	cppVar_27341 = cppVar_27358;
	}
	cppVar_27324 = cppVar_27341;
	}
	cppVar_27307 = cppVar_27324;
	}
	cppVar_27290 = cppVar_27307;
	}
	cppVar_27273 = cppVar_27290;
	}
	cppVar_27256 = cppVar_27273;
	}
	cppVar_27239 = cppVar_27256;
	}
	cppVar_27222 = cppVar_27239;
	}
	cppVar_27205 = cppVar_27222;
	}
	cppVar_27188 = cppVar_27205;
	}
	cppVar_27171 = cppVar_27188;
	}
	cppVar_27154 = cppVar_27171;
	}
	cppVar_27121 = cppVar_27154;
	}
	BIT_VEC cppVar_27512 = cppVar_27120 & cppVar_27121;
	BIT_VEC cppVar_27514 = 1;
	BIT_VEC cppVar_27515 = PC + 1;
	cppVar_27515 = (cppVar_27515 & cppMask_un_16_);
	BIT_VEC cppVar_27516 = ROM.rd(cppVar_27515);
	BIT_VEC cppVar_27517 = (cppVar_27516 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_27518 = (cppVar_27517 & cppMask_un_3_);
	BIT_VEC cppVar_27519 = cppVar_27514 << static_cast<unsigned>(cppVar_27518);
	cppVar_27519 = (cppVar_27519 & cppMask_un_8_);
	BIT_VEC cppVar_27520 = cppVar_27512 | cppVar_27519;
	cppVar_27093 = cppVar_27520;
	} else {
	cppVar_27093 = P1;
	}
	cppVar_27089 = cppVar_27093;
	} else {
	BIT_VEC cppVar_27521;
	BIT_VEC cppVar_27522 = ROM.rd(PC);
	bool cppVar_27524 = (cppVar_27522 == 208);
	if (cppVar_27524) {
	BIT_VEC cppVar_27525;
	BIT_VEC cppVar_27527 = PC + 1;
	cppVar_27527 = (cppVar_27527 & cppMask_un_16_);
	BIT_VEC cppVar_27528 = ROM.rd(cppVar_27527);
	bool cppVar_27530 = (cppVar_27528 == 144);
	if (cppVar_27530) {
	BIT_VEC cppVar_27531 = IRAM.rd(SP);
	cppVar_27525 = cppVar_27531;
	} else {
	cppVar_27525 = P1;
	}
	cppVar_27521 = cppVar_27525;
	} else {
	BIT_VEC cppVar_27532;
	BIT_VEC cppVar_27533 = ROM.rd(PC);
	bool cppVar_27535 = (cppVar_27533 == 245);
	BIT_VEC cppVar_27536 = ROM.rd(PC);
	bool cppVar_27538 = (cppVar_27536 == 197);
	bool cppVar_27539 = cppVar_27535 || cppVar_27538;
	if (cppVar_27539) {
	BIT_VEC cppVar_27540;
	BIT_VEC cppVar_27542 = PC + 1;
	cppVar_27542 = (cppVar_27542 & cppMask_un_16_);
	BIT_VEC cppVar_27543 = ROM.rd(cppVar_27542);
	bool cppVar_27545 = (cppVar_27543 == 144);
	if (cppVar_27545) {
	cppVar_27540 = ACC;
	} else {
	cppVar_27540 = P1;
	}
	cppVar_27532 = cppVar_27540;
	} else {
	BIT_VEC cppVar_27546;
	BIT_VEC cppVar_27547 = ROM.rd(PC);
	bool cppVar_27549 = (cppVar_27547 == 178);
	if (cppVar_27549) {
	BIT_VEC cppVar_27550;
	BIT_VEC cppVar_27551;
	BIT_VEC cppVar_27553 = PC + 1;
	cppVar_27553 = (cppVar_27553 & cppMask_un_16_);
	BIT_VEC cppVar_27554 = ROM.rd(cppVar_27553);
	BIT_VEC cppVar_27555 = (cppVar_27554 >> 7) & cppMask_un_1_;
	bool cppVar_27557 = (cppVar_27555 == 1);
	if (cppVar_27557) {
	BIT_VEC cppVar_27558 = PC + 1;
	cppVar_27558 = (cppVar_27558 & cppMask_un_16_);
	BIT_VEC cppVar_27559 = ROM.rd(cppVar_27558);
	BIT_VEC cppVar_27560 = (cppVar_27559 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27562 = (cppVar_27560 << 3) | 0;
	cppVar_27562 = (cppVar_27562 & cppMask_un_8_);
	cppVar_27551 = cppVar_27562;
	} else {
	BIT_VEC cppVar_27563 = PC + 1;
	cppVar_27563 = (cppVar_27563 & cppMask_un_16_);
	BIT_VEC cppVar_27564 = ROM.rd(cppVar_27563);
	BIT_VEC cppVar_27565 = (cppVar_27564 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27566 = (cppVar_27565 & cppMask_un_5_);
	BIT_VEC cppVar_27568 = cppVar_27566 + 32;
	cppVar_27568 = (cppVar_27568 & cppMask_un_8_);
	cppVar_27551 = cppVar_27568;
	}
	bool cppVar_27570 = (cppVar_27551 == 144);
	if (cppVar_27570) {
	BIT_VEC cppVar_27572 = PC + 1;
	cppVar_27572 = (cppVar_27572 & cppMask_un_16_);
	BIT_VEC cppVar_27573 = ROM.rd(cppVar_27572);
	BIT_VEC cppVar_27574 = (cppVar_27573 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_27575 = (cppVar_27574 & cppMask_un_3_);
	BIT_VEC cppVar_27576 = 1 << static_cast<unsigned>(cppVar_27575);
	cppVar_27576 = (cppVar_27576 & cppMask_un_8_);
	BIT_VEC cppVar_27577 = ~cppVar_27576;
	BIT_VEC cppVar_27578;
	BIT_VEC cppVar_27579;
	BIT_VEC cppVar_27580 = PC + 1;
	cppVar_27580 = (cppVar_27580 & cppMask_un_16_);
	BIT_VEC cppVar_27581 = ROM.rd(cppVar_27580);
	BIT_VEC cppVar_27582 = (cppVar_27581 >> 7) & cppMask_un_1_;
	bool cppVar_27583 = (cppVar_27582 == 1);
	if (cppVar_27583) {
	BIT_VEC cppVar_27584 = PC + 1;
	cppVar_27584 = (cppVar_27584 & cppMask_un_16_);
	BIT_VEC cppVar_27585 = ROM.rd(cppVar_27584);
	BIT_VEC cppVar_27586 = (cppVar_27585 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27587 = (cppVar_27586 << 3) | 0;
	cppVar_27587 = (cppVar_27587 & cppMask_un_8_);
	cppVar_27579 = cppVar_27587;
	} else {
	BIT_VEC cppVar_27588 = PC + 1;
	cppVar_27588 = (cppVar_27588 & cppMask_un_16_);
	BIT_VEC cppVar_27589 = ROM.rd(cppVar_27588);
	BIT_VEC cppVar_27590 = (cppVar_27589 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27591 = (cppVar_27590 & cppMask_un_5_);
	BIT_VEC cppVar_27592 = cppVar_27591 + 32;
	cppVar_27592 = (cppVar_27592 & cppMask_un_8_);
	cppVar_27579 = cppVar_27592;
	}
	BIT_VEC cppVar_27593 = (cppVar_27579 >> 7) & cppMask_un_1_;
	bool cppVar_27595 = (cppVar_27593 == 0);
	if (cppVar_27595) {
	BIT_VEC cppVar_27596;
	BIT_VEC cppVar_27597 = PC + 1;
	cppVar_27597 = (cppVar_27597 & cppMask_un_16_);
	BIT_VEC cppVar_27598 = ROM.rd(cppVar_27597);
	BIT_VEC cppVar_27599 = (cppVar_27598 >> 7) & cppMask_un_1_;
	bool cppVar_27600 = (cppVar_27599 == 1);
	if (cppVar_27600) {
	BIT_VEC cppVar_27601 = PC + 1;
	cppVar_27601 = (cppVar_27601 & cppMask_un_16_);
	BIT_VEC cppVar_27602 = ROM.rd(cppVar_27601);
	BIT_VEC cppVar_27603 = (cppVar_27602 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27604 = (cppVar_27603 << 3) | 0;
	cppVar_27604 = (cppVar_27604 & cppMask_un_8_);
	cppVar_27596 = cppVar_27604;
	} else {
	BIT_VEC cppVar_27605 = PC + 1;
	cppVar_27605 = (cppVar_27605 & cppMask_un_16_);
	BIT_VEC cppVar_27606 = ROM.rd(cppVar_27605);
	BIT_VEC cppVar_27607 = (cppVar_27606 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27608 = (cppVar_27607 & cppMask_un_5_);
	BIT_VEC cppVar_27609 = cppVar_27608 + 32;
	cppVar_27609 = (cppVar_27609 & cppMask_un_8_);
	cppVar_27596 = cppVar_27609;
	}
	BIT_VEC cppVar_27610 = IRAM.rd(cppVar_27596);
	cppVar_27578 = cppVar_27610;
	} else {
	BIT_VEC cppVar_27611;
	BIT_VEC cppVar_27612;
	BIT_VEC cppVar_27613 = PC + 1;
	cppVar_27613 = (cppVar_27613 & cppMask_un_16_);
	BIT_VEC cppVar_27614 = ROM.rd(cppVar_27613);
	BIT_VEC cppVar_27615 = (cppVar_27614 >> 7) & cppMask_un_1_;
	bool cppVar_27616 = (cppVar_27615 == 1);
	if (cppVar_27616) {
	BIT_VEC cppVar_27617 = PC + 1;
	cppVar_27617 = (cppVar_27617 & cppMask_un_16_);
	BIT_VEC cppVar_27618 = ROM.rd(cppVar_27617);
	BIT_VEC cppVar_27619 = (cppVar_27618 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27620 = (cppVar_27619 << 3) | 0;
	cppVar_27620 = (cppVar_27620 & cppMask_un_8_);
	cppVar_27612 = cppVar_27620;
	} else {
	BIT_VEC cppVar_27621 = PC + 1;
	cppVar_27621 = (cppVar_27621 & cppMask_un_16_);
	BIT_VEC cppVar_27622 = ROM.rd(cppVar_27621);
	BIT_VEC cppVar_27623 = (cppVar_27622 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27624 = (cppVar_27623 & cppMask_un_5_);
	BIT_VEC cppVar_27625 = cppVar_27624 + 32;
	cppVar_27625 = (cppVar_27625 & cppMask_un_8_);
	cppVar_27612 = cppVar_27625;
	}
	bool cppVar_27627 = (cppVar_27612 == 128);
	if (cppVar_27627) {
	cppVar_27611 = P0;
	} else {
	BIT_VEC cppVar_27628;
	BIT_VEC cppVar_27629;
	BIT_VEC cppVar_27630 = PC + 1;
	cppVar_27630 = (cppVar_27630 & cppMask_un_16_);
	BIT_VEC cppVar_27631 = ROM.rd(cppVar_27630);
	BIT_VEC cppVar_27632 = (cppVar_27631 >> 7) & cppMask_un_1_;
	bool cppVar_27633 = (cppVar_27632 == 1);
	if (cppVar_27633) {
	BIT_VEC cppVar_27634 = PC + 1;
	cppVar_27634 = (cppVar_27634 & cppMask_un_16_);
	BIT_VEC cppVar_27635 = ROM.rd(cppVar_27634);
	BIT_VEC cppVar_27636 = (cppVar_27635 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27637 = (cppVar_27636 << 3) | 0;
	cppVar_27637 = (cppVar_27637 & cppMask_un_8_);
	cppVar_27629 = cppVar_27637;
	} else {
	BIT_VEC cppVar_27638 = PC + 1;
	cppVar_27638 = (cppVar_27638 & cppMask_un_16_);
	BIT_VEC cppVar_27639 = ROM.rd(cppVar_27638);
	BIT_VEC cppVar_27640 = (cppVar_27639 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27641 = (cppVar_27640 & cppMask_un_5_);
	BIT_VEC cppVar_27642 = cppVar_27641 + 32;
	cppVar_27642 = (cppVar_27642 & cppMask_un_8_);
	cppVar_27629 = cppVar_27642;
	}
	bool cppVar_27644 = (cppVar_27629 == 129);
	if (cppVar_27644) {
	cppVar_27628 = SP;
	} else {
	BIT_VEC cppVar_27645;
	BIT_VEC cppVar_27646;
	BIT_VEC cppVar_27647 = PC + 1;
	cppVar_27647 = (cppVar_27647 & cppMask_un_16_);
	BIT_VEC cppVar_27648 = ROM.rd(cppVar_27647);
	BIT_VEC cppVar_27649 = (cppVar_27648 >> 7) & cppMask_un_1_;
	bool cppVar_27650 = (cppVar_27649 == 1);
	if (cppVar_27650) {
	BIT_VEC cppVar_27651 = PC + 1;
	cppVar_27651 = (cppVar_27651 & cppMask_un_16_);
	BIT_VEC cppVar_27652 = ROM.rd(cppVar_27651);
	BIT_VEC cppVar_27653 = (cppVar_27652 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27654 = (cppVar_27653 << 3) | 0;
	cppVar_27654 = (cppVar_27654 & cppMask_un_8_);
	cppVar_27646 = cppVar_27654;
	} else {
	BIT_VEC cppVar_27655 = PC + 1;
	cppVar_27655 = (cppVar_27655 & cppMask_un_16_);
	BIT_VEC cppVar_27656 = ROM.rd(cppVar_27655);
	BIT_VEC cppVar_27657 = (cppVar_27656 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27658 = (cppVar_27657 & cppMask_un_5_);
	BIT_VEC cppVar_27659 = cppVar_27658 + 32;
	cppVar_27659 = (cppVar_27659 & cppMask_un_8_);
	cppVar_27646 = cppVar_27659;
	}
	bool cppVar_27661 = (cppVar_27646 == 130);
	if (cppVar_27661) {
	cppVar_27645 = DPL;
	} else {
	BIT_VEC cppVar_27662;
	BIT_VEC cppVar_27663;
	BIT_VEC cppVar_27664 = PC + 1;
	cppVar_27664 = (cppVar_27664 & cppMask_un_16_);
	BIT_VEC cppVar_27665 = ROM.rd(cppVar_27664);
	BIT_VEC cppVar_27666 = (cppVar_27665 >> 7) & cppMask_un_1_;
	bool cppVar_27667 = (cppVar_27666 == 1);
	if (cppVar_27667) {
	BIT_VEC cppVar_27668 = PC + 1;
	cppVar_27668 = (cppVar_27668 & cppMask_un_16_);
	BIT_VEC cppVar_27669 = ROM.rd(cppVar_27668);
	BIT_VEC cppVar_27670 = (cppVar_27669 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27671 = (cppVar_27670 << 3) | 0;
	cppVar_27671 = (cppVar_27671 & cppMask_un_8_);
	cppVar_27663 = cppVar_27671;
	} else {
	BIT_VEC cppVar_27672 = PC + 1;
	cppVar_27672 = (cppVar_27672 & cppMask_un_16_);
	BIT_VEC cppVar_27673 = ROM.rd(cppVar_27672);
	BIT_VEC cppVar_27674 = (cppVar_27673 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27675 = (cppVar_27674 & cppMask_un_5_);
	BIT_VEC cppVar_27676 = cppVar_27675 + 32;
	cppVar_27676 = (cppVar_27676 & cppMask_un_8_);
	cppVar_27663 = cppVar_27676;
	}
	bool cppVar_27678 = (cppVar_27663 == 131);
	if (cppVar_27678) {
	cppVar_27662 = DPH;
	} else {
	BIT_VEC cppVar_27679;
	BIT_VEC cppVar_27680;
	BIT_VEC cppVar_27681 = PC + 1;
	cppVar_27681 = (cppVar_27681 & cppMask_un_16_);
	BIT_VEC cppVar_27682 = ROM.rd(cppVar_27681);
	BIT_VEC cppVar_27683 = (cppVar_27682 >> 7) & cppMask_un_1_;
	bool cppVar_27684 = (cppVar_27683 == 1);
	if (cppVar_27684) {
	BIT_VEC cppVar_27685 = PC + 1;
	cppVar_27685 = (cppVar_27685 & cppMask_un_16_);
	BIT_VEC cppVar_27686 = ROM.rd(cppVar_27685);
	BIT_VEC cppVar_27687 = (cppVar_27686 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27688 = (cppVar_27687 << 3) | 0;
	cppVar_27688 = (cppVar_27688 & cppMask_un_8_);
	cppVar_27680 = cppVar_27688;
	} else {
	BIT_VEC cppVar_27689 = PC + 1;
	cppVar_27689 = (cppVar_27689 & cppMask_un_16_);
	BIT_VEC cppVar_27690 = ROM.rd(cppVar_27689);
	BIT_VEC cppVar_27691 = (cppVar_27690 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27692 = (cppVar_27691 & cppMask_un_5_);
	BIT_VEC cppVar_27693 = cppVar_27692 + 32;
	cppVar_27693 = (cppVar_27693 & cppMask_un_8_);
	cppVar_27680 = cppVar_27693;
	}
	bool cppVar_27695 = (cppVar_27680 == 135);
	if (cppVar_27695) {
	cppVar_27679 = PCON;
	} else {
	BIT_VEC cppVar_27696;
	BIT_VEC cppVar_27697;
	BIT_VEC cppVar_27698 = PC + 1;
	cppVar_27698 = (cppVar_27698 & cppMask_un_16_);
	BIT_VEC cppVar_27699 = ROM.rd(cppVar_27698);
	BIT_VEC cppVar_27700 = (cppVar_27699 >> 7) & cppMask_un_1_;
	bool cppVar_27701 = (cppVar_27700 == 1);
	if (cppVar_27701) {
	BIT_VEC cppVar_27702 = PC + 1;
	cppVar_27702 = (cppVar_27702 & cppMask_un_16_);
	BIT_VEC cppVar_27703 = ROM.rd(cppVar_27702);
	BIT_VEC cppVar_27704 = (cppVar_27703 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27705 = (cppVar_27704 << 3) | 0;
	cppVar_27705 = (cppVar_27705 & cppMask_un_8_);
	cppVar_27697 = cppVar_27705;
	} else {
	BIT_VEC cppVar_27706 = PC + 1;
	cppVar_27706 = (cppVar_27706 & cppMask_un_16_);
	BIT_VEC cppVar_27707 = ROM.rd(cppVar_27706);
	BIT_VEC cppVar_27708 = (cppVar_27707 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27709 = (cppVar_27708 & cppMask_un_5_);
	BIT_VEC cppVar_27710 = cppVar_27709 + 32;
	cppVar_27710 = (cppVar_27710 & cppMask_un_8_);
	cppVar_27697 = cppVar_27710;
	}
	bool cppVar_27712 = (cppVar_27697 == 136);
	if (cppVar_27712) {
	cppVar_27696 = TCON;
	} else {
	BIT_VEC cppVar_27713;
	BIT_VEC cppVar_27714;
	BIT_VEC cppVar_27715 = PC + 1;
	cppVar_27715 = (cppVar_27715 & cppMask_un_16_);
	BIT_VEC cppVar_27716 = ROM.rd(cppVar_27715);
	BIT_VEC cppVar_27717 = (cppVar_27716 >> 7) & cppMask_un_1_;
	bool cppVar_27718 = (cppVar_27717 == 1);
	if (cppVar_27718) {
	BIT_VEC cppVar_27719 = PC + 1;
	cppVar_27719 = (cppVar_27719 & cppMask_un_16_);
	BIT_VEC cppVar_27720 = ROM.rd(cppVar_27719);
	BIT_VEC cppVar_27721 = (cppVar_27720 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27722 = (cppVar_27721 << 3) | 0;
	cppVar_27722 = (cppVar_27722 & cppMask_un_8_);
	cppVar_27714 = cppVar_27722;
	} else {
	BIT_VEC cppVar_27723 = PC + 1;
	cppVar_27723 = (cppVar_27723 & cppMask_un_16_);
	BIT_VEC cppVar_27724 = ROM.rd(cppVar_27723);
	BIT_VEC cppVar_27725 = (cppVar_27724 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27726 = (cppVar_27725 & cppMask_un_5_);
	BIT_VEC cppVar_27727 = cppVar_27726 + 32;
	cppVar_27727 = (cppVar_27727 & cppMask_un_8_);
	cppVar_27714 = cppVar_27727;
	}
	bool cppVar_27729 = (cppVar_27714 == 137);
	if (cppVar_27729) {
	cppVar_27713 = TMOD;
	} else {
	BIT_VEC cppVar_27730;
	BIT_VEC cppVar_27731;
	BIT_VEC cppVar_27732 = PC + 1;
	cppVar_27732 = (cppVar_27732 & cppMask_un_16_);
	BIT_VEC cppVar_27733 = ROM.rd(cppVar_27732);
	BIT_VEC cppVar_27734 = (cppVar_27733 >> 7) & cppMask_un_1_;
	bool cppVar_27735 = (cppVar_27734 == 1);
	if (cppVar_27735) {
	BIT_VEC cppVar_27736 = PC + 1;
	cppVar_27736 = (cppVar_27736 & cppMask_un_16_);
	BIT_VEC cppVar_27737 = ROM.rd(cppVar_27736);
	BIT_VEC cppVar_27738 = (cppVar_27737 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27739 = (cppVar_27738 << 3) | 0;
	cppVar_27739 = (cppVar_27739 & cppMask_un_8_);
	cppVar_27731 = cppVar_27739;
	} else {
	BIT_VEC cppVar_27740 = PC + 1;
	cppVar_27740 = (cppVar_27740 & cppMask_un_16_);
	BIT_VEC cppVar_27741 = ROM.rd(cppVar_27740);
	BIT_VEC cppVar_27742 = (cppVar_27741 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27743 = (cppVar_27742 & cppMask_un_5_);
	BIT_VEC cppVar_27744 = cppVar_27743 + 32;
	cppVar_27744 = (cppVar_27744 & cppMask_un_8_);
	cppVar_27731 = cppVar_27744;
	}
	bool cppVar_27746 = (cppVar_27731 == 138);
	if (cppVar_27746) {
	cppVar_27730 = TL0;
	} else {
	BIT_VEC cppVar_27747;
	BIT_VEC cppVar_27748;
	BIT_VEC cppVar_27749 = PC + 1;
	cppVar_27749 = (cppVar_27749 & cppMask_un_16_);
	BIT_VEC cppVar_27750 = ROM.rd(cppVar_27749);
	BIT_VEC cppVar_27751 = (cppVar_27750 >> 7) & cppMask_un_1_;
	bool cppVar_27752 = (cppVar_27751 == 1);
	if (cppVar_27752) {
	BIT_VEC cppVar_27753 = PC + 1;
	cppVar_27753 = (cppVar_27753 & cppMask_un_16_);
	BIT_VEC cppVar_27754 = ROM.rd(cppVar_27753);
	BIT_VEC cppVar_27755 = (cppVar_27754 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27756 = (cppVar_27755 << 3) | 0;
	cppVar_27756 = (cppVar_27756 & cppMask_un_8_);
	cppVar_27748 = cppVar_27756;
	} else {
	BIT_VEC cppVar_27757 = PC + 1;
	cppVar_27757 = (cppVar_27757 & cppMask_un_16_);
	BIT_VEC cppVar_27758 = ROM.rd(cppVar_27757);
	BIT_VEC cppVar_27759 = (cppVar_27758 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27760 = (cppVar_27759 & cppMask_un_5_);
	BIT_VEC cppVar_27761 = cppVar_27760 + 32;
	cppVar_27761 = (cppVar_27761 & cppMask_un_8_);
	cppVar_27748 = cppVar_27761;
	}
	bool cppVar_27763 = (cppVar_27748 == 140);
	if (cppVar_27763) {
	cppVar_27747 = TH0;
	} else {
	BIT_VEC cppVar_27764;
	BIT_VEC cppVar_27765;
	BIT_VEC cppVar_27766 = PC + 1;
	cppVar_27766 = (cppVar_27766 & cppMask_un_16_);
	BIT_VEC cppVar_27767 = ROM.rd(cppVar_27766);
	BIT_VEC cppVar_27768 = (cppVar_27767 >> 7) & cppMask_un_1_;
	bool cppVar_27769 = (cppVar_27768 == 1);
	if (cppVar_27769) {
	BIT_VEC cppVar_27770 = PC + 1;
	cppVar_27770 = (cppVar_27770 & cppMask_un_16_);
	BIT_VEC cppVar_27771 = ROM.rd(cppVar_27770);
	BIT_VEC cppVar_27772 = (cppVar_27771 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27773 = (cppVar_27772 << 3) | 0;
	cppVar_27773 = (cppVar_27773 & cppMask_un_8_);
	cppVar_27765 = cppVar_27773;
	} else {
	BIT_VEC cppVar_27774 = PC + 1;
	cppVar_27774 = (cppVar_27774 & cppMask_un_16_);
	BIT_VEC cppVar_27775 = ROM.rd(cppVar_27774);
	BIT_VEC cppVar_27776 = (cppVar_27775 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27777 = (cppVar_27776 & cppMask_un_5_);
	BIT_VEC cppVar_27778 = cppVar_27777 + 32;
	cppVar_27778 = (cppVar_27778 & cppMask_un_8_);
	cppVar_27765 = cppVar_27778;
	}
	bool cppVar_27780 = (cppVar_27765 == 139);
	if (cppVar_27780) {
	cppVar_27764 = TL1;
	} else {
	BIT_VEC cppVar_27781;
	BIT_VEC cppVar_27782;
	BIT_VEC cppVar_27783 = PC + 1;
	cppVar_27783 = (cppVar_27783 & cppMask_un_16_);
	BIT_VEC cppVar_27784 = ROM.rd(cppVar_27783);
	BIT_VEC cppVar_27785 = (cppVar_27784 >> 7) & cppMask_un_1_;
	bool cppVar_27786 = (cppVar_27785 == 1);
	if (cppVar_27786) {
	BIT_VEC cppVar_27787 = PC + 1;
	cppVar_27787 = (cppVar_27787 & cppMask_un_16_);
	BIT_VEC cppVar_27788 = ROM.rd(cppVar_27787);
	BIT_VEC cppVar_27789 = (cppVar_27788 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27790 = (cppVar_27789 << 3) | 0;
	cppVar_27790 = (cppVar_27790 & cppMask_un_8_);
	cppVar_27782 = cppVar_27790;
	} else {
	BIT_VEC cppVar_27791 = PC + 1;
	cppVar_27791 = (cppVar_27791 & cppMask_un_16_);
	BIT_VEC cppVar_27792 = ROM.rd(cppVar_27791);
	BIT_VEC cppVar_27793 = (cppVar_27792 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27794 = (cppVar_27793 & cppMask_un_5_);
	BIT_VEC cppVar_27795 = cppVar_27794 + 32;
	cppVar_27795 = (cppVar_27795 & cppMask_un_8_);
	cppVar_27782 = cppVar_27795;
	}
	bool cppVar_27797 = (cppVar_27782 == 141);
	if (cppVar_27797) {
	cppVar_27781 = TH1;
	} else {
	BIT_VEC cppVar_27798;
	BIT_VEC cppVar_27799;
	BIT_VEC cppVar_27800 = PC + 1;
	cppVar_27800 = (cppVar_27800 & cppMask_un_16_);
	BIT_VEC cppVar_27801 = ROM.rd(cppVar_27800);
	BIT_VEC cppVar_27802 = (cppVar_27801 >> 7) & cppMask_un_1_;
	bool cppVar_27803 = (cppVar_27802 == 1);
	if (cppVar_27803) {
	BIT_VEC cppVar_27804 = PC + 1;
	cppVar_27804 = (cppVar_27804 & cppMask_un_16_);
	BIT_VEC cppVar_27805 = ROM.rd(cppVar_27804);
	BIT_VEC cppVar_27806 = (cppVar_27805 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27807 = (cppVar_27806 << 3) | 0;
	cppVar_27807 = (cppVar_27807 & cppMask_un_8_);
	cppVar_27799 = cppVar_27807;
	} else {
	BIT_VEC cppVar_27808 = PC + 1;
	cppVar_27808 = (cppVar_27808 & cppMask_un_16_);
	BIT_VEC cppVar_27809 = ROM.rd(cppVar_27808);
	BIT_VEC cppVar_27810 = (cppVar_27809 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27811 = (cppVar_27810 & cppMask_un_5_);
	BIT_VEC cppVar_27812 = cppVar_27811 + 32;
	cppVar_27812 = (cppVar_27812 & cppMask_un_8_);
	cppVar_27799 = cppVar_27812;
	}
	bool cppVar_27814 = (cppVar_27799 == 144);
	if (cppVar_27814) {
	cppVar_27798 = P1;
	} else {
	BIT_VEC cppVar_27815;
	BIT_VEC cppVar_27816;
	BIT_VEC cppVar_27817 = PC + 1;
	cppVar_27817 = (cppVar_27817 & cppMask_un_16_);
	BIT_VEC cppVar_27818 = ROM.rd(cppVar_27817);
	BIT_VEC cppVar_27819 = (cppVar_27818 >> 7) & cppMask_un_1_;
	bool cppVar_27820 = (cppVar_27819 == 1);
	if (cppVar_27820) {
	BIT_VEC cppVar_27821 = PC + 1;
	cppVar_27821 = (cppVar_27821 & cppMask_un_16_);
	BIT_VEC cppVar_27822 = ROM.rd(cppVar_27821);
	BIT_VEC cppVar_27823 = (cppVar_27822 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27824 = (cppVar_27823 << 3) | 0;
	cppVar_27824 = (cppVar_27824 & cppMask_un_8_);
	cppVar_27816 = cppVar_27824;
	} else {
	BIT_VEC cppVar_27825 = PC + 1;
	cppVar_27825 = (cppVar_27825 & cppMask_un_16_);
	BIT_VEC cppVar_27826 = ROM.rd(cppVar_27825);
	BIT_VEC cppVar_27827 = (cppVar_27826 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27828 = (cppVar_27827 & cppMask_un_5_);
	BIT_VEC cppVar_27829 = cppVar_27828 + 32;
	cppVar_27829 = (cppVar_27829 & cppMask_un_8_);
	cppVar_27816 = cppVar_27829;
	}
	bool cppVar_27831 = (cppVar_27816 == 152);
	if (cppVar_27831) {
	cppVar_27815 = SCON;
	} else {
	BIT_VEC cppVar_27832;
	BIT_VEC cppVar_27833;
	BIT_VEC cppVar_27834 = PC + 1;
	cppVar_27834 = (cppVar_27834 & cppMask_un_16_);
	BIT_VEC cppVar_27835 = ROM.rd(cppVar_27834);
	BIT_VEC cppVar_27836 = (cppVar_27835 >> 7) & cppMask_un_1_;
	bool cppVar_27837 = (cppVar_27836 == 1);
	if (cppVar_27837) {
	BIT_VEC cppVar_27838 = PC + 1;
	cppVar_27838 = (cppVar_27838 & cppMask_un_16_);
	BIT_VEC cppVar_27839 = ROM.rd(cppVar_27838);
	BIT_VEC cppVar_27840 = (cppVar_27839 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27841 = (cppVar_27840 << 3) | 0;
	cppVar_27841 = (cppVar_27841 & cppMask_un_8_);
	cppVar_27833 = cppVar_27841;
	} else {
	BIT_VEC cppVar_27842 = PC + 1;
	cppVar_27842 = (cppVar_27842 & cppMask_un_16_);
	BIT_VEC cppVar_27843 = ROM.rd(cppVar_27842);
	BIT_VEC cppVar_27844 = (cppVar_27843 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27845 = (cppVar_27844 & cppMask_un_5_);
	BIT_VEC cppVar_27846 = cppVar_27845 + 32;
	cppVar_27846 = (cppVar_27846 & cppMask_un_8_);
	cppVar_27833 = cppVar_27846;
	}
	bool cppVar_27848 = (cppVar_27833 == 153);
	if (cppVar_27848) {
	cppVar_27832 = SBUF;
	} else {
	BIT_VEC cppVar_27849;
	BIT_VEC cppVar_27850;
	BIT_VEC cppVar_27851 = PC + 1;
	cppVar_27851 = (cppVar_27851 & cppMask_un_16_);
	BIT_VEC cppVar_27852 = ROM.rd(cppVar_27851);
	BIT_VEC cppVar_27853 = (cppVar_27852 >> 7) & cppMask_un_1_;
	bool cppVar_27854 = (cppVar_27853 == 1);
	if (cppVar_27854) {
	BIT_VEC cppVar_27855 = PC + 1;
	cppVar_27855 = (cppVar_27855 & cppMask_un_16_);
	BIT_VEC cppVar_27856 = ROM.rd(cppVar_27855);
	BIT_VEC cppVar_27857 = (cppVar_27856 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27858 = (cppVar_27857 << 3) | 0;
	cppVar_27858 = (cppVar_27858 & cppMask_un_8_);
	cppVar_27850 = cppVar_27858;
	} else {
	BIT_VEC cppVar_27859 = PC + 1;
	cppVar_27859 = (cppVar_27859 & cppMask_un_16_);
	BIT_VEC cppVar_27860 = ROM.rd(cppVar_27859);
	BIT_VEC cppVar_27861 = (cppVar_27860 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27862 = (cppVar_27861 & cppMask_un_5_);
	BIT_VEC cppVar_27863 = cppVar_27862 + 32;
	cppVar_27863 = (cppVar_27863 & cppMask_un_8_);
	cppVar_27850 = cppVar_27863;
	}
	bool cppVar_27865 = (cppVar_27850 == 160);
	if (cppVar_27865) {
	cppVar_27849 = P2;
	} else {
	BIT_VEC cppVar_27866;
	BIT_VEC cppVar_27867;
	BIT_VEC cppVar_27868 = PC + 1;
	cppVar_27868 = (cppVar_27868 & cppMask_un_16_);
	BIT_VEC cppVar_27869 = ROM.rd(cppVar_27868);
	BIT_VEC cppVar_27870 = (cppVar_27869 >> 7) & cppMask_un_1_;
	bool cppVar_27871 = (cppVar_27870 == 1);
	if (cppVar_27871) {
	BIT_VEC cppVar_27872 = PC + 1;
	cppVar_27872 = (cppVar_27872 & cppMask_un_16_);
	BIT_VEC cppVar_27873 = ROM.rd(cppVar_27872);
	BIT_VEC cppVar_27874 = (cppVar_27873 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27875 = (cppVar_27874 << 3) | 0;
	cppVar_27875 = (cppVar_27875 & cppMask_un_8_);
	cppVar_27867 = cppVar_27875;
	} else {
	BIT_VEC cppVar_27876 = PC + 1;
	cppVar_27876 = (cppVar_27876 & cppMask_un_16_);
	BIT_VEC cppVar_27877 = ROM.rd(cppVar_27876);
	BIT_VEC cppVar_27878 = (cppVar_27877 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27879 = (cppVar_27878 & cppMask_un_5_);
	BIT_VEC cppVar_27880 = cppVar_27879 + 32;
	cppVar_27880 = (cppVar_27880 & cppMask_un_8_);
	cppVar_27867 = cppVar_27880;
	}
	bool cppVar_27882 = (cppVar_27867 == 168);
	if (cppVar_27882) {
	cppVar_27866 = IE;
	} else {
	BIT_VEC cppVar_27883;
	BIT_VEC cppVar_27884;
	BIT_VEC cppVar_27885 = PC + 1;
	cppVar_27885 = (cppVar_27885 & cppMask_un_16_);
	BIT_VEC cppVar_27886 = ROM.rd(cppVar_27885);
	BIT_VEC cppVar_27887 = (cppVar_27886 >> 7) & cppMask_un_1_;
	bool cppVar_27888 = (cppVar_27887 == 1);
	if (cppVar_27888) {
	BIT_VEC cppVar_27889 = PC + 1;
	cppVar_27889 = (cppVar_27889 & cppMask_un_16_);
	BIT_VEC cppVar_27890 = ROM.rd(cppVar_27889);
	BIT_VEC cppVar_27891 = (cppVar_27890 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27892 = (cppVar_27891 << 3) | 0;
	cppVar_27892 = (cppVar_27892 & cppMask_un_8_);
	cppVar_27884 = cppVar_27892;
	} else {
	BIT_VEC cppVar_27893 = PC + 1;
	cppVar_27893 = (cppVar_27893 & cppMask_un_16_);
	BIT_VEC cppVar_27894 = ROM.rd(cppVar_27893);
	BIT_VEC cppVar_27895 = (cppVar_27894 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27896 = (cppVar_27895 & cppMask_un_5_);
	BIT_VEC cppVar_27897 = cppVar_27896 + 32;
	cppVar_27897 = (cppVar_27897 & cppMask_un_8_);
	cppVar_27884 = cppVar_27897;
	}
	bool cppVar_27899 = (cppVar_27884 == 176);
	if (cppVar_27899) {
	cppVar_27883 = P3;
	} else {
	BIT_VEC cppVar_27900;
	BIT_VEC cppVar_27901;
	BIT_VEC cppVar_27902 = PC + 1;
	cppVar_27902 = (cppVar_27902 & cppMask_un_16_);
	BIT_VEC cppVar_27903 = ROM.rd(cppVar_27902);
	BIT_VEC cppVar_27904 = (cppVar_27903 >> 7) & cppMask_un_1_;
	bool cppVar_27905 = (cppVar_27904 == 1);
	if (cppVar_27905) {
	BIT_VEC cppVar_27906 = PC + 1;
	cppVar_27906 = (cppVar_27906 & cppMask_un_16_);
	BIT_VEC cppVar_27907 = ROM.rd(cppVar_27906);
	BIT_VEC cppVar_27908 = (cppVar_27907 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27909 = (cppVar_27908 << 3) | 0;
	cppVar_27909 = (cppVar_27909 & cppMask_un_8_);
	cppVar_27901 = cppVar_27909;
	} else {
	BIT_VEC cppVar_27910 = PC + 1;
	cppVar_27910 = (cppVar_27910 & cppMask_un_16_);
	BIT_VEC cppVar_27911 = ROM.rd(cppVar_27910);
	BIT_VEC cppVar_27912 = (cppVar_27911 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27913 = (cppVar_27912 & cppMask_un_5_);
	BIT_VEC cppVar_27914 = cppVar_27913 + 32;
	cppVar_27914 = (cppVar_27914 & cppMask_un_8_);
	cppVar_27901 = cppVar_27914;
	}
	bool cppVar_27916 = (cppVar_27901 == 184);
	if (cppVar_27916) {
	cppVar_27900 = IP;
	} else {
	BIT_VEC cppVar_27917;
	BIT_VEC cppVar_27918;
	BIT_VEC cppVar_27919 = PC + 1;
	cppVar_27919 = (cppVar_27919 & cppMask_un_16_);
	BIT_VEC cppVar_27920 = ROM.rd(cppVar_27919);
	BIT_VEC cppVar_27921 = (cppVar_27920 >> 7) & cppMask_un_1_;
	bool cppVar_27922 = (cppVar_27921 == 1);
	if (cppVar_27922) {
	BIT_VEC cppVar_27923 = PC + 1;
	cppVar_27923 = (cppVar_27923 & cppMask_un_16_);
	BIT_VEC cppVar_27924 = ROM.rd(cppVar_27923);
	BIT_VEC cppVar_27925 = (cppVar_27924 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27926 = (cppVar_27925 << 3) | 0;
	cppVar_27926 = (cppVar_27926 & cppMask_un_8_);
	cppVar_27918 = cppVar_27926;
	} else {
	BIT_VEC cppVar_27927 = PC + 1;
	cppVar_27927 = (cppVar_27927 & cppMask_un_16_);
	BIT_VEC cppVar_27928 = ROM.rd(cppVar_27927);
	BIT_VEC cppVar_27929 = (cppVar_27928 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27930 = (cppVar_27929 & cppMask_un_5_);
	BIT_VEC cppVar_27931 = cppVar_27930 + 32;
	cppVar_27931 = (cppVar_27931 & cppMask_un_8_);
	cppVar_27918 = cppVar_27931;
	}
	bool cppVar_27933 = (cppVar_27918 == 208);
	if (cppVar_27933) {
	cppVar_27917 = PSW;
	} else {
	BIT_VEC cppVar_27934;
	BIT_VEC cppVar_27935;
	BIT_VEC cppVar_27936 = PC + 1;
	cppVar_27936 = (cppVar_27936 & cppMask_un_16_);
	BIT_VEC cppVar_27937 = ROM.rd(cppVar_27936);
	BIT_VEC cppVar_27938 = (cppVar_27937 >> 7) & cppMask_un_1_;
	bool cppVar_27939 = (cppVar_27938 == 1);
	if (cppVar_27939) {
	BIT_VEC cppVar_27940 = PC + 1;
	cppVar_27940 = (cppVar_27940 & cppMask_un_16_);
	BIT_VEC cppVar_27941 = ROM.rd(cppVar_27940);
	BIT_VEC cppVar_27942 = (cppVar_27941 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27943 = (cppVar_27942 << 3) | 0;
	cppVar_27943 = (cppVar_27943 & cppMask_un_8_);
	cppVar_27935 = cppVar_27943;
	} else {
	BIT_VEC cppVar_27944 = PC + 1;
	cppVar_27944 = (cppVar_27944 & cppMask_un_16_);
	BIT_VEC cppVar_27945 = ROM.rd(cppVar_27944);
	BIT_VEC cppVar_27946 = (cppVar_27945 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27947 = (cppVar_27946 & cppMask_un_5_);
	BIT_VEC cppVar_27948 = cppVar_27947 + 32;
	cppVar_27948 = (cppVar_27948 & cppMask_un_8_);
	cppVar_27935 = cppVar_27948;
	}
	bool cppVar_27950 = (cppVar_27935 == 224);
	if (cppVar_27950) {
	cppVar_27934 = ACC;
	} else {
	BIT_VEC cppVar_27951;
	BIT_VEC cppVar_27952;
	BIT_VEC cppVar_27953 = PC + 1;
	cppVar_27953 = (cppVar_27953 & cppMask_un_16_);
	BIT_VEC cppVar_27954 = ROM.rd(cppVar_27953);
	BIT_VEC cppVar_27955 = (cppVar_27954 >> 7) & cppMask_un_1_;
	bool cppVar_27956 = (cppVar_27955 == 1);
	if (cppVar_27956) {
	BIT_VEC cppVar_27957 = PC + 1;
	cppVar_27957 = (cppVar_27957 & cppMask_un_16_);
	BIT_VEC cppVar_27958 = ROM.rd(cppVar_27957);
	BIT_VEC cppVar_27959 = (cppVar_27958 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27960 = (cppVar_27959 << 3) | 0;
	cppVar_27960 = (cppVar_27960 & cppMask_un_8_);
	cppVar_27952 = cppVar_27960;
	} else {
	BIT_VEC cppVar_27961 = PC + 1;
	cppVar_27961 = (cppVar_27961 & cppMask_un_16_);
	BIT_VEC cppVar_27962 = ROM.rd(cppVar_27961);
	BIT_VEC cppVar_27963 = (cppVar_27962 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27964 = (cppVar_27963 & cppMask_un_5_);
	BIT_VEC cppVar_27965 = cppVar_27964 + 32;
	cppVar_27965 = (cppVar_27965 & cppMask_un_8_);
	cppVar_27952 = cppVar_27965;
	}
	bool cppVar_27967 = (cppVar_27952 == 240);
	if (cppVar_27967) {
	cppVar_27951 = B;
	} else {
	cppVar_27951 = 0;
	}
	cppVar_27934 = cppVar_27951;
	}
	cppVar_27917 = cppVar_27934;
	}
	cppVar_27900 = cppVar_27917;
	}
	cppVar_27883 = cppVar_27900;
	}
	cppVar_27866 = cppVar_27883;
	}
	cppVar_27849 = cppVar_27866;
	}
	cppVar_27832 = cppVar_27849;
	}
	cppVar_27815 = cppVar_27832;
	}
	cppVar_27798 = cppVar_27815;
	}
	cppVar_27781 = cppVar_27798;
	}
	cppVar_27764 = cppVar_27781;
	}
	cppVar_27747 = cppVar_27764;
	}
	cppVar_27730 = cppVar_27747;
	}
	cppVar_27713 = cppVar_27730;
	}
	cppVar_27696 = cppVar_27713;
	}
	cppVar_27679 = cppVar_27696;
	}
	cppVar_27662 = cppVar_27679;
	}
	cppVar_27645 = cppVar_27662;
	}
	cppVar_27628 = cppVar_27645;
	}
	cppVar_27611 = cppVar_27628;
	}
	cppVar_27578 = cppVar_27611;
	}
	BIT_VEC cppVar_27969 = cppVar_27577 & cppVar_27578;
	BIT_VEC cppVar_27970;
	BIT_VEC cppVar_27971;
	BIT_VEC cppVar_27972 = PC + 1;
	cppVar_27972 = (cppVar_27972 & cppMask_un_16_);
	BIT_VEC cppVar_27973 = ROM.rd(cppVar_27972);
	BIT_VEC cppVar_27974 = (cppVar_27973 >> 7) & cppMask_un_1_;
	bool cppVar_27976 = (cppVar_27974 == 1);
	if (cppVar_27976) {
	BIT_VEC cppVar_27977 = PC + 1;
	cppVar_27977 = (cppVar_27977 & cppMask_un_16_);
	BIT_VEC cppVar_27978 = ROM.rd(cppVar_27977);
	BIT_VEC cppVar_27979 = (cppVar_27978 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27981 = (cppVar_27979 << 3) | 0;
	cppVar_27981 = (cppVar_27981 & cppMask_un_8_);
	cppVar_27971 = cppVar_27981;
	} else {
	BIT_VEC cppVar_27982 = PC + 1;
	cppVar_27982 = (cppVar_27982 & cppMask_un_16_);
	BIT_VEC cppVar_27983 = ROM.rd(cppVar_27982);
	BIT_VEC cppVar_27984 = (cppVar_27983 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27985 = (cppVar_27984 & cppMask_un_5_);
	BIT_VEC cppVar_27987 = cppVar_27985 + 32;
	cppVar_27987 = (cppVar_27987 & cppMask_un_8_);
	cppVar_27971 = cppVar_27987;
	}
	BIT_VEC cppVar_27988 = (cppVar_27971 >> 7) & cppMask_un_1_;
	bool cppVar_27990 = (cppVar_27988 == 0);
	if (cppVar_27990) {
	BIT_VEC cppVar_27991;
	BIT_VEC cppVar_27992 = PC + 1;
	cppVar_27992 = (cppVar_27992 & cppMask_un_16_);
	BIT_VEC cppVar_27993 = ROM.rd(cppVar_27992);
	BIT_VEC cppVar_27994 = (cppVar_27993 >> 7) & cppMask_un_1_;
	bool cppVar_27995 = (cppVar_27994 == 1);
	if (cppVar_27995) {
	BIT_VEC cppVar_27996 = PC + 1;
	cppVar_27996 = (cppVar_27996 & cppMask_un_16_);
	BIT_VEC cppVar_27997 = ROM.rd(cppVar_27996);
	BIT_VEC cppVar_27998 = (cppVar_27997 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_27999 = (cppVar_27998 << 3) | 0;
	cppVar_27999 = (cppVar_27999 & cppMask_un_8_);
	cppVar_27991 = cppVar_27999;
	} else {
	BIT_VEC cppVar_28000 = PC + 1;
	cppVar_28000 = (cppVar_28000 & cppMask_un_16_);
	BIT_VEC cppVar_28001 = ROM.rd(cppVar_28000);
	BIT_VEC cppVar_28002 = (cppVar_28001 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28003 = (cppVar_28002 & cppMask_un_5_);
	BIT_VEC cppVar_28004 = cppVar_28003 + 32;
	cppVar_28004 = (cppVar_28004 & cppMask_un_8_);
	cppVar_27991 = cppVar_28004;
	}
	BIT_VEC cppVar_28005 = IRAM.rd(cppVar_27991);
	cppVar_27970 = cppVar_28005;
	} else {
	BIT_VEC cppVar_28006;
	BIT_VEC cppVar_28007;
	BIT_VEC cppVar_28008 = PC + 1;
	cppVar_28008 = (cppVar_28008 & cppMask_un_16_);
	BIT_VEC cppVar_28009 = ROM.rd(cppVar_28008);
	BIT_VEC cppVar_28010 = (cppVar_28009 >> 7) & cppMask_un_1_;
	bool cppVar_28011 = (cppVar_28010 == 1);
	if (cppVar_28011) {
	BIT_VEC cppVar_28012 = PC + 1;
	cppVar_28012 = (cppVar_28012 & cppMask_un_16_);
	BIT_VEC cppVar_28013 = ROM.rd(cppVar_28012);
	BIT_VEC cppVar_28014 = (cppVar_28013 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28015 = (cppVar_28014 << 3) | 0;
	cppVar_28015 = (cppVar_28015 & cppMask_un_8_);
	cppVar_28007 = cppVar_28015;
	} else {
	BIT_VEC cppVar_28016 = PC + 1;
	cppVar_28016 = (cppVar_28016 & cppMask_un_16_);
	BIT_VEC cppVar_28017 = ROM.rd(cppVar_28016);
	BIT_VEC cppVar_28018 = (cppVar_28017 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28019 = (cppVar_28018 & cppMask_un_5_);
	BIT_VEC cppVar_28020 = cppVar_28019 + 32;
	cppVar_28020 = (cppVar_28020 & cppMask_un_8_);
	cppVar_28007 = cppVar_28020;
	}
	bool cppVar_28022 = (cppVar_28007 == 128);
	if (cppVar_28022) {
	cppVar_28006 = P0;
	} else {
	BIT_VEC cppVar_28023;
	BIT_VEC cppVar_28024;
	BIT_VEC cppVar_28025 = PC + 1;
	cppVar_28025 = (cppVar_28025 & cppMask_un_16_);
	BIT_VEC cppVar_28026 = ROM.rd(cppVar_28025);
	BIT_VEC cppVar_28027 = (cppVar_28026 >> 7) & cppMask_un_1_;
	bool cppVar_28028 = (cppVar_28027 == 1);
	if (cppVar_28028) {
	BIT_VEC cppVar_28029 = PC + 1;
	cppVar_28029 = (cppVar_28029 & cppMask_un_16_);
	BIT_VEC cppVar_28030 = ROM.rd(cppVar_28029);
	BIT_VEC cppVar_28031 = (cppVar_28030 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28032 = (cppVar_28031 << 3) | 0;
	cppVar_28032 = (cppVar_28032 & cppMask_un_8_);
	cppVar_28024 = cppVar_28032;
	} else {
	BIT_VEC cppVar_28033 = PC + 1;
	cppVar_28033 = (cppVar_28033 & cppMask_un_16_);
	BIT_VEC cppVar_28034 = ROM.rd(cppVar_28033);
	BIT_VEC cppVar_28035 = (cppVar_28034 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28036 = (cppVar_28035 & cppMask_un_5_);
	BIT_VEC cppVar_28037 = cppVar_28036 + 32;
	cppVar_28037 = (cppVar_28037 & cppMask_un_8_);
	cppVar_28024 = cppVar_28037;
	}
	bool cppVar_28039 = (cppVar_28024 == 129);
	if (cppVar_28039) {
	cppVar_28023 = SP;
	} else {
	BIT_VEC cppVar_28040;
	BIT_VEC cppVar_28041;
	BIT_VEC cppVar_28042 = PC + 1;
	cppVar_28042 = (cppVar_28042 & cppMask_un_16_);
	BIT_VEC cppVar_28043 = ROM.rd(cppVar_28042);
	BIT_VEC cppVar_28044 = (cppVar_28043 >> 7) & cppMask_un_1_;
	bool cppVar_28045 = (cppVar_28044 == 1);
	if (cppVar_28045) {
	BIT_VEC cppVar_28046 = PC + 1;
	cppVar_28046 = (cppVar_28046 & cppMask_un_16_);
	BIT_VEC cppVar_28047 = ROM.rd(cppVar_28046);
	BIT_VEC cppVar_28048 = (cppVar_28047 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28049 = (cppVar_28048 << 3) | 0;
	cppVar_28049 = (cppVar_28049 & cppMask_un_8_);
	cppVar_28041 = cppVar_28049;
	} else {
	BIT_VEC cppVar_28050 = PC + 1;
	cppVar_28050 = (cppVar_28050 & cppMask_un_16_);
	BIT_VEC cppVar_28051 = ROM.rd(cppVar_28050);
	BIT_VEC cppVar_28052 = (cppVar_28051 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28053 = (cppVar_28052 & cppMask_un_5_);
	BIT_VEC cppVar_28054 = cppVar_28053 + 32;
	cppVar_28054 = (cppVar_28054 & cppMask_un_8_);
	cppVar_28041 = cppVar_28054;
	}
	bool cppVar_28056 = (cppVar_28041 == 130);
	if (cppVar_28056) {
	cppVar_28040 = DPL;
	} else {
	BIT_VEC cppVar_28057;
	BIT_VEC cppVar_28058;
	BIT_VEC cppVar_28059 = PC + 1;
	cppVar_28059 = (cppVar_28059 & cppMask_un_16_);
	BIT_VEC cppVar_28060 = ROM.rd(cppVar_28059);
	BIT_VEC cppVar_28061 = (cppVar_28060 >> 7) & cppMask_un_1_;
	bool cppVar_28062 = (cppVar_28061 == 1);
	if (cppVar_28062) {
	BIT_VEC cppVar_28063 = PC + 1;
	cppVar_28063 = (cppVar_28063 & cppMask_un_16_);
	BIT_VEC cppVar_28064 = ROM.rd(cppVar_28063);
	BIT_VEC cppVar_28065 = (cppVar_28064 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28066 = (cppVar_28065 << 3) | 0;
	cppVar_28066 = (cppVar_28066 & cppMask_un_8_);
	cppVar_28058 = cppVar_28066;
	} else {
	BIT_VEC cppVar_28067 = PC + 1;
	cppVar_28067 = (cppVar_28067 & cppMask_un_16_);
	BIT_VEC cppVar_28068 = ROM.rd(cppVar_28067);
	BIT_VEC cppVar_28069 = (cppVar_28068 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28070 = (cppVar_28069 & cppMask_un_5_);
	BIT_VEC cppVar_28071 = cppVar_28070 + 32;
	cppVar_28071 = (cppVar_28071 & cppMask_un_8_);
	cppVar_28058 = cppVar_28071;
	}
	bool cppVar_28073 = (cppVar_28058 == 131);
	if (cppVar_28073) {
	cppVar_28057 = DPH;
	} else {
	BIT_VEC cppVar_28074;
	BIT_VEC cppVar_28075;
	BIT_VEC cppVar_28076 = PC + 1;
	cppVar_28076 = (cppVar_28076 & cppMask_un_16_);
	BIT_VEC cppVar_28077 = ROM.rd(cppVar_28076);
	BIT_VEC cppVar_28078 = (cppVar_28077 >> 7) & cppMask_un_1_;
	bool cppVar_28079 = (cppVar_28078 == 1);
	if (cppVar_28079) {
	BIT_VEC cppVar_28080 = PC + 1;
	cppVar_28080 = (cppVar_28080 & cppMask_un_16_);
	BIT_VEC cppVar_28081 = ROM.rd(cppVar_28080);
	BIT_VEC cppVar_28082 = (cppVar_28081 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28083 = (cppVar_28082 << 3) | 0;
	cppVar_28083 = (cppVar_28083 & cppMask_un_8_);
	cppVar_28075 = cppVar_28083;
	} else {
	BIT_VEC cppVar_28084 = PC + 1;
	cppVar_28084 = (cppVar_28084 & cppMask_un_16_);
	BIT_VEC cppVar_28085 = ROM.rd(cppVar_28084);
	BIT_VEC cppVar_28086 = (cppVar_28085 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28087 = (cppVar_28086 & cppMask_un_5_);
	BIT_VEC cppVar_28088 = cppVar_28087 + 32;
	cppVar_28088 = (cppVar_28088 & cppMask_un_8_);
	cppVar_28075 = cppVar_28088;
	}
	bool cppVar_28090 = (cppVar_28075 == 135);
	if (cppVar_28090) {
	cppVar_28074 = PCON;
	} else {
	BIT_VEC cppVar_28091;
	BIT_VEC cppVar_28092;
	BIT_VEC cppVar_28093 = PC + 1;
	cppVar_28093 = (cppVar_28093 & cppMask_un_16_);
	BIT_VEC cppVar_28094 = ROM.rd(cppVar_28093);
	BIT_VEC cppVar_28095 = (cppVar_28094 >> 7) & cppMask_un_1_;
	bool cppVar_28096 = (cppVar_28095 == 1);
	if (cppVar_28096) {
	BIT_VEC cppVar_28097 = PC + 1;
	cppVar_28097 = (cppVar_28097 & cppMask_un_16_);
	BIT_VEC cppVar_28098 = ROM.rd(cppVar_28097);
	BIT_VEC cppVar_28099 = (cppVar_28098 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28100 = (cppVar_28099 << 3) | 0;
	cppVar_28100 = (cppVar_28100 & cppMask_un_8_);
	cppVar_28092 = cppVar_28100;
	} else {
	BIT_VEC cppVar_28101 = PC + 1;
	cppVar_28101 = (cppVar_28101 & cppMask_un_16_);
	BIT_VEC cppVar_28102 = ROM.rd(cppVar_28101);
	BIT_VEC cppVar_28103 = (cppVar_28102 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28104 = (cppVar_28103 & cppMask_un_5_);
	BIT_VEC cppVar_28105 = cppVar_28104 + 32;
	cppVar_28105 = (cppVar_28105 & cppMask_un_8_);
	cppVar_28092 = cppVar_28105;
	}
	bool cppVar_28107 = (cppVar_28092 == 136);
	if (cppVar_28107) {
	cppVar_28091 = TCON;
	} else {
	BIT_VEC cppVar_28108;
	BIT_VEC cppVar_28109;
	BIT_VEC cppVar_28110 = PC + 1;
	cppVar_28110 = (cppVar_28110 & cppMask_un_16_);
	BIT_VEC cppVar_28111 = ROM.rd(cppVar_28110);
	BIT_VEC cppVar_28112 = (cppVar_28111 >> 7) & cppMask_un_1_;
	bool cppVar_28113 = (cppVar_28112 == 1);
	if (cppVar_28113) {
	BIT_VEC cppVar_28114 = PC + 1;
	cppVar_28114 = (cppVar_28114 & cppMask_un_16_);
	BIT_VEC cppVar_28115 = ROM.rd(cppVar_28114);
	BIT_VEC cppVar_28116 = (cppVar_28115 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28117 = (cppVar_28116 << 3) | 0;
	cppVar_28117 = (cppVar_28117 & cppMask_un_8_);
	cppVar_28109 = cppVar_28117;
	} else {
	BIT_VEC cppVar_28118 = PC + 1;
	cppVar_28118 = (cppVar_28118 & cppMask_un_16_);
	BIT_VEC cppVar_28119 = ROM.rd(cppVar_28118);
	BIT_VEC cppVar_28120 = (cppVar_28119 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28121 = (cppVar_28120 & cppMask_un_5_);
	BIT_VEC cppVar_28122 = cppVar_28121 + 32;
	cppVar_28122 = (cppVar_28122 & cppMask_un_8_);
	cppVar_28109 = cppVar_28122;
	}
	bool cppVar_28124 = (cppVar_28109 == 137);
	if (cppVar_28124) {
	cppVar_28108 = TMOD;
	} else {
	BIT_VEC cppVar_28125;
	BIT_VEC cppVar_28126;
	BIT_VEC cppVar_28127 = PC + 1;
	cppVar_28127 = (cppVar_28127 & cppMask_un_16_);
	BIT_VEC cppVar_28128 = ROM.rd(cppVar_28127);
	BIT_VEC cppVar_28129 = (cppVar_28128 >> 7) & cppMask_un_1_;
	bool cppVar_28130 = (cppVar_28129 == 1);
	if (cppVar_28130) {
	BIT_VEC cppVar_28131 = PC + 1;
	cppVar_28131 = (cppVar_28131 & cppMask_un_16_);
	BIT_VEC cppVar_28132 = ROM.rd(cppVar_28131);
	BIT_VEC cppVar_28133 = (cppVar_28132 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28134 = (cppVar_28133 << 3) | 0;
	cppVar_28134 = (cppVar_28134 & cppMask_un_8_);
	cppVar_28126 = cppVar_28134;
	} else {
	BIT_VEC cppVar_28135 = PC + 1;
	cppVar_28135 = (cppVar_28135 & cppMask_un_16_);
	BIT_VEC cppVar_28136 = ROM.rd(cppVar_28135);
	BIT_VEC cppVar_28137 = (cppVar_28136 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28138 = (cppVar_28137 & cppMask_un_5_);
	BIT_VEC cppVar_28139 = cppVar_28138 + 32;
	cppVar_28139 = (cppVar_28139 & cppMask_un_8_);
	cppVar_28126 = cppVar_28139;
	}
	bool cppVar_28141 = (cppVar_28126 == 138);
	if (cppVar_28141) {
	cppVar_28125 = TL0;
	} else {
	BIT_VEC cppVar_28142;
	BIT_VEC cppVar_28143;
	BIT_VEC cppVar_28144 = PC + 1;
	cppVar_28144 = (cppVar_28144 & cppMask_un_16_);
	BIT_VEC cppVar_28145 = ROM.rd(cppVar_28144);
	BIT_VEC cppVar_28146 = (cppVar_28145 >> 7) & cppMask_un_1_;
	bool cppVar_28147 = (cppVar_28146 == 1);
	if (cppVar_28147) {
	BIT_VEC cppVar_28148 = PC + 1;
	cppVar_28148 = (cppVar_28148 & cppMask_un_16_);
	BIT_VEC cppVar_28149 = ROM.rd(cppVar_28148);
	BIT_VEC cppVar_28150 = (cppVar_28149 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28151 = (cppVar_28150 << 3) | 0;
	cppVar_28151 = (cppVar_28151 & cppMask_un_8_);
	cppVar_28143 = cppVar_28151;
	} else {
	BIT_VEC cppVar_28152 = PC + 1;
	cppVar_28152 = (cppVar_28152 & cppMask_un_16_);
	BIT_VEC cppVar_28153 = ROM.rd(cppVar_28152);
	BIT_VEC cppVar_28154 = (cppVar_28153 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28155 = (cppVar_28154 & cppMask_un_5_);
	BIT_VEC cppVar_28156 = cppVar_28155 + 32;
	cppVar_28156 = (cppVar_28156 & cppMask_un_8_);
	cppVar_28143 = cppVar_28156;
	}
	bool cppVar_28158 = (cppVar_28143 == 140);
	if (cppVar_28158) {
	cppVar_28142 = TH0;
	} else {
	BIT_VEC cppVar_28159;
	BIT_VEC cppVar_28160;
	BIT_VEC cppVar_28161 = PC + 1;
	cppVar_28161 = (cppVar_28161 & cppMask_un_16_);
	BIT_VEC cppVar_28162 = ROM.rd(cppVar_28161);
	BIT_VEC cppVar_28163 = (cppVar_28162 >> 7) & cppMask_un_1_;
	bool cppVar_28164 = (cppVar_28163 == 1);
	if (cppVar_28164) {
	BIT_VEC cppVar_28165 = PC + 1;
	cppVar_28165 = (cppVar_28165 & cppMask_un_16_);
	BIT_VEC cppVar_28166 = ROM.rd(cppVar_28165);
	BIT_VEC cppVar_28167 = (cppVar_28166 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28168 = (cppVar_28167 << 3) | 0;
	cppVar_28168 = (cppVar_28168 & cppMask_un_8_);
	cppVar_28160 = cppVar_28168;
	} else {
	BIT_VEC cppVar_28169 = PC + 1;
	cppVar_28169 = (cppVar_28169 & cppMask_un_16_);
	BIT_VEC cppVar_28170 = ROM.rd(cppVar_28169);
	BIT_VEC cppVar_28171 = (cppVar_28170 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28172 = (cppVar_28171 & cppMask_un_5_);
	BIT_VEC cppVar_28173 = cppVar_28172 + 32;
	cppVar_28173 = (cppVar_28173 & cppMask_un_8_);
	cppVar_28160 = cppVar_28173;
	}
	bool cppVar_28175 = (cppVar_28160 == 139);
	if (cppVar_28175) {
	cppVar_28159 = TL1;
	} else {
	BIT_VEC cppVar_28176;
	BIT_VEC cppVar_28177;
	BIT_VEC cppVar_28178 = PC + 1;
	cppVar_28178 = (cppVar_28178 & cppMask_un_16_);
	BIT_VEC cppVar_28179 = ROM.rd(cppVar_28178);
	BIT_VEC cppVar_28180 = (cppVar_28179 >> 7) & cppMask_un_1_;
	bool cppVar_28181 = (cppVar_28180 == 1);
	if (cppVar_28181) {
	BIT_VEC cppVar_28182 = PC + 1;
	cppVar_28182 = (cppVar_28182 & cppMask_un_16_);
	BIT_VEC cppVar_28183 = ROM.rd(cppVar_28182);
	BIT_VEC cppVar_28184 = (cppVar_28183 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28185 = (cppVar_28184 << 3) | 0;
	cppVar_28185 = (cppVar_28185 & cppMask_un_8_);
	cppVar_28177 = cppVar_28185;
	} else {
	BIT_VEC cppVar_28186 = PC + 1;
	cppVar_28186 = (cppVar_28186 & cppMask_un_16_);
	BIT_VEC cppVar_28187 = ROM.rd(cppVar_28186);
	BIT_VEC cppVar_28188 = (cppVar_28187 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28189 = (cppVar_28188 & cppMask_un_5_);
	BIT_VEC cppVar_28190 = cppVar_28189 + 32;
	cppVar_28190 = (cppVar_28190 & cppMask_un_8_);
	cppVar_28177 = cppVar_28190;
	}
	bool cppVar_28192 = (cppVar_28177 == 141);
	if (cppVar_28192) {
	cppVar_28176 = TH1;
	} else {
	BIT_VEC cppVar_28193;
	BIT_VEC cppVar_28194;
	BIT_VEC cppVar_28195 = PC + 1;
	cppVar_28195 = (cppVar_28195 & cppMask_un_16_);
	BIT_VEC cppVar_28196 = ROM.rd(cppVar_28195);
	BIT_VEC cppVar_28197 = (cppVar_28196 >> 7) & cppMask_un_1_;
	bool cppVar_28198 = (cppVar_28197 == 1);
	if (cppVar_28198) {
	BIT_VEC cppVar_28199 = PC + 1;
	cppVar_28199 = (cppVar_28199 & cppMask_un_16_);
	BIT_VEC cppVar_28200 = ROM.rd(cppVar_28199);
	BIT_VEC cppVar_28201 = (cppVar_28200 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28202 = (cppVar_28201 << 3) | 0;
	cppVar_28202 = (cppVar_28202 & cppMask_un_8_);
	cppVar_28194 = cppVar_28202;
	} else {
	BIT_VEC cppVar_28203 = PC + 1;
	cppVar_28203 = (cppVar_28203 & cppMask_un_16_);
	BIT_VEC cppVar_28204 = ROM.rd(cppVar_28203);
	BIT_VEC cppVar_28205 = (cppVar_28204 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28206 = (cppVar_28205 & cppMask_un_5_);
	BIT_VEC cppVar_28207 = cppVar_28206 + 32;
	cppVar_28207 = (cppVar_28207 & cppMask_un_8_);
	cppVar_28194 = cppVar_28207;
	}
	bool cppVar_28209 = (cppVar_28194 == 144);
	if (cppVar_28209) {
	cppVar_28193 = P1;
	} else {
	BIT_VEC cppVar_28210;
	BIT_VEC cppVar_28211;
	BIT_VEC cppVar_28212 = PC + 1;
	cppVar_28212 = (cppVar_28212 & cppMask_un_16_);
	BIT_VEC cppVar_28213 = ROM.rd(cppVar_28212);
	BIT_VEC cppVar_28214 = (cppVar_28213 >> 7) & cppMask_un_1_;
	bool cppVar_28215 = (cppVar_28214 == 1);
	if (cppVar_28215) {
	BIT_VEC cppVar_28216 = PC + 1;
	cppVar_28216 = (cppVar_28216 & cppMask_un_16_);
	BIT_VEC cppVar_28217 = ROM.rd(cppVar_28216);
	BIT_VEC cppVar_28218 = (cppVar_28217 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28219 = (cppVar_28218 << 3) | 0;
	cppVar_28219 = (cppVar_28219 & cppMask_un_8_);
	cppVar_28211 = cppVar_28219;
	} else {
	BIT_VEC cppVar_28220 = PC + 1;
	cppVar_28220 = (cppVar_28220 & cppMask_un_16_);
	BIT_VEC cppVar_28221 = ROM.rd(cppVar_28220);
	BIT_VEC cppVar_28222 = (cppVar_28221 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28223 = (cppVar_28222 & cppMask_un_5_);
	BIT_VEC cppVar_28224 = cppVar_28223 + 32;
	cppVar_28224 = (cppVar_28224 & cppMask_un_8_);
	cppVar_28211 = cppVar_28224;
	}
	bool cppVar_28226 = (cppVar_28211 == 152);
	if (cppVar_28226) {
	cppVar_28210 = SCON;
	} else {
	BIT_VEC cppVar_28227;
	BIT_VEC cppVar_28228;
	BIT_VEC cppVar_28229 = PC + 1;
	cppVar_28229 = (cppVar_28229 & cppMask_un_16_);
	BIT_VEC cppVar_28230 = ROM.rd(cppVar_28229);
	BIT_VEC cppVar_28231 = (cppVar_28230 >> 7) & cppMask_un_1_;
	bool cppVar_28232 = (cppVar_28231 == 1);
	if (cppVar_28232) {
	BIT_VEC cppVar_28233 = PC + 1;
	cppVar_28233 = (cppVar_28233 & cppMask_un_16_);
	BIT_VEC cppVar_28234 = ROM.rd(cppVar_28233);
	BIT_VEC cppVar_28235 = (cppVar_28234 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28236 = (cppVar_28235 << 3) | 0;
	cppVar_28236 = (cppVar_28236 & cppMask_un_8_);
	cppVar_28228 = cppVar_28236;
	} else {
	BIT_VEC cppVar_28237 = PC + 1;
	cppVar_28237 = (cppVar_28237 & cppMask_un_16_);
	BIT_VEC cppVar_28238 = ROM.rd(cppVar_28237);
	BIT_VEC cppVar_28239 = (cppVar_28238 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28240 = (cppVar_28239 & cppMask_un_5_);
	BIT_VEC cppVar_28241 = cppVar_28240 + 32;
	cppVar_28241 = (cppVar_28241 & cppMask_un_8_);
	cppVar_28228 = cppVar_28241;
	}
	bool cppVar_28243 = (cppVar_28228 == 153);
	if (cppVar_28243) {
	cppVar_28227 = SBUF;
	} else {
	BIT_VEC cppVar_28244;
	BIT_VEC cppVar_28245;
	BIT_VEC cppVar_28246 = PC + 1;
	cppVar_28246 = (cppVar_28246 & cppMask_un_16_);
	BIT_VEC cppVar_28247 = ROM.rd(cppVar_28246);
	BIT_VEC cppVar_28248 = (cppVar_28247 >> 7) & cppMask_un_1_;
	bool cppVar_28249 = (cppVar_28248 == 1);
	if (cppVar_28249) {
	BIT_VEC cppVar_28250 = PC + 1;
	cppVar_28250 = (cppVar_28250 & cppMask_un_16_);
	BIT_VEC cppVar_28251 = ROM.rd(cppVar_28250);
	BIT_VEC cppVar_28252 = (cppVar_28251 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28253 = (cppVar_28252 << 3) | 0;
	cppVar_28253 = (cppVar_28253 & cppMask_un_8_);
	cppVar_28245 = cppVar_28253;
	} else {
	BIT_VEC cppVar_28254 = PC + 1;
	cppVar_28254 = (cppVar_28254 & cppMask_un_16_);
	BIT_VEC cppVar_28255 = ROM.rd(cppVar_28254);
	BIT_VEC cppVar_28256 = (cppVar_28255 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28257 = (cppVar_28256 & cppMask_un_5_);
	BIT_VEC cppVar_28258 = cppVar_28257 + 32;
	cppVar_28258 = (cppVar_28258 & cppMask_un_8_);
	cppVar_28245 = cppVar_28258;
	}
	bool cppVar_28260 = (cppVar_28245 == 160);
	if (cppVar_28260) {
	cppVar_28244 = P2;
	} else {
	BIT_VEC cppVar_28261;
	BIT_VEC cppVar_28262;
	BIT_VEC cppVar_28263 = PC + 1;
	cppVar_28263 = (cppVar_28263 & cppMask_un_16_);
	BIT_VEC cppVar_28264 = ROM.rd(cppVar_28263);
	BIT_VEC cppVar_28265 = (cppVar_28264 >> 7) & cppMask_un_1_;
	bool cppVar_28266 = (cppVar_28265 == 1);
	if (cppVar_28266) {
	BIT_VEC cppVar_28267 = PC + 1;
	cppVar_28267 = (cppVar_28267 & cppMask_un_16_);
	BIT_VEC cppVar_28268 = ROM.rd(cppVar_28267);
	BIT_VEC cppVar_28269 = (cppVar_28268 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28270 = (cppVar_28269 << 3) | 0;
	cppVar_28270 = (cppVar_28270 & cppMask_un_8_);
	cppVar_28262 = cppVar_28270;
	} else {
	BIT_VEC cppVar_28271 = PC + 1;
	cppVar_28271 = (cppVar_28271 & cppMask_un_16_);
	BIT_VEC cppVar_28272 = ROM.rd(cppVar_28271);
	BIT_VEC cppVar_28273 = (cppVar_28272 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28274 = (cppVar_28273 & cppMask_un_5_);
	BIT_VEC cppVar_28275 = cppVar_28274 + 32;
	cppVar_28275 = (cppVar_28275 & cppMask_un_8_);
	cppVar_28262 = cppVar_28275;
	}
	bool cppVar_28277 = (cppVar_28262 == 168);
	if (cppVar_28277) {
	cppVar_28261 = IE;
	} else {
	BIT_VEC cppVar_28278;
	BIT_VEC cppVar_28279;
	BIT_VEC cppVar_28280 = PC + 1;
	cppVar_28280 = (cppVar_28280 & cppMask_un_16_);
	BIT_VEC cppVar_28281 = ROM.rd(cppVar_28280);
	BIT_VEC cppVar_28282 = (cppVar_28281 >> 7) & cppMask_un_1_;
	bool cppVar_28283 = (cppVar_28282 == 1);
	if (cppVar_28283) {
	BIT_VEC cppVar_28284 = PC + 1;
	cppVar_28284 = (cppVar_28284 & cppMask_un_16_);
	BIT_VEC cppVar_28285 = ROM.rd(cppVar_28284);
	BIT_VEC cppVar_28286 = (cppVar_28285 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28287 = (cppVar_28286 << 3) | 0;
	cppVar_28287 = (cppVar_28287 & cppMask_un_8_);
	cppVar_28279 = cppVar_28287;
	} else {
	BIT_VEC cppVar_28288 = PC + 1;
	cppVar_28288 = (cppVar_28288 & cppMask_un_16_);
	BIT_VEC cppVar_28289 = ROM.rd(cppVar_28288);
	BIT_VEC cppVar_28290 = (cppVar_28289 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28291 = (cppVar_28290 & cppMask_un_5_);
	BIT_VEC cppVar_28292 = cppVar_28291 + 32;
	cppVar_28292 = (cppVar_28292 & cppMask_un_8_);
	cppVar_28279 = cppVar_28292;
	}
	bool cppVar_28294 = (cppVar_28279 == 176);
	if (cppVar_28294) {
	cppVar_28278 = P3;
	} else {
	BIT_VEC cppVar_28295;
	BIT_VEC cppVar_28296;
	BIT_VEC cppVar_28297 = PC + 1;
	cppVar_28297 = (cppVar_28297 & cppMask_un_16_);
	BIT_VEC cppVar_28298 = ROM.rd(cppVar_28297);
	BIT_VEC cppVar_28299 = (cppVar_28298 >> 7) & cppMask_un_1_;
	bool cppVar_28300 = (cppVar_28299 == 1);
	if (cppVar_28300) {
	BIT_VEC cppVar_28301 = PC + 1;
	cppVar_28301 = (cppVar_28301 & cppMask_un_16_);
	BIT_VEC cppVar_28302 = ROM.rd(cppVar_28301);
	BIT_VEC cppVar_28303 = (cppVar_28302 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28304 = (cppVar_28303 << 3) | 0;
	cppVar_28304 = (cppVar_28304 & cppMask_un_8_);
	cppVar_28296 = cppVar_28304;
	} else {
	BIT_VEC cppVar_28305 = PC + 1;
	cppVar_28305 = (cppVar_28305 & cppMask_un_16_);
	BIT_VEC cppVar_28306 = ROM.rd(cppVar_28305);
	BIT_VEC cppVar_28307 = (cppVar_28306 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28308 = (cppVar_28307 & cppMask_un_5_);
	BIT_VEC cppVar_28309 = cppVar_28308 + 32;
	cppVar_28309 = (cppVar_28309 & cppMask_un_8_);
	cppVar_28296 = cppVar_28309;
	}
	bool cppVar_28311 = (cppVar_28296 == 184);
	if (cppVar_28311) {
	cppVar_28295 = IP;
	} else {
	BIT_VEC cppVar_28312;
	BIT_VEC cppVar_28313;
	BIT_VEC cppVar_28314 = PC + 1;
	cppVar_28314 = (cppVar_28314 & cppMask_un_16_);
	BIT_VEC cppVar_28315 = ROM.rd(cppVar_28314);
	BIT_VEC cppVar_28316 = (cppVar_28315 >> 7) & cppMask_un_1_;
	bool cppVar_28317 = (cppVar_28316 == 1);
	if (cppVar_28317) {
	BIT_VEC cppVar_28318 = PC + 1;
	cppVar_28318 = (cppVar_28318 & cppMask_un_16_);
	BIT_VEC cppVar_28319 = ROM.rd(cppVar_28318);
	BIT_VEC cppVar_28320 = (cppVar_28319 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28321 = (cppVar_28320 << 3) | 0;
	cppVar_28321 = (cppVar_28321 & cppMask_un_8_);
	cppVar_28313 = cppVar_28321;
	} else {
	BIT_VEC cppVar_28322 = PC + 1;
	cppVar_28322 = (cppVar_28322 & cppMask_un_16_);
	BIT_VEC cppVar_28323 = ROM.rd(cppVar_28322);
	BIT_VEC cppVar_28324 = (cppVar_28323 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28325 = (cppVar_28324 & cppMask_un_5_);
	BIT_VEC cppVar_28326 = cppVar_28325 + 32;
	cppVar_28326 = (cppVar_28326 & cppMask_un_8_);
	cppVar_28313 = cppVar_28326;
	}
	bool cppVar_28328 = (cppVar_28313 == 208);
	if (cppVar_28328) {
	cppVar_28312 = PSW;
	} else {
	BIT_VEC cppVar_28329;
	BIT_VEC cppVar_28330;
	BIT_VEC cppVar_28331 = PC + 1;
	cppVar_28331 = (cppVar_28331 & cppMask_un_16_);
	BIT_VEC cppVar_28332 = ROM.rd(cppVar_28331);
	BIT_VEC cppVar_28333 = (cppVar_28332 >> 7) & cppMask_un_1_;
	bool cppVar_28334 = (cppVar_28333 == 1);
	if (cppVar_28334) {
	BIT_VEC cppVar_28335 = PC + 1;
	cppVar_28335 = (cppVar_28335 & cppMask_un_16_);
	BIT_VEC cppVar_28336 = ROM.rd(cppVar_28335);
	BIT_VEC cppVar_28337 = (cppVar_28336 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28338 = (cppVar_28337 << 3) | 0;
	cppVar_28338 = (cppVar_28338 & cppMask_un_8_);
	cppVar_28330 = cppVar_28338;
	} else {
	BIT_VEC cppVar_28339 = PC + 1;
	cppVar_28339 = (cppVar_28339 & cppMask_un_16_);
	BIT_VEC cppVar_28340 = ROM.rd(cppVar_28339);
	BIT_VEC cppVar_28341 = (cppVar_28340 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28342 = (cppVar_28341 & cppMask_un_5_);
	BIT_VEC cppVar_28343 = cppVar_28342 + 32;
	cppVar_28343 = (cppVar_28343 & cppMask_un_8_);
	cppVar_28330 = cppVar_28343;
	}
	bool cppVar_28345 = (cppVar_28330 == 224);
	if (cppVar_28345) {
	cppVar_28329 = ACC;
	} else {
	BIT_VEC cppVar_28346;
	BIT_VEC cppVar_28347;
	BIT_VEC cppVar_28348 = PC + 1;
	cppVar_28348 = (cppVar_28348 & cppMask_un_16_);
	BIT_VEC cppVar_28349 = ROM.rd(cppVar_28348);
	BIT_VEC cppVar_28350 = (cppVar_28349 >> 7) & cppMask_un_1_;
	bool cppVar_28351 = (cppVar_28350 == 1);
	if (cppVar_28351) {
	BIT_VEC cppVar_28352 = PC + 1;
	cppVar_28352 = (cppVar_28352 & cppMask_un_16_);
	BIT_VEC cppVar_28353 = ROM.rd(cppVar_28352);
	BIT_VEC cppVar_28354 = (cppVar_28353 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28355 = (cppVar_28354 << 3) | 0;
	cppVar_28355 = (cppVar_28355 & cppMask_un_8_);
	cppVar_28347 = cppVar_28355;
	} else {
	BIT_VEC cppVar_28356 = PC + 1;
	cppVar_28356 = (cppVar_28356 & cppMask_un_16_);
	BIT_VEC cppVar_28357 = ROM.rd(cppVar_28356);
	BIT_VEC cppVar_28358 = (cppVar_28357 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28359 = (cppVar_28358 & cppMask_un_5_);
	BIT_VEC cppVar_28360 = cppVar_28359 + 32;
	cppVar_28360 = (cppVar_28360 & cppMask_un_8_);
	cppVar_28347 = cppVar_28360;
	}
	bool cppVar_28362 = (cppVar_28347 == 240);
	if (cppVar_28362) {
	cppVar_28346 = B;
	} else {
	cppVar_28346 = 0;
	}
	cppVar_28329 = cppVar_28346;
	}
	cppVar_28312 = cppVar_28329;
	}
	cppVar_28295 = cppVar_28312;
	}
	cppVar_28278 = cppVar_28295;
	}
	cppVar_28261 = cppVar_28278;
	}
	cppVar_28244 = cppVar_28261;
	}
	cppVar_28227 = cppVar_28244;
	}
	cppVar_28210 = cppVar_28227;
	}
	cppVar_28193 = cppVar_28210;
	}
	cppVar_28176 = cppVar_28193;
	}
	cppVar_28159 = cppVar_28176;
	}
	cppVar_28142 = cppVar_28159;
	}
	cppVar_28125 = cppVar_28142;
	}
	cppVar_28108 = cppVar_28125;
	}
	cppVar_28091 = cppVar_28108;
	}
	cppVar_28074 = cppVar_28091;
	}
	cppVar_28057 = cppVar_28074;
	}
	cppVar_28040 = cppVar_28057;
	}
	cppVar_28023 = cppVar_28040;
	}
	cppVar_28006 = cppVar_28023;
	}
	cppVar_27970 = cppVar_28006;
	}
	BIT_VEC cppVar_28364 = PC + 1;
	cppVar_28364 = (cppVar_28364 & cppMask_un_16_);
	BIT_VEC cppVar_28365 = ROM.rd(cppVar_28364);
	BIT_VEC cppVar_28366 = (cppVar_28365 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_28367 = (cppVar_27970 >> static_cast<unsigned>(cppVar_28366)) & 0x1;
	BIT_VEC cppVar_28368 = ~cppVar_28367;
	BIT_VEC cppVar_28369 = (cppVar_28368 & cppMask_un_1_);
	BIT_VEC cppVar_28370 = PC + 1;
	cppVar_28370 = (cppVar_28370 & cppMask_un_16_);
	BIT_VEC cppVar_28371 = ROM.rd(cppVar_28370);
	BIT_VEC cppVar_28372 = (cppVar_28371 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_28373 = (cppVar_28372 & cppMask_un_3_);
	BIT_VEC cppVar_28374 = cppVar_28369 << static_cast<unsigned>(cppVar_28373);
	cppVar_28374 = (cppVar_28374 & cppMask_un_8_);
	BIT_VEC cppVar_28375 = cppVar_27969 | cppVar_28374;
	cppVar_27550 = cppVar_28375;
	} else {
	cppVar_27550 = P1;
	}
	cppVar_27546 = cppVar_27550;
	} else {
	BIT_VEC cppVar_28376;
	BIT_VEC cppVar_28377 = ROM.rd(PC);
	bool cppVar_28379 = (cppVar_28377 == 146);
	if (cppVar_28379) {
	BIT_VEC cppVar_28380;
	BIT_VEC cppVar_28381;
	BIT_VEC cppVar_28383 = PC + 1;
	cppVar_28383 = (cppVar_28383 & cppMask_un_16_);
	BIT_VEC cppVar_28384 = ROM.rd(cppVar_28383);
	BIT_VEC cppVar_28385 = (cppVar_28384 >> 7) & cppMask_un_1_;
	bool cppVar_28387 = (cppVar_28385 == 1);
	if (cppVar_28387) {
	BIT_VEC cppVar_28388 = PC + 1;
	cppVar_28388 = (cppVar_28388 & cppMask_un_16_);
	BIT_VEC cppVar_28389 = ROM.rd(cppVar_28388);
	BIT_VEC cppVar_28390 = (cppVar_28389 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28392 = (cppVar_28390 << 3) | 0;
	cppVar_28392 = (cppVar_28392 & cppMask_un_8_);
	cppVar_28381 = cppVar_28392;
	} else {
	BIT_VEC cppVar_28393 = PC + 1;
	cppVar_28393 = (cppVar_28393 & cppMask_un_16_);
	BIT_VEC cppVar_28394 = ROM.rd(cppVar_28393);
	BIT_VEC cppVar_28395 = (cppVar_28394 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28396 = (cppVar_28395 & cppMask_un_5_);
	BIT_VEC cppVar_28398 = cppVar_28396 + 32;
	cppVar_28398 = (cppVar_28398 & cppMask_un_8_);
	cppVar_28381 = cppVar_28398;
	}
	bool cppVar_28400 = (cppVar_28381 == 144);
	if (cppVar_28400) {
	BIT_VEC cppVar_28402 = PC + 1;
	cppVar_28402 = (cppVar_28402 & cppMask_un_16_);
	BIT_VEC cppVar_28403 = ROM.rd(cppVar_28402);
	BIT_VEC cppVar_28404 = (cppVar_28403 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_28405 = (cppVar_28404 & cppMask_un_3_);
	BIT_VEC cppVar_28406 = 1 << static_cast<unsigned>(cppVar_28405);
	cppVar_28406 = (cppVar_28406 & cppMask_un_8_);
	BIT_VEC cppVar_28407 = ~cppVar_28406;
	BIT_VEC cppVar_28408;
	BIT_VEC cppVar_28409;
	BIT_VEC cppVar_28410 = PC + 1;
	cppVar_28410 = (cppVar_28410 & cppMask_un_16_);
	BIT_VEC cppVar_28411 = ROM.rd(cppVar_28410);
	BIT_VEC cppVar_28412 = (cppVar_28411 >> 7) & cppMask_un_1_;
	bool cppVar_28413 = (cppVar_28412 == 1);
	if (cppVar_28413) {
	BIT_VEC cppVar_28414 = PC + 1;
	cppVar_28414 = (cppVar_28414 & cppMask_un_16_);
	BIT_VEC cppVar_28415 = ROM.rd(cppVar_28414);
	BIT_VEC cppVar_28416 = (cppVar_28415 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28417 = (cppVar_28416 << 3) | 0;
	cppVar_28417 = (cppVar_28417 & cppMask_un_8_);
	cppVar_28409 = cppVar_28417;
	} else {
	BIT_VEC cppVar_28418 = PC + 1;
	cppVar_28418 = (cppVar_28418 & cppMask_un_16_);
	BIT_VEC cppVar_28419 = ROM.rd(cppVar_28418);
	BIT_VEC cppVar_28420 = (cppVar_28419 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28421 = (cppVar_28420 & cppMask_un_5_);
	BIT_VEC cppVar_28422 = cppVar_28421 + 32;
	cppVar_28422 = (cppVar_28422 & cppMask_un_8_);
	cppVar_28409 = cppVar_28422;
	}
	BIT_VEC cppVar_28423 = (cppVar_28409 >> 7) & cppMask_un_1_;
	bool cppVar_28425 = (cppVar_28423 == 0);
	if (cppVar_28425) {
	BIT_VEC cppVar_28426;
	BIT_VEC cppVar_28427 = PC + 1;
	cppVar_28427 = (cppVar_28427 & cppMask_un_16_);
	BIT_VEC cppVar_28428 = ROM.rd(cppVar_28427);
	BIT_VEC cppVar_28429 = (cppVar_28428 >> 7) & cppMask_un_1_;
	bool cppVar_28430 = (cppVar_28429 == 1);
	if (cppVar_28430) {
	BIT_VEC cppVar_28431 = PC + 1;
	cppVar_28431 = (cppVar_28431 & cppMask_un_16_);
	BIT_VEC cppVar_28432 = ROM.rd(cppVar_28431);
	BIT_VEC cppVar_28433 = (cppVar_28432 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28434 = (cppVar_28433 << 3) | 0;
	cppVar_28434 = (cppVar_28434 & cppMask_un_8_);
	cppVar_28426 = cppVar_28434;
	} else {
	BIT_VEC cppVar_28435 = PC + 1;
	cppVar_28435 = (cppVar_28435 & cppMask_un_16_);
	BIT_VEC cppVar_28436 = ROM.rd(cppVar_28435);
	BIT_VEC cppVar_28437 = (cppVar_28436 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28438 = (cppVar_28437 & cppMask_un_5_);
	BIT_VEC cppVar_28439 = cppVar_28438 + 32;
	cppVar_28439 = (cppVar_28439 & cppMask_un_8_);
	cppVar_28426 = cppVar_28439;
	}
	BIT_VEC cppVar_28440 = IRAM.rd(cppVar_28426);
	cppVar_28408 = cppVar_28440;
	} else {
	BIT_VEC cppVar_28441;
	BIT_VEC cppVar_28442;
	BIT_VEC cppVar_28443 = PC + 1;
	cppVar_28443 = (cppVar_28443 & cppMask_un_16_);
	BIT_VEC cppVar_28444 = ROM.rd(cppVar_28443);
	BIT_VEC cppVar_28445 = (cppVar_28444 >> 7) & cppMask_un_1_;
	bool cppVar_28446 = (cppVar_28445 == 1);
	if (cppVar_28446) {
	BIT_VEC cppVar_28447 = PC + 1;
	cppVar_28447 = (cppVar_28447 & cppMask_un_16_);
	BIT_VEC cppVar_28448 = ROM.rd(cppVar_28447);
	BIT_VEC cppVar_28449 = (cppVar_28448 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28450 = (cppVar_28449 << 3) | 0;
	cppVar_28450 = (cppVar_28450 & cppMask_un_8_);
	cppVar_28442 = cppVar_28450;
	} else {
	BIT_VEC cppVar_28451 = PC + 1;
	cppVar_28451 = (cppVar_28451 & cppMask_un_16_);
	BIT_VEC cppVar_28452 = ROM.rd(cppVar_28451);
	BIT_VEC cppVar_28453 = (cppVar_28452 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28454 = (cppVar_28453 & cppMask_un_5_);
	BIT_VEC cppVar_28455 = cppVar_28454 + 32;
	cppVar_28455 = (cppVar_28455 & cppMask_un_8_);
	cppVar_28442 = cppVar_28455;
	}
	bool cppVar_28457 = (cppVar_28442 == 128);
	if (cppVar_28457) {
	cppVar_28441 = P0;
	} else {
	BIT_VEC cppVar_28458;
	BIT_VEC cppVar_28459;
	BIT_VEC cppVar_28460 = PC + 1;
	cppVar_28460 = (cppVar_28460 & cppMask_un_16_);
	BIT_VEC cppVar_28461 = ROM.rd(cppVar_28460);
	BIT_VEC cppVar_28462 = (cppVar_28461 >> 7) & cppMask_un_1_;
	bool cppVar_28463 = (cppVar_28462 == 1);
	if (cppVar_28463) {
	BIT_VEC cppVar_28464 = PC + 1;
	cppVar_28464 = (cppVar_28464 & cppMask_un_16_);
	BIT_VEC cppVar_28465 = ROM.rd(cppVar_28464);
	BIT_VEC cppVar_28466 = (cppVar_28465 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28467 = (cppVar_28466 << 3) | 0;
	cppVar_28467 = (cppVar_28467 & cppMask_un_8_);
	cppVar_28459 = cppVar_28467;
	} else {
	BIT_VEC cppVar_28468 = PC + 1;
	cppVar_28468 = (cppVar_28468 & cppMask_un_16_);
	BIT_VEC cppVar_28469 = ROM.rd(cppVar_28468);
	BIT_VEC cppVar_28470 = (cppVar_28469 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28471 = (cppVar_28470 & cppMask_un_5_);
	BIT_VEC cppVar_28472 = cppVar_28471 + 32;
	cppVar_28472 = (cppVar_28472 & cppMask_un_8_);
	cppVar_28459 = cppVar_28472;
	}
	bool cppVar_28474 = (cppVar_28459 == 129);
	if (cppVar_28474) {
	cppVar_28458 = SP;
	} else {
	BIT_VEC cppVar_28475;
	BIT_VEC cppVar_28476;
	BIT_VEC cppVar_28477 = PC + 1;
	cppVar_28477 = (cppVar_28477 & cppMask_un_16_);
	BIT_VEC cppVar_28478 = ROM.rd(cppVar_28477);
	BIT_VEC cppVar_28479 = (cppVar_28478 >> 7) & cppMask_un_1_;
	bool cppVar_28480 = (cppVar_28479 == 1);
	if (cppVar_28480) {
	BIT_VEC cppVar_28481 = PC + 1;
	cppVar_28481 = (cppVar_28481 & cppMask_un_16_);
	BIT_VEC cppVar_28482 = ROM.rd(cppVar_28481);
	BIT_VEC cppVar_28483 = (cppVar_28482 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28484 = (cppVar_28483 << 3) | 0;
	cppVar_28484 = (cppVar_28484 & cppMask_un_8_);
	cppVar_28476 = cppVar_28484;
	} else {
	BIT_VEC cppVar_28485 = PC + 1;
	cppVar_28485 = (cppVar_28485 & cppMask_un_16_);
	BIT_VEC cppVar_28486 = ROM.rd(cppVar_28485);
	BIT_VEC cppVar_28487 = (cppVar_28486 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28488 = (cppVar_28487 & cppMask_un_5_);
	BIT_VEC cppVar_28489 = cppVar_28488 + 32;
	cppVar_28489 = (cppVar_28489 & cppMask_un_8_);
	cppVar_28476 = cppVar_28489;
	}
	bool cppVar_28491 = (cppVar_28476 == 130);
	if (cppVar_28491) {
	cppVar_28475 = DPL;
	} else {
	BIT_VEC cppVar_28492;
	BIT_VEC cppVar_28493;
	BIT_VEC cppVar_28494 = PC + 1;
	cppVar_28494 = (cppVar_28494 & cppMask_un_16_);
	BIT_VEC cppVar_28495 = ROM.rd(cppVar_28494);
	BIT_VEC cppVar_28496 = (cppVar_28495 >> 7) & cppMask_un_1_;
	bool cppVar_28497 = (cppVar_28496 == 1);
	if (cppVar_28497) {
	BIT_VEC cppVar_28498 = PC + 1;
	cppVar_28498 = (cppVar_28498 & cppMask_un_16_);
	BIT_VEC cppVar_28499 = ROM.rd(cppVar_28498);
	BIT_VEC cppVar_28500 = (cppVar_28499 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28501 = (cppVar_28500 << 3) | 0;
	cppVar_28501 = (cppVar_28501 & cppMask_un_8_);
	cppVar_28493 = cppVar_28501;
	} else {
	BIT_VEC cppVar_28502 = PC + 1;
	cppVar_28502 = (cppVar_28502 & cppMask_un_16_);
	BIT_VEC cppVar_28503 = ROM.rd(cppVar_28502);
	BIT_VEC cppVar_28504 = (cppVar_28503 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28505 = (cppVar_28504 & cppMask_un_5_);
	BIT_VEC cppVar_28506 = cppVar_28505 + 32;
	cppVar_28506 = (cppVar_28506 & cppMask_un_8_);
	cppVar_28493 = cppVar_28506;
	}
	bool cppVar_28508 = (cppVar_28493 == 131);
	if (cppVar_28508) {
	cppVar_28492 = DPH;
	} else {
	BIT_VEC cppVar_28509;
	BIT_VEC cppVar_28510;
	BIT_VEC cppVar_28511 = PC + 1;
	cppVar_28511 = (cppVar_28511 & cppMask_un_16_);
	BIT_VEC cppVar_28512 = ROM.rd(cppVar_28511);
	BIT_VEC cppVar_28513 = (cppVar_28512 >> 7) & cppMask_un_1_;
	bool cppVar_28514 = (cppVar_28513 == 1);
	if (cppVar_28514) {
	BIT_VEC cppVar_28515 = PC + 1;
	cppVar_28515 = (cppVar_28515 & cppMask_un_16_);
	BIT_VEC cppVar_28516 = ROM.rd(cppVar_28515);
	BIT_VEC cppVar_28517 = (cppVar_28516 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28518 = (cppVar_28517 << 3) | 0;
	cppVar_28518 = (cppVar_28518 & cppMask_un_8_);
	cppVar_28510 = cppVar_28518;
	} else {
	BIT_VEC cppVar_28519 = PC + 1;
	cppVar_28519 = (cppVar_28519 & cppMask_un_16_);
	BIT_VEC cppVar_28520 = ROM.rd(cppVar_28519);
	BIT_VEC cppVar_28521 = (cppVar_28520 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28522 = (cppVar_28521 & cppMask_un_5_);
	BIT_VEC cppVar_28523 = cppVar_28522 + 32;
	cppVar_28523 = (cppVar_28523 & cppMask_un_8_);
	cppVar_28510 = cppVar_28523;
	}
	bool cppVar_28525 = (cppVar_28510 == 135);
	if (cppVar_28525) {
	cppVar_28509 = PCON;
	} else {
	BIT_VEC cppVar_28526;
	BIT_VEC cppVar_28527;
	BIT_VEC cppVar_28528 = PC + 1;
	cppVar_28528 = (cppVar_28528 & cppMask_un_16_);
	BIT_VEC cppVar_28529 = ROM.rd(cppVar_28528);
	BIT_VEC cppVar_28530 = (cppVar_28529 >> 7) & cppMask_un_1_;
	bool cppVar_28531 = (cppVar_28530 == 1);
	if (cppVar_28531) {
	BIT_VEC cppVar_28532 = PC + 1;
	cppVar_28532 = (cppVar_28532 & cppMask_un_16_);
	BIT_VEC cppVar_28533 = ROM.rd(cppVar_28532);
	BIT_VEC cppVar_28534 = (cppVar_28533 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28535 = (cppVar_28534 << 3) | 0;
	cppVar_28535 = (cppVar_28535 & cppMask_un_8_);
	cppVar_28527 = cppVar_28535;
	} else {
	BIT_VEC cppVar_28536 = PC + 1;
	cppVar_28536 = (cppVar_28536 & cppMask_un_16_);
	BIT_VEC cppVar_28537 = ROM.rd(cppVar_28536);
	BIT_VEC cppVar_28538 = (cppVar_28537 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28539 = (cppVar_28538 & cppMask_un_5_);
	BIT_VEC cppVar_28540 = cppVar_28539 + 32;
	cppVar_28540 = (cppVar_28540 & cppMask_un_8_);
	cppVar_28527 = cppVar_28540;
	}
	bool cppVar_28542 = (cppVar_28527 == 136);
	if (cppVar_28542) {
	cppVar_28526 = TCON;
	} else {
	BIT_VEC cppVar_28543;
	BIT_VEC cppVar_28544;
	BIT_VEC cppVar_28545 = PC + 1;
	cppVar_28545 = (cppVar_28545 & cppMask_un_16_);
	BIT_VEC cppVar_28546 = ROM.rd(cppVar_28545);
	BIT_VEC cppVar_28547 = (cppVar_28546 >> 7) & cppMask_un_1_;
	bool cppVar_28548 = (cppVar_28547 == 1);
	if (cppVar_28548) {
	BIT_VEC cppVar_28549 = PC + 1;
	cppVar_28549 = (cppVar_28549 & cppMask_un_16_);
	BIT_VEC cppVar_28550 = ROM.rd(cppVar_28549);
	BIT_VEC cppVar_28551 = (cppVar_28550 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28552 = (cppVar_28551 << 3) | 0;
	cppVar_28552 = (cppVar_28552 & cppMask_un_8_);
	cppVar_28544 = cppVar_28552;
	} else {
	BIT_VEC cppVar_28553 = PC + 1;
	cppVar_28553 = (cppVar_28553 & cppMask_un_16_);
	BIT_VEC cppVar_28554 = ROM.rd(cppVar_28553);
	BIT_VEC cppVar_28555 = (cppVar_28554 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28556 = (cppVar_28555 & cppMask_un_5_);
	BIT_VEC cppVar_28557 = cppVar_28556 + 32;
	cppVar_28557 = (cppVar_28557 & cppMask_un_8_);
	cppVar_28544 = cppVar_28557;
	}
	bool cppVar_28559 = (cppVar_28544 == 137);
	if (cppVar_28559) {
	cppVar_28543 = TMOD;
	} else {
	BIT_VEC cppVar_28560;
	BIT_VEC cppVar_28561;
	BIT_VEC cppVar_28562 = PC + 1;
	cppVar_28562 = (cppVar_28562 & cppMask_un_16_);
	BIT_VEC cppVar_28563 = ROM.rd(cppVar_28562);
	BIT_VEC cppVar_28564 = (cppVar_28563 >> 7) & cppMask_un_1_;
	bool cppVar_28565 = (cppVar_28564 == 1);
	if (cppVar_28565) {
	BIT_VEC cppVar_28566 = PC + 1;
	cppVar_28566 = (cppVar_28566 & cppMask_un_16_);
	BIT_VEC cppVar_28567 = ROM.rd(cppVar_28566);
	BIT_VEC cppVar_28568 = (cppVar_28567 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28569 = (cppVar_28568 << 3) | 0;
	cppVar_28569 = (cppVar_28569 & cppMask_un_8_);
	cppVar_28561 = cppVar_28569;
	} else {
	BIT_VEC cppVar_28570 = PC + 1;
	cppVar_28570 = (cppVar_28570 & cppMask_un_16_);
	BIT_VEC cppVar_28571 = ROM.rd(cppVar_28570);
	BIT_VEC cppVar_28572 = (cppVar_28571 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28573 = (cppVar_28572 & cppMask_un_5_);
	BIT_VEC cppVar_28574 = cppVar_28573 + 32;
	cppVar_28574 = (cppVar_28574 & cppMask_un_8_);
	cppVar_28561 = cppVar_28574;
	}
	bool cppVar_28576 = (cppVar_28561 == 138);
	if (cppVar_28576) {
	cppVar_28560 = TL0;
	} else {
	BIT_VEC cppVar_28577;
	BIT_VEC cppVar_28578;
	BIT_VEC cppVar_28579 = PC + 1;
	cppVar_28579 = (cppVar_28579 & cppMask_un_16_);
	BIT_VEC cppVar_28580 = ROM.rd(cppVar_28579);
	BIT_VEC cppVar_28581 = (cppVar_28580 >> 7) & cppMask_un_1_;
	bool cppVar_28582 = (cppVar_28581 == 1);
	if (cppVar_28582) {
	BIT_VEC cppVar_28583 = PC + 1;
	cppVar_28583 = (cppVar_28583 & cppMask_un_16_);
	BIT_VEC cppVar_28584 = ROM.rd(cppVar_28583);
	BIT_VEC cppVar_28585 = (cppVar_28584 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28586 = (cppVar_28585 << 3) | 0;
	cppVar_28586 = (cppVar_28586 & cppMask_un_8_);
	cppVar_28578 = cppVar_28586;
	} else {
	BIT_VEC cppVar_28587 = PC + 1;
	cppVar_28587 = (cppVar_28587 & cppMask_un_16_);
	BIT_VEC cppVar_28588 = ROM.rd(cppVar_28587);
	BIT_VEC cppVar_28589 = (cppVar_28588 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28590 = (cppVar_28589 & cppMask_un_5_);
	BIT_VEC cppVar_28591 = cppVar_28590 + 32;
	cppVar_28591 = (cppVar_28591 & cppMask_un_8_);
	cppVar_28578 = cppVar_28591;
	}
	bool cppVar_28593 = (cppVar_28578 == 140);
	if (cppVar_28593) {
	cppVar_28577 = TH0;
	} else {
	BIT_VEC cppVar_28594;
	BIT_VEC cppVar_28595;
	BIT_VEC cppVar_28596 = PC + 1;
	cppVar_28596 = (cppVar_28596 & cppMask_un_16_);
	BIT_VEC cppVar_28597 = ROM.rd(cppVar_28596);
	BIT_VEC cppVar_28598 = (cppVar_28597 >> 7) & cppMask_un_1_;
	bool cppVar_28599 = (cppVar_28598 == 1);
	if (cppVar_28599) {
	BIT_VEC cppVar_28600 = PC + 1;
	cppVar_28600 = (cppVar_28600 & cppMask_un_16_);
	BIT_VEC cppVar_28601 = ROM.rd(cppVar_28600);
	BIT_VEC cppVar_28602 = (cppVar_28601 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28603 = (cppVar_28602 << 3) | 0;
	cppVar_28603 = (cppVar_28603 & cppMask_un_8_);
	cppVar_28595 = cppVar_28603;
	} else {
	BIT_VEC cppVar_28604 = PC + 1;
	cppVar_28604 = (cppVar_28604 & cppMask_un_16_);
	BIT_VEC cppVar_28605 = ROM.rd(cppVar_28604);
	BIT_VEC cppVar_28606 = (cppVar_28605 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28607 = (cppVar_28606 & cppMask_un_5_);
	BIT_VEC cppVar_28608 = cppVar_28607 + 32;
	cppVar_28608 = (cppVar_28608 & cppMask_un_8_);
	cppVar_28595 = cppVar_28608;
	}
	bool cppVar_28610 = (cppVar_28595 == 139);
	if (cppVar_28610) {
	cppVar_28594 = TL1;
	} else {
	BIT_VEC cppVar_28611;
	BIT_VEC cppVar_28612;
	BIT_VEC cppVar_28613 = PC + 1;
	cppVar_28613 = (cppVar_28613 & cppMask_un_16_);
	BIT_VEC cppVar_28614 = ROM.rd(cppVar_28613);
	BIT_VEC cppVar_28615 = (cppVar_28614 >> 7) & cppMask_un_1_;
	bool cppVar_28616 = (cppVar_28615 == 1);
	if (cppVar_28616) {
	BIT_VEC cppVar_28617 = PC + 1;
	cppVar_28617 = (cppVar_28617 & cppMask_un_16_);
	BIT_VEC cppVar_28618 = ROM.rd(cppVar_28617);
	BIT_VEC cppVar_28619 = (cppVar_28618 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28620 = (cppVar_28619 << 3) | 0;
	cppVar_28620 = (cppVar_28620 & cppMask_un_8_);
	cppVar_28612 = cppVar_28620;
	} else {
	BIT_VEC cppVar_28621 = PC + 1;
	cppVar_28621 = (cppVar_28621 & cppMask_un_16_);
	BIT_VEC cppVar_28622 = ROM.rd(cppVar_28621);
	BIT_VEC cppVar_28623 = (cppVar_28622 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28624 = (cppVar_28623 & cppMask_un_5_);
	BIT_VEC cppVar_28625 = cppVar_28624 + 32;
	cppVar_28625 = (cppVar_28625 & cppMask_un_8_);
	cppVar_28612 = cppVar_28625;
	}
	bool cppVar_28627 = (cppVar_28612 == 141);
	if (cppVar_28627) {
	cppVar_28611 = TH1;
	} else {
	BIT_VEC cppVar_28628;
	BIT_VEC cppVar_28629;
	BIT_VEC cppVar_28630 = PC + 1;
	cppVar_28630 = (cppVar_28630 & cppMask_un_16_);
	BIT_VEC cppVar_28631 = ROM.rd(cppVar_28630);
	BIT_VEC cppVar_28632 = (cppVar_28631 >> 7) & cppMask_un_1_;
	bool cppVar_28633 = (cppVar_28632 == 1);
	if (cppVar_28633) {
	BIT_VEC cppVar_28634 = PC + 1;
	cppVar_28634 = (cppVar_28634 & cppMask_un_16_);
	BIT_VEC cppVar_28635 = ROM.rd(cppVar_28634);
	BIT_VEC cppVar_28636 = (cppVar_28635 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28637 = (cppVar_28636 << 3) | 0;
	cppVar_28637 = (cppVar_28637 & cppMask_un_8_);
	cppVar_28629 = cppVar_28637;
	} else {
	BIT_VEC cppVar_28638 = PC + 1;
	cppVar_28638 = (cppVar_28638 & cppMask_un_16_);
	BIT_VEC cppVar_28639 = ROM.rd(cppVar_28638);
	BIT_VEC cppVar_28640 = (cppVar_28639 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28641 = (cppVar_28640 & cppMask_un_5_);
	BIT_VEC cppVar_28642 = cppVar_28641 + 32;
	cppVar_28642 = (cppVar_28642 & cppMask_un_8_);
	cppVar_28629 = cppVar_28642;
	}
	bool cppVar_28644 = (cppVar_28629 == 144);
	if (cppVar_28644) {
	cppVar_28628 = P1;
	} else {
	BIT_VEC cppVar_28645;
	BIT_VEC cppVar_28646;
	BIT_VEC cppVar_28647 = PC + 1;
	cppVar_28647 = (cppVar_28647 & cppMask_un_16_);
	BIT_VEC cppVar_28648 = ROM.rd(cppVar_28647);
	BIT_VEC cppVar_28649 = (cppVar_28648 >> 7) & cppMask_un_1_;
	bool cppVar_28650 = (cppVar_28649 == 1);
	if (cppVar_28650) {
	BIT_VEC cppVar_28651 = PC + 1;
	cppVar_28651 = (cppVar_28651 & cppMask_un_16_);
	BIT_VEC cppVar_28652 = ROM.rd(cppVar_28651);
	BIT_VEC cppVar_28653 = (cppVar_28652 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28654 = (cppVar_28653 << 3) | 0;
	cppVar_28654 = (cppVar_28654 & cppMask_un_8_);
	cppVar_28646 = cppVar_28654;
	} else {
	BIT_VEC cppVar_28655 = PC + 1;
	cppVar_28655 = (cppVar_28655 & cppMask_un_16_);
	BIT_VEC cppVar_28656 = ROM.rd(cppVar_28655);
	BIT_VEC cppVar_28657 = (cppVar_28656 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28658 = (cppVar_28657 & cppMask_un_5_);
	BIT_VEC cppVar_28659 = cppVar_28658 + 32;
	cppVar_28659 = (cppVar_28659 & cppMask_un_8_);
	cppVar_28646 = cppVar_28659;
	}
	bool cppVar_28661 = (cppVar_28646 == 152);
	if (cppVar_28661) {
	cppVar_28645 = SCON;
	} else {
	BIT_VEC cppVar_28662;
	BIT_VEC cppVar_28663;
	BIT_VEC cppVar_28664 = PC + 1;
	cppVar_28664 = (cppVar_28664 & cppMask_un_16_);
	BIT_VEC cppVar_28665 = ROM.rd(cppVar_28664);
	BIT_VEC cppVar_28666 = (cppVar_28665 >> 7) & cppMask_un_1_;
	bool cppVar_28667 = (cppVar_28666 == 1);
	if (cppVar_28667) {
	BIT_VEC cppVar_28668 = PC + 1;
	cppVar_28668 = (cppVar_28668 & cppMask_un_16_);
	BIT_VEC cppVar_28669 = ROM.rd(cppVar_28668);
	BIT_VEC cppVar_28670 = (cppVar_28669 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28671 = (cppVar_28670 << 3) | 0;
	cppVar_28671 = (cppVar_28671 & cppMask_un_8_);
	cppVar_28663 = cppVar_28671;
	} else {
	BIT_VEC cppVar_28672 = PC + 1;
	cppVar_28672 = (cppVar_28672 & cppMask_un_16_);
	BIT_VEC cppVar_28673 = ROM.rd(cppVar_28672);
	BIT_VEC cppVar_28674 = (cppVar_28673 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28675 = (cppVar_28674 & cppMask_un_5_);
	BIT_VEC cppVar_28676 = cppVar_28675 + 32;
	cppVar_28676 = (cppVar_28676 & cppMask_un_8_);
	cppVar_28663 = cppVar_28676;
	}
	bool cppVar_28678 = (cppVar_28663 == 153);
	if (cppVar_28678) {
	cppVar_28662 = SBUF;
	} else {
	BIT_VEC cppVar_28679;
	BIT_VEC cppVar_28680;
	BIT_VEC cppVar_28681 = PC + 1;
	cppVar_28681 = (cppVar_28681 & cppMask_un_16_);
	BIT_VEC cppVar_28682 = ROM.rd(cppVar_28681);
	BIT_VEC cppVar_28683 = (cppVar_28682 >> 7) & cppMask_un_1_;
	bool cppVar_28684 = (cppVar_28683 == 1);
	if (cppVar_28684) {
	BIT_VEC cppVar_28685 = PC + 1;
	cppVar_28685 = (cppVar_28685 & cppMask_un_16_);
	BIT_VEC cppVar_28686 = ROM.rd(cppVar_28685);
	BIT_VEC cppVar_28687 = (cppVar_28686 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28688 = (cppVar_28687 << 3) | 0;
	cppVar_28688 = (cppVar_28688 & cppMask_un_8_);
	cppVar_28680 = cppVar_28688;
	} else {
	BIT_VEC cppVar_28689 = PC + 1;
	cppVar_28689 = (cppVar_28689 & cppMask_un_16_);
	BIT_VEC cppVar_28690 = ROM.rd(cppVar_28689);
	BIT_VEC cppVar_28691 = (cppVar_28690 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28692 = (cppVar_28691 & cppMask_un_5_);
	BIT_VEC cppVar_28693 = cppVar_28692 + 32;
	cppVar_28693 = (cppVar_28693 & cppMask_un_8_);
	cppVar_28680 = cppVar_28693;
	}
	bool cppVar_28695 = (cppVar_28680 == 160);
	if (cppVar_28695) {
	cppVar_28679 = P2;
	} else {
	BIT_VEC cppVar_28696;
	BIT_VEC cppVar_28697;
	BIT_VEC cppVar_28698 = PC + 1;
	cppVar_28698 = (cppVar_28698 & cppMask_un_16_);
	BIT_VEC cppVar_28699 = ROM.rd(cppVar_28698);
	BIT_VEC cppVar_28700 = (cppVar_28699 >> 7) & cppMask_un_1_;
	bool cppVar_28701 = (cppVar_28700 == 1);
	if (cppVar_28701) {
	BIT_VEC cppVar_28702 = PC + 1;
	cppVar_28702 = (cppVar_28702 & cppMask_un_16_);
	BIT_VEC cppVar_28703 = ROM.rd(cppVar_28702);
	BIT_VEC cppVar_28704 = (cppVar_28703 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28705 = (cppVar_28704 << 3) | 0;
	cppVar_28705 = (cppVar_28705 & cppMask_un_8_);
	cppVar_28697 = cppVar_28705;
	} else {
	BIT_VEC cppVar_28706 = PC + 1;
	cppVar_28706 = (cppVar_28706 & cppMask_un_16_);
	BIT_VEC cppVar_28707 = ROM.rd(cppVar_28706);
	BIT_VEC cppVar_28708 = (cppVar_28707 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28709 = (cppVar_28708 & cppMask_un_5_);
	BIT_VEC cppVar_28710 = cppVar_28709 + 32;
	cppVar_28710 = (cppVar_28710 & cppMask_un_8_);
	cppVar_28697 = cppVar_28710;
	}
	bool cppVar_28712 = (cppVar_28697 == 168);
	if (cppVar_28712) {
	cppVar_28696 = IE;
	} else {
	BIT_VEC cppVar_28713;
	BIT_VEC cppVar_28714;
	BIT_VEC cppVar_28715 = PC + 1;
	cppVar_28715 = (cppVar_28715 & cppMask_un_16_);
	BIT_VEC cppVar_28716 = ROM.rd(cppVar_28715);
	BIT_VEC cppVar_28717 = (cppVar_28716 >> 7) & cppMask_un_1_;
	bool cppVar_28718 = (cppVar_28717 == 1);
	if (cppVar_28718) {
	BIT_VEC cppVar_28719 = PC + 1;
	cppVar_28719 = (cppVar_28719 & cppMask_un_16_);
	BIT_VEC cppVar_28720 = ROM.rd(cppVar_28719);
	BIT_VEC cppVar_28721 = (cppVar_28720 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28722 = (cppVar_28721 << 3) | 0;
	cppVar_28722 = (cppVar_28722 & cppMask_un_8_);
	cppVar_28714 = cppVar_28722;
	} else {
	BIT_VEC cppVar_28723 = PC + 1;
	cppVar_28723 = (cppVar_28723 & cppMask_un_16_);
	BIT_VEC cppVar_28724 = ROM.rd(cppVar_28723);
	BIT_VEC cppVar_28725 = (cppVar_28724 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28726 = (cppVar_28725 & cppMask_un_5_);
	BIT_VEC cppVar_28727 = cppVar_28726 + 32;
	cppVar_28727 = (cppVar_28727 & cppMask_un_8_);
	cppVar_28714 = cppVar_28727;
	}
	bool cppVar_28729 = (cppVar_28714 == 176);
	if (cppVar_28729) {
	cppVar_28713 = P3;
	} else {
	BIT_VEC cppVar_28730;
	BIT_VEC cppVar_28731;
	BIT_VEC cppVar_28732 = PC + 1;
	cppVar_28732 = (cppVar_28732 & cppMask_un_16_);
	BIT_VEC cppVar_28733 = ROM.rd(cppVar_28732);
	BIT_VEC cppVar_28734 = (cppVar_28733 >> 7) & cppMask_un_1_;
	bool cppVar_28735 = (cppVar_28734 == 1);
	if (cppVar_28735) {
	BIT_VEC cppVar_28736 = PC + 1;
	cppVar_28736 = (cppVar_28736 & cppMask_un_16_);
	BIT_VEC cppVar_28737 = ROM.rd(cppVar_28736);
	BIT_VEC cppVar_28738 = (cppVar_28737 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28739 = (cppVar_28738 << 3) | 0;
	cppVar_28739 = (cppVar_28739 & cppMask_un_8_);
	cppVar_28731 = cppVar_28739;
	} else {
	BIT_VEC cppVar_28740 = PC + 1;
	cppVar_28740 = (cppVar_28740 & cppMask_un_16_);
	BIT_VEC cppVar_28741 = ROM.rd(cppVar_28740);
	BIT_VEC cppVar_28742 = (cppVar_28741 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28743 = (cppVar_28742 & cppMask_un_5_);
	BIT_VEC cppVar_28744 = cppVar_28743 + 32;
	cppVar_28744 = (cppVar_28744 & cppMask_un_8_);
	cppVar_28731 = cppVar_28744;
	}
	bool cppVar_28746 = (cppVar_28731 == 184);
	if (cppVar_28746) {
	cppVar_28730 = IP;
	} else {
	BIT_VEC cppVar_28747;
	BIT_VEC cppVar_28748;
	BIT_VEC cppVar_28749 = PC + 1;
	cppVar_28749 = (cppVar_28749 & cppMask_un_16_);
	BIT_VEC cppVar_28750 = ROM.rd(cppVar_28749);
	BIT_VEC cppVar_28751 = (cppVar_28750 >> 7) & cppMask_un_1_;
	bool cppVar_28752 = (cppVar_28751 == 1);
	if (cppVar_28752) {
	BIT_VEC cppVar_28753 = PC + 1;
	cppVar_28753 = (cppVar_28753 & cppMask_un_16_);
	BIT_VEC cppVar_28754 = ROM.rd(cppVar_28753);
	BIT_VEC cppVar_28755 = (cppVar_28754 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28756 = (cppVar_28755 << 3) | 0;
	cppVar_28756 = (cppVar_28756 & cppMask_un_8_);
	cppVar_28748 = cppVar_28756;
	} else {
	BIT_VEC cppVar_28757 = PC + 1;
	cppVar_28757 = (cppVar_28757 & cppMask_un_16_);
	BIT_VEC cppVar_28758 = ROM.rd(cppVar_28757);
	BIT_VEC cppVar_28759 = (cppVar_28758 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28760 = (cppVar_28759 & cppMask_un_5_);
	BIT_VEC cppVar_28761 = cppVar_28760 + 32;
	cppVar_28761 = (cppVar_28761 & cppMask_un_8_);
	cppVar_28748 = cppVar_28761;
	}
	bool cppVar_28763 = (cppVar_28748 == 208);
	if (cppVar_28763) {
	cppVar_28747 = PSW;
	} else {
	BIT_VEC cppVar_28764;
	BIT_VEC cppVar_28765;
	BIT_VEC cppVar_28766 = PC + 1;
	cppVar_28766 = (cppVar_28766 & cppMask_un_16_);
	BIT_VEC cppVar_28767 = ROM.rd(cppVar_28766);
	BIT_VEC cppVar_28768 = (cppVar_28767 >> 7) & cppMask_un_1_;
	bool cppVar_28769 = (cppVar_28768 == 1);
	if (cppVar_28769) {
	BIT_VEC cppVar_28770 = PC + 1;
	cppVar_28770 = (cppVar_28770 & cppMask_un_16_);
	BIT_VEC cppVar_28771 = ROM.rd(cppVar_28770);
	BIT_VEC cppVar_28772 = (cppVar_28771 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28773 = (cppVar_28772 << 3) | 0;
	cppVar_28773 = (cppVar_28773 & cppMask_un_8_);
	cppVar_28765 = cppVar_28773;
	} else {
	BIT_VEC cppVar_28774 = PC + 1;
	cppVar_28774 = (cppVar_28774 & cppMask_un_16_);
	BIT_VEC cppVar_28775 = ROM.rd(cppVar_28774);
	BIT_VEC cppVar_28776 = (cppVar_28775 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28777 = (cppVar_28776 & cppMask_un_5_);
	BIT_VEC cppVar_28778 = cppVar_28777 + 32;
	cppVar_28778 = (cppVar_28778 & cppMask_un_8_);
	cppVar_28765 = cppVar_28778;
	}
	bool cppVar_28780 = (cppVar_28765 == 224);
	if (cppVar_28780) {
	cppVar_28764 = ACC;
	} else {
	BIT_VEC cppVar_28781;
	BIT_VEC cppVar_28782;
	BIT_VEC cppVar_28783 = PC + 1;
	cppVar_28783 = (cppVar_28783 & cppMask_un_16_);
	BIT_VEC cppVar_28784 = ROM.rd(cppVar_28783);
	BIT_VEC cppVar_28785 = (cppVar_28784 >> 7) & cppMask_un_1_;
	bool cppVar_28786 = (cppVar_28785 == 1);
	if (cppVar_28786) {
	BIT_VEC cppVar_28787 = PC + 1;
	cppVar_28787 = (cppVar_28787 & cppMask_un_16_);
	BIT_VEC cppVar_28788 = ROM.rd(cppVar_28787);
	BIT_VEC cppVar_28789 = (cppVar_28788 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28790 = (cppVar_28789 << 3) | 0;
	cppVar_28790 = (cppVar_28790 & cppMask_un_8_);
	cppVar_28782 = cppVar_28790;
	} else {
	BIT_VEC cppVar_28791 = PC + 1;
	cppVar_28791 = (cppVar_28791 & cppMask_un_16_);
	BIT_VEC cppVar_28792 = ROM.rd(cppVar_28791);
	BIT_VEC cppVar_28793 = (cppVar_28792 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_28794 = (cppVar_28793 & cppMask_un_5_);
	BIT_VEC cppVar_28795 = cppVar_28794 + 32;
	cppVar_28795 = (cppVar_28795 & cppMask_un_8_);
	cppVar_28782 = cppVar_28795;
	}
	bool cppVar_28797 = (cppVar_28782 == 240);
	if (cppVar_28797) {
	cppVar_28781 = B;
	} else {
	cppVar_28781 = 0;
	}
	cppVar_28764 = cppVar_28781;
	}
	cppVar_28747 = cppVar_28764;
	}
	cppVar_28730 = cppVar_28747;
	}
	cppVar_28713 = cppVar_28730;
	}
	cppVar_28696 = cppVar_28713;
	}
	cppVar_28679 = cppVar_28696;
	}
	cppVar_28662 = cppVar_28679;
	}
	cppVar_28645 = cppVar_28662;
	}
	cppVar_28628 = cppVar_28645;
	}
	cppVar_28611 = cppVar_28628;
	}
	cppVar_28594 = cppVar_28611;
	}
	cppVar_28577 = cppVar_28594;
	}
	cppVar_28560 = cppVar_28577;
	}
	cppVar_28543 = cppVar_28560;
	}
	cppVar_28526 = cppVar_28543;
	}
	cppVar_28509 = cppVar_28526;
	}
	cppVar_28492 = cppVar_28509;
	}
	cppVar_28475 = cppVar_28492;
	}
	cppVar_28458 = cppVar_28475;
	}
	cppVar_28441 = cppVar_28458;
	}
	cppVar_28408 = cppVar_28441;
	}
	BIT_VEC cppVar_28799 = cppVar_28407 & cppVar_28408;
	BIT_VEC cppVar_28800 = (PSW >> 7) & cppMask_un_1_;
	BIT_VEC cppVar_28801 = (cppVar_28800 & cppMask_un_1_);
	BIT_VEC cppVar_28802 = PC + 1;
	cppVar_28802 = (cppVar_28802 & cppMask_un_16_);
	BIT_VEC cppVar_28803 = ROM.rd(cppVar_28802);
	BIT_VEC cppVar_28804 = (cppVar_28803 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_28805 = (cppVar_28804 & cppMask_un_3_);
	BIT_VEC cppVar_28806 = cppVar_28801 << static_cast<unsigned>(cppVar_28805);
	cppVar_28806 = (cppVar_28806 & cppMask_un_8_);
	BIT_VEC cppVar_28807 = cppVar_28799 | cppVar_28806;
	cppVar_28380 = cppVar_28807;
	} else {
	cppVar_28380 = P1;
	}
	cppVar_28376 = cppVar_28380;
	} else {
	BIT_VEC cppVar_28808;
	BIT_VEC cppVar_28809 = ROM.rd(PC);
	bool cppVar_28811 = (cppVar_28809 == 143);
	if (cppVar_28811) {
	BIT_VEC cppVar_28812;
	BIT_VEC cppVar_28814 = PC + 1;
	cppVar_28814 = (cppVar_28814 & cppMask_un_16_);
	BIT_VEC cppVar_28815 = ROM.rd(cppVar_28814);
	bool cppVar_28817 = (cppVar_28815 == 144);
	if (cppVar_28817) {
	BIT_VEC cppVar_28818;
	BIT_VEC cppVar_28820 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28822 = (cppVar_28820 << 3) | 7;
	cppVar_28822 = (cppVar_28822 & cppMask_un_5_);
	BIT_VEC cppVar_28823 = (0 << 5) | cppVar_28822;
	cppVar_28823 = (cppVar_28823 & cppMask_un_8_);
	BIT_VEC cppVar_28824 = (cppVar_28823 >> 7) & cppMask_un_1_;
	bool cppVar_28826 = (cppVar_28824 == 0);
	if (cppVar_28826) {
	BIT_VEC cppVar_28827 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28828 = (cppVar_28827 << 3) | 7;
	cppVar_28828 = (cppVar_28828 & cppMask_un_5_);
	BIT_VEC cppVar_28829 = (0 << 5) | cppVar_28828;
	cppVar_28829 = (cppVar_28829 & cppMask_un_8_);
	BIT_VEC cppVar_28830 = IRAM.rd(cppVar_28829);
	cppVar_28818 = cppVar_28830;
	} else {
	BIT_VEC cppVar_28831;
	BIT_VEC cppVar_28832 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28833 = (cppVar_28832 << 3) | 7;
	cppVar_28833 = (cppVar_28833 & cppMask_un_5_);
	BIT_VEC cppVar_28834 = (0 << 5) | cppVar_28833;
	cppVar_28834 = (cppVar_28834 & cppMask_un_8_);
	bool cppVar_28836 = (cppVar_28834 == 128);
	if (cppVar_28836) {
	cppVar_28831 = P0;
	} else {
	BIT_VEC cppVar_28837;
	BIT_VEC cppVar_28838 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28839 = (cppVar_28838 << 3) | 7;
	cppVar_28839 = (cppVar_28839 & cppMask_un_5_);
	BIT_VEC cppVar_28840 = (0 << 5) | cppVar_28839;
	cppVar_28840 = (cppVar_28840 & cppMask_un_8_);
	bool cppVar_28842 = (cppVar_28840 == 129);
	if (cppVar_28842) {
	cppVar_28837 = SP;
	} else {
	BIT_VEC cppVar_28843;
	BIT_VEC cppVar_28844 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28845 = (cppVar_28844 << 3) | 7;
	cppVar_28845 = (cppVar_28845 & cppMask_un_5_);
	BIT_VEC cppVar_28846 = (0 << 5) | cppVar_28845;
	cppVar_28846 = (cppVar_28846 & cppMask_un_8_);
	bool cppVar_28848 = (cppVar_28846 == 130);
	if (cppVar_28848) {
	cppVar_28843 = DPL;
	} else {
	BIT_VEC cppVar_28849;
	BIT_VEC cppVar_28850 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28851 = (cppVar_28850 << 3) | 7;
	cppVar_28851 = (cppVar_28851 & cppMask_un_5_);
	BIT_VEC cppVar_28852 = (0 << 5) | cppVar_28851;
	cppVar_28852 = (cppVar_28852 & cppMask_un_8_);
	bool cppVar_28854 = (cppVar_28852 == 131);
	if (cppVar_28854) {
	cppVar_28849 = DPH;
	} else {
	BIT_VEC cppVar_28855;
	BIT_VEC cppVar_28856 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28857 = (cppVar_28856 << 3) | 7;
	cppVar_28857 = (cppVar_28857 & cppMask_un_5_);
	BIT_VEC cppVar_28858 = (0 << 5) | cppVar_28857;
	cppVar_28858 = (cppVar_28858 & cppMask_un_8_);
	bool cppVar_28860 = (cppVar_28858 == 135);
	if (cppVar_28860) {
	cppVar_28855 = PCON;
	} else {
	BIT_VEC cppVar_28861;
	BIT_VEC cppVar_28862 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28863 = (cppVar_28862 << 3) | 7;
	cppVar_28863 = (cppVar_28863 & cppMask_un_5_);
	BIT_VEC cppVar_28864 = (0 << 5) | cppVar_28863;
	cppVar_28864 = (cppVar_28864 & cppMask_un_8_);
	bool cppVar_28866 = (cppVar_28864 == 136);
	if (cppVar_28866) {
	cppVar_28861 = TCON;
	} else {
	BIT_VEC cppVar_28867;
	BIT_VEC cppVar_28868 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28869 = (cppVar_28868 << 3) | 7;
	cppVar_28869 = (cppVar_28869 & cppMask_un_5_);
	BIT_VEC cppVar_28870 = (0 << 5) | cppVar_28869;
	cppVar_28870 = (cppVar_28870 & cppMask_un_8_);
	bool cppVar_28872 = (cppVar_28870 == 137);
	if (cppVar_28872) {
	cppVar_28867 = TMOD;
	} else {
	BIT_VEC cppVar_28873;
	BIT_VEC cppVar_28874 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28875 = (cppVar_28874 << 3) | 7;
	cppVar_28875 = (cppVar_28875 & cppMask_un_5_);
	BIT_VEC cppVar_28876 = (0 << 5) | cppVar_28875;
	cppVar_28876 = (cppVar_28876 & cppMask_un_8_);
	bool cppVar_28878 = (cppVar_28876 == 138);
	if (cppVar_28878) {
	cppVar_28873 = TL0;
	} else {
	BIT_VEC cppVar_28879;
	BIT_VEC cppVar_28880 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28881 = (cppVar_28880 << 3) | 7;
	cppVar_28881 = (cppVar_28881 & cppMask_un_5_);
	BIT_VEC cppVar_28882 = (0 << 5) | cppVar_28881;
	cppVar_28882 = (cppVar_28882 & cppMask_un_8_);
	bool cppVar_28884 = (cppVar_28882 == 140);
	if (cppVar_28884) {
	cppVar_28879 = TH0;
	} else {
	BIT_VEC cppVar_28885;
	BIT_VEC cppVar_28886 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28887 = (cppVar_28886 << 3) | 7;
	cppVar_28887 = (cppVar_28887 & cppMask_un_5_);
	BIT_VEC cppVar_28888 = (0 << 5) | cppVar_28887;
	cppVar_28888 = (cppVar_28888 & cppMask_un_8_);
	bool cppVar_28890 = (cppVar_28888 == 139);
	if (cppVar_28890) {
	cppVar_28885 = TL1;
	} else {
	BIT_VEC cppVar_28891;
	BIT_VEC cppVar_28892 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28893 = (cppVar_28892 << 3) | 7;
	cppVar_28893 = (cppVar_28893 & cppMask_un_5_);
	BIT_VEC cppVar_28894 = (0 << 5) | cppVar_28893;
	cppVar_28894 = (cppVar_28894 & cppMask_un_8_);
	bool cppVar_28896 = (cppVar_28894 == 141);
	if (cppVar_28896) {
	cppVar_28891 = TH1;
	} else {
	BIT_VEC cppVar_28897;
	BIT_VEC cppVar_28898 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28899 = (cppVar_28898 << 3) | 7;
	cppVar_28899 = (cppVar_28899 & cppMask_un_5_);
	BIT_VEC cppVar_28900 = (0 << 5) | cppVar_28899;
	cppVar_28900 = (cppVar_28900 & cppMask_un_8_);
	bool cppVar_28902 = (cppVar_28900 == 144);
	if (cppVar_28902) {
	cppVar_28897 = P1;
	} else {
	BIT_VEC cppVar_28903;
	BIT_VEC cppVar_28904 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28905 = (cppVar_28904 << 3) | 7;
	cppVar_28905 = (cppVar_28905 & cppMask_un_5_);
	BIT_VEC cppVar_28906 = (0 << 5) | cppVar_28905;
	cppVar_28906 = (cppVar_28906 & cppMask_un_8_);
	bool cppVar_28908 = (cppVar_28906 == 152);
	if (cppVar_28908) {
	cppVar_28903 = SCON;
	} else {
	BIT_VEC cppVar_28909;
	BIT_VEC cppVar_28910 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28911 = (cppVar_28910 << 3) | 7;
	cppVar_28911 = (cppVar_28911 & cppMask_un_5_);
	BIT_VEC cppVar_28912 = (0 << 5) | cppVar_28911;
	cppVar_28912 = (cppVar_28912 & cppMask_un_8_);
	bool cppVar_28914 = (cppVar_28912 == 153);
	if (cppVar_28914) {
	cppVar_28909 = SBUF;
	} else {
	BIT_VEC cppVar_28915;
	BIT_VEC cppVar_28916 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28917 = (cppVar_28916 << 3) | 7;
	cppVar_28917 = (cppVar_28917 & cppMask_un_5_);
	BIT_VEC cppVar_28918 = (0 << 5) | cppVar_28917;
	cppVar_28918 = (cppVar_28918 & cppMask_un_8_);
	bool cppVar_28920 = (cppVar_28918 == 160);
	if (cppVar_28920) {
	cppVar_28915 = P2;
	} else {
	BIT_VEC cppVar_28921;
	BIT_VEC cppVar_28922 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28923 = (cppVar_28922 << 3) | 7;
	cppVar_28923 = (cppVar_28923 & cppMask_un_5_);
	BIT_VEC cppVar_28924 = (0 << 5) | cppVar_28923;
	cppVar_28924 = (cppVar_28924 & cppMask_un_8_);
	bool cppVar_28926 = (cppVar_28924 == 168);
	if (cppVar_28926) {
	cppVar_28921 = IE;
	} else {
	BIT_VEC cppVar_28927;
	BIT_VEC cppVar_28928 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28929 = (cppVar_28928 << 3) | 7;
	cppVar_28929 = (cppVar_28929 & cppMask_un_5_);
	BIT_VEC cppVar_28930 = (0 << 5) | cppVar_28929;
	cppVar_28930 = (cppVar_28930 & cppMask_un_8_);
	bool cppVar_28932 = (cppVar_28930 == 176);
	if (cppVar_28932) {
	cppVar_28927 = P3;
	} else {
	BIT_VEC cppVar_28933;
	BIT_VEC cppVar_28934 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28935 = (cppVar_28934 << 3) | 7;
	cppVar_28935 = (cppVar_28935 & cppMask_un_5_);
	BIT_VEC cppVar_28936 = (0 << 5) | cppVar_28935;
	cppVar_28936 = (cppVar_28936 & cppMask_un_8_);
	bool cppVar_28938 = (cppVar_28936 == 184);
	if (cppVar_28938) {
	cppVar_28933 = IP;
	} else {
	BIT_VEC cppVar_28939;
	BIT_VEC cppVar_28940 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28941 = (cppVar_28940 << 3) | 7;
	cppVar_28941 = (cppVar_28941 & cppMask_un_5_);
	BIT_VEC cppVar_28942 = (0 << 5) | cppVar_28941;
	cppVar_28942 = (cppVar_28942 & cppMask_un_8_);
	bool cppVar_28944 = (cppVar_28942 == 208);
	if (cppVar_28944) {
	cppVar_28939 = PSW;
	} else {
	BIT_VEC cppVar_28945;
	BIT_VEC cppVar_28946 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28947 = (cppVar_28946 << 3) | 7;
	cppVar_28947 = (cppVar_28947 & cppMask_un_5_);
	BIT_VEC cppVar_28948 = (0 << 5) | cppVar_28947;
	cppVar_28948 = (cppVar_28948 & cppMask_un_8_);
	bool cppVar_28950 = (cppVar_28948 == 224);
	if (cppVar_28950) {
	cppVar_28945 = ACC;
	} else {
	BIT_VEC cppVar_28951;
	BIT_VEC cppVar_28952 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28953 = (cppVar_28952 << 3) | 7;
	cppVar_28953 = (cppVar_28953 & cppMask_un_5_);
	BIT_VEC cppVar_28954 = (0 << 5) | cppVar_28953;
	cppVar_28954 = (cppVar_28954 & cppMask_un_8_);
	bool cppVar_28956 = (cppVar_28954 == 240);
	if (cppVar_28956) {
	cppVar_28951 = B;
	} else {
	cppVar_28951 = 0;
	}
	cppVar_28945 = cppVar_28951;
	}
	cppVar_28939 = cppVar_28945;
	}
	cppVar_28933 = cppVar_28939;
	}
	cppVar_28927 = cppVar_28933;
	}
	cppVar_28921 = cppVar_28927;
	}
	cppVar_28915 = cppVar_28921;
	}
	cppVar_28909 = cppVar_28915;
	}
	cppVar_28903 = cppVar_28909;
	}
	cppVar_28897 = cppVar_28903;
	}
	cppVar_28891 = cppVar_28897;
	}
	cppVar_28885 = cppVar_28891;
	}
	cppVar_28879 = cppVar_28885;
	}
	cppVar_28873 = cppVar_28879;
	}
	cppVar_28867 = cppVar_28873;
	}
	cppVar_28861 = cppVar_28867;
	}
	cppVar_28855 = cppVar_28861;
	}
	cppVar_28849 = cppVar_28855;
	}
	cppVar_28843 = cppVar_28849;
	}
	cppVar_28837 = cppVar_28843;
	}
	cppVar_28831 = cppVar_28837;
	}
	cppVar_28818 = cppVar_28831;
	}
	cppVar_28812 = cppVar_28818;
	} else {
	cppVar_28812 = P1;
	}
	cppVar_28808 = cppVar_28812;
	} else {
	BIT_VEC cppVar_28958;
	BIT_VEC cppVar_28959 = ROM.rd(PC);
	bool cppVar_28961 = (cppVar_28959 == 142);
	if (cppVar_28961) {
	BIT_VEC cppVar_28962;
	BIT_VEC cppVar_28964 = PC + 1;
	cppVar_28964 = (cppVar_28964 & cppMask_un_16_);
	BIT_VEC cppVar_28965 = ROM.rd(cppVar_28964);
	bool cppVar_28967 = (cppVar_28965 == 144);
	if (cppVar_28967) {
	BIT_VEC cppVar_28968;
	BIT_VEC cppVar_28970 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28972 = (cppVar_28970 << 3) | 6;
	cppVar_28972 = (cppVar_28972 & cppMask_un_5_);
	BIT_VEC cppVar_28973 = (0 << 5) | cppVar_28972;
	cppVar_28973 = (cppVar_28973 & cppMask_un_8_);
	BIT_VEC cppVar_28974 = (cppVar_28973 >> 7) & cppMask_un_1_;
	bool cppVar_28976 = (cppVar_28974 == 0);
	if (cppVar_28976) {
	BIT_VEC cppVar_28977 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28978 = (cppVar_28977 << 3) | 6;
	cppVar_28978 = (cppVar_28978 & cppMask_un_5_);
	BIT_VEC cppVar_28979 = (0 << 5) | cppVar_28978;
	cppVar_28979 = (cppVar_28979 & cppMask_un_8_);
	BIT_VEC cppVar_28980 = IRAM.rd(cppVar_28979);
	cppVar_28968 = cppVar_28980;
	} else {
	BIT_VEC cppVar_28981;
	BIT_VEC cppVar_28982 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28983 = (cppVar_28982 << 3) | 6;
	cppVar_28983 = (cppVar_28983 & cppMask_un_5_);
	BIT_VEC cppVar_28984 = (0 << 5) | cppVar_28983;
	cppVar_28984 = (cppVar_28984 & cppMask_un_8_);
	bool cppVar_28986 = (cppVar_28984 == 128);
	if (cppVar_28986) {
	cppVar_28981 = P0;
	} else {
	BIT_VEC cppVar_28987;
	BIT_VEC cppVar_28988 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28989 = (cppVar_28988 << 3) | 6;
	cppVar_28989 = (cppVar_28989 & cppMask_un_5_);
	BIT_VEC cppVar_28990 = (0 << 5) | cppVar_28989;
	cppVar_28990 = (cppVar_28990 & cppMask_un_8_);
	bool cppVar_28992 = (cppVar_28990 == 129);
	if (cppVar_28992) {
	cppVar_28987 = SP;
	} else {
	BIT_VEC cppVar_28993;
	BIT_VEC cppVar_28994 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_28995 = (cppVar_28994 << 3) | 6;
	cppVar_28995 = (cppVar_28995 & cppMask_un_5_);
	BIT_VEC cppVar_28996 = (0 << 5) | cppVar_28995;
	cppVar_28996 = (cppVar_28996 & cppMask_un_8_);
	bool cppVar_28998 = (cppVar_28996 == 130);
	if (cppVar_28998) {
	cppVar_28993 = DPL;
	} else {
	BIT_VEC cppVar_28999;
	BIT_VEC cppVar_29000 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29001 = (cppVar_29000 << 3) | 6;
	cppVar_29001 = (cppVar_29001 & cppMask_un_5_);
	BIT_VEC cppVar_29002 = (0 << 5) | cppVar_29001;
	cppVar_29002 = (cppVar_29002 & cppMask_un_8_);
	bool cppVar_29004 = (cppVar_29002 == 131);
	if (cppVar_29004) {
	cppVar_28999 = DPH;
	} else {
	BIT_VEC cppVar_29005;
	BIT_VEC cppVar_29006 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29007 = (cppVar_29006 << 3) | 6;
	cppVar_29007 = (cppVar_29007 & cppMask_un_5_);
	BIT_VEC cppVar_29008 = (0 << 5) | cppVar_29007;
	cppVar_29008 = (cppVar_29008 & cppMask_un_8_);
	bool cppVar_29010 = (cppVar_29008 == 135);
	if (cppVar_29010) {
	cppVar_29005 = PCON;
	} else {
	BIT_VEC cppVar_29011;
	BIT_VEC cppVar_29012 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29013 = (cppVar_29012 << 3) | 6;
	cppVar_29013 = (cppVar_29013 & cppMask_un_5_);
	BIT_VEC cppVar_29014 = (0 << 5) | cppVar_29013;
	cppVar_29014 = (cppVar_29014 & cppMask_un_8_);
	bool cppVar_29016 = (cppVar_29014 == 136);
	if (cppVar_29016) {
	cppVar_29011 = TCON;
	} else {
	BIT_VEC cppVar_29017;
	BIT_VEC cppVar_29018 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29019 = (cppVar_29018 << 3) | 6;
	cppVar_29019 = (cppVar_29019 & cppMask_un_5_);
	BIT_VEC cppVar_29020 = (0 << 5) | cppVar_29019;
	cppVar_29020 = (cppVar_29020 & cppMask_un_8_);
	bool cppVar_29022 = (cppVar_29020 == 137);
	if (cppVar_29022) {
	cppVar_29017 = TMOD;
	} else {
	BIT_VEC cppVar_29023;
	BIT_VEC cppVar_29024 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29025 = (cppVar_29024 << 3) | 6;
	cppVar_29025 = (cppVar_29025 & cppMask_un_5_);
	BIT_VEC cppVar_29026 = (0 << 5) | cppVar_29025;
	cppVar_29026 = (cppVar_29026 & cppMask_un_8_);
	bool cppVar_29028 = (cppVar_29026 == 138);
	if (cppVar_29028) {
	cppVar_29023 = TL0;
	} else {
	BIT_VEC cppVar_29029;
	BIT_VEC cppVar_29030 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29031 = (cppVar_29030 << 3) | 6;
	cppVar_29031 = (cppVar_29031 & cppMask_un_5_);
	BIT_VEC cppVar_29032 = (0 << 5) | cppVar_29031;
	cppVar_29032 = (cppVar_29032 & cppMask_un_8_);
	bool cppVar_29034 = (cppVar_29032 == 140);
	if (cppVar_29034) {
	cppVar_29029 = TH0;
	} else {
	BIT_VEC cppVar_29035;
	BIT_VEC cppVar_29036 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29037 = (cppVar_29036 << 3) | 6;
	cppVar_29037 = (cppVar_29037 & cppMask_un_5_);
	BIT_VEC cppVar_29038 = (0 << 5) | cppVar_29037;
	cppVar_29038 = (cppVar_29038 & cppMask_un_8_);
	bool cppVar_29040 = (cppVar_29038 == 139);
	if (cppVar_29040) {
	cppVar_29035 = TL1;
	} else {
	BIT_VEC cppVar_29041;
	BIT_VEC cppVar_29042 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29043 = (cppVar_29042 << 3) | 6;
	cppVar_29043 = (cppVar_29043 & cppMask_un_5_);
	BIT_VEC cppVar_29044 = (0 << 5) | cppVar_29043;
	cppVar_29044 = (cppVar_29044 & cppMask_un_8_);
	bool cppVar_29046 = (cppVar_29044 == 141);
	if (cppVar_29046) {
	cppVar_29041 = TH1;
	} else {
	BIT_VEC cppVar_29047;
	BIT_VEC cppVar_29048 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29049 = (cppVar_29048 << 3) | 6;
	cppVar_29049 = (cppVar_29049 & cppMask_un_5_);
	BIT_VEC cppVar_29050 = (0 << 5) | cppVar_29049;
	cppVar_29050 = (cppVar_29050 & cppMask_un_8_);
	bool cppVar_29052 = (cppVar_29050 == 144);
	if (cppVar_29052) {
	cppVar_29047 = P1;
	} else {
	BIT_VEC cppVar_29053;
	BIT_VEC cppVar_29054 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29055 = (cppVar_29054 << 3) | 6;
	cppVar_29055 = (cppVar_29055 & cppMask_un_5_);
	BIT_VEC cppVar_29056 = (0 << 5) | cppVar_29055;
	cppVar_29056 = (cppVar_29056 & cppMask_un_8_);
	bool cppVar_29058 = (cppVar_29056 == 152);
	if (cppVar_29058) {
	cppVar_29053 = SCON;
	} else {
	BIT_VEC cppVar_29059;
	BIT_VEC cppVar_29060 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29061 = (cppVar_29060 << 3) | 6;
	cppVar_29061 = (cppVar_29061 & cppMask_un_5_);
	BIT_VEC cppVar_29062 = (0 << 5) | cppVar_29061;
	cppVar_29062 = (cppVar_29062 & cppMask_un_8_);
	bool cppVar_29064 = (cppVar_29062 == 153);
	if (cppVar_29064) {
	cppVar_29059 = SBUF;
	} else {
	BIT_VEC cppVar_29065;
	BIT_VEC cppVar_29066 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29067 = (cppVar_29066 << 3) | 6;
	cppVar_29067 = (cppVar_29067 & cppMask_un_5_);
	BIT_VEC cppVar_29068 = (0 << 5) | cppVar_29067;
	cppVar_29068 = (cppVar_29068 & cppMask_un_8_);
	bool cppVar_29070 = (cppVar_29068 == 160);
	if (cppVar_29070) {
	cppVar_29065 = P2;
	} else {
	BIT_VEC cppVar_29071;
	BIT_VEC cppVar_29072 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29073 = (cppVar_29072 << 3) | 6;
	cppVar_29073 = (cppVar_29073 & cppMask_un_5_);
	BIT_VEC cppVar_29074 = (0 << 5) | cppVar_29073;
	cppVar_29074 = (cppVar_29074 & cppMask_un_8_);
	bool cppVar_29076 = (cppVar_29074 == 168);
	if (cppVar_29076) {
	cppVar_29071 = IE;
	} else {
	BIT_VEC cppVar_29077;
	BIT_VEC cppVar_29078 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29079 = (cppVar_29078 << 3) | 6;
	cppVar_29079 = (cppVar_29079 & cppMask_un_5_);
	BIT_VEC cppVar_29080 = (0 << 5) | cppVar_29079;
	cppVar_29080 = (cppVar_29080 & cppMask_un_8_);
	bool cppVar_29082 = (cppVar_29080 == 176);
	if (cppVar_29082) {
	cppVar_29077 = P3;
	} else {
	BIT_VEC cppVar_29083;
	BIT_VEC cppVar_29084 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29085 = (cppVar_29084 << 3) | 6;
	cppVar_29085 = (cppVar_29085 & cppMask_un_5_);
	BIT_VEC cppVar_29086 = (0 << 5) | cppVar_29085;
	cppVar_29086 = (cppVar_29086 & cppMask_un_8_);
	bool cppVar_29088 = (cppVar_29086 == 184);
	if (cppVar_29088) {
	cppVar_29083 = IP;
	} else {
	BIT_VEC cppVar_29089;
	BIT_VEC cppVar_29090 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29091 = (cppVar_29090 << 3) | 6;
	cppVar_29091 = (cppVar_29091 & cppMask_un_5_);
	BIT_VEC cppVar_29092 = (0 << 5) | cppVar_29091;
	cppVar_29092 = (cppVar_29092 & cppMask_un_8_);
	bool cppVar_29094 = (cppVar_29092 == 208);
	if (cppVar_29094) {
	cppVar_29089 = PSW;
	} else {
	BIT_VEC cppVar_29095;
	BIT_VEC cppVar_29096 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29097 = (cppVar_29096 << 3) | 6;
	cppVar_29097 = (cppVar_29097 & cppMask_un_5_);
	BIT_VEC cppVar_29098 = (0 << 5) | cppVar_29097;
	cppVar_29098 = (cppVar_29098 & cppMask_un_8_);
	bool cppVar_29100 = (cppVar_29098 == 224);
	if (cppVar_29100) {
	cppVar_29095 = ACC;
	} else {
	BIT_VEC cppVar_29101;
	BIT_VEC cppVar_29102 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29103 = (cppVar_29102 << 3) | 6;
	cppVar_29103 = (cppVar_29103 & cppMask_un_5_);
	BIT_VEC cppVar_29104 = (0 << 5) | cppVar_29103;
	cppVar_29104 = (cppVar_29104 & cppMask_un_8_);
	bool cppVar_29106 = (cppVar_29104 == 240);
	if (cppVar_29106) {
	cppVar_29101 = B;
	} else {
	cppVar_29101 = 0;
	}
	cppVar_29095 = cppVar_29101;
	}
	cppVar_29089 = cppVar_29095;
	}
	cppVar_29083 = cppVar_29089;
	}
	cppVar_29077 = cppVar_29083;
	}
	cppVar_29071 = cppVar_29077;
	}
	cppVar_29065 = cppVar_29071;
	}
	cppVar_29059 = cppVar_29065;
	}
	cppVar_29053 = cppVar_29059;
	}
	cppVar_29047 = cppVar_29053;
	}
	cppVar_29041 = cppVar_29047;
	}
	cppVar_29035 = cppVar_29041;
	}
	cppVar_29029 = cppVar_29035;
	}
	cppVar_29023 = cppVar_29029;
	}
	cppVar_29017 = cppVar_29023;
	}
	cppVar_29011 = cppVar_29017;
	}
	cppVar_29005 = cppVar_29011;
	}
	cppVar_28999 = cppVar_29005;
	}
	cppVar_28993 = cppVar_28999;
	}
	cppVar_28987 = cppVar_28993;
	}
	cppVar_28981 = cppVar_28987;
	}
	cppVar_28968 = cppVar_28981;
	}
	cppVar_28962 = cppVar_28968;
	} else {
	cppVar_28962 = P1;
	}
	cppVar_28958 = cppVar_28962;
	} else {
	BIT_VEC cppVar_29108;
	BIT_VEC cppVar_29109 = ROM.rd(PC);
	bool cppVar_29111 = (cppVar_29109 == 141);
	if (cppVar_29111) {
	BIT_VEC cppVar_29112;
	BIT_VEC cppVar_29114 = PC + 1;
	cppVar_29114 = (cppVar_29114 & cppMask_un_16_);
	BIT_VEC cppVar_29115 = ROM.rd(cppVar_29114);
	bool cppVar_29117 = (cppVar_29115 == 144);
	if (cppVar_29117) {
	BIT_VEC cppVar_29118;
	BIT_VEC cppVar_29120 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29122 = (cppVar_29120 << 3) | 5;
	cppVar_29122 = (cppVar_29122 & cppMask_un_5_);
	BIT_VEC cppVar_29123 = (0 << 5) | cppVar_29122;
	cppVar_29123 = (cppVar_29123 & cppMask_un_8_);
	BIT_VEC cppVar_29124 = (cppVar_29123 >> 7) & cppMask_un_1_;
	bool cppVar_29126 = (cppVar_29124 == 0);
	if (cppVar_29126) {
	BIT_VEC cppVar_29127 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29128 = (cppVar_29127 << 3) | 5;
	cppVar_29128 = (cppVar_29128 & cppMask_un_5_);
	BIT_VEC cppVar_29129 = (0 << 5) | cppVar_29128;
	cppVar_29129 = (cppVar_29129 & cppMask_un_8_);
	BIT_VEC cppVar_29130 = IRAM.rd(cppVar_29129);
	cppVar_29118 = cppVar_29130;
	} else {
	BIT_VEC cppVar_29131;
	BIT_VEC cppVar_29132 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29133 = (cppVar_29132 << 3) | 5;
	cppVar_29133 = (cppVar_29133 & cppMask_un_5_);
	BIT_VEC cppVar_29134 = (0 << 5) | cppVar_29133;
	cppVar_29134 = (cppVar_29134 & cppMask_un_8_);
	bool cppVar_29136 = (cppVar_29134 == 128);
	if (cppVar_29136) {
	cppVar_29131 = P0;
	} else {
	BIT_VEC cppVar_29137;
	BIT_VEC cppVar_29138 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29139 = (cppVar_29138 << 3) | 5;
	cppVar_29139 = (cppVar_29139 & cppMask_un_5_);
	BIT_VEC cppVar_29140 = (0 << 5) | cppVar_29139;
	cppVar_29140 = (cppVar_29140 & cppMask_un_8_);
	bool cppVar_29142 = (cppVar_29140 == 129);
	if (cppVar_29142) {
	cppVar_29137 = SP;
	} else {
	BIT_VEC cppVar_29143;
	BIT_VEC cppVar_29144 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29145 = (cppVar_29144 << 3) | 5;
	cppVar_29145 = (cppVar_29145 & cppMask_un_5_);
	BIT_VEC cppVar_29146 = (0 << 5) | cppVar_29145;
	cppVar_29146 = (cppVar_29146 & cppMask_un_8_);
	bool cppVar_29148 = (cppVar_29146 == 130);
	if (cppVar_29148) {
	cppVar_29143 = DPL;
	} else {
	BIT_VEC cppVar_29149;
	BIT_VEC cppVar_29150 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29151 = (cppVar_29150 << 3) | 5;
	cppVar_29151 = (cppVar_29151 & cppMask_un_5_);
	BIT_VEC cppVar_29152 = (0 << 5) | cppVar_29151;
	cppVar_29152 = (cppVar_29152 & cppMask_un_8_);
	bool cppVar_29154 = (cppVar_29152 == 131);
	if (cppVar_29154) {
	cppVar_29149 = DPH;
	} else {
	BIT_VEC cppVar_29155;
	BIT_VEC cppVar_29156 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29157 = (cppVar_29156 << 3) | 5;
	cppVar_29157 = (cppVar_29157 & cppMask_un_5_);
	BIT_VEC cppVar_29158 = (0 << 5) | cppVar_29157;
	cppVar_29158 = (cppVar_29158 & cppMask_un_8_);
	bool cppVar_29160 = (cppVar_29158 == 135);
	if (cppVar_29160) {
	cppVar_29155 = PCON;
	} else {
	BIT_VEC cppVar_29161;
	BIT_VEC cppVar_29162 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29163 = (cppVar_29162 << 3) | 5;
	cppVar_29163 = (cppVar_29163 & cppMask_un_5_);
	BIT_VEC cppVar_29164 = (0 << 5) | cppVar_29163;
	cppVar_29164 = (cppVar_29164 & cppMask_un_8_);
	bool cppVar_29166 = (cppVar_29164 == 136);
	if (cppVar_29166) {
	cppVar_29161 = TCON;
	} else {
	BIT_VEC cppVar_29167;
	BIT_VEC cppVar_29168 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29169 = (cppVar_29168 << 3) | 5;
	cppVar_29169 = (cppVar_29169 & cppMask_un_5_);
	BIT_VEC cppVar_29170 = (0 << 5) | cppVar_29169;
	cppVar_29170 = (cppVar_29170 & cppMask_un_8_);
	bool cppVar_29172 = (cppVar_29170 == 137);
	if (cppVar_29172) {
	cppVar_29167 = TMOD;
	} else {
	BIT_VEC cppVar_29173;
	BIT_VEC cppVar_29174 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29175 = (cppVar_29174 << 3) | 5;
	cppVar_29175 = (cppVar_29175 & cppMask_un_5_);
	BIT_VEC cppVar_29176 = (0 << 5) | cppVar_29175;
	cppVar_29176 = (cppVar_29176 & cppMask_un_8_);
	bool cppVar_29178 = (cppVar_29176 == 138);
	if (cppVar_29178) {
	cppVar_29173 = TL0;
	} else {
	BIT_VEC cppVar_29179;
	BIT_VEC cppVar_29180 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29181 = (cppVar_29180 << 3) | 5;
	cppVar_29181 = (cppVar_29181 & cppMask_un_5_);
	BIT_VEC cppVar_29182 = (0 << 5) | cppVar_29181;
	cppVar_29182 = (cppVar_29182 & cppMask_un_8_);
	bool cppVar_29184 = (cppVar_29182 == 140);
	if (cppVar_29184) {
	cppVar_29179 = TH0;
	} else {
	BIT_VEC cppVar_29185;
	BIT_VEC cppVar_29186 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29187 = (cppVar_29186 << 3) | 5;
	cppVar_29187 = (cppVar_29187 & cppMask_un_5_);
	BIT_VEC cppVar_29188 = (0 << 5) | cppVar_29187;
	cppVar_29188 = (cppVar_29188 & cppMask_un_8_);
	bool cppVar_29190 = (cppVar_29188 == 139);
	if (cppVar_29190) {
	cppVar_29185 = TL1;
	} else {
	BIT_VEC cppVar_29191;
	BIT_VEC cppVar_29192 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29193 = (cppVar_29192 << 3) | 5;
	cppVar_29193 = (cppVar_29193 & cppMask_un_5_);
	BIT_VEC cppVar_29194 = (0 << 5) | cppVar_29193;
	cppVar_29194 = (cppVar_29194 & cppMask_un_8_);
	bool cppVar_29196 = (cppVar_29194 == 141);
	if (cppVar_29196) {
	cppVar_29191 = TH1;
	} else {
	BIT_VEC cppVar_29197;
	BIT_VEC cppVar_29198 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29199 = (cppVar_29198 << 3) | 5;
	cppVar_29199 = (cppVar_29199 & cppMask_un_5_);
	BIT_VEC cppVar_29200 = (0 << 5) | cppVar_29199;
	cppVar_29200 = (cppVar_29200 & cppMask_un_8_);
	bool cppVar_29202 = (cppVar_29200 == 144);
	if (cppVar_29202) {
	cppVar_29197 = P1;
	} else {
	BIT_VEC cppVar_29203;
	BIT_VEC cppVar_29204 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29205 = (cppVar_29204 << 3) | 5;
	cppVar_29205 = (cppVar_29205 & cppMask_un_5_);
	BIT_VEC cppVar_29206 = (0 << 5) | cppVar_29205;
	cppVar_29206 = (cppVar_29206 & cppMask_un_8_);
	bool cppVar_29208 = (cppVar_29206 == 152);
	if (cppVar_29208) {
	cppVar_29203 = SCON;
	} else {
	BIT_VEC cppVar_29209;
	BIT_VEC cppVar_29210 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29211 = (cppVar_29210 << 3) | 5;
	cppVar_29211 = (cppVar_29211 & cppMask_un_5_);
	BIT_VEC cppVar_29212 = (0 << 5) | cppVar_29211;
	cppVar_29212 = (cppVar_29212 & cppMask_un_8_);
	bool cppVar_29214 = (cppVar_29212 == 153);
	if (cppVar_29214) {
	cppVar_29209 = SBUF;
	} else {
	BIT_VEC cppVar_29215;
	BIT_VEC cppVar_29216 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29217 = (cppVar_29216 << 3) | 5;
	cppVar_29217 = (cppVar_29217 & cppMask_un_5_);
	BIT_VEC cppVar_29218 = (0 << 5) | cppVar_29217;
	cppVar_29218 = (cppVar_29218 & cppMask_un_8_);
	bool cppVar_29220 = (cppVar_29218 == 160);
	if (cppVar_29220) {
	cppVar_29215 = P2;
	} else {
	BIT_VEC cppVar_29221;
	BIT_VEC cppVar_29222 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29223 = (cppVar_29222 << 3) | 5;
	cppVar_29223 = (cppVar_29223 & cppMask_un_5_);
	BIT_VEC cppVar_29224 = (0 << 5) | cppVar_29223;
	cppVar_29224 = (cppVar_29224 & cppMask_un_8_);
	bool cppVar_29226 = (cppVar_29224 == 168);
	if (cppVar_29226) {
	cppVar_29221 = IE;
	} else {
	BIT_VEC cppVar_29227;
	BIT_VEC cppVar_29228 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29229 = (cppVar_29228 << 3) | 5;
	cppVar_29229 = (cppVar_29229 & cppMask_un_5_);
	BIT_VEC cppVar_29230 = (0 << 5) | cppVar_29229;
	cppVar_29230 = (cppVar_29230 & cppMask_un_8_);
	bool cppVar_29232 = (cppVar_29230 == 176);
	if (cppVar_29232) {
	cppVar_29227 = P3;
	} else {
	BIT_VEC cppVar_29233;
	BIT_VEC cppVar_29234 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29235 = (cppVar_29234 << 3) | 5;
	cppVar_29235 = (cppVar_29235 & cppMask_un_5_);
	BIT_VEC cppVar_29236 = (0 << 5) | cppVar_29235;
	cppVar_29236 = (cppVar_29236 & cppMask_un_8_);
	bool cppVar_29238 = (cppVar_29236 == 184);
	if (cppVar_29238) {
	cppVar_29233 = IP;
	} else {
	BIT_VEC cppVar_29239;
	BIT_VEC cppVar_29240 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29241 = (cppVar_29240 << 3) | 5;
	cppVar_29241 = (cppVar_29241 & cppMask_un_5_);
	BIT_VEC cppVar_29242 = (0 << 5) | cppVar_29241;
	cppVar_29242 = (cppVar_29242 & cppMask_un_8_);
	bool cppVar_29244 = (cppVar_29242 == 208);
	if (cppVar_29244) {
	cppVar_29239 = PSW;
	} else {
	BIT_VEC cppVar_29245;
	BIT_VEC cppVar_29246 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29247 = (cppVar_29246 << 3) | 5;
	cppVar_29247 = (cppVar_29247 & cppMask_un_5_);
	BIT_VEC cppVar_29248 = (0 << 5) | cppVar_29247;
	cppVar_29248 = (cppVar_29248 & cppMask_un_8_);
	bool cppVar_29250 = (cppVar_29248 == 224);
	if (cppVar_29250) {
	cppVar_29245 = ACC;
	} else {
	BIT_VEC cppVar_29251;
	BIT_VEC cppVar_29252 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29253 = (cppVar_29252 << 3) | 5;
	cppVar_29253 = (cppVar_29253 & cppMask_un_5_);
	BIT_VEC cppVar_29254 = (0 << 5) | cppVar_29253;
	cppVar_29254 = (cppVar_29254 & cppMask_un_8_);
	bool cppVar_29256 = (cppVar_29254 == 240);
	if (cppVar_29256) {
	cppVar_29251 = B;
	} else {
	cppVar_29251 = 0;
	}
	cppVar_29245 = cppVar_29251;
	}
	cppVar_29239 = cppVar_29245;
	}
	cppVar_29233 = cppVar_29239;
	}
	cppVar_29227 = cppVar_29233;
	}
	cppVar_29221 = cppVar_29227;
	}
	cppVar_29215 = cppVar_29221;
	}
	cppVar_29209 = cppVar_29215;
	}
	cppVar_29203 = cppVar_29209;
	}
	cppVar_29197 = cppVar_29203;
	}
	cppVar_29191 = cppVar_29197;
	}
	cppVar_29185 = cppVar_29191;
	}
	cppVar_29179 = cppVar_29185;
	}
	cppVar_29173 = cppVar_29179;
	}
	cppVar_29167 = cppVar_29173;
	}
	cppVar_29161 = cppVar_29167;
	}
	cppVar_29155 = cppVar_29161;
	}
	cppVar_29149 = cppVar_29155;
	}
	cppVar_29143 = cppVar_29149;
	}
	cppVar_29137 = cppVar_29143;
	}
	cppVar_29131 = cppVar_29137;
	}
	cppVar_29118 = cppVar_29131;
	}
	cppVar_29112 = cppVar_29118;
	} else {
	cppVar_29112 = P1;
	}
	cppVar_29108 = cppVar_29112;
	} else {
	BIT_VEC cppVar_29258;
	BIT_VEC cppVar_29259 = ROM.rd(PC);
	bool cppVar_29261 = (cppVar_29259 == 140);
	if (cppVar_29261) {
	BIT_VEC cppVar_29262;
	BIT_VEC cppVar_29264 = PC + 1;
	cppVar_29264 = (cppVar_29264 & cppMask_un_16_);
	BIT_VEC cppVar_29265 = ROM.rd(cppVar_29264);
	bool cppVar_29267 = (cppVar_29265 == 144);
	if (cppVar_29267) {
	BIT_VEC cppVar_29268;
	BIT_VEC cppVar_29270 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29272 = (cppVar_29270 << 3) | 4;
	cppVar_29272 = (cppVar_29272 & cppMask_un_5_);
	BIT_VEC cppVar_29273 = (0 << 5) | cppVar_29272;
	cppVar_29273 = (cppVar_29273 & cppMask_un_8_);
	BIT_VEC cppVar_29274 = (cppVar_29273 >> 7) & cppMask_un_1_;
	bool cppVar_29276 = (cppVar_29274 == 0);
	if (cppVar_29276) {
	BIT_VEC cppVar_29277 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29278 = (cppVar_29277 << 3) | 4;
	cppVar_29278 = (cppVar_29278 & cppMask_un_5_);
	BIT_VEC cppVar_29279 = (0 << 5) | cppVar_29278;
	cppVar_29279 = (cppVar_29279 & cppMask_un_8_);
	BIT_VEC cppVar_29280 = IRAM.rd(cppVar_29279);
	cppVar_29268 = cppVar_29280;
	} else {
	BIT_VEC cppVar_29281;
	BIT_VEC cppVar_29282 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29283 = (cppVar_29282 << 3) | 4;
	cppVar_29283 = (cppVar_29283 & cppMask_un_5_);
	BIT_VEC cppVar_29284 = (0 << 5) | cppVar_29283;
	cppVar_29284 = (cppVar_29284 & cppMask_un_8_);
	bool cppVar_29286 = (cppVar_29284 == 128);
	if (cppVar_29286) {
	cppVar_29281 = P0;
	} else {
	BIT_VEC cppVar_29287;
	BIT_VEC cppVar_29288 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29289 = (cppVar_29288 << 3) | 4;
	cppVar_29289 = (cppVar_29289 & cppMask_un_5_);
	BIT_VEC cppVar_29290 = (0 << 5) | cppVar_29289;
	cppVar_29290 = (cppVar_29290 & cppMask_un_8_);
	bool cppVar_29292 = (cppVar_29290 == 129);
	if (cppVar_29292) {
	cppVar_29287 = SP;
	} else {
	BIT_VEC cppVar_29293;
	BIT_VEC cppVar_29294 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29295 = (cppVar_29294 << 3) | 4;
	cppVar_29295 = (cppVar_29295 & cppMask_un_5_);
	BIT_VEC cppVar_29296 = (0 << 5) | cppVar_29295;
	cppVar_29296 = (cppVar_29296 & cppMask_un_8_);
	bool cppVar_29298 = (cppVar_29296 == 130);
	if (cppVar_29298) {
	cppVar_29293 = DPL;
	} else {
	BIT_VEC cppVar_29299;
	BIT_VEC cppVar_29300 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29301 = (cppVar_29300 << 3) | 4;
	cppVar_29301 = (cppVar_29301 & cppMask_un_5_);
	BIT_VEC cppVar_29302 = (0 << 5) | cppVar_29301;
	cppVar_29302 = (cppVar_29302 & cppMask_un_8_);
	bool cppVar_29304 = (cppVar_29302 == 131);
	if (cppVar_29304) {
	cppVar_29299 = DPH;
	} else {
	BIT_VEC cppVar_29305;
	BIT_VEC cppVar_29306 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29307 = (cppVar_29306 << 3) | 4;
	cppVar_29307 = (cppVar_29307 & cppMask_un_5_);
	BIT_VEC cppVar_29308 = (0 << 5) | cppVar_29307;
	cppVar_29308 = (cppVar_29308 & cppMask_un_8_);
	bool cppVar_29310 = (cppVar_29308 == 135);
	if (cppVar_29310) {
	cppVar_29305 = PCON;
	} else {
	BIT_VEC cppVar_29311;
	BIT_VEC cppVar_29312 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29313 = (cppVar_29312 << 3) | 4;
	cppVar_29313 = (cppVar_29313 & cppMask_un_5_);
	BIT_VEC cppVar_29314 = (0 << 5) | cppVar_29313;
	cppVar_29314 = (cppVar_29314 & cppMask_un_8_);
	bool cppVar_29316 = (cppVar_29314 == 136);
	if (cppVar_29316) {
	cppVar_29311 = TCON;
	} else {
	BIT_VEC cppVar_29317;
	BIT_VEC cppVar_29318 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29319 = (cppVar_29318 << 3) | 4;
	cppVar_29319 = (cppVar_29319 & cppMask_un_5_);
	BIT_VEC cppVar_29320 = (0 << 5) | cppVar_29319;
	cppVar_29320 = (cppVar_29320 & cppMask_un_8_);
	bool cppVar_29322 = (cppVar_29320 == 137);
	if (cppVar_29322) {
	cppVar_29317 = TMOD;
	} else {
	BIT_VEC cppVar_29323;
	BIT_VEC cppVar_29324 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29325 = (cppVar_29324 << 3) | 4;
	cppVar_29325 = (cppVar_29325 & cppMask_un_5_);
	BIT_VEC cppVar_29326 = (0 << 5) | cppVar_29325;
	cppVar_29326 = (cppVar_29326 & cppMask_un_8_);
	bool cppVar_29328 = (cppVar_29326 == 138);
	if (cppVar_29328) {
	cppVar_29323 = TL0;
	} else {
	BIT_VEC cppVar_29329;
	BIT_VEC cppVar_29330 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29331 = (cppVar_29330 << 3) | 4;
	cppVar_29331 = (cppVar_29331 & cppMask_un_5_);
	BIT_VEC cppVar_29332 = (0 << 5) | cppVar_29331;
	cppVar_29332 = (cppVar_29332 & cppMask_un_8_);
	bool cppVar_29334 = (cppVar_29332 == 140);
	if (cppVar_29334) {
	cppVar_29329 = TH0;
	} else {
	BIT_VEC cppVar_29335;
	BIT_VEC cppVar_29336 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29337 = (cppVar_29336 << 3) | 4;
	cppVar_29337 = (cppVar_29337 & cppMask_un_5_);
	BIT_VEC cppVar_29338 = (0 << 5) | cppVar_29337;
	cppVar_29338 = (cppVar_29338 & cppMask_un_8_);
	bool cppVar_29340 = (cppVar_29338 == 139);
	if (cppVar_29340) {
	cppVar_29335 = TL1;
	} else {
	BIT_VEC cppVar_29341;
	BIT_VEC cppVar_29342 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29343 = (cppVar_29342 << 3) | 4;
	cppVar_29343 = (cppVar_29343 & cppMask_un_5_);
	BIT_VEC cppVar_29344 = (0 << 5) | cppVar_29343;
	cppVar_29344 = (cppVar_29344 & cppMask_un_8_);
	bool cppVar_29346 = (cppVar_29344 == 141);
	if (cppVar_29346) {
	cppVar_29341 = TH1;
	} else {
	BIT_VEC cppVar_29347;
	BIT_VEC cppVar_29348 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29349 = (cppVar_29348 << 3) | 4;
	cppVar_29349 = (cppVar_29349 & cppMask_un_5_);
	BIT_VEC cppVar_29350 = (0 << 5) | cppVar_29349;
	cppVar_29350 = (cppVar_29350 & cppMask_un_8_);
	bool cppVar_29352 = (cppVar_29350 == 144);
	if (cppVar_29352) {
	cppVar_29347 = P1;
	} else {
	BIT_VEC cppVar_29353;
	BIT_VEC cppVar_29354 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29355 = (cppVar_29354 << 3) | 4;
	cppVar_29355 = (cppVar_29355 & cppMask_un_5_);
	BIT_VEC cppVar_29356 = (0 << 5) | cppVar_29355;
	cppVar_29356 = (cppVar_29356 & cppMask_un_8_);
	bool cppVar_29358 = (cppVar_29356 == 152);
	if (cppVar_29358) {
	cppVar_29353 = SCON;
	} else {
	BIT_VEC cppVar_29359;
	BIT_VEC cppVar_29360 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29361 = (cppVar_29360 << 3) | 4;
	cppVar_29361 = (cppVar_29361 & cppMask_un_5_);
	BIT_VEC cppVar_29362 = (0 << 5) | cppVar_29361;
	cppVar_29362 = (cppVar_29362 & cppMask_un_8_);
	bool cppVar_29364 = (cppVar_29362 == 153);
	if (cppVar_29364) {
	cppVar_29359 = SBUF;
	} else {
	BIT_VEC cppVar_29365;
	BIT_VEC cppVar_29366 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29367 = (cppVar_29366 << 3) | 4;
	cppVar_29367 = (cppVar_29367 & cppMask_un_5_);
	BIT_VEC cppVar_29368 = (0 << 5) | cppVar_29367;
	cppVar_29368 = (cppVar_29368 & cppMask_un_8_);
	bool cppVar_29370 = (cppVar_29368 == 160);
	if (cppVar_29370) {
	cppVar_29365 = P2;
	} else {
	BIT_VEC cppVar_29371;
	BIT_VEC cppVar_29372 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29373 = (cppVar_29372 << 3) | 4;
	cppVar_29373 = (cppVar_29373 & cppMask_un_5_);
	BIT_VEC cppVar_29374 = (0 << 5) | cppVar_29373;
	cppVar_29374 = (cppVar_29374 & cppMask_un_8_);
	bool cppVar_29376 = (cppVar_29374 == 168);
	if (cppVar_29376) {
	cppVar_29371 = IE;
	} else {
	BIT_VEC cppVar_29377;
	BIT_VEC cppVar_29378 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29379 = (cppVar_29378 << 3) | 4;
	cppVar_29379 = (cppVar_29379 & cppMask_un_5_);
	BIT_VEC cppVar_29380 = (0 << 5) | cppVar_29379;
	cppVar_29380 = (cppVar_29380 & cppMask_un_8_);
	bool cppVar_29382 = (cppVar_29380 == 176);
	if (cppVar_29382) {
	cppVar_29377 = P3;
	} else {
	BIT_VEC cppVar_29383;
	BIT_VEC cppVar_29384 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29385 = (cppVar_29384 << 3) | 4;
	cppVar_29385 = (cppVar_29385 & cppMask_un_5_);
	BIT_VEC cppVar_29386 = (0 << 5) | cppVar_29385;
	cppVar_29386 = (cppVar_29386 & cppMask_un_8_);
	bool cppVar_29388 = (cppVar_29386 == 184);
	if (cppVar_29388) {
	cppVar_29383 = IP;
	} else {
	BIT_VEC cppVar_29389;
	BIT_VEC cppVar_29390 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29391 = (cppVar_29390 << 3) | 4;
	cppVar_29391 = (cppVar_29391 & cppMask_un_5_);
	BIT_VEC cppVar_29392 = (0 << 5) | cppVar_29391;
	cppVar_29392 = (cppVar_29392 & cppMask_un_8_);
	bool cppVar_29394 = (cppVar_29392 == 208);
	if (cppVar_29394) {
	cppVar_29389 = PSW;
	} else {
	BIT_VEC cppVar_29395;
	BIT_VEC cppVar_29396 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29397 = (cppVar_29396 << 3) | 4;
	cppVar_29397 = (cppVar_29397 & cppMask_un_5_);
	BIT_VEC cppVar_29398 = (0 << 5) | cppVar_29397;
	cppVar_29398 = (cppVar_29398 & cppMask_un_8_);
	bool cppVar_29400 = (cppVar_29398 == 224);
	if (cppVar_29400) {
	cppVar_29395 = ACC;
	} else {
	BIT_VEC cppVar_29401;
	BIT_VEC cppVar_29402 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29403 = (cppVar_29402 << 3) | 4;
	cppVar_29403 = (cppVar_29403 & cppMask_un_5_);
	BIT_VEC cppVar_29404 = (0 << 5) | cppVar_29403;
	cppVar_29404 = (cppVar_29404 & cppMask_un_8_);
	bool cppVar_29406 = (cppVar_29404 == 240);
	if (cppVar_29406) {
	cppVar_29401 = B;
	} else {
	cppVar_29401 = 0;
	}
	cppVar_29395 = cppVar_29401;
	}
	cppVar_29389 = cppVar_29395;
	}
	cppVar_29383 = cppVar_29389;
	}
	cppVar_29377 = cppVar_29383;
	}
	cppVar_29371 = cppVar_29377;
	}
	cppVar_29365 = cppVar_29371;
	}
	cppVar_29359 = cppVar_29365;
	}
	cppVar_29353 = cppVar_29359;
	}
	cppVar_29347 = cppVar_29353;
	}
	cppVar_29341 = cppVar_29347;
	}
	cppVar_29335 = cppVar_29341;
	}
	cppVar_29329 = cppVar_29335;
	}
	cppVar_29323 = cppVar_29329;
	}
	cppVar_29317 = cppVar_29323;
	}
	cppVar_29311 = cppVar_29317;
	}
	cppVar_29305 = cppVar_29311;
	}
	cppVar_29299 = cppVar_29305;
	}
	cppVar_29293 = cppVar_29299;
	}
	cppVar_29287 = cppVar_29293;
	}
	cppVar_29281 = cppVar_29287;
	}
	cppVar_29268 = cppVar_29281;
	}
	cppVar_29262 = cppVar_29268;
	} else {
	cppVar_29262 = P1;
	}
	cppVar_29258 = cppVar_29262;
	} else {
	BIT_VEC cppVar_29408;
	BIT_VEC cppVar_29409 = ROM.rd(PC);
	bool cppVar_29411 = (cppVar_29409 == 139);
	if (cppVar_29411) {
	BIT_VEC cppVar_29412;
	BIT_VEC cppVar_29414 = PC + 1;
	cppVar_29414 = (cppVar_29414 & cppMask_un_16_);
	BIT_VEC cppVar_29415 = ROM.rd(cppVar_29414);
	bool cppVar_29417 = (cppVar_29415 == 144);
	if (cppVar_29417) {
	BIT_VEC cppVar_29418;
	BIT_VEC cppVar_29420 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29422 = (cppVar_29420 << 3) | 3;
	cppVar_29422 = (cppVar_29422 & cppMask_un_5_);
	BIT_VEC cppVar_29423 = (0 << 5) | cppVar_29422;
	cppVar_29423 = (cppVar_29423 & cppMask_un_8_);
	BIT_VEC cppVar_29424 = (cppVar_29423 >> 7) & cppMask_un_1_;
	bool cppVar_29426 = (cppVar_29424 == 0);
	if (cppVar_29426) {
	BIT_VEC cppVar_29427 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29428 = (cppVar_29427 << 3) | 3;
	cppVar_29428 = (cppVar_29428 & cppMask_un_5_);
	BIT_VEC cppVar_29429 = (0 << 5) | cppVar_29428;
	cppVar_29429 = (cppVar_29429 & cppMask_un_8_);
	BIT_VEC cppVar_29430 = IRAM.rd(cppVar_29429);
	cppVar_29418 = cppVar_29430;
	} else {
	BIT_VEC cppVar_29431;
	BIT_VEC cppVar_29432 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29433 = (cppVar_29432 << 3) | 3;
	cppVar_29433 = (cppVar_29433 & cppMask_un_5_);
	BIT_VEC cppVar_29434 = (0 << 5) | cppVar_29433;
	cppVar_29434 = (cppVar_29434 & cppMask_un_8_);
	bool cppVar_29436 = (cppVar_29434 == 128);
	if (cppVar_29436) {
	cppVar_29431 = P0;
	} else {
	BIT_VEC cppVar_29437;
	BIT_VEC cppVar_29438 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29439 = (cppVar_29438 << 3) | 3;
	cppVar_29439 = (cppVar_29439 & cppMask_un_5_);
	BIT_VEC cppVar_29440 = (0 << 5) | cppVar_29439;
	cppVar_29440 = (cppVar_29440 & cppMask_un_8_);
	bool cppVar_29442 = (cppVar_29440 == 129);
	if (cppVar_29442) {
	cppVar_29437 = SP;
	} else {
	BIT_VEC cppVar_29443;
	BIT_VEC cppVar_29444 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29445 = (cppVar_29444 << 3) | 3;
	cppVar_29445 = (cppVar_29445 & cppMask_un_5_);
	BIT_VEC cppVar_29446 = (0 << 5) | cppVar_29445;
	cppVar_29446 = (cppVar_29446 & cppMask_un_8_);
	bool cppVar_29448 = (cppVar_29446 == 130);
	if (cppVar_29448) {
	cppVar_29443 = DPL;
	} else {
	BIT_VEC cppVar_29449;
	BIT_VEC cppVar_29450 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29451 = (cppVar_29450 << 3) | 3;
	cppVar_29451 = (cppVar_29451 & cppMask_un_5_);
	BIT_VEC cppVar_29452 = (0 << 5) | cppVar_29451;
	cppVar_29452 = (cppVar_29452 & cppMask_un_8_);
	bool cppVar_29454 = (cppVar_29452 == 131);
	if (cppVar_29454) {
	cppVar_29449 = DPH;
	} else {
	BIT_VEC cppVar_29455;
	BIT_VEC cppVar_29456 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29457 = (cppVar_29456 << 3) | 3;
	cppVar_29457 = (cppVar_29457 & cppMask_un_5_);
	BIT_VEC cppVar_29458 = (0 << 5) | cppVar_29457;
	cppVar_29458 = (cppVar_29458 & cppMask_un_8_);
	bool cppVar_29460 = (cppVar_29458 == 135);
	if (cppVar_29460) {
	cppVar_29455 = PCON;
	} else {
	BIT_VEC cppVar_29461;
	BIT_VEC cppVar_29462 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29463 = (cppVar_29462 << 3) | 3;
	cppVar_29463 = (cppVar_29463 & cppMask_un_5_);
	BIT_VEC cppVar_29464 = (0 << 5) | cppVar_29463;
	cppVar_29464 = (cppVar_29464 & cppMask_un_8_);
	bool cppVar_29466 = (cppVar_29464 == 136);
	if (cppVar_29466) {
	cppVar_29461 = TCON;
	} else {
	BIT_VEC cppVar_29467;
	BIT_VEC cppVar_29468 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29469 = (cppVar_29468 << 3) | 3;
	cppVar_29469 = (cppVar_29469 & cppMask_un_5_);
	BIT_VEC cppVar_29470 = (0 << 5) | cppVar_29469;
	cppVar_29470 = (cppVar_29470 & cppMask_un_8_);
	bool cppVar_29472 = (cppVar_29470 == 137);
	if (cppVar_29472) {
	cppVar_29467 = TMOD;
	} else {
	BIT_VEC cppVar_29473;
	BIT_VEC cppVar_29474 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29475 = (cppVar_29474 << 3) | 3;
	cppVar_29475 = (cppVar_29475 & cppMask_un_5_);
	BIT_VEC cppVar_29476 = (0 << 5) | cppVar_29475;
	cppVar_29476 = (cppVar_29476 & cppMask_un_8_);
	bool cppVar_29478 = (cppVar_29476 == 138);
	if (cppVar_29478) {
	cppVar_29473 = TL0;
	} else {
	BIT_VEC cppVar_29479;
	BIT_VEC cppVar_29480 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29481 = (cppVar_29480 << 3) | 3;
	cppVar_29481 = (cppVar_29481 & cppMask_un_5_);
	BIT_VEC cppVar_29482 = (0 << 5) | cppVar_29481;
	cppVar_29482 = (cppVar_29482 & cppMask_un_8_);
	bool cppVar_29484 = (cppVar_29482 == 140);
	if (cppVar_29484) {
	cppVar_29479 = TH0;
	} else {
	BIT_VEC cppVar_29485;
	BIT_VEC cppVar_29486 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29487 = (cppVar_29486 << 3) | 3;
	cppVar_29487 = (cppVar_29487 & cppMask_un_5_);
	BIT_VEC cppVar_29488 = (0 << 5) | cppVar_29487;
	cppVar_29488 = (cppVar_29488 & cppMask_un_8_);
	bool cppVar_29490 = (cppVar_29488 == 139);
	if (cppVar_29490) {
	cppVar_29485 = TL1;
	} else {
	BIT_VEC cppVar_29491;
	BIT_VEC cppVar_29492 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29493 = (cppVar_29492 << 3) | 3;
	cppVar_29493 = (cppVar_29493 & cppMask_un_5_);
	BIT_VEC cppVar_29494 = (0 << 5) | cppVar_29493;
	cppVar_29494 = (cppVar_29494 & cppMask_un_8_);
	bool cppVar_29496 = (cppVar_29494 == 141);
	if (cppVar_29496) {
	cppVar_29491 = TH1;
	} else {
	BIT_VEC cppVar_29497;
	BIT_VEC cppVar_29498 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29499 = (cppVar_29498 << 3) | 3;
	cppVar_29499 = (cppVar_29499 & cppMask_un_5_);
	BIT_VEC cppVar_29500 = (0 << 5) | cppVar_29499;
	cppVar_29500 = (cppVar_29500 & cppMask_un_8_);
	bool cppVar_29502 = (cppVar_29500 == 144);
	if (cppVar_29502) {
	cppVar_29497 = P1;
	} else {
	BIT_VEC cppVar_29503;
	BIT_VEC cppVar_29504 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29505 = (cppVar_29504 << 3) | 3;
	cppVar_29505 = (cppVar_29505 & cppMask_un_5_);
	BIT_VEC cppVar_29506 = (0 << 5) | cppVar_29505;
	cppVar_29506 = (cppVar_29506 & cppMask_un_8_);
	bool cppVar_29508 = (cppVar_29506 == 152);
	if (cppVar_29508) {
	cppVar_29503 = SCON;
	} else {
	BIT_VEC cppVar_29509;
	BIT_VEC cppVar_29510 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29511 = (cppVar_29510 << 3) | 3;
	cppVar_29511 = (cppVar_29511 & cppMask_un_5_);
	BIT_VEC cppVar_29512 = (0 << 5) | cppVar_29511;
	cppVar_29512 = (cppVar_29512 & cppMask_un_8_);
	bool cppVar_29514 = (cppVar_29512 == 153);
	if (cppVar_29514) {
	cppVar_29509 = SBUF;
	} else {
	BIT_VEC cppVar_29515;
	BIT_VEC cppVar_29516 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29517 = (cppVar_29516 << 3) | 3;
	cppVar_29517 = (cppVar_29517 & cppMask_un_5_);
	BIT_VEC cppVar_29518 = (0 << 5) | cppVar_29517;
	cppVar_29518 = (cppVar_29518 & cppMask_un_8_);
	bool cppVar_29520 = (cppVar_29518 == 160);
	if (cppVar_29520) {
	cppVar_29515 = P2;
	} else {
	BIT_VEC cppVar_29521;
	BIT_VEC cppVar_29522 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29523 = (cppVar_29522 << 3) | 3;
	cppVar_29523 = (cppVar_29523 & cppMask_un_5_);
	BIT_VEC cppVar_29524 = (0 << 5) | cppVar_29523;
	cppVar_29524 = (cppVar_29524 & cppMask_un_8_);
	bool cppVar_29526 = (cppVar_29524 == 168);
	if (cppVar_29526) {
	cppVar_29521 = IE;
	} else {
	BIT_VEC cppVar_29527;
	BIT_VEC cppVar_29528 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29529 = (cppVar_29528 << 3) | 3;
	cppVar_29529 = (cppVar_29529 & cppMask_un_5_);
	BIT_VEC cppVar_29530 = (0 << 5) | cppVar_29529;
	cppVar_29530 = (cppVar_29530 & cppMask_un_8_);
	bool cppVar_29532 = (cppVar_29530 == 176);
	if (cppVar_29532) {
	cppVar_29527 = P3;
	} else {
	BIT_VEC cppVar_29533;
	BIT_VEC cppVar_29534 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29535 = (cppVar_29534 << 3) | 3;
	cppVar_29535 = (cppVar_29535 & cppMask_un_5_);
	BIT_VEC cppVar_29536 = (0 << 5) | cppVar_29535;
	cppVar_29536 = (cppVar_29536 & cppMask_un_8_);
	bool cppVar_29538 = (cppVar_29536 == 184);
	if (cppVar_29538) {
	cppVar_29533 = IP;
	} else {
	BIT_VEC cppVar_29539;
	BIT_VEC cppVar_29540 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29541 = (cppVar_29540 << 3) | 3;
	cppVar_29541 = (cppVar_29541 & cppMask_un_5_);
	BIT_VEC cppVar_29542 = (0 << 5) | cppVar_29541;
	cppVar_29542 = (cppVar_29542 & cppMask_un_8_);
	bool cppVar_29544 = (cppVar_29542 == 208);
	if (cppVar_29544) {
	cppVar_29539 = PSW;
	} else {
	BIT_VEC cppVar_29545;
	BIT_VEC cppVar_29546 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29547 = (cppVar_29546 << 3) | 3;
	cppVar_29547 = (cppVar_29547 & cppMask_un_5_);
	BIT_VEC cppVar_29548 = (0 << 5) | cppVar_29547;
	cppVar_29548 = (cppVar_29548 & cppMask_un_8_);
	bool cppVar_29550 = (cppVar_29548 == 224);
	if (cppVar_29550) {
	cppVar_29545 = ACC;
	} else {
	BIT_VEC cppVar_29551;
	BIT_VEC cppVar_29552 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29553 = (cppVar_29552 << 3) | 3;
	cppVar_29553 = (cppVar_29553 & cppMask_un_5_);
	BIT_VEC cppVar_29554 = (0 << 5) | cppVar_29553;
	cppVar_29554 = (cppVar_29554 & cppMask_un_8_);
	bool cppVar_29556 = (cppVar_29554 == 240);
	if (cppVar_29556) {
	cppVar_29551 = B;
	} else {
	cppVar_29551 = 0;
	}
	cppVar_29545 = cppVar_29551;
	}
	cppVar_29539 = cppVar_29545;
	}
	cppVar_29533 = cppVar_29539;
	}
	cppVar_29527 = cppVar_29533;
	}
	cppVar_29521 = cppVar_29527;
	}
	cppVar_29515 = cppVar_29521;
	}
	cppVar_29509 = cppVar_29515;
	}
	cppVar_29503 = cppVar_29509;
	}
	cppVar_29497 = cppVar_29503;
	}
	cppVar_29491 = cppVar_29497;
	}
	cppVar_29485 = cppVar_29491;
	}
	cppVar_29479 = cppVar_29485;
	}
	cppVar_29473 = cppVar_29479;
	}
	cppVar_29467 = cppVar_29473;
	}
	cppVar_29461 = cppVar_29467;
	}
	cppVar_29455 = cppVar_29461;
	}
	cppVar_29449 = cppVar_29455;
	}
	cppVar_29443 = cppVar_29449;
	}
	cppVar_29437 = cppVar_29443;
	}
	cppVar_29431 = cppVar_29437;
	}
	cppVar_29418 = cppVar_29431;
	}
	cppVar_29412 = cppVar_29418;
	} else {
	cppVar_29412 = P1;
	}
	cppVar_29408 = cppVar_29412;
	} else {
	BIT_VEC cppVar_29558;
	BIT_VEC cppVar_29559 = ROM.rd(PC);
	bool cppVar_29561 = (cppVar_29559 == 138);
	if (cppVar_29561) {
	BIT_VEC cppVar_29562;
	BIT_VEC cppVar_29564 = PC + 1;
	cppVar_29564 = (cppVar_29564 & cppMask_un_16_);
	BIT_VEC cppVar_29565 = ROM.rd(cppVar_29564);
	bool cppVar_29567 = (cppVar_29565 == 144);
	if (cppVar_29567) {
	BIT_VEC cppVar_29568;
	BIT_VEC cppVar_29570 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29572 = (cppVar_29570 << 3) | 2;
	cppVar_29572 = (cppVar_29572 & cppMask_un_5_);
	BIT_VEC cppVar_29573 = (0 << 5) | cppVar_29572;
	cppVar_29573 = (cppVar_29573 & cppMask_un_8_);
	BIT_VEC cppVar_29574 = (cppVar_29573 >> 7) & cppMask_un_1_;
	bool cppVar_29576 = (cppVar_29574 == 0);
	if (cppVar_29576) {
	BIT_VEC cppVar_29577 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29578 = (cppVar_29577 << 3) | 2;
	cppVar_29578 = (cppVar_29578 & cppMask_un_5_);
	BIT_VEC cppVar_29579 = (0 << 5) | cppVar_29578;
	cppVar_29579 = (cppVar_29579 & cppMask_un_8_);
	BIT_VEC cppVar_29580 = IRAM.rd(cppVar_29579);
	cppVar_29568 = cppVar_29580;
	} else {
	BIT_VEC cppVar_29581;
	BIT_VEC cppVar_29582 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29583 = (cppVar_29582 << 3) | 2;
	cppVar_29583 = (cppVar_29583 & cppMask_un_5_);
	BIT_VEC cppVar_29584 = (0 << 5) | cppVar_29583;
	cppVar_29584 = (cppVar_29584 & cppMask_un_8_);
	bool cppVar_29586 = (cppVar_29584 == 128);
	if (cppVar_29586) {
	cppVar_29581 = P0;
	} else {
	BIT_VEC cppVar_29587;
	BIT_VEC cppVar_29588 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29589 = (cppVar_29588 << 3) | 2;
	cppVar_29589 = (cppVar_29589 & cppMask_un_5_);
	BIT_VEC cppVar_29590 = (0 << 5) | cppVar_29589;
	cppVar_29590 = (cppVar_29590 & cppMask_un_8_);
	bool cppVar_29592 = (cppVar_29590 == 129);
	if (cppVar_29592) {
	cppVar_29587 = SP;
	} else {
	BIT_VEC cppVar_29593;
	BIT_VEC cppVar_29594 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29595 = (cppVar_29594 << 3) | 2;
	cppVar_29595 = (cppVar_29595 & cppMask_un_5_);
	BIT_VEC cppVar_29596 = (0 << 5) | cppVar_29595;
	cppVar_29596 = (cppVar_29596 & cppMask_un_8_);
	bool cppVar_29598 = (cppVar_29596 == 130);
	if (cppVar_29598) {
	cppVar_29593 = DPL;
	} else {
	BIT_VEC cppVar_29599;
	BIT_VEC cppVar_29600 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29601 = (cppVar_29600 << 3) | 2;
	cppVar_29601 = (cppVar_29601 & cppMask_un_5_);
	BIT_VEC cppVar_29602 = (0 << 5) | cppVar_29601;
	cppVar_29602 = (cppVar_29602 & cppMask_un_8_);
	bool cppVar_29604 = (cppVar_29602 == 131);
	if (cppVar_29604) {
	cppVar_29599 = DPH;
	} else {
	BIT_VEC cppVar_29605;
	BIT_VEC cppVar_29606 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29607 = (cppVar_29606 << 3) | 2;
	cppVar_29607 = (cppVar_29607 & cppMask_un_5_);
	BIT_VEC cppVar_29608 = (0 << 5) | cppVar_29607;
	cppVar_29608 = (cppVar_29608 & cppMask_un_8_);
	bool cppVar_29610 = (cppVar_29608 == 135);
	if (cppVar_29610) {
	cppVar_29605 = PCON;
	} else {
	BIT_VEC cppVar_29611;
	BIT_VEC cppVar_29612 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29613 = (cppVar_29612 << 3) | 2;
	cppVar_29613 = (cppVar_29613 & cppMask_un_5_);
	BIT_VEC cppVar_29614 = (0 << 5) | cppVar_29613;
	cppVar_29614 = (cppVar_29614 & cppMask_un_8_);
	bool cppVar_29616 = (cppVar_29614 == 136);
	if (cppVar_29616) {
	cppVar_29611 = TCON;
	} else {
	BIT_VEC cppVar_29617;
	BIT_VEC cppVar_29618 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29619 = (cppVar_29618 << 3) | 2;
	cppVar_29619 = (cppVar_29619 & cppMask_un_5_);
	BIT_VEC cppVar_29620 = (0 << 5) | cppVar_29619;
	cppVar_29620 = (cppVar_29620 & cppMask_un_8_);
	bool cppVar_29622 = (cppVar_29620 == 137);
	if (cppVar_29622) {
	cppVar_29617 = TMOD;
	} else {
	BIT_VEC cppVar_29623;
	BIT_VEC cppVar_29624 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29625 = (cppVar_29624 << 3) | 2;
	cppVar_29625 = (cppVar_29625 & cppMask_un_5_);
	BIT_VEC cppVar_29626 = (0 << 5) | cppVar_29625;
	cppVar_29626 = (cppVar_29626 & cppMask_un_8_);
	bool cppVar_29628 = (cppVar_29626 == 138);
	if (cppVar_29628) {
	cppVar_29623 = TL0;
	} else {
	BIT_VEC cppVar_29629;
	BIT_VEC cppVar_29630 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29631 = (cppVar_29630 << 3) | 2;
	cppVar_29631 = (cppVar_29631 & cppMask_un_5_);
	BIT_VEC cppVar_29632 = (0 << 5) | cppVar_29631;
	cppVar_29632 = (cppVar_29632 & cppMask_un_8_);
	bool cppVar_29634 = (cppVar_29632 == 140);
	if (cppVar_29634) {
	cppVar_29629 = TH0;
	} else {
	BIT_VEC cppVar_29635;
	BIT_VEC cppVar_29636 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29637 = (cppVar_29636 << 3) | 2;
	cppVar_29637 = (cppVar_29637 & cppMask_un_5_);
	BIT_VEC cppVar_29638 = (0 << 5) | cppVar_29637;
	cppVar_29638 = (cppVar_29638 & cppMask_un_8_);
	bool cppVar_29640 = (cppVar_29638 == 139);
	if (cppVar_29640) {
	cppVar_29635 = TL1;
	} else {
	BIT_VEC cppVar_29641;
	BIT_VEC cppVar_29642 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29643 = (cppVar_29642 << 3) | 2;
	cppVar_29643 = (cppVar_29643 & cppMask_un_5_);
	BIT_VEC cppVar_29644 = (0 << 5) | cppVar_29643;
	cppVar_29644 = (cppVar_29644 & cppMask_un_8_);
	bool cppVar_29646 = (cppVar_29644 == 141);
	if (cppVar_29646) {
	cppVar_29641 = TH1;
	} else {
	BIT_VEC cppVar_29647;
	BIT_VEC cppVar_29648 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29649 = (cppVar_29648 << 3) | 2;
	cppVar_29649 = (cppVar_29649 & cppMask_un_5_);
	BIT_VEC cppVar_29650 = (0 << 5) | cppVar_29649;
	cppVar_29650 = (cppVar_29650 & cppMask_un_8_);
	bool cppVar_29652 = (cppVar_29650 == 144);
	if (cppVar_29652) {
	cppVar_29647 = P1;
	} else {
	BIT_VEC cppVar_29653;
	BIT_VEC cppVar_29654 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29655 = (cppVar_29654 << 3) | 2;
	cppVar_29655 = (cppVar_29655 & cppMask_un_5_);
	BIT_VEC cppVar_29656 = (0 << 5) | cppVar_29655;
	cppVar_29656 = (cppVar_29656 & cppMask_un_8_);
	bool cppVar_29658 = (cppVar_29656 == 152);
	if (cppVar_29658) {
	cppVar_29653 = SCON;
	} else {
	BIT_VEC cppVar_29659;
	BIT_VEC cppVar_29660 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29661 = (cppVar_29660 << 3) | 2;
	cppVar_29661 = (cppVar_29661 & cppMask_un_5_);
	BIT_VEC cppVar_29662 = (0 << 5) | cppVar_29661;
	cppVar_29662 = (cppVar_29662 & cppMask_un_8_);
	bool cppVar_29664 = (cppVar_29662 == 153);
	if (cppVar_29664) {
	cppVar_29659 = SBUF;
	} else {
	BIT_VEC cppVar_29665;
	BIT_VEC cppVar_29666 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29667 = (cppVar_29666 << 3) | 2;
	cppVar_29667 = (cppVar_29667 & cppMask_un_5_);
	BIT_VEC cppVar_29668 = (0 << 5) | cppVar_29667;
	cppVar_29668 = (cppVar_29668 & cppMask_un_8_);
	bool cppVar_29670 = (cppVar_29668 == 160);
	if (cppVar_29670) {
	cppVar_29665 = P2;
	} else {
	BIT_VEC cppVar_29671;
	BIT_VEC cppVar_29672 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29673 = (cppVar_29672 << 3) | 2;
	cppVar_29673 = (cppVar_29673 & cppMask_un_5_);
	BIT_VEC cppVar_29674 = (0 << 5) | cppVar_29673;
	cppVar_29674 = (cppVar_29674 & cppMask_un_8_);
	bool cppVar_29676 = (cppVar_29674 == 168);
	if (cppVar_29676) {
	cppVar_29671 = IE;
	} else {
	BIT_VEC cppVar_29677;
	BIT_VEC cppVar_29678 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29679 = (cppVar_29678 << 3) | 2;
	cppVar_29679 = (cppVar_29679 & cppMask_un_5_);
	BIT_VEC cppVar_29680 = (0 << 5) | cppVar_29679;
	cppVar_29680 = (cppVar_29680 & cppMask_un_8_);
	bool cppVar_29682 = (cppVar_29680 == 176);
	if (cppVar_29682) {
	cppVar_29677 = P3;
	} else {
	BIT_VEC cppVar_29683;
	BIT_VEC cppVar_29684 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29685 = (cppVar_29684 << 3) | 2;
	cppVar_29685 = (cppVar_29685 & cppMask_un_5_);
	BIT_VEC cppVar_29686 = (0 << 5) | cppVar_29685;
	cppVar_29686 = (cppVar_29686 & cppMask_un_8_);
	bool cppVar_29688 = (cppVar_29686 == 184);
	if (cppVar_29688) {
	cppVar_29683 = IP;
	} else {
	BIT_VEC cppVar_29689;
	BIT_VEC cppVar_29690 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29691 = (cppVar_29690 << 3) | 2;
	cppVar_29691 = (cppVar_29691 & cppMask_un_5_);
	BIT_VEC cppVar_29692 = (0 << 5) | cppVar_29691;
	cppVar_29692 = (cppVar_29692 & cppMask_un_8_);
	bool cppVar_29694 = (cppVar_29692 == 208);
	if (cppVar_29694) {
	cppVar_29689 = PSW;
	} else {
	BIT_VEC cppVar_29695;
	BIT_VEC cppVar_29696 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29697 = (cppVar_29696 << 3) | 2;
	cppVar_29697 = (cppVar_29697 & cppMask_un_5_);
	BIT_VEC cppVar_29698 = (0 << 5) | cppVar_29697;
	cppVar_29698 = (cppVar_29698 & cppMask_un_8_);
	bool cppVar_29700 = (cppVar_29698 == 224);
	if (cppVar_29700) {
	cppVar_29695 = ACC;
	} else {
	BIT_VEC cppVar_29701;
	BIT_VEC cppVar_29702 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29703 = (cppVar_29702 << 3) | 2;
	cppVar_29703 = (cppVar_29703 & cppMask_un_5_);
	BIT_VEC cppVar_29704 = (0 << 5) | cppVar_29703;
	cppVar_29704 = (cppVar_29704 & cppMask_un_8_);
	bool cppVar_29706 = (cppVar_29704 == 240);
	if (cppVar_29706) {
	cppVar_29701 = B;
	} else {
	cppVar_29701 = 0;
	}
	cppVar_29695 = cppVar_29701;
	}
	cppVar_29689 = cppVar_29695;
	}
	cppVar_29683 = cppVar_29689;
	}
	cppVar_29677 = cppVar_29683;
	}
	cppVar_29671 = cppVar_29677;
	}
	cppVar_29665 = cppVar_29671;
	}
	cppVar_29659 = cppVar_29665;
	}
	cppVar_29653 = cppVar_29659;
	}
	cppVar_29647 = cppVar_29653;
	}
	cppVar_29641 = cppVar_29647;
	}
	cppVar_29635 = cppVar_29641;
	}
	cppVar_29629 = cppVar_29635;
	}
	cppVar_29623 = cppVar_29629;
	}
	cppVar_29617 = cppVar_29623;
	}
	cppVar_29611 = cppVar_29617;
	}
	cppVar_29605 = cppVar_29611;
	}
	cppVar_29599 = cppVar_29605;
	}
	cppVar_29593 = cppVar_29599;
	}
	cppVar_29587 = cppVar_29593;
	}
	cppVar_29581 = cppVar_29587;
	}
	cppVar_29568 = cppVar_29581;
	}
	cppVar_29562 = cppVar_29568;
	} else {
	cppVar_29562 = P1;
	}
	cppVar_29558 = cppVar_29562;
	} else {
	BIT_VEC cppVar_29708;
	BIT_VEC cppVar_29709 = ROM.rd(PC);
	bool cppVar_29711 = (cppVar_29709 == 137);
	if (cppVar_29711) {
	BIT_VEC cppVar_29712;
	BIT_VEC cppVar_29714 = PC + 1;
	cppVar_29714 = (cppVar_29714 & cppMask_un_16_);
	BIT_VEC cppVar_29715 = ROM.rd(cppVar_29714);
	bool cppVar_29717 = (cppVar_29715 == 144);
	if (cppVar_29717) {
	BIT_VEC cppVar_29718;
	BIT_VEC cppVar_29720 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29722 = (cppVar_29720 << 3) | 1;
	cppVar_29722 = (cppVar_29722 & cppMask_un_5_);
	BIT_VEC cppVar_29723 = (0 << 5) | cppVar_29722;
	cppVar_29723 = (cppVar_29723 & cppMask_un_8_);
	BIT_VEC cppVar_29724 = (cppVar_29723 >> 7) & cppMask_un_1_;
	bool cppVar_29726 = (cppVar_29724 == 0);
	if (cppVar_29726) {
	BIT_VEC cppVar_29727 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29728 = (cppVar_29727 << 3) | 1;
	cppVar_29728 = (cppVar_29728 & cppMask_un_5_);
	BIT_VEC cppVar_29729 = (0 << 5) | cppVar_29728;
	cppVar_29729 = (cppVar_29729 & cppMask_un_8_);
	BIT_VEC cppVar_29730 = IRAM.rd(cppVar_29729);
	cppVar_29718 = cppVar_29730;
	} else {
	BIT_VEC cppVar_29731;
	BIT_VEC cppVar_29732 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29733 = (cppVar_29732 << 3) | 1;
	cppVar_29733 = (cppVar_29733 & cppMask_un_5_);
	BIT_VEC cppVar_29734 = (0 << 5) | cppVar_29733;
	cppVar_29734 = (cppVar_29734 & cppMask_un_8_);
	bool cppVar_29736 = (cppVar_29734 == 128);
	if (cppVar_29736) {
	cppVar_29731 = P0;
	} else {
	BIT_VEC cppVar_29737;
	BIT_VEC cppVar_29738 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29739 = (cppVar_29738 << 3) | 1;
	cppVar_29739 = (cppVar_29739 & cppMask_un_5_);
	BIT_VEC cppVar_29740 = (0 << 5) | cppVar_29739;
	cppVar_29740 = (cppVar_29740 & cppMask_un_8_);
	bool cppVar_29742 = (cppVar_29740 == 129);
	if (cppVar_29742) {
	cppVar_29737 = SP;
	} else {
	BIT_VEC cppVar_29743;
	BIT_VEC cppVar_29744 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29745 = (cppVar_29744 << 3) | 1;
	cppVar_29745 = (cppVar_29745 & cppMask_un_5_);
	BIT_VEC cppVar_29746 = (0 << 5) | cppVar_29745;
	cppVar_29746 = (cppVar_29746 & cppMask_un_8_);
	bool cppVar_29748 = (cppVar_29746 == 130);
	if (cppVar_29748) {
	cppVar_29743 = DPL;
	} else {
	BIT_VEC cppVar_29749;
	BIT_VEC cppVar_29750 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29751 = (cppVar_29750 << 3) | 1;
	cppVar_29751 = (cppVar_29751 & cppMask_un_5_);
	BIT_VEC cppVar_29752 = (0 << 5) | cppVar_29751;
	cppVar_29752 = (cppVar_29752 & cppMask_un_8_);
	bool cppVar_29754 = (cppVar_29752 == 131);
	if (cppVar_29754) {
	cppVar_29749 = DPH;
	} else {
	BIT_VEC cppVar_29755;
	BIT_VEC cppVar_29756 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29757 = (cppVar_29756 << 3) | 1;
	cppVar_29757 = (cppVar_29757 & cppMask_un_5_);
	BIT_VEC cppVar_29758 = (0 << 5) | cppVar_29757;
	cppVar_29758 = (cppVar_29758 & cppMask_un_8_);
	bool cppVar_29760 = (cppVar_29758 == 135);
	if (cppVar_29760) {
	cppVar_29755 = PCON;
	} else {
	BIT_VEC cppVar_29761;
	BIT_VEC cppVar_29762 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29763 = (cppVar_29762 << 3) | 1;
	cppVar_29763 = (cppVar_29763 & cppMask_un_5_);
	BIT_VEC cppVar_29764 = (0 << 5) | cppVar_29763;
	cppVar_29764 = (cppVar_29764 & cppMask_un_8_);
	bool cppVar_29766 = (cppVar_29764 == 136);
	if (cppVar_29766) {
	cppVar_29761 = TCON;
	} else {
	BIT_VEC cppVar_29767;
	BIT_VEC cppVar_29768 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29769 = (cppVar_29768 << 3) | 1;
	cppVar_29769 = (cppVar_29769 & cppMask_un_5_);
	BIT_VEC cppVar_29770 = (0 << 5) | cppVar_29769;
	cppVar_29770 = (cppVar_29770 & cppMask_un_8_);
	bool cppVar_29772 = (cppVar_29770 == 137);
	if (cppVar_29772) {
	cppVar_29767 = TMOD;
	} else {
	BIT_VEC cppVar_29773;
	BIT_VEC cppVar_29774 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29775 = (cppVar_29774 << 3) | 1;
	cppVar_29775 = (cppVar_29775 & cppMask_un_5_);
	BIT_VEC cppVar_29776 = (0 << 5) | cppVar_29775;
	cppVar_29776 = (cppVar_29776 & cppMask_un_8_);
	bool cppVar_29778 = (cppVar_29776 == 138);
	if (cppVar_29778) {
	cppVar_29773 = TL0;
	} else {
	BIT_VEC cppVar_29779;
	BIT_VEC cppVar_29780 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29781 = (cppVar_29780 << 3) | 1;
	cppVar_29781 = (cppVar_29781 & cppMask_un_5_);
	BIT_VEC cppVar_29782 = (0 << 5) | cppVar_29781;
	cppVar_29782 = (cppVar_29782 & cppMask_un_8_);
	bool cppVar_29784 = (cppVar_29782 == 140);
	if (cppVar_29784) {
	cppVar_29779 = TH0;
	} else {
	BIT_VEC cppVar_29785;
	BIT_VEC cppVar_29786 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29787 = (cppVar_29786 << 3) | 1;
	cppVar_29787 = (cppVar_29787 & cppMask_un_5_);
	BIT_VEC cppVar_29788 = (0 << 5) | cppVar_29787;
	cppVar_29788 = (cppVar_29788 & cppMask_un_8_);
	bool cppVar_29790 = (cppVar_29788 == 139);
	if (cppVar_29790) {
	cppVar_29785 = TL1;
	} else {
	BIT_VEC cppVar_29791;
	BIT_VEC cppVar_29792 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29793 = (cppVar_29792 << 3) | 1;
	cppVar_29793 = (cppVar_29793 & cppMask_un_5_);
	BIT_VEC cppVar_29794 = (0 << 5) | cppVar_29793;
	cppVar_29794 = (cppVar_29794 & cppMask_un_8_);
	bool cppVar_29796 = (cppVar_29794 == 141);
	if (cppVar_29796) {
	cppVar_29791 = TH1;
	} else {
	BIT_VEC cppVar_29797;
	BIT_VEC cppVar_29798 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29799 = (cppVar_29798 << 3) | 1;
	cppVar_29799 = (cppVar_29799 & cppMask_un_5_);
	BIT_VEC cppVar_29800 = (0 << 5) | cppVar_29799;
	cppVar_29800 = (cppVar_29800 & cppMask_un_8_);
	bool cppVar_29802 = (cppVar_29800 == 144);
	if (cppVar_29802) {
	cppVar_29797 = P1;
	} else {
	BIT_VEC cppVar_29803;
	BIT_VEC cppVar_29804 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29805 = (cppVar_29804 << 3) | 1;
	cppVar_29805 = (cppVar_29805 & cppMask_un_5_);
	BIT_VEC cppVar_29806 = (0 << 5) | cppVar_29805;
	cppVar_29806 = (cppVar_29806 & cppMask_un_8_);
	bool cppVar_29808 = (cppVar_29806 == 152);
	if (cppVar_29808) {
	cppVar_29803 = SCON;
	} else {
	BIT_VEC cppVar_29809;
	BIT_VEC cppVar_29810 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29811 = (cppVar_29810 << 3) | 1;
	cppVar_29811 = (cppVar_29811 & cppMask_un_5_);
	BIT_VEC cppVar_29812 = (0 << 5) | cppVar_29811;
	cppVar_29812 = (cppVar_29812 & cppMask_un_8_);
	bool cppVar_29814 = (cppVar_29812 == 153);
	if (cppVar_29814) {
	cppVar_29809 = SBUF;
	} else {
	BIT_VEC cppVar_29815;
	BIT_VEC cppVar_29816 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29817 = (cppVar_29816 << 3) | 1;
	cppVar_29817 = (cppVar_29817 & cppMask_un_5_);
	BIT_VEC cppVar_29818 = (0 << 5) | cppVar_29817;
	cppVar_29818 = (cppVar_29818 & cppMask_un_8_);
	bool cppVar_29820 = (cppVar_29818 == 160);
	if (cppVar_29820) {
	cppVar_29815 = P2;
	} else {
	BIT_VEC cppVar_29821;
	BIT_VEC cppVar_29822 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29823 = (cppVar_29822 << 3) | 1;
	cppVar_29823 = (cppVar_29823 & cppMask_un_5_);
	BIT_VEC cppVar_29824 = (0 << 5) | cppVar_29823;
	cppVar_29824 = (cppVar_29824 & cppMask_un_8_);
	bool cppVar_29826 = (cppVar_29824 == 168);
	if (cppVar_29826) {
	cppVar_29821 = IE;
	} else {
	BIT_VEC cppVar_29827;
	BIT_VEC cppVar_29828 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29829 = (cppVar_29828 << 3) | 1;
	cppVar_29829 = (cppVar_29829 & cppMask_un_5_);
	BIT_VEC cppVar_29830 = (0 << 5) | cppVar_29829;
	cppVar_29830 = (cppVar_29830 & cppMask_un_8_);
	bool cppVar_29832 = (cppVar_29830 == 176);
	if (cppVar_29832) {
	cppVar_29827 = P3;
	} else {
	BIT_VEC cppVar_29833;
	BIT_VEC cppVar_29834 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29835 = (cppVar_29834 << 3) | 1;
	cppVar_29835 = (cppVar_29835 & cppMask_un_5_);
	BIT_VEC cppVar_29836 = (0 << 5) | cppVar_29835;
	cppVar_29836 = (cppVar_29836 & cppMask_un_8_);
	bool cppVar_29838 = (cppVar_29836 == 184);
	if (cppVar_29838) {
	cppVar_29833 = IP;
	} else {
	BIT_VEC cppVar_29839;
	BIT_VEC cppVar_29840 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29841 = (cppVar_29840 << 3) | 1;
	cppVar_29841 = (cppVar_29841 & cppMask_un_5_);
	BIT_VEC cppVar_29842 = (0 << 5) | cppVar_29841;
	cppVar_29842 = (cppVar_29842 & cppMask_un_8_);
	bool cppVar_29844 = (cppVar_29842 == 208);
	if (cppVar_29844) {
	cppVar_29839 = PSW;
	} else {
	BIT_VEC cppVar_29845;
	BIT_VEC cppVar_29846 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29847 = (cppVar_29846 << 3) | 1;
	cppVar_29847 = (cppVar_29847 & cppMask_un_5_);
	BIT_VEC cppVar_29848 = (0 << 5) | cppVar_29847;
	cppVar_29848 = (cppVar_29848 & cppMask_un_8_);
	bool cppVar_29850 = (cppVar_29848 == 224);
	if (cppVar_29850) {
	cppVar_29845 = ACC;
	} else {
	BIT_VEC cppVar_29851;
	BIT_VEC cppVar_29852 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29853 = (cppVar_29852 << 3) | 1;
	cppVar_29853 = (cppVar_29853 & cppMask_un_5_);
	BIT_VEC cppVar_29854 = (0 << 5) | cppVar_29853;
	cppVar_29854 = (cppVar_29854 & cppMask_un_8_);
	bool cppVar_29856 = (cppVar_29854 == 240);
	if (cppVar_29856) {
	cppVar_29851 = B;
	} else {
	cppVar_29851 = 0;
	}
	cppVar_29845 = cppVar_29851;
	}
	cppVar_29839 = cppVar_29845;
	}
	cppVar_29833 = cppVar_29839;
	}
	cppVar_29827 = cppVar_29833;
	}
	cppVar_29821 = cppVar_29827;
	}
	cppVar_29815 = cppVar_29821;
	}
	cppVar_29809 = cppVar_29815;
	}
	cppVar_29803 = cppVar_29809;
	}
	cppVar_29797 = cppVar_29803;
	}
	cppVar_29791 = cppVar_29797;
	}
	cppVar_29785 = cppVar_29791;
	}
	cppVar_29779 = cppVar_29785;
	}
	cppVar_29773 = cppVar_29779;
	}
	cppVar_29767 = cppVar_29773;
	}
	cppVar_29761 = cppVar_29767;
	}
	cppVar_29755 = cppVar_29761;
	}
	cppVar_29749 = cppVar_29755;
	}
	cppVar_29743 = cppVar_29749;
	}
	cppVar_29737 = cppVar_29743;
	}
	cppVar_29731 = cppVar_29737;
	}
	cppVar_29718 = cppVar_29731;
	}
	cppVar_29712 = cppVar_29718;
	} else {
	cppVar_29712 = P1;
	}
	cppVar_29708 = cppVar_29712;
	} else {
	BIT_VEC cppVar_29858;
	BIT_VEC cppVar_29859 = ROM.rd(PC);
	bool cppVar_29861 = (cppVar_29859 == 136);
	if (cppVar_29861) {
	BIT_VEC cppVar_29862;
	BIT_VEC cppVar_29864 = PC + 1;
	cppVar_29864 = (cppVar_29864 & cppMask_un_16_);
	BIT_VEC cppVar_29865 = ROM.rd(cppVar_29864);
	bool cppVar_29867 = (cppVar_29865 == 144);
	if (cppVar_29867) {
	BIT_VEC cppVar_29868;
	BIT_VEC cppVar_29870 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29872 = (cppVar_29870 << 3) | 0;
	cppVar_29872 = (cppVar_29872 & cppMask_un_5_);
	BIT_VEC cppVar_29873 = (0 << 5) | cppVar_29872;
	cppVar_29873 = (cppVar_29873 & cppMask_un_8_);
	BIT_VEC cppVar_29874 = (cppVar_29873 >> 7) & cppMask_un_1_;
	bool cppVar_29876 = (cppVar_29874 == 0);
	if (cppVar_29876) {
	BIT_VEC cppVar_29877 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29878 = (cppVar_29877 << 3) | 0;
	cppVar_29878 = (cppVar_29878 & cppMask_un_5_);
	BIT_VEC cppVar_29879 = (0 << 5) | cppVar_29878;
	cppVar_29879 = (cppVar_29879 & cppMask_un_8_);
	BIT_VEC cppVar_29880 = IRAM.rd(cppVar_29879);
	cppVar_29868 = cppVar_29880;
	} else {
	BIT_VEC cppVar_29881;
	BIT_VEC cppVar_29882 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29883 = (cppVar_29882 << 3) | 0;
	cppVar_29883 = (cppVar_29883 & cppMask_un_5_);
	BIT_VEC cppVar_29884 = (0 << 5) | cppVar_29883;
	cppVar_29884 = (cppVar_29884 & cppMask_un_8_);
	bool cppVar_29886 = (cppVar_29884 == 128);
	if (cppVar_29886) {
	cppVar_29881 = P0;
	} else {
	BIT_VEC cppVar_29887;
	BIT_VEC cppVar_29888 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29889 = (cppVar_29888 << 3) | 0;
	cppVar_29889 = (cppVar_29889 & cppMask_un_5_);
	BIT_VEC cppVar_29890 = (0 << 5) | cppVar_29889;
	cppVar_29890 = (cppVar_29890 & cppMask_un_8_);
	bool cppVar_29892 = (cppVar_29890 == 129);
	if (cppVar_29892) {
	cppVar_29887 = SP;
	} else {
	BIT_VEC cppVar_29893;
	BIT_VEC cppVar_29894 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29895 = (cppVar_29894 << 3) | 0;
	cppVar_29895 = (cppVar_29895 & cppMask_un_5_);
	BIT_VEC cppVar_29896 = (0 << 5) | cppVar_29895;
	cppVar_29896 = (cppVar_29896 & cppMask_un_8_);
	bool cppVar_29898 = (cppVar_29896 == 130);
	if (cppVar_29898) {
	cppVar_29893 = DPL;
	} else {
	BIT_VEC cppVar_29899;
	BIT_VEC cppVar_29900 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29901 = (cppVar_29900 << 3) | 0;
	cppVar_29901 = (cppVar_29901 & cppMask_un_5_);
	BIT_VEC cppVar_29902 = (0 << 5) | cppVar_29901;
	cppVar_29902 = (cppVar_29902 & cppMask_un_8_);
	bool cppVar_29904 = (cppVar_29902 == 131);
	if (cppVar_29904) {
	cppVar_29899 = DPH;
	} else {
	BIT_VEC cppVar_29905;
	BIT_VEC cppVar_29906 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29907 = (cppVar_29906 << 3) | 0;
	cppVar_29907 = (cppVar_29907 & cppMask_un_5_);
	BIT_VEC cppVar_29908 = (0 << 5) | cppVar_29907;
	cppVar_29908 = (cppVar_29908 & cppMask_un_8_);
	bool cppVar_29910 = (cppVar_29908 == 135);
	if (cppVar_29910) {
	cppVar_29905 = PCON;
	} else {
	BIT_VEC cppVar_29911;
	BIT_VEC cppVar_29912 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29913 = (cppVar_29912 << 3) | 0;
	cppVar_29913 = (cppVar_29913 & cppMask_un_5_);
	BIT_VEC cppVar_29914 = (0 << 5) | cppVar_29913;
	cppVar_29914 = (cppVar_29914 & cppMask_un_8_);
	bool cppVar_29916 = (cppVar_29914 == 136);
	if (cppVar_29916) {
	cppVar_29911 = TCON;
	} else {
	BIT_VEC cppVar_29917;
	BIT_VEC cppVar_29918 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29919 = (cppVar_29918 << 3) | 0;
	cppVar_29919 = (cppVar_29919 & cppMask_un_5_);
	BIT_VEC cppVar_29920 = (0 << 5) | cppVar_29919;
	cppVar_29920 = (cppVar_29920 & cppMask_un_8_);
	bool cppVar_29922 = (cppVar_29920 == 137);
	if (cppVar_29922) {
	cppVar_29917 = TMOD;
	} else {
	BIT_VEC cppVar_29923;
	BIT_VEC cppVar_29924 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29925 = (cppVar_29924 << 3) | 0;
	cppVar_29925 = (cppVar_29925 & cppMask_un_5_);
	BIT_VEC cppVar_29926 = (0 << 5) | cppVar_29925;
	cppVar_29926 = (cppVar_29926 & cppMask_un_8_);
	bool cppVar_29928 = (cppVar_29926 == 138);
	if (cppVar_29928) {
	cppVar_29923 = TL0;
	} else {
	BIT_VEC cppVar_29929;
	BIT_VEC cppVar_29930 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29931 = (cppVar_29930 << 3) | 0;
	cppVar_29931 = (cppVar_29931 & cppMask_un_5_);
	BIT_VEC cppVar_29932 = (0 << 5) | cppVar_29931;
	cppVar_29932 = (cppVar_29932 & cppMask_un_8_);
	bool cppVar_29934 = (cppVar_29932 == 140);
	if (cppVar_29934) {
	cppVar_29929 = TH0;
	} else {
	BIT_VEC cppVar_29935;
	BIT_VEC cppVar_29936 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29937 = (cppVar_29936 << 3) | 0;
	cppVar_29937 = (cppVar_29937 & cppMask_un_5_);
	BIT_VEC cppVar_29938 = (0 << 5) | cppVar_29937;
	cppVar_29938 = (cppVar_29938 & cppMask_un_8_);
	bool cppVar_29940 = (cppVar_29938 == 139);
	if (cppVar_29940) {
	cppVar_29935 = TL1;
	} else {
	BIT_VEC cppVar_29941;
	BIT_VEC cppVar_29942 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29943 = (cppVar_29942 << 3) | 0;
	cppVar_29943 = (cppVar_29943 & cppMask_un_5_);
	BIT_VEC cppVar_29944 = (0 << 5) | cppVar_29943;
	cppVar_29944 = (cppVar_29944 & cppMask_un_8_);
	bool cppVar_29946 = (cppVar_29944 == 141);
	if (cppVar_29946) {
	cppVar_29941 = TH1;
	} else {
	BIT_VEC cppVar_29947;
	BIT_VEC cppVar_29948 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29949 = (cppVar_29948 << 3) | 0;
	cppVar_29949 = (cppVar_29949 & cppMask_un_5_);
	BIT_VEC cppVar_29950 = (0 << 5) | cppVar_29949;
	cppVar_29950 = (cppVar_29950 & cppMask_un_8_);
	bool cppVar_29952 = (cppVar_29950 == 144);
	if (cppVar_29952) {
	cppVar_29947 = P1;
	} else {
	BIT_VEC cppVar_29953;
	BIT_VEC cppVar_29954 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29955 = (cppVar_29954 << 3) | 0;
	cppVar_29955 = (cppVar_29955 & cppMask_un_5_);
	BIT_VEC cppVar_29956 = (0 << 5) | cppVar_29955;
	cppVar_29956 = (cppVar_29956 & cppMask_un_8_);
	bool cppVar_29958 = (cppVar_29956 == 152);
	if (cppVar_29958) {
	cppVar_29953 = SCON;
	} else {
	BIT_VEC cppVar_29959;
	BIT_VEC cppVar_29960 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29961 = (cppVar_29960 << 3) | 0;
	cppVar_29961 = (cppVar_29961 & cppMask_un_5_);
	BIT_VEC cppVar_29962 = (0 << 5) | cppVar_29961;
	cppVar_29962 = (cppVar_29962 & cppMask_un_8_);
	bool cppVar_29964 = (cppVar_29962 == 153);
	if (cppVar_29964) {
	cppVar_29959 = SBUF;
	} else {
	BIT_VEC cppVar_29965;
	BIT_VEC cppVar_29966 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29967 = (cppVar_29966 << 3) | 0;
	cppVar_29967 = (cppVar_29967 & cppMask_un_5_);
	BIT_VEC cppVar_29968 = (0 << 5) | cppVar_29967;
	cppVar_29968 = (cppVar_29968 & cppMask_un_8_);
	bool cppVar_29970 = (cppVar_29968 == 160);
	if (cppVar_29970) {
	cppVar_29965 = P2;
	} else {
	BIT_VEC cppVar_29971;
	BIT_VEC cppVar_29972 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29973 = (cppVar_29972 << 3) | 0;
	cppVar_29973 = (cppVar_29973 & cppMask_un_5_);
	BIT_VEC cppVar_29974 = (0 << 5) | cppVar_29973;
	cppVar_29974 = (cppVar_29974 & cppMask_un_8_);
	bool cppVar_29976 = (cppVar_29974 == 168);
	if (cppVar_29976) {
	cppVar_29971 = IE;
	} else {
	BIT_VEC cppVar_29977;
	BIT_VEC cppVar_29978 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29979 = (cppVar_29978 << 3) | 0;
	cppVar_29979 = (cppVar_29979 & cppMask_un_5_);
	BIT_VEC cppVar_29980 = (0 << 5) | cppVar_29979;
	cppVar_29980 = (cppVar_29980 & cppMask_un_8_);
	bool cppVar_29982 = (cppVar_29980 == 176);
	if (cppVar_29982) {
	cppVar_29977 = P3;
	} else {
	BIT_VEC cppVar_29983;
	BIT_VEC cppVar_29984 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29985 = (cppVar_29984 << 3) | 0;
	cppVar_29985 = (cppVar_29985 & cppMask_un_5_);
	BIT_VEC cppVar_29986 = (0 << 5) | cppVar_29985;
	cppVar_29986 = (cppVar_29986 & cppMask_un_8_);
	bool cppVar_29988 = (cppVar_29986 == 184);
	if (cppVar_29988) {
	cppVar_29983 = IP;
	} else {
	BIT_VEC cppVar_29989;
	BIT_VEC cppVar_29990 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29991 = (cppVar_29990 << 3) | 0;
	cppVar_29991 = (cppVar_29991 & cppMask_un_5_);
	BIT_VEC cppVar_29992 = (0 << 5) | cppVar_29991;
	cppVar_29992 = (cppVar_29992 & cppMask_un_8_);
	bool cppVar_29994 = (cppVar_29992 == 208);
	if (cppVar_29994) {
	cppVar_29989 = PSW;
	} else {
	BIT_VEC cppVar_29995;
	BIT_VEC cppVar_29996 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_29997 = (cppVar_29996 << 3) | 0;
	cppVar_29997 = (cppVar_29997 & cppMask_un_5_);
	BIT_VEC cppVar_29998 = (0 << 5) | cppVar_29997;
	cppVar_29998 = (cppVar_29998 & cppMask_un_8_);
	bool cppVar_30000 = (cppVar_29998 == 224);
	if (cppVar_30000) {
	cppVar_29995 = ACC;
	} else {
	BIT_VEC cppVar_30001;
	BIT_VEC cppVar_30002 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_30003 = (cppVar_30002 << 3) | 0;
	cppVar_30003 = (cppVar_30003 & cppMask_un_5_);
	BIT_VEC cppVar_30004 = (0 << 5) | cppVar_30003;
	cppVar_30004 = (cppVar_30004 & cppMask_un_8_);
	bool cppVar_30006 = (cppVar_30004 == 240);
	if (cppVar_30006) {
	cppVar_30001 = B;
	} else {
	cppVar_30001 = 0;
	}
	cppVar_29995 = cppVar_30001;
	}
	cppVar_29989 = cppVar_29995;
	}
	cppVar_29983 = cppVar_29989;
	}
	cppVar_29977 = cppVar_29983;
	}
	cppVar_29971 = cppVar_29977;
	}
	cppVar_29965 = cppVar_29971;
	}
	cppVar_29959 = cppVar_29965;
	}
	cppVar_29953 = cppVar_29959;
	}
	cppVar_29947 = cppVar_29953;
	}
	cppVar_29941 = cppVar_29947;
	}
	cppVar_29935 = cppVar_29941;
	}
	cppVar_29929 = cppVar_29935;
	}
	cppVar_29923 = cppVar_29929;
	}
	cppVar_29917 = cppVar_29923;
	}
	cppVar_29911 = cppVar_29917;
	}
	cppVar_29905 = cppVar_29911;
	}
	cppVar_29899 = cppVar_29905;
	}
	cppVar_29893 = cppVar_29899;
	}
	cppVar_29887 = cppVar_29893;
	}
	cppVar_29881 = cppVar_29887;
	}
	cppVar_29868 = cppVar_29881;
	}
	cppVar_29862 = cppVar_29868;
	} else {
	cppVar_29862 = P1;
	}
	cppVar_29858 = cppVar_29862;
	} else {
	BIT_VEC cppVar_30008;
	BIT_VEC cppVar_30009 = ROM.rd(PC);
	bool cppVar_30011 = (cppVar_30009 == 135);
	if (cppVar_30011) {
	BIT_VEC cppVar_30012;
	BIT_VEC cppVar_30014 = PC + 1;
	cppVar_30014 = (cppVar_30014 & cppMask_un_16_);
	BIT_VEC cppVar_30015 = ROM.rd(cppVar_30014);
	bool cppVar_30017 = (cppVar_30015 == 144);
	if (cppVar_30017) {
	BIT_VEC cppVar_30019 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_30021 = (cppVar_30019 << 3) | 1;
	cppVar_30021 = (cppVar_30021 & cppMask_un_5_);
	BIT_VEC cppVar_30022 = (0 << 5) | cppVar_30021;
	cppVar_30022 = (cppVar_30022 & cppMask_un_8_);
	BIT_VEC cppVar_30023 = IRAM.rd(cppVar_30022);
	BIT_VEC cppVar_30024 = IRAM.rd(cppVar_30023);
	cppVar_30012 = cppVar_30024;
	} else {
	cppVar_30012 = P1;
	}
	cppVar_30008 = cppVar_30012;
	} else {
	BIT_VEC cppVar_30025;
	BIT_VEC cppVar_30026 = ROM.rd(PC);
	bool cppVar_30028 = (cppVar_30026 == 134);
	if (cppVar_30028) {
	BIT_VEC cppVar_30029;
	BIT_VEC cppVar_30031 = PC + 1;
	cppVar_30031 = (cppVar_30031 & cppMask_un_16_);
	BIT_VEC cppVar_30032 = ROM.rd(cppVar_30031);
	bool cppVar_30034 = (cppVar_30032 == 144);
	if (cppVar_30034) {
	BIT_VEC cppVar_30036 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_30038 = (cppVar_30036 << 3) | 0;
	cppVar_30038 = (cppVar_30038 & cppMask_un_5_);
	BIT_VEC cppVar_30039 = (0 << 5) | cppVar_30038;
	cppVar_30039 = (cppVar_30039 & cppMask_un_8_);
	BIT_VEC cppVar_30040 = IRAM.rd(cppVar_30039);
	BIT_VEC cppVar_30041 = IRAM.rd(cppVar_30040);
	cppVar_30029 = cppVar_30041;
	} else {
	cppVar_30029 = P1;
	}
	cppVar_30025 = cppVar_30029;
	} else {
	BIT_VEC cppVar_30042;
	BIT_VEC cppVar_30043 = ROM.rd(PC);
	bool cppVar_30045 = (cppVar_30043 == 133);
	if (cppVar_30045) {
	BIT_VEC cppVar_30046;
	BIT_VEC cppVar_30048 = PC + 2;
	cppVar_30048 = (cppVar_30048 & cppMask_un_16_);
	BIT_VEC cppVar_30049 = ROM.rd(cppVar_30048);
	bool cppVar_30051 = (cppVar_30049 == 144);
	if (cppVar_30051) {
	BIT_VEC cppVar_30052;
	BIT_VEC cppVar_30054 = PC + 1;
	cppVar_30054 = (cppVar_30054 & cppMask_un_16_);
	BIT_VEC cppVar_30055 = ROM.rd(cppVar_30054);
	BIT_VEC cppVar_30056 = (cppVar_30055 >> 7) & cppMask_un_1_;
	bool cppVar_30058 = (cppVar_30056 == 0);
	if (cppVar_30058) {
	BIT_VEC cppVar_30059 = PC + 1;
	cppVar_30059 = (cppVar_30059 & cppMask_un_16_);
	BIT_VEC cppVar_30060 = ROM.rd(cppVar_30059);
	BIT_VEC cppVar_30061 = IRAM.rd(cppVar_30060);
	cppVar_30052 = cppVar_30061;
	} else {
	BIT_VEC cppVar_30062;
	BIT_VEC cppVar_30063 = PC + 1;
	cppVar_30063 = (cppVar_30063 & cppMask_un_16_);
	BIT_VEC cppVar_30064 = ROM.rd(cppVar_30063);
	bool cppVar_30066 = (cppVar_30064 == 128);
	if (cppVar_30066) {
	cppVar_30062 = P0;
	} else {
	BIT_VEC cppVar_30067;
	BIT_VEC cppVar_30068 = PC + 1;
	cppVar_30068 = (cppVar_30068 & cppMask_un_16_);
	BIT_VEC cppVar_30069 = ROM.rd(cppVar_30068);
	bool cppVar_30071 = (cppVar_30069 == 129);
	if (cppVar_30071) {
	cppVar_30067 = SP;
	} else {
	BIT_VEC cppVar_30072;
	BIT_VEC cppVar_30073 = PC + 1;
	cppVar_30073 = (cppVar_30073 & cppMask_un_16_);
	BIT_VEC cppVar_30074 = ROM.rd(cppVar_30073);
	bool cppVar_30076 = (cppVar_30074 == 130);
	if (cppVar_30076) {
	cppVar_30072 = DPL;
	} else {
	BIT_VEC cppVar_30077;
	BIT_VEC cppVar_30078 = PC + 1;
	cppVar_30078 = (cppVar_30078 & cppMask_un_16_);
	BIT_VEC cppVar_30079 = ROM.rd(cppVar_30078);
	bool cppVar_30081 = (cppVar_30079 == 131);
	if (cppVar_30081) {
	cppVar_30077 = DPH;
	} else {
	BIT_VEC cppVar_30082;
	BIT_VEC cppVar_30083 = PC + 1;
	cppVar_30083 = (cppVar_30083 & cppMask_un_16_);
	BIT_VEC cppVar_30084 = ROM.rd(cppVar_30083);
	bool cppVar_30086 = (cppVar_30084 == 135);
	if (cppVar_30086) {
	cppVar_30082 = PCON;
	} else {
	BIT_VEC cppVar_30087;
	BIT_VEC cppVar_30088 = PC + 1;
	cppVar_30088 = (cppVar_30088 & cppMask_un_16_);
	BIT_VEC cppVar_30089 = ROM.rd(cppVar_30088);
	bool cppVar_30091 = (cppVar_30089 == 136);
	if (cppVar_30091) {
	cppVar_30087 = TCON;
	} else {
	BIT_VEC cppVar_30092;
	BIT_VEC cppVar_30093 = PC + 1;
	cppVar_30093 = (cppVar_30093 & cppMask_un_16_);
	BIT_VEC cppVar_30094 = ROM.rd(cppVar_30093);
	bool cppVar_30096 = (cppVar_30094 == 137);
	if (cppVar_30096) {
	cppVar_30092 = TMOD;
	} else {
	BIT_VEC cppVar_30097;
	BIT_VEC cppVar_30098 = PC + 1;
	cppVar_30098 = (cppVar_30098 & cppMask_un_16_);
	BIT_VEC cppVar_30099 = ROM.rd(cppVar_30098);
	bool cppVar_30101 = (cppVar_30099 == 138);
	if (cppVar_30101) {
	cppVar_30097 = TL0;
	} else {
	BIT_VEC cppVar_30102;
	BIT_VEC cppVar_30103 = PC + 1;
	cppVar_30103 = (cppVar_30103 & cppMask_un_16_);
	BIT_VEC cppVar_30104 = ROM.rd(cppVar_30103);
	bool cppVar_30106 = (cppVar_30104 == 140);
	if (cppVar_30106) {
	cppVar_30102 = TH0;
	} else {
	BIT_VEC cppVar_30107;
	BIT_VEC cppVar_30108 = PC + 1;
	cppVar_30108 = (cppVar_30108 & cppMask_un_16_);
	BIT_VEC cppVar_30109 = ROM.rd(cppVar_30108);
	bool cppVar_30111 = (cppVar_30109 == 139);
	if (cppVar_30111) {
	cppVar_30107 = TL1;
	} else {
	BIT_VEC cppVar_30112;
	BIT_VEC cppVar_30113 = PC + 1;
	cppVar_30113 = (cppVar_30113 & cppMask_un_16_);
	BIT_VEC cppVar_30114 = ROM.rd(cppVar_30113);
	bool cppVar_30116 = (cppVar_30114 == 141);
	if (cppVar_30116) {
	cppVar_30112 = TH1;
	} else {
	BIT_VEC cppVar_30117;
	BIT_VEC cppVar_30118 = PC + 1;
	cppVar_30118 = (cppVar_30118 & cppMask_un_16_);
	BIT_VEC cppVar_30119 = ROM.rd(cppVar_30118);
	bool cppVar_30121 = (cppVar_30119 == 144);
	if (cppVar_30121) {
	cppVar_30117 = P1;
	} else {
	BIT_VEC cppVar_30122;
	BIT_VEC cppVar_30123 = PC + 1;
	cppVar_30123 = (cppVar_30123 & cppMask_un_16_);
	BIT_VEC cppVar_30124 = ROM.rd(cppVar_30123);
	bool cppVar_30126 = (cppVar_30124 == 152);
	if (cppVar_30126) {
	cppVar_30122 = SCON;
	} else {
	BIT_VEC cppVar_30127;
	BIT_VEC cppVar_30128 = PC + 1;
	cppVar_30128 = (cppVar_30128 & cppMask_un_16_);
	BIT_VEC cppVar_30129 = ROM.rd(cppVar_30128);
	bool cppVar_30131 = (cppVar_30129 == 153);
	if (cppVar_30131) {
	cppVar_30127 = SBUF;
	} else {
	BIT_VEC cppVar_30132;
	BIT_VEC cppVar_30133 = PC + 1;
	cppVar_30133 = (cppVar_30133 & cppMask_un_16_);
	BIT_VEC cppVar_30134 = ROM.rd(cppVar_30133);
	bool cppVar_30136 = (cppVar_30134 == 160);
	if (cppVar_30136) {
	cppVar_30132 = P2;
	} else {
	BIT_VEC cppVar_30137;
	BIT_VEC cppVar_30138 = PC + 1;
	cppVar_30138 = (cppVar_30138 & cppMask_un_16_);
	BIT_VEC cppVar_30139 = ROM.rd(cppVar_30138);
	bool cppVar_30141 = (cppVar_30139 == 168);
	if (cppVar_30141) {
	cppVar_30137 = IE;
	} else {
	BIT_VEC cppVar_30142;
	BIT_VEC cppVar_30143 = PC + 1;
	cppVar_30143 = (cppVar_30143 & cppMask_un_16_);
	BIT_VEC cppVar_30144 = ROM.rd(cppVar_30143);
	bool cppVar_30146 = (cppVar_30144 == 176);
	if (cppVar_30146) {
	cppVar_30142 = P3;
	} else {
	BIT_VEC cppVar_30147;
	BIT_VEC cppVar_30148 = PC + 1;
	cppVar_30148 = (cppVar_30148 & cppMask_un_16_);
	BIT_VEC cppVar_30149 = ROM.rd(cppVar_30148);
	bool cppVar_30151 = (cppVar_30149 == 184);
	if (cppVar_30151) {
	cppVar_30147 = IP;
	} else {
	BIT_VEC cppVar_30152;
	BIT_VEC cppVar_30153 = PC + 1;
	cppVar_30153 = (cppVar_30153 & cppMask_un_16_);
	BIT_VEC cppVar_30154 = ROM.rd(cppVar_30153);
	bool cppVar_30156 = (cppVar_30154 == 208);
	if (cppVar_30156) {
	cppVar_30152 = PSW;
	} else {
	BIT_VEC cppVar_30157;
	BIT_VEC cppVar_30158 = PC + 1;
	cppVar_30158 = (cppVar_30158 & cppMask_un_16_);
	BIT_VEC cppVar_30159 = ROM.rd(cppVar_30158);
	bool cppVar_30161 = (cppVar_30159 == 224);
	if (cppVar_30161) {
	cppVar_30157 = ACC;
	} else {
	BIT_VEC cppVar_30162;
	BIT_VEC cppVar_30163 = PC + 1;
	cppVar_30163 = (cppVar_30163 & cppMask_un_16_);
	BIT_VEC cppVar_30164 = ROM.rd(cppVar_30163);
	bool cppVar_30166 = (cppVar_30164 == 240);
	if (cppVar_30166) {
	cppVar_30162 = B;
	} else {
	cppVar_30162 = 0;
	}
	cppVar_30157 = cppVar_30162;
	}
	cppVar_30152 = cppVar_30157;
	}
	cppVar_30147 = cppVar_30152;
	}
	cppVar_30142 = cppVar_30147;
	}
	cppVar_30137 = cppVar_30142;
	}
	cppVar_30132 = cppVar_30137;
	}
	cppVar_30127 = cppVar_30132;
	}
	cppVar_30122 = cppVar_30127;
	}
	cppVar_30117 = cppVar_30122;
	}
	cppVar_30112 = cppVar_30117;
	}
	cppVar_30107 = cppVar_30112;
	}
	cppVar_30102 = cppVar_30107;
	}
	cppVar_30097 = cppVar_30102;
	}
	cppVar_30092 = cppVar_30097;
	}
	cppVar_30087 = cppVar_30092;
	}
	cppVar_30082 = cppVar_30087;
	}
	cppVar_30077 = cppVar_30082;
	}
	cppVar_30072 = cppVar_30077;
	}
	cppVar_30067 = cppVar_30072;
	}
	cppVar_30062 = cppVar_30067;
	}
	cppVar_30052 = cppVar_30062;
	}
	cppVar_30046 = cppVar_30052;
	} else {
	cppVar_30046 = P1;
	}
	cppVar_30042 = cppVar_30046;
	} else {
	BIT_VEC cppVar_30168;
	BIT_VEC cppVar_30169 = ROM.rd(PC);
	bool cppVar_30171 = (cppVar_30169 == 117);
	if (cppVar_30171) {
	BIT_VEC cppVar_30172;
	BIT_VEC cppVar_30174 = PC + 1;
	cppVar_30174 = (cppVar_30174 & cppMask_un_16_);
	BIT_VEC cppVar_30175 = ROM.rd(cppVar_30174);
	bool cppVar_30177 = (cppVar_30175 == 144);
	if (cppVar_30177) {
	BIT_VEC cppVar_30179 = PC + 2;
	cppVar_30179 = (cppVar_30179 & cppMask_un_16_);
	BIT_VEC cppVar_30180 = ROM.rd(cppVar_30179);
	cppVar_30172 = cppVar_30180;
	} else {
	cppVar_30172 = P1;
	}
	cppVar_30168 = cppVar_30172;
	} else {
	BIT_VEC cppVar_30181;
	BIT_VEC cppVar_30182 = ROM.rd(PC);
	bool cppVar_30184 = (cppVar_30182 == 99);
	if (cppVar_30184) {
	BIT_VEC cppVar_30185;
	BIT_VEC cppVar_30187 = PC + 1;
	cppVar_30187 = (cppVar_30187 & cppMask_un_16_);
	BIT_VEC cppVar_30188 = ROM.rd(cppVar_30187);
	bool cppVar_30190 = (cppVar_30188 == 144);
	if (cppVar_30190) {
	BIT_VEC cppVar_30191;
	BIT_VEC cppVar_30192 = PC + 1;
	cppVar_30192 = (cppVar_30192 & cppMask_un_16_);
	BIT_VEC cppVar_30193 = ROM.rd(cppVar_30192);
	BIT_VEC cppVar_30194 = (cppVar_30193 >> 7) & cppMask_un_1_;
	bool cppVar_30196 = (cppVar_30194 == 0);
	if (cppVar_30196) {
	BIT_VEC cppVar_30197 = PC + 1;
	cppVar_30197 = (cppVar_30197 & cppMask_un_16_);
	BIT_VEC cppVar_30198 = ROM.rd(cppVar_30197);
	BIT_VEC cppVar_30199 = IRAM.rd(cppVar_30198);
	cppVar_30191 = cppVar_30199;
	} else {
	BIT_VEC cppVar_30200;
	BIT_VEC cppVar_30201 = PC + 1;
	cppVar_30201 = (cppVar_30201 & cppMask_un_16_);
	BIT_VEC cppVar_30202 = ROM.rd(cppVar_30201);
	bool cppVar_30204 = (cppVar_30202 == 128);
	if (cppVar_30204) {
	cppVar_30200 = P0;
	} else {
	BIT_VEC cppVar_30205;
	BIT_VEC cppVar_30206 = PC + 1;
	cppVar_30206 = (cppVar_30206 & cppMask_un_16_);
	BIT_VEC cppVar_30207 = ROM.rd(cppVar_30206);
	bool cppVar_30209 = (cppVar_30207 == 129);
	if (cppVar_30209) {
	cppVar_30205 = SP;
	} else {
	BIT_VEC cppVar_30210;
	BIT_VEC cppVar_30211 = PC + 1;
	cppVar_30211 = (cppVar_30211 & cppMask_un_16_);
	BIT_VEC cppVar_30212 = ROM.rd(cppVar_30211);
	bool cppVar_30214 = (cppVar_30212 == 130);
	if (cppVar_30214) {
	cppVar_30210 = DPL;
	} else {
	BIT_VEC cppVar_30215;
	BIT_VEC cppVar_30216 = PC + 1;
	cppVar_30216 = (cppVar_30216 & cppMask_un_16_);
	BIT_VEC cppVar_30217 = ROM.rd(cppVar_30216);
	bool cppVar_30219 = (cppVar_30217 == 131);
	if (cppVar_30219) {
	cppVar_30215 = DPH;
	} else {
	BIT_VEC cppVar_30220;
	BIT_VEC cppVar_30221 = PC + 1;
	cppVar_30221 = (cppVar_30221 & cppMask_un_16_);
	BIT_VEC cppVar_30222 = ROM.rd(cppVar_30221);
	bool cppVar_30224 = (cppVar_30222 == 135);
	if (cppVar_30224) {
	cppVar_30220 = PCON;
	} else {
	BIT_VEC cppVar_30225;
	BIT_VEC cppVar_30226 = PC + 1;
	cppVar_30226 = (cppVar_30226 & cppMask_un_16_);
	BIT_VEC cppVar_30227 = ROM.rd(cppVar_30226);
	bool cppVar_30229 = (cppVar_30227 == 136);
	if (cppVar_30229) {
	cppVar_30225 = TCON;
	} else {
	BIT_VEC cppVar_30230;
	BIT_VEC cppVar_30231 = PC + 1;
	cppVar_30231 = (cppVar_30231 & cppMask_un_16_);
	BIT_VEC cppVar_30232 = ROM.rd(cppVar_30231);
	bool cppVar_30234 = (cppVar_30232 == 137);
	if (cppVar_30234) {
	cppVar_30230 = TMOD;
	} else {
	BIT_VEC cppVar_30235;
	BIT_VEC cppVar_30236 = PC + 1;
	cppVar_30236 = (cppVar_30236 & cppMask_un_16_);
	BIT_VEC cppVar_30237 = ROM.rd(cppVar_30236);
	bool cppVar_30239 = (cppVar_30237 == 138);
	if (cppVar_30239) {
	cppVar_30235 = TL0;
	} else {
	BIT_VEC cppVar_30240;
	BIT_VEC cppVar_30241 = PC + 1;
	cppVar_30241 = (cppVar_30241 & cppMask_un_16_);
	BIT_VEC cppVar_30242 = ROM.rd(cppVar_30241);
	bool cppVar_30244 = (cppVar_30242 == 140);
	if (cppVar_30244) {
	cppVar_30240 = TH0;
	} else {
	BIT_VEC cppVar_30245;
	BIT_VEC cppVar_30246 = PC + 1;
	cppVar_30246 = (cppVar_30246 & cppMask_un_16_);
	BIT_VEC cppVar_30247 = ROM.rd(cppVar_30246);
	bool cppVar_30249 = (cppVar_30247 == 139);
	if (cppVar_30249) {
	cppVar_30245 = TL1;
	} else {
	BIT_VEC cppVar_30250;
	BIT_VEC cppVar_30251 = PC + 1;
	cppVar_30251 = (cppVar_30251 & cppMask_un_16_);
	BIT_VEC cppVar_30252 = ROM.rd(cppVar_30251);
	bool cppVar_30254 = (cppVar_30252 == 141);
	if (cppVar_30254) {
	cppVar_30250 = TH1;
	} else {
	BIT_VEC cppVar_30255;
	BIT_VEC cppVar_30256 = PC + 1;
	cppVar_30256 = (cppVar_30256 & cppMask_un_16_);
	BIT_VEC cppVar_30257 = ROM.rd(cppVar_30256);
	bool cppVar_30259 = (cppVar_30257 == 144);
	if (cppVar_30259) {
	cppVar_30255 = P1;
	} else {
	BIT_VEC cppVar_30260;
	BIT_VEC cppVar_30261 = PC + 1;
	cppVar_30261 = (cppVar_30261 & cppMask_un_16_);
	BIT_VEC cppVar_30262 = ROM.rd(cppVar_30261);
	bool cppVar_30264 = (cppVar_30262 == 152);
	if (cppVar_30264) {
	cppVar_30260 = SCON;
	} else {
	BIT_VEC cppVar_30265;
	BIT_VEC cppVar_30266 = PC + 1;
	cppVar_30266 = (cppVar_30266 & cppMask_un_16_);
	BIT_VEC cppVar_30267 = ROM.rd(cppVar_30266);
	bool cppVar_30269 = (cppVar_30267 == 153);
	if (cppVar_30269) {
	cppVar_30265 = SBUF;
	} else {
	BIT_VEC cppVar_30270;
	BIT_VEC cppVar_30271 = PC + 1;
	cppVar_30271 = (cppVar_30271 & cppMask_un_16_);
	BIT_VEC cppVar_30272 = ROM.rd(cppVar_30271);
	bool cppVar_30274 = (cppVar_30272 == 160);
	if (cppVar_30274) {
	cppVar_30270 = P2;
	} else {
	BIT_VEC cppVar_30275;
	BIT_VEC cppVar_30276 = PC + 1;
	cppVar_30276 = (cppVar_30276 & cppMask_un_16_);
	BIT_VEC cppVar_30277 = ROM.rd(cppVar_30276);
	bool cppVar_30279 = (cppVar_30277 == 168);
	if (cppVar_30279) {
	cppVar_30275 = IE;
	} else {
	BIT_VEC cppVar_30280;
	BIT_VEC cppVar_30281 = PC + 1;
	cppVar_30281 = (cppVar_30281 & cppMask_un_16_);
	BIT_VEC cppVar_30282 = ROM.rd(cppVar_30281);
	bool cppVar_30284 = (cppVar_30282 == 176);
	if (cppVar_30284) {
	cppVar_30280 = P3;
	} else {
	BIT_VEC cppVar_30285;
	BIT_VEC cppVar_30286 = PC + 1;
	cppVar_30286 = (cppVar_30286 & cppMask_un_16_);
	BIT_VEC cppVar_30287 = ROM.rd(cppVar_30286);
	bool cppVar_30289 = (cppVar_30287 == 184);
	if (cppVar_30289) {
	cppVar_30285 = IP;
	} else {
	BIT_VEC cppVar_30290;
	BIT_VEC cppVar_30291 = PC + 1;
	cppVar_30291 = (cppVar_30291 & cppMask_un_16_);
	BIT_VEC cppVar_30292 = ROM.rd(cppVar_30291);
	bool cppVar_30294 = (cppVar_30292 == 208);
	if (cppVar_30294) {
	cppVar_30290 = PSW;
	} else {
	BIT_VEC cppVar_30295;
	BIT_VEC cppVar_30296 = PC + 1;
	cppVar_30296 = (cppVar_30296 & cppMask_un_16_);
	BIT_VEC cppVar_30297 = ROM.rd(cppVar_30296);
	bool cppVar_30299 = (cppVar_30297 == 224);
	if (cppVar_30299) {
	cppVar_30295 = ACC;
	} else {
	BIT_VEC cppVar_30300;
	BIT_VEC cppVar_30301 = PC + 1;
	cppVar_30301 = (cppVar_30301 & cppMask_un_16_);
	BIT_VEC cppVar_30302 = ROM.rd(cppVar_30301);
	bool cppVar_30304 = (cppVar_30302 == 240);
	if (cppVar_30304) {
	cppVar_30300 = B;
	} else {
	cppVar_30300 = 0;
	}
	cppVar_30295 = cppVar_30300;
	}
	cppVar_30290 = cppVar_30295;
	}
	cppVar_30285 = cppVar_30290;
	}
	cppVar_30280 = cppVar_30285;
	}
	cppVar_30275 = cppVar_30280;
	}
	cppVar_30270 = cppVar_30275;
	}
	cppVar_30265 = cppVar_30270;
	}
	cppVar_30260 = cppVar_30265;
	}
	cppVar_30255 = cppVar_30260;
	}
	cppVar_30250 = cppVar_30255;
	}
	cppVar_30245 = cppVar_30250;
	}
	cppVar_30240 = cppVar_30245;
	}
	cppVar_30235 = cppVar_30240;
	}
	cppVar_30230 = cppVar_30235;
	}
	cppVar_30225 = cppVar_30230;
	}
	cppVar_30220 = cppVar_30225;
	}
	cppVar_30215 = cppVar_30220;
	}
	cppVar_30210 = cppVar_30215;
	}
	cppVar_30205 = cppVar_30210;
	}
	cppVar_30200 = cppVar_30205;
	}
	cppVar_30191 = cppVar_30200;
	}
	BIT_VEC cppVar_30307 = PC + 2;
	cppVar_30307 = (cppVar_30307 & cppMask_un_16_);
	BIT_VEC cppVar_30308 = ROM.rd(cppVar_30307);
	BIT_VEC cppVar_30309 = cppVar_30191 ^ cppVar_30308;
	cppVar_30185 = cppVar_30309;
	} else {
	cppVar_30185 = P1;
	}
	cppVar_30181 = cppVar_30185;
	} else {
	BIT_VEC cppVar_30310;
	BIT_VEC cppVar_30311 = ROM.rd(PC);
	bool cppVar_30313 = (cppVar_30311 == 98);
	if (cppVar_30313) {
	BIT_VEC cppVar_30314;
	BIT_VEC cppVar_30316 = PC + 1;
	cppVar_30316 = (cppVar_30316 & cppMask_un_16_);
	BIT_VEC cppVar_30317 = ROM.rd(cppVar_30316);
	bool cppVar_30319 = (cppVar_30317 == 144);
	if (cppVar_30319) {
	BIT_VEC cppVar_30320;
	BIT_VEC cppVar_30321 = PC + 1;
	cppVar_30321 = (cppVar_30321 & cppMask_un_16_);
	BIT_VEC cppVar_30322 = ROM.rd(cppVar_30321);
	BIT_VEC cppVar_30323 = (cppVar_30322 >> 7) & cppMask_un_1_;
	bool cppVar_30325 = (cppVar_30323 == 0);
	if (cppVar_30325) {
	BIT_VEC cppVar_30326 = PC + 1;
	cppVar_30326 = (cppVar_30326 & cppMask_un_16_);
	BIT_VEC cppVar_30327 = ROM.rd(cppVar_30326);
	BIT_VEC cppVar_30328 = IRAM.rd(cppVar_30327);
	cppVar_30320 = cppVar_30328;
	} else {
	BIT_VEC cppVar_30329;
	BIT_VEC cppVar_30330 = PC + 1;
	cppVar_30330 = (cppVar_30330 & cppMask_un_16_);
	BIT_VEC cppVar_30331 = ROM.rd(cppVar_30330);
	bool cppVar_30333 = (cppVar_30331 == 128);
	if (cppVar_30333) {
	cppVar_30329 = P0;
	} else {
	BIT_VEC cppVar_30334;
	BIT_VEC cppVar_30335 = PC + 1;
	cppVar_30335 = (cppVar_30335 & cppMask_un_16_);
	BIT_VEC cppVar_30336 = ROM.rd(cppVar_30335);
	bool cppVar_30338 = (cppVar_30336 == 129);
	if (cppVar_30338) {
	cppVar_30334 = SP;
	} else {
	BIT_VEC cppVar_30339;
	BIT_VEC cppVar_30340 = PC + 1;
	cppVar_30340 = (cppVar_30340 & cppMask_un_16_);
	BIT_VEC cppVar_30341 = ROM.rd(cppVar_30340);
	bool cppVar_30343 = (cppVar_30341 == 130);
	if (cppVar_30343) {
	cppVar_30339 = DPL;
	} else {
	BIT_VEC cppVar_30344;
	BIT_VEC cppVar_30345 = PC + 1;
	cppVar_30345 = (cppVar_30345 & cppMask_un_16_);
	BIT_VEC cppVar_30346 = ROM.rd(cppVar_30345);
	bool cppVar_30348 = (cppVar_30346 == 131);
	if (cppVar_30348) {
	cppVar_30344 = DPH;
	} else {
	BIT_VEC cppVar_30349;
	BIT_VEC cppVar_30350 = PC + 1;
	cppVar_30350 = (cppVar_30350 & cppMask_un_16_);
	BIT_VEC cppVar_30351 = ROM.rd(cppVar_30350);
	bool cppVar_30353 = (cppVar_30351 == 135);
	if (cppVar_30353) {
	cppVar_30349 = PCON;
	} else {
	BIT_VEC cppVar_30354;
	BIT_VEC cppVar_30355 = PC + 1;
	cppVar_30355 = (cppVar_30355 & cppMask_un_16_);
	BIT_VEC cppVar_30356 = ROM.rd(cppVar_30355);
	bool cppVar_30358 = (cppVar_30356 == 136);
	if (cppVar_30358) {
	cppVar_30354 = TCON;
	} else {
	BIT_VEC cppVar_30359;
	BIT_VEC cppVar_30360 = PC + 1;
	cppVar_30360 = (cppVar_30360 & cppMask_un_16_);
	BIT_VEC cppVar_30361 = ROM.rd(cppVar_30360);
	bool cppVar_30363 = (cppVar_30361 == 137);
	if (cppVar_30363) {
	cppVar_30359 = TMOD;
	} else {
	BIT_VEC cppVar_30364;
	BIT_VEC cppVar_30365 = PC + 1;
	cppVar_30365 = (cppVar_30365 & cppMask_un_16_);
	BIT_VEC cppVar_30366 = ROM.rd(cppVar_30365);
	bool cppVar_30368 = (cppVar_30366 == 138);
	if (cppVar_30368) {
	cppVar_30364 = TL0;
	} else {
	BIT_VEC cppVar_30369;
	BIT_VEC cppVar_30370 = PC + 1;
	cppVar_30370 = (cppVar_30370 & cppMask_un_16_);
	BIT_VEC cppVar_30371 = ROM.rd(cppVar_30370);
	bool cppVar_30373 = (cppVar_30371 == 140);
	if (cppVar_30373) {
	cppVar_30369 = TH0;
	} else {
	BIT_VEC cppVar_30374;
	BIT_VEC cppVar_30375 = PC + 1;
	cppVar_30375 = (cppVar_30375 & cppMask_un_16_);
	BIT_VEC cppVar_30376 = ROM.rd(cppVar_30375);
	bool cppVar_30378 = (cppVar_30376 == 139);
	if (cppVar_30378) {
	cppVar_30374 = TL1;
	} else {
	BIT_VEC cppVar_30379;
	BIT_VEC cppVar_30380 = PC + 1;
	cppVar_30380 = (cppVar_30380 & cppMask_un_16_);
	BIT_VEC cppVar_30381 = ROM.rd(cppVar_30380);
	bool cppVar_30383 = (cppVar_30381 == 141);
	if (cppVar_30383) {
	cppVar_30379 = TH1;
	} else {
	BIT_VEC cppVar_30384;
	BIT_VEC cppVar_30385 = PC + 1;
	cppVar_30385 = (cppVar_30385 & cppMask_un_16_);
	BIT_VEC cppVar_30386 = ROM.rd(cppVar_30385);
	bool cppVar_30388 = (cppVar_30386 == 144);
	if (cppVar_30388) {
	cppVar_30384 = P1;
	} else {
	BIT_VEC cppVar_30389;
	BIT_VEC cppVar_30390 = PC + 1;
	cppVar_30390 = (cppVar_30390 & cppMask_un_16_);
	BIT_VEC cppVar_30391 = ROM.rd(cppVar_30390);
	bool cppVar_30393 = (cppVar_30391 == 152);
	if (cppVar_30393) {
	cppVar_30389 = SCON;
	} else {
	BIT_VEC cppVar_30394;
	BIT_VEC cppVar_30395 = PC + 1;
	cppVar_30395 = (cppVar_30395 & cppMask_un_16_);
	BIT_VEC cppVar_30396 = ROM.rd(cppVar_30395);
	bool cppVar_30398 = (cppVar_30396 == 153);
	if (cppVar_30398) {
	cppVar_30394 = SBUF;
	} else {
	BIT_VEC cppVar_30399;
	BIT_VEC cppVar_30400 = PC + 1;
	cppVar_30400 = (cppVar_30400 & cppMask_un_16_);
	BIT_VEC cppVar_30401 = ROM.rd(cppVar_30400);
	bool cppVar_30403 = (cppVar_30401 == 160);
	if (cppVar_30403) {
	cppVar_30399 = P2;
	} else {
	BIT_VEC cppVar_30404;
	BIT_VEC cppVar_30405 = PC + 1;
	cppVar_30405 = (cppVar_30405 & cppMask_un_16_);
	BIT_VEC cppVar_30406 = ROM.rd(cppVar_30405);
	bool cppVar_30408 = (cppVar_30406 == 168);
	if (cppVar_30408) {
	cppVar_30404 = IE;
	} else {
	BIT_VEC cppVar_30409;
	BIT_VEC cppVar_30410 = PC + 1;
	cppVar_30410 = (cppVar_30410 & cppMask_un_16_);
	BIT_VEC cppVar_30411 = ROM.rd(cppVar_30410);
	bool cppVar_30413 = (cppVar_30411 == 176);
	if (cppVar_30413) {
	cppVar_30409 = P3;
	} else {
	BIT_VEC cppVar_30414;
	BIT_VEC cppVar_30415 = PC + 1;
	cppVar_30415 = (cppVar_30415 & cppMask_un_16_);
	BIT_VEC cppVar_30416 = ROM.rd(cppVar_30415);
	bool cppVar_30418 = (cppVar_30416 == 184);
	if (cppVar_30418) {
	cppVar_30414 = IP;
	} else {
	BIT_VEC cppVar_30419;
	BIT_VEC cppVar_30420 = PC + 1;
	cppVar_30420 = (cppVar_30420 & cppMask_un_16_);
	BIT_VEC cppVar_30421 = ROM.rd(cppVar_30420);
	bool cppVar_30423 = (cppVar_30421 == 208);
	if (cppVar_30423) {
	cppVar_30419 = PSW;
	} else {
	BIT_VEC cppVar_30424;
	BIT_VEC cppVar_30425 = PC + 1;
	cppVar_30425 = (cppVar_30425 & cppMask_un_16_);
	BIT_VEC cppVar_30426 = ROM.rd(cppVar_30425);
	bool cppVar_30428 = (cppVar_30426 == 224);
	if (cppVar_30428) {
	cppVar_30424 = ACC;
	} else {
	BIT_VEC cppVar_30429;
	BIT_VEC cppVar_30430 = PC + 1;
	cppVar_30430 = (cppVar_30430 & cppMask_un_16_);
	BIT_VEC cppVar_30431 = ROM.rd(cppVar_30430);
	bool cppVar_30433 = (cppVar_30431 == 240);
	if (cppVar_30433) {
	cppVar_30429 = B;
	} else {
	cppVar_30429 = 0;
	}
	cppVar_30424 = cppVar_30429;
	}
	cppVar_30419 = cppVar_30424;
	}
	cppVar_30414 = cppVar_30419;
	}
	cppVar_30409 = cppVar_30414;
	}
	cppVar_30404 = cppVar_30409;
	}
	cppVar_30399 = cppVar_30404;
	}
	cppVar_30394 = cppVar_30399;
	}
	cppVar_30389 = cppVar_30394;
	}
	cppVar_30384 = cppVar_30389;
	}
	cppVar_30379 = cppVar_30384;
	}
	cppVar_30374 = cppVar_30379;
	}
	cppVar_30369 = cppVar_30374;
	}
	cppVar_30364 = cppVar_30369;
	}
	cppVar_30359 = cppVar_30364;
	}
	cppVar_30354 = cppVar_30359;
	}
	cppVar_30349 = cppVar_30354;
	}
	cppVar_30344 = cppVar_30349;
	}
	cppVar_30339 = cppVar_30344;
	}
	cppVar_30334 = cppVar_30339;
	}
	cppVar_30329 = cppVar_30334;
	}
	cppVar_30320 = cppVar_30329;
	}
	BIT_VEC cppVar_30435 = cppVar_30320 ^ ACC;
	cppVar_30314 = cppVar_30435;
	} else {
	cppVar_30314 = P1;
	}
	cppVar_30310 = cppVar_30314;
	} else {
	BIT_VEC cppVar_30436;
	BIT_VEC cppVar_30437 = ROM.rd(PC);
	bool cppVar_30439 = (cppVar_30437 == 83);
	if (cppVar_30439) {
	BIT_VEC cppVar_30440;
	BIT_VEC cppVar_30442 = PC + 1;
	cppVar_30442 = (cppVar_30442 & cppMask_un_16_);
	BIT_VEC cppVar_30443 = ROM.rd(cppVar_30442);
	bool cppVar_30445 = (cppVar_30443 == 144);
	if (cppVar_30445) {
	BIT_VEC cppVar_30446;
	BIT_VEC cppVar_30447 = PC + 1;
	cppVar_30447 = (cppVar_30447 & cppMask_un_16_);
	BIT_VEC cppVar_30448 = ROM.rd(cppVar_30447);
	BIT_VEC cppVar_30449 = (cppVar_30448 >> 7) & cppMask_un_1_;
	bool cppVar_30451 = (cppVar_30449 == 0);
	if (cppVar_30451) {
	BIT_VEC cppVar_30452 = PC + 1;
	cppVar_30452 = (cppVar_30452 & cppMask_un_16_);
	BIT_VEC cppVar_30453 = ROM.rd(cppVar_30452);
	BIT_VEC cppVar_30454 = IRAM.rd(cppVar_30453);
	cppVar_30446 = cppVar_30454;
	} else {
	BIT_VEC cppVar_30455;
	BIT_VEC cppVar_30456 = PC + 1;
	cppVar_30456 = (cppVar_30456 & cppMask_un_16_);
	BIT_VEC cppVar_30457 = ROM.rd(cppVar_30456);
	bool cppVar_30459 = (cppVar_30457 == 128);
	if (cppVar_30459) {
	cppVar_30455 = P0;
	} else {
	BIT_VEC cppVar_30460;
	BIT_VEC cppVar_30461 = PC + 1;
	cppVar_30461 = (cppVar_30461 & cppMask_un_16_);
	BIT_VEC cppVar_30462 = ROM.rd(cppVar_30461);
	bool cppVar_30464 = (cppVar_30462 == 129);
	if (cppVar_30464) {
	cppVar_30460 = SP;
	} else {
	BIT_VEC cppVar_30465;
	BIT_VEC cppVar_30466 = PC + 1;
	cppVar_30466 = (cppVar_30466 & cppMask_un_16_);
	BIT_VEC cppVar_30467 = ROM.rd(cppVar_30466);
	bool cppVar_30469 = (cppVar_30467 == 130);
	if (cppVar_30469) {
	cppVar_30465 = DPL;
	} else {
	BIT_VEC cppVar_30470;
	BIT_VEC cppVar_30471 = PC + 1;
	cppVar_30471 = (cppVar_30471 & cppMask_un_16_);
	BIT_VEC cppVar_30472 = ROM.rd(cppVar_30471);
	bool cppVar_30474 = (cppVar_30472 == 131);
	if (cppVar_30474) {
	cppVar_30470 = DPH;
	} else {
	BIT_VEC cppVar_30475;
	BIT_VEC cppVar_30476 = PC + 1;
	cppVar_30476 = (cppVar_30476 & cppMask_un_16_);
	BIT_VEC cppVar_30477 = ROM.rd(cppVar_30476);
	bool cppVar_30479 = (cppVar_30477 == 135);
	if (cppVar_30479) {
	cppVar_30475 = PCON;
	} else {
	BIT_VEC cppVar_30480;
	BIT_VEC cppVar_30481 = PC + 1;
	cppVar_30481 = (cppVar_30481 & cppMask_un_16_);
	BIT_VEC cppVar_30482 = ROM.rd(cppVar_30481);
	bool cppVar_30484 = (cppVar_30482 == 136);
	if (cppVar_30484) {
	cppVar_30480 = TCON;
	} else {
	BIT_VEC cppVar_30485;
	BIT_VEC cppVar_30486 = PC + 1;
	cppVar_30486 = (cppVar_30486 & cppMask_un_16_);
	BIT_VEC cppVar_30487 = ROM.rd(cppVar_30486);
	bool cppVar_30489 = (cppVar_30487 == 137);
	if (cppVar_30489) {
	cppVar_30485 = TMOD;
	} else {
	BIT_VEC cppVar_30490;
	BIT_VEC cppVar_30491 = PC + 1;
	cppVar_30491 = (cppVar_30491 & cppMask_un_16_);
	BIT_VEC cppVar_30492 = ROM.rd(cppVar_30491);
	bool cppVar_30494 = (cppVar_30492 == 138);
	if (cppVar_30494) {
	cppVar_30490 = TL0;
	} else {
	BIT_VEC cppVar_30495;
	BIT_VEC cppVar_30496 = PC + 1;
	cppVar_30496 = (cppVar_30496 & cppMask_un_16_);
	BIT_VEC cppVar_30497 = ROM.rd(cppVar_30496);
	bool cppVar_30499 = (cppVar_30497 == 140);
	if (cppVar_30499) {
	cppVar_30495 = TH0;
	} else {
	BIT_VEC cppVar_30500;
	BIT_VEC cppVar_30501 = PC + 1;
	cppVar_30501 = (cppVar_30501 & cppMask_un_16_);
	BIT_VEC cppVar_30502 = ROM.rd(cppVar_30501);
	bool cppVar_30504 = (cppVar_30502 == 139);
	if (cppVar_30504) {
	cppVar_30500 = TL1;
	} else {
	BIT_VEC cppVar_30505;
	BIT_VEC cppVar_30506 = PC + 1;
	cppVar_30506 = (cppVar_30506 & cppMask_un_16_);
	BIT_VEC cppVar_30507 = ROM.rd(cppVar_30506);
	bool cppVar_30509 = (cppVar_30507 == 141);
	if (cppVar_30509) {
	cppVar_30505 = TH1;
	} else {
	BIT_VEC cppVar_30510;
	BIT_VEC cppVar_30511 = PC + 1;
	cppVar_30511 = (cppVar_30511 & cppMask_un_16_);
	BIT_VEC cppVar_30512 = ROM.rd(cppVar_30511);
	bool cppVar_30514 = (cppVar_30512 == 144);
	if (cppVar_30514) {
	cppVar_30510 = P1;
	} else {
	BIT_VEC cppVar_30515;
	BIT_VEC cppVar_30516 = PC + 1;
	cppVar_30516 = (cppVar_30516 & cppMask_un_16_);
	BIT_VEC cppVar_30517 = ROM.rd(cppVar_30516);
	bool cppVar_30519 = (cppVar_30517 == 152);
	if (cppVar_30519) {
	cppVar_30515 = SCON;
	} else {
	BIT_VEC cppVar_30520;
	BIT_VEC cppVar_30521 = PC + 1;
	cppVar_30521 = (cppVar_30521 & cppMask_un_16_);
	BIT_VEC cppVar_30522 = ROM.rd(cppVar_30521);
	bool cppVar_30524 = (cppVar_30522 == 153);
	if (cppVar_30524) {
	cppVar_30520 = SBUF;
	} else {
	BIT_VEC cppVar_30525;
	BIT_VEC cppVar_30526 = PC + 1;
	cppVar_30526 = (cppVar_30526 & cppMask_un_16_);
	BIT_VEC cppVar_30527 = ROM.rd(cppVar_30526);
	bool cppVar_30529 = (cppVar_30527 == 160);
	if (cppVar_30529) {
	cppVar_30525 = P2;
	} else {
	BIT_VEC cppVar_30530;
	BIT_VEC cppVar_30531 = PC + 1;
	cppVar_30531 = (cppVar_30531 & cppMask_un_16_);
	BIT_VEC cppVar_30532 = ROM.rd(cppVar_30531);
	bool cppVar_30534 = (cppVar_30532 == 168);
	if (cppVar_30534) {
	cppVar_30530 = IE;
	} else {
	BIT_VEC cppVar_30535;
	BIT_VEC cppVar_30536 = PC + 1;
	cppVar_30536 = (cppVar_30536 & cppMask_un_16_);
	BIT_VEC cppVar_30537 = ROM.rd(cppVar_30536);
	bool cppVar_30539 = (cppVar_30537 == 176);
	if (cppVar_30539) {
	cppVar_30535 = P3;
	} else {
	BIT_VEC cppVar_30540;
	BIT_VEC cppVar_30541 = PC + 1;
	cppVar_30541 = (cppVar_30541 & cppMask_un_16_);
	BIT_VEC cppVar_30542 = ROM.rd(cppVar_30541);
	bool cppVar_30544 = (cppVar_30542 == 184);
	if (cppVar_30544) {
	cppVar_30540 = IP;
	} else {
	BIT_VEC cppVar_30545;
	BIT_VEC cppVar_30546 = PC + 1;
	cppVar_30546 = (cppVar_30546 & cppMask_un_16_);
	BIT_VEC cppVar_30547 = ROM.rd(cppVar_30546);
	bool cppVar_30549 = (cppVar_30547 == 208);
	if (cppVar_30549) {
	cppVar_30545 = PSW;
	} else {
	BIT_VEC cppVar_30550;
	BIT_VEC cppVar_30551 = PC + 1;
	cppVar_30551 = (cppVar_30551 & cppMask_un_16_);
	BIT_VEC cppVar_30552 = ROM.rd(cppVar_30551);
	bool cppVar_30554 = (cppVar_30552 == 224);
	if (cppVar_30554) {
	cppVar_30550 = ACC;
	} else {
	BIT_VEC cppVar_30555;
	BIT_VEC cppVar_30556 = PC + 1;
	cppVar_30556 = (cppVar_30556 & cppMask_un_16_);
	BIT_VEC cppVar_30557 = ROM.rd(cppVar_30556);
	bool cppVar_30559 = (cppVar_30557 == 240);
	if (cppVar_30559) {
	cppVar_30555 = B;
	} else {
	cppVar_30555 = 0;
	}
	cppVar_30550 = cppVar_30555;
	}
	cppVar_30545 = cppVar_30550;
	}
	cppVar_30540 = cppVar_30545;
	}
	cppVar_30535 = cppVar_30540;
	}
	cppVar_30530 = cppVar_30535;
	}
	cppVar_30525 = cppVar_30530;
	}
	cppVar_30520 = cppVar_30525;
	}
	cppVar_30515 = cppVar_30520;
	}
	cppVar_30510 = cppVar_30515;
	}
	cppVar_30505 = cppVar_30510;
	}
	cppVar_30500 = cppVar_30505;
	}
	cppVar_30495 = cppVar_30500;
	}
	cppVar_30490 = cppVar_30495;
	}
	cppVar_30485 = cppVar_30490;
	}
	cppVar_30480 = cppVar_30485;
	}
	cppVar_30475 = cppVar_30480;
	}
	cppVar_30470 = cppVar_30475;
	}
	cppVar_30465 = cppVar_30470;
	}
	cppVar_30460 = cppVar_30465;
	}
	cppVar_30455 = cppVar_30460;
	}
	cppVar_30446 = cppVar_30455;
	}
	BIT_VEC cppVar_30562 = PC + 2;
	cppVar_30562 = (cppVar_30562 & cppMask_un_16_);
	BIT_VEC cppVar_30563 = ROM.rd(cppVar_30562);
	BIT_VEC cppVar_30564 = cppVar_30446 & cppVar_30563;
	cppVar_30440 = cppVar_30564;
	} else {
	cppVar_30440 = P1;
	}
	cppVar_30436 = cppVar_30440;
	} else {
	BIT_VEC cppVar_30565;
	BIT_VEC cppVar_30566 = ROM.rd(PC);
	bool cppVar_30568 = (cppVar_30566 == 82);
	if (cppVar_30568) {
	BIT_VEC cppVar_30569;
	BIT_VEC cppVar_30571 = PC + 1;
	cppVar_30571 = (cppVar_30571 & cppMask_un_16_);
	BIT_VEC cppVar_30572 = ROM.rd(cppVar_30571);
	bool cppVar_30574 = (cppVar_30572 == 144);
	if (cppVar_30574) {
	BIT_VEC cppVar_30575;
	BIT_VEC cppVar_30576 = PC + 1;
	cppVar_30576 = (cppVar_30576 & cppMask_un_16_);
	BIT_VEC cppVar_30577 = ROM.rd(cppVar_30576);
	BIT_VEC cppVar_30578 = (cppVar_30577 >> 7) & cppMask_un_1_;
	bool cppVar_30580 = (cppVar_30578 == 0);
	if (cppVar_30580) {
	BIT_VEC cppVar_30581 = PC + 1;
	cppVar_30581 = (cppVar_30581 & cppMask_un_16_);
	BIT_VEC cppVar_30582 = ROM.rd(cppVar_30581);
	BIT_VEC cppVar_30583 = IRAM.rd(cppVar_30582);
	cppVar_30575 = cppVar_30583;
	} else {
	BIT_VEC cppVar_30584;
	BIT_VEC cppVar_30585 = PC + 1;
	cppVar_30585 = (cppVar_30585 & cppMask_un_16_);
	BIT_VEC cppVar_30586 = ROM.rd(cppVar_30585);
	bool cppVar_30588 = (cppVar_30586 == 128);
	if (cppVar_30588) {
	cppVar_30584 = P0;
	} else {
	BIT_VEC cppVar_30589;
	BIT_VEC cppVar_30590 = PC + 1;
	cppVar_30590 = (cppVar_30590 & cppMask_un_16_);
	BIT_VEC cppVar_30591 = ROM.rd(cppVar_30590);
	bool cppVar_30593 = (cppVar_30591 == 129);
	if (cppVar_30593) {
	cppVar_30589 = SP;
	} else {
	BIT_VEC cppVar_30594;
	BIT_VEC cppVar_30595 = PC + 1;
	cppVar_30595 = (cppVar_30595 & cppMask_un_16_);
	BIT_VEC cppVar_30596 = ROM.rd(cppVar_30595);
	bool cppVar_30598 = (cppVar_30596 == 130);
	if (cppVar_30598) {
	cppVar_30594 = DPL;
	} else {
	BIT_VEC cppVar_30599;
	BIT_VEC cppVar_30600 = PC + 1;
	cppVar_30600 = (cppVar_30600 & cppMask_un_16_);
	BIT_VEC cppVar_30601 = ROM.rd(cppVar_30600);
	bool cppVar_30603 = (cppVar_30601 == 131);
	if (cppVar_30603) {
	cppVar_30599 = DPH;
	} else {
	BIT_VEC cppVar_30604;
	BIT_VEC cppVar_30605 = PC + 1;
	cppVar_30605 = (cppVar_30605 & cppMask_un_16_);
	BIT_VEC cppVar_30606 = ROM.rd(cppVar_30605);
	bool cppVar_30608 = (cppVar_30606 == 135);
	if (cppVar_30608) {
	cppVar_30604 = PCON;
	} else {
	BIT_VEC cppVar_30609;
	BIT_VEC cppVar_30610 = PC + 1;
	cppVar_30610 = (cppVar_30610 & cppMask_un_16_);
	BIT_VEC cppVar_30611 = ROM.rd(cppVar_30610);
	bool cppVar_30613 = (cppVar_30611 == 136);
	if (cppVar_30613) {
	cppVar_30609 = TCON;
	} else {
	BIT_VEC cppVar_30614;
	BIT_VEC cppVar_30615 = PC + 1;
	cppVar_30615 = (cppVar_30615 & cppMask_un_16_);
	BIT_VEC cppVar_30616 = ROM.rd(cppVar_30615);
	bool cppVar_30618 = (cppVar_30616 == 137);
	if (cppVar_30618) {
	cppVar_30614 = TMOD;
	} else {
	BIT_VEC cppVar_30619;
	BIT_VEC cppVar_30620 = PC + 1;
	cppVar_30620 = (cppVar_30620 & cppMask_un_16_);
	BIT_VEC cppVar_30621 = ROM.rd(cppVar_30620);
	bool cppVar_30623 = (cppVar_30621 == 138);
	if (cppVar_30623) {
	cppVar_30619 = TL0;
	} else {
	BIT_VEC cppVar_30624;
	BIT_VEC cppVar_30625 = PC + 1;
	cppVar_30625 = (cppVar_30625 & cppMask_un_16_);
	BIT_VEC cppVar_30626 = ROM.rd(cppVar_30625);
	bool cppVar_30628 = (cppVar_30626 == 140);
	if (cppVar_30628) {
	cppVar_30624 = TH0;
	} else {
	BIT_VEC cppVar_30629;
	BIT_VEC cppVar_30630 = PC + 1;
	cppVar_30630 = (cppVar_30630 & cppMask_un_16_);
	BIT_VEC cppVar_30631 = ROM.rd(cppVar_30630);
	bool cppVar_30633 = (cppVar_30631 == 139);
	if (cppVar_30633) {
	cppVar_30629 = TL1;
	} else {
	BIT_VEC cppVar_30634;
	BIT_VEC cppVar_30635 = PC + 1;
	cppVar_30635 = (cppVar_30635 & cppMask_un_16_);
	BIT_VEC cppVar_30636 = ROM.rd(cppVar_30635);
	bool cppVar_30638 = (cppVar_30636 == 141);
	if (cppVar_30638) {
	cppVar_30634 = TH1;
	} else {
	BIT_VEC cppVar_30639;
	BIT_VEC cppVar_30640 = PC + 1;
	cppVar_30640 = (cppVar_30640 & cppMask_un_16_);
	BIT_VEC cppVar_30641 = ROM.rd(cppVar_30640);
	bool cppVar_30643 = (cppVar_30641 == 144);
	if (cppVar_30643) {
	cppVar_30639 = P1;
	} else {
	BIT_VEC cppVar_30644;
	BIT_VEC cppVar_30645 = PC + 1;
	cppVar_30645 = (cppVar_30645 & cppMask_un_16_);
	BIT_VEC cppVar_30646 = ROM.rd(cppVar_30645);
	bool cppVar_30648 = (cppVar_30646 == 152);
	if (cppVar_30648) {
	cppVar_30644 = SCON;
	} else {
	BIT_VEC cppVar_30649;
	BIT_VEC cppVar_30650 = PC + 1;
	cppVar_30650 = (cppVar_30650 & cppMask_un_16_);
	BIT_VEC cppVar_30651 = ROM.rd(cppVar_30650);
	bool cppVar_30653 = (cppVar_30651 == 153);
	if (cppVar_30653) {
	cppVar_30649 = SBUF;
	} else {
	BIT_VEC cppVar_30654;
	BIT_VEC cppVar_30655 = PC + 1;
	cppVar_30655 = (cppVar_30655 & cppMask_un_16_);
	BIT_VEC cppVar_30656 = ROM.rd(cppVar_30655);
	bool cppVar_30658 = (cppVar_30656 == 160);
	if (cppVar_30658) {
	cppVar_30654 = P2;
	} else {
	BIT_VEC cppVar_30659;
	BIT_VEC cppVar_30660 = PC + 1;
	cppVar_30660 = (cppVar_30660 & cppMask_un_16_);
	BIT_VEC cppVar_30661 = ROM.rd(cppVar_30660);
	bool cppVar_30663 = (cppVar_30661 == 168);
	if (cppVar_30663) {
	cppVar_30659 = IE;
	} else {
	BIT_VEC cppVar_30664;
	BIT_VEC cppVar_30665 = PC + 1;
	cppVar_30665 = (cppVar_30665 & cppMask_un_16_);
	BIT_VEC cppVar_30666 = ROM.rd(cppVar_30665);
	bool cppVar_30668 = (cppVar_30666 == 176);
	if (cppVar_30668) {
	cppVar_30664 = P3;
	} else {
	BIT_VEC cppVar_30669;
	BIT_VEC cppVar_30670 = PC + 1;
	cppVar_30670 = (cppVar_30670 & cppMask_un_16_);
	BIT_VEC cppVar_30671 = ROM.rd(cppVar_30670);
	bool cppVar_30673 = (cppVar_30671 == 184);
	if (cppVar_30673) {
	cppVar_30669 = IP;
	} else {
	BIT_VEC cppVar_30674;
	BIT_VEC cppVar_30675 = PC + 1;
	cppVar_30675 = (cppVar_30675 & cppMask_un_16_);
	BIT_VEC cppVar_30676 = ROM.rd(cppVar_30675);
	bool cppVar_30678 = (cppVar_30676 == 208);
	if (cppVar_30678) {
	cppVar_30674 = PSW;
	} else {
	BIT_VEC cppVar_30679;
	BIT_VEC cppVar_30680 = PC + 1;
	cppVar_30680 = (cppVar_30680 & cppMask_un_16_);
	BIT_VEC cppVar_30681 = ROM.rd(cppVar_30680);
	bool cppVar_30683 = (cppVar_30681 == 224);
	if (cppVar_30683) {
	cppVar_30679 = ACC;
	} else {
	BIT_VEC cppVar_30684;
	BIT_VEC cppVar_30685 = PC + 1;
	cppVar_30685 = (cppVar_30685 & cppMask_un_16_);
	BIT_VEC cppVar_30686 = ROM.rd(cppVar_30685);
	bool cppVar_30688 = (cppVar_30686 == 240);
	if (cppVar_30688) {
	cppVar_30684 = B;
	} else {
	cppVar_30684 = 0;
	}
	cppVar_30679 = cppVar_30684;
	}
	cppVar_30674 = cppVar_30679;
	}
	cppVar_30669 = cppVar_30674;
	}
	cppVar_30664 = cppVar_30669;
	}
	cppVar_30659 = cppVar_30664;
	}
	cppVar_30654 = cppVar_30659;
	}
	cppVar_30649 = cppVar_30654;
	}
	cppVar_30644 = cppVar_30649;
	}
	cppVar_30639 = cppVar_30644;
	}
	cppVar_30634 = cppVar_30639;
	}
	cppVar_30629 = cppVar_30634;
	}
	cppVar_30624 = cppVar_30629;
	}
	cppVar_30619 = cppVar_30624;
	}
	cppVar_30614 = cppVar_30619;
	}
	cppVar_30609 = cppVar_30614;
	}
	cppVar_30604 = cppVar_30609;
	}
	cppVar_30599 = cppVar_30604;
	}
	cppVar_30594 = cppVar_30599;
	}
	cppVar_30589 = cppVar_30594;
	}
	cppVar_30584 = cppVar_30589;
	}
	cppVar_30575 = cppVar_30584;
	}
	BIT_VEC cppVar_30690 = cppVar_30575 & ACC;
	cppVar_30569 = cppVar_30690;
	} else {
	cppVar_30569 = P1;
	}
	cppVar_30565 = cppVar_30569;
	} else {
	BIT_VEC cppVar_30691;
	BIT_VEC cppVar_30692 = ROM.rd(PC);
	bool cppVar_30694 = (cppVar_30692 == 67);
	if (cppVar_30694) {
	BIT_VEC cppVar_30695;
	BIT_VEC cppVar_30697 = PC + 1;
	cppVar_30697 = (cppVar_30697 & cppMask_un_16_);
	BIT_VEC cppVar_30698 = ROM.rd(cppVar_30697);
	bool cppVar_30700 = (cppVar_30698 == 144);
	if (cppVar_30700) {
	BIT_VEC cppVar_30701;
	BIT_VEC cppVar_30702 = PC + 1;
	cppVar_30702 = (cppVar_30702 & cppMask_un_16_);
	BIT_VEC cppVar_30703 = ROM.rd(cppVar_30702);
	BIT_VEC cppVar_30704 = (cppVar_30703 >> 7) & cppMask_un_1_;
	bool cppVar_30706 = (cppVar_30704 == 0);
	if (cppVar_30706) {
	BIT_VEC cppVar_30707 = PC + 1;
	cppVar_30707 = (cppVar_30707 & cppMask_un_16_);
	BIT_VEC cppVar_30708 = ROM.rd(cppVar_30707);
	BIT_VEC cppVar_30709 = IRAM.rd(cppVar_30708);
	cppVar_30701 = cppVar_30709;
	} else {
	BIT_VEC cppVar_30710;
	BIT_VEC cppVar_30711 = PC + 1;
	cppVar_30711 = (cppVar_30711 & cppMask_un_16_);
	BIT_VEC cppVar_30712 = ROM.rd(cppVar_30711);
	bool cppVar_30714 = (cppVar_30712 == 128);
	if (cppVar_30714) {
	cppVar_30710 = P0;
	} else {
	BIT_VEC cppVar_30715;
	BIT_VEC cppVar_30716 = PC + 1;
	cppVar_30716 = (cppVar_30716 & cppMask_un_16_);
	BIT_VEC cppVar_30717 = ROM.rd(cppVar_30716);
	bool cppVar_30719 = (cppVar_30717 == 129);
	if (cppVar_30719) {
	cppVar_30715 = SP;
	} else {
	BIT_VEC cppVar_30720;
	BIT_VEC cppVar_30721 = PC + 1;
	cppVar_30721 = (cppVar_30721 & cppMask_un_16_);
	BIT_VEC cppVar_30722 = ROM.rd(cppVar_30721);
	bool cppVar_30724 = (cppVar_30722 == 130);
	if (cppVar_30724) {
	cppVar_30720 = DPL;
	} else {
	BIT_VEC cppVar_30725;
	BIT_VEC cppVar_30726 = PC + 1;
	cppVar_30726 = (cppVar_30726 & cppMask_un_16_);
	BIT_VEC cppVar_30727 = ROM.rd(cppVar_30726);
	bool cppVar_30729 = (cppVar_30727 == 131);
	if (cppVar_30729) {
	cppVar_30725 = DPH;
	} else {
	BIT_VEC cppVar_30730;
	BIT_VEC cppVar_30731 = PC + 1;
	cppVar_30731 = (cppVar_30731 & cppMask_un_16_);
	BIT_VEC cppVar_30732 = ROM.rd(cppVar_30731);
	bool cppVar_30734 = (cppVar_30732 == 135);
	if (cppVar_30734) {
	cppVar_30730 = PCON;
	} else {
	BIT_VEC cppVar_30735;
	BIT_VEC cppVar_30736 = PC + 1;
	cppVar_30736 = (cppVar_30736 & cppMask_un_16_);
	BIT_VEC cppVar_30737 = ROM.rd(cppVar_30736);
	bool cppVar_30739 = (cppVar_30737 == 136);
	if (cppVar_30739) {
	cppVar_30735 = TCON;
	} else {
	BIT_VEC cppVar_30740;
	BIT_VEC cppVar_30741 = PC + 1;
	cppVar_30741 = (cppVar_30741 & cppMask_un_16_);
	BIT_VEC cppVar_30742 = ROM.rd(cppVar_30741);
	bool cppVar_30744 = (cppVar_30742 == 137);
	if (cppVar_30744) {
	cppVar_30740 = TMOD;
	} else {
	BIT_VEC cppVar_30745;
	BIT_VEC cppVar_30746 = PC + 1;
	cppVar_30746 = (cppVar_30746 & cppMask_un_16_);
	BIT_VEC cppVar_30747 = ROM.rd(cppVar_30746);
	bool cppVar_30749 = (cppVar_30747 == 138);
	if (cppVar_30749) {
	cppVar_30745 = TL0;
	} else {
	BIT_VEC cppVar_30750;
	BIT_VEC cppVar_30751 = PC + 1;
	cppVar_30751 = (cppVar_30751 & cppMask_un_16_);
	BIT_VEC cppVar_30752 = ROM.rd(cppVar_30751);
	bool cppVar_30754 = (cppVar_30752 == 140);
	if (cppVar_30754) {
	cppVar_30750 = TH0;
	} else {
	BIT_VEC cppVar_30755;
	BIT_VEC cppVar_30756 = PC + 1;
	cppVar_30756 = (cppVar_30756 & cppMask_un_16_);
	BIT_VEC cppVar_30757 = ROM.rd(cppVar_30756);
	bool cppVar_30759 = (cppVar_30757 == 139);
	if (cppVar_30759) {
	cppVar_30755 = TL1;
	} else {
	BIT_VEC cppVar_30760;
	BIT_VEC cppVar_30761 = PC + 1;
	cppVar_30761 = (cppVar_30761 & cppMask_un_16_);
	BIT_VEC cppVar_30762 = ROM.rd(cppVar_30761);
	bool cppVar_30764 = (cppVar_30762 == 141);
	if (cppVar_30764) {
	cppVar_30760 = TH1;
	} else {
	BIT_VEC cppVar_30765;
	BIT_VEC cppVar_30766 = PC + 1;
	cppVar_30766 = (cppVar_30766 & cppMask_un_16_);
	BIT_VEC cppVar_30767 = ROM.rd(cppVar_30766);
	bool cppVar_30769 = (cppVar_30767 == 144);
	if (cppVar_30769) {
	cppVar_30765 = P1;
	} else {
	BIT_VEC cppVar_30770;
	BIT_VEC cppVar_30771 = PC + 1;
	cppVar_30771 = (cppVar_30771 & cppMask_un_16_);
	BIT_VEC cppVar_30772 = ROM.rd(cppVar_30771);
	bool cppVar_30774 = (cppVar_30772 == 152);
	if (cppVar_30774) {
	cppVar_30770 = SCON;
	} else {
	BIT_VEC cppVar_30775;
	BIT_VEC cppVar_30776 = PC + 1;
	cppVar_30776 = (cppVar_30776 & cppMask_un_16_);
	BIT_VEC cppVar_30777 = ROM.rd(cppVar_30776);
	bool cppVar_30779 = (cppVar_30777 == 153);
	if (cppVar_30779) {
	cppVar_30775 = SBUF;
	} else {
	BIT_VEC cppVar_30780;
	BIT_VEC cppVar_30781 = PC + 1;
	cppVar_30781 = (cppVar_30781 & cppMask_un_16_);
	BIT_VEC cppVar_30782 = ROM.rd(cppVar_30781);
	bool cppVar_30784 = (cppVar_30782 == 160);
	if (cppVar_30784) {
	cppVar_30780 = P2;
	} else {
	BIT_VEC cppVar_30785;
	BIT_VEC cppVar_30786 = PC + 1;
	cppVar_30786 = (cppVar_30786 & cppMask_un_16_);
	BIT_VEC cppVar_30787 = ROM.rd(cppVar_30786);
	bool cppVar_30789 = (cppVar_30787 == 168);
	if (cppVar_30789) {
	cppVar_30785 = IE;
	} else {
	BIT_VEC cppVar_30790;
	BIT_VEC cppVar_30791 = PC + 1;
	cppVar_30791 = (cppVar_30791 & cppMask_un_16_);
	BIT_VEC cppVar_30792 = ROM.rd(cppVar_30791);
	bool cppVar_30794 = (cppVar_30792 == 176);
	if (cppVar_30794) {
	cppVar_30790 = P3;
	} else {
	BIT_VEC cppVar_30795;
	BIT_VEC cppVar_30796 = PC + 1;
	cppVar_30796 = (cppVar_30796 & cppMask_un_16_);
	BIT_VEC cppVar_30797 = ROM.rd(cppVar_30796);
	bool cppVar_30799 = (cppVar_30797 == 184);
	if (cppVar_30799) {
	cppVar_30795 = IP;
	} else {
	BIT_VEC cppVar_30800;
	BIT_VEC cppVar_30801 = PC + 1;
	cppVar_30801 = (cppVar_30801 & cppMask_un_16_);
	BIT_VEC cppVar_30802 = ROM.rd(cppVar_30801);
	bool cppVar_30804 = (cppVar_30802 == 208);
	if (cppVar_30804) {
	cppVar_30800 = PSW;
	} else {
	BIT_VEC cppVar_30805;
	BIT_VEC cppVar_30806 = PC + 1;
	cppVar_30806 = (cppVar_30806 & cppMask_un_16_);
	BIT_VEC cppVar_30807 = ROM.rd(cppVar_30806);
	bool cppVar_30809 = (cppVar_30807 == 224);
	if (cppVar_30809) {
	cppVar_30805 = ACC;
	} else {
	BIT_VEC cppVar_30810;
	BIT_VEC cppVar_30811 = PC + 1;
	cppVar_30811 = (cppVar_30811 & cppMask_un_16_);
	BIT_VEC cppVar_30812 = ROM.rd(cppVar_30811);
	bool cppVar_30814 = (cppVar_30812 == 240);
	if (cppVar_30814) {
	cppVar_30810 = B;
	} else {
	cppVar_30810 = 0;
	}
	cppVar_30805 = cppVar_30810;
	}
	cppVar_30800 = cppVar_30805;
	}
	cppVar_30795 = cppVar_30800;
	}
	cppVar_30790 = cppVar_30795;
	}
	cppVar_30785 = cppVar_30790;
	}
	cppVar_30780 = cppVar_30785;
	}
	cppVar_30775 = cppVar_30780;
	}
	cppVar_30770 = cppVar_30775;
	}
	cppVar_30765 = cppVar_30770;
	}
	cppVar_30760 = cppVar_30765;
	}
	cppVar_30755 = cppVar_30760;
	}
	cppVar_30750 = cppVar_30755;
	}
	cppVar_30745 = cppVar_30750;
	}
	cppVar_30740 = cppVar_30745;
	}
	cppVar_30735 = cppVar_30740;
	}
	cppVar_30730 = cppVar_30735;
	}
	cppVar_30725 = cppVar_30730;
	}
	cppVar_30720 = cppVar_30725;
	}
	cppVar_30715 = cppVar_30720;
	}
	cppVar_30710 = cppVar_30715;
	}
	cppVar_30701 = cppVar_30710;
	}
	BIT_VEC cppVar_30817 = PC + 2;
	cppVar_30817 = (cppVar_30817 & cppMask_un_16_);
	BIT_VEC cppVar_30818 = ROM.rd(cppVar_30817);
	BIT_VEC cppVar_30819 = cppVar_30701 | cppVar_30818;
	cppVar_30695 = cppVar_30819;
	} else {
	cppVar_30695 = P1;
	}
	cppVar_30691 = cppVar_30695;
	} else {
	BIT_VEC cppVar_30820;
	BIT_VEC cppVar_30821 = ROM.rd(PC);
	bool cppVar_30823 = (cppVar_30821 == 66);
	if (cppVar_30823) {
	BIT_VEC cppVar_30824;
	BIT_VEC cppVar_30826 = PC + 1;
	cppVar_30826 = (cppVar_30826 & cppMask_un_16_);
	BIT_VEC cppVar_30827 = ROM.rd(cppVar_30826);
	bool cppVar_30829 = (cppVar_30827 == 144);
	if (cppVar_30829) {
	BIT_VEC cppVar_30830;
	BIT_VEC cppVar_30831 = PC + 1;
	cppVar_30831 = (cppVar_30831 & cppMask_un_16_);
	BIT_VEC cppVar_30832 = ROM.rd(cppVar_30831);
	BIT_VEC cppVar_30833 = (cppVar_30832 >> 7) & cppMask_un_1_;
	bool cppVar_30835 = (cppVar_30833 == 0);
	if (cppVar_30835) {
	BIT_VEC cppVar_30836 = PC + 1;
	cppVar_30836 = (cppVar_30836 & cppMask_un_16_);
	BIT_VEC cppVar_30837 = ROM.rd(cppVar_30836);
	BIT_VEC cppVar_30838 = IRAM.rd(cppVar_30837);
	cppVar_30830 = cppVar_30838;
	} else {
	BIT_VEC cppVar_30839;
	BIT_VEC cppVar_30840 = PC + 1;
	cppVar_30840 = (cppVar_30840 & cppMask_un_16_);
	BIT_VEC cppVar_30841 = ROM.rd(cppVar_30840);
	bool cppVar_30843 = (cppVar_30841 == 128);
	if (cppVar_30843) {
	cppVar_30839 = P0;
	} else {
	BIT_VEC cppVar_30844;
	BIT_VEC cppVar_30845 = PC + 1;
	cppVar_30845 = (cppVar_30845 & cppMask_un_16_);
	BIT_VEC cppVar_30846 = ROM.rd(cppVar_30845);
	bool cppVar_30848 = (cppVar_30846 == 129);
	if (cppVar_30848) {
	cppVar_30844 = SP;
	} else {
	BIT_VEC cppVar_30849;
	BIT_VEC cppVar_30850 = PC + 1;
	cppVar_30850 = (cppVar_30850 & cppMask_un_16_);
	BIT_VEC cppVar_30851 = ROM.rd(cppVar_30850);
	bool cppVar_30853 = (cppVar_30851 == 130);
	if (cppVar_30853) {
	cppVar_30849 = DPL;
	} else {
	BIT_VEC cppVar_30854;
	BIT_VEC cppVar_30855 = PC + 1;
	cppVar_30855 = (cppVar_30855 & cppMask_un_16_);
	BIT_VEC cppVar_30856 = ROM.rd(cppVar_30855);
	bool cppVar_30858 = (cppVar_30856 == 131);
	if (cppVar_30858) {
	cppVar_30854 = DPH;
	} else {
	BIT_VEC cppVar_30859;
	BIT_VEC cppVar_30860 = PC + 1;
	cppVar_30860 = (cppVar_30860 & cppMask_un_16_);
	BIT_VEC cppVar_30861 = ROM.rd(cppVar_30860);
	bool cppVar_30863 = (cppVar_30861 == 135);
	if (cppVar_30863) {
	cppVar_30859 = PCON;
	} else {
	BIT_VEC cppVar_30864;
	BIT_VEC cppVar_30865 = PC + 1;
	cppVar_30865 = (cppVar_30865 & cppMask_un_16_);
	BIT_VEC cppVar_30866 = ROM.rd(cppVar_30865);
	bool cppVar_30868 = (cppVar_30866 == 136);
	if (cppVar_30868) {
	cppVar_30864 = TCON;
	} else {
	BIT_VEC cppVar_30869;
	BIT_VEC cppVar_30870 = PC + 1;
	cppVar_30870 = (cppVar_30870 & cppMask_un_16_);
	BIT_VEC cppVar_30871 = ROM.rd(cppVar_30870);
	bool cppVar_30873 = (cppVar_30871 == 137);
	if (cppVar_30873) {
	cppVar_30869 = TMOD;
	} else {
	BIT_VEC cppVar_30874;
	BIT_VEC cppVar_30875 = PC + 1;
	cppVar_30875 = (cppVar_30875 & cppMask_un_16_);
	BIT_VEC cppVar_30876 = ROM.rd(cppVar_30875);
	bool cppVar_30878 = (cppVar_30876 == 138);
	if (cppVar_30878) {
	cppVar_30874 = TL0;
	} else {
	BIT_VEC cppVar_30879;
	BIT_VEC cppVar_30880 = PC + 1;
	cppVar_30880 = (cppVar_30880 & cppMask_un_16_);
	BIT_VEC cppVar_30881 = ROM.rd(cppVar_30880);
	bool cppVar_30883 = (cppVar_30881 == 140);
	if (cppVar_30883) {
	cppVar_30879 = TH0;
	} else {
	BIT_VEC cppVar_30884;
	BIT_VEC cppVar_30885 = PC + 1;
	cppVar_30885 = (cppVar_30885 & cppMask_un_16_);
	BIT_VEC cppVar_30886 = ROM.rd(cppVar_30885);
	bool cppVar_30888 = (cppVar_30886 == 139);
	if (cppVar_30888) {
	cppVar_30884 = TL1;
	} else {
	BIT_VEC cppVar_30889;
	BIT_VEC cppVar_30890 = PC + 1;
	cppVar_30890 = (cppVar_30890 & cppMask_un_16_);
	BIT_VEC cppVar_30891 = ROM.rd(cppVar_30890);
	bool cppVar_30893 = (cppVar_30891 == 141);
	if (cppVar_30893) {
	cppVar_30889 = TH1;
	} else {
	BIT_VEC cppVar_30894;
	BIT_VEC cppVar_30895 = PC + 1;
	cppVar_30895 = (cppVar_30895 & cppMask_un_16_);
	BIT_VEC cppVar_30896 = ROM.rd(cppVar_30895);
	bool cppVar_30898 = (cppVar_30896 == 144);
	if (cppVar_30898) {
	cppVar_30894 = P1;
	} else {
	BIT_VEC cppVar_30899;
	BIT_VEC cppVar_30900 = PC + 1;
	cppVar_30900 = (cppVar_30900 & cppMask_un_16_);
	BIT_VEC cppVar_30901 = ROM.rd(cppVar_30900);
	bool cppVar_30903 = (cppVar_30901 == 152);
	if (cppVar_30903) {
	cppVar_30899 = SCON;
	} else {
	BIT_VEC cppVar_30904;
	BIT_VEC cppVar_30905 = PC + 1;
	cppVar_30905 = (cppVar_30905 & cppMask_un_16_);
	BIT_VEC cppVar_30906 = ROM.rd(cppVar_30905);
	bool cppVar_30908 = (cppVar_30906 == 153);
	if (cppVar_30908) {
	cppVar_30904 = SBUF;
	} else {
	BIT_VEC cppVar_30909;
	BIT_VEC cppVar_30910 = PC + 1;
	cppVar_30910 = (cppVar_30910 & cppMask_un_16_);
	BIT_VEC cppVar_30911 = ROM.rd(cppVar_30910);
	bool cppVar_30913 = (cppVar_30911 == 160);
	if (cppVar_30913) {
	cppVar_30909 = P2;
	} else {
	BIT_VEC cppVar_30914;
	BIT_VEC cppVar_30915 = PC + 1;
	cppVar_30915 = (cppVar_30915 & cppMask_un_16_);
	BIT_VEC cppVar_30916 = ROM.rd(cppVar_30915);
	bool cppVar_30918 = (cppVar_30916 == 168);
	if (cppVar_30918) {
	cppVar_30914 = IE;
	} else {
	BIT_VEC cppVar_30919;
	BIT_VEC cppVar_30920 = PC + 1;
	cppVar_30920 = (cppVar_30920 & cppMask_un_16_);
	BIT_VEC cppVar_30921 = ROM.rd(cppVar_30920);
	bool cppVar_30923 = (cppVar_30921 == 176);
	if (cppVar_30923) {
	cppVar_30919 = P3;
	} else {
	BIT_VEC cppVar_30924;
	BIT_VEC cppVar_30925 = PC + 1;
	cppVar_30925 = (cppVar_30925 & cppMask_un_16_);
	BIT_VEC cppVar_30926 = ROM.rd(cppVar_30925);
	bool cppVar_30928 = (cppVar_30926 == 184);
	if (cppVar_30928) {
	cppVar_30924 = IP;
	} else {
	BIT_VEC cppVar_30929;
	BIT_VEC cppVar_30930 = PC + 1;
	cppVar_30930 = (cppVar_30930 & cppMask_un_16_);
	BIT_VEC cppVar_30931 = ROM.rd(cppVar_30930);
	bool cppVar_30933 = (cppVar_30931 == 208);
	if (cppVar_30933) {
	cppVar_30929 = PSW;
	} else {
	BIT_VEC cppVar_30934;
	BIT_VEC cppVar_30935 = PC + 1;
	cppVar_30935 = (cppVar_30935 & cppMask_un_16_);
	BIT_VEC cppVar_30936 = ROM.rd(cppVar_30935);
	bool cppVar_30938 = (cppVar_30936 == 224);
	if (cppVar_30938) {
	cppVar_30934 = ACC;
	} else {
	BIT_VEC cppVar_30939;
	BIT_VEC cppVar_30940 = PC + 1;
	cppVar_30940 = (cppVar_30940 & cppMask_un_16_);
	BIT_VEC cppVar_30941 = ROM.rd(cppVar_30940);
	bool cppVar_30943 = (cppVar_30941 == 240);
	if (cppVar_30943) {
	cppVar_30939 = B;
	} else {
	cppVar_30939 = 0;
	}
	cppVar_30934 = cppVar_30939;
	}
	cppVar_30929 = cppVar_30934;
	}
	cppVar_30924 = cppVar_30929;
	}
	cppVar_30919 = cppVar_30924;
	}
	cppVar_30914 = cppVar_30919;
	}
	cppVar_30909 = cppVar_30914;
	}
	cppVar_30904 = cppVar_30909;
	}
	cppVar_30899 = cppVar_30904;
	}
	cppVar_30894 = cppVar_30899;
	}
	cppVar_30889 = cppVar_30894;
	}
	cppVar_30884 = cppVar_30889;
	}
	cppVar_30879 = cppVar_30884;
	}
	cppVar_30874 = cppVar_30879;
	}
	cppVar_30869 = cppVar_30874;
	}
	cppVar_30864 = cppVar_30869;
	}
	cppVar_30859 = cppVar_30864;
	}
	cppVar_30854 = cppVar_30859;
	}
	cppVar_30849 = cppVar_30854;
	}
	cppVar_30844 = cppVar_30849;
	}
	cppVar_30839 = cppVar_30844;
	}
	cppVar_30830 = cppVar_30839;
	}
	BIT_VEC cppVar_30945 = cppVar_30830 | ACC;
	cppVar_30824 = cppVar_30945;
	} else {
	cppVar_30824 = P1;
	}
	cppVar_30820 = cppVar_30824;
	} else {
	BIT_VEC cppVar_30946;
	BIT_VEC cppVar_30947 = ROM.rd(PC);
	bool cppVar_30949 = (cppVar_30947 == 213);
	BIT_VEC cppVar_30950 = ROM.rd(PC);
	bool cppVar_30952 = (cppVar_30950 == 21);
	bool cppVar_30953 = cppVar_30949 || cppVar_30952;
	if (cppVar_30953) {
	BIT_VEC cppVar_30954;
	BIT_VEC cppVar_30956 = PC + 1;
	cppVar_30956 = (cppVar_30956 & cppMask_un_16_);
	BIT_VEC cppVar_30957 = ROM.rd(cppVar_30956);
	bool cppVar_30959 = (cppVar_30957 == 144);
	if (cppVar_30959) {
	BIT_VEC cppVar_30960;
	BIT_VEC cppVar_30961 = PC + 1;
	cppVar_30961 = (cppVar_30961 & cppMask_un_16_);
	BIT_VEC cppVar_30962 = ROM.rd(cppVar_30961);
	BIT_VEC cppVar_30963 = (cppVar_30962 >> 7) & cppMask_un_1_;
	bool cppVar_30965 = (cppVar_30963 == 0);
	if (cppVar_30965) {
	BIT_VEC cppVar_30966 = PC + 1;
	cppVar_30966 = (cppVar_30966 & cppMask_un_16_);
	BIT_VEC cppVar_30967 = ROM.rd(cppVar_30966);
	BIT_VEC cppVar_30968 = IRAM.rd(cppVar_30967);
	cppVar_30960 = cppVar_30968;
	} else {
	BIT_VEC cppVar_30969;
	BIT_VEC cppVar_30970 = PC + 1;
	cppVar_30970 = (cppVar_30970 & cppMask_un_16_);
	BIT_VEC cppVar_30971 = ROM.rd(cppVar_30970);
	bool cppVar_30973 = (cppVar_30971 == 128);
	if (cppVar_30973) {
	cppVar_30969 = P0;
	} else {
	BIT_VEC cppVar_30974;
	BIT_VEC cppVar_30975 = PC + 1;
	cppVar_30975 = (cppVar_30975 & cppMask_un_16_);
	BIT_VEC cppVar_30976 = ROM.rd(cppVar_30975);
	bool cppVar_30978 = (cppVar_30976 == 129);
	if (cppVar_30978) {
	cppVar_30974 = SP;
	} else {
	BIT_VEC cppVar_30979;
	BIT_VEC cppVar_30980 = PC + 1;
	cppVar_30980 = (cppVar_30980 & cppMask_un_16_);
	BIT_VEC cppVar_30981 = ROM.rd(cppVar_30980);
	bool cppVar_30983 = (cppVar_30981 == 130);
	if (cppVar_30983) {
	cppVar_30979 = DPL;
	} else {
	BIT_VEC cppVar_30984;
	BIT_VEC cppVar_30985 = PC + 1;
	cppVar_30985 = (cppVar_30985 & cppMask_un_16_);
	BIT_VEC cppVar_30986 = ROM.rd(cppVar_30985);
	bool cppVar_30988 = (cppVar_30986 == 131);
	if (cppVar_30988) {
	cppVar_30984 = DPH;
	} else {
	BIT_VEC cppVar_30989;
	BIT_VEC cppVar_30990 = PC + 1;
	cppVar_30990 = (cppVar_30990 & cppMask_un_16_);
	BIT_VEC cppVar_30991 = ROM.rd(cppVar_30990);
	bool cppVar_30993 = (cppVar_30991 == 135);
	if (cppVar_30993) {
	cppVar_30989 = PCON;
	} else {
	BIT_VEC cppVar_30994;
	BIT_VEC cppVar_30995 = PC + 1;
	cppVar_30995 = (cppVar_30995 & cppMask_un_16_);
	BIT_VEC cppVar_30996 = ROM.rd(cppVar_30995);
	bool cppVar_30998 = (cppVar_30996 == 136);
	if (cppVar_30998) {
	cppVar_30994 = TCON;
	} else {
	BIT_VEC cppVar_30999;
	BIT_VEC cppVar_31000 = PC + 1;
	cppVar_31000 = (cppVar_31000 & cppMask_un_16_);
	BIT_VEC cppVar_31001 = ROM.rd(cppVar_31000);
	bool cppVar_31003 = (cppVar_31001 == 137);
	if (cppVar_31003) {
	cppVar_30999 = TMOD;
	} else {
	BIT_VEC cppVar_31004;
	BIT_VEC cppVar_31005 = PC + 1;
	cppVar_31005 = (cppVar_31005 & cppMask_un_16_);
	BIT_VEC cppVar_31006 = ROM.rd(cppVar_31005);
	bool cppVar_31008 = (cppVar_31006 == 138);
	if (cppVar_31008) {
	cppVar_31004 = TL0;
	} else {
	BIT_VEC cppVar_31009;
	BIT_VEC cppVar_31010 = PC + 1;
	cppVar_31010 = (cppVar_31010 & cppMask_un_16_);
	BIT_VEC cppVar_31011 = ROM.rd(cppVar_31010);
	bool cppVar_31013 = (cppVar_31011 == 140);
	if (cppVar_31013) {
	cppVar_31009 = TH0;
	} else {
	BIT_VEC cppVar_31014;
	BIT_VEC cppVar_31015 = PC + 1;
	cppVar_31015 = (cppVar_31015 & cppMask_un_16_);
	BIT_VEC cppVar_31016 = ROM.rd(cppVar_31015);
	bool cppVar_31018 = (cppVar_31016 == 139);
	if (cppVar_31018) {
	cppVar_31014 = TL1;
	} else {
	BIT_VEC cppVar_31019;
	BIT_VEC cppVar_31020 = PC + 1;
	cppVar_31020 = (cppVar_31020 & cppMask_un_16_);
	BIT_VEC cppVar_31021 = ROM.rd(cppVar_31020);
	bool cppVar_31023 = (cppVar_31021 == 141);
	if (cppVar_31023) {
	cppVar_31019 = TH1;
	} else {
	BIT_VEC cppVar_31024;
	BIT_VEC cppVar_31025 = PC + 1;
	cppVar_31025 = (cppVar_31025 & cppMask_un_16_);
	BIT_VEC cppVar_31026 = ROM.rd(cppVar_31025);
	bool cppVar_31028 = (cppVar_31026 == 144);
	if (cppVar_31028) {
	cppVar_31024 = P1;
	} else {
	BIT_VEC cppVar_31029;
	BIT_VEC cppVar_31030 = PC + 1;
	cppVar_31030 = (cppVar_31030 & cppMask_un_16_);
	BIT_VEC cppVar_31031 = ROM.rd(cppVar_31030);
	bool cppVar_31033 = (cppVar_31031 == 152);
	if (cppVar_31033) {
	cppVar_31029 = SCON;
	} else {
	BIT_VEC cppVar_31034;
	BIT_VEC cppVar_31035 = PC + 1;
	cppVar_31035 = (cppVar_31035 & cppMask_un_16_);
	BIT_VEC cppVar_31036 = ROM.rd(cppVar_31035);
	bool cppVar_31038 = (cppVar_31036 == 153);
	if (cppVar_31038) {
	cppVar_31034 = SBUF;
	} else {
	BIT_VEC cppVar_31039;
	BIT_VEC cppVar_31040 = PC + 1;
	cppVar_31040 = (cppVar_31040 & cppMask_un_16_);
	BIT_VEC cppVar_31041 = ROM.rd(cppVar_31040);
	bool cppVar_31043 = (cppVar_31041 == 160);
	if (cppVar_31043) {
	cppVar_31039 = P2;
	} else {
	BIT_VEC cppVar_31044;
	BIT_VEC cppVar_31045 = PC + 1;
	cppVar_31045 = (cppVar_31045 & cppMask_un_16_);
	BIT_VEC cppVar_31046 = ROM.rd(cppVar_31045);
	bool cppVar_31048 = (cppVar_31046 == 168);
	if (cppVar_31048) {
	cppVar_31044 = IE;
	} else {
	BIT_VEC cppVar_31049;
	BIT_VEC cppVar_31050 = PC + 1;
	cppVar_31050 = (cppVar_31050 & cppMask_un_16_);
	BIT_VEC cppVar_31051 = ROM.rd(cppVar_31050);
	bool cppVar_31053 = (cppVar_31051 == 176);
	if (cppVar_31053) {
	cppVar_31049 = P3;
	} else {
	BIT_VEC cppVar_31054;
	BIT_VEC cppVar_31055 = PC + 1;
	cppVar_31055 = (cppVar_31055 & cppMask_un_16_);
	BIT_VEC cppVar_31056 = ROM.rd(cppVar_31055);
	bool cppVar_31058 = (cppVar_31056 == 184);
	if (cppVar_31058) {
	cppVar_31054 = IP;
	} else {
	BIT_VEC cppVar_31059;
	BIT_VEC cppVar_31060 = PC + 1;
	cppVar_31060 = (cppVar_31060 & cppMask_un_16_);
	BIT_VEC cppVar_31061 = ROM.rd(cppVar_31060);
	bool cppVar_31063 = (cppVar_31061 == 208);
	if (cppVar_31063) {
	cppVar_31059 = PSW;
	} else {
	BIT_VEC cppVar_31064;
	BIT_VEC cppVar_31065 = PC + 1;
	cppVar_31065 = (cppVar_31065 & cppMask_un_16_);
	BIT_VEC cppVar_31066 = ROM.rd(cppVar_31065);
	bool cppVar_31068 = (cppVar_31066 == 224);
	if (cppVar_31068) {
	cppVar_31064 = ACC;
	} else {
	BIT_VEC cppVar_31069;
	BIT_VEC cppVar_31070 = PC + 1;
	cppVar_31070 = (cppVar_31070 & cppMask_un_16_);
	BIT_VEC cppVar_31071 = ROM.rd(cppVar_31070);
	bool cppVar_31073 = (cppVar_31071 == 240);
	if (cppVar_31073) {
	cppVar_31069 = B;
	} else {
	cppVar_31069 = 0;
	}
	cppVar_31064 = cppVar_31069;
	}
	cppVar_31059 = cppVar_31064;
	}
	cppVar_31054 = cppVar_31059;
	}
	cppVar_31049 = cppVar_31054;
	}
	cppVar_31044 = cppVar_31049;
	}
	cppVar_31039 = cppVar_31044;
	}
	cppVar_31034 = cppVar_31039;
	}
	cppVar_31029 = cppVar_31034;
	}
	cppVar_31024 = cppVar_31029;
	}
	cppVar_31019 = cppVar_31024;
	}
	cppVar_31014 = cppVar_31019;
	}
	cppVar_31009 = cppVar_31014;
	}
	cppVar_31004 = cppVar_31009;
	}
	cppVar_30999 = cppVar_31004;
	}
	cppVar_30994 = cppVar_30999;
	}
	cppVar_30989 = cppVar_30994;
	}
	cppVar_30984 = cppVar_30989;
	}
	cppVar_30979 = cppVar_30984;
	}
	cppVar_30974 = cppVar_30979;
	}
	cppVar_30969 = cppVar_30974;
	}
	cppVar_30960 = cppVar_30969;
	}
	BIT_VEC cppVar_31076 = cppVar_30960 - 1;
	cppVar_31076 = (cppVar_31076 & cppMask_un_8_);
	cppVar_30954 = cppVar_31076;
	} else {
	cppVar_30954 = P1;
	}
	cppVar_30946 = cppVar_30954;
	} else {
	BIT_VEC cppVar_31077;
	BIT_VEC cppVar_31078 = ROM.rd(PC);
	bool cppVar_31080 = (cppVar_31078 == 194);
	BIT_VEC cppVar_31081 = ROM.rd(PC);
	bool cppVar_31083 = (cppVar_31081 == 16);
	bool cppVar_31084 = cppVar_31080 || cppVar_31083;
	if (cppVar_31084) {
	BIT_VEC cppVar_31085;
	BIT_VEC cppVar_31086;
	BIT_VEC cppVar_31088 = PC + 1;
	cppVar_31088 = (cppVar_31088 & cppMask_un_16_);
	BIT_VEC cppVar_31089 = ROM.rd(cppVar_31088);
	BIT_VEC cppVar_31090 = (cppVar_31089 >> 7) & cppMask_un_1_;
	bool cppVar_31092 = (cppVar_31090 == 1);
	if (cppVar_31092) {
	BIT_VEC cppVar_31093 = PC + 1;
	cppVar_31093 = (cppVar_31093 & cppMask_un_16_);
	BIT_VEC cppVar_31094 = ROM.rd(cppVar_31093);
	BIT_VEC cppVar_31095 = (cppVar_31094 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31097 = (cppVar_31095 << 3) | 0;
	cppVar_31097 = (cppVar_31097 & cppMask_un_8_);
	cppVar_31086 = cppVar_31097;
	} else {
	BIT_VEC cppVar_31098 = PC + 1;
	cppVar_31098 = (cppVar_31098 & cppMask_un_16_);
	BIT_VEC cppVar_31099 = ROM.rd(cppVar_31098);
	BIT_VEC cppVar_31100 = (cppVar_31099 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31101 = (cppVar_31100 & cppMask_un_5_);
	BIT_VEC cppVar_31103 = cppVar_31101 + 32;
	cppVar_31103 = (cppVar_31103 & cppMask_un_8_);
	cppVar_31086 = cppVar_31103;
	}
	bool cppVar_31105 = (cppVar_31086 == 144);
	if (cppVar_31105) {
	BIT_VEC cppVar_31107 = PC + 1;
	cppVar_31107 = (cppVar_31107 & cppMask_un_16_);
	BIT_VEC cppVar_31108 = ROM.rd(cppVar_31107);
	BIT_VEC cppVar_31109 = (cppVar_31108 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_31110 = (cppVar_31109 & cppMask_un_3_);
	BIT_VEC cppVar_31111 = 1 << static_cast<unsigned>(cppVar_31110);
	cppVar_31111 = (cppVar_31111 & cppMask_un_8_);
	BIT_VEC cppVar_31112 = ~cppVar_31111;
	BIT_VEC cppVar_31113;
	BIT_VEC cppVar_31114;
	BIT_VEC cppVar_31115 = PC + 1;
	cppVar_31115 = (cppVar_31115 & cppMask_un_16_);
	BIT_VEC cppVar_31116 = ROM.rd(cppVar_31115);
	BIT_VEC cppVar_31117 = (cppVar_31116 >> 7) & cppMask_un_1_;
	bool cppVar_31118 = (cppVar_31117 == 1);
	if (cppVar_31118) {
	BIT_VEC cppVar_31119 = PC + 1;
	cppVar_31119 = (cppVar_31119 & cppMask_un_16_);
	BIT_VEC cppVar_31120 = ROM.rd(cppVar_31119);
	BIT_VEC cppVar_31121 = (cppVar_31120 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31122 = (cppVar_31121 << 3) | 0;
	cppVar_31122 = (cppVar_31122 & cppMask_un_8_);
	cppVar_31114 = cppVar_31122;
	} else {
	BIT_VEC cppVar_31123 = PC + 1;
	cppVar_31123 = (cppVar_31123 & cppMask_un_16_);
	BIT_VEC cppVar_31124 = ROM.rd(cppVar_31123);
	BIT_VEC cppVar_31125 = (cppVar_31124 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31126 = (cppVar_31125 & cppMask_un_5_);
	BIT_VEC cppVar_31127 = cppVar_31126 + 32;
	cppVar_31127 = (cppVar_31127 & cppMask_un_8_);
	cppVar_31114 = cppVar_31127;
	}
	BIT_VEC cppVar_31128 = (cppVar_31114 >> 7) & cppMask_un_1_;
	bool cppVar_31130 = (cppVar_31128 == 0);
	if (cppVar_31130) {
	BIT_VEC cppVar_31131;
	BIT_VEC cppVar_31132 = PC + 1;
	cppVar_31132 = (cppVar_31132 & cppMask_un_16_);
	BIT_VEC cppVar_31133 = ROM.rd(cppVar_31132);
	BIT_VEC cppVar_31134 = (cppVar_31133 >> 7) & cppMask_un_1_;
	bool cppVar_31135 = (cppVar_31134 == 1);
	if (cppVar_31135) {
	BIT_VEC cppVar_31136 = PC + 1;
	cppVar_31136 = (cppVar_31136 & cppMask_un_16_);
	BIT_VEC cppVar_31137 = ROM.rd(cppVar_31136);
	BIT_VEC cppVar_31138 = (cppVar_31137 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31139 = (cppVar_31138 << 3) | 0;
	cppVar_31139 = (cppVar_31139 & cppMask_un_8_);
	cppVar_31131 = cppVar_31139;
	} else {
	BIT_VEC cppVar_31140 = PC + 1;
	cppVar_31140 = (cppVar_31140 & cppMask_un_16_);
	BIT_VEC cppVar_31141 = ROM.rd(cppVar_31140);
	BIT_VEC cppVar_31142 = (cppVar_31141 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31143 = (cppVar_31142 & cppMask_un_5_);
	BIT_VEC cppVar_31144 = cppVar_31143 + 32;
	cppVar_31144 = (cppVar_31144 & cppMask_un_8_);
	cppVar_31131 = cppVar_31144;
	}
	BIT_VEC cppVar_31145 = IRAM.rd(cppVar_31131);
	cppVar_31113 = cppVar_31145;
	} else {
	BIT_VEC cppVar_31146;
	BIT_VEC cppVar_31147;
	BIT_VEC cppVar_31148 = PC + 1;
	cppVar_31148 = (cppVar_31148 & cppMask_un_16_);
	BIT_VEC cppVar_31149 = ROM.rd(cppVar_31148);
	BIT_VEC cppVar_31150 = (cppVar_31149 >> 7) & cppMask_un_1_;
	bool cppVar_31151 = (cppVar_31150 == 1);
	if (cppVar_31151) {
	BIT_VEC cppVar_31152 = PC + 1;
	cppVar_31152 = (cppVar_31152 & cppMask_un_16_);
	BIT_VEC cppVar_31153 = ROM.rd(cppVar_31152);
	BIT_VEC cppVar_31154 = (cppVar_31153 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31155 = (cppVar_31154 << 3) | 0;
	cppVar_31155 = (cppVar_31155 & cppMask_un_8_);
	cppVar_31147 = cppVar_31155;
	} else {
	BIT_VEC cppVar_31156 = PC + 1;
	cppVar_31156 = (cppVar_31156 & cppMask_un_16_);
	BIT_VEC cppVar_31157 = ROM.rd(cppVar_31156);
	BIT_VEC cppVar_31158 = (cppVar_31157 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31159 = (cppVar_31158 & cppMask_un_5_);
	BIT_VEC cppVar_31160 = cppVar_31159 + 32;
	cppVar_31160 = (cppVar_31160 & cppMask_un_8_);
	cppVar_31147 = cppVar_31160;
	}
	bool cppVar_31162 = (cppVar_31147 == 128);
	if (cppVar_31162) {
	cppVar_31146 = P0;
	} else {
	BIT_VEC cppVar_31163;
	BIT_VEC cppVar_31164;
	BIT_VEC cppVar_31165 = PC + 1;
	cppVar_31165 = (cppVar_31165 & cppMask_un_16_);
	BIT_VEC cppVar_31166 = ROM.rd(cppVar_31165);
	BIT_VEC cppVar_31167 = (cppVar_31166 >> 7) & cppMask_un_1_;
	bool cppVar_31168 = (cppVar_31167 == 1);
	if (cppVar_31168) {
	BIT_VEC cppVar_31169 = PC + 1;
	cppVar_31169 = (cppVar_31169 & cppMask_un_16_);
	BIT_VEC cppVar_31170 = ROM.rd(cppVar_31169);
	BIT_VEC cppVar_31171 = (cppVar_31170 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31172 = (cppVar_31171 << 3) | 0;
	cppVar_31172 = (cppVar_31172 & cppMask_un_8_);
	cppVar_31164 = cppVar_31172;
	} else {
	BIT_VEC cppVar_31173 = PC + 1;
	cppVar_31173 = (cppVar_31173 & cppMask_un_16_);
	BIT_VEC cppVar_31174 = ROM.rd(cppVar_31173);
	BIT_VEC cppVar_31175 = (cppVar_31174 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31176 = (cppVar_31175 & cppMask_un_5_);
	BIT_VEC cppVar_31177 = cppVar_31176 + 32;
	cppVar_31177 = (cppVar_31177 & cppMask_un_8_);
	cppVar_31164 = cppVar_31177;
	}
	bool cppVar_31179 = (cppVar_31164 == 129);
	if (cppVar_31179) {
	cppVar_31163 = SP;
	} else {
	BIT_VEC cppVar_31180;
	BIT_VEC cppVar_31181;
	BIT_VEC cppVar_31182 = PC + 1;
	cppVar_31182 = (cppVar_31182 & cppMask_un_16_);
	BIT_VEC cppVar_31183 = ROM.rd(cppVar_31182);
	BIT_VEC cppVar_31184 = (cppVar_31183 >> 7) & cppMask_un_1_;
	bool cppVar_31185 = (cppVar_31184 == 1);
	if (cppVar_31185) {
	BIT_VEC cppVar_31186 = PC + 1;
	cppVar_31186 = (cppVar_31186 & cppMask_un_16_);
	BIT_VEC cppVar_31187 = ROM.rd(cppVar_31186);
	BIT_VEC cppVar_31188 = (cppVar_31187 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31189 = (cppVar_31188 << 3) | 0;
	cppVar_31189 = (cppVar_31189 & cppMask_un_8_);
	cppVar_31181 = cppVar_31189;
	} else {
	BIT_VEC cppVar_31190 = PC + 1;
	cppVar_31190 = (cppVar_31190 & cppMask_un_16_);
	BIT_VEC cppVar_31191 = ROM.rd(cppVar_31190);
	BIT_VEC cppVar_31192 = (cppVar_31191 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31193 = (cppVar_31192 & cppMask_un_5_);
	BIT_VEC cppVar_31194 = cppVar_31193 + 32;
	cppVar_31194 = (cppVar_31194 & cppMask_un_8_);
	cppVar_31181 = cppVar_31194;
	}
	bool cppVar_31196 = (cppVar_31181 == 130);
	if (cppVar_31196) {
	cppVar_31180 = DPL;
	} else {
	BIT_VEC cppVar_31197;
	BIT_VEC cppVar_31198;
	BIT_VEC cppVar_31199 = PC + 1;
	cppVar_31199 = (cppVar_31199 & cppMask_un_16_);
	BIT_VEC cppVar_31200 = ROM.rd(cppVar_31199);
	BIT_VEC cppVar_31201 = (cppVar_31200 >> 7) & cppMask_un_1_;
	bool cppVar_31202 = (cppVar_31201 == 1);
	if (cppVar_31202) {
	BIT_VEC cppVar_31203 = PC + 1;
	cppVar_31203 = (cppVar_31203 & cppMask_un_16_);
	BIT_VEC cppVar_31204 = ROM.rd(cppVar_31203);
	BIT_VEC cppVar_31205 = (cppVar_31204 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31206 = (cppVar_31205 << 3) | 0;
	cppVar_31206 = (cppVar_31206 & cppMask_un_8_);
	cppVar_31198 = cppVar_31206;
	} else {
	BIT_VEC cppVar_31207 = PC + 1;
	cppVar_31207 = (cppVar_31207 & cppMask_un_16_);
	BIT_VEC cppVar_31208 = ROM.rd(cppVar_31207);
	BIT_VEC cppVar_31209 = (cppVar_31208 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31210 = (cppVar_31209 & cppMask_un_5_);
	BIT_VEC cppVar_31211 = cppVar_31210 + 32;
	cppVar_31211 = (cppVar_31211 & cppMask_un_8_);
	cppVar_31198 = cppVar_31211;
	}
	bool cppVar_31213 = (cppVar_31198 == 131);
	if (cppVar_31213) {
	cppVar_31197 = DPH;
	} else {
	BIT_VEC cppVar_31214;
	BIT_VEC cppVar_31215;
	BIT_VEC cppVar_31216 = PC + 1;
	cppVar_31216 = (cppVar_31216 & cppMask_un_16_);
	BIT_VEC cppVar_31217 = ROM.rd(cppVar_31216);
	BIT_VEC cppVar_31218 = (cppVar_31217 >> 7) & cppMask_un_1_;
	bool cppVar_31219 = (cppVar_31218 == 1);
	if (cppVar_31219) {
	BIT_VEC cppVar_31220 = PC + 1;
	cppVar_31220 = (cppVar_31220 & cppMask_un_16_);
	BIT_VEC cppVar_31221 = ROM.rd(cppVar_31220);
	BIT_VEC cppVar_31222 = (cppVar_31221 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31223 = (cppVar_31222 << 3) | 0;
	cppVar_31223 = (cppVar_31223 & cppMask_un_8_);
	cppVar_31215 = cppVar_31223;
	} else {
	BIT_VEC cppVar_31224 = PC + 1;
	cppVar_31224 = (cppVar_31224 & cppMask_un_16_);
	BIT_VEC cppVar_31225 = ROM.rd(cppVar_31224);
	BIT_VEC cppVar_31226 = (cppVar_31225 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31227 = (cppVar_31226 & cppMask_un_5_);
	BIT_VEC cppVar_31228 = cppVar_31227 + 32;
	cppVar_31228 = (cppVar_31228 & cppMask_un_8_);
	cppVar_31215 = cppVar_31228;
	}
	bool cppVar_31230 = (cppVar_31215 == 135);
	if (cppVar_31230) {
	cppVar_31214 = PCON;
	} else {
	BIT_VEC cppVar_31231;
	BIT_VEC cppVar_31232;
	BIT_VEC cppVar_31233 = PC + 1;
	cppVar_31233 = (cppVar_31233 & cppMask_un_16_);
	BIT_VEC cppVar_31234 = ROM.rd(cppVar_31233);
	BIT_VEC cppVar_31235 = (cppVar_31234 >> 7) & cppMask_un_1_;
	bool cppVar_31236 = (cppVar_31235 == 1);
	if (cppVar_31236) {
	BIT_VEC cppVar_31237 = PC + 1;
	cppVar_31237 = (cppVar_31237 & cppMask_un_16_);
	BIT_VEC cppVar_31238 = ROM.rd(cppVar_31237);
	BIT_VEC cppVar_31239 = (cppVar_31238 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31240 = (cppVar_31239 << 3) | 0;
	cppVar_31240 = (cppVar_31240 & cppMask_un_8_);
	cppVar_31232 = cppVar_31240;
	} else {
	BIT_VEC cppVar_31241 = PC + 1;
	cppVar_31241 = (cppVar_31241 & cppMask_un_16_);
	BIT_VEC cppVar_31242 = ROM.rd(cppVar_31241);
	BIT_VEC cppVar_31243 = (cppVar_31242 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31244 = (cppVar_31243 & cppMask_un_5_);
	BIT_VEC cppVar_31245 = cppVar_31244 + 32;
	cppVar_31245 = (cppVar_31245 & cppMask_un_8_);
	cppVar_31232 = cppVar_31245;
	}
	bool cppVar_31247 = (cppVar_31232 == 136);
	if (cppVar_31247) {
	cppVar_31231 = TCON;
	} else {
	BIT_VEC cppVar_31248;
	BIT_VEC cppVar_31249;
	BIT_VEC cppVar_31250 = PC + 1;
	cppVar_31250 = (cppVar_31250 & cppMask_un_16_);
	BIT_VEC cppVar_31251 = ROM.rd(cppVar_31250);
	BIT_VEC cppVar_31252 = (cppVar_31251 >> 7) & cppMask_un_1_;
	bool cppVar_31253 = (cppVar_31252 == 1);
	if (cppVar_31253) {
	BIT_VEC cppVar_31254 = PC + 1;
	cppVar_31254 = (cppVar_31254 & cppMask_un_16_);
	BIT_VEC cppVar_31255 = ROM.rd(cppVar_31254);
	BIT_VEC cppVar_31256 = (cppVar_31255 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31257 = (cppVar_31256 << 3) | 0;
	cppVar_31257 = (cppVar_31257 & cppMask_un_8_);
	cppVar_31249 = cppVar_31257;
	} else {
	BIT_VEC cppVar_31258 = PC + 1;
	cppVar_31258 = (cppVar_31258 & cppMask_un_16_);
	BIT_VEC cppVar_31259 = ROM.rd(cppVar_31258);
	BIT_VEC cppVar_31260 = (cppVar_31259 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31261 = (cppVar_31260 & cppMask_un_5_);
	BIT_VEC cppVar_31262 = cppVar_31261 + 32;
	cppVar_31262 = (cppVar_31262 & cppMask_un_8_);
	cppVar_31249 = cppVar_31262;
	}
	bool cppVar_31264 = (cppVar_31249 == 137);
	if (cppVar_31264) {
	cppVar_31248 = TMOD;
	} else {
	BIT_VEC cppVar_31265;
	BIT_VEC cppVar_31266;
	BIT_VEC cppVar_31267 = PC + 1;
	cppVar_31267 = (cppVar_31267 & cppMask_un_16_);
	BIT_VEC cppVar_31268 = ROM.rd(cppVar_31267);
	BIT_VEC cppVar_31269 = (cppVar_31268 >> 7) & cppMask_un_1_;
	bool cppVar_31270 = (cppVar_31269 == 1);
	if (cppVar_31270) {
	BIT_VEC cppVar_31271 = PC + 1;
	cppVar_31271 = (cppVar_31271 & cppMask_un_16_);
	BIT_VEC cppVar_31272 = ROM.rd(cppVar_31271);
	BIT_VEC cppVar_31273 = (cppVar_31272 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31274 = (cppVar_31273 << 3) | 0;
	cppVar_31274 = (cppVar_31274 & cppMask_un_8_);
	cppVar_31266 = cppVar_31274;
	} else {
	BIT_VEC cppVar_31275 = PC + 1;
	cppVar_31275 = (cppVar_31275 & cppMask_un_16_);
	BIT_VEC cppVar_31276 = ROM.rd(cppVar_31275);
	BIT_VEC cppVar_31277 = (cppVar_31276 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31278 = (cppVar_31277 & cppMask_un_5_);
	BIT_VEC cppVar_31279 = cppVar_31278 + 32;
	cppVar_31279 = (cppVar_31279 & cppMask_un_8_);
	cppVar_31266 = cppVar_31279;
	}
	bool cppVar_31281 = (cppVar_31266 == 138);
	if (cppVar_31281) {
	cppVar_31265 = TL0;
	} else {
	BIT_VEC cppVar_31282;
	BIT_VEC cppVar_31283;
	BIT_VEC cppVar_31284 = PC + 1;
	cppVar_31284 = (cppVar_31284 & cppMask_un_16_);
	BIT_VEC cppVar_31285 = ROM.rd(cppVar_31284);
	BIT_VEC cppVar_31286 = (cppVar_31285 >> 7) & cppMask_un_1_;
	bool cppVar_31287 = (cppVar_31286 == 1);
	if (cppVar_31287) {
	BIT_VEC cppVar_31288 = PC + 1;
	cppVar_31288 = (cppVar_31288 & cppMask_un_16_);
	BIT_VEC cppVar_31289 = ROM.rd(cppVar_31288);
	BIT_VEC cppVar_31290 = (cppVar_31289 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31291 = (cppVar_31290 << 3) | 0;
	cppVar_31291 = (cppVar_31291 & cppMask_un_8_);
	cppVar_31283 = cppVar_31291;
	} else {
	BIT_VEC cppVar_31292 = PC + 1;
	cppVar_31292 = (cppVar_31292 & cppMask_un_16_);
	BIT_VEC cppVar_31293 = ROM.rd(cppVar_31292);
	BIT_VEC cppVar_31294 = (cppVar_31293 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31295 = (cppVar_31294 & cppMask_un_5_);
	BIT_VEC cppVar_31296 = cppVar_31295 + 32;
	cppVar_31296 = (cppVar_31296 & cppMask_un_8_);
	cppVar_31283 = cppVar_31296;
	}
	bool cppVar_31298 = (cppVar_31283 == 140);
	if (cppVar_31298) {
	cppVar_31282 = TH0;
	} else {
	BIT_VEC cppVar_31299;
	BIT_VEC cppVar_31300;
	BIT_VEC cppVar_31301 = PC + 1;
	cppVar_31301 = (cppVar_31301 & cppMask_un_16_);
	BIT_VEC cppVar_31302 = ROM.rd(cppVar_31301);
	BIT_VEC cppVar_31303 = (cppVar_31302 >> 7) & cppMask_un_1_;
	bool cppVar_31304 = (cppVar_31303 == 1);
	if (cppVar_31304) {
	BIT_VEC cppVar_31305 = PC + 1;
	cppVar_31305 = (cppVar_31305 & cppMask_un_16_);
	BIT_VEC cppVar_31306 = ROM.rd(cppVar_31305);
	BIT_VEC cppVar_31307 = (cppVar_31306 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31308 = (cppVar_31307 << 3) | 0;
	cppVar_31308 = (cppVar_31308 & cppMask_un_8_);
	cppVar_31300 = cppVar_31308;
	} else {
	BIT_VEC cppVar_31309 = PC + 1;
	cppVar_31309 = (cppVar_31309 & cppMask_un_16_);
	BIT_VEC cppVar_31310 = ROM.rd(cppVar_31309);
	BIT_VEC cppVar_31311 = (cppVar_31310 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31312 = (cppVar_31311 & cppMask_un_5_);
	BIT_VEC cppVar_31313 = cppVar_31312 + 32;
	cppVar_31313 = (cppVar_31313 & cppMask_un_8_);
	cppVar_31300 = cppVar_31313;
	}
	bool cppVar_31315 = (cppVar_31300 == 139);
	if (cppVar_31315) {
	cppVar_31299 = TL1;
	} else {
	BIT_VEC cppVar_31316;
	BIT_VEC cppVar_31317;
	BIT_VEC cppVar_31318 = PC + 1;
	cppVar_31318 = (cppVar_31318 & cppMask_un_16_);
	BIT_VEC cppVar_31319 = ROM.rd(cppVar_31318);
	BIT_VEC cppVar_31320 = (cppVar_31319 >> 7) & cppMask_un_1_;
	bool cppVar_31321 = (cppVar_31320 == 1);
	if (cppVar_31321) {
	BIT_VEC cppVar_31322 = PC + 1;
	cppVar_31322 = (cppVar_31322 & cppMask_un_16_);
	BIT_VEC cppVar_31323 = ROM.rd(cppVar_31322);
	BIT_VEC cppVar_31324 = (cppVar_31323 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31325 = (cppVar_31324 << 3) | 0;
	cppVar_31325 = (cppVar_31325 & cppMask_un_8_);
	cppVar_31317 = cppVar_31325;
	} else {
	BIT_VEC cppVar_31326 = PC + 1;
	cppVar_31326 = (cppVar_31326 & cppMask_un_16_);
	BIT_VEC cppVar_31327 = ROM.rd(cppVar_31326);
	BIT_VEC cppVar_31328 = (cppVar_31327 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31329 = (cppVar_31328 & cppMask_un_5_);
	BIT_VEC cppVar_31330 = cppVar_31329 + 32;
	cppVar_31330 = (cppVar_31330 & cppMask_un_8_);
	cppVar_31317 = cppVar_31330;
	}
	bool cppVar_31332 = (cppVar_31317 == 141);
	if (cppVar_31332) {
	cppVar_31316 = TH1;
	} else {
	BIT_VEC cppVar_31333;
	BIT_VEC cppVar_31334;
	BIT_VEC cppVar_31335 = PC + 1;
	cppVar_31335 = (cppVar_31335 & cppMask_un_16_);
	BIT_VEC cppVar_31336 = ROM.rd(cppVar_31335);
	BIT_VEC cppVar_31337 = (cppVar_31336 >> 7) & cppMask_un_1_;
	bool cppVar_31338 = (cppVar_31337 == 1);
	if (cppVar_31338) {
	BIT_VEC cppVar_31339 = PC + 1;
	cppVar_31339 = (cppVar_31339 & cppMask_un_16_);
	BIT_VEC cppVar_31340 = ROM.rd(cppVar_31339);
	BIT_VEC cppVar_31341 = (cppVar_31340 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31342 = (cppVar_31341 << 3) | 0;
	cppVar_31342 = (cppVar_31342 & cppMask_un_8_);
	cppVar_31334 = cppVar_31342;
	} else {
	BIT_VEC cppVar_31343 = PC + 1;
	cppVar_31343 = (cppVar_31343 & cppMask_un_16_);
	BIT_VEC cppVar_31344 = ROM.rd(cppVar_31343);
	BIT_VEC cppVar_31345 = (cppVar_31344 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31346 = (cppVar_31345 & cppMask_un_5_);
	BIT_VEC cppVar_31347 = cppVar_31346 + 32;
	cppVar_31347 = (cppVar_31347 & cppMask_un_8_);
	cppVar_31334 = cppVar_31347;
	}
	bool cppVar_31349 = (cppVar_31334 == 144);
	if (cppVar_31349) {
	cppVar_31333 = P1;
	} else {
	BIT_VEC cppVar_31350;
	BIT_VEC cppVar_31351;
	BIT_VEC cppVar_31352 = PC + 1;
	cppVar_31352 = (cppVar_31352 & cppMask_un_16_);
	BIT_VEC cppVar_31353 = ROM.rd(cppVar_31352);
	BIT_VEC cppVar_31354 = (cppVar_31353 >> 7) & cppMask_un_1_;
	bool cppVar_31355 = (cppVar_31354 == 1);
	if (cppVar_31355) {
	BIT_VEC cppVar_31356 = PC + 1;
	cppVar_31356 = (cppVar_31356 & cppMask_un_16_);
	BIT_VEC cppVar_31357 = ROM.rd(cppVar_31356);
	BIT_VEC cppVar_31358 = (cppVar_31357 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31359 = (cppVar_31358 << 3) | 0;
	cppVar_31359 = (cppVar_31359 & cppMask_un_8_);
	cppVar_31351 = cppVar_31359;
	} else {
	BIT_VEC cppVar_31360 = PC + 1;
	cppVar_31360 = (cppVar_31360 & cppMask_un_16_);
	BIT_VEC cppVar_31361 = ROM.rd(cppVar_31360);
	BIT_VEC cppVar_31362 = (cppVar_31361 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31363 = (cppVar_31362 & cppMask_un_5_);
	BIT_VEC cppVar_31364 = cppVar_31363 + 32;
	cppVar_31364 = (cppVar_31364 & cppMask_un_8_);
	cppVar_31351 = cppVar_31364;
	}
	bool cppVar_31366 = (cppVar_31351 == 152);
	if (cppVar_31366) {
	cppVar_31350 = SCON;
	} else {
	BIT_VEC cppVar_31367;
	BIT_VEC cppVar_31368;
	BIT_VEC cppVar_31369 = PC + 1;
	cppVar_31369 = (cppVar_31369 & cppMask_un_16_);
	BIT_VEC cppVar_31370 = ROM.rd(cppVar_31369);
	BIT_VEC cppVar_31371 = (cppVar_31370 >> 7) & cppMask_un_1_;
	bool cppVar_31372 = (cppVar_31371 == 1);
	if (cppVar_31372) {
	BIT_VEC cppVar_31373 = PC + 1;
	cppVar_31373 = (cppVar_31373 & cppMask_un_16_);
	BIT_VEC cppVar_31374 = ROM.rd(cppVar_31373);
	BIT_VEC cppVar_31375 = (cppVar_31374 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31376 = (cppVar_31375 << 3) | 0;
	cppVar_31376 = (cppVar_31376 & cppMask_un_8_);
	cppVar_31368 = cppVar_31376;
	} else {
	BIT_VEC cppVar_31377 = PC + 1;
	cppVar_31377 = (cppVar_31377 & cppMask_un_16_);
	BIT_VEC cppVar_31378 = ROM.rd(cppVar_31377);
	BIT_VEC cppVar_31379 = (cppVar_31378 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31380 = (cppVar_31379 & cppMask_un_5_);
	BIT_VEC cppVar_31381 = cppVar_31380 + 32;
	cppVar_31381 = (cppVar_31381 & cppMask_un_8_);
	cppVar_31368 = cppVar_31381;
	}
	bool cppVar_31383 = (cppVar_31368 == 153);
	if (cppVar_31383) {
	cppVar_31367 = SBUF;
	} else {
	BIT_VEC cppVar_31384;
	BIT_VEC cppVar_31385;
	BIT_VEC cppVar_31386 = PC + 1;
	cppVar_31386 = (cppVar_31386 & cppMask_un_16_);
	BIT_VEC cppVar_31387 = ROM.rd(cppVar_31386);
	BIT_VEC cppVar_31388 = (cppVar_31387 >> 7) & cppMask_un_1_;
	bool cppVar_31389 = (cppVar_31388 == 1);
	if (cppVar_31389) {
	BIT_VEC cppVar_31390 = PC + 1;
	cppVar_31390 = (cppVar_31390 & cppMask_un_16_);
	BIT_VEC cppVar_31391 = ROM.rd(cppVar_31390);
	BIT_VEC cppVar_31392 = (cppVar_31391 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31393 = (cppVar_31392 << 3) | 0;
	cppVar_31393 = (cppVar_31393 & cppMask_un_8_);
	cppVar_31385 = cppVar_31393;
	} else {
	BIT_VEC cppVar_31394 = PC + 1;
	cppVar_31394 = (cppVar_31394 & cppMask_un_16_);
	BIT_VEC cppVar_31395 = ROM.rd(cppVar_31394);
	BIT_VEC cppVar_31396 = (cppVar_31395 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31397 = (cppVar_31396 & cppMask_un_5_);
	BIT_VEC cppVar_31398 = cppVar_31397 + 32;
	cppVar_31398 = (cppVar_31398 & cppMask_un_8_);
	cppVar_31385 = cppVar_31398;
	}
	bool cppVar_31400 = (cppVar_31385 == 160);
	if (cppVar_31400) {
	cppVar_31384 = P2;
	} else {
	BIT_VEC cppVar_31401;
	BIT_VEC cppVar_31402;
	BIT_VEC cppVar_31403 = PC + 1;
	cppVar_31403 = (cppVar_31403 & cppMask_un_16_);
	BIT_VEC cppVar_31404 = ROM.rd(cppVar_31403);
	BIT_VEC cppVar_31405 = (cppVar_31404 >> 7) & cppMask_un_1_;
	bool cppVar_31406 = (cppVar_31405 == 1);
	if (cppVar_31406) {
	BIT_VEC cppVar_31407 = PC + 1;
	cppVar_31407 = (cppVar_31407 & cppMask_un_16_);
	BIT_VEC cppVar_31408 = ROM.rd(cppVar_31407);
	BIT_VEC cppVar_31409 = (cppVar_31408 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31410 = (cppVar_31409 << 3) | 0;
	cppVar_31410 = (cppVar_31410 & cppMask_un_8_);
	cppVar_31402 = cppVar_31410;
	} else {
	BIT_VEC cppVar_31411 = PC + 1;
	cppVar_31411 = (cppVar_31411 & cppMask_un_16_);
	BIT_VEC cppVar_31412 = ROM.rd(cppVar_31411);
	BIT_VEC cppVar_31413 = (cppVar_31412 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31414 = (cppVar_31413 & cppMask_un_5_);
	BIT_VEC cppVar_31415 = cppVar_31414 + 32;
	cppVar_31415 = (cppVar_31415 & cppMask_un_8_);
	cppVar_31402 = cppVar_31415;
	}
	bool cppVar_31417 = (cppVar_31402 == 168);
	if (cppVar_31417) {
	cppVar_31401 = IE;
	} else {
	BIT_VEC cppVar_31418;
	BIT_VEC cppVar_31419;
	BIT_VEC cppVar_31420 = PC + 1;
	cppVar_31420 = (cppVar_31420 & cppMask_un_16_);
	BIT_VEC cppVar_31421 = ROM.rd(cppVar_31420);
	BIT_VEC cppVar_31422 = (cppVar_31421 >> 7) & cppMask_un_1_;
	bool cppVar_31423 = (cppVar_31422 == 1);
	if (cppVar_31423) {
	BIT_VEC cppVar_31424 = PC + 1;
	cppVar_31424 = (cppVar_31424 & cppMask_un_16_);
	BIT_VEC cppVar_31425 = ROM.rd(cppVar_31424);
	BIT_VEC cppVar_31426 = (cppVar_31425 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31427 = (cppVar_31426 << 3) | 0;
	cppVar_31427 = (cppVar_31427 & cppMask_un_8_);
	cppVar_31419 = cppVar_31427;
	} else {
	BIT_VEC cppVar_31428 = PC + 1;
	cppVar_31428 = (cppVar_31428 & cppMask_un_16_);
	BIT_VEC cppVar_31429 = ROM.rd(cppVar_31428);
	BIT_VEC cppVar_31430 = (cppVar_31429 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31431 = (cppVar_31430 & cppMask_un_5_);
	BIT_VEC cppVar_31432 = cppVar_31431 + 32;
	cppVar_31432 = (cppVar_31432 & cppMask_un_8_);
	cppVar_31419 = cppVar_31432;
	}
	bool cppVar_31434 = (cppVar_31419 == 176);
	if (cppVar_31434) {
	cppVar_31418 = P3;
	} else {
	BIT_VEC cppVar_31435;
	BIT_VEC cppVar_31436;
	BIT_VEC cppVar_31437 = PC + 1;
	cppVar_31437 = (cppVar_31437 & cppMask_un_16_);
	BIT_VEC cppVar_31438 = ROM.rd(cppVar_31437);
	BIT_VEC cppVar_31439 = (cppVar_31438 >> 7) & cppMask_un_1_;
	bool cppVar_31440 = (cppVar_31439 == 1);
	if (cppVar_31440) {
	BIT_VEC cppVar_31441 = PC + 1;
	cppVar_31441 = (cppVar_31441 & cppMask_un_16_);
	BIT_VEC cppVar_31442 = ROM.rd(cppVar_31441);
	BIT_VEC cppVar_31443 = (cppVar_31442 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31444 = (cppVar_31443 << 3) | 0;
	cppVar_31444 = (cppVar_31444 & cppMask_un_8_);
	cppVar_31436 = cppVar_31444;
	} else {
	BIT_VEC cppVar_31445 = PC + 1;
	cppVar_31445 = (cppVar_31445 & cppMask_un_16_);
	BIT_VEC cppVar_31446 = ROM.rd(cppVar_31445);
	BIT_VEC cppVar_31447 = (cppVar_31446 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31448 = (cppVar_31447 & cppMask_un_5_);
	BIT_VEC cppVar_31449 = cppVar_31448 + 32;
	cppVar_31449 = (cppVar_31449 & cppMask_un_8_);
	cppVar_31436 = cppVar_31449;
	}
	bool cppVar_31451 = (cppVar_31436 == 184);
	if (cppVar_31451) {
	cppVar_31435 = IP;
	} else {
	BIT_VEC cppVar_31452;
	BIT_VEC cppVar_31453;
	BIT_VEC cppVar_31454 = PC + 1;
	cppVar_31454 = (cppVar_31454 & cppMask_un_16_);
	BIT_VEC cppVar_31455 = ROM.rd(cppVar_31454);
	BIT_VEC cppVar_31456 = (cppVar_31455 >> 7) & cppMask_un_1_;
	bool cppVar_31457 = (cppVar_31456 == 1);
	if (cppVar_31457) {
	BIT_VEC cppVar_31458 = PC + 1;
	cppVar_31458 = (cppVar_31458 & cppMask_un_16_);
	BIT_VEC cppVar_31459 = ROM.rd(cppVar_31458);
	BIT_VEC cppVar_31460 = (cppVar_31459 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31461 = (cppVar_31460 << 3) | 0;
	cppVar_31461 = (cppVar_31461 & cppMask_un_8_);
	cppVar_31453 = cppVar_31461;
	} else {
	BIT_VEC cppVar_31462 = PC + 1;
	cppVar_31462 = (cppVar_31462 & cppMask_un_16_);
	BIT_VEC cppVar_31463 = ROM.rd(cppVar_31462);
	BIT_VEC cppVar_31464 = (cppVar_31463 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31465 = (cppVar_31464 & cppMask_un_5_);
	BIT_VEC cppVar_31466 = cppVar_31465 + 32;
	cppVar_31466 = (cppVar_31466 & cppMask_un_8_);
	cppVar_31453 = cppVar_31466;
	}
	bool cppVar_31468 = (cppVar_31453 == 208);
	if (cppVar_31468) {
	cppVar_31452 = PSW;
	} else {
	BIT_VEC cppVar_31469;
	BIT_VEC cppVar_31470;
	BIT_VEC cppVar_31471 = PC + 1;
	cppVar_31471 = (cppVar_31471 & cppMask_un_16_);
	BIT_VEC cppVar_31472 = ROM.rd(cppVar_31471);
	BIT_VEC cppVar_31473 = (cppVar_31472 >> 7) & cppMask_un_1_;
	bool cppVar_31474 = (cppVar_31473 == 1);
	if (cppVar_31474) {
	BIT_VEC cppVar_31475 = PC + 1;
	cppVar_31475 = (cppVar_31475 & cppMask_un_16_);
	BIT_VEC cppVar_31476 = ROM.rd(cppVar_31475);
	BIT_VEC cppVar_31477 = (cppVar_31476 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31478 = (cppVar_31477 << 3) | 0;
	cppVar_31478 = (cppVar_31478 & cppMask_un_8_);
	cppVar_31470 = cppVar_31478;
	} else {
	BIT_VEC cppVar_31479 = PC + 1;
	cppVar_31479 = (cppVar_31479 & cppMask_un_16_);
	BIT_VEC cppVar_31480 = ROM.rd(cppVar_31479);
	BIT_VEC cppVar_31481 = (cppVar_31480 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31482 = (cppVar_31481 & cppMask_un_5_);
	BIT_VEC cppVar_31483 = cppVar_31482 + 32;
	cppVar_31483 = (cppVar_31483 & cppMask_un_8_);
	cppVar_31470 = cppVar_31483;
	}
	bool cppVar_31485 = (cppVar_31470 == 224);
	if (cppVar_31485) {
	cppVar_31469 = ACC;
	} else {
	BIT_VEC cppVar_31486;
	BIT_VEC cppVar_31487;
	BIT_VEC cppVar_31488 = PC + 1;
	cppVar_31488 = (cppVar_31488 & cppMask_un_16_);
	BIT_VEC cppVar_31489 = ROM.rd(cppVar_31488);
	BIT_VEC cppVar_31490 = (cppVar_31489 >> 7) & cppMask_un_1_;
	bool cppVar_31491 = (cppVar_31490 == 1);
	if (cppVar_31491) {
	BIT_VEC cppVar_31492 = PC + 1;
	cppVar_31492 = (cppVar_31492 & cppMask_un_16_);
	BIT_VEC cppVar_31493 = ROM.rd(cppVar_31492);
	BIT_VEC cppVar_31494 = (cppVar_31493 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31495 = (cppVar_31494 << 3) | 0;
	cppVar_31495 = (cppVar_31495 & cppMask_un_8_);
	cppVar_31487 = cppVar_31495;
	} else {
	BIT_VEC cppVar_31496 = PC + 1;
	cppVar_31496 = (cppVar_31496 & cppMask_un_16_);
	BIT_VEC cppVar_31497 = ROM.rd(cppVar_31496);
	BIT_VEC cppVar_31498 = (cppVar_31497 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_31499 = (cppVar_31498 & cppMask_un_5_);
	BIT_VEC cppVar_31500 = cppVar_31499 + 32;
	cppVar_31500 = (cppVar_31500 & cppMask_un_8_);
	cppVar_31487 = cppVar_31500;
	}
	bool cppVar_31502 = (cppVar_31487 == 240);
	if (cppVar_31502) {
	cppVar_31486 = B;
	} else {
	cppVar_31486 = 0;
	}
	cppVar_31469 = cppVar_31486;
	}
	cppVar_31452 = cppVar_31469;
	}
	cppVar_31435 = cppVar_31452;
	}
	cppVar_31418 = cppVar_31435;
	}
	cppVar_31401 = cppVar_31418;
	}
	cppVar_31384 = cppVar_31401;
	}
	cppVar_31367 = cppVar_31384;
	}
	cppVar_31350 = cppVar_31367;
	}
	cppVar_31333 = cppVar_31350;
	}
	cppVar_31316 = cppVar_31333;
	}
	cppVar_31299 = cppVar_31316;
	}
	cppVar_31282 = cppVar_31299;
	}
	cppVar_31265 = cppVar_31282;
	}
	cppVar_31248 = cppVar_31265;
	}
	cppVar_31231 = cppVar_31248;
	}
	cppVar_31214 = cppVar_31231;
	}
	cppVar_31197 = cppVar_31214;
	}
	cppVar_31180 = cppVar_31197;
	}
	cppVar_31163 = cppVar_31180;
	}
	cppVar_31146 = cppVar_31163;
	}
	cppVar_31113 = cppVar_31146;
	}
	BIT_VEC cppVar_31504 = cppVar_31112 & cppVar_31113;
	BIT_VEC cppVar_31506 = 0;
	BIT_VEC cppVar_31507 = PC + 1;
	cppVar_31507 = (cppVar_31507 & cppMask_un_16_);
	BIT_VEC cppVar_31508 = ROM.rd(cppVar_31507);
	BIT_VEC cppVar_31509 = (cppVar_31508 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_31510 = (cppVar_31509 & cppMask_un_3_);
	BIT_VEC cppVar_31511 = cppVar_31506 << static_cast<unsigned>(cppVar_31510);
	cppVar_31511 = (cppVar_31511 & cppMask_un_8_);
	BIT_VEC cppVar_31512 = cppVar_31504 | cppVar_31511;
	cppVar_31085 = cppVar_31512;
	} else {
	cppVar_31085 = P1;
	}
	cppVar_31077 = cppVar_31085;
	} else {
	BIT_VEC cppVar_31513;
	BIT_VEC cppVar_31514 = ROM.rd(PC);
	bool cppVar_31516 = (cppVar_31514 == 5);
	if (cppVar_31516) {
	BIT_VEC cppVar_31517;
	BIT_VEC cppVar_31519 = PC + 1;
	cppVar_31519 = (cppVar_31519 & cppMask_un_16_);
	BIT_VEC cppVar_31520 = ROM.rd(cppVar_31519);
	bool cppVar_31522 = (cppVar_31520 == 144);
	if (cppVar_31522) {
	BIT_VEC cppVar_31523;
	BIT_VEC cppVar_31524 = PC + 1;
	cppVar_31524 = (cppVar_31524 & cppMask_un_16_);
	BIT_VEC cppVar_31525 = ROM.rd(cppVar_31524);
	BIT_VEC cppVar_31526 = (cppVar_31525 >> 7) & cppMask_un_1_;
	bool cppVar_31528 = (cppVar_31526 == 0);
	if (cppVar_31528) {
	BIT_VEC cppVar_31529 = PC + 1;
	cppVar_31529 = (cppVar_31529 & cppMask_un_16_);
	BIT_VEC cppVar_31530 = ROM.rd(cppVar_31529);
	BIT_VEC cppVar_31531 = IRAM.rd(cppVar_31530);
	cppVar_31523 = cppVar_31531;
	} else {
	BIT_VEC cppVar_31532;
	BIT_VEC cppVar_31533 = PC + 1;
	cppVar_31533 = (cppVar_31533 & cppMask_un_16_);
	BIT_VEC cppVar_31534 = ROM.rd(cppVar_31533);
	bool cppVar_31536 = (cppVar_31534 == 128);
	if (cppVar_31536) {
	cppVar_31532 = P0;
	} else {
	BIT_VEC cppVar_31537;
	BIT_VEC cppVar_31538 = PC + 1;
	cppVar_31538 = (cppVar_31538 & cppMask_un_16_);
	BIT_VEC cppVar_31539 = ROM.rd(cppVar_31538);
	bool cppVar_31541 = (cppVar_31539 == 129);
	if (cppVar_31541) {
	cppVar_31537 = SP;
	} else {
	BIT_VEC cppVar_31542;
	BIT_VEC cppVar_31543 = PC + 1;
	cppVar_31543 = (cppVar_31543 & cppMask_un_16_);
	BIT_VEC cppVar_31544 = ROM.rd(cppVar_31543);
	bool cppVar_31546 = (cppVar_31544 == 130);
	if (cppVar_31546) {
	cppVar_31542 = DPL;
	} else {
	BIT_VEC cppVar_31547;
	BIT_VEC cppVar_31548 = PC + 1;
	cppVar_31548 = (cppVar_31548 & cppMask_un_16_);
	BIT_VEC cppVar_31549 = ROM.rd(cppVar_31548);
	bool cppVar_31551 = (cppVar_31549 == 131);
	if (cppVar_31551) {
	cppVar_31547 = DPH;
	} else {
	BIT_VEC cppVar_31552;
	BIT_VEC cppVar_31553 = PC + 1;
	cppVar_31553 = (cppVar_31553 & cppMask_un_16_);
	BIT_VEC cppVar_31554 = ROM.rd(cppVar_31553);
	bool cppVar_31556 = (cppVar_31554 == 135);
	if (cppVar_31556) {
	cppVar_31552 = PCON;
	} else {
	BIT_VEC cppVar_31557;
	BIT_VEC cppVar_31558 = PC + 1;
	cppVar_31558 = (cppVar_31558 & cppMask_un_16_);
	BIT_VEC cppVar_31559 = ROM.rd(cppVar_31558);
	bool cppVar_31561 = (cppVar_31559 == 136);
	if (cppVar_31561) {
	cppVar_31557 = TCON;
	} else {
	BIT_VEC cppVar_31562;
	BIT_VEC cppVar_31563 = PC + 1;
	cppVar_31563 = (cppVar_31563 & cppMask_un_16_);
	BIT_VEC cppVar_31564 = ROM.rd(cppVar_31563);
	bool cppVar_31566 = (cppVar_31564 == 137);
	if (cppVar_31566) {
	cppVar_31562 = TMOD;
	} else {
	BIT_VEC cppVar_31567;
	BIT_VEC cppVar_31568 = PC + 1;
	cppVar_31568 = (cppVar_31568 & cppMask_un_16_);
	BIT_VEC cppVar_31569 = ROM.rd(cppVar_31568);
	bool cppVar_31571 = (cppVar_31569 == 138);
	if (cppVar_31571) {
	cppVar_31567 = TL0;
	} else {
	BIT_VEC cppVar_31572;
	BIT_VEC cppVar_31573 = PC + 1;
	cppVar_31573 = (cppVar_31573 & cppMask_un_16_);
	BIT_VEC cppVar_31574 = ROM.rd(cppVar_31573);
	bool cppVar_31576 = (cppVar_31574 == 140);
	if (cppVar_31576) {
	cppVar_31572 = TH0;
	} else {
	BIT_VEC cppVar_31577;
	BIT_VEC cppVar_31578 = PC + 1;
	cppVar_31578 = (cppVar_31578 & cppMask_un_16_);
	BIT_VEC cppVar_31579 = ROM.rd(cppVar_31578);
	bool cppVar_31581 = (cppVar_31579 == 139);
	if (cppVar_31581) {
	cppVar_31577 = TL1;
	} else {
	BIT_VEC cppVar_31582;
	BIT_VEC cppVar_31583 = PC + 1;
	cppVar_31583 = (cppVar_31583 & cppMask_un_16_);
	BIT_VEC cppVar_31584 = ROM.rd(cppVar_31583);
	bool cppVar_31586 = (cppVar_31584 == 141);
	if (cppVar_31586) {
	cppVar_31582 = TH1;
	} else {
	BIT_VEC cppVar_31587;
	BIT_VEC cppVar_31588 = PC + 1;
	cppVar_31588 = (cppVar_31588 & cppMask_un_16_);
	BIT_VEC cppVar_31589 = ROM.rd(cppVar_31588);
	bool cppVar_31591 = (cppVar_31589 == 144);
	if (cppVar_31591) {
	cppVar_31587 = P1;
	} else {
	BIT_VEC cppVar_31592;
	BIT_VEC cppVar_31593 = PC + 1;
	cppVar_31593 = (cppVar_31593 & cppMask_un_16_);
	BIT_VEC cppVar_31594 = ROM.rd(cppVar_31593);
	bool cppVar_31596 = (cppVar_31594 == 152);
	if (cppVar_31596) {
	cppVar_31592 = SCON;
	} else {
	BIT_VEC cppVar_31597;
	BIT_VEC cppVar_31598 = PC + 1;
	cppVar_31598 = (cppVar_31598 & cppMask_un_16_);
	BIT_VEC cppVar_31599 = ROM.rd(cppVar_31598);
	bool cppVar_31601 = (cppVar_31599 == 153);
	if (cppVar_31601) {
	cppVar_31597 = SBUF;
	} else {
	BIT_VEC cppVar_31602;
	BIT_VEC cppVar_31603 = PC + 1;
	cppVar_31603 = (cppVar_31603 & cppMask_un_16_);
	BIT_VEC cppVar_31604 = ROM.rd(cppVar_31603);
	bool cppVar_31606 = (cppVar_31604 == 160);
	if (cppVar_31606) {
	cppVar_31602 = P2;
	} else {
	BIT_VEC cppVar_31607;
	BIT_VEC cppVar_31608 = PC + 1;
	cppVar_31608 = (cppVar_31608 & cppMask_un_16_);
	BIT_VEC cppVar_31609 = ROM.rd(cppVar_31608);
	bool cppVar_31611 = (cppVar_31609 == 168);
	if (cppVar_31611) {
	cppVar_31607 = IE;
	} else {
	BIT_VEC cppVar_31612;
	BIT_VEC cppVar_31613 = PC + 1;
	cppVar_31613 = (cppVar_31613 & cppMask_un_16_);
	BIT_VEC cppVar_31614 = ROM.rd(cppVar_31613);
	bool cppVar_31616 = (cppVar_31614 == 176);
	if (cppVar_31616) {
	cppVar_31612 = P3;
	} else {
	BIT_VEC cppVar_31617;
	BIT_VEC cppVar_31618 = PC + 1;
	cppVar_31618 = (cppVar_31618 & cppMask_un_16_);
	BIT_VEC cppVar_31619 = ROM.rd(cppVar_31618);
	bool cppVar_31621 = (cppVar_31619 == 184);
	if (cppVar_31621) {
	cppVar_31617 = IP;
	} else {
	BIT_VEC cppVar_31622;
	BIT_VEC cppVar_31623 = PC + 1;
	cppVar_31623 = (cppVar_31623 & cppMask_un_16_);
	BIT_VEC cppVar_31624 = ROM.rd(cppVar_31623);
	bool cppVar_31626 = (cppVar_31624 == 208);
	if (cppVar_31626) {
	cppVar_31622 = PSW;
	} else {
	BIT_VEC cppVar_31627;
	BIT_VEC cppVar_31628 = PC + 1;
	cppVar_31628 = (cppVar_31628 & cppMask_un_16_);
	BIT_VEC cppVar_31629 = ROM.rd(cppVar_31628);
	bool cppVar_31631 = (cppVar_31629 == 224);
	if (cppVar_31631) {
	cppVar_31627 = ACC;
	} else {
	BIT_VEC cppVar_31632;
	BIT_VEC cppVar_31633 = PC + 1;
	cppVar_31633 = (cppVar_31633 & cppMask_un_16_);
	BIT_VEC cppVar_31634 = ROM.rd(cppVar_31633);
	bool cppVar_31636 = (cppVar_31634 == 240);
	if (cppVar_31636) {
	cppVar_31632 = B;
	} else {
	cppVar_31632 = 0;
	}
	cppVar_31627 = cppVar_31632;
	}
	cppVar_31622 = cppVar_31627;
	}
	cppVar_31617 = cppVar_31622;
	}
	cppVar_31612 = cppVar_31617;
	}
	cppVar_31607 = cppVar_31612;
	}
	cppVar_31602 = cppVar_31607;
	}
	cppVar_31597 = cppVar_31602;
	}
	cppVar_31592 = cppVar_31597;
	}
	cppVar_31587 = cppVar_31592;
	}
	cppVar_31582 = cppVar_31587;
	}
	cppVar_31577 = cppVar_31582;
	}
	cppVar_31572 = cppVar_31577;
	}
	cppVar_31567 = cppVar_31572;
	}
	cppVar_31562 = cppVar_31567;
	}
	cppVar_31557 = cppVar_31562;
	}
	cppVar_31552 = cppVar_31557;
	}
	cppVar_31547 = cppVar_31552;
	}
	cppVar_31542 = cppVar_31547;
	}
	cppVar_31537 = cppVar_31542;
	}
	cppVar_31532 = cppVar_31537;
	}
	cppVar_31523 = cppVar_31532;
	}
	BIT_VEC cppVar_31639 = cppVar_31523 + 1;
	cppVar_31639 = (cppVar_31639 & cppMask_un_8_);
	cppVar_31517 = cppVar_31639;
	} else {
	cppVar_31517 = P1;
	}
	cppVar_31513 = cppVar_31517;
	} else {
	cppVar_31513 = P1;
	}
	cppVar_31077 = cppVar_31513;
	}
	cppVar_30946 = cppVar_31077;
	}
	cppVar_30820 = cppVar_30946;
	}
	cppVar_30691 = cppVar_30820;
	}
	cppVar_30565 = cppVar_30691;
	}
	cppVar_30436 = cppVar_30565;
	}
	cppVar_30310 = cppVar_30436;
	}
	cppVar_30181 = cppVar_30310;
	}
	cppVar_30168 = cppVar_30181;
	}
	cppVar_30042 = cppVar_30168;
	}
	cppVar_30025 = cppVar_30042;
	}
	cppVar_30008 = cppVar_30025;
	}
	cppVar_29858 = cppVar_30008;
	}
	cppVar_29708 = cppVar_29858;
	}
	cppVar_29558 = cppVar_29708;
	}
	cppVar_29408 = cppVar_29558;
	}
	cppVar_29258 = cppVar_29408;
	}
	cppVar_29108 = cppVar_29258;
	}
	cppVar_28958 = cppVar_29108;
	}
	cppVar_28808 = cppVar_28958;
	}
	cppVar_28376 = cppVar_28808;
	}
	cppVar_27546 = cppVar_28376;
	}
	cppVar_27532 = cppVar_27546;
	}
	cppVar_27521 = cppVar_27532;
	}
	cppVar_27089 = cppVar_27521;
	}
	return cppVar_27089;
}
