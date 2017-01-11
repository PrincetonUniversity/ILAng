#include "common.hpp"
#include "model_aes_class.hpp"

BIT_VEC model_aes::cppUpdateFun_aes_key1(BIT_VEC cmd, BIT_VEC cmdaddr, BIT_VEC cmddata)
{
	BIT_VEC cppVar_470;
	bool cppVar_472 = (aes_state == 0);
	bool cppVar_474 = (cmd == 2);
	bool cppVar_475 = cppVar_472 && cppVar_474;
	bool cppVar_477 = (cmdaddr == 65343);
	bool cppVar_478 = cppVar_475 && cppVar_477;
	if (cppVar_478) {
	BIT_VEC cppVar_479 = (aes_key1 >> 0) & cppMask_un_120_;
	BIT_VEC cppVar_480 = (cmddata << 120) | cppVar_479;
	cppVar_480 = (cppVar_480 & cppMask_un_128_);
	cppVar_470 = cppVar_480;
	} else {
	BIT_VEC cppVar_481;
	bool cppVar_483 = (aes_state == 0);
	bool cppVar_485 = (cmd == 2);
	bool cppVar_486 = cppVar_483 && cppVar_485;
	bool cppVar_488 = (cmdaddr == 65342);
	bool cppVar_489 = cppVar_486 && cppVar_488;
	if (cppVar_489) {
	BIT_VEC cppVar_490 = (aes_key1 >> 120) & cppMask_un_8_;
	BIT_VEC cppVar_491 = (cppVar_490 << 8) | cmddata;
	cppVar_491 = (cppVar_491 & cppMask_un_16_);
	BIT_VEC cppVar_492 = (aes_key1 >> 0) & cppMask_un_112_;
	BIT_VEC cppVar_493 = (cppVar_491 << 112) | cppVar_492;
	cppVar_493 = (cppVar_493 & cppMask_un_128_);
	cppVar_481 = cppVar_493;
	} else {
	BIT_VEC cppVar_494;
	bool cppVar_496 = (aes_state == 0);
	bool cppVar_498 = (cmd == 2);
	bool cppVar_499 = cppVar_496 && cppVar_498;
	bool cppVar_501 = (cmdaddr == 65341);
	bool cppVar_502 = cppVar_499 && cppVar_501;
	if (cppVar_502) {
	BIT_VEC cppVar_503 = (aes_key1 >> 112) & cppMask_un_16_;
	BIT_VEC cppVar_504 = (cppVar_503 << 8) | cmddata;
	cppVar_504 = (cppVar_504 & cppMask_un_24_);
	BIT_VEC cppVar_505 = (aes_key1 >> 0) & cppMask_un_104_;
	BIT_VEC cppVar_506 = (cppVar_504 << 104) | cppVar_505;
	cppVar_506 = (cppVar_506 & cppMask_un_128_);
	cppVar_494 = cppVar_506;
	} else {
	BIT_VEC cppVar_507;
	bool cppVar_509 = (aes_state == 0);
	bool cppVar_511 = (cmd == 2);
	bool cppVar_512 = cppVar_509 && cppVar_511;
	bool cppVar_514 = (cmdaddr == 65340);
	bool cppVar_515 = cppVar_512 && cppVar_514;
	if (cppVar_515) {
	BIT_VEC cppVar_516 = (aes_key1 >> 104) & cppMask_un_24_;
	BIT_VEC cppVar_517 = (cppVar_516 << 8) | cmddata;
	cppVar_517 = (cppVar_517 & cppMask_un_32_);
	BIT_VEC cppVar_518 = (aes_key1 >> 0) & cppMask_un_96_;
	BIT_VEC cppVar_519 = (cppVar_517 << 96) | cppVar_518;
	cppVar_519 = (cppVar_519 & cppMask_un_128_);
	cppVar_507 = cppVar_519;
	} else {
	BIT_VEC cppVar_520;
	bool cppVar_522 = (aes_state == 0);
	bool cppVar_524 = (cmd == 2);
	bool cppVar_525 = cppVar_522 && cppVar_524;
	bool cppVar_527 = (cmdaddr == 65339);
	bool cppVar_528 = cppVar_525 && cppVar_527;
	if (cppVar_528) {
	BIT_VEC cppVar_529 = (aes_key1 >> 96) & cppMask_un_32_;
	BIT_VEC cppVar_530 = (cppVar_529 << 8) | cmddata;
	cppVar_530 = (cppVar_530 & cppMask_un_40_);
	BIT_VEC cppVar_531 = (aes_key1 >> 0) & cppMask_un_88_;
	BIT_VEC cppVar_532 = (cppVar_530 << 88) | cppVar_531;
	cppVar_532 = (cppVar_532 & cppMask_un_128_);
	cppVar_520 = cppVar_532;
	} else {
	BIT_VEC cppVar_533;
	bool cppVar_535 = (aes_state == 0);
	bool cppVar_537 = (cmd == 2);
	bool cppVar_538 = cppVar_535 && cppVar_537;
	bool cppVar_540 = (cmdaddr == 65338);
	bool cppVar_541 = cppVar_538 && cppVar_540;
	if (cppVar_541) {
	BIT_VEC cppVar_542 = (aes_key1 >> 88) & cppMask_un_40_;
	BIT_VEC cppVar_543 = (cppVar_542 << 8) | cmddata;
	cppVar_543 = (cppVar_543 & cppMask_un_48_);
	BIT_VEC cppVar_544 = (aes_key1 >> 0) & cppMask_un_80_;
	BIT_VEC cppVar_545 = (cppVar_543 << 80) | cppVar_544;
	cppVar_545 = (cppVar_545 & cppMask_un_128_);
	cppVar_533 = cppVar_545;
	} else {
	BIT_VEC cppVar_546;
	bool cppVar_548 = (aes_state == 0);
	bool cppVar_550 = (cmd == 2);
	bool cppVar_551 = cppVar_548 && cppVar_550;
	bool cppVar_553 = (cmdaddr == 65337);
	bool cppVar_554 = cppVar_551 && cppVar_553;
	if (cppVar_554) {
	BIT_VEC cppVar_555 = (aes_key1 >> 80) & cppMask_un_48_;
	BIT_VEC cppVar_556 = (cppVar_555 << 8) | cmddata;
	cppVar_556 = (cppVar_556 & cppMask_un_56_);
	BIT_VEC cppVar_557 = (aes_key1 >> 0) & cppMask_un_72_;
	BIT_VEC cppVar_558 = (cppVar_556 << 72) | cppVar_557;
	cppVar_558 = (cppVar_558 & cppMask_un_128_);
	cppVar_546 = cppVar_558;
	} else {
	BIT_VEC cppVar_559;
	bool cppVar_561 = (aes_state == 0);
	bool cppVar_563 = (cmd == 2);
	bool cppVar_564 = cppVar_561 && cppVar_563;
	bool cppVar_566 = (cmdaddr == 65336);
	bool cppVar_567 = cppVar_564 && cppVar_566;
	if (cppVar_567) {
	BIT_VEC cppVar_568 = (aes_key1 >> 72) & cppMask_un_56_;
	BIT_VEC cppVar_569 = (cppVar_568 << 8) | cmddata;
	cppVar_569 = (cppVar_569 & cppMask_un_64_);
	BIT_VEC cppVar_570 = (aes_key1 >> 0) & cppMask_un_64_;
	BIT_VEC cppVar_571 = (cppVar_569 << 64) | cppVar_570;
	cppVar_571 = (cppVar_571 & cppMask_un_128_);
	cppVar_559 = cppVar_571;
	} else {
	BIT_VEC cppVar_572;
	bool cppVar_574 = (aes_state == 0);
	bool cppVar_576 = (cmd == 2);
	bool cppVar_577 = cppVar_574 && cppVar_576;
	bool cppVar_579 = (cmdaddr == 65335);
	bool cppVar_580 = cppVar_577 && cppVar_579;
	if (cppVar_580) {
	BIT_VEC cppVar_581 = (aes_key1 >> 64) & cppMask_un_64_;
	BIT_VEC cppVar_582 = (cppVar_581 << 8) | cmddata;
	cppVar_582 = (cppVar_582 & cppMask_un_72_);
	BIT_VEC cppVar_583 = (aes_key1 >> 0) & cppMask_un_56_;
	BIT_VEC cppVar_584 = (cppVar_582 << 56) | cppVar_583;
	cppVar_584 = (cppVar_584 & cppMask_un_128_);
	cppVar_572 = cppVar_584;
	} else {
	BIT_VEC cppVar_585;
	bool cppVar_587 = (aes_state == 0);
	bool cppVar_589 = (cmd == 2);
	bool cppVar_590 = cppVar_587 && cppVar_589;
	bool cppVar_592 = (cmdaddr == 65334);
	bool cppVar_593 = cppVar_590 && cppVar_592;
	if (cppVar_593) {
	BIT_VEC cppVar_594 = (aes_key1 >> 56) & cppMask_un_72_;
	BIT_VEC cppVar_595 = (cppVar_594 << 8) | cmddata;
	cppVar_595 = (cppVar_595 & cppMask_un_80_);
	BIT_VEC cppVar_596 = (aes_key1 >> 0) & cppMask_un_48_;
	BIT_VEC cppVar_597 = (cppVar_595 << 48) | cppVar_596;
	cppVar_597 = (cppVar_597 & cppMask_un_128_);
	cppVar_585 = cppVar_597;
	} else {
	BIT_VEC cppVar_598;
	bool cppVar_600 = (aes_state == 0);
	bool cppVar_602 = (cmd == 2);
	bool cppVar_603 = cppVar_600 && cppVar_602;
	bool cppVar_605 = (cmdaddr == 65333);
	bool cppVar_606 = cppVar_603 && cppVar_605;
	if (cppVar_606) {
	BIT_VEC cppVar_607 = (aes_key1 >> 48) & cppMask_un_80_;
	BIT_VEC cppVar_608 = (cppVar_607 << 8) | cmddata;
	cppVar_608 = (cppVar_608 & cppMask_un_88_);
	BIT_VEC cppVar_609 = (aes_key1 >> 0) & cppMask_un_40_;
	BIT_VEC cppVar_610 = (cppVar_608 << 40) | cppVar_609;
	cppVar_610 = (cppVar_610 & cppMask_un_128_);
	cppVar_598 = cppVar_610;
	} else {
	BIT_VEC cppVar_611;
	bool cppVar_613 = (aes_state == 0);
	bool cppVar_615 = (cmd == 2);
	bool cppVar_616 = cppVar_613 && cppVar_615;
	bool cppVar_618 = (cmdaddr == 65332);
	bool cppVar_619 = cppVar_616 && cppVar_618;
	if (cppVar_619) {
	BIT_VEC cppVar_620 = (aes_key1 >> 40) & cppMask_un_88_;
	BIT_VEC cppVar_621 = (cppVar_620 << 8) | cmddata;
	cppVar_621 = (cppVar_621 & cppMask_un_96_);
	BIT_VEC cppVar_622 = (aes_key1 >> 0) & cppMask_un_32_;
	BIT_VEC cppVar_623 = (cppVar_621 << 32) | cppVar_622;
	cppVar_623 = (cppVar_623 & cppMask_un_128_);
	cppVar_611 = cppVar_623;
	} else {
	BIT_VEC cppVar_624;
	bool cppVar_626 = (aes_state == 0);
	bool cppVar_628 = (cmd == 2);
	bool cppVar_629 = cppVar_626 && cppVar_628;
	bool cppVar_631 = (cmdaddr == 65331);
	bool cppVar_632 = cppVar_629 && cppVar_631;
	if (cppVar_632) {
	BIT_VEC cppVar_633 = (aes_key1 >> 32) & cppMask_un_96_;
	BIT_VEC cppVar_634 = (cppVar_633 << 8) | cmddata;
	cppVar_634 = (cppVar_634 & cppMask_un_104_);
	BIT_VEC cppVar_635 = (aes_key1 >> 0) & cppMask_un_24_;
	BIT_VEC cppVar_636 = (cppVar_634 << 24) | cppVar_635;
	cppVar_636 = (cppVar_636 & cppMask_un_128_);
	cppVar_624 = cppVar_636;
	} else {
	BIT_VEC cppVar_637;
	bool cppVar_639 = (aes_state == 0);
	bool cppVar_641 = (cmd == 2);
	bool cppVar_642 = cppVar_639 && cppVar_641;
	bool cppVar_644 = (cmdaddr == 65330);
	bool cppVar_645 = cppVar_642 && cppVar_644;
	if (cppVar_645) {
	BIT_VEC cppVar_646 = (aes_key1 >> 24) & cppMask_un_104_;
	BIT_VEC cppVar_647 = (cppVar_646 << 8) | cmddata;
	cppVar_647 = (cppVar_647 & cppMask_un_112_);
	BIT_VEC cppVar_648 = (aes_key1 >> 0) & cppMask_un_16_;
	BIT_VEC cppVar_649 = (cppVar_647 << 16) | cppVar_648;
	cppVar_649 = (cppVar_649 & cppMask_un_128_);
	cppVar_637 = cppVar_649;
	} else {
	BIT_VEC cppVar_650;
	bool cppVar_652 = (aes_state == 0);
	bool cppVar_654 = (cmd == 2);
	bool cppVar_655 = cppVar_652 && cppVar_654;
	bool cppVar_657 = (cmdaddr == 65329);
	bool cppVar_658 = cppVar_655 && cppVar_657;
	if (cppVar_658) {
	BIT_VEC cppVar_659 = (aes_key1 >> 16) & cppMask_un_112_;
	BIT_VEC cppVar_660 = (cppVar_659 << 8) | cmddata;
	cppVar_660 = (cppVar_660 & cppMask_un_120_);
	BIT_VEC cppVar_661 = (aes_key1 >> 0) & cppMask_un_8_;
	BIT_VEC cppVar_662 = (cppVar_660 << 8) | cppVar_661;
	cppVar_662 = (cppVar_662 & cppMask_un_128_);
	cppVar_650 = cppVar_662;
	} else {
	BIT_VEC cppVar_663;
	bool cppVar_665 = (aes_state == 0);
	bool cppVar_667 = (cmd == 2);
	bool cppVar_668 = cppVar_665 && cppVar_667;
	bool cppVar_670 = (cmdaddr == 65328);
	bool cppVar_671 = cppVar_668 && cppVar_670;
	if (cppVar_671) {
	BIT_VEC cppVar_672 = (aes_key1 >> 8) & cppMask_un_120_;
	BIT_VEC cppVar_673 = (cppVar_672 << 8) | cmddata;
	cppVar_673 = (cppVar_673 & cppMask_un_128_);
	cppVar_663 = cppVar_673;
	} else {
	cppVar_663 = aes_key1;
	}
	cppVar_650 = cppVar_663;
	}
	cppVar_637 = cppVar_650;
	}
	cppVar_624 = cppVar_637;
	}
	cppVar_611 = cppVar_624;
	}
	cppVar_598 = cppVar_611;
	}
	cppVar_585 = cppVar_598;
	}
	cppVar_572 = cppVar_585;
	}
	cppVar_559 = cppVar_572;
	}
	cppVar_546 = cppVar_559;
	}
	cppVar_533 = cppVar_546;
	}
	cppVar_520 = cppVar_533;
	}
	cppVar_507 = cppVar_520;
	}
	cppVar_494 = cppVar_507;
	}
	cppVar_481 = cppVar_494;
	}
	cppVar_470 = cppVar_481;
	}
	return cppVar_470;
}
