#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_key1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_453;
	bool cppVar_455 = (aes_state == 0);
	bool cppVar_457 = (cmd == 2);
	bool cppVar_458 = cppVar_455 && cppVar_457;
	bool cppVar_460 = (cmdaddr == 65343);
	bool cppVar_461 = cppVar_458 && cppVar_460;
	if (cppVar_461) {
	BIT_VEC cppVar_462 = (aes_key1 >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_463 = (cmddata << 120) | cppVar_462;
	cppVar_463 = (cppVar_463 & cppMask_un_128_);
	cppVar_453 = cppVar_463;
	} else {
	BIT_VEC cppVar_464;
	bool cppVar_466 = (aes_state == 0);
	bool cppVar_468 = (cmd == 2);
	bool cppVar_469 = cppVar_466 && cppVar_468;
	bool cppVar_471 = (cmdaddr == 65342);
	bool cppVar_472 = cppVar_469 && cppVar_471;
	if (cppVar_472) {
	BIT_VEC cppVar_473 = (aes_key1 >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_474 = (cppVar_473 << 8) | cmddata;
	cppVar_474 = (cppVar_474 & cppMask_un_16_);
	BIT_VEC cppVar_475 = (aes_key1 >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_476 = (cppVar_474 << 112) | cppVar_475;
	cppVar_476 = (cppVar_476 & cppMask_un_128_);
	cppVar_464 = cppVar_476;
	} else {
	BIT_VEC cppVar_477;
	bool cppVar_479 = (aes_state == 0);
	bool cppVar_481 = (cmd == 2);
	bool cppVar_482 = cppVar_479 && cppVar_481;
	bool cppVar_484 = (cmdaddr == 65341);
	bool cppVar_485 = cppVar_482 && cppVar_484;
	if (cppVar_485) {
	BIT_VEC cppVar_486 = (aes_key1 >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_487 = (cppVar_486 << 8) | cmddata;
	cppVar_487 = (cppVar_487 & cppMask_un_24_);
	BIT_VEC cppVar_488 = (aes_key1 >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_489 = (cppVar_487 << 104) | cppVar_488;
	cppVar_489 = (cppVar_489 & cppMask_un_128_);
	cppVar_477 = cppVar_489;
	} else {
	BIT_VEC cppVar_490;
	bool cppVar_492 = (aes_state == 0);
	bool cppVar_494 = (cmd == 2);
	bool cppVar_495 = cppVar_492 && cppVar_494;
	bool cppVar_497 = (cmdaddr == 65340);
	bool cppVar_498 = cppVar_495 && cppVar_497;
	if (cppVar_498) {
	BIT_VEC cppVar_499 = (aes_key1 >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_500 = (cppVar_499 << 8) | cmddata;
	cppVar_500 = (cppVar_500 & cppMask_un_32_);
	BIT_VEC cppVar_501 = (aes_key1 >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_502 = (cppVar_500 << 96) | cppVar_501;
	cppVar_502 = (cppVar_502 & cppMask_un_128_);
	cppVar_490 = cppVar_502;
	} else {
	BIT_VEC cppVar_503;
	bool cppVar_505 = (aes_state == 0);
	bool cppVar_507 = (cmd == 2);
	bool cppVar_508 = cppVar_505 && cppVar_507;
	bool cppVar_510 = (cmdaddr == 65339);
	bool cppVar_511 = cppVar_508 && cppVar_510;
	if (cppVar_511) {
	BIT_VEC cppVar_512 = (aes_key1 >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_513 = (cppVar_512 << 8) | cmddata;
	cppVar_513 = (cppVar_513 & cppMask_un_40_);
	BIT_VEC cppVar_514 = (aes_key1 >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_515 = (cppVar_513 << 88) | cppVar_514;
	cppVar_515 = (cppVar_515 & cppMask_un_128_);
	cppVar_503 = cppVar_515;
	} else {
	BIT_VEC cppVar_516;
	bool cppVar_518 = (aes_state == 0);
	bool cppVar_520 = (cmd == 2);
	bool cppVar_521 = cppVar_518 && cppVar_520;
	bool cppVar_523 = (cmdaddr == 65338);
	bool cppVar_524 = cppVar_521 && cppVar_523;
	if (cppVar_524) {
	BIT_VEC cppVar_525 = (aes_key1 >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_526 = (cppVar_525 << 8) | cmddata;
	cppVar_526 = (cppVar_526 & cppMask_un_48_);
	BIT_VEC cppVar_527 = (aes_key1 >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_528 = (cppVar_526 << 80) | cppVar_527;
	cppVar_528 = (cppVar_528 & cppMask_un_128_);
	cppVar_516 = cppVar_528;
	} else {
	BIT_VEC cppVar_529;
	bool cppVar_531 = (aes_state == 0);
	bool cppVar_533 = (cmd == 2);
	bool cppVar_534 = cppVar_531 && cppVar_533;
	bool cppVar_536 = (cmdaddr == 65337);
	bool cppVar_537 = cppVar_534 && cppVar_536;
	if (cppVar_537) {
	BIT_VEC cppVar_538 = (aes_key1 >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_539 = (cppVar_538 << 8) | cmddata;
	cppVar_539 = (cppVar_539 & cppMask_un_56_);
	BIT_VEC cppVar_540 = (aes_key1 >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_541 = (cppVar_539 << 72) | cppVar_540;
	cppVar_541 = (cppVar_541 & cppMask_un_128_);
	cppVar_529 = cppVar_541;
	} else {
	BIT_VEC cppVar_542;
	bool cppVar_544 = (aes_state == 0);
	bool cppVar_546 = (cmd == 2);
	bool cppVar_547 = cppVar_544 && cppVar_546;
	bool cppVar_549 = (cmdaddr == 65336);
	bool cppVar_550 = cppVar_547 && cppVar_549;
	if (cppVar_550) {
	BIT_VEC cppVar_551 = (aes_key1 >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_552 = (cppVar_551 << 8) | cmddata;
	cppVar_552 = (cppVar_552 & cppMask_un_64_);
	BIT_VEC cppVar_553 = (aes_key1 >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_554 = (cppVar_552 << 64) | cppVar_553;
	cppVar_554 = (cppVar_554 & cppMask_un_128_);
	cppVar_542 = cppVar_554;
	} else {
	BIT_VEC cppVar_555;
	bool cppVar_557 = (aes_state == 0);
	bool cppVar_559 = (cmd == 2);
	bool cppVar_560 = cppVar_557 && cppVar_559;
	bool cppVar_562 = (cmdaddr == 65335);
	bool cppVar_563 = cppVar_560 && cppVar_562;
	if (cppVar_563) {
	BIT_VEC cppVar_564 = (aes_key1 >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_565 = (cppVar_564 << 8) | cmddata;
	cppVar_565 = (cppVar_565 & cppMask_un_72_);
	BIT_VEC cppVar_566 = (aes_key1 >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_567 = (cppVar_565 << 56) | cppVar_566;
	cppVar_567 = (cppVar_567 & cppMask_un_128_);
	cppVar_555 = cppVar_567;
	} else {
	BIT_VEC cppVar_568;
	bool cppVar_570 = (aes_state == 0);
	bool cppVar_572 = (cmd == 2);
	bool cppVar_573 = cppVar_570 && cppVar_572;
	bool cppVar_575 = (cmdaddr == 65334);
	bool cppVar_576 = cppVar_573 && cppVar_575;
	if (cppVar_576) {
	BIT_VEC cppVar_577 = (aes_key1 >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_578 = (cppVar_577 << 8) | cmddata;
	cppVar_578 = (cppVar_578 & cppMask_un_80_);
	BIT_VEC cppVar_579 = (aes_key1 >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_580 = (cppVar_578 << 48) | cppVar_579;
	cppVar_580 = (cppVar_580 & cppMask_un_128_);
	cppVar_568 = cppVar_580;
	} else {
	BIT_VEC cppVar_581;
	bool cppVar_583 = (aes_state == 0);
	bool cppVar_585 = (cmd == 2);
	bool cppVar_586 = cppVar_583 && cppVar_585;
	bool cppVar_588 = (cmdaddr == 65333);
	bool cppVar_589 = cppVar_586 && cppVar_588;
	if (cppVar_589) {
	BIT_VEC cppVar_590 = (aes_key1 >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_591 = (cppVar_590 << 8) | cmddata;
	cppVar_591 = (cppVar_591 & cppMask_un_88_);
	BIT_VEC cppVar_592 = (aes_key1 >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_593 = (cppVar_591 << 40) | cppVar_592;
	cppVar_593 = (cppVar_593 & cppMask_un_128_);
	cppVar_581 = cppVar_593;
	} else {
	BIT_VEC cppVar_594;
	bool cppVar_596 = (aes_state == 0);
	bool cppVar_598 = (cmd == 2);
	bool cppVar_599 = cppVar_596 && cppVar_598;
	bool cppVar_601 = (cmdaddr == 65332);
	bool cppVar_602 = cppVar_599 && cppVar_601;
	if (cppVar_602) {
	BIT_VEC cppVar_603 = (aes_key1 >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_604 = (cppVar_603 << 8) | cmddata;
	cppVar_604 = (cppVar_604 & cppMask_un_96_);
	BIT_VEC cppVar_605 = (aes_key1 >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_606 = (cppVar_604 << 32) | cppVar_605;
	cppVar_606 = (cppVar_606 & cppMask_un_128_);
	cppVar_594 = cppVar_606;
	} else {
	BIT_VEC cppVar_607;
	bool cppVar_609 = (aes_state == 0);
	bool cppVar_611 = (cmd == 2);
	bool cppVar_612 = cppVar_609 && cppVar_611;
	bool cppVar_614 = (cmdaddr == 65331);
	bool cppVar_615 = cppVar_612 && cppVar_614;
	if (cppVar_615) {
	BIT_VEC cppVar_616 = (aes_key1 >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_617 = (cppVar_616 << 8) | cmddata;
	cppVar_617 = (cppVar_617 & cppMask_un_104_);
	BIT_VEC cppVar_618 = (aes_key1 >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_619 = (cppVar_617 << 24) | cppVar_618;
	cppVar_619 = (cppVar_619 & cppMask_un_128_);
	cppVar_607 = cppVar_619;
	} else {
	BIT_VEC cppVar_620;
	bool cppVar_622 = (aes_state == 0);
	bool cppVar_624 = (cmd == 2);
	bool cppVar_625 = cppVar_622 && cppVar_624;
	bool cppVar_627 = (cmdaddr == 65330);
	bool cppVar_628 = cppVar_625 && cppVar_627;
	if (cppVar_628) {
	BIT_VEC cppVar_629 = (aes_key1 >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_630 = (cppVar_629 << 8) | cmddata;
	cppVar_630 = (cppVar_630 & cppMask_un_112_);
	BIT_VEC cppVar_631 = (aes_key1 >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_632 = (cppVar_630 << 16) | cppVar_631;
	cppVar_632 = (cppVar_632 & cppMask_un_128_);
	cppVar_620 = cppVar_632;
	} else {
	BIT_VEC cppVar_633;
	bool cppVar_635 = (aes_state == 0);
	bool cppVar_637 = (cmd == 2);
	bool cppVar_638 = cppVar_635 && cppVar_637;
	bool cppVar_640 = (cmdaddr == 65329);
	bool cppVar_641 = cppVar_638 && cppVar_640;
	if (cppVar_641) {
	BIT_VEC cppVar_642 = (aes_key1 >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_643 = (cppVar_642 << 8) | cmddata;
	cppVar_643 = (cppVar_643 & cppMask_un_120_);
	BIT_VEC cppVar_644 = (aes_key1 >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_645 = (cppVar_643 << 8) | cppVar_644;
	cppVar_645 = (cppVar_645 & cppMask_un_128_);
	cppVar_633 = cppVar_645;
	} else {
	BIT_VEC cppVar_646;
	bool cppVar_648 = (aes_state == 0);
	bool cppVar_650 = (cmd == 2);
	bool cppVar_651 = cppVar_648 && cppVar_650;
	bool cppVar_653 = (cmdaddr == 65328);
	bool cppVar_654 = cppVar_651 && cppVar_653;
	if (cppVar_654) {
	BIT_VEC cppVar_655 = (aes_key1 >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_656 = (cppVar_655 << 8) | cmddata;
	cppVar_656 = (cppVar_656 & cppMask_un_128_);
	cppVar_646 = cppVar_656;
	} else {
	cppVar_646 = aes_key1;
	}
	cppVar_633 = cppVar_646;
	}
	cppVar_620 = cppVar_633;
	}
	cppVar_607 = cppVar_620;
	}
	cppVar_594 = cppVar_607;
	}
	cppVar_581 = cppVar_594;
	}
	cppVar_568 = cppVar_581;
	}
	cppVar_555 = cppVar_568;
	}
	cppVar_542 = cppVar_555;
	}
	cppVar_529 = cppVar_542;
	}
	cppVar_516 = cppVar_529;
	}
	cppVar_503 = cppVar_516;
	}
	cppVar_490 = cppVar_503;
	}
	cppVar_477 = cppVar_490;
	}
	cppVar_464 = cppVar_477;
	}
	cppVar_453 = cppVar_464;
	}
	return cppVar_453;
}
