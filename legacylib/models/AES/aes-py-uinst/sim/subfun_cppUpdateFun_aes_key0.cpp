#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_key0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_265;
	bool cppVar_267 = (aes_state == 0);
	bool cppVar_269 = (cmd == 2);
	bool cppVar_270 = cppVar_267 && cppVar_269;
	bool cppVar_272 = (cmdaddr == 65327);
	bool cppVar_273 = cppVar_270 && cppVar_272;
	if (cppVar_273) {
	BIT_VEC cppVar_274 = (aes_key0 >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_275 = (cmddata << 120) | cppVar_274;
	cppVar_275 = (cppVar_275 & cppMask_un_128_);
	cppVar_265 = cppVar_275;
	} else {
	BIT_VEC cppVar_276;
	bool cppVar_278 = (aes_state == 0);
	bool cppVar_280 = (cmd == 2);
	bool cppVar_281 = cppVar_278 && cppVar_280;
	bool cppVar_283 = (cmdaddr == 65326);
	bool cppVar_284 = cppVar_281 && cppVar_283;
	if (cppVar_284) {
	BIT_VEC cppVar_285 = (aes_key0 >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_286 = (cppVar_285 << 8) | cmddata;
	cppVar_286 = (cppVar_286 & cppMask_un_16_);
	BIT_VEC cppVar_287 = (aes_key0 >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_288 = (cppVar_286 << 112) | cppVar_287;
	cppVar_288 = (cppVar_288 & cppMask_un_128_);
	cppVar_276 = cppVar_288;
	} else {
	BIT_VEC cppVar_289;
	bool cppVar_291 = (aes_state == 0);
	bool cppVar_293 = (cmd == 2);
	bool cppVar_294 = cppVar_291 && cppVar_293;
	bool cppVar_296 = (cmdaddr == 65325);
	bool cppVar_297 = cppVar_294 && cppVar_296;
	if (cppVar_297) {
	BIT_VEC cppVar_298 = (aes_key0 >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_299 = (cppVar_298 << 8) | cmddata;
	cppVar_299 = (cppVar_299 & cppMask_un_24_);
	BIT_VEC cppVar_300 = (aes_key0 >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_301 = (cppVar_299 << 104) | cppVar_300;
	cppVar_301 = (cppVar_301 & cppMask_un_128_);
	cppVar_289 = cppVar_301;
	} else {
	BIT_VEC cppVar_302;
	bool cppVar_304 = (aes_state == 0);
	bool cppVar_306 = (cmd == 2);
	bool cppVar_307 = cppVar_304 && cppVar_306;
	bool cppVar_309 = (cmdaddr == 65324);
	bool cppVar_310 = cppVar_307 && cppVar_309;
	if (cppVar_310) {
	BIT_VEC cppVar_311 = (aes_key0 >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_312 = (cppVar_311 << 8) | cmddata;
	cppVar_312 = (cppVar_312 & cppMask_un_32_);
	BIT_VEC cppVar_313 = (aes_key0 >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_314 = (cppVar_312 << 96) | cppVar_313;
	cppVar_314 = (cppVar_314 & cppMask_un_128_);
	cppVar_302 = cppVar_314;
	} else {
	BIT_VEC cppVar_315;
	bool cppVar_317 = (aes_state == 0);
	bool cppVar_319 = (cmd == 2);
	bool cppVar_320 = cppVar_317 && cppVar_319;
	bool cppVar_322 = (cmdaddr == 65323);
	bool cppVar_323 = cppVar_320 && cppVar_322;
	if (cppVar_323) {
	BIT_VEC cppVar_324 = (aes_key0 >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_325 = (cppVar_324 << 8) | cmddata;
	cppVar_325 = (cppVar_325 & cppMask_un_40_);
	BIT_VEC cppVar_326 = (aes_key0 >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_327 = (cppVar_325 << 88) | cppVar_326;
	cppVar_327 = (cppVar_327 & cppMask_un_128_);
	cppVar_315 = cppVar_327;
	} else {
	BIT_VEC cppVar_328;
	bool cppVar_330 = (aes_state == 0);
	bool cppVar_332 = (cmd == 2);
	bool cppVar_333 = cppVar_330 && cppVar_332;
	bool cppVar_335 = (cmdaddr == 65322);
	bool cppVar_336 = cppVar_333 && cppVar_335;
	if (cppVar_336) {
	BIT_VEC cppVar_337 = (aes_key0 >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_338 = (cppVar_337 << 8) | cmddata;
	cppVar_338 = (cppVar_338 & cppMask_un_48_);
	BIT_VEC cppVar_339 = (aes_key0 >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_340 = (cppVar_338 << 80) | cppVar_339;
	cppVar_340 = (cppVar_340 & cppMask_un_128_);
	cppVar_328 = cppVar_340;
	} else {
	BIT_VEC cppVar_341;
	bool cppVar_343 = (aes_state == 0);
	bool cppVar_345 = (cmd == 2);
	bool cppVar_346 = cppVar_343 && cppVar_345;
	bool cppVar_348 = (cmdaddr == 65321);
	bool cppVar_349 = cppVar_346 && cppVar_348;
	if (cppVar_349) {
	BIT_VEC cppVar_350 = (aes_key0 >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_351 = (cppVar_350 << 8) | cmddata;
	cppVar_351 = (cppVar_351 & cppMask_un_56_);
	BIT_VEC cppVar_352 = (aes_key0 >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_353 = (cppVar_351 << 72) | cppVar_352;
	cppVar_353 = (cppVar_353 & cppMask_un_128_);
	cppVar_341 = cppVar_353;
	} else {
	BIT_VEC cppVar_354;
	bool cppVar_356 = (aes_state == 0);
	bool cppVar_358 = (cmd == 2);
	bool cppVar_359 = cppVar_356 && cppVar_358;
	bool cppVar_361 = (cmdaddr == 65320);
	bool cppVar_362 = cppVar_359 && cppVar_361;
	if (cppVar_362) {
	BIT_VEC cppVar_363 = (aes_key0 >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_364 = (cppVar_363 << 8) | cmddata;
	cppVar_364 = (cppVar_364 & cppMask_un_64_);
	BIT_VEC cppVar_365 = (aes_key0 >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_366 = (cppVar_364 << 64) | cppVar_365;
	cppVar_366 = (cppVar_366 & cppMask_un_128_);
	cppVar_354 = cppVar_366;
	} else {
	BIT_VEC cppVar_367;
	bool cppVar_369 = (aes_state == 0);
	bool cppVar_371 = (cmd == 2);
	bool cppVar_372 = cppVar_369 && cppVar_371;
	bool cppVar_374 = (cmdaddr == 65319);
	bool cppVar_375 = cppVar_372 && cppVar_374;
	if (cppVar_375) {
	BIT_VEC cppVar_376 = (aes_key0 >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_377 = (cppVar_376 << 8) | cmddata;
	cppVar_377 = (cppVar_377 & cppMask_un_72_);
	BIT_VEC cppVar_378 = (aes_key0 >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_379 = (cppVar_377 << 56) | cppVar_378;
	cppVar_379 = (cppVar_379 & cppMask_un_128_);
	cppVar_367 = cppVar_379;
	} else {
	BIT_VEC cppVar_380;
	bool cppVar_382 = (aes_state == 0);
	bool cppVar_384 = (cmd == 2);
	bool cppVar_385 = cppVar_382 && cppVar_384;
	bool cppVar_387 = (cmdaddr == 65318);
	bool cppVar_388 = cppVar_385 && cppVar_387;
	if (cppVar_388) {
	BIT_VEC cppVar_389 = (aes_key0 >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_390 = (cppVar_389 << 8) | cmddata;
	cppVar_390 = (cppVar_390 & cppMask_un_80_);
	BIT_VEC cppVar_391 = (aes_key0 >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_392 = (cppVar_390 << 48) | cppVar_391;
	cppVar_392 = (cppVar_392 & cppMask_un_128_);
	cppVar_380 = cppVar_392;
	} else {
	BIT_VEC cppVar_393;
	bool cppVar_395 = (aes_state == 0);
	bool cppVar_397 = (cmd == 2);
	bool cppVar_398 = cppVar_395 && cppVar_397;
	bool cppVar_400 = (cmdaddr == 65317);
	bool cppVar_401 = cppVar_398 && cppVar_400;
	if (cppVar_401) {
	BIT_VEC cppVar_402 = (aes_key0 >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_403 = (cppVar_402 << 8) | cmddata;
	cppVar_403 = (cppVar_403 & cppMask_un_88_);
	BIT_VEC cppVar_404 = (aes_key0 >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_405 = (cppVar_403 << 40) | cppVar_404;
	cppVar_405 = (cppVar_405 & cppMask_un_128_);
	cppVar_393 = cppVar_405;
	} else {
	BIT_VEC cppVar_406;
	bool cppVar_408 = (aes_state == 0);
	bool cppVar_410 = (cmd == 2);
	bool cppVar_411 = cppVar_408 && cppVar_410;
	bool cppVar_413 = (cmdaddr == 65316);
	bool cppVar_414 = cppVar_411 && cppVar_413;
	if (cppVar_414) {
	BIT_VEC cppVar_415 = (aes_key0 >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_416 = (cppVar_415 << 8) | cmddata;
	cppVar_416 = (cppVar_416 & cppMask_un_96_);
	BIT_VEC cppVar_417 = (aes_key0 >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_418 = (cppVar_416 << 32) | cppVar_417;
	cppVar_418 = (cppVar_418 & cppMask_un_128_);
	cppVar_406 = cppVar_418;
	} else {
	BIT_VEC cppVar_419;
	bool cppVar_421 = (aes_state == 0);
	bool cppVar_423 = (cmd == 2);
	bool cppVar_424 = cppVar_421 && cppVar_423;
	bool cppVar_426 = (cmdaddr == 65315);
	bool cppVar_427 = cppVar_424 && cppVar_426;
	if (cppVar_427) {
	BIT_VEC cppVar_428 = (aes_key0 >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_429 = (cppVar_428 << 8) | cmddata;
	cppVar_429 = (cppVar_429 & cppMask_un_104_);
	BIT_VEC cppVar_430 = (aes_key0 >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_431 = (cppVar_429 << 24) | cppVar_430;
	cppVar_431 = (cppVar_431 & cppMask_un_128_);
	cppVar_419 = cppVar_431;
	} else {
	BIT_VEC cppVar_432;
	bool cppVar_434 = (aes_state == 0);
	bool cppVar_436 = (cmd == 2);
	bool cppVar_437 = cppVar_434 && cppVar_436;
	bool cppVar_439 = (cmdaddr == 65314);
	bool cppVar_440 = cppVar_437 && cppVar_439;
	if (cppVar_440) {
	BIT_VEC cppVar_441 = (aes_key0 >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_442 = (cppVar_441 << 8) | cmddata;
	cppVar_442 = (cppVar_442 & cppMask_un_112_);
	BIT_VEC cppVar_443 = (aes_key0 >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_444 = (cppVar_442 << 16) | cppVar_443;
	cppVar_444 = (cppVar_444 & cppMask_un_128_);
	cppVar_432 = cppVar_444;
	} else {
	BIT_VEC cppVar_445;
	bool cppVar_447 = (aes_state == 0);
	bool cppVar_449 = (cmd == 2);
	bool cppVar_450 = cppVar_447 && cppVar_449;
	bool cppVar_452 = (cmdaddr == 65313);
	bool cppVar_453 = cppVar_450 && cppVar_452;
	if (cppVar_453) {
	BIT_VEC cppVar_454 = (aes_key0 >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_455 = (cppVar_454 << 8) | cmddata;
	cppVar_455 = (cppVar_455 & cppMask_un_120_);
	BIT_VEC cppVar_456 = (aes_key0 >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_457 = (cppVar_455 << 8) | cppVar_456;
	cppVar_457 = (cppVar_457 & cppMask_un_128_);
	cppVar_445 = cppVar_457;
	} else {
	BIT_VEC cppVar_458;
	bool cppVar_460 = (aes_state == 0);
	bool cppVar_462 = (cmd == 2);
	bool cppVar_463 = cppVar_460 && cppVar_462;
	bool cppVar_465 = (cmdaddr == 65312);
	bool cppVar_466 = cppVar_463 && cppVar_465;
	if (cppVar_466) {
	BIT_VEC cppVar_467 = (aes_key0 >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_468 = (cppVar_467 << 8) | cmddata;
	cppVar_468 = (cppVar_468 & cppMask_un_128_);
	cppVar_458 = cppVar_468;
	} else {
	cppVar_458 = aes_key0;
	}
	cppVar_445 = cppVar_458;
	}
	cppVar_432 = cppVar_445;
	}
	cppVar_419 = cppVar_432;
	}
	cppVar_406 = cppVar_419;
	}
	cppVar_393 = cppVar_406;
	}
	cppVar_380 = cppVar_393;
	}
	cppVar_367 = cppVar_380;
	}
	cppVar_354 = cppVar_367;
	}
	cppVar_341 = cppVar_354;
	}
	cppVar_328 = cppVar_341;
	}
	cppVar_315 = cppVar_328;
	}
	cppVar_302 = cppVar_315;
	}
	cppVar_289 = cppVar_302;
	}
	cppVar_276 = cppVar_289;
	}
	cppVar_265 = cppVar_276;
	}
	return cppVar_265;
}
