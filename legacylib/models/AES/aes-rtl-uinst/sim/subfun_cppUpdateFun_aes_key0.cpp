#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_key0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_267;
	bool cppVar_269 = (aes_state == 0);
	bool cppVar_271 = (cmd == 2);
	bool cppVar_272 = cppVar_269 && cppVar_271;
	bool cppVar_274 = (cmdaddr == 65327);
	bool cppVar_275 = cppVar_272 && cppVar_274;
	if (cppVar_275) {
	BIT_VEC cppVar_276 = (aes_key0 >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_277 = (cmddata << 120) | cppVar_276;
	cppVar_277 = (cppVar_277 & cppMask_un_128_);
	cppVar_267 = cppVar_277;
	} else {
	BIT_VEC cppVar_278;
	bool cppVar_280 = (aes_state == 0);
	bool cppVar_282 = (cmd == 2);
	bool cppVar_283 = cppVar_280 && cppVar_282;
	bool cppVar_285 = (cmdaddr == 65326);
	bool cppVar_286 = cppVar_283 && cppVar_285;
	if (cppVar_286) {
	BIT_VEC cppVar_287 = (aes_key0 >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_288 = (cppVar_287 << 8) | cmddata;
	cppVar_288 = (cppVar_288 & cppMask_un_16_);
	BIT_VEC cppVar_289 = (aes_key0 >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_290 = (cppVar_288 << 112) | cppVar_289;
	cppVar_290 = (cppVar_290 & cppMask_un_128_);
	cppVar_278 = cppVar_290;
	} else {
	BIT_VEC cppVar_291;
	bool cppVar_293 = (aes_state == 0);
	bool cppVar_295 = (cmd == 2);
	bool cppVar_296 = cppVar_293 && cppVar_295;
	bool cppVar_298 = (cmdaddr == 65325);
	bool cppVar_299 = cppVar_296 && cppVar_298;
	if (cppVar_299) {
	BIT_VEC cppVar_300 = (aes_key0 >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_301 = (cppVar_300 << 8) | cmddata;
	cppVar_301 = (cppVar_301 & cppMask_un_24_);
	BIT_VEC cppVar_302 = (aes_key0 >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_303 = (cppVar_301 << 104) | cppVar_302;
	cppVar_303 = (cppVar_303 & cppMask_un_128_);
	cppVar_291 = cppVar_303;
	} else {
	BIT_VEC cppVar_304;
	bool cppVar_306 = (aes_state == 0);
	bool cppVar_308 = (cmd == 2);
	bool cppVar_309 = cppVar_306 && cppVar_308;
	bool cppVar_311 = (cmdaddr == 65324);
	bool cppVar_312 = cppVar_309 && cppVar_311;
	if (cppVar_312) {
	BIT_VEC cppVar_313 = (aes_key0 >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_314 = (cppVar_313 << 8) | cmddata;
	cppVar_314 = (cppVar_314 & cppMask_un_32_);
	BIT_VEC cppVar_315 = (aes_key0 >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_316 = (cppVar_314 << 96) | cppVar_315;
	cppVar_316 = (cppVar_316 & cppMask_un_128_);
	cppVar_304 = cppVar_316;
	} else {
	BIT_VEC cppVar_317;
	bool cppVar_319 = (aes_state == 0);
	bool cppVar_321 = (cmd == 2);
	bool cppVar_322 = cppVar_319 && cppVar_321;
	bool cppVar_324 = (cmdaddr == 65323);
	bool cppVar_325 = cppVar_322 && cppVar_324;
	if (cppVar_325) {
	BIT_VEC cppVar_326 = (aes_key0 >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_327 = (cppVar_326 << 8) | cmddata;
	cppVar_327 = (cppVar_327 & cppMask_un_40_);
	BIT_VEC cppVar_328 = (aes_key0 >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_329 = (cppVar_327 << 88) | cppVar_328;
	cppVar_329 = (cppVar_329 & cppMask_un_128_);
	cppVar_317 = cppVar_329;
	} else {
	BIT_VEC cppVar_330;
	bool cppVar_332 = (aes_state == 0);
	bool cppVar_334 = (cmd == 2);
	bool cppVar_335 = cppVar_332 && cppVar_334;
	bool cppVar_337 = (cmdaddr == 65322);
	bool cppVar_338 = cppVar_335 && cppVar_337;
	if (cppVar_338) {
	BIT_VEC cppVar_339 = (aes_key0 >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_340 = (cppVar_339 << 8) | cmddata;
	cppVar_340 = (cppVar_340 & cppMask_un_48_);
	BIT_VEC cppVar_341 = (aes_key0 >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_342 = (cppVar_340 << 80) | cppVar_341;
	cppVar_342 = (cppVar_342 & cppMask_un_128_);
	cppVar_330 = cppVar_342;
	} else {
	BIT_VEC cppVar_343;
	bool cppVar_345 = (aes_state == 0);
	bool cppVar_347 = (cmd == 2);
	bool cppVar_348 = cppVar_345 && cppVar_347;
	bool cppVar_350 = (cmdaddr == 65321);
	bool cppVar_351 = cppVar_348 && cppVar_350;
	if (cppVar_351) {
	BIT_VEC cppVar_352 = (aes_key0 >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_353 = (cppVar_352 << 8) | cmddata;
	cppVar_353 = (cppVar_353 & cppMask_un_56_);
	BIT_VEC cppVar_354 = (aes_key0 >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_355 = (cppVar_353 << 72) | cppVar_354;
	cppVar_355 = (cppVar_355 & cppMask_un_128_);
	cppVar_343 = cppVar_355;
	} else {
	BIT_VEC cppVar_356;
	bool cppVar_358 = (aes_state == 0);
	bool cppVar_360 = (cmd == 2);
	bool cppVar_361 = cppVar_358 && cppVar_360;
	bool cppVar_363 = (cmdaddr == 65320);
	bool cppVar_364 = cppVar_361 && cppVar_363;
	if (cppVar_364) {
	BIT_VEC cppVar_365 = (aes_key0 >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_366 = (cppVar_365 << 8) | cmddata;
	cppVar_366 = (cppVar_366 & cppMask_un_64_);
	BIT_VEC cppVar_367 = (aes_key0 >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_368 = (cppVar_366 << 64) | cppVar_367;
	cppVar_368 = (cppVar_368 & cppMask_un_128_);
	cppVar_356 = cppVar_368;
	} else {
	BIT_VEC cppVar_369;
	bool cppVar_371 = (aes_state == 0);
	bool cppVar_373 = (cmd == 2);
	bool cppVar_374 = cppVar_371 && cppVar_373;
	bool cppVar_376 = (cmdaddr == 65319);
	bool cppVar_377 = cppVar_374 && cppVar_376;
	if (cppVar_377) {
	BIT_VEC cppVar_378 = (aes_key0 >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_379 = (cppVar_378 << 8) | cmddata;
	cppVar_379 = (cppVar_379 & cppMask_un_72_);
	BIT_VEC cppVar_380 = (aes_key0 >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_381 = (cppVar_379 << 56) | cppVar_380;
	cppVar_381 = (cppVar_381 & cppMask_un_128_);
	cppVar_369 = cppVar_381;
	} else {
	BIT_VEC cppVar_382;
	bool cppVar_384 = (aes_state == 0);
	bool cppVar_386 = (cmd == 2);
	bool cppVar_387 = cppVar_384 && cppVar_386;
	bool cppVar_389 = (cmdaddr == 65318);
	bool cppVar_390 = cppVar_387 && cppVar_389;
	if (cppVar_390) {
	BIT_VEC cppVar_391 = (aes_key0 >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_392 = (cppVar_391 << 8) | cmddata;
	cppVar_392 = (cppVar_392 & cppMask_un_80_);
	BIT_VEC cppVar_393 = (aes_key0 >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_394 = (cppVar_392 << 48) | cppVar_393;
	cppVar_394 = (cppVar_394 & cppMask_un_128_);
	cppVar_382 = cppVar_394;
	} else {
	BIT_VEC cppVar_395;
	bool cppVar_397 = (aes_state == 0);
	bool cppVar_399 = (cmd == 2);
	bool cppVar_400 = cppVar_397 && cppVar_399;
	bool cppVar_402 = (cmdaddr == 65317);
	bool cppVar_403 = cppVar_400 && cppVar_402;
	if (cppVar_403) {
	BIT_VEC cppVar_404 = (aes_key0 >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_405 = (cppVar_404 << 8) | cmddata;
	cppVar_405 = (cppVar_405 & cppMask_un_88_);
	BIT_VEC cppVar_406 = (aes_key0 >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_407 = (cppVar_405 << 40) | cppVar_406;
	cppVar_407 = (cppVar_407 & cppMask_un_128_);
	cppVar_395 = cppVar_407;
	} else {
	BIT_VEC cppVar_408;
	bool cppVar_410 = (aes_state == 0);
	bool cppVar_412 = (cmd == 2);
	bool cppVar_413 = cppVar_410 && cppVar_412;
	bool cppVar_415 = (cmdaddr == 65316);
	bool cppVar_416 = cppVar_413 && cppVar_415;
	if (cppVar_416) {
	BIT_VEC cppVar_417 = (aes_key0 >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_418 = (cppVar_417 << 8) | cmddata;
	cppVar_418 = (cppVar_418 & cppMask_un_96_);
	BIT_VEC cppVar_419 = (aes_key0 >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_420 = (cppVar_418 << 32) | cppVar_419;
	cppVar_420 = (cppVar_420 & cppMask_un_128_);
	cppVar_408 = cppVar_420;
	} else {
	BIT_VEC cppVar_421;
	bool cppVar_423 = (aes_state == 0);
	bool cppVar_425 = (cmd == 2);
	bool cppVar_426 = cppVar_423 && cppVar_425;
	bool cppVar_428 = (cmdaddr == 65315);
	bool cppVar_429 = cppVar_426 && cppVar_428;
	if (cppVar_429) {
	BIT_VEC cppVar_430 = (aes_key0 >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_431 = (cppVar_430 << 8) | cmddata;
	cppVar_431 = (cppVar_431 & cppMask_un_104_);
	BIT_VEC cppVar_432 = (aes_key0 >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_433 = (cppVar_431 << 24) | cppVar_432;
	cppVar_433 = (cppVar_433 & cppMask_un_128_);
	cppVar_421 = cppVar_433;
	} else {
	BIT_VEC cppVar_434;
	bool cppVar_436 = (aes_state == 0);
	bool cppVar_438 = (cmd == 2);
	bool cppVar_439 = cppVar_436 && cppVar_438;
	bool cppVar_441 = (cmdaddr == 65314);
	bool cppVar_442 = cppVar_439 && cppVar_441;
	if (cppVar_442) {
	BIT_VEC cppVar_443 = (aes_key0 >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_444 = (cppVar_443 << 8) | cmddata;
	cppVar_444 = (cppVar_444 & cppMask_un_112_);
	BIT_VEC cppVar_445 = (aes_key0 >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_446 = (cppVar_444 << 16) | cppVar_445;
	cppVar_446 = (cppVar_446 & cppMask_un_128_);
	cppVar_434 = cppVar_446;
	} else {
	BIT_VEC cppVar_447;
	bool cppVar_449 = (aes_state == 0);
	bool cppVar_451 = (cmd == 2);
	bool cppVar_452 = cppVar_449 && cppVar_451;
	bool cppVar_454 = (cmdaddr == 65313);
	bool cppVar_455 = cppVar_452 && cppVar_454;
	if (cppVar_455) {
	BIT_VEC cppVar_456 = (aes_key0 >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_457 = (cppVar_456 << 8) | cmddata;
	cppVar_457 = (cppVar_457 & cppMask_un_120_);
	BIT_VEC cppVar_458 = (aes_key0 >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_459 = (cppVar_457 << 8) | cppVar_458;
	cppVar_459 = (cppVar_459 & cppMask_un_128_);
	cppVar_447 = cppVar_459;
	} else {
	BIT_VEC cppVar_460;
	bool cppVar_462 = (aes_state == 0);
	bool cppVar_464 = (cmd == 2);
	bool cppVar_465 = cppVar_462 && cppVar_464;
	bool cppVar_467 = (cmdaddr == 65312);
	bool cppVar_468 = cppVar_465 && cppVar_467;
	if (cppVar_468) {
	BIT_VEC cppVar_469 = (aes_key0 >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_470 = (cppVar_469 << 8) | cmddata;
	cppVar_470 = (cppVar_470 & cppMask_un_128_);
	cppVar_460 = cppVar_470;
	} else {
	cppVar_460 = aes_key0;
	}
	cppVar_447 = cppVar_460;
	}
	cppVar_434 = cppVar_447;
	}
	cppVar_421 = cppVar_434;
	}
	cppVar_408 = cppVar_421;
	}
	cppVar_395 = cppVar_408;
	}
	cppVar_382 = cppVar_395;
	}
	cppVar_369 = cppVar_382;
	}
	cppVar_356 = cppVar_369;
	}
	cppVar_343 = cppVar_356;
	}
	cppVar_330 = cppVar_343;
	}
	cppVar_317 = cppVar_330;
	}
	cppVar_304 = cppVar_317;
	}
	cppVar_291 = cppVar_304;
	}
	cppVar_278 = cppVar_291;
	}
	cppVar_267 = cppVar_278;
	}
	return cppVar_267;
}
