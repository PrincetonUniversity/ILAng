#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_TMOD()
{
	BIT_VEC cppVar_82114;
	BIT_VEC cppVar_82115 = ROM.rd(PC);
	bool cppVar_82117 = (cppVar_82115 == 208);
	if (cppVar_82117) {
	BIT_VEC cppVar_82118;
	BIT_VEC cppVar_82120 = PC + 1;
	cppVar_82120 = (cppVar_82120 & cppMask_un_16_);
	BIT_VEC cppVar_82121 = ROM.rd(cppVar_82120);
	bool cppVar_82123 = (cppVar_82121 == 137);
	if (cppVar_82123) {
	BIT_VEC cppVar_82124 = IRAM.rd(SP);
	cppVar_82118 = cppVar_82124;
	} else {
	cppVar_82118 = TMOD;
	}
	cppVar_82114 = cppVar_82118;
	} else {
	BIT_VEC cppVar_82125;
	BIT_VEC cppVar_82126 = ROM.rd(PC);
	bool cppVar_82128 = (cppVar_82126 == 245);
	BIT_VEC cppVar_82129 = ROM.rd(PC);
	bool cppVar_82131 = (cppVar_82129 == 197);
	bool cppVar_82132 = cppVar_82128 || cppVar_82131;
	if (cppVar_82132) {
	BIT_VEC cppVar_82133;
	BIT_VEC cppVar_82135 = PC + 1;
	cppVar_82135 = (cppVar_82135 & cppMask_un_16_);
	BIT_VEC cppVar_82136 = ROM.rd(cppVar_82135);
	bool cppVar_82138 = (cppVar_82136 == 137);
	if (cppVar_82138) {
	cppVar_82133 = ACC;
	} else {
	cppVar_82133 = TMOD;
	}
	cppVar_82125 = cppVar_82133;
	} else {
	BIT_VEC cppVar_82139;
	BIT_VEC cppVar_82140 = ROM.rd(PC);
	bool cppVar_82142 = (cppVar_82140 == 143);
	if (cppVar_82142) {
	BIT_VEC cppVar_82143;
	BIT_VEC cppVar_82145 = PC + 1;
	cppVar_82145 = (cppVar_82145 & cppMask_un_16_);
	BIT_VEC cppVar_82146 = ROM.rd(cppVar_82145);
	bool cppVar_82148 = (cppVar_82146 == 137);
	if (cppVar_82148) {
	BIT_VEC cppVar_82149;
	BIT_VEC cppVar_82151 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82153 = (cppVar_82151 << 3) | 7;
	cppVar_82153 = (cppVar_82153 & cppMask_un_5_);
	BIT_VEC cppVar_82154 = (0 << 5) | cppVar_82153;
	cppVar_82154 = (cppVar_82154 & cppMask_un_8_);
	BIT_VEC cppVar_82155 = (cppVar_82154 >> 7) & cppMask_un_1_;
	bool cppVar_82157 = (cppVar_82155 == 0);
	if (cppVar_82157) {
	BIT_VEC cppVar_82158 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82159 = (cppVar_82158 << 3) | 7;
	cppVar_82159 = (cppVar_82159 & cppMask_un_5_);
	BIT_VEC cppVar_82160 = (0 << 5) | cppVar_82159;
	cppVar_82160 = (cppVar_82160 & cppMask_un_8_);
	BIT_VEC cppVar_82161 = IRAM.rd(cppVar_82160);
	cppVar_82149 = cppVar_82161;
	} else {
	BIT_VEC cppVar_82162;
	BIT_VEC cppVar_82163 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82164 = (cppVar_82163 << 3) | 7;
	cppVar_82164 = (cppVar_82164 & cppMask_un_5_);
	BIT_VEC cppVar_82165 = (0 << 5) | cppVar_82164;
	cppVar_82165 = (cppVar_82165 & cppMask_un_8_);
	bool cppVar_82167 = (cppVar_82165 == 128);
	if (cppVar_82167) {
	cppVar_82162 = P0;
	} else {
	BIT_VEC cppVar_82168;
	BIT_VEC cppVar_82169 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82170 = (cppVar_82169 << 3) | 7;
	cppVar_82170 = (cppVar_82170 & cppMask_un_5_);
	BIT_VEC cppVar_82171 = (0 << 5) | cppVar_82170;
	cppVar_82171 = (cppVar_82171 & cppMask_un_8_);
	bool cppVar_82173 = (cppVar_82171 == 129);
	if (cppVar_82173) {
	cppVar_82168 = SP;
	} else {
	BIT_VEC cppVar_82174;
	BIT_VEC cppVar_82175 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82176 = (cppVar_82175 << 3) | 7;
	cppVar_82176 = (cppVar_82176 & cppMask_un_5_);
	BIT_VEC cppVar_82177 = (0 << 5) | cppVar_82176;
	cppVar_82177 = (cppVar_82177 & cppMask_un_8_);
	bool cppVar_82179 = (cppVar_82177 == 130);
	if (cppVar_82179) {
	cppVar_82174 = DPL;
	} else {
	BIT_VEC cppVar_82180;
	BIT_VEC cppVar_82181 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82182 = (cppVar_82181 << 3) | 7;
	cppVar_82182 = (cppVar_82182 & cppMask_un_5_);
	BIT_VEC cppVar_82183 = (0 << 5) | cppVar_82182;
	cppVar_82183 = (cppVar_82183 & cppMask_un_8_);
	bool cppVar_82185 = (cppVar_82183 == 131);
	if (cppVar_82185) {
	cppVar_82180 = DPH;
	} else {
	BIT_VEC cppVar_82186;
	BIT_VEC cppVar_82187 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82188 = (cppVar_82187 << 3) | 7;
	cppVar_82188 = (cppVar_82188 & cppMask_un_5_);
	BIT_VEC cppVar_82189 = (0 << 5) | cppVar_82188;
	cppVar_82189 = (cppVar_82189 & cppMask_un_8_);
	bool cppVar_82191 = (cppVar_82189 == 135);
	if (cppVar_82191) {
	cppVar_82186 = PCON;
	} else {
	BIT_VEC cppVar_82192;
	BIT_VEC cppVar_82193 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82194 = (cppVar_82193 << 3) | 7;
	cppVar_82194 = (cppVar_82194 & cppMask_un_5_);
	BIT_VEC cppVar_82195 = (0 << 5) | cppVar_82194;
	cppVar_82195 = (cppVar_82195 & cppMask_un_8_);
	bool cppVar_82197 = (cppVar_82195 == 136);
	if (cppVar_82197) {
	cppVar_82192 = TCON;
	} else {
	BIT_VEC cppVar_82198;
	BIT_VEC cppVar_82199 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82200 = (cppVar_82199 << 3) | 7;
	cppVar_82200 = (cppVar_82200 & cppMask_un_5_);
	BIT_VEC cppVar_82201 = (0 << 5) | cppVar_82200;
	cppVar_82201 = (cppVar_82201 & cppMask_un_8_);
	bool cppVar_82203 = (cppVar_82201 == 137);
	if (cppVar_82203) {
	cppVar_82198 = TMOD;
	} else {
	BIT_VEC cppVar_82204;
	BIT_VEC cppVar_82205 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82206 = (cppVar_82205 << 3) | 7;
	cppVar_82206 = (cppVar_82206 & cppMask_un_5_);
	BIT_VEC cppVar_82207 = (0 << 5) | cppVar_82206;
	cppVar_82207 = (cppVar_82207 & cppMask_un_8_);
	bool cppVar_82209 = (cppVar_82207 == 138);
	if (cppVar_82209) {
	cppVar_82204 = TL0;
	} else {
	BIT_VEC cppVar_82210;
	BIT_VEC cppVar_82211 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82212 = (cppVar_82211 << 3) | 7;
	cppVar_82212 = (cppVar_82212 & cppMask_un_5_);
	BIT_VEC cppVar_82213 = (0 << 5) | cppVar_82212;
	cppVar_82213 = (cppVar_82213 & cppMask_un_8_);
	bool cppVar_82215 = (cppVar_82213 == 140);
	if (cppVar_82215) {
	cppVar_82210 = TH0;
	} else {
	BIT_VEC cppVar_82216;
	BIT_VEC cppVar_82217 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82218 = (cppVar_82217 << 3) | 7;
	cppVar_82218 = (cppVar_82218 & cppMask_un_5_);
	BIT_VEC cppVar_82219 = (0 << 5) | cppVar_82218;
	cppVar_82219 = (cppVar_82219 & cppMask_un_8_);
	bool cppVar_82221 = (cppVar_82219 == 139);
	if (cppVar_82221) {
	cppVar_82216 = TL1;
	} else {
	BIT_VEC cppVar_82222;
	BIT_VEC cppVar_82223 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82224 = (cppVar_82223 << 3) | 7;
	cppVar_82224 = (cppVar_82224 & cppMask_un_5_);
	BIT_VEC cppVar_82225 = (0 << 5) | cppVar_82224;
	cppVar_82225 = (cppVar_82225 & cppMask_un_8_);
	bool cppVar_82227 = (cppVar_82225 == 141);
	if (cppVar_82227) {
	cppVar_82222 = TH1;
	} else {
	BIT_VEC cppVar_82228;
	BIT_VEC cppVar_82229 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82230 = (cppVar_82229 << 3) | 7;
	cppVar_82230 = (cppVar_82230 & cppMask_un_5_);
	BIT_VEC cppVar_82231 = (0 << 5) | cppVar_82230;
	cppVar_82231 = (cppVar_82231 & cppMask_un_8_);
	bool cppVar_82233 = (cppVar_82231 == 144);
	if (cppVar_82233) {
	cppVar_82228 = P1;
	} else {
	BIT_VEC cppVar_82234;
	BIT_VEC cppVar_82235 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82236 = (cppVar_82235 << 3) | 7;
	cppVar_82236 = (cppVar_82236 & cppMask_un_5_);
	BIT_VEC cppVar_82237 = (0 << 5) | cppVar_82236;
	cppVar_82237 = (cppVar_82237 & cppMask_un_8_);
	bool cppVar_82239 = (cppVar_82237 == 152);
	if (cppVar_82239) {
	cppVar_82234 = SCON;
	} else {
	BIT_VEC cppVar_82240;
	BIT_VEC cppVar_82241 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82242 = (cppVar_82241 << 3) | 7;
	cppVar_82242 = (cppVar_82242 & cppMask_un_5_);
	BIT_VEC cppVar_82243 = (0 << 5) | cppVar_82242;
	cppVar_82243 = (cppVar_82243 & cppMask_un_8_);
	bool cppVar_82245 = (cppVar_82243 == 153);
	if (cppVar_82245) {
	cppVar_82240 = SBUF;
	} else {
	BIT_VEC cppVar_82246;
	BIT_VEC cppVar_82247 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82248 = (cppVar_82247 << 3) | 7;
	cppVar_82248 = (cppVar_82248 & cppMask_un_5_);
	BIT_VEC cppVar_82249 = (0 << 5) | cppVar_82248;
	cppVar_82249 = (cppVar_82249 & cppMask_un_8_);
	bool cppVar_82251 = (cppVar_82249 == 160);
	if (cppVar_82251) {
	cppVar_82246 = P2;
	} else {
	BIT_VEC cppVar_82252;
	BIT_VEC cppVar_82253 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82254 = (cppVar_82253 << 3) | 7;
	cppVar_82254 = (cppVar_82254 & cppMask_un_5_);
	BIT_VEC cppVar_82255 = (0 << 5) | cppVar_82254;
	cppVar_82255 = (cppVar_82255 & cppMask_un_8_);
	bool cppVar_82257 = (cppVar_82255 == 168);
	if (cppVar_82257) {
	cppVar_82252 = IE;
	} else {
	BIT_VEC cppVar_82258;
	BIT_VEC cppVar_82259 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82260 = (cppVar_82259 << 3) | 7;
	cppVar_82260 = (cppVar_82260 & cppMask_un_5_);
	BIT_VEC cppVar_82261 = (0 << 5) | cppVar_82260;
	cppVar_82261 = (cppVar_82261 & cppMask_un_8_);
	bool cppVar_82263 = (cppVar_82261 == 176);
	if (cppVar_82263) {
	cppVar_82258 = P3;
	} else {
	BIT_VEC cppVar_82264;
	BIT_VEC cppVar_82265 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82266 = (cppVar_82265 << 3) | 7;
	cppVar_82266 = (cppVar_82266 & cppMask_un_5_);
	BIT_VEC cppVar_82267 = (0 << 5) | cppVar_82266;
	cppVar_82267 = (cppVar_82267 & cppMask_un_8_);
	bool cppVar_82269 = (cppVar_82267 == 184);
	if (cppVar_82269) {
	cppVar_82264 = IP;
	} else {
	BIT_VEC cppVar_82270;
	BIT_VEC cppVar_82271 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82272 = (cppVar_82271 << 3) | 7;
	cppVar_82272 = (cppVar_82272 & cppMask_un_5_);
	BIT_VEC cppVar_82273 = (0 << 5) | cppVar_82272;
	cppVar_82273 = (cppVar_82273 & cppMask_un_8_);
	bool cppVar_82275 = (cppVar_82273 == 208);
	if (cppVar_82275) {
	cppVar_82270 = PSW;
	} else {
	BIT_VEC cppVar_82276;
	BIT_VEC cppVar_82277 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82278 = (cppVar_82277 << 3) | 7;
	cppVar_82278 = (cppVar_82278 & cppMask_un_5_);
	BIT_VEC cppVar_82279 = (0 << 5) | cppVar_82278;
	cppVar_82279 = (cppVar_82279 & cppMask_un_8_);
	bool cppVar_82281 = (cppVar_82279 == 224);
	if (cppVar_82281) {
	cppVar_82276 = ACC;
	} else {
	BIT_VEC cppVar_82282;
	BIT_VEC cppVar_82283 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82284 = (cppVar_82283 << 3) | 7;
	cppVar_82284 = (cppVar_82284 & cppMask_un_5_);
	BIT_VEC cppVar_82285 = (0 << 5) | cppVar_82284;
	cppVar_82285 = (cppVar_82285 & cppMask_un_8_);
	bool cppVar_82287 = (cppVar_82285 == 240);
	if (cppVar_82287) {
	cppVar_82282 = B;
	} else {
	cppVar_82282 = 0;
	}
	cppVar_82276 = cppVar_82282;
	}
	cppVar_82270 = cppVar_82276;
	}
	cppVar_82264 = cppVar_82270;
	}
	cppVar_82258 = cppVar_82264;
	}
	cppVar_82252 = cppVar_82258;
	}
	cppVar_82246 = cppVar_82252;
	}
	cppVar_82240 = cppVar_82246;
	}
	cppVar_82234 = cppVar_82240;
	}
	cppVar_82228 = cppVar_82234;
	}
	cppVar_82222 = cppVar_82228;
	}
	cppVar_82216 = cppVar_82222;
	}
	cppVar_82210 = cppVar_82216;
	}
	cppVar_82204 = cppVar_82210;
	}
	cppVar_82198 = cppVar_82204;
	}
	cppVar_82192 = cppVar_82198;
	}
	cppVar_82186 = cppVar_82192;
	}
	cppVar_82180 = cppVar_82186;
	}
	cppVar_82174 = cppVar_82180;
	}
	cppVar_82168 = cppVar_82174;
	}
	cppVar_82162 = cppVar_82168;
	}
	cppVar_82149 = cppVar_82162;
	}
	cppVar_82143 = cppVar_82149;
	} else {
	cppVar_82143 = TMOD;
	}
	cppVar_82139 = cppVar_82143;
	} else {
	BIT_VEC cppVar_82289;
	BIT_VEC cppVar_82290 = ROM.rd(PC);
	bool cppVar_82292 = (cppVar_82290 == 142);
	if (cppVar_82292) {
	BIT_VEC cppVar_82293;
	BIT_VEC cppVar_82295 = PC + 1;
	cppVar_82295 = (cppVar_82295 & cppMask_un_16_);
	BIT_VEC cppVar_82296 = ROM.rd(cppVar_82295);
	bool cppVar_82298 = (cppVar_82296 == 137);
	if (cppVar_82298) {
	BIT_VEC cppVar_82299;
	BIT_VEC cppVar_82301 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82303 = (cppVar_82301 << 3) | 6;
	cppVar_82303 = (cppVar_82303 & cppMask_un_5_);
	BIT_VEC cppVar_82304 = (0 << 5) | cppVar_82303;
	cppVar_82304 = (cppVar_82304 & cppMask_un_8_);
	BIT_VEC cppVar_82305 = (cppVar_82304 >> 7) & cppMask_un_1_;
	bool cppVar_82307 = (cppVar_82305 == 0);
	if (cppVar_82307) {
	BIT_VEC cppVar_82308 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82309 = (cppVar_82308 << 3) | 6;
	cppVar_82309 = (cppVar_82309 & cppMask_un_5_);
	BIT_VEC cppVar_82310 = (0 << 5) | cppVar_82309;
	cppVar_82310 = (cppVar_82310 & cppMask_un_8_);
	BIT_VEC cppVar_82311 = IRAM.rd(cppVar_82310);
	cppVar_82299 = cppVar_82311;
	} else {
	BIT_VEC cppVar_82312;
	BIT_VEC cppVar_82313 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82314 = (cppVar_82313 << 3) | 6;
	cppVar_82314 = (cppVar_82314 & cppMask_un_5_);
	BIT_VEC cppVar_82315 = (0 << 5) | cppVar_82314;
	cppVar_82315 = (cppVar_82315 & cppMask_un_8_);
	bool cppVar_82317 = (cppVar_82315 == 128);
	if (cppVar_82317) {
	cppVar_82312 = P0;
	} else {
	BIT_VEC cppVar_82318;
	BIT_VEC cppVar_82319 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82320 = (cppVar_82319 << 3) | 6;
	cppVar_82320 = (cppVar_82320 & cppMask_un_5_);
	BIT_VEC cppVar_82321 = (0 << 5) | cppVar_82320;
	cppVar_82321 = (cppVar_82321 & cppMask_un_8_);
	bool cppVar_82323 = (cppVar_82321 == 129);
	if (cppVar_82323) {
	cppVar_82318 = SP;
	} else {
	BIT_VEC cppVar_82324;
	BIT_VEC cppVar_82325 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82326 = (cppVar_82325 << 3) | 6;
	cppVar_82326 = (cppVar_82326 & cppMask_un_5_);
	BIT_VEC cppVar_82327 = (0 << 5) | cppVar_82326;
	cppVar_82327 = (cppVar_82327 & cppMask_un_8_);
	bool cppVar_82329 = (cppVar_82327 == 130);
	if (cppVar_82329) {
	cppVar_82324 = DPL;
	} else {
	BIT_VEC cppVar_82330;
	BIT_VEC cppVar_82331 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82332 = (cppVar_82331 << 3) | 6;
	cppVar_82332 = (cppVar_82332 & cppMask_un_5_);
	BIT_VEC cppVar_82333 = (0 << 5) | cppVar_82332;
	cppVar_82333 = (cppVar_82333 & cppMask_un_8_);
	bool cppVar_82335 = (cppVar_82333 == 131);
	if (cppVar_82335) {
	cppVar_82330 = DPH;
	} else {
	BIT_VEC cppVar_82336;
	BIT_VEC cppVar_82337 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82338 = (cppVar_82337 << 3) | 6;
	cppVar_82338 = (cppVar_82338 & cppMask_un_5_);
	BIT_VEC cppVar_82339 = (0 << 5) | cppVar_82338;
	cppVar_82339 = (cppVar_82339 & cppMask_un_8_);
	bool cppVar_82341 = (cppVar_82339 == 135);
	if (cppVar_82341) {
	cppVar_82336 = PCON;
	} else {
	BIT_VEC cppVar_82342;
	BIT_VEC cppVar_82343 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82344 = (cppVar_82343 << 3) | 6;
	cppVar_82344 = (cppVar_82344 & cppMask_un_5_);
	BIT_VEC cppVar_82345 = (0 << 5) | cppVar_82344;
	cppVar_82345 = (cppVar_82345 & cppMask_un_8_);
	bool cppVar_82347 = (cppVar_82345 == 136);
	if (cppVar_82347) {
	cppVar_82342 = TCON;
	} else {
	BIT_VEC cppVar_82348;
	BIT_VEC cppVar_82349 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82350 = (cppVar_82349 << 3) | 6;
	cppVar_82350 = (cppVar_82350 & cppMask_un_5_);
	BIT_VEC cppVar_82351 = (0 << 5) | cppVar_82350;
	cppVar_82351 = (cppVar_82351 & cppMask_un_8_);
	bool cppVar_82353 = (cppVar_82351 == 137);
	if (cppVar_82353) {
	cppVar_82348 = TMOD;
	} else {
	BIT_VEC cppVar_82354;
	BIT_VEC cppVar_82355 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82356 = (cppVar_82355 << 3) | 6;
	cppVar_82356 = (cppVar_82356 & cppMask_un_5_);
	BIT_VEC cppVar_82357 = (0 << 5) | cppVar_82356;
	cppVar_82357 = (cppVar_82357 & cppMask_un_8_);
	bool cppVar_82359 = (cppVar_82357 == 138);
	if (cppVar_82359) {
	cppVar_82354 = TL0;
	} else {
	BIT_VEC cppVar_82360;
	BIT_VEC cppVar_82361 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82362 = (cppVar_82361 << 3) | 6;
	cppVar_82362 = (cppVar_82362 & cppMask_un_5_);
	BIT_VEC cppVar_82363 = (0 << 5) | cppVar_82362;
	cppVar_82363 = (cppVar_82363 & cppMask_un_8_);
	bool cppVar_82365 = (cppVar_82363 == 140);
	if (cppVar_82365) {
	cppVar_82360 = TH0;
	} else {
	BIT_VEC cppVar_82366;
	BIT_VEC cppVar_82367 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82368 = (cppVar_82367 << 3) | 6;
	cppVar_82368 = (cppVar_82368 & cppMask_un_5_);
	BIT_VEC cppVar_82369 = (0 << 5) | cppVar_82368;
	cppVar_82369 = (cppVar_82369 & cppMask_un_8_);
	bool cppVar_82371 = (cppVar_82369 == 139);
	if (cppVar_82371) {
	cppVar_82366 = TL1;
	} else {
	BIT_VEC cppVar_82372;
	BIT_VEC cppVar_82373 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82374 = (cppVar_82373 << 3) | 6;
	cppVar_82374 = (cppVar_82374 & cppMask_un_5_);
	BIT_VEC cppVar_82375 = (0 << 5) | cppVar_82374;
	cppVar_82375 = (cppVar_82375 & cppMask_un_8_);
	bool cppVar_82377 = (cppVar_82375 == 141);
	if (cppVar_82377) {
	cppVar_82372 = TH1;
	} else {
	BIT_VEC cppVar_82378;
	BIT_VEC cppVar_82379 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82380 = (cppVar_82379 << 3) | 6;
	cppVar_82380 = (cppVar_82380 & cppMask_un_5_);
	BIT_VEC cppVar_82381 = (0 << 5) | cppVar_82380;
	cppVar_82381 = (cppVar_82381 & cppMask_un_8_);
	bool cppVar_82383 = (cppVar_82381 == 144);
	if (cppVar_82383) {
	cppVar_82378 = P1;
	} else {
	BIT_VEC cppVar_82384;
	BIT_VEC cppVar_82385 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82386 = (cppVar_82385 << 3) | 6;
	cppVar_82386 = (cppVar_82386 & cppMask_un_5_);
	BIT_VEC cppVar_82387 = (0 << 5) | cppVar_82386;
	cppVar_82387 = (cppVar_82387 & cppMask_un_8_);
	bool cppVar_82389 = (cppVar_82387 == 152);
	if (cppVar_82389) {
	cppVar_82384 = SCON;
	} else {
	BIT_VEC cppVar_82390;
	BIT_VEC cppVar_82391 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82392 = (cppVar_82391 << 3) | 6;
	cppVar_82392 = (cppVar_82392 & cppMask_un_5_);
	BIT_VEC cppVar_82393 = (0 << 5) | cppVar_82392;
	cppVar_82393 = (cppVar_82393 & cppMask_un_8_);
	bool cppVar_82395 = (cppVar_82393 == 153);
	if (cppVar_82395) {
	cppVar_82390 = SBUF;
	} else {
	BIT_VEC cppVar_82396;
	BIT_VEC cppVar_82397 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82398 = (cppVar_82397 << 3) | 6;
	cppVar_82398 = (cppVar_82398 & cppMask_un_5_);
	BIT_VEC cppVar_82399 = (0 << 5) | cppVar_82398;
	cppVar_82399 = (cppVar_82399 & cppMask_un_8_);
	bool cppVar_82401 = (cppVar_82399 == 160);
	if (cppVar_82401) {
	cppVar_82396 = P2;
	} else {
	BIT_VEC cppVar_82402;
	BIT_VEC cppVar_82403 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82404 = (cppVar_82403 << 3) | 6;
	cppVar_82404 = (cppVar_82404 & cppMask_un_5_);
	BIT_VEC cppVar_82405 = (0 << 5) | cppVar_82404;
	cppVar_82405 = (cppVar_82405 & cppMask_un_8_);
	bool cppVar_82407 = (cppVar_82405 == 168);
	if (cppVar_82407) {
	cppVar_82402 = IE;
	} else {
	BIT_VEC cppVar_82408;
	BIT_VEC cppVar_82409 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82410 = (cppVar_82409 << 3) | 6;
	cppVar_82410 = (cppVar_82410 & cppMask_un_5_);
	BIT_VEC cppVar_82411 = (0 << 5) | cppVar_82410;
	cppVar_82411 = (cppVar_82411 & cppMask_un_8_);
	bool cppVar_82413 = (cppVar_82411 == 176);
	if (cppVar_82413) {
	cppVar_82408 = P3;
	} else {
	BIT_VEC cppVar_82414;
	BIT_VEC cppVar_82415 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82416 = (cppVar_82415 << 3) | 6;
	cppVar_82416 = (cppVar_82416 & cppMask_un_5_);
	BIT_VEC cppVar_82417 = (0 << 5) | cppVar_82416;
	cppVar_82417 = (cppVar_82417 & cppMask_un_8_);
	bool cppVar_82419 = (cppVar_82417 == 184);
	if (cppVar_82419) {
	cppVar_82414 = IP;
	} else {
	BIT_VEC cppVar_82420;
	BIT_VEC cppVar_82421 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82422 = (cppVar_82421 << 3) | 6;
	cppVar_82422 = (cppVar_82422 & cppMask_un_5_);
	BIT_VEC cppVar_82423 = (0 << 5) | cppVar_82422;
	cppVar_82423 = (cppVar_82423 & cppMask_un_8_);
	bool cppVar_82425 = (cppVar_82423 == 208);
	if (cppVar_82425) {
	cppVar_82420 = PSW;
	} else {
	BIT_VEC cppVar_82426;
	BIT_VEC cppVar_82427 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82428 = (cppVar_82427 << 3) | 6;
	cppVar_82428 = (cppVar_82428 & cppMask_un_5_);
	BIT_VEC cppVar_82429 = (0 << 5) | cppVar_82428;
	cppVar_82429 = (cppVar_82429 & cppMask_un_8_);
	bool cppVar_82431 = (cppVar_82429 == 224);
	if (cppVar_82431) {
	cppVar_82426 = ACC;
	} else {
	BIT_VEC cppVar_82432;
	BIT_VEC cppVar_82433 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82434 = (cppVar_82433 << 3) | 6;
	cppVar_82434 = (cppVar_82434 & cppMask_un_5_);
	BIT_VEC cppVar_82435 = (0 << 5) | cppVar_82434;
	cppVar_82435 = (cppVar_82435 & cppMask_un_8_);
	bool cppVar_82437 = (cppVar_82435 == 240);
	if (cppVar_82437) {
	cppVar_82432 = B;
	} else {
	cppVar_82432 = 0;
	}
	cppVar_82426 = cppVar_82432;
	}
	cppVar_82420 = cppVar_82426;
	}
	cppVar_82414 = cppVar_82420;
	}
	cppVar_82408 = cppVar_82414;
	}
	cppVar_82402 = cppVar_82408;
	}
	cppVar_82396 = cppVar_82402;
	}
	cppVar_82390 = cppVar_82396;
	}
	cppVar_82384 = cppVar_82390;
	}
	cppVar_82378 = cppVar_82384;
	}
	cppVar_82372 = cppVar_82378;
	}
	cppVar_82366 = cppVar_82372;
	}
	cppVar_82360 = cppVar_82366;
	}
	cppVar_82354 = cppVar_82360;
	}
	cppVar_82348 = cppVar_82354;
	}
	cppVar_82342 = cppVar_82348;
	}
	cppVar_82336 = cppVar_82342;
	}
	cppVar_82330 = cppVar_82336;
	}
	cppVar_82324 = cppVar_82330;
	}
	cppVar_82318 = cppVar_82324;
	}
	cppVar_82312 = cppVar_82318;
	}
	cppVar_82299 = cppVar_82312;
	}
	cppVar_82293 = cppVar_82299;
	} else {
	cppVar_82293 = TMOD;
	}
	cppVar_82289 = cppVar_82293;
	} else {
	BIT_VEC cppVar_82439;
	BIT_VEC cppVar_82440 = ROM.rd(PC);
	bool cppVar_82442 = (cppVar_82440 == 141);
	if (cppVar_82442) {
	BIT_VEC cppVar_82443;
	BIT_VEC cppVar_82445 = PC + 1;
	cppVar_82445 = (cppVar_82445 & cppMask_un_16_);
	BIT_VEC cppVar_82446 = ROM.rd(cppVar_82445);
	bool cppVar_82448 = (cppVar_82446 == 137);
	if (cppVar_82448) {
	BIT_VEC cppVar_82449;
	BIT_VEC cppVar_82451 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82453 = (cppVar_82451 << 3) | 5;
	cppVar_82453 = (cppVar_82453 & cppMask_un_5_);
	BIT_VEC cppVar_82454 = (0 << 5) | cppVar_82453;
	cppVar_82454 = (cppVar_82454 & cppMask_un_8_);
	BIT_VEC cppVar_82455 = (cppVar_82454 >> 7) & cppMask_un_1_;
	bool cppVar_82457 = (cppVar_82455 == 0);
	if (cppVar_82457) {
	BIT_VEC cppVar_82458 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82459 = (cppVar_82458 << 3) | 5;
	cppVar_82459 = (cppVar_82459 & cppMask_un_5_);
	BIT_VEC cppVar_82460 = (0 << 5) | cppVar_82459;
	cppVar_82460 = (cppVar_82460 & cppMask_un_8_);
	BIT_VEC cppVar_82461 = IRAM.rd(cppVar_82460);
	cppVar_82449 = cppVar_82461;
	} else {
	BIT_VEC cppVar_82462;
	BIT_VEC cppVar_82463 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82464 = (cppVar_82463 << 3) | 5;
	cppVar_82464 = (cppVar_82464 & cppMask_un_5_);
	BIT_VEC cppVar_82465 = (0 << 5) | cppVar_82464;
	cppVar_82465 = (cppVar_82465 & cppMask_un_8_);
	bool cppVar_82467 = (cppVar_82465 == 128);
	if (cppVar_82467) {
	cppVar_82462 = P0;
	} else {
	BIT_VEC cppVar_82468;
	BIT_VEC cppVar_82469 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82470 = (cppVar_82469 << 3) | 5;
	cppVar_82470 = (cppVar_82470 & cppMask_un_5_);
	BIT_VEC cppVar_82471 = (0 << 5) | cppVar_82470;
	cppVar_82471 = (cppVar_82471 & cppMask_un_8_);
	bool cppVar_82473 = (cppVar_82471 == 129);
	if (cppVar_82473) {
	cppVar_82468 = SP;
	} else {
	BIT_VEC cppVar_82474;
	BIT_VEC cppVar_82475 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82476 = (cppVar_82475 << 3) | 5;
	cppVar_82476 = (cppVar_82476 & cppMask_un_5_);
	BIT_VEC cppVar_82477 = (0 << 5) | cppVar_82476;
	cppVar_82477 = (cppVar_82477 & cppMask_un_8_);
	bool cppVar_82479 = (cppVar_82477 == 130);
	if (cppVar_82479) {
	cppVar_82474 = DPL;
	} else {
	BIT_VEC cppVar_82480;
	BIT_VEC cppVar_82481 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82482 = (cppVar_82481 << 3) | 5;
	cppVar_82482 = (cppVar_82482 & cppMask_un_5_);
	BIT_VEC cppVar_82483 = (0 << 5) | cppVar_82482;
	cppVar_82483 = (cppVar_82483 & cppMask_un_8_);
	bool cppVar_82485 = (cppVar_82483 == 131);
	if (cppVar_82485) {
	cppVar_82480 = DPH;
	} else {
	BIT_VEC cppVar_82486;
	BIT_VEC cppVar_82487 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82488 = (cppVar_82487 << 3) | 5;
	cppVar_82488 = (cppVar_82488 & cppMask_un_5_);
	BIT_VEC cppVar_82489 = (0 << 5) | cppVar_82488;
	cppVar_82489 = (cppVar_82489 & cppMask_un_8_);
	bool cppVar_82491 = (cppVar_82489 == 135);
	if (cppVar_82491) {
	cppVar_82486 = PCON;
	} else {
	BIT_VEC cppVar_82492;
	BIT_VEC cppVar_82493 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82494 = (cppVar_82493 << 3) | 5;
	cppVar_82494 = (cppVar_82494 & cppMask_un_5_);
	BIT_VEC cppVar_82495 = (0 << 5) | cppVar_82494;
	cppVar_82495 = (cppVar_82495 & cppMask_un_8_);
	bool cppVar_82497 = (cppVar_82495 == 136);
	if (cppVar_82497) {
	cppVar_82492 = TCON;
	} else {
	BIT_VEC cppVar_82498;
	BIT_VEC cppVar_82499 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82500 = (cppVar_82499 << 3) | 5;
	cppVar_82500 = (cppVar_82500 & cppMask_un_5_);
	BIT_VEC cppVar_82501 = (0 << 5) | cppVar_82500;
	cppVar_82501 = (cppVar_82501 & cppMask_un_8_);
	bool cppVar_82503 = (cppVar_82501 == 137);
	if (cppVar_82503) {
	cppVar_82498 = TMOD;
	} else {
	BIT_VEC cppVar_82504;
	BIT_VEC cppVar_82505 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82506 = (cppVar_82505 << 3) | 5;
	cppVar_82506 = (cppVar_82506 & cppMask_un_5_);
	BIT_VEC cppVar_82507 = (0 << 5) | cppVar_82506;
	cppVar_82507 = (cppVar_82507 & cppMask_un_8_);
	bool cppVar_82509 = (cppVar_82507 == 138);
	if (cppVar_82509) {
	cppVar_82504 = TL0;
	} else {
	BIT_VEC cppVar_82510;
	BIT_VEC cppVar_82511 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82512 = (cppVar_82511 << 3) | 5;
	cppVar_82512 = (cppVar_82512 & cppMask_un_5_);
	BIT_VEC cppVar_82513 = (0 << 5) | cppVar_82512;
	cppVar_82513 = (cppVar_82513 & cppMask_un_8_);
	bool cppVar_82515 = (cppVar_82513 == 140);
	if (cppVar_82515) {
	cppVar_82510 = TH0;
	} else {
	BIT_VEC cppVar_82516;
	BIT_VEC cppVar_82517 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82518 = (cppVar_82517 << 3) | 5;
	cppVar_82518 = (cppVar_82518 & cppMask_un_5_);
	BIT_VEC cppVar_82519 = (0 << 5) | cppVar_82518;
	cppVar_82519 = (cppVar_82519 & cppMask_un_8_);
	bool cppVar_82521 = (cppVar_82519 == 139);
	if (cppVar_82521) {
	cppVar_82516 = TL1;
	} else {
	BIT_VEC cppVar_82522;
	BIT_VEC cppVar_82523 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82524 = (cppVar_82523 << 3) | 5;
	cppVar_82524 = (cppVar_82524 & cppMask_un_5_);
	BIT_VEC cppVar_82525 = (0 << 5) | cppVar_82524;
	cppVar_82525 = (cppVar_82525 & cppMask_un_8_);
	bool cppVar_82527 = (cppVar_82525 == 141);
	if (cppVar_82527) {
	cppVar_82522 = TH1;
	} else {
	BIT_VEC cppVar_82528;
	BIT_VEC cppVar_82529 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82530 = (cppVar_82529 << 3) | 5;
	cppVar_82530 = (cppVar_82530 & cppMask_un_5_);
	BIT_VEC cppVar_82531 = (0 << 5) | cppVar_82530;
	cppVar_82531 = (cppVar_82531 & cppMask_un_8_);
	bool cppVar_82533 = (cppVar_82531 == 144);
	if (cppVar_82533) {
	cppVar_82528 = P1;
	} else {
	BIT_VEC cppVar_82534;
	BIT_VEC cppVar_82535 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82536 = (cppVar_82535 << 3) | 5;
	cppVar_82536 = (cppVar_82536 & cppMask_un_5_);
	BIT_VEC cppVar_82537 = (0 << 5) | cppVar_82536;
	cppVar_82537 = (cppVar_82537 & cppMask_un_8_);
	bool cppVar_82539 = (cppVar_82537 == 152);
	if (cppVar_82539) {
	cppVar_82534 = SCON;
	} else {
	BIT_VEC cppVar_82540;
	BIT_VEC cppVar_82541 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82542 = (cppVar_82541 << 3) | 5;
	cppVar_82542 = (cppVar_82542 & cppMask_un_5_);
	BIT_VEC cppVar_82543 = (0 << 5) | cppVar_82542;
	cppVar_82543 = (cppVar_82543 & cppMask_un_8_);
	bool cppVar_82545 = (cppVar_82543 == 153);
	if (cppVar_82545) {
	cppVar_82540 = SBUF;
	} else {
	BIT_VEC cppVar_82546;
	BIT_VEC cppVar_82547 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82548 = (cppVar_82547 << 3) | 5;
	cppVar_82548 = (cppVar_82548 & cppMask_un_5_);
	BIT_VEC cppVar_82549 = (0 << 5) | cppVar_82548;
	cppVar_82549 = (cppVar_82549 & cppMask_un_8_);
	bool cppVar_82551 = (cppVar_82549 == 160);
	if (cppVar_82551) {
	cppVar_82546 = P2;
	} else {
	BIT_VEC cppVar_82552;
	BIT_VEC cppVar_82553 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82554 = (cppVar_82553 << 3) | 5;
	cppVar_82554 = (cppVar_82554 & cppMask_un_5_);
	BIT_VEC cppVar_82555 = (0 << 5) | cppVar_82554;
	cppVar_82555 = (cppVar_82555 & cppMask_un_8_);
	bool cppVar_82557 = (cppVar_82555 == 168);
	if (cppVar_82557) {
	cppVar_82552 = IE;
	} else {
	BIT_VEC cppVar_82558;
	BIT_VEC cppVar_82559 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82560 = (cppVar_82559 << 3) | 5;
	cppVar_82560 = (cppVar_82560 & cppMask_un_5_);
	BIT_VEC cppVar_82561 = (0 << 5) | cppVar_82560;
	cppVar_82561 = (cppVar_82561 & cppMask_un_8_);
	bool cppVar_82563 = (cppVar_82561 == 176);
	if (cppVar_82563) {
	cppVar_82558 = P3;
	} else {
	BIT_VEC cppVar_82564;
	BIT_VEC cppVar_82565 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82566 = (cppVar_82565 << 3) | 5;
	cppVar_82566 = (cppVar_82566 & cppMask_un_5_);
	BIT_VEC cppVar_82567 = (0 << 5) | cppVar_82566;
	cppVar_82567 = (cppVar_82567 & cppMask_un_8_);
	bool cppVar_82569 = (cppVar_82567 == 184);
	if (cppVar_82569) {
	cppVar_82564 = IP;
	} else {
	BIT_VEC cppVar_82570;
	BIT_VEC cppVar_82571 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82572 = (cppVar_82571 << 3) | 5;
	cppVar_82572 = (cppVar_82572 & cppMask_un_5_);
	BIT_VEC cppVar_82573 = (0 << 5) | cppVar_82572;
	cppVar_82573 = (cppVar_82573 & cppMask_un_8_);
	bool cppVar_82575 = (cppVar_82573 == 208);
	if (cppVar_82575) {
	cppVar_82570 = PSW;
	} else {
	BIT_VEC cppVar_82576;
	BIT_VEC cppVar_82577 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82578 = (cppVar_82577 << 3) | 5;
	cppVar_82578 = (cppVar_82578 & cppMask_un_5_);
	BIT_VEC cppVar_82579 = (0 << 5) | cppVar_82578;
	cppVar_82579 = (cppVar_82579 & cppMask_un_8_);
	bool cppVar_82581 = (cppVar_82579 == 224);
	if (cppVar_82581) {
	cppVar_82576 = ACC;
	} else {
	BIT_VEC cppVar_82582;
	BIT_VEC cppVar_82583 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82584 = (cppVar_82583 << 3) | 5;
	cppVar_82584 = (cppVar_82584 & cppMask_un_5_);
	BIT_VEC cppVar_82585 = (0 << 5) | cppVar_82584;
	cppVar_82585 = (cppVar_82585 & cppMask_un_8_);
	bool cppVar_82587 = (cppVar_82585 == 240);
	if (cppVar_82587) {
	cppVar_82582 = B;
	} else {
	cppVar_82582 = 0;
	}
	cppVar_82576 = cppVar_82582;
	}
	cppVar_82570 = cppVar_82576;
	}
	cppVar_82564 = cppVar_82570;
	}
	cppVar_82558 = cppVar_82564;
	}
	cppVar_82552 = cppVar_82558;
	}
	cppVar_82546 = cppVar_82552;
	}
	cppVar_82540 = cppVar_82546;
	}
	cppVar_82534 = cppVar_82540;
	}
	cppVar_82528 = cppVar_82534;
	}
	cppVar_82522 = cppVar_82528;
	}
	cppVar_82516 = cppVar_82522;
	}
	cppVar_82510 = cppVar_82516;
	}
	cppVar_82504 = cppVar_82510;
	}
	cppVar_82498 = cppVar_82504;
	}
	cppVar_82492 = cppVar_82498;
	}
	cppVar_82486 = cppVar_82492;
	}
	cppVar_82480 = cppVar_82486;
	}
	cppVar_82474 = cppVar_82480;
	}
	cppVar_82468 = cppVar_82474;
	}
	cppVar_82462 = cppVar_82468;
	}
	cppVar_82449 = cppVar_82462;
	}
	cppVar_82443 = cppVar_82449;
	} else {
	cppVar_82443 = TMOD;
	}
	cppVar_82439 = cppVar_82443;
	} else {
	BIT_VEC cppVar_82589;
	BIT_VEC cppVar_82590 = ROM.rd(PC);
	bool cppVar_82592 = (cppVar_82590 == 140);
	if (cppVar_82592) {
	BIT_VEC cppVar_82593;
	BIT_VEC cppVar_82595 = PC + 1;
	cppVar_82595 = (cppVar_82595 & cppMask_un_16_);
	BIT_VEC cppVar_82596 = ROM.rd(cppVar_82595);
	bool cppVar_82598 = (cppVar_82596 == 137);
	if (cppVar_82598) {
	BIT_VEC cppVar_82599;
	BIT_VEC cppVar_82601 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82603 = (cppVar_82601 << 3) | 4;
	cppVar_82603 = (cppVar_82603 & cppMask_un_5_);
	BIT_VEC cppVar_82604 = (0 << 5) | cppVar_82603;
	cppVar_82604 = (cppVar_82604 & cppMask_un_8_);
	BIT_VEC cppVar_82605 = (cppVar_82604 >> 7) & cppMask_un_1_;
	bool cppVar_82607 = (cppVar_82605 == 0);
	if (cppVar_82607) {
	BIT_VEC cppVar_82608 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82609 = (cppVar_82608 << 3) | 4;
	cppVar_82609 = (cppVar_82609 & cppMask_un_5_);
	BIT_VEC cppVar_82610 = (0 << 5) | cppVar_82609;
	cppVar_82610 = (cppVar_82610 & cppMask_un_8_);
	BIT_VEC cppVar_82611 = IRAM.rd(cppVar_82610);
	cppVar_82599 = cppVar_82611;
	} else {
	BIT_VEC cppVar_82612;
	BIT_VEC cppVar_82613 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82614 = (cppVar_82613 << 3) | 4;
	cppVar_82614 = (cppVar_82614 & cppMask_un_5_);
	BIT_VEC cppVar_82615 = (0 << 5) | cppVar_82614;
	cppVar_82615 = (cppVar_82615 & cppMask_un_8_);
	bool cppVar_82617 = (cppVar_82615 == 128);
	if (cppVar_82617) {
	cppVar_82612 = P0;
	} else {
	BIT_VEC cppVar_82618;
	BIT_VEC cppVar_82619 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82620 = (cppVar_82619 << 3) | 4;
	cppVar_82620 = (cppVar_82620 & cppMask_un_5_);
	BIT_VEC cppVar_82621 = (0 << 5) | cppVar_82620;
	cppVar_82621 = (cppVar_82621 & cppMask_un_8_);
	bool cppVar_82623 = (cppVar_82621 == 129);
	if (cppVar_82623) {
	cppVar_82618 = SP;
	} else {
	BIT_VEC cppVar_82624;
	BIT_VEC cppVar_82625 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82626 = (cppVar_82625 << 3) | 4;
	cppVar_82626 = (cppVar_82626 & cppMask_un_5_);
	BIT_VEC cppVar_82627 = (0 << 5) | cppVar_82626;
	cppVar_82627 = (cppVar_82627 & cppMask_un_8_);
	bool cppVar_82629 = (cppVar_82627 == 130);
	if (cppVar_82629) {
	cppVar_82624 = DPL;
	} else {
	BIT_VEC cppVar_82630;
	BIT_VEC cppVar_82631 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82632 = (cppVar_82631 << 3) | 4;
	cppVar_82632 = (cppVar_82632 & cppMask_un_5_);
	BIT_VEC cppVar_82633 = (0 << 5) | cppVar_82632;
	cppVar_82633 = (cppVar_82633 & cppMask_un_8_);
	bool cppVar_82635 = (cppVar_82633 == 131);
	if (cppVar_82635) {
	cppVar_82630 = DPH;
	} else {
	BIT_VEC cppVar_82636;
	BIT_VEC cppVar_82637 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82638 = (cppVar_82637 << 3) | 4;
	cppVar_82638 = (cppVar_82638 & cppMask_un_5_);
	BIT_VEC cppVar_82639 = (0 << 5) | cppVar_82638;
	cppVar_82639 = (cppVar_82639 & cppMask_un_8_);
	bool cppVar_82641 = (cppVar_82639 == 135);
	if (cppVar_82641) {
	cppVar_82636 = PCON;
	} else {
	BIT_VEC cppVar_82642;
	BIT_VEC cppVar_82643 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82644 = (cppVar_82643 << 3) | 4;
	cppVar_82644 = (cppVar_82644 & cppMask_un_5_);
	BIT_VEC cppVar_82645 = (0 << 5) | cppVar_82644;
	cppVar_82645 = (cppVar_82645 & cppMask_un_8_);
	bool cppVar_82647 = (cppVar_82645 == 136);
	if (cppVar_82647) {
	cppVar_82642 = TCON;
	} else {
	BIT_VEC cppVar_82648;
	BIT_VEC cppVar_82649 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82650 = (cppVar_82649 << 3) | 4;
	cppVar_82650 = (cppVar_82650 & cppMask_un_5_);
	BIT_VEC cppVar_82651 = (0 << 5) | cppVar_82650;
	cppVar_82651 = (cppVar_82651 & cppMask_un_8_);
	bool cppVar_82653 = (cppVar_82651 == 137);
	if (cppVar_82653) {
	cppVar_82648 = TMOD;
	} else {
	BIT_VEC cppVar_82654;
	BIT_VEC cppVar_82655 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82656 = (cppVar_82655 << 3) | 4;
	cppVar_82656 = (cppVar_82656 & cppMask_un_5_);
	BIT_VEC cppVar_82657 = (0 << 5) | cppVar_82656;
	cppVar_82657 = (cppVar_82657 & cppMask_un_8_);
	bool cppVar_82659 = (cppVar_82657 == 138);
	if (cppVar_82659) {
	cppVar_82654 = TL0;
	} else {
	BIT_VEC cppVar_82660;
	BIT_VEC cppVar_82661 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82662 = (cppVar_82661 << 3) | 4;
	cppVar_82662 = (cppVar_82662 & cppMask_un_5_);
	BIT_VEC cppVar_82663 = (0 << 5) | cppVar_82662;
	cppVar_82663 = (cppVar_82663 & cppMask_un_8_);
	bool cppVar_82665 = (cppVar_82663 == 140);
	if (cppVar_82665) {
	cppVar_82660 = TH0;
	} else {
	BIT_VEC cppVar_82666;
	BIT_VEC cppVar_82667 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82668 = (cppVar_82667 << 3) | 4;
	cppVar_82668 = (cppVar_82668 & cppMask_un_5_);
	BIT_VEC cppVar_82669 = (0 << 5) | cppVar_82668;
	cppVar_82669 = (cppVar_82669 & cppMask_un_8_);
	bool cppVar_82671 = (cppVar_82669 == 139);
	if (cppVar_82671) {
	cppVar_82666 = TL1;
	} else {
	BIT_VEC cppVar_82672;
	BIT_VEC cppVar_82673 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82674 = (cppVar_82673 << 3) | 4;
	cppVar_82674 = (cppVar_82674 & cppMask_un_5_);
	BIT_VEC cppVar_82675 = (0 << 5) | cppVar_82674;
	cppVar_82675 = (cppVar_82675 & cppMask_un_8_);
	bool cppVar_82677 = (cppVar_82675 == 141);
	if (cppVar_82677) {
	cppVar_82672 = TH1;
	} else {
	BIT_VEC cppVar_82678;
	BIT_VEC cppVar_82679 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82680 = (cppVar_82679 << 3) | 4;
	cppVar_82680 = (cppVar_82680 & cppMask_un_5_);
	BIT_VEC cppVar_82681 = (0 << 5) | cppVar_82680;
	cppVar_82681 = (cppVar_82681 & cppMask_un_8_);
	bool cppVar_82683 = (cppVar_82681 == 144);
	if (cppVar_82683) {
	cppVar_82678 = P1;
	} else {
	BIT_VEC cppVar_82684;
	BIT_VEC cppVar_82685 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82686 = (cppVar_82685 << 3) | 4;
	cppVar_82686 = (cppVar_82686 & cppMask_un_5_);
	BIT_VEC cppVar_82687 = (0 << 5) | cppVar_82686;
	cppVar_82687 = (cppVar_82687 & cppMask_un_8_);
	bool cppVar_82689 = (cppVar_82687 == 152);
	if (cppVar_82689) {
	cppVar_82684 = SCON;
	} else {
	BIT_VEC cppVar_82690;
	BIT_VEC cppVar_82691 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82692 = (cppVar_82691 << 3) | 4;
	cppVar_82692 = (cppVar_82692 & cppMask_un_5_);
	BIT_VEC cppVar_82693 = (0 << 5) | cppVar_82692;
	cppVar_82693 = (cppVar_82693 & cppMask_un_8_);
	bool cppVar_82695 = (cppVar_82693 == 153);
	if (cppVar_82695) {
	cppVar_82690 = SBUF;
	} else {
	BIT_VEC cppVar_82696;
	BIT_VEC cppVar_82697 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82698 = (cppVar_82697 << 3) | 4;
	cppVar_82698 = (cppVar_82698 & cppMask_un_5_);
	BIT_VEC cppVar_82699 = (0 << 5) | cppVar_82698;
	cppVar_82699 = (cppVar_82699 & cppMask_un_8_);
	bool cppVar_82701 = (cppVar_82699 == 160);
	if (cppVar_82701) {
	cppVar_82696 = P2;
	} else {
	BIT_VEC cppVar_82702;
	BIT_VEC cppVar_82703 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82704 = (cppVar_82703 << 3) | 4;
	cppVar_82704 = (cppVar_82704 & cppMask_un_5_);
	BIT_VEC cppVar_82705 = (0 << 5) | cppVar_82704;
	cppVar_82705 = (cppVar_82705 & cppMask_un_8_);
	bool cppVar_82707 = (cppVar_82705 == 168);
	if (cppVar_82707) {
	cppVar_82702 = IE;
	} else {
	BIT_VEC cppVar_82708;
	BIT_VEC cppVar_82709 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82710 = (cppVar_82709 << 3) | 4;
	cppVar_82710 = (cppVar_82710 & cppMask_un_5_);
	BIT_VEC cppVar_82711 = (0 << 5) | cppVar_82710;
	cppVar_82711 = (cppVar_82711 & cppMask_un_8_);
	bool cppVar_82713 = (cppVar_82711 == 176);
	if (cppVar_82713) {
	cppVar_82708 = P3;
	} else {
	BIT_VEC cppVar_82714;
	BIT_VEC cppVar_82715 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82716 = (cppVar_82715 << 3) | 4;
	cppVar_82716 = (cppVar_82716 & cppMask_un_5_);
	BIT_VEC cppVar_82717 = (0 << 5) | cppVar_82716;
	cppVar_82717 = (cppVar_82717 & cppMask_un_8_);
	bool cppVar_82719 = (cppVar_82717 == 184);
	if (cppVar_82719) {
	cppVar_82714 = IP;
	} else {
	BIT_VEC cppVar_82720;
	BIT_VEC cppVar_82721 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82722 = (cppVar_82721 << 3) | 4;
	cppVar_82722 = (cppVar_82722 & cppMask_un_5_);
	BIT_VEC cppVar_82723 = (0 << 5) | cppVar_82722;
	cppVar_82723 = (cppVar_82723 & cppMask_un_8_);
	bool cppVar_82725 = (cppVar_82723 == 208);
	if (cppVar_82725) {
	cppVar_82720 = PSW;
	} else {
	BIT_VEC cppVar_82726;
	BIT_VEC cppVar_82727 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82728 = (cppVar_82727 << 3) | 4;
	cppVar_82728 = (cppVar_82728 & cppMask_un_5_);
	BIT_VEC cppVar_82729 = (0 << 5) | cppVar_82728;
	cppVar_82729 = (cppVar_82729 & cppMask_un_8_);
	bool cppVar_82731 = (cppVar_82729 == 224);
	if (cppVar_82731) {
	cppVar_82726 = ACC;
	} else {
	BIT_VEC cppVar_82732;
	BIT_VEC cppVar_82733 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82734 = (cppVar_82733 << 3) | 4;
	cppVar_82734 = (cppVar_82734 & cppMask_un_5_);
	BIT_VEC cppVar_82735 = (0 << 5) | cppVar_82734;
	cppVar_82735 = (cppVar_82735 & cppMask_un_8_);
	bool cppVar_82737 = (cppVar_82735 == 240);
	if (cppVar_82737) {
	cppVar_82732 = B;
	} else {
	cppVar_82732 = 0;
	}
	cppVar_82726 = cppVar_82732;
	}
	cppVar_82720 = cppVar_82726;
	}
	cppVar_82714 = cppVar_82720;
	}
	cppVar_82708 = cppVar_82714;
	}
	cppVar_82702 = cppVar_82708;
	}
	cppVar_82696 = cppVar_82702;
	}
	cppVar_82690 = cppVar_82696;
	}
	cppVar_82684 = cppVar_82690;
	}
	cppVar_82678 = cppVar_82684;
	}
	cppVar_82672 = cppVar_82678;
	}
	cppVar_82666 = cppVar_82672;
	}
	cppVar_82660 = cppVar_82666;
	}
	cppVar_82654 = cppVar_82660;
	}
	cppVar_82648 = cppVar_82654;
	}
	cppVar_82642 = cppVar_82648;
	}
	cppVar_82636 = cppVar_82642;
	}
	cppVar_82630 = cppVar_82636;
	}
	cppVar_82624 = cppVar_82630;
	}
	cppVar_82618 = cppVar_82624;
	}
	cppVar_82612 = cppVar_82618;
	}
	cppVar_82599 = cppVar_82612;
	}
	cppVar_82593 = cppVar_82599;
	} else {
	cppVar_82593 = TMOD;
	}
	cppVar_82589 = cppVar_82593;
	} else {
	BIT_VEC cppVar_82739;
	BIT_VEC cppVar_82740 = ROM.rd(PC);
	bool cppVar_82742 = (cppVar_82740 == 139);
	if (cppVar_82742) {
	BIT_VEC cppVar_82743;
	BIT_VEC cppVar_82745 = PC + 1;
	cppVar_82745 = (cppVar_82745 & cppMask_un_16_);
	BIT_VEC cppVar_82746 = ROM.rd(cppVar_82745);
	bool cppVar_82748 = (cppVar_82746 == 137);
	if (cppVar_82748) {
	BIT_VEC cppVar_82749;
	BIT_VEC cppVar_82751 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82753 = (cppVar_82751 << 3) | 3;
	cppVar_82753 = (cppVar_82753 & cppMask_un_5_);
	BIT_VEC cppVar_82754 = (0 << 5) | cppVar_82753;
	cppVar_82754 = (cppVar_82754 & cppMask_un_8_);
	BIT_VEC cppVar_82755 = (cppVar_82754 >> 7) & cppMask_un_1_;
	bool cppVar_82757 = (cppVar_82755 == 0);
	if (cppVar_82757) {
	BIT_VEC cppVar_82758 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82759 = (cppVar_82758 << 3) | 3;
	cppVar_82759 = (cppVar_82759 & cppMask_un_5_);
	BIT_VEC cppVar_82760 = (0 << 5) | cppVar_82759;
	cppVar_82760 = (cppVar_82760 & cppMask_un_8_);
	BIT_VEC cppVar_82761 = IRAM.rd(cppVar_82760);
	cppVar_82749 = cppVar_82761;
	} else {
	BIT_VEC cppVar_82762;
	BIT_VEC cppVar_82763 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82764 = (cppVar_82763 << 3) | 3;
	cppVar_82764 = (cppVar_82764 & cppMask_un_5_);
	BIT_VEC cppVar_82765 = (0 << 5) | cppVar_82764;
	cppVar_82765 = (cppVar_82765 & cppMask_un_8_);
	bool cppVar_82767 = (cppVar_82765 == 128);
	if (cppVar_82767) {
	cppVar_82762 = P0;
	} else {
	BIT_VEC cppVar_82768;
	BIT_VEC cppVar_82769 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82770 = (cppVar_82769 << 3) | 3;
	cppVar_82770 = (cppVar_82770 & cppMask_un_5_);
	BIT_VEC cppVar_82771 = (0 << 5) | cppVar_82770;
	cppVar_82771 = (cppVar_82771 & cppMask_un_8_);
	bool cppVar_82773 = (cppVar_82771 == 129);
	if (cppVar_82773) {
	cppVar_82768 = SP;
	} else {
	BIT_VEC cppVar_82774;
	BIT_VEC cppVar_82775 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82776 = (cppVar_82775 << 3) | 3;
	cppVar_82776 = (cppVar_82776 & cppMask_un_5_);
	BIT_VEC cppVar_82777 = (0 << 5) | cppVar_82776;
	cppVar_82777 = (cppVar_82777 & cppMask_un_8_);
	bool cppVar_82779 = (cppVar_82777 == 130);
	if (cppVar_82779) {
	cppVar_82774 = DPL;
	} else {
	BIT_VEC cppVar_82780;
	BIT_VEC cppVar_82781 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82782 = (cppVar_82781 << 3) | 3;
	cppVar_82782 = (cppVar_82782 & cppMask_un_5_);
	BIT_VEC cppVar_82783 = (0 << 5) | cppVar_82782;
	cppVar_82783 = (cppVar_82783 & cppMask_un_8_);
	bool cppVar_82785 = (cppVar_82783 == 131);
	if (cppVar_82785) {
	cppVar_82780 = DPH;
	} else {
	BIT_VEC cppVar_82786;
	BIT_VEC cppVar_82787 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82788 = (cppVar_82787 << 3) | 3;
	cppVar_82788 = (cppVar_82788 & cppMask_un_5_);
	BIT_VEC cppVar_82789 = (0 << 5) | cppVar_82788;
	cppVar_82789 = (cppVar_82789 & cppMask_un_8_);
	bool cppVar_82791 = (cppVar_82789 == 135);
	if (cppVar_82791) {
	cppVar_82786 = PCON;
	} else {
	BIT_VEC cppVar_82792;
	BIT_VEC cppVar_82793 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82794 = (cppVar_82793 << 3) | 3;
	cppVar_82794 = (cppVar_82794 & cppMask_un_5_);
	BIT_VEC cppVar_82795 = (0 << 5) | cppVar_82794;
	cppVar_82795 = (cppVar_82795 & cppMask_un_8_);
	bool cppVar_82797 = (cppVar_82795 == 136);
	if (cppVar_82797) {
	cppVar_82792 = TCON;
	} else {
	BIT_VEC cppVar_82798;
	BIT_VEC cppVar_82799 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82800 = (cppVar_82799 << 3) | 3;
	cppVar_82800 = (cppVar_82800 & cppMask_un_5_);
	BIT_VEC cppVar_82801 = (0 << 5) | cppVar_82800;
	cppVar_82801 = (cppVar_82801 & cppMask_un_8_);
	bool cppVar_82803 = (cppVar_82801 == 137);
	if (cppVar_82803) {
	cppVar_82798 = TMOD;
	} else {
	BIT_VEC cppVar_82804;
	BIT_VEC cppVar_82805 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82806 = (cppVar_82805 << 3) | 3;
	cppVar_82806 = (cppVar_82806 & cppMask_un_5_);
	BIT_VEC cppVar_82807 = (0 << 5) | cppVar_82806;
	cppVar_82807 = (cppVar_82807 & cppMask_un_8_);
	bool cppVar_82809 = (cppVar_82807 == 138);
	if (cppVar_82809) {
	cppVar_82804 = TL0;
	} else {
	BIT_VEC cppVar_82810;
	BIT_VEC cppVar_82811 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82812 = (cppVar_82811 << 3) | 3;
	cppVar_82812 = (cppVar_82812 & cppMask_un_5_);
	BIT_VEC cppVar_82813 = (0 << 5) | cppVar_82812;
	cppVar_82813 = (cppVar_82813 & cppMask_un_8_);
	bool cppVar_82815 = (cppVar_82813 == 140);
	if (cppVar_82815) {
	cppVar_82810 = TH0;
	} else {
	BIT_VEC cppVar_82816;
	BIT_VEC cppVar_82817 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82818 = (cppVar_82817 << 3) | 3;
	cppVar_82818 = (cppVar_82818 & cppMask_un_5_);
	BIT_VEC cppVar_82819 = (0 << 5) | cppVar_82818;
	cppVar_82819 = (cppVar_82819 & cppMask_un_8_);
	bool cppVar_82821 = (cppVar_82819 == 139);
	if (cppVar_82821) {
	cppVar_82816 = TL1;
	} else {
	BIT_VEC cppVar_82822;
	BIT_VEC cppVar_82823 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82824 = (cppVar_82823 << 3) | 3;
	cppVar_82824 = (cppVar_82824 & cppMask_un_5_);
	BIT_VEC cppVar_82825 = (0 << 5) | cppVar_82824;
	cppVar_82825 = (cppVar_82825 & cppMask_un_8_);
	bool cppVar_82827 = (cppVar_82825 == 141);
	if (cppVar_82827) {
	cppVar_82822 = TH1;
	} else {
	BIT_VEC cppVar_82828;
	BIT_VEC cppVar_82829 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82830 = (cppVar_82829 << 3) | 3;
	cppVar_82830 = (cppVar_82830 & cppMask_un_5_);
	BIT_VEC cppVar_82831 = (0 << 5) | cppVar_82830;
	cppVar_82831 = (cppVar_82831 & cppMask_un_8_);
	bool cppVar_82833 = (cppVar_82831 == 144);
	if (cppVar_82833) {
	cppVar_82828 = P1;
	} else {
	BIT_VEC cppVar_82834;
	BIT_VEC cppVar_82835 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82836 = (cppVar_82835 << 3) | 3;
	cppVar_82836 = (cppVar_82836 & cppMask_un_5_);
	BIT_VEC cppVar_82837 = (0 << 5) | cppVar_82836;
	cppVar_82837 = (cppVar_82837 & cppMask_un_8_);
	bool cppVar_82839 = (cppVar_82837 == 152);
	if (cppVar_82839) {
	cppVar_82834 = SCON;
	} else {
	BIT_VEC cppVar_82840;
	BIT_VEC cppVar_82841 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82842 = (cppVar_82841 << 3) | 3;
	cppVar_82842 = (cppVar_82842 & cppMask_un_5_);
	BIT_VEC cppVar_82843 = (0 << 5) | cppVar_82842;
	cppVar_82843 = (cppVar_82843 & cppMask_un_8_);
	bool cppVar_82845 = (cppVar_82843 == 153);
	if (cppVar_82845) {
	cppVar_82840 = SBUF;
	} else {
	BIT_VEC cppVar_82846;
	BIT_VEC cppVar_82847 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82848 = (cppVar_82847 << 3) | 3;
	cppVar_82848 = (cppVar_82848 & cppMask_un_5_);
	BIT_VEC cppVar_82849 = (0 << 5) | cppVar_82848;
	cppVar_82849 = (cppVar_82849 & cppMask_un_8_);
	bool cppVar_82851 = (cppVar_82849 == 160);
	if (cppVar_82851) {
	cppVar_82846 = P2;
	} else {
	BIT_VEC cppVar_82852;
	BIT_VEC cppVar_82853 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82854 = (cppVar_82853 << 3) | 3;
	cppVar_82854 = (cppVar_82854 & cppMask_un_5_);
	BIT_VEC cppVar_82855 = (0 << 5) | cppVar_82854;
	cppVar_82855 = (cppVar_82855 & cppMask_un_8_);
	bool cppVar_82857 = (cppVar_82855 == 168);
	if (cppVar_82857) {
	cppVar_82852 = IE;
	} else {
	BIT_VEC cppVar_82858;
	BIT_VEC cppVar_82859 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82860 = (cppVar_82859 << 3) | 3;
	cppVar_82860 = (cppVar_82860 & cppMask_un_5_);
	BIT_VEC cppVar_82861 = (0 << 5) | cppVar_82860;
	cppVar_82861 = (cppVar_82861 & cppMask_un_8_);
	bool cppVar_82863 = (cppVar_82861 == 176);
	if (cppVar_82863) {
	cppVar_82858 = P3;
	} else {
	BIT_VEC cppVar_82864;
	BIT_VEC cppVar_82865 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82866 = (cppVar_82865 << 3) | 3;
	cppVar_82866 = (cppVar_82866 & cppMask_un_5_);
	BIT_VEC cppVar_82867 = (0 << 5) | cppVar_82866;
	cppVar_82867 = (cppVar_82867 & cppMask_un_8_);
	bool cppVar_82869 = (cppVar_82867 == 184);
	if (cppVar_82869) {
	cppVar_82864 = IP;
	} else {
	BIT_VEC cppVar_82870;
	BIT_VEC cppVar_82871 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82872 = (cppVar_82871 << 3) | 3;
	cppVar_82872 = (cppVar_82872 & cppMask_un_5_);
	BIT_VEC cppVar_82873 = (0 << 5) | cppVar_82872;
	cppVar_82873 = (cppVar_82873 & cppMask_un_8_);
	bool cppVar_82875 = (cppVar_82873 == 208);
	if (cppVar_82875) {
	cppVar_82870 = PSW;
	} else {
	BIT_VEC cppVar_82876;
	BIT_VEC cppVar_82877 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82878 = (cppVar_82877 << 3) | 3;
	cppVar_82878 = (cppVar_82878 & cppMask_un_5_);
	BIT_VEC cppVar_82879 = (0 << 5) | cppVar_82878;
	cppVar_82879 = (cppVar_82879 & cppMask_un_8_);
	bool cppVar_82881 = (cppVar_82879 == 224);
	if (cppVar_82881) {
	cppVar_82876 = ACC;
	} else {
	BIT_VEC cppVar_82882;
	BIT_VEC cppVar_82883 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82884 = (cppVar_82883 << 3) | 3;
	cppVar_82884 = (cppVar_82884 & cppMask_un_5_);
	BIT_VEC cppVar_82885 = (0 << 5) | cppVar_82884;
	cppVar_82885 = (cppVar_82885 & cppMask_un_8_);
	bool cppVar_82887 = (cppVar_82885 == 240);
	if (cppVar_82887) {
	cppVar_82882 = B;
	} else {
	cppVar_82882 = 0;
	}
	cppVar_82876 = cppVar_82882;
	}
	cppVar_82870 = cppVar_82876;
	}
	cppVar_82864 = cppVar_82870;
	}
	cppVar_82858 = cppVar_82864;
	}
	cppVar_82852 = cppVar_82858;
	}
	cppVar_82846 = cppVar_82852;
	}
	cppVar_82840 = cppVar_82846;
	}
	cppVar_82834 = cppVar_82840;
	}
	cppVar_82828 = cppVar_82834;
	}
	cppVar_82822 = cppVar_82828;
	}
	cppVar_82816 = cppVar_82822;
	}
	cppVar_82810 = cppVar_82816;
	}
	cppVar_82804 = cppVar_82810;
	}
	cppVar_82798 = cppVar_82804;
	}
	cppVar_82792 = cppVar_82798;
	}
	cppVar_82786 = cppVar_82792;
	}
	cppVar_82780 = cppVar_82786;
	}
	cppVar_82774 = cppVar_82780;
	}
	cppVar_82768 = cppVar_82774;
	}
	cppVar_82762 = cppVar_82768;
	}
	cppVar_82749 = cppVar_82762;
	}
	cppVar_82743 = cppVar_82749;
	} else {
	cppVar_82743 = TMOD;
	}
	cppVar_82739 = cppVar_82743;
	} else {
	BIT_VEC cppVar_82889;
	BIT_VEC cppVar_82890 = ROM.rd(PC);
	bool cppVar_82892 = (cppVar_82890 == 138);
	if (cppVar_82892) {
	BIT_VEC cppVar_82893;
	BIT_VEC cppVar_82895 = PC + 1;
	cppVar_82895 = (cppVar_82895 & cppMask_un_16_);
	BIT_VEC cppVar_82896 = ROM.rd(cppVar_82895);
	bool cppVar_82898 = (cppVar_82896 == 137);
	if (cppVar_82898) {
	BIT_VEC cppVar_82899;
	BIT_VEC cppVar_82901 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82903 = (cppVar_82901 << 3) | 2;
	cppVar_82903 = (cppVar_82903 & cppMask_un_5_);
	BIT_VEC cppVar_82904 = (0 << 5) | cppVar_82903;
	cppVar_82904 = (cppVar_82904 & cppMask_un_8_);
	BIT_VEC cppVar_82905 = (cppVar_82904 >> 7) & cppMask_un_1_;
	bool cppVar_82907 = (cppVar_82905 == 0);
	if (cppVar_82907) {
	BIT_VEC cppVar_82908 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82909 = (cppVar_82908 << 3) | 2;
	cppVar_82909 = (cppVar_82909 & cppMask_un_5_);
	BIT_VEC cppVar_82910 = (0 << 5) | cppVar_82909;
	cppVar_82910 = (cppVar_82910 & cppMask_un_8_);
	BIT_VEC cppVar_82911 = IRAM.rd(cppVar_82910);
	cppVar_82899 = cppVar_82911;
	} else {
	BIT_VEC cppVar_82912;
	BIT_VEC cppVar_82913 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82914 = (cppVar_82913 << 3) | 2;
	cppVar_82914 = (cppVar_82914 & cppMask_un_5_);
	BIT_VEC cppVar_82915 = (0 << 5) | cppVar_82914;
	cppVar_82915 = (cppVar_82915 & cppMask_un_8_);
	bool cppVar_82917 = (cppVar_82915 == 128);
	if (cppVar_82917) {
	cppVar_82912 = P0;
	} else {
	BIT_VEC cppVar_82918;
	BIT_VEC cppVar_82919 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82920 = (cppVar_82919 << 3) | 2;
	cppVar_82920 = (cppVar_82920 & cppMask_un_5_);
	BIT_VEC cppVar_82921 = (0 << 5) | cppVar_82920;
	cppVar_82921 = (cppVar_82921 & cppMask_un_8_);
	bool cppVar_82923 = (cppVar_82921 == 129);
	if (cppVar_82923) {
	cppVar_82918 = SP;
	} else {
	BIT_VEC cppVar_82924;
	BIT_VEC cppVar_82925 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82926 = (cppVar_82925 << 3) | 2;
	cppVar_82926 = (cppVar_82926 & cppMask_un_5_);
	BIT_VEC cppVar_82927 = (0 << 5) | cppVar_82926;
	cppVar_82927 = (cppVar_82927 & cppMask_un_8_);
	bool cppVar_82929 = (cppVar_82927 == 130);
	if (cppVar_82929) {
	cppVar_82924 = DPL;
	} else {
	BIT_VEC cppVar_82930;
	BIT_VEC cppVar_82931 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82932 = (cppVar_82931 << 3) | 2;
	cppVar_82932 = (cppVar_82932 & cppMask_un_5_);
	BIT_VEC cppVar_82933 = (0 << 5) | cppVar_82932;
	cppVar_82933 = (cppVar_82933 & cppMask_un_8_);
	bool cppVar_82935 = (cppVar_82933 == 131);
	if (cppVar_82935) {
	cppVar_82930 = DPH;
	} else {
	BIT_VEC cppVar_82936;
	BIT_VEC cppVar_82937 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82938 = (cppVar_82937 << 3) | 2;
	cppVar_82938 = (cppVar_82938 & cppMask_un_5_);
	BIT_VEC cppVar_82939 = (0 << 5) | cppVar_82938;
	cppVar_82939 = (cppVar_82939 & cppMask_un_8_);
	bool cppVar_82941 = (cppVar_82939 == 135);
	if (cppVar_82941) {
	cppVar_82936 = PCON;
	} else {
	BIT_VEC cppVar_82942;
	BIT_VEC cppVar_82943 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82944 = (cppVar_82943 << 3) | 2;
	cppVar_82944 = (cppVar_82944 & cppMask_un_5_);
	BIT_VEC cppVar_82945 = (0 << 5) | cppVar_82944;
	cppVar_82945 = (cppVar_82945 & cppMask_un_8_);
	bool cppVar_82947 = (cppVar_82945 == 136);
	if (cppVar_82947) {
	cppVar_82942 = TCON;
	} else {
	BIT_VEC cppVar_82948;
	BIT_VEC cppVar_82949 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82950 = (cppVar_82949 << 3) | 2;
	cppVar_82950 = (cppVar_82950 & cppMask_un_5_);
	BIT_VEC cppVar_82951 = (0 << 5) | cppVar_82950;
	cppVar_82951 = (cppVar_82951 & cppMask_un_8_);
	bool cppVar_82953 = (cppVar_82951 == 137);
	if (cppVar_82953) {
	cppVar_82948 = TMOD;
	} else {
	BIT_VEC cppVar_82954;
	BIT_VEC cppVar_82955 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82956 = (cppVar_82955 << 3) | 2;
	cppVar_82956 = (cppVar_82956 & cppMask_un_5_);
	BIT_VEC cppVar_82957 = (0 << 5) | cppVar_82956;
	cppVar_82957 = (cppVar_82957 & cppMask_un_8_);
	bool cppVar_82959 = (cppVar_82957 == 138);
	if (cppVar_82959) {
	cppVar_82954 = TL0;
	} else {
	BIT_VEC cppVar_82960;
	BIT_VEC cppVar_82961 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82962 = (cppVar_82961 << 3) | 2;
	cppVar_82962 = (cppVar_82962 & cppMask_un_5_);
	BIT_VEC cppVar_82963 = (0 << 5) | cppVar_82962;
	cppVar_82963 = (cppVar_82963 & cppMask_un_8_);
	bool cppVar_82965 = (cppVar_82963 == 140);
	if (cppVar_82965) {
	cppVar_82960 = TH0;
	} else {
	BIT_VEC cppVar_82966;
	BIT_VEC cppVar_82967 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82968 = (cppVar_82967 << 3) | 2;
	cppVar_82968 = (cppVar_82968 & cppMask_un_5_);
	BIT_VEC cppVar_82969 = (0 << 5) | cppVar_82968;
	cppVar_82969 = (cppVar_82969 & cppMask_un_8_);
	bool cppVar_82971 = (cppVar_82969 == 139);
	if (cppVar_82971) {
	cppVar_82966 = TL1;
	} else {
	BIT_VEC cppVar_82972;
	BIT_VEC cppVar_82973 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82974 = (cppVar_82973 << 3) | 2;
	cppVar_82974 = (cppVar_82974 & cppMask_un_5_);
	BIT_VEC cppVar_82975 = (0 << 5) | cppVar_82974;
	cppVar_82975 = (cppVar_82975 & cppMask_un_8_);
	bool cppVar_82977 = (cppVar_82975 == 141);
	if (cppVar_82977) {
	cppVar_82972 = TH1;
	} else {
	BIT_VEC cppVar_82978;
	BIT_VEC cppVar_82979 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82980 = (cppVar_82979 << 3) | 2;
	cppVar_82980 = (cppVar_82980 & cppMask_un_5_);
	BIT_VEC cppVar_82981 = (0 << 5) | cppVar_82980;
	cppVar_82981 = (cppVar_82981 & cppMask_un_8_);
	bool cppVar_82983 = (cppVar_82981 == 144);
	if (cppVar_82983) {
	cppVar_82978 = P1;
	} else {
	BIT_VEC cppVar_82984;
	BIT_VEC cppVar_82985 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82986 = (cppVar_82985 << 3) | 2;
	cppVar_82986 = (cppVar_82986 & cppMask_un_5_);
	BIT_VEC cppVar_82987 = (0 << 5) | cppVar_82986;
	cppVar_82987 = (cppVar_82987 & cppMask_un_8_);
	bool cppVar_82989 = (cppVar_82987 == 152);
	if (cppVar_82989) {
	cppVar_82984 = SCON;
	} else {
	BIT_VEC cppVar_82990;
	BIT_VEC cppVar_82991 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82992 = (cppVar_82991 << 3) | 2;
	cppVar_82992 = (cppVar_82992 & cppMask_un_5_);
	BIT_VEC cppVar_82993 = (0 << 5) | cppVar_82992;
	cppVar_82993 = (cppVar_82993 & cppMask_un_8_);
	bool cppVar_82995 = (cppVar_82993 == 153);
	if (cppVar_82995) {
	cppVar_82990 = SBUF;
	} else {
	BIT_VEC cppVar_82996;
	BIT_VEC cppVar_82997 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_82998 = (cppVar_82997 << 3) | 2;
	cppVar_82998 = (cppVar_82998 & cppMask_un_5_);
	BIT_VEC cppVar_82999 = (0 << 5) | cppVar_82998;
	cppVar_82999 = (cppVar_82999 & cppMask_un_8_);
	bool cppVar_83001 = (cppVar_82999 == 160);
	if (cppVar_83001) {
	cppVar_82996 = P2;
	} else {
	BIT_VEC cppVar_83002;
	BIT_VEC cppVar_83003 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83004 = (cppVar_83003 << 3) | 2;
	cppVar_83004 = (cppVar_83004 & cppMask_un_5_);
	BIT_VEC cppVar_83005 = (0 << 5) | cppVar_83004;
	cppVar_83005 = (cppVar_83005 & cppMask_un_8_);
	bool cppVar_83007 = (cppVar_83005 == 168);
	if (cppVar_83007) {
	cppVar_83002 = IE;
	} else {
	BIT_VEC cppVar_83008;
	BIT_VEC cppVar_83009 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83010 = (cppVar_83009 << 3) | 2;
	cppVar_83010 = (cppVar_83010 & cppMask_un_5_);
	BIT_VEC cppVar_83011 = (0 << 5) | cppVar_83010;
	cppVar_83011 = (cppVar_83011 & cppMask_un_8_);
	bool cppVar_83013 = (cppVar_83011 == 176);
	if (cppVar_83013) {
	cppVar_83008 = P3;
	} else {
	BIT_VEC cppVar_83014;
	BIT_VEC cppVar_83015 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83016 = (cppVar_83015 << 3) | 2;
	cppVar_83016 = (cppVar_83016 & cppMask_un_5_);
	BIT_VEC cppVar_83017 = (0 << 5) | cppVar_83016;
	cppVar_83017 = (cppVar_83017 & cppMask_un_8_);
	bool cppVar_83019 = (cppVar_83017 == 184);
	if (cppVar_83019) {
	cppVar_83014 = IP;
	} else {
	BIT_VEC cppVar_83020;
	BIT_VEC cppVar_83021 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83022 = (cppVar_83021 << 3) | 2;
	cppVar_83022 = (cppVar_83022 & cppMask_un_5_);
	BIT_VEC cppVar_83023 = (0 << 5) | cppVar_83022;
	cppVar_83023 = (cppVar_83023 & cppMask_un_8_);
	bool cppVar_83025 = (cppVar_83023 == 208);
	if (cppVar_83025) {
	cppVar_83020 = PSW;
	} else {
	BIT_VEC cppVar_83026;
	BIT_VEC cppVar_83027 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83028 = (cppVar_83027 << 3) | 2;
	cppVar_83028 = (cppVar_83028 & cppMask_un_5_);
	BIT_VEC cppVar_83029 = (0 << 5) | cppVar_83028;
	cppVar_83029 = (cppVar_83029 & cppMask_un_8_);
	bool cppVar_83031 = (cppVar_83029 == 224);
	if (cppVar_83031) {
	cppVar_83026 = ACC;
	} else {
	BIT_VEC cppVar_83032;
	BIT_VEC cppVar_83033 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83034 = (cppVar_83033 << 3) | 2;
	cppVar_83034 = (cppVar_83034 & cppMask_un_5_);
	BIT_VEC cppVar_83035 = (0 << 5) | cppVar_83034;
	cppVar_83035 = (cppVar_83035 & cppMask_un_8_);
	bool cppVar_83037 = (cppVar_83035 == 240);
	if (cppVar_83037) {
	cppVar_83032 = B;
	} else {
	cppVar_83032 = 0;
	}
	cppVar_83026 = cppVar_83032;
	}
	cppVar_83020 = cppVar_83026;
	}
	cppVar_83014 = cppVar_83020;
	}
	cppVar_83008 = cppVar_83014;
	}
	cppVar_83002 = cppVar_83008;
	}
	cppVar_82996 = cppVar_83002;
	}
	cppVar_82990 = cppVar_82996;
	}
	cppVar_82984 = cppVar_82990;
	}
	cppVar_82978 = cppVar_82984;
	}
	cppVar_82972 = cppVar_82978;
	}
	cppVar_82966 = cppVar_82972;
	}
	cppVar_82960 = cppVar_82966;
	}
	cppVar_82954 = cppVar_82960;
	}
	cppVar_82948 = cppVar_82954;
	}
	cppVar_82942 = cppVar_82948;
	}
	cppVar_82936 = cppVar_82942;
	}
	cppVar_82930 = cppVar_82936;
	}
	cppVar_82924 = cppVar_82930;
	}
	cppVar_82918 = cppVar_82924;
	}
	cppVar_82912 = cppVar_82918;
	}
	cppVar_82899 = cppVar_82912;
	}
	cppVar_82893 = cppVar_82899;
	} else {
	cppVar_82893 = TMOD;
	}
	cppVar_82889 = cppVar_82893;
	} else {
	BIT_VEC cppVar_83039;
	BIT_VEC cppVar_83040 = ROM.rd(PC);
	bool cppVar_83042 = (cppVar_83040 == 137);
	if (cppVar_83042) {
	BIT_VEC cppVar_83043;
	BIT_VEC cppVar_83045 = PC + 1;
	cppVar_83045 = (cppVar_83045 & cppMask_un_16_);
	BIT_VEC cppVar_83046 = ROM.rd(cppVar_83045);
	bool cppVar_83048 = (cppVar_83046 == 137);
	if (cppVar_83048) {
	BIT_VEC cppVar_83049;
	BIT_VEC cppVar_83051 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83053 = (cppVar_83051 << 3) | 1;
	cppVar_83053 = (cppVar_83053 & cppMask_un_5_);
	BIT_VEC cppVar_83054 = (0 << 5) | cppVar_83053;
	cppVar_83054 = (cppVar_83054 & cppMask_un_8_);
	BIT_VEC cppVar_83055 = (cppVar_83054 >> 7) & cppMask_un_1_;
	bool cppVar_83057 = (cppVar_83055 == 0);
	if (cppVar_83057) {
	BIT_VEC cppVar_83058 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83059 = (cppVar_83058 << 3) | 1;
	cppVar_83059 = (cppVar_83059 & cppMask_un_5_);
	BIT_VEC cppVar_83060 = (0 << 5) | cppVar_83059;
	cppVar_83060 = (cppVar_83060 & cppMask_un_8_);
	BIT_VEC cppVar_83061 = IRAM.rd(cppVar_83060);
	cppVar_83049 = cppVar_83061;
	} else {
	BIT_VEC cppVar_83062;
	BIT_VEC cppVar_83063 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83064 = (cppVar_83063 << 3) | 1;
	cppVar_83064 = (cppVar_83064 & cppMask_un_5_);
	BIT_VEC cppVar_83065 = (0 << 5) | cppVar_83064;
	cppVar_83065 = (cppVar_83065 & cppMask_un_8_);
	bool cppVar_83067 = (cppVar_83065 == 128);
	if (cppVar_83067) {
	cppVar_83062 = P0;
	} else {
	BIT_VEC cppVar_83068;
	BIT_VEC cppVar_83069 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83070 = (cppVar_83069 << 3) | 1;
	cppVar_83070 = (cppVar_83070 & cppMask_un_5_);
	BIT_VEC cppVar_83071 = (0 << 5) | cppVar_83070;
	cppVar_83071 = (cppVar_83071 & cppMask_un_8_);
	bool cppVar_83073 = (cppVar_83071 == 129);
	if (cppVar_83073) {
	cppVar_83068 = SP;
	} else {
	BIT_VEC cppVar_83074;
	BIT_VEC cppVar_83075 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83076 = (cppVar_83075 << 3) | 1;
	cppVar_83076 = (cppVar_83076 & cppMask_un_5_);
	BIT_VEC cppVar_83077 = (0 << 5) | cppVar_83076;
	cppVar_83077 = (cppVar_83077 & cppMask_un_8_);
	bool cppVar_83079 = (cppVar_83077 == 130);
	if (cppVar_83079) {
	cppVar_83074 = DPL;
	} else {
	BIT_VEC cppVar_83080;
	BIT_VEC cppVar_83081 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83082 = (cppVar_83081 << 3) | 1;
	cppVar_83082 = (cppVar_83082 & cppMask_un_5_);
	BIT_VEC cppVar_83083 = (0 << 5) | cppVar_83082;
	cppVar_83083 = (cppVar_83083 & cppMask_un_8_);
	bool cppVar_83085 = (cppVar_83083 == 131);
	if (cppVar_83085) {
	cppVar_83080 = DPH;
	} else {
	BIT_VEC cppVar_83086;
	BIT_VEC cppVar_83087 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83088 = (cppVar_83087 << 3) | 1;
	cppVar_83088 = (cppVar_83088 & cppMask_un_5_);
	BIT_VEC cppVar_83089 = (0 << 5) | cppVar_83088;
	cppVar_83089 = (cppVar_83089 & cppMask_un_8_);
	bool cppVar_83091 = (cppVar_83089 == 135);
	if (cppVar_83091) {
	cppVar_83086 = PCON;
	} else {
	BIT_VEC cppVar_83092;
	BIT_VEC cppVar_83093 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83094 = (cppVar_83093 << 3) | 1;
	cppVar_83094 = (cppVar_83094 & cppMask_un_5_);
	BIT_VEC cppVar_83095 = (0 << 5) | cppVar_83094;
	cppVar_83095 = (cppVar_83095 & cppMask_un_8_);
	bool cppVar_83097 = (cppVar_83095 == 136);
	if (cppVar_83097) {
	cppVar_83092 = TCON;
	} else {
	BIT_VEC cppVar_83098;
	BIT_VEC cppVar_83099 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83100 = (cppVar_83099 << 3) | 1;
	cppVar_83100 = (cppVar_83100 & cppMask_un_5_);
	BIT_VEC cppVar_83101 = (0 << 5) | cppVar_83100;
	cppVar_83101 = (cppVar_83101 & cppMask_un_8_);
	bool cppVar_83103 = (cppVar_83101 == 137);
	if (cppVar_83103) {
	cppVar_83098 = TMOD;
	} else {
	BIT_VEC cppVar_83104;
	BIT_VEC cppVar_83105 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83106 = (cppVar_83105 << 3) | 1;
	cppVar_83106 = (cppVar_83106 & cppMask_un_5_);
	BIT_VEC cppVar_83107 = (0 << 5) | cppVar_83106;
	cppVar_83107 = (cppVar_83107 & cppMask_un_8_);
	bool cppVar_83109 = (cppVar_83107 == 138);
	if (cppVar_83109) {
	cppVar_83104 = TL0;
	} else {
	BIT_VEC cppVar_83110;
	BIT_VEC cppVar_83111 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83112 = (cppVar_83111 << 3) | 1;
	cppVar_83112 = (cppVar_83112 & cppMask_un_5_);
	BIT_VEC cppVar_83113 = (0 << 5) | cppVar_83112;
	cppVar_83113 = (cppVar_83113 & cppMask_un_8_);
	bool cppVar_83115 = (cppVar_83113 == 140);
	if (cppVar_83115) {
	cppVar_83110 = TH0;
	} else {
	BIT_VEC cppVar_83116;
	BIT_VEC cppVar_83117 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83118 = (cppVar_83117 << 3) | 1;
	cppVar_83118 = (cppVar_83118 & cppMask_un_5_);
	BIT_VEC cppVar_83119 = (0 << 5) | cppVar_83118;
	cppVar_83119 = (cppVar_83119 & cppMask_un_8_);
	bool cppVar_83121 = (cppVar_83119 == 139);
	if (cppVar_83121) {
	cppVar_83116 = TL1;
	} else {
	BIT_VEC cppVar_83122;
	BIT_VEC cppVar_83123 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83124 = (cppVar_83123 << 3) | 1;
	cppVar_83124 = (cppVar_83124 & cppMask_un_5_);
	BIT_VEC cppVar_83125 = (0 << 5) | cppVar_83124;
	cppVar_83125 = (cppVar_83125 & cppMask_un_8_);
	bool cppVar_83127 = (cppVar_83125 == 141);
	if (cppVar_83127) {
	cppVar_83122 = TH1;
	} else {
	BIT_VEC cppVar_83128;
	BIT_VEC cppVar_83129 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83130 = (cppVar_83129 << 3) | 1;
	cppVar_83130 = (cppVar_83130 & cppMask_un_5_);
	BIT_VEC cppVar_83131 = (0 << 5) | cppVar_83130;
	cppVar_83131 = (cppVar_83131 & cppMask_un_8_);
	bool cppVar_83133 = (cppVar_83131 == 144);
	if (cppVar_83133) {
	cppVar_83128 = P1;
	} else {
	BIT_VEC cppVar_83134;
	BIT_VEC cppVar_83135 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83136 = (cppVar_83135 << 3) | 1;
	cppVar_83136 = (cppVar_83136 & cppMask_un_5_);
	BIT_VEC cppVar_83137 = (0 << 5) | cppVar_83136;
	cppVar_83137 = (cppVar_83137 & cppMask_un_8_);
	bool cppVar_83139 = (cppVar_83137 == 152);
	if (cppVar_83139) {
	cppVar_83134 = SCON;
	} else {
	BIT_VEC cppVar_83140;
	BIT_VEC cppVar_83141 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83142 = (cppVar_83141 << 3) | 1;
	cppVar_83142 = (cppVar_83142 & cppMask_un_5_);
	BIT_VEC cppVar_83143 = (0 << 5) | cppVar_83142;
	cppVar_83143 = (cppVar_83143 & cppMask_un_8_);
	bool cppVar_83145 = (cppVar_83143 == 153);
	if (cppVar_83145) {
	cppVar_83140 = SBUF;
	} else {
	BIT_VEC cppVar_83146;
	BIT_VEC cppVar_83147 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83148 = (cppVar_83147 << 3) | 1;
	cppVar_83148 = (cppVar_83148 & cppMask_un_5_);
	BIT_VEC cppVar_83149 = (0 << 5) | cppVar_83148;
	cppVar_83149 = (cppVar_83149 & cppMask_un_8_);
	bool cppVar_83151 = (cppVar_83149 == 160);
	if (cppVar_83151) {
	cppVar_83146 = P2;
	} else {
	BIT_VEC cppVar_83152;
	BIT_VEC cppVar_83153 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83154 = (cppVar_83153 << 3) | 1;
	cppVar_83154 = (cppVar_83154 & cppMask_un_5_);
	BIT_VEC cppVar_83155 = (0 << 5) | cppVar_83154;
	cppVar_83155 = (cppVar_83155 & cppMask_un_8_);
	bool cppVar_83157 = (cppVar_83155 == 168);
	if (cppVar_83157) {
	cppVar_83152 = IE;
	} else {
	BIT_VEC cppVar_83158;
	BIT_VEC cppVar_83159 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83160 = (cppVar_83159 << 3) | 1;
	cppVar_83160 = (cppVar_83160 & cppMask_un_5_);
	BIT_VEC cppVar_83161 = (0 << 5) | cppVar_83160;
	cppVar_83161 = (cppVar_83161 & cppMask_un_8_);
	bool cppVar_83163 = (cppVar_83161 == 176);
	if (cppVar_83163) {
	cppVar_83158 = P3;
	} else {
	BIT_VEC cppVar_83164;
	BIT_VEC cppVar_83165 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83166 = (cppVar_83165 << 3) | 1;
	cppVar_83166 = (cppVar_83166 & cppMask_un_5_);
	BIT_VEC cppVar_83167 = (0 << 5) | cppVar_83166;
	cppVar_83167 = (cppVar_83167 & cppMask_un_8_);
	bool cppVar_83169 = (cppVar_83167 == 184);
	if (cppVar_83169) {
	cppVar_83164 = IP;
	} else {
	BIT_VEC cppVar_83170;
	BIT_VEC cppVar_83171 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83172 = (cppVar_83171 << 3) | 1;
	cppVar_83172 = (cppVar_83172 & cppMask_un_5_);
	BIT_VEC cppVar_83173 = (0 << 5) | cppVar_83172;
	cppVar_83173 = (cppVar_83173 & cppMask_un_8_);
	bool cppVar_83175 = (cppVar_83173 == 208);
	if (cppVar_83175) {
	cppVar_83170 = PSW;
	} else {
	BIT_VEC cppVar_83176;
	BIT_VEC cppVar_83177 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83178 = (cppVar_83177 << 3) | 1;
	cppVar_83178 = (cppVar_83178 & cppMask_un_5_);
	BIT_VEC cppVar_83179 = (0 << 5) | cppVar_83178;
	cppVar_83179 = (cppVar_83179 & cppMask_un_8_);
	bool cppVar_83181 = (cppVar_83179 == 224);
	if (cppVar_83181) {
	cppVar_83176 = ACC;
	} else {
	BIT_VEC cppVar_83182;
	BIT_VEC cppVar_83183 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83184 = (cppVar_83183 << 3) | 1;
	cppVar_83184 = (cppVar_83184 & cppMask_un_5_);
	BIT_VEC cppVar_83185 = (0 << 5) | cppVar_83184;
	cppVar_83185 = (cppVar_83185 & cppMask_un_8_);
	bool cppVar_83187 = (cppVar_83185 == 240);
	if (cppVar_83187) {
	cppVar_83182 = B;
	} else {
	cppVar_83182 = 0;
	}
	cppVar_83176 = cppVar_83182;
	}
	cppVar_83170 = cppVar_83176;
	}
	cppVar_83164 = cppVar_83170;
	}
	cppVar_83158 = cppVar_83164;
	}
	cppVar_83152 = cppVar_83158;
	}
	cppVar_83146 = cppVar_83152;
	}
	cppVar_83140 = cppVar_83146;
	}
	cppVar_83134 = cppVar_83140;
	}
	cppVar_83128 = cppVar_83134;
	}
	cppVar_83122 = cppVar_83128;
	}
	cppVar_83116 = cppVar_83122;
	}
	cppVar_83110 = cppVar_83116;
	}
	cppVar_83104 = cppVar_83110;
	}
	cppVar_83098 = cppVar_83104;
	}
	cppVar_83092 = cppVar_83098;
	}
	cppVar_83086 = cppVar_83092;
	}
	cppVar_83080 = cppVar_83086;
	}
	cppVar_83074 = cppVar_83080;
	}
	cppVar_83068 = cppVar_83074;
	}
	cppVar_83062 = cppVar_83068;
	}
	cppVar_83049 = cppVar_83062;
	}
	cppVar_83043 = cppVar_83049;
	} else {
	cppVar_83043 = TMOD;
	}
	cppVar_83039 = cppVar_83043;
	} else {
	BIT_VEC cppVar_83189;
	BIT_VEC cppVar_83190 = ROM.rd(PC);
	bool cppVar_83192 = (cppVar_83190 == 136);
	if (cppVar_83192) {
	BIT_VEC cppVar_83193;
	BIT_VEC cppVar_83195 = PC + 1;
	cppVar_83195 = (cppVar_83195 & cppMask_un_16_);
	BIT_VEC cppVar_83196 = ROM.rd(cppVar_83195);
	bool cppVar_83198 = (cppVar_83196 == 137);
	if (cppVar_83198) {
	BIT_VEC cppVar_83199;
	BIT_VEC cppVar_83201 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83203 = (cppVar_83201 << 3) | 0;
	cppVar_83203 = (cppVar_83203 & cppMask_un_5_);
	BIT_VEC cppVar_83204 = (0 << 5) | cppVar_83203;
	cppVar_83204 = (cppVar_83204 & cppMask_un_8_);
	BIT_VEC cppVar_83205 = (cppVar_83204 >> 7) & cppMask_un_1_;
	bool cppVar_83207 = (cppVar_83205 == 0);
	if (cppVar_83207) {
	BIT_VEC cppVar_83208 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83209 = (cppVar_83208 << 3) | 0;
	cppVar_83209 = (cppVar_83209 & cppMask_un_5_);
	BIT_VEC cppVar_83210 = (0 << 5) | cppVar_83209;
	cppVar_83210 = (cppVar_83210 & cppMask_un_8_);
	BIT_VEC cppVar_83211 = IRAM.rd(cppVar_83210);
	cppVar_83199 = cppVar_83211;
	} else {
	BIT_VEC cppVar_83212;
	BIT_VEC cppVar_83213 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83214 = (cppVar_83213 << 3) | 0;
	cppVar_83214 = (cppVar_83214 & cppMask_un_5_);
	BIT_VEC cppVar_83215 = (0 << 5) | cppVar_83214;
	cppVar_83215 = (cppVar_83215 & cppMask_un_8_);
	bool cppVar_83217 = (cppVar_83215 == 128);
	if (cppVar_83217) {
	cppVar_83212 = P0;
	} else {
	BIT_VEC cppVar_83218;
	BIT_VEC cppVar_83219 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83220 = (cppVar_83219 << 3) | 0;
	cppVar_83220 = (cppVar_83220 & cppMask_un_5_);
	BIT_VEC cppVar_83221 = (0 << 5) | cppVar_83220;
	cppVar_83221 = (cppVar_83221 & cppMask_un_8_);
	bool cppVar_83223 = (cppVar_83221 == 129);
	if (cppVar_83223) {
	cppVar_83218 = SP;
	} else {
	BIT_VEC cppVar_83224;
	BIT_VEC cppVar_83225 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83226 = (cppVar_83225 << 3) | 0;
	cppVar_83226 = (cppVar_83226 & cppMask_un_5_);
	BIT_VEC cppVar_83227 = (0 << 5) | cppVar_83226;
	cppVar_83227 = (cppVar_83227 & cppMask_un_8_);
	bool cppVar_83229 = (cppVar_83227 == 130);
	if (cppVar_83229) {
	cppVar_83224 = DPL;
	} else {
	BIT_VEC cppVar_83230;
	BIT_VEC cppVar_83231 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83232 = (cppVar_83231 << 3) | 0;
	cppVar_83232 = (cppVar_83232 & cppMask_un_5_);
	BIT_VEC cppVar_83233 = (0 << 5) | cppVar_83232;
	cppVar_83233 = (cppVar_83233 & cppMask_un_8_);
	bool cppVar_83235 = (cppVar_83233 == 131);
	if (cppVar_83235) {
	cppVar_83230 = DPH;
	} else {
	BIT_VEC cppVar_83236;
	BIT_VEC cppVar_83237 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83238 = (cppVar_83237 << 3) | 0;
	cppVar_83238 = (cppVar_83238 & cppMask_un_5_);
	BIT_VEC cppVar_83239 = (0 << 5) | cppVar_83238;
	cppVar_83239 = (cppVar_83239 & cppMask_un_8_);
	bool cppVar_83241 = (cppVar_83239 == 135);
	if (cppVar_83241) {
	cppVar_83236 = PCON;
	} else {
	BIT_VEC cppVar_83242;
	BIT_VEC cppVar_83243 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83244 = (cppVar_83243 << 3) | 0;
	cppVar_83244 = (cppVar_83244 & cppMask_un_5_);
	BIT_VEC cppVar_83245 = (0 << 5) | cppVar_83244;
	cppVar_83245 = (cppVar_83245 & cppMask_un_8_);
	bool cppVar_83247 = (cppVar_83245 == 136);
	if (cppVar_83247) {
	cppVar_83242 = TCON;
	} else {
	BIT_VEC cppVar_83248;
	BIT_VEC cppVar_83249 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83250 = (cppVar_83249 << 3) | 0;
	cppVar_83250 = (cppVar_83250 & cppMask_un_5_);
	BIT_VEC cppVar_83251 = (0 << 5) | cppVar_83250;
	cppVar_83251 = (cppVar_83251 & cppMask_un_8_);
	bool cppVar_83253 = (cppVar_83251 == 137);
	if (cppVar_83253) {
	cppVar_83248 = TMOD;
	} else {
	BIT_VEC cppVar_83254;
	BIT_VEC cppVar_83255 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83256 = (cppVar_83255 << 3) | 0;
	cppVar_83256 = (cppVar_83256 & cppMask_un_5_);
	BIT_VEC cppVar_83257 = (0 << 5) | cppVar_83256;
	cppVar_83257 = (cppVar_83257 & cppMask_un_8_);
	bool cppVar_83259 = (cppVar_83257 == 138);
	if (cppVar_83259) {
	cppVar_83254 = TL0;
	} else {
	BIT_VEC cppVar_83260;
	BIT_VEC cppVar_83261 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83262 = (cppVar_83261 << 3) | 0;
	cppVar_83262 = (cppVar_83262 & cppMask_un_5_);
	BIT_VEC cppVar_83263 = (0 << 5) | cppVar_83262;
	cppVar_83263 = (cppVar_83263 & cppMask_un_8_);
	bool cppVar_83265 = (cppVar_83263 == 140);
	if (cppVar_83265) {
	cppVar_83260 = TH0;
	} else {
	BIT_VEC cppVar_83266;
	BIT_VEC cppVar_83267 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83268 = (cppVar_83267 << 3) | 0;
	cppVar_83268 = (cppVar_83268 & cppMask_un_5_);
	BIT_VEC cppVar_83269 = (0 << 5) | cppVar_83268;
	cppVar_83269 = (cppVar_83269 & cppMask_un_8_);
	bool cppVar_83271 = (cppVar_83269 == 139);
	if (cppVar_83271) {
	cppVar_83266 = TL1;
	} else {
	BIT_VEC cppVar_83272;
	BIT_VEC cppVar_83273 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83274 = (cppVar_83273 << 3) | 0;
	cppVar_83274 = (cppVar_83274 & cppMask_un_5_);
	BIT_VEC cppVar_83275 = (0 << 5) | cppVar_83274;
	cppVar_83275 = (cppVar_83275 & cppMask_un_8_);
	bool cppVar_83277 = (cppVar_83275 == 141);
	if (cppVar_83277) {
	cppVar_83272 = TH1;
	} else {
	BIT_VEC cppVar_83278;
	BIT_VEC cppVar_83279 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83280 = (cppVar_83279 << 3) | 0;
	cppVar_83280 = (cppVar_83280 & cppMask_un_5_);
	BIT_VEC cppVar_83281 = (0 << 5) | cppVar_83280;
	cppVar_83281 = (cppVar_83281 & cppMask_un_8_);
	bool cppVar_83283 = (cppVar_83281 == 144);
	if (cppVar_83283) {
	cppVar_83278 = P1;
	} else {
	BIT_VEC cppVar_83284;
	BIT_VEC cppVar_83285 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83286 = (cppVar_83285 << 3) | 0;
	cppVar_83286 = (cppVar_83286 & cppMask_un_5_);
	BIT_VEC cppVar_83287 = (0 << 5) | cppVar_83286;
	cppVar_83287 = (cppVar_83287 & cppMask_un_8_);
	bool cppVar_83289 = (cppVar_83287 == 152);
	if (cppVar_83289) {
	cppVar_83284 = SCON;
	} else {
	BIT_VEC cppVar_83290;
	BIT_VEC cppVar_83291 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83292 = (cppVar_83291 << 3) | 0;
	cppVar_83292 = (cppVar_83292 & cppMask_un_5_);
	BIT_VEC cppVar_83293 = (0 << 5) | cppVar_83292;
	cppVar_83293 = (cppVar_83293 & cppMask_un_8_);
	bool cppVar_83295 = (cppVar_83293 == 153);
	if (cppVar_83295) {
	cppVar_83290 = SBUF;
	} else {
	BIT_VEC cppVar_83296;
	BIT_VEC cppVar_83297 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83298 = (cppVar_83297 << 3) | 0;
	cppVar_83298 = (cppVar_83298 & cppMask_un_5_);
	BIT_VEC cppVar_83299 = (0 << 5) | cppVar_83298;
	cppVar_83299 = (cppVar_83299 & cppMask_un_8_);
	bool cppVar_83301 = (cppVar_83299 == 160);
	if (cppVar_83301) {
	cppVar_83296 = P2;
	} else {
	BIT_VEC cppVar_83302;
	BIT_VEC cppVar_83303 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83304 = (cppVar_83303 << 3) | 0;
	cppVar_83304 = (cppVar_83304 & cppMask_un_5_);
	BIT_VEC cppVar_83305 = (0 << 5) | cppVar_83304;
	cppVar_83305 = (cppVar_83305 & cppMask_un_8_);
	bool cppVar_83307 = (cppVar_83305 == 168);
	if (cppVar_83307) {
	cppVar_83302 = IE;
	} else {
	BIT_VEC cppVar_83308;
	BIT_VEC cppVar_83309 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83310 = (cppVar_83309 << 3) | 0;
	cppVar_83310 = (cppVar_83310 & cppMask_un_5_);
	BIT_VEC cppVar_83311 = (0 << 5) | cppVar_83310;
	cppVar_83311 = (cppVar_83311 & cppMask_un_8_);
	bool cppVar_83313 = (cppVar_83311 == 176);
	if (cppVar_83313) {
	cppVar_83308 = P3;
	} else {
	BIT_VEC cppVar_83314;
	BIT_VEC cppVar_83315 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83316 = (cppVar_83315 << 3) | 0;
	cppVar_83316 = (cppVar_83316 & cppMask_un_5_);
	BIT_VEC cppVar_83317 = (0 << 5) | cppVar_83316;
	cppVar_83317 = (cppVar_83317 & cppMask_un_8_);
	bool cppVar_83319 = (cppVar_83317 == 184);
	if (cppVar_83319) {
	cppVar_83314 = IP;
	} else {
	BIT_VEC cppVar_83320;
	BIT_VEC cppVar_83321 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83322 = (cppVar_83321 << 3) | 0;
	cppVar_83322 = (cppVar_83322 & cppMask_un_5_);
	BIT_VEC cppVar_83323 = (0 << 5) | cppVar_83322;
	cppVar_83323 = (cppVar_83323 & cppMask_un_8_);
	bool cppVar_83325 = (cppVar_83323 == 208);
	if (cppVar_83325) {
	cppVar_83320 = PSW;
	} else {
	BIT_VEC cppVar_83326;
	BIT_VEC cppVar_83327 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83328 = (cppVar_83327 << 3) | 0;
	cppVar_83328 = (cppVar_83328 & cppMask_un_5_);
	BIT_VEC cppVar_83329 = (0 << 5) | cppVar_83328;
	cppVar_83329 = (cppVar_83329 & cppMask_un_8_);
	bool cppVar_83331 = (cppVar_83329 == 224);
	if (cppVar_83331) {
	cppVar_83326 = ACC;
	} else {
	BIT_VEC cppVar_83332;
	BIT_VEC cppVar_83333 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83334 = (cppVar_83333 << 3) | 0;
	cppVar_83334 = (cppVar_83334 & cppMask_un_5_);
	BIT_VEC cppVar_83335 = (0 << 5) | cppVar_83334;
	cppVar_83335 = (cppVar_83335 & cppMask_un_8_);
	bool cppVar_83337 = (cppVar_83335 == 240);
	if (cppVar_83337) {
	cppVar_83332 = B;
	} else {
	cppVar_83332 = 0;
	}
	cppVar_83326 = cppVar_83332;
	}
	cppVar_83320 = cppVar_83326;
	}
	cppVar_83314 = cppVar_83320;
	}
	cppVar_83308 = cppVar_83314;
	}
	cppVar_83302 = cppVar_83308;
	}
	cppVar_83296 = cppVar_83302;
	}
	cppVar_83290 = cppVar_83296;
	}
	cppVar_83284 = cppVar_83290;
	}
	cppVar_83278 = cppVar_83284;
	}
	cppVar_83272 = cppVar_83278;
	}
	cppVar_83266 = cppVar_83272;
	}
	cppVar_83260 = cppVar_83266;
	}
	cppVar_83254 = cppVar_83260;
	}
	cppVar_83248 = cppVar_83254;
	}
	cppVar_83242 = cppVar_83248;
	}
	cppVar_83236 = cppVar_83242;
	}
	cppVar_83230 = cppVar_83236;
	}
	cppVar_83224 = cppVar_83230;
	}
	cppVar_83218 = cppVar_83224;
	}
	cppVar_83212 = cppVar_83218;
	}
	cppVar_83199 = cppVar_83212;
	}
	cppVar_83193 = cppVar_83199;
	} else {
	cppVar_83193 = TMOD;
	}
	cppVar_83189 = cppVar_83193;
	} else {
	BIT_VEC cppVar_83339;
	BIT_VEC cppVar_83340 = ROM.rd(PC);
	bool cppVar_83342 = (cppVar_83340 == 135);
	if (cppVar_83342) {
	BIT_VEC cppVar_83343;
	BIT_VEC cppVar_83345 = PC + 1;
	cppVar_83345 = (cppVar_83345 & cppMask_un_16_);
	BIT_VEC cppVar_83346 = ROM.rd(cppVar_83345);
	bool cppVar_83348 = (cppVar_83346 == 137);
	if (cppVar_83348) {
	BIT_VEC cppVar_83350 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83352 = (cppVar_83350 << 3) | 1;
	cppVar_83352 = (cppVar_83352 & cppMask_un_5_);
	BIT_VEC cppVar_83353 = (0 << 5) | cppVar_83352;
	cppVar_83353 = (cppVar_83353 & cppMask_un_8_);
	BIT_VEC cppVar_83354 = IRAM.rd(cppVar_83353);
	BIT_VEC cppVar_83355 = IRAM.rd(cppVar_83354);
	cppVar_83343 = cppVar_83355;
	} else {
	cppVar_83343 = TMOD;
	}
	cppVar_83339 = cppVar_83343;
	} else {
	BIT_VEC cppVar_83356;
	BIT_VEC cppVar_83357 = ROM.rd(PC);
	bool cppVar_83359 = (cppVar_83357 == 134);
	if (cppVar_83359) {
	BIT_VEC cppVar_83360;
	BIT_VEC cppVar_83362 = PC + 1;
	cppVar_83362 = (cppVar_83362 & cppMask_un_16_);
	BIT_VEC cppVar_83363 = ROM.rd(cppVar_83362);
	bool cppVar_83365 = (cppVar_83363 == 137);
	if (cppVar_83365) {
	BIT_VEC cppVar_83367 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_83369 = (cppVar_83367 << 3) | 0;
	cppVar_83369 = (cppVar_83369 & cppMask_un_5_);
	BIT_VEC cppVar_83370 = (0 << 5) | cppVar_83369;
	cppVar_83370 = (cppVar_83370 & cppMask_un_8_);
	BIT_VEC cppVar_83371 = IRAM.rd(cppVar_83370);
	BIT_VEC cppVar_83372 = IRAM.rd(cppVar_83371);
	cppVar_83360 = cppVar_83372;
	} else {
	cppVar_83360 = TMOD;
	}
	cppVar_83356 = cppVar_83360;
	} else {
	BIT_VEC cppVar_83373;
	BIT_VEC cppVar_83374 = ROM.rd(PC);
	bool cppVar_83376 = (cppVar_83374 == 133);
	if (cppVar_83376) {
	BIT_VEC cppVar_83377;
	BIT_VEC cppVar_83379 = PC + 2;
	cppVar_83379 = (cppVar_83379 & cppMask_un_16_);
	BIT_VEC cppVar_83380 = ROM.rd(cppVar_83379);
	bool cppVar_83382 = (cppVar_83380 == 137);
	if (cppVar_83382) {
	BIT_VEC cppVar_83383;
	BIT_VEC cppVar_83385 = PC + 1;
	cppVar_83385 = (cppVar_83385 & cppMask_un_16_);
	BIT_VEC cppVar_83386 = ROM.rd(cppVar_83385);
	BIT_VEC cppVar_83387 = (cppVar_83386 >> 7) & cppMask_un_1_;
	bool cppVar_83389 = (cppVar_83387 == 0);
	if (cppVar_83389) {
	BIT_VEC cppVar_83390 = PC + 1;
	cppVar_83390 = (cppVar_83390 & cppMask_un_16_);
	BIT_VEC cppVar_83391 = ROM.rd(cppVar_83390);
	BIT_VEC cppVar_83392 = IRAM.rd(cppVar_83391);
	cppVar_83383 = cppVar_83392;
	} else {
	BIT_VEC cppVar_83393;
	BIT_VEC cppVar_83394 = PC + 1;
	cppVar_83394 = (cppVar_83394 & cppMask_un_16_);
	BIT_VEC cppVar_83395 = ROM.rd(cppVar_83394);
	bool cppVar_83397 = (cppVar_83395 == 128);
	if (cppVar_83397) {
	cppVar_83393 = P0;
	} else {
	BIT_VEC cppVar_83398;
	BIT_VEC cppVar_83399 = PC + 1;
	cppVar_83399 = (cppVar_83399 & cppMask_un_16_);
	BIT_VEC cppVar_83400 = ROM.rd(cppVar_83399);
	bool cppVar_83402 = (cppVar_83400 == 129);
	if (cppVar_83402) {
	cppVar_83398 = SP;
	} else {
	BIT_VEC cppVar_83403;
	BIT_VEC cppVar_83404 = PC + 1;
	cppVar_83404 = (cppVar_83404 & cppMask_un_16_);
	BIT_VEC cppVar_83405 = ROM.rd(cppVar_83404);
	bool cppVar_83407 = (cppVar_83405 == 130);
	if (cppVar_83407) {
	cppVar_83403 = DPL;
	} else {
	BIT_VEC cppVar_83408;
	BIT_VEC cppVar_83409 = PC + 1;
	cppVar_83409 = (cppVar_83409 & cppMask_un_16_);
	BIT_VEC cppVar_83410 = ROM.rd(cppVar_83409);
	bool cppVar_83412 = (cppVar_83410 == 131);
	if (cppVar_83412) {
	cppVar_83408 = DPH;
	} else {
	BIT_VEC cppVar_83413;
	BIT_VEC cppVar_83414 = PC + 1;
	cppVar_83414 = (cppVar_83414 & cppMask_un_16_);
	BIT_VEC cppVar_83415 = ROM.rd(cppVar_83414);
	bool cppVar_83417 = (cppVar_83415 == 135);
	if (cppVar_83417) {
	cppVar_83413 = PCON;
	} else {
	BIT_VEC cppVar_83418;
	BIT_VEC cppVar_83419 = PC + 1;
	cppVar_83419 = (cppVar_83419 & cppMask_un_16_);
	BIT_VEC cppVar_83420 = ROM.rd(cppVar_83419);
	bool cppVar_83422 = (cppVar_83420 == 136);
	if (cppVar_83422) {
	cppVar_83418 = TCON;
	} else {
	BIT_VEC cppVar_83423;
	BIT_VEC cppVar_83424 = PC + 1;
	cppVar_83424 = (cppVar_83424 & cppMask_un_16_);
	BIT_VEC cppVar_83425 = ROM.rd(cppVar_83424);
	bool cppVar_83427 = (cppVar_83425 == 137);
	if (cppVar_83427) {
	cppVar_83423 = TMOD;
	} else {
	BIT_VEC cppVar_83428;
	BIT_VEC cppVar_83429 = PC + 1;
	cppVar_83429 = (cppVar_83429 & cppMask_un_16_);
	BIT_VEC cppVar_83430 = ROM.rd(cppVar_83429);
	bool cppVar_83432 = (cppVar_83430 == 138);
	if (cppVar_83432) {
	cppVar_83428 = TL0;
	} else {
	BIT_VEC cppVar_83433;
	BIT_VEC cppVar_83434 = PC + 1;
	cppVar_83434 = (cppVar_83434 & cppMask_un_16_);
	BIT_VEC cppVar_83435 = ROM.rd(cppVar_83434);
	bool cppVar_83437 = (cppVar_83435 == 140);
	if (cppVar_83437) {
	cppVar_83433 = TH0;
	} else {
	BIT_VEC cppVar_83438;
	BIT_VEC cppVar_83439 = PC + 1;
	cppVar_83439 = (cppVar_83439 & cppMask_un_16_);
	BIT_VEC cppVar_83440 = ROM.rd(cppVar_83439);
	bool cppVar_83442 = (cppVar_83440 == 139);
	if (cppVar_83442) {
	cppVar_83438 = TL1;
	} else {
	BIT_VEC cppVar_83443;
	BIT_VEC cppVar_83444 = PC + 1;
	cppVar_83444 = (cppVar_83444 & cppMask_un_16_);
	BIT_VEC cppVar_83445 = ROM.rd(cppVar_83444);
	bool cppVar_83447 = (cppVar_83445 == 141);
	if (cppVar_83447) {
	cppVar_83443 = TH1;
	} else {
	BIT_VEC cppVar_83448;
	BIT_VEC cppVar_83449 = PC + 1;
	cppVar_83449 = (cppVar_83449 & cppMask_un_16_);
	BIT_VEC cppVar_83450 = ROM.rd(cppVar_83449);
	bool cppVar_83452 = (cppVar_83450 == 144);
	if (cppVar_83452) {
	cppVar_83448 = P1;
	} else {
	BIT_VEC cppVar_83453;
	BIT_VEC cppVar_83454 = PC + 1;
	cppVar_83454 = (cppVar_83454 & cppMask_un_16_);
	BIT_VEC cppVar_83455 = ROM.rd(cppVar_83454);
	bool cppVar_83457 = (cppVar_83455 == 152);
	if (cppVar_83457) {
	cppVar_83453 = SCON;
	} else {
	BIT_VEC cppVar_83458;
	BIT_VEC cppVar_83459 = PC + 1;
	cppVar_83459 = (cppVar_83459 & cppMask_un_16_);
	BIT_VEC cppVar_83460 = ROM.rd(cppVar_83459);
	bool cppVar_83462 = (cppVar_83460 == 153);
	if (cppVar_83462) {
	cppVar_83458 = SBUF;
	} else {
	BIT_VEC cppVar_83463;
	BIT_VEC cppVar_83464 = PC + 1;
	cppVar_83464 = (cppVar_83464 & cppMask_un_16_);
	BIT_VEC cppVar_83465 = ROM.rd(cppVar_83464);
	bool cppVar_83467 = (cppVar_83465 == 160);
	if (cppVar_83467) {
	cppVar_83463 = P2;
	} else {
	BIT_VEC cppVar_83468;
	BIT_VEC cppVar_83469 = PC + 1;
	cppVar_83469 = (cppVar_83469 & cppMask_un_16_);
	BIT_VEC cppVar_83470 = ROM.rd(cppVar_83469);
	bool cppVar_83472 = (cppVar_83470 == 168);
	if (cppVar_83472) {
	cppVar_83468 = IE;
	} else {
	BIT_VEC cppVar_83473;
	BIT_VEC cppVar_83474 = PC + 1;
	cppVar_83474 = (cppVar_83474 & cppMask_un_16_);
	BIT_VEC cppVar_83475 = ROM.rd(cppVar_83474);
	bool cppVar_83477 = (cppVar_83475 == 176);
	if (cppVar_83477) {
	cppVar_83473 = P3;
	} else {
	BIT_VEC cppVar_83478;
	BIT_VEC cppVar_83479 = PC + 1;
	cppVar_83479 = (cppVar_83479 & cppMask_un_16_);
	BIT_VEC cppVar_83480 = ROM.rd(cppVar_83479);
	bool cppVar_83482 = (cppVar_83480 == 184);
	if (cppVar_83482) {
	cppVar_83478 = IP;
	} else {
	BIT_VEC cppVar_83483;
	BIT_VEC cppVar_83484 = PC + 1;
	cppVar_83484 = (cppVar_83484 & cppMask_un_16_);
	BIT_VEC cppVar_83485 = ROM.rd(cppVar_83484);
	bool cppVar_83487 = (cppVar_83485 == 208);
	if (cppVar_83487) {
	cppVar_83483 = PSW;
	} else {
	BIT_VEC cppVar_83488;
	BIT_VEC cppVar_83489 = PC + 1;
	cppVar_83489 = (cppVar_83489 & cppMask_un_16_);
	BIT_VEC cppVar_83490 = ROM.rd(cppVar_83489);
	bool cppVar_83492 = (cppVar_83490 == 224);
	if (cppVar_83492) {
	cppVar_83488 = ACC;
	} else {
	BIT_VEC cppVar_83493;
	BIT_VEC cppVar_83494 = PC + 1;
	cppVar_83494 = (cppVar_83494 & cppMask_un_16_);
	BIT_VEC cppVar_83495 = ROM.rd(cppVar_83494);
	bool cppVar_83497 = (cppVar_83495 == 240);
	if (cppVar_83497) {
	cppVar_83493 = B;
	} else {
	cppVar_83493 = 0;
	}
	cppVar_83488 = cppVar_83493;
	}
	cppVar_83483 = cppVar_83488;
	}
	cppVar_83478 = cppVar_83483;
	}
	cppVar_83473 = cppVar_83478;
	}
	cppVar_83468 = cppVar_83473;
	}
	cppVar_83463 = cppVar_83468;
	}
	cppVar_83458 = cppVar_83463;
	}
	cppVar_83453 = cppVar_83458;
	}
	cppVar_83448 = cppVar_83453;
	}
	cppVar_83443 = cppVar_83448;
	}
	cppVar_83438 = cppVar_83443;
	}
	cppVar_83433 = cppVar_83438;
	}
	cppVar_83428 = cppVar_83433;
	}
	cppVar_83423 = cppVar_83428;
	}
	cppVar_83418 = cppVar_83423;
	}
	cppVar_83413 = cppVar_83418;
	}
	cppVar_83408 = cppVar_83413;
	}
	cppVar_83403 = cppVar_83408;
	}
	cppVar_83398 = cppVar_83403;
	}
	cppVar_83393 = cppVar_83398;
	}
	cppVar_83383 = cppVar_83393;
	}
	cppVar_83377 = cppVar_83383;
	} else {
	cppVar_83377 = TMOD;
	}
	cppVar_83373 = cppVar_83377;
	} else {
	BIT_VEC cppVar_83499;
	BIT_VEC cppVar_83500 = ROM.rd(PC);
	bool cppVar_83502 = (cppVar_83500 == 117);
	if (cppVar_83502) {
	BIT_VEC cppVar_83503;
	BIT_VEC cppVar_83505 = PC + 1;
	cppVar_83505 = (cppVar_83505 & cppMask_un_16_);
	BIT_VEC cppVar_83506 = ROM.rd(cppVar_83505);
	bool cppVar_83508 = (cppVar_83506 == 137);
	if (cppVar_83508) {
	BIT_VEC cppVar_83510 = PC + 2;
	cppVar_83510 = (cppVar_83510 & cppMask_un_16_);
	BIT_VEC cppVar_83511 = ROM.rd(cppVar_83510);
	cppVar_83503 = cppVar_83511;
	} else {
	cppVar_83503 = TMOD;
	}
	cppVar_83499 = cppVar_83503;
	} else {
	BIT_VEC cppVar_83512;
	BIT_VEC cppVar_83513 = ROM.rd(PC);
	bool cppVar_83515 = (cppVar_83513 == 99);
	if (cppVar_83515) {
	BIT_VEC cppVar_83516;
	BIT_VEC cppVar_83518 = PC + 1;
	cppVar_83518 = (cppVar_83518 & cppMask_un_16_);
	BIT_VEC cppVar_83519 = ROM.rd(cppVar_83518);
	bool cppVar_83521 = (cppVar_83519 == 137);
	if (cppVar_83521) {
	BIT_VEC cppVar_83522;
	BIT_VEC cppVar_83523 = PC + 1;
	cppVar_83523 = (cppVar_83523 & cppMask_un_16_);
	BIT_VEC cppVar_83524 = ROM.rd(cppVar_83523);
	BIT_VEC cppVar_83525 = (cppVar_83524 >> 7) & cppMask_un_1_;
	bool cppVar_83527 = (cppVar_83525 == 0);
	if (cppVar_83527) {
	BIT_VEC cppVar_83528 = PC + 1;
	cppVar_83528 = (cppVar_83528 & cppMask_un_16_);
	BIT_VEC cppVar_83529 = ROM.rd(cppVar_83528);
	BIT_VEC cppVar_83530 = IRAM.rd(cppVar_83529);
	cppVar_83522 = cppVar_83530;
	} else {
	BIT_VEC cppVar_83531;
	BIT_VEC cppVar_83532 = PC + 1;
	cppVar_83532 = (cppVar_83532 & cppMask_un_16_);
	BIT_VEC cppVar_83533 = ROM.rd(cppVar_83532);
	bool cppVar_83535 = (cppVar_83533 == 128);
	if (cppVar_83535) {
	cppVar_83531 = P0;
	} else {
	BIT_VEC cppVar_83536;
	BIT_VEC cppVar_83537 = PC + 1;
	cppVar_83537 = (cppVar_83537 & cppMask_un_16_);
	BIT_VEC cppVar_83538 = ROM.rd(cppVar_83537);
	bool cppVar_83540 = (cppVar_83538 == 129);
	if (cppVar_83540) {
	cppVar_83536 = SP;
	} else {
	BIT_VEC cppVar_83541;
	BIT_VEC cppVar_83542 = PC + 1;
	cppVar_83542 = (cppVar_83542 & cppMask_un_16_);
	BIT_VEC cppVar_83543 = ROM.rd(cppVar_83542);
	bool cppVar_83545 = (cppVar_83543 == 130);
	if (cppVar_83545) {
	cppVar_83541 = DPL;
	} else {
	BIT_VEC cppVar_83546;
	BIT_VEC cppVar_83547 = PC + 1;
	cppVar_83547 = (cppVar_83547 & cppMask_un_16_);
	BIT_VEC cppVar_83548 = ROM.rd(cppVar_83547);
	bool cppVar_83550 = (cppVar_83548 == 131);
	if (cppVar_83550) {
	cppVar_83546 = DPH;
	} else {
	BIT_VEC cppVar_83551;
	BIT_VEC cppVar_83552 = PC + 1;
	cppVar_83552 = (cppVar_83552 & cppMask_un_16_);
	BIT_VEC cppVar_83553 = ROM.rd(cppVar_83552);
	bool cppVar_83555 = (cppVar_83553 == 135);
	if (cppVar_83555) {
	cppVar_83551 = PCON;
	} else {
	BIT_VEC cppVar_83556;
	BIT_VEC cppVar_83557 = PC + 1;
	cppVar_83557 = (cppVar_83557 & cppMask_un_16_);
	BIT_VEC cppVar_83558 = ROM.rd(cppVar_83557);
	bool cppVar_83560 = (cppVar_83558 == 136);
	if (cppVar_83560) {
	cppVar_83556 = TCON;
	} else {
	BIT_VEC cppVar_83561;
	BIT_VEC cppVar_83562 = PC + 1;
	cppVar_83562 = (cppVar_83562 & cppMask_un_16_);
	BIT_VEC cppVar_83563 = ROM.rd(cppVar_83562);
	bool cppVar_83565 = (cppVar_83563 == 137);
	if (cppVar_83565) {
	cppVar_83561 = TMOD;
	} else {
	BIT_VEC cppVar_83566;
	BIT_VEC cppVar_83567 = PC + 1;
	cppVar_83567 = (cppVar_83567 & cppMask_un_16_);
	BIT_VEC cppVar_83568 = ROM.rd(cppVar_83567);
	bool cppVar_83570 = (cppVar_83568 == 138);
	if (cppVar_83570) {
	cppVar_83566 = TL0;
	} else {
	BIT_VEC cppVar_83571;
	BIT_VEC cppVar_83572 = PC + 1;
	cppVar_83572 = (cppVar_83572 & cppMask_un_16_);
	BIT_VEC cppVar_83573 = ROM.rd(cppVar_83572);
	bool cppVar_83575 = (cppVar_83573 == 140);
	if (cppVar_83575) {
	cppVar_83571 = TH0;
	} else {
	BIT_VEC cppVar_83576;
	BIT_VEC cppVar_83577 = PC + 1;
	cppVar_83577 = (cppVar_83577 & cppMask_un_16_);
	BIT_VEC cppVar_83578 = ROM.rd(cppVar_83577);
	bool cppVar_83580 = (cppVar_83578 == 139);
	if (cppVar_83580) {
	cppVar_83576 = TL1;
	} else {
	BIT_VEC cppVar_83581;
	BIT_VEC cppVar_83582 = PC + 1;
	cppVar_83582 = (cppVar_83582 & cppMask_un_16_);
	BIT_VEC cppVar_83583 = ROM.rd(cppVar_83582);
	bool cppVar_83585 = (cppVar_83583 == 141);
	if (cppVar_83585) {
	cppVar_83581 = TH1;
	} else {
	BIT_VEC cppVar_83586;
	BIT_VEC cppVar_83587 = PC + 1;
	cppVar_83587 = (cppVar_83587 & cppMask_un_16_);
	BIT_VEC cppVar_83588 = ROM.rd(cppVar_83587);
	bool cppVar_83590 = (cppVar_83588 == 144);
	if (cppVar_83590) {
	cppVar_83586 = P1;
	} else {
	BIT_VEC cppVar_83591;
	BIT_VEC cppVar_83592 = PC + 1;
	cppVar_83592 = (cppVar_83592 & cppMask_un_16_);
	BIT_VEC cppVar_83593 = ROM.rd(cppVar_83592);
	bool cppVar_83595 = (cppVar_83593 == 152);
	if (cppVar_83595) {
	cppVar_83591 = SCON;
	} else {
	BIT_VEC cppVar_83596;
	BIT_VEC cppVar_83597 = PC + 1;
	cppVar_83597 = (cppVar_83597 & cppMask_un_16_);
	BIT_VEC cppVar_83598 = ROM.rd(cppVar_83597);
	bool cppVar_83600 = (cppVar_83598 == 153);
	if (cppVar_83600) {
	cppVar_83596 = SBUF;
	} else {
	BIT_VEC cppVar_83601;
	BIT_VEC cppVar_83602 = PC + 1;
	cppVar_83602 = (cppVar_83602 & cppMask_un_16_);
	BIT_VEC cppVar_83603 = ROM.rd(cppVar_83602);
	bool cppVar_83605 = (cppVar_83603 == 160);
	if (cppVar_83605) {
	cppVar_83601 = P2;
	} else {
	BIT_VEC cppVar_83606;
	BIT_VEC cppVar_83607 = PC + 1;
	cppVar_83607 = (cppVar_83607 & cppMask_un_16_);
	BIT_VEC cppVar_83608 = ROM.rd(cppVar_83607);
	bool cppVar_83610 = (cppVar_83608 == 168);
	if (cppVar_83610) {
	cppVar_83606 = IE;
	} else {
	BIT_VEC cppVar_83611;
	BIT_VEC cppVar_83612 = PC + 1;
	cppVar_83612 = (cppVar_83612 & cppMask_un_16_);
	BIT_VEC cppVar_83613 = ROM.rd(cppVar_83612);
	bool cppVar_83615 = (cppVar_83613 == 176);
	if (cppVar_83615) {
	cppVar_83611 = P3;
	} else {
	BIT_VEC cppVar_83616;
	BIT_VEC cppVar_83617 = PC + 1;
	cppVar_83617 = (cppVar_83617 & cppMask_un_16_);
	BIT_VEC cppVar_83618 = ROM.rd(cppVar_83617);
	bool cppVar_83620 = (cppVar_83618 == 184);
	if (cppVar_83620) {
	cppVar_83616 = IP;
	} else {
	BIT_VEC cppVar_83621;
	BIT_VEC cppVar_83622 = PC + 1;
	cppVar_83622 = (cppVar_83622 & cppMask_un_16_);
	BIT_VEC cppVar_83623 = ROM.rd(cppVar_83622);
	bool cppVar_83625 = (cppVar_83623 == 208);
	if (cppVar_83625) {
	cppVar_83621 = PSW;
	} else {
	BIT_VEC cppVar_83626;
	BIT_VEC cppVar_83627 = PC + 1;
	cppVar_83627 = (cppVar_83627 & cppMask_un_16_);
	BIT_VEC cppVar_83628 = ROM.rd(cppVar_83627);
	bool cppVar_83630 = (cppVar_83628 == 224);
	if (cppVar_83630) {
	cppVar_83626 = ACC;
	} else {
	BIT_VEC cppVar_83631;
	BIT_VEC cppVar_83632 = PC + 1;
	cppVar_83632 = (cppVar_83632 & cppMask_un_16_);
	BIT_VEC cppVar_83633 = ROM.rd(cppVar_83632);
	bool cppVar_83635 = (cppVar_83633 == 240);
	if (cppVar_83635) {
	cppVar_83631 = B;
	} else {
	cppVar_83631 = 0;
	}
	cppVar_83626 = cppVar_83631;
	}
	cppVar_83621 = cppVar_83626;
	}
	cppVar_83616 = cppVar_83621;
	}
	cppVar_83611 = cppVar_83616;
	}
	cppVar_83606 = cppVar_83611;
	}
	cppVar_83601 = cppVar_83606;
	}
	cppVar_83596 = cppVar_83601;
	}
	cppVar_83591 = cppVar_83596;
	}
	cppVar_83586 = cppVar_83591;
	}
	cppVar_83581 = cppVar_83586;
	}
	cppVar_83576 = cppVar_83581;
	}
	cppVar_83571 = cppVar_83576;
	}
	cppVar_83566 = cppVar_83571;
	}
	cppVar_83561 = cppVar_83566;
	}
	cppVar_83556 = cppVar_83561;
	}
	cppVar_83551 = cppVar_83556;
	}
	cppVar_83546 = cppVar_83551;
	}
	cppVar_83541 = cppVar_83546;
	}
	cppVar_83536 = cppVar_83541;
	}
	cppVar_83531 = cppVar_83536;
	}
	cppVar_83522 = cppVar_83531;
	}
	BIT_VEC cppVar_83638 = PC + 2;
	cppVar_83638 = (cppVar_83638 & cppMask_un_16_);
	BIT_VEC cppVar_83639 = ROM.rd(cppVar_83638);
	BIT_VEC cppVar_83640 = cppVar_83522 ^ cppVar_83639;
	cppVar_83516 = cppVar_83640;
	} else {
	cppVar_83516 = TMOD;
	}
	cppVar_83512 = cppVar_83516;
	} else {
	BIT_VEC cppVar_83641;
	BIT_VEC cppVar_83642 = ROM.rd(PC);
	bool cppVar_83644 = (cppVar_83642 == 98);
	if (cppVar_83644) {
	BIT_VEC cppVar_83645;
	BIT_VEC cppVar_83647 = PC + 1;
	cppVar_83647 = (cppVar_83647 & cppMask_un_16_);
	BIT_VEC cppVar_83648 = ROM.rd(cppVar_83647);
	bool cppVar_83650 = (cppVar_83648 == 137);
	if (cppVar_83650) {
	BIT_VEC cppVar_83651;
	BIT_VEC cppVar_83652 = PC + 1;
	cppVar_83652 = (cppVar_83652 & cppMask_un_16_);
	BIT_VEC cppVar_83653 = ROM.rd(cppVar_83652);
	BIT_VEC cppVar_83654 = (cppVar_83653 >> 7) & cppMask_un_1_;
	bool cppVar_83656 = (cppVar_83654 == 0);
	if (cppVar_83656) {
	BIT_VEC cppVar_83657 = PC + 1;
	cppVar_83657 = (cppVar_83657 & cppMask_un_16_);
	BIT_VEC cppVar_83658 = ROM.rd(cppVar_83657);
	BIT_VEC cppVar_83659 = IRAM.rd(cppVar_83658);
	cppVar_83651 = cppVar_83659;
	} else {
	BIT_VEC cppVar_83660;
	BIT_VEC cppVar_83661 = PC + 1;
	cppVar_83661 = (cppVar_83661 & cppMask_un_16_);
	BIT_VEC cppVar_83662 = ROM.rd(cppVar_83661);
	bool cppVar_83664 = (cppVar_83662 == 128);
	if (cppVar_83664) {
	cppVar_83660 = P0;
	} else {
	BIT_VEC cppVar_83665;
	BIT_VEC cppVar_83666 = PC + 1;
	cppVar_83666 = (cppVar_83666 & cppMask_un_16_);
	BIT_VEC cppVar_83667 = ROM.rd(cppVar_83666);
	bool cppVar_83669 = (cppVar_83667 == 129);
	if (cppVar_83669) {
	cppVar_83665 = SP;
	} else {
	BIT_VEC cppVar_83670;
	BIT_VEC cppVar_83671 = PC + 1;
	cppVar_83671 = (cppVar_83671 & cppMask_un_16_);
	BIT_VEC cppVar_83672 = ROM.rd(cppVar_83671);
	bool cppVar_83674 = (cppVar_83672 == 130);
	if (cppVar_83674) {
	cppVar_83670 = DPL;
	} else {
	BIT_VEC cppVar_83675;
	BIT_VEC cppVar_83676 = PC + 1;
	cppVar_83676 = (cppVar_83676 & cppMask_un_16_);
	BIT_VEC cppVar_83677 = ROM.rd(cppVar_83676);
	bool cppVar_83679 = (cppVar_83677 == 131);
	if (cppVar_83679) {
	cppVar_83675 = DPH;
	} else {
	BIT_VEC cppVar_83680;
	BIT_VEC cppVar_83681 = PC + 1;
	cppVar_83681 = (cppVar_83681 & cppMask_un_16_);
	BIT_VEC cppVar_83682 = ROM.rd(cppVar_83681);
	bool cppVar_83684 = (cppVar_83682 == 135);
	if (cppVar_83684) {
	cppVar_83680 = PCON;
	} else {
	BIT_VEC cppVar_83685;
	BIT_VEC cppVar_83686 = PC + 1;
	cppVar_83686 = (cppVar_83686 & cppMask_un_16_);
	BIT_VEC cppVar_83687 = ROM.rd(cppVar_83686);
	bool cppVar_83689 = (cppVar_83687 == 136);
	if (cppVar_83689) {
	cppVar_83685 = TCON;
	} else {
	BIT_VEC cppVar_83690;
	BIT_VEC cppVar_83691 = PC + 1;
	cppVar_83691 = (cppVar_83691 & cppMask_un_16_);
	BIT_VEC cppVar_83692 = ROM.rd(cppVar_83691);
	bool cppVar_83694 = (cppVar_83692 == 137);
	if (cppVar_83694) {
	cppVar_83690 = TMOD;
	} else {
	BIT_VEC cppVar_83695;
	BIT_VEC cppVar_83696 = PC + 1;
	cppVar_83696 = (cppVar_83696 & cppMask_un_16_);
	BIT_VEC cppVar_83697 = ROM.rd(cppVar_83696);
	bool cppVar_83699 = (cppVar_83697 == 138);
	if (cppVar_83699) {
	cppVar_83695 = TL0;
	} else {
	BIT_VEC cppVar_83700;
	BIT_VEC cppVar_83701 = PC + 1;
	cppVar_83701 = (cppVar_83701 & cppMask_un_16_);
	BIT_VEC cppVar_83702 = ROM.rd(cppVar_83701);
	bool cppVar_83704 = (cppVar_83702 == 140);
	if (cppVar_83704) {
	cppVar_83700 = TH0;
	} else {
	BIT_VEC cppVar_83705;
	BIT_VEC cppVar_83706 = PC + 1;
	cppVar_83706 = (cppVar_83706 & cppMask_un_16_);
	BIT_VEC cppVar_83707 = ROM.rd(cppVar_83706);
	bool cppVar_83709 = (cppVar_83707 == 139);
	if (cppVar_83709) {
	cppVar_83705 = TL1;
	} else {
	BIT_VEC cppVar_83710;
	BIT_VEC cppVar_83711 = PC + 1;
	cppVar_83711 = (cppVar_83711 & cppMask_un_16_);
	BIT_VEC cppVar_83712 = ROM.rd(cppVar_83711);
	bool cppVar_83714 = (cppVar_83712 == 141);
	if (cppVar_83714) {
	cppVar_83710 = TH1;
	} else {
	BIT_VEC cppVar_83715;
	BIT_VEC cppVar_83716 = PC + 1;
	cppVar_83716 = (cppVar_83716 & cppMask_un_16_);
	BIT_VEC cppVar_83717 = ROM.rd(cppVar_83716);
	bool cppVar_83719 = (cppVar_83717 == 144);
	if (cppVar_83719) {
	cppVar_83715 = P1;
	} else {
	BIT_VEC cppVar_83720;
	BIT_VEC cppVar_83721 = PC + 1;
	cppVar_83721 = (cppVar_83721 & cppMask_un_16_);
	BIT_VEC cppVar_83722 = ROM.rd(cppVar_83721);
	bool cppVar_83724 = (cppVar_83722 == 152);
	if (cppVar_83724) {
	cppVar_83720 = SCON;
	} else {
	BIT_VEC cppVar_83725;
	BIT_VEC cppVar_83726 = PC + 1;
	cppVar_83726 = (cppVar_83726 & cppMask_un_16_);
	BIT_VEC cppVar_83727 = ROM.rd(cppVar_83726);
	bool cppVar_83729 = (cppVar_83727 == 153);
	if (cppVar_83729) {
	cppVar_83725 = SBUF;
	} else {
	BIT_VEC cppVar_83730;
	BIT_VEC cppVar_83731 = PC + 1;
	cppVar_83731 = (cppVar_83731 & cppMask_un_16_);
	BIT_VEC cppVar_83732 = ROM.rd(cppVar_83731);
	bool cppVar_83734 = (cppVar_83732 == 160);
	if (cppVar_83734) {
	cppVar_83730 = P2;
	} else {
	BIT_VEC cppVar_83735;
	BIT_VEC cppVar_83736 = PC + 1;
	cppVar_83736 = (cppVar_83736 & cppMask_un_16_);
	BIT_VEC cppVar_83737 = ROM.rd(cppVar_83736);
	bool cppVar_83739 = (cppVar_83737 == 168);
	if (cppVar_83739) {
	cppVar_83735 = IE;
	} else {
	BIT_VEC cppVar_83740;
	BIT_VEC cppVar_83741 = PC + 1;
	cppVar_83741 = (cppVar_83741 & cppMask_un_16_);
	BIT_VEC cppVar_83742 = ROM.rd(cppVar_83741);
	bool cppVar_83744 = (cppVar_83742 == 176);
	if (cppVar_83744) {
	cppVar_83740 = P3;
	} else {
	BIT_VEC cppVar_83745;
	BIT_VEC cppVar_83746 = PC + 1;
	cppVar_83746 = (cppVar_83746 & cppMask_un_16_);
	BIT_VEC cppVar_83747 = ROM.rd(cppVar_83746);
	bool cppVar_83749 = (cppVar_83747 == 184);
	if (cppVar_83749) {
	cppVar_83745 = IP;
	} else {
	BIT_VEC cppVar_83750;
	BIT_VEC cppVar_83751 = PC + 1;
	cppVar_83751 = (cppVar_83751 & cppMask_un_16_);
	BIT_VEC cppVar_83752 = ROM.rd(cppVar_83751);
	bool cppVar_83754 = (cppVar_83752 == 208);
	if (cppVar_83754) {
	cppVar_83750 = PSW;
	} else {
	BIT_VEC cppVar_83755;
	BIT_VEC cppVar_83756 = PC + 1;
	cppVar_83756 = (cppVar_83756 & cppMask_un_16_);
	BIT_VEC cppVar_83757 = ROM.rd(cppVar_83756);
	bool cppVar_83759 = (cppVar_83757 == 224);
	if (cppVar_83759) {
	cppVar_83755 = ACC;
	} else {
	BIT_VEC cppVar_83760;
	BIT_VEC cppVar_83761 = PC + 1;
	cppVar_83761 = (cppVar_83761 & cppMask_un_16_);
	BIT_VEC cppVar_83762 = ROM.rd(cppVar_83761);
	bool cppVar_83764 = (cppVar_83762 == 240);
	if (cppVar_83764) {
	cppVar_83760 = B;
	} else {
	cppVar_83760 = 0;
	}
	cppVar_83755 = cppVar_83760;
	}
	cppVar_83750 = cppVar_83755;
	}
	cppVar_83745 = cppVar_83750;
	}
	cppVar_83740 = cppVar_83745;
	}
	cppVar_83735 = cppVar_83740;
	}
	cppVar_83730 = cppVar_83735;
	}
	cppVar_83725 = cppVar_83730;
	}
	cppVar_83720 = cppVar_83725;
	}
	cppVar_83715 = cppVar_83720;
	}
	cppVar_83710 = cppVar_83715;
	}
	cppVar_83705 = cppVar_83710;
	}
	cppVar_83700 = cppVar_83705;
	}
	cppVar_83695 = cppVar_83700;
	}
	cppVar_83690 = cppVar_83695;
	}
	cppVar_83685 = cppVar_83690;
	}
	cppVar_83680 = cppVar_83685;
	}
	cppVar_83675 = cppVar_83680;
	}
	cppVar_83670 = cppVar_83675;
	}
	cppVar_83665 = cppVar_83670;
	}
	cppVar_83660 = cppVar_83665;
	}
	cppVar_83651 = cppVar_83660;
	}
	BIT_VEC cppVar_83766 = cppVar_83651 ^ ACC;
	cppVar_83645 = cppVar_83766;
	} else {
	cppVar_83645 = TMOD;
	}
	cppVar_83641 = cppVar_83645;
	} else {
	BIT_VEC cppVar_83767;
	BIT_VEC cppVar_83768 = ROM.rd(PC);
	bool cppVar_83770 = (cppVar_83768 == 83);
	if (cppVar_83770) {
	BIT_VEC cppVar_83771;
	BIT_VEC cppVar_83773 = PC + 1;
	cppVar_83773 = (cppVar_83773 & cppMask_un_16_);
	BIT_VEC cppVar_83774 = ROM.rd(cppVar_83773);
	bool cppVar_83776 = (cppVar_83774 == 137);
	if (cppVar_83776) {
	BIT_VEC cppVar_83777;
	BIT_VEC cppVar_83778 = PC + 1;
	cppVar_83778 = (cppVar_83778 & cppMask_un_16_);
	BIT_VEC cppVar_83779 = ROM.rd(cppVar_83778);
	BIT_VEC cppVar_83780 = (cppVar_83779 >> 7) & cppMask_un_1_;
	bool cppVar_83782 = (cppVar_83780 == 0);
	if (cppVar_83782) {
	BIT_VEC cppVar_83783 = PC + 1;
	cppVar_83783 = (cppVar_83783 & cppMask_un_16_);
	BIT_VEC cppVar_83784 = ROM.rd(cppVar_83783);
	BIT_VEC cppVar_83785 = IRAM.rd(cppVar_83784);
	cppVar_83777 = cppVar_83785;
	} else {
	BIT_VEC cppVar_83786;
	BIT_VEC cppVar_83787 = PC + 1;
	cppVar_83787 = (cppVar_83787 & cppMask_un_16_);
	BIT_VEC cppVar_83788 = ROM.rd(cppVar_83787);
	bool cppVar_83790 = (cppVar_83788 == 128);
	if (cppVar_83790) {
	cppVar_83786 = P0;
	} else {
	BIT_VEC cppVar_83791;
	BIT_VEC cppVar_83792 = PC + 1;
	cppVar_83792 = (cppVar_83792 & cppMask_un_16_);
	BIT_VEC cppVar_83793 = ROM.rd(cppVar_83792);
	bool cppVar_83795 = (cppVar_83793 == 129);
	if (cppVar_83795) {
	cppVar_83791 = SP;
	} else {
	BIT_VEC cppVar_83796;
	BIT_VEC cppVar_83797 = PC + 1;
	cppVar_83797 = (cppVar_83797 & cppMask_un_16_);
	BIT_VEC cppVar_83798 = ROM.rd(cppVar_83797);
	bool cppVar_83800 = (cppVar_83798 == 130);
	if (cppVar_83800) {
	cppVar_83796 = DPL;
	} else {
	BIT_VEC cppVar_83801;
	BIT_VEC cppVar_83802 = PC + 1;
	cppVar_83802 = (cppVar_83802 & cppMask_un_16_);
	BIT_VEC cppVar_83803 = ROM.rd(cppVar_83802);
	bool cppVar_83805 = (cppVar_83803 == 131);
	if (cppVar_83805) {
	cppVar_83801 = DPH;
	} else {
	BIT_VEC cppVar_83806;
	BIT_VEC cppVar_83807 = PC + 1;
	cppVar_83807 = (cppVar_83807 & cppMask_un_16_);
	BIT_VEC cppVar_83808 = ROM.rd(cppVar_83807);
	bool cppVar_83810 = (cppVar_83808 == 135);
	if (cppVar_83810) {
	cppVar_83806 = PCON;
	} else {
	BIT_VEC cppVar_83811;
	BIT_VEC cppVar_83812 = PC + 1;
	cppVar_83812 = (cppVar_83812 & cppMask_un_16_);
	BIT_VEC cppVar_83813 = ROM.rd(cppVar_83812);
	bool cppVar_83815 = (cppVar_83813 == 136);
	if (cppVar_83815) {
	cppVar_83811 = TCON;
	} else {
	BIT_VEC cppVar_83816;
	BIT_VEC cppVar_83817 = PC + 1;
	cppVar_83817 = (cppVar_83817 & cppMask_un_16_);
	BIT_VEC cppVar_83818 = ROM.rd(cppVar_83817);
	bool cppVar_83820 = (cppVar_83818 == 137);
	if (cppVar_83820) {
	cppVar_83816 = TMOD;
	} else {
	BIT_VEC cppVar_83821;
	BIT_VEC cppVar_83822 = PC + 1;
	cppVar_83822 = (cppVar_83822 & cppMask_un_16_);
	BIT_VEC cppVar_83823 = ROM.rd(cppVar_83822);
	bool cppVar_83825 = (cppVar_83823 == 138);
	if (cppVar_83825) {
	cppVar_83821 = TL0;
	} else {
	BIT_VEC cppVar_83826;
	BIT_VEC cppVar_83827 = PC + 1;
	cppVar_83827 = (cppVar_83827 & cppMask_un_16_);
	BIT_VEC cppVar_83828 = ROM.rd(cppVar_83827);
	bool cppVar_83830 = (cppVar_83828 == 140);
	if (cppVar_83830) {
	cppVar_83826 = TH0;
	} else {
	BIT_VEC cppVar_83831;
	BIT_VEC cppVar_83832 = PC + 1;
	cppVar_83832 = (cppVar_83832 & cppMask_un_16_);
	BIT_VEC cppVar_83833 = ROM.rd(cppVar_83832);
	bool cppVar_83835 = (cppVar_83833 == 139);
	if (cppVar_83835) {
	cppVar_83831 = TL1;
	} else {
	BIT_VEC cppVar_83836;
	BIT_VEC cppVar_83837 = PC + 1;
	cppVar_83837 = (cppVar_83837 & cppMask_un_16_);
	BIT_VEC cppVar_83838 = ROM.rd(cppVar_83837);
	bool cppVar_83840 = (cppVar_83838 == 141);
	if (cppVar_83840) {
	cppVar_83836 = TH1;
	} else {
	BIT_VEC cppVar_83841;
	BIT_VEC cppVar_83842 = PC + 1;
	cppVar_83842 = (cppVar_83842 & cppMask_un_16_);
	BIT_VEC cppVar_83843 = ROM.rd(cppVar_83842);
	bool cppVar_83845 = (cppVar_83843 == 144);
	if (cppVar_83845) {
	cppVar_83841 = P1;
	} else {
	BIT_VEC cppVar_83846;
	BIT_VEC cppVar_83847 = PC + 1;
	cppVar_83847 = (cppVar_83847 & cppMask_un_16_);
	BIT_VEC cppVar_83848 = ROM.rd(cppVar_83847);
	bool cppVar_83850 = (cppVar_83848 == 152);
	if (cppVar_83850) {
	cppVar_83846 = SCON;
	} else {
	BIT_VEC cppVar_83851;
	BIT_VEC cppVar_83852 = PC + 1;
	cppVar_83852 = (cppVar_83852 & cppMask_un_16_);
	BIT_VEC cppVar_83853 = ROM.rd(cppVar_83852);
	bool cppVar_83855 = (cppVar_83853 == 153);
	if (cppVar_83855) {
	cppVar_83851 = SBUF;
	} else {
	BIT_VEC cppVar_83856;
	BIT_VEC cppVar_83857 = PC + 1;
	cppVar_83857 = (cppVar_83857 & cppMask_un_16_);
	BIT_VEC cppVar_83858 = ROM.rd(cppVar_83857);
	bool cppVar_83860 = (cppVar_83858 == 160);
	if (cppVar_83860) {
	cppVar_83856 = P2;
	} else {
	BIT_VEC cppVar_83861;
	BIT_VEC cppVar_83862 = PC + 1;
	cppVar_83862 = (cppVar_83862 & cppMask_un_16_);
	BIT_VEC cppVar_83863 = ROM.rd(cppVar_83862);
	bool cppVar_83865 = (cppVar_83863 == 168);
	if (cppVar_83865) {
	cppVar_83861 = IE;
	} else {
	BIT_VEC cppVar_83866;
	BIT_VEC cppVar_83867 = PC + 1;
	cppVar_83867 = (cppVar_83867 & cppMask_un_16_);
	BIT_VEC cppVar_83868 = ROM.rd(cppVar_83867);
	bool cppVar_83870 = (cppVar_83868 == 176);
	if (cppVar_83870) {
	cppVar_83866 = P3;
	} else {
	BIT_VEC cppVar_83871;
	BIT_VEC cppVar_83872 = PC + 1;
	cppVar_83872 = (cppVar_83872 & cppMask_un_16_);
	BIT_VEC cppVar_83873 = ROM.rd(cppVar_83872);
	bool cppVar_83875 = (cppVar_83873 == 184);
	if (cppVar_83875) {
	cppVar_83871 = IP;
	} else {
	BIT_VEC cppVar_83876;
	BIT_VEC cppVar_83877 = PC + 1;
	cppVar_83877 = (cppVar_83877 & cppMask_un_16_);
	BIT_VEC cppVar_83878 = ROM.rd(cppVar_83877);
	bool cppVar_83880 = (cppVar_83878 == 208);
	if (cppVar_83880) {
	cppVar_83876 = PSW;
	} else {
	BIT_VEC cppVar_83881;
	BIT_VEC cppVar_83882 = PC + 1;
	cppVar_83882 = (cppVar_83882 & cppMask_un_16_);
	BIT_VEC cppVar_83883 = ROM.rd(cppVar_83882);
	bool cppVar_83885 = (cppVar_83883 == 224);
	if (cppVar_83885) {
	cppVar_83881 = ACC;
	} else {
	BIT_VEC cppVar_83886;
	BIT_VEC cppVar_83887 = PC + 1;
	cppVar_83887 = (cppVar_83887 & cppMask_un_16_);
	BIT_VEC cppVar_83888 = ROM.rd(cppVar_83887);
	bool cppVar_83890 = (cppVar_83888 == 240);
	if (cppVar_83890) {
	cppVar_83886 = B;
	} else {
	cppVar_83886 = 0;
	}
	cppVar_83881 = cppVar_83886;
	}
	cppVar_83876 = cppVar_83881;
	}
	cppVar_83871 = cppVar_83876;
	}
	cppVar_83866 = cppVar_83871;
	}
	cppVar_83861 = cppVar_83866;
	}
	cppVar_83856 = cppVar_83861;
	}
	cppVar_83851 = cppVar_83856;
	}
	cppVar_83846 = cppVar_83851;
	}
	cppVar_83841 = cppVar_83846;
	}
	cppVar_83836 = cppVar_83841;
	}
	cppVar_83831 = cppVar_83836;
	}
	cppVar_83826 = cppVar_83831;
	}
	cppVar_83821 = cppVar_83826;
	}
	cppVar_83816 = cppVar_83821;
	}
	cppVar_83811 = cppVar_83816;
	}
	cppVar_83806 = cppVar_83811;
	}
	cppVar_83801 = cppVar_83806;
	}
	cppVar_83796 = cppVar_83801;
	}
	cppVar_83791 = cppVar_83796;
	}
	cppVar_83786 = cppVar_83791;
	}
	cppVar_83777 = cppVar_83786;
	}
	BIT_VEC cppVar_83893 = PC + 2;
	cppVar_83893 = (cppVar_83893 & cppMask_un_16_);
	BIT_VEC cppVar_83894 = ROM.rd(cppVar_83893);
	BIT_VEC cppVar_83895 = cppVar_83777 & cppVar_83894;
	cppVar_83771 = cppVar_83895;
	} else {
	cppVar_83771 = TMOD;
	}
	cppVar_83767 = cppVar_83771;
	} else {
	BIT_VEC cppVar_83896;
	BIT_VEC cppVar_83897 = ROM.rd(PC);
	bool cppVar_83899 = (cppVar_83897 == 82);
	if (cppVar_83899) {
	BIT_VEC cppVar_83900;
	BIT_VEC cppVar_83902 = PC + 1;
	cppVar_83902 = (cppVar_83902 & cppMask_un_16_);
	BIT_VEC cppVar_83903 = ROM.rd(cppVar_83902);
	bool cppVar_83905 = (cppVar_83903 == 137);
	if (cppVar_83905) {
	BIT_VEC cppVar_83906;
	BIT_VEC cppVar_83907 = PC + 1;
	cppVar_83907 = (cppVar_83907 & cppMask_un_16_);
	BIT_VEC cppVar_83908 = ROM.rd(cppVar_83907);
	BIT_VEC cppVar_83909 = (cppVar_83908 >> 7) & cppMask_un_1_;
	bool cppVar_83911 = (cppVar_83909 == 0);
	if (cppVar_83911) {
	BIT_VEC cppVar_83912 = PC + 1;
	cppVar_83912 = (cppVar_83912 & cppMask_un_16_);
	BIT_VEC cppVar_83913 = ROM.rd(cppVar_83912);
	BIT_VEC cppVar_83914 = IRAM.rd(cppVar_83913);
	cppVar_83906 = cppVar_83914;
	} else {
	BIT_VEC cppVar_83915;
	BIT_VEC cppVar_83916 = PC + 1;
	cppVar_83916 = (cppVar_83916 & cppMask_un_16_);
	BIT_VEC cppVar_83917 = ROM.rd(cppVar_83916);
	bool cppVar_83919 = (cppVar_83917 == 128);
	if (cppVar_83919) {
	cppVar_83915 = P0;
	} else {
	BIT_VEC cppVar_83920;
	BIT_VEC cppVar_83921 = PC + 1;
	cppVar_83921 = (cppVar_83921 & cppMask_un_16_);
	BIT_VEC cppVar_83922 = ROM.rd(cppVar_83921);
	bool cppVar_83924 = (cppVar_83922 == 129);
	if (cppVar_83924) {
	cppVar_83920 = SP;
	} else {
	BIT_VEC cppVar_83925;
	BIT_VEC cppVar_83926 = PC + 1;
	cppVar_83926 = (cppVar_83926 & cppMask_un_16_);
	BIT_VEC cppVar_83927 = ROM.rd(cppVar_83926);
	bool cppVar_83929 = (cppVar_83927 == 130);
	if (cppVar_83929) {
	cppVar_83925 = DPL;
	} else {
	BIT_VEC cppVar_83930;
	BIT_VEC cppVar_83931 = PC + 1;
	cppVar_83931 = (cppVar_83931 & cppMask_un_16_);
	BIT_VEC cppVar_83932 = ROM.rd(cppVar_83931);
	bool cppVar_83934 = (cppVar_83932 == 131);
	if (cppVar_83934) {
	cppVar_83930 = DPH;
	} else {
	BIT_VEC cppVar_83935;
	BIT_VEC cppVar_83936 = PC + 1;
	cppVar_83936 = (cppVar_83936 & cppMask_un_16_);
	BIT_VEC cppVar_83937 = ROM.rd(cppVar_83936);
	bool cppVar_83939 = (cppVar_83937 == 135);
	if (cppVar_83939) {
	cppVar_83935 = PCON;
	} else {
	BIT_VEC cppVar_83940;
	BIT_VEC cppVar_83941 = PC + 1;
	cppVar_83941 = (cppVar_83941 & cppMask_un_16_);
	BIT_VEC cppVar_83942 = ROM.rd(cppVar_83941);
	bool cppVar_83944 = (cppVar_83942 == 136);
	if (cppVar_83944) {
	cppVar_83940 = TCON;
	} else {
	BIT_VEC cppVar_83945;
	BIT_VEC cppVar_83946 = PC + 1;
	cppVar_83946 = (cppVar_83946 & cppMask_un_16_);
	BIT_VEC cppVar_83947 = ROM.rd(cppVar_83946);
	bool cppVar_83949 = (cppVar_83947 == 137);
	if (cppVar_83949) {
	cppVar_83945 = TMOD;
	} else {
	BIT_VEC cppVar_83950;
	BIT_VEC cppVar_83951 = PC + 1;
	cppVar_83951 = (cppVar_83951 & cppMask_un_16_);
	BIT_VEC cppVar_83952 = ROM.rd(cppVar_83951);
	bool cppVar_83954 = (cppVar_83952 == 138);
	if (cppVar_83954) {
	cppVar_83950 = TL0;
	} else {
	BIT_VEC cppVar_83955;
	BIT_VEC cppVar_83956 = PC + 1;
	cppVar_83956 = (cppVar_83956 & cppMask_un_16_);
	BIT_VEC cppVar_83957 = ROM.rd(cppVar_83956);
	bool cppVar_83959 = (cppVar_83957 == 140);
	if (cppVar_83959) {
	cppVar_83955 = TH0;
	} else {
	BIT_VEC cppVar_83960;
	BIT_VEC cppVar_83961 = PC + 1;
	cppVar_83961 = (cppVar_83961 & cppMask_un_16_);
	BIT_VEC cppVar_83962 = ROM.rd(cppVar_83961);
	bool cppVar_83964 = (cppVar_83962 == 139);
	if (cppVar_83964) {
	cppVar_83960 = TL1;
	} else {
	BIT_VEC cppVar_83965;
	BIT_VEC cppVar_83966 = PC + 1;
	cppVar_83966 = (cppVar_83966 & cppMask_un_16_);
	BIT_VEC cppVar_83967 = ROM.rd(cppVar_83966);
	bool cppVar_83969 = (cppVar_83967 == 141);
	if (cppVar_83969) {
	cppVar_83965 = TH1;
	} else {
	BIT_VEC cppVar_83970;
	BIT_VEC cppVar_83971 = PC + 1;
	cppVar_83971 = (cppVar_83971 & cppMask_un_16_);
	BIT_VEC cppVar_83972 = ROM.rd(cppVar_83971);
	bool cppVar_83974 = (cppVar_83972 == 144);
	if (cppVar_83974) {
	cppVar_83970 = P1;
	} else {
	BIT_VEC cppVar_83975;
	BIT_VEC cppVar_83976 = PC + 1;
	cppVar_83976 = (cppVar_83976 & cppMask_un_16_);
	BIT_VEC cppVar_83977 = ROM.rd(cppVar_83976);
	bool cppVar_83979 = (cppVar_83977 == 152);
	if (cppVar_83979) {
	cppVar_83975 = SCON;
	} else {
	BIT_VEC cppVar_83980;
	BIT_VEC cppVar_83981 = PC + 1;
	cppVar_83981 = (cppVar_83981 & cppMask_un_16_);
	BIT_VEC cppVar_83982 = ROM.rd(cppVar_83981);
	bool cppVar_83984 = (cppVar_83982 == 153);
	if (cppVar_83984) {
	cppVar_83980 = SBUF;
	} else {
	BIT_VEC cppVar_83985;
	BIT_VEC cppVar_83986 = PC + 1;
	cppVar_83986 = (cppVar_83986 & cppMask_un_16_);
	BIT_VEC cppVar_83987 = ROM.rd(cppVar_83986);
	bool cppVar_83989 = (cppVar_83987 == 160);
	if (cppVar_83989) {
	cppVar_83985 = P2;
	} else {
	BIT_VEC cppVar_83990;
	BIT_VEC cppVar_83991 = PC + 1;
	cppVar_83991 = (cppVar_83991 & cppMask_un_16_);
	BIT_VEC cppVar_83992 = ROM.rd(cppVar_83991);
	bool cppVar_83994 = (cppVar_83992 == 168);
	if (cppVar_83994) {
	cppVar_83990 = IE;
	} else {
	BIT_VEC cppVar_83995;
	BIT_VEC cppVar_83996 = PC + 1;
	cppVar_83996 = (cppVar_83996 & cppMask_un_16_);
	BIT_VEC cppVar_83997 = ROM.rd(cppVar_83996);
	bool cppVar_83999 = (cppVar_83997 == 176);
	if (cppVar_83999) {
	cppVar_83995 = P3;
	} else {
	BIT_VEC cppVar_84000;
	BIT_VEC cppVar_84001 = PC + 1;
	cppVar_84001 = (cppVar_84001 & cppMask_un_16_);
	BIT_VEC cppVar_84002 = ROM.rd(cppVar_84001);
	bool cppVar_84004 = (cppVar_84002 == 184);
	if (cppVar_84004) {
	cppVar_84000 = IP;
	} else {
	BIT_VEC cppVar_84005;
	BIT_VEC cppVar_84006 = PC + 1;
	cppVar_84006 = (cppVar_84006 & cppMask_un_16_);
	BIT_VEC cppVar_84007 = ROM.rd(cppVar_84006);
	bool cppVar_84009 = (cppVar_84007 == 208);
	if (cppVar_84009) {
	cppVar_84005 = PSW;
	} else {
	BIT_VEC cppVar_84010;
	BIT_VEC cppVar_84011 = PC + 1;
	cppVar_84011 = (cppVar_84011 & cppMask_un_16_);
	BIT_VEC cppVar_84012 = ROM.rd(cppVar_84011);
	bool cppVar_84014 = (cppVar_84012 == 224);
	if (cppVar_84014) {
	cppVar_84010 = ACC;
	} else {
	BIT_VEC cppVar_84015;
	BIT_VEC cppVar_84016 = PC + 1;
	cppVar_84016 = (cppVar_84016 & cppMask_un_16_);
	BIT_VEC cppVar_84017 = ROM.rd(cppVar_84016);
	bool cppVar_84019 = (cppVar_84017 == 240);
	if (cppVar_84019) {
	cppVar_84015 = B;
	} else {
	cppVar_84015 = 0;
	}
	cppVar_84010 = cppVar_84015;
	}
	cppVar_84005 = cppVar_84010;
	}
	cppVar_84000 = cppVar_84005;
	}
	cppVar_83995 = cppVar_84000;
	}
	cppVar_83990 = cppVar_83995;
	}
	cppVar_83985 = cppVar_83990;
	}
	cppVar_83980 = cppVar_83985;
	}
	cppVar_83975 = cppVar_83980;
	}
	cppVar_83970 = cppVar_83975;
	}
	cppVar_83965 = cppVar_83970;
	}
	cppVar_83960 = cppVar_83965;
	}
	cppVar_83955 = cppVar_83960;
	}
	cppVar_83950 = cppVar_83955;
	}
	cppVar_83945 = cppVar_83950;
	}
	cppVar_83940 = cppVar_83945;
	}
	cppVar_83935 = cppVar_83940;
	}
	cppVar_83930 = cppVar_83935;
	}
	cppVar_83925 = cppVar_83930;
	}
	cppVar_83920 = cppVar_83925;
	}
	cppVar_83915 = cppVar_83920;
	}
	cppVar_83906 = cppVar_83915;
	}
	BIT_VEC cppVar_84021 = cppVar_83906 & ACC;
	cppVar_83900 = cppVar_84021;
	} else {
	cppVar_83900 = TMOD;
	}
	cppVar_83896 = cppVar_83900;
	} else {
	BIT_VEC cppVar_84022;
	BIT_VEC cppVar_84023 = ROM.rd(PC);
	bool cppVar_84025 = (cppVar_84023 == 67);
	if (cppVar_84025) {
	BIT_VEC cppVar_84026;
	BIT_VEC cppVar_84028 = PC + 1;
	cppVar_84028 = (cppVar_84028 & cppMask_un_16_);
	BIT_VEC cppVar_84029 = ROM.rd(cppVar_84028);
	bool cppVar_84031 = (cppVar_84029 == 137);
	if (cppVar_84031) {
	BIT_VEC cppVar_84032;
	BIT_VEC cppVar_84033 = PC + 1;
	cppVar_84033 = (cppVar_84033 & cppMask_un_16_);
	BIT_VEC cppVar_84034 = ROM.rd(cppVar_84033);
	BIT_VEC cppVar_84035 = (cppVar_84034 >> 7) & cppMask_un_1_;
	bool cppVar_84037 = (cppVar_84035 == 0);
	if (cppVar_84037) {
	BIT_VEC cppVar_84038 = PC + 1;
	cppVar_84038 = (cppVar_84038 & cppMask_un_16_);
	BIT_VEC cppVar_84039 = ROM.rd(cppVar_84038);
	BIT_VEC cppVar_84040 = IRAM.rd(cppVar_84039);
	cppVar_84032 = cppVar_84040;
	} else {
	BIT_VEC cppVar_84041;
	BIT_VEC cppVar_84042 = PC + 1;
	cppVar_84042 = (cppVar_84042 & cppMask_un_16_);
	BIT_VEC cppVar_84043 = ROM.rd(cppVar_84042);
	bool cppVar_84045 = (cppVar_84043 == 128);
	if (cppVar_84045) {
	cppVar_84041 = P0;
	} else {
	BIT_VEC cppVar_84046;
	BIT_VEC cppVar_84047 = PC + 1;
	cppVar_84047 = (cppVar_84047 & cppMask_un_16_);
	BIT_VEC cppVar_84048 = ROM.rd(cppVar_84047);
	bool cppVar_84050 = (cppVar_84048 == 129);
	if (cppVar_84050) {
	cppVar_84046 = SP;
	} else {
	BIT_VEC cppVar_84051;
	BIT_VEC cppVar_84052 = PC + 1;
	cppVar_84052 = (cppVar_84052 & cppMask_un_16_);
	BIT_VEC cppVar_84053 = ROM.rd(cppVar_84052);
	bool cppVar_84055 = (cppVar_84053 == 130);
	if (cppVar_84055) {
	cppVar_84051 = DPL;
	} else {
	BIT_VEC cppVar_84056;
	BIT_VEC cppVar_84057 = PC + 1;
	cppVar_84057 = (cppVar_84057 & cppMask_un_16_);
	BIT_VEC cppVar_84058 = ROM.rd(cppVar_84057);
	bool cppVar_84060 = (cppVar_84058 == 131);
	if (cppVar_84060) {
	cppVar_84056 = DPH;
	} else {
	BIT_VEC cppVar_84061;
	BIT_VEC cppVar_84062 = PC + 1;
	cppVar_84062 = (cppVar_84062 & cppMask_un_16_);
	BIT_VEC cppVar_84063 = ROM.rd(cppVar_84062);
	bool cppVar_84065 = (cppVar_84063 == 135);
	if (cppVar_84065) {
	cppVar_84061 = PCON;
	} else {
	BIT_VEC cppVar_84066;
	BIT_VEC cppVar_84067 = PC + 1;
	cppVar_84067 = (cppVar_84067 & cppMask_un_16_);
	BIT_VEC cppVar_84068 = ROM.rd(cppVar_84067);
	bool cppVar_84070 = (cppVar_84068 == 136);
	if (cppVar_84070) {
	cppVar_84066 = TCON;
	} else {
	BIT_VEC cppVar_84071;
	BIT_VEC cppVar_84072 = PC + 1;
	cppVar_84072 = (cppVar_84072 & cppMask_un_16_);
	BIT_VEC cppVar_84073 = ROM.rd(cppVar_84072);
	bool cppVar_84075 = (cppVar_84073 == 137);
	if (cppVar_84075) {
	cppVar_84071 = TMOD;
	} else {
	BIT_VEC cppVar_84076;
	BIT_VEC cppVar_84077 = PC + 1;
	cppVar_84077 = (cppVar_84077 & cppMask_un_16_);
	BIT_VEC cppVar_84078 = ROM.rd(cppVar_84077);
	bool cppVar_84080 = (cppVar_84078 == 138);
	if (cppVar_84080) {
	cppVar_84076 = TL0;
	} else {
	BIT_VEC cppVar_84081;
	BIT_VEC cppVar_84082 = PC + 1;
	cppVar_84082 = (cppVar_84082 & cppMask_un_16_);
	BIT_VEC cppVar_84083 = ROM.rd(cppVar_84082);
	bool cppVar_84085 = (cppVar_84083 == 140);
	if (cppVar_84085) {
	cppVar_84081 = TH0;
	} else {
	BIT_VEC cppVar_84086;
	BIT_VEC cppVar_84087 = PC + 1;
	cppVar_84087 = (cppVar_84087 & cppMask_un_16_);
	BIT_VEC cppVar_84088 = ROM.rd(cppVar_84087);
	bool cppVar_84090 = (cppVar_84088 == 139);
	if (cppVar_84090) {
	cppVar_84086 = TL1;
	} else {
	BIT_VEC cppVar_84091;
	BIT_VEC cppVar_84092 = PC + 1;
	cppVar_84092 = (cppVar_84092 & cppMask_un_16_);
	BIT_VEC cppVar_84093 = ROM.rd(cppVar_84092);
	bool cppVar_84095 = (cppVar_84093 == 141);
	if (cppVar_84095) {
	cppVar_84091 = TH1;
	} else {
	BIT_VEC cppVar_84096;
	BIT_VEC cppVar_84097 = PC + 1;
	cppVar_84097 = (cppVar_84097 & cppMask_un_16_);
	BIT_VEC cppVar_84098 = ROM.rd(cppVar_84097);
	bool cppVar_84100 = (cppVar_84098 == 144);
	if (cppVar_84100) {
	cppVar_84096 = P1;
	} else {
	BIT_VEC cppVar_84101;
	BIT_VEC cppVar_84102 = PC + 1;
	cppVar_84102 = (cppVar_84102 & cppMask_un_16_);
	BIT_VEC cppVar_84103 = ROM.rd(cppVar_84102);
	bool cppVar_84105 = (cppVar_84103 == 152);
	if (cppVar_84105) {
	cppVar_84101 = SCON;
	} else {
	BIT_VEC cppVar_84106;
	BIT_VEC cppVar_84107 = PC + 1;
	cppVar_84107 = (cppVar_84107 & cppMask_un_16_);
	BIT_VEC cppVar_84108 = ROM.rd(cppVar_84107);
	bool cppVar_84110 = (cppVar_84108 == 153);
	if (cppVar_84110) {
	cppVar_84106 = SBUF;
	} else {
	BIT_VEC cppVar_84111;
	BIT_VEC cppVar_84112 = PC + 1;
	cppVar_84112 = (cppVar_84112 & cppMask_un_16_);
	BIT_VEC cppVar_84113 = ROM.rd(cppVar_84112);
	bool cppVar_84115 = (cppVar_84113 == 160);
	if (cppVar_84115) {
	cppVar_84111 = P2;
	} else {
	BIT_VEC cppVar_84116;
	BIT_VEC cppVar_84117 = PC + 1;
	cppVar_84117 = (cppVar_84117 & cppMask_un_16_);
	BIT_VEC cppVar_84118 = ROM.rd(cppVar_84117);
	bool cppVar_84120 = (cppVar_84118 == 168);
	if (cppVar_84120) {
	cppVar_84116 = IE;
	} else {
	BIT_VEC cppVar_84121;
	BIT_VEC cppVar_84122 = PC + 1;
	cppVar_84122 = (cppVar_84122 & cppMask_un_16_);
	BIT_VEC cppVar_84123 = ROM.rd(cppVar_84122);
	bool cppVar_84125 = (cppVar_84123 == 176);
	if (cppVar_84125) {
	cppVar_84121 = P3;
	} else {
	BIT_VEC cppVar_84126;
	BIT_VEC cppVar_84127 = PC + 1;
	cppVar_84127 = (cppVar_84127 & cppMask_un_16_);
	BIT_VEC cppVar_84128 = ROM.rd(cppVar_84127);
	bool cppVar_84130 = (cppVar_84128 == 184);
	if (cppVar_84130) {
	cppVar_84126 = IP;
	} else {
	BIT_VEC cppVar_84131;
	BIT_VEC cppVar_84132 = PC + 1;
	cppVar_84132 = (cppVar_84132 & cppMask_un_16_);
	BIT_VEC cppVar_84133 = ROM.rd(cppVar_84132);
	bool cppVar_84135 = (cppVar_84133 == 208);
	if (cppVar_84135) {
	cppVar_84131 = PSW;
	} else {
	BIT_VEC cppVar_84136;
	BIT_VEC cppVar_84137 = PC + 1;
	cppVar_84137 = (cppVar_84137 & cppMask_un_16_);
	BIT_VEC cppVar_84138 = ROM.rd(cppVar_84137);
	bool cppVar_84140 = (cppVar_84138 == 224);
	if (cppVar_84140) {
	cppVar_84136 = ACC;
	} else {
	BIT_VEC cppVar_84141;
	BIT_VEC cppVar_84142 = PC + 1;
	cppVar_84142 = (cppVar_84142 & cppMask_un_16_);
	BIT_VEC cppVar_84143 = ROM.rd(cppVar_84142);
	bool cppVar_84145 = (cppVar_84143 == 240);
	if (cppVar_84145) {
	cppVar_84141 = B;
	} else {
	cppVar_84141 = 0;
	}
	cppVar_84136 = cppVar_84141;
	}
	cppVar_84131 = cppVar_84136;
	}
	cppVar_84126 = cppVar_84131;
	}
	cppVar_84121 = cppVar_84126;
	}
	cppVar_84116 = cppVar_84121;
	}
	cppVar_84111 = cppVar_84116;
	}
	cppVar_84106 = cppVar_84111;
	}
	cppVar_84101 = cppVar_84106;
	}
	cppVar_84096 = cppVar_84101;
	}
	cppVar_84091 = cppVar_84096;
	}
	cppVar_84086 = cppVar_84091;
	}
	cppVar_84081 = cppVar_84086;
	}
	cppVar_84076 = cppVar_84081;
	}
	cppVar_84071 = cppVar_84076;
	}
	cppVar_84066 = cppVar_84071;
	}
	cppVar_84061 = cppVar_84066;
	}
	cppVar_84056 = cppVar_84061;
	}
	cppVar_84051 = cppVar_84056;
	}
	cppVar_84046 = cppVar_84051;
	}
	cppVar_84041 = cppVar_84046;
	}
	cppVar_84032 = cppVar_84041;
	}
	BIT_VEC cppVar_84148 = PC + 2;
	cppVar_84148 = (cppVar_84148 & cppMask_un_16_);
	BIT_VEC cppVar_84149 = ROM.rd(cppVar_84148);
	BIT_VEC cppVar_84150 = cppVar_84032 | cppVar_84149;
	cppVar_84026 = cppVar_84150;
	} else {
	cppVar_84026 = TMOD;
	}
	cppVar_84022 = cppVar_84026;
	} else {
	BIT_VEC cppVar_84151;
	BIT_VEC cppVar_84152 = ROM.rd(PC);
	bool cppVar_84154 = (cppVar_84152 == 66);
	if (cppVar_84154) {
	BIT_VEC cppVar_84155;
	BIT_VEC cppVar_84157 = PC + 1;
	cppVar_84157 = (cppVar_84157 & cppMask_un_16_);
	BIT_VEC cppVar_84158 = ROM.rd(cppVar_84157);
	bool cppVar_84160 = (cppVar_84158 == 137);
	if (cppVar_84160) {
	BIT_VEC cppVar_84161;
	BIT_VEC cppVar_84162 = PC + 1;
	cppVar_84162 = (cppVar_84162 & cppMask_un_16_);
	BIT_VEC cppVar_84163 = ROM.rd(cppVar_84162);
	BIT_VEC cppVar_84164 = (cppVar_84163 >> 7) & cppMask_un_1_;
	bool cppVar_84166 = (cppVar_84164 == 0);
	if (cppVar_84166) {
	BIT_VEC cppVar_84167 = PC + 1;
	cppVar_84167 = (cppVar_84167 & cppMask_un_16_);
	BIT_VEC cppVar_84168 = ROM.rd(cppVar_84167);
	BIT_VEC cppVar_84169 = IRAM.rd(cppVar_84168);
	cppVar_84161 = cppVar_84169;
	} else {
	BIT_VEC cppVar_84170;
	BIT_VEC cppVar_84171 = PC + 1;
	cppVar_84171 = (cppVar_84171 & cppMask_un_16_);
	BIT_VEC cppVar_84172 = ROM.rd(cppVar_84171);
	bool cppVar_84174 = (cppVar_84172 == 128);
	if (cppVar_84174) {
	cppVar_84170 = P0;
	} else {
	BIT_VEC cppVar_84175;
	BIT_VEC cppVar_84176 = PC + 1;
	cppVar_84176 = (cppVar_84176 & cppMask_un_16_);
	BIT_VEC cppVar_84177 = ROM.rd(cppVar_84176);
	bool cppVar_84179 = (cppVar_84177 == 129);
	if (cppVar_84179) {
	cppVar_84175 = SP;
	} else {
	BIT_VEC cppVar_84180;
	BIT_VEC cppVar_84181 = PC + 1;
	cppVar_84181 = (cppVar_84181 & cppMask_un_16_);
	BIT_VEC cppVar_84182 = ROM.rd(cppVar_84181);
	bool cppVar_84184 = (cppVar_84182 == 130);
	if (cppVar_84184) {
	cppVar_84180 = DPL;
	} else {
	BIT_VEC cppVar_84185;
	BIT_VEC cppVar_84186 = PC + 1;
	cppVar_84186 = (cppVar_84186 & cppMask_un_16_);
	BIT_VEC cppVar_84187 = ROM.rd(cppVar_84186);
	bool cppVar_84189 = (cppVar_84187 == 131);
	if (cppVar_84189) {
	cppVar_84185 = DPH;
	} else {
	BIT_VEC cppVar_84190;
	BIT_VEC cppVar_84191 = PC + 1;
	cppVar_84191 = (cppVar_84191 & cppMask_un_16_);
	BIT_VEC cppVar_84192 = ROM.rd(cppVar_84191);
	bool cppVar_84194 = (cppVar_84192 == 135);
	if (cppVar_84194) {
	cppVar_84190 = PCON;
	} else {
	BIT_VEC cppVar_84195;
	BIT_VEC cppVar_84196 = PC + 1;
	cppVar_84196 = (cppVar_84196 & cppMask_un_16_);
	BIT_VEC cppVar_84197 = ROM.rd(cppVar_84196);
	bool cppVar_84199 = (cppVar_84197 == 136);
	if (cppVar_84199) {
	cppVar_84195 = TCON;
	} else {
	BIT_VEC cppVar_84200;
	BIT_VEC cppVar_84201 = PC + 1;
	cppVar_84201 = (cppVar_84201 & cppMask_un_16_);
	BIT_VEC cppVar_84202 = ROM.rd(cppVar_84201);
	bool cppVar_84204 = (cppVar_84202 == 137);
	if (cppVar_84204) {
	cppVar_84200 = TMOD;
	} else {
	BIT_VEC cppVar_84205;
	BIT_VEC cppVar_84206 = PC + 1;
	cppVar_84206 = (cppVar_84206 & cppMask_un_16_);
	BIT_VEC cppVar_84207 = ROM.rd(cppVar_84206);
	bool cppVar_84209 = (cppVar_84207 == 138);
	if (cppVar_84209) {
	cppVar_84205 = TL0;
	} else {
	BIT_VEC cppVar_84210;
	BIT_VEC cppVar_84211 = PC + 1;
	cppVar_84211 = (cppVar_84211 & cppMask_un_16_);
	BIT_VEC cppVar_84212 = ROM.rd(cppVar_84211);
	bool cppVar_84214 = (cppVar_84212 == 140);
	if (cppVar_84214) {
	cppVar_84210 = TH0;
	} else {
	BIT_VEC cppVar_84215;
	BIT_VEC cppVar_84216 = PC + 1;
	cppVar_84216 = (cppVar_84216 & cppMask_un_16_);
	BIT_VEC cppVar_84217 = ROM.rd(cppVar_84216);
	bool cppVar_84219 = (cppVar_84217 == 139);
	if (cppVar_84219) {
	cppVar_84215 = TL1;
	} else {
	BIT_VEC cppVar_84220;
	BIT_VEC cppVar_84221 = PC + 1;
	cppVar_84221 = (cppVar_84221 & cppMask_un_16_);
	BIT_VEC cppVar_84222 = ROM.rd(cppVar_84221);
	bool cppVar_84224 = (cppVar_84222 == 141);
	if (cppVar_84224) {
	cppVar_84220 = TH1;
	} else {
	BIT_VEC cppVar_84225;
	BIT_VEC cppVar_84226 = PC + 1;
	cppVar_84226 = (cppVar_84226 & cppMask_un_16_);
	BIT_VEC cppVar_84227 = ROM.rd(cppVar_84226);
	bool cppVar_84229 = (cppVar_84227 == 144);
	if (cppVar_84229) {
	cppVar_84225 = P1;
	} else {
	BIT_VEC cppVar_84230;
	BIT_VEC cppVar_84231 = PC + 1;
	cppVar_84231 = (cppVar_84231 & cppMask_un_16_);
	BIT_VEC cppVar_84232 = ROM.rd(cppVar_84231);
	bool cppVar_84234 = (cppVar_84232 == 152);
	if (cppVar_84234) {
	cppVar_84230 = SCON;
	} else {
	BIT_VEC cppVar_84235;
	BIT_VEC cppVar_84236 = PC + 1;
	cppVar_84236 = (cppVar_84236 & cppMask_un_16_);
	BIT_VEC cppVar_84237 = ROM.rd(cppVar_84236);
	bool cppVar_84239 = (cppVar_84237 == 153);
	if (cppVar_84239) {
	cppVar_84235 = SBUF;
	} else {
	BIT_VEC cppVar_84240;
	BIT_VEC cppVar_84241 = PC + 1;
	cppVar_84241 = (cppVar_84241 & cppMask_un_16_);
	BIT_VEC cppVar_84242 = ROM.rd(cppVar_84241);
	bool cppVar_84244 = (cppVar_84242 == 160);
	if (cppVar_84244) {
	cppVar_84240 = P2;
	} else {
	BIT_VEC cppVar_84245;
	BIT_VEC cppVar_84246 = PC + 1;
	cppVar_84246 = (cppVar_84246 & cppMask_un_16_);
	BIT_VEC cppVar_84247 = ROM.rd(cppVar_84246);
	bool cppVar_84249 = (cppVar_84247 == 168);
	if (cppVar_84249) {
	cppVar_84245 = IE;
	} else {
	BIT_VEC cppVar_84250;
	BIT_VEC cppVar_84251 = PC + 1;
	cppVar_84251 = (cppVar_84251 & cppMask_un_16_);
	BIT_VEC cppVar_84252 = ROM.rd(cppVar_84251);
	bool cppVar_84254 = (cppVar_84252 == 176);
	if (cppVar_84254) {
	cppVar_84250 = P3;
	} else {
	BIT_VEC cppVar_84255;
	BIT_VEC cppVar_84256 = PC + 1;
	cppVar_84256 = (cppVar_84256 & cppMask_un_16_);
	BIT_VEC cppVar_84257 = ROM.rd(cppVar_84256);
	bool cppVar_84259 = (cppVar_84257 == 184);
	if (cppVar_84259) {
	cppVar_84255 = IP;
	} else {
	BIT_VEC cppVar_84260;
	BIT_VEC cppVar_84261 = PC + 1;
	cppVar_84261 = (cppVar_84261 & cppMask_un_16_);
	BIT_VEC cppVar_84262 = ROM.rd(cppVar_84261);
	bool cppVar_84264 = (cppVar_84262 == 208);
	if (cppVar_84264) {
	cppVar_84260 = PSW;
	} else {
	BIT_VEC cppVar_84265;
	BIT_VEC cppVar_84266 = PC + 1;
	cppVar_84266 = (cppVar_84266 & cppMask_un_16_);
	BIT_VEC cppVar_84267 = ROM.rd(cppVar_84266);
	bool cppVar_84269 = (cppVar_84267 == 224);
	if (cppVar_84269) {
	cppVar_84265 = ACC;
	} else {
	BIT_VEC cppVar_84270;
	BIT_VEC cppVar_84271 = PC + 1;
	cppVar_84271 = (cppVar_84271 & cppMask_un_16_);
	BIT_VEC cppVar_84272 = ROM.rd(cppVar_84271);
	bool cppVar_84274 = (cppVar_84272 == 240);
	if (cppVar_84274) {
	cppVar_84270 = B;
	} else {
	cppVar_84270 = 0;
	}
	cppVar_84265 = cppVar_84270;
	}
	cppVar_84260 = cppVar_84265;
	}
	cppVar_84255 = cppVar_84260;
	}
	cppVar_84250 = cppVar_84255;
	}
	cppVar_84245 = cppVar_84250;
	}
	cppVar_84240 = cppVar_84245;
	}
	cppVar_84235 = cppVar_84240;
	}
	cppVar_84230 = cppVar_84235;
	}
	cppVar_84225 = cppVar_84230;
	}
	cppVar_84220 = cppVar_84225;
	}
	cppVar_84215 = cppVar_84220;
	}
	cppVar_84210 = cppVar_84215;
	}
	cppVar_84205 = cppVar_84210;
	}
	cppVar_84200 = cppVar_84205;
	}
	cppVar_84195 = cppVar_84200;
	}
	cppVar_84190 = cppVar_84195;
	}
	cppVar_84185 = cppVar_84190;
	}
	cppVar_84180 = cppVar_84185;
	}
	cppVar_84175 = cppVar_84180;
	}
	cppVar_84170 = cppVar_84175;
	}
	cppVar_84161 = cppVar_84170;
	}
	BIT_VEC cppVar_84276 = cppVar_84161 | ACC;
	cppVar_84155 = cppVar_84276;
	} else {
	cppVar_84155 = TMOD;
	}
	cppVar_84151 = cppVar_84155;
	} else {
	BIT_VEC cppVar_84277;
	BIT_VEC cppVar_84278 = ROM.rd(PC);
	bool cppVar_84280 = (cppVar_84278 == 213);
	BIT_VEC cppVar_84281 = ROM.rd(PC);
	bool cppVar_84283 = (cppVar_84281 == 21);
	bool cppVar_84284 = cppVar_84280 || cppVar_84283;
	if (cppVar_84284) {
	BIT_VEC cppVar_84285;
	BIT_VEC cppVar_84287 = PC + 1;
	cppVar_84287 = (cppVar_84287 & cppMask_un_16_);
	BIT_VEC cppVar_84288 = ROM.rd(cppVar_84287);
	bool cppVar_84290 = (cppVar_84288 == 137);
	if (cppVar_84290) {
	BIT_VEC cppVar_84291;
	BIT_VEC cppVar_84292 = PC + 1;
	cppVar_84292 = (cppVar_84292 & cppMask_un_16_);
	BIT_VEC cppVar_84293 = ROM.rd(cppVar_84292);
	BIT_VEC cppVar_84294 = (cppVar_84293 >> 7) & cppMask_un_1_;
	bool cppVar_84296 = (cppVar_84294 == 0);
	if (cppVar_84296) {
	BIT_VEC cppVar_84297 = PC + 1;
	cppVar_84297 = (cppVar_84297 & cppMask_un_16_);
	BIT_VEC cppVar_84298 = ROM.rd(cppVar_84297);
	BIT_VEC cppVar_84299 = IRAM.rd(cppVar_84298);
	cppVar_84291 = cppVar_84299;
	} else {
	BIT_VEC cppVar_84300;
	BIT_VEC cppVar_84301 = PC + 1;
	cppVar_84301 = (cppVar_84301 & cppMask_un_16_);
	BIT_VEC cppVar_84302 = ROM.rd(cppVar_84301);
	bool cppVar_84304 = (cppVar_84302 == 128);
	if (cppVar_84304) {
	cppVar_84300 = P0;
	} else {
	BIT_VEC cppVar_84305;
	BIT_VEC cppVar_84306 = PC + 1;
	cppVar_84306 = (cppVar_84306 & cppMask_un_16_);
	BIT_VEC cppVar_84307 = ROM.rd(cppVar_84306);
	bool cppVar_84309 = (cppVar_84307 == 129);
	if (cppVar_84309) {
	cppVar_84305 = SP;
	} else {
	BIT_VEC cppVar_84310;
	BIT_VEC cppVar_84311 = PC + 1;
	cppVar_84311 = (cppVar_84311 & cppMask_un_16_);
	BIT_VEC cppVar_84312 = ROM.rd(cppVar_84311);
	bool cppVar_84314 = (cppVar_84312 == 130);
	if (cppVar_84314) {
	cppVar_84310 = DPL;
	} else {
	BIT_VEC cppVar_84315;
	BIT_VEC cppVar_84316 = PC + 1;
	cppVar_84316 = (cppVar_84316 & cppMask_un_16_);
	BIT_VEC cppVar_84317 = ROM.rd(cppVar_84316);
	bool cppVar_84319 = (cppVar_84317 == 131);
	if (cppVar_84319) {
	cppVar_84315 = DPH;
	} else {
	BIT_VEC cppVar_84320;
	BIT_VEC cppVar_84321 = PC + 1;
	cppVar_84321 = (cppVar_84321 & cppMask_un_16_);
	BIT_VEC cppVar_84322 = ROM.rd(cppVar_84321);
	bool cppVar_84324 = (cppVar_84322 == 135);
	if (cppVar_84324) {
	cppVar_84320 = PCON;
	} else {
	BIT_VEC cppVar_84325;
	BIT_VEC cppVar_84326 = PC + 1;
	cppVar_84326 = (cppVar_84326 & cppMask_un_16_);
	BIT_VEC cppVar_84327 = ROM.rd(cppVar_84326);
	bool cppVar_84329 = (cppVar_84327 == 136);
	if (cppVar_84329) {
	cppVar_84325 = TCON;
	} else {
	BIT_VEC cppVar_84330;
	BIT_VEC cppVar_84331 = PC + 1;
	cppVar_84331 = (cppVar_84331 & cppMask_un_16_);
	BIT_VEC cppVar_84332 = ROM.rd(cppVar_84331);
	bool cppVar_84334 = (cppVar_84332 == 137);
	if (cppVar_84334) {
	cppVar_84330 = TMOD;
	} else {
	BIT_VEC cppVar_84335;
	BIT_VEC cppVar_84336 = PC + 1;
	cppVar_84336 = (cppVar_84336 & cppMask_un_16_);
	BIT_VEC cppVar_84337 = ROM.rd(cppVar_84336);
	bool cppVar_84339 = (cppVar_84337 == 138);
	if (cppVar_84339) {
	cppVar_84335 = TL0;
	} else {
	BIT_VEC cppVar_84340;
	BIT_VEC cppVar_84341 = PC + 1;
	cppVar_84341 = (cppVar_84341 & cppMask_un_16_);
	BIT_VEC cppVar_84342 = ROM.rd(cppVar_84341);
	bool cppVar_84344 = (cppVar_84342 == 140);
	if (cppVar_84344) {
	cppVar_84340 = TH0;
	} else {
	BIT_VEC cppVar_84345;
	BIT_VEC cppVar_84346 = PC + 1;
	cppVar_84346 = (cppVar_84346 & cppMask_un_16_);
	BIT_VEC cppVar_84347 = ROM.rd(cppVar_84346);
	bool cppVar_84349 = (cppVar_84347 == 139);
	if (cppVar_84349) {
	cppVar_84345 = TL1;
	} else {
	BIT_VEC cppVar_84350;
	BIT_VEC cppVar_84351 = PC + 1;
	cppVar_84351 = (cppVar_84351 & cppMask_un_16_);
	BIT_VEC cppVar_84352 = ROM.rd(cppVar_84351);
	bool cppVar_84354 = (cppVar_84352 == 141);
	if (cppVar_84354) {
	cppVar_84350 = TH1;
	} else {
	BIT_VEC cppVar_84355;
	BIT_VEC cppVar_84356 = PC + 1;
	cppVar_84356 = (cppVar_84356 & cppMask_un_16_);
	BIT_VEC cppVar_84357 = ROM.rd(cppVar_84356);
	bool cppVar_84359 = (cppVar_84357 == 144);
	if (cppVar_84359) {
	cppVar_84355 = P1;
	} else {
	BIT_VEC cppVar_84360;
	BIT_VEC cppVar_84361 = PC + 1;
	cppVar_84361 = (cppVar_84361 & cppMask_un_16_);
	BIT_VEC cppVar_84362 = ROM.rd(cppVar_84361);
	bool cppVar_84364 = (cppVar_84362 == 152);
	if (cppVar_84364) {
	cppVar_84360 = SCON;
	} else {
	BIT_VEC cppVar_84365;
	BIT_VEC cppVar_84366 = PC + 1;
	cppVar_84366 = (cppVar_84366 & cppMask_un_16_);
	BIT_VEC cppVar_84367 = ROM.rd(cppVar_84366);
	bool cppVar_84369 = (cppVar_84367 == 153);
	if (cppVar_84369) {
	cppVar_84365 = SBUF;
	} else {
	BIT_VEC cppVar_84370;
	BIT_VEC cppVar_84371 = PC + 1;
	cppVar_84371 = (cppVar_84371 & cppMask_un_16_);
	BIT_VEC cppVar_84372 = ROM.rd(cppVar_84371);
	bool cppVar_84374 = (cppVar_84372 == 160);
	if (cppVar_84374) {
	cppVar_84370 = P2;
	} else {
	BIT_VEC cppVar_84375;
	BIT_VEC cppVar_84376 = PC + 1;
	cppVar_84376 = (cppVar_84376 & cppMask_un_16_);
	BIT_VEC cppVar_84377 = ROM.rd(cppVar_84376);
	bool cppVar_84379 = (cppVar_84377 == 168);
	if (cppVar_84379) {
	cppVar_84375 = IE;
	} else {
	BIT_VEC cppVar_84380;
	BIT_VEC cppVar_84381 = PC + 1;
	cppVar_84381 = (cppVar_84381 & cppMask_un_16_);
	BIT_VEC cppVar_84382 = ROM.rd(cppVar_84381);
	bool cppVar_84384 = (cppVar_84382 == 176);
	if (cppVar_84384) {
	cppVar_84380 = P3;
	} else {
	BIT_VEC cppVar_84385;
	BIT_VEC cppVar_84386 = PC + 1;
	cppVar_84386 = (cppVar_84386 & cppMask_un_16_);
	BIT_VEC cppVar_84387 = ROM.rd(cppVar_84386);
	bool cppVar_84389 = (cppVar_84387 == 184);
	if (cppVar_84389) {
	cppVar_84385 = IP;
	} else {
	BIT_VEC cppVar_84390;
	BIT_VEC cppVar_84391 = PC + 1;
	cppVar_84391 = (cppVar_84391 & cppMask_un_16_);
	BIT_VEC cppVar_84392 = ROM.rd(cppVar_84391);
	bool cppVar_84394 = (cppVar_84392 == 208);
	if (cppVar_84394) {
	cppVar_84390 = PSW;
	} else {
	BIT_VEC cppVar_84395;
	BIT_VEC cppVar_84396 = PC + 1;
	cppVar_84396 = (cppVar_84396 & cppMask_un_16_);
	BIT_VEC cppVar_84397 = ROM.rd(cppVar_84396);
	bool cppVar_84399 = (cppVar_84397 == 224);
	if (cppVar_84399) {
	cppVar_84395 = ACC;
	} else {
	BIT_VEC cppVar_84400;
	BIT_VEC cppVar_84401 = PC + 1;
	cppVar_84401 = (cppVar_84401 & cppMask_un_16_);
	BIT_VEC cppVar_84402 = ROM.rd(cppVar_84401);
	bool cppVar_84404 = (cppVar_84402 == 240);
	if (cppVar_84404) {
	cppVar_84400 = B;
	} else {
	cppVar_84400 = 0;
	}
	cppVar_84395 = cppVar_84400;
	}
	cppVar_84390 = cppVar_84395;
	}
	cppVar_84385 = cppVar_84390;
	}
	cppVar_84380 = cppVar_84385;
	}
	cppVar_84375 = cppVar_84380;
	}
	cppVar_84370 = cppVar_84375;
	}
	cppVar_84365 = cppVar_84370;
	}
	cppVar_84360 = cppVar_84365;
	}
	cppVar_84355 = cppVar_84360;
	}
	cppVar_84350 = cppVar_84355;
	}
	cppVar_84345 = cppVar_84350;
	}
	cppVar_84340 = cppVar_84345;
	}
	cppVar_84335 = cppVar_84340;
	}
	cppVar_84330 = cppVar_84335;
	}
	cppVar_84325 = cppVar_84330;
	}
	cppVar_84320 = cppVar_84325;
	}
	cppVar_84315 = cppVar_84320;
	}
	cppVar_84310 = cppVar_84315;
	}
	cppVar_84305 = cppVar_84310;
	}
	cppVar_84300 = cppVar_84305;
	}
	cppVar_84291 = cppVar_84300;
	}
	BIT_VEC cppVar_84407 = cppVar_84291 - 1;
	cppVar_84407 = (cppVar_84407 & cppMask_un_8_);
	cppVar_84285 = cppVar_84407;
	} else {
	cppVar_84285 = TMOD;
	}
	cppVar_84277 = cppVar_84285;
	} else {
	BIT_VEC cppVar_84408;
	BIT_VEC cppVar_84409 = ROM.rd(PC);
	bool cppVar_84411 = (cppVar_84409 == 5);
	if (cppVar_84411) {
	BIT_VEC cppVar_84412;
	BIT_VEC cppVar_84414 = PC + 1;
	cppVar_84414 = (cppVar_84414 & cppMask_un_16_);
	BIT_VEC cppVar_84415 = ROM.rd(cppVar_84414);
	bool cppVar_84417 = (cppVar_84415 == 137);
	if (cppVar_84417) {
	BIT_VEC cppVar_84418;
	BIT_VEC cppVar_84419 = PC + 1;
	cppVar_84419 = (cppVar_84419 & cppMask_un_16_);
	BIT_VEC cppVar_84420 = ROM.rd(cppVar_84419);
	BIT_VEC cppVar_84421 = (cppVar_84420 >> 7) & cppMask_un_1_;
	bool cppVar_84423 = (cppVar_84421 == 0);
	if (cppVar_84423) {
	BIT_VEC cppVar_84424 = PC + 1;
	cppVar_84424 = (cppVar_84424 & cppMask_un_16_);
	BIT_VEC cppVar_84425 = ROM.rd(cppVar_84424);
	BIT_VEC cppVar_84426 = IRAM.rd(cppVar_84425);
	cppVar_84418 = cppVar_84426;
	} else {
	BIT_VEC cppVar_84427;
	BIT_VEC cppVar_84428 = PC + 1;
	cppVar_84428 = (cppVar_84428 & cppMask_un_16_);
	BIT_VEC cppVar_84429 = ROM.rd(cppVar_84428);
	bool cppVar_84431 = (cppVar_84429 == 128);
	if (cppVar_84431) {
	cppVar_84427 = P0;
	} else {
	BIT_VEC cppVar_84432;
	BIT_VEC cppVar_84433 = PC + 1;
	cppVar_84433 = (cppVar_84433 & cppMask_un_16_);
	BIT_VEC cppVar_84434 = ROM.rd(cppVar_84433);
	bool cppVar_84436 = (cppVar_84434 == 129);
	if (cppVar_84436) {
	cppVar_84432 = SP;
	} else {
	BIT_VEC cppVar_84437;
	BIT_VEC cppVar_84438 = PC + 1;
	cppVar_84438 = (cppVar_84438 & cppMask_un_16_);
	BIT_VEC cppVar_84439 = ROM.rd(cppVar_84438);
	bool cppVar_84441 = (cppVar_84439 == 130);
	if (cppVar_84441) {
	cppVar_84437 = DPL;
	} else {
	BIT_VEC cppVar_84442;
	BIT_VEC cppVar_84443 = PC + 1;
	cppVar_84443 = (cppVar_84443 & cppMask_un_16_);
	BIT_VEC cppVar_84444 = ROM.rd(cppVar_84443);
	bool cppVar_84446 = (cppVar_84444 == 131);
	if (cppVar_84446) {
	cppVar_84442 = DPH;
	} else {
	BIT_VEC cppVar_84447;
	BIT_VEC cppVar_84448 = PC + 1;
	cppVar_84448 = (cppVar_84448 & cppMask_un_16_);
	BIT_VEC cppVar_84449 = ROM.rd(cppVar_84448);
	bool cppVar_84451 = (cppVar_84449 == 135);
	if (cppVar_84451) {
	cppVar_84447 = PCON;
	} else {
	BIT_VEC cppVar_84452;
	BIT_VEC cppVar_84453 = PC + 1;
	cppVar_84453 = (cppVar_84453 & cppMask_un_16_);
	BIT_VEC cppVar_84454 = ROM.rd(cppVar_84453);
	bool cppVar_84456 = (cppVar_84454 == 136);
	if (cppVar_84456) {
	cppVar_84452 = TCON;
	} else {
	BIT_VEC cppVar_84457;
	BIT_VEC cppVar_84458 = PC + 1;
	cppVar_84458 = (cppVar_84458 & cppMask_un_16_);
	BIT_VEC cppVar_84459 = ROM.rd(cppVar_84458);
	bool cppVar_84461 = (cppVar_84459 == 137);
	if (cppVar_84461) {
	cppVar_84457 = TMOD;
	} else {
	BIT_VEC cppVar_84462;
	BIT_VEC cppVar_84463 = PC + 1;
	cppVar_84463 = (cppVar_84463 & cppMask_un_16_);
	BIT_VEC cppVar_84464 = ROM.rd(cppVar_84463);
	bool cppVar_84466 = (cppVar_84464 == 138);
	if (cppVar_84466) {
	cppVar_84462 = TL0;
	} else {
	BIT_VEC cppVar_84467;
	BIT_VEC cppVar_84468 = PC + 1;
	cppVar_84468 = (cppVar_84468 & cppMask_un_16_);
	BIT_VEC cppVar_84469 = ROM.rd(cppVar_84468);
	bool cppVar_84471 = (cppVar_84469 == 140);
	if (cppVar_84471) {
	cppVar_84467 = TH0;
	} else {
	BIT_VEC cppVar_84472;
	BIT_VEC cppVar_84473 = PC + 1;
	cppVar_84473 = (cppVar_84473 & cppMask_un_16_);
	BIT_VEC cppVar_84474 = ROM.rd(cppVar_84473);
	bool cppVar_84476 = (cppVar_84474 == 139);
	if (cppVar_84476) {
	cppVar_84472 = TL1;
	} else {
	BIT_VEC cppVar_84477;
	BIT_VEC cppVar_84478 = PC + 1;
	cppVar_84478 = (cppVar_84478 & cppMask_un_16_);
	BIT_VEC cppVar_84479 = ROM.rd(cppVar_84478);
	bool cppVar_84481 = (cppVar_84479 == 141);
	if (cppVar_84481) {
	cppVar_84477 = TH1;
	} else {
	BIT_VEC cppVar_84482;
	BIT_VEC cppVar_84483 = PC + 1;
	cppVar_84483 = (cppVar_84483 & cppMask_un_16_);
	BIT_VEC cppVar_84484 = ROM.rd(cppVar_84483);
	bool cppVar_84486 = (cppVar_84484 == 144);
	if (cppVar_84486) {
	cppVar_84482 = P1;
	} else {
	BIT_VEC cppVar_84487;
	BIT_VEC cppVar_84488 = PC + 1;
	cppVar_84488 = (cppVar_84488 & cppMask_un_16_);
	BIT_VEC cppVar_84489 = ROM.rd(cppVar_84488);
	bool cppVar_84491 = (cppVar_84489 == 152);
	if (cppVar_84491) {
	cppVar_84487 = SCON;
	} else {
	BIT_VEC cppVar_84492;
	BIT_VEC cppVar_84493 = PC + 1;
	cppVar_84493 = (cppVar_84493 & cppMask_un_16_);
	BIT_VEC cppVar_84494 = ROM.rd(cppVar_84493);
	bool cppVar_84496 = (cppVar_84494 == 153);
	if (cppVar_84496) {
	cppVar_84492 = SBUF;
	} else {
	BIT_VEC cppVar_84497;
	BIT_VEC cppVar_84498 = PC + 1;
	cppVar_84498 = (cppVar_84498 & cppMask_un_16_);
	BIT_VEC cppVar_84499 = ROM.rd(cppVar_84498);
	bool cppVar_84501 = (cppVar_84499 == 160);
	if (cppVar_84501) {
	cppVar_84497 = P2;
	} else {
	BIT_VEC cppVar_84502;
	BIT_VEC cppVar_84503 = PC + 1;
	cppVar_84503 = (cppVar_84503 & cppMask_un_16_);
	BIT_VEC cppVar_84504 = ROM.rd(cppVar_84503);
	bool cppVar_84506 = (cppVar_84504 == 168);
	if (cppVar_84506) {
	cppVar_84502 = IE;
	} else {
	BIT_VEC cppVar_84507;
	BIT_VEC cppVar_84508 = PC + 1;
	cppVar_84508 = (cppVar_84508 & cppMask_un_16_);
	BIT_VEC cppVar_84509 = ROM.rd(cppVar_84508);
	bool cppVar_84511 = (cppVar_84509 == 176);
	if (cppVar_84511) {
	cppVar_84507 = P3;
	} else {
	BIT_VEC cppVar_84512;
	BIT_VEC cppVar_84513 = PC + 1;
	cppVar_84513 = (cppVar_84513 & cppMask_un_16_);
	BIT_VEC cppVar_84514 = ROM.rd(cppVar_84513);
	bool cppVar_84516 = (cppVar_84514 == 184);
	if (cppVar_84516) {
	cppVar_84512 = IP;
	} else {
	BIT_VEC cppVar_84517;
	BIT_VEC cppVar_84518 = PC + 1;
	cppVar_84518 = (cppVar_84518 & cppMask_un_16_);
	BIT_VEC cppVar_84519 = ROM.rd(cppVar_84518);
	bool cppVar_84521 = (cppVar_84519 == 208);
	if (cppVar_84521) {
	cppVar_84517 = PSW;
	} else {
	BIT_VEC cppVar_84522;
	BIT_VEC cppVar_84523 = PC + 1;
	cppVar_84523 = (cppVar_84523 & cppMask_un_16_);
	BIT_VEC cppVar_84524 = ROM.rd(cppVar_84523);
	bool cppVar_84526 = (cppVar_84524 == 224);
	if (cppVar_84526) {
	cppVar_84522 = ACC;
	} else {
	BIT_VEC cppVar_84527;
	BIT_VEC cppVar_84528 = PC + 1;
	cppVar_84528 = (cppVar_84528 & cppMask_un_16_);
	BIT_VEC cppVar_84529 = ROM.rd(cppVar_84528);
	bool cppVar_84531 = (cppVar_84529 == 240);
	if (cppVar_84531) {
	cppVar_84527 = B;
	} else {
	cppVar_84527 = 0;
	}
	cppVar_84522 = cppVar_84527;
	}
	cppVar_84517 = cppVar_84522;
	}
	cppVar_84512 = cppVar_84517;
	}
	cppVar_84507 = cppVar_84512;
	}
	cppVar_84502 = cppVar_84507;
	}
	cppVar_84497 = cppVar_84502;
	}
	cppVar_84492 = cppVar_84497;
	}
	cppVar_84487 = cppVar_84492;
	}
	cppVar_84482 = cppVar_84487;
	}
	cppVar_84477 = cppVar_84482;
	}
	cppVar_84472 = cppVar_84477;
	}
	cppVar_84467 = cppVar_84472;
	}
	cppVar_84462 = cppVar_84467;
	}
	cppVar_84457 = cppVar_84462;
	}
	cppVar_84452 = cppVar_84457;
	}
	cppVar_84447 = cppVar_84452;
	}
	cppVar_84442 = cppVar_84447;
	}
	cppVar_84437 = cppVar_84442;
	}
	cppVar_84432 = cppVar_84437;
	}
	cppVar_84427 = cppVar_84432;
	}
	cppVar_84418 = cppVar_84427;
	}
	BIT_VEC cppVar_84534 = cppVar_84418 + 1;
	cppVar_84534 = (cppVar_84534 & cppMask_un_8_);
	cppVar_84412 = cppVar_84534;
	} else {
	cppVar_84412 = TMOD;
	}
	cppVar_84408 = cppVar_84412;
	} else {
	cppVar_84408 = TMOD;
	}
	cppVar_84277 = cppVar_84408;
	}
	cppVar_84151 = cppVar_84277;
	}
	cppVar_84022 = cppVar_84151;
	}
	cppVar_83896 = cppVar_84022;
	}
	cppVar_83767 = cppVar_83896;
	}
	cppVar_83641 = cppVar_83767;
	}
	cppVar_83512 = cppVar_83641;
	}
	cppVar_83499 = cppVar_83512;
	}
	cppVar_83373 = cppVar_83499;
	}
	cppVar_83356 = cppVar_83373;
	}
	cppVar_83339 = cppVar_83356;
	}
	cppVar_83189 = cppVar_83339;
	}
	cppVar_83039 = cppVar_83189;
	}
	cppVar_82889 = cppVar_83039;
	}
	cppVar_82739 = cppVar_82889;
	}
	cppVar_82589 = cppVar_82739;
	}
	cppVar_82439 = cppVar_82589;
	}
	cppVar_82289 = cppVar_82439;
	}
	cppVar_82139 = cppVar_82289;
	}
	cppVar_82125 = cppVar_82139;
	}
	cppVar_82114 = cppVar_82125;
	}
	return cppVar_82114;
}
