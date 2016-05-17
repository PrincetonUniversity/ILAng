#include "common.hpp"
#include "model_oc8051_class.hpp"

BIT_VEC model_oc8051::cppUpdateFun_TL0()
{
	BIT_VEC cppVar_77270;
	BIT_VEC cppVar_77271 = ROM.rd(PC);
	bool cppVar_77273 = (cppVar_77271 == 208);
	if (cppVar_77273) {
	BIT_VEC cppVar_77274;
	BIT_VEC cppVar_77276 = PC + 1;
	cppVar_77276 = (cppVar_77276 & cppMask_un_16_);
	BIT_VEC cppVar_77277 = ROM.rd(cppVar_77276);
	bool cppVar_77279 = (cppVar_77277 == 138);
	if (cppVar_77279) {
	BIT_VEC cppVar_77280 = IRAM.rd(SP);
	cppVar_77274 = cppVar_77280;
	} else {
	cppVar_77274 = TL0;
	}
	cppVar_77270 = cppVar_77274;
	} else {
	BIT_VEC cppVar_77281;
	BIT_VEC cppVar_77282 = ROM.rd(PC);
	bool cppVar_77284 = (cppVar_77282 == 245);
	BIT_VEC cppVar_77285 = ROM.rd(PC);
	bool cppVar_77287 = (cppVar_77285 == 197);
	bool cppVar_77288 = cppVar_77284 || cppVar_77287;
	if (cppVar_77288) {
	BIT_VEC cppVar_77289;
	BIT_VEC cppVar_77291 = PC + 1;
	cppVar_77291 = (cppVar_77291 & cppMask_un_16_);
	BIT_VEC cppVar_77292 = ROM.rd(cppVar_77291);
	bool cppVar_77294 = (cppVar_77292 == 138);
	if (cppVar_77294) {
	cppVar_77289 = ACC;
	} else {
	cppVar_77289 = TL0;
	}
	cppVar_77281 = cppVar_77289;
	} else {
	BIT_VEC cppVar_77295;
	BIT_VEC cppVar_77296 = ROM.rd(PC);
	bool cppVar_77298 = (cppVar_77296 == 143);
	if (cppVar_77298) {
	BIT_VEC cppVar_77299;
	BIT_VEC cppVar_77301 = PC + 1;
	cppVar_77301 = (cppVar_77301 & cppMask_un_16_);
	BIT_VEC cppVar_77302 = ROM.rd(cppVar_77301);
	bool cppVar_77304 = (cppVar_77302 == 138);
	if (cppVar_77304) {
	BIT_VEC cppVar_77305;
	BIT_VEC cppVar_77307 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77309 = (cppVar_77307 << 3) | 7;
	cppVar_77309 = (cppVar_77309 & cppMask_un_5_);
	BIT_VEC cppVar_77310 = (0 << 5) | cppVar_77309;
	cppVar_77310 = (cppVar_77310 & cppMask_un_8_);
	BIT_VEC cppVar_77311 = (cppVar_77310 >> 7) & cppMask_un_1_;
	bool cppVar_77313 = (cppVar_77311 == 0);
	if (cppVar_77313) {
	BIT_VEC cppVar_77314 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77315 = (cppVar_77314 << 3) | 7;
	cppVar_77315 = (cppVar_77315 & cppMask_un_5_);
	BIT_VEC cppVar_77316 = (0 << 5) | cppVar_77315;
	cppVar_77316 = (cppVar_77316 & cppMask_un_8_);
	BIT_VEC cppVar_77317 = IRAM.rd(cppVar_77316);
	cppVar_77305 = cppVar_77317;
	} else {
	BIT_VEC cppVar_77318;
	BIT_VEC cppVar_77319 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77320 = (cppVar_77319 << 3) | 7;
	cppVar_77320 = (cppVar_77320 & cppMask_un_5_);
	BIT_VEC cppVar_77321 = (0 << 5) | cppVar_77320;
	cppVar_77321 = (cppVar_77321 & cppMask_un_8_);
	bool cppVar_77323 = (cppVar_77321 == 128);
	if (cppVar_77323) {
	cppVar_77318 = P0;
	} else {
	BIT_VEC cppVar_77324;
	BIT_VEC cppVar_77325 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77326 = (cppVar_77325 << 3) | 7;
	cppVar_77326 = (cppVar_77326 & cppMask_un_5_);
	BIT_VEC cppVar_77327 = (0 << 5) | cppVar_77326;
	cppVar_77327 = (cppVar_77327 & cppMask_un_8_);
	bool cppVar_77329 = (cppVar_77327 == 129);
	if (cppVar_77329) {
	cppVar_77324 = SP;
	} else {
	BIT_VEC cppVar_77330;
	BIT_VEC cppVar_77331 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77332 = (cppVar_77331 << 3) | 7;
	cppVar_77332 = (cppVar_77332 & cppMask_un_5_);
	BIT_VEC cppVar_77333 = (0 << 5) | cppVar_77332;
	cppVar_77333 = (cppVar_77333 & cppMask_un_8_);
	bool cppVar_77335 = (cppVar_77333 == 130);
	if (cppVar_77335) {
	cppVar_77330 = DPL;
	} else {
	BIT_VEC cppVar_77336;
	BIT_VEC cppVar_77337 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77338 = (cppVar_77337 << 3) | 7;
	cppVar_77338 = (cppVar_77338 & cppMask_un_5_);
	BIT_VEC cppVar_77339 = (0 << 5) | cppVar_77338;
	cppVar_77339 = (cppVar_77339 & cppMask_un_8_);
	bool cppVar_77341 = (cppVar_77339 == 131);
	if (cppVar_77341) {
	cppVar_77336 = DPH;
	} else {
	BIT_VEC cppVar_77342;
	BIT_VEC cppVar_77343 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77344 = (cppVar_77343 << 3) | 7;
	cppVar_77344 = (cppVar_77344 & cppMask_un_5_);
	BIT_VEC cppVar_77345 = (0 << 5) | cppVar_77344;
	cppVar_77345 = (cppVar_77345 & cppMask_un_8_);
	bool cppVar_77347 = (cppVar_77345 == 135);
	if (cppVar_77347) {
	cppVar_77342 = PCON;
	} else {
	BIT_VEC cppVar_77348;
	BIT_VEC cppVar_77349 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77350 = (cppVar_77349 << 3) | 7;
	cppVar_77350 = (cppVar_77350 & cppMask_un_5_);
	BIT_VEC cppVar_77351 = (0 << 5) | cppVar_77350;
	cppVar_77351 = (cppVar_77351 & cppMask_un_8_);
	bool cppVar_77353 = (cppVar_77351 == 136);
	if (cppVar_77353) {
	cppVar_77348 = TCON;
	} else {
	BIT_VEC cppVar_77354;
	BIT_VEC cppVar_77355 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77356 = (cppVar_77355 << 3) | 7;
	cppVar_77356 = (cppVar_77356 & cppMask_un_5_);
	BIT_VEC cppVar_77357 = (0 << 5) | cppVar_77356;
	cppVar_77357 = (cppVar_77357 & cppMask_un_8_);
	bool cppVar_77359 = (cppVar_77357 == 137);
	if (cppVar_77359) {
	cppVar_77354 = TMOD;
	} else {
	BIT_VEC cppVar_77360;
	BIT_VEC cppVar_77361 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77362 = (cppVar_77361 << 3) | 7;
	cppVar_77362 = (cppVar_77362 & cppMask_un_5_);
	BIT_VEC cppVar_77363 = (0 << 5) | cppVar_77362;
	cppVar_77363 = (cppVar_77363 & cppMask_un_8_);
	bool cppVar_77365 = (cppVar_77363 == 138);
	if (cppVar_77365) {
	cppVar_77360 = TL0;
	} else {
	BIT_VEC cppVar_77366;
	BIT_VEC cppVar_77367 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77368 = (cppVar_77367 << 3) | 7;
	cppVar_77368 = (cppVar_77368 & cppMask_un_5_);
	BIT_VEC cppVar_77369 = (0 << 5) | cppVar_77368;
	cppVar_77369 = (cppVar_77369 & cppMask_un_8_);
	bool cppVar_77371 = (cppVar_77369 == 140);
	if (cppVar_77371) {
	cppVar_77366 = TH0;
	} else {
	BIT_VEC cppVar_77372;
	BIT_VEC cppVar_77373 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77374 = (cppVar_77373 << 3) | 7;
	cppVar_77374 = (cppVar_77374 & cppMask_un_5_);
	BIT_VEC cppVar_77375 = (0 << 5) | cppVar_77374;
	cppVar_77375 = (cppVar_77375 & cppMask_un_8_);
	bool cppVar_77377 = (cppVar_77375 == 139);
	if (cppVar_77377) {
	cppVar_77372 = TL1;
	} else {
	BIT_VEC cppVar_77378;
	BIT_VEC cppVar_77379 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77380 = (cppVar_77379 << 3) | 7;
	cppVar_77380 = (cppVar_77380 & cppMask_un_5_);
	BIT_VEC cppVar_77381 = (0 << 5) | cppVar_77380;
	cppVar_77381 = (cppVar_77381 & cppMask_un_8_);
	bool cppVar_77383 = (cppVar_77381 == 141);
	if (cppVar_77383) {
	cppVar_77378 = TH1;
	} else {
	BIT_VEC cppVar_77384;
	BIT_VEC cppVar_77385 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77386 = (cppVar_77385 << 3) | 7;
	cppVar_77386 = (cppVar_77386 & cppMask_un_5_);
	BIT_VEC cppVar_77387 = (0 << 5) | cppVar_77386;
	cppVar_77387 = (cppVar_77387 & cppMask_un_8_);
	bool cppVar_77389 = (cppVar_77387 == 144);
	if (cppVar_77389) {
	cppVar_77384 = P1;
	} else {
	BIT_VEC cppVar_77390;
	BIT_VEC cppVar_77391 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77392 = (cppVar_77391 << 3) | 7;
	cppVar_77392 = (cppVar_77392 & cppMask_un_5_);
	BIT_VEC cppVar_77393 = (0 << 5) | cppVar_77392;
	cppVar_77393 = (cppVar_77393 & cppMask_un_8_);
	bool cppVar_77395 = (cppVar_77393 == 152);
	if (cppVar_77395) {
	cppVar_77390 = SCON;
	} else {
	BIT_VEC cppVar_77396;
	BIT_VEC cppVar_77397 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77398 = (cppVar_77397 << 3) | 7;
	cppVar_77398 = (cppVar_77398 & cppMask_un_5_);
	BIT_VEC cppVar_77399 = (0 << 5) | cppVar_77398;
	cppVar_77399 = (cppVar_77399 & cppMask_un_8_);
	bool cppVar_77401 = (cppVar_77399 == 153);
	if (cppVar_77401) {
	cppVar_77396 = SBUF;
	} else {
	BIT_VEC cppVar_77402;
	BIT_VEC cppVar_77403 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77404 = (cppVar_77403 << 3) | 7;
	cppVar_77404 = (cppVar_77404 & cppMask_un_5_);
	BIT_VEC cppVar_77405 = (0 << 5) | cppVar_77404;
	cppVar_77405 = (cppVar_77405 & cppMask_un_8_);
	bool cppVar_77407 = (cppVar_77405 == 160);
	if (cppVar_77407) {
	cppVar_77402 = P2;
	} else {
	BIT_VEC cppVar_77408;
	BIT_VEC cppVar_77409 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77410 = (cppVar_77409 << 3) | 7;
	cppVar_77410 = (cppVar_77410 & cppMask_un_5_);
	BIT_VEC cppVar_77411 = (0 << 5) | cppVar_77410;
	cppVar_77411 = (cppVar_77411 & cppMask_un_8_);
	bool cppVar_77413 = (cppVar_77411 == 168);
	if (cppVar_77413) {
	cppVar_77408 = IE;
	} else {
	BIT_VEC cppVar_77414;
	BIT_VEC cppVar_77415 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77416 = (cppVar_77415 << 3) | 7;
	cppVar_77416 = (cppVar_77416 & cppMask_un_5_);
	BIT_VEC cppVar_77417 = (0 << 5) | cppVar_77416;
	cppVar_77417 = (cppVar_77417 & cppMask_un_8_);
	bool cppVar_77419 = (cppVar_77417 == 176);
	if (cppVar_77419) {
	cppVar_77414 = P3;
	} else {
	BIT_VEC cppVar_77420;
	BIT_VEC cppVar_77421 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77422 = (cppVar_77421 << 3) | 7;
	cppVar_77422 = (cppVar_77422 & cppMask_un_5_);
	BIT_VEC cppVar_77423 = (0 << 5) | cppVar_77422;
	cppVar_77423 = (cppVar_77423 & cppMask_un_8_);
	bool cppVar_77425 = (cppVar_77423 == 184);
	if (cppVar_77425) {
	cppVar_77420 = IP;
	} else {
	BIT_VEC cppVar_77426;
	BIT_VEC cppVar_77427 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77428 = (cppVar_77427 << 3) | 7;
	cppVar_77428 = (cppVar_77428 & cppMask_un_5_);
	BIT_VEC cppVar_77429 = (0 << 5) | cppVar_77428;
	cppVar_77429 = (cppVar_77429 & cppMask_un_8_);
	bool cppVar_77431 = (cppVar_77429 == 208);
	if (cppVar_77431) {
	cppVar_77426 = PSW;
	} else {
	BIT_VEC cppVar_77432;
	BIT_VEC cppVar_77433 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77434 = (cppVar_77433 << 3) | 7;
	cppVar_77434 = (cppVar_77434 & cppMask_un_5_);
	BIT_VEC cppVar_77435 = (0 << 5) | cppVar_77434;
	cppVar_77435 = (cppVar_77435 & cppMask_un_8_);
	bool cppVar_77437 = (cppVar_77435 == 224);
	if (cppVar_77437) {
	cppVar_77432 = ACC;
	} else {
	BIT_VEC cppVar_77438;
	BIT_VEC cppVar_77439 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77440 = (cppVar_77439 << 3) | 7;
	cppVar_77440 = (cppVar_77440 & cppMask_un_5_);
	BIT_VEC cppVar_77441 = (0 << 5) | cppVar_77440;
	cppVar_77441 = (cppVar_77441 & cppMask_un_8_);
	bool cppVar_77443 = (cppVar_77441 == 240);
	if (cppVar_77443) {
	cppVar_77438 = B;
	} else {
	cppVar_77438 = 0;
	}
	cppVar_77432 = cppVar_77438;
	}
	cppVar_77426 = cppVar_77432;
	}
	cppVar_77420 = cppVar_77426;
	}
	cppVar_77414 = cppVar_77420;
	}
	cppVar_77408 = cppVar_77414;
	}
	cppVar_77402 = cppVar_77408;
	}
	cppVar_77396 = cppVar_77402;
	}
	cppVar_77390 = cppVar_77396;
	}
	cppVar_77384 = cppVar_77390;
	}
	cppVar_77378 = cppVar_77384;
	}
	cppVar_77372 = cppVar_77378;
	}
	cppVar_77366 = cppVar_77372;
	}
	cppVar_77360 = cppVar_77366;
	}
	cppVar_77354 = cppVar_77360;
	}
	cppVar_77348 = cppVar_77354;
	}
	cppVar_77342 = cppVar_77348;
	}
	cppVar_77336 = cppVar_77342;
	}
	cppVar_77330 = cppVar_77336;
	}
	cppVar_77324 = cppVar_77330;
	}
	cppVar_77318 = cppVar_77324;
	}
	cppVar_77305 = cppVar_77318;
	}
	cppVar_77299 = cppVar_77305;
	} else {
	cppVar_77299 = TL0;
	}
	cppVar_77295 = cppVar_77299;
	} else {
	BIT_VEC cppVar_77445;
	BIT_VEC cppVar_77446 = ROM.rd(PC);
	bool cppVar_77448 = (cppVar_77446 == 142);
	if (cppVar_77448) {
	BIT_VEC cppVar_77449;
	BIT_VEC cppVar_77451 = PC + 1;
	cppVar_77451 = (cppVar_77451 & cppMask_un_16_);
	BIT_VEC cppVar_77452 = ROM.rd(cppVar_77451);
	bool cppVar_77454 = (cppVar_77452 == 138);
	if (cppVar_77454) {
	BIT_VEC cppVar_77455;
	BIT_VEC cppVar_77457 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77459 = (cppVar_77457 << 3) | 6;
	cppVar_77459 = (cppVar_77459 & cppMask_un_5_);
	BIT_VEC cppVar_77460 = (0 << 5) | cppVar_77459;
	cppVar_77460 = (cppVar_77460 & cppMask_un_8_);
	BIT_VEC cppVar_77461 = (cppVar_77460 >> 7) & cppMask_un_1_;
	bool cppVar_77463 = (cppVar_77461 == 0);
	if (cppVar_77463) {
	BIT_VEC cppVar_77464 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77465 = (cppVar_77464 << 3) | 6;
	cppVar_77465 = (cppVar_77465 & cppMask_un_5_);
	BIT_VEC cppVar_77466 = (0 << 5) | cppVar_77465;
	cppVar_77466 = (cppVar_77466 & cppMask_un_8_);
	BIT_VEC cppVar_77467 = IRAM.rd(cppVar_77466);
	cppVar_77455 = cppVar_77467;
	} else {
	BIT_VEC cppVar_77468;
	BIT_VEC cppVar_77469 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77470 = (cppVar_77469 << 3) | 6;
	cppVar_77470 = (cppVar_77470 & cppMask_un_5_);
	BIT_VEC cppVar_77471 = (0 << 5) | cppVar_77470;
	cppVar_77471 = (cppVar_77471 & cppMask_un_8_);
	bool cppVar_77473 = (cppVar_77471 == 128);
	if (cppVar_77473) {
	cppVar_77468 = P0;
	} else {
	BIT_VEC cppVar_77474;
	BIT_VEC cppVar_77475 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77476 = (cppVar_77475 << 3) | 6;
	cppVar_77476 = (cppVar_77476 & cppMask_un_5_);
	BIT_VEC cppVar_77477 = (0 << 5) | cppVar_77476;
	cppVar_77477 = (cppVar_77477 & cppMask_un_8_);
	bool cppVar_77479 = (cppVar_77477 == 129);
	if (cppVar_77479) {
	cppVar_77474 = SP;
	} else {
	BIT_VEC cppVar_77480;
	BIT_VEC cppVar_77481 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77482 = (cppVar_77481 << 3) | 6;
	cppVar_77482 = (cppVar_77482 & cppMask_un_5_);
	BIT_VEC cppVar_77483 = (0 << 5) | cppVar_77482;
	cppVar_77483 = (cppVar_77483 & cppMask_un_8_);
	bool cppVar_77485 = (cppVar_77483 == 130);
	if (cppVar_77485) {
	cppVar_77480 = DPL;
	} else {
	BIT_VEC cppVar_77486;
	BIT_VEC cppVar_77487 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77488 = (cppVar_77487 << 3) | 6;
	cppVar_77488 = (cppVar_77488 & cppMask_un_5_);
	BIT_VEC cppVar_77489 = (0 << 5) | cppVar_77488;
	cppVar_77489 = (cppVar_77489 & cppMask_un_8_);
	bool cppVar_77491 = (cppVar_77489 == 131);
	if (cppVar_77491) {
	cppVar_77486 = DPH;
	} else {
	BIT_VEC cppVar_77492;
	BIT_VEC cppVar_77493 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77494 = (cppVar_77493 << 3) | 6;
	cppVar_77494 = (cppVar_77494 & cppMask_un_5_);
	BIT_VEC cppVar_77495 = (0 << 5) | cppVar_77494;
	cppVar_77495 = (cppVar_77495 & cppMask_un_8_);
	bool cppVar_77497 = (cppVar_77495 == 135);
	if (cppVar_77497) {
	cppVar_77492 = PCON;
	} else {
	BIT_VEC cppVar_77498;
	BIT_VEC cppVar_77499 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77500 = (cppVar_77499 << 3) | 6;
	cppVar_77500 = (cppVar_77500 & cppMask_un_5_);
	BIT_VEC cppVar_77501 = (0 << 5) | cppVar_77500;
	cppVar_77501 = (cppVar_77501 & cppMask_un_8_);
	bool cppVar_77503 = (cppVar_77501 == 136);
	if (cppVar_77503) {
	cppVar_77498 = TCON;
	} else {
	BIT_VEC cppVar_77504;
	BIT_VEC cppVar_77505 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77506 = (cppVar_77505 << 3) | 6;
	cppVar_77506 = (cppVar_77506 & cppMask_un_5_);
	BIT_VEC cppVar_77507 = (0 << 5) | cppVar_77506;
	cppVar_77507 = (cppVar_77507 & cppMask_un_8_);
	bool cppVar_77509 = (cppVar_77507 == 137);
	if (cppVar_77509) {
	cppVar_77504 = TMOD;
	} else {
	BIT_VEC cppVar_77510;
	BIT_VEC cppVar_77511 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77512 = (cppVar_77511 << 3) | 6;
	cppVar_77512 = (cppVar_77512 & cppMask_un_5_);
	BIT_VEC cppVar_77513 = (0 << 5) | cppVar_77512;
	cppVar_77513 = (cppVar_77513 & cppMask_un_8_);
	bool cppVar_77515 = (cppVar_77513 == 138);
	if (cppVar_77515) {
	cppVar_77510 = TL0;
	} else {
	BIT_VEC cppVar_77516;
	BIT_VEC cppVar_77517 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77518 = (cppVar_77517 << 3) | 6;
	cppVar_77518 = (cppVar_77518 & cppMask_un_5_);
	BIT_VEC cppVar_77519 = (0 << 5) | cppVar_77518;
	cppVar_77519 = (cppVar_77519 & cppMask_un_8_);
	bool cppVar_77521 = (cppVar_77519 == 140);
	if (cppVar_77521) {
	cppVar_77516 = TH0;
	} else {
	BIT_VEC cppVar_77522;
	BIT_VEC cppVar_77523 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77524 = (cppVar_77523 << 3) | 6;
	cppVar_77524 = (cppVar_77524 & cppMask_un_5_);
	BIT_VEC cppVar_77525 = (0 << 5) | cppVar_77524;
	cppVar_77525 = (cppVar_77525 & cppMask_un_8_);
	bool cppVar_77527 = (cppVar_77525 == 139);
	if (cppVar_77527) {
	cppVar_77522 = TL1;
	} else {
	BIT_VEC cppVar_77528;
	BIT_VEC cppVar_77529 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77530 = (cppVar_77529 << 3) | 6;
	cppVar_77530 = (cppVar_77530 & cppMask_un_5_);
	BIT_VEC cppVar_77531 = (0 << 5) | cppVar_77530;
	cppVar_77531 = (cppVar_77531 & cppMask_un_8_);
	bool cppVar_77533 = (cppVar_77531 == 141);
	if (cppVar_77533) {
	cppVar_77528 = TH1;
	} else {
	BIT_VEC cppVar_77534;
	BIT_VEC cppVar_77535 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77536 = (cppVar_77535 << 3) | 6;
	cppVar_77536 = (cppVar_77536 & cppMask_un_5_);
	BIT_VEC cppVar_77537 = (0 << 5) | cppVar_77536;
	cppVar_77537 = (cppVar_77537 & cppMask_un_8_);
	bool cppVar_77539 = (cppVar_77537 == 144);
	if (cppVar_77539) {
	cppVar_77534 = P1;
	} else {
	BIT_VEC cppVar_77540;
	BIT_VEC cppVar_77541 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77542 = (cppVar_77541 << 3) | 6;
	cppVar_77542 = (cppVar_77542 & cppMask_un_5_);
	BIT_VEC cppVar_77543 = (0 << 5) | cppVar_77542;
	cppVar_77543 = (cppVar_77543 & cppMask_un_8_);
	bool cppVar_77545 = (cppVar_77543 == 152);
	if (cppVar_77545) {
	cppVar_77540 = SCON;
	} else {
	BIT_VEC cppVar_77546;
	BIT_VEC cppVar_77547 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77548 = (cppVar_77547 << 3) | 6;
	cppVar_77548 = (cppVar_77548 & cppMask_un_5_);
	BIT_VEC cppVar_77549 = (0 << 5) | cppVar_77548;
	cppVar_77549 = (cppVar_77549 & cppMask_un_8_);
	bool cppVar_77551 = (cppVar_77549 == 153);
	if (cppVar_77551) {
	cppVar_77546 = SBUF;
	} else {
	BIT_VEC cppVar_77552;
	BIT_VEC cppVar_77553 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77554 = (cppVar_77553 << 3) | 6;
	cppVar_77554 = (cppVar_77554 & cppMask_un_5_);
	BIT_VEC cppVar_77555 = (0 << 5) | cppVar_77554;
	cppVar_77555 = (cppVar_77555 & cppMask_un_8_);
	bool cppVar_77557 = (cppVar_77555 == 160);
	if (cppVar_77557) {
	cppVar_77552 = P2;
	} else {
	BIT_VEC cppVar_77558;
	BIT_VEC cppVar_77559 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77560 = (cppVar_77559 << 3) | 6;
	cppVar_77560 = (cppVar_77560 & cppMask_un_5_);
	BIT_VEC cppVar_77561 = (0 << 5) | cppVar_77560;
	cppVar_77561 = (cppVar_77561 & cppMask_un_8_);
	bool cppVar_77563 = (cppVar_77561 == 168);
	if (cppVar_77563) {
	cppVar_77558 = IE;
	} else {
	BIT_VEC cppVar_77564;
	BIT_VEC cppVar_77565 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77566 = (cppVar_77565 << 3) | 6;
	cppVar_77566 = (cppVar_77566 & cppMask_un_5_);
	BIT_VEC cppVar_77567 = (0 << 5) | cppVar_77566;
	cppVar_77567 = (cppVar_77567 & cppMask_un_8_);
	bool cppVar_77569 = (cppVar_77567 == 176);
	if (cppVar_77569) {
	cppVar_77564 = P3;
	} else {
	BIT_VEC cppVar_77570;
	BIT_VEC cppVar_77571 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77572 = (cppVar_77571 << 3) | 6;
	cppVar_77572 = (cppVar_77572 & cppMask_un_5_);
	BIT_VEC cppVar_77573 = (0 << 5) | cppVar_77572;
	cppVar_77573 = (cppVar_77573 & cppMask_un_8_);
	bool cppVar_77575 = (cppVar_77573 == 184);
	if (cppVar_77575) {
	cppVar_77570 = IP;
	} else {
	BIT_VEC cppVar_77576;
	BIT_VEC cppVar_77577 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77578 = (cppVar_77577 << 3) | 6;
	cppVar_77578 = (cppVar_77578 & cppMask_un_5_);
	BIT_VEC cppVar_77579 = (0 << 5) | cppVar_77578;
	cppVar_77579 = (cppVar_77579 & cppMask_un_8_);
	bool cppVar_77581 = (cppVar_77579 == 208);
	if (cppVar_77581) {
	cppVar_77576 = PSW;
	} else {
	BIT_VEC cppVar_77582;
	BIT_VEC cppVar_77583 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77584 = (cppVar_77583 << 3) | 6;
	cppVar_77584 = (cppVar_77584 & cppMask_un_5_);
	BIT_VEC cppVar_77585 = (0 << 5) | cppVar_77584;
	cppVar_77585 = (cppVar_77585 & cppMask_un_8_);
	bool cppVar_77587 = (cppVar_77585 == 224);
	if (cppVar_77587) {
	cppVar_77582 = ACC;
	} else {
	BIT_VEC cppVar_77588;
	BIT_VEC cppVar_77589 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77590 = (cppVar_77589 << 3) | 6;
	cppVar_77590 = (cppVar_77590 & cppMask_un_5_);
	BIT_VEC cppVar_77591 = (0 << 5) | cppVar_77590;
	cppVar_77591 = (cppVar_77591 & cppMask_un_8_);
	bool cppVar_77593 = (cppVar_77591 == 240);
	if (cppVar_77593) {
	cppVar_77588 = B;
	} else {
	cppVar_77588 = 0;
	}
	cppVar_77582 = cppVar_77588;
	}
	cppVar_77576 = cppVar_77582;
	}
	cppVar_77570 = cppVar_77576;
	}
	cppVar_77564 = cppVar_77570;
	}
	cppVar_77558 = cppVar_77564;
	}
	cppVar_77552 = cppVar_77558;
	}
	cppVar_77546 = cppVar_77552;
	}
	cppVar_77540 = cppVar_77546;
	}
	cppVar_77534 = cppVar_77540;
	}
	cppVar_77528 = cppVar_77534;
	}
	cppVar_77522 = cppVar_77528;
	}
	cppVar_77516 = cppVar_77522;
	}
	cppVar_77510 = cppVar_77516;
	}
	cppVar_77504 = cppVar_77510;
	}
	cppVar_77498 = cppVar_77504;
	}
	cppVar_77492 = cppVar_77498;
	}
	cppVar_77486 = cppVar_77492;
	}
	cppVar_77480 = cppVar_77486;
	}
	cppVar_77474 = cppVar_77480;
	}
	cppVar_77468 = cppVar_77474;
	}
	cppVar_77455 = cppVar_77468;
	}
	cppVar_77449 = cppVar_77455;
	} else {
	cppVar_77449 = TL0;
	}
	cppVar_77445 = cppVar_77449;
	} else {
	BIT_VEC cppVar_77595;
	BIT_VEC cppVar_77596 = ROM.rd(PC);
	bool cppVar_77598 = (cppVar_77596 == 141);
	if (cppVar_77598) {
	BIT_VEC cppVar_77599;
	BIT_VEC cppVar_77601 = PC + 1;
	cppVar_77601 = (cppVar_77601 & cppMask_un_16_);
	BIT_VEC cppVar_77602 = ROM.rd(cppVar_77601);
	bool cppVar_77604 = (cppVar_77602 == 138);
	if (cppVar_77604) {
	BIT_VEC cppVar_77605;
	BIT_VEC cppVar_77607 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77609 = (cppVar_77607 << 3) | 5;
	cppVar_77609 = (cppVar_77609 & cppMask_un_5_);
	BIT_VEC cppVar_77610 = (0 << 5) | cppVar_77609;
	cppVar_77610 = (cppVar_77610 & cppMask_un_8_);
	BIT_VEC cppVar_77611 = (cppVar_77610 >> 7) & cppMask_un_1_;
	bool cppVar_77613 = (cppVar_77611 == 0);
	if (cppVar_77613) {
	BIT_VEC cppVar_77614 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77615 = (cppVar_77614 << 3) | 5;
	cppVar_77615 = (cppVar_77615 & cppMask_un_5_);
	BIT_VEC cppVar_77616 = (0 << 5) | cppVar_77615;
	cppVar_77616 = (cppVar_77616 & cppMask_un_8_);
	BIT_VEC cppVar_77617 = IRAM.rd(cppVar_77616);
	cppVar_77605 = cppVar_77617;
	} else {
	BIT_VEC cppVar_77618;
	BIT_VEC cppVar_77619 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77620 = (cppVar_77619 << 3) | 5;
	cppVar_77620 = (cppVar_77620 & cppMask_un_5_);
	BIT_VEC cppVar_77621 = (0 << 5) | cppVar_77620;
	cppVar_77621 = (cppVar_77621 & cppMask_un_8_);
	bool cppVar_77623 = (cppVar_77621 == 128);
	if (cppVar_77623) {
	cppVar_77618 = P0;
	} else {
	BIT_VEC cppVar_77624;
	BIT_VEC cppVar_77625 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77626 = (cppVar_77625 << 3) | 5;
	cppVar_77626 = (cppVar_77626 & cppMask_un_5_);
	BIT_VEC cppVar_77627 = (0 << 5) | cppVar_77626;
	cppVar_77627 = (cppVar_77627 & cppMask_un_8_);
	bool cppVar_77629 = (cppVar_77627 == 129);
	if (cppVar_77629) {
	cppVar_77624 = SP;
	} else {
	BIT_VEC cppVar_77630;
	BIT_VEC cppVar_77631 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77632 = (cppVar_77631 << 3) | 5;
	cppVar_77632 = (cppVar_77632 & cppMask_un_5_);
	BIT_VEC cppVar_77633 = (0 << 5) | cppVar_77632;
	cppVar_77633 = (cppVar_77633 & cppMask_un_8_);
	bool cppVar_77635 = (cppVar_77633 == 130);
	if (cppVar_77635) {
	cppVar_77630 = DPL;
	} else {
	BIT_VEC cppVar_77636;
	BIT_VEC cppVar_77637 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77638 = (cppVar_77637 << 3) | 5;
	cppVar_77638 = (cppVar_77638 & cppMask_un_5_);
	BIT_VEC cppVar_77639 = (0 << 5) | cppVar_77638;
	cppVar_77639 = (cppVar_77639 & cppMask_un_8_);
	bool cppVar_77641 = (cppVar_77639 == 131);
	if (cppVar_77641) {
	cppVar_77636 = DPH;
	} else {
	BIT_VEC cppVar_77642;
	BIT_VEC cppVar_77643 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77644 = (cppVar_77643 << 3) | 5;
	cppVar_77644 = (cppVar_77644 & cppMask_un_5_);
	BIT_VEC cppVar_77645 = (0 << 5) | cppVar_77644;
	cppVar_77645 = (cppVar_77645 & cppMask_un_8_);
	bool cppVar_77647 = (cppVar_77645 == 135);
	if (cppVar_77647) {
	cppVar_77642 = PCON;
	} else {
	BIT_VEC cppVar_77648;
	BIT_VEC cppVar_77649 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77650 = (cppVar_77649 << 3) | 5;
	cppVar_77650 = (cppVar_77650 & cppMask_un_5_);
	BIT_VEC cppVar_77651 = (0 << 5) | cppVar_77650;
	cppVar_77651 = (cppVar_77651 & cppMask_un_8_);
	bool cppVar_77653 = (cppVar_77651 == 136);
	if (cppVar_77653) {
	cppVar_77648 = TCON;
	} else {
	BIT_VEC cppVar_77654;
	BIT_VEC cppVar_77655 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77656 = (cppVar_77655 << 3) | 5;
	cppVar_77656 = (cppVar_77656 & cppMask_un_5_);
	BIT_VEC cppVar_77657 = (0 << 5) | cppVar_77656;
	cppVar_77657 = (cppVar_77657 & cppMask_un_8_);
	bool cppVar_77659 = (cppVar_77657 == 137);
	if (cppVar_77659) {
	cppVar_77654 = TMOD;
	} else {
	BIT_VEC cppVar_77660;
	BIT_VEC cppVar_77661 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77662 = (cppVar_77661 << 3) | 5;
	cppVar_77662 = (cppVar_77662 & cppMask_un_5_);
	BIT_VEC cppVar_77663 = (0 << 5) | cppVar_77662;
	cppVar_77663 = (cppVar_77663 & cppMask_un_8_);
	bool cppVar_77665 = (cppVar_77663 == 138);
	if (cppVar_77665) {
	cppVar_77660 = TL0;
	} else {
	BIT_VEC cppVar_77666;
	BIT_VEC cppVar_77667 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77668 = (cppVar_77667 << 3) | 5;
	cppVar_77668 = (cppVar_77668 & cppMask_un_5_);
	BIT_VEC cppVar_77669 = (0 << 5) | cppVar_77668;
	cppVar_77669 = (cppVar_77669 & cppMask_un_8_);
	bool cppVar_77671 = (cppVar_77669 == 140);
	if (cppVar_77671) {
	cppVar_77666 = TH0;
	} else {
	BIT_VEC cppVar_77672;
	BIT_VEC cppVar_77673 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77674 = (cppVar_77673 << 3) | 5;
	cppVar_77674 = (cppVar_77674 & cppMask_un_5_);
	BIT_VEC cppVar_77675 = (0 << 5) | cppVar_77674;
	cppVar_77675 = (cppVar_77675 & cppMask_un_8_);
	bool cppVar_77677 = (cppVar_77675 == 139);
	if (cppVar_77677) {
	cppVar_77672 = TL1;
	} else {
	BIT_VEC cppVar_77678;
	BIT_VEC cppVar_77679 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77680 = (cppVar_77679 << 3) | 5;
	cppVar_77680 = (cppVar_77680 & cppMask_un_5_);
	BIT_VEC cppVar_77681 = (0 << 5) | cppVar_77680;
	cppVar_77681 = (cppVar_77681 & cppMask_un_8_);
	bool cppVar_77683 = (cppVar_77681 == 141);
	if (cppVar_77683) {
	cppVar_77678 = TH1;
	} else {
	BIT_VEC cppVar_77684;
	BIT_VEC cppVar_77685 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77686 = (cppVar_77685 << 3) | 5;
	cppVar_77686 = (cppVar_77686 & cppMask_un_5_);
	BIT_VEC cppVar_77687 = (0 << 5) | cppVar_77686;
	cppVar_77687 = (cppVar_77687 & cppMask_un_8_);
	bool cppVar_77689 = (cppVar_77687 == 144);
	if (cppVar_77689) {
	cppVar_77684 = P1;
	} else {
	BIT_VEC cppVar_77690;
	BIT_VEC cppVar_77691 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77692 = (cppVar_77691 << 3) | 5;
	cppVar_77692 = (cppVar_77692 & cppMask_un_5_);
	BIT_VEC cppVar_77693 = (0 << 5) | cppVar_77692;
	cppVar_77693 = (cppVar_77693 & cppMask_un_8_);
	bool cppVar_77695 = (cppVar_77693 == 152);
	if (cppVar_77695) {
	cppVar_77690 = SCON;
	} else {
	BIT_VEC cppVar_77696;
	BIT_VEC cppVar_77697 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77698 = (cppVar_77697 << 3) | 5;
	cppVar_77698 = (cppVar_77698 & cppMask_un_5_);
	BIT_VEC cppVar_77699 = (0 << 5) | cppVar_77698;
	cppVar_77699 = (cppVar_77699 & cppMask_un_8_);
	bool cppVar_77701 = (cppVar_77699 == 153);
	if (cppVar_77701) {
	cppVar_77696 = SBUF;
	} else {
	BIT_VEC cppVar_77702;
	BIT_VEC cppVar_77703 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77704 = (cppVar_77703 << 3) | 5;
	cppVar_77704 = (cppVar_77704 & cppMask_un_5_);
	BIT_VEC cppVar_77705 = (0 << 5) | cppVar_77704;
	cppVar_77705 = (cppVar_77705 & cppMask_un_8_);
	bool cppVar_77707 = (cppVar_77705 == 160);
	if (cppVar_77707) {
	cppVar_77702 = P2;
	} else {
	BIT_VEC cppVar_77708;
	BIT_VEC cppVar_77709 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77710 = (cppVar_77709 << 3) | 5;
	cppVar_77710 = (cppVar_77710 & cppMask_un_5_);
	BIT_VEC cppVar_77711 = (0 << 5) | cppVar_77710;
	cppVar_77711 = (cppVar_77711 & cppMask_un_8_);
	bool cppVar_77713 = (cppVar_77711 == 168);
	if (cppVar_77713) {
	cppVar_77708 = IE;
	} else {
	BIT_VEC cppVar_77714;
	BIT_VEC cppVar_77715 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77716 = (cppVar_77715 << 3) | 5;
	cppVar_77716 = (cppVar_77716 & cppMask_un_5_);
	BIT_VEC cppVar_77717 = (0 << 5) | cppVar_77716;
	cppVar_77717 = (cppVar_77717 & cppMask_un_8_);
	bool cppVar_77719 = (cppVar_77717 == 176);
	if (cppVar_77719) {
	cppVar_77714 = P3;
	} else {
	BIT_VEC cppVar_77720;
	BIT_VEC cppVar_77721 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77722 = (cppVar_77721 << 3) | 5;
	cppVar_77722 = (cppVar_77722 & cppMask_un_5_);
	BIT_VEC cppVar_77723 = (0 << 5) | cppVar_77722;
	cppVar_77723 = (cppVar_77723 & cppMask_un_8_);
	bool cppVar_77725 = (cppVar_77723 == 184);
	if (cppVar_77725) {
	cppVar_77720 = IP;
	} else {
	BIT_VEC cppVar_77726;
	BIT_VEC cppVar_77727 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77728 = (cppVar_77727 << 3) | 5;
	cppVar_77728 = (cppVar_77728 & cppMask_un_5_);
	BIT_VEC cppVar_77729 = (0 << 5) | cppVar_77728;
	cppVar_77729 = (cppVar_77729 & cppMask_un_8_);
	bool cppVar_77731 = (cppVar_77729 == 208);
	if (cppVar_77731) {
	cppVar_77726 = PSW;
	} else {
	BIT_VEC cppVar_77732;
	BIT_VEC cppVar_77733 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77734 = (cppVar_77733 << 3) | 5;
	cppVar_77734 = (cppVar_77734 & cppMask_un_5_);
	BIT_VEC cppVar_77735 = (0 << 5) | cppVar_77734;
	cppVar_77735 = (cppVar_77735 & cppMask_un_8_);
	bool cppVar_77737 = (cppVar_77735 == 224);
	if (cppVar_77737) {
	cppVar_77732 = ACC;
	} else {
	BIT_VEC cppVar_77738;
	BIT_VEC cppVar_77739 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77740 = (cppVar_77739 << 3) | 5;
	cppVar_77740 = (cppVar_77740 & cppMask_un_5_);
	BIT_VEC cppVar_77741 = (0 << 5) | cppVar_77740;
	cppVar_77741 = (cppVar_77741 & cppMask_un_8_);
	bool cppVar_77743 = (cppVar_77741 == 240);
	if (cppVar_77743) {
	cppVar_77738 = B;
	} else {
	cppVar_77738 = 0;
	}
	cppVar_77732 = cppVar_77738;
	}
	cppVar_77726 = cppVar_77732;
	}
	cppVar_77720 = cppVar_77726;
	}
	cppVar_77714 = cppVar_77720;
	}
	cppVar_77708 = cppVar_77714;
	}
	cppVar_77702 = cppVar_77708;
	}
	cppVar_77696 = cppVar_77702;
	}
	cppVar_77690 = cppVar_77696;
	}
	cppVar_77684 = cppVar_77690;
	}
	cppVar_77678 = cppVar_77684;
	}
	cppVar_77672 = cppVar_77678;
	}
	cppVar_77666 = cppVar_77672;
	}
	cppVar_77660 = cppVar_77666;
	}
	cppVar_77654 = cppVar_77660;
	}
	cppVar_77648 = cppVar_77654;
	}
	cppVar_77642 = cppVar_77648;
	}
	cppVar_77636 = cppVar_77642;
	}
	cppVar_77630 = cppVar_77636;
	}
	cppVar_77624 = cppVar_77630;
	}
	cppVar_77618 = cppVar_77624;
	}
	cppVar_77605 = cppVar_77618;
	}
	cppVar_77599 = cppVar_77605;
	} else {
	cppVar_77599 = TL0;
	}
	cppVar_77595 = cppVar_77599;
	} else {
	BIT_VEC cppVar_77745;
	BIT_VEC cppVar_77746 = ROM.rd(PC);
	bool cppVar_77748 = (cppVar_77746 == 140);
	if (cppVar_77748) {
	BIT_VEC cppVar_77749;
	BIT_VEC cppVar_77751 = PC + 1;
	cppVar_77751 = (cppVar_77751 & cppMask_un_16_);
	BIT_VEC cppVar_77752 = ROM.rd(cppVar_77751);
	bool cppVar_77754 = (cppVar_77752 == 138);
	if (cppVar_77754) {
	BIT_VEC cppVar_77755;
	BIT_VEC cppVar_77757 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77759 = (cppVar_77757 << 3) | 4;
	cppVar_77759 = (cppVar_77759 & cppMask_un_5_);
	BIT_VEC cppVar_77760 = (0 << 5) | cppVar_77759;
	cppVar_77760 = (cppVar_77760 & cppMask_un_8_);
	BIT_VEC cppVar_77761 = (cppVar_77760 >> 7) & cppMask_un_1_;
	bool cppVar_77763 = (cppVar_77761 == 0);
	if (cppVar_77763) {
	BIT_VEC cppVar_77764 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77765 = (cppVar_77764 << 3) | 4;
	cppVar_77765 = (cppVar_77765 & cppMask_un_5_);
	BIT_VEC cppVar_77766 = (0 << 5) | cppVar_77765;
	cppVar_77766 = (cppVar_77766 & cppMask_un_8_);
	BIT_VEC cppVar_77767 = IRAM.rd(cppVar_77766);
	cppVar_77755 = cppVar_77767;
	} else {
	BIT_VEC cppVar_77768;
	BIT_VEC cppVar_77769 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77770 = (cppVar_77769 << 3) | 4;
	cppVar_77770 = (cppVar_77770 & cppMask_un_5_);
	BIT_VEC cppVar_77771 = (0 << 5) | cppVar_77770;
	cppVar_77771 = (cppVar_77771 & cppMask_un_8_);
	bool cppVar_77773 = (cppVar_77771 == 128);
	if (cppVar_77773) {
	cppVar_77768 = P0;
	} else {
	BIT_VEC cppVar_77774;
	BIT_VEC cppVar_77775 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77776 = (cppVar_77775 << 3) | 4;
	cppVar_77776 = (cppVar_77776 & cppMask_un_5_);
	BIT_VEC cppVar_77777 = (0 << 5) | cppVar_77776;
	cppVar_77777 = (cppVar_77777 & cppMask_un_8_);
	bool cppVar_77779 = (cppVar_77777 == 129);
	if (cppVar_77779) {
	cppVar_77774 = SP;
	} else {
	BIT_VEC cppVar_77780;
	BIT_VEC cppVar_77781 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77782 = (cppVar_77781 << 3) | 4;
	cppVar_77782 = (cppVar_77782 & cppMask_un_5_);
	BIT_VEC cppVar_77783 = (0 << 5) | cppVar_77782;
	cppVar_77783 = (cppVar_77783 & cppMask_un_8_);
	bool cppVar_77785 = (cppVar_77783 == 130);
	if (cppVar_77785) {
	cppVar_77780 = DPL;
	} else {
	BIT_VEC cppVar_77786;
	BIT_VEC cppVar_77787 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77788 = (cppVar_77787 << 3) | 4;
	cppVar_77788 = (cppVar_77788 & cppMask_un_5_);
	BIT_VEC cppVar_77789 = (0 << 5) | cppVar_77788;
	cppVar_77789 = (cppVar_77789 & cppMask_un_8_);
	bool cppVar_77791 = (cppVar_77789 == 131);
	if (cppVar_77791) {
	cppVar_77786 = DPH;
	} else {
	BIT_VEC cppVar_77792;
	BIT_VEC cppVar_77793 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77794 = (cppVar_77793 << 3) | 4;
	cppVar_77794 = (cppVar_77794 & cppMask_un_5_);
	BIT_VEC cppVar_77795 = (0 << 5) | cppVar_77794;
	cppVar_77795 = (cppVar_77795 & cppMask_un_8_);
	bool cppVar_77797 = (cppVar_77795 == 135);
	if (cppVar_77797) {
	cppVar_77792 = PCON;
	} else {
	BIT_VEC cppVar_77798;
	BIT_VEC cppVar_77799 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77800 = (cppVar_77799 << 3) | 4;
	cppVar_77800 = (cppVar_77800 & cppMask_un_5_);
	BIT_VEC cppVar_77801 = (0 << 5) | cppVar_77800;
	cppVar_77801 = (cppVar_77801 & cppMask_un_8_);
	bool cppVar_77803 = (cppVar_77801 == 136);
	if (cppVar_77803) {
	cppVar_77798 = TCON;
	} else {
	BIT_VEC cppVar_77804;
	BIT_VEC cppVar_77805 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77806 = (cppVar_77805 << 3) | 4;
	cppVar_77806 = (cppVar_77806 & cppMask_un_5_);
	BIT_VEC cppVar_77807 = (0 << 5) | cppVar_77806;
	cppVar_77807 = (cppVar_77807 & cppMask_un_8_);
	bool cppVar_77809 = (cppVar_77807 == 137);
	if (cppVar_77809) {
	cppVar_77804 = TMOD;
	} else {
	BIT_VEC cppVar_77810;
	BIT_VEC cppVar_77811 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77812 = (cppVar_77811 << 3) | 4;
	cppVar_77812 = (cppVar_77812 & cppMask_un_5_);
	BIT_VEC cppVar_77813 = (0 << 5) | cppVar_77812;
	cppVar_77813 = (cppVar_77813 & cppMask_un_8_);
	bool cppVar_77815 = (cppVar_77813 == 138);
	if (cppVar_77815) {
	cppVar_77810 = TL0;
	} else {
	BIT_VEC cppVar_77816;
	BIT_VEC cppVar_77817 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77818 = (cppVar_77817 << 3) | 4;
	cppVar_77818 = (cppVar_77818 & cppMask_un_5_);
	BIT_VEC cppVar_77819 = (0 << 5) | cppVar_77818;
	cppVar_77819 = (cppVar_77819 & cppMask_un_8_);
	bool cppVar_77821 = (cppVar_77819 == 140);
	if (cppVar_77821) {
	cppVar_77816 = TH0;
	} else {
	BIT_VEC cppVar_77822;
	BIT_VEC cppVar_77823 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77824 = (cppVar_77823 << 3) | 4;
	cppVar_77824 = (cppVar_77824 & cppMask_un_5_);
	BIT_VEC cppVar_77825 = (0 << 5) | cppVar_77824;
	cppVar_77825 = (cppVar_77825 & cppMask_un_8_);
	bool cppVar_77827 = (cppVar_77825 == 139);
	if (cppVar_77827) {
	cppVar_77822 = TL1;
	} else {
	BIT_VEC cppVar_77828;
	BIT_VEC cppVar_77829 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77830 = (cppVar_77829 << 3) | 4;
	cppVar_77830 = (cppVar_77830 & cppMask_un_5_);
	BIT_VEC cppVar_77831 = (0 << 5) | cppVar_77830;
	cppVar_77831 = (cppVar_77831 & cppMask_un_8_);
	bool cppVar_77833 = (cppVar_77831 == 141);
	if (cppVar_77833) {
	cppVar_77828 = TH1;
	} else {
	BIT_VEC cppVar_77834;
	BIT_VEC cppVar_77835 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77836 = (cppVar_77835 << 3) | 4;
	cppVar_77836 = (cppVar_77836 & cppMask_un_5_);
	BIT_VEC cppVar_77837 = (0 << 5) | cppVar_77836;
	cppVar_77837 = (cppVar_77837 & cppMask_un_8_);
	bool cppVar_77839 = (cppVar_77837 == 144);
	if (cppVar_77839) {
	cppVar_77834 = P1;
	} else {
	BIT_VEC cppVar_77840;
	BIT_VEC cppVar_77841 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77842 = (cppVar_77841 << 3) | 4;
	cppVar_77842 = (cppVar_77842 & cppMask_un_5_);
	BIT_VEC cppVar_77843 = (0 << 5) | cppVar_77842;
	cppVar_77843 = (cppVar_77843 & cppMask_un_8_);
	bool cppVar_77845 = (cppVar_77843 == 152);
	if (cppVar_77845) {
	cppVar_77840 = SCON;
	} else {
	BIT_VEC cppVar_77846;
	BIT_VEC cppVar_77847 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77848 = (cppVar_77847 << 3) | 4;
	cppVar_77848 = (cppVar_77848 & cppMask_un_5_);
	BIT_VEC cppVar_77849 = (0 << 5) | cppVar_77848;
	cppVar_77849 = (cppVar_77849 & cppMask_un_8_);
	bool cppVar_77851 = (cppVar_77849 == 153);
	if (cppVar_77851) {
	cppVar_77846 = SBUF;
	} else {
	BIT_VEC cppVar_77852;
	BIT_VEC cppVar_77853 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77854 = (cppVar_77853 << 3) | 4;
	cppVar_77854 = (cppVar_77854 & cppMask_un_5_);
	BIT_VEC cppVar_77855 = (0 << 5) | cppVar_77854;
	cppVar_77855 = (cppVar_77855 & cppMask_un_8_);
	bool cppVar_77857 = (cppVar_77855 == 160);
	if (cppVar_77857) {
	cppVar_77852 = P2;
	} else {
	BIT_VEC cppVar_77858;
	BIT_VEC cppVar_77859 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77860 = (cppVar_77859 << 3) | 4;
	cppVar_77860 = (cppVar_77860 & cppMask_un_5_);
	BIT_VEC cppVar_77861 = (0 << 5) | cppVar_77860;
	cppVar_77861 = (cppVar_77861 & cppMask_un_8_);
	bool cppVar_77863 = (cppVar_77861 == 168);
	if (cppVar_77863) {
	cppVar_77858 = IE;
	} else {
	BIT_VEC cppVar_77864;
	BIT_VEC cppVar_77865 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77866 = (cppVar_77865 << 3) | 4;
	cppVar_77866 = (cppVar_77866 & cppMask_un_5_);
	BIT_VEC cppVar_77867 = (0 << 5) | cppVar_77866;
	cppVar_77867 = (cppVar_77867 & cppMask_un_8_);
	bool cppVar_77869 = (cppVar_77867 == 176);
	if (cppVar_77869) {
	cppVar_77864 = P3;
	} else {
	BIT_VEC cppVar_77870;
	BIT_VEC cppVar_77871 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77872 = (cppVar_77871 << 3) | 4;
	cppVar_77872 = (cppVar_77872 & cppMask_un_5_);
	BIT_VEC cppVar_77873 = (0 << 5) | cppVar_77872;
	cppVar_77873 = (cppVar_77873 & cppMask_un_8_);
	bool cppVar_77875 = (cppVar_77873 == 184);
	if (cppVar_77875) {
	cppVar_77870 = IP;
	} else {
	BIT_VEC cppVar_77876;
	BIT_VEC cppVar_77877 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77878 = (cppVar_77877 << 3) | 4;
	cppVar_77878 = (cppVar_77878 & cppMask_un_5_);
	BIT_VEC cppVar_77879 = (0 << 5) | cppVar_77878;
	cppVar_77879 = (cppVar_77879 & cppMask_un_8_);
	bool cppVar_77881 = (cppVar_77879 == 208);
	if (cppVar_77881) {
	cppVar_77876 = PSW;
	} else {
	BIT_VEC cppVar_77882;
	BIT_VEC cppVar_77883 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77884 = (cppVar_77883 << 3) | 4;
	cppVar_77884 = (cppVar_77884 & cppMask_un_5_);
	BIT_VEC cppVar_77885 = (0 << 5) | cppVar_77884;
	cppVar_77885 = (cppVar_77885 & cppMask_un_8_);
	bool cppVar_77887 = (cppVar_77885 == 224);
	if (cppVar_77887) {
	cppVar_77882 = ACC;
	} else {
	BIT_VEC cppVar_77888;
	BIT_VEC cppVar_77889 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77890 = (cppVar_77889 << 3) | 4;
	cppVar_77890 = (cppVar_77890 & cppMask_un_5_);
	BIT_VEC cppVar_77891 = (0 << 5) | cppVar_77890;
	cppVar_77891 = (cppVar_77891 & cppMask_un_8_);
	bool cppVar_77893 = (cppVar_77891 == 240);
	if (cppVar_77893) {
	cppVar_77888 = B;
	} else {
	cppVar_77888 = 0;
	}
	cppVar_77882 = cppVar_77888;
	}
	cppVar_77876 = cppVar_77882;
	}
	cppVar_77870 = cppVar_77876;
	}
	cppVar_77864 = cppVar_77870;
	}
	cppVar_77858 = cppVar_77864;
	}
	cppVar_77852 = cppVar_77858;
	}
	cppVar_77846 = cppVar_77852;
	}
	cppVar_77840 = cppVar_77846;
	}
	cppVar_77834 = cppVar_77840;
	}
	cppVar_77828 = cppVar_77834;
	}
	cppVar_77822 = cppVar_77828;
	}
	cppVar_77816 = cppVar_77822;
	}
	cppVar_77810 = cppVar_77816;
	}
	cppVar_77804 = cppVar_77810;
	}
	cppVar_77798 = cppVar_77804;
	}
	cppVar_77792 = cppVar_77798;
	}
	cppVar_77786 = cppVar_77792;
	}
	cppVar_77780 = cppVar_77786;
	}
	cppVar_77774 = cppVar_77780;
	}
	cppVar_77768 = cppVar_77774;
	}
	cppVar_77755 = cppVar_77768;
	}
	cppVar_77749 = cppVar_77755;
	} else {
	cppVar_77749 = TL0;
	}
	cppVar_77745 = cppVar_77749;
	} else {
	BIT_VEC cppVar_77895;
	BIT_VEC cppVar_77896 = ROM.rd(PC);
	bool cppVar_77898 = (cppVar_77896 == 139);
	if (cppVar_77898) {
	BIT_VEC cppVar_77899;
	BIT_VEC cppVar_77901 = PC + 1;
	cppVar_77901 = (cppVar_77901 & cppMask_un_16_);
	BIT_VEC cppVar_77902 = ROM.rd(cppVar_77901);
	bool cppVar_77904 = (cppVar_77902 == 138);
	if (cppVar_77904) {
	BIT_VEC cppVar_77905;
	BIT_VEC cppVar_77907 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77909 = (cppVar_77907 << 3) | 3;
	cppVar_77909 = (cppVar_77909 & cppMask_un_5_);
	BIT_VEC cppVar_77910 = (0 << 5) | cppVar_77909;
	cppVar_77910 = (cppVar_77910 & cppMask_un_8_);
	BIT_VEC cppVar_77911 = (cppVar_77910 >> 7) & cppMask_un_1_;
	bool cppVar_77913 = (cppVar_77911 == 0);
	if (cppVar_77913) {
	BIT_VEC cppVar_77914 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77915 = (cppVar_77914 << 3) | 3;
	cppVar_77915 = (cppVar_77915 & cppMask_un_5_);
	BIT_VEC cppVar_77916 = (0 << 5) | cppVar_77915;
	cppVar_77916 = (cppVar_77916 & cppMask_un_8_);
	BIT_VEC cppVar_77917 = IRAM.rd(cppVar_77916);
	cppVar_77905 = cppVar_77917;
	} else {
	BIT_VEC cppVar_77918;
	BIT_VEC cppVar_77919 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77920 = (cppVar_77919 << 3) | 3;
	cppVar_77920 = (cppVar_77920 & cppMask_un_5_);
	BIT_VEC cppVar_77921 = (0 << 5) | cppVar_77920;
	cppVar_77921 = (cppVar_77921 & cppMask_un_8_);
	bool cppVar_77923 = (cppVar_77921 == 128);
	if (cppVar_77923) {
	cppVar_77918 = P0;
	} else {
	BIT_VEC cppVar_77924;
	BIT_VEC cppVar_77925 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77926 = (cppVar_77925 << 3) | 3;
	cppVar_77926 = (cppVar_77926 & cppMask_un_5_);
	BIT_VEC cppVar_77927 = (0 << 5) | cppVar_77926;
	cppVar_77927 = (cppVar_77927 & cppMask_un_8_);
	bool cppVar_77929 = (cppVar_77927 == 129);
	if (cppVar_77929) {
	cppVar_77924 = SP;
	} else {
	BIT_VEC cppVar_77930;
	BIT_VEC cppVar_77931 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77932 = (cppVar_77931 << 3) | 3;
	cppVar_77932 = (cppVar_77932 & cppMask_un_5_);
	BIT_VEC cppVar_77933 = (0 << 5) | cppVar_77932;
	cppVar_77933 = (cppVar_77933 & cppMask_un_8_);
	bool cppVar_77935 = (cppVar_77933 == 130);
	if (cppVar_77935) {
	cppVar_77930 = DPL;
	} else {
	BIT_VEC cppVar_77936;
	BIT_VEC cppVar_77937 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77938 = (cppVar_77937 << 3) | 3;
	cppVar_77938 = (cppVar_77938 & cppMask_un_5_);
	BIT_VEC cppVar_77939 = (0 << 5) | cppVar_77938;
	cppVar_77939 = (cppVar_77939 & cppMask_un_8_);
	bool cppVar_77941 = (cppVar_77939 == 131);
	if (cppVar_77941) {
	cppVar_77936 = DPH;
	} else {
	BIT_VEC cppVar_77942;
	BIT_VEC cppVar_77943 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77944 = (cppVar_77943 << 3) | 3;
	cppVar_77944 = (cppVar_77944 & cppMask_un_5_);
	BIT_VEC cppVar_77945 = (0 << 5) | cppVar_77944;
	cppVar_77945 = (cppVar_77945 & cppMask_un_8_);
	bool cppVar_77947 = (cppVar_77945 == 135);
	if (cppVar_77947) {
	cppVar_77942 = PCON;
	} else {
	BIT_VEC cppVar_77948;
	BIT_VEC cppVar_77949 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77950 = (cppVar_77949 << 3) | 3;
	cppVar_77950 = (cppVar_77950 & cppMask_un_5_);
	BIT_VEC cppVar_77951 = (0 << 5) | cppVar_77950;
	cppVar_77951 = (cppVar_77951 & cppMask_un_8_);
	bool cppVar_77953 = (cppVar_77951 == 136);
	if (cppVar_77953) {
	cppVar_77948 = TCON;
	} else {
	BIT_VEC cppVar_77954;
	BIT_VEC cppVar_77955 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77956 = (cppVar_77955 << 3) | 3;
	cppVar_77956 = (cppVar_77956 & cppMask_un_5_);
	BIT_VEC cppVar_77957 = (0 << 5) | cppVar_77956;
	cppVar_77957 = (cppVar_77957 & cppMask_un_8_);
	bool cppVar_77959 = (cppVar_77957 == 137);
	if (cppVar_77959) {
	cppVar_77954 = TMOD;
	} else {
	BIT_VEC cppVar_77960;
	BIT_VEC cppVar_77961 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77962 = (cppVar_77961 << 3) | 3;
	cppVar_77962 = (cppVar_77962 & cppMask_un_5_);
	BIT_VEC cppVar_77963 = (0 << 5) | cppVar_77962;
	cppVar_77963 = (cppVar_77963 & cppMask_un_8_);
	bool cppVar_77965 = (cppVar_77963 == 138);
	if (cppVar_77965) {
	cppVar_77960 = TL0;
	} else {
	BIT_VEC cppVar_77966;
	BIT_VEC cppVar_77967 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77968 = (cppVar_77967 << 3) | 3;
	cppVar_77968 = (cppVar_77968 & cppMask_un_5_);
	BIT_VEC cppVar_77969 = (0 << 5) | cppVar_77968;
	cppVar_77969 = (cppVar_77969 & cppMask_un_8_);
	bool cppVar_77971 = (cppVar_77969 == 140);
	if (cppVar_77971) {
	cppVar_77966 = TH0;
	} else {
	BIT_VEC cppVar_77972;
	BIT_VEC cppVar_77973 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77974 = (cppVar_77973 << 3) | 3;
	cppVar_77974 = (cppVar_77974 & cppMask_un_5_);
	BIT_VEC cppVar_77975 = (0 << 5) | cppVar_77974;
	cppVar_77975 = (cppVar_77975 & cppMask_un_8_);
	bool cppVar_77977 = (cppVar_77975 == 139);
	if (cppVar_77977) {
	cppVar_77972 = TL1;
	} else {
	BIT_VEC cppVar_77978;
	BIT_VEC cppVar_77979 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77980 = (cppVar_77979 << 3) | 3;
	cppVar_77980 = (cppVar_77980 & cppMask_un_5_);
	BIT_VEC cppVar_77981 = (0 << 5) | cppVar_77980;
	cppVar_77981 = (cppVar_77981 & cppMask_un_8_);
	bool cppVar_77983 = (cppVar_77981 == 141);
	if (cppVar_77983) {
	cppVar_77978 = TH1;
	} else {
	BIT_VEC cppVar_77984;
	BIT_VEC cppVar_77985 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77986 = (cppVar_77985 << 3) | 3;
	cppVar_77986 = (cppVar_77986 & cppMask_un_5_);
	BIT_VEC cppVar_77987 = (0 << 5) | cppVar_77986;
	cppVar_77987 = (cppVar_77987 & cppMask_un_8_);
	bool cppVar_77989 = (cppVar_77987 == 144);
	if (cppVar_77989) {
	cppVar_77984 = P1;
	} else {
	BIT_VEC cppVar_77990;
	BIT_VEC cppVar_77991 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77992 = (cppVar_77991 << 3) | 3;
	cppVar_77992 = (cppVar_77992 & cppMask_un_5_);
	BIT_VEC cppVar_77993 = (0 << 5) | cppVar_77992;
	cppVar_77993 = (cppVar_77993 & cppMask_un_8_);
	bool cppVar_77995 = (cppVar_77993 == 152);
	if (cppVar_77995) {
	cppVar_77990 = SCON;
	} else {
	BIT_VEC cppVar_77996;
	BIT_VEC cppVar_77997 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_77998 = (cppVar_77997 << 3) | 3;
	cppVar_77998 = (cppVar_77998 & cppMask_un_5_);
	BIT_VEC cppVar_77999 = (0 << 5) | cppVar_77998;
	cppVar_77999 = (cppVar_77999 & cppMask_un_8_);
	bool cppVar_78001 = (cppVar_77999 == 153);
	if (cppVar_78001) {
	cppVar_77996 = SBUF;
	} else {
	BIT_VEC cppVar_78002;
	BIT_VEC cppVar_78003 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78004 = (cppVar_78003 << 3) | 3;
	cppVar_78004 = (cppVar_78004 & cppMask_un_5_);
	BIT_VEC cppVar_78005 = (0 << 5) | cppVar_78004;
	cppVar_78005 = (cppVar_78005 & cppMask_un_8_);
	bool cppVar_78007 = (cppVar_78005 == 160);
	if (cppVar_78007) {
	cppVar_78002 = P2;
	} else {
	BIT_VEC cppVar_78008;
	BIT_VEC cppVar_78009 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78010 = (cppVar_78009 << 3) | 3;
	cppVar_78010 = (cppVar_78010 & cppMask_un_5_);
	BIT_VEC cppVar_78011 = (0 << 5) | cppVar_78010;
	cppVar_78011 = (cppVar_78011 & cppMask_un_8_);
	bool cppVar_78013 = (cppVar_78011 == 168);
	if (cppVar_78013) {
	cppVar_78008 = IE;
	} else {
	BIT_VEC cppVar_78014;
	BIT_VEC cppVar_78015 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78016 = (cppVar_78015 << 3) | 3;
	cppVar_78016 = (cppVar_78016 & cppMask_un_5_);
	BIT_VEC cppVar_78017 = (0 << 5) | cppVar_78016;
	cppVar_78017 = (cppVar_78017 & cppMask_un_8_);
	bool cppVar_78019 = (cppVar_78017 == 176);
	if (cppVar_78019) {
	cppVar_78014 = P3;
	} else {
	BIT_VEC cppVar_78020;
	BIT_VEC cppVar_78021 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78022 = (cppVar_78021 << 3) | 3;
	cppVar_78022 = (cppVar_78022 & cppMask_un_5_);
	BIT_VEC cppVar_78023 = (0 << 5) | cppVar_78022;
	cppVar_78023 = (cppVar_78023 & cppMask_un_8_);
	bool cppVar_78025 = (cppVar_78023 == 184);
	if (cppVar_78025) {
	cppVar_78020 = IP;
	} else {
	BIT_VEC cppVar_78026;
	BIT_VEC cppVar_78027 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78028 = (cppVar_78027 << 3) | 3;
	cppVar_78028 = (cppVar_78028 & cppMask_un_5_);
	BIT_VEC cppVar_78029 = (0 << 5) | cppVar_78028;
	cppVar_78029 = (cppVar_78029 & cppMask_un_8_);
	bool cppVar_78031 = (cppVar_78029 == 208);
	if (cppVar_78031) {
	cppVar_78026 = PSW;
	} else {
	BIT_VEC cppVar_78032;
	BIT_VEC cppVar_78033 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78034 = (cppVar_78033 << 3) | 3;
	cppVar_78034 = (cppVar_78034 & cppMask_un_5_);
	BIT_VEC cppVar_78035 = (0 << 5) | cppVar_78034;
	cppVar_78035 = (cppVar_78035 & cppMask_un_8_);
	bool cppVar_78037 = (cppVar_78035 == 224);
	if (cppVar_78037) {
	cppVar_78032 = ACC;
	} else {
	BIT_VEC cppVar_78038;
	BIT_VEC cppVar_78039 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78040 = (cppVar_78039 << 3) | 3;
	cppVar_78040 = (cppVar_78040 & cppMask_un_5_);
	BIT_VEC cppVar_78041 = (0 << 5) | cppVar_78040;
	cppVar_78041 = (cppVar_78041 & cppMask_un_8_);
	bool cppVar_78043 = (cppVar_78041 == 240);
	if (cppVar_78043) {
	cppVar_78038 = B;
	} else {
	cppVar_78038 = 0;
	}
	cppVar_78032 = cppVar_78038;
	}
	cppVar_78026 = cppVar_78032;
	}
	cppVar_78020 = cppVar_78026;
	}
	cppVar_78014 = cppVar_78020;
	}
	cppVar_78008 = cppVar_78014;
	}
	cppVar_78002 = cppVar_78008;
	}
	cppVar_77996 = cppVar_78002;
	}
	cppVar_77990 = cppVar_77996;
	}
	cppVar_77984 = cppVar_77990;
	}
	cppVar_77978 = cppVar_77984;
	}
	cppVar_77972 = cppVar_77978;
	}
	cppVar_77966 = cppVar_77972;
	}
	cppVar_77960 = cppVar_77966;
	}
	cppVar_77954 = cppVar_77960;
	}
	cppVar_77948 = cppVar_77954;
	}
	cppVar_77942 = cppVar_77948;
	}
	cppVar_77936 = cppVar_77942;
	}
	cppVar_77930 = cppVar_77936;
	}
	cppVar_77924 = cppVar_77930;
	}
	cppVar_77918 = cppVar_77924;
	}
	cppVar_77905 = cppVar_77918;
	}
	cppVar_77899 = cppVar_77905;
	} else {
	cppVar_77899 = TL0;
	}
	cppVar_77895 = cppVar_77899;
	} else {
	BIT_VEC cppVar_78045;
	BIT_VEC cppVar_78046 = ROM.rd(PC);
	bool cppVar_78048 = (cppVar_78046 == 138);
	if (cppVar_78048) {
	BIT_VEC cppVar_78049;
	BIT_VEC cppVar_78051 = PC + 1;
	cppVar_78051 = (cppVar_78051 & cppMask_un_16_);
	BIT_VEC cppVar_78052 = ROM.rd(cppVar_78051);
	bool cppVar_78054 = (cppVar_78052 == 138);
	if (cppVar_78054) {
	BIT_VEC cppVar_78055;
	BIT_VEC cppVar_78057 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78059 = (cppVar_78057 << 3) | 2;
	cppVar_78059 = (cppVar_78059 & cppMask_un_5_);
	BIT_VEC cppVar_78060 = (0 << 5) | cppVar_78059;
	cppVar_78060 = (cppVar_78060 & cppMask_un_8_);
	BIT_VEC cppVar_78061 = (cppVar_78060 >> 7) & cppMask_un_1_;
	bool cppVar_78063 = (cppVar_78061 == 0);
	if (cppVar_78063) {
	BIT_VEC cppVar_78064 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78065 = (cppVar_78064 << 3) | 2;
	cppVar_78065 = (cppVar_78065 & cppMask_un_5_);
	BIT_VEC cppVar_78066 = (0 << 5) | cppVar_78065;
	cppVar_78066 = (cppVar_78066 & cppMask_un_8_);
	BIT_VEC cppVar_78067 = IRAM.rd(cppVar_78066);
	cppVar_78055 = cppVar_78067;
	} else {
	BIT_VEC cppVar_78068;
	BIT_VEC cppVar_78069 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78070 = (cppVar_78069 << 3) | 2;
	cppVar_78070 = (cppVar_78070 & cppMask_un_5_);
	BIT_VEC cppVar_78071 = (0 << 5) | cppVar_78070;
	cppVar_78071 = (cppVar_78071 & cppMask_un_8_);
	bool cppVar_78073 = (cppVar_78071 == 128);
	if (cppVar_78073) {
	cppVar_78068 = P0;
	} else {
	BIT_VEC cppVar_78074;
	BIT_VEC cppVar_78075 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78076 = (cppVar_78075 << 3) | 2;
	cppVar_78076 = (cppVar_78076 & cppMask_un_5_);
	BIT_VEC cppVar_78077 = (0 << 5) | cppVar_78076;
	cppVar_78077 = (cppVar_78077 & cppMask_un_8_);
	bool cppVar_78079 = (cppVar_78077 == 129);
	if (cppVar_78079) {
	cppVar_78074 = SP;
	} else {
	BIT_VEC cppVar_78080;
	BIT_VEC cppVar_78081 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78082 = (cppVar_78081 << 3) | 2;
	cppVar_78082 = (cppVar_78082 & cppMask_un_5_);
	BIT_VEC cppVar_78083 = (0 << 5) | cppVar_78082;
	cppVar_78083 = (cppVar_78083 & cppMask_un_8_);
	bool cppVar_78085 = (cppVar_78083 == 130);
	if (cppVar_78085) {
	cppVar_78080 = DPL;
	} else {
	BIT_VEC cppVar_78086;
	BIT_VEC cppVar_78087 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78088 = (cppVar_78087 << 3) | 2;
	cppVar_78088 = (cppVar_78088 & cppMask_un_5_);
	BIT_VEC cppVar_78089 = (0 << 5) | cppVar_78088;
	cppVar_78089 = (cppVar_78089 & cppMask_un_8_);
	bool cppVar_78091 = (cppVar_78089 == 131);
	if (cppVar_78091) {
	cppVar_78086 = DPH;
	} else {
	BIT_VEC cppVar_78092;
	BIT_VEC cppVar_78093 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78094 = (cppVar_78093 << 3) | 2;
	cppVar_78094 = (cppVar_78094 & cppMask_un_5_);
	BIT_VEC cppVar_78095 = (0 << 5) | cppVar_78094;
	cppVar_78095 = (cppVar_78095 & cppMask_un_8_);
	bool cppVar_78097 = (cppVar_78095 == 135);
	if (cppVar_78097) {
	cppVar_78092 = PCON;
	} else {
	BIT_VEC cppVar_78098;
	BIT_VEC cppVar_78099 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78100 = (cppVar_78099 << 3) | 2;
	cppVar_78100 = (cppVar_78100 & cppMask_un_5_);
	BIT_VEC cppVar_78101 = (0 << 5) | cppVar_78100;
	cppVar_78101 = (cppVar_78101 & cppMask_un_8_);
	bool cppVar_78103 = (cppVar_78101 == 136);
	if (cppVar_78103) {
	cppVar_78098 = TCON;
	} else {
	BIT_VEC cppVar_78104;
	BIT_VEC cppVar_78105 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78106 = (cppVar_78105 << 3) | 2;
	cppVar_78106 = (cppVar_78106 & cppMask_un_5_);
	BIT_VEC cppVar_78107 = (0 << 5) | cppVar_78106;
	cppVar_78107 = (cppVar_78107 & cppMask_un_8_);
	bool cppVar_78109 = (cppVar_78107 == 137);
	if (cppVar_78109) {
	cppVar_78104 = TMOD;
	} else {
	BIT_VEC cppVar_78110;
	BIT_VEC cppVar_78111 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78112 = (cppVar_78111 << 3) | 2;
	cppVar_78112 = (cppVar_78112 & cppMask_un_5_);
	BIT_VEC cppVar_78113 = (0 << 5) | cppVar_78112;
	cppVar_78113 = (cppVar_78113 & cppMask_un_8_);
	bool cppVar_78115 = (cppVar_78113 == 138);
	if (cppVar_78115) {
	cppVar_78110 = TL0;
	} else {
	BIT_VEC cppVar_78116;
	BIT_VEC cppVar_78117 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78118 = (cppVar_78117 << 3) | 2;
	cppVar_78118 = (cppVar_78118 & cppMask_un_5_);
	BIT_VEC cppVar_78119 = (0 << 5) | cppVar_78118;
	cppVar_78119 = (cppVar_78119 & cppMask_un_8_);
	bool cppVar_78121 = (cppVar_78119 == 140);
	if (cppVar_78121) {
	cppVar_78116 = TH0;
	} else {
	BIT_VEC cppVar_78122;
	BIT_VEC cppVar_78123 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78124 = (cppVar_78123 << 3) | 2;
	cppVar_78124 = (cppVar_78124 & cppMask_un_5_);
	BIT_VEC cppVar_78125 = (0 << 5) | cppVar_78124;
	cppVar_78125 = (cppVar_78125 & cppMask_un_8_);
	bool cppVar_78127 = (cppVar_78125 == 139);
	if (cppVar_78127) {
	cppVar_78122 = TL1;
	} else {
	BIT_VEC cppVar_78128;
	BIT_VEC cppVar_78129 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78130 = (cppVar_78129 << 3) | 2;
	cppVar_78130 = (cppVar_78130 & cppMask_un_5_);
	BIT_VEC cppVar_78131 = (0 << 5) | cppVar_78130;
	cppVar_78131 = (cppVar_78131 & cppMask_un_8_);
	bool cppVar_78133 = (cppVar_78131 == 141);
	if (cppVar_78133) {
	cppVar_78128 = TH1;
	} else {
	BIT_VEC cppVar_78134;
	BIT_VEC cppVar_78135 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78136 = (cppVar_78135 << 3) | 2;
	cppVar_78136 = (cppVar_78136 & cppMask_un_5_);
	BIT_VEC cppVar_78137 = (0 << 5) | cppVar_78136;
	cppVar_78137 = (cppVar_78137 & cppMask_un_8_);
	bool cppVar_78139 = (cppVar_78137 == 144);
	if (cppVar_78139) {
	cppVar_78134 = P1;
	} else {
	BIT_VEC cppVar_78140;
	BIT_VEC cppVar_78141 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78142 = (cppVar_78141 << 3) | 2;
	cppVar_78142 = (cppVar_78142 & cppMask_un_5_);
	BIT_VEC cppVar_78143 = (0 << 5) | cppVar_78142;
	cppVar_78143 = (cppVar_78143 & cppMask_un_8_);
	bool cppVar_78145 = (cppVar_78143 == 152);
	if (cppVar_78145) {
	cppVar_78140 = SCON;
	} else {
	BIT_VEC cppVar_78146;
	BIT_VEC cppVar_78147 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78148 = (cppVar_78147 << 3) | 2;
	cppVar_78148 = (cppVar_78148 & cppMask_un_5_);
	BIT_VEC cppVar_78149 = (0 << 5) | cppVar_78148;
	cppVar_78149 = (cppVar_78149 & cppMask_un_8_);
	bool cppVar_78151 = (cppVar_78149 == 153);
	if (cppVar_78151) {
	cppVar_78146 = SBUF;
	} else {
	BIT_VEC cppVar_78152;
	BIT_VEC cppVar_78153 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78154 = (cppVar_78153 << 3) | 2;
	cppVar_78154 = (cppVar_78154 & cppMask_un_5_);
	BIT_VEC cppVar_78155 = (0 << 5) | cppVar_78154;
	cppVar_78155 = (cppVar_78155 & cppMask_un_8_);
	bool cppVar_78157 = (cppVar_78155 == 160);
	if (cppVar_78157) {
	cppVar_78152 = P2;
	} else {
	BIT_VEC cppVar_78158;
	BIT_VEC cppVar_78159 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78160 = (cppVar_78159 << 3) | 2;
	cppVar_78160 = (cppVar_78160 & cppMask_un_5_);
	BIT_VEC cppVar_78161 = (0 << 5) | cppVar_78160;
	cppVar_78161 = (cppVar_78161 & cppMask_un_8_);
	bool cppVar_78163 = (cppVar_78161 == 168);
	if (cppVar_78163) {
	cppVar_78158 = IE;
	} else {
	BIT_VEC cppVar_78164;
	BIT_VEC cppVar_78165 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78166 = (cppVar_78165 << 3) | 2;
	cppVar_78166 = (cppVar_78166 & cppMask_un_5_);
	BIT_VEC cppVar_78167 = (0 << 5) | cppVar_78166;
	cppVar_78167 = (cppVar_78167 & cppMask_un_8_);
	bool cppVar_78169 = (cppVar_78167 == 176);
	if (cppVar_78169) {
	cppVar_78164 = P3;
	} else {
	BIT_VEC cppVar_78170;
	BIT_VEC cppVar_78171 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78172 = (cppVar_78171 << 3) | 2;
	cppVar_78172 = (cppVar_78172 & cppMask_un_5_);
	BIT_VEC cppVar_78173 = (0 << 5) | cppVar_78172;
	cppVar_78173 = (cppVar_78173 & cppMask_un_8_);
	bool cppVar_78175 = (cppVar_78173 == 184);
	if (cppVar_78175) {
	cppVar_78170 = IP;
	} else {
	BIT_VEC cppVar_78176;
	BIT_VEC cppVar_78177 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78178 = (cppVar_78177 << 3) | 2;
	cppVar_78178 = (cppVar_78178 & cppMask_un_5_);
	BIT_VEC cppVar_78179 = (0 << 5) | cppVar_78178;
	cppVar_78179 = (cppVar_78179 & cppMask_un_8_);
	bool cppVar_78181 = (cppVar_78179 == 208);
	if (cppVar_78181) {
	cppVar_78176 = PSW;
	} else {
	BIT_VEC cppVar_78182;
	BIT_VEC cppVar_78183 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78184 = (cppVar_78183 << 3) | 2;
	cppVar_78184 = (cppVar_78184 & cppMask_un_5_);
	BIT_VEC cppVar_78185 = (0 << 5) | cppVar_78184;
	cppVar_78185 = (cppVar_78185 & cppMask_un_8_);
	bool cppVar_78187 = (cppVar_78185 == 224);
	if (cppVar_78187) {
	cppVar_78182 = ACC;
	} else {
	BIT_VEC cppVar_78188;
	BIT_VEC cppVar_78189 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78190 = (cppVar_78189 << 3) | 2;
	cppVar_78190 = (cppVar_78190 & cppMask_un_5_);
	BIT_VEC cppVar_78191 = (0 << 5) | cppVar_78190;
	cppVar_78191 = (cppVar_78191 & cppMask_un_8_);
	bool cppVar_78193 = (cppVar_78191 == 240);
	if (cppVar_78193) {
	cppVar_78188 = B;
	} else {
	cppVar_78188 = 0;
	}
	cppVar_78182 = cppVar_78188;
	}
	cppVar_78176 = cppVar_78182;
	}
	cppVar_78170 = cppVar_78176;
	}
	cppVar_78164 = cppVar_78170;
	}
	cppVar_78158 = cppVar_78164;
	}
	cppVar_78152 = cppVar_78158;
	}
	cppVar_78146 = cppVar_78152;
	}
	cppVar_78140 = cppVar_78146;
	}
	cppVar_78134 = cppVar_78140;
	}
	cppVar_78128 = cppVar_78134;
	}
	cppVar_78122 = cppVar_78128;
	}
	cppVar_78116 = cppVar_78122;
	}
	cppVar_78110 = cppVar_78116;
	}
	cppVar_78104 = cppVar_78110;
	}
	cppVar_78098 = cppVar_78104;
	}
	cppVar_78092 = cppVar_78098;
	}
	cppVar_78086 = cppVar_78092;
	}
	cppVar_78080 = cppVar_78086;
	}
	cppVar_78074 = cppVar_78080;
	}
	cppVar_78068 = cppVar_78074;
	}
	cppVar_78055 = cppVar_78068;
	}
	cppVar_78049 = cppVar_78055;
	} else {
	cppVar_78049 = TL0;
	}
	cppVar_78045 = cppVar_78049;
	} else {
	BIT_VEC cppVar_78195;
	BIT_VEC cppVar_78196 = ROM.rd(PC);
	bool cppVar_78198 = (cppVar_78196 == 137);
	if (cppVar_78198) {
	BIT_VEC cppVar_78199;
	BIT_VEC cppVar_78201 = PC + 1;
	cppVar_78201 = (cppVar_78201 & cppMask_un_16_);
	BIT_VEC cppVar_78202 = ROM.rd(cppVar_78201);
	bool cppVar_78204 = (cppVar_78202 == 138);
	if (cppVar_78204) {
	BIT_VEC cppVar_78205;
	BIT_VEC cppVar_78207 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78209 = (cppVar_78207 << 3) | 1;
	cppVar_78209 = (cppVar_78209 & cppMask_un_5_);
	BIT_VEC cppVar_78210 = (0 << 5) | cppVar_78209;
	cppVar_78210 = (cppVar_78210 & cppMask_un_8_);
	BIT_VEC cppVar_78211 = (cppVar_78210 >> 7) & cppMask_un_1_;
	bool cppVar_78213 = (cppVar_78211 == 0);
	if (cppVar_78213) {
	BIT_VEC cppVar_78214 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78215 = (cppVar_78214 << 3) | 1;
	cppVar_78215 = (cppVar_78215 & cppMask_un_5_);
	BIT_VEC cppVar_78216 = (0 << 5) | cppVar_78215;
	cppVar_78216 = (cppVar_78216 & cppMask_un_8_);
	BIT_VEC cppVar_78217 = IRAM.rd(cppVar_78216);
	cppVar_78205 = cppVar_78217;
	} else {
	BIT_VEC cppVar_78218;
	BIT_VEC cppVar_78219 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78220 = (cppVar_78219 << 3) | 1;
	cppVar_78220 = (cppVar_78220 & cppMask_un_5_);
	BIT_VEC cppVar_78221 = (0 << 5) | cppVar_78220;
	cppVar_78221 = (cppVar_78221 & cppMask_un_8_);
	bool cppVar_78223 = (cppVar_78221 == 128);
	if (cppVar_78223) {
	cppVar_78218 = P0;
	} else {
	BIT_VEC cppVar_78224;
	BIT_VEC cppVar_78225 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78226 = (cppVar_78225 << 3) | 1;
	cppVar_78226 = (cppVar_78226 & cppMask_un_5_);
	BIT_VEC cppVar_78227 = (0 << 5) | cppVar_78226;
	cppVar_78227 = (cppVar_78227 & cppMask_un_8_);
	bool cppVar_78229 = (cppVar_78227 == 129);
	if (cppVar_78229) {
	cppVar_78224 = SP;
	} else {
	BIT_VEC cppVar_78230;
	BIT_VEC cppVar_78231 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78232 = (cppVar_78231 << 3) | 1;
	cppVar_78232 = (cppVar_78232 & cppMask_un_5_);
	BIT_VEC cppVar_78233 = (0 << 5) | cppVar_78232;
	cppVar_78233 = (cppVar_78233 & cppMask_un_8_);
	bool cppVar_78235 = (cppVar_78233 == 130);
	if (cppVar_78235) {
	cppVar_78230 = DPL;
	} else {
	BIT_VEC cppVar_78236;
	BIT_VEC cppVar_78237 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78238 = (cppVar_78237 << 3) | 1;
	cppVar_78238 = (cppVar_78238 & cppMask_un_5_);
	BIT_VEC cppVar_78239 = (0 << 5) | cppVar_78238;
	cppVar_78239 = (cppVar_78239 & cppMask_un_8_);
	bool cppVar_78241 = (cppVar_78239 == 131);
	if (cppVar_78241) {
	cppVar_78236 = DPH;
	} else {
	BIT_VEC cppVar_78242;
	BIT_VEC cppVar_78243 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78244 = (cppVar_78243 << 3) | 1;
	cppVar_78244 = (cppVar_78244 & cppMask_un_5_);
	BIT_VEC cppVar_78245 = (0 << 5) | cppVar_78244;
	cppVar_78245 = (cppVar_78245 & cppMask_un_8_);
	bool cppVar_78247 = (cppVar_78245 == 135);
	if (cppVar_78247) {
	cppVar_78242 = PCON;
	} else {
	BIT_VEC cppVar_78248;
	BIT_VEC cppVar_78249 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78250 = (cppVar_78249 << 3) | 1;
	cppVar_78250 = (cppVar_78250 & cppMask_un_5_);
	BIT_VEC cppVar_78251 = (0 << 5) | cppVar_78250;
	cppVar_78251 = (cppVar_78251 & cppMask_un_8_);
	bool cppVar_78253 = (cppVar_78251 == 136);
	if (cppVar_78253) {
	cppVar_78248 = TCON;
	} else {
	BIT_VEC cppVar_78254;
	BIT_VEC cppVar_78255 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78256 = (cppVar_78255 << 3) | 1;
	cppVar_78256 = (cppVar_78256 & cppMask_un_5_);
	BIT_VEC cppVar_78257 = (0 << 5) | cppVar_78256;
	cppVar_78257 = (cppVar_78257 & cppMask_un_8_);
	bool cppVar_78259 = (cppVar_78257 == 137);
	if (cppVar_78259) {
	cppVar_78254 = TMOD;
	} else {
	BIT_VEC cppVar_78260;
	BIT_VEC cppVar_78261 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78262 = (cppVar_78261 << 3) | 1;
	cppVar_78262 = (cppVar_78262 & cppMask_un_5_);
	BIT_VEC cppVar_78263 = (0 << 5) | cppVar_78262;
	cppVar_78263 = (cppVar_78263 & cppMask_un_8_);
	bool cppVar_78265 = (cppVar_78263 == 138);
	if (cppVar_78265) {
	cppVar_78260 = TL0;
	} else {
	BIT_VEC cppVar_78266;
	BIT_VEC cppVar_78267 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78268 = (cppVar_78267 << 3) | 1;
	cppVar_78268 = (cppVar_78268 & cppMask_un_5_);
	BIT_VEC cppVar_78269 = (0 << 5) | cppVar_78268;
	cppVar_78269 = (cppVar_78269 & cppMask_un_8_);
	bool cppVar_78271 = (cppVar_78269 == 140);
	if (cppVar_78271) {
	cppVar_78266 = TH0;
	} else {
	BIT_VEC cppVar_78272;
	BIT_VEC cppVar_78273 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78274 = (cppVar_78273 << 3) | 1;
	cppVar_78274 = (cppVar_78274 & cppMask_un_5_);
	BIT_VEC cppVar_78275 = (0 << 5) | cppVar_78274;
	cppVar_78275 = (cppVar_78275 & cppMask_un_8_);
	bool cppVar_78277 = (cppVar_78275 == 139);
	if (cppVar_78277) {
	cppVar_78272 = TL1;
	} else {
	BIT_VEC cppVar_78278;
	BIT_VEC cppVar_78279 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78280 = (cppVar_78279 << 3) | 1;
	cppVar_78280 = (cppVar_78280 & cppMask_un_5_);
	BIT_VEC cppVar_78281 = (0 << 5) | cppVar_78280;
	cppVar_78281 = (cppVar_78281 & cppMask_un_8_);
	bool cppVar_78283 = (cppVar_78281 == 141);
	if (cppVar_78283) {
	cppVar_78278 = TH1;
	} else {
	BIT_VEC cppVar_78284;
	BIT_VEC cppVar_78285 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78286 = (cppVar_78285 << 3) | 1;
	cppVar_78286 = (cppVar_78286 & cppMask_un_5_);
	BIT_VEC cppVar_78287 = (0 << 5) | cppVar_78286;
	cppVar_78287 = (cppVar_78287 & cppMask_un_8_);
	bool cppVar_78289 = (cppVar_78287 == 144);
	if (cppVar_78289) {
	cppVar_78284 = P1;
	} else {
	BIT_VEC cppVar_78290;
	BIT_VEC cppVar_78291 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78292 = (cppVar_78291 << 3) | 1;
	cppVar_78292 = (cppVar_78292 & cppMask_un_5_);
	BIT_VEC cppVar_78293 = (0 << 5) | cppVar_78292;
	cppVar_78293 = (cppVar_78293 & cppMask_un_8_);
	bool cppVar_78295 = (cppVar_78293 == 152);
	if (cppVar_78295) {
	cppVar_78290 = SCON;
	} else {
	BIT_VEC cppVar_78296;
	BIT_VEC cppVar_78297 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78298 = (cppVar_78297 << 3) | 1;
	cppVar_78298 = (cppVar_78298 & cppMask_un_5_);
	BIT_VEC cppVar_78299 = (0 << 5) | cppVar_78298;
	cppVar_78299 = (cppVar_78299 & cppMask_un_8_);
	bool cppVar_78301 = (cppVar_78299 == 153);
	if (cppVar_78301) {
	cppVar_78296 = SBUF;
	} else {
	BIT_VEC cppVar_78302;
	BIT_VEC cppVar_78303 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78304 = (cppVar_78303 << 3) | 1;
	cppVar_78304 = (cppVar_78304 & cppMask_un_5_);
	BIT_VEC cppVar_78305 = (0 << 5) | cppVar_78304;
	cppVar_78305 = (cppVar_78305 & cppMask_un_8_);
	bool cppVar_78307 = (cppVar_78305 == 160);
	if (cppVar_78307) {
	cppVar_78302 = P2;
	} else {
	BIT_VEC cppVar_78308;
	BIT_VEC cppVar_78309 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78310 = (cppVar_78309 << 3) | 1;
	cppVar_78310 = (cppVar_78310 & cppMask_un_5_);
	BIT_VEC cppVar_78311 = (0 << 5) | cppVar_78310;
	cppVar_78311 = (cppVar_78311 & cppMask_un_8_);
	bool cppVar_78313 = (cppVar_78311 == 168);
	if (cppVar_78313) {
	cppVar_78308 = IE;
	} else {
	BIT_VEC cppVar_78314;
	BIT_VEC cppVar_78315 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78316 = (cppVar_78315 << 3) | 1;
	cppVar_78316 = (cppVar_78316 & cppMask_un_5_);
	BIT_VEC cppVar_78317 = (0 << 5) | cppVar_78316;
	cppVar_78317 = (cppVar_78317 & cppMask_un_8_);
	bool cppVar_78319 = (cppVar_78317 == 176);
	if (cppVar_78319) {
	cppVar_78314 = P3;
	} else {
	BIT_VEC cppVar_78320;
	BIT_VEC cppVar_78321 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78322 = (cppVar_78321 << 3) | 1;
	cppVar_78322 = (cppVar_78322 & cppMask_un_5_);
	BIT_VEC cppVar_78323 = (0 << 5) | cppVar_78322;
	cppVar_78323 = (cppVar_78323 & cppMask_un_8_);
	bool cppVar_78325 = (cppVar_78323 == 184);
	if (cppVar_78325) {
	cppVar_78320 = IP;
	} else {
	BIT_VEC cppVar_78326;
	BIT_VEC cppVar_78327 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78328 = (cppVar_78327 << 3) | 1;
	cppVar_78328 = (cppVar_78328 & cppMask_un_5_);
	BIT_VEC cppVar_78329 = (0 << 5) | cppVar_78328;
	cppVar_78329 = (cppVar_78329 & cppMask_un_8_);
	bool cppVar_78331 = (cppVar_78329 == 208);
	if (cppVar_78331) {
	cppVar_78326 = PSW;
	} else {
	BIT_VEC cppVar_78332;
	BIT_VEC cppVar_78333 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78334 = (cppVar_78333 << 3) | 1;
	cppVar_78334 = (cppVar_78334 & cppMask_un_5_);
	BIT_VEC cppVar_78335 = (0 << 5) | cppVar_78334;
	cppVar_78335 = (cppVar_78335 & cppMask_un_8_);
	bool cppVar_78337 = (cppVar_78335 == 224);
	if (cppVar_78337) {
	cppVar_78332 = ACC;
	} else {
	BIT_VEC cppVar_78338;
	BIT_VEC cppVar_78339 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78340 = (cppVar_78339 << 3) | 1;
	cppVar_78340 = (cppVar_78340 & cppMask_un_5_);
	BIT_VEC cppVar_78341 = (0 << 5) | cppVar_78340;
	cppVar_78341 = (cppVar_78341 & cppMask_un_8_);
	bool cppVar_78343 = (cppVar_78341 == 240);
	if (cppVar_78343) {
	cppVar_78338 = B;
	} else {
	cppVar_78338 = 0;
	}
	cppVar_78332 = cppVar_78338;
	}
	cppVar_78326 = cppVar_78332;
	}
	cppVar_78320 = cppVar_78326;
	}
	cppVar_78314 = cppVar_78320;
	}
	cppVar_78308 = cppVar_78314;
	}
	cppVar_78302 = cppVar_78308;
	}
	cppVar_78296 = cppVar_78302;
	}
	cppVar_78290 = cppVar_78296;
	}
	cppVar_78284 = cppVar_78290;
	}
	cppVar_78278 = cppVar_78284;
	}
	cppVar_78272 = cppVar_78278;
	}
	cppVar_78266 = cppVar_78272;
	}
	cppVar_78260 = cppVar_78266;
	}
	cppVar_78254 = cppVar_78260;
	}
	cppVar_78248 = cppVar_78254;
	}
	cppVar_78242 = cppVar_78248;
	}
	cppVar_78236 = cppVar_78242;
	}
	cppVar_78230 = cppVar_78236;
	}
	cppVar_78224 = cppVar_78230;
	}
	cppVar_78218 = cppVar_78224;
	}
	cppVar_78205 = cppVar_78218;
	}
	cppVar_78199 = cppVar_78205;
	} else {
	cppVar_78199 = TL0;
	}
	cppVar_78195 = cppVar_78199;
	} else {
	BIT_VEC cppVar_78345;
	BIT_VEC cppVar_78346 = ROM.rd(PC);
	bool cppVar_78348 = (cppVar_78346 == 136);
	if (cppVar_78348) {
	BIT_VEC cppVar_78349;
	BIT_VEC cppVar_78351 = PC + 1;
	cppVar_78351 = (cppVar_78351 & cppMask_un_16_);
	BIT_VEC cppVar_78352 = ROM.rd(cppVar_78351);
	bool cppVar_78354 = (cppVar_78352 == 138);
	if (cppVar_78354) {
	BIT_VEC cppVar_78355;
	BIT_VEC cppVar_78357 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78359 = (cppVar_78357 << 3) | 0;
	cppVar_78359 = (cppVar_78359 & cppMask_un_5_);
	BIT_VEC cppVar_78360 = (0 << 5) | cppVar_78359;
	cppVar_78360 = (cppVar_78360 & cppMask_un_8_);
	BIT_VEC cppVar_78361 = (cppVar_78360 >> 7) & cppMask_un_1_;
	bool cppVar_78363 = (cppVar_78361 == 0);
	if (cppVar_78363) {
	BIT_VEC cppVar_78364 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78365 = (cppVar_78364 << 3) | 0;
	cppVar_78365 = (cppVar_78365 & cppMask_un_5_);
	BIT_VEC cppVar_78366 = (0 << 5) | cppVar_78365;
	cppVar_78366 = (cppVar_78366 & cppMask_un_8_);
	BIT_VEC cppVar_78367 = IRAM.rd(cppVar_78366);
	cppVar_78355 = cppVar_78367;
	} else {
	BIT_VEC cppVar_78368;
	BIT_VEC cppVar_78369 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78370 = (cppVar_78369 << 3) | 0;
	cppVar_78370 = (cppVar_78370 & cppMask_un_5_);
	BIT_VEC cppVar_78371 = (0 << 5) | cppVar_78370;
	cppVar_78371 = (cppVar_78371 & cppMask_un_8_);
	bool cppVar_78373 = (cppVar_78371 == 128);
	if (cppVar_78373) {
	cppVar_78368 = P0;
	} else {
	BIT_VEC cppVar_78374;
	BIT_VEC cppVar_78375 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78376 = (cppVar_78375 << 3) | 0;
	cppVar_78376 = (cppVar_78376 & cppMask_un_5_);
	BIT_VEC cppVar_78377 = (0 << 5) | cppVar_78376;
	cppVar_78377 = (cppVar_78377 & cppMask_un_8_);
	bool cppVar_78379 = (cppVar_78377 == 129);
	if (cppVar_78379) {
	cppVar_78374 = SP;
	} else {
	BIT_VEC cppVar_78380;
	BIT_VEC cppVar_78381 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78382 = (cppVar_78381 << 3) | 0;
	cppVar_78382 = (cppVar_78382 & cppMask_un_5_);
	BIT_VEC cppVar_78383 = (0 << 5) | cppVar_78382;
	cppVar_78383 = (cppVar_78383 & cppMask_un_8_);
	bool cppVar_78385 = (cppVar_78383 == 130);
	if (cppVar_78385) {
	cppVar_78380 = DPL;
	} else {
	BIT_VEC cppVar_78386;
	BIT_VEC cppVar_78387 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78388 = (cppVar_78387 << 3) | 0;
	cppVar_78388 = (cppVar_78388 & cppMask_un_5_);
	BIT_VEC cppVar_78389 = (0 << 5) | cppVar_78388;
	cppVar_78389 = (cppVar_78389 & cppMask_un_8_);
	bool cppVar_78391 = (cppVar_78389 == 131);
	if (cppVar_78391) {
	cppVar_78386 = DPH;
	} else {
	BIT_VEC cppVar_78392;
	BIT_VEC cppVar_78393 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78394 = (cppVar_78393 << 3) | 0;
	cppVar_78394 = (cppVar_78394 & cppMask_un_5_);
	BIT_VEC cppVar_78395 = (0 << 5) | cppVar_78394;
	cppVar_78395 = (cppVar_78395 & cppMask_un_8_);
	bool cppVar_78397 = (cppVar_78395 == 135);
	if (cppVar_78397) {
	cppVar_78392 = PCON;
	} else {
	BIT_VEC cppVar_78398;
	BIT_VEC cppVar_78399 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78400 = (cppVar_78399 << 3) | 0;
	cppVar_78400 = (cppVar_78400 & cppMask_un_5_);
	BIT_VEC cppVar_78401 = (0 << 5) | cppVar_78400;
	cppVar_78401 = (cppVar_78401 & cppMask_un_8_);
	bool cppVar_78403 = (cppVar_78401 == 136);
	if (cppVar_78403) {
	cppVar_78398 = TCON;
	} else {
	BIT_VEC cppVar_78404;
	BIT_VEC cppVar_78405 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78406 = (cppVar_78405 << 3) | 0;
	cppVar_78406 = (cppVar_78406 & cppMask_un_5_);
	BIT_VEC cppVar_78407 = (0 << 5) | cppVar_78406;
	cppVar_78407 = (cppVar_78407 & cppMask_un_8_);
	bool cppVar_78409 = (cppVar_78407 == 137);
	if (cppVar_78409) {
	cppVar_78404 = TMOD;
	} else {
	BIT_VEC cppVar_78410;
	BIT_VEC cppVar_78411 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78412 = (cppVar_78411 << 3) | 0;
	cppVar_78412 = (cppVar_78412 & cppMask_un_5_);
	BIT_VEC cppVar_78413 = (0 << 5) | cppVar_78412;
	cppVar_78413 = (cppVar_78413 & cppMask_un_8_);
	bool cppVar_78415 = (cppVar_78413 == 138);
	if (cppVar_78415) {
	cppVar_78410 = TL0;
	} else {
	BIT_VEC cppVar_78416;
	BIT_VEC cppVar_78417 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78418 = (cppVar_78417 << 3) | 0;
	cppVar_78418 = (cppVar_78418 & cppMask_un_5_);
	BIT_VEC cppVar_78419 = (0 << 5) | cppVar_78418;
	cppVar_78419 = (cppVar_78419 & cppMask_un_8_);
	bool cppVar_78421 = (cppVar_78419 == 140);
	if (cppVar_78421) {
	cppVar_78416 = TH0;
	} else {
	BIT_VEC cppVar_78422;
	BIT_VEC cppVar_78423 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78424 = (cppVar_78423 << 3) | 0;
	cppVar_78424 = (cppVar_78424 & cppMask_un_5_);
	BIT_VEC cppVar_78425 = (0 << 5) | cppVar_78424;
	cppVar_78425 = (cppVar_78425 & cppMask_un_8_);
	bool cppVar_78427 = (cppVar_78425 == 139);
	if (cppVar_78427) {
	cppVar_78422 = TL1;
	} else {
	BIT_VEC cppVar_78428;
	BIT_VEC cppVar_78429 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78430 = (cppVar_78429 << 3) | 0;
	cppVar_78430 = (cppVar_78430 & cppMask_un_5_);
	BIT_VEC cppVar_78431 = (0 << 5) | cppVar_78430;
	cppVar_78431 = (cppVar_78431 & cppMask_un_8_);
	bool cppVar_78433 = (cppVar_78431 == 141);
	if (cppVar_78433) {
	cppVar_78428 = TH1;
	} else {
	BIT_VEC cppVar_78434;
	BIT_VEC cppVar_78435 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78436 = (cppVar_78435 << 3) | 0;
	cppVar_78436 = (cppVar_78436 & cppMask_un_5_);
	BIT_VEC cppVar_78437 = (0 << 5) | cppVar_78436;
	cppVar_78437 = (cppVar_78437 & cppMask_un_8_);
	bool cppVar_78439 = (cppVar_78437 == 144);
	if (cppVar_78439) {
	cppVar_78434 = P1;
	} else {
	BIT_VEC cppVar_78440;
	BIT_VEC cppVar_78441 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78442 = (cppVar_78441 << 3) | 0;
	cppVar_78442 = (cppVar_78442 & cppMask_un_5_);
	BIT_VEC cppVar_78443 = (0 << 5) | cppVar_78442;
	cppVar_78443 = (cppVar_78443 & cppMask_un_8_);
	bool cppVar_78445 = (cppVar_78443 == 152);
	if (cppVar_78445) {
	cppVar_78440 = SCON;
	} else {
	BIT_VEC cppVar_78446;
	BIT_VEC cppVar_78447 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78448 = (cppVar_78447 << 3) | 0;
	cppVar_78448 = (cppVar_78448 & cppMask_un_5_);
	BIT_VEC cppVar_78449 = (0 << 5) | cppVar_78448;
	cppVar_78449 = (cppVar_78449 & cppMask_un_8_);
	bool cppVar_78451 = (cppVar_78449 == 153);
	if (cppVar_78451) {
	cppVar_78446 = SBUF;
	} else {
	BIT_VEC cppVar_78452;
	BIT_VEC cppVar_78453 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78454 = (cppVar_78453 << 3) | 0;
	cppVar_78454 = (cppVar_78454 & cppMask_un_5_);
	BIT_VEC cppVar_78455 = (0 << 5) | cppVar_78454;
	cppVar_78455 = (cppVar_78455 & cppMask_un_8_);
	bool cppVar_78457 = (cppVar_78455 == 160);
	if (cppVar_78457) {
	cppVar_78452 = P2;
	} else {
	BIT_VEC cppVar_78458;
	BIT_VEC cppVar_78459 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78460 = (cppVar_78459 << 3) | 0;
	cppVar_78460 = (cppVar_78460 & cppMask_un_5_);
	BIT_VEC cppVar_78461 = (0 << 5) | cppVar_78460;
	cppVar_78461 = (cppVar_78461 & cppMask_un_8_);
	bool cppVar_78463 = (cppVar_78461 == 168);
	if (cppVar_78463) {
	cppVar_78458 = IE;
	} else {
	BIT_VEC cppVar_78464;
	BIT_VEC cppVar_78465 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78466 = (cppVar_78465 << 3) | 0;
	cppVar_78466 = (cppVar_78466 & cppMask_un_5_);
	BIT_VEC cppVar_78467 = (0 << 5) | cppVar_78466;
	cppVar_78467 = (cppVar_78467 & cppMask_un_8_);
	bool cppVar_78469 = (cppVar_78467 == 176);
	if (cppVar_78469) {
	cppVar_78464 = P3;
	} else {
	BIT_VEC cppVar_78470;
	BIT_VEC cppVar_78471 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78472 = (cppVar_78471 << 3) | 0;
	cppVar_78472 = (cppVar_78472 & cppMask_un_5_);
	BIT_VEC cppVar_78473 = (0 << 5) | cppVar_78472;
	cppVar_78473 = (cppVar_78473 & cppMask_un_8_);
	bool cppVar_78475 = (cppVar_78473 == 184);
	if (cppVar_78475) {
	cppVar_78470 = IP;
	} else {
	BIT_VEC cppVar_78476;
	BIT_VEC cppVar_78477 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78478 = (cppVar_78477 << 3) | 0;
	cppVar_78478 = (cppVar_78478 & cppMask_un_5_);
	BIT_VEC cppVar_78479 = (0 << 5) | cppVar_78478;
	cppVar_78479 = (cppVar_78479 & cppMask_un_8_);
	bool cppVar_78481 = (cppVar_78479 == 208);
	if (cppVar_78481) {
	cppVar_78476 = PSW;
	} else {
	BIT_VEC cppVar_78482;
	BIT_VEC cppVar_78483 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78484 = (cppVar_78483 << 3) | 0;
	cppVar_78484 = (cppVar_78484 & cppMask_un_5_);
	BIT_VEC cppVar_78485 = (0 << 5) | cppVar_78484;
	cppVar_78485 = (cppVar_78485 & cppMask_un_8_);
	bool cppVar_78487 = (cppVar_78485 == 224);
	if (cppVar_78487) {
	cppVar_78482 = ACC;
	} else {
	BIT_VEC cppVar_78488;
	BIT_VEC cppVar_78489 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78490 = (cppVar_78489 << 3) | 0;
	cppVar_78490 = (cppVar_78490 & cppMask_un_5_);
	BIT_VEC cppVar_78491 = (0 << 5) | cppVar_78490;
	cppVar_78491 = (cppVar_78491 & cppMask_un_8_);
	bool cppVar_78493 = (cppVar_78491 == 240);
	if (cppVar_78493) {
	cppVar_78488 = B;
	} else {
	cppVar_78488 = 0;
	}
	cppVar_78482 = cppVar_78488;
	}
	cppVar_78476 = cppVar_78482;
	}
	cppVar_78470 = cppVar_78476;
	}
	cppVar_78464 = cppVar_78470;
	}
	cppVar_78458 = cppVar_78464;
	}
	cppVar_78452 = cppVar_78458;
	}
	cppVar_78446 = cppVar_78452;
	}
	cppVar_78440 = cppVar_78446;
	}
	cppVar_78434 = cppVar_78440;
	}
	cppVar_78428 = cppVar_78434;
	}
	cppVar_78422 = cppVar_78428;
	}
	cppVar_78416 = cppVar_78422;
	}
	cppVar_78410 = cppVar_78416;
	}
	cppVar_78404 = cppVar_78410;
	}
	cppVar_78398 = cppVar_78404;
	}
	cppVar_78392 = cppVar_78398;
	}
	cppVar_78386 = cppVar_78392;
	}
	cppVar_78380 = cppVar_78386;
	}
	cppVar_78374 = cppVar_78380;
	}
	cppVar_78368 = cppVar_78374;
	}
	cppVar_78355 = cppVar_78368;
	}
	cppVar_78349 = cppVar_78355;
	} else {
	cppVar_78349 = TL0;
	}
	cppVar_78345 = cppVar_78349;
	} else {
	BIT_VEC cppVar_78495;
	BIT_VEC cppVar_78496 = ROM.rd(PC);
	bool cppVar_78498 = (cppVar_78496 == 135);
	if (cppVar_78498) {
	BIT_VEC cppVar_78499;
	BIT_VEC cppVar_78501 = PC + 1;
	cppVar_78501 = (cppVar_78501 & cppMask_un_16_);
	BIT_VEC cppVar_78502 = ROM.rd(cppVar_78501);
	bool cppVar_78504 = (cppVar_78502 == 138);
	if (cppVar_78504) {
	BIT_VEC cppVar_78506 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78508 = (cppVar_78506 << 3) | 1;
	cppVar_78508 = (cppVar_78508 & cppMask_un_5_);
	BIT_VEC cppVar_78509 = (0 << 5) | cppVar_78508;
	cppVar_78509 = (cppVar_78509 & cppMask_un_8_);
	BIT_VEC cppVar_78510 = IRAM.rd(cppVar_78509);
	BIT_VEC cppVar_78511 = IRAM.rd(cppVar_78510);
	cppVar_78499 = cppVar_78511;
	} else {
	cppVar_78499 = TL0;
	}
	cppVar_78495 = cppVar_78499;
	} else {
	BIT_VEC cppVar_78512;
	BIT_VEC cppVar_78513 = ROM.rd(PC);
	bool cppVar_78515 = (cppVar_78513 == 134);
	if (cppVar_78515) {
	BIT_VEC cppVar_78516;
	BIT_VEC cppVar_78518 = PC + 1;
	cppVar_78518 = (cppVar_78518 & cppMask_un_16_);
	BIT_VEC cppVar_78519 = ROM.rd(cppVar_78518);
	bool cppVar_78521 = (cppVar_78519 == 138);
	if (cppVar_78521) {
	BIT_VEC cppVar_78523 = (PSW >> 3) & cppMask_un_2_;
	BIT_VEC cppVar_78525 = (cppVar_78523 << 3) | 0;
	cppVar_78525 = (cppVar_78525 & cppMask_un_5_);
	BIT_VEC cppVar_78526 = (0 << 5) | cppVar_78525;
	cppVar_78526 = (cppVar_78526 & cppMask_un_8_);
	BIT_VEC cppVar_78527 = IRAM.rd(cppVar_78526);
	BIT_VEC cppVar_78528 = IRAM.rd(cppVar_78527);
	cppVar_78516 = cppVar_78528;
	} else {
	cppVar_78516 = TL0;
	}
	cppVar_78512 = cppVar_78516;
	} else {
	BIT_VEC cppVar_78529;
	BIT_VEC cppVar_78530 = ROM.rd(PC);
	bool cppVar_78532 = (cppVar_78530 == 133);
	if (cppVar_78532) {
	BIT_VEC cppVar_78533;
	BIT_VEC cppVar_78535 = PC + 2;
	cppVar_78535 = (cppVar_78535 & cppMask_un_16_);
	BIT_VEC cppVar_78536 = ROM.rd(cppVar_78535);
	bool cppVar_78538 = (cppVar_78536 == 138);
	if (cppVar_78538) {
	BIT_VEC cppVar_78539;
	BIT_VEC cppVar_78541 = PC + 1;
	cppVar_78541 = (cppVar_78541 & cppMask_un_16_);
	BIT_VEC cppVar_78542 = ROM.rd(cppVar_78541);
	BIT_VEC cppVar_78543 = (cppVar_78542 >> 7) & cppMask_un_1_;
	bool cppVar_78545 = (cppVar_78543 == 0);
	if (cppVar_78545) {
	BIT_VEC cppVar_78546 = PC + 1;
	cppVar_78546 = (cppVar_78546 & cppMask_un_16_);
	BIT_VEC cppVar_78547 = ROM.rd(cppVar_78546);
	BIT_VEC cppVar_78548 = IRAM.rd(cppVar_78547);
	cppVar_78539 = cppVar_78548;
	} else {
	BIT_VEC cppVar_78549;
	BIT_VEC cppVar_78550 = PC + 1;
	cppVar_78550 = (cppVar_78550 & cppMask_un_16_);
	BIT_VEC cppVar_78551 = ROM.rd(cppVar_78550);
	bool cppVar_78553 = (cppVar_78551 == 128);
	if (cppVar_78553) {
	cppVar_78549 = P0;
	} else {
	BIT_VEC cppVar_78554;
	BIT_VEC cppVar_78555 = PC + 1;
	cppVar_78555 = (cppVar_78555 & cppMask_un_16_);
	BIT_VEC cppVar_78556 = ROM.rd(cppVar_78555);
	bool cppVar_78558 = (cppVar_78556 == 129);
	if (cppVar_78558) {
	cppVar_78554 = SP;
	} else {
	BIT_VEC cppVar_78559;
	BIT_VEC cppVar_78560 = PC + 1;
	cppVar_78560 = (cppVar_78560 & cppMask_un_16_);
	BIT_VEC cppVar_78561 = ROM.rd(cppVar_78560);
	bool cppVar_78563 = (cppVar_78561 == 130);
	if (cppVar_78563) {
	cppVar_78559 = DPL;
	} else {
	BIT_VEC cppVar_78564;
	BIT_VEC cppVar_78565 = PC + 1;
	cppVar_78565 = (cppVar_78565 & cppMask_un_16_);
	BIT_VEC cppVar_78566 = ROM.rd(cppVar_78565);
	bool cppVar_78568 = (cppVar_78566 == 131);
	if (cppVar_78568) {
	cppVar_78564 = DPH;
	} else {
	BIT_VEC cppVar_78569;
	BIT_VEC cppVar_78570 = PC + 1;
	cppVar_78570 = (cppVar_78570 & cppMask_un_16_);
	BIT_VEC cppVar_78571 = ROM.rd(cppVar_78570);
	bool cppVar_78573 = (cppVar_78571 == 135);
	if (cppVar_78573) {
	cppVar_78569 = PCON;
	} else {
	BIT_VEC cppVar_78574;
	BIT_VEC cppVar_78575 = PC + 1;
	cppVar_78575 = (cppVar_78575 & cppMask_un_16_);
	BIT_VEC cppVar_78576 = ROM.rd(cppVar_78575);
	bool cppVar_78578 = (cppVar_78576 == 136);
	if (cppVar_78578) {
	cppVar_78574 = TCON;
	} else {
	BIT_VEC cppVar_78579;
	BIT_VEC cppVar_78580 = PC + 1;
	cppVar_78580 = (cppVar_78580 & cppMask_un_16_);
	BIT_VEC cppVar_78581 = ROM.rd(cppVar_78580);
	bool cppVar_78583 = (cppVar_78581 == 137);
	if (cppVar_78583) {
	cppVar_78579 = TMOD;
	} else {
	BIT_VEC cppVar_78584;
	BIT_VEC cppVar_78585 = PC + 1;
	cppVar_78585 = (cppVar_78585 & cppMask_un_16_);
	BIT_VEC cppVar_78586 = ROM.rd(cppVar_78585);
	bool cppVar_78588 = (cppVar_78586 == 138);
	if (cppVar_78588) {
	cppVar_78584 = TL0;
	} else {
	BIT_VEC cppVar_78589;
	BIT_VEC cppVar_78590 = PC + 1;
	cppVar_78590 = (cppVar_78590 & cppMask_un_16_);
	BIT_VEC cppVar_78591 = ROM.rd(cppVar_78590);
	bool cppVar_78593 = (cppVar_78591 == 140);
	if (cppVar_78593) {
	cppVar_78589 = TH0;
	} else {
	BIT_VEC cppVar_78594;
	BIT_VEC cppVar_78595 = PC + 1;
	cppVar_78595 = (cppVar_78595 & cppMask_un_16_);
	BIT_VEC cppVar_78596 = ROM.rd(cppVar_78595);
	bool cppVar_78598 = (cppVar_78596 == 139);
	if (cppVar_78598) {
	cppVar_78594 = TL1;
	} else {
	BIT_VEC cppVar_78599;
	BIT_VEC cppVar_78600 = PC + 1;
	cppVar_78600 = (cppVar_78600 & cppMask_un_16_);
	BIT_VEC cppVar_78601 = ROM.rd(cppVar_78600);
	bool cppVar_78603 = (cppVar_78601 == 141);
	if (cppVar_78603) {
	cppVar_78599 = TH1;
	} else {
	BIT_VEC cppVar_78604;
	BIT_VEC cppVar_78605 = PC + 1;
	cppVar_78605 = (cppVar_78605 & cppMask_un_16_);
	BIT_VEC cppVar_78606 = ROM.rd(cppVar_78605);
	bool cppVar_78608 = (cppVar_78606 == 144);
	if (cppVar_78608) {
	cppVar_78604 = P1;
	} else {
	BIT_VEC cppVar_78609;
	BIT_VEC cppVar_78610 = PC + 1;
	cppVar_78610 = (cppVar_78610 & cppMask_un_16_);
	BIT_VEC cppVar_78611 = ROM.rd(cppVar_78610);
	bool cppVar_78613 = (cppVar_78611 == 152);
	if (cppVar_78613) {
	cppVar_78609 = SCON;
	} else {
	BIT_VEC cppVar_78614;
	BIT_VEC cppVar_78615 = PC + 1;
	cppVar_78615 = (cppVar_78615 & cppMask_un_16_);
	BIT_VEC cppVar_78616 = ROM.rd(cppVar_78615);
	bool cppVar_78618 = (cppVar_78616 == 153);
	if (cppVar_78618) {
	cppVar_78614 = SBUF;
	} else {
	BIT_VEC cppVar_78619;
	BIT_VEC cppVar_78620 = PC + 1;
	cppVar_78620 = (cppVar_78620 & cppMask_un_16_);
	BIT_VEC cppVar_78621 = ROM.rd(cppVar_78620);
	bool cppVar_78623 = (cppVar_78621 == 160);
	if (cppVar_78623) {
	cppVar_78619 = P2;
	} else {
	BIT_VEC cppVar_78624;
	BIT_VEC cppVar_78625 = PC + 1;
	cppVar_78625 = (cppVar_78625 & cppMask_un_16_);
	BIT_VEC cppVar_78626 = ROM.rd(cppVar_78625);
	bool cppVar_78628 = (cppVar_78626 == 168);
	if (cppVar_78628) {
	cppVar_78624 = IE;
	} else {
	BIT_VEC cppVar_78629;
	BIT_VEC cppVar_78630 = PC + 1;
	cppVar_78630 = (cppVar_78630 & cppMask_un_16_);
	BIT_VEC cppVar_78631 = ROM.rd(cppVar_78630);
	bool cppVar_78633 = (cppVar_78631 == 176);
	if (cppVar_78633) {
	cppVar_78629 = P3;
	} else {
	BIT_VEC cppVar_78634;
	BIT_VEC cppVar_78635 = PC + 1;
	cppVar_78635 = (cppVar_78635 & cppMask_un_16_);
	BIT_VEC cppVar_78636 = ROM.rd(cppVar_78635);
	bool cppVar_78638 = (cppVar_78636 == 184);
	if (cppVar_78638) {
	cppVar_78634 = IP;
	} else {
	BIT_VEC cppVar_78639;
	BIT_VEC cppVar_78640 = PC + 1;
	cppVar_78640 = (cppVar_78640 & cppMask_un_16_);
	BIT_VEC cppVar_78641 = ROM.rd(cppVar_78640);
	bool cppVar_78643 = (cppVar_78641 == 208);
	if (cppVar_78643) {
	cppVar_78639 = PSW;
	} else {
	BIT_VEC cppVar_78644;
	BIT_VEC cppVar_78645 = PC + 1;
	cppVar_78645 = (cppVar_78645 & cppMask_un_16_);
	BIT_VEC cppVar_78646 = ROM.rd(cppVar_78645);
	bool cppVar_78648 = (cppVar_78646 == 224);
	if (cppVar_78648) {
	cppVar_78644 = ACC;
	} else {
	BIT_VEC cppVar_78649;
	BIT_VEC cppVar_78650 = PC + 1;
	cppVar_78650 = (cppVar_78650 & cppMask_un_16_);
	BIT_VEC cppVar_78651 = ROM.rd(cppVar_78650);
	bool cppVar_78653 = (cppVar_78651 == 240);
	if (cppVar_78653) {
	cppVar_78649 = B;
	} else {
	cppVar_78649 = 0;
	}
	cppVar_78644 = cppVar_78649;
	}
	cppVar_78639 = cppVar_78644;
	}
	cppVar_78634 = cppVar_78639;
	}
	cppVar_78629 = cppVar_78634;
	}
	cppVar_78624 = cppVar_78629;
	}
	cppVar_78619 = cppVar_78624;
	}
	cppVar_78614 = cppVar_78619;
	}
	cppVar_78609 = cppVar_78614;
	}
	cppVar_78604 = cppVar_78609;
	}
	cppVar_78599 = cppVar_78604;
	}
	cppVar_78594 = cppVar_78599;
	}
	cppVar_78589 = cppVar_78594;
	}
	cppVar_78584 = cppVar_78589;
	}
	cppVar_78579 = cppVar_78584;
	}
	cppVar_78574 = cppVar_78579;
	}
	cppVar_78569 = cppVar_78574;
	}
	cppVar_78564 = cppVar_78569;
	}
	cppVar_78559 = cppVar_78564;
	}
	cppVar_78554 = cppVar_78559;
	}
	cppVar_78549 = cppVar_78554;
	}
	cppVar_78539 = cppVar_78549;
	}
	cppVar_78533 = cppVar_78539;
	} else {
	cppVar_78533 = TL0;
	}
	cppVar_78529 = cppVar_78533;
	} else {
	BIT_VEC cppVar_78655;
	BIT_VEC cppVar_78656 = ROM.rd(PC);
	bool cppVar_78658 = (cppVar_78656 == 117);
	if (cppVar_78658) {
	BIT_VEC cppVar_78659;
	BIT_VEC cppVar_78661 = PC + 1;
	cppVar_78661 = (cppVar_78661 & cppMask_un_16_);
	BIT_VEC cppVar_78662 = ROM.rd(cppVar_78661);
	bool cppVar_78664 = (cppVar_78662 == 138);
	if (cppVar_78664) {
	BIT_VEC cppVar_78666 = PC + 2;
	cppVar_78666 = (cppVar_78666 & cppMask_un_16_);
	BIT_VEC cppVar_78667 = ROM.rd(cppVar_78666);
	cppVar_78659 = cppVar_78667;
	} else {
	cppVar_78659 = TL0;
	}
	cppVar_78655 = cppVar_78659;
	} else {
	BIT_VEC cppVar_78668;
	BIT_VEC cppVar_78669 = ROM.rd(PC);
	bool cppVar_78671 = (cppVar_78669 == 99);
	if (cppVar_78671) {
	BIT_VEC cppVar_78672;
	BIT_VEC cppVar_78674 = PC + 1;
	cppVar_78674 = (cppVar_78674 & cppMask_un_16_);
	BIT_VEC cppVar_78675 = ROM.rd(cppVar_78674);
	bool cppVar_78677 = (cppVar_78675 == 138);
	if (cppVar_78677) {
	BIT_VEC cppVar_78678;
	BIT_VEC cppVar_78679 = PC + 1;
	cppVar_78679 = (cppVar_78679 & cppMask_un_16_);
	BIT_VEC cppVar_78680 = ROM.rd(cppVar_78679);
	BIT_VEC cppVar_78681 = (cppVar_78680 >> 7) & cppMask_un_1_;
	bool cppVar_78683 = (cppVar_78681 == 0);
	if (cppVar_78683) {
	BIT_VEC cppVar_78684 = PC + 1;
	cppVar_78684 = (cppVar_78684 & cppMask_un_16_);
	BIT_VEC cppVar_78685 = ROM.rd(cppVar_78684);
	BIT_VEC cppVar_78686 = IRAM.rd(cppVar_78685);
	cppVar_78678 = cppVar_78686;
	} else {
	BIT_VEC cppVar_78687;
	BIT_VEC cppVar_78688 = PC + 1;
	cppVar_78688 = (cppVar_78688 & cppMask_un_16_);
	BIT_VEC cppVar_78689 = ROM.rd(cppVar_78688);
	bool cppVar_78691 = (cppVar_78689 == 128);
	if (cppVar_78691) {
	cppVar_78687 = P0;
	} else {
	BIT_VEC cppVar_78692;
	BIT_VEC cppVar_78693 = PC + 1;
	cppVar_78693 = (cppVar_78693 & cppMask_un_16_);
	BIT_VEC cppVar_78694 = ROM.rd(cppVar_78693);
	bool cppVar_78696 = (cppVar_78694 == 129);
	if (cppVar_78696) {
	cppVar_78692 = SP;
	} else {
	BIT_VEC cppVar_78697;
	BIT_VEC cppVar_78698 = PC + 1;
	cppVar_78698 = (cppVar_78698 & cppMask_un_16_);
	BIT_VEC cppVar_78699 = ROM.rd(cppVar_78698);
	bool cppVar_78701 = (cppVar_78699 == 130);
	if (cppVar_78701) {
	cppVar_78697 = DPL;
	} else {
	BIT_VEC cppVar_78702;
	BIT_VEC cppVar_78703 = PC + 1;
	cppVar_78703 = (cppVar_78703 & cppMask_un_16_);
	BIT_VEC cppVar_78704 = ROM.rd(cppVar_78703);
	bool cppVar_78706 = (cppVar_78704 == 131);
	if (cppVar_78706) {
	cppVar_78702 = DPH;
	} else {
	BIT_VEC cppVar_78707;
	BIT_VEC cppVar_78708 = PC + 1;
	cppVar_78708 = (cppVar_78708 & cppMask_un_16_);
	BIT_VEC cppVar_78709 = ROM.rd(cppVar_78708);
	bool cppVar_78711 = (cppVar_78709 == 135);
	if (cppVar_78711) {
	cppVar_78707 = PCON;
	} else {
	BIT_VEC cppVar_78712;
	BIT_VEC cppVar_78713 = PC + 1;
	cppVar_78713 = (cppVar_78713 & cppMask_un_16_);
	BIT_VEC cppVar_78714 = ROM.rd(cppVar_78713);
	bool cppVar_78716 = (cppVar_78714 == 136);
	if (cppVar_78716) {
	cppVar_78712 = TCON;
	} else {
	BIT_VEC cppVar_78717;
	BIT_VEC cppVar_78718 = PC + 1;
	cppVar_78718 = (cppVar_78718 & cppMask_un_16_);
	BIT_VEC cppVar_78719 = ROM.rd(cppVar_78718);
	bool cppVar_78721 = (cppVar_78719 == 137);
	if (cppVar_78721) {
	cppVar_78717 = TMOD;
	} else {
	BIT_VEC cppVar_78722;
	BIT_VEC cppVar_78723 = PC + 1;
	cppVar_78723 = (cppVar_78723 & cppMask_un_16_);
	BIT_VEC cppVar_78724 = ROM.rd(cppVar_78723);
	bool cppVar_78726 = (cppVar_78724 == 138);
	if (cppVar_78726) {
	cppVar_78722 = TL0;
	} else {
	BIT_VEC cppVar_78727;
	BIT_VEC cppVar_78728 = PC + 1;
	cppVar_78728 = (cppVar_78728 & cppMask_un_16_);
	BIT_VEC cppVar_78729 = ROM.rd(cppVar_78728);
	bool cppVar_78731 = (cppVar_78729 == 140);
	if (cppVar_78731) {
	cppVar_78727 = TH0;
	} else {
	BIT_VEC cppVar_78732;
	BIT_VEC cppVar_78733 = PC + 1;
	cppVar_78733 = (cppVar_78733 & cppMask_un_16_);
	BIT_VEC cppVar_78734 = ROM.rd(cppVar_78733);
	bool cppVar_78736 = (cppVar_78734 == 139);
	if (cppVar_78736) {
	cppVar_78732 = TL1;
	} else {
	BIT_VEC cppVar_78737;
	BIT_VEC cppVar_78738 = PC + 1;
	cppVar_78738 = (cppVar_78738 & cppMask_un_16_);
	BIT_VEC cppVar_78739 = ROM.rd(cppVar_78738);
	bool cppVar_78741 = (cppVar_78739 == 141);
	if (cppVar_78741) {
	cppVar_78737 = TH1;
	} else {
	BIT_VEC cppVar_78742;
	BIT_VEC cppVar_78743 = PC + 1;
	cppVar_78743 = (cppVar_78743 & cppMask_un_16_);
	BIT_VEC cppVar_78744 = ROM.rd(cppVar_78743);
	bool cppVar_78746 = (cppVar_78744 == 144);
	if (cppVar_78746) {
	cppVar_78742 = P1;
	} else {
	BIT_VEC cppVar_78747;
	BIT_VEC cppVar_78748 = PC + 1;
	cppVar_78748 = (cppVar_78748 & cppMask_un_16_);
	BIT_VEC cppVar_78749 = ROM.rd(cppVar_78748);
	bool cppVar_78751 = (cppVar_78749 == 152);
	if (cppVar_78751) {
	cppVar_78747 = SCON;
	} else {
	BIT_VEC cppVar_78752;
	BIT_VEC cppVar_78753 = PC + 1;
	cppVar_78753 = (cppVar_78753 & cppMask_un_16_);
	BIT_VEC cppVar_78754 = ROM.rd(cppVar_78753);
	bool cppVar_78756 = (cppVar_78754 == 153);
	if (cppVar_78756) {
	cppVar_78752 = SBUF;
	} else {
	BIT_VEC cppVar_78757;
	BIT_VEC cppVar_78758 = PC + 1;
	cppVar_78758 = (cppVar_78758 & cppMask_un_16_);
	BIT_VEC cppVar_78759 = ROM.rd(cppVar_78758);
	bool cppVar_78761 = (cppVar_78759 == 160);
	if (cppVar_78761) {
	cppVar_78757 = P2;
	} else {
	BIT_VEC cppVar_78762;
	BIT_VEC cppVar_78763 = PC + 1;
	cppVar_78763 = (cppVar_78763 & cppMask_un_16_);
	BIT_VEC cppVar_78764 = ROM.rd(cppVar_78763);
	bool cppVar_78766 = (cppVar_78764 == 168);
	if (cppVar_78766) {
	cppVar_78762 = IE;
	} else {
	BIT_VEC cppVar_78767;
	BIT_VEC cppVar_78768 = PC + 1;
	cppVar_78768 = (cppVar_78768 & cppMask_un_16_);
	BIT_VEC cppVar_78769 = ROM.rd(cppVar_78768);
	bool cppVar_78771 = (cppVar_78769 == 176);
	if (cppVar_78771) {
	cppVar_78767 = P3;
	} else {
	BIT_VEC cppVar_78772;
	BIT_VEC cppVar_78773 = PC + 1;
	cppVar_78773 = (cppVar_78773 & cppMask_un_16_);
	BIT_VEC cppVar_78774 = ROM.rd(cppVar_78773);
	bool cppVar_78776 = (cppVar_78774 == 184);
	if (cppVar_78776) {
	cppVar_78772 = IP;
	} else {
	BIT_VEC cppVar_78777;
	BIT_VEC cppVar_78778 = PC + 1;
	cppVar_78778 = (cppVar_78778 & cppMask_un_16_);
	BIT_VEC cppVar_78779 = ROM.rd(cppVar_78778);
	bool cppVar_78781 = (cppVar_78779 == 208);
	if (cppVar_78781) {
	cppVar_78777 = PSW;
	} else {
	BIT_VEC cppVar_78782;
	BIT_VEC cppVar_78783 = PC + 1;
	cppVar_78783 = (cppVar_78783 & cppMask_un_16_);
	BIT_VEC cppVar_78784 = ROM.rd(cppVar_78783);
	bool cppVar_78786 = (cppVar_78784 == 224);
	if (cppVar_78786) {
	cppVar_78782 = ACC;
	} else {
	BIT_VEC cppVar_78787;
	BIT_VEC cppVar_78788 = PC + 1;
	cppVar_78788 = (cppVar_78788 & cppMask_un_16_);
	BIT_VEC cppVar_78789 = ROM.rd(cppVar_78788);
	bool cppVar_78791 = (cppVar_78789 == 240);
	if (cppVar_78791) {
	cppVar_78787 = B;
	} else {
	cppVar_78787 = 0;
	}
	cppVar_78782 = cppVar_78787;
	}
	cppVar_78777 = cppVar_78782;
	}
	cppVar_78772 = cppVar_78777;
	}
	cppVar_78767 = cppVar_78772;
	}
	cppVar_78762 = cppVar_78767;
	}
	cppVar_78757 = cppVar_78762;
	}
	cppVar_78752 = cppVar_78757;
	}
	cppVar_78747 = cppVar_78752;
	}
	cppVar_78742 = cppVar_78747;
	}
	cppVar_78737 = cppVar_78742;
	}
	cppVar_78732 = cppVar_78737;
	}
	cppVar_78727 = cppVar_78732;
	}
	cppVar_78722 = cppVar_78727;
	}
	cppVar_78717 = cppVar_78722;
	}
	cppVar_78712 = cppVar_78717;
	}
	cppVar_78707 = cppVar_78712;
	}
	cppVar_78702 = cppVar_78707;
	}
	cppVar_78697 = cppVar_78702;
	}
	cppVar_78692 = cppVar_78697;
	}
	cppVar_78687 = cppVar_78692;
	}
	cppVar_78678 = cppVar_78687;
	}
	BIT_VEC cppVar_78794 = PC + 2;
	cppVar_78794 = (cppVar_78794 & cppMask_un_16_);
	BIT_VEC cppVar_78795 = ROM.rd(cppVar_78794);
	BIT_VEC cppVar_78796 = cppVar_78678 ^ cppVar_78795;
	cppVar_78672 = cppVar_78796;
	} else {
	cppVar_78672 = TL0;
	}
	cppVar_78668 = cppVar_78672;
	} else {
	BIT_VEC cppVar_78797;
	BIT_VEC cppVar_78798 = ROM.rd(PC);
	bool cppVar_78800 = (cppVar_78798 == 98);
	if (cppVar_78800) {
	BIT_VEC cppVar_78801;
	BIT_VEC cppVar_78803 = PC + 1;
	cppVar_78803 = (cppVar_78803 & cppMask_un_16_);
	BIT_VEC cppVar_78804 = ROM.rd(cppVar_78803);
	bool cppVar_78806 = (cppVar_78804 == 138);
	if (cppVar_78806) {
	BIT_VEC cppVar_78807;
	BIT_VEC cppVar_78808 = PC + 1;
	cppVar_78808 = (cppVar_78808 & cppMask_un_16_);
	BIT_VEC cppVar_78809 = ROM.rd(cppVar_78808);
	BIT_VEC cppVar_78810 = (cppVar_78809 >> 7) & cppMask_un_1_;
	bool cppVar_78812 = (cppVar_78810 == 0);
	if (cppVar_78812) {
	BIT_VEC cppVar_78813 = PC + 1;
	cppVar_78813 = (cppVar_78813 & cppMask_un_16_);
	BIT_VEC cppVar_78814 = ROM.rd(cppVar_78813);
	BIT_VEC cppVar_78815 = IRAM.rd(cppVar_78814);
	cppVar_78807 = cppVar_78815;
	} else {
	BIT_VEC cppVar_78816;
	BIT_VEC cppVar_78817 = PC + 1;
	cppVar_78817 = (cppVar_78817 & cppMask_un_16_);
	BIT_VEC cppVar_78818 = ROM.rd(cppVar_78817);
	bool cppVar_78820 = (cppVar_78818 == 128);
	if (cppVar_78820) {
	cppVar_78816 = P0;
	} else {
	BIT_VEC cppVar_78821;
	BIT_VEC cppVar_78822 = PC + 1;
	cppVar_78822 = (cppVar_78822 & cppMask_un_16_);
	BIT_VEC cppVar_78823 = ROM.rd(cppVar_78822);
	bool cppVar_78825 = (cppVar_78823 == 129);
	if (cppVar_78825) {
	cppVar_78821 = SP;
	} else {
	BIT_VEC cppVar_78826;
	BIT_VEC cppVar_78827 = PC + 1;
	cppVar_78827 = (cppVar_78827 & cppMask_un_16_);
	BIT_VEC cppVar_78828 = ROM.rd(cppVar_78827);
	bool cppVar_78830 = (cppVar_78828 == 130);
	if (cppVar_78830) {
	cppVar_78826 = DPL;
	} else {
	BIT_VEC cppVar_78831;
	BIT_VEC cppVar_78832 = PC + 1;
	cppVar_78832 = (cppVar_78832 & cppMask_un_16_);
	BIT_VEC cppVar_78833 = ROM.rd(cppVar_78832);
	bool cppVar_78835 = (cppVar_78833 == 131);
	if (cppVar_78835) {
	cppVar_78831 = DPH;
	} else {
	BIT_VEC cppVar_78836;
	BIT_VEC cppVar_78837 = PC + 1;
	cppVar_78837 = (cppVar_78837 & cppMask_un_16_);
	BIT_VEC cppVar_78838 = ROM.rd(cppVar_78837);
	bool cppVar_78840 = (cppVar_78838 == 135);
	if (cppVar_78840) {
	cppVar_78836 = PCON;
	} else {
	BIT_VEC cppVar_78841;
	BIT_VEC cppVar_78842 = PC + 1;
	cppVar_78842 = (cppVar_78842 & cppMask_un_16_);
	BIT_VEC cppVar_78843 = ROM.rd(cppVar_78842);
	bool cppVar_78845 = (cppVar_78843 == 136);
	if (cppVar_78845) {
	cppVar_78841 = TCON;
	} else {
	BIT_VEC cppVar_78846;
	BIT_VEC cppVar_78847 = PC + 1;
	cppVar_78847 = (cppVar_78847 & cppMask_un_16_);
	BIT_VEC cppVar_78848 = ROM.rd(cppVar_78847);
	bool cppVar_78850 = (cppVar_78848 == 137);
	if (cppVar_78850) {
	cppVar_78846 = TMOD;
	} else {
	BIT_VEC cppVar_78851;
	BIT_VEC cppVar_78852 = PC + 1;
	cppVar_78852 = (cppVar_78852 & cppMask_un_16_);
	BIT_VEC cppVar_78853 = ROM.rd(cppVar_78852);
	bool cppVar_78855 = (cppVar_78853 == 138);
	if (cppVar_78855) {
	cppVar_78851 = TL0;
	} else {
	BIT_VEC cppVar_78856;
	BIT_VEC cppVar_78857 = PC + 1;
	cppVar_78857 = (cppVar_78857 & cppMask_un_16_);
	BIT_VEC cppVar_78858 = ROM.rd(cppVar_78857);
	bool cppVar_78860 = (cppVar_78858 == 140);
	if (cppVar_78860) {
	cppVar_78856 = TH0;
	} else {
	BIT_VEC cppVar_78861;
	BIT_VEC cppVar_78862 = PC + 1;
	cppVar_78862 = (cppVar_78862 & cppMask_un_16_);
	BIT_VEC cppVar_78863 = ROM.rd(cppVar_78862);
	bool cppVar_78865 = (cppVar_78863 == 139);
	if (cppVar_78865) {
	cppVar_78861 = TL1;
	} else {
	BIT_VEC cppVar_78866;
	BIT_VEC cppVar_78867 = PC + 1;
	cppVar_78867 = (cppVar_78867 & cppMask_un_16_);
	BIT_VEC cppVar_78868 = ROM.rd(cppVar_78867);
	bool cppVar_78870 = (cppVar_78868 == 141);
	if (cppVar_78870) {
	cppVar_78866 = TH1;
	} else {
	BIT_VEC cppVar_78871;
	BIT_VEC cppVar_78872 = PC + 1;
	cppVar_78872 = (cppVar_78872 & cppMask_un_16_);
	BIT_VEC cppVar_78873 = ROM.rd(cppVar_78872);
	bool cppVar_78875 = (cppVar_78873 == 144);
	if (cppVar_78875) {
	cppVar_78871 = P1;
	} else {
	BIT_VEC cppVar_78876;
	BIT_VEC cppVar_78877 = PC + 1;
	cppVar_78877 = (cppVar_78877 & cppMask_un_16_);
	BIT_VEC cppVar_78878 = ROM.rd(cppVar_78877);
	bool cppVar_78880 = (cppVar_78878 == 152);
	if (cppVar_78880) {
	cppVar_78876 = SCON;
	} else {
	BIT_VEC cppVar_78881;
	BIT_VEC cppVar_78882 = PC + 1;
	cppVar_78882 = (cppVar_78882 & cppMask_un_16_);
	BIT_VEC cppVar_78883 = ROM.rd(cppVar_78882);
	bool cppVar_78885 = (cppVar_78883 == 153);
	if (cppVar_78885) {
	cppVar_78881 = SBUF;
	} else {
	BIT_VEC cppVar_78886;
	BIT_VEC cppVar_78887 = PC + 1;
	cppVar_78887 = (cppVar_78887 & cppMask_un_16_);
	BIT_VEC cppVar_78888 = ROM.rd(cppVar_78887);
	bool cppVar_78890 = (cppVar_78888 == 160);
	if (cppVar_78890) {
	cppVar_78886 = P2;
	} else {
	BIT_VEC cppVar_78891;
	BIT_VEC cppVar_78892 = PC + 1;
	cppVar_78892 = (cppVar_78892 & cppMask_un_16_);
	BIT_VEC cppVar_78893 = ROM.rd(cppVar_78892);
	bool cppVar_78895 = (cppVar_78893 == 168);
	if (cppVar_78895) {
	cppVar_78891 = IE;
	} else {
	BIT_VEC cppVar_78896;
	BIT_VEC cppVar_78897 = PC + 1;
	cppVar_78897 = (cppVar_78897 & cppMask_un_16_);
	BIT_VEC cppVar_78898 = ROM.rd(cppVar_78897);
	bool cppVar_78900 = (cppVar_78898 == 176);
	if (cppVar_78900) {
	cppVar_78896 = P3;
	} else {
	BIT_VEC cppVar_78901;
	BIT_VEC cppVar_78902 = PC + 1;
	cppVar_78902 = (cppVar_78902 & cppMask_un_16_);
	BIT_VEC cppVar_78903 = ROM.rd(cppVar_78902);
	bool cppVar_78905 = (cppVar_78903 == 184);
	if (cppVar_78905) {
	cppVar_78901 = IP;
	} else {
	BIT_VEC cppVar_78906;
	BIT_VEC cppVar_78907 = PC + 1;
	cppVar_78907 = (cppVar_78907 & cppMask_un_16_);
	BIT_VEC cppVar_78908 = ROM.rd(cppVar_78907);
	bool cppVar_78910 = (cppVar_78908 == 208);
	if (cppVar_78910) {
	cppVar_78906 = PSW;
	} else {
	BIT_VEC cppVar_78911;
	BIT_VEC cppVar_78912 = PC + 1;
	cppVar_78912 = (cppVar_78912 & cppMask_un_16_);
	BIT_VEC cppVar_78913 = ROM.rd(cppVar_78912);
	bool cppVar_78915 = (cppVar_78913 == 224);
	if (cppVar_78915) {
	cppVar_78911 = ACC;
	} else {
	BIT_VEC cppVar_78916;
	BIT_VEC cppVar_78917 = PC + 1;
	cppVar_78917 = (cppVar_78917 & cppMask_un_16_);
	BIT_VEC cppVar_78918 = ROM.rd(cppVar_78917);
	bool cppVar_78920 = (cppVar_78918 == 240);
	if (cppVar_78920) {
	cppVar_78916 = B;
	} else {
	cppVar_78916 = 0;
	}
	cppVar_78911 = cppVar_78916;
	}
	cppVar_78906 = cppVar_78911;
	}
	cppVar_78901 = cppVar_78906;
	}
	cppVar_78896 = cppVar_78901;
	}
	cppVar_78891 = cppVar_78896;
	}
	cppVar_78886 = cppVar_78891;
	}
	cppVar_78881 = cppVar_78886;
	}
	cppVar_78876 = cppVar_78881;
	}
	cppVar_78871 = cppVar_78876;
	}
	cppVar_78866 = cppVar_78871;
	}
	cppVar_78861 = cppVar_78866;
	}
	cppVar_78856 = cppVar_78861;
	}
	cppVar_78851 = cppVar_78856;
	}
	cppVar_78846 = cppVar_78851;
	}
	cppVar_78841 = cppVar_78846;
	}
	cppVar_78836 = cppVar_78841;
	}
	cppVar_78831 = cppVar_78836;
	}
	cppVar_78826 = cppVar_78831;
	}
	cppVar_78821 = cppVar_78826;
	}
	cppVar_78816 = cppVar_78821;
	}
	cppVar_78807 = cppVar_78816;
	}
	BIT_VEC cppVar_78922 = cppVar_78807 ^ ACC;
	cppVar_78801 = cppVar_78922;
	} else {
	cppVar_78801 = TL0;
	}
	cppVar_78797 = cppVar_78801;
	} else {
	BIT_VEC cppVar_78923;
	BIT_VEC cppVar_78924 = ROM.rd(PC);
	bool cppVar_78926 = (cppVar_78924 == 83);
	if (cppVar_78926) {
	BIT_VEC cppVar_78927;
	BIT_VEC cppVar_78929 = PC + 1;
	cppVar_78929 = (cppVar_78929 & cppMask_un_16_);
	BIT_VEC cppVar_78930 = ROM.rd(cppVar_78929);
	bool cppVar_78932 = (cppVar_78930 == 138);
	if (cppVar_78932) {
	BIT_VEC cppVar_78933;
	BIT_VEC cppVar_78934 = PC + 1;
	cppVar_78934 = (cppVar_78934 & cppMask_un_16_);
	BIT_VEC cppVar_78935 = ROM.rd(cppVar_78934);
	BIT_VEC cppVar_78936 = (cppVar_78935 >> 7) & cppMask_un_1_;
	bool cppVar_78938 = (cppVar_78936 == 0);
	if (cppVar_78938) {
	BIT_VEC cppVar_78939 = PC + 1;
	cppVar_78939 = (cppVar_78939 & cppMask_un_16_);
	BIT_VEC cppVar_78940 = ROM.rd(cppVar_78939);
	BIT_VEC cppVar_78941 = IRAM.rd(cppVar_78940);
	cppVar_78933 = cppVar_78941;
	} else {
	BIT_VEC cppVar_78942;
	BIT_VEC cppVar_78943 = PC + 1;
	cppVar_78943 = (cppVar_78943 & cppMask_un_16_);
	BIT_VEC cppVar_78944 = ROM.rd(cppVar_78943);
	bool cppVar_78946 = (cppVar_78944 == 128);
	if (cppVar_78946) {
	cppVar_78942 = P0;
	} else {
	BIT_VEC cppVar_78947;
	BIT_VEC cppVar_78948 = PC + 1;
	cppVar_78948 = (cppVar_78948 & cppMask_un_16_);
	BIT_VEC cppVar_78949 = ROM.rd(cppVar_78948);
	bool cppVar_78951 = (cppVar_78949 == 129);
	if (cppVar_78951) {
	cppVar_78947 = SP;
	} else {
	BIT_VEC cppVar_78952;
	BIT_VEC cppVar_78953 = PC + 1;
	cppVar_78953 = (cppVar_78953 & cppMask_un_16_);
	BIT_VEC cppVar_78954 = ROM.rd(cppVar_78953);
	bool cppVar_78956 = (cppVar_78954 == 130);
	if (cppVar_78956) {
	cppVar_78952 = DPL;
	} else {
	BIT_VEC cppVar_78957;
	BIT_VEC cppVar_78958 = PC + 1;
	cppVar_78958 = (cppVar_78958 & cppMask_un_16_);
	BIT_VEC cppVar_78959 = ROM.rd(cppVar_78958);
	bool cppVar_78961 = (cppVar_78959 == 131);
	if (cppVar_78961) {
	cppVar_78957 = DPH;
	} else {
	BIT_VEC cppVar_78962;
	BIT_VEC cppVar_78963 = PC + 1;
	cppVar_78963 = (cppVar_78963 & cppMask_un_16_);
	BIT_VEC cppVar_78964 = ROM.rd(cppVar_78963);
	bool cppVar_78966 = (cppVar_78964 == 135);
	if (cppVar_78966) {
	cppVar_78962 = PCON;
	} else {
	BIT_VEC cppVar_78967;
	BIT_VEC cppVar_78968 = PC + 1;
	cppVar_78968 = (cppVar_78968 & cppMask_un_16_);
	BIT_VEC cppVar_78969 = ROM.rd(cppVar_78968);
	bool cppVar_78971 = (cppVar_78969 == 136);
	if (cppVar_78971) {
	cppVar_78967 = TCON;
	} else {
	BIT_VEC cppVar_78972;
	BIT_VEC cppVar_78973 = PC + 1;
	cppVar_78973 = (cppVar_78973 & cppMask_un_16_);
	BIT_VEC cppVar_78974 = ROM.rd(cppVar_78973);
	bool cppVar_78976 = (cppVar_78974 == 137);
	if (cppVar_78976) {
	cppVar_78972 = TMOD;
	} else {
	BIT_VEC cppVar_78977;
	BIT_VEC cppVar_78978 = PC + 1;
	cppVar_78978 = (cppVar_78978 & cppMask_un_16_);
	BIT_VEC cppVar_78979 = ROM.rd(cppVar_78978);
	bool cppVar_78981 = (cppVar_78979 == 138);
	if (cppVar_78981) {
	cppVar_78977 = TL0;
	} else {
	BIT_VEC cppVar_78982;
	BIT_VEC cppVar_78983 = PC + 1;
	cppVar_78983 = (cppVar_78983 & cppMask_un_16_);
	BIT_VEC cppVar_78984 = ROM.rd(cppVar_78983);
	bool cppVar_78986 = (cppVar_78984 == 140);
	if (cppVar_78986) {
	cppVar_78982 = TH0;
	} else {
	BIT_VEC cppVar_78987;
	BIT_VEC cppVar_78988 = PC + 1;
	cppVar_78988 = (cppVar_78988 & cppMask_un_16_);
	BIT_VEC cppVar_78989 = ROM.rd(cppVar_78988);
	bool cppVar_78991 = (cppVar_78989 == 139);
	if (cppVar_78991) {
	cppVar_78987 = TL1;
	} else {
	BIT_VEC cppVar_78992;
	BIT_VEC cppVar_78993 = PC + 1;
	cppVar_78993 = (cppVar_78993 & cppMask_un_16_);
	BIT_VEC cppVar_78994 = ROM.rd(cppVar_78993);
	bool cppVar_78996 = (cppVar_78994 == 141);
	if (cppVar_78996) {
	cppVar_78992 = TH1;
	} else {
	BIT_VEC cppVar_78997;
	BIT_VEC cppVar_78998 = PC + 1;
	cppVar_78998 = (cppVar_78998 & cppMask_un_16_);
	BIT_VEC cppVar_78999 = ROM.rd(cppVar_78998);
	bool cppVar_79001 = (cppVar_78999 == 144);
	if (cppVar_79001) {
	cppVar_78997 = P1;
	} else {
	BIT_VEC cppVar_79002;
	BIT_VEC cppVar_79003 = PC + 1;
	cppVar_79003 = (cppVar_79003 & cppMask_un_16_);
	BIT_VEC cppVar_79004 = ROM.rd(cppVar_79003);
	bool cppVar_79006 = (cppVar_79004 == 152);
	if (cppVar_79006) {
	cppVar_79002 = SCON;
	} else {
	BIT_VEC cppVar_79007;
	BIT_VEC cppVar_79008 = PC + 1;
	cppVar_79008 = (cppVar_79008 & cppMask_un_16_);
	BIT_VEC cppVar_79009 = ROM.rd(cppVar_79008);
	bool cppVar_79011 = (cppVar_79009 == 153);
	if (cppVar_79011) {
	cppVar_79007 = SBUF;
	} else {
	BIT_VEC cppVar_79012;
	BIT_VEC cppVar_79013 = PC + 1;
	cppVar_79013 = (cppVar_79013 & cppMask_un_16_);
	BIT_VEC cppVar_79014 = ROM.rd(cppVar_79013);
	bool cppVar_79016 = (cppVar_79014 == 160);
	if (cppVar_79016) {
	cppVar_79012 = P2;
	} else {
	BIT_VEC cppVar_79017;
	BIT_VEC cppVar_79018 = PC + 1;
	cppVar_79018 = (cppVar_79018 & cppMask_un_16_);
	BIT_VEC cppVar_79019 = ROM.rd(cppVar_79018);
	bool cppVar_79021 = (cppVar_79019 == 168);
	if (cppVar_79021) {
	cppVar_79017 = IE;
	} else {
	BIT_VEC cppVar_79022;
	BIT_VEC cppVar_79023 = PC + 1;
	cppVar_79023 = (cppVar_79023 & cppMask_un_16_);
	BIT_VEC cppVar_79024 = ROM.rd(cppVar_79023);
	bool cppVar_79026 = (cppVar_79024 == 176);
	if (cppVar_79026) {
	cppVar_79022 = P3;
	} else {
	BIT_VEC cppVar_79027;
	BIT_VEC cppVar_79028 = PC + 1;
	cppVar_79028 = (cppVar_79028 & cppMask_un_16_);
	BIT_VEC cppVar_79029 = ROM.rd(cppVar_79028);
	bool cppVar_79031 = (cppVar_79029 == 184);
	if (cppVar_79031) {
	cppVar_79027 = IP;
	} else {
	BIT_VEC cppVar_79032;
	BIT_VEC cppVar_79033 = PC + 1;
	cppVar_79033 = (cppVar_79033 & cppMask_un_16_);
	BIT_VEC cppVar_79034 = ROM.rd(cppVar_79033);
	bool cppVar_79036 = (cppVar_79034 == 208);
	if (cppVar_79036) {
	cppVar_79032 = PSW;
	} else {
	BIT_VEC cppVar_79037;
	BIT_VEC cppVar_79038 = PC + 1;
	cppVar_79038 = (cppVar_79038 & cppMask_un_16_);
	BIT_VEC cppVar_79039 = ROM.rd(cppVar_79038);
	bool cppVar_79041 = (cppVar_79039 == 224);
	if (cppVar_79041) {
	cppVar_79037 = ACC;
	} else {
	BIT_VEC cppVar_79042;
	BIT_VEC cppVar_79043 = PC + 1;
	cppVar_79043 = (cppVar_79043 & cppMask_un_16_);
	BIT_VEC cppVar_79044 = ROM.rd(cppVar_79043);
	bool cppVar_79046 = (cppVar_79044 == 240);
	if (cppVar_79046) {
	cppVar_79042 = B;
	} else {
	cppVar_79042 = 0;
	}
	cppVar_79037 = cppVar_79042;
	}
	cppVar_79032 = cppVar_79037;
	}
	cppVar_79027 = cppVar_79032;
	}
	cppVar_79022 = cppVar_79027;
	}
	cppVar_79017 = cppVar_79022;
	}
	cppVar_79012 = cppVar_79017;
	}
	cppVar_79007 = cppVar_79012;
	}
	cppVar_79002 = cppVar_79007;
	}
	cppVar_78997 = cppVar_79002;
	}
	cppVar_78992 = cppVar_78997;
	}
	cppVar_78987 = cppVar_78992;
	}
	cppVar_78982 = cppVar_78987;
	}
	cppVar_78977 = cppVar_78982;
	}
	cppVar_78972 = cppVar_78977;
	}
	cppVar_78967 = cppVar_78972;
	}
	cppVar_78962 = cppVar_78967;
	}
	cppVar_78957 = cppVar_78962;
	}
	cppVar_78952 = cppVar_78957;
	}
	cppVar_78947 = cppVar_78952;
	}
	cppVar_78942 = cppVar_78947;
	}
	cppVar_78933 = cppVar_78942;
	}
	BIT_VEC cppVar_79049 = PC + 2;
	cppVar_79049 = (cppVar_79049 & cppMask_un_16_);
	BIT_VEC cppVar_79050 = ROM.rd(cppVar_79049);
	BIT_VEC cppVar_79051 = cppVar_78933 & cppVar_79050;
	cppVar_78927 = cppVar_79051;
	} else {
	cppVar_78927 = TL0;
	}
	cppVar_78923 = cppVar_78927;
	} else {
	BIT_VEC cppVar_79052;
	BIT_VEC cppVar_79053 = ROM.rd(PC);
	bool cppVar_79055 = (cppVar_79053 == 82);
	if (cppVar_79055) {
	BIT_VEC cppVar_79056;
	BIT_VEC cppVar_79058 = PC + 1;
	cppVar_79058 = (cppVar_79058 & cppMask_un_16_);
	BIT_VEC cppVar_79059 = ROM.rd(cppVar_79058);
	bool cppVar_79061 = (cppVar_79059 == 138);
	if (cppVar_79061) {
	BIT_VEC cppVar_79062;
	BIT_VEC cppVar_79063 = PC + 1;
	cppVar_79063 = (cppVar_79063 & cppMask_un_16_);
	BIT_VEC cppVar_79064 = ROM.rd(cppVar_79063);
	BIT_VEC cppVar_79065 = (cppVar_79064 >> 7) & cppMask_un_1_;
	bool cppVar_79067 = (cppVar_79065 == 0);
	if (cppVar_79067) {
	BIT_VEC cppVar_79068 = PC + 1;
	cppVar_79068 = (cppVar_79068 & cppMask_un_16_);
	BIT_VEC cppVar_79069 = ROM.rd(cppVar_79068);
	BIT_VEC cppVar_79070 = IRAM.rd(cppVar_79069);
	cppVar_79062 = cppVar_79070;
	} else {
	BIT_VEC cppVar_79071;
	BIT_VEC cppVar_79072 = PC + 1;
	cppVar_79072 = (cppVar_79072 & cppMask_un_16_);
	BIT_VEC cppVar_79073 = ROM.rd(cppVar_79072);
	bool cppVar_79075 = (cppVar_79073 == 128);
	if (cppVar_79075) {
	cppVar_79071 = P0;
	} else {
	BIT_VEC cppVar_79076;
	BIT_VEC cppVar_79077 = PC + 1;
	cppVar_79077 = (cppVar_79077 & cppMask_un_16_);
	BIT_VEC cppVar_79078 = ROM.rd(cppVar_79077);
	bool cppVar_79080 = (cppVar_79078 == 129);
	if (cppVar_79080) {
	cppVar_79076 = SP;
	} else {
	BIT_VEC cppVar_79081;
	BIT_VEC cppVar_79082 = PC + 1;
	cppVar_79082 = (cppVar_79082 & cppMask_un_16_);
	BIT_VEC cppVar_79083 = ROM.rd(cppVar_79082);
	bool cppVar_79085 = (cppVar_79083 == 130);
	if (cppVar_79085) {
	cppVar_79081 = DPL;
	} else {
	BIT_VEC cppVar_79086;
	BIT_VEC cppVar_79087 = PC + 1;
	cppVar_79087 = (cppVar_79087 & cppMask_un_16_);
	BIT_VEC cppVar_79088 = ROM.rd(cppVar_79087);
	bool cppVar_79090 = (cppVar_79088 == 131);
	if (cppVar_79090) {
	cppVar_79086 = DPH;
	} else {
	BIT_VEC cppVar_79091;
	BIT_VEC cppVar_79092 = PC + 1;
	cppVar_79092 = (cppVar_79092 & cppMask_un_16_);
	BIT_VEC cppVar_79093 = ROM.rd(cppVar_79092);
	bool cppVar_79095 = (cppVar_79093 == 135);
	if (cppVar_79095) {
	cppVar_79091 = PCON;
	} else {
	BIT_VEC cppVar_79096;
	BIT_VEC cppVar_79097 = PC + 1;
	cppVar_79097 = (cppVar_79097 & cppMask_un_16_);
	BIT_VEC cppVar_79098 = ROM.rd(cppVar_79097);
	bool cppVar_79100 = (cppVar_79098 == 136);
	if (cppVar_79100) {
	cppVar_79096 = TCON;
	} else {
	BIT_VEC cppVar_79101;
	BIT_VEC cppVar_79102 = PC + 1;
	cppVar_79102 = (cppVar_79102 & cppMask_un_16_);
	BIT_VEC cppVar_79103 = ROM.rd(cppVar_79102);
	bool cppVar_79105 = (cppVar_79103 == 137);
	if (cppVar_79105) {
	cppVar_79101 = TMOD;
	} else {
	BIT_VEC cppVar_79106;
	BIT_VEC cppVar_79107 = PC + 1;
	cppVar_79107 = (cppVar_79107 & cppMask_un_16_);
	BIT_VEC cppVar_79108 = ROM.rd(cppVar_79107);
	bool cppVar_79110 = (cppVar_79108 == 138);
	if (cppVar_79110) {
	cppVar_79106 = TL0;
	} else {
	BIT_VEC cppVar_79111;
	BIT_VEC cppVar_79112 = PC + 1;
	cppVar_79112 = (cppVar_79112 & cppMask_un_16_);
	BIT_VEC cppVar_79113 = ROM.rd(cppVar_79112);
	bool cppVar_79115 = (cppVar_79113 == 140);
	if (cppVar_79115) {
	cppVar_79111 = TH0;
	} else {
	BIT_VEC cppVar_79116;
	BIT_VEC cppVar_79117 = PC + 1;
	cppVar_79117 = (cppVar_79117 & cppMask_un_16_);
	BIT_VEC cppVar_79118 = ROM.rd(cppVar_79117);
	bool cppVar_79120 = (cppVar_79118 == 139);
	if (cppVar_79120) {
	cppVar_79116 = TL1;
	} else {
	BIT_VEC cppVar_79121;
	BIT_VEC cppVar_79122 = PC + 1;
	cppVar_79122 = (cppVar_79122 & cppMask_un_16_);
	BIT_VEC cppVar_79123 = ROM.rd(cppVar_79122);
	bool cppVar_79125 = (cppVar_79123 == 141);
	if (cppVar_79125) {
	cppVar_79121 = TH1;
	} else {
	BIT_VEC cppVar_79126;
	BIT_VEC cppVar_79127 = PC + 1;
	cppVar_79127 = (cppVar_79127 & cppMask_un_16_);
	BIT_VEC cppVar_79128 = ROM.rd(cppVar_79127);
	bool cppVar_79130 = (cppVar_79128 == 144);
	if (cppVar_79130) {
	cppVar_79126 = P1;
	} else {
	BIT_VEC cppVar_79131;
	BIT_VEC cppVar_79132 = PC + 1;
	cppVar_79132 = (cppVar_79132 & cppMask_un_16_);
	BIT_VEC cppVar_79133 = ROM.rd(cppVar_79132);
	bool cppVar_79135 = (cppVar_79133 == 152);
	if (cppVar_79135) {
	cppVar_79131 = SCON;
	} else {
	BIT_VEC cppVar_79136;
	BIT_VEC cppVar_79137 = PC + 1;
	cppVar_79137 = (cppVar_79137 & cppMask_un_16_);
	BIT_VEC cppVar_79138 = ROM.rd(cppVar_79137);
	bool cppVar_79140 = (cppVar_79138 == 153);
	if (cppVar_79140) {
	cppVar_79136 = SBUF;
	} else {
	BIT_VEC cppVar_79141;
	BIT_VEC cppVar_79142 = PC + 1;
	cppVar_79142 = (cppVar_79142 & cppMask_un_16_);
	BIT_VEC cppVar_79143 = ROM.rd(cppVar_79142);
	bool cppVar_79145 = (cppVar_79143 == 160);
	if (cppVar_79145) {
	cppVar_79141 = P2;
	} else {
	BIT_VEC cppVar_79146;
	BIT_VEC cppVar_79147 = PC + 1;
	cppVar_79147 = (cppVar_79147 & cppMask_un_16_);
	BIT_VEC cppVar_79148 = ROM.rd(cppVar_79147);
	bool cppVar_79150 = (cppVar_79148 == 168);
	if (cppVar_79150) {
	cppVar_79146 = IE;
	} else {
	BIT_VEC cppVar_79151;
	BIT_VEC cppVar_79152 = PC + 1;
	cppVar_79152 = (cppVar_79152 & cppMask_un_16_);
	BIT_VEC cppVar_79153 = ROM.rd(cppVar_79152);
	bool cppVar_79155 = (cppVar_79153 == 176);
	if (cppVar_79155) {
	cppVar_79151 = P3;
	} else {
	BIT_VEC cppVar_79156;
	BIT_VEC cppVar_79157 = PC + 1;
	cppVar_79157 = (cppVar_79157 & cppMask_un_16_);
	BIT_VEC cppVar_79158 = ROM.rd(cppVar_79157);
	bool cppVar_79160 = (cppVar_79158 == 184);
	if (cppVar_79160) {
	cppVar_79156 = IP;
	} else {
	BIT_VEC cppVar_79161;
	BIT_VEC cppVar_79162 = PC + 1;
	cppVar_79162 = (cppVar_79162 & cppMask_un_16_);
	BIT_VEC cppVar_79163 = ROM.rd(cppVar_79162);
	bool cppVar_79165 = (cppVar_79163 == 208);
	if (cppVar_79165) {
	cppVar_79161 = PSW;
	} else {
	BIT_VEC cppVar_79166;
	BIT_VEC cppVar_79167 = PC + 1;
	cppVar_79167 = (cppVar_79167 & cppMask_un_16_);
	BIT_VEC cppVar_79168 = ROM.rd(cppVar_79167);
	bool cppVar_79170 = (cppVar_79168 == 224);
	if (cppVar_79170) {
	cppVar_79166 = ACC;
	} else {
	BIT_VEC cppVar_79171;
	BIT_VEC cppVar_79172 = PC + 1;
	cppVar_79172 = (cppVar_79172 & cppMask_un_16_);
	BIT_VEC cppVar_79173 = ROM.rd(cppVar_79172);
	bool cppVar_79175 = (cppVar_79173 == 240);
	if (cppVar_79175) {
	cppVar_79171 = B;
	} else {
	cppVar_79171 = 0;
	}
	cppVar_79166 = cppVar_79171;
	}
	cppVar_79161 = cppVar_79166;
	}
	cppVar_79156 = cppVar_79161;
	}
	cppVar_79151 = cppVar_79156;
	}
	cppVar_79146 = cppVar_79151;
	}
	cppVar_79141 = cppVar_79146;
	}
	cppVar_79136 = cppVar_79141;
	}
	cppVar_79131 = cppVar_79136;
	}
	cppVar_79126 = cppVar_79131;
	}
	cppVar_79121 = cppVar_79126;
	}
	cppVar_79116 = cppVar_79121;
	}
	cppVar_79111 = cppVar_79116;
	}
	cppVar_79106 = cppVar_79111;
	}
	cppVar_79101 = cppVar_79106;
	}
	cppVar_79096 = cppVar_79101;
	}
	cppVar_79091 = cppVar_79096;
	}
	cppVar_79086 = cppVar_79091;
	}
	cppVar_79081 = cppVar_79086;
	}
	cppVar_79076 = cppVar_79081;
	}
	cppVar_79071 = cppVar_79076;
	}
	cppVar_79062 = cppVar_79071;
	}
	BIT_VEC cppVar_79177 = cppVar_79062 & ACC;
	cppVar_79056 = cppVar_79177;
	} else {
	cppVar_79056 = TL0;
	}
	cppVar_79052 = cppVar_79056;
	} else {
	BIT_VEC cppVar_79178;
	BIT_VEC cppVar_79179 = ROM.rd(PC);
	bool cppVar_79181 = (cppVar_79179 == 67);
	if (cppVar_79181) {
	BIT_VEC cppVar_79182;
	BIT_VEC cppVar_79184 = PC + 1;
	cppVar_79184 = (cppVar_79184 & cppMask_un_16_);
	BIT_VEC cppVar_79185 = ROM.rd(cppVar_79184);
	bool cppVar_79187 = (cppVar_79185 == 138);
	if (cppVar_79187) {
	BIT_VEC cppVar_79188;
	BIT_VEC cppVar_79189 = PC + 1;
	cppVar_79189 = (cppVar_79189 & cppMask_un_16_);
	BIT_VEC cppVar_79190 = ROM.rd(cppVar_79189);
	BIT_VEC cppVar_79191 = (cppVar_79190 >> 7) & cppMask_un_1_;
	bool cppVar_79193 = (cppVar_79191 == 0);
	if (cppVar_79193) {
	BIT_VEC cppVar_79194 = PC + 1;
	cppVar_79194 = (cppVar_79194 & cppMask_un_16_);
	BIT_VEC cppVar_79195 = ROM.rd(cppVar_79194);
	BIT_VEC cppVar_79196 = IRAM.rd(cppVar_79195);
	cppVar_79188 = cppVar_79196;
	} else {
	BIT_VEC cppVar_79197;
	BIT_VEC cppVar_79198 = PC + 1;
	cppVar_79198 = (cppVar_79198 & cppMask_un_16_);
	BIT_VEC cppVar_79199 = ROM.rd(cppVar_79198);
	bool cppVar_79201 = (cppVar_79199 == 128);
	if (cppVar_79201) {
	cppVar_79197 = P0;
	} else {
	BIT_VEC cppVar_79202;
	BIT_VEC cppVar_79203 = PC + 1;
	cppVar_79203 = (cppVar_79203 & cppMask_un_16_);
	BIT_VEC cppVar_79204 = ROM.rd(cppVar_79203);
	bool cppVar_79206 = (cppVar_79204 == 129);
	if (cppVar_79206) {
	cppVar_79202 = SP;
	} else {
	BIT_VEC cppVar_79207;
	BIT_VEC cppVar_79208 = PC + 1;
	cppVar_79208 = (cppVar_79208 & cppMask_un_16_);
	BIT_VEC cppVar_79209 = ROM.rd(cppVar_79208);
	bool cppVar_79211 = (cppVar_79209 == 130);
	if (cppVar_79211) {
	cppVar_79207 = DPL;
	} else {
	BIT_VEC cppVar_79212;
	BIT_VEC cppVar_79213 = PC + 1;
	cppVar_79213 = (cppVar_79213 & cppMask_un_16_);
	BIT_VEC cppVar_79214 = ROM.rd(cppVar_79213);
	bool cppVar_79216 = (cppVar_79214 == 131);
	if (cppVar_79216) {
	cppVar_79212 = DPH;
	} else {
	BIT_VEC cppVar_79217;
	BIT_VEC cppVar_79218 = PC + 1;
	cppVar_79218 = (cppVar_79218 & cppMask_un_16_);
	BIT_VEC cppVar_79219 = ROM.rd(cppVar_79218);
	bool cppVar_79221 = (cppVar_79219 == 135);
	if (cppVar_79221) {
	cppVar_79217 = PCON;
	} else {
	BIT_VEC cppVar_79222;
	BIT_VEC cppVar_79223 = PC + 1;
	cppVar_79223 = (cppVar_79223 & cppMask_un_16_);
	BIT_VEC cppVar_79224 = ROM.rd(cppVar_79223);
	bool cppVar_79226 = (cppVar_79224 == 136);
	if (cppVar_79226) {
	cppVar_79222 = TCON;
	} else {
	BIT_VEC cppVar_79227;
	BIT_VEC cppVar_79228 = PC + 1;
	cppVar_79228 = (cppVar_79228 & cppMask_un_16_);
	BIT_VEC cppVar_79229 = ROM.rd(cppVar_79228);
	bool cppVar_79231 = (cppVar_79229 == 137);
	if (cppVar_79231) {
	cppVar_79227 = TMOD;
	} else {
	BIT_VEC cppVar_79232;
	BIT_VEC cppVar_79233 = PC + 1;
	cppVar_79233 = (cppVar_79233 & cppMask_un_16_);
	BIT_VEC cppVar_79234 = ROM.rd(cppVar_79233);
	bool cppVar_79236 = (cppVar_79234 == 138);
	if (cppVar_79236) {
	cppVar_79232 = TL0;
	} else {
	BIT_VEC cppVar_79237;
	BIT_VEC cppVar_79238 = PC + 1;
	cppVar_79238 = (cppVar_79238 & cppMask_un_16_);
	BIT_VEC cppVar_79239 = ROM.rd(cppVar_79238);
	bool cppVar_79241 = (cppVar_79239 == 140);
	if (cppVar_79241) {
	cppVar_79237 = TH0;
	} else {
	BIT_VEC cppVar_79242;
	BIT_VEC cppVar_79243 = PC + 1;
	cppVar_79243 = (cppVar_79243 & cppMask_un_16_);
	BIT_VEC cppVar_79244 = ROM.rd(cppVar_79243);
	bool cppVar_79246 = (cppVar_79244 == 139);
	if (cppVar_79246) {
	cppVar_79242 = TL1;
	} else {
	BIT_VEC cppVar_79247;
	BIT_VEC cppVar_79248 = PC + 1;
	cppVar_79248 = (cppVar_79248 & cppMask_un_16_);
	BIT_VEC cppVar_79249 = ROM.rd(cppVar_79248);
	bool cppVar_79251 = (cppVar_79249 == 141);
	if (cppVar_79251) {
	cppVar_79247 = TH1;
	} else {
	BIT_VEC cppVar_79252;
	BIT_VEC cppVar_79253 = PC + 1;
	cppVar_79253 = (cppVar_79253 & cppMask_un_16_);
	BIT_VEC cppVar_79254 = ROM.rd(cppVar_79253);
	bool cppVar_79256 = (cppVar_79254 == 144);
	if (cppVar_79256) {
	cppVar_79252 = P1;
	} else {
	BIT_VEC cppVar_79257;
	BIT_VEC cppVar_79258 = PC + 1;
	cppVar_79258 = (cppVar_79258 & cppMask_un_16_);
	BIT_VEC cppVar_79259 = ROM.rd(cppVar_79258);
	bool cppVar_79261 = (cppVar_79259 == 152);
	if (cppVar_79261) {
	cppVar_79257 = SCON;
	} else {
	BIT_VEC cppVar_79262;
	BIT_VEC cppVar_79263 = PC + 1;
	cppVar_79263 = (cppVar_79263 & cppMask_un_16_);
	BIT_VEC cppVar_79264 = ROM.rd(cppVar_79263);
	bool cppVar_79266 = (cppVar_79264 == 153);
	if (cppVar_79266) {
	cppVar_79262 = SBUF;
	} else {
	BIT_VEC cppVar_79267;
	BIT_VEC cppVar_79268 = PC + 1;
	cppVar_79268 = (cppVar_79268 & cppMask_un_16_);
	BIT_VEC cppVar_79269 = ROM.rd(cppVar_79268);
	bool cppVar_79271 = (cppVar_79269 == 160);
	if (cppVar_79271) {
	cppVar_79267 = P2;
	} else {
	BIT_VEC cppVar_79272;
	BIT_VEC cppVar_79273 = PC + 1;
	cppVar_79273 = (cppVar_79273 & cppMask_un_16_);
	BIT_VEC cppVar_79274 = ROM.rd(cppVar_79273);
	bool cppVar_79276 = (cppVar_79274 == 168);
	if (cppVar_79276) {
	cppVar_79272 = IE;
	} else {
	BIT_VEC cppVar_79277;
	BIT_VEC cppVar_79278 = PC + 1;
	cppVar_79278 = (cppVar_79278 & cppMask_un_16_);
	BIT_VEC cppVar_79279 = ROM.rd(cppVar_79278);
	bool cppVar_79281 = (cppVar_79279 == 176);
	if (cppVar_79281) {
	cppVar_79277 = P3;
	} else {
	BIT_VEC cppVar_79282;
	BIT_VEC cppVar_79283 = PC + 1;
	cppVar_79283 = (cppVar_79283 & cppMask_un_16_);
	BIT_VEC cppVar_79284 = ROM.rd(cppVar_79283);
	bool cppVar_79286 = (cppVar_79284 == 184);
	if (cppVar_79286) {
	cppVar_79282 = IP;
	} else {
	BIT_VEC cppVar_79287;
	BIT_VEC cppVar_79288 = PC + 1;
	cppVar_79288 = (cppVar_79288 & cppMask_un_16_);
	BIT_VEC cppVar_79289 = ROM.rd(cppVar_79288);
	bool cppVar_79291 = (cppVar_79289 == 208);
	if (cppVar_79291) {
	cppVar_79287 = PSW;
	} else {
	BIT_VEC cppVar_79292;
	BIT_VEC cppVar_79293 = PC + 1;
	cppVar_79293 = (cppVar_79293 & cppMask_un_16_);
	BIT_VEC cppVar_79294 = ROM.rd(cppVar_79293);
	bool cppVar_79296 = (cppVar_79294 == 224);
	if (cppVar_79296) {
	cppVar_79292 = ACC;
	} else {
	BIT_VEC cppVar_79297;
	BIT_VEC cppVar_79298 = PC + 1;
	cppVar_79298 = (cppVar_79298 & cppMask_un_16_);
	BIT_VEC cppVar_79299 = ROM.rd(cppVar_79298);
	bool cppVar_79301 = (cppVar_79299 == 240);
	if (cppVar_79301) {
	cppVar_79297 = B;
	} else {
	cppVar_79297 = 0;
	}
	cppVar_79292 = cppVar_79297;
	}
	cppVar_79287 = cppVar_79292;
	}
	cppVar_79282 = cppVar_79287;
	}
	cppVar_79277 = cppVar_79282;
	}
	cppVar_79272 = cppVar_79277;
	}
	cppVar_79267 = cppVar_79272;
	}
	cppVar_79262 = cppVar_79267;
	}
	cppVar_79257 = cppVar_79262;
	}
	cppVar_79252 = cppVar_79257;
	}
	cppVar_79247 = cppVar_79252;
	}
	cppVar_79242 = cppVar_79247;
	}
	cppVar_79237 = cppVar_79242;
	}
	cppVar_79232 = cppVar_79237;
	}
	cppVar_79227 = cppVar_79232;
	}
	cppVar_79222 = cppVar_79227;
	}
	cppVar_79217 = cppVar_79222;
	}
	cppVar_79212 = cppVar_79217;
	}
	cppVar_79207 = cppVar_79212;
	}
	cppVar_79202 = cppVar_79207;
	}
	cppVar_79197 = cppVar_79202;
	}
	cppVar_79188 = cppVar_79197;
	}
	BIT_VEC cppVar_79304 = PC + 2;
	cppVar_79304 = (cppVar_79304 & cppMask_un_16_);
	BIT_VEC cppVar_79305 = ROM.rd(cppVar_79304);
	BIT_VEC cppVar_79306 = cppVar_79188 | cppVar_79305;
	cppVar_79182 = cppVar_79306;
	} else {
	cppVar_79182 = TL0;
	}
	cppVar_79178 = cppVar_79182;
	} else {
	BIT_VEC cppVar_79307;
	BIT_VEC cppVar_79308 = ROM.rd(PC);
	bool cppVar_79310 = (cppVar_79308 == 66);
	if (cppVar_79310) {
	BIT_VEC cppVar_79311;
	BIT_VEC cppVar_79313 = PC + 1;
	cppVar_79313 = (cppVar_79313 & cppMask_un_16_);
	BIT_VEC cppVar_79314 = ROM.rd(cppVar_79313);
	bool cppVar_79316 = (cppVar_79314 == 138);
	if (cppVar_79316) {
	BIT_VEC cppVar_79317;
	BIT_VEC cppVar_79318 = PC + 1;
	cppVar_79318 = (cppVar_79318 & cppMask_un_16_);
	BIT_VEC cppVar_79319 = ROM.rd(cppVar_79318);
	BIT_VEC cppVar_79320 = (cppVar_79319 >> 7) & cppMask_un_1_;
	bool cppVar_79322 = (cppVar_79320 == 0);
	if (cppVar_79322) {
	BIT_VEC cppVar_79323 = PC + 1;
	cppVar_79323 = (cppVar_79323 & cppMask_un_16_);
	BIT_VEC cppVar_79324 = ROM.rd(cppVar_79323);
	BIT_VEC cppVar_79325 = IRAM.rd(cppVar_79324);
	cppVar_79317 = cppVar_79325;
	} else {
	BIT_VEC cppVar_79326;
	BIT_VEC cppVar_79327 = PC + 1;
	cppVar_79327 = (cppVar_79327 & cppMask_un_16_);
	BIT_VEC cppVar_79328 = ROM.rd(cppVar_79327);
	bool cppVar_79330 = (cppVar_79328 == 128);
	if (cppVar_79330) {
	cppVar_79326 = P0;
	} else {
	BIT_VEC cppVar_79331;
	BIT_VEC cppVar_79332 = PC + 1;
	cppVar_79332 = (cppVar_79332 & cppMask_un_16_);
	BIT_VEC cppVar_79333 = ROM.rd(cppVar_79332);
	bool cppVar_79335 = (cppVar_79333 == 129);
	if (cppVar_79335) {
	cppVar_79331 = SP;
	} else {
	BIT_VEC cppVar_79336;
	BIT_VEC cppVar_79337 = PC + 1;
	cppVar_79337 = (cppVar_79337 & cppMask_un_16_);
	BIT_VEC cppVar_79338 = ROM.rd(cppVar_79337);
	bool cppVar_79340 = (cppVar_79338 == 130);
	if (cppVar_79340) {
	cppVar_79336 = DPL;
	} else {
	BIT_VEC cppVar_79341;
	BIT_VEC cppVar_79342 = PC + 1;
	cppVar_79342 = (cppVar_79342 & cppMask_un_16_);
	BIT_VEC cppVar_79343 = ROM.rd(cppVar_79342);
	bool cppVar_79345 = (cppVar_79343 == 131);
	if (cppVar_79345) {
	cppVar_79341 = DPH;
	} else {
	BIT_VEC cppVar_79346;
	BIT_VEC cppVar_79347 = PC + 1;
	cppVar_79347 = (cppVar_79347 & cppMask_un_16_);
	BIT_VEC cppVar_79348 = ROM.rd(cppVar_79347);
	bool cppVar_79350 = (cppVar_79348 == 135);
	if (cppVar_79350) {
	cppVar_79346 = PCON;
	} else {
	BIT_VEC cppVar_79351;
	BIT_VEC cppVar_79352 = PC + 1;
	cppVar_79352 = (cppVar_79352 & cppMask_un_16_);
	BIT_VEC cppVar_79353 = ROM.rd(cppVar_79352);
	bool cppVar_79355 = (cppVar_79353 == 136);
	if (cppVar_79355) {
	cppVar_79351 = TCON;
	} else {
	BIT_VEC cppVar_79356;
	BIT_VEC cppVar_79357 = PC + 1;
	cppVar_79357 = (cppVar_79357 & cppMask_un_16_);
	BIT_VEC cppVar_79358 = ROM.rd(cppVar_79357);
	bool cppVar_79360 = (cppVar_79358 == 137);
	if (cppVar_79360) {
	cppVar_79356 = TMOD;
	} else {
	BIT_VEC cppVar_79361;
	BIT_VEC cppVar_79362 = PC + 1;
	cppVar_79362 = (cppVar_79362 & cppMask_un_16_);
	BIT_VEC cppVar_79363 = ROM.rd(cppVar_79362);
	bool cppVar_79365 = (cppVar_79363 == 138);
	if (cppVar_79365) {
	cppVar_79361 = TL0;
	} else {
	BIT_VEC cppVar_79366;
	BIT_VEC cppVar_79367 = PC + 1;
	cppVar_79367 = (cppVar_79367 & cppMask_un_16_);
	BIT_VEC cppVar_79368 = ROM.rd(cppVar_79367);
	bool cppVar_79370 = (cppVar_79368 == 140);
	if (cppVar_79370) {
	cppVar_79366 = TH0;
	} else {
	BIT_VEC cppVar_79371;
	BIT_VEC cppVar_79372 = PC + 1;
	cppVar_79372 = (cppVar_79372 & cppMask_un_16_);
	BIT_VEC cppVar_79373 = ROM.rd(cppVar_79372);
	bool cppVar_79375 = (cppVar_79373 == 139);
	if (cppVar_79375) {
	cppVar_79371 = TL1;
	} else {
	BIT_VEC cppVar_79376;
	BIT_VEC cppVar_79377 = PC + 1;
	cppVar_79377 = (cppVar_79377 & cppMask_un_16_);
	BIT_VEC cppVar_79378 = ROM.rd(cppVar_79377);
	bool cppVar_79380 = (cppVar_79378 == 141);
	if (cppVar_79380) {
	cppVar_79376 = TH1;
	} else {
	BIT_VEC cppVar_79381;
	BIT_VEC cppVar_79382 = PC + 1;
	cppVar_79382 = (cppVar_79382 & cppMask_un_16_);
	BIT_VEC cppVar_79383 = ROM.rd(cppVar_79382);
	bool cppVar_79385 = (cppVar_79383 == 144);
	if (cppVar_79385) {
	cppVar_79381 = P1;
	} else {
	BIT_VEC cppVar_79386;
	BIT_VEC cppVar_79387 = PC + 1;
	cppVar_79387 = (cppVar_79387 & cppMask_un_16_);
	BIT_VEC cppVar_79388 = ROM.rd(cppVar_79387);
	bool cppVar_79390 = (cppVar_79388 == 152);
	if (cppVar_79390) {
	cppVar_79386 = SCON;
	} else {
	BIT_VEC cppVar_79391;
	BIT_VEC cppVar_79392 = PC + 1;
	cppVar_79392 = (cppVar_79392 & cppMask_un_16_);
	BIT_VEC cppVar_79393 = ROM.rd(cppVar_79392);
	bool cppVar_79395 = (cppVar_79393 == 153);
	if (cppVar_79395) {
	cppVar_79391 = SBUF;
	} else {
	BIT_VEC cppVar_79396;
	BIT_VEC cppVar_79397 = PC + 1;
	cppVar_79397 = (cppVar_79397 & cppMask_un_16_);
	BIT_VEC cppVar_79398 = ROM.rd(cppVar_79397);
	bool cppVar_79400 = (cppVar_79398 == 160);
	if (cppVar_79400) {
	cppVar_79396 = P2;
	} else {
	BIT_VEC cppVar_79401;
	BIT_VEC cppVar_79402 = PC + 1;
	cppVar_79402 = (cppVar_79402 & cppMask_un_16_);
	BIT_VEC cppVar_79403 = ROM.rd(cppVar_79402);
	bool cppVar_79405 = (cppVar_79403 == 168);
	if (cppVar_79405) {
	cppVar_79401 = IE;
	} else {
	BIT_VEC cppVar_79406;
	BIT_VEC cppVar_79407 = PC + 1;
	cppVar_79407 = (cppVar_79407 & cppMask_un_16_);
	BIT_VEC cppVar_79408 = ROM.rd(cppVar_79407);
	bool cppVar_79410 = (cppVar_79408 == 176);
	if (cppVar_79410) {
	cppVar_79406 = P3;
	} else {
	BIT_VEC cppVar_79411;
	BIT_VEC cppVar_79412 = PC + 1;
	cppVar_79412 = (cppVar_79412 & cppMask_un_16_);
	BIT_VEC cppVar_79413 = ROM.rd(cppVar_79412);
	bool cppVar_79415 = (cppVar_79413 == 184);
	if (cppVar_79415) {
	cppVar_79411 = IP;
	} else {
	BIT_VEC cppVar_79416;
	BIT_VEC cppVar_79417 = PC + 1;
	cppVar_79417 = (cppVar_79417 & cppMask_un_16_);
	BIT_VEC cppVar_79418 = ROM.rd(cppVar_79417);
	bool cppVar_79420 = (cppVar_79418 == 208);
	if (cppVar_79420) {
	cppVar_79416 = PSW;
	} else {
	BIT_VEC cppVar_79421;
	BIT_VEC cppVar_79422 = PC + 1;
	cppVar_79422 = (cppVar_79422 & cppMask_un_16_);
	BIT_VEC cppVar_79423 = ROM.rd(cppVar_79422);
	bool cppVar_79425 = (cppVar_79423 == 224);
	if (cppVar_79425) {
	cppVar_79421 = ACC;
	} else {
	BIT_VEC cppVar_79426;
	BIT_VEC cppVar_79427 = PC + 1;
	cppVar_79427 = (cppVar_79427 & cppMask_un_16_);
	BIT_VEC cppVar_79428 = ROM.rd(cppVar_79427);
	bool cppVar_79430 = (cppVar_79428 == 240);
	if (cppVar_79430) {
	cppVar_79426 = B;
	} else {
	cppVar_79426 = 0;
	}
	cppVar_79421 = cppVar_79426;
	}
	cppVar_79416 = cppVar_79421;
	}
	cppVar_79411 = cppVar_79416;
	}
	cppVar_79406 = cppVar_79411;
	}
	cppVar_79401 = cppVar_79406;
	}
	cppVar_79396 = cppVar_79401;
	}
	cppVar_79391 = cppVar_79396;
	}
	cppVar_79386 = cppVar_79391;
	}
	cppVar_79381 = cppVar_79386;
	}
	cppVar_79376 = cppVar_79381;
	}
	cppVar_79371 = cppVar_79376;
	}
	cppVar_79366 = cppVar_79371;
	}
	cppVar_79361 = cppVar_79366;
	}
	cppVar_79356 = cppVar_79361;
	}
	cppVar_79351 = cppVar_79356;
	}
	cppVar_79346 = cppVar_79351;
	}
	cppVar_79341 = cppVar_79346;
	}
	cppVar_79336 = cppVar_79341;
	}
	cppVar_79331 = cppVar_79336;
	}
	cppVar_79326 = cppVar_79331;
	}
	cppVar_79317 = cppVar_79326;
	}
	BIT_VEC cppVar_79432 = cppVar_79317 | ACC;
	cppVar_79311 = cppVar_79432;
	} else {
	cppVar_79311 = TL0;
	}
	cppVar_79307 = cppVar_79311;
	} else {
	BIT_VEC cppVar_79433;
	BIT_VEC cppVar_79434 = ROM.rd(PC);
	bool cppVar_79436 = (cppVar_79434 == 213);
	BIT_VEC cppVar_79437 = ROM.rd(PC);
	bool cppVar_79439 = (cppVar_79437 == 21);
	bool cppVar_79440 = cppVar_79436 || cppVar_79439;
	if (cppVar_79440) {
	BIT_VEC cppVar_79441;
	BIT_VEC cppVar_79443 = PC + 1;
	cppVar_79443 = (cppVar_79443 & cppMask_un_16_);
	BIT_VEC cppVar_79444 = ROM.rd(cppVar_79443);
	bool cppVar_79446 = (cppVar_79444 == 138);
	if (cppVar_79446) {
	BIT_VEC cppVar_79447;
	BIT_VEC cppVar_79448 = PC + 1;
	cppVar_79448 = (cppVar_79448 & cppMask_un_16_);
	BIT_VEC cppVar_79449 = ROM.rd(cppVar_79448);
	BIT_VEC cppVar_79450 = (cppVar_79449 >> 7) & cppMask_un_1_;
	bool cppVar_79452 = (cppVar_79450 == 0);
	if (cppVar_79452) {
	BIT_VEC cppVar_79453 = PC + 1;
	cppVar_79453 = (cppVar_79453 & cppMask_un_16_);
	BIT_VEC cppVar_79454 = ROM.rd(cppVar_79453);
	BIT_VEC cppVar_79455 = IRAM.rd(cppVar_79454);
	cppVar_79447 = cppVar_79455;
	} else {
	BIT_VEC cppVar_79456;
	BIT_VEC cppVar_79457 = PC + 1;
	cppVar_79457 = (cppVar_79457 & cppMask_un_16_);
	BIT_VEC cppVar_79458 = ROM.rd(cppVar_79457);
	bool cppVar_79460 = (cppVar_79458 == 128);
	if (cppVar_79460) {
	cppVar_79456 = P0;
	} else {
	BIT_VEC cppVar_79461;
	BIT_VEC cppVar_79462 = PC + 1;
	cppVar_79462 = (cppVar_79462 & cppMask_un_16_);
	BIT_VEC cppVar_79463 = ROM.rd(cppVar_79462);
	bool cppVar_79465 = (cppVar_79463 == 129);
	if (cppVar_79465) {
	cppVar_79461 = SP;
	} else {
	BIT_VEC cppVar_79466;
	BIT_VEC cppVar_79467 = PC + 1;
	cppVar_79467 = (cppVar_79467 & cppMask_un_16_);
	BIT_VEC cppVar_79468 = ROM.rd(cppVar_79467);
	bool cppVar_79470 = (cppVar_79468 == 130);
	if (cppVar_79470) {
	cppVar_79466 = DPL;
	} else {
	BIT_VEC cppVar_79471;
	BIT_VEC cppVar_79472 = PC + 1;
	cppVar_79472 = (cppVar_79472 & cppMask_un_16_);
	BIT_VEC cppVar_79473 = ROM.rd(cppVar_79472);
	bool cppVar_79475 = (cppVar_79473 == 131);
	if (cppVar_79475) {
	cppVar_79471 = DPH;
	} else {
	BIT_VEC cppVar_79476;
	BIT_VEC cppVar_79477 = PC + 1;
	cppVar_79477 = (cppVar_79477 & cppMask_un_16_);
	BIT_VEC cppVar_79478 = ROM.rd(cppVar_79477);
	bool cppVar_79480 = (cppVar_79478 == 135);
	if (cppVar_79480) {
	cppVar_79476 = PCON;
	} else {
	BIT_VEC cppVar_79481;
	BIT_VEC cppVar_79482 = PC + 1;
	cppVar_79482 = (cppVar_79482 & cppMask_un_16_);
	BIT_VEC cppVar_79483 = ROM.rd(cppVar_79482);
	bool cppVar_79485 = (cppVar_79483 == 136);
	if (cppVar_79485) {
	cppVar_79481 = TCON;
	} else {
	BIT_VEC cppVar_79486;
	BIT_VEC cppVar_79487 = PC + 1;
	cppVar_79487 = (cppVar_79487 & cppMask_un_16_);
	BIT_VEC cppVar_79488 = ROM.rd(cppVar_79487);
	bool cppVar_79490 = (cppVar_79488 == 137);
	if (cppVar_79490) {
	cppVar_79486 = TMOD;
	} else {
	BIT_VEC cppVar_79491;
	BIT_VEC cppVar_79492 = PC + 1;
	cppVar_79492 = (cppVar_79492 & cppMask_un_16_);
	BIT_VEC cppVar_79493 = ROM.rd(cppVar_79492);
	bool cppVar_79495 = (cppVar_79493 == 138);
	if (cppVar_79495) {
	cppVar_79491 = TL0;
	} else {
	BIT_VEC cppVar_79496;
	BIT_VEC cppVar_79497 = PC + 1;
	cppVar_79497 = (cppVar_79497 & cppMask_un_16_);
	BIT_VEC cppVar_79498 = ROM.rd(cppVar_79497);
	bool cppVar_79500 = (cppVar_79498 == 140);
	if (cppVar_79500) {
	cppVar_79496 = TH0;
	} else {
	BIT_VEC cppVar_79501;
	BIT_VEC cppVar_79502 = PC + 1;
	cppVar_79502 = (cppVar_79502 & cppMask_un_16_);
	BIT_VEC cppVar_79503 = ROM.rd(cppVar_79502);
	bool cppVar_79505 = (cppVar_79503 == 139);
	if (cppVar_79505) {
	cppVar_79501 = TL1;
	} else {
	BIT_VEC cppVar_79506;
	BIT_VEC cppVar_79507 = PC + 1;
	cppVar_79507 = (cppVar_79507 & cppMask_un_16_);
	BIT_VEC cppVar_79508 = ROM.rd(cppVar_79507);
	bool cppVar_79510 = (cppVar_79508 == 141);
	if (cppVar_79510) {
	cppVar_79506 = TH1;
	} else {
	BIT_VEC cppVar_79511;
	BIT_VEC cppVar_79512 = PC + 1;
	cppVar_79512 = (cppVar_79512 & cppMask_un_16_);
	BIT_VEC cppVar_79513 = ROM.rd(cppVar_79512);
	bool cppVar_79515 = (cppVar_79513 == 144);
	if (cppVar_79515) {
	cppVar_79511 = P1;
	} else {
	BIT_VEC cppVar_79516;
	BIT_VEC cppVar_79517 = PC + 1;
	cppVar_79517 = (cppVar_79517 & cppMask_un_16_);
	BIT_VEC cppVar_79518 = ROM.rd(cppVar_79517);
	bool cppVar_79520 = (cppVar_79518 == 152);
	if (cppVar_79520) {
	cppVar_79516 = SCON;
	} else {
	BIT_VEC cppVar_79521;
	BIT_VEC cppVar_79522 = PC + 1;
	cppVar_79522 = (cppVar_79522 & cppMask_un_16_);
	BIT_VEC cppVar_79523 = ROM.rd(cppVar_79522);
	bool cppVar_79525 = (cppVar_79523 == 153);
	if (cppVar_79525) {
	cppVar_79521 = SBUF;
	} else {
	BIT_VEC cppVar_79526;
	BIT_VEC cppVar_79527 = PC + 1;
	cppVar_79527 = (cppVar_79527 & cppMask_un_16_);
	BIT_VEC cppVar_79528 = ROM.rd(cppVar_79527);
	bool cppVar_79530 = (cppVar_79528 == 160);
	if (cppVar_79530) {
	cppVar_79526 = P2;
	} else {
	BIT_VEC cppVar_79531;
	BIT_VEC cppVar_79532 = PC + 1;
	cppVar_79532 = (cppVar_79532 & cppMask_un_16_);
	BIT_VEC cppVar_79533 = ROM.rd(cppVar_79532);
	bool cppVar_79535 = (cppVar_79533 == 168);
	if (cppVar_79535) {
	cppVar_79531 = IE;
	} else {
	BIT_VEC cppVar_79536;
	BIT_VEC cppVar_79537 = PC + 1;
	cppVar_79537 = (cppVar_79537 & cppMask_un_16_);
	BIT_VEC cppVar_79538 = ROM.rd(cppVar_79537);
	bool cppVar_79540 = (cppVar_79538 == 176);
	if (cppVar_79540) {
	cppVar_79536 = P3;
	} else {
	BIT_VEC cppVar_79541;
	BIT_VEC cppVar_79542 = PC + 1;
	cppVar_79542 = (cppVar_79542 & cppMask_un_16_);
	BIT_VEC cppVar_79543 = ROM.rd(cppVar_79542);
	bool cppVar_79545 = (cppVar_79543 == 184);
	if (cppVar_79545) {
	cppVar_79541 = IP;
	} else {
	BIT_VEC cppVar_79546;
	BIT_VEC cppVar_79547 = PC + 1;
	cppVar_79547 = (cppVar_79547 & cppMask_un_16_);
	BIT_VEC cppVar_79548 = ROM.rd(cppVar_79547);
	bool cppVar_79550 = (cppVar_79548 == 208);
	if (cppVar_79550) {
	cppVar_79546 = PSW;
	} else {
	BIT_VEC cppVar_79551;
	BIT_VEC cppVar_79552 = PC + 1;
	cppVar_79552 = (cppVar_79552 & cppMask_un_16_);
	BIT_VEC cppVar_79553 = ROM.rd(cppVar_79552);
	bool cppVar_79555 = (cppVar_79553 == 224);
	if (cppVar_79555) {
	cppVar_79551 = ACC;
	} else {
	BIT_VEC cppVar_79556;
	BIT_VEC cppVar_79557 = PC + 1;
	cppVar_79557 = (cppVar_79557 & cppMask_un_16_);
	BIT_VEC cppVar_79558 = ROM.rd(cppVar_79557);
	bool cppVar_79560 = (cppVar_79558 == 240);
	if (cppVar_79560) {
	cppVar_79556 = B;
	} else {
	cppVar_79556 = 0;
	}
	cppVar_79551 = cppVar_79556;
	}
	cppVar_79546 = cppVar_79551;
	}
	cppVar_79541 = cppVar_79546;
	}
	cppVar_79536 = cppVar_79541;
	}
	cppVar_79531 = cppVar_79536;
	}
	cppVar_79526 = cppVar_79531;
	}
	cppVar_79521 = cppVar_79526;
	}
	cppVar_79516 = cppVar_79521;
	}
	cppVar_79511 = cppVar_79516;
	}
	cppVar_79506 = cppVar_79511;
	}
	cppVar_79501 = cppVar_79506;
	}
	cppVar_79496 = cppVar_79501;
	}
	cppVar_79491 = cppVar_79496;
	}
	cppVar_79486 = cppVar_79491;
	}
	cppVar_79481 = cppVar_79486;
	}
	cppVar_79476 = cppVar_79481;
	}
	cppVar_79471 = cppVar_79476;
	}
	cppVar_79466 = cppVar_79471;
	}
	cppVar_79461 = cppVar_79466;
	}
	cppVar_79456 = cppVar_79461;
	}
	cppVar_79447 = cppVar_79456;
	}
	BIT_VEC cppVar_79563 = cppVar_79447 - 1;
	cppVar_79563 = (cppVar_79563 & cppMask_un_8_);
	cppVar_79441 = cppVar_79563;
	} else {
	cppVar_79441 = TL0;
	}
	cppVar_79433 = cppVar_79441;
	} else {
	BIT_VEC cppVar_79564;
	BIT_VEC cppVar_79565 = ROM.rd(PC);
	bool cppVar_79567 = (cppVar_79565 == 5);
	if (cppVar_79567) {
	BIT_VEC cppVar_79568;
	BIT_VEC cppVar_79570 = PC + 1;
	cppVar_79570 = (cppVar_79570 & cppMask_un_16_);
	BIT_VEC cppVar_79571 = ROM.rd(cppVar_79570);
	bool cppVar_79573 = (cppVar_79571 == 138);
	if (cppVar_79573) {
	BIT_VEC cppVar_79574;
	BIT_VEC cppVar_79575 = PC + 1;
	cppVar_79575 = (cppVar_79575 & cppMask_un_16_);
	BIT_VEC cppVar_79576 = ROM.rd(cppVar_79575);
	BIT_VEC cppVar_79577 = (cppVar_79576 >> 7) & cppMask_un_1_;
	bool cppVar_79579 = (cppVar_79577 == 0);
	if (cppVar_79579) {
	BIT_VEC cppVar_79580 = PC + 1;
	cppVar_79580 = (cppVar_79580 & cppMask_un_16_);
	BIT_VEC cppVar_79581 = ROM.rd(cppVar_79580);
	BIT_VEC cppVar_79582 = IRAM.rd(cppVar_79581);
	cppVar_79574 = cppVar_79582;
	} else {
	BIT_VEC cppVar_79583;
	BIT_VEC cppVar_79584 = PC + 1;
	cppVar_79584 = (cppVar_79584 & cppMask_un_16_);
	BIT_VEC cppVar_79585 = ROM.rd(cppVar_79584);
	bool cppVar_79587 = (cppVar_79585 == 128);
	if (cppVar_79587) {
	cppVar_79583 = P0;
	} else {
	BIT_VEC cppVar_79588;
	BIT_VEC cppVar_79589 = PC + 1;
	cppVar_79589 = (cppVar_79589 & cppMask_un_16_);
	BIT_VEC cppVar_79590 = ROM.rd(cppVar_79589);
	bool cppVar_79592 = (cppVar_79590 == 129);
	if (cppVar_79592) {
	cppVar_79588 = SP;
	} else {
	BIT_VEC cppVar_79593;
	BIT_VEC cppVar_79594 = PC + 1;
	cppVar_79594 = (cppVar_79594 & cppMask_un_16_);
	BIT_VEC cppVar_79595 = ROM.rd(cppVar_79594);
	bool cppVar_79597 = (cppVar_79595 == 130);
	if (cppVar_79597) {
	cppVar_79593 = DPL;
	} else {
	BIT_VEC cppVar_79598;
	BIT_VEC cppVar_79599 = PC + 1;
	cppVar_79599 = (cppVar_79599 & cppMask_un_16_);
	BIT_VEC cppVar_79600 = ROM.rd(cppVar_79599);
	bool cppVar_79602 = (cppVar_79600 == 131);
	if (cppVar_79602) {
	cppVar_79598 = DPH;
	} else {
	BIT_VEC cppVar_79603;
	BIT_VEC cppVar_79604 = PC + 1;
	cppVar_79604 = (cppVar_79604 & cppMask_un_16_);
	BIT_VEC cppVar_79605 = ROM.rd(cppVar_79604);
	bool cppVar_79607 = (cppVar_79605 == 135);
	if (cppVar_79607) {
	cppVar_79603 = PCON;
	} else {
	BIT_VEC cppVar_79608;
	BIT_VEC cppVar_79609 = PC + 1;
	cppVar_79609 = (cppVar_79609 & cppMask_un_16_);
	BIT_VEC cppVar_79610 = ROM.rd(cppVar_79609);
	bool cppVar_79612 = (cppVar_79610 == 136);
	if (cppVar_79612) {
	cppVar_79608 = TCON;
	} else {
	BIT_VEC cppVar_79613;
	BIT_VEC cppVar_79614 = PC + 1;
	cppVar_79614 = (cppVar_79614 & cppMask_un_16_);
	BIT_VEC cppVar_79615 = ROM.rd(cppVar_79614);
	bool cppVar_79617 = (cppVar_79615 == 137);
	if (cppVar_79617) {
	cppVar_79613 = TMOD;
	} else {
	BIT_VEC cppVar_79618;
	BIT_VEC cppVar_79619 = PC + 1;
	cppVar_79619 = (cppVar_79619 & cppMask_un_16_);
	BIT_VEC cppVar_79620 = ROM.rd(cppVar_79619);
	bool cppVar_79622 = (cppVar_79620 == 138);
	if (cppVar_79622) {
	cppVar_79618 = TL0;
	} else {
	BIT_VEC cppVar_79623;
	BIT_VEC cppVar_79624 = PC + 1;
	cppVar_79624 = (cppVar_79624 & cppMask_un_16_);
	BIT_VEC cppVar_79625 = ROM.rd(cppVar_79624);
	bool cppVar_79627 = (cppVar_79625 == 140);
	if (cppVar_79627) {
	cppVar_79623 = TH0;
	} else {
	BIT_VEC cppVar_79628;
	BIT_VEC cppVar_79629 = PC + 1;
	cppVar_79629 = (cppVar_79629 & cppMask_un_16_);
	BIT_VEC cppVar_79630 = ROM.rd(cppVar_79629);
	bool cppVar_79632 = (cppVar_79630 == 139);
	if (cppVar_79632) {
	cppVar_79628 = TL1;
	} else {
	BIT_VEC cppVar_79633;
	BIT_VEC cppVar_79634 = PC + 1;
	cppVar_79634 = (cppVar_79634 & cppMask_un_16_);
	BIT_VEC cppVar_79635 = ROM.rd(cppVar_79634);
	bool cppVar_79637 = (cppVar_79635 == 141);
	if (cppVar_79637) {
	cppVar_79633 = TH1;
	} else {
	BIT_VEC cppVar_79638;
	BIT_VEC cppVar_79639 = PC + 1;
	cppVar_79639 = (cppVar_79639 & cppMask_un_16_);
	BIT_VEC cppVar_79640 = ROM.rd(cppVar_79639);
	bool cppVar_79642 = (cppVar_79640 == 144);
	if (cppVar_79642) {
	cppVar_79638 = P1;
	} else {
	BIT_VEC cppVar_79643;
	BIT_VEC cppVar_79644 = PC + 1;
	cppVar_79644 = (cppVar_79644 & cppMask_un_16_);
	BIT_VEC cppVar_79645 = ROM.rd(cppVar_79644);
	bool cppVar_79647 = (cppVar_79645 == 152);
	if (cppVar_79647) {
	cppVar_79643 = SCON;
	} else {
	BIT_VEC cppVar_79648;
	BIT_VEC cppVar_79649 = PC + 1;
	cppVar_79649 = (cppVar_79649 & cppMask_un_16_);
	BIT_VEC cppVar_79650 = ROM.rd(cppVar_79649);
	bool cppVar_79652 = (cppVar_79650 == 153);
	if (cppVar_79652) {
	cppVar_79648 = SBUF;
	} else {
	BIT_VEC cppVar_79653;
	BIT_VEC cppVar_79654 = PC + 1;
	cppVar_79654 = (cppVar_79654 & cppMask_un_16_);
	BIT_VEC cppVar_79655 = ROM.rd(cppVar_79654);
	bool cppVar_79657 = (cppVar_79655 == 160);
	if (cppVar_79657) {
	cppVar_79653 = P2;
	} else {
	BIT_VEC cppVar_79658;
	BIT_VEC cppVar_79659 = PC + 1;
	cppVar_79659 = (cppVar_79659 & cppMask_un_16_);
	BIT_VEC cppVar_79660 = ROM.rd(cppVar_79659);
	bool cppVar_79662 = (cppVar_79660 == 168);
	if (cppVar_79662) {
	cppVar_79658 = IE;
	} else {
	BIT_VEC cppVar_79663;
	BIT_VEC cppVar_79664 = PC + 1;
	cppVar_79664 = (cppVar_79664 & cppMask_un_16_);
	BIT_VEC cppVar_79665 = ROM.rd(cppVar_79664);
	bool cppVar_79667 = (cppVar_79665 == 176);
	if (cppVar_79667) {
	cppVar_79663 = P3;
	} else {
	BIT_VEC cppVar_79668;
	BIT_VEC cppVar_79669 = PC + 1;
	cppVar_79669 = (cppVar_79669 & cppMask_un_16_);
	BIT_VEC cppVar_79670 = ROM.rd(cppVar_79669);
	bool cppVar_79672 = (cppVar_79670 == 184);
	if (cppVar_79672) {
	cppVar_79668 = IP;
	} else {
	BIT_VEC cppVar_79673;
	BIT_VEC cppVar_79674 = PC + 1;
	cppVar_79674 = (cppVar_79674 & cppMask_un_16_);
	BIT_VEC cppVar_79675 = ROM.rd(cppVar_79674);
	bool cppVar_79677 = (cppVar_79675 == 208);
	if (cppVar_79677) {
	cppVar_79673 = PSW;
	} else {
	BIT_VEC cppVar_79678;
	BIT_VEC cppVar_79679 = PC + 1;
	cppVar_79679 = (cppVar_79679 & cppMask_un_16_);
	BIT_VEC cppVar_79680 = ROM.rd(cppVar_79679);
	bool cppVar_79682 = (cppVar_79680 == 224);
	if (cppVar_79682) {
	cppVar_79678 = ACC;
	} else {
	BIT_VEC cppVar_79683;
	BIT_VEC cppVar_79684 = PC + 1;
	cppVar_79684 = (cppVar_79684 & cppMask_un_16_);
	BIT_VEC cppVar_79685 = ROM.rd(cppVar_79684);
	bool cppVar_79687 = (cppVar_79685 == 240);
	if (cppVar_79687) {
	cppVar_79683 = B;
	} else {
	cppVar_79683 = 0;
	}
	cppVar_79678 = cppVar_79683;
	}
	cppVar_79673 = cppVar_79678;
	}
	cppVar_79668 = cppVar_79673;
	}
	cppVar_79663 = cppVar_79668;
	}
	cppVar_79658 = cppVar_79663;
	}
	cppVar_79653 = cppVar_79658;
	}
	cppVar_79648 = cppVar_79653;
	}
	cppVar_79643 = cppVar_79648;
	}
	cppVar_79638 = cppVar_79643;
	}
	cppVar_79633 = cppVar_79638;
	}
	cppVar_79628 = cppVar_79633;
	}
	cppVar_79623 = cppVar_79628;
	}
	cppVar_79618 = cppVar_79623;
	}
	cppVar_79613 = cppVar_79618;
	}
	cppVar_79608 = cppVar_79613;
	}
	cppVar_79603 = cppVar_79608;
	}
	cppVar_79598 = cppVar_79603;
	}
	cppVar_79593 = cppVar_79598;
	}
	cppVar_79588 = cppVar_79593;
	}
	cppVar_79583 = cppVar_79588;
	}
	cppVar_79574 = cppVar_79583;
	}
	BIT_VEC cppVar_79690 = cppVar_79574 + 1;
	cppVar_79690 = (cppVar_79690 & cppMask_un_8_);
	cppVar_79568 = cppVar_79690;
	} else {
	cppVar_79568 = TL0;
	}
	cppVar_79564 = cppVar_79568;
	} else {
	cppVar_79564 = TL0;
	}
	cppVar_79433 = cppVar_79564;
	}
	cppVar_79307 = cppVar_79433;
	}
	cppVar_79178 = cppVar_79307;
	}
	cppVar_79052 = cppVar_79178;
	}
	cppVar_78923 = cppVar_79052;
	}
	cppVar_78797 = cppVar_78923;
	}
	cppVar_78668 = cppVar_78797;
	}
	cppVar_78655 = cppVar_78668;
	}
	cppVar_78529 = cppVar_78655;
	}
	cppVar_78512 = cppVar_78529;
	}
	cppVar_78495 = cppVar_78512;
	}
	cppVar_78345 = cppVar_78495;
	}
	cppVar_78195 = cppVar_78345;
	}
	cppVar_78045 = cppVar_78195;
	}
	cppVar_77895 = cppVar_78045;
	}
	cppVar_77745 = cppVar_77895;
	}
	cppVar_77595 = cppVar_77745;
	}
	cppVar_77445 = cppVar_77595;
	}
	cppVar_77295 = cppVar_77445;
	}
	cppVar_77281 = cppVar_77295;
	}
	cppVar_77270 = cppVar_77281;
	}
	return cppVar_77270;
}
