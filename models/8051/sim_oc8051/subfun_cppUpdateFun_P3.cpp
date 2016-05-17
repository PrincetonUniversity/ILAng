#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_P3()
{
	BIT_VEC cppVar_36193;
	BIT_VEC cppVar_36194 = ROM.rd(PC);
	bool cppVar_36196 = (cppVar_36194 == 210);
	if (cppVar_36196) {
	BIT_VEC cppVar_36197;
	BIT_VEC cppVar_36198;
	BIT_VEC cppVar_36200 = PC + 1;
	cppVar_36200 = (cppVar_36200 & cppMask_un_16_);
	BIT_VEC cppVar_36201 = ROM.rd(cppVar_36200);
	BIT_VEC cppVar_36202 = (cppVar_36201 >> 7) & cppMask_un_1_;
	bool cppVar_36204 = (cppVar_36202 == 1);
	if (cppVar_36204) {
	BIT_VEC cppVar_36205 = PC + 1;
	cppVar_36205 = (cppVar_36205 & cppMask_un_16_);
	BIT_VEC cppVar_36206 = ROM.rd(cppVar_36205);
	BIT_VEC cppVar_36207 = (cppVar_36206 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36209 = (cppVar_36207 << 3) | 0;
	cppVar_36209 = (cppVar_36209 & cppMask_un_8_);
	cppVar_36198 = cppVar_36209;
	} else {
	BIT_VEC cppVar_36210 = PC + 1;
	cppVar_36210 = (cppVar_36210 & cppMask_un_16_);
	BIT_VEC cppVar_36211 = ROM.rd(cppVar_36210);
	BIT_VEC cppVar_36212 = (cppVar_36211 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36213 = (cppVar_36212 & cppMask_un_5_);
	BIT_VEC cppVar_36215 = cppVar_36213 + 32;
	cppVar_36215 = (cppVar_36215 & cppMask_un_8_);
	cppVar_36198 = cppVar_36215;
	}
	bool cppVar_36217 = (cppVar_36198 == 176);
	if (cppVar_36217) {
	BIT_VEC cppVar_36219 = PC + 1;
	cppVar_36219 = (cppVar_36219 & cppMask_un_16_);
	BIT_VEC cppVar_36220 = ROM.rd(cppVar_36219);
	BIT_VEC cppVar_36221 = (cppVar_36220 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_36222 = (cppVar_36221 & cppMask_un_3_);
	BIT_VEC cppVar_36223 = 1 << static_cast<unsigned>(cppVar_36222);
	cppVar_36223 = (cppVar_36223 & cppMask_un_8_);
	BIT_VEC cppVar_36224 = ~cppVar_36223;
	BIT_VEC cppVar_36225;
	BIT_VEC cppVar_36226;
	BIT_VEC cppVar_36227 = PC + 1;
	cppVar_36227 = (cppVar_36227 & cppMask_un_16_);
	BIT_VEC cppVar_36228 = ROM.rd(cppVar_36227);
	BIT_VEC cppVar_36229 = (cppVar_36228 >> 7) & cppMask_un_1_;
	bool cppVar_36230 = (cppVar_36229 == 1);
	if (cppVar_36230) {
	BIT_VEC cppVar_36231 = PC + 1;
	cppVar_36231 = (cppVar_36231 & cppMask_un_16_);
	BIT_VEC cppVar_36232 = ROM.rd(cppVar_36231);
	BIT_VEC cppVar_36233 = (cppVar_36232 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36234 = (cppVar_36233 << 3) | 0;
	cppVar_36234 = (cppVar_36234 & cppMask_un_8_);
	cppVar_36226 = cppVar_36234;
	} else {
	BIT_VEC cppVar_36235 = PC + 1;
	cppVar_36235 = (cppVar_36235 & cppMask_un_16_);
	BIT_VEC cppVar_36236 = ROM.rd(cppVar_36235);
	BIT_VEC cppVar_36237 = (cppVar_36236 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36238 = (cppVar_36237 & cppMask_un_5_);
	BIT_VEC cppVar_36239 = cppVar_36238 + 32;
	cppVar_36239 = (cppVar_36239 & cppMask_un_8_);
	cppVar_36226 = cppVar_36239;
	}
	BIT_VEC cppVar_36240 = (cppVar_36226 >> 7) & cppMask_un_1_;
	bool cppVar_36242 = (cppVar_36240 == 0);
	if (cppVar_36242) {
	BIT_VEC cppVar_36243;
	BIT_VEC cppVar_36244 = PC + 1;
	cppVar_36244 = (cppVar_36244 & cppMask_un_16_);
	BIT_VEC cppVar_36245 = ROM.rd(cppVar_36244);
	BIT_VEC cppVar_36246 = (cppVar_36245 >> 7) & cppMask_un_1_;
	bool cppVar_36247 = (cppVar_36246 == 1);
	if (cppVar_36247) {
	BIT_VEC cppVar_36248 = PC + 1;
	cppVar_36248 = (cppVar_36248 & cppMask_un_16_);
	BIT_VEC cppVar_36249 = ROM.rd(cppVar_36248);
	BIT_VEC cppVar_36250 = (cppVar_36249 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36251 = (cppVar_36250 << 3) | 0;
	cppVar_36251 = (cppVar_36251 & cppMask_un_8_);
	cppVar_36243 = cppVar_36251;
	} else {
	BIT_VEC cppVar_36252 = PC + 1;
	cppVar_36252 = (cppVar_36252 & cppMask_un_16_);
	BIT_VEC cppVar_36253 = ROM.rd(cppVar_36252);
	BIT_VEC cppVar_36254 = (cppVar_36253 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36255 = (cppVar_36254 & cppMask_un_5_);
	BIT_VEC cppVar_36256 = cppVar_36255 + 32;
	cppVar_36256 = (cppVar_36256 & cppMask_un_8_);
	cppVar_36243 = cppVar_36256;
	}
	BIT_VEC cppVar_36257 = IRAM.rd(cppVar_36243);
	cppVar_36225 = cppVar_36257;
	} else {
	BIT_VEC cppVar_36258;
	BIT_VEC cppVar_36259;
	BIT_VEC cppVar_36260 = PC + 1;
	cppVar_36260 = (cppVar_36260 & cppMask_un_16_);
	BIT_VEC cppVar_36261 = ROM.rd(cppVar_36260);
	BIT_VEC cppVar_36262 = (cppVar_36261 >> 7) & cppMask_un_1_;
	bool cppVar_36263 = (cppVar_36262 == 1);
	if (cppVar_36263) {
	BIT_VEC cppVar_36264 = PC + 1;
	cppVar_36264 = (cppVar_36264 & cppMask_un_16_);
	BIT_VEC cppVar_36265 = ROM.rd(cppVar_36264);
	BIT_VEC cppVar_36266 = (cppVar_36265 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36267 = (cppVar_36266 << 3) | 0;
	cppVar_36267 = (cppVar_36267 & cppMask_un_8_);
	cppVar_36259 = cppVar_36267;
	} else {
	BIT_VEC cppVar_36268 = PC + 1;
	cppVar_36268 = (cppVar_36268 & cppMask_un_16_);
	BIT_VEC cppVar_36269 = ROM.rd(cppVar_36268);
	BIT_VEC cppVar_36270 = (cppVar_36269 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36271 = (cppVar_36270 & cppMask_un_5_);
	BIT_VEC cppVar_36272 = cppVar_36271 + 32;
	cppVar_36272 = (cppVar_36272 & cppMask_un_8_);
	cppVar_36259 = cppVar_36272;
	}
	bool cppVar_36274 = (cppVar_36259 == 128);
	if (cppVar_36274) {
	cppVar_36258 = P0;
	} else {
	BIT_VEC cppVar_36275;
	BIT_VEC cppVar_36276;
	BIT_VEC cppVar_36277 = PC + 1;
	cppVar_36277 = (cppVar_36277 & cppMask_un_16_);
	BIT_VEC cppVar_36278 = ROM.rd(cppVar_36277);
	BIT_VEC cppVar_36279 = (cppVar_36278 >> 7) & cppMask_un_1_;
	bool cppVar_36280 = (cppVar_36279 == 1);
	if (cppVar_36280) {
	BIT_VEC cppVar_36281 = PC + 1;
	cppVar_36281 = (cppVar_36281 & cppMask_un_16_);
	BIT_VEC cppVar_36282 = ROM.rd(cppVar_36281);
	BIT_VEC cppVar_36283 = (cppVar_36282 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36284 = (cppVar_36283 << 3) | 0;
	cppVar_36284 = (cppVar_36284 & cppMask_un_8_);
	cppVar_36276 = cppVar_36284;
	} else {
	BIT_VEC cppVar_36285 = PC + 1;
	cppVar_36285 = (cppVar_36285 & cppMask_un_16_);
	BIT_VEC cppVar_36286 = ROM.rd(cppVar_36285);
	BIT_VEC cppVar_36287 = (cppVar_36286 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36288 = (cppVar_36287 & cppMask_un_5_);
	BIT_VEC cppVar_36289 = cppVar_36288 + 32;
	cppVar_36289 = (cppVar_36289 & cppMask_un_8_);
	cppVar_36276 = cppVar_36289;
	}
	bool cppVar_36291 = (cppVar_36276 == 129);
	if (cppVar_36291) {
	cppVar_36275 = SP;
	} else {
	BIT_VEC cppVar_36292;
	BIT_VEC cppVar_36293;
	BIT_VEC cppVar_36294 = PC + 1;
	cppVar_36294 = (cppVar_36294 & cppMask_un_16_);
	BIT_VEC cppVar_36295 = ROM.rd(cppVar_36294);
	BIT_VEC cppVar_36296 = (cppVar_36295 >> 7) & cppMask_un_1_;
	bool cppVar_36297 = (cppVar_36296 == 1);
	if (cppVar_36297) {
	BIT_VEC cppVar_36298 = PC + 1;
	cppVar_36298 = (cppVar_36298 & cppMask_un_16_);
	BIT_VEC cppVar_36299 = ROM.rd(cppVar_36298);
	BIT_VEC cppVar_36300 = (cppVar_36299 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36301 = (cppVar_36300 << 3) | 0;
	cppVar_36301 = (cppVar_36301 & cppMask_un_8_);
	cppVar_36293 = cppVar_36301;
	} else {
	BIT_VEC cppVar_36302 = PC + 1;
	cppVar_36302 = (cppVar_36302 & cppMask_un_16_);
	BIT_VEC cppVar_36303 = ROM.rd(cppVar_36302);
	BIT_VEC cppVar_36304 = (cppVar_36303 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36305 = (cppVar_36304 & cppMask_un_5_);
	BIT_VEC cppVar_36306 = cppVar_36305 + 32;
	cppVar_36306 = (cppVar_36306 & cppMask_un_8_);
	cppVar_36293 = cppVar_36306;
	}
	bool cppVar_36308 = (cppVar_36293 == 130);
	if (cppVar_36308) {
	cppVar_36292 = DPL;
	} else {
	BIT_VEC cppVar_36309;
	BIT_VEC cppVar_36310;
	BIT_VEC cppVar_36311 = PC + 1;
	cppVar_36311 = (cppVar_36311 & cppMask_un_16_);
	BIT_VEC cppVar_36312 = ROM.rd(cppVar_36311);
	BIT_VEC cppVar_36313 = (cppVar_36312 >> 7) & cppMask_un_1_;
	bool cppVar_36314 = (cppVar_36313 == 1);
	if (cppVar_36314) {
	BIT_VEC cppVar_36315 = PC + 1;
	cppVar_36315 = (cppVar_36315 & cppMask_un_16_);
	BIT_VEC cppVar_36316 = ROM.rd(cppVar_36315);
	BIT_VEC cppVar_36317 = (cppVar_36316 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36318 = (cppVar_36317 << 3) | 0;
	cppVar_36318 = (cppVar_36318 & cppMask_un_8_);
	cppVar_36310 = cppVar_36318;
	} else {
	BIT_VEC cppVar_36319 = PC + 1;
	cppVar_36319 = (cppVar_36319 & cppMask_un_16_);
	BIT_VEC cppVar_36320 = ROM.rd(cppVar_36319);
	BIT_VEC cppVar_36321 = (cppVar_36320 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36322 = (cppVar_36321 & cppMask_un_5_);
	BIT_VEC cppVar_36323 = cppVar_36322 + 32;
	cppVar_36323 = (cppVar_36323 & cppMask_un_8_);
	cppVar_36310 = cppVar_36323;
	}
	bool cppVar_36325 = (cppVar_36310 == 131);
	if (cppVar_36325) {
	cppVar_36309 = DPH;
	} else {
	BIT_VEC cppVar_36326;
	BIT_VEC cppVar_36327;
	BIT_VEC cppVar_36328 = PC + 1;
	cppVar_36328 = (cppVar_36328 & cppMask_un_16_);
	BIT_VEC cppVar_36329 = ROM.rd(cppVar_36328);
	BIT_VEC cppVar_36330 = (cppVar_36329 >> 7) & cppMask_un_1_;
	bool cppVar_36331 = (cppVar_36330 == 1);
	if (cppVar_36331) {
	BIT_VEC cppVar_36332 = PC + 1;
	cppVar_36332 = (cppVar_36332 & cppMask_un_16_);
	BIT_VEC cppVar_36333 = ROM.rd(cppVar_36332);
	BIT_VEC cppVar_36334 = (cppVar_36333 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36335 = (cppVar_36334 << 3) | 0;
	cppVar_36335 = (cppVar_36335 & cppMask_un_8_);
	cppVar_36327 = cppVar_36335;
	} else {
	BIT_VEC cppVar_36336 = PC + 1;
	cppVar_36336 = (cppVar_36336 & cppMask_un_16_);
	BIT_VEC cppVar_36337 = ROM.rd(cppVar_36336);
	BIT_VEC cppVar_36338 = (cppVar_36337 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36339 = (cppVar_36338 & cppMask_un_5_);
	BIT_VEC cppVar_36340 = cppVar_36339 + 32;
	cppVar_36340 = (cppVar_36340 & cppMask_un_8_);
	cppVar_36327 = cppVar_36340;
	}
	bool cppVar_36342 = (cppVar_36327 == 135);
	if (cppVar_36342) {
	cppVar_36326 = PCON;
	} else {
	BIT_VEC cppVar_36343;
	BIT_VEC cppVar_36344;
	BIT_VEC cppVar_36345 = PC + 1;
	cppVar_36345 = (cppVar_36345 & cppMask_un_16_);
	BIT_VEC cppVar_36346 = ROM.rd(cppVar_36345);
	BIT_VEC cppVar_36347 = (cppVar_36346 >> 7) & cppMask_un_1_;
	bool cppVar_36348 = (cppVar_36347 == 1);
	if (cppVar_36348) {
	BIT_VEC cppVar_36349 = PC + 1;
	cppVar_36349 = (cppVar_36349 & cppMask_un_16_);
	BIT_VEC cppVar_36350 = ROM.rd(cppVar_36349);
	BIT_VEC cppVar_36351 = (cppVar_36350 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36352 = (cppVar_36351 << 3) | 0;
	cppVar_36352 = (cppVar_36352 & cppMask_un_8_);
	cppVar_36344 = cppVar_36352;
	} else {
	BIT_VEC cppVar_36353 = PC + 1;
	cppVar_36353 = (cppVar_36353 & cppMask_un_16_);
	BIT_VEC cppVar_36354 = ROM.rd(cppVar_36353);
	BIT_VEC cppVar_36355 = (cppVar_36354 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36356 = (cppVar_36355 & cppMask_un_5_);
	BIT_VEC cppVar_36357 = cppVar_36356 + 32;
	cppVar_36357 = (cppVar_36357 & cppMask_un_8_);
	cppVar_36344 = cppVar_36357;
	}
	bool cppVar_36359 = (cppVar_36344 == 136);
	if (cppVar_36359) {
	cppVar_36343 = TCON;
	} else {
	BIT_VEC cppVar_36360;
	BIT_VEC cppVar_36361;
	BIT_VEC cppVar_36362 = PC + 1;
	cppVar_36362 = (cppVar_36362 & cppMask_un_16_);
	BIT_VEC cppVar_36363 = ROM.rd(cppVar_36362);
	BIT_VEC cppVar_36364 = (cppVar_36363 >> 7) & cppMask_un_1_;
	bool cppVar_36365 = (cppVar_36364 == 1);
	if (cppVar_36365) {
	BIT_VEC cppVar_36366 = PC + 1;
	cppVar_36366 = (cppVar_36366 & cppMask_un_16_);
	BIT_VEC cppVar_36367 = ROM.rd(cppVar_36366);
	BIT_VEC cppVar_36368 = (cppVar_36367 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36369 = (cppVar_36368 << 3) | 0;
	cppVar_36369 = (cppVar_36369 & cppMask_un_8_);
	cppVar_36361 = cppVar_36369;
	} else {
	BIT_VEC cppVar_36370 = PC + 1;
	cppVar_36370 = (cppVar_36370 & cppMask_un_16_);
	BIT_VEC cppVar_36371 = ROM.rd(cppVar_36370);
	BIT_VEC cppVar_36372 = (cppVar_36371 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36373 = (cppVar_36372 & cppMask_un_5_);
	BIT_VEC cppVar_36374 = cppVar_36373 + 32;
	cppVar_36374 = (cppVar_36374 & cppMask_un_8_);
	cppVar_36361 = cppVar_36374;
	}
	bool cppVar_36376 = (cppVar_36361 == 137);
	if (cppVar_36376) {
	cppVar_36360 = TMOD;
	} else {
	BIT_VEC cppVar_36377;
	BIT_VEC cppVar_36378;
	BIT_VEC cppVar_36379 = PC + 1;
	cppVar_36379 = (cppVar_36379 & cppMask_un_16_);
	BIT_VEC cppVar_36380 = ROM.rd(cppVar_36379);
	BIT_VEC cppVar_36381 = (cppVar_36380 >> 7) & cppMask_un_1_;
	bool cppVar_36382 = (cppVar_36381 == 1);
	if (cppVar_36382) {
	BIT_VEC cppVar_36383 = PC + 1;
	cppVar_36383 = (cppVar_36383 & cppMask_un_16_);
	BIT_VEC cppVar_36384 = ROM.rd(cppVar_36383);
	BIT_VEC cppVar_36385 = (cppVar_36384 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36386 = (cppVar_36385 << 3) | 0;
	cppVar_36386 = (cppVar_36386 & cppMask_un_8_);
	cppVar_36378 = cppVar_36386;
	} else {
	BIT_VEC cppVar_36387 = PC + 1;
	cppVar_36387 = (cppVar_36387 & cppMask_un_16_);
	BIT_VEC cppVar_36388 = ROM.rd(cppVar_36387);
	BIT_VEC cppVar_36389 = (cppVar_36388 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36390 = (cppVar_36389 & cppMask_un_5_);
	BIT_VEC cppVar_36391 = cppVar_36390 + 32;
	cppVar_36391 = (cppVar_36391 & cppMask_un_8_);
	cppVar_36378 = cppVar_36391;
	}
	bool cppVar_36393 = (cppVar_36378 == 138);
	if (cppVar_36393) {
	cppVar_36377 = TL0;
	} else {
	BIT_VEC cppVar_36394;
	BIT_VEC cppVar_36395;
	BIT_VEC cppVar_36396 = PC + 1;
	cppVar_36396 = (cppVar_36396 & cppMask_un_16_);
	BIT_VEC cppVar_36397 = ROM.rd(cppVar_36396);
	BIT_VEC cppVar_36398 = (cppVar_36397 >> 7) & cppMask_un_1_;
	bool cppVar_36399 = (cppVar_36398 == 1);
	if (cppVar_36399) {
	BIT_VEC cppVar_36400 = PC + 1;
	cppVar_36400 = (cppVar_36400 & cppMask_un_16_);
	BIT_VEC cppVar_36401 = ROM.rd(cppVar_36400);
	BIT_VEC cppVar_36402 = (cppVar_36401 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36403 = (cppVar_36402 << 3) | 0;
	cppVar_36403 = (cppVar_36403 & cppMask_un_8_);
	cppVar_36395 = cppVar_36403;
	} else {
	BIT_VEC cppVar_36404 = PC + 1;
	cppVar_36404 = (cppVar_36404 & cppMask_un_16_);
	BIT_VEC cppVar_36405 = ROM.rd(cppVar_36404);
	BIT_VEC cppVar_36406 = (cppVar_36405 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36407 = (cppVar_36406 & cppMask_un_5_);
	BIT_VEC cppVar_36408 = cppVar_36407 + 32;
	cppVar_36408 = (cppVar_36408 & cppMask_un_8_);
	cppVar_36395 = cppVar_36408;
	}
	bool cppVar_36410 = (cppVar_36395 == 140);
	if (cppVar_36410) {
	cppVar_36394 = TH0;
	} else {
	BIT_VEC cppVar_36411;
	BIT_VEC cppVar_36412;
	BIT_VEC cppVar_36413 = PC + 1;
	cppVar_36413 = (cppVar_36413 & cppMask_un_16_);
	BIT_VEC cppVar_36414 = ROM.rd(cppVar_36413);
	BIT_VEC cppVar_36415 = (cppVar_36414 >> 7) & cppMask_un_1_;
	bool cppVar_36416 = (cppVar_36415 == 1);
	if (cppVar_36416) {
	BIT_VEC cppVar_36417 = PC + 1;
	cppVar_36417 = (cppVar_36417 & cppMask_un_16_);
	BIT_VEC cppVar_36418 = ROM.rd(cppVar_36417);
	BIT_VEC cppVar_36419 = (cppVar_36418 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36420 = (cppVar_36419 << 3) | 0;
	cppVar_36420 = (cppVar_36420 & cppMask_un_8_);
	cppVar_36412 = cppVar_36420;
	} else {
	BIT_VEC cppVar_36421 = PC + 1;
	cppVar_36421 = (cppVar_36421 & cppMask_un_16_);
	BIT_VEC cppVar_36422 = ROM.rd(cppVar_36421);
	BIT_VEC cppVar_36423 = (cppVar_36422 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36424 = (cppVar_36423 & cppMask_un_5_);
	BIT_VEC cppVar_36425 = cppVar_36424 + 32;
	cppVar_36425 = (cppVar_36425 & cppMask_un_8_);
	cppVar_36412 = cppVar_36425;
	}
	bool cppVar_36427 = (cppVar_36412 == 139);
	if (cppVar_36427) {
	cppVar_36411 = TL1;
	} else {
	BIT_VEC cppVar_36428;
	BIT_VEC cppVar_36429;
	BIT_VEC cppVar_36430 = PC + 1;
	cppVar_36430 = (cppVar_36430 & cppMask_un_16_);
	BIT_VEC cppVar_36431 = ROM.rd(cppVar_36430);
	BIT_VEC cppVar_36432 = (cppVar_36431 >> 7) & cppMask_un_1_;
	bool cppVar_36433 = (cppVar_36432 == 1);
	if (cppVar_36433) {
	BIT_VEC cppVar_36434 = PC + 1;
	cppVar_36434 = (cppVar_36434 & cppMask_un_16_);
	BIT_VEC cppVar_36435 = ROM.rd(cppVar_36434);
	BIT_VEC cppVar_36436 = (cppVar_36435 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36437 = (cppVar_36436 << 3) | 0;
	cppVar_36437 = (cppVar_36437 & cppMask_un_8_);
	cppVar_36429 = cppVar_36437;
	} else {
	BIT_VEC cppVar_36438 = PC + 1;
	cppVar_36438 = (cppVar_36438 & cppMask_un_16_);
	BIT_VEC cppVar_36439 = ROM.rd(cppVar_36438);
	BIT_VEC cppVar_36440 = (cppVar_36439 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36441 = (cppVar_36440 & cppMask_un_5_);
	BIT_VEC cppVar_36442 = cppVar_36441 + 32;
	cppVar_36442 = (cppVar_36442 & cppMask_un_8_);
	cppVar_36429 = cppVar_36442;
	}
	bool cppVar_36444 = (cppVar_36429 == 141);
	if (cppVar_36444) {
	cppVar_36428 = TH1;
	} else {
	BIT_VEC cppVar_36445;
	BIT_VEC cppVar_36446;
	BIT_VEC cppVar_36447 = PC + 1;
	cppVar_36447 = (cppVar_36447 & cppMask_un_16_);
	BIT_VEC cppVar_36448 = ROM.rd(cppVar_36447);
	BIT_VEC cppVar_36449 = (cppVar_36448 >> 7) & cppMask_un_1_;
	bool cppVar_36450 = (cppVar_36449 == 1);
	if (cppVar_36450) {
	BIT_VEC cppVar_36451 = PC + 1;
	cppVar_36451 = (cppVar_36451 & cppMask_un_16_);
	BIT_VEC cppVar_36452 = ROM.rd(cppVar_36451);
	BIT_VEC cppVar_36453 = (cppVar_36452 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36454 = (cppVar_36453 << 3) | 0;
	cppVar_36454 = (cppVar_36454 & cppMask_un_8_);
	cppVar_36446 = cppVar_36454;
	} else {
	BIT_VEC cppVar_36455 = PC + 1;
	cppVar_36455 = (cppVar_36455 & cppMask_un_16_);
	BIT_VEC cppVar_36456 = ROM.rd(cppVar_36455);
	BIT_VEC cppVar_36457 = (cppVar_36456 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36458 = (cppVar_36457 & cppMask_un_5_);
	BIT_VEC cppVar_36459 = cppVar_36458 + 32;
	cppVar_36459 = (cppVar_36459 & cppMask_un_8_);
	cppVar_36446 = cppVar_36459;
	}
	bool cppVar_36461 = (cppVar_36446 == 144);
	if (cppVar_36461) {
	cppVar_36445 = P1;
	} else {
	BIT_VEC cppVar_36462;
	BIT_VEC cppVar_36463;
	BIT_VEC cppVar_36464 = PC + 1;
	cppVar_36464 = (cppVar_36464 & cppMask_un_16_);
	BIT_VEC cppVar_36465 = ROM.rd(cppVar_36464);
	BIT_VEC cppVar_36466 = (cppVar_36465 >> 7) & cppMask_un_1_;
	bool cppVar_36467 = (cppVar_36466 == 1);
	if (cppVar_36467) {
	BIT_VEC cppVar_36468 = PC + 1;
	cppVar_36468 = (cppVar_36468 & cppMask_un_16_);
	BIT_VEC cppVar_36469 = ROM.rd(cppVar_36468);
	BIT_VEC cppVar_36470 = (cppVar_36469 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36471 = (cppVar_36470 << 3) | 0;
	cppVar_36471 = (cppVar_36471 & cppMask_un_8_);
	cppVar_36463 = cppVar_36471;
	} else {
	BIT_VEC cppVar_36472 = PC + 1;
	cppVar_36472 = (cppVar_36472 & cppMask_un_16_);
	BIT_VEC cppVar_36473 = ROM.rd(cppVar_36472);
	BIT_VEC cppVar_36474 = (cppVar_36473 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36475 = (cppVar_36474 & cppMask_un_5_);
	BIT_VEC cppVar_36476 = cppVar_36475 + 32;
	cppVar_36476 = (cppVar_36476 & cppMask_un_8_);
	cppVar_36463 = cppVar_36476;
	}
	bool cppVar_36478 = (cppVar_36463 == 152);
	if (cppVar_36478) {
	cppVar_36462 = SCON;
	} else {
	BIT_VEC cppVar_36479;
	BIT_VEC cppVar_36480;
	BIT_VEC cppVar_36481 = PC + 1;
	cppVar_36481 = (cppVar_36481 & cppMask_un_16_);
	BIT_VEC cppVar_36482 = ROM.rd(cppVar_36481);
	BIT_VEC cppVar_36483 = (cppVar_36482 >> 7) & cppMask_un_1_;
	bool cppVar_36484 = (cppVar_36483 == 1);
	if (cppVar_36484) {
	BIT_VEC cppVar_36485 = PC + 1;
	cppVar_36485 = (cppVar_36485 & cppMask_un_16_);
	BIT_VEC cppVar_36486 = ROM.rd(cppVar_36485);
	BIT_VEC cppVar_36487 = (cppVar_36486 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36488 = (cppVar_36487 << 3) | 0;
	cppVar_36488 = (cppVar_36488 & cppMask_un_8_);
	cppVar_36480 = cppVar_36488;
	} else {
	BIT_VEC cppVar_36489 = PC + 1;
	cppVar_36489 = (cppVar_36489 & cppMask_un_16_);
	BIT_VEC cppVar_36490 = ROM.rd(cppVar_36489);
	BIT_VEC cppVar_36491 = (cppVar_36490 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36492 = (cppVar_36491 & cppMask_un_5_);
	BIT_VEC cppVar_36493 = cppVar_36492 + 32;
	cppVar_36493 = (cppVar_36493 & cppMask_un_8_);
	cppVar_36480 = cppVar_36493;
	}
	bool cppVar_36495 = (cppVar_36480 == 153);
	if (cppVar_36495) {
	cppVar_36479 = SBUF;
	} else {
	BIT_VEC cppVar_36496;
	BIT_VEC cppVar_36497;
	BIT_VEC cppVar_36498 = PC + 1;
	cppVar_36498 = (cppVar_36498 & cppMask_un_16_);
	BIT_VEC cppVar_36499 = ROM.rd(cppVar_36498);
	BIT_VEC cppVar_36500 = (cppVar_36499 >> 7) & cppMask_un_1_;
	bool cppVar_36501 = (cppVar_36500 == 1);
	if (cppVar_36501) {
	BIT_VEC cppVar_36502 = PC + 1;
	cppVar_36502 = (cppVar_36502 & cppMask_un_16_);
	BIT_VEC cppVar_36503 = ROM.rd(cppVar_36502);
	BIT_VEC cppVar_36504 = (cppVar_36503 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36505 = (cppVar_36504 << 3) | 0;
	cppVar_36505 = (cppVar_36505 & cppMask_un_8_);
	cppVar_36497 = cppVar_36505;
	} else {
	BIT_VEC cppVar_36506 = PC + 1;
	cppVar_36506 = (cppVar_36506 & cppMask_un_16_);
	BIT_VEC cppVar_36507 = ROM.rd(cppVar_36506);
	BIT_VEC cppVar_36508 = (cppVar_36507 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36509 = (cppVar_36508 & cppMask_un_5_);
	BIT_VEC cppVar_36510 = cppVar_36509 + 32;
	cppVar_36510 = (cppVar_36510 & cppMask_un_8_);
	cppVar_36497 = cppVar_36510;
	}
	bool cppVar_36512 = (cppVar_36497 == 160);
	if (cppVar_36512) {
	cppVar_36496 = P2;
	} else {
	BIT_VEC cppVar_36513;
	BIT_VEC cppVar_36514;
	BIT_VEC cppVar_36515 = PC + 1;
	cppVar_36515 = (cppVar_36515 & cppMask_un_16_);
	BIT_VEC cppVar_36516 = ROM.rd(cppVar_36515);
	BIT_VEC cppVar_36517 = (cppVar_36516 >> 7) & cppMask_un_1_;
	bool cppVar_36518 = (cppVar_36517 == 1);
	if (cppVar_36518) {
	BIT_VEC cppVar_36519 = PC + 1;
	cppVar_36519 = (cppVar_36519 & cppMask_un_16_);
	BIT_VEC cppVar_36520 = ROM.rd(cppVar_36519);
	BIT_VEC cppVar_36521 = (cppVar_36520 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36522 = (cppVar_36521 << 3) | 0;
	cppVar_36522 = (cppVar_36522 & cppMask_un_8_);
	cppVar_36514 = cppVar_36522;
	} else {
	BIT_VEC cppVar_36523 = PC + 1;
	cppVar_36523 = (cppVar_36523 & cppMask_un_16_);
	BIT_VEC cppVar_36524 = ROM.rd(cppVar_36523);
	BIT_VEC cppVar_36525 = (cppVar_36524 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36526 = (cppVar_36525 & cppMask_un_5_);
	BIT_VEC cppVar_36527 = cppVar_36526 + 32;
	cppVar_36527 = (cppVar_36527 & cppMask_un_8_);
	cppVar_36514 = cppVar_36527;
	}
	bool cppVar_36529 = (cppVar_36514 == 168);
	if (cppVar_36529) {
	cppVar_36513 = IE;
	} else {
	BIT_VEC cppVar_36530;
	BIT_VEC cppVar_36531;
	BIT_VEC cppVar_36532 = PC + 1;
	cppVar_36532 = (cppVar_36532 & cppMask_un_16_);
	BIT_VEC cppVar_36533 = ROM.rd(cppVar_36532);
	BIT_VEC cppVar_36534 = (cppVar_36533 >> 7) & cppMask_un_1_;
	bool cppVar_36535 = (cppVar_36534 == 1);
	if (cppVar_36535) {
	BIT_VEC cppVar_36536 = PC + 1;
	cppVar_36536 = (cppVar_36536 & cppMask_un_16_);
	BIT_VEC cppVar_36537 = ROM.rd(cppVar_36536);
	BIT_VEC cppVar_36538 = (cppVar_36537 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36539 = (cppVar_36538 << 3) | 0;
	cppVar_36539 = (cppVar_36539 & cppMask_un_8_);
	cppVar_36531 = cppVar_36539;
	} else {
	BIT_VEC cppVar_36540 = PC + 1;
	cppVar_36540 = (cppVar_36540 & cppMask_un_16_);
	BIT_VEC cppVar_36541 = ROM.rd(cppVar_36540);
	BIT_VEC cppVar_36542 = (cppVar_36541 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36543 = (cppVar_36542 & cppMask_un_5_);
	BIT_VEC cppVar_36544 = cppVar_36543 + 32;
	cppVar_36544 = (cppVar_36544 & cppMask_un_8_);
	cppVar_36531 = cppVar_36544;
	}
	bool cppVar_36546 = (cppVar_36531 == 176);
	if (cppVar_36546) {
	cppVar_36530 = P3;
	} else {
	BIT_VEC cppVar_36547;
	BIT_VEC cppVar_36548;
	BIT_VEC cppVar_36549 = PC + 1;
	cppVar_36549 = (cppVar_36549 & cppMask_un_16_);
	BIT_VEC cppVar_36550 = ROM.rd(cppVar_36549);
	BIT_VEC cppVar_36551 = (cppVar_36550 >> 7) & cppMask_un_1_;
	bool cppVar_36552 = (cppVar_36551 == 1);
	if (cppVar_36552) {
	BIT_VEC cppVar_36553 = PC + 1;
	cppVar_36553 = (cppVar_36553 & cppMask_un_16_);
	BIT_VEC cppVar_36554 = ROM.rd(cppVar_36553);
	BIT_VEC cppVar_36555 = (cppVar_36554 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36556 = (cppVar_36555 << 3) | 0;
	cppVar_36556 = (cppVar_36556 & cppMask_un_8_);
	cppVar_36548 = cppVar_36556;
	} else {
	BIT_VEC cppVar_36557 = PC + 1;
	cppVar_36557 = (cppVar_36557 & cppMask_un_16_);
	BIT_VEC cppVar_36558 = ROM.rd(cppVar_36557);
	BIT_VEC cppVar_36559 = (cppVar_36558 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36560 = (cppVar_36559 & cppMask_un_5_);
	BIT_VEC cppVar_36561 = cppVar_36560 + 32;
	cppVar_36561 = (cppVar_36561 & cppMask_un_8_);
	cppVar_36548 = cppVar_36561;
	}
	bool cppVar_36563 = (cppVar_36548 == 184);
	if (cppVar_36563) {
	cppVar_36547 = IP;
	} else {
	BIT_VEC cppVar_36564;
	BIT_VEC cppVar_36565;
	BIT_VEC cppVar_36566 = PC + 1;
	cppVar_36566 = (cppVar_36566 & cppMask_un_16_);
	BIT_VEC cppVar_36567 = ROM.rd(cppVar_36566);
	BIT_VEC cppVar_36568 = (cppVar_36567 >> 7) & cppMask_un_1_;
	bool cppVar_36569 = (cppVar_36568 == 1);
	if (cppVar_36569) {
	BIT_VEC cppVar_36570 = PC + 1;
	cppVar_36570 = (cppVar_36570 & cppMask_un_16_);
	BIT_VEC cppVar_36571 = ROM.rd(cppVar_36570);
	BIT_VEC cppVar_36572 = (cppVar_36571 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36573 = (cppVar_36572 << 3) | 0;
	cppVar_36573 = (cppVar_36573 & cppMask_un_8_);
	cppVar_36565 = cppVar_36573;
	} else {
	BIT_VEC cppVar_36574 = PC + 1;
	cppVar_36574 = (cppVar_36574 & cppMask_un_16_);
	BIT_VEC cppVar_36575 = ROM.rd(cppVar_36574);
	BIT_VEC cppVar_36576 = (cppVar_36575 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36577 = (cppVar_36576 & cppMask_un_5_);
	BIT_VEC cppVar_36578 = cppVar_36577 + 32;
	cppVar_36578 = (cppVar_36578 & cppMask_un_8_);
	cppVar_36565 = cppVar_36578;
	}
	bool cppVar_36580 = (cppVar_36565 == 208);
	if (cppVar_36580) {
	cppVar_36564 = PSW;
	} else {
	BIT_VEC cppVar_36581;
	BIT_VEC cppVar_36582;
	BIT_VEC cppVar_36583 = PC + 1;
	cppVar_36583 = (cppVar_36583 & cppMask_un_16_);
	BIT_VEC cppVar_36584 = ROM.rd(cppVar_36583);
	BIT_VEC cppVar_36585 = (cppVar_36584 >> 7) & cppMask_un_1_;
	bool cppVar_36586 = (cppVar_36585 == 1);
	if (cppVar_36586) {
	BIT_VEC cppVar_36587 = PC + 1;
	cppVar_36587 = (cppVar_36587 & cppMask_un_16_);
	BIT_VEC cppVar_36588 = ROM.rd(cppVar_36587);
	BIT_VEC cppVar_36589 = (cppVar_36588 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36590 = (cppVar_36589 << 3) | 0;
	cppVar_36590 = (cppVar_36590 & cppMask_un_8_);
	cppVar_36582 = cppVar_36590;
	} else {
	BIT_VEC cppVar_36591 = PC + 1;
	cppVar_36591 = (cppVar_36591 & cppMask_un_16_);
	BIT_VEC cppVar_36592 = ROM.rd(cppVar_36591);
	BIT_VEC cppVar_36593 = (cppVar_36592 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36594 = (cppVar_36593 & cppMask_un_5_);
	BIT_VEC cppVar_36595 = cppVar_36594 + 32;
	cppVar_36595 = (cppVar_36595 & cppMask_un_8_);
	cppVar_36582 = cppVar_36595;
	}
	bool cppVar_36597 = (cppVar_36582 == 224);
	if (cppVar_36597) {
	cppVar_36581 = ACC;
	} else {
	BIT_VEC cppVar_36598;
	BIT_VEC cppVar_36599;
	BIT_VEC cppVar_36600 = PC + 1;
	cppVar_36600 = (cppVar_36600 & cppMask_un_16_);
	BIT_VEC cppVar_36601 = ROM.rd(cppVar_36600);
	BIT_VEC cppVar_36602 = (cppVar_36601 >> 7) & cppMask_un_1_;
	bool cppVar_36603 = (cppVar_36602 == 1);
	if (cppVar_36603) {
	BIT_VEC cppVar_36604 = PC + 1;
	cppVar_36604 = (cppVar_36604 & cppMask_un_16_);
	BIT_VEC cppVar_36605 = ROM.rd(cppVar_36604);
	BIT_VEC cppVar_36606 = (cppVar_36605 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36607 = (cppVar_36606 << 3) | 0;
	cppVar_36607 = (cppVar_36607 & cppMask_un_8_);
	cppVar_36599 = cppVar_36607;
	} else {
	BIT_VEC cppVar_36608 = PC + 1;
	cppVar_36608 = (cppVar_36608 & cppMask_un_16_);
	BIT_VEC cppVar_36609 = ROM.rd(cppVar_36608);
	BIT_VEC cppVar_36610 = (cppVar_36609 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36611 = (cppVar_36610 & cppMask_un_5_);
	BIT_VEC cppVar_36612 = cppVar_36611 + 32;
	cppVar_36612 = (cppVar_36612 & cppMask_un_8_);
	cppVar_36599 = cppVar_36612;
	}
	bool cppVar_36614 = (cppVar_36599 == 240);
	if (cppVar_36614) {
	cppVar_36598 = B;
	} else {
	cppVar_36598 = 0;
	}
	cppVar_36581 = cppVar_36598;
	}
	cppVar_36564 = cppVar_36581;
	}
	cppVar_36547 = cppVar_36564;
	}
	cppVar_36530 = cppVar_36547;
	}
	cppVar_36513 = cppVar_36530;
	}
	cppVar_36496 = cppVar_36513;
	}
	cppVar_36479 = cppVar_36496;
	}
	cppVar_36462 = cppVar_36479;
	}
	cppVar_36445 = cppVar_36462;
	}
	cppVar_36428 = cppVar_36445;
	}
	cppVar_36411 = cppVar_36428;
	}
	cppVar_36394 = cppVar_36411;
	}
	cppVar_36377 = cppVar_36394;
	}
	cppVar_36360 = cppVar_36377;
	}
	cppVar_36343 = cppVar_36360;
	}
	cppVar_36326 = cppVar_36343;
	}
	cppVar_36309 = cppVar_36326;
	}
	cppVar_36292 = cppVar_36309;
	}
	cppVar_36275 = cppVar_36292;
	}
	cppVar_36258 = cppVar_36275;
	}
	cppVar_36225 = cppVar_36258;
	}
	BIT_VEC cppVar_36616 = cppVar_36224 & cppVar_36225;
	BIT_VEC cppVar_36618 = 1;
	BIT_VEC cppVar_36619 = PC + 1;
	cppVar_36619 = (cppVar_36619 & cppMask_un_16_);
	BIT_VEC cppVar_36620 = ROM.rd(cppVar_36619);
	BIT_VEC cppVar_36621 = (cppVar_36620 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_36622 = (cppVar_36621 & cppMask_un_3_);
	BIT_VEC cppVar_36623 = cppVar_36618 << static_cast<unsigned>(cppVar_36622);
	cppVar_36623 = (cppVar_36623 & cppMask_un_8_);
	BIT_VEC cppVar_36624 = cppVar_36616 | cppVar_36623;
	cppVar_36197 = cppVar_36624;
	} else {
	cppVar_36197 = P3;
	}
	cppVar_36193 = cppVar_36197;
	} else {
	BIT_VEC cppVar_36625;
	BIT_VEC cppVar_36626 = ROM.rd(PC);
	bool cppVar_36628 = (cppVar_36626 == 208);
	if (cppVar_36628) {
	BIT_VEC cppVar_36629;
	BIT_VEC cppVar_36631 = PC + 1;
	cppVar_36631 = (cppVar_36631 & cppMask_un_16_);
	BIT_VEC cppVar_36632 = ROM.rd(cppVar_36631);
	bool cppVar_36634 = (cppVar_36632 == 176);
	if (cppVar_36634) {
	BIT_VEC cppVar_36635 = IRAM.rd(SP);
	cppVar_36629 = cppVar_36635;
	} else {
	cppVar_36629 = P3;
	}
	cppVar_36625 = cppVar_36629;
	} else {
	BIT_VEC cppVar_36636;
	BIT_VEC cppVar_36637 = ROM.rd(PC);
	bool cppVar_36639 = (cppVar_36637 == 245);
	BIT_VEC cppVar_36640 = ROM.rd(PC);
	bool cppVar_36642 = (cppVar_36640 == 197);
	bool cppVar_36643 = cppVar_36639 || cppVar_36642;
	if (cppVar_36643) {
	BIT_VEC cppVar_36644;
	BIT_VEC cppVar_36646 = PC + 1;
	cppVar_36646 = (cppVar_36646 & cppMask_un_16_);
	BIT_VEC cppVar_36647 = ROM.rd(cppVar_36646);
	bool cppVar_36649 = (cppVar_36647 == 176);
	if (cppVar_36649) {
	cppVar_36644 = ACC;
	} else {
	cppVar_36644 = P3;
	}
	cppVar_36636 = cppVar_36644;
	} else {
	BIT_VEC cppVar_36650;
	BIT_VEC cppVar_36651 = ROM.rd(PC);
	bool cppVar_36653 = (cppVar_36651 == 178);
	if (cppVar_36653) {
	BIT_VEC cppVar_36654;
	BIT_VEC cppVar_36655;
	BIT_VEC cppVar_36657 = PC + 1;
	cppVar_36657 = (cppVar_36657 & cppMask_un_16_);
	BIT_VEC cppVar_36658 = ROM.rd(cppVar_36657);
	BIT_VEC cppVar_36659 = (cppVar_36658 >> 7) & cppMask_un_1_;
	bool cppVar_36661 = (cppVar_36659 == 1);
	if (cppVar_36661) {
	BIT_VEC cppVar_36662 = PC + 1;
	cppVar_36662 = (cppVar_36662 & cppMask_un_16_);
	BIT_VEC cppVar_36663 = ROM.rd(cppVar_36662);
	BIT_VEC cppVar_36664 = (cppVar_36663 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36666 = (cppVar_36664 << 3) | 0;
	cppVar_36666 = (cppVar_36666 & cppMask_un_8_);
	cppVar_36655 = cppVar_36666;
	} else {
	BIT_VEC cppVar_36667 = PC + 1;
	cppVar_36667 = (cppVar_36667 & cppMask_un_16_);
	BIT_VEC cppVar_36668 = ROM.rd(cppVar_36667);
	BIT_VEC cppVar_36669 = (cppVar_36668 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36670 = (cppVar_36669 & cppMask_un_5_);
	BIT_VEC cppVar_36672 = cppVar_36670 + 32;
	cppVar_36672 = (cppVar_36672 & cppMask_un_8_);
	cppVar_36655 = cppVar_36672;
	}
	bool cppVar_36674 = (cppVar_36655 == 176);
	if (cppVar_36674) {
	BIT_VEC cppVar_36676 = PC + 1;
	cppVar_36676 = (cppVar_36676 & cppMask_un_16_);
	BIT_VEC cppVar_36677 = ROM.rd(cppVar_36676);
	BIT_VEC cppVar_36678 = (cppVar_36677 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_36679 = (cppVar_36678 & cppMask_un_3_);
	BIT_VEC cppVar_36680 = 1 << static_cast<unsigned>(cppVar_36679);
	cppVar_36680 = (cppVar_36680 & cppMask_un_8_);
	BIT_VEC cppVar_36681 = ~cppVar_36680;
	BIT_VEC cppVar_36682;
	BIT_VEC cppVar_36683;
	BIT_VEC cppVar_36684 = PC + 1;
	cppVar_36684 = (cppVar_36684 & cppMask_un_16_);
	BIT_VEC cppVar_36685 = ROM.rd(cppVar_36684);
	BIT_VEC cppVar_36686 = (cppVar_36685 >> 7) & cppMask_un_1_;
	bool cppVar_36687 = (cppVar_36686 == 1);
	if (cppVar_36687) {
	BIT_VEC cppVar_36688 = PC + 1;
	cppVar_36688 = (cppVar_36688 & cppMask_un_16_);
	BIT_VEC cppVar_36689 = ROM.rd(cppVar_36688);
	BIT_VEC cppVar_36690 = (cppVar_36689 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36691 = (cppVar_36690 << 3) | 0;
	cppVar_36691 = (cppVar_36691 & cppMask_un_8_);
	cppVar_36683 = cppVar_36691;
	} else {
	BIT_VEC cppVar_36692 = PC + 1;
	cppVar_36692 = (cppVar_36692 & cppMask_un_16_);
	BIT_VEC cppVar_36693 = ROM.rd(cppVar_36692);
	BIT_VEC cppVar_36694 = (cppVar_36693 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36695 = (cppVar_36694 & cppMask_un_5_);
	BIT_VEC cppVar_36696 = cppVar_36695 + 32;
	cppVar_36696 = (cppVar_36696 & cppMask_un_8_);
	cppVar_36683 = cppVar_36696;
	}
	BIT_VEC cppVar_36697 = (cppVar_36683 >> 7) & cppMask_un_1_;
	bool cppVar_36699 = (cppVar_36697 == 0);
	if (cppVar_36699) {
	BIT_VEC cppVar_36700;
	BIT_VEC cppVar_36701 = PC + 1;
	cppVar_36701 = (cppVar_36701 & cppMask_un_16_);
	BIT_VEC cppVar_36702 = ROM.rd(cppVar_36701);
	BIT_VEC cppVar_36703 = (cppVar_36702 >> 7) & cppMask_un_1_;
	bool cppVar_36704 = (cppVar_36703 == 1);
	if (cppVar_36704) {
	BIT_VEC cppVar_36705 = PC + 1;
	cppVar_36705 = (cppVar_36705 & cppMask_un_16_);
	BIT_VEC cppVar_36706 = ROM.rd(cppVar_36705);
	BIT_VEC cppVar_36707 = (cppVar_36706 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36708 = (cppVar_36707 << 3) | 0;
	cppVar_36708 = (cppVar_36708 & cppMask_un_8_);
	cppVar_36700 = cppVar_36708;
	} else {
	BIT_VEC cppVar_36709 = PC + 1;
	cppVar_36709 = (cppVar_36709 & cppMask_un_16_);
	BIT_VEC cppVar_36710 = ROM.rd(cppVar_36709);
	BIT_VEC cppVar_36711 = (cppVar_36710 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36712 = (cppVar_36711 & cppMask_un_5_);
	BIT_VEC cppVar_36713 = cppVar_36712 + 32;
	cppVar_36713 = (cppVar_36713 & cppMask_un_8_);
	cppVar_36700 = cppVar_36713;
	}
	BIT_VEC cppVar_36714 = IRAM.rd(cppVar_36700);
	cppVar_36682 = cppVar_36714;
	} else {
	BIT_VEC cppVar_36715;
	BIT_VEC cppVar_36716;
	BIT_VEC cppVar_36717 = PC + 1;
	cppVar_36717 = (cppVar_36717 & cppMask_un_16_);
	BIT_VEC cppVar_36718 = ROM.rd(cppVar_36717);
	BIT_VEC cppVar_36719 = (cppVar_36718 >> 7) & cppMask_un_1_;
	bool cppVar_36720 = (cppVar_36719 == 1);
	if (cppVar_36720) {
	BIT_VEC cppVar_36721 = PC + 1;
	cppVar_36721 = (cppVar_36721 & cppMask_un_16_);
	BIT_VEC cppVar_36722 = ROM.rd(cppVar_36721);
	BIT_VEC cppVar_36723 = (cppVar_36722 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36724 = (cppVar_36723 << 3) | 0;
	cppVar_36724 = (cppVar_36724 & cppMask_un_8_);
	cppVar_36716 = cppVar_36724;
	} else {
	BIT_VEC cppVar_36725 = PC + 1;
	cppVar_36725 = (cppVar_36725 & cppMask_un_16_);
	BIT_VEC cppVar_36726 = ROM.rd(cppVar_36725);
	BIT_VEC cppVar_36727 = (cppVar_36726 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36728 = (cppVar_36727 & cppMask_un_5_);
	BIT_VEC cppVar_36729 = cppVar_36728 + 32;
	cppVar_36729 = (cppVar_36729 & cppMask_un_8_);
	cppVar_36716 = cppVar_36729;
	}
	bool cppVar_36731 = (cppVar_36716 == 128);
	if (cppVar_36731) {
	cppVar_36715 = P0;
	} else {
	BIT_VEC cppVar_36732;
	BIT_VEC cppVar_36733;
	BIT_VEC cppVar_36734 = PC + 1;
	cppVar_36734 = (cppVar_36734 & cppMask_un_16_);
	BIT_VEC cppVar_36735 = ROM.rd(cppVar_36734);
	BIT_VEC cppVar_36736 = (cppVar_36735 >> 7) & cppMask_un_1_;
	bool cppVar_36737 = (cppVar_36736 == 1);
	if (cppVar_36737) {
	BIT_VEC cppVar_36738 = PC + 1;
	cppVar_36738 = (cppVar_36738 & cppMask_un_16_);
	BIT_VEC cppVar_36739 = ROM.rd(cppVar_36738);
	BIT_VEC cppVar_36740 = (cppVar_36739 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36741 = (cppVar_36740 << 3) | 0;
	cppVar_36741 = (cppVar_36741 & cppMask_un_8_);
	cppVar_36733 = cppVar_36741;
	} else {
	BIT_VEC cppVar_36742 = PC + 1;
	cppVar_36742 = (cppVar_36742 & cppMask_un_16_);
	BIT_VEC cppVar_36743 = ROM.rd(cppVar_36742);
	BIT_VEC cppVar_36744 = (cppVar_36743 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36745 = (cppVar_36744 & cppMask_un_5_);
	BIT_VEC cppVar_36746 = cppVar_36745 + 32;
	cppVar_36746 = (cppVar_36746 & cppMask_un_8_);
	cppVar_36733 = cppVar_36746;
	}
	bool cppVar_36748 = (cppVar_36733 == 129);
	if (cppVar_36748) {
	cppVar_36732 = SP;
	} else {
	BIT_VEC cppVar_36749;
	BIT_VEC cppVar_36750;
	BIT_VEC cppVar_36751 = PC + 1;
	cppVar_36751 = (cppVar_36751 & cppMask_un_16_);
	BIT_VEC cppVar_36752 = ROM.rd(cppVar_36751);
	BIT_VEC cppVar_36753 = (cppVar_36752 >> 7) & cppMask_un_1_;
	bool cppVar_36754 = (cppVar_36753 == 1);
	if (cppVar_36754) {
	BIT_VEC cppVar_36755 = PC + 1;
	cppVar_36755 = (cppVar_36755 & cppMask_un_16_);
	BIT_VEC cppVar_36756 = ROM.rd(cppVar_36755);
	BIT_VEC cppVar_36757 = (cppVar_36756 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36758 = (cppVar_36757 << 3) | 0;
	cppVar_36758 = (cppVar_36758 & cppMask_un_8_);
	cppVar_36750 = cppVar_36758;
	} else {
	BIT_VEC cppVar_36759 = PC + 1;
	cppVar_36759 = (cppVar_36759 & cppMask_un_16_);
	BIT_VEC cppVar_36760 = ROM.rd(cppVar_36759);
	BIT_VEC cppVar_36761 = (cppVar_36760 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36762 = (cppVar_36761 & cppMask_un_5_);
	BIT_VEC cppVar_36763 = cppVar_36762 + 32;
	cppVar_36763 = (cppVar_36763 & cppMask_un_8_);
	cppVar_36750 = cppVar_36763;
	}
	bool cppVar_36765 = (cppVar_36750 == 130);
	if (cppVar_36765) {
	cppVar_36749 = DPL;
	} else {
	BIT_VEC cppVar_36766;
	BIT_VEC cppVar_36767;
	BIT_VEC cppVar_36768 = PC + 1;
	cppVar_36768 = (cppVar_36768 & cppMask_un_16_);
	BIT_VEC cppVar_36769 = ROM.rd(cppVar_36768);
	BIT_VEC cppVar_36770 = (cppVar_36769 >> 7) & cppMask_un_1_;
	bool cppVar_36771 = (cppVar_36770 == 1);
	if (cppVar_36771) {
	BIT_VEC cppVar_36772 = PC + 1;
	cppVar_36772 = (cppVar_36772 & cppMask_un_16_);
	BIT_VEC cppVar_36773 = ROM.rd(cppVar_36772);
	BIT_VEC cppVar_36774 = (cppVar_36773 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36775 = (cppVar_36774 << 3) | 0;
	cppVar_36775 = (cppVar_36775 & cppMask_un_8_);
	cppVar_36767 = cppVar_36775;
	} else {
	BIT_VEC cppVar_36776 = PC + 1;
	cppVar_36776 = (cppVar_36776 & cppMask_un_16_);
	BIT_VEC cppVar_36777 = ROM.rd(cppVar_36776);
	BIT_VEC cppVar_36778 = (cppVar_36777 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36779 = (cppVar_36778 & cppMask_un_5_);
	BIT_VEC cppVar_36780 = cppVar_36779 + 32;
	cppVar_36780 = (cppVar_36780 & cppMask_un_8_);
	cppVar_36767 = cppVar_36780;
	}
	bool cppVar_36782 = (cppVar_36767 == 131);
	if (cppVar_36782) {
	cppVar_36766 = DPH;
	} else {
	BIT_VEC cppVar_36783;
	BIT_VEC cppVar_36784;
	BIT_VEC cppVar_36785 = PC + 1;
	cppVar_36785 = (cppVar_36785 & cppMask_un_16_);
	BIT_VEC cppVar_36786 = ROM.rd(cppVar_36785);
	BIT_VEC cppVar_36787 = (cppVar_36786 >> 7) & cppMask_un_1_;
	bool cppVar_36788 = (cppVar_36787 == 1);
	if (cppVar_36788) {
	BIT_VEC cppVar_36789 = PC + 1;
	cppVar_36789 = (cppVar_36789 & cppMask_un_16_);
	BIT_VEC cppVar_36790 = ROM.rd(cppVar_36789);
	BIT_VEC cppVar_36791 = (cppVar_36790 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36792 = (cppVar_36791 << 3) | 0;
	cppVar_36792 = (cppVar_36792 & cppMask_un_8_);
	cppVar_36784 = cppVar_36792;
	} else {
	BIT_VEC cppVar_36793 = PC + 1;
	cppVar_36793 = (cppVar_36793 & cppMask_un_16_);
	BIT_VEC cppVar_36794 = ROM.rd(cppVar_36793);
	BIT_VEC cppVar_36795 = (cppVar_36794 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36796 = (cppVar_36795 & cppMask_un_5_);
	BIT_VEC cppVar_36797 = cppVar_36796 + 32;
	cppVar_36797 = (cppVar_36797 & cppMask_un_8_);
	cppVar_36784 = cppVar_36797;
	}
	bool cppVar_36799 = (cppVar_36784 == 135);
	if (cppVar_36799) {
	cppVar_36783 = PCON;
	} else {
	BIT_VEC cppVar_36800;
	BIT_VEC cppVar_36801;
	BIT_VEC cppVar_36802 = PC + 1;
	cppVar_36802 = (cppVar_36802 & cppMask_un_16_);
	BIT_VEC cppVar_36803 = ROM.rd(cppVar_36802);
	BIT_VEC cppVar_36804 = (cppVar_36803 >> 7) & cppMask_un_1_;
	bool cppVar_36805 = (cppVar_36804 == 1);
	if (cppVar_36805) {
	BIT_VEC cppVar_36806 = PC + 1;
	cppVar_36806 = (cppVar_36806 & cppMask_un_16_);
	BIT_VEC cppVar_36807 = ROM.rd(cppVar_36806);
	BIT_VEC cppVar_36808 = (cppVar_36807 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36809 = (cppVar_36808 << 3) | 0;
	cppVar_36809 = (cppVar_36809 & cppMask_un_8_);
	cppVar_36801 = cppVar_36809;
	} else {
	BIT_VEC cppVar_36810 = PC + 1;
	cppVar_36810 = (cppVar_36810 & cppMask_un_16_);
	BIT_VEC cppVar_36811 = ROM.rd(cppVar_36810);
	BIT_VEC cppVar_36812 = (cppVar_36811 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36813 = (cppVar_36812 & cppMask_un_5_);
	BIT_VEC cppVar_36814 = cppVar_36813 + 32;
	cppVar_36814 = (cppVar_36814 & cppMask_un_8_);
	cppVar_36801 = cppVar_36814;
	}
	bool cppVar_36816 = (cppVar_36801 == 136);
	if (cppVar_36816) {
	cppVar_36800 = TCON;
	} else {
	BIT_VEC cppVar_36817;
	BIT_VEC cppVar_36818;
	BIT_VEC cppVar_36819 = PC + 1;
	cppVar_36819 = (cppVar_36819 & cppMask_un_16_);
	BIT_VEC cppVar_36820 = ROM.rd(cppVar_36819);
	BIT_VEC cppVar_36821 = (cppVar_36820 >> 7) & cppMask_un_1_;
	bool cppVar_36822 = (cppVar_36821 == 1);
	if (cppVar_36822) {
	BIT_VEC cppVar_36823 = PC + 1;
	cppVar_36823 = (cppVar_36823 & cppMask_un_16_);
	BIT_VEC cppVar_36824 = ROM.rd(cppVar_36823);
	BIT_VEC cppVar_36825 = (cppVar_36824 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36826 = (cppVar_36825 << 3) | 0;
	cppVar_36826 = (cppVar_36826 & cppMask_un_8_);
	cppVar_36818 = cppVar_36826;
	} else {
	BIT_VEC cppVar_36827 = PC + 1;
	cppVar_36827 = (cppVar_36827 & cppMask_un_16_);
	BIT_VEC cppVar_36828 = ROM.rd(cppVar_36827);
	BIT_VEC cppVar_36829 = (cppVar_36828 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36830 = (cppVar_36829 & cppMask_un_5_);
	BIT_VEC cppVar_36831 = cppVar_36830 + 32;
	cppVar_36831 = (cppVar_36831 & cppMask_un_8_);
	cppVar_36818 = cppVar_36831;
	}
	bool cppVar_36833 = (cppVar_36818 == 137);
	if (cppVar_36833) {
	cppVar_36817 = TMOD;
	} else {
	BIT_VEC cppVar_36834;
	BIT_VEC cppVar_36835;
	BIT_VEC cppVar_36836 = PC + 1;
	cppVar_36836 = (cppVar_36836 & cppMask_un_16_);
	BIT_VEC cppVar_36837 = ROM.rd(cppVar_36836);
	BIT_VEC cppVar_36838 = (cppVar_36837 >> 7) & cppMask_un_1_;
	bool cppVar_36839 = (cppVar_36838 == 1);
	if (cppVar_36839) {
	BIT_VEC cppVar_36840 = PC + 1;
	cppVar_36840 = (cppVar_36840 & cppMask_un_16_);
	BIT_VEC cppVar_36841 = ROM.rd(cppVar_36840);
	BIT_VEC cppVar_36842 = (cppVar_36841 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36843 = (cppVar_36842 << 3) | 0;
	cppVar_36843 = (cppVar_36843 & cppMask_un_8_);
	cppVar_36835 = cppVar_36843;
	} else {
	BIT_VEC cppVar_36844 = PC + 1;
	cppVar_36844 = (cppVar_36844 & cppMask_un_16_);
	BIT_VEC cppVar_36845 = ROM.rd(cppVar_36844);
	BIT_VEC cppVar_36846 = (cppVar_36845 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36847 = (cppVar_36846 & cppMask_un_5_);
	BIT_VEC cppVar_36848 = cppVar_36847 + 32;
	cppVar_36848 = (cppVar_36848 & cppMask_un_8_);
	cppVar_36835 = cppVar_36848;
	}
	bool cppVar_36850 = (cppVar_36835 == 138);
	if (cppVar_36850) {
	cppVar_36834 = TL0;
	} else {
	BIT_VEC cppVar_36851;
	BIT_VEC cppVar_36852;
	BIT_VEC cppVar_36853 = PC + 1;
	cppVar_36853 = (cppVar_36853 & cppMask_un_16_);
	BIT_VEC cppVar_36854 = ROM.rd(cppVar_36853);
	BIT_VEC cppVar_36855 = (cppVar_36854 >> 7) & cppMask_un_1_;
	bool cppVar_36856 = (cppVar_36855 == 1);
	if (cppVar_36856) {
	BIT_VEC cppVar_36857 = PC + 1;
	cppVar_36857 = (cppVar_36857 & cppMask_un_16_);
	BIT_VEC cppVar_36858 = ROM.rd(cppVar_36857);
	BIT_VEC cppVar_36859 = (cppVar_36858 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36860 = (cppVar_36859 << 3) | 0;
	cppVar_36860 = (cppVar_36860 & cppMask_un_8_);
	cppVar_36852 = cppVar_36860;
	} else {
	BIT_VEC cppVar_36861 = PC + 1;
	cppVar_36861 = (cppVar_36861 & cppMask_un_16_);
	BIT_VEC cppVar_36862 = ROM.rd(cppVar_36861);
	BIT_VEC cppVar_36863 = (cppVar_36862 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36864 = (cppVar_36863 & cppMask_un_5_);
	BIT_VEC cppVar_36865 = cppVar_36864 + 32;
	cppVar_36865 = (cppVar_36865 & cppMask_un_8_);
	cppVar_36852 = cppVar_36865;
	}
	bool cppVar_36867 = (cppVar_36852 == 140);
	if (cppVar_36867) {
	cppVar_36851 = TH0;
	} else {
	BIT_VEC cppVar_36868;
	BIT_VEC cppVar_36869;
	BIT_VEC cppVar_36870 = PC + 1;
	cppVar_36870 = (cppVar_36870 & cppMask_un_16_);
	BIT_VEC cppVar_36871 = ROM.rd(cppVar_36870);
	BIT_VEC cppVar_36872 = (cppVar_36871 >> 7) & cppMask_un_1_;
	bool cppVar_36873 = (cppVar_36872 == 1);
	if (cppVar_36873) {
	BIT_VEC cppVar_36874 = PC + 1;
	cppVar_36874 = (cppVar_36874 & cppMask_un_16_);
	BIT_VEC cppVar_36875 = ROM.rd(cppVar_36874);
	BIT_VEC cppVar_36876 = (cppVar_36875 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36877 = (cppVar_36876 << 3) | 0;
	cppVar_36877 = (cppVar_36877 & cppMask_un_8_);
	cppVar_36869 = cppVar_36877;
	} else {
	BIT_VEC cppVar_36878 = PC + 1;
	cppVar_36878 = (cppVar_36878 & cppMask_un_16_);
	BIT_VEC cppVar_36879 = ROM.rd(cppVar_36878);
	BIT_VEC cppVar_36880 = (cppVar_36879 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36881 = (cppVar_36880 & cppMask_un_5_);
	BIT_VEC cppVar_36882 = cppVar_36881 + 32;
	cppVar_36882 = (cppVar_36882 & cppMask_un_8_);
	cppVar_36869 = cppVar_36882;
	}
	bool cppVar_36884 = (cppVar_36869 == 139);
	if (cppVar_36884) {
	cppVar_36868 = TL1;
	} else {
	BIT_VEC cppVar_36885;
	BIT_VEC cppVar_36886;
	BIT_VEC cppVar_36887 = PC + 1;
	cppVar_36887 = (cppVar_36887 & cppMask_un_16_);
	BIT_VEC cppVar_36888 = ROM.rd(cppVar_36887);
	BIT_VEC cppVar_36889 = (cppVar_36888 >> 7) & cppMask_un_1_;
	bool cppVar_36890 = (cppVar_36889 == 1);
	if (cppVar_36890) {
	BIT_VEC cppVar_36891 = PC + 1;
	cppVar_36891 = (cppVar_36891 & cppMask_un_16_);
	BIT_VEC cppVar_36892 = ROM.rd(cppVar_36891);
	BIT_VEC cppVar_36893 = (cppVar_36892 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36894 = (cppVar_36893 << 3) | 0;
	cppVar_36894 = (cppVar_36894 & cppMask_un_8_);
	cppVar_36886 = cppVar_36894;
	} else {
	BIT_VEC cppVar_36895 = PC + 1;
	cppVar_36895 = (cppVar_36895 & cppMask_un_16_);
	BIT_VEC cppVar_36896 = ROM.rd(cppVar_36895);
	BIT_VEC cppVar_36897 = (cppVar_36896 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36898 = (cppVar_36897 & cppMask_un_5_);
	BIT_VEC cppVar_36899 = cppVar_36898 + 32;
	cppVar_36899 = (cppVar_36899 & cppMask_un_8_);
	cppVar_36886 = cppVar_36899;
	}
	bool cppVar_36901 = (cppVar_36886 == 141);
	if (cppVar_36901) {
	cppVar_36885 = TH1;
	} else {
	BIT_VEC cppVar_36902;
	BIT_VEC cppVar_36903;
	BIT_VEC cppVar_36904 = PC + 1;
	cppVar_36904 = (cppVar_36904 & cppMask_un_16_);
	BIT_VEC cppVar_36905 = ROM.rd(cppVar_36904);
	BIT_VEC cppVar_36906 = (cppVar_36905 >> 7) & cppMask_un_1_;
	bool cppVar_36907 = (cppVar_36906 == 1);
	if (cppVar_36907) {
	BIT_VEC cppVar_36908 = PC + 1;
	cppVar_36908 = (cppVar_36908 & cppMask_un_16_);
	BIT_VEC cppVar_36909 = ROM.rd(cppVar_36908);
	BIT_VEC cppVar_36910 = (cppVar_36909 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36911 = (cppVar_36910 << 3) | 0;
	cppVar_36911 = (cppVar_36911 & cppMask_un_8_);
	cppVar_36903 = cppVar_36911;
	} else {
	BIT_VEC cppVar_36912 = PC + 1;
	cppVar_36912 = (cppVar_36912 & cppMask_un_16_);
	BIT_VEC cppVar_36913 = ROM.rd(cppVar_36912);
	BIT_VEC cppVar_36914 = (cppVar_36913 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36915 = (cppVar_36914 & cppMask_un_5_);
	BIT_VEC cppVar_36916 = cppVar_36915 + 32;
	cppVar_36916 = (cppVar_36916 & cppMask_un_8_);
	cppVar_36903 = cppVar_36916;
	}
	bool cppVar_36918 = (cppVar_36903 == 144);
	if (cppVar_36918) {
	cppVar_36902 = P1;
	} else {
	BIT_VEC cppVar_36919;
	BIT_VEC cppVar_36920;
	BIT_VEC cppVar_36921 = PC + 1;
	cppVar_36921 = (cppVar_36921 & cppMask_un_16_);
	BIT_VEC cppVar_36922 = ROM.rd(cppVar_36921);
	BIT_VEC cppVar_36923 = (cppVar_36922 >> 7) & cppMask_un_1_;
	bool cppVar_36924 = (cppVar_36923 == 1);
	if (cppVar_36924) {
	BIT_VEC cppVar_36925 = PC + 1;
	cppVar_36925 = (cppVar_36925 & cppMask_un_16_);
	BIT_VEC cppVar_36926 = ROM.rd(cppVar_36925);
	BIT_VEC cppVar_36927 = (cppVar_36926 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36928 = (cppVar_36927 << 3) | 0;
	cppVar_36928 = (cppVar_36928 & cppMask_un_8_);
	cppVar_36920 = cppVar_36928;
	} else {
	BIT_VEC cppVar_36929 = PC + 1;
	cppVar_36929 = (cppVar_36929 & cppMask_un_16_);
	BIT_VEC cppVar_36930 = ROM.rd(cppVar_36929);
	BIT_VEC cppVar_36931 = (cppVar_36930 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36932 = (cppVar_36931 & cppMask_un_5_);
	BIT_VEC cppVar_36933 = cppVar_36932 + 32;
	cppVar_36933 = (cppVar_36933 & cppMask_un_8_);
	cppVar_36920 = cppVar_36933;
	}
	bool cppVar_36935 = (cppVar_36920 == 152);
	if (cppVar_36935) {
	cppVar_36919 = SCON;
	} else {
	BIT_VEC cppVar_36936;
	BIT_VEC cppVar_36937;
	BIT_VEC cppVar_36938 = PC + 1;
	cppVar_36938 = (cppVar_36938 & cppMask_un_16_);
	BIT_VEC cppVar_36939 = ROM.rd(cppVar_36938);
	BIT_VEC cppVar_36940 = (cppVar_36939 >> 7) & cppMask_un_1_;
	bool cppVar_36941 = (cppVar_36940 == 1);
	if (cppVar_36941) {
	BIT_VEC cppVar_36942 = PC + 1;
	cppVar_36942 = (cppVar_36942 & cppMask_un_16_);
	BIT_VEC cppVar_36943 = ROM.rd(cppVar_36942);
	BIT_VEC cppVar_36944 = (cppVar_36943 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36945 = (cppVar_36944 << 3) | 0;
	cppVar_36945 = (cppVar_36945 & cppMask_un_8_);
	cppVar_36937 = cppVar_36945;
	} else {
	BIT_VEC cppVar_36946 = PC + 1;
	cppVar_36946 = (cppVar_36946 & cppMask_un_16_);
	BIT_VEC cppVar_36947 = ROM.rd(cppVar_36946);
	BIT_VEC cppVar_36948 = (cppVar_36947 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36949 = (cppVar_36948 & cppMask_un_5_);
	BIT_VEC cppVar_36950 = cppVar_36949 + 32;
	cppVar_36950 = (cppVar_36950 & cppMask_un_8_);
	cppVar_36937 = cppVar_36950;
	}
	bool cppVar_36952 = (cppVar_36937 == 153);
	if (cppVar_36952) {
	cppVar_36936 = SBUF;
	} else {
	BIT_VEC cppVar_36953;
	BIT_VEC cppVar_36954;
	BIT_VEC cppVar_36955 = PC + 1;
	cppVar_36955 = (cppVar_36955 & cppMask_un_16_);
	BIT_VEC cppVar_36956 = ROM.rd(cppVar_36955);
	BIT_VEC cppVar_36957 = (cppVar_36956 >> 7) & cppMask_un_1_;
	bool cppVar_36958 = (cppVar_36957 == 1);
	if (cppVar_36958) {
	BIT_VEC cppVar_36959 = PC + 1;
	cppVar_36959 = (cppVar_36959 & cppMask_un_16_);
	BIT_VEC cppVar_36960 = ROM.rd(cppVar_36959);
	BIT_VEC cppVar_36961 = (cppVar_36960 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36962 = (cppVar_36961 << 3) | 0;
	cppVar_36962 = (cppVar_36962 & cppMask_un_8_);
	cppVar_36954 = cppVar_36962;
	} else {
	BIT_VEC cppVar_36963 = PC + 1;
	cppVar_36963 = (cppVar_36963 & cppMask_un_16_);
	BIT_VEC cppVar_36964 = ROM.rd(cppVar_36963);
	BIT_VEC cppVar_36965 = (cppVar_36964 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36966 = (cppVar_36965 & cppMask_un_5_);
	BIT_VEC cppVar_36967 = cppVar_36966 + 32;
	cppVar_36967 = (cppVar_36967 & cppMask_un_8_);
	cppVar_36954 = cppVar_36967;
	}
	bool cppVar_36969 = (cppVar_36954 == 160);
	if (cppVar_36969) {
	cppVar_36953 = P2;
	} else {
	BIT_VEC cppVar_36970;
	BIT_VEC cppVar_36971;
	BIT_VEC cppVar_36972 = PC + 1;
	cppVar_36972 = (cppVar_36972 & cppMask_un_16_);
	BIT_VEC cppVar_36973 = ROM.rd(cppVar_36972);
	BIT_VEC cppVar_36974 = (cppVar_36973 >> 7) & cppMask_un_1_;
	bool cppVar_36975 = (cppVar_36974 == 1);
	if (cppVar_36975) {
	BIT_VEC cppVar_36976 = PC + 1;
	cppVar_36976 = (cppVar_36976 & cppMask_un_16_);
	BIT_VEC cppVar_36977 = ROM.rd(cppVar_36976);
	BIT_VEC cppVar_36978 = (cppVar_36977 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36979 = (cppVar_36978 << 3) | 0;
	cppVar_36979 = (cppVar_36979 & cppMask_un_8_);
	cppVar_36971 = cppVar_36979;
	} else {
	BIT_VEC cppVar_36980 = PC + 1;
	cppVar_36980 = (cppVar_36980 & cppMask_un_16_);
	BIT_VEC cppVar_36981 = ROM.rd(cppVar_36980);
	BIT_VEC cppVar_36982 = (cppVar_36981 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36983 = (cppVar_36982 & cppMask_un_5_);
	BIT_VEC cppVar_36984 = cppVar_36983 + 32;
	cppVar_36984 = (cppVar_36984 & cppMask_un_8_);
	cppVar_36971 = cppVar_36984;
	}
	bool cppVar_36986 = (cppVar_36971 == 168);
	if (cppVar_36986) {
	cppVar_36970 = IE;
	} else {
	BIT_VEC cppVar_36987;
	BIT_VEC cppVar_36988;
	BIT_VEC cppVar_36989 = PC + 1;
	cppVar_36989 = (cppVar_36989 & cppMask_un_16_);
	BIT_VEC cppVar_36990 = ROM.rd(cppVar_36989);
	BIT_VEC cppVar_36991 = (cppVar_36990 >> 7) & cppMask_un_1_;
	bool cppVar_36992 = (cppVar_36991 == 1);
	if (cppVar_36992) {
	BIT_VEC cppVar_36993 = PC + 1;
	cppVar_36993 = (cppVar_36993 & cppMask_un_16_);
	BIT_VEC cppVar_36994 = ROM.rd(cppVar_36993);
	BIT_VEC cppVar_36995 = (cppVar_36994 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_36996 = (cppVar_36995 << 3) | 0;
	cppVar_36996 = (cppVar_36996 & cppMask_un_8_);
	cppVar_36988 = cppVar_36996;
	} else {
	BIT_VEC cppVar_36997 = PC + 1;
	cppVar_36997 = (cppVar_36997 & cppMask_un_16_);
	BIT_VEC cppVar_36998 = ROM.rd(cppVar_36997);
	BIT_VEC cppVar_36999 = (cppVar_36998 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37000 = (cppVar_36999 & cppMask_un_5_);
	BIT_VEC cppVar_37001 = cppVar_37000 + 32;
	cppVar_37001 = (cppVar_37001 & cppMask_un_8_);
	cppVar_36988 = cppVar_37001;
	}
	bool cppVar_37003 = (cppVar_36988 == 176);
	if (cppVar_37003) {
	cppVar_36987 = P3;
	} else {
	BIT_VEC cppVar_37004;
	BIT_VEC cppVar_37005;
	BIT_VEC cppVar_37006 = PC + 1;
	cppVar_37006 = (cppVar_37006 & cppMask_un_16_);
	BIT_VEC cppVar_37007 = ROM.rd(cppVar_37006);
	BIT_VEC cppVar_37008 = (cppVar_37007 >> 7) & cppMask_un_1_;
	bool cppVar_37009 = (cppVar_37008 == 1);
	if (cppVar_37009) {
	BIT_VEC cppVar_37010 = PC + 1;
	cppVar_37010 = (cppVar_37010 & cppMask_un_16_);
	BIT_VEC cppVar_37011 = ROM.rd(cppVar_37010);
	BIT_VEC cppVar_37012 = (cppVar_37011 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37013 = (cppVar_37012 << 3) | 0;
	cppVar_37013 = (cppVar_37013 & cppMask_un_8_);
	cppVar_37005 = cppVar_37013;
	} else {
	BIT_VEC cppVar_37014 = PC + 1;
	cppVar_37014 = (cppVar_37014 & cppMask_un_16_);
	BIT_VEC cppVar_37015 = ROM.rd(cppVar_37014);
	BIT_VEC cppVar_37016 = (cppVar_37015 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37017 = (cppVar_37016 & cppMask_un_5_);
	BIT_VEC cppVar_37018 = cppVar_37017 + 32;
	cppVar_37018 = (cppVar_37018 & cppMask_un_8_);
	cppVar_37005 = cppVar_37018;
	}
	bool cppVar_37020 = (cppVar_37005 == 184);
	if (cppVar_37020) {
	cppVar_37004 = IP;
	} else {
	BIT_VEC cppVar_37021;
	BIT_VEC cppVar_37022;
	BIT_VEC cppVar_37023 = PC + 1;
	cppVar_37023 = (cppVar_37023 & cppMask_un_16_);
	BIT_VEC cppVar_37024 = ROM.rd(cppVar_37023);
	BIT_VEC cppVar_37025 = (cppVar_37024 >> 7) & cppMask_un_1_;
	bool cppVar_37026 = (cppVar_37025 == 1);
	if (cppVar_37026) {
	BIT_VEC cppVar_37027 = PC + 1;
	cppVar_37027 = (cppVar_37027 & cppMask_un_16_);
	BIT_VEC cppVar_37028 = ROM.rd(cppVar_37027);
	BIT_VEC cppVar_37029 = (cppVar_37028 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37030 = (cppVar_37029 << 3) | 0;
	cppVar_37030 = (cppVar_37030 & cppMask_un_8_);
	cppVar_37022 = cppVar_37030;
	} else {
	BIT_VEC cppVar_37031 = PC + 1;
	cppVar_37031 = (cppVar_37031 & cppMask_un_16_);
	BIT_VEC cppVar_37032 = ROM.rd(cppVar_37031);
	BIT_VEC cppVar_37033 = (cppVar_37032 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37034 = (cppVar_37033 & cppMask_un_5_);
	BIT_VEC cppVar_37035 = cppVar_37034 + 32;
	cppVar_37035 = (cppVar_37035 & cppMask_un_8_);
	cppVar_37022 = cppVar_37035;
	}
	bool cppVar_37037 = (cppVar_37022 == 208);
	if (cppVar_37037) {
	cppVar_37021 = PSW;
	} else {
	BIT_VEC cppVar_37038;
	BIT_VEC cppVar_37039;
	BIT_VEC cppVar_37040 = PC + 1;
	cppVar_37040 = (cppVar_37040 & cppMask_un_16_);
	BIT_VEC cppVar_37041 = ROM.rd(cppVar_37040);
	BIT_VEC cppVar_37042 = (cppVar_37041 >> 7) & cppMask_un_1_;
	bool cppVar_37043 = (cppVar_37042 == 1);
	if (cppVar_37043) {
	BIT_VEC cppVar_37044 = PC + 1;
	cppVar_37044 = (cppVar_37044 & cppMask_un_16_);
	BIT_VEC cppVar_37045 = ROM.rd(cppVar_37044);
	BIT_VEC cppVar_37046 = (cppVar_37045 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37047 = (cppVar_37046 << 3) | 0;
	cppVar_37047 = (cppVar_37047 & cppMask_un_8_);
	cppVar_37039 = cppVar_37047;
	} else {
	BIT_VEC cppVar_37048 = PC + 1;
	cppVar_37048 = (cppVar_37048 & cppMask_un_16_);
	BIT_VEC cppVar_37049 = ROM.rd(cppVar_37048);
	BIT_VEC cppVar_37050 = (cppVar_37049 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37051 = (cppVar_37050 & cppMask_un_5_);
	BIT_VEC cppVar_37052 = cppVar_37051 + 32;
	cppVar_37052 = (cppVar_37052 & cppMask_un_8_);
	cppVar_37039 = cppVar_37052;
	}
	bool cppVar_37054 = (cppVar_37039 == 224);
	if (cppVar_37054) {
	cppVar_37038 = ACC;
	} else {
	BIT_VEC cppVar_37055;
	BIT_VEC cppVar_37056;
	BIT_VEC cppVar_37057 = PC + 1;
	cppVar_37057 = (cppVar_37057 & cppMask_un_16_);
	BIT_VEC cppVar_37058 = ROM.rd(cppVar_37057);
	BIT_VEC cppVar_37059 = (cppVar_37058 >> 7) & cppMask_un_1_;
	bool cppVar_37060 = (cppVar_37059 == 1);
	if (cppVar_37060) {
	BIT_VEC cppVar_37061 = PC + 1;
	cppVar_37061 = (cppVar_37061 & cppMask_un_16_);
	BIT_VEC cppVar_37062 = ROM.rd(cppVar_37061);
	BIT_VEC cppVar_37063 = (cppVar_37062 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37064 = (cppVar_37063 << 3) | 0;
	cppVar_37064 = (cppVar_37064 & cppMask_un_8_);
	cppVar_37056 = cppVar_37064;
	} else {
	BIT_VEC cppVar_37065 = PC + 1;
	cppVar_37065 = (cppVar_37065 & cppMask_un_16_);
	BIT_VEC cppVar_37066 = ROM.rd(cppVar_37065);
	BIT_VEC cppVar_37067 = (cppVar_37066 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37068 = (cppVar_37067 & cppMask_un_5_);
	BIT_VEC cppVar_37069 = cppVar_37068 + 32;
	cppVar_37069 = (cppVar_37069 & cppMask_un_8_);
	cppVar_37056 = cppVar_37069;
	}
	bool cppVar_37071 = (cppVar_37056 == 240);
	if (cppVar_37071) {
	cppVar_37055 = B;
	} else {
	cppVar_37055 = 0;
	}
	cppVar_37038 = cppVar_37055;
	}
	cppVar_37021 = cppVar_37038;
	}
	cppVar_37004 = cppVar_37021;
	}
	cppVar_36987 = cppVar_37004;
	}
	cppVar_36970 = cppVar_36987;
	}
	cppVar_36953 = cppVar_36970;
	}
	cppVar_36936 = cppVar_36953;
	}
	cppVar_36919 = cppVar_36936;
	}
	cppVar_36902 = cppVar_36919;
	}
	cppVar_36885 = cppVar_36902;
	}
	cppVar_36868 = cppVar_36885;
	}
	cppVar_36851 = cppVar_36868;
	}
	cppVar_36834 = cppVar_36851;
	}
	cppVar_36817 = cppVar_36834;
	}
	cppVar_36800 = cppVar_36817;
	}
	cppVar_36783 = cppVar_36800;
	}
	cppVar_36766 = cppVar_36783;
	}
	cppVar_36749 = cppVar_36766;
	}
	cppVar_36732 = cppVar_36749;
	}
	cppVar_36715 = cppVar_36732;
	}
	cppVar_36682 = cppVar_36715;
	}
	BIT_VEC cppVar_37073 = cppVar_36681 & cppVar_36682;
	BIT_VEC cppVar_37074;
	BIT_VEC cppVar_37075;
	BIT_VEC cppVar_37076 = PC + 1;
	cppVar_37076 = (cppVar_37076 & cppMask_un_16_);
	BIT_VEC cppVar_37077 = ROM.rd(cppVar_37076);
	BIT_VEC cppVar_37078 = (cppVar_37077 >> 7) & cppMask_un_1_;
	bool cppVar_37080 = (cppVar_37078 == 1);
	if (cppVar_37080) {
	BIT_VEC cppVar_37081 = PC + 1;
	cppVar_37081 = (cppVar_37081 & cppMask_un_16_);
	BIT_VEC cppVar_37082 = ROM.rd(cppVar_37081);
	BIT_VEC cppVar_37083 = (cppVar_37082 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37085 = (cppVar_37083 << 3) | 0;
	cppVar_37085 = (cppVar_37085 & cppMask_un_8_);
	cppVar_37075 = cppVar_37085;
	} else {
	BIT_VEC cppVar_37086 = PC + 1;
	cppVar_37086 = (cppVar_37086 & cppMask_un_16_);
	BIT_VEC cppVar_37087 = ROM.rd(cppVar_37086);
	BIT_VEC cppVar_37088 = (cppVar_37087 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37089 = (cppVar_37088 & cppMask_un_5_);
	BIT_VEC cppVar_37091 = cppVar_37089 + 32;
	cppVar_37091 = (cppVar_37091 & cppMask_un_8_);
	cppVar_37075 = cppVar_37091;
	}
	BIT_VEC cppVar_37092 = (cppVar_37075 >> 7) & cppMask_un_1_;
	bool cppVar_37094 = (cppVar_37092 == 0);
	if (cppVar_37094) {
	BIT_VEC cppVar_37095;
	BIT_VEC cppVar_37096 = PC + 1;
	cppVar_37096 = (cppVar_37096 & cppMask_un_16_);
	BIT_VEC cppVar_37097 = ROM.rd(cppVar_37096);
	BIT_VEC cppVar_37098 = (cppVar_37097 >> 7) & cppMask_un_1_;
	bool cppVar_37099 = (cppVar_37098 == 1);
	if (cppVar_37099) {
	BIT_VEC cppVar_37100 = PC + 1;
	cppVar_37100 = (cppVar_37100 & cppMask_un_16_);
	BIT_VEC cppVar_37101 = ROM.rd(cppVar_37100);
	BIT_VEC cppVar_37102 = (cppVar_37101 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37103 = (cppVar_37102 << 3) | 0;
	cppVar_37103 = (cppVar_37103 & cppMask_un_8_);
	cppVar_37095 = cppVar_37103;
	} else {
	BIT_VEC cppVar_37104 = PC + 1;
	cppVar_37104 = (cppVar_37104 & cppMask_un_16_);
	BIT_VEC cppVar_37105 = ROM.rd(cppVar_37104);
	BIT_VEC cppVar_37106 = (cppVar_37105 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37107 = (cppVar_37106 & cppMask_un_5_);
	BIT_VEC cppVar_37108 = cppVar_37107 + 32;
	cppVar_37108 = (cppVar_37108 & cppMask_un_8_);
	cppVar_37095 = cppVar_37108;
	}
	BIT_VEC cppVar_37109 = IRAM.rd(cppVar_37095);
	cppVar_37074 = cppVar_37109;
	} else {
	BIT_VEC cppVar_37110;
	BIT_VEC cppVar_37111;
	BIT_VEC cppVar_37112 = PC + 1;
	cppVar_37112 = (cppVar_37112 & cppMask_un_16_);
	BIT_VEC cppVar_37113 = ROM.rd(cppVar_37112);
	BIT_VEC cppVar_37114 = (cppVar_37113 >> 7) & cppMask_un_1_;
	bool cppVar_37115 = (cppVar_37114 == 1);
	if (cppVar_37115) {
	BIT_VEC cppVar_37116 = PC + 1;
	cppVar_37116 = (cppVar_37116 & cppMask_un_16_);
	BIT_VEC cppVar_37117 = ROM.rd(cppVar_37116);
	BIT_VEC cppVar_37118 = (cppVar_37117 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37119 = (cppVar_37118 << 3) | 0;
	cppVar_37119 = (cppVar_37119 & cppMask_un_8_);
	cppVar_37111 = cppVar_37119;
	} else {
	BIT_VEC cppVar_37120 = PC + 1;
	cppVar_37120 = (cppVar_37120 & cppMask_un_16_);
	BIT_VEC cppVar_37121 = ROM.rd(cppVar_37120);
	BIT_VEC cppVar_37122 = (cppVar_37121 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37123 = (cppVar_37122 & cppMask_un_5_);
	BIT_VEC cppVar_37124 = cppVar_37123 + 32;
	cppVar_37124 = (cppVar_37124 & cppMask_un_8_);
	cppVar_37111 = cppVar_37124;
	}
	bool cppVar_37126 = (cppVar_37111 == 128);
	if (cppVar_37126) {
	cppVar_37110 = P0;
	} else {
	BIT_VEC cppVar_37127;
	BIT_VEC cppVar_37128;
	BIT_VEC cppVar_37129 = PC + 1;
	cppVar_37129 = (cppVar_37129 & cppMask_un_16_);
	BIT_VEC cppVar_37130 = ROM.rd(cppVar_37129);
	BIT_VEC cppVar_37131 = (cppVar_37130 >> 7) & cppMask_un_1_;
	bool cppVar_37132 = (cppVar_37131 == 1);
	if (cppVar_37132) {
	BIT_VEC cppVar_37133 = PC + 1;
	cppVar_37133 = (cppVar_37133 & cppMask_un_16_);
	BIT_VEC cppVar_37134 = ROM.rd(cppVar_37133);
	BIT_VEC cppVar_37135 = (cppVar_37134 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37136 = (cppVar_37135 << 3) | 0;
	cppVar_37136 = (cppVar_37136 & cppMask_un_8_);
	cppVar_37128 = cppVar_37136;
	} else {
	BIT_VEC cppVar_37137 = PC + 1;
	cppVar_37137 = (cppVar_37137 & cppMask_un_16_);
	BIT_VEC cppVar_37138 = ROM.rd(cppVar_37137);
	BIT_VEC cppVar_37139 = (cppVar_37138 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37140 = (cppVar_37139 & cppMask_un_5_);
	BIT_VEC cppVar_37141 = cppVar_37140 + 32;
	cppVar_37141 = (cppVar_37141 & cppMask_un_8_);
	cppVar_37128 = cppVar_37141;
	}
	bool cppVar_37143 = (cppVar_37128 == 129);
	if (cppVar_37143) {
	cppVar_37127 = SP;
	} else {
	BIT_VEC cppVar_37144;
	BIT_VEC cppVar_37145;
	BIT_VEC cppVar_37146 = PC + 1;
	cppVar_37146 = (cppVar_37146 & cppMask_un_16_);
	BIT_VEC cppVar_37147 = ROM.rd(cppVar_37146);
	BIT_VEC cppVar_37148 = (cppVar_37147 >> 7) & cppMask_un_1_;
	bool cppVar_37149 = (cppVar_37148 == 1);
	if (cppVar_37149) {
	BIT_VEC cppVar_37150 = PC + 1;
	cppVar_37150 = (cppVar_37150 & cppMask_un_16_);
	BIT_VEC cppVar_37151 = ROM.rd(cppVar_37150);
	BIT_VEC cppVar_37152 = (cppVar_37151 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37153 = (cppVar_37152 << 3) | 0;
	cppVar_37153 = (cppVar_37153 & cppMask_un_8_);
	cppVar_37145 = cppVar_37153;
	} else {
	BIT_VEC cppVar_37154 = PC + 1;
	cppVar_37154 = (cppVar_37154 & cppMask_un_16_);
	BIT_VEC cppVar_37155 = ROM.rd(cppVar_37154);
	BIT_VEC cppVar_37156 = (cppVar_37155 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37157 = (cppVar_37156 & cppMask_un_5_);
	BIT_VEC cppVar_37158 = cppVar_37157 + 32;
	cppVar_37158 = (cppVar_37158 & cppMask_un_8_);
	cppVar_37145 = cppVar_37158;
	}
	bool cppVar_37160 = (cppVar_37145 == 130);
	if (cppVar_37160) {
	cppVar_37144 = DPL;
	} else {
	BIT_VEC cppVar_37161;
	BIT_VEC cppVar_37162;
	BIT_VEC cppVar_37163 = PC + 1;
	cppVar_37163 = (cppVar_37163 & cppMask_un_16_);
	BIT_VEC cppVar_37164 = ROM.rd(cppVar_37163);
	BIT_VEC cppVar_37165 = (cppVar_37164 >> 7) & cppMask_un_1_;
	bool cppVar_37166 = (cppVar_37165 == 1);
	if (cppVar_37166) {
	BIT_VEC cppVar_37167 = PC + 1;
	cppVar_37167 = (cppVar_37167 & cppMask_un_16_);
	BIT_VEC cppVar_37168 = ROM.rd(cppVar_37167);
	BIT_VEC cppVar_37169 = (cppVar_37168 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37170 = (cppVar_37169 << 3) | 0;
	cppVar_37170 = (cppVar_37170 & cppMask_un_8_);
	cppVar_37162 = cppVar_37170;
	} else {
	BIT_VEC cppVar_37171 = PC + 1;
	cppVar_37171 = (cppVar_37171 & cppMask_un_16_);
	BIT_VEC cppVar_37172 = ROM.rd(cppVar_37171);
	BIT_VEC cppVar_37173 = (cppVar_37172 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37174 = (cppVar_37173 & cppMask_un_5_);
	BIT_VEC cppVar_37175 = cppVar_37174 + 32;
	cppVar_37175 = (cppVar_37175 & cppMask_un_8_);
	cppVar_37162 = cppVar_37175;
	}
	bool cppVar_37177 = (cppVar_37162 == 131);
	if (cppVar_37177) {
	cppVar_37161 = DPH;
	} else {
	BIT_VEC cppVar_37178;
	BIT_VEC cppVar_37179;
	BIT_VEC cppVar_37180 = PC + 1;
	cppVar_37180 = (cppVar_37180 & cppMask_un_16_);
	BIT_VEC cppVar_37181 = ROM.rd(cppVar_37180);
	BIT_VEC cppVar_37182 = (cppVar_37181 >> 7) & cppMask_un_1_;
	bool cppVar_37183 = (cppVar_37182 == 1);
	if (cppVar_37183) {
	BIT_VEC cppVar_37184 = PC + 1;
	cppVar_37184 = (cppVar_37184 & cppMask_un_16_);
	BIT_VEC cppVar_37185 = ROM.rd(cppVar_37184);
	BIT_VEC cppVar_37186 = (cppVar_37185 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37187 = (cppVar_37186 << 3) | 0;
	cppVar_37187 = (cppVar_37187 & cppMask_un_8_);
	cppVar_37179 = cppVar_37187;
	} else {
	BIT_VEC cppVar_37188 = PC + 1;
	cppVar_37188 = (cppVar_37188 & cppMask_un_16_);
	BIT_VEC cppVar_37189 = ROM.rd(cppVar_37188);
	BIT_VEC cppVar_37190 = (cppVar_37189 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37191 = (cppVar_37190 & cppMask_un_5_);
	BIT_VEC cppVar_37192 = cppVar_37191 + 32;
	cppVar_37192 = (cppVar_37192 & cppMask_un_8_);
	cppVar_37179 = cppVar_37192;
	}
	bool cppVar_37194 = (cppVar_37179 == 135);
	if (cppVar_37194) {
	cppVar_37178 = PCON;
	} else {
	BIT_VEC cppVar_37195;
	BIT_VEC cppVar_37196;
	BIT_VEC cppVar_37197 = PC + 1;
	cppVar_37197 = (cppVar_37197 & cppMask_un_16_);
	BIT_VEC cppVar_37198 = ROM.rd(cppVar_37197);
	BIT_VEC cppVar_37199 = (cppVar_37198 >> 7) & cppMask_un_1_;
	bool cppVar_37200 = (cppVar_37199 == 1);
	if (cppVar_37200) {
	BIT_VEC cppVar_37201 = PC + 1;
	cppVar_37201 = (cppVar_37201 & cppMask_un_16_);
	BIT_VEC cppVar_37202 = ROM.rd(cppVar_37201);
	BIT_VEC cppVar_37203 = (cppVar_37202 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37204 = (cppVar_37203 << 3) | 0;
	cppVar_37204 = (cppVar_37204 & cppMask_un_8_);
	cppVar_37196 = cppVar_37204;
	} else {
	BIT_VEC cppVar_37205 = PC + 1;
	cppVar_37205 = (cppVar_37205 & cppMask_un_16_);
	BIT_VEC cppVar_37206 = ROM.rd(cppVar_37205);
	BIT_VEC cppVar_37207 = (cppVar_37206 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37208 = (cppVar_37207 & cppMask_un_5_);
	BIT_VEC cppVar_37209 = cppVar_37208 + 32;
	cppVar_37209 = (cppVar_37209 & cppMask_un_8_);
	cppVar_37196 = cppVar_37209;
	}
	bool cppVar_37211 = (cppVar_37196 == 136);
	if (cppVar_37211) {
	cppVar_37195 = TCON;
	} else {
	BIT_VEC cppVar_37212;
	BIT_VEC cppVar_37213;
	BIT_VEC cppVar_37214 = PC + 1;
	cppVar_37214 = (cppVar_37214 & cppMask_un_16_);
	BIT_VEC cppVar_37215 = ROM.rd(cppVar_37214);
	BIT_VEC cppVar_37216 = (cppVar_37215 >> 7) & cppMask_un_1_;
	bool cppVar_37217 = (cppVar_37216 == 1);
	if (cppVar_37217) {
	BIT_VEC cppVar_37218 = PC + 1;
	cppVar_37218 = (cppVar_37218 & cppMask_un_16_);
	BIT_VEC cppVar_37219 = ROM.rd(cppVar_37218);
	BIT_VEC cppVar_37220 = (cppVar_37219 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37221 = (cppVar_37220 << 3) | 0;
	cppVar_37221 = (cppVar_37221 & cppMask_un_8_);
	cppVar_37213 = cppVar_37221;
	} else {
	BIT_VEC cppVar_37222 = PC + 1;
	cppVar_37222 = (cppVar_37222 & cppMask_un_16_);
	BIT_VEC cppVar_37223 = ROM.rd(cppVar_37222);
	BIT_VEC cppVar_37224 = (cppVar_37223 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37225 = (cppVar_37224 & cppMask_un_5_);
	BIT_VEC cppVar_37226 = cppVar_37225 + 32;
	cppVar_37226 = (cppVar_37226 & cppMask_un_8_);
	cppVar_37213 = cppVar_37226;
	}
	bool cppVar_37228 = (cppVar_37213 == 137);
	if (cppVar_37228) {
	cppVar_37212 = TMOD;
	} else {
	BIT_VEC cppVar_37229;
	BIT_VEC cppVar_37230;
	BIT_VEC cppVar_37231 = PC + 1;
	cppVar_37231 = (cppVar_37231 & cppMask_un_16_);
	BIT_VEC cppVar_37232 = ROM.rd(cppVar_37231);
	BIT_VEC cppVar_37233 = (cppVar_37232 >> 7) & cppMask_un_1_;
	bool cppVar_37234 = (cppVar_37233 == 1);
	if (cppVar_37234) {
	BIT_VEC cppVar_37235 = PC + 1;
	cppVar_37235 = (cppVar_37235 & cppMask_un_16_);
	BIT_VEC cppVar_37236 = ROM.rd(cppVar_37235);
	BIT_VEC cppVar_37237 = (cppVar_37236 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37238 = (cppVar_37237 << 3) | 0;
	cppVar_37238 = (cppVar_37238 & cppMask_un_8_);
	cppVar_37230 = cppVar_37238;
	} else {
	BIT_VEC cppVar_37239 = PC + 1;
	cppVar_37239 = (cppVar_37239 & cppMask_un_16_);
	BIT_VEC cppVar_37240 = ROM.rd(cppVar_37239);
	BIT_VEC cppVar_37241 = (cppVar_37240 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37242 = (cppVar_37241 & cppMask_un_5_);
	BIT_VEC cppVar_37243 = cppVar_37242 + 32;
	cppVar_37243 = (cppVar_37243 & cppMask_un_8_);
	cppVar_37230 = cppVar_37243;
	}
	bool cppVar_37245 = (cppVar_37230 == 138);
	if (cppVar_37245) {
	cppVar_37229 = TL0;
	} else {
	BIT_VEC cppVar_37246;
	BIT_VEC cppVar_37247;
	BIT_VEC cppVar_37248 = PC + 1;
	cppVar_37248 = (cppVar_37248 & cppMask_un_16_);
	BIT_VEC cppVar_37249 = ROM.rd(cppVar_37248);
	BIT_VEC cppVar_37250 = (cppVar_37249 >> 7) & cppMask_un_1_;
	bool cppVar_37251 = (cppVar_37250 == 1);
	if (cppVar_37251) {
	BIT_VEC cppVar_37252 = PC + 1;
	cppVar_37252 = (cppVar_37252 & cppMask_un_16_);
	BIT_VEC cppVar_37253 = ROM.rd(cppVar_37252);
	BIT_VEC cppVar_37254 = (cppVar_37253 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37255 = (cppVar_37254 << 3) | 0;
	cppVar_37255 = (cppVar_37255 & cppMask_un_8_);
	cppVar_37247 = cppVar_37255;
	} else {
	BIT_VEC cppVar_37256 = PC + 1;
	cppVar_37256 = (cppVar_37256 & cppMask_un_16_);
	BIT_VEC cppVar_37257 = ROM.rd(cppVar_37256);
	BIT_VEC cppVar_37258 = (cppVar_37257 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37259 = (cppVar_37258 & cppMask_un_5_);
	BIT_VEC cppVar_37260 = cppVar_37259 + 32;
	cppVar_37260 = (cppVar_37260 & cppMask_un_8_);
	cppVar_37247 = cppVar_37260;
	}
	bool cppVar_37262 = (cppVar_37247 == 140);
	if (cppVar_37262) {
	cppVar_37246 = TH0;
	} else {
	BIT_VEC cppVar_37263;
	BIT_VEC cppVar_37264;
	BIT_VEC cppVar_37265 = PC + 1;
	cppVar_37265 = (cppVar_37265 & cppMask_un_16_);
	BIT_VEC cppVar_37266 = ROM.rd(cppVar_37265);
	BIT_VEC cppVar_37267 = (cppVar_37266 >> 7) & cppMask_un_1_;
	bool cppVar_37268 = (cppVar_37267 == 1);
	if (cppVar_37268) {
	BIT_VEC cppVar_37269 = PC + 1;
	cppVar_37269 = (cppVar_37269 & cppMask_un_16_);
	BIT_VEC cppVar_37270 = ROM.rd(cppVar_37269);
	BIT_VEC cppVar_37271 = (cppVar_37270 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37272 = (cppVar_37271 << 3) | 0;
	cppVar_37272 = (cppVar_37272 & cppMask_un_8_);
	cppVar_37264 = cppVar_37272;
	} else {
	BIT_VEC cppVar_37273 = PC + 1;
	cppVar_37273 = (cppVar_37273 & cppMask_un_16_);
	BIT_VEC cppVar_37274 = ROM.rd(cppVar_37273);
	BIT_VEC cppVar_37275 = (cppVar_37274 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37276 = (cppVar_37275 & cppMask_un_5_);
	BIT_VEC cppVar_37277 = cppVar_37276 + 32;
	cppVar_37277 = (cppVar_37277 & cppMask_un_8_);
	cppVar_37264 = cppVar_37277;
	}
	bool cppVar_37279 = (cppVar_37264 == 139);
	if (cppVar_37279) {
	cppVar_37263 = TL1;
	} else {
	BIT_VEC cppVar_37280;
	BIT_VEC cppVar_37281;
	BIT_VEC cppVar_37282 = PC + 1;
	cppVar_37282 = (cppVar_37282 & cppMask_un_16_);
	BIT_VEC cppVar_37283 = ROM.rd(cppVar_37282);
	BIT_VEC cppVar_37284 = (cppVar_37283 >> 7) & cppMask_un_1_;
	bool cppVar_37285 = (cppVar_37284 == 1);
	if (cppVar_37285) {
	BIT_VEC cppVar_37286 = PC + 1;
	cppVar_37286 = (cppVar_37286 & cppMask_un_16_);
	BIT_VEC cppVar_37287 = ROM.rd(cppVar_37286);
	BIT_VEC cppVar_37288 = (cppVar_37287 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37289 = (cppVar_37288 << 3) | 0;
	cppVar_37289 = (cppVar_37289 & cppMask_un_8_);
	cppVar_37281 = cppVar_37289;
	} else {
	BIT_VEC cppVar_37290 = PC + 1;
	cppVar_37290 = (cppVar_37290 & cppMask_un_16_);
	BIT_VEC cppVar_37291 = ROM.rd(cppVar_37290);
	BIT_VEC cppVar_37292 = (cppVar_37291 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37293 = (cppVar_37292 & cppMask_un_5_);
	BIT_VEC cppVar_37294 = cppVar_37293 + 32;
	cppVar_37294 = (cppVar_37294 & cppMask_un_8_);
	cppVar_37281 = cppVar_37294;
	}
	bool cppVar_37296 = (cppVar_37281 == 141);
	if (cppVar_37296) {
	cppVar_37280 = TH1;
	} else {
	BIT_VEC cppVar_37297;
	BIT_VEC cppVar_37298;
	BIT_VEC cppVar_37299 = PC + 1;
	cppVar_37299 = (cppVar_37299 & cppMask_un_16_);
	BIT_VEC cppVar_37300 = ROM.rd(cppVar_37299);
	BIT_VEC cppVar_37301 = (cppVar_37300 >> 7) & cppMask_un_1_;
	bool cppVar_37302 = (cppVar_37301 == 1);
	if (cppVar_37302) {
	BIT_VEC cppVar_37303 = PC + 1;
	cppVar_37303 = (cppVar_37303 & cppMask_un_16_);
	BIT_VEC cppVar_37304 = ROM.rd(cppVar_37303);
	BIT_VEC cppVar_37305 = (cppVar_37304 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37306 = (cppVar_37305 << 3) | 0;
	cppVar_37306 = (cppVar_37306 & cppMask_un_8_);
	cppVar_37298 = cppVar_37306;
	} else {
	BIT_VEC cppVar_37307 = PC + 1;
	cppVar_37307 = (cppVar_37307 & cppMask_un_16_);
	BIT_VEC cppVar_37308 = ROM.rd(cppVar_37307);
	BIT_VEC cppVar_37309 = (cppVar_37308 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37310 = (cppVar_37309 & cppMask_un_5_);
	BIT_VEC cppVar_37311 = cppVar_37310 + 32;
	cppVar_37311 = (cppVar_37311 & cppMask_un_8_);
	cppVar_37298 = cppVar_37311;
	}
	bool cppVar_37313 = (cppVar_37298 == 144);
	if (cppVar_37313) {
	cppVar_37297 = P1;
	} else {
	BIT_VEC cppVar_37314;
	BIT_VEC cppVar_37315;
	BIT_VEC cppVar_37316 = PC + 1;
	cppVar_37316 = (cppVar_37316 & cppMask_un_16_);
	BIT_VEC cppVar_37317 = ROM.rd(cppVar_37316);
	BIT_VEC cppVar_37318 = (cppVar_37317 >> 7) & cppMask_un_1_;
	bool cppVar_37319 = (cppVar_37318 == 1);
	if (cppVar_37319) {
	BIT_VEC cppVar_37320 = PC + 1;
	cppVar_37320 = (cppVar_37320 & cppMask_un_16_);
	BIT_VEC cppVar_37321 = ROM.rd(cppVar_37320);
	BIT_VEC cppVar_37322 = (cppVar_37321 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37323 = (cppVar_37322 << 3) | 0;
	cppVar_37323 = (cppVar_37323 & cppMask_un_8_);
	cppVar_37315 = cppVar_37323;
	} else {
	BIT_VEC cppVar_37324 = PC + 1;
	cppVar_37324 = (cppVar_37324 & cppMask_un_16_);
	BIT_VEC cppVar_37325 = ROM.rd(cppVar_37324);
	BIT_VEC cppVar_37326 = (cppVar_37325 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37327 = (cppVar_37326 & cppMask_un_5_);
	BIT_VEC cppVar_37328 = cppVar_37327 + 32;
	cppVar_37328 = (cppVar_37328 & cppMask_un_8_);
	cppVar_37315 = cppVar_37328;
	}
	bool cppVar_37330 = (cppVar_37315 == 152);
	if (cppVar_37330) {
	cppVar_37314 = SCON;
	} else {
	BIT_VEC cppVar_37331;
	BIT_VEC cppVar_37332;
	BIT_VEC cppVar_37333 = PC + 1;
	cppVar_37333 = (cppVar_37333 & cppMask_un_16_);
	BIT_VEC cppVar_37334 = ROM.rd(cppVar_37333);
	BIT_VEC cppVar_37335 = (cppVar_37334 >> 7) & cppMask_un_1_;
	bool cppVar_37336 = (cppVar_37335 == 1);
	if (cppVar_37336) {
	BIT_VEC cppVar_37337 = PC + 1;
	cppVar_37337 = (cppVar_37337 & cppMask_un_16_);
	BIT_VEC cppVar_37338 = ROM.rd(cppVar_37337);
	BIT_VEC cppVar_37339 = (cppVar_37338 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37340 = (cppVar_37339 << 3) | 0;
	cppVar_37340 = (cppVar_37340 & cppMask_un_8_);
	cppVar_37332 = cppVar_37340;
	} else {
	BIT_VEC cppVar_37341 = PC + 1;
	cppVar_37341 = (cppVar_37341 & cppMask_un_16_);
	BIT_VEC cppVar_37342 = ROM.rd(cppVar_37341);
	BIT_VEC cppVar_37343 = (cppVar_37342 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37344 = (cppVar_37343 & cppMask_un_5_);
	BIT_VEC cppVar_37345 = cppVar_37344 + 32;
	cppVar_37345 = (cppVar_37345 & cppMask_un_8_);
	cppVar_37332 = cppVar_37345;
	}
	bool cppVar_37347 = (cppVar_37332 == 153);
	if (cppVar_37347) {
	cppVar_37331 = SBUF;
	} else {
	BIT_VEC cppVar_37348;
	BIT_VEC cppVar_37349;
	BIT_VEC cppVar_37350 = PC + 1;
	cppVar_37350 = (cppVar_37350 & cppMask_un_16_);
	BIT_VEC cppVar_37351 = ROM.rd(cppVar_37350);
	BIT_VEC cppVar_37352 = (cppVar_37351 >> 7) & cppMask_un_1_;
	bool cppVar_37353 = (cppVar_37352 == 1);
	if (cppVar_37353) {
	BIT_VEC cppVar_37354 = PC + 1;
	cppVar_37354 = (cppVar_37354 & cppMask_un_16_);
	BIT_VEC cppVar_37355 = ROM.rd(cppVar_37354);
	BIT_VEC cppVar_37356 = (cppVar_37355 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37357 = (cppVar_37356 << 3) | 0;
	cppVar_37357 = (cppVar_37357 & cppMask_un_8_);
	cppVar_37349 = cppVar_37357;
	} else {
	BIT_VEC cppVar_37358 = PC + 1;
	cppVar_37358 = (cppVar_37358 & cppMask_un_16_);
	BIT_VEC cppVar_37359 = ROM.rd(cppVar_37358);
	BIT_VEC cppVar_37360 = (cppVar_37359 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37361 = (cppVar_37360 & cppMask_un_5_);
	BIT_VEC cppVar_37362 = cppVar_37361 + 32;
	cppVar_37362 = (cppVar_37362 & cppMask_un_8_);
	cppVar_37349 = cppVar_37362;
	}
	bool cppVar_37364 = (cppVar_37349 == 160);
	if (cppVar_37364) {
	cppVar_37348 = P2;
	} else {
	BIT_VEC cppVar_37365;
	BIT_VEC cppVar_37366;
	BIT_VEC cppVar_37367 = PC + 1;
	cppVar_37367 = (cppVar_37367 & cppMask_un_16_);
	BIT_VEC cppVar_37368 = ROM.rd(cppVar_37367);
	BIT_VEC cppVar_37369 = (cppVar_37368 >> 7) & cppMask_un_1_;
	bool cppVar_37370 = (cppVar_37369 == 1);
	if (cppVar_37370) {
	BIT_VEC cppVar_37371 = PC + 1;
	cppVar_37371 = (cppVar_37371 & cppMask_un_16_);
	BIT_VEC cppVar_37372 = ROM.rd(cppVar_37371);
	BIT_VEC cppVar_37373 = (cppVar_37372 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37374 = (cppVar_37373 << 3) | 0;
	cppVar_37374 = (cppVar_37374 & cppMask_un_8_);
	cppVar_37366 = cppVar_37374;
	} else {
	BIT_VEC cppVar_37375 = PC + 1;
	cppVar_37375 = (cppVar_37375 & cppMask_un_16_);
	BIT_VEC cppVar_37376 = ROM.rd(cppVar_37375);
	BIT_VEC cppVar_37377 = (cppVar_37376 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37378 = (cppVar_37377 & cppMask_un_5_);
	BIT_VEC cppVar_37379 = cppVar_37378 + 32;
	cppVar_37379 = (cppVar_37379 & cppMask_un_8_);
	cppVar_37366 = cppVar_37379;
	}
	bool cppVar_37381 = (cppVar_37366 == 168);
	if (cppVar_37381) {
	cppVar_37365 = IE;
	} else {
	BIT_VEC cppVar_37382;
	BIT_VEC cppVar_37383;
	BIT_VEC cppVar_37384 = PC + 1;
	cppVar_37384 = (cppVar_37384 & cppMask_un_16_);
	BIT_VEC cppVar_37385 = ROM.rd(cppVar_37384);
	BIT_VEC cppVar_37386 = (cppVar_37385 >> 7) & cppMask_un_1_;
	bool cppVar_37387 = (cppVar_37386 == 1);
	if (cppVar_37387) {
	BIT_VEC cppVar_37388 = PC + 1;
	cppVar_37388 = (cppVar_37388 & cppMask_un_16_);
	BIT_VEC cppVar_37389 = ROM.rd(cppVar_37388);
	BIT_VEC cppVar_37390 = (cppVar_37389 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37391 = (cppVar_37390 << 3) | 0;
	cppVar_37391 = (cppVar_37391 & cppMask_un_8_);
	cppVar_37383 = cppVar_37391;
	} else {
	BIT_VEC cppVar_37392 = PC + 1;
	cppVar_37392 = (cppVar_37392 & cppMask_un_16_);
	BIT_VEC cppVar_37393 = ROM.rd(cppVar_37392);
	BIT_VEC cppVar_37394 = (cppVar_37393 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37395 = (cppVar_37394 & cppMask_un_5_);
	BIT_VEC cppVar_37396 = cppVar_37395 + 32;
	cppVar_37396 = (cppVar_37396 & cppMask_un_8_);
	cppVar_37383 = cppVar_37396;
	}
	bool cppVar_37398 = (cppVar_37383 == 176);
	if (cppVar_37398) {
	cppVar_37382 = P3;
	} else {
	BIT_VEC cppVar_37399;
	BIT_VEC cppVar_37400;
	BIT_VEC cppVar_37401 = PC + 1;
	cppVar_37401 = (cppVar_37401 & cppMask_un_16_);
	BIT_VEC cppVar_37402 = ROM.rd(cppVar_37401);
	BIT_VEC cppVar_37403 = (cppVar_37402 >> 7) & cppMask_un_1_;
	bool cppVar_37404 = (cppVar_37403 == 1);
	if (cppVar_37404) {
	BIT_VEC cppVar_37405 = PC + 1;
	cppVar_37405 = (cppVar_37405 & cppMask_un_16_);
	BIT_VEC cppVar_37406 = ROM.rd(cppVar_37405);
	BIT_VEC cppVar_37407 = (cppVar_37406 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37408 = (cppVar_37407 << 3) | 0;
	cppVar_37408 = (cppVar_37408 & cppMask_un_8_);
	cppVar_37400 = cppVar_37408;
	} else {
	BIT_VEC cppVar_37409 = PC + 1;
	cppVar_37409 = (cppVar_37409 & cppMask_un_16_);
	BIT_VEC cppVar_37410 = ROM.rd(cppVar_37409);
	BIT_VEC cppVar_37411 = (cppVar_37410 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37412 = (cppVar_37411 & cppMask_un_5_);
	BIT_VEC cppVar_37413 = cppVar_37412 + 32;
	cppVar_37413 = (cppVar_37413 & cppMask_un_8_);
	cppVar_37400 = cppVar_37413;
	}
	bool cppVar_37415 = (cppVar_37400 == 184);
	if (cppVar_37415) {
	cppVar_37399 = IP;
	} else {
	BIT_VEC cppVar_37416;
	BIT_VEC cppVar_37417;
	BIT_VEC cppVar_37418 = PC + 1;
	cppVar_37418 = (cppVar_37418 & cppMask_un_16_);
	BIT_VEC cppVar_37419 = ROM.rd(cppVar_37418);
	BIT_VEC cppVar_37420 = (cppVar_37419 >> 7) & cppMask_un_1_;
	bool cppVar_37421 = (cppVar_37420 == 1);
	if (cppVar_37421) {
	BIT_VEC cppVar_37422 = PC + 1;
	cppVar_37422 = (cppVar_37422 & cppMask_un_16_);
	BIT_VEC cppVar_37423 = ROM.rd(cppVar_37422);
	BIT_VEC cppVar_37424 = (cppVar_37423 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37425 = (cppVar_37424 << 3) | 0;
	cppVar_37425 = (cppVar_37425 & cppMask_un_8_);
	cppVar_37417 = cppVar_37425;
	} else {
	BIT_VEC cppVar_37426 = PC + 1;
	cppVar_37426 = (cppVar_37426 & cppMask_un_16_);
	BIT_VEC cppVar_37427 = ROM.rd(cppVar_37426);
	BIT_VEC cppVar_37428 = (cppVar_37427 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37429 = (cppVar_37428 & cppMask_un_5_);
	BIT_VEC cppVar_37430 = cppVar_37429 + 32;
	cppVar_37430 = (cppVar_37430 & cppMask_un_8_);
	cppVar_37417 = cppVar_37430;
	}
	bool cppVar_37432 = (cppVar_37417 == 208);
	if (cppVar_37432) {
	cppVar_37416 = PSW;
	} else {
	BIT_VEC cppVar_37433;
	BIT_VEC cppVar_37434;
	BIT_VEC cppVar_37435 = PC + 1;
	cppVar_37435 = (cppVar_37435 & cppMask_un_16_);
	BIT_VEC cppVar_37436 = ROM.rd(cppVar_37435);
	BIT_VEC cppVar_37437 = (cppVar_37436 >> 7) & cppMask_un_1_;
	bool cppVar_37438 = (cppVar_37437 == 1);
	if (cppVar_37438) {
	BIT_VEC cppVar_37439 = PC + 1;
	cppVar_37439 = (cppVar_37439 & cppMask_un_16_);
	BIT_VEC cppVar_37440 = ROM.rd(cppVar_37439);
	BIT_VEC cppVar_37441 = (cppVar_37440 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37442 = (cppVar_37441 << 3) | 0;
	cppVar_37442 = (cppVar_37442 & cppMask_un_8_);
	cppVar_37434 = cppVar_37442;
	} else {
	BIT_VEC cppVar_37443 = PC + 1;
	cppVar_37443 = (cppVar_37443 & cppMask_un_16_);
	BIT_VEC cppVar_37444 = ROM.rd(cppVar_37443);
	BIT_VEC cppVar_37445 = (cppVar_37444 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37446 = (cppVar_37445 & cppMask_un_5_);
	BIT_VEC cppVar_37447 = cppVar_37446 + 32;
	cppVar_37447 = (cppVar_37447 & cppMask_un_8_);
	cppVar_37434 = cppVar_37447;
	}
	bool cppVar_37449 = (cppVar_37434 == 224);
	if (cppVar_37449) {
	cppVar_37433 = ACC;
	} else {
	BIT_VEC cppVar_37450;
	BIT_VEC cppVar_37451;
	BIT_VEC cppVar_37452 = PC + 1;
	cppVar_37452 = (cppVar_37452 & cppMask_un_16_);
	BIT_VEC cppVar_37453 = ROM.rd(cppVar_37452);
	BIT_VEC cppVar_37454 = (cppVar_37453 >> 7) & cppMask_un_1_;
	bool cppVar_37455 = (cppVar_37454 == 1);
	if (cppVar_37455) {
	BIT_VEC cppVar_37456 = PC + 1;
	cppVar_37456 = (cppVar_37456 & cppMask_un_16_);
	BIT_VEC cppVar_37457 = ROM.rd(cppVar_37456);
	BIT_VEC cppVar_37458 = (cppVar_37457 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37459 = (cppVar_37458 << 3) | 0;
	cppVar_37459 = (cppVar_37459 & cppMask_un_8_);
	cppVar_37451 = cppVar_37459;
	} else {
	BIT_VEC cppVar_37460 = PC + 1;
	cppVar_37460 = (cppVar_37460 & cppMask_un_16_);
	BIT_VEC cppVar_37461 = ROM.rd(cppVar_37460);
	BIT_VEC cppVar_37462 = (cppVar_37461 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37463 = (cppVar_37462 & cppMask_un_5_);
	BIT_VEC cppVar_37464 = cppVar_37463 + 32;
	cppVar_37464 = (cppVar_37464 & cppMask_un_8_);
	cppVar_37451 = cppVar_37464;
	}
	bool cppVar_37466 = (cppVar_37451 == 240);
	if (cppVar_37466) {
	cppVar_37450 = B;
	} else {
	cppVar_37450 = 0;
	}
	cppVar_37433 = cppVar_37450;
	}
	cppVar_37416 = cppVar_37433;
	}
	cppVar_37399 = cppVar_37416;
	}
	cppVar_37382 = cppVar_37399;
	}
	cppVar_37365 = cppVar_37382;
	}
	cppVar_37348 = cppVar_37365;
	}
	cppVar_37331 = cppVar_37348;
	}
	cppVar_37314 = cppVar_37331;
	}
	cppVar_37297 = cppVar_37314;
	}
	cppVar_37280 = cppVar_37297;
	}
	cppVar_37263 = cppVar_37280;
	}
	cppVar_37246 = cppVar_37263;
	}
	cppVar_37229 = cppVar_37246;
	}
	cppVar_37212 = cppVar_37229;
	}
	cppVar_37195 = cppVar_37212;
	}
	cppVar_37178 = cppVar_37195;
	}
	cppVar_37161 = cppVar_37178;
	}
	cppVar_37144 = cppVar_37161;
	}
	cppVar_37127 = cppVar_37144;
	}
	cppVar_37110 = cppVar_37127;
	}
	cppVar_37074 = cppVar_37110;
	}
	BIT_VEC cppVar_37468 = PC + 1;
	cppVar_37468 = (cppVar_37468 & cppMask_un_16_);
	BIT_VEC cppVar_37469 = ROM.rd(cppVar_37468);
	BIT_VEC cppVar_37470 = (cppVar_37469 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_37471 = (cppVar_37074 >> static_cast<unsigned>(cppVar_37470)) & 0x1;
	BIT_VEC cppVar_37472 = ~cppVar_37471;
	BIT_VEC cppVar_37473 = (cppVar_37472 & cppMask_un_1_);
	BIT_VEC cppVar_37474 = PC + 1;
	cppVar_37474 = (cppVar_37474 & cppMask_un_16_);
	BIT_VEC cppVar_37475 = ROM.rd(cppVar_37474);
	BIT_VEC cppVar_37476 = (cppVar_37475 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_37477 = (cppVar_37476 & cppMask_un_3_);
	BIT_VEC cppVar_37478 = cppVar_37473 << static_cast<unsigned>(cppVar_37477);
	cppVar_37478 = (cppVar_37478 & cppMask_un_8_);
	BIT_VEC cppVar_37479 = cppVar_37073 | cppVar_37478;
	cppVar_36654 = cppVar_37479;
	} else {
	cppVar_36654 = P3;
	}
	cppVar_36650 = cppVar_36654;
	} else {
	BIT_VEC cppVar_37480;
	BIT_VEC cppVar_37481 = ROM.rd(PC);
	bool cppVar_37483 = (cppVar_37481 == 146);
	if (cppVar_37483) {
	BIT_VEC cppVar_37484;
	BIT_VEC cppVar_37485;
	BIT_VEC cppVar_37487 = PC + 1;
	cppVar_37487 = (cppVar_37487 & cppMask_un_16_);
	BIT_VEC cppVar_37488 = ROM.rd(cppVar_37487);
	BIT_VEC cppVar_37489 = (cppVar_37488 >> 7) & cppMask_un_1_;
	bool cppVar_37491 = (cppVar_37489 == 1);
	if (cppVar_37491) {
	BIT_VEC cppVar_37492 = PC + 1;
	cppVar_37492 = (cppVar_37492 & cppMask_un_16_);
	BIT_VEC cppVar_37493 = ROM.rd(cppVar_37492);
	BIT_VEC cppVar_37494 = (cppVar_37493 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37496 = (cppVar_37494 << 3) | 0;
	cppVar_37496 = (cppVar_37496 & cppMask_un_8_);
	cppVar_37485 = cppVar_37496;
	} else {
	BIT_VEC cppVar_37497 = PC + 1;
	cppVar_37497 = (cppVar_37497 & cppMask_un_16_);
	BIT_VEC cppVar_37498 = ROM.rd(cppVar_37497);
	BIT_VEC cppVar_37499 = (cppVar_37498 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37500 = (cppVar_37499 & cppMask_un_5_);
	BIT_VEC cppVar_37502 = cppVar_37500 + 32;
	cppVar_37502 = (cppVar_37502 & cppMask_un_8_);
	cppVar_37485 = cppVar_37502;
	}
	bool cppVar_37504 = (cppVar_37485 == 176);
	if (cppVar_37504) {
	BIT_VEC cppVar_37506 = PC + 1;
	cppVar_37506 = (cppVar_37506 & cppMask_un_16_);
	BIT_VEC cppVar_37507 = ROM.rd(cppVar_37506);
	BIT_VEC cppVar_37508 = (cppVar_37507 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_37509 = (cppVar_37508 & cppMask_un_3_);
	BIT_VEC cppVar_37510 = 1 << static_cast<unsigned>(cppVar_37509);
	cppVar_37510 = (cppVar_37510 & cppMask_un_8_);
	BIT_VEC cppVar_37511 = ~cppVar_37510;
	BIT_VEC cppVar_37512;
	BIT_VEC cppVar_37513;
	BIT_VEC cppVar_37514 = PC + 1;
	cppVar_37514 = (cppVar_37514 & cppMask_un_16_);
	BIT_VEC cppVar_37515 = ROM.rd(cppVar_37514);
	BIT_VEC cppVar_37516 = (cppVar_37515 >> 7) & cppMask_un_1_;
	bool cppVar_37517 = (cppVar_37516 == 1);
	if (cppVar_37517) {
	BIT_VEC cppVar_37518 = PC + 1;
	cppVar_37518 = (cppVar_37518 & cppMask_un_16_);
	BIT_VEC cppVar_37519 = ROM.rd(cppVar_37518);
	BIT_VEC cppVar_37520 = (cppVar_37519 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37521 = (cppVar_37520 << 3) | 0;
	cppVar_37521 = (cppVar_37521 & cppMask_un_8_);
	cppVar_37513 = cppVar_37521;
	} else {
	BIT_VEC cppVar_37522 = PC + 1;
	cppVar_37522 = (cppVar_37522 & cppMask_un_16_);
	BIT_VEC cppVar_37523 = ROM.rd(cppVar_37522);
	BIT_VEC cppVar_37524 = (cppVar_37523 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37525 = (cppVar_37524 & cppMask_un_5_);
	BIT_VEC cppVar_37526 = cppVar_37525 + 32;
	cppVar_37526 = (cppVar_37526 & cppMask_un_8_);
	cppVar_37513 = cppVar_37526;
	}
	BIT_VEC cppVar_37527 = (cppVar_37513 >> 7) & cppMask_un_1_;
	bool cppVar_37529 = (cppVar_37527 == 0);
	if (cppVar_37529) {
	BIT_VEC cppVar_37530;
	BIT_VEC cppVar_37531 = PC + 1;
	cppVar_37531 = (cppVar_37531 & cppMask_un_16_);
	BIT_VEC cppVar_37532 = ROM.rd(cppVar_37531);
	BIT_VEC cppVar_37533 = (cppVar_37532 >> 7) & cppMask_un_1_;
	bool cppVar_37534 = (cppVar_37533 == 1);
	if (cppVar_37534) {
	BIT_VEC cppVar_37535 = PC + 1;
	cppVar_37535 = (cppVar_37535 & cppMask_un_16_);
	BIT_VEC cppVar_37536 = ROM.rd(cppVar_37535);
	BIT_VEC cppVar_37537 = (cppVar_37536 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37538 = (cppVar_37537 << 3) | 0;
	cppVar_37538 = (cppVar_37538 & cppMask_un_8_);
	cppVar_37530 = cppVar_37538;
	} else {
	BIT_VEC cppVar_37539 = PC + 1;
	cppVar_37539 = (cppVar_37539 & cppMask_un_16_);
	BIT_VEC cppVar_37540 = ROM.rd(cppVar_37539);
	BIT_VEC cppVar_37541 = (cppVar_37540 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37542 = (cppVar_37541 & cppMask_un_5_);
	BIT_VEC cppVar_37543 = cppVar_37542 + 32;
	cppVar_37543 = (cppVar_37543 & cppMask_un_8_);
	cppVar_37530 = cppVar_37543;
	}
	BIT_VEC cppVar_37544 = IRAM.rd(cppVar_37530);
	cppVar_37512 = cppVar_37544;
	} else {
	BIT_VEC cppVar_37545;
	BIT_VEC cppVar_37546;
	BIT_VEC cppVar_37547 = PC + 1;
	cppVar_37547 = (cppVar_37547 & cppMask_un_16_);
	BIT_VEC cppVar_37548 = ROM.rd(cppVar_37547);
	BIT_VEC cppVar_37549 = (cppVar_37548 >> 7) & cppMask_un_1_;
	bool cppVar_37550 = (cppVar_37549 == 1);
	if (cppVar_37550) {
	BIT_VEC cppVar_37551 = PC + 1;
	cppVar_37551 = (cppVar_37551 & cppMask_un_16_);
	BIT_VEC cppVar_37552 = ROM.rd(cppVar_37551);
	BIT_VEC cppVar_37553 = (cppVar_37552 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37554 = (cppVar_37553 << 3) | 0;
	cppVar_37554 = (cppVar_37554 & cppMask_un_8_);
	cppVar_37546 = cppVar_37554;
	} else {
	BIT_VEC cppVar_37555 = PC + 1;
	cppVar_37555 = (cppVar_37555 & cppMask_un_16_);
	BIT_VEC cppVar_37556 = ROM.rd(cppVar_37555);
	BIT_VEC cppVar_37557 = (cppVar_37556 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37558 = (cppVar_37557 & cppMask_un_5_);
	BIT_VEC cppVar_37559 = cppVar_37558 + 32;
	cppVar_37559 = (cppVar_37559 & cppMask_un_8_);
	cppVar_37546 = cppVar_37559;
	}
	bool cppVar_37561 = (cppVar_37546 == 128);
	if (cppVar_37561) {
	cppVar_37545 = P0;
	} else {
	BIT_VEC cppVar_37562;
	BIT_VEC cppVar_37563;
	BIT_VEC cppVar_37564 = PC + 1;
	cppVar_37564 = (cppVar_37564 & cppMask_un_16_);
	BIT_VEC cppVar_37565 = ROM.rd(cppVar_37564);
	BIT_VEC cppVar_37566 = (cppVar_37565 >> 7) & cppMask_un_1_;
	bool cppVar_37567 = (cppVar_37566 == 1);
	if (cppVar_37567) {
	BIT_VEC cppVar_37568 = PC + 1;
	cppVar_37568 = (cppVar_37568 & cppMask_un_16_);
	BIT_VEC cppVar_37569 = ROM.rd(cppVar_37568);
	BIT_VEC cppVar_37570 = (cppVar_37569 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37571 = (cppVar_37570 << 3) | 0;
	cppVar_37571 = (cppVar_37571 & cppMask_un_8_);
	cppVar_37563 = cppVar_37571;
	} else {
	BIT_VEC cppVar_37572 = PC + 1;
	cppVar_37572 = (cppVar_37572 & cppMask_un_16_);
	BIT_VEC cppVar_37573 = ROM.rd(cppVar_37572);
	BIT_VEC cppVar_37574 = (cppVar_37573 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37575 = (cppVar_37574 & cppMask_un_5_);
	BIT_VEC cppVar_37576 = cppVar_37575 + 32;
	cppVar_37576 = (cppVar_37576 & cppMask_un_8_);
	cppVar_37563 = cppVar_37576;
	}
	bool cppVar_37578 = (cppVar_37563 == 129);
	if (cppVar_37578) {
	cppVar_37562 = SP;
	} else {
	BIT_VEC cppVar_37579;
	BIT_VEC cppVar_37580;
	BIT_VEC cppVar_37581 = PC + 1;
	cppVar_37581 = (cppVar_37581 & cppMask_un_16_);
	BIT_VEC cppVar_37582 = ROM.rd(cppVar_37581);
	BIT_VEC cppVar_37583 = (cppVar_37582 >> 7) & cppMask_un_1_;
	bool cppVar_37584 = (cppVar_37583 == 1);
	if (cppVar_37584) {
	BIT_VEC cppVar_37585 = PC + 1;
	cppVar_37585 = (cppVar_37585 & cppMask_un_16_);
	BIT_VEC cppVar_37586 = ROM.rd(cppVar_37585);
	BIT_VEC cppVar_37587 = (cppVar_37586 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37588 = (cppVar_37587 << 3) | 0;
	cppVar_37588 = (cppVar_37588 & cppMask_un_8_);
	cppVar_37580 = cppVar_37588;
	} else {
	BIT_VEC cppVar_37589 = PC + 1;
	cppVar_37589 = (cppVar_37589 & cppMask_un_16_);
	BIT_VEC cppVar_37590 = ROM.rd(cppVar_37589);
	BIT_VEC cppVar_37591 = (cppVar_37590 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37592 = (cppVar_37591 & cppMask_un_5_);
	BIT_VEC cppVar_37593 = cppVar_37592 + 32;
	cppVar_37593 = (cppVar_37593 & cppMask_un_8_);
	cppVar_37580 = cppVar_37593;
	}
	bool cppVar_37595 = (cppVar_37580 == 130);
	if (cppVar_37595) {
	cppVar_37579 = DPL;
	} else {
	BIT_VEC cppVar_37596;
	BIT_VEC cppVar_37597;
	BIT_VEC cppVar_37598 = PC + 1;
	cppVar_37598 = (cppVar_37598 & cppMask_un_16_);
	BIT_VEC cppVar_37599 = ROM.rd(cppVar_37598);
	BIT_VEC cppVar_37600 = (cppVar_37599 >> 7) & cppMask_un_1_;
	bool cppVar_37601 = (cppVar_37600 == 1);
	if (cppVar_37601) {
	BIT_VEC cppVar_37602 = PC + 1;
	cppVar_37602 = (cppVar_37602 & cppMask_un_16_);
	BIT_VEC cppVar_37603 = ROM.rd(cppVar_37602);
	BIT_VEC cppVar_37604 = (cppVar_37603 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37605 = (cppVar_37604 << 3) | 0;
	cppVar_37605 = (cppVar_37605 & cppMask_un_8_);
	cppVar_37597 = cppVar_37605;
	} else {
	BIT_VEC cppVar_37606 = PC + 1;
	cppVar_37606 = (cppVar_37606 & cppMask_un_16_);
	BIT_VEC cppVar_37607 = ROM.rd(cppVar_37606);
	BIT_VEC cppVar_37608 = (cppVar_37607 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37609 = (cppVar_37608 & cppMask_un_5_);
	BIT_VEC cppVar_37610 = cppVar_37609 + 32;
	cppVar_37610 = (cppVar_37610 & cppMask_un_8_);
	cppVar_37597 = cppVar_37610;
	}
	bool cppVar_37612 = (cppVar_37597 == 131);
	if (cppVar_37612) {
	cppVar_37596 = DPH;
	} else {
	BIT_VEC cppVar_37613;
	BIT_VEC cppVar_37614;
	BIT_VEC cppVar_37615 = PC + 1;
	cppVar_37615 = (cppVar_37615 & cppMask_un_16_);
	BIT_VEC cppVar_37616 = ROM.rd(cppVar_37615);
	BIT_VEC cppVar_37617 = (cppVar_37616 >> 7) & cppMask_un_1_;
	bool cppVar_37618 = (cppVar_37617 == 1);
	if (cppVar_37618) {
	BIT_VEC cppVar_37619 = PC + 1;
	cppVar_37619 = (cppVar_37619 & cppMask_un_16_);
	BIT_VEC cppVar_37620 = ROM.rd(cppVar_37619);
	BIT_VEC cppVar_37621 = (cppVar_37620 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37622 = (cppVar_37621 << 3) | 0;
	cppVar_37622 = (cppVar_37622 & cppMask_un_8_);
	cppVar_37614 = cppVar_37622;
	} else {
	BIT_VEC cppVar_37623 = PC + 1;
	cppVar_37623 = (cppVar_37623 & cppMask_un_16_);
	BIT_VEC cppVar_37624 = ROM.rd(cppVar_37623);
	BIT_VEC cppVar_37625 = (cppVar_37624 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37626 = (cppVar_37625 & cppMask_un_5_);
	BIT_VEC cppVar_37627 = cppVar_37626 + 32;
	cppVar_37627 = (cppVar_37627 & cppMask_un_8_);
	cppVar_37614 = cppVar_37627;
	}
	bool cppVar_37629 = (cppVar_37614 == 135);
	if (cppVar_37629) {
	cppVar_37613 = PCON;
	} else {
	BIT_VEC cppVar_37630;
	BIT_VEC cppVar_37631;
	BIT_VEC cppVar_37632 = PC + 1;
	cppVar_37632 = (cppVar_37632 & cppMask_un_16_);
	BIT_VEC cppVar_37633 = ROM.rd(cppVar_37632);
	BIT_VEC cppVar_37634 = (cppVar_37633 >> 7) & cppMask_un_1_;
	bool cppVar_37635 = (cppVar_37634 == 1);
	if (cppVar_37635) {
	BIT_VEC cppVar_37636 = PC + 1;
	cppVar_37636 = (cppVar_37636 & cppMask_un_16_);
	BIT_VEC cppVar_37637 = ROM.rd(cppVar_37636);
	BIT_VEC cppVar_37638 = (cppVar_37637 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37639 = (cppVar_37638 << 3) | 0;
	cppVar_37639 = (cppVar_37639 & cppMask_un_8_);
	cppVar_37631 = cppVar_37639;
	} else {
	BIT_VEC cppVar_37640 = PC + 1;
	cppVar_37640 = (cppVar_37640 & cppMask_un_16_);
	BIT_VEC cppVar_37641 = ROM.rd(cppVar_37640);
	BIT_VEC cppVar_37642 = (cppVar_37641 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37643 = (cppVar_37642 & cppMask_un_5_);
	BIT_VEC cppVar_37644 = cppVar_37643 + 32;
	cppVar_37644 = (cppVar_37644 & cppMask_un_8_);
	cppVar_37631 = cppVar_37644;
	}
	bool cppVar_37646 = (cppVar_37631 == 136);
	if (cppVar_37646) {
	cppVar_37630 = TCON;
	} else {
	BIT_VEC cppVar_37647;
	BIT_VEC cppVar_37648;
	BIT_VEC cppVar_37649 = PC + 1;
	cppVar_37649 = (cppVar_37649 & cppMask_un_16_);
	BIT_VEC cppVar_37650 = ROM.rd(cppVar_37649);
	BIT_VEC cppVar_37651 = (cppVar_37650 >> 7) & cppMask_un_1_;
	bool cppVar_37652 = (cppVar_37651 == 1);
	if (cppVar_37652) {
	BIT_VEC cppVar_37653 = PC + 1;
	cppVar_37653 = (cppVar_37653 & cppMask_un_16_);
	BIT_VEC cppVar_37654 = ROM.rd(cppVar_37653);
	BIT_VEC cppVar_37655 = (cppVar_37654 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37656 = (cppVar_37655 << 3) | 0;
	cppVar_37656 = (cppVar_37656 & cppMask_un_8_);
	cppVar_37648 = cppVar_37656;
	} else {
	BIT_VEC cppVar_37657 = PC + 1;
	cppVar_37657 = (cppVar_37657 & cppMask_un_16_);
	BIT_VEC cppVar_37658 = ROM.rd(cppVar_37657);
	BIT_VEC cppVar_37659 = (cppVar_37658 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37660 = (cppVar_37659 & cppMask_un_5_);
	BIT_VEC cppVar_37661 = cppVar_37660 + 32;
	cppVar_37661 = (cppVar_37661 & cppMask_un_8_);
	cppVar_37648 = cppVar_37661;
	}
	bool cppVar_37663 = (cppVar_37648 == 137);
	if (cppVar_37663) {
	cppVar_37647 = TMOD;
	} else {
	BIT_VEC cppVar_37664;
	BIT_VEC cppVar_37665;
	BIT_VEC cppVar_37666 = PC + 1;
	cppVar_37666 = (cppVar_37666 & cppMask_un_16_);
	BIT_VEC cppVar_37667 = ROM.rd(cppVar_37666);
	BIT_VEC cppVar_37668 = (cppVar_37667 >> 7) & cppMask_un_1_;
	bool cppVar_37669 = (cppVar_37668 == 1);
	if (cppVar_37669) {
	BIT_VEC cppVar_37670 = PC + 1;
	cppVar_37670 = (cppVar_37670 & cppMask_un_16_);
	BIT_VEC cppVar_37671 = ROM.rd(cppVar_37670);
	BIT_VEC cppVar_37672 = (cppVar_37671 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37673 = (cppVar_37672 << 3) | 0;
	cppVar_37673 = (cppVar_37673 & cppMask_un_8_);
	cppVar_37665 = cppVar_37673;
	} else {
	BIT_VEC cppVar_37674 = PC + 1;
	cppVar_37674 = (cppVar_37674 & cppMask_un_16_);
	BIT_VEC cppVar_37675 = ROM.rd(cppVar_37674);
	BIT_VEC cppVar_37676 = (cppVar_37675 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37677 = (cppVar_37676 & cppMask_un_5_);
	BIT_VEC cppVar_37678 = cppVar_37677 + 32;
	cppVar_37678 = (cppVar_37678 & cppMask_un_8_);
	cppVar_37665 = cppVar_37678;
	}
	bool cppVar_37680 = (cppVar_37665 == 138);
	if (cppVar_37680) {
	cppVar_37664 = TL0;
	} else {
	BIT_VEC cppVar_37681;
	BIT_VEC cppVar_37682;
	BIT_VEC cppVar_37683 = PC + 1;
	cppVar_37683 = (cppVar_37683 & cppMask_un_16_);
	BIT_VEC cppVar_37684 = ROM.rd(cppVar_37683);
	BIT_VEC cppVar_37685 = (cppVar_37684 >> 7) & cppMask_un_1_;
	bool cppVar_37686 = (cppVar_37685 == 1);
	if (cppVar_37686) {
	BIT_VEC cppVar_37687 = PC + 1;
	cppVar_37687 = (cppVar_37687 & cppMask_un_16_);
	BIT_VEC cppVar_37688 = ROM.rd(cppVar_37687);
	BIT_VEC cppVar_37689 = (cppVar_37688 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37690 = (cppVar_37689 << 3) | 0;
	cppVar_37690 = (cppVar_37690 & cppMask_un_8_);
	cppVar_37682 = cppVar_37690;
	} else {
	BIT_VEC cppVar_37691 = PC + 1;
	cppVar_37691 = (cppVar_37691 & cppMask_un_16_);
	BIT_VEC cppVar_37692 = ROM.rd(cppVar_37691);
	BIT_VEC cppVar_37693 = (cppVar_37692 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37694 = (cppVar_37693 & cppMask_un_5_);
	BIT_VEC cppVar_37695 = cppVar_37694 + 32;
	cppVar_37695 = (cppVar_37695 & cppMask_un_8_);
	cppVar_37682 = cppVar_37695;
	}
	bool cppVar_37697 = (cppVar_37682 == 140);
	if (cppVar_37697) {
	cppVar_37681 = TH0;
	} else {
	BIT_VEC cppVar_37698;
	BIT_VEC cppVar_37699;
	BIT_VEC cppVar_37700 = PC + 1;
	cppVar_37700 = (cppVar_37700 & cppMask_un_16_);
	BIT_VEC cppVar_37701 = ROM.rd(cppVar_37700);
	BIT_VEC cppVar_37702 = (cppVar_37701 >> 7) & cppMask_un_1_;
	bool cppVar_37703 = (cppVar_37702 == 1);
	if (cppVar_37703) {
	BIT_VEC cppVar_37704 = PC + 1;
	cppVar_37704 = (cppVar_37704 & cppMask_un_16_);
	BIT_VEC cppVar_37705 = ROM.rd(cppVar_37704);
	BIT_VEC cppVar_37706 = (cppVar_37705 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37707 = (cppVar_37706 << 3) | 0;
	cppVar_37707 = (cppVar_37707 & cppMask_un_8_);
	cppVar_37699 = cppVar_37707;
	} else {
	BIT_VEC cppVar_37708 = PC + 1;
	cppVar_37708 = (cppVar_37708 & cppMask_un_16_);
	BIT_VEC cppVar_37709 = ROM.rd(cppVar_37708);
	BIT_VEC cppVar_37710 = (cppVar_37709 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37711 = (cppVar_37710 & cppMask_un_5_);
	BIT_VEC cppVar_37712 = cppVar_37711 + 32;
	cppVar_37712 = (cppVar_37712 & cppMask_un_8_);
	cppVar_37699 = cppVar_37712;
	}
	bool cppVar_37714 = (cppVar_37699 == 139);
	if (cppVar_37714) {
	cppVar_37698 = TL1;
	} else {
	BIT_VEC cppVar_37715;
	BIT_VEC cppVar_37716;
	BIT_VEC cppVar_37717 = PC + 1;
	cppVar_37717 = (cppVar_37717 & cppMask_un_16_);
	BIT_VEC cppVar_37718 = ROM.rd(cppVar_37717);
	BIT_VEC cppVar_37719 = (cppVar_37718 >> 7) & cppMask_un_1_;
	bool cppVar_37720 = (cppVar_37719 == 1);
	if (cppVar_37720) {
	BIT_VEC cppVar_37721 = PC + 1;
	cppVar_37721 = (cppVar_37721 & cppMask_un_16_);
	BIT_VEC cppVar_37722 = ROM.rd(cppVar_37721);
	BIT_VEC cppVar_37723 = (cppVar_37722 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37724 = (cppVar_37723 << 3) | 0;
	cppVar_37724 = (cppVar_37724 & cppMask_un_8_);
	cppVar_37716 = cppVar_37724;
	} else {
	BIT_VEC cppVar_37725 = PC + 1;
	cppVar_37725 = (cppVar_37725 & cppMask_un_16_);
	BIT_VEC cppVar_37726 = ROM.rd(cppVar_37725);
	BIT_VEC cppVar_37727 = (cppVar_37726 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37728 = (cppVar_37727 & cppMask_un_5_);
	BIT_VEC cppVar_37729 = cppVar_37728 + 32;
	cppVar_37729 = (cppVar_37729 & cppMask_un_8_);
	cppVar_37716 = cppVar_37729;
	}
	bool cppVar_37731 = (cppVar_37716 == 141);
	if (cppVar_37731) {
	cppVar_37715 = TH1;
	} else {
	BIT_VEC cppVar_37732;
	BIT_VEC cppVar_37733;
	BIT_VEC cppVar_37734 = PC + 1;
	cppVar_37734 = (cppVar_37734 & cppMask_un_16_);
	BIT_VEC cppVar_37735 = ROM.rd(cppVar_37734);
	BIT_VEC cppVar_37736 = (cppVar_37735 >> 7) & cppMask_un_1_;
	bool cppVar_37737 = (cppVar_37736 == 1);
	if (cppVar_37737) {
	BIT_VEC cppVar_37738 = PC + 1;
	cppVar_37738 = (cppVar_37738 & cppMask_un_16_);
	BIT_VEC cppVar_37739 = ROM.rd(cppVar_37738);
	BIT_VEC cppVar_37740 = (cppVar_37739 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37741 = (cppVar_37740 << 3) | 0;
	cppVar_37741 = (cppVar_37741 & cppMask_un_8_);
	cppVar_37733 = cppVar_37741;
	} else {
	BIT_VEC cppVar_37742 = PC + 1;
	cppVar_37742 = (cppVar_37742 & cppMask_un_16_);
	BIT_VEC cppVar_37743 = ROM.rd(cppVar_37742);
	BIT_VEC cppVar_37744 = (cppVar_37743 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37745 = (cppVar_37744 & cppMask_un_5_);
	BIT_VEC cppVar_37746 = cppVar_37745 + 32;
	cppVar_37746 = (cppVar_37746 & cppMask_un_8_);
	cppVar_37733 = cppVar_37746;
	}
	bool cppVar_37748 = (cppVar_37733 == 144);
	if (cppVar_37748) {
	cppVar_37732 = P1;
	} else {
	BIT_VEC cppVar_37749;
	BIT_VEC cppVar_37750;
	BIT_VEC cppVar_37751 = PC + 1;
	cppVar_37751 = (cppVar_37751 & cppMask_un_16_);
	BIT_VEC cppVar_37752 = ROM.rd(cppVar_37751);
	BIT_VEC cppVar_37753 = (cppVar_37752 >> 7) & cppMask_un_1_;
	bool cppVar_37754 = (cppVar_37753 == 1);
	if (cppVar_37754) {
	BIT_VEC cppVar_37755 = PC + 1;
	cppVar_37755 = (cppVar_37755 & cppMask_un_16_);
	BIT_VEC cppVar_37756 = ROM.rd(cppVar_37755);
	BIT_VEC cppVar_37757 = (cppVar_37756 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37758 = (cppVar_37757 << 3) | 0;
	cppVar_37758 = (cppVar_37758 & cppMask_un_8_);
	cppVar_37750 = cppVar_37758;
	} else {
	BIT_VEC cppVar_37759 = PC + 1;
	cppVar_37759 = (cppVar_37759 & cppMask_un_16_);
	BIT_VEC cppVar_37760 = ROM.rd(cppVar_37759);
	BIT_VEC cppVar_37761 = (cppVar_37760 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37762 = (cppVar_37761 & cppMask_un_5_);
	BIT_VEC cppVar_37763 = cppVar_37762 + 32;
	cppVar_37763 = (cppVar_37763 & cppMask_un_8_);
	cppVar_37750 = cppVar_37763;
	}
	bool cppVar_37765 = (cppVar_37750 == 152);
	if (cppVar_37765) {
	cppVar_37749 = SCON;
	} else {
	BIT_VEC cppVar_37766;
	BIT_VEC cppVar_37767;
	BIT_VEC cppVar_37768 = PC + 1;
	cppVar_37768 = (cppVar_37768 & cppMask_un_16_);
	BIT_VEC cppVar_37769 = ROM.rd(cppVar_37768);
	BIT_VEC cppVar_37770 = (cppVar_37769 >> 7) & cppMask_un_1_;
	bool cppVar_37771 = (cppVar_37770 == 1);
	if (cppVar_37771) {
	BIT_VEC cppVar_37772 = PC + 1;
	cppVar_37772 = (cppVar_37772 & cppMask_un_16_);
	BIT_VEC cppVar_37773 = ROM.rd(cppVar_37772);
	BIT_VEC cppVar_37774 = (cppVar_37773 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37775 = (cppVar_37774 << 3) | 0;
	cppVar_37775 = (cppVar_37775 & cppMask_un_8_);
	cppVar_37767 = cppVar_37775;
	} else {
	BIT_VEC cppVar_37776 = PC + 1;
	cppVar_37776 = (cppVar_37776 & cppMask_un_16_);
	BIT_VEC cppVar_37777 = ROM.rd(cppVar_37776);
	BIT_VEC cppVar_37778 = (cppVar_37777 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37779 = (cppVar_37778 & cppMask_un_5_);
	BIT_VEC cppVar_37780 = cppVar_37779 + 32;
	cppVar_37780 = (cppVar_37780 & cppMask_un_8_);
	cppVar_37767 = cppVar_37780;
	}
	bool cppVar_37782 = (cppVar_37767 == 153);
	if (cppVar_37782) {
	cppVar_37766 = SBUF;
	} else {
	BIT_VEC cppVar_37783;
	BIT_VEC cppVar_37784;
	BIT_VEC cppVar_37785 = PC + 1;
	cppVar_37785 = (cppVar_37785 & cppMask_un_16_);
	BIT_VEC cppVar_37786 = ROM.rd(cppVar_37785);
	BIT_VEC cppVar_37787 = (cppVar_37786 >> 7) & cppMask_un_1_;
	bool cppVar_37788 = (cppVar_37787 == 1);
	if (cppVar_37788) {
	BIT_VEC cppVar_37789 = PC + 1;
	cppVar_37789 = (cppVar_37789 & cppMask_un_16_);
	BIT_VEC cppVar_37790 = ROM.rd(cppVar_37789);
	BIT_VEC cppVar_37791 = (cppVar_37790 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37792 = (cppVar_37791 << 3) | 0;
	cppVar_37792 = (cppVar_37792 & cppMask_un_8_);
	cppVar_37784 = cppVar_37792;
	} else {
	BIT_VEC cppVar_37793 = PC + 1;
	cppVar_37793 = (cppVar_37793 & cppMask_un_16_);
	BIT_VEC cppVar_37794 = ROM.rd(cppVar_37793);
	BIT_VEC cppVar_37795 = (cppVar_37794 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37796 = (cppVar_37795 & cppMask_un_5_);
	BIT_VEC cppVar_37797 = cppVar_37796 + 32;
	cppVar_37797 = (cppVar_37797 & cppMask_un_8_);
	cppVar_37784 = cppVar_37797;
	}
	bool cppVar_37799 = (cppVar_37784 == 160);
	if (cppVar_37799) {
	cppVar_37783 = P2;
	} else {
	BIT_VEC cppVar_37800;
	BIT_VEC cppVar_37801;
	BIT_VEC cppVar_37802 = PC + 1;
	cppVar_37802 = (cppVar_37802 & cppMask_un_16_);
	BIT_VEC cppVar_37803 = ROM.rd(cppVar_37802);
	BIT_VEC cppVar_37804 = (cppVar_37803 >> 7) & cppMask_un_1_;
	bool cppVar_37805 = (cppVar_37804 == 1);
	if (cppVar_37805) {
	BIT_VEC cppVar_37806 = PC + 1;
	cppVar_37806 = (cppVar_37806 & cppMask_un_16_);
	BIT_VEC cppVar_37807 = ROM.rd(cppVar_37806);
	BIT_VEC cppVar_37808 = (cppVar_37807 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37809 = (cppVar_37808 << 3) | 0;
	cppVar_37809 = (cppVar_37809 & cppMask_un_8_);
	cppVar_37801 = cppVar_37809;
	} else {
	BIT_VEC cppVar_37810 = PC + 1;
	cppVar_37810 = (cppVar_37810 & cppMask_un_16_);
	BIT_VEC cppVar_37811 = ROM.rd(cppVar_37810);
	BIT_VEC cppVar_37812 = (cppVar_37811 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37813 = (cppVar_37812 & cppMask_un_5_);
	BIT_VEC cppVar_37814 = cppVar_37813 + 32;
	cppVar_37814 = (cppVar_37814 & cppMask_un_8_);
	cppVar_37801 = cppVar_37814;
	}
	bool cppVar_37816 = (cppVar_37801 == 168);
	if (cppVar_37816) {
	cppVar_37800 = IE;
	} else {
	BIT_VEC cppVar_37817;
	BIT_VEC cppVar_37818;
	BIT_VEC cppVar_37819 = PC + 1;
	cppVar_37819 = (cppVar_37819 & cppMask_un_16_);
	BIT_VEC cppVar_37820 = ROM.rd(cppVar_37819);
	BIT_VEC cppVar_37821 = (cppVar_37820 >> 7) & cppMask_un_1_;
	bool cppVar_37822 = (cppVar_37821 == 1);
	if (cppVar_37822) {
	BIT_VEC cppVar_37823 = PC + 1;
	cppVar_37823 = (cppVar_37823 & cppMask_un_16_);
	BIT_VEC cppVar_37824 = ROM.rd(cppVar_37823);
	BIT_VEC cppVar_37825 = (cppVar_37824 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37826 = (cppVar_37825 << 3) | 0;
	cppVar_37826 = (cppVar_37826 & cppMask_un_8_);
	cppVar_37818 = cppVar_37826;
	} else {
	BIT_VEC cppVar_37827 = PC + 1;
	cppVar_37827 = (cppVar_37827 & cppMask_un_16_);
	BIT_VEC cppVar_37828 = ROM.rd(cppVar_37827);
	BIT_VEC cppVar_37829 = (cppVar_37828 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37830 = (cppVar_37829 & cppMask_un_5_);
	BIT_VEC cppVar_37831 = cppVar_37830 + 32;
	cppVar_37831 = (cppVar_37831 & cppMask_un_8_);
	cppVar_37818 = cppVar_37831;
	}
	bool cppVar_37833 = (cppVar_37818 == 176);
	if (cppVar_37833) {
	cppVar_37817 = P3;
	} else {
	BIT_VEC cppVar_37834;
	BIT_VEC cppVar_37835;
	BIT_VEC cppVar_37836 = PC + 1;
	cppVar_37836 = (cppVar_37836 & cppMask_un_16_);
	BIT_VEC cppVar_37837 = ROM.rd(cppVar_37836);
	BIT_VEC cppVar_37838 = (cppVar_37837 >> 7) & cppMask_un_1_;
	bool cppVar_37839 = (cppVar_37838 == 1);
	if (cppVar_37839) {
	BIT_VEC cppVar_37840 = PC + 1;
	cppVar_37840 = (cppVar_37840 & cppMask_un_16_);
	BIT_VEC cppVar_37841 = ROM.rd(cppVar_37840);
	BIT_VEC cppVar_37842 = (cppVar_37841 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37843 = (cppVar_37842 << 3) | 0;
	cppVar_37843 = (cppVar_37843 & cppMask_un_8_);
	cppVar_37835 = cppVar_37843;
	} else {
	BIT_VEC cppVar_37844 = PC + 1;
	cppVar_37844 = (cppVar_37844 & cppMask_un_16_);
	BIT_VEC cppVar_37845 = ROM.rd(cppVar_37844);
	BIT_VEC cppVar_37846 = (cppVar_37845 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37847 = (cppVar_37846 & cppMask_un_5_);
	BIT_VEC cppVar_37848 = cppVar_37847 + 32;
	cppVar_37848 = (cppVar_37848 & cppMask_un_8_);
	cppVar_37835 = cppVar_37848;
	}
	bool cppVar_37850 = (cppVar_37835 == 184);
	if (cppVar_37850) {
	cppVar_37834 = IP;
	} else {
	BIT_VEC cppVar_37851;
	BIT_VEC cppVar_37852;
	BIT_VEC cppVar_37853 = PC + 1;
	cppVar_37853 = (cppVar_37853 & cppMask_un_16_);
	BIT_VEC cppVar_37854 = ROM.rd(cppVar_37853);
	BIT_VEC cppVar_37855 = (cppVar_37854 >> 7) & cppMask_un_1_;
	bool cppVar_37856 = (cppVar_37855 == 1);
	if (cppVar_37856) {
	BIT_VEC cppVar_37857 = PC + 1;
	cppVar_37857 = (cppVar_37857 & cppMask_un_16_);
	BIT_VEC cppVar_37858 = ROM.rd(cppVar_37857);
	BIT_VEC cppVar_37859 = (cppVar_37858 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37860 = (cppVar_37859 << 3) | 0;
	cppVar_37860 = (cppVar_37860 & cppMask_un_8_);
	cppVar_37852 = cppVar_37860;
	} else {
	BIT_VEC cppVar_37861 = PC + 1;
	cppVar_37861 = (cppVar_37861 & cppMask_un_16_);
	BIT_VEC cppVar_37862 = ROM.rd(cppVar_37861);
	BIT_VEC cppVar_37863 = (cppVar_37862 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37864 = (cppVar_37863 & cppMask_un_5_);
	BIT_VEC cppVar_37865 = cppVar_37864 + 32;
	cppVar_37865 = (cppVar_37865 & cppMask_un_8_);
	cppVar_37852 = cppVar_37865;
	}
	bool cppVar_37867 = (cppVar_37852 == 208);
	if (cppVar_37867) {
	cppVar_37851 = PSW;
	} else {
	BIT_VEC cppVar_37868;
	BIT_VEC cppVar_37869;
	BIT_VEC cppVar_37870 = PC + 1;
	cppVar_37870 = (cppVar_37870 & cppMask_un_16_);
	BIT_VEC cppVar_37871 = ROM.rd(cppVar_37870);
	BIT_VEC cppVar_37872 = (cppVar_37871 >> 7) & cppMask_un_1_;
	bool cppVar_37873 = (cppVar_37872 == 1);
	if (cppVar_37873) {
	BIT_VEC cppVar_37874 = PC + 1;
	cppVar_37874 = (cppVar_37874 & cppMask_un_16_);
	BIT_VEC cppVar_37875 = ROM.rd(cppVar_37874);
	BIT_VEC cppVar_37876 = (cppVar_37875 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37877 = (cppVar_37876 << 3) | 0;
	cppVar_37877 = (cppVar_37877 & cppMask_un_8_);
	cppVar_37869 = cppVar_37877;
	} else {
	BIT_VEC cppVar_37878 = PC + 1;
	cppVar_37878 = (cppVar_37878 & cppMask_un_16_);
	BIT_VEC cppVar_37879 = ROM.rd(cppVar_37878);
	BIT_VEC cppVar_37880 = (cppVar_37879 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37881 = (cppVar_37880 & cppMask_un_5_);
	BIT_VEC cppVar_37882 = cppVar_37881 + 32;
	cppVar_37882 = (cppVar_37882 & cppMask_un_8_);
	cppVar_37869 = cppVar_37882;
	}
	bool cppVar_37884 = (cppVar_37869 == 224);
	if (cppVar_37884) {
	cppVar_37868 = ACC;
	} else {
	BIT_VEC cppVar_37885;
	BIT_VEC cppVar_37886;
	BIT_VEC cppVar_37887 = PC + 1;
	cppVar_37887 = (cppVar_37887 & cppMask_un_16_);
	BIT_VEC cppVar_37888 = ROM.rd(cppVar_37887);
	BIT_VEC cppVar_37889 = (cppVar_37888 >> 7) & cppMask_un_1_;
	bool cppVar_37890 = (cppVar_37889 == 1);
	if (cppVar_37890) {
	BIT_VEC cppVar_37891 = PC + 1;
	cppVar_37891 = (cppVar_37891 & cppMask_un_16_);
	BIT_VEC cppVar_37892 = ROM.rd(cppVar_37891);
	BIT_VEC cppVar_37893 = (cppVar_37892 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37894 = (cppVar_37893 << 3) | 0;
	cppVar_37894 = (cppVar_37894 & cppMask_un_8_);
	cppVar_37886 = cppVar_37894;
	} else {
	BIT_VEC cppVar_37895 = PC + 1;
	cppVar_37895 = (cppVar_37895 & cppMask_un_16_);
	BIT_VEC cppVar_37896 = ROM.rd(cppVar_37895);
	BIT_VEC cppVar_37897 = (cppVar_37896 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_37898 = (cppVar_37897 & cppMask_un_5_);
	BIT_VEC cppVar_37899 = cppVar_37898 + 32;
	cppVar_37899 = (cppVar_37899 & cppMask_un_8_);
	cppVar_37886 = cppVar_37899;
	}
	bool cppVar_37901 = (cppVar_37886 == 240);
	if (cppVar_37901) {
	cppVar_37885 = B;
	} else {
	cppVar_37885 = 0;
	}
	cppVar_37868 = cppVar_37885;
	}
	cppVar_37851 = cppVar_37868;
	}
	cppVar_37834 = cppVar_37851;
	}
	cppVar_37817 = cppVar_37834;
	}
	cppVar_37800 = cppVar_37817;
	}
	cppVar_37783 = cppVar_37800;
	}
	cppVar_37766 = cppVar_37783;
	}
	cppVar_37749 = cppVar_37766;
	}
	cppVar_37732 = cppVar_37749;
	}
	cppVar_37715 = cppVar_37732;
	}
	cppVar_37698 = cppVar_37715;
	}
	cppVar_37681 = cppVar_37698;
	}
	cppVar_37664 = cppVar_37681;
	}
	cppVar_37647 = cppVar_37664;
	}
	cppVar_37630 = cppVar_37647;
	}
	cppVar_37613 = cppVar_37630;
	}
	cppVar_37596 = cppVar_37613;
	}
	cppVar_37579 = cppVar_37596;
	}
	cppVar_37562 = cppVar_37579;
	}
	cppVar_37545 = cppVar_37562;
	}
	cppVar_37512 = cppVar_37545;
	}
	BIT_VEC cppVar_37903 = cppVar_37511 & cppVar_37512;
	BIT_VEC cppVar_37904 = (PSW >> 7) & cppMask_un_1_;
	BIT_VEC cppVar_37905 = (cppVar_37904 & cppMask_un_1_);
	BIT_VEC cppVar_37906 = PC + 1;
	cppVar_37906 = (cppVar_37906 & cppMask_un_16_);
	BIT_VEC cppVar_37907 = ROM.rd(cppVar_37906);
	BIT_VEC cppVar_37908 = (cppVar_37907 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_37909 = (cppVar_37908 & cppMask_un_3_);
	BIT_VEC cppVar_37910 = cppVar_37905 << static_cast<unsigned>(cppVar_37909);
	cppVar_37910 = (cppVar_37910 & cppMask_un_8_);
	BIT_VEC cppVar_37911 = cppVar_37903 | cppVar_37910;
	cppVar_37484 = cppVar_37911;
	} else {
	cppVar_37484 = P3;
	}
	cppVar_37480 = cppVar_37484;
	} else {
	BIT_VEC cppVar_37912;
	BIT_VEC cppVar_37913 = ROM.rd(PC);
	bool cppVar_37915 = (cppVar_37913 == 143);
	if (cppVar_37915) {
	BIT_VEC cppVar_37916;
	BIT_VEC cppVar_37918 = PC + 1;
	cppVar_37918 = (cppVar_37918 & cppMask_un_16_);
	BIT_VEC cppVar_37919 = ROM.rd(cppVar_37918);
	bool cppVar_37921 = (cppVar_37919 == 176);
	if (cppVar_37921) {
	BIT_VEC cppVar_37922;
	BIT_VEC cppVar_37924 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37926 = (cppVar_37924 << 3) | 7;
	cppVar_37926 = (cppVar_37926 & cppMask_un_5_);
	BIT_VEC cppVar_37927 = (0 << 5) | cppVar_37926;
	cppVar_37927 = (cppVar_37927 & cppMask_un_8_);
	BIT_VEC cppVar_37928 = (cppVar_37927 >> 7) & cppMask_un_1_;
	bool cppVar_37930 = (cppVar_37928 == 0);
	if (cppVar_37930) {
	BIT_VEC cppVar_37931 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37932 = (cppVar_37931 << 3) | 7;
	cppVar_37932 = (cppVar_37932 & cppMask_un_5_);
	BIT_VEC cppVar_37933 = (0 << 5) | cppVar_37932;
	cppVar_37933 = (cppVar_37933 & cppMask_un_8_);
	BIT_VEC cppVar_37934 = IRAM.rd(cppVar_37933);
	cppVar_37922 = cppVar_37934;
	} else {
	BIT_VEC cppVar_37935;
	BIT_VEC cppVar_37936 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37937 = (cppVar_37936 << 3) | 7;
	cppVar_37937 = (cppVar_37937 & cppMask_un_5_);
	BIT_VEC cppVar_37938 = (0 << 5) | cppVar_37937;
	cppVar_37938 = (cppVar_37938 & cppMask_un_8_);
	bool cppVar_37940 = (cppVar_37938 == 128);
	if (cppVar_37940) {
	cppVar_37935 = P0;
	} else {
	BIT_VEC cppVar_37941;
	BIT_VEC cppVar_37942 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37943 = (cppVar_37942 << 3) | 7;
	cppVar_37943 = (cppVar_37943 & cppMask_un_5_);
	BIT_VEC cppVar_37944 = (0 << 5) | cppVar_37943;
	cppVar_37944 = (cppVar_37944 & cppMask_un_8_);
	bool cppVar_37946 = (cppVar_37944 == 129);
	if (cppVar_37946) {
	cppVar_37941 = SP;
	} else {
	BIT_VEC cppVar_37947;
	BIT_VEC cppVar_37948 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37949 = (cppVar_37948 << 3) | 7;
	cppVar_37949 = (cppVar_37949 & cppMask_un_5_);
	BIT_VEC cppVar_37950 = (0 << 5) | cppVar_37949;
	cppVar_37950 = (cppVar_37950 & cppMask_un_8_);
	bool cppVar_37952 = (cppVar_37950 == 130);
	if (cppVar_37952) {
	cppVar_37947 = DPL;
	} else {
	BIT_VEC cppVar_37953;
	BIT_VEC cppVar_37954 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37955 = (cppVar_37954 << 3) | 7;
	cppVar_37955 = (cppVar_37955 & cppMask_un_5_);
	BIT_VEC cppVar_37956 = (0 << 5) | cppVar_37955;
	cppVar_37956 = (cppVar_37956 & cppMask_un_8_);
	bool cppVar_37958 = (cppVar_37956 == 131);
	if (cppVar_37958) {
	cppVar_37953 = DPH;
	} else {
	BIT_VEC cppVar_37959;
	BIT_VEC cppVar_37960 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37961 = (cppVar_37960 << 3) | 7;
	cppVar_37961 = (cppVar_37961 & cppMask_un_5_);
	BIT_VEC cppVar_37962 = (0 << 5) | cppVar_37961;
	cppVar_37962 = (cppVar_37962 & cppMask_un_8_);
	bool cppVar_37964 = (cppVar_37962 == 135);
	if (cppVar_37964) {
	cppVar_37959 = PCON;
	} else {
	BIT_VEC cppVar_37965;
	BIT_VEC cppVar_37966 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37967 = (cppVar_37966 << 3) | 7;
	cppVar_37967 = (cppVar_37967 & cppMask_un_5_);
	BIT_VEC cppVar_37968 = (0 << 5) | cppVar_37967;
	cppVar_37968 = (cppVar_37968 & cppMask_un_8_);
	bool cppVar_37970 = (cppVar_37968 == 136);
	if (cppVar_37970) {
	cppVar_37965 = TCON;
	} else {
	BIT_VEC cppVar_37971;
	BIT_VEC cppVar_37972 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37973 = (cppVar_37972 << 3) | 7;
	cppVar_37973 = (cppVar_37973 & cppMask_un_5_);
	BIT_VEC cppVar_37974 = (0 << 5) | cppVar_37973;
	cppVar_37974 = (cppVar_37974 & cppMask_un_8_);
	bool cppVar_37976 = (cppVar_37974 == 137);
	if (cppVar_37976) {
	cppVar_37971 = TMOD;
	} else {
	BIT_VEC cppVar_37977;
	BIT_VEC cppVar_37978 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37979 = (cppVar_37978 << 3) | 7;
	cppVar_37979 = (cppVar_37979 & cppMask_un_5_);
	BIT_VEC cppVar_37980 = (0 << 5) | cppVar_37979;
	cppVar_37980 = (cppVar_37980 & cppMask_un_8_);
	bool cppVar_37982 = (cppVar_37980 == 138);
	if (cppVar_37982) {
	cppVar_37977 = TL0;
	} else {
	BIT_VEC cppVar_37983;
	BIT_VEC cppVar_37984 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37985 = (cppVar_37984 << 3) | 7;
	cppVar_37985 = (cppVar_37985 & cppMask_un_5_);
	BIT_VEC cppVar_37986 = (0 << 5) | cppVar_37985;
	cppVar_37986 = (cppVar_37986 & cppMask_un_8_);
	bool cppVar_37988 = (cppVar_37986 == 140);
	if (cppVar_37988) {
	cppVar_37983 = TH0;
	} else {
	BIT_VEC cppVar_37989;
	BIT_VEC cppVar_37990 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37991 = (cppVar_37990 << 3) | 7;
	cppVar_37991 = (cppVar_37991 & cppMask_un_5_);
	BIT_VEC cppVar_37992 = (0 << 5) | cppVar_37991;
	cppVar_37992 = (cppVar_37992 & cppMask_un_8_);
	bool cppVar_37994 = (cppVar_37992 == 139);
	if (cppVar_37994) {
	cppVar_37989 = TL1;
	} else {
	BIT_VEC cppVar_37995;
	BIT_VEC cppVar_37996 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_37997 = (cppVar_37996 << 3) | 7;
	cppVar_37997 = (cppVar_37997 & cppMask_un_5_);
	BIT_VEC cppVar_37998 = (0 << 5) | cppVar_37997;
	cppVar_37998 = (cppVar_37998 & cppMask_un_8_);
	bool cppVar_38000 = (cppVar_37998 == 141);
	if (cppVar_38000) {
	cppVar_37995 = TH1;
	} else {
	BIT_VEC cppVar_38001;
	BIT_VEC cppVar_38002 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38003 = (cppVar_38002 << 3) | 7;
	cppVar_38003 = (cppVar_38003 & cppMask_un_5_);
	BIT_VEC cppVar_38004 = (0 << 5) | cppVar_38003;
	cppVar_38004 = (cppVar_38004 & cppMask_un_8_);
	bool cppVar_38006 = (cppVar_38004 == 144);
	if (cppVar_38006) {
	cppVar_38001 = P1;
	} else {
	BIT_VEC cppVar_38007;
	BIT_VEC cppVar_38008 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38009 = (cppVar_38008 << 3) | 7;
	cppVar_38009 = (cppVar_38009 & cppMask_un_5_);
	BIT_VEC cppVar_38010 = (0 << 5) | cppVar_38009;
	cppVar_38010 = (cppVar_38010 & cppMask_un_8_);
	bool cppVar_38012 = (cppVar_38010 == 152);
	if (cppVar_38012) {
	cppVar_38007 = SCON;
	} else {
	BIT_VEC cppVar_38013;
	BIT_VEC cppVar_38014 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38015 = (cppVar_38014 << 3) | 7;
	cppVar_38015 = (cppVar_38015 & cppMask_un_5_);
	BIT_VEC cppVar_38016 = (0 << 5) | cppVar_38015;
	cppVar_38016 = (cppVar_38016 & cppMask_un_8_);
	bool cppVar_38018 = (cppVar_38016 == 153);
	if (cppVar_38018) {
	cppVar_38013 = SBUF;
	} else {
	BIT_VEC cppVar_38019;
	BIT_VEC cppVar_38020 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38021 = (cppVar_38020 << 3) | 7;
	cppVar_38021 = (cppVar_38021 & cppMask_un_5_);
	BIT_VEC cppVar_38022 = (0 << 5) | cppVar_38021;
	cppVar_38022 = (cppVar_38022 & cppMask_un_8_);
	bool cppVar_38024 = (cppVar_38022 == 160);
	if (cppVar_38024) {
	cppVar_38019 = P2;
	} else {
	BIT_VEC cppVar_38025;
	BIT_VEC cppVar_38026 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38027 = (cppVar_38026 << 3) | 7;
	cppVar_38027 = (cppVar_38027 & cppMask_un_5_);
	BIT_VEC cppVar_38028 = (0 << 5) | cppVar_38027;
	cppVar_38028 = (cppVar_38028 & cppMask_un_8_);
	bool cppVar_38030 = (cppVar_38028 == 168);
	if (cppVar_38030) {
	cppVar_38025 = IE;
	} else {
	BIT_VEC cppVar_38031;
	BIT_VEC cppVar_38032 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38033 = (cppVar_38032 << 3) | 7;
	cppVar_38033 = (cppVar_38033 & cppMask_un_5_);
	BIT_VEC cppVar_38034 = (0 << 5) | cppVar_38033;
	cppVar_38034 = (cppVar_38034 & cppMask_un_8_);
	bool cppVar_38036 = (cppVar_38034 == 176);
	if (cppVar_38036) {
	cppVar_38031 = P3;
	} else {
	BIT_VEC cppVar_38037;
	BIT_VEC cppVar_38038 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38039 = (cppVar_38038 << 3) | 7;
	cppVar_38039 = (cppVar_38039 & cppMask_un_5_);
	BIT_VEC cppVar_38040 = (0 << 5) | cppVar_38039;
	cppVar_38040 = (cppVar_38040 & cppMask_un_8_);
	bool cppVar_38042 = (cppVar_38040 == 184);
	if (cppVar_38042) {
	cppVar_38037 = IP;
	} else {
	BIT_VEC cppVar_38043;
	BIT_VEC cppVar_38044 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38045 = (cppVar_38044 << 3) | 7;
	cppVar_38045 = (cppVar_38045 & cppMask_un_5_);
	BIT_VEC cppVar_38046 = (0 << 5) | cppVar_38045;
	cppVar_38046 = (cppVar_38046 & cppMask_un_8_);
	bool cppVar_38048 = (cppVar_38046 == 208);
	if (cppVar_38048) {
	cppVar_38043 = PSW;
	} else {
	BIT_VEC cppVar_38049;
	BIT_VEC cppVar_38050 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38051 = (cppVar_38050 << 3) | 7;
	cppVar_38051 = (cppVar_38051 & cppMask_un_5_);
	BIT_VEC cppVar_38052 = (0 << 5) | cppVar_38051;
	cppVar_38052 = (cppVar_38052 & cppMask_un_8_);
	bool cppVar_38054 = (cppVar_38052 == 224);
	if (cppVar_38054) {
	cppVar_38049 = ACC;
	} else {
	BIT_VEC cppVar_38055;
	BIT_VEC cppVar_38056 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38057 = (cppVar_38056 << 3) | 7;
	cppVar_38057 = (cppVar_38057 & cppMask_un_5_);
	BIT_VEC cppVar_38058 = (0 << 5) | cppVar_38057;
	cppVar_38058 = (cppVar_38058 & cppMask_un_8_);
	bool cppVar_38060 = (cppVar_38058 == 240);
	if (cppVar_38060) {
	cppVar_38055 = B;
	} else {
	cppVar_38055 = 0;
	}
	cppVar_38049 = cppVar_38055;
	}
	cppVar_38043 = cppVar_38049;
	}
	cppVar_38037 = cppVar_38043;
	}
	cppVar_38031 = cppVar_38037;
	}
	cppVar_38025 = cppVar_38031;
	}
	cppVar_38019 = cppVar_38025;
	}
	cppVar_38013 = cppVar_38019;
	}
	cppVar_38007 = cppVar_38013;
	}
	cppVar_38001 = cppVar_38007;
	}
	cppVar_37995 = cppVar_38001;
	}
	cppVar_37989 = cppVar_37995;
	}
	cppVar_37983 = cppVar_37989;
	}
	cppVar_37977 = cppVar_37983;
	}
	cppVar_37971 = cppVar_37977;
	}
	cppVar_37965 = cppVar_37971;
	}
	cppVar_37959 = cppVar_37965;
	}
	cppVar_37953 = cppVar_37959;
	}
	cppVar_37947 = cppVar_37953;
	}
	cppVar_37941 = cppVar_37947;
	}
	cppVar_37935 = cppVar_37941;
	}
	cppVar_37922 = cppVar_37935;
	}
	cppVar_37916 = cppVar_37922;
	} else {
	cppVar_37916 = P3;
	}
	cppVar_37912 = cppVar_37916;
	} else {
	BIT_VEC cppVar_38062;
	BIT_VEC cppVar_38063 = ROM.rd(PC);
	bool cppVar_38065 = (cppVar_38063 == 142);
	if (cppVar_38065) {
	BIT_VEC cppVar_38066;
	BIT_VEC cppVar_38068 = PC + 1;
	cppVar_38068 = (cppVar_38068 & cppMask_un_16_);
	BIT_VEC cppVar_38069 = ROM.rd(cppVar_38068);
	bool cppVar_38071 = (cppVar_38069 == 176);
	if (cppVar_38071) {
	BIT_VEC cppVar_38072;
	BIT_VEC cppVar_38074 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38076 = (cppVar_38074 << 3) | 6;
	cppVar_38076 = (cppVar_38076 & cppMask_un_5_);
	BIT_VEC cppVar_38077 = (0 << 5) | cppVar_38076;
	cppVar_38077 = (cppVar_38077 & cppMask_un_8_);
	BIT_VEC cppVar_38078 = (cppVar_38077 >> 7) & cppMask_un_1_;
	bool cppVar_38080 = (cppVar_38078 == 0);
	if (cppVar_38080) {
	BIT_VEC cppVar_38081 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38082 = (cppVar_38081 << 3) | 6;
	cppVar_38082 = (cppVar_38082 & cppMask_un_5_);
	BIT_VEC cppVar_38083 = (0 << 5) | cppVar_38082;
	cppVar_38083 = (cppVar_38083 & cppMask_un_8_);
	BIT_VEC cppVar_38084 = IRAM.rd(cppVar_38083);
	cppVar_38072 = cppVar_38084;
	} else {
	BIT_VEC cppVar_38085;
	BIT_VEC cppVar_38086 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38087 = (cppVar_38086 << 3) | 6;
	cppVar_38087 = (cppVar_38087 & cppMask_un_5_);
	BIT_VEC cppVar_38088 = (0 << 5) | cppVar_38087;
	cppVar_38088 = (cppVar_38088 & cppMask_un_8_);
	bool cppVar_38090 = (cppVar_38088 == 128);
	if (cppVar_38090) {
	cppVar_38085 = P0;
	} else {
	BIT_VEC cppVar_38091;
	BIT_VEC cppVar_38092 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38093 = (cppVar_38092 << 3) | 6;
	cppVar_38093 = (cppVar_38093 & cppMask_un_5_);
	BIT_VEC cppVar_38094 = (0 << 5) | cppVar_38093;
	cppVar_38094 = (cppVar_38094 & cppMask_un_8_);
	bool cppVar_38096 = (cppVar_38094 == 129);
	if (cppVar_38096) {
	cppVar_38091 = SP;
	} else {
	BIT_VEC cppVar_38097;
	BIT_VEC cppVar_38098 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38099 = (cppVar_38098 << 3) | 6;
	cppVar_38099 = (cppVar_38099 & cppMask_un_5_);
	BIT_VEC cppVar_38100 = (0 << 5) | cppVar_38099;
	cppVar_38100 = (cppVar_38100 & cppMask_un_8_);
	bool cppVar_38102 = (cppVar_38100 == 130);
	if (cppVar_38102) {
	cppVar_38097 = DPL;
	} else {
	BIT_VEC cppVar_38103;
	BIT_VEC cppVar_38104 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38105 = (cppVar_38104 << 3) | 6;
	cppVar_38105 = (cppVar_38105 & cppMask_un_5_);
	BIT_VEC cppVar_38106 = (0 << 5) | cppVar_38105;
	cppVar_38106 = (cppVar_38106 & cppMask_un_8_);
	bool cppVar_38108 = (cppVar_38106 == 131);
	if (cppVar_38108) {
	cppVar_38103 = DPH;
	} else {
	BIT_VEC cppVar_38109;
	BIT_VEC cppVar_38110 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38111 = (cppVar_38110 << 3) | 6;
	cppVar_38111 = (cppVar_38111 & cppMask_un_5_);
	BIT_VEC cppVar_38112 = (0 << 5) | cppVar_38111;
	cppVar_38112 = (cppVar_38112 & cppMask_un_8_);
	bool cppVar_38114 = (cppVar_38112 == 135);
	if (cppVar_38114) {
	cppVar_38109 = PCON;
	} else {
	BIT_VEC cppVar_38115;
	BIT_VEC cppVar_38116 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38117 = (cppVar_38116 << 3) | 6;
	cppVar_38117 = (cppVar_38117 & cppMask_un_5_);
	BIT_VEC cppVar_38118 = (0 << 5) | cppVar_38117;
	cppVar_38118 = (cppVar_38118 & cppMask_un_8_);
	bool cppVar_38120 = (cppVar_38118 == 136);
	if (cppVar_38120) {
	cppVar_38115 = TCON;
	} else {
	BIT_VEC cppVar_38121;
	BIT_VEC cppVar_38122 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38123 = (cppVar_38122 << 3) | 6;
	cppVar_38123 = (cppVar_38123 & cppMask_un_5_);
	BIT_VEC cppVar_38124 = (0 << 5) | cppVar_38123;
	cppVar_38124 = (cppVar_38124 & cppMask_un_8_);
	bool cppVar_38126 = (cppVar_38124 == 137);
	if (cppVar_38126) {
	cppVar_38121 = TMOD;
	} else {
	BIT_VEC cppVar_38127;
	BIT_VEC cppVar_38128 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38129 = (cppVar_38128 << 3) | 6;
	cppVar_38129 = (cppVar_38129 & cppMask_un_5_);
	BIT_VEC cppVar_38130 = (0 << 5) | cppVar_38129;
	cppVar_38130 = (cppVar_38130 & cppMask_un_8_);
	bool cppVar_38132 = (cppVar_38130 == 138);
	if (cppVar_38132) {
	cppVar_38127 = TL0;
	} else {
	BIT_VEC cppVar_38133;
	BIT_VEC cppVar_38134 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38135 = (cppVar_38134 << 3) | 6;
	cppVar_38135 = (cppVar_38135 & cppMask_un_5_);
	BIT_VEC cppVar_38136 = (0 << 5) | cppVar_38135;
	cppVar_38136 = (cppVar_38136 & cppMask_un_8_);
	bool cppVar_38138 = (cppVar_38136 == 140);
	if (cppVar_38138) {
	cppVar_38133 = TH0;
	} else {
	BIT_VEC cppVar_38139;
	BIT_VEC cppVar_38140 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38141 = (cppVar_38140 << 3) | 6;
	cppVar_38141 = (cppVar_38141 & cppMask_un_5_);
	BIT_VEC cppVar_38142 = (0 << 5) | cppVar_38141;
	cppVar_38142 = (cppVar_38142 & cppMask_un_8_);
	bool cppVar_38144 = (cppVar_38142 == 139);
	if (cppVar_38144) {
	cppVar_38139 = TL1;
	} else {
	BIT_VEC cppVar_38145;
	BIT_VEC cppVar_38146 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38147 = (cppVar_38146 << 3) | 6;
	cppVar_38147 = (cppVar_38147 & cppMask_un_5_);
	BIT_VEC cppVar_38148 = (0 << 5) | cppVar_38147;
	cppVar_38148 = (cppVar_38148 & cppMask_un_8_);
	bool cppVar_38150 = (cppVar_38148 == 141);
	if (cppVar_38150) {
	cppVar_38145 = TH1;
	} else {
	BIT_VEC cppVar_38151;
	BIT_VEC cppVar_38152 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38153 = (cppVar_38152 << 3) | 6;
	cppVar_38153 = (cppVar_38153 & cppMask_un_5_);
	BIT_VEC cppVar_38154 = (0 << 5) | cppVar_38153;
	cppVar_38154 = (cppVar_38154 & cppMask_un_8_);
	bool cppVar_38156 = (cppVar_38154 == 144);
	if (cppVar_38156) {
	cppVar_38151 = P1;
	} else {
	BIT_VEC cppVar_38157;
	BIT_VEC cppVar_38158 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38159 = (cppVar_38158 << 3) | 6;
	cppVar_38159 = (cppVar_38159 & cppMask_un_5_);
	BIT_VEC cppVar_38160 = (0 << 5) | cppVar_38159;
	cppVar_38160 = (cppVar_38160 & cppMask_un_8_);
	bool cppVar_38162 = (cppVar_38160 == 152);
	if (cppVar_38162) {
	cppVar_38157 = SCON;
	} else {
	BIT_VEC cppVar_38163;
	BIT_VEC cppVar_38164 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38165 = (cppVar_38164 << 3) | 6;
	cppVar_38165 = (cppVar_38165 & cppMask_un_5_);
	BIT_VEC cppVar_38166 = (0 << 5) | cppVar_38165;
	cppVar_38166 = (cppVar_38166 & cppMask_un_8_);
	bool cppVar_38168 = (cppVar_38166 == 153);
	if (cppVar_38168) {
	cppVar_38163 = SBUF;
	} else {
	BIT_VEC cppVar_38169;
	BIT_VEC cppVar_38170 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38171 = (cppVar_38170 << 3) | 6;
	cppVar_38171 = (cppVar_38171 & cppMask_un_5_);
	BIT_VEC cppVar_38172 = (0 << 5) | cppVar_38171;
	cppVar_38172 = (cppVar_38172 & cppMask_un_8_);
	bool cppVar_38174 = (cppVar_38172 == 160);
	if (cppVar_38174) {
	cppVar_38169 = P2;
	} else {
	BIT_VEC cppVar_38175;
	BIT_VEC cppVar_38176 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38177 = (cppVar_38176 << 3) | 6;
	cppVar_38177 = (cppVar_38177 & cppMask_un_5_);
	BIT_VEC cppVar_38178 = (0 << 5) | cppVar_38177;
	cppVar_38178 = (cppVar_38178 & cppMask_un_8_);
	bool cppVar_38180 = (cppVar_38178 == 168);
	if (cppVar_38180) {
	cppVar_38175 = IE;
	} else {
	BIT_VEC cppVar_38181;
	BIT_VEC cppVar_38182 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38183 = (cppVar_38182 << 3) | 6;
	cppVar_38183 = (cppVar_38183 & cppMask_un_5_);
	BIT_VEC cppVar_38184 = (0 << 5) | cppVar_38183;
	cppVar_38184 = (cppVar_38184 & cppMask_un_8_);
	bool cppVar_38186 = (cppVar_38184 == 176);
	if (cppVar_38186) {
	cppVar_38181 = P3;
	} else {
	BIT_VEC cppVar_38187;
	BIT_VEC cppVar_38188 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38189 = (cppVar_38188 << 3) | 6;
	cppVar_38189 = (cppVar_38189 & cppMask_un_5_);
	BIT_VEC cppVar_38190 = (0 << 5) | cppVar_38189;
	cppVar_38190 = (cppVar_38190 & cppMask_un_8_);
	bool cppVar_38192 = (cppVar_38190 == 184);
	if (cppVar_38192) {
	cppVar_38187 = IP;
	} else {
	BIT_VEC cppVar_38193;
	BIT_VEC cppVar_38194 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38195 = (cppVar_38194 << 3) | 6;
	cppVar_38195 = (cppVar_38195 & cppMask_un_5_);
	BIT_VEC cppVar_38196 = (0 << 5) | cppVar_38195;
	cppVar_38196 = (cppVar_38196 & cppMask_un_8_);
	bool cppVar_38198 = (cppVar_38196 == 208);
	if (cppVar_38198) {
	cppVar_38193 = PSW;
	} else {
	BIT_VEC cppVar_38199;
	BIT_VEC cppVar_38200 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38201 = (cppVar_38200 << 3) | 6;
	cppVar_38201 = (cppVar_38201 & cppMask_un_5_);
	BIT_VEC cppVar_38202 = (0 << 5) | cppVar_38201;
	cppVar_38202 = (cppVar_38202 & cppMask_un_8_);
	bool cppVar_38204 = (cppVar_38202 == 224);
	if (cppVar_38204) {
	cppVar_38199 = ACC;
	} else {
	BIT_VEC cppVar_38205;
	BIT_VEC cppVar_38206 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38207 = (cppVar_38206 << 3) | 6;
	cppVar_38207 = (cppVar_38207 & cppMask_un_5_);
	BIT_VEC cppVar_38208 = (0 << 5) | cppVar_38207;
	cppVar_38208 = (cppVar_38208 & cppMask_un_8_);
	bool cppVar_38210 = (cppVar_38208 == 240);
	if (cppVar_38210) {
	cppVar_38205 = B;
	} else {
	cppVar_38205 = 0;
	}
	cppVar_38199 = cppVar_38205;
	}
	cppVar_38193 = cppVar_38199;
	}
	cppVar_38187 = cppVar_38193;
	}
	cppVar_38181 = cppVar_38187;
	}
	cppVar_38175 = cppVar_38181;
	}
	cppVar_38169 = cppVar_38175;
	}
	cppVar_38163 = cppVar_38169;
	}
	cppVar_38157 = cppVar_38163;
	}
	cppVar_38151 = cppVar_38157;
	}
	cppVar_38145 = cppVar_38151;
	}
	cppVar_38139 = cppVar_38145;
	}
	cppVar_38133 = cppVar_38139;
	}
	cppVar_38127 = cppVar_38133;
	}
	cppVar_38121 = cppVar_38127;
	}
	cppVar_38115 = cppVar_38121;
	}
	cppVar_38109 = cppVar_38115;
	}
	cppVar_38103 = cppVar_38109;
	}
	cppVar_38097 = cppVar_38103;
	}
	cppVar_38091 = cppVar_38097;
	}
	cppVar_38085 = cppVar_38091;
	}
	cppVar_38072 = cppVar_38085;
	}
	cppVar_38066 = cppVar_38072;
	} else {
	cppVar_38066 = P3;
	}
	cppVar_38062 = cppVar_38066;
	} else {
	BIT_VEC cppVar_38212;
	BIT_VEC cppVar_38213 = ROM.rd(PC);
	bool cppVar_38215 = (cppVar_38213 == 141);
	if (cppVar_38215) {
	BIT_VEC cppVar_38216;
	BIT_VEC cppVar_38218 = PC + 1;
	cppVar_38218 = (cppVar_38218 & cppMask_un_16_);
	BIT_VEC cppVar_38219 = ROM.rd(cppVar_38218);
	bool cppVar_38221 = (cppVar_38219 == 176);
	if (cppVar_38221) {
	BIT_VEC cppVar_38222;
	BIT_VEC cppVar_38224 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38226 = (cppVar_38224 << 3) | 5;
	cppVar_38226 = (cppVar_38226 & cppMask_un_5_);
	BIT_VEC cppVar_38227 = (0 << 5) | cppVar_38226;
	cppVar_38227 = (cppVar_38227 & cppMask_un_8_);
	BIT_VEC cppVar_38228 = (cppVar_38227 >> 7) & cppMask_un_1_;
	bool cppVar_38230 = (cppVar_38228 == 0);
	if (cppVar_38230) {
	BIT_VEC cppVar_38231 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38232 = (cppVar_38231 << 3) | 5;
	cppVar_38232 = (cppVar_38232 & cppMask_un_5_);
	BIT_VEC cppVar_38233 = (0 << 5) | cppVar_38232;
	cppVar_38233 = (cppVar_38233 & cppMask_un_8_);
	BIT_VEC cppVar_38234 = IRAM.rd(cppVar_38233);
	cppVar_38222 = cppVar_38234;
	} else {
	BIT_VEC cppVar_38235;
	BIT_VEC cppVar_38236 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38237 = (cppVar_38236 << 3) | 5;
	cppVar_38237 = (cppVar_38237 & cppMask_un_5_);
	BIT_VEC cppVar_38238 = (0 << 5) | cppVar_38237;
	cppVar_38238 = (cppVar_38238 & cppMask_un_8_);
	bool cppVar_38240 = (cppVar_38238 == 128);
	if (cppVar_38240) {
	cppVar_38235 = P0;
	} else {
	BIT_VEC cppVar_38241;
	BIT_VEC cppVar_38242 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38243 = (cppVar_38242 << 3) | 5;
	cppVar_38243 = (cppVar_38243 & cppMask_un_5_);
	BIT_VEC cppVar_38244 = (0 << 5) | cppVar_38243;
	cppVar_38244 = (cppVar_38244 & cppMask_un_8_);
	bool cppVar_38246 = (cppVar_38244 == 129);
	if (cppVar_38246) {
	cppVar_38241 = SP;
	} else {
	BIT_VEC cppVar_38247;
	BIT_VEC cppVar_38248 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38249 = (cppVar_38248 << 3) | 5;
	cppVar_38249 = (cppVar_38249 & cppMask_un_5_);
	BIT_VEC cppVar_38250 = (0 << 5) | cppVar_38249;
	cppVar_38250 = (cppVar_38250 & cppMask_un_8_);
	bool cppVar_38252 = (cppVar_38250 == 130);
	if (cppVar_38252) {
	cppVar_38247 = DPL;
	} else {
	BIT_VEC cppVar_38253;
	BIT_VEC cppVar_38254 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38255 = (cppVar_38254 << 3) | 5;
	cppVar_38255 = (cppVar_38255 & cppMask_un_5_);
	BIT_VEC cppVar_38256 = (0 << 5) | cppVar_38255;
	cppVar_38256 = (cppVar_38256 & cppMask_un_8_);
	bool cppVar_38258 = (cppVar_38256 == 131);
	if (cppVar_38258) {
	cppVar_38253 = DPH;
	} else {
	BIT_VEC cppVar_38259;
	BIT_VEC cppVar_38260 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38261 = (cppVar_38260 << 3) | 5;
	cppVar_38261 = (cppVar_38261 & cppMask_un_5_);
	BIT_VEC cppVar_38262 = (0 << 5) | cppVar_38261;
	cppVar_38262 = (cppVar_38262 & cppMask_un_8_);
	bool cppVar_38264 = (cppVar_38262 == 135);
	if (cppVar_38264) {
	cppVar_38259 = PCON;
	} else {
	BIT_VEC cppVar_38265;
	BIT_VEC cppVar_38266 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38267 = (cppVar_38266 << 3) | 5;
	cppVar_38267 = (cppVar_38267 & cppMask_un_5_);
	BIT_VEC cppVar_38268 = (0 << 5) | cppVar_38267;
	cppVar_38268 = (cppVar_38268 & cppMask_un_8_);
	bool cppVar_38270 = (cppVar_38268 == 136);
	if (cppVar_38270) {
	cppVar_38265 = TCON;
	} else {
	BIT_VEC cppVar_38271;
	BIT_VEC cppVar_38272 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38273 = (cppVar_38272 << 3) | 5;
	cppVar_38273 = (cppVar_38273 & cppMask_un_5_);
	BIT_VEC cppVar_38274 = (0 << 5) | cppVar_38273;
	cppVar_38274 = (cppVar_38274 & cppMask_un_8_);
	bool cppVar_38276 = (cppVar_38274 == 137);
	if (cppVar_38276) {
	cppVar_38271 = TMOD;
	} else {
	BIT_VEC cppVar_38277;
	BIT_VEC cppVar_38278 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38279 = (cppVar_38278 << 3) | 5;
	cppVar_38279 = (cppVar_38279 & cppMask_un_5_);
	BIT_VEC cppVar_38280 = (0 << 5) | cppVar_38279;
	cppVar_38280 = (cppVar_38280 & cppMask_un_8_);
	bool cppVar_38282 = (cppVar_38280 == 138);
	if (cppVar_38282) {
	cppVar_38277 = TL0;
	} else {
	BIT_VEC cppVar_38283;
	BIT_VEC cppVar_38284 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38285 = (cppVar_38284 << 3) | 5;
	cppVar_38285 = (cppVar_38285 & cppMask_un_5_);
	BIT_VEC cppVar_38286 = (0 << 5) | cppVar_38285;
	cppVar_38286 = (cppVar_38286 & cppMask_un_8_);
	bool cppVar_38288 = (cppVar_38286 == 140);
	if (cppVar_38288) {
	cppVar_38283 = TH0;
	} else {
	BIT_VEC cppVar_38289;
	BIT_VEC cppVar_38290 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38291 = (cppVar_38290 << 3) | 5;
	cppVar_38291 = (cppVar_38291 & cppMask_un_5_);
	BIT_VEC cppVar_38292 = (0 << 5) | cppVar_38291;
	cppVar_38292 = (cppVar_38292 & cppMask_un_8_);
	bool cppVar_38294 = (cppVar_38292 == 139);
	if (cppVar_38294) {
	cppVar_38289 = TL1;
	} else {
	BIT_VEC cppVar_38295;
	BIT_VEC cppVar_38296 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38297 = (cppVar_38296 << 3) | 5;
	cppVar_38297 = (cppVar_38297 & cppMask_un_5_);
	BIT_VEC cppVar_38298 = (0 << 5) | cppVar_38297;
	cppVar_38298 = (cppVar_38298 & cppMask_un_8_);
	bool cppVar_38300 = (cppVar_38298 == 141);
	if (cppVar_38300) {
	cppVar_38295 = TH1;
	} else {
	BIT_VEC cppVar_38301;
	BIT_VEC cppVar_38302 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38303 = (cppVar_38302 << 3) | 5;
	cppVar_38303 = (cppVar_38303 & cppMask_un_5_);
	BIT_VEC cppVar_38304 = (0 << 5) | cppVar_38303;
	cppVar_38304 = (cppVar_38304 & cppMask_un_8_);
	bool cppVar_38306 = (cppVar_38304 == 144);
	if (cppVar_38306) {
	cppVar_38301 = P1;
	} else {
	BIT_VEC cppVar_38307;
	BIT_VEC cppVar_38308 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38309 = (cppVar_38308 << 3) | 5;
	cppVar_38309 = (cppVar_38309 & cppMask_un_5_);
	BIT_VEC cppVar_38310 = (0 << 5) | cppVar_38309;
	cppVar_38310 = (cppVar_38310 & cppMask_un_8_);
	bool cppVar_38312 = (cppVar_38310 == 152);
	if (cppVar_38312) {
	cppVar_38307 = SCON;
	} else {
	BIT_VEC cppVar_38313;
	BIT_VEC cppVar_38314 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38315 = (cppVar_38314 << 3) | 5;
	cppVar_38315 = (cppVar_38315 & cppMask_un_5_);
	BIT_VEC cppVar_38316 = (0 << 5) | cppVar_38315;
	cppVar_38316 = (cppVar_38316 & cppMask_un_8_);
	bool cppVar_38318 = (cppVar_38316 == 153);
	if (cppVar_38318) {
	cppVar_38313 = SBUF;
	} else {
	BIT_VEC cppVar_38319;
	BIT_VEC cppVar_38320 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38321 = (cppVar_38320 << 3) | 5;
	cppVar_38321 = (cppVar_38321 & cppMask_un_5_);
	BIT_VEC cppVar_38322 = (0 << 5) | cppVar_38321;
	cppVar_38322 = (cppVar_38322 & cppMask_un_8_);
	bool cppVar_38324 = (cppVar_38322 == 160);
	if (cppVar_38324) {
	cppVar_38319 = P2;
	} else {
	BIT_VEC cppVar_38325;
	BIT_VEC cppVar_38326 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38327 = (cppVar_38326 << 3) | 5;
	cppVar_38327 = (cppVar_38327 & cppMask_un_5_);
	BIT_VEC cppVar_38328 = (0 << 5) | cppVar_38327;
	cppVar_38328 = (cppVar_38328 & cppMask_un_8_);
	bool cppVar_38330 = (cppVar_38328 == 168);
	if (cppVar_38330) {
	cppVar_38325 = IE;
	} else {
	BIT_VEC cppVar_38331;
	BIT_VEC cppVar_38332 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38333 = (cppVar_38332 << 3) | 5;
	cppVar_38333 = (cppVar_38333 & cppMask_un_5_);
	BIT_VEC cppVar_38334 = (0 << 5) | cppVar_38333;
	cppVar_38334 = (cppVar_38334 & cppMask_un_8_);
	bool cppVar_38336 = (cppVar_38334 == 176);
	if (cppVar_38336) {
	cppVar_38331 = P3;
	} else {
	BIT_VEC cppVar_38337;
	BIT_VEC cppVar_38338 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38339 = (cppVar_38338 << 3) | 5;
	cppVar_38339 = (cppVar_38339 & cppMask_un_5_);
	BIT_VEC cppVar_38340 = (0 << 5) | cppVar_38339;
	cppVar_38340 = (cppVar_38340 & cppMask_un_8_);
	bool cppVar_38342 = (cppVar_38340 == 184);
	if (cppVar_38342) {
	cppVar_38337 = IP;
	} else {
	BIT_VEC cppVar_38343;
	BIT_VEC cppVar_38344 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38345 = (cppVar_38344 << 3) | 5;
	cppVar_38345 = (cppVar_38345 & cppMask_un_5_);
	BIT_VEC cppVar_38346 = (0 << 5) | cppVar_38345;
	cppVar_38346 = (cppVar_38346 & cppMask_un_8_);
	bool cppVar_38348 = (cppVar_38346 == 208);
	if (cppVar_38348) {
	cppVar_38343 = PSW;
	} else {
	BIT_VEC cppVar_38349;
	BIT_VEC cppVar_38350 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38351 = (cppVar_38350 << 3) | 5;
	cppVar_38351 = (cppVar_38351 & cppMask_un_5_);
	BIT_VEC cppVar_38352 = (0 << 5) | cppVar_38351;
	cppVar_38352 = (cppVar_38352 & cppMask_un_8_);
	bool cppVar_38354 = (cppVar_38352 == 224);
	if (cppVar_38354) {
	cppVar_38349 = ACC;
	} else {
	BIT_VEC cppVar_38355;
	BIT_VEC cppVar_38356 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38357 = (cppVar_38356 << 3) | 5;
	cppVar_38357 = (cppVar_38357 & cppMask_un_5_);
	BIT_VEC cppVar_38358 = (0 << 5) | cppVar_38357;
	cppVar_38358 = (cppVar_38358 & cppMask_un_8_);
	bool cppVar_38360 = (cppVar_38358 == 240);
	if (cppVar_38360) {
	cppVar_38355 = B;
	} else {
	cppVar_38355 = 0;
	}
	cppVar_38349 = cppVar_38355;
	}
	cppVar_38343 = cppVar_38349;
	}
	cppVar_38337 = cppVar_38343;
	}
	cppVar_38331 = cppVar_38337;
	}
	cppVar_38325 = cppVar_38331;
	}
	cppVar_38319 = cppVar_38325;
	}
	cppVar_38313 = cppVar_38319;
	}
	cppVar_38307 = cppVar_38313;
	}
	cppVar_38301 = cppVar_38307;
	}
	cppVar_38295 = cppVar_38301;
	}
	cppVar_38289 = cppVar_38295;
	}
	cppVar_38283 = cppVar_38289;
	}
	cppVar_38277 = cppVar_38283;
	}
	cppVar_38271 = cppVar_38277;
	}
	cppVar_38265 = cppVar_38271;
	}
	cppVar_38259 = cppVar_38265;
	}
	cppVar_38253 = cppVar_38259;
	}
	cppVar_38247 = cppVar_38253;
	}
	cppVar_38241 = cppVar_38247;
	}
	cppVar_38235 = cppVar_38241;
	}
	cppVar_38222 = cppVar_38235;
	}
	cppVar_38216 = cppVar_38222;
	} else {
	cppVar_38216 = P3;
	}
	cppVar_38212 = cppVar_38216;
	} else {
	BIT_VEC cppVar_38362;
	BIT_VEC cppVar_38363 = ROM.rd(PC);
	bool cppVar_38365 = (cppVar_38363 == 140);
	if (cppVar_38365) {
	BIT_VEC cppVar_38366;
	BIT_VEC cppVar_38368 = PC + 1;
	cppVar_38368 = (cppVar_38368 & cppMask_un_16_);
	BIT_VEC cppVar_38369 = ROM.rd(cppVar_38368);
	bool cppVar_38371 = (cppVar_38369 == 176);
	if (cppVar_38371) {
	BIT_VEC cppVar_38372;
	BIT_VEC cppVar_38374 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38376 = (cppVar_38374 << 3) | 4;
	cppVar_38376 = (cppVar_38376 & cppMask_un_5_);
	BIT_VEC cppVar_38377 = (0 << 5) | cppVar_38376;
	cppVar_38377 = (cppVar_38377 & cppMask_un_8_);
	BIT_VEC cppVar_38378 = (cppVar_38377 >> 7) & cppMask_un_1_;
	bool cppVar_38380 = (cppVar_38378 == 0);
	if (cppVar_38380) {
	BIT_VEC cppVar_38381 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38382 = (cppVar_38381 << 3) | 4;
	cppVar_38382 = (cppVar_38382 & cppMask_un_5_);
	BIT_VEC cppVar_38383 = (0 << 5) | cppVar_38382;
	cppVar_38383 = (cppVar_38383 & cppMask_un_8_);
	BIT_VEC cppVar_38384 = IRAM.rd(cppVar_38383);
	cppVar_38372 = cppVar_38384;
	} else {
	BIT_VEC cppVar_38385;
	BIT_VEC cppVar_38386 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38387 = (cppVar_38386 << 3) | 4;
	cppVar_38387 = (cppVar_38387 & cppMask_un_5_);
	BIT_VEC cppVar_38388 = (0 << 5) | cppVar_38387;
	cppVar_38388 = (cppVar_38388 & cppMask_un_8_);
	bool cppVar_38390 = (cppVar_38388 == 128);
	if (cppVar_38390) {
	cppVar_38385 = P0;
	} else {
	BIT_VEC cppVar_38391;
	BIT_VEC cppVar_38392 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38393 = (cppVar_38392 << 3) | 4;
	cppVar_38393 = (cppVar_38393 & cppMask_un_5_);
	BIT_VEC cppVar_38394 = (0 << 5) | cppVar_38393;
	cppVar_38394 = (cppVar_38394 & cppMask_un_8_);
	bool cppVar_38396 = (cppVar_38394 == 129);
	if (cppVar_38396) {
	cppVar_38391 = SP;
	} else {
	BIT_VEC cppVar_38397;
	BIT_VEC cppVar_38398 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38399 = (cppVar_38398 << 3) | 4;
	cppVar_38399 = (cppVar_38399 & cppMask_un_5_);
	BIT_VEC cppVar_38400 = (0 << 5) | cppVar_38399;
	cppVar_38400 = (cppVar_38400 & cppMask_un_8_);
	bool cppVar_38402 = (cppVar_38400 == 130);
	if (cppVar_38402) {
	cppVar_38397 = DPL;
	} else {
	BIT_VEC cppVar_38403;
	BIT_VEC cppVar_38404 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38405 = (cppVar_38404 << 3) | 4;
	cppVar_38405 = (cppVar_38405 & cppMask_un_5_);
	BIT_VEC cppVar_38406 = (0 << 5) | cppVar_38405;
	cppVar_38406 = (cppVar_38406 & cppMask_un_8_);
	bool cppVar_38408 = (cppVar_38406 == 131);
	if (cppVar_38408) {
	cppVar_38403 = DPH;
	} else {
	BIT_VEC cppVar_38409;
	BIT_VEC cppVar_38410 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38411 = (cppVar_38410 << 3) | 4;
	cppVar_38411 = (cppVar_38411 & cppMask_un_5_);
	BIT_VEC cppVar_38412 = (0 << 5) | cppVar_38411;
	cppVar_38412 = (cppVar_38412 & cppMask_un_8_);
	bool cppVar_38414 = (cppVar_38412 == 135);
	if (cppVar_38414) {
	cppVar_38409 = PCON;
	} else {
	BIT_VEC cppVar_38415;
	BIT_VEC cppVar_38416 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38417 = (cppVar_38416 << 3) | 4;
	cppVar_38417 = (cppVar_38417 & cppMask_un_5_);
	BIT_VEC cppVar_38418 = (0 << 5) | cppVar_38417;
	cppVar_38418 = (cppVar_38418 & cppMask_un_8_);
	bool cppVar_38420 = (cppVar_38418 == 136);
	if (cppVar_38420) {
	cppVar_38415 = TCON;
	} else {
	BIT_VEC cppVar_38421;
	BIT_VEC cppVar_38422 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38423 = (cppVar_38422 << 3) | 4;
	cppVar_38423 = (cppVar_38423 & cppMask_un_5_);
	BIT_VEC cppVar_38424 = (0 << 5) | cppVar_38423;
	cppVar_38424 = (cppVar_38424 & cppMask_un_8_);
	bool cppVar_38426 = (cppVar_38424 == 137);
	if (cppVar_38426) {
	cppVar_38421 = TMOD;
	} else {
	BIT_VEC cppVar_38427;
	BIT_VEC cppVar_38428 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38429 = (cppVar_38428 << 3) | 4;
	cppVar_38429 = (cppVar_38429 & cppMask_un_5_);
	BIT_VEC cppVar_38430 = (0 << 5) | cppVar_38429;
	cppVar_38430 = (cppVar_38430 & cppMask_un_8_);
	bool cppVar_38432 = (cppVar_38430 == 138);
	if (cppVar_38432) {
	cppVar_38427 = TL0;
	} else {
	BIT_VEC cppVar_38433;
	BIT_VEC cppVar_38434 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38435 = (cppVar_38434 << 3) | 4;
	cppVar_38435 = (cppVar_38435 & cppMask_un_5_);
	BIT_VEC cppVar_38436 = (0 << 5) | cppVar_38435;
	cppVar_38436 = (cppVar_38436 & cppMask_un_8_);
	bool cppVar_38438 = (cppVar_38436 == 140);
	if (cppVar_38438) {
	cppVar_38433 = TH0;
	} else {
	BIT_VEC cppVar_38439;
	BIT_VEC cppVar_38440 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38441 = (cppVar_38440 << 3) | 4;
	cppVar_38441 = (cppVar_38441 & cppMask_un_5_);
	BIT_VEC cppVar_38442 = (0 << 5) | cppVar_38441;
	cppVar_38442 = (cppVar_38442 & cppMask_un_8_);
	bool cppVar_38444 = (cppVar_38442 == 139);
	if (cppVar_38444) {
	cppVar_38439 = TL1;
	} else {
	BIT_VEC cppVar_38445;
	BIT_VEC cppVar_38446 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38447 = (cppVar_38446 << 3) | 4;
	cppVar_38447 = (cppVar_38447 & cppMask_un_5_);
	BIT_VEC cppVar_38448 = (0 << 5) | cppVar_38447;
	cppVar_38448 = (cppVar_38448 & cppMask_un_8_);
	bool cppVar_38450 = (cppVar_38448 == 141);
	if (cppVar_38450) {
	cppVar_38445 = TH1;
	} else {
	BIT_VEC cppVar_38451;
	BIT_VEC cppVar_38452 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38453 = (cppVar_38452 << 3) | 4;
	cppVar_38453 = (cppVar_38453 & cppMask_un_5_);
	BIT_VEC cppVar_38454 = (0 << 5) | cppVar_38453;
	cppVar_38454 = (cppVar_38454 & cppMask_un_8_);
	bool cppVar_38456 = (cppVar_38454 == 144);
	if (cppVar_38456) {
	cppVar_38451 = P1;
	} else {
	BIT_VEC cppVar_38457;
	BIT_VEC cppVar_38458 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38459 = (cppVar_38458 << 3) | 4;
	cppVar_38459 = (cppVar_38459 & cppMask_un_5_);
	BIT_VEC cppVar_38460 = (0 << 5) | cppVar_38459;
	cppVar_38460 = (cppVar_38460 & cppMask_un_8_);
	bool cppVar_38462 = (cppVar_38460 == 152);
	if (cppVar_38462) {
	cppVar_38457 = SCON;
	} else {
	BIT_VEC cppVar_38463;
	BIT_VEC cppVar_38464 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38465 = (cppVar_38464 << 3) | 4;
	cppVar_38465 = (cppVar_38465 & cppMask_un_5_);
	BIT_VEC cppVar_38466 = (0 << 5) | cppVar_38465;
	cppVar_38466 = (cppVar_38466 & cppMask_un_8_);
	bool cppVar_38468 = (cppVar_38466 == 153);
	if (cppVar_38468) {
	cppVar_38463 = SBUF;
	} else {
	BIT_VEC cppVar_38469;
	BIT_VEC cppVar_38470 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38471 = (cppVar_38470 << 3) | 4;
	cppVar_38471 = (cppVar_38471 & cppMask_un_5_);
	BIT_VEC cppVar_38472 = (0 << 5) | cppVar_38471;
	cppVar_38472 = (cppVar_38472 & cppMask_un_8_);
	bool cppVar_38474 = (cppVar_38472 == 160);
	if (cppVar_38474) {
	cppVar_38469 = P2;
	} else {
	BIT_VEC cppVar_38475;
	BIT_VEC cppVar_38476 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38477 = (cppVar_38476 << 3) | 4;
	cppVar_38477 = (cppVar_38477 & cppMask_un_5_);
	BIT_VEC cppVar_38478 = (0 << 5) | cppVar_38477;
	cppVar_38478 = (cppVar_38478 & cppMask_un_8_);
	bool cppVar_38480 = (cppVar_38478 == 168);
	if (cppVar_38480) {
	cppVar_38475 = IE;
	} else {
	BIT_VEC cppVar_38481;
	BIT_VEC cppVar_38482 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38483 = (cppVar_38482 << 3) | 4;
	cppVar_38483 = (cppVar_38483 & cppMask_un_5_);
	BIT_VEC cppVar_38484 = (0 << 5) | cppVar_38483;
	cppVar_38484 = (cppVar_38484 & cppMask_un_8_);
	bool cppVar_38486 = (cppVar_38484 == 176);
	if (cppVar_38486) {
	cppVar_38481 = P3;
	} else {
	BIT_VEC cppVar_38487;
	BIT_VEC cppVar_38488 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38489 = (cppVar_38488 << 3) | 4;
	cppVar_38489 = (cppVar_38489 & cppMask_un_5_);
	BIT_VEC cppVar_38490 = (0 << 5) | cppVar_38489;
	cppVar_38490 = (cppVar_38490 & cppMask_un_8_);
	bool cppVar_38492 = (cppVar_38490 == 184);
	if (cppVar_38492) {
	cppVar_38487 = IP;
	} else {
	BIT_VEC cppVar_38493;
	BIT_VEC cppVar_38494 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38495 = (cppVar_38494 << 3) | 4;
	cppVar_38495 = (cppVar_38495 & cppMask_un_5_);
	BIT_VEC cppVar_38496 = (0 << 5) | cppVar_38495;
	cppVar_38496 = (cppVar_38496 & cppMask_un_8_);
	bool cppVar_38498 = (cppVar_38496 == 208);
	if (cppVar_38498) {
	cppVar_38493 = PSW;
	} else {
	BIT_VEC cppVar_38499;
	BIT_VEC cppVar_38500 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38501 = (cppVar_38500 << 3) | 4;
	cppVar_38501 = (cppVar_38501 & cppMask_un_5_);
	BIT_VEC cppVar_38502 = (0 << 5) | cppVar_38501;
	cppVar_38502 = (cppVar_38502 & cppMask_un_8_);
	bool cppVar_38504 = (cppVar_38502 == 224);
	if (cppVar_38504) {
	cppVar_38499 = ACC;
	} else {
	BIT_VEC cppVar_38505;
	BIT_VEC cppVar_38506 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38507 = (cppVar_38506 << 3) | 4;
	cppVar_38507 = (cppVar_38507 & cppMask_un_5_);
	BIT_VEC cppVar_38508 = (0 << 5) | cppVar_38507;
	cppVar_38508 = (cppVar_38508 & cppMask_un_8_);
	bool cppVar_38510 = (cppVar_38508 == 240);
	if (cppVar_38510) {
	cppVar_38505 = B;
	} else {
	cppVar_38505 = 0;
	}
	cppVar_38499 = cppVar_38505;
	}
	cppVar_38493 = cppVar_38499;
	}
	cppVar_38487 = cppVar_38493;
	}
	cppVar_38481 = cppVar_38487;
	}
	cppVar_38475 = cppVar_38481;
	}
	cppVar_38469 = cppVar_38475;
	}
	cppVar_38463 = cppVar_38469;
	}
	cppVar_38457 = cppVar_38463;
	}
	cppVar_38451 = cppVar_38457;
	}
	cppVar_38445 = cppVar_38451;
	}
	cppVar_38439 = cppVar_38445;
	}
	cppVar_38433 = cppVar_38439;
	}
	cppVar_38427 = cppVar_38433;
	}
	cppVar_38421 = cppVar_38427;
	}
	cppVar_38415 = cppVar_38421;
	}
	cppVar_38409 = cppVar_38415;
	}
	cppVar_38403 = cppVar_38409;
	}
	cppVar_38397 = cppVar_38403;
	}
	cppVar_38391 = cppVar_38397;
	}
	cppVar_38385 = cppVar_38391;
	}
	cppVar_38372 = cppVar_38385;
	}
	cppVar_38366 = cppVar_38372;
	} else {
	cppVar_38366 = P3;
	}
	cppVar_38362 = cppVar_38366;
	} else {
	BIT_VEC cppVar_38512;
	BIT_VEC cppVar_38513 = ROM.rd(PC);
	bool cppVar_38515 = (cppVar_38513 == 139);
	if (cppVar_38515) {
	BIT_VEC cppVar_38516;
	BIT_VEC cppVar_38518 = PC + 1;
	cppVar_38518 = (cppVar_38518 & cppMask_un_16_);
	BIT_VEC cppVar_38519 = ROM.rd(cppVar_38518);
	bool cppVar_38521 = (cppVar_38519 == 176);
	if (cppVar_38521) {
	BIT_VEC cppVar_38522;
	BIT_VEC cppVar_38524 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38526 = (cppVar_38524 << 3) | 3;
	cppVar_38526 = (cppVar_38526 & cppMask_un_5_);
	BIT_VEC cppVar_38527 = (0 << 5) | cppVar_38526;
	cppVar_38527 = (cppVar_38527 & cppMask_un_8_);
	BIT_VEC cppVar_38528 = (cppVar_38527 >> 7) & cppMask_un_1_;
	bool cppVar_38530 = (cppVar_38528 == 0);
	if (cppVar_38530) {
	BIT_VEC cppVar_38531 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38532 = (cppVar_38531 << 3) | 3;
	cppVar_38532 = (cppVar_38532 & cppMask_un_5_);
	BIT_VEC cppVar_38533 = (0 << 5) | cppVar_38532;
	cppVar_38533 = (cppVar_38533 & cppMask_un_8_);
	BIT_VEC cppVar_38534 = IRAM.rd(cppVar_38533);
	cppVar_38522 = cppVar_38534;
	} else {
	BIT_VEC cppVar_38535;
	BIT_VEC cppVar_38536 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38537 = (cppVar_38536 << 3) | 3;
	cppVar_38537 = (cppVar_38537 & cppMask_un_5_);
	BIT_VEC cppVar_38538 = (0 << 5) | cppVar_38537;
	cppVar_38538 = (cppVar_38538 & cppMask_un_8_);
	bool cppVar_38540 = (cppVar_38538 == 128);
	if (cppVar_38540) {
	cppVar_38535 = P0;
	} else {
	BIT_VEC cppVar_38541;
	BIT_VEC cppVar_38542 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38543 = (cppVar_38542 << 3) | 3;
	cppVar_38543 = (cppVar_38543 & cppMask_un_5_);
	BIT_VEC cppVar_38544 = (0 << 5) | cppVar_38543;
	cppVar_38544 = (cppVar_38544 & cppMask_un_8_);
	bool cppVar_38546 = (cppVar_38544 == 129);
	if (cppVar_38546) {
	cppVar_38541 = SP;
	} else {
	BIT_VEC cppVar_38547;
	BIT_VEC cppVar_38548 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38549 = (cppVar_38548 << 3) | 3;
	cppVar_38549 = (cppVar_38549 & cppMask_un_5_);
	BIT_VEC cppVar_38550 = (0 << 5) | cppVar_38549;
	cppVar_38550 = (cppVar_38550 & cppMask_un_8_);
	bool cppVar_38552 = (cppVar_38550 == 130);
	if (cppVar_38552) {
	cppVar_38547 = DPL;
	} else {
	BIT_VEC cppVar_38553;
	BIT_VEC cppVar_38554 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38555 = (cppVar_38554 << 3) | 3;
	cppVar_38555 = (cppVar_38555 & cppMask_un_5_);
	BIT_VEC cppVar_38556 = (0 << 5) | cppVar_38555;
	cppVar_38556 = (cppVar_38556 & cppMask_un_8_);
	bool cppVar_38558 = (cppVar_38556 == 131);
	if (cppVar_38558) {
	cppVar_38553 = DPH;
	} else {
	BIT_VEC cppVar_38559;
	BIT_VEC cppVar_38560 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38561 = (cppVar_38560 << 3) | 3;
	cppVar_38561 = (cppVar_38561 & cppMask_un_5_);
	BIT_VEC cppVar_38562 = (0 << 5) | cppVar_38561;
	cppVar_38562 = (cppVar_38562 & cppMask_un_8_);
	bool cppVar_38564 = (cppVar_38562 == 135);
	if (cppVar_38564) {
	cppVar_38559 = PCON;
	} else {
	BIT_VEC cppVar_38565;
	BIT_VEC cppVar_38566 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38567 = (cppVar_38566 << 3) | 3;
	cppVar_38567 = (cppVar_38567 & cppMask_un_5_);
	BIT_VEC cppVar_38568 = (0 << 5) | cppVar_38567;
	cppVar_38568 = (cppVar_38568 & cppMask_un_8_);
	bool cppVar_38570 = (cppVar_38568 == 136);
	if (cppVar_38570) {
	cppVar_38565 = TCON;
	} else {
	BIT_VEC cppVar_38571;
	BIT_VEC cppVar_38572 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38573 = (cppVar_38572 << 3) | 3;
	cppVar_38573 = (cppVar_38573 & cppMask_un_5_);
	BIT_VEC cppVar_38574 = (0 << 5) | cppVar_38573;
	cppVar_38574 = (cppVar_38574 & cppMask_un_8_);
	bool cppVar_38576 = (cppVar_38574 == 137);
	if (cppVar_38576) {
	cppVar_38571 = TMOD;
	} else {
	BIT_VEC cppVar_38577;
	BIT_VEC cppVar_38578 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38579 = (cppVar_38578 << 3) | 3;
	cppVar_38579 = (cppVar_38579 & cppMask_un_5_);
	BIT_VEC cppVar_38580 = (0 << 5) | cppVar_38579;
	cppVar_38580 = (cppVar_38580 & cppMask_un_8_);
	bool cppVar_38582 = (cppVar_38580 == 138);
	if (cppVar_38582) {
	cppVar_38577 = TL0;
	} else {
	BIT_VEC cppVar_38583;
	BIT_VEC cppVar_38584 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38585 = (cppVar_38584 << 3) | 3;
	cppVar_38585 = (cppVar_38585 & cppMask_un_5_);
	BIT_VEC cppVar_38586 = (0 << 5) | cppVar_38585;
	cppVar_38586 = (cppVar_38586 & cppMask_un_8_);
	bool cppVar_38588 = (cppVar_38586 == 140);
	if (cppVar_38588) {
	cppVar_38583 = TH0;
	} else {
	BIT_VEC cppVar_38589;
	BIT_VEC cppVar_38590 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38591 = (cppVar_38590 << 3) | 3;
	cppVar_38591 = (cppVar_38591 & cppMask_un_5_);
	BIT_VEC cppVar_38592 = (0 << 5) | cppVar_38591;
	cppVar_38592 = (cppVar_38592 & cppMask_un_8_);
	bool cppVar_38594 = (cppVar_38592 == 139);
	if (cppVar_38594) {
	cppVar_38589 = TL1;
	} else {
	BIT_VEC cppVar_38595;
	BIT_VEC cppVar_38596 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38597 = (cppVar_38596 << 3) | 3;
	cppVar_38597 = (cppVar_38597 & cppMask_un_5_);
	BIT_VEC cppVar_38598 = (0 << 5) | cppVar_38597;
	cppVar_38598 = (cppVar_38598 & cppMask_un_8_);
	bool cppVar_38600 = (cppVar_38598 == 141);
	if (cppVar_38600) {
	cppVar_38595 = TH1;
	} else {
	BIT_VEC cppVar_38601;
	BIT_VEC cppVar_38602 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38603 = (cppVar_38602 << 3) | 3;
	cppVar_38603 = (cppVar_38603 & cppMask_un_5_);
	BIT_VEC cppVar_38604 = (0 << 5) | cppVar_38603;
	cppVar_38604 = (cppVar_38604 & cppMask_un_8_);
	bool cppVar_38606 = (cppVar_38604 == 144);
	if (cppVar_38606) {
	cppVar_38601 = P1;
	} else {
	BIT_VEC cppVar_38607;
	BIT_VEC cppVar_38608 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38609 = (cppVar_38608 << 3) | 3;
	cppVar_38609 = (cppVar_38609 & cppMask_un_5_);
	BIT_VEC cppVar_38610 = (0 << 5) | cppVar_38609;
	cppVar_38610 = (cppVar_38610 & cppMask_un_8_);
	bool cppVar_38612 = (cppVar_38610 == 152);
	if (cppVar_38612) {
	cppVar_38607 = SCON;
	} else {
	BIT_VEC cppVar_38613;
	BIT_VEC cppVar_38614 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38615 = (cppVar_38614 << 3) | 3;
	cppVar_38615 = (cppVar_38615 & cppMask_un_5_);
	BIT_VEC cppVar_38616 = (0 << 5) | cppVar_38615;
	cppVar_38616 = (cppVar_38616 & cppMask_un_8_);
	bool cppVar_38618 = (cppVar_38616 == 153);
	if (cppVar_38618) {
	cppVar_38613 = SBUF;
	} else {
	BIT_VEC cppVar_38619;
	BIT_VEC cppVar_38620 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38621 = (cppVar_38620 << 3) | 3;
	cppVar_38621 = (cppVar_38621 & cppMask_un_5_);
	BIT_VEC cppVar_38622 = (0 << 5) | cppVar_38621;
	cppVar_38622 = (cppVar_38622 & cppMask_un_8_);
	bool cppVar_38624 = (cppVar_38622 == 160);
	if (cppVar_38624) {
	cppVar_38619 = P2;
	} else {
	BIT_VEC cppVar_38625;
	BIT_VEC cppVar_38626 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38627 = (cppVar_38626 << 3) | 3;
	cppVar_38627 = (cppVar_38627 & cppMask_un_5_);
	BIT_VEC cppVar_38628 = (0 << 5) | cppVar_38627;
	cppVar_38628 = (cppVar_38628 & cppMask_un_8_);
	bool cppVar_38630 = (cppVar_38628 == 168);
	if (cppVar_38630) {
	cppVar_38625 = IE;
	} else {
	BIT_VEC cppVar_38631;
	BIT_VEC cppVar_38632 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38633 = (cppVar_38632 << 3) | 3;
	cppVar_38633 = (cppVar_38633 & cppMask_un_5_);
	BIT_VEC cppVar_38634 = (0 << 5) | cppVar_38633;
	cppVar_38634 = (cppVar_38634 & cppMask_un_8_);
	bool cppVar_38636 = (cppVar_38634 == 176);
	if (cppVar_38636) {
	cppVar_38631 = P3;
	} else {
	BIT_VEC cppVar_38637;
	BIT_VEC cppVar_38638 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38639 = (cppVar_38638 << 3) | 3;
	cppVar_38639 = (cppVar_38639 & cppMask_un_5_);
	BIT_VEC cppVar_38640 = (0 << 5) | cppVar_38639;
	cppVar_38640 = (cppVar_38640 & cppMask_un_8_);
	bool cppVar_38642 = (cppVar_38640 == 184);
	if (cppVar_38642) {
	cppVar_38637 = IP;
	} else {
	BIT_VEC cppVar_38643;
	BIT_VEC cppVar_38644 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38645 = (cppVar_38644 << 3) | 3;
	cppVar_38645 = (cppVar_38645 & cppMask_un_5_);
	BIT_VEC cppVar_38646 = (0 << 5) | cppVar_38645;
	cppVar_38646 = (cppVar_38646 & cppMask_un_8_);
	bool cppVar_38648 = (cppVar_38646 == 208);
	if (cppVar_38648) {
	cppVar_38643 = PSW;
	} else {
	BIT_VEC cppVar_38649;
	BIT_VEC cppVar_38650 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38651 = (cppVar_38650 << 3) | 3;
	cppVar_38651 = (cppVar_38651 & cppMask_un_5_);
	BIT_VEC cppVar_38652 = (0 << 5) | cppVar_38651;
	cppVar_38652 = (cppVar_38652 & cppMask_un_8_);
	bool cppVar_38654 = (cppVar_38652 == 224);
	if (cppVar_38654) {
	cppVar_38649 = ACC;
	} else {
	BIT_VEC cppVar_38655;
	BIT_VEC cppVar_38656 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38657 = (cppVar_38656 << 3) | 3;
	cppVar_38657 = (cppVar_38657 & cppMask_un_5_);
	BIT_VEC cppVar_38658 = (0 << 5) | cppVar_38657;
	cppVar_38658 = (cppVar_38658 & cppMask_un_8_);
	bool cppVar_38660 = (cppVar_38658 == 240);
	if (cppVar_38660) {
	cppVar_38655 = B;
	} else {
	cppVar_38655 = 0;
	}
	cppVar_38649 = cppVar_38655;
	}
	cppVar_38643 = cppVar_38649;
	}
	cppVar_38637 = cppVar_38643;
	}
	cppVar_38631 = cppVar_38637;
	}
	cppVar_38625 = cppVar_38631;
	}
	cppVar_38619 = cppVar_38625;
	}
	cppVar_38613 = cppVar_38619;
	}
	cppVar_38607 = cppVar_38613;
	}
	cppVar_38601 = cppVar_38607;
	}
	cppVar_38595 = cppVar_38601;
	}
	cppVar_38589 = cppVar_38595;
	}
	cppVar_38583 = cppVar_38589;
	}
	cppVar_38577 = cppVar_38583;
	}
	cppVar_38571 = cppVar_38577;
	}
	cppVar_38565 = cppVar_38571;
	}
	cppVar_38559 = cppVar_38565;
	}
	cppVar_38553 = cppVar_38559;
	}
	cppVar_38547 = cppVar_38553;
	}
	cppVar_38541 = cppVar_38547;
	}
	cppVar_38535 = cppVar_38541;
	}
	cppVar_38522 = cppVar_38535;
	}
	cppVar_38516 = cppVar_38522;
	} else {
	cppVar_38516 = P3;
	}
	cppVar_38512 = cppVar_38516;
	} else {
	BIT_VEC cppVar_38662;
	BIT_VEC cppVar_38663 = ROM.rd(PC);
	bool cppVar_38665 = (cppVar_38663 == 138);
	if (cppVar_38665) {
	BIT_VEC cppVar_38666;
	BIT_VEC cppVar_38668 = PC + 1;
	cppVar_38668 = (cppVar_38668 & cppMask_un_16_);
	BIT_VEC cppVar_38669 = ROM.rd(cppVar_38668);
	bool cppVar_38671 = (cppVar_38669 == 176);
	if (cppVar_38671) {
	BIT_VEC cppVar_38672;
	BIT_VEC cppVar_38674 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38676 = (cppVar_38674 << 3) | 2;
	cppVar_38676 = (cppVar_38676 & cppMask_un_5_);
	BIT_VEC cppVar_38677 = (0 << 5) | cppVar_38676;
	cppVar_38677 = (cppVar_38677 & cppMask_un_8_);
	BIT_VEC cppVar_38678 = (cppVar_38677 >> 7) & cppMask_un_1_;
	bool cppVar_38680 = (cppVar_38678 == 0);
	if (cppVar_38680) {
	BIT_VEC cppVar_38681 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38682 = (cppVar_38681 << 3) | 2;
	cppVar_38682 = (cppVar_38682 & cppMask_un_5_);
	BIT_VEC cppVar_38683 = (0 << 5) | cppVar_38682;
	cppVar_38683 = (cppVar_38683 & cppMask_un_8_);
	BIT_VEC cppVar_38684 = IRAM.rd(cppVar_38683);
	cppVar_38672 = cppVar_38684;
	} else {
	BIT_VEC cppVar_38685;
	BIT_VEC cppVar_38686 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38687 = (cppVar_38686 << 3) | 2;
	cppVar_38687 = (cppVar_38687 & cppMask_un_5_);
	BIT_VEC cppVar_38688 = (0 << 5) | cppVar_38687;
	cppVar_38688 = (cppVar_38688 & cppMask_un_8_);
	bool cppVar_38690 = (cppVar_38688 == 128);
	if (cppVar_38690) {
	cppVar_38685 = P0;
	} else {
	BIT_VEC cppVar_38691;
	BIT_VEC cppVar_38692 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38693 = (cppVar_38692 << 3) | 2;
	cppVar_38693 = (cppVar_38693 & cppMask_un_5_);
	BIT_VEC cppVar_38694 = (0 << 5) | cppVar_38693;
	cppVar_38694 = (cppVar_38694 & cppMask_un_8_);
	bool cppVar_38696 = (cppVar_38694 == 129);
	if (cppVar_38696) {
	cppVar_38691 = SP;
	} else {
	BIT_VEC cppVar_38697;
	BIT_VEC cppVar_38698 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38699 = (cppVar_38698 << 3) | 2;
	cppVar_38699 = (cppVar_38699 & cppMask_un_5_);
	BIT_VEC cppVar_38700 = (0 << 5) | cppVar_38699;
	cppVar_38700 = (cppVar_38700 & cppMask_un_8_);
	bool cppVar_38702 = (cppVar_38700 == 130);
	if (cppVar_38702) {
	cppVar_38697 = DPL;
	} else {
	BIT_VEC cppVar_38703;
	BIT_VEC cppVar_38704 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38705 = (cppVar_38704 << 3) | 2;
	cppVar_38705 = (cppVar_38705 & cppMask_un_5_);
	BIT_VEC cppVar_38706 = (0 << 5) | cppVar_38705;
	cppVar_38706 = (cppVar_38706 & cppMask_un_8_);
	bool cppVar_38708 = (cppVar_38706 == 131);
	if (cppVar_38708) {
	cppVar_38703 = DPH;
	} else {
	BIT_VEC cppVar_38709;
	BIT_VEC cppVar_38710 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38711 = (cppVar_38710 << 3) | 2;
	cppVar_38711 = (cppVar_38711 & cppMask_un_5_);
	BIT_VEC cppVar_38712 = (0 << 5) | cppVar_38711;
	cppVar_38712 = (cppVar_38712 & cppMask_un_8_);
	bool cppVar_38714 = (cppVar_38712 == 135);
	if (cppVar_38714) {
	cppVar_38709 = PCON;
	} else {
	BIT_VEC cppVar_38715;
	BIT_VEC cppVar_38716 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38717 = (cppVar_38716 << 3) | 2;
	cppVar_38717 = (cppVar_38717 & cppMask_un_5_);
	BIT_VEC cppVar_38718 = (0 << 5) | cppVar_38717;
	cppVar_38718 = (cppVar_38718 & cppMask_un_8_);
	bool cppVar_38720 = (cppVar_38718 == 136);
	if (cppVar_38720) {
	cppVar_38715 = TCON;
	} else {
	BIT_VEC cppVar_38721;
	BIT_VEC cppVar_38722 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38723 = (cppVar_38722 << 3) | 2;
	cppVar_38723 = (cppVar_38723 & cppMask_un_5_);
	BIT_VEC cppVar_38724 = (0 << 5) | cppVar_38723;
	cppVar_38724 = (cppVar_38724 & cppMask_un_8_);
	bool cppVar_38726 = (cppVar_38724 == 137);
	if (cppVar_38726) {
	cppVar_38721 = TMOD;
	} else {
	BIT_VEC cppVar_38727;
	BIT_VEC cppVar_38728 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38729 = (cppVar_38728 << 3) | 2;
	cppVar_38729 = (cppVar_38729 & cppMask_un_5_);
	BIT_VEC cppVar_38730 = (0 << 5) | cppVar_38729;
	cppVar_38730 = (cppVar_38730 & cppMask_un_8_);
	bool cppVar_38732 = (cppVar_38730 == 138);
	if (cppVar_38732) {
	cppVar_38727 = TL0;
	} else {
	BIT_VEC cppVar_38733;
	BIT_VEC cppVar_38734 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38735 = (cppVar_38734 << 3) | 2;
	cppVar_38735 = (cppVar_38735 & cppMask_un_5_);
	BIT_VEC cppVar_38736 = (0 << 5) | cppVar_38735;
	cppVar_38736 = (cppVar_38736 & cppMask_un_8_);
	bool cppVar_38738 = (cppVar_38736 == 140);
	if (cppVar_38738) {
	cppVar_38733 = TH0;
	} else {
	BIT_VEC cppVar_38739;
	BIT_VEC cppVar_38740 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38741 = (cppVar_38740 << 3) | 2;
	cppVar_38741 = (cppVar_38741 & cppMask_un_5_);
	BIT_VEC cppVar_38742 = (0 << 5) | cppVar_38741;
	cppVar_38742 = (cppVar_38742 & cppMask_un_8_);
	bool cppVar_38744 = (cppVar_38742 == 139);
	if (cppVar_38744) {
	cppVar_38739 = TL1;
	} else {
	BIT_VEC cppVar_38745;
	BIT_VEC cppVar_38746 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38747 = (cppVar_38746 << 3) | 2;
	cppVar_38747 = (cppVar_38747 & cppMask_un_5_);
	BIT_VEC cppVar_38748 = (0 << 5) | cppVar_38747;
	cppVar_38748 = (cppVar_38748 & cppMask_un_8_);
	bool cppVar_38750 = (cppVar_38748 == 141);
	if (cppVar_38750) {
	cppVar_38745 = TH1;
	} else {
	BIT_VEC cppVar_38751;
	BIT_VEC cppVar_38752 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38753 = (cppVar_38752 << 3) | 2;
	cppVar_38753 = (cppVar_38753 & cppMask_un_5_);
	BIT_VEC cppVar_38754 = (0 << 5) | cppVar_38753;
	cppVar_38754 = (cppVar_38754 & cppMask_un_8_);
	bool cppVar_38756 = (cppVar_38754 == 144);
	if (cppVar_38756) {
	cppVar_38751 = P1;
	} else {
	BIT_VEC cppVar_38757;
	BIT_VEC cppVar_38758 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38759 = (cppVar_38758 << 3) | 2;
	cppVar_38759 = (cppVar_38759 & cppMask_un_5_);
	BIT_VEC cppVar_38760 = (0 << 5) | cppVar_38759;
	cppVar_38760 = (cppVar_38760 & cppMask_un_8_);
	bool cppVar_38762 = (cppVar_38760 == 152);
	if (cppVar_38762) {
	cppVar_38757 = SCON;
	} else {
	BIT_VEC cppVar_38763;
	BIT_VEC cppVar_38764 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38765 = (cppVar_38764 << 3) | 2;
	cppVar_38765 = (cppVar_38765 & cppMask_un_5_);
	BIT_VEC cppVar_38766 = (0 << 5) | cppVar_38765;
	cppVar_38766 = (cppVar_38766 & cppMask_un_8_);
	bool cppVar_38768 = (cppVar_38766 == 153);
	if (cppVar_38768) {
	cppVar_38763 = SBUF;
	} else {
	BIT_VEC cppVar_38769;
	BIT_VEC cppVar_38770 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38771 = (cppVar_38770 << 3) | 2;
	cppVar_38771 = (cppVar_38771 & cppMask_un_5_);
	BIT_VEC cppVar_38772 = (0 << 5) | cppVar_38771;
	cppVar_38772 = (cppVar_38772 & cppMask_un_8_);
	bool cppVar_38774 = (cppVar_38772 == 160);
	if (cppVar_38774) {
	cppVar_38769 = P2;
	} else {
	BIT_VEC cppVar_38775;
	BIT_VEC cppVar_38776 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38777 = (cppVar_38776 << 3) | 2;
	cppVar_38777 = (cppVar_38777 & cppMask_un_5_);
	BIT_VEC cppVar_38778 = (0 << 5) | cppVar_38777;
	cppVar_38778 = (cppVar_38778 & cppMask_un_8_);
	bool cppVar_38780 = (cppVar_38778 == 168);
	if (cppVar_38780) {
	cppVar_38775 = IE;
	} else {
	BIT_VEC cppVar_38781;
	BIT_VEC cppVar_38782 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38783 = (cppVar_38782 << 3) | 2;
	cppVar_38783 = (cppVar_38783 & cppMask_un_5_);
	BIT_VEC cppVar_38784 = (0 << 5) | cppVar_38783;
	cppVar_38784 = (cppVar_38784 & cppMask_un_8_);
	bool cppVar_38786 = (cppVar_38784 == 176);
	if (cppVar_38786) {
	cppVar_38781 = P3;
	} else {
	BIT_VEC cppVar_38787;
	BIT_VEC cppVar_38788 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38789 = (cppVar_38788 << 3) | 2;
	cppVar_38789 = (cppVar_38789 & cppMask_un_5_);
	BIT_VEC cppVar_38790 = (0 << 5) | cppVar_38789;
	cppVar_38790 = (cppVar_38790 & cppMask_un_8_);
	bool cppVar_38792 = (cppVar_38790 == 184);
	if (cppVar_38792) {
	cppVar_38787 = IP;
	} else {
	BIT_VEC cppVar_38793;
	BIT_VEC cppVar_38794 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38795 = (cppVar_38794 << 3) | 2;
	cppVar_38795 = (cppVar_38795 & cppMask_un_5_);
	BIT_VEC cppVar_38796 = (0 << 5) | cppVar_38795;
	cppVar_38796 = (cppVar_38796 & cppMask_un_8_);
	bool cppVar_38798 = (cppVar_38796 == 208);
	if (cppVar_38798) {
	cppVar_38793 = PSW;
	} else {
	BIT_VEC cppVar_38799;
	BIT_VEC cppVar_38800 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38801 = (cppVar_38800 << 3) | 2;
	cppVar_38801 = (cppVar_38801 & cppMask_un_5_);
	BIT_VEC cppVar_38802 = (0 << 5) | cppVar_38801;
	cppVar_38802 = (cppVar_38802 & cppMask_un_8_);
	bool cppVar_38804 = (cppVar_38802 == 224);
	if (cppVar_38804) {
	cppVar_38799 = ACC;
	} else {
	BIT_VEC cppVar_38805;
	BIT_VEC cppVar_38806 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38807 = (cppVar_38806 << 3) | 2;
	cppVar_38807 = (cppVar_38807 & cppMask_un_5_);
	BIT_VEC cppVar_38808 = (0 << 5) | cppVar_38807;
	cppVar_38808 = (cppVar_38808 & cppMask_un_8_);
	bool cppVar_38810 = (cppVar_38808 == 240);
	if (cppVar_38810) {
	cppVar_38805 = B;
	} else {
	cppVar_38805 = 0;
	}
	cppVar_38799 = cppVar_38805;
	}
	cppVar_38793 = cppVar_38799;
	}
	cppVar_38787 = cppVar_38793;
	}
	cppVar_38781 = cppVar_38787;
	}
	cppVar_38775 = cppVar_38781;
	}
	cppVar_38769 = cppVar_38775;
	}
	cppVar_38763 = cppVar_38769;
	}
	cppVar_38757 = cppVar_38763;
	}
	cppVar_38751 = cppVar_38757;
	}
	cppVar_38745 = cppVar_38751;
	}
	cppVar_38739 = cppVar_38745;
	}
	cppVar_38733 = cppVar_38739;
	}
	cppVar_38727 = cppVar_38733;
	}
	cppVar_38721 = cppVar_38727;
	}
	cppVar_38715 = cppVar_38721;
	}
	cppVar_38709 = cppVar_38715;
	}
	cppVar_38703 = cppVar_38709;
	}
	cppVar_38697 = cppVar_38703;
	}
	cppVar_38691 = cppVar_38697;
	}
	cppVar_38685 = cppVar_38691;
	}
	cppVar_38672 = cppVar_38685;
	}
	cppVar_38666 = cppVar_38672;
	} else {
	cppVar_38666 = P3;
	}
	cppVar_38662 = cppVar_38666;
	} else {
	BIT_VEC cppVar_38812;
	BIT_VEC cppVar_38813 = ROM.rd(PC);
	bool cppVar_38815 = (cppVar_38813 == 137);
	if (cppVar_38815) {
	BIT_VEC cppVar_38816;
	BIT_VEC cppVar_38818 = PC + 1;
	cppVar_38818 = (cppVar_38818 & cppMask_un_16_);
	BIT_VEC cppVar_38819 = ROM.rd(cppVar_38818);
	bool cppVar_38821 = (cppVar_38819 == 176);
	if (cppVar_38821) {
	BIT_VEC cppVar_38822;
	BIT_VEC cppVar_38824 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38826 = (cppVar_38824 << 3) | 1;
	cppVar_38826 = (cppVar_38826 & cppMask_un_5_);
	BIT_VEC cppVar_38827 = (0 << 5) | cppVar_38826;
	cppVar_38827 = (cppVar_38827 & cppMask_un_8_);
	BIT_VEC cppVar_38828 = (cppVar_38827 >> 7) & cppMask_un_1_;
	bool cppVar_38830 = (cppVar_38828 == 0);
	if (cppVar_38830) {
	BIT_VEC cppVar_38831 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38832 = (cppVar_38831 << 3) | 1;
	cppVar_38832 = (cppVar_38832 & cppMask_un_5_);
	BIT_VEC cppVar_38833 = (0 << 5) | cppVar_38832;
	cppVar_38833 = (cppVar_38833 & cppMask_un_8_);
	BIT_VEC cppVar_38834 = IRAM.rd(cppVar_38833);
	cppVar_38822 = cppVar_38834;
	} else {
	BIT_VEC cppVar_38835;
	BIT_VEC cppVar_38836 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38837 = (cppVar_38836 << 3) | 1;
	cppVar_38837 = (cppVar_38837 & cppMask_un_5_);
	BIT_VEC cppVar_38838 = (0 << 5) | cppVar_38837;
	cppVar_38838 = (cppVar_38838 & cppMask_un_8_);
	bool cppVar_38840 = (cppVar_38838 == 128);
	if (cppVar_38840) {
	cppVar_38835 = P0;
	} else {
	BIT_VEC cppVar_38841;
	BIT_VEC cppVar_38842 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38843 = (cppVar_38842 << 3) | 1;
	cppVar_38843 = (cppVar_38843 & cppMask_un_5_);
	BIT_VEC cppVar_38844 = (0 << 5) | cppVar_38843;
	cppVar_38844 = (cppVar_38844 & cppMask_un_8_);
	bool cppVar_38846 = (cppVar_38844 == 129);
	if (cppVar_38846) {
	cppVar_38841 = SP;
	} else {
	BIT_VEC cppVar_38847;
	BIT_VEC cppVar_38848 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38849 = (cppVar_38848 << 3) | 1;
	cppVar_38849 = (cppVar_38849 & cppMask_un_5_);
	BIT_VEC cppVar_38850 = (0 << 5) | cppVar_38849;
	cppVar_38850 = (cppVar_38850 & cppMask_un_8_);
	bool cppVar_38852 = (cppVar_38850 == 130);
	if (cppVar_38852) {
	cppVar_38847 = DPL;
	} else {
	BIT_VEC cppVar_38853;
	BIT_VEC cppVar_38854 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38855 = (cppVar_38854 << 3) | 1;
	cppVar_38855 = (cppVar_38855 & cppMask_un_5_);
	BIT_VEC cppVar_38856 = (0 << 5) | cppVar_38855;
	cppVar_38856 = (cppVar_38856 & cppMask_un_8_);
	bool cppVar_38858 = (cppVar_38856 == 131);
	if (cppVar_38858) {
	cppVar_38853 = DPH;
	} else {
	BIT_VEC cppVar_38859;
	BIT_VEC cppVar_38860 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38861 = (cppVar_38860 << 3) | 1;
	cppVar_38861 = (cppVar_38861 & cppMask_un_5_);
	BIT_VEC cppVar_38862 = (0 << 5) | cppVar_38861;
	cppVar_38862 = (cppVar_38862 & cppMask_un_8_);
	bool cppVar_38864 = (cppVar_38862 == 135);
	if (cppVar_38864) {
	cppVar_38859 = PCON;
	} else {
	BIT_VEC cppVar_38865;
	BIT_VEC cppVar_38866 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38867 = (cppVar_38866 << 3) | 1;
	cppVar_38867 = (cppVar_38867 & cppMask_un_5_);
	BIT_VEC cppVar_38868 = (0 << 5) | cppVar_38867;
	cppVar_38868 = (cppVar_38868 & cppMask_un_8_);
	bool cppVar_38870 = (cppVar_38868 == 136);
	if (cppVar_38870) {
	cppVar_38865 = TCON;
	} else {
	BIT_VEC cppVar_38871;
	BIT_VEC cppVar_38872 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38873 = (cppVar_38872 << 3) | 1;
	cppVar_38873 = (cppVar_38873 & cppMask_un_5_);
	BIT_VEC cppVar_38874 = (0 << 5) | cppVar_38873;
	cppVar_38874 = (cppVar_38874 & cppMask_un_8_);
	bool cppVar_38876 = (cppVar_38874 == 137);
	if (cppVar_38876) {
	cppVar_38871 = TMOD;
	} else {
	BIT_VEC cppVar_38877;
	BIT_VEC cppVar_38878 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38879 = (cppVar_38878 << 3) | 1;
	cppVar_38879 = (cppVar_38879 & cppMask_un_5_);
	BIT_VEC cppVar_38880 = (0 << 5) | cppVar_38879;
	cppVar_38880 = (cppVar_38880 & cppMask_un_8_);
	bool cppVar_38882 = (cppVar_38880 == 138);
	if (cppVar_38882) {
	cppVar_38877 = TL0;
	} else {
	BIT_VEC cppVar_38883;
	BIT_VEC cppVar_38884 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38885 = (cppVar_38884 << 3) | 1;
	cppVar_38885 = (cppVar_38885 & cppMask_un_5_);
	BIT_VEC cppVar_38886 = (0 << 5) | cppVar_38885;
	cppVar_38886 = (cppVar_38886 & cppMask_un_8_);
	bool cppVar_38888 = (cppVar_38886 == 140);
	if (cppVar_38888) {
	cppVar_38883 = TH0;
	} else {
	BIT_VEC cppVar_38889;
	BIT_VEC cppVar_38890 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38891 = (cppVar_38890 << 3) | 1;
	cppVar_38891 = (cppVar_38891 & cppMask_un_5_);
	BIT_VEC cppVar_38892 = (0 << 5) | cppVar_38891;
	cppVar_38892 = (cppVar_38892 & cppMask_un_8_);
	bool cppVar_38894 = (cppVar_38892 == 139);
	if (cppVar_38894) {
	cppVar_38889 = TL1;
	} else {
	BIT_VEC cppVar_38895;
	BIT_VEC cppVar_38896 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38897 = (cppVar_38896 << 3) | 1;
	cppVar_38897 = (cppVar_38897 & cppMask_un_5_);
	BIT_VEC cppVar_38898 = (0 << 5) | cppVar_38897;
	cppVar_38898 = (cppVar_38898 & cppMask_un_8_);
	bool cppVar_38900 = (cppVar_38898 == 141);
	if (cppVar_38900) {
	cppVar_38895 = TH1;
	} else {
	BIT_VEC cppVar_38901;
	BIT_VEC cppVar_38902 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38903 = (cppVar_38902 << 3) | 1;
	cppVar_38903 = (cppVar_38903 & cppMask_un_5_);
	BIT_VEC cppVar_38904 = (0 << 5) | cppVar_38903;
	cppVar_38904 = (cppVar_38904 & cppMask_un_8_);
	bool cppVar_38906 = (cppVar_38904 == 144);
	if (cppVar_38906) {
	cppVar_38901 = P1;
	} else {
	BIT_VEC cppVar_38907;
	BIT_VEC cppVar_38908 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38909 = (cppVar_38908 << 3) | 1;
	cppVar_38909 = (cppVar_38909 & cppMask_un_5_);
	BIT_VEC cppVar_38910 = (0 << 5) | cppVar_38909;
	cppVar_38910 = (cppVar_38910 & cppMask_un_8_);
	bool cppVar_38912 = (cppVar_38910 == 152);
	if (cppVar_38912) {
	cppVar_38907 = SCON;
	} else {
	BIT_VEC cppVar_38913;
	BIT_VEC cppVar_38914 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38915 = (cppVar_38914 << 3) | 1;
	cppVar_38915 = (cppVar_38915 & cppMask_un_5_);
	BIT_VEC cppVar_38916 = (0 << 5) | cppVar_38915;
	cppVar_38916 = (cppVar_38916 & cppMask_un_8_);
	bool cppVar_38918 = (cppVar_38916 == 153);
	if (cppVar_38918) {
	cppVar_38913 = SBUF;
	} else {
	BIT_VEC cppVar_38919;
	BIT_VEC cppVar_38920 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38921 = (cppVar_38920 << 3) | 1;
	cppVar_38921 = (cppVar_38921 & cppMask_un_5_);
	BIT_VEC cppVar_38922 = (0 << 5) | cppVar_38921;
	cppVar_38922 = (cppVar_38922 & cppMask_un_8_);
	bool cppVar_38924 = (cppVar_38922 == 160);
	if (cppVar_38924) {
	cppVar_38919 = P2;
	} else {
	BIT_VEC cppVar_38925;
	BIT_VEC cppVar_38926 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38927 = (cppVar_38926 << 3) | 1;
	cppVar_38927 = (cppVar_38927 & cppMask_un_5_);
	BIT_VEC cppVar_38928 = (0 << 5) | cppVar_38927;
	cppVar_38928 = (cppVar_38928 & cppMask_un_8_);
	bool cppVar_38930 = (cppVar_38928 == 168);
	if (cppVar_38930) {
	cppVar_38925 = IE;
	} else {
	BIT_VEC cppVar_38931;
	BIT_VEC cppVar_38932 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38933 = (cppVar_38932 << 3) | 1;
	cppVar_38933 = (cppVar_38933 & cppMask_un_5_);
	BIT_VEC cppVar_38934 = (0 << 5) | cppVar_38933;
	cppVar_38934 = (cppVar_38934 & cppMask_un_8_);
	bool cppVar_38936 = (cppVar_38934 == 176);
	if (cppVar_38936) {
	cppVar_38931 = P3;
	} else {
	BIT_VEC cppVar_38937;
	BIT_VEC cppVar_38938 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38939 = (cppVar_38938 << 3) | 1;
	cppVar_38939 = (cppVar_38939 & cppMask_un_5_);
	BIT_VEC cppVar_38940 = (0 << 5) | cppVar_38939;
	cppVar_38940 = (cppVar_38940 & cppMask_un_8_);
	bool cppVar_38942 = (cppVar_38940 == 184);
	if (cppVar_38942) {
	cppVar_38937 = IP;
	} else {
	BIT_VEC cppVar_38943;
	BIT_VEC cppVar_38944 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38945 = (cppVar_38944 << 3) | 1;
	cppVar_38945 = (cppVar_38945 & cppMask_un_5_);
	BIT_VEC cppVar_38946 = (0 << 5) | cppVar_38945;
	cppVar_38946 = (cppVar_38946 & cppMask_un_8_);
	bool cppVar_38948 = (cppVar_38946 == 208);
	if (cppVar_38948) {
	cppVar_38943 = PSW;
	} else {
	BIT_VEC cppVar_38949;
	BIT_VEC cppVar_38950 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38951 = (cppVar_38950 << 3) | 1;
	cppVar_38951 = (cppVar_38951 & cppMask_un_5_);
	BIT_VEC cppVar_38952 = (0 << 5) | cppVar_38951;
	cppVar_38952 = (cppVar_38952 & cppMask_un_8_);
	bool cppVar_38954 = (cppVar_38952 == 224);
	if (cppVar_38954) {
	cppVar_38949 = ACC;
	} else {
	BIT_VEC cppVar_38955;
	BIT_VEC cppVar_38956 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38957 = (cppVar_38956 << 3) | 1;
	cppVar_38957 = (cppVar_38957 & cppMask_un_5_);
	BIT_VEC cppVar_38958 = (0 << 5) | cppVar_38957;
	cppVar_38958 = (cppVar_38958 & cppMask_un_8_);
	bool cppVar_38960 = (cppVar_38958 == 240);
	if (cppVar_38960) {
	cppVar_38955 = B;
	} else {
	cppVar_38955 = 0;
	}
	cppVar_38949 = cppVar_38955;
	}
	cppVar_38943 = cppVar_38949;
	}
	cppVar_38937 = cppVar_38943;
	}
	cppVar_38931 = cppVar_38937;
	}
	cppVar_38925 = cppVar_38931;
	}
	cppVar_38919 = cppVar_38925;
	}
	cppVar_38913 = cppVar_38919;
	}
	cppVar_38907 = cppVar_38913;
	}
	cppVar_38901 = cppVar_38907;
	}
	cppVar_38895 = cppVar_38901;
	}
	cppVar_38889 = cppVar_38895;
	}
	cppVar_38883 = cppVar_38889;
	}
	cppVar_38877 = cppVar_38883;
	}
	cppVar_38871 = cppVar_38877;
	}
	cppVar_38865 = cppVar_38871;
	}
	cppVar_38859 = cppVar_38865;
	}
	cppVar_38853 = cppVar_38859;
	}
	cppVar_38847 = cppVar_38853;
	}
	cppVar_38841 = cppVar_38847;
	}
	cppVar_38835 = cppVar_38841;
	}
	cppVar_38822 = cppVar_38835;
	}
	cppVar_38816 = cppVar_38822;
	} else {
	cppVar_38816 = P3;
	}
	cppVar_38812 = cppVar_38816;
	} else {
	BIT_VEC cppVar_38962;
	BIT_VEC cppVar_38963 = ROM.rd(PC);
	bool cppVar_38965 = (cppVar_38963 == 136);
	if (cppVar_38965) {
	BIT_VEC cppVar_38966;
	BIT_VEC cppVar_38968 = PC + 1;
	cppVar_38968 = (cppVar_38968 & cppMask_un_16_);
	BIT_VEC cppVar_38969 = ROM.rd(cppVar_38968);
	bool cppVar_38971 = (cppVar_38969 == 176);
	if (cppVar_38971) {
	BIT_VEC cppVar_38972;
	BIT_VEC cppVar_38974 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38976 = (cppVar_38974 << 3) | 0;
	cppVar_38976 = (cppVar_38976 & cppMask_un_5_);
	BIT_VEC cppVar_38977 = (0 << 5) | cppVar_38976;
	cppVar_38977 = (cppVar_38977 & cppMask_un_8_);
	BIT_VEC cppVar_38978 = (cppVar_38977 >> 7) & cppMask_un_1_;
	bool cppVar_38980 = (cppVar_38978 == 0);
	if (cppVar_38980) {
	BIT_VEC cppVar_38981 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38982 = (cppVar_38981 << 3) | 0;
	cppVar_38982 = (cppVar_38982 & cppMask_un_5_);
	BIT_VEC cppVar_38983 = (0 << 5) | cppVar_38982;
	cppVar_38983 = (cppVar_38983 & cppMask_un_8_);
	BIT_VEC cppVar_38984 = IRAM.rd(cppVar_38983);
	cppVar_38972 = cppVar_38984;
	} else {
	BIT_VEC cppVar_38985;
	BIT_VEC cppVar_38986 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38987 = (cppVar_38986 << 3) | 0;
	cppVar_38987 = (cppVar_38987 & cppMask_un_5_);
	BIT_VEC cppVar_38988 = (0 << 5) | cppVar_38987;
	cppVar_38988 = (cppVar_38988 & cppMask_un_8_);
	bool cppVar_38990 = (cppVar_38988 == 128);
	if (cppVar_38990) {
	cppVar_38985 = P0;
	} else {
	BIT_VEC cppVar_38991;
	BIT_VEC cppVar_38992 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38993 = (cppVar_38992 << 3) | 0;
	cppVar_38993 = (cppVar_38993 & cppMask_un_5_);
	BIT_VEC cppVar_38994 = (0 << 5) | cppVar_38993;
	cppVar_38994 = (cppVar_38994 & cppMask_un_8_);
	bool cppVar_38996 = (cppVar_38994 == 129);
	if (cppVar_38996) {
	cppVar_38991 = SP;
	} else {
	BIT_VEC cppVar_38997;
	BIT_VEC cppVar_38998 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_38999 = (cppVar_38998 << 3) | 0;
	cppVar_38999 = (cppVar_38999 & cppMask_un_5_);
	BIT_VEC cppVar_39000 = (0 << 5) | cppVar_38999;
	cppVar_39000 = (cppVar_39000 & cppMask_un_8_);
	bool cppVar_39002 = (cppVar_39000 == 130);
	if (cppVar_39002) {
	cppVar_38997 = DPL;
	} else {
	BIT_VEC cppVar_39003;
	BIT_VEC cppVar_39004 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39005 = (cppVar_39004 << 3) | 0;
	cppVar_39005 = (cppVar_39005 & cppMask_un_5_);
	BIT_VEC cppVar_39006 = (0 << 5) | cppVar_39005;
	cppVar_39006 = (cppVar_39006 & cppMask_un_8_);
	bool cppVar_39008 = (cppVar_39006 == 131);
	if (cppVar_39008) {
	cppVar_39003 = DPH;
	} else {
	BIT_VEC cppVar_39009;
	BIT_VEC cppVar_39010 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39011 = (cppVar_39010 << 3) | 0;
	cppVar_39011 = (cppVar_39011 & cppMask_un_5_);
	BIT_VEC cppVar_39012 = (0 << 5) | cppVar_39011;
	cppVar_39012 = (cppVar_39012 & cppMask_un_8_);
	bool cppVar_39014 = (cppVar_39012 == 135);
	if (cppVar_39014) {
	cppVar_39009 = PCON;
	} else {
	BIT_VEC cppVar_39015;
	BIT_VEC cppVar_39016 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39017 = (cppVar_39016 << 3) | 0;
	cppVar_39017 = (cppVar_39017 & cppMask_un_5_);
	BIT_VEC cppVar_39018 = (0 << 5) | cppVar_39017;
	cppVar_39018 = (cppVar_39018 & cppMask_un_8_);
	bool cppVar_39020 = (cppVar_39018 == 136);
	if (cppVar_39020) {
	cppVar_39015 = TCON;
	} else {
	BIT_VEC cppVar_39021;
	BIT_VEC cppVar_39022 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39023 = (cppVar_39022 << 3) | 0;
	cppVar_39023 = (cppVar_39023 & cppMask_un_5_);
	BIT_VEC cppVar_39024 = (0 << 5) | cppVar_39023;
	cppVar_39024 = (cppVar_39024 & cppMask_un_8_);
	bool cppVar_39026 = (cppVar_39024 == 137);
	if (cppVar_39026) {
	cppVar_39021 = TMOD;
	} else {
	BIT_VEC cppVar_39027;
	BIT_VEC cppVar_39028 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39029 = (cppVar_39028 << 3) | 0;
	cppVar_39029 = (cppVar_39029 & cppMask_un_5_);
	BIT_VEC cppVar_39030 = (0 << 5) | cppVar_39029;
	cppVar_39030 = (cppVar_39030 & cppMask_un_8_);
	bool cppVar_39032 = (cppVar_39030 == 138);
	if (cppVar_39032) {
	cppVar_39027 = TL0;
	} else {
	BIT_VEC cppVar_39033;
	BIT_VEC cppVar_39034 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39035 = (cppVar_39034 << 3) | 0;
	cppVar_39035 = (cppVar_39035 & cppMask_un_5_);
	BIT_VEC cppVar_39036 = (0 << 5) | cppVar_39035;
	cppVar_39036 = (cppVar_39036 & cppMask_un_8_);
	bool cppVar_39038 = (cppVar_39036 == 140);
	if (cppVar_39038) {
	cppVar_39033 = TH0;
	} else {
	BIT_VEC cppVar_39039;
	BIT_VEC cppVar_39040 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39041 = (cppVar_39040 << 3) | 0;
	cppVar_39041 = (cppVar_39041 & cppMask_un_5_);
	BIT_VEC cppVar_39042 = (0 << 5) | cppVar_39041;
	cppVar_39042 = (cppVar_39042 & cppMask_un_8_);
	bool cppVar_39044 = (cppVar_39042 == 139);
	if (cppVar_39044) {
	cppVar_39039 = TL1;
	} else {
	BIT_VEC cppVar_39045;
	BIT_VEC cppVar_39046 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39047 = (cppVar_39046 << 3) | 0;
	cppVar_39047 = (cppVar_39047 & cppMask_un_5_);
	BIT_VEC cppVar_39048 = (0 << 5) | cppVar_39047;
	cppVar_39048 = (cppVar_39048 & cppMask_un_8_);
	bool cppVar_39050 = (cppVar_39048 == 141);
	if (cppVar_39050) {
	cppVar_39045 = TH1;
	} else {
	BIT_VEC cppVar_39051;
	BIT_VEC cppVar_39052 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39053 = (cppVar_39052 << 3) | 0;
	cppVar_39053 = (cppVar_39053 & cppMask_un_5_);
	BIT_VEC cppVar_39054 = (0 << 5) | cppVar_39053;
	cppVar_39054 = (cppVar_39054 & cppMask_un_8_);
	bool cppVar_39056 = (cppVar_39054 == 144);
	if (cppVar_39056) {
	cppVar_39051 = P1;
	} else {
	BIT_VEC cppVar_39057;
	BIT_VEC cppVar_39058 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39059 = (cppVar_39058 << 3) | 0;
	cppVar_39059 = (cppVar_39059 & cppMask_un_5_);
	BIT_VEC cppVar_39060 = (0 << 5) | cppVar_39059;
	cppVar_39060 = (cppVar_39060 & cppMask_un_8_);
	bool cppVar_39062 = (cppVar_39060 == 152);
	if (cppVar_39062) {
	cppVar_39057 = SCON;
	} else {
	BIT_VEC cppVar_39063;
	BIT_VEC cppVar_39064 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39065 = (cppVar_39064 << 3) | 0;
	cppVar_39065 = (cppVar_39065 & cppMask_un_5_);
	BIT_VEC cppVar_39066 = (0 << 5) | cppVar_39065;
	cppVar_39066 = (cppVar_39066 & cppMask_un_8_);
	bool cppVar_39068 = (cppVar_39066 == 153);
	if (cppVar_39068) {
	cppVar_39063 = SBUF;
	} else {
	BIT_VEC cppVar_39069;
	BIT_VEC cppVar_39070 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39071 = (cppVar_39070 << 3) | 0;
	cppVar_39071 = (cppVar_39071 & cppMask_un_5_);
	BIT_VEC cppVar_39072 = (0 << 5) | cppVar_39071;
	cppVar_39072 = (cppVar_39072 & cppMask_un_8_);
	bool cppVar_39074 = (cppVar_39072 == 160);
	if (cppVar_39074) {
	cppVar_39069 = P2;
	} else {
	BIT_VEC cppVar_39075;
	BIT_VEC cppVar_39076 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39077 = (cppVar_39076 << 3) | 0;
	cppVar_39077 = (cppVar_39077 & cppMask_un_5_);
	BIT_VEC cppVar_39078 = (0 << 5) | cppVar_39077;
	cppVar_39078 = (cppVar_39078 & cppMask_un_8_);
	bool cppVar_39080 = (cppVar_39078 == 168);
	if (cppVar_39080) {
	cppVar_39075 = IE;
	} else {
	BIT_VEC cppVar_39081;
	BIT_VEC cppVar_39082 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39083 = (cppVar_39082 << 3) | 0;
	cppVar_39083 = (cppVar_39083 & cppMask_un_5_);
	BIT_VEC cppVar_39084 = (0 << 5) | cppVar_39083;
	cppVar_39084 = (cppVar_39084 & cppMask_un_8_);
	bool cppVar_39086 = (cppVar_39084 == 176);
	if (cppVar_39086) {
	cppVar_39081 = P3;
	} else {
	BIT_VEC cppVar_39087;
	BIT_VEC cppVar_39088 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39089 = (cppVar_39088 << 3) | 0;
	cppVar_39089 = (cppVar_39089 & cppMask_un_5_);
	BIT_VEC cppVar_39090 = (0 << 5) | cppVar_39089;
	cppVar_39090 = (cppVar_39090 & cppMask_un_8_);
	bool cppVar_39092 = (cppVar_39090 == 184);
	if (cppVar_39092) {
	cppVar_39087 = IP;
	} else {
	BIT_VEC cppVar_39093;
	BIT_VEC cppVar_39094 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39095 = (cppVar_39094 << 3) | 0;
	cppVar_39095 = (cppVar_39095 & cppMask_un_5_);
	BIT_VEC cppVar_39096 = (0 << 5) | cppVar_39095;
	cppVar_39096 = (cppVar_39096 & cppMask_un_8_);
	bool cppVar_39098 = (cppVar_39096 == 208);
	if (cppVar_39098) {
	cppVar_39093 = PSW;
	} else {
	BIT_VEC cppVar_39099;
	BIT_VEC cppVar_39100 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39101 = (cppVar_39100 << 3) | 0;
	cppVar_39101 = (cppVar_39101 & cppMask_un_5_);
	BIT_VEC cppVar_39102 = (0 << 5) | cppVar_39101;
	cppVar_39102 = (cppVar_39102 & cppMask_un_8_);
	bool cppVar_39104 = (cppVar_39102 == 224);
	if (cppVar_39104) {
	cppVar_39099 = ACC;
	} else {
	BIT_VEC cppVar_39105;
	BIT_VEC cppVar_39106 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39107 = (cppVar_39106 << 3) | 0;
	cppVar_39107 = (cppVar_39107 & cppMask_un_5_);
	BIT_VEC cppVar_39108 = (0 << 5) | cppVar_39107;
	cppVar_39108 = (cppVar_39108 & cppMask_un_8_);
	bool cppVar_39110 = (cppVar_39108 == 240);
	if (cppVar_39110) {
	cppVar_39105 = B;
	} else {
	cppVar_39105 = 0;
	}
	cppVar_39099 = cppVar_39105;
	}
	cppVar_39093 = cppVar_39099;
	}
	cppVar_39087 = cppVar_39093;
	}
	cppVar_39081 = cppVar_39087;
	}
	cppVar_39075 = cppVar_39081;
	}
	cppVar_39069 = cppVar_39075;
	}
	cppVar_39063 = cppVar_39069;
	}
	cppVar_39057 = cppVar_39063;
	}
	cppVar_39051 = cppVar_39057;
	}
	cppVar_39045 = cppVar_39051;
	}
	cppVar_39039 = cppVar_39045;
	}
	cppVar_39033 = cppVar_39039;
	}
	cppVar_39027 = cppVar_39033;
	}
	cppVar_39021 = cppVar_39027;
	}
	cppVar_39015 = cppVar_39021;
	}
	cppVar_39009 = cppVar_39015;
	}
	cppVar_39003 = cppVar_39009;
	}
	cppVar_38997 = cppVar_39003;
	}
	cppVar_38991 = cppVar_38997;
	}
	cppVar_38985 = cppVar_38991;
	}
	cppVar_38972 = cppVar_38985;
	}
	cppVar_38966 = cppVar_38972;
	} else {
	cppVar_38966 = P3;
	}
	cppVar_38962 = cppVar_38966;
	} else {
	BIT_VEC cppVar_39112;
	BIT_VEC cppVar_39113 = ROM.rd(PC);
	bool cppVar_39115 = (cppVar_39113 == 135);
	if (cppVar_39115) {
	BIT_VEC cppVar_39116;
	BIT_VEC cppVar_39118 = PC + 1;
	cppVar_39118 = (cppVar_39118 & cppMask_un_16_);
	BIT_VEC cppVar_39119 = ROM.rd(cppVar_39118);
	bool cppVar_39121 = (cppVar_39119 == 176);
	if (cppVar_39121) {
	BIT_VEC cppVar_39123 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39125 = (cppVar_39123 << 3) | 1;
	cppVar_39125 = (cppVar_39125 & cppMask_un_5_);
	BIT_VEC cppVar_39126 = (0 << 5) | cppVar_39125;
	cppVar_39126 = (cppVar_39126 & cppMask_un_8_);
	BIT_VEC cppVar_39127 = IRAM.rd(cppVar_39126);
	BIT_VEC cppVar_39128 = IRAM.rd(cppVar_39127);
	cppVar_39116 = cppVar_39128;
	} else {
	cppVar_39116 = P3;
	}
	cppVar_39112 = cppVar_39116;
	} else {
	BIT_VEC cppVar_39129;
	BIT_VEC cppVar_39130 = ROM.rd(PC);
	bool cppVar_39132 = (cppVar_39130 == 134);
	if (cppVar_39132) {
	BIT_VEC cppVar_39133;
	BIT_VEC cppVar_39135 = PC + 1;
	cppVar_39135 = (cppVar_39135 & cppMask_un_16_);
	BIT_VEC cppVar_39136 = ROM.rd(cppVar_39135);
	bool cppVar_39138 = (cppVar_39136 == 176);
	if (cppVar_39138) {
	BIT_VEC cppVar_39140 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_39142 = (cppVar_39140 << 3) | 0;
	cppVar_39142 = (cppVar_39142 & cppMask_un_5_);
	BIT_VEC cppVar_39143 = (0 << 5) | cppVar_39142;
	cppVar_39143 = (cppVar_39143 & cppMask_un_8_);
	BIT_VEC cppVar_39144 = IRAM.rd(cppVar_39143);
	BIT_VEC cppVar_39145 = IRAM.rd(cppVar_39144);
	cppVar_39133 = cppVar_39145;
	} else {
	cppVar_39133 = P3;
	}
	cppVar_39129 = cppVar_39133;
	} else {
	BIT_VEC cppVar_39146;
	BIT_VEC cppVar_39147 = ROM.rd(PC);
	bool cppVar_39149 = (cppVar_39147 == 133);
	if (cppVar_39149) {
	BIT_VEC cppVar_39150;
	BIT_VEC cppVar_39152 = PC + 2;
	cppVar_39152 = (cppVar_39152 & cppMask_un_16_);
	BIT_VEC cppVar_39153 = ROM.rd(cppVar_39152);
	bool cppVar_39155 = (cppVar_39153 == 176);
	if (cppVar_39155) {
	BIT_VEC cppVar_39156;
	BIT_VEC cppVar_39158 = PC + 1;
	cppVar_39158 = (cppVar_39158 & cppMask_un_16_);
	BIT_VEC cppVar_39159 = ROM.rd(cppVar_39158);
	BIT_VEC cppVar_39160 = (cppVar_39159 >> 7) & cppMask_un_1_;
	bool cppVar_39162 = (cppVar_39160 == 0);
	if (cppVar_39162) {
	BIT_VEC cppVar_39163 = PC + 1;
	cppVar_39163 = (cppVar_39163 & cppMask_un_16_);
	BIT_VEC cppVar_39164 = ROM.rd(cppVar_39163);
	BIT_VEC cppVar_39165 = IRAM.rd(cppVar_39164);
	cppVar_39156 = cppVar_39165;
	} else {
	BIT_VEC cppVar_39166;
	BIT_VEC cppVar_39167 = PC + 1;
	cppVar_39167 = (cppVar_39167 & cppMask_un_16_);
	BIT_VEC cppVar_39168 = ROM.rd(cppVar_39167);
	bool cppVar_39170 = (cppVar_39168 == 128);
	if (cppVar_39170) {
	cppVar_39166 = P0;
	} else {
	BIT_VEC cppVar_39171;
	BIT_VEC cppVar_39172 = PC + 1;
	cppVar_39172 = (cppVar_39172 & cppMask_un_16_);
	BIT_VEC cppVar_39173 = ROM.rd(cppVar_39172);
	bool cppVar_39175 = (cppVar_39173 == 129);
	if (cppVar_39175) {
	cppVar_39171 = SP;
	} else {
	BIT_VEC cppVar_39176;
	BIT_VEC cppVar_39177 = PC + 1;
	cppVar_39177 = (cppVar_39177 & cppMask_un_16_);
	BIT_VEC cppVar_39178 = ROM.rd(cppVar_39177);
	bool cppVar_39180 = (cppVar_39178 == 130);
	if (cppVar_39180) {
	cppVar_39176 = DPL;
	} else {
	BIT_VEC cppVar_39181;
	BIT_VEC cppVar_39182 = PC + 1;
	cppVar_39182 = (cppVar_39182 & cppMask_un_16_);
	BIT_VEC cppVar_39183 = ROM.rd(cppVar_39182);
	bool cppVar_39185 = (cppVar_39183 == 131);
	if (cppVar_39185) {
	cppVar_39181 = DPH;
	} else {
	BIT_VEC cppVar_39186;
	BIT_VEC cppVar_39187 = PC + 1;
	cppVar_39187 = (cppVar_39187 & cppMask_un_16_);
	BIT_VEC cppVar_39188 = ROM.rd(cppVar_39187);
	bool cppVar_39190 = (cppVar_39188 == 135);
	if (cppVar_39190) {
	cppVar_39186 = PCON;
	} else {
	BIT_VEC cppVar_39191;
	BIT_VEC cppVar_39192 = PC + 1;
	cppVar_39192 = (cppVar_39192 & cppMask_un_16_);
	BIT_VEC cppVar_39193 = ROM.rd(cppVar_39192);
	bool cppVar_39195 = (cppVar_39193 == 136);
	if (cppVar_39195) {
	cppVar_39191 = TCON;
	} else {
	BIT_VEC cppVar_39196;
	BIT_VEC cppVar_39197 = PC + 1;
	cppVar_39197 = (cppVar_39197 & cppMask_un_16_);
	BIT_VEC cppVar_39198 = ROM.rd(cppVar_39197);
	bool cppVar_39200 = (cppVar_39198 == 137);
	if (cppVar_39200) {
	cppVar_39196 = TMOD;
	} else {
	BIT_VEC cppVar_39201;
	BIT_VEC cppVar_39202 = PC + 1;
	cppVar_39202 = (cppVar_39202 & cppMask_un_16_);
	BIT_VEC cppVar_39203 = ROM.rd(cppVar_39202);
	bool cppVar_39205 = (cppVar_39203 == 138);
	if (cppVar_39205) {
	cppVar_39201 = TL0;
	} else {
	BIT_VEC cppVar_39206;
	BIT_VEC cppVar_39207 = PC + 1;
	cppVar_39207 = (cppVar_39207 & cppMask_un_16_);
	BIT_VEC cppVar_39208 = ROM.rd(cppVar_39207);
	bool cppVar_39210 = (cppVar_39208 == 140);
	if (cppVar_39210) {
	cppVar_39206 = TH0;
	} else {
	BIT_VEC cppVar_39211;
	BIT_VEC cppVar_39212 = PC + 1;
	cppVar_39212 = (cppVar_39212 & cppMask_un_16_);
	BIT_VEC cppVar_39213 = ROM.rd(cppVar_39212);
	bool cppVar_39215 = (cppVar_39213 == 139);
	if (cppVar_39215) {
	cppVar_39211 = TL1;
	} else {
	BIT_VEC cppVar_39216;
	BIT_VEC cppVar_39217 = PC + 1;
	cppVar_39217 = (cppVar_39217 & cppMask_un_16_);
	BIT_VEC cppVar_39218 = ROM.rd(cppVar_39217);
	bool cppVar_39220 = (cppVar_39218 == 141);
	if (cppVar_39220) {
	cppVar_39216 = TH1;
	} else {
	BIT_VEC cppVar_39221;
	BIT_VEC cppVar_39222 = PC + 1;
	cppVar_39222 = (cppVar_39222 & cppMask_un_16_);
	BIT_VEC cppVar_39223 = ROM.rd(cppVar_39222);
	bool cppVar_39225 = (cppVar_39223 == 144);
	if (cppVar_39225) {
	cppVar_39221 = P1;
	} else {
	BIT_VEC cppVar_39226;
	BIT_VEC cppVar_39227 = PC + 1;
	cppVar_39227 = (cppVar_39227 & cppMask_un_16_);
	BIT_VEC cppVar_39228 = ROM.rd(cppVar_39227);
	bool cppVar_39230 = (cppVar_39228 == 152);
	if (cppVar_39230) {
	cppVar_39226 = SCON;
	} else {
	BIT_VEC cppVar_39231;
	BIT_VEC cppVar_39232 = PC + 1;
	cppVar_39232 = (cppVar_39232 & cppMask_un_16_);
	BIT_VEC cppVar_39233 = ROM.rd(cppVar_39232);
	bool cppVar_39235 = (cppVar_39233 == 153);
	if (cppVar_39235) {
	cppVar_39231 = SBUF;
	} else {
	BIT_VEC cppVar_39236;
	BIT_VEC cppVar_39237 = PC + 1;
	cppVar_39237 = (cppVar_39237 & cppMask_un_16_);
	BIT_VEC cppVar_39238 = ROM.rd(cppVar_39237);
	bool cppVar_39240 = (cppVar_39238 == 160);
	if (cppVar_39240) {
	cppVar_39236 = P2;
	} else {
	BIT_VEC cppVar_39241;
	BIT_VEC cppVar_39242 = PC + 1;
	cppVar_39242 = (cppVar_39242 & cppMask_un_16_);
	BIT_VEC cppVar_39243 = ROM.rd(cppVar_39242);
	bool cppVar_39245 = (cppVar_39243 == 168);
	if (cppVar_39245) {
	cppVar_39241 = IE;
	} else {
	BIT_VEC cppVar_39246;
	BIT_VEC cppVar_39247 = PC + 1;
	cppVar_39247 = (cppVar_39247 & cppMask_un_16_);
	BIT_VEC cppVar_39248 = ROM.rd(cppVar_39247);
	bool cppVar_39250 = (cppVar_39248 == 176);
	if (cppVar_39250) {
	cppVar_39246 = P3;
	} else {
	BIT_VEC cppVar_39251;
	BIT_VEC cppVar_39252 = PC + 1;
	cppVar_39252 = (cppVar_39252 & cppMask_un_16_);
	BIT_VEC cppVar_39253 = ROM.rd(cppVar_39252);
	bool cppVar_39255 = (cppVar_39253 == 184);
	if (cppVar_39255) {
	cppVar_39251 = IP;
	} else {
	BIT_VEC cppVar_39256;
	BIT_VEC cppVar_39257 = PC + 1;
	cppVar_39257 = (cppVar_39257 & cppMask_un_16_);
	BIT_VEC cppVar_39258 = ROM.rd(cppVar_39257);
	bool cppVar_39260 = (cppVar_39258 == 208);
	if (cppVar_39260) {
	cppVar_39256 = PSW;
	} else {
	BIT_VEC cppVar_39261;
	BIT_VEC cppVar_39262 = PC + 1;
	cppVar_39262 = (cppVar_39262 & cppMask_un_16_);
	BIT_VEC cppVar_39263 = ROM.rd(cppVar_39262);
	bool cppVar_39265 = (cppVar_39263 == 224);
	if (cppVar_39265) {
	cppVar_39261 = ACC;
	} else {
	BIT_VEC cppVar_39266;
	BIT_VEC cppVar_39267 = PC + 1;
	cppVar_39267 = (cppVar_39267 & cppMask_un_16_);
	BIT_VEC cppVar_39268 = ROM.rd(cppVar_39267);
	bool cppVar_39270 = (cppVar_39268 == 240);
	if (cppVar_39270) {
	cppVar_39266 = B;
	} else {
	cppVar_39266 = 0;
	}
	cppVar_39261 = cppVar_39266;
	}
	cppVar_39256 = cppVar_39261;
	}
	cppVar_39251 = cppVar_39256;
	}
	cppVar_39246 = cppVar_39251;
	}
	cppVar_39241 = cppVar_39246;
	}
	cppVar_39236 = cppVar_39241;
	}
	cppVar_39231 = cppVar_39236;
	}
	cppVar_39226 = cppVar_39231;
	}
	cppVar_39221 = cppVar_39226;
	}
	cppVar_39216 = cppVar_39221;
	}
	cppVar_39211 = cppVar_39216;
	}
	cppVar_39206 = cppVar_39211;
	}
	cppVar_39201 = cppVar_39206;
	}
	cppVar_39196 = cppVar_39201;
	}
	cppVar_39191 = cppVar_39196;
	}
	cppVar_39186 = cppVar_39191;
	}
	cppVar_39181 = cppVar_39186;
	}
	cppVar_39176 = cppVar_39181;
	}
	cppVar_39171 = cppVar_39176;
	}
	cppVar_39166 = cppVar_39171;
	}
	cppVar_39156 = cppVar_39166;
	}
	cppVar_39150 = cppVar_39156;
	} else {
	cppVar_39150 = P3;
	}
	cppVar_39146 = cppVar_39150;
	} else {
	BIT_VEC cppVar_39272;
	BIT_VEC cppVar_39273 = ROM.rd(PC);
	bool cppVar_39275 = (cppVar_39273 == 117);
	if (cppVar_39275) {
	BIT_VEC cppVar_39276;
	BIT_VEC cppVar_39278 = PC + 1;
	cppVar_39278 = (cppVar_39278 & cppMask_un_16_);
	BIT_VEC cppVar_39279 = ROM.rd(cppVar_39278);
	bool cppVar_39281 = (cppVar_39279 == 176);
	if (cppVar_39281) {
	BIT_VEC cppVar_39283 = PC + 2;
	cppVar_39283 = (cppVar_39283 & cppMask_un_16_);
	BIT_VEC cppVar_39284 = ROM.rd(cppVar_39283);
	cppVar_39276 = cppVar_39284;
	} else {
	cppVar_39276 = P3;
	}
	cppVar_39272 = cppVar_39276;
	} else {
	BIT_VEC cppVar_39285;
	BIT_VEC cppVar_39286 = ROM.rd(PC);
	bool cppVar_39288 = (cppVar_39286 == 99);
	if (cppVar_39288) {
	BIT_VEC cppVar_39289;
	BIT_VEC cppVar_39291 = PC + 1;
	cppVar_39291 = (cppVar_39291 & cppMask_un_16_);
	BIT_VEC cppVar_39292 = ROM.rd(cppVar_39291);
	bool cppVar_39294 = (cppVar_39292 == 176);
	if (cppVar_39294) {
	BIT_VEC cppVar_39295;
	BIT_VEC cppVar_39296 = PC + 1;
	cppVar_39296 = (cppVar_39296 & cppMask_un_16_);
	BIT_VEC cppVar_39297 = ROM.rd(cppVar_39296);
	BIT_VEC cppVar_39298 = (cppVar_39297 >> 7) & cppMask_un_1_;
	bool cppVar_39300 = (cppVar_39298 == 0);
	if (cppVar_39300) {
	BIT_VEC cppVar_39301 = PC + 1;
	cppVar_39301 = (cppVar_39301 & cppMask_un_16_);
	BIT_VEC cppVar_39302 = ROM.rd(cppVar_39301);
	BIT_VEC cppVar_39303 = IRAM.rd(cppVar_39302);
	cppVar_39295 = cppVar_39303;
	} else {
	BIT_VEC cppVar_39304;
	BIT_VEC cppVar_39305 = PC + 1;
	cppVar_39305 = (cppVar_39305 & cppMask_un_16_);
	BIT_VEC cppVar_39306 = ROM.rd(cppVar_39305);
	bool cppVar_39308 = (cppVar_39306 == 128);
	if (cppVar_39308) {
	cppVar_39304 = P0;
	} else {
	BIT_VEC cppVar_39309;
	BIT_VEC cppVar_39310 = PC + 1;
	cppVar_39310 = (cppVar_39310 & cppMask_un_16_);
	BIT_VEC cppVar_39311 = ROM.rd(cppVar_39310);
	bool cppVar_39313 = (cppVar_39311 == 129);
	if (cppVar_39313) {
	cppVar_39309 = SP;
	} else {
	BIT_VEC cppVar_39314;
	BIT_VEC cppVar_39315 = PC + 1;
	cppVar_39315 = (cppVar_39315 & cppMask_un_16_);
	BIT_VEC cppVar_39316 = ROM.rd(cppVar_39315);
	bool cppVar_39318 = (cppVar_39316 == 130);
	if (cppVar_39318) {
	cppVar_39314 = DPL;
	} else {
	BIT_VEC cppVar_39319;
	BIT_VEC cppVar_39320 = PC + 1;
	cppVar_39320 = (cppVar_39320 & cppMask_un_16_);
	BIT_VEC cppVar_39321 = ROM.rd(cppVar_39320);
	bool cppVar_39323 = (cppVar_39321 == 131);
	if (cppVar_39323) {
	cppVar_39319 = DPH;
	} else {
	BIT_VEC cppVar_39324;
	BIT_VEC cppVar_39325 = PC + 1;
	cppVar_39325 = (cppVar_39325 & cppMask_un_16_);
	BIT_VEC cppVar_39326 = ROM.rd(cppVar_39325);
	bool cppVar_39328 = (cppVar_39326 == 135);
	if (cppVar_39328) {
	cppVar_39324 = PCON;
	} else {
	BIT_VEC cppVar_39329;
	BIT_VEC cppVar_39330 = PC + 1;
	cppVar_39330 = (cppVar_39330 & cppMask_un_16_);
	BIT_VEC cppVar_39331 = ROM.rd(cppVar_39330);
	bool cppVar_39333 = (cppVar_39331 == 136);
	if (cppVar_39333) {
	cppVar_39329 = TCON;
	} else {
	BIT_VEC cppVar_39334;
	BIT_VEC cppVar_39335 = PC + 1;
	cppVar_39335 = (cppVar_39335 & cppMask_un_16_);
	BIT_VEC cppVar_39336 = ROM.rd(cppVar_39335);
	bool cppVar_39338 = (cppVar_39336 == 137);
	if (cppVar_39338) {
	cppVar_39334 = TMOD;
	} else {
	BIT_VEC cppVar_39339;
	BIT_VEC cppVar_39340 = PC + 1;
	cppVar_39340 = (cppVar_39340 & cppMask_un_16_);
	BIT_VEC cppVar_39341 = ROM.rd(cppVar_39340);
	bool cppVar_39343 = (cppVar_39341 == 138);
	if (cppVar_39343) {
	cppVar_39339 = TL0;
	} else {
	BIT_VEC cppVar_39344;
	BIT_VEC cppVar_39345 = PC + 1;
	cppVar_39345 = (cppVar_39345 & cppMask_un_16_);
	BIT_VEC cppVar_39346 = ROM.rd(cppVar_39345);
	bool cppVar_39348 = (cppVar_39346 == 140);
	if (cppVar_39348) {
	cppVar_39344 = TH0;
	} else {
	BIT_VEC cppVar_39349;
	BIT_VEC cppVar_39350 = PC + 1;
	cppVar_39350 = (cppVar_39350 & cppMask_un_16_);
	BIT_VEC cppVar_39351 = ROM.rd(cppVar_39350);
	bool cppVar_39353 = (cppVar_39351 == 139);
	if (cppVar_39353) {
	cppVar_39349 = TL1;
	} else {
	BIT_VEC cppVar_39354;
	BIT_VEC cppVar_39355 = PC + 1;
	cppVar_39355 = (cppVar_39355 & cppMask_un_16_);
	BIT_VEC cppVar_39356 = ROM.rd(cppVar_39355);
	bool cppVar_39358 = (cppVar_39356 == 141);
	if (cppVar_39358) {
	cppVar_39354 = TH1;
	} else {
	BIT_VEC cppVar_39359;
	BIT_VEC cppVar_39360 = PC + 1;
	cppVar_39360 = (cppVar_39360 & cppMask_un_16_);
	BIT_VEC cppVar_39361 = ROM.rd(cppVar_39360);
	bool cppVar_39363 = (cppVar_39361 == 144);
	if (cppVar_39363) {
	cppVar_39359 = P1;
	} else {
	BIT_VEC cppVar_39364;
	BIT_VEC cppVar_39365 = PC + 1;
	cppVar_39365 = (cppVar_39365 & cppMask_un_16_);
	BIT_VEC cppVar_39366 = ROM.rd(cppVar_39365);
	bool cppVar_39368 = (cppVar_39366 == 152);
	if (cppVar_39368) {
	cppVar_39364 = SCON;
	} else {
	BIT_VEC cppVar_39369;
	BIT_VEC cppVar_39370 = PC + 1;
	cppVar_39370 = (cppVar_39370 & cppMask_un_16_);
	BIT_VEC cppVar_39371 = ROM.rd(cppVar_39370);
	bool cppVar_39373 = (cppVar_39371 == 153);
	if (cppVar_39373) {
	cppVar_39369 = SBUF;
	} else {
	BIT_VEC cppVar_39374;
	BIT_VEC cppVar_39375 = PC + 1;
	cppVar_39375 = (cppVar_39375 & cppMask_un_16_);
	BIT_VEC cppVar_39376 = ROM.rd(cppVar_39375);
	bool cppVar_39378 = (cppVar_39376 == 160);
	if (cppVar_39378) {
	cppVar_39374 = P2;
	} else {
	BIT_VEC cppVar_39379;
	BIT_VEC cppVar_39380 = PC + 1;
	cppVar_39380 = (cppVar_39380 & cppMask_un_16_);
	BIT_VEC cppVar_39381 = ROM.rd(cppVar_39380);
	bool cppVar_39383 = (cppVar_39381 == 168);
	if (cppVar_39383) {
	cppVar_39379 = IE;
	} else {
	BIT_VEC cppVar_39384;
	BIT_VEC cppVar_39385 = PC + 1;
	cppVar_39385 = (cppVar_39385 & cppMask_un_16_);
	BIT_VEC cppVar_39386 = ROM.rd(cppVar_39385);
	bool cppVar_39388 = (cppVar_39386 == 176);
	if (cppVar_39388) {
	cppVar_39384 = P3;
	} else {
	BIT_VEC cppVar_39389;
	BIT_VEC cppVar_39390 = PC + 1;
	cppVar_39390 = (cppVar_39390 & cppMask_un_16_);
	BIT_VEC cppVar_39391 = ROM.rd(cppVar_39390);
	bool cppVar_39393 = (cppVar_39391 == 184);
	if (cppVar_39393) {
	cppVar_39389 = IP;
	} else {
	BIT_VEC cppVar_39394;
	BIT_VEC cppVar_39395 = PC + 1;
	cppVar_39395 = (cppVar_39395 & cppMask_un_16_);
	BIT_VEC cppVar_39396 = ROM.rd(cppVar_39395);
	bool cppVar_39398 = (cppVar_39396 == 208);
	if (cppVar_39398) {
	cppVar_39394 = PSW;
	} else {
	BIT_VEC cppVar_39399;
	BIT_VEC cppVar_39400 = PC + 1;
	cppVar_39400 = (cppVar_39400 & cppMask_un_16_);
	BIT_VEC cppVar_39401 = ROM.rd(cppVar_39400);
	bool cppVar_39403 = (cppVar_39401 == 224);
	if (cppVar_39403) {
	cppVar_39399 = ACC;
	} else {
	BIT_VEC cppVar_39404;
	BIT_VEC cppVar_39405 = PC + 1;
	cppVar_39405 = (cppVar_39405 & cppMask_un_16_);
	BIT_VEC cppVar_39406 = ROM.rd(cppVar_39405);
	bool cppVar_39408 = (cppVar_39406 == 240);
	if (cppVar_39408) {
	cppVar_39404 = B;
	} else {
	cppVar_39404 = 0;
	}
	cppVar_39399 = cppVar_39404;
	}
	cppVar_39394 = cppVar_39399;
	}
	cppVar_39389 = cppVar_39394;
	}
	cppVar_39384 = cppVar_39389;
	}
	cppVar_39379 = cppVar_39384;
	}
	cppVar_39374 = cppVar_39379;
	}
	cppVar_39369 = cppVar_39374;
	}
	cppVar_39364 = cppVar_39369;
	}
	cppVar_39359 = cppVar_39364;
	}
	cppVar_39354 = cppVar_39359;
	}
	cppVar_39349 = cppVar_39354;
	}
	cppVar_39344 = cppVar_39349;
	}
	cppVar_39339 = cppVar_39344;
	}
	cppVar_39334 = cppVar_39339;
	}
	cppVar_39329 = cppVar_39334;
	}
	cppVar_39324 = cppVar_39329;
	}
	cppVar_39319 = cppVar_39324;
	}
	cppVar_39314 = cppVar_39319;
	}
	cppVar_39309 = cppVar_39314;
	}
	cppVar_39304 = cppVar_39309;
	}
	cppVar_39295 = cppVar_39304;
	}
	BIT_VEC cppVar_39411 = PC + 2;
	cppVar_39411 = (cppVar_39411 & cppMask_un_16_);
	BIT_VEC cppVar_39412 = ROM.rd(cppVar_39411);
	BIT_VEC cppVar_39413 = cppVar_39295 ^ cppVar_39412;
	cppVar_39289 = cppVar_39413;
	} else {
	cppVar_39289 = P3;
	}
	cppVar_39285 = cppVar_39289;
	} else {
	BIT_VEC cppVar_39414;
	BIT_VEC cppVar_39415 = ROM.rd(PC);
	bool cppVar_39417 = (cppVar_39415 == 98);
	if (cppVar_39417) {
	BIT_VEC cppVar_39418;
	BIT_VEC cppVar_39420 = PC + 1;
	cppVar_39420 = (cppVar_39420 & cppMask_un_16_);
	BIT_VEC cppVar_39421 = ROM.rd(cppVar_39420);
	bool cppVar_39423 = (cppVar_39421 == 176);
	if (cppVar_39423) {
	BIT_VEC cppVar_39424;
	BIT_VEC cppVar_39425 = PC + 1;
	cppVar_39425 = (cppVar_39425 & cppMask_un_16_);
	BIT_VEC cppVar_39426 = ROM.rd(cppVar_39425);
	BIT_VEC cppVar_39427 = (cppVar_39426 >> 7) & cppMask_un_1_;
	bool cppVar_39429 = (cppVar_39427 == 0);
	if (cppVar_39429) {
	BIT_VEC cppVar_39430 = PC + 1;
	cppVar_39430 = (cppVar_39430 & cppMask_un_16_);
	BIT_VEC cppVar_39431 = ROM.rd(cppVar_39430);
	BIT_VEC cppVar_39432 = IRAM.rd(cppVar_39431);
	cppVar_39424 = cppVar_39432;
	} else {
	BIT_VEC cppVar_39433;
	BIT_VEC cppVar_39434 = PC + 1;
	cppVar_39434 = (cppVar_39434 & cppMask_un_16_);
	BIT_VEC cppVar_39435 = ROM.rd(cppVar_39434);
	bool cppVar_39437 = (cppVar_39435 == 128);
	if (cppVar_39437) {
	cppVar_39433 = P0;
	} else {
	BIT_VEC cppVar_39438;
	BIT_VEC cppVar_39439 = PC + 1;
	cppVar_39439 = (cppVar_39439 & cppMask_un_16_);
	BIT_VEC cppVar_39440 = ROM.rd(cppVar_39439);
	bool cppVar_39442 = (cppVar_39440 == 129);
	if (cppVar_39442) {
	cppVar_39438 = SP;
	} else {
	BIT_VEC cppVar_39443;
	BIT_VEC cppVar_39444 = PC + 1;
	cppVar_39444 = (cppVar_39444 & cppMask_un_16_);
	BIT_VEC cppVar_39445 = ROM.rd(cppVar_39444);
	bool cppVar_39447 = (cppVar_39445 == 130);
	if (cppVar_39447) {
	cppVar_39443 = DPL;
	} else {
	BIT_VEC cppVar_39448;
	BIT_VEC cppVar_39449 = PC + 1;
	cppVar_39449 = (cppVar_39449 & cppMask_un_16_);
	BIT_VEC cppVar_39450 = ROM.rd(cppVar_39449);
	bool cppVar_39452 = (cppVar_39450 == 131);
	if (cppVar_39452) {
	cppVar_39448 = DPH;
	} else {
	BIT_VEC cppVar_39453;
	BIT_VEC cppVar_39454 = PC + 1;
	cppVar_39454 = (cppVar_39454 & cppMask_un_16_);
	BIT_VEC cppVar_39455 = ROM.rd(cppVar_39454);
	bool cppVar_39457 = (cppVar_39455 == 135);
	if (cppVar_39457) {
	cppVar_39453 = PCON;
	} else {
	BIT_VEC cppVar_39458;
	BIT_VEC cppVar_39459 = PC + 1;
	cppVar_39459 = (cppVar_39459 & cppMask_un_16_);
	BIT_VEC cppVar_39460 = ROM.rd(cppVar_39459);
	bool cppVar_39462 = (cppVar_39460 == 136);
	if (cppVar_39462) {
	cppVar_39458 = TCON;
	} else {
	BIT_VEC cppVar_39463;
	BIT_VEC cppVar_39464 = PC + 1;
	cppVar_39464 = (cppVar_39464 & cppMask_un_16_);
	BIT_VEC cppVar_39465 = ROM.rd(cppVar_39464);
	bool cppVar_39467 = (cppVar_39465 == 137);
	if (cppVar_39467) {
	cppVar_39463 = TMOD;
	} else {
	BIT_VEC cppVar_39468;
	BIT_VEC cppVar_39469 = PC + 1;
	cppVar_39469 = (cppVar_39469 & cppMask_un_16_);
	BIT_VEC cppVar_39470 = ROM.rd(cppVar_39469);
	bool cppVar_39472 = (cppVar_39470 == 138);
	if (cppVar_39472) {
	cppVar_39468 = TL0;
	} else {
	BIT_VEC cppVar_39473;
	BIT_VEC cppVar_39474 = PC + 1;
	cppVar_39474 = (cppVar_39474 & cppMask_un_16_);
	BIT_VEC cppVar_39475 = ROM.rd(cppVar_39474);
	bool cppVar_39477 = (cppVar_39475 == 140);
	if (cppVar_39477) {
	cppVar_39473 = TH0;
	} else {
	BIT_VEC cppVar_39478;
	BIT_VEC cppVar_39479 = PC + 1;
	cppVar_39479 = (cppVar_39479 & cppMask_un_16_);
	BIT_VEC cppVar_39480 = ROM.rd(cppVar_39479);
	bool cppVar_39482 = (cppVar_39480 == 139);
	if (cppVar_39482) {
	cppVar_39478 = TL1;
	} else {
	BIT_VEC cppVar_39483;
	BIT_VEC cppVar_39484 = PC + 1;
	cppVar_39484 = (cppVar_39484 & cppMask_un_16_);
	BIT_VEC cppVar_39485 = ROM.rd(cppVar_39484);
	bool cppVar_39487 = (cppVar_39485 == 141);
	if (cppVar_39487) {
	cppVar_39483 = TH1;
	} else {
	BIT_VEC cppVar_39488;
	BIT_VEC cppVar_39489 = PC + 1;
	cppVar_39489 = (cppVar_39489 & cppMask_un_16_);
	BIT_VEC cppVar_39490 = ROM.rd(cppVar_39489);
	bool cppVar_39492 = (cppVar_39490 == 144);
	if (cppVar_39492) {
	cppVar_39488 = P1;
	} else {
	BIT_VEC cppVar_39493;
	BIT_VEC cppVar_39494 = PC + 1;
	cppVar_39494 = (cppVar_39494 & cppMask_un_16_);
	BIT_VEC cppVar_39495 = ROM.rd(cppVar_39494);
	bool cppVar_39497 = (cppVar_39495 == 152);
	if (cppVar_39497) {
	cppVar_39493 = SCON;
	} else {
	BIT_VEC cppVar_39498;
	BIT_VEC cppVar_39499 = PC + 1;
	cppVar_39499 = (cppVar_39499 & cppMask_un_16_);
	BIT_VEC cppVar_39500 = ROM.rd(cppVar_39499);
	bool cppVar_39502 = (cppVar_39500 == 153);
	if (cppVar_39502) {
	cppVar_39498 = SBUF;
	} else {
	BIT_VEC cppVar_39503;
	BIT_VEC cppVar_39504 = PC + 1;
	cppVar_39504 = (cppVar_39504 & cppMask_un_16_);
	BIT_VEC cppVar_39505 = ROM.rd(cppVar_39504);
	bool cppVar_39507 = (cppVar_39505 == 160);
	if (cppVar_39507) {
	cppVar_39503 = P2;
	} else {
	BIT_VEC cppVar_39508;
	BIT_VEC cppVar_39509 = PC + 1;
	cppVar_39509 = (cppVar_39509 & cppMask_un_16_);
	BIT_VEC cppVar_39510 = ROM.rd(cppVar_39509);
	bool cppVar_39512 = (cppVar_39510 == 168);
	if (cppVar_39512) {
	cppVar_39508 = IE;
	} else {
	BIT_VEC cppVar_39513;
	BIT_VEC cppVar_39514 = PC + 1;
	cppVar_39514 = (cppVar_39514 & cppMask_un_16_);
	BIT_VEC cppVar_39515 = ROM.rd(cppVar_39514);
	bool cppVar_39517 = (cppVar_39515 == 176);
	if (cppVar_39517) {
	cppVar_39513 = P3;
	} else {
	BIT_VEC cppVar_39518;
	BIT_VEC cppVar_39519 = PC + 1;
	cppVar_39519 = (cppVar_39519 & cppMask_un_16_);
	BIT_VEC cppVar_39520 = ROM.rd(cppVar_39519);
	bool cppVar_39522 = (cppVar_39520 == 184);
	if (cppVar_39522) {
	cppVar_39518 = IP;
	} else {
	BIT_VEC cppVar_39523;
	BIT_VEC cppVar_39524 = PC + 1;
	cppVar_39524 = (cppVar_39524 & cppMask_un_16_);
	BIT_VEC cppVar_39525 = ROM.rd(cppVar_39524);
	bool cppVar_39527 = (cppVar_39525 == 208);
	if (cppVar_39527) {
	cppVar_39523 = PSW;
	} else {
	BIT_VEC cppVar_39528;
	BIT_VEC cppVar_39529 = PC + 1;
	cppVar_39529 = (cppVar_39529 & cppMask_un_16_);
	BIT_VEC cppVar_39530 = ROM.rd(cppVar_39529);
	bool cppVar_39532 = (cppVar_39530 == 224);
	if (cppVar_39532) {
	cppVar_39528 = ACC;
	} else {
	BIT_VEC cppVar_39533;
	BIT_VEC cppVar_39534 = PC + 1;
	cppVar_39534 = (cppVar_39534 & cppMask_un_16_);
	BIT_VEC cppVar_39535 = ROM.rd(cppVar_39534);
	bool cppVar_39537 = (cppVar_39535 == 240);
	if (cppVar_39537) {
	cppVar_39533 = B;
	} else {
	cppVar_39533 = 0;
	}
	cppVar_39528 = cppVar_39533;
	}
	cppVar_39523 = cppVar_39528;
	}
	cppVar_39518 = cppVar_39523;
	}
	cppVar_39513 = cppVar_39518;
	}
	cppVar_39508 = cppVar_39513;
	}
	cppVar_39503 = cppVar_39508;
	}
	cppVar_39498 = cppVar_39503;
	}
	cppVar_39493 = cppVar_39498;
	}
	cppVar_39488 = cppVar_39493;
	}
	cppVar_39483 = cppVar_39488;
	}
	cppVar_39478 = cppVar_39483;
	}
	cppVar_39473 = cppVar_39478;
	}
	cppVar_39468 = cppVar_39473;
	}
	cppVar_39463 = cppVar_39468;
	}
	cppVar_39458 = cppVar_39463;
	}
	cppVar_39453 = cppVar_39458;
	}
	cppVar_39448 = cppVar_39453;
	}
	cppVar_39443 = cppVar_39448;
	}
	cppVar_39438 = cppVar_39443;
	}
	cppVar_39433 = cppVar_39438;
	}
	cppVar_39424 = cppVar_39433;
	}
	BIT_VEC cppVar_39539 = cppVar_39424 ^ ACC;
	cppVar_39418 = cppVar_39539;
	} else {
	cppVar_39418 = P3;
	}
	cppVar_39414 = cppVar_39418;
	} else {
	BIT_VEC cppVar_39540;
	BIT_VEC cppVar_39541 = ROM.rd(PC);
	bool cppVar_39543 = (cppVar_39541 == 83);
	if (cppVar_39543) {
	BIT_VEC cppVar_39544;
	BIT_VEC cppVar_39546 = PC + 1;
	cppVar_39546 = (cppVar_39546 & cppMask_un_16_);
	BIT_VEC cppVar_39547 = ROM.rd(cppVar_39546);
	bool cppVar_39549 = (cppVar_39547 == 176);
	if (cppVar_39549) {
	BIT_VEC cppVar_39550;
	BIT_VEC cppVar_39551 = PC + 1;
	cppVar_39551 = (cppVar_39551 & cppMask_un_16_);
	BIT_VEC cppVar_39552 = ROM.rd(cppVar_39551);
	BIT_VEC cppVar_39553 = (cppVar_39552 >> 7) & cppMask_un_1_;
	bool cppVar_39555 = (cppVar_39553 == 0);
	if (cppVar_39555) {
	BIT_VEC cppVar_39556 = PC + 1;
	cppVar_39556 = (cppVar_39556 & cppMask_un_16_);
	BIT_VEC cppVar_39557 = ROM.rd(cppVar_39556);
	BIT_VEC cppVar_39558 = IRAM.rd(cppVar_39557);
	cppVar_39550 = cppVar_39558;
	} else {
	BIT_VEC cppVar_39559;
	BIT_VEC cppVar_39560 = PC + 1;
	cppVar_39560 = (cppVar_39560 & cppMask_un_16_);
	BIT_VEC cppVar_39561 = ROM.rd(cppVar_39560);
	bool cppVar_39563 = (cppVar_39561 == 128);
	if (cppVar_39563) {
	cppVar_39559 = P0;
	} else {
	BIT_VEC cppVar_39564;
	BIT_VEC cppVar_39565 = PC + 1;
	cppVar_39565 = (cppVar_39565 & cppMask_un_16_);
	BIT_VEC cppVar_39566 = ROM.rd(cppVar_39565);
	bool cppVar_39568 = (cppVar_39566 == 129);
	if (cppVar_39568) {
	cppVar_39564 = SP;
	} else {
	BIT_VEC cppVar_39569;
	BIT_VEC cppVar_39570 = PC + 1;
	cppVar_39570 = (cppVar_39570 & cppMask_un_16_);
	BIT_VEC cppVar_39571 = ROM.rd(cppVar_39570);
	bool cppVar_39573 = (cppVar_39571 == 130);
	if (cppVar_39573) {
	cppVar_39569 = DPL;
	} else {
	BIT_VEC cppVar_39574;
	BIT_VEC cppVar_39575 = PC + 1;
	cppVar_39575 = (cppVar_39575 & cppMask_un_16_);
	BIT_VEC cppVar_39576 = ROM.rd(cppVar_39575);
	bool cppVar_39578 = (cppVar_39576 == 131);
	if (cppVar_39578) {
	cppVar_39574 = DPH;
	} else {
	BIT_VEC cppVar_39579;
	BIT_VEC cppVar_39580 = PC + 1;
	cppVar_39580 = (cppVar_39580 & cppMask_un_16_);
	BIT_VEC cppVar_39581 = ROM.rd(cppVar_39580);
	bool cppVar_39583 = (cppVar_39581 == 135);
	if (cppVar_39583) {
	cppVar_39579 = PCON;
	} else {
	BIT_VEC cppVar_39584;
	BIT_VEC cppVar_39585 = PC + 1;
	cppVar_39585 = (cppVar_39585 & cppMask_un_16_);
	BIT_VEC cppVar_39586 = ROM.rd(cppVar_39585);
	bool cppVar_39588 = (cppVar_39586 == 136);
	if (cppVar_39588) {
	cppVar_39584 = TCON;
	} else {
	BIT_VEC cppVar_39589;
	BIT_VEC cppVar_39590 = PC + 1;
	cppVar_39590 = (cppVar_39590 & cppMask_un_16_);
	BIT_VEC cppVar_39591 = ROM.rd(cppVar_39590);
	bool cppVar_39593 = (cppVar_39591 == 137);
	if (cppVar_39593) {
	cppVar_39589 = TMOD;
	} else {
	BIT_VEC cppVar_39594;
	BIT_VEC cppVar_39595 = PC + 1;
	cppVar_39595 = (cppVar_39595 & cppMask_un_16_);
	BIT_VEC cppVar_39596 = ROM.rd(cppVar_39595);
	bool cppVar_39598 = (cppVar_39596 == 138);
	if (cppVar_39598) {
	cppVar_39594 = TL0;
	} else {
	BIT_VEC cppVar_39599;
	BIT_VEC cppVar_39600 = PC + 1;
	cppVar_39600 = (cppVar_39600 & cppMask_un_16_);
	BIT_VEC cppVar_39601 = ROM.rd(cppVar_39600);
	bool cppVar_39603 = (cppVar_39601 == 140);
	if (cppVar_39603) {
	cppVar_39599 = TH0;
	} else {
	BIT_VEC cppVar_39604;
	BIT_VEC cppVar_39605 = PC + 1;
	cppVar_39605 = (cppVar_39605 & cppMask_un_16_);
	BIT_VEC cppVar_39606 = ROM.rd(cppVar_39605);
	bool cppVar_39608 = (cppVar_39606 == 139);
	if (cppVar_39608) {
	cppVar_39604 = TL1;
	} else {
	BIT_VEC cppVar_39609;
	BIT_VEC cppVar_39610 = PC + 1;
	cppVar_39610 = (cppVar_39610 & cppMask_un_16_);
	BIT_VEC cppVar_39611 = ROM.rd(cppVar_39610);
	bool cppVar_39613 = (cppVar_39611 == 141);
	if (cppVar_39613) {
	cppVar_39609 = TH1;
	} else {
	BIT_VEC cppVar_39614;
	BIT_VEC cppVar_39615 = PC + 1;
	cppVar_39615 = (cppVar_39615 & cppMask_un_16_);
	BIT_VEC cppVar_39616 = ROM.rd(cppVar_39615);
	bool cppVar_39618 = (cppVar_39616 == 144);
	if (cppVar_39618) {
	cppVar_39614 = P1;
	} else {
	BIT_VEC cppVar_39619;
	BIT_VEC cppVar_39620 = PC + 1;
	cppVar_39620 = (cppVar_39620 & cppMask_un_16_);
	BIT_VEC cppVar_39621 = ROM.rd(cppVar_39620);
	bool cppVar_39623 = (cppVar_39621 == 152);
	if (cppVar_39623) {
	cppVar_39619 = SCON;
	} else {
	BIT_VEC cppVar_39624;
	BIT_VEC cppVar_39625 = PC + 1;
	cppVar_39625 = (cppVar_39625 & cppMask_un_16_);
	BIT_VEC cppVar_39626 = ROM.rd(cppVar_39625);
	bool cppVar_39628 = (cppVar_39626 == 153);
	if (cppVar_39628) {
	cppVar_39624 = SBUF;
	} else {
	BIT_VEC cppVar_39629;
	BIT_VEC cppVar_39630 = PC + 1;
	cppVar_39630 = (cppVar_39630 & cppMask_un_16_);
	BIT_VEC cppVar_39631 = ROM.rd(cppVar_39630);
	bool cppVar_39633 = (cppVar_39631 == 160);
	if (cppVar_39633) {
	cppVar_39629 = P2;
	} else {
	BIT_VEC cppVar_39634;
	BIT_VEC cppVar_39635 = PC + 1;
	cppVar_39635 = (cppVar_39635 & cppMask_un_16_);
	BIT_VEC cppVar_39636 = ROM.rd(cppVar_39635);
	bool cppVar_39638 = (cppVar_39636 == 168);
	if (cppVar_39638) {
	cppVar_39634 = IE;
	} else {
	BIT_VEC cppVar_39639;
	BIT_VEC cppVar_39640 = PC + 1;
	cppVar_39640 = (cppVar_39640 & cppMask_un_16_);
	BIT_VEC cppVar_39641 = ROM.rd(cppVar_39640);
	bool cppVar_39643 = (cppVar_39641 == 176);
	if (cppVar_39643) {
	cppVar_39639 = P3;
	} else {
	BIT_VEC cppVar_39644;
	BIT_VEC cppVar_39645 = PC + 1;
	cppVar_39645 = (cppVar_39645 & cppMask_un_16_);
	BIT_VEC cppVar_39646 = ROM.rd(cppVar_39645);
	bool cppVar_39648 = (cppVar_39646 == 184);
	if (cppVar_39648) {
	cppVar_39644 = IP;
	} else {
	BIT_VEC cppVar_39649;
	BIT_VEC cppVar_39650 = PC + 1;
	cppVar_39650 = (cppVar_39650 & cppMask_un_16_);
	BIT_VEC cppVar_39651 = ROM.rd(cppVar_39650);
	bool cppVar_39653 = (cppVar_39651 == 208);
	if (cppVar_39653) {
	cppVar_39649 = PSW;
	} else {
	BIT_VEC cppVar_39654;
	BIT_VEC cppVar_39655 = PC + 1;
	cppVar_39655 = (cppVar_39655 & cppMask_un_16_);
	BIT_VEC cppVar_39656 = ROM.rd(cppVar_39655);
	bool cppVar_39658 = (cppVar_39656 == 224);
	if (cppVar_39658) {
	cppVar_39654 = ACC;
	} else {
	BIT_VEC cppVar_39659;
	BIT_VEC cppVar_39660 = PC + 1;
	cppVar_39660 = (cppVar_39660 & cppMask_un_16_);
	BIT_VEC cppVar_39661 = ROM.rd(cppVar_39660);
	bool cppVar_39663 = (cppVar_39661 == 240);
	if (cppVar_39663) {
	cppVar_39659 = B;
	} else {
	cppVar_39659 = 0;
	}
	cppVar_39654 = cppVar_39659;
	}
	cppVar_39649 = cppVar_39654;
	}
	cppVar_39644 = cppVar_39649;
	}
	cppVar_39639 = cppVar_39644;
	}
	cppVar_39634 = cppVar_39639;
	}
	cppVar_39629 = cppVar_39634;
	}
	cppVar_39624 = cppVar_39629;
	}
	cppVar_39619 = cppVar_39624;
	}
	cppVar_39614 = cppVar_39619;
	}
	cppVar_39609 = cppVar_39614;
	}
	cppVar_39604 = cppVar_39609;
	}
	cppVar_39599 = cppVar_39604;
	}
	cppVar_39594 = cppVar_39599;
	}
	cppVar_39589 = cppVar_39594;
	}
	cppVar_39584 = cppVar_39589;
	}
	cppVar_39579 = cppVar_39584;
	}
	cppVar_39574 = cppVar_39579;
	}
	cppVar_39569 = cppVar_39574;
	}
	cppVar_39564 = cppVar_39569;
	}
	cppVar_39559 = cppVar_39564;
	}
	cppVar_39550 = cppVar_39559;
	}
	BIT_VEC cppVar_39666 = PC + 2;
	cppVar_39666 = (cppVar_39666 & cppMask_un_16_);
	BIT_VEC cppVar_39667 = ROM.rd(cppVar_39666);
	BIT_VEC cppVar_39668 = cppVar_39550 & cppVar_39667;
	cppVar_39544 = cppVar_39668;
	} else {
	cppVar_39544 = P3;
	}
	cppVar_39540 = cppVar_39544;
	} else {
	BIT_VEC cppVar_39669;
	BIT_VEC cppVar_39670 = ROM.rd(PC);
	bool cppVar_39672 = (cppVar_39670 == 82);
	if (cppVar_39672) {
	BIT_VEC cppVar_39673;
	BIT_VEC cppVar_39675 = PC + 1;
	cppVar_39675 = (cppVar_39675 & cppMask_un_16_);
	BIT_VEC cppVar_39676 = ROM.rd(cppVar_39675);
	bool cppVar_39678 = (cppVar_39676 == 176);
	if (cppVar_39678) {
	BIT_VEC cppVar_39679;
	BIT_VEC cppVar_39680 = PC + 1;
	cppVar_39680 = (cppVar_39680 & cppMask_un_16_);
	BIT_VEC cppVar_39681 = ROM.rd(cppVar_39680);
	BIT_VEC cppVar_39682 = (cppVar_39681 >> 7) & cppMask_un_1_;
	bool cppVar_39684 = (cppVar_39682 == 0);
	if (cppVar_39684) {
	BIT_VEC cppVar_39685 = PC + 1;
	cppVar_39685 = (cppVar_39685 & cppMask_un_16_);
	BIT_VEC cppVar_39686 = ROM.rd(cppVar_39685);
	BIT_VEC cppVar_39687 = IRAM.rd(cppVar_39686);
	cppVar_39679 = cppVar_39687;
	} else {
	BIT_VEC cppVar_39688;
	BIT_VEC cppVar_39689 = PC + 1;
	cppVar_39689 = (cppVar_39689 & cppMask_un_16_);
	BIT_VEC cppVar_39690 = ROM.rd(cppVar_39689);
	bool cppVar_39692 = (cppVar_39690 == 128);
	if (cppVar_39692) {
	cppVar_39688 = P0;
	} else {
	BIT_VEC cppVar_39693;
	BIT_VEC cppVar_39694 = PC + 1;
	cppVar_39694 = (cppVar_39694 & cppMask_un_16_);
	BIT_VEC cppVar_39695 = ROM.rd(cppVar_39694);
	bool cppVar_39697 = (cppVar_39695 == 129);
	if (cppVar_39697) {
	cppVar_39693 = SP;
	} else {
	BIT_VEC cppVar_39698;
	BIT_VEC cppVar_39699 = PC + 1;
	cppVar_39699 = (cppVar_39699 & cppMask_un_16_);
	BIT_VEC cppVar_39700 = ROM.rd(cppVar_39699);
	bool cppVar_39702 = (cppVar_39700 == 130);
	if (cppVar_39702) {
	cppVar_39698 = DPL;
	} else {
	BIT_VEC cppVar_39703;
	BIT_VEC cppVar_39704 = PC + 1;
	cppVar_39704 = (cppVar_39704 & cppMask_un_16_);
	BIT_VEC cppVar_39705 = ROM.rd(cppVar_39704);
	bool cppVar_39707 = (cppVar_39705 == 131);
	if (cppVar_39707) {
	cppVar_39703 = DPH;
	} else {
	BIT_VEC cppVar_39708;
	BIT_VEC cppVar_39709 = PC + 1;
	cppVar_39709 = (cppVar_39709 & cppMask_un_16_);
	BIT_VEC cppVar_39710 = ROM.rd(cppVar_39709);
	bool cppVar_39712 = (cppVar_39710 == 135);
	if (cppVar_39712) {
	cppVar_39708 = PCON;
	} else {
	BIT_VEC cppVar_39713;
	BIT_VEC cppVar_39714 = PC + 1;
	cppVar_39714 = (cppVar_39714 & cppMask_un_16_);
	BIT_VEC cppVar_39715 = ROM.rd(cppVar_39714);
	bool cppVar_39717 = (cppVar_39715 == 136);
	if (cppVar_39717) {
	cppVar_39713 = TCON;
	} else {
	BIT_VEC cppVar_39718;
	BIT_VEC cppVar_39719 = PC + 1;
	cppVar_39719 = (cppVar_39719 & cppMask_un_16_);
	BIT_VEC cppVar_39720 = ROM.rd(cppVar_39719);
	bool cppVar_39722 = (cppVar_39720 == 137);
	if (cppVar_39722) {
	cppVar_39718 = TMOD;
	} else {
	BIT_VEC cppVar_39723;
	BIT_VEC cppVar_39724 = PC + 1;
	cppVar_39724 = (cppVar_39724 & cppMask_un_16_);
	BIT_VEC cppVar_39725 = ROM.rd(cppVar_39724);
	bool cppVar_39727 = (cppVar_39725 == 138);
	if (cppVar_39727) {
	cppVar_39723 = TL0;
	} else {
	BIT_VEC cppVar_39728;
	BIT_VEC cppVar_39729 = PC + 1;
	cppVar_39729 = (cppVar_39729 & cppMask_un_16_);
	BIT_VEC cppVar_39730 = ROM.rd(cppVar_39729);
	bool cppVar_39732 = (cppVar_39730 == 140);
	if (cppVar_39732) {
	cppVar_39728 = TH0;
	} else {
	BIT_VEC cppVar_39733;
	BIT_VEC cppVar_39734 = PC + 1;
	cppVar_39734 = (cppVar_39734 & cppMask_un_16_);
	BIT_VEC cppVar_39735 = ROM.rd(cppVar_39734);
	bool cppVar_39737 = (cppVar_39735 == 139);
	if (cppVar_39737) {
	cppVar_39733 = TL1;
	} else {
	BIT_VEC cppVar_39738;
	BIT_VEC cppVar_39739 = PC + 1;
	cppVar_39739 = (cppVar_39739 & cppMask_un_16_);
	BIT_VEC cppVar_39740 = ROM.rd(cppVar_39739);
	bool cppVar_39742 = (cppVar_39740 == 141);
	if (cppVar_39742) {
	cppVar_39738 = TH1;
	} else {
	BIT_VEC cppVar_39743;
	BIT_VEC cppVar_39744 = PC + 1;
	cppVar_39744 = (cppVar_39744 & cppMask_un_16_);
	BIT_VEC cppVar_39745 = ROM.rd(cppVar_39744);
	bool cppVar_39747 = (cppVar_39745 == 144);
	if (cppVar_39747) {
	cppVar_39743 = P1;
	} else {
	BIT_VEC cppVar_39748;
	BIT_VEC cppVar_39749 = PC + 1;
	cppVar_39749 = (cppVar_39749 & cppMask_un_16_);
	BIT_VEC cppVar_39750 = ROM.rd(cppVar_39749);
	bool cppVar_39752 = (cppVar_39750 == 152);
	if (cppVar_39752) {
	cppVar_39748 = SCON;
	} else {
	BIT_VEC cppVar_39753;
	BIT_VEC cppVar_39754 = PC + 1;
	cppVar_39754 = (cppVar_39754 & cppMask_un_16_);
	BIT_VEC cppVar_39755 = ROM.rd(cppVar_39754);
	bool cppVar_39757 = (cppVar_39755 == 153);
	if (cppVar_39757) {
	cppVar_39753 = SBUF;
	} else {
	BIT_VEC cppVar_39758;
	BIT_VEC cppVar_39759 = PC + 1;
	cppVar_39759 = (cppVar_39759 & cppMask_un_16_);
	BIT_VEC cppVar_39760 = ROM.rd(cppVar_39759);
	bool cppVar_39762 = (cppVar_39760 == 160);
	if (cppVar_39762) {
	cppVar_39758 = P2;
	} else {
	BIT_VEC cppVar_39763;
	BIT_VEC cppVar_39764 = PC + 1;
	cppVar_39764 = (cppVar_39764 & cppMask_un_16_);
	BIT_VEC cppVar_39765 = ROM.rd(cppVar_39764);
	bool cppVar_39767 = (cppVar_39765 == 168);
	if (cppVar_39767) {
	cppVar_39763 = IE;
	} else {
	BIT_VEC cppVar_39768;
	BIT_VEC cppVar_39769 = PC + 1;
	cppVar_39769 = (cppVar_39769 & cppMask_un_16_);
	BIT_VEC cppVar_39770 = ROM.rd(cppVar_39769);
	bool cppVar_39772 = (cppVar_39770 == 176);
	if (cppVar_39772) {
	cppVar_39768 = P3;
	} else {
	BIT_VEC cppVar_39773;
	BIT_VEC cppVar_39774 = PC + 1;
	cppVar_39774 = (cppVar_39774 & cppMask_un_16_);
	BIT_VEC cppVar_39775 = ROM.rd(cppVar_39774);
	bool cppVar_39777 = (cppVar_39775 == 184);
	if (cppVar_39777) {
	cppVar_39773 = IP;
	} else {
	BIT_VEC cppVar_39778;
	BIT_VEC cppVar_39779 = PC + 1;
	cppVar_39779 = (cppVar_39779 & cppMask_un_16_);
	BIT_VEC cppVar_39780 = ROM.rd(cppVar_39779);
	bool cppVar_39782 = (cppVar_39780 == 208);
	if (cppVar_39782) {
	cppVar_39778 = PSW;
	} else {
	BIT_VEC cppVar_39783;
	BIT_VEC cppVar_39784 = PC + 1;
	cppVar_39784 = (cppVar_39784 & cppMask_un_16_);
	BIT_VEC cppVar_39785 = ROM.rd(cppVar_39784);
	bool cppVar_39787 = (cppVar_39785 == 224);
	if (cppVar_39787) {
	cppVar_39783 = ACC;
	} else {
	BIT_VEC cppVar_39788;
	BIT_VEC cppVar_39789 = PC + 1;
	cppVar_39789 = (cppVar_39789 & cppMask_un_16_);
	BIT_VEC cppVar_39790 = ROM.rd(cppVar_39789);
	bool cppVar_39792 = (cppVar_39790 == 240);
	if (cppVar_39792) {
	cppVar_39788 = B;
	} else {
	cppVar_39788 = 0;
	}
	cppVar_39783 = cppVar_39788;
	}
	cppVar_39778 = cppVar_39783;
	}
	cppVar_39773 = cppVar_39778;
	}
	cppVar_39768 = cppVar_39773;
	}
	cppVar_39763 = cppVar_39768;
	}
	cppVar_39758 = cppVar_39763;
	}
	cppVar_39753 = cppVar_39758;
	}
	cppVar_39748 = cppVar_39753;
	}
	cppVar_39743 = cppVar_39748;
	}
	cppVar_39738 = cppVar_39743;
	}
	cppVar_39733 = cppVar_39738;
	}
	cppVar_39728 = cppVar_39733;
	}
	cppVar_39723 = cppVar_39728;
	}
	cppVar_39718 = cppVar_39723;
	}
	cppVar_39713 = cppVar_39718;
	}
	cppVar_39708 = cppVar_39713;
	}
	cppVar_39703 = cppVar_39708;
	}
	cppVar_39698 = cppVar_39703;
	}
	cppVar_39693 = cppVar_39698;
	}
	cppVar_39688 = cppVar_39693;
	}
	cppVar_39679 = cppVar_39688;
	}
	BIT_VEC cppVar_39794 = cppVar_39679 & ACC;
	cppVar_39673 = cppVar_39794;
	} else {
	cppVar_39673 = P3;
	}
	cppVar_39669 = cppVar_39673;
	} else {
	BIT_VEC cppVar_39795;
	BIT_VEC cppVar_39796 = ROM.rd(PC);
	bool cppVar_39798 = (cppVar_39796 == 67);
	if (cppVar_39798) {
	BIT_VEC cppVar_39799;
	BIT_VEC cppVar_39801 = PC + 1;
	cppVar_39801 = (cppVar_39801 & cppMask_un_16_);
	BIT_VEC cppVar_39802 = ROM.rd(cppVar_39801);
	bool cppVar_39804 = (cppVar_39802 == 176);
	if (cppVar_39804) {
	BIT_VEC cppVar_39805;
	BIT_VEC cppVar_39806 = PC + 1;
	cppVar_39806 = (cppVar_39806 & cppMask_un_16_);
	BIT_VEC cppVar_39807 = ROM.rd(cppVar_39806);
	BIT_VEC cppVar_39808 = (cppVar_39807 >> 7) & cppMask_un_1_;
	bool cppVar_39810 = (cppVar_39808 == 0);
	if (cppVar_39810) {
	BIT_VEC cppVar_39811 = PC + 1;
	cppVar_39811 = (cppVar_39811 & cppMask_un_16_);
	BIT_VEC cppVar_39812 = ROM.rd(cppVar_39811);
	BIT_VEC cppVar_39813 = IRAM.rd(cppVar_39812);
	cppVar_39805 = cppVar_39813;
	} else {
	BIT_VEC cppVar_39814;
	BIT_VEC cppVar_39815 = PC + 1;
	cppVar_39815 = (cppVar_39815 & cppMask_un_16_);
	BIT_VEC cppVar_39816 = ROM.rd(cppVar_39815);
	bool cppVar_39818 = (cppVar_39816 == 128);
	if (cppVar_39818) {
	cppVar_39814 = P0;
	} else {
	BIT_VEC cppVar_39819;
	BIT_VEC cppVar_39820 = PC + 1;
	cppVar_39820 = (cppVar_39820 & cppMask_un_16_);
	BIT_VEC cppVar_39821 = ROM.rd(cppVar_39820);
	bool cppVar_39823 = (cppVar_39821 == 129);
	if (cppVar_39823) {
	cppVar_39819 = SP;
	} else {
	BIT_VEC cppVar_39824;
	BIT_VEC cppVar_39825 = PC + 1;
	cppVar_39825 = (cppVar_39825 & cppMask_un_16_);
	BIT_VEC cppVar_39826 = ROM.rd(cppVar_39825);
	bool cppVar_39828 = (cppVar_39826 == 130);
	if (cppVar_39828) {
	cppVar_39824 = DPL;
	} else {
	BIT_VEC cppVar_39829;
	BIT_VEC cppVar_39830 = PC + 1;
	cppVar_39830 = (cppVar_39830 & cppMask_un_16_);
	BIT_VEC cppVar_39831 = ROM.rd(cppVar_39830);
	bool cppVar_39833 = (cppVar_39831 == 131);
	if (cppVar_39833) {
	cppVar_39829 = DPH;
	} else {
	BIT_VEC cppVar_39834;
	BIT_VEC cppVar_39835 = PC + 1;
	cppVar_39835 = (cppVar_39835 & cppMask_un_16_);
	BIT_VEC cppVar_39836 = ROM.rd(cppVar_39835);
	bool cppVar_39838 = (cppVar_39836 == 135);
	if (cppVar_39838) {
	cppVar_39834 = PCON;
	} else {
	BIT_VEC cppVar_39839;
	BIT_VEC cppVar_39840 = PC + 1;
	cppVar_39840 = (cppVar_39840 & cppMask_un_16_);
	BIT_VEC cppVar_39841 = ROM.rd(cppVar_39840);
	bool cppVar_39843 = (cppVar_39841 == 136);
	if (cppVar_39843) {
	cppVar_39839 = TCON;
	} else {
	BIT_VEC cppVar_39844;
	BIT_VEC cppVar_39845 = PC + 1;
	cppVar_39845 = (cppVar_39845 & cppMask_un_16_);
	BIT_VEC cppVar_39846 = ROM.rd(cppVar_39845);
	bool cppVar_39848 = (cppVar_39846 == 137);
	if (cppVar_39848) {
	cppVar_39844 = TMOD;
	} else {
	BIT_VEC cppVar_39849;
	BIT_VEC cppVar_39850 = PC + 1;
	cppVar_39850 = (cppVar_39850 & cppMask_un_16_);
	BIT_VEC cppVar_39851 = ROM.rd(cppVar_39850);
	bool cppVar_39853 = (cppVar_39851 == 138);
	if (cppVar_39853) {
	cppVar_39849 = TL0;
	} else {
	BIT_VEC cppVar_39854;
	BIT_VEC cppVar_39855 = PC + 1;
	cppVar_39855 = (cppVar_39855 & cppMask_un_16_);
	BIT_VEC cppVar_39856 = ROM.rd(cppVar_39855);
	bool cppVar_39858 = (cppVar_39856 == 140);
	if (cppVar_39858) {
	cppVar_39854 = TH0;
	} else {
	BIT_VEC cppVar_39859;
	BIT_VEC cppVar_39860 = PC + 1;
	cppVar_39860 = (cppVar_39860 & cppMask_un_16_);
	BIT_VEC cppVar_39861 = ROM.rd(cppVar_39860);
	bool cppVar_39863 = (cppVar_39861 == 139);
	if (cppVar_39863) {
	cppVar_39859 = TL1;
	} else {
	BIT_VEC cppVar_39864;
	BIT_VEC cppVar_39865 = PC + 1;
	cppVar_39865 = (cppVar_39865 & cppMask_un_16_);
	BIT_VEC cppVar_39866 = ROM.rd(cppVar_39865);
	bool cppVar_39868 = (cppVar_39866 == 141);
	if (cppVar_39868) {
	cppVar_39864 = TH1;
	} else {
	BIT_VEC cppVar_39869;
	BIT_VEC cppVar_39870 = PC + 1;
	cppVar_39870 = (cppVar_39870 & cppMask_un_16_);
	BIT_VEC cppVar_39871 = ROM.rd(cppVar_39870);
	bool cppVar_39873 = (cppVar_39871 == 144);
	if (cppVar_39873) {
	cppVar_39869 = P1;
	} else {
	BIT_VEC cppVar_39874;
	BIT_VEC cppVar_39875 = PC + 1;
	cppVar_39875 = (cppVar_39875 & cppMask_un_16_);
	BIT_VEC cppVar_39876 = ROM.rd(cppVar_39875);
	bool cppVar_39878 = (cppVar_39876 == 152);
	if (cppVar_39878) {
	cppVar_39874 = SCON;
	} else {
	BIT_VEC cppVar_39879;
	BIT_VEC cppVar_39880 = PC + 1;
	cppVar_39880 = (cppVar_39880 & cppMask_un_16_);
	BIT_VEC cppVar_39881 = ROM.rd(cppVar_39880);
	bool cppVar_39883 = (cppVar_39881 == 153);
	if (cppVar_39883) {
	cppVar_39879 = SBUF;
	} else {
	BIT_VEC cppVar_39884;
	BIT_VEC cppVar_39885 = PC + 1;
	cppVar_39885 = (cppVar_39885 & cppMask_un_16_);
	BIT_VEC cppVar_39886 = ROM.rd(cppVar_39885);
	bool cppVar_39888 = (cppVar_39886 == 160);
	if (cppVar_39888) {
	cppVar_39884 = P2;
	} else {
	BIT_VEC cppVar_39889;
	BIT_VEC cppVar_39890 = PC + 1;
	cppVar_39890 = (cppVar_39890 & cppMask_un_16_);
	BIT_VEC cppVar_39891 = ROM.rd(cppVar_39890);
	bool cppVar_39893 = (cppVar_39891 == 168);
	if (cppVar_39893) {
	cppVar_39889 = IE;
	} else {
	BIT_VEC cppVar_39894;
	BIT_VEC cppVar_39895 = PC + 1;
	cppVar_39895 = (cppVar_39895 & cppMask_un_16_);
	BIT_VEC cppVar_39896 = ROM.rd(cppVar_39895);
	bool cppVar_39898 = (cppVar_39896 == 176);
	if (cppVar_39898) {
	cppVar_39894 = P3;
	} else {
	BIT_VEC cppVar_39899;
	BIT_VEC cppVar_39900 = PC + 1;
	cppVar_39900 = (cppVar_39900 & cppMask_un_16_);
	BIT_VEC cppVar_39901 = ROM.rd(cppVar_39900);
	bool cppVar_39903 = (cppVar_39901 == 184);
	if (cppVar_39903) {
	cppVar_39899 = IP;
	} else {
	BIT_VEC cppVar_39904;
	BIT_VEC cppVar_39905 = PC + 1;
	cppVar_39905 = (cppVar_39905 & cppMask_un_16_);
	BIT_VEC cppVar_39906 = ROM.rd(cppVar_39905);
	bool cppVar_39908 = (cppVar_39906 == 208);
	if (cppVar_39908) {
	cppVar_39904 = PSW;
	} else {
	BIT_VEC cppVar_39909;
	BIT_VEC cppVar_39910 = PC + 1;
	cppVar_39910 = (cppVar_39910 & cppMask_un_16_);
	BIT_VEC cppVar_39911 = ROM.rd(cppVar_39910);
	bool cppVar_39913 = (cppVar_39911 == 224);
	if (cppVar_39913) {
	cppVar_39909 = ACC;
	} else {
	BIT_VEC cppVar_39914;
	BIT_VEC cppVar_39915 = PC + 1;
	cppVar_39915 = (cppVar_39915 & cppMask_un_16_);
	BIT_VEC cppVar_39916 = ROM.rd(cppVar_39915);
	bool cppVar_39918 = (cppVar_39916 == 240);
	if (cppVar_39918) {
	cppVar_39914 = B;
	} else {
	cppVar_39914 = 0;
	}
	cppVar_39909 = cppVar_39914;
	}
	cppVar_39904 = cppVar_39909;
	}
	cppVar_39899 = cppVar_39904;
	}
	cppVar_39894 = cppVar_39899;
	}
	cppVar_39889 = cppVar_39894;
	}
	cppVar_39884 = cppVar_39889;
	}
	cppVar_39879 = cppVar_39884;
	}
	cppVar_39874 = cppVar_39879;
	}
	cppVar_39869 = cppVar_39874;
	}
	cppVar_39864 = cppVar_39869;
	}
	cppVar_39859 = cppVar_39864;
	}
	cppVar_39854 = cppVar_39859;
	}
	cppVar_39849 = cppVar_39854;
	}
	cppVar_39844 = cppVar_39849;
	}
	cppVar_39839 = cppVar_39844;
	}
	cppVar_39834 = cppVar_39839;
	}
	cppVar_39829 = cppVar_39834;
	}
	cppVar_39824 = cppVar_39829;
	}
	cppVar_39819 = cppVar_39824;
	}
	cppVar_39814 = cppVar_39819;
	}
	cppVar_39805 = cppVar_39814;
	}
	BIT_VEC cppVar_39921 = PC + 2;
	cppVar_39921 = (cppVar_39921 & cppMask_un_16_);
	BIT_VEC cppVar_39922 = ROM.rd(cppVar_39921);
	BIT_VEC cppVar_39923 = cppVar_39805 | cppVar_39922;
	cppVar_39799 = cppVar_39923;
	} else {
	cppVar_39799 = P3;
	}
	cppVar_39795 = cppVar_39799;
	} else {
	BIT_VEC cppVar_39924;
	BIT_VEC cppVar_39925 = ROM.rd(PC);
	bool cppVar_39927 = (cppVar_39925 == 66);
	if (cppVar_39927) {
	BIT_VEC cppVar_39928;
	BIT_VEC cppVar_39930 = PC + 1;
	cppVar_39930 = (cppVar_39930 & cppMask_un_16_);
	BIT_VEC cppVar_39931 = ROM.rd(cppVar_39930);
	bool cppVar_39933 = (cppVar_39931 == 176);
	if (cppVar_39933) {
	BIT_VEC cppVar_39934;
	BIT_VEC cppVar_39935 = PC + 1;
	cppVar_39935 = (cppVar_39935 & cppMask_un_16_);
	BIT_VEC cppVar_39936 = ROM.rd(cppVar_39935);
	BIT_VEC cppVar_39937 = (cppVar_39936 >> 7) & cppMask_un_1_;
	bool cppVar_39939 = (cppVar_39937 == 0);
	if (cppVar_39939) {
	BIT_VEC cppVar_39940 = PC + 1;
	cppVar_39940 = (cppVar_39940 & cppMask_un_16_);
	BIT_VEC cppVar_39941 = ROM.rd(cppVar_39940);
	BIT_VEC cppVar_39942 = IRAM.rd(cppVar_39941);
	cppVar_39934 = cppVar_39942;
	} else {
	BIT_VEC cppVar_39943;
	BIT_VEC cppVar_39944 = PC + 1;
	cppVar_39944 = (cppVar_39944 & cppMask_un_16_);
	BIT_VEC cppVar_39945 = ROM.rd(cppVar_39944);
	bool cppVar_39947 = (cppVar_39945 == 128);
	if (cppVar_39947) {
	cppVar_39943 = P0;
	} else {
	BIT_VEC cppVar_39948;
	BIT_VEC cppVar_39949 = PC + 1;
	cppVar_39949 = (cppVar_39949 & cppMask_un_16_);
	BIT_VEC cppVar_39950 = ROM.rd(cppVar_39949);
	bool cppVar_39952 = (cppVar_39950 == 129);
	if (cppVar_39952) {
	cppVar_39948 = SP;
	} else {
	BIT_VEC cppVar_39953;
	BIT_VEC cppVar_39954 = PC + 1;
	cppVar_39954 = (cppVar_39954 & cppMask_un_16_);
	BIT_VEC cppVar_39955 = ROM.rd(cppVar_39954);
	bool cppVar_39957 = (cppVar_39955 == 130);
	if (cppVar_39957) {
	cppVar_39953 = DPL;
	} else {
	BIT_VEC cppVar_39958;
	BIT_VEC cppVar_39959 = PC + 1;
	cppVar_39959 = (cppVar_39959 & cppMask_un_16_);
	BIT_VEC cppVar_39960 = ROM.rd(cppVar_39959);
	bool cppVar_39962 = (cppVar_39960 == 131);
	if (cppVar_39962) {
	cppVar_39958 = DPH;
	} else {
	BIT_VEC cppVar_39963;
	BIT_VEC cppVar_39964 = PC + 1;
	cppVar_39964 = (cppVar_39964 & cppMask_un_16_);
	BIT_VEC cppVar_39965 = ROM.rd(cppVar_39964);
	bool cppVar_39967 = (cppVar_39965 == 135);
	if (cppVar_39967) {
	cppVar_39963 = PCON;
	} else {
	BIT_VEC cppVar_39968;
	BIT_VEC cppVar_39969 = PC + 1;
	cppVar_39969 = (cppVar_39969 & cppMask_un_16_);
	BIT_VEC cppVar_39970 = ROM.rd(cppVar_39969);
	bool cppVar_39972 = (cppVar_39970 == 136);
	if (cppVar_39972) {
	cppVar_39968 = TCON;
	} else {
	BIT_VEC cppVar_39973;
	BIT_VEC cppVar_39974 = PC + 1;
	cppVar_39974 = (cppVar_39974 & cppMask_un_16_);
	BIT_VEC cppVar_39975 = ROM.rd(cppVar_39974);
	bool cppVar_39977 = (cppVar_39975 == 137);
	if (cppVar_39977) {
	cppVar_39973 = TMOD;
	} else {
	BIT_VEC cppVar_39978;
	BIT_VEC cppVar_39979 = PC + 1;
	cppVar_39979 = (cppVar_39979 & cppMask_un_16_);
	BIT_VEC cppVar_39980 = ROM.rd(cppVar_39979);
	bool cppVar_39982 = (cppVar_39980 == 138);
	if (cppVar_39982) {
	cppVar_39978 = TL0;
	} else {
	BIT_VEC cppVar_39983;
	BIT_VEC cppVar_39984 = PC + 1;
	cppVar_39984 = (cppVar_39984 & cppMask_un_16_);
	BIT_VEC cppVar_39985 = ROM.rd(cppVar_39984);
	bool cppVar_39987 = (cppVar_39985 == 140);
	if (cppVar_39987) {
	cppVar_39983 = TH0;
	} else {
	BIT_VEC cppVar_39988;
	BIT_VEC cppVar_39989 = PC + 1;
	cppVar_39989 = (cppVar_39989 & cppMask_un_16_);
	BIT_VEC cppVar_39990 = ROM.rd(cppVar_39989);
	bool cppVar_39992 = (cppVar_39990 == 139);
	if (cppVar_39992) {
	cppVar_39988 = TL1;
	} else {
	BIT_VEC cppVar_39993;
	BIT_VEC cppVar_39994 = PC + 1;
	cppVar_39994 = (cppVar_39994 & cppMask_un_16_);
	BIT_VEC cppVar_39995 = ROM.rd(cppVar_39994);
	bool cppVar_39997 = (cppVar_39995 == 141);
	if (cppVar_39997) {
	cppVar_39993 = TH1;
	} else {
	BIT_VEC cppVar_39998;
	BIT_VEC cppVar_39999 = PC + 1;
	cppVar_39999 = (cppVar_39999 & cppMask_un_16_);
	BIT_VEC cppVar_40000 = ROM.rd(cppVar_39999);
	bool cppVar_40002 = (cppVar_40000 == 144);
	if (cppVar_40002) {
	cppVar_39998 = P1;
	} else {
	BIT_VEC cppVar_40003;
	BIT_VEC cppVar_40004 = PC + 1;
	cppVar_40004 = (cppVar_40004 & cppMask_un_16_);
	BIT_VEC cppVar_40005 = ROM.rd(cppVar_40004);
	bool cppVar_40007 = (cppVar_40005 == 152);
	if (cppVar_40007) {
	cppVar_40003 = SCON;
	} else {
	BIT_VEC cppVar_40008;
	BIT_VEC cppVar_40009 = PC + 1;
	cppVar_40009 = (cppVar_40009 & cppMask_un_16_);
	BIT_VEC cppVar_40010 = ROM.rd(cppVar_40009);
	bool cppVar_40012 = (cppVar_40010 == 153);
	if (cppVar_40012) {
	cppVar_40008 = SBUF;
	} else {
	BIT_VEC cppVar_40013;
	BIT_VEC cppVar_40014 = PC + 1;
	cppVar_40014 = (cppVar_40014 & cppMask_un_16_);
	BIT_VEC cppVar_40015 = ROM.rd(cppVar_40014);
	bool cppVar_40017 = (cppVar_40015 == 160);
	if (cppVar_40017) {
	cppVar_40013 = P2;
	} else {
	BIT_VEC cppVar_40018;
	BIT_VEC cppVar_40019 = PC + 1;
	cppVar_40019 = (cppVar_40019 & cppMask_un_16_);
	BIT_VEC cppVar_40020 = ROM.rd(cppVar_40019);
	bool cppVar_40022 = (cppVar_40020 == 168);
	if (cppVar_40022) {
	cppVar_40018 = IE;
	} else {
	BIT_VEC cppVar_40023;
	BIT_VEC cppVar_40024 = PC + 1;
	cppVar_40024 = (cppVar_40024 & cppMask_un_16_);
	BIT_VEC cppVar_40025 = ROM.rd(cppVar_40024);
	bool cppVar_40027 = (cppVar_40025 == 176);
	if (cppVar_40027) {
	cppVar_40023 = P3;
	} else {
	BIT_VEC cppVar_40028;
	BIT_VEC cppVar_40029 = PC + 1;
	cppVar_40029 = (cppVar_40029 & cppMask_un_16_);
	BIT_VEC cppVar_40030 = ROM.rd(cppVar_40029);
	bool cppVar_40032 = (cppVar_40030 == 184);
	if (cppVar_40032) {
	cppVar_40028 = IP;
	} else {
	BIT_VEC cppVar_40033;
	BIT_VEC cppVar_40034 = PC + 1;
	cppVar_40034 = (cppVar_40034 & cppMask_un_16_);
	BIT_VEC cppVar_40035 = ROM.rd(cppVar_40034);
	bool cppVar_40037 = (cppVar_40035 == 208);
	if (cppVar_40037) {
	cppVar_40033 = PSW;
	} else {
	BIT_VEC cppVar_40038;
	BIT_VEC cppVar_40039 = PC + 1;
	cppVar_40039 = (cppVar_40039 & cppMask_un_16_);
	BIT_VEC cppVar_40040 = ROM.rd(cppVar_40039);
	bool cppVar_40042 = (cppVar_40040 == 224);
	if (cppVar_40042) {
	cppVar_40038 = ACC;
	} else {
	BIT_VEC cppVar_40043;
	BIT_VEC cppVar_40044 = PC + 1;
	cppVar_40044 = (cppVar_40044 & cppMask_un_16_);
	BIT_VEC cppVar_40045 = ROM.rd(cppVar_40044);
	bool cppVar_40047 = (cppVar_40045 == 240);
	if (cppVar_40047) {
	cppVar_40043 = B;
	} else {
	cppVar_40043 = 0;
	}
	cppVar_40038 = cppVar_40043;
	}
	cppVar_40033 = cppVar_40038;
	}
	cppVar_40028 = cppVar_40033;
	}
	cppVar_40023 = cppVar_40028;
	}
	cppVar_40018 = cppVar_40023;
	}
	cppVar_40013 = cppVar_40018;
	}
	cppVar_40008 = cppVar_40013;
	}
	cppVar_40003 = cppVar_40008;
	}
	cppVar_39998 = cppVar_40003;
	}
	cppVar_39993 = cppVar_39998;
	}
	cppVar_39988 = cppVar_39993;
	}
	cppVar_39983 = cppVar_39988;
	}
	cppVar_39978 = cppVar_39983;
	}
	cppVar_39973 = cppVar_39978;
	}
	cppVar_39968 = cppVar_39973;
	}
	cppVar_39963 = cppVar_39968;
	}
	cppVar_39958 = cppVar_39963;
	}
	cppVar_39953 = cppVar_39958;
	}
	cppVar_39948 = cppVar_39953;
	}
	cppVar_39943 = cppVar_39948;
	}
	cppVar_39934 = cppVar_39943;
	}
	BIT_VEC cppVar_40049 = cppVar_39934 | ACC;
	cppVar_39928 = cppVar_40049;
	} else {
	cppVar_39928 = P3;
	}
	cppVar_39924 = cppVar_39928;
	} else {
	BIT_VEC cppVar_40050;
	BIT_VEC cppVar_40051 = ROM.rd(PC);
	bool cppVar_40053 = (cppVar_40051 == 213);
	BIT_VEC cppVar_40054 = ROM.rd(PC);
	bool cppVar_40056 = (cppVar_40054 == 21);
	bool cppVar_40057 = cppVar_40053 || cppVar_40056;
	if (cppVar_40057) {
	BIT_VEC cppVar_40058;
	BIT_VEC cppVar_40060 = PC + 1;
	cppVar_40060 = (cppVar_40060 & cppMask_un_16_);
	BIT_VEC cppVar_40061 = ROM.rd(cppVar_40060);
	bool cppVar_40063 = (cppVar_40061 == 176);
	if (cppVar_40063) {
	BIT_VEC cppVar_40064;
	BIT_VEC cppVar_40065 = PC + 1;
	cppVar_40065 = (cppVar_40065 & cppMask_un_16_);
	BIT_VEC cppVar_40066 = ROM.rd(cppVar_40065);
	BIT_VEC cppVar_40067 = (cppVar_40066 >> 7) & cppMask_un_1_;
	bool cppVar_40069 = (cppVar_40067 == 0);
	if (cppVar_40069) {
	BIT_VEC cppVar_40070 = PC + 1;
	cppVar_40070 = (cppVar_40070 & cppMask_un_16_);
	BIT_VEC cppVar_40071 = ROM.rd(cppVar_40070);
	BIT_VEC cppVar_40072 = IRAM.rd(cppVar_40071);
	cppVar_40064 = cppVar_40072;
	} else {
	BIT_VEC cppVar_40073;
	BIT_VEC cppVar_40074 = PC + 1;
	cppVar_40074 = (cppVar_40074 & cppMask_un_16_);
	BIT_VEC cppVar_40075 = ROM.rd(cppVar_40074);
	bool cppVar_40077 = (cppVar_40075 == 128);
	if (cppVar_40077) {
	cppVar_40073 = P0;
	} else {
	BIT_VEC cppVar_40078;
	BIT_VEC cppVar_40079 = PC + 1;
	cppVar_40079 = (cppVar_40079 & cppMask_un_16_);
	BIT_VEC cppVar_40080 = ROM.rd(cppVar_40079);
	bool cppVar_40082 = (cppVar_40080 == 129);
	if (cppVar_40082) {
	cppVar_40078 = SP;
	} else {
	BIT_VEC cppVar_40083;
	BIT_VEC cppVar_40084 = PC + 1;
	cppVar_40084 = (cppVar_40084 & cppMask_un_16_);
	BIT_VEC cppVar_40085 = ROM.rd(cppVar_40084);
	bool cppVar_40087 = (cppVar_40085 == 130);
	if (cppVar_40087) {
	cppVar_40083 = DPL;
	} else {
	BIT_VEC cppVar_40088;
	BIT_VEC cppVar_40089 = PC + 1;
	cppVar_40089 = (cppVar_40089 & cppMask_un_16_);
	BIT_VEC cppVar_40090 = ROM.rd(cppVar_40089);
	bool cppVar_40092 = (cppVar_40090 == 131);
	if (cppVar_40092) {
	cppVar_40088 = DPH;
	} else {
	BIT_VEC cppVar_40093;
	BIT_VEC cppVar_40094 = PC + 1;
	cppVar_40094 = (cppVar_40094 & cppMask_un_16_);
	BIT_VEC cppVar_40095 = ROM.rd(cppVar_40094);
	bool cppVar_40097 = (cppVar_40095 == 135);
	if (cppVar_40097) {
	cppVar_40093 = PCON;
	} else {
	BIT_VEC cppVar_40098;
	BIT_VEC cppVar_40099 = PC + 1;
	cppVar_40099 = (cppVar_40099 & cppMask_un_16_);
	BIT_VEC cppVar_40100 = ROM.rd(cppVar_40099);
	bool cppVar_40102 = (cppVar_40100 == 136);
	if (cppVar_40102) {
	cppVar_40098 = TCON;
	} else {
	BIT_VEC cppVar_40103;
	BIT_VEC cppVar_40104 = PC + 1;
	cppVar_40104 = (cppVar_40104 & cppMask_un_16_);
	BIT_VEC cppVar_40105 = ROM.rd(cppVar_40104);
	bool cppVar_40107 = (cppVar_40105 == 137);
	if (cppVar_40107) {
	cppVar_40103 = TMOD;
	} else {
	BIT_VEC cppVar_40108;
	BIT_VEC cppVar_40109 = PC + 1;
	cppVar_40109 = (cppVar_40109 & cppMask_un_16_);
	BIT_VEC cppVar_40110 = ROM.rd(cppVar_40109);
	bool cppVar_40112 = (cppVar_40110 == 138);
	if (cppVar_40112) {
	cppVar_40108 = TL0;
	} else {
	BIT_VEC cppVar_40113;
	BIT_VEC cppVar_40114 = PC + 1;
	cppVar_40114 = (cppVar_40114 & cppMask_un_16_);
	BIT_VEC cppVar_40115 = ROM.rd(cppVar_40114);
	bool cppVar_40117 = (cppVar_40115 == 140);
	if (cppVar_40117) {
	cppVar_40113 = TH0;
	} else {
	BIT_VEC cppVar_40118;
	BIT_VEC cppVar_40119 = PC + 1;
	cppVar_40119 = (cppVar_40119 & cppMask_un_16_);
	BIT_VEC cppVar_40120 = ROM.rd(cppVar_40119);
	bool cppVar_40122 = (cppVar_40120 == 139);
	if (cppVar_40122) {
	cppVar_40118 = TL1;
	} else {
	BIT_VEC cppVar_40123;
	BIT_VEC cppVar_40124 = PC + 1;
	cppVar_40124 = (cppVar_40124 & cppMask_un_16_);
	BIT_VEC cppVar_40125 = ROM.rd(cppVar_40124);
	bool cppVar_40127 = (cppVar_40125 == 141);
	if (cppVar_40127) {
	cppVar_40123 = TH1;
	} else {
	BIT_VEC cppVar_40128;
	BIT_VEC cppVar_40129 = PC + 1;
	cppVar_40129 = (cppVar_40129 & cppMask_un_16_);
	BIT_VEC cppVar_40130 = ROM.rd(cppVar_40129);
	bool cppVar_40132 = (cppVar_40130 == 144);
	if (cppVar_40132) {
	cppVar_40128 = P1;
	} else {
	BIT_VEC cppVar_40133;
	BIT_VEC cppVar_40134 = PC + 1;
	cppVar_40134 = (cppVar_40134 & cppMask_un_16_);
	BIT_VEC cppVar_40135 = ROM.rd(cppVar_40134);
	bool cppVar_40137 = (cppVar_40135 == 152);
	if (cppVar_40137) {
	cppVar_40133 = SCON;
	} else {
	BIT_VEC cppVar_40138;
	BIT_VEC cppVar_40139 = PC + 1;
	cppVar_40139 = (cppVar_40139 & cppMask_un_16_);
	BIT_VEC cppVar_40140 = ROM.rd(cppVar_40139);
	bool cppVar_40142 = (cppVar_40140 == 153);
	if (cppVar_40142) {
	cppVar_40138 = SBUF;
	} else {
	BIT_VEC cppVar_40143;
	BIT_VEC cppVar_40144 = PC + 1;
	cppVar_40144 = (cppVar_40144 & cppMask_un_16_);
	BIT_VEC cppVar_40145 = ROM.rd(cppVar_40144);
	bool cppVar_40147 = (cppVar_40145 == 160);
	if (cppVar_40147) {
	cppVar_40143 = P2;
	} else {
	BIT_VEC cppVar_40148;
	BIT_VEC cppVar_40149 = PC + 1;
	cppVar_40149 = (cppVar_40149 & cppMask_un_16_);
	BIT_VEC cppVar_40150 = ROM.rd(cppVar_40149);
	bool cppVar_40152 = (cppVar_40150 == 168);
	if (cppVar_40152) {
	cppVar_40148 = IE;
	} else {
	BIT_VEC cppVar_40153;
	BIT_VEC cppVar_40154 = PC + 1;
	cppVar_40154 = (cppVar_40154 & cppMask_un_16_);
	BIT_VEC cppVar_40155 = ROM.rd(cppVar_40154);
	bool cppVar_40157 = (cppVar_40155 == 176);
	if (cppVar_40157) {
	cppVar_40153 = P3;
	} else {
	BIT_VEC cppVar_40158;
	BIT_VEC cppVar_40159 = PC + 1;
	cppVar_40159 = (cppVar_40159 & cppMask_un_16_);
	BIT_VEC cppVar_40160 = ROM.rd(cppVar_40159);
	bool cppVar_40162 = (cppVar_40160 == 184);
	if (cppVar_40162) {
	cppVar_40158 = IP;
	} else {
	BIT_VEC cppVar_40163;
	BIT_VEC cppVar_40164 = PC + 1;
	cppVar_40164 = (cppVar_40164 & cppMask_un_16_);
	BIT_VEC cppVar_40165 = ROM.rd(cppVar_40164);
	bool cppVar_40167 = (cppVar_40165 == 208);
	if (cppVar_40167) {
	cppVar_40163 = PSW;
	} else {
	BIT_VEC cppVar_40168;
	BIT_VEC cppVar_40169 = PC + 1;
	cppVar_40169 = (cppVar_40169 & cppMask_un_16_);
	BIT_VEC cppVar_40170 = ROM.rd(cppVar_40169);
	bool cppVar_40172 = (cppVar_40170 == 224);
	if (cppVar_40172) {
	cppVar_40168 = ACC;
	} else {
	BIT_VEC cppVar_40173;
	BIT_VEC cppVar_40174 = PC + 1;
	cppVar_40174 = (cppVar_40174 & cppMask_un_16_);
	BIT_VEC cppVar_40175 = ROM.rd(cppVar_40174);
	bool cppVar_40177 = (cppVar_40175 == 240);
	if (cppVar_40177) {
	cppVar_40173 = B;
	} else {
	cppVar_40173 = 0;
	}
	cppVar_40168 = cppVar_40173;
	}
	cppVar_40163 = cppVar_40168;
	}
	cppVar_40158 = cppVar_40163;
	}
	cppVar_40153 = cppVar_40158;
	}
	cppVar_40148 = cppVar_40153;
	}
	cppVar_40143 = cppVar_40148;
	}
	cppVar_40138 = cppVar_40143;
	}
	cppVar_40133 = cppVar_40138;
	}
	cppVar_40128 = cppVar_40133;
	}
	cppVar_40123 = cppVar_40128;
	}
	cppVar_40118 = cppVar_40123;
	}
	cppVar_40113 = cppVar_40118;
	}
	cppVar_40108 = cppVar_40113;
	}
	cppVar_40103 = cppVar_40108;
	}
	cppVar_40098 = cppVar_40103;
	}
	cppVar_40093 = cppVar_40098;
	}
	cppVar_40088 = cppVar_40093;
	}
	cppVar_40083 = cppVar_40088;
	}
	cppVar_40078 = cppVar_40083;
	}
	cppVar_40073 = cppVar_40078;
	}
	cppVar_40064 = cppVar_40073;
	}
	BIT_VEC cppVar_40180 = cppVar_40064 - 1;
	cppVar_40180 = (cppVar_40180 & cppMask_un_8_);
	cppVar_40058 = cppVar_40180;
	} else {
	cppVar_40058 = P3;
	}
	cppVar_40050 = cppVar_40058;
	} else {
	BIT_VEC cppVar_40181;
	BIT_VEC cppVar_40182 = ROM.rd(PC);
	bool cppVar_40184 = (cppVar_40182 == 194);
	BIT_VEC cppVar_40185 = ROM.rd(PC);
	bool cppVar_40187 = (cppVar_40185 == 16);
	bool cppVar_40188 = cppVar_40184 || cppVar_40187;
	if (cppVar_40188) {
	BIT_VEC cppVar_40189;
	BIT_VEC cppVar_40190;
	BIT_VEC cppVar_40192 = PC + 1;
	cppVar_40192 = (cppVar_40192 & cppMask_un_16_);
	BIT_VEC cppVar_40193 = ROM.rd(cppVar_40192);
	BIT_VEC cppVar_40194 = (cppVar_40193 >> 7) & cppMask_un_1_;
	bool cppVar_40196 = (cppVar_40194 == 1);
	if (cppVar_40196) {
	BIT_VEC cppVar_40197 = PC + 1;
	cppVar_40197 = (cppVar_40197 & cppMask_un_16_);
	BIT_VEC cppVar_40198 = ROM.rd(cppVar_40197);
	BIT_VEC cppVar_40199 = (cppVar_40198 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40201 = (cppVar_40199 << 3) | 0;
	cppVar_40201 = (cppVar_40201 & cppMask_un_8_);
	cppVar_40190 = cppVar_40201;
	} else {
	BIT_VEC cppVar_40202 = PC + 1;
	cppVar_40202 = (cppVar_40202 & cppMask_un_16_);
	BIT_VEC cppVar_40203 = ROM.rd(cppVar_40202);
	BIT_VEC cppVar_40204 = (cppVar_40203 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40205 = (cppVar_40204 & cppMask_un_5_);
	BIT_VEC cppVar_40207 = cppVar_40205 + 32;
	cppVar_40207 = (cppVar_40207 & cppMask_un_8_);
	cppVar_40190 = cppVar_40207;
	}
	bool cppVar_40209 = (cppVar_40190 == 176);
	if (cppVar_40209) {
	BIT_VEC cppVar_40211 = PC + 1;
	cppVar_40211 = (cppVar_40211 & cppMask_un_16_);
	BIT_VEC cppVar_40212 = ROM.rd(cppVar_40211);
	BIT_VEC cppVar_40213 = (cppVar_40212 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_40214 = (cppVar_40213 & cppMask_un_3_);
	BIT_VEC cppVar_40215 = 1 << static_cast<unsigned>(cppVar_40214);
	cppVar_40215 = (cppVar_40215 & cppMask_un_8_);
	BIT_VEC cppVar_40216 = ~cppVar_40215;
	BIT_VEC cppVar_40217;
	BIT_VEC cppVar_40218;
	BIT_VEC cppVar_40219 = PC + 1;
	cppVar_40219 = (cppVar_40219 & cppMask_un_16_);
	BIT_VEC cppVar_40220 = ROM.rd(cppVar_40219);
	BIT_VEC cppVar_40221 = (cppVar_40220 >> 7) & cppMask_un_1_;
	bool cppVar_40222 = (cppVar_40221 == 1);
	if (cppVar_40222) {
	BIT_VEC cppVar_40223 = PC + 1;
	cppVar_40223 = (cppVar_40223 & cppMask_un_16_);
	BIT_VEC cppVar_40224 = ROM.rd(cppVar_40223);
	BIT_VEC cppVar_40225 = (cppVar_40224 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40226 = (cppVar_40225 << 3) | 0;
	cppVar_40226 = (cppVar_40226 & cppMask_un_8_);
	cppVar_40218 = cppVar_40226;
	} else {
	BIT_VEC cppVar_40227 = PC + 1;
	cppVar_40227 = (cppVar_40227 & cppMask_un_16_);
	BIT_VEC cppVar_40228 = ROM.rd(cppVar_40227);
	BIT_VEC cppVar_40229 = (cppVar_40228 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40230 = (cppVar_40229 & cppMask_un_5_);
	BIT_VEC cppVar_40231 = cppVar_40230 + 32;
	cppVar_40231 = (cppVar_40231 & cppMask_un_8_);
	cppVar_40218 = cppVar_40231;
	}
	BIT_VEC cppVar_40232 = (cppVar_40218 >> 7) & cppMask_un_1_;
	bool cppVar_40234 = (cppVar_40232 == 0);
	if (cppVar_40234) {
	BIT_VEC cppVar_40235;
	BIT_VEC cppVar_40236 = PC + 1;
	cppVar_40236 = (cppVar_40236 & cppMask_un_16_);
	BIT_VEC cppVar_40237 = ROM.rd(cppVar_40236);
	BIT_VEC cppVar_40238 = (cppVar_40237 >> 7) & cppMask_un_1_;
	bool cppVar_40239 = (cppVar_40238 == 1);
	if (cppVar_40239) {
	BIT_VEC cppVar_40240 = PC + 1;
	cppVar_40240 = (cppVar_40240 & cppMask_un_16_);
	BIT_VEC cppVar_40241 = ROM.rd(cppVar_40240);
	BIT_VEC cppVar_40242 = (cppVar_40241 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40243 = (cppVar_40242 << 3) | 0;
	cppVar_40243 = (cppVar_40243 & cppMask_un_8_);
	cppVar_40235 = cppVar_40243;
	} else {
	BIT_VEC cppVar_40244 = PC + 1;
	cppVar_40244 = (cppVar_40244 & cppMask_un_16_);
	BIT_VEC cppVar_40245 = ROM.rd(cppVar_40244);
	BIT_VEC cppVar_40246 = (cppVar_40245 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40247 = (cppVar_40246 & cppMask_un_5_);
	BIT_VEC cppVar_40248 = cppVar_40247 + 32;
	cppVar_40248 = (cppVar_40248 & cppMask_un_8_);
	cppVar_40235 = cppVar_40248;
	}
	BIT_VEC cppVar_40249 = IRAM.rd(cppVar_40235);
	cppVar_40217 = cppVar_40249;
	} else {
	BIT_VEC cppVar_40250;
	BIT_VEC cppVar_40251;
	BIT_VEC cppVar_40252 = PC + 1;
	cppVar_40252 = (cppVar_40252 & cppMask_un_16_);
	BIT_VEC cppVar_40253 = ROM.rd(cppVar_40252);
	BIT_VEC cppVar_40254 = (cppVar_40253 >> 7) & cppMask_un_1_;
	bool cppVar_40255 = (cppVar_40254 == 1);
	if (cppVar_40255) {
	BIT_VEC cppVar_40256 = PC + 1;
	cppVar_40256 = (cppVar_40256 & cppMask_un_16_);
	BIT_VEC cppVar_40257 = ROM.rd(cppVar_40256);
	BIT_VEC cppVar_40258 = (cppVar_40257 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40259 = (cppVar_40258 << 3) | 0;
	cppVar_40259 = (cppVar_40259 & cppMask_un_8_);
	cppVar_40251 = cppVar_40259;
	} else {
	BIT_VEC cppVar_40260 = PC + 1;
	cppVar_40260 = (cppVar_40260 & cppMask_un_16_);
	BIT_VEC cppVar_40261 = ROM.rd(cppVar_40260);
	BIT_VEC cppVar_40262 = (cppVar_40261 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40263 = (cppVar_40262 & cppMask_un_5_);
	BIT_VEC cppVar_40264 = cppVar_40263 + 32;
	cppVar_40264 = (cppVar_40264 & cppMask_un_8_);
	cppVar_40251 = cppVar_40264;
	}
	bool cppVar_40266 = (cppVar_40251 == 128);
	if (cppVar_40266) {
	cppVar_40250 = P0;
	} else {
	BIT_VEC cppVar_40267;
	BIT_VEC cppVar_40268;
	BIT_VEC cppVar_40269 = PC + 1;
	cppVar_40269 = (cppVar_40269 & cppMask_un_16_);
	BIT_VEC cppVar_40270 = ROM.rd(cppVar_40269);
	BIT_VEC cppVar_40271 = (cppVar_40270 >> 7) & cppMask_un_1_;
	bool cppVar_40272 = (cppVar_40271 == 1);
	if (cppVar_40272) {
	BIT_VEC cppVar_40273 = PC + 1;
	cppVar_40273 = (cppVar_40273 & cppMask_un_16_);
	BIT_VEC cppVar_40274 = ROM.rd(cppVar_40273);
	BIT_VEC cppVar_40275 = (cppVar_40274 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40276 = (cppVar_40275 << 3) | 0;
	cppVar_40276 = (cppVar_40276 & cppMask_un_8_);
	cppVar_40268 = cppVar_40276;
	} else {
	BIT_VEC cppVar_40277 = PC + 1;
	cppVar_40277 = (cppVar_40277 & cppMask_un_16_);
	BIT_VEC cppVar_40278 = ROM.rd(cppVar_40277);
	BIT_VEC cppVar_40279 = (cppVar_40278 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40280 = (cppVar_40279 & cppMask_un_5_);
	BIT_VEC cppVar_40281 = cppVar_40280 + 32;
	cppVar_40281 = (cppVar_40281 & cppMask_un_8_);
	cppVar_40268 = cppVar_40281;
	}
	bool cppVar_40283 = (cppVar_40268 == 129);
	if (cppVar_40283) {
	cppVar_40267 = SP;
	} else {
	BIT_VEC cppVar_40284;
	BIT_VEC cppVar_40285;
	BIT_VEC cppVar_40286 = PC + 1;
	cppVar_40286 = (cppVar_40286 & cppMask_un_16_);
	BIT_VEC cppVar_40287 = ROM.rd(cppVar_40286);
	BIT_VEC cppVar_40288 = (cppVar_40287 >> 7) & cppMask_un_1_;
	bool cppVar_40289 = (cppVar_40288 == 1);
	if (cppVar_40289) {
	BIT_VEC cppVar_40290 = PC + 1;
	cppVar_40290 = (cppVar_40290 & cppMask_un_16_);
	BIT_VEC cppVar_40291 = ROM.rd(cppVar_40290);
	BIT_VEC cppVar_40292 = (cppVar_40291 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40293 = (cppVar_40292 << 3) | 0;
	cppVar_40293 = (cppVar_40293 & cppMask_un_8_);
	cppVar_40285 = cppVar_40293;
	} else {
	BIT_VEC cppVar_40294 = PC + 1;
	cppVar_40294 = (cppVar_40294 & cppMask_un_16_);
	BIT_VEC cppVar_40295 = ROM.rd(cppVar_40294);
	BIT_VEC cppVar_40296 = (cppVar_40295 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40297 = (cppVar_40296 & cppMask_un_5_);
	BIT_VEC cppVar_40298 = cppVar_40297 + 32;
	cppVar_40298 = (cppVar_40298 & cppMask_un_8_);
	cppVar_40285 = cppVar_40298;
	}
	bool cppVar_40300 = (cppVar_40285 == 130);
	if (cppVar_40300) {
	cppVar_40284 = DPL;
	} else {
	BIT_VEC cppVar_40301;
	BIT_VEC cppVar_40302;
	BIT_VEC cppVar_40303 = PC + 1;
	cppVar_40303 = (cppVar_40303 & cppMask_un_16_);
	BIT_VEC cppVar_40304 = ROM.rd(cppVar_40303);
	BIT_VEC cppVar_40305 = (cppVar_40304 >> 7) & cppMask_un_1_;
	bool cppVar_40306 = (cppVar_40305 == 1);
	if (cppVar_40306) {
	BIT_VEC cppVar_40307 = PC + 1;
	cppVar_40307 = (cppVar_40307 & cppMask_un_16_);
	BIT_VEC cppVar_40308 = ROM.rd(cppVar_40307);
	BIT_VEC cppVar_40309 = (cppVar_40308 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40310 = (cppVar_40309 << 3) | 0;
	cppVar_40310 = (cppVar_40310 & cppMask_un_8_);
	cppVar_40302 = cppVar_40310;
	} else {
	BIT_VEC cppVar_40311 = PC + 1;
	cppVar_40311 = (cppVar_40311 & cppMask_un_16_);
	BIT_VEC cppVar_40312 = ROM.rd(cppVar_40311);
	BIT_VEC cppVar_40313 = (cppVar_40312 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40314 = (cppVar_40313 & cppMask_un_5_);
	BIT_VEC cppVar_40315 = cppVar_40314 + 32;
	cppVar_40315 = (cppVar_40315 & cppMask_un_8_);
	cppVar_40302 = cppVar_40315;
	}
	bool cppVar_40317 = (cppVar_40302 == 131);
	if (cppVar_40317) {
	cppVar_40301 = DPH;
	} else {
	BIT_VEC cppVar_40318;
	BIT_VEC cppVar_40319;
	BIT_VEC cppVar_40320 = PC + 1;
	cppVar_40320 = (cppVar_40320 & cppMask_un_16_);
	BIT_VEC cppVar_40321 = ROM.rd(cppVar_40320);
	BIT_VEC cppVar_40322 = (cppVar_40321 >> 7) & cppMask_un_1_;
	bool cppVar_40323 = (cppVar_40322 == 1);
	if (cppVar_40323) {
	BIT_VEC cppVar_40324 = PC + 1;
	cppVar_40324 = (cppVar_40324 & cppMask_un_16_);
	BIT_VEC cppVar_40325 = ROM.rd(cppVar_40324);
	BIT_VEC cppVar_40326 = (cppVar_40325 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40327 = (cppVar_40326 << 3) | 0;
	cppVar_40327 = (cppVar_40327 & cppMask_un_8_);
	cppVar_40319 = cppVar_40327;
	} else {
	BIT_VEC cppVar_40328 = PC + 1;
	cppVar_40328 = (cppVar_40328 & cppMask_un_16_);
	BIT_VEC cppVar_40329 = ROM.rd(cppVar_40328);
	BIT_VEC cppVar_40330 = (cppVar_40329 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40331 = (cppVar_40330 & cppMask_un_5_);
	BIT_VEC cppVar_40332 = cppVar_40331 + 32;
	cppVar_40332 = (cppVar_40332 & cppMask_un_8_);
	cppVar_40319 = cppVar_40332;
	}
	bool cppVar_40334 = (cppVar_40319 == 135);
	if (cppVar_40334) {
	cppVar_40318 = PCON;
	} else {
	BIT_VEC cppVar_40335;
	BIT_VEC cppVar_40336;
	BIT_VEC cppVar_40337 = PC + 1;
	cppVar_40337 = (cppVar_40337 & cppMask_un_16_);
	BIT_VEC cppVar_40338 = ROM.rd(cppVar_40337);
	BIT_VEC cppVar_40339 = (cppVar_40338 >> 7) & cppMask_un_1_;
	bool cppVar_40340 = (cppVar_40339 == 1);
	if (cppVar_40340) {
	BIT_VEC cppVar_40341 = PC + 1;
	cppVar_40341 = (cppVar_40341 & cppMask_un_16_);
	BIT_VEC cppVar_40342 = ROM.rd(cppVar_40341);
	BIT_VEC cppVar_40343 = (cppVar_40342 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40344 = (cppVar_40343 << 3) | 0;
	cppVar_40344 = (cppVar_40344 & cppMask_un_8_);
	cppVar_40336 = cppVar_40344;
	} else {
	BIT_VEC cppVar_40345 = PC + 1;
	cppVar_40345 = (cppVar_40345 & cppMask_un_16_);
	BIT_VEC cppVar_40346 = ROM.rd(cppVar_40345);
	BIT_VEC cppVar_40347 = (cppVar_40346 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40348 = (cppVar_40347 & cppMask_un_5_);
	BIT_VEC cppVar_40349 = cppVar_40348 + 32;
	cppVar_40349 = (cppVar_40349 & cppMask_un_8_);
	cppVar_40336 = cppVar_40349;
	}
	bool cppVar_40351 = (cppVar_40336 == 136);
	if (cppVar_40351) {
	cppVar_40335 = TCON;
	} else {
	BIT_VEC cppVar_40352;
	BIT_VEC cppVar_40353;
	BIT_VEC cppVar_40354 = PC + 1;
	cppVar_40354 = (cppVar_40354 & cppMask_un_16_);
	BIT_VEC cppVar_40355 = ROM.rd(cppVar_40354);
	BIT_VEC cppVar_40356 = (cppVar_40355 >> 7) & cppMask_un_1_;
	bool cppVar_40357 = (cppVar_40356 == 1);
	if (cppVar_40357) {
	BIT_VEC cppVar_40358 = PC + 1;
	cppVar_40358 = (cppVar_40358 & cppMask_un_16_);
	BIT_VEC cppVar_40359 = ROM.rd(cppVar_40358);
	BIT_VEC cppVar_40360 = (cppVar_40359 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40361 = (cppVar_40360 << 3) | 0;
	cppVar_40361 = (cppVar_40361 & cppMask_un_8_);
	cppVar_40353 = cppVar_40361;
	} else {
	BIT_VEC cppVar_40362 = PC + 1;
	cppVar_40362 = (cppVar_40362 & cppMask_un_16_);
	BIT_VEC cppVar_40363 = ROM.rd(cppVar_40362);
	BIT_VEC cppVar_40364 = (cppVar_40363 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40365 = (cppVar_40364 & cppMask_un_5_);
	BIT_VEC cppVar_40366 = cppVar_40365 + 32;
	cppVar_40366 = (cppVar_40366 & cppMask_un_8_);
	cppVar_40353 = cppVar_40366;
	}
	bool cppVar_40368 = (cppVar_40353 == 137);
	if (cppVar_40368) {
	cppVar_40352 = TMOD;
	} else {
	BIT_VEC cppVar_40369;
	BIT_VEC cppVar_40370;
	BIT_VEC cppVar_40371 = PC + 1;
	cppVar_40371 = (cppVar_40371 & cppMask_un_16_);
	BIT_VEC cppVar_40372 = ROM.rd(cppVar_40371);
	BIT_VEC cppVar_40373 = (cppVar_40372 >> 7) & cppMask_un_1_;
	bool cppVar_40374 = (cppVar_40373 == 1);
	if (cppVar_40374) {
	BIT_VEC cppVar_40375 = PC + 1;
	cppVar_40375 = (cppVar_40375 & cppMask_un_16_);
	BIT_VEC cppVar_40376 = ROM.rd(cppVar_40375);
	BIT_VEC cppVar_40377 = (cppVar_40376 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40378 = (cppVar_40377 << 3) | 0;
	cppVar_40378 = (cppVar_40378 & cppMask_un_8_);
	cppVar_40370 = cppVar_40378;
	} else {
	BIT_VEC cppVar_40379 = PC + 1;
	cppVar_40379 = (cppVar_40379 & cppMask_un_16_);
	BIT_VEC cppVar_40380 = ROM.rd(cppVar_40379);
	BIT_VEC cppVar_40381 = (cppVar_40380 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40382 = (cppVar_40381 & cppMask_un_5_);
	BIT_VEC cppVar_40383 = cppVar_40382 + 32;
	cppVar_40383 = (cppVar_40383 & cppMask_un_8_);
	cppVar_40370 = cppVar_40383;
	}
	bool cppVar_40385 = (cppVar_40370 == 138);
	if (cppVar_40385) {
	cppVar_40369 = TL0;
	} else {
	BIT_VEC cppVar_40386;
	BIT_VEC cppVar_40387;
	BIT_VEC cppVar_40388 = PC + 1;
	cppVar_40388 = (cppVar_40388 & cppMask_un_16_);
	BIT_VEC cppVar_40389 = ROM.rd(cppVar_40388);
	BIT_VEC cppVar_40390 = (cppVar_40389 >> 7) & cppMask_un_1_;
	bool cppVar_40391 = (cppVar_40390 == 1);
	if (cppVar_40391) {
	BIT_VEC cppVar_40392 = PC + 1;
	cppVar_40392 = (cppVar_40392 & cppMask_un_16_);
	BIT_VEC cppVar_40393 = ROM.rd(cppVar_40392);
	BIT_VEC cppVar_40394 = (cppVar_40393 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40395 = (cppVar_40394 << 3) | 0;
	cppVar_40395 = (cppVar_40395 & cppMask_un_8_);
	cppVar_40387 = cppVar_40395;
	} else {
	BIT_VEC cppVar_40396 = PC + 1;
	cppVar_40396 = (cppVar_40396 & cppMask_un_16_);
	BIT_VEC cppVar_40397 = ROM.rd(cppVar_40396);
	BIT_VEC cppVar_40398 = (cppVar_40397 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40399 = (cppVar_40398 & cppMask_un_5_);
	BIT_VEC cppVar_40400 = cppVar_40399 + 32;
	cppVar_40400 = (cppVar_40400 & cppMask_un_8_);
	cppVar_40387 = cppVar_40400;
	}
	bool cppVar_40402 = (cppVar_40387 == 140);
	if (cppVar_40402) {
	cppVar_40386 = TH0;
	} else {
	BIT_VEC cppVar_40403;
	BIT_VEC cppVar_40404;
	BIT_VEC cppVar_40405 = PC + 1;
	cppVar_40405 = (cppVar_40405 & cppMask_un_16_);
	BIT_VEC cppVar_40406 = ROM.rd(cppVar_40405);
	BIT_VEC cppVar_40407 = (cppVar_40406 >> 7) & cppMask_un_1_;
	bool cppVar_40408 = (cppVar_40407 == 1);
	if (cppVar_40408) {
	BIT_VEC cppVar_40409 = PC + 1;
	cppVar_40409 = (cppVar_40409 & cppMask_un_16_);
	BIT_VEC cppVar_40410 = ROM.rd(cppVar_40409);
	BIT_VEC cppVar_40411 = (cppVar_40410 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40412 = (cppVar_40411 << 3) | 0;
	cppVar_40412 = (cppVar_40412 & cppMask_un_8_);
	cppVar_40404 = cppVar_40412;
	} else {
	BIT_VEC cppVar_40413 = PC + 1;
	cppVar_40413 = (cppVar_40413 & cppMask_un_16_);
	BIT_VEC cppVar_40414 = ROM.rd(cppVar_40413);
	BIT_VEC cppVar_40415 = (cppVar_40414 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40416 = (cppVar_40415 & cppMask_un_5_);
	BIT_VEC cppVar_40417 = cppVar_40416 + 32;
	cppVar_40417 = (cppVar_40417 & cppMask_un_8_);
	cppVar_40404 = cppVar_40417;
	}
	bool cppVar_40419 = (cppVar_40404 == 139);
	if (cppVar_40419) {
	cppVar_40403 = TL1;
	} else {
	BIT_VEC cppVar_40420;
	BIT_VEC cppVar_40421;
	BIT_VEC cppVar_40422 = PC + 1;
	cppVar_40422 = (cppVar_40422 & cppMask_un_16_);
	BIT_VEC cppVar_40423 = ROM.rd(cppVar_40422);
	BIT_VEC cppVar_40424 = (cppVar_40423 >> 7) & cppMask_un_1_;
	bool cppVar_40425 = (cppVar_40424 == 1);
	if (cppVar_40425) {
	BIT_VEC cppVar_40426 = PC + 1;
	cppVar_40426 = (cppVar_40426 & cppMask_un_16_);
	BIT_VEC cppVar_40427 = ROM.rd(cppVar_40426);
	BIT_VEC cppVar_40428 = (cppVar_40427 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40429 = (cppVar_40428 << 3) | 0;
	cppVar_40429 = (cppVar_40429 & cppMask_un_8_);
	cppVar_40421 = cppVar_40429;
	} else {
	BIT_VEC cppVar_40430 = PC + 1;
	cppVar_40430 = (cppVar_40430 & cppMask_un_16_);
	BIT_VEC cppVar_40431 = ROM.rd(cppVar_40430);
	BIT_VEC cppVar_40432 = (cppVar_40431 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40433 = (cppVar_40432 & cppMask_un_5_);
	BIT_VEC cppVar_40434 = cppVar_40433 + 32;
	cppVar_40434 = (cppVar_40434 & cppMask_un_8_);
	cppVar_40421 = cppVar_40434;
	}
	bool cppVar_40436 = (cppVar_40421 == 141);
	if (cppVar_40436) {
	cppVar_40420 = TH1;
	} else {
	BIT_VEC cppVar_40437;
	BIT_VEC cppVar_40438;
	BIT_VEC cppVar_40439 = PC + 1;
	cppVar_40439 = (cppVar_40439 & cppMask_un_16_);
	BIT_VEC cppVar_40440 = ROM.rd(cppVar_40439);
	BIT_VEC cppVar_40441 = (cppVar_40440 >> 7) & cppMask_un_1_;
	bool cppVar_40442 = (cppVar_40441 == 1);
	if (cppVar_40442) {
	BIT_VEC cppVar_40443 = PC + 1;
	cppVar_40443 = (cppVar_40443 & cppMask_un_16_);
	BIT_VEC cppVar_40444 = ROM.rd(cppVar_40443);
	BIT_VEC cppVar_40445 = (cppVar_40444 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40446 = (cppVar_40445 << 3) | 0;
	cppVar_40446 = (cppVar_40446 & cppMask_un_8_);
	cppVar_40438 = cppVar_40446;
	} else {
	BIT_VEC cppVar_40447 = PC + 1;
	cppVar_40447 = (cppVar_40447 & cppMask_un_16_);
	BIT_VEC cppVar_40448 = ROM.rd(cppVar_40447);
	BIT_VEC cppVar_40449 = (cppVar_40448 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40450 = (cppVar_40449 & cppMask_un_5_);
	BIT_VEC cppVar_40451 = cppVar_40450 + 32;
	cppVar_40451 = (cppVar_40451 & cppMask_un_8_);
	cppVar_40438 = cppVar_40451;
	}
	bool cppVar_40453 = (cppVar_40438 == 144);
	if (cppVar_40453) {
	cppVar_40437 = P1;
	} else {
	BIT_VEC cppVar_40454;
	BIT_VEC cppVar_40455;
	BIT_VEC cppVar_40456 = PC + 1;
	cppVar_40456 = (cppVar_40456 & cppMask_un_16_);
	BIT_VEC cppVar_40457 = ROM.rd(cppVar_40456);
	BIT_VEC cppVar_40458 = (cppVar_40457 >> 7) & cppMask_un_1_;
	bool cppVar_40459 = (cppVar_40458 == 1);
	if (cppVar_40459) {
	BIT_VEC cppVar_40460 = PC + 1;
	cppVar_40460 = (cppVar_40460 & cppMask_un_16_);
	BIT_VEC cppVar_40461 = ROM.rd(cppVar_40460);
	BIT_VEC cppVar_40462 = (cppVar_40461 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40463 = (cppVar_40462 << 3) | 0;
	cppVar_40463 = (cppVar_40463 & cppMask_un_8_);
	cppVar_40455 = cppVar_40463;
	} else {
	BIT_VEC cppVar_40464 = PC + 1;
	cppVar_40464 = (cppVar_40464 & cppMask_un_16_);
	BIT_VEC cppVar_40465 = ROM.rd(cppVar_40464);
	BIT_VEC cppVar_40466 = (cppVar_40465 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40467 = (cppVar_40466 & cppMask_un_5_);
	BIT_VEC cppVar_40468 = cppVar_40467 + 32;
	cppVar_40468 = (cppVar_40468 & cppMask_un_8_);
	cppVar_40455 = cppVar_40468;
	}
	bool cppVar_40470 = (cppVar_40455 == 152);
	if (cppVar_40470) {
	cppVar_40454 = SCON;
	} else {
	BIT_VEC cppVar_40471;
	BIT_VEC cppVar_40472;
	BIT_VEC cppVar_40473 = PC + 1;
	cppVar_40473 = (cppVar_40473 & cppMask_un_16_);
	BIT_VEC cppVar_40474 = ROM.rd(cppVar_40473);
	BIT_VEC cppVar_40475 = (cppVar_40474 >> 7) & cppMask_un_1_;
	bool cppVar_40476 = (cppVar_40475 == 1);
	if (cppVar_40476) {
	BIT_VEC cppVar_40477 = PC + 1;
	cppVar_40477 = (cppVar_40477 & cppMask_un_16_);
	BIT_VEC cppVar_40478 = ROM.rd(cppVar_40477);
	BIT_VEC cppVar_40479 = (cppVar_40478 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40480 = (cppVar_40479 << 3) | 0;
	cppVar_40480 = (cppVar_40480 & cppMask_un_8_);
	cppVar_40472 = cppVar_40480;
	} else {
	BIT_VEC cppVar_40481 = PC + 1;
	cppVar_40481 = (cppVar_40481 & cppMask_un_16_);
	BIT_VEC cppVar_40482 = ROM.rd(cppVar_40481);
	BIT_VEC cppVar_40483 = (cppVar_40482 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40484 = (cppVar_40483 & cppMask_un_5_);
	BIT_VEC cppVar_40485 = cppVar_40484 + 32;
	cppVar_40485 = (cppVar_40485 & cppMask_un_8_);
	cppVar_40472 = cppVar_40485;
	}
	bool cppVar_40487 = (cppVar_40472 == 153);
	if (cppVar_40487) {
	cppVar_40471 = SBUF;
	} else {
	BIT_VEC cppVar_40488;
	BIT_VEC cppVar_40489;
	BIT_VEC cppVar_40490 = PC + 1;
	cppVar_40490 = (cppVar_40490 & cppMask_un_16_);
	BIT_VEC cppVar_40491 = ROM.rd(cppVar_40490);
	BIT_VEC cppVar_40492 = (cppVar_40491 >> 7) & cppMask_un_1_;
	bool cppVar_40493 = (cppVar_40492 == 1);
	if (cppVar_40493) {
	BIT_VEC cppVar_40494 = PC + 1;
	cppVar_40494 = (cppVar_40494 & cppMask_un_16_);
	BIT_VEC cppVar_40495 = ROM.rd(cppVar_40494);
	BIT_VEC cppVar_40496 = (cppVar_40495 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40497 = (cppVar_40496 << 3) | 0;
	cppVar_40497 = (cppVar_40497 & cppMask_un_8_);
	cppVar_40489 = cppVar_40497;
	} else {
	BIT_VEC cppVar_40498 = PC + 1;
	cppVar_40498 = (cppVar_40498 & cppMask_un_16_);
	BIT_VEC cppVar_40499 = ROM.rd(cppVar_40498);
	BIT_VEC cppVar_40500 = (cppVar_40499 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40501 = (cppVar_40500 & cppMask_un_5_);
	BIT_VEC cppVar_40502 = cppVar_40501 + 32;
	cppVar_40502 = (cppVar_40502 & cppMask_un_8_);
	cppVar_40489 = cppVar_40502;
	}
	bool cppVar_40504 = (cppVar_40489 == 160);
	if (cppVar_40504) {
	cppVar_40488 = P2;
	} else {
	BIT_VEC cppVar_40505;
	BIT_VEC cppVar_40506;
	BIT_VEC cppVar_40507 = PC + 1;
	cppVar_40507 = (cppVar_40507 & cppMask_un_16_);
	BIT_VEC cppVar_40508 = ROM.rd(cppVar_40507);
	BIT_VEC cppVar_40509 = (cppVar_40508 >> 7) & cppMask_un_1_;
	bool cppVar_40510 = (cppVar_40509 == 1);
	if (cppVar_40510) {
	BIT_VEC cppVar_40511 = PC + 1;
	cppVar_40511 = (cppVar_40511 & cppMask_un_16_);
	BIT_VEC cppVar_40512 = ROM.rd(cppVar_40511);
	BIT_VEC cppVar_40513 = (cppVar_40512 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40514 = (cppVar_40513 << 3) | 0;
	cppVar_40514 = (cppVar_40514 & cppMask_un_8_);
	cppVar_40506 = cppVar_40514;
	} else {
	BIT_VEC cppVar_40515 = PC + 1;
	cppVar_40515 = (cppVar_40515 & cppMask_un_16_);
	BIT_VEC cppVar_40516 = ROM.rd(cppVar_40515);
	BIT_VEC cppVar_40517 = (cppVar_40516 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40518 = (cppVar_40517 & cppMask_un_5_);
	BIT_VEC cppVar_40519 = cppVar_40518 + 32;
	cppVar_40519 = (cppVar_40519 & cppMask_un_8_);
	cppVar_40506 = cppVar_40519;
	}
	bool cppVar_40521 = (cppVar_40506 == 168);
	if (cppVar_40521) {
	cppVar_40505 = IE;
	} else {
	BIT_VEC cppVar_40522;
	BIT_VEC cppVar_40523;
	BIT_VEC cppVar_40524 = PC + 1;
	cppVar_40524 = (cppVar_40524 & cppMask_un_16_);
	BIT_VEC cppVar_40525 = ROM.rd(cppVar_40524);
	BIT_VEC cppVar_40526 = (cppVar_40525 >> 7) & cppMask_un_1_;
	bool cppVar_40527 = (cppVar_40526 == 1);
	if (cppVar_40527) {
	BIT_VEC cppVar_40528 = PC + 1;
	cppVar_40528 = (cppVar_40528 & cppMask_un_16_);
	BIT_VEC cppVar_40529 = ROM.rd(cppVar_40528);
	BIT_VEC cppVar_40530 = (cppVar_40529 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40531 = (cppVar_40530 << 3) | 0;
	cppVar_40531 = (cppVar_40531 & cppMask_un_8_);
	cppVar_40523 = cppVar_40531;
	} else {
	BIT_VEC cppVar_40532 = PC + 1;
	cppVar_40532 = (cppVar_40532 & cppMask_un_16_);
	BIT_VEC cppVar_40533 = ROM.rd(cppVar_40532);
	BIT_VEC cppVar_40534 = (cppVar_40533 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40535 = (cppVar_40534 & cppMask_un_5_);
	BIT_VEC cppVar_40536 = cppVar_40535 + 32;
	cppVar_40536 = (cppVar_40536 & cppMask_un_8_);
	cppVar_40523 = cppVar_40536;
	}
	bool cppVar_40538 = (cppVar_40523 == 176);
	if (cppVar_40538) {
	cppVar_40522 = P3;
	} else {
	BIT_VEC cppVar_40539;
	BIT_VEC cppVar_40540;
	BIT_VEC cppVar_40541 = PC + 1;
	cppVar_40541 = (cppVar_40541 & cppMask_un_16_);
	BIT_VEC cppVar_40542 = ROM.rd(cppVar_40541);
	BIT_VEC cppVar_40543 = (cppVar_40542 >> 7) & cppMask_un_1_;
	bool cppVar_40544 = (cppVar_40543 == 1);
	if (cppVar_40544) {
	BIT_VEC cppVar_40545 = PC + 1;
	cppVar_40545 = (cppVar_40545 & cppMask_un_16_);
	BIT_VEC cppVar_40546 = ROM.rd(cppVar_40545);
	BIT_VEC cppVar_40547 = (cppVar_40546 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40548 = (cppVar_40547 << 3) | 0;
	cppVar_40548 = (cppVar_40548 & cppMask_un_8_);
	cppVar_40540 = cppVar_40548;
	} else {
	BIT_VEC cppVar_40549 = PC + 1;
	cppVar_40549 = (cppVar_40549 & cppMask_un_16_);
	BIT_VEC cppVar_40550 = ROM.rd(cppVar_40549);
	BIT_VEC cppVar_40551 = (cppVar_40550 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40552 = (cppVar_40551 & cppMask_un_5_);
	BIT_VEC cppVar_40553 = cppVar_40552 + 32;
	cppVar_40553 = (cppVar_40553 & cppMask_un_8_);
	cppVar_40540 = cppVar_40553;
	}
	bool cppVar_40555 = (cppVar_40540 == 184);
	if (cppVar_40555) {
	cppVar_40539 = IP;
	} else {
	BIT_VEC cppVar_40556;
	BIT_VEC cppVar_40557;
	BIT_VEC cppVar_40558 = PC + 1;
	cppVar_40558 = (cppVar_40558 & cppMask_un_16_);
	BIT_VEC cppVar_40559 = ROM.rd(cppVar_40558);
	BIT_VEC cppVar_40560 = (cppVar_40559 >> 7) & cppMask_un_1_;
	bool cppVar_40561 = (cppVar_40560 == 1);
	if (cppVar_40561) {
	BIT_VEC cppVar_40562 = PC + 1;
	cppVar_40562 = (cppVar_40562 & cppMask_un_16_);
	BIT_VEC cppVar_40563 = ROM.rd(cppVar_40562);
	BIT_VEC cppVar_40564 = (cppVar_40563 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40565 = (cppVar_40564 << 3) | 0;
	cppVar_40565 = (cppVar_40565 & cppMask_un_8_);
	cppVar_40557 = cppVar_40565;
	} else {
	BIT_VEC cppVar_40566 = PC + 1;
	cppVar_40566 = (cppVar_40566 & cppMask_un_16_);
	BIT_VEC cppVar_40567 = ROM.rd(cppVar_40566);
	BIT_VEC cppVar_40568 = (cppVar_40567 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40569 = (cppVar_40568 & cppMask_un_5_);
	BIT_VEC cppVar_40570 = cppVar_40569 + 32;
	cppVar_40570 = (cppVar_40570 & cppMask_un_8_);
	cppVar_40557 = cppVar_40570;
	}
	bool cppVar_40572 = (cppVar_40557 == 208);
	if (cppVar_40572) {
	cppVar_40556 = PSW;
	} else {
	BIT_VEC cppVar_40573;
	BIT_VEC cppVar_40574;
	BIT_VEC cppVar_40575 = PC + 1;
	cppVar_40575 = (cppVar_40575 & cppMask_un_16_);
	BIT_VEC cppVar_40576 = ROM.rd(cppVar_40575);
	BIT_VEC cppVar_40577 = (cppVar_40576 >> 7) & cppMask_un_1_;
	bool cppVar_40578 = (cppVar_40577 == 1);
	if (cppVar_40578) {
	BIT_VEC cppVar_40579 = PC + 1;
	cppVar_40579 = (cppVar_40579 & cppMask_un_16_);
	BIT_VEC cppVar_40580 = ROM.rd(cppVar_40579);
	BIT_VEC cppVar_40581 = (cppVar_40580 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40582 = (cppVar_40581 << 3) | 0;
	cppVar_40582 = (cppVar_40582 & cppMask_un_8_);
	cppVar_40574 = cppVar_40582;
	} else {
	BIT_VEC cppVar_40583 = PC + 1;
	cppVar_40583 = (cppVar_40583 & cppMask_un_16_);
	BIT_VEC cppVar_40584 = ROM.rd(cppVar_40583);
	BIT_VEC cppVar_40585 = (cppVar_40584 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40586 = (cppVar_40585 & cppMask_un_5_);
	BIT_VEC cppVar_40587 = cppVar_40586 + 32;
	cppVar_40587 = (cppVar_40587 & cppMask_un_8_);
	cppVar_40574 = cppVar_40587;
	}
	bool cppVar_40589 = (cppVar_40574 == 224);
	if (cppVar_40589) {
	cppVar_40573 = ACC;
	} else {
	BIT_VEC cppVar_40590;
	BIT_VEC cppVar_40591;
	BIT_VEC cppVar_40592 = PC + 1;
	cppVar_40592 = (cppVar_40592 & cppMask_un_16_);
	BIT_VEC cppVar_40593 = ROM.rd(cppVar_40592);
	BIT_VEC cppVar_40594 = (cppVar_40593 >> 7) & cppMask_un_1_;
	bool cppVar_40595 = (cppVar_40594 == 1);
	if (cppVar_40595) {
	BIT_VEC cppVar_40596 = PC + 1;
	cppVar_40596 = (cppVar_40596 & cppMask_un_16_);
	BIT_VEC cppVar_40597 = ROM.rd(cppVar_40596);
	BIT_VEC cppVar_40598 = (cppVar_40597 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40599 = (cppVar_40598 << 3) | 0;
	cppVar_40599 = (cppVar_40599 & cppMask_un_8_);
	cppVar_40591 = cppVar_40599;
	} else {
	BIT_VEC cppVar_40600 = PC + 1;
	cppVar_40600 = (cppVar_40600 & cppMask_un_16_);
	BIT_VEC cppVar_40601 = ROM.rd(cppVar_40600);
	BIT_VEC cppVar_40602 = (cppVar_40601 >> 3) & cppMask_un_5_;
	BIT_VEC cppVar_40603 = (cppVar_40602 & cppMask_un_5_);
	BIT_VEC cppVar_40604 = cppVar_40603 + 32;
	cppVar_40604 = (cppVar_40604 & cppMask_un_8_);
	cppVar_40591 = cppVar_40604;
	}
	bool cppVar_40606 = (cppVar_40591 == 240);
	if (cppVar_40606) {
	cppVar_40590 = B;
	} else {
	cppVar_40590 = 0;
	}
	cppVar_40573 = cppVar_40590;
	}
	cppVar_40556 = cppVar_40573;
	}
	cppVar_40539 = cppVar_40556;
	}
	cppVar_40522 = cppVar_40539;
	}
	cppVar_40505 = cppVar_40522;
	}
	cppVar_40488 = cppVar_40505;
	}
	cppVar_40471 = cppVar_40488;
	}
	cppVar_40454 = cppVar_40471;
	}
	cppVar_40437 = cppVar_40454;
	}
	cppVar_40420 = cppVar_40437;
	}
	cppVar_40403 = cppVar_40420;
	}
	cppVar_40386 = cppVar_40403;
	}
	cppVar_40369 = cppVar_40386;
	}
	cppVar_40352 = cppVar_40369;
	}
	cppVar_40335 = cppVar_40352;
	}
	cppVar_40318 = cppVar_40335;
	}
	cppVar_40301 = cppVar_40318;
	}
	cppVar_40284 = cppVar_40301;
	}
	cppVar_40267 = cppVar_40284;
	}
	cppVar_40250 = cppVar_40267;
	}
	cppVar_40217 = cppVar_40250;
	}
	BIT_VEC cppVar_40608 = cppVar_40216 & cppVar_40217;
	BIT_VEC cppVar_40610 = 0;
	BIT_VEC cppVar_40611 = PC + 1;
	cppVar_40611 = (cppVar_40611 & cppMask_un_16_);
	BIT_VEC cppVar_40612 = ROM.rd(cppVar_40611);
	BIT_VEC cppVar_40613 = (cppVar_40612 >> 0) & cppMask_un_3_;
	BIT_VEC cppVar_40614 = (cppVar_40613 & cppMask_un_3_);
	BIT_VEC cppVar_40615 = cppVar_40610 << static_cast<unsigned>(cppVar_40614);
	cppVar_40615 = (cppVar_40615 & cppMask_un_8_);
	BIT_VEC cppVar_40616 = cppVar_40608 | cppVar_40615;
	cppVar_40189 = cppVar_40616;
	} else {
	cppVar_40189 = P3;
	}
	cppVar_40181 = cppVar_40189;
	} else {
	BIT_VEC cppVar_40617;
	BIT_VEC cppVar_40618 = ROM.rd(PC);
	bool cppVar_40620 = (cppVar_40618 == 5);
	if (cppVar_40620) {
	BIT_VEC cppVar_40621;
	BIT_VEC cppVar_40623 = PC + 1;
	cppVar_40623 = (cppVar_40623 & cppMask_un_16_);
	BIT_VEC cppVar_40624 = ROM.rd(cppVar_40623);
	bool cppVar_40626 = (cppVar_40624 == 176);
	if (cppVar_40626) {
	BIT_VEC cppVar_40627;
	BIT_VEC cppVar_40628 = PC + 1;
	cppVar_40628 = (cppVar_40628 & cppMask_un_16_);
	BIT_VEC cppVar_40629 = ROM.rd(cppVar_40628);
	BIT_VEC cppVar_40630 = (cppVar_40629 >> 7) & cppMask_un_1_;
	bool cppVar_40632 = (cppVar_40630 == 0);
	if (cppVar_40632) {
	BIT_VEC cppVar_40633 = PC + 1;
	cppVar_40633 = (cppVar_40633 & cppMask_un_16_);
	BIT_VEC cppVar_40634 = ROM.rd(cppVar_40633);
	BIT_VEC cppVar_40635 = IRAM.rd(cppVar_40634);
	cppVar_40627 = cppVar_40635;
	} else {
	BIT_VEC cppVar_40636;
	BIT_VEC cppVar_40637 = PC + 1;
	cppVar_40637 = (cppVar_40637 & cppMask_un_16_);
	BIT_VEC cppVar_40638 = ROM.rd(cppVar_40637);
	bool cppVar_40640 = (cppVar_40638 == 128);
	if (cppVar_40640) {
	cppVar_40636 = P0;
	} else {
	BIT_VEC cppVar_40641;
	BIT_VEC cppVar_40642 = PC + 1;
	cppVar_40642 = (cppVar_40642 & cppMask_un_16_);
	BIT_VEC cppVar_40643 = ROM.rd(cppVar_40642);
	bool cppVar_40645 = (cppVar_40643 == 129);
	if (cppVar_40645) {
	cppVar_40641 = SP;
	} else {
	BIT_VEC cppVar_40646;
	BIT_VEC cppVar_40647 = PC + 1;
	cppVar_40647 = (cppVar_40647 & cppMask_un_16_);
	BIT_VEC cppVar_40648 = ROM.rd(cppVar_40647);
	bool cppVar_40650 = (cppVar_40648 == 130);
	if (cppVar_40650) {
	cppVar_40646 = DPL;
	} else {
	BIT_VEC cppVar_40651;
	BIT_VEC cppVar_40652 = PC + 1;
	cppVar_40652 = (cppVar_40652 & cppMask_un_16_);
	BIT_VEC cppVar_40653 = ROM.rd(cppVar_40652);
	bool cppVar_40655 = (cppVar_40653 == 131);
	if (cppVar_40655) {
	cppVar_40651 = DPH;
	} else {
	BIT_VEC cppVar_40656;
	BIT_VEC cppVar_40657 = PC + 1;
	cppVar_40657 = (cppVar_40657 & cppMask_un_16_);
	BIT_VEC cppVar_40658 = ROM.rd(cppVar_40657);
	bool cppVar_40660 = (cppVar_40658 == 135);
	if (cppVar_40660) {
	cppVar_40656 = PCON;
	} else {
	BIT_VEC cppVar_40661;
	BIT_VEC cppVar_40662 = PC + 1;
	cppVar_40662 = (cppVar_40662 & cppMask_un_16_);
	BIT_VEC cppVar_40663 = ROM.rd(cppVar_40662);
	bool cppVar_40665 = (cppVar_40663 == 136);
	if (cppVar_40665) {
	cppVar_40661 = TCON;
	} else {
	BIT_VEC cppVar_40666;
	BIT_VEC cppVar_40667 = PC + 1;
	cppVar_40667 = (cppVar_40667 & cppMask_un_16_);
	BIT_VEC cppVar_40668 = ROM.rd(cppVar_40667);
	bool cppVar_40670 = (cppVar_40668 == 137);
	if (cppVar_40670) {
	cppVar_40666 = TMOD;
	} else {
	BIT_VEC cppVar_40671;
	BIT_VEC cppVar_40672 = PC + 1;
	cppVar_40672 = (cppVar_40672 & cppMask_un_16_);
	BIT_VEC cppVar_40673 = ROM.rd(cppVar_40672);
	bool cppVar_40675 = (cppVar_40673 == 138);
	if (cppVar_40675) {
	cppVar_40671 = TL0;
	} else {
	BIT_VEC cppVar_40676;
	BIT_VEC cppVar_40677 = PC + 1;
	cppVar_40677 = (cppVar_40677 & cppMask_un_16_);
	BIT_VEC cppVar_40678 = ROM.rd(cppVar_40677);
	bool cppVar_40680 = (cppVar_40678 == 140);
	if (cppVar_40680) {
	cppVar_40676 = TH0;
	} else {
	BIT_VEC cppVar_40681;
	BIT_VEC cppVar_40682 = PC + 1;
	cppVar_40682 = (cppVar_40682 & cppMask_un_16_);
	BIT_VEC cppVar_40683 = ROM.rd(cppVar_40682);
	bool cppVar_40685 = (cppVar_40683 == 139);
	if (cppVar_40685) {
	cppVar_40681 = TL1;
	} else {
	BIT_VEC cppVar_40686;
	BIT_VEC cppVar_40687 = PC + 1;
	cppVar_40687 = (cppVar_40687 & cppMask_un_16_);
	BIT_VEC cppVar_40688 = ROM.rd(cppVar_40687);
	bool cppVar_40690 = (cppVar_40688 == 141);
	if (cppVar_40690) {
	cppVar_40686 = TH1;
	} else {
	BIT_VEC cppVar_40691;
	BIT_VEC cppVar_40692 = PC + 1;
	cppVar_40692 = (cppVar_40692 & cppMask_un_16_);
	BIT_VEC cppVar_40693 = ROM.rd(cppVar_40692);
	bool cppVar_40695 = (cppVar_40693 == 144);
	if (cppVar_40695) {
	cppVar_40691 = P1;
	} else {
	BIT_VEC cppVar_40696;
	BIT_VEC cppVar_40697 = PC + 1;
	cppVar_40697 = (cppVar_40697 & cppMask_un_16_);
	BIT_VEC cppVar_40698 = ROM.rd(cppVar_40697);
	bool cppVar_40700 = (cppVar_40698 == 152);
	if (cppVar_40700) {
	cppVar_40696 = SCON;
	} else {
	BIT_VEC cppVar_40701;
	BIT_VEC cppVar_40702 = PC + 1;
	cppVar_40702 = (cppVar_40702 & cppMask_un_16_);
	BIT_VEC cppVar_40703 = ROM.rd(cppVar_40702);
	bool cppVar_40705 = (cppVar_40703 == 153);
	if (cppVar_40705) {
	cppVar_40701 = SBUF;
	} else {
	BIT_VEC cppVar_40706;
	BIT_VEC cppVar_40707 = PC + 1;
	cppVar_40707 = (cppVar_40707 & cppMask_un_16_);
	BIT_VEC cppVar_40708 = ROM.rd(cppVar_40707);
	bool cppVar_40710 = (cppVar_40708 == 160);
	if (cppVar_40710) {
	cppVar_40706 = P2;
	} else {
	BIT_VEC cppVar_40711;
	BIT_VEC cppVar_40712 = PC + 1;
	cppVar_40712 = (cppVar_40712 & cppMask_un_16_);
	BIT_VEC cppVar_40713 = ROM.rd(cppVar_40712);
	bool cppVar_40715 = (cppVar_40713 == 168);
	if (cppVar_40715) {
	cppVar_40711 = IE;
	} else {
	BIT_VEC cppVar_40716;
	BIT_VEC cppVar_40717 = PC + 1;
	cppVar_40717 = (cppVar_40717 & cppMask_un_16_);
	BIT_VEC cppVar_40718 = ROM.rd(cppVar_40717);
	bool cppVar_40720 = (cppVar_40718 == 176);
	if (cppVar_40720) {
	cppVar_40716 = P3;
	} else {
	BIT_VEC cppVar_40721;
	BIT_VEC cppVar_40722 = PC + 1;
	cppVar_40722 = (cppVar_40722 & cppMask_un_16_);
	BIT_VEC cppVar_40723 = ROM.rd(cppVar_40722);
	bool cppVar_40725 = (cppVar_40723 == 184);
	if (cppVar_40725) {
	cppVar_40721 = IP;
	} else {
	BIT_VEC cppVar_40726;
	BIT_VEC cppVar_40727 = PC + 1;
	cppVar_40727 = (cppVar_40727 & cppMask_un_16_);
	BIT_VEC cppVar_40728 = ROM.rd(cppVar_40727);
	bool cppVar_40730 = (cppVar_40728 == 208);
	if (cppVar_40730) {
	cppVar_40726 = PSW;
	} else {
	BIT_VEC cppVar_40731;
	BIT_VEC cppVar_40732 = PC + 1;
	cppVar_40732 = (cppVar_40732 & cppMask_un_16_);
	BIT_VEC cppVar_40733 = ROM.rd(cppVar_40732);
	bool cppVar_40735 = (cppVar_40733 == 224);
	if (cppVar_40735) {
	cppVar_40731 = ACC;
	} else {
	BIT_VEC cppVar_40736;
	BIT_VEC cppVar_40737 = PC + 1;
	cppVar_40737 = (cppVar_40737 & cppMask_un_16_);
	BIT_VEC cppVar_40738 = ROM.rd(cppVar_40737);
	bool cppVar_40740 = (cppVar_40738 == 240);
	if (cppVar_40740) {
	cppVar_40736 = B;
	} else {
	cppVar_40736 = 0;
	}
	cppVar_40731 = cppVar_40736;
	}
	cppVar_40726 = cppVar_40731;
	}
	cppVar_40721 = cppVar_40726;
	}
	cppVar_40716 = cppVar_40721;
	}
	cppVar_40711 = cppVar_40716;
	}
	cppVar_40706 = cppVar_40711;
	}
	cppVar_40701 = cppVar_40706;
	}
	cppVar_40696 = cppVar_40701;
	}
	cppVar_40691 = cppVar_40696;
	}
	cppVar_40686 = cppVar_40691;
	}
	cppVar_40681 = cppVar_40686;
	}
	cppVar_40676 = cppVar_40681;
	}
	cppVar_40671 = cppVar_40676;
	}
	cppVar_40666 = cppVar_40671;
	}
	cppVar_40661 = cppVar_40666;
	}
	cppVar_40656 = cppVar_40661;
	}
	cppVar_40651 = cppVar_40656;
	}
	cppVar_40646 = cppVar_40651;
	}
	cppVar_40641 = cppVar_40646;
	}
	cppVar_40636 = cppVar_40641;
	}
	cppVar_40627 = cppVar_40636;
	}
	BIT_VEC cppVar_40743 = cppVar_40627 + 1;
	cppVar_40743 = (cppVar_40743 & cppMask_un_8_);
	cppVar_40621 = cppVar_40743;
	} else {
	cppVar_40621 = P3;
	}
	cppVar_40617 = cppVar_40621;
	} else {
	BIT_VEC cppVar_40744;
	BIT_VEC cppVar_40745 = ROM.rd(PC);
	bool cppVar_40747 = (cppVar_40745 == 255);
	BIT_VEC cppVar_40748 = ROM.rd(PC);
	bool cppVar_40750 = (cppVar_40748 == 254);
	BIT_VEC cppVar_40751 = ROM.rd(PC);
	bool cppVar_40753 = (cppVar_40751 == 253);
	BIT_VEC cppVar_40754 = ROM.rd(PC);
	bool cppVar_40756 = (cppVar_40754 == 252);
	BIT_VEC cppVar_40757 = ROM.rd(PC);
	bool cppVar_40759 = (cppVar_40757 == 251);
	BIT_VEC cppVar_40760 = ROM.rd(PC);
	bool cppVar_40762 = (cppVar_40760 == 250);
	BIT_VEC cppVar_40763 = ROM.rd(PC);
	bool cppVar_40765 = (cppVar_40763 == 249);
	BIT_VEC cppVar_40766 = ROM.rd(PC);
	bool cppVar_40768 = (cppVar_40766 == 248);
	BIT_VEC cppVar_40769 = ROM.rd(PC);
	bool cppVar_40771 = (cppVar_40769 == 247);
	BIT_VEC cppVar_40772 = ROM.rd(PC);
	bool cppVar_40774 = (cppVar_40772 == 246);
	BIT_VEC cppVar_40775 = ROM.rd(PC);
	bool cppVar_40777 = (cppVar_40775 == 244);
	BIT_VEC cppVar_40778 = ROM.rd(PC);
	bool cppVar_40780 = (cppVar_40778 == 243);
	BIT_VEC cppVar_40781 = ROM.rd(PC);
	bool cppVar_40783 = (cppVar_40781 == 242);
	BIT_VEC cppVar_40784 = ROM.rd(PC);
	bool cppVar_40786 = (cppVar_40784 == 241);
	BIT_VEC cppVar_40787 = ROM.rd(PC);
	bool cppVar_40789 = (cppVar_40787 == 240);
	BIT_VEC cppVar_40790 = ROM.rd(PC);
	bool cppVar_40792 = (cppVar_40790 == 239);
	BIT_VEC cppVar_40793 = ROM.rd(PC);
	bool cppVar_40795 = (cppVar_40793 == 238);
	BIT_VEC cppVar_40796 = ROM.rd(PC);
	bool cppVar_40798 = (cppVar_40796 == 237);
	BIT_VEC cppVar_40799 = ROM.rd(PC);
	bool cppVar_40801 = (cppVar_40799 == 236);
	BIT_VEC cppVar_40802 = ROM.rd(PC);
	bool cppVar_40804 = (cppVar_40802 == 235);
	BIT_VEC cppVar_40805 = ROM.rd(PC);
	bool cppVar_40807 = (cppVar_40805 == 234);
	BIT_VEC cppVar_40808 = ROM.rd(PC);
	bool cppVar_40810 = (cppVar_40808 == 233);
	BIT_VEC cppVar_40811 = ROM.rd(PC);
	bool cppVar_40813 = (cppVar_40811 == 232);
	BIT_VEC cppVar_40814 = ROM.rd(PC);
	bool cppVar_40816 = (cppVar_40814 == 231);
	BIT_VEC cppVar_40817 = ROM.rd(PC);
	bool cppVar_40819 = (cppVar_40817 == 230);
	BIT_VEC cppVar_40820 = ROM.rd(PC);
	bool cppVar_40822 = (cppVar_40820 == 229);
	BIT_VEC cppVar_40823 = ROM.rd(PC);
	bool cppVar_40825 = (cppVar_40823 == 228);
	BIT_VEC cppVar_40826 = ROM.rd(PC);
	bool cppVar_40828 = (cppVar_40826 == 227);
	BIT_VEC cppVar_40829 = ROM.rd(PC);
	bool cppVar_40831 = (cppVar_40829 == 226);
	BIT_VEC cppVar_40832 = ROM.rd(PC);
	bool cppVar_40834 = (cppVar_40832 == 225);
	BIT_VEC cppVar_40835 = ROM.rd(PC);
	bool cppVar_40837 = (cppVar_40835 == 224);
	BIT_VEC cppVar_40838 = ROM.rd(PC);
	bool cppVar_40840 = (cppVar_40838 == 223);
	BIT_VEC cppVar_40841 = ROM.rd(PC);
	bool cppVar_40843 = (cppVar_40841 == 222);
	BIT_VEC cppVar_40844 = ROM.rd(PC);
	bool cppVar_40846 = (cppVar_40844 == 221);
	BIT_VEC cppVar_40847 = ROM.rd(PC);
	bool cppVar_40849 = (cppVar_40847 == 220);
	BIT_VEC cppVar_40850 = ROM.rd(PC);
	bool cppVar_40852 = (cppVar_40850 == 219);
	BIT_VEC cppVar_40853 = ROM.rd(PC);
	bool cppVar_40855 = (cppVar_40853 == 218);
	BIT_VEC cppVar_40856 = ROM.rd(PC);
	bool cppVar_40858 = (cppVar_40856 == 217);
	BIT_VEC cppVar_40859 = ROM.rd(PC);
	bool cppVar_40861 = (cppVar_40859 == 216);
	BIT_VEC cppVar_40862 = ROM.rd(PC);
	bool cppVar_40864 = (cppVar_40862 == 215);
	BIT_VEC cppVar_40865 = ROM.rd(PC);
	bool cppVar_40867 = (cppVar_40865 == 214);
	BIT_VEC cppVar_40868 = ROM.rd(PC);
	bool cppVar_40870 = (cppVar_40868 == 212);
	BIT_VEC cppVar_40871 = ROM.rd(PC);
	bool cppVar_40873 = (cppVar_40871 == 211);
	BIT_VEC cppVar_40874 = ROM.rd(PC);
	bool cppVar_40876 = (cppVar_40874 == 209);
	BIT_VEC cppVar_40877 = ROM.rd(PC);
	bool cppVar_40879 = (cppVar_40877 == 207);
	BIT_VEC cppVar_40880 = ROM.rd(PC);
	bool cppVar_40882 = (cppVar_40880 == 206);
	BIT_VEC cppVar_40883 = ROM.rd(PC);
	bool cppVar_40885 = (cppVar_40883 == 205);
	BIT_VEC cppVar_40886 = ROM.rd(PC);
	bool cppVar_40888 = (cppVar_40886 == 204);
	BIT_VEC cppVar_40889 = ROM.rd(PC);
	bool cppVar_40891 = (cppVar_40889 == 203);
	BIT_VEC cppVar_40892 = ROM.rd(PC);
	bool cppVar_40894 = (cppVar_40892 == 202);
	BIT_VEC cppVar_40895 = ROM.rd(PC);
	bool cppVar_40897 = (cppVar_40895 == 201);
	BIT_VEC cppVar_40898 = ROM.rd(PC);
	bool cppVar_40900 = (cppVar_40898 == 200);
	BIT_VEC cppVar_40901 = ROM.rd(PC);
	bool cppVar_40903 = (cppVar_40901 == 199);
	BIT_VEC cppVar_40904 = ROM.rd(PC);
	bool cppVar_40906 = (cppVar_40904 == 198);
	BIT_VEC cppVar_40907 = ROM.rd(PC);
	bool cppVar_40909 = (cppVar_40907 == 196);
	BIT_VEC cppVar_40910 = ROM.rd(PC);
	bool cppVar_40912 = (cppVar_40910 == 195);
	BIT_VEC cppVar_40913 = ROM.rd(PC);
	bool cppVar_40915 = (cppVar_40913 == 193);
	BIT_VEC cppVar_40916 = ROM.rd(PC);
	bool cppVar_40918 = (cppVar_40916 == 192);
	BIT_VEC cppVar_40919 = ROM.rd(PC);
	bool cppVar_40921 = (cppVar_40919 == 191);
	BIT_VEC cppVar_40922 = ROM.rd(PC);
	bool cppVar_40924 = (cppVar_40922 == 190);
	BIT_VEC cppVar_40925 = ROM.rd(PC);
	bool cppVar_40927 = (cppVar_40925 == 189);
	BIT_VEC cppVar_40928 = ROM.rd(PC);
	bool cppVar_40930 = (cppVar_40928 == 188);
	BIT_VEC cppVar_40931 = ROM.rd(PC);
	bool cppVar_40933 = (cppVar_40931 == 187);
	BIT_VEC cppVar_40934 = ROM.rd(PC);
	bool cppVar_40936 = (cppVar_40934 == 186);
	BIT_VEC cppVar_40937 = ROM.rd(PC);
	bool cppVar_40939 = (cppVar_40937 == 185);
	BIT_VEC cppVar_40940 = ROM.rd(PC);
	bool cppVar_40942 = (cppVar_40940 == 184);
	BIT_VEC cppVar_40943 = ROM.rd(PC);
	bool cppVar_40945 = (cppVar_40943 == 183);
	BIT_VEC cppVar_40946 = ROM.rd(PC);
	bool cppVar_40948 = (cppVar_40946 == 182);
	BIT_VEC cppVar_40949 = ROM.rd(PC);
	bool cppVar_40951 = (cppVar_40949 == 181);
	BIT_VEC cppVar_40952 = ROM.rd(PC);
	bool cppVar_40954 = (cppVar_40952 == 180);
	BIT_VEC cppVar_40955 = ROM.rd(PC);
	bool cppVar_40957 = (cppVar_40955 == 179);
	BIT_VEC cppVar_40958 = ROM.rd(PC);
	bool cppVar_40960 = (cppVar_40958 == 177);
	BIT_VEC cppVar_40961 = ROM.rd(PC);
	bool cppVar_40963 = (cppVar_40961 == 176);
	BIT_VEC cppVar_40964 = ROM.rd(PC);
	bool cppVar_40966 = (cppVar_40964 == 175);
	BIT_VEC cppVar_40967 = ROM.rd(PC);
	bool cppVar_40969 = (cppVar_40967 == 174);
	BIT_VEC cppVar_40970 = ROM.rd(PC);
	bool cppVar_40972 = (cppVar_40970 == 173);
	BIT_VEC cppVar_40973 = ROM.rd(PC);
	bool cppVar_40975 = (cppVar_40973 == 172);
	BIT_VEC cppVar_40976 = ROM.rd(PC);
	bool cppVar_40978 = (cppVar_40976 == 171);
	BIT_VEC cppVar_40979 = ROM.rd(PC);
	bool cppVar_40981 = (cppVar_40979 == 170);
	BIT_VEC cppVar_40982 = ROM.rd(PC);
	bool cppVar_40984 = (cppVar_40982 == 169);
	BIT_VEC cppVar_40985 = ROM.rd(PC);
	bool cppVar_40987 = (cppVar_40985 == 168);
	BIT_VEC cppVar_40988 = ROM.rd(PC);
	bool cppVar_40990 = (cppVar_40988 == 167);
	BIT_VEC cppVar_40991 = ROM.rd(PC);
	bool cppVar_40993 = (cppVar_40991 == 166);
	BIT_VEC cppVar_40994 = ROM.rd(PC);
	bool cppVar_40996 = (cppVar_40994 == 165);
	BIT_VEC cppVar_40997 = ROM.rd(PC);
	bool cppVar_40999 = (cppVar_40997 == 164);
	BIT_VEC cppVar_41000 = ROM.rd(PC);
	bool cppVar_41002 = (cppVar_41000 == 163);
	BIT_VEC cppVar_41003 = ROM.rd(PC);
	bool cppVar_41005 = (cppVar_41003 == 162);
	BIT_VEC cppVar_41006 = ROM.rd(PC);
	bool cppVar_41008 = (cppVar_41006 == 161);
	BIT_VEC cppVar_41009 = ROM.rd(PC);
	bool cppVar_41011 = (cppVar_41009 == 160);
	BIT_VEC cppVar_41012 = ROM.rd(PC);
	bool cppVar_41014 = (cppVar_41012 == 159);
	BIT_VEC cppVar_41015 = ROM.rd(PC);
	bool cppVar_41017 = (cppVar_41015 == 158);
	BIT_VEC cppVar_41018 = ROM.rd(PC);
	bool cppVar_41020 = (cppVar_41018 == 157);
	BIT_VEC cppVar_41021 = ROM.rd(PC);
	bool cppVar_41023 = (cppVar_41021 == 156);
	BIT_VEC cppVar_41024 = ROM.rd(PC);
	bool cppVar_41026 = (cppVar_41024 == 155);
	BIT_VEC cppVar_41027 = ROM.rd(PC);
	bool cppVar_41029 = (cppVar_41027 == 154);
	BIT_VEC cppVar_41030 = ROM.rd(PC);
	bool cppVar_41032 = (cppVar_41030 == 153);
	BIT_VEC cppVar_41033 = ROM.rd(PC);
	bool cppVar_41035 = (cppVar_41033 == 152);
	BIT_VEC cppVar_41036 = ROM.rd(PC);
	bool cppVar_41038 = (cppVar_41036 == 151);
	BIT_VEC cppVar_41039 = ROM.rd(PC);
	bool cppVar_41041 = (cppVar_41039 == 150);
	BIT_VEC cppVar_41042 = ROM.rd(PC);
	bool cppVar_41044 = (cppVar_41042 == 149);
	BIT_VEC cppVar_41045 = ROM.rd(PC);
	bool cppVar_41047 = (cppVar_41045 == 148);
	BIT_VEC cppVar_41048 = ROM.rd(PC);
	bool cppVar_41050 = (cppVar_41048 == 147);
	BIT_VEC cppVar_41051 = ROM.rd(PC);
	bool cppVar_41053 = (cppVar_41051 == 145);
	BIT_VEC cppVar_41054 = ROM.rd(PC);
	bool cppVar_41056 = (cppVar_41054 == 144);
	BIT_VEC cppVar_41057 = ROM.rd(PC);
	bool cppVar_41059 = (cppVar_41057 == 132);
	BIT_VEC cppVar_41060 = ROM.rd(PC);
	bool cppVar_41062 = (cppVar_41060 == 131);
	BIT_VEC cppVar_41063 = ROM.rd(PC);
	bool cppVar_41065 = (cppVar_41063 == 130);
	BIT_VEC cppVar_41066 = ROM.rd(PC);
	bool cppVar_41068 = (cppVar_41066 == 129);
	BIT_VEC cppVar_41069 = ROM.rd(PC);
	bool cppVar_41071 = (cppVar_41069 == 128);
	BIT_VEC cppVar_41072 = ROM.rd(PC);
	bool cppVar_41074 = (cppVar_41072 == 127);
	BIT_VEC cppVar_41075 = ROM.rd(PC);
	bool cppVar_41077 = (cppVar_41075 == 126);
	BIT_VEC cppVar_41078 = ROM.rd(PC);
	bool cppVar_41080 = (cppVar_41078 == 125);
	BIT_VEC cppVar_41081 = ROM.rd(PC);
	bool cppVar_41083 = (cppVar_41081 == 124);
	BIT_VEC cppVar_41084 = ROM.rd(PC);
	bool cppVar_41086 = (cppVar_41084 == 123);
	BIT_VEC cppVar_41087 = ROM.rd(PC);
	bool cppVar_41089 = (cppVar_41087 == 122);
	BIT_VEC cppVar_41090 = ROM.rd(PC);
	bool cppVar_41092 = (cppVar_41090 == 121);
	BIT_VEC cppVar_41093 = ROM.rd(PC);
	bool cppVar_41095 = (cppVar_41093 == 120);
	BIT_VEC cppVar_41096 = ROM.rd(PC);
	bool cppVar_41098 = (cppVar_41096 == 119);
	BIT_VEC cppVar_41099 = ROM.rd(PC);
	bool cppVar_41101 = (cppVar_41099 == 118);
	BIT_VEC cppVar_41102 = ROM.rd(PC);
	bool cppVar_41104 = (cppVar_41102 == 116);
	BIT_VEC cppVar_41105 = ROM.rd(PC);
	bool cppVar_41107 = (cppVar_41105 == 115);
	BIT_VEC cppVar_41108 = ROM.rd(PC);
	bool cppVar_41110 = (cppVar_41108 == 114);
	BIT_VEC cppVar_41111 = ROM.rd(PC);
	bool cppVar_41113 = (cppVar_41111 == 113);
	BIT_VEC cppVar_41114 = ROM.rd(PC);
	bool cppVar_41116 = (cppVar_41114 == 112);
	BIT_VEC cppVar_41117 = ROM.rd(PC);
	bool cppVar_41119 = (cppVar_41117 == 111);
	BIT_VEC cppVar_41120 = ROM.rd(PC);
	bool cppVar_41122 = (cppVar_41120 == 110);
	BIT_VEC cppVar_41123 = ROM.rd(PC);
	bool cppVar_41125 = (cppVar_41123 == 109);
	BIT_VEC cppVar_41126 = ROM.rd(PC);
	bool cppVar_41128 = (cppVar_41126 == 108);
	BIT_VEC cppVar_41129 = ROM.rd(PC);
	bool cppVar_41131 = (cppVar_41129 == 107);
	BIT_VEC cppVar_41132 = ROM.rd(PC);
	bool cppVar_41134 = (cppVar_41132 == 106);
	BIT_VEC cppVar_41135 = ROM.rd(PC);
	bool cppVar_41137 = (cppVar_41135 == 105);
	BIT_VEC cppVar_41138 = ROM.rd(PC);
	bool cppVar_41140 = (cppVar_41138 == 104);
	BIT_VEC cppVar_41141 = ROM.rd(PC);
	bool cppVar_41143 = (cppVar_41141 == 103);
	BIT_VEC cppVar_41144 = ROM.rd(PC);
	bool cppVar_41146 = (cppVar_41144 == 102);
	BIT_VEC cppVar_41147 = ROM.rd(PC);
	bool cppVar_41149 = (cppVar_41147 == 101);
	BIT_VEC cppVar_41150 = ROM.rd(PC);
	bool cppVar_41152 = (cppVar_41150 == 100);
	BIT_VEC cppVar_41153 = ROM.rd(PC);
	bool cppVar_41155 = (cppVar_41153 == 97);
	BIT_VEC cppVar_41156 = ROM.rd(PC);
	bool cppVar_41158 = (cppVar_41156 == 96);
	BIT_VEC cppVar_41159 = ROM.rd(PC);
	bool cppVar_41161 = (cppVar_41159 == 95);
	BIT_VEC cppVar_41162 = ROM.rd(PC);
	bool cppVar_41164 = (cppVar_41162 == 94);
	BIT_VEC cppVar_41165 = ROM.rd(PC);
	bool cppVar_41167 = (cppVar_41165 == 93);
	BIT_VEC cppVar_41168 = ROM.rd(PC);
	bool cppVar_41170 = (cppVar_41168 == 92);
	BIT_VEC cppVar_41171 = ROM.rd(PC);
	bool cppVar_41173 = (cppVar_41171 == 91);
	BIT_VEC cppVar_41174 = ROM.rd(PC);
	bool cppVar_41176 = (cppVar_41174 == 90);
	BIT_VEC cppVar_41177 = ROM.rd(PC);
	bool cppVar_41179 = (cppVar_41177 == 89);
	BIT_VEC cppVar_41180 = ROM.rd(PC);
	bool cppVar_41182 = (cppVar_41180 == 88);
	BIT_VEC cppVar_41183 = ROM.rd(PC);
	bool cppVar_41185 = (cppVar_41183 == 87);
	BIT_VEC cppVar_41186 = ROM.rd(PC);
	bool cppVar_41188 = (cppVar_41186 == 86);
	BIT_VEC cppVar_41189 = ROM.rd(PC);
	bool cppVar_41191 = (cppVar_41189 == 85);
	BIT_VEC cppVar_41192 = ROM.rd(PC);
	bool cppVar_41194 = (cppVar_41192 == 84);
	BIT_VEC cppVar_41195 = ROM.rd(PC);
	bool cppVar_41197 = (cppVar_41195 == 81);
	BIT_VEC cppVar_41198 = ROM.rd(PC);
	bool cppVar_41200 = (cppVar_41198 == 80);
	BIT_VEC cppVar_41201 = ROM.rd(PC);
	bool cppVar_41203 = (cppVar_41201 == 79);
	BIT_VEC cppVar_41204 = ROM.rd(PC);
	bool cppVar_41206 = (cppVar_41204 == 78);
	BIT_VEC cppVar_41207 = ROM.rd(PC);
	bool cppVar_41209 = (cppVar_41207 == 77);
	BIT_VEC cppVar_41210 = ROM.rd(PC);
	bool cppVar_41212 = (cppVar_41210 == 76);
	BIT_VEC cppVar_41213 = ROM.rd(PC);
	bool cppVar_41215 = (cppVar_41213 == 75);
	BIT_VEC cppVar_41216 = ROM.rd(PC);
	bool cppVar_41218 = (cppVar_41216 == 74);
	BIT_VEC cppVar_41219 = ROM.rd(PC);
	bool cppVar_41221 = (cppVar_41219 == 73);
	BIT_VEC cppVar_41222 = ROM.rd(PC);
	bool cppVar_41224 = (cppVar_41222 == 72);
	BIT_VEC cppVar_41225 = ROM.rd(PC);
	bool cppVar_41227 = (cppVar_41225 == 71);
	BIT_VEC cppVar_41228 = ROM.rd(PC);
	bool cppVar_41230 = (cppVar_41228 == 70);
	BIT_VEC cppVar_41231 = ROM.rd(PC);
	bool cppVar_41233 = (cppVar_41231 == 69);
	BIT_VEC cppVar_41234 = ROM.rd(PC);
	bool cppVar_41236 = (cppVar_41234 == 68);
	BIT_VEC cppVar_41237 = ROM.rd(PC);
	bool cppVar_41239 = (cppVar_41237 == 65);
	BIT_VEC cppVar_41240 = ROM.rd(PC);
	bool cppVar_41242 = (cppVar_41240 == 64);
	BIT_VEC cppVar_41243 = ROM.rd(PC);
	bool cppVar_41245 = (cppVar_41243 == 63);
	BIT_VEC cppVar_41246 = ROM.rd(PC);
	bool cppVar_41248 = (cppVar_41246 == 62);
	BIT_VEC cppVar_41249 = ROM.rd(PC);
	bool cppVar_41251 = (cppVar_41249 == 61);
	BIT_VEC cppVar_41252 = ROM.rd(PC);
	bool cppVar_41254 = (cppVar_41252 == 60);
	BIT_VEC cppVar_41255 = ROM.rd(PC);
	bool cppVar_41257 = (cppVar_41255 == 59);
	BIT_VEC cppVar_41258 = ROM.rd(PC);
	bool cppVar_41260 = (cppVar_41258 == 58);
	BIT_VEC cppVar_41261 = ROM.rd(PC);
	bool cppVar_41263 = (cppVar_41261 == 57);
	BIT_VEC cppVar_41264 = ROM.rd(PC);
	bool cppVar_41266 = (cppVar_41264 == 56);
	BIT_VEC cppVar_41267 = ROM.rd(PC);
	bool cppVar_41269 = (cppVar_41267 == 55);
	BIT_VEC cppVar_41270 = ROM.rd(PC);
	bool cppVar_41272 = (cppVar_41270 == 54);
	BIT_VEC cppVar_41273 = ROM.rd(PC);
	bool cppVar_41275 = (cppVar_41273 == 53);
	BIT_VEC cppVar_41276 = ROM.rd(PC);
	bool cppVar_41278 = (cppVar_41276 == 52);
	BIT_VEC cppVar_41279 = ROM.rd(PC);
	bool cppVar_41281 = (cppVar_41279 == 51);
	BIT_VEC cppVar_41282 = ROM.rd(PC);
	bool cppVar_41284 = (cppVar_41282 == 50);
	BIT_VEC cppVar_41285 = ROM.rd(PC);
	bool cppVar_41287 = (cppVar_41285 == 49);
	BIT_VEC cppVar_41288 = ROM.rd(PC);
	bool cppVar_41290 = (cppVar_41288 == 48);
	BIT_VEC cppVar_41291 = ROM.rd(PC);
	bool cppVar_41293 = (cppVar_41291 == 47);
	BIT_VEC cppVar_41294 = ROM.rd(PC);
	bool cppVar_41296 = (cppVar_41294 == 46);
	BIT_VEC cppVar_41297 = ROM.rd(PC);
	bool cppVar_41299 = (cppVar_41297 == 45);
	BIT_VEC cppVar_41300 = ROM.rd(PC);
	bool cppVar_41302 = (cppVar_41300 == 44);
	BIT_VEC cppVar_41303 = ROM.rd(PC);
	bool cppVar_41305 = (cppVar_41303 == 43);
	BIT_VEC cppVar_41306 = ROM.rd(PC);
	bool cppVar_41308 = (cppVar_41306 == 42);
	BIT_VEC cppVar_41309 = ROM.rd(PC);
	bool cppVar_41311 = (cppVar_41309 == 41);
	BIT_VEC cppVar_41312 = ROM.rd(PC);
	bool cppVar_41314 = (cppVar_41312 == 40);
	BIT_VEC cppVar_41315 = ROM.rd(PC);
	bool cppVar_41317 = (cppVar_41315 == 39);
	BIT_VEC cppVar_41318 = ROM.rd(PC);
	bool cppVar_41320 = (cppVar_41318 == 38);
	BIT_VEC cppVar_41321 = ROM.rd(PC);
	bool cppVar_41323 = (cppVar_41321 == 37);
	BIT_VEC cppVar_41324 = ROM.rd(PC);
	bool cppVar_41326 = (cppVar_41324 == 36);
	BIT_VEC cppVar_41327 = ROM.rd(PC);
	bool cppVar_41329 = (cppVar_41327 == 35);
	BIT_VEC cppVar_41330 = ROM.rd(PC);
	bool cppVar_41332 = (cppVar_41330 == 34);
	BIT_VEC cppVar_41333 = ROM.rd(PC);
	bool cppVar_41335 = (cppVar_41333 == 33);
	BIT_VEC cppVar_41336 = ROM.rd(PC);
	bool cppVar_41338 = (cppVar_41336 == 32);
	BIT_VEC cppVar_41339 = ROM.rd(PC);
	bool cppVar_41341 = (cppVar_41339 == 31);
	BIT_VEC cppVar_41342 = ROM.rd(PC);
	bool cppVar_41344 = (cppVar_41342 == 30);
	BIT_VEC cppVar_41345 = ROM.rd(PC);
	bool cppVar_41347 = (cppVar_41345 == 29);
	BIT_VEC cppVar_41348 = ROM.rd(PC);
	bool cppVar_41350 = (cppVar_41348 == 28);
	BIT_VEC cppVar_41351 = ROM.rd(PC);
	bool cppVar_41353 = (cppVar_41351 == 27);
	BIT_VEC cppVar_41354 = ROM.rd(PC);
	bool cppVar_41356 = (cppVar_41354 == 26);
	BIT_VEC cppVar_41357 = ROM.rd(PC);
	bool cppVar_41359 = (cppVar_41357 == 25);
	BIT_VEC cppVar_41360 = ROM.rd(PC);
	bool cppVar_41362 = (cppVar_41360 == 24);
	BIT_VEC cppVar_41363 = ROM.rd(PC);
	bool cppVar_41365 = (cppVar_41363 == 23);
	BIT_VEC cppVar_41366 = ROM.rd(PC);
	bool cppVar_41368 = (cppVar_41366 == 22);
	BIT_VEC cppVar_41369 = ROM.rd(PC);
	bool cppVar_41371 = (cppVar_41369 == 20);
	BIT_VEC cppVar_41372 = ROM.rd(PC);
	bool cppVar_41374 = (cppVar_41372 == 19);
	BIT_VEC cppVar_41375 = ROM.rd(PC);
	bool cppVar_41377 = (cppVar_41375 == 18);
	BIT_VEC cppVar_41378 = ROM.rd(PC);
	bool cppVar_41380 = (cppVar_41378 == 17);
	BIT_VEC cppVar_41381 = ROM.rd(PC);
	bool cppVar_41383 = (cppVar_41381 == 15);
	BIT_VEC cppVar_41384 = ROM.rd(PC);
	bool cppVar_41386 = (cppVar_41384 == 14);
	BIT_VEC cppVar_41387 = ROM.rd(PC);
	bool cppVar_41389 = (cppVar_41387 == 13);
	BIT_VEC cppVar_41390 = ROM.rd(PC);
	bool cppVar_41392 = (cppVar_41390 == 12);
	BIT_VEC cppVar_41393 = ROM.rd(PC);
	bool cppVar_41395 = (cppVar_41393 == 11);
	BIT_VEC cppVar_41396 = ROM.rd(PC);
	bool cppVar_41398 = (cppVar_41396 == 10);
	BIT_VEC cppVar_41399 = ROM.rd(PC);
	bool cppVar_41401 = (cppVar_41399 == 9);
	BIT_VEC cppVar_41402 = ROM.rd(PC);
	bool cppVar_41404 = (cppVar_41402 == 8);
	BIT_VEC cppVar_41405 = ROM.rd(PC);
	bool cppVar_41407 = (cppVar_41405 == 7);
	BIT_VEC cppVar_41408 = ROM.rd(PC);
	bool cppVar_41410 = (cppVar_41408 == 6);
	BIT_VEC cppVar_41411 = ROM.rd(PC);
	bool cppVar_41413 = (cppVar_41411 == 4);
	BIT_VEC cppVar_41414 = ROM.rd(PC);
	bool cppVar_41416 = (cppVar_41414 == 3);
	BIT_VEC cppVar_41417 = ROM.rd(PC);
	bool cppVar_41419 = (cppVar_41417 == 2);
	BIT_VEC cppVar_41420 = ROM.rd(PC);
	bool cppVar_41422 = (cppVar_41420 == 1);
	BIT_VEC cppVar_41423 = ROM.rd(PC);
	bool cppVar_41425 = (cppVar_41423 == 0);
	bool cppVar_41426 = cppVar_41422 || cppVar_41425;
	bool cppVar_41427 = cppVar_41419 || cppVar_41426;
	bool cppVar_41428 = cppVar_41416 || cppVar_41427;
	bool cppVar_41429 = cppVar_41413 || cppVar_41428;
	bool cppVar_41430 = cppVar_41410 || cppVar_41429;
	bool cppVar_41431 = cppVar_41407 || cppVar_41430;
	bool cppVar_41432 = cppVar_41404 || cppVar_41431;
	bool cppVar_41433 = cppVar_41401 || cppVar_41432;
	bool cppVar_41434 = cppVar_41398 || cppVar_41433;
	bool cppVar_41435 = cppVar_41395 || cppVar_41434;
	bool cppVar_41436 = cppVar_41392 || cppVar_41435;
	bool cppVar_41437 = cppVar_41389 || cppVar_41436;
	bool cppVar_41438 = cppVar_41386 || cppVar_41437;
	bool cppVar_41439 = cppVar_41383 || cppVar_41438;
	bool cppVar_41440 = cppVar_41380 || cppVar_41439;
	bool cppVar_41441 = cppVar_41377 || cppVar_41440;
	bool cppVar_41442 = cppVar_41374 || cppVar_41441;
	bool cppVar_41443 = cppVar_41371 || cppVar_41442;
	bool cppVar_41444 = cppVar_41368 || cppVar_41443;
	bool cppVar_41445 = cppVar_41365 || cppVar_41444;
	bool cppVar_41446 = cppVar_41362 || cppVar_41445;
	bool cppVar_41447 = cppVar_41359 || cppVar_41446;
	bool cppVar_41448 = cppVar_41356 || cppVar_41447;
	bool cppVar_41449 = cppVar_41353 || cppVar_41448;
	bool cppVar_41450 = cppVar_41350 || cppVar_41449;
	bool cppVar_41451 = cppVar_41347 || cppVar_41450;
	bool cppVar_41452 = cppVar_41344 || cppVar_41451;
	bool cppVar_41453 = cppVar_41341 || cppVar_41452;
	bool cppVar_41454 = cppVar_41338 || cppVar_41453;
	bool cppVar_41455 = cppVar_41335 || cppVar_41454;
	bool cppVar_41456 = cppVar_41332 || cppVar_41455;
	bool cppVar_41457 = cppVar_41329 || cppVar_41456;
	bool cppVar_41458 = cppVar_41326 || cppVar_41457;
	bool cppVar_41459 = cppVar_41323 || cppVar_41458;
	bool cppVar_41460 = cppVar_41320 || cppVar_41459;
	bool cppVar_41461 = cppVar_41317 || cppVar_41460;
	bool cppVar_41462 = cppVar_41314 || cppVar_41461;
	bool cppVar_41463 = cppVar_41311 || cppVar_41462;
	bool cppVar_41464 = cppVar_41308 || cppVar_41463;
	bool cppVar_41465 = cppVar_41305 || cppVar_41464;
	bool cppVar_41466 = cppVar_41302 || cppVar_41465;
	bool cppVar_41467 = cppVar_41299 || cppVar_41466;
	bool cppVar_41468 = cppVar_41296 || cppVar_41467;
	bool cppVar_41469 = cppVar_41293 || cppVar_41468;
	bool cppVar_41470 = cppVar_41290 || cppVar_41469;
	bool cppVar_41471 = cppVar_41287 || cppVar_41470;
	bool cppVar_41472 = cppVar_41284 || cppVar_41471;
	bool cppVar_41473 = cppVar_41281 || cppVar_41472;
	bool cppVar_41474 = cppVar_41278 || cppVar_41473;
	bool cppVar_41475 = cppVar_41275 || cppVar_41474;
	bool cppVar_41476 = cppVar_41272 || cppVar_41475;
	bool cppVar_41477 = cppVar_41269 || cppVar_41476;
	bool cppVar_41478 = cppVar_41266 || cppVar_41477;
	bool cppVar_41479 = cppVar_41263 || cppVar_41478;
	bool cppVar_41480 = cppVar_41260 || cppVar_41479;
	bool cppVar_41481 = cppVar_41257 || cppVar_41480;
	bool cppVar_41482 = cppVar_41254 || cppVar_41481;
	bool cppVar_41483 = cppVar_41251 || cppVar_41482;
	bool cppVar_41484 = cppVar_41248 || cppVar_41483;
	bool cppVar_41485 = cppVar_41245 || cppVar_41484;
	bool cppVar_41486 = cppVar_41242 || cppVar_41485;
	bool cppVar_41487 = cppVar_41239 || cppVar_41486;
	bool cppVar_41488 = cppVar_41236 || cppVar_41487;
	bool cppVar_41489 = cppVar_41233 || cppVar_41488;
	bool cppVar_41490 = cppVar_41230 || cppVar_41489;
	bool cppVar_41491 = cppVar_41227 || cppVar_41490;
	bool cppVar_41492 = cppVar_41224 || cppVar_41491;
	bool cppVar_41493 = cppVar_41221 || cppVar_41492;
	bool cppVar_41494 = cppVar_41218 || cppVar_41493;
	bool cppVar_41495 = cppVar_41215 || cppVar_41494;
	bool cppVar_41496 = cppVar_41212 || cppVar_41495;
	bool cppVar_41497 = cppVar_41209 || cppVar_41496;
	bool cppVar_41498 = cppVar_41206 || cppVar_41497;
	bool cppVar_41499 = cppVar_41203 || cppVar_41498;
	bool cppVar_41500 = cppVar_41200 || cppVar_41499;
	bool cppVar_41501 = cppVar_41197 || cppVar_41500;
	bool cppVar_41502 = cppVar_41194 || cppVar_41501;
	bool cppVar_41503 = cppVar_41191 || cppVar_41502;
	bool cppVar_41504 = cppVar_41188 || cppVar_41503;
	bool cppVar_41505 = cppVar_41185 || cppVar_41504;
	bool cppVar_41506 = cppVar_41182 || cppVar_41505;
	bool cppVar_41507 = cppVar_41179 || cppVar_41506;
	bool cppVar_41508 = cppVar_41176 || cppVar_41507;
	bool cppVar_41509 = cppVar_41173 || cppVar_41508;
	bool cppVar_41510 = cppVar_41170 || cppVar_41509;
	bool cppVar_41511 = cppVar_41167 || cppVar_41510;
	bool cppVar_41512 = cppVar_41164 || cppVar_41511;
	bool cppVar_41513 = cppVar_41161 || cppVar_41512;
	bool cppVar_41514 = cppVar_41158 || cppVar_41513;
	bool cppVar_41515 = cppVar_41155 || cppVar_41514;
	bool cppVar_41516 = cppVar_41152 || cppVar_41515;
	bool cppVar_41517 = cppVar_41149 || cppVar_41516;
	bool cppVar_41518 = cppVar_41146 || cppVar_41517;
	bool cppVar_41519 = cppVar_41143 || cppVar_41518;
	bool cppVar_41520 = cppVar_41140 || cppVar_41519;
	bool cppVar_41521 = cppVar_41137 || cppVar_41520;
	bool cppVar_41522 = cppVar_41134 || cppVar_41521;
	bool cppVar_41523 = cppVar_41131 || cppVar_41522;
	bool cppVar_41524 = cppVar_41128 || cppVar_41523;
	bool cppVar_41525 = cppVar_41125 || cppVar_41524;
	bool cppVar_41526 = cppVar_41122 || cppVar_41525;
	bool cppVar_41527 = cppVar_41119 || cppVar_41526;
	bool cppVar_41528 = cppVar_41116 || cppVar_41527;
	bool cppVar_41529 = cppVar_41113 || cppVar_41528;
	bool cppVar_41530 = cppVar_41110 || cppVar_41529;
	bool cppVar_41531 = cppVar_41107 || cppVar_41530;
	bool cppVar_41532 = cppVar_41104 || cppVar_41531;
	bool cppVar_41533 = cppVar_41101 || cppVar_41532;
	bool cppVar_41534 = cppVar_41098 || cppVar_41533;
	bool cppVar_41535 = cppVar_41095 || cppVar_41534;
	bool cppVar_41536 = cppVar_41092 || cppVar_41535;
	bool cppVar_41537 = cppVar_41089 || cppVar_41536;
	bool cppVar_41538 = cppVar_41086 || cppVar_41537;
	bool cppVar_41539 = cppVar_41083 || cppVar_41538;
	bool cppVar_41540 = cppVar_41080 || cppVar_41539;
	bool cppVar_41541 = cppVar_41077 || cppVar_41540;
	bool cppVar_41542 = cppVar_41074 || cppVar_41541;
	bool cppVar_41543 = cppVar_41071 || cppVar_41542;
	bool cppVar_41544 = cppVar_41068 || cppVar_41543;
	bool cppVar_41545 = cppVar_41065 || cppVar_41544;
	bool cppVar_41546 = cppVar_41062 || cppVar_41545;
	bool cppVar_41547 = cppVar_41059 || cppVar_41546;
	bool cppVar_41548 = cppVar_41056 || cppVar_41547;
	bool cppVar_41549 = cppVar_41053 || cppVar_41548;
	bool cppVar_41550 = cppVar_41050 || cppVar_41549;
	bool cppVar_41551 = cppVar_41047 || cppVar_41550;
	bool cppVar_41552 = cppVar_41044 || cppVar_41551;
	bool cppVar_41553 = cppVar_41041 || cppVar_41552;
	bool cppVar_41554 = cppVar_41038 || cppVar_41553;
	bool cppVar_41555 = cppVar_41035 || cppVar_41554;
	bool cppVar_41556 = cppVar_41032 || cppVar_41555;
	bool cppVar_41557 = cppVar_41029 || cppVar_41556;
	bool cppVar_41558 = cppVar_41026 || cppVar_41557;
	bool cppVar_41559 = cppVar_41023 || cppVar_41558;
	bool cppVar_41560 = cppVar_41020 || cppVar_41559;
	bool cppVar_41561 = cppVar_41017 || cppVar_41560;
	bool cppVar_41562 = cppVar_41014 || cppVar_41561;
	bool cppVar_41563 = cppVar_41011 || cppVar_41562;
	bool cppVar_41564 = cppVar_41008 || cppVar_41563;
	bool cppVar_41565 = cppVar_41005 || cppVar_41564;
	bool cppVar_41566 = cppVar_41002 || cppVar_41565;
	bool cppVar_41567 = cppVar_40999 || cppVar_41566;
	bool cppVar_41568 = cppVar_40996 || cppVar_41567;
	bool cppVar_41569 = cppVar_40993 || cppVar_41568;
	bool cppVar_41570 = cppVar_40990 || cppVar_41569;
	bool cppVar_41571 = cppVar_40987 || cppVar_41570;
	bool cppVar_41572 = cppVar_40984 || cppVar_41571;
	bool cppVar_41573 = cppVar_40981 || cppVar_41572;
	bool cppVar_41574 = cppVar_40978 || cppVar_41573;
	bool cppVar_41575 = cppVar_40975 || cppVar_41574;
	bool cppVar_41576 = cppVar_40972 || cppVar_41575;
	bool cppVar_41577 = cppVar_40969 || cppVar_41576;
	bool cppVar_41578 = cppVar_40966 || cppVar_41577;
	bool cppVar_41579 = cppVar_40963 || cppVar_41578;
	bool cppVar_41580 = cppVar_40960 || cppVar_41579;
	bool cppVar_41581 = cppVar_40957 || cppVar_41580;
	bool cppVar_41582 = cppVar_40954 || cppVar_41581;
	bool cppVar_41583 = cppVar_40951 || cppVar_41582;
	bool cppVar_41584 = cppVar_40948 || cppVar_41583;
	bool cppVar_41585 = cppVar_40945 || cppVar_41584;
	bool cppVar_41586 = cppVar_40942 || cppVar_41585;
	bool cppVar_41587 = cppVar_40939 || cppVar_41586;
	bool cppVar_41588 = cppVar_40936 || cppVar_41587;
	bool cppVar_41589 = cppVar_40933 || cppVar_41588;
	bool cppVar_41590 = cppVar_40930 || cppVar_41589;
	bool cppVar_41591 = cppVar_40927 || cppVar_41590;
	bool cppVar_41592 = cppVar_40924 || cppVar_41591;
	bool cppVar_41593 = cppVar_40921 || cppVar_41592;
	bool cppVar_41594 = cppVar_40918 || cppVar_41593;
	bool cppVar_41595 = cppVar_40915 || cppVar_41594;
	bool cppVar_41596 = cppVar_40912 || cppVar_41595;
	bool cppVar_41597 = cppVar_40909 || cppVar_41596;
	bool cppVar_41598 = cppVar_40906 || cppVar_41597;
	bool cppVar_41599 = cppVar_40903 || cppVar_41598;
	bool cppVar_41600 = cppVar_40900 || cppVar_41599;
	bool cppVar_41601 = cppVar_40897 || cppVar_41600;
	bool cppVar_41602 = cppVar_40894 || cppVar_41601;
	bool cppVar_41603 = cppVar_40891 || cppVar_41602;
	bool cppVar_41604 = cppVar_40888 || cppVar_41603;
	bool cppVar_41605 = cppVar_40885 || cppVar_41604;
	bool cppVar_41606 = cppVar_40882 || cppVar_41605;
	bool cppVar_41607 = cppVar_40879 || cppVar_41606;
	bool cppVar_41608 = cppVar_40876 || cppVar_41607;
	bool cppVar_41609 = cppVar_40873 || cppVar_41608;
	bool cppVar_41610 = cppVar_40870 || cppVar_41609;
	bool cppVar_41611 = cppVar_40867 || cppVar_41610;
	bool cppVar_41612 = cppVar_40864 || cppVar_41611;
	bool cppVar_41613 = cppVar_40861 || cppVar_41612;
	bool cppVar_41614 = cppVar_40858 || cppVar_41613;
	bool cppVar_41615 = cppVar_40855 || cppVar_41614;
	bool cppVar_41616 = cppVar_40852 || cppVar_41615;
	bool cppVar_41617 = cppVar_40849 || cppVar_41616;
	bool cppVar_41618 = cppVar_40846 || cppVar_41617;
	bool cppVar_41619 = cppVar_40843 || cppVar_41618;
	bool cppVar_41620 = cppVar_40840 || cppVar_41619;
	bool cppVar_41621 = cppVar_40837 || cppVar_41620;
	bool cppVar_41622 = cppVar_40834 || cppVar_41621;
	bool cppVar_41623 = cppVar_40831 || cppVar_41622;
	bool cppVar_41624 = cppVar_40828 || cppVar_41623;
	bool cppVar_41625 = cppVar_40825 || cppVar_41624;
	bool cppVar_41626 = cppVar_40822 || cppVar_41625;
	bool cppVar_41627 = cppVar_40819 || cppVar_41626;
	bool cppVar_41628 = cppVar_40816 || cppVar_41627;
	bool cppVar_41629 = cppVar_40813 || cppVar_41628;
	bool cppVar_41630 = cppVar_40810 || cppVar_41629;
	bool cppVar_41631 = cppVar_40807 || cppVar_41630;
	bool cppVar_41632 = cppVar_40804 || cppVar_41631;
	bool cppVar_41633 = cppVar_40801 || cppVar_41632;
	bool cppVar_41634 = cppVar_40798 || cppVar_41633;
	bool cppVar_41635 = cppVar_40795 || cppVar_41634;
	bool cppVar_41636 = cppVar_40792 || cppVar_41635;
	bool cppVar_41637 = cppVar_40789 || cppVar_41636;
	bool cppVar_41638 = cppVar_40786 || cppVar_41637;
	bool cppVar_41639 = cppVar_40783 || cppVar_41638;
	bool cppVar_41640 = cppVar_40780 || cppVar_41639;
	bool cppVar_41641 = cppVar_40777 || cppVar_41640;
	bool cppVar_41642 = cppVar_40774 || cppVar_41641;
	bool cppVar_41643 = cppVar_40771 || cppVar_41642;
	bool cppVar_41644 = cppVar_40768 || cppVar_41643;
	bool cppVar_41645 = cppVar_40765 || cppVar_41644;
	bool cppVar_41646 = cppVar_40762 || cppVar_41645;
	bool cppVar_41647 = cppVar_40759 || cppVar_41646;
	bool cppVar_41648 = cppVar_40756 || cppVar_41647;
	bool cppVar_41649 = cppVar_40753 || cppVar_41648;
	bool cppVar_41650 = cppVar_40750 || cppVar_41649;
	bool cppVar_41651 = cppVar_40747 || cppVar_41650;
	if (cppVar_41651) {
	BIT_VEC cppVar_41652;
	BIT_VEC cppVar_41654 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_41656 = (cppVar_41654 << 3) | 7;
	cppVar_41656 = (cppVar_41656 & cppMask_un_5_);
	BIT_VEC cppVar_41657 = (0 << 5) | cppVar_41656;
	cppVar_41657 = (cppVar_41657 & cppMask_un_8_);
	bool cppVar_41659 = (cppVar_41657 == 176);
	if (cppVar_41659) {
	cppVar_41652 = ACC;
	} else {
	cppVar_41652 = P3;
	}
	cppVar_40744 = cppVar_41652;
	} else {
	cppVar_40744 = P3;
	}
	cppVar_40617 = cppVar_40744;
	}
	cppVar_40181 = cppVar_40617;
	}
	cppVar_40050 = cppVar_40181;
	}
	cppVar_39924 = cppVar_40050;
	}
	cppVar_39795 = cppVar_39924;
	}
	cppVar_39669 = cppVar_39795;
	}
	cppVar_39540 = cppVar_39669;
	}
	cppVar_39414 = cppVar_39540;
	}
	cppVar_39285 = cppVar_39414;
	}
	cppVar_39272 = cppVar_39285;
	}
	cppVar_39146 = cppVar_39272;
	}
	cppVar_39129 = cppVar_39146;
	}
	cppVar_39112 = cppVar_39129;
	}
	cppVar_38962 = cppVar_39112;
	}
	cppVar_38812 = cppVar_38962;
	}
	cppVar_38662 = cppVar_38812;
	}
	cppVar_38512 = cppVar_38662;
	}
	cppVar_38362 = cppVar_38512;
	}
	cppVar_38212 = cppVar_38362;
	}
	cppVar_38062 = cppVar_38212;
	}
	cppVar_37912 = cppVar_38062;
	}
	cppVar_37480 = cppVar_37912;
	}
	cppVar_36650 = cppVar_37480;
	}
	cppVar_36636 = cppVar_36650;
	}
	cppVar_36625 = cppVar_36636;
	}
	cppVar_36193 = cppVar_36625;
	}
	return cppVar_36193;
}
