#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_key0(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_248;
	bool cppVar_250 = (aes_state == 0);
	bool cppVar_252 = (cmd == 2);
	bool cppVar_253 = cppVar_250 && cppVar_252;
	bool cppVar_255 = (cmdaddr == 65327);
	bool cppVar_256 = cppVar_253 && cppVar_255;
	if (cppVar_256) {
	BIT_VEC cppVar_257 = (aes_key0 >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_258 = (cmddata << 120) | cppVar_257;
	cppVar_258 = (cppVar_258 & cppMask_un_128_);
	cppVar_248 = cppVar_258;
	} else {
	BIT_VEC cppVar_259;
	bool cppVar_261 = (aes_state == 0);
	bool cppVar_263 = (cmd == 2);
	bool cppVar_264 = cppVar_261 && cppVar_263;
	bool cppVar_266 = (cmdaddr == 65326);
	bool cppVar_267 = cppVar_264 && cppVar_266;
	if (cppVar_267) {
	BIT_VEC cppVar_268 = (aes_key0 >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_269 = (cppVar_268 << 8) | cmddata;
	cppVar_269 = (cppVar_269 & cppMask_un_16_);
	BIT_VEC cppVar_270 = (aes_key0 >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_271 = (cppVar_269 << 112) | cppVar_270;
	cppVar_271 = (cppVar_271 & cppMask_un_128_);
	cppVar_259 = cppVar_271;
	} else {
	BIT_VEC cppVar_272;
	bool cppVar_274 = (aes_state == 0);
	bool cppVar_276 = (cmd == 2);
	bool cppVar_277 = cppVar_274 && cppVar_276;
	bool cppVar_279 = (cmdaddr == 65325);
	bool cppVar_280 = cppVar_277 && cppVar_279;
	if (cppVar_280) {
	BIT_VEC cppVar_281 = (aes_key0 >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_282 = (cppVar_281 << 8) | cmddata;
	cppVar_282 = (cppVar_282 & cppMask_un_24_);
	BIT_VEC cppVar_283 = (aes_key0 >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_284 = (cppVar_282 << 104) | cppVar_283;
	cppVar_284 = (cppVar_284 & cppMask_un_128_);
	cppVar_272 = cppVar_284;
	} else {
	BIT_VEC cppVar_285;
	bool cppVar_287 = (aes_state == 0);
	bool cppVar_289 = (cmd == 2);
	bool cppVar_290 = cppVar_287 && cppVar_289;
	bool cppVar_292 = (cmdaddr == 65324);
	bool cppVar_293 = cppVar_290 && cppVar_292;
	if (cppVar_293) {
	BIT_VEC cppVar_294 = (aes_key0 >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_295 = (cppVar_294 << 8) | cmddata;
	cppVar_295 = (cppVar_295 & cppMask_un_32_);
	BIT_VEC cppVar_296 = (aes_key0 >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_297 = (cppVar_295 << 96) | cppVar_296;
	cppVar_297 = (cppVar_297 & cppMask_un_128_);
	cppVar_285 = cppVar_297;
	} else {
	BIT_VEC cppVar_298;
	bool cppVar_300 = (aes_state == 0);
	bool cppVar_302 = (cmd == 2);
	bool cppVar_303 = cppVar_300 && cppVar_302;
	bool cppVar_305 = (cmdaddr == 65323);
	bool cppVar_306 = cppVar_303 && cppVar_305;
	if (cppVar_306) {
	BIT_VEC cppVar_307 = (aes_key0 >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_308 = (cppVar_307 << 8) | cmddata;
	cppVar_308 = (cppVar_308 & cppMask_un_40_);
	BIT_VEC cppVar_309 = (aes_key0 >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_310 = (cppVar_308 << 88) | cppVar_309;
	cppVar_310 = (cppVar_310 & cppMask_un_128_);
	cppVar_298 = cppVar_310;
	} else {
	BIT_VEC cppVar_311;
	bool cppVar_313 = (aes_state == 0);
	bool cppVar_315 = (cmd == 2);
	bool cppVar_316 = cppVar_313 && cppVar_315;
	bool cppVar_318 = (cmdaddr == 65322);
	bool cppVar_319 = cppVar_316 && cppVar_318;
	if (cppVar_319) {
	BIT_VEC cppVar_320 = (aes_key0 >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_321 = (cppVar_320 << 8) | cmddata;
	cppVar_321 = (cppVar_321 & cppMask_un_48_);
	BIT_VEC cppVar_322 = (aes_key0 >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_323 = (cppVar_321 << 80) | cppVar_322;
	cppVar_323 = (cppVar_323 & cppMask_un_128_);
	cppVar_311 = cppVar_323;
	} else {
	BIT_VEC cppVar_324;
	bool cppVar_326 = (aes_state == 0);
	bool cppVar_328 = (cmd == 2);
	bool cppVar_329 = cppVar_326 && cppVar_328;
	bool cppVar_331 = (cmdaddr == 65321);
	bool cppVar_332 = cppVar_329 && cppVar_331;
	if (cppVar_332) {
	BIT_VEC cppVar_333 = (aes_key0 >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_334 = (cppVar_333 << 8) | cmddata;
	cppVar_334 = (cppVar_334 & cppMask_un_56_);
	BIT_VEC cppVar_335 = (aes_key0 >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_336 = (cppVar_334 << 72) | cppVar_335;
	cppVar_336 = (cppVar_336 & cppMask_un_128_);
	cppVar_324 = cppVar_336;
	} else {
	BIT_VEC cppVar_337;
	bool cppVar_339 = (aes_state == 0);
	bool cppVar_341 = (cmd == 2);
	bool cppVar_342 = cppVar_339 && cppVar_341;
	bool cppVar_344 = (cmdaddr == 65320);
	bool cppVar_345 = cppVar_342 && cppVar_344;
	if (cppVar_345) {
	BIT_VEC cppVar_346 = (aes_key0 >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_347 = (cppVar_346 << 8) | cmddata;
	cppVar_347 = (cppVar_347 & cppMask_un_64_);
	BIT_VEC cppVar_348 = (aes_key0 >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_349 = (cppVar_347 << 64) | cppVar_348;
	cppVar_349 = (cppVar_349 & cppMask_un_128_);
	cppVar_337 = cppVar_349;
	} else {
	BIT_VEC cppVar_350;
	bool cppVar_352 = (aes_state == 0);
	bool cppVar_354 = (cmd == 2);
	bool cppVar_355 = cppVar_352 && cppVar_354;
	bool cppVar_357 = (cmdaddr == 65319);
	bool cppVar_358 = cppVar_355 && cppVar_357;
	if (cppVar_358) {
	BIT_VEC cppVar_359 = (aes_key0 >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_360 = (cppVar_359 << 8) | cmddata;
	cppVar_360 = (cppVar_360 & cppMask_un_72_);
	BIT_VEC cppVar_361 = (aes_key0 >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_362 = (cppVar_360 << 56) | cppVar_361;
	cppVar_362 = (cppVar_362 & cppMask_un_128_);
	cppVar_350 = cppVar_362;
	} else {
	BIT_VEC cppVar_363;
	bool cppVar_365 = (aes_state == 0);
	bool cppVar_367 = (cmd == 2);
	bool cppVar_368 = cppVar_365 && cppVar_367;
	bool cppVar_370 = (cmdaddr == 65318);
	bool cppVar_371 = cppVar_368 && cppVar_370;
	if (cppVar_371) {
	BIT_VEC cppVar_372 = (aes_key0 >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_373 = (cppVar_372 << 8) | cmddata;
	cppVar_373 = (cppVar_373 & cppMask_un_80_);
	BIT_VEC cppVar_374 = (aes_key0 >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_375 = (cppVar_373 << 48) | cppVar_374;
	cppVar_375 = (cppVar_375 & cppMask_un_128_);
	cppVar_363 = cppVar_375;
	} else {
	BIT_VEC cppVar_376;
	bool cppVar_378 = (aes_state == 0);
	bool cppVar_380 = (cmd == 2);
	bool cppVar_381 = cppVar_378 && cppVar_380;
	bool cppVar_383 = (cmdaddr == 65317);
	bool cppVar_384 = cppVar_381 && cppVar_383;
	if (cppVar_384) {
	BIT_VEC cppVar_385 = (aes_key0 >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_386 = (cppVar_385 << 8) | cmddata;
	cppVar_386 = (cppVar_386 & cppMask_un_88_);
	BIT_VEC cppVar_387 = (aes_key0 >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_388 = (cppVar_386 << 40) | cppVar_387;
	cppVar_388 = (cppVar_388 & cppMask_un_128_);
	cppVar_376 = cppVar_388;
	} else {
	BIT_VEC cppVar_389;
	bool cppVar_391 = (aes_state == 0);
	bool cppVar_393 = (cmd == 2);
	bool cppVar_394 = cppVar_391 && cppVar_393;
	bool cppVar_396 = (cmdaddr == 65316);
	bool cppVar_397 = cppVar_394 && cppVar_396;
	if (cppVar_397) {
	BIT_VEC cppVar_398 = (aes_key0 >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_399 = (cppVar_398 << 8) | cmddata;
	cppVar_399 = (cppVar_399 & cppMask_un_96_);
	BIT_VEC cppVar_400 = (aes_key0 >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_401 = (cppVar_399 << 32) | cppVar_400;
	cppVar_401 = (cppVar_401 & cppMask_un_128_);
	cppVar_389 = cppVar_401;
	} else {
	BIT_VEC cppVar_402;
	bool cppVar_404 = (aes_state == 0);
	bool cppVar_406 = (cmd == 2);
	bool cppVar_407 = cppVar_404 && cppVar_406;
	bool cppVar_409 = (cmdaddr == 65315);
	bool cppVar_410 = cppVar_407 && cppVar_409;
	if (cppVar_410) {
	BIT_VEC cppVar_411 = (aes_key0 >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_412 = (cppVar_411 << 8) | cmddata;
	cppVar_412 = (cppVar_412 & cppMask_un_104_);
	BIT_VEC cppVar_413 = (aes_key0 >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_414 = (cppVar_412 << 24) | cppVar_413;
	cppVar_414 = (cppVar_414 & cppMask_un_128_);
	cppVar_402 = cppVar_414;
	} else {
	BIT_VEC cppVar_415;
	bool cppVar_417 = (aes_state == 0);
	bool cppVar_419 = (cmd == 2);
	bool cppVar_420 = cppVar_417 && cppVar_419;
	bool cppVar_422 = (cmdaddr == 65314);
	bool cppVar_423 = cppVar_420 && cppVar_422;
	if (cppVar_423) {
	BIT_VEC cppVar_424 = (aes_key0 >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_425 = (cppVar_424 << 8) | cmddata;
	cppVar_425 = (cppVar_425 & cppMask_un_112_);
	BIT_VEC cppVar_426 = (aes_key0 >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_427 = (cppVar_425 << 16) | cppVar_426;
	cppVar_427 = (cppVar_427 & cppMask_un_128_);
	cppVar_415 = cppVar_427;
	} else {
	BIT_VEC cppVar_428;
	bool cppVar_430 = (aes_state == 0);
	bool cppVar_432 = (cmd == 2);
	bool cppVar_433 = cppVar_430 && cppVar_432;
	bool cppVar_435 = (cmdaddr == 65313);
	bool cppVar_436 = cppVar_433 && cppVar_435;
	if (cppVar_436) {
	BIT_VEC cppVar_437 = (aes_key0 >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_438 = (cppVar_437 << 8) | cmddata;
	cppVar_438 = (cppVar_438 & cppMask_un_120_);
	BIT_VEC cppVar_439 = (aes_key0 >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_440 = (cppVar_438 << 8) | cppVar_439;
	cppVar_440 = (cppVar_440 & cppMask_un_128_);
	cppVar_428 = cppVar_440;
	} else {
	BIT_VEC cppVar_441;
	bool cppVar_443 = (aes_state == 0);
	bool cppVar_445 = (cmd == 2);
	bool cppVar_446 = cppVar_443 && cppVar_445;
	bool cppVar_448 = (cmdaddr == 65312);
	bool cppVar_449 = cppVar_446 && cppVar_448;
	if (cppVar_449) {
	BIT_VEC cppVar_450 = (aes_key0 >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_451 = (cppVar_450 << 8) | cmddata;
	cppVar_451 = (cppVar_451 & cppMask_un_128_);
	cppVar_441 = cppVar_451;
	} else {
	cppVar_441 = aes_key0;
	}
	cppVar_428 = cppVar_441;
	}
	cppVar_415 = cppVar_428;
	}
	cppVar_402 = cppVar_415;
	}
	cppVar_389 = cppVar_402;
	}
	cppVar_376 = cppVar_389;
	}
	cppVar_363 = cppVar_376;
	}
	cppVar_350 = cppVar_363;
	}
	cppVar_337 = cppVar_350;
	}
	cppVar_324 = cppVar_337;
	}
	cppVar_311 = cppVar_324;
	}
	cppVar_298 = cppVar_311;
	}
	cppVar_285 = cppVar_298;
	}
	cppVar_272 = cppVar_285;
	}
	cppVar_259 = cppVar_272;
	}
	cppVar_248 = cppVar_259;
	}
	return cppVar_248;
}
